# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-12 04:11 UTC

**Git SHA**: `fe79e0c794`

**Run Duration**: 232m 43s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1274 |
| Passing | **1213** (95.2%) |
| Ruffle-matched | 36 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1249** (98.0%) |
| Failing | 25 |
| Total expected lines | 157153 |
| Matching lines | 154265 (98.2%) |
| Mismatched lines | 2888 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 25 | 100.0% |

## Passing Tests

**1213 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 26.7s |  |
| 2 | `accessibility` | 1 | 8.1s |  |
| 3 | `accessibilityimplementation` | 18 | 26.6s |  |
| 4 | `activation_class` | 6 | 8.3s |  |
| 5 | `add` | 1058 | 20.0s |  |
| 6 | `agal_compiler` | 13 | 10.7s |  |
| 7 | `air_datagram_socket` | 1 | 10.3s |  |
| 8 | `air_hidden_lookup` | 2 | 8.3s |  |
| 9 | `air_ifilepromise` | 1 | 8.1s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 8.3s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.2s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.2s |  |
| 13 | `all_classes/display/swf10` | 2569 | 8.2s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.3s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.3s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.3s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.2s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.2s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 8.2s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.2s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.2s |  |
| 22 | `all_classes/errors/swf10` | 140 | 8.2s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.2s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.2s |  |
| 25 | `all_classes/events/swf10` | 1638 | 8.2s |  |
| 26 | `all_classes/events/swf11` | 1750 | 1.2s |  |
| 27 | `all_classes/events/swf12` | 1814 | 1.2s |  |
| 28 | `all_classes/events/swf30` | 2353 | 1.2s |  |
| 29 | `all_classes/events/swf9` | 1030 | 1.2s |  |
| 30 | `all_classes/security/swf11` | 3 | 8.2s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.2s |  |
| 32 | `all_classes/security/swf13` | 53 | 1.2s |  |
| 33 | `all_classes/security/swf30` | 53 | 1.2s |  |
| 34 | `all_classes/xml/swf30` | 116 | 8.2s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.2s |  |
| 36 | `amf_array_serialization` | 17 | 29.0s |  |
| 37 | `amf_custom_obj` | 26 | 8.3s |  |
| 38 | `amf_dictionary` | 9 | 8.1s |  |
| 39 | `amf_function` | 46 | 8.3s |  |
| 40 | `amf_invalid_date` | 2 | 8.2s |  |
| 41 | `amf_missing_prop` | 6 | 8.2s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 8.2s |  |
| 43 | `amf_setter_error` | 8 | 8.3s |  |
| 44 | `amf_vector` | 40 | 27.8s |  |
| 45 | `amf_xml` | 6 | 8.4s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 8.9s |  |
| 47 | `application_domain` | 4 | 8.4s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 27.8s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 8.4s |  |
| 50 | `array_access` | 18 | 8.5s |  |
| 51 | `array_access_interpreter` | 4 | 8.4s |  |
| 52 | `array_access_no_pubns` | 2 | 8.4s |  |
| 53 | `array_concat` | 41 | 8.5s |  |
| 54 | `array_constr` | 10 | 8.5s |  |
| 55 | `array_delete` | 44 | 8.5s |  |
| 56 | `array_enumeration` | 10 | 8.5s |  |
| 57 | `array_enumeration_elements` | 11 | 8.4s |  |
| 58 | `array_every` | 8 | 8.4s |  |
| 59 | `array_filter` | 6 | 8.4s |  |
| 60 | `array_foreach` | 18 | 8.4s |  |
| 61 | `array_hasownproperty` | 11 | 8.5s |  |
| 62 | `array_holes` | 9 | 8.4s |  |
| 63 | `array_index_max` | 84 | 8.4s |  |
| 64 | `array_indexof` | 25 | 8.4s |  |
| 65 | `array_join` | 26 | 8.5s |  |
| 66 | `array_lastindexof` | 29 | 8.4s |  |
| 67 | `array_length` | 14 | 8.4s |  |
| 68 | `array_literal` | 3 | 8.4s |  |
| 69 | `array_map` | 8 | 3.0s |  |
| 70 | `array_pop` | 52 | 8.5s |  |
| 71 | `array_push` | 24 | 8.4s |  |
| 72 | `array_reborrow_bug` | 6 | 8.4s |  |
| 73 | `array_reverse` | 28 | 8.4s |  |
| 74 | `array_shift` | 51 | 3.2s |  |
| 75 | `array_slice` | 39 | 8.5s |  |
| 76 | `array_some` | 8 | 8.4s |  |
| 77 | `array_sort` | 297 | 8.9s |  |
| 78 | `array_sort_fun_swf12` | 2 | 8.5s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 80 | `array_sort_random` | 210 | 8.5s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 8.4s |  |
| 82 | `array_sorton` | 545 | 9.4s |  |
| 83 | `array_sparse_ops` | 41 | 8.6s |  |
| 84 | `array_splice` | 133 | 8.7s |  |
| 85 | `array_splice2` | 428 | 27.6s |  |
| 86 | `array_splice_types` | 48 | 8.5s |  |
| 87 | `array_storage` | 8 | 27.3s |  |
| 88 | `array_tolocalestring` | 9 | 8.4s |  |
| 89 | `array_tostring` | 12 | 8.4s |  |
| 90 | `array_unshift` | 24 | 8.4s |  |
| 91 | `array_valueof` | 9 | 8.3s |  |
| 92 | `array_vector_null_callback` | 10 | 8.4s |  |
| 93 | `astype` | 28 | 8.4s |  |
| 94 | `astypelate` | 24 | 8.5s |  |
| 95 | `astypelate_propagates` | 1 | 8.3s |  |
| 96 | `asymmetric_key_events` | 11 | 8.5s |  |
| 97 | `automation_classes` | 122 | 8.8s |  |
| 98 | `av_classes` | 340 | 8.7s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 8.5s |  |
| 100 | `avm2_catchup_dobj` | 158 | 9.3s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 93.9s |  |
| 102 | `bevel_filter` | 187 | 8.7s |  |
| 103 | `bitand` | 1058 | 20.3s |  |
| 104 | `bitmap_constr` | 17 | 8.6s |  |
| 105 | `bitmap_data` | 1000 | 16.3s |  |
| 106 | `bitmap_filter_abstract` | 6 | 8.4s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 27.9s |  |
| 108 | `bitmap_properties` | 23 | 8.4s |  |
| 109 | `bitmap_subclass` | 7 | 9.9s |  |
| 110 | `bitmap_subclass_properties` | 9 | 8.9s |  |
| 111 | `bitmap_timeline` | 9 | 8.8s |  |
| 112 | `bitmapdata_accuracy` | 1 | 43.5s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 28.4s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 9.2s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 27.8s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 28.2s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 27.3s |  |
| 118 | `bitmapdata_clone` | 13 | 8.7s |  |
| 119 | `bitmapdata_colortransform` | 0 | 8.9s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 8.3s |  |
| 121 | `bitmapdata_constr` | 22 | 8.5s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 8.8s |  |
| 123 | `bitmapdata_copychannel` | 0 | 29.4s |  |
| 124 | `bitmapdata_copypixels` | 23 | 28.6s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 8.5s |  |
| 126 | `bitmapdata_copypixels_alpha_merge` | 9 | 22.5s |  |
| 127 | `bitmapdata_copypixels_blend` | 1029 | 9.0s |  |
| 128 | `bitmapdata_copypixels_blend_over` | 1 | 8.6s |  |
| 129 | `bitmapdata_copypixels_self` | 612 | 8.6s |  |
| 130 | `bitmapdata_copypixelstobytearray` | 39 | 8.6s |  |
| 131 | `bitmapdata_dispose` | 7 | 8.5s |  |
| 132 | `bitmapdata_draw` | 0 | 28.9s |  |
| 133 | `bitmapdata_draw_alpha_erase` | 8 | 8.7s |  |
| 134 | `bitmapdata_draw_cab_quality` | 0 | 29.1s |  |
| 135 | `bitmapdata_draw_colortransform` | 0 | 27.9s |  |
| 136 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 28.1s |  |
| 137 | `bitmapdata_draw_filters` | 0 | 28.0s |  |
| 138 | `bitmapdata_draw_masks` | 0 | 8.9s |  |
| 139 | `bitmapdata_draw_rotation` | 0 | 8.8s |  |
| 140 | `bitmapdata_draw_self_via_graphic` | 0 | 8.7s |  |
| 141 | `bitmapdata_draw_stage` | 0 | 28.0s |  |
| 142 | `bitmapdata_drawwithquality` | 0 | 9.1s |  |
| 143 | `bitmapdata_embedded` | 9 | 8.9s |  |
| 144 | `bitmapdata_fillrect` | 0 | 8.7s |  |
| 145 | `bitmapdata_filter_sourcerect` | 0 | 28.4s |  |
| 146 | `bitmapdata_floodfill` | 35 | 8.5s |  |
| 147 | `bitmapdata_getpixels` | 39 | 28.1s |  |
| 148 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 149 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 150 | `bitmapdata_hittest` | 112 | 9.1s |  |
| 151 | `bitmapdata_hittest_threshold` | 18 | 8.6s |  |
| 152 | `bitmapdata_opaque` | 0 | 8.7s |  |
| 153 | `bitmapdata_pixeldissolve` | 1037 | 9.1s |  |
| 154 | `bitmapdata_pixeldissolve_image` | 0 | 8.9s |  |
| 155 | `bitmapdata_rectangle_rounding` | 16 | 8.4s |  |
| 156 | `bitmapdata_setpixels` | 286 | 8.6s |  |
| 157 | `bitmapdata_setvector` | 26 | 8.6s |  |
| 158 | `bitmapdata_sync` | 0 | 28.0s |  |
| 159 | `bitmapdata_threshold` | 176 | 9.2s |  |
| 160 | `bitmapdata_zero_size` | 8 | 8.5s |  |
| 161 | `bitnot` | 46 | 8.5s |  |
| 162 | `bitor` | 1058 | 20.5s |  |
| 163 | `bitxor` | 1058 | 20.4s |  |
| 164 | `blend_mode_null` | 1 | 8.4s |  |
| 165 | `blend_multiply_alpha` | 0 | 8.7s |  |
| 166 | `blend_scroll` | 0 | 8.7s |  |
| 167 | `blend_shader_luma_lighten` | 3 | 9.3s |  |
| 168 | `blur_filter` | 43 | 7.1s |  |
| 169 | `boolean_constr` | 32 | 7.0s |  |
| 170 | `boolean_negation` | 30 | 6.9s |  |
| 171 | `boolean_tostring` | 8 | 6.9s |  |
| 172 | `broadcast_event` | 7 | 6.7s |  |
| 173 | `button_bounds` | 1 | 6.9s |  |
| 174 | `button_hittest` | 2 | 22.1s |  |
| 175 | `button_nested_frame` | 48 | 23.1s |  |
| 176 | `button_nested_frame_simple` | 27 | 7.6s |  |
| 177 | `bytearray` | 48 | 7.9s |  |
| 178 | `bytearray_bad_symbol_class` | 3 | 7.2s |  |
| 179 | `bytearray_bad_symbol_class_other_movie` | 6 | 7.5s |  |
| 180 | `bytearray_compress` | 31 | 7.3s |  |
| 181 | `bytearray_errors` | 24 | 7.2s |  |
| 182 | `bytearray_method_serialization` | 1 | 7.1s |  |
| 183 | `bytearray_oom` | 3 | 7.2s |  |
| 184 | `bytearray_readobject_amf0` | 50 | 7.2s |  |
| 185 | `bytearray_readobject_amf3` | 53 | 7.2s |  |
| 186 | `bytearray_readutf8bytes_with_bom` | 16 | 7.3s |  |
| 187 | `bytearray_serialization` | 3 | 7.2s |  |
| 188 | `bytearray_string_null` | 19 | 7.4s |  |
| 189 | `bytearray_tostring` | 15 | 7.2s |  |
| 190 | `bytearray_utf16` | 8 | 7.1s |  |
| 191 | `bytearray_writeobject` | 24 | 7.1s |  |
| 192 | `callee_in_initializer` | 6 | 7.1s |  |
| 193 | `callproplex_class` | 1 | 7.2s |  |
| 194 | `capabilities_resolution` | 8 | 24.9s |  |
| 195 | `catch_class` | 6 | 7.1s |  |
| 196 | `catch_scope_slot` | 7 | 7.3s |  |
| 197 | `checkfilter` | 4 | 2.8s |  |
| 198 | `class_call` | 32 | 7.3s |  |
| 199 | `class_cast_call` | 14 | 7.2s |  |
| 200 | `class_enumeration` | 4 | 7.2s |  |
| 201 | `class_has_own_property` | 2 | 7.3s |  |
| 202 | `class_init_interpreter_mode` | 1 | 7.1s |  |
| 203 | `class_is` | 32 | 7.2s |  |
| 204 | `class_methods` | 5 | 7.2s |  |
| 205 | `class_object_properties` | 10 | 7.2s |  |
| 206 | `class_singleton` | 18 | 7.3s |  |
| 207 | `class_supercalls_errors` | 35 | 7.3s |  |
| 208 | `class_supercalls_mismatched` | 26 | 7.2s |  |
| 209 | `class_superclass_wrong_order` | 1 | 6.8s |  |
| 210 | `class_to_locale_string` | 2 | 6.8s |  |
| 211 | `class_to_string` | 2 | 6.7s |  |
| 212 | `class_value_of` | 2 | 6.8s |  |
| 213 | `click_block` | 5 | 22.9s |  |
| 214 | `click_invisible` | 3 | 6.8s |  |
| 215 | `closures` | 12 | 6.8s |  |
| 216 | `coerce_return_type` | 40 | 2.7s |  |
| 217 | `coerce_return_type_fail` | 2 | 6.8s |  |
| 218 | `coerce_return_void` | 3 | 6.7s |  |
| 219 | `coerce_string` | 86 | 6.9s |  |
| 220 | `coerce_string_precision` | 28 | 6.8s |  |
| 221 | `coerce_to_primitive_side_effects` | 29 | 6.8s |  |
| 222 | `color_matrix_filter` | 19 | 6.9s |  |
| 223 | `construct_errors_swf10` | 8 | 6.8s |  |
| 224 | `construct_frame_list` | 22 | 22.2s |  |
| 225 | `construct_interface` | 3 | 6.8s |  |
| 226 | `constructor_call` | 3 | 6.8s |  |
| 227 | `constructors_vs_timeline` | 5 | 22.2s |  |
| 228 | `constructprop_dynamic_primitive` | 7 | 6.8s |  |
| 229 | `constructprop_method` | 2 | 6.8s |  |
| 230 | `constructsuper_null` | 2 | 2.6s |  |
| 231 | `content_element_basic` | 50 | 7.0s |  |
| 232 | `context3d_creation` | 9 | 6.9s |  |
| 233 | `control_flow_bool` | 4 | 6.8s |  |
| 234 | `control_flow_stricteq` | 8 | 6.8s |  |
| 235 | `convert_boolean` | 30 | 6.8s |  |
| 236 | `convert_integer` | 90 | 6.9s |  |
| 237 | `convert_number` | 56 | 2.6s |  |
| 238 | `convert_uinteger` | 90 | 6.9s |  |
| 239 | `convolution_filter` | 89 | 6.9s |  |
| 240 | `core_exceptions` | 47 | 7.5s |  |
| 241 | `cpool_index_invalid_bytecode_1` | 6 | 6.8s |  |
| 242 | `cpool_index_invalid_bytecode_2` | 3 | 6.8s |  |
| 243 | `cpool_index_invalid_bytecode_3` | 1 | 6.8s |  |
| 244 | `cross_api_version_call_newer` | 12 | 7.3s |  |
| 245 | `cross_api_version_call_older` | 12 | 7.1s |  |
| 246 | `cryptscore` | 11 | 6.9s |  |
| 247 | `currency_parse_result` | 7 | 6.8s |  |
| 248 | `date` | 30 | 7.1s |  |
| 249 | `date_parse` | 36 | 6.8s |  |
| 250 | `declocal` | 46 | 8.9s |  |
| 251 | `declocal_i` | 46 | 8.8s |  |
| 252 | `decode_uri` | 71 | 9.2s |  |
| 253 | `decrement` | 46 | 8.9s |  |
| 254 | `decrement_i` | 46 | 3.4s |  |
| 255 | `default_values` | 7 | 8.8s |  |
| 256 | `delayed_symbolclass` | 28 | 28.8s |  |
| 257 | `describe_type_basic` | 152 | 9.1s |  |
| 258 | `describe_type_json` | 301 | 9.0s |  |
| 259 | `describe_type_metadata` | 125 | 8.9s |  |
| 260 | `describe_type_native` | 23 | 8.8s |  |
| 261 | `dictionary_access` | 62 | 9.1s |  |
| 262 | `dictionary_access_no_pubns` | 2 | 8.8s |  |
| 263 | `dictionary_delete` | 101 | 9.3s |  |
| 264 | `dictionary_foreach` | 42 | 9.1s |  |
| 265 | `dictionary_hasownproperty` | 63 | 9.1s |  |
| 266 | `dictionary_in` | 62 | 9.1s |  |
| 267 | `dictionary_iter_modify` | 8 | 8.9s |  |
| 268 | `dictionary_namespaces` | 36 | 8.9s |  |
| 269 | `displacement_map_filter` | 61 | 9.0s |  |
| 270 | `displayobject_alpha` | 277 | 8.8s |  |
| 271 | `displayobject_blendmode` | 0 | 29.2s |  |
| 272 | `displayobject_colortransform_nested` | 0 | 29.1s |  |
| 273 | `displayobject_early_init` | 54 | 10.7s |  |
| 274 | `displayobject_filters` | 17 | 9.1s |  |
| 275 | `displayobject_from_enterframe` | 1 | 29.2s |  |
| 276 | `displayobject_getbounds_shape` | 0 | 29.6s |  |
| 277 | `displayobject_getrect` | 16 | 9.3s |  |
| 278 | `displayobject_height` | 6052 | 29.8s |  |
| 279 | `displayobject_hittestobject` | 32 | 9.2s |  |
| 280 | `displayobject_hittestpoint` | 49 | 9.2s |  |
| 281 | `displayobject_hittestpoint_boundary` | 65 | 29.9s |  |
| 282 | `displayobject_hittestpoint_root` | 13 | 9.3s |  |
| 283 | `displayobject_invalid_floats` | 60 | 9.1s |  |
| 284 | `displayobject_invalid_props` | 3 | 9.0s |  |
| 285 | `displayobject_mask` | 3 | 9.6s |  |
| 286 | `displayobject_mask_self_referential` | 0 | 8.9s |  |
| 287 | `displayobject_metaData` | 3 | 9.0s |  |
| 288 | `displayobject_name` | 22 | 29.8s |  |
| 289 | `displayobject_name_from_timeline` | 24 | 9.2s |  |
| 290 | `displayobject_opaque_background` | 6 | 9.1s |  |
| 291 | `displayobject_parent` | 12 | 28.0s |  |
| 292 | `displayobject_root` | 24 | 8.5s |  |
| 293 | `displayobject_rotation` | 1284 | 8.6s |  |
| 294 | `displayobject_scrollrect` | 33 | 9.6s |  |
| 295 | `displayobject_set_matrix_nested` | 0 | 28.3s |  |
| 296 | `displayobject_set_name_loaded` | 3 | 8.9s |  |
| 297 | `displayobject_subclass` | 2 | 8.5s |  |
| 298 | `displayobject_transform` | 89 | 28.1s |  |
| 299 | `displayobject_visible` | 23 | 8.6s |  |
| 300 | `displayobject_width` | 4852 | 28.6s |  |
| 301 | `displayobject_x` | 614 | 8.6s |  |
| 302 | `displayobject_y` | 617 | 8.6s |  |
| 303 | `displayobject_z` | 38 | 29.1s |  |
| 304 | `displayobjectcontainer_addchild` | 32 | 8.7s |  |
| 305 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 8.5s |  |
| 306 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.8s |  |
| 307 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 8.7s |  |
| 308 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 8.8s |  |
| 309 | `displayobjectcontainer_addchildat` | 42 | 8.7s |  |
| 310 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 8.8s |  |
| 311 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 8.7s |  |
| 312 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.8s |  |
| 313 | `displayobjectcontainer_contains` | 66 | 28.6s |  |
| 314 | `displayobjectcontainer_getchildat` | 4 | 8.6s |  |
| 315 | `displayobjectcontainer_getchildbyname` | 9 | 8.6s |  |
| 316 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 8.6s |  |
| 317 | `displayobjectcontainer_getchildindex` | 28 | 8.6s |  |
| 318 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 28.4s |  |
| 319 | `displayobjectcontainer_removechild` | 10 | 8.6s |  |
| 320 | `displayobjectcontainer_removechild_errors` | 4 | 8.5s |  |
| 321 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 8.6s |  |
| 322 | `displayobjectcontainer_removechildat` | 18 | 8.5s |  |
| 323 | `displayobjectcontainer_removechildren` | 51 | 8.8s |  |
| 324 | `displayobjectcontainer_setchildindex` | 42 | 8.5s |  |
| 325 | `displayobjectcontainer_stopallmovieclips` | 2 | 28.6s |  |
| 326 | `displayobjectcontainer_swapchildren` | 42 | 8.6s |  |
| 327 | `displayobjectcontainer_swapchildrenat` | 42 | 8.6s |  |
| 328 | `displayobjectcontainer_timelineinstance` | 48 | 28.3s |  |
| 329 | `divide` | 1058 | 20.9s |  |
| 330 | `doabc_and_symbolclass_script_init_goto` | 7 | 28.3s |  |
| 331 | `doabc_and_symbolclass_script_init_normal` | 6 | 8.5s |  |
| 332 | `doabc_is_eager` | 1 | 27.9s |  |
| 333 | `documentclass` | 9 | 8.7s |  |
| 334 | `domain_memory` | 133 | 29.1s |  |
| 335 | `drag_drop` | 10 | 8.6s |  |
| 336 | `drop_shadow_filter` | 172 | 9.4s |  |
| 337 | `duplicate_defs` | 1 | 8.8s |  |
| 338 | `eager_init` | 1 | 8.8s |  |
| 339 | `east_asian_justifier_clone` | 8 | 8.8s |  |
| 340 | `edit_text_linkage` | 7 | 8.9s |  |
| 341 | `edittext_align` | 60 | 9.3s |  |
| 342 | `edittext_always_show_selection` | 0 | 28.9s |  |
| 343 | `edittext_antialiastype` | 296 | 8.9s |  |
| 344 | `edittext_at_point_methods_basic` | 16 | 10.0s |  |
| 345 | `edittext_autosize` | 39 | 9.1s |  |
| 346 | `edittext_autosize_align` | 0 | 28.8s |  |
| 347 | `edittext_autosize_height_dynamic` | 60 | 28.4s |  |
| 348 | `edittext_autosize_height_input` | 60 | 8.7s |  |
| 349 | `edittext_autosize_lazy_bounds_events` | 65 | 8.7s |  |
| 350 | `edittext_autosize_lazy_bounds_interactions` | 19 | 8.6s |  |
| 351 | `edittext_autosize_lazy_bounds_props` | 490 | 10.0s |  |
| 352 | `edittext_autosize_lazy_bounds_visual` | 0 | 29.2s |  |
| 353 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 8.9s |  |
| 354 | `edittext_bottom_scroll_v_basic` | 210 | 8.7s |  |
| 355 | `edittext_bounds_scale` | 24 | 28.0s |  |
| 356 | `edittext_bullet` | 30 | 8.8s |  |
| 357 | `edittext_default_format` | 221 | 9.1s |  |
| 358 | `edittext_default_format_empty` | 136 | 8.9s |  |
| 359 | `edittext_empty_text_format` | 7 | 8.6s |  |
| 360 | `edittext_focus_selection` | 5 | 8.5s |  |
| 361 | `edittext_font_size` | 45 | 8.7s |  |
| 362 | `edittext_format_empty_font` | 8 | 8.5s |  |
| 363 | `edittext_get_char_index_at_point` | 4 | 30.5s |  |
| 364 | `edittext_get_line_index_at_point` | 2 | 8.9s |  |
| 365 | `edittext_get_line_index_of_char` | 76 | 9.5s |  |
| 366 | `edittext_getcharboundaries` | 172 | 9.3s |  |
| 367 | `edittext_getcharboundaries_missing_glyphs` | 63 | 8.7s |  |
| 368 | `edittext_getcharboundaries_scroll` | 85 | 8.6s |  |
| 369 | `edittext_getlinemetrics` | 146 | 8.9s |  |
| 370 | `edittext_html` | 3101 | 9.1s |  |
| 371 | `edittext_html_condensewhite` | 487 | 8.6s |  |
| 372 | `edittext_html_entity` | 4 | 8.6s |  |
| 373 | `edittext_html_font_size_swf12` | 267 | 28.2s |  |
| 374 | `edittext_html_font_size_swf13` | 273 | 8.0s |  |
| 375 | `edittext_html_roundtrip` | 17 | 28.7s |  |
| 376 | `edittext_ime_focus_lost` | 9 | 28.1s |  |
| 377 | `edittext_input_control` | 12 | 8.2s |  |
| 378 | `edittext_leading` | 9 | 8.6s |  |
| 379 | `edittext_letter_spacing` | 15 | 8.6s |  |
| 380 | `edittext_line_methods` | 294 | 9.7s |  |
| 381 | `edittext_line_metrics` | 11 | 29.3s |  |
| 382 | `edittext_margins` | 25 | 8.5s |  |
| 383 | `edittext_max_scroll_h_basic` | 475 | 8.5s |  |
| 384 | `edittext_max_scroll_v_basic` | 1000 | 8.3s |  |
| 385 | `edittext_mouse_selection` | 363 | 29.4s |  |
| 386 | `edittext_mousedown` | 3 | 8.9s |  |
| 387 | `edittext_mouseenabled` | 26 | 8.5s |  |
| 388 | `edittext_newline_character` | 22 | 8.6s |  |
| 389 | `edittext_newline_stripping` | 64 | 11.3s |  |
| 390 | `edittext_newlines` | 30 | 8.6s |  |
| 391 | `edittext_paragraph_methods` | 257 | 8.4s |  |
| 392 | `edittext_paste_events` | 8 | 8.3s |  |
| 393 | `edittext_paste_maxchars` | 4 | 8.4s |  |
| 394 | `edittext_paste_restrict` | 16 | 8.1s |  |
| 395 | `edittext_restrict` | 191 | 8.2s |  |
| 396 | `edittext_restrict_events` | 22 | 8.2s |  |
| 397 | `edittext_scroll_event` | 37 | 8.6s |  |
| 398 | `edittext_scrollh` | 10 | 3.0s |  |
| 399 | `edittext_selected_text` | 9 | 8.3s |  |
| 400 | `edittext_set_html_same` | 17 | 8.4s |  |
| 401 | `edittext_set_text_vs_html` | 9 | 8.3s |  |
| 402 | `edittext_stylesheet` | 536 | 8.7s |  |
| 403 | `edittext_stylesheet_custom_tag` | 76 | 8.3s |  |
| 404 | `edittext_stylesheet_display` | 272 | 8.4s |  |
| 405 | `edittext_tag_indent` | 49 | 28.2s |  |
| 406 | `edittext_underline` | 40 | 8.7s |  |
| 407 | `edittext_width_height` | 103 | 8.8s |  |
| 408 | `edittext_wordwrap_word` | 150 | 8.7s |  |
| 409 | `edittext_wrap_breaks` | 2375 | 8.9s |  |
| 410 | `element_format_clone` | 44 | 8.5s |  |
| 411 | `element_format_constructor_order` | 64 | 3.2s |  |
| 412 | `element_format_properties` | 235 | 9.3s |  |
| 413 | `empty_bounds` | 1 | 8.1s |  |
| 414 | `encode_uri_surrogate_pair_invalid` | 8 | 8.2s |  |
| 415 | `encode_uri_surrogate_pair_swf11` | 15 | 1.9s |  |
| 416 | `equals` | 512 | 8.2s |  |
| 417 | `error_geterrormessage` | 779 | 6.1s |  |
| 418 | `error_prototype` | 15 | 6.3s |  |
| 419 | `error_stack_trace` | 45 | 6.2s |  |
| 420 | `error_stack_trace_debug_swf17` | 0 | 21.2s |  |
| 421 | `error_stack_trace_debug_swf18` | 0 | 5.8s |  |
| 422 | `error_stack_trace_edge_cases` | 6 | 6.1s |  |
| 423 | `error_stack_trace_release_swf17` | 0 | 2.2s |  |
| 424 | `error_stack_trace_release_swf18` | 0 | 6.4s |  |
| 425 | `error_throwerror` | 103 | 6.0s |  |
| 426 | `error_tostring` | 29 | 6.1s |  |
| 427 | `error_tostring_more` | 86 | 5.9s |  |
| 428 | `es3_inheritance` | 31 | 6.2s |  |
| 429 | `es4_inheritance` | 30 | 6.0s |  |
| 430 | `es4_interfaces` | 30 | 6.0s |  |
| 431 | `es4_method_binding` | 8 | 6.7s |  |
| 432 | `es4_oop_prototypes` | 14 | 6.6s |  |
| 433 | `es4_protected_inheritance` | 6 | 6.1s |  |
| 434 | `escape` | 71 | 6.4s |  |
| 435 | `escape_multi_byte` | 45 | 6.1s |  |
| 436 | `event_bubbles` | 2 | 6.0s |  |
| 437 | `event_cancelable` | 2 | 6.0s |  |
| 438 | `event_clone` | 20 | 6.2s |  |
| 439 | `event_clone_error_redispatch` | 3 | 6.0s |  |
| 440 | `event_clone_on_redispatch` | 10 | 6.1s |  |
| 441 | `event_formattostring` | 31 | 6.0s |  |
| 442 | `event_isdefaultprevented` | 12 | 6.1s |  |
| 443 | `event_target_getter` | 5 | 2.0s |  |
| 444 | `event_target_set` | 9 | 6.1s |  |
| 445 | `event_type` | 1 | 5.9s |  |
| 446 | `event_valueof_tostring` | 18 | 6.4s |  |
| 447 | `eventdispatcher_dispatchevent` | 12 | 5.9s |  |
| 448 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.0s |  |
| 449 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.1s |  |
| 450 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.9s |  |
| 451 | `eventdispatcher_dispatchevent_this` | 5 | 6.2s |  |
| 452 | `eventdispatcher_haseventlistener` | 25 | 6.0s |  |
| 453 | `eventdispatcher_interface_invoke` | 1 | 6.1s |  |
| 454 | `eventdispatcher_tostring` | 10 | 5.9s |  |
| 455 | `eventdispatcher_willtrigger` | 25 | 7.2s |  |
| 456 | `falsiness` | 30 | 7.0s |  |
| 457 | `fast_index_access` | 12 | 7.2s |  |
| 458 | `filefilter_properties` | 4 | 7.1s |  |
| 459 | `filereference_browse_cancel` | 3 | 7.1s |  |
| 460 | `filereference_browse_select` | 9 | 2.7s |  |
| 461 | `filereference_load` | 31 | 7.1s |  |
| 462 | `filereference_save` | 16 | 7.2s |  |
| 463 | `filereference_save_and_browse` | 42 | 7.1s |  |
| 464 | `filereference_save_and_load` | 22 | 7.1s |  |
| 465 | `filereference_uninitialized` | 8 | 7.0s |  |
| 466 | `filereferencelist_browse_cancel` | 6 | 7.2s |  |
| 467 | `filereferencelist_browse_select` | 7 | 7.2s |  |
| 468 | `filter_rewind` | 8 | 23.0s |  |
| 469 | `filters_array_holes` | 25 | 7.0s |  |
| 470 | `finddef` | 3 | 7.0s |  |
| 471 | `findprop_global_prototype` | 6 | 7.2s |  |
| 472 | `flash_media_video_constructor` | 156 | 7.8s |  |
| 473 | `flash_media_video_rotation_probe` | 27 | 7.1s |  |
| 474 | `flash_media_video_setter` | 40 | 7.4s |  |
| 475 | `flash_trace` | 17 | 7.2s |  |
| 476 | `flash_ui_mouse_cursor` | 35 | 7.5s |  |
| 477 | `flash_xml` | 29 | 7.2s |  |
| 478 | `flash_xml_cloneNode` | 22 | 7.1s |  |
| 479 | `flash_xml_namespace` | 109 | 7.6s |  |
| 480 | `flash_xml_removeNode` | 60 | 7.1s |  |
| 481 | `focus_events_code` | 161 | 24.1s |  |
| 482 | `focus_events_key_basic` | 132 | 23.9s |  |
| 483 | `focus_events_key_navigation` | 53 | 24.2s |  |
| 484 | `focus_events_key_same_object` | 26 | 7.3s |  |
| 485 | `focus_events_mixed_key_mouse` | 100 | 24.2s |  |
| 486 | `focus_events_mouse_basic` | 260 | 23.9s |  |
| 487 | `focus_events_mouse_focusable` | 112 | 23.9s |  |
| 488 | `focus_events_mouse_same_object` | 40 | 7.1s |  |
| 489 | `focus_remove` | 20 | 22.6s |  |
| 490 | `focus_root_movie` | 4 | 23.1s |  |
| 491 | `focus_stage` | 1 | 6.9s |  |
| 492 | `focusrect` | 18 | 8.0s |  |
| 493 | `focusrect_focuslost` | 9 | 7.2s |  |
| 494 | `focusrect_property` | 110 | 2.6s |  |
| 495 | `font_description_clone` | 14 | 7.0s |  |
| 496 | `font_embedded` | 24 | 29.0s |  |
| 497 | `font_enumeratefonts` | 41 | 9.5s |  |
| 498 | `font_enumeratefonts_filter` | 4 | 29.2s |  |
| 499 | `font_enumeratefonts_order` | 9 | 10.2s |  |
| 500 | `font_hasglyphs` | 40 | 9.3s |  |
| 501 | `font_registerfont` | 129 | 9.8s |  |
| 502 | `framelabel_constr` | 5 | 8.7s |  |
| 503 | `function_call` | 12 | 3.4s |  |
| 504 | `function_call_arguments` | 46 | 8.9s |  |
| 505 | `function_call_arguments_enumerate` | 5 | 8.7s |  |
| 506 | `function_call_coercion` | 108 | 9.2s |  |
| 507 | `function_call_default` | 6 | 8.7s |  |
| 508 | `function_call_rest` | 22 | 8.8s |  |
| 509 | `function_call_types` | 3 | 8.7s |  |
| 510 | `function_call_via_apply` | 11 | 8.7s |  |
| 511 | `function_call_via_call` | 3 | 8.7s |  |
| 512 | `function_display_anonymous` | 7 | 3.3s |  |
| 513 | `function_length` | 6 | 8.7s |  |
| 514 | `function_object` | 2 | 8.7s |  |
| 515 | `function_proto` | 5 | 8.7s |  |
| 516 | `function_proto_created` | 61 | 8.8s |  |
| 517 | `function_to_locale_string` | 4 | 8.7s |  |
| 518 | `function_to_string` | 4 | 8.7s |  |
| 519 | `function_type` | 6 | 8.8s |  |
| 520 | `function_unbound_this` | 51 | 9.0s |  |
| 521 | `function_value_of` | 4 | 8.9s |  |
| 522 | `game_input` | 4 | 9.3s |  |
| 523 | `generate_random_bytes` | 3 | 9.0s |  |
| 524 | `geom_transform` | 74 | 29.5s |  |
| 525 | `get_definition_by_name` | 11 | 8.8s |  |
| 526 | `get_qualified_class_name` | 20 | 8.8s |  |
| 527 | `get_qualified_super_class_name` | 18 | 8.8s |  |
| 528 | `get_slot_edge_cases` | 1 | 8.8s |  |
| 529 | `get_timer` | 2 | 3.3s |  |
| 530 | `getglobalslot` | 1 | 8.7s |  |
| 531 | `getouterscope` | 8 | 8.7s |  |
| 532 | `getouterscope_two_classobjects` | 13 | 9.2s |  |
| 533 | `getter_different_namespace_setter` | 2 | 8.9s |  |
| 534 | `glow_filter` | 127 | 9.2s |  |
| 535 | `goto_button_nested_framescript` | 28 | 28.8s |  |
| 536 | `goto_in_constructframe` | 12 | 30.4s |  |
| 537 | `goto_in_scene_last_frame` | 2 | 31.5s |  |
| 538 | `goto_methods` | 56 | 9.8s |  |
| 539 | `goto_methods_swfver10` | 8 | 9.5s |  |
| 540 | `goto_nested_construct_sibling` | 18 | 9.9s |  |
| 541 | `goto_nested_framescript` | 9 | 9.7s |  |
| 542 | `goto_on_orphan` | 15 | 32.0s |  |
| 543 | `gradient_bevel_filter` | 206 | 9.6s |  |
| 544 | `gradient_glow_filter` | 206 | 9.4s |  |
| 545 | `graphic_linkage` | 9 | 9.6s |  |
| 546 | `graphics_bad_direct_commands` | 5 | 10.5s |  |
| 547 | `graphics_bitmap_fill` | 0 | 32.7s |  |
| 548 | `graphics_bitmaps` | 0 | 9.8s |  |
| 549 | `graphics_direct_commands` | 0 | 9.9s |  |
| 550 | `graphics_draw_triangles` | 98 | 31.1s |  |
| 551 | `graphics_gradients` | 0 | 9.6s |  |
| 552 | `graphics_gradients_nulls` | 0 | 9.5s |  |
| 553 | `graphics_path` | 56 | 9.2s |  |
| 554 | `graphics_round_rects` | 0 | 9.0s |  |
| 555 | `graphics_simple_shapes` | 0 | 9.2s |  |
| 556 | `greaterequals` | 512 | 12.8s |  |
| 557 | `greaterthan` | 512 | 12.9s |  |
| 558 | `has_own_property` | 102 | 9.4s |  |
| 559 | `hasownproperty_namespaces` | 2 | 9.0s |  |
| 560 | `hello_world` | 1 | 8.9s |  |
| 561 | `hittest_morph` | 30 | 9.1s |  |
| 562 | `id3_info` | 8 | 29.1s |  |
| 563 | `if_eq` | 10 | 8.9s |  |
| 564 | `if_gt` | 1 | 9.1s |  |
| 565 | `if_gte` | 10 | 3.6s |  |
| 566 | `if_lt` | 1 | 1.4s |  |
| 567 | `if_lte` | 10 | 9.0s |  |
| 568 | `if_ne` | 7 | 3.5s |  |
| 569 | `if_stricteq` | 6 | 9.1s |  |
| 570 | `if_strictne` | 11 | 9.0s |  |
| 571 | `ime_linux_dead_keys` | 10 | 9.2s |  |
| 572 | `in` | 102 | 9.7s |  |
| 573 | `inclocal` | 46 | 9.3s |  |
| 574 | `inclocal_i` | 46 | 9.3s |  |
| 575 | `increment` | 46 | 8.9s |  |
| 576 | `increment_i` | 46 | 7.0s |  |
| 577 | `indexing_delete` | 75 | 6.8s |  |
| 578 | `indexof_xml` | 10 | 7.0s |  |
| 579 | `init_callee_cached` | 24 | 7.4s |  |
| 580 | `instanceof` | 58 | 7.1s |  |
| 581 | `instantiate_root_character` | 4 | 7.3s |  |
| 582 | `instantiation_on_enter_frame` | 7 | 22.4s |  |
| 583 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.8s |  |
| 584 | `int_constr` | 92 | 7.1s |  |
| 585 | `int_edge_cases` | 19 | 22.6s |  |
| 586 | `int_instanceof` | 3 | 6.8s |  |
| 587 | `int_tofixed` | 1215 | 6.8s |  |
| 588 | `int_toprecision` | 1125 | 7.0s |  |
| 589 | `int_tostring` | 3375 | 7.1s |  |
| 590 | `interactiveobject_enabled` | 25 | 6.8s |  |
| 591 | `interface_namespaces` | 78 | 7.0s |  |
| 592 | `invalid_utf8` | 12 | 7.0s |  |
| 593 | `is_finite` | 46 | 6.9s |  |
| 594 | `is_nan` | 46 | 7.0s |  |
| 595 | `is_prototype_of` | 12 | 7.0s |  |
| 596 | `issue_10221` | 2 | 7.2s |  |
| 597 | `issue_13780` | 12 | 6.8s |  |
| 598 | `issue_14901` | 1 | 6.8s |  |
| 599 | `issue_17675_edittext_paste_maxchars` | 1 | 7.0s |  |
| 600 | `issue_5292` | 5 | 6.9s |  |
| 601 | `issue_8630` | 2 | 7.0s |  |
| 602 | `issue_8630_placeremoveplace` | 15 | 7.1s |  |
| 603 | `issue_8630_placeremoveplace_scriptremove` | 16 | 6.9s |  |
| 604 | `issue_8630_scriptremove` | 11 | 6.9s |  |
| 605 | `istype` | 24 | 2.7s |  |
| 606 | `istypelate` | 58 | 7.3s |  |
| 607 | `istypelate_coerce` | 198 | 7.6s |  |
| 608 | `jpeg_loader_context` | 6 | 2.6s |  |
| 609 | `json_errors` | 9 | 22.8s |  |
| 610 | `json_parse` | 21 | 2.6s |  |
| 611 | `json_parse_errors` | 84 | 6.8s |  |
| 612 | `json_stringify` | 12 | 7.1s |  |
| 613 | `json_stringify_function` | 12 | 6.8s |  |
| 614 | `json_stringify_order` | 1 | 6.9s |  |
| 615 | `json_version_gated` | 1 | 6.8s |  |
| 616 | `key_input_80percent` | 1812 | 22.1s |  |
| 617 | `key_input_location` | 126 | 6.8s |  |
| 618 | `key_input_numpad` | 384 | 6.7s |  |
| 619 | `large_preload_from_bytes` | 51 | 24.7s |  |
| 620 | `large_preload_from_url` | 27 | 8.5s |  |
| 621 | `large_preload_image_from_bytes` | 25 | 7.2s |  |
| 622 | `lazyinit` | 17 | 6.8s |  |
| 623 | `lessequals` | 512 | 9.6s |  |
| 624 | `lessthan` | 512 | 9.6s |  |
| 625 | `loader_bitmap_transparency` | 14 | 6.9s |  |
| 626 | `loader_bytes_unknown_content` | 14 | 6.9s |  |
| 627 | `loader_child_getdefinition` | 5 | 7.0s |  |
| 628 | `loader_duplicate_class` | 48 | 8.3s |  |
| 629 | `loader_duplicate_coerce` | 3 | 7.0s |  |
| 630 | `loader_duplicate_coerce_new_domain` | 4 | 6.9s |  |
| 631 | `loader_error_in_root_ctor` | 4 | 7.0s |  |
| 632 | `loader_events` | 92 | 7.5s |  |
| 633 | `loader_image` | 8 | 7.2s |  |
| 634 | `loader_jpegxr` | 2 | 22.5s |  |
| 635 | `loader_jpegxr_alpha` | 1 | 22.2s |  |
| 636 | `loader_loadbytes_events` | 30 | 7.3s |  |
| 637 | `loader_loadbytes_invalid_png` | 4 | 6.9s |  |
| 638 | `loader_loadbytes_url` | 12 | 7.1s |  |
| 639 | `loader_loaderurl` | 6 | 7.2s |  |
| 640 | `loader_method` | 85 | 6.8s |  |
| 641 | `loader_noninteractive_try_click_root` | 5 | 22.4s |  |
| 642 | `loader_reuse` | 38 | 7.0s |  |
| 643 | `loader_try_click_root` | 16 | 7.1s |  |
| 644 | `loader_unknown_content` | 24 | 6.9s |  |
| 645 | `loader_visibility_interactive` | 1 | 6.8s |  |
| 646 | `loaderinfo_events` | 7 | 6.8s |  |
| 647 | `loaderinfo_loadurl` | 12 | 6.8s |  |
| 648 | `loaderinfo_more` | 6 | 7.0s |  |
| 649 | `loaderinfo_properties` | 18 | 22.1s |  |
| 650 | `loaderinfo_properties_not_loaded` | 23 | 6.9s |  |
| 651 | `loaderinfo_quine` | 1005 | 6.8s |  |
| 652 | `loaderinfo_root` | 10 | 6.8s |  |
| 653 | `loaderinfo_root_allows` | 2 | 6.8s |  |
| 654 | `localconnection` | 890 | 8.6s |  |
| 655 | `localconnection_send` | 4 | 20.2s |  |
| 656 | `lshift` | 1058 | 13.0s |  |
| 657 | `mask_reapply` | 1 | 20.2s |  |
| 658 | `math` | 497 | 6.0s |  |
| 659 | `matrix` | 338 | 13.1s |  |
| 660 | `matrix3d` | 57 | 20.8s |  |
| 661 | `matrix3d_append` | 16 | 5.9s |  |
| 662 | `matrix3d_append_prepend_scale` | 86 | 5.9s |  |
| 663 | `matrix3d_append_prepend_translation` | 42 | 5.9s |  |
| 664 | `matrix3d_append_rotation` | 23 | 5.9s |  |
| 665 | `matrix3d_compose` | 34 | 5.9s |  |
| 666 | `matrix3d_constructor_clone` | 15 | 5.8s |  |
| 667 | `matrix3d_copy_column` | 83 | 5.9s |  |
| 668 | `matrix3d_copy_from` | 19 | 5.9s |  |
| 669 | `matrix3d_copy_raw_data_from` | 55 | 2.1s |  |
| 670 | `matrix3d_copy_raw_data_to` | 38 | 6.1s |  |
| 671 | `matrix3d_copy_row` | 83 | 5.9s |  |
| 672 | `matrix3d_copy_to_matrix3d` | 19 | 6.0s |  |
| 673 | `matrix3d_determinant` | 182 | 6.0s |  |
| 674 | `matrix3d_interpolate` | 21 | 6.1s |  |
| 675 | `matrix3d_invert` | 18 | 6.0s |  |
| 676 | `matrix3d_position` | 19 | 5.9s |  |
| 677 | `matrix3d_precision` | 28 | 6.0s |  |
| 678 | `matrix3d_prepend` | 16 | 5.8s |  |
| 679 | `matrix3d_raw_data` | 33 | 6.1s |  |
| 680 | `matrix3d_transform_vector` | 52 | 6.2s |  |
| 681 | `matrix3d_transpose` | 5 | 5.9s |  |
| 682 | `method_association` | 5 | 5.9s |  |
| 683 | `method_without_body` | 3 | 20.3s |  |
| 684 | `missing_external_interface` | 10 | 5.9s |  |
| 685 | `modulo` | 1058 | 13.3s |  |
| 686 | `morph_shape` | 2 | 20.4s |  |
| 687 | `mouse_children` | 192 | 20.7s |  |
| 688 | `mouse_click_events` | 90 | 20.4s |  |
| 689 | `mouse_double_click_events` | 188 | 6.1s |  |
| 690 | `mouse_empty_parent` | 4 | 6.0s |  |
| 691 | `mouse_over_while_dragging` | 3 | 5.9s |  |
| 692 | `mouse_pick_avm1_root` | 2 | 20.5s |  |
| 693 | `mouse_pick_button_mode` | 2 | 6.0s |  |
| 694 | `mouse_pick_dobj_mask` | 4 | 6.2s |  |
| 695 | `mouse_pick_masking` | 7 | 29.4s |  |
| 696 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 29.9s |  |
| 697 | `mouse_pick_non_interactive_dobj_mask` | 3 | 29.8s |  |
| 698 | `mouse_pick_text` | 8 | 9.1s |  |
| 699 | `mouse_sibling` | 8 | 8.9s |  |
| 700 | `mouse_wheel_events` | 36 | 30.5s |  |
| 701 | `mouseevent_constr` | 66 | 8.8s |  |
| 702 | `mouseevent_stagexy` | 35 | 9.0s |  |
| 703 | `mouseevent_valueof_tostring` | 28 | 8.8s |  |
| 704 | `movieclip_addframescript` | 3 | 29.4s |  |
| 705 | `movieclip_addframescript_error` | 9 | 8.9s |  |
| 706 | `movieclip_child_property` | 16 | 9.0s |  |
| 707 | `movieclip_constr` | 21 | 9.0s |  |
| 708 | `movieclip_currentlabels` | 17 | 29.6s |  |
| 709 | `movieclip_currentlabels_dupes1` | 46 | 28.8s |  |
| 710 | `movieclip_currentlabels_dupes2` | 30 | 8.8s |  |
| 711 | `movieclip_currentlabels_dupes3` | 67 | 8.7s |  |
| 712 | `movieclip_currentscene` | 12 | 28.3s |  |
| 713 | `movieclip_dispatchevent` | 430 | 8.8s |  |
| 714 | `movieclip_dispatchevent_cancel` | 102 | 8.7s |  |
| 715 | `movieclip_dispatchevent_handlerorder` | 251 | 8.7s |  |
| 716 | `movieclip_dispatchevent_selfadd` | 80 | 8.6s |  |
| 717 | `movieclip_dispatchevent_target` | 899 | 8.7s |  |
| 718 | `movieclip_displayevents` | 96 | 28.5s |  |
| 719 | `movieclip_displayevents_clickgoto` | 676 | 28.7s |  |
| 720 | `movieclip_displayevents_clickgoto2` | 2001 | 9.2s |  |
| 721 | `movieclip_displayevents_clickplay` | 575 | 8.8s |  |
| 722 | `movieclip_displayevents_clicksymbol` | 562 | 3.5s |  |
| 723 | `movieclip_displayevents_constructframegoto` | 140 | 9.1s |  |
| 724 | `movieclip_displayevents_constructframeplay` | 50 | 8.9s |  |
| 725 | `movieclip_displayevents_constructframesymbol` | 144 | 8.7s |  |
| 726 | `movieclip_displayevents_dblhandler` | 21 | 8.7s |  |
| 727 | `movieclip_displayevents_enterframegoto` | 149 | 8.9s |  |
| 728 | `movieclip_displayevents_enterframeplay` | 48 | 8.7s |  |
| 729 | `movieclip_displayevents_enterframesymbol` | 149 | 28.5s |  |
| 730 | `movieclip_displayevents_exitframegoto` | 106 | 8.7s |  |
| 731 | `movieclip_displayevents_exitframeplay` | 44 | 8.7s |  |
| 732 | `movieclip_displayevents_exitframesymbol` | 135 | 8.8s |  |
| 733 | `movieclip_displayevents_looping` | 63 | 28.4s |  |
| 734 | `movieclip_displayevents_stopped` | 113 | 8.9s |  |
| 735 | `movieclip_displayevents_swap` | 96 | 3.1s |  |
| 736 | `movieclip_displayevents_timeline` | 128 | 9.0s |  |
| 737 | `movieclip_drawrect` | 54 | 27.7s |  |
| 738 | `movieclip_frameconstruct_skipped` | 9 | 8.4s |  |
| 739 | `movieclip_goto_during_frame_script` | 15 | 27.7s |  |
| 740 | `movieclip_goto_overwrite` | 14 | 28.5s |  |
| 741 | `movieclip_goto_scene_last_frame_int` | 1 | 27.9s |  |
| 742 | `movieclip_goto_scene_last_frame_label` | 1 | 3.1s |  |
| 743 | `movieclip_gotoandplay` | 15 | 27.9s |  |
| 744 | `movieclip_gotoandstop` | 13 | 8.5s |  |
| 745 | `movieclip_gotoandstop_children` | 4 | 8.6s |  |
| 746 | `movieclip_gotoandstop_framescripts1` | 4 | 8.5s |  |
| 747 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 748 | `movieclip_gotoandstop_framescripts_self` | 7 | 27.9s |  |
| 749 | `movieclip_gotoandstop_queueing` | 12 | 27.9s |  |
| 750 | `movieclip_hittest` | 67 | 8.7s |  |
| 751 | `movieclip_next_frame` | 2 | 8.6s |  |
| 752 | `movieclip_next_scene` | 6 | 27.9s |  |
| 753 | `movieclip_play` | 3 | 8.4s |  |
| 754 | `movieclip_prev_frame` | 3 | 8.3s |  |
| 755 | `movieclip_prev_scene` | 7 | 8.5s |  |
| 756 | `movieclip_properties` | 79 | 28.0s |  |
| 757 | `movieclip_queued_noop_goto_swf10` | 9 | 8.6s |  |
| 758 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 759 | `movieclip_scenes` | 11 | 8.4s |  |
| 760 | `movieclip_soundtransform` | 831 | 29.9s |  |
| 761 | `movieclip_stop` | 1 | 8.4s |  |
| 762 | `movieclip_super_is_symbol` | 20 | 8.8s |  |
| 763 | `movieclip_symbol_constr` | 8 | 8.6s |  |
| 764 | `movieclip_text_mousedown` | 1 | 8.5s |  |
| 765 | `movieclip_willtrigger` | 5 | 8.6s |  |
| 766 | `multiply` | 1058 | 20.6s |  |
| 767 | `namespace_constr` | 253 | 8.7s |  |
| 768 | `namespace_constr_args` | 1 | 8.4s |  |
| 769 | `namespace_enumeration_order` | 7 | 27.7s |  |
| 770 | `nan_scale` | 9 | 8.5s |  |
| 771 | `native_menu_basic` | 19 | 10.8s |  |
| 772 | `navigateToURL_target_normalize` | 107 | 29.9s |  |
| 773 | `negate` | 30 | 8.5s |  |
| 774 | `negative_volume_panned` | 0 | 8.8s |  |
| 775 | `nested_iteration` | 11 | 8.5s |  |
| 776 | `net_getClassByAlias` | 3 | 8.5s |  |
| 777 | `net_navigateToURL` | 57 | 8.5s |  |
| 778 | `net_stream_play_options` | 6 | 8.5s |  |
| 779 | `netconnection_close` | 55 | 26.8s |  |
| 780 | `netconnection_properties` | 78 | 8.0s |  |
| 781 | `netconnection_send_remote` | 50 | 29.7s |  |
| 782 | `netconnection_serialize_arrays` | 6 | 7.9s |  |
| 783 | `netfilterevent` | 10 | 26.6s |  |
| 784 | `netstream_client` | 10 | 8.1s |  |
| 785 | `netstream_connect` | 7 | 7.9s |  |
| 786 | `netstream_flv_date` | 4 | 8.0s |  |
| 787 | `newactivation_in_script_init` | 3 | 7.8s |  |
| 788 | `newclass_mismatched` | 4 | 7.9s |  |
| 789 | `newclass_twice` | 3 | 7.8s |  |
| 790 | `nonconflicting_declarations` | 0 | 2.8s |  |
| 791 | `null_void_types` | 8 | 8.0s |  |
| 792 | `number_autoconv` | 21 | 2.8s |  |
| 793 | `number_autoconv_amf` | 132 | 7.9s |  |
| 794 | `number_autoconv_array_sort_32bit` | 1 | 7.9s |  |
| 795 | `number_constr` | 58 | 8.0s |  |
| 796 | `number_convert_edge_cases` | 180 | 26.7s |  |
| 797 | `number_toexponential` | 378 | 8.0s |  |
| 798 | `number_toexponential2` | 35 | 2.7s |  |
| 799 | `number_tofixed` | 378 | 7.8s |  |
| 800 | `number_toprecision` | 350 | 8.0s |  |
| 801 | `obfuscated_class_names` | 3 | 7.9s |  |
| 802 | `object_enumeration` | 10 | 8.0s |  |
| 803 | `object_prototype` | 4 | 8.0s |  |
| 804 | `object_to_locale_string` | 2 | 7.9s |  |
| 805 | `object_to_string` | 2 | 7.8s |  |
| 806 | `object_value_of` | 2 | 2.6s |  |
| 807 | `op_coerce` | 54 | 8.0s |  |
| 808 | `op_coerce_x` | 54 | 8.0s |  |
| 809 | `op_escxattr` | 2 | 7.9s |  |
| 810 | `op_escxelem` | 2 | 7.9s |  |
| 811 | `op_lookupswitch` | 4 | 7.9s |  |
| 812 | `optimize_coerce` | 1 | 7.9s |  |
| 813 | `orphan_movie_complex` | 80 | 8.4s |  |
| 814 | `orphan_movie_reorder` | 111 | 27.3s |  |
| 815 | `orphan_removeobject` | 636 | 28.6s |  |
| 816 | `package_namespace` | 7 | 27.9s |  |
| 817 | `param_default_value_has_zero_cpool_index` | 1 | 27.6s |  |
| 818 | `parent_early_access_child` | 16 | 28.2s |  |
| 819 | `parse_float` | 81 | 8.7s |  |
| 820 | `parse_float_swf10` | 81 | 8.4s |  |
| 821 | `parse_int` | 135 | 9.2s |  |
| 822 | `perspective_projection` | 1443 | 28.4s |  |
| 823 | `perspective_projection_basic` | 40 | 8.6s |  |
| 824 | `pixelbender_ceil` | 77 | 8.7s |  |
| 825 | `pixelbender_conditional` | 138 | 9.0s |  |
| 826 | `pixelbender_conversions` | 270 | 8.9s |  |
| 827 | `pixelbender_dithering` | 8 | 34.3s |  |
| 828 | `pixelbender_div` | 36 | 8.6s |  |
| 829 | `pixelbender_effect_BlurredFocus` | 0 | 36.7s |  |
| 830 | `pixelbender_effect_glassDisplace` | 0 | 14.8s |  |
| 831 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 32.7s |  |
| 832 | `pixelbender_effect_smudge` | 0 | 12.1s |  |
| 833 | `pixelbender_effect_tintype` | 0 | 11.3s |  |
| 834 | `pixelbender_effect_twirl` | 0 | 12.9s |  |
| 835 | `pixelbender_eof` | 7 | 8.6s |  |
| 836 | `pixelbender_images` | 0 | 11.0s |  |
| 837 | `pixelbender_input` | 103 | 28.7s |  |
| 838 | `pixelbender_logicalnot` | 20 | 8.6s |  |
| 839 | `pixelbender_malformed_data` | 190 | 29.0s |  |
| 840 | `pixelbender_multiple_out_params` | 1 | 8.6s |  |
| 841 | `pixelbender_no_out_param` | 6 | 8.5s |  |
| 842 | `pixelbender_outputs` | 13 | 8.7s |  |
| 843 | `pixelbender_padding_bytes` | 22 | 8.6s |  |
| 844 | `pixelbender_param_qualifier` | 512 | 8.7s |  |
| 845 | `pixelbender_parameters` | 1563 | 8.9s |  |
| 846 | `pixelbender_parameters_bool` | 240 | 8.8s |  |
| 847 | `pixelbender_parameters_int_vs_bool` | 54 | 8.7s |  |
| 848 | `pixelbender_parse_errors` | 6 | 8.6s |  |
| 849 | `pixelbender_rsqrt` | 24 | 8.7s |  |
| 850 | `pixelbender_select_kinds` | 8 | 8.8s |  |
| 851 | `pixelbender_shaderdata` | 49 | 8.6s |  |
| 852 | `pixelbender_shaderdata_setter` | 99 | 9.0s |  |
| 853 | `pixelbender_sign` | 60 | 8.8s |  |
| 854 | `pixelbender_vector_output` | 11 | 8.7s |  |
| 855 | `place_and_lookup/swf10` | 33 | 8.6s |  |
| 856 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 857 | `place_multiple` | 17 | 27.7s |  |
| 858 | `place_object_replace` | 9 | 27.7s |  |
| 859 | `place_object_replace_2` | 24 | 27.5s |  |
| 860 | `place_object_same_depth_frame` | 1 | 27.4s |  |
| 861 | `point` | 132 | 9.0s |  |
| 862 | `primitive_edge_cases` | 1 | 8.3s |  |
| 863 | `primitive_keys` | 54 | 8.5s |  |
| 864 | `primitive_toString` | 277 | 8.7s |  |
| 865 | `primitive_valueOf` | 285 | 8.4s |  |
| 866 | `print_job_options` | 3 | 8.4s |  |
| 867 | `property_is_enumerable` | 114 | 9.5s |  |
| 868 | `property_is_enumerable_reset` | 23 | 8.4s |  |
| 869 | `property_priority` | 22 | 8.8s |  |
| 870 | `property_priority_chained` | 4 | 8.4s |  |
| 871 | `property_priority_definition_names_order` | 2 | 8.7s |  |
| 872 | `property_priority_three_level` | 6 | 8.6s |  |
| 873 | `propertyisenumerable_namespaces` | 6 | 8.4s |  |
| 874 | `prototype_set_null` | 7 | 8.4s |  |
| 875 | `proxy_callproperty` | 24 | 8.4s |  |
| 876 | `proxy_deleteproperty` | 64 | 8.5s |  |
| 877 | `proxy_enumeration` | 34 | 8.4s |  |
| 878 | `proxy_getproperty` | 77 | 8.5s |  |
| 879 | `proxy_hasownproperty` | 8 | 3.1s |  |
| 880 | `proxy_hasproperty` | 32 | 8.4s |  |
| 881 | `proxy_not_overridden` | 54 | 8.4s |  |
| 882 | `proxy_serialize` | 9 | 8.4s |  |
| 883 | `proxy_setproperty` | 42 | 8.5s |  |
| 884 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.3s |  |
| 885 | `qname_constr` | 32 | 8.4s |  |
| 886 | `qname_constr_namespace` | 24 | 8.5s |  |
| 887 | `qname_enumeration` | 9 | 8.4s |  |
| 888 | `qname_indexing` | 23 | 3.2s |  |
| 889 | `qname_tostring` | 25 | 8.7s |  |
| 890 | `qname_valueof` | 29 | 8.5s |  |
| 891 | `rectangle` | 1094 | 9.1s |  |
| 892 | `regexp_constr` | 148 | 8.6s |  |
| 893 | `regexp_exec` | 19 | 8.5s |  |
| 894 | `regexp_extended` | 47 | 8.4s |  |
| 895 | `regexp_multiargs` | 1 | 8.3s |  |
| 896 | `regexp_test` | 27 | 3.2s |  |
| 897 | `regexp_toString` | 10 | 8.4s |  |
| 898 | `register_script_refresh` | 35 | 28.0s |  |
| 899 | `remove_child_clear_field` | 88 | 28.4s |  |
| 900 | `remove_dobj` | 3 | 28.1s |  |
| 901 | `resolve_order` | 4 | 8.5s |  |
| 902 | `responder_null_callbacks` | 1 | 28.0s |  |
| 903 | `rng` | 1 | 9.8s |  |
| 904 | `rootless` | 42 | 8.5s |  |
| 905 | `rshift` | 1058 | 20.6s |  |
| 906 | `rtqname_not_namespace` | 12 | 8.5s |  |
| 907 | `sandbox_type_inherited` | 2 | 8.7s |  |
| 908 | `sandbox_type_local_file` | 1 | 8.5s |  |
| 909 | `sandbox_type_local_network` | 1 | 8.3s |  |
| 910 | `scene_constr` | 8 | 8.5s |  |
| 911 | `scope_optimizations` | 4 | 8.4s |  |
| 912 | `scopes_dont_cache/order-1` | 1 | 27.8s |  |
| 913 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 914 | `security_domain_current` | 2 | 8.5s |  |
| 915 | `selection` | 239 | 9.4s |  |
| 916 | `set_local_0` | 31 | 3.3s |  |
| 917 | `set_property_is_enumerable` | 85 | 9.0s |  |
| 918 | `shaderparameter_value` | 4 | 8.6s |  |
| 919 | `shape_drawrect` | 54 | 8.7s |  |
| 920 | `shared_object_no_root` | 3 | 8.5s |  |
| 921 | `simplebutton_added_to_stage` | 45 | 28.6s |  |
| 922 | `simplebutton_childevents` | 86 | 28.7s |  |
| 923 | `simplebutton_childevents_nested` | 54 | 8.8s |  |
| 924 | `simplebutton_childevents_sprite` | 13 | 8.7s |  |
| 925 | `simplebutton_childprops` | 144 | 8.8s |  |
| 926 | `simplebutton_childshuffle` | 23 | 8.4s |  |
| 927 | `simplebutton_constr` | 36 | 8.8s |  |
| 928 | `simplebutton_constr_childevents` | 48 | 8.8s |  |
| 929 | `simplebutton_constr_params` | 42 | 8.6s |  |
| 930 | `simplebutton_mouseenabled` | 26 | 8.5s |  |
| 931 | `simplebutton_multi_children` | 19 | 8.8s |  |
| 932 | `simplebutton_soundtransform` | 887 | 30.1s |  |
| 933 | `simplebutton_structure` | 27 | 8.8s |  |
| 934 | `simplebutton_symbolclass` | 68 | 9.0s |  |
| 935 | `slot_disp_id_shared_numbering` | 1 | 27.9s |  |
| 936 | `slots_force_autoassigned` | 1 | 28.3s |  |
| 937 | `socket_after_disconnect` | 1 | 8.6s |  |
| 938 | `socket_close` | 2 | 8.5s |  |
| 939 | `socket_connect` | 4 | 8.6s |  |
| 940 | `socket_errors` | 56 | 9.2s |  |
| 941 | `socket_read_big` | 48 | 8.8s |  |
| 942 | `socket_read_little` | 48 | 3.1s |  |
| 943 | `socket_read_write_object` | 8 | 8.5s |  |
| 944 | `socket_write_big` | 15 | 8.8s |  |
| 945 | `socket_write_little` | 14 | 8.5s |  |
| 946 | `sound_constructor_with_args` | 6 | 8.7s |  |
| 947 | `sound_embeddedprops` | 26 | 8.7s |  |
| 948 | `sound_play` | 19 | 8.9s |  |
| 949 | `sound_rootless` | 7 | 8.8s |  |
| 950 | `sound_valueof` | 33 | 8.8s |  |
| 951 | `soundchannel_soundtransform` | 835 | 31.8s |  |
| 952 | `soundchannel_soundtransform_exists` | 5 | 29.9s |  |
| 953 | `soundchannel_stop` | 8 | 29.8s |  |
| 954 | `soundmixer_buffertime` | 5 | 8.8s |  |
| 955 | `soundmixer_soundtransform` | 900 | 11.1s |  |
| 956 | `soundmixer_stopall` | 6 | 29.2s |  |
| 957 | `soundtransform` | 442 | 14.8s |  |
| 958 | `space_justifier_clone` | 12 | 9.0s |  |
| 959 | `sprite_with_frames` | 0 | 30.9s |  |
| 960 | `stage3d_agal_cross_product` | 0 | 12.2s |  |
| 961 | `stage3d_agal_upload_errors` | 66 | 11.8s |  |
| 962 | `stage3d_bitmap` | 0 | 35.0s |  |
| 963 | `stage3d_blend` | 81 | 34.1s |  |
| 964 | `stage3d_context3d_string_args` | 158 | 10.1s |  |
| 965 | `stage3d_errors` | 7 | 9.0s |  |
| 966 | `stage3d_errors_atf` | 3 | 10.4s |  |
| 967 | `stage3d_errors_swf_29` | 6 | 9.1s |  |
| 968 | `stage3d_float1_index` | 0 | 32.0s |  |
| 969 | `stage3d_fractal` | 0 | 32.7s |  |
| 970 | `stage3d_ignore_sampler_override` | 0 | 32.5s |  |
| 971 | `stage3d_multistage_triangle` | 3 | 11.8s |  |
| 972 | `stage3d_program_constants_bytearray_be` | 0 | 34.3s |  |
| 973 | `stage3d_program_constants_bytearray_le` | 0 | 26.0s |  |
| 974 | `stage3d_program_constants_invalid_input` | 21 | 22.9s |  |
| 975 | `stage3d_raytrace` | 0 | 43.6s |  |
| 976 | `stage3d_rotating_cube` | 0 | 9.4s |  |
| 977 | `stage3d_sampler` | 0 | 8.9s |  |
| 978 | `stage3d_sampler_partial_upload` | 0 | 8.9s |  |
| 979 | `stage3d_stencil` | 0 | 25.0s |  |
| 980 | `stage3d_texture` | 0 | 13.1s |  |
| 981 | `stage3d_texture_bytearray` | 0 | 10.0s |  |
| 982 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.4s |  |
| 983 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.3s |  |
| 984 | `stage3d_triangle` | 0 | 8.9s |  |
| 985 | `stage3d_triangle_bytes4` | 0 | 8.9s |  |
| 986 | `stage3d_triangle_float1` | 0 | 8.8s |  |
| 987 | `stage3d_triangle_index_upload` | 0 | 8.9s |  |
| 988 | `stage3d_x_y` | 22 | 6.8s |  |
| 989 | `stage_access` | 10 | 6.9s |  |
| 990 | `stage_display_state` | 6 | 6.8s |  |
| 991 | `stage_displayobject_properties` | 24 | 6.8s |  |
| 992 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.8s |  |
| 993 | `stage_framerate_nan` | 7 | 6.8s |  |
| 994 | `stage_framerate_negative` | 6 | 6.8s |  |
| 995 | `stage_framerate_zero` | 6 | 6.8s |  |
| 996 | `stage_invalidate` | 38 | 7.0s |  |
| 997 | `stage_loaderinfo_properties` | 24 | 22.2s |  |
| 998 | `stage_mousechildren` | 2 | 6.8s |  |
| 999 | `stage_mouseenabled` | 15 | 6.8s |  |
| 1000 | `stage_overriden_setters` | 31 | 6.9s |  |
| 1001 | `stage_properties` | 30 | 6.8s |  |
| 1002 | `stage_properties2` | 213 | 6.9s |  |
| 1003 | `stage_scale_factor` | 12 | 26.0s |  |
| 1004 | `stage_stage3Ds_vector` | 1 | 6.7s |  |
| 1005 | `static_length` | 24 | 6.9s |  |
| 1006 | `static_text` | 3 | 7.0s |  |
| 1007 | `static_var_with_this_in_ctor` | 2 | 6.8s |  |
| 1008 | `statictext_text` | 8 | 6.9s |  |
| 1009 | `stored_properties` | 11 | 6.8s |  |
| 1010 | `strict_equality` | 34 | 6.8s |  |
| 1011 | `string_call` | 13 | 6.8s |  |
| 1012 | `string_case` | 23 | 6.9s |  |
| 1013 | `string_char_at` | 27 | 6.8s |  |
| 1014 | `string_char_code_at` | 28 | 2.5s |  |
| 1015 | `string_concat_fromcharcode` | 37 | 30.0s |  |
| 1016 | `string_constr` | 25 | 29.8s |  |
| 1017 | `string_indexof_lastindexof` | 87 | 9.1s |  |
| 1018 | `string_length` | 16 | 8.8s |  |
| 1019 | `string_locale_compare` | 39 | 9.2s |  |
| 1020 | `string_match` | 51 | 9.1s |  |
| 1021 | `string_relational_compare` | 4 | 8.8s |  |
| 1022 | `string_replace` | 51 | 9.0s |  |
| 1023 | `string_search` | 41 | 9.1s |  |
| 1024 | `string_slice_substr_substring` | 170 | 10.1s |  |
| 1025 | `string_split` | 29 | 8.9s |  |
| 1026 | `string_substr_negative` | 21 | 8.9s |  |
| 1027 | `string_substr_weird` | 182 | 8.9s |  |
| 1028 | `stylesheet` | 221 | 9.4s |  |
| 1029 | `stylesheet_parse_color` | 69 | 8.8s |  |
| 1030 | `stylesheet_transform` | 307 | 9.1s |  |
| 1031 | `sub_super_same_field` | 12 | 3.4s |  |
| 1032 | `subclass_superclass_linked_symbol` | 4 | 9.4s |  |
| 1033 | `subtract` | 1058 | 21.2s |  |
| 1034 | `super_get_call` | 12 | 8.8s |  |
| 1035 | `supercall_two_classobjects` | 2 | 8.8s |  |
| 1036 | `supercalls_coerce` | 8 | 8.9s |  |
| 1037 | `supercalls_weird` | 2 | 8.6s |  |
| 1038 | `superinterface_call` | 20 | 8.9s |  |
| 1039 | `superinterface_instanceof` | 18 | 8.8s |  |
| 1040 | `swf8` | 1 | 8.8s |  |
| 1041 | `swf_10_queued_goto_scripts_construct` | 52 | 29.9s |  |
| 1042 | `swf_9_goto_in_enter_frame` | 17 | 8.9s |  |
| 1043 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.8s |  |
| 1044 | `swf_9_queued_goto_scripts` | 6 | 29.4s |  |
| 1045 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 1046 | `swf_9_versioning` | 2 | 8.9s |  |
| 1047 | `swf_wrong_frame_count` | 38 | 9.3s |  |
| 1048 | `swf_wrong_frame_count_isplaying` | 22 | 8.9s |  |
| 1049 | `symbol_class_binary_data` | 8 | 8.9s |  |
| 1050 | `symbol_class_conflict` | 4 | 9.5s |  |
| 1051 | `symbol_class_root_not_zero` | 1 | 8.8s |  |
| 1052 | `symbolclass_invalid_utf8` | 2 | 8.9s |  |
| 1053 | `system_exit` | 3 | 8.9s |  |
| 1054 | `system_setclipboard_null` | 1 | 8.8s |  |
| 1055 | `tab_ordering_arrows` | 998 | 14.6s |  |
| 1056 | `tab_ordering_automatic_advanced` | 184 | 0.9s |  |
| 1057 | `tab_ordering_automatic_basic` | 45 | 14.8s |  |
| 1058 | `tab_ordering_children` | 116 | 0.9s |  |
| 1059 | `tab_ordering_custom_basic` | 34 | 0.9s |  |
| 1060 | `tab_ordering_stage_tab_children` | 32 | 0.9s |  |
| 1061 | `tab_ordering_stage_tab_children_remove_root` | 5 | 0.9s |  |
| 1062 | `tab_ordering_tabbable` | 47 | 0.9s |  |
| 1063 | `tabstop_properties` | 105 | 13.9s |  |
| 1064 | `text_element_basic` | 34 | 0.9s |  |
| 1065 | `text_engine_fontdescription` | 27 | 0.9s |  |
| 1066 | `text_engine_groupelement` | 64 | 0.8s |  |
| 1067 | `text_run` | 7 | 0.8s |  |
| 1068 | `textblock_createline_errors` | 23 | 0.8s |  |
| 1069 | `textblock_createline_fte` | 9 | 13.9s |  |
| 1070 | `textblock_properties` | 118 | 0.9s |  |
| 1071 | `textbox_click` | 37 | 14.8s |  |
| 1072 | `textfield_event` | 66 | 0.9s |  |
| 1073 | `textfield_focusin_event` | 9 | 0.9s |  |
| 1074 | `textfield_input_dead_keys_windows` | 15 | 0.9s |  |
| 1075 | `textfield_input_events` | 25 | 8.8s |  |
| 1076 | `textfield_unload` | 39 | 14.4s |  |
| 1077 | `textformat` | 1134 | 0.9s |  |
| 1078 | `textformat_display` | 14 | 0.9s |  |
| 1079 | `textformat_font_max_length` | 4 | 0.9s |  |
| 1080 | `textline_inapplicable_properties` | 10 | 0.9s |  |
| 1081 | `textline_name` | 1 | 0.9s |  |
| 1082 | `textline_raw_text_length` | 30 | 0.9s |  |
| 1083 | `textline_splitting_basic` | 76 | 0.9s |  |
| 1084 | `textline_throwerror` | 30 | 0.9s |  |
| 1085 | `textline_validity` | 162 | 0.9s |  |
| 1086 | `throw` | 3 | 0.9s |  |
| 1087 | `timeline_scripts` | 3 | 13.9s |  |
| 1088 | `timer` | 90 | 1.0s |  |
| 1089 | `timer_events` | 3 | 0.8s |  |
| 1090 | `timer_finished` | 11 | 0.9s |  |
| 1091 | `timer_invalid_delay` | 30 | 0.8s |  |
| 1092 | `timer_reset` | 8 | 27.8s |  |
| 1093 | `timer_setdelay` | 5 | 27.7s |  |
| 1094 | `trace` | 12 | 7.6s |  |
| 1095 | `truthiness` | 30 | 7.7s |  |
| 1096 | `try_catch` | 11 | 7.6s |  |
| 1097 | `try_catch_typed` | 12 | 7.6s |  |
| 1098 | `typeof` | 30 | 7.9s |  |
| 1099 | `uint_constr` | 92 | 7.8s |  |
| 1100 | `uint_tofixed` | 1215 | 7.3s |  |
| 1101 | `uint_toprecision` | 1125 | 7.8s |  |
| 1102 | `uint_tostring` | 3375 | 7.7s |  |
| 1103 | `uncaught_error_basic` | 2 | 7.3s |  |
| 1104 | `unchecked_function` | 15 | 7.4s |  |
| 1105 | `unescape` | 28 | 7.4s |  |
| 1106 | `url_loader` | 25 | 7.6s |  |
| 1107 | `url_vars` | 27 | 7.6s |  |
| 1108 | `urlrequest` | 18 | 2.2s |  |
| 1109 | `urlstream_basic` | 5 | 7.4s |  |
| 1110 | `urshift` | 1058 | 19.3s |  |
| 1111 | `utils3d` | 7 | 2.1s |  |
| 1112 | `vector3d` | 397 | 12.0s |  |
| 1113 | `vector3d_near_equals` | 80 | 7.5s |  |
| 1114 | `vector_class` | 36 | 7.8s |  |
| 1115 | `vector_class_call` | 11 | 7.7s |  |
| 1116 | `vector_coercion` | 66 | 8.3s |  |
| 1117 | `vector_concat` | 90 | 8.0s |  |
| 1118 | `vector_constr` | 107 | 8.1s |  |
| 1119 | `vector_enumeration` | 5 | 7.4s |  |
| 1120 | `vector_every` | 92 | 8.2s |  |
| 1121 | `vector_filter` | 95 | 8.3s |  |
| 1122 | `vector_holes` | 24 | 7.5s |  |
| 1123 | `vector_indexof` | 302 | 12.2s |  |
| 1124 | `vector_insertat` | 270 | 8.6s |  |
| 1125 | `vector_int_access` | 4 | 7.4s |  |
| 1126 | `vector_int_delete` | 11 | 7.4s |  |
| 1127 | `vector_join` | 58 | 7.8s |  |
| 1128 | `vector_lastindexof` | 302 | 7.3s |  |
| 1129 | `vector_legacy` | 10 | 7.6s |  |
| 1130 | `vector_map` | 85 | 8.2s |  |
| 1131 | `vector_object_final` | 1 | 7.5s |  |
| 1132 | `vector_object_toString` | 10 | 28.7s |  |
| 1133 | `vector_pushpop` | 255 | 29.8s |  |
| 1134 | `vector_reborrow_bug` | 10 | 8.8s |  |
| 1135 | `vector_removeat` | 172 | 9.9s |  |
| 1136 | `vector_reverse` | 232 | 9.9s |  |
| 1137 | `vector_shiftunshift` | 252 | 8.8s |  |
| 1138 | `vector_slice` | 331 | 10.5s |  |
| 1139 | `vector_sort` | 905 | 17.6s |  |
| 1140 | `vector_splice` | 693 | 12.5s |  |
| 1141 | `vector_splice_fixed_bug_compat` | 4 | 9.0s |  |
| 1142 | `vector_tostring` | 79 | 9.5s |  |
| 1143 | `verification` | 8 | 9.0s |  |
| 1144 | `verify_abnormal_loop` | 1 | 8.7s |  |
| 1145 | `verify_dxns_without_flag` | 3 | 9.2s |  |
| 1146 | `verify_exception_target_two_jumps` | 1 | 8.8s |  |
| 1147 | `verify_exception_targets_edge_case` | 1 | 8.8s |  |
| 1148 | `verify_illegal_opcode` | 1 | 3.7s |  |
| 1149 | `verify_jump_to_middle_of_op` | 1 | 9.0s |  |
| 1150 | `verify_lookup_switch_edge_case` | 1 | 8.8s |  |
| 1151 | `verify_method_info_oob` | 1 | 1.3s |  |
| 1152 | `verify_stack` | 5 | 8.8s |  |
| 1153 | `verify_typecheck` | 4 | 8.9s |  |
| 1154 | `verify_unreachable_exception` | 2 | 8.7s |  |
| 1155 | `versioned_isplaying` | 2 | 8.8s |  |
| 1156 | `virtual_properties` | 16 | 3.4s |  |
| 1157 | `with` | 4 | 8.8s |  |
| 1158 | `wrong_arg_count` | 7 | 9.0s |  |
| 1159 | `xml_abstract_equality` | 36 | 9.1s |  |
| 1160 | `xml_advanced` | 52 | 8.9s |  |
| 1161 | `xml_appendchild` | 10 | 8.8s |  |
| 1162 | `xml_appendchild_swf_v21` | 13 | 3.6s |  |
| 1163 | `xml_as_attribute` | 9 | 8.7s |  |
| 1164 | `xml_attribute` | 35 | 8.9s |  |
| 1165 | `xml_attribute_name` | 40 | 8.8s |  |
| 1166 | `xml_basic` | 33 | 8.9s |  |
| 1167 | `xml_child` | 25 | 8.9s |  |
| 1168 | `xml_childindex` | 7 | 8.9s |  |
| 1169 | `xml_children` | 43 | 9.4s |  |
| 1170 | `xml_class_call` | 9 | 8.8s |  |
| 1171 | `xml_contains` | 197 | 9.0s |  |
| 1172 | `xml_copy` | 20 | 28.3s |  |
| 1173 | `xml_ctor_from_tostring` | 23 | 28.4s |  |
| 1174 | `xml_delete` | 114 | 8.8s |  |
| 1175 | `xml_descendants` | 83 | 8.8s |  |
| 1176 | `xml_duplicate_attribute` | 14 | 8.7s |  |
| 1177 | `xml_elements` | 6 | 8.7s |  |
| 1178 | `xml_equals_namespace_check` | 2 | 8.7s |  |
| 1179 | `xml_explicit_use_namespace` | 5 | 8.7s |  |
| 1180 | `xml_getdescendants_qname` | 21 | 8.7s |  |
| 1181 | `xml_has_property_via_in` | 26 | 8.7s |  |
| 1182 | `xml_hasownproperty` | 6 | 8.7s |  |
| 1183 | `xml_ignore_white` | 6 | 8.7s |  |
| 1184 | `xml_length` | 2 | 8.7s |  |
| 1185 | `xml_list_as_attribute` | 9 | 8.7s |  |
| 1186 | `xml_list_concat` | 20 | 8.7s |  |
| 1187 | `xml_list_ctor_errors` | 34 | 8.7s |  |
| 1188 | `xml_list_delete_clear_parent` | 6 | 8.7s |  |
| 1189 | `xml_list_enumerate` | 4 | 8.6s |  |
| 1190 | `xml_methods_settings` | 3 | 8.7s |  |
| 1191 | `xml_mismatched_tag` | 37 | 8.8s |  |
| 1192 | `xml_namespace` | 39 | 8.7s |  |
| 1193 | `xml_namespace_methods` | 245 | 8.8s |  |
| 1194 | `xml_namespaced_property` | 7 | 8.7s |  |
| 1195 | `xml_no_namespace` | 1 | 8.7s |  |
| 1196 | `xml_nodekind` | 3 | 8.7s |  |
| 1197 | `xml_normalize` | 35 | 8.8s |  |
| 1198 | `xml_notification_bubbling` | 361 | 8.7s |  |
| 1199 | `xml_parent` | 8 | 8.7s |  |
| 1200 | `xml_set_children` | 17 | 8.8s |  |
| 1201 | `xml_set_name` | 34 | 8.7s |  |
| 1202 | `xml_settings` | 6 | 3.3s |  |
| 1203 | `xml_simple_complex_content` | 47 | 8.7s |  |
| 1204 | `xml_socket` | 11 | 8.8s |  |
| 1205 | `xml_text` | 7 | 8.7s |  |
| 1206 | `xml_tostring` | 6 | 8.7s |  |
| 1207 | `xml_tostring_namespace` | 12 | 8.6s |  |
| 1208 | `xml_unescaping` | 23 | 8.8s |  |
| 1209 | `xml_weird_ignores` | 54 | 3.4s |  |
| 1210 | `xml_wildcard` | 11 | 8.7s |  |
| 1211 | `xmldocument` | 254 | 8.8s |  |
| 1212 | `xmlnode` | 3540 | 8.9s |  |
| 1213 | `zero_frame_clip` | 3 | 9.3s |  |

