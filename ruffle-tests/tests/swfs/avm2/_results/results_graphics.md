# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-11 18:18 UTC

**Git SHA**: `60bb82a8a6`

**Run Duration**: 231m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1270 |
| Passing | **1200** (94.5%) |
| Ruffle-matched | 36 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1236** (97.3%) |
| Failing | 34 |
| Total expected lines | 155348 |
| Matching lines | 152229 (98.0%) |
| Mismatched lines | 3119 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 34 | 100.0% |

## Passing Tests

**1200 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 25.1s |  |
| 2 | `accessibility` | 1 | 7.3s |  |
| 3 | `accessibilityimplementation` | 18 | 24.9s |  |
| 4 | `activation_class` | 6 | 7.2s |  |
| 5 | `add` | 1058 | 15.5s |  |
| 6 | `agal_compiler` | 13 | 9.2s |  |
| 7 | `air_datagram_socket` | 1 | 9.1s |  |
| 8 | `air_hidden_lookup` | 2 | 7.2s |  |
| 9 | `air_ifilepromise` | 1 | 7.1s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 7.3s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.0s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.0s |  |
| 13 | `all_classes/display/swf10` | 2569 | 7.4s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.1s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.1s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.1s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.1s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.1s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 7.3s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.1s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.0s |  |
| 22 | `all_classes/errors/swf10` | 140 | 7.5s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.1s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.0s |  |
| 25 | `all_classes/events/swf10` | 1638 | 7.3s |  |
| 26 | `all_classes/events/swf11` | 1750 | 1.0s |  |
| 27 | `all_classes/events/swf12` | 1814 | 1.0s |  |
| 28 | `all_classes/events/swf30` | 2353 | 1.1s |  |
| 29 | `all_classes/events/swf9` | 1030 | 1.1s |  |
| 30 | `all_classes/security/swf11` | 3 | 7.5s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.0s |  |
| 32 | `all_classes/security/swf13` | 53 | 1.0s |  |
| 33 | `all_classes/security/swf30` | 53 | 1.0s |  |
| 34 | `all_classes/xml/swf30` | 116 | 7.4s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.1s |  |
| 36 | `amf_array_serialization` | 17 | 27.6s |  |
| 37 | `amf_custom_obj` | 26 | 7.3s |  |
| 38 | `amf_dictionary` | 9 | 7.3s |  |
| 39 | `amf_function` | 46 | 7.1s |  |
| 40 | `amf_invalid_date` | 2 | 7.3s |  |
| 41 | `amf_missing_prop` | 6 | 7.2s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 7.2s |  |
| 43 | `amf_setter_error` | 8 | 7.5s |  |
| 44 | `amf_vector` | 40 | 27.7s |  |
| 45 | `amf_xml` | 6 | 8.4s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 8.8s |  |
| 47 | `application_domain` | 4 | 8.4s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 27.7s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 8.3s |  |
| 50 | `array_access` | 18 | 8.4s |  |
| 51 | `array_access_interpreter` | 4 | 8.4s |  |
| 52 | `array_access_no_pubns` | 2 | 8.3s |  |
| 53 | `array_concat` | 41 | 8.4s |  |
| 54 | `array_constr` | 10 | 8.4s |  |
| 55 | `array_delete` | 44 | 8.4s |  |
| 56 | `array_enumeration` | 10 | 8.4s |  |
| 57 | `array_enumeration_elements` | 11 | 8.4s |  |
| 58 | `array_every` | 8 | 8.3s |  |
| 59 | `array_filter` | 6 | 8.3s |  |
| 60 | `array_foreach` | 18 | 8.4s |  |
| 61 | `array_hasownproperty` | 11 | 8.3s |  |
| 62 | `array_holes` | 9 | 8.3s |  |
| 63 | `array_index_max` | 84 | 8.3s |  |
| 64 | `array_indexof` | 25 | 8.4s |  |
| 65 | `array_join` | 26 | 8.4s |  |
| 66 | `array_lastindexof` | 29 | 8.4s |  |
| 67 | `array_length` | 14 | 8.4s |  |
| 68 | `array_literal` | 3 | 8.3s |  |
| 69 | `array_map` | 8 | 8.2s |  |
| 70 | `array_pop` | 52 | 8.4s |  |
| 71 | `array_push` | 24 | 8.4s |  |
| 72 | `array_reborrow_bug` | 6 | 8.3s |  |
| 73 | `array_reverse` | 28 | 8.4s |  |
| 74 | `array_shift` | 51 | 3.3s |  |
| 75 | `array_slice` | 39 | 8.4s |  |
| 76 | `array_some` | 8 | 8.4s |  |
| 77 | `array_sort` | 297 | 8.8s |  |
| 78 | `array_sort_fun_swf12` | 2 | 8.4s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 80 | `array_sort_random` | 210 | 8.4s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 8.4s |  |
| 82 | `array_sorton` | 545 | 9.2s |  |
| 83 | `array_sparse_ops` | 41 | 8.5s |  |
| 84 | `array_splice` | 133 | 8.6s |  |
| 85 | `array_splice2` | 428 | 24.4s |  |
| 86 | `array_splice_types` | 48 | 7.4s |  |
| 87 | `array_storage` | 8 | 24.1s |  |
| 88 | `array_tolocalestring` | 9 | 7.0s |  |
| 89 | `array_tostring` | 12 | 7.0s |  |
| 90 | `array_unshift` | 24 | 7.0s |  |
| 91 | `array_valueof` | 9 | 6.9s |  |
| 92 | `array_vector_null_callback` | 10 | 7.1s |  |
| 93 | `astype` | 28 | 7.1s |  |
| 94 | `astypelate` | 24 | 7.2s |  |
| 95 | `astypelate_propagates` | 1 | 7.1s |  |
| 96 | `asymmetric_key_events` | 11 | 6.9s |  |
| 97 | `automation_classes` | 122 | 7.1s |  |
| 98 | `av_classes` | 340 | 7.0s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 6.9s |  |
| 100 | `avm2_catchup_dobj` | 158 | 7.6s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 79.3s |  |
| 102 | `bevel_filter` | 187 | 7.2s |  |
| 103 | `bitand` | 1058 | 16.1s |  |
| 104 | `bitmap_constr` | 17 | 7.3s |  |
| 105 | `bitmap_data` | 1000 | 13.3s |  |
| 106 | `bitmap_pixelsnapping` | 2 | 22.4s |  |
| 107 | `bitmap_properties` | 23 | 6.9s |  |
| 108 | `bitmap_subclass` | 7 | 8.1s |  |
| 109 | `bitmap_subclass_properties` | 9 | 7.3s |  |
| 110 | `bitmap_timeline` | 9 | 7.2s |  |
| 111 | `bitmapdata_accuracy` | 1 | 39.8s |  |
| 112 | `bitmapdata_applyfilter_blur` | 0 | 23.0s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.5s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | 0 | 22.7s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 23.0s |  |
| 116 | `bitmapdata_applyfilter_identity` | 4 | 22.4s |  |
| 117 | `bitmapdata_clone` | 13 | 7.4s |  |
| 118 | `bitmapdata_colortransform` | 0 | 7.4s |  |
| 119 | `bitmapdata_colortransform_oob` | 2 | 6.8s |  |
| 120 | `bitmapdata_constr` | 22 | 2.8s |  |
| 121 | `bitmapdata_constructor_from_timeline` | 1 | 7.3s |  |
| 122 | `bitmapdata_copychannel` | 0 | 23.8s |  |
| 123 | `bitmapdata_copypixels` | 23 | 23.6s |  |
| 124 | `bitmapdata_copypixels_alpha_combine` | 13 | 7.0s |  |
| 125 | `bitmapdata_copypixels_blend_over` | 1 | 8.5s |  |
| 126 | `bitmapdata_copypixelstobytearray` | 39 | 8.4s |  |
| 127 | `bitmapdata_dispose` | 7 | 8.5s |  |
| 128 | `bitmapdata_draw` | 0 | 28.9s |  |
| 129 | `bitmapdata_draw_alpha_erase` | 8 | 8.6s |  |
| 130 | `bitmapdata_draw_cab_quality` | 0 | 29.1s |  |
| 131 | `bitmapdata_draw_colortransform` | 0 | 27.9s |  |
| 132 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 27.9s |  |
| 133 | `bitmapdata_draw_filters` | 0 | 27.8s |  |
| 134 | `bitmapdata_draw_masks` | 0 | 8.8s |  |
| 135 | `bitmapdata_draw_rotation` | 0 | 8.7s |  |
| 136 | `bitmapdata_draw_self_via_graphic` | 0 | 8.6s |  |
| 137 | `bitmapdata_draw_stage` | 0 | 27.7s |  |
| 138 | `bitmapdata_drawwithquality` | 0 | 9.0s |  |
| 139 | `bitmapdata_embedded` | 9 | 8.7s |  |
| 140 | `bitmapdata_fillrect` | 0 | 8.6s |  |
| 141 | `bitmapdata_filter_sourcerect` | 0 | 28.1s |  |
| 142 | `bitmapdata_floodfill` | 35 | 8.4s |  |
| 143 | `bitmapdata_getpixels` | 39 | 27.7s |  |
| 144 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 145 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 146 | `bitmapdata_hittest` | 112 | 9.1s |  |
| 147 | `bitmapdata_hittest_threshold` | 18 | 8.5s |  |
| 148 | `bitmapdata_opaque` | 0 | 8.7s |  |
| 149 | `bitmapdata_pixeldissolve` | 1037 | 9.1s |  |
| 150 | `bitmapdata_pixeldissolve_image` | 0 | 8.7s |  |
| 151 | `bitmapdata_rectangle_rounding` | 16 | 8.3s |  |
| 152 | `bitmapdata_setpixels` | 286 | 8.5s |  |
| 153 | `bitmapdata_setvector` | 26 | 8.5s |  |
| 154 | `bitmapdata_sync` | 0 | 28.0s |  |
| 155 | `bitmapdata_threshold` | 176 | 9.1s |  |
| 156 | `bitmapdata_zero_size` | 8 | 8.4s |  |
| 157 | `bitnot` | 46 | 8.4s |  |
| 158 | `bitor` | 1058 | 20.6s |  |
| 159 | `bitxor` | 1058 | 20.4s |  |
| 160 | `blend_mode_null` | 1 | 8.3s |  |
| 161 | `blend_multiply_alpha` | 0 | 8.6s |  |
| 162 | `blend_scroll` | 0 | 8.6s |  |
| 163 | `blend_shader_luma_lighten` | 3 | 9.1s |  |
| 164 | `blur_filter` | 43 | 8.7s |  |
| 165 | `boolean_constr` | 32 | 22.0s |  |
| 166 | `boolean_negation` | 30 | 6.7s |  |
| 167 | `boolean_tostring` | 8 | 6.7s |  |
| 168 | `broadcast_event` | 7 | 6.7s |  |
| 169 | `button_bounds` | 1 | 6.8s |  |
| 170 | `button_hittest` | 2 | 21.9s |  |
| 171 | `button_nested_frame` | 48 | 22.2s |  |
| 172 | `button_nested_frame_simple` | 27 | 7.0s |  |
| 173 | `bytearray` | 48 | 6.9s |  |
| 174 | `bytearray_compress` | 31 | 22.0s |  |
| 175 | `bytearray_errors` | 24 | 6.8s |  |
| 176 | `bytearray_method_serialization` | 1 | 6.8s |  |
| 177 | `bytearray_oom` | 3 | 6.7s |  |
| 178 | `bytearray_readobject_amf0` | 50 | 6.8s |  |
| 179 | `bytearray_readobject_amf3` | 53 | 6.8s |  |
| 180 | `bytearray_readutf8bytes_with_bom` | 16 | 6.7s |  |
| 181 | `bytearray_serialization` | 3 | 6.7s |  |
| 182 | `bytearray_string_null` | 19 | 6.9s |  |
| 183 | `bytearray_tostring` | 15 | 6.7s |  |
| 184 | `bytearray_utf16` | 8 | 6.7s |  |
| 185 | `bytearray_writeobject` | 24 | 6.7s |  |
| 186 | `callee_in_initializer` | 6 | 6.7s |  |
| 187 | `callproplex_class` | 1 | 6.7s |  |
| 188 | `capabilities_resolution` | 8 | 23.0s |  |
| 189 | `catch_class` | 6 | 6.7s |  |
| 190 | `catch_scope_slot` | 7 | 6.8s |  |
| 191 | `checkfilter` | 4 | 2.6s |  |
| 192 | `class_call` | 32 | 6.8s |  |
| 193 | `class_cast_call` | 14 | 6.7s |  |
| 194 | `class_enumeration` | 4 | 6.7s |  |
| 195 | `class_has_own_property` | 2 | 6.7s |  |
| 196 | `class_init_interpreter_mode` | 1 | 6.7s |  |
| 197 | `class_is` | 32 | 6.8s |  |
| 198 | `class_methods` | 5 | 6.7s |  |
| 199 | `class_object_properties` | 10 | 6.8s |  |
| 200 | `class_singleton` | 18 | 6.8s |  |
| 201 | `class_supercalls_errors` | 35 | 6.9s |  |
| 202 | `class_supercalls_mismatched` | 26 | 6.8s |  |
| 203 | `class_superclass_wrong_order` | 1 | 6.7s |  |
| 204 | `class_to_locale_string` | 2 | 6.7s |  |
| 205 | `class_to_string` | 2 | 8.2s |  |
| 206 | `class_value_of` | 2 | 8.2s |  |
| 207 | `click_block` | 5 | 28.0s |  |
| 208 | `click_invisible` | 3 | 8.4s |  |
| 209 | `closures` | 12 | 8.2s |  |
| 210 | `coerce_return_type` | 40 | 8.4s |  |
| 211 | `coerce_return_type_fail` | 2 | 8.2s |  |
| 212 | `coerce_return_void` | 3 | 8.2s |  |
| 213 | `coerce_string` | 86 | 8.4s |  |
| 214 | `coerce_string_precision` | 28 | 8.2s |  |
| 215 | `coerce_to_primitive_side_effects` | 29 | 27.2s |  |
| 216 | `color_matrix_filter` | 19 | 8.4s |  |
| 217 | `construct_errors_swf10` | 8 | 8.3s |  |
| 218 | `construct_frame_list` | 22 | 27.1s |  |
| 219 | `construct_interface` | 3 | 8.2s |  |
| 220 | `constructor_call` | 3 | 8.2s |  |
| 221 | `constructors_vs_timeline` | 5 | 27.2s |  |
| 222 | `constructprop_dynamic_primitive` | 7 | 8.3s |  |
| 223 | `constructprop_method` | 2 | 8.2s |  |
| 224 | `constructsuper_null` | 2 | 8.2s |  |
| 225 | `content_element_basic` | 50 | 8.5s |  |
| 226 | `context3d_creation` | 9 | 8.3s |  |
| 227 | `control_flow_bool` | 4 | 8.2s |  |
| 228 | `control_flow_stricteq` | 8 | 8.2s |  |
| 229 | `convert_boolean` | 30 | 8.3s |  |
| 230 | `convert_integer` | 90 | 8.4s |  |
| 231 | `convert_number` | 56 | 8.3s |  |
| 232 | `convert_uinteger` | 90 | 8.4s |  |
| 233 | `convolution_filter` | 89 | 8.4s |  |
| 234 | `core_exceptions` | 47 | 9.1s |  |
| 235 | `cpool_index_invalid_bytecode_1` | 6 | 8.3s |  |
| 236 | `cpool_index_invalid_bytecode_2` | 3 | 8.2s |  |
| 237 | `cpool_index_invalid_bytecode_3` | 1 | 8.2s |  |
| 238 | `cross_api_version_call_newer` | 12 | 8.8s |  |
| 239 | `cross_api_version_call_older` | 12 | 8.6s |  |
| 240 | `cryptscore` | 11 | 8.3s |  |
| 241 | `currency_parse_result` | 7 | 8.3s |  |
| 242 | `date` | 30 | 8.6s |  |
| 243 | `date_parse` | 36 | 8.2s |  |
| 244 | `declocal` | 46 | 3.1s |  |
| 245 | `declocal_i` | 46 | 8.3s |  |
| 246 | `decode_uri` | 71 | 8.7s |  |
| 247 | `decrement` | 46 | 8.4s |  |
| 248 | `decrement_i` | 46 | 8.5s |  |
| 249 | `default_values` | 7 | 8.4s |  |
| 250 | `delayed_symbolclass` | 28 | 28.1s |  |
| 251 | `describe_type_basic` | 152 | 8.6s |  |
| 252 | `describe_type_json` | 301 | 8.6s |  |
| 253 | `describe_type_metadata` | 125 | 8.6s |  |
| 254 | `describe_type_native` | 23 | 8.7s |  |
| 255 | `dictionary_access` | 62 | 8.8s |  |
| 256 | `dictionary_access_no_pubns` | 2 | 8.4s |  |
| 257 | `dictionary_delete` | 101 | 9.0s |  |
| 258 | `dictionary_foreach` | 42 | 8.8s |  |
| 259 | `dictionary_hasownproperty` | 63 | 8.9s |  |
| 260 | `dictionary_in` | 62 | 8.8s |  |
| 261 | `dictionary_iter_modify` | 8 | 8.5s |  |
| 262 | `dictionary_namespaces` | 36 | 8.6s |  |
| 263 | `displacement_map_filter` | 61 | 8.5s |  |
| 264 | `displayobject_alpha` | 277 | 8.4s |  |
| 265 | `displayobject_blendmode` | 0 | 29.3s |  |
| 266 | `displayobject_colortransform_nested` | 0 | 27.9s |  |
| 267 | `displayobject_early_init` | 54 | 10.3s |  |
| 268 | `displayobject_filters` | 17 | 8.6s |  |
| 269 | `displayobject_from_enterframe` | 1 | 28.1s |  |
| 270 | `displayobject_getbounds_shape` | 0 | 28.4s |  |
| 271 | `displayobject_height` | 6052 | 28.3s |  |
| 272 | `displayobject_hittestobject` | 32 | 8.5s |  |
| 273 | `displayobject_hittestpoint` | 49 | 8.8s |  |
| 274 | `displayobject_hittestpoint_boundary` | 65 | 28.6s |  |
| 275 | `displayobject_hittestpoint_root` | 13 | 8.6s |  |
| 276 | `displayobject_invalid_floats` | 60 | 8.4s |  |
| 277 | `displayobject_invalid_props` | 3 | 3.1s |  |
| 278 | `displayobject_mask` | 3 | 8.9s |  |
| 279 | `displayobject_mask_self_referential` | 0 | 8.3s |  |
| 280 | `displayobject_metaData` | 3 | 8.4s |  |
| 281 | `displayobject_name` | 22 | 27.6s |  |
| 282 | `displayobject_name_from_timeline` | 24 | 8.5s |  |
| 283 | `displayobject_opaque_background` | 6 | 8.4s |  |
| 284 | `displayobject_parent` | 12 | 8.4s |  |
| 285 | `displayobject_root` | 24 | 8.4s |  |
| 286 | `displayobject_rotation` | 1284 | 8.6s |  |
| 287 | `displayobject_scrollrect` | 33 | 10.8s |  |
| 288 | `displayobject_set_matrix_nested` | 0 | 28.5s |  |
| 289 | `displayobject_set_name_loaded` | 3 | 8.9s |  |
| 290 | `displayobject_subclass` | 2 | 8.6s |  |
| 291 | `displayobject_transform` | 89 | 28.3s |  |
| 292 | `displayobject_visible` | 23 | 28.4s |  |
| 293 | `displayobject_width` | 4852 | 28.6s |  |
| 294 | `displayobject_x` | 614 | 8.6s |  |
| 295 | `displayobject_y` | 617 | 8.6s |  |
| 296 | `displayobjectcontainer_addchild` | 32 | 8.6s |  |
| 297 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 8.6s |  |
| 298 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.6s |  |
| 299 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 8.5s |  |
| 300 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 8.6s |  |
| 301 | `displayobjectcontainer_addchildat` | 42 | 8.5s |  |
| 302 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.4s |  |
| 303 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 8.5s |  |
| 304 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.6s |  |
| 305 | `displayobjectcontainer_contains` | 66 | 28.3s |  |
| 306 | `displayobjectcontainer_getchildat` | 4 | 8.6s |  |
| 307 | `displayobjectcontainer_getchildbyname` | 9 | 8.5s |  |
| 308 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 8.5s |  |
| 309 | `displayobjectcontainer_getchildindex` | 28 | 8.5s |  |
| 310 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 28.6s |  |
| 311 | `displayobjectcontainer_removechild` | 10 | 8.6s |  |
| 312 | `displayobjectcontainer_removechild_errors` | 4 | 8.5s |  |
| 313 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 8.6s |  |
| 314 | `displayobjectcontainer_removechildat` | 18 | 8.5s |  |
| 315 | `displayobjectcontainer_removechildren` | 51 | 8.8s |  |
| 316 | `displayobjectcontainer_setchildindex` | 42 | 8.3s |  |
| 317 | `displayobjectcontainer_stopallmovieclips` | 2 | 28.7s |  |
| 318 | `displayobjectcontainer_swapchildren` | 42 | 8.6s |  |
| 319 | `displayobjectcontainer_swapchildrenat` | 42 | 8.7s |  |
| 320 | `displayobjectcontainer_timelineinstance` | 48 | 28.3s |  |
| 321 | `divide` | 1058 | 20.9s |  |
| 322 | `doabc_and_symbolclass_script_init_goto` | 7 | 28.8s |  |
| 323 | `doabc_and_symbolclass_script_init_normal` | 6 | 8.5s |  |
| 324 | `doabc_is_eager` | 1 | 29.1s |  |
| 325 | `documentclass` | 9 | 8.7s |  |
| 326 | `domain_memory` | 133 | 9.8s |  |
| 327 | `drag_drop` | 10 | 6.2s |  |
| 328 | `drop_shadow_filter` | 172 | 6.6s |  |
| 329 | `duplicate_defs` | 1 | 5.8s |  |
| 330 | `eager_init` | 1 | 6.5s |  |
| 331 | `east_asian_justifier_clone` | 8 | 20.6s |  |
| 332 | `edit_text_linkage` | 7 | 6.2s |  |
| 333 | `edittext_align` | 60 | 7.0s |  |
| 334 | `edittext_always_show_selection` | 0 | 22.3s |  |
| 335 | `edittext_antialiastype` | 296 | 6.4s |  |
| 336 | `edittext_at_point_methods_basic` | 16 | 7.3s |  |
| 337 | `edittext_autosize` | 39 | 6.3s |  |
| 338 | `edittext_autosize_align` | 0 | 20.8s |  |
| 339 | `edittext_autosize_height_dynamic` | 60 | 20.9s |  |
| 340 | `edittext_autosize_height_input` | 60 | 6.2s |  |
| 341 | `edittext_autosize_lazy_bounds_events` | 65 | 6.2s |  |
| 342 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.8s |  |
| 343 | `edittext_autosize_lazy_bounds_props` | 490 | 7.3s |  |
| 344 | `edittext_autosize_lazy_bounds_visual` | 0 | 6.2s |  |
| 345 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.0s |  |
| 346 | `edittext_bottom_scroll_v_basic` | 210 | 5.9s |  |
| 347 | `edittext_bounds_scale` | 24 | 20.3s |  |
| 348 | `edittext_bullet` | 30 | 6.1s |  |
| 349 | `edittext_default_format` | 221 | 6.4s |  |
| 350 | `edittext_default_format_empty` | 136 | 6.1s |  |
| 351 | `edittext_empty_text_format` | 7 | 5.8s |  |
| 352 | `edittext_focus_selection` | 5 | 6.0s |  |
| 353 | `edittext_font_size` | 45 | 6.2s |  |
| 354 | `edittext_format_empty_font` | 8 | 2.0s |  |
| 355 | `edittext_get_char_index_at_point` | 4 | 22.4s |  |
| 356 | `edittext_get_line_index_at_point` | 2 | 21.0s |  |
| 357 | `edittext_get_line_index_of_char` | 76 | 6.6s |  |
| 358 | `edittext_getcharboundaries` | 172 | 6.3s |  |
| 359 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.2s |  |
| 360 | `edittext_getcharboundaries_scroll` | 85 | 6.2s |  |
| 361 | `edittext_getlinemetrics` | 146 | 6.3s |  |
| 362 | `edittext_html` | 3101 | 6.2s |  |
| 363 | `edittext_html_condensewhite` | 487 | 6.2s |  |
| 364 | `edittext_html_entity` | 4 | 5.9s |  |
| 365 | `edittext_html_font_size_swf12` | 267 | 6.0s |  |
| 366 | `edittext_html_font_size_swf13` | 273 | 5.8s |  |
| 367 | `edittext_html_roundtrip` | 17 | 7.8s |  |
| 368 | `edittext_ime_focus_lost` | 9 | 26.0s |  |
| 369 | `edittext_input_control` | 12 | 25.9s |  |
| 370 | `edittext_leading` | 9 | 8.1s |  |
| 371 | `edittext_letter_spacing` | 15 | 8.0s |  |
| 372 | `edittext_line_methods` | 294 | 9.0s |  |
| 373 | `edittext_line_metrics` | 11 | 28.2s |  |
| 374 | `edittext_margins` | 25 | 8.1s |  |
| 375 | `edittext_max_scroll_h_basic` | 475 | 9.0s |  |
| 376 | `edittext_max_scroll_v_basic` | 1000 | 7.7s |  |
| 377 | `edittext_mouse_selection` | 363 | 26.9s |  |
| 378 | `edittext_mousedown` | 3 | 8.0s |  |
| 379 | `edittext_mouseenabled` | 26 | 7.2s |  |
| 380 | `edittext_newline_character` | 22 | 7.3s |  |
| 381 | `edittext_newline_stripping` | 64 | 9.8s |  |
| 382 | `edittext_newlines` | 30 | 7.7s |  |
| 383 | `edittext_paragraph_methods` | 257 | 7.3s |  |
| 384 | `edittext_paste_events` | 8 | 7.6s |  |
| 385 | `edittext_paste_maxchars` | 4 | 7.2s |  |
| 386 | `edittext_paste_restrict` | 16 | 7.1s |  |
| 387 | `edittext_restrict` | 191 | 7.1s |  |
| 388 | `edittext_restrict_events` | 22 | 7.1s |  |
| 389 | `edittext_scrollh` | 10 | 2.5s |  |
| 390 | `edittext_selected_text` | 9 | 7.1s |  |
| 391 | `edittext_set_html_same` | 17 | 7.4s |  |
| 392 | `edittext_set_text_vs_html` | 9 | 7.4s |  |
| 393 | `edittext_stylesheet` | 536 | 7.6s |  |
| 394 | `edittext_stylesheet_custom_tag` | 76 | 7.4s |  |
| 395 | `edittext_stylesheet_display` | 272 | 7.5s |  |
| 396 | `edittext_tag_indent` | 49 | 25.5s |  |
| 397 | `edittext_underline` | 40 | 7.6s |  |
| 398 | `edittext_width_height` | 103 | 7.7s |  |
| 399 | `edittext_wordwrap_word` | 150 | 7.5s |  |
| 400 | `edittext_wrap_breaks` | 2375 | 7.9s |  |
| 401 | `element_format_clone` | 44 | 7.5s |  |
| 402 | `element_format_constructor_order` | 64 | 3.0s |  |
| 403 | `element_format_properties` | 235 | 8.3s |  |
| 404 | `empty_bounds` | 1 | 7.5s |  |
| 405 | `encode_uri_surrogate_pair_invalid` | 8 | 7.3s |  |
| 406 | `encode_uri_surrogate_pair_swf11` | 15 | 7.7s |  |
| 407 | `equals` | 512 | 24.3s |  |
| 408 | `error_geterrormessage` | 779 | 6.5s |  |
| 409 | `error_prototype` | 15 | 6.3s |  |
| 410 | `error_stack_trace` | 45 | 6.3s |  |
| 411 | `error_stack_trace_debug_swf17` | 0 | 21.6s |  |
| 412 | `error_stack_trace_debug_swf18` | 0 | 6.5s |  |
| 413 | `error_stack_trace_edge_cases` | 6 | 6.7s |  |
| 414 | `error_stack_trace_release_swf17` | 0 | 2.6s |  |
| 415 | `error_stack_trace_release_swf18` | 0 | 6.1s |  |
| 416 | `error_throwerror` | 103 | 6.3s |  |
| 417 | `error_tostring` | 29 | 6.1s |  |
| 418 | `error_tostring_more` | 86 | 20.8s |  |
| 419 | `es3_inheritance` | 31 | 6.1s |  |
| 420 | `es4_inheritance` | 30 | 6.2s |  |
| 421 | `es4_interfaces` | 30 | 6.4s |  |
| 422 | `es4_method_binding` | 8 | 2.3s |  |
| 423 | `es4_oop_prototypes` | 14 | 6.3s |  |
| 424 | `es4_protected_inheritance` | 6 | 6.1s |  |
| 425 | `escape` | 71 | 6.4s |  |
| 426 | `escape_multi_byte` | 45 | 6.2s |  |
| 427 | `event_bubbles` | 2 | 6.7s |  |
| 428 | `event_cancelable` | 2 | 6.5s |  |
| 429 | `event_clone` | 20 | 6.2s |  |
| 430 | `event_clone_error_redispatch` | 3 | 6.1s |  |
| 431 | `event_clone_on_redispatch` | 10 | 6.7s |  |
| 432 | `event_formattostring` | 31 | 6.3s |  |
| 433 | `event_isdefaultprevented` | 12 | 6.1s |  |
| 434 | `event_target_getter` | 5 | 2.2s |  |
| 435 | `event_target_set` | 9 | 6.1s |  |
| 436 | `event_type` | 1 | 6.2s |  |
| 437 | `event_valueof_tostring` | 18 | 6.5s |  |
| 438 | `eventdispatcher_dispatchevent` | 12 | 6.2s |  |
| 439 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.4s |  |
| 440 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.2s |  |
| 441 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.8s |  |
| 442 | `eventdispatcher_dispatchevent_this` | 5 | 6.6s |  |
| 443 | `eventdispatcher_haseventlistener` | 25 | 6.5s |  |
| 444 | `eventdispatcher_interface_invoke` | 1 | 6.1s |  |
| 445 | `eventdispatcher_tostring` | 10 | 6.4s |  |
| 446 | `eventdispatcher_willtrigger` | 25 | 6.0s |  |
| 447 | `falsiness` | 30 | 8.9s |  |
| 448 | `fast_index_access` | 12 | 8.9s |  |
| 449 | `filefilter_properties` | 4 | 8.8s |  |
| 450 | `filereference_browse_cancel` | 3 | 8.9s |  |
| 451 | `filereference_browse_select` | 9 | 9.0s |  |
| 452 | `filereference_load` | 31 | 3.5s |  |
| 453 | `filereference_save` | 16 | 8.9s |  |
| 454 | `filereference_save_and_browse` | 42 | 9.0s |  |
| 455 | `filereference_save_and_load` | 22 | 9.0s |  |
| 456 | `filereference_uninitialized` | 8 | 8.7s |  |
| 457 | `filereferencelist_browse_cancel` | 6 | 3.4s |  |
| 458 | `filereferencelist_browse_select` | 7 | 8.8s |  |
| 459 | `filter_rewind` | 8 | 28.9s |  |
| 460 | `filters_array_holes` | 25 | 10.1s |  |
| 461 | `finddef` | 3 | 8.8s |  |
| 462 | `findprop_global_prototype` | 6 | 8.8s |  |
| 463 | `flash_media_video_constructor` | 156 | 9.6s |  |
| 464 | `flash_media_video_rotation_probe` | 27 | 8.9s |  |
| 465 | `flash_media_video_setter` | 40 | 9.2s |  |
| 466 | `flash_trace` | 17 | 8.8s |  |
| 467 | `flash_ui_mouse_cursor` | 35 | 9.2s |  |
| 468 | `flash_xml` | 29 | 8.8s |  |
| 469 | `flash_xml_cloneNode` | 22 | 8.8s |  |
| 470 | `flash_xml_namespace` | 109 | 8.7s |  |
| 471 | `flash_xml_removeNode` | 60 | 8.7s |  |
| 472 | `focus_events_code` | 161 | 28.7s |  |
| 473 | `focus_events_key_basic` | 132 | 29.1s |  |
| 474 | `focus_events_key_navigation` | 53 | 29.9s |  |
| 475 | `focus_events_key_same_object` | 26 | 9.1s |  |
| 476 | `focus_events_mixed_key_mouse` | 100 | 28.9s |  |
| 477 | `focus_events_mouse_basic` | 260 | 28.7s |  |
| 478 | `focus_events_mouse_focusable` | 112 | 28.9s |  |
| 479 | `focus_events_mouse_same_object` | 40 | 8.9s |  |
| 480 | `focus_remove` | 20 | 29.1s |  |
| 481 | `focus_root_movie` | 4 | 29.2s |  |
| 482 | `focus_stage` | 1 | 8.9s |  |
| 483 | `focusrect` | 18 | 9.8s |  |
| 484 | `focusrect_focuslost` | 9 | 9.0s |  |
| 485 | `focusrect_property` | 110 | 3.4s |  |
| 486 | `font_description_clone` | 14 | 8.8s |  |
| 487 | `font_embedded` | 24 | 6.7s |  |
| 488 | `font_enumeratefonts` | 41 | 6.8s |  |
| 489 | `font_enumeratefonts_filter` | 4 | 21.0s |  |
| 490 | `font_enumeratefonts_order` | 9 | 7.2s |  |
| 491 | `font_hasglyphs` | 40 | 6.2s |  |
| 492 | `font_registerfont` | 129 | 6.7s |  |
| 493 | `framelabel_constr` | 5 | 5.9s |  |
| 494 | `function_call` | 12 | 2.2s |  |
| 495 | `function_call_arguments` | 46 | 6.0s |  |
| 496 | `function_call_arguments_enumerate` | 5 | 6.7s |  |
| 497 | `function_call_coercion` | 108 | 6.6s |  |
| 498 | `function_call_default` | 6 | 6.1s |  |
| 499 | `function_call_rest` | 22 | 6.5s |  |
| 500 | `function_call_types` | 3 | 5.9s |  |
| 501 | `function_call_via_apply` | 11 | 6.2s |  |
| 502 | `function_call_via_call` | 3 | 6.0s |  |
| 503 | `function_display_anonymous` | 7 | 2.2s |  |
| 504 | `function_length` | 6 | 6.1s |  |
| 505 | `function_object` | 2 | 6.0s |  |
| 506 | `function_proto` | 5 | 6.0s |  |
| 507 | `function_proto_created` | 61 | 6.1s |  |
| 508 | `function_to_locale_string` | 4 | 6.0s |  |
| 509 | `function_to_string` | 4 | 5.9s |  |
| 510 | `function_type` | 6 | 5.8s |  |
| 511 | `function_unbound_this` | 51 | 6.0s |  |
| 512 | `function_value_of` | 4 | 2.1s |  |
| 513 | `game_input` | 4 | 6.0s |  |
| 514 | `generate_random_bytes` | 3 | 6.4s |  |
| 515 | `get_definition_by_name` | 11 | 6.1s |  |
| 516 | `get_qualified_class_name` | 20 | 6.0s |  |
| 517 | `get_qualified_super_class_name` | 18 | 6.1s |  |
| 518 | `get_slot_edge_cases` | 1 | 5.9s |  |
| 519 | `get_timer` | 2 | 2.2s |  |
| 520 | `getglobalslot` | 1 | 6.2s |  |
| 521 | `getouterscope` | 8 | 6.1s |  |
| 522 | `getouterscope_two_classobjects` | 13 | 6.0s |  |
| 523 | `getter_different_namespace_setter` | 2 | 5.9s |  |
| 524 | `glow_filter` | 127 | 6.3s |  |
| 525 | `goto_button_nested_framescript` | 28 | 20.9s |  |
| 526 | `goto_in_constructframe` | 12 | 28.6s |  |
| 527 | `goto_in_scene_last_frame` | 2 | 27.6s |  |
| 528 | `goto_methods` | 56 | 27.6s |  |
| 529 | `goto_methods_swfver10` | 8 | 8.3s |  |
| 530 | `goto_nested_construct_sibling` | 18 | 8.7s |  |
| 531 | `goto_nested_framescript` | 9 | 8.5s |  |
| 532 | `goto_on_orphan` | 15 | 27.8s |  |
| 533 | `gradient_bevel_filter` | 206 | 8.7s |  |
| 534 | `gradient_glow_filter` | 206 | 8.4s |  |
| 535 | `graphic_linkage` | 9 | 8.7s |  |
| 536 | `graphics_bad_direct_commands` | 5 | 10.5s |  |
| 537 | `graphics_bitmap_fill` | 0 | 29.7s |  |
| 538 | `graphics_bitmaps` | 0 | 8.9s |  |
| 539 | `graphics_direct_commands` | 0 | 9.2s |  |
| 540 | `graphics_draw_triangles` | 98 | 28.1s |  |
| 541 | `graphics_gradients` | 0 | 8.6s |  |
| 542 | `graphics_gradients_nulls` | 0 | 8.6s |  |
| 543 | `graphics_path` | 56 | 8.4s |  |
| 544 | `graphics_round_rects` | 0 | 8.3s |  |
| 545 | `graphics_simple_shapes` | 0 | 8.6s |  |
| 546 | `greaterequals` | 512 | 12.2s |  |
| 547 | `greaterthan` | 512 | 12.4s |  |
| 548 | `has_own_property` | 102 | 8.8s |  |
| 549 | `hasownproperty_namespaces` | 2 | 8.3s |  |
| 550 | `hello_world` | 1 | 8.3s |  |
| 551 | `hittest_morph` | 30 | 8.4s |  |
| 552 | `if_eq` | 10 | 8.3s |  |
| 553 | `if_gt` | 1 | 8.3s |  |
| 554 | `if_gte` | 10 | 3.2s |  |
| 555 | `if_lt` | 1 | 1.2s |  |
| 556 | `if_lte` | 10 | 8.2s |  |
| 557 | `if_ne` | 7 | 3.2s |  |
| 558 | `if_stricteq` | 6 | 8.3s |  |
| 559 | `if_strictne` | 11 | 8.4s |  |
| 560 | `ime_linux_dead_keys` | 10 | 8.4s |  |
| 561 | `in` | 102 | 8.8s |  |
| 562 | `inclocal` | 46 | 3.2s |  |
| 563 | `inclocal_i` | 46 | 8.4s |  |
| 564 | `increment` | 46 | 8.4s |  |
| 565 | `increment_i` | 46 | 8.8s |  |
| 566 | `indexing_delete` | 75 | 8.7s |  |
| 567 | `indexof_xml` | 10 | 9.0s |  |
| 568 | `init_callee_cached` | 24 | 8.7s |  |
| 569 | `instanceof` | 58 | 8.9s |  |
| 570 | `instantiate_root_character` | 4 | 9.3s |  |
| 571 | `instantiation_on_enter_frame` | 7 | 29.7s |  |
| 572 | `instantiation_on_enterframe_gotoandstop` | 8 | 8.8s |  |
| 573 | `int_constr` | 92 | 8.7s |  |
| 574 | `int_edge_cases` | 19 | 29.6s |  |
| 575 | `int_instanceof` | 3 | 8.8s |  |
| 576 | `int_tofixed` | 1215 | 8.9s |  |
| 577 | `int_toprecision` | 1125 | 8.8s |  |
| 578 | `int_tostring` | 3375 | 8.8s |  |
| 579 | `interactiveobject_enabled` | 25 | 8.8s |  |
| 580 | `interface_namespaces` | 78 | 9.1s |  |
| 581 | `invalid_utf8` | 12 | 8.9s |  |
| 582 | `is_finite` | 46 | 8.9s |  |
| 583 | `is_nan` | 46 | 8.7s |  |
| 584 | `is_prototype_of` | 12 | 8.8s |  |
| 585 | `issue_10221` | 2 | 8.8s |  |
| 586 | `issue_13780` | 12 | 8.9s |  |
| 587 | `issue_14901` | 1 | 8.9s |  |
| 588 | `issue_17675_edittext_paste_maxchars` | 1 | 8.7s |  |
| 589 | `issue_5292` | 5 | 8.7s |  |
| 590 | `issue_8630` | 2 | 8.7s |  |
| 591 | `issue_8630_placeremoveplace` | 15 | 8.8s |  |
| 592 | `issue_8630_placeremoveplace_scriptremove` | 16 | 8.5s |  |
| 593 | `issue_8630_scriptremove` | 11 | 8.5s |  |
| 594 | `istype` | 24 | 3.3s |  |
| 595 | `istypelate` | 58 | 8.9s |  |
| 596 | `istypelate_coerce` | 198 | 9.6s |  |
| 597 | `jpeg_loader_context` | 6 | 8.5s |  |
| 598 | `json_errors` | 9 | 28.7s |  |
| 599 | `json_parse` | 21 | 8.6s |  |
| 600 | `json_stringify` | 12 | 8.8s |  |
| 601 | `json_stringify_function` | 12 | 8.6s |  |
| 602 | `json_stringify_order` | 1 | 8.6s |  |
| 603 | `json_version_gated` | 1 | 8.6s |  |
| 604 | `key_input_80percent` | 1812 | 32.1s |  |
| 605 | `key_input_location` | 126 | 9.4s |  |
| 606 | `key_input_numpad` | 384 | 9.1s |  |
| 607 | `large_preload_from_bytes` | 51 | 35.4s |  |
| 608 | `large_preload_from_url` | 27 | 11.8s |  |
| 609 | `large_preload_image_from_bytes` | 25 | 9.7s |  |
| 610 | `lazyinit` | 17 | 9.0s |  |
| 611 | `lessequals` | 512 | 12.9s |  |
| 612 | `lessthan` | 512 | 12.8s |  |
| 613 | `loader_bitmap_transparency` | 14 | 9.2s |  |
| 614 | `loader_bytes_unknown_content` | 14 | 9.2s |  |
| 615 | `loader_child_getdefinition` | 5 | 9.5s |  |
| 616 | `loader_duplicate_class` | 48 | 11.4s |  |
| 617 | `loader_duplicate_coerce` | 3 | 9.5s |  |
| 618 | `loader_duplicate_coerce_new_domain` | 4 | 9.4s |  |
| 619 | `loader_error_in_root_ctor` | 4 | 9.6s |  |
| 620 | `loader_events` | 92 | 11.4s |  |
| 621 | `loader_image` | 8 | 9.9s |  |
| 622 | `loader_jpegxr` | 2 | 30.5s |  |
| 623 | `loader_jpegxr_alpha` | 1 | 30.4s |  |
| 624 | `loader_loadbytes_events` | 30 | 9.8s |  |
| 625 | `loader_loadbytes_invalid_png` | 4 | 9.1s |  |
| 626 | `loader_loadbytes_url` | 12 | 9.5s |  |
| 627 | `loader_loaderurl` | 6 | 9.8s |  |
| 628 | `loader_method` | 85 | 9.3s |  |
| 629 | `loader_noninteractive_try_click_root` | 5 | 30.8s |  |
| 630 | `loader_reuse` | 38 | 9.4s |  |
| 631 | `loader_try_click_root` | 16 | 9.5s |  |
| 632 | `loader_unknown_content` | 24 | 9.4s |  |
| 633 | `loader_visibility_interactive` | 1 | 9.4s |  |
| 634 | `loaderinfo_events` | 7 | 9.2s |  |
| 635 | `loaderinfo_loadurl` | 12 | 9.1s |  |
| 636 | `loaderinfo_more` | 6 | 9.5s |  |
| 637 | `loaderinfo_properties` | 18 | 29.9s |  |
| 638 | `loaderinfo_properties_not_loaded` | 23 | 9.2s |  |
| 639 | `loaderinfo_quine` | 1005 | 9.0s |  |
| 640 | `loaderinfo_root` | 10 | 9.0s |  |
| 641 | `loaderinfo_root_allows` | 2 | 9.1s |  |
| 642 | `localconnection` | 890 | 11.5s |  |
| 643 | `localconnection_send` | 4 | 27.8s |  |
| 644 | `lshift` | 1058 | 20.8s |  |
| 645 | `mask_reapply` | 1 | 28.5s |  |
| 646 | `math` | 497 | 8.7s |  |
| 647 | `matrix` | 338 | 19.6s |  |
| 648 | `matrix3d` | 57 | 28.4s |  |
| 649 | `matrix3d_append` | 16 | 8.6s |  |
| 650 | `matrix3d_append_prepend_scale` | 86 | 8.5s |  |
| 651 | `matrix3d_append_prepend_translation` | 42 | 8.5s |  |
| 652 | `matrix3d_compose` | 34 | 8.8s |  |
| 653 | `matrix3d_constructor_clone` | 15 | 8.6s |  |
| 654 | `matrix3d_copy_column` | 83 | 8.9s |  |
| 655 | `matrix3d_copy_from` | 19 | 8.6s |  |
| 656 | `matrix3d_copy_raw_data_from` | 55 | 3.5s |  |
| 657 | `matrix3d_copy_raw_data_to` | 38 | 8.8s |  |
| 658 | `matrix3d_copy_row` | 83 | 8.5s |  |
| 659 | `matrix3d_copy_to_matrix3d` | 19 | 8.6s |  |
| 660 | `matrix3d_determinant` | 182 | 8.7s |  |
| 661 | `matrix3d_interpolate` | 21 | 8.8s |  |
| 662 | `matrix3d_invert` | 18 | 3.3s |  |
| 663 | `matrix3d_position` | 19 | 8.6s |  |
| 664 | `matrix3d_precision` | 28 | 8.8s |  |
| 665 | `matrix3d_prepend` | 16 | 8.4s |  |
| 666 | `matrix3d_raw_data` | 33 | 8.6s |  |
| 667 | `matrix3d_transform_vector` | 52 | 8.9s |  |
| 668 | `matrix3d_transpose` | 5 | 8.6s |  |
| 669 | `method_association` | 5 | 8.5s |  |
| 670 | `method_without_body` | 3 | 28.2s |  |
| 671 | `missing_external_interface` | 10 | 8.6s |  |
| 672 | `modulo` | 1058 | 20.9s |  |
| 673 | `morph_shape` | 2 | 27.9s |  |
| 674 | `mouse_children` | 192 | 28.6s |  |
| 675 | `mouse_click_events` | 90 | 27.8s |  |
| 676 | `mouse_double_click_events` | 188 | 8.6s |  |
| 677 | `mouse_empty_parent` | 4 | 8.4s |  |
| 678 | `mouse_over_while_dragging` | 3 | 8.4s |  |
| 679 | `mouse_pick_avm1_root` | 2 | 28.1s |  |
| 680 | `mouse_pick_button_mode` | 2 | 8.5s |  |
| 681 | `mouse_pick_dobj_mask` | 4 | 9.1s |  |
| 682 | `mouse_pick_masking` | 7 | 27.9s |  |
| 683 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 28.2s |  |
| 684 | `mouse_pick_non_interactive_dobj_mask` | 3 | 28.2s |  |
| 685 | `mouse_pick_text` | 8 | 8.6s |  |
| 686 | `mouse_sibling` | 8 | 8.4s |  |
| 687 | `mouse_wheel_events` | 36 | 28.9s |  |
| 688 | `mouseevent_constr` | 66 | 8.4s |  |
| 689 | `mouseevent_stagexy` | 35 | 8.4s |  |
| 690 | `mouseevent_valueof_tostring` | 28 | 8.4s |  |
| 691 | `movieclip_addframescript` | 3 | 27.6s |  |
| 692 | `movieclip_addframescript_error` | 9 | 8.4s |  |
| 693 | `movieclip_child_property` | 16 | 8.5s |  |
| 694 | `movieclip_constr` | 21 | 8.4s |  |
| 695 | `movieclip_currentlabels` | 17 | 27.8s |  |
| 696 | `movieclip_currentlabels_dupes1` | 46 | 27.8s |  |
| 697 | `movieclip_currentlabels_dupes2` | 30 | 8.5s |  |
| 698 | `movieclip_currentlabels_dupes3` | 67 | 8.4s |  |
| 699 | `movieclip_currentscene` | 12 | 27.5s |  |
| 700 | `movieclip_dispatchevent` | 430 | 8.5s |  |
| 701 | `movieclip_dispatchevent_cancel` | 102 | 8.5s |  |
| 702 | `movieclip_dispatchevent_handlerorder` | 251 | 8.5s |  |
| 703 | `movieclip_dispatchevent_selfadd` | 80 | 8.4s |  |
| 704 | `movieclip_dispatchevent_target` | 899 | 8.5s |  |
| 705 | `movieclip_displayevents` | 96 | 27.7s |  |
| 706 | `movieclip_displayevents_clickgoto` | 676 | 28.1s |  |
| 707 | `movieclip_displayevents_clickgoto2` | 2001 | 9.1s |  |
| 708 | `movieclip_displayevents_clickplay` | 575 | 8.6s |  |
| 709 | `movieclip_displayevents_clicksymbol` | 562 | 8.6s |  |
| 710 | `movieclip_displayevents_constructframegoto` | 140 | 8.8s |  |
| 711 | `movieclip_displayevents_constructframeplay` | 50 | 8.7s |  |
| 712 | `movieclip_displayevents_constructframesymbol` | 144 | 8.6s |  |
| 713 | `movieclip_displayevents_dblhandler` | 21 | 8.7s |  |
| 714 | `movieclip_displayevents_enterframegoto` | 149 | 8.7s |  |
| 715 | `movieclip_displayevents_enterframeplay` | 48 | 8.5s |  |
| 716 | `movieclip_displayevents_enterframesymbol` | 149 | 27.9s |  |
| 717 | `movieclip_displayevents_exitframegoto` | 106 | 8.5s |  |
| 718 | `movieclip_displayevents_exitframeplay` | 44 | 8.5s |  |
| 719 | `movieclip_displayevents_exitframesymbol` | 135 | 8.5s |  |
| 720 | `movieclip_displayevents_looping` | 63 | 27.8s |  |
| 721 | `movieclip_displayevents_stopped` | 113 | 8.8s |  |
| 722 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 723 | `movieclip_displayevents_timeline` | 128 | 8.7s |  |
| 724 | `movieclip_drawrect` | 54 | 27.9s |  |
| 725 | `movieclip_frameconstruct_skipped` | 9 | 8.4s |  |
| 726 | `movieclip_goto_during_frame_script` | 15 | 28.0s |  |
| 727 | `movieclip_goto_overwrite` | 14 | 28.7s |  |
| 728 | `movieclip_goto_scene_last_frame_int` | 1 | 28.5s |  |
| 729 | `movieclip_goto_scene_last_frame_label` | 1 | 3.2s |  |
| 730 | `movieclip_gotoandplay` | 15 | 28.3s |  |
| 731 | `movieclip_gotoandstop` | 13 | 8.5s |  |
| 732 | `movieclip_gotoandstop_children` | 4 | 8.6s |  |
| 733 | `movieclip_gotoandstop_framescripts1` | 4 | 8.6s |  |
| 734 | `movieclip_gotoandstop_framescripts2` | 4 | 3.2s |  |
| 735 | `movieclip_gotoandstop_framescripts_self` | 7 | 28.1s |  |
| 736 | `movieclip_gotoandstop_queueing` | 12 | 28.0s |  |
| 737 | `movieclip_hittest` | 67 | 8.7s |  |
| 738 | `movieclip_next_frame` | 2 | 8.6s |  |
| 739 | `movieclip_next_scene` | 6 | 27.9s |  |
| 740 | `movieclip_play` | 3 | 3.2s |  |
| 741 | `movieclip_prev_frame` | 3 | 8.3s |  |
| 742 | `movieclip_prev_scene` | 7 | 8.5s |  |
| 743 | `movieclip_properties` | 79 | 28.4s |  |
| 744 | `movieclip_queued_noop_goto_swf10` | 9 | 8.5s |  |
| 745 | `movieclip_queued_noop_goto_swf9` | 7 | 1.4s |  |
| 746 | `movieclip_scenes` | 11 | 8.4s |  |
| 747 | `movieclip_soundtransform` | 831 | 29.9s |  |
| 748 | `movieclip_stop` | 1 | 8.4s |  |
| 749 | `movieclip_super_is_symbol` | 20 | 8.8s |  |
| 750 | `movieclip_symbol_constr` | 8 | 8.5s |  |
| 751 | `movieclip_text_mousedown` | 1 | 8.5s |  |
| 752 | `movieclip_willtrigger` | 5 | 8.6s |  |
| 753 | `multiply` | 1058 | 20.6s |  |
| 754 | `namespace_constr` | 253 | 8.8s |  |
| 755 | `namespace_constr_args` | 1 | 8.5s |  |
| 756 | `namespace_enumeration_order` | 7 | 28.2s |  |
| 757 | `nan_scale` | 9 | 8.6s |  |
| 758 | `native_menu_basic` | 19 | 11.0s |  |
| 759 | `navigateToURL_target_normalize` | 107 | 30.9s |  |
| 760 | `negate` | 30 | 8.7s |  |
| 761 | `negative_volume_panned` | 0 | 8.9s |  |
| 762 | `nested_iteration` | 11 | 8.7s |  |
| 763 | `net_getClassByAlias` | 3 | 8.7s |  |
| 764 | `net_navigateToURL` | 57 | 8.6s |  |
| 765 | `net_stream_play_options` | 6 | 8.6s |  |
| 766 | `netconnection_close` | 55 | 27.5s |  |
| 767 | `netconnection_properties` | 78 | 8.1s |  |
| 768 | `netconnection_send_remote` | 50 | 30.6s |  |
| 769 | `netconnection_serialize_arrays` | 6 | 8.1s |  |
| 770 | `netfilterevent` | 10 | 27.3s |  |
| 771 | `netstream_client` | 10 | 8.2s |  |
| 772 | `netstream_connect` | 7 | 8.0s |  |
| 773 | `netstream_flv_date` | 4 | 8.0s |  |
| 774 | `newactivation_in_script_init` | 3 | 8.0s |  |
| 775 | `newclass_mismatched` | 4 | 8.0s |  |
| 776 | `newclass_twice` | 3 | 7.9s |  |
| 777 | `nonconflicting_declarations` | 0 | 8.2s |  |
| 778 | `null_void_types` | 8 | 8.2s |  |
| 779 | `number_autoconv` | 21 | 3.0s |  |
| 780 | `number_autoconv_amf` | 132 | 8.1s |  |
| 781 | `number_autoconv_array_sort_32bit` | 1 | 8.0s |  |
| 782 | `number_constr` | 58 | 8.1s |  |
| 783 | `number_convert_edge_cases` | 180 | 27.1s |  |
| 784 | `number_toexponential` | 378 | 8.1s |  |
| 785 | `number_toexponential2` | 35 | 8.0s |  |
| 786 | `number_tofixed` | 378 | 7.9s |  |
| 787 | `number_toprecision` | 350 | 8.0s |  |
| 788 | `obfuscated_class_names` | 3 | 8.0s |  |
| 789 | `object_enumeration` | 10 | 8.0s |  |
| 790 | `object_prototype` | 4 | 8.0s |  |
| 791 | `object_to_locale_string` | 2 | 8.0s |  |
| 792 | `object_to_string` | 2 | 7.9s |  |
| 793 | `object_value_of` | 2 | 2.7s |  |
| 794 | `op_coerce` | 54 | 2.9s |  |
| 795 | `op_coerce_x` | 54 | 8.1s |  |
| 796 | `op_escxattr` | 2 | 8.0s |  |
| 797 | `op_escxelem` | 2 | 7.9s |  |
| 798 | `op_lookupswitch` | 4 | 7.9s |  |
| 799 | `optimize_coerce` | 1 | 7.8s |  |
| 800 | `orphan_movie_complex` | 80 | 8.3s |  |
| 801 | `orphan_movie_reorder` | 111 | 27.6s |  |
| 802 | `orphan_removeobject` | 636 | 29.9s |  |
| 803 | `package_namespace` | 7 | 29.0s |  |
| 804 | `param_default_value_has_zero_cpool_index` | 1 | 29.7s |  |
| 805 | `parent_early_access_child` | 16 | 29.3s |  |
| 806 | `parse_float` | 81 | 9.1s |  |
| 807 | `parse_float_swf10` | 81 | 8.7s |  |
| 808 | `parse_int` | 135 | 9.4s |  |
| 809 | `perspective_projection` | 1443 | 29.7s |  |
| 810 | `perspective_projection_basic` | 40 | 8.8s |  |
| 811 | `pixelbender_ceil` | 77 | 9.0s |  |
| 812 | `pixelbender_conditional` | 138 | 9.3s |  |
| 813 | `pixelbender_conversions` | 270 | 9.2s |  |
| 814 | `pixelbender_dithering` | 8 | 37.1s |  |
| 815 | `pixelbender_div` | 36 | 9.1s |  |
| 816 | `pixelbender_effect_BlurredFocus` | 0 | 37.8s |  |
| 817 | `pixelbender_effect_glassDisplace` | 0 | 15.4s |  |
| 818 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 33.5s |  |
| 819 | `pixelbender_effect_smudge` | 0 | 12.2s |  |
| 820 | `pixelbender_effect_tintype` | 0 | 11.5s |  |
| 821 | `pixelbender_effect_twirl` | 0 | 13.0s |  |
| 822 | `pixelbender_eof` | 7 | 8.6s |  |
| 823 | `pixelbender_images` | 0 | 10.9s |  |
| 824 | `pixelbender_input` | 103 | 29.0s |  |
| 825 | `pixelbender_logicalnot` | 20 | 8.5s |  |
| 826 | `pixelbender_malformed_data` | 190 | 29.6s |  |
| 827 | `pixelbender_multiple_out_params` | 1 | 3.2s |  |
| 828 | `pixelbender_no_out_param` | 6 | 8.6s |  |
| 829 | `pixelbender_outputs` | 13 | 8.8s |  |
| 830 | `pixelbender_padding_bytes` | 22 | 8.7s |  |
| 831 | `pixelbender_param_qualifier` | 512 | 8.7s |  |
| 832 | `pixelbender_parameters` | 1563 | 9.0s |  |
| 833 | `pixelbender_parameters_bool` | 240 | 8.9s |  |
| 834 | `pixelbender_parameters_int_vs_bool` | 54 | 8.8s |  |
| 835 | `pixelbender_parse_errors` | 6 | 8.8s |  |
| 836 | `pixelbender_rsqrt` | 24 | 8.9s |  |
| 837 | `pixelbender_select_kinds` | 8 | 9.0s |  |
| 838 | `pixelbender_shaderdata` | 49 | 8.6s |  |
| 839 | `pixelbender_shaderdata_setter` | 99 | 9.0s |  |
| 840 | `pixelbender_sign` | 60 | 8.9s |  |
| 841 | `pixelbender_vector_output` | 11 | 8.8s |  |
| 842 | `place_and_lookup/swf10` | 33 | 8.8s |  |
| 843 | `place_and_lookup/swf9` | 33 | 1.4s |  |
| 844 | `place_multiple` | 17 | 20.8s |  |
| 845 | `place_object_replace` | 9 | 20.6s |  |
| 846 | `place_object_replace_2` | 24 | 20.6s |  |
| 847 | `place_object_same_depth_frame` | 1 | 20.3s |  |
| 848 | `point` | 132 | 6.6s |  |
| 849 | `primitive_edge_cases` | 1 | 6.4s |  |
| 850 | `primitive_keys` | 54 | 6.1s |  |
| 851 | `primitive_toString` | 277 | 6.0s |  |
| 852 | `primitive_valueOf` | 285 | 5.8s |  |
| 853 | `print_job_options` | 3 | 6.2s |  |
| 854 | `property_is_enumerable` | 114 | 6.6s |  |
| 855 | `property_is_enumerable_reset` | 23 | 5.9s |  |
| 856 | `property_priority` | 22 | 6.0s |  |
| 857 | `property_priority_chained` | 4 | 5.7s |  |
| 858 | `property_priority_definition_names_order` | 2 | 6.2s |  |
| 859 | `property_priority_three_level` | 6 | 6.1s |  |
| 860 | `propertyisenumerable_namespaces` | 6 | 5.9s |  |
| 861 | `prototype_set_null` | 7 | 5.9s |  |
| 862 | `proxy_callproperty` | 24 | 6.0s |  |
| 863 | `proxy_deleteproperty` | 64 | 6.1s |  |
| 864 | `proxy_enumeration` | 34 | 5.9s |  |
| 865 | `proxy_getproperty` | 77 | 6.5s |  |
| 866 | `proxy_hasownproperty` | 8 | 5.9s |  |
| 867 | `proxy_hasproperty` | 32 | 6.0s |  |
| 868 | `proxy_not_overridden` | 54 | 6.0s |  |
| 869 | `proxy_serialize` | 9 | 6.5s |  |
| 870 | `proxy_setproperty` | 42 | 6.0s |  |
| 871 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.0s |  |
| 872 | `qname_constr` | 32 | 6.2s |  |
| 873 | `qname_constr_namespace` | 24 | 6.2s |  |
| 874 | `qname_enumeration` | 9 | 6.0s |  |
| 875 | `qname_indexing` | 23 | 6.1s |  |
| 876 | `qname_tostring` | 25 | 6.0s |  |
| 877 | `qname_valueof` | 29 | 5.9s |  |
| 878 | `rectangle` | 1094 | 6.4s |  |
| 879 | `regexp_constr` | 148 | 6.7s |  |
| 880 | `regexp_exec` | 19 | 6.2s |  |
| 881 | `regexp_extended` | 47 | 6.1s |  |
| 882 | `regexp_multiargs` | 1 | 6.0s |  |
| 883 | `regexp_test` | 27 | 2.1s |  |
| 884 | `regexp_toString` | 10 | 6.3s |  |
| 885 | `register_script_refresh` | 35 | 20.5s |  |
| 886 | `remove_child_clear_field` | 88 | 28.7s |  |
| 887 | `remove_dobj` | 3 | 28.0s |  |
| 888 | `resolve_order` | 4 | 8.5s |  |
| 889 | `responder_null_callbacks` | 1 | 28.2s |  |
| 890 | `rng` | 1 | 9.8s |  |
| 891 | `rootless` | 42 | 8.7s |  |
| 892 | `rshift` | 1058 | 20.9s |  |
| 893 | `rtqname_not_namespace` | 12 | 8.5s |  |
| 894 | `sandbox_type_inherited` | 2 | 9.0s |  |
| 895 | `sandbox_type_local_file` | 1 | 8.5s |  |
| 896 | `sandbox_type_local_network` | 1 | 8.3s |  |
| 897 | `scene_constr` | 8 | 8.5s |  |
| 898 | `scope_optimizations` | 4 | 8.5s |  |
| 899 | `scopes_dont_cache/order-1` | 1 | 27.9s |  |
| 900 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 901 | `security_domain_current` | 2 | 3.2s |  |
| 902 | `selection` | 239 | 9.3s |  |
| 903 | `set_local_0` | 31 | 8.6s |  |
| 904 | `set_property_is_enumerable` | 85 | 9.0s |  |
| 905 | `shaderparameter_value` | 4 | 8.5s |  |
| 906 | `shape_drawrect` | 54 | 8.6s |  |
| 907 | `shared_object_no_root` | 3 | 8.5s |  |
| 908 | `simplebutton_added_to_stage` | 45 | 28.3s |  |
| 909 | `simplebutton_childevents` | 86 | 28.5s |  |
| 910 | `simplebutton_childevents_nested` | 54 | 8.9s |  |
| 911 | `simplebutton_childevents_sprite` | 13 | 8.6s |  |
| 912 | `simplebutton_childprops` | 144 | 8.8s |  |
| 913 | `simplebutton_childshuffle` | 23 | 8.5s |  |
| 914 | `simplebutton_constr` | 36 | 8.8s |  |
| 915 | `simplebutton_constr_childevents` | 48 | 8.8s |  |
| 916 | `simplebutton_constr_params` | 42 | 8.7s |  |
| 917 | `simplebutton_mouseenabled` | 26 | 8.5s |  |
| 918 | `simplebutton_multi_children` | 19 | 8.8s |  |
| 919 | `simplebutton_soundtransform` | 887 | 30.4s |  |
| 920 | `simplebutton_structure` | 27 | 8.8s |  |
| 921 | `simplebutton_symbolclass` | 68 | 8.8s |  |
| 922 | `slot_disp_id_shared_numbering` | 1 | 28.0s |  |
| 923 | `slots_force_autoassigned` | 1 | 29.4s |  |
| 924 | `socket_after_disconnect` | 1 | 8.9s |  |
| 925 | `socket_close` | 2 | 8.8s |  |
| 926 | `socket_connect` | 4 | 8.9s |  |
| 927 | `socket_errors` | 56 | 9.4s |  |
| 928 | `socket_read_big` | 48 | 9.1s |  |
| 929 | `socket_read_little` | 48 | 3.4s |  |
| 930 | `socket_read_write_object` | 8 | 8.9s |  |
| 931 | `socket_write_big` | 15 | 9.2s |  |
| 932 | `socket_write_little` | 14 | 8.9s |  |
| 933 | `sound_constructor_with_args` | 6 | 9.3s |  |
| 934 | `sound_embeddedprops` | 26 | 9.2s |  |
| 935 | `sound_play` | 19 | 9.3s |  |
| 936 | `sound_rootless` | 7 | 9.1s |  |
| 937 | `sound_valueof` | 33 | 9.0s |  |
| 938 | `soundchannel_soundtransform` | 835 | 31.2s |  |
| 939 | `soundchannel_soundtransform_exists` | 5 | 29.1s |  |
| 940 | `soundchannel_stop` | 8 | 29.3s |  |
| 941 | `soundmixer_buffertime` | 5 | 8.8s |  |
| 942 | `soundmixer_soundtransform` | 900 | 10.9s |  |
| 943 | `soundmixer_stopall` | 6 | 29.9s |  |
| 944 | `soundtransform` | 442 | 9.5s |  |
| 945 | `space_justifier_clone` | 12 | 3.4s |  |
| 946 | `sprite_with_frames` | 0 | 32.9s |  |
| 947 | `stage3d_agal_cross_product` | 0 | 11.7s |  |
| 948 | `stage3d_agal_upload_errors` | 66 | 11.7s |  |
| 949 | `stage3d_bitmap` | 0 | 34.0s |  |
| 950 | `stage3d_blend` | 81 | 32.8s |  |
| 951 | `stage3d_context3d_string_args` | 158 | 9.6s |  |
| 952 | `stage3d_errors` | 7 | 8.7s |  |
| 953 | `stage3d_errors_atf` | 3 | 9.9s |  |
| 954 | `stage3d_errors_swf_29` | 6 | 8.7s |  |
| 955 | `stage3d_float1_index` | 0 | 31.5s |  |
| 956 | `stage3d_fractal` | 0 | 31.8s |  |
| 957 | `stage3d_ignore_sampler_override` | 0 | 31.4s |  |
| 958 | `stage3d_multistage_triangle` | 3 | 11.5s |  |
| 959 | `stage3d_program_constants_bytearray_be` | 0 | 33.5s |  |
| 960 | `stage3d_program_constants_bytearray_le` | 0 | 33.4s |  |
| 961 | `stage3d_program_constants_invalid_input` | 21 | 30.1s |  |
| 962 | `stage3d_raytrace` | 0 | 54.4s |  |
| 963 | `stage3d_rotating_cube` | 0 | 12.2s |  |
| 964 | `stage3d_sampler` | 0 | 11.5s |  |
| 965 | `stage3d_sampler_partial_upload` | 0 | 11.4s |  |
| 966 | `stage3d_stencil` | 0 | 31.8s |  |
| 967 | `stage3d_texture` | 0 | 16.8s |  |
| 968 | `stage3d_texture_bytearray` | 0 | 12.7s |  |
| 969 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 11.9s |  |
| 970 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 13.2s |  |
| 971 | `stage3d_triangle` | 0 | 11.6s |  |
| 972 | `stage3d_triangle_bytes4` | 0 | 11.4s |  |
| 973 | `stage3d_triangle_float1` | 0 | 11.3s |  |
| 974 | `stage3d_triangle_index_upload` | 0 | 11.3s |  |
| 975 | `stage3d_x_y` | 22 | 8.7s |  |
| 976 | `stage_access` | 10 | 3.4s |  |
| 977 | `stage_display_state` | 6 | 8.7s |  |
| 978 | `stage_displayobject_properties` | 24 | 8.6s |  |
| 979 | `stage_domain_getQualifiedDefinitionNames` | 5 | 8.6s |  |
| 980 | `stage_framerate_nan` | 7 | 3.5s |  |
| 981 | `stage_framerate_negative` | 6 | 8.7s |  |
| 982 | `stage_framerate_zero` | 6 | 8.7s |  |
| 983 | `stage_invalidate` | 38 | 9.0s |  |
| 984 | `stage_loaderinfo_properties` | 24 | 28.6s |  |
| 985 | `stage_mousechildren` | 2 | 8.6s |  |
| 986 | `stage_mouseenabled` | 15 | 8.6s |  |
| 987 | `stage_overriden_setters` | 31 | 8.8s |  |
| 988 | `stage_properties` | 30 | 8.7s |  |
| 989 | `stage_properties2` | 213 | 8.8s |  |
| 990 | `stage_scale_factor` | 12 | 33.8s |  |
| 991 | `stage_stage3Ds_vector` | 1 | 8.7s |  |
| 992 | `static_length` | 24 | 9.0s |  |
| 993 | `static_text` | 3 | 9.1s |  |
| 994 | `static_var_with_this_in_ctor` | 2 | 8.9s |  |
| 995 | `statictext_text` | 8 | 9.0s |  |
| 996 | `stored_properties` | 11 | 8.9s |  |
| 997 | `strict_equality` | 34 | 8.9s |  |
| 998 | `string_call` | 13 | 8.8s |  |
| 999 | `string_case` | 23 | 8.9s |  |
| 1000 | `string_char_at` | 27 | 8.8s |  |
| 1001 | `string_char_code_at` | 28 | 8.6s |  |
| 1002 | `string_concat_fromcharcode` | 37 | 28.8s |  |
| 1003 | `string_constr` | 25 | 28.3s |  |
| 1004 | `string_indexof_lastindexof` | 87 | 8.8s |  |
| 1005 | `string_length` | 16 | 8.6s |  |
| 1006 | `string_locale_compare` | 39 | 8.9s |  |
| 1007 | `string_match` | 51 | 8.9s |  |
| 1008 | `string_relational_compare` | 4 | 8.7s |  |
| 1009 | `string_replace` | 51 | 8.8s |  |
| 1010 | `string_search` | 41 | 8.6s |  |
| 1011 | `string_slice_substr_substring` | 170 | 9.8s |  |
| 1012 | `string_split` | 29 | 8.7s |  |
| 1013 | `string_substr_negative` | 21 | 8.5s |  |
| 1014 | `string_substr_weird` | 182 | 8.5s |  |
| 1015 | `stylesheet` | 221 | 9.1s |  |
| 1016 | `stylesheet_parse_color` | 69 | 8.7s |  |
| 1017 | `stylesheet_transform` | 307 | 8.9s |  |
| 1018 | `sub_super_same_field` | 12 | 3.3s |  |
| 1019 | `subclass_superclass_linked_symbol` | 4 | 9.1s |  |
| 1020 | `subtract` | 1058 | 20.9s |  |
| 1021 | `super_get_call` | 12 | 8.7s |  |
| 1022 | `supercall_two_classobjects` | 2 | 8.6s |  |
| 1023 | `supercalls_coerce` | 8 | 8.6s |  |
| 1024 | `supercalls_weird` | 2 | 8.5s |  |
| 1025 | `superinterface_call` | 20 | 8.6s |  |
| 1026 | `superinterface_instanceof` | 18 | 8.6s |  |
| 1027 | `swf8` | 1 | 8.6s |  |
| 1028 | `swf_10_queued_goto_scripts_construct` | 52 | 28.8s |  |
| 1029 | `swf_9_goto_in_enter_frame` | 17 | 8.7s |  |
| 1030 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.6s |  |
| 1031 | `swf_9_queued_goto_scripts` | 6 | 28.6s |  |
| 1032 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 1033 | `swf_9_versioning` | 2 | 8.6s |  |
| 1034 | `swf_wrong_frame_count` | 38 | 9.1s |  |
| 1035 | `swf_wrong_frame_count_isplaying` | 22 | 8.7s |  |
| 1036 | `symbol_class_binary_data` | 8 | 8.7s |  |
| 1037 | `symbol_class_conflict` | 4 | 10.4s |  |
| 1038 | `symbol_class_root_not_zero` | 1 | 8.7s |  |
| 1039 | `symbolclass_invalid_utf8` | 2 | 8.8s |  |
| 1040 | `system_exit` | 3 | 8.7s |  |
| 1041 | `system_setclipboard_null` | 1 | 8.6s |  |
| 1042 | `tab_ordering_arrows` | 998 | 29.4s |  |
| 1043 | `tab_ordering_automatic_advanced` | 184 | 8.7s |  |
| 1044 | `tab_ordering_automatic_basic` | 45 | 28.6s |  |
| 1045 | `tab_ordering_children` | 116 | 8.9s |  |
| 1046 | `tab_ordering_custom_basic` | 34 | 8.7s |  |
| 1047 | `tab_ordering_stage_tab_children` | 32 | 8.5s |  |
| 1048 | `tab_ordering_stage_tab_children_remove_root` | 5 | 8.4s |  |
| 1049 | `tab_ordering_tabbable` | 47 | 8.6s |  |
| 1050 | `tabstop_properties` | 105 | 28.1s |  |
| 1051 | `text_element_basic` | 34 | 8.6s |  |
| 1052 | `text_engine_fontdescription` | 27 | 8.6s |  |
| 1053 | `text_engine_groupelement` | 64 | 9.4s |  |
| 1054 | `text_run` | 7 | 8.3s |  |
| 1055 | `textblock_createline_errors` | 23 | 8.7s |  |
| 1056 | `textblock_createline_fte` | 9 | 28.4s |  |
| 1057 | `textblock_properties` | 118 | 9.0s |  |
| 1058 | `textbox_click` | 37 | 28.9s |  |
| 1059 | `textfield_event` | 66 | 9.1s |  |
| 1060 | `textfield_focusin_event` | 9 | 8.6s |  |
| 1061 | `textfield_input_dead_keys_windows` | 15 | 8.6s |  |
| 1062 | `textfield_input_events` | 25 | 21.9s |  |
| 1063 | `textfield_unload` | 39 | 28.6s |  |
| 1064 | `textformat` | 1134 | 8.7s |  |
| 1065 | `textformat_display` | 14 | 8.7s |  |
| 1066 | `textformat_font_max_length` | 4 | 3.3s |  |
| 1067 | `textline_inapplicable_properties` | 10 | 8.6s |  |
| 1068 | `textline_name` | 1 | 8.4s |  |
| 1069 | `textline_raw_text_length` | 30 | 8.5s |  |
| 1070 | `textline_splitting_basic` | 76 | 8.6s |  |
| 1071 | `textline_throwerror` | 30 | 8.6s |  |
| 1072 | `textline_validity` | 162 | 8.7s |  |
| 1073 | `throw` | 3 | 8.5s |  |
| 1074 | `timeline_scripts` | 3 | 28.1s |  |
| 1075 | `timer` | 90 | 9.6s |  |
| 1076 | `timer_events` | 3 | 8.6s |  |
| 1077 | `timer_finished` | 11 | 3.4s |  |
| 1078 | `timer_invalid_delay` | 30 | 8.6s |  |
| 1079 | `timer_reset` | 8 | 21.4s |  |
| 1080 | `timer_setdelay` | 5 | 21.2s |  |
| 1081 | `trace` | 12 | 1.2s |  |
| 1082 | `truthiness` | 30 | 1.2s |  |
| 1083 | `try_catch` | 11 | 1.2s |  |
| 1084 | `try_catch_typed` | 12 | 1.2s |  |
| 1085 | `typeof` | 30 | 1.2s |  |
| 1086 | `uint_constr` | 92 | 1.2s |  |
| 1087 | `uint_tofixed` | 1215 | 1.2s |  |
| 1088 | `uint_toprecision` | 1125 | 1.2s |  |
| 1089 | `uint_tostring` | 3375 | 1.2s |  |
| 1090 | `uncaught_error_basic` | 2 | 1.2s |  |
| 1091 | `unchecked_function` | 15 | 1.2s |  |
| 1092 | `unescape` | 28 | 1.2s |  |
| 1093 | `url_loader` | 25 | 1.2s |  |
| 1094 | `url_vars` | 27 | 1.2s |  |
| 1095 | `urlrequest` | 18 | 1.2s |  |
| 1096 | `urlstream_basic` | 5 | 1.2s |  |
| 1097 | `urshift` | 1058 | 1.2s |  |
| 1098 | `utils3d` | 7 | 1.2s |  |
| 1099 | `vector3d` | 397 | 1.2s |  |
| 1100 | `vector3d_near_equals` | 80 | 1.2s |  |
| 1101 | `vector_class` | 36 | 1.1s |  |
| 1102 | `vector_class_call` | 11 | 1.1s |  |
| 1103 | `vector_coercion` | 66 | 1.1s |  |
| 1104 | `vector_concat` | 90 | 1.1s |  |
| 1105 | `vector_constr` | 107 | 1.2s |  |
| 1106 | `vector_enumeration` | 5 | 1.2s |  |
| 1107 | `vector_every` | 92 | 1.1s |  |
| 1108 | `vector_filter` | 95 | 1.2s |  |
| 1109 | `vector_holes` | 24 | 1.1s |  |
| 1110 | `vector_indexof` | 302 | 1.2s |  |
| 1111 | `vector_insertat` | 270 | 1.1s |  |
| 1112 | `vector_int_access` | 4 | 1.1s |  |
| 1113 | `vector_int_delete` | 11 | 1.2s |  |
| 1114 | `vector_join` | 58 | 1.2s |  |
| 1115 | `vector_lastindexof` | 302 | 1.2s |  |
| 1116 | `vector_legacy` | 10 | 1.1s |  |
| 1117 | `vector_map` | 85 | 1.1s |  |
| 1118 | `vector_object_final` | 1 | 1.2s |  |
| 1119 | `vector_object_toString` | 10 | 20.9s |  |
| 1120 | `vector_pushpop` | 255 | 21.8s |  |
| 1121 | `vector_reborrow_bug` | 10 | 6.8s |  |
| 1122 | `vector_removeat` | 172 | 6.9s |  |
| 1123 | `vector_reverse` | 232 | 7.1s |  |
| 1124 | `vector_shiftunshift` | 252 | 6.0s |  |
| 1125 | `vector_slice` | 331 | 7.0s |  |
| 1126 | `vector_sort` | 905 | 12.2s |  |
| 1127 | `vector_splice` | 693 | 8.1s |  |
| 1128 | `vector_splice_fixed_bug_compat` | 4 | 6.0s |  |
| 1129 | `vector_tostring` | 79 | 7.6s |  |
| 1130 | `verification` | 8 | 6.5s |  |
| 1131 | `verify_abnormal_loop` | 1 | 6.3s |  |
| 1132 | `verify_dxns_without_flag` | 3 | 6.4s |  |
| 1133 | `verify_exception_target_two_jumps` | 1 | 5.9s |  |
| 1134 | `verify_exception_targets_edge_case` | 1 | 5.9s |  |
| 1135 | `verify_illegal_opcode` | 1 | 2.8s |  |
| 1136 | `verify_jump_to_middle_of_op` | 1 | 6.0s |  |
| 1137 | `verify_lookup_switch_edge_case` | 1 | 6.0s |  |
| 1138 | `verify_method_info_oob` | 1 | 0.9s |  |
| 1139 | `verify_stack` | 5 | 6.2s |  |
| 1140 | `verify_typecheck` | 4 | 2.0s |  |
| 1141 | `verify_unreachable_exception` | 2 | 5.9s |  |
| 1142 | `versioned_isplaying` | 2 | 6.1s |  |
| 1143 | `virtual_properties` | 16 | 5.8s |  |
| 1144 | `with` | 4 | 5.9s |  |
| 1145 | `wrong_arg_count` | 7 | 5.9s |  |
| 1146 | `xml_abstract_equality` | 36 | 5.9s |  |
| 1147 | `xml_advanced` | 52 | 6.6s |  |
| 1148 | `xml_appendchild` | 10 | 6.2s |  |
| 1149 | `xml_appendchild_swf_v21` | 13 | 2.2s |  |
| 1150 | `xml_as_attribute` | 9 | 6.4s |  |
| 1151 | `xml_attribute` | 35 | 6.0s |  |
| 1152 | `xml_attribute_name` | 40 | 5.8s |  |
| 1153 | `xml_basic` | 33 | 5.8s |  |
| 1154 | `xml_child` | 25 | 6.0s |  |
| 1155 | `xml_childindex` | 7 | 5.7s |  |
| 1156 | `xml_children` | 43 | 6.4s |  |
| 1157 | `xml_class_call` | 9 | 5.9s |  |
| 1158 | `xml_contains` | 197 | 5.9s |  |
| 1159 | `xml_copy` | 20 | 28.5s |  |
| 1160 | `xml_ctor_from_tostring` | 23 | 28.7s |  |
| 1161 | `xml_delete` | 114 | 8.8s |  |
| 1162 | `xml_descendants` | 83 | 8.7s |  |
| 1163 | `xml_duplicate_attribute` | 14 | 8.7s |  |
| 1164 | `xml_elements` | 6 | 8.5s |  |
| 1165 | `xml_equals_namespace_check` | 2 | 8.5s |  |
| 1166 | `xml_explicit_use_namespace` | 5 | 8.6s |  |
| 1167 | `xml_getdescendants_qname` | 21 | 8.5s |  |
| 1168 | `xml_has_property_via_in` | 26 | 8.7s |  |
| 1169 | `xml_hasownproperty` | 6 | 8.5s |  |
| 1170 | `xml_ignore_white` | 6 | 8.6s |  |
| 1171 | `xml_length` | 2 | 8.7s |  |
| 1172 | `xml_list_as_attribute` | 9 | 8.7s |  |
| 1173 | `xml_list_concat` | 20 | 8.7s |  |
| 1174 | `xml_list_ctor_errors` | 34 | 8.6s |  |
| 1175 | `xml_list_delete_clear_parent` | 6 | 8.4s |  |
| 1176 | `xml_list_enumerate` | 4 | 8.5s |  |
| 1177 | `xml_methods_settings` | 3 | 8.6s |  |
| 1178 | `xml_mismatched_tag` | 37 | 8.6s |  |
| 1179 | `xml_namespace` | 39 | 3.2s |  |
| 1180 | `xml_namespace_methods` | 245 | 8.6s |  |
| 1181 | `xml_namespaced_property` | 7 | 8.5s |  |
| 1182 | `xml_no_namespace` | 1 | 8.6s |  |
| 1183 | `xml_nodekind` | 3 | 8.6s |  |
| 1184 | `xml_normalize` | 35 | 8.7s |  |
| 1185 | `xml_notification_bubbling` | 361 | 8.6s |  |
| 1186 | `xml_parent` | 8 | 8.6s |  |
| 1187 | `xml_set_children` | 17 | 8.7s |  |
| 1188 | `xml_set_name` | 34 | 8.7s |  |
| 1189 | `xml_settings` | 6 | 3.3s |  |
| 1190 | `xml_simple_complex_content` | 47 | 8.8s |  |
| 1191 | `xml_socket` | 11 | 9.0s |  |
| 1192 | `xml_text` | 7 | 8.7s |  |
| 1193 | `xml_tostring` | 6 | 8.7s |  |
| 1194 | `xml_tostring_namespace` | 12 | 8.5s |  |
| 1195 | `xml_unescaping` | 23 | 8.8s |  |
| 1196 | `xml_weird_ignores` | 54 | 8.8s |  |
| 1197 | `xml_wildcard` | 11 | 8.8s |  |
| 1198 | `xmldocument` | 254 | 8.9s |  |
| 1199 | `xmlnode` | 3540 | 9.0s |  |
| 1200 | `zero_frame_clip` | 3 | 9.6s |  |

