# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-17 00:25 UTC

**Git SHA**: `2973513c45`

**Run Duration**: 218m 25s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1275 |
| Passing | **1213** (95.1%) |
| Ruffle-matched | 35 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1248** (97.9%) |
| Failing | 27 |
| Total expected lines | 157157 |
| Matching lines | 154268 (98.2%) |
| Mismatched lines | 2889 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 27 | 100.0% |

## Passing Tests

**1213 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 22.7s |  |
| 2 | `accessibility` | 1 | 8.8s |  |
| 3 | `accessibilityimplementation` | 18 | 8.8s |  |
| 4 | `activation_class` | 6 | 8.8s |  |
| 5 | `add` | 1058 | 19.2s |  |
| 6 | `agal_compiler` | 13 | 11.7s |  |
| 7 | `air_datagram_socket` | 1 | 10.9s |  |
| 8 | `air_hidden_lookup` | 2 | 8.8s |  |
| 9 | `air_ifilepromise` | 1 | 8.7s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 8.9s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.4s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.4s |  |
| 13 | `all_classes/display/swf10` | 2569 | 8.9s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.5s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.4s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.5s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.4s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.4s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 8.8s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.4s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.4s |  |
| 22 | `all_classes/errors/swf10` | 140 | 8.8s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.4s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.4s |  |
| 25 | `all_classes/events/swf10` | 1638 | 8.9s |  |
| 26 | `all_classes/events/swf11` | 1750 | 1.4s |  |
| 27 | `all_classes/events/swf12` | 1814 | 1.4s |  |
| 28 | `all_classes/events/swf30` | 2353 | 1.4s |  |
| 29 | `all_classes/events/swf9` | 1030 | 1.4s |  |
| 30 | `all_classes/security/swf11` | 3 | 8.8s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.4s |  |
| 32 | `all_classes/security/swf13` | 53 | 1.4s |  |
| 33 | `all_classes/security/swf30` | 53 | 1.4s |  |
| 34 | `all_classes/xml/swf30` | 116 | 8.8s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.3s |  |
| 36 | `amf_array_serialization` | 17 | 31.1s |  |
| 37 | `amf_custom_obj` | 26 | 8.9s |  |
| 38 | `amf_dictionary` | 9 | 8.8s |  |
| 39 | `amf_function` | 46 | 8.8s |  |
| 40 | `amf_invalid_date` | 2 | 8.7s |  |
| 41 | `amf_missing_prop` | 6 | 8.8s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 8.8s |  |
| 43 | `amf_setter_error` | 8 | 8.9s |  |
| 44 | `amf_vector` | 40 | 22.4s |  |
| 45 | `amf_xml` | 6 | 8.7s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 9.3s |  |
| 47 | `application_domain` | 4 | 8.7s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 8.8s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 8.7s |  |
| 50 | `array_access` | 18 | 8.8s |  |
| 51 | `array_access_interpreter` | 4 | 8.8s |  |
| 52 | `array_access_no_pubns` | 2 | 8.7s |  |
| 53 | `array_concat` | 41 | 8.8s |  |
| 54 | `array_constr` | 10 | 8.7s |  |
| 55 | `array_delete` | 44 | 8.9s |  |
| 56 | `array_enumeration` | 10 | 8.8s |  |
| 57 | `array_enumeration_elements` | 11 | 8.8s |  |
| 58 | `array_every` | 8 | 8.7s |  |
| 59 | `array_filter` | 6 | 8.7s |  |
| 60 | `array_foreach` | 18 | 8.7s |  |
| 61 | `array_hasownproperty` | 11 | 8.7s |  |
| 62 | `array_holes` | 9 | 8.7s |  |
| 63 | `array_index_max` | 84 | 8.6s |  |
| 64 | `array_indexof` | 25 | 8.7s |  |
| 65 | `array_join` | 26 | 8.8s |  |
| 66 | `array_lastindexof` | 29 | 8.8s |  |
| 67 | `array_length` | 14 | 8.7s |  |
| 68 | `array_literal` | 3 | 8.7s |  |
| 69 | `array_map` | 8 | 8.6s |  |
| 70 | `array_pop` | 52 | 8.9s |  |
| 71 | `array_push` | 24 | 8.7s |  |
| 72 | `array_reborrow_bug` | 6 | 8.7s |  |
| 73 | `array_reverse` | 28 | 8.7s |  |
| 74 | `array_shift` | 51 | 3.5s |  |
| 75 | `array_slice` | 39 | 8.8s |  |
| 76 | `array_some` | 8 | 8.7s |  |
| 77 | `array_sort` | 297 | 9.5s |  |
| 78 | `array_sort_fun_swf12` | 2 | 8.7s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 80 | `array_sort_random` | 210 | 8.7s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 8.7s |  |
| 82 | `array_sorton` | 545 | 9.9s |  |
| 83 | `array_sparse_ops` | 41 | 9.0s |  |
| 84 | `array_splice` | 133 | 9.0s |  |
| 85 | `array_splice2` | 428 | 22.4s |  |
| 86 | `array_splice_types` | 48 | 8.8s |  |
| 87 | `array_storage` | 8 | 8.6s |  |
| 88 | `array_tolocalestring` | 9 | 8.5s |  |
| 89 | `array_tostring` | 12 | 8.6s |  |
| 90 | `array_unshift` | 24 | 8.6s |  |
| 91 | `array_valueof` | 9 | 8.4s |  |
| 92 | `array_vector_null_callback` | 10 | 8.7s |  |
| 93 | `astype` | 28 | 8.8s |  |
| 94 | `astypelate` | 24 | 8.8s |  |
| 95 | `astypelate_propagates` | 1 | 8.5s |  |
| 96 | `asymmetric_key_events` | 11 | 9.0s |  |
| 97 | `automation_classes` | 122 | 9.2s |  |
| 98 | `av_classes` | 340 | 8.9s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 8.8s |  |
| 100 | `avm2_catchup_dobj` | 158 | 9.8s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 108.9s |  |
| 102 | `bevel_filter` | 187 | 9.0s |  |
| 103 | `bitand` | 1058 | 20.0s |  |
| 104 | `bitmap_constr` | 17 | 9.0s |  |
| 105 | `bitmap_data` | 1000 | 19.6s |  |
| 106 | `bitmap_filter_abstract` | 6 | 8.6s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 29.1s |  |
| 108 | `bitmap_properties` | 23 | 8.7s |  |
| 109 | `bitmap_subclass` | 7 | 10.6s |  |
| 110 | `bitmap_subclass_properties` | 9 | 9.1s |  |
| 111 | `bitmap_timeline` | 9 | 9.0s |  |
| 112 | `bitmapdata_accuracy` | 1 | 47.2s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 29.4s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.8s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 29.1s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 29.0s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 28.5s |  |
| 118 | `bitmapdata_clone` | 13 | 8.8s |  |
| 119 | `bitmapdata_colortransform` | 0 | 9.1s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 8.6s |  |
| 121 | `bitmapdata_constr` | 22 | 8.7s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 9.0s |  |
| 123 | `bitmapdata_copychannel` | 0 | 30.9s |  |
| 124 | `bitmapdata_copypixels` | 23 | 29.9s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 9.0s |  |
| 126 | `bitmapdata_copypixels_alpha_merge` | 9 | 23.3s |  |
| 127 | `bitmapdata_copypixels_blend` | 1029 | 9.6s |  |
| 128 | `bitmapdata_copypixels_blend_over` | 1 | 9.3s |  |
| 129 | `bitmapdata_copypixels_self` | 612 | 9.2s |  |
| 130 | `bitmapdata_copypixelstobytearray` | 39 | 9.1s |  |
| 131 | `bitmapdata_dispose` | 7 | 9.2s |  |
| 132 | `bitmapdata_draw` | 0 | 31.8s |  |
| 133 | `bitmapdata_draw_alpha_erase` | 8 | 9.3s |  |
| 134 | `bitmapdata_draw_cab_quality` | 0 | 32.1s |  |
| 135 | `bitmapdata_draw_colortransform` | 0 | 9.4s |  |
| 136 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 31.0s |  |
| 137 | `bitmapdata_draw_filters` | 0 | 30.4s |  |
| 138 | `bitmapdata_draw_masks` | 0 | 9.6s |  |
| 139 | `bitmapdata_draw_rotation` | 0 | 9.4s |  |
| 140 | `bitmapdata_draw_self_via_graphic` | 0 | 9.2s |  |
| 141 | `bitmapdata_draw_stage` | 0 | 30.5s |  |
| 142 | `bitmapdata_drawwithquality` | 0 | 9.9s |  |
| 143 | `bitmapdata_embedded` | 9 | 9.5s |  |
| 144 | `bitmapdata_fillrect` | 0 | 9.3s |  |
| 145 | `bitmapdata_filter_sourcerect` | 0 | 30.5s |  |
| 146 | `bitmapdata_floodfill` | 35 | 9.0s |  |
| 147 | `bitmapdata_getpixels` | 39 | 30.7s |  |
| 148 | `bitmapdata_getvector` | 27 | 3.5s |  |
| 149 | `bitmapdata_histogram` | 59 | 3.5s |  |
| 150 | `bitmapdata_hittest` | 112 | 9.9s |  |
| 151 | `bitmapdata_hittest_threshold` | 18 | 9.2s |  |
| 152 | `bitmapdata_opaque` | 0 | 9.3s |  |
| 153 | `bitmapdata_pixeldissolve` | 1037 | 9.9s |  |
| 154 | `bitmapdata_pixeldissolve_image` | 0 | 9.6s |  |
| 155 | `bitmapdata_rectangle_rounding` | 16 | 8.9s |  |
| 156 | `bitmapdata_setpixels` | 286 | 9.2s |  |
| 157 | `bitmapdata_setvector` | 26 | 9.4s |  |
| 158 | `bitmapdata_sync` | 0 | 30.4s |  |
| 159 | `bitmapdata_threshold` | 176 | 9.7s |  |
| 160 | `bitmapdata_zero_size` | 8 | 9.1s |  |
| 161 | `bitnot` | 46 | 9.0s |  |
| 162 | `bitor` | 1058 | 20.8s |  |
| 163 | `bitxor` | 1058 | 20.6s |  |
| 164 | `blend_mode_null` | 1 | 9.0s |  |
| 165 | `blend_multiply_alpha` | 0 | 9.2s |  |
| 166 | `blend_scroll` | 0 | 9.2s |  |
| 167 | `blend_shader_luma_lighten` | 3 | 9.8s |  |
| 168 | `blur_filter` | 43 | 7.1s |  |
| 169 | `boolean_constr` | 32 | 6.9s |  |
| 170 | `boolean_negation` | 30 | 6.8s |  |
| 171 | `boolean_tostring` | 8 | 6.8s |  |
| 172 | `broadcast_event` | 7 | 6.9s |  |
| 173 | `button_bounds` | 1 | 6.8s |  |
| 174 | `button_hittest` | 2 | 23.2s |  |
| 175 | `button_nested_frame` | 48 | 23.6s |  |
| 176 | `button_nested_frame_simple` | 27 | 7.1s |  |
| 177 | `bytearray` | 48 | 7.0s |  |
| 178 | `bytearray_bad_symbol_class` | 3 | 6.8s |  |
| 179 | `bytearray_bad_symbol_class_other_movie` | 6 | 7.2s |  |
| 180 | `bytearray_compress` | 31 | 6.8s |  |
| 181 | `bytearray_errors` | 24 | 7.0s |  |
| 182 | `bytearray_method_serialization` | 1 | 6.8s |  |
| 183 | `bytearray_oom` | 3 | 6.8s |  |
| 184 | `bytearray_readobject_amf0` | 50 | 6.8s |  |
| 185 | `bytearray_readobject_amf3` | 53 | 6.8s |  |
| 186 | `bytearray_readutf8bytes_with_bom` | 16 | 6.8s |  |
| 187 | `bytearray_serialization` | 3 | 6.8s |  |
| 188 | `bytearray_string_null` | 19 | 7.0s |  |
| 189 | `bytearray_tostring` | 15 | 6.8s |  |
| 190 | `bytearray_utf16` | 8 | 6.8s |  |
| 191 | `bytearray_writeobject` | 24 | 6.7s |  |
| 192 | `callee_in_initializer` | 6 | 6.7s |  |
| 193 | `callproplex_class` | 1 | 6.8s |  |
| 194 | `capabilities_resolution` | 8 | 24.3s |  |
| 195 | `catch_class` | 6 | 6.8s |  |
| 196 | `catch_scope_slot` | 7 | 6.9s |  |
| 197 | `checkfilter` | 4 | 2.3s |  |
| 198 | `class_call` | 32 | 7.0s |  |
| 199 | `class_cast_call` | 14 | 6.8s |  |
| 200 | `class_enumeration` | 4 | 6.8s |  |
| 201 | `class_has_own_property` | 2 | 6.8s |  |
| 202 | `class_init_interpreter_mode` | 1 | 6.7s |  |
| 203 | `class_is` | 32 | 6.9s |  |
| 204 | `class_methods` | 5 | 6.8s |  |
| 205 | `class_object_properties` | 10 | 6.8s |  |
| 206 | `class_singleton` | 18 | 6.9s |  |
| 207 | `class_supercalls_errors` | 35 | 7.0s |  |
| 208 | `class_supercalls_mismatched` | 26 | 6.9s |  |
| 209 | `class_superclass_wrong_order` | 1 | 8.6s |  |
| 210 | `class_to_locale_string` | 2 | 8.5s |  |
| 211 | `class_to_string` | 2 | 8.4s |  |
| 212 | `class_value_of` | 2 | 8.5s |  |
| 213 | `click_block` | 5 | 29.1s |  |
| 214 | `click_invisible` | 3 | 8.9s |  |
| 215 | `closures` | 12 | 8.6s |  |
| 216 | `coerce_return_type` | 40 | 8.8s |  |
| 217 | `coerce_return_type_fail` | 2 | 8.6s |  |
| 218 | `coerce_return_void` | 3 | 8.6s |  |
| 219 | `coerce_string` | 86 | 8.7s |  |
| 220 | `coerce_string_precision` | 28 | 8.6s |  |
| 221 | `coerce_to_primitive_side_effects` | 29 | 8.7s |  |
| 222 | `color_matrix_filter` | 19 | 8.7s |  |
| 223 | `construct_errors_swf10` | 8 | 8.7s |  |
| 224 | `construct_frame_list` | 22 | 28.5s |  |
| 225 | `construct_interface` | 3 | 8.6s |  |
| 226 | `constructor_call` | 3 | 8.5s |  |
| 227 | `constructors_vs_timeline` | 5 | 28.4s |  |
| 228 | `constructprop_dynamic_primitive` | 7 | 8.7s |  |
| 229 | `constructprop_method` | 2 | 8.6s |  |
| 230 | `constructsuper_null` | 2 | 3.2s |  |
| 231 | `content_element_basic` | 50 | 9.0s |  |
| 232 | `context3d_creation` | 9 | 8.6s |  |
| 233 | `control_flow_bool` | 4 | 8.6s |  |
| 234 | `control_flow_stricteq` | 8 | 8.7s |  |
| 235 | `convert_boolean` | 30 | 8.6s |  |
| 236 | `convert_integer` | 90 | 8.7s |  |
| 237 | `convert_number` | 56 | 8.6s |  |
| 238 | `convert_uinteger` | 90 | 8.7s |  |
| 239 | `convolution_filter` | 89 | 8.8s |  |
| 240 | `core_exceptions` | 47 | 10.2s |  |
| 241 | `cpool_index_invalid_bytecode_1` | 6 | 8.7s |  |
| 242 | `cpool_index_invalid_bytecode_2` | 3 | 8.7s |  |
| 243 | `cpool_index_invalid_bytecode_3` | 1 | 8.7s |  |
| 244 | `cross_api_version_call_newer` | 12 | 9.3s |  |
| 245 | `cross_api_version_call_older` | 12 | 9.0s |  |
| 246 | `cryptscore` | 11 | 8.7s |  |
| 247 | `currency_parse_result` | 7 | 8.6s |  |
| 248 | `date` | 30 | 9.2s |  |
| 249 | `date_parse` | 36 | 8.5s |  |
| 250 | `declocal` | 46 | 6.2s |  |
| 251 | `declocal_i` | 46 | 5.9s |  |
| 252 | `decode_uri` | 71 | 6.4s |  |
| 253 | `decrement` | 46 | 6.1s |  |
| 254 | `decrement_i` | 46 | 2.1s |  |
| 255 | `default_values` | 7 | 6.0s |  |
| 256 | `delayed_symbolclass` | 28 | 6.1s |  |
| 257 | `describe_type_basic` | 152 | 6.2s |  |
| 258 | `describe_type_json` | 301 | 6.3s |  |
| 259 | `describe_type_metadata` | 125 | 6.1s |  |
| 260 | `describe_type_native` | 23 | 6.5s |  |
| 261 | `dictionary_access` | 62 | 6.2s |  |
| 262 | `dictionary_access_no_pubns` | 2 | 6.5s |  |
| 263 | `dictionary_delete` | 101 | 6.6s |  |
| 264 | `dictionary_foreach` | 42 | 6.2s |  |
| 265 | `dictionary_hasownproperty` | 63 | 6.3s |  |
| 266 | `dictionary_in` | 62 | 6.3s |  |
| 267 | `dictionary_iter_modify` | 8 | 6.2s |  |
| 268 | `dictionary_namespaces` | 36 | 6.1s |  |
| 269 | `displacement_map_filter` | 61 | 6.2s |  |
| 270 | `displayobject_alpha` | 277 | 6.7s |  |
| 271 | `displayobject_blendmode` | 0 | 21.2s |  |
| 272 | `displayobject_colortransform_nested` | 0 | 21.5s |  |
| 273 | `displayobject_early_init` | 54 | 7.5s |  |
| 274 | `displayobject_filters` | 17 | 6.2s |  |
| 275 | `displayobject_from_enterframe` | 1 | 20.7s |  |
| 276 | `displayobject_getbounds_shape` | 0 | 21.1s |  |
| 277 | `displayobject_getrect` | 16 | 6.3s |  |
| 278 | `displayobject_height` | 6052 | 21.0s |  |
| 279 | `displayobject_hittestobject` | 32 | 6.3s |  |
| 280 | `displayobject_hittestpoint` | 49 | 6.3s |  |
| 281 | `displayobject_hittestpoint_boundary` | 65 | 21.5s |  |
| 282 | `displayobject_hittestpoint_root` | 13 | 6.3s |  |
| 283 | `displayobject_invalid_floats` | 60 | 6.2s |  |
| 284 | `displayobject_invalid_props` | 3 | 6.0s |  |
| 285 | `displayobject_mask` | 3 | 6.5s |  |
| 286 | `displayobject_mask_self_referential` | 0 | 6.1s |  |
| 287 | `displayobject_metaData` | 3 | 6.0s |  |
| 288 | `displayobject_name` | 22 | 6.5s |  |
| 289 | `displayobject_name_from_timeline` | 24 | 6.2s |  |
| 290 | `displayobject_opaque_background` | 6 | 6.2s |  |
| 291 | `displayobject_parent` | 12 | 6.0s |  |
| 292 | `displayobject_root` | 24 | 6.0s |  |
| 293 | `displayobject_rotation` | 1284 | 6.6s |  |
| 294 | `displayobject_scrollrect` | 33 | 7.1s |  |
| 295 | `displayobject_set_matrix_nested` | 0 | 21.0s |  |
| 296 | `displayobject_set_name_loaded` | 3 | 6.5s |  |
| 297 | `displayobject_subclass` | 2 | 6.3s |  |
| 298 | `displayobject_transform` | 89 | 6.2s |  |
| 299 | `displayobject_visible` | 23 | 6.3s |  |
| 300 | `displayobject_width` | 4852 | 19.6s |  |
| 301 | `displayobject_x` | 614 | 5.9s |  |
| 302 | `displayobject_y` | 617 | 6.1s |  |
| 303 | `displayobject_z` | 38 | 19.9s |  |
| 304 | `displayobjectcontainer_addchild` | 32 | 6.7s |  |
| 305 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.7s |  |
| 306 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.8s |  |
| 307 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.0s |  |
| 308 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.9s |  |
| 309 | `displayobjectcontainer_addchildat` | 42 | 5.6s |  |
| 310 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.8s |  |
| 311 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.8s |  |
| 312 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.7s |  |
| 313 | `displayobjectcontainer_contains` | 66 | 6.1s |  |
| 314 | `displayobjectcontainer_getchildat` | 4 | 5.8s |  |
| 315 | `displayobjectcontainer_getchildbyname` | 9 | 5.6s |  |
| 316 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.6s |  |
| 317 | `displayobjectcontainer_getchildindex` | 28 | 5.8s |  |
| 318 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 5.7s |  |
| 319 | `displayobjectcontainer_removechild` | 10 | 5.7s |  |
| 320 | `displayobjectcontainer_removechild_errors` | 4 | 5.5s |  |
| 321 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.0s |  |
| 322 | `displayobjectcontainer_removechildat` | 18 | 5.4s |  |
| 323 | `displayobjectcontainer_removechildren` | 51 | 5.7s |  |
| 324 | `displayobjectcontainer_setchildindex` | 42 | 5.5s |  |
| 325 | `displayobjectcontainer_stopallmovieclips` | 2 | 19.6s |  |
| 326 | `displayobjectcontainer_swapchildren` | 42 | 6.6s |  |
| 327 | `displayobjectcontainer_swapchildrenat` | 42 | 5.8s |  |
| 328 | `displayobjectcontainer_timelineinstance` | 48 | 19.5s |  |
| 329 | `divide` | 1058 | 12.3s |  |
| 330 | `doabc_and_symbolclass_script_init_goto` | 7 | 18.9s |  |
| 331 | `doabc_and_symbolclass_script_init_normal` | 6 | 5.9s |  |
| 332 | `doabc_is_eager` | 1 | 19.5s |  |
| 333 | `documentclass` | 9 | 6.2s |  |
| 334 | `domain_memory` | 133 | 7.0s |  |
| 335 | `drag_drop` | 10 | 6.3s |  |
| 336 | `drop_shadow_filter` | 172 | 6.4s |  |
| 337 | `duplicate_defs` | 1 | 6.3s |  |
| 338 | `eager_init` | 1 | 6.0s |  |
| 339 | `east_asian_justifier_clone` | 8 | 6.4s |  |
| 340 | `edit_text_linkage` | 7 | 6.7s |  |
| 341 | `edittext_align` | 60 | 6.6s |  |
| 342 | `edittext_always_show_selection` | 0 | 21.9s |  |
| 343 | `edittext_antialiastype` | 296 | 6.9s |  |
| 344 | `edittext_at_point_methods_basic` | 16 | 7.3s |  |
| 345 | `edittext_autosize` | 39 | 6.5s |  |
| 346 | `edittext_autosize_align` | 0 | 20.7s |  |
| 347 | `edittext_autosize_height_dynamic` | 60 | 21.0s |  |
| 348 | `edittext_autosize_height_input` | 60 | 6.5s |  |
| 349 | `edittext_autosize_lazy_bounds_events` | 65 | 6.3s |  |
| 350 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.3s |  |
| 351 | `edittext_autosize_lazy_bounds_props` | 490 | 7.7s |  |
| 352 | `edittext_autosize_lazy_bounds_visual` | 0 | 21.5s |  |
| 353 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.6s |  |
| 354 | `edittext_bottom_scroll_v_basic` | 210 | 6.4s |  |
| 355 | `edittext_bounds_scale` | 24 | 6.1s |  |
| 356 | `edittext_bullet` | 30 | 6.0s |  |
| 357 | `edittext_default_format` | 221 | 6.6s |  |
| 358 | `edittext_default_format_empty` | 136 | 6.6s |  |
| 359 | `edittext_empty_text_format` | 7 | 6.6s |  |
| 360 | `edittext_focus_selection` | 5 | 6.8s |  |
| 361 | `edittext_font_size` | 45 | 6.2s |  |
| 362 | `edittext_format_empty_font` | 8 | 6.1s |  |
| 363 | `edittext_get_char_index_at_point` | 4 | 22.6s |  |
| 364 | `edittext_get_line_index_at_point` | 2 | 6.2s |  |
| 365 | `edittext_get_line_index_of_char` | 76 | 7.1s |  |
| 366 | `edittext_getcharboundaries` | 172 | 6.3s |  |
| 367 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.6s |  |
| 368 | `edittext_getcharboundaries_scroll` | 85 | 6.5s |  |
| 369 | `edittext_getlinemetrics` | 146 | 6.4s |  |
| 370 | `edittext_html` | 3101 | 6.6s |  |
| 371 | `edittext_html_condensewhite` | 487 | 6.2s |  |
| 372 | `edittext_html_entity` | 4 | 6.1s |  |
| 373 | `edittext_html_font_size_swf12` | 267 | 7.7s |  |
| 374 | `edittext_html_font_size_swf13` | 273 | 7.3s |  |
| 375 | `edittext_html_roundtrip` | 17 | 8.9s |  |
| 376 | `edittext_ime_focus_lost` | 9 | 7.9s |  |
| 377 | `edittext_input_control` | 12 | 8.1s |  |
| 378 | `edittext_leading` | 9 | 8.3s |  |
| 379 | `edittext_letter_spacing` | 15 | 8.2s |  |
| 380 | `edittext_line_methods` | 294 | 8.9s |  |
| 381 | `edittext_line_metrics` | 11 | 26.4s |  |
| 382 | `edittext_margins` | 25 | 7.3s |  |
| 383 | `edittext_max_scroll_h_basic` | 475 | 7.2s |  |
| 384 | `edittext_max_scroll_v_basic` | 1000 | 7.2s |  |
| 385 | `edittext_mouse_selection` | 363 | 25.3s |  |
| 386 | `edittext_mousedown` | 3 | 7.8s |  |
| 387 | `edittext_mouseenabled` | 26 | 7.4s |  |
| 388 | `edittext_newline_character` | 22 | 7.3s |  |
| 389 | `edittext_newline_stripping` | 64 | 9.5s |  |
| 390 | `edittext_newlines` | 30 | 7.8s |  |
| 391 | `edittext_paragraph_methods` | 257 | 7.3s |  |
| 392 | `edittext_paste_events` | 8 | 7.5s |  |
| 393 | `edittext_paste_maxchars` | 4 | 7.1s |  |
| 394 | `edittext_paste_restrict` | 16 | 7.6s |  |
| 395 | `edittext_restrict` | 191 | 7.2s |  |
| 396 | `edittext_restrict_events` | 22 | 7.4s |  |
| 397 | `edittext_scroll_event` | 37 | 7.8s |  |
| 398 | `edittext_scrollh` | 10 | 7.3s |  |
| 399 | `edittext_selected_text` | 9 | 7.4s |  |
| 400 | `edittext_set_html_same` | 17 | 7.2s |  |
| 401 | `edittext_set_text_vs_html` | 9 | 7.1s |  |
| 402 | `edittext_stylesheet` | 536 | 7.6s |  |
| 403 | `edittext_stylesheet_custom_tag` | 76 | 7.3s |  |
| 404 | `edittext_stylesheet_display` | 272 | 7.7s |  |
| 405 | `edittext_tag_indent` | 49 | 24.9s |  |
| 406 | `edittext_underline` | 40 | 7.7s |  |
| 407 | `edittext_width_height` | 103 | 7.9s |  |
| 408 | `edittext_wordwrap_word` | 150 | 7.7s |  |
| 409 | `edittext_wrap_breaks` | 2375 | 8.3s |  |
| 410 | `element_format_clone` | 44 | 7.6s |  |
| 411 | `element_format_constructor_order` | 64 | 3.0s |  |
| 412 | `element_format_properties` | 235 | 8.4s |  |
| 413 | `empty_bounds` | 1 | 7.1s |  |
| 414 | `encode_uri_surrogate_pair_invalid` | 8 | 7.4s |  |
| 415 | `encode_uri_surrogate_pair_swf11` | 15 | 8.3s |  |
| 416 | `equals` | 512 | 13.0s |  |
| 417 | `error_geterrormessage` | 779 | 8.6s |  |
| 418 | `error_prototype` | 15 | 8.7s |  |
| 419 | `error_stack_trace` | 45 | 8.6s |  |
| 420 | `error_stack_trace_debug_swf17` | 0 | 28.1s |  |
| 421 | `error_stack_trace_debug_swf18` | 0 | 8.3s |  |
| 422 | `error_stack_trace_edge_cases` | 6 | 8.6s |  |
| 423 | `error_stack_trace_release_swf17` | 0 | 3.2s |  |
| 424 | `error_stack_trace_release_swf18` | 0 | 8.3s |  |
| 425 | `error_throwerror` | 103 | 8.6s |  |
| 426 | `error_tostring` | 29 | 8.6s |  |
| 427 | `error_tostring_more` | 86 | 8.7s |  |
| 428 | `es3_inheritance` | 31 | 8.7s |  |
| 429 | `es4_inheritance` | 30 | 8.6s |  |
| 430 | `es4_interfaces` | 30 | 8.6s |  |
| 431 | `es4_method_binding` | 8 | 8.6s |  |
| 432 | `es4_oop_prototypes` | 14 | 8.8s |  |
| 433 | `es4_protected_inheritance` | 6 | 8.7s |  |
| 434 | `escape` | 71 | 8.7s |  |
| 435 | `escape_multi_byte` | 45 | 8.9s |  |
| 436 | `event_bubbles` | 2 | 8.5s |  |
| 437 | `event_cancelable` | 2 | 8.4s |  |
| 438 | `event_clone` | 20 | 8.6s |  |
| 439 | `event_clone_error_redispatch` | 3 | 8.7s |  |
| 440 | `event_clone_on_redispatch` | 10 | 8.8s |  |
| 441 | `event_formattostring` | 31 | 8.7s |  |
| 442 | `event_isdefaultprevented` | 12 | 8.6s |  |
| 443 | `event_target_getter` | 5 | 3.3s |  |
| 444 | `event_target_set` | 9 | 8.5s |  |
| 445 | `event_type` | 1 | 8.9s |  |
| 446 | `event_valueof_tostring` | 18 | 8.8s |  |
| 447 | `eventdispatcher_dispatchevent` | 12 | 8.9s |  |
| 448 | `eventdispatcher_dispatchevent_cancel` | 20 | 8.7s |  |
| 449 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 8.6s |  |
| 450 | `eventdispatcher_dispatchevent_indirect` | 9 | 8.7s |  |
| 451 | `eventdispatcher_dispatchevent_this` | 5 | 8.6s |  |
| 452 | `eventdispatcher_haseventlistener` | 25 | 8.5s |  |
| 453 | `eventdispatcher_interface_invoke` | 1 | 8.5s |  |
| 454 | `eventdispatcher_tostring` | 10 | 8.5s |  |
| 455 | `eventdispatcher_willtrigger` | 25 | 6.9s |  |
| 456 | `falsiness` | 30 | 6.8s |  |
| 457 | `fast_index_access` | 12 | 6.9s |  |
| 458 | `filefilter_properties` | 4 | 6.8s |  |
| 459 | `filereference_browse_cancel` | 3 | 6.8s |  |
| 460 | `filereference_browse_select` | 9 | 6.8s |  |
| 461 | `filereference_load` | 31 | 6.9s |  |
| 462 | `filereference_save` | 16 | 6.9s |  |
| 463 | `filereference_save_and_browse` | 42 | 6.9s |  |
| 464 | `filereference_save_and_load` | 22 | 6.9s |  |
| 465 | `filereference_uninitialized` | 8 | 6.8s |  |
| 466 | `filereferencelist_browse_cancel` | 6 | 6.8s |  |
| 467 | `filereferencelist_browse_select` | 7 | 6.8s |  |
| 468 | `filter_rewind` | 8 | 23.4s |  |
| 469 | `filters_array_holes` | 25 | 6.8s |  |
| 470 | `finddef` | 3 | 6.8s |  |
| 471 | `findprop_global_prototype` | 6 | 6.8s |  |
| 472 | `flash_media_video_constructor` | 156 | 7.5s |  |
| 473 | `flash_media_video_rotation_probe` | 27 | 6.9s |  |
| 474 | `flash_media_video_setter` | 40 | 7.2s |  |
| 475 | `flash_trace` | 17 | 6.9s |  |
| 476 | `flash_ui_mouse_cursor` | 35 | 7.2s |  |
| 477 | `flash_xml` | 29 | 6.9s |  |
| 478 | `flash_xml_cloneNode` | 22 | 6.9s |  |
| 479 | `flash_xml_namespace` | 109 | 6.8s |  |
| 480 | `flash_xml_removeNode` | 60 | 6.8s |  |
| 481 | `focus_events_code` | 161 | 23.6s |  |
| 482 | `focus_events_key_basic` | 132 | 23.6s |  |
| 483 | `focus_events_key_navigation` | 53 | 23.4s |  |
| 484 | `focus_events_key_same_object` | 26 | 6.9s |  |
| 485 | `focus_events_mixed_key_mouse` | 100 | 23.4s |  |
| 486 | `focus_events_mouse_basic` | 260 | 23.4s |  |
| 487 | `focus_events_mouse_focusable` | 112 | 23.5s |  |
| 488 | `focus_events_mouse_same_object` | 40 | 6.9s |  |
| 489 | `focus_remove` | 20 | 23.3s |  |
| 490 | `focus_root_movie` | 4 | 23.3s |  |
| 491 | `focus_stage` | 1 | 6.8s |  |
| 492 | `focusrect` | 18 | 7.5s |  |
| 493 | `focusrect_focuslost` | 9 | 6.9s |  |
| 494 | `focusrect_property` | 110 | 2.3s |  |
| 495 | `font_description_clone` | 14 | 6.8s |  |
| 496 | `font_embedded` | 24 | 9.2s |  |
| 497 | `font_enumeratefonts` | 41 | 9.4s |  |
| 498 | `font_enumeratefonts_filter` | 4 | 9.4s |  |
| 499 | `font_enumeratefonts_order` | 9 | 10.2s |  |
| 500 | `font_hasglyphs` | 40 | 9.1s |  |
| 501 | `font_registerfont` | 129 | 9.8s |  |
| 502 | `framelabel_constr` | 5 | 8.8s |  |
| 503 | `function_call` | 12 | 3.5s |  |
| 504 | `function_call_arguments` | 46 | 9.2s |  |
| 505 | `function_call_arguments_enumerate` | 5 | 8.9s |  |
| 506 | `function_call_coercion` | 108 | 9.3s |  |
| 507 | `function_call_default` | 6 | 8.9s |  |
| 508 | `function_call_rest` | 22 | 8.9s |  |
| 509 | `function_call_types` | 3 | 8.8s |  |
| 510 | `function_call_via_apply` | 11 | 8.8s |  |
| 511 | `function_call_via_call` | 3 | 8.8s |  |
| 512 | `function_display_anonymous` | 7 | 3.4s |  |
| 513 | `function_length` | 6 | 9.0s |  |
| 514 | `function_object` | 2 | 9.0s |  |
| 515 | `function_proto` | 5 | 8.9s |  |
| 516 | `function_proto_created` | 61 | 9.1s |  |
| 517 | `function_to_locale_string` | 4 | 9.0s |  |
| 518 | `function_to_string` | 4 | 8.8s |  |
| 519 | `function_type` | 6 | 9.0s |  |
| 520 | `function_unbound_this` | 51 | 9.1s |  |
| 521 | `function_value_of` | 4 | 8.9s |  |
| 522 | `game_input` | 4 | 8.9s |  |
| 523 | `generate_random_bytes` | 3 | 8.9s |  |
| 524 | `geom_transform` | 74 | 30.6s |  |
| 525 | `get_definition_by_name` | 11 | 8.8s |  |
| 526 | `get_qualified_class_name` | 20 | 8.9s |  |
| 527 | `get_qualified_super_class_name` | 18 | 8.7s |  |
| 528 | `get_slot_edge_cases` | 1 | 8.5s |  |
| 529 | `get_timer` | 2 | 3.2s |  |
| 530 | `getglobalslot` | 1 | 8.5s |  |
| 531 | `getouterscope` | 8 | 8.5s |  |
| 532 | `getouterscope_two_classobjects` | 13 | 8.6s |  |
| 533 | `getter_different_namespace_setter` | 2 | 8.4s |  |
| 534 | `glow_filter` | 127 | 9.0s |  |
| 535 | `goto_button_nested_framescript` | 28 | 28.5s |  |
| 536 | `goto_in_constructframe` | 12 | 9.5s |  |
| 537 | `goto_in_scene_last_frame` | 2 | 28.9s |  |
| 538 | `goto_methods` | 56 | 9.3s |  |
| 539 | `goto_methods_swfver10` | 8 | 9.0s |  |
| 540 | `goto_nested_construct_sibling` | 18 | 9.6s |  |
| 541 | `goto_nested_framescript` | 9 | 9.1s |  |
| 542 | `goto_on_orphan` | 15 | 28.7s |  |
| 543 | `gradient_bevel_filter` | 206 | 9.1s |  |
| 544 | `gradient_glow_filter` | 206 | 8.8s |  |
| 545 | `graphic_linkage` | 9 | 9.1s |  |
| 546 | `graphics_bad_direct_commands` | 5 | 10.1s |  |
| 547 | `graphics_bitmap_fill` | 0 | 11.6s |  |
| 548 | `graphics_bitmaps` | 0 | 9.6s |  |
| 549 | `graphics_direct_commands` | 0 | 9.7s |  |
| 550 | `graphics_draw_triangles` | 98 | 29.8s |  |
| 551 | `graphics_gradients` | 0 | 9.3s |  |
| 552 | `graphics_gradients_nulls` | 0 | 9.2s |  |
| 553 | `graphics_path` | 56 | 9.0s |  |
| 554 | `graphics_round_rects` | 0 | 9.1s |  |
| 555 | `graphics_simple_shapes` | 0 | 9.2s |  |
| 556 | `greaterequals` | 512 | 13.1s |  |
| 557 | `greaterthan` | 512 | 13.2s |  |
| 558 | `has_own_property` | 102 | 9.8s |  |
| 559 | `hasownproperty_namespaces` | 2 | 9.1s |  |
| 560 | `hello_world` | 1 | 9.1s |  |
| 561 | `hittest_morph` | 30 | 9.3s |  |
| 562 | `id3_info` | 8 | 29.9s |  |
| 563 | `if_eq` | 10 | 9.2s |  |
| 564 | `if_gt` | 1 | 9.2s |  |
| 565 | `if_gte` | 10 | 3.6s |  |
| 566 | `if_lt` | 1 | 1.4s |  |
| 567 | `if_lte` | 10 | 9.2s |  |
| 568 | `if_ne` | 7 | 3.6s |  |
| 569 | `if_stricteq` | 6 | 9.2s |  |
| 570 | `if_strictne` | 11 | 9.1s |  |
| 571 | `ime_linux_dead_keys` | 10 | 9.2s |  |
| 572 | `in` | 102 | 9.8s |  |
| 573 | `inclocal` | 46 | 9.2s |  |
| 574 | `inclocal_i` | 46 | 9.1s |  |
| 575 | `increment` | 46 | 7.7s |  |
| 576 | `increment_i` | 46 | 7.9s |  |
| 577 | `indexing_delete` | 75 | 8.0s |  |
| 578 | `indexof_xml` | 10 | 8.3s |  |
| 579 | `init_callee_cached` | 24 | 8.2s |  |
| 580 | `instanceof` | 58 | 8.3s |  |
| 581 | `instantiate_root_character` | 4 | 8.3s |  |
| 582 | `instantiation_on_enter_frame` | 7 | 27.0s |  |
| 583 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.9s |  |
| 584 | `int_constr` | 92 | 8.2s |  |
| 585 | `int_edge_cases` | 19 | 7.9s |  |
| 586 | `int_instanceof` | 3 | 7.4s |  |
| 587 | `int_tofixed` | 1215 | 7.9s |  |
| 588 | `int_toprecision` | 1125 | 7.8s |  |
| 589 | `int_tostring` | 3375 | 8.0s |  |
| 590 | `interactiveobject_enabled` | 25 | 7.2s |  |
| 591 | `interface_namespaces` | 78 | 7.8s |  |
| 592 | `invalid_utf8` | 12 | 7.5s |  |
| 593 | `is_finite` | 46 | 7.8s |  |
| 594 | `is_nan` | 46 | 7.5s |  |
| 595 | `is_prototype_of` | 12 | 7.3s |  |
| 596 | `issue_10221` | 2 | 7.1s |  |
| 597 | `issue_13780` | 12 | 7.3s |  |
| 598 | `issue_14901` | 1 | 7.3s |  |
| 599 | `issue_17675_edittext_paste_maxchars` | 1 | 7.2s |  |
| 600 | `issue_5292` | 5 | 7.3s |  |
| 601 | `issue_8630` | 2 | 7.3s |  |
| 602 | `issue_8630_placeremoveplace` | 15 | 7.3s |  |
| 603 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.8s |  |
| 604 | `issue_8630_scriptremove` | 11 | 7.9s |  |
| 605 | `istype` | 24 | 2.8s |  |
| 606 | `istypelate` | 58 | 8.0s |  |
| 607 | `istypelate_coerce` | 198 | 8.7s |  |
| 608 | `jpeg_loader_context` | 6 | 7.6s |  |
| 609 | `json_errors` | 9 | 27.0s |  |
| 610 | `json_parse` | 21 | 7.8s |  |
| 611 | `json_parse_errors` | 84 | 8.1s |  |
| 612 | `json_stringify` | 12 | 8.1s |  |
| 613 | `json_stringify_function` | 12 | 8.0s |  |
| 614 | `json_stringify_order` | 1 | 7.9s |  |
| 615 | `json_version_gated` | 1 | 8.1s |  |
| 616 | `key_input_80percent` | 1812 | 17.5s |  |
| 617 | `key_input_location` | 126 | 7.0s |  |
| 618 | `key_input_numpad` | 384 | 6.8s |  |
| 619 | `large_preload_from_bytes` | 51 | 9.8s |  |
| 620 | `large_preload_from_url` | 27 | 8.7s |  |
| 621 | `large_preload_image_from_bytes` | 25 | 7.4s |  |
| 622 | `lazyinit` | 17 | 7.0s |  |
| 623 | `lessequals` | 512 | 10.0s |  |
| 624 | `lessthan` | 512 | 10.0s |  |
| 625 | `loader_bitmap_transparency` | 14 | 7.0s |  |
| 626 | `loader_bytes_unknown_content` | 14 | 7.0s |  |
| 627 | `loader_child_getdefinition` | 5 | 7.1s |  |
| 628 | `loader_duplicate_class` | 48 | 8.7s |  |
| 629 | `loader_duplicate_coerce` | 3 | 7.1s |  |
| 630 | `loader_duplicate_coerce_new_domain` | 4 | 6.9s |  |
| 631 | `loader_error_in_root_ctor` | 4 | 7.0s |  |
| 632 | `loader_events` | 92 | 7.7s |  |
| 633 | `loader_image` | 8 | 7.2s |  |
| 634 | `loader_jpegxr` | 2 | 22.4s |  |
| 635 | `loader_jpegxr_alpha` | 1 | 6.9s |  |
| 636 | `loader_loadbytes_events` | 30 | 7.5s |  |
| 637 | `loader_loadbytes_invalid_png` | 4 | 6.9s |  |
| 638 | `loader_loadbytes_url` | 12 | 7.2s |  |
| 639 | `loader_loaderurl` | 6 | 7.3s |  |
| 640 | `loader_method` | 85 | 6.9s |  |
| 641 | `loader_noninteractive_try_click_root` | 5 | 22.6s |  |
| 642 | `loader_reuse` | 38 | 7.1s |  |
| 643 | `loader_try_click_root` | 16 | 7.1s |  |
| 644 | `loader_unknown_content` | 24 | 7.0s |  |
| 645 | `loader_visibility_interactive` | 1 | 6.9s |  |
| 646 | `loaderinfo_events` | 7 | 6.8s |  |
| 647 | `loaderinfo_loadurl` | 12 | 6.9s |  |
| 648 | `loaderinfo_more` | 6 | 7.0s |  |
| 649 | `loaderinfo_properties` | 18 | 22.2s |  |
| 650 | `loaderinfo_properties_not_loaded` | 23 | 6.9s |  |
| 651 | `loaderinfo_quine` | 1005 | 6.8s |  |
| 652 | `loaderinfo_root` | 10 | 6.9s |  |
| 653 | `loaderinfo_root_allows` | 2 | 6.8s |  |
| 654 | `localconnection` | 890 | 8.9s |  |
| 655 | `localconnection_send` | 4 | 22.1s |  |
| 656 | `lshift` | 1058 | 20.1s |  |
| 657 | `mask_reapply` | 1 | 28.8s |  |
| 658 | `math` | 497 | 9.0s |  |
| 659 | `matrix` | 338 | 20.9s |  |
| 660 | `matrix3d` | 57 | 9.6s |  |
| 661 | `matrix3d_append` | 16 | 8.8s |  |
| 662 | `matrix3d_append_prepend_scale` | 86 | 8.8s |  |
| 663 | `matrix3d_append_prepend_translation` | 42 | 8.7s |  |
| 664 | `matrix3d_append_rotation` | 23 | 8.7s |  |
| 665 | `matrix3d_compose` | 34 | 8.9s |  |
| 666 | `matrix3d_constructor_clone` | 15 | 8.6s |  |
| 667 | `matrix3d_copy_column` | 83 | 8.9s |  |
| 668 | `matrix3d_copy_from` | 19 | 8.7s |  |
| 669 | `matrix3d_copy_raw_data_from` | 55 | 3.5s |  |
| 670 | `matrix3d_copy_raw_data_to` | 38 | 8.9s |  |
| 671 | `matrix3d_copy_row` | 83 | 8.5s |  |
| 672 | `matrix3d_copy_to_matrix3d` | 19 | 8.7s |  |
| 673 | `matrix3d_determinant` | 182 | 9.0s |  |
| 674 | `matrix3d_interpolate` | 21 | 8.9s |  |
| 675 | `matrix3d_invert` | 18 | 8.7s |  |
| 676 | `matrix3d_position` | 19 | 8.8s |  |
| 677 | `matrix3d_precision` | 28 | 8.9s |  |
| 678 | `matrix3d_prepend` | 16 | 8.5s |  |
| 679 | `matrix3d_raw_data` | 33 | 8.8s |  |
| 680 | `matrix3d_transform_vector` | 52 | 9.1s |  |
| 681 | `matrix3d_transpose` | 5 | 8.6s |  |
| 682 | `method_association` | 5 | 8.7s |  |
| 683 | `method_without_body` | 3 | 28.3s |  |
| 684 | `missing_external_interface` | 10 | 8.7s |  |
| 685 | `modulo` | 1058 | 20.0s |  |
| 686 | `morph_shape` | 2 | 28.3s |  |
| 687 | `mouse_children` | 192 | 29.0s |  |
| 688 | `mouse_click_events` | 90 | 28.4s |  |
| 689 | `mouse_double_click_events` | 188 | 8.8s |  |
| 690 | `mouse_empty_parent` | 4 | 8.7s |  |
| 691 | `mouse_over_while_dragging` | 3 | 8.9s |  |
| 692 | `mouse_pick_avm1_root` | 2 | 28.9s |  |
| 693 | `mouse_pick_button_mode` | 2 | 8.8s |  |
| 694 | `mouse_pick_dobj_mask` | 4 | 9.2s |  |
| 695 | `mouse_pick_masking` | 7 | 42.4s |  |
| 696 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 28.8s |  |
| 697 | `mouse_pick_non_interactive_dobj_mask` | 3 | 9.3s |  |
| 698 | `mouse_pick_text` | 8 | 9.0s |  |
| 699 | `mouse_sibling` | 8 | 8.9s |  |
| 700 | `mouse_wheel_events` | 36 | 29.7s |  |
| 701 | `mouseevent_constr` | 66 | 9.0s |  |
| 702 | `mouseevent_stagexy` | 35 | 8.9s |  |
| 703 | `mouseevent_valueof_tostring` | 28 | 8.8s |  |
| 704 | `movieclip_addframescript` | 3 | 28.7s |  |
| 705 | `movieclip_addframescript_error` | 9 | 8.8s |  |
| 706 | `movieclip_child_property` | 16 | 8.9s |  |
| 707 | `movieclip_constr` | 21 | 8.8s |  |
| 708 | `movieclip_currentlabels` | 17 | 28.6s |  |
| 709 | `movieclip_currentlabels_dupes1` | 46 | 28.7s |  |
| 710 | `movieclip_currentlabels_dupes2` | 30 | 8.9s |  |
| 711 | `movieclip_currentlabels_dupes3` | 67 | 8.9s |  |
| 712 | `movieclip_currentscene` | 12 | 8.8s |  |
| 713 | `movieclip_dispatchevent` | 430 | 9.0s |  |
| 714 | `movieclip_dispatchevent_cancel` | 102 | 9.0s |  |
| 715 | `movieclip_dispatchevent_handlerorder` | 251 | 9.0s |  |
| 716 | `movieclip_dispatchevent_selfadd` | 80 | 8.9s |  |
| 717 | `movieclip_dispatchevent_target` | 899 | 9.0s |  |
| 718 | `movieclip_displayevents` | 96 | 28.8s |  |
| 719 | `movieclip_displayevents_clickgoto` | 676 | 9.7s |  |
| 720 | `movieclip_displayevents_clickgoto2` | 2001 | 9.7s |  |
| 721 | `movieclip_displayevents_clickplay` | 575 | 9.2s |  |
| 722 | `movieclip_displayevents_clicksymbol` | 562 | 9.3s |  |
| 723 | `movieclip_displayevents_constructframegoto` | 140 | 9.5s |  |
| 724 | `movieclip_displayevents_constructframeplay` | 50 | 9.3s |  |
| 725 | `movieclip_displayevents_constructframesymbol` | 144 | 9.2s |  |
| 726 | `movieclip_displayevents_dblhandler` | 21 | 9.1s |  |
| 727 | `movieclip_displayevents_enterframegoto` | 149 | 9.3s |  |
| 728 | `movieclip_displayevents_enterframeplay` | 48 | 9.1s |  |
| 729 | `movieclip_displayevents_enterframesymbol` | 149 | 28.9s |  |
| 730 | `movieclip_displayevents_exitframegoto` | 106 | 9.1s |  |
| 731 | `movieclip_displayevents_exitframeplay` | 44 | 9.1s |  |
| 732 | `movieclip_displayevents_exitframesymbol` | 135 | 9.2s |  |
| 733 | `movieclip_displayevents_looping` | 63 | 9.3s |  |
| 734 | `movieclip_displayevents_stopped` | 113 | 9.5s |  |
| 735 | `movieclip_displayevents_swap` | 96 | 3.2s |  |
| 736 | `movieclip_displayevents_timeline` | 128 | 9.4s |  |
| 737 | `movieclip_drawrect` | 54 | 16.8s |  |
| 738 | `movieclip_frameconstruct_skipped` | 9 | 6.3s |  |
| 739 | `movieclip_goto_during_frame_script` | 15 | 6.3s |  |
| 740 | `movieclip_goto_overwrite` | 14 | 20.9s |  |
| 741 | `movieclip_goto_scene_last_frame_int` | 1 | 19.4s |  |
| 742 | `movieclip_goto_scene_last_frame_label` | 1 | 6.0s |  |
| 743 | `movieclip_gotoandplay` | 15 | 18.7s |  |
| 744 | `movieclip_gotoandstop` | 13 | 6.2s |  |
| 745 | `movieclip_gotoandstop_children` | 4 | 6.5s |  |
| 746 | `movieclip_gotoandstop_framescripts1` | 4 | 6.2s |  |
| 747 | `movieclip_gotoandstop_framescripts2` | 4 | 2.5s |  |
| 748 | `movieclip_gotoandstop_framescripts_self` | 7 | 19.5s |  |
| 749 | `movieclip_gotoandstop_queueing` | 12 | 6.3s |  |
| 750 | `movieclip_hittest` | 67 | 6.4s |  |
| 751 | `movieclip_next_frame` | 2 | 6.3s |  |
| 752 | `movieclip_next_scene` | 6 | 18.6s |  |
| 753 | `movieclip_play` | 3 | 5.9s |  |
| 754 | `movieclip_prev_frame` | 3 | 6.1s |  |
| 755 | `movieclip_prev_scene` | 7 | 6.3s |  |
| 756 | `movieclip_properties` | 79 | 6.5s |  |
| 757 | `movieclip_queued_noop_goto_swf10` | 9 | 6.1s |  |
| 758 | `movieclip_queued_noop_goto_swf9` | 7 | 1.0s |  |
| 759 | `movieclip_scenes` | 11 | 6.3s |  |
| 760 | `movieclip_soundtransform` | 831 | 21.5s |  |
| 761 | `movieclip_stop` | 1 | 6.0s |  |
| 762 | `movieclip_super_is_symbol` | 20 | 6.4s |  |
| 763 | `movieclip_symbol_constr` | 8 | 6.4s |  |
| 764 | `movieclip_text_mousedown` | 1 | 6.7s |  |
| 765 | `movieclip_willtrigger` | 5 | 6.4s |  |
| 766 | `multiply` | 1058 | 13.0s |  |
| 767 | `namespace_constr` | 253 | 6.3s |  |
| 768 | `namespace_constr_args` | 1 | 6.3s |  |
| 769 | `namespace_enumeration_order` | 7 | 6.7s |  |
| 770 | `nan_scale` | 9 | 6.1s |  |
| 771 | `native_menu_basic` | 19 | 7.9s |  |
| 772 | `navigateToURL_target_normalize` | 107 | 21.0s |  |
| 773 | `negate` | 30 | 5.9s |  |
| 774 | `negative_volume_panned` | 0 | 6.3s |  |
| 775 | `nested_iteration` | 11 | 6.2s |  |
| 776 | `net_getClassByAlias` | 3 | 5.9s |  |
| 777 | `net_navigateToURL` | 57 | 6.3s |  |
| 778 | `net_stream_play_options` | 6 | 6.1s |  |
| 779 | `netconnection_close` | 55 | 18.1s |  |
| 780 | `netconnection_properties` | 78 | 6.9s |  |
| 781 | `netconnection_send_remote` | 50 | 25.8s |  |
| 782 | `netconnection_serialize_arrays` | 6 | 6.9s |  |
| 783 | `netfilterevent` | 10 | 6.8s |  |
| 784 | `netstream_client` | 10 | 7.0s |  |
| 785 | `netstream_connect` | 7 | 6.8s |  |
| 786 | `netstream_flv_date` | 4 | 6.9s |  |
| 787 | `newactivation_in_script_init` | 3 | 6.8s |  |
| 788 | `newclass_mismatched` | 4 | 6.9s |  |
| 789 | `newclass_twice` | 3 | 7.1s |  |
| 790 | `nonconflicting_declarations` | 0 | 7.3s |  |
| 791 | `null_void_types` | 8 | 6.8s |  |
| 792 | `number_autoconv` | 21 | 6.9s |  |
| 793 | `number_autoconv_amf` | 132 | 6.8s |  |
| 794 | `number_autoconv_array_sort_32bit` | 1 | 6.7s |  |
| 795 | `number_constr` | 58 | 6.9s |  |
| 796 | `number_convert_edge_cases` | 180 | 23.6s |  |
| 797 | `number_toexponential` | 378 | 6.9s |  |
| 798 | `number_toexponential2` | 35 | 6.8s |  |
| 799 | `number_tofixed` | 378 | 6.9s |  |
| 800 | `number_toprecision` | 350 | 6.8s |  |
| 801 | `obfuscated_class_names` | 3 | 7.2s |  |
| 802 | `object_enumeration` | 10 | 6.8s |  |
| 803 | `object_prototype` | 4 | 6.9s |  |
| 804 | `object_to_locale_string` | 2 | 6.8s |  |
| 805 | `object_to_string` | 2 | 7.0s |  |
| 806 | `object_value_of` | 2 | 2.2s |  |
| 807 | `op_coerce` | 54 | 6.8s |  |
| 808 | `op_coerce_x` | 54 | 7.0s |  |
| 809 | `op_escxattr` | 2 | 6.8s |  |
| 810 | `op_escxelem` | 2 | 6.8s |  |
| 811 | `op_lookupswitch` | 4 | 6.9s |  |
| 812 | `optimize_coerce` | 1 | 6.7s |  |
| 813 | `orphan_movie_complex` | 80 | 7.2s |  |
| 814 | `orphan_movie_reorder` | 111 | 23.9s |  |
| 815 | `orphan_removeobject` | 636 | 42.6s |  |
| 816 | `package_namespace` | 7 | 8.9s |  |
| 817 | `param_default_value_has_zero_cpool_index` | 1 | 8.6s |  |
| 818 | `parent_early_access_child` | 16 | 9.1s |  |
| 819 | `parse_float` | 81 | 8.9s |  |
| 820 | `parse_float_swf10` | 81 | 8.6s |  |
| 821 | `parse_int` | 135 | 9.2s |  |
| 822 | `perspective_projection` | 1443 | 28.5s |  |
| 823 | `perspective_projection_basic` | 40 | 8.7s |  |
| 824 | `pixelbender_ceil` | 77 | 8.9s |  |
| 825 | `pixelbender_conditional` | 138 | 9.0s |  |
| 826 | `pixelbender_conversions` | 270 | 9.0s |  |
| 827 | `pixelbender_dithering` | 8 | 34.8s |  |
| 828 | `pixelbender_div` | 36 | 8.7s |  |
| 829 | `pixelbender_effect_BlurredFocus` | 0 | 37.3s |  |
| 830 | `pixelbender_effect_glassDisplace` | 0 | 15.5s |  |
| 831 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 13.6s |  |
| 832 | `pixelbender_effect_smudge` | 0 | 12.3s |  |
| 833 | `pixelbender_effect_tintype` | 0 | 11.5s |  |
| 834 | `pixelbender_effect_twirl` | 0 | 13.1s |  |
| 835 | `pixelbender_eof` | 7 | 8.6s |  |
| 836 | `pixelbender_images` | 0 | 11.2s |  |
| 837 | `pixelbender_input` | 103 | 28.8s |  |
| 838 | `pixelbender_logicalnot` | 20 | 8.6s |  |
| 839 | `pixelbender_malformed_data` | 190 | 29.2s |  |
| 840 | `pixelbender_multiple_out_params` | 1 | 8.6s |  |
| 841 | `pixelbender_no_out_param` | 6 | 8.7s |  |
| 842 | `pixelbender_outputs` | 13 | 8.9s |  |
| 843 | `pixelbender_padding_bytes` | 22 | 8.8s |  |
| 844 | `pixelbender_param_qualifier` | 512 | 8.8s |  |
| 845 | `pixelbender_parameters` | 1563 | 9.1s |  |
| 846 | `pixelbender_parameters_bool` | 240 | 9.0s |  |
| 847 | `pixelbender_parameters_int_vs_bool` | 54 | 8.8s |  |
| 848 | `pixelbender_parse_errors` | 6 | 8.7s |  |
| 849 | `pixelbender_rsqrt` | 24 | 8.8s |  |
| 850 | `pixelbender_select_kinds` | 8 | 8.9s |  |
| 851 | `pixelbender_shaderdata` | 49 | 8.7s |  |
| 852 | `pixelbender_shaderdata_setter` | 99 | 9.2s |  |
| 853 | `pixelbender_sign` | 60 | 9.0s |  |
| 854 | `pixelbender_vector_output` | 11 | 8.9s |  |
| 855 | `place_and_lookup/swf10` | 33 | 8.8s |  |
| 856 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 857 | `place_multiple` | 17 | 22.7s |  |
| 858 | `place_object_replace` | 9 | 28.7s |  |
| 859 | `place_object_replace_2` | 24 | 9.1s |  |
| 860 | `place_object_same_depth_frame` | 1 | 8.9s |  |
| 861 | `point` | 132 | 9.4s |  |
| 862 | `primitive_edge_cases` | 1 | 8.8s |  |
| 863 | `primitive_keys` | 54 | 8.8s |  |
| 864 | `primitive_toString` | 277 | 9.0s |  |
| 865 | `primitive_valueOf` | 285 | 8.7s |  |
| 866 | `print_job_options` | 3 | 8.7s |  |
| 867 | `property_is_enumerable` | 114 | 9.9s |  |
| 868 | `property_is_enumerable_reset` | 23 | 8.8s |  |
| 869 | `property_priority` | 22 | 9.1s |  |
| 870 | `property_priority_chained` | 4 | 8.7s |  |
| 871 | `property_priority_definition_names_order` | 2 | 9.1s |  |
| 872 | `property_priority_three_level` | 6 | 8.9s |  |
| 873 | `propertyisenumerable_namespaces` | 6 | 8.8s |  |
| 874 | `prototype_set_null` | 7 | 8.8s |  |
| 875 | `proxy_callproperty` | 24 | 8.8s |  |
| 876 | `proxy_deleteproperty` | 64 | 8.9s |  |
| 877 | `proxy_enumeration` | 34 | 8.8s |  |
| 878 | `proxy_getproperty` | 77 | 8.9s |  |
| 879 | `proxy_hasownproperty` | 8 | 8.7s |  |
| 880 | `proxy_hasproperty` | 32 | 8.9s |  |
| 881 | `proxy_not_overridden` | 54 | 8.9s |  |
| 882 | `proxy_serialize` | 9 | 8.8s |  |
| 883 | `proxy_setproperty` | 42 | 8.9s |  |
| 884 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.7s |  |
| 885 | `qname_constr` | 32 | 8.9s |  |
| 886 | `qname_constr_namespace` | 24 | 8.9s |  |
| 887 | `qname_enumeration` | 9 | 8.8s |  |
| 888 | `qname_indexing` | 23 | 8.9s |  |
| 889 | `qname_tostring` | 25 | 8.9s |  |
| 890 | `qname_valueof` | 29 | 8.9s |  |
| 891 | `rectangle` | 1094 | 9.5s |  |
| 892 | `regexp_constr` | 148 | 9.1s |  |
| 893 | `regexp_exec` | 19 | 8.8s |  |
| 894 | `regexp_extended` | 47 | 8.7s |  |
| 895 | `regexp_multiargs` | 1 | 8.7s |  |
| 896 | `regexp_test` | 27 | 8.8s |  |
| 897 | `regexp_toString` | 10 | 8.8s |  |
| 898 | `register_script_refresh` | 35 | 9.5s |  |
| 899 | `remove_child_clear_field` | 88 | 23.8s |  |
| 900 | `remove_dobj` | 3 | 9.5s |  |
| 901 | `resolve_order` | 4 | 9.2s |  |
| 902 | `responder_null_callbacks` | 1 | 9.2s |  |
| 903 | `rng` | 1 | 10.8s |  |
| 904 | `rootless` | 42 | 9.4s |  |
| 905 | `rshift` | 1058 | 20.0s |  |
| 906 | `rtqname_not_namespace` | 12 | 9.2s |  |
| 907 | `sandbox_type_inherited` | 2 | 9.7s |  |
| 908 | `sandbox_type_local_file` | 1 | 9.1s |  |
| 909 | `sandbox_type_local_network` | 1 | 8.9s |  |
| 910 | `scene_constr` | 8 | 9.3s |  |
| 911 | `scope_optimizations` | 4 | 9.1s |  |
| 912 | `scopes_dont_cache/order-1` | 1 | 30.0s |  |
| 913 | `scopes_dont_cache/order-2` | 1 | 1.2s |  |
| 914 | `security_domain_current` | 2 | 8.8s |  |
| 915 | `selection` | 239 | 9.8s |  |
| 916 | `set_local_0` | 31 | 9.2s |  |
| 917 | `set_property_is_enumerable` | 85 | 9.4s |  |
| 918 | `shaderparameter_value` | 4 | 8.8s |  |
| 919 | `shape_drawrect` | 54 | 8.9s |  |
| 920 | `shared_object_no_root` | 3 | 8.9s |  |
| 921 | `simplebutton_added_to_stage` | 45 | 30.2s |  |
| 922 | `simplebutton_childevents` | 86 | 31.7s |  |
| 923 | `simplebutton_childevents_nested` | 54 | 9.8s |  |
| 924 | `simplebutton_childevents_sprite` | 13 | 9.5s |  |
| 925 | `simplebutton_childprops` | 144 | 9.8s |  |
| 926 | `simplebutton_childshuffle` | 23 | 9.0s |  |
| 927 | `simplebutton_constr` | 36 | 9.7s |  |
| 928 | `simplebutton_constr_childevents` | 48 | 10.3s |  |
| 929 | `simplebutton_constr_params` | 42 | 9.9s |  |
| 930 | `simplebutton_mouseenabled` | 26 | 9.7s |  |
| 931 | `simplebutton_multi_children` | 19 | 9.8s |  |
| 932 | `simplebutton_soundtransform` | 887 | 33.1s |  |
| 933 | `simplebutton_structure` | 27 | 9.6s |  |
| 934 | `simplebutton_symbolclass` | 68 | 9.9s |  |
| 935 | `slot_disp_id_shared_numbering` | 1 | 29.8s |  |
| 936 | `slots_force_autoassigned` | 1 | 8.9s |  |
| 937 | `socket_after_disconnect` | 1 | 9.0s |  |
| 938 | `socket_close` | 2 | 8.7s |  |
| 939 | `socket_connect` | 4 | 8.8s |  |
| 940 | `socket_errors` | 56 | 9.2s |  |
| 941 | `socket_read_big` | 48 | 8.8s |  |
| 942 | `socket_read_little` | 48 | 3.2s |  |
| 943 | `socket_read_write_object` | 8 | 8.8s |  |
| 944 | `socket_write_big` | 15 | 9.1s |  |
| 945 | `socket_write_little` | 14 | 8.8s |  |
| 946 | `sound_constructor_with_args` | 6 | 9.2s |  |
| 947 | `sound_embeddedprops` | 26 | 9.3s |  |
| 948 | `sound_play` | 19 | 9.2s |  |
| 949 | `sound_rootless` | 7 | 9.1s |  |
| 950 | `sound_valueof` | 33 | 9.2s |  |
| 951 | `soundchannel_soundtransform` | 835 | 31.8s |  |
| 952 | `soundchannel_soundtransform_exists` | 5 | 29.7s |  |
| 953 | `soundchannel_stop` | 8 | 9.5s |  |
| 954 | `soundmixer_buffertime` | 5 | 9.2s |  |
| 955 | `soundmixer_soundtransform` | 900 | 11.2s |  |
| 956 | `soundmixer_stopall` | 6 | 9.0s |  |
| 957 | `soundtransform` | 442 | 15.5s |  |
| 958 | `space_justifier_clone` | 12 | 9.0s |  |
| 959 | `sprite_with_frames` | 0 | 31.0s |  |
| 960 | `stage3d_agal_cross_product` | 0 | 12.7s |  |
| 961 | `stage3d_agal_upload_errors` | 66 | 12.5s |  |
| 962 | `stage3d_bitmap` | 0 | 36.7s |  |
| 963 | `stage3d_blend` | 81 | 35.3s |  |
| 964 | `stage3d_context3d_string_args` | 158 | 10.6s |  |
| 965 | `stage3d_errors` | 7 | 9.1s |  |
| 966 | `stage3d_errors_atf` | 3 | 10.7s |  |
| 967 | `stage3d_errors_swf_29` | 6 | 9.1s |  |
| 968 | `stage3d_float1_index` | 0 | 31.4s |  |
| 969 | `stage3d_fractal` | 0 | 32.4s |  |
| 970 | `stage3d_ignore_sampler_override` | 0 | 33.4s |  |
| 971 | `stage3d_multistage_triangle` | 3 | 13.0s |  |
| 972 | `stage3d_program_constants_bytearray_be` | 0 | 35.1s |  |
| 973 | `stage3d_program_constants_bytearray_le` | 0 | 47.4s |  |
| 974 | `stage3d_program_constants_invalid_input` | 21 | 11.9s |  |
| 975 | `stage3d_raytrace` | 0 | 39.7s |  |
| 976 | `stage3d_rotating_cube` | 0 | 13.2s |  |
| 977 | `stage3d_sampler` | 0 | 12.7s |  |
| 978 | `stage3d_sampler_partial_upload` | 0 | 12.6s |  |
| 979 | `stage3d_stencil` | 0 | 13.5s |  |
| 980 | `stage3d_texture` | 0 | 19.2s |  |
| 981 | `stage3d_texture_bytearray` | 0 | 14.2s |  |
| 982 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 13.2s |  |
| 983 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 14.4s |  |
| 984 | `stage3d_triangle` | 0 | 12.6s |  |
| 985 | `stage3d_triangle_bytes4` | 0 | 12.6s |  |
| 986 | `stage3d_triangle_float1` | 0 | 12.6s |  |
| 987 | `stage3d_triangle_index_upload` | 0 | 12.5s |  |
| 988 | `stage3d_x_y` | 22 | 9.1s |  |
| 989 | `stage_access` | 10 | 9.2s |  |
| 990 | `stage_display_state` | 6 | 9.2s |  |
| 991 | `stage_displayobject_properties` | 24 | 9.2s |  |
| 992 | `stage_domain_getQualifiedDefinitionNames` | 5 | 9.1s |  |
| 993 | `stage_framerate_nan` | 7 | 9.3s |  |
| 994 | `stage_framerate_negative` | 6 | 9.1s |  |
| 995 | `stage_framerate_zero` | 6 | 9.1s |  |
| 996 | `stage_invalidate` | 38 | 9.6s |  |
| 997 | `stage_loaderinfo_properties` | 24 | 29.7s |  |
| 998 | `stage_mousechildren` | 2 | 8.9s |  |
| 999 | `stage_mouseenabled` | 15 | 8.8s |  |
| 1000 | `stage_overriden_setters` | 31 | 9.0s |  |
| 1001 | `stage_properties` | 30 | 8.8s |  |
| 1002 | `stage_properties2` | 213 | 9.1s |  |
| 1003 | `stage_scale_factor` | 12 | 34.9s |  |
| 1004 | `stage_stage3Ds_vector` | 1 | 9.2s |  |
| 1005 | `static_length` | 24 | 9.0s |  |
| 1006 | `static_text` | 3 | 9.0s |  |
| 1007 | `static_var_with_this_in_ctor` | 2 | 8.8s |  |
| 1008 | `statictext_text` | 8 | 8.9s |  |
| 1009 | `stored_properties` | 11 | 8.9s |  |
| 1010 | `strict_equality` | 34 | 8.9s |  |
| 1011 | `string_call` | 13 | 8.8s |  |
| 1012 | `string_case` | 23 | 8.9s |  |
| 1013 | `string_char_at` | 27 | 8.9s |  |
| 1014 | `string_char_code_at` | 28 | 8.7s |  |
| 1015 | `string_concat_fromcharcode` | 37 | 18.9s |  |
| 1016 | `string_constr` | 25 | 6.9s |  |
| 1017 | `string_indexof_lastindexof` | 87 | 7.2s |  |
| 1018 | `string_length` | 16 | 7.0s |  |
| 1019 | `string_locale_compare` | 39 | 7.3s |  |
| 1020 | `string_match` | 51 | 7.4s |  |
| 1021 | `string_relational_compare` | 4 | 7.1s |  |
| 1022 | `string_replace` | 51 | 7.3s |  |
| 1023 | `string_search` | 41 | 7.4s |  |
| 1024 | `string_slice_substr_substring` | 170 | 8.4s |  |
| 1025 | `string_split` | 29 | 7.4s |  |
| 1026 | `string_substr_negative` | 21 | 7.4s |  |
| 1027 | `string_substr_weird` | 182 | 7.3s |  |
| 1028 | `stylesheet` | 221 | 8.3s |  |
| 1029 | `stylesheet_parse_color` | 69 | 7.5s |  |
| 1030 | `stylesheet_transform` | 307 | 7.8s |  |
| 1031 | `sub_super_same_field` | 12 | 3.1s |  |
| 1032 | `subclass_superclass_linked_symbol` | 4 | 8.3s |  |
| 1033 | `subtract` | 1058 | 16.1s |  |
| 1034 | `super_get_call` | 12 | 7.3s |  |
| 1035 | `supercall_two_classobjects` | 2 | 7.4s |  |
| 1036 | `supercalls_coerce` | 8 | 7.7s |  |
| 1037 | `supercalls_weird` | 2 | 7.2s |  |
| 1038 | `superinterface_call` | 20 | 7.3s |  |
| 1039 | `superinterface_instanceof` | 18 | 7.7s |  |
| 1040 | `swf8` | 1 | 7.5s |  |
| 1041 | `swf_10_queued_goto_scripts_construct` | 52 | 7.6s |  |
| 1042 | `swf_9_goto_in_enter_frame` | 17 | 7.4s |  |
| 1043 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.4s |  |
| 1044 | `swf_9_queued_goto_scripts` | 6 | 7.5s |  |
| 1045 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 1046 | `swf_9_versioning` | 2 | 7.9s |  |
| 1047 | `swf_wrong_frame_count` | 38 | 7.6s |  |
| 1048 | `swf_wrong_frame_count_isplaying` | 22 | 7.3s |  |
| 1049 | `symbol_class_binary_data` | 8 | 7.5s |  |
| 1050 | `symbol_class_conflict` | 4 | 7.7s |  |
| 1051 | `symbol_class_root_not_zero` | 1 | 7.2s |  |
| 1052 | `symbolclass_invalid_utf8` | 2 | 7.3s |  |
| 1053 | `system_exit` | 3 | 7.2s |  |
| 1054 | `system_setclipboard_null` | 1 | 6.9s |  |
| 1055 | `tab_ordering_arrows` | 998 | 21.8s |  |
| 1056 | `tab_ordering_automatic_advanced` | 184 | 7.9s |  |
| 1057 | `tab_ordering_automatic_basic` | 45 | 7.3s |  |
| 1058 | `tab_ordering_children` | 116 | 7.5s |  |
| 1059 | `tab_ordering_custom_basic` | 34 | 7.2s |  |
| 1060 | `tab_ordering_stage_tab_children` | 32 | 7.3s |  |
| 1061 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.1s |  |
| 1062 | `tab_ordering_tabbable` | 47 | 7.4s |  |
| 1063 | `tabstop_properties` | 105 | 7.6s |  |
| 1064 | `text_element_basic` | 34 | 7.3s |  |
| 1065 | `text_engine_fontdescription` | 27 | 7.4s |  |
| 1066 | `text_engine_groupelement` | 64 | 8.1s |  |
| 1067 | `text_run` | 7 | 7.1s |  |
| 1068 | `textblock_createline_errors` | 23 | 7.4s |  |
| 1069 | `textblock_createline_fte` | 9 | 7.5s |  |
| 1070 | `textblock_properties` | 118 | 7.8s |  |
| 1071 | `textbox_click` | 37 | 7.4s |  |
| 1072 | `textfield_event` | 66 | 7.3s |  |
| 1073 | `textfield_focusin_event` | 9 | 7.2s |  |
| 1074 | `textfield_input_dead_keys_windows` | 15 | 7.2s |  |
| 1075 | `textfield_input_events` | 25 | 19.6s |  |
| 1076 | `textfield_unload` | 39 | 7.5s |  |
| 1077 | `textformat` | 1134 | 7.3s |  |
| 1078 | `textformat_display` | 14 | 7.2s |  |
| 1079 | `textformat_font_max_length` | 4 | 7.2s |  |
| 1080 | `textline_inapplicable_properties` | 10 | 7.2s |  |
| 1081 | `textline_name` | 1 | 7.1s |  |
| 1082 | `textline_raw_text_length` | 30 | 7.2s |  |
| 1083 | `textline_splitting_basic` | 76 | 7.3s |  |
| 1084 | `textline_throwerror` | 30 | 7.2s |  |
| 1085 | `textline_validity` | 162 | 7.4s |  |
| 1086 | `throw` | 3 | 7.2s |  |
| 1087 | `timeline_scripts` | 3 | 7.4s |  |
| 1088 | `timer` | 90 | 8.5s |  |
| 1089 | `timer_events` | 3 | 7.4s |  |
| 1090 | `timer_finished` | 11 | 7.4s |  |
| 1091 | `timer_invalid_delay` | 30 | 7.2s |  |
| 1092 | `timer_reset` | 8 | 21.7s |  |
| 1093 | `timer_setdelay` | 5 | 8.1s |  |
| 1094 | `trace` | 12 | 7.9s |  |
| 1095 | `truthiness` | 30 | 8.0s |  |
| 1096 | `try_catch` | 11 | 8.0s |  |
| 1097 | `try_catch_typed` | 12 | 7.9s |  |
| 1098 | `typeof` | 30 | 7.9s |  |
| 1099 | `uint_constr` | 92 | 8.0s |  |
| 1100 | `uint_tofixed` | 1215 | 7.5s |  |
| 1101 | `uint_toprecision` | 1125 | 8.0s |  |
| 1102 | `uint_tostring` | 3375 | 8.0s |  |
| 1103 | `uncaught_error_basic` | 2 | 7.8s |  |
| 1104 | `unchecked_function` | 15 | 7.8s |  |
| 1105 | `unescape` | 28 | 7.8s |  |
| 1106 | `url_loader` | 25 | 8.0s |  |
| 1107 | `url_vars` | 27 | 8.0s |  |
| 1108 | `urlrequest` | 18 | 7.9s |  |
| 1109 | `urlstream_basic` | 5 | 7.8s |  |
| 1110 | `urshift` | 1058 | 19.1s |  |
| 1111 | `utils3d` | 7 | 7.7s |  |
| 1112 | `vector3d` | 397 | 12.5s |  |
| 1113 | `vector3d_near_equals` | 80 | 7.9s |  |
| 1114 | `vector_class` | 36 | 8.2s |  |
| 1115 | `vector_class_call` | 11 | 8.2s |  |
| 1116 | `vector_coercion` | 66 | 8.7s |  |
| 1117 | `vector_concat` | 90 | 8.7s |  |
| 1118 | `vector_constr` | 107 | 8.8s |  |
| 1119 | `vector_enumeration` | 5 | 7.9s |  |
| 1120 | `vector_every` | 92 | 8.8s |  |
| 1121 | `vector_filter` | 95 | 8.8s |  |
| 1122 | `vector_holes` | 24 | 7.9s |  |
| 1123 | `vector_indexof` | 302 | 13.0s |  |
| 1124 | `vector_insertat` | 270 | 9.1s |  |
| 1125 | `vector_int_access` | 4 | 7.7s |  |
| 1126 | `vector_int_delete` | 11 | 7.7s |  |
| 1127 | `vector_join` | 58 | 8.2s |  |
| 1128 | `vector_lastindexof` | 302 | 7.6s |  |
| 1129 | `vector_legacy` | 10 | 8.0s |  |
| 1130 | `vector_map` | 85 | 8.6s |  |
| 1131 | `vector_object_final` | 1 | 7.7s |  |
| 1132 | `vector_object_toString` | 10 | 23.1s |  |
| 1133 | `vector_pushpop` | 255 | 10.6s |  |
| 1134 | `vector_reborrow_bug` | 10 | 9.2s |  |
| 1135 | `vector_removeat` | 172 | 10.3s |  |
| 1136 | `vector_reverse` | 232 | 10.3s |  |
| 1137 | `vector_shiftunshift` | 252 | 8.9s |  |
| 1138 | `vector_slice` | 331 | 10.8s |  |
| 1139 | `vector_sort` | 905 | 18.8s |  |
| 1140 | `vector_splice` | 693 | 13.3s |  |
| 1141 | `vector_splice_fixed_bug_compat` | 4 | 9.3s |  |
| 1142 | `vector_tostring` | 79 | 9.9s |  |
| 1143 | `verification` | 8 | 9.2s |  |
| 1144 | `verify_abnormal_loop` | 1 | 8.9s |  |
| 1145 | `verify_dxns_without_flag` | 3 | 9.4s |  |
| 1146 | `verify_exception_target_two_jumps` | 1 | 8.9s |  |
| 1147 | `verify_exception_targets_edge_case` | 1 | 9.0s |  |
| 1148 | `verify_illegal_opcode` | 1 | 3.9s |  |
| 1149 | `verify_jump_to_middle_of_op` | 1 | 9.1s |  |
| 1150 | `verify_lookup_switch_edge_case` | 1 | 9.0s |  |
| 1151 | `verify_method_info_oob` | 1 | 1.3s |  |
| 1152 | `verify_stack` | 5 | 9.1s |  |
| 1153 | `verify_typecheck` | 4 | 9.0s |  |
| 1154 | `verify_unreachable_exception` | 2 | 8.9s |  |
| 1155 | `versioned_isplaying` | 2 | 9.0s |  |
| 1156 | `virtual_properties` | 16 | 9.1s |  |
| 1157 | `with` | 4 | 9.2s |  |
| 1158 | `wrong_arg_count` | 7 | 9.4s |  |
| 1159 | `xml_abstract_equality` | 36 | 9.4s |  |
| 1160 | `xml_advanced` | 52 | 9.1s |  |
| 1161 | `xml_appendchild` | 10 | 9.2s |  |
| 1162 | `xml_appendchild_swf_v21` | 13 | 9.3s |  |
| 1163 | `xml_as_attribute` | 9 | 8.9s |  |
| 1164 | `xml_attribute` | 35 | 9.2s |  |
| 1165 | `xml_attribute_name` | 40 | 9.1s |  |
| 1166 | `xml_basic` | 33 | 9.3s |  |
| 1167 | `xml_child` | 25 | 9.2s |  |
| 1168 | `xml_childindex` | 7 | 9.2s |  |
| 1169 | `xml_children` | 43 | 9.7s |  |
| 1170 | `xml_class_call` | 9 | 9.1s |  |
| 1171 | `xml_contains` | 197 | 9.2s |  |
| 1172 | `xml_copy` | 20 | 21.4s |  |
| 1173 | `xml_ctor_from_tostring` | 23 | 8.5s |  |
| 1174 | `xml_delete` | 114 | 8.3s |  |
| 1175 | `xml_descendants` | 83 | 8.1s |  |
| 1176 | `xml_duplicate_attribute` | 14 | 8.2s |  |
| 1177 | `xml_elements` | 6 | 8.0s |  |
| 1178 | `xml_equals_namespace_check` | 2 | 8.0s |  |
| 1179 | `xml_explicit_use_namespace` | 5 | 8.0s |  |
| 1180 | `xml_getdescendants_qname` | 21 | 8.1s |  |
| 1181 | `xml_has_property_via_in` | 26 | 8.0s |  |
| 1182 | `xml_hasownproperty` | 6 | 7.9s |  |
| 1183 | `xml_ignore_white` | 6 | 8.0s |  |
| 1184 | `xml_length` | 2 | 8.1s |  |
| 1185 | `xml_list_as_attribute` | 9 | 8.0s |  |
| 1186 | `xml_list_concat` | 20 | 8.0s |  |
| 1187 | `xml_list_ctor_errors` | 34 | 8.1s |  |
| 1188 | `xml_list_delete_clear_parent` | 6 | 8.0s |  |
| 1189 | `xml_list_enumerate` | 4 | 7.9s |  |
| 1190 | `xml_methods_settings` | 3 | 7.9s |  |
| 1191 | `xml_mismatched_tag` | 37 | 8.2s |  |
| 1192 | `xml_namespace` | 39 | 8.1s |  |
| 1193 | `xml_namespace_methods` | 245 | 8.1s |  |
| 1194 | `xml_namespaced_property` | 7 | 8.0s |  |
| 1195 | `xml_no_namespace` | 1 | 8.0s |  |
| 1196 | `xml_nodekind` | 3 | 7.9s |  |
| 1197 | `xml_normalize` | 35 | 8.0s |  |
| 1198 | `xml_notification_bubbling` | 361 | 8.0s |  |
| 1199 | `xml_parent` | 8 | 8.1s |  |
| 1200 | `xml_set_children` | 17 | 8.0s |  |
| 1201 | `xml_set_name` | 34 | 7.9s |  |
| 1202 | `xml_settings` | 6 | 3.0s |  |
| 1203 | `xml_simple_complex_content` | 47 | 8.1s |  |
| 1204 | `xml_socket` | 11 | 8.2s |  |
| 1205 | `xml_text` | 7 | 8.0s |  |
| 1206 | `xml_tostring` | 6 | 8.0s |  |
| 1207 | `xml_tostring_namespace` | 12 | 7.9s |  |
| 1208 | `xml_unescaping` | 23 | 8.0s |  |
| 1209 | `xml_weird_ignores` | 54 | 8.1s |  |
| 1210 | `xml_wildcard` | 11 | 8.1s |  |
| 1211 | `xmldocument` | 254 | 8.2s |  |
| 1212 | `xmlnode` | 3540 | 8.5s |  |
| 1213 | `zero_frame_clip` | 3 | 9.1s |  |

