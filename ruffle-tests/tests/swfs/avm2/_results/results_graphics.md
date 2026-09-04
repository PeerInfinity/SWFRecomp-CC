# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 04:04 UTC

**Git SHA**: `82f27e5f90`

**Run Duration**: 235m 7s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1261 |
| Passing | **1180** (93.6%) |
| Ruffle-matched | 33 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1213** (96.2%) |
| Failing | 48 |
| Total expected lines | 155033 |
| Matching lines | 151410 (97.7%) |
| Mismatched lines | 3623 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 48 | 100.0% |

## Passing Tests

**1180 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 20.8s |  |
| 2 | `accessibility` | 1 | 5.5s |  |
| 3 | `accessibilityimplementation` | 18 | 19.7s |  |
| 4 | `activation_class` | 6 | 6.1s |  |
| 5 | `add` | 1058 | 13.2s |  |
| 6 | `agal_compiler` | 13 | 7.4s |  |
| 7 | `air_datagram_socket` | 1 | 7.4s |  |
| 8 | `air_hidden_lookup` | 2 | 5.5s |  |
| 9 | `air_ifilepromise` | 1 | 5.5s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 5.6s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.9s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.9s |  |
| 13 | `all_classes/display/swf10` | 2569 | 5.8s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.9s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.8s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.9s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.8s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.8s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 5.6s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.8s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.9s |  |
| 22 | `all_classes/errors/swf10` | 140 | 5.8s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.8s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.8s |  |
| 25 | `all_classes/events/swf10` | 1638 | 5.7s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.9s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.9s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.9s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.8s |  |
| 30 | `all_classes/security/swf11` | 3 | 5.5s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.8s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.8s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.8s |  |
| 34 | `all_classes/xml/swf30` | 116 | 5.5s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.9s |  |
| 36 | `amf_array_serialization` | 17 | 21.4s |  |
| 37 | `amf_custom_obj` | 26 | 5.6s |  |
| 38 | `amf_dictionary` | 9 | 5.8s |  |
| 39 | `amf_function` | 46 | 5.7s |  |
| 40 | `amf_invalid_date` | 2 | 5.7s |  |
| 41 | `amf_missing_prop` | 6 | 5.5s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 5.6s |  |
| 43 | `amf_setter_error` | 8 | 5.5s |  |
| 44 | `amf_vector` | 40 | 28.5s |  |
| 45 | `amf_xml` | 6 | 8.2s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 8.6s |  |
| 47 | `application_domain` | 4 | 8.2s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 27.5s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 8.1s |  |
| 50 | `array_access` | 18 | 8.3s |  |
| 51 | `array_access_interpreter` | 4 | 8.2s |  |
| 52 | `array_access_no_pubns` | 2 | 8.1s |  |
| 53 | `array_concat` | 41 | 8.2s |  |
| 54 | `array_constr` | 10 | 8.1s |  |
| 55 | `array_delete` | 44 | 8.2s |  |
| 56 | `array_enumeration` | 10 | 8.2s |  |
| 57 | `array_enumeration_elements` | 11 | 8.2s |  |
| 58 | `array_every` | 8 | 8.2s |  |
| 59 | `array_filter` | 6 | 8.2s |  |
| 60 | `array_foreach` | 18 | 8.2s |  |
| 61 | `array_hasownproperty` | 11 | 8.1s |  |
| 62 | `array_holes` | 9 | 8.1s |  |
| 63 | `array_index_max` | 84 | 8.0s |  |
| 64 | `array_indexof` | 25 | 8.2s |  |
| 65 | `array_join` | 26 | 8.2s |  |
| 66 | `array_lastindexof` | 29 | 8.2s |  |
| 67 | `array_length` | 14 | 8.1s |  |
| 68 | `array_literal` | 3 | 8.0s |  |
| 69 | `array_map` | 8 | 7.9s |  |
| 70 | `array_pop` | 52 | 8.2s |  |
| 71 | `array_push` | 24 | 8.1s |  |
| 72 | `array_reborrow_bug` | 6 | 8.0s |  |
| 73 | `array_reverse` | 28 | 8.1s |  |
| 74 | `array_shift` | 51 | 3.2s |  |
| 75 | `array_slice` | 39 | 8.2s |  |
| 76 | `array_some` | 8 | 8.1s |  |
| 77 | `array_sort` | 297 | 8.5s |  |
| 78 | `array_sort_fun_swf12` | 2 | 8.1s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 80 | `array_sort_random` | 210 | 8.1s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 8.1s |  |
| 82 | `array_sorton` | 545 | 8.9s |  |
| 83 | `array_sparse_ops` | 41 | 8.2s |  |
| 84 | `array_splice` | 133 | 29.3s |  |
| 85 | `array_splice2` | 428 | 28.2s |  |
| 86 | `array_splice_types` | 48 | 8.4s |  |
| 87 | `array_storage` | 8 | 8.3s |  |
| 88 | `array_tolocalestring` | 9 | 8.3s |  |
| 89 | `array_tostring` | 12 | 8.3s |  |
| 90 | `array_unshift` | 24 | 8.3s |  |
| 91 | `array_valueof` | 9 | 8.2s |  |
| 92 | `array_vector_null_callback` | 10 | 8.3s |  |
| 93 | `astype` | 28 | 8.4s |  |
| 94 | `astypelate` | 24 | 8.4s |  |
| 95 | `astypelate_propagates` | 1 | 8.2s |  |
| 96 | `asymmetric_key_events` | 11 | 8.5s |  |
| 97 | `automation_classes` | 122 | 8.8s |  |
| 98 | `av_classes` | 340 | 8.8s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 8.4s |  |
| 100 | `avm2_catchup_dobj` | 158 | 9.2s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 96.1s |  |
| 102 | `bevel_filter` | 187 | 8.6s |  |
| 103 | `bitand` | 1058 | 20.6s |  |
| 104 | `bitmap_constr` | 17 | 8.4s |  |
| 105 | `bitmap_data` | 1000 | 16.7s |  |
| 106 | `bitmap_pixelsnapping` | 2 | 28.6s |  |
| 107 | `bitmap_properties` | 23 | 8.4s |  |
| 108 | `bitmap_subclass` | 7 | 9.8s |  |
| 109 | `bitmap_subclass_properties` | 9 | 8.9s |  |
| 110 | `bitmap_timeline` | 9 | 8.6s |  |
| 111 | `bitmapdata_accuracy` | 1 | 46.1s |  |
| 112 | `bitmapdata_applyfilter_blur` | 0 | 28.4s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.1s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | 0 | 28.4s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 28.7s |  |
| 116 | `bitmapdata_clone` | 13 | 8.5s |  |
| 117 | `bitmapdata_colortransform` | 0 | 8.7s |  |
| 118 | `bitmapdata_colortransform_oob` | 2 | 8.2s |  |
| 119 | `bitmapdata_constr` | 22 | 8.3s |  |
| 120 | `bitmapdata_constructor_from_timeline` | 1 | 8.6s |  |
| 121 | `bitmapdata_copychannel` | 0 | 29.4s |  |
| 122 | `bitmapdata_copypixels` | 23 | 28.9s |  |
| 123 | `bitmapdata_copypixels_blend_over` | 1 | 8.5s |  |
| 124 | `bitmapdata_copypixelstobytearray` | 39 | 8.4s |  |
| 125 | `bitmapdata_dispose` | 7 | 8.5s |  |
| 126 | `bitmapdata_draw` | 0 | 29.5s |  |
| 127 | `bitmapdata_draw_alpha_erase` | 8 | 8.7s |  |
| 128 | `bitmapdata_draw_colortransform` | 0 | 28.1s |  |
| 129 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 28.1s |  |
| 130 | `bitmapdata_draw_filters` | 0 | 28.1s |  |
| 131 | `bitmapdata_draw_masks` | 0 | 8.8s |  |
| 132 | `bitmapdata_draw_rotation` | 0 | 8.7s |  |
| 133 | `bitmapdata_draw_self_via_graphic` | 0 | 8.7s |  |
| 134 | `bitmapdata_draw_stage` | 0 | 27.8s |  |
| 135 | `bitmapdata_drawwithquality` | 0 | 9.0s |  |
| 136 | `bitmapdata_embedded` | 9 | 8.8s |  |
| 137 | `bitmapdata_fillrect` | 0 | 8.7s |  |
| 138 | `bitmapdata_filter_sourcerect` | 0 | 28.3s |  |
| 139 | `bitmapdata_floodfill` | 35 | 8.4s |  |
| 140 | `bitmapdata_getpixels` | 39 | 28.0s |  |
| 141 | `bitmapdata_getvector` | 27 | 3.4s |  |
| 142 | `bitmapdata_histogram` | 59 | 3.4s |  |
| 143 | `bitmapdata_hittest` | 112 | 9.0s |  |
| 144 | `bitmapdata_hittest_threshold` | 18 | 8.5s |  |
| 145 | `bitmapdata_opaque` | 0 | 8.6s |  |
| 146 | `bitmapdata_pixeldissolve` | 1037 | 9.1s |  |
| 147 | `bitmapdata_pixeldissolve_image` | 0 | 8.8s |  |
| 148 | `bitmapdata_rectangle_rounding` | 16 | 8.4s |  |
| 149 | `bitmapdata_setpixels` | 286 | 8.6s |  |
| 150 | `bitmapdata_setvector` | 26 | 8.7s |  |
| 151 | `bitmapdata_sync` | 0 | 28.1s |  |
| 152 | `bitmapdata_threshold` | 176 | 9.2s |  |
| 153 | `bitmapdata_zero_size` | 8 | 8.4s |  |
| 154 | `bitnot` | 46 | 8.5s |  |
| 155 | `bitor` | 1058 | 19.8s |  |
| 156 | `bitxor` | 1058 | 19.8s |  |
| 157 | `blend_mode_null` | 1 | 8.4s |  |
| 158 | `blend_multiply_alpha` | 0 | 8.6s |  |
| 159 | `blend_scroll` | 0 | 8.7s |  |
| 160 | `blend_shader_luma_lighten` | 3 | 9.2s |  |
| 161 | `blur_filter` | 43 | 8.7s |  |
| 162 | `boolean_constr` | 32 | 8.5s |  |
| 163 | `boolean_negation` | 30 | 8.4s |  |
| 164 | `boolean_tostring` | 8 | 8.5s |  |
| 165 | `broadcast_event` | 7 | 8.3s |  |
| 166 | `button_bounds` | 1 | 8.5s |  |
| 167 | `button_hittest` | 2 | 28.3s |  |
| 168 | `button_nested_frame` | 48 | 28.6s |  |
| 169 | `button_nested_frame_simple` | 27 | 8.7s |  |
| 170 | `bytearray` | 48 | 8.7s |  |
| 171 | `bytearray_compress` | 31 | 8.4s |  |
| 172 | `bytearray_errors` | 24 | 8.5s |  |
| 173 | `bytearray_method_serialization` | 1 | 8.4s |  |
| 174 | `bytearray_oom` | 3 | 8.4s |  |
| 175 | `bytearray_readobject_amf0` | 50 | 8.4s |  |
| 176 | `bytearray_readobject_amf3` | 53 | 8.4s |  |
| 177 | `bytearray_readutf8bytes_with_bom` | 16 | 8.5s |  |
| 178 | `bytearray_serialization` | 3 | 8.4s |  |
| 179 | `bytearray_string_null` | 19 | 8.7s |  |
| 180 | `bytearray_tostring` | 15 | 8.4s |  |
| 181 | `bytearray_utf16` | 8 | 8.4s |  |
| 182 | `bytearray_writeobject` | 24 | 8.3s |  |
| 183 | `callee_in_initializer` | 6 | 8.3s |  |
| 184 | `callproplex_class` | 1 | 8.4s |  |
| 185 | `capabilities_resolution` | 8 | 29.8s |  |
| 186 | `catch_class` | 6 | 8.3s |  |
| 187 | `catch_scope_slot` | 7 | 8.6s |  |
| 188 | `checkfilter` | 4 | 3.4s |  |
| 189 | `class_call` | 32 | 8.6s |  |
| 190 | `class_cast_call` | 14 | 8.5s |  |
| 191 | `class_enumeration` | 4 | 8.4s |  |
| 192 | `class_has_own_property` | 2 | 8.4s |  |
| 193 | `class_init_interpreter_mode` | 1 | 8.4s |  |
| 194 | `class_is` | 32 | 8.5s |  |
| 195 | `class_methods` | 5 | 8.4s |  |
| 196 | `class_object_properties` | 10 | 8.5s |  |
| 197 | `class_singleton` | 18 | 8.5s |  |
| 198 | `class_supercalls_errors` | 35 | 8.7s |  |
| 199 | `class_supercalls_mismatched` | 26 | 8.6s |  |
| 200 | `class_superclass_wrong_order` | 1 | 8.3s |  |
| 201 | `class_to_locale_string` | 2 | 8.3s |  |
| 202 | `class_to_string` | 2 | 8.6s |  |
| 203 | `class_value_of` | 2 | 8.5s |  |
| 204 | `click_block` | 5 | 29.8s |  |
| 205 | `click_invisible` | 3 | 8.5s |  |
| 206 | `closures` | 12 | 8.4s |  |
| 207 | `coerce_return_type` | 40 | 8.6s |  |
| 208 | `coerce_return_type_fail` | 2 | 8.3s |  |
| 209 | `coerce_return_void` | 3 | 8.3s |  |
| 210 | `coerce_string` | 86 | 8.6s |  |
| 211 | `coerce_string_precision` | 28 | 8.6s |  |
| 212 | `coerce_to_primitive_side_effects` | 29 | 28.6s |  |
| 213 | `color_matrix_filter` | 19 | 8.7s |  |
| 214 | `construct_errors_swf10` | 8 | 8.4s |  |
| 215 | `construct_frame_list` | 22 | 28.9s |  |
| 216 | `construct_interface` | 3 | 8.6s |  |
| 217 | `constructor_call` | 3 | 8.7s |  |
| 218 | `constructors_vs_timeline` | 5 | 29.6s |  |
| 219 | `constructprop_dynamic_primitive` | 7 | 8.7s |  |
| 220 | `constructprop_method` | 2 | 8.7s |  |
| 221 | `constructsuper_null` | 2 | 8.6s |  |
| 222 | `content_element_basic` | 50 | 9.0s |  |
| 223 | `context3d_creation` | 9 | 8.7s |  |
| 224 | `control_flow_bool` | 4 | 8.5s |  |
| 225 | `control_flow_stricteq` | 8 | 8.3s |  |
| 226 | `convert_boolean` | 30 | 8.3s |  |
| 227 | `convert_integer` | 90 | 8.3s |  |
| 228 | `convert_number` | 56 | 8.3s |  |
| 229 | `convert_uinteger` | 90 | 8.4s |  |
| 230 | `convolution_filter` | 89 | 8.4s |  |
| 231 | `core_exceptions` | 47 | 9.2s |  |
| 232 | `cpool_index_invalid_bytecode_1` | 6 | 8.3s |  |
| 233 | `cpool_index_invalid_bytecode_2` | 3 | 8.2s |  |
| 234 | `cpool_index_invalid_bytecode_3` | 1 | 8.1s |  |
| 235 | `cross_api_version_call_newer` | 12 | 8.9s |  |
| 236 | `cross_api_version_call_older` | 12 | 8.6s |  |
| 237 | `cryptscore` | 11 | 8.3s |  |
| 238 | `currency_parse_result` | 7 | 8.2s |  |
| 239 | `date` | 30 | 8.6s |  |
| 240 | `date_parse` | 36 | 8.3s |  |
| 241 | `declocal` | 46 | 7.5s |  |
| 242 | `declocal_i` | 46 | 8.8s |  |
| 243 | `decode_uri` | 71 | 8.9s |  |
| 244 | `decrement` | 46 | 8.6s |  |
| 245 | `decrement_i` | 46 | 3.4s |  |
| 246 | `default_values` | 7 | 8.5s |  |
| 247 | `delayed_symbolclass` | 28 | 28.7s |  |
| 248 | `describe_type_basic` | 152 | 8.8s |  |
| 249 | `describe_type_json` | 301 | 8.7s |  |
| 250 | `describe_type_metadata` | 125 | 8.6s |  |
| 251 | `describe_type_native` | 23 | 8.6s |  |
| 252 | `dictionary_access` | 62 | 8.8s |  |
| 253 | `dictionary_access_no_pubns` | 2 | 8.4s |  |
| 254 | `dictionary_delete` | 101 | 8.9s |  |
| 255 | `dictionary_foreach` | 42 | 8.7s |  |
| 256 | `dictionary_hasownproperty` | 63 | 8.7s |  |
| 257 | `dictionary_in` | 62 | 8.8s |  |
| 258 | `dictionary_iter_modify` | 8 | 8.5s |  |
| 259 | `dictionary_namespaces` | 36 | 8.6s |  |
| 260 | `displacement_map_filter` | 61 | 8.6s |  |
| 261 | `displayobject_alpha` | 277 | 8.3s |  |
| 262 | `displayobject_blendmode` | 0 | 10.0s |  |
| 263 | `displayobject_colortransform_nested` | 0 | 28.5s |  |
| 264 | `displayobject_early_init` | 54 | 10.4s |  |
| 265 | `displayobject_filters` | 17 | 8.6s |  |
| 266 | `displayobject_from_enterframe` | 1 | 28.6s |  |
| 267 | `displayobject_getbounds_shape` | 0 | 28.2s |  |
| 268 | `displayobject_height` | 6052 | 28.5s |  |
| 269 | `displayobject_hittestobject` | 32 | 8.7s |  |
| 270 | `displayobject_hittestpoint` | 49 | 8.6s |  |
| 271 | `displayobject_hittestpoint_boundary` | 65 | 28.5s |  |
| 272 | `displayobject_hittestpoint_root` | 13 | 8.8s |  |
| 273 | `displayobject_invalid_floats` | 60 | 8.5s |  |
| 274 | `displayobject_invalid_props` | 3 | 8.4s |  |
| 275 | `displayobject_mask` | 3 | 9.1s |  |
| 276 | `displayobject_mask_self_referential` | 0 | 8.4s |  |
| 277 | `displayobject_metaData` | 3 | 8.4s |  |
| 278 | `displayobject_name` | 22 | 27.9s |  |
| 279 | `displayobject_name_from_timeline` | 24 | 8.6s |  |
| 280 | `displayobject_opaque_background` | 6 | 8.5s |  |
| 281 | `displayobject_parent` | 12 | 28.8s |  |
| 282 | `displayobject_root` | 24 | 8.3s |  |
| 283 | `displayobject_rotation` | 1284 | 8.4s |  |
| 284 | `displayobject_scrollrect` | 33 | 10.7s |  |
| 285 | `displayobject_set_matrix_nested` | 0 | 28.0s |  |
| 286 | `displayobject_set_name_loaded` | 3 | 8.6s |  |
| 287 | `displayobject_subclass` | 2 | 8.2s |  |
| 288 | `displayobject_transform` | 89 | 27.8s |  |
| 289 | `displayobject_visible` | 23 | 8.3s |  |
| 290 | `displayobject_width` | 4852 | 28.3s |  |
| 291 | `displayobject_x` | 614 | 8.3s |  |
| 292 | `displayobject_y` | 617 | 8.3s |  |
| 293 | `displayobjectcontainer_addchild` | 32 | 8.5s |  |
| 294 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 8.3s |  |
| 295 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.5s |  |
| 296 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 8.6s |  |
| 297 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 8.6s |  |
| 298 | `displayobjectcontainer_addchildat` | 42 | 8.6s |  |
| 299 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 8.5s |  |
| 300 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 8.5s |  |
| 301 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.5s |  |
| 302 | `displayobjectcontainer_contains` | 66 | 28.1s |  |
| 303 | `displayobjectcontainer_getchildat` | 4 | 8.4s |  |
| 304 | `displayobjectcontainer_getchildbyname` | 9 | 8.4s |  |
| 305 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 8.5s |  |
| 306 | `displayobjectcontainer_getchildindex` | 28 | 8.5s |  |
| 307 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 28.9s |  |
| 308 | `displayobjectcontainer_removechild` | 10 | 8.3s |  |
| 309 | `displayobjectcontainer_removechild_errors` | 4 | 8.4s |  |
| 310 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 8.5s |  |
| 311 | `displayobjectcontainer_removechildat` | 18 | 8.3s |  |
| 312 | `displayobjectcontainer_removechildren` | 51 | 8.7s |  |
| 313 | `displayobjectcontainer_setchildindex` | 42 | 8.3s |  |
| 314 | `displayobjectcontainer_stopallmovieclips` | 2 | 28.2s |  |
| 315 | `displayobjectcontainer_swapchildren` | 42 | 8.2s |  |
| 316 | `displayobjectcontainer_swapchildrenat` | 42 | 8.2s |  |
| 317 | `displayobjectcontainer_timelineinstance` | 48 | 27.6s |  |
| 318 | `divide` | 1058 | 20.1s |  |
| 319 | `doabc_and_symbolclass_script_init_goto` | 7 | 27.5s |  |
| 320 | `doabc_and_symbolclass_script_init_normal` | 6 | 8.1s |  |
| 321 | `doabc_is_eager` | 1 | 27.2s |  |
| 322 | `documentclass` | 9 | 8.8s |  |
| 323 | `domain_memory` | 133 | 29.1s |  |
| 324 | `drag_drop` | 10 | 8.8s |  |
| 325 | `drop_shadow_filter` | 172 | 8.9s |  |
| 326 | `duplicate_defs` | 1 | 8.4s |  |
| 327 | `eager_init` | 1 | 8.4s |  |
| 328 | `east_asian_justifier_clone` | 8 | 8.5s |  |
| 329 | `edit_text_linkage` | 7 | 8.7s |  |
| 330 | `edittext_align` | 60 | 9.1s |  |
| 331 | `edittext_always_show_selection` | 0 | 29.9s |  |
| 332 | `edittext_antialiastype` | 296 | 8.8s |  |
| 333 | `edittext_at_point_methods_basic` | 16 | 9.8s |  |
| 334 | `edittext_autosize` | 39 | 8.9s |  |
| 335 | `edittext_autosize_align` | 0 | 28.7s |  |
| 336 | `edittext_autosize_height_dynamic` | 60 | 29.3s |  |
| 337 | `edittext_autosize_height_input` | 60 | 9.0s |  |
| 338 | `edittext_autosize_lazy_bounds_events` | 65 | 9.2s |  |
| 339 | `edittext_autosize_lazy_bounds_interactions` | 19 | 8.8s |  |
| 340 | `edittext_autosize_lazy_bounds_props` | 490 | 10.2s |  |
| 341 | `edittext_autosize_lazy_bounds_visual` | 0 | 28.9s |  |
| 342 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 9.0s |  |
| 343 | `edittext_bottom_scroll_v_basic` | 210 | 8.9s |  |
| 344 | `edittext_bounds_scale` | 24 | 28.7s |  |
| 345 | `edittext_bullet` | 30 | 9.0s |  |
| 346 | `edittext_default_format` | 221 | 9.3s |  |
| 347 | `edittext_default_format_empty` | 136 | 9.1s |  |
| 348 | `edittext_empty_text_format` | 7 | 8.8s |  |
| 349 | `edittext_focus_selection` | 5 | 8.8s |  |
| 350 | `edittext_font_size` | 45 | 8.9s |  |
| 351 | `edittext_format_empty_font` | 8 | 8.8s |  |
| 352 | `edittext_get_char_index_at_point` | 4 | 31.7s |  |
| 353 | `edittext_get_line_index_at_point` | 2 | 29.1s |  |
| 354 | `edittext_get_line_index_of_char` | 76 | 9.6s |  |
| 355 | `edittext_getcharboundaries` | 172 | 9.1s |  |
| 356 | `edittext_getcharboundaries_missing_glyphs` | 63 | 8.6s |  |
| 357 | `edittext_getcharboundaries_scroll` | 85 | 8.6s |  |
| 358 | `edittext_getlinemetrics` | 146 | 8.9s |  |
| 359 | `edittext_html` | 3101 | 9.1s |  |
| 360 | `edittext_html_condensewhite` | 487 | 8.6s |  |
| 361 | `edittext_html_entity` | 4 | 8.6s |  |
| 362 | `edittext_html_font_size_swf12` | 267 | 27.3s |  |
| 363 | `edittext_html_font_size_swf13` | 273 | 7.9s |  |
| 364 | `edittext_html_roundtrip` | 17 | 8.2s |  |
| 365 | `edittext_ime_focus_lost` | 9 | 27.4s |  |
| 366 | `edittext_input_control` | 12 | 8.2s |  |
| 367 | `edittext_leading` | 9 | 8.7s |  |
| 368 | `edittext_letter_spacing` | 15 | 8.4s |  |
| 369 | `edittext_line_methods` | 294 | 9.7s |  |
| 370 | `edittext_line_metrics` | 11 | 28.6s |  |
| 371 | `edittext_margins` | 25 | 8.5s |  |
| 372 | `edittext_max_scroll_h_basic` | 475 | 8.6s |  |
| 373 | `edittext_max_scroll_v_basic` | 1000 | 8.3s |  |
| 374 | `edittext_mouse_selection` | 363 | 28.3s |  |
| 375 | `edittext_mousedown` | 3 | 8.5s |  |
| 376 | `edittext_mouseenabled` | 26 | 8.1s |  |
| 377 | `edittext_newline_character` | 22 | 8.1s |  |
| 378 | `edittext_newline_stripping` | 64 | 11.0s |  |
| 379 | `edittext_newlines` | 30 | 8.2s |  |
| 380 | `edittext_paragraph_methods` | 257 | 8.1s |  |
| 381 | `edittext_paste_events` | 8 | 8.1s |  |
| 382 | `edittext_paste_maxchars` | 4 | 8.1s |  |
| 383 | `edittext_paste_restrict` | 16 | 8.0s |  |
| 384 | `edittext_restrict` | 191 | 8.2s |  |
| 385 | `edittext_restrict_events` | 22 | 8.1s |  |
| 386 | `edittext_scrollh` | 10 | 8.1s |  |
| 387 | `edittext_selected_text` | 9 | 8.1s |  |
| 388 | `edittext_set_html_same` | 17 | 8.2s |  |
| 389 | `edittext_set_text_vs_html` | 9 | 8.2s |  |
| 390 | `edittext_stylesheet` | 536 | 8.6s |  |
| 391 | `edittext_stylesheet_custom_tag` | 76 | 8.2s |  |
| 392 | `edittext_stylesheet_display` | 272 | 8.4s |  |
| 393 | `edittext_tag_indent` | 49 | 29.7s |  |
| 394 | `edittext_underline` | 40 | 8.6s |  |
| 395 | `edittext_width_height` | 103 | 8.7s |  |
| 396 | `edittext_wordwrap_word` | 150 | 8.4s |  |
| 397 | `edittext_wrap_breaks` | 2375 | 8.8s |  |
| 398 | `element_format_clone` | 44 | 8.4s |  |
| 399 | `element_format_constructor_order` | 64 | 3.5s |  |
| 400 | `element_format_properties` | 235 | 9.3s |  |
| 401 | `empty_bounds` | 1 | 8.3s |  |
| 402 | `encode_uri_surrogate_pair_invalid` | 8 | 27.6s |  |
| 403 | `encode_uri_surrogate_pair_swf11` | 15 | 7.9s |  |
| 404 | `equals` | 512 | 31.4s |  |
| 405 | `error_geterrormessage` | 779 | 8.2s |  |
| 406 | `error_prototype` | 15 | 8.3s |  |
| 407 | `error_stack_trace` | 45 | 8.3s |  |
| 408 | `error_stack_trace_debug_swf17` | 0 | 27.7s |  |
| 409 | `error_stack_trace_debug_swf18` | 0 | 8.2s |  |
| 410 | `error_stack_trace_edge_cases` | 6 | 8.4s |  |
| 411 | `error_stack_trace_release_swf17` | 0 | 8.5s |  |
| 412 | `error_stack_trace_release_swf18` | 0 | 8.1s |  |
| 413 | `error_throwerror` | 103 | 8.3s |  |
| 414 | `error_tostring` | 29 | 8.1s |  |
| 415 | `error_tostring_more` | 86 | 8.3s |  |
| 416 | `es3_inheritance` | 31 | 8.2s |  |
| 417 | `es4_inheritance` | 30 | 8.2s |  |
| 418 | `es4_interfaces` | 30 | 8.2s |  |
| 419 | `es4_method_binding` | 8 | 8.1s |  |
| 420 | `es4_oop_prototypes` | 14 | 8.4s |  |
| 421 | `es4_protected_inheritance` | 6 | 8.2s |  |
| 422 | `escape` | 71 | 8.2s |  |
| 423 | `escape_multi_byte` | 45 | 8.3s |  |
| 424 | `event_bubbles` | 2 | 8.1s |  |
| 425 | `event_cancelable` | 2 | 8.0s |  |
| 426 | `event_clone` | 20 | 8.2s |  |
| 427 | `event_clone_error_redispatch` | 3 | 8.3s |  |
| 428 | `event_clone_on_redispatch` | 10 | 8.2s |  |
| 429 | `event_formattostring` | 31 | 8.2s |  |
| 430 | `event_isdefaultprevented` | 12 | 8.1s |  |
| 431 | `event_target_getter` | 5 | 3.2s |  |
| 432 | `event_target_set` | 9 | 8.1s |  |
| 433 | `event_type` | 1 | 8.1s |  |
| 434 | `event_valueof_tostring` | 18 | 8.1s |  |
| 435 | `eventdispatcher_dispatchevent` | 12 | 8.1s |  |
| 436 | `eventdispatcher_dispatchevent_cancel` | 20 | 8.1s |  |
| 437 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 8.1s |  |
| 438 | `eventdispatcher_dispatchevent_indirect` | 9 | 8.2s |  |
| 439 | `eventdispatcher_dispatchevent_this` | 5 | 8.1s |  |
| 440 | `eventdispatcher_haseventlistener` | 25 | 8.2s |  |
| 441 | `eventdispatcher_interface_invoke` | 1 | 6.7s |  |
| 442 | `eventdispatcher_tostring` | 10 | 6.7s |  |
| 443 | `eventdispatcher_willtrigger` | 25 | 6.7s |  |
| 444 | `falsiness` | 30 | 6.7s |  |
| 445 | `fast_index_access` | 12 | 6.8s |  |
| 446 | `filefilter_properties` | 4 | 6.8s |  |
| 447 | `filereference_browse_cancel` | 3 | 6.8s |  |
| 448 | `filereference_browse_select` | 9 | 6.6s |  |
| 449 | `filereference_load` | 31 | 6.7s |  |
| 450 | `filereference_save` | 16 | 6.6s |  |
| 451 | `filereference_save_and_browse` | 42 | 6.7s |  |
| 452 | `filereference_save_and_load` | 22 | 6.7s |  |
| 453 | `filereference_uninitialized` | 8 | 6.6s |  |
| 454 | `filereferencelist_browse_cancel` | 6 | 6.6s |  |
| 455 | `filereferencelist_browse_select` | 7 | 6.8s |  |
| 456 | `filter_rewind` | 8 | 22.1s |  |
| 457 | `filters_array_holes` | 25 | 8.0s |  |
| 458 | `finddef` | 3 | 6.8s |  |
| 459 | `findprop_global_prototype` | 6 | 6.8s |  |
| 460 | `flash_media_video_constructor` | 156 | 7.5s |  |
| 461 | `flash_media_video_rotation_probe` | 27 | 6.8s |  |
| 462 | `flash_media_video_setter` | 40 | 7.1s |  |
| 463 | `flash_trace` | 17 | 6.8s |  |
| 464 | `flash_xml` | 29 | 6.7s |  |
| 465 | `flash_xml_cloneNode` | 22 | 6.7s |  |
| 466 | `flash_xml_namespace` | 109 | 6.8s |  |
| 467 | `flash_xml_removeNode` | 60 | 6.7s |  |
| 468 | `focus_events_code` | 161 | 22.5s |  |
| 469 | `focus_events_key_basic` | 132 | 22.3s |  |
| 470 | `focus_events_key_navigation` | 53 | 22.5s |  |
| 471 | `focus_events_key_same_object` | 26 | 6.7s |  |
| 472 | `focus_events_mixed_key_mouse` | 100 | 21.8s |  |
| 473 | `focus_events_mouse_basic` | 260 | 22.3s |  |
| 474 | `focus_events_mouse_focusable` | 112 | 22.1s |  |
| 475 | `focus_events_mouse_same_object` | 40 | 6.7s |  |
| 476 | `focus_remove` | 20 | 21.8s |  |
| 477 | `focus_root_movie` | 4 | 23.8s |  |
| 478 | `focus_stage` | 1 | 6.5s |  |
| 479 | `focusrect` | 18 | 7.4s |  |
| 480 | `focusrect_focuslost` | 9 | 32.1s |  |
| 481 | `focusrect_property` | 110 | 27.5s |  |
| 482 | `font_description_clone` | 14 | 8.2s |  |
| 483 | `font_embedded` | 24 | 27.6s |  |
| 484 | `font_enumeratefonts` | 41 | 8.9s |  |
| 485 | `font_enumeratefonts_filter` | 4 | 8.9s |  |
| 486 | `font_enumeratefonts_order` | 9 | 9.5s |  |
| 487 | `font_hasglyphs` | 40 | 8.7s |  |
| 488 | `font_registerfont` | 129 | 9.2s |  |
| 489 | `framelabel_constr` | 5 | 8.2s |  |
| 490 | `function_call` | 12 | 8.2s |  |
| 491 | `function_call_arguments` | 46 | 8.3s |  |
| 492 | `function_call_arguments_enumerate` | 5 | 8.1s |  |
| 493 | `function_call_coercion` | 108 | 8.6s |  |
| 494 | `function_call_default` | 6 | 8.1s |  |
| 495 | `function_call_rest` | 22 | 8.2s |  |
| 496 | `function_call_types` | 3 | 8.1s |  |
| 497 | `function_call_via_apply` | 11 | 8.1s |  |
| 498 | `function_call_via_call` | 3 | 8.1s |  |
| 499 | `function_display_anonymous` | 7 | 3.2s |  |
| 500 | `function_length` | 6 | 8.1s |  |
| 501 | `function_object` | 2 | 8.1s |  |
| 502 | `function_proto` | 5 | 8.1s |  |
| 503 | `function_proto_created` | 61 | 8.1s |  |
| 504 | `function_to_locale_string` | 4 | 8.1s |  |
| 505 | `function_to_string` | 4 | 8.0s |  |
| 506 | `function_type` | 6 | 8.1s |  |
| 507 | `function_unbound_this` | 51 | 8.2s |  |
| 508 | `function_value_of` | 4 | 8.1s |  |
| 509 | `game_input` | 4 | 8.1s |  |
| 510 | `generate_random_bytes` | 3 | 8.1s |  |
| 511 | `geom_transform` | 74 | 28.1s |  |
| 512 | `get_definition_by_name` | 11 | 8.1s |  |
| 513 | `get_qualified_class_name` | 20 | 8.2s |  |
| 514 | `get_qualified_super_class_name` | 18 | 8.2s |  |
| 515 | `get_slot_edge_cases` | 1 | 8.1s |  |
| 516 | `get_timer` | 2 | 3.1s |  |
| 517 | `getglobalslot` | 1 | 8.0s |  |
| 518 | `getouterscope` | 8 | 8.0s |  |
| 519 | `getouterscope_two_classobjects` | 13 | 8.1s |  |
| 520 | `getter_different_namespace_setter` | 2 | 8.0s |  |
| 521 | `glow_filter` | 127 | 29.3s |  |
| 522 | `goto_button_nested_framescript` | 28 | 27.6s |  |
| 523 | `goto_in_constructframe` | 12 | 27.6s |  |
| 524 | `goto_in_scene_last_frame` | 2 | 27.7s |  |
| 525 | `goto_methods` | 56 | 8.4s |  |
| 526 | `goto_methods_swfver10` | 8 | 8.2s |  |
| 527 | `goto_nested_construct_sibling` | 18 | 8.5s |  |
| 528 | `goto_nested_framescript` | 9 | 8.3s |  |
| 529 | `goto_on_orphan` | 15 | 8.4s |  |
| 530 | `gradient_bevel_filter` | 206 | 8.3s |  |
| 531 | `gradient_glow_filter` | 206 | 8.1s |  |
| 532 | `graphic_linkage` | 9 | 8.4s |  |
| 533 | `graphics_bad_direct_commands` | 5 | 12.3s |  |
| 534 | `graphics_bitmap_fill` | 0 | 29.3s |  |
| 535 | `graphics_bitmaps` | 0 | 8.8s |  |
| 536 | `graphics_direct_commands` | 0 | 8.8s |  |
| 537 | `graphics_draw_triangles` | 98 | 28.4s |  |
| 538 | `graphics_gradients` | 0 | 8.6s |  |
| 539 | `graphics_gradients_nulls` | 0 | 8.6s |  |
| 540 | `graphics_path` | 56 | 8.3s |  |
| 541 | `graphics_round_rects` | 0 | 8.2s |  |
| 542 | `graphics_simple_shapes` | 0 | 8.5s |  |
| 543 | `greaterequals` | 512 | 12.2s |  |
| 544 | `greaterthan` | 512 | 12.3s |  |
| 545 | `has_own_property` | 102 | 8.8s |  |
| 546 | `hasownproperty_namespaces` | 2 | 8.2s |  |
| 547 | `hello_world` | 1 | 8.2s |  |
| 548 | `hittest_morph` | 30 | 8.4s |  |
| 549 | `if_eq` | 10 | 8.3s |  |
| 550 | `if_gt` | 1 | 8.3s |  |
| 551 | `if_gte` | 10 | 3.2s |  |
| 552 | `if_lt` | 1 | 1.3s |  |
| 553 | `if_lte` | 10 | 8.1s |  |
| 554 | `if_ne` | 7 | 3.2s |  |
| 555 | `if_stricteq` | 6 | 8.2s |  |
| 556 | `if_strictne` | 11 | 8.2s |  |
| 557 | `ime_linux_dead_keys` | 10 | 8.2s |  |
| 558 | `in` | 102 | 8.7s |  |
| 559 | `inclocal` | 46 | 19.3s |  |
| 560 | `inclocal_i` | 46 | 5.2s |  |
| 561 | `increment` | 46 | 5.0s |  |
| 562 | `increment_i` | 46 | 4.9s |  |
| 563 | `indexing_delete` | 75 | 4.9s |  |
| 564 | `init_callee_cached` | 24 | 4.8s |  |
| 565 | `instanceof` | 58 | 4.9s |  |
| 566 | `instantiate_root_character` | 4 | 5.0s |  |
| 567 | `instantiation_on_enter_frame` | 7 | 17.9s |  |
| 568 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.8s |  |
| 569 | `int_constr` | 92 | 4.9s |  |
| 570 | `int_edge_cases` | 19 | 17.6s |  |
| 571 | `int_instanceof` | 3 | 4.9s |  |
| 572 | `int_tofixed` | 1215 | 4.8s |  |
| 573 | `int_toprecision` | 1125 | 4.8s |  |
| 574 | `int_tostring` | 3375 | 4.8s |  |
| 575 | `interactiveobject_enabled` | 25 | 4.9s |  |
| 576 | `interface_namespaces` | 78 | 4.9s |  |
| 577 | `invalid_utf8` | 12 | 4.9s |  |
| 578 | `is_finite` | 46 | 4.7s |  |
| 579 | `is_nan` | 46 | 4.9s |  |
| 580 | `is_prototype_of` | 12 | 5.5s |  |
| 581 | `issue_10221` | 2 | 4.8s |  |
| 582 | `issue_13780` | 12 | 4.9s |  |
| 583 | `issue_14901` | 1 | 5.1s |  |
| 584 | `issue_17675_edittext_paste_maxchars` | 1 | 5.2s |  |
| 585 | `issue_5292` | 5 | 5.3s |  |
| 586 | `issue_8630` | 2 | 5.2s |  |
| 587 | `issue_8630_placeremoveplace` | 15 | 5.2s |  |
| 588 | `issue_8630_placeremoveplace_scriptremove` | 16 | 5.1s |  |
| 589 | `issue_8630_scriptremove` | 11 | 5.1s |  |
| 590 | `istype` | 24 | 1.6s |  |
| 591 | `istypelate` | 58 | 5.1s |  |
| 592 | `istypelate_coerce` | 198 | 5.1s |  |
| 593 | `jpeg_loader_context` | 6 | 5.0s |  |
| 594 | `json_errors` | 9 | 18.9s |  |
| 595 | `json_parse` | 21 | 5.1s |  |
| 596 | `json_stringify` | 12 | 5.3s |  |
| 597 | `json_stringify_function` | 12 | 5.2s |  |
| 598 | `json_stringify_order` | 1 | 5.2s |  |
| 599 | `json_version_gated` | 1 | 5.1s |  |
| 600 | `key_input_80percent` | 1812 | 29.0s |  |
| 601 | `key_input_location` | 126 | 8.2s |  |
| 602 | `key_input_numpad` | 384 | 8.3s |  |
| 603 | `large_preload_from_url` | 27 | 10.3s |  |
| 604 | `large_preload_image_from_bytes` | 25 | 8.7s |  |
| 605 | `lazyinit` | 17 | 8.1s |  |
| 606 | `lessequals` | 512 | 12.1s |  |
| 607 | `lessthan` | 512 | 12.1s |  |
| 608 | `loader_bitmap_transparency` | 14 | 8.3s |  |
| 609 | `loader_bytes_unknown_content` | 14 | 8.3s |  |
| 610 | `loader_child_getdefinition` | 5 | 8.4s |  |
| 611 | `loader_duplicate_coerce` | 3 | 8.7s |  |
| 612 | `loader_duplicate_coerce_new_domain` | 4 | 8.5s |  |
| 613 | `loader_error_in_root_ctor` | 4 | 8.7s |  |
| 614 | `loader_events` | 92 | 10.6s |  |
| 615 | `loader_image` | 8 | 8.9s |  |
| 616 | `loader_jpegxr` | 2 | 28.7s |  |
| 617 | `loader_jpegxr_alpha` | 1 | 28.1s |  |
| 618 | `loader_loadbytes_events` | 30 | 9.1s |  |
| 619 | `loader_loadbytes_invalid_png` | 4 | 8.6s |  |
| 620 | `loader_loadbytes_url` | 12 | 8.6s |  |
| 621 | `loader_loaderurl` | 6 | 8.9s |  |
| 622 | `loader_method` | 85 | 8.6s |  |
| 623 | `loader_noninteractive_try_click_root` | 5 | 29.3s |  |
| 624 | `loader_reuse` | 38 | 8.8s |  |
| 625 | `loader_unknown_content` | 24 | 8.6s |  |
| 626 | `loader_visibility_interactive` | 1 | 8.6s |  |
| 627 | `loaderinfo_events` | 7 | 8.5s |  |
| 628 | `loaderinfo_loadurl` | 12 | 8.5s |  |
| 629 | `loaderinfo_more` | 6 | 8.7s |  |
| 630 | `loaderinfo_properties` | 18 | 28.8s |  |
| 631 | `loaderinfo_properties_not_loaded` | 23 | 8.6s |  |
| 632 | `loaderinfo_quine` | 1005 | 8.4s |  |
| 633 | `loaderinfo_root` | 10 | 8.5s |  |
| 634 | `loaderinfo_root_allows` | 2 | 8.4s |  |
| 635 | `localconnection` | 890 | 10.8s |  |
| 636 | `localconnection_send` | 4 | 29.2s |  |
| 637 | `lshift` | 1058 | 20.0s |  |
| 638 | `mask_reapply` | 1 | 28.3s |  |
| 639 | `math` | 497 | 8.6s |  |
| 640 | `matrix` | 338 | 18.3s |  |
| 641 | `matrix3d` | 57 | 28.6s |  |
| 642 | `matrix3d_append` | 16 | 8.5s |  |
| 643 | `matrix3d_append_prepend_translation` | 42 | 8.5s |  |
| 644 | `matrix3d_compose` | 34 | 8.8s |  |
| 645 | `matrix3d_constructor_clone` | 15 | 8.5s |  |
| 646 | `matrix3d_copy_column` | 83 | 8.8s |  |
| 647 | `matrix3d_copy_raw_data_from` | 55 | 3.7s |  |
| 648 | `matrix3d_copy_raw_data_to` | 38 | 8.8s |  |
| 649 | `matrix3d_copy_row` | 83 | 8.5s |  |
| 650 | `matrix3d_determinant` | 182 | 8.8s |  |
| 651 | `matrix3d_invert` | 18 | 8.6s |  |
| 652 | `matrix3d_position` | 19 | 8.7s |  |
| 653 | `matrix3d_precision` | 28 | 8.8s |  |
| 654 | `matrix3d_prepend` | 16 | 8.5s |  |
| 655 | `matrix3d_raw_data` | 33 | 8.7s |  |
| 656 | `matrix3d_transform_vector` | 52 | 8.8s |  |
| 657 | `matrix3d_transpose` | 5 | 8.6s |  |
| 658 | `method_association` | 5 | 8.6s |  |
| 659 | `method_without_body` | 3 | 27.9s |  |
| 660 | `missing_external_interface` | 10 | 8.4s |  |
| 661 | `modulo` | 1058 | 19.6s |  |
| 662 | `morph_shape` | 2 | 27.7s |  |
| 663 | `mouse_children` | 192 | 28.0s |  |
| 664 | `mouse_click_events` | 90 | 27.5s |  |
| 665 | `mouse_double_click_events` | 188 | 8.4s |  |
| 666 | `mouse_empty_parent` | 4 | 8.4s |  |
| 667 | `mouse_over_while_dragging` | 3 | 8.4s |  |
| 668 | `mouse_pick_avm1_root` | 2 | 27.8s |  |
| 669 | `mouse_pick_button_mode` | 2 | 8.4s |  |
| 670 | `mouse_pick_dobj_mask` | 4 | 9.0s |  |
| 671 | `mouse_pick_masking` | 7 | 23.6s |  |
| 672 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 22.1s |  |
| 673 | `mouse_pick_non_interactive_dobj_mask` | 3 | 22.3s |  |
| 674 | `mouse_pick_text` | 8 | 6.8s |  |
| 675 | `mouse_sibling` | 8 | 6.8s |  |
| 676 | `mouse_wheel_events` | 36 | 22.9s |  |
| 677 | `mouseevent_constr` | 66 | 6.6s |  |
| 678 | `mouseevent_stagexy` | 35 | 6.7s |  |
| 679 | `mouseevent_valueof_tostring` | 28 | 6.6s |  |
| 680 | `movieclip_addframescript` | 3 | 22.0s |  |
| 681 | `movieclip_child_property` | 16 | 6.7s |  |
| 682 | `movieclip_constr` | 21 | 6.6s |  |
| 683 | `movieclip_currentlabels` | 17 | 22.0s |  |
| 684 | `movieclip_currentlabels_dupes1` | 46 | 22.0s |  |
| 685 | `movieclip_currentlabels_dupes2` | 30 | 6.6s |  |
| 686 | `movieclip_currentlabels_dupes3` | 67 | 6.6s |  |
| 687 | `movieclip_currentscene` | 12 | 21.8s |  |
| 688 | `movieclip_dispatchevent` | 430 | 6.7s |  |
| 689 | `movieclip_dispatchevent_cancel` | 102 | 6.7s |  |
| 690 | `movieclip_dispatchevent_handlerorder` | 251 | 6.6s |  |
| 691 | `movieclip_dispatchevent_selfadd` | 80 | 6.6s |  |
| 692 | `movieclip_dispatchevent_target` | 899 | 6.7s |  |
| 693 | `movieclip_displayevents` | 96 | 21.9s |  |
| 694 | `movieclip_displayevents_clickgoto` | 676 | 22.2s |  |
| 695 | `movieclip_displayevents_clickgoto2` | 2001 | 7.1s |  |
| 696 | `movieclip_displayevents_clickplay` | 575 | 6.8s |  |
| 697 | `movieclip_displayevents_clicksymbol` | 562 | 6.8s |  |
| 698 | `movieclip_displayevents_constructframegoto` | 140 | 7.0s |  |
| 699 | `movieclip_displayevents_constructframeplay` | 50 | 6.9s |  |
| 700 | `movieclip_displayevents_constructframesymbol` | 144 | 7.0s |  |
| 701 | `movieclip_displayevents_dblhandler` | 21 | 6.8s |  |
| 702 | `movieclip_displayevents_enterframegoto` | 149 | 6.8s |  |
| 703 | `movieclip_displayevents_enterframeplay` | 48 | 6.8s |  |
| 704 | `movieclip_displayevents_enterframesymbol` | 149 | 22.1s |  |
| 705 | `movieclip_displayevents_exitframegoto` | 106 | 6.9s |  |
| 706 | `movieclip_displayevents_exitframeplay` | 44 | 6.7s |  |
| 707 | `movieclip_displayevents_exitframesymbol` | 135 | 6.8s |  |
| 708 | `movieclip_displayevents_looping` | 63 | 21.9s |  |
| 709 | `movieclip_displayevents_stopped` | 113 | 7.0s |  |
| 710 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 711 | `movieclip_displayevents_timeline` | 128 | 6.8s |  |
| 712 | `movieclip_drawrect` | 54 | 28.3s |  |
| 713 | `movieclip_frameconstruct_skipped` | 9 | 8.2s |  |
| 714 | `movieclip_goto_during_frame_script` | 15 | 27.4s |  |
| 715 | `movieclip_goto_overwrite` | 14 | 27.4s |  |
| 716 | `movieclip_goto_scene_last_frame_int` | 1 | 27.1s |  |
| 717 | `movieclip_goto_scene_last_frame_label` | 1 | 8.0s |  |
| 718 | `movieclip_gotoandplay` | 15 | 27.1s |  |
| 719 | `movieclip_gotoandstop` | 13 | 8.1s |  |
| 720 | `movieclip_gotoandstop_children` | 4 | 8.2s |  |
| 721 | `movieclip_gotoandstop_framescripts1` | 4 | 8.1s |  |
| 722 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 723 | `movieclip_gotoandstop_framescripts_self` | 7 | 27.1s |  |
| 724 | `movieclip_gotoandstop_queueing` | 12 | 27.3s |  |
| 725 | `movieclip_hittest` | 67 | 8.3s |  |
| 726 | `movieclip_next_frame` | 2 | 8.1s |  |
| 727 | `movieclip_next_scene` | 6 | 27.0s |  |
| 728 | `movieclip_play` | 3 | 8.0s |  |
| 729 | `movieclip_prev_frame` | 3 | 7.9s |  |
| 730 | `movieclip_prev_scene` | 7 | 8.1s |  |
| 731 | `movieclip_properties` | 79 | 27.2s |  |
| 732 | `movieclip_queued_noop_goto_swf10` | 9 | 8.2s |  |
| 733 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 734 | `movieclip_scenes` | 11 | 8.1s |  |
| 735 | `movieclip_soundtransform` | 831 | 29.2s |  |
| 736 | `movieclip_stop` | 1 | 8.0s |  |
| 737 | `movieclip_super_is_symbol` | 20 | 8.4s |  |
| 738 | `movieclip_symbol_constr` | 8 | 8.2s |  |
| 739 | `movieclip_text_mousedown` | 1 | 8.2s |  |
| 740 | `movieclip_willtrigger` | 5 | 8.2s |  |
| 741 | `multiply` | 1058 | 19.8s |  |
| 742 | `namespace_constr` | 253 | 8.4s |  |
| 743 | `namespace_constr_args` | 1 | 8.1s |  |
| 744 | `namespace_enumeration_order` | 7 | 27.1s |  |
| 745 | `nan_scale` | 9 | 8.2s |  |
| 746 | `native_menu_basic` | 19 | 10.5s |  |
| 747 | `navigateToURL_target_normalize` | 107 | 29.7s |  |
| 748 | `negate` | 30 | 8.2s |  |
| 749 | `negative_volume_panned` | 0 | 8.4s |  |
| 750 | `nested_iteration` | 11 | 8.1s |  |
| 751 | `net_getClassByAlias` | 3 | 8.1s |  |
| 752 | `net_navigateToURL` | 57 | 8.1s |  |
| 753 | `net_stream_play_options` | 6 | 8.1s |  |
| 754 | `netconnection_close` | 55 | 29.1s |  |
| 755 | `netconnection_properties` | 78 | 8.4s |  |
| 756 | `netconnection_send_remote` | 50 | 30.9s |  |
| 757 | `netconnection_serialize_arrays` | 6 | 8.4s |  |
| 758 | `netfilterevent` | 10 | 27.8s |  |
| 759 | `netstream_client` | 10 | 8.5s |  |
| 760 | `netstream_connect` | 7 | 8.3s |  |
| 761 | `netstream_flv_date` | 4 | 8.3s |  |
| 762 | `newactivation_in_script_init` | 3 | 8.2s |  |
| 763 | `newclass_mismatched` | 4 | 8.2s |  |
| 764 | `newclass_twice` | 3 | 8.2s |  |
| 765 | `nonconflicting_declarations` | 0 | 8.2s |  |
| 766 | `null_void_types` | 8 | 8.2s |  |
| 767 | `number_autoconv` | 21 | 8.3s |  |
| 768 | `number_autoconv_amf` | 132 | 8.3s |  |
| 769 | `number_autoconv_array_sort_32bit` | 1 | 8.2s |  |
| 770 | `number_constr` | 58 | 8.4s |  |
| 771 | `number_convert_edge_cases` | 180 | 27.7s |  |
| 772 | `number_toexponential` | 378 | 8.3s |  |
| 773 | `number_toexponential2` | 35 | 8.2s |  |
| 774 | `number_tofixed` | 378 | 8.2s |  |
| 775 | `number_toprecision` | 350 | 8.4s |  |
| 776 | `obfuscated_class_names` | 3 | 8.2s |  |
| 777 | `object_enumeration` | 10 | 8.2s |  |
| 778 | `object_prototype` | 4 | 8.3s |  |
| 779 | `object_to_locale_string` | 2 | 8.2s |  |
| 780 | `object_to_string` | 2 | 8.2s |  |
| 781 | `object_value_of` | 2 | 3.1s |  |
| 782 | `op_coerce` | 54 | 8.4s |  |
| 783 | `op_coerce_x` | 54 | 8.3s |  |
| 784 | `op_escxattr` | 2 | 8.2s |  |
| 785 | `op_escxelem` | 2 | 8.3s |  |
| 786 | `op_lookupswitch` | 4 | 8.4s |  |
| 787 | `optimize_coerce` | 1 | 8.2s |  |
| 788 | `orphan_movie_complex` | 80 | 8.8s |  |
| 789 | `orphan_movie_reorder` | 111 | 28.1s |  |
| 790 | `package_namespace` | 7 | 28.0s |  |
| 791 | `param_default_value_has_zero_cpool_index` | 1 | 27.8s |  |
| 792 | `parent_early_access_child` | 16 | 27.9s |  |
| 793 | `parse_float` | 81 | 8.6s |  |
| 794 | `parse_float_swf10` | 81 | 8.3s |  |
| 795 | `parse_int` | 135 | 8.9s |  |
| 796 | `perspective_projection` | 1443 | 27.9s |  |
| 797 | `perspective_projection_basic` | 40 | 8.4s |  |
| 798 | `pixelbender_ceil` | 77 | 8.6s |  |
| 799 | `pixelbender_conditional` | 138 | 8.8s |  |
| 800 | `pixelbender_conversions` | 270 | 8.7s |  |
| 801 | `pixelbender_dithering` | 8 | 37.2s |  |
| 802 | `pixelbender_div` | 36 | 8.7s |  |
| 803 | `pixelbender_effect_BlurredFocus` | 0 | 37.4s |  |
| 804 | `pixelbender_effect_glassDisplace` | 0 | 15.5s |  |
| 805 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 33.9s |  |
| 806 | `pixelbender_effect_smudge` | 0 | 12.3s |  |
| 807 | `pixelbender_effect_tintype` | 0 | 11.4s |  |
| 808 | `pixelbender_effect_twirl` | 0 | 13.1s |  |
| 809 | `pixelbender_eof` | 7 | 8.7s |  |
| 810 | `pixelbender_images` | 0 | 11.1s |  |
| 811 | `pixelbender_input` | 103 | 28.8s |  |
| 812 | `pixelbender_logicalnot` | 20 | 8.4s |  |
| 813 | `pixelbender_malformed_data` | 190 | 28.9s |  |
| 814 | `pixelbender_multiple_out_params` | 1 | 8.4s |  |
| 815 | `pixelbender_no_out_param` | 6 | 8.4s |  |
| 816 | `pixelbender_outputs` | 13 | 8.6s |  |
| 817 | `pixelbender_padding_bytes` | 22 | 8.5s |  |
| 818 | `pixelbender_param_qualifier` | 512 | 8.5s |  |
| 819 | `pixelbender_parameters` | 1563 | 8.8s |  |
| 820 | `pixelbender_parameters_bool` | 240 | 8.7s |  |
| 821 | `pixelbender_parameters_int_vs_bool` | 54 | 8.5s |  |
| 822 | `pixelbender_parse_errors` | 6 | 8.5s |  |
| 823 | `pixelbender_rsqrt` | 24 | 8.6s |  |
| 824 | `pixelbender_select_kinds` | 8 | 8.7s |  |
| 825 | `pixelbender_shaderdata` | 49 | 8.6s |  |
| 826 | `pixelbender_shaderdata_setter` | 99 | 8.9s |  |
| 827 | `pixelbender_sign` | 60 | 8.7s |  |
| 828 | `pixelbender_vector_output` | 11 | 8.7s |  |
| 829 | `place_and_lookup/swf10` | 33 | 8.5s |  |
| 830 | `place_and_lookup/swf9` | 33 | 1.4s |  |
| 831 | `place_multiple` | 17 | 29.0s |  |
| 832 | `place_object_replace` | 9 | 27.6s |  |
| 833 | `place_object_replace_2` | 24 | 27.6s |  |
| 834 | `place_object_same_depth_frame` | 1 | 27.5s |  |
| 835 | `point` | 132 | 8.9s |  |
| 836 | `primitive_edge_cases` | 1 | 8.4s |  |
| 837 | `primitive_toString` | 277 | 8.6s |  |
| 838 | `primitive_valueOf` | 285 | 8.3s |  |
| 839 | `print_job_options` | 3 | 8.4s |  |
| 840 | `property_is_enumerable` | 114 | 9.1s |  |
| 841 | `property_is_enumerable_reset` | 23 | 8.4s |  |
| 842 | `property_priority` | 22 | 8.8s |  |
| 843 | `property_priority_chained` | 4 | 8.3s |  |
| 844 | `property_priority_definition_names_order` | 2 | 8.6s |  |
| 845 | `property_priority_three_level` | 6 | 8.5s |  |
| 846 | `propertyisenumerable_namespaces` | 6 | 8.4s |  |
| 847 | `prototype_set_null` | 7 | 8.3s |  |
| 848 | `proxy_callproperty` | 24 | 8.4s |  |
| 849 | `proxy_deleteproperty` | 64 | 8.5s |  |
| 850 | `proxy_enumeration` | 34 | 8.4s |  |
| 851 | `proxy_getproperty` | 77 | 8.5s |  |
| 852 | `proxy_hasownproperty` | 8 | 8.3s |  |
| 853 | `proxy_hasproperty` | 32 | 8.4s |  |
| 854 | `proxy_not_overridden` | 54 | 8.4s |  |
| 855 | `proxy_serialize` | 9 | 8.4s |  |
| 856 | `proxy_setproperty` | 42 | 8.4s |  |
| 857 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.3s |  |
| 858 | `qname_constr` | 32 | 8.4s |  |
| 859 | `qname_constr_namespace` | 24 | 8.4s |  |
| 860 | `qname_enumeration` | 9 | 8.4s |  |
| 861 | `qname_indexing` | 23 | 8.4s |  |
| 862 | `qname_tostring` | 25 | 8.4s |  |
| 863 | `qname_valueof` | 29 | 8.4s |  |
| 864 | `rectangle` | 1094 | 9.0s |  |
| 865 | `regexp_constr` | 148 | 8.6s |  |
| 866 | `regexp_exec` | 19 | 8.4s |  |
| 867 | `regexp_extended` | 47 | 8.3s |  |
| 868 | `regexp_multiargs` | 1 | 8.3s |  |
| 869 | `regexp_test` | 27 | 8.4s |  |
| 870 | `regexp_toString` | 10 | 8.4s |  |
| 871 | `register_script_refresh` | 35 | 28.0s |  |
| 872 | `remove_child_clear_field` | 88 | 29.9s |  |
| 873 | `remove_dobj` | 3 | 28.4s |  |
| 874 | `resolve_order` | 4 | 8.4s |  |
| 875 | `responder_null_callbacks` | 1 | 27.5s |  |
| 876 | `rng` | 1 | 9.4s |  |
| 877 | `rootless` | 42 | 8.3s |  |
| 878 | `rshift` | 1058 | 20.4s |  |
| 879 | `rtqname_not_namespace` | 12 | 8.1s |  |
| 880 | `sandbox_type_inherited` | 2 | 8.6s |  |
| 881 | `sandbox_type_local_file` | 1 | 8.1s |  |
| 882 | `sandbox_type_local_network` | 1 | 7.9s |  |
| 883 | `scene_constr` | 8 | 8.1s |  |
| 884 | `scope_optimizations` | 4 | 8.0s |  |
| 885 | `scopes_dont_cache/order-1` | 1 | 27.0s |  |
| 886 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 887 | `security_domain_current` | 2 | 8.1s |  |
| 888 | `selection` | 239 | 9.1s |  |
| 889 | `set_local_0` | 31 | 8.3s |  |
| 890 | `set_property_is_enumerable` | 85 | 8.6s |  |
| 891 | `shaderparameter_value` | 4 | 8.3s |  |
| 892 | `shape_drawrect` | 54 | 8.4s |  |
| 893 | `shared_object_no_root` | 3 | 8.3s |  |
| 894 | `simplebutton_added_to_stage` | 45 | 27.8s |  |
| 895 | `simplebutton_childevents` | 86 | 27.8s |  |
| 896 | `simplebutton_childevents_nested` | 54 | 8.5s |  |
| 897 | `simplebutton_childevents_sprite` | 13 | 8.2s |  |
| 898 | `simplebutton_childprops` | 144 | 8.3s |  |
| 899 | `simplebutton_childshuffle` | 23 | 8.1s |  |
| 900 | `simplebutton_constr` | 36 | 8.5s |  |
| 901 | `simplebutton_constr_childevents` | 48 | 8.5s |  |
| 902 | `simplebutton_constr_params` | 42 | 8.3s |  |
| 903 | `simplebutton_mouseenabled` | 26 | 8.3s |  |
| 904 | `simplebutton_multi_children` | 19 | 8.5s |  |
| 905 | `simplebutton_structure` | 27 | 8.3s |  |
| 906 | `simplebutton_symbolclass` | 68 | 8.3s |  |
| 907 | `slot_disp_id_shared_numbering` | 1 | 26.9s |  |
| 908 | `slots_force_autoassigned` | 1 | 28.1s |  |
| 909 | `socket_after_disconnect` | 1 | 8.5s |  |
| 910 | `socket_close` | 2 | 8.6s |  |
| 911 | `socket_connect` | 4 | 8.7s |  |
| 912 | `socket_errors` | 56 | 9.0s |  |
| 913 | `socket_read_big` | 48 | 8.6s |  |
| 914 | `socket_read_little` | 48 | 3.4s |  |
| 915 | `socket_read_write_object` | 8 | 8.5s |  |
| 916 | `socket_write_big` | 15 | 8.8s |  |
| 917 | `socket_write_little` | 14 | 8.6s |  |
| 918 | `sound_constructor_with_args` | 6 | 8.9s |  |
| 919 | `sound_embeddedprops` | 26 | 8.8s |  |
| 920 | `sound_play` | 19 | 8.7s |  |
| 921 | `sound_rootless` | 7 | 8.6s |  |
| 922 | `sound_valueof` | 33 | 8.6s |  |
| 923 | `soundchannel_soundtransform` | 835 | 30.1s |  |
| 924 | `soundchannel_soundtransform_exists` | 5 | 28.3s |  |
| 925 | `soundchannel_stop` | 8 | 28.4s |  |
| 926 | `soundmixer_buffertime` | 5 | 8.5s |  |
| 927 | `soundmixer_stopall` | 6 | 28.2s |  |
| 928 | `soundtransform` | 442 | 13.7s |  |
| 929 | `space_justifier_clone` | 12 | 8.5s |  |
| 930 | `sprite_with_frames` | 0 | 32.3s |  |
| 931 | `stage3d_agal_cross_product` | 0 | 11.1s |  |
| 932 | `stage3d_agal_upload_errors` | 66 | 11.1s |  |
| 933 | `stage3d_bitmap` | 0 | 33.4s |  |
| 934 | `stage3d_blend` | 81 | 32.5s |  |
| 935 | `stage3d_context3d_string_args` | 158 | 9.6s |  |
| 936 | `stage3d_errors` | 7 | 8.7s |  |
| 937 | `stage3d_errors_atf` | 3 | 9.9s |  |
| 938 | `stage3d_errors_swf_29` | 6 | 8.8s |  |
| 939 | `stage3d_float1_index` | 0 | 31.0s |  |
| 940 | `stage3d_fractal` | 0 | 31.7s |  |
| 941 | `stage3d_ignore_sampler_override` | 0 | 31.1s |  |
| 942 | `stage3d_multistage_triangle` | 3 | 11.3s |  |
| 943 | `stage3d_program_constants_bytearray_be` | 0 | 33.1s |  |
| 944 | `stage3d_program_constants_bytearray_le` | 0 | 28.7s |  |
| 945 | `stage3d_program_constants_invalid_input` | 21 | 23.9s |  |
| 946 | `stage3d_raytrace` | 0 | 43.9s |  |
| 947 | `stage3d_rotating_cube` | 0 | 9.9s |  |
| 948 | `stage3d_sampler` | 0 | 9.0s |  |
| 949 | `stage3d_sampler_partial_upload` | 0 | 8.8s |  |
| 950 | `stage3d_stencil` | 0 | 25.1s |  |
| 951 | `stage3d_texture` | 0 | 13.1s |  |
| 952 | `stage3d_texture_bytearray` | 0 | 10.1s |  |
| 953 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.3s |  |
| 954 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.3s |  |
| 955 | `stage3d_triangle` | 0 | 9.0s |  |
| 956 | `stage3d_triangle_bytes4` | 0 | 8.8s |  |
| 957 | `stage3d_triangle_float1` | 0 | 8.8s |  |
| 958 | `stage3d_triangle_index_upload` | 0 | 8.7s |  |
| 959 | `stage3d_x_y` | 22 | 6.8s |  |
| 960 | `stage_access` | 10 | 6.8s |  |
| 961 | `stage_displayobject_properties` | 24 | 6.7s |  |
| 962 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.6s |  |
| 963 | `stage_framerate_nan` | 7 | 6.8s |  |
| 964 | `stage_framerate_negative` | 6 | 6.6s |  |
| 965 | `stage_framerate_zero` | 6 | 6.7s |  |
| 966 | `stage_invalidate` | 38 | 6.8s |  |
| 967 | `stage_loaderinfo_properties` | 24 | 22.1s |  |
| 968 | `stage_mousechildren` | 2 | 6.6s |  |
| 969 | `stage_mouseenabled` | 15 | 6.6s |  |
| 970 | `stage_overriden_setters` | 31 | 6.7s |  |
| 971 | `stage_properties` | 30 | 6.5s |  |
| 972 | `stage_properties2` | 213 | 6.7s |  |
| 973 | `stage_stage3Ds_vector` | 1 | 6.5s |  |
| 974 | `static_length` | 24 | 6.8s |  |
| 975 | `static_text` | 3 | 6.7s |  |
| 976 | `static_var_with_this_in_ctor` | 2 | 6.6s |  |
| 977 | `statictext_text` | 8 | 6.7s |  |
| 978 | `stored_properties` | 11 | 6.6s |  |
| 979 | `strict_equality` | 34 | 6.9s |  |
| 980 | `string_call` | 13 | 6.8s |  |
| 981 | `string_case` | 23 | 6.6s |  |
| 982 | `string_char_at` | 27 | 6.6s |  |
| 983 | `string_char_code_at` | 28 | 6.5s |  |
| 984 | `string_concat_fromcharcode` | 37 | 28.5s |  |
| 985 | `string_constr` | 25 | 27.0s |  |
| 986 | `string_indexof_lastindexof` | 87 | 8.3s |  |
| 987 | `string_length` | 16 | 8.1s |  |
| 988 | `string_locale_compare` | 39 | 8.4s |  |
| 989 | `string_match` | 51 | 8.3s |  |
| 990 | `string_relational_compare` | 4 | 8.1s |  |
| 991 | `string_replace` | 51 | 8.3s |  |
| 992 | `string_search` | 41 | 8.2s |  |
| 993 | `string_slice_substr_substring` | 170 | 9.2s |  |
| 994 | `string_split` | 29 | 8.2s |  |
| 995 | `string_substr_negative` | 21 | 8.1s |  |
| 996 | `string_substr_weird` | 182 | 8.1s |  |
| 997 | `stylesheet` | 221 | 8.6s |  |
| 998 | `stylesheet_parse_color` | 69 | 8.1s |  |
| 999 | `stylesheet_transform` | 307 | 8.5s |  |
| 1000 | `sub_super_same_field` | 12 | 3.2s |  |
| 1001 | `subclass_superclass_linked_symbol` | 4 | 8.6s |  |
| 1002 | `subtract` | 1058 | 20.2s |  |
| 1003 | `super_get_call` | 12 | 8.1s |  |
| 1004 | `supercall_two_classobjects` | 2 | 8.1s |  |
| 1005 | `supercalls_coerce` | 8 | 8.2s |  |
| 1006 | `supercalls_weird` | 2 | 8.0s |  |
| 1007 | `superinterface_call` | 20 | 8.1s |  |
| 1008 | `superinterface_instanceof` | 18 | 8.1s |  |
| 1009 | `swf8` | 1 | 8.1s |  |
| 1010 | `swf_10_queued_goto_scripts_construct` | 52 | 27.4s |  |
| 1011 | `swf_9_goto_in_enter_frame` | 17 | 8.1s |  |
| 1012 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.2s |  |
| 1013 | `swf_9_queued_goto_scripts` | 6 | 27.2s |  |
| 1014 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 1015 | `swf_9_versioning` | 2 | 8.1s |  |
| 1016 | `swf_wrong_frame_count` | 38 | 8.4s |  |
| 1017 | `swf_wrong_frame_count_isplaying` | 22 | 8.1s |  |
| 1018 | `symbol_class_binary_data` | 8 | 8.1s |  |
| 1019 | `symbol_class_conflict` | 4 | 11.8s |  |
| 1020 | `symbol_class_root_not_zero` | 1 | 8.0s |  |
| 1021 | `symbolclass_invalid_utf8` | 2 | 8.2s |  |
| 1022 | `system_exit` | 3 | 8.2s |  |
| 1023 | `system_setclipboard_null` | 1 | 8.0s |  |
| 1024 | `tab_ordering_arrows` | 998 | 25.0s |  |
| 1025 | `tab_ordering_automatic_advanced` | 184 | 7.5s |  |
| 1026 | `tab_ordering_automatic_basic` | 45 | 22.9s |  |
| 1027 | `tab_ordering_children` | 116 | 7.1s |  |
| 1028 | `tab_ordering_custom_basic` | 34 | 6.9s |  |
| 1029 | `tab_ordering_stage_tab_children` | 32 | 7.1s |  |
| 1030 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.0s |  |
| 1031 | `tab_ordering_tabbable` | 47 | 7.2s |  |
| 1032 | `tabstop_properties` | 105 | 23.3s |  |
| 1033 | `text_element_basic` | 34 | 7.0s |  |
| 1034 | `text_engine_fontdescription` | 27 | 7.0s |  |
| 1035 | `text_engine_groupelement` | 64 | 8.0s |  |
| 1036 | `text_run` | 7 | 7.1s |  |
| 1037 | `textblock_createline_errors` | 23 | 6.9s |  |
| 1038 | `textblock_createline_fte` | 9 | 23.1s |  |
| 1039 | `textblock_properties` | 118 | 7.2s |  |
| 1040 | `textbox_click` | 37 | 23.6s |  |
| 1041 | `textfield_event` | 66 | 7.4s |  |
| 1042 | `textfield_focusin_event` | 9 | 7.0s |  |
| 1043 | `textfield_input_dead_keys_windows` | 15 | 7.0s |  |
| 1044 | `textfield_input_events` | 25 | 19.0s |  |
| 1045 | `textfield_unload` | 39 | 24.5s |  |
| 1046 | `textformat` | 1134 | 7.2s |  |
| 1047 | `textformat_display` | 14 | 7.2s |  |
| 1048 | `textformat_font_max_length` | 4 | 7.0s |  |
| 1049 | `textline_inapplicable_properties` | 10 | 7.2s |  |
| 1050 | `textline_name` | 1 | 7.1s |  |
| 1051 | `textline_raw_text_length` | 30 | 7.1s |  |
| 1052 | `textline_splitting_basic` | 76 | 7.2s |  |
| 1053 | `textline_throwerror` | 30 | 7.1s |  |
| 1054 | `textline_validity` | 162 | 7.2s |  |
| 1055 | `throw` | 3 | 7.0s |  |
| 1056 | `timeline_scripts` | 3 | 23.5s |  |
| 1057 | `timer` | 90 | 7.9s |  |
| 1058 | `timer_events` | 3 | 7.3s |  |
| 1059 | `timer_finished` | 11 | 7.3s |  |
| 1060 | `timer_invalid_delay` | 30 | 7.0s |  |
| 1061 | `timer_reset` | 8 | 28.8s |  |
| 1062 | `timer_setdelay` | 5 | 27.6s |  |
| 1063 | `trace` | 12 | 7.3s |  |
| 1064 | `truthiness` | 30 | 7.3s |  |
| 1065 | `try_catch` | 11 | 7.3s |  |
| 1066 | `try_catch_typed` | 12 | 7.3s |  |
| 1067 | `typeof` | 30 | 7.4s |  |
| 1068 | `uint_constr` | 92 | 7.3s |  |
| 1069 | `uint_tofixed` | 1215 | 7.3s |  |
| 1070 | `uint_toprecision` | 1125 | 7.3s |  |
| 1071 | `uint_tostring` | 3375 | 7.3s |  |
| 1072 | `uncaught_error_basic` | 2 | 7.5s |  |
| 1073 | `unchecked_function` | 15 | 7.3s |  |
| 1074 | `unescape` | 28 | 7.3s |  |
| 1075 | `url_loader` | 25 | 7.4s |  |
| 1076 | `url_vars` | 27 | 7.2s |  |
| 1077 | `urlrequest` | 18 | 7.3s |  |
| 1078 | `urlstream_basic` | 5 | 7.3s |  |
| 1079 | `urshift` | 1058 | 7.2s |  |
| 1080 | `utils3d` | 7 | 7.2s |  |
| 1081 | `vector3d` | 397 | 7.3s |  |
| 1082 | `vector_class` | 36 | 7.3s |  |
| 1083 | `vector_class_call` | 11 | 7.3s |  |
| 1084 | `vector_coercion` | 66 | 7.4s |  |
| 1085 | `vector_concat` | 90 | 7.5s |  |
| 1086 | `vector_constr` | 107 | 7.5s |  |
| 1087 | `vector_enumeration` | 5 | 7.4s |  |
| 1088 | `vector_every` | 92 | 7.5s |  |
| 1089 | `vector_filter` | 95 | 7.5s |  |
| 1090 | `vector_holes` | 24 | 7.5s |  |
| 1091 | `vector_indexof` | 302 | 7.5s |  |
| 1092 | `vector_insertat` | 270 | 7.5s |  |
| 1093 | `vector_int_access` | 4 | 7.5s |  |
| 1094 | `vector_int_delete` | 11 | 7.4s |  |
| 1095 | `vector_join` | 58 | 7.3s |  |
| 1096 | `vector_lastindexof` | 302 | 7.4s |  |
| 1097 | `vector_legacy` | 10 | 7.4s |  |
| 1098 | `vector_map` | 85 | 7.5s |  |
| 1099 | `vector_object_final` | 1 | 7.3s |  |
| 1100 | `vector_object_toString` | 10 | 29.0s |  |
| 1101 | `vector_pushpop` | 255 | 28.9s |  |
| 1102 | `vector_reborrow_bug` | 10 | 8.3s |  |
| 1103 | `vector_removeat` | 172 | 9.3s |  |
| 1104 | `vector_reverse` | 232 | 9.3s |  |
| 1105 | `vector_shiftunshift` | 252 | 8.3s |  |
| 1106 | `vector_slice` | 331 | 9.8s |  |
| 1107 | `vector_sort` | 905 | 17.0s |  |
| 1108 | `vector_splice` | 693 | 11.9s |  |
| 1109 | `vector_splice_fixed_bug_compat` | 4 | 8.2s |  |
| 1110 | `vector_tostring` | 79 | 8.9s |  |
| 1111 | `verification` | 8 | 8.4s |  |
| 1112 | `verify_abnormal_loop` | 1 | 8.3s |  |
| 1113 | `verify_dxns_without_flag` | 3 | 8.6s |  |
| 1114 | `verify_exception_target_two_jumps` | 1 | 8.2s |  |
| 1115 | `verify_exception_targets_edge_case` | 1 | 8.3s |  |
| 1116 | `verify_illegal_opcode` | 1 | 3.5s |  |
| 1117 | `verify_jump_to_middle_of_op` | 1 | 8.2s |  |
| 1118 | `verify_lookup_switch_edge_case` | 1 | 8.2s |  |
| 1119 | `verify_method_info_oob` | 1 | 1.3s |  |
| 1120 | `verify_stack` | 5 | 8.3s |  |
| 1121 | `verify_typecheck` | 4 | 8.3s |  |
| 1122 | `verify_unreachable_exception` | 2 | 8.2s |  |
| 1123 | `versioned_isplaying` | 2 | 8.2s |  |
| 1124 | `virtual_properties` | 16 | 8.4s |  |
| 1125 | `with` | 4 | 8.3s |  |
| 1126 | `wrong_arg_count` | 7 | 8.4s |  |
| 1127 | `xml_abstract_equality` | 36 | 8.5s |  |
| 1128 | `xml_advanced` | 52 | 8.3s |  |
| 1129 | `xml_appendchild` | 10 | 8.3s |  |
| 1130 | `xml_appendchild_swf_v21` | 13 | 8.5s |  |
| 1131 | `xml_as_attribute` | 9 | 8.2s |  |
| 1132 | `xml_attribute` | 35 | 8.3s |  |
| 1133 | `xml_attribute_name` | 40 | 8.3s |  |
| 1134 | `xml_basic` | 33 | 8.3s |  |
| 1135 | `xml_child` | 25 | 8.4s |  |
| 1136 | `xml_childindex` | 7 | 8.3s |  |
| 1137 | `xml_children` | 43 | 8.8s |  |
| 1138 | `xml_class_call` | 9 | 8.2s |  |
| 1139 | `xml_contains` | 197 | 8.2s |  |
| 1140 | `xml_copy` | 20 | 23.5s |  |
| 1141 | `xml_ctor_from_tostring` | 23 | 22.7s |  |
| 1142 | `xml_delete` | 114 | 6.5s |  |
| 1143 | `xml_descendants` | 83 | 6.5s |  |
| 1144 | `xml_elements` | 6 | 6.4s |  |
| 1145 | `xml_equals_namespace_check` | 2 | 6.4s |  |
| 1146 | `xml_explicit_use_namespace` | 5 | 6.5s |  |
| 1147 | `xml_getdescendants_qname` | 21 | 6.5s |  |
| 1148 | `xml_has_property_via_in` | 26 | 6.5s |  |
| 1149 | `xml_hasownproperty` | 6 | 6.4s |  |
| 1150 | `xml_ignore_white` | 6 | 6.5s |  |
| 1151 | `xml_length` | 2 | 6.5s |  |
| 1152 | `xml_list_as_attribute` | 9 | 6.4s |  |
| 1153 | `xml_list_concat` | 20 | 6.5s |  |
| 1154 | `xml_list_ctor_errors` | 34 | 6.5s |  |
| 1155 | `xml_list_delete_clear_parent` | 6 | 6.4s |  |
| 1156 | `xml_list_enumerate` | 4 | 6.4s |  |
| 1157 | `xml_methods_settings` | 3 | 6.4s |  |
| 1158 | `xml_mismatched_tag` | 37 | 6.4s |  |
| 1159 | `xml_namespace` | 39 | 6.4s |  |
| 1160 | `xml_namespace_methods` | 245 | 6.5s |  |
| 1161 | `xml_namespaced_property` | 7 | 6.4s |  |
| 1162 | `xml_no_namespace` | 1 | 6.4s |  |
| 1163 | `xml_nodekind` | 3 | 6.4s |  |
| 1164 | `xml_normalize` | 35 | 6.5s |  |
| 1165 | `xml_notification_bubbling` | 361 | 6.4s |  |
| 1166 | `xml_parent` | 8 | 6.4s |  |
| 1167 | `xml_set_children` | 17 | 6.5s |  |
| 1168 | `xml_set_name` | 34 | 6.5s |  |
| 1169 | `xml_settings` | 6 | 2.2s |  |
| 1170 | `xml_simple_complex_content` | 47 | 6.5s |  |
| 1171 | `xml_socket` | 11 | 6.5s |  |
| 1172 | `xml_text` | 7 | 6.5s |  |
| 1173 | `xml_tostring` | 6 | 6.4s |  |
| 1174 | `xml_tostring_namespace` | 12 | 6.3s |  |
| 1175 | `xml_unescaping` | 23 | 6.5s |  |
| 1176 | `xml_weird_ignores` | 54 | 6.5s |  |
| 1177 | `xml_wildcard` | 11 | 6.4s |  |
| 1178 | `xmldocument` | 254 | 6.5s |  |
| 1179 | `xmlnode` | 3540 | 6.6s |  |
| 1180 | `zero_frame_clip` | 3 | 6.8s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.0s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.0s |  |
| 3 | `blend_transform` | 1 | 1 | 8.6s |  |
| 4 | `bounds_mode` | 6 | 6 | 9.0s |  |
| 5 | `coerce_property` | 3 | 3 | 8.8s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 8.7s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 28.4s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 27.5s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 9.1s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 8.8s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 8.6s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 8.5s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 8.3s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 8.3s |  |
| 15 | `freestanding_superclass` | 2 | 4 | 8.1s |  |
| 16 | `goto_framescript_queued` | 5 | 5 | 27.6s |  |
| 17 | `graphics_draw_path` | 50 | 50 | 28.2s |  |
| 18 | `groupelement_text` | 2 | 2 | 8.4s |  |
| 19 | `int_toexponential` | 76 | 76 | 4.8s |  |
| 20 | `matrix3d_append_rotation` | 1 | 3 | 8.6s |  |
| 21 | `matrix3d_recompose_edge_cases` | 85 | 85 | 8.9s |  |
| 22 | `simplebutton_childevents_script_order` | 4 | 4 | 8.4s |  |
| 23 | `slot_holes_fail` | 1 | 1 | 8.0s |  |
| 24 | `slot_id_exceeds_trait_count` | 1 | 1 | 29.5s |  |
| 25 | `soundchannel_position` | 74 | 74 | 29.2s |  |
| 26 | `soundchannel_soundcomplete` | 10 | 10 | 8.8s |  |
| 27 | `sprite_dropTarget` | 15 | 15 | 8.6s |  |
| 28 | `swf_9_goto_in_construct_frame` | 12 | 12 | 27.2s |  |
| 29 | `textblock_line_changes` | 44 | 44 | 7.6s |  |
| 30 | `textblock_releaselines` | 4 | 4 | 8.6s |  |
| 31 | `uint_toexponential` | 100 | 100 | 7.3s |  |
| 32 | `uncaught_errors_stringified` | 15 | 15 | 7.3s |  |
| 33 | `weird_superinterface_properties` | 1 | 1 | 8.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**21 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 2 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 3 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 4 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 5 | `vector3d_near_equals` | 83.8% | 67 | 80 | 13 |  |
| 6 | `large_preload_from_bytes` | 80.4% | 41 | 51 | 10 |  |
| 7 | `matrix3d_copy_from` | 78.9% | 15 | 19 | 4 |  |
| 8 | `matrix3d_copy_to_matrix3d` | 78.9% | 15 | 19 | 4 |  |
| 9 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 10 | `displayobject_getrect` | 68.8% | 11 | 16 | 5 |  |
| 11 | `number_to_string` | 67.1% | 237 | 353 | 116 |  |
| 12 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 13 | `primitive_keys` | 61.1% | 33 | 54 | 21 |  |
| 14 | `loader_duplicate_class` | 60.4% | 29 | 48 | 19 |  |
| 15 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 16 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 17 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 18 | `bitmapdata_applyfilter_identity` | 50.0% | 2 | 4 | 2 |  |
| 19 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 20 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |
| 21 | `xml_duplicate_attribute` | 50.0% | 7 | 14 | 7 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**48 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 2 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 3 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 4 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 5 | `vector3d_near_equals` | 83.8% | 67/80 | 80 | 80 |  |
| 6 | `large_preload_from_bytes` | 80.4% | 41/51 | 51 | 51 |  |
| 7 | `matrix3d_copy_from` | 78.9% | 15/19 | 16 | 19 |  |
| 8 | `matrix3d_copy_to_matrix3d` | 78.9% | 15/19 | 16 | 19 |  |
| 9 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 10 | `displayobject_getrect` | 68.8% | 11/16 | 16 | 16 |  |
| 11 | `number_to_string` | 67.1% | 237/353 | 353 | 353 |  |
| 12 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 13 | `primitive_keys` | 61.1% | 33/54 | 54 | 54 |  |
| 14 | `loader_duplicate_class` | 60.4% | 29/48 | 48 | 48 |  |
| 15 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 16 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 17 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 18 | `bitmapdata_applyfilter_identity` | 50.0% | 2/4 | 4 | 4 |  |
| 19 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 20 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 21 | `xml_duplicate_attribute` | 50.0% | 7/14 | 14 | 14 |  |
| 22 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 23 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 24 | `bitmapdata_copypixels_alpha_merge` | 33.3% | 3/9 | 9 | 9 |  |
| 25 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 26 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 27 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 28 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 29 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 30 | `bitmapdata_copypixels_alpha_combine` | 15.4% | 2/13 | 13 | 13 |  |
| 31 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 32 | `loader_events_2` | 5.7% | 2/35 | 31 | 35 |  |
| 33 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 34 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 35 | `flash_ui_mouse_cursor` | 2.9% | 1/35 | 3 | 35 |  |
| 36 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 37 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 38 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 39 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 40 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 41 | `matrix3d_append_prepend_scale` | 0.0% | 0/86 | 46 | 86 |  |
| 42 | `matrix3d_interpolate` | 0.0% | 0/21 | 3 | 21 |  |
| 43 | `movieclip_addframescript_error` | 0.0% | 0/9 | 0 | 9 |  |
| 44 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 45 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 46 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 47 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 48 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
