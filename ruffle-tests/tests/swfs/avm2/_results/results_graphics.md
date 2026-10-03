# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-03 20:48 UTC

**Git SHA**: `4c450f076e`

**Run Duration**: 220m 57s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1284 |
| Passing | **1222** (95.2%) |
| Ruffle-matched | 41 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1263** (98.4%) |
| Failing | 21 |
| Total expected lines | 158060 |
| Matching lines | 155359 (98.3%) |
| Mismatched lines | 2701 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 21 | 100.0% |

## Passing Tests

**1222 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 17.4s |  |
| 2 | `accessibility` | 1 | 8.6s |  |
| 3 | `accessibilityimplementation` | 18 | 8.8s |  |
| 4 | `activation_class` | 6 | 8.7s |  |
| 5 | `add` | 1058 | 20.1s |  |
| 6 | `agal_compiler` | 13 | 11.7s |  |
| 7 | `air_datagram_socket` | 1 | 10.7s |  |
| 8 | `air_hidden_lookup` | 2 | 8.7s |  |
| 9 | `air_ifilepromise` | 1 | 8.6s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 8.7s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.3s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.3s |  |
| 13 | `all_classes/display/swf10` | 2569 | 8.7s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.3s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.4s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.3s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.3s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.3s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 8.7s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.3s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.3s |  |
| 22 | `all_classes/errors/swf10` | 140 | 8.7s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.3s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.3s |  |
| 25 | `all_classes/events/swf10` | 1638 | 8.7s |  |
| 26 | `all_classes/events/swf11` | 1750 | 1.3s |  |
| 27 | `all_classes/events/swf12` | 1814 | 1.3s |  |
| 28 | `all_classes/events/swf30` | 2353 | 1.3s |  |
| 29 | `all_classes/events/swf9` | 1030 | 1.3s |  |
| 30 | `all_classes/security/swf11` | 3 | 8.7s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.3s |  |
| 32 | `all_classes/security/swf13` | 53 | 1.3s |  |
| 33 | `all_classes/security/swf30` | 53 | 1.3s |  |
| 34 | `all_classes/xml/swf30` | 116 | 8.7s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.3s |  |
| 36 | `amf_array_serialization` | 17 | 30.7s |  |
| 37 | `amf_custom_obj` | 26 | 8.8s |  |
| 38 | `amf_dictionary` | 9 | 8.6s |  |
| 39 | `amf_function` | 46 | 8.8s |  |
| 40 | `amf_invalid_date` | 2 | 8.6s |  |
| 41 | `amf_missing_prop` | 6 | 8.6s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 8.7s |  |
| 43 | `amf_setter_error` | 8 | 8.8s |  |
| 44 | `amf_vector` | 40 | 18.1s |  |
| 45 | `amf_xml` | 6 | 9.0s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 9.5s |  |
| 47 | `application_domain` | 4 | 9.0s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 9.1s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 9.0s |  |
| 50 | `array_access` | 18 | 9.1s |  |
| 51 | `array_access_interpreter` | 4 | 9.1s |  |
| 52 | `array_access_no_pubns` | 2 | 9.0s |  |
| 53 | `array_concat` | 41 | 9.0s |  |
| 54 | `array_constr` | 10 | 8.9s |  |
| 55 | `array_delete` | 44 | 9.1s |  |
| 56 | `array_enumeration` | 10 | 9.0s |  |
| 57 | `array_enumeration_elements` | 11 | 8.9s |  |
| 58 | `array_every` | 8 | 8.9s |  |
| 59 | `array_filter` | 6 | 8.9s |  |
| 60 | `array_foreach` | 18 | 8.9s |  |
| 61 | `array_hasownproperty` | 11 | 8.9s |  |
| 62 | `array_holes` | 9 | 8.8s |  |
| 63 | `array_index_max` | 84 | 8.9s |  |
| 64 | `array_indexof` | 25 | 8.9s |  |
| 65 | `array_join` | 26 | 9.0s |  |
| 66 | `array_lastindexof` | 29 | 8.9s |  |
| 67 | `array_length` | 14 | 8.9s |  |
| 68 | `array_literal` | 3 | 8.9s |  |
| 69 | `array_map` | 8 | 8.8s |  |
| 70 | `array_pop` | 52 | 9.1s |  |
| 71 | `array_push` | 24 | 8.9s |  |
| 72 | `array_reborrow_bug` | 6 | 8.9s |  |
| 73 | `array_reverse` | 28 | 8.8s |  |
| 74 | `array_shift` | 51 | 3.6s |  |
| 75 | `array_slice` | 39 | 9.1s |  |
| 76 | `array_some` | 8 | 8.9s |  |
| 77 | `array_sort` | 297 | 9.7s |  |
| 78 | `array_sort_fun_swf12` | 2 | 8.9s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 80 | `array_sort_random` | 210 | 8.9s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 8.8s |  |
| 82 | `array_sorton` | 545 | 10.0s |  |
| 83 | `array_sparse_ops` | 41 | 9.2s |  |
| 84 | `array_splice` | 133 | 9.2s |  |
| 85 | `array_splice2` | 428 | 17.3s |  |
| 86 | `array_splice_types` | 48 | 8.6s |  |
| 87 | `array_storage` | 8 | 8.5s |  |
| 88 | `array_tolocalestring` | 9 | 8.5s |  |
| 89 | `array_tostring` | 12 | 8.6s |  |
| 90 | `array_unshift` | 24 | 8.5s |  |
| 91 | `array_valueof` | 9 | 8.4s |  |
| 92 | `array_vector_null_callback` | 10 | 8.4s |  |
| 93 | `astype` | 28 | 8.6s |  |
| 94 | `astypelate` | 24 | 8.7s |  |
| 95 | `astypelate_propagates` | 1 | 8.4s |  |
| 96 | `asymmetric_key_events` | 11 | 8.6s |  |
| 97 | `automation_classes` | 122 | 8.9s |  |
| 98 | `av_classes` | 340 | 8.8s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 8.6s |  |
| 100 | `avm2_catchup_dobj` | 158 | 9.5s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 107.2s |  |
| 102 | `bevel_filter` | 187 | 8.8s |  |
| 103 | `bitand` | 1058 | 17.4s |  |
| 104 | `bitmap_constr` | 17 | 8.8s |  |
| 105 | `bitmap_data` | 1000 | 17.2s |  |
| 106 | `bitmap_filter_abstract` | 6 | 8.5s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 29.0s |  |
| 108 | `bitmap_properties` | 23 | 8.6s |  |
| 109 | `bitmap_subclass` | 7 | 10.2s |  |
| 110 | `bitmap_subclass_properties` | 9 | 8.8s |  |
| 111 | `bitmap_timeline` | 9 | 8.9s |  |
| 112 | `bitmapdata_accuracy` | 1 | 56.7s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 29.5s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.3s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 29.0s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 29.5s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 28.6s |  |
| 118 | `bitmapdata_clone` | 13 | 8.6s |  |
| 119 | `bitmapdata_colortransform` | 0 | 8.9s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 8.5s |  |
| 121 | `bitmapdata_constr` | 22 | 8.6s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 8.9s |  |
| 123 | `bitmapdata_copychannel` | 0 | 30.8s |  |
| 124 | `bitmapdata_copypixels` | 23 | 29.6s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 8.6s |  |
| 126 | `bitmapdata_copypixels_alpha_merge` | 9 | 17.3s |  |
| 127 | `bitmapdata_copypixels_blend` | 1029 | 9.3s |  |
| 128 | `bitmapdata_copypixels_blend_over` | 1 | 8.7s |  |
| 129 | `bitmapdata_copypixels_self` | 612 | 8.8s |  |
| 130 | `bitmapdata_copypixelstobytearray` | 39 | 8.7s |  |
| 131 | `bitmapdata_dispose` | 7 | 8.6s |  |
| 132 | `bitmapdata_draw` | 0 | 29.3s |  |
| 133 | `bitmapdata_draw_alpha_erase` | 8 | 8.8s |  |
| 134 | `bitmapdata_draw_cab_quality` | 0 | 29.7s |  |
| 135 | `bitmapdata_draw_colortransform` | 0 | 8.8s |  |
| 136 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 28.7s |  |
| 137 | `bitmapdata_draw_filters` | 0 | 28.6s |  |
| 138 | `bitmapdata_draw_masks` | 0 | 9.1s |  |
| 139 | `bitmapdata_draw_rotation` | 0 | 8.9s |  |
| 140 | `bitmapdata_draw_self_via_graphic` | 0 | 8.8s |  |
| 141 | `bitmapdata_draw_stage` | 0 | 28.6s |  |
| 142 | `bitmapdata_drawwithquality` | 0 | 11.4s |  |
| 143 | `bitmapdata_embedded` | 9 | 9.0s |  |
| 144 | `bitmapdata_fillrect` | 0 | 8.8s |  |
| 145 | `bitmapdata_filter_sourcerect` | 0 | 28.6s |  |
| 146 | `bitmapdata_floodfill` | 35 | 8.7s |  |
| 147 | `bitmapdata_getpixels` | 39 | 28.3s |  |
| 148 | `bitmapdata_getvector` | 27 | 3.3s |  |
| 149 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 150 | `bitmapdata_hittest` | 112 | 9.3s |  |
| 151 | `bitmapdata_hittest_threshold` | 18 | 8.7s |  |
| 152 | `bitmapdata_opaque` | 0 | 8.8s |  |
| 153 | `bitmapdata_pixeldissolve` | 1037 | 9.3s |  |
| 154 | `bitmapdata_pixeldissolve_image` | 0 | 9.1s |  |
| 155 | `bitmapdata_rectangle_rounding` | 16 | 8.7s |  |
| 156 | `bitmapdata_setpixels` | 286 | 8.8s |  |
| 157 | `bitmapdata_setvector` | 26 | 8.9s |  |
| 158 | `bitmapdata_sync` | 0 | 28.7s |  |
| 159 | `bitmapdata_threshold` | 176 | 9.4s |  |
| 160 | `bitmapdata_zero_size` | 8 | 8.7s |  |
| 161 | `bitnot` | 46 | 8.7s |  |
| 162 | `bitor` | 1058 | 19.9s |  |
| 163 | `bitxor` | 1058 | 19.8s |  |
| 164 | `blend_mode_null` | 1 | 8.6s |  |
| 165 | `blend_multiply_alpha` | 0 | 8.8s |  |
| 166 | `blend_scroll` | 0 | 8.9s |  |
| 167 | `blend_shader_luma_lighten` | 3 | 9.2s |  |
| 168 | `blur_filter` | 43 | 9.0s |  |
| 169 | `boolean_constr` | 32 | 8.5s |  |
| 170 | `boolean_negation` | 30 | 8.6s |  |
| 171 | `boolean_tostring` | 8 | 8.6s |  |
| 172 | `broadcast_event` | 7 | 8.5s |  |
| 173 | `button_bounds` | 1 | 8.8s |  |
| 174 | `button_hittest` | 2 | 29.6s |  |
| 175 | `button_nested_frame` | 48 | 29.4s |  |
| 176 | `button_nested_frame_simple` | 27 | 8.9s |  |
| 177 | `bytearray` | 48 | 8.9s |  |
| 178 | `bytearray_bad_symbol_class` | 3 | 8.5s |  |
| 179 | `bytearray_bad_symbol_class_other_movie` | 6 | 8.8s |  |
| 180 | `bytearray_compress` | 31 | 8.5s |  |
| 181 | `bytearray_errors` | 24 | 8.6s |  |
| 182 | `bytearray_method_serialization` | 1 | 8.6s |  |
| 183 | `bytearray_oom` | 3 | 8.5s |  |
| 184 | `bytearray_readobject_amf0` | 50 | 8.5s |  |
| 185 | `bytearray_readobject_amf3` | 53 | 8.5s |  |
| 186 | `bytearray_readutf8bytes_with_bom` | 16 | 8.5s |  |
| 187 | `bytearray_serialization` | 3 | 8.6s |  |
| 188 | `bytearray_string_null` | 19 | 8.7s |  |
| 189 | `bytearray_tostring` | 15 | 8.4s |  |
| 190 | `bytearray_utf16` | 8 | 8.3s |  |
| 191 | `bytearray_writeobject` | 24 | 8.2s |  |
| 192 | `callee_in_initializer` | 6 | 8.2s |  |
| 193 | `callproplex_class` | 1 | 8.3s |  |
| 194 | `capabilities_resolution` | 8 | 29.8s |  |
| 195 | `casi32` | 166 | 8.6s |  |
| 196 | `catch_class` | 6 | 8.5s |  |
| 197 | `catch_scope_slot` | 7 | 8.6s |  |
| 198 | `checkfilter` | 4 | 3.0s |  |
| 199 | `class_call` | 32 | 8.7s |  |
| 200 | `class_cast_call` | 14 | 8.5s |  |
| 201 | `class_enumeration` | 4 | 8.5s |  |
| 202 | `class_has_own_property` | 2 | 8.3s |  |
| 203 | `class_init_interpreter_mode` | 1 | 8.4s |  |
| 204 | `class_is` | 32 | 8.7s |  |
| 205 | `class_methods` | 5 | 8.6s |  |
| 206 | `class_object_properties` | 10 | 8.6s |  |
| 207 | `class_singleton` | 18 | 8.6s |  |
| 208 | `class_supercalls_errors` | 35 | 8.8s |  |
| 209 | `class_supercalls_mismatched` | 26 | 9.5s |  |
| 210 | `class_superclass_wrong_order` | 1 | 9.4s |  |
| 211 | `class_to_locale_string` | 2 | 9.4s |  |
| 212 | `class_to_string` | 2 | 9.4s |  |
| 213 | `class_value_of` | 2 | 9.5s |  |
| 214 | `click_block` | 5 | 33.1s |  |
| 215 | `click_invisible` | 3 | 9.4s |  |
| 216 | `closures` | 12 | 9.2s |  |
| 217 | `coerce_return_type` | 40 | 9.6s |  |
| 218 | `coerce_return_type_fail` | 2 | 9.1s |  |
| 219 | `coerce_return_void` | 3 | 9.2s |  |
| 220 | `coerce_string` | 86 | 9.6s |  |
| 221 | `coerce_string_precision` | 28 | 9.4s |  |
| 222 | `coerce_to_primitive_side_effects` | 29 | 9.4s |  |
| 223 | `color_matrix_filter` | 19 | 9.5s |  |
| 224 | `construct_errors_swf10` | 8 | 9.5s |  |
| 225 | `construct_frame_list` | 22 | 31.8s |  |
| 226 | `construct_interface` | 3 | 9.4s |  |
| 227 | `constructor_call` | 3 | 9.4s |  |
| 228 | `constructors_vs_timeline` | 5 | 32.5s |  |
| 229 | `constructprop_dynamic_primitive` | 7 | 9.5s |  |
| 230 | `constructprop_method` | 2 | 9.4s |  |
| 231 | `constructsuper_null` | 2 | 3.6s |  |
| 232 | `content_element_basic` | 50 | 9.8s |  |
| 233 | `context3d_creation` | 9 | 11.9s |  |
| 234 | `control_flow_bool` | 4 | 9.4s |  |
| 235 | `control_flow_stricteq` | 8 | 9.3s |  |
| 236 | `convert_boolean` | 30 | 9.4s |  |
| 237 | `convert_integer` | 90 | 9.5s |  |
| 238 | `convert_number` | 56 | 9.4s |  |
| 239 | `convert_uinteger` | 90 | 9.5s |  |
| 240 | `convolution_filter` | 89 | 9.6s |  |
| 241 | `core_exceptions` | 47 | 11.1s |  |
| 242 | `cpool_index_invalid_bytecode_1` | 6 | 9.6s |  |
| 243 | `cpool_index_invalid_bytecode_2` | 3 | 9.4s |  |
| 244 | `cpool_index_invalid_bytecode_3` | 1 | 9.6s |  |
| 245 | `cross_api_version_call_newer` | 12 | 10.2s |  |
| 246 | `cross_api_version_call_older` | 12 | 9.7s |  |
| 247 | `cryptscore` | 11 | 9.5s |  |
| 248 | `currency_parse_result` | 7 | 9.5s |  |
| 249 | `date` | 30 | 10.3s |  |
| 250 | `date_parse` | 36 | 6.2s |  |
| 251 | `date_set_time_out_of_range` | 62 | 6.0s |  |
| 252 | `declocal` | 46 | 6.3s |  |
| 253 | `declocal_i` | 46 | 6.0s |  |
| 254 | `decode_uri` | 71 | 6.3s |  |
| 255 | `decrement` | 46 | 6.2s |  |
| 256 | `decrement_i` | 46 | 2.2s |  |
| 257 | `default_values` | 7 | 6.2s |  |
| 258 | `delayed_symbolclass` | 28 | 6.3s |  |
| 259 | `describe_type_basic` | 152 | 6.4s |  |
| 260 | `describe_type_json` | 301 | 6.3s |  |
| 261 | `describe_type_metadata` | 125 | 6.1s |  |
| 262 | `describe_type_native` | 23 | 6.0s |  |
| 263 | `dictionary_access` | 62 | 6.2s |  |
| 264 | `dictionary_access_no_pubns` | 2 | 6.2s |  |
| 265 | `dictionary_delete` | 101 | 6.7s |  |
| 266 | `dictionary_foreach` | 42 | 6.7s |  |
| 267 | `dictionary_hasownproperty` | 63 | 6.5s |  |
| 268 | `dictionary_in` | 62 | 6.3s |  |
| 269 | `dictionary_iter_modify` | 8 | 6.1s |  |
| 270 | `dictionary_namespaces` | 36 | 6.5s |  |
| 271 | `displacement_map_filter` | 61 | 6.5s |  |
| 272 | `displayobject_alpha` | 277 | 6.2s |  |
| 273 | `displayobject_blendmode` | 0 | 20.9s |  |
| 274 | `displayobject_colortransform_nested` | 0 | 21.5s |  |
| 275 | `displayobject_early_init` | 54 | 7.4s |  |
| 276 | `displayobject_filters` | 17 | 6.2s |  |
| 277 | `displayobject_from_enterframe` | 1 | 20.5s |  |
| 278 | `displayobject_getbounds_shape` | 0 | 20.5s |  |
| 279 | `displayobject_getrect` | 16 | 6.2s |  |
| 280 | `displayobject_height` | 6052 | 21.3s |  |
| 281 | `displayobject_hittestobject` | 32 | 6.3s |  |
| 282 | `displayobject_hittestpoint` | 49 | 6.6s |  |
| 283 | `displayobject_hittestpoint_boundary` | 65 | 22.1s |  |
| 284 | `displayobject_hittestpoint_root` | 13 | 6.4s |  |
| 285 | `displayobject_invalid_floats` | 60 | 6.5s |  |
| 286 | `displayobject_invalid_props` | 3 | 6.5s |  |
| 287 | `displayobject_mask` | 3 | 6.4s |  |
| 288 | `displayobject_mask_self_referential` | 0 | 6.4s |  |
| 289 | `displayobject_metaData` | 3 | 6.2s |  |
| 290 | `displayobject_name` | 22 | 6.4s |  |
| 291 | `displayobject_name_from_timeline` | 24 | 9.0s |  |
| 292 | `displayobject_opaque_background` | 6 | 29.3s |  |
| 293 | `displayobject_parent` | 12 | 8.9s |  |
| 294 | `displayobject_root` | 24 | 8.9s |  |
| 295 | `displayobject_rotation` | 1284 | 9.0s |  |
| 296 | `displayobject_scrollrect` | 33 | 9.9s |  |
| 297 | `displayobject_set_matrix_nested` | 0 | 29.2s |  |
| 298 | `displayobject_set_name_loaded` | 3 | 9.2s |  |
| 299 | `displayobject_subclass` | 2 | 8.9s |  |
| 300 | `displayobject_transform` | 89 | 8.9s |  |
| 301 | `displayobject_visible` | 23 | 8.9s |  |
| 302 | `displayobject_width` | 4852 | 29.4s |  |
| 303 | `displayobject_x` | 614 | 8.9s |  |
| 304 | `displayobject_y` | 617 | 8.9s |  |
| 305 | `displayobject_z` | 38 | 30.1s |  |
| 306 | `displayobjectcontainer_addchild` | 32 | 8.9s |  |
| 307 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 8.8s |  |
| 308 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 9.1s |  |
| 309 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 8.9s |  |
| 310 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 9.0s |  |
| 311 | `displayobjectcontainer_addchildat` | 42 | 8.9s |  |
| 312 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 9.0s |  |
| 313 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 8.9s |  |
| 314 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 9.0s |  |
| 315 | `displayobjectcontainer_contains` | 66 | 9.1s |  |
| 316 | `displayobjectcontainer_getchildat` | 4 | 8.9s |  |
| 317 | `displayobjectcontainer_getchildbyname` | 9 | 8.8s |  |
| 318 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 8.8s |  |
| 319 | `displayobjectcontainer_getchildindex` | 28 | 8.8s |  |
| 320 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 9.0s |  |
| 321 | `displayobjectcontainer_removechild` | 10 | 8.8s |  |
| 322 | `displayobjectcontainer_removechild_errors` | 4 | 8.8s |  |
| 323 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 8.8s |  |
| 324 | `displayobjectcontainer_removechildat` | 18 | 8.7s |  |
| 325 | `displayobjectcontainer_removechildren` | 51 | 9.2s |  |
| 326 | `displayobjectcontainer_setchildindex` | 42 | 8.6s |  |
| 327 | `displayobjectcontainer_stopallmovieclips` | 2 | 29.3s |  |
| 328 | `displayobjectcontainer_swapchildren` | 42 | 9.0s |  |
| 329 | `displayobjectcontainer_swapchildrenat` | 42 | 8.9s |  |
| 330 | `displayobjectcontainer_timelineinstance` | 48 | 29.1s |  |
| 331 | `divide` | 1058 | 20.1s |  |
| 332 | `doabc_and_symbolclass_script_init_goto` | 7 | 29.1s |  |
| 333 | `doabc_and_symbolclass_script_init_normal` | 6 | 28.3s |  |
| 334 | `doabc_is_eager` | 1 | 27.8s |  |
| 335 | `documentclass` | 9 | 8.7s |  |
| 336 | `domain_memory` | 133 | 9.9s |  |
| 337 | `drag_drop` | 10 | 8.8s |  |
| 338 | `drop_shadow_filter` | 172 | 9.0s |  |
| 339 | `duplicate_defs` | 1 | 8.5s |  |
| 340 | `eager_init` | 1 | 8.6s |  |
| 341 | `east_asian_justifier_clone` | 8 | 8.7s |  |
| 342 | `edit_text_linkage` | 7 | 8.9s |  |
| 343 | `edittext_align` | 60 | 9.4s |  |
| 344 | `edittext_always_show_selection` | 0 | 28.9s |  |
| 345 | `edittext_antialiastype` | 296 | 9.2s |  |
| 346 | `edittext_at_point_methods_basic` | 16 | 10.1s |  |
| 347 | `edittext_autosize` | 39 | 9.3s |  |
| 348 | `edittext_autosize_align` | 0 | 28.4s |  |
| 349 | `edittext_autosize_height_dynamic` | 60 | 28.4s |  |
| 350 | `edittext_autosize_height_input` | 60 | 8.8s |  |
| 351 | `edittext_autosize_lazy_bounds_events` | 65 | 8.8s |  |
| 352 | `edittext_autosize_lazy_bounds_interactions` | 19 | 8.7s |  |
| 353 | `edittext_autosize_lazy_bounds_props` | 490 | 10.4s |  |
| 354 | `edittext_autosize_lazy_bounds_visual` | 0 | 8.8s |  |
| 355 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 8.8s |  |
| 356 | `edittext_bottom_scroll_v_basic` | 210 | 8.8s |  |
| 357 | `edittext_bounds_scale` | 24 | 8.8s |  |
| 358 | `edittext_bullet` | 30 | 9.0s |  |
| 359 | `edittext_default_format` | 221 | 9.2s |  |
| 360 | `edittext_default_format_empty` | 136 | 9.0s |  |
| 361 | `edittext_empty_text_format` | 7 | 8.8s |  |
| 362 | `edittext_focus_selection` | 5 | 8.7s |  |
| 363 | `edittext_font_size` | 45 | 9.2s |  |
| 364 | `edittext_format_empty_font` | 8 | 8.9s |  |
| 365 | `edittext_get_char_index_at_point` | 4 | 32.5s |  |
| 366 | `edittext_get_line_index_at_point` | 2 | 30.2s |  |
| 367 | `edittext_get_line_index_of_char` | 76 | 10.2s |  |
| 368 | `edittext_getcharboundaries` | 172 | 9.6s |  |
| 369 | `edittext_getcharboundaries_missing_glyphs` | 63 | 9.2s |  |
| 370 | `edittext_getcharboundaries_scroll` | 85 | 9.2s |  |
| 371 | `edittext_getlinemetrics` | 146 | 9.5s |  |
| 372 | `edittext_html` | 3101 | 9.6s |  |
| 373 | `edittext_html_condensewhite` | 487 | 8.8s |  |
| 374 | `edittext_html_entity` | 4 | 9.5s |  |
| 375 | `edittext_html_font_size_swf12` | 267 | 8.7s |  |
| 376 | `edittext_html_font_size_swf13` | 273 | 8.3s |  |
| 377 | `edittext_html_roundtrip` | 17 | 8.8s |  |
| 378 | `edittext_ime_focus_lost` | 9 | 8.9s |  |
| 379 | `edittext_input_control` | 12 | 8.6s |  |
| 380 | `edittext_leading` | 9 | 9.1s |  |
| 381 | `edittext_letter_spacing` | 15 | 8.9s |  |
| 382 | `edittext_line_methods` | 294 | 10.2s |  |
| 383 | `edittext_line_metrics` | 11 | 29.9s |  |
| 384 | `edittext_margins` | 25 | 8.9s |  |
| 385 | `edittext_max_scroll_h_basic` | 475 | 8.9s |  |
| 386 | `edittext_max_scroll_v_basic` | 1000 | 8.7s |  |
| 387 | `edittext_mouse_selection` | 363 | 29.6s |  |
| 388 | `edittext_mousedown` | 3 | 9.1s |  |
| 389 | `edittext_mouseenabled` | 26 | 8.7s |  |
| 390 | `edittext_newline_character` | 22 | 8.7s |  |
| 391 | `edittext_newline_stripping` | 64 | 15.5s |  |
| 392 | `edittext_newlines` | 30 | 8.9s |  |
| 393 | `edittext_paragraph_methods` | 257 | 8.7s |  |
| 394 | `edittext_paste_events` | 8 | 8.7s |  |
| 395 | `edittext_paste_maxchars` | 4 | 8.7s |  |
| 396 | `edittext_paste_restrict` | 16 | 8.5s |  |
| 397 | `edittext_restrict` | 191 | 8.7s |  |
| 398 | `edittext_restrict_events` | 22 | 8.7s |  |
| 399 | `edittext_scroll_event` | 37 | 8.9s |  |
| 400 | `edittext_scrollh` | 10 | 8.6s |  |
| 401 | `edittext_selected_text` | 9 | 8.6s |  |
| 402 | `edittext_set_html_same` | 17 | 8.7s |  |
| 403 | `edittext_set_text_vs_html` | 9 | 8.6s |  |
| 404 | `edittext_stylesheet` | 536 | 9.1s |  |
| 405 | `edittext_stylesheet_custom_tag` | 76 | 8.7s |  |
| 406 | `edittext_stylesheet_display` | 272 | 8.8s |  |
| 407 | `edittext_tag_indent` | 49 | 28.5s |  |
| 408 | `edittext_underline` | 40 | 9.0s |  |
| 409 | `edittext_width_height` | 103 | 9.0s |  |
| 410 | `edittext_wordwrap_word` | 150 | 8.7s |  |
| 411 | `edittext_wrap_breaks` | 2375 | 9.2s |  |
| 412 | `element_format_clone` | 44 | 8.9s |  |
| 413 | `element_format_constructor_order` | 64 | 3.4s |  |
| 414 | `element_format_properties` | 235 | 10.0s |  |
| 415 | `empty_bounds` | 1 | 5.5s |  |
| 416 | `encode_uri_surrogate_pair_invalid` | 8 | 5.6s |  |
| 417 | `encode_uri_surrogate_pair_swf11` | 15 | 5.4s |  |
| 418 | `equals` | 512 | 8.0s |  |
| 419 | `error_geterrormessage` | 779 | 5.9s |  |
| 420 | `error_prototype` | 15 | 5.8s |  |
| 421 | `error_stack_trace` | 45 | 6.1s |  |
| 422 | `error_stack_trace_debug_swf17` | 0 | 18.1s |  |
| 423 | `error_stack_trace_debug_swf18` | 0 | 5.4s |  |
| 424 | `error_stack_trace_edge_cases` | 6 | 5.6s |  |
| 425 | `error_stack_trace_release_swf17` | 0 | 2.2s |  |
| 426 | `error_stack_trace_release_swf18` | 0 | 5.3s |  |
| 427 | `error_throwerror` | 103 | 5.6s |  |
| 428 | `error_tostring` | 29 | 5.6s |  |
| 429 | `error_tostring_more` | 86 | 5.5s |  |
| 430 | `es3_inheritance` | 31 | 5.6s |  |
| 431 | `es4_inheritance` | 30 | 5.6s |  |
| 432 | `es4_interfaces` | 30 | 5.6s |  |
| 433 | `es4_method_binding` | 8 | 5.6s |  |
| 434 | `es4_oop_prototypes` | 14 | 5.8s |  |
| 435 | `es4_protected_inheritance` | 6 | 5.5s |  |
| 436 | `escape` | 71 | 5.7s |  |
| 437 | `escape_multi_byte` | 45 | 6.1s |  |
| 438 | `event_bubbles` | 2 | 5.9s |  |
| 439 | `event_cancelable` | 2 | 5.8s |  |
| 440 | `event_clone` | 20 | 5.9s |  |
| 441 | `event_clone_error_redispatch` | 3 | 5.8s |  |
| 442 | `event_clone_on_redispatch` | 10 | 5.6s |  |
| 443 | `event_formattostring` | 31 | 5.5s |  |
| 444 | `event_isdefaultprevented` | 12 | 5.6s |  |
| 445 | `event_target_getter` | 5 | 2.2s |  |
| 446 | `event_target_set` | 9 | 5.7s |  |
| 447 | `event_type` | 1 | 5.5s |  |
| 448 | `event_valueof_tostring` | 18 | 5.7s |  |
| 449 | `eventdispatcher_dispatchevent` | 12 | 5.6s |  |
| 450 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.8s |  |
| 451 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.0s |  |
| 452 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.1s |  |
| 453 | `eventdispatcher_dispatchevent_this` | 5 | 6.0s |  |
| 454 | `eventdispatcher_haseventlistener` | 25 | 6.1s |  |
| 455 | `eventdispatcher_interface_invoke` | 1 | 8.6s |  |
| 456 | `eventdispatcher_tostring` | 10 | 8.7s |  |
| 457 | `eventdispatcher_willtrigger` | 25 | 8.7s |  |
| 458 | `falsiness` | 30 | 8.7s |  |
| 459 | `fast_index_access` | 12 | 8.8s |  |
| 460 | `filefilter_properties` | 4 | 8.7s |  |
| 461 | `filereference_browse_cancel` | 3 | 8.7s |  |
| 462 | `filereference_browse_select` | 9 | 8.7s |  |
| 463 | `filereference_load` | 31 | 8.8s |  |
| 464 | `filereference_save` | 16 | 8.8s |  |
| 465 | `filereference_save_and_browse` | 42 | 8.8s |  |
| 466 | `filereference_save_and_load` | 22 | 8.8s |  |
| 467 | `filereference_uninitialized` | 8 | 8.6s |  |
| 468 | `filereferencelist_browse_cancel` | 6 | 8.7s |  |
| 469 | `filereferencelist_browse_select` | 7 | 8.6s |  |
| 470 | `filter_rewind` | 8 | 28.6s |  |
| 471 | `filters_array_holes` | 25 | 10.7s |  |
| 472 | `finddef` | 3 | 8.7s |  |
| 473 | `findprop_global_prototype` | 6 | 8.7s |  |
| 474 | `flash_media_video_constructor` | 156 | 9.5s |  |
| 475 | `flash_media_video_rotation_probe` | 27 | 8.8s |  |
| 476 | `flash_media_video_setter` | 40 | 9.2s |  |
| 477 | `flash_trace` | 17 | 8.9s |  |
| 478 | `flash_ui_mouse_cursor` | 35 | 9.1s |  |
| 479 | `flash_xml` | 29 | 8.8s |  |
| 480 | `flash_xml_cloneNode` | 22 | 8.7s |  |
| 481 | `flash_xml_namespace` | 109 | 8.7s |  |
| 482 | `flash_xml_removeNode` | 60 | 8.8s |  |
| 483 | `focus_events_code` | 161 | 28.9s |  |
| 484 | `focus_events_key_basic` | 132 | 28.8s |  |
| 485 | `focus_events_key_navigation` | 53 | 28.7s |  |
| 486 | `focus_events_key_same_object` | 26 | 8.8s |  |
| 487 | `focus_events_mixed_key_mouse` | 100 | 28.3s |  |
| 488 | `focus_events_mouse_basic` | 260 | 28.5s |  |
| 489 | `focus_events_mouse_focusable` | 112 | 28.8s |  |
| 490 | `focus_events_mouse_same_object` | 40 | 8.8s |  |
| 491 | `focus_remove` | 20 | 28.5s |  |
| 492 | `focus_root_movie` | 4 | 28.9s |  |
| 493 | `focus_stage` | 1 | 8.6s |  |
| 494 | `focusrect` | 18 | 9.6s |  |
| 495 | `focusrect_focuslost` | 9 | 8.8s |  |
| 496 | `focusrect_property` | 110 | 7.2s |  |
| 497 | `font_description_clone` | 14 | 7.5s |  |
| 498 | `font_embedded` | 24 | 7.7s |  |
| 499 | `font_enumeratefonts` | 41 | 8.1s |  |
| 500 | `font_enumeratefonts_filter` | 4 | 8.0s |  |
| 501 | `font_enumeratefonts_order` | 9 | 8.5s |  |
| 502 | `font_hasglyphs` | 40 | 7.7s |  |
| 503 | `font_registerfont` | 129 | 8.1s |  |
| 504 | `framelabel_constr` | 5 | 7.2s |  |
| 505 | `function_call` | 12 | 2.9s |  |
| 506 | `function_call_arguments` | 46 | 7.4s |  |
| 507 | `function_call_arguments_enumerate` | 5 | 7.1s |  |
| 508 | `function_call_coercion` | 108 | 7.5s |  |
| 509 | `function_call_default` | 6 | 7.1s |  |
| 510 | `function_call_rest` | 22 | 7.1s |  |
| 511 | `function_call_types` | 3 | 7.1s |  |
| 512 | `function_call_via_apply` | 11 | 7.1s |  |
| 513 | `function_call_via_call` | 3 | 7.1s |  |
| 514 | `function_display_anonymous` | 7 | 2.7s |  |
| 515 | `function_length` | 6 | 7.1s |  |
| 516 | `function_object` | 2 | 7.0s |  |
| 517 | `function_proto` | 5 | 7.2s |  |
| 518 | `function_proto_created` | 61 | 7.2s |  |
| 519 | `function_to_locale_string` | 4 | 7.1s |  |
| 520 | `function_to_string` | 4 | 7.0s |  |
| 521 | `function_type` | 6 | 7.2s |  |
| 522 | `function_unbound_this` | 51 | 7.3s |  |
| 523 | `function_value_of` | 4 | 7.1s |  |
| 524 | `game_input` | 4 | 7.1s |  |
| 525 | `generate_random_bytes` | 3 | 7.2s |  |
| 526 | `geom_transform` | 74 | 24.3s |  |
| 527 | `get_definition_by_name` | 11 | 7.2s |  |
| 528 | `get_qualified_class_name` | 20 | 7.1s |  |
| 529 | `get_qualified_super_class_name` | 18 | 7.2s |  |
| 530 | `get_slot_edge_cases` | 1 | 7.1s |  |
| 531 | `get_timer` | 2 | 2.7s |  |
| 532 | `getglobalslot` | 1 | 7.0s |  |
| 533 | `getouterscope` | 8 | 7.1s |  |
| 534 | `getouterscope_two_classobjects` | 13 | 7.1s |  |
| 535 | `getter_different_namespace_setter` | 2 | 7.0s |  |
| 536 | `glow_filter` | 127 | 7.5s |  |
| 537 | `goto_button_nested_framescript` | 28 | 23.5s |  |
| 538 | `goto_framescript_queued/swf10` | 59 | 23.3s |  |
| 539 | `goto_framescript_queued/swf9` | 52 | 1.5s |  |
| 540 | `goto_framescript_queued_same_frame` | 4 | 7.1s |  |
| 541 | `goto_in_constructframe` | 12 | 7.4s |  |
| 542 | `goto_in_scene_last_frame` | 2 | 23.1s |  |
| 543 | `goto_methods` | 56 | 7.5s |  |
| 544 | `goto_methods_swfver10` | 8 | 7.1s |  |
| 545 | `goto_nested_construct_sibling` | 18 | 7.5s |  |
| 546 | `goto_nested_framescript` | 9 | 7.3s |  |
| 547 | `goto_on_orphan` | 15 | 23.3s |  |
| 548 | `gradient_bevel_filter` | 206 | 7.2s |  |
| 549 | `gradient_glow_filter` | 206 | 7.0s |  |
| 550 | `graphic_linkage` | 9 | 7.3s |  |
| 551 | `graphics_bad_direct_commands` | 5 | 7.8s |  |
| 552 | `graphics_bitmap_fill` | 0 | 9.0s |  |
| 553 | `graphics_bitmaps` | 0 | 7.5s |  |
| 554 | `graphics_direct_commands` | 0 | 7.5s |  |
| 555 | `graphics_draw_triangles` | 98 | 24.1s |  |
| 556 | `graphics_gradients` | 0 | 7.5s |  |
| 557 | `graphics_gradients_nulls` | 0 | 7.4s |  |
| 558 | `graphics_path` | 56 | 7.3s |  |
| 559 | `graphics_round_rects` | 0 | 8.8s |  |
| 560 | `graphics_simple_shapes` | 0 | 7.3s |  |
| 561 | `greaterequals` | 512 | 10.5s |  |
| 562 | `greaterthan` | 512 | 10.5s |  |
| 563 | `has_own_property` | 102 | 7.7s |  |
| 564 | `hasownproperty_namespaces` | 2 | 7.1s |  |
| 565 | `hello_world` | 1 | 7.0s |  |
| 566 | `hittest_morph` | 30 | 7.2s |  |
| 567 | `id3_info` | 8 | 23.3s |  |
| 568 | `if_eq` | 10 | 7.0s |  |
| 569 | `if_gt` | 1 | 7.1s |  |
| 570 | `if_gte` | 10 | 2.8s |  |
| 571 | `if_lt` | 1 | 1.1s |  |
| 572 | `if_lte` | 10 | 7.0s |  |
| 573 | `if_ne` | 7 | 8.8s |  |
| 574 | `if_stricteq` | 6 | 8.8s |  |
| 575 | `if_strictne` | 11 | 8.8s |  |
| 576 | `ime_linux_dead_keys` | 10 | 8.7s |  |
| 577 | `in` | 102 | 9.3s |  |
| 578 | `inclocal` | 46 | 8.8s |  |
| 579 | `inclocal_i` | 46 | 8.8s |  |
| 580 | `increment` | 46 | 8.7s |  |
| 581 | `increment_i` | 46 | 8.8s |  |
| 582 | `indexing_delete` | 75 | 8.8s |  |
| 583 | `indexof_xml` | 10 | 8.8s |  |
| 584 | `init_callee_cached` | 24 | 8.7s |  |
| 585 | `instanceof` | 58 | 9.3s |  |
| 586 | `instantiate_root_character` | 4 | 9.1s |  |
| 587 | `instantiation_on_enter_frame` | 7 | 29.2s |  |
| 588 | `instantiation_on_enterframe_gotoandstop` | 8 | 8.9s |  |
| 589 | `int_constr` | 92 | 9.1s |  |
| 590 | `int_edge_cases` | 19 | 8.8s |  |
| 591 | `int_instanceof` | 3 | 8.8s |  |
| 592 | `int_tofixed` | 1215 | 8.8s |  |
| 593 | `int_toprecision` | 1125 | 8.9s |  |
| 594 | `int_tostring` | 3375 | 9.0s |  |
| 595 | `interactiveobject_enabled` | 25 | 8.7s |  |
| 596 | `interface_namespaces` | 78 | 8.9s |  |
| 597 | `invalid_utf8` | 12 | 8.8s |  |
| 598 | `is_finite` | 46 | 8.8s |  |
| 599 | `is_nan` | 46 | 8.5s |  |
| 600 | `is_prototype_of` | 12 | 8.7s |  |
| 601 | `issue_10221` | 2 | 8.7s |  |
| 602 | `issue_13780` | 12 | 8.8s |  |
| 603 | `issue_14901` | 1 | 8.7s |  |
| 604 | `issue_17675_edittext_paste_maxchars` | 1 | 8.9s |  |
| 605 | `issue_5292` | 5 | 8.9s |  |
| 606 | `issue_8630` | 2 | 9.0s |  |
| 607 | `issue_8630_placeremoveplace` | 15 | 9.2s |  |
| 608 | `issue_8630_placeremoveplace_scriptremove` | 16 | 9.1s |  |
| 609 | `issue_8630_scriptremove` | 11 | 9.0s |  |
| 610 | `istype` | 24 | 3.5s |  |
| 611 | `istypelate` | 58 | 9.3s |  |
| 612 | `istypelate_coerce` | 198 | 10.3s |  |
| 613 | `jpeg_loader_context` | 6 | 9.0s |  |
| 614 | `json_errors` | 9 | 29.6s |  |
| 615 | `json_parse` | 21 | 14.1s |  |
| 616 | `json_parse_errors` | 84 | 7.2s |  |
| 617 | `json_stringify` | 12 | 7.3s |  |
| 618 | `json_stringify_function` | 12 | 7.0s |  |
| 619 | `json_stringify_order` | 1 | 7.2s |  |
| 620 | `json_version_gated` | 1 | 7.1s |  |
| 621 | `key_input_80percent` | 1812 | 7.2s |  |
| 622 | `key_input_location` | 126 | 7.1s |  |
| 623 | `key_input_numpad` | 384 | 6.9s |  |
| 624 | `large_preload_from_bytes` | 51 | 10.1s |  |
| 625 | `large_preload_from_url` | 27 | 8.8s |  |
| 626 | `large_preload_image_from_bytes` | 25 | 7.5s |  |
| 627 | `lazyinit` | 17 | 7.1s |  |
| 628 | `lessequals` | 512 | 10.3s |  |
| 629 | `lessthan` | 512 | 10.4s |  |
| 630 | `loader_bitmap_transparency` | 14 | 7.4s |  |
| 631 | `loader_bytes_unknown_content` | 14 | 7.4s |  |
| 632 | `loader_child_getdefinition` | 5 | 8.4s |  |
| 633 | `loader_duplicate_class` | 48 | 9.9s |  |
| 634 | `loader_duplicate_coerce` | 3 | 7.5s |  |
| 635 | `loader_duplicate_coerce_new_domain` | 4 | 7.4s |  |
| 636 | `loader_error_in_root_ctor` | 4 | 7.3s |  |
| 637 | `loader_events` | 92 | 8.2s |  |
| 638 | `loader_image` | 8 | 7.6s |  |
| 639 | `loader_jpegxr` | 2 | 24.7s |  |
| 640 | `loader_jpegxr_alpha` | 1 | 7.6s |  |
| 641 | `loader_loadbytes_events` | 30 | 8.1s |  |
| 642 | `loader_loadbytes_invalid_png` | 4 | 7.6s |  |
| 643 | `loader_loadbytes_url` | 12 | 7.8s |  |
| 644 | `loader_loaderurl` | 6 | 8.2s |  |
| 645 | `loader_method` | 85 | 7.6s |  |
| 646 | `loader_noninteractive_try_click_root` | 5 | 25.2s |  |
| 647 | `loader_reuse` | 38 | 7.7s |  |
| 648 | `loader_try_click_root` | 16 | 7.9s |  |
| 649 | `loader_unknown_content` | 24 | 7.8s |  |
| 650 | `loader_visibility_interactive` | 1 | 7.5s |  |
| 651 | `loaderinfo_events` | 7 | 7.6s |  |
| 652 | `loaderinfo_loadurl` | 12 | 7.5s |  |
| 653 | `loaderinfo_more` | 6 | 7.6s |  |
| 654 | `loaderinfo_properties` | 18 | 30.8s |  |
| 655 | `loaderinfo_properties_not_loaded` | 23 | 7.3s |  |
| 656 | `loaderinfo_quine` | 1005 | 7.2s |  |
| 657 | `loaderinfo_root` | 10 | 7.2s |  |
| 658 | `loaderinfo_root_allows` | 2 | 7.2s |  |
| 659 | `localconnection` | 890 | 9.5s |  |
| 660 | `localconnection_send` | 4 | 7.4s |  |
| 661 | `lshift` | 1058 | 16.1s |  |
| 662 | `mask_reapply` | 1 | 24.4s |  |
| 663 | `math` | 497 | 7.6s |  |
| 664 | `matrix` | 338 | 16.6s |  |
| 665 | `matrix3d` | 57 | 8.2s |  |
| 666 | `matrix3d_append` | 16 | 7.4s |  |
| 667 | `matrix3d_append_prepend_scale` | 86 | 7.5s |  |
| 668 | `matrix3d_append_prepend_translation` | 42 | 7.4s |  |
| 669 | `matrix3d_append_rotation` | 23 | 7.3s |  |
| 670 | `matrix3d_compose` | 34 | 7.5s |  |
| 671 | `matrix3d_constructor_clone` | 15 | 7.1s |  |
| 672 | `matrix3d_copy_column` | 83 | 7.4s |  |
| 673 | `matrix3d_copy_from` | 19 | 7.2s |  |
| 674 | `matrix3d_copy_raw_data_from` | 55 | 3.0s |  |
| 675 | `matrix3d_copy_raw_data_to` | 38 | 7.3s |  |
| 676 | `matrix3d_copy_row` | 83 | 7.0s |  |
| 677 | `matrix3d_copy_to_matrix3d` | 19 | 7.1s |  |
| 678 | `matrix3d_determinant` | 182 | 7.4s |  |
| 679 | `matrix3d_interpolate` | 21 | 7.4s |  |
| 680 | `matrix3d_invert` | 18 | 7.0s |  |
| 681 | `matrix3d_position` | 19 | 7.3s |  |
| 682 | `matrix3d_precision` | 28 | 7.3s |  |
| 683 | `matrix3d_prepend` | 16 | 6.9s |  |
| 684 | `matrix3d_raw_data` | 33 | 7.3s |  |
| 685 | `matrix3d_transform_vector` | 52 | 7.5s |  |
| 686 | `matrix3d_transpose` | 5 | 7.0s |  |
| 687 | `method_association` | 5 | 7.0s |  |
| 688 | `method_without_body` | 3 | 22.9s |  |
| 689 | `missing_external_interface` | 10 | 7.0s |  |
| 690 | `modulo` | 1058 | 15.4s |  |
| 691 | `morph_shape` | 2 | 22.6s |  |
| 692 | `mouse_children` | 192 | 23.3s |  |
| 693 | `mouse_click_events` | 90 | 22.8s |  |
| 694 | `mouse_double_click_events` | 188 | 7.1s |  |
| 695 | `mouse_empty_parent` | 4 | 7.0s |  |
| 696 | `mouse_over_while_dragging` | 3 | 13.9s |  |
| 697 | `mouse_pick_avm1_root` | 2 | 23.1s |  |
| 698 | `mouse_pick_button_mode` | 2 | 7.1s |  |
| 699 | `mouse_pick_dobj_mask` | 4 | 7.4s |  |
| 700 | `mouse_pick_masking` | 7 | 23.1s |  |
| 701 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 23.1s |  |
| 702 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.2s |  |
| 703 | `mouse_pick_text` | 8 | 7.1s |  |
| 704 | `mouse_sibling` | 8 | 7.1s |  |
| 705 | `mouse_wheel_events` | 36 | 23.8s |  |
| 706 | `mouseevent_constr` | 66 | 7.5s |  |
| 707 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 708 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 709 | `movieclip_addframescript` | 3 | 22.9s |  |
| 710 | `movieclip_addframescript_error` | 9 | 7.2s |  |
| 711 | `movieclip_child_property` | 16 | 7.3s |  |
| 712 | `movieclip_constr` | 21 | 7.2s |  |
| 713 | `movieclip_currentlabels` | 17 | 22.9s |  |
| 714 | `movieclip_currentlabels_dupes1` | 46 | 23.2s |  |
| 715 | `movieclip_currentlabels_dupes2` | 30 | 7.3s |  |
| 716 | `movieclip_currentlabels_dupes3` | 67 | 7.1s |  |
| 717 | `movieclip_currentscene` | 12 | 7.0s |  |
| 718 | `movieclip_dispatchevent` | 430 | 7.3s |  |
| 719 | `movieclip_dispatchevent_cancel` | 102 | 7.4s |  |
| 720 | `movieclip_dispatchevent_handlerorder` | 251 | 7.3s |  |
| 721 | `movieclip_dispatchevent_selfadd` | 80 | 7.1s |  |
| 722 | `movieclip_dispatchevent_target` | 899 | 7.2s |  |
| 723 | `movieclip_displayevents` | 96 | 23.4s |  |
| 724 | `movieclip_displayevents_clickgoto` | 676 | 7.8s |  |
| 725 | `movieclip_displayevents_clickgoto2` | 2001 | 7.8s |  |
| 726 | `movieclip_displayevents_clickplay` | 575 | 7.4s |  |
| 727 | `movieclip_displayevents_clicksymbol` | 562 | 7.4s |  |
| 728 | `movieclip_displayevents_constructframegoto` | 140 | 7.7s |  |
| 729 | `movieclip_displayevents_constructframeplay` | 50 | 7.7s |  |
| 730 | `movieclip_displayevents_constructframesymbol` | 144 | 7.5s |  |
| 731 | `movieclip_displayevents_dblhandler` | 21 | 7.2s |  |
| 732 | `movieclip_displayevents_enterframegoto` | 149 | 7.5s |  |
| 733 | `movieclip_displayevents_enterframeplay` | 48 | 7.2s |  |
| 734 | `movieclip_displayevents_enterframesymbol` | 149 | 23.2s |  |
| 735 | `movieclip_displayevents_exitframegoto` | 106 | 7.2s |  |
| 736 | `movieclip_displayevents_exitframeplay` | 44 | 7.6s |  |
| 737 | `movieclip_displayevents_exitframesymbol` | 135 | 7.4s |  |
| 738 | `movieclip_displayevents_looping` | 63 | 17.8s |  |
| 739 | `movieclip_displayevents_stopped` | 113 | 29.2s |  |
| 740 | `movieclip_displayevents_swap` | 96 | 28.5s |  |
| 741 | `movieclip_displayevents_timeline` | 128 | 29.0s |  |
| 742 | `movieclip_drawrect` | 54 | 8.8s |  |
| 743 | `movieclip_frameconstruct_skipped` | 9 | 8.7s |  |
| 744 | `movieclip_goto_during_frame_script` | 15 | 8.9s |  |
| 745 | `movieclip_goto_overwrite` | 14 | 28.4s |  |
| 746 | `movieclip_goto_scene_last_frame_int` | 1 | 28.2s |  |
| 747 | `movieclip_goto_scene_last_frame_label` | 1 | 8.6s |  |
| 748 | `movieclip_gotoandplay` | 15 | 29.2s |  |
| 749 | `movieclip_gotoandstop` | 13 | 8.7s |  |
| 750 | `movieclip_gotoandstop_children` | 4 | 8.8s |  |
| 751 | `movieclip_gotoandstop_framescripts1` | 4 | 8.7s |  |
| 752 | `movieclip_gotoandstop_framescripts2` | 4 | 3.2s |  |
| 753 | `movieclip_gotoandstop_framescripts_self` | 7 | 28.3s |  |
| 754 | `movieclip_gotoandstop_queueing` | 12 | 8.9s |  |
| 755 | `movieclip_hittest` | 67 | 9.1s |  |
| 756 | `movieclip_next_frame` | 2 | 8.7s |  |
| 757 | `movieclip_next_scene` | 6 | 8.8s |  |
| 758 | `movieclip_play` | 3 | 8.5s |  |
| 759 | `movieclip_prev_frame` | 3 | 8.4s |  |
| 760 | `movieclip_prev_scene` | 7 | 8.6s |  |
| 761 | `movieclip_properties` | 79 | 8.8s |  |
| 762 | `movieclip_queued_noop_goto_swf10` | 9 | 8.6s |  |
| 763 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 764 | `movieclip_scenes` | 11 | 8.6s |  |
| 765 | `movieclip_soundtransform` | 831 | 30.4s |  |
| 766 | `movieclip_stop` | 1 | 8.5s |  |
| 767 | `movieclip_super_is_symbol` | 20 | 8.9s |  |
| 768 | `movieclip_symbol_constr` | 8 | 8.7s |  |
| 769 | `movieclip_text_mousedown` | 1 | 8.7s |  |
| 770 | `movieclip_willtrigger` | 5 | 8.7s |  |
| 771 | `multiply` | 1058 | 19.6s |  |
| 772 | `namespace_constr` | 253 | 8.9s |  |
| 773 | `namespace_constr_args` | 1 | 8.5s |  |
| 774 | `namespace_enumeration_order` | 7 | 8.6s |  |
| 775 | `nan_scale` | 9 | 8.6s |  |
| 776 | `native_menu_basic` | 19 | 10.9s |  |
| 777 | `navigateToURL_target_normalize` | 107 | 30.2s |  |
| 778 | `negate` | 30 | 8.6s |  |
| 779 | `negative_volume_panned` | 0 | 8.9s |  |
| 780 | `nested_iteration` | 11 | 8.6s |  |
| 781 | `net_getClassByAlias` | 3 | 17.8s |  |
| 782 | `net_navigateToURL` | 57 | 32.1s |  |
| 783 | `net_stream_play_options` | 6 | 9.0s |  |
| 784 | `netconnection_close` | 55 | 9.1s |  |
| 785 | `netconnection_properties` | 78 | 9.2s |  |
| 786 | `netconnection_send_remote` | 50 | 30.2s |  |
| 787 | `netconnection_serialize_arrays` | 6 | 9.1s |  |
| 788 | `netfilterevent` | 10 | 9.1s |  |
| 789 | `netstream_client` | 10 | 9.3s |  |
| 790 | `netstream_connect` | 7 | 9.0s |  |
| 791 | `netstream_flv_date` | 4 | 9.1s |  |
| 792 | `newactivation_in_script_init` | 3 | 8.8s |  |
| 793 | `newclass_mismatched` | 4 | 8.9s |  |
| 794 | `newclass_twice` | 3 | 8.8s |  |
| 795 | `nonconflicting_declarations` | 0 | 8.9s |  |
| 796 | `null_void_types` | 8 | 8.9s |  |
| 797 | `number_autoconv` | 21 | 8.9s |  |
| 798 | `number_autoconv_amf` | 132 | 8.9s |  |
| 799 | `number_autoconv_array_sort_32bit` | 1 | 8.9s |  |
| 800 | `number_constr` | 58 | 9.3s |  |
| 801 | `number_convert_edge_cases` | 180 | 30.4s |  |
| 802 | `number_toexponential` | 378 | 9.0s |  |
| 803 | `number_toexponential2` | 35 | 8.9s |  |
| 804 | `number_tofixed` | 378 | 8.8s |  |
| 805 | `number_toprecision` | 350 | 9.0s |  |
| 806 | `obfuscated_class_names` | 3 | 8.8s |  |
| 807 | `object_enumeration` | 10 | 8.9s |  |
| 808 | `object_prototype` | 4 | 8.9s |  |
| 809 | `object_to_locale_string` | 2 | 8.8s |  |
| 810 | `object_to_string` | 2 | 8.8s |  |
| 811 | `object_value_of` | 2 | 3.2s |  |
| 812 | `op_coerce` | 54 | 8.8s |  |
| 813 | `op_coerce_x` | 54 | 9.0s |  |
| 814 | `op_escxattr` | 2 | 8.9s |  |
| 815 | `op_escxelem` | 2 | 8.9s |  |
| 816 | `op_lookupswitch` | 4 | 8.9s |  |
| 817 | `optimize_coerce` | 1 | 8.8s |  |
| 818 | `orphan_movie_complex` | 80 | 18.0s |  |
| 819 | `orphan_movie_reorder` | 111 | 29.9s |  |
| 820 | `orphan_removeobject` | 636 | 31.0s |  |
| 821 | `package_namespace` | 7 | 8.9s |  |
| 822 | `param_default_value_has_zero_cpool_index` | 1 | 8.7s |  |
| 823 | `parent_early_access_child` | 16 | 9.1s |  |
| 824 | `parse_float` | 81 | 9.2s |  |
| 825 | `parse_float_swf10` | 81 | 9.0s |  |
| 826 | `parse_int` | 135 | 9.4s |  |
| 827 | `perspective_projection` | 1443 | 30.5s |  |
| 828 | `perspective_projection_basic` | 40 | 9.0s |  |
| 829 | `pixelbender_ceil` | 77 | 9.3s |  |
| 830 | `pixelbender_conditional` | 138 | 9.2s |  |
| 831 | `pixelbender_conversions` | 270 | 9.2s |  |
| 832 | `pixelbender_dithering` | 8 | 35.5s |  |
| 833 | `pixelbender_div` | 36 | 8.8s |  |
| 834 | `pixelbender_effect_BlurredFocus` | 0 | 37.0s |  |
| 835 | `pixelbender_effect_glassDisplace` | 0 | 15.2s |  |
| 836 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 33.4s |  |
| 837 | `pixelbender_effect_smudge` | 0 | 12.7s |  |
| 838 | `pixelbender_effect_tintype` | 0 | 12.0s |  |
| 839 | `pixelbender_effect_twirl` | 0 | 13.6s |  |
| 840 | `pixelbender_eof` | 7 | 8.8s |  |
| 841 | `pixelbender_images` | 0 | 11.4s |  |
| 842 | `pixelbender_input` | 103 | 32.0s |  |
| 843 | `pixelbender_logicalnot` | 20 | 8.8s |  |
| 844 | `pixelbender_malformed_data` | 190 | 29.5s |  |
| 845 | `pixelbender_multiple_out_params` | 1 | 8.6s |  |
| 846 | `pixelbender_no_out_param` | 6 | 8.7s |  |
| 847 | `pixelbender_outputs` | 13 | 8.9s |  |
| 848 | `pixelbender_padding_bytes` | 22 | 8.8s |  |
| 849 | `pixelbender_param_qualifier` | 512 | 8.8s |  |
| 850 | `pixelbender_parameters` | 1563 | 9.2s |  |
| 851 | `pixelbender_parameters_bool` | 240 | 9.0s |  |
| 852 | `pixelbender_parameters_int_vs_bool` | 54 | 8.8s |  |
| 853 | `pixelbender_parse_errors` | 6 | 8.7s |  |
| 854 | `pixelbender_rsqrt` | 24 | 8.8s |  |
| 855 | `pixelbender_select_kinds` | 8 | 9.0s |  |
| 856 | `pixelbender_shaderdata` | 49 | 8.8s |  |
| 857 | `pixelbender_shaderdata_setter` | 99 | 9.2s |  |
| 858 | `pixelbender_sign` | 60 | 9.0s |  |
| 859 | `pixelbender_vector_output` | 11 | 8.9s |  |
| 860 | `place_and_lookup/swf10` | 33 | 8.7s |  |
| 861 | `place_and_lookup/swf9` | 33 | 19.6s |  |
| 862 | `place_multiple` | 17 | 9.9s |  |
| 863 | `place_object_replace` | 9 | 31.7s |  |
| 864 | `place_object_replace_2` | 24 | 9.8s |  |
| 865 | `place_object_same_depth_frame` | 1 | 9.9s |  |
| 866 | `point` | 132 | 10.6s |  |
| 867 | `primitive_edge_cases` | 1 | 9.2s |  |
| 868 | `primitive_keys` | 54 | 9.1s |  |
| 869 | `primitive_toString` | 277 | 9.2s |  |
| 870 | `primitive_valueOf` | 285 | 8.9s |  |
| 871 | `print_job_options` | 3 | 8.9s |  |
| 872 | `property_is_enumerable` | 114 | 10.3s |  |
| 873 | `property_is_enumerable_reset` | 23 | 8.8s |  |
| 874 | `property_priority` | 22 | 9.2s |  |
| 875 | `property_priority_chained` | 4 | 8.8s |  |
| 876 | `property_priority_definition_names_order` | 2 | 9.2s |  |
| 877 | `property_priority_three_level` | 6 | 9.1s |  |
| 878 | `propertyisenumerable_namespaces` | 6 | 8.9s |  |
| 879 | `prototype_set_null` | 7 | 9.0s |  |
| 880 | `proxy_callproperty` | 24 | 8.9s |  |
| 881 | `proxy_deleteproperty` | 64 | 8.9s |  |
| 882 | `proxy_enumeration` | 34 | 9.2s |  |
| 883 | `proxy_getproperty` | 77 | 9.5s |  |
| 884 | `proxy_hasownproperty` | 8 | 9.3s |  |
| 885 | `proxy_hasproperty` | 32 | 9.7s |  |
| 886 | `proxy_not_overridden` | 54 | 9.5s |  |
| 887 | `proxy_serialize` | 9 | 9.4s |  |
| 888 | `proxy_setproperty` | 42 | 9.8s |  |
| 889 | `qname_as_lazy_name_attribute_multiname` | 1 | 9.3s |  |
| 890 | `qname_constr` | 32 | 9.2s |  |
| 891 | `qname_constr_namespace` | 24 | 9.5s |  |
| 892 | `qname_enumeration` | 9 | 9.0s |  |
| 893 | `qname_indexing` | 23 | 9.1s |  |
| 894 | `qname_tostring` | 25 | 9.1s |  |
| 895 | `qname_valueof` | 29 | 9.0s |  |
| 896 | `rectangle` | 1094 | 9.8s |  |
| 897 | `regexp_constr` | 148 | 9.2s |  |
| 898 | `regexp_exec` | 19 | 9.1s |  |
| 899 | `regexp_extended` | 47 | 8.9s |  |
| 900 | `regexp_multiargs` | 1 | 8.9s |  |
| 901 | `regexp_test` | 27 | 8.8s |  |
| 902 | `regexp_toString` | 10 | 8.9s |  |
| 903 | `register_script_refresh` | 35 | 9.5s |  |
| 904 | `remove_child_clear_field` | 88 | 14.2s |  |
| 905 | `remove_dobj` | 3 | 6.8s |  |
| 906 | `resolve_order` | 4 | 7.3s |  |
| 907 | `responder_null_callbacks` | 1 | 7.0s |  |
| 908 | `rng` | 1 | 8.1s |  |
| 909 | `rootless` | 42 | 7.0s |  |
| 910 | `rshift` | 1058 | 15.4s |  |
| 911 | `rtqname_not_namespace` | 12 | 7.2s |  |
| 912 | `sandbox_type_inherited` | 2 | 7.3s |  |
| 913 | `sandbox_type_local_file` | 1 | 7.0s |  |
| 914 | `sandbox_type_local_network` | 1 | 7.0s |  |
| 915 | `scene_constr` | 8 | 7.1s |  |
| 916 | `scope_optimizations` | 4 | 7.1s |  |
| 917 | `scopes_dont_cache/order-1` | 1 | 22.9s |  |
| 918 | `scopes_dont_cache/order-2` | 1 | 0.9s |  |
| 919 | `security_domain_current` | 2 | 6.9s |  |
| 920 | `selection` | 239 | 7.7s |  |
| 921 | `set_local_0` | 31 | 7.1s |  |
| 922 | `set_property_is_enumerable` | 85 | 7.4s |  |
| 923 | `shaderparameter_value` | 4 | 7.0s |  |
| 924 | `shape_drawrect` | 54 | 7.2s |  |
| 925 | `shared_object_no_root` | 3 | 7.0s |  |
| 926 | `simplebutton_added_to_stage` | 45 | 23.1s |  |
| 927 | `simplebutton_childevents` | 86 | 23.6s |  |
| 928 | `simplebutton_childevents_nested` | 54 | 7.6s |  |
| 929 | `simplebutton_childevents_sprite` | 13 | 7.6s |  |
| 930 | `simplebutton_childprops` | 144 | 7.6s |  |
| 931 | `simplebutton_childshuffle` | 23 | 7.1s |  |
| 932 | `simplebutton_constr` | 36 | 7.3s |  |
| 933 | `simplebutton_constr_childevents` | 48 | 7.7s |  |
| 934 | `simplebutton_constr_params` | 42 | 7.3s |  |
| 935 | `simplebutton_mouseenabled` | 26 | 7.2s |  |
| 936 | `simplebutton_multi_children` | 19 | 7.6s |  |
| 937 | `simplebutton_soundtransform` | 887 | 25.1s |  |
| 938 | `simplebutton_structure` | 27 | 7.5s |  |
| 939 | `simplebutton_symbolclass` | 68 | 7.6s |  |
| 940 | `slot_disp_id_shared_numbering` | 1 | 23.1s |  |
| 941 | `slots_force_autoassigned` | 1 | 11.1s |  |
| 942 | `socket_after_disconnect` | 1 | 5.4s |  |
| 943 | `socket_close` | 2 | 5.4s |  |
| 944 | `socket_connect` | 4 | 5.5s |  |
| 945 | `socket_errors` | 56 | 5.8s |  |
| 946 | `socket_read_big` | 48 | 5.6s |  |
| 947 | `socket_read_little` | 48 | 2.1s |  |
| 948 | `socket_read_write_object` | 8 | 5.6s |  |
| 949 | `socket_write_big` | 15 | 5.8s |  |
| 950 | `socket_write_little` | 14 | 5.7s |  |
| 951 | `sound_constructor_with_args` | 6 | 5.8s |  |
| 952 | `sound_embeddedprops` | 26 | 5.7s |  |
| 953 | `sound_load_multiple` | 19 | 6.3s |  |
| 954 | `sound_play` | 19 | 5.6s |  |
| 955 | `sound_rootless` | 7 | 5.5s |  |
| 956 | `sound_valueof` | 33 | 5.7s |  |
| 957 | `soundchannel_soundtransform` | 835 | 18.9s |  |
| 958 | `soundchannel_soundtransform_exists` | 5 | 17.5s |  |
| 959 | `soundchannel_stop` | 8 | 5.6s |  |
| 960 | `soundmixer_buffertime` | 5 | 5.5s |  |
| 961 | `soundmixer_soundtransform` | 900 | 6.8s |  |
| 962 | `soundmixer_stopall` | 6 | 5.5s |  |
| 963 | `soundtransform` | 442 | 8.6s |  |
| 964 | `space_justifier_clone` | 12 | 5.5s |  |
| 965 | `sprite_with_frames` | 0 | 17.9s |  |
| 966 | `stage3d_agal_cross_product` | 0 | 7.3s |  |
| 967 | `stage3d_agal_upload_errors` | 66 | 8.4s |  |
| 968 | `stage3d_bitmap` | 0 | 21.0s |  |
| 969 | `stage3d_blend` | 81 | 20.1s |  |
| 970 | `stage3d_context3d_string_args` | 158 | 6.6s |  |
| 971 | `stage3d_errors` | 7 | 5.6s |  |
| 972 | `stage3d_errors_atf` | 3 | 6.4s |  |
| 973 | `stage3d_errors_swf_29` | 6 | 5.6s |  |
| 974 | `stage3d_float1_index` | 0 | 19.0s |  |
| 975 | `stage3d_fractal` | 0 | 19.7s |  |
| 976 | `stage3d_ignore_sampler_override` | 0 | 19.7s |  |
| 977 | `stage3d_multistage_triangle` | 3 | 7.3s |  |
| 978 | `stage3d_program_constants_bytearray_be` | 0 | 20.8s |  |
| 979 | `stage3d_program_constants_bytearray_le` | 0 | 7.6s |  |
| 980 | `stage3d_program_constants_invalid_input` | 21 | 6.0s |  |
| 981 | `stage3d_raytrace` | 0 | 47.4s |  |
| 982 | `stage3d_rotating_cube` | 0 | 13.1s |  |
| 983 | `stage3d_sampler` | 0 | 12.0s |  |
| 984 | `stage3d_sampler_partial_upload` | 0 | 12.0s |  |
| 985 | `stage3d_stencil` | 0 | 12.9s |  |
| 986 | `stage3d_texture` | 0 | 18.4s |  |
| 987 | `stage3d_texture_bytearray` | 0 | 13.8s |  |
| 988 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 12.8s |  |
| 989 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 13.9s |  |
| 990 | `stage3d_triangle` | 0 | 12.2s |  |
| 991 | `stage3d_triangle_bytes4` | 0 | 12.3s |  |
| 992 | `stage3d_triangle_float1` | 0 | 12.1s |  |
| 993 | `stage3d_triangle_index_upload` | 0 | 12.1s |  |
| 994 | `stage3d_x_y` | 22 | 9.0s |  |
| 995 | `stage_access` | 10 | 9.0s |  |
| 996 | `stage_display_state` | 6 | 9.0s |  |
| 997 | `stage_displayobject_properties` | 24 | 8.9s |  |
| 998 | `stage_domain_getQualifiedDefinitionNames` | 5 | 8.9s |  |
| 999 | `stage_framerate_nan` | 7 | 8.9s |  |
| 1000 | `stage_framerate_negative` | 6 | 8.9s |  |
| 1001 | `stage_framerate_zero` | 6 | 8.9s |  |
| 1002 | `stage_invalidate` | 38 | 9.0s |  |
| 1003 | `stage_loaderinfo_properties` | 24 | 29.0s |  |
| 1004 | `stage_mousechildren` | 2 | 8.9s |  |
| 1005 | `stage_mouseenabled` | 15 | 8.8s |  |
| 1006 | `stage_overriden_setters` | 31 | 9.1s |  |
| 1007 | `stage_properties` | 30 | 8.9s |  |
| 1008 | `stage_properties2` | 213 | 9.2s |  |
| 1009 | `stage_scale_factor` | 12 | 34.3s |  |
| 1010 | `stage_stage3Ds_vector` | 1 | 8.8s |  |
| 1011 | `static_length` | 24 | 9.0s |  |
| 1012 | `static_text` | 3 | 9.1s |  |
| 1013 | `static_var_with_this_in_ctor` | 2 | 8.8s |  |
| 1014 | `statictext_text` | 8 | 9.0s |  |
| 1015 | `stored_properties` | 11 | 9.0s |  |
| 1016 | `strict_equality` | 34 | 9.0s |  |
| 1017 | `string_call` | 13 | 8.9s |  |
| 1018 | `string_case` | 23 | 8.9s |  |
| 1019 | `string_char_at` | 27 | 8.9s |  |
| 1020 | `string_char_code_at` | 28 | 8.7s |  |
| 1021 | `string_concat_fromcharcode` | 37 | 8.8s |  |
| 1022 | `string_constr` | 25 | 8.9s |  |
| 1023 | `string_indexof_lastindexof` | 87 | 18.3s |  |
| 1024 | `string_length` | 16 | 8.7s |  |
| 1025 | `string_locale_compare` | 39 | 9.5s |  |
| 1026 | `string_match` | 51 | 9.1s |  |
| 1027 | `string_relational_compare` | 4 | 8.9s |  |
| 1028 | `string_replace` | 51 | 8.8s |  |
| 1029 | `string_search` | 41 | 9.2s |  |
| 1030 | `string_slice_substr_substring` | 170 | 10.4s |  |
| 1031 | `string_split` | 29 | 9.0s |  |
| 1032 | `string_substr_negative` | 21 | 8.8s |  |
| 1033 | `string_substr_weird` | 182 | 8.7s |  |
| 1034 | `stylesheet` | 221 | 9.4s |  |
| 1035 | `stylesheet_parse_color` | 69 | 8.8s |  |
| 1036 | `stylesheet_transform` | 307 | 9.4s |  |
| 1037 | `sub_super_same_field` | 12 | 3.3s |  |
| 1038 | `subclass_superclass_linked_symbol` | 4 | 9.6s |  |
| 1039 | `subtract` | 1058 | 19.6s |  |
| 1040 | `super_get_call` | 12 | 9.2s |  |
| 1041 | `supercall_two_classobjects` | 2 | 8.7s |  |
| 1042 | `supercalls_coerce` | 8 | 9.3s |  |
| 1043 | `supercalls_weird` | 2 | 8.6s |  |
| 1044 | `superinterface_call` | 20 | 8.8s |  |
| 1045 | `superinterface_instanceof` | 18 | 8.7s |  |
| 1046 | `swf8` | 1 | 8.9s |  |
| 1047 | `swf_10_queued_goto_scripts_construct` | 52 | 9.1s |  |
| 1048 | `swf_9_goto_in_enter_frame` | 17 | 9.3s |  |
| 1049 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.9s |  |
| 1050 | `swf_9_queued_goto_scripts` | 6 | 8.8s |  |
| 1051 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 1052 | `swf_9_versioning` | 2 | 8.6s |  |
| 1053 | `swf_wrong_frame_count` | 38 | 9.6s |  |
| 1054 | `swf_wrong_frame_count_isplaying` | 22 | 8.8s |  |
| 1055 | `symbol_class_binary_data` | 8 | 8.7s |  |
| 1056 | `symbol_class_conflict` | 4 | 9.6s |  |
| 1057 | `symbol_class_root_not_zero` | 1 | 8.7s |  |
| 1058 | `symbolclass_invalid_utf8` | 2 | 8.9s |  |
| 1059 | `system_exit` | 3 | 8.6s |  |
| 1060 | `system_setclipboard_null` | 1 | 8.6s |  |
| 1061 | `tab_ordering_arrows` | 998 | 31.7s |  |
| 1062 | `tab_ordering_automatic_advanced` | 184 | 9.5s |  |
| 1063 | `tab_ordering_automatic_basic` | 45 | 16.5s |  |
| 1064 | `tab_ordering_children` | 116 | 6.9s |  |
| 1065 | `tab_ordering_custom_basic` | 34 | 6.8s |  |
| 1066 | `tab_ordering_properties` | 732 | 6.8s |  |
| 1067 | `tab_ordering_stage_tab_children` | 32 | 6.8s |  |
| 1068 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.8s |  |
| 1069 | `tab_ordering_tabbable` | 47 | 6.8s |  |
| 1070 | `tabstop_properties` | 105 | 6.8s |  |
| 1071 | `text_element_basic` | 34 | 6.8s |  |
| 1072 | `text_engine_fontdescription` | 27 | 6.8s |  |
| 1073 | `text_engine_groupelement` | 64 | 6.8s |  |
| 1074 | `text_run` | 7 | 6.8s |  |
| 1075 | `textblock_createline_errors` | 23 | 6.8s |  |
| 1076 | `textblock_createline_fte` | 9 | 6.8s |  |
| 1077 | `textblock_properties` | 118 | 6.8s |  |
| 1078 | `textbox_click` | 37 | 6.9s |  |
| 1079 | `textfield_event` | 66 | 6.8s |  |
| 1080 | `textfield_focusin_event` | 9 | 6.7s |  |
| 1081 | `textfield_input_dead_keys_windows` | 15 | 6.7s |  |
| 1082 | `textfield_input_events` | 25 | 8.9s |  |
| 1083 | `textfield_unload` | 39 | 6.8s |  |
| 1084 | `textformat` | 1134 | 6.7s |  |
| 1085 | `textformat_display` | 14 | 6.7s |  |
| 1086 | `textformat_font_max_length` | 4 | 7.0s |  |
| 1087 | `textjustifier_locale` | 132 | 6.8s |  |
| 1088 | `textline_has_tabs` | 47 | 6.7s |  |
| 1089 | `textline_inapplicable_properties` | 10 | 6.7s |  |
| 1090 | `textline_name` | 1 | 6.6s |  |
| 1091 | `textline_raw_text_length` | 30 | 6.6s |  |
| 1092 | `textline_splitting_basic` | 76 | 6.6s |  |
| 1093 | `textline_throwerror` | 30 | 6.6s |  |
| 1094 | `textline_validity` | 162 | 6.6s |  |
| 1095 | `throw` | 3 | 6.6s |  |
| 1096 | `timeline_scripts` | 3 | 6.6s |  |
| 1097 | `timer` | 90 | 7.0s |  |
| 1098 | `timer_events` | 3 | 6.6s |  |
| 1099 | `timer_finished` | 11 | 6.7s |  |
| 1100 | `timer_invalid_delay` | 30 | 6.8s |  |
| 1101 | `timer_reset` | 8 | 17.8s |  |
| 1102 | `timer_setdelay` | 5 | 9.2s |  |
| 1103 | `trace` | 12 | 8.8s |  |
| 1104 | `truthiness` | 30 | 9.0s |  |
| 1105 | `try_catch` | 11 | 8.9s |  |
| 1106 | `try_catch_typed` | 12 | 9.0s |  |
| 1107 | `typeof` | 30 | 9.0s |  |
| 1108 | `uint_constr` | 92 | 9.1s |  |
| 1109 | `uint_tofixed` | 1215 | 8.8s |  |
| 1110 | `uint_toprecision` | 1125 | 9.2s |  |
| 1111 | `uint_tostring` | 3375 | 9.2s |  |
| 1112 | `uncaught_error_basic` | 2 | 8.8s |  |
| 1113 | `unchecked_function` | 15 | 8.9s |  |
| 1114 | `unescape` | 28 | 9.1s |  |
| 1115 | `url_loader` | 25 | 9.3s |  |
| 1116 | `url_vars` | 27 | 9.2s |  |
| 1117 | `urlrequest` | 18 | 8.9s |  |
| 1118 | `urlstream_basic` | 5 | 9.0s |  |
| 1119 | `urshift` | 1058 | 20.4s |  |
| 1120 | `utils3d` | 7 | 9.0s |  |
| 1121 | `vector3d` | 397 | 14.0s |  |
| 1122 | `vector3d_near_equals` | 80 | 9.3s |  |
| 1123 | `vector_class` | 36 | 9.6s |  |
| 1124 | `vector_class_call` | 11 | 9.2s |  |
| 1125 | `vector_coercion` | 66 | 10.2s |  |
| 1126 | `vector_concat` | 90 | 9.8s |  |
| 1127 | `vector_constr` | 107 | 9.9s |  |
| 1128 | `vector_enumeration` | 5 | 9.0s |  |
| 1129 | `vector_every` | 92 | 10.0s |  |
| 1130 | `vector_filter` | 95 | 10.0s |  |
| 1131 | `vector_holes` | 24 | 9.0s |  |
| 1132 | `vector_indexof` | 302 | 14.4s |  |
| 1133 | `vector_insertat` | 270 | 10.3s |  |
| 1134 | `vector_int_access` | 4 | 8.9s |  |
| 1135 | `vector_int_delete` | 11 | 8.8s |  |
| 1136 | `vector_join` | 58 | 9.3s |  |
| 1137 | `vector_lastindexof` | 302 | 8.6s |  |
| 1138 | `vector_legacy` | 10 | 8.8s |  |
| 1139 | `vector_map` | 85 | 9.6s |  |
| 1140 | `vector_object_final` | 1 | 8.6s |  |
| 1141 | `vector_object_toString` | 10 | 18.4s |  |
| 1142 | `vector_pushpop` | 255 | 10.9s |  |
| 1143 | `vector_reborrow_bug` | 10 | 9.2s |  |
| 1144 | `vector_removeat` | 172 | 10.7s |  |
| 1145 | `vector_reverse` | 232 | 10.8s |  |
| 1146 | `vector_shiftunshift` | 252 | 9.1s |  |
| 1147 | `vector_slice` | 331 | 11.3s |  |
| 1148 | `vector_sort` | 905 | 20.2s |  |
| 1149 | `vector_splice` | 693 | 14.1s |  |
| 1150 | `vector_splice_fixed_bug_compat` | 4 | 9.2s |  |
| 1151 | `vector_tostring` | 79 | 10.0s |  |
| 1152 | `verification` | 8 | 9.2s |  |
| 1153 | `verify_abnormal_loop` | 1 | 9.0s |  |
| 1154 | `verify_dxns_without_flag` | 3 | 9.4s |  |
| 1155 | `verify_exception_target_two_jumps` | 1 | 9.0s |  |
| 1156 | `verify_exception_targets_edge_case` | 1 | 9.1s |  |
| 1157 | `verify_illegal_opcode` | 1 | 3.7s |  |
| 1158 | `verify_jump_to_middle_of_op` | 1 | 9.0s |  |
| 1159 | `verify_lookup_switch_edge_case` | 1 | 9.0s |  |
| 1160 | `verify_method_info_oob` | 1 | 1.3s |  |
| 1161 | `verify_stack` | 5 | 9.2s |  |
| 1162 | `verify_typecheck` | 4 | 9.1s |  |
| 1163 | `verify_unreachable_exception` | 2 | 9.1s |  |
| 1164 | `versioned_isplaying` | 2 | 9.1s |  |
| 1165 | `virtual_properties` | 16 | 9.2s |  |
| 1166 | `with` | 4 | 9.2s |  |
| 1167 | `wrong_arg_count` | 7 | 9.3s |  |
| 1168 | `xml_abstract_equality` | 36 | 9.5s |  |
| 1169 | `xml_advanced` | 52 | 9.3s |  |
| 1170 | `xml_appendchild` | 10 | 9.2s |  |
| 1171 | `xml_appendchild_swf_v21` | 13 | 9.4s |  |
| 1172 | `xml_as_attribute` | 9 | 9.0s |  |
| 1173 | `xml_attribute` | 35 | 9.3s |  |
| 1174 | `xml_attribute_name` | 40 | 9.1s |  |
| 1175 | `xml_basic` | 33 | 9.1s |  |
| 1176 | `xml_child` | 25 | 9.2s |  |
| 1177 | `xml_childindex` | 7 | 9.2s |  |
| 1178 | `xml_children` | 43 | 9.8s |  |
| 1179 | `xml_class_call` | 9 | 9.1s |  |
| 1180 | `xml_contains` | 197 | 9.4s |  |
| 1181 | `xml_copy` | 20 | 14.4s |  |
| 1182 | `xml_ctor_from_tostring` | 23 | 5.7s |  |
| 1183 | `xml_delete` | 114 | 5.8s |  |
| 1184 | `xml_descendants` | 83 | 5.8s |  |
| 1185 | `xml_duplicate_attribute` | 14 | 5.7s |  |
| 1186 | `xml_elements` | 6 | 5.7s |  |
| 1187 | `xml_equals_namespace_check` | 2 | 5.7s |  |
| 1188 | `xml_explicit_use_namespace` | 5 | 5.7s |  |
| 1189 | `xml_getdescendants_qname` | 21 | 5.7s |  |
| 1190 | `xml_has_property_via_in` | 26 | 5.6s |  |
| 1191 | `xml_hasownproperty` | 6 | 5.7s |  |
| 1192 | `xml_ignore_white` | 6 | 5.7s |  |
| 1193 | `xml_length` | 2 | 5.7s |  |
| 1194 | `xml_list_as_attribute` | 9 | 5.8s |  |
| 1195 | `xml_list_concat` | 20 | 5.8s |  |
| 1196 | `xml_list_ctor_errors` | 34 | 5.7s |  |
| 1197 | `xml_list_delete_clear_parent` | 6 | 5.6s |  |
| 1198 | `xml_list_enumerate` | 4 | 5.8s |  |
| 1199 | `xml_methods_settings` | 3 | 5.7s |  |
| 1200 | `xml_mismatched_tag` | 37 | 5.8s |  |
| 1201 | `xml_namespace` | 39 | 5.8s |  |
| 1202 | `xml_namespace_methods` | 245 | 6.0s |  |
| 1203 | `xml_namespaced_property` | 7 | 5.8s |  |
| 1204 | `xml_no_namespace` | 1 | 5.6s |  |
| 1205 | `xml_nodekind` | 3 | 5.6s |  |
| 1206 | `xml_normalize` | 35 | 5.6s |  |
| 1207 | `xml_notification_bubbling` | 361 | 5.6s |  |
| 1208 | `xml_parent` | 8 | 5.7s |  |
| 1209 | `xml_set_children` | 17 | 5.7s |  |
| 1210 | `xml_set_name` | 34 | 5.9s |  |
| 1211 | `xml_settings` | 6 | 1.2s |  |
| 1212 | `xml_simple_complex_content` | 47 | 5.7s |  |
| 1213 | `xml_socket` | 11 | 5.8s |  |
| 1214 | `xml_text` | 7 | 5.7s |  |
| 1215 | `xml_tostring` | 6 | 5.6s |  |
| 1216 | `xml_tostring_namespace` | 12 | 5.6s |  |
| 1217 | `xml_unescaping` | 23 | 5.6s |  |
| 1218 | `xml_weird_ignores` | 54 | 5.6s |  |
| 1219 | `xml_wildcard` | 11 | 5.7s |  |
| 1220 | `xmldocument` | 254 | 5.6s |  |
| 1221 | `xmlnode` | 3540 | 5.6s |  |
| 1222 | `zero_frame_clip` | 3 | 6.1s |  |