## Ruffle-Matched Tests

**36 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.1s |  |
| 3 | `blend_transform` | 1 | 1 | 8.8s |  |
| 4 | `bounds_mode` | 6 | 6 | 7.3s |  |
| 5 | `coerce_property` | 3 | 3 | 6.9s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.8s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 28.7s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 28.3s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 8.8s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 9.0s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 8.8s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 8.7s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 16.4s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 6.2s |  |
| 15 | `event_handler_exception` | 4 | 4 | 5.9s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 8.8s |  |
| 17 | `goto_framescript_queued/swf13` | 42 | 42 | 1.5s |  |
| 18 | `graphics_draw_path` | 50 | 50 | 31.4s |  |
| 19 | `groupelement_text` | 2 | 2 | 9.1s |  |
| 20 | `int_toexponential` | 76 | 76 | 7.0s |  |
| 21 | `json_parse_numbers` | 4 | 79 | 6.9s |  |
| 22 | `loader_events_2` | 30 | 30 | 7.2s |  |
| 23 | `matrix3d_recompose_edge_cases` | 8 | 85 | 6.2s |  |
| 24 | `number_convert_errors` | 706 | 706 | 8.2s |  |
| 25 | `simplebutton_childevents_script_order` | 4 | 4 | 8.8s |  |
| 26 | `slot_holes_fail` | 1 | 1 | 8.5s |  |
| 27 | `slot_id_exceeds_trait_count` | 1 | 1 | 28.3s |  |
| 28 | `soundchannel_position` | 74 | 74 | 29.8s |  |
| 29 | `soundchannel_soundcomplete` | 10 | 10 | 9.3s |  |
| 30 | `sprite_dropTarget` | 15 | 15 | 9.1s |  |
| 31 | `swf_9_goto_in_construct_frame` | 12 | 12 | 29.8s |  |
| 32 | `textblock_line_changes` | 44 | 44 | 0.9s |  |
| 33 | `textblock_releaselines` | 4 | 4 | 0.9s |  |
| 34 | `uint_toexponential` | 100 | 100 | 7.7s |  |
| 35 | `uncaught_errors_stringified` | 15 | 15 | 7.5s |  |
| 36 | `weird_superinterface_properties` | 1 | 1 | 8.8s |  |

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

**25 tests** with output mismatch, sorted by match rate (best first)

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
| 22 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 23 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 24 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 25 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
