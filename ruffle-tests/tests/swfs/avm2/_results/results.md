# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 19:49 UTC

**Git SHA**: `c489b84d99`

**Run Duration**: 186m 45s

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
| 1 | `abstract_classes` | 132 | 37.3s |  |
| 2 | `accessibility` | 1 | 5.7s |  |
| 3 | `accessibilityimplementation` | 18 | 21.8s |  |
| 4 | `activation_class` | 6 | 5.7s |  |
| 5 | `add` | 1058 | 13.1s |  |
| 6 | `agal_compiler` | 13 | 8.0s |  |
| 7 | `air_datagram_socket` | 1 | 7.6s |  |
| 8 | `air_hidden_lookup` | 2 | 5.8s |  |
| 9 | `air_ifilepromise` | 1 | 5.8s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 5.9s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.4s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.4s |  |
| 13 | `all_classes/display/swf10` | 2569 | 5.9s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.5s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.5s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.5s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.5s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.4s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 5.8s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.4s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.4s |  |
| 22 | `all_classes/errors/swf10` | 140 | 5.7s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.4s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.4s |  |
| 25 | `all_classes/events/swf10` | 1638 | 5.8s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.4s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.4s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.4s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.4s |  |
| 30 | `all_classes/security/swf11` | 3 | 5.7s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.4s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.4s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.4s |  |
| 34 | `all_classes/xml/swf30` | 116 | 5.8s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.4s |  |
| 36 | `allow_networking` | 72 | 24.5s |  |
| 37 | `amf_array_serialization` | 17 | 6.2s |  |
| 38 | `amf_custom_obj` | 26 | 5.9s |  |
| 39 | `amf_dictionary` | 9 | 5.8s |  |
| 40 | `amf_function` | 46 | 5.8s |  |
| 41 | `amf_invalid_date` | 2 | 5.7s |  |
| 42 | `amf_missing_prop` | 6 | 5.7s |  |
| 43 | `amf_nondynamic_function_prop` | 6 | 5.7s |  |
| 44 | `amf_sealed_class_dynamic_properties` | 16 | 5.8s |  |
| 45 | `amf_setter_error` | 8 | 5.7s |  |
| 46 | `amf_vector` | 40 | 36.9s |  |
| 47 | `amf_xml` | 6 | 5.5s |  |
| 48 | `appdomain_lookup_edge_cases` | 32 | 6.1s |  |
| 49 | `application_domain` | 4 | 5.6s |  |
| 50 | `applicationdomain_getqualifieddefinitionnames` | 9 | 21.3s |  |
| 51 | `applicationdomain_hasdefinition_null` | 2 | 5.5s |  |
| 52 | `array_access` | 18 | 5.6s |  |
| 53 | `array_access_interpreter` | 4 | 5.6s |  |
| 54 | `array_access_no_pubns` | 2 | 5.6s |  |
| 55 | `array_concat` | 41 | 5.6s |  |
| 56 | `array_constr` | 10 | 5.5s |  |
| 57 | `array_delete` | 44 | 5.8s |  |
| 58 | `array_enumeration` | 10 | 5.7s |  |
| 59 | `array_enumeration_elements` | 11 | 5.7s |  |
| 60 | `array_every` | 8 | 5.6s |  |
| 61 | `array_filter` | 6 | 5.6s |  |
| 62 | `array_foreach` | 18 | 5.6s |  |
| 63 | `array_hasownproperty` | 11 | 5.6s |  |
| 64 | `array_holes` | 9 | 5.6s |  |
| 65 | `array_index_max` | 84 | 5.5s |  |
| 66 | `array_indexof` | 25 | 5.6s |  |
| 67 | `array_join` | 26 | 5.6s |  |
| 68 | `array_lastindexof` | 29 | 5.5s |  |
| 69 | `array_length` | 14 | 5.5s |  |
| 70 | `array_literal` | 3 | 5.5s |  |
| 71 | `array_map` | 8 | 5.4s |  |
| 72 | `array_pop` | 52 | 5.7s |  |
| 73 | `array_push` | 24 | 5.6s |  |
| 74 | `array_reborrow_bug` | 6 | 5.6s |  |
| 75 | `array_reverse` | 28 | 5.6s |  |
| 76 | `array_shift` | 51 | 1.7s |  |
| 77 | `array_slice` | 39 | 5.6s |  |
| 78 | `array_some` | 8 | 5.5s |  |
| 79 | `array_sort` | 297 | 6.1s |  |
| 80 | `array_sort_fun_swf12` | 2 | 5.5s |  |
| 81 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 82 | `array_sort_random` | 210 | 5.6s |  |
| 83 | `array_sort_swf10_32bit` | 1 | 5.5s |  |
| 84 | `array_sorton` | 545 | 6.4s |  |
| 85 | `array_sparse_ops` | 41 | 6.0s |  |
| 86 | `array_splice` | 133 | 5.9s |  |
| 87 | `array_splice2` | 428 | 5.9s |  |
| 88 | `array_splice_types` | 48 | 5.8s |  |
| 89 | `array_storage` | 8 | 5.7s |  |
| 90 | `array_tolocalestring` | 9 | 5.7s |  |
| 91 | `array_tostring` | 12 | 5.7s |  |
| 92 | `array_unshift` | 24 | 5.6s |  |
| 93 | `array_valueof` | 9 | 5.6s |  |
| 94 | `array_vector_null_callback` | 10 | 5.7s |  |
| 95 | `astype` | 28 | 5.8s |  |
| 96 | `astypelate` | 24 | 5.8s |  |
| 97 | `astypelate_propagates` | 1 | 5.6s |  |
| 98 | `asymmetric_key_events` | 11 | 5.8s |  |
| 99 | `automation_classes` | 122 | 2.0s |  |
| 100 | `av_classes` | 340 | 5.9s |  |
| 101 | `avm1movie_addcallback_call` | 14 | 5.7s |  |
| 102 | `avm2_catchup_dobj` | 158 | 6.3s |  |
| 103 | `away3d_advanced_shallow_water_demo` | 0 | 77.3s |  |
| 104 | `bevel_filter` | 187 | 5.7s |  |
| 105 | `bitand` | 1058 | 12.8s |  |
| 106 | `bitmap_constr` | 17 | 5.8s |  |
| 107 | `bitmap_data` | 1000 | 12.4s |  |
| 108 | `bitmap_filter_abstract` | 6 | 5.7s |  |
| 109 | `bitmap_pixelsnapping` | 2 | 21.9s |  |
| 110 | `bitmap_properties` | 23 | 5.7s |  |
| 111 | `bitmap_subclass` | 7 | 7.0s |  |
| 112 | `bitmap_subclass_properties` | 9 | 5.9s |  |
| 113 | `bitmap_timeline` | 9 | 5.7s |  |
| 114 | `bitmapdata_accuracy` | 1 | 48.5s |  |
| 115 | `bitmapdata_applyfilter_blur` | 0 | 22.1s |  |
| 116 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.1s |  |
| 117 | `bitmapdata_applyfilter_destpoint` | 0 | 21.8s |  |
| 118 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 21.9s |  |
| 119 | `bitmapdata_applyfilter_identity` | 4 | 21.5s |  |
| 120 | `bitmapdata_clone` | 13 | 5.7s |  |
| 121 | `bitmapdata_colortransform` | 0 | 5.8s |  |
| 122 | `bitmapdata_colortransform_oob` | 2 | 5.6s |  |
| 123 | `bitmapdata_constr` | 22 | 5.7s |  |
| 124 | `bitmapdata_constructor_from_timeline` | 1 | 5.9s |  |
| 125 | `bitmapdata_copychannel` | 0 | 23.3s |  |
| 126 | `bitmapdata_copypixels` | 23 | 21.8s |  |
| 127 | `bitmapdata_copypixels_alpha_combine` | 13 | 5.7s |  |
| 128 | `bitmapdata_copypixels_alpha_merge` | 9 | 7.7s |  |
| 129 | `bitmapdata_copypixels_blend` | 1029 | 8.2s |  |
| 130 | `bitmapdata_copypixels_blend_over` | 1 | 7.8s |  |
| 131 | `bitmapdata_copypixels_self` | 612 | 7.7s |  |
| 132 | `bitmapdata_copypixelstobytearray` | 39 | 7.7s |  |
| 133 | `bitmapdata_dispose` | 7 | 7.8s |  |
| 134 | `bitmapdata_draw` | 0 | 28.9s |  |
| 135 | `bitmapdata_draw_alpha_erase` | 8 | 7.8s |  |
| 136 | `bitmapdata_draw_cab_quality` | 0 | 29.9s |  |
| 137 | `bitmapdata_draw_colortransform` | 0 | 7.7s |  |
| 138 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 28.4s |  |
| 139 | `bitmapdata_draw_filters` | 0 | 28.2s |  |
| 140 | `bitmapdata_draw_masks` | 0 | 7.6s |  |
| 141 | `bitmapdata_draw_rotation` | 0 | 7.7s |  |
| 142 | `bitmapdata_draw_self_via_graphic` | 0 | 7.5s |  |
| 143 | `bitmapdata_draw_stage` | 0 | 28.3s |  |
| 144 | `bitmapdata_drawwithquality` | 0 | 7.9s |  |
| 145 | `bitmapdata_embedded` | 9 | 7.7s |  |
| 146 | `bitmapdata_encode_jpeg_visual` | 0 | 28.5s |  |
| 147 | `bitmapdata_encode_png_roundtrip` | 33 | 7.8s |  |
| 148 | `bitmapdata_encode_png_visual` | 0 | 7.7s |  |
| 149 | `bitmapdata_fillrect` | 0 | 7.7s |  |
| 150 | `bitmapdata_filter_sourcerect` | 0 | 28.2s |  |
| 151 | `bitmapdata_floodfill` | 35 | 7.6s |  |
| 152 | `bitmapdata_getpixels` | 39 | 28.1s |  |
| 153 | `bitmapdata_getvector` | 27 | 2.4s |  |
| 154 | `bitmapdata_histogram` | 59 | 2.4s |  |
| 155 | `bitmapdata_hittest` | 112 | 8.2s |  |
| 156 | `bitmapdata_hittest_threshold` | 18 | 7.6s |  |
| 157 | `bitmapdata_opaque` | 0 | 7.6s |  |
| 158 | `bitmapdata_pixeldissolve` | 1037 | 8.2s |  |
| 159 | `bitmapdata_pixeldissolve_image` | 0 | 7.8s |  |
| 160 | `bitmapdata_rectangle_rounding` | 16 | 7.6s |  |
| 161 | `bitmapdata_setpixels` | 286 | 7.7s |  |
| 162 | `bitmapdata_setvector` | 26 | 7.8s |  |
| 163 | `bitmapdata_sync` | 0 | 28.6s |  |
| 164 | `bitmapdata_threshold` | 176 | 8.4s |  |
| 165 | `bitmapdata_zero_size` | 8 | 7.7s |  |
| 166 | `bitnot` | 46 | 7.7s |  |
| 167 | `bitor` | 1058 | 16.6s |  |
| 168 | `bitxor` | 1058 | 16.9s |  |
| 169 | `blend_mode_null` | 1 | 7.7s |  |
| 170 | `blend_multiply_alpha` | 0 | 7.7s |  |
| 171 | `blend_scroll` | 0 | 7.7s |  |
| 172 | `blend_shader_luma_lighten` | 3 | 8.4s |  |
| 173 | `blur_filter` | 43 | 8.2s |  |
| 174 | `boolean_constr` | 32 | 8.1s |  |
| 175 | `boolean_negation` | 30 | 8.2s |  |
| 176 | `boolean_tostring` | 8 | 8.0s |  |
| 177 | `broadcast_event` | 7 | 8.0s |  |
| 178 | `button_bounds` | 1 | 8.1s |  |
| 179 | `button_hittest` | 2 | 29.5s |  |
| 180 | `button_nested_frame` | 48 | 29.6s |  |
| 181 | `button_nested_frame_simple` | 27 | 8.3s |  |
| 182 | `bytearray` | 48 | 8.2s |  |
| 183 | `bytearray_amf3_shared_references` | 4 | 7.8s |  |
| 184 | `bytearray_bad_symbol_class` | 3 | 7.8s |  |
| 185 | `bytearray_bad_symbol_class_other_movie` | 6 | 3.1s |  |
| 186 | `bytearray_compress` | 31 | 8.0s |  |
| 187 | `bytearray_errors` | 24 | 8.1s |  |
| 188 | `bytearray_insertion_reborrow` | 5 | 8.0s |  |
| 189 | `bytearray_method_serialization` | 1 | 7.9s |  |
| 190 | `bytearray_oom` | 3 | 8.0s |  |
| 191 | `bytearray_readobject_amf0` | 50 | 7.9s |  |
| 192 | `bytearray_readobject_amf3` | 53 | 8.0s |  |
| 193 | `bytearray_readutf8bytes_with_bom` | 16 | 8.1s |  |
| 194 | `bytearray_serialization` | 3 | 8.0s |  |
| 195 | `bytearray_string_null` | 19 | 8.2s |  |
| 196 | `bytearray_tostring` | 15 | 8.0s |  |
| 197 | `bytearray_utf16` | 8 | 2.6s |  |
| 198 | `bytearray_writeobject` | 24 | 7.7s |  |
| 199 | `callee_in_initializer` | 6 | 7.9s |  |
| 200 | `callproplex_class` | 1 | 7.9s |  |
| 201 | `capabilities_resolution` | 8 | 30.1s |  |
| 202 | `casi32` | 166 | 8.0s |  |
| 203 | `catch_class` | 6 | 8.0s |  |
| 204 | `catch_scope_slot` | 7 | 8.0s |  |
| 205 | `checkfilter` | 4 | 2.7s |  |
| 206 | `class_call` | 32 | 8.3s |  |
| 207 | `class_cast_call` | 14 | 8.0s |  |
| 208 | `class_enumeration` | 4 | 7.8s |  |
| 209 | `class_has_own_property` | 2 | 7.9s |  |
| 210 | `class_init_interpreter_mode` | 1 | 7.8s |  |
| 211 | `class_is` | 32 | 8.1s |  |
| 212 | `class_methods` | 5 | 7.9s |  |
| 213 | `class_object_properties` | 10 | 8.1s |  |
| 214 | `class_singleton` | 18 | 5.7s |  |
| 215 | `class_supercalls_errors` | 35 | 5.8s |  |
| 216 | `class_supercalls_mismatched` | 26 | 5.8s |  |
| 217 | `class_superclass_wrong_order` | 1 | 21.7s |  |
| 218 | `class_to_locale_string` | 2 | 5.7s |  |
| 219 | `class_to_string` | 2 | 5.6s |  |
| 220 | `class_value_of` | 2 | 5.6s |  |
| 221 | `click_block` | 5 | 21.9s |  |
| 222 | `click_invisible` | 3 | 5.8s |  |
| 223 | `closures` | 12 | 5.7s |  |
| 224 | `coerce_return_type` | 40 | 5.8s |  |
| 225 | `coerce_return_type_fail` | 2 | 5.7s |  |
| 226 | `coerce_return_void` | 3 | 5.7s |  |
| 227 | `coerce_string` | 86 | 5.8s |  |
| 228 | `coerce_string_precision` | 28 | 5.7s |  |
| 229 | `coerce_to_primitive_side_effects` | 29 | 5.8s |  |
| 230 | `collator_compare_basic` | 93 | 5.9s |  |
| 231 | `collator_flags` | 111 | 5.7s |  |
| 232 | `collator_locale_ids_windows` | 120 | 5.8s |  |
| 233 | `color_matrix_filter` | 19 | 5.8s |  |
| 234 | `construct_errors_swf10` | 8 | 5.7s |  |
| 235 | `construct_frame_list` | 22 | 22.1s |  |
| 236 | `construct_interface` | 3 | 5.7s |  |
| 237 | `constructor_call` | 3 | 5.7s |  |
| 238 | `constructors_vs_timeline` | 5 | 21.9s |  |
| 239 | `constructprop_dynamic_primitive` | 7 | 5.7s |  |
| 240 | `constructprop_method` | 2 | 5.7s |  |
| 241 | `constructsuper_null` | 2 | 1.6s |  |
| 242 | `content_element_basic` | 50 | 6.0s |  |
| 243 | `context3d_clear_mask` | 4 | 5.6s |  |
| 244 | `context3d_creation` | 9 | 5.7s |  |
| 245 | `control_flow_bool` | 4 | 5.6s |  |
| 246 | `control_flow_stricteq` | 8 | 5.7s |  |
| 247 | `convert_boolean` | 30 | 5.7s |  |
| 248 | `convert_integer` | 90 | 5.8s |  |
| 249 | `convert_number` | 56 | 5.7s |  |
| 250 | `convert_uinteger` | 90 | 5.7s |  |
| 251 | `convolution_filter` | 89 | 5.7s |  |
| 252 | `core_exceptions` | 47 | 6.5s |  |
| 253 | `cpool_index_invalid_bytecode_1` | 6 | 5.6s |  |
| 254 | `cpool_index_invalid_bytecode_2` | 3 | 5.6s |  |
| 255 | `cpool_index_invalid_bytecode_3` | 1 | 5.5s |  |
| 256 | `cross_api_version_call_newer` | 12 | 6.1s |  |
| 257 | `cross_api_version_call_older` | 12 | 5.8s |  |
| 258 | `cryptscore` | 11 | 5.4s |  |
| 259 | `currency_parse_result` | 7 | 5.7s |  |
| 260 | `date` | 30 | 5.8s |  |
| 261 | `date_parse` | 36 | 5.3s |  |
| 262 | `date_set_time_out_of_range` | 62 | 5.6s |  |
| 263 | `declocal` | 46 | 5.5s |  |
| 264 | `declocal_i` | 46 | 5.4s |  |
| 265 | `decode_uri` | 71 | 5.6s |  |
| 266 | `decrement` | 46 | 5.3s |  |
| 267 | `decrement_i` | 46 | 1.6s |  |
| 268 | `default_values` | 7 | 5.3s |  |
| 269 | `delayed_symbolclass` | 28 | 20.4s |  |
| 270 | `describe_type_basic` | 152 | 5.9s |  |
| 271 | `describe_type_json` | 301 | 5.5s |  |
| 272 | `describe_type_metadata` | 125 | 5.9s |  |
| 273 | `describe_type_native` | 23 | 5.3s |  |
| 274 | `dictionary_access` | 62 | 5.5s |  |
| 275 | `dictionary_access_no_pubns` | 2 | 5.6s |  |
| 276 | `dictionary_delete` | 101 | 5.7s |  |
| 277 | `dictionary_foreach` | 42 | 5.5s |  |
| 278 | `dictionary_hasownproperty` | 63 | 5.6s |  |
| 279 | `dictionary_in` | 62 | 5.5s |  |
| 280 | `dictionary_iter_modify` | 8 | 5.3s |  |
| 281 | `dictionary_namespaces` | 36 | 5.4s |  |
| 282 | `dictionary_qname_keys` | 45 | 5.6s |  |
| 283 | `displacement_map_filter` | 61 | 5.6s |  |
| 284 | `displayobject_alpha` | 277 | 5.3s |  |
| 285 | `displayobject_blendmode` | 0 | 20.5s |  |
| 286 | `displayobject_colortransform_nested` | 0 | 20.7s |  |
| 287 | `displayobject_early_init` | 54 | 6.9s |  |
| 288 | `displayobject_filters` | 17 | 5.4s |  |
| 289 | `displayobject_from_enterframe` | 1 | 20.2s |  |
| 290 | `displayobject_getbounds_shape` | 0 | 20.2s |  |
| 291 | `displayobject_getrect` | 16 | 6.0s |  |
| 292 | `displayobject_height` | 6052 | 20.4s |  |
| 293 | `displayobject_hittestobject` | 32 | 5.4s |  |
| 294 | `displayobject_hittestpoint` | 49 | 5.6s |  |
| 295 | `displayobject_hittestpoint_boundary` | 65 | 20.8s |  |
| 296 | `displayobject_hittestpoint_root` | 13 | 5.6s |  |
| 297 | `displayobject_invalid_floats` | 60 | 5.4s |  |
| 298 | `displayobject_invalid_props` | 3 | 5.3s |  |
| 299 | `displayobject_mask` | 3 | 7.5s |  |
| 300 | `displayobject_mask_self_referential` | 0 | 6.5s |  |
| 301 | `displayobject_metaData` | 3 | 6.6s |  |
| 302 | `displayobject_name` | 22 | 26.6s |  |
| 303 | `displayobject_name_from_timeline` | 24 | 6.8s |  |
| 304 | `displayobject_opaque_background` | 6 | 21.5s |  |
| 305 | `displayobject_parent` | 12 | 6.5s |  |
| 306 | `displayobject_root` | 24 | 6.5s |  |
| 307 | `displayobject_rotation` | 1284 | 6.6s |  |
| 308 | `displayobject_scrollrect` | 33 | 6.8s |  |
| 309 | `displayobject_set_matrix_nested` | 0 | 26.8s |  |
| 310 | `displayobject_set_name_loaded` | 3 | 6.9s |  |
| 311 | `displayobject_subclass` | 2 | 6.6s |  |
| 312 | `displayobject_transform` | 89 | 6.6s |  |
| 313 | `displayobject_visible` | 23 | 6.6s |  |
| 314 | `displayobject_width` | 4852 | 27.6s |  |
| 315 | `displayobject_x` | 614 | 6.5s |  |
| 316 | `displayobject_y` | 617 | 6.5s |  |
| 317 | `displayobject_z` | 38 | 26.9s |  |
| 318 | `displayobjectcontainer_addchild` | 32 | 6.8s |  |
| 319 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.6s |  |
| 320 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.6s |  |
| 321 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.7s |  |
| 322 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.8s |  |
| 323 | `displayobjectcontainer_addchildat` | 42 | 6.6s |  |
| 324 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.6s |  |
| 325 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.6s |  |
| 326 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.6s |  |
| 327 | `displayobjectcontainer_contains` | 66 | 26.9s |  |
| 328 | `displayobjectcontainer_getchildat` | 4 | 6.6s |  |
| 329 | `displayobjectcontainer_getchildbyname` | 9 | 6.7s |  |
| 330 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.6s |  |
| 331 | `displayobjectcontainer_getchildindex` | 28 | 6.7s |  |
| 332 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 27.1s |  |
| 333 | `displayobjectcontainer_removechild` | 10 | 6.6s |  |
| 334 | `displayobjectcontainer_removechild_errors` | 4 | 6.7s |  |
| 335 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.6s |  |
| 336 | `displayobjectcontainer_removechildat` | 18 | 6.6s |  |
| 337 | `displayobjectcontainer_removechildren` | 51 | 6.8s |  |
| 338 | `displayobjectcontainer_setchildindex` | 42 | 6.6s |  |
| 339 | `displayobjectcontainer_stopallmovieclips` | 2 | 28.0s |  |
| 340 | `displayobjectcontainer_swapchildren` | 42 | 4.9s |  |
| 341 | `displayobjectcontainer_swapchildrenat` | 42 | 5.7s |  |
| 342 | `displayobjectcontainer_timelineinstance` | 48 | 22.0s |  |
| 343 | `divide` | 1058 | 13.1s |  |
| 344 | `doabc_and_symbolclass_script_init_goto` | 7 | 22.2s |  |
| 345 | `doabc_and_symbolclass_script_init_normal` | 6 | 5.7s |  |
| 346 | `doabc_is_eager` | 1 | 21.7s |  |
| 347 | `documentclass` | 9 | 5.8s |  |
| 348 | `domain_memory` | 133 | 6.7s |  |
| 349 | `drag_drop` | 10 | 5.9s |  |
| 350 | `drop_shadow_filter` | 172 | 5.8s |  |
| 351 | `duplicate_defs` | 1 | 5.5s |  |
| 352 | `eager_init` | 1 | 5.5s |  |
| 353 | `east_asian_justifier_clone` | 8 | 5.7s |  |
| 354 | `edit_text_linkage` | 7 | 5.8s |  |
| 355 | `edittext_align` | 60 | 6.2s |  |
| 356 | `edittext_always_show_selection` | 0 | 22.1s |  |
| 357 | `edittext_antialiastype` | 296 | 6.0s |  |
| 358 | `edittext_at_point_methods_basic` | 16 | 6.8s |  |
| 359 | `edittext_autosize` | 39 | 6.1s |  |
| 360 | `edittext_autosize_align` | 0 | 22.0s |  |
| 361 | `edittext_autosize_height_dynamic` | 60 | 22.0s |  |
| 362 | `edittext_autosize_height_input` | 60 | 5.8s |  |
| 363 | `edittext_autosize_lazy_bounds_events` | 65 | 5.9s |  |
| 364 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.8s |  |
| 365 | `edittext_autosize_lazy_bounds_props` | 490 | 7.1s |  |
| 366 | `edittext_autosize_lazy_bounds_visual` | 0 | 5.8s |  |
| 367 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.9s |  |
| 368 | `edittext_bottom_scroll_v_basic` | 210 | 5.8s |  |
| 369 | `edittext_bounds_scale` | 24 | 21.9s |  |
| 370 | `edittext_bullet` | 30 | 5.9s |  |
| 371 | `edittext_default_format` | 221 | 6.1s |  |
| 372 | `edittext_default_format_empty` | 136 | 6.0s |  |
| 373 | `edittext_empty_text_format` | 7 | 5.7s |  |
| 374 | `edittext_event_link_case_insensitive` | 1 | 5.7s |  |
| 375 | `edittext_focus_selection` | 5 | 5.7s |  |
| 376 | `edittext_font_size` | 45 | 5.9s |  |
| 377 | `edittext_format_empty_font` | 8 | 5.5s |  |
| 378 | `edittext_get_char_index_at_point` | 4 | 23.2s |  |
| 379 | `edittext_get_line_index_at_point` | 2 | 22.0s |  |
| 380 | `edittext_get_line_index_of_char` | 76 | 6.5s |  |
| 381 | `edittext_getcharboundaries` | 172 | 6.1s |  |
| 382 | `edittext_getcharboundaries_missing_glyphs` | 63 | 8.2s |  |
| 383 | `edittext_getcharboundaries_scroll` | 85 | 8.3s |  |
| 384 | `edittext_getlinemetrics` | 146 | 8.4s |  |
| 385 | `edittext_html` | 3101 | 8.5s |  |
| 386 | `edittext_html_condensewhite` | 487 | 8.1s |  |
| 387 | `edittext_html_entity` | 4 | 8.4s |  |
| 388 | `edittext_html_font_size_swf12` | 267 | 8.0s |  |
| 389 | `edittext_html_font_size_swf13` | 273 | 7.5s |  |
| 390 | `edittext_html_roundtrip` | 17 | 8.1s |  |
| 391 | `edittext_ime_focus_lost` | 9 | 28.7s |  |
| 392 | `edittext_input_control` | 12 | 8.2s |  |
| 393 | `edittext_leading` | 9 | 8.4s |  |
| 394 | `edittext_letter_spacing` | 15 | 8.0s |  |
| 395 | `edittext_line_methods` | 294 | 9.6s |  |
| 396 | `edittext_line_metrics` | 11 | 30.4s |  |
| 397 | `edittext_margins` | 25 | 8.1s |  |
| 398 | `edittext_max_scroll_h_basic` | 475 | 8.2s |  |
| 399 | `edittext_max_scroll_v_basic` | 1000 | 8.0s |  |
| 400 | `edittext_mouse_selection` | 363 | 30.2s |  |
| 401 | `edittext_mousedown` | 3 | 8.3s |  |
| 402 | `edittext_mouseenabled` | 26 | 7.9s |  |
| 403 | `edittext_newline_character` | 22 | 7.9s |  |
| 404 | `edittext_newline_stripping` | 64 | 16.4s |  |
| 405 | `edittext_newlines` | 30 | 8.1s |  |
| 406 | `edittext_paragraph_methods` | 257 | 7.8s |  |
| 407 | `edittext_paste_events` | 8 | 8.2s |  |
| 408 | `edittext_paste_maxchars` | 4 | 8.0s |  |
| 409 | `edittext_paste_restrict` | 16 | 7.7s |  |
| 410 | `edittext_restrict` | 191 | 8.0s |  |
| 411 | `edittext_restrict_events` | 22 | 2.7s |  |
| 412 | `edittext_scroll_event` | 37 | 8.2s |  |
| 413 | `edittext_scrollh` | 10 | 7.9s |  |
| 414 | `edittext_selected_text` | 9 | 7.9s |  |
| 415 | `edittext_set_html_same` | 17 | 7.9s |  |
| 416 | `edittext_set_text_vs_html` | 9 | 7.8s |  |
| 417 | `edittext_stylesheet` | 536 | 8.4s |  |
| 418 | `edittext_stylesheet_custom_tag` | 76 | 8.0s |  |
| 419 | `edittext_stylesheet_display` | 272 | 8.1s |  |
| 420 | `edittext_tag_indent` | 49 | 29.0s |  |
| 421 | `edittext_underline` | 40 | 8.1s |  |
| 422 | `edittext_width_height` | 103 | 8.3s |  |
| 423 | `edittext_wordwrap_word` | 150 | 8.1s |  |
| 424 | `edittext_wrap_breaks` | 2375 | 5.7s |  |
| 425 | `element_format_clone` | 44 | 5.3s |  |
| 426 | `element_format_constructor_order` | 64 | 5.3s |  |
| 427 | `element_format_properties` | 235 | 5.9s |  |
| 428 | `empty_bounds` | 1 | 5.0s |  |
| 429 | `encode_uri_surrogate_pair_invalid` | 8 | 5.1s |  |
| 430 | `encode_uri_surrogate_pair_swf11` | 15 | 4.8s |  |
| 431 | `equals` | 512 | 7.6s |  |
| 432 | `error_geterrormessage` | 779 | 1.9s |  |
| 433 | `error_prototype` | 15 | 5.2s |  |
| 434 | `error_stack_trace` | 45 | 5.1s |  |
| 435 | `error_stack_trace_debug_swf17` | 0 | 17.8s |  |
| 436 | `error_stack_trace_debug_swf18` | 0 | 4.8s |  |
| 437 | `error_stack_trace_edge_cases` | 6 | 5.0s |  |
| 438 | `error_stack_trace_release_swf17` | 0 | 1.7s |  |
| 439 | `error_stack_trace_release_swf18` | 0 | 4.9s |  |
| 440 | `error_throwerror` | 103 | 5.3s |  |
| 441 | `error_tostring` | 29 | 5.1s |  |
| 442 | `error_tostring_more` | 86 | 5.2s |  |
| 443 | `es3_inheritance` | 31 | 5.2s |  |
| 444 | `es4_inheritance` | 30 | 5.2s |  |
| 445 | `es4_interfaces` | 30 | 5.3s |  |
| 446 | `es4_method_binding` | 8 | 5.2s |  |
| 447 | `es4_oop_prototypes` | 14 | 5.3s |  |
| 448 | `es4_protected_inheritance` | 6 | 4.9s |  |
| 449 | `escape` | 71 | 5.1s |  |
| 450 | `escape_multi_byte` | 45 | 5.2s |  |
| 451 | `event_bubbles` | 2 | 5.0s |  |
| 452 | `event_cancelable` | 2 | 4.9s |  |
| 453 | `event_clone` | 20 | 5.1s |  |
| 454 | `event_clone_error_redispatch` | 3 | 5.2s |  |
| 455 | `event_clone_on_redispatch` | 10 | 5.0s |  |
| 456 | `event_formattostring` | 31 | 5.1s |  |
| 457 | `event_isdefaultprevented` | 12 | 5.0s |  |
| 458 | `event_target_getter` | 5 | 1.7s |  |
| 459 | `event_target_set` | 9 | 5.0s |  |
| 460 | `event_type` | 1 | 5.0s |  |
| 461 | `event_valueof_tostring` | 18 | 5.1s |  |
| 462 | `eventdispatcher_dispatchevent` | 12 | 1.7s |  |
| 463 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.0s |  |
| 464 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.7s |  |
| 465 | `eventdispatcher_dispatchevent_indirect` | 9 | 21.6s |  |
| 466 | `eventdispatcher_dispatchevent_this` | 5 | 5.6s |  |
| 467 | `eventdispatcher_haseventlistener` | 25 | 5.7s |  |
| 468 | `eventdispatcher_interface_invoke` | 1 | 5.5s |  |
| 469 | `eventdispatcher_tostring` | 10 | 5.6s |  |
| 470 | `eventdispatcher_willtrigger` | 25 | 5.5s |  |
| 471 | `external_interface` | 105 | 5.8s |  |
| 472 | `falsiness` | 30 | 5.6s |  |
| 473 | `fast_index_access` | 12 | 5.7s |  |
| 474 | `filefilter_properties` | 4 | 5.6s |  |
| 475 | `filereference_browse_cancel` | 3 | 5.7s |  |
| 476 | `filereference_browse_select` | 9 | 5.7s |  |
| 477 | `filereference_load` | 31 | 5.7s |  |
| 478 | `filereference_save` | 16 | 5.7s |  |
| 479 | `filereference_save_and_browse` | 42 | 5.7s |  |
| 480 | `filereference_save_and_load` | 22 | 5.6s |  |
| 481 | `filereference_uninitialized` | 8 | 5.5s |  |
| 482 | `filereferencelist_browse_cancel` | 6 | 5.5s |  |
| 483 | `filereferencelist_browse_select` | 7 | 5.5s |  |
| 484 | `filter_rewind` | 8 | 21.3s |  |
| 485 | `filters_array_holes` | 25 | 5.6s |  |
| 486 | `finddef` | 3 | 5.5s |  |
| 487 | `findprop_global_prototype` | 6 | 5.6s |  |
| 488 | `flash_media_video_constructor` | 156 | 6.3s |  |
| 489 | `flash_media_video_rotation_probe` | 27 | 5.7s |  |
| 490 | `flash_media_video_setter` | 40 | 6.0s |  |
| 491 | `flash_trace` | 17 | 5.6s |  |
| 492 | `flash_ui_mouse_cursor` | 35 | 5.9s |  |
| 493 | `flash_xml` | 29 | 5.7s |  |
| 494 | `flash_xml_cloneNode` | 22 | 5.7s |  |
| 495 | `flash_xml_namespace` | 109 | 5.6s |  |
| 496 | `flash_xml_removeNode` | 60 | 5.6s |  |
| 497 | `focus_events_code` | 161 | 21.8s |  |
| 498 | `focus_events_key_basic` | 132 | 21.5s |  |
| 499 | `focus_events_key_navigation` | 53 | 21.2s |  |
| 500 | `focus_events_key_same_object` | 26 | 5.6s |  |
| 501 | `focus_events_mixed_avm_edittext` | 49 | 6.0s |  |
| 502 | `focus_events_mixed_key_mouse` | 100 | 21.2s |  |
| 503 | `focus_events_mouse_basic` | 260 | 21.6s |  |
| 504 | `focus_events_mouse_focusable` | 112 | 21.6s |  |
| 505 | `focus_events_mouse_same_object` | 40 | 5.7s |  |
| 506 | `focus_remove` | 20 | 21.5s |  |
| 507 | `focus_root_movie` | 4 | 21.3s |  |
| 508 | `focus_stage` | 1 | 5.6s |  |
| 509 | `focusrect` | 18 | 26.3s |  |
| 510 | `focusrect_focuslost` | 9 | 7.2s |  |
| 511 | `focusrect_property` | 110 | 25.0s |  |
| 512 | `font_description_clone` | 14 | 6.7s |  |
| 513 | `font_embedded` | 24 | 7.6s |  |
| 514 | `font_enumeratefonts` | 41 | 7.7s |  |
| 515 | `font_enumeratefonts_filter` | 4 | 7.6s |  |
| 516 | `font_enumeratefonts_order` | 9 | 8.3s |  |
| 517 | `font_hasglyphs` | 40 | 7.3s |  |
| 518 | `font_registerfont` | 129 | 8.1s |  |
| 519 | `framelabel_constr` | 5 | 7.1s |  |
| 520 | `function_call` | 12 | 2.4s |  |
| 521 | `function_call_arguments` | 46 | 7.1s |  |
| 522 | `function_call_arguments_enumerate` | 5 | 6.8s |  |
| 523 | `function_call_coercion` | 108 | 7.3s |  |
| 524 | `function_call_default` | 6 | 6.9s |  |
| 525 | `function_call_rest` | 22 | 6.9s |  |
| 526 | `function_call_types` | 3 | 7.0s |  |
| 527 | `function_call_via_apply` | 11 | 6.9s |  |
| 528 | `function_call_via_call` | 3 | 6.7s |  |
| 529 | `function_display_anonymous` | 7 | 2.4s |  |
| 530 | `function_length` | 6 | 6.8s |  |
| 531 | `function_object` | 2 | 6.7s |  |
| 532 | `function_proto` | 5 | 6.8s |  |
| 533 | `function_proto_created` | 61 | 6.9s |  |
| 534 | `function_to_locale_string` | 4 | 6.8s |  |
| 535 | `function_to_string` | 4 | 6.7s |  |
| 536 | `function_type` | 6 | 6.7s |  |
| 537 | `function_unbound_this` | 51 | 6.9s |  |
| 538 | `function_value_of` | 4 | 6.7s |  |
| 539 | `game_input` | 4 | 6.7s |  |
| 540 | `generate_random_bytes` | 3 | 6.9s |  |
| 541 | `geom_transform` | 74 | 25.3s |  |
| 542 | `get_definition_by_name` | 11 | 6.8s |  |
| 543 | `get_qualified_class_name` | 20 | 6.8s |  |
| 544 | `get_qualified_super_class_name` | 18 | 6.8s |  |
| 545 | `get_slot_edge_cases` | 1 | 6.7s |  |
| 546 | `get_timer` | 2 | 2.3s |  |
| 547 | `getglobalslot` | 1 | 6.6s |  |
| 548 | `getouterscope` | 8 | 6.8s |  |
| 549 | `getouterscope_two_classobjects` | 13 | 6.3s |  |
| 550 | `getter_different_namespace_setter` | 2 | 6.3s |  |
| 551 | `glow_filter` | 127 | 6.5s |  |
| 552 | `goto_button_nested_framescript` | 28 | 22.7s |  |
| 553 | `goto_framescript_queued/swf10` | 59 | 21.1s |  |
| 554 | `goto_framescript_queued/swf9` | 52 | 0.4s |  |
| 555 | `goto_framescript_queued_same_frame` | 4 | 20.9s |  |
| 556 | `goto_in_constructframe` | 12 | 21.3s |  |
| 557 | `goto_in_scene_last_frame` | 2 | 21.1s |  |
| 558 | `goto_methods` | 56 | 5.8s |  |
| 559 | `goto_methods_swfver10` | 8 | 5.5s |  |
| 560 | `goto_nested_construct_sibling` | 18 | 6.0s |  |
| 561 | `goto_nested_framescript` | 9 | 5.6s |  |
| 562 | `goto_on_orphan` | 15 | 21.1s |  |
| 563 | `goto_queued_invalid/swf10` | 34 | 21.4s |  |
| 564 | `goto_queued_invalid/swf11` | 43 | 0.4s |  |
| 565 | `goto_queued_invalid/swf9` | 32 | 0.4s |  |
| 566 | `gradient_bevel_filter` | 206 | 5.7s |  |
| 567 | `gradient_glow_filter` | 206 | 5.5s |  |
| 568 | `graphic_linkage` | 9 | 5.6s |  |
| 569 | `graphics_bad_direct_commands` | 5 | 6.0s |  |
| 570 | `graphics_bitmap_fill` | 0 | 7.0s |  |
| 571 | `graphics_bitmaps` | 0 | 5.7s |  |
| 572 | `graphics_direct_commands` | 0 | 5.7s |  |
| 573 | `graphics_draw_triangles` | 98 | 22.0s |  |
| 574 | `graphics_gradients` | 0 | 5.7s |  |
| 575 | `graphics_gradients_nulls` | 0 | 5.5s |  |
| 576 | `graphics_path` | 56 | 5.5s |  |
| 577 | `graphics_round_rects` | 0 | 5.5s |  |
| 578 | `graphics_simple_shapes` | 0 | 5.5s |  |
| 579 | `greaterequals` | 512 | 7.9s |  |
| 580 | `greaterthan` | 512 | 7.9s |  |
| 581 | `has_own_property` | 102 | 6.0s |  |
| 582 | `hasownproperty_namespaces` | 2 | 5.5s |  |
| 583 | `hello_world` | 1 | 5.5s |  |
| 584 | `hittest_morph` | 30 | 5.6s |  |
| 585 | `id3_info` | 8 | 16.9s |  |
| 586 | `if_eq` | 10 | 5.4s |  |
| 587 | `if_gt` | 1 | 5.6s |  |
| 588 | `if_gte` | 10 | 1.6s |  |
| 589 | `if_lt` | 1 | 0.4s |  |
| 590 | `if_lte` | 10 | 5.4s |  |
| 591 | `if_ne` | 7 | 1.6s |  |
| 592 | `if_stricteq` | 6 | 5.5s |  |
| 593 | `if_strictne` | 11 | 5.5s |  |
| 594 | `ime_linux_dead_keys` | 10 | 5.7s |  |
| 595 | `in` | 102 | 5.9s |  |
| 596 | `inclocal` | 46 | 5.5s |  |
| 597 | `inclocal_i` | 46 | 5.5s |  |
| 598 | `increment` | 46 | 5.5s |  |
| 599 | `increment_i` | 46 | 1.6s |  |
| 600 | `indexing_delete` | 75 | 5.5s |  |
| 601 | `indexof_xml` | 10 | 5.6s |  |
| 602 | `init_callee_cached` | 24 | 5.5s |  |
| 603 | `instanceof` | 58 | 5.8s |  |
| 604 | `instantiate_root_character` | 4 | 5.6s |  |
| 605 | `instantiation_on_enter_frame` | 7 | 21.0s |  |
| 606 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.5s |  |
| 607 | `int_constr` | 92 | 5.7s |  |
| 608 | `int_edge_cases` | 19 | 5.6s |  |
| 609 | `int_instanceof` | 3 | 5.4s |  |
| 610 | `int_tofixed` | 1215 | 5.4s |  |
| 611 | `int_toprecision` | 1125 | 5.6s |  |
| 612 | `int_tostring` | 3375 | 5.7s |  |
| 613 | `interactiveobject_enabled` | 25 | 5.5s |  |
| 614 | `interface_namespaces` | 78 | 5.7s |  |
| 615 | `invalid_utf8` | 12 | 5.6s |  |
| 616 | `is_finite` | 46 | 5.6s |  |
| 617 | `is_nan` | 46 | 5.4s |  |
| 618 | `is_prototype_of` | 12 | 5.5s |  |
| 619 | `issue_10221` | 2 | 5.5s |  |
| 620 | `issue_13780` | 12 | 5.5s |  |
| 621 | `issue_14901` | 1 | 5.5s |  |
| 622 | `issue_17675_edittext_paste_maxchars` | 1 | 5.4s |  |
| 623 | `issue_5292` | 5 | 1.6s |  |
| 624 | `issue_8630` | 2 | 5.5s |  |
| 625 | `issue_8630_placeremoveplace` | 15 | 5.6s |  |
| 626 | `issue_8630_placeremoveplace_scriptremove` | 16 | 5.5s |  |
| 627 | `issue_8630_scriptremove` | 11 | 5.6s |  |
| 628 | `istype` | 24 | 1.7s |  |
| 629 | `istypelate` | 58 | 5.9s |  |
| 630 | `istypelate_coerce` | 198 | 6.4s |  |
| 631 | `jpeg_loader_context` | 6 | 5.6s |  |
| 632 | `json_errors` | 9 | 21.5s |  |
| 633 | `json_parse` | 21 | 5.6s |  |
| 634 | `json_parse_errors` | 84 | 5.5s |  |
| 635 | `json_stringify` | 12 | 1.8s |  |
| 636 | `json_stringify_function` | 12 | 5.4s |  |
| 637 | `json_stringify_order` | 1 | 5.5s |  |
| 638 | `json_version_gated` | 1 | 5.5s |  |
| 639 | `key_input_80percent` | 1812 | 5.8s |  |
| 640 | `key_input_location` | 126 | 5.7s |  |
| 641 | `key_input_numpad` | 384 | 1.6s |  |
| 642 | `large_preload_from_bytes` | 51 | 8.4s |  |
| 643 | `large_preload_from_url` | 27 | 7.3s |  |
| 644 | `large_preload_image_from_bytes` | 25 | 6.0s |  |
| 645 | `lazyinit` | 17 | 5.5s |  |
| 646 | `lessequals` | 512 | 8.0s |  |
| 647 | `lessthan` | 512 | 8.1s |  |
| 648 | `loader_bitmap_transparency` | 14 | 5.7s |  |
| 649 | `loader_bytes_unknown_content` | 14 | 5.7s |  |
| 650 | `loader_child_getdefinition` | 5 | 5.8s |  |
| 651 | `loader_duplicate_class` | 48 | 7.0s |  |
| 652 | `loader_duplicate_coerce` | 3 | 5.8s |  |
| 653 | `loader_duplicate_coerce_new_domain` | 4 | 1.7s |  |
| 654 | `loader_error_in_root_ctor` | 4 | 5.7s |  |
| 655 | `loader_events` | 92 | 6.0s |  |
| 656 | `loader_image` | 8 | 1.7s |  |
| 657 | `loader_jpegxr` | 2 | 21.4s |  |
| 658 | `loader_jpegxr_alpha` | 1 | 21.0s |  |
| 659 | `loader_loadbytes_events` | 30 | 6.0s |  |
| 660 | `loader_loadbytes_invalid_png` | 4 | 5.6s |  |
| 661 | `loader_loadbytes_url` | 12 | 5.8s |  |
| 662 | `loader_loaderurl` | 6 | 6.0s |  |
| 663 | `loader_method` | 85 | 5.6s |  |
| 664 | `loader_noninteractive_try_click_root` | 5 | 21.6s |  |
| 665 | `loader_reuse` | 38 | 5.8s |  |
| 666 | `loader_try_click_root` | 16 | 5.8s |  |
| 667 | `loader_unknown_content` | 24 | 5.8s |  |
| 668 | `loader_unloadandstop_subclass` | 1 | 5.6s |  |
| 669 | `loader_visibility_interactive` | 1 | 5.7s |  |
| 670 | `loaderinfo_child_progress` | 9 | 6.1s |  |
| 671 | `loaderinfo_events` | 7 | 5.6s |  |
| 672 | `loaderinfo_loadurl` | 12 | 5.6s |  |
| 673 | `loaderinfo_more` | 6 | 5.8s |  |
| 674 | `loaderinfo_properties` | 18 | 21.5s |  |
| 675 | `loaderinfo_properties_not_loaded` | 23 | 5.7s |  |
| 676 | `loaderinfo_quine` | 1005 | 33.6s |  |
| 677 | `loaderinfo_root` | 10 | 5.9s |  |
| 678 | `loaderinfo_root_allows` | 2 | 5.4s |  |
| 679 | `localconnection` | 890 | 7.3s |  |
| 680 | `localconnection_send` | 4 | 5.7s |  |
| 681 | `lshift` | 1058 | 12.9s |  |
| 682 | `mask_reapply` | 1 | 20.0s |  |
| 683 | `math` | 497 | 5.6s |  |
| 684 | `matrix` | 338 | 12.2s |  |
| 685 | `matrix3d` | 57 | 18.7s |  |
| 686 | `matrix3d_append` | 16 | 5.3s |  |
| 687 | `matrix3d_append_prepend_scale` | 86 | 5.4s |  |
| 688 | `matrix3d_append_prepend_translation` | 42 | 5.3s |  |
| 689 | `matrix3d_append_rotation` | 23 | 5.8s |  |
| 690 | `matrix3d_compose` | 34 | 5.8s |  |
| 691 | `matrix3d_constructor_clone` | 15 | 5.2s |  |
| 692 | `matrix3d_copy_column` | 83 | 5.3s |  |
| 693 | `matrix3d_copy_from` | 19 | 5.3s |  |
| 694 | `matrix3d_copy_raw_data_from` | 55 | 1.9s |  |
| 695 | `matrix3d_copy_raw_data_to` | 38 | 5.4s |  |
| 696 | `matrix3d_copy_row` | 83 | 5.2s |  |
| 697 | `matrix3d_copy_to_matrix3d` | 19 | 5.1s |  |
| 698 | `matrix3d_determinant` | 182 | 5.4s |  |
| 699 | `matrix3d_interpolate` | 21 | 5.5s |  |
| 700 | `matrix3d_invert` | 18 | 5.2s |  |
| 701 | `matrix3d_position` | 19 | 5.5s |  |
| 702 | `matrix3d_precision` | 28 | 5.6s |  |
| 703 | `matrix3d_prepend` | 16 | 5.4s |  |
| 704 | `matrix3d_raw_data` | 33 | 5.3s |  |
| 705 | `matrix3d_transform_vector` | 52 | 5.6s |  |
| 706 | `matrix3d_transpose` | 5 | 5.4s |  |
| 707 | `method_association` | 5 | 5.4s |  |
| 708 | `method_without_body` | 3 | 18.5s |  |
| 709 | `missing_external_interface` | 10 | 5.3s |  |
| 710 | `modulo` | 1058 | 11.7s |  |
| 711 | `morph_shape` | 2 | 18.8s |  |
| 712 | `mouse_children` | 192 | 18.5s |  |
| 713 | `mouse_click_events` | 90 | 18.6s |  |
| 714 | `mouse_double_click_events` | 188 | 5.3s |  |
| 715 | `mouse_empty_parent` | 4 | 5.2s |  |
| 716 | `mouse_over_while_dragging` | 3 | 5.3s |  |
| 717 | `mouse_pick_avm1_root` | 2 | 21.9s |  |
| 718 | `mouse_pick_button_mode` | 2 | 5.9s |  |
| 719 | `mouse_pick_dobj_mask` | 4 | 5.7s |  |
| 720 | `mouse_pick_loader_avm1` | 42 | 6.1s |  |
| 721 | `mouse_pick_masking` | 7 | 21.7s |  |
| 722 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 21.7s |  |
| 723 | `mouse_pick_non_interactive_dobj_mask` | 3 | 5.7s |  |
| 724 | `mouse_pick_scroll_rect` | 27 | 21.8s |  |
| 725 | `mouse_pick_scroll_rect_button` | 5 | 5.8s |  |
| 726 | `mouse_pick_scroll_rect_loader` | 5 | 6.0s |  |
| 727 | `mouse_pick_text` | 8 | 5.8s |  |
| 728 | `mouse_sibling` | 8 | 5.8s |  |
| 729 | `mouse_wheel_events` | 36 | 22.5s |  |
| 730 | `mouseevent_constr` | 66 | 5.7s |  |
| 731 | `mouseevent_stagexy` | 35 | 5.7s |  |
| 732 | `mouseevent_valueof_tostring` | 28 | 5.7s |  |
| 733 | `movieclip_addframescript` | 3 | 21.7s |  |
| 734 | `movieclip_addframescript_error` | 9 | 5.5s |  |
| 735 | `movieclip_child_property` | 16 | 5.7s |  |
| 736 | `movieclip_constr` | 21 | 5.7s |  |
| 737 | `movieclip_currentlabels` | 17 | 21.6s |  |
| 738 | `movieclip_currentlabels_dupes1` | 46 | 21.8s |  |
| 739 | `movieclip_currentlabels_dupes2` | 30 | 5.7s |  |
| 740 | `movieclip_currentlabels_dupes3` | 67 | 5.7s |  |
| 741 | `movieclip_currentscene` | 12 | 21.6s |  |
| 742 | `movieclip_dispatchevent` | 430 | 5.8s |  |
| 743 | `movieclip_dispatchevent_cancel` | 102 | 5.8s |  |
| 744 | `movieclip_dispatchevent_handlerorder` | 251 | 5.8s |  |
| 745 | `movieclip_dispatchevent_selfadd` | 80 | 5.7s |  |
| 746 | `movieclip_dispatchevent_target` | 899 | 5.8s |  |
| 747 | `movieclip_displayevents` | 96 | 21.9s |  |
| 748 | `movieclip_displayevents_clickgoto` | 676 | 22.1s |  |
| 749 | `movieclip_displayevents_clickgoto2` | 2001 | 6.3s |  |
| 750 | `movieclip_displayevents_clickplay` | 575 | 6.0s |  |
| 751 | `movieclip_displayevents_clicksymbol` | 562 | 6.0s |  |
| 752 | `movieclip_displayevents_constructframegoto` | 140 | 6.1s |  |
| 753 | `movieclip_displayevents_constructframeplay` | 50 | 6.0s |  |
| 754 | `movieclip_displayevents_constructframesymbol` | 144 | 5.9s |  |
| 755 | `movieclip_displayevents_dblhandler` | 21 | 5.7s |  |
| 756 | `movieclip_displayevents_enterframegoto` | 149 | 6.0s |  |
| 757 | `movieclip_displayevents_enterframeplay` | 48 | 5.8s |  |
| 758 | `movieclip_displayevents_enterframesymbol` | 149 | 21.9s |  |
| 759 | `movieclip_displayevents_exitframegoto` | 106 | 5.8s |  |
| 760 | `movieclip_displayevents_exitframeplay` | 44 | 5.8s |  |
| 761 | `movieclip_displayevents_exitframesymbol` | 135 | 22.8s |  |
| 762 | `movieclip_displayevents_looping` | 63 | 22.7s |  |
| 763 | `movieclip_displayevents_stopped` | 113 | 22.4s |  |
| 764 | `movieclip_displayevents_swap` | 96 | 6.0s |  |
| 765 | `movieclip_displayevents_timeline` | 128 | 22.8s |  |
| 766 | `movieclip_drawrect` | 54 | 5.8s |  |
| 767 | `movieclip_frameconstruct_skipped` | 9 | 5.9s |  |
| 768 | `movieclip_goto_during_frame_script` | 15 | 22.3s |  |
| 769 | `movieclip_goto_overwrite` | 14 | 22.2s |  |
| 770 | `movieclip_goto_scene_last_frame_int` | 1 | 22.2s |  |
| 771 | `movieclip_goto_scene_last_frame_label` | 1 | 5.7s |  |
| 772 | `movieclip_gotoandplay` | 15 | 22.4s |  |
| 773 | `movieclip_gotoandstop` | 13 | 5.8s |  |
| 774 | `movieclip_gotoandstop_children` | 4 | 5.9s |  |
| 775 | `movieclip_gotoandstop_framescripts1` | 4 | 5.8s |  |
| 776 | `movieclip_gotoandstop_framescripts2` | 4 | 1.7s |  |
| 777 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.4s |  |
| 778 | `movieclip_gotoandstop_queueing` | 12 | 6.0s |  |
| 779 | `movieclip_hittest` | 67 | 6.0s |  |
| 780 | `movieclip_next_frame` | 2 | 1.8s |  |
| 781 | `movieclip_next_scene` | 6 | 5.9s |  |
| 782 | `movieclip_play` | 3 | 5.8s |  |
| 783 | `movieclip_prev_frame` | 3 | 5.6s |  |
| 784 | `movieclip_prev_scene` | 7 | 5.9s |  |
| 785 | `movieclip_properties` | 79 | 22.5s |  |
| 786 | `movieclip_queued_noop_goto_swf10` | 9 | 5.8s |  |
| 787 | `movieclip_queued_noop_goto_swf9` | 7 | 0.4s |  |
| 788 | `movieclip_scenes` | 11 | 5.7s |  |
| 789 | `movieclip_soundtransform` | 831 | 23.9s |  |
| 790 | `movieclip_stop` | 1 | 5.7s |  |
| 791 | `movieclip_super_is_symbol` | 20 | 6.0s |  |
| 792 | `movieclip_symbol_constr` | 8 | 5.9s |  |
| 793 | `movieclip_text_mousedown` | 1 | 5.8s |  |
| 794 | `movieclip_willtrigger` | 5 | 5.8s |  |
| 795 | `multiply` | 1058 | 13.2s |  |
| 796 | `namespace_constr` | 253 | 6.0s |  |
| 797 | `namespace_constr_args` | 1 | 5.7s |  |
| 798 | `namespace_enumeration_order` | 7 | 5.7s |  |
| 799 | `nan_scale` | 9 | 5.7s |  |
| 800 | `native_menu_basic` | 19 | 7.7s |  |
| 801 | `navigateToURL_target_normalize` | 107 | 23.9s |  |
| 802 | `negate` | 30 | 5.7s |  |
| 803 | `negative_volume_panned` | 0 | 6.0s |  |
| 804 | `nested_iteration` | 11 | 5.8s |  |
| 805 | `net_getClassByAlias` | 3 | 5.8s |  |
| 806 | `net_navigateToURL` | 57 | 24.2s |  |
| 807 | `net_stream_play_options` | 6 | 5.7s |  |
| 808 | `netconnection_call_with_responder` | 6 | 21.9s |  |
| 809 | `netconnection_close` | 55 | 5.7s |  |
| 810 | `netconnection_properties` | 78 | 5.8s |  |
| 811 | `netconnection_send_remote` | 50 | 5.9s |  |
| 812 | `netconnection_serialize_arrays` | 6 | 5.7s |  |
| 813 | `netfilterevent` | 10 | 5.7s |  |
| 814 | `netstream_client` | 10 | 5.8s |  |
| 815 | `netstream_connect` | 7 | 5.7s |  |
| 816 | `netstream_flv_date` | 4 | 5.8s |  |
| 817 | `newactivation_in_script_init` | 3 | 5.7s |  |
| 818 | `newclass_mismatched` | 4 | 5.7s |  |
| 819 | `newclass_twice` | 3 | 5.7s |  |
| 820 | `nonconflicting_declarations` | 0 | 5.7s |  |
| 821 | `null_void_types` | 8 | 5.8s |  |
| 822 | `number_autoconv` | 21 | 5.7s |  |
| 823 | `number_autoconv_amf` | 132 | 5.7s |  |
| 824 | `number_autoconv_array_sort_32bit` | 1 | 5.6s |  |
| 825 | `number_constr` | 58 | 5.7s |  |
| 826 | `number_convert_edge_cases` | 180 | 21.5s |  |
| 827 | `number_toexponential` | 378 | 5.7s |  |
| 828 | `number_toexponential2` | 35 | 5.5s |  |
| 829 | `number_tofixed` | 378 | 5.6s |  |
| 830 | `number_toprecision` | 350 | 5.7s |  |
| 831 | `obfuscated_class_names` | 3 | 5.7s |  |
| 832 | `object_enumeration` | 10 | 5.6s |  |
| 833 | `object_prototype` | 4 | 5.7s |  |
| 834 | `object_to_locale_string` | 2 | 5.7s |  |
| 835 | `object_to_string` | 2 | 5.7s |  |
| 836 | `object_value_of` | 2 | 1.6s |  |
| 837 | `op_coerce` | 54 | 5.8s |  |
| 838 | `op_coerce_x` | 54 | 5.8s |  |
| 839 | `op_escxattr` | 2 | 5.7s |  |
| 840 | `op_escxelem` | 2 | 1.7s |  |
| 841 | `op_lookupswitch` | 4 | 5.7s |  |
| 842 | `optimize_coerce` | 1 | 5.7s |  |
| 843 | `orphan_movie_complex` | 80 | 8.3s |  |
| 844 | `orphan_movie_reorder` | 111 | 28.4s |  |
| 845 | `orphan_removeobject` | 636 | 29.1s |  |
| 846 | `package_namespace` | 7 | 7.8s |  |
| 847 | `param_default_value_has_zero_cpool_index` | 1 | 7.8s |  |
| 848 | `parent_early_access_child` | 16 | 28.6s |  |
| 849 | `parse_float` | 81 | 8.0s |  |
| 850 | `parse_float_swf10` | 81 | 7.8s |  |
| 851 | `parse_int` | 135 | 8.3s |  |
| 852 | `perspective_projection` | 1443 | 28.7s |  |
| 853 | `perspective_projection_basic` | 40 | 7.8s |  |
| 854 | `perspective_projection_center` | 34 | 8.0s |  |
| 855 | `pixelbender_ceil` | 77 | 8.1s |  |
| 856 | `pixelbender_conditional` | 138 | 8.3s |  |
| 857 | `pixelbender_conversions` | 270 | 8.2s |  |
| 858 | `pixelbender_dithering` | 8 | 33.6s |  |
| 859 | `pixelbender_div` | 36 | 8.0s |  |
| 860 | `pixelbender_effect_BlurredFocus` | 0 | 36.8s |  |
| 861 | `pixelbender_effect_glassDisplace` | 0 | 14.3s |  |
| 862 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 31.7s |  |
| 863 | `pixelbender_effect_smudge` | 0 | 11.7s |  |
| 864 | `pixelbender_effect_tintype` | 0 | 10.7s |  |
| 865 | `pixelbender_effect_twirl` | 0 | 12.2s |  |
| 866 | `pixelbender_eof` | 7 | 7.9s |  |
| 867 | `pixelbender_images` | 0 | 10.5s |  |
| 868 | `pixelbender_input` | 103 | 29.0s |  |
| 869 | `pixelbender_logicalnot` | 20 | 7.8s |  |
| 870 | `pixelbender_malformed_data` | 190 | 8.8s |  |
| 871 | `pixelbender_multiple_out_params` | 1 | 7.8s |  |
| 872 | `pixelbender_no_out_param` | 6 | 7.8s |  |
| 873 | `pixelbender_outputs` | 13 | 8.0s |  |
| 874 | `pixelbender_padding_bytes` | 22 | 7.9s |  |
| 875 | `pixelbender_param_qualifier` | 512 | 8.1s |  |
| 876 | `pixelbender_parameters` | 1563 | 8.4s |  |
| 877 | `pixelbender_parameters_bool` | 240 | 8.2s |  |
| 878 | `pixelbender_parameters_int_vs_bool` | 54 | 8.0s |  |
| 879 | `pixelbender_parse_errors` | 6 | 7.9s |  |
| 880 | `pixelbender_rsqrt` | 24 | 7.9s |  |
| 881 | `pixelbender_select_kinds` | 8 | 8.1s |  |
| 882 | `pixelbender_shaderdata` | 49 | 2.8s |  |
| 883 | `pixelbender_shaderdata_setter` | 99 | 8.2s |  |
| 884 | `pixelbender_sign` | 60 | 8.1s |  |
| 885 | `pixelbender_vector_output` | 11 | 8.1s |  |
| 886 | `place_and_lookup/swf10` | 33 | 7.9s |  |
| 887 | `place_and_lookup/swf9` | 33 | 41.2s |  |
| 888 | `place_multiple` | 17 | 23.7s |  |
| 889 | `place_object_replace` | 9 | 24.3s |  |
| 890 | `place_object_replace_2` | 24 | 24.4s |  |
| 891 | `place_object_same_depth_frame` | 1 | 6.8s |  |
| 892 | `point` | 132 | 7.1s |  |
| 893 | `primitive_edge_cases` | 1 | 6.9s |  |
| 894 | `primitive_keys` | 54 | 6.9s |  |
| 895 | `primitive_toString` | 277 | 6.9s |  |
| 896 | `primitive_valueOf` | 285 | 6.6s |  |
| 897 | `print_job_options` | 3 | 6.6s |  |
| 898 | `property_is_enumerable` | 114 | 8.2s |  |
| 899 | `property_is_enumerable_reset` | 23 | 7.2s |  |
| 900 | `property_priority` | 22 | 7.1s |  |
| 901 | `property_priority_chained` | 4 | 6.6s |  |
| 902 | `property_priority_definition_names_order` | 2 | 6.8s |  |
| 903 | `property_priority_three_level` | 6 | 6.9s |  |
| 904 | `propertyisenumerable_namespaces` | 6 | 6.6s |  |
| 905 | `prototype_set_null` | 7 | 6.5s |  |
| 906 | `proxy_callproperty` | 24 | 6.7s |  |
| 907 | `proxy_deleteproperty` | 64 | 6.8s |  |
| 908 | `proxy_enumeration` | 34 | 6.8s |  |
| 909 | `proxy_getproperty` | 77 | 6.9s |  |
| 910 | `proxy_hasownproperty` | 8 | 6.7s |  |
| 911 | `proxy_hasproperty` | 32 | 7.4s |  |
| 912 | `proxy_not_overridden` | 54 | 7.0s |  |
| 913 | `proxy_serialize` | 9 | 7.1s |  |
| 914 | `proxy_setproperty` | 42 | 7.1s |  |
| 915 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.8s |  |
| 916 | `qname_constr` | 32 | 7.0s |  |
| 917 | `qname_constr_namespace` | 24 | 6.9s |  |
| 918 | `qname_enumeration` | 9 | 7.5s |  |
| 919 | `qname_indexing` | 23 | 7.0s |  |
| 920 | `qname_tostring` | 25 | 6.9s |  |
| 921 | `qname_valueof` | 29 | 7.0s |  |
| 922 | `rectangle` | 1094 | 7.5s |  |
| 923 | `regexp_constr` | 148 | 7.1s |  |
| 924 | `regexp_exec` | 19 | 6.9s |  |
| 925 | `regexp_extended` | 47 | 6.9s |  |
| 926 | `regexp_multiargs` | 1 | 6.9s |  |
| 927 | `regexp_test` | 27 | 7.0s |  |
| 928 | `regexp_toString` | 10 | 7.0s |  |
| 929 | `register_script_refresh` | 35 | 26.2s |  |
| 930 | `remove_child_clear_field` | 88 | 19.3s |  |
| 931 | `remove_dobj` | 3 | 5.5s |  |
| 932 | `resolve_order` | 4 | 5.5s |  |
| 933 | `responder_null_callbacks` | 1 | 1.9s |  |
| 934 | `rng` | 1 | 6.6s |  |
| 935 | `rootless` | 42 | 5.7s |  |
| 936 | `rshift` | 1058 | 12.4s |  |
| 937 | `rtqname_not_namespace` | 12 | 5.7s |  |
| 938 | `sandbox_type_inherited` | 2 | 5.8s |  |
| 939 | `sandbox_type_local_file` | 1 | 5.0s |  |
| 940 | `sandbox_type_local_network` | 1 | 4.9s |  |
| 941 | `scene_constr` | 8 | 5.3s |  |
| 942 | `scope_optimizations` | 4 | 5.2s |  |
| 943 | `scopes_dont_cache/order-1` | 1 | 18.4s |  |
| 944 | `scopes_dont_cache/order-2` | 1 | 0.3s |  |
| 945 | `security_domain_current` | 2 | 5.3s |  |
| 946 | `selection` | 239 | 5.4s |  |
| 947 | `selection_onsetfocus_mixed_avm` | 5 | 15.1s |  |
| 948 | `set_local_0` | 31 | 5.4s |  |
| 949 | `set_property_is_enumerable` | 85 | 5.5s |  |
| 950 | `shaderparameter_value` | 4 | 5.0s |  |
| 951 | `shape_drawrect` | 54 | 5.2s |  |
| 952 | `shared_object_no_root` | 3 | 5.4s |  |
| 953 | `simplebutton_added_to_stage` | 45 | 18.8s |  |
| 954 | `simplebutton_childevents` | 86 | 18.8s |  |
| 955 | `simplebutton_childevents_nested` | 54 | 6.0s |  |
| 956 | `simplebutton_childevents_sprite` | 13 | 5.6s |  |
| 957 | `simplebutton_childprops` | 144 | 5.5s |  |
| 958 | `simplebutton_childshuffle` | 23 | 5.5s |  |
| 959 | `simplebutton_constr` | 36 | 5.7s |  |
| 960 | `simplebutton_constr_childevents` | 48 | 5.8s |  |
| 961 | `simplebutton_constr_params` | 42 | 5.4s |  |
| 962 | `simplebutton_mouseenabled` | 26 | 5.1s |  |
| 963 | `simplebutton_multi_children` | 19 | 5.5s |  |
| 964 | `simplebutton_soundtransform` | 887 | 21.4s |  |
| 965 | `simplebutton_structure` | 27 | 5.8s |  |
| 966 | `simplebutton_symbolclass` | 68 | 2.4s |  |
| 967 | `slot_disp_id_shared_numbering` | 1 | 20.3s |  |
| 968 | `slots_force_autoassigned` | 1 | 5.7s |  |
| 969 | `socket_after_disconnect` | 1 | 5.5s |  |
| 970 | `socket_close` | 2 | 5.5s |  |
| 971 | `socket_connect` | 4 | 5.6s |  |
| 972 | `socket_errors` | 56 | 5.9s |  |
| 973 | `socket_read_big` | 48 | 5.6s |  |
| 974 | `socket_read_little` | 48 | 1.5s |  |
| 975 | `socket_read_write_object` | 8 | 5.6s |  |
| 976 | `socket_write_big` | 15 | 5.7s |  |
| 977 | `socket_write_little` | 14 | 5.6s |  |
| 978 | `sound_constructor_with_args` | 6 | 5.8s |  |
| 979 | `sound_embeddedprops` | 26 | 5.8s |  |
| 980 | `sound_load_multiple` | 19 | 6.6s |  |
| 981 | `sound_play` | 19 | 5.9s |  |
| 982 | `sound_rootless` | 7 | 5.6s |  |
| 983 | `sound_valueof` | 33 | 5.7s |  |
| 984 | `soundchannel_soundtransform` | 835 | 23.2s |  |
| 985 | `soundchannel_soundtransform_exists` | 5 | 17.8s |  |
| 986 | `soundchannel_stop` | 8 | 21.9s |  |
| 987 | `soundmixer_buffertime` | 5 | 5.6s |  |
| 988 | `soundmixer_soundtransform` | 900 | 7.2s |  |
| 989 | `soundmixer_stopall` | 6 | 21.4s |  |
| 990 | `soundtransform` | 442 | 9.4s |  |
| 991 | `space_justifier_clone` | 12 | 5.6s |  |
| 992 | `sprite_with_frames` | 0 | 21.7s |  |
| 993 | `stage3d_agal_cross_product` | 0 | 7.9s |  |
| 994 | `stage3d_agal_upload_errors` | 66 | 8.0s |  |
| 995 | `stage3d_bitmap` | 0 | 25.9s |  |
| 996 | `stage3d_blend` | 81 | 23.7s |  |
| 997 | `stage3d_context3d_string_args` | 158 | 6.8s |  |
| 998 | `stage3d_errors` | 7 | 5.6s |  |
| 999 | `stage3d_errors_atf` | 3 | 6.7s |  |
| 1000 | `stage3d_errors_swf_29` | 6 | 5.7s |  |
| 1001 | `stage3d_float1_index` | 0 | 23.3s |  |
| 1002 | `stage3d_fractal` | 0 | 24.4s |  |
| 1003 | `stage3d_ignore_sampler_override` | 0 | 23.5s |  |
| 1004 | `stage3d_multistage_triangle` | 3 | 8.0s |  |
| 1005 | `stage3d_program_constants_bytearray_be` | 0 | 25.1s |  |
| 1006 | `stage3d_program_constants_bytearray_le` | 0 | 8.3s |  |
| 1007 | `stage3d_program_constants_invalid_input` | 21 | 6.4s |  |
| 1008 | `stage3d_raytrace` | 0 | 28.9s |  |
| 1009 | `stage3d_rotating_cube` | 0 | 8.5s |  |
| 1010 | `stage3d_sampler` | 0 | 7.8s |  |
| 1011 | `stage3d_sampler_partial_upload` | 0 | 7.8s |  |
| 1012 | `stage3d_stencil` | 0 | 23.9s |  |
| 1013 | `stage3d_texture` | 0 | 12.7s |  |
| 1014 | `stage3d_texture_bytearray` | 0 | 9.1s |  |
| 1015 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.3s |  |
| 1016 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.2s |  |
| 1017 | `stage3d_triangle` | 0 | 8.0s |  |
| 1018 | `stage3d_triangle_bytes4` | 0 | 8.0s |  |
| 1019 | `stage3d_triangle_float1` | 0 | 7.9s |  |
| 1020 | `stage3d_triangle_index_upload` | 0 | 7.9s |  |
| 1021 | `stage3d_x_y` | 22 | 5.6s |  |
| 1022 | `stage_access` | 10 | 5.6s |  |
| 1023 | `stage_display_state` | 6 | 5.6s |  |
| 1024 | `stage_displayobject_properties` | 24 | 5.6s |  |
| 1025 | `stage_domain_getQualifiedDefinitionNames` | 5 | 5.6s |  |
| 1026 | `stage_framerate_nan` | 7 | 5.7s |  |
| 1027 | `stage_framerate_negative` | 6 | 5.6s |  |
| 1028 | `stage_framerate_zero` | 6 | 5.6s |  |
| 1029 | `stage_invalidate` | 38 | 5.8s |  |
| 1030 | `stage_loaderinfo_properties` | 24 | 21.4s |  |
| 1031 | `stage_mousechildren` | 2 | 5.5s |  |
| 1032 | `stage_mouseenabled` | 15 | 5.6s |  |
| 1033 | `stage_overriden_setters` | 31 | 5.6s |  |
| 1034 | `stage_properties` | 30 | 5.6s |  |
| 1035 | `stage_properties2` | 213 | 5.8s |  |
| 1036 | `stage_scale_factor` | 12 | 24.7s |  |
| 1037 | `stage_stage3Ds_vector` | 1 | 5.5s |  |
| 1038 | `static_length` | 24 | 5.7s |  |
| 1039 | `static_text` | 3 | 5.7s |  |
| 1040 | `static_var_with_this_in_ctor` | 2 | 5.5s |  |
| 1041 | `statictext_text` | 8 | 5.6s |  |
| 1042 | `stored_properties` | 11 | 5.6s |  |
| 1043 | `strict_equality` | 34 | 1.7s |  |
| 1044 | `string_call` | 13 | 1.6s |  |
| 1045 | `string_case` | 23 | 5.6s |  |
| 1046 | `string_char_at` | 27 | 5.6s |  |
| 1047 | `string_char_code_at` | 28 | 5.3s |  |
| 1048 | `string_concat_fromcharcode` | 37 | 5.5s |  |
| 1049 | `string_constr` | 25 | 5.6s |  |
| 1050 | `string_indexof_lastindexof` | 87 | 5.8s |  |
| 1051 | `string_length` | 16 | 5.6s |  |
| 1052 | `string_locale_compare` | 39 | 6.0s |  |
| 1053 | `string_match` | 51 | 6.0s |  |
| 1054 | `string_relational_compare` | 4 | 1.6s |  |
| 1055 | `string_replace` | 51 | 5.8s |  |
| 1056 | `string_search` | 41 | 5.8s |  |
| 1057 | `string_slice_substr_substring` | 170 | 6.5s |  |
| 1058 | `string_split` | 29 | 5.8s |  |
| 1059 | `string_substr_negative` | 21 | 5.6s |  |
| 1060 | `string_substr_weird` | 182 | 5.6s |  |
| 1061 | `stylesheet` | 221 | 6.3s |  |
| 1062 | `stylesheet_parse_color` | 69 | 5.7s |  |
| 1063 | `stylesheet_transform` | 307 | 5.9s |  |
| 1064 | `sub_super_same_field` | 12 | 1.7s |  |
| 1065 | `subclass_superclass_linked_symbol` | 4 | 6.1s |  |
| 1066 | `subtract` | 1058 | 13.1s |  |
| 1067 | `super_get_call` | 12 | 5.7s |  |
| 1068 | `supercall_two_classobjects` | 2 | 5.7s |  |
| 1069 | `supercalls_coerce` | 8 | 1.7s |  |
| 1070 | `supercalls_weird` | 2 | 5.6s |  |
| 1071 | `superinterface_call` | 20 | 5.7s |  |
| 1072 | `superinterface_instanceof` | 18 | 5.7s |  |
| 1073 | `swf8` | 1 | 5.6s |  |
| 1074 | `swf_10_queued_goto_scripts_construct` | 52 | 21.9s |  |
| 1075 | `swf_9_goto_in_enter_frame` | 17 | 5.8s |  |
| 1076 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.8s |  |
| 1077 | `swf_9_queued_goto_scripts` | 6 | 21.6s |  |
| 1078 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 1079 | `swf_9_versioning` | 2 | 5.6s |  |
| 1080 | `swf_wrong_frame_count` | 38 | 6.0s |  |
| 1081 | `swf_wrong_frame_count_isplaying` | 22 | 5.7s |  |
| 1082 | `symbol_class_binary_data` | 8 | 5.7s |  |
| 1083 | `symbol_class_conflict` | 4 | 5.8s |  |
| 1084 | `symbol_class_root_not_zero` | 1 | 5.6s |  |
| 1085 | `symbolclass_invalid_utf8` | 2 | 5.7s |  |
| 1086 | `system_exit` | 3 | 5.7s |  |
| 1087 | `system_setclipboard_null` | 1 | 5.6s |  |
| 1088 | `tab_ordering_arrows` | 998 | 22.8s |  |
| 1089 | `tab_ordering_automatic_advanced` | 184 | 6.2s |  |
| 1090 | `tab_ordering_automatic_basic` | 45 | 5.8s |  |
| 1091 | `tab_ordering_children` | 116 | 5.8s |  |
| 1092 | `tab_ordering_custom_basic` | 34 | 5.6s |  |
| 1093 | `tab_ordering_properties` | 732 | 6.0s |  |
| 1094 | `tab_ordering_stage_tab_children` | 32 | 6.6s |  |
| 1095 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.1s |  |
| 1096 | `tab_ordering_tabbable` | 47 | 6.2s |  |
| 1097 | `tabstop_properties` | 105 | 6.6s |  |
| 1098 | `text_element_basic` | 34 | 6.4s |  |
| 1099 | `text_engine_fontdescription` | 27 | 6.3s |  |
| 1100 | `text_engine_groupelement` | 64 | 7.1s |  |
| 1101 | `text_run` | 7 | 2.1s |  |
| 1102 | `textblock_createline_errors` | 23 | 6.5s |  |
| 1103 | `textblock_createline_fte` | 9 | 22.8s |  |
| 1104 | `textblock_properties` | 118 | 6.7s |  |
| 1105 | `textbox_click` | 37 | 23.2s |  |
| 1106 | `textfield_default_text_format_null` | 20 | 6.5s |  |
| 1107 | `textfield_event` | 66 | 6.8s |  |
| 1108 | `textfield_focusin_event` | 9 | 6.3s |  |
| 1109 | `textfield_input_dead_keys_windows` | 15 | 6.5s |  |
| 1110 | `textfield_input_events` | 25 | 23.2s |  |
| 1111 | `textfield_unload` | 39 | 23.4s |  |
| 1112 | `textformat` | 1134 | 6.5s |  |
| 1113 | `textformat_display` | 14 | 6.5s |  |
| 1114 | `textformat_font_max_length` | 4 | 6.5s |  |
| 1115 | `textjustifier_locale` | 132 | 6.8s |  |
| 1116 | `textline_has_tabs` | 47 | 6.9s |  |
| 1117 | `textline_inapplicable_properties` | 10 | 6.7s |  |
| 1118 | `textline_name` | 1 | 6.4s |  |
| 1119 | `textline_raw_text_length` | 30 | 6.5s |  |
| 1120 | `textline_splitting_basic` | 76 | 6.6s |  |
| 1121 | `textline_throwerror` | 30 | 6.6s |  |
| 1122 | `textline_validity` | 162 | 6.8s |  |
| 1123 | `throw` | 3 | 6.6s |  |
| 1124 | `timeline_scripts` | 3 | 23.7s |  |
| 1125 | `timer` | 90 | 7.0s |  |
| 1126 | `timer_events` | 3 | 6.4s |  |
| 1127 | `timer_finished` | 11 | 6.5s |  |
| 1128 | `timer_invalid_delay` | 30 | 6.5s |  |
| 1129 | `timer_reset` | 8 | 6.7s |  |
| 1130 | `timer_setdelay` | 5 | 6.6s |  |
| 1131 | `trace` | 12 | 5.6s |  |
| 1132 | `truthiness` | 30 | 5.6s |  |
| 1133 | `try_catch` | 11 | 5.7s |  |
| 1134 | `try_catch_typed` | 12 | 5.6s |  |
| 1135 | `typeof` | 30 | 5.6s |  |
| 1136 | `uint_constr` | 92 | 5.7s |  |
| 1137 | `uint_tofixed` | 1215 | 5.5s |  |
| 1138 | `uint_toprecision` | 1125 | 5.7s |  |
| 1139 | `uint_tostring` | 3375 | 5.8s |  |
| 1140 | `uncaught_error_basic` | 2 | 5.5s |  |
| 1141 | `unchecked_function` | 15 | 5.6s |  |
| 1142 | `unescape` | 28 | 5.6s |  |
| 1143 | `url_loader` | 25 | 5.8s |  |
| 1144 | `url_vars` | 27 | 5.8s |  |
| 1145 | `urlrequest` | 18 | 5.6s |  |
| 1146 | `urlstream_basic` | 5 | 5.6s |  |
| 1147 | `urshift` | 1058 | 12.8s |  |
| 1148 | `utils3d` | 7 | 5.6s |  |
| 1149 | `vector3d` | 397 | 8.3s |  |
| 1150 | `vector3d_near_equals` | 80 | 5.7s |  |
| 1151 | `vector_class` | 36 | 6.0s |  |
| 1152 | `vector_class_call` | 11 | 5.7s |  |
| 1153 | `vector_coercion` | 66 | 6.3s |  |
| 1154 | `vector_concat` | 90 | 6.1s |  |
| 1155 | `vector_constr` | 107 | 6.2s |  |
| 1156 | `vector_enumeration` | 5 | 5.6s |  |
| 1157 | `vector_every` | 92 | 6.3s |  |
| 1158 | `vector_filter` | 95 | 6.4s |  |
| 1159 | `vector_holes` | 24 | 5.7s |  |
| 1160 | `vector_indexof` | 302 | 8.5s |  |
| 1161 | `vector_insertat` | 270 | 6.4s |  |
| 1162 | `vector_int_access` | 4 | 5.6s |  |
| 1163 | `vector_int_delete` | 11 | 5.6s |  |
| 1164 | `vector_join` | 58 | 6.0s |  |
| 1165 | `vector_lastindexof` | 302 | 5.5s |  |
| 1166 | `vector_legacy` | 10 | 5.6s |  |
| 1167 | `vector_map` | 85 | 6.2s |  |
| 1168 | `vector_object_final` | 1 | 5.5s |  |
| 1169 | `vector_object_toString` | 10 | 5.7s |  |
| 1170 | `vector_prototype_some` | 125 | 5.8s |  |
| 1171 | `vector_pushpop` | 255 | 7.6s |  |
| 1172 | `vector_reborrow_bug` | 10 | 6.4s |  |
| 1173 | `vector_removeat` | 172 | 7.3s |  |
| 1174 | `vector_reverse` | 232 | 7.3s |  |
| 1175 | `vector_shiftunshift` | 252 | 6.3s |  |
| 1176 | `vector_slice` | 331 | 8.1s |  |
| 1177 | `vector_sort` | 905 | 14.2s |  |
| 1178 | `vector_splice` | 693 | 10.2s |  |
| 1179 | `vector_splice_fixed_bug_compat` | 4 | 6.3s |  |
| 1180 | `vector_tostring` | 79 | 6.9s |  |
| 1181 | `verification` | 8 | 6.4s |  |
| 1182 | `verify_abnormal_loop` | 1 | 6.6s |  |
| 1183 | `verify_dxns_without_flag` | 3 | 6.7s |  |
| 1184 | `verify_exception_target_two_jumps` | 1 | 2.1s |  |
| 1185 | `verify_exception_targets_edge_case` | 1 | 6.3s |  |
| 1186 | `verify_illegal_opcode` | 1 | 2.5s |  |
| 1187 | `verify_jump_to_middle_of_op` | 1 | 6.1s |  |
| 1188 | `verify_lookup_switch_edge_case` | 1 | 6.2s |  |
| 1189 | `verify_method_info_oob` | 1 | 0.5s |  |
| 1190 | `verify_stack` | 5 | 6.3s |  |
| 1191 | `verify_typecheck` | 4 | 6.3s |  |
| 1192 | `verify_unreachable_exception` | 2 | 6.3s |  |
| 1193 | `versioned_isplaying` | 2 | 6.2s |  |
| 1194 | `virtual_properties` | 16 | 6.6s |  |
| 1195 | `with` | 4 | 6.3s |  |
| 1196 | `wrong_arg_count` | 7 | 6.4s |  |
| 1197 | `xml_abstract_equality` | 36 | 6.5s |  |
| 1198 | `xml_advanced` | 52 | 6.3s |  |
| 1199 | `xml_appendchild` | 10 | 6.2s |  |
| 1200 | `xml_appendchild_swf_v21` | 13 | 6.5s |  |
| 1201 | `xml_as_attribute` | 9 | 6.2s |  |
| 1202 | `xml_attribute` | 35 | 6.4s |  |
| 1203 | `xml_attribute_name` | 40 | 6.2s |  |
| 1204 | `xml_basic` | 33 | 6.3s |  |
| 1205 | `xml_child` | 25 | 6.3s |  |
| 1206 | `xml_childindex` | 7 | 2.1s |  |
| 1207 | `xml_children` | 43 | 6.7s |  |
| 1208 | `xml_class_call` | 9 | 6.2s |  |
| 1209 | `xml_contains` | 197 | 6.4s |  |
| 1210 | `xml_copy` | 20 | 5.3s |  |
| 1211 | `xml_ctor_from_tostring` | 23 | 5.2s |  |
| 1212 | `xml_delete` | 114 | 5.2s |  |
| 1213 | `xml_descendants` | 83 | 5.2s |  |
| 1214 | `xml_duplicate_attribute` | 14 | 5.1s |  |
| 1215 | `xml_elements` | 6 | 5.1s |  |
| 1216 | `xml_equals_namespace_check` | 2 | 5.3s |  |
| 1217 | `xml_explicit_use_namespace` | 5 | 5.3s |  |
| 1218 | `xml_getdescendants_qname` | 21 | 5.2s |  |
| 1219 | `xml_has_property_via_in` | 26 | 5.3s |  |
| 1220 | `xml_hasownproperty` | 6 | 5.1s |  |
| 1221 | `xml_ignore_white` | 6 | 5.0s |  |
| 1222 | `xml_length` | 2 | 5.0s |  |
| 1223 | `xml_list_as_attribute` | 9 | 5.2s |  |
| 1224 | `xml_list_concat` | 20 | 5.2s |  |
| 1225 | `xml_list_ctor_errors` | 34 | 5.1s |  |
| 1226 | `xml_list_delete_clear_parent` | 6 | 5.2s |  |
| 1227 | `xml_list_enumerate` | 4 | 5.1s |  |
| 1228 | `xml_many_namespace_declarations` | 2 | 1.7s |  |
| 1229 | `xml_methods_settings` | 3 | 5.0s |  |
| 1230 | `xml_mismatched_tag` | 45 | 1.7s |  |
| 1231 | `xml_namespace` | 39 | 5.1s |  |
| 1232 | `xml_namespace_methods` | 245 | 5.1s |  |
| 1233 | `xml_namespaced_property` | 7 | 5.2s |  |
| 1234 | `xml_no_namespace` | 1 | 5.3s |  |
| 1235 | `xml_nodekind` | 3 | 5.0s |  |
| 1236 | `xml_normalize` | 35 | 5.1s |  |
| 1237 | `xml_notification_bubbling` | 361 | 5.1s |  |
| 1238 | `xml_parent` | 8 | 5.0s |  |
| 1239 | `xml_set_children` | 17 | 5.2s |  |
| 1240 | `xml_set_name` | 34 | 4.9s |  |
| 1241 | `xml_settings` | 6 | 1.7s |  |
| 1242 | `xml_simple_complex_content` | 47 | 5.3s |  |
| 1243 | `xml_socket` | 11 | 5.6s |  |
| 1244 | `xml_text` | 7 | 5.5s |  |
| 1245 | `xml_tostring` | 6 | 5.3s |  |
| 1246 | `xml_tostring_namespace` | 12 | 5.2s |  |
| 1247 | `xml_unescaping` | 23 | 5.4s |  |
| 1248 | `xml_unescaping_nul_char_ref` | 19 | 5.6s |  |
| 1249 | `xml_weird_ignores` | 54 | 5.5s |  |
| 1250 | `xml_wildcard` | 11 | 5.3s |  |
| 1251 | `xmldocument` | 254 | 5.5s |  |
| 1252 | `xmlnode` | 3540 | 5.3s |  |
| 1253 | `zero_frame_clip` | 3 | 5.5s |  |