## Ruffle-Matched Tests

**36 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.3s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.0s |  |
| 3 | `bitmapdata_copypixels_alpha_merge` | 4 | 4 | 27.6s |  |
| 4 | `blend_transform` | 1 | 1 | 8.6s |  |
| 5 | `bounds_mode` | 6 | 6 | 7.0s |  |
| 6 | `coerce_property` | 3 | 3 | 8.4s |  |
| 7 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 8.3s |  |
| 8 | `dictionary_weak_keys` | 1 | 1 | 28.0s |  |
| 9 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 28.5s |  |
| 10 | `edittext_device_transform_layout` | 20 | 20 | 6.0s |  |
| 11 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.2s |  |
| 12 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.9s |  |
| 13 | `edittext_tab_stops` | 6 | 6 | 7.5s |  |
| 14 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.4s |  |
| 15 | `error_1034_debug_string` | 19 | 19 | 6.5s |  |
| 16 | `event_handler_exception` | 4 | 4 | 6.4s |  |
| 17 | `freestanding_superclass` | 2 | 4 | 6.0s |  |
| 18 | `goto_framescript_queued` | 5 | 5 | 20.3s |  |
| 19 | `graphics_draw_path` | 50 | 50 | 28.7s |  |
| 20 | `groupelement_text` | 2 | 2 | 8.6s |  |
| 21 | `int_toexponential` | 76 | 76 | 8.8s |  |
| 22 | `matrix3d_append_rotation` | 1 | 3 | 8.7s |  |
| 23 | `matrix3d_recompose_edge_cases` | 85 | 85 | 9.0s |  |
| 24 | `number_convert_errors` | 706 | 706 | 8.3s |  |
| 25 | `simplebutton_childevents_script_order` | 4 | 4 | 8.8s |  |
| 26 | `slot_holes_fail` | 1 | 1 | 8.4s |  |
| 27 | `slot_id_exceeds_trait_count` | 1 | 1 | 30.2s |  |
| 28 | `soundchannel_position` | 74 | 74 | 30.6s |  |
| 29 | `soundchannel_soundcomplete` | 10 | 10 | 9.1s |  |
| 30 | `sprite_dropTarget` | 15 | 15 | 9.1s |  |
| 31 | `swf_9_goto_in_construct_frame` | 12 | 12 | 28.8s |  |
| 32 | `textblock_line_changes` | 44 | 44 | 9.3s |  |
| 33 | `textblock_releaselines` | 4 | 4 | 10.4s |  |
| 34 | `uint_toexponential` | 100 | 100 | 1.2s |  |
| 35 | `uncaught_errors_stringified` | 15 | 15 | 1.2s |  |
| 36 | `weird_superinterface_properties` | 1 | 1 | 5.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `geom_transform` | 95.9% | 71 | 74 | 3 |  |
| 3 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 4 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 5 | `displayobject_getrect` | 68.8% | 11 | 16 | 5 |  |
| 6 | `number_to_string` | 67.1% | 237 | 353 | 116 |  |
| 7 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 8 | `bytearray_bad_symbol_class_other_movie` | 66.7% | 4 | 6 | 2 |  |
| 9 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 10 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 11 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**34 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `geom_transform` | 95.9% | 71/74 | 74 | 74 |  |
| 3 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 4 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 5 | `displayobject_getrect` | 68.8% | 11/16 | 16 | 16 |  |
| 6 | `number_to_string` | 67.1% | 237/353 | 353 | 353 |  |
| 7 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 8 | `bytearray_bad_symbol_class_other_movie` | 66.7% | 4/6 | 5 | 6 |  |
| 9 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 10 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 11 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 12 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 13 | `bytearray_bad_symbol_class` | 33.3% | 1/3 | 2 | 3 |  |
| 14 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 15 | `json_parse_numbers` | 23.7% | 31/131 | 118 | 131 |  |
| 16 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 17 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 18 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 19 | `displayobject_z` | 15.8% | 6/38 | 11 | 38 |  |
| 20 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 21 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 22 | `loader_events_2` | 5.7% | 2/35 | 31 | 35 |  |
| 23 | `edittext_scroll_event` | 5.4% | 2/37 | 7 | 37 |  |
| 24 | `json_parse_errors` | 4.8% | 4/84 | 64 | 84 |  |
| 25 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 26 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 27 | `bitmap_filter_abstract` | 0.0% | 0/6 | 4 | 6 |  |
| 28 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 29 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 30 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 31 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 32 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 33 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 34 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
