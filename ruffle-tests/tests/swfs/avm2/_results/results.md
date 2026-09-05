# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-05 04:40 UTC

**Git SHA**: `7f7a6ba369`

**Run Duration**: 219m 8s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1261 |
| Passing | **1198** (95.0%) |
| Ruffle-matched | 36 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1234** (97.9%) |
| Failing | 27 |
| Total expected lines | 155033 |
| Matching lines | 152158 (98.1%) |
| Mismatched lines | 2875 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 27 | 100.0% |

## Passing Tests

**1198 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 44.4s |  |
| 2 | `accessibility` | 1 | 7.1s |  |
| 3 | `accessibilityimplementation` | 18 | 26.1s |  |
| 4 | `activation_class` | 6 | 7.1s |  |
| 5 | `add` | 1058 | 19.2s |  |
| 6 | `agal_compiler` | 13 | 9.6s |  |
| 7 | `air_datagram_socket` | 1 | 9.2s |  |
| 8 | `air_hidden_lookup` | 2 | 7.1s |  |
| 9 | `air_ifilepromise` | 1 | 7.1s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 7.2s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.7s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.7s |  |
| 13 | `all_classes/display/swf10` | 2569 | 7.2s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.7s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.7s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.7s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.6s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.6s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 7.1s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.6s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.6s |  |
| 22 | `all_classes/errors/swf10` | 140 | 7.1s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.6s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.6s |  |
| 25 | `all_classes/events/swf10` | 1638 | 7.1s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.6s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.6s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.6s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.6s |  |
| 30 | `all_classes/security/swf11` | 3 | 7.1s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.6s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.6s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.6s |  |
| 34 | `all_classes/xml/swf30` | 116 | 7.1s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.6s |  |
| 36 | `amf_array_serialization` | 17 | 28.5s |  |
| 37 | `amf_custom_obj` | 26 | 7.2s |  |
| 38 | `amf_dictionary` | 9 | 7.1s |  |
| 39 | `amf_function` | 46 | 7.1s |  |
| 40 | `amf_invalid_date` | 2 | 7.0s |  |
| 41 | `amf_missing_prop` | 6 | 7.1s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 7.0s |  |
| 43 | `amf_setter_error` | 8 | 7.2s |  |
| 44 | `amf_vector` | 40 | 43.4s |  |
| 45 | `amf_xml` | 6 | 6.8s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 7.2s |  |
| 47 | `application_domain` | 4 | 6.8s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 25.6s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 6.7s |  |
| 50 | `array_access` | 18 | 6.7s |  |
| 51 | `array_access_interpreter` | 4 | 6.7s |  |
| 52 | `array_access_no_pubns` | 2 | 6.7s |  |
| 53 | `array_concat` | 41 | 6.8s |  |
| 54 | `array_constr` | 10 | 6.7s |  |
| 55 | `array_delete` | 44 | 6.8s |  |
| 56 | `array_enumeration` | 10 | 6.8s |  |
| 57 | `array_enumeration_elements` | 11 | 6.7s |  |
| 58 | `array_every` | 8 | 6.7s |  |
| 59 | `array_filter` | 6 | 6.7s |  |
| 60 | `array_foreach` | 18 | 6.7s |  |
| 61 | `array_hasownproperty` | 11 | 6.7s |  |
| 62 | `array_holes` | 9 | 6.7s |  |
| 63 | `array_index_max` | 84 | 6.7s |  |
| 64 | `array_indexof` | 25 | 6.8s |  |
| 65 | `array_join` | 26 | 6.8s |  |
| 66 | `array_lastindexof` | 29 | 6.8s |  |
| 67 | `array_length` | 14 | 6.7s |  |
| 68 | `array_literal` | 3 | 6.7s |  |
| 69 | `array_map` | 8 | 6.5s |  |
| 70 | `array_pop` | 52 | 6.8s |  |
| 71 | `array_push` | 24 | 6.7s |  |
| 72 | `array_reborrow_bug` | 6 | 6.7s |  |
| 73 | `array_reverse` | 28 | 6.7s |  |
| 74 | `array_shift` | 51 | 2.1s |  |
| 75 | `array_slice` | 39 | 6.8s |  |
| 76 | `array_some` | 8 | 6.7s |  |
| 77 | `array_sort` | 297 | 7.1s |  |
| 78 | `array_sort_fun_swf12` | 2 | 6.7s |  |
| 79 | `array_sort_fun_swf13` | 2 | 0.6s |  |
| 80 | `array_sort_random` | 210 | 6.9s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 6.7s |  |
| 82 | `array_sorton` | 545 | 7.4s |  |
| 83 | `array_sparse_ops` | 41 | 6.8s |  |
| 84 | `array_splice` | 133 | 44.7s |  |
| 85 | `array_splice2` | 428 | 26.9s |  |
| 86 | `array_splice_types` | 48 | 7.3s |  |
| 87 | `array_storage` | 8 | 7.2s |  |
| 88 | `array_tolocalestring` | 9 | 7.2s |  |
| 89 | `array_tostring` | 12 | 7.2s |  |
| 90 | `array_unshift` | 24 | 7.1s |  |
| 91 | `array_valueof` | 9 | 7.1s |  |
| 92 | `array_vector_null_callback` | 10 | 7.2s |  |
| 93 | `astype` | 28 | 7.3s |  |
| 94 | `astypelate` | 24 | 7.3s |  |
| 95 | `astypelate_propagates` | 1 | 7.2s |  |
| 96 | `asymmetric_key_events` | 11 | 7.4s |  |
| 97 | `automation_classes` | 122 | 7.7s |  |
| 98 | `av_classes` | 340 | 7.6s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 7.3s |  |
| 100 | `avm2_catchup_dobj` | 158 | 7.8s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 84.6s |  |
| 102 | `bevel_filter` | 187 | 7.3s |  |
| 103 | `bitand` | 1058 | 19.4s |  |
| 104 | `bitmap_constr` | 17 | 7.4s |  |
| 105 | `bitmap_data` | 1000 | 15.4s |  |
| 106 | `bitmap_pixelsnapping` | 2 | 26.5s |  |
| 107 | `bitmap_properties` | 23 | 7.2s |  |
| 108 | `bitmap_subclass` | 7 | 8.7s |  |
| 109 | `bitmap_subclass_properties` | 9 | 7.5s |  |
| 110 | `bitmap_timeline` | 9 | 7.3s |  |
| 111 | `bitmapdata_accuracy` | 1 | 43.0s |  |
| 112 | `bitmapdata_applyfilter_blur` | 0 | 26.5s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.5s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | 0 | 26.5s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.7s |  |
| 116 | `bitmapdata_applyfilter_identity` | 4 | 26.2s |  |
| 117 | `bitmapdata_clone` | 13 | 7.3s |  |
| 118 | `bitmapdata_colortransform` | 0 | 7.4s |  |
| 119 | `bitmapdata_colortransform_oob` | 2 | 7.1s |  |
| 120 | `bitmapdata_constr` | 22 | 7.2s |  |
| 121 | `bitmapdata_constructor_from_timeline` | 1 | 7.5s |  |
| 122 | `bitmapdata_copychannel` | 0 | 28.2s |  |
| 123 | `bitmapdata_copypixels` | 23 | 26.6s |  |
| 124 | `bitmapdata_copypixels_alpha_combine` | 13 | 45.8s |  |
| 125 | `bitmapdata_copypixels_blend_over` | 1 | 7.5s |  |
| 126 | `bitmapdata_copypixelstobytearray` | 39 | 7.4s |  |
| 127 | `bitmapdata_dispose` | 7 | 7.4s |  |
| 128 | `bitmapdata_draw` | 0 | 27.5s |  |
| 129 | `bitmapdata_draw_alpha_erase` | 8 | 7.4s |  |
| 130 | `bitmapdata_draw_colortransform` | 0 | 27.6s |  |
| 131 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 28.1s |  |
| 132 | `bitmapdata_draw_filters` | 0 | 27.6s |  |
| 133 | `bitmapdata_draw_masks` | 0 | 7.4s |  |
| 134 | `bitmapdata_draw_rotation` | 0 | 7.5s |  |
| 135 | `bitmapdata_draw_self_via_graphic` | 0 | 7.5s |  |
| 136 | `bitmapdata_draw_stage` | 0 | 27.2s |  |
| 137 | `bitmapdata_drawwithquality` | 0 | 7.7s |  |
| 138 | `bitmapdata_embedded` | 9 | 7.5s |  |
| 139 | `bitmapdata_fillrect` | 0 | 7.5s |  |
| 140 | `bitmapdata_filter_sourcerect` | 0 | 26.9s |  |
| 141 | `bitmapdata_floodfill` | 35 | 7.3s |  |
| 142 | `bitmapdata_getpixels` | 39 | 26.6s |  |
| 143 | `bitmapdata_getvector` | 27 | 2.5s |  |
| 144 | `bitmapdata_histogram` | 59 | 2.5s |  |
| 145 | `bitmapdata_hittest` | 112 | 8.0s |  |
| 146 | `bitmapdata_hittest_threshold` | 18 | 7.3s |  |
| 147 | `bitmapdata_opaque` | 0 | 7.3s |  |
| 148 | `bitmapdata_pixeldissolve` | 1037 | 7.9s |  |
| 149 | `bitmapdata_pixeldissolve_image` | 0 | 7.6s |  |
| 150 | `bitmapdata_rectangle_rounding` | 16 | 7.4s |  |
| 151 | `bitmapdata_setpixels` | 286 | 7.5s |  |
| 152 | `bitmapdata_setvector` | 26 | 7.5s |  |
| 153 | `bitmapdata_sync` | 0 | 26.9s |  |
| 154 | `bitmapdata_threshold` | 176 | 8.0s |  |
| 155 | `bitmapdata_zero_size` | 8 | 7.2s |  |
| 156 | `bitnot` | 46 | 7.3s |  |
| 157 | `bitor` | 1058 | 19.5s |  |
| 158 | `bitxor` | 1058 | 19.4s |  |
| 159 | `blend_mode_null` | 1 | 7.3s |  |
| 160 | `blend_multiply_alpha` | 0 | 7.3s |  |
| 161 | `blend_scroll` | 0 | 7.3s |  |
| 162 | `blend_shader_luma_lighten` | 3 | 7.5s |  |
| 163 | `blur_filter` | 43 | 7.4s |  |
| 164 | `boolean_constr` | 32 | 22.1s |  |
| 165 | `boolean_negation` | 30 | 5.8s |  |
| 166 | `boolean_tostring` | 8 | 5.8s |  |
| 167 | `broadcast_event` | 7 | 5.8s |  |
| 168 | `button_bounds` | 1 | 5.9s |  |
| 169 | `button_hittest` | 2 | 22.0s |  |
| 170 | `button_nested_frame` | 48 | 22.4s |  |
| 171 | `button_nested_frame_simple` | 27 | 6.0s |  |
| 172 | `bytearray` | 48 | 6.1s |  |
| 173 | `bytearray_compress` | 31 | 5.9s |  |
| 174 | `bytearray_errors` | 24 | 5.9s |  |
| 175 | `bytearray_method_serialization` | 1 | 5.8s |  |
| 176 | `bytearray_oom` | 3 | 6.0s |  |
| 177 | `bytearray_readobject_amf0` | 50 | 5.8s |  |
| 178 | `bytearray_readobject_amf3` | 53 | 5.8s |  |
| 179 | `bytearray_readutf8bytes_with_bom` | 16 | 5.9s |  |
| 180 | `bytearray_serialization` | 3 | 5.8s |  |
| 181 | `bytearray_string_null` | 19 | 6.2s |  |
| 182 | `bytearray_tostring` | 15 | 5.9s |  |
| 183 | `bytearray_utf16` | 8 | 5.8s |  |
| 184 | `bytearray_writeobject` | 24 | 5.6s |  |
| 185 | `callee_in_initializer` | 6 | 5.8s |  |
| 186 | `callproplex_class` | 1 | 5.8s |  |
| 187 | `capabilities_resolution` | 8 | 23.1s |  |
| 188 | `catch_class` | 6 | 5.8s |  |
| 189 | `catch_scope_slot` | 7 | 5.8s |  |
| 190 | `checkfilter` | 4 | 1.8s |  |
| 191 | `class_call` | 32 | 5.9s |  |
| 192 | `class_cast_call` | 14 | 5.8s |  |
| 193 | `class_enumeration` | 4 | 5.8s |  |
| 194 | `class_has_own_property` | 2 | 5.7s |  |
| 195 | `class_init_interpreter_mode` | 1 | 5.7s |  |
| 196 | `class_is` | 32 | 5.8s |  |
| 197 | `class_methods` | 5 | 5.8s |  |
| 198 | `class_object_properties` | 10 | 5.8s |  |
| 199 | `class_singleton` | 18 | 5.8s |  |
| 200 | `class_supercalls_errors` | 35 | 6.0s |  |
| 201 | `class_supercalls_mismatched` | 26 | 5.9s |  |
| 202 | `class_superclass_wrong_order` | 1 | 5.7s |  |
| 203 | `class_to_locale_string` | 2 | 5.7s |  |
| 204 | `class_to_string` | 2 | 7.2s |  |
| 205 | `class_value_of` | 2 | 7.3s |  |
| 206 | `click_block` | 5 | 27.4s |  |
| 207 | `click_invisible` | 3 | 7.4s |  |
| 208 | `closures` | 12 | 7.2s |  |
| 209 | `coerce_return_type` | 40 | 7.3s |  |
| 210 | `coerce_return_type_fail` | 2 | 7.2s |  |
| 211 | `coerce_return_void` | 3 | 7.1s |  |
| 212 | `coerce_string` | 86 | 7.3s |  |
| 213 | `coerce_string_precision` | 28 | 7.2s |  |
| 214 | `coerce_to_primitive_side_effects` | 29 | 26.5s |  |
| 215 | `color_matrix_filter` | 19 | 7.3s |  |
| 216 | `construct_errors_swf10` | 8 | 7.2s |  |
| 217 | `construct_frame_list` | 22 | 26.8s |  |
| 218 | `construct_interface` | 3 | 7.2s |  |
| 219 | `constructor_call` | 3 | 7.2s |  |
| 220 | `constructors_vs_timeline` | 5 | 26.6s |  |
| 221 | `constructprop_dynamic_primitive` | 7 | 7.3s |  |
| 222 | `constructprop_method` | 2 | 7.2s |  |
| 223 | `constructsuper_null` | 2 | 7.2s |  |
| 224 | `content_element_basic` | 50 | 7.5s |  |
| 225 | `context3d_creation` | 9 | 7.3s |  |
| 226 | `control_flow_bool` | 4 | 7.2s |  |
| 227 | `control_flow_stricteq` | 8 | 7.2s |  |
| 228 | `convert_boolean` | 30 | 7.2s |  |
| 229 | `convert_integer` | 90 | 7.3s |  |
| 230 | `convert_number` | 56 | 7.3s |  |
| 231 | `convert_uinteger` | 90 | 7.4s |  |
| 232 | `convolution_filter` | 89 | 7.4s |  |
| 233 | `core_exceptions` | 47 | 8.2s |  |
| 234 | `cpool_index_invalid_bytecode_1` | 6 | 7.2s |  |
| 235 | `cpool_index_invalid_bytecode_2` | 3 | 7.2s |  |
| 236 | `cpool_index_invalid_bytecode_3` | 1 | 7.1s |  |
| 237 | `cross_api_version_call_newer` | 12 | 7.8s |  |
| 238 | `cross_api_version_call_older` | 12 | 7.5s |  |
| 239 | `cryptscore` | 11 | 7.3s |  |
| 240 | `currency_parse_result` | 7 | 7.2s |  |
| 241 | `date` | 30 | 7.6s |  |
| 242 | `date_parse` | 36 | 7.2s |  |
| 243 | `declocal` | 46 | 7.2s |  |
| 244 | `declocal_i` | 46 | 7.5s |  |
| 245 | `decode_uri` | 71 | 7.8s |  |
| 246 | `decrement` | 46 | 7.5s |  |
| 247 | `decrement_i` | 46 | 2.5s |  |
| 248 | `default_values` | 7 | 7.5s |  |
| 249 | `delayed_symbolclass` | 28 | 27.6s |  |
| 250 | `describe_type_basic` | 152 | 7.7s |  |
| 251 | `describe_type_json` | 301 | 7.6s |  |
| 252 | `describe_type_metadata` | 125 | 7.6s |  |
| 253 | `describe_type_native` | 23 | 7.5s |  |
| 254 | `dictionary_access` | 62 | 7.7s |  |
| 255 | `dictionary_access_no_pubns` | 2 | 7.5s |  |
| 256 | `dictionary_delete` | 101 | 8.0s |  |
| 257 | `dictionary_foreach` | 42 | 7.8s |  |
| 258 | `dictionary_hasownproperty` | 63 | 7.8s |  |
| 259 | `dictionary_in` | 62 | 7.8s |  |
| 260 | `dictionary_iter_modify` | 8 | 7.6s |  |
| 261 | `dictionary_namespaces` | 36 | 7.6s |  |
| 262 | `displacement_map_filter` | 61 | 7.7s |  |
| 263 | `displayobject_alpha` | 277 | 7.5s |  |
| 264 | `displayobject_blendmode` | 0 | 27.8s |  |
| 265 | `displayobject_colortransform_nested` | 0 | 27.8s |  |
| 266 | `displayobject_early_init` | 54 | 9.0s |  |
| 267 | `displayobject_filters` | 17 | 7.6s |  |
| 268 | `displayobject_from_enterframe` | 1 | 27.6s |  |
| 269 | `displayobject_getbounds_shape` | 0 | 27.8s |  |
| 270 | `displayobject_height` | 6052 | 28.3s |  |
| 271 | `displayobject_hittestobject` | 32 | 7.7s |  |
| 272 | `displayobject_hittestpoint` | 49 | 7.9s |  |
| 273 | `displayobject_hittestpoint_boundary` | 65 | 28.4s |  |
| 274 | `displayobject_hittestpoint_root` | 13 | 7.8s |  |
| 275 | `displayobject_invalid_floats` | 60 | 7.5s |  |
| 276 | `displayobject_invalid_props` | 3 | 7.5s |  |
| 277 | `displayobject_mask` | 3 | 7.6s |  |
| 278 | `displayobject_mask_self_referential` | 0 | 7.5s |  |
| 279 | `displayobject_metaData` | 3 | 7.5s |  |
| 280 | `displayobject_name` | 22 | 28.2s |  |
| 281 | `displayobject_name_from_timeline` | 24 | 7.8s |  |
| 282 | `displayobject_opaque_background` | 6 | 7.7s |  |
| 283 | `displayobject_parent` | 12 | 23.6s |  |
| 284 | `displayobject_root` | 24 | 6.5s |  |
| 285 | `displayobject_rotation` | 1284 | 6.6s |  |
| 286 | `displayobject_scrollrect` | 33 | 7.2s |  |
| 287 | `displayobject_set_matrix_nested` | 0 | 23.8s |  |
| 288 | `displayobject_set_name_loaded` | 3 | 6.6s |  |
| 289 | `displayobject_subclass` | 2 | 6.2s |  |
| 290 | `displayobject_transform` | 89 | 23.9s |  |
| 291 | `displayobject_visible` | 23 | 6.2s |  |
| 292 | `displayobject_width` | 4852 | 24.2s |  |
| 293 | `displayobject_x` | 614 | 6.4s |  |
| 294 | `displayobject_y` | 617 | 6.3s |  |
| 295 | `displayobjectcontainer_addchild` | 32 | 6.4s |  |
| 296 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.5s |  |
| 297 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.4s |  |
| 298 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.3s |  |
| 299 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.3s |  |
| 300 | `displayobjectcontainer_addchildat` | 42 | 6.2s |  |
| 301 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.2s |  |
| 302 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.2s |  |
| 303 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.2s |  |
| 304 | `displayobjectcontainer_contains` | 66 | 23.6s |  |
| 305 | `displayobjectcontainer_getchildat` | 4 | 6.2s |  |
| 306 | `displayobjectcontainer_getchildbyname` | 9 | 6.2s |  |
| 307 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.1s |  |
| 308 | `displayobjectcontainer_getchildindex` | 28 | 6.2s |  |
| 309 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 23.4s |  |
| 310 | `displayobjectcontainer_removechild` | 10 | 6.1s |  |
| 311 | `displayobjectcontainer_removechild_errors` | 4 | 6.0s |  |
| 312 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.3s |  |
| 313 | `displayobjectcontainer_removechildat` | 18 | 6.0s |  |
| 314 | `displayobjectcontainer_removechildren` | 51 | 6.2s |  |
| 315 | `displayobjectcontainer_setchildindex` | 42 | 6.0s |  |
| 316 | `displayobjectcontainer_stopallmovieclips` | 2 | 23.6s |  |
| 317 | `displayobjectcontainer_swapchildren` | 42 | 6.2s |  |
| 318 | `displayobjectcontainer_swapchildrenat` | 42 | 6.2s |  |
| 319 | `displayobjectcontainer_timelineinstance` | 48 | 23.7s |  |
| 320 | `divide` | 1058 | 14.7s |  |
| 321 | `doabc_and_symbolclass_script_init_goto` | 7 | 23.6s |  |
| 322 | `doabc_and_symbolclass_script_init_normal` | 6 | 6.1s |  |
| 323 | `doabc_is_eager` | 1 | 23.7s |  |
| 324 | `documentclass` | 9 | 7.3s |  |
| 325 | `domain_memory` | 133 | 27.4s |  |
| 326 | `drag_drop` | 10 | 7.4s |  |
| 327 | `drop_shadow_filter` | 172 | 7.3s |  |
| 328 | `duplicate_defs` | 1 | 7.0s |  |
| 329 | `eager_init` | 1 | 7.1s |  |
| 330 | `east_asian_justifier_clone` | 8 | 7.2s |  |
| 331 | `edit_text_linkage` | 7 | 7.4s |  |
| 332 | `edittext_align` | 60 | 7.7s |  |
| 333 | `edittext_always_show_selection` | 0 | 26.5s |  |
| 334 | `edittext_antialiastype` | 296 | 7.5s |  |
| 335 | `edittext_at_point_methods_basic` | 16 | 8.6s |  |
| 336 | `edittext_autosize` | 39 | 7.6s |  |
| 337 | `edittext_autosize_align` | 0 | 26.6s |  |
| 338 | `edittext_autosize_height_dynamic` | 60 | 26.3s |  |
| 339 | `edittext_autosize_height_input` | 60 | 7.3s |  |
| 340 | `edittext_autosize_lazy_bounds_events` | 65 | 7.5s |  |
| 341 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.2s |  |
| 342 | `edittext_autosize_lazy_bounds_props` | 490 | 8.6s |  |
| 343 | `edittext_autosize_lazy_bounds_visual` | 0 | 7.3s |  |
| 344 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.4s |  |
| 345 | `edittext_bottom_scroll_v_basic` | 210 | 7.3s |  |
| 346 | `edittext_bounds_scale` | 24 | 26.3s |  |
| 347 | `edittext_bullet` | 30 | 7.3s |  |
| 348 | `edittext_default_format` | 221 | 7.6s |  |
| 349 | `edittext_default_format_empty` | 136 | 7.5s |  |
| 350 | `edittext_empty_text_format` | 7 | 7.2s |  |
| 351 | `edittext_focus_selection` | 5 | 7.1s |  |
| 352 | `edittext_font_size` | 45 | 7.3s |  |
| 353 | `edittext_format_empty_font` | 8 | 7.2s |  |
| 354 | `edittext_get_char_index_at_point` | 4 | 28.0s |  |
| 355 | `edittext_get_line_index_at_point` | 2 | 26.5s |  |
| 356 | `edittext_get_line_index_of_char` | 76 | 8.2s |  |
| 357 | `edittext_getcharboundaries` | 172 | 7.7s |  |
| 358 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.2s |  |
| 359 | `edittext_getcharboundaries_scroll` | 85 | 7.3s |  |
| 360 | `edittext_getlinemetrics` | 146 | 7.6s |  |
| 361 | `edittext_html` | 3101 | 7.7s |  |
| 362 | `edittext_html_condensewhite` | 487 | 7.3s |  |
| 363 | `edittext_html_entity` | 4 | 7.9s |  |
| 364 | `edittext_html_font_size_swf12` | 267 | 27.0s |  |
| 365 | `edittext_html_font_size_swf13` | 273 | 7.1s |  |
| 366 | `edittext_html_roundtrip` | 17 | 7.4s |  |
| 367 | `edittext_ime_focus_lost` | 9 | 27.2s |  |
| 368 | `edittext_input_control` | 12 | 7.5s |  |
| 369 | `edittext_leading` | 9 | 7.7s |  |
| 370 | `edittext_letter_spacing` | 15 | 7.3s |  |
| 371 | `edittext_line_methods` | 294 | 8.8s |  |
| 372 | `edittext_line_metrics` | 11 | 29.1s |  |
| 373 | `edittext_margins` | 25 | 7.6s |  |
| 374 | `edittext_max_scroll_h_basic` | 475 | 7.8s |  |
| 375 | `edittext_max_scroll_v_basic` | 1000 | 7.5s |  |
| 376 | `edittext_mouse_selection` | 363 | 28.4s |  |
| 377 | `edittext_mousedown` | 3 | 7.8s |  |
| 378 | `edittext_mouseenabled` | 26 | 7.4s |  |
| 379 | `edittext_newline_character` | 22 | 7.4s |  |
| 380 | `edittext_newline_stripping` | 64 | 10.4s |  |
| 381 | `edittext_newlines` | 30 | 7.6s |  |
| 382 | `edittext_paragraph_methods` | 257 | 7.3s |  |
| 383 | `edittext_paste_events` | 8 | 7.6s |  |
| 384 | `edittext_paste_maxchars` | 4 | 7.5s |  |
| 385 | `edittext_paste_restrict` | 16 | 7.2s |  |
| 386 | `edittext_restrict` | 191 | 7.3s |  |
| 387 | `edittext_restrict_events` | 22 | 7.3s |  |
| 388 | `edittext_scrollh` | 10 | 7.3s |  |
| 389 | `edittext_selected_text` | 9 | 7.3s |  |
| 390 | `edittext_set_html_same` | 17 | 7.3s |  |
| 391 | `edittext_set_text_vs_html` | 9 | 7.3s |  |
| 392 | `edittext_stylesheet` | 536 | 7.8s |  |
| 393 | `edittext_stylesheet_custom_tag` | 76 | 7.4s |  |
| 394 | `edittext_stylesheet_display` | 272 | 7.4s |  |
| 395 | `edittext_tag_indent` | 49 | 27.3s |  |
| 396 | `edittext_underline` | 40 | 7.4s |  |
| 397 | `edittext_width_height` | 103 | 7.7s |  |
| 398 | `edittext_wordwrap_word` | 150 | 7.6s |  |
| 399 | `edittext_wrap_breaks` | 2375 | 8.0s |  |
| 400 | `element_format_clone` | 44 | 7.6s |  |
| 401 | `element_format_constructor_order` | 64 | 2.7s |  |
| 402 | `element_format_properties` | 235 | 8.4s |  |
| 403 | `empty_bounds` | 1 | 7.4s |  |
| 404 | `encode_uri_surrogate_pair_invalid` | 8 | 24.3s |  |
| 405 | `encode_uri_surrogate_pair_swf11` | 15 | 6.0s |  |
| 406 | `equals` | 512 | 10.0s |  |
| 407 | `error_geterrormessage` | 779 | 6.3s |  |
| 408 | `error_prototype` | 15 | 6.3s |  |
| 409 | `error_stack_trace` | 45 | 6.3s |  |
| 410 | `error_stack_trace_debug_swf17` | 0 | 24.6s |  |
| 411 | `error_stack_trace_debug_swf18` | 0 | 6.2s |  |
| 412 | `error_stack_trace_edge_cases` | 6 | 6.5s |  |
| 413 | `error_stack_trace_release_swf17` | 0 | 6.5s |  |
| 414 | `error_stack_trace_release_swf18` | 0 | 6.3s |  |
| 415 | `error_throwerror` | 103 | 6.4s |  |
| 416 | `error_tostring` | 29 | 6.4s |  |
| 417 | `error_tostring_more` | 86 | 6.5s |  |
| 418 | `es3_inheritance` | 31 | 6.5s |  |
| 419 | `es4_inheritance` | 30 | 6.3s |  |
| 420 | `es4_interfaces` | 30 | 6.3s |  |
| 421 | `es4_method_binding` | 8 | 6.3s |  |
| 422 | `es4_oop_prototypes` | 14 | 6.4s |  |
| 423 | `es4_protected_inheritance` | 6 | 6.3s |  |
| 424 | `escape` | 71 | 6.3s |  |
| 425 | `escape_multi_byte` | 45 | 6.4s |  |
| 426 | `event_bubbles` | 2 | 6.3s |  |
| 427 | `event_cancelable` | 2 | 6.2s |  |
| 428 | `event_clone` | 20 | 6.5s |  |
| 429 | `event_clone_error_redispatch` | 3 | 6.5s |  |
| 430 | `event_clone_on_redispatch` | 10 | 6.5s |  |
| 431 | `event_formattostring` | 31 | 6.3s |  |
| 432 | `event_isdefaultprevented` | 12 | 6.3s |  |
| 433 | `event_target_getter` | 5 | 2.1s |  |
| 434 | `event_target_set` | 9 | 6.2s |  |
| 435 | `event_type` | 1 | 6.3s |  |
| 436 | `event_valueof_tostring` | 18 | 6.2s |  |
| 437 | `eventdispatcher_dispatchevent` | 12 | 6.2s |  |
| 438 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.3s |  |
| 439 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.3s |  |
| 440 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.4s |  |
| 441 | `eventdispatcher_dispatchevent_this` | 5 | 6.2s |  |
| 442 | `eventdispatcher_haseventlistener` | 25 | 6.4s |  |
| 443 | `eventdispatcher_interface_invoke` | 1 | 7.2s |  |
| 444 | `eventdispatcher_tostring` | 10 | 7.4s |  |
| 445 | `eventdispatcher_willtrigger` | 25 | 7.2s |  |
| 446 | `falsiness` | 30 | 7.2s |  |
| 447 | `fast_index_access` | 12 | 7.3s |  |
| 448 | `filefilter_properties` | 4 | 7.2s |  |
| 449 | `filereference_browse_cancel` | 3 | 7.1s |  |
| 450 | `filereference_browse_select` | 9 | 7.2s |  |
| 451 | `filereference_load` | 31 | 7.2s |  |
| 452 | `filereference_save` | 16 | 7.2s |  |
| 453 | `filereference_save_and_browse` | 42 | 7.2s |  |
| 454 | `filereference_save_and_load` | 22 | 7.2s |  |
| 455 | `filereference_uninitialized` | 8 | 7.1s |  |
| 456 | `filereferencelist_browse_cancel` | 6 | 7.1s |  |
| 457 | `filereferencelist_browse_select` | 7 | 7.1s |  |
| 458 | `filter_rewind` | 8 | 26.4s |  |
| 459 | `filters_array_holes` | 25 | 7.2s |  |
| 460 | `finddef` | 3 | 7.1s |  |
| 461 | `findprop_global_prototype` | 6 | 7.2s |  |
| 462 | `flash_media_video_constructor` | 156 | 8.0s |  |
| 463 | `flash_media_video_rotation_probe` | 27 | 7.2s |  |
| 464 | `flash_media_video_setter` | 40 | 7.7s |  |
| 465 | `flash_trace` | 17 | 7.2s |  |
| 466 | `flash_ui_mouse_cursor` | 35 | 7.5s |  |
| 467 | `flash_xml` | 29 | 7.2s |  |
| 468 | `flash_xml_cloneNode` | 22 | 7.2s |  |
| 469 | `flash_xml_namespace` | 109 | 7.1s |  |
| 470 | `flash_xml_removeNode` | 60 | 7.2s |  |
| 471 | `focus_events_code` | 161 | 26.6s |  |
| 472 | `focus_events_key_basic` | 132 | 26.6s |  |
| 473 | `focus_events_key_navigation` | 53 | 26.4s |  |
| 474 | `focus_events_key_same_object` | 26 | 7.2s |  |
| 475 | `focus_events_mixed_key_mouse` | 100 | 26.3s |  |
| 476 | `focus_events_mouse_basic` | 260 | 26.4s |  |
| 477 | `focus_events_mouse_focusable` | 112 | 26.5s |  |
| 478 | `focus_events_mouse_same_object` | 40 | 7.2s |  |
| 479 | `focus_remove` | 20 | 26.1s |  |
| 480 | `focus_root_movie` | 4 | 26.3s |  |
| 481 | `focus_stage` | 1 | 7.2s |  |
| 482 | `focusrect` | 18 | 7.9s |  |
| 483 | `focusrect_focuslost` | 9 | 27.1s |  |
| 484 | `focusrect_property` | 110 | 26.6s |  |
| 485 | `font_description_clone` | 14 | 7.4s |  |
| 486 | `font_embedded` | 24 | 7.8s |  |
| 487 | `font_enumeratefonts` | 41 | 8.1s |  |
| 488 | `font_enumeratefonts_filter` | 4 | 8.1s |  |
| 489 | `font_enumeratefonts_order` | 9 | 8.7s |  |
| 490 | `font_hasglyphs` | 40 | 7.9s |  |
| 491 | `font_registerfont` | 129 | 8.4s |  |
| 492 | `framelabel_constr` | 5 | 7.5s |  |
| 493 | `function_call` | 12 | 2.5s |  |
| 494 | `function_call_arguments` | 46 | 7.5s |  |
| 495 | `function_call_arguments_enumerate` | 5 | 7.3s |  |
| 496 | `function_call_coercion` | 108 | 7.7s |  |
| 497 | `function_call_default` | 6 | 7.3s |  |
| 498 | `function_call_rest` | 22 | 7.3s |  |
| 499 | `function_call_types` | 3 | 7.3s |  |
| 500 | `function_call_via_apply` | 11 | 7.3s |  |
| 501 | `function_call_via_call` | 3 | 7.3s |  |
| 502 | `function_display_anonymous` | 7 | 2.5s |  |
| 503 | `function_length` | 6 | 7.3s |  |
| 504 | `function_object` | 2 | 7.3s |  |
| 505 | `function_proto` | 5 | 7.3s |  |
| 506 | `function_proto_created` | 61 | 7.4s |  |
| 507 | `function_to_locale_string` | 4 | 7.3s |  |
| 508 | `function_to_string` | 4 | 7.2s |  |
| 509 | `function_type` | 6 | 7.3s |  |
| 510 | `function_unbound_this` | 51 | 7.4s |  |
| 511 | `function_value_of` | 4 | 7.3s |  |
| 512 | `game_input` | 4 | 7.3s |  |
| 513 | `generate_random_bytes` | 3 | 7.3s |  |
| 514 | `geom_transform` | 74 | 27.1s |  |
| 515 | `get_definition_by_name` | 11 | 7.3s |  |
| 516 | `get_qualified_class_name` | 20 | 7.4s |  |
| 517 | `get_qualified_super_class_name` | 18 | 7.4s |  |
| 518 | `get_slot_edge_cases` | 1 | 7.4s |  |
| 519 | `get_timer` | 2 | 2.4s |  |
| 520 | `getglobalslot` | 1 | 7.3s |  |
| 521 | `getouterscope` | 8 | 7.3s |  |
| 522 | `getouterscope_two_classobjects` | 13 | 7.4s |  |
| 523 | `getter_different_namespace_setter` | 2 | 7.1s |  |
| 524 | `glow_filter` | 127 | 7.3s |  |
| 525 | `goto_button_nested_framescript` | 28 | 26.7s |  |
| 526 | `goto_in_constructframe` | 12 | 26.5s |  |
| 527 | `goto_in_scene_last_frame` | 2 | 26.3s |  |
| 528 | `goto_methods` | 56 | 7.4s |  |
| 529 | `goto_methods_swfver10` | 8 | 7.2s |  |
| 530 | `goto_nested_construct_sibling` | 18 | 7.6s |  |
| 531 | `goto_nested_framescript` | 9 | 7.3s |  |
| 532 | `goto_on_orphan` | 15 | 7.4s |  |
| 533 | `gradient_bevel_filter` | 206 | 7.3s |  |
| 534 | `gradient_glow_filter` | 206 | 7.1s |  |
| 535 | `graphic_linkage` | 9 | 7.4s |  |
| 536 | `graphics_bad_direct_commands` | 5 | 7.7s |  |
| 537 | `graphics_bitmap_fill` | 0 | 27.9s |  |
| 538 | `graphics_bitmaps` | 0 | 7.4s |  |
| 539 | `graphics_direct_commands` | 0 | 7.3s |  |
| 540 | `graphics_draw_triangles` | 98 | 27.2s |  |
| 541 | `graphics_gradients` | 0 | 7.3s |  |
| 542 | `graphics_gradients_nulls` | 0 | 7.3s |  |
| 543 | `graphics_path` | 56 | 7.2s |  |
| 544 | `graphics_round_rects` | 0 | 7.2s |  |
| 545 | `graphics_simple_shapes` | 0 | 7.2s |  |
| 546 | `greaterequals` | 512 | 11.1s |  |
| 547 | `greaterthan` | 512 | 11.2s |  |
| 548 | `has_own_property` | 102 | 7.7s |  |
| 549 | `hasownproperty_namespaces` | 2 | 7.2s |  |
| 550 | `hello_world` | 1 | 7.1s |  |
| 551 | `hittest_morph` | 30 | 7.3s |  |
| 552 | `if_eq` | 10 | 7.2s |  |
| 553 | `if_gt` | 1 | 7.2s |  |
| 554 | `if_gte` | 10 | 2.4s |  |
| 555 | `if_lt` | 1 | 0.6s |  |
| 556 | `if_lte` | 10 | 7.0s |  |
| 557 | `if_ne` | 7 | 2.4s |  |
| 558 | `if_stricteq` | 6 | 7.2s |  |
| 559 | `if_strictne` | 11 | 7.2s |  |
| 560 | `ime_linux_dead_keys` | 10 | 7.2s |  |
| 561 | `in` | 102 | 7.6s |  |
| 562 | `inclocal` | 46 | 7.2s |  |
| 563 | `inclocal_i` | 46 | 7.2s |  |
| 564 | `increment` | 46 | 7.3s |  |
| 565 | `increment_i` | 46 | 7.2s |  |
| 566 | `indexing_delete` | 75 | 7.2s |  |
| 567 | `init_callee_cached` | 24 | 7.1s |  |
| 568 | `instanceof` | 58 | 7.4s |  |
| 569 | `instantiate_root_character` | 4 | 7.5s |  |
| 570 | `instantiation_on_enter_frame` | 7 | 26.6s |  |
| 571 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.2s |  |
| 572 | `int_constr` | 92 | 7.4s |  |
| 573 | `int_edge_cases` | 19 | 27.4s |  |
| 574 | `int_instanceof` | 3 | 7.2s |  |
| 575 | `int_tofixed` | 1215 | 7.2s |  |
| 576 | `int_toprecision` | 1125 | 7.4s |  |
| 577 | `int_tostring` | 3375 | 7.5s |  |
| 578 | `interactiveobject_enabled` | 25 | 7.2s |  |
| 579 | `interface_namespaces` | 78 | 7.4s |  |
| 580 | `invalid_utf8` | 12 | 7.2s |  |
| 581 | `is_finite` | 46 | 7.2s |  |
| 582 | `is_nan` | 46 | 7.0s |  |
| 583 | `is_prototype_of` | 12 | 7.1s |  |
| 584 | `issue_10221` | 2 | 7.1s |  |
| 585 | `issue_13780` | 12 | 7.1s |  |
| 586 | `issue_14901` | 1 | 7.1s |  |
| 587 | `issue_17675_edittext_paste_maxchars` | 1 | 7.4s |  |
| 588 | `issue_5292` | 5 | 7.3s |  |
| 589 | `issue_8630` | 2 | 7.3s |  |
| 590 | `issue_8630_placeremoveplace` | 15 | 7.4s |  |
| 591 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.2s |  |
| 592 | `issue_8630_scriptremove` | 11 | 7.3s |  |
| 593 | `istype` | 24 | 2.5s |  |
| 594 | `istypelate` | 58 | 7.5s |  |
| 595 | `istypelate_coerce` | 198 | 8.3s |  |
| 596 | `jpeg_loader_context` | 6 | 7.3s |  |
| 597 | `json_errors` | 9 | 27.7s |  |
| 598 | `json_parse` | 21 | 7.4s |  |
| 599 | `json_stringify` | 12 | 7.6s |  |
| 600 | `json_stringify_function` | 12 | 7.3s |  |
| 601 | `json_stringify_order` | 1 | 7.4s |  |
| 602 | `json_version_gated` | 1 | 7.5s |  |
| 603 | `key_input_80percent` | 1812 | 45.6s |  |
| 604 | `key_input_location` | 126 | 7.3s |  |
| 605 | `key_input_numpad` | 384 | 7.4s |  |
| 606 | `large_preload_from_bytes` | 51 | 30.3s |  |
| 607 | `large_preload_from_url` | 27 | 9.6s |  |
| 608 | `large_preload_image_from_bytes` | 25 | 7.8s |  |
| 609 | `lazyinit` | 17 | 7.5s |  |
| 610 | `lessequals` | 512 | 11.3s |  |
| 611 | `lessthan` | 512 | 11.0s |  |
| 612 | `loader_bitmap_transparency` | 14 | 7.3s |  |
| 613 | `loader_bytes_unknown_content` | 14 | 7.2s |  |
| 614 | `loader_child_getdefinition` | 5 | 7.4s |  |
| 615 | `loader_duplicate_coerce` | 3 | 7.5s |  |
| 616 | `loader_duplicate_coerce_new_domain` | 4 | 7.4s |  |
| 617 | `loader_error_in_root_ctor` | 4 | 7.6s |  |
| 618 | `loader_events` | 92 | 7.7s |  |
| 619 | `loader_image` | 8 | 7.3s |  |
| 620 | `loader_jpegxr` | 2 | 26.5s |  |
| 621 | `loader_jpegxr_alpha` | 1 | 27.3s |  |
| 622 | `loader_loadbytes_events` | 30 | 7.6s |  |
| 623 | `loader_loadbytes_invalid_png` | 4 | 7.2s |  |
| 624 | `loader_loadbytes_url` | 12 | 7.4s |  |
| 625 | `loader_loaderurl` | 6 | 7.6s |  |
| 626 | `loader_method` | 85 | 7.2s |  |
| 627 | `loader_noninteractive_try_click_root` | 5 | 27.1s |  |
| 628 | `loader_reuse` | 38 | 7.5s |  |
| 629 | `loader_try_click_root` | 16 | 7.5s |  |
| 630 | `loader_unknown_content` | 24 | 7.3s |  |
| 631 | `loader_visibility_interactive` | 1 | 7.3s |  |
| 632 | `loaderinfo_events` | 7 | 7.2s |  |
| 633 | `loaderinfo_loadurl` | 12 | 7.2s |  |
| 634 | `loaderinfo_more` | 6 | 7.4s |  |
| 635 | `loaderinfo_properties` | 18 | 26.6s |  |
| 636 | `loaderinfo_properties_not_loaded` | 23 | 7.5s |  |
| 637 | `loaderinfo_quine` | 1005 | 7.4s |  |
| 638 | `loaderinfo_root` | 10 | 7.4s |  |
| 639 | `loaderinfo_root_allows` | 2 | 7.3s |  |
| 640 | `localconnection` | 890 | 9.2s |  |
| 641 | `localconnection_send` | 4 | 45.0s |  |
| 642 | `lshift` | 1058 | 19.5s |  |
| 643 | `mask_reapply` | 1 | 26.6s |  |
| 644 | `math` | 497 | 7.5s |  |
| 645 | `matrix` | 338 | 18.2s |  |
| 646 | `matrix3d` | 57 | 27.3s |  |
| 647 | `matrix3d_append` | 16 | 7.4s |  |
| 648 | `matrix3d_append_prepend_scale` | 86 | 7.3s |  |
| 649 | `matrix3d_append_prepend_translation` | 42 | 7.3s |  |
| 650 | `matrix3d_compose` | 34 | 7.4s |  |
| 651 | `matrix3d_constructor_clone` | 15 | 7.2s |  |
| 652 | `matrix3d_copy_column` | 83 | 7.5s |  |
| 653 | `matrix3d_copy_from` | 19 | 7.2s |  |
| 654 | `matrix3d_copy_raw_data_from` | 55 | 2.5s |  |
| 655 | `matrix3d_copy_raw_data_to` | 38 | 7.4s |  |
| 656 | `matrix3d_copy_row` | 83 | 7.1s |  |
| 657 | `matrix3d_copy_to_matrix3d` | 19 | 7.2s |  |
| 658 | `matrix3d_determinant` | 182 | 7.4s |  |
| 659 | `matrix3d_interpolate` | 21 | 7.4s |  |
| 660 | `matrix3d_invert` | 18 | 7.3s |  |
| 661 | `matrix3d_position` | 19 | 7.5s |  |
| 662 | `matrix3d_precision` | 28 | 7.5s |  |
| 663 | `matrix3d_prepend` | 16 | 7.3s |  |
| 664 | `matrix3d_raw_data` | 33 | 7.4s |  |
| 665 | `matrix3d_transform_vector` | 52 | 7.6s |  |
| 666 | `matrix3d_transpose` | 5 | 7.2s |  |
| 667 | `method_association` | 5 | 7.2s |  |
| 668 | `method_without_body` | 3 | 26.9s |  |
| 669 | `missing_external_interface` | 10 | 7.3s |  |
| 670 | `modulo` | 1058 | 19.4s |  |
| 671 | `morph_shape` | 2 | 27.1s |  |
| 672 | `mouse_children` | 192 | 27.8s |  |
| 673 | `mouse_click_events` | 90 | 27.1s |  |
| 674 | `mouse_double_click_events` | 188 | 7.3s |  |
| 675 | `mouse_empty_parent` | 4 | 7.2s |  |
| 676 | `mouse_over_while_dragging` | 3 | 7.5s |  |
| 677 | `mouse_pick_avm1_root` | 2 | 27.1s |  |
| 678 | `mouse_pick_button_mode` | 2 | 7.3s |  |
| 679 | `mouse_pick_dobj_mask` | 4 | 7.3s |  |
| 680 | `mouse_pick_masking` | 7 | 37.6s |  |
| 681 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 22.3s |  |
| 682 | `mouse_pick_non_interactive_dobj_mask` | 3 | 22.3s |  |
| 683 | `mouse_pick_text` | 8 | 6.1s |  |
| 684 | `mouse_sibling` | 8 | 5.8s |  |
| 685 | `mouse_wheel_events` | 36 | 23.1s |  |
| 686 | `mouseevent_constr` | 66 | 6.0s |  |
| 687 | `mouseevent_stagexy` | 35 | 5.9s |  |
| 688 | `mouseevent_valueof_tostring` | 28 | 5.8s |  |
| 689 | `movieclip_addframescript` | 3 | 22.4s |  |
| 690 | `movieclip_addframescript_error` | 9 | 5.8s |  |
| 691 | `movieclip_child_property` | 16 | 5.9s |  |
| 692 | `movieclip_constr` | 21 | 5.8s |  |
| 693 | `movieclip_currentlabels` | 17 | 22.4s |  |
| 694 | `movieclip_currentlabels_dupes1` | 46 | 22.5s |  |
| 695 | `movieclip_currentlabels_dupes2` | 30 | 5.8s |  |
| 696 | `movieclip_currentlabels_dupes3` | 67 | 5.8s |  |
| 697 | `movieclip_currentscene` | 12 | 22.3s |  |
| 698 | `movieclip_dispatchevent` | 430 | 6.1s |  |
| 699 | `movieclip_dispatchevent_cancel` | 102 | 6.0s |  |
| 700 | `movieclip_dispatchevent_handlerorder` | 251 | 6.0s |  |
| 701 | `movieclip_dispatchevent_selfadd` | 80 | 5.9s |  |
| 702 | `movieclip_dispatchevent_target` | 899 | 6.0s |  |
| 703 | `movieclip_displayevents` | 96 | 22.4s |  |
| 704 | `movieclip_displayevents_clickgoto` | 676 | 23.0s |  |
| 705 | `movieclip_displayevents_clickgoto2` | 2001 | 6.3s |  |
| 706 | `movieclip_displayevents_clickplay` | 575 | 6.0s |  |
| 707 | `movieclip_displayevents_clicksymbol` | 562 | 6.0s |  |
| 708 | `movieclip_displayevents_constructframegoto` | 140 | 6.3s |  |
| 709 | `movieclip_displayevents_constructframeplay` | 50 | 6.0s |  |
| 710 | `movieclip_displayevents_constructframesymbol` | 144 | 6.0s |  |
| 711 | `movieclip_displayevents_dblhandler` | 21 | 6.1s |  |
| 712 | `movieclip_displayevents_enterframegoto` | 149 | 6.1s |  |
| 713 | `movieclip_displayevents_enterframeplay` | 48 | 6.1s |  |
| 714 | `movieclip_displayevents_enterframesymbol` | 149 | 22.4s |  |
| 715 | `movieclip_displayevents_exitframegoto` | 106 | 5.9s |  |
| 716 | `movieclip_displayevents_exitframeplay` | 44 | 5.9s |  |
| 717 | `movieclip_displayevents_exitframesymbol` | 135 | 6.0s |  |
| 718 | `movieclip_displayevents_looping` | 63 | 22.4s |  |
| 719 | `movieclip_displayevents_stopped` | 113 | 6.4s |  |
| 720 | `movieclip_displayevents_swap` | 96 | 1.6s |  |
| 721 | `movieclip_displayevents_timeline` | 128 | 6.2s |  |
| 722 | `movieclip_drawrect` | 54 | 44.4s |  |
| 723 | `movieclip_frameconstruct_skipped` | 9 | 7.4s |  |
| 724 | `movieclip_goto_during_frame_script` | 15 | 26.3s |  |
| 725 | `movieclip_goto_overwrite` | 14 | 26.5s |  |
| 726 | `movieclip_goto_scene_last_frame_int` | 1 | 26.6s |  |
| 727 | `movieclip_goto_scene_last_frame_label` | 1 | 7.1s |  |
| 728 | `movieclip_gotoandplay` | 15 | 26.6s |  |
| 729 | `movieclip_gotoandstop` | 13 | 7.2s |  |
| 730 | `movieclip_gotoandstop_children` | 4 | 7.2s |  |
| 731 | `movieclip_gotoandstop_framescripts1` | 4 | 7.2s |  |
| 732 | `movieclip_gotoandstop_framescripts2` | 4 | 2.3s |  |
| 733 | `movieclip_gotoandstop_framescripts_self` | 7 | 26.3s |  |
| 734 | `movieclip_gotoandstop_queueing` | 12 | 26.3s |  |
| 735 | `movieclip_hittest` | 67 | 7.3s |  |
| 736 | `movieclip_next_frame` | 2 | 7.1s |  |
| 737 | `movieclip_next_scene` | 6 | 26.3s |  |
| 738 | `movieclip_play` | 3 | 7.1s |  |
| 739 | `movieclip_prev_frame` | 3 | 6.9s |  |
| 740 | `movieclip_prev_scene` | 7 | 7.2s |  |
| 741 | `movieclip_properties` | 79 | 26.5s |  |
| 742 | `movieclip_queued_noop_goto_swf10` | 9 | 7.2s |  |
| 743 | `movieclip_queued_noop_goto_swf9` | 7 | 0.7s |  |
| 744 | `movieclip_scenes` | 11 | 7.1s |  |
| 745 | `movieclip_soundtransform` | 831 | 28.2s |  |
| 746 | `movieclip_stop` | 1 | 7.0s |  |
| 747 | `movieclip_super_is_symbol` | 20 | 7.4s |  |
| 748 | `movieclip_symbol_constr` | 8 | 7.2s |  |
| 749 | `movieclip_text_mousedown` | 1 | 7.2s |  |
| 750 | `movieclip_willtrigger` | 5 | 7.2s |  |
| 751 | `multiply` | 1058 | 19.0s |  |
| 752 | `namespace_constr` | 253 | 7.5s |  |
| 753 | `namespace_constr_args` | 1 | 7.1s |  |
| 754 | `namespace_enumeration_order` | 7 | 26.2s |  |
| 755 | `nan_scale` | 9 | 7.1s |  |
| 756 | `native_menu_basic` | 19 | 9.4s |  |
| 757 | `navigateToURL_target_normalize` | 107 | 28.3s |  |
| 758 | `negate` | 30 | 7.2s |  |
| 759 | `negative_volume_panned` | 0 | 7.4s |  |
| 760 | `nested_iteration` | 11 | 7.1s |  |
| 761 | `net_getClassByAlias` | 3 | 7.1s |  |
| 762 | `net_navigateToURL` | 57 | 7.1s |  |
| 763 | `net_stream_play_options` | 6 | 7.2s |  |
| 764 | `netconnection_close` | 55 | 44.4s |  |
| 765 | `netconnection_properties` | 78 | 7.2s |  |
| 766 | `netconnection_send_remote` | 50 | 29.5s |  |
| 767 | `netconnection_serialize_arrays` | 6 | 7.2s |  |
| 768 | `netfilterevent` | 10 | 26.2s |  |
| 769 | `netstream_client` | 10 | 7.3s |  |
| 770 | `netstream_connect` | 7 | 7.2s |  |
| 771 | `netstream_flv_date` | 4 | 7.3s |  |
| 772 | `newactivation_in_script_init` | 3 | 7.1s |  |
| 773 | `newclass_mismatched` | 4 | 7.1s |  |
| 774 | `newclass_twice` | 3 | 7.1s |  |
| 775 | `nonconflicting_declarations` | 0 | 7.1s |  |
| 776 | `null_void_types` | 8 | 7.2s |  |
| 777 | `number_autoconv` | 21 | 7.1s |  |
| 778 | `number_autoconv_amf` | 132 | 7.2s |  |
| 779 | `number_autoconv_array_sort_32bit` | 1 | 7.1s |  |
| 780 | `number_constr` | 58 | 7.2s |  |
| 781 | `number_convert_edge_cases` | 180 | 26.3s |  |
| 782 | `number_toexponential` | 378 | 7.2s |  |
| 783 | `number_toexponential2` | 35 | 7.1s |  |
| 784 | `number_tofixed` | 378 | 7.2s |  |
| 785 | `number_toprecision` | 350 | 7.4s |  |
| 786 | `obfuscated_class_names` | 3 | 7.3s |  |
| 787 | `object_enumeration` | 10 | 7.6s |  |
| 788 | `object_prototype` | 4 | 7.3s |  |
| 789 | `object_to_locale_string` | 2 | 7.3s |  |
| 790 | `object_to_string` | 2 | 7.3s |  |
| 791 | `object_value_of` | 2 | 2.2s |  |
| 792 | `op_coerce` | 54 | 7.5s |  |
| 793 | `op_coerce_x` | 54 | 7.7s |  |
| 794 | `op_escxattr` | 2 | 7.5s |  |
| 795 | `op_escxelem` | 2 | 7.5s |  |
| 796 | `op_lookupswitch` | 4 | 7.5s |  |
| 797 | `optimize_coerce` | 1 | 7.2s |  |
| 798 | `orphan_movie_complex` | 80 | 7.6s |  |
| 799 | `orphan_movie_reorder` | 111 | 26.8s |  |
| 800 | `orphan_removeobject` | 636 | 46.0s |  |
| 801 | `package_namespace` | 7 | 27.1s |  |
| 802 | `param_default_value_has_zero_cpool_index` | 1 | 26.9s |  |
| 803 | `parent_early_access_child` | 16 | 27.3s |  |
| 804 | `parse_float` | 81 | 7.7s |  |
| 805 | `parse_float_swf10` | 81 | 7.3s |  |
| 806 | `parse_int` | 135 | 8.0s |  |
| 807 | `perspective_projection` | 1443 | 27.2s |  |
| 808 | `perspective_projection_basic` | 40 | 7.4s |  |
| 809 | `pixelbender_ceil` | 77 | 7.6s |  |
| 810 | `pixelbender_conditional` | 138 | 7.8s |  |
| 811 | `pixelbender_conversions` | 270 | 7.7s |  |
| 812 | `pixelbender_dithering` | 8 | 31.7s |  |
| 813 | `pixelbender_div` | 36 | 7.7s |  |
| 814 | `pixelbender_effect_BlurredFocus` | 0 | 34.8s |  |
| 815 | `pixelbender_effect_glassDisplace` | 0 | 13.1s |  |
| 816 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 30.5s |  |
| 817 | `pixelbender_effect_smudge` | 0 | 10.6s |  |
| 818 | `pixelbender_effect_tintype` | 0 | 9.9s |  |
| 819 | `pixelbender_effect_twirl` | 0 | 11.2s |  |
| 820 | `pixelbender_eof` | 7 | 7.4s |  |
| 821 | `pixelbender_images` | 0 | 9.6s |  |
| 822 | `pixelbender_input` | 103 | 27.6s |  |
| 823 | `pixelbender_logicalnot` | 20 | 7.5s |  |
| 824 | `pixelbender_malformed_data` | 190 | 27.7s |  |
| 825 | `pixelbender_multiple_out_params` | 1 | 7.4s |  |
| 826 | `pixelbender_no_out_param` | 6 | 7.4s |  |
| 827 | `pixelbender_outputs` | 13 | 7.6s |  |
| 828 | `pixelbender_padding_bytes` | 22 | 7.5s |  |
| 829 | `pixelbender_param_qualifier` | 512 | 7.5s |  |
| 830 | `pixelbender_parameters` | 1563 | 7.8s |  |
| 831 | `pixelbender_parameters_bool` | 240 | 7.7s |  |
| 832 | `pixelbender_parameters_int_vs_bool` | 54 | 7.5s |  |
| 833 | `pixelbender_parse_errors` | 6 | 7.5s |  |
| 834 | `pixelbender_rsqrt` | 24 | 7.5s |  |
| 835 | `pixelbender_select_kinds` | 8 | 7.6s |  |
| 836 | `pixelbender_shaderdata` | 49 | 7.5s |  |
| 837 | `pixelbender_shaderdata_setter` | 99 | 7.8s |  |
| 838 | `pixelbender_sign` | 60 | 7.6s |  |
| 839 | `pixelbender_vector_output` | 11 | 7.7s |  |
| 840 | `place_and_lookup/swf10` | 33 | 7.5s |  |
| 841 | `place_and_lookup/swf9` | 33 | 0.7s |  |
| 842 | `place_multiple` | 17 | 47.5s |  |
| 843 | `place_object_replace` | 9 | 28.9s |  |
| 844 | `place_object_replace_2` | 24 | 27.7s |  |
| 845 | `place_object_same_depth_frame` | 1 | 27.8s |  |
| 846 | `point` | 132 | 8.1s |  |
| 847 | `primitive_edge_cases` | 1 | 7.5s |  |
| 848 | `primitive_keys` | 54 | 7.6s |  |
| 849 | `primitive_toString` | 277 | 7.7s |  |
| 850 | `primitive_valueOf` | 285 | 7.5s |  |
| 851 | `print_job_options` | 3 | 7.5s |  |
| 852 | `property_is_enumerable` | 114 | 8.2s |  |
| 853 | `property_is_enumerable_reset` | 23 | 7.5s |  |
| 854 | `property_priority` | 22 | 7.9s |  |
| 855 | `property_priority_chained` | 4 | 7.5s |  |
| 856 | `property_priority_definition_names_order` | 2 | 7.8s |  |
| 857 | `property_priority_three_level` | 6 | 7.7s |  |
| 858 | `propertyisenumerable_namespaces` | 6 | 7.6s |  |
| 859 | `prototype_set_null` | 7 | 7.6s |  |
| 860 | `proxy_callproperty` | 24 | 7.6s |  |
| 861 | `proxy_deleteproperty` | 64 | 7.7s |  |
| 862 | `proxy_enumeration` | 34 | 7.5s |  |
| 863 | `proxy_getproperty` | 77 | 7.5s |  |
| 864 | `proxy_hasownproperty` | 8 | 7.5s |  |
| 865 | `proxy_hasproperty` | 32 | 7.5s |  |
| 866 | `proxy_not_overridden` | 54 | 7.6s |  |
| 867 | `proxy_serialize` | 9 | 7.5s |  |
| 868 | `proxy_setproperty` | 42 | 7.5s |  |
| 869 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.4s |  |
| 870 | `qname_constr` | 32 | 7.5s |  |
| 871 | `qname_constr_namespace` | 24 | 7.6s |  |
| 872 | `qname_enumeration` | 9 | 7.6s |  |
| 873 | `qname_indexing` | 23 | 7.6s |  |
| 874 | `qname_tostring` | 25 | 7.6s |  |
| 875 | `qname_valueof` | 29 | 7.5s |  |
| 876 | `rectangle` | 1094 | 8.2s |  |
| 877 | `regexp_constr` | 148 | 7.7s |  |
| 878 | `regexp_exec` | 19 | 7.5s |  |
| 879 | `regexp_extended` | 47 | 7.4s |  |
| 880 | `regexp_multiargs` | 1 | 7.6s |  |
| 881 | `regexp_test` | 27 | 8.6s |  |
| 882 | `regexp_toString` | 10 | 8.7s |  |
| 883 | `register_script_refresh` | 35 | 31.7s |  |
| 884 | `remove_child_clear_field` | 88 | 46.0s |  |
| 885 | `remove_dobj` | 3 | 27.7s |  |
| 886 | `resolve_order` | 4 | 7.3s |  |
| 887 | `responder_null_callbacks` | 1 | 27.4s |  |
| 888 | `rng` | 1 | 8.7s |  |
| 889 | `rootless` | 42 | 7.6s |  |
| 890 | `rshift` | 1058 | 19.6s |  |
| 891 | `rtqname_not_namespace` | 12 | 7.5s |  |
| 892 | `sandbox_type_inherited` | 2 | 7.9s |  |
| 893 | `sandbox_type_local_file` | 1 | 7.4s |  |
| 894 | `sandbox_type_local_network` | 1 | 7.1s |  |
| 895 | `scene_constr` | 8 | 7.6s |  |
| 896 | `scope_optimizations` | 4 | 7.3s |  |
| 897 | `scopes_dont_cache/order-1` | 1 | 27.3s |  |
| 898 | `scopes_dont_cache/order-2` | 1 | 0.4s |  |
| 899 | `security_domain_current` | 2 | 7.3s |  |
| 900 | `selection` | 239 | 7.9s |  |
| 901 | `set_local_0` | 31 | 7.4s |  |
| 902 | `set_property_is_enumerable` | 85 | 7.9s |  |
| 903 | `shaderparameter_value` | 4 | 7.3s |  |
| 904 | `shape_drawrect` | 54 | 7.4s |  |
| 905 | `shared_object_no_root` | 3 | 7.4s |  |
| 906 | `simplebutton_added_to_stage` | 45 | 27.7s |  |
| 907 | `simplebutton_childevents` | 86 | 27.7s |  |
| 908 | `simplebutton_childevents_nested` | 54 | 7.7s |  |
| 909 | `simplebutton_childevents_sprite` | 13 | 7.5s |  |
| 910 | `simplebutton_childprops` | 144 | 7.7s |  |
| 911 | `simplebutton_childshuffle` | 23 | 7.4s |  |
| 912 | `simplebutton_constr` | 36 | 7.8s |  |
| 913 | `simplebutton_constr_childevents` | 48 | 7.8s |  |
| 914 | `simplebutton_constr_params` | 42 | 7.6s |  |
| 915 | `simplebutton_mouseenabled` | 26 | 7.5s |  |
| 916 | `simplebutton_multi_children` | 19 | 7.6s |  |
| 917 | `simplebutton_soundtransform` | 887 | 29.5s |  |
| 918 | `simplebutton_structure` | 27 | 7.7s |  |
| 919 | `simplebutton_symbolclass` | 68 | 7.8s |  |
| 920 | `slot_disp_id_shared_numbering` | 1 | 27.2s |  |
| 921 | `slots_force_autoassigned` | 1 | 23.1s |  |
| 922 | `socket_after_disconnect` | 1 | 6.2s |  |
| 923 | `socket_close` | 2 | 5.9s |  |
| 924 | `socket_connect` | 4 | 6.2s |  |
| 925 | `socket_errors` | 56 | 6.5s |  |
| 926 | `socket_read_big` | 48 | 6.1s |  |
| 927 | `socket_read_little` | 48 | 1.7s |  |
| 928 | `socket_read_write_object` | 8 | 6.1s |  |
| 929 | `socket_write_big` | 15 | 6.6s |  |
| 930 | `socket_write_little` | 14 | 6.1s |  |
| 931 | `sound_constructor_with_args` | 6 | 6.2s |  |
| 932 | `sound_embeddedprops` | 26 | 6.2s |  |
| 933 | `sound_play` | 19 | 6.2s |  |
| 934 | `sound_rootless` | 7 | 6.1s |  |
| 935 | `sound_valueof` | 33 | 6.2s |  |
| 936 | `soundchannel_soundtransform` | 835 | 24.8s |  |
| 937 | `soundchannel_soundtransform_exists` | 5 | 23.0s |  |
| 938 | `soundchannel_stop` | 8 | 23.0s |  |
| 939 | `soundmixer_buffertime` | 5 | 6.0s |  |
| 940 | `soundmixer_soundtransform` | 900 | 7.6s |  |
| 941 | `soundmixer_stopall` | 6 | 22.8s |  |
| 942 | `soundtransform` | 442 | 9.8s |  |
| 943 | `space_justifier_clone` | 12 | 6.0s |  |
| 944 | `sprite_with_frames` | 0 | 23.1s |  |
| 945 | `stage3d_agal_cross_product` | 0 | 8.1s |  |
| 946 | `stage3d_agal_upload_errors` | 66 | 8.2s |  |
| 947 | `stage3d_bitmap` | 0 | 26.8s |  |
| 948 | `stage3d_blend` | 81 | 24.7s |  |
| 949 | `stage3d_context3d_string_args` | 158 | 7.0s |  |
| 950 | `stage3d_errors` | 7 | 6.1s |  |
| 951 | `stage3d_errors_atf` | 3 | 7.2s |  |
| 952 | `stage3d_errors_swf_29` | 6 | 6.3s |  |
| 953 | `stage3d_float1_index` | 0 | 24.9s |  |
| 954 | `stage3d_fractal` | 0 | 25.1s |  |
| 955 | `stage3d_ignore_sampler_override` | 0 | 25.5s |  |
| 956 | `stage3d_multistage_triangle` | 3 | 8.1s |  |
| 957 | `stage3d_program_constants_bytearray_be` | 0 | 26.5s |  |
| 958 | `stage3d_program_constants_bytearray_le` | 0 | 39.6s |  |
| 959 | `stage3d_program_constants_invalid_input` | 21 | 23.9s |  |
| 960 | `stage3d_raytrace` | 0 | 42.8s |  |
| 961 | `stage3d_rotating_cube` | 0 | 8.2s |  |
| 962 | `stage3d_sampler` | 0 | 7.8s |  |
| 963 | `stage3d_sampler_partial_upload` | 0 | 7.8s |  |
| 964 | `stage3d_stencil` | 0 | 24.0s |  |
| 965 | `stage3d_texture` | 0 | 11.9s |  |
| 966 | `stage3d_texture_bytearray` | 0 | 8.7s |  |
| 967 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.1s |  |
| 968 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.1s |  |
| 969 | `stage3d_triangle` | 0 | 7.7s |  |
| 970 | `stage3d_triangle_bytes4` | 0 | 7.6s |  |
| 971 | `stage3d_triangle_float1` | 0 | 8.0s |  |
| 972 | `stage3d_triangle_index_upload` | 0 | 7.6s |  |
| 973 | `stage3d_x_y` | 22 | 5.8s |  |
| 974 | `stage_access` | 10 | 5.8s |  |
| 975 | `stage_display_state` | 6 | 5.8s |  |
| 976 | `stage_displayobject_properties` | 24 | 5.7s |  |
| 977 | `stage_domain_getQualifiedDefinitionNames` | 5 | 5.9s |  |
| 978 | `stage_framerate_nan` | 7 | 6.0s |  |
| 979 | `stage_framerate_negative` | 6 | 5.7s |  |
| 980 | `stage_framerate_zero` | 6 | 5.7s |  |
| 981 | `stage_invalidate` | 38 | 6.0s |  |
| 982 | `stage_loaderinfo_properties` | 24 | 22.0s |  |
| 983 | `stage_mousechildren` | 2 | 5.7s |  |
| 984 | `stage_mouseenabled` | 15 | 5.7s |  |
| 985 | `stage_overriden_setters` | 31 | 5.8s |  |
| 986 | `stage_properties` | 30 | 5.7s |  |
| 987 | `stage_properties2` | 213 | 5.8s |  |
| 988 | `stage_scale_factor` | 12 | 25.0s |  |
| 989 | `stage_stage3Ds_vector` | 1 | 5.7s |  |
| 990 | `static_length` | 24 | 5.8s |  |
| 991 | `static_text` | 3 | 5.9s |  |
| 992 | `static_var_with_this_in_ctor` | 2 | 5.7s |  |
| 993 | `statictext_text` | 8 | 5.8s |  |
| 994 | `stored_properties` | 11 | 5.8s |  |
| 995 | `strict_equality` | 34 | 5.8s |  |
| 996 | `string_call` | 13 | 5.7s |  |
| 997 | `string_case` | 23 | 5.8s |  |
| 998 | `string_char_at` | 27 | 5.7s |  |
| 999 | `string_char_code_at` | 28 | 5.7s |  |
| 1000 | `string_concat_fromcharcode` | 37 | 39.0s |  |
| 1001 | `string_constr` | 25 | 22.7s |  |
| 1002 | `string_indexof_lastindexof` | 87 | 6.2s |  |
| 1003 | `string_length` | 16 | 5.9s |  |
| 1004 | `string_locale_compare` | 39 | 6.2s |  |
| 1005 | `string_match` | 51 | 6.1s |  |
| 1006 | `string_relational_compare` | 4 | 5.9s |  |
| 1007 | `string_replace` | 51 | 6.1s |  |
| 1008 | `string_search` | 41 | 6.1s |  |
| 1009 | `string_slice_substr_substring` | 170 | 6.7s |  |
| 1010 | `string_split` | 29 | 6.0s |  |
| 1011 | `string_substr_negative` | 21 | 6.0s |  |
| 1012 | `string_substr_weird` | 182 | 5.9s |  |
| 1013 | `stylesheet` | 221 | 6.5s |  |
| 1014 | `stylesheet_parse_color` | 69 | 5.9s |  |
| 1015 | `stylesheet_transform` | 307 | 6.2s |  |
| 1016 | `sub_super_same_field` | 12 | 2.1s |  |
| 1017 | `subclass_superclass_linked_symbol` | 4 | 6.4s |  |
| 1018 | `subtract` | 1058 | 14.2s |  |
| 1019 | `super_get_call` | 12 | 6.0s |  |
| 1020 | `supercall_two_classobjects` | 2 | 6.1s |  |
| 1021 | `supercalls_coerce` | 8 | 6.0s |  |
| 1022 | `supercalls_weird` | 2 | 6.2s |  |
| 1023 | `superinterface_call` | 20 | 6.5s |  |
| 1024 | `superinterface_instanceof` | 18 | 6.1s |  |
| 1025 | `swf8` | 1 | 6.0s |  |
| 1026 | `swf_10_queued_goto_scripts_construct` | 52 | 23.5s |  |
| 1027 | `swf_9_goto_in_enter_frame` | 17 | 6.0s |  |
| 1028 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.0s |  |
| 1029 | `swf_9_queued_goto_scripts` | 6 | 23.0s |  |
| 1030 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 1031 | `swf_9_versioning` | 2 | 5.9s |  |
| 1032 | `swf_wrong_frame_count` | 38 | 6.5s |  |
| 1033 | `swf_wrong_frame_count_isplaying` | 22 | 6.0s |  |
| 1034 | `symbol_class_binary_data` | 8 | 6.1s |  |
| 1035 | `symbol_class_conflict` | 4 | 6.1s |  |
| 1036 | `symbol_class_root_not_zero` | 1 | 5.9s |  |
| 1037 | `symbolclass_invalid_utf8` | 2 | 5.9s |  |
| 1038 | `system_exit` | 3 | 6.0s |  |
| 1039 | `system_setclipboard_null` | 1 | 5.9s |  |
| 1040 | `tab_ordering_arrows` | 998 | 34.6s |  |
| 1041 | `tab_ordering_automatic_advanced` | 184 | 5.3s |  |
| 1042 | `tab_ordering_automatic_basic` | 45 | 20.3s |  |
| 1043 | `tab_ordering_children` | 116 | 5.3s |  |
| 1044 | `tab_ordering_custom_basic` | 34 | 5.3s |  |
| 1045 | `tab_ordering_stage_tab_children` | 32 | 5.3s |  |
| 1046 | `tab_ordering_stage_tab_children_remove_root` | 5 | 5.3s |  |
| 1047 | `tab_ordering_tabbable` | 47 | 5.3s |  |
| 1048 | `tabstop_properties` | 105 | 20.3s |  |
| 1049 | `text_element_basic` | 34 | 5.3s |  |
| 1050 | `text_engine_fontdescription` | 27 | 5.3s |  |
| 1051 | `text_engine_groupelement` | 64 | 5.3s |  |
| 1052 | `text_run` | 7 | 5.3s |  |
| 1053 | `textblock_createline_errors` | 23 | 5.3s |  |
| 1054 | `textblock_createline_fte` | 9 | 20.4s |  |
| 1055 | `textblock_properties` | 118 | 5.3s |  |
| 1056 | `textbox_click` | 37 | 20.6s |  |
| 1057 | `textfield_event` | 66 | 5.6s |  |
| 1058 | `textfield_focusin_event` | 9 | 5.3s |  |
| 1059 | `textfield_input_dead_keys_windows` | 15 | 5.3s |  |
| 1060 | `textfield_input_events` | 25 | 15.6s |  |
| 1061 | `textfield_unload` | 39 | 20.6s |  |
| 1062 | `textformat` | 1134 | 5.3s |  |
| 1063 | `textformat_display` | 14 | 5.3s |  |
| 1064 | `textformat_font_max_length` | 4 | 5.3s |  |
| 1065 | `textline_inapplicable_properties` | 10 | 5.3s |  |
| 1066 | `textline_name` | 1 | 5.3s |  |
| 1067 | `textline_raw_text_length` | 30 | 5.3s |  |
| 1068 | `textline_splitting_basic` | 76 | 5.3s |  |
| 1069 | `textline_throwerror` | 30 | 5.3s |  |
| 1070 | `textline_validity` | 162 | 5.3s |  |
| 1071 | `throw` | 3 | 5.3s |  |
| 1072 | `timeline_scripts` | 3 | 20.5s |  |
| 1073 | `timer` | 90 | 5.5s |  |
| 1074 | `timer_events` | 3 | 5.5s |  |
| 1075 | `timer_finished` | 11 | 5.4s |  |
| 1076 | `timer_invalid_delay` | 30 | 5.3s |  |
| 1077 | `timer_reset` | 8 | 44.5s |  |
| 1078 | `timer_setdelay` | 5 | 26.4s |  |
| 1079 | `trace` | 12 | 7.3s |  |
| 1080 | `truthiness` | 30 | 7.2s |  |
| 1081 | `try_catch` | 11 | 7.2s |  |
| 1082 | `try_catch_typed` | 12 | 7.2s |  |
| 1083 | `typeof` | 30 | 7.2s |  |
| 1084 | `uint_constr` | 92 | 7.3s |  |
| 1085 | `uint_tofixed` | 1215 | 7.0s |  |
| 1086 | `uint_toprecision` | 1125 | 7.3s |  |
| 1087 | `uint_tostring` | 3375 | 7.4s |  |
| 1088 | `uncaught_error_basic` | 2 | 7.1s |  |
| 1089 | `unchecked_function` | 15 | 7.1s |  |
| 1090 | `unescape` | 28 | 7.1s |  |
| 1091 | `url_loader` | 25 | 7.2s |  |
| 1092 | `url_vars` | 27 | 7.2s |  |
| 1093 | `urlrequest` | 18 | 7.2s |  |
| 1094 | `urlstream_basic` | 5 | 7.1s |  |
| 1095 | `urshift` | 1058 | 19.2s |  |
| 1096 | `utils3d` | 7 | 7.1s |  |
| 1097 | `vector3d` | 397 | 12.0s |  |
| 1098 | `vector3d_near_equals` | 80 | 7.2s |  |
| 1099 | `vector_class` | 36 | 7.5s |  |
| 1100 | `vector_class_call` | 11 | 7.3s |  |
| 1101 | `vector_coercion` | 66 | 7.9s |  |
| 1102 | `vector_concat` | 90 | 7.7s |  |
| 1103 | `vector_constr` | 107 | 7.8s |  |
| 1104 | `vector_enumeration` | 5 | 7.1s |  |
| 1105 | `vector_every` | 92 | 8.0s |  |
| 1106 | `vector_filter` | 95 | 8.0s |  |
| 1107 | `vector_holes` | 24 | 7.3s |  |
| 1108 | `vector_indexof` | 302 | 12.0s |  |
| 1109 | `vector_insertat` | 270 | 8.3s |  |
| 1110 | `vector_int_access` | 4 | 7.1s |  |
| 1111 | `vector_int_delete` | 11 | 7.2s |  |
| 1112 | `vector_join` | 58 | 7.7s |  |
| 1113 | `vector_lastindexof` | 302 | 7.2s |  |
| 1114 | `vector_legacy` | 10 | 7.2s |  |
| 1115 | `vector_map` | 85 | 8.0s |  |
| 1116 | `vector_object_final` | 1 | 7.0s |  |
| 1117 | `vector_object_toString` | 10 | 45.4s |  |
| 1118 | `vector_pushpop` | 255 | 28.0s |  |
| 1119 | `vector_reborrow_bug` | 10 | 7.4s |  |
| 1120 | `vector_removeat` | 172 | 8.5s |  |
| 1121 | `vector_reverse` | 232 | 8.4s |  |
| 1122 | `vector_shiftunshift` | 252 | 7.3s |  |
| 1123 | `vector_slice` | 331 | 8.9s |  |
| 1124 | `vector_sort` | 905 | 16.1s |  |
| 1125 | `vector_splice` | 693 | 11.1s |  |
| 1126 | `vector_splice_fixed_bug_compat` | 4 | 7.5s |  |
| 1127 | `vector_tostring` | 79 | 8.0s |  |
| 1128 | `verification` | 8 | 7.6s |  |
| 1129 | `verify_abnormal_loop` | 1 | 7.4s |  |
| 1130 | `verify_dxns_without_flag` | 3 | 7.8s |  |
| 1131 | `verify_exception_target_two_jumps` | 1 | 7.3s |  |
| 1132 | `verify_exception_targets_edge_case` | 1 | 7.4s |  |
| 1133 | `verify_illegal_opcode` | 1 | 2.9s |  |
| 1134 | `verify_jump_to_middle_of_op` | 1 | 7.4s |  |
| 1135 | `verify_lookup_switch_edge_case` | 1 | 7.3s |  |
| 1136 | `verify_method_info_oob` | 1 | 0.6s |  |
| 1137 | `verify_stack` | 5 | 7.4s |  |
| 1138 | `verify_typecheck` | 4 | 7.4s |  |
| 1139 | `verify_unreachable_exception` | 2 | 7.3s |  |
| 1140 | `versioned_isplaying` | 2 | 7.4s |  |
| 1141 | `virtual_properties` | 16 | 7.5s |  |
| 1142 | `with` | 4 | 7.4s |  |
| 1143 | `wrong_arg_count` | 7 | 7.5s |  |
| 1144 | `xml_abstract_equality` | 36 | 7.6s |  |
| 1145 | `xml_advanced` | 52 | 7.4s |  |
| 1146 | `xml_appendchild` | 10 | 7.4s |  |
| 1147 | `xml_appendchild_swf_v21` | 13 | 7.6s |  |
| 1148 | `xml_as_attribute` | 9 | 7.3s |  |
| 1149 | `xml_attribute` | 35 | 7.5s |  |
| 1150 | `xml_attribute_name` | 40 | 7.4s |  |
| 1151 | `xml_basic` | 33 | 7.5s |  |
| 1152 | `xml_child` | 25 | 7.4s |  |
| 1153 | `xml_childindex` | 7 | 7.3s |  |
| 1154 | `xml_children` | 43 | 7.9s |  |
| 1155 | `xml_class_call` | 9 | 7.3s |  |
| 1156 | `xml_contains` | 197 | 7.5s |  |
| 1157 | `xml_copy` | 20 | 44.8s |  |
| 1158 | `xml_ctor_from_tostring` | 23 | 27.0s |  |
| 1159 | `xml_delete` | 114 | 7.3s |  |
| 1160 | `xml_descendants` | 83 | 7.3s |  |
| 1161 | `xml_duplicate_attribute` | 14 | 7.2s |  |
| 1162 | `xml_elements` | 6 | 7.2s |  |
| 1163 | `xml_equals_namespace_check` | 2 | 7.2s |  |
| 1164 | `xml_explicit_use_namespace` | 5 | 7.3s |  |
| 1165 | `xml_getdescendants_qname` | 21 | 7.3s |  |
| 1166 | `xml_has_property_via_in` | 26 | 7.2s |  |
| 1167 | `xml_hasownproperty` | 6 | 7.2s |  |
| 1168 | `xml_ignore_white` | 6 | 7.2s |  |
| 1169 | `xml_length` | 2 | 7.2s |  |
| 1170 | `xml_list_as_attribute` | 9 | 7.2s |  |
| 1171 | `xml_list_concat` | 20 | 7.2s |  |
| 1172 | `xml_list_ctor_errors` | 34 | 7.2s |  |
| 1173 | `xml_list_delete_clear_parent` | 6 | 7.2s |  |
| 1174 | `xml_list_enumerate` | 4 | 7.2s |  |
| 1175 | `xml_methods_settings` | 3 | 7.2s |  |
| 1176 | `xml_mismatched_tag` | 37 | 7.2s |  |
| 1177 | `xml_namespace` | 39 | 7.2s |  |
| 1178 | `xml_namespace_methods` | 245 | 7.3s |  |
| 1179 | `xml_namespaced_property` | 7 | 7.2s |  |
| 1180 | `xml_no_namespace` | 1 | 7.2s |  |
| 1181 | `xml_nodekind` | 3 | 7.2s |  |
| 1182 | `xml_normalize` | 35 | 7.3s |  |
| 1183 | `xml_notification_bubbling` | 361 | 7.2s |  |
| 1184 | `xml_parent` | 8 | 7.2s |  |
| 1185 | `xml_set_children` | 17 | 7.3s |  |
| 1186 | `xml_set_name` | 34 | 7.2s |  |
| 1187 | `xml_settings` | 6 | 2.4s |  |
| 1188 | `xml_simple_complex_content` | 47 | 7.2s |  |
| 1189 | `xml_socket` | 11 | 7.5s |  |
| 1190 | `xml_text` | 7 | 7.2s |  |
| 1191 | `xml_tostring` | 6 | 7.3s |  |
| 1192 | `xml_tostring_namespace` | 12 | 6.9s |  |
| 1193 | `xml_unescaping` | 23 | 7.2s |  |
| 1194 | `xml_weird_ignores` | 54 | 7.2s |  |
| 1195 | `xml_wildcard` | 11 | 7.2s |  |
| 1196 | `xmldocument` | 254 | 7.2s |  |
| 1197 | `xmlnode` | 3540 | 7.3s |  |
| 1198 | `zero_frame_clip` | 3 | 7.4s |  |

