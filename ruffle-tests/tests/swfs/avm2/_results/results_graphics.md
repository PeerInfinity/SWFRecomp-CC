# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-17 00:59 UTC

**Git SHA**: `bdf127c35c`

**Run Duration**: 237m 6s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1291 |
| Passing | **1228** (95.1%) |
| Ruffle-matched | 41 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1269** (98.3%) |
| Failing | 22 |
| Total expected lines | 158864 |
| Matching lines | 156013 (98.2%) |
| Mismatched lines | 2851 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 22 | 100.0% |

## Passing Tests

**1228 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 33.7s |  |
| 2 | `accessibility` | 1 | 9.0s |  |
| 3 | `accessibilityimplementation` | 18 | 29.3s |  |
| 4 | `activation_class` | 6 | 9.0s |  |
| 5 | `add` | 1058 | 19.6s |  |
| 6 | `agal_compiler` | 13 | 11.8s |  |
| 7 | `air_datagram_socket` | 1 | 11.1s |  |
| 8 | `air_hidden_lookup` | 2 | 8.9s |  |
| 9 | `air_ifilepromise` | 1 | 8.9s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 9.1s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.4s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.4s |  |
| 13 | `all_classes/display/swf10` | 2569 | 9.1s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.5s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.5s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.5s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.4s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.4s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 9.0s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.4s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.4s |  |
| 22 | `all_classes/errors/swf10` | 140 | 9.0s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.4s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.4s |  |
| 25 | `all_classes/events/swf10` | 1638 | 9.1s |  |
| 26 | `all_classes/events/swf11` | 1750 | 1.4s |  |
| 27 | `all_classes/events/swf12` | 1814 | 1.4s |  |
| 28 | `all_classes/events/swf30` | 2353 | 1.4s |  |
| 29 | `all_classes/events/swf9` | 1030 | 1.4s |  |
| 30 | `all_classes/security/swf11` | 3 | 9.0s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.4s |  |
| 32 | `all_classes/security/swf13` | 53 | 1.4s |  |
| 33 | `all_classes/security/swf30` | 53 | 1.4s |  |
| 34 | `all_classes/xml/swf30` | 116 | 9.0s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.4s |  |
| 36 | `amf_array_serialization` | 17 | 31.9s |  |
| 37 | `amf_custom_obj` | 26 | 9.1s |  |
| 38 | `amf_dictionary` | 9 | 9.0s |  |
| 39 | `amf_function` | 46 | 9.2s |  |
| 40 | `amf_invalid_date` | 2 | 8.9s |  |
| 41 | `amf_missing_prop` | 6 | 9.0s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 8.9s |  |
| 43 | `amf_setter_error` | 8 | 9.1s |  |
| 44 | `amf_vector` | 40 | 9.2s |  |
| 45 | `amf_xml` | 6 | 32.4s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 9.3s |  |
| 47 | `application_domain` | 4 | 8.7s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 28.0s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 8.5s |  |
| 50 | `array_access` | 18 | 8.7s |  |
| 51 | `array_access_interpreter` | 4 | 8.5s |  |
| 52 | `array_access_no_pubns` | 2 | 8.5s |  |
| 53 | `array_concat` | 41 | 8.5s |  |
| 54 | `array_constr` | 10 | 8.4s |  |
| 55 | `array_delete` | 44 | 8.6s |  |
| 56 | `array_enumeration` | 10 | 8.5s |  |
| 57 | `array_enumeration_elements` | 11 | 8.5s |  |
| 58 | `array_every` | 8 | 8.5s |  |
| 59 | `array_filter` | 6 | 8.5s |  |
| 60 | `array_foreach` | 18 | 8.5s |  |
| 61 | `array_hasownproperty` | 11 | 8.5s |  |
| 62 | `array_holes` | 9 | 8.5s |  |
| 63 | `array_index_max` | 84 | 8.4s |  |
| 64 | `array_indexof` | 25 | 8.5s |  |
| 65 | `array_join` | 26 | 8.5s |  |
| 66 | `array_lastindexof` | 29 | 8.5s |  |
| 67 | `array_length` | 14 | 8.5s |  |
| 68 | `array_literal` | 3 | 8.5s |  |
| 69 | `array_map` | 8 | 8.3s |  |
| 70 | `array_pop` | 52 | 8.6s |  |
| 71 | `array_push` | 24 | 8.5s |  |
| 72 | `array_reborrow_bug` | 6 | 8.5s |  |
| 73 | `array_reverse` | 28 | 8.6s |  |
| 74 | `array_shift` | 51 | 3.4s |  |
| 75 | `array_slice` | 39 | 8.7s |  |
| 76 | `array_some` | 8 | 8.5s |  |
| 77 | `array_sort` | 297 | 9.3s |  |
| 78 | `array_sort_fun_swf12` | 2 | 8.5s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 80 | `array_sort_random` | 210 | 8.5s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 8.5s |  |
| 82 | `array_sorton` | 545 | 9.6s |  |
| 83 | `array_sparse_ops` | 41 | 8.7s |  |
| 84 | `array_splice` | 133 | 8.8s |  |
| 85 | `array_splice2` | 428 | 8.8s |  |
| 86 | `array_splice_types` | 48 | 32.6s |  |
| 87 | `array_storage` | 8 | 28.2s |  |
| 88 | `array_tolocalestring` | 9 | 8.6s |  |
| 89 | `array_tostring` | 12 | 8.8s |  |
| 90 | `array_unshift` | 24 | 8.6s |  |
| 91 | `array_valueof` | 9 | 8.5s |  |
| 92 | `array_vector_null_callback` | 10 | 8.8s |  |
| 93 | `astype` | 28 | 8.9s |  |
| 94 | `astypelate` | 24 | 8.9s |  |
| 95 | `astypelate_propagates` | 1 | 8.8s |  |
| 96 | `asymmetric_key_events` | 11 | 9.4s |  |
| 97 | `automation_classes` | 122 | 9.4s |  |
| 98 | `av_classes` | 340 | 9.3s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 9.1s |  |
| 100 | `avm2_catchup_dobj` | 158 | 10.0s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 113.0s |  |
| 102 | `bevel_filter` | 187 | 9.2s |  |
| 103 | `bitand` | 1058 | 20.1s |  |
| 104 | `bitmap_constr` | 17 | 9.0s |  |
| 105 | `bitmap_data` | 1000 | 20.1s |  |
| 106 | `bitmap_filter_abstract` | 6 | 9.0s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 29.2s |  |
| 108 | `bitmap_properties` | 23 | 8.9s |  |
| 109 | `bitmap_subclass` | 7 | 10.6s |  |
| 110 | `bitmap_subclass_properties` | 9 | 9.2s |  |
| 111 | `bitmap_timeline` | 9 | 9.1s |  |
| 112 | `bitmapdata_accuracy` | 1 | 45.1s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 29.6s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.6s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 31.3s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 29.7s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 28.6s |  |
| 118 | `bitmapdata_clone` | 13 | 8.9s |  |
| 119 | `bitmapdata_colortransform` | 0 | 9.1s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 8.6s |  |
| 121 | `bitmapdata_constr` | 22 | 8.9s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 9.1s |  |
| 123 | `bitmapdata_copychannel` | 0 | 30.3s |  |
| 124 | `bitmapdata_copypixels` | 23 | 29.4s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 8.8s |  |
| 126 | `bitmapdata_copypixels_alpha_merge` | 9 | 8.6s |  |
| 127 | `bitmapdata_copypixels_blend` | 1029 | 34.0s |  |
| 128 | `bitmapdata_copypixels_blend_over` | 1 | 8.7s |  |
| 129 | `bitmapdata_copypixels_self` | 612 | 8.7s |  |
| 130 | `bitmapdata_copypixelstobytearray` | 39 | 8.6s |  |
| 131 | `bitmapdata_dispose` | 7 | 8.7s |  |
| 132 | `bitmapdata_draw` | 0 | 30.0s |  |
| 133 | `bitmapdata_draw_alpha_erase` | 8 | 8.8s |  |
| 134 | `bitmapdata_draw_cab_quality` | 0 | 30.6s |  |
| 135 | `bitmapdata_draw_colortransform` | 0 | 29.2s |  |
| 136 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 29.3s |  |
| 137 | `bitmapdata_draw_filters` | 0 | 29.2s |  |
| 138 | `bitmapdata_draw_masks` | 0 | 9.0s |  |
| 139 | `bitmapdata_draw_rotation` | 0 | 8.9s |  |
| 140 | `bitmapdata_draw_self_via_graphic` | 0 | 8.7s |  |
| 141 | `bitmapdata_draw_stage` | 0 | 29.3s |  |
| 142 | `bitmapdata_drawwithquality` | 0 | 11.3s |  |
| 143 | `bitmapdata_embedded` | 9 | 8.9s |  |
| 144 | `bitmapdata_fillrect` | 0 | 8.8s |  |
| 145 | `bitmapdata_filter_sourcerect` | 0 | 29.4s |  |
| 146 | `bitmapdata_floodfill` | 35 | 8.6s |  |
| 147 | `bitmapdata_getpixels` | 39 | 29.1s |  |
| 148 | `bitmapdata_getvector` | 27 | 3.1s |  |
| 149 | `bitmapdata_histogram` | 59 | 3.1s |  |
| 150 | `bitmapdata_hittest` | 112 | 9.2s |  |
| 151 | `bitmapdata_hittest_threshold` | 18 | 8.7s |  |
| 152 | `bitmapdata_opaque` | 0 | 8.7s |  |
| 153 | `bitmapdata_pixeldissolve` | 1037 | 9.2s |  |
| 154 | `bitmapdata_pixeldissolve_image` | 0 | 8.9s |  |
| 155 | `bitmapdata_rectangle_rounding` | 16 | 8.6s |  |
| 156 | `bitmapdata_setpixels` | 286 | 8.8s |  |
| 157 | `bitmapdata_setvector` | 26 | 8.8s |  |
| 158 | `bitmapdata_sync` | 0 | 29.4s |  |
| 159 | `bitmapdata_threshold` | 176 | 9.3s |  |
| 160 | `bitmapdata_zero_size` | 8 | 8.7s |  |
| 161 | `bitnot` | 46 | 8.7s |  |
| 162 | `bitor` | 1058 | 17.6s |  |
| 163 | `bitxor` | 1058 | 17.6s |  |
| 164 | `blend_mode_null` | 1 | 8.6s |  |
| 165 | `blend_multiply_alpha` | 0 | 8.7s |  |
| 166 | `blend_scroll` | 0 | 8.7s |  |
| 167 | `blend_shader_luma_lighten` | 3 | 9.0s |  |
| 168 | `blur_filter` | 43 | 8.9s |  |
| 169 | `boolean_constr` | 32 | 9.1s |  |
| 170 | `boolean_negation` | 30 | 8.9s |  |
| 171 | `boolean_tostring` | 8 | 8.9s |  |
| 172 | `broadcast_event` | 7 | 9.1s |  |
| 173 | `button_bounds` | 1 | 9.0s |  |
| 174 | `button_hittest` | 2 | 29.1s |  |
| 175 | `button_nested_frame` | 48 | 30.3s |  |
| 176 | `button_nested_frame_simple` | 27 | 9.6s |  |
| 177 | `bytearray` | 48 | 9.4s |  |
| 178 | `bytearray_bad_symbol_class` | 3 | 9.2s |  |
| 179 | `bytearray_bad_symbol_class_other_movie` | 6 | 9.8s |  |
| 180 | `bytearray_compress` | 31 | 9.2s |  |
| 181 | `bytearray_errors` | 24 | 9.3s |  |
| 182 | `bytearray_method_serialization` | 1 | 9.1s |  |
| 183 | `bytearray_oom` | 3 | 9.1s |  |
| 184 | `bytearray_readobject_amf0` | 50 | 9.1s |  |
| 185 | `bytearray_readobject_amf3` | 53 | 9.2s |  |
| 186 | `bytearray_readutf8bytes_with_bom` | 16 | 9.2s |  |
| 187 | `bytearray_serialization` | 3 | 9.2s |  |
| 188 | `bytearray_string_null` | 19 | 9.4s |  |
| 189 | `bytearray_tostring` | 15 | 9.1s |  |
| 190 | `bytearray_utf16` | 8 | 9.1s |  |
| 191 | `bytearray_writeobject` | 24 | 9.0s |  |
| 192 | `callee_in_initializer` | 6 | 9.0s |  |
| 193 | `callproplex_class` | 1 | 9.1s |  |
| 194 | `capabilities_resolution` | 8 | 31.4s |  |
| 195 | `casi32` | 166 | 9.2s |  |
| 196 | `catch_class` | 6 | 9.1s |  |
| 197 | `catch_scope_slot` | 7 | 9.2s |  |
| 198 | `checkfilter` | 4 | 3.6s |  |
| 199 | `class_call` | 32 | 9.4s |  |
| 200 | `class_cast_call` | 14 | 9.1s |  |
| 201 | `class_enumeration` | 4 | 9.1s |  |
| 202 | `class_has_own_property` | 2 | 9.1s |  |
| 203 | `class_init_interpreter_mode` | 1 | 9.1s |  |
| 204 | `class_is` | 32 | 9.2s |  |
| 205 | `class_methods` | 5 | 9.1s |  |
| 206 | `class_object_properties` | 10 | 9.1s |  |
| 207 | `class_singleton` | 18 | 9.2s |  |
| 208 | `class_supercalls_errors` | 35 | 9.4s |  |
| 209 | `class_supercalls_mismatched` | 26 | 9.2s |  |
| 210 | `class_superclass_wrong_order` | 1 | 28.4s |  |
| 211 | `class_to_locale_string` | 2 | 8.7s |  |
| 212 | `class_to_string` | 2 | 8.5s |  |
| 213 | `class_value_of` | 2 | 8.7s |  |
| 214 | `click_block` | 5 | 29.2s |  |
| 215 | `click_invisible` | 3 | 8.9s |  |
| 216 | `closures` | 12 | 8.7s |  |
| 217 | `coerce_return_type` | 40 | 8.8s |  |
| 218 | `coerce_return_type_fail` | 2 | 8.6s |  |
| 219 | `coerce_return_void` | 3 | 8.6s |  |
| 220 | `coerce_string` | 86 | 8.8s |  |
| 221 | `coerce_string_precision` | 28 | 8.7s |  |
| 222 | `coerce_to_primitive_side_effects` | 29 | 8.8s |  |
| 223 | `collator_compare_basic` | 93 | 8.9s |  |
| 224 | `collator_flags` | 111 | 8.7s |  |
| 225 | `collator_locale_ids_windows` | 120 | 8.9s |  |
| 226 | `color_matrix_filter` | 19 | 8.8s |  |
| 227 | `construct_errors_swf10` | 8 | 8.8s |  |
| 228 | `construct_frame_list` | 22 | 28.5s |  |
| 229 | `construct_interface` | 3 | 8.7s |  |
| 230 | `constructor_call` | 3 | 8.7s |  |
| 231 | `constructors_vs_timeline` | 5 | 28.2s |  |
| 232 | `constructprop_dynamic_primitive` | 7 | 8.8s |  |
| 233 | `constructprop_method` | 2 | 8.6s |  |
| 234 | `constructsuper_null` | 2 | 3.3s |  |
| 235 | `content_element_basic` | 50 | 9.0s |  |
| 236 | `context3d_creation` | 9 | 10.9s |  |
| 237 | `control_flow_bool` | 4 | 8.7s |  |
| 238 | `control_flow_stricteq` | 8 | 8.7s |  |
| 239 | `convert_boolean` | 30 | 8.7s |  |
| 240 | `convert_integer` | 90 | 8.8s |  |
| 241 | `convert_number` | 56 | 8.8s |  |
| 242 | `convert_uinteger` | 90 | 8.8s |  |
| 243 | `convolution_filter` | 89 | 8.8s |  |
| 244 | `core_exceptions` | 47 | 9.9s |  |
| 245 | `cpool_index_invalid_bytecode_1` | 6 | 8.7s |  |
| 246 | `cpool_index_invalid_bytecode_2` | 3 | 8.7s |  |
| 247 | `cpool_index_invalid_bytecode_3` | 1 | 8.6s |  |
| 248 | `cross_api_version_call_newer` | 12 | 9.4s |  |
| 249 | `cross_api_version_call_older` | 12 | 9.0s |  |
| 250 | `cryptscore` | 11 | 8.8s |  |
| 251 | `currency_parse_result` | 7 | 7.3s |  |
| 252 | `date` | 30 | 7.7s |  |
| 253 | `date_parse` | 36 | 7.3s |  |
| 254 | `date_set_time_out_of_range` | 62 | 7.5s |  |
| 255 | `declocal` | 46 | 7.4s |  |
| 256 | `declocal_i` | 46 | 7.4s |  |
| 257 | `decode_uri` | 71 | 7.5s |  |
| 258 | `decrement` | 46 | 7.2s |  |
| 259 | `decrement_i` | 46 | 2.8s |  |
| 260 | `default_values` | 7 | 7.2s |  |
| 261 | `delayed_symbolclass` | 28 | 23.8s |  |
| 262 | `describe_type_basic` | 152 | 7.5s |  |
| 263 | `describe_type_json` | 301 | 7.5s |  |
| 264 | `describe_type_metadata` | 125 | 7.3s |  |
| 265 | `describe_type_native` | 23 | 7.2s |  |
| 266 | `dictionary_access` | 62 | 7.6s |  |
| 267 | `dictionary_access_no_pubns` | 2 | 7.3s |  |
| 268 | `dictionary_delete` | 101 | 7.8s |  |
| 269 | `dictionary_foreach` | 42 | 7.5s |  |
| 270 | `dictionary_hasownproperty` | 63 | 7.4s |  |
| 271 | `dictionary_in` | 62 | 8.0s |  |
| 272 | `dictionary_iter_modify` | 8 | 7.8s |  |
| 273 | `dictionary_namespaces` | 36 | 7.3s |  |
| 274 | `displacement_map_filter` | 61 | 8.0s |  |
| 275 | `displayobject_alpha` | 277 | 7.2s |  |
| 276 | `displayobject_blendmode` | 0 | 26.5s |  |
| 277 | `displayobject_colortransform_nested` | 0 | 24.0s |  |
| 278 | `displayobject_early_init` | 54 | 8.9s |  |
| 279 | `displayobject_filters` | 17 | 7.6s |  |
| 280 | `displayobject_from_enterframe` | 1 | 23.3s |  |
| 281 | `displayobject_getbounds_shape` | 0 | 23.5s |  |
| 282 | `displayobject_getrect` | 16 | 7.4s |  |
| 283 | `displayobject_height` | 6052 | 24.3s |  |
| 284 | `displayobject_hittestobject` | 32 | 7.5s |  |
| 285 | `displayobject_hittestpoint` | 49 | 7.7s |  |
| 286 | `displayobject_hittestpoint_boundary` | 65 | 24.8s |  |
| 287 | `displayobject_hittestpoint_root` | 13 | 7.6s |  |
| 288 | `displayobject_invalid_floats` | 60 | 7.3s |  |
| 289 | `displayobject_invalid_props` | 3 | 7.2s |  |
| 290 | `displayobject_mask` | 3 | 7.6s |  |
| 291 | `displayobject_mask_self_referential` | 0 | 7.2s |  |
| 292 | `displayobject_metaData` | 3 | 9.5s |  |
| 293 | `displayobject_name` | 22 | 9.9s |  |
| 294 | `displayobject_name_from_timeline` | 24 | 9.8s |  |
| 295 | `displayobject_opaque_background` | 6 | 10.0s |  |
| 296 | `displayobject_parent` | 12 | 9.7s |  |
| 297 | `displayobject_root` | 24 | 9.7s |  |
| 298 | `displayobject_rotation` | 1284 | 9.8s |  |
| 299 | `displayobject_scrollrect` | 33 | 10.8s |  |
| 300 | `displayobject_set_matrix_nested` | 0 | 31.3s |  |
| 301 | `displayobject_set_name_loaded` | 3 | 10.1s |  |
| 302 | `displayobject_subclass` | 2 | 9.7s |  |
| 303 | `displayobject_transform` | 89 | 9.9s |  |
| 304 | `displayobject_visible` | 23 | 9.8s |  |
| 305 | `displayobject_width` | 4852 | 32.0s |  |
| 306 | `displayobject_x` | 614 | 9.8s |  |
| 307 | `displayobject_y` | 617 | 9.8s |  |
| 308 | `displayobject_z` | 38 | 32.5s |  |
| 309 | `displayobjectcontainer_addchild` | 32 | 10.0s |  |
| 310 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 9.7s |  |
| 311 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 10.1s |  |
| 312 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 9.9s |  |
| 313 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 9.9s |  |
| 314 | `displayobjectcontainer_addchildat` | 42 | 9.8s |  |
| 315 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 9.9s |  |
| 316 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 9.8s |  |
| 317 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 9.8s |  |
| 318 | `displayobjectcontainer_contains` | 66 | 31.7s |  |
| 319 | `displayobjectcontainer_getchildat` | 4 | 9.9s |  |
| 320 | `displayobjectcontainer_getchildbyname` | 9 | 9.7s |  |
| 321 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 9.6s |  |
| 322 | `displayobjectcontainer_getchildindex` | 28 | 9.7s |  |
| 323 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 9.7s |  |
| 324 | `displayobjectcontainer_removechild` | 10 | 9.5s |  |
| 325 | `displayobjectcontainer_removechild_errors` | 4 | 9.6s |  |
| 326 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 9.5s |  |
| 327 | `displayobjectcontainer_removechildat` | 18 | 9.5s |  |
| 328 | `displayobjectcontainer_removechildren` | 51 | 9.6s |  |
| 329 | `displayobjectcontainer_setchildindex` | 42 | 9.3s |  |
| 330 | `displayobjectcontainer_stopallmovieclips` | 2 | 31.4s |  |
| 331 | `displayobjectcontainer_swapchildren` | 42 | 9.6s |  |
| 332 | `displayobjectcontainer_swapchildrenat` | 42 | 9.6s |  |
| 333 | `displayobjectcontainer_timelineinstance` | 48 | 30.9s |  |
| 334 | `divide` | 1058 | 12.5s |  |
| 335 | `doabc_and_symbolclass_script_init_goto` | 7 | 19.4s |  |
| 336 | `doabc_and_symbolclass_script_init_normal` | 6 | 5.9s |  |
| 337 | `doabc_is_eager` | 1 | 18.4s |  |
| 338 | `documentclass` | 9 | 6.0s |  |
| 339 | `domain_memory` | 133 | 20.1s |  |
| 340 | `drag_drop` | 10 | 6.6s |  |
| 341 | `drop_shadow_filter` | 172 | 6.6s |  |
| 342 | `duplicate_defs` | 1 | 6.1s |  |
| 343 | `eager_init` | 1 | 6.3s |  |
| 344 | `east_asian_justifier_clone` | 8 | 6.5s |  |
| 345 | `edit_text_linkage` | 7 | 6.4s |  |
| 346 | `edittext_align` | 60 | 6.4s |  |
| 347 | `edittext_always_show_selection` | 0 | 21.9s |  |
| 348 | `edittext_antialiastype` | 296 | 6.2s |  |
| 349 | `edittext_at_point_methods_basic` | 16 | 6.9s |  |
| 350 | `edittext_autosize` | 39 | 6.3s |  |
| 351 | `edittext_autosize_align` | 0 | 18.8s |  |
| 352 | `edittext_autosize_height_dynamic` | 60 | 19.2s |  |
| 353 | `edittext_autosize_height_input` | 60 | 6.2s |  |
| 354 | `edittext_autosize_lazy_bounds_events` | 65 | 6.2s |  |
| 355 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.0s |  |
| 356 | `edittext_autosize_lazy_bounds_props` | 490 | 7.1s |  |
| 357 | `edittext_autosize_lazy_bounds_visual` | 0 | 6.1s |  |
| 358 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.1s |  |
| 359 | `edittext_bottom_scroll_v_basic` | 210 | 6.0s |  |
| 360 | `edittext_bounds_scale` | 24 | 18.9s |  |
| 361 | `edittext_bullet` | 30 | 6.0s |  |
| 362 | `edittext_default_format` | 221 | 6.3s |  |
| 363 | `edittext_default_format_empty` | 136 | 6.1s |  |
| 364 | `edittext_empty_text_format` | 7 | 6.0s |  |
| 365 | `edittext_focus_selection` | 5 | 6.0s |  |
| 366 | `edittext_font_size` | 45 | 5.9s |  |
| 367 | `edittext_format_empty_font` | 8 | 5.9s |  |
| 368 | `edittext_get_char_index_at_point` | 4 | 20.3s |  |
| 369 | `edittext_get_line_index_at_point` | 2 | 19.4s |  |
| 370 | `edittext_get_line_index_of_char` | 76 | 6.6s |  |
| 371 | `edittext_getcharboundaries` | 172 | 6.4s |  |
| 372 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.1s |  |
| 373 | `edittext_getcharboundaries_scroll` | 85 | 6.1s |  |
| 374 | `edittext_getlinemetrics` | 146 | 9.4s |  |
| 375 | `edittext_html` | 3101 | 9.1s |  |
| 376 | `edittext_html_condensewhite` | 487 | 8.7s |  |
| 377 | `edittext_html_entity` | 4 | 8.7s |  |
| 378 | `edittext_html_font_size_swf12` | 267 | 8.8s |  |
| 379 | `edittext_html_font_size_swf13` | 273 | 8.3s |  |
| 380 | `edittext_html_roundtrip` | 17 | 8.7s |  |
| 381 | `edittext_ime_focus_lost` | 9 | 8.9s |  |
| 382 | `edittext_input_control` | 12 | 8.6s |  |
| 383 | `edittext_leading` | 9 | 8.8s |  |
| 384 | `edittext_letter_spacing` | 15 | 8.9s |  |
| 385 | `edittext_line_methods` | 294 | 9.8s |  |
| 386 | `edittext_line_metrics` | 11 | 29.7s |  |
| 387 | `edittext_margins` | 25 | 8.9s |  |
| 388 | `edittext_max_scroll_h_basic` | 475 | 8.7s |  |
| 389 | `edittext_max_scroll_v_basic` | 1000 | 8.7s |  |
| 390 | `edittext_mouse_selection` | 363 | 29.3s |  |
| 391 | `edittext_mousedown` | 3 | 9.1s |  |
| 392 | `edittext_mouseenabled` | 26 | 8.6s |  |
| 393 | `edittext_newline_character` | 22 | 8.6s |  |
| 394 | `edittext_newline_stripping` | 64 | 15.4s |  |
| 395 | `edittext_newlines` | 30 | 8.8s |  |
| 396 | `edittext_paragraph_methods` | 257 | 8.7s |  |
| 397 | `edittext_paste_events` | 8 | 8.6s |  |
| 398 | `edittext_paste_maxchars` | 4 | 8.6s |  |
| 399 | `edittext_paste_restrict` | 16 | 8.5s |  |
| 400 | `edittext_restrict` | 191 | 8.6s |  |
| 401 | `edittext_restrict_events` | 22 | 8.6s |  |
| 402 | `edittext_scroll_event` | 37 | 8.8s |  |
| 403 | `edittext_scrollh` | 10 | 8.5s |  |
| 404 | `edittext_selected_text` | 9 | 8.5s |  |
| 405 | `edittext_set_html_same` | 17 | 8.6s |  |
| 406 | `edittext_set_text_vs_html` | 9 | 8.5s |  |
| 407 | `edittext_stylesheet` | 536 | 9.0s |  |
| 408 | `edittext_stylesheet_custom_tag` | 76 | 8.7s |  |
| 409 | `edittext_stylesheet_display` | 272 | 8.7s |  |
| 410 | `edittext_tag_indent` | 49 | 28.1s |  |
| 411 | `edittext_underline` | 40 | 9.0s |  |
| 412 | `edittext_width_height` | 103 | 8.7s |  |
| 413 | `edittext_wordwrap_word` | 150 | 8.7s |  |
| 414 | `edittext_wrap_breaks` | 2375 | 9.2s |  |
| 415 | `element_format_clone` | 44 | 8.8s |  |
| 416 | `element_format_constructor_order` | 64 | 9.4s |  |
| 417 | `element_format_properties` | 235 | 10.7s |  |
| 418 | `empty_bounds` | 1 | 9.2s |  |
| 419 | `encode_uri_surrogate_pair_invalid` | 8 | 30.1s |  |
| 420 | `encode_uri_surrogate_pair_swf11` | 15 | 8.8s |  |
| 421 | `equals` | 512 | 14.0s |  |
| 422 | `error_geterrormessage` | 779 | 9.3s |  |
| 423 | `error_prototype` | 15 | 9.3s |  |
| 424 | `error_stack_trace` | 45 | 9.3s |  |
| 425 | `error_stack_trace_debug_swf17` | 0 | 30.9s |  |
| 426 | `error_stack_trace_debug_swf18` | 0 | 9.0s |  |
| 427 | `error_stack_trace_edge_cases` | 6 | 9.2s |  |
| 428 | `error_stack_trace_release_swf17` | 0 | 3.5s |  |
| 429 | `error_stack_trace_release_swf18` | 0 | 8.9s |  |
| 430 | `error_throwerror` | 103 | 9.4s |  |
| 431 | `error_tostring` | 29 | 9.1s |  |
| 432 | `error_tostring_more` | 86 | 9.2s |  |
| 433 | `es3_inheritance` | 31 | 9.2s |  |
| 434 | `es4_inheritance` | 30 | 9.3s |  |
| 435 | `es4_interfaces` | 30 | 9.2s |  |
| 436 | `es4_method_binding` | 8 | 9.3s |  |
| 437 | `es4_oop_prototypes` | 14 | 9.5s |  |
| 438 | `es4_protected_inheritance` | 6 | 9.3s |  |
| 439 | `escape` | 71 | 9.4s |  |
| 440 | `escape_multi_byte` | 45 | 9.7s |  |
| 441 | `event_bubbles` | 2 | 9.2s |  |
| 442 | `event_cancelable` | 2 | 9.1s |  |
| 443 | `event_clone` | 20 | 9.2s |  |
| 444 | `event_clone_error_redispatch` | 3 | 9.4s |  |
| 445 | `event_clone_on_redispatch` | 10 | 9.4s |  |
| 446 | `event_formattostring` | 31 | 9.4s |  |
| 447 | `event_isdefaultprevented` | 12 | 9.3s |  |
| 448 | `event_target_getter` | 5 | 3.6s |  |
| 449 | `event_target_set` | 9 | 9.0s |  |
| 450 | `event_type` | 1 | 9.0s |  |
| 451 | `event_valueof_tostring` | 18 | 9.1s |  |
| 452 | `eventdispatcher_dispatchevent` | 12 | 9.1s |  |
| 453 | `eventdispatcher_dispatchevent_cancel` | 20 | 9.1s |  |
| 454 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 9.0s |  |
| 455 | `eventdispatcher_dispatchevent_indirect` | 9 | 9.1s |  |
| 456 | `eventdispatcher_dispatchevent_this` | 5 | 8.5s |  |
| 457 | `eventdispatcher_haseventlistener` | 25 | 8.5s |  |
| 458 | `eventdispatcher_interface_invoke` | 1 | 8.5s |  |
| 459 | `eventdispatcher_tostring` | 10 | 8.5s |  |
| 460 | `eventdispatcher_willtrigger` | 25 | 8.5s |  |
| 461 | `falsiness` | 30 | 8.5s |  |
| 462 | `fast_index_access` | 12 | 8.5s |  |
| 463 | `filefilter_properties` | 4 | 8.5s |  |
| 464 | `filereference_browse_cancel` | 3 | 8.4s |  |
| 465 | `filereference_browse_select` | 9 | 8.4s |  |
| 466 | `filereference_load` | 31 | 8.4s |  |
| 467 | `filereference_save` | 16 | 8.4s |  |
| 468 | `filereference_save_and_browse` | 42 | 8.4s |  |
| 469 | `filereference_save_and_load` | 22 | 8.4s |  |
| 470 | `filereference_uninitialized` | 8 | 8.4s |  |
| 471 | `filereferencelist_browse_cancel` | 6 | 8.4s |  |
| 472 | `filereferencelist_browse_select` | 7 | 8.4s |  |
| 473 | `filter_rewind` | 8 | 27.9s |  |
| 474 | `filters_array_holes` | 25 | 11.7s |  |
| 475 | `finddef` | 3 | 8.4s |  |
| 476 | `findprop_global_prototype` | 6 | 8.4s |  |
| 477 | `flash_media_video_constructor` | 156 | 8.5s |  |
| 478 | `flash_media_video_rotation_probe` | 27 | 8.4s |  |
| 479 | `flash_media_video_setter` | 40 | 8.5s |  |
| 480 | `flash_trace` | 17 | 8.5s |  |
| 481 | `flash_ui_mouse_cursor` | 35 | 8.7s |  |
| 482 | `flash_xml` | 29 | 8.5s |  |
| 483 | `flash_xml_cloneNode` | 22 | 8.4s |  |
| 484 | `flash_xml_namespace` | 109 | 8.5s |  |
| 485 | `flash_xml_removeNode` | 60 | 8.4s |  |
| 486 | `focus_events_code` | 161 | 27.9s |  |
| 487 | `focus_events_key_basic` | 132 | 28.0s |  |
| 488 | `focus_events_key_navigation` | 53 | 28.1s |  |
| 489 | `focus_events_key_same_object` | 26 | 8.5s |  |
| 490 | `focus_events_mixed_key_mouse` | 100 | 27.6s |  |
| 491 | `focus_events_mouse_basic` | 260 | 27.8s |  |
| 492 | `focus_events_mouse_focusable` | 112 | 27.8s |  |
| 493 | `focus_events_mouse_same_object` | 40 | 8.4s |  |
| 494 | `focus_remove` | 20 | 27.8s |  |
| 495 | `focus_root_movie` | 4 | 30.2s |  |
| 496 | `focus_stage` | 1 | 8.4s |  |
| 497 | `focusrect` | 18 | 32.9s |  |
| 498 | `focusrect_focuslost` | 9 | 8.8s |  |
| 499 | `focusrect_property` | 110 | 28.6s |  |
| 500 | `font_description_clone` | 14 | 8.8s |  |
| 501 | `font_embedded` | 24 | 29.4s |  |
| 502 | `font_enumeratefonts` | 41 | 9.5s |  |
| 503 | `font_enumeratefonts_filter` | 4 | 9.7s |  |
| 504 | `font_enumeratefonts_order` | 9 | 10.3s |  |
| 505 | `font_hasglyphs` | 40 | 9.4s |  |
| 506 | `font_registerfont` | 129 | 9.9s |  |
| 507 | `framelabel_constr` | 5 | 8.9s |  |
| 508 | `function_call` | 12 | 3.4s |  |
| 509 | `function_call_arguments` | 46 | 9.1s |  |
| 510 | `function_call_arguments_enumerate` | 5 | 8.8s |  |
| 511 | `function_call_coercion` | 108 | 9.2s |  |
| 512 | `function_call_default` | 6 | 8.8s |  |
| 513 | `function_call_rest` | 22 | 8.8s |  |
| 514 | `function_call_types` | 3 | 8.7s |  |
| 515 | `function_call_via_apply` | 11 | 8.7s |  |
| 516 | `function_call_via_call` | 3 | 8.8s |  |
| 517 | `function_display_anonymous` | 7 | 3.4s |  |
| 518 | `function_length` | 6 | 8.8s |  |
| 519 | `function_object` | 2 | 8.8s |  |
| 520 | `function_proto` | 5 | 8.8s |  |
| 521 | `function_proto_created` | 61 | 8.9s |  |
| 522 | `function_to_locale_string` | 4 | 8.8s |  |
| 523 | `function_to_string` | 4 | 8.6s |  |
| 524 | `function_type` | 6 | 8.7s |  |
| 525 | `function_unbound_this` | 51 | 8.9s |  |
| 526 | `function_value_of` | 4 | 8.8s |  |
| 527 | `game_input` | 4 | 8.8s |  |
| 528 | `generate_random_bytes` | 3 | 8.8s |  |
| 529 | `geom_transform` | 74 | 29.8s |  |
| 530 | `get_definition_by_name` | 11 | 8.8s |  |
| 531 | `get_qualified_class_name` | 20 | 8.9s |  |
| 532 | `get_qualified_super_class_name` | 18 | 8.8s |  |
| 533 | `get_slot_edge_cases` | 1 | 8.8s |  |
| 534 | `get_timer` | 2 | 3.3s |  |
| 535 | `getglobalslot` | 1 | 8.7s |  |
| 536 | `getouterscope` | 8 | 8.8s |  |
| 537 | `getouterscope_two_classobjects` | 13 | 8.8s |  |
| 538 | `getter_different_namespace_setter` | 2 | 8.7s |  |
| 539 | `glow_filter` | 127 | 7.3s |  |
| 540 | `goto_button_nested_framescript` | 28 | 23.1s |  |
| 541 | `goto_framescript_queued/swf10` | 59 | 23.1s |  |
| 542 | `goto_framescript_queued/swf9` | 52 | 1.2s |  |
| 543 | `goto_framescript_queued_same_frame` | 4 | 7.3s |  |
| 544 | `goto_in_constructframe` | 12 | 23.1s |  |
| 545 | `goto_in_scene_last_frame` | 2 | 22.9s |  |
| 546 | `goto_methods` | 56 | 7.4s |  |
| 547 | `goto_methods_swfver10` | 8 | 7.1s |  |
| 548 | `goto_nested_construct_sibling` | 18 | 7.4s |  |
| 549 | `goto_nested_framescript` | 9 | 7.2s |  |
| 550 | `goto_on_orphan` | 15 | 7.3s |  |
| 551 | `goto_queued_invalid/swf10` | 34 | 23.2s |  |
| 552 | `goto_queued_invalid/swf11` | 43 | 1.1s |  |
| 553 | `goto_queued_invalid/swf9` | 32 | 1.1s |  |
| 554 | `gradient_bevel_filter` | 206 | 7.1s |  |
| 555 | `gradient_glow_filter` | 206 | 7.0s |  |
| 556 | `graphic_linkage` | 9 | 7.2s |  |
| 557 | `graphics_bad_direct_commands` | 5 | 7.7s |  |
| 558 | `graphics_bitmap_fill` | 0 | 9.1s |  |
| 559 | `graphics_bitmaps` | 0 | 7.5s |  |
| 560 | `graphics_direct_commands` | 0 | 7.4s |  |
| 561 | `graphics_draw_triangles` | 98 | 8.0s |  |
| 562 | `graphics_gradients` | 0 | 7.3s |  |
| 563 | `graphics_gradients_nulls` | 0 | 7.2s |  |
| 564 | `graphics_path` | 56 | 7.1s |  |
| 565 | `graphics_round_rects` | 0 | 8.7s |  |
| 566 | `graphics_simple_shapes` | 0 | 7.2s |  |
| 567 | `greaterequals` | 512 | 10.3s |  |
| 568 | `greaterthan` | 512 | 10.3s |  |
| 569 | `has_own_property` | 102 | 7.5s |  |
| 570 | `hasownproperty_namespaces` | 2 | 7.0s |  |
| 571 | `hello_world` | 1 | 7.0s |  |
| 572 | `hittest_morph` | 30 | 7.2s |  |
| 573 | `id3_info` | 8 | 22.9s |  |
| 574 | `if_eq` | 10 | 7.1s |  |
| 575 | `if_gt` | 1 | 7.1s |  |
| 576 | `if_gte` | 10 | 2.8s |  |
| 577 | `if_lt` | 1 | 8.8s |  |
| 578 | `if_lte` | 10 | 8.7s |  |
| 579 | `if_ne` | 7 | 3.3s |  |
| 580 | `if_stricteq` | 6 | 8.7s |  |
| 581 | `if_strictne` | 11 | 8.7s |  |
| 582 | `ime_linux_dead_keys` | 10 | 28.4s |  |
| 583 | `in` | 102 | 9.3s |  |
| 584 | `inclocal` | 46 | 8.7s |  |
| 585 | `inclocal_i` | 46 | 8.8s |  |
| 586 | `increment` | 46 | 8.7s |  |
| 587 | `increment_i` | 46 | 8.7s |  |
| 588 | `indexing_delete` | 75 | 8.7s |  |
| 589 | `indexof_xml` | 10 | 8.8s |  |
| 590 | `init_callee_cached` | 24 | 8.7s |  |
| 591 | `instanceof` | 58 | 9.2s |  |
| 592 | `instantiate_root_character` | 4 | 9.0s |  |
| 593 | `instantiation_on_enter_frame` | 7 | 28.6s |  |
| 594 | `instantiation_on_enterframe_gotoandstop` | 8 | 8.7s |  |
| 595 | `int_constr` | 92 | 8.9s |  |
| 596 | `int_edge_cases` | 19 | 8.8s |  |
| 597 | `int_instanceof` | 3 | 8.6s |  |
| 598 | `int_tofixed` | 1215 | 8.6s |  |
| 599 | `int_toprecision` | 1125 | 8.9s |  |
| 600 | `int_tostring` | 3375 | 9.0s |  |
| 601 | `interactiveobject_enabled` | 25 | 8.7s |  |
| 602 | `interface_namespaces` | 78 | 8.9s |  |
| 603 | `invalid_utf8` | 12 | 8.8s |  |
| 604 | `is_finite` | 46 | 8.8s |  |
| 605 | `is_nan` | 46 | 8.6s |  |
| 606 | `is_prototype_of` | 12 | 8.7s |  |
| 607 | `issue_10221` | 2 | 8.6s |  |
| 608 | `issue_13780` | 12 | 8.7s |  |
| 609 | `issue_14901` | 1 | 8.6s |  |
| 610 | `issue_17675_edittext_paste_maxchars` | 1 | 8.7s |  |
| 611 | `issue_5292` | 5 | 8.8s |  |
| 612 | `issue_8630` | 2 | 8.7s |  |
| 613 | `issue_8630_placeremoveplace` | 15 | 8.9s |  |
| 614 | `issue_8630_placeremoveplace_scriptremove` | 16 | 8.7s |  |
| 615 | `issue_8630_scriptremove` | 11 | 8.7s |  |
| 616 | `istype` | 24 | 3.4s |  |
| 617 | `istypelate` | 58 | 9.1s |  |
| 618 | `istypelate_coerce` | 198 | 10.0s |  |
| 619 | `jpeg_loader_context` | 6 | 5.6s |  |
| 620 | `json_errors` | 9 | 18.4s |  |
| 621 | `json_parse` | 21 | 5.9s |  |
| 622 | `json_parse_errors` | 84 | 5.8s |  |
| 623 | `json_stringify` | 12 | 5.8s |  |
| 624 | `json_stringify_function` | 12 | 5.7s |  |
| 625 | `json_stringify_order` | 1 | 5.7s |  |
| 626 | `json_version_gated` | 1 | 6.0s |  |
| 627 | `key_input_80percent` | 1812 | 6.0s |  |
| 628 | `key_input_location` | 126 | 6.0s |  |
| 629 | `key_input_numpad` | 384 | 5.9s |  |
| 630 | `large_preload_from_bytes` | 51 | 8.3s |  |
| 631 | `large_preload_from_url` | 27 | 7.3s |  |
| 632 | `large_preload_image_from_bytes` | 25 | 6.2s |  |
| 633 | `lazyinit` | 17 | 5.8s |  |
| 634 | `lessequals` | 512 | 8.1s |  |
| 635 | `lessthan` | 512 | 7.7s |  |
| 636 | `loader_bitmap_transparency` | 14 | 5.7s |  |
| 637 | `loader_bytes_unknown_content` | 14 | 5.8s |  |
| 638 | `loader_child_getdefinition` | 5 | 6.3s |  |
| 639 | `loader_duplicate_class` | 48 | 7.4s |  |
| 640 | `loader_duplicate_coerce` | 3 | 6.1s |  |
| 641 | `loader_duplicate_coerce_new_domain` | 4 | 5.8s |  |
| 642 | `loader_error_in_root_ctor` | 4 | 6.0s |  |
| 643 | `loader_events` | 92 | 6.5s |  |
| 644 | `loader_image` | 8 | 6.1s |  |
| 645 | `loader_jpegxr` | 2 | 18.6s |  |
| 646 | `loader_jpegxr_alpha` | 1 | 6.1s |  |
| 647 | `loader_loadbytes_events` | 30 | 6.5s |  |
| 648 | `loader_loadbytes_invalid_png` | 4 | 6.0s |  |
| 649 | `loader_loadbytes_url` | 12 | 6.0s |  |
| 650 | `loader_loaderurl` | 6 | 6.6s |  |
| 651 | `loader_method` | 85 | 5.9s |  |
| 652 | `loader_noninteractive_try_click_root` | 5 | 18.6s |  |
| 653 | `loader_reuse` | 38 | 6.0s |  |
| 654 | `loader_try_click_root` | 16 | 5.9s |  |
| 655 | `loader_unknown_content` | 24 | 5.8s |  |
| 656 | `loader_visibility_interactive` | 1 | 5.8s |  |
| 657 | `loaderinfo_events` | 7 | 5.8s |  |
| 658 | `loaderinfo_loadurl` | 12 | 32.6s |  |
| 659 | `loaderinfo_more` | 6 | 29.2s |  |
| 660 | `loaderinfo_properties` | 18 | 28.5s |  |
| 661 | `loaderinfo_properties_not_loaded` | 23 | 8.9s |  |
| 662 | `loaderinfo_quine` | 1005 | 8.8s |  |
| 663 | `loaderinfo_root` | 10 | 8.8s |  |
| 664 | `loaderinfo_root_allows` | 2 | 8.7s |  |
| 665 | `localconnection` | 890 | 11.6s |  |
| 666 | `localconnection_send` | 4 | 8.8s |  |
| 667 | `lshift` | 1058 | 20.1s |  |
| 668 | `mask_reapply` | 1 | 28.9s |  |
| 669 | `math` | 497 | 9.1s |  |
| 670 | `matrix` | 338 | 21.2s |  |
| 671 | `matrix3d` | 57 | 9.7s |  |
| 672 | `matrix3d_append` | 16 | 8.8s |  |
| 673 | `matrix3d_append_prepend_scale` | 86 | 8.7s |  |
| 674 | `matrix3d_append_prepend_translation` | 42 | 8.6s |  |
| 675 | `matrix3d_append_rotation` | 23 | 8.8s |  |
| 676 | `matrix3d_compose` | 34 | 9.0s |  |
| 677 | `matrix3d_constructor_clone` | 15 | 8.7s |  |
| 678 | `matrix3d_copy_column` | 83 | 8.9s |  |
| 679 | `matrix3d_copy_from` | 19 | 8.6s |  |
| 680 | `matrix3d_copy_raw_data_from` | 55 | 3.5s |  |
| 681 | `matrix3d_copy_raw_data_to` | 38 | 8.8s |  |
| 682 | `matrix3d_copy_row` | 83 | 8.5s |  |
| 683 | `matrix3d_copy_to_matrix3d` | 19 | 8.6s |  |
| 684 | `matrix3d_determinant` | 182 | 8.8s |  |
| 685 | `matrix3d_interpolate` | 21 | 8.8s |  |
| 686 | `matrix3d_invert` | 18 | 8.6s |  |
| 687 | `matrix3d_position` | 19 | 8.8s |  |
| 688 | `matrix3d_precision` | 28 | 9.0s |  |
| 689 | `matrix3d_prepend` | 16 | 8.7s |  |
| 690 | `matrix3d_raw_data` | 33 | 9.0s |  |
| 691 | `matrix3d_transform_vector` | 52 | 9.2s |  |
| 692 | `matrix3d_transpose` | 5 | 8.7s |  |
| 693 | `method_association` | 5 | 8.7s |  |
| 694 | `method_without_body` | 3 | 28.2s |  |
| 695 | `missing_external_interface` | 10 | 8.6s |  |
| 696 | `modulo` | 1058 | 19.5s |  |
| 697 | `morph_shape` | 2 | 27.9s |  |
| 698 | `mouse_children` | 192 | 28.6s |  |
| 699 | `mouse_click_events` | 90 | 28.4s |  |
| 700 | `mouse_double_click_events` | 188 | 26.6s |  |
| 701 | `mouse_empty_parent` | 4 | 23.3s |  |
| 702 | `mouse_over_while_dragging` | 3 | 23.6s |  |
| 703 | `mouse_pick_avm1_root` | 2 | 23.7s |  |
| 704 | `mouse_pick_button_mode` | 2 | 7.2s |  |
| 705 | `mouse_pick_dobj_mask` | 4 | 7.5s |  |
| 706 | `mouse_pick_masking` | 7 | 23.4s |  |
| 707 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 23.1s |  |
| 708 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.3s |  |
| 709 | `mouse_pick_text` | 8 | 7.2s |  |
| 710 | `mouse_sibling` | 8 | 7.4s |  |
| 711 | `mouse_wheel_events` | 36 | 24.0s |  |
| 712 | `mouseevent_constr` | 66 | 7.2s |  |
| 713 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 714 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 715 | `movieclip_addframescript` | 3 | 23.3s |  |
| 716 | `movieclip_addframescript_error` | 9 | 7.4s |  |
| 717 | `movieclip_child_property` | 16 | 7.3s |  |
| 718 | `movieclip_constr` | 21 | 7.3s |  |
| 719 | `movieclip_currentlabels` | 17 | 23.3s |  |
| 720 | `movieclip_currentlabels_dupes1` | 46 | 23.5s |  |
| 721 | `movieclip_currentlabels_dupes2` | 30 | 7.2s |  |
| 722 | `movieclip_currentlabels_dupes3` | 67 | 7.2s |  |
| 723 | `movieclip_currentscene` | 12 | 23.5s |  |
| 724 | `movieclip_dispatchevent` | 430 | 7.3s |  |
| 725 | `movieclip_dispatchevent_cancel` | 102 | 7.3s |  |
| 726 | `movieclip_dispatchevent_handlerorder` | 251 | 7.2s |  |
| 727 | `movieclip_dispatchevent_selfadd` | 80 | 7.2s |  |
| 728 | `movieclip_dispatchevent_target` | 899 | 7.3s |  |
| 729 | `movieclip_displayevents` | 96 | 23.4s |  |
| 730 | `movieclip_displayevents_clickgoto` | 676 | 23.5s |  |
| 731 | `movieclip_displayevents_clickgoto2` | 2001 | 7.8s |  |
| 732 | `movieclip_displayevents_clickplay` | 575 | 7.4s |  |
| 733 | `movieclip_displayevents_clicksymbol` | 562 | 7.4s |  |
| 734 | `movieclip_displayevents_constructframegoto` | 140 | 7.5s |  |
| 735 | `movieclip_displayevents_constructframeplay` | 50 | 7.5s |  |
| 736 | `movieclip_displayevents_constructframesymbol` | 144 | 7.4s |  |
| 737 | `movieclip_displayevents_dblhandler` | 21 | 7.1s |  |
| 738 | `movieclip_displayevents_enterframegoto` | 149 | 7.4s |  |
| 739 | `movieclip_displayevents_enterframeplay` | 48 | 9.6s |  |
| 740 | `movieclip_displayevents_enterframesymbol` | 149 | 29.8s |  |
| 741 | `movieclip_displayevents_exitframegoto` | 106 | 9.6s |  |
| 742 | `movieclip_displayevents_exitframeplay` | 44 | 9.3s |  |
| 743 | `movieclip_displayevents_exitframesymbol` | 135 | 29.8s |  |
| 744 | `movieclip_displayevents_looping` | 63 | 30.2s |  |
| 745 | `movieclip_displayevents_stopped` | 113 | 9.8s |  |
| 746 | `movieclip_displayevents_swap` | 96 | 9.4s |  |
| 747 | `movieclip_displayevents_timeline` | 128 | 30.3s |  |
| 748 | `movieclip_drawrect` | 54 | 9.2s |  |
| 749 | `movieclip_frameconstruct_skipped` | 9 | 9.1s |  |
| 750 | `movieclip_goto_during_frame_script` | 15 | 9.2s |  |
| 751 | `movieclip_goto_overwrite` | 14 | 29.8s |  |
| 752 | `movieclip_goto_scene_last_frame_int` | 1 | 29.6s |  |
| 753 | `movieclip_goto_scene_last_frame_label` | 1 | 9.0s |  |
| 754 | `movieclip_gotoandplay` | 15 | 29.6s |  |
| 755 | `movieclip_gotoandstop` | 13 | 9.0s |  |
| 756 | `movieclip_gotoandstop_children` | 4 | 9.1s |  |
| 757 | `movieclip_gotoandstop_framescripts1` | 4 | 9.1s |  |
| 758 | `movieclip_gotoandstop_framescripts2` | 4 | 3.4s |  |
| 759 | `movieclip_gotoandstop_framescripts_self` | 7 | 29.1s |  |
| 760 | `movieclip_gotoandstop_queueing` | 12 | 9.2s |  |
| 761 | `movieclip_hittest` | 67 | 9.3s |  |
| 762 | `movieclip_next_frame` | 2 | 9.0s |  |
| 763 | `movieclip_next_scene` | 6 | 9.1s |  |
| 764 | `movieclip_play` | 3 | 8.9s |  |
| 765 | `movieclip_prev_frame` | 3 | 8.8s |  |
| 766 | `movieclip_prev_scene` | 7 | 9.1s |  |
| 767 | `movieclip_properties` | 79 | 29.5s |  |
| 768 | `movieclip_queued_noop_goto_swf10` | 9 | 9.1s |  |
| 769 | `movieclip_queued_noop_goto_swf9` | 7 | 1.4s |  |
| 770 | `movieclip_scenes` | 11 | 3.5s |  |
| 771 | `movieclip_soundtransform` | 831 | 31.5s |  |
| 772 | `movieclip_stop` | 1 | 9.1s |  |
| 773 | `movieclip_super_is_symbol` | 20 | 9.4s |  |
| 774 | `movieclip_symbol_constr` | 8 | 9.1s |  |
| 775 | `movieclip_text_mousedown` | 1 | 9.0s |  |
| 776 | `movieclip_willtrigger` | 5 | 9.0s |  |
| 777 | `multiply` | 1058 | 19.2s |  |
| 778 | `namespace_constr` | 253 | 9.2s |  |
| 779 | `namespace_constr_args` | 1 | 8.8s |  |
| 780 | `namespace_enumeration_order` | 7 | 8.9s |  |
| 781 | `nan_scale` | 9 | 8.9s |  |
| 782 | `native_menu_basic` | 19 | 27.6s |  |
| 783 | `navigateToURL_target_normalize` | 107 | 25.9s |  |
| 784 | `negate` | 30 | 8.8s |  |
| 785 | `negative_volume_panned` | 0 | 7.2s |  |
| 786 | `nested_iteration` | 11 | 6.9s |  |
| 787 | `net_getClassByAlias` | 3 | 23.4s |  |
| 788 | `net_navigateToURL` | 57 | 7.0s |  |
| 789 | `net_stream_play_options` | 6 | 7.0s |  |
| 790 | `netconnection_close` | 55 | 7.0s |  |
| 791 | `netconnection_properties` | 78 | 7.0s |  |
| 792 | `netconnection_send_remote` | 50 | 23.8s |  |
| 793 | `netconnection_serialize_arrays` | 6 | 7.0s |  |
| 794 | `netfilterevent` | 10 | 6.9s |  |
| 795 | `netstream_client` | 10 | 7.0s |  |
| 796 | `netstream_connect` | 7 | 6.9s |  |
| 797 | `netstream_flv_date` | 4 | 7.1s |  |
| 798 | `newactivation_in_script_init` | 3 | 6.9s |  |
| 799 | `newclass_mismatched` | 4 | 6.9s |  |
| 800 | `newclass_twice` | 3 | 6.8s |  |
| 801 | `nonconflicting_declarations` | 0 | 6.9s |  |
| 802 | `null_void_types` | 8 | 6.9s |  |
| 803 | `number_autoconv` | 21 | 6.9s |  |
| 804 | `number_autoconv_amf` | 132 | 6.9s |  |
| 805 | `number_autoconv_array_sort_32bit` | 1 | 6.9s |  |
| 806 | `number_constr` | 58 | 7.0s |  |
| 807 | `number_convert_edge_cases` | 180 | 23.5s |  |
| 808 | `number_toexponential` | 378 | 7.1s |  |
| 809 | `number_toexponential2` | 35 | 6.9s |  |
| 810 | `number_tofixed` | 378 | 6.8s |  |
| 811 | `number_toprecision` | 350 | 7.0s |  |
| 812 | `obfuscated_class_names` | 3 | 6.9s |  |
| 813 | `object_enumeration` | 10 | 6.9s |  |
| 814 | `object_prototype` | 4 | 7.0s |  |
| 815 | `object_to_locale_string` | 2 | 6.9s |  |
| 816 | `object_to_string` | 2 | 6.8s |  |
| 817 | `object_value_of` | 2 | 2.3s |  |
| 818 | `op_coerce` | 54 | 7.0s |  |
| 819 | `op_coerce_x` | 54 | 33.3s |  |
| 820 | `op_escxattr` | 2 | 28.8s |  |
| 821 | `op_escxelem` | 2 | 8.8s |  |
| 822 | `op_lookupswitch` | 4 | 8.9s |  |
| 823 | `optimize_coerce` | 1 | 8.8s |  |
| 824 | `orphan_movie_complex` | 80 | 9.6s |  |
| 825 | `orphan_movie_reorder` | 111 | 29.6s |  |
| 826 | `orphan_removeobject` | 636 | 30.0s |  |
| 827 | `package_namespace` | 7 | 8.8s |  |
| 828 | `param_default_value_has_zero_cpool_index` | 1 | 8.9s |  |
| 829 | `parent_early_access_child` | 16 | 29.1s |  |
| 830 | `parse_float` | 81 | 9.2s |  |
| 831 | `parse_float_swf10` | 81 | 8.8s |  |
| 832 | `parse_int` | 135 | 9.4s |  |
| 833 | `perspective_projection` | 1443 | 29.3s |  |
| 834 | `perspective_projection_basic` | 40 | 9.0s |  |
| 835 | `pixelbender_ceil` | 77 | 9.2s |  |
| 836 | `pixelbender_conditional` | 138 | 9.4s |  |
| 837 | `pixelbender_conversions` | 270 | 9.3s |  |
| 838 | `pixelbender_dithering` | 8 | 38.6s |  |
| 839 | `pixelbender_div` | 36 | 9.2s |  |
| 840 | `pixelbender_effect_BlurredFocus` | 0 | 37.6s |  |
| 841 | `pixelbender_effect_glassDisplace` | 0 | 15.8s |  |
| 842 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 36.1s |  |
| 843 | `pixelbender_effect_smudge` | 0 | 13.9s |  |
| 844 | `pixelbender_effect_tintype` | 0 | 13.0s |  |
| 845 | `pixelbender_effect_twirl` | 0 | 15.0s |  |
| 846 | `pixelbender_eof` | 7 | 9.8s |  |
| 847 | `pixelbender_images` | 0 | 12.6s |  |
| 848 | `pixelbender_input` | 103 | 34.8s |  |
| 849 | `pixelbender_logicalnot` | 20 | 9.2s |  |
| 850 | `pixelbender_malformed_data` | 190 | 31.2s |  |
| 851 | `pixelbender_multiple_out_params` | 1 | 9.1s |  |
| 852 | `pixelbender_no_out_param` | 6 | 9.1s |  |
| 853 | `pixelbender_outputs` | 13 | 9.4s |  |
| 854 | `pixelbender_padding_bytes` | 22 | 9.2s |  |
| 855 | `pixelbender_param_qualifier` | 512 | 9.3s |  |
| 856 | `pixelbender_parameters` | 1563 | 9.7s |  |
| 857 | `pixelbender_parameters_bool` | 240 | 9.6s |  |
| 858 | `pixelbender_parameters_int_vs_bool` | 54 | 9.3s |  |
| 859 | `pixelbender_parse_errors` | 6 | 9.1s |  |
| 860 | `pixelbender_rsqrt` | 24 | 9.3s |  |
| 861 | `pixelbender_select_kinds` | 8 | 9.4s |  |
| 862 | `pixelbender_shaderdata` | 49 | 36.2s |  |
| 863 | `pixelbender_shaderdata_setter` | 99 | 28.7s |  |
| 864 | `pixelbender_sign` | 60 | 8.9s |  |
| 865 | `pixelbender_vector_output` | 11 | 9.0s |  |
| 866 | `place_and_lookup/swf10` | 33 | 8.7s |  |
| 867 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 868 | `place_multiple` | 17 | 8.8s |  |
| 869 | `place_object_replace` | 9 | 28.5s |  |
| 870 | `place_object_replace_2` | 24 | 28.8s |  |
| 871 | `place_object_same_depth_frame` | 1 | 8.9s |  |
| 872 | `point` | 132 | 9.3s |  |
| 873 | `primitive_edge_cases` | 1 | 8.7s |  |
| 874 | `primitive_keys` | 54 | 8.8s |  |
| 875 | `primitive_toString` | 277 | 8.9s |  |
| 876 | `primitive_valueOf` | 285 | 8.5s |  |
| 877 | `print_job_options` | 3 | 8.6s |  |
| 878 | `property_is_enumerable` | 114 | 9.8s |  |
| 879 | `property_is_enumerable_reset` | 23 | 8.6s |  |
| 880 | `property_priority` | 22 | 8.9s |  |
| 881 | `property_priority_chained` | 4 | 8.6s |  |
| 882 | `property_priority_definition_names_order` | 2 | 8.8s |  |
| 883 | `property_priority_three_level` | 6 | 8.7s |  |
| 884 | `propertyisenumerable_namespaces` | 6 | 8.6s |  |
| 885 | `prototype_set_null` | 7 | 8.6s |  |
| 886 | `proxy_callproperty` | 24 | 8.7s |  |
| 887 | `proxy_deleteproperty` | 64 | 8.7s |  |
| 888 | `proxy_enumeration` | 34 | 8.7s |  |
| 889 | `proxy_getproperty` | 77 | 8.7s |  |
| 890 | `proxy_hasownproperty` | 8 | 8.6s |  |
| 891 | `proxy_hasproperty` | 32 | 8.7s |  |
| 892 | `proxy_not_overridden` | 54 | 8.6s |  |
| 893 | `proxy_serialize` | 9 | 8.7s |  |
| 894 | `proxy_setproperty` | 42 | 8.7s |  |
| 895 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.5s |  |
| 896 | `qname_constr` | 32 | 8.7s |  |
| 897 | `qname_constr_namespace` | 24 | 8.7s |  |
| 898 | `qname_enumeration` | 9 | 8.7s |  |
| 899 | `qname_indexing` | 23 | 8.9s |  |
| 900 | `qname_tostring` | 25 | 8.8s |  |
| 901 | `qname_valueof` | 29 | 8.8s |  |
| 902 | `rectangle` | 1094 | 9.5s |  |
| 903 | `regexp_constr` | 148 | 9.0s |  |
| 904 | `regexp_exec` | 19 | 8.7s |  |
| 905 | `regexp_extended` | 47 | 8.8s |  |
| 906 | `regexp_multiargs` | 1 | 8.8s |  |
| 907 | `regexp_test` | 27 | 8.9s |  |
| 908 | `regexp_toString` | 10 | 8.7s |  |
| 909 | `register_script_refresh` | 35 | 9.4s |  |
| 910 | `remove_child_clear_field` | 88 | 9.2s |  |
| 911 | `remove_dobj` | 3 | 8.7s |  |
| 912 | `resolve_order` | 4 | 8.8s |  |
| 913 | `responder_null_callbacks` | 1 | 8.7s |  |
| 914 | `rng` | 1 | 4.4s |  |
| 915 | `rootless` | 42 | 8.8s |  |
| 916 | `rshift` | 1058 | 18.2s |  |
| 917 | `rtqname_not_namespace` | 12 | 8.8s |  |
| 918 | `sandbox_type_inherited` | 2 | 9.2s |  |
| 919 | `sandbox_type_local_file` | 1 | 8.8s |  |
| 920 | `sandbox_type_local_network` | 1 | 8.6s |  |
| 921 | `scene_constr` | 8 | 8.9s |  |
| 922 | `scope_optimizations` | 4 | 9.0s |  |
| 923 | `scopes_dont_cache/order-1` | 1 | 30.5s |  |
| 924 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 925 | `security_domain_current` | 2 | 9.0s |  |
| 926 | `selection` | 239 | 9.8s |  |
| 927 | `set_local_0` | 31 | 9.0s |  |
| 928 | `set_property_is_enumerable` | 85 | 9.4s |  |
| 929 | `shaderparameter_value` | 4 | 8.9s |  |
| 930 | `shape_drawrect` | 54 | 9.1s |  |
| 931 | `shared_object_no_root` | 3 | 8.9s |  |
| 932 | `simplebutton_added_to_stage` | 45 | 30.6s |  |
| 933 | `simplebutton_childevents` | 86 | 30.9s |  |
| 934 | `simplebutton_childevents_nested` | 54 | 9.5s |  |
| 935 | `simplebutton_childevents_sprite` | 13 | 9.2s |  |
| 936 | `simplebutton_childprops` | 144 | 9.2s |  |
| 937 | `simplebutton_childshuffle` | 23 | 8.9s |  |
| 938 | `simplebutton_constr` | 36 | 9.3s |  |
| 939 | `simplebutton_constr_childevents` | 48 | 9.4s |  |
| 940 | `simplebutton_constr_params` | 42 | 9.1s |  |
| 941 | `simplebutton_mouseenabled` | 26 | 9.0s |  |
| 942 | `simplebutton_multi_children` | 19 | 9.1s |  |
| 943 | `simplebutton_soundtransform` | 887 | 32.3s |  |
| 944 | `simplebutton_structure` | 27 | 29.0s |  |
| 945 | `simplebutton_symbolclass` | 68 | 9.2s |  |
| 946 | `slot_disp_id_shared_numbering` | 1 | 28.4s |  |
| 947 | `slots_force_autoassigned` | 1 | 8.7s |  |
| 948 | `socket_after_disconnect` | 1 | 8.8s |  |
| 949 | `socket_close` | 2 | 8.6s |  |
| 950 | `socket_connect` | 4 | 8.7s |  |
| 951 | `socket_errors` | 56 | 9.2s |  |
| 952 | `socket_read_big` | 48 | 8.7s |  |
| 953 | `socket_read_little` | 48 | 3.1s |  |
| 954 | `socket_read_write_object` | 8 | 8.7s |  |
| 955 | `socket_write_big` | 15 | 9.0s |  |
| 956 | `socket_write_little` | 14 | 8.6s |  |
| 957 | `sound_constructor_with_args` | 6 | 8.9s |  |
| 958 | `sound_embeddedprops` | 26 | 8.9s |  |
| 959 | `sound_load_multiple` | 19 | 9.8s |  |
| 960 | `sound_play` | 19 | 9.0s |  |
| 961 | `sound_rootless` | 7 | 8.7s |  |
| 962 | `sound_valueof` | 33 | 8.9s |  |
| 963 | `soundchannel_soundtransform` | 835 | 30.7s |  |
| 964 | `soundchannel_soundtransform_exists` | 5 | 28.2s |  |
| 965 | `soundchannel_stop` | 8 | 28.3s |  |
| 966 | `soundmixer_buffertime` | 5 | 8.7s |  |
| 967 | `soundmixer_soundtransform` | 900 | 11.0s |  |
| 968 | `soundmixer_stopall` | 6 | 8.8s |  |
| 969 | `soundtransform` | 442 | 14.9s |  |
| 970 | `space_justifier_clone` | 12 | 8.8s |  |
| 971 | `sprite_with_frames` | 0 | 9.7s |  |
| 972 | `stage3d_agal_cross_product` | 0 | 12.3s |  |
| 973 | `stage3d_agal_upload_errors` | 66 | 14.1s |  |
| 974 | `stage3d_bitmap` | 0 | 34.9s |  |
| 975 | `stage3d_blend` | 81 | 32.8s |  |
| 976 | `stage3d_context3d_string_args` | 158 | 10.1s |  |
| 977 | `stage3d_errors` | 7 | 8.7s |  |
| 978 | `stage3d_errors_atf` | 3 | 10.2s |  |
| 979 | `stage3d_errors_swf_29` | 6 | 8.8s |  |
| 980 | `stage3d_float1_index` | 0 | 31.2s |  |
| 981 | `stage3d_fractal` | 0 | 32.5s |  |
| 982 | `stage3d_ignore_sampler_override` | 0 | 32.5s |  |
| 983 | `stage3d_multistage_triangle` | 3 | 25.9s |  |
| 984 | `stage3d_program_constants_bytearray_be` | 0 | 29.2s |  |
| 985 | `stage3d_program_constants_bytearray_le` | 0 | 10.3s |  |
| 986 | `stage3d_program_constants_invalid_input` | 21 | 25.6s |  |
| 987 | `stage3d_raytrace` | 0 | 32.0s |  |
| 988 | `stage3d_rotating_cube` | 0 | 10.1s |  |
| 989 | `stage3d_sampler` | 0 | 9.6s |  |
| 990 | `stage3d_sampler_partial_upload` | 0 | 9.5s |  |
| 991 | `stage3d_stencil` | 0 | 26.1s |  |
| 992 | `stage3d_texture` | 0 | 14.7s |  |
| 993 | `stage3d_texture_bytearray` | 0 | 10.9s |  |
| 994 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.5s |  |
| 995 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.3s |  |
| 996 | `stage3d_triangle` | 0 | 9.8s |  |
| 997 | `stage3d_triangle_bytes4` | 0 | 9.7s |  |
| 998 | `stage3d_triangle_float1` | 0 | 9.8s |  |
| 999 | `stage3d_triangle_index_upload` | 0 | 9.8s |  |
| 1000 | `stage3d_x_y` | 22 | 7.2s |  |
| 1001 | `stage_access` | 10 | 7.3s |  |
| 1002 | `stage_display_state` | 6 | 7.5s |  |
| 1003 | `stage_displayobject_properties` | 24 | 7.3s |  |
| 1004 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.2s |  |
| 1005 | `stage_framerate_nan` | 7 | 7.3s |  |
| 1006 | `stage_framerate_negative` | 6 | 7.0s |  |
| 1007 | `stage_framerate_zero` | 6 | 7.2s |  |
| 1008 | `stage_invalidate` | 38 | 7.5s |  |
| 1009 | `stage_loaderinfo_properties` | 24 | 23.6s |  |
| 1010 | `stage_mousechildren` | 2 | 7.3s |  |
| 1011 | `stage_mouseenabled` | 15 | 7.3s |  |
| 1012 | `stage_overriden_setters` | 31 | 7.3s |  |
| 1013 | `stage_properties` | 30 | 7.2s |  |
| 1014 | `stage_properties2` | 213 | 7.4s |  |
| 1015 | `stage_scale_factor` | 12 | 27.3s |  |
| 1016 | `stage_stage3Ds_vector` | 1 | 7.0s |  |
| 1017 | `static_length` | 24 | 7.1s |  |
| 1018 | `static_text` | 3 | 7.3s |  |
| 1019 | `static_var_with_this_in_ctor` | 2 | 7.0s |  |
| 1020 | `statictext_text` | 8 | 7.1s |  |
| 1021 | `stored_properties` | 11 | 7.1s |  |
| 1022 | `strict_equality` | 34 | 7.2s |  |
| 1023 | `string_call` | 13 | 7.2s |  |
| 1024 | `string_case` | 23 | 7.3s |  |
| 1025 | `string_char_at` | 27 | 26.5s |  |
| 1026 | `string_char_code_at` | 28 | 6.8s |  |
| 1027 | `string_concat_fromcharcode` | 37 | 22.8s |  |
| 1028 | `string_constr` | 25 | 7.1s |  |
| 1029 | `string_indexof_lastindexof` | 87 | 7.2s |  |
| 1030 | `string_length` | 16 | 7.1s |  |
| 1031 | `string_locale_compare` | 39 | 7.3s |  |
| 1032 | `string_match` | 51 | 7.6s |  |
| 1033 | `string_relational_compare` | 4 | 7.3s |  |
| 1034 | `string_replace` | 51 | 7.8s |  |
| 1035 | `string_search` | 41 | 7.2s |  |
| 1036 | `string_slice_substr_substring` | 170 | 7.9s |  |
| 1037 | `string_split` | 29 | 7.2s |  |
| 1038 | `string_substr_negative` | 21 | 7.0s |  |
| 1039 | `string_substr_weird` | 182 | 7.2s |  |
| 1040 | `stylesheet` | 221 | 7.7s |  |
| 1041 | `stylesheet_parse_color` | 69 | 7.3s |  |
| 1042 | `stylesheet_transform` | 307 | 7.4s |  |
| 1043 | `sub_super_same_field` | 12 | 2.8s |  |
| 1044 | `subclass_superclass_linked_symbol` | 4 | 7.6s |  |
| 1045 | `subtract` | 1058 | 16.1s |  |
| 1046 | `super_get_call` | 12 | 7.6s |  |
| 1047 | `supercall_two_classobjects` | 2 | 7.2s |  |
| 1048 | `supercalls_coerce` | 8 | 7.2s |  |
| 1049 | `supercalls_weird` | 2 | 7.2s |  |
| 1050 | `superinterface_call` | 20 | 7.7s |  |
| 1051 | `superinterface_instanceof` | 18 | 7.8s |  |
| 1052 | `swf8` | 1 | 7.1s |  |
| 1053 | `swf_10_queued_goto_scripts_construct` | 52 | 23.1s |  |
| 1054 | `swf_9_goto_in_enter_frame` | 17 | 7.0s |  |
| 1055 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 1056 | `swf_9_queued_goto_scripts` | 6 | 22.4s |  |
| 1057 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 1058 | `swf_9_versioning` | 2 | 7.3s |  |
| 1059 | `swf_wrong_frame_count` | 38 | 7.4s |  |
| 1060 | `swf_wrong_frame_count_isplaying` | 22 | 7.0s |  |
| 1061 | `symbol_class_binary_data` | 8 | 7.1s |  |
| 1062 | `symbol_class_conflict` | 4 | 10.2s |  |
| 1063 | `symbol_class_root_not_zero` | 1 | 6.8s |  |
| 1064 | `symbolclass_invalid_utf8` | 2 | 7.0s |  |
| 1065 | `system_exit` | 3 | 7.2s |  |
| 1066 | `system_setclipboard_null` | 1 | 8.7s |  |
| 1067 | `tab_ordering_arrows` | 998 | 30.4s |  |
| 1068 | `tab_ordering_automatic_advanced` | 184 | 9.5s |  |
| 1069 | `tab_ordering_automatic_basic` | 45 | 8.7s |  |
| 1070 | `tab_ordering_children` | 116 | 9.2s |  |
| 1071 | `tab_ordering_custom_basic` | 34 | 8.9s |  |
| 1072 | `tab_ordering_properties` | 732 | 9.3s |  |
| 1073 | `tab_ordering_stage_tab_children` | 32 | 8.9s |  |
| 1074 | `tab_ordering_stage_tab_children_remove_root` | 5 | 8.9s |  |
| 1075 | `tab_ordering_tabbable` | 47 | 9.2s |  |
| 1076 | `tabstop_properties` | 105 | 9.3s |  |
| 1077 | `text_element_basic` | 34 | 9.0s |  |
| 1078 | `text_engine_fontdescription` | 27 | 9.0s |  |
| 1079 | `text_engine_groupelement` | 64 | 9.9s |  |
| 1080 | `text_run` | 7 | 8.8s |  |
| 1081 | `textblock_createline_errors` | 23 | 9.0s |  |
| 1082 | `textblock_createline_fte` | 9 | 9.0s |  |
| 1083 | `textblock_properties` | 118 | 9.5s |  |
| 1084 | `textbox_click` | 37 | 29.6s |  |
| 1085 | `textfield_event` | 66 | 9.3s |  |
| 1086 | `textfield_focusin_event` | 9 | 8.9s |  |
| 1087 | `textfield_input_dead_keys_windows` | 15 | 8.9s |  |
| 1088 | `textfield_input_events` | 25 | 25.0s |  |
| 1089 | `textfield_unload` | 39 | 29.5s |  |
| 1090 | `textformat` | 1134 | 8.8s |  |
| 1091 | `textformat_display` | 14 | 9.0s |  |
| 1092 | `textformat_font_max_length` | 4 | 8.7s |  |
| 1093 | `textjustifier_locale` | 132 | 9.0s |  |
| 1094 | `textline_has_tabs` | 47 | 8.9s |  |
| 1095 | `textline_inapplicable_properties` | 10 | 8.7s |  |
| 1096 | `textline_name` | 1 | 8.6s |  |
| 1097 | `textline_raw_text_length` | 30 | 8.7s |  |
| 1098 | `textline_splitting_basic` | 76 | 8.9s |  |
| 1099 | `textline_throwerror` | 30 | 8.7s |  |
| 1100 | `textline_validity` | 162 | 8.9s |  |
| 1101 | `throw` | 3 | 8.7s |  |
| 1102 | `timeline_scripts` | 3 | 8.8s |  |
| 1103 | `timer` | 90 | 10.3s |  |
| 1104 | `timer_events` | 3 | 6.0s |  |
| 1105 | `timer_finished` | 11 | 5.8s |  |
| 1106 | `timer_invalid_delay` | 30 | 5.7s |  |
| 1107 | `timer_reset` | 8 | 5.9s |  |
| 1108 | `timer_setdelay` | 5 | 2.3s |  |
| 1109 | `trace` | 12 | 5.6s |  |
| 1110 | `truthiness` | 30 | 5.7s |  |
| 1111 | `try_catch` | 11 | 5.9s |  |
| 1112 | `try_catch_typed` | 12 | 5.7s |  |
| 1113 | `typeof` | 30 | 5.8s |  |
| 1114 | `uint_constr` | 92 | 5.7s |  |
| 1115 | `uint_tofixed` | 1215 | 5.6s |  |
| 1116 | `uint_toprecision` | 1125 | 5.7s |  |
| 1117 | `uint_tostring` | 3375 | 5.9s |  |
| 1118 | `uncaught_error_basic` | 2 | 5.6s |  |
| 1119 | `unchecked_function` | 15 | 5.6s |  |
| 1120 | `unescape` | 28 | 5.8s |  |
| 1121 | `url_loader` | 25 | 5.8s |  |
| 1122 | `url_vars` | 27 | 5.9s |  |
| 1123 | `urlrequest` | 18 | 5.6s |  |
| 1124 | `urlstream_basic` | 5 | 5.6s |  |
| 1125 | `urshift` | 1058 | 11.7s |  |
| 1126 | `utils3d` | 7 | 2.2s |  |
| 1127 | `vector3d` | 397 | 8.3s |  |
| 1128 | `vector3d_near_equals` | 80 | 6.1s |  |
| 1129 | `vector_class` | 36 | 6.2s |  |
| 1130 | `vector_class_call` | 11 | 5.8s |  |
| 1131 | `vector_coercion` | 66 | 6.3s |  |
| 1132 | `vector_concat` | 90 | 6.3s |  |
| 1133 | `vector_constr` | 107 | 6.3s |  |
| 1134 | `vector_enumeration` | 5 | 5.8s |  |
| 1135 | `vector_every` | 92 | 6.3s |  |
| 1136 | `vector_filter` | 95 | 6.3s |  |
| 1137 | `vector_holes` | 24 | 5.8s |  |
| 1138 | `vector_indexof` | 302 | 8.3s |  |
| 1139 | `vector_insertat` | 270 | 6.4s |  |
| 1140 | `vector_int_access` | 4 | 5.7s |  |
| 1141 | `vector_int_delete` | 11 | 5.7s |  |
| 1142 | `vector_join` | 58 | 5.9s |  |
| 1143 | `vector_lastindexof` | 302 | 5.8s |  |
| 1144 | `vector_legacy` | 10 | 5.7s |  |
| 1145 | `vector_map` | 85 | 6.5s |  |
| 1146 | `vector_object_final` | 1 | 2.3s |  |
| 1147 | `vector_object_toString` | 10 | 6.1s |  |
| 1148 | `vector_pushpop` | 255 | 7.2s |  |
| 1149 | `vector_reborrow_bug` | 10 | 6.0s |  |
| 1150 | `vector_removeat` | 172 | 7.0s |  |
| 1151 | `vector_reverse` | 232 | 6.7s |  |
| 1152 | `vector_shiftunshift` | 252 | 6.1s |  |
| 1153 | `vector_slice` | 331 | 7.1s |  |
| 1154 | `vector_sort` | 905 | 12.3s |  |
| 1155 | `vector_splice` | 693 | 8.9s |  |
| 1156 | `vector_splice_fixed_bug_compat` | 4 | 6.3s |  |
| 1157 | `vector_tostring` | 79 | 6.7s |  |
| 1158 | `verification` | 8 | 6.4s |  |
| 1159 | `verify_abnormal_loop` | 1 | 6.2s |  |
| 1160 | `verify_dxns_without_flag` | 3 | 6.7s |  |
| 1161 | `verify_exception_target_two_jumps` | 1 | 6.5s |  |
| 1162 | `verify_exception_targets_edge_case` | 1 | 6.3s |  |
| 1163 | `verify_illegal_opcode` | 1 | 2.6s |  |
| 1164 | `verify_jump_to_middle_of_op` | 1 | 6.1s |  |
| 1165 | `verify_lookup_switch_edge_case` | 1 | 6.2s |  |
| 1166 | `verify_method_info_oob` | 1 | 1.0s |  |
| 1167 | `verify_stack` | 5 | 6.5s |  |
| 1168 | `verify_typecheck` | 4 | 6.5s |  |
| 1169 | `verify_unreachable_exception` | 2 | 6.3s |  |
| 1170 | `versioned_isplaying` | 2 | 6.3s |  |
| 1171 | `virtual_properties` | 16 | 6.5s |  |
| 1172 | `with` | 4 | 6.5s |  |
| 1173 | `wrong_arg_count` | 7 | 6.3s |  |
| 1174 | `xml_abstract_equality` | 36 | 6.3s |  |
| 1175 | `xml_advanced` | 52 | 6.1s |  |
| 1176 | `xml_appendchild` | 10 | 6.2s |  |
| 1177 | `xml_appendchild_swf_v21` | 13 | 6.2s |  |
| 1178 | `xml_as_attribute` | 9 | 6.0s |  |
| 1179 | `xml_attribute` | 35 | 6.1s |  |
| 1180 | `xml_attribute_name` | 40 | 6.2s |  |
| 1181 | `xml_basic` | 33 | 6.2s |  |
| 1182 | `xml_child` | 25 | 6.1s |  |
| 1183 | `xml_childindex` | 7 | 6.3s |  |
| 1184 | `xml_children` | 43 | 6.4s |  |
| 1185 | `xml_class_call` | 9 | 5.9s |  |
| 1186 | `xml_contains` | 197 | 34.8s |  |
| 1187 | `xml_copy` | 20 | 9.3s |  |
| 1188 | `xml_ctor_from_tostring` | 23 | 30.4s |  |
| 1189 | `xml_delete` | 114 | 9.3s |  |
| 1190 | `xml_descendants` | 83 | 9.3s |  |
| 1191 | `xml_duplicate_attribute` | 14 | 9.2s |  |
| 1192 | `xml_elements` | 6 | 9.2s |  |
| 1193 | `xml_equals_namespace_check` | 2 | 9.3s |  |
| 1194 | `xml_explicit_use_namespace` | 5 | 9.4s |  |
| 1195 | `xml_getdescendants_qname` | 21 | 9.3s |  |
| 1196 | `xml_has_property_via_in` | 26 | 9.2s |  |
| 1197 | `xml_hasownproperty` | 6 | 9.2s |  |
| 1198 | `xml_ignore_white` | 6 | 9.3s |  |
| 1199 | `xml_length` | 2 | 9.2s |  |
| 1200 | `xml_list_as_attribute` | 9 | 9.2s |  |
| 1201 | `xml_list_concat` | 20 | 9.3s |  |
| 1202 | `xml_list_ctor_errors` | 34 | 9.2s |  |
| 1203 | `xml_list_delete_clear_parent` | 6 | 9.1s |  |
| 1204 | `xml_list_enumerate` | 4 | 9.1s |  |
| 1205 | `xml_methods_settings` | 3 | 9.2s |  |
| 1206 | `xml_mismatched_tag` | 37 | 9.3s |  |
| 1207 | `xml_namespace` | 39 | 9.2s |  |
| 1208 | `xml_namespace_methods` | 245 | 9.3s |  |
| 1209 | `xml_namespaced_property` | 7 | 9.1s |  |
| 1210 | `xml_no_namespace` | 1 | 9.2s |  |
| 1211 | `xml_nodekind` | 3 | 9.2s |  |
| 1212 | `xml_normalize` | 35 | 9.3s |  |
| 1213 | `xml_notification_bubbling` | 361 | 9.3s |  |
| 1214 | `xml_parent` | 8 | 9.3s |  |
| 1215 | `xml_set_children` | 17 | 9.4s |  |
| 1216 | `xml_set_name` | 34 | 9.2s |  |
| 1217 | `xml_settings` | 6 | 3.6s |  |
| 1218 | `xml_simple_complex_content` | 47 | 9.3s |  |
| 1219 | `xml_socket` | 11 | 9.6s |  |
| 1220 | `xml_text` | 7 | 9.2s |  |
| 1221 | `xml_tostring` | 6 | 9.3s |  |
| 1222 | `xml_tostring_namespace` | 12 | 9.1s |  |
| 1223 | `xml_unescaping` | 23 | 9.3s |  |
| 1224 | `xml_weird_ignores` | 54 | 9.2s |  |
| 1225 | `xml_wildcard` | 11 | 9.1s |  |
| 1226 | `xmldocument` | 254 | 9.0s |  |
| 1227 | `xmlnode` | 3540 | 9.2s |  |
| 1228 | `zero_frame_clip` | 3 | 9.8s |  |

