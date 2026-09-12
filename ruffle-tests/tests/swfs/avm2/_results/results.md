# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-12 03:19 UTC

**Git SHA**: `d8da5a18c3`

**Run Duration**: 218m 22s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1274 |
| Passing | **1212** (95.1%) |
| Ruffle-matched | 36 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1248** (98.0%) |
| Failing | 26 |
| Total expected lines | 157153 |
| Matching lines | 154263 (98.2%) |
| Mismatched lines | 2890 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 26 | 100.0% |

## Passing Tests

**1212 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 37.5s |  |
| 2 | `accessibility` | 1 | 5.9s |  |
| 3 | `accessibilityimplementation` | 18 | 22.2s |  |
| 4 | `activation_class` | 6 | 6.0s |  |
| 5 | `add` | 1058 | 13.8s |  |
| 6 | `agal_compiler` | 13 | 7.7s |  |
| 7 | `air_datagram_socket` | 1 | 7.8s |  |
| 8 | `air_hidden_lookup` | 2 | 5.9s |  |
| 9 | `air_ifilepromise` | 1 | 5.8s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 5.9s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.5s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.5s |  |
| 13 | `all_classes/display/swf10` | 2569 | 6.0s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.5s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.5s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.5s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.5s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.4s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 5.9s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.4s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.4s |  |
| 22 | `all_classes/errors/swf10` | 140 | 5.9s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.4s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.4s |  |
| 25 | `all_classes/events/swf10` | 1638 | 5.9s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.4s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.4s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.5s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.4s |  |
| 30 | `all_classes/security/swf11` | 3 | 5.9s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.4s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.4s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.4s |  |
| 34 | `all_classes/xml/swf30` | 116 | 5.9s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.4s |  |
| 36 | `amf_array_serialization` | 17 | 24.1s |  |
| 37 | `amf_custom_obj` | 26 | 5.9s |  |
| 38 | `amf_dictionary` | 9 | 5.8s |  |
| 39 | `amf_function` | 46 | 5.8s |  |
| 40 | `amf_invalid_date` | 2 | 5.8s |  |
| 41 | `amf_missing_prop` | 6 | 5.9s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 5.8s |  |
| 43 | `amf_setter_error` | 8 | 5.9s |  |
| 44 | `amf_vector` | 40 | 32.8s |  |
| 45 | `amf_xml` | 6 | 4.9s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 5.7s |  |
| 47 | `application_domain` | 4 | 5.0s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 19.5s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 5.2s |  |
| 50 | `array_access` | 18 | 5.0s |  |
| 51 | `array_access_interpreter` | 4 | 5.2s |  |
| 52 | `array_access_no_pubns` | 2 | 5.1s |  |
| 53 | `array_concat` | 41 | 5.0s |  |
| 54 | `array_constr` | 10 | 4.9s |  |
| 55 | `array_delete` | 44 | 5.1s |  |
| 56 | `array_enumeration` | 10 | 5.2s |  |
| 57 | `array_enumeration_elements` | 11 | 5.0s |  |
| 58 | `array_every` | 8 | 4.9s |  |
| 59 | `array_filter` | 6 | 5.3s |  |
| 60 | `array_foreach` | 18 | 4.9s |  |
| 61 | `array_hasownproperty` | 11 | 4.9s |  |
| 62 | `array_holes` | 9 | 5.1s |  |
| 63 | `array_index_max` | 84 | 5.3s |  |
| 64 | `array_indexof` | 25 | 5.0s |  |
| 65 | `array_join` | 26 | 5.2s |  |
| 66 | `array_lastindexof` | 29 | 4.9s |  |
| 67 | `array_length` | 14 | 5.1s |  |
| 68 | `array_literal` | 3 | 5.9s |  |
| 69 | `array_map` | 8 | 4.9s |  |
| 70 | `array_pop` | 52 | 5.0s |  |
| 71 | `array_push` | 24 | 4.9s |  |
| 72 | `array_reborrow_bug` | 6 | 5.0s |  |
| 73 | `array_reverse` | 28 | 5.3s |  |
| 74 | `array_shift` | 51 | 1.5s |  |
| 75 | `array_slice` | 39 | 5.2s |  |
| 76 | `array_some` | 8 | 5.1s |  |
| 77 | `array_sort` | 297 | 5.8s |  |
| 78 | `array_sort_fun_swf12` | 2 | 5.3s |  |
| 79 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 80 | `array_sort_random` | 210 | 5.0s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 5.0s |  |
| 82 | `array_sorton` | 545 | 6.1s |  |
| 83 | `array_sparse_ops` | 41 | 5.1s |  |
| 84 | `array_splice` | 133 | 5.1s |  |
| 85 | `array_splice2` | 428 | 30.5s |  |
| 86 | `array_splice_types` | 48 | 5.6s |  |
| 87 | `array_storage` | 8 | 19.2s |  |
| 88 | `array_tolocalestring` | 9 | 5.1s |  |
| 89 | `array_tostring` | 12 | 5.3s |  |
| 90 | `array_unshift` | 24 | 5.2s |  |
| 91 | `array_valueof` | 9 | 5.3s |  |
| 92 | `array_vector_null_callback` | 10 | 5.2s |  |
| 93 | `astype` | 28 | 5.1s |  |
| 94 | `astypelate` | 24 | 5.0s |  |
| 95 | `astypelate_propagates` | 1 | 5.1s |  |
| 96 | `asymmetric_key_events` | 11 | 5.2s |  |
| 97 | `automation_classes` | 122 | 5.5s |  |
| 98 | `av_classes` | 340 | 5.6s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 4.9s |  |
| 100 | `avm2_catchup_dobj` | 158 | 5.2s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 53.5s |  |
| 102 | `bevel_filter` | 187 | 4.7s |  |
| 103 | `bitand` | 1058 | 10.9s |  |
| 104 | `bitmap_constr` | 17 | 4.8s |  |
| 105 | `bitmap_data` | 1000 | 9.0s |  |
| 106 | `bitmap_filter_abstract` | 6 | 4.8s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 16.6s |  |
| 108 | `bitmap_properties` | 23 | 4.7s |  |
| 109 | `bitmap_subclass` | 7 | 5.7s |  |
| 110 | `bitmap_subclass_properties` | 9 | 5.0s |  |
| 111 | `bitmap_timeline` | 9 | 4.7s |  |
| 112 | `bitmapdata_accuracy` | 1 | 32.4s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 17.2s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.9s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 17.1s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 17.8s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 17.0s |  |
| 118 | `bitmapdata_clone` | 13 | 4.7s |  |
| 119 | `bitmapdata_colortransform` | 0 | 4.9s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 4.6s |  |
| 121 | `bitmapdata_constr` | 22 | 4.7s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 5.1s |  |
| 123 | `bitmapdata_copychannel` | 0 | 18.5s |  |
| 124 | `bitmapdata_copypixels` | 23 | 17.1s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 5.0s |  |
| 126 | `bitmapdata_copypixels_alpha_merge` | 9 | 45.0s |  |
| 127 | `bitmapdata_copypixels_blend` | 1029 | 7.8s |  |
| 128 | `bitmapdata_copypixels_blend_over` | 1 | 7.5s |  |
| 129 | `bitmapdata_copypixels_self` | 612 | 7.3s |  |
| 130 | `bitmapdata_copypixelstobytearray` | 39 | 7.3s |  |
| 131 | `bitmapdata_dispose` | 7 | 7.3s |  |
| 132 | `bitmapdata_draw` | 0 | 27.0s |  |
| 133 | `bitmapdata_draw_alpha_erase` | 8 | 7.4s |  |
| 134 | `bitmapdata_draw_cab_quality` | 0 | 28.1s |  |
| 135 | `bitmapdata_draw_colortransform` | 0 | 26.8s |  |
| 136 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 27.0s |  |
| 137 | `bitmapdata_draw_filters` | 0 | 26.6s |  |
| 138 | `bitmapdata_draw_masks` | 0 | 7.3s |  |
| 139 | `bitmapdata_draw_rotation` | 0 | 7.3s |  |
| 140 | `bitmapdata_draw_self_via_graphic` | 0 | 7.3s |  |
| 141 | `bitmapdata_draw_stage` | 0 | 26.6s |  |
| 142 | `bitmapdata_drawwithquality` | 0 | 7.5s |  |
| 143 | `bitmapdata_embedded` | 9 | 7.4s |  |
| 144 | `bitmapdata_fillrect` | 0 | 7.3s |  |
| 145 | `bitmapdata_filter_sourcerect` | 0 | 26.8s |  |
| 146 | `bitmapdata_floodfill` | 35 | 7.2s |  |
| 147 | `bitmapdata_getpixels` | 39 | 26.7s |  |
| 148 | `bitmapdata_getvector` | 27 | 2.4s |  |
| 149 | `bitmapdata_histogram` | 59 | 2.4s |  |
| 150 | `bitmapdata_hittest` | 112 | 8.0s |  |
| 151 | `bitmapdata_hittest_threshold` | 18 | 7.3s |  |
| 152 | `bitmapdata_opaque` | 0 | 7.3s |  |
| 153 | `bitmapdata_pixeldissolve` | 1037 | 8.0s |  |
| 154 | `bitmapdata_pixeldissolve_image` | 0 | 7.6s |  |
| 155 | `bitmapdata_rectangle_rounding` | 16 | 7.3s |  |
| 156 | `bitmapdata_setpixels` | 286 | 7.4s |  |
| 157 | `bitmapdata_setvector` | 26 | 7.4s |  |
| 158 | `bitmapdata_sync` | 0 | 26.9s |  |
| 159 | `bitmapdata_threshold` | 176 | 8.0s |  |
| 160 | `bitmapdata_zero_size` | 8 | 7.3s |  |
| 161 | `bitnot` | 46 | 7.3s |  |
| 162 | `bitor` | 1058 | 19.6s |  |
| 163 | `bitxor` | 1058 | 19.7s |  |
| 164 | `blend_mode_null` | 1 | 7.4s |  |
| 165 | `blend_multiply_alpha` | 0 | 7.4s |  |
| 166 | `blend_scroll` | 0 | 7.4s |  |
| 167 | `blend_shader_luma_lighten` | 3 | 7.5s |  |
| 168 | `blur_filter` | 43 | 7.4s |  |
| 169 | `boolean_constr` | 32 | 7.4s |  |
| 170 | `boolean_negation` | 30 | 7.3s |  |
| 171 | `boolean_tostring` | 8 | 7.2s |  |
| 172 | `broadcast_event` | 7 | 7.3s |  |
| 173 | `button_bounds` | 1 | 7.3s |  |
| 174 | `button_hittest` | 2 | 26.7s |  |
| 175 | `button_nested_frame` | 48 | 27.0s |  |
| 176 | `button_nested_frame_simple` | 27 | 7.6s |  |
| 177 | `bytearray` | 48 | 7.5s |  |
| 178 | `bytearray_bad_symbol_class` | 3 | 7.3s |  |
| 179 | `bytearray_bad_symbol_class_other_movie` | 6 | 7.7s |  |
| 180 | `bytearray_compress` | 31 | 7.3s |  |
| 181 | `bytearray_errors` | 24 | 7.4s |  |
| 182 | `bytearray_method_serialization` | 1 | 7.2s |  |
| 183 | `bytearray_oom` | 3 | 7.3s |  |
| 184 | `bytearray_readobject_amf0` | 50 | 7.2s |  |
| 185 | `bytearray_readobject_amf3` | 53 | 7.3s |  |
| 186 | `bytearray_readutf8bytes_with_bom` | 16 | 7.3s |  |
| 187 | `bytearray_serialization` | 3 | 7.3s |  |
| 188 | `bytearray_string_null` | 19 | 7.5s |  |
| 189 | `bytearray_tostring` | 15 | 7.2s |  |
| 190 | `bytearray_utf16` | 8 | 7.2s |  |
| 191 | `bytearray_writeobject` | 24 | 7.0s |  |
| 192 | `callee_in_initializer` | 6 | 7.2s |  |
| 193 | `callproplex_class` | 1 | 7.2s |  |
| 194 | `capabilities_resolution` | 8 | 27.9s |  |
| 195 | `catch_class` | 6 | 7.3s |  |
| 196 | `catch_scope_slot` | 7 | 7.3s |  |
| 197 | `checkfilter` | 4 | 2.4s |  |
| 198 | `class_call` | 32 | 7.4s |  |
| 199 | `class_cast_call` | 14 | 7.3s |  |
| 200 | `class_enumeration` | 4 | 7.3s |  |
| 201 | `class_has_own_property` | 2 | 7.2s |  |
| 202 | `class_init_interpreter_mode` | 1 | 7.2s |  |
| 203 | `class_is` | 32 | 7.3s |  |
| 204 | `class_methods` | 5 | 7.2s |  |
| 205 | `class_object_properties` | 10 | 7.4s |  |
| 206 | `class_singleton` | 18 | 7.3s |  |
| 207 | `class_supercalls_errors` | 35 | 7.5s |  |
| 208 | `class_supercalls_mismatched` | 26 | 7.3s |  |
| 209 | `class_superclass_wrong_order` | 1 | 7.2s |  |
| 210 | `class_to_locale_string` | 2 | 7.3s |  |
| 211 | `class_to_string` | 2 | 7.1s |  |
| 212 | `class_value_of` | 2 | 7.2s |  |
| 213 | `click_block` | 5 | 26.6s |  |
| 214 | `click_invisible` | 3 | 7.4s |  |
| 215 | `closures` | 12 | 7.2s |  |
| 216 | `coerce_return_type` | 40 | 7.4s |  |
| 217 | `coerce_return_type_fail` | 2 | 7.2s |  |
| 218 | `coerce_return_void` | 3 | 7.1s |  |
| 219 | `coerce_string` | 86 | 7.3s |  |
| 220 | `coerce_string_precision` | 28 | 7.2s |  |
| 221 | `coerce_to_primitive_side_effects` | 29 | 7.3s |  |
| 222 | `color_matrix_filter` | 19 | 7.3s |  |
| 223 | `construct_errors_swf10` | 8 | 7.3s |  |
| 224 | `construct_frame_list` | 22 | 26.4s |  |
| 225 | `construct_interface` | 3 | 7.2s |  |
| 226 | `constructor_call` | 3 | 7.2s |  |
| 227 | `constructors_vs_timeline` | 5 | 26.2s |  |
| 228 | `constructprop_dynamic_primitive` | 7 | 7.3s |  |
| 229 | `constructprop_method` | 2 | 7.2s |  |
| 230 | `constructsuper_null` | 2 | 2.3s |  |
| 231 | `content_element_basic` | 50 | 7.5s |  |
| 232 | `context3d_creation` | 9 | 7.3s |  |
| 233 | `control_flow_bool` | 4 | 7.2s |  |
| 234 | `control_flow_stricteq` | 8 | 7.2s |  |
| 235 | `convert_boolean` | 30 | 7.2s |  |
| 236 | `convert_integer` | 90 | 7.3s |  |
| 237 | `convert_number` | 56 | 7.3s |  |
| 238 | `convert_uinteger` | 90 | 7.4s |  |
| 239 | `convolution_filter` | 89 | 7.3s |  |
| 240 | `core_exceptions` | 47 | 8.1s |  |
| 241 | `cpool_index_invalid_bytecode_1` | 6 | 7.3s |  |
| 242 | `cpool_index_invalid_bytecode_2` | 3 | 7.2s |  |
| 243 | `cpool_index_invalid_bytecode_3` | 1 | 7.2s |  |
| 244 | `cross_api_version_call_newer` | 12 | 7.8s |  |
| 245 | `cross_api_version_call_older` | 12 | 7.4s |  |
| 246 | `cryptscore` | 11 | 7.3s |  |
| 247 | `currency_parse_result` | 7 | 7.2s |  |
| 248 | `date` | 30 | 7.6s |  |
| 249 | `date_parse` | 36 | 7.2s |  |
| 250 | `declocal` | 46 | 7.1s |  |
| 251 | `declocal_i` | 46 | 7.1s |  |
| 252 | `decode_uri` | 71 | 7.4s |  |
| 253 | `decrement` | 46 | 7.1s |  |
| 254 | `decrement_i` | 46 | 2.2s |  |
| 255 | `default_values` | 7 | 7.1s |  |
| 256 | `delayed_symbolclass` | 28 | 26.9s |  |
| 257 | `describe_type_basic` | 152 | 7.2s |  |
| 258 | `describe_type_json` | 301 | 7.2s |  |
| 259 | `describe_type_metadata` | 125 | 7.2s |  |
| 260 | `describe_type_native` | 23 | 7.1s |  |
| 261 | `dictionary_access` | 62 | 7.3s |  |
| 262 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 263 | `dictionary_delete` | 101 | 7.4s |  |
| 264 | `dictionary_foreach` | 42 | 7.2s |  |
| 265 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 266 | `dictionary_in` | 62 | 7.3s |  |
| 267 | `dictionary_iter_modify` | 8 | 7.0s |  |
| 268 | `dictionary_namespaces` | 36 | 7.2s |  |
| 269 | `displacement_map_filter` | 61 | 7.2s |  |
| 270 | `displayobject_alpha` | 277 | 7.0s |  |
| 271 | `displayobject_blendmode` | 0 | 26.6s |  |
| 272 | `displayobject_colortransform_nested` | 0 | 27.1s |  |
| 273 | `displayobject_early_init` | 54 | 8.6s |  |
| 274 | `displayobject_filters` | 17 | 7.4s |  |
| 275 | `displayobject_from_enterframe` | 1 | 26.8s |  |
| 276 | `displayobject_getbounds_shape` | 0 | 26.6s |  |
| 277 | `displayobject_getrect` | 16 | 7.2s |  |
| 278 | `displayobject_height` | 6052 | 26.9s |  |
| 279 | `displayobject_hittestobject` | 32 | 7.0s |  |
| 280 | `displayobject_hittestpoint` | 49 | 7.3s |  |
| 281 | `displayobject_hittestpoint_boundary` | 65 | 26.8s |  |
| 282 | `displayobject_hittestpoint_root` | 13 | 7.2s |  |
| 283 | `displayobject_invalid_floats` | 60 | 7.0s |  |
| 284 | `displayobject_invalid_props` | 3 | 7.0s |  |
| 285 | `displayobject_mask` | 3 | 7.1s |  |
| 286 | `displayobject_mask_self_referential` | 0 | 6.9s |  |
| 287 | `displayobject_metaData` | 3 | 6.9s |  |
| 288 | `displayobject_name` | 22 | 26.5s |  |
| 289 | `displayobject_name_from_timeline` | 24 | 7.2s |  |
| 290 | `displayobject_opaque_background` | 6 | 7.0s |  |
| 291 | `displayobject_parent` | 12 | 26.9s |  |
| 292 | `displayobject_root` | 24 | 7.4s |  |
| 293 | `displayobject_rotation` | 1284 | 7.6s |  |
| 294 | `displayobject_scrollrect` | 33 | 8.1s |  |
| 295 | `displayobject_set_matrix_nested` | 0 | 27.8s |  |
| 296 | `displayobject_set_name_loaded` | 3 | 7.8s |  |
| 297 | `displayobject_subclass` | 2 | 7.3s |  |
| 298 | `displayobject_transform` | 89 | 26.9s |  |
| 299 | `displayobject_visible` | 23 | 7.3s |  |
| 300 | `displayobject_width` | 4852 | 27.3s |  |
| 301 | `displayobject_x` | 614 | 7.3s |  |
| 302 | `displayobject_y` | 617 | 7.3s |  |
| 303 | `displayobject_z` | 38 | 27.0s |  |
| 304 | `displayobjectcontainer_addchild` | 32 | 7.4s |  |
| 305 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.3s |  |
| 306 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.5s |  |
| 307 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.5s |  |
| 308 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.5s |  |
| 309 | `displayobjectcontainer_addchildat` | 42 | 7.3s |  |
| 310 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.5s |  |
| 311 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.4s |  |
| 312 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.4s |  |
| 313 | `displayobjectcontainer_contains` | 66 | 27.1s |  |
| 314 | `displayobjectcontainer_getchildat` | 4 | 7.4s |  |
| 315 | `displayobjectcontainer_getchildbyname` | 9 | 7.3s |  |
| 316 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.2s |  |
| 317 | `displayobjectcontainer_getchildindex` | 28 | 7.2s |  |
| 318 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 26.4s |  |
| 319 | `displayobjectcontainer_removechild` | 10 | 7.2s |  |
| 320 | `displayobjectcontainer_removechild_errors` | 4 | 7.3s |  |
| 321 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.3s |  |
| 322 | `displayobjectcontainer_removechildat` | 18 | 7.2s |  |
| 323 | `displayobjectcontainer_removechildren` | 51 | 7.6s |  |
| 324 | `displayobjectcontainer_setchildindex` | 42 | 7.3s |  |
| 325 | `displayobjectcontainer_stopallmovieclips` | 2 | 27.2s |  |
| 326 | `displayobjectcontainer_swapchildren` | 42 | 7.4s |  |
| 327 | `displayobjectcontainer_swapchildrenat` | 42 | 7.3s |  |
| 328 | `displayobjectcontainer_timelineinstance` | 48 | 27.1s |  |
| 329 | `divide` | 1058 | 19.7s |  |
| 330 | `doabc_and_symbolclass_script_init_goto` | 7 | 26.9s |  |
| 331 | `doabc_and_symbolclass_script_init_normal` | 6 | 7.2s |  |
| 332 | `doabc_is_eager` | 1 | 26.4s |  |
| 333 | `documentclass` | 9 | 7.6s |  |
| 334 | `domain_memory` | 133 | 28.3s |  |
| 335 | `drag_drop` | 10 | 7.7s |  |
| 336 | `drop_shadow_filter` | 172 | 7.7s |  |
| 337 | `duplicate_defs` | 1 | 7.3s |  |
| 338 | `eager_init` | 1 | 7.5s |  |
| 339 | `east_asian_justifier_clone` | 8 | 7.5s |  |
| 340 | `edit_text_linkage` | 7 | 7.7s |  |
| 341 | `edittext_align` | 60 | 7.9s |  |
| 342 | `edittext_always_show_selection` | 0 | 27.4s |  |
| 343 | `edittext_antialiastype` | 296 | 7.8s |  |
| 344 | `edittext_at_point_methods_basic` | 16 | 8.9s |  |
| 345 | `edittext_autosize` | 39 | 7.9s |  |
| 346 | `edittext_autosize_align` | 0 | 27.1s |  |
| 347 | `edittext_autosize_height_dynamic` | 60 | 27.1s |  |
| 348 | `edittext_autosize_height_input` | 60 | 7.6s |  |
| 349 | `edittext_autosize_lazy_bounds_events` | 65 | 7.9s |  |
| 350 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.5s |  |
| 351 | `edittext_autosize_lazy_bounds_props` | 490 | 8.9s |  |
| 352 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.9s |  |
| 353 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.7s |  |
| 354 | `edittext_bottom_scroll_v_basic` | 210 | 7.6s |  |
| 355 | `edittext_bounds_scale` | 24 | 26.9s |  |
| 356 | `edittext_bullet` | 30 | 7.6s |  |
| 357 | `edittext_default_format` | 221 | 7.9s |  |
| 358 | `edittext_default_format_empty` | 136 | 7.8s |  |
| 359 | `edittext_empty_text_format` | 7 | 7.5s |  |
| 360 | `edittext_focus_selection` | 5 | 7.5s |  |
| 361 | `edittext_font_size` | 45 | 7.6s |  |
| 362 | `edittext_format_empty_font` | 8 | 7.4s |  |
| 363 | `edittext_get_char_index_at_point` | 4 | 28.6s |  |
| 364 | `edittext_get_line_index_at_point` | 2 | 7.7s |  |
| 365 | `edittext_get_line_index_of_char` | 76 | 8.4s |  |
| 366 | `edittext_getcharboundaries` | 172 | 8.0s |  |
| 367 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.6s |  |
| 368 | `edittext_getcharboundaries_scroll` | 85 | 7.6s |  |
| 369 | `edittext_getlinemetrics` | 146 | 7.9s |  |
| 370 | `edittext_html` | 3101 | 8.0s |  |
| 371 | `edittext_html_condensewhite` | 487 | 7.6s |  |
| 372 | `edittext_html_entity` | 4 | 7.6s |  |
| 373 | `edittext_html_font_size_swf12` | 267 | 26.9s |  |
| 374 | `edittext_html_font_size_swf13` | 273 | 7.0s |  |
| 375 | `edittext_html_roundtrip` | 17 | 26.7s |  |
| 376 | `edittext_ime_focus_lost` | 9 | 26.8s |  |
| 377 | `edittext_input_control` | 12 | 7.5s |  |
| 378 | `edittext_leading` | 9 | 7.7s |  |
| 379 | `edittext_letter_spacing` | 15 | 7.7s |  |
| 380 | `edittext_line_methods` | 294 | 8.9s |  |
| 381 | `edittext_line_metrics` | 11 | 28.1s |  |
| 382 | `edittext_margins` | 25 | 7.4s |  |
| 383 | `edittext_max_scroll_h_basic` | 475 | 7.7s |  |
| 384 | `edittext_max_scroll_v_basic` | 1000 | 7.4s |  |
| 385 | `edittext_mouse_selection` | 363 | 27.9s |  |
| 386 | `edittext_mousedown` | 3 | 7.7s |  |
| 387 | `edittext_mouseenabled` | 26 | 7.4s |  |
| 388 | `edittext_newline_character` | 22 | 7.4s |  |
| 389 | `edittext_newline_stripping` | 64 | 10.3s |  |
| 390 | `edittext_newlines` | 30 | 7.4s |  |
| 391 | `edittext_paragraph_methods` | 257 | 7.3s |  |
| 392 | `edittext_paste_events` | 8 | 7.6s |  |
| 393 | `edittext_paste_maxchars` | 4 | 7.3s |  |
| 394 | `edittext_paste_restrict` | 16 | 7.1s |  |
| 395 | `edittext_restrict` | 191 | 7.3s |  |
| 396 | `edittext_restrict_events` | 22 | 7.3s |  |
| 397 | `edittext_scroll_event` | 37 | 7.6s |  |
| 398 | `edittext_scrollh` | 10 | 7.3s |  |
| 399 | `edittext_selected_text` | 9 | 7.3s |  |
| 400 | `edittext_set_html_same` | 17 | 7.3s |  |
| 401 | `edittext_set_text_vs_html` | 9 | 7.3s |  |
| 402 | `edittext_stylesheet` | 536 | 7.7s |  |
| 403 | `edittext_stylesheet_custom_tag` | 76 | 7.3s |  |
| 404 | `edittext_stylesheet_display` | 272 | 7.4s |  |
| 405 | `edittext_tag_indent` | 49 | 26.8s |  |
| 406 | `edittext_underline` | 40 | 7.5s |  |
| 407 | `edittext_width_height` | 103 | 7.7s |  |
| 408 | `edittext_wordwrap_word` | 150 | 7.4s |  |
| 409 | `edittext_wrap_breaks` | 2375 | 7.9s |  |
| 410 | `element_format_clone` | 44 | 7.5s |  |
| 411 | `element_format_constructor_order` | 64 | 2.6s |  |
| 412 | `element_format_properties` | 235 | 8.4s |  |
| 413 | `empty_bounds` | 1 | 7.3s |  |
| 414 | `encode_uri_surrogate_pair_invalid` | 8 | 7.4s |  |
| 415 | `encode_uri_surrogate_pair_swf11` | 15 | 7.3s |  |
| 416 | `equals` | 512 | 12.2s |  |
| 417 | `error_geterrormessage` | 779 | 7.6s |  |
| 418 | `error_prototype` | 15 | 7.5s |  |
| 419 | `error_stack_trace` | 45 | 7.5s |  |
| 420 | `error_stack_trace_debug_swf17` | 0 | 28.5s |  |
| 421 | `error_stack_trace_debug_swf18` | 0 | 7.4s |  |
| 422 | `error_stack_trace_edge_cases` | 6 | 7.7s |  |
| 423 | `error_stack_trace_release_swf17` | 0 | 2.5s |  |
| 424 | `error_stack_trace_release_swf18` | 0 | 7.4s |  |
| 425 | `error_throwerror` | 103 | 7.9s |  |
| 426 | `error_tostring` | 29 | 7.8s |  |
| 427 | `error_tostring_more` | 86 | 8.0s |  |
| 428 | `es3_inheritance` | 31 | 7.8s |  |
| 429 | `es4_inheritance` | 30 | 7.8s |  |
| 430 | `es4_interfaces` | 30 | 7.8s |  |
| 431 | `es4_method_binding` | 8 | 7.8s |  |
| 432 | `es4_oop_prototypes` | 14 | 7.9s |  |
| 433 | `es4_protected_inheritance` | 6 | 7.7s |  |
| 434 | `escape` | 71 | 7.8s |  |
| 435 | `escape_multi_byte` | 45 | 8.0s |  |
| 436 | `event_bubbles` | 2 | 7.5s |  |
| 437 | `event_cancelable` | 2 | 7.4s |  |
| 438 | `event_clone` | 20 | 7.7s |  |
| 439 | `event_clone_error_redispatch` | 3 | 7.7s |  |
| 440 | `event_clone_on_redispatch` | 10 | 7.8s |  |
| 441 | `event_formattostring` | 31 | 7.6s |  |
| 442 | `event_isdefaultprevented` | 12 | 7.4s |  |
| 443 | `event_target_getter` | 5 | 2.5s |  |
| 444 | `event_target_set` | 9 | 7.4s |  |
| 445 | `event_type` | 1 | 7.4s |  |
| 446 | `event_valueof_tostring` | 18 | 7.4s |  |
| 447 | `eventdispatcher_dispatchevent` | 12 | 7.3s |  |
| 448 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.5s |  |
| 449 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.5s |  |
| 450 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.5s |  |
| 451 | `eventdispatcher_dispatchevent_this` | 5 | 7.5s |  |
| 452 | `eventdispatcher_haseventlistener` | 25 | 7.5s |  |
| 453 | `eventdispatcher_interface_invoke` | 1 | 7.4s |  |
| 454 | `eventdispatcher_tostring` | 10 | 7.4s |  |
| 455 | `eventdispatcher_willtrigger` | 25 | 5.3s |  |
| 456 | `falsiness` | 30 | 5.0s |  |
| 457 | `fast_index_access` | 12 | 5.2s |  |
| 458 | `filefilter_properties` | 4 | 5.4s |  |
| 459 | `filereference_browse_cancel` | 3 | 5.3s |  |
| 460 | `filereference_browse_select` | 9 | 5.1s |  |
| 461 | `filereference_load` | 31 | 5.1s |  |
| 462 | `filereference_save` | 16 | 5.1s |  |
| 463 | `filereference_save_and_browse` | 42 | 5.3s |  |
| 464 | `filereference_save_and_load` | 22 | 5.1s |  |
| 465 | `filereference_uninitialized` | 8 | 5.0s |  |
| 466 | `filereferencelist_browse_cancel` | 6 | 5.2s |  |
| 467 | `filereferencelist_browse_select` | 7 | 5.0s |  |
| 468 | `filter_rewind` | 8 | 19.4s |  |
| 469 | `filters_array_holes` | 25 | 5.1s |  |
| 470 | `finddef` | 3 | 5.1s |  |
| 471 | `findprop_global_prototype` | 6 | 5.2s |  |
| 472 | `flash_media_video_constructor` | 156 | 5.7s |  |
| 473 | `flash_media_video_rotation_probe` | 27 | 5.3s |  |
| 474 | `flash_media_video_setter` | 40 | 5.4s |  |
| 475 | `flash_trace` | 17 | 5.2s |  |
| 476 | `flash_ui_mouse_cursor` | 35 | 5.2s |  |
| 477 | `flash_xml` | 29 | 5.1s |  |
| 478 | `flash_xml_cloneNode` | 22 | 5.1s |  |
| 479 | `flash_xml_namespace` | 109 | 5.0s |  |
| 480 | `flash_xml_removeNode` | 60 | 5.2s |  |
| 481 | `focus_events_code` | 161 | 20.0s |  |
| 482 | `focus_events_key_basic` | 132 | 19.6s |  |
| 483 | `focus_events_key_navigation` | 53 | 19.5s |  |
| 484 | `focus_events_key_same_object` | 26 | 5.3s |  |
| 485 | `focus_events_mixed_key_mouse` | 100 | 19.3s |  |
| 486 | `focus_events_mouse_basic` | 260 | 19.8s |  |
| 487 | `focus_events_mouse_focusable` | 112 | 19.4s |  |
| 488 | `focus_events_mouse_same_object` | 40 | 5.1s |  |
| 489 | `focus_remove` | 20 | 19.3s |  |
| 490 | `focus_root_movie` | 4 | 19.5s |  |
| 491 | `focus_stage` | 1 | 5.0s |  |
| 492 | `focusrect` | 18 | 5.8s |  |
| 493 | `focusrect_focuslost` | 9 | 5.6s |  |
| 494 | `focusrect_property` | 110 | 1.5s |  |
| 495 | `font_description_clone` | 14 | 5.2s |  |
| 496 | `font_embedded` | 24 | 26.8s |  |
| 497 | `font_enumeratefonts` | 41 | 7.9s |  |
| 498 | `font_enumeratefonts_filter` | 4 | 26.9s |  |
| 499 | `font_enumeratefonts_order` | 9 | 8.7s |  |
| 500 | `font_hasglyphs` | 40 | 7.8s |  |
| 501 | `font_registerfont` | 129 | 8.3s |  |
| 502 | `framelabel_constr` | 5 | 7.5s |  |
| 503 | `function_call` | 12 | 2.4s |  |
| 504 | `function_call_arguments` | 46 | 7.4s |  |
| 505 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 506 | `function_call_coercion` | 108 | 7.7s |  |
| 507 | `function_call_default` | 6 | 7.2s |  |
| 508 | `function_call_rest` | 22 | 7.2s |  |
| 509 | `function_call_types` | 3 | 7.2s |  |
| 510 | `function_call_via_apply` | 11 | 7.2s |  |
| 511 | `function_call_via_call` | 3 | 7.2s |  |
| 512 | `function_display_anonymous` | 7 | 2.4s |  |
| 513 | `function_length` | 6 | 7.2s |  |
| 514 | `function_object` | 2 | 7.2s |  |
| 515 | `function_proto` | 5 | 7.2s |  |
| 516 | `function_proto_created` | 61 | 7.3s |  |
| 517 | `function_to_locale_string` | 4 | 7.2s |  |
| 518 | `function_to_string` | 4 | 7.1s |  |
| 519 | `function_type` | 6 | 7.2s |  |
| 520 | `function_unbound_this` | 51 | 7.3s |  |
| 521 | `function_value_of` | 4 | 7.2s |  |
| 522 | `game_input` | 4 | 7.2s |  |
| 523 | `generate_random_bytes` | 3 | 7.2s |  |
| 524 | `geom_transform` | 74 | 26.9s |  |
| 525 | `get_definition_by_name` | 11 | 7.3s |  |
| 526 | `get_qualified_class_name` | 20 | 7.3s |  |
| 527 | `get_qualified_super_class_name` | 18 | 7.3s |  |
| 528 | `get_slot_edge_cases` | 1 | 7.2s |  |
| 529 | `get_timer` | 2 | 2.3s |  |
| 530 | `getglobalslot` | 1 | 7.2s |  |
| 531 | `getouterscope` | 8 | 7.2s |  |
| 532 | `getouterscope_two_classobjects` | 13 | 7.2s |  |
| 533 | `getter_different_namespace_setter` | 2 | 7.0s |  |
| 534 | `glow_filter` | 127 | 7.4s |  |
| 535 | `goto_button_nested_framescript` | 28 | 26.7s |  |
| 536 | `goto_in_constructframe` | 12 | 27.1s |  |
| 537 | `goto_in_scene_last_frame` | 2 | 27.0s |  |
| 538 | `goto_methods` | 56 | 7.7s |  |
| 539 | `goto_methods_swfver10` | 8 | 7.5s |  |
| 540 | `goto_nested_construct_sibling` | 18 | 8.0s |  |
| 541 | `goto_nested_framescript` | 9 | 7.8s |  |
| 542 | `goto_on_orphan` | 15 | 27.8s |  |
| 543 | `gradient_bevel_filter` | 206 | 7.7s |  |
| 544 | `gradient_glow_filter` | 206 | 7.5s |  |
| 545 | `graphic_linkage` | 9 | 7.8s |  |
| 546 | `graphics_bad_direct_commands` | 5 | 8.4s |  |
| 547 | `graphics_bitmap_fill` | 0 | 30.6s |  |
| 548 | `graphics_bitmaps` | 0 | 8.2s |  |
| 549 | `graphics_direct_commands` | 0 | 8.0s |  |
| 550 | `graphics_draw_triangles` | 98 | 30.2s |  |
| 551 | `graphics_gradients` | 0 | 7.8s |  |
| 552 | `graphics_gradients_nulls` | 0 | 7.7s |  |
| 553 | `graphics_path` | 56 | 7.7s |  |
| 554 | `graphics_round_rects` | 0 | 7.7s |  |
| 555 | `graphics_simple_shapes` | 0 | 7.7s |  |
| 556 | `greaterequals` | 512 | 11.9s |  |
| 557 | `greaterthan` | 512 | 11.9s |  |
| 558 | `has_own_property` | 102 | 8.3s |  |
| 559 | `hasownproperty_namespaces` | 2 | 7.5s |  |
| 560 | `hello_world` | 1 | 7.6s |  |
| 561 | `hittest_morph` | 30 | 7.8s |  |
| 562 | `id3_info` | 8 | 28.6s |  |
| 563 | `if_eq` | 10 | 8.0s |  |
| 564 | `if_gt` | 1 | 7.9s |  |
| 565 | `if_gte` | 10 | 2.7s |  |
| 566 | `if_lt` | 1 | 0.7s |  |
| 567 | `if_lte` | 10 | 7.7s |  |
| 568 | `if_ne` | 7 | 2.7s |  |
| 569 | `if_stricteq` | 6 | 7.9s |  |
| 570 | `if_strictne` | 11 | 7.9s |  |
| 571 | `ime_linux_dead_keys` | 10 | 7.9s |  |
| 572 | `in` | 102 | 8.3s |  |
| 573 | `inclocal` | 46 | 7.9s |  |
| 574 | `inclocal_i` | 46 | 7.8s |  |
| 575 | `increment` | 46 | 7.7s |  |
| 576 | `increment_i` | 46 | 5.0s |  |
| 577 | `indexing_delete` | 75 | 5.0s |  |
| 578 | `indexof_xml` | 10 | 4.9s |  |
| 579 | `init_callee_cached` | 24 | 4.9s |  |
| 580 | `instanceof` | 58 | 5.4s |  |
| 581 | `instantiate_root_character` | 4 | 5.3s |  |
| 582 | `instantiation_on_enter_frame` | 7 | 18.9s |  |
| 583 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.0s |  |
| 584 | `int_constr` | 92 | 5.2s |  |
| 585 | `int_edge_cases` | 19 | 18.4s |  |
| 586 | `int_instanceof` | 3 | 5.0s |  |
| 587 | `int_tofixed` | 1215 | 5.0s |  |
| 588 | `int_toprecision` | 1125 | 5.0s |  |
| 589 | `int_tostring` | 3375 | 5.5s |  |
| 590 | `interactiveobject_enabled` | 25 | 4.9s |  |
| 591 | `interface_namespaces` | 78 | 5.3s |  |
| 592 | `invalid_utf8` | 12 | 5.0s |  |
| 593 | `is_finite` | 46 | 5.3s |  |
| 594 | `is_nan` | 46 | 5.5s |  |
| 595 | `is_prototype_of` | 12 | 5.7s |  |
| 596 | `issue_10221` | 2 | 5.2s |  |
| 597 | `issue_13780` | 12 | 5.2s |  |
| 598 | `issue_14901` | 1 | 4.8s |  |
| 599 | `issue_17675_edittext_paste_maxchars` | 1 | 5.0s |  |
| 600 | `issue_5292` | 5 | 5.3s |  |
| 601 | `issue_8630` | 2 | 5.2s |  |
| 602 | `issue_8630_placeremoveplace` | 15 | 5.1s |  |
| 603 | `issue_8630_placeremoveplace_scriptremove` | 16 | 5.1s |  |
| 604 | `issue_8630_scriptremove` | 11 | 5.4s |  |
| 605 | `istype` | 24 | 1.8s |  |
| 606 | `istypelate` | 58 | 5.3s |  |
| 607 | `istypelate_coerce` | 198 | 5.6s |  |
| 608 | `jpeg_loader_context` | 6 | 5.1s |  |
| 609 | `json_errors` | 9 | 19.1s |  |
| 610 | `json_parse` | 21 | 5.5s |  |
| 611 | `json_parse_errors` | 84 | 5.6s |  |
| 612 | `json_stringify` | 12 | 5.6s |  |
| 613 | `json_stringify_function` | 12 | 5.5s |  |
| 614 | `json_stringify_order` | 1 | 5.5s |  |
| 615 | `json_version_gated` | 1 | 5.4s |  |
| 616 | `key_input_80percent` | 1812 | 47.5s |  |
| 617 | `key_input_location` | 126 | 7.9s |  |
| 618 | `key_input_numpad` | 384 | 7.7s |  |
| 619 | `large_preload_from_bytes` | 51 | 31.8s |  |
| 620 | `large_preload_from_url` | 27 | 9.8s |  |
| 621 | `large_preload_image_from_bytes` | 25 | 8.1s |  |
| 622 | `lazyinit` | 17 | 7.7s |  |
| 623 | `lessequals` | 512 | 11.9s |  |
| 624 | `lessthan` | 512 | 11.8s |  |
| 625 | `loader_bitmap_transparency` | 14 | 7.8s |  |
| 626 | `loader_bytes_unknown_content` | 14 | 7.7s |  |
| 627 | `loader_child_getdefinition` | 5 | 7.9s |  |
| 628 | `loader_duplicate_class` | 48 | 9.6s |  |
| 629 | `loader_duplicate_coerce` | 3 | 7.8s |  |
| 630 | `loader_duplicate_coerce_new_domain` | 4 | 7.8s |  |
| 631 | `loader_error_in_root_ctor` | 4 | 7.9s |  |
| 632 | `loader_events` | 92 | 8.2s |  |
| 633 | `loader_image` | 8 | 7.8s |  |
| 634 | `loader_jpegxr` | 2 | 27.9s |  |
| 635 | `loader_jpegxr_alpha` | 1 | 27.8s |  |
| 636 | `loader_loadbytes_events` | 30 | 7.9s |  |
| 637 | `loader_loadbytes_invalid_png` | 4 | 7.5s |  |
| 638 | `loader_loadbytes_url` | 12 | 7.7s |  |
| 639 | `loader_loaderurl` | 6 | 7.9s |  |
| 640 | `loader_method` | 85 | 7.5s |  |
| 641 | `loader_noninteractive_try_click_root` | 5 | 27.4s |  |
| 642 | `loader_reuse` | 38 | 7.8s |  |
| 643 | `loader_try_click_root` | 16 | 7.5s |  |
| 644 | `loader_unknown_content` | 24 | 7.6s |  |
| 645 | `loader_visibility_interactive` | 1 | 7.5s |  |
| 646 | `loaderinfo_events` | 7 | 7.4s |  |
| 647 | `loaderinfo_loadurl` | 12 | 7.5s |  |
| 648 | `loaderinfo_more` | 6 | 7.5s |  |
| 649 | `loaderinfo_properties` | 18 | 27.3s |  |
| 650 | `loaderinfo_properties_not_loaded` | 23 | 7.7s |  |
| 651 | `loaderinfo_quine` | 1005 | 7.4s |  |
| 652 | `loaderinfo_root` | 10 | 7.5s |  |
| 653 | `loaderinfo_root_allows` | 2 | 7.5s |  |
| 654 | `localconnection` | 890 | 9.4s |  |
| 655 | `localconnection_send` | 4 | 44.8s |  |
| 656 | `lshift` | 1058 | 19.6s |  |
| 657 | `mask_reapply` | 1 | 26.4s |  |
| 658 | `math` | 497 | 7.5s |  |
| 659 | `matrix` | 338 | 18.2s |  |
| 660 | `matrix3d` | 57 | 27.1s |  |
| 661 | `matrix3d_append` | 16 | 7.4s |  |
| 662 | `matrix3d_append_prepend_scale` | 86 | 7.3s |  |
| 663 | `matrix3d_append_prepend_translation` | 42 | 7.3s |  |
| 664 | `matrix3d_append_rotation` | 23 | 7.4s |  |
| 665 | `matrix3d_compose` | 34 | 7.5s |  |
| 666 | `matrix3d_constructor_clone` | 15 | 7.3s |  |
| 667 | `matrix3d_copy_column` | 83 | 7.6s |  |
| 668 | `matrix3d_copy_from` | 19 | 7.3s |  |
| 669 | `matrix3d_copy_raw_data_from` | 55 | 2.5s |  |
| 670 | `matrix3d_copy_raw_data_to` | 38 | 7.5s |  |
| 671 | `matrix3d_copy_row` | 83 | 7.1s |  |
| 672 | `matrix3d_copy_to_matrix3d` | 19 | 7.3s |  |
| 673 | `matrix3d_determinant` | 182 | 7.4s |  |
| 674 | `matrix3d_interpolate` | 21 | 7.5s |  |
| 675 | `matrix3d_invert` | 18 | 7.3s |  |
| 676 | `matrix3d_position` | 19 | 7.3s |  |
| 677 | `matrix3d_precision` | 28 | 7.4s |  |
| 678 | `matrix3d_prepend` | 16 | 7.2s |  |
| 679 | `matrix3d_raw_data` | 33 | 7.3s |  |
| 680 | `matrix3d_transform_vector` | 52 | 7.6s |  |
| 681 | `matrix3d_transpose` | 5 | 7.2s |  |
| 682 | `method_association` | 5 | 7.3s |  |
| 683 | `method_without_body` | 3 | 26.4s |  |
| 684 | `missing_external_interface` | 10 | 7.4s |  |
| 685 | `modulo` | 1058 | 19.4s |  |
| 686 | `morph_shape` | 2 | 26.6s |  |
| 687 | `mouse_children` | 192 | 26.8s |  |
| 688 | `mouse_click_events` | 90 | 26.4s |  |
| 689 | `mouse_double_click_events` | 188 | 7.3s |  |
| 690 | `mouse_empty_parent` | 4 | 7.2s |  |
| 691 | `mouse_over_while_dragging` | 3 | 7.4s |  |
| 692 | `mouse_pick_button_mode` | 2 | 7.3s |  |
| 693 | `mouse_pick_dobj_mask` | 4 | 7.3s |  |
| 694 | `mouse_pick_masking` | 7 | 44.4s |  |
| 695 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.2s |  |
| 696 | `mouse_pick_non_interactive_dobj_mask` | 3 | 26.2s |  |
| 697 | `mouse_pick_text` | 8 | 7.3s |  |
| 698 | `mouse_sibling` | 8 | 7.2s |  |
| 699 | `mouse_wheel_events` | 36 | 27.3s |  |
| 700 | `mouseevent_constr` | 66 | 7.4s |  |
| 701 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 702 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 703 | `movieclip_addframescript` | 3 | 26.2s |  |
| 704 | `movieclip_addframescript_error` | 9 | 7.2s |  |
| 705 | `movieclip_child_property` | 16 | 7.3s |  |
| 706 | `movieclip_constr` | 21 | 7.2s |  |
| 707 | `movieclip_currentlabels` | 17 | 26.3s |  |
| 708 | `movieclip_currentlabels_dupes1` | 46 | 26.3s |  |
| 709 | `movieclip_currentlabels_dupes2` | 30 | 7.2s |  |
| 710 | `movieclip_currentlabels_dupes3` | 67 | 7.2s |  |
| 711 | `movieclip_currentscene` | 12 | 26.1s |  |
| 712 | `movieclip_dispatchevent` | 430 | 7.3s |  |
| 713 | `movieclip_dispatchevent_cancel` | 102 | 7.3s |  |
| 714 | `movieclip_dispatchevent_handlerorder` | 251 | 7.2s |  |
| 715 | `movieclip_dispatchevent_selfadd` | 80 | 7.2s |  |
| 716 | `movieclip_dispatchevent_target` | 899 | 7.3s |  |
| 717 | `movieclip_displayevents` | 96 | 26.2s |  |
| 718 | `movieclip_displayevents_clickgoto` | 676 | 26.5s |  |
| 719 | `movieclip_displayevents_clickgoto2` | 2001 | 7.7s |  |
| 720 | `movieclip_displayevents_clickplay` | 575 | 7.4s |  |
| 721 | `movieclip_displayevents_clicksymbol` | 562 | 7.4s |  |
| 722 | `movieclip_displayevents_constructframegoto` | 140 | 7.6s |  |
| 723 | `movieclip_displayevents_constructframeplay` | 50 | 7.5s |  |
| 724 | `movieclip_displayevents_constructframesymbol` | 144 | 7.4s |  |
| 725 | `movieclip_displayevents_dblhandler` | 21 | 7.4s |  |
| 726 | `movieclip_displayevents_enterframegoto` | 149 | 7.5s |  |
| 727 | `movieclip_displayevents_enterframeplay` | 48 | 7.3s |  |
| 728 | `movieclip_displayevents_enterframesymbol` | 149 | 26.4s |  |
| 729 | `movieclip_displayevents_exitframegoto` | 106 | 7.3s |  |
| 730 | `movieclip_displayevents_exitframeplay` | 44 | 7.3s |  |
| 731 | `movieclip_displayevents_exitframesymbol` | 135 | 7.3s |  |
| 732 | `movieclip_displayevents_looping` | 63 | 26.3s |  |
| 733 | `movieclip_displayevents_stopped` | 113 | 7.7s |  |
| 734 | `movieclip_displayevents_swap` | 96 | 2.2s |  |
| 735 | `movieclip_displayevents_timeline` | 128 | 7.5s |  |
| 736 | `movieclip_drawrect` | 54 | 34.3s |  |
| 737 | `movieclip_frameconstruct_skipped` | 9 | 5.6s |  |
| 738 | `movieclip_goto_during_frame_script` | 15 | 20.3s |  |
| 739 | `movieclip_goto_overwrite` | 14 | 20.7s |  |
| 740 | `movieclip_goto_scene_last_frame_int` | 1 | 20.6s |  |
| 741 | `movieclip_goto_scene_last_frame_label` | 1 | 6.0s |  |
| 742 | `movieclip_gotoandplay` | 15 | 20.3s |  |
| 743 | `movieclip_gotoandstop` | 13 | 5.3s |  |
| 744 | `movieclip_gotoandstop_children` | 4 | 5.3s |  |
| 745 | `movieclip_gotoandstop_framescripts1` | 4 | 5.3s |  |
| 746 | `movieclip_gotoandstop_framescripts2` | 4 | 1.6s |  |
| 747 | `movieclip_gotoandstop_framescripts_self` | 7 | 19.9s |  |
| 748 | `movieclip_gotoandstop_queueing` | 12 | 20.1s |  |
| 749 | `movieclip_hittest` | 67 | 5.7s |  |
| 750 | `movieclip_next_frame` | 2 | 5.5s |  |
| 751 | `movieclip_next_scene` | 6 | 19.9s |  |
| 752 | `movieclip_play` | 3 | 5.4s |  |
| 753 | `movieclip_prev_frame` | 3 | 5.2s |  |
| 754 | `movieclip_prev_scene` | 7 | 5.2s |  |
| 755 | `movieclip_properties` | 79 | 20.0s |  |
| 756 | `movieclip_queued_noop_goto_swf10` | 9 | 5.2s |  |
| 757 | `movieclip_queued_noop_goto_swf9` | 7 | 0.4s |  |
| 758 | `movieclip_scenes` | 11 | 5.1s |  |
| 759 | `movieclip_soundtransform` | 831 | 21.7s |  |
| 760 | `movieclip_stop` | 1 | 5.4s |  |
| 761 | `movieclip_super_is_symbol` | 20 | 5.6s |  |
| 762 | `movieclip_symbol_constr` | 8 | 5.4s |  |
| 763 | `movieclip_text_mousedown` | 1 | 5.5s |  |
| 764 | `movieclip_willtrigger` | 5 | 5.4s |  |
| 765 | `multiply` | 1058 | 13.3s |  |
| 766 | `namespace_constr` | 253 | 5.9s |  |
| 767 | `namespace_constr_args` | 1 | 5.6s |  |
| 768 | `namespace_enumeration_order` | 7 | 20.7s |  |
| 769 | `nan_scale` | 9 | 5.4s |  |
| 770 | `native_menu_basic` | 19 | 7.5s |  |
| 771 | `navigateToURL_target_normalize` | 107 | 22.6s |  |
| 772 | `negate` | 30 | 5.7s |  |
| 773 | `negative_volume_panned` | 0 | 5.7s |  |
| 774 | `nested_iteration` | 11 | 5.3s |  |
| 775 | `net_getClassByAlias` | 3 | 5.4s |  |
| 776 | `net_navigateToURL` | 57 | 5.3s |  |
| 777 | `net_stream_play_options` | 6 | 5.6s |  |
| 778 | `netconnection_close` | 55 | 45.2s |  |
| 779 | `netconnection_properties` | 78 | 7.4s |  |
| 780 | `netconnection_send_remote` | 50 | 29.7s |  |
| 781 | `netconnection_serialize_arrays` | 6 | 7.3s |  |
| 782 | `netfilterevent` | 10 | 26.4s |  |
| 783 | `netstream_client` | 10 | 7.4s |  |
| 784 | `netstream_connect` | 7 | 7.3s |  |
| 785 | `netstream_flv_date` | 4 | 7.4s |  |
| 786 | `newactivation_in_script_init` | 3 | 7.3s |  |
| 787 | `newclass_mismatched` | 4 | 7.3s |  |
| 788 | `newclass_twice` | 3 | 7.2s |  |
| 789 | `nonconflicting_declarations` | 0 | 7.2s |  |
| 790 | `null_void_types` | 8 | 7.3s |  |
| 791 | `number_autoconv` | 21 | 7.3s |  |
| 792 | `number_autoconv_amf` | 132 | 7.3s |  |
| 793 | `number_autoconv_array_sort_32bit` | 1 | 7.3s |  |
| 794 | `number_constr` | 58 | 7.5s |  |
| 795 | `number_convert_edge_cases` | 180 | 26.8s |  |
| 796 | `number_toexponential` | 378 | 7.3s |  |
| 797 | `number_toexponential2` | 35 | 7.2s |  |
| 798 | `number_tofixed` | 378 | 7.2s |  |
| 799 | `number_toprecision` | 350 | 7.3s |  |
| 800 | `obfuscated_class_names` | 3 | 7.2s |  |
| 801 | `object_enumeration` | 10 | 7.2s |  |
| 802 | `object_prototype` | 4 | 7.4s |  |
| 803 | `object_to_locale_string` | 2 | 7.2s |  |
| 804 | `object_to_string` | 2 | 7.2s |  |
| 805 | `object_value_of` | 2 | 2.1s |  |
| 806 | `op_coerce` | 54 | 7.4s |  |
| 807 | `op_coerce_x` | 54 | 7.3s |  |
| 808 | `op_escxattr` | 2 | 7.2s |  |
| 809 | `op_escxelem` | 2 | 7.3s |  |
| 810 | `op_lookupswitch` | 4 | 7.3s |  |
| 811 | `optimize_coerce` | 1 | 7.2s |  |
| 812 | `orphan_movie_complex` | 80 | 7.7s |  |
| 813 | `orphan_movie_reorder` | 111 | 26.8s |  |
| 814 | `orphan_removeobject` | 636 | 37.5s |  |
| 815 | `package_namespace` | 7 | 21.9s |  |
| 816 | `param_default_value_has_zero_cpool_index` | 1 | 21.8s |  |
| 817 | `parent_early_access_child` | 16 | 22.0s |  |
| 818 | `parse_float` | 81 | 6.1s |  |
| 819 | `parse_float_swf10` | 81 | 5.7s |  |
| 820 | `parse_int` | 135 | 6.2s |  |
| 821 | `perspective_projection` | 1443 | 22.0s |  |
| 822 | `perspective_projection_basic` | 40 | 5.8s |  |
| 823 | `pixelbender_ceil` | 77 | 5.9s |  |
| 824 | `pixelbender_conditional` | 138 | 6.1s |  |
| 825 | `pixelbender_conversions` | 270 | 6.1s |  |
| 826 | `pixelbender_dithering` | 8 | 25.5s |  |
| 827 | `pixelbender_div` | 36 | 6.0s |  |
| 828 | `pixelbender_effect_BlurredFocus` | 0 | 28.4s |  |
| 829 | `pixelbender_effect_glassDisplace` | 0 | 10.1s |  |
| 830 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 24.7s |  |
| 831 | `pixelbender_effect_smudge` | 0 | 8.4s |  |
| 832 | `pixelbender_effect_tintype` | 0 | 7.7s |  |
| 833 | `pixelbender_effect_twirl` | 0 | 8.8s |  |
| 834 | `pixelbender_eof` | 7 | 5.8s |  |
| 835 | `pixelbender_images` | 0 | 7.5s |  |
| 836 | `pixelbender_input` | 103 | 22.5s |  |
| 837 | `pixelbender_logicalnot` | 20 | 5.8s |  |
| 838 | `pixelbender_malformed_data` | 190 | 22.6s |  |
| 839 | `pixelbender_multiple_out_params` | 1 | 5.8s |  |
| 840 | `pixelbender_no_out_param` | 6 | 5.8s |  |
| 841 | `pixelbender_outputs` | 13 | 6.0s |  |
| 842 | `pixelbender_padding_bytes` | 22 | 5.9s |  |
| 843 | `pixelbender_param_qualifier` | 512 | 6.0s |  |
| 844 | `pixelbender_parameters` | 1563 | 6.2s |  |
| 845 | `pixelbender_parameters_bool` | 240 | 6.0s |  |
| 846 | `pixelbender_parameters_int_vs_bool` | 54 | 5.9s |  |
| 847 | `pixelbender_parse_errors` | 6 | 5.8s |  |
| 848 | `pixelbender_rsqrt` | 24 | 6.1s |  |
| 849 | `pixelbender_select_kinds` | 8 | 6.0s |  |
| 850 | `pixelbender_shaderdata` | 49 | 5.9s |  |
| 851 | `pixelbender_shaderdata_setter` | 99 | 6.1s |  |
| 852 | `pixelbender_sign` | 60 | 6.0s |  |
| 853 | `pixelbender_vector_output` | 11 | 6.1s |  |
| 854 | `place_and_lookup/swf10` | 33 | 5.9s |  |
| 855 | `place_and_lookup/swf9` | 33 | 0.5s |  |
| 856 | `place_multiple` | 17 | 47.0s |  |
| 857 | `place_object_replace` | 9 | 28.2s |  |
| 858 | `place_object_replace_2` | 24 | 28.2s |  |
| 859 | `place_object_same_depth_frame` | 1 | 28.2s |  |
| 860 | `point` | 132 | 8.2s |  |
| 861 | `primitive_edge_cases` | 1 | 7.6s |  |
| 862 | `primitive_keys` | 54 | 7.6s |  |
| 863 | `primitive_toString` | 277 | 7.8s |  |
| 864 | `primitive_valueOf` | 285 | 7.4s |  |
| 865 | `print_job_options` | 3 | 7.5s |  |
| 866 | `property_is_enumerable` | 114 | 8.2s |  |
| 867 | `property_is_enumerable_reset` | 23 | 7.4s |  |
| 868 | `property_priority` | 22 | 7.8s |  |
| 869 | `property_priority_chained` | 4 | 7.3s |  |
| 870 | `property_priority_definition_names_order` | 2 | 7.7s |  |
| 871 | `property_priority_three_level` | 6 | 7.6s |  |
| 872 | `propertyisenumerable_namespaces` | 6 | 7.5s |  |
| 873 | `prototype_set_null` | 7 | 7.4s |  |
| 874 | `proxy_callproperty` | 24 | 7.5s |  |
| 875 | `proxy_deleteproperty` | 64 | 7.6s |  |
| 876 | `proxy_enumeration` | 34 | 7.4s |  |
| 877 | `proxy_getproperty` | 77 | 7.4s |  |
| 878 | `proxy_hasownproperty` | 8 | 7.2s |  |
| 879 | `proxy_hasproperty` | 32 | 7.4s |  |
| 880 | `proxy_not_overridden` | 54 | 7.4s |  |
| 881 | `proxy_serialize` | 9 | 7.3s |  |
| 882 | `proxy_setproperty` | 42 | 7.4s |  |
| 883 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.4s |  |
| 884 | `qname_constr` | 32 | 7.4s |  |
| 885 | `qname_constr_namespace` | 24 | 7.4s |  |
| 886 | `qname_enumeration` | 9 | 7.5s |  |
| 887 | `qname_indexing` | 23 | 7.5s |  |
| 888 | `qname_tostring` | 25 | 7.5s |  |
| 889 | `qname_valueof` | 29 | 7.5s |  |
| 890 | `rectangle` | 1094 | 8.2s |  |
| 891 | `regexp_constr` | 148 | 7.7s |  |
| 892 | `regexp_exec` | 19 | 7.5s |  |
| 893 | `regexp_extended` | 47 | 7.5s |  |
| 894 | `regexp_multiargs` | 1 | 7.4s |  |
| 895 | `regexp_test` | 27 | 7.5s |  |
| 896 | `regexp_toString` | 10 | 7.4s |  |
| 897 | `register_script_refresh` | 35 | 27.7s |  |
| 898 | `remove_child_clear_field` | 88 | 45.0s |  |
| 899 | `remove_dobj` | 3 | 26.5s |  |
| 900 | `resolve_order` | 4 | 7.2s |  |
| 901 | `responder_null_callbacks` | 1 | 26.3s |  |
| 902 | `rng` | 1 | 8.6s |  |
| 903 | `rootless` | 42 | 7.4s |  |
| 904 | `rshift` | 1058 | 19.3s |  |
| 905 | `rtqname_not_namespace` | 12 | 7.4s |  |
| 906 | `sandbox_type_inherited` | 2 | 7.9s |  |
| 907 | `sandbox_type_local_file` | 1 | 7.3s |  |
| 908 | `sandbox_type_local_network` | 1 | 7.1s |  |
| 909 | `scene_constr` | 8 | 7.5s |  |
| 910 | `scope_optimizations` | 4 | 7.2s |  |
| 911 | `scopes_dont_cache/order-1` | 1 | 26.3s |  |
| 912 | `scopes_dont_cache/order-2` | 1 | 0.4s |  |
| 913 | `security_domain_current` | 2 | 7.2s |  |
| 914 | `selection` | 239 | 7.7s |  |
| 915 | `set_local_0` | 31 | 7.3s |  |
| 916 | `set_property_is_enumerable` | 85 | 7.8s |  |
| 917 | `shaderparameter_value` | 4 | 7.2s |  |
| 918 | `shape_drawrect` | 54 | 7.3s |  |
| 919 | `shared_object_no_root` | 3 | 7.2s |  |
| 920 | `simplebutton_added_to_stage` | 45 | 26.6s |  |
| 921 | `simplebutton_childevents` | 86 | 26.8s |  |
| 922 | `simplebutton_childevents_nested` | 54 | 7.6s |  |
| 923 | `simplebutton_childevents_sprite` | 13 | 7.3s |  |
| 924 | `simplebutton_childprops` | 144 | 7.5s |  |
| 925 | `simplebutton_childshuffle` | 23 | 7.2s |  |
| 926 | `simplebutton_constr` | 36 | 7.5s |  |
| 927 | `simplebutton_constr_childevents` | 48 | 7.5s |  |
| 928 | `simplebutton_constr_params` | 42 | 7.4s |  |
| 929 | `simplebutton_mouseenabled` | 26 | 7.3s |  |
| 930 | `simplebutton_multi_children` | 19 | 7.5s |  |
| 931 | `simplebutton_soundtransform` | 887 | 28.9s |  |
| 932 | `simplebutton_structure` | 27 | 7.6s |  |
| 933 | `simplebutton_symbolclass` | 68 | 7.8s |  |
| 934 | `slot_disp_id_shared_numbering` | 1 | 26.8s |  |
| 935 | `slots_force_autoassigned` | 1 | 26.2s |  |
| 936 | `socket_after_disconnect` | 1 | 7.4s |  |
| 937 | `socket_close` | 2 | 7.2s |  |
| 938 | `socket_connect` | 4 | 7.2s |  |
| 939 | `socket_errors` | 56 | 7.7s |  |
| 940 | `socket_read_big` | 48 | 7.3s |  |
| 941 | `socket_read_little` | 48 | 2.3s |  |
| 942 | `socket_read_write_object` | 8 | 7.2s |  |
| 943 | `socket_write_big` | 15 | 7.6s |  |
| 944 | `socket_write_little` | 14 | 7.2s |  |
| 945 | `sound_constructor_with_args` | 6 | 7.4s |  |
| 946 | `sound_embeddedprops` | 26 | 7.4s |  |
| 947 | `sound_play` | 19 | 7.5s |  |
| 948 | `sound_rootless` | 7 | 7.3s |  |
| 949 | `sound_valueof` | 33 | 7.3s |  |
| 950 | `soundchannel_soundtransform` | 835 | 28.2s |  |
| 951 | `soundchannel_soundtransform_exists` | 5 | 26.2s |  |
| 952 | `soundchannel_stop` | 8 | 26.4s |  |
| 953 | `soundmixer_buffertime` | 5 | 7.2s |  |
| 954 | `soundmixer_soundtransform` | 900 | 9.2s |  |
| 955 | `soundmixer_stopall` | 6 | 26.2s |  |
| 956 | `soundtransform` | 442 | 12.8s |  |
| 957 | `space_justifier_clone` | 12 | 7.2s |  |
| 958 | `sprite_with_frames` | 0 | 26.6s |  |
| 959 | `stage3d_agal_cross_product` | 0 | 9.6s |  |
| 960 | `stage3d_agal_upload_errors` | 66 | 9.9s |  |
| 961 | `stage3d_bitmap` | 0 | 31.3s |  |
| 962 | `stage3d_blend` | 81 | 28.8s |  |
| 963 | `stage3d_context3d_string_args` | 158 | 8.3s |  |
| 964 | `stage3d_errors` | 7 | 7.3s |  |
| 965 | `stage3d_errors_atf` | 3 | 8.6s |  |
| 966 | `stage3d_errors_swf_29` | 6 | 7.4s |  |
| 967 | `stage3d_float1_index` | 0 | 28.7s |  |
| 968 | `stage3d_fractal` | 0 | 28.8s |  |
| 969 | `stage3d_ignore_sampler_override` | 0 | 28.8s |  |
| 970 | `stage3d_multistage_triangle` | 3 | 9.8s |  |
| 971 | `stage3d_program_constants_bytearray_be` | 0 | 30.6s |  |
| 972 | `stage3d_program_constants_bytearray_le` | 0 | 49.0s |  |
| 973 | `stage3d_program_constants_invalid_input` | 21 | 29.3s |  |
| 974 | `stage3d_raytrace` | 0 | 52.6s |  |
| 975 | `stage3d_rotating_cube` | 0 | 10.7s |  |
| 976 | `stage3d_sampler` | 0 | 10.1s |  |
| 977 | `stage3d_sampler_partial_upload` | 0 | 9.9s |  |
| 978 | `stage3d_stencil` | 0 | 29.5s |  |
| 979 | `stage3d_texture` | 0 | 15.2s |  |
| 980 | `stage3d_texture_bytearray` | 0 | 11.2s |  |
| 981 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.5s |  |
| 982 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.6s |  |
| 983 | `stage3d_triangle` | 0 | 9.9s |  |
| 984 | `stage3d_triangle_bytes4` | 0 | 9.9s |  |
| 985 | `stage3d_triangle_float1` | 0 | 9.9s |  |
| 986 | `stage3d_triangle_index_upload` | 0 | 9.9s |  |
| 987 | `stage3d_x_y` | 22 | 7.6s |  |
| 988 | `stage_access` | 10 | 7.6s |  |
| 989 | `stage_display_state` | 6 | 7.5s |  |
| 990 | `stage_displayobject_properties` | 24 | 7.4s |  |
| 991 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.5s |  |
| 992 | `stage_framerate_nan` | 7 | 7.7s |  |
| 993 | `stage_framerate_negative` | 6 | 7.5s |  |
| 994 | `stage_framerate_zero` | 6 | 7.5s |  |
| 995 | `stage_invalidate` | 38 | 7.7s |  |
| 996 | `stage_loaderinfo_properties` | 24 | 27.1s |  |
| 997 | `stage_mousechildren` | 2 | 7.4s |  |
| 998 | `stage_mouseenabled` | 15 | 7.4s |  |
| 999 | `stage_overriden_setters` | 31 | 7.7s |  |
| 1000 | `stage_properties` | 30 | 7.5s |  |
| 1001 | `stage_properties2` | 213 | 7.6s |  |
| 1002 | `stage_scale_factor` | 12 | 30.8s |  |
| 1003 | `stage_stage3Ds_vector` | 1 | 7.4s |  |
| 1004 | `static_length` | 24 | 7.6s |  |
| 1005 | `static_text` | 3 | 7.7s |  |
| 1006 | `static_var_with_this_in_ctor` | 2 | 7.5s |  |
| 1007 | `statictext_text` | 8 | 7.6s |  |
| 1008 | `stored_properties` | 11 | 7.5s |  |
| 1009 | `strict_equality` | 34 | 7.5s |  |
| 1010 | `string_call` | 13 | 7.5s |  |
| 1011 | `string_case` | 23 | 7.5s |  |
| 1012 | `string_char_at` | 27 | 7.5s |  |
| 1013 | `string_char_code_at` | 28 | 7.4s |  |
| 1014 | `string_concat_fromcharcode` | 37 | 45.0s |  |
| 1015 | `string_constr` | 25 | 26.6s |  |
| 1016 | `string_indexof_lastindexof` | 87 | 7.5s |  |
| 1017 | `string_length` | 16 | 7.2s |  |
| 1018 | `string_locale_compare` | 39 | 7.6s |  |
| 1019 | `string_match` | 51 | 7.5s |  |
| 1020 | `string_relational_compare` | 4 | 7.3s |  |
| 1021 | `string_replace` | 51 | 7.4s |  |
| 1022 | `string_search` | 41 | 7.4s |  |
| 1023 | `string_slice_substr_substring` | 170 | 8.4s |  |
| 1024 | `string_split` | 29 | 7.3s |  |
| 1025 | `string_substr_negative` | 21 | 7.3s |  |
| 1026 | `string_substr_weird` | 182 | 7.3s |  |
| 1027 | `stylesheet` | 221 | 7.8s |  |
| 1028 | `stylesheet_parse_color` | 69 | 7.3s |  |
| 1029 | `stylesheet_transform` | 307 | 7.6s |  |
| 1030 | `sub_super_same_field` | 12 | 2.4s |  |
| 1031 | `subclass_superclass_linked_symbol` | 4 | 7.8s |  |
| 1032 | `subtract` | 1058 | 19.3s |  |
| 1033 | `super_get_call` | 12 | 7.3s |  |
| 1034 | `supercall_two_classobjects` | 2 | 7.3s |  |
| 1035 | `supercalls_coerce` | 8 | 7.3s |  |
| 1036 | `supercalls_weird` | 2 | 7.2s |  |
| 1037 | `superinterface_call` | 20 | 7.3s |  |
| 1038 | `superinterface_instanceof` | 18 | 7.3s |  |
| 1039 | `swf8` | 1 | 7.2s |  |
| 1040 | `swf_10_queued_goto_scripts_construct` | 52 | 26.8s |  |
| 1041 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 1042 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 1043 | `swf_9_queued_goto_scripts` | 6 | 26.6s |  |
| 1044 | `swf_9_queued_goto_scripts_construct` | 28 | 0.7s |  |
| 1045 | `swf_9_versioning` | 2 | 7.2s |  |
| 1046 | `swf_wrong_frame_count` | 38 | 7.6s |  |
| 1047 | `swf_wrong_frame_count_isplaying` | 22 | 7.3s |  |
| 1048 | `symbol_class_binary_data` | 8 | 7.3s |  |
| 1049 | `symbol_class_conflict` | 4 | 7.4s |  |
| 1050 | `symbol_class_root_not_zero` | 1 | 7.2s |  |
| 1051 | `symbolclass_invalid_utf8` | 2 | 7.3s |  |
| 1052 | `system_exit` | 3 | 7.2s |  |
| 1053 | `system_setclipboard_null` | 1 | 7.2s |  |
| 1054 | `tab_ordering_arrows` | 998 | 45.3s |  |
| 1055 | `tab_ordering_automatic_advanced` | 184 | 7.6s |  |
| 1056 | `tab_ordering_automatic_basic` | 45 | 26.1s |  |
| 1057 | `tab_ordering_children` | 116 | 7.2s |  |
| 1058 | `tab_ordering_custom_basic` | 34 | 7.0s |  |
| 1059 | `tab_ordering_stage_tab_children` | 32 | 7.0s |  |
| 1060 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.9s |  |
| 1061 | `tab_ordering_tabbable` | 47 | 7.1s |  |
| 1062 | `tabstop_properties` | 105 | 26.3s |  |
| 1063 | `text_element_basic` | 34 | 7.1s |  |
| 1064 | `text_engine_fontdescription` | 27 | 7.2s |  |
| 1065 | `text_engine_groupelement` | 64 | 8.0s |  |
| 1066 | `text_run` | 7 | 6.9s |  |
| 1067 | `textblock_createline_errors` | 23 | 7.2s |  |
| 1068 | `textblock_createline_fte` | 9 | 26.4s |  |
| 1069 | `textblock_properties` | 118 | 7.4s |  |
| 1070 | `textbox_click` | 37 | 26.4s |  |
| 1071 | `textfield_event` | 66 | 7.3s |  |
| 1072 | `textfield_focusin_event` | 9 | 7.0s |  |
| 1073 | `textfield_input_dead_keys_windows` | 15 | 7.0s |  |
| 1074 | `textfield_input_events` | 25 | 19.4s |  |
| 1075 | `textfield_unload` | 39 | 26.6s |  |
| 1076 | `textformat` | 1134 | 7.1s |  |
| 1077 | `textformat_display` | 14 | 7.1s |  |
| 1078 | `textformat_font_max_length` | 4 | 7.0s |  |
| 1079 | `textline_inapplicable_properties` | 10 | 7.0s |  |
| 1080 | `textline_name` | 1 | 7.0s |  |
| 1081 | `textline_raw_text_length` | 30 | 7.0s |  |
| 1082 | `textline_splitting_basic` | 76 | 7.1s |  |
| 1083 | `textline_throwerror` | 30 | 7.0s |  |
| 1084 | `textline_validity` | 162 | 7.1s |  |
| 1085 | `throw` | 3 | 7.0s |  |
| 1086 | `timeline_scripts` | 3 | 26.2s |  |
| 1087 | `timer` | 90 | 7.7s |  |
| 1088 | `timer_events` | 3 | 7.2s |  |
| 1089 | `timer_finished` | 11 | 7.2s |  |
| 1090 | `timer_invalid_delay` | 30 | 7.1s |  |
| 1091 | `timer_reset` | 8 | 44.8s |  |
| 1092 | `timer_setdelay` | 5 | 26.5s |  |
| 1093 | `trace` | 12 | 7.4s |  |
| 1094 | `truthiness` | 30 | 7.3s |  |
| 1095 | `try_catch` | 11 | 7.3s |  |
| 1096 | `try_catch_typed` | 12 | 7.4s |  |
| 1097 | `typeof` | 30 | 7.2s |  |
| 1098 | `uint_constr` | 92 | 7.4s |  |
| 1099 | `uint_tofixed` | 1215 | 7.1s |  |
| 1100 | `uint_toprecision` | 1125 | 7.4s |  |
| 1101 | `uint_tostring` | 3375 | 7.5s |  |
| 1102 | `uncaught_error_basic` | 2 | 7.2s |  |
| 1103 | `unchecked_function` | 15 | 7.1s |  |
| 1104 | `unescape` | 28 | 7.2s |  |
| 1105 | `url_loader` | 25 | 7.3s |  |
| 1106 | `url_vars` | 27 | 7.3s |  |
| 1107 | `urlrequest` | 18 | 7.3s |  |
| 1108 | `urlstream_basic` | 5 | 7.2s |  |
| 1109 | `urshift` | 1058 | 19.0s |  |
| 1110 | `utils3d` | 7 | 7.2s |  |
| 1111 | `vector3d` | 397 | 11.7s |  |
| 1112 | `vector3d_near_equals` | 80 | 7.3s |  |
| 1113 | `vector_class` | 36 | 7.6s |  |
| 1114 | `vector_class_call` | 11 | 7.4s |  |
| 1115 | `vector_coercion` | 66 | 8.0s |  |
| 1116 | `vector_concat` | 90 | 7.8s |  |
| 1117 | `vector_constr` | 107 | 7.8s |  |
| 1118 | `vector_enumeration` | 5 | 7.1s |  |
| 1119 | `vector_every` | 92 | 8.1s |  |
| 1120 | `vector_filter` | 95 | 8.2s |  |
| 1121 | `vector_holes` | 24 | 7.3s |  |
| 1122 | `vector_indexof` | 302 | 12.2s |  |
| 1123 | `vector_insertat` | 270 | 8.4s |  |
| 1124 | `vector_int_access` | 4 | 7.2s |  |
| 1125 | `vector_int_delete` | 11 | 7.3s |  |
| 1126 | `vector_join` | 58 | 7.8s |  |
| 1127 | `vector_lastindexof` | 302 | 7.3s |  |
| 1128 | `vector_legacy` | 10 | 7.4s |  |
| 1129 | `vector_map` | 85 | 8.1s |  |
| 1130 | `vector_object_final` | 1 | 7.2s |  |
| 1131 | `vector_object_toString` | 10 | 43.2s |  |
| 1132 | `vector_pushpop` | 255 | 26.5s |  |
| 1133 | `vector_reborrow_bug` | 10 | 6.5s |  |
| 1134 | `vector_removeat` | 172 | 7.4s |  |
| 1135 | `vector_reverse` | 232 | 7.4s |  |
| 1136 | `vector_shiftunshift` | 252 | 6.4s |  |
| 1137 | `vector_slice` | 331 | 7.8s |  |
| 1138 | `vector_sort` | 905 | 13.7s |  |
| 1139 | `vector_splice` | 693 | 9.3s |  |
| 1140 | `vector_splice_fixed_bug_compat` | 4 | 6.5s |  |
| 1141 | `vector_tostring` | 79 | 7.0s |  |
| 1142 | `verification` | 8 | 6.7s |  |
| 1143 | `verify_abnormal_loop` | 1 | 6.5s |  |
| 1144 | `verify_dxns_without_flag` | 3 | 6.8s |  |
| 1145 | `verify_exception_target_two_jumps` | 1 | 6.5s |  |
| 1146 | `verify_exception_targets_edge_case` | 1 | 6.5s |  |
| 1147 | `verify_illegal_opcode` | 1 | 2.0s |  |
| 1148 | `verify_jump_to_middle_of_op` | 1 | 6.5s |  |
| 1149 | `verify_lookup_switch_edge_case` | 1 | 6.5s |  |
| 1150 | `verify_method_info_oob` | 1 | 0.4s |  |
| 1151 | `verify_stack` | 5 | 6.5s |  |
| 1152 | `verify_typecheck` | 4 | 6.5s |  |
| 1153 | `verify_unreachable_exception` | 2 | 6.4s |  |
| 1154 | `versioned_isplaying` | 2 | 6.5s |  |
| 1155 | `virtual_properties` | 16 | 6.6s |  |
| 1156 | `with` | 4 | 6.5s |  |
| 1157 | `wrong_arg_count` | 7 | 6.6s |  |
| 1158 | `xml_abstract_equality` | 36 | 6.7s |  |
| 1159 | `xml_advanced` | 52 | 6.5s |  |
| 1160 | `xml_appendchild` | 10 | 6.5s |  |
| 1161 | `xml_appendchild_swf_v21` | 13 | 6.7s |  |
| 1162 | `xml_as_attribute` | 9 | 6.5s |  |
| 1163 | `xml_attribute` | 35 | 6.6s |  |
| 1164 | `xml_attribute_name` | 40 | 6.5s |  |
| 1165 | `xml_basic` | 33 | 6.5s |  |
| 1166 | `xml_child` | 25 | 6.6s |  |
| 1167 | `xml_childindex` | 7 | 6.5s |  |
| 1168 | `xml_children` | 43 | 7.0s |  |
| 1169 | `xml_class_call` | 9 | 6.5s |  |
| 1170 | `xml_contains` | 197 | 6.6s |  |
| 1171 | `xml_copy` | 20 | 45.2s |  |
| 1172 | `xml_ctor_from_tostring` | 23 | 26.9s |  |
| 1173 | `xml_delete` | 114 | 7.4s |  |
| 1174 | `xml_descendants` | 83 | 7.4s |  |
| 1175 | `xml_duplicate_attribute` | 14 | 7.4s |  |
| 1176 | `xml_elements` | 6 | 7.2s |  |
| 1177 | `xml_equals_namespace_check` | 2 | 7.4s |  |
| 1178 | `xml_explicit_use_namespace` | 5 | 7.5s |  |
| 1179 | `xml_getdescendants_qname` | 21 | 7.5s |  |
| 1180 | `xml_has_property_via_in` | 26 | 7.4s |  |
| 1181 | `xml_hasownproperty` | 6 | 7.3s |  |
| 1182 | `xml_ignore_white` | 6 | 7.5s |  |
| 1183 | `xml_length` | 2 | 7.4s |  |
| 1184 | `xml_list_as_attribute` | 9 | 7.3s |  |
| 1185 | `xml_list_concat` | 20 | 7.5s |  |
| 1186 | `xml_list_ctor_errors` | 34 | 7.5s |  |
| 1187 | `xml_list_delete_clear_parent` | 6 | 7.4s |  |
| 1188 | `xml_list_enumerate` | 4 | 7.3s |  |
| 1189 | `xml_methods_settings` | 3 | 7.3s |  |
| 1190 | `xml_mismatched_tag` | 37 | 7.4s |  |
| 1191 | `xml_namespace` | 39 | 7.3s |  |
| 1192 | `xml_namespace_methods` | 245 | 7.6s |  |
| 1193 | `xml_namespaced_property` | 7 | 7.4s |  |
| 1194 | `xml_no_namespace` | 1 | 7.3s |  |
| 1195 | `xml_nodekind` | 3 | 7.3s |  |
| 1196 | `xml_normalize` | 35 | 7.5s |  |
| 1197 | `xml_notification_bubbling` | 361 | 7.3s |  |
| 1198 | `xml_parent` | 8 | 7.2s |  |
| 1199 | `xml_set_children` | 17 | 7.3s |  |
| 1200 | `xml_set_name` | 34 | 7.3s |  |
| 1201 | `xml_settings` | 6 | 2.3s |  |
| 1202 | `xml_simple_complex_content` | 47 | 7.3s |  |
| 1203 | `xml_socket` | 11 | 7.5s |  |
| 1204 | `xml_text` | 7 | 7.3s |  |
| 1205 | `xml_tostring` | 6 | 7.3s |  |
| 1206 | `xml_tostring_namespace` | 12 | 7.1s |  |
| 1207 | `xml_unescaping` | 23 | 7.3s |  |
| 1208 | `xml_weird_ignores` | 54 | 7.4s |  |
| 1209 | `xml_wildcard` | 11 | 7.3s |  |
| 1210 | `xmldocument` | 254 | 7.4s |  |
| 1211 | `xmlnode` | 3540 | 7.5s |  |
| 1212 | `zero_frame_clip` | 3 | 7.6s |  |