## Ruffle-Matched Tests

**36 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 6.6s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.3s |  |
| 3 | `bitmapdata_copypixels_alpha_merge` | 4 | 4 | 7.4s |  |
| 4 | `blend_transform` | 1 | 1 | 7.4s |  |
| 5 | `bounds_mode` | 6 | 6 | 6.1s |  |
| 6 | `coerce_property` | 3 | 3 | 7.4s |  |
| 7 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.3s |  |
| 8 | `dictionary_weak_keys` | 1 | 1 | 27.8s |  |
| 9 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 23.6s |  |
| 10 | `edittext_device_transform_layout` | 20 | 20 | 7.4s |  |
| 11 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.4s |  |
| 12 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 7.2s |  |
| 13 | `edittext_tab_stops` | 6 | 6 | 7.5s |  |
| 14 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.2s |  |
| 15 | `error_1034_debug_string` | 19 | 19 | 6.4s |  |
| 16 | `event_handler_exception` | 4 | 4 | 6.4s |  |
| 17 | `freestanding_superclass` | 2 | 4 | 7.3s |  |
| 18 | `goto_framescript_queued` | 5 | 5 | 26.6s |  |
| 19 | `graphics_draw_path` | 50 | 50 | 27.1s |  |
| 20 | `groupelement_text` | 2 | 2 | 7.3s |  |
| 21 | `int_toexponential` | 76 | 76 | 7.8s |  |
| 22 | `matrix3d_append_rotation` | 1 | 3 | 7.4s |  |
| 23 | `matrix3d_recompose_edge_cases` | 85 | 85 | 7.8s |  |
| 24 | `number_convert_errors` | 706 | 706 | 7.4s |  |
| 25 | `simplebutton_childevents_script_order` | 4 | 4 | 7.6s |  |
| 26 | `slot_holes_fail` | 1 | 1 | 7.3s |  |
| 27 | `slot_id_exceeds_trait_count` | 1 | 1 | 38.9s |  |
| 28 | `soundchannel_position` | 74 | 74 | 23.8s |  |
| 29 | `soundchannel_soundcomplete` | 10 | 10 | 6.2s |  |
| 30 | `sprite_dropTarget` | 15 | 15 | 6.1s |  |
| 31 | `swf_9_goto_in_construct_frame` | 12 | 12 | 23.2s |  |
| 32 | `textblock_line_changes` | 44 | 44 | 5.3s |  |
| 33 | `textblock_releaselines` | 4 | 4 | 5.3s |  |
| 34 | `uint_toexponential` | 100 | 100 | 7.3s |  |
| 35 | `uncaught_errors_stringified` | 15 | 15 | 7.3s |  |
| 36 | `weird_superinterface_properties` | 1 | 1 | 7.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 3 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 4 | `displayobject_getrect` | 68.8% | 11 | 16 | 5 |  |
| 5 | `number_to_string` | 67.1% | 237 | 353 | 116 |  |
| 6 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 7 | `loader_duplicate_class` | 66.7% | 32 | 48 | 16 |  |
| 8 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 9 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 10 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**27 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 3 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 4 | `displayobject_getrect` | 68.8% | 11/16 | 16 | 16 |  |
| 5 | `number_to_string` | 67.1% | 237/353 | 353 | 353 |  |
| 6 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 7 | `loader_duplicate_class` | 66.7% | 32/48 | 48 | 48 |  |
| 8 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 9 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 10 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 11 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 12 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 13 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 14 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 15 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 16 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 17 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 18 | `loader_events_2` | 5.7% | 2/35 | 31 | 35 |  |
| 19 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 20 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 21 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 22 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 23 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 24 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 25 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 26 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 27 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