## Ruffle-Matched Tests

**41 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.3s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.0s |  |
| 3 | `blend_transform` | 1 | 1 | 8.8s |  |
| 4 | `bounds_mode` | 6 | 6 | 9.4s |  |
| 5 | `coerce_property` | 3 | 3 | 8.8s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 8.8s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 23.4s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 31.0s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 6.0s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.2s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 6.0s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 8.9s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 9.1s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 9.3s |  |
| 15 | `event_handler_exception` | 4 | 4 | 9.5s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 8.7s |  |
| 17 | `goto_framescript_queued/swf13` | 3 | 3 | 1.2s |  |
| 18 | `gradient_values_readback` | 12 | 12 | 7.4s |  |
| 19 | `graphics_draw_path` | 50 | 50 | 23.6s |  |
| 20 | `groupelement_text` | 2 | 2 | 7.3s |  |
| 21 | `int_toexponential` | 76 | 76 | 8.8s |  |
| 22 | `json_parse_numbers` | 4 | 79 | 5.8s |  |
| 23 | `loader_events_2` | 30 | 30 | 6.2s |  |
| 24 | `matrix3d_recompose_edge_cases` | 8 | 85 | 9.3s |  |
| 25 | `number_convert_errors` | 706 | 706 | 7.2s |  |
| 26 | `number_to_string` | 104 | 104 | 7.4s |  |
| 27 | `simplebutton_childevents_multichild` | 101 | 101 | 9.2s |  |
| 28 | `simplebutton_childevents_script_order` | 4 | 4 | 3.7s |  |
| 29 | `slot_holes_fail` | 1 | 1 | 8.6s |  |
| 30 | `slot_id_exceeds_trait_count` | 1 | 1 | 8.7s |  |
| 31 | `soundchannel_position` | 74 | 74 | 29.9s |  |
| 32 | `soundchannel_soundcomplete` | 10 | 10 | 9.0s |  |
| 33 | `sprite_dropTarget` | 15 | 15 | 8.8s |  |
| 34 | `swf_9_goto_in_construct_frame` | 12 | 12 | 23.0s |  |
| 35 | `textblock_line_changes` | 44 | 44 | 9.5s |  |
| 36 | `textblock_recreateline` | 137 | 138 | 9.5s |  |
| 37 | `textblock_releaselines` | 4 | 4 | 10.6s |  |
| 38 | `textline_atom_index_at_char_index` | 3 | 3 | 9.9s |  |
| 39 | `uint_toexponential` | 100 | 100 | 5.7s |  |
| 40 | `uncaught_errors_stringified` | 15 | 15 | 6.0s |  |
| 41 | `weird_superinterface_properties` | 1 | 1 | 6.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**7 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 3 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 4 | `mouse_pick_scroll_rect_button` | 60.0% | 3 | 5 | 2 |  |
| 5 | `html_text_img_parsing` | 56.3% | 338 | 600 | 262 |  |
| 6 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 7 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**22 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 3 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 4 | `mouse_pick_scroll_rect_button` | 60.0% | 3/5 | 5 | 5 |  |
| 5 | `html_text_img_parsing` | 56.3% | 338/600 | 505 | 600 |  |
| 6 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 7 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 8 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 9 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 10 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 11 | `mouse_pick_scroll_rect_loader` | 20.0% | 1/5 | 5 | 5 |  |
| 12 | `mouse_pick_scroll_rect` | 11.1% | 3/27 | 27 | 27 |  |
| 13 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 14 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 15 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 16 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 17 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 18 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 19 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 20 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 21 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 22 | `textline_metrics` | 0.0% | 0/20 | 20 | 20 |  |
