# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-11 21:45 UTC

**Git SHA**: `254145a5b6`

**Run Duration**: 202m 19s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1272 |
| Passing | **1200** (94.3%) |
| Ruffle-matched | 35 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1235** (97.1%) |
| Failing | 37 |
| Total expected lines | 156989 |
| Matching lines | 152800 (97.3%) |
| Mismatched lines | 4189 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 37 | 100.0% |

## Passing Tests

**1200 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 5.8s |  |
| 2 | `accessibility` | 1 | 6.0s |  |
| 3 | `accessibilityimplementation` | 18 | 5.7s |  |
| 4 | `activation_class` | 6 | 5.5s |  |
| 5 | `add` | 1058 | 12.4s |  |
| 6 | `agal_compiler` | 13 | 6.9s |  |
| 7 | `air_datagram_socket` | 1 | 7.3s |  |
| 8 | `air_hidden_lookup` | 2 | 5.5s |  |
| 9 | `air_ifilepromise` | 1 | 6.1s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 5.7s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.0s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.9s |  |
| 13 | `all_classes/display/swf10` | 2569 | 5.8s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.0s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.0s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.0s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.9s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.9s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 5.6s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.9s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.9s |  |
| 22 | `all_classes/errors/swf10` | 140 | 5.8s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.9s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.9s |  |
| 25 | `all_classes/events/swf10` | 1638 | 5.7s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.9s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.9s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.9s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.9s |  |
| 30 | `all_classes/security/swf11` | 3 | 5.8s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.0s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.9s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.9s |  |
| 34 | `all_classes/xml/swf30` | 116 | 5.8s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.0s |  |
| 36 | `amf_array_serialization` | 17 | 20.0s |  |
| 37 | `amf_custom_obj` | 26 | 6.1s |  |
| 38 | `amf_dictionary` | 9 | 5.8s |  |
| 39 | `amf_function` | 46 | 5.6s |  |
| 40 | `amf_invalid_date` | 2 | 5.5s |  |
| 41 | `amf_missing_prop` | 6 | 5.8s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 5.6s |  |
| 43 | `amf_setter_error` | 8 | 5.9s |  |
| 44 | `amf_vector` | 40 | 6.8s |  |
| 45 | `amf_xml` | 6 | 6.7s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 7.1s |  |
| 47 | `application_domain` | 4 | 6.7s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 6.8s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 6.7s |  |
| 50 | `array_access` | 18 | 6.8s |  |
| 51 | `array_access_interpreter` | 4 | 6.7s |  |
| 52 | `array_access_no_pubns` | 2 | 6.7s |  |
| 53 | `array_concat` | 41 | 6.7s |  |
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
| 64 | `array_indexof` | 25 | 6.7s |  |
| 65 | `array_join` | 26 | 6.8s |  |
| 66 | `array_lastindexof` | 29 | 6.8s |  |
| 67 | `array_length` | 14 | 6.8s |  |
| 68 | `array_literal` | 3 | 6.7s |  |
| 69 | `array_map` | 8 | 6.7s |  |
| 70 | `array_pop` | 52 | 6.8s |  |
| 71 | `array_push` | 24 | 6.7s |  |
| 72 | `array_reborrow_bug` | 6 | 6.7s |  |
| 73 | `array_reverse` | 28 | 6.8s |  |
| 74 | `array_shift` | 51 | 2.7s |  |
| 75 | `array_slice` | 39 | 6.8s |  |
| 76 | `array_some` | 8 | 6.8s |  |
| 77 | `array_sort` | 297 | 7.1s |  |
| 78 | `array_sort_fun_swf12` | 2 | 6.8s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 80 | `array_sort_random` | 210 | 6.8s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 6.7s |  |
| 82 | `array_sorton` | 545 | 7.3s |  |
| 83 | `array_sparse_ops` | 41 | 6.8s |  |
| 84 | `array_splice` | 133 | 6.9s |  |
| 85 | `array_splice2` | 428 | 8.7s |  |
| 86 | `array_splice_types` | 48 | 8.5s |  |
| 87 | `array_storage` | 8 | 8.4s |  |
| 88 | `array_tolocalestring` | 9 | 8.4s |  |
| 89 | `array_tostring` | 12 | 8.3s |  |
| 90 | `array_unshift` | 24 | 8.4s |  |
| 91 | `array_valueof` | 9 | 8.3s |  |
| 92 | `array_vector_null_callback` | 10 | 8.3s |  |
| 93 | `astype` | 28 | 8.4s |  |
| 94 | `astypelate` | 24 | 8.5s |  |
| 95 | `astypelate_propagates` | 1 | 8.3s |  |
| 96 | `asymmetric_key_events` | 11 | 8.5s |  |
| 97 | `automation_classes` | 122 | 8.8s |  |
| 98 | `av_classes` | 340 | 8.8s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 8.5s |  |
| 100 | `avm2_catchup_dobj` | 158 | 9.3s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 94.7s |  |
| 102 | `bevel_filter` | 187 | 8.7s |  |
| 103 | `bitand` | 1058 | 20.4s |  |
| 104 | `bitmap_constr` | 17 | 8.6s |  |
| 105 | `bitmap_data` | 1000 | 16.5s |  |
| 106 | `bitmap_pixelsnapping` | 2 | 28.0s |  |
| 107 | `bitmap_properties` | 23 | 8.4s |  |
| 108 | `bitmap_subclass` | 7 | 9.9s |  |
| 109 | `bitmap_subclass_properties` | 9 | 8.8s |  |
| 110 | `bitmap_timeline` | 9 | 8.7s |  |
| 111 | `bitmapdata_accuracy` | 1 | 44.3s |  |
| 112 | `bitmapdata_applyfilter_blur` | 0 | 28.6s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.2s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | 0 | 28.2s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 28.3s |  |
| 116 | `bitmapdata_applyfilter_identity` | 4 | 27.4s |  |
| 117 | `bitmapdata_clone` | 13 | 8.6s |  |
| 118 | `bitmapdata_colortransform` | 0 | 8.9s |  |
| 119 | `bitmapdata_colortransform_oob` | 2 | 8.3s |  |
| 120 | `bitmapdata_constr` | 22 | 3.2s |  |
| 121 | `bitmapdata_constructor_from_timeline` | 1 | 8.8s |  |
| 122 | `bitmapdata_copychannel` | 0 | 29.4s |  |
| 123 | `bitmapdata_copypixels` | 23 | 28.9s |  |
| 124 | `bitmapdata_copypixels_alpha_combine` | 13 | 8.5s |  |
| 125 | `bitmapdata_copypixels_blend_over` | 1 | 6.9s |  |
| 126 | `bitmapdata_copypixelstobytearray` | 39 | 6.9s |  |
| 127 | `bitmapdata_dispose` | 7 | 6.9s |  |
| 128 | `bitmapdata_draw` | 0 | 24.4s |  |
| 129 | `bitmapdata_draw_alpha_erase` | 8 | 6.9s |  |
| 130 | `bitmapdata_draw_cab_quality` | 0 | 24.4s |  |
| 131 | `bitmapdata_draw_colortransform` | 0 | 7.0s |  |
| 132 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 24.0s |  |
| 133 | `bitmapdata_draw_filters` | 0 | 23.7s |  |
| 134 | `bitmapdata_draw_masks` | 0 | 7.2s |  |
| 135 | `bitmapdata_draw_rotation` | 0 | 7.1s |  |
| 136 | `bitmapdata_draw_self_via_graphic` | 0 | 7.0s |  |
| 137 | `bitmapdata_draw_stage` | 0 | 23.6s |  |
| 138 | `bitmapdata_drawwithquality` | 0 | 7.4s |  |
| 139 | `bitmapdata_embedded` | 9 | 7.4s |  |
| 140 | `bitmapdata_fillrect` | 0 | 7.3s |  |
| 141 | `bitmapdata_filter_sourcerect` | 0 | 24.1s |  |
| 142 | `bitmapdata_floodfill` | 35 | 6.9s |  |
| 143 | `bitmapdata_getpixels` | 39 | 23.3s |  |
| 144 | `bitmapdata_getvector` | 27 | 2.4s |  |
| 145 | `bitmapdata_histogram` | 59 | 2.4s |  |
| 146 | `bitmapdata_hittest` | 112 | 7.4s |  |
| 147 | `bitmapdata_hittest_threshold` | 18 | 7.0s |  |
| 148 | `bitmapdata_opaque` | 0 | 7.0s |  |
| 149 | `bitmapdata_pixeldissolve` | 1037 | 7.5s |  |
| 150 | `bitmapdata_pixeldissolve_image` | 0 | 7.3s |  |
| 151 | `bitmapdata_rectangle_rounding` | 16 | 7.1s |  |
| 152 | `bitmapdata_setpixels` | 286 | 8.0s |  |
| 153 | `bitmapdata_setvector` | 26 | 7.6s |  |
| 154 | `bitmapdata_sync` | 0 | 23.9s |  |
| 155 | `bitmapdata_threshold` | 176 | 7.5s |  |
| 156 | `bitmapdata_zero_size` | 8 | 6.8s |  |
| 157 | `bitnot` | 46 | 6.8s |  |
| 158 | `bitor` | 1058 | 14.9s |  |
| 159 | `bitxor` | 1058 | 15.1s |  |
| 160 | `blend_mode_null` | 1 | 6.7s |  |
| 161 | `blend_multiply_alpha` | 0 | 7.1s |  |
| 162 | `blend_scroll` | 0 | 6.9s |  |
| 163 | `blend_shader_luma_lighten` | 3 | 7.4s |  |
| 164 | `blur_filter` | 43 | 8.6s |  |
| 165 | `boolean_constr` | 32 | 8.3s |  |
| 166 | `boolean_negation` | 30 | 8.3s |  |
| 167 | `boolean_tostring` | 8 | 8.2s |  |
| 168 | `broadcast_event` | 7 | 8.3s |  |
| 169 | `button_bounds` | 1 | 8.3s |  |
| 170 | `button_hittest` | 2 | 27.5s |  |
| 171 | `button_nested_frame` | 48 | 27.6s |  |
| 172 | `button_nested_frame_simple` | 27 | 8.7s |  |
| 173 | `bytearray` | 48 | 8.6s |  |
| 174 | `bytearray_compress` | 31 | 8.3s |  |
| 175 | `bytearray_errors` | 24 | 8.4s |  |
| 176 | `bytearray_method_serialization` | 1 | 8.3s |  |
| 177 | `bytearray_oom` | 3 | 8.3s |  |
| 178 | `bytearray_readobject_amf0` | 50 | 8.3s |  |
| 179 | `bytearray_readobject_amf3` | 53 | 8.4s |  |
| 180 | `bytearray_readutf8bytes_with_bom` | 16 | 8.3s |  |
| 181 | `bytearray_serialization` | 3 | 8.3s |  |
| 182 | `bytearray_string_null` | 19 | 8.6s |  |
| 183 | `bytearray_tostring` | 15 | 8.3s |  |
| 184 | `bytearray_utf16` | 8 | 8.3s |  |
| 185 | `bytearray_writeobject` | 24 | 8.2s |  |
| 186 | `callee_in_initializer` | 6 | 8.2s |  |
| 187 | `callproplex_class` | 1 | 8.2s |  |
| 188 | `capabilities_resolution` | 8 | 28.7s |  |
| 189 | `catch_class` | 6 | 8.3s |  |
| 190 | `catch_scope_slot` | 7 | 8.4s |  |
| 191 | `checkfilter` | 4 | 3.2s |  |
| 192 | `class_call` | 32 | 8.6s |  |
| 193 | `class_cast_call` | 14 | 8.6s |  |
| 194 | `class_enumeration` | 4 | 8.5s |  |
| 195 | `class_has_own_property` | 2 | 8.6s |  |
| 196 | `class_init_interpreter_mode` | 1 | 8.4s |  |
| 197 | `class_is` | 32 | 8.5s |  |
| 198 | `class_methods` | 5 | 8.4s |  |
| 199 | `class_object_properties` | 10 | 8.5s |  |
| 200 | `class_singleton` | 18 | 8.4s |  |
| 201 | `class_supercalls_errors` | 35 | 8.6s |  |
| 202 | `class_supercalls_mismatched` | 26 | 8.5s |  |
| 203 | `class_superclass_wrong_order` | 1 | 8.7s |  |
| 204 | `class_to_locale_string` | 2 | 8.6s |  |
| 205 | `class_to_string` | 2 | 8.6s |  |
| 206 | `class_value_of` | 2 | 8.6s |  |
| 207 | `click_block` | 5 | 29.2s |  |
| 208 | `click_invisible` | 3 | 8.9s |  |
| 209 | `closures` | 12 | 8.7s |  |
| 210 | `coerce_return_type` | 40 | 8.8s |  |
| 211 | `coerce_return_type_fail` | 2 | 8.7s |  |
| 212 | `coerce_return_void` | 3 | 8.6s |  |
| 213 | `coerce_string` | 86 | 8.8s |  |
| 214 | `coerce_string_precision` | 28 | 8.7s |  |
| 215 | `coerce_to_primitive_side_effects` | 29 | 8.8s |  |
| 216 | `color_matrix_filter` | 19 | 8.9s |  |
| 217 | `construct_errors_swf10` | 8 | 8.8s |  |
| 218 | `construct_frame_list` | 22 | 28.5s |  |
| 219 | `construct_interface` | 3 | 8.7s |  |
| 220 | `constructor_call` | 3 | 8.8s |  |
| 221 | `constructors_vs_timeline` | 5 | 28.8s |  |
| 222 | `constructprop_dynamic_primitive` | 7 | 8.8s |  |
| 223 | `constructprop_method` | 2 | 8.8s |  |
| 224 | `constructsuper_null` | 2 | 3.4s |  |
| 225 | `content_element_basic` | 50 | 9.0s |  |
| 226 | `context3d_creation` | 9 | 8.7s |  |
| 227 | `control_flow_bool` | 4 | 8.7s |  |
| 228 | `control_flow_stricteq` | 8 | 8.7s |  |
| 229 | `convert_boolean` | 30 | 8.7s |  |
| 230 | `convert_integer` | 90 | 8.8s |  |
| 231 | `convert_number` | 56 | 8.8s |  |
| 232 | `convert_uinteger` | 90 | 8.8s |  |
| 233 | `convolution_filter` | 89 | 8.9s |  |
| 234 | `core_exceptions` | 47 | 9.5s |  |
| 235 | `cpool_index_invalid_bytecode_1` | 6 | 8.7s |  |
| 236 | `cpool_index_invalid_bytecode_2` | 3 | 8.7s |  |
| 237 | `cpool_index_invalid_bytecode_3` | 1 | 8.6s |  |
| 238 | `cross_api_version_call_newer` | 12 | 9.3s |  |
| 239 | `cross_api_version_call_older` | 12 | 9.1s |  |
| 240 | `cryptscore` | 11 | 8.8s |  |
| 241 | `currency_parse_result` | 7 | 8.7s |  |
| 242 | `date` | 30 | 9.2s |  |
| 243 | `date_parse` | 36 | 8.8s |  |
| 244 | `declocal` | 46 | 2.4s |  |
| 245 | `declocal_i` | 46 | 6.7s |  |
| 246 | `decode_uri` | 71 | 6.9s |  |
| 247 | `decrement` | 46 | 6.7s |  |
| 248 | `decrement_i` | 46 | 2.3s |  |
| 249 | `default_values` | 7 | 6.7s |  |
| 250 | `delayed_symbolclass` | 28 | 23.0s |  |
| 251 | `describe_type_basic` | 152 | 7.1s |  |
| 252 | `describe_type_json` | 301 | 6.8s |  |
| 253 | `describe_type_metadata` | 125 | 6.8s |  |
| 254 | `describe_type_native` | 23 | 6.7s |  |
| 255 | `dictionary_access` | 62 | 6.9s |  |
| 256 | `dictionary_access_no_pubns` | 2 | 6.6s |  |
| 257 | `dictionary_delete` | 101 | 7.1s |  |
| 258 | `dictionary_foreach` | 42 | 6.9s |  |
| 259 | `dictionary_hasownproperty` | 63 | 6.9s |  |
| 260 | `dictionary_in` | 62 | 6.9s |  |
| 261 | `dictionary_iter_modify` | 8 | 6.7s |  |
| 262 | `dictionary_namespaces` | 36 | 6.8s |  |
| 263 | `displacement_map_filter` | 61 | 6.9s |  |
| 264 | `displayobject_alpha` | 277 | 6.7s |  |
| 265 | `displayobject_blendmode` | 0 | 24.2s |  |
| 266 | `displayobject_colortransform_nested` | 0 | 22.9s |  |
| 267 | `displayobject_early_init` | 54 | 8.0s |  |
| 268 | `displayobject_filters` | 17 | 6.8s |  |
| 269 | `displayobject_from_enterframe` | 1 | 23.0s |  |
| 270 | `displayobject_getbounds_shape` | 0 | 23.0s |  |
| 271 | `displayobject_height` | 6052 | 23.3s |  |
| 272 | `displayobject_hittestobject` | 32 | 6.8s |  |
| 273 | `displayobject_hittestpoint` | 49 | 7.0s |  |
| 274 | `displayobject_hittestpoint_boundary` | 65 | 23.4s |  |
| 275 | `displayobject_hittestpoint_root` | 13 | 7.0s |  |
| 276 | `displayobject_invalid_floats` | 60 | 6.7s |  |
| 277 | `displayobject_invalid_props` | 3 | 2.3s |  |
| 278 | `displayobject_mask` | 3 | 7.0s |  |
| 279 | `displayobject_mask_self_referential` | 0 | 6.6s |  |
| 280 | `displayobject_metaData` | 3 | 6.7s |  |
| 281 | `displayobject_name` | 22 | 7.0s |  |
| 282 | `displayobject_name_from_timeline` | 24 | 6.8s |  |
| 283 | `displayobject_opaque_background` | 6 | 6.9s |  |
| 284 | `displayobject_parent` | 12 | 8.7s |  |
| 285 | `displayobject_root` | 24 | 8.5s |  |
| 286 | `displayobject_rotation` | 1284 | 8.5s |  |
| 287 | `displayobject_scrollrect` | 33 | 12.8s |  |
| 288 | `displayobject_set_matrix_nested` | 0 | 28.0s |  |
| 289 | `displayobject_set_name_loaded` | 3 | 8.8s |  |
| 290 | `displayobject_subclass` | 2 | 8.4s |  |
| 291 | `displayobject_transform` | 89 | 8.6s |  |
| 292 | `displayobject_visible` | 23 | 8.4s |  |
| 293 | `displayobject_width` | 4852 | 28.2s |  |
| 294 | `displayobject_x` | 614 | 8.4s |  |
| 295 | `displayobject_y` | 617 | 8.4s |  |
| 296 | `displayobjectcontainer_addchild` | 32 | 8.6s |  |
| 297 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 8.4s |  |
| 298 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.6s |  |
| 299 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 8.6s |  |
| 300 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 8.6s |  |
| 301 | `displayobjectcontainer_addchildat` | 42 | 8.5s |  |
| 302 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.3s |  |
| 303 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 8.5s |  |
| 304 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.5s |  |
| 305 | `displayobjectcontainer_contains` | 66 | 27.8s |  |
| 306 | `displayobjectcontainer_getchildat` | 4 | 8.5s |  |
| 307 | `displayobjectcontainer_getchildbyname` | 9 | 8.4s |  |
| 308 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 8.4s |  |
| 309 | `displayobjectcontainer_getchildindex` | 28 | 8.4s |  |
| 310 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 27.8s |  |
| 311 | `displayobjectcontainer_removechild` | 10 | 8.3s |  |
| 312 | `displayobjectcontainer_removechild_errors` | 4 | 8.4s |  |
| 313 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 8.4s |  |
| 314 | `displayobjectcontainer_removechildat` | 18 | 8.4s |  |
| 315 | `displayobjectcontainer_removechildren` | 51 | 8.7s |  |
| 316 | `displayobjectcontainer_setchildindex` | 42 | 8.3s |  |
| 317 | `displayobjectcontainer_stopallmovieclips` | 2 | 28.1s |  |
| 318 | `displayobjectcontainer_swapchildren` | 42 | 8.4s |  |
| 319 | `displayobjectcontainer_swapchildrenat` | 42 | 8.4s |  |
| 320 | `displayobjectcontainer_timelineinstance` | 48 | 27.8s |  |
| 321 | `divide` | 1058 | 20.6s |  |
| 322 | `doabc_and_symbolclass_script_init_goto` | 7 | 27.9s |  |
| 323 | `doabc_and_symbolclass_script_init_normal` | 6 | 8.4s |  |
| 324 | `doabc_is_eager` | 1 | 27.6s |  |
| 325 | `documentclass` | 9 | 7.3s |  |
| 326 | `domain_memory` | 133 | 8.2s |  |
| 327 | `drag_drop` | 10 | 7.4s |  |
| 328 | `drop_shadow_filter` | 172 | 7.4s |  |
| 329 | `duplicate_defs` | 1 | 7.0s |  |
| 330 | `eager_init` | 1 | 7.0s |  |
| 331 | `east_asian_justifier_clone` | 8 | 7.2s |  |
| 332 | `edit_text_linkage` | 7 | 7.3s |  |
| 333 | `edittext_align` | 60 | 8.2s |  |
| 334 | `edittext_always_show_selection` | 0 | 25.1s |  |
| 335 | `edittext_antialiastype` | 296 | 7.4s |  |
| 336 | `edittext_at_point_methods_basic` | 16 | 8.2s |  |
| 337 | `edittext_autosize` | 39 | 7.4s |  |
| 338 | `edittext_autosize_align` | 0 | 23.1s |  |
| 339 | `edittext_autosize_height_dynamic` | 60 | 23.9s |  |
| 340 | `edittext_autosize_height_input` | 60 | 7.6s |  |
| 341 | `edittext_autosize_lazy_bounds_events` | 65 | 7.4s |  |
| 342 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.2s |  |
| 343 | `edittext_autosize_lazy_bounds_props` | 490 | 8.5s |  |
| 344 | `edittext_autosize_lazy_bounds_visual` | 0 | 7.4s |  |
| 345 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.3s |  |
| 346 | `edittext_bottom_scroll_v_basic` | 210 | 7.4s |  |
| 347 | `edittext_bounds_scale` | 24 | 23.5s |  |
| 348 | `edittext_bullet` | 30 | 7.4s |  |
| 349 | `edittext_default_format` | 221 | 7.5s |  |
| 350 | `edittext_default_format_empty` | 136 | 7.6s |  |
| 351 | `edittext_empty_text_format` | 7 | 7.2s |  |
| 352 | `edittext_focus_selection` | 5 | 7.4s |  |
| 353 | `edittext_font_size` | 45 | 7.4s |  |
| 354 | `edittext_format_empty_font` | 8 | 2.8s |  |
| 355 | `edittext_get_char_index_at_point` | 4 | 26.5s |  |
| 356 | `edittext_get_line_index_at_point` | 2 | 24.8s |  |
| 357 | `edittext_get_line_index_of_char` | 76 | 8.1s |  |
| 358 | `edittext_getcharboundaries` | 172 | 7.5s |  |
| 359 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.1s |  |
| 360 | `edittext_getcharboundaries_scroll` | 85 | 7.3s |  |
| 361 | `edittext_getlinemetrics` | 146 | 7.7s |  |
| 362 | `edittext_html` | 3101 | 7.7s |  |
| 363 | `edittext_html_condensewhite` | 487 | 7.3s |  |
| 364 | `edittext_html_entity` | 4 | 7.2s |  |
| 365 | `edittext_html_font_size_swf12` | 267 | 8.6s |  |
| 366 | `edittext_html_font_size_swf13` | 273 | 8.2s |  |
| 367 | `edittext_html_roundtrip` | 17 | 8.9s |  |
| 368 | `edittext_ime_focus_lost` | 9 | 27.8s |  |
| 369 | `edittext_input_control` | 12 | 8.6s |  |
| 370 | `edittext_leading` | 9 | 8.9s |  |
| 371 | `edittext_letter_spacing` | 15 | 8.9s |  |
| 372 | `edittext_line_methods` | 294 | 10.0s |  |
| 373 | `edittext_line_metrics` | 11 | 29.3s |  |
| 374 | `edittext_margins` | 25 | 8.7s |  |
| 375 | `edittext_max_scroll_h_basic` | 475 | 8.8s |  |
| 376 | `edittext_max_scroll_v_basic` | 1000 | 8.7s |  |
| 377 | `edittext_mouse_selection` | 363 | 29.1s |  |
| 378 | `edittext_mousedown` | 3 | 8.9s |  |
| 379 | `edittext_mouseenabled` | 26 | 8.5s |  |
| 380 | `edittext_newline_character` | 22 | 8.4s |  |
| 381 | `edittext_newline_stripping` | 64 | 11.4s |  |
| 382 | `edittext_newlines` | 30 | 8.8s |  |
| 383 | `edittext_paragraph_methods` | 257 | 8.4s |  |
| 384 | `edittext_paste_events` | 8 | 8.5s |  |
| 385 | `edittext_paste_maxchars` | 4 | 8.5s |  |
| 386 | `edittext_paste_restrict` | 16 | 8.4s |  |
| 387 | `edittext_restrict` | 191 | 8.4s |  |
| 388 | `edittext_restrict_events` | 22 | 8.4s |  |
| 389 | `edittext_scrollh` | 10 | 3.2s |  |
| 390 | `edittext_selected_text` | 9 | 8.4s |  |
| 391 | `edittext_set_html_same` | 17 | 8.3s |  |
| 392 | `edittext_set_text_vs_html` | 9 | 8.3s |  |
| 393 | `edittext_stylesheet` | 536 | 8.7s |  |
| 394 | `edittext_stylesheet_custom_tag` | 76 | 8.4s |  |
| 395 | `edittext_stylesheet_display` | 272 | 8.6s |  |
| 396 | `edittext_tag_indent` | 49 | 27.6s |  |
| 397 | `edittext_underline` | 40 | 8.8s |  |
| 398 | `edittext_width_height` | 103 | 8.7s |  |
| 399 | `edittext_wordwrap_word` | 150 | 8.5s |  |
| 400 | `edittext_wrap_breaks` | 2375 | 9.0s |  |
| 401 | `element_format_clone` | 44 | 8.5s |  |
| 402 | `element_format_constructor_order` | 64 | 3.4s |  |
| 403 | `element_format_properties` | 235 | 9.4s |  |
| 404 | `empty_bounds` | 1 | 8.3s |  |
| 405 | `encode_uri_surrogate_pair_invalid` | 8 | 8.5s |  |
| 406 | `encode_uri_surrogate_pair_swf11` | 15 | 8.3s |  |
| 407 | `equals` | 512 | 12.6s |  |
| 408 | `error_geterrormessage` | 779 | 8.6s |  |
| 409 | `error_prototype` | 15 | 8.6s |  |
| 410 | `error_stack_trace` | 45 | 8.6s |  |
| 411 | `error_stack_trace_debug_swf17` | 0 | 28.4s |  |
| 412 | `error_stack_trace_debug_swf18` | 0 | 8.4s |  |
| 413 | `error_stack_trace_edge_cases` | 6 | 8.7s |  |
| 414 | `error_stack_trace_release_swf17` | 0 | 3.3s |  |
| 415 | `error_stack_trace_release_swf18` | 0 | 8.4s |  |
| 416 | `error_throwerror` | 103 | 8.6s |  |
| 417 | `error_tostring` | 29 | 8.6s |  |
| 418 | `error_tostring_more` | 86 | 8.6s |  |
| 419 | `es3_inheritance` | 31 | 8.6s |  |
| 420 | `es4_inheritance` | 30 | 8.7s |  |
| 421 | `es4_interfaces` | 30 | 8.7s |  |
| 422 | `es4_method_binding` | 8 | 3.4s |  |
| 423 | `es4_oop_prototypes` | 14 | 8.7s |  |
| 424 | `es4_protected_inheritance` | 6 | 8.6s |  |
| 425 | `escape` | 71 | 8.6s |  |
| 426 | `escape_multi_byte` | 45 | 8.7s |  |
| 427 | `event_bubbles` | 2 | 8.5s |  |
| 428 | `event_cancelable` | 2 | 8.4s |  |
| 429 | `event_clone` | 20 | 8.5s |  |
| 430 | `event_clone_error_redispatch` | 3 | 8.6s |  |
| 431 | `event_clone_on_redispatch` | 10 | 8.7s |  |
| 432 | `event_formattostring` | 31 | 8.7s |  |
| 433 | `event_isdefaultprevented` | 12 | 8.5s |  |
| 434 | `event_target_getter` | 5 | 3.2s |  |
| 435 | `event_target_set` | 9 | 8.5s |  |
| 436 | `event_type` | 1 | 8.5s |  |
| 437 | `event_valueof_tostring` | 18 | 8.6s |  |
| 438 | `eventdispatcher_dispatchevent` | 12 | 8.6s |  |
| 439 | `eventdispatcher_dispatchevent_cancel` | 20 | 8.5s |  |
| 440 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 8.6s |  |
| 441 | `eventdispatcher_dispatchevent_indirect` | 9 | 8.6s |  |
| 442 | `eventdispatcher_dispatchevent_this` | 5 | 8.5s |  |
| 443 | `eventdispatcher_haseventlistener` | 25 | 8.4s |  |
| 444 | `eventdispatcher_interface_invoke` | 1 | 8.4s |  |
| 445 | `eventdispatcher_tostring` | 10 | 8.6s |  |
| 446 | `eventdispatcher_willtrigger` | 25 | 6.8s |  |
| 447 | `falsiness` | 30 | 6.8s |  |
| 448 | `fast_index_access` | 12 | 6.9s |  |
| 449 | `filefilter_properties` | 4 | 6.8s |  |
| 450 | `filereference_browse_cancel` | 3 | 6.7s |  |
| 451 | `filereference_browse_select` | 9 | 6.7s |  |
| 452 | `filereference_load` | 31 | 2.6s |  |
| 453 | `filereference_save` | 16 | 6.8s |  |
| 454 | `filereference_save_and_browse` | 42 | 6.8s |  |
| 455 | `filereference_save_and_load` | 22 | 6.8s |  |
| 456 | `filereference_uninitialized` | 8 | 6.7s |  |
| 457 | `filereferencelist_browse_cancel` | 6 | 2.6s |  |
| 458 | `filereferencelist_browse_select` | 7 | 6.7s |  |
| 459 | `filter_rewind` | 8 | 22.3s |  |
| 460 | `filters_array_holes` | 25 | 7.8s |  |
| 461 | `finddef` | 3 | 6.7s |  |
| 462 | `findprop_global_prototype` | 6 | 6.8s |  |
| 463 | `flash_media_video_constructor` | 156 | 7.4s |  |
| 464 | `flash_media_video_rotation_probe` | 27 | 6.9s |  |
| 465 | `flash_media_video_setter` | 40 | 7.2s |  |
| 466 | `flash_trace` | 17 | 6.8s |  |
| 467 | `flash_ui_mouse_cursor` | 35 | 7.1s |  |
| 468 | `flash_xml` | 29 | 6.9s |  |
| 469 | `flash_xml_cloneNode` | 22 | 6.8s |  |
| 470 | `flash_xml_namespace` | 109 | 6.7s |  |
| 471 | `flash_xml_removeNode` | 60 | 6.8s |  |
| 472 | `focus_events_code` | 161 | 22.4s |  |
| 473 | `focus_events_key_basic` | 132 | 22.4s |  |
| 474 | `focus_events_key_navigation` | 53 | 22.2s |  |
| 475 | `focus_events_key_same_object` | 26 | 6.8s |  |
| 476 | `focus_events_mixed_key_mouse` | 100 | 22.0s |  |
| 477 | `focus_events_mouse_basic` | 260 | 22.3s |  |
| 478 | `focus_events_mouse_focusable` | 112 | 22.3s |  |
| 479 | `focus_events_mouse_same_object` | 40 | 6.8s |  |
| 480 | `focus_remove` | 20 | 22.1s |  |
| 481 | `focus_root_movie` | 4 | 23.8s |  |
| 482 | `focus_stage` | 1 | 6.7s |  |
| 483 | `focusrect` | 18 | 7.4s |  |
| 484 | `focusrect_focuslost` | 9 | 6.8s |  |
| 485 | `focusrect_property` | 110 | 2.5s |  |
| 486 | `font_description_clone` | 14 | 6.7s |  |
| 487 | `font_embedded` | 24 | 5.8s |  |
| 488 | `font_enumeratefonts` | 41 | 5.8s |  |
| 489 | `font_enumeratefonts_filter` | 4 | 6.2s |  |
| 490 | `font_enumeratefonts_order` | 9 | 6.6s |  |
| 491 | `font_hasglyphs` | 40 | 5.9s |  |
| 492 | `font_registerfont` | 129 | 6.2s |  |
| 493 | `framelabel_constr` | 5 | 5.5s |  |
| 494 | `function_call` | 12 | 2.1s |  |
| 495 | `function_call_arguments` | 46 | 5.5s |  |
| 496 | `function_call_arguments_enumerate` | 5 | 5.4s |  |
| 497 | `function_call_coercion` | 108 | 5.6s |  |
| 498 | `function_call_default` | 6 | 5.4s |  |
| 499 | `function_call_rest` | 22 | 5.6s |  |
| 500 | `function_call_types` | 3 | 5.6s |  |
| 501 | `function_call_via_apply` | 11 | 5.5s |  |
| 502 | `function_call_via_call` | 3 | 5.5s |  |
| 503 | `function_display_anonymous` | 7 | 2.2s |  |
| 504 | `function_length` | 6 | 5.6s |  |
| 505 | `function_object` | 2 | 5.5s |  |
| 506 | `function_proto` | 5 | 5.4s |  |
| 507 | `function_proto_created` | 61 | 5.6s |  |
| 508 | `function_to_locale_string` | 4 | 5.6s |  |
| 509 | `function_to_string` | 4 | 5.8s |  |
| 510 | `function_type` | 6 | 5.8s |  |
| 511 | `function_unbound_this` | 51 | 5.7s |  |
| 512 | `function_value_of` | 4 | 2.3s |  |
| 513 | `game_input` | 4 | 5.7s |  |
| 514 | `generate_random_bytes` | 3 | 5.5s |  |
| 515 | `get_definition_by_name` | 11 | 5.7s |  |
| 516 | `get_qualified_class_name` | 20 | 5.8s |  |
| 517 | `get_qualified_super_class_name` | 18 | 5.6s |  |
| 518 | `get_slot_edge_cases` | 1 | 5.6s |  |
| 519 | `get_timer` | 2 | 2.1s |  |
| 520 | `getglobalslot` | 1 | 5.4s |  |
| 521 | `getouterscope` | 8 | 5.9s |  |
| 522 | `getouterscope_two_classobjects` | 13 | 5.7s |  |
| 523 | `getter_different_namespace_setter` | 2 | 5.5s |  |
| 524 | `glow_filter` | 127 | 5.8s |  |
| 525 | `goto_button_nested_framescript` | 28 | 18.1s |  |
| 526 | `goto_in_constructframe` | 12 | 7.2s |  |
| 527 | `goto_in_scene_last_frame` | 2 | 22.5s |  |
| 528 | `goto_methods` | 56 | 7.0s |  |
| 529 | `goto_methods_swfver10` | 8 | 6.9s |  |
| 530 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 531 | `goto_nested_framescript` | 9 | 7.2s |  |
| 532 | `goto_on_orphan` | 15 | 22.9s |  |
| 533 | `gradient_bevel_filter` | 206 | 7.0s |  |
| 534 | `gradient_glow_filter` | 206 | 6.9s |  |
| 535 | `graphic_linkage` | 9 | 6.9s |  |
| 536 | `graphics_bad_direct_commands` | 5 | 8.5s |  |
| 537 | `graphics_bitmap_fill` | 0 | 8.5s |  |
| 538 | `graphics_bitmaps` | 0 | 7.5s |  |
| 539 | `graphics_direct_commands` | 0 | 7.8s |  |
| 540 | `graphics_draw_triangles` | 98 | 23.2s |  |
| 541 | `graphics_gradients` | 0 | 7.1s |  |
| 542 | `graphics_gradients_nulls` | 0 | 7.0s |  |
| 543 | `graphics_path` | 56 | 6.8s |  |
| 544 | `graphics_round_rects` | 0 | 7.0s |  |
| 545 | `graphics_simple_shapes` | 0 | 7.3s |  |
| 546 | `greaterequals` | 512 | 9.7s |  |
| 547 | `greaterthan` | 512 | 9.9s |  |
| 548 | `has_own_property` | 102 | 7.5s |  |
| 549 | `hasownproperty_namespaces` | 2 | 7.1s |  |
| 550 | `hello_world` | 1 | 7.4s |  |
| 551 | `hittest_morph` | 30 | 7.0s |  |
| 552 | `if_eq` | 10 | 7.0s |  |
| 553 | `if_gt` | 1 | 7.0s |  |
| 554 | `if_gte` | 10 | 3.0s |  |
| 555 | `if_lt` | 1 | 1.1s |  |
| 556 | `if_lte` | 10 | 6.7s |  |
| 557 | `if_ne` | 7 | 2.8s |  |
| 558 | `if_stricteq` | 6 | 6.8s |  |
| 559 | `if_strictne` | 11 | 6.9s |  |
| 560 | `ime_linux_dead_keys` | 10 | 7.0s |  |
| 561 | `in` | 102 | 7.2s |  |
| 562 | `inclocal` | 46 | 2.6s |  |
| 563 | `inclocal_i` | 46 | 7.0s |  |
| 564 | `increment` | 46 | 7.0s |  |
| 565 | `increment_i` | 46 | 8.4s |  |
| 566 | `indexing_delete` | 75 | 8.3s |  |
| 567 | `indexof_xml` | 10 | 8.5s |  |
| 568 | `init_callee_cached` | 24 | 8.4s |  |
| 569 | `instanceof` | 58 | 8.6s |  |
| 570 | `instantiate_root_character` | 4 | 8.8s |  |
| 571 | `instantiation_on_enter_frame` | 7 | 27.7s |  |
| 572 | `instantiation_on_enterframe_gotoandstop` | 8 | 8.4s |  |
| 573 | `int_constr` | 92 | 8.3s |  |
| 574 | `int_edge_cases` | 19 | 8.4s |  |
| 575 | `int_instanceof` | 3 | 8.3s |  |
| 576 | `int_tofixed` | 1215 | 8.4s |  |
| 577 | `int_toprecision` | 1125 | 8.4s |  |
| 578 | `int_tostring` | 3375 | 8.5s |  |
| 579 | `interactiveobject_enabled` | 25 | 8.5s |  |
| 580 | `interface_namespaces` | 78 | 8.7s |  |
| 581 | `invalid_utf8` | 12 | 8.6s |  |
| 582 | `is_finite` | 46 | 8.6s |  |
| 583 | `is_nan` | 46 | 8.4s |  |
| 584 | `is_prototype_of` | 12 | 8.4s |  |
| 585 | `issue_10221` | 2 | 8.4s |  |
| 586 | `issue_13780` | 12 | 8.5s |  |
| 587 | `issue_14901` | 1 | 8.4s |  |
| 588 | `issue_17675_edittext_paste_maxchars` | 1 | 8.5s |  |
| 589 | `issue_5292` | 5 | 8.5s |  |
| 590 | `issue_8630` | 2 | 8.4s |  |
| 591 | `issue_8630_placeremoveplace` | 15 | 8.5s |  |
| 592 | `issue_8630_placeremoveplace_scriptremove` | 16 | 8.3s |  |
| 593 | `issue_8630_scriptremove` | 11 | 8.5s |  |
| 594 | `istype` | 24 | 3.3s |  |
| 595 | `istypelate` | 58 | 8.7s |  |
| 596 | `istypelate_coerce` | 198 | 9.5s |  |
| 597 | `jpeg_loader_context` | 6 | 8.4s |  |
| 598 | `json_errors` | 9 | 28.0s |  |
| 599 | `json_parse` | 21 | 8.3s |  |
| 600 | `json_stringify` | 12 | 8.6s |  |
| 601 | `json_stringify_function` | 12 | 8.3s |  |
| 602 | `json_stringify_order` | 1 | 8.3s |  |
| 603 | `json_version_gated` | 1 | 8.3s |  |
| 604 | `key_input_80percent` | 1812 | 8.7s |  |
| 605 | `key_input_location` | 126 | 8.4s |  |
| 606 | `key_input_numpad` | 384 | 8.3s |  |
| 607 | `large_preload_from_bytes` | 51 | 11.9s |  |
| 608 | `large_preload_from_url` | 27 | 10.7s |  |
| 609 | `large_preload_image_from_bytes` | 25 | 8.9s |  |
| 610 | `lazyinit` | 17 | 8.5s |  |
| 611 | `lessequals` | 512 | 12.2s |  |
| 612 | `lessthan` | 512 | 12.3s |  |
| 613 | `loader_bitmap_transparency` | 14 | 8.5s |  |
| 614 | `loader_bytes_unknown_content` | 14 | 8.4s |  |
| 615 | `loader_child_getdefinition` | 5 | 8.7s |  |
| 616 | `loader_duplicate_class` | 48 | 10.4s |  |
| 617 | `loader_duplicate_coerce` | 3 | 8.7s |  |
| 618 | `loader_duplicate_coerce_new_domain` | 4 | 8.5s |  |
| 619 | `loader_error_in_root_ctor` | 4 | 8.7s |  |
| 620 | `loader_events` | 92 | 10.5s |  |
| 621 | `loader_image` | 8 | 8.9s |  |
| 622 | `loader_jpegxr` | 2 | 28.0s |  |
| 623 | `loader_jpegxr_alpha` | 1 | 27.7s |  |
| 624 | `loader_loadbytes_events` | 30 | 9.0s |  |
| 625 | `loader_loadbytes_invalid_png` | 4 | 8.5s |  |
| 626 | `loader_loadbytes_url` | 12 | 8.7s |  |
| 627 | `loader_loaderurl` | 6 | 8.8s |  |
| 628 | `loader_method` | 85 | 8.5s |  |
| 629 | `loader_noninteractive_try_click_root` | 5 | 28.2s |  |
| 630 | `loader_reuse` | 38 | 8.7s |  |
| 631 | `loader_try_click_root` | 16 | 8.7s |  |
| 632 | `loader_unknown_content` | 24 | 8.5s |  |
| 633 | `loader_visibility_interactive` | 1 | 8.4s |  |
| 634 | `loaderinfo_events` | 7 | 8.4s |  |
| 635 | `loaderinfo_loadurl` | 12 | 8.3s |  |
| 636 | `loaderinfo_more` | 6 | 8.6s |  |
| 637 | `loaderinfo_properties` | 18 | 27.6s |  |
| 638 | `loaderinfo_properties_not_loaded` | 23 | 8.5s |  |
| 639 | `loaderinfo_quine` | 1005 | 8.3s |  |
| 640 | `loaderinfo_root` | 10 | 8.3s |  |
| 641 | `loaderinfo_root_allows` | 2 | 8.3s |  |
| 642 | `localconnection` | 890 | 10.7s |  |
| 643 | `localconnection_send` | 4 | 6.9s |  |
| 644 | `lshift` | 1058 | 15.8s |  |
| 645 | `mask_reapply` | 1 | 22.5s |  |
| 646 | `math` | 497 | 6.9s |  |
| 647 | `matrix` | 338 | 14.7s |  |
| 648 | `matrix3d` | 57 | 7.3s |  |
| 649 | `matrix3d_append` | 16 | 6.8s |  |
| 650 | `matrix3d_append_prepend_scale` | 86 | 6.9s |  |
| 651 | `matrix3d_append_prepend_translation` | 42 | 6.8s |  |
| 652 | `matrix3d_compose` | 34 | 7.0s |  |
| 653 | `matrix3d_constructor_clone` | 15 | 6.8s |  |
| 654 | `matrix3d_copy_column` | 83 | 7.0s |  |
| 655 | `matrix3d_copy_from` | 19 | 6.9s |  |
| 656 | `matrix3d_copy_raw_data_from` | 55 | 2.8s |  |
| 657 | `matrix3d_copy_raw_data_to` | 38 | 6.9s |  |
| 658 | `matrix3d_copy_row` | 83 | 6.7s |  |
| 659 | `matrix3d_copy_to_matrix3d` | 19 | 6.8s |  |
| 660 | `matrix3d_determinant` | 182 | 7.0s |  |
| 661 | `matrix3d_interpolate` | 21 | 7.1s |  |
| 662 | `matrix3d_invert` | 18 | 2.7s |  |
| 663 | `matrix3d_position` | 19 | 7.0s |  |
| 664 | `matrix3d_precision` | 28 | 7.1s |  |
| 665 | `matrix3d_prepend` | 16 | 6.8s |  |
| 666 | `matrix3d_raw_data` | 33 | 6.9s |  |
| 667 | `matrix3d_transform_vector` | 52 | 7.0s |  |
| 668 | `matrix3d_transpose` | 5 | 6.8s |  |
| 669 | `method_association` | 5 | 6.8s |  |
| 670 | `method_without_body` | 3 | 22.2s |  |
| 671 | `missing_external_interface` | 10 | 6.8s |  |
| 672 | `modulo` | 1058 | 15.7s |  |
| 673 | `morph_shape` | 2 | 22.9s |  |
| 674 | `mouse_children` | 192 | 23.0s |  |
| 675 | `mouse_click_events` | 90 | 22.1s |  |
| 676 | `mouse_double_click_events` | 188 | 6.8s |  |
| 677 | `mouse_empty_parent` | 4 | 6.8s |  |
| 678 | `mouse_over_while_dragging` | 3 | 6.9s |  |
| 679 | `mouse_pick_avm1_root` | 2 | 22.4s |  |
| 680 | `mouse_pick_button_mode` | 2 | 6.9s |  |
| 681 | `mouse_pick_dobj_mask` | 4 | 7.1s |  |
| 682 | `mouse_pick_masking` | 7 | 28.8s |  |
| 683 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 28.0s |  |
| 684 | `mouse_pick_non_interactive_dobj_mask` | 3 | 8.9s |  |
| 685 | `mouse_pick_text` | 8 | 8.5s |  |
| 686 | `mouse_sibling` | 8 | 8.5s |  |
| 687 | `mouse_wheel_events` | 36 | 29.5s |  |
| 688 | `mouseevent_constr` | 66 | 8.5s |  |
| 689 | `mouseevent_stagexy` | 35 | 8.5s |  |
| 690 | `mouseevent_valueof_tostring` | 28 | 8.5s |  |
| 691 | `movieclip_addframescript` | 3 | 28.1s |  |
| 692 | `movieclip_addframescript_error` | 9 | 8.5s |  |
| 693 | `movieclip_child_property` | 16 | 8.6s |  |
| 694 | `movieclip_constr` | 21 | 8.5s |  |
| 695 | `movieclip_currentlabels` | 17 | 28.1s |  |
| 696 | `movieclip_currentlabels_dupes1` | 46 | 27.7s |  |
| 697 | `movieclip_currentlabels_dupes2` | 30 | 8.5s |  |
| 698 | `movieclip_currentlabels_dupes3` | 67 | 8.6s |  |
| 699 | `movieclip_currentscene` | 12 | 8.5s |  |
| 700 | `movieclip_dispatchevent` | 430 | 8.5s |  |
| 701 | `movieclip_dispatchevent_cancel` | 102 | 8.5s |  |
| 702 | `movieclip_dispatchevent_handlerorder` | 251 | 8.5s |  |
| 703 | `movieclip_dispatchevent_selfadd` | 80 | 8.4s |  |
| 704 | `movieclip_dispatchevent_target` | 899 | 8.4s |  |
| 705 | `movieclip_displayevents` | 96 | 27.9s |  |
| 706 | `movieclip_displayevents_clickgoto` | 676 | 9.1s |  |
| 707 | `movieclip_displayevents_clickgoto2` | 2001 | 9.1s |  |
| 708 | `movieclip_displayevents_clickplay` | 575 | 8.7s |  |
| 709 | `movieclip_displayevents_clicksymbol` | 562 | 8.8s |  |
| 710 | `movieclip_displayevents_constructframegoto` | 140 | 9.0s |  |
| 711 | `movieclip_displayevents_constructframeplay` | 50 | 8.9s |  |
| 712 | `movieclip_displayevents_constructframesymbol` | 144 | 8.8s |  |
| 713 | `movieclip_displayevents_dblhandler` | 21 | 8.9s |  |
| 714 | `movieclip_displayevents_enterframegoto` | 149 | 9.1s |  |
| 715 | `movieclip_displayevents_enterframeplay` | 48 | 8.7s |  |
| 716 | `movieclip_displayevents_enterframesymbol` | 149 | 28.0s |  |
| 717 | `movieclip_displayevents_exitframegoto` | 106 | 8.6s |  |
| 718 | `movieclip_displayevents_exitframeplay` | 44 | 8.6s |  |
| 719 | `movieclip_displayevents_exitframesymbol` | 135 | 8.6s |  |
| 720 | `movieclip_displayevents_looping` | 63 | 27.9s |  |
| 721 | `movieclip_displayevents_stopped` | 113 | 8.8s |  |
| 722 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 723 | `movieclip_displayevents_timeline` | 128 | 8.7s |  |
| 724 | `movieclip_drawrect` | 54 | 7.0s |  |
| 725 | `movieclip_frameconstruct_skipped` | 9 | 6.8s |  |
| 726 | `movieclip_goto_during_frame_script` | 15 | 7.2s |  |
| 727 | `movieclip_goto_overwrite` | 14 | 23.2s |  |
| 728 | `movieclip_goto_scene_last_frame_int` | 1 | 23.5s |  |
| 729 | `movieclip_goto_scene_last_frame_label` | 1 | 2.7s |  |
| 730 | `movieclip_gotoandplay` | 15 | 23.4s |  |
| 731 | `movieclip_gotoandstop` | 13 | 7.0s |  |
| 732 | `movieclip_gotoandstop_children` | 4 | 7.4s |  |
| 733 | `movieclip_gotoandstop_framescripts1` | 4 | 7.0s |  |
| 734 | `movieclip_gotoandstop_framescripts2` | 4 | 2.7s |  |
| 735 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.8s |  |
| 736 | `movieclip_gotoandstop_queueing` | 12 | 23.3s |  |
| 737 | `movieclip_hittest` | 67 | 7.2s |  |
| 738 | `movieclip_next_frame` | 2 | 7.0s |  |
| 739 | `movieclip_next_scene` | 6 | 23.1s |  |
| 740 | `movieclip_play` | 3 | 2.7s |  |
| 741 | `movieclip_prev_frame` | 3 | 6.8s |  |
| 742 | `movieclip_prev_scene` | 7 | 7.0s |  |
| 743 | `movieclip_properties` | 79 | 7.2s |  |
| 744 | `movieclip_queued_noop_goto_swf10` | 9 | 6.9s |  |
| 745 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 746 | `movieclip_scenes` | 11 | 6.8s |  |
| 747 | `movieclip_soundtransform` | 831 | 24.3s |  |
| 748 | `movieclip_stop` | 1 | 7.2s |  |
| 749 | `movieclip_super_is_symbol` | 20 | 7.2s |  |
| 750 | `movieclip_symbol_constr` | 8 | 7.2s |  |
| 751 | `movieclip_text_mousedown` | 1 | 7.3s |  |
| 752 | `movieclip_willtrigger` | 5 | 7.3s |  |
| 753 | `multiply` | 1058 | 16.4s |  |
| 754 | `namespace_constr` | 253 | 7.5s |  |
| 755 | `namespace_constr_args` | 1 | 7.2s |  |
| 756 | `namespace_enumeration_order` | 7 | 7.5s |  |
| 757 | `nan_scale` | 9 | 7.2s |  |
| 758 | `native_menu_basic` | 19 | 9.2s |  |
| 759 | `navigateToURL_target_normalize` | 107 | 25.1s |  |
| 760 | `negate` | 30 | 7.1s |  |
| 761 | `negative_volume_panned` | 0 | 7.5s |  |
| 762 | `nested_iteration` | 11 | 7.0s |  |
| 763 | `net_getClassByAlias` | 3 | 7.0s |  |
| 764 | `net_navigateToURL` | 57 | 7.1s |  |
| 765 | `net_stream_play_options` | 6 | 7.1s |  |
| 766 | `netconnection_close` | 55 | 8.9s |  |
| 767 | `netconnection_properties` | 78 | 9.0s |  |
| 768 | `netconnection_send_remote` | 50 | 33.0s |  |
| 769 | `netconnection_serialize_arrays` | 6 | 8.9s |  |
| 770 | `netfilterevent` | 10 | 8.8s |  |
| 771 | `netstream_client` | 10 | 8.9s |  |
| 772 | `netstream_connect` | 7 | 8.8s |  |
| 773 | `netstream_flv_date` | 4 | 8.9s |  |
| 774 | `newactivation_in_script_init` | 3 | 8.6s |  |
| 775 | `newclass_mismatched` | 4 | 8.7s |  |
| 776 | `newclass_twice` | 3 | 8.8s |  |
| 777 | `nonconflicting_declarations` | 0 | 8.9s |  |
| 778 | `null_void_types` | 8 | 8.9s |  |
| 779 | `number_autoconv` | 21 | 3.5s |  |
| 780 | `number_autoconv_amf` | 132 | 8.9s |  |
| 781 | `number_autoconv_array_sort_32bit` | 1 | 8.7s |  |
| 782 | `number_constr` | 58 | 9.0s |  |
| 783 | `number_convert_edge_cases` | 180 | 28.6s |  |
| 784 | `number_toexponential` | 378 | 8.6s |  |
| 785 | `number_toexponential2` | 35 | 8.7s |  |
| 786 | `number_tofixed` | 378 | 8.5s |  |
| 787 | `number_toprecision` | 350 | 8.6s |  |
| 788 | `obfuscated_class_names` | 3 | 8.6s |  |
| 789 | `object_enumeration` | 10 | 8.8s |  |
| 790 | `object_prototype` | 4 | 8.9s |  |
| 791 | `object_to_locale_string` | 2 | 8.5s |  |
| 792 | `object_to_string` | 2 | 8.4s |  |
| 793 | `object_value_of` | 2 | 3.1s |  |
| 794 | `op_coerce` | 54 | 3.3s |  |
| 795 | `op_coerce_x` | 54 | 8.6s |  |
| 796 | `op_escxattr` | 2 | 8.5s |  |
| 797 | `op_escxelem` | 2 | 8.5s |  |
| 798 | `op_lookupswitch` | 4 | 8.5s |  |
| 799 | `optimize_coerce` | 1 | 8.4s |  |
| 800 | `orphan_movie_complex` | 80 | 9.1s |  |
| 801 | `orphan_movie_reorder` | 111 | 29.6s |  |
| 802 | `orphan_removeobject` | 636 | 21.1s |  |
| 803 | `package_namespace` | 7 | 5.9s |  |
| 804 | `param_default_value_has_zero_cpool_index` | 1 | 5.9s |  |
| 805 | `parent_early_access_child` | 16 | 5.9s |  |
| 806 | `parse_float` | 81 | 6.2s |  |
| 807 | `parse_float_swf10` | 81 | 6.3s |  |
| 808 | `parse_int` | 135 | 6.3s |  |
| 809 | `perspective_projection` | 1443 | 20.4s |  |
| 810 | `perspective_projection_basic` | 40 | 6.0s |  |
| 811 | `pixelbender_ceil` | 77 | 6.8s |  |
| 812 | `pixelbender_conditional` | 138 | 6.3s |  |
| 813 | `pixelbender_conversions` | 270 | 6.5s |  |
| 814 | `pixelbender_dithering` | 8 | 25.3s |  |
| 815 | `pixelbender_div` | 36 | 6.6s |  |
| 816 | `pixelbender_effect_BlurredFocus` | 0 | 26.1s |  |
| 817 | `pixelbender_effect_glassDisplace` | 0 | 10.6s |  |
| 818 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 23.6s |  |
| 819 | `pixelbender_effect_smudge` | 0 | 8.2s |  |
| 820 | `pixelbender_effect_tintype` | 0 | 7.6s |  |
| 821 | `pixelbender_effect_twirl` | 0 | 9.0s |  |
| 822 | `pixelbender_eof` | 7 | 5.9s |  |
| 823 | `pixelbender_images` | 0 | 7.5s |  |
| 824 | `pixelbender_input` | 103 | 20.3s |  |
| 825 | `pixelbender_logicalnot` | 20 | 5.8s |  |
| 826 | `pixelbender_malformed_data` | 190 | 20.4s |  |
| 827 | `pixelbender_multiple_out_params` | 1 | 2.0s |  |
| 828 | `pixelbender_no_out_param` | 6 | 5.7s |  |
| 829 | `pixelbender_outputs` | 13 | 5.8s |  |
| 830 | `pixelbender_padding_bytes` | 22 | 5.8s |  |
| 831 | `pixelbender_param_qualifier` | 512 | 5.8s |  |
| 832 | `pixelbender_parameters` | 1563 | 6.0s |  |
| 833 | `pixelbender_parameters_bool` | 240 | 5.9s |  |
| 834 | `pixelbender_parameters_int_vs_bool` | 54 | 5.8s |  |
| 835 | `pixelbender_parse_errors` | 6 | 5.8s |  |
| 836 | `pixelbender_rsqrt` | 24 | 5.8s |  |
| 837 | `pixelbender_select_kinds` | 8 | 5.9s |  |
| 838 | `pixelbender_shaderdata` | 49 | 5.7s |  |
| 839 | `pixelbender_shaderdata_setter` | 99 | 6.1s |  |
| 840 | `pixelbender_sign` | 60 | 5.9s |  |
| 841 | `pixelbender_vector_output` | 11 | 5.8s |  |
| 842 | `place_and_lookup/swf10` | 33 | 5.8s |  |
| 843 | `place_and_lookup/swf9` | 33 | 0.9s |  |
| 844 | `place_multiple` | 17 | 8.8s |  |
| 845 | `place_object_replace` | 9 | 28.5s |  |
| 846 | `place_object_replace_2` | 24 | 8.8s |  |
| 847 | `place_object_same_depth_frame` | 1 | 8.8s |  |
| 848 | `point` | 132 | 9.2s |  |
| 849 | `primitive_edge_cases` | 1 | 8.6s |  |
| 850 | `primitive_keys` | 54 | 8.8s |  |
| 851 | `primitive_toString` | 277 | 8.8s |  |
| 852 | `primitive_valueOf` | 285 | 8.6s |  |
| 853 | `print_job_options` | 3 | 8.7s |  |
| 854 | `property_is_enumerable` | 114 | 9.4s |  |
| 855 | `property_is_enumerable_reset` | 23 | 8.7s |  |
| 856 | `property_priority` | 22 | 9.0s |  |
| 857 | `property_priority_chained` | 4 | 8.6s |  |
| 858 | `property_priority_definition_names_order` | 2 | 8.9s |  |
| 859 | `property_priority_three_level` | 6 | 8.8s |  |
| 860 | `propertyisenumerable_namespaces` | 6 | 8.6s |  |
| 861 | `prototype_set_null` | 7 | 8.6s |  |
| 862 | `proxy_callproperty` | 24 | 8.7s |  |
| 863 | `proxy_deleteproperty` | 64 | 8.7s |  |
| 864 | `proxy_enumeration` | 34 | 8.7s |  |
| 865 | `proxy_getproperty` | 77 | 8.7s |  |
| 866 | `proxy_hasownproperty` | 8 | 8.7s |  |
| 867 | `proxy_hasproperty` | 32 | 8.7s |  |
| 868 | `proxy_not_overridden` | 54 | 8.7s |  |
| 869 | `proxy_serialize` | 9 | 8.7s |  |
| 870 | `proxy_setproperty` | 42 | 8.7s |  |
| 871 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.6s |  |
| 872 | `qname_constr` | 32 | 8.7s |  |
| 873 | `qname_constr_namespace` | 24 | 8.7s |  |
| 874 | `qname_enumeration` | 9 | 8.7s |  |
| 875 | `qname_indexing` | 23 | 8.7s |  |
| 876 | `qname_tostring` | 25 | 8.7s |  |
| 877 | `qname_valueof` | 29 | 8.7s |  |
| 878 | `rectangle` | 1094 | 9.3s |  |
| 879 | `regexp_constr` | 148 | 8.9s |  |
| 880 | `regexp_exec` | 19 | 8.7s |  |
| 881 | `regexp_extended` | 47 | 8.6s |  |
| 882 | `regexp_multiargs` | 1 | 8.6s |  |
| 883 | `regexp_test` | 27 | 3.4s |  |
| 884 | `regexp_toString` | 10 | 8.7s |  |
| 885 | `register_script_refresh` | 35 | 9.1s |  |
| 886 | `remove_child_clear_field` | 88 | 8.8s |  |
| 887 | `remove_dobj` | 3 | 8.4s |  |
| 888 | `resolve_order` | 4 | 8.4s |  |
| 889 | `responder_null_callbacks` | 1 | 8.4s |  |
| 890 | `rng` | 1 | 9.7s |  |
| 891 | `rootless` | 42 | 8.6s |  |
| 892 | `rshift` | 1058 | 20.8s |  |
| 893 | `rtqname_not_namespace` | 12 | 8.4s |  |
| 894 | `sandbox_type_inherited` | 2 | 8.9s |  |
| 895 | `sandbox_type_local_file` | 1 | 8.4s |  |
| 896 | `sandbox_type_local_network` | 1 | 8.4s |  |
| 897 | `scene_constr` | 8 | 8.4s |  |
| 898 | `scope_optimizations` | 4 | 8.3s |  |
| 899 | `scopes_dont_cache/order-1` | 1 | 27.8s |  |
| 900 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 901 | `security_domain_current` | 2 | 3.2s |  |
| 902 | `selection` | 239 | 9.4s |  |
| 903 | `set_local_0` | 31 | 8.4s |  |
| 904 | `set_property_is_enumerable` | 85 | 8.8s |  |
| 905 | `shaderparameter_value` | 4 | 8.5s |  |
| 906 | `shape_drawrect` | 54 | 8.5s |  |
| 907 | `shared_object_no_root` | 3 | 8.4s |  |
| 908 | `simplebutton_added_to_stage` | 45 | 28.0s |  |
| 909 | `simplebutton_childevents` | 86 | 28.1s |  |
| 910 | `simplebutton_childevents_nested` | 54 | 8.8s |  |
| 911 | `simplebutton_childevents_sprite` | 13 | 8.5s |  |
| 912 | `simplebutton_childprops` | 144 | 8.7s |  |
| 913 | `simplebutton_childshuffle` | 23 | 8.5s |  |
| 914 | `simplebutton_constr` | 36 | 8.7s |  |
| 915 | `simplebutton_constr_childevents` | 48 | 8.7s |  |
| 916 | `simplebutton_constr_params` | 42 | 8.6s |  |
| 917 | `simplebutton_mouseenabled` | 26 | 8.4s |  |
| 918 | `simplebutton_multi_children` | 19 | 8.7s |  |
| 919 | `simplebutton_soundtransform` | 887 | 30.1s |  |
| 920 | `simplebutton_structure` | 27 | 8.7s |  |
| 921 | `simplebutton_symbolclass` | 68 | 8.7s |  |
| 922 | `slot_disp_id_shared_numbering` | 1 | 27.9s |  |
| 923 | `slots_force_autoassigned` | 1 | 8.9s |  |
| 924 | `socket_after_disconnect` | 1 | 8.8s |  |
| 925 | `socket_close` | 2 | 8.6s |  |
| 926 | `socket_connect` | 4 | 8.7s |  |
| 927 | `socket_errors` | 56 | 9.2s |  |
| 928 | `socket_read_big` | 48 | 8.7s |  |
| 929 | `socket_read_little` | 48 | 3.2s |  |
| 930 | `socket_read_write_object` | 8 | 8.8s |  |
| 931 | `socket_write_big` | 15 | 9.1s |  |
| 932 | `socket_write_little` | 14 | 8.8s |  |
| 933 | `sound_constructor_with_args` | 6 | 8.9s |  |
| 934 | `sound_embeddedprops` | 26 | 8.8s |  |
| 935 | `sound_play` | 19 | 9.0s |  |
| 936 | `sound_rootless` | 7 | 9.0s |  |
| 937 | `sound_valueof` | 33 | 8.7s |  |
| 938 | `soundchannel_soundtransform` | 835 | 31.3s |  |
| 939 | `soundchannel_soundtransform_exists` | 5 | 27.9s |  |
| 940 | `soundchannel_stop` | 8 | 8.8s |  |
| 941 | `soundmixer_buffertime` | 5 | 8.6s |  |
| 942 | `soundmixer_soundtransform` | 900 | 10.6s |  |
| 943 | `soundmixer_stopall` | 6 | 8.6s |  |
| 944 | `soundtransform` | 442 | 9.0s |  |
| 945 | `space_justifier_clone` | 12 | 3.3s |  |
| 946 | `sprite_with_frames` | 0 | 32.6s |  |
| 947 | `stage3d_agal_cross_product` | 0 | 11.5s |  |
| 948 | `stage3d_agal_upload_errors` | 66 | 11.3s |  |
| 949 | `stage3d_bitmap` | 0 | 33.7s |  |
| 950 | `stage3d_blend` | 81 | 33.0s |  |
| 951 | `stage3d_context3d_string_args` | 158 | 9.5s |  |
| 952 | `stage3d_errors` | 7 | 8.7s |  |
| 953 | `stage3d_errors_atf` | 3 | 9.9s |  |
| 954 | `stage3d_errors_swf_29` | 6 | 8.6s |  |
| 955 | `stage3d_float1_index` | 0 | 30.5s |  |
| 956 | `stage3d_fractal` | 0 | 31.2s |  |
| 957 | `stage3d_ignore_sampler_override` | 0 | 30.7s |  |
| 958 | `stage3d_multistage_triangle` | 3 | 11.4s |  |
| 959 | `stage3d_program_constants_bytearray_be` | 0 | 32.9s |  |
| 960 | `stage3d_program_constants_bytearray_le` | 0 | 27.6s |  |
| 961 | `stage3d_program_constants_invalid_input` | 21 | 8.4s |  |
| 962 | `stage3d_raytrace` | 0 | 27.8s |  |
| 963 | `stage3d_rotating_cube` | 0 | 9.5s |  |
| 964 | `stage3d_sampler` | 0 | 8.9s |  |
| 965 | `stage3d_sampler_partial_upload` | 0 | 8.9s |  |
| 966 | `stage3d_stencil` | 0 | 25.0s |  |
| 967 | `stage3d_texture` | 0 | 13.1s |  |
| 968 | `stage3d_texture_bytearray` | 0 | 9.9s |  |
| 969 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.4s |  |
| 970 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.2s |  |
| 971 | `stage3d_triangle` | 0 | 8.9s |  |
| 972 | `stage3d_triangle_bytes4` | 0 | 8.9s |  |
| 973 | `stage3d_triangle_float1` | 0 | 8.8s |  |
| 974 | `stage3d_triangle_index_upload` | 0 | 8.9s |  |
| 975 | `stage3d_x_y` | 22 | 6.8s |  |
| 976 | `stage_access` | 10 | 2.7s |  |
| 977 | `stage_display_state` | 6 | 6.8s |  |
| 978 | `stage_displayobject_properties` | 24 | 6.7s |  |
| 979 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.8s |  |
| 980 | `stage_framerate_nan` | 7 | 2.8s |  |
| 981 | `stage_framerate_negative` | 6 | 6.9s |  |
| 982 | `stage_framerate_zero` | 6 | 6.9s |  |
| 983 | `stage_invalidate` | 38 | 6.9s |  |
| 984 | `stage_loaderinfo_properties` | 24 | 22.2s |  |
| 985 | `stage_mousechildren` | 2 | 6.7s |  |
| 986 | `stage_mouseenabled` | 15 | 6.7s |  |
| 987 | `stage_overriden_setters` | 31 | 6.8s |  |
| 988 | `stage_properties` | 30 | 6.7s |  |
| 989 | `stage_properties2` | 213 | 6.8s |  |
| 990 | `stage_scale_factor` | 12 | 26.0s |  |
| 991 | `stage_stage3Ds_vector` | 1 | 6.7s |  |
| 992 | `static_length` | 24 | 6.8s |  |
| 993 | `static_text` | 3 | 7.3s |  |
| 994 | `static_var_with_this_in_ctor` | 2 | 6.7s |  |
| 995 | `statictext_text` | 8 | 6.8s |  |
| 996 | `stored_properties` | 11 | 6.8s |  |
| 997 | `strict_equality` | 34 | 6.8s |  |
| 998 | `string_call` | 13 | 6.8s |  |
| 999 | `string_case` | 23 | 6.8s |  |
| 1000 | `string_char_at` | 27 | 6.8s |  |
| 1001 | `string_char_code_at` | 28 | 6.7s |  |
| 1002 | `string_concat_fromcharcode` | 37 | 8.8s |  |
| 1003 | `string_constr` | 25 | 8.7s |  |
| 1004 | `string_indexof_lastindexof` | 87 | 8.9s |  |
| 1005 | `string_length` | 16 | 8.6s |  |
| 1006 | `string_locale_compare` | 39 | 8.9s |  |
| 1007 | `string_match` | 51 | 8.9s |  |
| 1008 | `string_relational_compare` | 4 | 8.6s |  |
| 1009 | `string_replace` | 51 | 8.8s |  |
| 1010 | `string_search` | 41 | 8.8s |  |
| 1011 | `string_slice_substr_substring` | 170 | 9.7s |  |
| 1012 | `string_split` | 29 | 8.8s |  |
| 1013 | `string_substr_negative` | 21 | 8.6s |  |
| 1014 | `string_substr_weird` | 182 | 8.6s |  |
| 1015 | `stylesheet` | 221 | 9.2s |  |
| 1016 | `stylesheet_parse_color` | 69 | 8.7s |  |
| 1017 | `stylesheet_transform` | 307 | 9.0s |  |
| 1018 | `sub_super_same_field` | 12 | 3.4s |  |
| 1019 | `subclass_superclass_linked_symbol` | 4 | 9.2s |  |
| 1020 | `subtract` | 1058 | 19.9s |  |
| 1021 | `super_get_call` | 12 | 8.7s |  |
| 1022 | `supercall_two_classobjects` | 2 | 8.7s |  |
| 1023 | `supercalls_coerce` | 8 | 8.7s |  |
| 1024 | `supercalls_weird` | 2 | 8.6s |  |
| 1025 | `superinterface_call` | 20 | 8.7s |  |
| 1026 | `superinterface_instanceof` | 18 | 8.8s |  |
| 1027 | `swf8` | 1 | 8.6s |  |
| 1028 | `swf_10_queued_goto_scripts_construct` | 52 | 9.1s |  |
| 1029 | `swf_9_goto_in_enter_frame` | 17 | 8.8s |  |
| 1030 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.8s |  |
| 1031 | `swf_9_queued_goto_scripts` | 6 | 8.7s |  |
| 1032 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 1033 | `swf_9_versioning` | 2 | 8.6s |  |
| 1034 | `swf_wrong_frame_count` | 38 | 9.1s |  |
| 1035 | `swf_wrong_frame_count_isplaying` | 22 | 8.7s |  |
| 1036 | `symbol_class_binary_data` | 8 | 8.7s |  |
| 1037 | `symbol_class_conflict` | 4 | 12.6s |  |
| 1038 | `symbol_class_root_not_zero` | 1 | 8.6s |  |
| 1039 | `symbolclass_invalid_utf8` | 2 | 8.7s |  |
| 1040 | `system_exit` | 3 | 8.6s |  |
| 1041 | `system_setclipboard_null` | 1 | 8.6s |  |
| 1042 | `tab_ordering_arrows` | 998 | 29.8s |  |
| 1043 | `tab_ordering_automatic_advanced` | 184 | 9.2s |  |
| 1044 | `tab_ordering_automatic_basic` | 45 | 8.7s |  |
| 1045 | `tab_ordering_children` | 116 | 8.7s |  |
| 1046 | `tab_ordering_custom_basic` | 34 | 8.5s |  |
| 1047 | `tab_ordering_stage_tab_children` | 32 | 8.6s |  |
| 1048 | `tab_ordering_stage_tab_children_remove_root` | 5 | 8.5s |  |
| 1049 | `tab_ordering_tabbable` | 47 | 8.7s |  |
| 1050 | `tabstop_properties` | 105 | 8.9s |  |
| 1051 | `text_element_basic` | 34 | 8.7s |  |
| 1052 | `text_engine_fontdescription` | 27 | 8.8s |  |
| 1053 | `text_engine_groupelement` | 64 | 9.5s |  |
| 1054 | `text_run` | 7 | 8.5s |  |
| 1055 | `textblock_createline_errors` | 23 | 8.8s |  |
| 1056 | `textblock_createline_fte` | 9 | 29.1s |  |
| 1057 | `textblock_properties` | 118 | 9.0s |  |
| 1058 | `textbox_click` | 37 | 29.0s |  |
| 1059 | `textfield_event` | 66 | 9.0s |  |
| 1060 | `textfield_focusin_event` | 9 | 8.5s |  |
| 1061 | `textfield_input_dead_keys_windows` | 15 | 8.6s |  |
| 1062 | `textfield_input_events` | 25 | 21.7s |  |
| 1063 | `textfield_unload` | 39 | 28.4s |  |
| 1064 | `textformat` | 1134 | 8.6s |  |
| 1065 | `textformat_display` | 14 | 8.6s |  |
| 1066 | `textformat_font_max_length` | 4 | 3.2s |  |
| 1067 | `textline_inapplicable_properties` | 10 | 8.6s |  |
| 1068 | `textline_name` | 1 | 8.5s |  |
| 1069 | `textline_raw_text_length` | 30 | 8.6s |  |
| 1070 | `textline_splitting_basic` | 76 | 8.8s |  |
| 1071 | `textline_throwerror` | 30 | 8.6s |  |
| 1072 | `textline_validity` | 162 | 8.7s |  |
| 1073 | `throw` | 3 | 8.6s |  |
| 1074 | `timeline_scripts` | 3 | 8.7s |  |
| 1075 | `timer` | 90 | 9.7s |  |
| 1076 | `timer_events` | 3 | 8.7s |  |
| 1077 | `timer_finished` | 11 | 3.5s |  |
| 1078 | `timer_invalid_delay` | 30 | 8.5s |  |
| 1079 | `timer_reset` | 8 | 1.4s |  |
| 1080 | `timer_setdelay` | 5 | 1.4s |  |
| 1081 | `trace` | 12 | 1.1s |  |
| 1082 | `truthiness` | 30 | 1.1s |  |
| 1083 | `try_catch` | 11 | 1.1s |  |
| 1084 | `try_catch_typed` | 12 | 1.1s |  |
| 1085 | `typeof` | 30 | 1.1s |  |
| 1086 | `uint_constr` | 92 | 1.1s |  |
| 1087 | `uint_tofixed` | 1215 | 1.1s |  |
| 1088 | `uint_toprecision` | 1125 | 1.1s |  |
| 1089 | `uint_tostring` | 3375 | 1.1s |  |
| 1090 | `uncaught_error_basic` | 2 | 1.1s |  |
| 1091 | `unchecked_function` | 15 | 1.1s |  |
| 1092 | `unescape` | 28 | 1.1s |  |
| 1093 | `url_loader` | 25 | 1.1s |  |
| 1094 | `url_vars` | 27 | 1.1s |  |
| 1095 | `urlrequest` | 18 | 1.1s |  |
| 1096 | `urlstream_basic` | 5 | 1.1s |  |
| 1097 | `urshift` | 1058 | 1.2s |  |
| 1098 | `utils3d` | 7 | 1.1s |  |
| 1099 | `vector3d` | 397 | 1.1s |  |
| 1100 | `vector3d_near_equals` | 80 | 1.1s |  |
| 1101 | `vector_class` | 36 | 1.1s |  |
| 1102 | `vector_class_call` | 11 | 1.1s |  |
| 1103 | `vector_coercion` | 66 | 1.1s |  |
| 1104 | `vector_concat` | 90 | 1.1s |  |
| 1105 | `vector_constr` | 107 | 1.1s |  |
| 1106 | `vector_enumeration` | 5 | 1.1s |  |
| 1107 | `vector_every` | 92 | 1.1s |  |
| 1108 | `vector_filter` | 95 | 1.1s |  |
| 1109 | `vector_holes` | 24 | 1.1s |  |
| 1110 | `vector_indexof` | 302 | 1.1s |  |
| 1111 | `vector_insertat` | 270 | 1.1s |  |
| 1112 | `vector_int_access` | 4 | 1.1s |  |
| 1113 | `vector_int_delete` | 11 | 1.1s |  |
| 1114 | `vector_join` | 58 | 1.1s |  |
| 1115 | `vector_lastindexof` | 302 | 1.1s |  |
| 1116 | `vector_legacy` | 10 | 1.1s |  |
| 1117 | `vector_map` | 85 | 1.1s |  |
| 1118 | `vector_object_final` | 1 | 1.1s |  |
| 1119 | `vector_object_toString` | 10 | 6.0s |  |
| 1120 | `vector_pushpop` | 255 | 6.9s |  |
| 1121 | `vector_reborrow_bug` | 10 | 6.6s |  |
| 1122 | `vector_removeat` | 172 | 6.8s |  |
| 1123 | `vector_reverse` | 232 | 6.8s |  |
| 1124 | `vector_shiftunshift` | 252 | 5.9s |  |
| 1125 | `vector_slice` | 331 | 7.0s |  |
| 1126 | `vector_sort` | 905 | 12.2s |  |
| 1127 | `vector_splice` | 693 | 8.4s |  |
| 1128 | `vector_splice_fixed_bug_compat` | 4 | 6.0s |  |
| 1129 | `vector_tostring` | 79 | 6.5s |  |
| 1130 | `verification` | 8 | 6.3s |  |
| 1131 | `verify_abnormal_loop` | 1 | 6.1s |  |
| 1132 | `verify_dxns_without_flag` | 3 | 6.5s |  |
| 1133 | `verify_exception_target_two_jumps` | 1 | 6.2s |  |
| 1134 | `verify_exception_targets_edge_case` | 1 | 5.9s |  |
| 1135 | `verify_illegal_opcode` | 1 | 2.4s |  |
| 1136 | `verify_jump_to_middle_of_op` | 1 | 6.2s |  |
| 1137 | `verify_lookup_switch_edge_case` | 1 | 6.0s |  |
| 1138 | `verify_method_info_oob` | 1 | 1.0s |  |
| 1139 | `verify_stack` | 5 | 6.1s |  |
| 1140 | `verify_typecheck` | 4 | 2.2s |  |
| 1141 | `verify_unreachable_exception` | 2 | 5.9s |  |
| 1142 | `versioned_isplaying` | 2 | 6.0s |  |
| 1143 | `virtual_properties` | 16 | 6.1s |  |
| 1144 | `with` | 4 | 6.0s |  |
| 1145 | `wrong_arg_count` | 7 | 6.2s |  |
| 1146 | `xml_abstract_equality` | 36 | 6.1s |  |
| 1147 | `xml_advanced` | 52 | 6.5s |  |
| 1148 | `xml_appendchild` | 10 | 6.0s |  |
| 1149 | `xml_appendchild_swf_v21` | 13 | 2.3s |  |
| 1150 | `xml_as_attribute` | 9 | 5.9s |  |
| 1151 | `xml_attribute` | 35 | 6.2s |  |
| 1152 | `xml_attribute_name` | 40 | 5.9s |  |
| 1153 | `xml_basic` | 33 | 6.1s |  |
| 1154 | `xml_child` | 25 | 6.2s |  |
| 1155 | `xml_childindex` | 7 | 6.0s |  |
| 1156 | `xml_children` | 43 | 6.7s |  |
| 1157 | `xml_class_call` | 9 | 6.1s |  |
| 1158 | `xml_contains` | 197 | 6.4s |  |
| 1159 | `xml_copy` | 20 | 8.3s |  |
| 1160 | `xml_ctor_from_tostring` | 23 | 8.5s |  |
| 1161 | `xml_delete` | 114 | 8.4s |  |
| 1162 | `xml_descendants` | 83 | 8.3s |  |
| 1163 | `xml_duplicate_attribute` | 14 | 8.3s |  |
| 1164 | `xml_elements` | 6 | 8.3s |  |
| 1165 | `xml_equals_namespace_check` | 2 | 8.4s |  |
| 1166 | `xml_explicit_use_namespace` | 5 | 8.4s |  |
| 1167 | `xml_getdescendants_qname` | 21 | 8.4s |  |
| 1168 | `xml_has_property_via_in` | 26 | 8.4s |  |
| 1169 | `xml_hasownproperty` | 6 | 8.4s |  |
| 1170 | `xml_ignore_white` | 6 | 8.5s |  |
| 1171 | `xml_length` | 2 | 8.5s |  |
| 1172 | `xml_list_as_attribute` | 9 | 8.4s |  |
| 1173 | `xml_list_concat` | 20 | 8.6s |  |
| 1174 | `xml_list_ctor_errors` | 34 | 8.7s |  |
| 1175 | `xml_list_delete_clear_parent` | 6 | 8.9s |  |
| 1176 | `xml_list_enumerate` | 4 | 8.7s |  |
| 1177 | `xml_methods_settings` | 3 | 8.9s |  |
| 1178 | `xml_mismatched_tag` | 37 | 8.7s |  |
| 1179 | `xml_namespace` | 39 | 3.3s |  |
| 1180 | `xml_namespace_methods` | 245 | 8.5s |  |
| 1181 | `xml_namespaced_property` | 7 | 8.6s |  |
| 1182 | `xml_no_namespace` | 1 | 8.6s |  |
| 1183 | `xml_nodekind` | 3 | 8.5s |  |
| 1184 | `xml_normalize` | 35 | 8.6s |  |
| 1185 | `xml_notification_bubbling` | 361 | 8.5s |  |
| 1186 | `xml_parent` | 8 | 8.5s |  |
| 1187 | `xml_set_children` | 17 | 8.8s |  |
| 1188 | `xml_set_name` | 34 | 8.6s |  |
| 1189 | `xml_settings` | 6 | 3.2s |  |
| 1190 | `xml_simple_complex_content` | 47 | 8.5s |  |
| 1191 | `xml_socket` | 11 | 8.8s |  |
| 1192 | `xml_text` | 7 | 8.5s |  |
| 1193 | `xml_tostring` | 6 | 8.5s |  |
| 1194 | `xml_tostring_namespace` | 12 | 8.4s |  |
| 1195 | `xml_unescaping` | 23 | 8.4s |  |
| 1196 | `xml_weird_ignores` | 54 | 8.5s |  |
| 1197 | `xml_wildcard` | 11 | 8.4s |  |
| 1198 | `xmldocument` | 254 | 9.0s |  |
| 1199 | `xmlnode` | 3540 | 8.9s |  |
| 1200 | `zero_frame_clip` | 3 | 9.3s |  |

