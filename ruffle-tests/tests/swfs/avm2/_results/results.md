# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-13 08:50 UTC

**Git SHA**: `bdf734c46c`

**Run Duration**: 206m 35s

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
| 1 | `abstract_classes` | 132 | 26.9s |  |
| 2 | `accessibility` | 1 | 7.1s |  |
| 3 | `accessibilityimplementation` | 18 | 26.9s |  |
| 4 | `activation_class` | 6 | 7.2s |  |
| 5 | `add` | 1058 | 18.8s |  |
| 6 | `agal_compiler` | 13 | 9.4s |  |
| 7 | `air_datagram_socket` | 1 | 9.1s |  |
| 8 | `air_hidden_lookup` | 2 | 7.0s |  |
| 9 | `air_ifilepromise` | 1 | 7.0s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 7.1s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.5s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.5s |  |
| 13 | `all_classes/display/swf10` | 2569 | 7.1s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.6s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.6s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.6s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.6s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.6s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 7.1s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.5s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.5s |  |
| 22 | `all_classes/errors/swf10` | 140 | 7.1s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.5s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.5s |  |
| 25 | `all_classes/events/swf10` | 1638 | 7.1s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.5s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.5s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.6s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.5s |  |
| 30 | `all_classes/security/swf11` | 3 | 7.0s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.5s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.5s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.5s |  |
| 34 | `all_classes/xml/swf30` | 116 | 7.1s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.5s |  |
| 36 | `amf_array_serialization` | 17 | 29.1s |  |
| 37 | `amf_custom_obj` | 26 | 7.1s |  |
| 38 | `amf_dictionary` | 9 | 7.0s |  |
| 39 | `amf_function` | 46 | 7.1s |  |
| 40 | `amf_invalid_date` | 2 | 7.0s |  |
| 41 | `amf_missing_prop` | 6 | 7.1s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 7.0s |  |
| 43 | `amf_setter_error` | 8 | 7.2s |  |
| 44 | `amf_vector` | 40 | 19.0s |  |
| 45 | `amf_xml` | 6 | 5.3s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 5.6s |  |
| 47 | `application_domain` | 4 | 5.0s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 19.2s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 5.0s |  |
| 50 | `array_access` | 18 | 5.2s |  |
| 51 | `array_access_interpreter` | 4 | 5.0s |  |
| 52 | `array_access_no_pubns` | 2 | 5.0s |  |
| 53 | `array_concat` | 41 | 5.4s |  |
| 54 | `array_constr` | 10 | 5.1s |  |
| 55 | `array_delete` | 44 | 5.4s |  |
| 56 | `array_enumeration` | 10 | 5.2s |  |
| 57 | `array_enumeration_elements` | 11 | 5.2s |  |
| 58 | `array_every` | 8 | 5.3s |  |
| 59 | `array_filter` | 6 | 5.1s |  |
| 60 | `array_foreach` | 18 | 5.2s |  |
| 61 | `array_hasownproperty` | 11 | 5.0s |  |
| 62 | `array_holes` | 9 | 5.3s |  |
| 63 | `array_index_max` | 84 | 5.1s |  |
| 64 | `array_indexof` | 25 | 5.1s |  |
| 65 | `array_join` | 26 | 5.3s |  |
| 66 | `array_lastindexof` | 29 | 5.0s |  |
| 67 | `array_length` | 14 | 5.2s |  |
| 68 | `array_literal` | 3 | 5.1s |  |
| 69 | `array_map` | 8 | 1.4s |  |
| 70 | `array_pop` | 52 | 5.1s |  |
| 71 | `array_push` | 24 | 5.0s |  |
| 72 | `array_reborrow_bug` | 6 | 5.0s |  |
| 73 | `array_reverse` | 28 | 5.1s |  |
| 74 | `array_shift` | 51 | 1.8s |  |
| 75 | `array_slice` | 39 | 5.4s |  |
| 76 | `array_some` | 8 | 5.5s |  |
| 77 | `array_sort` | 297 | 5.7s |  |
| 78 | `array_sort_fun_swf12` | 2 | 5.1s |  |
| 79 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 80 | `array_sort_random` | 210 | 5.5s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 5.0s |  |
| 82 | `array_sorton` | 545 | 5.5s |  |
| 83 | `array_sparse_ops` | 41 | 5.2s |  |
| 84 | `array_splice` | 133 | 5.4s |  |
| 85 | `array_splice2` | 428 | 21.4s |  |
| 86 | `array_splice_types` | 48 | 5.9s |  |
| 87 | `array_storage` | 8 | 21.2s |  |
| 88 | `array_tolocalestring` | 9 | 5.8s |  |
| 89 | `array_tostring` | 12 | 5.9s |  |
| 90 | `array_unshift` | 24 | 5.8s |  |
| 91 | `array_valueof` | 9 | 5.9s |  |
| 92 | `array_vector_null_callback` | 10 | 5.9s |  |
| 93 | `astype` | 28 | 5.9s |  |
| 94 | `astypelate` | 24 | 5.9s |  |
| 95 | `astypelate_propagates` | 1 | 6.0s |  |
| 96 | `asymmetric_key_events` | 11 | 6.1s |  |
| 97 | `automation_classes` | 122 | 6.1s |  |
| 98 | `av_classes` | 340 | 6.1s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 6.0s |  |
| 100 | `avm2_catchup_dobj` | 158 | 6.3s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 68.7s |  |
| 102 | `bevel_filter` | 187 | 6.1s |  |
| 103 | `bitand` | 1058 | 14.9s |  |
| 104 | `bitmap_constr` | 17 | 6.0s |  |
| 105 | `bitmap_data` | 1000 | 12.3s |  |
| 106 | `bitmap_filter_abstract` | 6 | 5.9s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 21.7s |  |
| 108 | `bitmap_properties` | 23 | 5.9s |  |
| 109 | `bitmap_subclass` | 7 | 7.0s |  |
| 110 | `bitmap_subclass_properties` | 9 | 6.2s |  |
| 111 | `bitmap_timeline` | 9 | 5.9s |  |
| 112 | `bitmapdata_accuracy` | 1 | 37.9s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 21.4s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.1s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 21.5s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 21.6s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 21.3s |  |
| 118 | `bitmapdata_clone` | 13 | 5.9s |  |
| 119 | `bitmapdata_colortransform` | 0 | 6.1s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 5.8s |  |
| 121 | `bitmapdata_constr` | 22 | 5.9s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 6.2s |  |
| 123 | `bitmapdata_copychannel` | 0 | 22.7s |  |
| 124 | `bitmapdata_copypixels` | 23 | 21.4s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 5.9s |  |
| 126 | `bitmapdata_copypixels_alpha_merge` | 9 | 21.5s |  |
| 127 | `bitmapdata_copypixels_blend` | 1029 | 7.9s |  |
| 128 | `bitmapdata_copypixels_blend_over` | 1 | 7.3s |  |
| 129 | `bitmapdata_copypixels_self` | 612 | 7.3s |  |
| 130 | `bitmapdata_copypixelstobytearray` | 39 | 7.2s |  |
| 131 | `bitmapdata_dispose` | 7 | 7.2s |  |
| 132 | `bitmapdata_draw` | 0 | 26.6s |  |
| 133 | `bitmapdata_draw_alpha_erase` | 8 | 7.3s |  |
| 134 | `bitmapdata_draw_cab_quality` | 0 | 27.9s |  |
| 135 | `bitmapdata_draw_colortransform` | 0 | 26.5s |  |
| 136 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.7s |  |
| 137 | `bitmapdata_draw_filters` | 0 | 26.4s |  |
| 138 | `bitmapdata_draw_masks` | 0 | 7.2s |  |
| 139 | `bitmapdata_draw_rotation` | 0 | 7.3s |  |
| 140 | `bitmapdata_draw_self_via_graphic` | 0 | 7.2s |  |
| 141 | `bitmapdata_draw_stage` | 0 | 26.5s |  |
| 142 | `bitmapdata_drawwithquality` | 0 | 7.5s |  |
| 143 | `bitmapdata_embedded` | 9 | 7.4s |  |
| 144 | `bitmapdata_fillrect` | 0 | 7.3s |  |
| 145 | `bitmapdata_filter_sourcerect` | 0 | 26.5s |  |
| 146 | `bitmapdata_floodfill` | 35 | 7.2s |  |
| 147 | `bitmapdata_getpixels` | 39 | 26.4s |  |
| 148 | `bitmapdata_getvector` | 27 | 2.4s |  |
| 149 | `bitmapdata_histogram` | 59 | 2.4s |  |
| 150 | `bitmapdata_hittest` | 112 | 7.8s |  |
| 151 | `bitmapdata_hittest_threshold` | 18 | 7.2s |  |
| 152 | `bitmapdata_opaque` | 0 | 7.2s |  |
| 153 | `bitmapdata_pixeldissolve` | 1037 | 7.9s |  |
| 154 | `bitmapdata_pixeldissolve_image` | 0 | 7.5s |  |
| 155 | `bitmapdata_rectangle_rounding` | 16 | 7.3s |  |
| 156 | `bitmapdata_setpixels` | 286 | 7.4s |  |
| 157 | `bitmapdata_setvector` | 26 | 7.4s |  |
| 158 | `bitmapdata_sync` | 0 | 26.6s |  |
| 159 | `bitmapdata_threshold` | 176 | 8.0s |  |
| 160 | `bitmapdata_zero_size` | 8 | 7.2s |  |
| 161 | `bitnot` | 46 | 7.3s |  |
| 162 | `bitor` | 1058 | 19.1s |  |
| 163 | `bitxor` | 1058 | 19.1s |  |
| 164 | `blend_mode_null` | 1 | 7.2s |  |
| 165 | `blend_multiply_alpha` | 0 | 7.3s |  |
| 166 | `blend_scroll` | 0 | 7.3s |  |
| 167 | `blend_shader_luma_lighten` | 3 | 7.5s |  |
| 168 | `blur_filter` | 43 | 6.1s |  |
| 169 | `boolean_constr` | 32 | 5.8s |  |
| 170 | `boolean_negation` | 30 | 5.8s |  |
| 171 | `boolean_tostring` | 8 | 5.8s |  |
| 172 | `broadcast_event` | 7 | 5.8s |  |
| 173 | `button_bounds` | 1 | 5.9s |  |
| 174 | `button_hittest` | 2 | 21.4s |  |
| 175 | `button_nested_frame` | 48 | 21.8s |  |
| 176 | `button_nested_frame_simple` | 27 | 6.1s |  |
| 177 | `bytearray` | 48 | 6.1s |  |
| 178 | `bytearray_bad_symbol_class` | 3 | 6.0s |  |
| 179 | `bytearray_bad_symbol_class_other_movie` | 6 | 6.4s |  |
| 180 | `bytearray_compress` | 31 | 5.9s |  |
| 181 | `bytearray_errors` | 24 | 6.0s |  |
| 182 | `bytearray_method_serialization` | 1 | 5.8s |  |
| 183 | `bytearray_oom` | 3 | 5.9s |  |
| 184 | `bytearray_readobject_amf0` | 50 | 5.8s |  |
| 185 | `bytearray_readobject_amf3` | 53 | 6.0s |  |
| 186 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 187 | `bytearray_serialization` | 3 | 5.8s |  |
| 188 | `bytearray_string_null` | 19 | 6.2s |  |
| 189 | `bytearray_tostring` | 15 | 5.9s |  |
| 190 | `bytearray_utf16` | 8 | 5.8s |  |
| 191 | `bytearray_writeobject` | 24 | 5.8s |  |
| 192 | `callee_in_initializer` | 6 | 5.8s |  |
| 193 | `callproplex_class` | 1 | 5.8s |  |
| 194 | `capabilities_resolution` | 8 | 22.1s |  |
| 195 | `catch_class` | 6 | 5.8s |  |
| 196 | `catch_scope_slot` | 7 | 5.9s |  |
| 197 | `checkfilter` | 4 | 1.9s |  |
| 198 | `class_call` | 32 | 5.9s |  |
| 199 | `class_cast_call` | 14 | 5.9s |  |
| 200 | `class_enumeration` | 4 | 5.9s |  |
| 201 | `class_has_own_property` | 2 | 5.8s |  |
| 202 | `class_init_interpreter_mode` | 1 | 5.8s |  |
| 203 | `class_is` | 32 | 5.9s |  |
| 204 | `class_methods` | 5 | 5.8s |  |
| 205 | `class_object_properties` | 10 | 5.8s |  |
| 206 | `class_singleton` | 18 | 5.9s |  |
| 207 | `class_supercalls_errors` | 35 | 6.0s |  |
| 208 | `class_supercalls_mismatched` | 26 | 5.9s |  |
| 209 | `class_superclass_wrong_order` | 1 | 4.6s |  |
| 210 | `class_to_locale_string` | 2 | 4.5s |  |
| 211 | `class_to_string` | 2 | 4.5s |  |
| 212 | `class_value_of` | 2 | 4.6s |  |
| 213 | `click_block` | 5 | 16.4s |  |
| 214 | `click_invisible` | 3 | 4.6s |  |
| 215 | `closures` | 12 | 4.6s |  |
| 216 | `coerce_return_type` | 40 | 1.6s |  |
| 217 | `coerce_return_type_fail` | 2 | 4.6s |  |
| 218 | `coerce_return_void` | 3 | 4.5s |  |
| 219 | `coerce_string` | 86 | 4.6s |  |
| 220 | `coerce_string_precision` | 28 | 4.6s |  |
| 221 | `coerce_to_primitive_side_effects` | 29 | 4.6s |  |
| 222 | `color_matrix_filter` | 19 | 4.6s |  |
| 223 | `construct_errors_swf10` | 8 | 4.6s |  |
| 224 | `construct_frame_list` | 22 | 16.4s |  |
| 225 | `construct_interface` | 3 | 4.6s |  |
| 226 | `constructor_call` | 3 | 4.6s |  |
| 227 | `constructors_vs_timeline` | 5 | 16.3s |  |
| 228 | `constructprop_dynamic_primitive` | 7 | 4.5s |  |
| 229 | `constructprop_method` | 2 | 4.6s |  |
| 230 | `constructsuper_null` | 2 | 1.5s |  |
| 231 | `content_element_basic` | 50 | 4.7s |  |
| 232 | `context3d_creation` | 9 | 4.6s |  |
| 233 | `control_flow_bool` | 4 | 4.6s |  |
| 234 | `control_flow_stricteq` | 8 | 4.6s |  |
| 235 | `convert_boolean` | 30 | 4.6s |  |
| 236 | `convert_integer` | 90 | 4.7s |  |
| 237 | `convert_number` | 56 | 1.5s |  |
| 238 | `convert_uinteger` | 90 | 4.6s |  |
| 239 | `convolution_filter` | 89 | 4.7s |  |
| 240 | `core_exceptions` | 47 | 5.0s |  |
| 241 | `cpool_index_invalid_bytecode_1` | 6 | 4.5s |  |
| 242 | `cpool_index_invalid_bytecode_2` | 3 | 4.6s |  |
| 243 | `cpool_index_invalid_bytecode_3` | 1 | 4.5s |  |
| 244 | `cross_api_version_call_newer` | 12 | 4.9s |  |
| 245 | `cross_api_version_call_older` | 12 | 4.7s |  |
| 246 | `cryptscore` | 11 | 4.5s |  |
| 247 | `currency_parse_result` | 7 | 4.6s |  |
| 248 | `date` | 30 | 4.8s |  |
| 249 | `date_parse` | 36 | 4.5s |  |
| 250 | `declocal` | 46 | 7.6s |  |
| 251 | `declocal_i` | 46 | 7.6s |  |
| 252 | `decode_uri` | 71 | 7.9s |  |
| 253 | `decrement` | 46 | 7.7s |  |
| 254 | `decrement_i` | 46 | 2.5s |  |
| 255 | `default_values` | 7 | 7.5s |  |
| 256 | `delayed_symbolclass` | 28 | 27.4s |  |
| 257 | `describe_type_basic` | 152 | 7.7s |  |
| 258 | `describe_type_json` | 301 | 7.7s |  |
| 259 | `describe_type_metadata` | 125 | 7.6s |  |
| 260 | `describe_type_native` | 23 | 7.6s |  |
| 261 | `dictionary_access` | 62 | 7.8s |  |
| 262 | `dictionary_access_no_pubns` | 2 | 7.5s |  |
| 263 | `dictionary_delete` | 101 | 8.0s |  |
| 264 | `dictionary_foreach` | 42 | 7.8s |  |
| 265 | `dictionary_hasownproperty` | 63 | 7.8s |  |
| 266 | `dictionary_in` | 62 | 7.8s |  |
| 267 | `dictionary_iter_modify` | 8 | 7.6s |  |
| 268 | `dictionary_namespaces` | 36 | 7.7s |  |
| 269 | `displacement_map_filter` | 61 | 7.7s |  |
| 270 | `displayobject_alpha` | 277 | 7.5s |  |
| 271 | `displayobject_blendmode` | 0 | 27.3s |  |
| 272 | `displayobject_colortransform_nested` | 0 | 27.6s |  |
| 273 | `displayobject_early_init` | 54 | 9.1s |  |
| 274 | `displayobject_filters` | 17 | 7.7s |  |
| 275 | `displayobject_from_enterframe` | 1 | 27.4s |  |
| 276 | `displayobject_getbounds_shape` | 0 | 27.3s |  |
| 277 | `displayobject_getrect` | 16 | 7.8s |  |
| 278 | `displayobject_height` | 6052 | 28.0s |  |
| 279 | `displayobject_hittestobject` | 32 | 7.7s |  |
| 280 | `displayobject_hittestpoint` | 49 | 7.7s |  |
| 281 | `displayobject_hittestpoint_boundary` | 65 | 28.3s |  |
| 282 | `displayobject_hittestpoint_root` | 13 | 8.0s |  |
| 283 | `displayobject_invalid_floats` | 60 | 7.8s |  |
| 284 | `displayobject_invalid_props` | 3 | 7.6s |  |
| 285 | `displayobject_mask` | 3 | 7.6s |  |
| 286 | `displayobject_mask_self_referential` | 0 | 7.5s |  |
| 287 | `displayobject_metaData` | 3 | 7.7s |  |
| 288 | `displayobject_name` | 22 | 27.5s |  |
| 289 | `displayobject_name_from_timeline` | 24 | 7.7s |  |
| 290 | `displayobject_opaque_background` | 6 | 7.6s |  |
| 291 | `displayobject_parent` | 12 | 27.8s |  |
| 292 | `displayobject_root` | 24 | 7.6s |  |
| 293 | `displayobject_rotation` | 1284 | 7.6s |  |
| 294 | `displayobject_scrollrect` | 33 | 7.9s |  |
| 295 | `displayobject_set_matrix_nested` | 0 | 27.6s |  |
| 296 | `displayobject_set_name_loaded` | 3 | 7.9s |  |
| 297 | `displayobject_subclass` | 2 | 7.4s |  |
| 298 | `displayobject_transform` | 89 | 27.2s |  |
| 299 | `displayobject_visible` | 23 | 7.4s |  |
| 300 | `displayobject_width` | 4852 | 27.9s |  |
| 301 | `displayobject_x` | 614 | 7.5s |  |
| 302 | `displayobject_y` | 617 | 7.7s |  |
| 303 | `displayobject_z` | 38 | 27.9s |  |
| 304 | `displayobjectcontainer_addchild` | 32 | 7.6s |  |
| 305 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.4s |  |
| 306 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.6s |  |
| 307 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.5s |  |
| 308 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.5s |  |
| 309 | `displayobjectcontainer_addchildat` | 42 | 7.5s |  |
| 310 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.6s |  |
| 311 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.6s |  |
| 312 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.5s |  |
| 313 | `displayobjectcontainer_contains` | 66 | 28.8s |  |
| 314 | `displayobjectcontainer_getchildat` | 4 | 7.9s |  |
| 315 | `displayobjectcontainer_getchildbyname` | 9 | 7.9s |  |
| 316 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.9s |  |
| 317 | `displayobjectcontainer_getchildindex` | 28 | 7.9s |  |
| 318 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 30.0s |  |
| 319 | `displayobjectcontainer_removechild` | 10 | 7.8s |  |
| 320 | `displayobjectcontainer_removechild_errors` | 4 | 7.5s |  |
| 321 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.5s |  |
| 322 | `displayobjectcontainer_removechildat` | 18 | 7.5s |  |
| 323 | `displayobjectcontainer_removechildren` | 51 | 7.9s |  |
| 324 | `displayobjectcontainer_setchildindex` | 42 | 7.5s |  |
| 325 | `displayobjectcontainer_stopallmovieclips` | 2 | 28.1s |  |
| 326 | `displayobjectcontainer_swapchildren` | 42 | 7.5s |  |
| 327 | `displayobjectcontainer_swapchildrenat` | 42 | 7.5s |  |
| 328 | `displayobjectcontainer_timelineinstance` | 48 | 27.6s |  |
| 329 | `divide` | 1058 | 19.8s |  |
| 330 | `doabc_and_symbolclass_script_init_goto` | 7 | 27.5s |  |
| 331 | `doabc_and_symbolclass_script_init_normal` | 6 | 7.4s |  |
| 332 | `doabc_is_eager` | 1 | 27.1s |  |
| 333 | `documentclass` | 9 | 5.2s |  |
| 334 | `domain_memory` | 133 | 20.4s |  |
| 335 | `drag_drop` | 10 | 5.2s |  |
| 336 | `drop_shadow_filter` | 172 | 5.3s |  |
| 337 | `duplicate_defs` | 1 | 5.3s |  |
| 338 | `eager_init` | 1 | 5.4s |  |
| 339 | `east_asian_justifier_clone` | 8 | 5.1s |  |
| 340 | `edit_text_linkage` | 7 | 5.5s |  |
| 341 | `edittext_align` | 60 | 5.5s |  |
| 342 | `edittext_always_show_selection` | 0 | 20.3s |  |
| 343 | `edittext_antialiastype` | 296 | 5.3s |  |
| 344 | `edittext_at_point_methods_basic` | 16 | 6.1s |  |
| 345 | `edittext_autosize` | 39 | 5.4s |  |
| 346 | `edittext_autosize_align` | 0 | 20.0s |  |
| 347 | `edittext_autosize_height_dynamic` | 60 | 19.7s |  |
| 348 | `edittext_autosize_height_input` | 60 | 5.1s |  |
| 349 | `edittext_autosize_lazy_bounds_events` | 65 | 5.4s |  |
| 350 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.6s |  |
| 351 | `edittext_autosize_lazy_bounds_props` | 490 | 6.5s |  |
| 352 | `edittext_autosize_lazy_bounds_visual` | 0 | 20.1s |  |
| 353 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.2s |  |
| 354 | `edittext_bottom_scroll_v_basic` | 210 | 5.7s |  |
| 355 | `edittext_bounds_scale` | 24 | 19.8s |  |
| 356 | `edittext_bullet` | 30 | 5.2s |  |
| 357 | `edittext_default_format` | 221 | 5.5s |  |
| 358 | `edittext_default_format_empty` | 136 | 5.2s |  |
| 359 | `edittext_empty_text_format` | 7 | 5.6s |  |
| 360 | `edittext_focus_selection` | 5 | 5.1s |  |
| 361 | `edittext_font_size` | 45 | 5.9s |  |
| 362 | `edittext_format_empty_font` | 8 | 6.2s |  |
| 363 | `edittext_get_char_index_at_point` | 4 | 21.1s |  |
| 364 | `edittext_get_line_index_at_point` | 2 | 5.2s |  |
| 365 | `edittext_get_line_index_of_char` | 76 | 5.8s |  |
| 366 | `edittext_getcharboundaries` | 172 | 5.7s |  |
| 367 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.5s |  |
| 368 | `edittext_getcharboundaries_scroll` | 85 | 5.1s |  |
| 369 | `edittext_getlinemetrics` | 146 | 5.7s |  |
| 370 | `edittext_html` | 3101 | 5.6s |  |
| 371 | `edittext_html_condensewhite` | 487 | 5.4s |  |
| 372 | `edittext_html_entity` | 4 | 5.4s |  |
| 373 | `edittext_html_font_size_swf12` | 267 | 26.7s |  |
| 374 | `edittext_html_font_size_swf13` | 273 | 7.0s |  |
| 375 | `edittext_html_roundtrip` | 17 | 26.5s |  |
| 376 | `edittext_ime_focus_lost` | 9 | 26.9s |  |
| 377 | `edittext_input_control` | 12 | 7.3s |  |
| 378 | `edittext_leading` | 9 | 7.7s |  |
| 379 | `edittext_letter_spacing` | 15 | 7.7s |  |
| 380 | `edittext_line_methods` | 294 | 8.8s |  |
| 381 | `edittext_line_metrics` | 11 | 28.1s |  |
| 382 | `edittext_margins` | 25 | 7.4s |  |
| 383 | `edittext_max_scroll_h_basic` | 475 | 7.7s |  |
| 384 | `edittext_max_scroll_v_basic` | 1000 | 7.4s |  |
| 385 | `edittext_mouse_selection` | 363 | 27.6s |  |
| 386 | `edittext_mousedown` | 3 | 7.7s |  |
| 387 | `edittext_mouseenabled` | 26 | 7.3s |  |
| 388 | `edittext_newline_character` | 22 | 7.3s |  |
| 389 | `edittext_newline_stripping` | 64 | 10.2s |  |
| 390 | `edittext_newlines` | 30 | 7.4s |  |
| 391 | `edittext_paragraph_methods` | 257 | 7.3s |  |
| 392 | `edittext_paste_events` | 8 | 7.3s |  |
| 393 | `edittext_paste_maxchars` | 4 | 7.3s |  |
| 394 | `edittext_paste_restrict` | 16 | 7.1s |  |
| 395 | `edittext_restrict` | 191 | 7.3s |  |
| 396 | `edittext_restrict_events` | 22 | 7.3s |  |
| 397 | `edittext_scroll_event` | 37 | 7.6s |  |
| 398 | `edittext_scrollh` | 10 | 2.4s |  |
| 399 | `edittext_selected_text` | 9 | 7.2s |  |
| 400 | `edittext_set_html_same` | 17 | 7.2s |  |
| 401 | `edittext_set_text_vs_html` | 9 | 7.2s |  |
| 402 | `edittext_stylesheet` | 536 | 7.7s |  |
| 403 | `edittext_stylesheet_custom_tag` | 76 | 7.4s |  |
| 404 | `edittext_stylesheet_display` | 272 | 7.4s |  |
| 405 | `edittext_tag_indent` | 49 | 26.7s |  |
| 406 | `edittext_underline` | 40 | 7.5s |  |
| 407 | `edittext_width_height` | 103 | 7.7s |  |
| 408 | `edittext_wordwrap_word` | 150 | 7.4s |  |
| 409 | `edittext_wrap_breaks` | 2375 | 7.9s |  |
| 410 | `element_format_clone` | 44 | 7.4s |  |
| 411 | `element_format_constructor_order` | 64 | 2.6s |  |
| 412 | `element_format_properties` | 235 | 8.3s |  |
| 413 | `empty_bounds` | 1 | 7.3s |  |
| 414 | `encode_uri_surrogate_pair_invalid` | 8 | 7.3s |  |
| 415 | `encode_uri_surrogate_pair_swf11` | 15 | 2.0s |  |
| 416 | `equals` | 512 | 11.3s |  |
| 417 | `error_geterrormessage` | 779 | 7.2s |  |
| 418 | `error_prototype` | 15 | 7.3s |  |
| 419 | `error_stack_trace` | 45 | 7.3s |  |
| 420 | `error_stack_trace_debug_swf17` | 0 | 26.4s |  |
| 421 | `error_stack_trace_debug_swf18` | 0 | 6.9s |  |
| 422 | `error_stack_trace_edge_cases` | 6 | 7.2s |  |
| 423 | `error_stack_trace_release_swf17` | 0 | 2.3s |  |
| 424 | `error_stack_trace_release_swf18` | 0 | 6.9s |  |
| 425 | `error_throwerror` | 103 | 7.3s |  |
| 426 | `error_tostring` | 29 | 7.2s |  |
| 427 | `error_tostring_more` | 86 | 7.3s |  |
| 428 | `es3_inheritance` | 31 | 7.2s |  |
| 429 | `es4_inheritance` | 30 | 7.3s |  |
| 430 | `es4_interfaces` | 30 | 7.4s |  |
| 431 | `es4_method_binding` | 8 | 7.3s |  |
| 432 | `es4_oop_prototypes` | 14 | 7.5s |  |
| 433 | `es4_protected_inheritance` | 6 | 7.3s |  |
| 434 | `escape` | 71 | 7.4s |  |
| 435 | `escape_multi_byte` | 45 | 7.4s |  |
| 436 | `event_bubbles` | 2 | 7.2s |  |
| 437 | `event_cancelable` | 2 | 7.1s |  |
| 438 | `event_clone` | 20 | 7.2s |  |
| 439 | `event_clone_error_redispatch` | 3 | 7.4s |  |
| 440 | `event_clone_on_redispatch` | 10 | 7.3s |  |
| 441 | `event_formattostring` | 31 | 7.2s |  |
| 442 | `event_isdefaultprevented` | 12 | 7.2s |  |
| 443 | `event_target_getter` | 5 | 2.3s |  |
| 444 | `event_target_set` | 9 | 7.1s |  |
| 445 | `event_type` | 1 | 7.2s |  |
| 446 | `event_valueof_tostring` | 18 | 7.2s |  |
| 447 | `eventdispatcher_dispatchevent` | 12 | 7.2s |  |
| 448 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.2s |  |
| 449 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.2s |  |
| 450 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.2s |  |
| 451 | `eventdispatcher_dispatchevent_this` | 5 | 7.2s |  |
| 452 | `eventdispatcher_haseventlistener` | 25 | 7.2s |  |
| 453 | `eventdispatcher_interface_invoke` | 1 | 7.1s |  |
| 454 | `eventdispatcher_tostring` | 10 | 7.2s |  |
| 455 | `eventdispatcher_willtrigger` | 25 | 7.1s |  |
| 456 | `falsiness` | 30 | 7.0s |  |
| 457 | `fast_index_access` | 12 | 7.1s |  |
| 458 | `filefilter_properties` | 4 | 7.0s |  |
| 459 | `filereference_browse_cancel` | 3 | 7.0s |  |
| 460 | `filereference_browse_select` | 9 | 2.1s |  |
| 461 | `filereference_load` | 31 | 7.1s |  |
| 462 | `filereference_save` | 16 | 7.1s |  |
| 463 | `filereference_save_and_browse` | 42 | 7.0s |  |
| 464 | `filereference_save_and_load` | 22 | 7.1s |  |
| 465 | `filereference_uninitialized` | 8 | 7.0s |  |
| 466 | `filereferencelist_browse_cancel` | 6 | 7.0s |  |
| 467 | `filereferencelist_browse_select` | 7 | 7.0s |  |
| 468 | `filter_rewind` | 8 | 26.4s |  |
| 469 | `filters_array_holes` | 25 | 6.8s |  |
| 470 | `finddef` | 3 | 6.9s |  |
| 471 | `findprop_global_prototype` | 6 | 7.0s |  |
| 472 | `flash_media_video_constructor` | 156 | 7.7s |  |
| 473 | `flash_media_video_rotation_probe` | 27 | 7.0s |  |
| 474 | `flash_media_video_setter` | 40 | 7.4s |  |
| 475 | `flash_trace` | 17 | 7.0s |  |
| 476 | `flash_ui_mouse_cursor` | 35 | 7.3s |  |
| 477 | `flash_xml` | 29 | 7.0s |  |
| 478 | `flash_xml_cloneNode` | 22 | 7.0s |  |
| 479 | `flash_xml_namespace` | 109 | 7.0s |  |
| 480 | `flash_xml_removeNode` | 60 | 7.1s |  |
| 481 | `focus_events_code` | 161 | 26.9s |  |
| 482 | `focus_events_key_basic` | 132 | 26.7s |  |
| 483 | `focus_events_key_navigation` | 53 | 26.2s |  |
| 484 | `focus_events_key_same_object` | 26 | 7.1s |  |
| 485 | `focus_events_mixed_key_mouse` | 100 | 26.7s |  |
| 486 | `focus_events_mouse_basic` | 260 | 27.0s |  |
| 487 | `focus_events_mouse_focusable` | 112 | 27.0s |  |
| 488 | `focus_events_mouse_same_object` | 40 | 7.0s |  |
| 489 | `focus_remove` | 20 | 26.6s |  |
| 490 | `focus_root_movie` | 4 | 26.6s |  |
| 491 | `focus_stage` | 1 | 7.0s |  |
| 492 | `focusrect` | 18 | 7.7s |  |
| 493 | `focusrect_focuslost` | 9 | 7.1s |  |
| 494 | `focusrect_property` | 110 | 1.9s |  |
| 495 | `font_description_clone` | 14 | 7.0s |  |
| 496 | `font_embedded` | 24 | 28.2s |  |
| 497 | `font_enumeratefonts` | 41 | 8.1s |  |
| 498 | `font_enumeratefonts_filter` | 4 | 27.3s |  |
| 499 | `font_enumeratefonts_order` | 9 | 8.5s |  |
| 500 | `font_hasglyphs` | 40 | 7.8s |  |
| 501 | `font_registerfont` | 129 | 8.3s |  |
| 502 | `framelabel_constr` | 5 | 7.2s |  |
| 503 | `function_call` | 12 | 2.5s |  |
| 504 | `function_call_arguments` | 46 | 7.7s |  |
| 505 | `function_call_arguments_enumerate` | 5 | 7.5s |  |
| 506 | `function_call_coercion` | 108 | 7.8s |  |
| 507 | `function_call_default` | 6 | 7.5s |  |
| 508 | `function_call_rest` | 22 | 7.5s |  |
| 509 | `function_call_types` | 3 | 7.5s |  |
| 510 | `function_call_via_apply` | 11 | 7.4s |  |
| 511 | `function_call_via_call` | 3 | 7.3s |  |
| 512 | `function_display_anonymous` | 7 | 2.4s |  |
| 513 | `function_length` | 6 | 7.2s |  |
| 514 | `function_object` | 2 | 7.3s |  |
| 515 | `function_proto` | 5 | 7.3s |  |
| 516 | `function_proto_created` | 61 | 7.5s |  |
| 517 | `function_to_locale_string` | 4 | 7.3s |  |
| 518 | `function_to_string` | 4 | 7.2s |  |
| 519 | `function_type` | 6 | 7.2s |  |
| 520 | `function_unbound_this` | 51 | 7.5s |  |
| 521 | `function_value_of` | 4 | 7.6s |  |
| 522 | `game_input` | 4 | 7.8s |  |
| 523 | `generate_random_bytes` | 3 | 7.4s |  |
| 524 | `geom_transform` | 74 | 28.2s |  |
| 525 | `get_definition_by_name` | 11 | 7.8s |  |
| 526 | `get_qualified_class_name` | 20 | 7.8s |  |
| 527 | `get_qualified_super_class_name` | 18 | 7.9s |  |
| 528 | `get_slot_edge_cases` | 1 | 7.3s |  |
| 529 | `get_timer` | 2 | 2.4s |  |
| 530 | `getglobalslot` | 1 | 7.3s |  |
| 531 | `getouterscope` | 8 | 7.4s |  |
| 532 | `getouterscope_two_classobjects` | 13 | 7.2s |  |
| 533 | `getter_different_namespace_setter` | 2 | 7.1s |  |
| 534 | `glow_filter` | 127 | 7.5s |  |
| 535 | `goto_button_nested_framescript` | 28 | 26.8s |  |
| 536 | `goto_in_constructframe` | 12 | 27.6s |  |
| 537 | `goto_in_scene_last_frame` | 2 | 26.5s |  |
| 538 | `goto_methods` | 56 | 7.5s |  |
| 539 | `goto_methods_swfver10` | 8 | 7.3s |  |
| 540 | `goto_nested_construct_sibling` | 18 | 7.7s |  |
| 541 | `goto_nested_framescript` | 9 | 7.5s |  |
| 542 | `goto_on_orphan` | 15 | 27.3s |  |
| 543 | `gradient_bevel_filter` | 206 | 7.7s |  |
| 544 | `gradient_glow_filter` | 206 | 7.2s |  |
| 545 | `graphic_linkage` | 9 | 7.5s |  |
| 546 | `graphics_bad_direct_commands` | 5 | 7.7s |  |
| 547 | `graphics_bitmap_fill` | 0 | 28.2s |  |
| 548 | `graphics_bitmaps` | 0 | 7.6s |  |
| 549 | `graphics_direct_commands` | 0 | 7.5s |  |
| 550 | `graphics_draw_triangles` | 98 | 27.1s |  |
| 551 | `graphics_gradients` | 0 | 7.4s |  |
| 552 | `graphics_gradients_nulls` | 0 | 7.3s |  |
| 553 | `graphics_path` | 56 | 7.3s |  |
| 554 | `graphics_round_rects` | 0 | 7.3s |  |
| 555 | `graphics_simple_shapes` | 0 | 7.3s |  |
| 556 | `greaterequals` | 512 | 11.1s |  |
| 557 | `greaterthan` | 512 | 11.2s |  |
| 558 | `has_own_property` | 102 | 7.8s |  |
| 559 | `hasownproperty_namespaces` | 2 | 7.2s |  |
| 560 | `hello_world` | 1 | 7.2s |  |
| 561 | `hittest_morph` | 30 | 7.3s |  |
| 562 | `id3_info` | 8 | 26.2s |  |
| 563 | `if_eq` | 10 | 7.3s |  |
| 564 | `if_gt` | 1 | 7.3s |  |
| 565 | `if_gte` | 10 | 2.4s |  |
| 566 | `if_lt` | 1 | 0.6s |  |
| 567 | `if_lte` | 10 | 7.1s |  |
| 568 | `if_ne` | 7 | 2.4s |  |
| 569 | `if_stricteq` | 6 | 7.3s |  |
| 570 | `if_strictne` | 11 | 7.2s |  |
| 571 | `ime_linux_dead_keys` | 10 | 7.2s |  |
| 572 | `in` | 102 | 7.7s |  |
| 573 | `inclocal` | 46 | 7.3s |  |
| 574 | `inclocal_i` | 46 | 7.2s |  |
| 575 | `increment` | 46 | 7.1s |  |
| 576 | `increment_i` | 46 | 7.3s |  |
| 577 | `indexing_delete` | 75 | 7.2s |  |
| 578 | `indexof_xml` | 10 | 7.2s |  |
| 579 | `init_callee_cached` | 24 | 7.2s |  |
| 580 | `instanceof` | 58 | 7.5s |  |
| 581 | `instantiate_root_character` | 4 | 7.4s |  |
| 582 | `instantiation_on_enter_frame` | 7 | 26.4s |  |
| 583 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.2s |  |
| 584 | `int_constr` | 92 | 7.4s |  |
| 585 | `int_edge_cases` | 19 | 26.3s |  |
| 586 | `int_instanceof` | 3 | 7.1s |  |
| 587 | `int_tofixed` | 1215 | 7.1s |  |
| 588 | `int_toprecision` | 1125 | 7.4s |  |
| 589 | `int_tostring` | 3375 | 7.5s |  |
| 590 | `interactiveobject_enabled` | 25 | 7.2s |  |
| 591 | `interface_namespaces` | 78 | 7.4s |  |
| 592 | `invalid_utf8` | 12 | 7.3s |  |
| 593 | `is_finite` | 46 | 7.3s |  |
| 594 | `is_nan` | 46 | 7.1s |  |
| 595 | `is_prototype_of` | 12 | 7.2s |  |
| 596 | `issue_10221` | 2 | 7.1s |  |
| 597 | `issue_13780` | 12 | 7.2s |  |
| 598 | `issue_14901` | 1 | 7.2s |  |
| 599 | `issue_17675_edittext_paste_maxchars` | 1 | 7.2s |  |
| 600 | `issue_5292` | 5 | 7.2s |  |
| 601 | `issue_8630` | 2 | 7.2s |  |
| 602 | `issue_8630_placeremoveplace` | 15 | 7.3s |  |
| 603 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.1s |  |
| 604 | `issue_8630_scriptremove` | 11 | 7.2s |  |
| 605 | `istype` | 24 | 2.4s |  |
| 606 | `istypelate` | 58 | 7.5s |  |
| 607 | `istypelate_coerce` | 198 | 8.3s |  |
| 608 | `jpeg_loader_context` | 6 | 2.3s |  |
| 609 | `json_errors` | 9 | 26.5s |  |
| 610 | `json_parse` | 21 | 2.3s |  |
| 611 | `json_parse_errors` | 84 | 7.2s |  |
| 612 | `json_stringify` | 12 | 7.3s |  |
| 613 | `json_stringify_function` | 12 | 7.1s |  |
| 614 | `json_stringify_order` | 1 | 7.2s |  |
| 615 | `json_version_gated` | 1 | 7.2s |  |
| 616 | `key_input_80percent` | 1812 | 24.6s |  |
| 617 | `key_input_location` | 126 | 6.6s |  |
| 618 | `key_input_numpad` | 384 | 6.5s |  |
| 619 | `large_preload_from_bytes` | 51 | 27.8s |  |
| 620 | `large_preload_from_url` | 27 | 8.4s |  |
| 621 | `large_preload_image_from_bytes` | 25 | 7.3s |  |
| 622 | `lazyinit` | 17 | 6.7s |  |
| 623 | `lessequals` | 512 | 9.5s |  |
| 624 | `lessthan` | 512 | 9.2s |  |
| 625 | `loader_bitmap_transparency` | 14 | 6.8s |  |
| 626 | `loader_bytes_unknown_content` | 14 | 6.8s |  |
| 627 | `loader_child_getdefinition` | 5 | 7.0s |  |
| 628 | `loader_duplicate_class` | 48 | 8.3s |  |
| 629 | `loader_duplicate_coerce` | 3 | 6.8s |  |
| 630 | `loader_duplicate_coerce_new_domain` | 4 | 6.7s |  |
| 631 | `loader_error_in_root_ctor` | 4 | 6.8s |  |
| 632 | `loader_events` | 92 | 7.2s |  |
| 633 | `loader_image` | 8 | 6.7s |  |
| 634 | `loader_jpegxr` | 2 | 24.3s |  |
| 635 | `loader_jpegxr_alpha` | 1 | 23.3s |  |
| 636 | `loader_loadbytes_events` | 30 | 7.1s |  |
| 637 | `loader_loadbytes_invalid_png` | 4 | 6.7s |  |
| 638 | `loader_loadbytes_url` | 12 | 6.8s |  |
| 639 | `loader_loaderurl` | 6 | 6.7s |  |
| 640 | `loader_method` | 85 | 6.5s |  |
| 641 | `loader_noninteractive_try_click_root` | 5 | 24.5s |  |
| 642 | `loader_reuse` | 38 | 6.7s |  |
| 643 | `loader_try_click_root` | 16 | 6.6s |  |
| 644 | `loader_unknown_content` | 24 | 6.5s |  |
| 645 | `loader_visibility_interactive` | 1 | 6.6s |  |
| 646 | `loaderinfo_events` | 7 | 6.5s |  |
| 647 | `loaderinfo_loadurl` | 12 | 6.6s |  |
| 648 | `loaderinfo_more` | 6 | 6.9s |  |
| 649 | `loaderinfo_properties` | 18 | 25.4s |  |
| 650 | `loaderinfo_properties_not_loaded` | 23 | 7.4s |  |
| 651 | `loaderinfo_quine` | 1005 | 6.7s |  |
| 652 | `loaderinfo_root` | 10 | 6.7s |  |
| 653 | `loaderinfo_root_allows` | 2 | 6.7s |  |
| 654 | `localconnection` | 890 | 8.6s |  |
| 655 | `localconnection_send` | 4 | 26.8s |  |
| 656 | `lshift` | 1058 | 16.7s |  |
| 657 | `mask_reapply` | 1 | 26.7s |  |
| 658 | `math` | 497 | 7.2s |  |
| 659 | `matrix` | 338 | 16.0s |  |
| 660 | `matrix3d` | 57 | 27.4s |  |
| 661 | `matrix3d_append` | 16 | 7.2s |  |
| 662 | `matrix3d_append_prepend_scale` | 86 | 7.2s |  |
| 663 | `matrix3d_append_prepend_translation` | 42 | 7.1s |  |
| 664 | `matrix3d_append_rotation` | 23 | 7.2s |  |
| 665 | `matrix3d_compose` | 34 | 7.3s |  |
| 666 | `matrix3d_constructor_clone` | 15 | 7.1s |  |
| 667 | `matrix3d_copy_column` | 83 | 7.3s |  |
| 668 | `matrix3d_copy_from` | 19 | 7.1s |  |
| 669 | `matrix3d_copy_raw_data_from` | 55 | 2.3s |  |
| 670 | `matrix3d_copy_raw_data_to` | 38 | 7.2s |  |
| 671 | `matrix3d_copy_row` | 83 | 7.0s |  |
| 672 | `matrix3d_copy_to_matrix3d` | 19 | 7.1s |  |
| 673 | `matrix3d_determinant` | 182 | 7.2s |  |
| 674 | `matrix3d_interpolate` | 21 | 7.3s |  |
| 675 | `matrix3d_invert` | 18 | 7.1s |  |
| 676 | `matrix3d_position` | 19 | 7.1s |  |
| 677 | `matrix3d_precision` | 28 | 7.2s |  |
| 678 | `matrix3d_prepend` | 16 | 7.0s |  |
| 679 | `matrix3d_raw_data` | 33 | 7.1s |  |
| 680 | `matrix3d_transform_vector` | 52 | 7.4s |  |
| 681 | `matrix3d_transpose` | 5 | 7.0s |  |
| 682 | `method_association` | 5 | 7.1s |  |
| 683 | `method_without_body` | 3 | 26.7s |  |
| 684 | `missing_external_interface` | 10 | 7.1s |  |
| 685 | `modulo` | 1058 | 16.7s |  |
| 686 | `morph_shape` | 2 | 26.7s |  |
| 687 | `mouse_children` | 192 | 26.7s |  |
| 688 | `mouse_click_events` | 90 | 26.7s |  |
| 689 | `mouse_double_click_events` | 188 | 7.1s |  |
| 690 | `mouse_empty_parent` | 4 | 7.1s |  |
| 691 | `mouse_over_while_dragging` | 3 | 7.1s |  |
| 692 | `mouse_pick_avm1_root` | 2 | 26.8s |  |
| 693 | `mouse_pick_button_mode` | 2 | 7.1s |  |
| 694 | `mouse_pick_dobj_mask` | 4 | 7.1s |  |
| 695 | `mouse_pick_masking` | 7 | 26.8s |  |
| 696 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.5s |  |
| 697 | `mouse_pick_non_interactive_dobj_mask` | 3 | 26.5s |  |
| 698 | `mouse_pick_text` | 8 | 7.5s |  |
| 699 | `mouse_sibling` | 8 | 7.3s |  |
| 700 | `mouse_wheel_events` | 36 | 27.6s |  |
| 701 | `mouseevent_constr` | 66 | 7.3s |  |
| 702 | `mouseevent_stagexy` | 35 | 7.4s |  |
| 703 | `mouseevent_valueof_tostring` | 28 | 7.3s |  |
| 704 | `movieclip_addframescript` | 3 | 26.6s |  |
| 705 | `movieclip_addframescript_error` | 9 | 7.2s |  |
| 706 | `movieclip_child_property` | 16 | 7.4s |  |
| 707 | `movieclip_constr` | 21 | 7.3s |  |
| 708 | `movieclip_currentlabels` | 17 | 26.7s |  |
| 709 | `movieclip_currentlabels_dupes1` | 46 | 27.0s |  |
| 710 | `movieclip_currentlabels_dupes2` | 30 | 7.3s |  |
| 711 | `movieclip_currentlabels_dupes3` | 67 | 7.3s |  |
| 712 | `movieclip_currentscene` | 12 | 26.5s |  |
| 713 | `movieclip_dispatchevent` | 430 | 7.5s |  |
| 714 | `movieclip_dispatchevent_cancel` | 102 | 7.5s |  |
| 715 | `movieclip_dispatchevent_handlerorder` | 251 | 7.4s |  |
| 716 | `movieclip_dispatchevent_selfadd` | 80 | 7.3s |  |
| 717 | `movieclip_dispatchevent_target` | 899 | 7.4s |  |
| 718 | `movieclip_displayevents` | 96 | 27.1s |  |
| 719 | `movieclip_displayevents_clickgoto` | 676 | 26.9s |  |
| 720 | `movieclip_displayevents_clickgoto2` | 2001 | 7.8s |  |
| 721 | `movieclip_displayevents_clickplay` | 575 | 7.5s |  |
| 722 | `movieclip_displayevents_clicksymbol` | 562 | 2.6s |  |
| 723 | `movieclip_displayevents_constructframegoto` | 140 | 7.7s |  |
| 724 | `movieclip_displayevents_constructframeplay` | 50 | 7.7s |  |
| 725 | `movieclip_displayevents_constructframesymbol` | 144 | 7.5s |  |
| 726 | `movieclip_displayevents_dblhandler` | 21 | 7.4s |  |
| 727 | `movieclip_displayevents_enterframegoto` | 149 | 7.6s |  |
| 728 | `movieclip_displayevents_enterframeplay` | 48 | 7.4s |  |
| 729 | `movieclip_displayevents_enterframesymbol` | 149 | 26.8s |  |
| 730 | `movieclip_displayevents_exitframegoto` | 106 | 7.4s |  |
| 731 | `movieclip_displayevents_exitframeplay` | 44 | 7.4s |  |
| 732 | `movieclip_displayevents_exitframesymbol` | 135 | 7.5s |  |
| 733 | `movieclip_displayevents_looping` | 63 | 26.7s |  |
| 734 | `movieclip_displayevents_stopped` | 113 | 7.5s |  |
| 735 | `movieclip_displayevents_swap` | 96 | 2.2s |  |
| 736 | `movieclip_displayevents_timeline` | 128 | 7.6s |  |
| 737 | `movieclip_drawrect` | 54 | 26.8s |  |
| 738 | `movieclip_frameconstruct_skipped` | 9 | 7.4s |  |
| 739 | `movieclip_goto_during_frame_script` | 15 | 26.7s |  |
| 740 | `movieclip_goto_overwrite` | 14 | 26.9s |  |
| 741 | `movieclip_goto_scene_last_frame_int` | 1 | 26.8s |  |
| 742 | `movieclip_goto_scene_last_frame_label` | 1 | 2.3s |  |
| 743 | `movieclip_gotoandplay` | 15 | 27.1s |  |
| 744 | `movieclip_gotoandstop` | 13 | 7.3s |  |
| 745 | `movieclip_gotoandstop_children` | 4 | 7.4s |  |
| 746 | `movieclip_gotoandstop_framescripts1` | 4 | 7.3s |  |
| 747 | `movieclip_gotoandstop_framescripts2` | 4 | 2.4s |  |
| 748 | `movieclip_gotoandstop_framescripts_self` | 7 | 26.8s |  |
| 749 | `movieclip_gotoandstop_queueing` | 12 | 26.9s |  |
| 750 | `movieclip_hittest` | 67 | 7.6s |  |
| 751 | `movieclip_next_frame` | 2 | 7.3s |  |
| 752 | `movieclip_next_scene` | 6 | 27.0s |  |
| 753 | `movieclip_play` | 3 | 7.3s |  |
| 754 | `movieclip_prev_frame` | 3 | 7.1s |  |
| 755 | `movieclip_prev_scene` | 7 | 7.4s |  |
| 756 | `movieclip_properties` | 79 | 26.8s |  |
| 757 | `movieclip_queued_noop_goto_swf10` | 9 | 7.4s |  |
| 758 | `movieclip_queued_noop_goto_swf9` | 7 | 0.7s |  |
| 759 | `movieclip_scenes` | 11 | 7.3s |  |
| 760 | `movieclip_soundtransform` | 831 | 28.9s |  |
| 761 | `movieclip_stop` | 1 | 7.2s |  |
| 762 | `movieclip_super_is_symbol` | 20 | 7.6s |  |
| 763 | `movieclip_symbol_constr` | 8 | 7.4s |  |
| 764 | `movieclip_text_mousedown` | 1 | 7.4s |  |
| 765 | `movieclip_willtrigger` | 5 | 7.4s |  |
| 766 | `multiply` | 1058 | 19.6s |  |
| 767 | `namespace_constr` | 253 | 7.7s |  |
| 768 | `namespace_constr_args` | 1 | 7.3s |  |
| 769 | `namespace_enumeration_order` | 7 | 26.6s |  |
| 770 | `nan_scale` | 9 | 7.3s |  |
| 771 | `native_menu_basic` | 19 | 9.6s |  |
| 772 | `navigateToURL_target_normalize` | 107 | 28.7s |  |
| 773 | `negate` | 30 | 7.4s |  |
| 774 | `negative_volume_panned` | 0 | 7.6s |  |
| 775 | `nested_iteration` | 11 | 7.4s |  |
| 776 | `net_getClassByAlias` | 3 | 7.3s |  |
| 777 | `net_navigateToURL` | 57 | 7.3s |  |
| 778 | `net_stream_play_options` | 6 | 7.4s |  |
| 779 | `netconnection_close` | 55 | 18.6s |  |
| 780 | `netconnection_properties` | 78 | 5.0s |  |
| 781 | `netconnection_send_remote` | 50 | 19.5s |  |
| 782 | `netconnection_serialize_arrays` | 6 | 4.9s |  |
| 783 | `netfilterevent` | 10 | 17.3s |  |
| 784 | `netstream_client` | 10 | 4.9s |  |
| 785 | `netstream_connect` | 7 | 5.0s |  |
| 786 | `netstream_flv_date` | 4 | 4.8s |  |
| 787 | `newactivation_in_script_init` | 3 | 4.8s |  |
| 788 | `newclass_mismatched` | 4 | 4.8s |  |
| 789 | `newclass_twice` | 3 | 4.9s |  |
| 790 | `nonconflicting_declarations` | 0 | 2.0s |  |
| 791 | `null_void_types` | 8 | 5.1s |  |
| 792 | `number_autoconv` | 21 | 1.7s |  |
| 793 | `number_autoconv_amf` | 132 | 4.9s |  |
| 794 | `number_autoconv_array_sort_32bit` | 1 | 5.4s |  |
| 795 | `number_constr` | 58 | 5.2s |  |
| 796 | `number_convert_edge_cases` | 180 | 17.8s |  |
| 797 | `number_toexponential` | 378 | 5.0s |  |
| 798 | `number_toexponential2` | 35 | 1.5s |  |
| 799 | `number_tofixed` | 378 | 4.6s |  |
| 800 | `number_toprecision` | 350 | 4.6s |  |
| 801 | `obfuscated_class_names` | 3 | 4.6s |  |
| 802 | `object_enumeration` | 10 | 4.6s |  |
| 803 | `object_prototype` | 4 | 4.9s |  |
| 804 | `object_to_locale_string` | 2 | 4.8s |  |
| 805 | `object_to_string` | 2 | 4.7s |  |
| 806 | `object_value_of` | 2 | 1.4s |  |
| 807 | `op_coerce` | 54 | 4.8s |  |
| 808 | `op_coerce_x` | 54 | 5.0s |  |
| 809 | `op_escxattr` | 2 | 4.7s |  |
| 810 | `op_escxelem` | 2 | 4.9s |  |
| 811 | `op_lookupswitch` | 4 | 4.7s |  |
| 812 | `optimize_coerce` | 1 | 4.8s |  |
| 813 | `orphan_movie_complex` | 80 | 5.4s |  |
| 814 | `orphan_movie_reorder` | 111 | 16.8s |  |
| 815 | `orphan_removeobject` | 636 | 28.3s |  |
| 816 | `package_namespace` | 7 | 27.8s |  |
| 817 | `param_default_value_has_zero_cpool_index` | 1 | 27.2s |  |
| 818 | `parent_early_access_child` | 16 | 27.9s |  |
| 819 | `parse_float` | 81 | 7.8s |  |
| 820 | `parse_float_swf10` | 81 | 7.4s |  |
| 821 | `parse_int` | 135 | 8.2s |  |
| 822 | `perspective_projection` | 1443 | 28.7s |  |
| 823 | `perspective_projection_basic` | 40 | 7.6s |  |
| 824 | `pixelbender_ceil` | 77 | 7.8s |  |
| 825 | `pixelbender_conditional` | 138 | 8.0s |  |
| 826 | `pixelbender_conversions` | 270 | 7.9s |  |
| 827 | `pixelbender_dithering` | 8 | 32.5s |  |
| 828 | `pixelbender_div` | 36 | 7.4s |  |
| 829 | `pixelbender_effect_BlurredFocus` | 0 | 36.5s |  |
| 830 | `pixelbender_effect_glassDisplace` | 0 | 13.6s |  |
| 831 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 31.5s |  |
| 832 | `pixelbender_effect_smudge` | 0 | 11.2s |  |
| 833 | `pixelbender_effect_tintype` | 0 | 10.1s |  |
| 834 | `pixelbender_effect_twirl` | 0 | 11.6s |  |
| 835 | `pixelbender_eof` | 7 | 7.5s |  |
| 836 | `pixelbender_images` | 0 | 9.6s |  |
| 837 | `pixelbender_input` | 103 | 28.2s |  |
| 838 | `pixelbender_logicalnot` | 20 | 7.7s |  |
| 839 | `pixelbender_malformed_data` | 190 | 28.0s |  |
| 840 | `pixelbender_multiple_out_params` | 1 | 7.4s |  |
| 841 | `pixelbender_no_out_param` | 6 | 7.5s |  |
| 842 | `pixelbender_outputs` | 13 | 7.6s |  |
| 843 | `pixelbender_padding_bytes` | 22 | 7.5s |  |
| 844 | `pixelbender_param_qualifier` | 512 | 7.7s |  |
| 845 | `pixelbender_parameters` | 1563 | 7.8s |  |
| 846 | `pixelbender_parameters_bool` | 240 | 7.9s |  |
| 847 | `pixelbender_parameters_int_vs_bool` | 54 | 7.8s |  |
| 848 | `pixelbender_parse_errors` | 6 | 7.6s |  |
| 849 | `pixelbender_rsqrt` | 24 | 7.8s |  |
| 850 | `pixelbender_select_kinds` | 8 | 7.9s |  |
| 851 | `pixelbender_shaderdata` | 49 | 7.9s |  |
| 852 | `pixelbender_shaderdata_setter` | 99 | 8.0s |  |
| 853 | `pixelbender_sign` | 60 | 7.8s |  |
| 854 | `pixelbender_vector_output` | 11 | 7.9s |  |
| 855 | `place_and_lookup/swf10` | 33 | 7.8s |  |
| 856 | `place_and_lookup/swf9` | 33 | 0.7s |  |
| 857 | `place_multiple` | 17 | 21.7s |  |
| 858 | `place_object_replace` | 9 | 21.8s |  |
| 859 | `place_object_replace_2` | 24 | 21.8s |  |
| 860 | `place_object_same_depth_frame` | 1 | 22.2s |  |
| 861 | `point` | 132 | 6.4s |  |
| 862 | `primitive_edge_cases` | 1 | 5.9s |  |
| 863 | `primitive_keys` | 54 | 6.0s |  |
| 864 | `primitive_toString` | 277 | 6.3s |  |
| 865 | `primitive_valueOf` | 285 | 5.9s |  |
| 866 | `print_job_options` | 3 | 5.9s |  |
| 867 | `property_is_enumerable` | 114 | 6.4s |  |
| 868 | `property_is_enumerable_reset` | 23 | 6.0s |  |
| 869 | `property_priority` | 22 | 6.2s |  |
| 870 | `property_priority_chained` | 4 | 5.9s |  |
| 871 | `property_priority_definition_names_order` | 2 | 6.2s |  |
| 872 | `property_priority_three_level` | 6 | 6.2s |  |
| 873 | `propertyisenumerable_namespaces` | 6 | 6.2s |  |
| 874 | `prototype_set_null` | 7 | 5.9s |  |
| 875 | `proxy_callproperty` | 24 | 6.0s |  |
| 876 | `proxy_deleteproperty` | 64 | 6.1s |  |
| 877 | `proxy_enumeration` | 34 | 6.0s |  |
| 878 | `proxy_getproperty` | 77 | 6.1s |  |
| 879 | `proxy_hasownproperty` | 8 | 2.0s |  |
| 880 | `proxy_hasproperty` | 32 | 6.0s |  |
| 881 | `proxy_not_overridden` | 54 | 6.0s |  |
| 882 | `proxy_serialize` | 9 | 6.1s |  |
| 883 | `proxy_setproperty` | 42 | 6.0s |  |
| 884 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.9s |  |
| 885 | `qname_constr` | 32 | 6.0s |  |
| 886 | `qname_constr_namespace` | 24 | 6.0s |  |
| 887 | `qname_enumeration` | 9 | 6.0s |  |
| 888 | `qname_indexing` | 23 | 2.0s |  |
| 889 | `qname_tostring` | 25 | 6.0s |  |
| 890 | `qname_valueof` | 29 | 6.1s |  |
| 891 | `rectangle` | 1094 | 6.6s |  |
| 892 | `regexp_constr` | 148 | 6.1s |  |
| 893 | `regexp_exec` | 19 | 5.9s |  |
| 894 | `regexp_extended` | 47 | 5.8s |  |
| 895 | `regexp_multiargs` | 1 | 5.9s |  |
| 896 | `regexp_test` | 27 | 2.0s |  |
| 897 | `regexp_toString` | 10 | 5.9s |  |
| 898 | `register_script_refresh` | 35 | 21.8s |  |
| 899 | `remove_child_clear_field` | 88 | 27.4s |  |
| 900 | `remove_dobj` | 3 | 26.9s |  |
| 901 | `resolve_order` | 4 | 7.4s |  |
| 902 | `responder_null_callbacks` | 1 | 27.2s |  |
| 903 | `rng` | 1 | 8.8s |  |
| 904 | `rootless` | 42 | 7.5s |  |
| 905 | `rshift` | 1058 | 19.6s |  |
| 906 | `rtqname_not_namespace` | 12 | 7.5s |  |
| 907 | `sandbox_type_inherited` | 2 | 7.7s |  |
| 908 | `sandbox_type_local_file` | 1 | 7.4s |  |
| 909 | `sandbox_type_local_network` | 1 | 7.2s |  |
| 910 | `scene_constr` | 8 | 7.4s |  |
| 911 | `scope_optimizations` | 4 | 7.3s |  |
| 912 | `scopes_dont_cache/order-1` | 1 | 27.0s |  |
| 913 | `scopes_dont_cache/order-2` | 1 | 0.4s |  |
| 914 | `security_domain_current` | 2 | 7.3s |  |
| 915 | `selection` | 239 | 7.8s |  |
| 916 | `set_local_0` | 31 | 2.5s |  |
| 917 | `set_property_is_enumerable` | 85 | 7.9s |  |
| 918 | `shaderparameter_value` | 4 | 7.4s |  |
| 919 | `shape_drawrect` | 54 | 7.5s |  |
| 920 | `shared_object_no_root` | 3 | 7.3s |  |
| 921 | `simplebutton_added_to_stage` | 45 | 27.3s |  |
| 922 | `simplebutton_childevents` | 86 | 27.1s |  |
| 923 | `simplebutton_childevents_nested` | 54 | 7.5s |  |
| 924 | `simplebutton_childevents_sprite` | 13 | 7.4s |  |
| 925 | `simplebutton_childprops` | 144 | 7.5s |  |
| 926 | `simplebutton_childshuffle` | 23 | 7.2s |  |
| 927 | `simplebutton_constr` | 36 | 7.5s |  |
| 928 | `simplebutton_constr_childevents` | 48 | 7.5s |  |
| 929 | `simplebutton_constr_params` | 42 | 7.4s |  |
| 930 | `simplebutton_mouseenabled` | 26 | 7.3s |  |
| 931 | `simplebutton_multi_children` | 19 | 7.5s |  |
| 932 | `simplebutton_soundtransform` | 887 | 28.6s |  |
| 933 | `simplebutton_structure` | 27 | 7.5s |  |
| 934 | `simplebutton_symbolclass` | 68 | 7.5s |  |
| 935 | `slot_disp_id_shared_numbering` | 1 | 26.2s |  |
| 936 | `slots_force_autoassigned` | 1 | 26.9s |  |
| 937 | `socket_after_disconnect` | 1 | 7.4s |  |
| 938 | `socket_close` | 2 | 7.4s |  |
| 939 | `socket_connect` | 4 | 7.4s |  |
| 940 | `socket_errors` | 56 | 7.9s |  |
| 941 | `socket_read_big` | 48 | 7.5s |  |
| 942 | `socket_read_little` | 48 | 2.4s |  |
| 943 | `socket_read_write_object` | 8 | 7.4s |  |
| 944 | `socket_write_big` | 15 | 7.8s |  |
| 945 | `socket_write_little` | 14 | 7.4s |  |
| 946 | `sound_constructor_with_args` | 6 | 7.6s |  |
| 947 | `sound_embeddedprops` | 26 | 7.6s |  |
| 948 | `sound_play` | 19 | 7.7s |  |
| 949 | `sound_rootless` | 7 | 7.5s |  |
| 950 | `sound_valueof` | 33 | 7.5s |  |
| 951 | `soundchannel_soundtransform` | 835 | 29.1s |  |
| 952 | `soundchannel_soundtransform_exists` | 5 | 26.9s |  |
| 953 | `soundchannel_stop` | 8 | 26.9s |  |
| 954 | `soundmixer_buffertime` | 5 | 7.4s |  |
| 955 | `soundmixer_soundtransform` | 900 | 9.4s |  |
| 956 | `soundmixer_stopall` | 6 | 27.0s |  |
| 957 | `soundtransform` | 442 | 13.2s |  |
| 958 | `space_justifier_clone` | 12 | 7.4s |  |
| 959 | `sprite_with_frames` | 0 | 27.1s |  |
| 960 | `stage3d_agal_cross_product` | 0 | 9.9s |  |
| 961 | `stage3d_agal_upload_errors` | 66 | 10.2s |  |
| 962 | `stage3d_bitmap` | 0 | 32.1s |  |
| 963 | `stage3d_blend` | 81 | 29.9s |  |
| 964 | `stage3d_context3d_string_args` | 158 | 8.5s |  |
| 965 | `stage3d_errors` | 7 | 7.5s |  |
| 966 | `stage3d_errors_atf` | 3 | 8.7s |  |
| 967 | `stage3d_errors_swf_29` | 6 | 7.6s |  |
| 968 | `stage3d_float1_index` | 0 | 29.8s |  |
| 969 | `stage3d_fractal` | 0 | 29.8s |  |
| 970 | `stage3d_ignore_sampler_override` | 0 | 29.7s |  |
| 971 | `stage3d_multistage_triangle` | 3 | 10.1s |  |
| 972 | `stage3d_program_constants_bytearray_be` | 0 | 31.6s |  |
| 973 | `stage3d_program_constants_bytearray_le` | 0 | 31.0s |  |
| 974 | `stage3d_program_constants_invalid_input` | 21 | 27.2s |  |
| 975 | `stage3d_raytrace` | 0 | 53.2s |  |
| 976 | `stage3d_rotating_cube` | 0 | 10.2s |  |
| 977 | `stage3d_sampler` | 0 | 9.5s |  |
| 978 | `stage3d_sampler_partial_upload` | 0 | 9.5s |  |
| 979 | `stage3d_stencil` | 0 | 29.7s |  |
| 980 | `stage3d_texture` | 0 | 15.1s |  |
| 981 | `stage3d_texture_bytearray` | 0 | 10.8s |  |
| 982 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.1s |  |
| 983 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.4s |  |
| 984 | `stage3d_triangle` | 0 | 9.6s |  |
| 985 | `stage3d_triangle_bytes4` | 0 | 9.5s |  |
| 986 | `stage3d_triangle_float1` | 0 | 9.6s |  |
| 987 | `stage3d_triangle_index_upload` | 0 | 9.6s |  |
| 988 | `stage3d_x_y` | 22 | 7.1s |  |
| 989 | `stage_access` | 10 | 7.2s |  |
| 990 | `stage_display_state` | 6 | 7.1s |  |
| 991 | `stage_displayobject_properties` | 24 | 7.0s |  |
| 992 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.0s |  |
| 993 | `stage_framerate_nan` | 7 | 7.0s |  |
| 994 | `stage_framerate_negative` | 6 | 7.0s |  |
| 995 | `stage_framerate_zero` | 6 | 7.1s |  |
| 996 | `stage_invalidate` | 38 | 7.3s |  |
| 997 | `stage_loaderinfo_properties` | 24 | 26.9s |  |
| 998 | `stage_mousechildren` | 2 | 7.0s |  |
| 999 | `stage_mouseenabled` | 15 | 7.0s |  |
| 1000 | `stage_overriden_setters` | 31 | 7.2s |  |
| 1001 | `stage_properties` | 30 | 7.0s |  |
| 1002 | `stage_properties2` | 213 | 7.1s |  |
| 1003 | `stage_scale_factor` | 12 | 30.3s |  |
| 1004 | `stage_stage3Ds_vector` | 1 | 7.0s |  |
| 1005 | `static_length` | 24 | 7.1s |  |
| 1006 | `static_text` | 3 | 7.2s |  |
| 1007 | `static_var_with_this_in_ctor` | 2 | 7.1s |  |
| 1008 | `statictext_text` | 8 | 7.1s |  |
| 1009 | `stored_properties` | 11 | 7.0s |  |
| 1010 | `strict_equality` | 34 | 7.1s |  |
| 1011 | `string_call` | 13 | 7.1s |  |
| 1012 | `string_case` | 23 | 7.0s |  |
| 1013 | `string_char_at` | 27 | 7.0s |  |
| 1014 | `string_char_code_at` | 28 | 2.0s |  |
| 1015 | `string_concat_fromcharcode` | 37 | 26.3s |  |
| 1016 | `string_constr` | 25 | 26.3s |  |
| 1017 | `string_indexof_lastindexof` | 87 | 7.3s |  |
| 1018 | `string_length` | 16 | 7.2s |  |
| 1019 | `string_locale_compare` | 39 | 7.5s |  |
| 1020 | `string_match` | 51 | 7.4s |  |
| 1021 | `string_relational_compare` | 4 | 7.0s |  |
| 1022 | `string_replace` | 51 | 7.4s |  |
| 1023 | `string_search` | 41 | 7.5s |  |
| 1024 | `string_slice_substr_substring` | 170 | 8.0s |  |
| 1025 | `string_split` | 29 | 7.0s |  |
| 1026 | `string_substr_negative` | 21 | 7.0s |  |
| 1027 | `string_substr_weird` | 182 | 7.0s |  |
| 1028 | `stylesheet` | 221 | 7.5s |  |
| 1029 | `stylesheet_parse_color` | 69 | 7.0s |  |
| 1030 | `stylesheet_transform` | 307 | 7.3s |  |
| 1031 | `sub_super_same_field` | 12 | 2.1s |  |
| 1032 | `subclass_superclass_linked_symbol` | 4 | 7.4s |  |
| 1033 | `subtract` | 1058 | 16.4s |  |
| 1034 | `super_get_call` | 12 | 7.0s |  |
| 1035 | `supercall_two_classobjects` | 2 | 7.0s |  |
| 1036 | `supercalls_coerce` | 8 | 7.1s |  |
| 1037 | `supercalls_weird` | 2 | 6.7s |  |
| 1038 | `superinterface_call` | 20 | 7.0s |  |
| 1039 | `superinterface_instanceof` | 18 | 7.1s |  |
| 1040 | `swf8` | 1 | 7.1s |  |
| 1041 | `swf_10_queued_goto_scripts_construct` | 52 | 26.7s |  |
| 1042 | `swf_9_goto_in_enter_frame` | 17 | 7.2s |  |
| 1043 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.1s |  |
| 1044 | `swf_9_queued_goto_scripts` | 6 | 26.6s |  |
| 1045 | `swf_9_queued_goto_scripts_construct` | 28 | 0.6s |  |
| 1046 | `swf_9_versioning` | 2 | 6.9s |  |
| 1047 | `swf_wrong_frame_count` | 38 | 7.2s |  |
| 1048 | `swf_wrong_frame_count_isplaying` | 22 | 7.0s |  |
| 1049 | `symbol_class_binary_data` | 8 | 7.0s |  |
| 1050 | `symbol_class_conflict` | 4 | 7.1s |  |
| 1051 | `symbol_class_root_not_zero` | 1 | 6.9s |  |
| 1052 | `symbolclass_invalid_utf8` | 2 | 7.0s |  |
| 1053 | `system_exit` | 3 | 7.0s |  |
| 1054 | `system_setclipboard_null` | 1 | 6.9s |  |
| 1055 | `tab_ordering_arrows` | 998 | 15.7s |  |
| 1056 | `tab_ordering_automatic_advanced` | 184 | 0.4s |  |
| 1057 | `tab_ordering_automatic_basic` | 45 | 15.6s |  |
| 1058 | `tab_ordering_children` | 116 | 0.4s |  |
| 1059 | `tab_ordering_custom_basic` | 34 | 0.4s |  |
| 1060 | `tab_ordering_stage_tab_children` | 32 | 0.4s |  |
| 1061 | `tab_ordering_stage_tab_children_remove_root` | 5 | 0.4s |  |
| 1062 | `tab_ordering_tabbable` | 47 | 0.4s |  |
| 1063 | `tabstop_properties` | 105 | 15.7s |  |
| 1064 | `text_element_basic` | 34 | 0.4s |  |
| 1065 | `text_engine_fontdescription` | 27 | 0.4s |  |
| 1066 | `text_engine_groupelement` | 64 | 0.4s |  |
| 1067 | `text_run` | 7 | 0.4s |  |
| 1068 | `textblock_createline_errors` | 23 | 0.4s |  |
| 1069 | `textblock_createline_fte` | 9 | 15.7s |  |
| 1070 | `textblock_properties` | 118 | 0.4s |  |
| 1071 | `textbox_click` | 37 | 15.8s |  |
| 1072 | `textfield_event` | 66 | 0.5s |  |
| 1073 | `textfield_focusin_event` | 9 | 0.4s |  |
| 1074 | `textfield_input_dead_keys_windows` | 15 | 0.4s |  |
| 1075 | `textfield_input_events` | 25 | 9.6s |  |
| 1076 | `textfield_unload` | 39 | 15.7s |  |
| 1077 | `textformat` | 1134 | 0.4s |  |
| 1078 | `textformat_display` | 14 | 0.4s |  |
| 1079 | `textformat_font_max_length` | 4 | 0.4s |  |
| 1080 | `textline_inapplicable_properties` | 10 | 0.4s |  |
| 1081 | `textline_name` | 1 | 0.4s |  |
| 1082 | `textline_raw_text_length` | 30 | 0.4s |  |
| 1083 | `textline_splitting_basic` | 76 | 0.5s |  |
| 1084 | `textline_throwerror` | 30 | 0.4s |  |
| 1085 | `textline_validity` | 162 | 0.4s |  |
| 1086 | `throw` | 3 | 0.4s |  |
| 1087 | `timeline_scripts` | 3 | 15.7s |  |
| 1088 | `timer` | 90 | 0.4s |  |
| 1089 | `timer_events` | 3 | 0.4s |  |
| 1090 | `timer_finished` | 11 | 0.4s |  |
| 1091 | `timer_invalid_delay` | 30 | 0.4s |  |
| 1092 | `timer_reset` | 8 | 27.3s |  |
| 1093 | `timer_setdelay` | 5 | 27.3s |  |
| 1094 | `trace` | 12 | 7.5s |  |
| 1095 | `truthiness` | 30 | 7.7s |  |
| 1096 | `try_catch` | 11 | 7.8s |  |
| 1097 | `try_catch_typed` | 12 | 7.7s |  |
| 1098 | `typeof` | 30 | 7.5s |  |
| 1099 | `uint_constr` | 92 | 7.8s |  |
| 1100 | `uint_tofixed` | 1215 | 7.5s |  |
| 1101 | `uint_toprecision` | 1125 | 7.6s |  |
| 1102 | `uint_tostring` | 3375 | 7.8s |  |
| 1103 | `uncaught_error_basic` | 2 | 7.4s |  |
| 1104 | `unchecked_function` | 15 | 7.4s |  |
| 1105 | `unescape` | 28 | 7.4s |  |
| 1106 | `url_loader` | 25 | 7.5s |  |
| 1107 | `url_vars` | 27 | 7.6s |  |
| 1108 | `urlrequest` | 18 | 2.4s |  |
| 1109 | `urlstream_basic` | 5 | 7.6s |  |
| 1110 | `urshift` | 1058 | 19.5s |  |
| 1111 | `utils3d` | 7 | 2.4s |  |
| 1112 | `vector3d` | 397 | 12.1s |  |
| 1113 | `vector3d_near_equals` | 80 | 7.5s |  |
| 1114 | `vector_class` | 36 | 7.8s |  |
| 1115 | `vector_class_call` | 11 | 7.6s |  |
| 1116 | `vector_coercion` | 66 | 8.1s |  |
| 1117 | `vector_concat` | 90 | 7.9s |  |
| 1118 | `vector_constr` | 107 | 8.1s |  |
| 1119 | `vector_enumeration` | 5 | 7.4s |  |
| 1120 | `vector_every` | 92 | 8.1s |  |
| 1121 | `vector_filter` | 95 | 8.2s |  |
| 1122 | `vector_holes` | 24 | 7.5s |  |
| 1123 | `vector_indexof` | 302 | 12.3s |  |
| 1124 | `vector_insertat` | 270 | 8.7s |  |
| 1125 | `vector_int_access` | 4 | 7.2s |  |
| 1126 | `vector_int_delete` | 11 | 7.3s |  |
| 1127 | `vector_join` | 58 | 7.8s |  |
| 1128 | `vector_lastindexof` | 302 | 7.3s |  |
| 1129 | `vector_legacy` | 10 | 7.4s |  |
| 1130 | `vector_map` | 85 | 8.0s |  |
| 1131 | `vector_object_final` | 1 | 7.2s |  |
| 1132 | `vector_object_toString` | 10 | 27.6s |  |
| 1133 | `vector_pushpop` | 255 | 28.4s |  |
| 1134 | `vector_reborrow_bug` | 10 | 7.3s |  |
| 1135 | `vector_removeat` | 172 | 8.3s |  |
| 1136 | `vector_reverse` | 232 | 8.4s |  |
| 1137 | `vector_shiftunshift` | 252 | 7.0s |  |
| 1138 | `vector_slice` | 331 | 8.8s |  |
| 1139 | `vector_sort` | 905 | 16.9s |  |
| 1140 | `vector_splice` | 693 | 11.2s |  |
| 1141 | `vector_splice_fixed_bug_compat` | 4 | 7.2s |  |
| 1142 | `vector_tostring` | 79 | 7.7s |  |
| 1143 | `verification` | 8 | 7.3s |  |
| 1144 | `verify_abnormal_loop` | 1 | 7.0s |  |
| 1145 | `verify_dxns_without_flag` | 3 | 7.3s |  |
| 1146 | `verify_exception_target_two_jumps` | 1 | 7.0s |  |
| 1147 | `verify_exception_targets_edge_case` | 1 | 7.0s |  |
| 1148 | `verify_illegal_opcode` | 1 | 2.2s |  |
| 1149 | `verify_jump_to_middle_of_op` | 1 | 6.9s |  |
| 1150 | `verify_lookup_switch_edge_case` | 1 | 6.8s |  |
| 1151 | `verify_method_info_oob` | 1 | 0.5s |  |
| 1152 | `verify_stack` | 5 | 7.0s |  |
| 1153 | `verify_typecheck` | 4 | 6.9s |  |
| 1154 | `verify_unreachable_exception` | 2 | 6.8s |  |
| 1155 | `versioned_isplaying` | 2 | 6.9s |  |
| 1156 | `virtual_properties` | 16 | 2.1s |  |
| 1157 | `with` | 4 | 6.9s |  |
| 1158 | `wrong_arg_count` | 7 | 7.0s |  |
| 1159 | `xml_abstract_equality` | 36 | 7.2s |  |
| 1160 | `xml_advanced` | 52 | 7.0s |  |
| 1161 | `xml_appendchild` | 10 | 7.0s |  |
| 1162 | `xml_appendchild_swf_v21` | 13 | 2.2s |  |
| 1163 | `xml_as_attribute` | 9 | 7.0s |  |
| 1164 | `xml_attribute` | 35 | 7.2s |  |
| 1165 | `xml_attribute_name` | 40 | 7.1s |  |
| 1166 | `xml_basic` | 33 | 7.1s |  |
| 1167 | `xml_child` | 25 | 7.1s |  |
| 1168 | `xml_childindex` | 7 | 7.0s |  |
| 1169 | `xml_children` | 43 | 7.5s |  |
| 1170 | `xml_class_call` | 9 | 7.0s |  |
| 1171 | `xml_contains` | 197 | 7.2s |  |
| 1172 | `xml_copy` | 20 | 29.3s |  |
| 1173 | `xml_ctor_from_tostring` | 23 | 29.4s |  |
| 1174 | `xml_delete` | 114 | 7.9s |  |
| 1175 | `xml_descendants` | 83 | 7.9s |  |
| 1176 | `xml_duplicate_attribute` | 14 | 7.9s |  |
| 1177 | `xml_elements` | 6 | 7.8s |  |
| 1178 | `xml_equals_namespace_check` | 2 | 7.8s |  |
| 1179 | `xml_explicit_use_namespace` | 5 | 7.7s |  |
| 1180 | `xml_getdescendants_qname` | 21 | 7.9s |  |
| 1181 | `xml_has_property_via_in` | 26 | 7.8s |  |
| 1182 | `xml_hasownproperty` | 6 | 7.8s |  |
| 1183 | `xml_ignore_white` | 6 | 7.7s |  |
| 1184 | `xml_length` | 2 | 7.9s |  |
| 1185 | `xml_list_as_attribute` | 9 | 7.8s |  |
| 1186 | `xml_list_concat` | 20 | 7.9s |  |
| 1187 | `xml_list_ctor_errors` | 34 | 7.9s |  |
| 1188 | `xml_list_delete_clear_parent` | 6 | 7.9s |  |
| 1189 | `xml_list_enumerate` | 4 | 7.8s |  |
| 1190 | `xml_methods_settings` | 3 | 7.8s |  |
| 1191 | `xml_mismatched_tag` | 37 | 7.8s |  |
| 1192 | `xml_namespace` | 39 | 7.8s |  |
| 1193 | `xml_namespace_methods` | 245 | 7.9s |  |
| 1194 | `xml_namespaced_property` | 7 | 7.8s |  |
| 1195 | `xml_no_namespace` | 1 | 7.8s |  |
| 1196 | `xml_nodekind` | 3 | 7.8s |  |
| 1197 | `xml_normalize` | 35 | 7.9s |  |
| 1198 | `xml_notification_bubbling` | 361 | 7.8s |  |
| 1199 | `xml_parent` | 8 | 7.8s |  |
| 1200 | `xml_set_children` | 17 | 8.0s |  |
| 1201 | `xml_set_name` | 34 | 8.0s |  |
| 1202 | `xml_settings` | 6 | 2.6s |  |
| 1203 | `xml_simple_complex_content` | 47 | 7.9s |  |
| 1204 | `xml_socket` | 11 | 8.4s |  |
| 1205 | `xml_text` | 7 | 8.2s |  |
| 1206 | `xml_tostring` | 6 | 7.7s |  |
| 1207 | `xml_tostring_namespace` | 12 | 7.5s |  |
| 1208 | `xml_unescaping` | 23 | 8.3s |  |
| 1209 | `xml_weird_ignores` | 54 | 2.9s |  |
| 1210 | `xml_wildcard` | 11 | 7.9s |  |
| 1211 | `xmldocument` | 254 | 8.4s |  |
| 1212 | `xmlnode` | 3540 | 8.2s |  |
| 1213 | `zero_frame_clip` | 3 | 8.5s |  |