## Ruffle-Matched Tests

**35 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.6s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.0s |  |
| 3 | `blend_transform` | 1 | 1 | 9.4s |  |
| 4 | `bounds_mode` | 6 | 6 | 7.2s |  |
| 5 | `coerce_property` | 3 | 3 | 8.8s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 8.7s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 6.2s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 19.6s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 6.6s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.3s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 6.1s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 7.5s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 8.6s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 8.7s |  |
| 15 | `event_handler_exception` | 4 | 4 | 8.8s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 8.8s |  |
| 17 | `graphics_draw_path` | 50 | 50 | 30.2s |  |
| 18 | `groupelement_text` | 2 | 2 | 9.5s |  |
| 19 | `int_toexponential` | 76 | 76 | 7.8s |  |
| 20 | `json_parse_numbers` | 4 | 79 | 7.8s |  |
| 21 | `loader_events_2` | 30 | 30 | 7.4s |  |
| 22 | `matrix3d_recompose_edge_cases` | 8 | 85 | 9.2s |  |
| 23 | `number_convert_errors` | 706 | 706 | 7.0s |  |
| 24 | `simplebutton_childevents_script_order` | 4 | 4 | 10.0s |  |
| 25 | `slot_holes_fail` | 1 | 1 | 9.1s |  |
| 26 | `slot_id_exceeds_trait_count` | 1 | 1 | 22.3s |  |
| 27 | `soundchannel_position` | 74 | 74 | 30.8s |  |
| 28 | `soundchannel_soundcomplete` | 10 | 10 | 9.2s |  |
| 29 | `sprite_dropTarget` | 15 | 15 | 9.1s |  |
| 30 | `swf_9_goto_in_construct_frame` | 12 | 12 | 24.4s |  |
| 31 | `textblock_line_changes` | 44 | 44 | 7.8s |  |
| 32 | `textblock_releaselines` | 4 | 4 | 8.8s |  |
| 33 | `uint_toexponential` | 100 | 100 | 7.9s |  |
| 34 | `uncaught_errors_stringified` | 15 | 15 | 8.1s |  |
| 35 | `weird_superinterface_properties` | 1 | 1 | 9.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**9 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 3 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 4 | `goto_framescript_queued_same_frame` | 75.0% | 3 | 4 | 1 |  |
| 5 | `number_to_string` | 67.1% | 237 | 353 | 116 |  |
| 6 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 7 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 8 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 9 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

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
| 4 | `goto_framescript_queued_same_frame` | 75.0% | 3/4 | 4 | 4 |  |
| 5 | `number_to_string` | 67.1% | 237/353 | 353 | 353 |  |
| 6 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 7 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 8 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 9 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 10 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 11 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 12 | `goto_framescript_queued/swf13` | 28.8% | 17/59 | 48 | 59 |  |
| 13 | `goto_framescript_queued/swf10` | 25.4% | 15/59 | 48 | 59 |  |
| 14 | `textblock_recreateline` | 22.1% | 40/181 | 181 | 180 |  |
| 15 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 16 | `goto_framescript_queued/swf9` | 21.2% | 11/52 | 46 | 52 |  |
| 17 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 18 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 19 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 20 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 21 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 22 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 23 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 24 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 25 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 26 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 27 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
