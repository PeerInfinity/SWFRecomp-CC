# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-28 21:10 UTC

**Git SHA**: `1b7a987cf4`

**Run Duration**: 236m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1280 |
| Passing | **1218** (95.2%) |
| Ruffle-matched | 38 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1256** (98.1%) |
| Failing | 24 |
| Total expected lines | 157776 |
| Matching lines | 154780 (98.1%) |
| Mismatched lines | 2996 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 24 | 100.0% |

## Passing Tests

**1218 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 32.1s |  |
| 2 | `accessibility` | 1 | 8.7s |  |
| 3 | `accessibilityimplementation` | 18 | 28.2s |  |
| 4 | `activation_class` | 6 | 8.8s |  |
| 5 | `add` | 1058 | 20.1s |  |
| 6 | `agal_compiler` | 13 | 11.8s |  |
| 7 | `air_datagram_socket` | 1 | 10.8s |  |
| 8 | `air_hidden_lookup` | 2 | 8.6s |  |
| 9 | `air_ifilepromise` | 1 | 8.6s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 8.7s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.3s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.3s |  |
| 13 | `all_classes/display/swf10` | 2569 | 8.7s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.4s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.3s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.4s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.3s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.3s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 8.7s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.3s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.3s |  |
| 22 | `all_classes/errors/swf10` | 140 | 8.6s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.3s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.3s |  |
| 25 | `all_classes/events/swf10` | 1638 | 8.7s |  |
| 26 | `all_classes/events/swf11` | 1750 | 1.3s |  |
| 27 | `all_classes/events/swf12` | 1814 | 1.3s |  |
| 28 | `all_classes/events/swf30` | 2353 | 1.3s |  |
| 29 | `all_classes/events/swf9` | 1030 | 1.3s |  |
| 30 | `all_classes/security/swf11` | 3 | 8.6s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.3s |  |
| 32 | `all_classes/security/swf13` | 53 | 1.3s |  |
| 33 | `all_classes/security/swf30` | 53 | 1.3s |  |
| 34 | `all_classes/xml/swf30` | 116 | 8.7s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.3s |  |
| 36 | `amf_array_serialization` | 17 | 30.6s |  |
| 37 | `amf_custom_obj` | 26 | 8.7s |  |
| 38 | `amf_dictionary` | 9 | 8.7s |  |
| 39 | `amf_function` | 46 | 8.7s |  |
| 40 | `amf_invalid_date` | 2 | 8.6s |  |
| 41 | `amf_missing_prop` | 6 | 8.7s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 8.7s |  |
| 43 | `amf_setter_error` | 8 | 8.8s |  |
| 44 | `amf_vector` | 40 | 21.4s |  |
| 45 | `amf_xml` | 6 | 6.1s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 6.3s |  |
| 47 | `application_domain` | 4 | 5.8s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 18.7s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 5.8s |  |
| 50 | `array_access` | 18 | 6.0s |  |
| 51 | `array_access_interpreter` | 4 | 5.8s |  |
| 52 | `array_access_no_pubns` | 2 | 5.8s |  |
| 53 | `array_concat` | 41 | 5.9s |  |
| 54 | `array_constr` | 10 | 6.0s |  |
| 55 | `array_delete` | 44 | 6.3s |  |
| 56 | `array_enumeration` | 10 | 6.1s |  |
| 57 | `array_enumeration_elements` | 11 | 6.0s |  |
| 58 | `array_every` | 8 | 6.0s |  |
| 59 | `array_filter` | 6 | 6.1s |  |
| 60 | `array_foreach` | 18 | 6.5s |  |
| 61 | `array_hasownproperty` | 11 | 6.0s |  |
| 62 | `array_holes` | 9 | 5.9s |  |
| 63 | `array_index_max` | 84 | 5.9s |  |
| 64 | `array_indexof` | 25 | 5.9s |  |
| 65 | `array_join` | 26 | 6.0s |  |
| 66 | `array_lastindexof` | 29 | 6.0s |  |
| 67 | `array_length` | 14 | 5.8s |  |
| 68 | `array_literal` | 3 | 5.8s |  |
| 69 | `array_map` | 8 | 5.7s |  |
| 70 | `array_pop` | 52 | 6.0s |  |
| 71 | `array_push` | 24 | 5.9s |  |
| 72 | `array_reborrow_bug` | 6 | 5.7s |  |
| 73 | `array_reverse` | 28 | 5.8s |  |
| 74 | `array_shift` | 51 | 2.3s |  |
| 75 | `array_slice` | 39 | 5.8s |  |
| 76 | `array_some` | 8 | 5.9s |  |
| 77 | `array_sort` | 297 | 6.1s |  |
| 78 | `array_sort_fun_swf12` | 2 | 5.9s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.0s |  |
| 80 | `array_sort_random` | 210 | 5.9s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 5.8s |  |
| 82 | `array_sorton` | 545 | 6.6s |  |
| 83 | `array_sparse_ops` | 41 | 6.1s |  |
| 84 | `array_splice` | 133 | 6.0s |  |
| 85 | `array_splice2` | 428 | 26.6s |  |
| 86 | `array_splice_types` | 48 | 7.4s |  |
| 87 | `array_storage` | 8 | 23.6s |  |
| 88 | `array_tolocalestring` | 9 | 7.4s |  |
| 89 | `array_tostring` | 12 | 7.2s |  |
| 90 | `array_unshift` | 24 | 7.3s |  |
| 91 | `array_valueof` | 9 | 7.2s |  |
| 92 | `array_vector_null_callback` | 10 | 7.3s |  |
| 93 | `astype` | 28 | 7.8s |  |
| 94 | `astypelate` | 24 | 7.5s |  |
| 95 | `astypelate_propagates` | 1 | 7.3s |  |
| 96 | `asymmetric_key_events` | 11 | 7.5s |  |
| 97 | `automation_classes` | 122 | 8.0s |  |
| 98 | `av_classes` | 340 | 7.7s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 7.7s |  |
| 100 | `avm2_catchup_dobj` | 158 | 8.5s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 92.4s |  |
| 102 | `bevel_filter` | 187 | 7.8s |  |
| 103 | `bitand` | 1058 | 16.0s |  |
| 104 | `bitmap_constr` | 17 | 7.9s |  |
| 105 | `bitmap_data` | 1000 | 16.7s |  |
| 106 | `bitmap_filter_abstract` | 6 | 7.4s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 24.8s |  |
| 108 | `bitmap_properties` | 23 | 7.6s |  |
| 109 | `bitmap_subclass` | 7 | 9.8s |  |
| 110 | `bitmap_subclass_properties` | 9 | 7.8s |  |
| 111 | `bitmap_timeline` | 9 | 7.6s |  |
| 112 | `bitmapdata_accuracy` | 1 | 45.4s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 25.1s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.3s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 25.0s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 24.6s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 23.7s |  |
| 118 | `bitmapdata_clone` | 13 | 7.5s |  |
| 119 | `bitmapdata_colortransform` | 0 | 7.6s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 7.2s |  |
| 121 | `bitmapdata_constr` | 22 | 7.4s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 7.6s |  |
| 123 | `bitmapdata_copychannel` | 0 | 25.1s |  |
| 124 | `bitmapdata_copypixels` | 23 | 23.8s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 7.2s |  |
| 126 | `bitmapdata_copypixels_alpha_merge` | 9 | 32.4s |  |
| 127 | `bitmapdata_copypixels_blend` | 1029 | 9.3s |  |
| 128 | `bitmapdata_copypixels_blend_over` | 1 | 8.8s |  |
| 129 | `bitmapdata_copypixels_self` | 612 | 9.0s |  |
| 130 | `bitmapdata_copypixelstobytearray` | 39 | 9.0s |  |
| 131 | `bitmapdata_dispose` | 7 | 8.8s |  |
| 132 | `bitmapdata_draw` | 0 | 30.4s |  |
| 133 | `bitmapdata_draw_alpha_erase` | 8 | 9.1s |  |
| 134 | `bitmapdata_draw_cab_quality` | 0 | 30.8s |  |
| 135 | `bitmapdata_draw_colortransform` | 0 | 28.8s |  |
| 136 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 29.1s |  |
| 137 | `bitmapdata_draw_filters` | 0 | 28.6s |  |
| 138 | `bitmapdata_draw_masks` | 0 | 9.1s |  |
| 139 | `bitmapdata_draw_rotation` | 0 | 8.9s |  |
| 140 | `bitmapdata_draw_self_via_graphic` | 0 | 9.0s |  |
| 141 | `bitmapdata_draw_stage` | 0 | 28.7s |  |
| 142 | `bitmapdata_drawwithquality` | 0 | 11.4s |  |
| 143 | `bitmapdata_embedded` | 9 | 9.1s |  |
| 144 | `bitmapdata_fillrect` | 0 | 8.9s |  |
| 145 | `bitmapdata_filter_sourcerect` | 0 | 29.3s |  |
| 146 | `bitmapdata_floodfill` | 35 | 8.9s |  |
| 147 | `bitmapdata_getpixels` | 39 | 29.4s |  |
| 148 | `bitmapdata_getvector` | 27 | 3.5s |  |
| 149 | `bitmapdata_histogram` | 59 | 3.4s |  |
| 150 | `bitmapdata_hittest` | 112 | 9.5s |  |
| 151 | `bitmapdata_hittest_threshold` | 18 | 8.9s |  |
| 152 | `bitmapdata_opaque` | 0 | 9.1s |  |
| 153 | `bitmapdata_pixeldissolve` | 1037 | 9.5s |  |
| 154 | `bitmapdata_pixeldissolve_image` | 0 | 9.2s |  |
| 155 | `bitmapdata_rectangle_rounding` | 16 | 8.9s |  |
| 156 | `bitmapdata_setpixels` | 286 | 9.0s |  |
| 157 | `bitmapdata_setvector` | 26 | 9.1s |  |
| 158 | `bitmapdata_sync` | 0 | 30.1s |  |
| 159 | `bitmapdata_threshold` | 176 | 9.8s |  |
| 160 | `bitmapdata_zero_size` | 8 | 9.1s |  |
| 161 | `bitnot` | 46 | 9.2s |  |
| 162 | `bitor` | 1058 | 20.7s |  |
| 163 | `bitxor` | 1058 | 20.6s |  |
| 164 | `blend_mode_null` | 1 | 9.2s |  |
| 165 | `blend_multiply_alpha` | 0 | 9.2s |  |
| 166 | `blend_scroll` | 0 | 9.2s |  |
| 167 | `blend_shader_luma_lighten` | 3 | 9.7s |  |
| 168 | `blur_filter` | 43 | 9.1s |  |
| 169 | `boolean_constr` | 32 | 8.6s |  |
| 170 | `boolean_negation` | 30 | 8.6s |  |
| 171 | `boolean_tostring` | 8 | 8.8s |  |
| 172 | `broadcast_event` | 7 | 8.5s |  |
| 173 | `button_bounds` | 1 | 8.7s |  |
| 174 | `button_hittest` | 2 | 28.3s |  |
| 175 | `button_nested_frame` | 48 | 28.4s |  |
| 176 | `button_nested_frame_simple` | 27 | 8.9s |  |
| 177 | `bytearray` | 48 | 8.9s |  |
| 178 | `bytearray_bad_symbol_class` | 3 | 8.6s |  |
| 179 | `bytearray_bad_symbol_class_other_movie` | 6 | 9.1s |  |
| 180 | `bytearray_compress` | 31 | 9.0s |  |
| 181 | `bytearray_errors` | 24 | 9.2s |  |
| 182 | `bytearray_method_serialization` | 1 | 8.8s |  |
| 183 | `bytearray_oom` | 3 | 8.9s |  |
| 184 | `bytearray_readobject_amf0` | 50 | 9.0s |  |
| 185 | `bytearray_readobject_amf3` | 53 | 8.7s |  |
| 186 | `bytearray_readutf8bytes_with_bom` | 16 | 8.7s |  |
| 187 | `bytearray_serialization` | 3 | 8.8s |  |
| 188 | `bytearray_string_null` | 19 | 8.9s |  |
| 189 | `bytearray_tostring` | 15 | 8.7s |  |
| 190 | `bytearray_utf16` | 8 | 8.6s |  |
| 191 | `bytearray_writeobject` | 24 | 8.6s |  |
| 192 | `callee_in_initializer` | 6 | 8.7s |  |
| 193 | `callproplex_class` | 1 | 8.7s |  |
| 194 | `capabilities_resolution` | 8 | 30.0s |  |
| 195 | `catch_class` | 6 | 8.7s |  |
| 196 | `catch_scope_slot` | 7 | 8.8s |  |
| 197 | `checkfilter` | 4 | 3.3s |  |
| 198 | `class_call` | 32 | 9.1s |  |
| 199 | `class_cast_call` | 14 | 8.8s |  |
| 200 | `class_enumeration` | 4 | 8.9s |  |
| 201 | `class_has_own_property` | 2 | 8.8s |  |
| 202 | `class_init_interpreter_mode` | 1 | 8.9s |  |
| 203 | `class_is` | 32 | 9.2s |  |
| 204 | `class_methods` | 5 | 9.0s |  |
| 205 | `class_object_properties` | 10 | 9.2s |  |
| 206 | `class_singleton` | 18 | 9.2s |  |
| 207 | `class_supercalls_errors` | 35 | 9.4s |  |
| 208 | `class_supercalls_mismatched` | 26 | 9.5s |  |
| 209 | `class_superclass_wrong_order` | 1 | 9.3s |  |
| 210 | `class_to_locale_string` | 2 | 9.2s |  |
| 211 | `class_to_string` | 2 | 9.1s |  |
| 212 | `class_value_of` | 2 | 9.2s |  |
| 213 | `click_block` | 5 | 31.8s |  |
| 214 | `click_invisible` | 3 | 9.2s |  |
| 215 | `closures` | 12 | 9.2s |  |
| 216 | `coerce_return_type` | 40 | 9.3s |  |
| 217 | `coerce_return_type_fail` | 2 | 9.2s |  |
| 218 | `coerce_return_void` | 3 | 9.1s |  |
| 219 | `coerce_string` | 86 | 9.3s |  |
| 220 | `coerce_string_precision` | 28 | 9.2s |  |
| 221 | `coerce_to_primitive_side_effects` | 29 | 9.3s |  |
| 222 | `color_matrix_filter` | 19 | 9.4s |  |
| 223 | `construct_errors_swf10` | 8 | 9.3s |  |
| 224 | `construct_frame_list` | 22 | 30.7s |  |
| 225 | `construct_interface` | 3 | 9.1s |  |
| 226 | `constructor_call` | 3 | 9.1s |  |
| 227 | `constructors_vs_timeline` | 5 | 31.1s |  |
| 228 | `constructprop_dynamic_primitive` | 7 | 9.2s |  |
| 229 | `constructprop_method` | 2 | 9.2s |  |
| 230 | `constructsuper_null` | 2 | 3.5s |  |
| 231 | `content_element_basic` | 50 | 9.6s |  |
| 232 | `context3d_creation` | 9 | 11.4s |  |
| 233 | `control_flow_bool` | 4 | 9.3s |  |
| 234 | `control_flow_stricteq` | 8 | 9.3s |  |
| 235 | `convert_boolean` | 30 | 9.2s |  |
| 236 | `convert_integer` | 90 | 9.3s |  |
| 237 | `convert_number` | 56 | 9.2s |  |
| 238 | `convert_uinteger` | 90 | 9.4s |  |
| 239 | `convolution_filter` | 89 | 9.4s |  |
| 240 | `core_exceptions` | 47 | 10.8s |  |
| 241 | `cpool_index_invalid_bytecode_1` | 6 | 9.4s |  |
| 242 | `cpool_index_invalid_bytecode_2` | 3 | 9.3s |  |
| 243 | `cpool_index_invalid_bytecode_3` | 1 | 9.2s |  |
| 244 | `cross_api_version_call_newer` | 12 | 9.9s |  |
| 245 | `cross_api_version_call_older` | 12 | 9.6s |  |
| 246 | `cryptscore` | 11 | 9.3s |  |
| 247 | `currency_parse_result` | 7 | 9.1s |  |
| 248 | `date` | 30 | 9.9s |  |
| 249 | `date_parse` | 36 | 9.0s |  |
| 250 | `date_set_time_out_of_range` | 62 | 9.0s |  |
| 251 | `declocal` | 46 | 9.0s |  |
| 252 | `declocal_i` | 46 | 8.8s |  |
| 253 | `decode_uri` | 71 | 9.1s |  |
| 254 | `decrement` | 46 | 8.7s |  |
| 255 | `decrement_i` | 46 | 3.3s |  |
| 256 | `default_values` | 7 | 8.7s |  |
| 257 | `delayed_symbolclass` | 28 | 28.8s |  |
| 258 | `describe_type_basic` | 152 | 8.9s |  |
| 259 | `describe_type_json` | 301 | 8.9s |  |
| 260 | `describe_type_metadata` | 125 | 8.8s |  |
| 261 | `describe_type_native` | 23 | 8.7s |  |
| 262 | `dictionary_access` | 62 | 9.0s |  |
| 263 | `dictionary_access_no_pubns` | 2 | 8.7s |  |
| 264 | `dictionary_delete` | 101 | 9.3s |  |
| 265 | `dictionary_foreach` | 42 | 8.9s |  |
| 266 | `dictionary_hasownproperty` | 63 | 9.0s |  |
| 267 | `dictionary_in` | 62 | 9.1s |  |
| 268 | `dictionary_iter_modify` | 8 | 8.7s |  |
| 269 | `dictionary_namespaces` | 36 | 9.0s |  |
| 270 | `displacement_map_filter` | 61 | 9.2s |  |
| 271 | `displayobject_alpha` | 277 | 9.0s |  |
| 272 | `displayobject_blendmode` | 0 | 29.2s |  |
| 273 | `displayobject_colortransform_nested` | 0 | 28.6s |  |
| 274 | `displayobject_early_init` | 54 | 10.9s |  |
| 275 | `displayobject_filters` | 17 | 8.9s |  |
| 276 | `displayobject_from_enterframe` | 1 | 29.2s |  |
| 277 | `displayobject_getbounds_shape` | 0 | 28.4s |  |
| 278 | `displayobject_getrect` | 16 | 8.9s |  |
| 279 | `displayobject_height` | 6052 | 29.1s |  |
| 280 | `displayobject_hittestobject` | 32 | 8.8s |  |
| 281 | `displayobject_hittestpoint` | 49 | 8.8s |  |
| 282 | `displayobject_hittestpoint_boundary` | 65 | 29.0s |  |
| 283 | `displayobject_hittestpoint_root` | 13 | 9.0s |  |
| 284 | `displayobject_invalid_floats` | 60 | 8.8s |  |
| 285 | `displayobject_invalid_props` | 3 | 8.6s |  |
| 286 | `displayobject_mask` | 3 | 9.2s |  |
| 287 | `displayobject_mask_self_referential` | 0 | 8.6s |  |
| 288 | `displayobject_metaData` | 3 | 8.6s |  |
| 289 | `displayobject_name` | 22 | 29.1s |  |
| 290 | `displayobject_name_from_timeline` | 24 | 6.8s |  |
| 291 | `displayobject_opaque_background` | 6 | 7.1s |  |
| 292 | `displayobject_parent` | 12 | 23.2s |  |
| 293 | `displayobject_root` | 24 | 7.3s |  |
| 294 | `displayobject_rotation` | 1284 | 6.8s |  |
| 295 | `displayobject_scrollrect` | 33 | 8.0s |  |
| 296 | `displayobject_set_matrix_nested` | 0 | 22.8s |  |
| 297 | `displayobject_set_name_loaded` | 3 | 7.7s |  |
| 298 | `displayobject_subclass` | 2 | 6.7s |  |
| 299 | `displayobject_transform` | 89 | 22.7s |  |
| 300 | `displayobject_visible` | 23 | 7.1s |  |
| 301 | `displayobject_width` | 4852 | 23.6s |  |
| 302 | `displayobject_x` | 614 | 6.9s |  |
| 303 | `displayobject_y` | 617 | 6.6s |  |
| 304 | `displayobject_z` | 38 | 23.4s |  |
| 305 | `displayobjectcontainer_addchild` | 32 | 6.7s |  |
| 306 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.6s |  |
| 307 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.9s |  |
| 308 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.0s |  |
| 309 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.1s |  |
| 310 | `displayobjectcontainer_addchildat` | 42 | 6.5s |  |
| 311 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.7s |  |
| 312 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.0s |  |
| 313 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.6s |  |
| 314 | `displayobjectcontainer_contains` | 66 | 22.6s |  |
| 315 | `displayobjectcontainer_getchildat` | 4 | 6.6s |  |
| 316 | `displayobjectcontainer_getchildbyname` | 9 | 6.4s |  |
| 317 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.0s |  |
| 318 | `displayobjectcontainer_getchildindex` | 28 | 6.4s |  |
| 319 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 22.1s |  |
| 320 | `displayobjectcontainer_removechild` | 10 | 6.4s |  |
| 321 | `displayobjectcontainer_removechild_errors` | 4 | 6.5s |  |
| 322 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.5s |  |
| 323 | `displayobjectcontainer_removechildat` | 18 | 6.6s |  |
| 324 | `displayobjectcontainer_removechildren` | 51 | 6.7s |  |
| 325 | `displayobjectcontainer_setchildindex` | 42 | 6.4s |  |
| 326 | `displayobjectcontainer_stopallmovieclips` | 2 | 22.8s |  |
| 327 | `displayobjectcontainer_swapchildren` | 42 | 6.7s |  |
| 328 | `displayobjectcontainer_swapchildrenat` | 42 | 6.7s |  |
| 329 | `displayobjectcontainer_timelineinstance` | 48 | 23.4s |  |
| 330 | `divide` | 1058 | 14.4s |  |
| 331 | `doabc_and_symbolclass_script_init_goto` | 7 | 22.6s |  |
| 332 | `doabc_and_symbolclass_script_init_normal` | 6 | 26.1s |  |
| 333 | `doabc_is_eager` | 1 | 25.6s |  |
| 334 | `documentclass` | 9 | 7.8s |  |
| 335 | `domain_memory` | 133 | 27.2s |  |
| 336 | `drag_drop` | 10 | 7.9s |  |
| 337 | `drop_shadow_filter` | 172 | 8.1s |  |
| 338 | `duplicate_defs` | 1 | 7.7s |  |
| 339 | `eager_init` | 1 | 7.8s |  |
| 340 | `east_asian_justifier_clone` | 8 | 7.8s |  |
| 341 | `edit_text_linkage` | 7 | 8.0s |  |
| 342 | `edittext_align` | 60 | 8.4s |  |
| 343 | `edittext_always_show_selection` | 0 | 26.2s |  |
| 344 | `edittext_antialiastype` | 296 | 7.9s |  |
| 345 | `edittext_at_point_methods_basic` | 16 | 8.9s |  |
| 346 | `edittext_autosize` | 39 | 8.3s |  |
| 347 | `edittext_autosize_align` | 0 | 25.5s |  |
| 348 | `edittext_autosize_height_dynamic` | 60 | 25.8s |  |
| 349 | `edittext_autosize_height_input` | 60 | 7.5s |  |
| 350 | `edittext_autosize_lazy_bounds_events` | 65 | 7.5s |  |
| 351 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.4s |  |
| 352 | `edittext_autosize_lazy_bounds_props` | 490 | 9.0s |  |
| 353 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.0s |  |
| 354 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.5s |  |
| 355 | `edittext_bottom_scroll_v_basic` | 210 | 7.3s |  |
| 356 | `edittext_bounds_scale` | 24 | 24.3s |  |
| 357 | `edittext_bullet` | 30 | 7.5s |  |
| 358 | `edittext_default_format` | 221 | 7.7s |  |
| 359 | `edittext_default_format_empty` | 136 | 7.8s |  |
| 360 | `edittext_empty_text_format` | 7 | 7.5s |  |
| 361 | `edittext_focus_selection` | 5 | 7.5s |  |
| 362 | `edittext_font_size` | 45 | 8.0s |  |
| 363 | `edittext_format_empty_font` | 8 | 7.7s |  |
| 364 | `edittext_get_char_index_at_point` | 4 | 27.8s |  |
| 365 | `edittext_get_line_index_at_point` | 2 | 7.9s |  |
| 366 | `edittext_get_line_index_of_char` | 76 | 8.6s |  |
| 367 | `edittext_getcharboundaries` | 172 | 8.2s |  |
| 368 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.6s |  |
| 369 | `edittext_getcharboundaries_scroll` | 85 | 7.7s |  |
| 370 | `edittext_getlinemetrics` | 146 | 7.8s |  |
| 371 | `edittext_html` | 3101 | 7.7s |  |
| 372 | `edittext_html_condensewhite` | 487 | 28.3s |  |
| 373 | `edittext_html_entity` | 4 | 29.0s |  |
| 374 | `edittext_html_font_size_swf12` | 267 | 8.5s |  |
| 375 | `edittext_html_font_size_swf13` | 273 | 8.2s |  |
| 376 | `edittext_html_roundtrip` | 17 | 8.5s |  |
| 377 | `edittext_ime_focus_lost` | 9 | 28.9s |  |
| 378 | `edittext_input_control` | 12 | 8.5s |  |
| 379 | `edittext_leading` | 9 | 9.0s |  |
| 380 | `edittext_letter_spacing` | 15 | 8.7s |  |
| 381 | `edittext_line_methods` | 294 | 10.0s |  |
| 382 | `edittext_line_metrics` | 11 | 30.3s |  |
| 383 | `edittext_margins` | 25 | 8.7s |  |
| 384 | `edittext_max_scroll_h_basic` | 475 | 8.7s |  |
| 385 | `edittext_max_scroll_v_basic` | 1000 | 8.6s |  |
| 386 | `edittext_mouse_selection` | 363 | 29.7s |  |
| 387 | `edittext_mousedown` | 3 | 8.9s |  |
| 388 | `edittext_mouseenabled` | 26 | 8.5s |  |
| 389 | `edittext_newline_character` | 22 | 8.3s |  |
| 390 | `edittext_newline_stripping` | 64 | 11.0s |  |
| 391 | `edittext_newlines` | 30 | 8.5s |  |
| 392 | `edittext_paragraph_methods` | 257 | 8.3s |  |
| 393 | `edittext_paste_events` | 8 | 8.1s |  |
| 394 | `edittext_paste_maxchars` | 4 | 8.2s |  |
| 395 | `edittext_paste_restrict` | 16 | 8.0s |  |
| 396 | `edittext_restrict` | 191 | 8.2s |  |
| 397 | `edittext_restrict_events` | 22 | 8.3s |  |
| 398 | `edittext_scroll_event` | 37 | 8.5s |  |
| 399 | `edittext_scrollh` | 10 | 8.3s |  |
| 400 | `edittext_selected_text` | 9 | 8.2s |  |
| 401 | `edittext_set_html_same` | 17 | 8.2s |  |
| 402 | `edittext_set_text_vs_html` | 9 | 8.1s |  |
| 403 | `edittext_stylesheet` | 536 | 8.7s |  |
| 404 | `edittext_stylesheet_custom_tag` | 76 | 8.3s |  |
| 405 | `edittext_stylesheet_display` | 272 | 8.5s |  |
| 406 | `edittext_tag_indent` | 49 | 28.0s |  |
| 407 | `edittext_underline` | 40 | 8.6s |  |
| 408 | `edittext_width_height` | 103 | 8.7s |  |
| 409 | `edittext_wordwrap_word` | 150 | 8.5s |  |
| 410 | `edittext_wrap_breaks` | 2375 | 9.0s |  |
| 411 | `element_format_clone` | 44 | 8.7s |  |
| 412 | `element_format_constructor_order` | 64 | 3.4s |  |
| 413 | `element_format_properties` | 235 | 9.8s |  |
| 414 | `empty_bounds` | 1 | 7.3s |  |
| 415 | `encode_uri_surrogate_pair_invalid` | 8 | 24.6s |  |
| 416 | `encode_uri_surrogate_pair_swf11` | 15 | 7.4s |  |
| 417 | `equals` | 512 | 11.9s |  |
| 418 | `error_geterrormessage` | 779 | 7.6s |  |
| 419 | `error_prototype` | 15 | 8.0s |  |
| 420 | `error_stack_trace` | 45 | 7.6s |  |
| 421 | `error_stack_trace_debug_swf17` | 0 | 24.8s |  |
| 422 | `error_stack_trace_debug_swf18` | 0 | 7.5s |  |
| 423 | `error_stack_trace_edge_cases` | 6 | 7.6s |  |
| 424 | `error_stack_trace_release_swf17` | 0 | 3.0s |  |
| 425 | `error_stack_trace_release_swf18` | 0 | 7.1s |  |
| 426 | `error_throwerror` | 103 | 7.7s |  |
| 427 | `error_tostring` | 29 | 7.5s |  |
| 428 | `error_tostring_more` | 86 | 8.3s |  |
| 429 | `es3_inheritance` | 31 | 7.7s |  |
| 430 | `es4_inheritance` | 30 | 7.6s |  |
| 431 | `es4_interfaces` | 30 | 7.7s |  |
| 432 | `es4_method_binding` | 8 | 7.8s |  |
| 433 | `es4_oop_prototypes` | 14 | 8.1s |  |
| 434 | `es4_protected_inheritance` | 6 | 7.6s |  |
| 435 | `escape` | 71 | 7.4s |  |
| 436 | `escape_multi_byte` | 45 | 7.8s |  |
| 437 | `event_bubbles` | 2 | 7.4s |  |
| 438 | `event_cancelable` | 2 | 7.1s |  |
| 439 | `event_clone` | 20 | 7.4s |  |
| 440 | `event_clone_error_redispatch` | 3 | 7.6s |  |
| 441 | `event_clone_on_redispatch` | 10 | 7.7s |  |
| 442 | `event_formattostring` | 31 | 7.4s |  |
| 443 | `event_isdefaultprevented` | 12 | 7.2s |  |
| 444 | `event_target_getter` | 5 | 2.8s |  |
| 445 | `event_target_set` | 9 | 7.1s |  |
| 446 | `event_type` | 1 | 7.1s |  |
| 447 | `event_valueof_tostring` | 18 | 7.1s |  |
| 448 | `eventdispatcher_dispatchevent` | 12 | 7.1s |  |
| 449 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.0s |  |
| 450 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.1s |  |
| 451 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.0s |  |
| 452 | `eventdispatcher_dispatchevent_this` | 5 | 7.1s |  |
| 453 | `eventdispatcher_haseventlistener` | 25 | 7.2s |  |
| 454 | `eventdispatcher_interface_invoke` | 1 | 6.9s |  |
| 455 | `eventdispatcher_tostring` | 10 | 7.0s |  |
| 456 | `eventdispatcher_willtrigger` | 25 | 7.0s |  |
| 457 | `falsiness` | 30 | 6.9s |  |
| 458 | `fast_index_access` | 12 | 7.1s |  |
| 459 | `filefilter_properties` | 4 | 7.1s |  |
| 460 | `filereference_browse_cancel` | 3 | 7.1s |  |
| 461 | `filereference_browse_select` | 9 | 7.1s |  |
| 462 | `filereference_load` | 31 | 7.1s |  |
| 463 | `filereference_save` | 16 | 7.1s |  |
| 464 | `filereference_save_and_browse` | 42 | 7.2s |  |
| 465 | `filereference_save_and_load` | 22 | 7.2s |  |
| 466 | `filereference_uninitialized` | 8 | 7.3s |  |
| 467 | `filereferencelist_browse_cancel` | 6 | 7.2s |  |
| 468 | `filereferencelist_browse_select` | 7 | 7.4s |  |
| 469 | `filter_rewind` | 8 | 23.2s |  |
| 470 | `filters_array_holes` | 25 | 8.5s |  |
| 471 | `finddef` | 3 | 7.0s |  |
| 472 | `findprop_global_prototype` | 6 | 7.1s |  |
| 473 | `flash_media_video_constructor` | 156 | 7.7s |  |
| 474 | `flash_media_video_rotation_probe` | 27 | 7.2s |  |
| 475 | `flash_media_video_setter` | 40 | 7.5s |  |
| 476 | `flash_trace` | 17 | 7.2s |  |
| 477 | `flash_ui_mouse_cursor` | 35 | 7.4s |  |
| 478 | `flash_xml` | 29 | 7.2s |  |
| 479 | `flash_xml_cloneNode` | 22 | 7.1s |  |
| 480 | `flash_xml_namespace` | 109 | 7.2s |  |
| 481 | `flash_xml_removeNode` | 60 | 7.3s |  |
| 482 | `focus_events_code` | 161 | 22.9s |  |
| 483 | `focus_events_key_basic` | 132 | 23.1s |  |
| 484 | `focus_events_key_navigation` | 53 | 23.0s |  |
| 485 | `focus_events_key_same_object` | 26 | 7.1s |  |
| 486 | `focus_events_mixed_key_mouse` | 100 | 22.7s |  |
| 487 | `focus_events_mouse_basic` | 260 | 23.1s |  |
| 488 | `focus_events_mouse_focusable` | 112 | 22.9s |  |
| 489 | `focus_events_mouse_same_object` | 40 | 7.2s |  |
| 490 | `focus_remove` | 20 | 22.9s |  |
| 491 | `focus_root_movie` | 4 | 22.9s |  |
| 492 | `focus_stage` | 1 | 7.1s |  |
| 493 | `focusrect` | 18 | 7.9s |  |
| 494 | `focusrect_focuslost` | 9 | 7.2s |  |
| 495 | `focusrect_property` | 110 | 24.4s |  |
| 496 | `font_description_clone` | 14 | 7.3s |  |
| 497 | `font_embedded` | 24 | 24.9s |  |
| 498 | `font_enumeratefonts` | 41 | 8.1s |  |
| 499 | `font_enumeratefonts_filter` | 4 | 8.3s |  |
| 500 | `font_enumeratefonts_order` | 9 | 9.1s |  |
| 501 | `font_hasglyphs` | 40 | 7.9s |  |
| 502 | `font_registerfont` | 129 | 8.4s |  |
| 503 | `framelabel_constr` | 5 | 7.5s |  |
| 504 | `function_call` | 12 | 2.9s |  |
| 505 | `function_call_arguments` | 46 | 7.6s |  |
| 506 | `function_call_arguments_enumerate` | 5 | 7.4s |  |
| 507 | `function_call_coercion` | 108 | 7.7s |  |
| 508 | `function_call_default` | 6 | 7.4s |  |
| 509 | `function_call_rest` | 22 | 7.4s |  |
| 510 | `function_call_types` | 3 | 7.4s |  |
| 511 | `function_call_via_apply` | 11 | 7.5s |  |
| 512 | `function_call_via_call` | 3 | 7.3s |  |
| 513 | `function_display_anonymous` | 7 | 2.9s |  |
| 514 | `function_length` | 6 | 7.5s |  |
| 515 | `function_object` | 2 | 7.4s |  |
| 516 | `function_proto` | 5 | 7.5s |  |
| 517 | `function_proto_created` | 61 | 7.8s |  |
| 518 | `function_to_locale_string` | 4 | 7.6s |  |
| 519 | `function_to_string` | 4 | 7.5s |  |
| 520 | `function_type` | 6 | 7.5s |  |
| 521 | `function_unbound_this` | 51 | 7.7s |  |
| 522 | `function_value_of` | 4 | 7.4s |  |
| 523 | `game_input` | 4 | 7.5s |  |
| 524 | `generate_random_bytes` | 3 | 7.6s |  |
| 525 | `geom_transform` | 74 | 25.9s |  |
| 526 | `get_definition_by_name` | 11 | 7.5s |  |
| 527 | `get_qualified_class_name` | 20 | 7.5s |  |
| 528 | `get_qualified_super_class_name` | 18 | 7.7s |  |
| 529 | `get_slot_edge_cases` | 1 | 7.5s |  |
| 530 | `get_timer` | 2 | 2.9s |  |
| 531 | `getglobalslot` | 1 | 7.5s |  |
| 532 | `getouterscope` | 8 | 7.7s |  |
| 533 | `getouterscope_two_classobjects` | 13 | 7.9s |  |
| 534 | `getter_different_namespace_setter` | 2 | 7.6s |  |
| 535 | `glow_filter` | 127 | 8.1s |  |
| 536 | `goto_button_nested_framescript` | 28 | 26.1s |  |
| 537 | `goto_framescript_queued/swf10` | 59 | 26.1s |  |
| 538 | `goto_framescript_queued/swf9` | 52 | 1.2s |  |
| 539 | `goto_framescript_queued_same_frame` | 4 | 26.0s |  |
| 540 | `goto_in_constructframe` | 12 | 26.2s |  |
| 541 | `goto_in_scene_last_frame` | 2 | 26.0s |  |
| 542 | `goto_methods` | 56 | 8.1s |  |
| 543 | `goto_methods_swfver10` | 8 | 7.8s |  |
| 544 | `goto_nested_construct_sibling` | 18 | 8.3s |  |
| 545 | `goto_nested_framescript` | 9 | 8.1s |  |
| 546 | `goto_on_orphan` | 15 | 26.6s |  |
| 547 | `gradient_bevel_filter` | 206 | 8.1s |  |
| 548 | `gradient_glow_filter` | 206 | 7.8s |  |
| 549 | `graphic_linkage` | 9 | 7.9s |  |
| 550 | `graphics_bad_direct_commands` | 5 | 8.5s |  |
| 551 | `graphics_bitmap_fill` | 0 | 27.8s |  |
| 552 | `graphics_bitmaps` | 0 | 8.2s |  |
| 553 | `graphics_direct_commands` | 0 | 8.3s |  |
| 554 | `graphics_draw_triangles` | 98 | 27.0s |  |
| 555 | `graphics_gradients` | 0 | 8.0s |  |
| 556 | `graphics_gradients_nulls` | 0 | 7.9s |  |
| 557 | `graphics_path` | 56 | 7.7s |  |
| 558 | `graphics_round_rects` | 0 | 9.4s |  |
| 559 | `graphics_simple_shapes` | 0 | 7.7s |  |
| 560 | `greaterequals` | 512 | 10.4s |  |
| 561 | `greaterthan` | 512 | 10.6s |  |
| 562 | `has_own_property` | 102 | 8.1s |  |
| 563 | `hasownproperty_namespaces` | 2 | 7.5s |  |
| 564 | `hello_world` | 1 | 7.5s |  |
| 565 | `hittest_morph` | 30 | 7.7s |  |
| 566 | `id3_info` | 8 | 25.7s |  |
| 567 | `if_eq` | 10 | 7.6s |  |
| 568 | `if_gt` | 1 | 7.5s |  |
| 569 | `if_gte` | 10 | 2.7s |  |
| 570 | `if_lt` | 1 | 1.1s |  |
| 571 | `if_lte` | 10 | 7.5s |  |
| 572 | `if_ne` | 7 | 2.8s |  |
| 573 | `if_stricteq` | 6 | 7.6s |  |
| 574 | `if_strictne` | 11 | 7.6s |  |
| 575 | `ime_linux_dead_keys` | 10 | 7.5s |  |
| 576 | `in` | 102 | 7.1s |  |
| 577 | `inclocal` | 46 | 6.3s |  |
| 578 | `inclocal_i` | 46 | 6.2s |  |
| 579 | `increment` | 46 | 6.5s |  |
| 580 | `increment_i` | 46 | 6.4s |  |
| 581 | `indexing_delete` | 75 | 6.2s |  |
| 582 | `indexof_xml` | 10 | 7.0s |  |
| 583 | `init_callee_cached` | 24 | 6.4s |  |
| 584 | `instanceof` | 58 | 6.5s |  |
| 585 | `instantiate_root_character` | 4 | 6.8s |  |
| 586 | `instantiation_on_enter_frame` | 7 | 21.6s |  |
| 587 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.5s |  |
| 588 | `int_constr` | 92 | 6.7s |  |
| 589 | `int_edge_cases` | 19 | 21.2s |  |
| 590 | `int_instanceof` | 3 | 6.6s |  |
| 591 | `int_tofixed` | 1215 | 6.3s |  |
| 592 | `int_toprecision` | 1125 | 6.5s |  |
| 593 | `int_tostring` | 3375 | 6.8s |  |
| 594 | `interactiveobject_enabled` | 25 | 6.2s |  |
| 595 | `interface_namespaces` | 78 | 6.7s |  |
| 596 | `invalid_utf8` | 12 | 6.7s |  |
| 597 | `is_finite` | 46 | 6.2s |  |
| 598 | `is_nan` | 46 | 6.3s |  |
| 599 | `is_prototype_of` | 12 | 6.9s |  |
| 600 | `issue_10221` | 2 | 6.1s |  |
| 601 | `issue_13780` | 12 | 6.2s |  |
| 602 | `issue_14901` | 1 | 6.3s |  |
| 603 | `issue_17675_edittext_paste_maxchars` | 1 | 6.3s |  |
| 604 | `issue_5292` | 5 | 6.2s |  |
| 605 | `issue_8630` | 2 | 6.4s |  |
| 606 | `issue_8630_placeremoveplace` | 15 | 6.3s |  |
| 607 | `issue_8630_placeremoveplace_scriptremove` | 16 | 6.4s |  |
| 608 | `issue_8630_scriptremove` | 11 | 6.5s |  |
| 609 | `istype` | 24 | 2.2s |  |
| 610 | `istypelate` | 58 | 6.5s |  |
| 611 | `istypelate_coerce` | 198 | 7.1s |  |
| 612 | `jpeg_loader_context` | 6 | 6.1s |  |
| 613 | `json_errors` | 9 | 21.4s |  |
| 614 | `json_parse` | 21 | 6.5s |  |
| 615 | `json_parse_errors` | 84 | 6.6s |  |
| 616 | `json_stringify` | 12 | 6.6s |  |
| 617 | `json_stringify_function` | 12 | 33.2s |  |
| 618 | `json_stringify_order` | 1 | 8.6s |  |
| 619 | `json_version_gated` | 1 | 8.6s |  |
| 620 | `key_input_80percent` | 1812 | 29.4s |  |
| 621 | `key_input_location` | 126 | 8.6s |  |
| 622 | `key_input_numpad` | 384 | 8.3s |  |
| 623 | `large_preload_from_bytes` | 51 | 12.6s |  |
| 624 | `large_preload_from_url` | 27 | 10.9s |  |
| 625 | `large_preload_image_from_bytes` | 25 | 9.1s |  |
| 626 | `lazyinit` | 17 | 8.4s |  |
| 627 | `lessequals` | 512 | 12.3s |  |
| 628 | `lessthan` | 512 | 12.2s |  |
| 629 | `loader_bitmap_transparency` | 14 | 8.6s |  |
| 630 | `loader_bytes_unknown_content` | 14 | 8.7s |  |
| 631 | `loader_child_getdefinition` | 5 | 8.7s |  |
| 632 | `loader_duplicate_class` | 48 | 10.6s |  |
| 633 | `loader_duplicate_coerce` | 3 | 8.7s |  |
| 634 | `loader_duplicate_coerce_new_domain` | 4 | 8.6s |  |
| 635 | `loader_error_in_root_ctor` | 4 | 8.8s |  |
| 636 | `loader_events` | 92 | 9.4s |  |
| 637 | `loader_image` | 8 | 8.9s |  |
| 638 | `loader_jpegxr` | 2 | 29.2s |  |
| 639 | `loader_jpegxr_alpha` | 1 | 28.6s |  |
| 640 | `loader_loadbytes_events` | 30 | 9.2s |  |
| 641 | `loader_loadbytes_invalid_png` | 4 | 8.7s |  |
| 642 | `loader_loadbytes_url` | 12 | 9.0s |  |
| 643 | `loader_loaderurl` | 6 | 9.2s |  |
| 644 | `loader_method` | 85 | 8.8s |  |
| 645 | `loader_noninteractive_try_click_root` | 5 | 30.0s |  |
| 646 | `loader_reuse` | 38 | 9.0s |  |
| 647 | `loader_try_click_root` | 16 | 8.9s |  |
| 648 | `loader_unknown_content` | 24 | 8.8s |  |
| 649 | `loader_visibility_interactive` | 1 | 8.7s |  |
| 650 | `loaderinfo_events` | 7 | 8.6s |  |
| 651 | `loaderinfo_loadurl` | 12 | 8.7s |  |
| 652 | `loaderinfo_more` | 6 | 9.1s |  |
| 653 | `loaderinfo_properties` | 18 | 30.2s |  |
| 654 | `loaderinfo_properties_not_loaded` | 23 | 9.0s |  |
| 655 | `loaderinfo_quine` | 1005 | 8.7s |  |
| 656 | `loaderinfo_root` | 10 | 8.7s |  |
| 657 | `loaderinfo_root_allows` | 2 | 31.7s |  |
| 658 | `localconnection` | 890 | 11.3s |  |
| 659 | `localconnection_send` | 4 | 8.6s |  |
| 660 | `lshift` | 1058 | 19.7s |  |
| 661 | `mask_reapply` | 1 | 30.3s |  |
| 662 | `math` | 497 | 9.0s |  |
| 663 | `matrix` | 338 | 20.8s |  |
| 664 | `matrix3d` | 57 | 29.0s |  |
| 665 | `matrix3d_append` | 16 | 9.1s |  |
| 666 | `matrix3d_append_prepend_scale` | 86 | 8.8s |  |
| 667 | `matrix3d_append_prepend_translation` | 42 | 8.8s |  |
| 668 | `matrix3d_append_rotation` | 23 | 8.8s |  |
| 669 | `matrix3d_compose` | 34 | 9.0s |  |
| 670 | `matrix3d_constructor_clone` | 15 | 8.7s |  |
| 671 | `matrix3d_copy_column` | 83 | 9.1s |  |
| 672 | `matrix3d_copy_from` | 19 | 8.7s |  |
| 673 | `matrix3d_copy_raw_data_from` | 55 | 3.5s |  |
| 674 | `matrix3d_copy_raw_data_to` | 38 | 8.8s |  |
| 675 | `matrix3d_copy_row` | 83 | 8.6s |  |
| 676 | `matrix3d_copy_to_matrix3d` | 19 | 8.7s |  |
| 677 | `matrix3d_determinant` | 182 | 8.8s |  |
| 678 | `matrix3d_interpolate` | 21 | 8.9s |  |
| 679 | `matrix3d_invert` | 18 | 8.7s |  |
| 680 | `matrix3d_position` | 19 | 8.7s |  |
| 681 | `matrix3d_precision` | 28 | 8.8s |  |
| 682 | `matrix3d_prepend` | 16 | 8.6s |  |
| 683 | `matrix3d_raw_data` | 33 | 8.8s |  |
| 684 | `matrix3d_transform_vector` | 52 | 9.0s |  |
| 685 | `matrix3d_transpose` | 5 | 8.8s |  |
| 686 | `method_association` | 5 | 8.7s |  |
| 687 | `method_without_body` | 3 | 28.6s |  |
| 688 | `missing_external_interface` | 10 | 8.8s |  |
| 689 | `modulo` | 1058 | 20.4s |  |
| 690 | `morph_shape` | 2 | 28.5s |  |
| 691 | `mouse_children` | 192 | 29.2s |  |
| 692 | `mouse_click_events` | 90 | 28.2s |  |
| 693 | `mouse_double_click_events` | 188 | 8.8s |  |
| 694 | `mouse_empty_parent` | 4 | 8.9s |  |
| 695 | `mouse_over_while_dragging` | 3 | 8.8s |  |
| 696 | `mouse_pick_avm1_root` | 2 | 29.0s |  |
| 697 | `mouse_pick_button_mode` | 2 | 8.8s |  |
| 698 | `mouse_pick_dobj_mask` | 4 | 9.3s |  |
| 699 | `mouse_pick_masking` | 7 | 29.5s |  |
| 700 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 29.6s |  |
| 701 | `mouse_pick_non_interactive_dobj_mask` | 3 | 9.5s |  |
| 702 | `mouse_pick_text` | 8 | 9.2s |  |
| 703 | `mouse_sibling` | 8 | 9.1s |  |
| 704 | `mouse_wheel_events` | 36 | 31.1s |  |
| 705 | `mouseevent_constr` | 66 | 9.4s |  |
| 706 | `mouseevent_stagexy` | 35 | 9.2s |  |
| 707 | `mouseevent_valueof_tostring` | 28 | 9.2s |  |
| 708 | `movieclip_addframescript` | 3 | 30.0s |  |
| 709 | `movieclip_addframescript_error` | 9 | 9.0s |  |
| 710 | `movieclip_child_property` | 16 | 9.2s |  |
| 711 | `movieclip_constr` | 21 | 9.1s |  |
| 712 | `movieclip_currentlabels` | 17 | 30.4s |  |
| 713 | `movieclip_currentlabels_dupes1` | 46 | 30.6s |  |
| 714 | `movieclip_currentlabels_dupes2` | 30 | 9.2s |  |
| 715 | `movieclip_currentlabels_dupes3` | 67 | 9.4s |  |
| 716 | `movieclip_currentscene` | 12 | 30.1s |  |
| 717 | `movieclip_dispatchevent` | 430 | 9.2s |  |
| 718 | `movieclip_dispatchevent_cancel` | 102 | 9.4s |  |
| 719 | `movieclip_dispatchevent_handlerorder` | 251 | 9.4s |  |
| 720 | `movieclip_dispatchevent_selfadd` | 80 | 9.4s |  |
| 721 | `movieclip_dispatchevent_target` | 899 | 9.8s |  |
| 722 | `movieclip_displayevents` | 96 | 32.1s |  |
| 723 | `movieclip_displayevents_clickgoto` | 676 | 31.2s |  |
| 724 | `movieclip_displayevents_clickgoto2` | 2001 | 10.0s |  |
| 725 | `movieclip_displayevents_clickplay` | 575 | 9.3s |  |
| 726 | `movieclip_displayevents_clicksymbol` | 562 | 9.5s |  |
| 727 | `movieclip_displayevents_constructframegoto` | 140 | 9.8s |  |
| 728 | `movieclip_displayevents_constructframeplay` | 50 | 9.6s |  |
| 729 | `movieclip_displayevents_constructframesymbol` | 144 | 9.4s |  |
| 730 | `movieclip_displayevents_dblhandler` | 21 | 9.3s |  |
| 731 | `movieclip_displayevents_enterframegoto` | 149 | 9.8s |  |
| 732 | `movieclip_displayevents_enterframeplay` | 48 | 9.6s |  |
| 733 | `movieclip_displayevents_enterframesymbol` | 149 | 30.3s |  |
| 734 | `movieclip_displayevents_exitframegoto` | 106 | 9.3s |  |
| 735 | `movieclip_displayevents_exitframeplay` | 44 | 9.2s |  |
| 736 | `movieclip_displayevents_exitframesymbol` | 135 | 9.4s |  |
| 737 | `movieclip_displayevents_looping` | 63 | 31.1s |  |
| 738 | `movieclip_displayevents_stopped` | 113 | 9.7s |  |
| 739 | `movieclip_displayevents_swap` | 96 | 3.3s |  |
| 740 | `movieclip_displayevents_timeline` | 128 | 9.7s |  |
| 741 | `movieclip_drawrect` | 54 | 27.4s |  |
| 742 | `movieclip_frameconstruct_skipped` | 9 | 7.1s |  |
| 743 | `movieclip_goto_during_frame_script` | 15 | 24.3s |  |
| 744 | `movieclip_goto_overwrite` | 14 | 24.7s |  |
| 745 | `movieclip_goto_scene_last_frame_int` | 1 | 23.9s |  |
| 746 | `movieclip_goto_scene_last_frame_label` | 1 | 7.0s |  |
| 747 | `movieclip_gotoandplay` | 15 | 23.9s |  |
| 748 | `movieclip_gotoandstop` | 13 | 7.1s |  |
| 749 | `movieclip_gotoandstop_children` | 4 | 7.1s |  |
| 750 | `movieclip_gotoandstop_framescripts1` | 4 | 7.0s |  |
| 751 | `movieclip_gotoandstop_framescripts2` | 4 | 2.4s |  |
| 752 | `movieclip_gotoandstop_framescripts_self` | 7 | 23.7s |  |
| 753 | `movieclip_gotoandstop_queueing` | 12 | 24.0s |  |
| 754 | `movieclip_hittest` | 67 | 7.3s |  |
| 755 | `movieclip_next_frame` | 2 | 7.0s |  |
| 756 | `movieclip_next_scene` | 6 | 23.9s |  |
| 757 | `movieclip_play` | 3 | 7.0s |  |
| 758 | `movieclip_prev_frame` | 3 | 7.1s |  |
| 759 | `movieclip_prev_scene` | 7 | 7.2s |  |
| 760 | `movieclip_properties` | 79 | 24.3s |  |
| 761 | `movieclip_queued_noop_goto_swf10` | 9 | 7.1s |  |
| 762 | `movieclip_queued_noop_goto_swf9` | 7 | 1.0s |  |
| 763 | `movieclip_scenes` | 11 | 7.1s |  |
| 764 | `movieclip_soundtransform` | 831 | 25.8s |  |
| 765 | `movieclip_stop` | 1 | 7.1s |  |
| 766 | `movieclip_super_is_symbol` | 20 | 7.4s |  |
| 767 | `movieclip_symbol_constr` | 8 | 7.2s |  |
| 768 | `movieclip_text_mousedown` | 1 | 7.2s |  |
| 769 | `movieclip_willtrigger` | 5 | 7.2s |  |
| 770 | `multiply` | 1058 | 14.7s |  |
| 771 | `namespace_constr` | 253 | 7.5s |  |
| 772 | `namespace_constr_args` | 1 | 7.1s |  |
| 773 | `namespace_enumeration_order` | 7 | 24.0s |  |
| 774 | `nan_scale` | 9 | 7.2s |  |
| 775 | `native_menu_basic` | 19 | 9.1s |  |
| 776 | `navigateToURL_target_normalize` | 107 | 25.7s |  |
| 777 | `negate` | 30 | 7.0s |  |
| 778 | `negative_volume_panned` | 0 | 7.3s |  |
| 779 | `nested_iteration` | 11 | 7.0s |  |
| 780 | `net_getClassByAlias` | 3 | 7.1s |  |
| 781 | `net_navigateToURL` | 57 | 7.1s |  |
| 782 | `net_stream_play_options` | 6 | 7.1s |  |
| 783 | `netconnection_close` | 55 | 7.2s |  |
| 784 | `netconnection_properties` | 78 | 33.6s |  |
| 785 | `netconnection_send_remote` | 50 | 33.7s |  |
| 786 | `netconnection_serialize_arrays` | 6 | 9.2s |  |
| 787 | `netfilterevent` | 10 | 30.2s |  |
| 788 | `netstream_client` | 10 | 9.4s |  |
| 789 | `netstream_connect` | 7 | 9.2s |  |
| 790 | `netstream_flv_date` | 4 | 9.3s |  |
| 791 | `newactivation_in_script_init` | 3 | 9.2s |  |
| 792 | `newclass_mismatched` | 4 | 9.2s |  |
| 793 | `newclass_twice` | 3 | 9.2s |  |
| 794 | `nonconflicting_declarations` | 0 | 9.3s |  |
| 795 | `null_void_types` | 8 | 9.3s |  |
| 796 | `number_autoconv` | 21 | 9.2s |  |
| 797 | `number_autoconv_amf` | 132 | 9.2s |  |
| 798 | `number_autoconv_array_sort_32bit` | 1 | 9.2s |  |
| 799 | `number_constr` | 58 | 9.3s |  |
| 800 | `number_convert_edge_cases` | 180 | 30.0s |  |
| 801 | `number_toexponential` | 378 | 9.3s |  |
| 802 | `number_toexponential2` | 35 | 9.2s |  |
| 803 | `number_tofixed` | 378 | 9.1s |  |
| 804 | `number_toprecision` | 350 | 9.3s |  |
| 805 | `obfuscated_class_names` | 3 | 9.2s |  |
| 806 | `object_enumeration` | 10 | 9.2s |  |
| 807 | `object_prototype` | 4 | 9.3s |  |
| 808 | `object_to_locale_string` | 2 | 9.2s |  |
| 809 | `object_to_string` | 2 | 9.2s |  |
| 810 | `object_value_of` | 2 | 3.5s |  |
| 811 | `op_coerce` | 54 | 9.2s |  |
| 812 | `op_coerce_x` | 54 | 9.3s |  |
| 813 | `op_escxattr` | 2 | 9.2s |  |
| 814 | `op_escxelem` | 2 | 9.2s |  |
| 815 | `op_lookupswitch` | 4 | 9.2s |  |
| 816 | `optimize_coerce` | 1 | 9.1s |  |
| 817 | `orphan_movie_complex` | 80 | 9.8s |  |
| 818 | `orphan_movie_reorder` | 111 | 30.8s |  |
| 819 | `orphan_removeobject` | 636 | 31.2s |  |
| 820 | `package_namespace` | 7 | 9.1s |  |
| 821 | `param_default_value_has_zero_cpool_index` | 1 | 31.6s |  |
| 822 | `parent_early_access_child` | 16 | 28.4s |  |
| 823 | `parse_float` | 81 | 28.2s |  |
| 824 | `parse_float_swf10` | 81 | 8.5s |  |
| 825 | `parse_int` | 135 | 9.2s |  |
| 826 | `perspective_projection` | 1443 | 28.5s |  |
| 827 | `perspective_projection_basic` | 40 | 8.6s |  |
| 828 | `pixelbender_ceil` | 77 | 8.8s |  |
| 829 | `pixelbender_conditional` | 138 | 9.1s |  |
| 830 | `pixelbender_conversions` | 270 | 9.0s |  |
| 831 | `pixelbender_dithering` | 8 | 34.5s |  |
| 832 | `pixelbender_div` | 36 | 8.7s |  |
| 833 | `pixelbender_effect_BlurredFocus` | 0 | 37.0s |  |
| 834 | `pixelbender_effect_glassDisplace` | 0 | 15.2s |  |
| 835 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 33.0s |  |
| 836 | `pixelbender_effect_smudge` | 0 | 12.4s |  |
| 837 | `pixelbender_effect_tintype` | 0 | 11.6s |  |
| 838 | `pixelbender_effect_twirl` | 0 | 13.2s |  |
| 839 | `pixelbender_eof` | 7 | 8.8s |  |
| 840 | `pixelbender_images` | 0 | 11.3s |  |
| 841 | `pixelbender_input` | 103 | 30.9s |  |
| 842 | `pixelbender_logicalnot` | 20 | 8.7s |  |
| 843 | `pixelbender_malformed_data` | 190 | 29.3s |  |
| 844 | `pixelbender_multiple_out_params` | 1 | 8.6s |  |
| 845 | `pixelbender_no_out_param` | 6 | 8.6s |  |
| 846 | `pixelbender_outputs` | 13 | 8.8s |  |
| 847 | `pixelbender_padding_bytes` | 22 | 8.7s |  |
| 848 | `pixelbender_param_qualifier` | 512 | 8.8s |  |
| 849 | `pixelbender_parameters` | 1563 | 9.2s |  |
| 850 | `pixelbender_parameters_bool` | 240 | 9.0s |  |
| 851 | `pixelbender_parameters_int_vs_bool` | 54 | 8.8s |  |
| 852 | `pixelbender_parse_errors` | 6 | 8.7s |  |
| 853 | `pixelbender_rsqrt` | 24 | 8.7s |  |
| 854 | `pixelbender_select_kinds` | 8 | 9.0s |  |
| 855 | `pixelbender_shaderdata` | 49 | 8.7s |  |
| 856 | `pixelbender_shaderdata_setter` | 99 | 9.1s |  |
| 857 | `pixelbender_sign` | 60 | 8.9s |  |
| 858 | `pixelbender_vector_output` | 11 | 8.8s |  |
| 859 | `place_and_lookup/swf10` | 33 | 8.7s |  |
| 860 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 861 | `place_multiple` | 17 | 8.8s |  |
| 862 | `place_object_replace` | 9 | 28.1s |  |
| 863 | `place_object_replace_2` | 24 | 20.8s |  |
| 864 | `place_object_same_depth_frame` | 1 | 18.3s |  |
| 865 | `point` | 132 | 6.1s |  |
| 866 | `primitive_edge_cases` | 1 | 18.3s |  |
| 867 | `primitive_keys` | 54 | 5.9s |  |
| 868 | `primitive_toString` | 277 | 6.0s |  |
| 869 | `primitive_valueOf` | 285 | 5.8s |  |
| 870 | `print_job_options` | 3 | 5.9s |  |
| 871 | `property_is_enumerable` | 114 | 6.5s |  |
| 872 | `property_is_enumerable_reset` | 23 | 5.8s |  |
| 873 | `property_priority` | 22 | 6.4s |  |
| 874 | `property_priority_chained` | 4 | 6.1s |  |
| 875 | `property_priority_definition_names_order` | 2 | 6.2s |  |
| 876 | `property_priority_three_level` | 6 | 6.2s |  |
| 877 | `propertyisenumerable_namespaces` | 6 | 6.0s |  |
| 878 | `prototype_set_null` | 7 | 5.8s |  |
| 879 | `proxy_callproperty` | 24 | 5.9s |  |
| 880 | `proxy_deleteproperty` | 64 | 5.7s |  |
| 881 | `proxy_enumeration` | 34 | 5.8s |  |
| 882 | `proxy_getproperty` | 77 | 6.4s |  |
| 883 | `proxy_hasownproperty` | 8 | 6.0s |  |
| 884 | `proxy_hasproperty` | 32 | 5.9s |  |
| 885 | `proxy_not_overridden` | 54 | 5.8s |  |
| 886 | `proxy_serialize` | 9 | 5.9s |  |
| 887 | `proxy_setproperty` | 42 | 5.9s |  |
| 888 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.9s |  |
| 889 | `qname_constr` | 32 | 5.9s |  |
| 890 | `qname_constr_namespace` | 24 | 5.8s |  |
| 891 | `qname_enumeration` | 9 | 5.7s |  |
| 892 | `qname_indexing` | 23 | 5.8s |  |
| 893 | `qname_tostring` | 25 | 5.9s |  |
| 894 | `qname_valueof` | 29 | 5.8s |  |
| 895 | `rectangle` | 1094 | 6.7s |  |
| 896 | `regexp_constr` | 148 | 6.2s |  |
| 897 | `regexp_exec` | 19 | 5.8s |  |
| 898 | `regexp_extended` | 47 | 6.0s |  |
| 899 | `regexp_multiargs` | 1 | 5.8s |  |
| 900 | `regexp_test` | 27 | 5.8s |  |
| 901 | `regexp_toString` | 10 | 6.1s |  |
| 902 | `register_script_refresh` | 35 | 20.0s |  |
| 903 | `remove_child_clear_field` | 88 | 6.6s |  |
| 904 | `remove_dobj` | 3 | 6.3s |  |
| 905 | `resolve_order` | 4 | 32.7s |  |
| 906 | `responder_null_callbacks` | 1 | 28.6s |  |
| 907 | `rng` | 1 | 10.1s |  |
| 908 | `rootless` | 42 | 8.6s |  |
| 909 | `rshift` | 1058 | 19.9s |  |
| 910 | `rtqname_not_namespace` | 12 | 8.7s |  |
| 911 | `sandbox_type_inherited` | 2 | 8.9s |  |
| 912 | `sandbox_type_local_file` | 1 | 8.6s |  |
| 913 | `sandbox_type_local_network` | 1 | 8.4s |  |
| 914 | `scene_constr` | 8 | 8.8s |  |
| 915 | `scope_optimizations` | 4 | 8.7s |  |
| 916 | `scopes_dont_cache/order-1` | 1 | 28.1s |  |
| 917 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 918 | `security_domain_current` | 2 | 8.6s |  |
| 919 | `selection` | 239 | 9.6s |  |
| 920 | `set_local_0` | 31 | 8.8s |  |
| 921 | `set_property_is_enumerable` | 85 | 9.2s |  |
| 922 | `shaderparameter_value` | 4 | 8.6s |  |
| 923 | `shape_drawrect` | 54 | 8.9s |  |
| 924 | `shared_object_no_root` | 3 | 8.6s |  |
| 925 | `simplebutton_added_to_stage` | 45 | 28.4s |  |
| 926 | `simplebutton_childevents` | 86 | 28.8s |  |
| 927 | `simplebutton_childevents_nested` | 54 | 9.3s |  |
| 928 | `simplebutton_childevents_sprite` | 13 | 8.9s |  |
| 929 | `simplebutton_childprops` | 144 | 9.1s |  |
| 930 | `simplebutton_childshuffle` | 23 | 8.6s |  |
| 931 | `simplebutton_constr` | 36 | 9.0s |  |
| 932 | `simplebutton_constr_childevents` | 48 | 9.2s |  |
| 933 | `simplebutton_constr_params` | 42 | 8.9s |  |
| 934 | `simplebutton_mouseenabled` | 26 | 8.7s |  |
| 935 | `simplebutton_multi_children` | 19 | 9.1s |  |
| 936 | `simplebutton_soundtransform` | 887 | 30.6s |  |
| 937 | `simplebutton_structure` | 27 | 9.0s |  |
| 938 | `simplebutton_symbolclass` | 68 | 9.0s |  |
| 939 | `slot_disp_id_shared_numbering` | 1 | 27.7s |  |
| 940 | `slots_force_autoassigned` | 1 | 8.7s |  |
| 941 | `socket_after_disconnect` | 1 | 28.4s |  |
| 942 | `socket_close` | 2 | 7.4s |  |
| 943 | `socket_connect` | 4 | 23.8s |  |
| 944 | `socket_errors` | 56 | 7.7s |  |
| 945 | `socket_read_big` | 48 | 7.4s |  |
| 946 | `socket_read_little` | 48 | 2.9s |  |
| 947 | `socket_read_write_object` | 8 | 7.4s |  |
| 948 | `socket_write_big` | 15 | 7.8s |  |
| 949 | `socket_write_little` | 14 | 7.4s |  |
| 950 | `sound_constructor_with_args` | 6 | 7.5s |  |
| 951 | `sound_embeddedprops` | 26 | 7.6s |  |
| 952 | `sound_play` | 19 | 7.8s |  |
| 953 | `sound_rootless` | 7 | 7.8s |  |
| 954 | `sound_valueof` | 33 | 7.7s |  |
| 955 | `soundchannel_soundtransform` | 835 | 26.8s |  |
| 956 | `soundchannel_soundtransform_exists` | 5 | 25.3s |  |
| 957 | `soundchannel_stop` | 8 | 24.8s |  |
| 958 | `soundmixer_buffertime` | 5 | 8.6s |  |
| 959 | `soundmixer_soundtransform` | 900 | 9.5s |  |
| 960 | `soundmixer_stopall` | 6 | 24.2s |  |
| 961 | `soundtransform` | 442 | 11.8s |  |
| 962 | `space_justifier_clone` | 12 | 7.2s |  |
| 963 | `sprite_with_frames` | 0 | 24.4s |  |
| 964 | `stage3d_agal_cross_product` | 0 | 10.1s |  |
| 965 | `stage3d_agal_upload_errors` | 66 | 11.5s |  |
| 966 | `stage3d_bitmap` | 0 | 28.6s |  |
| 967 | `stage3d_blend` | 81 | 28.7s |  |
| 968 | `stage3d_context3d_string_args` | 158 | 8.4s |  |
| 969 | `stage3d_errors` | 7 | 7.4s |  |
| 970 | `stage3d_errors_atf` | 3 | 8.5s |  |
| 971 | `stage3d_errors_swf_29` | 6 | 7.3s |  |
| 972 | `stage3d_float1_index` | 0 | 25.8s |  |
| 973 | `stage3d_fractal` | 0 | 27.1s |  |
| 974 | `stage3d_ignore_sampler_override` | 0 | 27.7s |  |
| 975 | `stage3d_multistage_triangle` | 3 | 10.0s |  |
| 976 | `stage3d_program_constants_bytearray_be` | 0 | 27.9s |  |
| 977 | `stage3d_program_constants_bytearray_le` | 0 | 10.5s |  |
| 978 | `stage3d_program_constants_invalid_input` | 21 | 8.3s |  |
| 979 | `stage3d_raytrace` | 0 | 46.8s |  |
| 980 | `stage3d_rotating_cube` | 0 | 11.1s |  |
| 981 | `stage3d_sampler` | 0 | 8.6s |  |
| 982 | `stage3d_sampler_partial_upload` | 0 | 8.7s |  |
| 983 | `stage3d_stencil` | 0 | 24.0s |  |
| 984 | `stage3d_texture` | 0 | 13.2s |  |
| 985 | `stage3d_texture_bytearray` | 0 | 9.7s |  |
| 986 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.1s |  |
| 987 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.8s |  |
| 988 | `stage3d_triangle` | 0 | 8.9s |  |
| 989 | `stage3d_triangle_bytes4` | 0 | 8.9s |  |
| 990 | `stage3d_triangle_float1` | 0 | 8.6s |  |
| 991 | `stage3d_triangle_index_upload` | 0 | 9.1s |  |
| 992 | `stage3d_x_y` | 22 | 6.4s |  |
| 993 | `stage_access` | 10 | 6.6s |  |
| 994 | `stage_display_state` | 6 | 6.3s |  |
| 995 | `stage_displayobject_properties` | 24 | 6.6s |  |
| 996 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.5s |  |
| 997 | `stage_framerate_nan` | 7 | 21.1s |  |
| 998 | `stage_framerate_negative` | 6 | 6.5s |  |
| 999 | `stage_framerate_zero` | 6 | 6.2s |  |
| 1000 | `stage_invalidate` | 38 | 6.3s |  |
| 1001 | `stage_loaderinfo_properties` | 24 | 21.5s |  |
| 1002 | `stage_mousechildren` | 2 | 6.5s |  |
| 1003 | `stage_mouseenabled` | 15 | 6.3s |  |
| 1004 | `stage_overriden_setters` | 31 | 6.5s |  |
| 1005 | `stage_properties` | 30 | 6.3s |  |
| 1006 | `stage_properties2` | 213 | 6.5s |  |
| 1007 | `stage_scale_factor` | 12 | 25.1s |  |
| 1008 | `stage_stage3Ds_vector` | 1 | 6.3s |  |
| 1009 | `static_length` | 24 | 6.2s |  |
| 1010 | `static_text` | 3 | 6.6s |  |
| 1011 | `static_var_with_this_in_ctor` | 2 | 6.2s |  |
| 1012 | `statictext_text` | 8 | 7.3s |  |
| 1013 | `stored_properties` | 11 | 6.3s |  |
| 1014 | `strict_equality` | 34 | 6.3s |  |
| 1015 | `string_call` | 13 | 6.2s |  |
| 1016 | `string_case` | 23 | 6.1s |  |
| 1017 | `string_char_at` | 27 | 6.5s |  |
| 1018 | `string_char_code_at` | 28 | 6.6s |  |
| 1019 | `string_concat_fromcharcode` | 37 | 6.5s |  |
| 1020 | `string_constr` | 25 | 6.2s |  |
| 1021 | `string_indexof_lastindexof` | 87 | 27.8s |  |
| 1022 | `string_length` | 16 | 24.2s |  |
| 1023 | `string_locale_compare` | 39 | 7.5s |  |
| 1024 | `string_match` | 51 | 7.6s |  |
| 1025 | `string_relational_compare` | 4 | 7.2s |  |
| 1026 | `string_replace` | 51 | 7.3s |  |
| 1027 | `string_search` | 41 | 7.3s |  |
| 1028 | `string_slice_substr_substring` | 170 | 8.1s |  |
| 1029 | `string_split` | 29 | 7.3s |  |
| 1030 | `string_substr_negative` | 21 | 7.2s |  |
| 1031 | `string_substr_weird` | 182 | 7.1s |  |
| 1032 | `stylesheet` | 221 | 7.9s |  |
| 1033 | `stylesheet_parse_color` | 69 | 7.3s |  |
| 1034 | `stylesheet_transform` | 307 | 7.5s |  |
| 1035 | `sub_super_same_field` | 12 | 2.5s |  |
| 1036 | `subclass_superclass_linked_symbol` | 4 | 7.7s |  |
| 1037 | `subtract` | 1058 | 14.8s |  |
| 1038 | `super_get_call` | 12 | 7.2s |  |
| 1039 | `supercall_two_classobjects` | 2 | 7.1s |  |
| 1040 | `supercalls_coerce` | 8 | 7.2s |  |
| 1041 | `supercalls_weird` | 2 | 7.0s |  |
| 1042 | `superinterface_call` | 20 | 7.1s |  |
| 1043 | `superinterface_instanceof` | 18 | 7.2s |  |
| 1044 | `swf8` | 1 | 7.1s |  |
| 1045 | `swf_10_queued_goto_scripts_construct` | 52 | 24.5s |  |
| 1046 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 1047 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 1048 | `swf_9_queued_goto_scripts` | 6 | 24.2s |  |
| 1049 | `swf_9_queued_goto_scripts_construct` | 28 | 1.0s |  |
| 1050 | `swf_9_versioning` | 2 | 7.2s |  |
| 1051 | `swf_wrong_frame_count` | 38 | 7.6s |  |
| 1052 | `swf_wrong_frame_count_isplaying` | 22 | 7.3s |  |
| 1053 | `symbol_class_binary_data` | 8 | 7.3s |  |
| 1054 | `symbol_class_conflict` | 4 | 7.6s |  |
| 1055 | `symbol_class_root_not_zero` | 1 | 7.1s |  |
| 1056 | `symbolclass_invalid_utf8` | 2 | 7.1s |  |
| 1057 | `system_exit` | 3 | 7.1s |  |
| 1058 | `system_setclipboard_null` | 1 | 7.1s |  |
| 1059 | `tab_ordering_arrows` | 998 | 24.1s |  |
| 1060 | `tab_ordering_automatic_advanced` | 184 | 7.0s |  |
| 1061 | `tab_ordering_automatic_basic` | 45 | 29.8s |  |
| 1062 | `tab_ordering_children` | 116 | 6.7s |  |
| 1063 | `tab_ordering_custom_basic` | 34 | 6.7s |  |
| 1064 | `tab_ordering_properties` | 732 | 6.8s |  |
| 1065 | `tab_ordering_stage_tab_children` | 32 | 6.7s |  |
| 1066 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.7s |  |
| 1067 | `tab_ordering_tabbable` | 47 | 6.7s |  |
| 1068 | `tabstop_properties` | 105 | 26.9s |  |
| 1069 | `text_element_basic` | 34 | 6.8s |  |
| 1070 | `text_engine_fontdescription` | 27 | 6.8s |  |
| 1071 | `text_engine_groupelement` | 64 | 6.7s |  |
| 1072 | `text_run` | 7 | 6.7s |  |
| 1073 | `textblock_createline_errors` | 23 | 6.7s |  |
| 1074 | `textblock_createline_fte` | 9 | 26.5s |  |
| 1075 | `textblock_properties` | 118 | 6.8s |  |
| 1076 | `textbox_click` | 37 | 26.2s |  |
| 1077 | `textfield_event` | 66 | 6.7s |  |
| 1078 | `textfield_focusin_event` | 9 | 6.7s |  |
| 1079 | `textfield_input_dead_keys_windows` | 15 | 6.6s |  |
| 1080 | `textfield_input_events` | 25 | 17.8s |  |
| 1081 | `textfield_unload` | 39 | 26.3s |  |
| 1082 | `textformat` | 1134 | 6.7s |  |
| 1083 | `textformat_display` | 14 | 6.7s |  |
| 1084 | `textformat_font_max_length` | 4 | 6.7s |  |
| 1085 | `textline_inapplicable_properties` | 10 | 6.6s |  |
| 1086 | `textline_name` | 1 | 6.7s |  |
| 1087 | `textline_raw_text_length` | 30 | 6.6s |  |
| 1088 | `textline_splitting_basic` | 76 | 6.6s |  |
| 1089 | `textline_throwerror` | 30 | 6.6s |  |
| 1090 | `textline_validity` | 162 | 6.6s |  |
| 1091 | `throw` | 3 | 6.6s |  |
| 1092 | `timeline_scripts` | 3 | 26.0s |  |
| 1093 | `timer` | 90 | 7.0s |  |
| 1094 | `timer_events` | 3 | 6.7s |  |
| 1095 | `timer_finished` | 11 | 6.7s |  |
| 1096 | `timer_invalid_delay` | 30 | 6.7s |  |
| 1097 | `timer_reset` | 8 | 25.5s |  |
| 1098 | `timer_setdelay` | 5 | 22.5s |  |
| 1099 | `trace` | 12 | 7.0s |  |
| 1100 | `truthiness` | 30 | 6.9s |  |
| 1101 | `try_catch` | 11 | 7.0s |  |
| 1102 | `try_catch_typed` | 12 | 7.0s |  |
| 1103 | `typeof` | 30 | 6.9s |  |
| 1104 | `uint_constr` | 92 | 7.4s |  |
| 1105 | `uint_tofixed` | 1215 | 6.7s |  |
| 1106 | `uint_toprecision` | 1125 | 7.0s |  |
| 1107 | `uint_tostring` | 3375 | 7.1s |  |
| 1108 | `uncaught_error_basic` | 2 | 6.8s |  |
| 1109 | `unchecked_function` | 15 | 7.2s |  |
| 1110 | `unescape` | 28 | 7.0s |  |
| 1111 | `url_loader` | 25 | 7.4s |  |
| 1112 | `url_vars` | 27 | 7.2s |  |
| 1113 | `urlrequest` | 18 | 6.8s |  |
| 1114 | `urlstream_basic` | 5 | 6.9s |  |
| 1115 | `urshift` | 1058 | 15.1s |  |
| 1116 | `utils3d` | 7 | 6.9s |  |
| 1117 | `vector3d` | 397 | 10.3s |  |
| 1118 | `vector3d_near_equals` | 80 | 7.4s |  |
| 1119 | `vector_class` | 36 | 7.3s |  |
| 1120 | `vector_class_call` | 11 | 7.2s |  |
| 1121 | `vector_coercion` | 66 | 7.7s |  |
| 1122 | `vector_concat` | 90 | 7.5s |  |
| 1123 | `vector_constr` | 107 | 7.6s |  |
| 1124 | `vector_enumeration` | 5 | 6.9s |  |
| 1125 | `vector_every` | 92 | 7.6s |  |
| 1126 | `vector_filter` | 95 | 7.7s |  |
| 1127 | `vector_holes` | 24 | 7.0s |  |
| 1128 | `vector_indexof` | 302 | 10.5s |  |
| 1129 | `vector_insertat` | 270 | 7.8s |  |
| 1130 | `vector_int_access` | 4 | 6.9s |  |
| 1131 | `vector_int_delete` | 11 | 6.8s |  |
| 1132 | `vector_join` | 58 | 7.3s |  |
| 1133 | `vector_lastindexof` | 302 | 6.7s |  |
| 1134 | `vector_legacy` | 10 | 7.0s |  |
| 1135 | `vector_map` | 85 | 7.5s |  |
| 1136 | `vector_object_final` | 1 | 6.8s |  |
| 1137 | `vector_object_toString` | 10 | 32.4s |  |
| 1138 | `vector_pushpop` | 255 | 30.3s |  |
| 1139 | `vector_reborrow_bug` | 10 | 8.7s |  |
| 1140 | `vector_removeat` | 172 | 10.2s |  |
| 1141 | `vector_reverse` | 232 | 10.5s |  |
| 1142 | `vector_shiftunshift` | 252 | 9.0s |  |
| 1143 | `vector_slice` | 331 | 11.1s |  |
| 1144 | `vector_sort` | 905 | 19.9s |  |
| 1145 | `vector_splice` | 693 | 13.6s |  |
| 1146 | `vector_splice_fixed_bug_compat` | 4 | 9.1s |  |
| 1147 | `vector_tostring` | 79 | 9.5s |  |
| 1148 | `verification` | 8 | 8.9s |  |
| 1149 | `verify_abnormal_loop` | 1 | 8.7s |  |
| 1150 | `verify_dxns_without_flag` | 3 | 9.0s |  |
| 1151 | `verify_exception_target_two_jumps` | 1 | 8.8s |  |
| 1152 | `verify_exception_targets_edge_case` | 1 | 8.7s |  |
| 1153 | `verify_illegal_opcode` | 1 | 3.5s |  |
| 1154 | `verify_jump_to_middle_of_op` | 1 | 8.8s |  |
| 1155 | `verify_lookup_switch_edge_case` | 1 | 8.8s |  |
| 1156 | `verify_method_info_oob` | 1 | 1.3s |  |
| 1157 | `verify_stack` | 5 | 8.7s |  |
| 1158 | `verify_typecheck` | 4 | 8.8s |  |
| 1159 | `verify_unreachable_exception` | 2 | 8.7s |  |
| 1160 | `versioned_isplaying` | 2 | 8.8s |  |
| 1161 | `virtual_properties` | 16 | 8.8s |  |
| 1162 | `with` | 4 | 8.8s |  |
| 1163 | `wrong_arg_count` | 7 | 8.9s |  |
| 1164 | `xml_abstract_equality` | 36 | 9.0s |  |
| 1165 | `xml_advanced` | 52 | 8.7s |  |
| 1166 | `xml_appendchild` | 10 | 8.7s |  |
| 1167 | `xml_appendchild_swf_v21` | 13 | 9.3s |  |
| 1168 | `xml_as_attribute` | 9 | 8.7s |  |
| 1169 | `xml_attribute` | 35 | 8.9s |  |
| 1170 | `xml_attribute_name` | 40 | 8.8s |  |
| 1171 | `xml_basic` | 33 | 8.9s |  |
| 1172 | `xml_child` | 25 | 8.9s |  |
| 1173 | `xml_childindex` | 7 | 8.8s |  |
| 1174 | `xml_children` | 43 | 9.4s |  |
| 1175 | `xml_class_call` | 9 | 8.8s |  |
| 1176 | `xml_contains` | 197 | 9.1s |  |
| 1177 | `xml_copy` | 20 | 34.6s |  |
| 1178 | `xml_ctor_from_tostring` | 23 | 31.8s |  |
| 1179 | `xml_delete` | 114 | 9.4s |  |
| 1180 | `xml_descendants` | 83 | 9.3s |  |
| 1181 | `xml_duplicate_attribute` | 14 | 9.2s |  |
| 1182 | `xml_elements` | 6 | 9.2s |  |
| 1183 | `xml_equals_namespace_check` | 2 | 9.1s |  |
| 1184 | `xml_explicit_use_namespace` | 5 | 9.2s |  |
| 1185 | `xml_getdescendants_qname` | 21 | 9.2s |  |
| 1186 | `xml_has_property_via_in` | 26 | 9.2s |  |
| 1187 | `xml_hasownproperty` | 6 | 9.0s |  |
| 1188 | `xml_ignore_white` | 6 | 9.2s |  |
| 1189 | `xml_length` | 2 | 9.2s |  |
| 1190 | `xml_list_as_attribute` | 9 | 9.0s |  |
| 1191 | `xml_list_concat` | 20 | 9.2s |  |
| 1192 | `xml_list_ctor_errors` | 34 | 9.1s |  |
| 1193 | `xml_list_delete_clear_parent` | 6 | 8.9s |  |
| 1194 | `xml_list_enumerate` | 4 | 8.9s |  |
| 1195 | `xml_methods_settings` | 3 | 9.2s |  |
| 1196 | `xml_mismatched_tag` | 37 | 9.2s |  |
| 1197 | `xml_namespace` | 39 | 9.2s |  |
| 1198 | `xml_namespace_methods` | 245 | 9.1s |  |
| 1199 | `xml_namespaced_property` | 7 | 9.0s |  |
| 1200 | `xml_no_namespace` | 1 | 9.0s |  |
| 1201 | `xml_nodekind` | 3 | 9.0s |  |
| 1202 | `xml_normalize` | 35 | 9.2s |  |
| 1203 | `xml_notification_bubbling` | 361 | 9.1s |  |
| 1204 | `xml_parent` | 8 | 8.9s |  |
| 1205 | `xml_set_children` | 17 | 9.1s |  |
| 1206 | `xml_set_name` | 34 | 9.0s |  |
| 1207 | `xml_settings` | 6 | 3.4s |  |
| 1208 | `xml_simple_complex_content` | 47 | 9.0s |  |
| 1209 | `xml_socket` | 11 | 9.1s |  |
| 1210 | `xml_text` | 7 | 9.0s |  |
| 1211 | `xml_tostring` | 6 | 9.0s |  |
| 1212 | `xml_tostring_namespace` | 12 | 8.7s |  |
| 1213 | `xml_unescaping` | 23 | 9.0s |  |
| 1214 | `xml_weird_ignores` | 54 | 9.1s |  |
| 1215 | `xml_wildcard` | 11 | 9.0s |  |
| 1216 | `xmldocument` | 254 | 9.1s |  |
| 1217 | `xmlnode` | 3540 | 9.2s |  |
| 1218 | `zero_frame_clip` | 3 | 9.7s |  |