## Ruffle-Matched Tests

**43 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 5.5s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.2s |  |
| 3 | `blend_transform` | 1 | 1 | 8.2s |  |
| 4 | `bounds_mode` | 6 | 6 | 8.5s |  |
| 5 | `coerce_property` | 3 | 3 | 5.8s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.8s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 20.7s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 27.5s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 5.8s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.9s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.7s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 8.2s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.1s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 5.4s |  |
| 15 | `event_handler_exception` | 3 | 3 | 5.2s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 6.8s |  |
| 17 | `goto_framescript_queued/swf13` | 3 | 3 | 0.4s |  |
| 18 | `gradient_values_readback` | 12 | 12 | 1.9s |  |
| 19 | `graphics_draw_path` | 50 | 50 | 21.9s |  |
| 20 | `groupelement_text` | 2 | 2 | 5.7s |  |
| 21 | `html_text_img_parsing` | 95 | 95 | 5.6s |  |
| 22 | `int_toexponential` | 76 | 76 | 5.6s |  |
| 23 | `json_parse_numbers` | 4 | 79 | 5.6s |  |
| 24 | `loader_events_2` | 30 | 30 | 5.8s |  |
| 25 | `matrix3d_recompose_edge_cases` | 8 | 85 | 5.5s |  |
| 26 | `number_convert_errors` | 706 | 706 | 5.9s |  |
| 27 | `number_to_string` | 104 | 104 | 6.0s |  |
| 28 | `simplebutton_childevents_multichild` | 101 | 101 | 5.5s |  |
| 29 | `simplebutton_childevents_script_order` | 4 | 4 | 5.8s |  |
| 30 | `slot_holes_fail` | 1 | 1 | 5.6s |  |
| 31 | `slot_id_exceeds_trait_count` | 1 | 1 | 5.7s |  |
| 32 | `soundchannel_position` | 74 | 74 | 22.3s |  |
| 33 | `soundchannel_soundcomplete` | 10 | 10 | 5.8s |  |
| 34 | `sprite_dropTarget` | 15 | 15 | 5.7s |  |
| 35 | `swf_9_goto_in_construct_frame` | 12 | 12 | 21.8s |  |
| 36 | `textblock_line_changes` | 44 | 44 | 6.8s |  |
| 37 | `textblock_recreateline` | 137 | 138 | 6.9s |  |
| 38 | `textblock_releaselines` | 4 | 4 | 8.1s |  |
| 39 | `textline_atom_index_at_char_index` | 3 | 3 | 7.3s |  |
| 40 | `uint_toexponential` | 100 | 100 | 5.7s |  |
| 41 | `uncaught_errors_stringified` | 15 | 15 | 5.7s |  |
| 42 | `vector_indexing_cutoffs` | 1 | 1 | 5.7s |  |
| 43 | `weird_superinterface_properties` | 1 | 1 | 6.3s |  |

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
