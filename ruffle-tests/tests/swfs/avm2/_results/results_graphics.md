# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-22 21:18 UTC

**Git SHA**: `19ba533729`

**Run Duration**: 246m 19s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1278 |
| Passing | **1217** (95.2%) |
| Ruffle-matched | 38 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1255** (98.2%) |
| Failing | 23 |
| Total expected lines | 157502 |
| Matching lines | 154637 (98.2%) |
| Mismatched lines | 2865 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 23 | 100.0% |

## Passing Tests

**1217 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 30.3s |  |
| 2 | `accessibility` | 1 | 8.7s |  |
| 3 | `accessibilityimplementation` | 18 | 28.7s |  |
| 4 | `activation_class` | 6 | 8.8s |  |
| 5 | `add` | 1058 | 20.0s |  |
| 6 | `agal_compiler` | 13 | 11.8s |  |
| 7 | `air_datagram_socket` | 1 | 10.8s |  |
| 8 | `air_hidden_lookup` | 2 | 8.7s |  |
| 9 | `air_ifilepromise` | 1 | 8.7s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 8.8s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.3s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.3s |  |
| 13 | `all_classes/display/swf10` | 2569 | 8.8s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.4s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.3s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.4s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.4s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.3s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 8.7s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.3s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.3s |  |
| 22 | `all_classes/errors/swf10` | 140 | 8.8s |  |
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
| 34 | `all_classes/xml/swf30` | 116 | 8.8s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.3s |  |
| 36 | `amf_array_serialization` | 17 | 30.8s |  |
| 37 | `amf_custom_obj` | 26 | 8.7s |  |
| 38 | `amf_dictionary` | 9 | 8.7s |  |
| 39 | `amf_function` | 46 | 8.7s |  |
| 40 | `amf_invalid_date` | 2 | 8.6s |  |
| 41 | `amf_missing_prop` | 6 | 8.6s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 8.7s |  |
| 43 | `amf_setter_error` | 8 | 8.8s |  |
| 44 | `amf_vector` | 40 | 30.3s |  |
| 45 | `amf_xml` | 6 | 8.8s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 9.4s |  |
| 47 | `application_domain` | 4 | 8.8s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 28.3s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 8.6s |  |
| 50 | `array_access` | 18 | 8.7s |  |
| 51 | `array_access_interpreter` | 4 | 8.6s |  |
| 52 | `array_access_no_pubns` | 2 | 8.6s |  |
| 53 | `array_concat` | 41 | 8.6s |  |
| 54 | `array_constr` | 10 | 8.6s |  |
| 55 | `array_delete` | 44 | 8.9s |  |
| 56 | `array_enumeration` | 10 | 8.8s |  |
| 57 | `array_enumeration_elements` | 11 | 8.8s |  |
| 58 | `array_every` | 8 | 8.8s |  |
| 59 | `array_filter` | 6 | 8.7s |  |
| 60 | `array_foreach` | 18 | 8.9s |  |
| 61 | `array_hasownproperty` | 11 | 9.1s |  |
| 62 | `array_holes` | 9 | 9.0s |  |
| 63 | `array_index_max` | 84 | 8.9s |  |
| 64 | `array_indexof` | 25 | 8.7s |  |
| 65 | `array_join` | 26 | 8.7s |  |
| 66 | `array_lastindexof` | 29 | 8.6s |  |
| 67 | `array_length` | 14 | 8.6s |  |
| 68 | `array_literal` | 3 | 8.6s |  |
| 69 | `array_map` | 8 | 3.1s |  |
| 70 | `array_pop` | 52 | 8.7s |  |
| 71 | `array_push` | 24 | 8.6s |  |
| 72 | `array_reborrow_bug` | 6 | 8.6s |  |
| 73 | `array_reverse` | 28 | 8.7s |  |
| 74 | `array_shift` | 51 | 3.4s |  |
| 75 | `array_slice` | 39 | 8.6s |  |
| 76 | `array_some` | 8 | 8.5s |  |
| 77 | `array_sort` | 297 | 9.2s |  |
| 78 | `array_sort_fun_swf12` | 2 | 8.5s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 80 | `array_sort_random` | 210 | 8.6s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 8.5s |  |
| 82 | `array_sorton` | 545 | 9.6s |  |
| 83 | `array_sparse_ops` | 41 | 8.8s |  |
| 84 | `array_splice` | 133 | 8.8s |  |
| 85 | `array_splice2` | 428 | 28.1s |  |
| 86 | `array_splice_types` | 48 | 8.1s |  |
| 87 | `array_storage` | 8 | 26.9s |  |
| 88 | `array_tolocalestring` | 9 | 8.0s |  |
| 89 | `array_tostring` | 12 | 8.0s |  |
| 90 | `array_unshift` | 24 | 8.0s |  |
| 91 | `array_valueof` | 9 | 8.0s |  |
| 92 | `array_vector_null_callback` | 10 | 8.0s |  |
| 93 | `astype` | 28 | 8.2s |  |
| 94 | `astypelate` | 24 | 8.2s |  |
| 95 | `astypelate_propagates` | 1 | 7.8s |  |
| 96 | `asymmetric_key_events` | 11 | 8.0s |  |
| 97 | `automation_classes` | 122 | 8.2s |  |
| 98 | `av_classes` | 340 | 7.9s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 7.7s |  |
| 100 | `avm2_catchup_dobj` | 158 | 8.5s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 99.0s |  |
| 102 | `bevel_filter` | 187 | 8.2s |  |
| 103 | `bitand` | 1058 | 16.2s |  |
| 104 | `bitmap_constr` | 17 | 8.2s |  |
| 105 | `bitmap_data` | 1000 | 15.9s |  |
| 106 | `bitmap_filter_abstract` | 6 | 7.7s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 26.5s |  |
| 108 | `bitmap_properties` | 23 | 7.9s |  |
| 109 | `bitmap_subclass` | 7 | 9.4s |  |
| 110 | `bitmap_subclass_properties` | 9 | 8.1s |  |
| 111 | `bitmap_timeline` | 9 | 7.9s |  |
| 112 | `bitmapdata_accuracy` | 1 | 52.0s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 26.6s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.3s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 26.2s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.6s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 25.8s |  |
| 118 | `bitmapdata_clone` | 13 | 7.8s |  |
| 119 | `bitmapdata_colortransform` | 0 | 8.1s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 7.7s |  |
| 121 | `bitmapdata_constr` | 22 | 7.9s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 8.2s |  |
| 123 | `bitmapdata_copychannel` | 0 | 28.5s |  |
| 124 | `bitmapdata_copypixels` | 23 | 27.3s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 7.8s |  |
| 126 | `bitmapdata_copypixels_alpha_merge` | 9 | 24.9s |  |
| 127 | `bitmapdata_copypixels_blend` | 1029 | 9.2s |  |
| 128 | `bitmapdata_copypixels_blend_over` | 1 | 8.6s |  |
| 129 | `bitmapdata_copypixels_self` | 612 | 8.7s |  |
| 130 | `bitmapdata_copypixelstobytearray` | 39 | 8.8s |  |
| 131 | `bitmapdata_dispose` | 7 | 8.8s |  |
| 132 | `bitmapdata_draw` | 0 | 30.9s |  |
| 133 | `bitmapdata_draw_alpha_erase` | 8 | 8.9s |  |
| 134 | `bitmapdata_draw_cab_quality` | 0 | 30.5s |  |
| 135 | `bitmapdata_draw_colortransform` | 0 | 29.1s |  |
| 136 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 29.2s |  |
| 137 | `bitmapdata_draw_filters` | 0 | 28.9s |  |
| 138 | `bitmapdata_draw_masks` | 0 | 8.8s |  |
| 139 | `bitmapdata_draw_rotation` | 0 | 8.8s |  |
| 140 | `bitmapdata_draw_self_via_graphic` | 0 | 8.7s |  |
| 141 | `bitmapdata_draw_stage` | 0 | 29.1s |  |
| 142 | `bitmapdata_drawwithquality` | 0 | 11.1s |  |
| 143 | `bitmapdata_embedded` | 9 | 8.9s |  |
| 144 | `bitmapdata_fillrect` | 0 | 8.7s |  |
| 145 | `bitmapdata_filter_sourcerect` | 0 | 29.5s |  |
| 146 | `bitmapdata_floodfill` | 35 | 8.6s |  |
| 147 | `bitmapdata_getpixels` | 39 | 29.0s |  |
| 148 | `bitmapdata_getvector` | 27 | 3.1s |  |
| 149 | `bitmapdata_histogram` | 59 | 3.0s |  |
| 150 | `bitmapdata_hittest` | 112 | 9.2s |  |
| 151 | `bitmapdata_hittest_threshold` | 18 | 8.6s |  |
| 152 | `bitmapdata_opaque` | 0 | 8.8s |  |
| 153 | `bitmapdata_pixeldissolve` | 1037 | 9.2s |  |
| 154 | `bitmapdata_pixeldissolve_image` | 0 | 8.8s |  |
| 155 | `bitmapdata_rectangle_rounding` | 16 | 8.5s |  |
| 156 | `bitmapdata_setpixels` | 286 | 8.6s |  |
| 157 | `bitmapdata_setvector` | 26 | 8.8s |  |
| 158 | `bitmapdata_sync` | 0 | 29.4s |  |
| 159 | `bitmapdata_threshold` | 176 | 9.6s |  |
| 160 | `bitmapdata_zero_size` | 8 | 8.8s |  |
| 161 | `bitnot` | 46 | 8.8s |  |
| 162 | `bitor` | 1058 | 18.0s |  |
| 163 | `bitxor` | 1058 | 18.1s |  |
| 164 | `blend_mode_null` | 1 | 8.7s |  |
| 165 | `blend_multiply_alpha` | 0 | 8.9s |  |
| 166 | `blend_scroll` | 0 | 8.8s |  |
| 167 | `blend_shader_luma_lighten` | 3 | 9.3s |  |
| 168 | `blur_filter` | 43 | 9.4s |  |
| 169 | `boolean_constr` | 32 | 8.9s |  |
| 170 | `boolean_negation` | 30 | 8.9s |  |
| 171 | `boolean_tostring` | 8 | 8.9s |  |
| 172 | `broadcast_event` | 7 | 8.7s |  |
| 173 | `button_bounds` | 1 | 8.8s |  |
| 174 | `button_hittest` | 2 | 28.5s |  |
| 175 | `button_nested_frame` | 48 | 29.0s |  |
| 176 | `button_nested_frame_simple` | 27 | 9.4s |  |
| 177 | `bytearray` | 48 | 9.2s |  |
| 178 | `bytearray_bad_symbol_class` | 3 | 8.9s |  |
| 179 | `bytearray_bad_symbol_class_other_movie` | 6 | 9.2s |  |
| 180 | `bytearray_compress` | 31 | 8.9s |  |
| 181 | `bytearray_errors` | 24 | 9.0s |  |
| 182 | `bytearray_method_serialization` | 1 | 8.8s |  |
| 183 | `bytearray_oom` | 3 | 8.8s |  |
| 184 | `bytearray_readobject_amf0` | 50 | 8.8s |  |
| 185 | `bytearray_readobject_amf3` | 53 | 8.9s |  |
| 186 | `bytearray_readutf8bytes_with_bom` | 16 | 8.9s |  |
| 187 | `bytearray_serialization` | 3 | 8.9s |  |
| 188 | `bytearray_string_null` | 19 | 9.2s |  |
| 189 | `bytearray_tostring` | 15 | 8.9s |  |
| 190 | `bytearray_utf16` | 8 | 8.8s |  |
| 191 | `bytearray_writeobject` | 24 | 8.7s |  |
| 192 | `callee_in_initializer` | 6 | 8.8s |  |
| 193 | `callproplex_class` | 1 | 8.8s |  |
| 194 | `capabilities_resolution` | 8 | 30.0s |  |
| 195 | `catch_class` | 6 | 8.8s |  |
| 196 | `catch_scope_slot` | 7 | 8.9s |  |
| 197 | `checkfilter` | 4 | 3.4s |  |
| 198 | `class_call` | 32 | 9.0s |  |
| 199 | `class_cast_call` | 14 | 8.8s |  |
| 200 | `class_enumeration` | 4 | 8.8s |  |
| 201 | `class_has_own_property` | 2 | 8.7s |  |
| 202 | `class_init_interpreter_mode` | 1 | 8.7s |  |
| 203 | `class_is` | 32 | 8.9s |  |
| 204 | `class_methods` | 5 | 8.8s |  |
| 205 | `class_object_properties` | 10 | 8.8s |  |
| 206 | `class_singleton` | 18 | 8.8s |  |
| 207 | `class_supercalls_errors` | 35 | 9.0s |  |
| 208 | `class_supercalls_mismatched` | 26 | 8.2s |  |
| 209 | `class_superclass_wrong_order` | 1 | 8.1s |  |
| 210 | `class_to_locale_string` | 2 | 8.1s |  |
| 211 | `class_to_string` | 2 | 8.0s |  |
| 212 | `class_value_of` | 2 | 8.1s |  |
| 213 | `click_block` | 5 | 28.1s |  |
| 214 | `click_invisible` | 3 | 8.1s |  |
| 215 | `closures` | 12 | 8.1s |  |
| 216 | `coerce_return_type` | 40 | 3.0s |  |
| 217 | `coerce_return_type_fail` | 2 | 8.1s |  |
| 218 | `coerce_return_void` | 3 | 8.1s |  |
| 219 | `coerce_string` | 86 | 8.2s |  |
| 220 | `coerce_string_precision` | 28 | 8.1s |  |
| 221 | `coerce_to_primitive_side_effects` | 29 | 8.2s |  |
| 222 | `color_matrix_filter` | 19 | 8.2s |  |
| 223 | `construct_errors_swf10` | 8 | 8.2s |  |
| 224 | `construct_frame_list` | 22 | 27.4s |  |
| 225 | `construct_interface` | 3 | 8.0s |  |
| 226 | `constructor_call` | 3 | 8.0s |  |
| 227 | `constructors_vs_timeline` | 5 | 27.4s |  |
| 228 | `constructprop_dynamic_primitive` | 7 | 8.2s |  |
| 229 | `constructprop_method` | 2 | 8.0s |  |
| 230 | `constructsuper_null` | 2 | 2.8s |  |
| 231 | `content_element_basic` | 50 | 8.4s |  |
| 232 | `context3d_creation` | 9 | 10.1s |  |
| 233 | `control_flow_bool` | 4 | 8.1s |  |
| 234 | `control_flow_stricteq` | 8 | 8.1s |  |
| 235 | `convert_boolean` | 30 | 8.1s |  |
| 236 | `convert_integer` | 90 | 8.2s |  |
| 237 | `convert_number` | 56 | 2.9s |  |
| 238 | `convert_uinteger` | 90 | 8.2s |  |
| 239 | `convolution_filter` | 89 | 8.2s |  |
| 240 | `core_exceptions` | 47 | 9.2s |  |
| 241 | `cpool_index_invalid_bytecode_1` | 6 | 8.2s |  |
| 242 | `cpool_index_invalid_bytecode_2` | 3 | 8.1s |  |
| 243 | `cpool_index_invalid_bytecode_3` | 1 | 8.0s |  |
| 244 | `cross_api_version_call_newer` | 12 | 8.7s |  |
| 245 | `cross_api_version_call_older` | 12 | 8.3s |  |
| 246 | `cryptscore` | 11 | 8.2s |  |
| 247 | `currency_parse_result` | 7 | 8.1s |  |
| 248 | `date` | 30 | 8.7s |  |
| 249 | `date_parse` | 36 | 8.9s |  |
| 250 | `declocal` | 46 | 8.9s |  |
| 251 | `declocal_i` | 46 | 8.9s |  |
| 252 | `decode_uri` | 71 | 9.3s |  |
| 253 | `decrement` | 46 | 8.9s |  |
| 254 | `decrement_i` | 46 | 3.4s |  |
| 255 | `default_values` | 7 | 8.8s |  |
| 256 | `delayed_symbolclass` | 28 | 29.6s |  |
| 257 | `describe_type_basic` | 152 | 9.1s |  |
| 258 | `describe_type_json` | 301 | 9.1s |  |
| 259 | `describe_type_metadata` | 125 | 9.0s |  |
| 260 | `describe_type_native` | 23 | 8.9s |  |
| 261 | `dictionary_access` | 62 | 9.2s |  |
| 262 | `dictionary_access_no_pubns` | 2 | 8.8s |  |
| 263 | `dictionary_delete` | 101 | 9.3s |  |
| 264 | `dictionary_foreach` | 42 | 9.0s |  |
| 265 | `dictionary_hasownproperty` | 63 | 9.1s |  |
| 266 | `dictionary_in` | 62 | 9.0s |  |
| 267 | `dictionary_iter_modify` | 8 | 8.7s |  |
| 268 | `dictionary_namespaces` | 36 | 8.9s |  |
| 269 | `displacement_map_filter` | 61 | 8.9s |  |
| 270 | `displayobject_alpha` | 277 | 8.7s |  |
| 271 | `displayobject_blendmode` | 0 | 29.5s |  |
| 272 | `displayobject_colortransform_nested` | 0 | 29.3s |  |
| 273 | `displayobject_early_init` | 54 | 11.3s |  |
| 274 | `displayobject_filters` | 17 | 9.1s |  |
| 275 | `displayobject_from_enterframe` | 1 | 29.9s |  |
| 276 | `displayobject_getbounds_shape` | 0 | 30.0s |  |
| 277 | `displayobject_getrect` | 16 | 9.3s |  |
| 278 | `displayobject_height` | 6052 | 30.3s |  |
| 279 | `displayobject_hittestobject` | 32 | 9.0s |  |
| 280 | `displayobject_hittestpoint` | 49 | 9.1s |  |
| 281 | `displayobject_hittestpoint_boundary` | 65 | 30.0s |  |
| 282 | `displayobject_hittestpoint_root` | 13 | 9.3s |  |
| 283 | `displayobject_invalid_floats` | 60 | 9.0s |  |
| 284 | `displayobject_invalid_props` | 3 | 8.8s |  |
| 285 | `displayobject_mask` | 3 | 9.4s |  |
| 286 | `displayobject_mask_self_referential` | 0 | 8.9s |  |
| 287 | `displayobject_metaData` | 3 | 8.8s |  |
| 288 | `displayobject_name` | 22 | 28.9s |  |
| 289 | `displayobject_name_from_timeline` | 24 | 9.0s |  |
| 290 | `displayobject_opaque_background` | 6 | 8.9s |  |
| 291 | `displayobject_parent` | 12 | 28.6s |  |
| 292 | `displayobject_root` | 24 | 8.7s |  |
| 293 | `displayobject_rotation` | 1284 | 8.8s |  |
| 294 | `displayobject_scrollrect` | 33 | 9.8s |  |
| 295 | `displayobject_set_matrix_nested` | 0 | 28.9s |  |
| 296 | `displayobject_set_name_loaded` | 3 | 9.0s |  |
| 297 | `displayobject_subclass` | 2 | 8.7s |  |
| 298 | `displayobject_transform` | 89 | 28.7s |  |
| 299 | `displayobject_visible` | 23 | 8.7s |  |
| 300 | `displayobject_width` | 4852 | 28.8s |  |
| 301 | `displayobject_x` | 614 | 8.7s |  |
| 302 | `displayobject_y` | 617 | 8.7s |  |
| 303 | `displayobject_z` | 38 | 29.2s |  |
| 304 | `displayobjectcontainer_addchild` | 32 | 8.8s |  |
| 305 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 8.6s |  |
| 306 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.9s |  |
| 307 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 8.8s |  |
| 308 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 8.7s |  |
| 309 | `displayobjectcontainer_addchildat` | 42 | 8.6s |  |
| 310 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 8.7s |  |
| 311 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 8.7s |  |
| 312 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.7s |  |
| 313 | `displayobjectcontainer_contains` | 66 | 28.4s |  |
| 314 | `displayobjectcontainer_getchildat` | 4 | 8.8s |  |
| 315 | `displayobjectcontainer_getchildbyname` | 9 | 8.7s |  |
| 316 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 8.6s |  |
| 317 | `displayobjectcontainer_getchildindex` | 28 | 8.6s |  |
| 318 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 28.6s |  |
| 319 | `displayobjectcontainer_removechild` | 10 | 8.6s |  |
| 320 | `displayobjectcontainer_removechild_errors` | 4 | 8.5s |  |
| 321 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 8.6s |  |
| 322 | `displayobjectcontainer_removechildat` | 18 | 8.5s |  |
| 323 | `displayobjectcontainer_removechildren` | 51 | 8.8s |  |
| 324 | `displayobjectcontainer_setchildindex` | 42 | 8.5s |  |
| 325 | `displayobjectcontainer_stopallmovieclips` | 2 | 28.4s |  |
| 326 | `displayobjectcontainer_swapchildren` | 42 | 8.7s |  |
| 327 | `displayobjectcontainer_swapchildrenat` | 42 | 8.6s |  |
| 328 | `displayobjectcontainer_timelineinstance` | 48 | 28.7s |  |
| 329 | `divide` | 1058 | 20.1s |  |
| 330 | `doabc_and_symbolclass_script_init_goto` | 7 | 29.0s |  |
| 331 | `doabc_and_symbolclass_script_init_normal` | 6 | 8.7s |  |
| 332 | `doabc_is_eager` | 1 | 28.7s |  |
| 333 | `documentclass` | 9 | 8.9s |  |
| 334 | `domain_memory` | 133 | 30.0s |  |
| 335 | `drag_drop` | 10 | 8.8s |  |
| 336 | `drop_shadow_filter` | 172 | 9.2s |  |
| 337 | `duplicate_defs` | 1 | 8.6s |  |
| 338 | `eager_init` | 1 | 8.7s |  |
| 339 | `east_asian_justifier_clone` | 8 | 8.8s |  |
| 340 | `edit_text_linkage` | 7 | 8.9s |  |
| 341 | `edittext_align` | 60 | 9.4s |  |
| 342 | `edittext_always_show_selection` | 0 | 29.2s |  |
| 343 | `edittext_antialiastype` | 296 | 9.2s |  |
| 344 | `edittext_at_point_methods_basic` | 16 | 10.1s |  |
| 345 | `edittext_autosize` | 39 | 9.3s |  |
| 346 | `edittext_autosize_align` | 0 | 29.1s |  |
| 347 | `edittext_autosize_height_dynamic` | 60 | 28.9s |  |
| 348 | `edittext_autosize_height_input` | 60 | 8.9s |  |
| 349 | `edittext_autosize_lazy_bounds_events` | 65 | 8.9s |  |
| 350 | `edittext_autosize_lazy_bounds_interactions` | 19 | 8.8s |  |
| 351 | `edittext_autosize_lazy_bounds_props` | 490 | 10.6s |  |
| 352 | `edittext_autosize_lazy_bounds_visual` | 0 | 28.6s |  |
| 353 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 9.0s |  |
| 354 | `edittext_bottom_scroll_v_basic` | 210 | 8.9s |  |
| 355 | `edittext_bounds_scale` | 24 | 28.5s |  |
| 356 | `edittext_bullet` | 30 | 9.0s |  |
| 357 | `edittext_default_format` | 221 | 9.2s |  |
| 358 | `edittext_default_format_empty` | 136 | 9.1s |  |
| 359 | `edittext_empty_text_format` | 7 | 8.8s |  |
| 360 | `edittext_focus_selection` | 5 | 8.7s |  |
| 361 | `edittext_font_size` | 45 | 9.0s |  |
| 362 | `edittext_format_empty_font` | 8 | 8.7s |  |
| 363 | `edittext_get_char_index_at_point` | 4 | 31.3s |  |
| 364 | `edittext_get_line_index_at_point` | 2 | 9.2s |  |
| 365 | `edittext_get_line_index_of_char` | 76 | 9.8s |  |
| 366 | `edittext_getcharboundaries` | 172 | 9.3s |  |
| 367 | `edittext_getcharboundaries_missing_glyphs` | 63 | 8.8s |  |
| 368 | `edittext_getcharboundaries_scroll` | 85 | 8.8s |  |
| 369 | `edittext_getlinemetrics` | 146 | 9.2s |  |
| 370 | `edittext_html` | 3101 | 9.3s |  |
| 371 | `edittext_html_condensewhite` | 487 | 8.9s |  |
| 372 | `edittext_html_entity` | 4 | 29.7s |  |
| 373 | `edittext_html_font_size_swf12` | 267 | 29.1s |  |
| 374 | `edittext_html_font_size_swf13` | 273 | 8.5s |  |
| 375 | `edittext_html_roundtrip` | 17 | 8.9s |  |
| 376 | `edittext_ime_focus_lost` | 9 | 29.0s |  |
| 377 | `edittext_input_control` | 12 | 8.9s |  |
| 378 | `edittext_leading` | 9 | 9.4s |  |
| 379 | `edittext_letter_spacing` | 15 | 9.1s |  |
| 380 | `edittext_line_methods` | 294 | 10.6s |  |
| 381 | `edittext_line_metrics` | 11 | 30.8s |  |
| 382 | `edittext_margins` | 25 | 9.0s |  |
| 383 | `edittext_max_scroll_h_basic` | 475 | 9.1s |  |
| 384 | `edittext_max_scroll_v_basic` | 1000 | 8.9s |  |
| 385 | `edittext_mouse_selection` | 363 | 30.4s |  |
| 386 | `edittext_mousedown` | 3 | 9.4s |  |
| 387 | `edittext_mouseenabled` | 26 | 8.9s |  |
| 388 | `edittext_newline_character` | 22 | 9.0s |  |
| 389 | `edittext_newline_stripping` | 64 | 12.1s |  |
| 390 | `edittext_newlines` | 30 | 9.1s |  |
| 391 | `edittext_paragraph_methods` | 257 | 8.9s |  |
| 392 | `edittext_paste_events` | 8 | 8.9s |  |
| 393 | `edittext_paste_maxchars` | 4 | 9.0s |  |
| 394 | `edittext_paste_restrict` | 16 | 8.7s |  |
| 395 | `edittext_restrict` | 191 | 8.8s |  |
| 396 | `edittext_restrict_events` | 22 | 8.8s |  |
| 397 | `edittext_scroll_event` | 37 | 9.1s |  |
| 398 | `edittext_scrollh` | 10 | 3.3s |  |
| 399 | `edittext_selected_text` | 9 | 8.8s |  |
| 400 | `edittext_set_html_same` | 17 | 8.9s |  |
| 401 | `edittext_set_text_vs_html` | 9 | 9.0s |  |
| 402 | `edittext_stylesheet` | 536 | 9.4s |  |
| 403 | `edittext_stylesheet_custom_tag` | 76 | 9.0s |  |
| 404 | `edittext_stylesheet_display` | 272 | 9.0s |  |
| 405 | `edittext_tag_indent` | 49 | 28.9s |  |
| 406 | `edittext_underline` | 40 | 9.1s |  |
| 407 | `edittext_width_height` | 103 | 9.1s |  |
| 408 | `edittext_wordwrap_word` | 150 | 9.0s |  |
| 409 | `edittext_wrap_breaks` | 2375 | 9.3s |  |
| 410 | `element_format_clone` | 44 | 9.1s |  |
| 411 | `element_format_constructor_order` | 64 | 3.5s |  |
| 412 | `element_format_properties` | 235 | 10.3s |  |
| 413 | `empty_bounds` | 1 | 8.8s |  |
| 414 | `encode_uri_surrogate_pair_invalid` | 8 | 25.9s |  |
| 415 | `encode_uri_surrogate_pair_swf11` | 15 | 2.8s |  |
| 416 | `equals` | 512 | 12.4s |  |
| 417 | `error_geterrormessage` | 779 | 8.0s |  |
| 418 | `error_prototype` | 15 | 8.0s |  |
| 419 | `error_stack_trace` | 45 | 8.0s |  |
| 420 | `error_stack_trace_debug_swf17` | 0 | 25.6s |  |
| 421 | `error_stack_trace_debug_swf18` | 0 | 7.6s |  |
| 422 | `error_stack_trace_edge_cases` | 6 | 7.9s |  |
| 423 | `error_stack_trace_release_swf17` | 0 | 3.0s |  |
| 424 | `error_stack_trace_release_swf18` | 0 | 7.6s |  |
| 425 | `error_throwerror` | 103 | 8.0s |  |
| 426 | `error_tostring` | 29 | 7.9s |  |
| 427 | `error_tostring_more` | 86 | 8.0s |  |
| 428 | `es3_inheritance` | 31 | 8.0s |  |
| 429 | `es4_inheritance` | 30 | 8.0s |  |
| 430 | `es4_interfaces` | 30 | 8.0s |  |
| 431 | `es4_method_binding` | 8 | 7.9s |  |
| 432 | `es4_oop_prototypes` | 14 | 8.1s |  |
| 433 | `es4_protected_inheritance` | 6 | 7.9s |  |
| 434 | `escape` | 71 | 8.0s |  |
| 435 | `escape_multi_byte` | 45 | 8.2s |  |
| 436 | `event_bubbles` | 2 | 7.9s |  |
| 437 | `event_cancelable` | 2 | 7.8s |  |
| 438 | `event_clone` | 20 | 7.9s |  |
| 439 | `event_clone_error_redispatch` | 3 | 8.0s |  |
| 440 | `event_clone_on_redispatch` | 10 | 8.0s |  |
| 441 | `event_formattostring` | 31 | 8.0s |  |
| 442 | `event_isdefaultprevented` | 12 | 7.9s |  |
| 443 | `event_target_getter` | 5 | 3.0s |  |
| 444 | `event_target_set` | 9 | 7.8s |  |
| 445 | `event_type` | 1 | 7.9s |  |
| 446 | `event_valueof_tostring` | 18 | 8.1s |  |
| 447 | `eventdispatcher_dispatchevent` | 12 | 8.1s |  |
| 448 | `eventdispatcher_dispatchevent_cancel` | 20 | 8.2s |  |
| 449 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 8.1s |  |
| 450 | `eventdispatcher_dispatchevent_indirect` | 9 | 8.1s |  |
| 451 | `eventdispatcher_dispatchevent_this` | 5 | 7.9s |  |
| 452 | `eventdispatcher_haseventlistener` | 25 | 8.0s |  |
| 453 | `eventdispatcher_interface_invoke` | 1 | 8.0s |  |
| 454 | `eventdispatcher_tostring` | 10 | 9.0s |  |
| 455 | `eventdispatcher_willtrigger` | 25 | 9.0s |  |
| 456 | `falsiness` | 30 | 9.0s |  |
| 457 | `fast_index_access` | 12 | 9.1s |  |
| 458 | `filefilter_properties` | 4 | 9.1s |  |
| 459 | `filereference_browse_cancel` | 3 | 9.0s |  |
| 460 | `filereference_browse_select` | 9 | 3.5s |  |
| 461 | `filereference_load` | 31 | 9.1s |  |
| 462 | `filereference_save` | 16 | 9.2s |  |
| 463 | `filereference_save_and_browse` | 42 | 9.2s |  |
| 464 | `filereference_save_and_load` | 22 | 9.1s |  |
| 465 | `filereference_uninitialized` | 8 | 9.0s |  |
| 466 | `filereferencelist_browse_cancel` | 6 | 9.0s |  |
| 467 | `filereferencelist_browse_select` | 7 | 9.2s |  |
| 468 | `filter_rewind` | 8 | 30.5s |  |
| 469 | `filters_array_holes` | 25 | 10.9s |  |
| 470 | `finddef` | 3 | 8.9s |  |
| 471 | `findprop_global_prototype` | 6 | 9.0s |  |
| 472 | `flash_media_video_constructor` | 156 | 9.9s |  |
| 473 | `flash_media_video_rotation_probe` | 27 | 9.1s |  |
| 474 | `flash_media_video_setter` | 40 | 9.5s |  |
| 475 | `flash_trace` | 17 | 9.0s |  |
| 476 | `flash_ui_mouse_cursor` | 35 | 9.4s |  |
| 477 | `flash_xml` | 29 | 9.2s |  |
| 478 | `flash_xml_cloneNode` | 22 | 9.0s |  |
| 479 | `flash_xml_namespace` | 109 | 9.0s |  |
| 480 | `flash_xml_removeNode` | 60 | 9.1s |  |
| 481 | `focus_events_code` | 161 | 30.3s |  |
| 482 | `focus_events_key_basic` | 132 | 29.9s |  |
| 483 | `focus_events_key_navigation` | 53 | 29.9s |  |
| 484 | `focus_events_key_same_object` | 26 | 9.3s |  |
| 485 | `focus_events_mixed_key_mouse` | 100 | 30.3s |  |
| 486 | `focus_events_mouse_basic` | 260 | 30.2s |  |
| 487 | `focus_events_mouse_focusable` | 112 | 30.7s |  |
| 488 | `focus_events_mouse_same_object` | 40 | 9.4s |  |
| 489 | `focus_remove` | 20 | 30.2s |  |
| 490 | `focus_root_movie` | 4 | 30.4s |  |
| 491 | `focus_stage` | 1 | 9.2s |  |
| 492 | `focusrect` | 18 | 10.0s |  |
| 493 | `focusrect_focuslost` | 9 | 9.2s |  |
| 494 | `focusrect_property` | 110 | 3.3s |  |
| 495 | `font_description_clone` | 14 | 28.4s |  |
| 496 | `font_embedded` | 24 | 28.8s |  |
| 497 | `font_enumeratefonts` | 41 | 9.3s |  |
| 498 | `font_enumeratefonts_filter` | 4 | 9.4s |  |
| 499 | `font_enumeratefonts_order` | 9 | 10.2s |  |
| 500 | `font_hasglyphs` | 40 | 9.3s |  |
| 501 | `font_registerfont` | 129 | 9.9s |  |
| 502 | `framelabel_constr` | 5 | 8.8s |  |
| 503 | `function_call` | 12 | 3.4s |  |
| 504 | `function_call_arguments` | 46 | 9.0s |  |
| 505 | `function_call_arguments_enumerate` | 5 | 8.7s |  |
| 506 | `function_call_coercion` | 108 | 9.2s |  |
| 507 | `function_call_default` | 6 | 8.8s |  |
| 508 | `function_call_rest` | 22 | 8.7s |  |
| 509 | `function_call_types` | 3 | 8.7s |  |
| 510 | `function_call_via_apply` | 11 | 8.7s |  |
| 511 | `function_call_via_call` | 3 | 8.6s |  |
| 512 | `function_display_anonymous` | 7 | 3.3s |  |
| 513 | `function_length` | 6 | 8.7s |  |
| 514 | `function_object` | 2 | 8.6s |  |
| 515 | `function_proto` | 5 | 8.5s |  |
| 516 | `function_proto_created` | 61 | 8.6s |  |
| 517 | `function_to_locale_string` | 4 | 8.6s |  |
| 518 | `function_to_string` | 4 | 8.5s |  |
| 519 | `function_type` | 6 | 8.5s |  |
| 520 | `function_unbound_this` | 51 | 8.7s |  |
| 521 | `function_value_of` | 4 | 8.5s |  |
| 522 | `game_input` | 4 | 8.5s |  |
| 523 | `generate_random_bytes` | 3 | 8.6s |  |
| 524 | `geom_transform` | 74 | 29.2s |  |
| 525 | `get_definition_by_name` | 11 | 8.6s |  |
| 526 | `get_qualified_class_name` | 20 | 8.7s |  |
| 527 | `get_qualified_super_class_name` | 18 | 8.6s |  |
| 528 | `get_slot_edge_cases` | 1 | 8.6s |  |
| 529 | `get_timer` | 2 | 3.3s |  |
| 530 | `getglobalslot` | 1 | 8.6s |  |
| 531 | `getouterscope` | 8 | 8.6s |  |
| 532 | `getouterscope_two_classobjects` | 13 | 8.7s |  |
| 533 | `getter_different_namespace_setter` | 2 | 8.5s |  |
| 534 | `glow_filter` | 127 | 9.0s |  |
| 535 | `goto_button_nested_framescript` | 28 | 28.4s |  |
| 536 | `goto_framescript_queued/swf10` | 59 | 28.7s |  |
| 537 | `goto_framescript_queued/swf9` | 52 | 1.4s |  |
| 538 | `goto_framescript_queued_same_frame` | 4 | 28.0s |  |
| 539 | `goto_in_constructframe` | 12 | 28.2s |  |
| 540 | `goto_in_scene_last_frame` | 2 | 28.0s |  |
| 541 | `goto_methods` | 56 | 9.0s |  |
| 542 | `goto_methods_swfver10` | 8 | 8.6s |  |
| 543 | `goto_nested_construct_sibling` | 18 | 9.0s |  |
| 544 | `goto_nested_framescript` | 9 | 8.7s |  |
| 545 | `goto_on_orphan` | 15 | 28.1s |  |
| 546 | `gradient_bevel_filter` | 206 | 8.8s |  |
| 547 | `gradient_glow_filter` | 206 | 8.5s |  |
| 548 | `graphic_linkage` | 9 | 8.8s |  |
| 549 | `graphics_bad_direct_commands` | 5 | 9.7s |  |
| 550 | `graphics_bitmap_fill` | 0 | 30.6s |  |
| 551 | `graphics_bitmaps` | 0 | 9.2s |  |
| 552 | `graphics_direct_commands` | 0 | 9.3s |  |
| 553 | `graphics_draw_triangles` | 98 | 29.1s |  |
| 554 | `graphics_gradients` | 0 | 8.9s |  |
| 555 | `graphics_gradients_nulls` | 0 | 8.8s |  |
| 556 | `graphics_path` | 56 | 8.6s |  |
| 557 | `graphics_round_rects` | 0 | 10.5s |  |
| 558 | `graphics_simple_shapes` | 0 | 8.8s |  |
| 559 | `greaterequals` | 512 | 12.9s |  |
| 560 | `greaterthan` | 512 | 12.8s |  |
| 561 | `has_own_property` | 102 | 9.4s |  |
| 562 | `hasownproperty_namespaces` | 2 | 8.7s |  |
| 563 | `hello_world` | 1 | 8.6s |  |
| 564 | `hittest_morph` | 30 | 8.8s |  |
| 565 | `id3_info` | 8 | 28.1s |  |
| 566 | `if_eq` | 10 | 8.7s |  |
| 567 | `if_gt` | 1 | 8.7s |  |
| 568 | `if_gte` | 10 | 3.3s |  |
| 569 | `if_lt` | 1 | 1.3s |  |
| 570 | `if_lte` | 10 | 8.5s |  |
| 571 | `if_ne` | 7 | 3.3s |  |
| 572 | `if_stricteq` | 6 | 8.7s |  |
| 573 | `if_strictne` | 11 | 8.6s |  |
| 574 | `ime_linux_dead_keys` | 10 | 8.6s |  |
| 575 | `in` | 102 | 9.2s |  |
| 576 | `inclocal` | 46 | 8.6s |  |
| 577 | `inclocal_i` | 46 | 7.2s |  |
| 578 | `increment` | 46 | 7.2s |  |
| 579 | `increment_i` | 46 | 7.3s |  |
| 580 | `indexing_delete` | 75 | 7.3s |  |
| 581 | `indexof_xml` | 10 | 7.2s |  |
| 582 | `init_callee_cached` | 24 | 7.5s |  |
| 583 | `instanceof` | 58 | 7.6s |  |
| 584 | `instantiate_root_character` | 4 | 7.6s |  |
| 585 | `instantiation_on_enter_frame` | 7 | 25.2s |  |
| 586 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.3s |  |
| 587 | `int_constr` | 92 | 7.5s |  |
| 588 | `int_edge_cases` | 19 | 25.2s |  |
| 589 | `int_instanceof` | 3 | 7.1s |  |
| 590 | `int_tofixed` | 1215 | 7.1s |  |
| 591 | `int_toprecision` | 1125 | 7.8s |  |
| 592 | `int_tostring` | 3375 | 7.5s |  |
| 593 | `interactiveobject_enabled` | 25 | 7.3s |  |
| 594 | `interface_namespaces` | 78 | 7.6s |  |
| 595 | `invalid_utf8` | 12 | 7.8s |  |
| 596 | `is_finite` | 46 | 7.2s |  |
| 597 | `is_nan` | 46 | 7.2s |  |
| 598 | `is_prototype_of` | 12 | 7.4s |  |
| 599 | `issue_10221` | 2 | 7.4s |  |
| 600 | `issue_13780` | 12 | 7.7s |  |
| 601 | `issue_14901` | 1 | 7.7s |  |
| 602 | `issue_17675_edittext_paste_maxchars` | 1 | 7.4s |  |
| 603 | `issue_5292` | 5 | 7.3s |  |
| 604 | `issue_8630` | 2 | 7.3s |  |
| 605 | `issue_8630_placeremoveplace` | 15 | 7.7s |  |
| 606 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.4s |  |
| 607 | `issue_8630_scriptremove` | 11 | 7.2s |  |
| 608 | `istype` | 24 | 2.5s |  |
| 609 | `istypelate` | 58 | 7.5s |  |
| 610 | `istypelate_coerce` | 198 | 8.1s |  |
| 611 | `jpeg_loader_context` | 6 | 2.5s |  |
| 612 | `json_errors` | 9 | 24.4s |  |
| 613 | `json_parse` | 21 | 2.6s |  |
| 614 | `json_parse_errors` | 84 | 7.2s |  |
| 615 | `json_stringify` | 12 | 7.5s |  |
| 616 | `json_stringify_function` | 12 | 7.2s |  |
| 617 | `json_stringify_order` | 1 | 7.2s |  |
| 618 | `json_version_gated` | 1 | 29.2s |  |
| 619 | `key_input_80percent` | 1812 | 28.1s |  |
| 620 | `key_input_location` | 126 | 8.8s |  |
| 621 | `key_input_numpad` | 384 | 8.4s |  |
| 622 | `large_preload_from_bytes` | 51 | 12.4s |  |
| 623 | `large_preload_from_url` | 27 | 10.8s |  |
| 624 | `large_preload_image_from_bytes` | 25 | 9.3s |  |
| 625 | `lazyinit` | 17 | 8.7s |  |
| 626 | `lessequals` | 512 | 12.9s |  |
| 627 | `lessthan` | 512 | 12.9s |  |
| 628 | `loader_bitmap_transparency` | 14 | 8.7s |  |
| 629 | `loader_bytes_unknown_content` | 14 | 8.7s |  |
| 630 | `loader_child_getdefinition` | 5 | 8.8s |  |
| 631 | `loader_duplicate_class` | 48 | 10.6s |  |
| 632 | `loader_duplicate_coerce` | 3 | 8.8s |  |
| 633 | `loader_duplicate_coerce_new_domain` | 4 | 8.6s |  |
| 634 | `loader_error_in_root_ctor` | 4 | 8.8s |  |
| 635 | `loader_events` | 92 | 9.6s |  |
| 636 | `loader_image` | 8 | 9.1s |  |
| 637 | `loader_jpegxr` | 2 | 28.2s |  |
| 638 | `loader_jpegxr_alpha` | 1 | 28.0s |  |
| 639 | `loader_loadbytes_events` | 30 | 9.3s |  |
| 640 | `loader_loadbytes_invalid_png` | 4 | 8.7s |  |
| 641 | `loader_loadbytes_url` | 12 | 8.9s |  |
| 642 | `loader_loaderurl` | 6 | 9.1s |  |
| 643 | `loader_method` | 85 | 8.6s |  |
| 644 | `loader_noninteractive_try_click_root` | 5 | 28.6s |  |
| 645 | `loader_reuse` | 38 | 8.8s |  |
| 646 | `loader_try_click_root` | 16 | 8.9s |  |
| 647 | `loader_unknown_content` | 24 | 8.8s |  |
| 648 | `loader_visibility_interactive` | 1 | 8.6s |  |
| 649 | `loaderinfo_events` | 7 | 8.6s |  |
| 650 | `loaderinfo_loadurl` | 12 | 8.5s |  |
| 651 | `loaderinfo_more` | 6 | 8.8s |  |
| 652 | `loaderinfo_properties` | 18 | 28.1s |  |
| 653 | `loaderinfo_properties_not_loaded` | 23 | 8.7s |  |
| 654 | `loaderinfo_quine` | 1005 | 8.5s |  |
| 655 | `loaderinfo_root` | 10 | 8.6s |  |
| 656 | `loaderinfo_root_allows` | 2 | 8.5s |  |
| 657 | `localconnection` | 890 | 11.2s |  |
| 658 | `localconnection_send` | 4 | 24.1s |  |
| 659 | `lshift` | 1058 | 15.4s |  |
| 660 | `mask_reapply` | 1 | 24.4s |  |
| 661 | `math` | 497 | 7.5s |  |
| 662 | `matrix` | 338 | 15.9s |  |
| 663 | `matrix3d` | 57 | 23.3s |  |
| 664 | `matrix3d_append` | 16 | 7.1s |  |
| 665 | `matrix3d_append_prepend_scale` | 86 | 7.1s |  |
| 666 | `matrix3d_append_prepend_translation` | 42 | 7.1s |  |
| 667 | `matrix3d_append_rotation` | 23 | 7.2s |  |
| 668 | `matrix3d_compose` | 34 | 7.2s |  |
| 669 | `matrix3d_constructor_clone` | 15 | 7.2s |  |
| 670 | `matrix3d_copy_column` | 83 | 7.2s |  |
| 671 | `matrix3d_copy_from` | 19 | 7.2s |  |
| 672 | `matrix3d_copy_raw_data_from` | 55 | 2.9s |  |
| 673 | `matrix3d_copy_raw_data_to` | 38 | 7.2s |  |
| 674 | `matrix3d_copy_row` | 83 | 7.1s |  |
| 675 | `matrix3d_copy_to_matrix3d` | 19 | 7.1s |  |
| 676 | `matrix3d_determinant` | 182 | 7.6s |  |
| 677 | `matrix3d_interpolate` | 21 | 7.4s |  |
| 678 | `matrix3d_invert` | 18 | 7.0s |  |
| 679 | `matrix3d_position` | 19 | 7.6s |  |
| 680 | `matrix3d_precision` | 28 | 7.1s |  |
| 681 | `matrix3d_prepend` | 16 | 7.0s |  |
| 682 | `matrix3d_raw_data` | 33 | 7.2s |  |
| 683 | `matrix3d_transform_vector` | 52 | 7.3s |  |
| 684 | `matrix3d_transpose` | 5 | 7.1s |  |
| 685 | `method_association` | 5 | 7.0s |  |
| 686 | `method_without_body` | 3 | 23.0s |  |
| 687 | `missing_external_interface` | 10 | 7.4s |  |
| 688 | `modulo` | 1058 | 15.5s |  |
| 689 | `morph_shape` | 2 | 23.5s |  |
| 690 | `mouse_children` | 192 | 23.2s |  |
| 691 | `mouse_click_events` | 90 | 23.2s |  |
| 692 | `mouse_double_click_events` | 188 | 7.1s |  |
| 693 | `mouse_empty_parent` | 4 | 7.0s |  |
| 694 | `mouse_over_while_dragging` | 3 | 7.0s |  |
| 695 | `mouse_pick_avm1_root` | 2 | 22.8s |  |
| 696 | `mouse_pick_button_mode` | 2 | 7.0s |  |
| 697 | `mouse_pick_dobj_mask` | 4 | 7.3s |  |
| 698 | `mouse_pick_masking` | 7 | 23.2s |  |
| 699 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 31.2s |  |
| 700 | `mouse_pick_non_interactive_dobj_mask` | 3 | 30.2s |  |
| 701 | `mouse_pick_text` | 8 | 9.7s |  |
| 702 | `mouse_sibling` | 8 | 9.2s |  |
| 703 | `mouse_wheel_events` | 36 | 30.2s |  |
| 704 | `mouseevent_constr` | 66 | 9.8s |  |
| 705 | `mouseevent_stagexy` | 35 | 9.4s |  |
| 706 | `mouseevent_valueof_tostring` | 28 | 9.2s |  |
| 707 | `movieclip_addframescript` | 3 | 28.5s |  |
| 708 | `movieclip_addframescript_error` | 9 | 8.9s |  |
| 709 | `movieclip_child_property` | 16 | 9.2s |  |
| 710 | `movieclip_constr` | 21 | 9.1s |  |
| 711 | `movieclip_currentlabels` | 17 | 28.4s |  |
| 712 | `movieclip_currentlabels_dupes1` | 46 | 30.9s |  |
| 713 | `movieclip_currentlabels_dupes2` | 30 | 9.1s |  |
| 714 | `movieclip_currentlabels_dupes3` | 67 | 9.1s |  |
| 715 | `movieclip_currentscene` | 12 | 30.6s |  |
| 716 | `movieclip_dispatchevent` | 430 | 9.6s |  |
| 717 | `movieclip_dispatchevent_cancel` | 102 | 9.3s |  |
| 718 | `movieclip_dispatchevent_handlerorder` | 251 | 9.1s |  |
| 719 | `movieclip_dispatchevent_selfadd` | 80 | 9.0s |  |
| 720 | `movieclip_dispatchevent_target` | 899 | 9.1s |  |
| 721 | `movieclip_displayevents` | 96 | 31.7s |  |
| 722 | `movieclip_displayevents_clickgoto` | 676 | 30.3s |  |
| 723 | `movieclip_displayevents_clickgoto2` | 2001 | 10.2s |  |
| 724 | `movieclip_displayevents_clickplay` | 575 | 9.6s |  |
| 725 | `movieclip_displayevents_clicksymbol` | 562 | 4.0s |  |
| 726 | `movieclip_displayevents_constructframegoto` | 140 | 9.3s |  |
| 727 | `movieclip_displayevents_constructframeplay` | 50 | 9.1s |  |
| 728 | `movieclip_displayevents_constructframesymbol` | 144 | 9.0s |  |
| 729 | `movieclip_displayevents_dblhandler` | 21 | 8.7s |  |
| 730 | `movieclip_displayevents_enterframegoto` | 149 | 9.7s |  |
| 731 | `movieclip_displayevents_enterframeplay` | 48 | 9.2s |  |
| 732 | `movieclip_displayevents_enterframesymbol` | 149 | 28.6s |  |
| 733 | `movieclip_displayevents_exitframegoto` | 106 | 8.9s |  |
| 734 | `movieclip_displayevents_exitframeplay` | 44 | 9.5s |  |
| 735 | `movieclip_displayevents_exitframesymbol` | 135 | 9.5s |  |
| 736 | `movieclip_displayevents_looping` | 63 | 29.0s |  |
| 737 | `movieclip_displayevents_stopped` | 113 | 9.1s |  |
| 738 | `movieclip_displayevents_swap` | 96 | 3.1s |  |
| 739 | `movieclip_displayevents_timeline` | 128 | 9.9s |  |
| 740 | `movieclip_drawrect` | 54 | 9.2s |  |
| 741 | `movieclip_frameconstruct_skipped` | 9 | 8.9s |  |
| 742 | `movieclip_goto_during_frame_script` | 15 | 40.3s |  |
| 743 | `movieclip_goto_overwrite` | 14 | 29.8s |  |
| 744 | `movieclip_goto_scene_last_frame_int` | 1 | 30.0s |  |
| 745 | `movieclip_goto_scene_last_frame_label` | 1 | 3.6s |  |
| 746 | `movieclip_gotoandplay` | 15 | 36.4s |  |
| 747 | `movieclip_gotoandstop` | 13 | 10.1s |  |
| 748 | `movieclip_gotoandstop_children` | 4 | 39.3s |  |
| 749 | `movieclip_gotoandstop_framescripts1` | 4 | 9.0s |  |
| 750 | `movieclip_gotoandstop_framescripts2` | 4 | 3.4s |  |
| 751 | `movieclip_gotoandstop_framescripts_self` | 7 | 29.4s |  |
| 752 | `movieclip_gotoandstop_queueing` | 12 | 39.0s |  |
| 753 | `movieclip_hittest` | 67 | 8.5s |  |
| 754 | `movieclip_next_frame` | 2 | 8.5s |  |
| 755 | `movieclip_next_scene` | 6 | 40.3s |  |
| 756 | `movieclip_play` | 3 | 9.8s |  |
| 757 | `movieclip_prev_frame` | 3 | 8.2s |  |
| 758 | `movieclip_prev_scene` | 7 | 10.0s |  |
| 759 | `movieclip_properties` | 79 | 39.0s |  |
| 760 | `movieclip_queued_noop_goto_swf10` | 9 | 10.3s |  |
| 761 | `movieclip_queued_noop_goto_swf9` | 7 | 1.7s |  |
| 762 | `movieclip_scenes` | 11 | 8.4s |  |
| 763 | `movieclip_soundtransform` | 831 | 31.1s |  |
| 764 | `movieclip_stop` | 1 | 9.9s |  |
| 765 | `movieclip_super_is_symbol` | 20 | 8.8s |  |
| 766 | `movieclip_symbol_constr` | 8 | 10.1s |  |
| 767 | `movieclip_text_mousedown` | 1 | 10.1s |  |
| 768 | `movieclip_willtrigger` | 5 | 10.4s |  |
| 769 | `multiply` | 1058 | 22.6s |  |
| 770 | `namespace_constr` | 253 | 8.8s |  |
| 771 | `namespace_constr_args` | 1 | 8.7s |  |
| 772 | `namespace_enumeration_order` | 7 | 26.9s |  |
| 773 | `nan_scale` | 9 | 10.3s |  |
| 774 | `native_menu_basic` | 19 | 11.5s |  |
| 775 | `navigateToURL_target_normalize` | 107 | 43.8s |  |
| 776 | `negate` | 30 | 9.3s |  |
| 777 | `negative_volume_panned` | 0 | 8.9s |  |
| 778 | `nested_iteration` | 11 | 7.7s |  |
| 779 | `net_getClassByAlias` | 3 | 8.6s |  |
| 780 | `net_navigateToURL` | 57 | 9.0s |  |
| 781 | `net_stream_play_options` | 6 | 8.6s |  |
| 782 | `netconnection_close` | 55 | 7.9s |  |
| 783 | `netconnection_properties` | 78 | 7.7s |  |
| 784 | `netconnection_send_remote` | 50 | 30.8s |  |
| 785 | `netconnection_serialize_arrays` | 6 | 8.7s |  |
| 786 | `netfilterevent` | 10 | 29.6s |  |
| 787 | `netstream_client` | 10 | 28.3s |  |
| 788 | `netstream_connect` | 7 | 8.8s |  |
| 789 | `netstream_flv_date` | 4 | 8.7s |  |
| 790 | `newactivation_in_script_init` | 3 | 8.6s |  |
| 791 | `newclass_mismatched` | 4 | 8.7s |  |
| 792 | `newclass_twice` | 3 | 8.6s |  |
| 793 | `nonconflicting_declarations` | 0 | 3.3s |  |
| 794 | `null_void_types` | 8 | 8.8s |  |
| 795 | `number_autoconv` | 21 | 3.3s |  |
| 796 | `number_autoconv_amf` | 132 | 8.7s |  |
| 797 | `number_autoconv_array_sort_32bit` | 1 | 8.6s |  |
| 798 | `number_constr` | 58 | 8.7s |  |
| 799 | `number_convert_edge_cases` | 180 | 28.1s |  |
| 800 | `number_toexponential` | 378 | 8.7s |  |
| 801 | `number_toexponential2` | 35 | 3.2s |  |
| 802 | `number_tofixed` | 378 | 8.5s |  |
| 803 | `number_toprecision` | 350 | 8.7s |  |
| 804 | `obfuscated_class_names` | 3 | 8.6s |  |
| 805 | `object_enumeration` | 10 | 8.6s |  |
| 806 | `object_prototype` | 4 | 8.6s |  |
| 807 | `object_to_locale_string` | 2 | 8.5s |  |
| 808 | `object_to_string` | 2 | 8.4s |  |
| 809 | `object_value_of` | 2 | 3.1s |  |
| 810 | `op_coerce` | 54 | 8.6s |  |
| 811 | `op_coerce_x` | 54 | 8.5s |  |
| 812 | `op_escxattr` | 2 | 8.5s |  |
| 813 | `op_escxelem` | 2 | 8.5s |  |
| 814 | `op_lookupswitch` | 4 | 8.5s |  |
| 815 | `optimize_coerce` | 1 | 8.4s |  |
| 816 | `orphan_movie_complex` | 80 | 9.1s |  |
| 817 | `orphan_movie_reorder` | 111 | 28.2s |  |
| 818 | `orphan_removeobject` | 636 | 28.8s |  |
| 819 | `package_namespace` | 7 | 8.4s |  |
| 820 | `param_default_value_has_zero_cpool_index` | 1 | 24.8s |  |
| 821 | `parent_early_access_child` | 16 | 24.4s |  |
| 822 | `parse_float` | 81 | 23.5s |  |
| 823 | `parse_float_swf10` | 81 | 7.1s |  |
| 824 | `parse_int` | 135 | 7.6s |  |
| 825 | `perspective_projection` | 1443 | 23.7s |  |
| 826 | `perspective_projection_basic` | 40 | 7.3s |  |
| 827 | `pixelbender_ceil` | 77 | 7.5s |  |
| 828 | `pixelbender_conditional` | 138 | 7.6s |  |
| 829 | `pixelbender_conversions` | 270 | 7.7s |  |
| 830 | `pixelbender_dithering` | 8 | 28.8s |  |
| 831 | `pixelbender_div` | 36 | 7.4s |  |
| 832 | `pixelbender_effect_BlurredFocus` | 0 | 30.5s |  |
| 833 | `pixelbender_effect_glassDisplace` | 0 | 12.9s |  |
| 834 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 27.4s |  |
| 835 | `pixelbender_effect_smudge` | 0 | 10.4s |  |
| 836 | `pixelbender_effect_tintype` | 0 | 9.7s |  |
| 837 | `pixelbender_effect_twirl` | 0 | 11.0s |  |
| 838 | `pixelbender_eof` | 7 | 7.2s |  |
| 839 | `pixelbender_images` | 0 | 9.4s |  |
| 840 | `pixelbender_input` | 103 | 26.0s |  |
| 841 | `pixelbender_logicalnot` | 20 | 7.3s |  |
| 842 | `pixelbender_malformed_data` | 190 | 24.7s |  |
| 843 | `pixelbender_multiple_out_params` | 1 | 7.2s |  |
| 844 | `pixelbender_no_out_param` | 6 | 7.5s |  |
| 845 | `pixelbender_outputs` | 13 | 7.5s |  |
| 846 | `pixelbender_padding_bytes` | 22 | 7.3s |  |
| 847 | `pixelbender_param_qualifier` | 512 | 7.4s |  |
| 848 | `pixelbender_parameters` | 1563 | 7.7s |  |
| 849 | `pixelbender_parameters_bool` | 240 | 7.6s |  |
| 850 | `pixelbender_parameters_int_vs_bool` | 54 | 7.3s |  |
| 851 | `pixelbender_parse_errors` | 6 | 7.3s |  |
| 852 | `pixelbender_rsqrt` | 24 | 7.4s |  |
| 853 | `pixelbender_select_kinds` | 8 | 7.5s |  |
| 854 | `pixelbender_shaderdata` | 49 | 7.4s |  |
| 855 | `pixelbender_shaderdata_setter` | 99 | 7.7s |  |
| 856 | `pixelbender_sign` | 60 | 7.6s |  |
| 857 | `pixelbender_vector_output` | 11 | 7.5s |  |
| 858 | `place_and_lookup/swf10` | 33 | 7.4s |  |
| 859 | `place_and_lookup/swf9` | 33 | 1.2s |  |
| 860 | `place_multiple` | 17 | 7.5s |  |
| 861 | `place_object_replace` | 9 | 24.0s |  |
| 862 | `place_object_replace_2` | 24 | 24.1s |  |
| 863 | `place_object_same_depth_frame` | 1 | 23.1s |  |
| 864 | `point` | 132 | 7.6s |  |
| 865 | `primitive_edge_cases` | 1 | 22.7s |  |
| 866 | `primitive_keys` | 54 | 6.9s |  |
| 867 | `primitive_toString` | 277 | 7.1s |  |
| 868 | `primitive_valueOf` | 285 | 6.8s |  |
| 869 | `print_job_options` | 3 | 6.9s |  |
| 870 | `property_is_enumerable` | 114 | 7.8s |  |
| 871 | `property_is_enumerable_reset` | 23 | 6.9s |  |
| 872 | `property_priority` | 22 | 7.4s |  |
| 873 | `property_priority_chained` | 4 | 6.9s |  |
| 874 | `property_priority_definition_names_order` | 2 | 7.4s |  |
| 875 | `property_priority_three_level` | 6 | 7.2s |  |
| 876 | `propertyisenumerable_namespaces` | 6 | 7.0s |  |
| 877 | `prototype_set_null` | 7 | 7.0s |  |
| 878 | `proxy_callproperty` | 24 | 7.0s |  |
| 879 | `proxy_deleteproperty` | 64 | 7.3s |  |
| 880 | `proxy_enumeration` | 34 | 7.0s |  |
| 881 | `proxy_getproperty` | 77 | 7.1s |  |
| 882 | `proxy_hasownproperty` | 8 | 2.8s |  |
| 883 | `proxy_hasproperty` | 32 | 7.3s |  |
| 884 | `proxy_not_overridden` | 54 | 7.1s |  |
| 885 | `proxy_serialize` | 9 | 7.1s |  |
| 886 | `proxy_setproperty` | 42 | 7.2s |  |
| 887 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.9s |  |
| 888 | `qname_constr` | 32 | 7.0s |  |
| 889 | `qname_constr_namespace` | 24 | 7.0s |  |
| 890 | `qname_enumeration` | 9 | 7.0s |  |
| 891 | `qname_indexing` | 23 | 2.8s |  |
| 892 | `qname_tostring` | 25 | 7.2s |  |
| 893 | `qname_valueof` | 29 | 7.1s |  |
| 894 | `rectangle` | 1094 | 7.6s |  |
| 895 | `regexp_constr` | 148 | 7.3s |  |
| 896 | `regexp_exec` | 19 | 7.0s |  |
| 897 | `regexp_extended` | 47 | 7.0s |  |
| 898 | `regexp_multiargs` | 1 | 7.0s |  |
| 899 | `regexp_test` | 27 | 2.9s |  |
| 900 | `regexp_toString` | 10 | 7.2s |  |
| 901 | `register_script_refresh` | 35 | 23.4s |  |
| 902 | `remove_child_clear_field` | 88 | 7.8s |  |
| 903 | `remove_dobj` | 3 | 7.2s |  |
| 904 | `resolve_order` | 4 | 30.4s |  |
| 905 | `responder_null_callbacks` | 1 | 29.0s |  |
| 906 | `rng` | 1 | 10.2s |  |
| 907 | `rootless` | 42 | 8.9s |  |
| 908 | `rshift` | 1058 | 20.7s |  |
| 909 | `rtqname_not_namespace` | 12 | 8.8s |  |
| 910 | `sandbox_type_inherited` | 2 | 9.0s |  |
| 911 | `sandbox_type_local_file` | 1 | 8.8s |  |
| 912 | `sandbox_type_local_network` | 1 | 8.6s |  |
| 913 | `scene_constr` | 8 | 8.8s |  |
| 914 | `scope_optimizations` | 4 | 8.8s |  |
| 915 | `scopes_dont_cache/order-1` | 1 | 28.6s |  |
| 916 | `scopes_dont_cache/order-2` | 1 | 1.1s |  |
| 917 | `security_domain_current` | 2 | 8.9s |  |
| 918 | `selection` | 239 | 9.8s |  |
| 919 | `set_local_0` | 31 | 3.5s |  |
| 920 | `set_property_is_enumerable` | 85 | 9.4s |  |
| 921 | `shaderparameter_value` | 4 | 8.8s |  |
| 922 | `shape_drawrect` | 54 | 8.8s |  |
| 923 | `shared_object_no_root` | 3 | 8.8s |  |
| 924 | `simplebutton_added_to_stage` | 45 | 29.4s |  |
| 925 | `simplebutton_childevents` | 86 | 29.6s |  |
| 926 | `simplebutton_childevents_nested` | 54 | 9.4s |  |
| 927 | `simplebutton_childevents_sprite` | 13 | 9.2s |  |
| 928 | `simplebutton_childprops` | 144 | 9.3s |  |
| 929 | `simplebutton_childshuffle` | 23 | 8.8s |  |
| 930 | `simplebutton_constr` | 36 | 9.2s |  |
| 931 | `simplebutton_constr_childevents` | 48 | 9.3s |  |
| 932 | `simplebutton_constr_params` | 42 | 9.1s |  |
| 933 | `simplebutton_mouseenabled` | 26 | 8.8s |  |
| 934 | `simplebutton_multi_children` | 19 | 9.0s |  |
| 935 | `simplebutton_soundtransform` | 887 | 30.6s |  |
| 936 | `simplebutton_structure` | 27 | 9.0s |  |
| 937 | `simplebutton_symbolclass` | 68 | 9.2s |  |
| 938 | `slot_disp_id_shared_numbering` | 1 | 28.6s |  |
| 939 | `slots_force_autoassigned` | 1 | 8.8s |  |
| 940 | `socket_after_disconnect` | 1 | 32.1s |  |
| 941 | `socket_close` | 2 | 9.2s |  |
| 942 | `socket_connect` | 4 | 30.8s |  |
| 943 | `socket_errors` | 56 | 9.8s |  |
| 944 | `socket_read_big` | 48 | 9.3s |  |
| 945 | `socket_read_little` | 48 | 3.4s |  |
| 946 | `socket_read_write_object` | 8 | 9.2s |  |
| 947 | `socket_write_big` | 15 | 9.6s |  |
| 948 | `socket_write_little` | 14 | 9.2s |  |
| 949 | `sound_constructor_with_args` | 6 | 9.5s |  |
| 950 | `sound_embeddedprops` | 26 | 9.5s |  |
| 951 | `sound_play` | 19 | 9.6s |  |
| 952 | `sound_rootless` | 7 | 9.4s |  |
| 953 | `sound_valueof` | 33 | 9.5s |  |
| 954 | `soundchannel_soundtransform` | 835 | 32.9s |  |
| 955 | `soundchannel_soundtransform_exists` | 5 | 30.8s |  |
| 956 | `soundchannel_stop` | 8 | 30.8s |  |
| 957 | `soundmixer_buffertime` | 5 | 9.2s |  |
| 958 | `soundmixer_soundtransform` | 900 | 11.7s |  |
| 959 | `soundmixer_stopall` | 6 | 30.7s |  |
| 960 | `soundtransform` | 442 | 16.0s |  |
| 961 | `space_justifier_clone` | 12 | 9.2s |  |
| 962 | `sprite_with_frames` | 0 | 31.9s |  |
| 963 | `stage3d_agal_cross_product` | 0 | 13.2s |  |
| 964 | `stage3d_agal_upload_errors` | 66 | 14.9s |  |
| 965 | `stage3d_bitmap` | 0 | 37.8s |  |
| 966 | `stage3d_blend` | 81 | 38.2s |  |
| 967 | `stage3d_context3d_string_args` | 158 | 10.7s |  |
| 968 | `stage3d_errors` | 7 | 9.3s |  |
| 969 | `stage3d_errors_atf` | 3 | 10.9s |  |
| 970 | `stage3d_errors_swf_29` | 6 | 9.4s |  |
| 971 | `stage3d_float1_index` | 0 | 33.6s |  |
| 972 | `stage3d_fractal` | 0 | 34.8s |  |
| 973 | `stage3d_ignore_sampler_override` | 0 | 34.7s |  |
| 974 | `stage3d_multistage_triangle` | 3 | 13.0s |  |
| 975 | `stage3d_program_constants_bytearray_be` | 0 | 36.4s |  |
| 976 | `stage3d_program_constants_bytearray_le` | 0 | 13.4s |  |
| 977 | `stage3d_program_constants_invalid_input` | 21 | 10.5s |  |
| 978 | `stage3d_raytrace` | 0 | 59.6s |  |
| 979 | `stage3d_rotating_cube` | 0 | 15.2s |  |
| 980 | `stage3d_sampler` | 0 | 12.0s |  |
| 981 | `stage3d_sampler_partial_upload` | 0 | 12.0s |  |
| 982 | `stage3d_stencil` | 0 | 32.6s |  |
| 983 | `stage3d_texture` | 0 | 18.2s |  |
| 984 | `stage3d_texture_bytearray` | 0 | 14.0s |  |
| 985 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 13.1s |  |
| 986 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 14.2s |  |
| 987 | `stage3d_triangle` | 0 | 12.4s |  |
| 988 | `stage3d_triangle_bytes4` | 0 | 12.2s |  |
| 989 | `stage3d_triangle_float1` | 0 | 12.2s |  |
| 990 | `stage3d_triangle_index_upload` | 0 | 12.4s |  |
| 991 | `stage3d_x_y` | 22 | 8.9s |  |
| 992 | `stage_access` | 10 | 9.0s |  |
| 993 | `stage_display_state` | 6 | 9.0s |  |
| 994 | `stage_displayobject_properties` | 24 | 8.8s |  |
| 995 | `stage_domain_getQualifiedDefinitionNames` | 5 | 8.8s |  |
| 996 | `stage_framerate_nan` | 7 | 28.5s |  |
| 997 | `stage_framerate_negative` | 6 | 8.6s |  |
| 998 | `stage_framerate_zero` | 6 | 8.6s |  |
| 999 | `stage_invalidate` | 38 | 8.9s |  |
| 1000 | `stage_loaderinfo_properties` | 24 | 28.4s |  |
| 1001 | `stage_mousechildren` | 2 | 8.6s |  |
| 1002 | `stage_mouseenabled` | 15 | 8.6s |  |
| 1003 | `stage_overriden_setters` | 31 | 8.8s |  |
| 1004 | `stage_properties` | 30 | 8.7s |  |
| 1005 | `stage_properties2` | 213 | 8.8s |  |
| 1006 | `stage_scale_factor` | 12 | 33.6s |  |
| 1007 | `stage_stage3Ds_vector` | 1 | 8.4s |  |
| 1008 | `static_length` | 24 | 8.7s |  |
| 1009 | `static_text` | 3 | 8.7s |  |
| 1010 | `static_var_with_this_in_ctor` | 2 | 8.5s |  |
| 1011 | `statictext_text` | 8 | 8.7s |  |
| 1012 | `stored_properties` | 11 | 8.6s |  |
| 1013 | `strict_equality` | 34 | 8.6s |  |
| 1014 | `string_call` | 13 | 8.5s |  |
| 1015 | `string_case` | 23 | 8.6s |  |
| 1016 | `string_char_at` | 27 | 8.6s |  |
| 1017 | `string_char_code_at` | 28 | 3.1s |  |
| 1018 | `string_concat_fromcharcode` | 37 | 8.6s |  |
| 1019 | `string_constr` | 25 | 8.6s |  |
| 1020 | `string_indexof_lastindexof` | 87 | 29.6s |  |
| 1021 | `string_length` | 16 | 28.1s |  |
| 1022 | `string_locale_compare` | 39 | 9.1s |  |
| 1023 | `string_match` | 51 | 9.2s |  |
| 1024 | `string_relational_compare` | 4 | 8.7s |  |
| 1025 | `string_replace` | 51 | 8.9s |  |
| 1026 | `string_search` | 41 | 8.8s |  |
| 1027 | `string_slice_substr_substring` | 170 | 9.8s |  |
| 1028 | `string_split` | 29 | 8.7s |  |
| 1029 | `string_substr_negative` | 21 | 8.6s |  |
| 1030 | `string_substr_weird` | 182 | 8.6s |  |
| 1031 | `stylesheet` | 221 | 9.5s |  |
| 1032 | `stylesheet_parse_color` | 69 | 8.8s |  |
| 1033 | `stylesheet_transform` | 307 | 9.1s |  |
| 1034 | `sub_super_same_field` | 12 | 3.4s |  |
| 1035 | `subclass_superclass_linked_symbol` | 4 | 9.2s |  |
| 1036 | `subtract` | 1058 | 19.9s |  |
| 1037 | `super_get_call` | 12 | 8.7s |  |
| 1038 | `supercall_two_classobjects` | 2 | 8.6s |  |
| 1039 | `supercalls_coerce` | 8 | 8.7s |  |
| 1040 | `supercalls_weird` | 2 | 8.5s |  |
| 1041 | `superinterface_call` | 20 | 8.8s |  |
| 1042 | `superinterface_instanceof` | 18 | 8.9s |  |
| 1043 | `swf8` | 1 | 8.8s |  |
| 1044 | `swf_10_queued_goto_scripts_construct` | 52 | 29.0s |  |
| 1045 | `swf_9_goto_in_enter_frame` | 17 | 8.9s |  |
| 1046 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.9s |  |
| 1047 | `swf_9_queued_goto_scripts` | 6 | 29.1s |  |
| 1048 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 1049 | `swf_9_versioning` | 2 | 8.5s |  |
| 1050 | `swf_wrong_frame_count` | 38 | 9.0s |  |
| 1051 | `swf_wrong_frame_count_isplaying` | 22 | 8.6s |  |
| 1052 | `symbol_class_binary_data` | 8 | 8.6s |  |
| 1053 | `symbol_class_conflict` | 4 | 9.2s |  |
| 1054 | `symbol_class_root_not_zero` | 1 | 8.6s |  |
| 1055 | `symbolclass_invalid_utf8` | 2 | 8.8s |  |
| 1056 | `system_exit` | 3 | 8.7s |  |
| 1057 | `system_setclipboard_null` | 1 | 8.6s |  |
| 1058 | `tab_ordering_arrows` | 998 | 22.5s |  |
| 1059 | `tab_ordering_automatic_advanced` | 184 | 3.0s |  |
| 1060 | `tab_ordering_automatic_basic` | 45 | 20.8s |  |
| 1061 | `tab_ordering_children` | 116 | 2.7s |  |
| 1062 | `tab_ordering_custom_basic` | 34 | 2.7s |  |
| 1063 | `tab_ordering_properties` | 732 | 2.7s |  |
| 1064 | `tab_ordering_stage_tab_children` | 32 | 2.6s |  |
| 1065 | `tab_ordering_stage_tab_children_remove_root` | 5 | 2.7s |  |
| 1066 | `tab_ordering_tabbable` | 47 | 2.6s |  |
| 1067 | `tabstop_properties` | 105 | 19.8s |  |
| 1068 | `text_element_basic` | 34 | 2.7s |  |
| 1069 | `text_engine_fontdescription` | 27 | 2.7s |  |
| 1070 | `text_engine_groupelement` | 64 | 2.7s |  |
| 1071 | `text_run` | 7 | 2.7s |  |
| 1072 | `textblock_createline_errors` | 23 | 2.7s |  |
| 1073 | `textblock_createline_fte` | 9 | 19.9s |  |
| 1074 | `textblock_properties` | 118 | 2.7s |  |
| 1075 | `textbox_click` | 37 | 20.2s |  |
| 1076 | `textfield_event` | 66 | 2.8s |  |
| 1077 | `textfield_focusin_event` | 9 | 2.7s |  |
| 1078 | `textfield_input_dead_keys_windows` | 15 | 2.6s |  |
| 1079 | `textfield_input_events` | 25 | 12.8s |  |
| 1080 | `textfield_unload` | 39 | 19.9s |  |
| 1081 | `textformat` | 1134 | 2.8s |  |
| 1082 | `textformat_display` | 14 | 3.0s |  |
| 1083 | `textformat_font_max_length` | 4 | 2.6s |  |
| 1084 | `textline_inapplicable_properties` | 10 | 2.5s |  |
| 1085 | `textline_name` | 1 | 2.5s |  |
| 1086 | `textline_raw_text_length` | 30 | 2.5s |  |
| 1087 | `textline_splitting_basic` | 76 | 2.7s |  |
| 1088 | `textline_throwerror` | 30 | 2.6s |  |
| 1089 | `textline_validity` | 162 | 2.6s |  |
| 1090 | `throw` | 3 | 2.5s |  |
| 1091 | `timeline_scripts` | 3 | 18.7s |  |
| 1092 | `timer` | 90 | 2.9s |  |
| 1093 | `timer_events` | 3 | 2.6s |  |
| 1094 | `timer_finished` | 11 | 2.6s |  |
| 1095 | `timer_invalid_delay` | 30 | 2.6s |  |
| 1096 | `timer_reset` | 8 | 24.9s |  |
| 1097 | `timer_setdelay` | 5 | 23.7s |  |
| 1098 | `trace` | 12 | 6.9s |  |
| 1099 | `truthiness` | 30 | 6.9s |  |
| 1100 | `try_catch` | 11 | 6.9s |  |
| 1101 | `try_catch_typed` | 12 | 6.9s |  |
| 1102 | `typeof` | 30 | 6.8s |  |
| 1103 | `uint_constr` | 92 | 7.0s |  |
| 1104 | `uint_tofixed` | 1215 | 6.7s |  |
| 1105 | `uint_toprecision` | 1125 | 7.1s |  |
| 1106 | `uint_tostring` | 3375 | 7.1s |  |
| 1107 | `uncaught_error_basic` | 2 | 6.8s |  |
| 1108 | `unchecked_function` | 15 | 6.8s |  |
| 1109 | `unescape` | 28 | 6.9s |  |
| 1110 | `url_loader` | 25 | 6.9s |  |
| 1111 | `url_vars` | 27 | 7.0s |  |
| 1112 | `urlrequest` | 18 | 2.2s |  |
| 1113 | `urlstream_basic` | 5 | 6.8s |  |
| 1114 | `urshift` | 1058 | 14.1s |  |
| 1115 | `utils3d` | 7 | 2.3s |  |
| 1116 | `vector3d` | 397 | 10.0s |  |
| 1117 | `vector3d_near_equals` | 80 | 7.0s |  |
| 1118 | `vector_class` | 36 | 7.3s |  |
| 1119 | `vector_class_call` | 11 | 7.2s |  |
| 1120 | `vector_coercion` | 66 | 7.6s |  |
| 1121 | `vector_concat` | 90 | 7.3s |  |
| 1122 | `vector_constr` | 107 | 7.4s |  |
| 1123 | `vector_enumeration` | 5 | 6.8s |  |
| 1124 | `vector_every` | 92 | 7.6s |  |
| 1125 | `vector_filter` | 95 | 7.7s |  |
| 1126 | `vector_holes` | 24 | 7.0s |  |
| 1127 | `vector_indexof` | 302 | 10.0s |  |
| 1128 | `vector_insertat` | 270 | 7.7s |  |
| 1129 | `vector_int_access` | 4 | 6.8s |  |
| 1130 | `vector_int_delete` | 11 | 6.7s |  |
| 1131 | `vector_join` | 58 | 7.1s |  |
| 1132 | `vector_lastindexof` | 302 | 6.7s |  |
| 1133 | `vector_legacy` | 10 | 6.9s |  |
| 1134 | `vector_map` | 85 | 7.5s |  |
| 1135 | `vector_object_final` | 1 | 6.8s |  |
| 1136 | `vector_object_toString` | 10 | 24.5s |  |
| 1137 | `vector_pushpop` | 255 | 26.0s |  |
| 1138 | `vector_reborrow_bug` | 10 | 7.3s |  |
| 1139 | `vector_removeat` | 172 | 8.6s |  |
| 1140 | `vector_reverse` | 232 | 8.4s |  |
| 1141 | `vector_shiftunshift` | 252 | 7.5s |  |
| 1142 | `vector_slice` | 331 | 9.2s |  |
| 1143 | `vector_sort` | 905 | 15.4s |  |
| 1144 | `vector_splice` | 693 | 11.1s |  |
| 1145 | `vector_splice_fixed_bug_compat` | 4 | 7.7s |  |
| 1146 | `vector_tostring` | 79 | 7.9s |  |
| 1147 | `verification` | 8 | 7.9s |  |
| 1148 | `verify_abnormal_loop` | 1 | 7.3s |  |
| 1149 | `verify_dxns_without_flag` | 3 | 7.9s |  |
| 1150 | `verify_exception_target_two_jumps` | 1 | 7.1s |  |
| 1151 | `verify_exception_targets_edge_case` | 1 | 7.2s |  |
| 1152 | `verify_illegal_opcode` | 1 | 3.3s |  |
| 1153 | `verify_jump_to_middle_of_op` | 1 | 7.3s |  |
| 1154 | `verify_lookup_switch_edge_case` | 1 | 7.2s |  |
| 1155 | `verify_method_info_oob` | 1 | 1.2s |  |
| 1156 | `verify_stack` | 5 | 8.0s |  |
| 1157 | `verify_typecheck` | 4 | 7.5s |  |
| 1158 | `verify_unreachable_exception` | 2 | 7.3s |  |
| 1159 | `versioned_isplaying` | 2 | 7.2s |  |
| 1160 | `virtual_properties` | 16 | 2.9s |  |
| 1161 | `with` | 4 | 7.3s |  |
| 1162 | `wrong_arg_count` | 7 | 7.4s |  |
| 1163 | `xml_abstract_equality` | 36 | 8.9s |  |
| 1164 | `xml_advanced` | 52 | 7.7s |  |
| 1165 | `xml_appendchild` | 10 | 7.2s |  |
| 1166 | `xml_appendchild_swf_v21` | 13 | 3.4s |  |
| 1167 | `xml_as_attribute` | 9 | 7.2s |  |
| 1168 | `xml_attribute` | 35 | 7.5s |  |
| 1169 | `xml_attribute_name` | 40 | 7.3s |  |
| 1170 | `xml_basic` | 33 | 7.4s |  |
| 1171 | `xml_child` | 25 | 7.4s |  |
| 1172 | `xml_childindex` | 7 | 7.2s |  |
| 1173 | `xml_children` | 43 | 8.0s |  |
| 1174 | `xml_class_call` | 9 | 7.2s |  |
| 1175 | `xml_contains` | 197 | 7.5s |  |
| 1176 | `xml_copy` | 20 | 28.7s |  |
| 1177 | `xml_ctor_from_tostring` | 23 | 27.9s |  |
| 1178 | `xml_delete` | 114 | 8.5s |  |
| 1179 | `xml_descendants` | 83 | 8.5s |  |
| 1180 | `xml_duplicate_attribute` | 14 | 8.3s |  |
| 1181 | `xml_elements` | 6 | 8.5s |  |
| 1182 | `xml_equals_namespace_check` | 2 | 8.5s |  |
| 1183 | `xml_explicit_use_namespace` | 5 | 8.2s |  |
| 1184 | `xml_getdescendants_qname` | 21 | 8.4s |  |
| 1185 | `xml_has_property_via_in` | 26 | 8.4s |  |
| 1186 | `xml_hasownproperty` | 6 | 8.4s |  |
| 1187 | `xml_ignore_white` | 6 | 8.6s |  |
| 1188 | `xml_length` | 2 | 8.5s |  |
| 1189 | `xml_list_as_attribute` | 9 | 8.3s |  |
| 1190 | `xml_list_concat` | 20 | 8.4s |  |
| 1191 | `xml_list_ctor_errors` | 34 | 8.4s |  |
| 1192 | `xml_list_delete_clear_parent` | 6 | 8.4s |  |
| 1193 | `xml_list_enumerate` | 4 | 8.5s |  |
| 1194 | `xml_methods_settings` | 3 | 8.5s |  |
| 1195 | `xml_mismatched_tag` | 37 | 8.4s |  |
| 1196 | `xml_namespace` | 39 | 8.4s |  |
| 1197 | `xml_namespace_methods` | 245 | 8.5s |  |
| 1198 | `xml_namespaced_property` | 7 | 8.3s |  |
| 1199 | `xml_no_namespace` | 1 | 8.5s |  |
| 1200 | `xml_nodekind` | 3 | 8.5s |  |
| 1201 | `xml_normalize` | 35 | 8.6s |  |
| 1202 | `xml_notification_bubbling` | 361 | 8.5s |  |
| 1203 | `xml_parent` | 8 | 8.6s |  |
| 1204 | `xml_set_children` | 17 | 8.6s |  |
| 1205 | `xml_set_name` | 34 | 8.5s |  |
| 1206 | `xml_settings` | 6 | 3.2s |  |
| 1207 | `xml_simple_complex_content` | 47 | 8.7s |  |
| 1208 | `xml_socket` | 11 | 8.7s |  |
| 1209 | `xml_text` | 7 | 8.4s |  |
| 1210 | `xml_tostring` | 6 | 8.4s |  |
| 1211 | `xml_tostring_namespace` | 12 | 8.3s |  |
| 1212 | `xml_unescaping` | 23 | 8.6s |  |
| 1213 | `xml_weird_ignores` | 54 | 3.3s |  |
| 1214 | `xml_wildcard` | 11 | 8.6s |  |
| 1215 | `xmldocument` | 254 | 8.7s |  |
| 1216 | `xmlnode` | 3540 | 8.8s |  |
| 1217 | `zero_frame_clip` | 3 | 9.1s |  |