## Ruffle-Matched Tests

**41 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.8s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.1s |  |
| 3 | `blend_transform` | 1 | 1 | 8.8s |  |
| 4 | `bounds_mode` | 6 | 6 | 9.1s |  |
| 5 | `coerce_property` | 3 | 3 | 9.5s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 9.5s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 6.8s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 29.3s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 8.9s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 9.3s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 9.1s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 9.0s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.7s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 5.8s |  |
| 15 | `event_handler_exception` | 4 | 4 | 5.7s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 7.2s |  |
| 17 | `goto_framescript_queued/swf13` | 3 | 3 | 1.3s |  |
| 18 | `gradient_values_readback` | 12 | 12 | 7.4s |  |
| 19 | `graphics_draw_path` | 50 | 50 | 24.1s |  |
| 20 | `groupelement_text` | 2 | 2 | 7.4s |  |
| 21 | `int_toexponential` | 76 | 76 | 9.1s |  |
| 22 | `json_parse_numbers` | 4 | 79 | 7.1s |  |
| 23 | `loader_events_2` | 30 | 30 | 7.9s |  |
| 24 | `matrix3d_recompose_edge_cases` | 8 | 85 | 7.6s |  |
| 25 | `number_convert_errors` | 706 | 706 | 9.2s |  |
| 26 | `number_to_string` | 104 | 104 | 9.5s |  |
| 27 | `simplebutton_childevents_multichild` | 101 | 101 | 7.4s |  |
| 28 | `simplebutton_childevents_script_order` | 4 | 4 | 7.3s |  |
| 29 | `slot_holes_fail` | 1 | 1 | 7.7s |  |
| 30 | `slot_id_exceeds_trait_count` | 1 | 1 | 7.5s |  |
| 31 | `soundchannel_position` | 74 | 74 | 18.4s |  |
| 32 | `soundchannel_soundcomplete` | 10 | 10 | 5.8s |  |
| 33 | `sprite_dropTarget` | 15 | 15 | 5.6s |  |
| 34 | `swf_9_goto_in_construct_frame` | 12 | 12 | 29.1s |  |
| 35 | `textblock_line_changes` | 44 | 44 | 6.8s |  |
| 36 | `textblock_recreateline` | 139 | 140 | 6.8s |  |
| 37 | `textblock_releaselines` | 4 | 4 | 6.8s |  |
| 38 | `textline_atom_index_at_char_index` | 3 | 3 | 6.8s |  |
| 39 | `uint_toexponential` | 100 | 100 | 9.1s |  |
| 40 | `uncaught_errors_stringified` | 15 | 15 | 8.8s |  |
| 41 | `weird_superinterface_properties` | 1 | 1 | 9.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 3 | `html_text_img_parsing` | 67.4% | 118 | 175 | 57 |  |
| 4 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 5 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 6 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**21 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 3 | `html_text_img_parsing` | 67.4% | 118/175 | 175 | 175 |  |
| 4 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 5 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 6 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 7 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 8 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 9 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 10 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 11 | `goto_queued_invalid/swf9` | 6.2% | 2/32 | 9 | 32 |  |
| 12 | `goto_queued_invalid/swf10` | 5.9% | 2/34 | 9 | 34 |  |
| 13 | `goto_queued_invalid/swf11` | 4.7% | 2/43 | 9 | 43 |  |
| 14 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 15 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 16 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 17 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 18 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 19 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 20 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 21 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
