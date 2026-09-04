# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 04:42 UTC

**Git SHA**: `82f27e5f90`

**Run Duration**: 210m 38s

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
| 1 | `abstract_classes` | 132 | 23.5s |  |
| 2 | `accessibility` | 1 | 5.7s |  |
| 3 | `accessibilityimplementation` | 18 | 22.1s |  |
| 4 | `activation_class` | 6 | 5.7s |  |
| 5 | `add` | 1058 | 14.0s |  |
| 6 | `agal_compiler` | 13 | 7.6s |  |
| 7 | `air_datagram_socket` | 1 | 7.4s |  |
| 8 | `air_hidden_lookup` | 2 | 5.8s |  |
| 9 | `air_ifilepromise` | 1 | 5.6s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 5.7s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.5s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.5s |  |
| 13 | `all_classes/display/swf10` | 2569 | 5.9s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.5s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.5s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.5s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.5s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.4s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 5.7s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.4s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.4s |  |
| 22 | `all_classes/errors/swf10` | 140 | 5.7s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.4s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.4s |  |
| 25 | `all_classes/events/swf10` | 1638 | 5.7s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.4s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.4s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.5s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.4s |  |
| 30 | `all_classes/security/swf11` | 3 | 5.7s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.4s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.4s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.4s |  |
| 34 | `all_classes/xml/swf30` | 116 | 6.0s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.4s |  |
| 36 | `amf_array_serialization` | 17 | 24.4s |  |
| 37 | `amf_custom_obj` | 26 | 5.9s |  |
| 38 | `amf_dictionary` | 9 | 5.7s |  |
| 39 | `amf_function` | 46 | 5.8s |  |
| 40 | `amf_invalid_date` | 2 | 5.8s |  |
| 41 | `amf_missing_prop` | 6 | 5.8s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 5.7s |  |
| 43 | `amf_setter_error` | 8 | 6.0s |  |
| 44 | `amf_vector` | 40 | 24.8s |  |
| 45 | `amf_xml` | 6 | 6.1s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 6.4s |  |
| 47 | `application_domain` | 4 | 6.2s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 22.6s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 6.0s |  |
| 50 | `array_access` | 18 | 6.2s |  |
| 51 | `array_access_interpreter` | 4 | 5.9s |  |
| 52 | `array_access_no_pubns` | 2 | 5.9s |  |
| 53 | `array_concat` | 41 | 5.9s |  |
| 54 | `array_constr` | 10 | 6.0s |  |
| 55 | `array_delete` | 44 | 5.8s |  |
| 56 | `array_enumeration` | 10 | 6.4s |  |
| 57 | `array_enumeration_elements` | 11 | 6.0s |  |
| 58 | `array_every` | 8 | 5.9s |  |
| 59 | `array_filter` | 6 | 5.9s |  |
| 60 | `array_foreach` | 18 | 6.0s |  |
| 61 | `array_hasownproperty` | 11 | 5.8s |  |
| 62 | `array_holes` | 9 | 5.8s |  |
| 63 | `array_index_max` | 84 | 5.7s |  |
| 64 | `array_indexof` | 25 | 6.1s |  |
| 65 | `array_join` | 26 | 6.0s |  |
| 66 | `array_lastindexof` | 29 | 6.0s |  |
| 67 | `array_length` | 14 | 5.9s |  |
| 68 | `array_literal` | 3 | 5.9s |  |
| 69 | `array_map` | 8 | 5.7s |  |
| 70 | `array_pop` | 52 | 5.9s |  |
| 71 | `array_push` | 24 | 5.8s |  |
| 72 | `array_reborrow_bug` | 6 | 6.0s |  |
| 73 | `array_reverse` | 28 | 6.1s |  |
| 74 | `array_shift` | 51 | 1.9s |  |
| 75 | `array_slice` | 39 | 6.1s |  |
| 76 | `array_some` | 8 | 5.8s |  |
| 77 | `array_sort` | 297 | 6.4s |  |
| 78 | `array_sort_fun_swf12` | 2 | 6.0s |  |
| 79 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 80 | `array_sort_random` | 210 | 6.0s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 6.5s |  |
| 82 | `array_sorton` | 545 | 6.4s |  |
| 83 | `array_sparse_ops` | 41 | 6.6s |  |
| 84 | `array_splice` | 133 | 27.8s |  |
| 85 | `array_splice2` | 428 | 26.2s |  |
| 86 | `array_splice_types` | 48 | 6.8s |  |
| 87 | `array_storage` | 8 | 6.7s |  |
| 88 | `array_tolocalestring` | 9 | 6.7s |  |
| 89 | `array_tostring` | 12 | 6.7s |  |
| 90 | `array_unshift` | 24 | 6.7s |  |
| 91 | `array_valueof` | 9 | 6.7s |  |
| 92 | `array_vector_null_callback` | 10 | 6.7s |  |
| 93 | `astype` | 28 | 6.7s |  |
| 94 | `astypelate` | 24 | 6.7s |  |
| 95 | `astypelate_propagates` | 1 | 6.6s |  |
| 96 | `asymmetric_key_events` | 11 | 6.6s |  |
| 97 | `automation_classes` | 122 | 7.1s |  |
| 98 | `av_classes` | 340 | 7.0s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 6.8s |  |
| 100 | `avm2_catchup_dobj` | 158 | 7.2s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 82.2s |  |
| 102 | `bevel_filter` | 187 | 6.8s |  |
| 103 | `bitand` | 1058 | 15.8s |  |
| 104 | `bitmap_constr` | 17 | 6.8s |  |
| 105 | `bitmap_data` | 1000 | 13.2s |  |
| 106 | `bitmap_pixelsnapping` | 2 | 25.8s |  |
| 107 | `bitmap_properties` | 23 | 6.9s |  |
| 108 | `bitmap_subclass` | 7 | 8.2s |  |
| 109 | `bitmap_subclass_properties` | 9 | 7.0s |  |
| 110 | `bitmap_timeline` | 9 | 6.8s |  |
| 111 | `bitmapdata_accuracy` | 1 | 52.9s |  |
| 112 | `bitmapdata_applyfilter_blur` | 0 | 26.2s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.0s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | 0 | 26.1s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.0s |  |
| 116 | `bitmapdata_clone` | 13 | 6.7s |  |
| 117 | `bitmapdata_colortransform` | 0 | 6.8s |  |
| 118 | `bitmapdata_colortransform_oob` | 2 | 6.5s |  |
| 119 | `bitmapdata_constr` | 22 | 6.7s |  |
| 120 | `bitmapdata_constructor_from_timeline` | 1 | 7.0s |  |
| 121 | `bitmapdata_copychannel` | 0 | 27.5s |  |
| 122 | `bitmapdata_copypixels` | 23 | 25.9s |  |
| 123 | `bitmapdata_copypixels_blend_over` | 1 | 5.9s |  |
| 124 | `bitmapdata_copypixelstobytearray` | 39 | 5.8s |  |
| 125 | `bitmapdata_dispose` | 7 | 5.8s |  |
| 126 | `bitmapdata_draw` | 0 | 22.4s |  |
| 127 | `bitmapdata_draw_alpha_erase` | 8 | 5.9s |  |
| 128 | `bitmapdata_draw_colortransform` | 0 | 21.8s |  |
| 129 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 22.0s |  |
| 130 | `bitmapdata_draw_filters` | 0 | 22.1s |  |
| 131 | `bitmapdata_draw_masks` | 0 | 6.0s |  |
| 132 | `bitmapdata_draw_rotation` | 0 | 5.9s |  |
| 133 | `bitmapdata_draw_self_via_graphic` | 0 | 5.9s |  |
| 134 | `bitmapdata_draw_stage` | 0 | 22.4s |  |
| 135 | `bitmapdata_drawwithquality` | 0 | 6.3s |  |
| 136 | `bitmapdata_embedded` | 9 | 6.1s |  |
| 137 | `bitmapdata_fillrect` | 0 | 6.1s |  |
| 138 | `bitmapdata_filter_sourcerect` | 0 | 22.4s |  |
| 139 | `bitmapdata_floodfill` | 35 | 5.9s |  |
| 140 | `bitmapdata_getpixels` | 39 | 22.6s |  |
| 141 | `bitmapdata_getvector` | 27 | 2.1s |  |
| 142 | `bitmapdata_histogram` | 59 | 2.1s |  |
| 143 | `bitmapdata_hittest` | 112 | 6.5s |  |
| 144 | `bitmapdata_hittest_threshold` | 18 | 6.1s |  |
| 145 | `bitmapdata_opaque` | 0 | 6.0s |  |
| 146 | `bitmapdata_pixeldissolve` | 1037 | 6.5s |  |
| 147 | `bitmapdata_pixeldissolve_image` | 0 | 6.3s |  |
| 148 | `bitmapdata_rectangle_rounding` | 16 | 6.5s |  |
| 149 | `bitmapdata_setpixels` | 286 | 5.9s |  |
| 150 | `bitmapdata_setvector` | 26 | 5.9s |  |
| 151 | `bitmapdata_sync` | 0 | 22.1s |  |
| 152 | `bitmapdata_threshold` | 176 | 6.6s |  |
| 153 | `bitmapdata_zero_size` | 8 | 6.1s |  |
| 154 | `bitnot` | 46 | 6.0s |  |
| 155 | `bitor` | 1058 | 15.8s |  |
| 156 | `bitxor` | 1058 | 15.6s |  |
| 157 | `blend_mode_null` | 1 | 6.1s |  |
| 158 | `blend_multiply_alpha` | 0 | 6.0s |  |
| 159 | `blend_scroll` | 0 | 6.6s |  |
| 160 | `blend_shader_luma_lighten` | 3 | 6.4s |  |
| 161 | `blur_filter` | 43 | 6.0s |  |
| 162 | `boolean_constr` | 32 | 7.2s |  |
| 163 | `boolean_negation` | 30 | 7.2s |  |
| 164 | `boolean_tostring` | 8 | 7.1s |  |
| 165 | `broadcast_event` | 7 | 7.0s |  |
| 166 | `button_bounds` | 1 | 7.1s |  |
| 167 | `button_hittest` | 2 | 27.0s |  |
| 168 | `button_nested_frame` | 48 | 27.1s |  |
| 169 | `button_nested_frame_simple` | 27 | 7.5s |  |
| 170 | `bytearray` | 48 | 7.4s |  |
| 171 | `bytearray_compress` | 31 | 7.2s |  |
| 172 | `bytearray_errors` | 24 | 7.2s |  |
| 173 | `bytearray_method_serialization` | 1 | 7.1s |  |
| 174 | `bytearray_oom` | 3 | 7.1s |  |
| 175 | `bytearray_readobject_amf0` | 50 | 7.1s |  |
| 176 | `bytearray_readobject_amf3` | 53 | 7.2s |  |
| 177 | `bytearray_readutf8bytes_with_bom` | 16 | 7.2s |  |
| 178 | `bytearray_serialization` | 3 | 7.1s |  |
| 179 | `bytearray_string_null` | 19 | 7.4s |  |
| 180 | `bytearray_tostring` | 15 | 7.1s |  |
| 181 | `bytearray_utf16` | 8 | 7.0s |  |
| 182 | `bytearray_writeobject` | 24 | 6.9s |  |
| 183 | `callee_in_initializer` | 6 | 7.1s |  |
| 184 | `callproplex_class` | 1 | 7.1s |  |
| 185 | `capabilities_resolution` | 8 | 28.1s |  |
| 186 | `catch_class` | 6 | 7.0s |  |
| 187 | `catch_scope_slot` | 7 | 7.2s |  |
| 188 | `checkfilter` | 4 | 2.3s |  |
| 189 | `class_call` | 32 | 7.3s |  |
| 190 | `class_cast_call` | 14 | 7.2s |  |
| 191 | `class_enumeration` | 4 | 7.2s |  |
| 192 | `class_has_own_property` | 2 | 7.2s |  |
| 193 | `class_init_interpreter_mode` | 1 | 7.2s |  |
| 194 | `class_is` | 32 | 7.5s |  |
| 195 | `class_methods` | 5 | 7.2s |  |
| 196 | `class_object_properties` | 10 | 7.3s |  |
| 197 | `class_singleton` | 18 | 7.4s |  |
| 198 | `class_supercalls_errors` | 35 | 7.2s |  |
| 199 | `class_supercalls_mismatched` | 26 | 7.5s |  |
| 200 | `class_superclass_wrong_order` | 1 | 7.2s |  |
| 201 | `class_to_locale_string` | 2 | 7.3s |  |
| 202 | `class_to_string` | 2 | 5.7s |  |
| 203 | `class_value_of` | 2 | 5.5s |  |
| 204 | `click_block` | 5 | 21.0s |  |
| 205 | `click_invisible` | 3 | 5.6s |  |
| 206 | `closures` | 12 | 5.6s |  |
| 207 | `coerce_return_type` | 40 | 5.6s |  |
| 208 | `coerce_return_type_fail` | 2 | 5.5s |  |
| 209 | `coerce_return_void` | 3 | 5.5s |  |
| 210 | `coerce_string` | 86 | 5.7s |  |
| 211 | `coerce_string_precision` | 28 | 5.6s |  |
| 212 | `coerce_to_primitive_side_effects` | 29 | 20.7s |  |
| 213 | `color_matrix_filter` | 19 | 5.6s |  |
| 214 | `construct_errors_swf10` | 8 | 5.6s |  |
| 215 | `construct_frame_list` | 22 | 20.6s |  |
| 216 | `construct_interface` | 3 | 5.7s |  |
| 217 | `constructor_call` | 3 | 5.6s |  |
| 218 | `constructors_vs_timeline` | 5 | 20.8s |  |
| 219 | `constructprop_dynamic_primitive` | 7 | 5.6s |  |
| 220 | `constructprop_method` | 2 | 5.5s |  |
| 221 | `constructsuper_null` | 2 | 5.8s |  |
| 222 | `content_element_basic` | 50 | 5.9s |  |
| 223 | `context3d_creation` | 9 | 5.8s |  |
| 224 | `control_flow_bool` | 4 | 5.5s |  |
| 225 | `control_flow_stricteq` | 8 | 6.1s |  |
| 226 | `convert_boolean` | 30 | 6.1s |  |
| 227 | `convert_integer` | 90 | 5.7s |  |
| 228 | `convert_number` | 56 | 5.7s |  |
| 229 | `convert_uinteger` | 90 | 5.7s |  |
| 230 | `convolution_filter` | 89 | 5.9s |  |
| 231 | `core_exceptions` | 47 | 6.3s |  |
| 232 | `cpool_index_invalid_bytecode_1` | 6 | 5.6s |  |
| 233 | `cpool_index_invalid_bytecode_2` | 3 | 6.1s |  |
| 234 | `cpool_index_invalid_bytecode_3` | 1 | 5.7s |  |
| 235 | `cross_api_version_call_newer` | 12 | 6.0s |  |
| 236 | `cross_api_version_call_older` | 12 | 5.8s |  |
| 237 | `cryptscore` | 11 | 5.6s |  |
| 238 | `currency_parse_result` | 7 | 5.6s |  |
| 239 | `date` | 30 | 5.9s |  |
| 240 | `date_parse` | 36 | 5.7s |  |
| 241 | `declocal` | 46 | 5.7s |  |
| 242 | `declocal_i` | 46 | 7.3s |  |
| 243 | `decode_uri` | 71 | 7.6s |  |
| 244 | `decrement` | 46 | 7.2s |  |
| 245 | `decrement_i` | 46 | 2.5s |  |
| 246 | `default_values` | 7 | 7.2s |  |
| 247 | `delayed_symbolclass` | 28 | 26.8s |  |
| 248 | `describe_type_basic` | 152 | 7.3s |  |
| 249 | `describe_type_json` | 301 | 7.3s |  |
| 250 | `describe_type_metadata` | 125 | 7.3s |  |
| 251 | `describe_type_native` | 23 | 7.2s |  |
| 252 | `dictionary_access` | 62 | 7.4s |  |
| 253 | `dictionary_access_no_pubns` | 2 | 7.1s |  |
| 254 | `dictionary_delete` | 101 | 7.6s |  |
| 255 | `dictionary_foreach` | 42 | 7.4s |  |
| 256 | `dictionary_hasownproperty` | 63 | 7.4s |  |
| 257 | `dictionary_in` | 62 | 7.4s |  |
| 258 | `dictionary_iter_modify` | 8 | 7.2s |  |
| 259 | `dictionary_namespaces` | 36 | 7.3s |  |
| 260 | `displacement_map_filter` | 61 | 7.3s |  |
| 261 | `displayobject_alpha` | 277 | 7.1s |  |
| 262 | `displayobject_blendmode` | 0 | 7.3s |  |
| 263 | `displayobject_colortransform_nested` | 0 | 26.6s |  |
| 264 | `displayobject_early_init` | 54 | 8.7s |  |
| 265 | `displayobject_filters` | 17 | 7.3s |  |
| 266 | `displayobject_from_enterframe` | 1 | 26.5s |  |
| 267 | `displayobject_getbounds_shape` | 0 | 26.5s |  |
| 268 | `displayobject_height` | 6052 | 27.1s |  |
| 269 | `displayobject_hittestobject` | 32 | 7.3s |  |
| 270 | `displayobject_hittestpoint` | 49 | 7.3s |  |
| 271 | `displayobject_hittestpoint_boundary` | 65 | 27.0s |  |
| 272 | `displayobject_hittestpoint_root` | 13 | 7.4s |  |
| 273 | `displayobject_invalid_floats` | 60 | 7.2s |  |
| 274 | `displayobject_invalid_props` | 3 | 7.1s |  |
| 275 | `displayobject_mask` | 3 | 7.2s |  |
| 276 | `displayobject_mask_self_referential` | 0 | 7.2s |  |
| 277 | `displayobject_metaData` | 3 | 7.2s |  |
| 278 | `displayobject_name` | 22 | 26.7s |  |
| 279 | `displayobject_name_from_timeline` | 24 | 7.3s |  |
| 280 | `displayobject_opaque_background` | 6 | 7.3s |  |
| 281 | `displayobject_parent` | 12 | 24.2s |  |
| 282 | `displayobject_root` | 24 | 6.5s |  |
| 283 | `displayobject_rotation` | 1284 | 6.7s |  |
| 284 | `displayobject_scrollrect` | 33 | 6.9s |  |
| 285 | `displayobject_set_matrix_nested` | 0 | 24.4s |  |
| 286 | `displayobject_set_name_loaded` | 3 | 6.8s |  |
| 287 | `displayobject_subclass` | 2 | 6.5s |  |
| 288 | `displayobject_transform` | 89 | 24.2s |  |
| 289 | `displayobject_visible` | 23 | 6.5s |  |
| 290 | `displayobject_width` | 4852 | 24.6s |  |
| 291 | `displayobject_x` | 614 | 6.5s |  |
| 292 | `displayobject_y` | 617 | 6.5s |  |
| 293 | `displayobjectcontainer_addchild` | 32 | 6.6s |  |
| 294 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.5s |  |
| 295 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.7s |  |
| 296 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.6s |  |
| 297 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.6s |  |
| 298 | `displayobjectcontainer_addchildat` | 42 | 6.5s |  |
| 299 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.6s |  |
| 300 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.6s |  |
| 301 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.6s |  |
| 302 | `displayobjectcontainer_contains` | 66 | 24.3s |  |
| 303 | `displayobjectcontainer_getchildat` | 4 | 6.5s |  |
| 304 | `displayobjectcontainer_getchildbyname` | 9 | 6.5s |  |
| 305 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.5s |  |
| 306 | `displayobjectcontainer_getchildindex` | 28 | 6.5s |  |
| 307 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 24.1s |  |
| 308 | `displayobjectcontainer_removechild` | 10 | 6.4s |  |
| 309 | `displayobjectcontainer_removechild_errors` | 4 | 6.5s |  |
| 310 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.5s |  |
| 311 | `displayobjectcontainer_removechildat` | 18 | 6.4s |  |
| 312 | `displayobjectcontainer_removechildren` | 51 | 6.8s |  |
| 313 | `displayobjectcontainer_setchildindex` | 42 | 6.4s |  |
| 314 | `displayobjectcontainer_stopallmovieclips` | 2 | 24.3s |  |
| 315 | `displayobjectcontainer_swapchildren` | 42 | 6.5s |  |
| 316 | `displayobjectcontainer_swapchildrenat` | 42 | 6.5s |  |
| 317 | `displayobjectcontainer_timelineinstance` | 48 | 24.4s |  |
| 318 | `divide` | 1058 | 17.8s |  |
| 319 | `doabc_and_symbolclass_script_init_goto` | 7 | 24.3s |  |
| 320 | `doabc_and_symbolclass_script_init_normal` | 6 | 6.5s |  |
| 321 | `doabc_is_eager` | 1 | 24.1s |  |
| 322 | `documentclass` | 9 | 6.0s |  |
| 323 | `domain_memory` | 133 | 22.8s |  |
| 324 | `drag_drop` | 10 | 5.9s |  |
| 325 | `drop_shadow_filter` | 172 | 6.1s |  |
| 326 | `duplicate_defs` | 1 | 5.6s |  |
| 327 | `eager_init` | 1 | 5.7s |  |
| 328 | `east_asian_justifier_clone` | 8 | 5.8s |  |
| 329 | `edit_text_linkage` | 7 | 6.1s |  |
| 330 | `edittext_align` | 60 | 6.3s |  |
| 331 | `edittext_always_show_selection` | 0 | 22.9s |  |
| 332 | `edittext_antialiastype` | 296 | 6.5s |  |
| 333 | `edittext_at_point_methods_basic` | 16 | 7.2s |  |
| 334 | `edittext_autosize` | 39 | 6.3s |  |
| 335 | `edittext_autosize_align` | 0 | 23.0s |  |
| 336 | `edittext_autosize_height_dynamic` | 60 | 22.3s |  |
| 337 | `edittext_autosize_height_input` | 60 | 6.0s |  |
| 338 | `edittext_autosize_lazy_bounds_events` | 65 | 6.2s |  |
| 339 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.0s |  |
| 340 | `edittext_autosize_lazy_bounds_props` | 490 | 7.4s |  |
| 341 | `edittext_autosize_lazy_bounds_visual` | 0 | 22.1s |  |
| 342 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.1s |  |
| 343 | `edittext_bottom_scroll_v_basic` | 210 | 6.0s |  |
| 344 | `edittext_bounds_scale` | 24 | 22.1s |  |
| 345 | `edittext_bullet` | 30 | 6.0s |  |
| 346 | `edittext_default_format` | 221 | 6.3s |  |
| 347 | `edittext_default_format_empty` | 136 | 6.0s |  |
| 348 | `edittext_empty_text_format` | 7 | 5.9s |  |
| 349 | `edittext_focus_selection` | 5 | 6.0s |  |
| 350 | `edittext_font_size` | 45 | 5.9s |  |
| 351 | `edittext_format_empty_font` | 8 | 5.7s |  |
| 352 | `edittext_get_char_index_at_point` | 4 | 23.3s |  |
| 353 | `edittext_get_line_index_at_point` | 2 | 21.4s |  |
| 354 | `edittext_get_line_index_of_char` | 76 | 6.8s |  |
| 355 | `edittext_getcharboundaries` | 172 | 6.4s |  |
| 356 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.9s |  |
| 357 | `edittext_getcharboundaries_scroll` | 85 | 5.7s |  |
| 358 | `edittext_getlinemetrics` | 146 | 6.2s |  |
| 359 | `edittext_html` | 3101 | 6.1s |  |
| 360 | `edittext_html_condensewhite` | 487 | 5.8s |  |
| 361 | `edittext_html_entity` | 4 | 7.3s |  |
| 362 | `edittext_html_font_size_swf12` | 267 | 26.1s |  |
| 363 | `edittext_html_font_size_swf13` | 273 | 6.7s |  |
| 364 | `edittext_html_roundtrip` | 17 | 7.0s |  |
| 365 | `edittext_ime_focus_lost` | 9 | 26.4s |  |
| 366 | `edittext_input_control` | 12 | 7.1s |  |
| 367 | `edittext_leading` | 9 | 7.5s |  |
| 368 | `edittext_letter_spacing` | 15 | 7.0s |  |
| 369 | `edittext_line_methods` | 294 | 8.4s |  |
| 370 | `edittext_line_metrics` | 11 | 27.3s |  |
| 371 | `edittext_margins` | 25 | 7.0s |  |
| 372 | `edittext_max_scroll_h_basic` | 475 | 7.3s |  |
| 373 | `edittext_max_scroll_v_basic` | 1000 | 7.0s |  |
| 374 | `edittext_mouse_selection` | 363 | 27.0s |  |
| 375 | `edittext_mousedown` | 3 | 7.3s |  |
| 376 | `edittext_mouseenabled` | 26 | 7.0s |  |
| 377 | `edittext_newline_character` | 22 | 6.9s |  |
| 378 | `edittext_newline_stripping` | 64 | 9.7s |  |
| 379 | `edittext_newlines` | 30 | 7.0s |  |
| 380 | `edittext_paragraph_methods` | 257 | 6.9s |  |
| 381 | `edittext_paste_events` | 8 | 6.9s |  |
| 382 | `edittext_paste_maxchars` | 4 | 6.9s |  |
| 383 | `edittext_paste_restrict` | 16 | 6.7s |  |
| 384 | `edittext_restrict` | 191 | 6.9s |  |
| 385 | `edittext_restrict_events` | 22 | 6.9s |  |
| 386 | `edittext_scrollh` | 10 | 7.0s |  |
| 387 | `edittext_selected_text` | 9 | 6.9s |  |
| 388 | `edittext_set_html_same` | 17 | 7.0s |  |
| 389 | `edittext_set_text_vs_html` | 9 | 6.9s |  |
| 390 | `edittext_stylesheet` | 536 | 7.3s |  |
| 391 | `edittext_stylesheet_custom_tag` | 76 | 7.0s |  |
| 392 | `edittext_stylesheet_display` | 272 | 7.1s |  |
| 393 | `edittext_tag_indent` | 49 | 26.6s |  |
| 394 | `edittext_underline` | 40 | 7.2s |  |
| 395 | `edittext_width_height` | 103 | 7.4s |  |
| 396 | `edittext_wordwrap_word` | 150 | 7.1s |  |
| 397 | `edittext_wrap_breaks` | 2375 | 7.6s |  |
| 398 | `element_format_clone` | 44 | 7.2s |  |
| 399 | `element_format_constructor_order` | 64 | 2.6s |  |
| 400 | `element_format_properties` | 235 | 8.0s |  |
| 401 | `empty_bounds` | 1 | 6.9s |  |
| 402 | `encode_uri_surrogate_pair_invalid` | 8 | 26.0s |  |
| 403 | `encode_uri_surrogate_pair_swf11` | 15 | 6.6s |  |
| 404 | `equals` | 512 | 30.0s |  |
| 405 | `error_geterrormessage` | 779 | 7.0s |  |
| 406 | `error_prototype` | 15 | 7.1s |  |
| 407 | `error_stack_trace` | 45 | 7.0s |  |
| 408 | `error_stack_trace_debug_swf17` | 0 | 26.3s |  |
| 409 | `error_stack_trace_debug_swf18` | 0 | 6.8s |  |
| 410 | `error_stack_trace_edge_cases` | 6 | 7.1s |  |
| 411 | `error_stack_trace_release_swf17` | 0 | 7.1s |  |
| 412 | `error_stack_trace_release_swf18` | 0 | 6.8s |  |
| 413 | `error_throwerror` | 103 | 7.2s |  |
| 414 | `error_tostring` | 29 | 7.1s |  |
| 415 | `error_tostring_more` | 86 | 7.2s |  |
| 416 | `es3_inheritance` | 31 | 7.2s |  |
| 417 | `es4_inheritance` | 30 | 7.1s |  |
| 418 | `es4_interfaces` | 30 | 7.2s |  |
| 419 | `es4_method_binding` | 8 | 7.1s |  |
| 420 | `es4_oop_prototypes` | 14 | 7.3s |  |
| 421 | `es4_protected_inheritance` | 6 | 7.1s |  |
| 422 | `escape` | 71 | 7.1s |  |
| 423 | `escape_multi_byte` | 45 | 7.3s |  |
| 424 | `event_bubbles` | 2 | 7.0s |  |
| 425 | `event_cancelable` | 2 | 6.9s |  |
| 426 | `event_clone` | 20 | 7.1s |  |
| 427 | `event_clone_error_redispatch` | 3 | 7.2s |  |
| 428 | `event_clone_on_redispatch` | 10 | 7.2s |  |
| 429 | `event_formattostring` | 31 | 7.2s |  |
| 430 | `event_isdefaultprevented` | 12 | 6.9s |  |
| 431 | `event_target_getter` | 5 | 2.4s |  |
| 432 | `event_target_set` | 9 | 6.9s |  |
| 433 | `event_type` | 1 | 7.1s |  |
| 434 | `event_valueof_tostring` | 18 | 7.2s |  |
| 435 | `eventdispatcher_dispatchevent` | 12 | 7.0s |  |
| 436 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.1s |  |
| 437 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.0s |  |
| 438 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.0s |  |
| 439 | `eventdispatcher_dispatchevent_this` | 5 | 7.0s |  |
| 440 | `eventdispatcher_haseventlistener` | 25 | 7.2s |  |
| 441 | `eventdispatcher_interface_invoke` | 1 | 6.5s |  |
| 442 | `eventdispatcher_tostring` | 10 | 6.5s |  |
| 443 | `eventdispatcher_willtrigger` | 25 | 6.5s |  |
| 444 | `falsiness` | 30 | 6.4s |  |
| 445 | `fast_index_access` | 12 | 6.6s |  |
| 446 | `filefilter_properties` | 4 | 6.5s |  |
| 447 | `filereference_browse_cancel` | 3 | 6.5s |  |
| 448 | `filereference_browse_select` | 9 | 6.5s |  |
| 449 | `filereference_load` | 31 | 6.5s |  |
| 450 | `filereference_save` | 16 | 6.5s |  |
| 451 | `filereference_save_and_browse` | 42 | 6.5s |  |
| 452 | `filereference_save_and_load` | 22 | 6.5s |  |
| 453 | `filereference_uninitialized` | 8 | 6.4s |  |
| 454 | `filereferencelist_browse_cancel` | 6 | 6.4s |  |
| 455 | `filereferencelist_browse_select` | 7 | 6.5s |  |
| 456 | `filter_rewind` | 8 | 24.9s |  |
| 457 | `filters_array_holes` | 25 | 6.5s |  |
| 458 | `finddef` | 3 | 6.4s |  |
| 459 | `findprop_global_prototype` | 6 | 6.5s |  |
| 460 | `flash_media_video_constructor` | 156 | 7.3s |  |
| 461 | `flash_media_video_rotation_probe` | 27 | 6.5s |  |
| 462 | `flash_media_video_setter` | 40 | 6.9s |  |
| 463 | `flash_trace` | 17 | 6.6s |  |
| 464 | `flash_xml` | 29 | 6.5s |  |
| 465 | `flash_xml_cloneNode` | 22 | 6.5s |  |
| 466 | `flash_xml_namespace` | 109 | 6.5s |  |
| 467 | `flash_xml_removeNode` | 60 | 6.5s |  |
| 468 | `focus_events_code` | 161 | 25.2s |  |
| 469 | `focus_events_key_basic` | 132 | 25.1s |  |
| 470 | `focus_events_key_navigation` | 53 | 25.0s |  |
| 471 | `focus_events_key_same_object` | 26 | 6.5s |  |
| 472 | `focus_events_mixed_key_mouse` | 100 | 24.8s |  |
| 473 | `focus_events_mouse_basic` | 260 | 25.0s |  |
| 474 | `focus_events_mouse_focusable` | 112 | 25.2s |  |
| 475 | `focus_events_mouse_same_object` | 40 | 6.5s |  |
| 476 | `focus_remove` | 20 | 24.8s |  |
| 477 | `focus_root_movie` | 4 | 25.0s |  |
| 478 | `focus_stage` | 1 | 6.5s |  |
| 479 | `focusrect` | 18 | 7.1s |  |
| 480 | `focusrect_focuslost` | 9 | 27.8s |  |
| 481 | `focusrect_property` | 110 | 26.2s |  |
| 482 | `font_description_clone` | 14 | 7.0s |  |
| 483 | `font_embedded` | 24 | 26.6s |  |
| 484 | `font_enumeratefonts` | 41 | 7.7s |  |
| 485 | `font_enumeratefonts_filter` | 4 | 7.7s |  |
| 486 | `font_enumeratefonts_order` | 9 | 8.2s |  |
| 487 | `font_hasglyphs` | 40 | 7.5s |  |
| 488 | `font_registerfont` | 129 | 8.1s |  |
| 489 | `framelabel_constr` | 5 | 7.0s |  |
| 490 | `function_call` | 12 | 7.0s |  |
| 491 | `function_call_arguments` | 46 | 7.1s |  |
| 492 | `function_call_arguments_enumerate` | 5 | 6.9s |  |
| 493 | `function_call_coercion` | 108 | 7.4s |  |
| 494 | `function_call_default` | 6 | 7.0s |  |
| 495 | `function_call_rest` | 22 | 7.0s |  |
| 496 | `function_call_types` | 3 | 7.0s |  |
| 497 | `function_call_via_apply` | 11 | 7.0s |  |
| 498 | `function_call_via_call` | 3 | 7.0s |  |
| 499 | `function_display_anonymous` | 7 | 2.4s |  |
| 500 | `function_length` | 6 | 7.0s |  |
| 501 | `function_object` | 2 | 7.0s |  |
| 502 | `function_proto` | 5 | 7.0s |  |
| 503 | `function_proto_created` | 61 | 7.1s |  |
| 504 | `function_to_locale_string` | 4 | 7.0s |  |
| 505 | `function_to_string` | 4 | 6.9s |  |
| 506 | `function_type` | 6 | 7.0s |  |
| 507 | `function_unbound_this` | 51 | 7.1s |  |
| 508 | `function_value_of` | 4 | 7.0s |  |
| 509 | `game_input` | 4 | 7.2s |  |
| 510 | `generate_random_bytes` | 3 | 7.1s |  |
| 511 | `geom_transform` | 74 | 26.9s |  |
| 512 | `get_definition_by_name` | 11 | 7.1s |  |
| 513 | `get_qualified_class_name` | 20 | 7.2s |  |
| 514 | `get_qualified_super_class_name` | 18 | 7.1s |  |
| 515 | `get_slot_edge_cases` | 1 | 7.1s |  |
| 516 | `get_timer` | 2 | 2.4s |  |
| 517 | `getglobalslot` | 1 | 7.0s |  |
| 518 | `getouterscope` | 8 | 7.0s |  |
| 519 | `getouterscope_two_classobjects` | 13 | 7.1s |  |
| 520 | `getter_different_namespace_setter` | 2 | 6.9s |  |
| 521 | `glow_filter` | 127 | 27.1s |  |
| 522 | `goto_button_nested_framescript` | 28 | 25.8s |  |
| 523 | `goto_in_constructframe` | 12 | 25.7s |  |
| 524 | `goto_in_scene_last_frame` | 2 | 25.6s |  |
| 525 | `goto_methods` | 56 | 7.1s |  |
| 526 | `goto_methods_swfver10` | 8 | 6.9s |  |
| 527 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 528 | `goto_nested_framescript` | 9 | 7.0s |  |
| 529 | `goto_on_orphan` | 15 | 7.1s |  |
| 530 | `gradient_bevel_filter` | 206 | 7.0s |  |
| 531 | `gradient_glow_filter` | 206 | 6.9s |  |
| 532 | `graphic_linkage` | 9 | 7.1s |  |
| 533 | `graphics_bad_direct_commands` | 5 | 7.5s |  |
| 534 | `graphics_bitmap_fill` | 0 | 27.4s |  |
| 535 | `graphics_bitmaps` | 0 | 7.2s |  |
| 536 | `graphics_direct_commands` | 0 | 7.1s |  |
| 537 | `graphics_draw_triangles` | 98 | 26.6s |  |
| 538 | `graphics_gradients` | 0 | 7.0s |  |
| 539 | `graphics_gradients_nulls` | 0 | 7.0s |  |
| 540 | `graphics_path` | 56 | 7.0s |  |
| 541 | `graphics_round_rects` | 0 | 6.9s |  |
| 542 | `graphics_simple_shapes` | 0 | 6.9s |  |
| 543 | `greaterequals` | 512 | 10.7s |  |
| 544 | `greaterthan` | 512 | 10.8s |  |
| 545 | `has_own_property` | 102 | 7.4s |  |
| 546 | `hasownproperty_namespaces` | 2 | 6.8s |  |
| 547 | `hello_world` | 1 | 6.8s |  |
| 548 | `hittest_morph` | 30 | 7.0s |  |
| 549 | `if_eq` | 10 | 7.0s |  |
| 550 | `if_gt` | 1 | 7.0s |  |
| 551 | `if_gte` | 10 | 2.4s |  |
| 552 | `if_lt` | 1 | 0.6s |  |
| 553 | `if_lte` | 10 | 6.8s |  |
| 554 | `if_ne` | 7 | 2.4s |  |
| 555 | `if_stricteq` | 6 | 7.0s |  |
| 556 | `if_strictne` | 11 | 7.0s |  |
| 557 | `ime_linux_dead_keys` | 10 | 7.0s |  |
| 558 | `in` | 102 | 7.4s |  |
| 559 | `inclocal` | 46 | 27.8s |  |
| 560 | `inclocal_i` | 46 | 7.2s |  |
| 561 | `increment` | 46 | 7.2s |  |
| 562 | `increment_i` | 46 | 7.2s |  |
| 563 | `indexing_delete` | 75 | 7.2s |  |
| 564 | `init_callee_cached` | 24 | 7.2s |  |
| 565 | `instanceof` | 58 | 7.4s |  |
| 566 | `instantiate_root_character` | 4 | 7.4s |  |
| 567 | `instantiation_on_enter_frame` | 7 | 26.5s |  |
| 568 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.1s |  |
| 569 | `int_constr` | 92 | 7.4s |  |
| 570 | `int_edge_cases` | 19 | 26.3s |  |
| 571 | `int_instanceof` | 3 | 7.0s |  |
| 572 | `int_tofixed` | 1215 | 7.0s |  |
| 573 | `int_toprecision` | 1125 | 7.3s |  |
| 574 | `int_tostring` | 3375 | 7.4s |  |
| 575 | `interactiveobject_enabled` | 25 | 7.1s |  |
| 576 | `interface_namespaces` | 78 | 7.3s |  |
| 577 | `invalid_utf8` | 12 | 7.2s |  |
| 578 | `is_finite` | 46 | 7.2s |  |
| 579 | `is_nan` | 46 | 7.0s |  |
| 580 | `is_prototype_of` | 12 | 7.1s |  |
| 581 | `issue_10221` | 2 | 7.1s |  |
| 582 | `issue_13780` | 12 | 7.2s |  |
| 583 | `issue_14901` | 1 | 7.1s |  |
| 584 | `issue_17675_edittext_paste_maxchars` | 1 | 7.2s |  |
| 585 | `issue_5292` | 5 | 7.2s |  |
| 586 | `issue_8630` | 2 | 7.2s |  |
| 587 | `issue_8630_placeremoveplace` | 15 | 7.2s |  |
| 588 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.2s |  |
| 589 | `issue_8630_scriptremove` | 11 | 7.2s |  |
| 590 | `istype` | 24 | 2.5s |  |
| 591 | `istypelate` | 58 | 7.4s |  |
| 592 | `istypelate_coerce` | 198 | 8.1s |  |
| 593 | `jpeg_loader_context` | 6 | 7.1s |  |
| 594 | `json_errors` | 9 | 26.6s |  |
| 595 | `json_parse` | 21 | 7.2s |  |
| 596 | `json_stringify` | 12 | 7.4s |  |
| 597 | `json_stringify_function` | 12 | 7.2s |  |
| 598 | `json_stringify_order` | 1 | 7.1s |  |
| 599 | `json_version_gated` | 1 | 7.2s |  |
| 600 | `key_input_80percent` | 1812 | 27.6s |  |
| 601 | `key_input_location` | 126 | 6.7s |  |
| 602 | `key_input_numpad` | 384 | 6.7s |  |
| 603 | `large_preload_from_url` | 27 | 8.9s |  |
| 604 | `large_preload_image_from_bytes` | 25 | 7.2s |  |
| 605 | `lazyinit` | 17 | 6.7s |  |
| 606 | `lessequals` | 512 | 10.1s |  |
| 607 | `lessthan` | 512 | 10.1s |  |
| 608 | `loader_bitmap_transparency` | 14 | 6.9s |  |
| 609 | `loader_bytes_unknown_content` | 14 | 6.9s |  |
| 610 | `loader_child_getdefinition` | 5 | 7.0s |  |
| 611 | `loader_duplicate_coerce` | 3 | 7.0s |  |
| 612 | `loader_duplicate_coerce_new_domain` | 4 | 6.9s |  |
| 613 | `loader_error_in_root_ctor` | 4 | 7.0s |  |
| 614 | `loader_events` | 92 | 7.2s |  |
| 615 | `loader_image` | 8 | 6.9s |  |
| 616 | `loader_jpegxr` | 2 | 26.7s |  |
| 617 | `loader_jpegxr_alpha` | 1 | 26.8s |  |
| 618 | `loader_loadbytes_events` | 30 | 7.2s |  |
| 619 | `loader_loadbytes_invalid_png` | 4 | 6.9s |  |
| 620 | `loader_loadbytes_url` | 12 | 7.0s |  |
| 621 | `loader_loaderurl` | 6 | 7.3s |  |
| 622 | `loader_method` | 85 | 6.9s |  |
| 623 | `loader_noninteractive_try_click_root` | 5 | 26.8s |  |
| 624 | `loader_reuse` | 38 | 7.0s |  |
| 625 | `loader_unknown_content` | 24 | 7.0s |  |
| 626 | `loader_visibility_interactive` | 1 | 6.9s |  |
| 627 | `loaderinfo_events` | 7 | 6.8s |  |
| 628 | `loaderinfo_loadurl` | 12 | 6.8s |  |
| 629 | `loaderinfo_more` | 6 | 7.0s |  |
| 630 | `loaderinfo_properties` | 18 | 26.6s |  |
| 631 | `loaderinfo_properties_not_loaded` | 23 | 7.0s |  |
| 632 | `loaderinfo_quine` | 1005 | 6.8s |  |
| 633 | `loaderinfo_root` | 10 | 6.9s |  |
| 634 | `loaderinfo_root_allows` | 2 | 6.8s |  |
| 635 | `localconnection` | 890 | 8.6s |  |
| 636 | `localconnection_send` | 4 | 27.0s |  |
| 637 | `lshift` | 1058 | 19.0s |  |
| 638 | `mask_reapply` | 1 | 25.8s |  |
| 639 | `math` | 497 | 7.1s |  |
| 640 | `matrix` | 338 | 17.5s |  |
| 641 | `matrix3d` | 57 | 26.3s |  |
| 642 | `matrix3d_append` | 16 | 7.0s |  |
| 643 | `matrix3d_append_prepend_translation` | 42 | 6.9s |  |
| 644 | `matrix3d_compose` | 34 | 7.1s |  |
| 645 | `matrix3d_constructor_clone` | 15 | 6.9s |  |
| 646 | `matrix3d_copy_column` | 83 | 7.2s |  |
| 647 | `matrix3d_copy_raw_data_from` | 55 | 2.5s |  |
| 648 | `matrix3d_copy_raw_data_to` | 38 | 7.1s |  |
| 649 | `matrix3d_copy_row` | 83 | 6.8s |  |
| 650 | `matrix3d_determinant` | 182 | 7.0s |  |
| 651 | `matrix3d_invert` | 18 | 6.9s |  |
| 652 | `matrix3d_position` | 19 | 7.0s |  |
| 653 | `matrix3d_precision` | 28 | 7.0s |  |
| 654 | `matrix3d_prepend` | 16 | 6.8s |  |
| 655 | `matrix3d_raw_data` | 33 | 7.0s |  |
| 656 | `matrix3d_transform_vector` | 52 | 7.3s |  |
| 657 | `matrix3d_transpose` | 5 | 6.9s |  |
| 658 | `method_association` | 5 | 7.0s |  |
| 659 | `method_without_body` | 3 | 25.7s |  |
| 660 | `missing_external_interface` | 10 | 6.9s |  |
| 661 | `modulo` | 1058 | 18.8s |  |
| 662 | `morph_shape` | 2 | 25.6s |  |
| 663 | `mouse_children` | 192 | 25.7s |  |
| 664 | `mouse_click_events` | 90 | 25.6s |  |
| 665 | `mouse_double_click_events` | 188 | 6.9s |  |
| 666 | `mouse_empty_parent` | 4 | 6.9s |  |
| 667 | `mouse_over_while_dragging` | 3 | 6.9s |  |
| 668 | `mouse_pick_avm1_root` | 2 | 25.7s |  |
| 669 | `mouse_pick_button_mode` | 2 | 7.0s |  |
| 670 | `mouse_pick_dobj_mask` | 4 | 7.0s |  |
| 671 | `mouse_pick_masking` | 7 | 29.3s |  |
| 672 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 27.3s |  |
| 673 | `mouse_pick_non_interactive_dobj_mask` | 3 | 27.4s |  |
| 674 | `mouse_pick_text` | 8 | 7.4s |  |
| 675 | `mouse_sibling` | 8 | 7.3s |  |
| 676 | `mouse_wheel_events` | 36 | 27.4s |  |
| 677 | `mouseevent_constr` | 66 | 7.1s |  |
| 678 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 679 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 680 | `movieclip_addframescript` | 3 | 26.6s |  |
| 681 | `movieclip_child_property` | 16 | 7.2s |  |
| 682 | `movieclip_constr` | 21 | 7.0s |  |
| 683 | `movieclip_currentlabels` | 17 | 27.4s |  |
| 684 | `movieclip_currentlabels_dupes1` | 46 | 27.6s |  |
| 685 | `movieclip_currentlabels_dupes2` | 30 | 7.2s |  |
| 686 | `movieclip_currentlabels_dupes3` | 67 | 7.3s |  |
| 687 | `movieclip_currentscene` | 12 | 27.2s |  |
| 688 | `movieclip_dispatchevent` | 430 | 7.2s |  |
| 689 | `movieclip_dispatchevent_cancel` | 102 | 7.2s |  |
| 690 | `movieclip_dispatchevent_handlerorder` | 251 | 7.1s |  |
| 691 | `movieclip_dispatchevent_selfadd` | 80 | 7.0s |  |
| 692 | `movieclip_dispatchevent_target` | 899 | 7.2s |  |
| 693 | `movieclip_displayevents` | 96 | 26.6s |  |
| 694 | `movieclip_displayevents_clickgoto` | 676 | 26.9s |  |
| 695 | `movieclip_displayevents_clickgoto2` | 2001 | 7.7s |  |
| 696 | `movieclip_displayevents_clickplay` | 575 | 7.2s |  |
| 697 | `movieclip_displayevents_clicksymbol` | 562 | 7.2s |  |
| 698 | `movieclip_displayevents_constructframegoto` | 140 | 7.4s |  |
| 699 | `movieclip_displayevents_constructframeplay` | 50 | 7.3s |  |
| 700 | `movieclip_displayevents_constructframesymbol` | 144 | 7.3s |  |
| 701 | `movieclip_displayevents_dblhandler` | 21 | 7.2s |  |
| 702 | `movieclip_displayevents_enterframegoto` | 149 | 7.4s |  |
| 703 | `movieclip_displayevents_enterframeplay` | 48 | 7.1s |  |
| 704 | `movieclip_displayevents_enterframesymbol` | 149 | 26.5s |  |
| 705 | `movieclip_displayevents_exitframegoto` | 106 | 7.3s |  |
| 706 | `movieclip_displayevents_exitframeplay` | 44 | 7.2s |  |
| 707 | `movieclip_displayevents_exitframesymbol` | 135 | 7.3s |  |
| 708 | `movieclip_displayevents_looping` | 63 | 27.0s |  |
| 709 | `movieclip_displayevents_stopped` | 113 | 7.4s |  |
| 710 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 711 | `movieclip_displayevents_timeline` | 128 | 7.5s |  |
| 712 | `movieclip_drawrect` | 54 | 22.9s |  |
| 713 | `movieclip_frameconstruct_skipped` | 9 | 5.8s |  |
| 714 | `movieclip_goto_during_frame_script` | 15 | 21.9s |  |
| 715 | `movieclip_goto_overwrite` | 14 | 21.9s |  |
| 716 | `movieclip_goto_scene_last_frame_int` | 1 | 21.5s |  |
| 717 | `movieclip_goto_scene_last_frame_label` | 1 | 6.1s |  |
| 718 | `movieclip_gotoandplay` | 15 | 22.1s |  |
| 719 | `movieclip_gotoandstop` | 13 | 6.0s |  |
| 720 | `movieclip_gotoandstop_children` | 4 | 5.9s |  |
| 721 | `movieclip_gotoandstop_framescripts1` | 4 | 5.8s |  |
| 722 | `movieclip_gotoandstop_framescripts2` | 4 | 2.0s |  |
| 723 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.1s |  |
| 724 | `movieclip_gotoandstop_queueing` | 12 | 22.4s |  |
| 725 | `movieclip_hittest` | 67 | 5.9s |  |
| 726 | `movieclip_next_frame` | 2 | 5.8s |  |
| 727 | `movieclip_next_scene` | 6 | 22.1s |  |
| 728 | `movieclip_play` | 3 | 5.9s |  |
| 729 | `movieclip_prev_frame` | 3 | 5.8s |  |
| 730 | `movieclip_prev_scene` | 7 | 6.1s |  |
| 731 | `movieclip_properties` | 79 | 21.4s |  |
| 732 | `movieclip_queued_noop_goto_swf10` | 9 | 6.0s |  |
| 733 | `movieclip_queued_noop_goto_swf9` | 7 | 0.6s |  |
| 734 | `movieclip_scenes` | 11 | 5.9s |  |
| 735 | `movieclip_soundtransform` | 831 | 23.0s |  |
| 736 | `movieclip_stop` | 1 | 5.8s |  |
| 737 | `movieclip_super_is_symbol` | 20 | 6.1s |  |
| 738 | `movieclip_symbol_constr` | 8 | 6.0s |  |
| 739 | `movieclip_text_mousedown` | 1 | 6.2s |  |
| 740 | `movieclip_willtrigger` | 5 | 5.8s |  |
| 741 | `multiply` | 1058 | 14.8s |  |
| 742 | `namespace_constr` | 253 | 6.1s |  |
| 743 | `namespace_constr_args` | 1 | 5.6s |  |
| 744 | `namespace_enumeration_order` | 7 | 20.9s |  |
| 745 | `nan_scale` | 9 | 5.7s |  |
| 746 | `native_menu_basic` | 19 | 7.7s |  |
| 747 | `navigateToURL_target_normalize` | 107 | 23.0s |  |
| 748 | `negate` | 30 | 5.9s |  |
| 749 | `negative_volume_panned` | 0 | 5.9s |  |
| 750 | `nested_iteration` | 11 | 5.7s |  |
| 751 | `net_getClassByAlias` | 3 | 5.6s |  |
| 752 | `net_navigateToURL` | 57 | 5.7s |  |
| 753 | `net_stream_play_options` | 6 | 5.7s |  |
| 754 | `netconnection_close` | 55 | 27.8s |  |
| 755 | `netconnection_properties` | 78 | 7.3s |  |
| 756 | `netconnection_send_remote` | 50 | 29.4s |  |
| 757 | `netconnection_serialize_arrays` | 6 | 7.2s |  |
| 758 | `netfilterevent` | 10 | 26.4s |  |
| 759 | `netstream_client` | 10 | 7.3s |  |
| 760 | `netstream_connect` | 7 | 7.2s |  |
| 761 | `netstream_flv_date` | 4 | 7.1s |  |
| 762 | `newactivation_in_script_init` | 3 | 7.1s |  |
| 763 | `newclass_mismatched` | 4 | 7.1s |  |
| 764 | `newclass_twice` | 3 | 7.1s |  |
| 765 | `nonconflicting_declarations` | 0 | 7.1s |  |
| 766 | `null_void_types` | 8 | 7.2s |  |
| 767 | `number_autoconv` | 21 | 7.1s |  |
| 768 | `number_autoconv_amf` | 132 | 7.1s |  |
| 769 | `number_autoconv_array_sort_32bit` | 1 | 7.1s |  |
| 770 | `number_constr` | 58 | 7.3s |  |
| 771 | `number_convert_edge_cases` | 180 | 26.6s |  |
| 772 | `number_toexponential` | 378 | 7.2s |  |
| 773 | `number_toexponential2` | 35 | 7.2s |  |
| 774 | `number_tofixed` | 378 | 7.1s |  |
| 775 | `number_toprecision` | 350 | 7.2s |  |
| 776 | `obfuscated_class_names` | 3 | 7.2s |  |
| 777 | `object_enumeration` | 10 | 7.1s |  |
| 778 | `object_prototype` | 4 | 7.2s |  |
| 779 | `object_to_locale_string` | 2 | 7.1s |  |
| 780 | `object_to_string` | 2 | 7.1s |  |
| 781 | `object_value_of` | 2 | 2.2s |  |
| 782 | `op_coerce` | 54 | 7.3s |  |
| 783 | `op_coerce_x` | 54 | 7.2s |  |
| 784 | `op_escxattr` | 2 | 7.2s |  |
| 785 | `op_escxelem` | 2 | 7.2s |  |
| 786 | `op_lookupswitch` | 4 | 7.2s |  |
| 787 | `optimize_coerce` | 1 | 7.1s |  |
| 788 | `orphan_movie_complex` | 80 | 7.6s |  |
| 789 | `orphan_movie_reorder` | 111 | 26.8s |  |
| 790 | `package_namespace` | 7 | 25.4s |  |
| 791 | `param_default_value_has_zero_cpool_index` | 1 | 25.3s |  |
| 792 | `parent_early_access_child` | 16 | 25.6s |  |
| 793 | `parse_float` | 81 | 7.2s |  |
| 794 | `parse_float_swf10` | 81 | 6.8s |  |
| 795 | `parse_int` | 135 | 7.5s |  |
| 796 | `perspective_projection` | 1443 | 26.0s |  |
| 797 | `perspective_projection_basic` | 40 | 6.9s |  |
| 798 | `pixelbender_ceil` | 77 | 7.2s |  |
| 799 | `pixelbender_conditional` | 138 | 7.3s |  |
| 800 | `pixelbender_conversions` | 270 | 7.2s |  |
| 801 | `pixelbender_dithering` | 8 | 30.4s |  |
| 802 | `pixelbender_div` | 36 | 7.1s |  |
| 803 | `pixelbender_effect_BlurredFocus` | 0 | 33.5s |  |
| 804 | `pixelbender_effect_glassDisplace` | 0 | 12.3s |  |
| 805 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 28.7s |  |
| 806 | `pixelbender_effect_smudge` | 0 | 10.1s |  |
| 807 | `pixelbender_effect_tintype` | 0 | 9.3s |  |
| 808 | `pixelbender_effect_twirl` | 0 | 10.7s |  |
| 809 | `pixelbender_eof` | 7 | 6.9s |  |
| 810 | `pixelbender_images` | 0 | 9.0s |  |
| 811 | `pixelbender_input` | 103 | 26.4s |  |
| 812 | `pixelbender_logicalnot` | 20 | 6.9s |  |
| 813 | `pixelbender_malformed_data` | 190 | 26.3s |  |
| 814 | `pixelbender_multiple_out_params` | 1 | 6.8s |  |
| 815 | `pixelbender_no_out_param` | 6 | 6.9s |  |
| 816 | `pixelbender_outputs` | 13 | 7.1s |  |
| 817 | `pixelbender_padding_bytes` | 22 | 7.0s |  |
| 818 | `pixelbender_param_qualifier` | 512 | 7.0s |  |
| 819 | `pixelbender_parameters` | 1563 | 7.3s |  |
| 820 | `pixelbender_parameters_bool` | 240 | 7.2s |  |
| 821 | `pixelbender_parameters_int_vs_bool` | 54 | 7.0s |  |
| 822 | `pixelbender_parse_errors` | 6 | 6.9s |  |
| 823 | `pixelbender_rsqrt` | 24 | 7.0s |  |
| 824 | `pixelbender_select_kinds` | 8 | 7.1s |  |
| 825 | `pixelbender_shaderdata` | 49 | 7.0s |  |
| 826 | `pixelbender_shaderdata_setter` | 99 | 7.3s |  |
| 827 | `pixelbender_sign` | 60 | 7.2s |  |
| 828 | `pixelbender_vector_output` | 11 | 7.2s |  |
| 829 | `place_and_lookup/swf10` | 33 | 7.0s |  |
| 830 | `place_and_lookup/swf9` | 33 | 0.7s |  |
| 831 | `place_multiple` | 17 | 28.6s |  |
| 832 | `place_object_replace` | 9 | 26.8s |  |
| 833 | `place_object_replace_2` | 24 | 26.4s |  |
| 834 | `place_object_same_depth_frame` | 1 | 26.8s |  |
| 835 | `point` | 132 | 7.7s |  |
| 836 | `primitive_edge_cases` | 1 | 7.1s |  |
| 837 | `primitive_toString` | 277 | 7.3s |  |
| 838 | `primitive_valueOf` | 285 | 7.0s |  |
| 839 | `print_job_options` | 3 | 7.2s |  |
| 840 | `property_is_enumerable` | 114 | 7.9s |  |
| 841 | `property_is_enumerable_reset` | 23 | 7.1s |  |
| 842 | `property_priority` | 22 | 7.5s |  |
| 843 | `property_priority_chained` | 4 | 7.1s |  |
| 844 | `property_priority_definition_names_order` | 2 | 7.3s |  |
| 845 | `property_priority_three_level` | 6 | 7.3s |  |
| 846 | `propertyisenumerable_namespaces` | 6 | 7.2s |  |
| 847 | `prototype_set_null` | 7 | 7.1s |  |
| 848 | `proxy_callproperty` | 24 | 7.2s |  |
| 849 | `proxy_deleteproperty` | 64 | 7.3s |  |
| 850 | `proxy_enumeration` | 34 | 7.2s |  |
| 851 | `proxy_getproperty` | 77 | 7.2s |  |
| 852 | `proxy_hasownproperty` | 8 | 7.1s |  |
| 853 | `proxy_hasproperty` | 32 | 7.2s |  |
| 854 | `proxy_not_overridden` | 54 | 7.2s |  |
| 855 | `proxy_serialize` | 9 | 7.2s |  |
| 856 | `proxy_setproperty` | 42 | 7.4s |  |
| 857 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.1s |  |
| 858 | `qname_constr` | 32 | 7.2s |  |
| 859 | `qname_constr_namespace` | 24 | 7.2s |  |
| 860 | `qname_enumeration` | 9 | 7.2s |  |
| 861 | `qname_indexing` | 23 | 7.2s |  |
| 862 | `qname_tostring` | 25 | 7.2s |  |
| 863 | `qname_valueof` | 29 | 7.2s |  |
| 864 | `rectangle` | 1094 | 7.9s |  |
| 865 | `regexp_constr` | 148 | 7.4s |  |
| 866 | `regexp_exec` | 19 | 7.2s |  |
| 867 | `regexp_extended` | 47 | 7.1s |  |
| 868 | `regexp_multiargs` | 1 | 7.1s |  |
| 869 | `regexp_test` | 27 | 7.2s |  |
| 870 | `regexp_toString` | 10 | 7.2s |  |
| 871 | `register_script_refresh` | 35 | 27.2s |  |
| 872 | `remove_child_clear_field` | 88 | 28.9s |  |
| 873 | `remove_dobj` | 3 | 27.0s |  |
| 874 | `resolve_order` | 4 | 7.2s |  |
| 875 | `responder_null_callbacks` | 1 | 27.3s |  |
| 876 | `rng` | 1 | 8.6s |  |
| 877 | `rootless` | 42 | 7.2s |  |
| 878 | `rshift` | 1058 | 19.8s |  |
| 879 | `rtqname_not_namespace` | 12 | 7.4s |  |
| 880 | `sandbox_type_inherited` | 2 | 7.5s |  |
| 881 | `sandbox_type_local_file` | 1 | 7.0s |  |
| 882 | `sandbox_type_local_network` | 1 | 6.8s |  |
| 883 | `scene_constr` | 8 | 7.1s |  |
| 884 | `scope_optimizations` | 4 | 7.0s |  |
| 885 | `scopes_dont_cache/order-1` | 1 | 26.6s |  |
| 886 | `scopes_dont_cache/order-2` | 1 | 0.4s |  |
| 887 | `security_domain_current` | 2 | 7.0s |  |
| 888 | `selection` | 239 | 7.5s |  |
| 889 | `set_local_0` | 31 | 7.3s |  |
| 890 | `set_property_is_enumerable` | 85 | 7.6s |  |
| 891 | `shaderparameter_value` | 4 | 7.2s |  |
| 892 | `shape_drawrect` | 54 | 7.2s |  |
| 893 | `shared_object_no_root` | 3 | 7.0s |  |
| 894 | `simplebutton_added_to_stage` | 45 | 27.3s |  |
| 895 | `simplebutton_childevents` | 86 | 26.9s |  |
| 896 | `simplebutton_childevents_nested` | 54 | 7.4s |  |
| 897 | `simplebutton_childevents_sprite` | 13 | 7.2s |  |
| 898 | `simplebutton_childprops` | 144 | 7.3s |  |
| 899 | `simplebutton_childshuffle` | 23 | 7.0s |  |
| 900 | `simplebutton_constr` | 36 | 7.3s |  |
| 901 | `simplebutton_constr_childevents` | 48 | 7.4s |  |
| 902 | `simplebutton_constr_params` | 42 | 7.3s |  |
| 903 | `simplebutton_mouseenabled` | 26 | 7.2s |  |
| 904 | `simplebutton_multi_children` | 19 | 7.3s |  |
| 905 | `simplebutton_structure` | 27 | 7.2s |  |
| 906 | `simplebutton_symbolclass` | 68 | 7.3s |  |
| 907 | `slot_disp_id_shared_numbering` | 1 | 26.4s |  |
| 908 | `slots_force_autoassigned` | 1 | 26.7s |  |
| 909 | `socket_after_disconnect` | 1 | 7.0s |  |
| 910 | `socket_close` | 2 | 7.0s |  |
| 911 | `socket_connect` | 4 | 7.0s |  |
| 912 | `socket_errors` | 56 | 7.5s |  |
| 913 | `socket_read_big` | 48 | 7.1s |  |
| 914 | `socket_read_little` | 48 | 2.3s |  |
| 915 | `socket_read_write_object` | 8 | 7.0s |  |
| 916 | `socket_write_big` | 15 | 7.4s |  |
| 917 | `socket_write_little` | 14 | 7.1s |  |
| 918 | `sound_constructor_with_args` | 6 | 7.1s |  |
| 919 | `sound_embeddedprops` | 26 | 7.2s |  |
| 920 | `sound_play` | 19 | 7.4s |  |
| 921 | `sound_rootless` | 7 | 7.2s |  |
| 922 | `sound_valueof` | 33 | 7.2s |  |
| 923 | `soundchannel_soundtransform` | 835 | 28.9s |  |
| 924 | `soundchannel_soundtransform_exists` | 5 | 26.8s |  |
| 925 | `soundchannel_stop` | 8 | 27.1s |  |
| 926 | `soundmixer_buffertime` | 5 | 7.2s |  |
| 927 | `soundmixer_stopall` | 6 | 26.4s |  |
| 928 | `soundtransform` | 442 | 12.8s |  |
| 929 | `space_justifier_clone` | 12 | 7.1s |  |
| 930 | `sprite_with_frames` | 0 | 27.4s |  |
| 931 | `stage3d_agal_cross_product` | 0 | 9.7s |  |
| 932 | `stage3d_agal_upload_errors` | 66 | 10.0s |  |
| 933 | `stage3d_bitmap` | 0 | 32.0s |  |
| 934 | `stage3d_blend` | 81 | 29.3s |  |
| 935 | `stage3d_context3d_string_args` | 158 | 8.2s |  |
| 936 | `stage3d_errors` | 7 | 7.2s |  |
| 937 | `stage3d_errors_atf` | 3 | 8.5s |  |
| 938 | `stage3d_errors_swf_29` | 6 | 7.3s |  |
| 939 | `stage3d_float1_index` | 0 | 29.2s |  |
| 940 | `stage3d_fractal` | 0 | 28.9s |  |
| 941 | `stage3d_ignore_sampler_override` | 0 | 29.2s |  |
| 942 | `stage3d_multistage_triangle` | 3 | 9.8s |  |
| 943 | `stage3d_program_constants_bytearray_be` | 0 | 31.2s |  |
| 944 | `stage3d_program_constants_bytearray_le` | 0 | 32.6s |  |
| 945 | `stage3d_program_constants_invalid_input` | 21 | 27.5s |  |
| 946 | `stage3d_raytrace` | 0 | 52.7s |  |
| 947 | `stage3d_rotating_cube` | 0 | 10.4s |  |
| 948 | `stage3d_sampler` | 0 | 9.7s |  |
| 949 | `stage3d_sampler_partial_upload` | 0 | 9.7s |  |
| 950 | `stage3d_stencil` | 0 | 29.5s |  |
| 951 | `stage3d_texture` | 0 | 14.8s |  |
| 952 | `stage3d_texture_bytearray` | 0 | 11.0s |  |
| 953 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.2s |  |
| 954 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.3s |  |
| 955 | `stage3d_triangle` | 0 | 9.7s |  |
| 956 | `stage3d_triangle_bytes4` | 0 | 9.7s |  |
| 957 | `stage3d_triangle_float1` | 0 | 9.7s |  |
| 958 | `stage3d_triangle_index_upload` | 0 | 9.7s |  |
| 959 | `stage3d_x_y` | 22 | 7.1s |  |
| 960 | `stage_access` | 10 | 7.1s |  |
| 961 | `stage_displayobject_properties` | 24 | 6.9s |  |
| 962 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.0s |  |
| 963 | `stage_framerate_nan` | 7 | 7.1s |  |
| 964 | `stage_framerate_negative` | 6 | 7.1s |  |
| 965 | `stage_framerate_zero` | 6 | 7.1s |  |
| 966 | `stage_invalidate` | 38 | 7.3s |  |
| 967 | `stage_loaderinfo_properties` | 24 | 26.7s |  |
| 968 | `stage_mousechildren` | 2 | 7.0s |  |
| 969 | `stage_mouseenabled` | 15 | 7.0s |  |
| 970 | `stage_overriden_setters` | 31 | 7.2s |  |
| 971 | `stage_properties` | 30 | 7.0s |  |
| 972 | `stage_properties2` | 213 | 7.2s |  |
| 973 | `stage_stage3Ds_vector` | 1 | 7.0s |  |
| 974 | `static_length` | 24 | 7.2s |  |
| 975 | `static_text` | 3 | 7.2s |  |
| 976 | `static_var_with_this_in_ctor` | 2 | 7.0s |  |
| 977 | `statictext_text` | 8 | 7.1s |  |
| 978 | `stored_properties` | 11 | 7.1s |  |
| 979 | `strict_equality` | 34 | 7.1s |  |
| 980 | `string_call` | 13 | 7.0s |  |
| 981 | `string_case` | 23 | 7.0s |  |
| 982 | `string_char_at` | 27 | 7.1s |  |
| 983 | `string_char_code_at` | 28 | 7.0s |  |
| 984 | `string_concat_fromcharcode` | 37 | 27.7s |  |
| 985 | `string_constr` | 25 | 26.6s |  |
| 986 | `string_indexof_lastindexof` | 87 | 7.4s |  |
| 987 | `string_length` | 16 | 7.0s |  |
| 988 | `string_locale_compare` | 39 | 7.4s |  |
| 989 | `string_match` | 51 | 7.3s |  |
| 990 | `string_relational_compare` | 4 | 7.0s |  |
| 991 | `string_replace` | 51 | 7.2s |  |
| 992 | `string_search` | 41 | 7.1s |  |
| 993 | `string_slice_substr_substring` | 170 | 8.2s |  |
| 994 | `string_split` | 29 | 7.1s |  |
| 995 | `string_substr_negative` | 21 | 7.0s |  |
| 996 | `string_substr_weird` | 182 | 7.0s |  |
| 997 | `stylesheet` | 221 | 7.7s |  |
| 998 | `stylesheet_parse_color` | 69 | 7.2s |  |
| 999 | `stylesheet_transform` | 307 | 7.5s |  |
| 1000 | `sub_super_same_field` | 12 | 2.5s |  |
| 1001 | `subclass_superclass_linked_symbol` | 4 | 7.8s |  |
| 1002 | `subtract` | 1058 | 19.3s |  |
| 1003 | `super_get_call` | 12 | 7.0s |  |
| 1004 | `supercall_two_classobjects` | 2 | 7.1s |  |
| 1005 | `supercalls_coerce` | 8 | 7.1s |  |
| 1006 | `supercalls_weird` | 2 | 7.0s |  |
| 1007 | `superinterface_call` | 20 | 7.0s |  |
| 1008 | `superinterface_instanceof` | 18 | 7.0s |  |
| 1009 | `swf8` | 1 | 7.0s |  |
| 1010 | `swf_10_queued_goto_scripts_construct` | 52 | 26.6s |  |
| 1011 | `swf_9_goto_in_enter_frame` | 17 | 7.1s |  |
| 1012 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.2s |  |
| 1013 | `swf_9_queued_goto_scripts` | 6 | 26.7s |  |
| 1014 | `swf_9_queued_goto_scripts_construct` | 28 | 0.7s |  |
| 1015 | `swf_9_versioning` | 2 | 7.1s |  |
| 1016 | `swf_wrong_frame_count` | 38 | 7.5s |  |
| 1017 | `swf_wrong_frame_count_isplaying` | 22 | 7.2s |  |
| 1018 | `symbol_class_binary_data` | 8 | 7.2s |  |
| 1019 | `symbol_class_conflict` | 4 | 7.3s |  |
| 1020 | `symbol_class_root_not_zero` | 1 | 7.0s |  |
| 1021 | `symbolclass_invalid_utf8` | 2 | 7.1s |  |
| 1022 | `system_exit` | 3 | 7.0s |  |
| 1023 | `system_setclipboard_null` | 1 | 6.9s |  |
| 1024 | `tab_ordering_arrows` | 998 | 28.4s |  |
| 1025 | `tab_ordering_automatic_advanced` | 184 | 6.1s |  |
| 1026 | `tab_ordering_automatic_basic` | 45 | 26.4s |  |
| 1027 | `tab_ordering_children` | 116 | 6.3s |  |
| 1028 | `tab_ordering_custom_basic` | 34 | 6.2s |  |
| 1029 | `tab_ordering_stage_tab_children` | 32 | 6.0s |  |
| 1030 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.0s |  |
| 1031 | `tab_ordering_tabbable` | 47 | 6.1s |  |
| 1032 | `tabstop_properties` | 105 | 26.6s |  |
| 1033 | `text_element_basic` | 34 | 6.2s |  |
| 1034 | `text_engine_fontdescription` | 27 | 6.3s |  |
| 1035 | `text_engine_groupelement` | 64 | 6.3s |  |
| 1036 | `text_run` | 7 | 6.2s |  |
| 1037 | `textblock_createline_errors` | 23 | 6.2s |  |
| 1038 | `textblock_createline_fte` | 9 | 26.6s |  |
| 1039 | `textblock_properties` | 118 | 6.2s |  |
| 1040 | `textbox_click` | 37 | 26.3s |  |
| 1041 | `textfield_event` | 66 | 6.5s |  |
| 1042 | `textfield_focusin_event` | 9 | 6.2s |  |
| 1043 | `textfield_input_dead_keys_windows` | 15 | 6.3s |  |
| 1044 | `textfield_input_events` | 25 | 17.9s |  |
| 1045 | `textfield_unload` | 39 | 27.2s |  |
| 1046 | `textformat` | 1134 | 6.2s |  |
| 1047 | `textformat_display` | 14 | 6.1s |  |
| 1048 | `textformat_font_max_length` | 4 | 6.3s |  |
| 1049 | `textline_inapplicable_properties` | 10 | 6.1s |  |
| 1050 | `textline_name` | 1 | 6.0s |  |
| 1051 | `textline_raw_text_length` | 30 | 6.0s |  |
| 1052 | `textline_splitting_basic` | 76 | 6.1s |  |
| 1053 | `textline_throwerror` | 30 | 6.0s |  |
| 1054 | `textline_validity` | 162 | 6.3s |  |
| 1055 | `throw` | 3 | 6.2s |  |
| 1056 | `timeline_scripts` | 3 | 26.9s |  |
| 1057 | `timer` | 90 | 6.1s |  |
| 1058 | `timer_events` | 3 | 6.1s |  |
| 1059 | `timer_finished` | 11 | 6.0s |  |
| 1060 | `timer_invalid_delay` | 30 | 6.1s |  |
| 1061 | `timer_reset` | 8 | 28.0s |  |
| 1062 | `timer_setdelay` | 5 | 26.5s |  |
| 1063 | `trace` | 12 | 7.2s |  |
| 1064 | `truthiness` | 30 | 7.2s |  |
| 1065 | `try_catch` | 11 | 7.3s |  |
| 1066 | `try_catch_typed` | 12 | 7.3s |  |
| 1067 | `typeof` | 30 | 7.2s |  |
| 1068 | `uint_constr` | 92 | 7.5s |  |
| 1069 | `uint_tofixed` | 1215 | 7.1s |  |
| 1070 | `uint_toprecision` | 1125 | 7.3s |  |
| 1071 | `uint_tostring` | 3375 | 7.5s |  |
| 1072 | `uncaught_error_basic` | 2 | 7.2s |  |
| 1073 | `unchecked_function` | 15 | 7.2s |  |
| 1074 | `unescape` | 28 | 7.2s |  |
| 1075 | `url_loader` | 25 | 7.3s |  |
| 1076 | `url_vars` | 27 | 7.3s |  |
| 1077 | `urlrequest` | 18 | 7.3s |  |
| 1078 | `urlstream_basic` | 5 | 7.2s |  |
| 1079 | `urshift` | 1058 | 18.6s |  |
| 1080 | `utils3d` | 7 | 7.2s |  |
| 1081 | `vector3d` | 397 | 11.4s |  |
| 1082 | `vector_class` | 36 | 7.6s |  |
| 1083 | `vector_class_call` | 11 | 7.4s |  |
| 1084 | `vector_coercion` | 66 | 8.0s |  |
| 1085 | `vector_concat` | 90 | 7.8s |  |
| 1086 | `vector_constr` | 107 | 7.9s |  |
| 1087 | `vector_enumeration` | 5 | 7.2s |  |
| 1088 | `vector_every` | 92 | 8.0s |  |
| 1089 | `vector_filter` | 95 | 8.0s |  |
| 1090 | `vector_holes` | 24 | 7.3s |  |
| 1091 | `vector_indexof` | 302 | 11.6s |  |
| 1092 | `vector_insertat` | 270 | 8.2s |  |
| 1093 | `vector_int_access` | 4 | 7.2s |  |
| 1094 | `vector_int_delete` | 11 | 7.2s |  |
| 1095 | `vector_join` | 58 | 7.7s |  |
| 1096 | `vector_lastindexof` | 302 | 7.2s |  |
| 1097 | `vector_legacy` | 10 | 7.2s |  |
| 1098 | `vector_map` | 85 | 8.0s |  |
| 1099 | `vector_object_final` | 1 | 7.1s |  |
| 1100 | `vector_object_toString` | 10 | 27.7s |  |
| 1101 | `vector_pushpop` | 255 | 29.1s |  |
| 1102 | `vector_reborrow_bug` | 10 | 7.3s |  |
| 1103 | `vector_removeat` | 172 | 8.3s |  |
| 1104 | `vector_reverse` | 232 | 8.2s |  |
| 1105 | `vector_shiftunshift` | 252 | 6.9s |  |
| 1106 | `vector_slice` | 331 | 8.7s |  |
| 1107 | `vector_sort` | 905 | 16.6s |  |
| 1108 | `vector_splice` | 693 | 11.4s |  |
| 1109 | `vector_splice_fixed_bug_compat` | 4 | 7.4s |  |
| 1110 | `vector_tostring` | 79 | 8.1s |  |
| 1111 | `verification` | 8 | 7.5s |  |
| 1112 | `verify_abnormal_loop` | 1 | 7.2s |  |
| 1113 | `verify_dxns_without_flag` | 3 | 7.5s |  |
| 1114 | `verify_exception_target_two_jumps` | 1 | 7.0s |  |
| 1115 | `verify_exception_targets_edge_case` | 1 | 6.9s |  |
| 1116 | `verify_illegal_opcode` | 1 | 2.7s |  |
| 1117 | `verify_jump_to_middle_of_op` | 1 | 7.2s |  |
| 1118 | `verify_lookup_switch_edge_case` | 1 | 7.0s |  |
| 1119 | `verify_method_info_oob` | 1 | 0.6s |  |
| 1120 | `verify_stack` | 5 | 7.0s |  |
| 1121 | `verify_typecheck` | 4 | 6.9s |  |
| 1122 | `verify_unreachable_exception` | 2 | 6.9s |  |
| 1123 | `versioned_isplaying` | 2 | 7.0s |  |
| 1124 | `virtual_properties` | 16 | 7.0s |  |
| 1125 | `with` | 4 | 7.0s |  |
| 1126 | `wrong_arg_count` | 7 | 7.1s |  |
| 1127 | `xml_abstract_equality` | 36 | 7.2s |  |
| 1128 | `xml_advanced` | 52 | 7.0s |  |
| 1129 | `xml_appendchild` | 10 | 6.9s |  |
| 1130 | `xml_appendchild_swf_v21` | 13 | 7.2s |  |
| 1131 | `xml_as_attribute` | 9 | 6.9s |  |
| 1132 | `xml_attribute` | 35 | 7.1s |  |
| 1133 | `xml_attribute_name` | 40 | 6.9s |  |
| 1134 | `xml_basic` | 33 | 7.0s |  |
| 1135 | `xml_child` | 25 | 7.0s |  |
| 1136 | `xml_childindex` | 7 | 6.9s |  |
| 1137 | `xml_children` | 43 | 7.5s |  |
| 1138 | `xml_class_call` | 9 | 6.9s |  |
| 1139 | `xml_contains` | 197 | 7.1s |  |
| 1140 | `xml_copy` | 20 | 21.9s |  |
| 1141 | `xml_ctor_from_tostring` | 23 | 21.4s |  |
| 1142 | `xml_delete` | 114 | 5.7s |  |
| 1143 | `xml_descendants` | 83 | 5.6s |  |
| 1144 | `xml_elements` | 6 | 5.7s |  |
| 1145 | `xml_equals_namespace_check` | 2 | 5.6s |  |
| 1146 | `xml_explicit_use_namespace` | 5 | 5.7s |  |
| 1147 | `xml_getdescendants_qname` | 21 | 5.8s |  |
| 1148 | `xml_has_property_via_in` | 26 | 5.7s |  |
| 1149 | `xml_hasownproperty` | 6 | 5.5s |  |
| 1150 | `xml_ignore_white` | 6 | 5.8s |  |
| 1151 | `xml_length` | 2 | 5.7s |  |
| 1152 | `xml_list_as_attribute` | 9 | 5.7s |  |
| 1153 | `xml_list_concat` | 20 | 5.8s |  |
| 1154 | `xml_list_ctor_errors` | 34 | 5.7s |  |
| 1155 | `xml_list_delete_clear_parent` | 6 | 5.6s |  |
| 1156 | `xml_list_enumerate` | 4 | 5.7s |  |
| 1157 | `xml_methods_settings` | 3 | 5.8s |  |
| 1158 | `xml_mismatched_tag` | 37 | 5.9s |  |
| 1159 | `xml_namespace` | 39 | 5.8s |  |
| 1160 | `xml_namespace_methods` | 245 | 5.8s |  |
| 1161 | `xml_namespaced_property` | 7 | 5.6s |  |
| 1162 | `xml_no_namespace` | 1 | 5.5s |  |
| 1163 | `xml_nodekind` | 3 | 5.6s |  |
| 1164 | `xml_normalize` | 35 | 5.7s |  |
| 1165 | `xml_notification_bubbling` | 361 | 5.7s |  |
| 1166 | `xml_parent` | 8 | 5.6s |  |
| 1167 | `xml_set_children` | 17 | 5.7s |  |
| 1168 | `xml_set_name` | 34 | 5.6s |  |
| 1169 | `xml_settings` | 6 | 1.9s |  |
| 1170 | `xml_simple_complex_content` | 47 | 5.6s |  |
| 1171 | `xml_socket` | 11 | 5.6s |  |
| 1172 | `xml_text` | 7 | 5.7s |  |
| 1173 | `xml_tostring` | 6 | 5.6s |  |
| 1174 | `xml_tostring_namespace` | 12 | 5.4s |  |
| 1175 | `xml_unescaping` | 23 | 5.6s |  |
| 1176 | `xml_weird_ignores` | 54 | 5.7s |  |
| 1177 | `xml_wildcard` | 11 | 5.6s |  |
| 1178 | `xmldocument` | 254 | 5.6s |  |
| 1179 | `xmlnode` | 3540 | 5.8s |  |
| 1180 | `zero_frame_clip` | 3 | 5.7s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 5.8s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.3s |  |
| 3 | `blend_transform` | 1 | 1 | 6.0s |  |
| 4 | `bounds_mode` | 6 | 6 | 7.5s |  |
| 5 | `coerce_property` | 3 | 3 | 5.7s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.6s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 26.7s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 24.2s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 6.1s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.1s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 6.3s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 7.1s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.0s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 7.1s |  |
| 15 | `freestanding_superclass` | 2 | 4 | 7.0s |  |
| 16 | `goto_framescript_queued` | 5 | 5 | 25.9s |  |
| 17 | `graphics_draw_path` | 50 | 50 | 26.5s |  |
| 18 | `groupelement_text` | 2 | 2 | 7.0s |  |
| 19 | `int_toexponential` | 76 | 76 | 7.3s |  |
| 20 | `matrix3d_append_rotation` | 1 | 3 | 7.0s |  |
| 21 | `matrix3d_recompose_edge_cases` | 85 | 85 | 7.3s |  |
| 22 | `simplebutton_childevents_script_order` | 4 | 4 | 7.3s |  |
| 23 | `slot_holes_fail` | 1 | 1 | 7.0s |  |
| 24 | `slot_id_exceeds_trait_count` | 1 | 1 | 28.1s |  |
| 25 | `soundchannel_position` | 74 | 74 | 27.5s |  |
| 26 | `soundchannel_soundcomplete` | 10 | 10 | 7.3s |  |
| 27 | `sprite_dropTarget` | 15 | 15 | 7.2s |  |
| 28 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.7s |  |
| 29 | `textblock_line_changes` | 44 | 44 | 6.2s |  |
| 30 | `textblock_releaselines` | 4 | 4 | 6.2s |  |
| 31 | `uint_toexponential` | 100 | 100 | 7.4s |  |
| 32 | `uncaught_errors_stringified` | 15 | 15 | 7.2s |  |
| 33 | `weird_superinterface_properties` | 1 | 1 | 6.9s |  |

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