## Ruffle-Matched Tests

**38 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.5s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.0s |  |
| 3 | `blend_transform` | 1 | 1 | 8.8s |  |
| 4 | `bounds_mode` | 6 | 6 | 9.3s |  |
| 5 | `coerce_property` | 3 | 3 | 8.3s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 8.2s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 28.7s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 28.2s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 9.0s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 9.1s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 8.8s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 9.1s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 3.2s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 8.2s |  |
| 15 | `event_handler_exception` | 4 | 4 | 7.9s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 8.8s |  |
| 17 | `goto_framescript_queued/swf13` | 3 | 3 | 28.3s |  |
| 18 | `graphics_draw_path` | 50 | 50 | 28.9s |  |
| 19 | `groupelement_text` | 2 | 2 | 8.8s |  |
| 20 | `int_toexponential` | 76 | 76 | 7.6s |  |
| 21 | `json_parse_numbers` | 4 | 79 | 7.2s |  |
| 22 | `loader_events_2` | 30 | 30 | 9.3s |  |
| 23 | `matrix3d_recompose_edge_cases` | 8 | 85 | 7.5s |  |
| 24 | `number_convert_errors` | 706 | 706 | 8.9s |  |
| 25 | `number_to_string` | 104 | 104 | 9.2s |  |
| 26 | `simplebutton_childevents_script_order` | 4 | 4 | 9.5s |  |
| 27 | `slot_holes_fail` | 1 | 1 | 8.7s |  |
| 28 | `slot_id_exceeds_trait_count` | 1 | 1 | 8.8s |  |
| 29 | `soundchannel_position` | 74 | 74 | 32.2s |  |
| 30 | `soundchannel_soundcomplete` | 10 | 10 | 9.6s |  |
| 31 | `sprite_dropTarget` | 15 | 15 | 9.4s |  |
| 32 | `swf_9_goto_in_construct_frame` | 12 | 12 | 29.0s |  |
| 33 | `textblock_line_changes` | 44 | 44 | 3.1s |  |
| 34 | `textblock_recreateline` | 139 | 140 | 2.7s |  |
| 35 | `textblock_releaselines` | 4 | 4 | 2.7s |  |
| 36 | `uint_toexponential` | 100 | 100 | 7.1s |  |
| 37 | `uncaught_errors_stringified` | 15 | 15 | 6.9s |  |
| 38 | `weird_superinterface_properties` | 1 | 1 | 7.2s |  |

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

**23 tests** with output mismatch, sorted by match rate (best first)

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
| 9 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 10 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 11 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 12 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 13 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 14 | `textjustifier_locale` | 6.1% | 8/132 | 52 | 132 |  |
| 15 | `casi32` | 5.2% | 9/174 | 174 | 166 |  |
| 16 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 17 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 18 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 19 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 20 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 21 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 22 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 23 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
