# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-04 10:43 UTC

**Git SHA**: `8b69f982f7`

**Run Duration**: 192m 37s

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
| 1 | `abstract_classes` | 132 | 16.0s |  |
| 2 | `accessibility` | 1 | 7.3s |  |
| 3 | `accessibilityimplementation` | 18 | 7.4s |  |
| 4 | `activation_class` | 6 | 7.3s |  |
| 5 | `add` | 1058 | 18.5s |  |
| 6 | `agal_compiler` | 13 | 10.3s |  |
| 7 | `air_datagram_socket` | 1 | 9.4s |  |
| 8 | `air_hidden_lookup` | 2 | 7.3s |  |
| 9 | `air_ifilepromise` | 1 | 7.3s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 7.4s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.7s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.6s |  |
| 13 | `all_classes/display/swf10` | 2569 | 7.4s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.7s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.7s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.7s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.7s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.6s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 7.4s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.6s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.6s |  |
| 22 | `all_classes/errors/swf10` | 140 | 7.3s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.6s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.6s |  |
| 25 | `all_classes/events/swf10` | 1638 | 7.5s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.6s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.6s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.7s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.6s |  |
| 30 | `all_classes/security/swf11` | 3 | 7.4s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.6s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.6s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.6s |  |
| 34 | `all_classes/xml/swf30` | 116 | 7.4s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.6s |  |
| 36 | `amf_array_serialization` | 17 | 29.3s |  |
| 37 | `amf_custom_obj` | 26 | 7.5s |  |
| 38 | `amf_dictionary` | 9 | 7.3s |  |
| 39 | `amf_function` | 46 | 7.4s |  |
| 40 | `amf_invalid_date` | 2 | 7.3s |  |
| 41 | `amf_missing_prop` | 6 | 7.3s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 7.4s |  |
| 43 | `amf_setter_error` | 8 | 7.5s |  |
| 44 | `amf_vector` | 40 | 13.6s |  |
| 45 | `amf_xml` | 6 | 6.5s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 6.9s |  |
| 47 | `application_domain` | 4 | 6.3s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 6.4s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 6.3s |  |
| 50 | `array_access` | 18 | 6.3s |  |
| 51 | `array_access_interpreter` | 4 | 6.3s |  |
| 52 | `array_access_no_pubns` | 2 | 6.2s |  |
| 53 | `array_concat` | 41 | 6.3s |  |
| 54 | `array_constr` | 10 | 6.3s |  |
| 55 | `array_delete` | 44 | 6.3s |  |
| 56 | `array_enumeration` | 10 | 6.2s |  |
| 57 | `array_enumeration_elements` | 11 | 6.3s |  |
| 58 | `array_every` | 8 | 6.2s |  |
| 59 | `array_filter` | 6 | 6.3s |  |
| 60 | `array_foreach` | 18 | 6.4s |  |
| 61 | `array_hasownproperty` | 11 | 6.3s |  |
| 62 | `array_holes` | 9 | 6.3s |  |
| 63 | `array_index_max` | 84 | 6.3s |  |
| 64 | `array_indexof` | 25 | 6.3s |  |
| 65 | `array_join` | 26 | 6.4s |  |
| 66 | `array_lastindexof` | 29 | 6.6s |  |
| 67 | `array_length` | 14 | 6.5s |  |
| 68 | `array_literal` | 3 | 6.3s |  |
| 69 | `array_map` | 8 | 6.2s |  |
| 70 | `array_pop` | 52 | 6.5s |  |
| 71 | `array_push` | 24 | 6.3s |  |
| 72 | `array_reborrow_bug` | 6 | 6.3s |  |
| 73 | `array_reverse` | 28 | 6.4s |  |
| 74 | `array_shift` | 51 | 2.4s |  |
| 75 | `array_slice` | 39 | 6.6s |  |
| 76 | `array_some` | 8 | 6.8s |  |
| 77 | `array_sort` | 297 | 7.0s |  |
| 78 | `array_sort_fun_swf12` | 2 | 6.4s |  |
| 79 | `array_sort_fun_swf13` | 2 | 0.6s |  |
| 80 | `array_sort_random` | 210 | 6.4s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 6.3s |  |
| 82 | `array_sorton` | 545 | 7.4s |  |
| 83 | `array_sparse_ops` | 41 | 6.6s |  |
| 84 | `array_splice` | 133 | 6.5s |  |
| 85 | `array_splice2` | 428 | 10.4s |  |
| 86 | `array_splice_types` | 48 | 4.7s |  |
| 87 | `array_storage` | 8 | 4.8s |  |
| 88 | `array_tolocalestring` | 9 | 4.7s |  |
| 89 | `array_tostring` | 12 | 4.7s |  |
| 90 | `array_unshift` | 24 | 4.8s |  |
| 91 | `array_valueof` | 9 | 4.6s |  |
| 92 | `array_vector_null_callback` | 10 | 4.7s |  |
| 93 | `astype` | 28 | 4.7s |  |
| 94 | `astypelate` | 24 | 4.9s |  |
| 95 | `astypelate_propagates` | 1 | 4.6s |  |
| 96 | `asymmetric_key_events` | 11 | 4.8s |  |
| 97 | `automation_classes` | 122 | 4.9s |  |
| 98 | `av_classes` | 340 | 4.9s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 4.9s |  |
| 100 | `avm2_catchup_dobj` | 158 | 5.2s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 61.5s |  |
| 102 | `bevel_filter` | 187 | 4.8s |  |
| 103 | `bitand` | 1058 | 11.2s |  |
| 104 | `bitmap_constr` | 17 | 5.0s |  |
| 105 | `bitmap_data` | 1000 | 11.2s |  |
| 106 | `bitmap_filter_abstract` | 6 | 4.9s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 17.4s |  |
| 108 | `bitmap_properties` | 23 | 4.8s |  |
| 109 | `bitmap_subclass` | 7 | 6.3s |  |
| 110 | `bitmap_subclass_properties` | 9 | 5.3s |  |
| 111 | `bitmap_timeline` | 9 | 5.2s |  |
| 112 | `bitmapdata_accuracy` | 1 | 34.8s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 18.7s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.3s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 18.1s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 19.2s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 18.3s |  |
| 118 | `bitmapdata_clone` | 13 | 5.1s |  |
| 119 | `bitmapdata_colortransform` | 0 | 5.2s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 4.9s |  |
| 121 | `bitmapdata_constr` | 22 | 4.9s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 5.1s |  |
| 123 | `bitmapdata_copychannel` | 0 | 18.9s |  |
| 124 | `bitmapdata_copypixels` | 23 | 17.6s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 4.9s |  |
| 126 | `bitmapdata_copypixels_alpha_merge` | 9 | 17.1s |  |
| 127 | `bitmapdata_copypixels_blend` | 1029 | 8.5s |  |
| 128 | `bitmapdata_copypixels_blend_over` | 1 | 8.0s |  |
| 129 | `bitmapdata_copypixels_self` | 612 | 8.0s |  |
| 130 | `bitmapdata_copypixelstobytearray` | 39 | 8.0s |  |
| 131 | `bitmapdata_dispose` | 7 | 7.9s |  |
| 132 | `bitmapdata_draw` | 0 | 29.7s |  |
| 133 | `bitmapdata_draw_alpha_erase` | 8 | 7.9s |  |
| 134 | `bitmapdata_draw_cab_quality` | 0 | 30.8s |  |
| 135 | `bitmapdata_draw_colortransform` | 0 | 7.9s |  |
| 136 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 8.2s |  |
| 137 | `bitmapdata_draw_filters` | 0 | 29.8s |  |
| 138 | `bitmapdata_draw_masks` | 0 | 7.9s |  |
| 139 | `bitmapdata_draw_rotation` | 0 | 7.9s |  |
| 140 | `bitmapdata_draw_self_via_graphic` | 0 | 7.9s |  |
| 141 | `bitmapdata_draw_stage` | 0 | 29.0s |  |
| 142 | `bitmapdata_drawwithquality` | 0 | 8.1s |  |
| 143 | `bitmapdata_embedded` | 9 | 7.8s |  |
| 144 | `bitmapdata_fillrect` | 0 | 7.7s |  |
| 145 | `bitmapdata_filter_sourcerect` | 0 | 27.7s |  |
| 146 | `bitmapdata_floodfill` | 35 | 7.5s |  |
| 147 | `bitmapdata_getpixels` | 39 | 27.8s |  |
| 148 | `bitmapdata_getvector` | 27 | 2.5s |  |
| 149 | `bitmapdata_histogram` | 59 | 2.5s |  |
| 150 | `bitmapdata_hittest` | 112 | 8.1s |  |
| 151 | `bitmapdata_hittest_threshold` | 18 | 7.6s |  |
| 152 | `bitmapdata_opaque` | 0 | 7.5s |  |
| 153 | `bitmapdata_pixeldissolve` | 1037 | 8.2s |  |
| 154 | `bitmapdata_pixeldissolve_image` | 0 | 7.9s |  |
| 155 | `bitmapdata_rectangle_rounding` | 16 | 7.5s |  |
| 156 | `bitmapdata_setpixels` | 286 | 7.6s |  |
| 157 | `bitmapdata_setvector` | 26 | 8.0s |  |
| 158 | `bitmapdata_sync` | 0 | 28.6s |  |
| 159 | `bitmapdata_threshold` | 176 | 8.5s |  |
| 160 | `bitmapdata_zero_size` | 8 | 7.6s |  |
| 161 | `bitnot` | 46 | 7.8s |  |
| 162 | `bitor` | 1058 | 19.3s |  |
| 163 | `bitxor` | 1058 | 19.0s |  |
| 164 | `blend_mode_null` | 1 | 7.5s |  |
| 165 | `blend_multiply_alpha` | 0 | 7.6s |  |
| 166 | `blend_scroll` | 0 | 7.6s |  |
| 167 | `blend_shader_luma_lighten` | 3 | 7.7s |  |
| 168 | `blur_filter` | 43 | 7.5s |  |
| 169 | `boolean_constr` | 32 | 7.4s |  |
| 170 | `boolean_negation` | 30 | 7.4s |  |
| 171 | `boolean_tostring` | 8 | 7.4s |  |
| 172 | `broadcast_event` | 7 | 7.2s |  |
| 173 | `button_bounds` | 1 | 7.6s |  |
| 174 | `button_hittest` | 2 | 27.6s |  |
| 175 | `button_nested_frame` | 48 | 7.9s |  |
| 176 | `button_nested_frame_simple` | 27 | 7.9s |  |
| 177 | `bytearray` | 48 | 7.7s |  |
| 178 | `bytearray_bad_symbol_class` | 3 | 7.5s |  |
| 179 | `bytearray_bad_symbol_class_other_movie` | 6 | 7.9s |  |
| 180 | `bytearray_compress` | 31 | 7.5s |  |
| 181 | `bytearray_errors` | 24 | 7.8s |  |
| 182 | `bytearray_method_serialization` | 1 | 7.5s |  |
| 183 | `bytearray_oom` | 3 | 7.5s |  |
| 184 | `bytearray_readobject_amf0` | 50 | 7.5s |  |
| 185 | `bytearray_readobject_amf3` | 53 | 7.6s |  |
| 186 | `bytearray_readutf8bytes_with_bom` | 16 | 7.6s |  |
| 187 | `bytearray_serialization` | 3 | 7.6s |  |
| 188 | `bytearray_string_null` | 19 | 7.8s |  |
| 189 | `bytearray_tostring` | 15 | 7.5s |  |
| 190 | `bytearray_utf16` | 8 | 7.5s |  |
| 191 | `bytearray_writeobject` | 24 | 7.3s |  |
| 192 | `callee_in_initializer` | 6 | 7.5s |  |
| 193 | `callproplex_class` | 1 | 7.5s |  |
| 194 | `capabilities_resolution` | 8 | 29.0s |  |
| 195 | `casi32` | 166 | 7.6s |  |
| 196 | `catch_class` | 6 | 7.6s |  |
| 197 | `catch_scope_slot` | 7 | 7.7s |  |
| 198 | `checkfilter` | 4 | 2.5s |  |
| 199 | `class_call` | 32 | 7.7s |  |
| 200 | `class_cast_call` | 14 | 7.5s |  |
| 201 | `class_enumeration` | 4 | 7.5s |  |
| 202 | `class_has_own_property` | 2 | 7.5s |  |
| 203 | `class_init_interpreter_mode` | 1 | 7.4s |  |
| 204 | `class_is` | 32 | 7.5s |  |
| 205 | `class_methods` | 5 | 7.3s |  |
| 206 | `class_object_properties` | 10 | 7.4s |  |
| 207 | `class_singleton` | 18 | 7.5s |  |
| 208 | `class_supercalls_errors` | 35 | 7.6s |  |
| 209 | `class_supercalls_mismatched` | 26 | 7.5s |  |
| 210 | `class_superclass_wrong_order` | 1 | 7.4s |  |
| 211 | `class_to_locale_string` | 2 | 7.4s |  |
| 212 | `class_to_string` | 2 | 7.2s |  |
| 213 | `class_value_of` | 2 | 7.5s |  |
| 214 | `click_block` | 5 | 28.0s |  |
| 215 | `click_invisible` | 3 | 7.5s |  |
| 216 | `closures` | 12 | 7.5s |  |
| 217 | `coerce_return_type` | 40 | 7.6s |  |
| 218 | `coerce_return_type_fail` | 2 | 7.4s |  |
| 219 | `coerce_return_void` | 3 | 7.4s |  |
| 220 | `coerce_string` | 86 | 7.7s |  |
| 221 | `coerce_string_precision` | 28 | 7.5s |  |
| 222 | `coerce_to_primitive_side_effects` | 29 | 7.7s |  |
| 223 | `color_matrix_filter` | 19 | 7.7s |  |
| 224 | `construct_errors_swf10` | 8 | 7.6s |  |
| 225 | `construct_frame_list` | 22 | 7.7s |  |
| 226 | `construct_interface` | 3 | 7.5s |  |
| 227 | `constructor_call` | 3 | 7.7s |  |
| 228 | `constructors_vs_timeline` | 5 | 28.4s |  |
| 229 | `constructprop_dynamic_primitive` | 7 | 7.7s |  |
| 230 | `constructprop_method` | 2 | 7.6s |  |
| 231 | `constructsuper_null` | 2 | 2.5s |  |
| 232 | `content_element_basic` | 50 | 7.9s |  |
| 233 | `context3d_creation` | 9 | 7.7s |  |
| 234 | `control_flow_bool` | 4 | 7.6s |  |
| 235 | `control_flow_stricteq` | 8 | 7.7s |  |
| 236 | `convert_boolean` | 30 | 7.6s |  |
| 237 | `convert_integer` | 90 | 7.7s |  |
| 238 | `convert_number` | 56 | 7.6s |  |
| 239 | `convert_uinteger` | 90 | 7.7s |  |
| 240 | `convolution_filter` | 89 | 7.7s |  |
| 241 | `core_exceptions` | 47 | 8.9s |  |
| 242 | `cpool_index_invalid_bytecode_1` | 6 | 7.7s |  |
| 243 | `cpool_index_invalid_bytecode_2` | 3 | 7.5s |  |
| 244 | `cpool_index_invalid_bytecode_3` | 1 | 7.5s |  |
| 245 | `cross_api_version_call_newer` | 12 | 8.2s |  |
| 246 | `cross_api_version_call_older` | 12 | 7.9s |  |
| 247 | `cryptscore` | 11 | 7.7s |  |
| 248 | `currency_parse_result` | 7 | 7.5s |  |
| 249 | `date` | 30 | 8.3s |  |
| 250 | `date_parse` | 36 | 4.9s |  |
| 251 | `date_set_time_out_of_range` | 62 | 5.0s |  |
| 252 | `declocal` | 46 | 5.0s |  |
| 253 | `declocal_i` | 46 | 5.0s |  |
| 254 | `decode_uri` | 71 | 5.2s |  |
| 255 | `decrement` | 46 | 5.0s |  |
| 256 | `decrement_i` | 46 | 1.7s |  |
| 257 | `default_values` | 7 | 4.9s |  |
| 258 | `delayed_symbolclass` | 28 | 17.4s |  |
| 259 | `describe_type_basic` | 152 | 4.9s |  |
| 260 | `describe_type_json` | 301 | 5.0s |  |
| 261 | `describe_type_metadata` | 125 | 5.2s |  |
| 262 | `describe_type_native` | 23 | 5.0s |  |
| 263 | `dictionary_access` | 62 | 5.0s |  |
| 264 | `dictionary_access_no_pubns` | 2 | 4.8s |  |
| 265 | `dictionary_delete` | 101 | 5.3s |  |
| 266 | `dictionary_foreach` | 42 | 5.1s |  |
| 267 | `dictionary_hasownproperty` | 63 | 5.1s |  |
| 268 | `dictionary_in` | 62 | 5.1s |  |
| 269 | `dictionary_iter_modify` | 8 | 4.9s |  |
| 270 | `dictionary_namespaces` | 36 | 4.9s |  |
| 271 | `displacement_map_filter` | 61 | 5.1s |  |
| 272 | `displayobject_alpha` | 277 | 5.1s |  |
| 273 | `displayobject_blendmode` | 0 | 5.1s |  |
| 274 | `displayobject_colortransform_nested` | 0 | 5.2s |  |
| 275 | `displayobject_early_init` | 54 | 6.1s |  |
| 276 | `displayobject_filters` | 17 | 5.3s |  |
| 277 | `displayobject_from_enterframe` | 1 | 5.1s |  |
| 278 | `displayobject_getbounds_shape` | 0 | 17.4s |  |
| 279 | `displayobject_getrect` | 16 | 5.2s |  |
| 280 | `displayobject_height` | 6052 | 17.6s |  |
| 281 | `displayobject_hittestobject` | 32 | 4.8s |  |
| 282 | `displayobject_hittestpoint` | 49 | 5.0s |  |
| 283 | `displayobject_hittestpoint_boundary` | 65 | 17.7s |  |
| 284 | `displayobject_hittestpoint_root` | 13 | 5.1s |  |
| 285 | `displayobject_invalid_floats` | 60 | 5.1s |  |
| 286 | `displayobject_invalid_props` | 3 | 4.7s |  |
| 287 | `displayobject_mask` | 3 | 4.9s |  |
| 288 | `displayobject_mask_self_referential` | 0 | 4.8s |  |
| 289 | `displayobject_metaData` | 3 | 4.9s |  |
| 290 | `displayobject_name` | 22 | 4.9s |  |
| 291 | `displayobject_name_from_timeline` | 24 | 5.1s |  |
| 292 | `displayobject_opaque_background` | 6 | 4.7s |  |
| 293 | `displayobject_parent` | 12 | 4.8s |  |
| 294 | `displayobject_root` | 24 | 4.8s |  |
| 295 | `displayobject_rotation` | 1284 | 4.8s |  |
| 296 | `displayobject_scrollrect` | 33 | 5.0s |  |
| 297 | `displayobject_set_matrix_nested` | 0 | 4.8s |  |
| 298 | `displayobject_set_name_loaded` | 3 | 4.9s |  |
| 299 | `displayobject_subclass` | 2 | 4.6s |  |
| 300 | `displayobject_transform` | 89 | 4.9s |  |
| 301 | `displayobject_visible` | 23 | 4.7s |  |
| 302 | `displayobject_width` | 4852 | 17.0s |  |
| 303 | `displayobject_x` | 614 | 4.7s |  |
| 304 | `displayobject_y` | 617 | 4.9s |  |
| 305 | `displayobject_z` | 38 | 17.2s |  |
| 306 | `displayobjectcontainer_addchild` | 32 | 4.7s |  |
| 307 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.7s |  |
| 308 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.9s |  |
| 309 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.8s |  |
| 310 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.7s |  |
| 311 | `displayobjectcontainer_addchildat` | 42 | 4.7s |  |
| 312 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.8s |  |
| 313 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.8s |  |
| 314 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.8s |  |
| 315 | `displayobjectcontainer_contains` | 66 | 17.1s |  |
| 316 | `displayobjectcontainer_getchildat` | 4 | 4.8s |  |
| 317 | `displayobjectcontainer_getchildbyname` | 9 | 4.7s |  |
| 318 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.6s |  |
| 319 | `displayobjectcontainer_getchildindex` | 28 | 4.6s |  |
| 320 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 16.7s |  |
| 321 | `displayobjectcontainer_removechild` | 10 | 4.7s |  |
| 322 | `displayobjectcontainer_removechild_errors` | 4 | 4.7s |  |
| 323 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.8s |  |
| 324 | `displayobjectcontainer_removechildat` | 18 | 4.6s |  |
| 325 | `displayobjectcontainer_removechildren` | 51 | 5.0s |  |
| 326 | `displayobjectcontainer_setchildindex` | 42 | 4.7s |  |
| 327 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.1s |  |
| 328 | `displayobjectcontainer_swapchildren` | 42 | 4.9s |  |
| 329 | `displayobjectcontainer_swapchildrenat` | 42 | 4.9s |  |
| 330 | `displayobjectcontainer_timelineinstance` | 48 | 17.5s |  |
| 331 | `divide` | 1058 | 11.1s |  |
| 332 | `doabc_and_symbolclass_script_init_goto` | 7 | 18.1s |  |
| 333 | `doabc_and_symbolclass_script_init_normal` | 6 | 27.3s |  |
| 334 | `doabc_is_eager` | 1 | 26.9s |  |
| 335 | `documentclass` | 9 | 7.2s |  |
| 336 | `domain_memory` | 133 | 8.4s |  |
| 337 | `drag_drop` | 10 | 7.3s |  |
| 338 | `drop_shadow_filter` | 172 | 7.3s |  |
| 339 | `duplicate_defs` | 1 | 6.8s |  |
| 340 | `eager_init` | 1 | 7.1s |  |
| 341 | `east_asian_justifier_clone` | 8 | 7.1s |  |
| 342 | `edit_text_linkage` | 7 | 7.3s |  |
| 343 | `edittext_align` | 60 | 7.6s |  |
| 344 | `edittext_always_show_selection` | 0 | 27.2s |  |
| 345 | `edittext_antialiastype` | 296 | 7.5s |  |
| 346 | `edittext_at_point_methods_basic` | 16 | 8.4s |  |
| 347 | `edittext_autosize` | 39 | 7.7s |  |
| 348 | `edittext_autosize_align` | 0 | 27.4s |  |
| 349 | `edittext_autosize_height_dynamic` | 60 | 27.3s |  |
| 350 | `edittext_autosize_height_input` | 60 | 7.3s |  |
| 351 | `edittext_autosize_lazy_bounds_events` | 65 | 7.4s |  |
| 352 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.2s |  |
| 353 | `edittext_autosize_lazy_bounds_props` | 490 | 8.9s |  |
| 354 | `edittext_autosize_lazy_bounds_visual` | 0 | 7.2s |  |
| 355 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.3s |  |
| 356 | `edittext_bottom_scroll_v_basic` | 210 | 7.3s |  |
| 357 | `edittext_bounds_scale` | 24 | 26.9s |  |
| 358 | `edittext_bullet` | 30 | 7.3s |  |
| 359 | `edittext_default_format` | 221 | 7.6s |  |
| 360 | `edittext_default_format_empty` | 136 | 7.4s |  |
| 361 | `edittext_empty_text_format` | 7 | 7.2s |  |
| 362 | `edittext_focus_selection` | 5 | 7.1s |  |
| 363 | `edittext_font_size` | 45 | 7.3s |  |
| 364 | `edittext_format_empty_font` | 8 | 7.1s |  |
| 365 | `edittext_get_char_index_at_point` | 4 | 28.8s |  |
| 366 | `edittext_get_line_index_at_point` | 2 | 27.2s |  |
| 367 | `edittext_get_line_index_of_char` | 76 | 8.2s |  |
| 368 | `edittext_getcharboundaries` | 172 | 7.7s |  |
| 369 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.2s |  |
| 370 | `edittext_getcharboundaries_scroll` | 85 | 7.2s |  |
| 371 | `edittext_getlinemetrics` | 146 | 7.5s |  |
| 372 | `edittext_html` | 3101 | 7.6s |  |
| 373 | `edittext_html_condensewhite` | 487 | 7.8s |  |
| 374 | `edittext_html_entity` | 4 | 8.0s |  |
| 375 | `edittext_html_font_size_swf12` | 267 | 7.5s |  |
| 376 | `edittext_html_font_size_swf13` | 273 | 7.3s |  |
| 377 | `edittext_html_roundtrip` | 17 | 7.7s |  |
| 378 | `edittext_ime_focus_lost` | 9 | 28.1s |  |
| 379 | `edittext_input_control` | 12 | 7.6s |  |
| 380 | `edittext_leading` | 9 | 8.0s |  |
| 381 | `edittext_letter_spacing` | 15 | 7.7s |  |
| 382 | `edittext_line_methods` | 294 | 9.2s |  |
| 383 | `edittext_line_metrics` | 11 | 30.3s |  |
| 384 | `edittext_margins` | 25 | 7.9s |  |
| 385 | `edittext_max_scroll_h_basic` | 475 | 8.1s |  |
| 386 | `edittext_max_scroll_v_basic` | 1000 | 7.8s |  |
| 387 | `edittext_mouse_selection` | 363 | 29.7s |  |
| 388 | `edittext_mousedown` | 3 | 8.1s |  |
| 389 | `edittext_mouseenabled` | 26 | 7.7s |  |
| 390 | `edittext_newline_character` | 22 | 7.7s |  |
| 391 | `edittext_newline_stripping` | 64 | 14.8s |  |
| 392 | `edittext_newlines` | 30 | 7.7s |  |
| 393 | `edittext_paragraph_methods` | 257 | 7.6s |  |
| 394 | `edittext_paste_events` | 8 | 7.6s |  |
| 395 | `edittext_paste_maxchars` | 4 | 7.5s |  |
| 396 | `edittext_paste_restrict` | 16 | 7.3s |  |
| 397 | `edittext_restrict` | 191 | 7.5s |  |
| 398 | `edittext_restrict_events` | 22 | 7.6s |  |
| 399 | `edittext_scroll_event` | 37 | 8.0s |  |
| 400 | `edittext_scrollh` | 10 | 7.6s |  |
| 401 | `edittext_selected_text` | 9 | 7.5s |  |
| 402 | `edittext_set_html_same` | 17 | 7.6s |  |
| 403 | `edittext_set_text_vs_html` | 9 | 7.5s |  |
| 404 | `edittext_stylesheet` | 536 | 8.1s |  |
| 405 | `edittext_stylesheet_custom_tag` | 76 | 7.8s |  |
| 406 | `edittext_stylesheet_display` | 272 | 7.8s |  |
| 407 | `edittext_tag_indent` | 49 | 27.8s |  |
| 408 | `edittext_underline` | 40 | 7.8s |  |
| 409 | `edittext_width_height` | 103 | 8.0s |  |
| 410 | `edittext_wordwrap_word` | 150 | 7.7s |  |
| 411 | `edittext_wrap_breaks` | 2375 | 8.1s |  |
| 412 | `element_format_clone` | 44 | 7.7s |  |
| 413 | `element_format_constructor_order` | 64 | 2.7s |  |
| 414 | `element_format_properties` | 235 | 8.9s |  |
| 415 | `empty_bounds` | 1 | 7.5s |  |
| 416 | `encode_uri_surrogate_pair_invalid` | 8 | 7.7s |  |
| 417 | `encode_uri_surrogate_pair_swf11` | 15 | 7.2s |  |
| 418 | `equals` | 512 | 12.1s |  |
| 419 | `error_geterrormessage` | 779 | 7.8s |  |
| 420 | `error_prototype` | 15 | 7.6s |  |
| 421 | `error_stack_trace` | 45 | 7.5s |  |
| 422 | `error_stack_trace_debug_swf17` | 0 | 27.6s |  |
| 423 | `error_stack_trace_debug_swf18` | 0 | 7.3s |  |
| 424 | `error_stack_trace_edge_cases` | 6 | 7.5s |  |
| 425 | `error_stack_trace_release_swf17` | 0 | 2.5s |  |
| 426 | `error_stack_trace_release_swf18` | 0 | 7.3s |  |
| 427 | `error_throwerror` | 103 | 7.7s |  |
| 428 | `error_tostring` | 29 | 7.6s |  |
| 429 | `error_tostring_more` | 86 | 7.7s |  |
| 430 | `es3_inheritance` | 31 | 7.8s |  |
| 431 | `es4_inheritance` | 30 | 7.7s |  |
| 432 | `es4_interfaces` | 30 | 7.7s |  |
| 433 | `es4_method_binding` | 8 | 7.7s |  |
| 434 | `es4_oop_prototypes` | 14 | 7.8s |  |
| 435 | `es4_protected_inheritance` | 6 | 7.6s |  |
| 436 | `escape` | 71 | 7.6s |  |
| 437 | `escape_multi_byte` | 45 | 7.9s |  |
| 438 | `event_bubbles` | 2 | 7.5s |  |
| 439 | `event_cancelable` | 2 | 7.4s |  |
| 440 | `event_clone` | 20 | 7.7s |  |
| 441 | `event_clone_error_redispatch` | 3 | 7.7s |  |
| 442 | `event_clone_on_redispatch` | 10 | 7.7s |  |
| 443 | `event_formattostring` | 31 | 7.8s |  |
| 444 | `event_isdefaultprevented` | 12 | 7.5s |  |
| 445 | `event_target_getter` | 5 | 2.5s |  |
| 446 | `event_target_set` | 9 | 7.5s |  |
| 447 | `event_type` | 1 | 7.5s |  |
| 448 | `event_valueof_tostring` | 18 | 7.6s |  |
| 449 | `eventdispatcher_dispatchevent` | 12 | 7.5s |  |
| 450 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.5s |  |
| 451 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.6s |  |
| 452 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.6s |  |
| 453 | `eventdispatcher_dispatchevent_this` | 5 | 7.5s |  |
| 454 | `eventdispatcher_haseventlistener` | 25 | 7.5s |  |
| 455 | `eventdispatcher_interface_invoke` | 1 | 5.8s |  |
| 456 | `eventdispatcher_tostring` | 10 | 5.8s |  |
| 457 | `eventdispatcher_willtrigger` | 25 | 5.7s |  |
| 458 | `falsiness` | 30 | 5.8s |  |
| 459 | `fast_index_access` | 12 | 5.7s |  |
| 460 | `filefilter_properties` | 4 | 5.7s |  |
| 461 | `filereference_browse_cancel` | 3 | 5.8s |  |
| 462 | `filereference_browse_select` | 9 | 5.7s |  |
| 463 | `filereference_load` | 31 | 5.8s |  |
| 464 | `filereference_save` | 16 | 5.7s |  |
| 465 | `filereference_save_and_browse` | 42 | 5.8s |  |
| 466 | `filereference_save_and_load` | 22 | 5.8s |  |
| 467 | `filereference_uninitialized` | 8 | 5.7s |  |
| 468 | `filereferencelist_browse_cancel` | 6 | 5.8s |  |
| 469 | `filereferencelist_browse_select` | 7 | 5.8s |  |
| 470 | `filter_rewind` | 8 | 5.8s |  |
| 471 | `filters_array_holes` | 25 | 5.8s |  |
| 472 | `finddef` | 3 | 5.7s |  |
| 473 | `findprop_global_prototype` | 6 | 5.8s |  |
| 474 | `flash_media_video_constructor` | 156 | 5.7s |  |
| 475 | `flash_media_video_rotation_probe` | 27 | 5.7s |  |
| 476 | `flash_media_video_setter` | 40 | 5.9s |  |
| 477 | `flash_trace` | 17 | 5.9s |  |
| 478 | `flash_ui_mouse_cursor` | 35 | 5.8s |  |
| 479 | `flash_xml` | 29 | 5.8s |  |
| 480 | `flash_xml_cloneNode` | 22 | 5.8s |  |
| 481 | `flash_xml_namespace` | 109 | 5.8s |  |
| 482 | `flash_xml_removeNode` | 60 | 5.8s |  |
| 483 | `focus_events_code` | 161 | 5.8s |  |
| 484 | `focus_events_key_basic` | 132 | 5.8s |  |
| 485 | `focus_events_key_navigation` | 53 | 5.8s |  |
| 486 | `focus_events_key_same_object` | 26 | 5.9s |  |
| 487 | `focus_events_mixed_key_mouse` | 100 | 5.8s |  |
| 488 | `focus_events_mouse_basic` | 260 | 5.8s |  |
| 489 | `focus_events_mouse_focusable` | 112 | 5.8s |  |
| 490 | `focus_events_mouse_same_object` | 40 | 5.8s |  |
| 491 | `focus_remove` | 20 | 5.8s |  |
| 492 | `focus_root_movie` | 4 | 5.8s |  |
| 493 | `focus_stage` | 1 | 5.7s |  |
| 494 | `focusrect` | 18 | 5.8s |  |
| 495 | `focusrect_focuslost` | 9 | 5.8s |  |
| 496 | `focusrect_property` | 110 | 7.4s |  |
| 497 | `font_description_clone` | 14 | 7.5s |  |
| 498 | `font_embedded` | 24 | 8.1s |  |
| 499 | `font_enumeratefonts` | 41 | 8.2s |  |
| 500 | `font_enumeratefonts_filter` | 4 | 8.2s |  |
| 501 | `font_enumeratefonts_order` | 9 | 8.8s |  |
| 502 | `font_hasglyphs` | 40 | 8.0s |  |
| 503 | `font_registerfont` | 129 | 8.6s |  |
| 504 | `framelabel_constr` | 5 | 7.5s |  |
| 505 | `function_call` | 12 | 2.5s |  |
| 506 | `function_call_arguments` | 46 | 7.6s |  |
| 507 | `function_call_arguments_enumerate` | 5 | 7.4s |  |
| 508 | `function_call_coercion` | 108 | 7.8s |  |
| 509 | `function_call_default` | 6 | 7.3s |  |
| 510 | `function_call_rest` | 22 | 7.3s |  |
| 511 | `function_call_types` | 3 | 7.3s |  |
| 512 | `function_call_via_apply` | 11 | 7.3s |  |
| 513 | `function_call_via_call` | 3 | 7.3s |  |
| 514 | `function_display_anonymous` | 7 | 2.4s |  |
| 515 | `function_length` | 6 | 7.4s |  |
| 516 | `function_object` | 2 | 7.3s |  |
| 517 | `function_proto` | 5 | 7.3s |  |
| 518 | `function_proto_created` | 61 | 7.4s |  |
| 519 | `function_to_locale_string` | 4 | 7.3s |  |
| 520 | `function_to_string` | 4 | 7.2s |  |
| 521 | `function_type` | 6 | 7.4s |  |
| 522 | `function_unbound_this` | 51 | 7.5s |  |
| 523 | `function_value_of` | 4 | 7.1s |  |
| 524 | `game_input` | 4 | 7.4s |  |
| 525 | `generate_random_bytes` | 3 | 7.4s |  |
| 526 | `geom_transform` | 74 | 27.5s |  |
| 527 | `get_definition_by_name` | 11 | 7.4s |  |
| 528 | `get_qualified_class_name` | 20 | 7.4s |  |
| 529 | `get_qualified_super_class_name` | 18 | 7.4s |  |
| 530 | `get_slot_edge_cases` | 1 | 7.4s |  |
| 531 | `get_timer` | 2 | 2.4s |  |
| 532 | `getglobalslot` | 1 | 7.3s |  |
| 533 | `getouterscope` | 8 | 7.3s |  |
| 534 | `getouterscope_two_classobjects` | 13 | 7.4s |  |
| 535 | `getter_different_namespace_setter` | 2 | 7.1s |  |
| 536 | `glow_filter` | 127 | 7.6s |  |
| 537 | `goto_button_nested_framescript` | 28 | 7.7s |  |
| 538 | `goto_framescript_queued/swf10` | 59 | 27.4s |  |
| 539 | `goto_framescript_queued/swf9` | 52 | 0.7s |  |
| 540 | `goto_framescript_queued_same_frame` | 4 | 7.6s |  |
| 541 | `goto_in_constructframe` | 12 | 27.3s |  |
| 542 | `goto_in_scene_last_frame` | 2 | 27.0s |  |
| 543 | `goto_methods` | 56 | 7.8s |  |
| 544 | `goto_methods_swfver10` | 8 | 7.4s |  |
| 545 | `goto_nested_construct_sibling` | 18 | 7.9s |  |
| 546 | `goto_nested_framescript` | 9 | 7.7s |  |
| 547 | `goto_on_orphan` | 15 | 7.7s |  |
| 548 | `gradient_bevel_filter` | 206 | 7.6s |  |
| 549 | `gradient_glow_filter` | 206 | 7.3s |  |
| 550 | `graphic_linkage` | 9 | 7.6s |  |
| 551 | `graphics_bad_direct_commands` | 5 | 8.0s |  |
| 552 | `graphics_bitmap_fill` | 0 | 9.5s |  |
| 553 | `graphics_bitmaps` | 0 | 7.8s |  |
| 554 | `graphics_direct_commands` | 0 | 7.7s |  |
| 555 | `graphics_draw_triangles` | 98 | 28.3s |  |
| 556 | `graphics_gradients` | 0 | 7.6s |  |
| 557 | `graphics_gradients_nulls` | 0 | 7.4s |  |
| 558 | `graphics_path` | 56 | 7.5s |  |
| 559 | `graphics_round_rects` | 0 | 7.5s |  |
| 560 | `graphics_simple_shapes` | 0 | 7.4s |  |
| 561 | `greaterequals` | 512 | 11.7s |  |
| 562 | `greaterthan` | 512 | 11.8s |  |
| 563 | `has_own_property` | 102 | 8.1s |  |
| 564 | `hasownproperty_namespaces` | 2 | 7.4s |  |
| 565 | `hello_world` | 1 | 7.3s |  |
| 566 | `hittest_morph` | 30 | 7.6s |  |
| 567 | `id3_info` | 8 | 26.9s |  |
| 568 | `if_eq` | 10 | 7.5s |  |
| 569 | `if_gt` | 1 | 7.5s |  |
| 570 | `if_gte` | 10 | 2.5s |  |
| 571 | `if_lt` | 1 | 0.7s |  |
| 572 | `if_lte` | 10 | 7.3s |  |
| 573 | `if_ne` | 7 | 7.9s |  |
| 574 | `if_stricteq` | 6 | 7.9s |  |
| 575 | `if_strictne` | 11 | 7.9s |  |
| 576 | `ime_linux_dead_keys` | 10 | 7.9s |  |
| 577 | `in` | 102 | 8.5s |  |
| 578 | `inclocal` | 46 | 7.9s |  |
| 579 | `inclocal_i` | 46 | 7.9s |  |
| 580 | `increment` | 46 | 7.9s |  |
| 581 | `increment_i` | 46 | 7.9s |  |
| 582 | `indexing_delete` | 75 | 7.5s |  |
| 583 | `indexof_xml` | 10 | 7.7s |  |
| 584 | `init_callee_cached` | 24 | 7.5s |  |
| 585 | `instanceof` | 58 | 7.9s |  |
| 586 | `instantiate_root_character` | 4 | 7.7s |  |
| 587 | `instantiation_on_enter_frame` | 7 | 27.8s |  |
| 588 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.5s |  |
| 589 | `int_constr` | 92 | 7.7s |  |
| 590 | `int_edge_cases` | 19 | 7.5s |  |
| 591 | `int_instanceof` | 3 | 7.3s |  |
| 592 | `int_tofixed` | 1215 | 7.4s |  |
| 593 | `int_toprecision` | 1125 | 7.7s |  |
| 594 | `int_tostring` | 3375 | 7.9s |  |
| 595 | `interactiveobject_enabled` | 25 | 7.6s |  |
| 596 | `interface_namespaces` | 78 | 7.8s |  |
| 597 | `invalid_utf8` | 12 | 7.7s |  |
| 598 | `is_finite` | 46 | 7.6s |  |
| 599 | `is_nan` | 46 | 7.3s |  |
| 600 | `is_prototype_of` | 12 | 7.5s |  |
| 601 | `issue_10221` | 2 | 7.4s |  |
| 602 | `issue_13780` | 12 | 7.4s |  |
| 603 | `issue_14901` | 1 | 7.4s |  |
| 604 | `issue_17675_edittext_paste_maxchars` | 1 | 7.4s |  |
| 605 | `issue_5292` | 5 | 7.2s |  |
| 606 | `issue_8630` | 2 | 7.4s |  |
| 607 | `issue_8630_placeremoveplace` | 15 | 7.6s |  |
| 608 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.3s |  |
| 609 | `issue_8630_scriptremove` | 11 | 7.4s |  |
| 610 | `istype` | 24 | 2.6s |  |
| 611 | `istypelate` | 58 | 7.8s |  |
| 612 | `istypelate_coerce` | 198 | 8.7s |  |
| 613 | `jpeg_loader_context` | 6 | 7.3s |  |
| 614 | `json_errors` | 9 | 27.1s |  |
| 615 | `json_parse` | 21 | 10.9s |  |
| 616 | `json_parse_errors` | 84 | 4.9s |  |
| 617 | `json_stringify` | 12 | 5.0s |  |
| 618 | `json_stringify_function` | 12 | 5.0s |  |
| 619 | `json_stringify_order` | 1 | 4.9s |  |
| 620 | `json_version_gated` | 1 | 5.0s |  |
| 621 | `key_input_80percent` | 1812 | 5.1s |  |
| 622 | `key_input_location` | 126 | 5.1s |  |
| 623 | `key_input_numpad` | 384 | 5.1s |  |
| 624 | `large_preload_from_bytes` | 51 | 7.5s |  |
| 625 | `large_preload_from_url` | 27 | 6.3s |  |
| 626 | `large_preload_image_from_bytes` | 25 | 5.3s |  |
| 627 | `lazyinit` | 17 | 4.9s |  |
| 628 | `lessequals` | 512 | 7.7s |  |
| 629 | `lessthan` | 512 | 7.9s |  |
| 630 | `loader_bitmap_transparency` | 14 | 5.3s |  |
| 631 | `loader_bytes_unknown_content` | 14 | 5.3s |  |
| 632 | `loader_child_getdefinition` | 5 | 5.1s |  |
| 633 | `loader_duplicate_class` | 48 | 6.6s |  |
| 634 | `loader_duplicate_coerce` | 3 | 5.2s |  |
| 635 | `loader_duplicate_coerce_new_domain` | 4 | 5.0s |  |
| 636 | `loader_error_in_root_ctor` | 4 | 5.0s |  |
| 637 | `loader_events` | 92 | 5.5s |  |
| 638 | `loader_image` | 8 | 5.1s |  |
| 639 | `loader_jpegxr` | 2 | 18.0s |  |
| 640 | `loader_jpegxr_alpha` | 1 | 17.5s |  |
| 641 | `loader_loadbytes_events` | 30 | 5.6s |  |
| 642 | `loader_loadbytes_invalid_png` | 4 | 5.0s |  |
| 643 | `loader_loadbytes_url` | 12 | 5.2s |  |
| 644 | `loader_loaderurl` | 6 | 5.5s |  |
| 645 | `loader_method` | 85 | 5.1s |  |
| 646 | `loader_noninteractive_try_click_root` | 5 | 18.2s |  |
| 647 | `loader_reuse` | 38 | 5.2s |  |
| 648 | `loader_try_click_root` | 16 | 5.0s |  |
| 649 | `loader_unknown_content` | 24 | 5.1s |  |
| 650 | `loader_visibility_interactive` | 1 | 4.9s |  |
| 651 | `loaderinfo_events` | 7 | 4.8s |  |
| 652 | `loaderinfo_loadurl` | 12 | 4.9s |  |
| 653 | `loaderinfo_more` | 6 | 5.1s |  |
| 654 | `loaderinfo_properties` | 18 | 16.6s |  |
| 655 | `loaderinfo_properties_not_loaded` | 23 | 7.6s |  |
| 656 | `loaderinfo_quine` | 1005 | 7.3s |  |
| 657 | `loaderinfo_root` | 10 | 7.4s |  |
| 658 | `loaderinfo_root_allows` | 2 | 7.3s |  |
| 659 | `localconnection` | 890 | 9.6s |  |
| 660 | `localconnection_send` | 4 | 7.4s |  |
| 661 | `lshift` | 1058 | 18.7s |  |
| 662 | `mask_reapply` | 1 | 26.7s |  |
| 663 | `math` | 497 | 7.7s |  |
| 664 | `matrix` | 338 | 19.1s |  |
| 665 | `matrix3d` | 57 | 8.2s |  |
| 666 | `matrix3d_append` | 16 | 7.4s |  |
| 667 | `matrix3d_append_prepend_scale` | 86 | 7.5s |  |
| 668 | `matrix3d_append_prepend_translation` | 42 | 7.4s |  |
| 669 | `matrix3d_append_rotation` | 23 | 7.5s |  |
| 670 | `matrix3d_compose` | 34 | 7.6s |  |
| 671 | `matrix3d_constructor_clone` | 15 | 7.3s |  |
| 672 | `matrix3d_copy_column` | 83 | 7.7s |  |
| 673 | `matrix3d_copy_from` | 19 | 7.3s |  |
| 674 | `matrix3d_copy_raw_data_from` | 55 | 2.7s |  |
| 675 | `matrix3d_copy_raw_data_to` | 38 | 7.8s |  |
| 676 | `matrix3d_copy_row` | 83 | 7.2s |  |
| 677 | `matrix3d_copy_to_matrix3d` | 19 | 7.4s |  |
| 678 | `matrix3d_determinant` | 182 | 7.5s |  |
| 679 | `matrix3d_interpolate` | 21 | 7.6s |  |
| 680 | `matrix3d_invert` | 18 | 7.4s |  |
| 681 | `matrix3d_position` | 19 | 7.4s |  |
| 682 | `matrix3d_precision` | 28 | 7.5s |  |
| 683 | `matrix3d_prepend` | 16 | 7.2s |  |
| 684 | `matrix3d_raw_data` | 33 | 7.5s |  |
| 685 | `matrix3d_transform_vector` | 52 | 7.7s |  |
| 686 | `matrix3d_transpose` | 5 | 7.3s |  |
| 687 | `method_association` | 5 | 7.4s |  |
| 688 | `method_without_body` | 3 | 26.6s |  |
| 689 | `missing_external_interface` | 10 | 7.3s |  |
| 690 | `modulo` | 1058 | 18.6s |  |
| 691 | `morph_shape` | 2 | 26.9s |  |
| 692 | `mouse_children` | 192 | 26.9s |  |
| 693 | `mouse_click_events` | 90 | 26.9s |  |
| 694 | `mouse_double_click_events` | 188 | 7.4s |  |
| 695 | `mouse_empty_parent` | 4 | 7.3s |  |
| 696 | `mouse_over_while_dragging` | 3 | 16.9s |  |
| 697 | `mouse_pick_avm1_root` | 2 | 8.1s |  |
| 698 | `mouse_pick_button_mode` | 2 | 7.9s |  |
| 699 | `mouse_pick_dobj_mask` | 4 | 8.0s |  |
| 700 | `mouse_pick_masking` | 7 | 28.9s |  |
| 701 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 7.9s |  |
| 702 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.9s |  |
| 703 | `mouse_pick_text` | 8 | 8.0s |  |
| 704 | `mouse_sibling` | 8 | 7.9s |  |
| 705 | `mouse_wheel_events` | 36 | 9.1s |  |
| 706 | `mouseevent_constr` | 66 | 7.9s |  |
| 707 | `mouseevent_stagexy` | 35 | 7.9s |  |
| 708 | `mouseevent_valueof_tostring` | 28 | 7.7s |  |
| 709 | `movieclip_addframescript` | 3 | 28.2s |  |
| 710 | `movieclip_addframescript_error` | 9 | 7.8s |  |
| 711 | `movieclip_child_property` | 16 | 7.9s |  |
| 712 | `movieclip_constr` | 21 | 7.8s |  |
| 713 | `movieclip_currentlabels` | 17 | 28.1s |  |
| 714 | `movieclip_currentlabels_dupes1` | 46 | 28.3s |  |
| 715 | `movieclip_currentlabels_dupes2` | 30 | 7.8s |  |
| 716 | `movieclip_currentlabels_dupes3` | 67 | 7.8s |  |
| 717 | `movieclip_currentscene` | 12 | 28.0s |  |
| 718 | `movieclip_dispatchevent` | 430 | 7.9s |  |
| 719 | `movieclip_dispatchevent_cancel` | 102 | 7.9s |  |
| 720 | `movieclip_dispatchevent_handlerorder` | 251 | 7.8s |  |
| 721 | `movieclip_dispatchevent_selfadd` | 80 | 7.8s |  |
| 722 | `movieclip_dispatchevent_target` | 899 | 7.9s |  |
| 723 | `movieclip_displayevents` | 96 | 28.6s |  |
| 724 | `movieclip_displayevents_clickgoto` | 676 | 8.5s |  |
| 725 | `movieclip_displayevents_clickgoto2` | 2001 | 8.5s |  |
| 726 | `movieclip_displayevents_clickplay` | 575 | 8.1s |  |
| 727 | `movieclip_displayevents_clicksymbol` | 562 | 8.1s |  |
| 728 | `movieclip_displayevents_constructframegoto` | 140 | 8.3s |  |
| 729 | `movieclip_displayevents_constructframeplay` | 50 | 8.1s |  |
| 730 | `movieclip_displayevents_constructframesymbol` | 144 | 8.0s |  |
| 731 | `movieclip_displayevents_dblhandler` | 21 | 7.8s |  |
| 732 | `movieclip_displayevents_enterframegoto` | 149 | 8.2s |  |
| 733 | `movieclip_displayevents_enterframeplay` | 48 | 7.9s |  |
| 734 | `movieclip_displayevents_enterframesymbol` | 149 | 28.5s |  |
| 735 | `movieclip_displayevents_exitframegoto` | 106 | 7.9s |  |
| 736 | `movieclip_displayevents_exitframeplay` | 44 | 7.9s |  |
| 737 | `movieclip_displayevents_exitframesymbol` | 135 | 8.1s |  |
| 738 | `movieclip_displayevents_looping` | 63 | 38.1s |  |
| 739 | `movieclip_displayevents_stopped` | 113 | 29.0s |  |
| 740 | `movieclip_displayevents_swap` | 96 | 28.7s |  |
| 741 | `movieclip_displayevents_timeline` | 128 | 29.8s |  |
| 742 | `movieclip_drawrect` | 54 | 7.8s |  |
| 743 | `movieclip_frameconstruct_skipped` | 9 | 7.7s |  |
| 744 | `movieclip_goto_during_frame_script` | 15 | 7.8s |  |
| 745 | `movieclip_goto_overwrite` | 14 | 28.3s |  |
| 746 | `movieclip_goto_scene_last_frame_int` | 1 | 28.4s |  |
| 747 | `movieclip_goto_scene_last_frame_label` | 1 | 7.6s |  |
| 748 | `movieclip_gotoandplay` | 15 | 28.6s |  |
| 749 | `movieclip_gotoandstop` | 13 | 7.7s |  |
| 750 | `movieclip_gotoandstop_children` | 4 | 7.8s |  |
| 751 | `movieclip_gotoandstop_framescripts1` | 4 | 7.5s |  |
| 752 | `movieclip_gotoandstop_framescripts2` | 4 | 2.5s |  |
| 753 | `movieclip_gotoandstop_framescripts_self` | 7 | 7.5s |  |
| 754 | `movieclip_gotoandstop_queueing` | 12 | 7.6s |  |
| 755 | `movieclip_hittest` | 67 | 7.8s |  |
| 756 | `movieclip_next_frame` | 2 | 7.5s |  |
| 757 | `movieclip_next_scene` | 6 | 7.5s |  |
| 758 | `movieclip_play` | 3 | 7.3s |  |
| 759 | `movieclip_prev_frame` | 3 | 7.2s |  |
| 760 | `movieclip_prev_scene` | 7 | 7.4s |  |
| 761 | `movieclip_properties` | 79 | 27.2s |  |
| 762 | `movieclip_queued_noop_goto_swf10` | 9 | 7.4s |  |
| 763 | `movieclip_queued_noop_goto_swf9` | 7 | 0.7s |  |
| 764 | `movieclip_scenes` | 11 | 7.3s |  |
| 765 | `movieclip_soundtransform` | 831 | 29.4s |  |
| 766 | `movieclip_stop` | 1 | 7.3s |  |
| 767 | `movieclip_super_is_symbol` | 20 | 7.9s |  |
| 768 | `movieclip_symbol_constr` | 8 | 7.7s |  |
| 769 | `movieclip_text_mousedown` | 1 | 7.5s |  |
| 770 | `movieclip_willtrigger` | 5 | 7.6s |  |
| 771 | `multiply` | 1058 | 18.9s |  |
| 772 | `namespace_constr` | 253 | 7.9s |  |
| 773 | `namespace_constr_args` | 1 | 7.4s |  |
| 774 | `namespace_enumeration_order` | 7 | 7.4s |  |
| 775 | `nan_scale` | 9 | 7.5s |  |
| 776 | `native_menu_basic` | 19 | 9.8s |  |
| 777 | `navigateToURL_target_normalize` | 107 | 29.3s |  |
| 778 | `negate` | 30 | 7.4s |  |
| 779 | `negative_volume_panned` | 0 | 7.7s |  |
| 780 | `nested_iteration` | 11 | 7.4s |  |
| 781 | `net_getClassByAlias` | 3 | 16.6s |  |
| 782 | `net_navigateToURL` | 57 | 30.9s |  |
| 783 | `net_stream_play_options` | 6 | 7.8s |  |
| 784 | `netconnection_close` | 55 | 7.8s |  |
| 785 | `netconnection_properties` | 78 | 7.9s |  |
| 786 | `netconnection_send_remote` | 50 | 29.0s |  |
| 787 | `netconnection_serialize_arrays` | 6 | 7.8s |  |
| 788 | `netfilterevent` | 10 | 7.8s |  |
| 789 | `netstream_client` | 10 | 8.0s |  |
| 790 | `netstream_connect` | 7 | 7.7s |  |
| 791 | `netstream_flv_date` | 4 | 7.7s |  |
| 792 | `newactivation_in_script_init` | 3 | 7.7s |  |
| 793 | `newclass_mismatched` | 4 | 7.7s |  |
| 794 | `newclass_twice` | 3 | 7.7s |  |
| 795 | `nonconflicting_declarations` | 0 | 7.7s |  |
| 796 | `null_void_types` | 8 | 7.5s |  |
| 797 | `number_autoconv` | 21 | 7.7s |  |
| 798 | `number_autoconv_amf` | 132 | 7.7s |  |
| 799 | `number_autoconv_array_sort_32bit` | 1 | 7.7s |  |
| 800 | `number_constr` | 58 | 7.8s |  |
| 801 | `number_convert_edge_cases` | 180 | 7.8s |  |
| 802 | `number_toexponential` | 378 | 7.8s |  |
| 803 | `number_toexponential2` | 35 | 7.7s |  |
| 804 | `number_tofixed` | 378 | 7.6s |  |
| 805 | `number_toprecision` | 350 | 7.8s |  |
| 806 | `obfuscated_class_names` | 3 | 7.7s |  |
| 807 | `object_enumeration` | 10 | 7.7s |  |
| 808 | `object_prototype` | 4 | 7.8s |  |
| 809 | `object_to_locale_string` | 2 | 7.7s |  |
| 810 | `object_to_string` | 2 | 7.4s |  |
| 811 | `object_value_of` | 2 | 2.4s |  |
| 812 | `op_coerce` | 54 | 7.8s |  |
| 813 | `op_coerce_x` | 54 | 7.7s |  |
| 814 | `op_escxattr` | 2 | 7.7s |  |
| 815 | `op_escxelem` | 2 | 7.7s |  |
| 816 | `op_lookupswitch` | 4 | 7.7s |  |
| 817 | `optimize_coerce` | 1 | 7.6s |  |
| 818 | `orphan_movie_complex` | 80 | 16.2s |  |
| 819 | `orphan_movie_reorder` | 111 | 27.3s |  |
| 820 | `orphan_removeobject` | 636 | 27.7s |  |
| 821 | `package_namespace` | 7 | 7.4s |  |
| 822 | `param_default_value_has_zero_cpool_index` | 1 | 7.3s |  |
| 823 | `parent_early_access_child` | 16 | 7.6s |  |
| 824 | `parse_float` | 81 | 7.6s |  |
| 825 | `parse_float_swf10` | 81 | 7.2s |  |
| 826 | `parse_int` | 135 | 7.9s |  |
| 827 | `perspective_projection` | 1443 | 7.8s |  |
| 828 | `perspective_projection_basic` | 40 | 7.4s |  |
| 829 | `pixelbender_ceil` | 77 | 7.6s |  |
| 830 | `pixelbender_conditional` | 138 | 7.6s |  |
| 831 | `pixelbender_conversions` | 270 | 7.7s |  |
| 832 | `pixelbender_dithering` | 8 | 31.7s |  |
| 833 | `pixelbender_div` | 36 | 7.6s |  |
| 834 | `pixelbender_effect_BlurredFocus` | 0 | 35.1s |  |
| 835 | `pixelbender_effect_glassDisplace` | 0 | 13.3s |  |
| 836 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 30.3s |  |
| 837 | `pixelbender_effect_smudge` | 0 | 10.9s |  |
| 838 | `pixelbender_effect_tintype` | 0 | 10.1s |  |
| 839 | `pixelbender_effect_twirl` | 0 | 11.5s |  |
| 840 | `pixelbender_eof` | 7 | 7.4s |  |
| 841 | `pixelbender_images` | 0 | 9.8s |  |
| 842 | `pixelbender_input` | 103 | 27.6s |  |
| 843 | `pixelbender_logicalnot` | 20 | 7.4s |  |
| 844 | `pixelbender_malformed_data` | 190 | 27.5s |  |
| 845 | `pixelbender_multiple_out_params` | 1 | 7.3s |  |
| 846 | `pixelbender_no_out_param` | 6 | 7.3s |  |
| 847 | `pixelbender_outputs` | 13 | 7.6s |  |
| 848 | `pixelbender_padding_bytes` | 22 | 7.5s |  |
| 849 | `pixelbender_param_qualifier` | 512 | 7.5s |  |
| 850 | `pixelbender_parameters` | 1563 | 7.9s |  |
| 851 | `pixelbender_parameters_bool` | 240 | 7.8s |  |
| 852 | `pixelbender_parameters_int_vs_bool` | 54 | 7.5s |  |
| 853 | `pixelbender_parse_errors` | 6 | 7.3s |  |
| 854 | `pixelbender_rsqrt` | 24 | 7.4s |  |
| 855 | `pixelbender_select_kinds` | 8 | 7.6s |  |
| 856 | `pixelbender_shaderdata` | 49 | 7.5s |  |
| 857 | `pixelbender_shaderdata_setter` | 99 | 7.9s |  |
| 858 | `pixelbender_sign` | 60 | 7.7s |  |
| 859 | `pixelbender_vector_output` | 11 | 7.6s |  |
| 860 | `place_and_lookup/swf10` | 33 | 7.5s |  |
| 861 | `place_and_lookup/swf9` | 33 | 16.2s |  |
| 862 | `place_multiple` | 17 | 7.6s |  |
| 863 | `place_object_replace` | 9 | 7.5s |  |
| 864 | `place_object_replace_2` | 24 | 27.2s |  |
| 865 | `place_object_same_depth_frame` | 1 | 7.5s |  |
| 866 | `point` | 132 | 8.1s |  |
| 867 | `primitive_edge_cases` | 1 | 7.4s |  |
| 868 | `primitive_keys` | 54 | 7.5s |  |
| 869 | `primitive_toString` | 277 | 7.7s |  |
| 870 | `primitive_valueOf` | 285 | 7.3s |  |
| 871 | `print_job_options` | 3 | 7.4s |  |
| 872 | `property_is_enumerable` | 114 | 8.6s |  |
| 873 | `property_is_enumerable_reset` | 23 | 7.4s |  |
| 874 | `property_priority` | 22 | 7.8s |  |
| 875 | `property_priority_chained` | 4 | 7.4s |  |
| 876 | `property_priority_definition_names_order` | 2 | 7.7s |  |
| 877 | `property_priority_three_level` | 6 | 7.6s |  |
| 878 | `propertyisenumerable_namespaces` | 6 | 7.4s |  |
| 879 | `prototype_set_null` | 7 | 7.3s |  |
| 880 | `proxy_callproperty` | 24 | 7.5s |  |
| 881 | `proxy_deleteproperty` | 64 | 7.5s |  |
| 882 | `proxy_enumeration` | 34 | 7.4s |  |
| 883 | `proxy_getproperty` | 77 | 7.5s |  |
| 884 | `proxy_hasownproperty` | 8 | 7.4s |  |
| 885 | `proxy_hasproperty` | 32 | 7.5s |  |
| 886 | `proxy_not_overridden` | 54 | 7.5s |  |
| 887 | `proxy_serialize` | 9 | 7.5s |  |
| 888 | `proxy_setproperty` | 42 | 7.5s |  |
| 889 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.3s |  |
| 890 | `qname_constr` | 32 | 7.5s |  |
| 891 | `qname_constr_namespace` | 24 | 7.5s |  |
| 892 | `qname_enumeration` | 9 | 7.5s |  |
| 893 | `qname_indexing` | 23 | 7.5s |  |
| 894 | `qname_tostring` | 25 | 7.5s |  |
| 895 | `qname_valueof` | 29 | 7.5s |  |
| 896 | `rectangle` | 1094 | 8.2s |  |
| 897 | `regexp_constr` | 148 | 7.5s |  |
| 898 | `regexp_exec` | 19 | 7.5s |  |
| 899 | `regexp_extended` | 47 | 7.4s |  |
| 900 | `regexp_multiargs` | 1 | 7.3s |  |
| 901 | `regexp_test` | 27 | 7.5s |  |
| 902 | `regexp_toString` | 10 | 7.5s |  |
| 903 | `register_script_refresh` | 35 | 8.0s |  |
| 904 | `remove_child_clear_field` | 88 | 11.0s |  |
| 905 | `remove_dobj` | 3 | 5.1s |  |
| 906 | `resolve_order` | 4 | 4.9s |  |
| 907 | `responder_null_callbacks` | 1 | 4.9s |  |
| 908 | `rng` | 1 | 5.8s |  |
| 909 | `rootless` | 42 | 4.8s |  |
| 910 | `rshift` | 1058 | 11.2s |  |
| 911 | `rtqname_not_namespace` | 12 | 4.9s |  |
| 912 | `sandbox_type_inherited` | 2 | 5.5s |  |
| 913 | `sandbox_type_local_file` | 1 | 4.9s |  |
| 914 | `sandbox_type_local_network` | 1 | 4.7s |  |
| 915 | `scene_constr` | 8 | 4.9s |  |
| 916 | `scope_optimizations` | 4 | 5.0s |  |
| 917 | `scopes_dont_cache/order-1` | 1 | 17.1s |  |
| 918 | `scopes_dont_cache/order-2` | 1 | 0.3s |  |
| 919 | `security_domain_current` | 2 | 4.7s |  |
| 920 | `selection` | 239 | 5.0s |  |
| 921 | `set_local_0` | 31 | 4.9s |  |
| 922 | `set_property_is_enumerable` | 85 | 5.2s |  |
| 923 | `shaderparameter_value` | 4 | 4.8s |  |
| 924 | `shape_drawrect` | 54 | 5.0s |  |
| 925 | `shared_object_no_root` | 3 | 4.8s |  |
| 926 | `simplebutton_added_to_stage` | 45 | 17.6s |  |
| 927 | `simplebutton_childevents` | 86 | 5.4s |  |
| 928 | `simplebutton_childevents_nested` | 54 | 5.2s |  |
| 929 | `simplebutton_childevents_sprite` | 13 | 5.2s |  |
| 930 | `simplebutton_childprops` | 144 | 5.2s |  |
| 931 | `simplebutton_childshuffle` | 23 | 4.9s |  |
| 932 | `simplebutton_constr` | 36 | 5.3s |  |
| 933 | `simplebutton_constr_childevents` | 48 | 5.3s |  |
| 934 | `simplebutton_constr_params` | 42 | 5.1s |  |
| 935 | `simplebutton_mouseenabled` | 26 | 5.1s |  |
| 936 | `simplebutton_multi_children` | 19 | 5.1s |  |
| 937 | `simplebutton_soundtransform` | 887 | 19.2s |  |
| 938 | `simplebutton_structure` | 27 | 5.2s |  |
| 939 | `simplebutton_symbolclass` | 68 | 5.3s |  |
| 940 | `slot_disp_id_shared_numbering` | 1 | 17.6s |  |
| 941 | `slots_force_autoassigned` | 1 | 16.2s |  |
| 942 | `socket_after_disconnect` | 1 | 7.5s |  |
| 943 | `socket_close` | 2 | 7.3s |  |
| 944 | `socket_connect` | 4 | 7.5s |  |
| 945 | `socket_errors` | 56 | 8.1s |  |
| 946 | `socket_read_big` | 48 | 7.6s |  |
| 947 | `socket_read_little` | 48 | 2.5s |  |
| 948 | `socket_read_write_object` | 8 | 7.5s |  |
| 949 | `socket_write_big` | 15 | 7.9s |  |
| 950 | `socket_write_little` | 14 | 7.7s |  |
| 951 | `sound_constructor_with_args` | 6 | 7.8s |  |
| 952 | `sound_embeddedprops` | 26 | 7.8s |  |
| 953 | `sound_load_multiple` | 19 | 8.9s |  |
| 954 | `sound_play` | 19 | 7.7s |  |
| 955 | `sound_rootless` | 7 | 7.5s |  |
| 956 | `sound_valueof` | 33 | 7.8s |  |
| 957 | `soundchannel_soundtransform` | 835 | 29.6s |  |
| 958 | `soundchannel_soundtransform_exists` | 5 | 28.0s |  |
| 959 | `soundchannel_stop` | 8 | 27.3s |  |
| 960 | `soundmixer_buffertime` | 5 | 7.4s |  |
| 961 | `soundmixer_soundtransform` | 900 | 9.7s |  |
| 962 | `soundmixer_stopall` | 6 | 7.5s |  |
| 963 | `soundtransform` | 442 | 13.6s |  |
| 964 | `space_justifier_clone` | 12 | 7.4s |  |
| 965 | `sprite_with_frames` | 0 | 7.6s |  |
| 966 | `stage3d_agal_cross_product` | 0 | 10.4s |  |
| 967 | `stage3d_agal_upload_errors` | 66 | 10.6s |  |
| 968 | `stage3d_bitmap` | 0 | 33.4s |  |
| 969 | `stage3d_blend` | 81 | 30.7s |  |
| 970 | `stage3d_context3d_string_args` | 158 | 9.1s |  |
| 971 | `stage3d_errors` | 7 | 7.7s |  |
| 972 | `stage3d_errors_atf` | 3 | 9.1s |  |
| 973 | `stage3d_errors_swf_29` | 6 | 7.6s |  |
| 974 | `stage3d_float1_index` | 0 | 30.1s |  |
| 975 | `stage3d_fractal` | 0 | 30.3s |  |
| 976 | `stage3d_ignore_sampler_override` | 0 | 30.3s |  |
| 977 | `stage3d_multistage_triangle` | 3 | 10.7s |  |
| 978 | `stage3d_program_constants_bytearray_be` | 0 | 32.0s |  |
| 979 | `stage3d_program_constants_bytearray_le` | 0 | 11.2s |  |
| 980 | `stage3d_program_constants_invalid_input` | 21 | 8.7s |  |
| 981 | `stage3d_raytrace` | 0 | 46.7s |  |
| 982 | `stage3d_rotating_cube` | 0 | 11.4s |  |
| 983 | `stage3d_sampler` | 0 | 10.6s |  |
| 984 | `stage3d_sampler_partial_upload` | 0 | 10.6s |  |
| 985 | `stage3d_stencil` | 0 | 30.9s |  |
| 986 | `stage3d_texture` | 0 | 16.7s |  |
| 987 | `stage3d_texture_bytearray` | 0 | 12.3s |  |
| 988 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 11.5s |  |
| 989 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 12.6s |  |
| 990 | `stage3d_triangle` | 0 | 10.6s |  |
| 991 | `stage3d_triangle_bytes4` | 0 | 10.6s |  |
| 992 | `stage3d_triangle_float1` | 0 | 10.5s |  |
| 993 | `stage3d_triangle_index_upload` | 0 | 10.5s |  |
| 994 | `stage3d_x_y` | 22 | 7.5s |  |
| 995 | `stage_access` | 10 | 7.5s |  |
| 996 | `stage_display_state` | 6 | 7.4s |  |
| 997 | `stage_displayobject_properties` | 24 | 7.4s |  |
| 998 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.4s |  |
| 999 | `stage_framerate_nan` | 7 | 7.4s |  |
| 1000 | `stage_framerate_negative` | 6 | 7.4s |  |
| 1001 | `stage_framerate_zero` | 6 | 7.4s |  |
| 1002 | `stage_invalidate` | 38 | 7.7s |  |
| 1003 | `stage_loaderinfo_properties` | 24 | 7.7s |  |
| 1004 | `stage_mousechildren` | 2 | 7.4s |  |
| 1005 | `stage_mouseenabled` | 15 | 7.5s |  |
| 1006 | `stage_overriden_setters` | 31 | 7.7s |  |
| 1007 | `stage_properties` | 30 | 7.6s |  |
| 1008 | `stage_properties2` | 213 | 7.8s |  |
| 1009 | `stage_scale_factor` | 12 | 32.6s |  |
| 1010 | `stage_stage3Ds_vector` | 1 | 7.4s |  |
| 1011 | `static_length` | 24 | 7.6s |  |
| 1012 | `static_text` | 3 | 7.6s |  |
| 1013 | `static_var_with_this_in_ctor` | 2 | 7.5s |  |
| 1014 | `statictext_text` | 8 | 7.5s |  |
| 1015 | `stored_properties` | 11 | 7.5s |  |
| 1016 | `strict_equality` | 34 | 7.5s |  |
| 1017 | `string_call` | 13 | 7.4s |  |
| 1018 | `string_case` | 23 | 7.5s |  |
| 1019 | `string_char_at` | 27 | 7.5s |  |
| 1020 | `string_char_code_at` | 28 | 7.3s |  |
| 1021 | `string_concat_fromcharcode` | 37 | 7.3s |  |
| 1022 | `string_constr` | 25 | 7.5s |  |
| 1023 | `string_indexof_lastindexof` | 87 | 17.3s |  |
| 1024 | `string_length` | 16 | 8.0s |  |
| 1025 | `string_locale_compare` | 39 | 8.2s |  |
| 1026 | `string_match` | 51 | 8.2s |  |
| 1027 | `string_relational_compare` | 4 | 7.6s |  |
| 1028 | `string_replace` | 51 | 8.0s |  |
| 1029 | `string_search` | 41 | 8.0s |  |
| 1030 | `string_slice_substr_substring` | 170 | 8.9s |  |
| 1031 | `string_split` | 29 | 7.9s |  |
| 1032 | `string_substr_negative` | 21 | 7.7s |  |
| 1033 | `string_substr_weird` | 182 | 7.7s |  |
| 1034 | `stylesheet` | 221 | 8.7s |  |
| 1035 | `stylesheet_parse_color` | 69 | 7.8s |  |
| 1036 | `stylesheet_transform` | 307 | 8.1s |  |
| 1037 | `sub_super_same_field` | 12 | 2.7s |  |
| 1038 | `subclass_superclass_linked_symbol` | 4 | 8.3s |  |
| 1039 | `subtract` | 1058 | 18.4s |  |
| 1040 | `super_get_call` | 12 | 7.7s |  |
| 1041 | `supercall_two_classobjects` | 2 | 7.8s |  |
| 1042 | `supercalls_coerce` | 8 | 7.8s |  |
| 1043 | `supercalls_weird` | 2 | 7.6s |  |
| 1044 | `superinterface_call` | 20 | 7.8s |  |
| 1045 | `superinterface_instanceof` | 18 | 7.9s |  |
| 1046 | `swf8` | 1 | 7.7s |  |
| 1047 | `swf_10_queued_goto_scripts_construct` | 52 | 8.0s |  |
| 1048 | `swf_9_goto_in_enter_frame` | 17 | 7.9s |  |
| 1049 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.8s |  |
| 1050 | `swf_9_queued_goto_scripts` | 6 | 28.0s |  |
| 1051 | `swf_9_queued_goto_scripts_construct` | 28 | 0.7s |  |
| 1052 | `swf_9_versioning` | 2 | 7.8s |  |
| 1053 | `swf_wrong_frame_count` | 38 | 8.3s |  |
| 1054 | `swf_wrong_frame_count_isplaying` | 22 | 7.8s |  |
| 1055 | `symbol_class_binary_data` | 8 | 7.9s |  |
| 1056 | `symbol_class_conflict` | 4 | 8.1s |  |
| 1057 | `symbol_class_root_not_zero` | 1 | 7.7s |  |
| 1058 | `symbolclass_invalid_utf8` | 2 | 7.7s |  |
| 1059 | `system_exit` | 3 | 7.7s |  |
| 1060 | `system_setclipboard_null` | 1 | 7.6s |  |
| 1061 | `tab_ordering_arrows` | 998 | 29.1s |  |
| 1062 | `tab_ordering_automatic_advanced` | 184 | 8.3s |  |
| 1063 | `tab_ordering_automatic_basic` | 45 | 15.9s |  |
| 1064 | `tab_ordering_children` | 116 | 7.0s |  |
| 1065 | `tab_ordering_custom_basic` | 34 | 7.1s |  |
| 1066 | `tab_ordering_properties` | 732 | 7.2s |  |
| 1067 | `tab_ordering_stage_tab_children` | 32 | 7.1s |  |
| 1068 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.1s |  |
| 1069 | `tab_ordering_tabbable` | 47 | 7.0s |  |
| 1070 | `tabstop_properties` | 105 | 7.1s |  |
| 1071 | `text_element_basic` | 34 | 7.1s |  |
| 1072 | `text_engine_fontdescription` | 27 | 7.1s |  |
| 1073 | `text_engine_groupelement` | 64 | 7.1s |  |
| 1074 | `text_run` | 7 | 7.1s |  |
| 1075 | `textblock_createline_errors` | 23 | 7.1s |  |
| 1076 | `textblock_createline_fte` | 9 | 28.0s |  |
| 1077 | `textblock_properties` | 118 | 7.2s |  |
| 1078 | `textbox_click` | 37 | 28.0s |  |
| 1079 | `textfield_event` | 66 | 7.5s |  |
| 1080 | `textfield_focusin_event` | 9 | 7.1s |  |
| 1081 | `textfield_input_dead_keys_windows` | 15 | 7.2s |  |
| 1082 | `textfield_input_events` | 25 | 22.1s |  |
| 1083 | `textfield_unload` | 39 | 28.0s |  |
| 1084 | `textformat` | 1134 | 7.2s |  |
| 1085 | `textformat_display` | 14 | 7.1s |  |
| 1086 | `textformat_font_max_length` | 4 | 7.2s |  |
| 1087 | `textjustifier_locale` | 132 | 7.1s |  |
| 1088 | `textline_has_tabs` | 47 | 7.2s |  |
| 1089 | `textline_inapplicable_properties` | 10 | 7.1s |  |
| 1090 | `textline_name` | 1 | 7.2s |  |
| 1091 | `textline_raw_text_length` | 30 | 7.1s |  |
| 1092 | `textline_splitting_basic` | 76 | 7.1s |  |
| 1093 | `textline_throwerror` | 30 | 7.1s |  |
| 1094 | `textline_validity` | 162 | 7.1s |  |
| 1095 | `throw` | 3 | 7.2s |  |
| 1096 | `timeline_scripts` | 3 | 7.2s |  |
| 1097 | `timer` | 90 | 7.4s |  |
| 1098 | `timer_events` | 3 | 7.4s |  |
| 1099 | `timer_finished` | 11 | 7.3s |  |
| 1100 | `timer_invalid_delay` | 30 | 7.1s |  |
| 1101 | `timer_reset` | 8 | 16.4s |  |
| 1102 | `timer_setdelay` | 5 | 7.7s |  |
| 1103 | `trace` | 12 | 7.5s |  |
| 1104 | `truthiness` | 30 | 7.5s |  |
| 1105 | `try_catch` | 11 | 7.6s |  |
| 1106 | `try_catch_typed` | 12 | 7.6s |  |
| 1107 | `typeof` | 30 | 7.6s |  |
| 1108 | `uint_constr` | 92 | 7.8s |  |
| 1109 | `uint_tofixed` | 1215 | 7.4s |  |
| 1110 | `uint_toprecision` | 1125 | 7.7s |  |
| 1111 | `uint_tostring` | 3375 | 7.7s |  |
| 1112 | `uncaught_error_basic` | 2 | 7.5s |  |
| 1113 | `unchecked_function` | 15 | 7.6s |  |
| 1114 | `unescape` | 28 | 7.7s |  |
| 1115 | `url_loader` | 25 | 7.7s |  |
| 1116 | `url_vars` | 27 | 7.7s |  |
| 1117 | `urlrequest` | 18 | 7.5s |  |
| 1118 | `urlstream_basic` | 5 | 7.6s |  |
| 1119 | `urshift` | 1058 | 19.2s |  |
| 1120 | `utils3d` | 7 | 7.6s |  |
| 1121 | `vector3d` | 397 | 12.7s |  |
| 1122 | `vector3d_near_equals` | 80 | 7.8s |  |
| 1123 | `vector_class` | 36 | 8.2s |  |
| 1124 | `vector_class_call` | 11 | 8.0s |  |
| 1125 | `vector_coercion` | 66 | 8.8s |  |
| 1126 | `vector_concat` | 90 | 8.6s |  |
| 1127 | `vector_constr` | 107 | 8.8s |  |
| 1128 | `vector_enumeration` | 5 | 8.0s |  |
| 1129 | `vector_every` | 92 | 9.0s |  |
| 1130 | `vector_filter` | 95 | 9.1s |  |
| 1131 | `vector_holes` | 24 | 7.9s |  |
| 1132 | `vector_indexof` | 302 | 13.5s |  |
| 1133 | `vector_insertat` | 270 | 9.6s |  |
| 1134 | `vector_int_access` | 4 | 7.9s |  |
| 1135 | `vector_int_delete` | 11 | 8.0s |  |
| 1136 | `vector_join` | 58 | 8.7s |  |
| 1137 | `vector_lastindexof` | 302 | 7.8s |  |
| 1138 | `vector_legacy` | 10 | 7.7s |  |
| 1139 | `vector_map` | 85 | 8.6s |  |
| 1140 | `vector_object_final` | 1 | 7.6s |  |
| 1141 | `vector_object_toString` | 10 | 15.4s |  |
| 1142 | `vector_pushpop` | 255 | 8.4s |  |
| 1143 | `vector_reborrow_bug` | 10 | 7.0s |  |
| 1144 | `vector_removeat` | 172 | 8.1s |  |
| 1145 | `vector_reverse` | 232 | 8.1s |  |
| 1146 | `vector_shiftunshift` | 252 | 6.9s |  |
| 1147 | `vector_slice` | 331 | 8.7s |  |
| 1148 | `vector_sort` | 905 | 16.2s |  |
| 1149 | `vector_splice` | 693 | 10.8s |  |
| 1150 | `vector_splice_fixed_bug_compat` | 4 | 7.0s |  |
| 1151 | `vector_tostring` | 79 | 7.7s |  |
| 1152 | `verification` | 8 | 7.1s |  |
| 1153 | `verify_abnormal_loop` | 1 | 6.9s |  |
| 1154 | `verify_dxns_without_flag` | 3 | 7.2s |  |
| 1155 | `verify_exception_target_two_jumps` | 1 | 6.9s |  |
| 1156 | `verify_exception_targets_edge_case` | 1 | 6.9s |  |
| 1157 | `verify_illegal_opcode` | 1 | 2.2s |  |
| 1158 | `verify_jump_to_middle_of_op` | 1 | 6.9s |  |
| 1159 | `verify_lookup_switch_edge_case` | 1 | 6.9s |  |
| 1160 | `verify_method_info_oob` | 1 | 0.5s |  |
| 1161 | `verify_stack` | 5 | 7.1s |  |
| 1162 | `verify_typecheck` | 4 | 7.0s |  |
| 1163 | `verify_unreachable_exception` | 2 | 6.9s |  |
| 1164 | `versioned_isplaying` | 2 | 7.0s |  |
| 1165 | `virtual_properties` | 16 | 7.1s |  |
| 1166 | `with` | 4 | 7.0s |  |
| 1167 | `wrong_arg_count` | 7 | 7.1s |  |
| 1168 | `xml_abstract_equality` | 36 | 7.2s |  |
| 1169 | `xml_advanced` | 52 | 7.1s |  |
| 1170 | `xml_appendchild` | 10 | 7.0s |  |
| 1171 | `xml_appendchild_swf_v21` | 13 | 7.3s |  |
| 1172 | `xml_as_attribute` | 9 | 7.0s |  |
| 1173 | `xml_attribute` | 35 | 7.2s |  |
| 1174 | `xml_attribute_name` | 40 | 7.0s |  |
| 1175 | `xml_basic` | 33 | 7.2s |  |
| 1176 | `xml_child` | 25 | 7.2s |  |
| 1177 | `xml_childindex` | 7 | 7.0s |  |
| 1178 | `xml_children` | 43 | 7.6s |  |
| 1179 | `xml_class_call` | 9 | 7.0s |  |
| 1180 | `xml_contains` | 197 | 7.1s |  |
| 1181 | `xml_copy` | 20 | 16.1s |  |
| 1182 | `xml_ctor_from_tostring` | 23 | 7.7s |  |
| 1183 | `xml_delete` | 114 | 7.5s |  |
| 1184 | `xml_descendants` | 83 | 7.4s |  |
| 1185 | `xml_duplicate_attribute` | 14 | 7.4s |  |
| 1186 | `xml_elements` | 6 | 7.3s |  |
| 1187 | `xml_equals_namespace_check` | 2 | 7.3s |  |
| 1188 | `xml_explicit_use_namespace` | 5 | 7.5s |  |
| 1189 | `xml_getdescendants_qname` | 21 | 7.4s |  |
| 1190 | `xml_has_property_via_in` | 26 | 7.4s |  |
| 1191 | `xml_hasownproperty` | 6 | 7.3s |  |
| 1192 | `xml_ignore_white` | 6 | 7.4s |  |
| 1193 | `xml_length` | 2 | 7.3s |  |
| 1194 | `xml_list_as_attribute` | 9 | 7.3s |  |
| 1195 | `xml_list_concat` | 20 | 7.3s |  |
| 1196 | `xml_list_ctor_errors` | 34 | 7.4s |  |
| 1197 | `xml_list_delete_clear_parent` | 6 | 7.3s |  |
| 1198 | `xml_list_enumerate` | 4 | 7.3s |  |
| 1199 | `xml_methods_settings` | 3 | 7.3s |  |
| 1200 | `xml_mismatched_tag` | 37 | 7.4s |  |
| 1201 | `xml_namespace` | 39 | 7.3s |  |
| 1202 | `xml_namespace_methods` | 245 | 7.5s |  |
| 1203 | `xml_namespaced_property` | 7 | 7.3s |  |
| 1204 | `xml_no_namespace` | 1 | 7.3s |  |
| 1205 | `xml_nodekind` | 3 | 7.3s |  |
| 1206 | `xml_normalize` | 35 | 7.4s |  |
| 1207 | `xml_notification_bubbling` | 361 | 7.5s |  |
| 1208 | `xml_parent` | 8 | 7.4s |  |
| 1209 | `xml_set_children` | 17 | 7.4s |  |
| 1210 | `xml_set_name` | 34 | 7.4s |  |
| 1211 | `xml_settings` | 6 | 2.4s |  |
| 1212 | `xml_simple_complex_content` | 47 | 7.4s |  |
| 1213 | `xml_socket` | 11 | 7.6s |  |
| 1214 | `xml_text` | 7 | 7.4s |  |
| 1215 | `xml_tostring` | 6 | 7.4s |  |
| 1216 | `xml_tostring_namespace` | 12 | 7.1s |  |
| 1217 | `xml_unescaping` | 23 | 7.4s |  |
| 1218 | `xml_weird_ignores` | 54 | 7.4s |  |
| 1219 | `xml_wildcard` | 11 | 7.4s |  |
| 1220 | `xmldocument` | 254 | 7.5s |  |
| 1221 | `xmlnode` | 3540 | 7.6s |  |
| 1222 | `zero_frame_clip` | 3 | 7.5s |  |