## Ruffle-Matched Tests

**36 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 4.9s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.2s |  |
| 3 | `blend_transform` | 1 | 1 | 7.4s |  |
| 4 | `bounds_mode` | 6 | 6 | 7.7s |  |
| 5 | `coerce_property` | 3 | 3 | 7.3s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.3s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 26.9s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 27.1s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 7.7s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.7s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 7.4s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 7.5s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 28.1s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 7.8s |  |
| 15 | `event_handler_exception` | 4 | 4 | 7.6s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 7.3s |  |
| 17 | `goto_framescript_queued/swf13` | 42 | 42 | 0.7s |  |
| 18 | `graphics_draw_path` | 50 | 50 | 30.6s |  |
| 19 | `groupelement_text` | 2 | 2 | 8.1s |  |
| 20 | `int_toexponential` | 76 | 76 | 5.8s |  |
| 21 | `json_parse_numbers` | 4 | 79 | 5.4s |  |
| 22 | `loader_events_2` | 30 | 30 | 8.1s |  |
| 23 | `matrix3d_recompose_edge_cases` | 8 | 85 | 7.7s |  |
| 24 | `number_convert_errors` | 706 | 706 | 7.5s |  |
| 25 | `simplebutton_childevents_script_order` | 4 | 4 | 7.5s |  |
| 26 | `slot_holes_fail` | 1 | 1 | 7.6s |  |
| 27 | `slot_id_exceeds_trait_count` | 1 | 1 | 44.4s |  |
| 28 | `soundchannel_position` | 74 | 74 | 27.1s |  |
| 29 | `soundchannel_soundcomplete` | 10 | 10 | 7.5s |  |
| 30 | `sprite_dropTarget` | 15 | 15 | 7.3s |  |
| 31 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.9s |  |
| 32 | `textblock_line_changes` | 44 | 44 | 7.7s |  |
| 33 | `textblock_releaselines` | 4 | 4 | 8.6s |  |
| 34 | `uint_toexponential` | 100 | 100 | 7.4s |  |
| 35 | `uncaught_errors_stringified` | 15 | 15 | 7.4s |  |
| 36 | `weird_superinterface_properties` | 1 | 1 | 6.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**8 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 3 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 4 | `number_to_string` | 67.1% | 237 | 353 | 116 |  |
| 5 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 6 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 7 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 8 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**26 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 3 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 4 | `number_to_string` | 67.1% | 237/353 | 353 | 353 |  |
| 5 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 6 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 7 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 8 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 9 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 10 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 11 | `goto_framescript_queued/swf10` | 25.4% | 15/59 | 48 | 59 |  |
| 12 | `textblock_recreateline` | 22.1% | 40/181 | 181 | 180 |  |
| 13 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 14 | `goto_framescript_queued/swf9` | 21.2% | 11/52 | 46 | 52 |  |
| 15 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 16 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 17 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 18 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 19 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 20 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 21 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 22 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 1 | 2 |  |
| 23 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 24 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 25 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 26 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
