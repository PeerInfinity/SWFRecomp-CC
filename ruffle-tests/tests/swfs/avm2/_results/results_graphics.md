# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 02:19 UTC

**Git SHA**: `1ccb87a956`

**Run Duration**: 222m 55s

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
| 1 | `abstract_classes` | 132 | 21.9s |  |
| 2 | `accessibility` | 1 | 2.9s |  |
| 3 | `accessibilityimplementation` | 18 | 21.7s |  |
| 4 | `activation_class` | 6 | 6.5s |  |
| 5 | `add` | 1058 | 15.5s |  |
| 6 | `agal_compiler` | 13 | 8.3s |  |
| 7 | `air_datagram_socket` | 1 | 8.1s |  |
| 8 | `air_hidden_lookup` | 2 | 6.7s |  |
| 9 | `air_ifilepromise` | 1 | 6.5s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 6.6s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.1s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.1s |  |
| 13 | `all_classes/display/swf10` | 2569 | 6.8s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.1s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.1s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.1s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.1s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.1s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 6.8s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.1s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.1s |  |
| 22 | `all_classes/errors/swf10` | 140 | 6.6s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.1s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.1s |  |
| 25 | `all_classes/events/swf10` | 1638 | 6.6s |  |
| 26 | `all_classes/events/swf11` | 1750 | 1.1s |  |
| 27 | `all_classes/events/swf12` | 1814 | 1.1s |  |
| 28 | `all_classes/events/swf30` | 2353 | 1.1s |  |
| 29 | `all_classes/events/swf9` | 1030 | 1.1s |  |
| 30 | `all_classes/security/swf11` | 3 | 6.5s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.1s |  |
| 32 | `all_classes/security/swf13` | 53 | 1.1s |  |
| 33 | `all_classes/security/swf30` | 53 | 1.1s |  |
| 34 | `all_classes/xml/swf30` | 116 | 6.5s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.1s |  |
| 36 | `amf_array_serialization` | 17 | 23.5s |  |
| 37 | `amf_custom_obj` | 26 | 6.6s |  |
| 38 | `amf_dictionary` | 9 | 6.5s |  |
| 39 | `amf_function` | 46 | 6.6s |  |
| 40 | `amf_invalid_date` | 2 | 6.5s |  |
| 41 | `amf_missing_prop` | 6 | 6.8s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 6.6s |  |
| 43 | `amf_setter_error` | 8 | 6.6s |  |
| 44 | `amf_vector` | 40 | 28.1s |  |
| 45 | `amf_xml` | 6 | 8.5s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 8.8s |  |
| 47 | `application_domain` | 4 | 8.4s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 27.7s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 8.3s |  |
| 50 | `array_access` | 18 | 8.4s |  |
| 51 | `array_access_interpreter` | 4 | 8.4s |  |
| 52 | `array_access_no_pubns` | 2 | 8.2s |  |
| 53 | `array_concat` | 41 | 3.4s |  |
| 54 | `array_constr` | 10 | 8.3s |  |
| 55 | `array_delete` | 44 | 8.5s |  |
| 56 | `array_enumeration` | 10 | 8.4s |  |
| 57 | `array_enumeration_elements` | 11 | 8.4s |  |
| 58 | `array_every` | 8 | 8.4s |  |
| 59 | `array_filter` | 6 | 8.4s |  |
| 60 | `array_foreach` | 18 | 8.3s |  |
| 61 | `array_hasownproperty` | 11 | 8.4s |  |
| 62 | `array_holes` | 9 | 8.4s |  |
| 63 | `array_index_max` | 84 | 8.3s |  |
| 64 | `array_indexof` | 25 | 8.4s |  |
| 65 | `array_join` | 26 | 8.4s |  |
| 66 | `array_lastindexof` | 29 | 8.4s |  |
| 67 | `array_length` | 14 | 8.3s |  |
| 68 | `array_literal` | 3 | 8.3s |  |
| 69 | `array_map` | 8 | 8.2s |  |
| 70 | `array_pop` | 52 | 8.5s |  |
| 71 | `array_push` | 24 | 8.3s |  |
| 72 | `array_reborrow_bug` | 6 | 8.4s |  |
| 73 | `array_reverse` | 28 | 8.4s |  |
| 74 | `array_shift` | 51 | 3.4s |  |
| 75 | `array_slice` | 39 | 8.4s |  |
| 76 | `array_some` | 8 | 8.4s |  |
| 77 | `array_sort` | 297 | 8.8s |  |
| 78 | `array_sort_fun_swf12` | 2 | 3.3s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 80 | `array_sort_random` | 210 | 8.4s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 8.4s |  |
| 82 | `array_sorton` | 545 | 9.2s |  |
| 83 | `array_sparse_ops` | 41 | 8.6s |  |
| 84 | `array_splice` | 133 | 27.1s |  |
| 85 | `array_splice2` | 428 | 27.0s |  |
| 86 | `array_splice_types` | 48 | 8.1s |  |
| 87 | `array_storage` | 8 | 3.1s |  |
| 88 | `array_tolocalestring` | 9 | 3.1s |  |
| 89 | `array_tostring` | 12 | 8.0s |  |
| 90 | `array_unshift` | 24 | 8.0s |  |
| 91 | `array_valueof` | 9 | 7.9s |  |
| 92 | `array_vector_null_callback` | 10 | 8.0s |  |
| 93 | `astype` | 28 | 8.2s |  |
| 94 | `astypelate` | 24 | 8.2s |  |
| 95 | `astypelate_propagates` | 1 | 8.0s |  |
| 96 | `asymmetric_key_events` | 11 | 8.2s |  |
| 97 | `automation_classes` | 122 | 8.4s |  |
| 98 | `av_classes` | 340 | 8.4s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 8.2s |  |
| 100 | `avm2_catchup_dobj` | 158 | 8.9s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 93.5s |  |
| 102 | `bevel_filter` | 187 | 8.3s |  |
| 103 | `bitand` | 1058 | 20.1s |  |
| 104 | `bitmap_constr` | 17 | 8.3s |  |
| 105 | `bitmap_data` | 1000 | 15.9s |  |
| 106 | `bitmap_pixelsnapping` | 2 | 27.1s |  |
| 107 | `bitmap_properties` | 23 | 8.1s |  |
| 108 | `bitmap_subclass` | 7 | 9.5s |  |
| 109 | `bitmap_subclass_properties` | 9 | 8.5s |  |
| 110 | `bitmap_timeline` | 9 | 8.3s |  |
| 111 | `bitmapdata_accuracy` | 1 | 42.2s |  |
| 112 | `bitmapdata_applyfilter_blur` | 0 | 27.6s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.8s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | 0 | 27.3s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 27.8s |  |
| 116 | `bitmapdata_clone` | 13 | 8.3s |  |
| 117 | `bitmapdata_colortransform` | 0 | 8.5s |  |
| 118 | `bitmapdata_colortransform_oob` | 2 | 8.0s |  |
| 119 | `bitmapdata_constr` | 22 | 3.2s |  |
| 120 | `bitmapdata_constructor_from_timeline` | 1 | 8.4s |  |
| 121 | `bitmapdata_copychannel` | 0 | 28.9s |  |
| 122 | `bitmapdata_copypixels` | 23 | 28.4s |  |
| 123 | `bitmapdata_copypixels_blend_over` | 1 | 7.0s |  |
| 124 | `bitmapdata_copypixelstobytearray` | 39 | 6.9s |  |
| 125 | `bitmapdata_dispose` | 7 | 6.7s |  |
| 126 | `bitmapdata_draw` | 0 | 23.8s |  |
| 127 | `bitmapdata_draw_alpha_erase` | 8 | 6.8s |  |
| 128 | `bitmapdata_draw_colortransform` | 0 | 23.7s |  |
| 129 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 23.5s |  |
| 130 | `bitmapdata_draw_filters` | 0 | 23.1s |  |
| 131 | `bitmapdata_draw_masks` | 0 | 6.8s |  |
| 132 | `bitmapdata_draw_rotation` | 0 | 7.2s |  |
| 133 | `bitmapdata_draw_self_via_graphic` | 0 | 6.8s |  |
| 134 | `bitmapdata_draw_stage` | 0 | 22.9s |  |
| 135 | `bitmapdata_drawwithquality` | 0 | 7.0s |  |
| 136 | `bitmapdata_embedded` | 9 | 7.0s |  |
| 137 | `bitmapdata_fillrect` | 0 | 6.7s |  |
| 138 | `bitmapdata_filter_sourcerect` | 0 | 23.0s |  |
| 139 | `bitmapdata_floodfill` | 35 | 6.5s |  |
| 140 | `bitmapdata_getpixels` | 39 | 22.6s |  |
| 141 | `bitmapdata_getvector` | 27 | 2.3s |  |
| 142 | `bitmapdata_histogram` | 59 | 2.6s |  |
| 143 | `bitmapdata_hittest` | 112 | 7.0s |  |
| 144 | `bitmapdata_hittest_threshold` | 18 | 6.5s |  |
| 145 | `bitmapdata_opaque` | 0 | 6.6s |  |
| 146 | `bitmapdata_pixeldissolve` | 1037 | 7.0s |  |
| 147 | `bitmapdata_pixeldissolve_image` | 0 | 6.8s |  |
| 148 | `bitmapdata_rectangle_rounding` | 16 | 6.5s |  |
| 149 | `bitmapdata_setpixels` | 286 | 6.7s |  |
| 150 | `bitmapdata_setvector` | 26 | 6.7s |  |
| 151 | `bitmapdata_sync` | 0 | 23.3s |  |
| 152 | `bitmapdata_threshold` | 176 | 7.3s |  |
| 153 | `bitmapdata_zero_size` | 8 | 6.5s |  |
| 154 | `bitnot` | 46 | 6.6s |  |
| 155 | `bitor` | 1058 | 14.8s |  |
| 156 | `bitxor` | 1058 | 14.8s |  |
| 157 | `blend_mode_null` | 1 | 6.6s |  |
| 158 | `blend_multiply_alpha` | 0 | 6.8s |  |
| 159 | `blend_scroll` | 0 | 6.8s |  |
| 160 | `blend_shader_luma_lighten` | 3 | 7.4s |  |
| 161 | `blur_filter` | 43 | 7.3s |  |
| 162 | `boolean_constr` | 32 | 7.7s |  |
| 163 | `boolean_negation` | 30 | 7.7s |  |
| 164 | `boolean_tostring` | 8 | 7.6s |  |
| 165 | `broadcast_event` | 7 | 7.4s |  |
| 166 | `button_bounds` | 1 | 7.7s |  |
| 167 | `button_hittest` | 2 | 26.6s |  |
| 168 | `button_nested_frame` | 48 | 26.7s |  |
| 169 | `button_nested_frame_simple` | 27 | 7.9s |  |
| 170 | `bytearray` | 48 | 7.8s |  |
| 171 | `bytearray_compress` | 31 | 7.7s |  |
| 172 | `bytearray_errors` | 24 | 7.8s |  |
| 173 | `bytearray_method_serialization` | 1 | 7.6s |  |
| 174 | `bytearray_oom` | 3 | 7.7s |  |
| 175 | `bytearray_readobject_amf0` | 50 | 7.6s |  |
| 176 | `bytearray_readobject_amf3` | 53 | 7.7s |  |
| 177 | `bytearray_readutf8bytes_with_bom` | 16 | 7.7s |  |
| 178 | `bytearray_serialization` | 3 | 7.6s |  |
| 179 | `bytearray_string_null` | 19 | 7.9s |  |
| 180 | `bytearray_tostring` | 15 | 7.6s |  |
| 181 | `bytearray_utf16` | 8 | 7.6s |  |
| 182 | `bytearray_writeobject` | 24 | 7.5s |  |
| 183 | `callee_in_initializer` | 6 | 7.5s |  |
| 184 | `callproplex_class` | 1 | 7.6s |  |
| 185 | `capabilities_resolution` | 8 | 28.1s |  |
| 186 | `catch_class` | 6 | 2.8s |  |
| 187 | `catch_scope_slot` | 7 | 7.7s |  |
| 188 | `checkfilter` | 4 | 2.7s |  |
| 189 | `class_call` | 32 | 7.7s |  |
| 190 | `class_cast_call` | 14 | 7.6s |  |
| 191 | `class_enumeration` | 4 | 7.5s |  |
| 192 | `class_has_own_property` | 2 | 7.6s |  |
| 193 | `class_init_interpreter_mode` | 1 | 7.6s |  |
| 194 | `class_is` | 32 | 7.7s |  |
| 195 | `class_methods` | 5 | 7.6s |  |
| 196 | `class_object_properties` | 10 | 7.6s |  |
| 197 | `class_singleton` | 18 | 7.6s |  |
| 198 | `class_supercalls_errors` | 35 | 7.8s |  |
| 199 | `class_supercalls_mismatched` | 26 | 7.6s |  |
| 200 | `class_superclass_wrong_order` | 1 | 7.5s |  |
| 201 | `class_to_locale_string` | 2 | 7.6s |  |
| 202 | `class_to_string` | 2 | 6.6s |  |
| 203 | `class_value_of` | 2 | 6.6s |  |
| 204 | `click_block` | 5 | 22.7s |  |
| 205 | `click_invisible` | 3 | 6.7s |  |
| 206 | `closures` | 12 | 6.7s |  |
| 207 | `coerce_return_type` | 40 | 6.7s |  |
| 208 | `coerce_return_type_fail` | 2 | 6.6s |  |
| 209 | `coerce_return_void` | 3 | 6.6s |  |
| 210 | `coerce_string` | 86 | 6.7s |  |
| 211 | `coerce_string_precision` | 28 | 6.6s |  |
| 212 | `coerce_to_primitive_side_effects` | 29 | 22.1s |  |
| 213 | `color_matrix_filter` | 19 | 6.8s |  |
| 214 | `construct_errors_swf10` | 8 | 6.7s |  |
| 215 | `construct_frame_list` | 22 | 22.2s |  |
| 216 | `construct_interface` | 3 | 6.6s |  |
| 217 | `constructor_call` | 3 | 6.6s |  |
| 218 | `constructors_vs_timeline` | 5 | 22.2s |  |
| 219 | `constructprop_dynamic_primitive` | 7 | 6.7s |  |
| 220 | `constructprop_method` | 2 | 6.6s |  |
| 221 | `constructsuper_null` | 2 | 6.6s |  |
| 222 | `content_element_basic` | 50 | 6.9s |  |
| 223 | `context3d_creation` | 9 | 6.7s |  |
| 224 | `control_flow_bool` | 4 | 6.6s |  |
| 225 | `control_flow_stricteq` | 8 | 2.6s |  |
| 226 | `convert_boolean` | 30 | 6.7s |  |
| 227 | `convert_integer` | 90 | 6.7s |  |
| 228 | `convert_number` | 56 | 6.6s |  |
| 229 | `convert_uinteger` | 90 | 6.7s |  |
| 230 | `convolution_filter` | 89 | 6.7s |  |
| 231 | `core_exceptions` | 47 | 7.3s |  |
| 232 | `cpool_index_invalid_bytecode_1` | 6 | 7.2s |  |
| 233 | `cpool_index_invalid_bytecode_2` | 3 | 7.5s |  |
| 234 | `cpool_index_invalid_bytecode_3` | 1 | 7.0s |  |
| 235 | `cross_api_version_call_newer` | 12 | 7.5s |  |
| 236 | `cross_api_version_call_older` | 12 | 6.8s |  |
| 237 | `cryptscore` | 11 | 6.7s |  |
| 238 | `currency_parse_result` | 7 | 6.6s |  |
| 239 | `date` | 30 | 7.0s |  |
| 240 | `date_parse` | 36 | 6.6s |  |
| 241 | `declocal` | 46 | 1.1s |  |
| 242 | `declocal_i` | 46 | 7.6s |  |
| 243 | `decode_uri` | 71 | 7.9s |  |
| 244 | `decrement` | 46 | 7.6s |  |
| 245 | `decrement_i` | 46 | 2.7s |  |
| 246 | `default_values` | 7 | 7.6s |  |
| 247 | `delayed_symbolclass` | 28 | 26.7s |  |
| 248 | `describe_type_basic` | 152 | 7.8s |  |
| 249 | `describe_type_json` | 301 | 7.7s |  |
| 250 | `describe_type_metadata` | 125 | 7.7s |  |
| 251 | `describe_type_native` | 23 | 7.6s |  |
| 252 | `dictionary_access` | 62 | 7.8s |  |
| 253 | `dictionary_access_no_pubns` | 2 | 7.5s |  |
| 254 | `dictionary_delete` | 101 | 8.1s |  |
| 255 | `dictionary_foreach` | 42 | 7.8s |  |
| 256 | `dictionary_hasownproperty` | 63 | 7.8s |  |
| 257 | `dictionary_in` | 62 | 7.8s |  |
| 258 | `dictionary_iter_modify` | 8 | 7.6s |  |
| 259 | `dictionary_namespaces` | 36 | 7.7s |  |
| 260 | `displacement_map_filter` | 61 | 7.8s |  |
| 261 | `displayobject_alpha` | 277 | 7.6s |  |
| 262 | `displayobject_blendmode` | 0 | 7.8s |  |
| 263 | `displayobject_colortransform_nested` | 0 | 26.5s |  |
| 264 | `displayobject_early_init` | 54 | 9.2s |  |
| 265 | `displayobject_filters` | 17 | 7.7s |  |
| 266 | `displayobject_from_enterframe` | 1 | 26.5s |  |
| 267 | `displayobject_getbounds_shape` | 0 | 26.4s |  |
| 268 | `displayobject_height` | 6052 | 26.8s |  |
| 269 | `displayobject_hittestobject` | 32 | 7.8s |  |
| 270 | `displayobject_hittestpoint` | 49 | 7.8s |  |
| 271 | `displayobject_hittestpoint_boundary` | 65 | 26.7s |  |
| 272 | `displayobject_hittestpoint_root` | 13 | 7.8s |  |
| 273 | `displayobject_invalid_floats` | 60 | 7.6s |  |
| 274 | `displayobject_invalid_props` | 3 | 2.7s |  |
| 275 | `displayobject_mask` | 3 | 8.0s |  |
| 276 | `displayobject_mask_self_referential` | 0 | 7.5s |  |
| 277 | `displayobject_metaData` | 3 | 7.5s |  |
| 278 | `displayobject_name` | 22 | 26.3s |  |
| 279 | `displayobject_name_from_timeline` | 24 | 7.7s |  |
| 280 | `displayobject_opaque_background` | 6 | 7.6s |  |
| 281 | `displayobject_parent` | 12 | 24.6s |  |
| 282 | `displayobject_root` | 24 | 7.4s |  |
| 283 | `displayobject_rotation` | 1284 | 7.2s |  |
| 284 | `displayobject_scrollrect` | 33 | 7.8s |  |
| 285 | `displayobject_set_matrix_nested` | 0 | 24.4s |  |
| 286 | `displayobject_set_name_loaded` | 3 | 7.2s |  |
| 287 | `displayobject_subclass` | 2 | 6.8s |  |
| 288 | `displayobject_transform` | 89 | 24.3s |  |
| 289 | `displayobject_visible` | 23 | 7.0s |  |
| 290 | `displayobject_width` | 4852 | 25.1s |  |
| 291 | `displayobject_x` | 614 | 7.0s |  |
| 292 | `displayobject_y` | 617 | 7.0s |  |
| 293 | `displayobjectcontainer_addchild` | 32 | 7.0s |  |
| 294 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.0s |  |
| 295 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.5s |  |
| 296 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.1s |  |
| 297 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.2s |  |
| 298 | `displayobjectcontainer_addchildat` | 42 | 7.1s |  |
| 299 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 2.7s |  |
| 300 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.3s |  |
| 301 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.5s |  |
| 302 | `displayobjectcontainer_contains` | 66 | 24.6s |  |
| 303 | `displayobjectcontainer_getchildat` | 4 | 7.0s |  |
| 304 | `displayobjectcontainer_getchildbyname` | 9 | 7.1s |  |
| 305 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.0s |  |
| 306 | `displayobjectcontainer_getchildindex` | 28 | 7.1s |  |
| 307 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 24.6s |  |
| 308 | `displayobjectcontainer_removechild` | 10 | 7.3s |  |
| 309 | `displayobjectcontainer_removechild_errors` | 4 | 6.8s |  |
| 310 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.0s |  |
| 311 | `displayobjectcontainer_removechildat` | 18 | 7.1s |  |
| 312 | `displayobjectcontainer_removechildren` | 51 | 7.2s |  |
| 313 | `displayobjectcontainer_setchildindex` | 42 | 6.9s |  |
| 314 | `displayobjectcontainer_stopallmovieclips` | 2 | 24.2s |  |
| 315 | `displayobjectcontainer_swapchildren` | 42 | 7.0s |  |
| 316 | `displayobjectcontainer_swapchildrenat` | 42 | 6.8s |  |
| 317 | `displayobjectcontainer_timelineinstance` | 48 | 24.7s |  |
| 318 | `divide` | 1058 | 15.4s |  |
| 319 | `doabc_and_symbolclass_script_init_goto` | 7 | 24.2s |  |
| 320 | `doabc_and_symbolclass_script_init_normal` | 6 | 2.4s |  |
| 321 | `doabc_is_eager` | 1 | 23.8s |  |
| 322 | `documentclass` | 9 | 8.4s |  |
| 323 | `domain_memory` | 133 | 28.8s |  |
| 324 | `drag_drop` | 10 | 8.6s |  |
| 325 | `drop_shadow_filter` | 172 | 8.6s |  |
| 326 | `duplicate_defs` | 1 | 8.1s |  |
| 327 | `eager_init` | 1 | 8.2s |  |
| 328 | `east_asian_justifier_clone` | 8 | 8.2s |  |
| 329 | `edit_text_linkage` | 7 | 8.5s |  |
| 330 | `edittext_align` | 60 | 9.0s |  |
| 331 | `edittext_always_show_selection` | 0 | 28.3s |  |
| 332 | `edittext_antialiastype` | 296 | 8.6s |  |
| 333 | `edittext_at_point_methods_basic` | 16 | 9.6s |  |
| 334 | `edittext_autosize` | 39 | 8.7s |  |
| 335 | `edittext_autosize_align` | 0 | 28.2s |  |
| 336 | `edittext_autosize_height_dynamic` | 60 | 28.1s |  |
| 337 | `edittext_autosize_height_input` | 60 | 8.4s |  |
| 338 | `edittext_autosize_lazy_bounds_events` | 65 | 8.8s |  |
| 339 | `edittext_autosize_lazy_bounds_interactions` | 19 | 8.3s |  |
| 340 | `edittext_autosize_lazy_bounds_props` | 490 | 9.7s |  |
| 341 | `edittext_autosize_lazy_bounds_visual` | 0 | 27.8s |  |
| 342 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 8.4s |  |
| 343 | `edittext_bottom_scroll_v_basic` | 210 | 8.4s |  |
| 344 | `edittext_bounds_scale` | 24 | 27.6s |  |
| 345 | `edittext_bullet` | 30 | 8.6s |  |
| 346 | `edittext_default_format` | 221 | 8.9s |  |
| 347 | `edittext_default_format_empty` | 136 | 8.6s |  |
| 348 | `edittext_empty_text_format` | 7 | 8.3s |  |
| 349 | `edittext_focus_selection` | 5 | 8.2s |  |
| 350 | `edittext_font_size` | 45 | 8.4s |  |
| 351 | `edittext_format_empty_font` | 8 | 3.2s |  |
| 352 | `edittext_get_char_index_at_point` | 4 | 30.9s |  |
| 353 | `edittext_get_line_index_at_point` | 2 | 28.7s |  |
| 354 | `edittext_get_line_index_of_char` | 76 | 9.3s |  |
| 355 | `edittext_getcharboundaries` | 172 | 8.8s |  |
| 356 | `edittext_getcharboundaries_missing_glyphs` | 63 | 8.3s |  |
| 357 | `edittext_getcharboundaries_scroll` | 85 | 8.3s |  |
| 358 | `edittext_getlinemetrics` | 146 | 8.6s |  |
| 359 | `edittext_html` | 3101 | 8.8s |  |
| 360 | `edittext_html_condensewhite` | 487 | 8.3s |  |
| 361 | `edittext_html_entity` | 4 | 8.8s |  |
| 362 | `edittext_html_font_size_swf12` | 267 | 28.4s |  |
| 363 | `edittext_html_font_size_swf13` | 273 | 8.1s |  |
| 364 | `edittext_html_roundtrip` | 17 | 8.4s |  |
| 365 | `edittext_ime_focus_lost` | 9 | 28.2s |  |
| 366 | `edittext_input_control` | 12 | 8.4s |  |
| 367 | `edittext_leading` | 9 | 9.0s |  |
| 368 | `edittext_letter_spacing` | 15 | 8.7s |  |
| 369 | `edittext_line_methods` | 294 | 9.9s |  |
| 370 | `edittext_line_metrics` | 11 | 30.3s |  |
| 371 | `edittext_margins` | 25 | 8.7s |  |
| 372 | `edittext_max_scroll_h_basic` | 475 | 8.7s |  |
| 373 | `edittext_max_scroll_v_basic` | 1000 | 8.6s |  |
| 374 | `edittext_mouse_selection` | 363 | 29.7s |  |
| 375 | `edittext_mousedown` | 3 | 8.9s |  |
| 376 | `edittext_mouseenabled` | 26 | 8.5s |  |
| 377 | `edittext_newline_character` | 22 | 8.4s |  |
| 378 | `edittext_newline_stripping` | 64 | 11.4s |  |
| 379 | `edittext_newlines` | 30 | 8.6s |  |
| 380 | `edittext_paragraph_methods` | 257 | 8.5s |  |
| 381 | `edittext_paste_events` | 8 | 8.4s |  |
| 382 | `edittext_paste_maxchars` | 4 | 8.4s |  |
| 383 | `edittext_paste_restrict` | 16 | 8.3s |  |
| 384 | `edittext_restrict` | 191 | 8.4s |  |
| 385 | `edittext_restrict_events` | 22 | 8.4s |  |
| 386 | `edittext_scrollh` | 10 | 3.4s |  |
| 387 | `edittext_selected_text` | 9 | 8.3s |  |
| 388 | `edittext_set_html_same` | 17 | 8.4s |  |
| 389 | `edittext_set_text_vs_html` | 9 | 8.4s |  |
| 390 | `edittext_stylesheet` | 536 | 8.7s |  |
| 391 | `edittext_stylesheet_custom_tag` | 76 | 8.4s |  |
| 392 | `edittext_stylesheet_display` | 272 | 8.5s |  |
| 393 | `edittext_tag_indent` | 49 | 28.5s |  |
| 394 | `edittext_underline` | 40 | 8.7s |  |
| 395 | `edittext_width_height` | 103 | 8.8s |  |
| 396 | `edittext_wordwrap_word` | 150 | 8.5s |  |
| 397 | `edittext_wrap_breaks` | 2375 | 9.0s |  |
| 398 | `element_format_clone` | 44 | 8.5s |  |
| 399 | `element_format_constructor_order` | 64 | 3.5s |  |
| 400 | `element_format_properties` | 235 | 9.4s |  |
| 401 | `empty_bounds` | 1 | 8.2s |  |
| 402 | `encode_uri_surrogate_pair_invalid` | 8 | 27.8s |  |
| 403 | `encode_uri_surrogate_pair_swf11` | 15 | 8.0s |  |
| 404 | `equals` | 512 | 12.3s |  |
| 405 | `error_geterrormessage` | 779 | 8.2s |  |
| 406 | `error_prototype` | 15 | 8.2s |  |
| 407 | `error_stack_trace` | 45 | 8.2s |  |
| 408 | `error_stack_trace_debug_swf17` | 0 | 27.6s |  |
| 409 | `error_stack_trace_debug_swf18` | 0 | 8.0s |  |
| 410 | `error_stack_trace_edge_cases` | 6 | 8.2s |  |
| 411 | `error_stack_trace_release_swf17` | 0 | 3.3s |  |
| 412 | `error_stack_trace_release_swf18` | 0 | 8.0s |  |
| 413 | `error_throwerror` | 103 | 8.2s |  |
| 414 | `error_tostring` | 29 | 8.2s |  |
| 415 | `error_tostring_more` | 86 | 8.2s |  |
| 416 | `es3_inheritance` | 31 | 8.3s |  |
| 417 | `es4_inheritance` | 30 | 8.2s |  |
| 418 | `es4_interfaces` | 30 | 8.3s |  |
| 419 | `es4_method_binding` | 8 | 3.2s |  |
| 420 | `es4_oop_prototypes` | 14 | 3.4s |  |
| 421 | `es4_protected_inheritance` | 6 | 8.2s |  |
| 422 | `escape` | 71 | 8.3s |  |
| 423 | `escape_multi_byte` | 45 | 8.4s |  |
| 424 | `event_bubbles` | 2 | 8.1s |  |
| 425 | `event_cancelable` | 2 | 8.1s |  |
| 426 | `event_clone` | 20 | 8.2s |  |
| 427 | `event_clone_error_redispatch` | 3 | 8.3s |  |
| 428 | `event_clone_on_redispatch` | 10 | 8.3s |  |
| 429 | `event_formattostring` | 31 | 8.3s |  |
| 430 | `event_isdefaultprevented` | 12 | 8.2s |  |
| 431 | `event_target_getter` | 5 | 3.2s |  |
| 432 | `event_target_set` | 9 | 8.1s |  |
| 433 | `event_type` | 1 | 8.2s |  |
| 434 | `event_valueof_tostring` | 18 | 8.2s |  |
| 435 | `eventdispatcher_dispatchevent` | 12 | 8.2s |  |
| 436 | `eventdispatcher_dispatchevent_cancel` | 20 | 8.2s |  |
| 437 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 8.3s |  |
| 438 | `eventdispatcher_dispatchevent_indirect` | 9 | 8.3s |  |
| 439 | `eventdispatcher_dispatchevent_this` | 5 | 8.2s |  |
| 440 | `eventdispatcher_haseventlistener` | 25 | 8.1s |  |
| 441 | `eventdispatcher_interface_invoke` | 1 | 8.4s |  |
| 442 | `eventdispatcher_tostring` | 10 | 8.4s |  |
| 443 | `eventdispatcher_willtrigger` | 25 | 8.5s |  |
| 444 | `falsiness` | 30 | 8.4s |  |
| 445 | `fast_index_access` | 12 | 8.6s |  |
| 446 | `filefilter_properties` | 4 | 8.4s |  |
| 447 | `filereference_browse_cancel` | 3 | 8.4s |  |
| 448 | `filereference_browse_select` | 9 | 8.5s |  |
| 449 | `filereference_load` | 31 | 3.4s |  |
| 450 | `filereference_save` | 16 | 8.6s |  |
| 451 | `filereference_save_and_browse` | 42 | 8.5s |  |
| 452 | `filereference_save_and_load` | 22 | 8.5s |  |
| 453 | `filereference_uninitialized` | 8 | 8.3s |  |
| 454 | `filereferencelist_browse_cancel` | 6 | 3.3s |  |
| 455 | `filereferencelist_browse_select` | 7 | 8.4s |  |
| 456 | `filter_rewind` | 8 | 27.9s |  |
| 457 | `filters_array_holes` | 25 | 8.5s |  |
| 458 | `finddef` | 3 | 8.4s |  |
| 459 | `findprop_global_prototype` | 6 | 8.4s |  |
| 460 | `flash_media_video_constructor` | 156 | 9.2s |  |
| 461 | `flash_media_video_rotation_probe` | 27 | 8.5s |  |
| 462 | `flash_media_video_setter` | 40 | 8.9s |  |
| 463 | `flash_trace` | 17 | 8.4s |  |
| 464 | `flash_xml` | 29 | 8.5s |  |
| 465 | `flash_xml_cloneNode` | 22 | 8.5s |  |
| 466 | `flash_xml_namespace` | 109 | 8.4s |  |
| 467 | `flash_xml_removeNode` | 60 | 8.4s |  |
| 468 | `focus_events_code` | 161 | 28.9s |  |
| 469 | `focus_events_key_basic` | 132 | 28.5s |  |
| 470 | `focus_events_key_navigation` | 53 | 28.1s |  |
| 471 | `focus_events_key_same_object` | 26 | 8.5s |  |
| 472 | `focus_events_mixed_key_mouse` | 100 | 28.1s |  |
| 473 | `focus_events_mouse_basic` | 260 | 28.6s |  |
| 474 | `focus_events_mouse_focusable` | 112 | 28.3s |  |
| 475 | `focus_events_mouse_same_object` | 40 | 8.4s |  |
| 476 | `focus_remove` | 20 | 27.8s |  |
| 477 | `focus_root_movie` | 4 | 28.2s |  |
| 478 | `focus_stage` | 1 | 8.4s |  |
| 479 | `focusrect` | 18 | 9.3s |  |
| 480 | `focusrect_focuslost` | 9 | 27.9s |  |
| 481 | `focusrect_property` | 110 | 27.0s |  |
| 482 | `font_description_clone` | 14 | 8.1s |  |
| 483 | `font_embedded` | 24 | 27.4s |  |
| 484 | `font_enumeratefonts` | 41 | 8.8s |  |
| 485 | `font_enumeratefonts_filter` | 4 | 8.8s |  |
| 486 | `font_enumeratefonts_order` | 9 | 9.3s |  |
| 487 | `font_hasglyphs` | 40 | 8.6s |  |
| 488 | `font_registerfont` | 129 | 9.1s |  |
| 489 | `framelabel_constr` | 5 | 8.0s |  |
| 490 | `function_call` | 12 | 3.2s |  |
| 491 | `function_call_arguments` | 46 | 8.1s |  |
| 492 | `function_call_arguments_enumerate` | 5 | 8.0s |  |
| 493 | `function_call_coercion` | 108 | 8.5s |  |
| 494 | `function_call_default` | 6 | 8.0s |  |
| 495 | `function_call_rest` | 22 | 8.1s |  |
| 496 | `function_call_types` | 3 | 8.0s |  |
| 497 | `function_call_via_apply` | 11 | 8.0s |  |
| 498 | `function_call_via_call` | 3 | 8.0s |  |
| 499 | `function_display_anonymous` | 7 | 3.1s |  |
| 500 | `function_length` | 6 | 8.0s |  |
| 501 | `function_object` | 2 | 8.0s |  |
| 502 | `function_proto` | 5 | 8.0s |  |
| 503 | `function_proto_created` | 61 | 8.2s |  |
| 504 | `function_to_locale_string` | 4 | 8.1s |  |
| 505 | `function_to_string` | 4 | 8.1s |  |
| 506 | `function_type` | 6 | 8.2s |  |
| 507 | `function_unbound_this` | 51 | 8.3s |  |
| 508 | `function_value_of` | 4 | 3.2s |  |
| 509 | `game_input` | 4 | 8.2s |  |
| 510 | `generate_random_bytes` | 3 | 8.2s |  |
| 511 | `geom_transform` | 74 | 28.5s |  |
| 512 | `get_definition_by_name` | 11 | 8.2s |  |
| 513 | `get_qualified_class_name` | 20 | 8.3s |  |
| 514 | `get_qualified_super_class_name` | 18 | 8.2s |  |
| 515 | `get_slot_edge_cases` | 1 | 8.1s |  |
| 516 | `get_timer` | 2 | 3.2s |  |
| 517 | `getglobalslot` | 1 | 8.2s |  |
| 518 | `getouterscope` | 8 | 8.1s |  |
| 519 | `getouterscope_two_classobjects` | 13 | 8.2s |  |
| 520 | `getter_different_namespace_setter` | 2 | 8.2s |  |
| 521 | `glow_filter` | 127 | 29.6s |  |
| 522 | `goto_button_nested_framescript` | 28 | 30.0s |  |
| 523 | `goto_in_constructframe` | 12 | 29.8s |  |
| 524 | `goto_in_scene_last_frame` | 2 | 29.2s |  |
| 525 | `goto_methods` | 56 | 8.9s |  |
| 526 | `goto_methods_swfver10` | 8 | 8.7s |  |
| 527 | `goto_nested_construct_sibling` | 18 | 9.1s |  |
| 528 | `goto_nested_framescript` | 9 | 8.8s |  |
| 529 | `goto_on_orphan` | 15 | 8.9s |  |
| 530 | `gradient_bevel_filter` | 206 | 8.8s |  |
| 531 | `gradient_glow_filter` | 206 | 8.6s |  |
| 532 | `graphic_linkage` | 9 | 8.9s |  |
| 533 | `graphics_bad_direct_commands` | 5 | 9.6s |  |
| 534 | `graphics_bitmap_fill` | 0 | 31.3s |  |
| 535 | `graphics_bitmaps` | 0 | 9.3s |  |
| 536 | `graphics_direct_commands` | 0 | 9.4s |  |
| 537 | `graphics_draw_triangles` | 98 | 30.0s |  |
| 538 | `graphics_gradients` | 0 | 9.2s |  |
| 539 | `graphics_gradients_nulls` | 0 | 9.1s |  |
| 540 | `graphics_path` | 56 | 8.9s |  |
| 541 | `graphics_round_rects` | 0 | 8.8s |  |
| 542 | `graphics_simple_shapes` | 0 | 9.0s |  |
| 543 | `greaterequals` | 512 | 13.0s |  |
| 544 | `greaterthan` | 512 | 12.9s |  |
| 545 | `has_own_property` | 102 | 9.1s |  |
| 546 | `hasownproperty_namespaces` | 2 | 8.7s |  |
| 547 | `hello_world` | 1 | 8.8s |  |
| 548 | `hittest_morph` | 30 | 8.8s |  |
| 549 | `if_eq` | 10 | 8.6s |  |
| 550 | `if_gt` | 1 | 8.5s |  |
| 551 | `if_gte` | 10 | 3.5s |  |
| 552 | `if_lt` | 1 | 1.4s |  |
| 553 | `if_lte` | 10 | 8.5s |  |
| 554 | `if_ne` | 7 | 3.6s |  |
| 555 | `if_stricteq` | 6 | 8.6s |  |
| 556 | `if_strictne` | 11 | 8.6s |  |
| 557 | `ime_linux_dead_keys` | 10 | 8.8s |  |
| 558 | `in` | 102 | 9.0s |  |
| 559 | `inclocal` | 46 | 20.0s |  |
| 560 | `inclocal_i` | 46 | 1.1s |  |
| 561 | `increment` | 46 | 1.1s |  |
| 562 | `increment_i` | 46 | 1.2s |  |
| 563 | `indexing_delete` | 75 | 1.1s |  |
| 564 | `init_callee_cached` | 24 | 1.1s |  |
| 565 | `instanceof` | 58 | 1.1s |  |
| 566 | `instantiate_root_character` | 4 | 1.2s |  |
| 567 | `instantiation_on_enter_frame` | 7 | 20.2s |  |
| 568 | `instantiation_on_enterframe_gotoandstop` | 8 | 1.1s |  |
| 569 | `int_constr` | 92 | 1.1s |  |
| 570 | `int_edge_cases` | 19 | 20.0s |  |
| 571 | `int_instanceof` | 3 | 1.1s |  |
| 572 | `int_tofixed` | 1215 | 1.1s |  |
| 573 | `int_toprecision` | 1125 | 1.1s |  |
| 574 | `int_tostring` | 3375 | 1.1s |  |
| 575 | `interactiveobject_enabled` | 25 | 1.1s |  |
| 576 | `interface_namespaces` | 78 | 1.1s |  |
| 577 | `invalid_utf8` | 12 | 1.1s |  |
| 578 | `is_finite` | 46 | 1.1s |  |
| 579 | `is_nan` | 46 | 1.1s |  |
| 580 | `is_prototype_of` | 12 | 1.1s |  |
| 581 | `issue_10221` | 2 | 1.1s |  |
| 582 | `issue_13780` | 12 | 1.1s |  |
| 583 | `issue_14901` | 1 | 1.1s |  |
| 584 | `issue_17675_edittext_paste_maxchars` | 1 | 1.1s |  |
| 585 | `issue_5292` | 5 | 1.1s |  |
| 586 | `issue_8630` | 2 | 1.1s |  |
| 587 | `issue_8630_placeremoveplace` | 15 | 1.1s |  |
| 588 | `issue_8630_placeremoveplace_scriptremove` | 16 | 1.2s |  |
| 589 | `issue_8630_scriptremove` | 11 | 1.2s |  |
| 590 | `istype` | 24 | 1.1s |  |
| 591 | `istypelate` | 58 | 1.1s |  |
| 592 | `istypelate_coerce` | 198 | 1.2s |  |
| 593 | `jpeg_loader_context` | 6 | 1.2s |  |
| 594 | `json_errors` | 9 | 20.2s |  |
| 595 | `json_parse` | 21 | 1.1s |  |
| 596 | `json_stringify` | 12 | 1.1s |  |
| 597 | `json_stringify_function` | 12 | 1.1s |  |
| 598 | `json_stringify_order` | 1 | 1.1s |  |
| 599 | `json_version_gated` | 1 | 1.1s |  |
| 600 | `key_input_80percent` | 1812 | 27.6s |  |
| 601 | `key_input_location` | 126 | 3.2s |  |
| 602 | `key_input_numpad` | 384 | 8.1s |  |
| 603 | `large_preload_from_url` | 27 | 10.4s |  |
| 604 | `large_preload_image_from_bytes` | 25 | 8.7s |  |
| 605 | `lazyinit` | 17 | 8.2s |  |
| 606 | `lessequals` | 512 | 12.2s |  |
| 607 | `lessthan` | 512 | 12.2s |  |
| 608 | `loader_bitmap_transparency` | 14 | 3.3s |  |
| 609 | `loader_bytes_unknown_content` | 14 | 8.3s |  |
| 610 | `loader_child_getdefinition` | 5 | 8.5s |  |
| 611 | `loader_duplicate_coerce` | 3 | 8.7s |  |
| 612 | `loader_duplicate_coerce_new_domain` | 4 | 8.6s |  |
| 613 | `loader_error_in_root_ctor` | 4 | 8.6s |  |
| 614 | `loader_events` | 92 | 9.2s |  |
| 615 | `loader_image` | 8 | 9.0s |  |
| 616 | `loader_jpegxr` | 2 | 29.2s |  |
| 617 | `loader_jpegxr_alpha` | 1 | 28.8s |  |
| 618 | `loader_loadbytes_events` | 30 | 8.9s |  |
| 619 | `loader_loadbytes_invalid_png` | 4 | 8.3s |  |
| 620 | `loader_loadbytes_url` | 12 | 8.4s |  |
| 621 | `loader_loaderurl` | 6 | 8.8s |  |
| 622 | `loader_method` | 85 | 8.3s |  |
| 623 | `loader_noninteractive_try_click_root` | 5 | 28.1s |  |
| 624 | `loader_reuse` | 38 | 8.6s |  |
| 625 | `loader_unknown_content` | 24 | 8.4s |  |
| 626 | `loader_visibility_interactive` | 1 | 8.4s |  |
| 627 | `loaderinfo_events` | 7 | 8.2s |  |
| 628 | `loaderinfo_loadurl` | 12 | 8.3s |  |
| 629 | `loaderinfo_more` | 6 | 8.6s |  |
| 630 | `loaderinfo_properties` | 18 | 28.4s |  |
| 631 | `loaderinfo_properties_not_loaded` | 23 | 8.8s |  |
| 632 | `loaderinfo_quine` | 1005 | 8.6s |  |
| 633 | `loaderinfo_root` | 10 | 8.6s |  |
| 634 | `loaderinfo_root_allows` | 2 | 8.6s |  |
| 635 | `localconnection` | 890 | 10.9s |  |
| 636 | `localconnection_send` | 4 | 27.1s |  |
| 637 | `lshift` | 1058 | 20.2s |  |
| 638 | `mask_reapply` | 1 | 27.5s |  |
| 639 | `math` | 497 | 8.3s |  |
| 640 | `matrix` | 338 | 19.2s |  |
| 641 | `matrix3d` | 57 | 27.9s |  |
| 642 | `matrix3d_append` | 16 | 8.1s |  |
| 643 | `matrix3d_append_prepend_translation` | 42 | 8.1s |  |
| 644 | `matrix3d_compose` | 34 | 8.3s |  |
| 645 | `matrix3d_constructor_clone` | 15 | 8.1s |  |
| 646 | `matrix3d_copy_column` | 83 | 8.4s |  |
| 647 | `matrix3d_copy_raw_data_from` | 55 | 3.4s |  |
| 648 | `matrix3d_copy_raw_data_to` | 38 | 8.3s |  |
| 649 | `matrix3d_copy_row` | 83 | 8.0s |  |
| 650 | `matrix3d_determinant` | 182 | 8.3s |  |
| 651 | `matrix3d_invert` | 18 | 3.2s |  |
| 652 | `matrix3d_position` | 19 | 8.2s |  |
| 653 | `matrix3d_precision` | 28 | 8.2s |  |
| 654 | `matrix3d_prepend` | 16 | 8.0s |  |
| 655 | `matrix3d_raw_data` | 33 | 8.2s |  |
| 656 | `matrix3d_transform_vector` | 52 | 8.5s |  |
| 657 | `matrix3d_transpose` | 5 | 8.1s |  |
| 658 | `method_association` | 5 | 8.2s |  |
| 659 | `method_without_body` | 3 | 27.1s |  |
| 660 | `missing_external_interface` | 10 | 8.1s |  |
| 661 | `modulo` | 1058 | 20.3s |  |
| 662 | `morph_shape` | 2 | 27.1s |  |
| 663 | `mouse_children` | 192 | 27.5s |  |
| 664 | `mouse_click_events` | 90 | 26.9s |  |
| 665 | `mouse_double_click_events` | 188 | 8.1s |  |
| 666 | `mouse_empty_parent` | 4 | 8.1s |  |
| 667 | `mouse_over_while_dragging` | 3 | 8.1s |  |
| 668 | `mouse_pick_avm1_root` | 2 | 27.3s |  |
| 669 | `mouse_pick_button_mode` | 2 | 8.2s |  |
| 670 | `mouse_pick_dobj_mask` | 4 | 8.7s |  |
| 671 | `mouse_pick_masking` | 7 | 28.2s |  |
| 672 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 28.4s |  |
| 673 | `mouse_pick_non_interactive_dobj_mask` | 3 | 28.8s |  |
| 674 | `mouse_pick_text` | 8 | 8.6s |  |
| 675 | `mouse_sibling` | 8 | 8.5s |  |
| 676 | `mouse_wheel_events` | 36 | 29.4s |  |
| 677 | `mouseevent_constr` | 66 | 8.4s |  |
| 678 | `mouseevent_stagexy` | 35 | 8.5s |  |
| 679 | `mouseevent_valueof_tostring` | 28 | 8.5s |  |
| 680 | `movieclip_addframescript` | 3 | 28.7s |  |
| 681 | `movieclip_child_property` | 16 | 8.5s |  |
| 682 | `movieclip_constr` | 21 | 8.4s |  |
| 683 | `movieclip_currentlabels` | 17 | 28.3s |  |
| 684 | `movieclip_currentlabels_dupes1` | 46 | 28.3s |  |
| 685 | `movieclip_currentlabels_dupes2` | 30 | 8.4s |  |
| 686 | `movieclip_currentlabels_dupes3` | 67 | 8.5s |  |
| 687 | `movieclip_currentscene` | 12 | 28.2s |  |
| 688 | `movieclip_dispatchevent` | 430 | 8.6s |  |
| 689 | `movieclip_dispatchevent_cancel` | 102 | 8.6s |  |
| 690 | `movieclip_dispatchevent_handlerorder` | 251 | 8.5s |  |
| 691 | `movieclip_dispatchevent_selfadd` | 80 | 8.5s |  |
| 692 | `movieclip_dispatchevent_target` | 899 | 8.5s |  |
| 693 | `movieclip_displayevents` | 96 | 28.4s |  |
| 694 | `movieclip_displayevents_clickgoto` | 676 | 28.7s |  |
| 695 | `movieclip_displayevents_clickgoto2` | 2001 | 9.1s |  |
| 696 | `movieclip_displayevents_clickplay` | 575 | 8.7s |  |
| 697 | `movieclip_displayevents_clicksymbol` | 562 | 8.7s |  |
| 698 | `movieclip_displayevents_constructframegoto` | 140 | 8.9s |  |
| 699 | `movieclip_displayevents_constructframeplay` | 50 | 8.7s |  |
| 700 | `movieclip_displayevents_constructframesymbol` | 144 | 8.7s |  |
| 701 | `movieclip_displayevents_dblhandler` | 21 | 3.6s |  |
| 702 | `movieclip_displayevents_enterframegoto` | 149 | 8.6s |  |
| 703 | `movieclip_displayevents_enterframeplay` | 48 | 8.4s |  |
| 704 | `movieclip_displayevents_enterframesymbol` | 149 | 28.6s |  |
| 705 | `movieclip_displayevents_exitframegoto` | 106 | 8.6s |  |
| 706 | `movieclip_displayevents_exitframeplay` | 44 | 8.5s |  |
| 707 | `movieclip_displayevents_exitframesymbol` | 135 | 8.6s |  |
| 708 | `movieclip_displayevents_looping` | 63 | 28.7s |  |
| 709 | `movieclip_displayevents_stopped` | 113 | 8.8s |  |
| 710 | `movieclip_displayevents_swap` | 96 | 3.2s |  |
| 711 | `movieclip_displayevents_timeline` | 128 | 8.8s |  |
| 712 | `movieclip_drawrect` | 54 | 27.3s |  |
| 713 | `movieclip_frameconstruct_skipped` | 9 | 8.0s |  |
| 714 | `movieclip_goto_during_frame_script` | 15 | 27.0s |  |
| 715 | `movieclip_goto_overwrite` | 14 | 27.4s |  |
| 716 | `movieclip_goto_scene_last_frame_int` | 1 | 27.3s |  |
| 717 | `movieclip_goto_scene_last_frame_label` | 1 | 3.1s |  |
| 718 | `movieclip_gotoandplay` | 15 | 27.8s |  |
| 719 | `movieclip_gotoandstop` | 13 | 8.3s |  |
| 720 | `movieclip_gotoandstop_children` | 4 | 8.3s |  |
| 721 | `movieclip_gotoandstop_framescripts1` | 4 | 8.2s |  |
| 722 | `movieclip_gotoandstop_framescripts2` | 4 | 3.3s |  |
| 723 | `movieclip_gotoandstop_framescripts_self` | 7 | 27.8s |  |
| 724 | `movieclip_gotoandstop_queueing` | 12 | 27.9s |  |
| 725 | `movieclip_hittest` | 67 | 8.4s |  |
| 726 | `movieclip_next_frame` | 2 | 8.1s |  |
| 727 | `movieclip_next_scene` | 6 | 27.2s |  |
| 728 | `movieclip_play` | 3 | 3.1s |  |
| 729 | `movieclip_prev_frame` | 3 | 8.1s |  |
| 730 | `movieclip_prev_scene` | 7 | 8.3s |  |
| 731 | `movieclip_properties` | 79 | 27.8s |  |
| 732 | `movieclip_queued_noop_goto_swf10` | 9 | 8.3s |  |
| 733 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 734 | `movieclip_scenes` | 11 | 8.2s |  |
| 735 | `movieclip_soundtransform` | 831 | 29.8s |  |
| 736 | `movieclip_stop` | 1 | 8.1s |  |
| 737 | `movieclip_super_is_symbol` | 20 | 8.4s |  |
| 738 | `movieclip_symbol_constr` | 8 | 8.2s |  |
| 739 | `movieclip_text_mousedown` | 1 | 8.2s |  |
| 740 | `movieclip_willtrigger` | 5 | 8.2s |  |
| 741 | `multiply` | 1058 | 20.0s |  |
| 742 | `namespace_constr` | 253 | 8.4s |  |
| 743 | `namespace_constr_args` | 1 | 8.0s |  |
| 744 | `namespace_enumeration_order` | 7 | 27.0s |  |
| 745 | `nan_scale` | 9 | 8.1s |  |
| 746 | `native_menu_basic` | 19 | 10.4s |  |
| 747 | `navigateToURL_target_normalize` | 107 | 29.6s |  |
| 748 | `negate` | 30 | 8.3s |  |
| 749 | `negative_volume_panned` | 0 | 8.5s |  |
| 750 | `nested_iteration` | 11 | 8.1s |  |
| 751 | `net_getClassByAlias` | 3 | 8.2s |  |
| 752 | `net_navigateToURL` | 57 | 8.3s |  |
| 753 | `net_stream_play_options` | 6 | 8.2s |  |
| 754 | `netconnection_close` | 55 | 27.6s |  |
| 755 | `netconnection_properties` | 78 | 8.3s |  |
| 756 | `netconnection_send_remote` | 50 | 30.2s |  |
| 757 | `netconnection_serialize_arrays` | 6 | 8.2s |  |
| 758 | `netfilterevent` | 10 | 27.2s |  |
| 759 | `netstream_client` | 10 | 8.2s |  |
| 760 | `netstream_connect` | 7 | 8.1s |  |
| 761 | `netstream_flv_date` | 4 | 8.2s |  |
| 762 | `newactivation_in_script_init` | 3 | 7.9s |  |
| 763 | `newclass_mismatched` | 4 | 8.0s |  |
| 764 | `newclass_twice` | 3 | 8.0s |  |
| 765 | `nonconflicting_declarations` | 0 | 8.0s |  |
| 766 | `null_void_types` | 8 | 8.1s |  |
| 767 | `number_autoconv` | 21 | 3.2s |  |
| 768 | `number_autoconv_amf` | 132 | 8.1s |  |
| 769 | `number_autoconv_array_sort_32bit` | 1 | 8.0s |  |
| 770 | `number_constr` | 58 | 8.2s |  |
| 771 | `number_convert_edge_cases` | 180 | 26.9s |  |
| 772 | `number_toexponential` | 378 | 8.1s |  |
| 773 | `number_toexponential2` | 35 | 8.0s |  |
| 774 | `number_tofixed` | 378 | 8.0s |  |
| 775 | `number_toprecision` | 350 | 8.1s |  |
| 776 | `obfuscated_class_names` | 3 | 8.1s |  |
| 777 | `object_enumeration` | 10 | 8.0s |  |
| 778 | `object_prototype` | 4 | 8.2s |  |
| 779 | `object_to_locale_string` | 2 | 8.2s |  |
| 780 | `object_to_string` | 2 | 8.1s |  |
| 781 | `object_value_of` | 2 | 3.0s |  |
| 782 | `op_coerce` | 54 | 3.2s |  |
| 783 | `op_coerce_x` | 54 | 8.2s |  |
| 784 | `op_escxattr` | 2 | 8.2s |  |
| 785 | `op_escxelem` | 2 | 8.2s |  |
| 786 | `op_lookupswitch` | 4 | 8.2s |  |
| 787 | `optimize_coerce` | 1 | 8.1s |  |
| 788 | `orphan_movie_complex` | 80 | 8.6s |  |
| 789 | `orphan_movie_reorder` | 111 | 27.6s |  |
| 790 | `package_namespace` | 7 | 26.6s |  |
| 791 | `param_default_value_has_zero_cpool_index` | 1 | 21.7s |  |
| 792 | `parent_early_access_child` | 16 | 26.8s |  |
| 793 | `parse_float` | 81 | 7.9s |  |
| 794 | `parse_float_swf10` | 81 | 7.6s |  |
| 795 | `parse_int` | 135 | 8.2s |  |
| 796 | `perspective_projection` | 1443 | 26.8s |  |
| 797 | `perspective_projection_basic` | 40 | 7.7s |  |
| 798 | `pixelbender_ceil` | 77 | 7.8s |  |
| 799 | `pixelbender_conditional` | 138 | 8.0s |  |
| 800 | `pixelbender_conversions` | 270 | 8.0s |  |
| 801 | `pixelbender_dithering` | 8 | 32.9s |  |
| 802 | `pixelbender_div` | 36 | 7.9s |  |
| 803 | `pixelbender_effect_BlurredFocus` | 0 | 35.0s |  |
| 804 | `pixelbender_effect_glassDisplace` | 0 | 14.1s |  |
| 805 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 31.2s |  |
| 806 | `pixelbender_effect_smudge` | 0 | 11.2s |  |
| 807 | `pixelbender_effect_tintype` | 0 | 10.3s |  |
| 808 | `pixelbender_effect_twirl` | 0 | 12.0s |  |
| 809 | `pixelbender_eof` | 7 | 7.7s |  |
| 810 | `pixelbender_images` | 0 | 10.1s |  |
| 811 | `pixelbender_input` | 103 | 27.5s |  |
| 812 | `pixelbender_logicalnot` | 20 | 7.7s |  |
| 813 | `pixelbender_malformed_data` | 190 | 27.7s |  |
| 814 | `pixelbender_multiple_out_params` | 1 | 2.8s |  |
| 815 | `pixelbender_no_out_param` | 6 | 7.7s |  |
| 816 | `pixelbender_outputs` | 13 | 7.9s |  |
| 817 | `pixelbender_padding_bytes` | 22 | 7.8s |  |
| 818 | `pixelbender_param_qualifier` | 512 | 7.8s |  |
| 819 | `pixelbender_parameters` | 1563 | 8.0s |  |
| 820 | `pixelbender_parameters_bool` | 240 | 3.0s |  |
| 821 | `pixelbender_parameters_int_vs_bool` | 54 | 7.8s |  |
| 822 | `pixelbender_parse_errors` | 6 | 7.7s |  |
| 823 | `pixelbender_rsqrt` | 24 | 7.8s |  |
| 824 | `pixelbender_select_kinds` | 8 | 7.9s |  |
| 825 | `pixelbender_shaderdata` | 49 | 7.7s |  |
| 826 | `pixelbender_shaderdata_setter` | 99 | 8.1s |  |
| 827 | `pixelbender_sign` | 60 | 7.9s |  |
| 828 | `pixelbender_vector_output` | 11 | 7.8s |  |
| 829 | `place_and_lookup/swf10` | 33 | 7.7s |  |
| 830 | `place_and_lookup/swf9` | 33 | 1.1s |  |
| 831 | `place_multiple` | 17 | 26.8s |  |
| 832 | `place_object_replace` | 9 | 26.9s |  |
| 833 | `place_object_replace_2` | 24 | 26.6s |  |
| 834 | `place_object_same_depth_frame` | 1 | 28.2s |  |
| 835 | `point` | 132 | 8.6s |  |
| 836 | `primitive_edge_cases` | 1 | 8.0s |  |
| 837 | `primitive_toString` | 277 | 3.2s |  |
| 838 | `primitive_valueOf` | 285 | 7.9s |  |
| 839 | `print_job_options` | 3 | 8.1s |  |
| 840 | `property_is_enumerable` | 114 | 8.6s |  |
| 841 | `property_is_enumerable_reset` | 23 | 7.8s |  |
| 842 | `property_priority` | 22 | 8.2s |  |
| 843 | `property_priority_chained` | 4 | 7.7s |  |
| 844 | `property_priority_definition_names_order` | 2 | 7.9s |  |
| 845 | `property_priority_three_level` | 6 | 7.8s |  |
| 846 | `propertyisenumerable_namespaces` | 6 | 7.6s |  |
| 847 | `prototype_set_null` | 7 | 7.7s |  |
| 848 | `proxy_callproperty` | 24 | 7.7s |  |
| 849 | `proxy_deleteproperty` | 64 | 7.7s |  |
| 850 | `proxy_enumeration` | 34 | 7.7s |  |
| 851 | `proxy_getproperty` | 77 | 7.7s |  |
| 852 | `proxy_hasownproperty` | 8 | 7.7s |  |
| 853 | `proxy_hasproperty` | 32 | 7.7s |  |
| 854 | `proxy_not_overridden` | 54 | 7.7s |  |
| 855 | `proxy_serialize` | 9 | 7.7s |  |
| 856 | `proxy_setproperty` | 42 | 7.8s |  |
| 857 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.6s |  |
| 858 | `qname_constr` | 32 | 7.7s |  |
| 859 | `qname_constr_namespace` | 24 | 7.7s |  |
| 860 | `qname_enumeration` | 9 | 7.6s |  |
| 861 | `qname_indexing` | 23 | 7.7s |  |
| 862 | `qname_tostring` | 25 | 7.6s |  |
| 863 | `qname_valueof` | 29 | 7.7s |  |
| 864 | `rectangle` | 1094 | 8.2s |  |
| 865 | `regexp_constr` | 148 | 3.0s |  |
| 866 | `regexp_exec` | 19 | 7.7s |  |
| 867 | `regexp_extended` | 47 | 7.6s |  |
| 868 | `regexp_multiargs` | 1 | 7.7s |  |
| 869 | `regexp_test` | 27 | 3.0s |  |
| 870 | `regexp_toString` | 10 | 7.9s |  |
| 871 | `register_script_refresh` | 35 | 28.4s |  |
| 872 | `remove_child_clear_field` | 88 | 29.0s |  |
| 873 | `remove_dobj` | 3 | 27.8s |  |
| 874 | `resolve_order` | 4 | 8.5s |  |
| 875 | `responder_null_callbacks` | 1 | 29.0s |  |
| 876 | `rng` | 1 | 9.8s |  |
| 877 | `rootless` | 42 | 8.6s |  |
| 878 | `rshift` | 1058 | 20.9s |  |
| 879 | `rtqname_not_namespace` | 12 | 8.4s |  |
| 880 | `sandbox_type_inherited` | 2 | 8.9s |  |
| 881 | `sandbox_type_local_file` | 1 | 8.5s |  |
| 882 | `sandbox_type_local_network` | 1 | 8.4s |  |
| 883 | `scene_constr` | 8 | 8.7s |  |
| 884 | `scope_optimizations` | 4 | 8.7s |  |
| 885 | `scopes_dont_cache/order-1` | 1 | 28.8s |  |
| 886 | `scopes_dont_cache/order-2` | 1 | 1.1s |  |
| 887 | `security_domain_current` | 2 | 3.4s |  |
| 888 | `selection` | 239 | 9.5s |  |
| 889 | `set_local_0` | 31 | 8.8s |  |
| 890 | `set_property_is_enumerable` | 85 | 9.4s |  |
| 891 | `shaderparameter_value` | 4 | 8.7s |  |
| 892 | `shape_drawrect` | 54 | 8.9s |  |
| 893 | `shared_object_no_root` | 3 | 8.6s |  |
| 894 | `simplebutton_added_to_stage` | 45 | 30.3s |  |
| 895 | `simplebutton_childevents` | 86 | 29.9s |  |
| 896 | `simplebutton_childevents_nested` | 54 | 8.8s |  |
| 897 | `simplebutton_childevents_sprite` | 13 | 8.3s |  |
| 898 | `simplebutton_childprops` | 144 | 8.4s |  |
| 899 | `simplebutton_childshuffle` | 23 | 8.1s |  |
| 900 | `simplebutton_constr` | 36 | 8.4s |  |
| 901 | `simplebutton_constr_childevents` | 48 | 8.4s |  |
| 902 | `simplebutton_constr_params` | 42 | 8.3s |  |
| 903 | `simplebutton_mouseenabled` | 26 | 8.2s |  |
| 904 | `simplebutton_multi_children` | 19 | 8.4s |  |
| 905 | `simplebutton_structure` | 27 | 8.3s |  |
| 906 | `simplebutton_symbolclass` | 68 | 8.4s |  |
| 907 | `slot_disp_id_shared_numbering` | 1 | 27.4s |  |
| 908 | `slots_force_autoassigned` | 1 | 28.0s |  |
| 909 | `socket_after_disconnect` | 1 | 8.2s |  |
| 910 | `socket_close` | 2 | 3.2s |  |
| 911 | `socket_connect` | 4 | 8.2s |  |
| 912 | `socket_errors` | 56 | 8.8s |  |
| 913 | `socket_read_big` | 48 | 8.3s |  |
| 914 | `socket_read_little` | 48 | 3.1s |  |
| 915 | `socket_read_write_object` | 8 | 8.2s |  |
| 916 | `socket_write_big` | 15 | 8.6s |  |
| 917 | `socket_write_little` | 14 | 8.2s |  |
| 918 | `sound_constructor_with_args` | 6 | 8.5s |  |
| 919 | `sound_embeddedprops` | 26 | 8.5s |  |
| 920 | `sound_play` | 19 | 8.5s |  |
| 921 | `sound_rootless` | 7 | 8.3s |  |
| 922 | `sound_valueof` | 33 | 8.3s |  |
| 923 | `soundchannel_soundtransform` | 835 | 29.9s |  |
| 924 | `soundchannel_soundtransform_exists` | 5 | 27.9s |  |
| 925 | `soundchannel_stop` | 8 | 28.8s |  |
| 926 | `soundmixer_buffertime` | 5 | 8.7s |  |
| 927 | `soundmixer_stopall` | 6 | 29.3s |  |
| 928 | `soundtransform` | 442 | 9.5s |  |
| 929 | `space_justifier_clone` | 12 | 3.4s |  |
| 930 | `sprite_with_frames` | 0 | 30.2s |  |
| 931 | `stage3d_agal_cross_product` | 0 | 11.4s |  |
| 932 | `stage3d_agal_upload_errors` | 66 | 11.4s |  |
| 933 | `stage3d_bitmap` | 0 | 34.5s |  |
| 934 | `stage3d_blend` | 81 | 32.9s |  |
| 935 | `stage3d_context3d_string_args` | 158 | 9.4s |  |
| 936 | `stage3d_errors` | 7 | 8.6s |  |
| 937 | `stage3d_errors_atf` | 3 | 9.7s |  |
| 938 | `stage3d_errors_swf_29` | 6 | 8.4s |  |
| 939 | `stage3d_float1_index` | 0 | 30.2s |  |
| 940 | `stage3d_fractal` | 0 | 31.5s |  |
| 941 | `stage3d_ignore_sampler_override` | 0 | 31.5s |  |
| 942 | `stage3d_multistage_triangle` | 3 | 11.3s |  |
| 943 | `stage3d_program_constants_bytearray_be` | 0 | 33.0s |  |
| 944 | `stage3d_program_constants_bytearray_le` | 0 | 26.8s |  |
| 945 | `stage3d_program_constants_invalid_input` | 21 | 23.4s |  |
| 946 | `stage3d_raytrace` | 0 | 44.1s |  |
| 947 | `stage3d_rotating_cube` | 0 | 8.9s |  |
| 948 | `stage3d_sampler` | 0 | 8.3s |  |
| 949 | `stage3d_sampler_partial_upload` | 0 | 8.4s |  |
| 950 | `stage3d_stencil` | 0 | 24.7s |  |
| 951 | `stage3d_texture` | 0 | 12.8s |  |
| 952 | `stage3d_texture_bytearray` | 0 | 9.6s |  |
| 953 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.8s |  |
| 954 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.8s |  |
| 955 | `stage3d_triangle` | 0 | 8.2s |  |
| 956 | `stage3d_triangle_bytes4` | 0 | 8.4s |  |
| 957 | `stage3d_triangle_float1` | 0 | 8.3s |  |
| 958 | `stage3d_triangle_index_upload` | 0 | 8.2s |  |
| 959 | `stage3d_x_y` | 22 | 6.3s |  |
| 960 | `stage_access` | 10 | 2.3s |  |
| 961 | `stage_displayobject_properties` | 24 | 6.4s |  |
| 962 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.2s |  |
| 963 | `stage_framerate_nan` | 7 | 2.8s |  |
| 964 | `stage_framerate_negative` | 6 | 6.3s |  |
| 965 | `stage_framerate_zero` | 6 | 6.2s |  |
| 966 | `stage_invalidate` | 38 | 6.4s |  |
| 967 | `stage_loaderinfo_properties` | 24 | 22.1s |  |
| 968 | `stage_mousechildren` | 2 | 6.2s |  |
| 969 | `stage_mouseenabled` | 15 | 6.2s |  |
| 970 | `stage_overriden_setters` | 31 | 6.3s |  |
| 971 | `stage_properties` | 30 | 6.2s |  |
| 972 | `stage_properties2` | 213 | 6.5s |  |
| 973 | `stage_stage3Ds_vector` | 1 | 6.3s |  |
| 974 | `static_length` | 24 | 6.2s |  |
| 975 | `static_text` | 3 | 6.5s |  |
| 976 | `static_var_with_this_in_ctor` | 2 | 6.2s |  |
| 977 | `statictext_text` | 8 | 6.2s |  |
| 978 | `stored_properties` | 11 | 6.1s |  |
| 979 | `strict_equality` | 34 | 7.0s |  |
| 980 | `string_call` | 13 | 6.1s |  |
| 981 | `string_case` | 23 | 6.4s |  |
| 982 | `string_char_at` | 27 | 6.2s |  |
| 983 | `string_char_code_at` | 28 | 6.0s |  |
| 984 | `string_concat_fromcharcode` | 37 | 28.4s |  |
| 985 | `string_constr` | 25 | 27.9s |  |
| 986 | `string_indexof_lastindexof` | 87 | 8.6s |  |
| 987 | `string_length` | 16 | 8.3s |  |
| 988 | `string_locale_compare` | 39 | 8.6s |  |
| 989 | `string_match` | 51 | 8.6s |  |
| 990 | `string_relational_compare` | 4 | 8.4s |  |
| 991 | `string_replace` | 51 | 8.6s |  |
| 992 | `string_search` | 41 | 8.6s |  |
| 993 | `string_slice_substr_substring` | 170 | 9.7s |  |
| 994 | `string_split` | 29 | 8.5s |  |
| 995 | `string_substr_negative` | 21 | 8.4s |  |
| 996 | `string_substr_weird` | 182 | 8.3s |  |
| 997 | `stylesheet` | 221 | 9.0s |  |
| 998 | `stylesheet_parse_color` | 69 | 8.6s |  |
| 999 | `stylesheet_transform` | 307 | 8.9s |  |
| 1000 | `sub_super_same_field` | 12 | 3.4s |  |
| 1001 | `subclass_superclass_linked_symbol` | 4 | 9.0s |  |
| 1002 | `subtract` | 1058 | 21.0s |  |
| 1003 | `super_get_call` | 12 | 8.5s |  |
| 1004 | `supercall_two_classobjects` | 2 | 8.6s |  |
| 1005 | `supercalls_coerce` | 8 | 8.6s |  |
| 1006 | `supercalls_weird` | 2 | 8.4s |  |
| 1007 | `superinterface_call` | 20 | 8.4s |  |
| 1008 | `superinterface_instanceof` | 18 | 8.4s |  |
| 1009 | `swf8` | 1 | 8.3s |  |
| 1010 | `swf_10_queued_goto_scripts_construct` | 52 | 28.5s |  |
| 1011 | `swf_9_goto_in_enter_frame` | 17 | 8.5s |  |
| 1012 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.5s |  |
| 1013 | `swf_9_queued_goto_scripts` | 6 | 28.3s |  |
| 1014 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 1015 | `swf_9_versioning` | 2 | 8.4s |  |
| 1016 | `swf_wrong_frame_count` | 38 | 8.8s |  |
| 1017 | `swf_wrong_frame_count_isplaying` | 22 | 8.4s |  |
| 1018 | `symbol_class_binary_data` | 8 | 8.6s |  |
| 1019 | `symbol_class_conflict` | 4 | 8.9s |  |
| 1020 | `symbol_class_root_not_zero` | 1 | 8.2s |  |
| 1021 | `symbolclass_invalid_utf8` | 2 | 8.3s |  |
| 1022 | `system_exit` | 3 | 3.2s |  |
| 1023 | `system_setclipboard_null` | 1 | 8.2s |  |
| 1024 | `tab_ordering_arrows` | 998 | 28.8s |  |
| 1025 | `tab_ordering_automatic_advanced` | 184 | 9.0s |  |
| 1026 | `tab_ordering_automatic_basic` | 45 | 27.7s |  |
| 1027 | `tab_ordering_children` | 116 | 8.6s |  |
| 1028 | `tab_ordering_custom_basic` | 34 | 8.4s |  |
| 1029 | `tab_ordering_stage_tab_children` | 32 | 8.4s |  |
| 1030 | `tab_ordering_stage_tab_children_remove_root` | 5 | 8.3s |  |
| 1031 | `tab_ordering_tabbable` | 47 | 8.5s |  |
| 1032 | `tabstop_properties` | 105 | 27.9s |  |
| 1033 | `text_element_basic` | 34 | 8.5s |  |
| 1034 | `text_engine_fontdescription` | 27 | 8.5s |  |
| 1035 | `text_engine_groupelement` | 64 | 9.3s |  |
| 1036 | `text_run` | 7 | 8.2s |  |
| 1037 | `textblock_createline_errors` | 23 | 8.6s |  |
| 1038 | `textblock_createline_fte` | 9 | 28.1s |  |
| 1039 | `textblock_properties` | 118 | 8.9s |  |
| 1040 | `textbox_click` | 37 | 28.4s |  |
| 1041 | `textfield_event` | 66 | 8.8s |  |
| 1042 | `textfield_focusin_event` | 9 | 8.3s |  |
| 1043 | `textfield_input_dead_keys_windows` | 15 | 8.4s |  |
| 1044 | `textfield_input_events` | 25 | 21.3s |  |
| 1045 | `textfield_unload` | 39 | 27.8s |  |
| 1046 | `textformat` | 1134 | 8.4s |  |
| 1047 | `textformat_display` | 14 | 8.4s |  |
| 1048 | `textformat_font_max_length` | 4 | 3.3s |  |
| 1049 | `textline_inapplicable_properties` | 10 | 8.4s |  |
| 1050 | `textline_name` | 1 | 3.3s |  |
| 1051 | `textline_raw_text_length` | 30 | 8.4s |  |
| 1052 | `textline_splitting_basic` | 76 | 8.6s |  |
| 1053 | `textline_throwerror` | 30 | 8.4s |  |
| 1054 | `textline_validity` | 162 | 8.6s |  |
| 1055 | `throw` | 3 | 8.4s |  |
| 1056 | `timeline_scripts` | 3 | 27.7s |  |
| 1057 | `timer` | 90 | 9.5s |  |
| 1058 | `timer_events` | 3 | 8.4s |  |
| 1059 | `timer_finished` | 11 | 3.6s |  |
| 1060 | `timer_invalid_delay` | 30 | 8.4s |  |
| 1061 | `timer_reset` | 8 | 20.8s |  |
| 1062 | `timer_setdelay` | 5 | 20.8s |  |
| 1063 | `trace` | 12 | 1.2s |  |
| 1064 | `truthiness` | 30 | 1.2s |  |
| 1065 | `try_catch` | 11 | 1.2s |  |
| 1066 | `try_catch_typed` | 12 | 1.2s |  |
| 1067 | `typeof` | 30 | 1.2s |  |
| 1068 | `uint_constr` | 92 | 1.2s |  |
| 1069 | `uint_tofixed` | 1215 | 1.2s |  |
| 1070 | `uint_toprecision` | 1125 | 1.2s |  |
| 1071 | `uint_tostring` | 3375 | 1.2s |  |
| 1072 | `uncaught_error_basic` | 2 | 1.2s |  |
| 1073 | `unchecked_function` | 15 | 1.2s |  |
| 1074 | `unescape` | 28 | 1.2s |  |
| 1075 | `url_loader` | 25 | 1.2s |  |
| 1076 | `url_vars` | 27 | 1.2s |  |
| 1077 | `urlrequest` | 18 | 1.2s |  |
| 1078 | `urlstream_basic` | 5 | 1.2s |  |
| 1079 | `urshift` | 1058 | 1.2s |  |
| 1080 | `utils3d` | 7 | 1.2s |  |
| 1081 | `vector3d` | 397 | 1.2s |  |
| 1082 | `vector_class` | 36 | 1.2s |  |
| 1083 | `vector_class_call` | 11 | 1.2s |  |
| 1084 | `vector_coercion` | 66 | 1.2s |  |
| 1085 | `vector_concat` | 90 | 1.2s |  |
| 1086 | `vector_constr` | 107 | 1.2s |  |
| 1087 | `vector_enumeration` | 5 | 1.2s |  |
| 1088 | `vector_every` | 92 | 1.2s |  |
| 1089 | `vector_filter` | 95 | 1.2s |  |
| 1090 | `vector_holes` | 24 | 1.2s |  |
| 1091 | `vector_indexof` | 302 | 1.2s |  |
| 1092 | `vector_insertat` | 270 | 1.2s |  |
| 1093 | `vector_int_access` | 4 | 1.2s |  |
| 1094 | `vector_int_delete` | 11 | 1.2s |  |
| 1095 | `vector_join` | 58 | 1.2s |  |
| 1096 | `vector_lastindexof` | 302 | 1.2s |  |
| 1097 | `vector_legacy` | 10 | 1.2s |  |
| 1098 | `vector_map` | 85 | 1.2s |  |
| 1099 | `vector_object_final` | 1 | 1.2s |  |
| 1100 | `vector_object_toString` | 10 | 27.5s |  |
| 1101 | `vector_pushpop` | 255 | 28.6s |  |
| 1102 | `vector_reborrow_bug` | 10 | 8.2s |  |
| 1103 | `vector_removeat` | 172 | 9.2s |  |
| 1104 | `vector_reverse` | 232 | 9.3s |  |
| 1105 | `vector_shiftunshift` | 252 | 8.1s |  |
| 1106 | `vector_slice` | 331 | 9.7s |  |
| 1107 | `vector_sort` | 905 | 8.0s |  |
| 1108 | `vector_splice` | 693 | 11.8s |  |
| 1109 | `vector_splice_fixed_bug_compat` | 4 | 8.0s |  |
| 1110 | `vector_tostring` | 79 | 8.7s |  |
| 1111 | `verification` | 8 | 3.2s |  |
| 1112 | `verify_abnormal_loop` | 1 | 8.1s |  |
| 1113 | `verify_dxns_without_flag` | 3 | 8.4s |  |
| 1114 | `verify_exception_target_two_jumps` | 1 | 8.2s |  |
| 1115 | `verify_exception_targets_edge_case` | 1 | 8.2s |  |
| 1116 | `verify_illegal_opcode` | 1 | 3.4s |  |
| 1117 | `verify_jump_to_middle_of_op` | 1 | 8.2s |  |
| 1118 | `verify_lookup_switch_edge_case` | 1 | 8.0s |  |
| 1119 | `verify_method_info_oob` | 1 | 1.3s |  |
| 1120 | `verify_stack` | 5 | 8.1s |  |
| 1121 | `verify_typecheck` | 4 | 3.2s |  |
| 1122 | `verify_unreachable_exception` | 2 | 8.1s |  |
| 1123 | `versioned_isplaying` | 2 | 8.0s |  |
| 1124 | `virtual_properties` | 16 | 8.2s |  |
| 1125 | `with` | 4 | 8.0s |  |
| 1126 | `wrong_arg_count` | 7 | 8.4s |  |
| 1127 | `xml_abstract_equality` | 36 | 8.3s |  |
| 1128 | `xml_advanced` | 52 | 8.2s |  |
| 1129 | `xml_appendchild` | 10 | 3.2s |  |
| 1130 | `xml_appendchild_swf_v21` | 13 | 3.3s |  |
| 1131 | `xml_as_attribute` | 9 | 8.2s |  |
| 1132 | `xml_attribute` | 35 | 8.2s |  |
| 1133 | `xml_attribute_name` | 40 | 8.1s |  |
| 1134 | `xml_basic` | 33 | 8.3s |  |
| 1135 | `xml_child` | 25 | 8.3s |  |
| 1136 | `xml_childindex` | 7 | 8.1s |  |
| 1137 | `xml_children` | 43 | 8.7s |  |
| 1138 | `xml_class_call` | 9 | 8.1s |  |
| 1139 | `xml_contains` | 197 | 8.1s |  |
| 1140 | `xml_copy` | 20 | 27.4s |  |
| 1141 | `xml_ctor_from_tostring` | 23 | 27.6s |  |
| 1142 | `xml_delete` | 114 | 8.2s |  |
| 1143 | `xml_descendants` | 83 | 8.2s |  |
| 1144 | `xml_elements` | 6 | 8.1s |  |
| 1145 | `xml_equals_namespace_check` | 2 | 8.0s |  |
| 1146 | `xml_explicit_use_namespace` | 5 | 8.2s |  |
| 1147 | `xml_getdescendants_qname` | 21 | 8.1s |  |
| 1148 | `xml_has_property_via_in` | 26 | 8.2s |  |
| 1149 | `xml_hasownproperty` | 6 | 8.2s |  |
| 1150 | `xml_ignore_white` | 6 | 8.1s |  |
| 1151 | `xml_length` | 2 | 8.1s |  |
| 1152 | `xml_list_as_attribute` | 9 | 8.1s |  |
| 1153 | `xml_list_concat` | 20 | 8.1s |  |
| 1154 | `xml_list_ctor_errors` | 34 | 8.2s |  |
| 1155 | `xml_list_delete_clear_parent` | 6 | 8.1s |  |
| 1156 | `xml_list_enumerate` | 4 | 8.1s |  |
| 1157 | `xml_methods_settings` | 3 | 8.1s |  |
| 1158 | `xml_mismatched_tag` | 37 | 8.2s |  |
| 1159 | `xml_namespace` | 39 | 3.1s |  |
| 1160 | `xml_namespace_methods` | 245 | 8.2s |  |
| 1161 | `xml_namespaced_property` | 7 | 8.1s |  |
| 1162 | `xml_no_namespace` | 1 | 8.1s |  |
| 1163 | `xml_nodekind` | 3 | 8.1s |  |
| 1164 | `xml_normalize` | 35 | 8.2s |  |
| 1165 | `xml_notification_bubbling` | 361 | 8.2s |  |
| 1166 | `xml_parent` | 8 | 8.2s |  |
| 1167 | `xml_set_children` | 17 | 8.2s |  |
| 1168 | `xml_set_name` | 34 | 8.2s |  |
| 1169 | `xml_settings` | 6 | 3.1s |  |
| 1170 | `xml_simple_complex_content` | 47 | 8.2s |  |
| 1171 | `xml_socket` | 11 | 8.2s |  |
| 1172 | `xml_text` | 7 | 8.2s |  |
| 1173 | `xml_tostring` | 6 | 8.2s |  |
| 1174 | `xml_tostring_namespace` | 12 | 8.0s |  |
| 1175 | `xml_unescaping` | 23 | 8.2s |  |
| 1176 | `xml_weird_ignores` | 54 | 8.3s |  |
| 1177 | `xml_wildcard` | 11 | 8.2s |  |
| 1178 | `xmldocument` | 254 | 8.2s |  |
| 1179 | `xmlnode` | 3540 | 8.3s |  |
| 1180 | `zero_frame_clip` | 3 | 8.8s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.3s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.1s |  |
| 3 | `blend_transform` | 1 | 1 | 7.0s |  |
| 4 | `bounds_mode` | 6 | 6 | 8.0s |  |
| 5 | `coerce_property` | 3 | 3 | 6.8s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.7s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 26.6s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 19.7s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 8.5s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 8.5s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 8.3s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 8.6s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 8.3s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 8.3s |  |
| 15 | `freestanding_superclass` | 2 | 4 | 8.0s |  |
| 16 | `goto_framescript_queued` | 5 | 5 | 29.6s |  |
| 17 | `graphics_draw_path` | 50 | 50 | 30.0s |  |
| 18 | `groupelement_text` | 2 | 2 | 9.1s |  |
| 19 | `int_toexponential` | 76 | 76 | 1.2s |  |
| 20 | `matrix3d_append_rotation` | 1 | 3 | 8.2s |  |
| 21 | `matrix3d_recompose_edge_cases` | 85 | 85 | 8.5s |  |
| 22 | `simplebutton_childevents_script_order` | 4 | 4 | 8.5s |  |
| 23 | `slot_holes_fail` | 1 | 1 | 8.2s |  |
| 24 | `slot_id_exceeds_trait_count` | 1 | 1 | 27.9s |  |
| 25 | `soundchannel_position` | 74 | 74 | 28.7s |  |
| 26 | `soundchannel_soundcomplete` | 10 | 10 | 8.6s |  |
| 27 | `sprite_dropTarget` | 15 | 15 | 8.7s |  |
| 28 | `swf_9_goto_in_construct_frame` | 12 | 12 | 28.6s |  |
| 29 | `textblock_line_changes` | 44 | 44 | 9.1s |  |
| 30 | `textblock_releaselines` | 4 | 4 | 10.1s |  |
| 31 | `uint_toexponential` | 100 | 100 | 1.2s |  |
| 32 | `uncaught_errors_stringified` | 15 | 15 | 1.2s |  |
| 33 | `weird_superinterface_properties` | 1 | 1 | 8.1s |  |

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