## Ruffle-Matched Tests

**41 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 6.2s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.4s |  |
| 3 | `blend_transform` | 1 | 1 | 7.4s |  |
| 4 | `bounds_mode` | 6 | 6 | 8.0s |  |
| 5 | `coerce_property` | 3 | 3 | 7.7s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.7s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 17.9s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 17.3s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 7.4s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.4s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 7.1s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 7.8s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.6s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 7.7s |  |
| 15 | `event_handler_exception` | 4 | 4 | 7.6s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 7.4s |  |
| 17 | `goto_framescript_queued/swf13` | 3 | 3 | 0.7s |  |
| 18 | `gradient_values_readback` | 12 | 12 | 7.8s |  |
| 19 | `graphics_draw_path` | 50 | 50 | 28.0s |  |
| 20 | `groupelement_text` | 2 | 2 | 7.6s |  |
| 21 | `int_toexponential` | 76 | 76 | 7.7s |  |
| 22 | `json_parse_numbers` | 4 | 79 | 4.9s |  |
| 23 | `loader_events_2` | 30 | 30 | 5.3s |  |
| 24 | `matrix3d_recompose_edge_cases` | 8 | 85 | 7.9s |  |
| 25 | `number_convert_errors` | 706 | 706 | 8.1s |  |
| 26 | `number_to_string` | 104 | 104 | 8.3s |  |
| 27 | `simplebutton_childevents_multichild` | 101 | 101 | 5.1s |  |
| 28 | `simplebutton_childevents_script_order` | 4 | 4 | 5.5s |  |
| 29 | `slot_holes_fail` | 1 | 1 | 4.9s |  |
| 30 | `slot_id_exceeds_trait_count` | 1 | 1 | 5.0s |  |
| 31 | `soundchannel_position` | 74 | 74 | 28.8s |  |
| 32 | `soundchannel_soundcomplete` | 10 | 10 | 7.8s |  |
| 33 | `sprite_dropTarget` | 15 | 15 | 7.5s |  |
| 34 | `swf_9_goto_in_construct_frame` | 12 | 12 | 8.0s |  |
| 35 | `textblock_line_changes` | 44 | 44 | 7.1s |  |
| 36 | `textblock_recreateline` | 139 | 140 | 7.0s |  |
| 37 | `textblock_releaselines` | 4 | 4 | 7.1s |  |
| 38 | `textline_atom_index_at_char_index` | 3 | 3 | 8.0s |  |
| 39 | `uint_toexponential` | 100 | 100 | 7.7s |  |
| 40 | `uncaught_errors_stringified` | 15 | 15 | 7.6s |  |
| 41 | `weird_superinterface_properties` | 1 | 1 | 7.1s |  |

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