## Ruffle-Matched Tests

**38 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 5.7s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.8s |  |
| 3 | `blend_transform` | 1 | 1 | 9.1s |  |
| 4 | `bounds_mode` | 6 | 6 | 9.4s |  |
| 5 | `coerce_property` | 3 | 3 | 9.4s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 9.4s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 29.8s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 22.9s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 7.9s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.9s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 7.5s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 8.6s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.8s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 7.6s |  |
| 15 | `event_handler_exception` | 4 | 4 | 7.5s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 7.7s |  |
| 17 | `goto_framescript_queued/swf13` | 3 | 3 | 1.2s |  |
| 18 | `graphics_draw_path` | 50 | 50 | 26.8s |  |
| 19 | `groupelement_text` | 2 | 2 | 7.7s |  |
| 20 | `int_toexponential` | 76 | 76 | 6.5s |  |
| 21 | `json_parse_numbers` | 4 | 79 | 6.3s |  |
| 22 | `loader_events_2` | 30 | 30 | 9.1s |  |
| 23 | `matrix3d_recompose_edge_cases` | 8 | 85 | 9.2s |  |
| 24 | `number_convert_errors` | 706 | 706 | 9.5s |  |
| 25 | `number_to_string` | 104 | 104 | 9.8s |  |
| 26 | `simplebutton_childevents_script_order` | 4 | 4 | 9.1s |  |
| 27 | `slot_holes_fail` | 1 | 1 | 8.6s |  |
| 28 | `slot_id_exceeds_trait_count` | 1 | 1 | 8.6s |  |
| 29 | `soundchannel_position` | 74 | 74 | 26.6s |  |
| 30 | `soundchannel_soundcomplete` | 10 | 10 | 8.3s |  |
| 31 | `sprite_dropTarget` | 15 | 15 | 7.5s |  |
| 32 | `swf_9_goto_in_construct_frame` | 12 | 12 | 24.4s |  |
| 33 | `textblock_line_changes` | 44 | 44 | 6.7s |  |
| 34 | `textblock_recreateline` | 139 | 140 | 6.7s |  |
| 35 | `textblock_releaselines` | 4 | 4 | 6.8s |  |
| 36 | `uint_toexponential` | 100 | 100 | 7.2s |  |
| 37 | `uncaught_errors_stringified` | 15 | 15 | 6.9s |  |
| 38 | `weird_superinterface_properties` | 1 | 1 | 8.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**7 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `textline_has_tabs` | 89.4% | 42 | 47 | 5 |  |
| 3 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 4 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 5 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 6 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 7 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**24 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `textline_has_tabs` | 89.4% | 42/47 | 47 | 47 |  |
| 3 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 4 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 5 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 6 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 7 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 8 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 9 | `gradient_values_readback` | 37.2% | 81/218 | 218 | 212 |  |
| 10 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 11 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 12 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 13 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 14 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 15 | `textjustifier_locale` | 6.1% | 8/132 | 52 | 132 |  |
| 16 | `casi32` | 5.2% | 9/174 | 174 | 166 |  |
| 17 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 18 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 19 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 20 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 21 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 22 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 23 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 24 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
