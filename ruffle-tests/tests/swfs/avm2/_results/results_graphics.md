# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-19 14:26 UTC

**Git SHA**: `9d038c750e`

**Run Duration**: 262m 25s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1251 |
| Passing | **1179** (94.2%) |
| Ruffle-matched | 33 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1212** (96.9%) |
| Failing | 39 |
| Total expected lines | 154806 |
| Matching lines | 151316 (97.7%) |
| Mismatched lines | 3490 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 39 | 100.0% |

## Passing Tests

**1179 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 28.8s |  |
| 2 | `accessibility` | 1 | 8.7s |  |
| 3 | `accessibilityimplementation` | 18 | 8.9s |  |
| 4 | `activation_class` | 6 | 28.6s |  |
| 5 | `add` | 1058 | 20.5s |  |
| 6 | `agal_compiler` | 13 | 11.5s |  |
| 7 | `air_datagram_socket` | 1 | 10.9s |  |
| 8 | `air_hidden_lookup` | 2 | 8.7s |  |
| 9 | `air_ifilepromise` | 1 | 8.9s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 8.7s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.5s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.5s |  |
| 13 | `all_classes/display/swf10` | 2569 | 8.8s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.6s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.6s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.6s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.6s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.5s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 8.7s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.5s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.5s |  |
| 22 | `all_classes/errors/swf10` | 140 | 8.6s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.4s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.4s |  |
| 25 | `all_classes/events/swf10` | 1638 | 8.6s |  |
| 26 | `all_classes/events/swf11` | 1750 | 1.4s |  |
| 27 | `all_classes/events/swf12` | 1814 | 1.5s |  |
| 28 | `all_classes/events/swf30` | 2353 | 1.5s |  |
| 29 | `all_classes/events/swf9` | 1030 | 1.4s |  |
| 30 | `all_classes/security/swf11` | 3 | 8.6s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.4s |  |
| 32 | `all_classes/security/swf13` | 53 | 1.4s |  |
| 33 | `all_classes/security/swf30` | 53 | 1.5s |  |
| 34 | `all_classes/xml/swf30` | 116 | 8.7s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.5s |  |
| 36 | `amf_array_serialization` | 17 | 30.9s |  |
| 37 | `amf_custom_obj` | 26 | 8.7s |  |
| 38 | `amf_dictionary` | 9 | 8.7s |  |
| 39 | `amf_function` | 46 | 8.8s |  |
| 40 | `amf_invalid_date` | 2 | 8.6s |  |
| 41 | `amf_missing_prop` | 6 | 8.8s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 8.6s |  |
| 43 | `amf_setter_error` | 8 | 8.8s |  |
| 44 | `amf_vector` | 40 | 8.7s |  |
| 45 | `amf_xml` | 6 | 8.6s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 9.1s |  |
| 47 | `application_domain` | 4 | 8.7s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 8.8s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 28.7s |  |
| 50 | `array_access` | 18 | 8.7s |  |
| 51 | `array_access_interpreter` | 4 | 8.7s |  |
| 52 | `array_access_no_pubns` | 2 | 8.7s |  |
| 53 | `array_concat` | 41 | 8.7s |  |
| 54 | `array_constr` | 10 | 8.5s |  |
| 55 | `array_delete` | 44 | 8.7s |  |
| 56 | `array_enumeration` | 10 | 8.6s |  |
| 57 | `array_enumeration_elements` | 11 | 8.6s |  |
| 58 | `array_every` | 8 | 8.6s |  |
| 59 | `array_filter` | 6 | 8.6s |  |
| 60 | `array_foreach` | 18 | 8.6s |  |
| 61 | `array_hasownproperty` | 11 | 8.6s |  |
| 62 | `array_holes` | 9 | 8.7s |  |
| 63 | `array_index_max` | 84 | 8.6s |  |
| 64 | `array_indexof` | 25 | 8.8s |  |
| 65 | `array_join` | 26 | 9.0s |  |
| 66 | `array_lastindexof` | 29 | 8.9s |  |
| 67 | `array_length` | 14 | 8.9s |  |
| 68 | `array_literal` | 3 | 8.9s |  |
| 69 | `array_map` | 8 | 8.6s |  |
| 70 | `array_pop` | 52 | 8.8s |  |
| 71 | `array_push` | 24 | 8.8s |  |
| 72 | `array_reborrow_bug` | 6 | 8.8s |  |
| 73 | `array_reverse` | 28 | 8.9s |  |
| 74 | `array_shift` | 51 | 3.7s |  |
| 75 | `array_slice` | 39 | 9.0s |  |
| 76 | `array_some` | 8 | 8.9s |  |
| 77 | `array_sort` | 297 | 9.3s |  |
| 78 | `array_sort_fun_swf12` | 2 | 8.7s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.6s |  |
| 80 | `array_sort_random` | 210 | 9.1s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 9.0s |  |
| 82 | `array_sorton` | 545 | 9.9s |  |
| 83 | `array_sparse_ops` | 41 | 28.1s |  |
| 84 | `array_splice` | 133 | 8.8s |  |
| 85 | `array_splice2` | 428 | 8.7s |  |
| 86 | `array_splice_types` | 48 | 8.7s |  |
| 87 | `array_storage` | 8 | 8.6s |  |
| 88 | `array_tolocalestring` | 9 | 8.4s |  |
| 89 | `array_tostring` | 12 | 8.5s |  |
| 90 | `array_unshift` | 24 | 8.5s |  |
| 91 | `array_valueof` | 9 | 8.5s |  |
| 92 | `array_vector_null_callback` | 10 | 8.5s |  |
| 93 | `astype` | 28 | 28.5s |  |
| 94 | `astypelate` | 24 | 8.8s |  |
| 95 | `astypelate_propagates` | 1 | 8.4s |  |
| 96 | `asymmetric_key_events` | 11 | 8.6s |  |
| 97 | `automation_classes` | 122 | 8.8s |  |
| 98 | `av_classes` | 340 | 8.7s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 8.6s |  |
| 100 | `avm2_catchup_dobj` | 158 | 9.2s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 96.7s |  |
| 102 | `bevel_filter` | 187 | 8.6s |  |
| 103 | `bitand` | 1058 | 20.9s |  |
| 104 | `bitmap_constr` | 17 | 8.5s |  |
| 105 | `bitmap_data` | 1000 | 16.9s |  |
| 106 | `bitmap_pixelsnapping` | 2 | 28.8s |  |
| 107 | `bitmap_properties` | 23 | 8.5s |  |
| 108 | `bitmap_subclass` | 7 | 9.9s |  |
| 109 | `bitmap_subclass_properties` | 9 | 8.9s |  |
| 110 | `bitmap_timeline` | 9 | 8.7s |  |
| 111 | `bitmapdata_accuracy` | 1 | 47.0s |  |
| 112 | `bitmapdata_applyfilter_blur` | 0 | 28.8s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.3s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | 0 | 28.4s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 28.6s |  |
| 116 | `bitmapdata_clone` | 13 | 8.7s |  |
| 117 | `bitmapdata_colortransform` | 0 | 9.0s |  |
| 118 | `bitmapdata_colortransform_oob` | 2 | 8.4s |  |
| 119 | `bitmapdata_constr` | 22 | 8.5s |  |
| 120 | `bitmapdata_constructor_from_timeline` | 1 | 8.8s |  |
| 121 | `bitmapdata_copychannel` | 0 | 31.4s |  |
| 122 | `bitmapdata_copypixels` | 23 | 30.1s |  |
| 123 | `bitmapdata_copypixels_blend_over` | 1 | 8.8s |  |
| 124 | `bitmapdata_copypixelstobytearray` | 39 | 8.6s |  |
| 125 | `bitmapdata_dispose` | 7 | 8.7s |  |
| 126 | `bitmapdata_draw` | 0 | 29.2s |  |
| 127 | `bitmapdata_draw_alpha_erase` | 8 | 8.7s |  |
| 128 | `bitmapdata_draw_colortransform` | 0 | 28.1s |  |
| 129 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 28.2s |  |
| 130 | `bitmapdata_draw_filters` | 0 | 27.9s |  |
| 131 | `bitmapdata_draw_masks` | 0 | 8.6s |  |
| 132 | `bitmapdata_draw_rotation` | 0 | 8.8s |  |
| 133 | `bitmapdata_draw_self_via_graphic` | 0 | 8.7s |  |
| 134 | `bitmapdata_draw_stage` | 0 | 28.4s |  |
| 135 | `bitmapdata_drawwithquality` | 0 | 9.1s |  |
| 136 | `bitmapdata_embedded` | 9 | 9.7s |  |
| 137 | `bitmapdata_fillrect` | 0 | 10.4s |  |
| 138 | `bitmapdata_filter_sourcerect` | 0 | 33.6s |  |
| 139 | `bitmapdata_floodfill` | 35 | 9.9s |  |
| 140 | `bitmapdata_getpixels` | 39 | 33.3s |  |
| 141 | `bitmapdata_getvector` | 27 | 4.2s |  |
| 142 | `bitmapdata_histogram` | 59 | 4.1s |  |
| 143 | `bitmapdata_hittest` | 112 | 11.0s |  |
| 144 | `bitmapdata_hittest_threshold` | 18 | 10.2s |  |
| 145 | `bitmapdata_opaque` | 0 | 10.5s |  |
| 146 | `bitmapdata_pixeldissolve` | 1037 | 11.1s |  |
| 147 | `bitmapdata_pixeldissolve_image` | 0 | 10.8s |  |
| 148 | `bitmapdata_rectangle_rounding` | 16 | 10.2s |  |
| 149 | `bitmapdata_setpixels` | 286 | 10.2s |  |
| 150 | `bitmapdata_setvector` | 26 | 10.3s |  |
| 151 | `bitmapdata_sync` | 0 | 31.4s |  |
| 152 | `bitmapdata_threshold` | 176 | 9.6s |  |
| 153 | `bitmapdata_zero_size` | 8 | 29.6s |  |
| 154 | `bitnot` | 46 | 8.9s |  |
| 155 | `bitor` | 1058 | 20.6s |  |
| 156 | `bitxor` | 1058 | 20.7s |  |
| 157 | `blend_mode_null` | 1 | 9.0s |  |
| 158 | `blend_multiply_alpha` | 0 | 9.2s |  |
| 159 | `blend_scroll` | 0 | 9.2s |  |
| 160 | `blend_shader_luma_lighten` | 3 | 9.7s |  |
| 161 | `blur_filter` | 43 | 9.2s |  |
| 162 | `boolean_constr` | 32 | 8.6s |  |
| 163 | `boolean_negation` | 30 | 8.7s |  |
| 164 | `boolean_tostring` | 8 | 8.6s |  |
| 165 | `broadcast_event` | 7 | 28.3s |  |
| 166 | `button_bounds` | 1 | 8.6s |  |
| 167 | `button_hittest` | 2 | 28.3s |  |
| 168 | `button_nested_frame` | 48 | 29.0s |  |
| 169 | `button_nested_frame_simple` | 27 | 8.8s |  |
| 170 | `bytearray` | 48 | 8.8s |  |
| 171 | `bytearray_compress` | 31 | 28.6s |  |
| 172 | `bytearray_errors` | 24 | 8.7s |  |
| 173 | `bytearray_method_serialization` | 1 | 8.4s |  |
| 174 | `bytearray_oom` | 3 | 8.5s |  |
| 175 | `bytearray_readobject_amf0` | 50 | 8.6s |  |
| 176 | `bytearray_readobject_amf3` | 53 | 8.5s |  |
| 177 | `bytearray_readutf8bytes_with_bom` | 16 | 8.6s |  |
| 178 | `bytearray_serialization` | 3 | 8.5s |  |
| 179 | `bytearray_string_null` | 19 | 8.7s |  |
| 180 | `bytearray_tostring` | 15 | 8.4s |  |
| 181 | `bytearray_utf16` | 8 | 8.4s |  |
| 182 | `bytearray_writeobject` | 24 | 8.3s |  |
| 183 | `callee_in_initializer` | 6 | 8.4s |  |
| 184 | `callproplex_class` | 1 | 8.5s |  |
| 185 | `capabilities_resolution` | 8 | 29.9s |  |
| 186 | `catch_class` | 6 | 8.5s |  |
| 187 | `catch_scope_slot` | 7 | 3.4s |  |
| 188 | `checkfilter` | 4 | 3.4s |  |
| 189 | `class_call` | 32 | 8.7s |  |
| 190 | `class_cast_call` | 14 | 8.5s |  |
| 191 | `class_enumeration` | 4 | 8.5s |  |
| 192 | `class_has_own_property` | 2 | 8.5s |  |
| 193 | `class_init_interpreter_mode` | 1 | 8.3s |  |
| 194 | `class_is` | 32 | 8.5s |  |
| 195 | `class_methods` | 5 | 8.5s |  |
| 196 | `class_object_properties` | 10 | 8.6s |  |
| 197 | `class_singleton` | 18 | 8.5s |  |
| 198 | `class_supercalls_errors` | 35 | 8.7s |  |
| 199 | `class_supercalls_mismatched` | 26 | 8.6s |  |
| 200 | `class_superclass_wrong_order` | 1 | 28.3s |  |
| 201 | `class_to_locale_string` | 2 | 8.5s |  |
| 202 | `class_to_string` | 2 | 8.3s |  |
| 203 | `class_value_of` | 2 | 8.5s |  |
| 204 | `click_block` | 5 | 27.7s |  |
| 205 | `click_invisible` | 3 | 8.3s |  |
| 206 | `closures` | 12 | 8.1s |  |
| 207 | `coerce_return_type` | 40 | 8.2s |  |
| 208 | `coerce_return_type_fail` | 2 | 26.7s |  |
| 209 | `coerce_return_void` | 3 | 8.0s |  |
| 210 | `coerce_string` | 86 | 8.2s |  |
| 211 | `coerce_string_precision` | 28 | 8.1s |  |
| 212 | `coerce_to_primitive_side_effects` | 29 | 26.9s |  |
| 213 | `color_matrix_filter` | 19 | 8.2s |  |
| 214 | `construct_errors_swf10` | 8 | 8.2s |  |
| 215 | `construct_frame_list` | 22 | 27.4s |  |
| 216 | `construct_interface` | 3 | 8.2s |  |
| 217 | `constructor_call` | 3 | 8.1s |  |
| 218 | `constructors_vs_timeline` | 5 | 27.6s |  |
| 219 | `constructprop_dynamic_primitive` | 7 | 8.2s |  |
| 220 | `constructprop_method` | 2 | 8.1s |  |
| 221 | `constructsuper_null` | 2 | 8.1s |  |
| 222 | `content_element_basic` | 50 | 8.4s |  |
| 223 | `context3d_creation` | 9 | 8.1s |  |
| 224 | `control_flow_bool` | 4 | 8.1s |  |
| 225 | `control_flow_stricteq` | 8 | 8.1s |  |
| 226 | `convert_boolean` | 30 | 8.1s |  |
| 227 | `convert_integer` | 90 | 8.3s |  |
| 228 | `convert_number` | 56 | 8.2s |  |
| 229 | `convert_uinteger` | 90 | 8.3s |  |
| 230 | `convolution_filter` | 89 | 8.3s |  |
| 231 | `core_exceptions` | 47 | 8.9s |  |
| 232 | `cpool_index_invalid_bytecode_1` | 6 | 8.2s |  |
| 233 | `cpool_index_invalid_bytecode_2` | 3 | 8.1s |  |
| 234 | `cpool_index_invalid_bytecode_3` | 1 | 8.1s |  |
| 235 | `cross_api_version_call_newer` | 12 | 8.7s |  |
| 236 | `cross_api_version_call_older` | 12 | 8.4s |  |
| 237 | `cryptscore` | 11 | 8.2s |  |
| 238 | `currency_parse_result` | 7 | 8.2s |  |
| 239 | `date` | 30 | 8.6s |  |
| 240 | `date_parse` | 36 | 8.1s |  |
| 241 | `declocal` | 46 | 8.2s |  |
| 242 | `declocal_i` | 46 | 8.2s |  |
| 243 | `decode_uri` | 71 | 8.4s |  |
| 244 | `decrement` | 46 | 8.6s |  |
| 245 | `decrement_i` | 46 | 8.6s |  |
| 246 | `default_values` | 7 | 8.4s |  |
| 247 | `delayed_symbolclass` | 28 | 29.1s |  |
| 248 | `describe_type_basic` | 152 | 8.6s |  |
| 249 | `describe_type_json` | 301 | 8.6s |  |
| 250 | `describe_type_metadata` | 125 | 8.7s |  |
| 251 | `describe_type_native` | 23 | 8.6s |  |
| 252 | `dictionary_access` | 62 | 8.7s |  |
| 253 | `dictionary_access_no_pubns` | 2 | 28.3s |  |
| 254 | `dictionary_delete` | 101 | 8.9s |  |
| 255 | `dictionary_foreach` | 42 | 8.8s |  |
| 256 | `dictionary_hasownproperty` | 63 | 8.8s |  |
| 257 | `dictionary_in` | 62 | 8.7s |  |
| 258 | `dictionary_iter_modify` | 8 | 8.4s |  |
| 259 | `dictionary_namespaces` | 36 | 8.6s |  |
| 260 | `dictionary_primitive_keys` | 29 | 8.4s |  |
| 261 | `displacement_map_filter` | 61 | 8.6s |  |
| 262 | `displayobject_alpha` | 277 | 8.4s |  |
| 263 | `displayobject_blendmode` | 0 | 9.8s |  |
| 264 | `displayobject_colortransform_nested` | 0 | 27.9s |  |
| 265 | `displayobject_early_init` | 54 | 10.2s |  |
| 266 | `displayobject_filters` | 17 | 8.6s |  |
| 267 | `displayobject_from_enterframe` | 1 | 28.3s |  |
| 268 | `displayobject_getbounds_shape` | 0 | 28.2s |  |
| 269 | `displayobject_height` | 6052 | 28.6s |  |
| 270 | `displayobject_hittestobject` | 32 | 8.5s |  |
| 271 | `displayobject_hittestpoint` | 49 | 27.9s |  |
| 272 | `displayobject_hittestpoint_boundary` | 65 | 28.2s |  |
| 273 | `displayobject_hittestpoint_root` | 13 | 8.7s |  |
| 274 | `displayobject_invalid_floats` | 60 | 8.6s |  |
| 275 | `displayobject_invalid_props` | 3 | 8.4s |  |
| 276 | `displayobject_mask` | 3 | 8.8s |  |
| 277 | `displayobject_mask_self_referential` | 0 | 8.3s |  |
| 278 | `displayobject_metaData` | 3 | 8.4s |  |
| 279 | `displayobject_name` | 22 | 28.4s |  |
| 280 | `displayobject_name_from_timeline` | 24 | 8.5s |  |
| 281 | `displayobject_opaque_background` | 6 | 8.2s |  |
| 282 | `displayobject_parent` | 12 | 8.1s |  |
| 283 | `displayobject_root` | 24 | 26.9s |  |
| 284 | `displayobject_rotation` | 1284 | 26.9s |  |
| 285 | `displayobject_scrollrect` | 33 | 10.1s |  |
| 286 | `displayobject_set_matrix_nested` | 0 | 26.9s |  |
| 287 | `displayobject_set_name_loaded` | 3 | 8.5s |  |
| 288 | `displayobject_subclass` | 2 | 8.1s |  |
| 289 | `displayobject_transform` | 89 | 26.8s |  |
| 290 | `displayobject_visible` | 23 | 8.0s |  |
| 291 | `displayobject_width` | 4852 | 26.8s |  |
| 292 | `displayobject_x` | 614 | 26.3s |  |
| 293 | `displayobject_y` | 617 | 8.1s |  |
| 294 | `displayobjectcontainer_addchild` | 32 | 8.1s |  |
| 295 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 8.0s |  |
| 296 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.2s |  |
| 297 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 8.1s |  |
| 298 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 8.1s |  |
| 299 | `displayobjectcontainer_addchildat` | 42 | 8.1s |  |
| 300 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 8.2s |  |
| 301 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 8.1s |  |
| 302 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.1s |  |
| 303 | `displayobjectcontainer_contains` | 66 | 26.8s |  |
| 304 | `displayobjectcontainer_getchildat` | 4 | 8.1s |  |
| 305 | `displayobjectcontainer_getchildbyname` | 9 | 8.0s |  |
| 306 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 8.0s |  |
| 307 | `displayobjectcontainer_getchildindex` | 28 | 8.0s |  |
| 308 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 26.6s |  |
| 309 | `displayobjectcontainer_removechild` | 10 | 8.0s |  |
| 310 | `displayobjectcontainer_removechild_errors` | 4 | 8.0s |  |
| 311 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 8.1s |  |
| 312 | `displayobjectcontainer_removechildat` | 18 | 8.0s |  |
| 313 | `displayobjectcontainer_removechildren` | 51 | 8.3s |  |
| 314 | `displayobjectcontainer_setchildindex` | 42 | 7.9s |  |
| 315 | `displayobjectcontainer_stopallmovieclips` | 2 | 26.9s |  |
| 316 | `displayobjectcontainer_swapchildren` | 42 | 8.1s |  |
| 317 | `displayobjectcontainer_swapchildrenat` | 42 | 8.1s |  |
| 318 | `displayobjectcontainer_timelineinstance` | 48 | 26.9s |  |
| 319 | `divide` | 1058 | 20.2s |  |
| 320 | `doabc_and_symbolclass_script_init_goto` | 7 | 26.7s |  |
| 321 | `doabc_and_symbolclass_script_init_normal` | 6 | 8.0s |  |
| 322 | `doabc_is_eager` | 1 | 26.4s |  |
| 323 | `documentclass` | 9 | 8.2s |  |
| 324 | `domain_memory` | 133 | 9.2s |  |
| 325 | `drag_drop` | 10 | 22.0s |  |
| 326 | `drop_shadow_filter` | 172 | 6.9s |  |
| 327 | `duplicate_defs` | 1 | 7.0s |  |
| 328 | `eager_init` | 1 | 6.7s |  |
| 329 | `east_asian_justifier_clone` | 8 | 17.9s |  |
| 330 | `edit_text_linkage` | 7 | 6.8s |  |
| 331 | `edittext_align` | 60 | 7.1s |  |
| 332 | `edittext_always_show_selection` | 0 | 23.1s |  |
| 333 | `edittext_antialiastype` | 296 | 7.0s |  |
| 334 | `edittext_at_point_methods_basic` | 16 | 7.8s |  |
| 335 | `edittext_autosize` | 39 | 7.2s |  |
| 336 | `edittext_autosize_align` | 0 | 22.9s |  |
| 337 | `edittext_autosize_height_dynamic` | 60 | 22.3s |  |
| 338 | `edittext_autosize_height_input` | 60 | 7.1s |  |
| 339 | `edittext_autosize_lazy_bounds_events` | 65 | 6.9s |  |
| 340 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.6s |  |
| 341 | `edittext_autosize_lazy_bounds_props` | 490 | 8.2s |  |
| 342 | `edittext_autosize_lazy_bounds_visual` | 0 | 21.8s |  |
| 343 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.8s |  |
| 344 | `edittext_bottom_scroll_v_basic` | 210 | 6.7s |  |
| 345 | `edittext_bounds_scale` | 24 | 21.6s |  |
| 346 | `edittext_bullet` | 30 | 6.9s |  |
| 347 | `edittext_default_format` | 221 | 7.1s |  |
| 348 | `edittext_default_format_empty` | 136 | 6.9s |  |
| 349 | `edittext_empty_text_format` | 7 | 6.7s |  |
| 350 | `edittext_focus_selection` | 5 | 7.0s |  |
| 351 | `edittext_font_size` | 45 | 7.2s |  |
| 352 | `edittext_format_empty_font` | 8 | 6.8s |  |
| 353 | `edittext_get_char_index_at_point` | 4 | 23.8s |  |
| 354 | `edittext_get_line_index_at_point` | 2 | 22.2s |  |
| 355 | `edittext_get_line_index_of_char` | 76 | 7.7s |  |
| 356 | `edittext_getcharboundaries` | 172 | 7.0s |  |
| 357 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.0s |  |
| 358 | `edittext_getcharboundaries_scroll` | 85 | 6.8s |  |
| 359 | `edittext_getlinemetrics` | 146 | 7.1s |  |
| 360 | `edittext_html` | 3101 | 7.3s |  |
| 361 | `edittext_html_condensewhite` | 487 | 6.9s |  |
| 362 | `edittext_html_entity` | 4 | 6.7s |  |
| 363 | `edittext_html_font_size_swf12` | 267 | 6.7s |  |
| 364 | `edittext_html_font_size_swf13` | 273 | 46.9s |  |
| 365 | `edittext_html_roundtrip` | 17 | 29.6s |  |
| 366 | `edittext_ime_focus_lost` | 9 | 29.7s |  |
| 367 | `edittext_input_control` | 12 | 9.0s |  |
| 368 | `edittext_leading` | 9 | 9.2s |  |
| 369 | `edittext_letter_spacing` | 15 | 9.2s |  |
| 370 | `edittext_line_methods` | 294 | 10.2s |  |
| 371 | `edittext_line_metrics` | 11 | 29.5s |  |
| 372 | `edittext_margins` | 25 | 8.6s |  |
| 373 | `edittext_max_scroll_h_basic` | 475 | 8.8s |  |
| 374 | `edittext_max_scroll_v_basic` | 1000 | 8.4s |  |
| 375 | `edittext_mouse_selection` | 363 | 29.1s |  |
| 376 | `edittext_mousedown` | 3 | 8.7s |  |
| 377 | `edittext_mouseenabled` | 26 | 28.2s |  |
| 378 | `edittext_newline_character` | 22 | 8.5s |  |
| 379 | `edittext_newline_stripping` | 64 | 11.5s |  |
| 380 | `edittext_newlines` | 30 | 8.7s |  |
| 381 | `edittext_paragraph_methods` | 257 | 8.6s |  |
| 382 | `edittext_paste_events` | 8 | 8.8s |  |
| 383 | `edittext_paste_maxchars` | 4 | 8.6s |  |
| 384 | `edittext_paste_restrict` | 16 | 8.4s |  |
| 385 | `edittext_restrict` | 191 | 8.7s |  |
| 386 | `edittext_restrict_events` | 22 | 8.7s |  |
| 387 | `edittext_scrollh` | 10 | 8.7s |  |
| 388 | `edittext_selected_text` | 9 | 8.7s |  |
| 389 | `edittext_set_html_same` | 17 | 8.8s |  |
| 390 | `edittext_set_text_vs_html` | 9 | 8.6s |  |
| 391 | `edittext_stylesheet` | 536 | 9.1s |  |
| 392 | `edittext_stylesheet_custom_tag` | 76 | 8.8s |  |
| 393 | `edittext_stylesheet_display` | 272 | 8.8s |  |
| 394 | `edittext_tag_indent` | 49 | 31.9s |  |
| 395 | `edittext_underline` | 40 | 8.9s |  |
| 396 | `edittext_width_height` | 103 | 9.1s |  |
| 397 | `edittext_wordwrap_word` | 150 | 8.9s |  |
| 398 | `edittext_wrap_breaks` | 2375 | 9.3s |  |
| 399 | `element_format_clone` | 44 | 8.9s |  |
| 400 | `element_format_constructor_order` | 64 | 3.8s |  |
| 401 | `element_format_properties` | 235 | 9.8s |  |
| 402 | `empty_bounds` | 1 | 8.8s |  |
| 403 | `encode_uri_surrogate_pair_invalid` | 8 | 8.8s |  |
| 404 | `encode_uri_surrogate_pair_swf11` | 15 | 45.7s |  |
| 405 | `equals` | 512 | 31.9s |  |
| 406 | `error_geterrormessage` | 779 | 8.4s |  |
| 407 | `error_prototype` | 15 | 8.4s |  |
| 408 | `error_stack_trace` | 45 | 8.3s |  |
| 409 | `error_stack_trace_debug_swf17` | 0 | 27.5s |  |
| 410 | `error_stack_trace_debug_swf18` | 0 | 8.0s |  |
| 411 | `error_stack_trace_edge_cases` | 6 | 8.3s |  |
| 412 | `error_stack_trace_release_swf17` | 0 | 8.2s |  |
| 413 | `error_stack_trace_release_swf18` | 0 | 8.0s |  |
| 414 | `error_throwerror` | 103 | 8.4s |  |
| 415 | `error_tostring` | 29 | 8.3s |  |
| 416 | `error_tostring_more` | 86 | 8.4s |  |
| 417 | `es3_inheritance` | 31 | 8.5s |  |
| 418 | `es4_inheritance` | 30 | 8.5s |  |
| 419 | `es4_interfaces` | 30 | 8.7s |  |
| 420 | `es4_method_binding` | 8 | 8.6s |  |
| 421 | `es4_oop_prototypes` | 14 | 8.5s |  |
| 422 | `es4_protected_inheritance` | 6 | 8.3s |  |
| 423 | `escape` | 71 | 8.4s |  |
| 424 | `escape_multi_byte` | 45 | 8.4s |  |
| 425 | `event_bubbles` | 2 | 8.3s |  |
| 426 | `event_cancelable` | 2 | 8.2s |  |
| 427 | `event_clone` | 20 | 8.4s |  |
| 428 | `event_clone_error_redispatch` | 3 | 8.7s |  |
| 429 | `event_clone_on_redispatch` | 10 | 8.7s |  |
| 430 | `event_formattostring` | 31 | 8.6s |  |
| 431 | `event_isdefaultprevented` | 12 | 8.4s |  |
| 432 | `event_target_getter` | 5 | 3.3s |  |
| 433 | `event_target_set` | 9 | 27.7s |  |
| 434 | `event_type` | 1 | 8.3s |  |
| 435 | `event_valueof_tostring` | 18 | 8.3s |  |
| 436 | `eventdispatcher_dispatchevent` | 12 | 8.3s |  |
| 437 | `eventdispatcher_dispatchevent_cancel` | 20 | 8.4s |  |
| 438 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 8.4s |  |
| 439 | `eventdispatcher_dispatchevent_indirect` | 9 | 8.4s |  |
| 440 | `eventdispatcher_dispatchevent_this` | 5 | 8.3s |  |
| 441 | `eventdispatcher_haseventlistener` | 25 | 8.4s |  |
| 442 | `eventdispatcher_interface_invoke` | 1 | 8.3s |  |
| 443 | `eventdispatcher_tostring` | 10 | 8.4s |  |
| 444 | `eventdispatcher_willtrigger` | 25 | 46.3s |  |
| 445 | `falsiness` | 30 | 8.6s |  |
| 446 | `fast_index_access` | 12 | 8.8s |  |
| 447 | `filefilter_properties` | 4 | 8.6s |  |
| 448 | `filereference_browse_cancel` | 3 | 8.5s |  |
| 449 | `filereference_browse_select` | 9 | 8.5s |  |
| 450 | `filereference_load` | 31 | 8.5s |  |
| 451 | `filereference_save` | 16 | 8.5s |  |
| 452 | `filereference_save_and_browse` | 42 | 8.6s |  |
| 453 | `filereference_save_and_load` | 22 | 8.6s |  |
| 454 | `filereference_uninitialized` | 8 | 8.5s |  |
| 455 | `filereferencelist_browse_cancel` | 6 | 8.5s |  |
| 456 | `filereferencelist_browse_select` | 7 | 8.4s |  |
| 457 | `filter_rewind` | 8 | 27.9s |  |
| 458 | `filters_array_holes` | 25 | 9.7s |  |
| 459 | `finddef` | 3 | 8.5s |  |
| 460 | `findprop_global_prototype` | 6 | 8.5s |  |
| 461 | `flash_media_video_constructor` | 156 | 9.3s |  |
| 462 | `flash_media_video_rotation_probe` | 27 | 8.6s |  |
| 463 | `flash_media_video_setter` | 40 | 9.0s |  |
| 464 | `flash_trace` | 17 | 8.6s |  |
| 465 | `flash_xml` | 29 | 8.6s |  |
| 466 | `flash_xml_cloneNode` | 22 | 8.5s |  |
| 467 | `flash_xml_namespace` | 109 | 8.5s |  |
| 468 | `flash_xml_removeNode` | 60 | 8.5s |  |
| 469 | `focus_events_code` | 161 | 28.2s |  |
| 470 | `focus_events_key_basic` | 132 | 28.4s |  |
| 471 | `focus_events_key_navigation` | 53 | 27.8s |  |
| 472 | `focus_events_key_same_object` | 26 | 8.4s |  |
| 473 | `focus_events_mixed_key_mouse` | 100 | 27.8s |  |
| 474 | `focus_events_mouse_basic` | 260 | 28.2s |  |
| 475 | `focus_events_mouse_focusable` | 112 | 28.5s |  |
| 476 | `focus_events_mouse_same_object` | 40 | 8.5s |  |
| 477 | `focus_remove` | 20 | 27.8s |  |
| 478 | `focus_root_movie` | 4 | 30.0s |  |
| 479 | `focus_stage` | 1 | 8.3s |  |
| 480 | `focusrect` | 18 | 9.2s |  |
| 481 | `focusrect_focuslost` | 9 | 8.4s |  |
| 482 | `focusrect_property` | 110 | 3.3s |  |
| 483 | `font_description_clone` | 14 | 8.5s |  |
| 484 | `font_embedded` | 24 | 48.1s |  |
| 485 | `font_enumeratefonts` | 41 | 9.6s |  |
| 486 | `font_enumeratefonts_filter` | 4 | 30.1s |  |
| 487 | `font_enumeratefonts_order` | 9 | 30.6s |  |
| 488 | `font_hasglyphs` | 40 | 9.0s |  |
| 489 | `font_registerfont` | 129 | 9.7s |  |
| 490 | `framelabel_constr` | 5 | 8.7s |  |
| 491 | `function_call` | 12 | 8.4s |  |
| 492 | `function_call_arguments` | 46 | 8.5s |  |
| 493 | `function_call_arguments_enumerate` | 5 | 8.4s |  |
| 494 | `function_call_coercion` | 108 | 8.8s |  |
| 495 | `function_call_default` | 6 | 8.3s |  |
| 496 | `function_call_rest` | 22 | 8.3s |  |
| 497 | `function_call_types` | 3 | 8.4s |  |
| 498 | `function_call_via_apply` | 11 | 8.5s |  |
| 499 | `function_call_via_call` | 3 | 8.5s |  |
| 500 | `function_display_anonymous` | 7 | 3.5s |  |
| 501 | `function_length` | 6 | 8.5s |  |
| 502 | `function_object` | 2 | 8.5s |  |
| 503 | `function_proto` | 5 | 8.4s |  |
| 504 | `function_proto_created` | 61 | 8.5s |  |
| 505 | `function_to_locale_string` | 4 | 8.4s |  |
| 506 | `function_to_string` | 4 | 8.3s |  |
| 507 | `function_type` | 6 | 8.4s |  |
| 508 | `function_unbound_this` | 51 | 8.5s |  |
| 509 | `function_value_of` | 4 | 8.3s |  |
| 510 | `game_input` | 4 | 8.4s |  |
| 511 | `generate_random_bytes` | 3 | 8.5s |  |
| 512 | `geom_transform` | 74 | 30.5s |  |
| 513 | `get_definition_by_name` | 11 | 8.5s |  |
| 514 | `get_qualified_class_name` | 20 | 8.4s |  |
| 515 | `get_qualified_super_class_name` | 18 | 8.4s |  |
| 516 | `get_slot_edge_cases` | 1 | 8.3s |  |
| 517 | `get_timer` | 2 | 3.3s |  |
| 518 | `getglobalslot` | 1 | 8.2s |  |
| 519 | `getouterscope` | 8 | 8.3s |  |
| 520 | `getter_different_namespace_setter` | 2 | 8.2s |  |
| 521 | `glow_filter` | 127 | 8.7s |  |
| 522 | `goto_button_nested_framescript` | 28 | 28.1s |  |
| 523 | `goto_in_constructframe` | 12 | 47.1s |  |
| 524 | `goto_in_scene_last_frame` | 2 | 29.8s |  |
| 525 | `goto_methods` | 56 | 28.8s |  |
| 526 | `goto_methods_swfver10` | 8 | 8.8s |  |
| 527 | `goto_nested_construct_sibling` | 18 | 29.5s |  |
| 528 | `goto_nested_framescript` | 9 | 9.1s |  |
| 529 | `goto_on_orphan` | 15 | 29.1s |  |
| 530 | `gradient_bevel_filter` | 206 | 9.0s |  |
| 531 | `gradient_glow_filter` | 206 | 8.9s |  |
| 532 | `graphic_linkage` | 9 | 9.0s |  |
| 533 | `graphics_bad_direct_commands` | 5 | 12.8s |  |
| 534 | `graphics_bitmap_fill` | 0 | 31.5s |  |
| 535 | `graphics_bitmaps` | 0 | 9.7s |  |
| 536 | `graphics_direct_commands` | 0 | 9.5s |  |
| 537 | `graphics_draw_triangles` | 98 | 30.4s |  |
| 538 | `graphics_gradients` | 0 | 9.1s |  |
| 539 | `graphics_gradients_nulls` | 0 | 9.1s |  |
| 540 | `graphics_path` | 56 | 9.0s |  |
| 541 | `graphics_round_rects` | 0 | 8.8s |  |
| 542 | `graphics_simple_shapes` | 0 | 9.2s |  |
| 543 | `greaterequals` | 512 | 12.8s |  |
| 544 | `greaterthan` | 512 | 12.8s |  |
| 545 | `has_own_property` | 102 | 9.3s |  |
| 546 | `hasownproperty_namespaces` | 2 | 9.0s |  |
| 547 | `hello_world` | 1 | 8.9s |  |
| 548 | `hittest_morph` | 30 | 9.1s |  |
| 549 | `if_eq` | 10 | 9.0s |  |
| 550 | `if_gt` | 1 | 9.0s |  |
| 551 | `if_gte` | 10 | 3.7s |  |
| 552 | `if_lt` | 1 | 1.6s |  |
| 553 | `if_lte` | 10 | 8.9s |  |
| 554 | `if_ne` | 7 | 3.7s |  |
| 555 | `if_stricteq` | 6 | 9.1s |  |
| 556 | `if_strictne` | 11 | 8.9s |  |
| 557 | `ime_linux_dead_keys` | 10 | 8.9s |  |
| 558 | `in` | 102 | 9.4s |  |
| 559 | `inclocal` | 46 | 8.9s |  |
| 560 | `inclocal_i` | 46 | 8.9s |  |
| 561 | `increment` | 46 | 9.0s |  |
| 562 | `increment_i` | 46 | 48.1s |  |
| 563 | `indexing_delete` | 75 | 8.8s |  |
| 564 | `instanceof` | 58 | 9.0s |  |
| 565 | `instantiate_root_character` | 4 | 9.1s |  |
| 566 | `instantiation_on_enter_frame` | 7 | 29.6s |  |
| 567 | `instantiation_on_enterframe_gotoandstop` | 8 | 8.7s |  |
| 568 | `int_constr` | 92 | 8.7s |  |
| 569 | `int_edge_cases` | 19 | 30.0s |  |
| 570 | `int_instanceof` | 3 | 30.1s |  |
| 571 | `int_tofixed` | 1215 | 8.9s |  |
| 572 | `int_toprecision` | 1125 | 9.0s |  |
| 573 | `int_tostring` | 3375 | 9.0s |  |
| 574 | `interactiveobject_enabled` | 25 | 8.7s |  |
| 575 | `interface_namespaces` | 78 | 9.1s |  |
| 576 | `invalid_utf8` | 12 | 8.8s |  |
| 577 | `is_finite` | 46 | 8.7s |  |
| 578 | `is_nan` | 46 | 8.5s |  |
| 579 | `is_prototype_of` | 12 | 8.7s |  |
| 580 | `issue_10221` | 2 | 8.8s |  |
| 581 | `issue_13780` | 12 | 9.1s |  |
| 582 | `issue_14901` | 1 | 9.0s |  |
| 583 | `issue_17675_edittext_paste_maxchars` | 1 | 9.1s |  |
| 584 | `issue_5292` | 5 | 9.1s |  |
| 585 | `issue_8630` | 2 | 29.6s |  |
| 586 | `issue_8630_placeremoveplace` | 15 | 8.9s |  |
| 587 | `issue_8630_placeremoveplace_scriptremove` | 16 | 8.9s |  |
| 588 | `issue_8630_scriptremove` | 11 | 8.9s |  |
| 589 | `istype` | 24 | 3.6s |  |
| 590 | `istypelate` | 58 | 9.3s |  |
| 591 | `istypelate_coerce` | 198 | 10.1s |  |
| 592 | `jpeg_loader_context` | 6 | 9.0s |  |
| 593 | `json_errors` | 9 | 30.2s |  |
| 594 | `json_parse` | 21 | 8.9s |  |
| 595 | `json_stringify` | 12 | 9.3s |  |
| 596 | `json_stringify_function` | 12 | 8.9s |  |
| 597 | `json_stringify_order` | 1 | 8.9s |  |
| 598 | `json_version_gated` | 1 | 9.0s |  |
| 599 | `key_input_80percent` | 1812 | 9.2s |  |
| 600 | `key_input_location` | 126 | 9.1s |  |
| 601 | `key_input_numpad` | 384 | 9.1s |  |
| 602 | `large_preload_from_url` | 27 | 10.4s |  |
| 603 | `large_preload_image_from_bytes` | 25 | 8.9s |  |
| 604 | `lazyinit` | 17 | 8.2s |  |
| 605 | `lessequals` | 512 | 12.2s |  |
| 606 | `lessthan` | 512 | 12.2s |  |
| 607 | `loader_bitmap_transparency` | 14 | 8.3s |  |
| 608 | `loader_bytes_unknown_content` | 14 | 8.3s |  |
| 609 | `loader_child_getdefinition` | 5 | 8.5s |  |
| 610 | `loader_duplicate_coerce` | 3 | 8.4s |  |
| 611 | `loader_duplicate_coerce_new_domain` | 4 | 8.3s |  |
| 612 | `loader_error_in_root_ctor` | 4 | 8.4s |  |
| 613 | `loader_events` | 92 | 8.9s |  |
| 614 | `loader_image` | 8 | 8.6s |  |
| 615 | `loader_jpegxr` | 2 | 27.6s |  |
| 616 | `loader_jpegxr_alpha` | 1 | 27.0s |  |
| 617 | `loader_loadbytes_events` | 30 | 8.8s |  |
| 618 | `loader_loadbytes_invalid_png` | 4 | 27.0s |  |
| 619 | `loader_loadbytes_url` | 12 | 8.5s |  |
| 620 | `loader_loaderurl` | 6 | 8.7s |  |
| 621 | `loader_method` | 85 | 8.3s |  |
| 622 | `loader_noninteractive_try_click_root` | 5 | 27.9s |  |
| 623 | `loader_reuse` | 38 | 8.4s |  |
| 624 | `loader_unknown_content` | 24 | 8.3s |  |
| 625 | `loader_visibility_interactive` | 1 | 8.4s |  |
| 626 | `loaderinfo_events` | 7 | 8.2s |  |
| 627 | `loaderinfo_loadurl` | 12 | 8.1s |  |
| 628 | `loaderinfo_more` | 6 | 3.4s |  |
| 629 | `loaderinfo_properties` | 18 | 27.1s |  |
| 630 | `loaderinfo_properties_not_loaded` | 23 | 8.3s |  |
| 631 | `loaderinfo_quine` | 1005 | 8.2s |  |
| 632 | `loaderinfo_root` | 10 | 8.2s |  |
| 633 | `loaderinfo_root_allows` | 2 | 8.1s |  |
| 634 | `localconnection` | 890 | 10.4s |  |
| 635 | `localconnection_send` | 4 | 8.2s |  |
| 636 | `lshift` | 1058 | 19.9s |  |
| 637 | `mask_reapply` | 1 | 26.9s |  |
| 638 | `math` | 497 | 8.4s |  |
| 639 | `matrix` | 338 | 19.1s |  |
| 640 | `matrix3d` | 57 | 38.2s |  |
| 641 | `matrix3d_append` | 16 | 22.5s |  |
| 642 | `matrix3d_append_prepend_translation` | 42 | 6.8s |  |
| 643 | `matrix3d_compose` | 34 | 7.1s |  |
| 644 | `matrix3d_constructor_clone` | 15 | 6.7s |  |
| 645 | `matrix3d_copy_column` | 83 | 7.0s |  |
| 646 | `matrix3d_copy_raw_data_from` | 55 | 2.8s |  |
| 647 | `matrix3d_copy_raw_data_to` | 38 | 6.9s |  |
| 648 | `matrix3d_copy_row` | 83 | 6.6s |  |
| 649 | `matrix3d_determinant` | 182 | 6.9s |  |
| 650 | `matrix3d_invert` | 18 | 6.8s |  |
| 651 | `matrix3d_position` | 19 | 6.8s |  |
| 652 | `matrix3d_precision` | 28 | 7.0s |  |
| 653 | `matrix3d_prepend` | 16 | 6.7s |  |
| 654 | `matrix3d_raw_data` | 33 | 7.0s |  |
| 655 | `matrix3d_transform_vector` | 52 | 7.7s |  |
| 656 | `matrix3d_transpose` | 5 | 7.6s |  |
| 657 | `method_association` | 5 | 25.7s |  |
| 658 | `method_without_body` | 3 | 25.4s |  |
| 659 | `missing_external_interface` | 10 | 7.4s |  |
| 660 | `modulo` | 1058 | 16.8s |  |
| 661 | `morph_shape` | 2 | 25.6s |  |
| 662 | `mouse_children` | 192 | 26.4s |  |
| 663 | `mouse_click_events` | 90 | 25.4s |  |
| 664 | `mouse_double_click_events` | 188 | 7.3s |  |
| 665 | `mouse_empty_parent` | 4 | 7.5s |  |
| 666 | `mouse_over_while_dragging` | 3 | 8.0s |  |
| 667 | `mouse_pick_avm1_root` | 2 | 25.6s |  |
| 668 | `mouse_pick_button_mode` | 2 | 7.5s |  |
| 669 | `mouse_pick_dobj_mask` | 4 | 7.7s |  |
| 670 | `mouse_pick_masking` | 7 | 25.3s |  |
| 671 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 24.7s |  |
| 672 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.5s |  |
| 673 | `mouse_pick_text` | 8 | 7.5s |  |
| 674 | `mouse_sibling` | 8 | 7.4s |  |
| 675 | `mouse_wheel_events` | 36 | 47.5s |  |
| 676 | `mouseevent_constr` | 66 | 28.5s |  |
| 677 | `mouseevent_stagexy` | 35 | 8.6s |  |
| 678 | `mouseevent_valueof_tostring` | 28 | 8.6s |  |
| 679 | `movieclip_addframescript` | 3 | 29.1s |  |
| 680 | `movieclip_child_property` | 16 | 9.0s |  |
| 681 | `movieclip_constr` | 21 | 29.4s |  |
| 682 | `movieclip_currentlabels` | 17 | 29.1s |  |
| 683 | `movieclip_currentlabels_dupes1` | 46 | 29.6s |  |
| 684 | `movieclip_currentlabels_dupes2` | 30 | 8.8s |  |
| 685 | `movieclip_currentlabels_dupes3` | 67 | 8.8s |  |
| 686 | `movieclip_currentscene` | 12 | 27.8s |  |
| 687 | `movieclip_dispatchevent` | 430 | 8.6s |  |
| 688 | `movieclip_dispatchevent_cancel` | 102 | 8.6s |  |
| 689 | `movieclip_dispatchevent_handlerorder` | 251 | 8.5s |  |
| 690 | `movieclip_dispatchevent_selfadd` | 80 | 8.5s |  |
| 691 | `movieclip_dispatchevent_target` | 899 | 8.6s |  |
| 692 | `movieclip_displayevents` | 96 | 28.0s |  |
| 693 | `movieclip_displayevents_clickgoto` | 676 | 28.2s |  |
| 694 | `movieclip_displayevents_clickgoto2` | 2001 | 9.2s |  |
| 695 | `movieclip_displayevents_clickplay` | 575 | 8.7s |  |
| 696 | `movieclip_displayevents_clicksymbol` | 562 | 8.7s |  |
| 697 | `movieclip_displayevents_constructframegoto` | 140 | 9.0s |  |
| 698 | `movieclip_displayevents_constructframeplay` | 50 | 8.9s |  |
| 699 | `movieclip_displayevents_constructframesymbol` | 144 | 8.7s |  |
| 700 | `movieclip_displayevents_dblhandler` | 21 | 8.7s |  |
| 701 | `movieclip_displayevents_enterframegoto` | 149 | 8.8s |  |
| 702 | `movieclip_displayevents_enterframeplay` | 48 | 8.7s |  |
| 703 | `movieclip_displayevents_enterframesymbol` | 149 | 28.3s |  |
| 704 | `movieclip_displayevents_exitframegoto` | 106 | 8.7s |  |
| 705 | `movieclip_displayevents_exitframeplay` | 44 | 8.6s |  |
| 706 | `movieclip_displayevents_exitframesymbol` | 135 | 8.7s |  |
| 707 | `movieclip_displayevents_looping` | 63 | 28.3s |  |
| 708 | `movieclip_displayevents_stopped` | 113 | 9.1s |  |
| 709 | `movieclip_displayevents_swap` | 96 | 3.4s |  |
| 710 | `movieclip_displayevents_timeline` | 128 | 28.8s |  |
| 711 | `movieclip_drawrect` | 54 | 8.6s |  |
| 712 | `movieclip_frameconstruct_skipped` | 9 | 9.1s |  |
| 713 | `movieclip_goto_during_frame_script` | 15 | 29.1s |  |
| 714 | `movieclip_goto_overwrite` | 14 | 28.6s |  |
| 715 | `movieclip_goto_scene_last_frame_int` | 1 | 28.7s |  |
| 716 | `movieclip_goto_scene_last_frame_label` | 1 | 8.5s |  |
| 717 | `movieclip_gotoandplay` | 15 | 45.3s |  |
| 718 | `movieclip_gotoandstop` | 13 | 27.2s |  |
| 719 | `movieclip_gotoandstop_children` | 4 | 27.2s |  |
| 720 | `movieclip_gotoandstop_framescripts1` | 4 | 7.8s |  |
| 721 | `movieclip_gotoandstop_framescripts2` | 4 | 2.9s |  |
| 722 | `movieclip_gotoandstop_framescripts_self` | 7 | 27.0s |  |
| 723 | `movieclip_gotoandstop_queueing` | 12 | 27.2s |  |
| 724 | `movieclip_hittest` | 67 | 27.1s |  |
| 725 | `movieclip_next_frame` | 2 | 26.8s |  |
| 726 | `movieclip_next_scene` | 6 | 26.9s |  |
| 727 | `movieclip_play` | 3 | 7.7s |  |
| 728 | `movieclip_prev_frame` | 3 | 7.6s |  |
| 729 | `movieclip_prev_scene` | 7 | 7.8s |  |
| 730 | `movieclip_properties` | 79 | 27.0s |  |
| 731 | `movieclip_queued_noop_goto_swf10` | 9 | 7.8s |  |
| 732 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 733 | `movieclip_scenes` | 11 | 7.7s |  |
| 734 | `movieclip_soundtransform` | 831 | 28.8s |  |
| 735 | `movieclip_stop` | 1 | 26.6s |  |
| 736 | `movieclip_super_is_symbol` | 20 | 8.0s |  |
| 737 | `movieclip_symbol_constr` | 8 | 7.8s |  |
| 738 | `movieclip_text_mousedown` | 1 | 7.8s |  |
| 739 | `movieclip_willtrigger` | 5 | 8.0s |  |
| 740 | `multiply` | 1058 | 17.4s |  |
| 741 | `namespace_constr` | 253 | 8.1s |  |
| 742 | `namespace_constr_args` | 1 | 7.7s |  |
| 743 | `namespace_enumeration_order` | 7 | 26.7s |  |
| 744 | `nan_scale` | 9 | 7.7s |  |
| 745 | `native_menu_basic` | 19 | 10.0s |  |
| 746 | `navigateToURL_target_normalize` | 107 | 28.6s |  |
| 747 | `negate` | 30 | 7.8s |  |
| 748 | `negative_volume_panned` | 0 | 8.0s |  |
| 749 | `nested_iteration` | 11 | 7.7s |  |
| 750 | `net_getClassByAlias` | 3 | 7.7s |  |
| 751 | `net_navigateToURL` | 57 | 7.7s |  |
| 752 | `net_stream_play_options` | 6 | 7.7s |  |
| 753 | `netconnection_close` | 55 | 7.7s |  |
| 754 | `netconnection_properties` | 78 | 7.8s |  |
| 755 | `netconnection_send_remote` | 50 | 26.9s |  |
| 756 | `netconnection_serialize_arrays` | 6 | 7.8s |  |
| 757 | `netfilterevent` | 10 | 7.6s |  |
| 758 | `netstream_client` | 10 | 7.9s |  |
| 759 | `netstream_connect` | 7 | 45.5s |  |
| 760 | `netstream_flv_date` | 4 | 8.5s |  |
| 761 | `newactivation_in_script_init` | 3 | 26.9s |  |
| 762 | `newclass_mismatched` | 4 | 8.1s |  |
| 763 | `newclass_twice` | 3 | 8.1s |  |
| 764 | `nonconflicting_declarations` | 0 | 8.2s |  |
| 765 | `null_void_types` | 8 | 8.2s |  |
| 766 | `number_autoconv` | 21 | 8.2s |  |
| 767 | `number_autoconv_amf` | 132 | 8.2s |  |
| 768 | `number_autoconv_array_sort_32bit` | 1 | 8.1s |  |
| 769 | `number_constr` | 58 | 8.2s |  |
| 770 | `number_convert_edge_cases` | 180 | 27.0s |  |
| 771 | `number_toexponential` | 378 | 8.2s |  |
| 772 | `number_toexponential2` | 35 | 8.1s |  |
| 773 | `number_tofixed` | 378 | 8.1s |  |
| 774 | `number_toprecision` | 350 | 8.2s |  |
| 775 | `obfuscated_class_names` | 3 | 8.1s |  |
| 776 | `object_enumeration` | 10 | 8.1s |  |
| 777 | `object_prototype` | 4 | 8.2s |  |
| 778 | `object_to_locale_string` | 2 | 8.1s |  |
| 779 | `object_to_string` | 2 | 8.1s |  |
| 780 | `object_value_of` | 2 | 3.1s |  |
| 781 | `op_coerce` | 54 | 8.2s |  |
| 782 | `op_coerce_x` | 54 | 8.2s |  |
| 783 | `op_escxattr` | 2 | 8.2s |  |
| 784 | `op_escxelem` | 2 | 8.2s |  |
| 785 | `op_lookupswitch` | 4 | 8.2s |  |
| 786 | `optimize_coerce` | 1 | 8.1s |  |
| 787 | `orphan_movie_complex` | 80 | 8.6s |  |
| 788 | `orphan_movie_reorder` | 111 | 27.5s |  |
| 789 | `package_namespace` | 7 | 8.0s |  |
| 790 | `param_default_value_has_zero_cpool_index` | 1 | 8.1s |  |
| 791 | `parent_early_access_child` | 16 | 27.2s |  |
| 792 | `parse_float` | 81 | 8.4s |  |
| 793 | `parse_float_swf10` | 81 | 8.1s |  |
| 794 | `parse_int` | 135 | 47.9s |  |
| 795 | `perspective_projection` | 1443 | 29.2s |  |
| 796 | `perspective_projection_basic` | 40 | 8.7s |  |
| 797 | `pixelbender_ceil` | 77 | 8.8s |  |
| 798 | `pixelbender_conditional` | 138 | 9.1s |  |
| 799 | `pixelbender_conversions` | 270 | 9.2s |  |
| 800 | `pixelbender_dithering` | 8 | 38.8s |  |
| 801 | `pixelbender_div` | 36 | 8.9s |  |
| 802 | `pixelbender_effect_BlurredFocus` | 0 | 38.0s |  |
| 803 | `pixelbender_effect_glassDisplace` | 0 | 15.6s |  |
| 804 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 34.3s |  |
| 805 | `pixelbender_effect_smudge` | 0 | 32.8s |  |
| 806 | `pixelbender_effect_tintype` | 0 | 11.6s |  |
| 807 | `pixelbender_effect_twirl` | 0 | 13.3s |  |
| 808 | `pixelbender_eof` | 7 | 8.7s |  |
| 809 | `pixelbender_images` | 0 | 11.2s |  |
| 810 | `pixelbender_input` | 103 | 29.8s |  |
| 811 | `pixelbender_logicalnot` | 20 | 8.7s |  |
| 812 | `pixelbender_malformed_data` | 190 | 30.0s |  |
| 813 | `pixelbender_multiple_out_params` | 1 | 8.7s |  |
| 814 | `pixelbender_no_out_param` | 6 | 8.6s |  |
| 815 | `pixelbender_outputs` | 13 | 8.9s |  |
| 816 | `pixelbender_padding_bytes` | 22 | 8.8s |  |
| 817 | `pixelbender_param_qualifier` | 512 | 8.9s |  |
| 818 | `pixelbender_parameters` | 1563 | 9.1s |  |
| 819 | `pixelbender_parameters_bool` | 240 | 8.8s |  |
| 820 | `pixelbender_parameters_int_vs_bool` | 54 | 8.7s |  |
| 821 | `pixelbender_parse_errors` | 6 | 8.6s |  |
| 822 | `pixelbender_rsqrt` | 24 | 8.7s |  |
| 823 | `pixelbender_select_kinds` | 8 | 8.8s |  |
| 824 | `pixelbender_shaderdata` | 49 | 8.9s |  |
| 825 | `pixelbender_shaderdata_setter` | 99 | 9.1s |  |
| 826 | `pixelbender_sign` | 60 | 9.0s |  |
| 827 | `pixelbender_vector_output` | 11 | 8.9s |  |
| 828 | `place_and_lookup/swf10` | 33 | 28.4s |  |
| 829 | `place_and_lookup/swf9` | 33 | 1.5s |  |
| 830 | `place_multiple` | 17 | 28.6s |  |
| 831 | `place_object_replace` | 9 | 28.9s |  |
| 832 | `place_object_replace_2` | 24 | 29.1s |  |
| 833 | `place_object_same_depth_frame` | 1 | 8.7s |  |
| 834 | `point` | 132 | 9.2s |  |
| 835 | `primitive_edge_cases` | 1 | 8.5s |  |
| 836 | `primitive_toString` | 277 | 46.6s |  |
| 837 | `primitive_valueOf` | 285 | 8.6s |  |
| 838 | `print_job_options` | 3 | 28.8s |  |
| 839 | `property_is_enumerable` | 114 | 9.4s |  |
| 840 | `property_is_enumerable_reset` | 23 | 8.6s |  |
| 841 | `property_priority` | 22 | 9.0s |  |
| 842 | `property_priority_chained` | 4 | 28.1s |  |
| 843 | `property_priority_definition_names_order` | 2 | 8.8s |  |
| 844 | `property_priority_three_level` | 6 | 28.5s |  |
| 845 | `propertyisenumerable_namespaces` | 6 | 8.6s |  |
| 846 | `prototype_set_null` | 7 | 8.6s |  |
| 847 | `proxy_callproperty` | 24 | 8.6s |  |
| 848 | `proxy_deleteproperty` | 64 | 8.8s |  |
| 849 | `proxy_enumeration` | 34 | 8.7s |  |
| 850 | `proxy_getproperty` | 77 | 8.8s |  |
| 851 | `proxy_hasownproperty` | 8 | 8.7s |  |
| 852 | `proxy_hasproperty` | 32 | 8.7s |  |
| 853 | `proxy_not_overridden` | 54 | 8.8s |  |
| 854 | `proxy_serialize` | 9 | 8.8s |  |
| 855 | `proxy_setproperty` | 42 | 8.9s |  |
| 856 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.8s |  |
| 857 | `qname_constr` | 32 | 8.9s |  |
| 858 | `qname_constr_namespace` | 24 | 9.0s |  |
| 859 | `qname_enumeration` | 9 | 9.0s |  |
| 860 | `qname_indexing` | 23 | 9.0s |  |
| 861 | `qname_tostring` | 25 | 8.9s |  |
| 862 | `qname_valueof` | 29 | 9.0s |  |
| 863 | `rectangle` | 1094 | 9.6s |  |
| 864 | `regexp_constr` | 148 | 9.2s |  |
| 865 | `regexp_exec` | 19 | 8.9s |  |
| 866 | `regexp_extended` | 47 | 8.9s |  |
| 867 | `regexp_multiargs` | 1 | 8.9s |  |
| 868 | `regexp_test` | 27 | 9.0s |  |
| 869 | `regexp_toString` | 10 | 8.9s |  |
| 870 | `register_script_refresh` | 35 | 30.4s |  |
| 871 | `remove_child_clear_field` | 88 | 9.5s |  |
| 872 | `remove_dobj` | 3 | 9.0s |  |
| 873 | `resolve_order` | 4 | 9.1s |  |
| 874 | `responder_null_callbacks` | 1 | 9.0s |  |
| 875 | `rng` | 1 | 10.2s |  |
| 876 | `rootless` | 42 | 9.1s |  |
| 877 | `rshift` | 1058 | 56.7s |  |
| 878 | `rtqname_not_namespace` | 12 | 27.1s |  |
| 879 | `sandbox_type_inherited` | 2 | 8.8s |  |
| 880 | `sandbox_type_local_file` | 1 | 27.3s |  |
| 881 | `sandbox_type_local_network` | 1 | 8.0s |  |
| 882 | `scene_constr` | 8 | 8.3s |  |
| 883 | `scope_optimizations` | 4 | 8.2s |  |
| 884 | `scopes_dont_cache/order-1` | 1 | 27.3s |  |
| 885 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 886 | `security_domain_current` | 2 | 8.3s |  |
| 887 | `selection` | 239 | 9.0s |  |
| 888 | `set_local_0` | 31 | 8.4s |  |
| 889 | `set_property_is_enumerable` | 85 | 8.8s |  |
| 890 | `shaderparameter_value` | 4 | 8.4s |  |
| 891 | `shape_drawrect` | 54 | 8.4s |  |
| 892 | `shared_object_no_root` | 3 | 8.3s |  |
| 893 | `simplebutton_added_to_stage` | 45 | 27.7s |  |
| 894 | `simplebutton_childevents` | 86 | 28.4s |  |
| 895 | `simplebutton_childevents_nested` | 54 | 8.8s |  |
| 896 | `simplebutton_childevents_sprite` | 13 | 8.4s |  |
| 897 | `simplebutton_childprops` | 144 | 8.7s |  |
| 898 | `simplebutton_childshuffle` | 23 | 8.3s |  |
| 899 | `simplebutton_constr` | 36 | 8.7s |  |
| 900 | `simplebutton_constr_childevents` | 48 | 8.7s |  |
| 901 | `simplebutton_constr_params` | 42 | 8.6s |  |
| 902 | `simplebutton_mouseenabled` | 26 | 8.5s |  |
| 903 | `simplebutton_multi_children` | 19 | 8.7s |  |
| 904 | `simplebutton_structure` | 27 | 8.7s |  |
| 905 | `simplebutton_symbolclass` | 68 | 9.2s |  |
| 906 | `slot_disp_id_shared_numbering` | 1 | 29.2s |  |
| 907 | `slots_force_autoassigned` | 1 | 8.5s |  |
| 908 | `socket_after_disconnect` | 1 | 8.6s |  |
| 909 | `socket_close` | 2 | 8.4s |  |
| 910 | `socket_connect` | 4 | 8.4s |  |
| 911 | `socket_errors` | 56 | 45.0s |  |
| 912 | `socket_read_big` | 48 | 8.3s |  |
| 913 | `socket_read_little` | 48 | 3.1s |  |
| 914 | `socket_read_write_object` | 8 | 8.1s |  |
| 915 | `socket_write_big` | 15 | 8.4s |  |
| 916 | `socket_write_little` | 14 | 8.2s |  |
| 917 | `sound_constructor_with_args` | 6 | 8.4s |  |
| 918 | `sound_embeddedprops` | 26 | 27.3s |  |
| 919 | `sound_play` | 19 | 8.4s |  |
| 920 | `sound_rootless` | 7 | 8.2s |  |
| 921 | `sound_valueof` | 33 | 8.3s |  |
| 922 | `soundchannel_soundtransform` | 835 | 29.1s |  |
| 923 | `soundchannel_soundtransform_exists` | 5 | 27.1s |  |
| 924 | `soundchannel_stop` | 8 | 27.1s |  |
| 925 | `soundmixer_buffertime` | 5 | 8.1s |  |
| 926 | `soundmixer_stopall` | 6 | 26.8s |  |
| 927 | `soundtransform` | 442 | 13.7s |  |
| 928 | `space_justifier_clone` | 12 | 8.0s |  |
| 929 | `sprite_with_frames` | 0 | 31.1s |  |
| 930 | `stage3d_agal_cross_product` | 0 | 10.9s |  |
| 931 | `stage3d_agal_upload_errors` | 66 | 10.8s |  |
| 932 | `stage3d_bitmap` | 0 | 32.6s |  |
| 933 | `stage3d_blend` | 81 | 31.9s |  |
| 934 | `stage3d_context3d_string_args` | 158 | 9.2s |  |
| 935 | `stage3d_errors` | 7 | 8.3s |  |
| 936 | `stage3d_errors_atf` | 3 | 9.5s |  |
| 937 | `stage3d_errors_swf_29` | 6 | 8.3s |  |
| 938 | `stage3d_float1_index` | 0 | 29.7s |  |
| 939 | `stage3d_fractal` | 0 | 30.4s |  |
| 940 | `stage3d_ignore_sampler_override` | 0 | 30.0s |  |
| 941 | `stage3d_multistage_triangle` | 3 | 11.1s |  |
| 942 | `stage3d_program_constants_bytearray_be` | 0 | 31.6s |  |
| 943 | `stage3d_program_constants_bytearray_le` | 0 | 11.4s |  |
| 944 | `stage3d_program_constants_invalid_input` | 21 | 9.0s |  |
| 945 | `stage3d_raytrace` | 0 | 34.0s |  |
| 946 | `stage3d_rotating_cube` | 0 | 11.6s |  |
| 947 | `stage3d_sampler` | 0 | 51.9s |  |
| 948 | `stage3d_sampler_partial_upload` | 0 | 11.6s |  |
| 949 | `stage3d_stencil` | 0 | 34.2s |  |
| 950 | `stage3d_texture` | 0 | 17.4s |  |
| 951 | `stage3d_texture_bytearray` | 0 | 12.9s |  |
| 952 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 12.4s |  |
| 953 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 13.5s |  |
| 954 | `stage3d_triangle` | 0 | 11.6s |  |
| 955 | `stage3d_triangle_bytes4` | 0 | 11.6s |  |
| 956 | `stage3d_triangle_float1` | 0 | 11.6s |  |
| 957 | `stage3d_triangle_index_upload` | 0 | 11.5s |  |
| 958 | `stage3d_x_y` | 22 | 8.8s |  |
| 959 | `stage_access` | 10 | 29.2s |  |
| 960 | `stage_displayobject_properties` | 24 | 8.3s |  |
| 961 | `stage_domain_getQualifiedDefinitionNames` | 5 | 8.2s |  |
| 962 | `stage_framerate_nan` | 7 | 27.6s |  |
| 963 | `stage_framerate_negative` | 6 | 8.3s |  |
| 964 | `stage_framerate_zero` | 6 | 8.2s |  |
| 965 | `stage_invalidate` | 38 | 8.5s |  |
| 966 | `stage_loaderinfo_properties` | 24 | 27.9s |  |
| 967 | `stage_mousechildren` | 2 | 8.2s |  |
| 968 | `stage_mouseenabled` | 15 | 8.3s |  |
| 969 | `stage_overriden_setters` | 31 | 8.5s |  |
| 970 | `stage_properties` | 30 | 8.3s |  |
| 971 | `stage_properties2` | 213 | 8.6s |  |
| 972 | `stage_stage3Ds_vector` | 1 | 28.4s |  |
| 973 | `static_length` | 24 | 8.5s |  |
| 974 | `static_text` | 3 | 8.8s |  |
| 975 | `static_var_with_this_in_ctor` | 2 | 8.6s |  |
| 976 | `statictext_text` | 8 | 8.7s |  |
| 977 | `stored_properties` | 11 | 8.6s |  |
| 978 | `strict_equality` | 34 | 8.6s |  |
| 979 | `string_call` | 13 | 8.5s |  |
| 980 | `string_case` | 23 | 8.5s |  |
| 981 | `string_char_at` | 27 | 8.6s |  |
| 982 | `string_char_code_at` | 28 | 8.4s |  |
| 983 | `string_concat_fromcharcode` | 37 | 8.5s |  |
| 984 | `string_constr` | 25 | 8.6s |  |
| 985 | `string_indexof_lastindexof` | 87 | 8.8s |  |
| 986 | `string_length` | 16 | 8.2s |  |
| 987 | `string_locale_compare` | 39 | 8.5s |  |
| 988 | `string_match` | 51 | 8.4s |  |
| 989 | `string_relational_compare` | 4 | 8.1s |  |
| 990 | `string_replace` | 51 | 8.4s |  |
| 991 | `string_search` | 41 | 8.4s |  |
| 992 | `string_slice_substr_substring` | 170 | 9.4s |  |
| 993 | `string_split` | 29 | 3.3s |  |
| 994 | `string_substr_negative` | 21 | 8.2s |  |
| 995 | `string_substr_weird` | 182 | 8.2s |  |
| 996 | `stylesheet` | 221 | 8.8s |  |
| 997 | `stylesheet_parse_color` | 69 | 8.1s |  |
| 998 | `stylesheet_transform` | 307 | 8.6s |  |
| 999 | `sub_super_same_field` | 12 | 3.3s |  |
| 1000 | `subclass_superclass_linked_symbol` | 4 | 8.8s |  |
| 1001 | `subtract` | 1058 | 20.4s |  |
| 1002 | `super_get_call` | 12 | 8.4s |  |
| 1003 | `supercall_two_classobjects` | 2 | 8.5s |  |
| 1004 | `supercalls_coerce` | 8 | 8.5s |  |
| 1005 | `supercalls_weird` | 2 | 8.3s |  |
| 1006 | `superinterface_call` | 20 | 8.4s |  |
| 1007 | `superinterface_instanceof` | 18 | 8.3s |  |
| 1008 | `swf8` | 1 | 8.4s |  |
| 1009 | `swf_10_queued_goto_scripts_construct` | 52 | 8.7s |  |
| 1010 | `swf_9_goto_in_enter_frame` | 17 | 8.5s |  |
| 1011 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.5s |  |
| 1012 | `swf_9_queued_goto_scripts` | 6 | 28.3s |  |
| 1013 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 1014 | `swf_9_versioning` | 2 | 8.4s |  |
| 1015 | `swf_wrong_frame_count` | 38 | 8.8s |  |
| 1016 | `swf_wrong_frame_count_isplaying` | 22 | 27.8s |  |
| 1017 | `symbol_class_binary_data` | 8 | 8.4s |  |
| 1018 | `symbol_class_conflict` | 4 | 8.9s |  |
| 1019 | `symbol_class_root_not_zero` | 1 | 8.2s |  |
| 1020 | `symbolclass_invalid_utf8` | 2 | 8.3s |  |
| 1021 | `system_exit` | 3 | 8.3s |  |
| 1022 | `system_setclipboard_null` | 1 | 8.3s |  |
| 1023 | `tab_ordering_arrows` | 998 | 28.8s |  |
| 1024 | `tab_ordering_automatic_advanced` | 184 | 9.1s |  |
| 1025 | `tab_ordering_automatic_basic` | 45 | 44.2s |  |
| 1026 | `tab_ordering_children` | 116 | 8.1s |  |
| 1027 | `tab_ordering_custom_basic` | 34 | 7.9s |  |
| 1028 | `tab_ordering_stage_tab_children` | 32 | 7.9s |  |
| 1029 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.7s |  |
| 1030 | `tab_ordering_tabbable` | 47 | 7.9s |  |
| 1031 | `tabstop_properties` | 105 | 26.9s |  |
| 1032 | `text_element_basic` | 34 | 8.1s |  |
| 1033 | `text_engine_fontdescription` | 27 | 8.0s |  |
| 1034 | `text_engine_groupelement` | 64 | 8.7s |  |
| 1035 | `text_run` | 7 | 7.8s |  |
| 1036 | `textblock_createline_errors` | 23 | 8.2s |  |
| 1037 | `textblock_createline_fte` | 9 | 26.9s |  |
| 1038 | `textblock_properties` | 118 | 8.4s |  |
| 1039 | `textbox_click` | 37 | 27.0s |  |
| 1040 | `textfield_event` | 66 | 8.2s |  |
| 1041 | `textfield_focusin_event` | 9 | 7.8s |  |
| 1042 | `textfield_input_dead_keys_windows` | 15 | 7.9s |  |
| 1043 | `textfield_input_events` | 25 | 20.4s |  |
| 1044 | `textfield_unload` | 39 | 26.8s |  |
| 1045 | `textformat` | 1134 | 26.6s |  |
| 1046 | `textformat_display` | 14 | 8.0s |  |
| 1047 | `textformat_font_max_length` | 4 | 7.8s |  |
| 1048 | `textline_inapplicable_properties` | 10 | 7.8s |  |
| 1049 | `textline_name` | 1 | 7.8s |  |
| 1050 | `textline_raw_text_length` | 30 | 8.0s |  |
| 1051 | `textline_splitting_basic` | 76 | 8.0s |  |
| 1052 | `textline_throwerror` | 30 | 7.9s |  |
| 1053 | `textline_validity` | 162 | 8.0s |  |
| 1054 | `throw` | 3 | 7.9s |  |
| 1055 | `timeline_scripts` | 3 | 26.6s |  |
| 1056 | `timer` | 90 | 9.0s |  |
| 1057 | `timer_events` | 3 | 8.0s |  |
| 1058 | `timer_finished` | 11 | 8.1s |  |
| 1059 | `timer_invalid_delay` | 30 | 8.0s |  |
| 1060 | `timer_reset` | 8 | 8.2s |  |
| 1061 | `timer_setdelay` | 5 | 7.9s |  |
| 1062 | `trace` | 12 | 46.6s |  |
| 1063 | `truthiness` | 30 | 8.3s |  |
| 1064 | `try_catch` | 11 | 8.3s |  |
| 1065 | `try_catch_typed` | 12 | 8.1s |  |
| 1066 | `typeof` | 30 | 8.2s |  |
| 1067 | `uint_constr` | 92 | 8.1s |  |
| 1068 | `uint_tofixed` | 1215 | 8.2s |  |
| 1069 | `uint_toprecision` | 1125 | 8.1s |  |
| 1070 | `uint_tostring` | 3375 | 8.2s |  |
| 1071 | `uncaught_error_basic` | 2 | 8.1s |  |
| 1072 | `unchecked_function` | 15 | 8.0s |  |
| 1073 | `unescape` | 28 | 7.9s |  |
| 1074 | `url_loader` | 25 | 8.0s |  |
| 1075 | `url_vars` | 27 | 8.1s |  |
| 1076 | `urlrequest` | 18 | 28.7s |  |
| 1077 | `urlstream_basic` | 5 | 8.2s |  |
| 1078 | `urshift` | 1058 | 8.2s |  |
| 1079 | `utils3d` | 7 | 8.1s |  |
| 1080 | `vector3d` | 397 | 8.1s |  |
| 1081 | `vector_class` | 36 | 8.1s |  |
| 1082 | `vector_class_call` | 11 | 27.4s |  |
| 1083 | `vector_coercion` | 66 | 7.9s |  |
| 1084 | `vector_concat` | 90 | 8.0s |  |
| 1085 | `vector_constr` | 107 | 8.1s |  |
| 1086 | `vector_enumeration` | 5 | 8.0s |  |
| 1087 | `vector_every` | 92 | 8.0s |  |
| 1088 | `vector_filter` | 95 | 8.0s |  |
| 1089 | `vector_holes` | 24 | 7.9s |  |
| 1090 | `vector_indexof` | 302 | 7.9s |  |
| 1091 | `vector_insertat` | 270 | 8.1s |  |
| 1092 | `vector_int_access` | 4 | 8.1s |  |
| 1093 | `vector_int_delete` | 11 | 8.2s |  |
| 1094 | `vector_join` | 58 | 8.0s |  |
| 1095 | `vector_lastindexof` | 302 | 8.0s |  |
| 1096 | `vector_legacy` | 10 | 8.1s |  |
| 1097 | `vector_map` | 85 | 7.9s |  |
| 1098 | `vector_object_final` | 1 | 7.8s |  |
| 1099 | `vector_object_toString` | 10 | 7.9s |  |
| 1100 | `vector_pushpop` | 255 | 47.9s |  |
| 1101 | `vector_reborrow_bug` | 10 | 28.0s |  |
| 1102 | `vector_removeat` | 172 | 9.4s |  |
| 1103 | `vector_reverse` | 232 | 9.4s |  |
| 1104 | `vector_shiftunshift` | 252 | 8.1s |  |
| 1105 | `vector_slice` | 331 | 9.9s |  |
| 1106 | `vector_sort` | 905 | 17.9s |  |
| 1107 | `vector_splice` | 693 | 12.2s |  |
| 1108 | `vector_splice_fixed_bug_compat` | 4 | 8.3s |  |
| 1109 | `vector_tostring` | 79 | 8.9s |  |
| 1110 | `verification` | 8 | 27.8s |  |
| 1111 | `verify_abnormal_loop` | 1 | 8.1s |  |
| 1112 | `verify_dxns_without_flag` | 3 | 8.5s |  |
| 1113 | `verify_exception_target_two_jumps` | 1 | 8.1s |  |
| 1114 | `verify_exception_targets_edge_case` | 1 | 8.1s |  |
| 1115 | `verify_illegal_opcode` | 1 | 3.4s |  |
| 1116 | `verify_jump_to_middle_of_op` | 1 | 8.0s |  |
| 1117 | `verify_lookup_switch_edge_case` | 1 | 8.2s |  |
| 1118 | `verify_method_info_oob` | 1 | 1.3s |  |
| 1119 | `verify_stack` | 5 | 8.2s |  |
| 1120 | `verify_typecheck` | 4 | 8.2s |  |
| 1121 | `verify_unreachable_exception` | 2 | 8.1s |  |
| 1122 | `versioned_isplaying` | 2 | 8.1s |  |
| 1123 | `virtual_properties` | 16 | 8.2s |  |
| 1124 | `with` | 4 | 8.1s |  |
| 1125 | `wrong_arg_count` | 7 | 8.4s |  |
| 1126 | `xml_abstract_equality` | 36 | 8.3s |  |
| 1127 | `xml_advanced` | 52 | 8.2s |  |
| 1128 | `xml_appendchild` | 10 | 8.1s |  |
| 1129 | `xml_appendchild_swf_v21` | 13 | 8.4s |  |
| 1130 | `xml_as_attribute` | 9 | 8.1s |  |
| 1131 | `xml_attribute` | 35 | 8.3s |  |
| 1132 | `xml_attribute_name` | 40 | 8.2s |  |
| 1133 | `xml_basic` | 33 | 8.3s |  |
| 1134 | `xml_child` | 25 | 8.1s |  |
| 1135 | `xml_childindex` | 7 | 8.1s |  |
| 1136 | `xml_children` | 43 | 8.8s |  |
| 1137 | `xml_class_call` | 9 | 8.2s |  |
| 1138 | `xml_contains` | 197 | 8.3s |  |
| 1139 | `xml_copy` | 20 | 47.1s |  |
| 1140 | `xml_ctor_from_tostring` | 23 | 28.8s |  |
| 1141 | `xml_delete` | 114 | 8.6s |  |
| 1142 | `xml_descendants` | 83 | 8.5s |  |
| 1143 | `xml_elements` | 6 | 8.4s |  |
| 1144 | `xml_equals_namespace_check` | 2 | 28.3s |  |
| 1145 | `xml_explicit_use_namespace` | 5 | 8.6s |  |
| 1146 | `xml_getdescendants_qname` | 21 | 8.4s |  |
| 1147 | `xml_has_property_via_in` | 26 | 8.4s |  |
| 1148 | `xml_hasownproperty` | 6 | 8.3s |  |
| 1149 | `xml_ignore_white` | 6 | 8.7s |  |
| 1150 | `xml_length` | 2 | 8.4s |  |
| 1151 | `xml_list_as_attribute` | 9 | 8.6s |  |
| 1152 | `xml_list_concat` | 20 | 8.5s |  |
| 1153 | `xml_list_ctor_errors` | 34 | 8.6s |  |
| 1154 | `xml_list_delete_clear_parent` | 6 | 8.4s |  |
| 1155 | `xml_list_enumerate` | 4 | 8.5s |  |
| 1156 | `xml_methods_settings` | 3 | 8.4s |  |
| 1157 | `xml_mismatched_tag` | 37 | 8.5s |  |
| 1158 | `xml_namespace` | 39 | 8.4s |  |
| 1159 | `xml_namespace_methods` | 245 | 8.4s |  |
| 1160 | `xml_namespaced_property` | 7 | 8.4s |  |
| 1161 | `xml_no_namespace` | 1 | 8.6s |  |
| 1162 | `xml_nodekind` | 3 | 8.5s |  |
| 1163 | `xml_normalize` | 35 | 8.6s |  |
| 1164 | `xml_notification_bubbling` | 361 | 8.3s |  |
| 1165 | `xml_parent` | 8 | 8.3s |  |
| 1166 | `xml_set_children` | 17 | 8.6s |  |
| 1167 | `xml_set_name` | 34 | 8.4s |  |
| 1168 | `xml_settings` | 6 | 3.3s |  |
| 1169 | `xml_simple_complex_content` | 47 | 8.6s |  |
| 1170 | `xml_socket` | 11 | 8.8s |  |
| 1171 | `xml_text` | 7 | 8.5s |  |
| 1172 | `xml_tostring` | 6 | 8.4s |  |
| 1173 | `xml_tostring_namespace` | 12 | 8.3s |  |
| 1174 | `xml_unescaping` | 23 | 8.3s |  |
| 1175 | `xml_weird_ignores` | 54 | 8.6s |  |
| 1176 | `xml_wildcard` | 11 | 8.5s |  |
| 1177 | `xmldocument` | 254 | 8.6s |  |
| 1178 | `xmlnode` | 3540 | 8.7s |  |
| 1179 | `zero_frame_clip` | 3 | 9.1s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.6s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.3s |  |
| 3 | `blend_transform` | 1 | 1 | 9.2s |  |
| 4 | `bounds_mode` | 6 | 6 | 8.9s |  |
| 5 | `coerce_property` | 3 | 3 | 8.2s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 8.1s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 28.6s |  |
| 8 | `edittext_device_transform_layout` | 20 | 20 | 6.7s |  |
| 9 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.9s |  |
| 10 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 6.8s |  |
| 11 | `edittext_tab_stops` | 6 | 6 | 9.0s |  |
| 12 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 8.5s |  |
| 13 | `error_1034_debug_string` | 19 | 19 | 8.5s |  |
| 14 | `freestanding_superclass` | 2 | 4 | 27.4s |  |
| 15 | `getouterscope_two_classobjects` | 4 | 4 | 8.3s |  |
| 16 | `goto_framescript_queued` | 5 | 5 | 27.4s |  |
| 17 | `graphics_draw_path` | 50 | 50 | 30.4s |  |
| 18 | `groupelement_text` | 2 | 2 | 9.1s |  |
| 19 | `int_toexponential` | 76 | 76 | 9.0s |  |
| 20 | `matrix3d_append_rotation` | 1 | 3 | 6.9s |  |
| 21 | `matrix3d_recompose_edge_cases` | 85 | 85 | 7.6s |  |
| 22 | `simplebutton_childevents_script_order` | 4 | 4 | 8.7s |  |
| 23 | `slot_holes_fail` | 1 | 1 | 8.3s |  |
| 24 | `slot_id_exceeds_trait_count` | 1 | 1 | 28.4s |  |
| 25 | `soundchannel_position` | 74 | 74 | 28.0s |  |
| 26 | `soundchannel_soundcomplete` | 10 | 10 | 8.5s |  |
| 27 | `sprite_dropTarget` | 15 | 15 | 26.6s |  |
| 28 | `swf_9_goto_in_construct_frame` | 12 | 12 | 28.4s |  |
| 29 | `textblock_line_changes` | 44 | 44 | 8.6s |  |
| 30 | `textblock_releaselines` | 4 | 4 | 9.5s |  |
| 31 | `uint_toexponential` | 100 | 100 | 8.2s |  |
| 32 | `uncaught_errors_stringified` | 15 | 15 | 8.2s |  |
| 33 | `weird_superinterface_properties` | 1 | 1 | 27.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**17 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 2 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 3 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 4 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 5 | `vector3d_near_equals` | 83.8% | 67 | 80 | 13 |  |
| 6 | `matrix3d_copy_from` | 78.9% | 15 | 19 | 4 |  |
| 7 | `matrix3d_copy_to_matrix3d` | 78.9% | 15 | 19 | 4 |  |
| 8 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 9 | `displayobject_getrect` | 68.8% | 11 | 16 | 5 |  |
| 10 | `large_preload_from_bytes` | 68.6% | 35 | 51 | 16 |  |
| 11 | `number_to_string` | 67.1% | 237 | 353 | 116 |  |
| 12 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 13 | `loader_duplicate_class` | 60.4% | 29 | 48 | 19 |  |
| 14 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 15 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 16 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 17 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**39 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 2 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 3 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 4 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 5 | `vector3d_near_equals` | 83.8% | 67/80 | 80 | 80 |  |
| 6 | `matrix3d_copy_from` | 78.9% | 15/19 | 16 | 19 |  |
| 7 | `matrix3d_copy_to_matrix3d` | 78.9% | 15/19 | 16 | 19 |  |
| 8 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 9 | `displayobject_getrect` | 68.8% | 11/16 | 16 | 16 |  |
| 10 | `large_preload_from_bytes` | 68.6% | 35/51 | 46 | 51 |  |
| 11 | `number_to_string` | 67.1% | 237/353 | 353 | 353 |  |
| 12 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 13 | `loader_duplicate_class` | 60.4% | 29/48 | 48 | 48 |  |
| 14 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 15 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 16 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 17 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 18 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 19 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 20 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 21 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 22 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 23 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 24 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 25 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 26 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 27 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 28 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 29 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 30 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 31 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 32 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 33 | `matrix3d_append_prepend_scale` | 0.0% | 0/86 | 46 | 86 |  |
| 34 | `matrix3d_interpolate` | 0.0% | 0/21 | 3 | 21 |  |
| 35 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 36 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 37 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 38 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 39 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