## Ruffle-Matched Tests

**35 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 6.7s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.9s |  |
| 3 | `blend_transform` | 1 | 1 | 7.1s |  |
| 4 | `bounds_mode` | 6 | 6 | 8.6s |  |
| 5 | `coerce_property` | 3 | 3 | 8.8s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 8.8s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 7.0s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 27.8s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 7.4s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.4s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 7.3s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 8.6s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 8.6s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 8.6s |  |
| 15 | `event_handler_exception` | 4 | 4 | 8.7s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 5.6s |  |
| 17 | `goto_framescript_queued` | 5 | 5 | 18.3s |  |
| 18 | `graphics_draw_path` | 50 | 50 | 23.2s |  |
| 19 | `groupelement_text` | 2 | 2 | 7.0s |  |
| 20 | `int_toexponential` | 76 | 76 | 8.3s |  |
| 21 | `matrix3d_append_rotation` | 1 | 3 | 6.9s |  |
| 22 | `matrix3d_recompose_edge_cases` | 85 | 85 | 7.1s |  |
| 23 | `number_convert_errors` | 706 | 706 | 8.9s |  |
| 24 | `simplebutton_childevents_script_order` | 4 | 4 | 8.6s |  |
| 25 | `slot_holes_fail` | 1 | 1 | 8.5s |  |
| 26 | `slot_id_exceeds_trait_count` | 1 | 1 | 8.6s |  |
| 27 | `soundchannel_position` | 74 | 74 | 29.0s |  |
| 28 | `soundchannel_soundcomplete` | 10 | 10 | 9.1s |  |
| 29 | `sprite_dropTarget` | 15 | 15 | 8.6s |  |
| 30 | `swf_9_goto_in_construct_frame` | 12 | 12 | 28.3s |  |
| 31 | `textblock_line_changes` | 44 | 44 | 9.3s |  |
| 32 | `textblock_releaselines` | 4 | 4 | 10.5s |  |
| 33 | `uint_toexponential` | 100 | 100 | 1.1s |  |
| 34 | `uncaught_errors_stringified` | 15 | 15 | 1.1s |  |
| 35 | `weird_superinterface_properties` | 1 | 1 | 6.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**13 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `geom_transform` | 95.9% | 71 | 74 | 3 |  |
| 3 | `bitmapdata_copypixels_self` | 93.3% | 571 | 612 | 41 |  |
| 4 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 5 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 6 | `displayobject_getrect` | 68.8% | 11 | 16 | 5 |  |
| 7 | `number_to_string` | 67.1% | 237 | 353 | 116 |  |
| 8 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 9 | `bytearray_bad_symbol_class_other_movie` | 66.7% | 4 | 6 | 2 |  |
| 10 | `bitmapdata_copypixels_alpha_merge` | 55.6% | 5 | 9 | 4 |  |
| 11 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 12 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 13 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**37 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `geom_transform` | 95.9% | 71/74 | 74 | 74 |  |
| 3 | `bitmapdata_copypixels_self` | 93.3% | 571/612 | 612 | 612 |  |
| 4 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 5 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 6 | `displayobject_getrect` | 68.8% | 11/16 | 16 | 16 |  |
| 7 | `number_to_string` | 67.1% | 237/353 | 353 | 353 |  |
| 8 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 9 | `bytearray_bad_symbol_class_other_movie` | 66.7% | 4/6 | 5 | 6 |  |
| 10 | `bitmapdata_copypixels_alpha_merge` | 55.6% | 5/9 | 9 | 9 |  |
| 11 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 12 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 13 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 14 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 15 | `bytearray_bad_symbol_class` | 33.3% | 1/3 | 2 | 3 |  |
| 16 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 17 | `json_parse_numbers` | 23.7% | 31/131 | 118 | 131 |  |
| 18 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 19 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 20 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 21 | `displayobject_z` | 15.8% | 6/38 | 11 | 38 |  |
| 22 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 23 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 24 | `loader_events_2` | 5.7% | 2/35 | 31 | 35 |  |
| 25 | `edittext_scroll_event` | 5.4% | 2/37 | 7 | 37 |  |
| 26 | `json_parse_errors` | 4.8% | 4/84 | 64 | 84 |  |
| 27 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 28 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 29 | `bitmap_filter_abstract` | 0.0% | 0/6 | 4 | 6 |  |
| 30 | `bitmapdata_copypixels_blend` | 0.0% | 0/1049 | 1049 | 1029 |  |
| 31 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 32 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 33 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 34 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 35 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 36 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 37 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