## Ruffle-Matched Tests

**36 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 5.0s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.2s |  |
| 3 | `blend_transform` | 1 | 1 | 7.3s |  |
| 4 | `bounds_mode` | 6 | 6 | 6.2s |  |
| 5 | `coerce_property` | 3 | 3 | 4.6s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 4.6s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 27.6s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 27.6s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 5.2s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.2s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.2s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 7.4s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 21.5s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 7.3s |  |
| 15 | `event_handler_exception` | 4 | 4 | 7.2s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 7.4s |  |
| 17 | `goto_framescript_queued/swf13` | 42 | 42 | 0.7s |  |
| 18 | `graphics_draw_path` | 50 | 50 | 27.4s |  |
| 19 | `groupelement_text` | 2 | 2 | 7.4s |  |
| 20 | `int_toexponential` | 76 | 76 | 7.3s |  |
| 21 | `json_parse_numbers` | 4 | 79 | 7.3s |  |
| 22 | `loader_events_2` | 30 | 30 | 7.0s |  |
| 23 | `matrix3d_recompose_edge_cases` | 8 | 85 | 7.5s |  |
| 24 | `number_convert_errors` | 706 | 706 | 5.0s |  |
| 25 | `simplebutton_childevents_script_order` | 4 | 4 | 7.5s |  |
| 26 | `slot_holes_fail` | 1 | 1 | 7.2s |  |
| 27 | `slot_id_exceeds_trait_count` | 1 | 1 | 26.9s |  |
| 28 | `soundchannel_position` | 74 | 74 | 27.9s |  |
| 29 | `soundchannel_soundcomplete` | 10 | 10 | 7.7s |  |
| 30 | `sprite_dropTarget` | 15 | 15 | 7.5s |  |
| 31 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.6s |  |
| 32 | `textblock_line_changes` | 44 | 44 | 0.4s |  |
| 33 | `textblock_releaselines` | 4 | 4 | 0.4s |  |
| 34 | `uint_toexponential` | 100 | 100 | 7.7s |  |
| 35 | `uncaught_errors_stringified` | 15 | 15 | 7.5s |  |
| 36 | `weird_superinterface_properties` | 1 | 1 | 6.9s |  |

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
