# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-19 20:20 UTC

**Git SHA**: `c1fa89bc20`

**Run Duration**: 205m 16s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1300 |
| Passing | **1234** (94.9%) |
| Ruffle-matched | 42 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1276** (98.2%) |
| Failing | 24 |
| Total expected lines | 160133 |
| Matching lines | 156721 (97.9%) |
| Mismatched lines | 3412 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 24 | 100.0% |

## Passing Tests

**1234 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 9.6s |  |
| 2 | `accessibility` | 1 | 8.8s |  |
| 3 | `accessibilityimplementation` | 18 | 8.9s |  |
| 4 | `activation_class` | 6 | 8.8s |  |
| 5 | `add` | 1058 | 20.2s |  |
| 6 | `agal_compiler` | 13 | 11.8s |  |
| 7 | `air_datagram_socket` | 1 | 11.1s |  |
| 8 | `air_hidden_lookup` | 2 | 9.0s |  |
| 9 | `air_ifilepromise` | 1 | 9.5s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 9.4s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.4s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.4s |  |
| 13 | `all_classes/display/swf10` | 2569 | 9.3s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.5s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.5s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.5s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.4s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.4s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 9.3s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.4s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.4s |  |
| 22 | `all_classes/errors/swf10` | 140 | 9.3s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.4s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.4s |  |
| 25 | `all_classes/events/swf10` | 1638 | 9.4s |  |
| 26 | `all_classes/events/swf11` | 1750 | 1.4s |  |
| 27 | `all_classes/events/swf12` | 1814 | 1.4s |  |
| 28 | `all_classes/events/swf30` | 2353 | 1.4s |  |
| 29 | `all_classes/events/swf9` | 1030 | 1.4s |  |
| 30 | `all_classes/security/swf11` | 3 | 9.3s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.4s |  |
| 32 | `all_classes/security/swf13` | 53 | 1.4s |  |
| 33 | `all_classes/security/swf30` | 53 | 1.4s |  |
| 34 | `all_classes/xml/swf30` | 116 | 9.3s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.4s |  |
| 36 | `amf_array_serialization` | 17 | 33.6s |  |
| 37 | `amf_custom_obj` | 26 | 9.5s |  |
| 38 | `amf_dictionary` | 9 | 9.3s |  |
| 39 | `amf_function` | 46 | 9.3s |  |
| 40 | `amf_invalid_date` | 2 | 9.2s |  |
| 41 | `amf_missing_prop` | 6 | 9.3s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 3.5s |  |
| 43 | `amf_setter_error` | 8 | 9.4s |  |
| 44 | `amf_vector` | 40 | 9.5s |  |
| 45 | `amf_xml` | 6 | 1.8s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 1.1s |  |
| 47 | `application_domain` | 4 | 1.1s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 1.1s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 1.1s |  |
| 50 | `array_access` | 18 | 1.1s |  |
| 51 | `array_access_interpreter` | 4 | 1.1s |  |
| 52 | `array_access_no_pubns` | 2 | 1.1s |  |
| 53 | `array_concat` | 41 | 1.1s |  |
| 54 | `array_constr` | 10 | 1.1s |  |
| 55 | `array_delete` | 44 | 1.1s |  |
| 56 | `array_enumeration` | 10 | 1.1s |  |
| 57 | `array_enumeration_elements` | 11 | 1.1s |  |
| 58 | `array_every` | 8 | 1.1s |  |
| 59 | `array_filter` | 6 | 1.1s |  |
| 60 | `array_foreach` | 18 | 1.1s |  |
| 61 | `array_hasownproperty` | 11 | 1.1s |  |
| 62 | `array_holes` | 9 | 1.1s |  |
| 63 | `array_index_max` | 84 | 1.1s |  |
| 64 | `array_indexof` | 25 | 1.1s |  |
| 65 | `array_join` | 26 | 1.1s |  |
| 66 | `array_lastindexof` | 29 | 1.1s |  |
| 67 | `array_length` | 14 | 1.1s |  |
| 68 | `array_literal` | 3 | 1.1s |  |
| 69 | `array_map` | 8 | 1.1s |  |
| 70 | `array_pop` | 52 | 1.1s |  |
| 71 | `array_push` | 24 | 1.1s |  |
| 72 | `array_reborrow_bug` | 6 | 1.1s |  |
| 73 | `array_reverse` | 28 | 1.2s |  |
| 74 | `array_shift` | 51 | 1.2s |  |
| 75 | `array_slice` | 39 | 1.1s |  |
| 76 | `array_some` | 8 | 1.2s |  |
| 77 | `array_sort` | 297 | 1.2s |  |
| 78 | `array_sort_fun_swf12` | 2 | 1.1s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 80 | `array_sort_random` | 210 | 1.1s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 1.1s |  |
| 82 | `array_sorton` | 545 | 1.1s |  |
| 83 | `array_sparse_ops` | 41 | 1.1s |  |
| 84 | `array_splice` | 133 | 1.1s |  |
| 85 | `array_splice2` | 428 | 1.5s |  |
| 86 | `array_splice_types` | 48 | 1.0s |  |
| 87 | `array_storage` | 8 | 7.4s |  |
| 88 | `array_tolocalestring` | 9 | 7.6s |  |
| 89 | `array_tostring` | 12 | 7.7s |  |
| 90 | `array_unshift` | 24 | 7.5s |  |
| 91 | `array_valueof` | 9 | 7.4s |  |
| 92 | `array_vector_null_callback` | 10 | 7.6s |  |
| 93 | `astype` | 28 | 7.7s |  |
| 94 | `astypelate` | 24 | 7.8s |  |
| 95 | `astypelate_propagates` | 1 | 7.7s |  |
| 96 | `asymmetric_key_events` | 11 | 7.8s |  |
| 97 | `automation_classes` | 122 | 7.9s |  |
| 98 | `av_classes` | 340 | 7.9s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 7.5s |  |
| 100 | `avm2_catchup_dobj` | 158 | 8.3s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 90.8s |  |
| 102 | `bevel_filter` | 187 | 7.8s |  |
| 103 | `bitand` | 1058 | 16.0s |  |
| 104 | `bitmap_constr` | 17 | 7.7s |  |
| 105 | `bitmap_data` | 1000 | 16.1s |  |
| 106 | `bitmap_filter_abstract` | 6 | 7.4s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 24.1s |  |
| 108 | `bitmap_properties` | 23 | 3.1s |  |
| 109 | `bitmap_subclass` | 7 | 9.2s |  |
| 110 | `bitmap_subclass_properties` | 9 | 7.9s |  |
| 111 | `bitmap_timeline` | 9 | 8.1s |  |
| 112 | `bitmapdata_accuracy` | 1 | 42.2s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 24.6s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.5s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 24.3s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.0s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 24.1s |  |
| 118 | `bitmapdata_clone` | 13 | 7.7s |  |
| 119 | `bitmapdata_colortransform` | 0 | 7.9s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 7.5s |  |
| 121 | `bitmapdata_constr` | 22 | 7.8s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 7.8s |  |
| 123 | `bitmapdata_copychannel` | 0 | 25.8s |  |
| 124 | `bitmapdata_copypixels` | 23 | 25.4s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 7.5s |  |
| 126 | `bitmapdata_copypixels_alpha_merge` | 9 | 7.4s |  |
| 127 | `bitmapdata_copypixels_blend` | 1029 | 6.2s |  |
| 128 | `bitmapdata_copypixels_blend_over` | 1 | 5.6s |  |
| 129 | `bitmapdata_copypixels_self` | 612 | 5.6s |  |
| 130 | `bitmapdata_copypixelstobytearray` | 39 | 5.6s |  |
| 131 | `bitmapdata_dispose` | 7 | 5.5s |  |
| 132 | `bitmapdata_draw` | 0 | 18.2s |  |
| 133 | `bitmapdata_draw_alpha_erase` | 8 | 5.7s |  |
| 134 | `bitmapdata_draw_cab_quality` | 0 | 18.4s |  |
| 135 | `bitmapdata_draw_colortransform` | 0 | 5.7s |  |
| 136 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 17.8s |  |
| 137 | `bitmapdata_draw_filters` | 0 | 17.6s |  |
| 138 | `bitmapdata_draw_masks` | 0 | 5.6s |  |
| 139 | `bitmapdata_draw_rotation` | 0 | 5.7s |  |
| 140 | `bitmapdata_draw_self_via_graphic` | 0 | 5.6s |  |
| 141 | `bitmapdata_draw_stage` | 0 | 17.5s |  |
| 142 | `bitmapdata_drawwithquality` | 0 | 5.9s |  |
| 143 | `bitmapdata_embedded` | 9 | 5.8s |  |
| 144 | `bitmapdata_fillrect` | 0 | 5.6s |  |
| 145 | `bitmapdata_filter_sourcerect` | 0 | 17.9s |  |
| 146 | `bitmapdata_floodfill` | 35 | 5.6s |  |
| 147 | `bitmapdata_getpixels` | 39 | 17.6s |  |
| 148 | `bitmapdata_getvector` | 27 | 2.1s |  |
| 149 | `bitmapdata_histogram` | 59 | 2.2s |  |
| 150 | `bitmapdata_hittest` | 112 | 5.9s |  |
| 151 | `bitmapdata_hittest_threshold` | 18 | 5.6s |  |
| 152 | `bitmapdata_opaque` | 0 | 5.6s |  |
| 153 | `bitmapdata_pixeldissolve` | 1037 | 6.0s |  |
| 154 | `bitmapdata_pixeldissolve_image` | 0 | 5.7s |  |
| 155 | `bitmapdata_rectangle_rounding` | 16 | 5.6s |  |
| 156 | `bitmapdata_setpixels` | 286 | 5.7s |  |
| 157 | `bitmapdata_setvector` | 26 | 5.7s |  |
| 158 | `bitmapdata_sync` | 0 | 17.7s |  |
| 159 | `bitmapdata_threshold` | 176 | 6.0s |  |
| 160 | `bitmapdata_zero_size` | 8 | 5.6s |  |
| 161 | `bitnot` | 46 | 5.5s |  |
| 162 | `bitor` | 1058 | 11.4s |  |
| 163 | `bitxor` | 1058 | 11.3s |  |
| 164 | `blend_mode_null` | 1 | 5.5s |  |
| 165 | `blend_multiply_alpha` | 0 | 5.6s |  |
| 166 | `blend_scroll` | 0 | 5.6s |  |
| 167 | `blend_shader_luma_lighten` | 3 | 5.9s |  |
| 168 | `blur_filter` | 43 | 5.7s |  |
| 169 | `boolean_constr` | 32 | 2.6s |  |
| 170 | `boolean_negation` | 30 | 5.9s |  |
| 171 | `boolean_tostring` | 8 | 5.8s |  |
| 172 | `broadcast_event` | 7 | 5.8s |  |
| 173 | `button_bounds` | 1 | 5.9s |  |
| 174 | `button_hittest` | 2 | 18.6s |  |
| 175 | `button_nested_frame` | 48 | 18.5s |  |
| 176 | `button_nested_frame_simple` | 27 | 6.0s |  |
| 177 | `bytearray` | 48 | 6.0s |  |
| 178 | `bytearray_bad_symbol_class` | 3 | 5.8s |  |
| 179 | `bytearray_bad_symbol_class_other_movie` | 6 | 2.5s |  |
| 180 | `bytearray_compress` | 31 | 5.9s |  |
| 181 | `bytearray_errors` | 24 | 6.0s |  |
| 182 | `bytearray_method_serialization` | 1 | 5.8s |  |
| 183 | `bytearray_oom` | 3 | 5.8s |  |
| 184 | `bytearray_readobject_amf0` | 50 | 6.0s |  |
| 185 | `bytearray_readobject_amf3` | 53 | 5.9s |  |
| 186 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 187 | `bytearray_serialization` | 3 | 5.8s |  |
| 188 | `bytearray_string_null` | 19 | 6.1s |  |
| 189 | `bytearray_tostring` | 15 | 5.8s |  |
| 190 | `bytearray_utf16` | 8 | 2.2s |  |
| 191 | `bytearray_writeobject` | 24 | 5.8s |  |
| 192 | `callee_in_initializer` | 6 | 5.8s |  |
| 193 | `callproplex_class` | 1 | 5.8s |  |
| 194 | `capabilities_resolution` | 8 | 19.1s |  |
| 195 | `casi32` | 166 | 5.8s |  |
| 196 | `catch_class` | 6 | 5.8s |  |
| 197 | `catch_scope_slot` | 7 | 5.9s |  |
| 198 | `checkfilter` | 4 | 2.2s |  |
| 199 | `class_call` | 32 | 2.4s |  |
| 200 | `class_cast_call` | 14 | 5.8s |  |
| 201 | `class_enumeration` | 4 | 5.8s |  |
| 202 | `class_has_own_property` | 2 | 5.7s |  |
| 203 | `class_init_interpreter_mode` | 1 | 5.8s |  |
| 204 | `class_is` | 32 | 5.9s |  |
| 205 | `class_methods` | 5 | 5.8s |  |
| 206 | `class_object_properties` | 10 | 5.8s |  |
| 207 | `class_singleton` | 18 | 5.9s |  |
| 208 | `class_supercalls_errors` | 35 | 6.0s |  |
| 209 | `class_supercalls_mismatched` | 26 | 5.8s |  |
| 210 | `class_superclass_wrong_order` | 1 | 5.8s |  |
| 211 | `class_to_locale_string` | 2 | 2.3s |  |
| 212 | `class_to_string` | 2 | 6.3s |  |
| 213 | `class_value_of` | 2 | 6.4s |  |
| 214 | `click_block` | 5 | 21.9s |  |
| 215 | `click_invisible` | 3 | 6.8s |  |
| 216 | `closures` | 12 | 7.0s |  |
| 217 | `coerce_return_type` | 40 | 6.4s |  |
| 218 | `coerce_return_type_fail` | 2 | 6.2s |  |
| 219 | `coerce_return_void` | 3 | 6.3s |  |
| 220 | `coerce_string` | 86 | 6.3s |  |
| 221 | `coerce_string_precision` | 28 | 6.4s |  |
| 222 | `coerce_to_primitive_side_effects` | 29 | 6.6s |  |
| 223 | `collator_compare_basic` | 93 | 6.7s |  |
| 224 | `collator_flags` | 111 | 6.5s |  |
| 225 | `collator_locale_ids_windows` | 120 | 6.5s |  |
| 226 | `color_matrix_filter` | 19 | 6.6s |  |
| 227 | `construct_errors_swf10` | 8 | 6.3s |  |
| 228 | `construct_frame_list` | 22 | 20.8s |  |
| 229 | `construct_interface` | 3 | 6.5s |  |
| 230 | `constructor_call` | 3 | 6.6s |  |
| 231 | `constructors_vs_timeline` | 5 | 20.3s |  |
| 232 | `constructprop_dynamic_primitive` | 7 | 6.5s |  |
| 233 | `constructprop_method` | 2 | 6.2s |  |
| 234 | `constructsuper_null` | 2 | 6.4s |  |
| 235 | `content_element_basic` | 50 | 6.7s |  |
| 236 | `context3d_creation` | 9 | 6.3s |  |
| 237 | `control_flow_bool` | 4 | 6.2s |  |
| 238 | `control_flow_stricteq` | 8 | 5.9s |  |
| 239 | `convert_boolean` | 30 | 6.0s |  |
| 240 | `convert_integer` | 90 | 6.0s |  |
| 241 | `convert_number` | 56 | 6.0s |  |
| 242 | `convert_uinteger` | 90 | 6.0s |  |
| 243 | `convolution_filter` | 89 | 6.2s |  |
| 244 | `core_exceptions` | 47 | 6.9s |  |
| 245 | `cpool_index_invalid_bytecode_1` | 6 | 6.4s |  |
| 246 | `cpool_index_invalid_bytecode_2` | 3 | 2.4s |  |
| 247 | `cpool_index_invalid_bytecode_3` | 1 | 6.1s |  |
| 248 | `cross_api_version_call_newer` | 12 | 6.6s |  |
| 249 | `cross_api_version_call_older` | 12 | 6.5s |  |
| 250 | `cryptscore` | 11 | 6.1s |  |
| 251 | `currency_parse_result` | 7 | 6.3s |  |
| 252 | `date` | 30 | 6.8s |  |
| 253 | `date_parse` | 36 | 9.6s |  |
| 254 | `date_set_time_out_of_range` | 62 | 9.3s |  |
| 255 | `declocal` | 46 | 9.4s |  |
| 256 | `declocal_i` | 46 | 9.3s |  |
| 257 | `decode_uri` | 71 | 9.8s |  |
| 258 | `decrement` | 46 | 9.5s |  |
| 259 | `decrement_i` | 46 | 3.6s |  |
| 260 | `default_values` | 7 | 9.3s |  |
| 261 | `delayed_symbolclass` | 28 | 31.6s |  |
| 262 | `describe_type_basic` | 152 | 9.6s |  |
| 263 | `describe_type_json` | 301 | 9.6s |  |
| 264 | `describe_type_metadata` | 125 | 9.5s |  |
| 265 | `describe_type_native` | 23 | 9.4s |  |
| 266 | `dictionary_access` | 62 | 9.8s |  |
| 267 | `dictionary_access_no_pubns` | 2 | 9.2s |  |
| 268 | `dictionary_delete` | 101 | 9.9s |  |
| 269 | `dictionary_foreach` | 42 | 9.7s |  |
| 270 | `dictionary_hasownproperty` | 63 | 9.8s |  |
| 271 | `dictionary_in` | 62 | 9.7s |  |
| 272 | `dictionary_iter_modify` | 8 | 9.7s |  |
| 273 | `dictionary_namespaces` | 36 | 9.6s |  |
| 274 | `displacement_map_filter` | 61 | 9.8s |  |
| 275 | `displayobject_alpha` | 277 | 9.6s |  |
| 276 | `displayobject_blendmode` | 0 | 33.1s |  |
| 277 | `displayobject_colortransform_nested` | 0 | 32.1s |  |
| 278 | `displayobject_early_init` | 54 | 11.9s |  |
| 279 | `displayobject_filters` | 17 | 9.7s |  |
| 280 | `displayobject_from_enterframe` | 1 | 31.8s |  |
| 281 | `displayobject_getbounds_shape` | 0 | 31.9s |  |
| 282 | `displayobject_getrect` | 16 | 9.8s |  |
| 283 | `displayobject_height` | 6052 | 32.5s |  |
| 284 | `displayobject_hittestobject` | 32 | 9.6s |  |
| 285 | `displayobject_hittestpoint` | 49 | 10.1s |  |
| 286 | `displayobject_hittestpoint_boundary` | 65 | 33.8s |  |
| 287 | `displayobject_hittestpoint_root` | 13 | 10.0s |  |
| 288 | `displayobject_invalid_floats` | 60 | 9.9s |  |
| 289 | `displayobject_invalid_props` | 3 | 9.3s |  |
| 290 | `displayobject_mask` | 3 | 10.1s |  |
| 291 | `displayobject_mask_self_referential` | 0 | 9.4s |  |
| 292 | `displayobject_metaData` | 3 | 9.3s |  |
| 293 | `displayobject_name` | 22 | 9.7s |  |
| 294 | `displayobject_name_from_timeline` | 24 | 9.0s |  |
| 295 | `displayobject_opaque_background` | 6 | 29.0s |  |
| 296 | `displayobject_parent` | 12 | 9.0s |  |
| 297 | `displayobject_root` | 24 | 8.9s |  |
| 298 | `displayobject_rotation` | 1284 | 8.9s |  |
| 299 | `displayobject_scrollrect` | 33 | 9.9s |  |
| 300 | `displayobject_set_matrix_nested` | 0 | 28.9s |  |
| 301 | `displayobject_set_name_loaded` | 3 | 9.2s |  |
| 302 | `displayobject_subclass` | 2 | 8.9s |  |
| 303 | `displayobject_transform` | 89 | 8.9s |  |
| 304 | `displayobject_visible` | 23 | 8.9s |  |
| 305 | `displayobject_width` | 4852 | 29.4s |  |
| 306 | `displayobject_x` | 614 | 8.9s |  |
| 307 | `displayobject_y` | 617 | 8.9s |  |
| 308 | `displayobject_z` | 38 | 30.1s |  |
| 309 | `displayobjectcontainer_addchild` | 32 | 8.8s |  |
| 310 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 8.8s |  |
| 311 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 3.6s |  |
| 312 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 9.0s |  |
| 313 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 9.1s |  |
| 314 | `displayobjectcontainer_addchildat` | 42 | 8.9s |  |
| 315 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 9.0s |  |
| 316 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 9.0s |  |
| 317 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.9s |  |
| 318 | `displayobjectcontainer_contains` | 66 | 29.2s |  |
| 319 | `displayobjectcontainer_getchildat` | 4 | 8.9s |  |
| 320 | `displayobjectcontainer_getchildbyname` | 9 | 8.9s |  |
| 321 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 8.8s |  |
| 322 | `displayobjectcontainer_getchildindex` | 28 | 8.8s |  |
| 323 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 28.9s |  |
| 324 | `displayobjectcontainer_removechild` | 10 | 8.8s |  |
| 325 | `displayobjectcontainer_removechild_errors` | 4 | 8.8s |  |
| 326 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 8.9s |  |
| 327 | `displayobjectcontainer_removechildat` | 18 | 3.3s |  |
| 328 | `displayobjectcontainer_removechildren` | 51 | 9.1s |  |
| 329 | `displayobjectcontainer_setchildindex` | 42 | 8.7s |  |
| 330 | `displayobjectcontainer_stopallmovieclips` | 2 | 29.3s |  |
| 331 | `displayobjectcontainer_swapchildren` | 42 | 9.0s |  |
| 332 | `displayobjectcontainer_swapchildrenat` | 42 | 3.4s |  |
| 333 | `displayobjectcontainer_timelineinstance` | 48 | 29.1s |  |
| 334 | `divide` | 1058 | 20.0s |  |
| 335 | `doabc_and_symbolclass_script_init_goto` | 7 | 29.1s |  |
| 336 | `doabc_and_symbolclass_script_init_normal` | 6 | 8.8s |  |
| 337 | `doabc_is_eager` | 1 | 29.7s |  |
| 338 | `documentclass` | 9 | 9.1s |  |
| 339 | `domain_memory` | 133 | 8.7s |  |
| 340 | `drag_drop` | 10 | 9.2s |  |
| 341 | `drop_shadow_filter` | 172 | 9.4s |  |
| 342 | `duplicate_defs` | 1 | 8.7s |  |
| 343 | `eager_init` | 1 | 8.8s |  |
| 344 | `east_asian_justifier_clone` | 8 | 8.8s |  |
| 345 | `edit_text_linkage` | 7 | 9.0s |  |
| 346 | `edittext_align` | 60 | 9.5s |  |
| 347 | `edittext_always_show_selection` | 0 | 30.4s |  |
| 348 | `edittext_antialiastype` | 296 | 9.3s |  |
| 349 | `edittext_at_point_methods_basic` | 16 | 10.4s |  |
| 350 | `edittext_autosize` | 39 | 9.1s |  |
| 351 | `edittext_autosize_align` | 0 | 30.3s |  |
| 352 | `edittext_autosize_height_dynamic` | 60 | 30.2s |  |
| 353 | `edittext_autosize_height_input` | 60 | 8.9s |  |
| 354 | `edittext_autosize_lazy_bounds_events` | 65 | 9.1s |  |
| 355 | `edittext_autosize_lazy_bounds_interactions` | 19 | 8.9s |  |
| 356 | `edittext_autosize_lazy_bounds_props` | 490 | 10.8s |  |
| 357 | `edittext_autosize_lazy_bounds_visual` | 0 | 9.0s |  |
| 358 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 9.0s |  |
| 359 | `edittext_bottom_scroll_v_basic` | 210 | 8.9s |  |
| 360 | `edittext_bounds_scale` | 24 | 29.9s |  |
| 361 | `edittext_bullet` | 30 | 9.1s |  |
| 362 | `edittext_default_format` | 221 | 9.4s |  |
| 363 | `edittext_default_format_empty` | 136 | 9.2s |  |
| 364 | `edittext_empty_text_format` | 7 | 8.6s |  |
| 365 | `edittext_focus_selection` | 5 | 8.7s |  |
| 366 | `edittext_font_size` | 45 | 9.1s |  |
| 367 | `edittext_format_empty_font` | 8 | 8.8s |  |
| 368 | `edittext_get_char_index_at_point` | 4 | 32.2s |  |
| 369 | `edittext_get_line_index_at_point` | 2 | 30.0s |  |
| 370 | `edittext_get_line_index_of_char` | 76 | 9.1s |  |
| 371 | `edittext_getcharboundaries` | 172 | 9.0s |  |
| 372 | `edittext_getcharboundaries_missing_glyphs` | 63 | 8.8s |  |
| 373 | `edittext_getcharboundaries_scroll` | 85 | 8.7s |  |
| 374 | `edittext_getlinemetrics` | 146 | 9.3s |  |
| 375 | `edittext_html` | 3101 | 9.4s |  |
| 376 | `edittext_html_condensewhite` | 487 | 8.9s |  |
| 377 | `edittext_html_entity` | 4 | 8.9s |  |
| 378 | `edittext_html_font_size_swf12` | 267 | 5.7s |  |
| 379 | `edittext_html_font_size_swf13` | 273 | 5.4s |  |
| 380 | `edittext_html_roundtrip` | 17 | 5.9s |  |
| 381 | `edittext_ime_focus_lost` | 9 | 17.8s |  |
| 382 | `edittext_input_control` | 12 | 5.8s |  |
| 383 | `edittext_leading` | 9 | 5.9s |  |
| 384 | `edittext_letter_spacing` | 15 | 5.8s |  |
| 385 | `edittext_line_methods` | 294 | 6.5s |  |
| 386 | `edittext_line_metrics` | 11 | 18.7s |  |
| 387 | `edittext_margins` | 25 | 5.8s |  |
| 388 | `edittext_max_scroll_h_basic` | 475 | 5.8s |  |
| 389 | `edittext_max_scroll_v_basic` | 1000 | 5.6s |  |
| 390 | `edittext_mouse_selection` | 363 | 18.6s |  |
| 391 | `edittext_mousedown` | 3 | 5.8s |  |
| 392 | `edittext_mouseenabled` | 26 | 5.5s |  |
| 393 | `edittext_newline_character` | 22 | 5.5s |  |
| 394 | `edittext_newline_stripping` | 64 | 10.1s |  |
| 395 | `edittext_newlines` | 30 | 5.7s |  |
| 396 | `edittext_paragraph_methods` | 257 | 5.6s |  |
| 397 | `edittext_paste_events` | 8 | 5.6s |  |
| 398 | `edittext_paste_maxchars` | 4 | 5.5s |  |
| 399 | `edittext_paste_restrict` | 16 | 5.5s |  |
| 400 | `edittext_restrict` | 191 | 5.6s |  |
| 401 | `edittext_restrict_events` | 22 | 2.1s |  |
| 402 | `edittext_scroll_event` | 37 | 5.7s |  |
| 403 | `edittext_scrollh` | 10 | 5.6s |  |
| 404 | `edittext_selected_text` | 9 | 2.1s |  |
| 405 | `edittext_set_html_same` | 17 | 5.5s |  |
| 406 | `edittext_set_text_vs_html` | 9 | 5.5s |  |
| 407 | `edittext_stylesheet` | 536 | 5.8s |  |
| 408 | `edittext_stylesheet_custom_tag` | 76 | 5.7s |  |
| 409 | `edittext_stylesheet_display` | 272 | 5.6s |  |
| 410 | `edittext_tag_indent` | 49 | 17.6s |  |
| 411 | `edittext_underline` | 40 | 5.7s |  |
| 412 | `edittext_width_height` | 103 | 5.8s |  |
| 413 | `edittext_wordwrap_word` | 150 | 5.7s |  |
| 414 | `edittext_wrap_breaks` | 2375 | 6.0s |  |
| 415 | `element_format_clone` | 44 | 5.7s |  |
| 416 | `element_format_constructor_order` | 64 | 2.2s |  |
| 417 | `element_format_properties` | 235 | 6.5s |  |
| 418 | `empty_bounds` | 1 | 5.5s |  |
| 419 | `encode_uri_surrogate_pair_invalid` | 8 | 5.6s |  |
| 420 | `encode_uri_surrogate_pair_swf11` | 15 | 5.7s |  |
| 421 | `equals` | 512 | 7.8s |  |
| 422 | `error_geterrormessage` | 779 | 2.2s |  |
| 423 | `error_prototype` | 15 | 5.6s |  |
| 424 | `error_stack_trace` | 45 | 5.6s |  |
| 425 | `error_stack_trace_debug_swf17` | 0 | 17.6s |  |
| 426 | `error_stack_trace_debug_swf18` | 0 | 5.4s |  |
| 427 | `error_stack_trace_edge_cases` | 6 | 5.7s |  |
| 428 | `error_stack_trace_release_swf17` | 0 | 2.1s |  |
| 429 | `error_stack_trace_release_swf18` | 0 | 5.5s |  |
| 430 | `error_throwerror` | 103 | 5.7s |  |
| 431 | `error_tostring` | 29 | 5.6s |  |
| 432 | `error_tostring_more` | 86 | 5.6s |  |
| 433 | `es3_inheritance` | 31 | 5.7s |  |
| 434 | `es4_inheritance` | 30 | 5.5s |  |
| 435 | `es4_interfaces` | 30 | 5.6s |  |
| 436 | `es4_method_binding` | 8 | 5.6s |  |
| 437 | `es4_oop_prototypes` | 14 | 5.8s |  |
| 438 | `es4_protected_inheritance` | 6 | 5.7s |  |
| 439 | `escape` | 71 | 5.6s |  |
| 440 | `escape_multi_byte` | 45 | 5.7s |  |
| 441 | `event_bubbles` | 2 | 5.6s |  |
| 442 | `event_cancelable` | 2 | 5.5s |  |
| 443 | `event_clone` | 20 | 5.7s |  |
| 444 | `event_clone_error_redispatch` | 3 | 2.2s |  |
| 445 | `event_clone_on_redispatch` | 10 | 5.6s |  |
| 446 | `event_formattostring` | 31 | 5.7s |  |
| 447 | `event_isdefaultprevented` | 12 | 5.6s |  |
| 448 | `event_target_getter` | 5 | 2.2s |  |
| 449 | `event_target_set` | 9 | 5.6s |  |
| 450 | `event_type` | 1 | 5.6s |  |
| 451 | `event_valueof_tostring` | 18 | 5.6s |  |
| 452 | `eventdispatcher_dispatchevent` | 12 | 2.1s |  |
| 453 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.5s |  |
| 454 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.6s |  |
| 455 | `eventdispatcher_dispatchevent_indirect` | 9 | 2.2s |  |
| 456 | `eventdispatcher_dispatchevent_this` | 5 | 5.5s |  |
| 457 | `eventdispatcher_haseventlistener` | 25 | 2.2s |  |
| 458 | `eventdispatcher_interface_invoke` | 1 | 5.6s |  |
| 459 | `eventdispatcher_tostring` | 10 | 5.6s |  |
| 460 | `eventdispatcher_willtrigger` | 25 | 5.5s |  |
| 461 | `external_interface` | 105 | 9.6s |  |
| 462 | `falsiness` | 30 | 9.4s |  |
| 463 | `fast_index_access` | 12 | 9.6s |  |
| 464 | `filefilter_properties` | 4 | 9.4s |  |
| 465 | `filereference_browse_cancel` | 3 | 9.5s |  |
| 466 | `filereference_browse_select` | 9 | 9.5s |  |
| 467 | `filereference_load` | 31 | 9.6s |  |
| 468 | `filereference_save` | 16 | 9.7s |  |
| 469 | `filereference_save_and_browse` | 42 | 9.7s |  |
| 470 | `filereference_save_and_load` | 22 | 3.8s |  |
| 471 | `filereference_uninitialized` | 8 | 9.6s |  |
| 472 | `filereferencelist_browse_cancel` | 6 | 9.6s |  |
| 473 | `filereferencelist_browse_select` | 7 | 9.5s |  |
| 474 | `filter_rewind` | 8 | 31.6s |  |
| 475 | `filters_array_holes` | 25 | 9.7s |  |
| 476 | `finddef` | 3 | 9.6s |  |
| 477 | `findprop_global_prototype` | 6 | 9.7s |  |
| 478 | `flash_media_video_constructor` | 156 | 10.6s |  |
| 479 | `flash_media_video_rotation_probe` | 27 | 9.7s |  |
| 480 | `flash_media_video_setter` | 40 | 10.2s |  |
| 481 | `flash_trace` | 17 | 9.7s |  |
| 482 | `flash_ui_mouse_cursor` | 35 | 10.2s |  |
| 483 | `flash_xml` | 29 | 9.9s |  |
| 484 | `flash_xml_cloneNode` | 22 | 9.7s |  |
| 485 | `flash_xml_namespace` | 109 | 9.7s |  |
| 486 | `flash_xml_removeNode` | 60 | 9.7s |  |
| 487 | `focus_events_code` | 161 | 32.1s |  |
| 488 | `focus_events_key_basic` | 132 | 32.2s |  |
| 489 | `focus_events_key_navigation` | 53 | 31.9s |  |
| 490 | `focus_events_key_same_object` | 26 | 9.8s |  |
| 491 | `focus_events_mixed_key_mouse` | 100 | 31.9s |  |
| 492 | `focus_events_mouse_basic` | 260 | 32.1s |  |
| 493 | `focus_events_mouse_focusable` | 112 | 32.0s |  |
| 494 | `focus_events_mouse_same_object` | 40 | 9.5s |  |
| 495 | `focus_remove` | 20 | 30.4s |  |
| 496 | `focus_root_movie` | 4 | 30.7s |  |
| 497 | `focus_stage` | 1 | 9.3s |  |
| 498 | `focusrect` | 18 | 10.3s |  |
| 499 | `focusrect_focuslost` | 9 | 9.4s |  |
| 500 | `focusrect_property` | 110 | 3.4s |  |
| 501 | `font_description_clone` | 14 | 9.3s |  |
| 502 | `font_embedded` | 24 | 10.0s |  |
| 503 | `font_enumeratefonts` | 41 | 7.9s |  |
| 504 | `font_enumeratefonts_filter` | 4 | 8.0s |  |
| 505 | `font_enumeratefonts_order` | 9 | 8.6s |  |
| 506 | `font_hasglyphs` | 40 | 7.8s |  |
| 507 | `font_registerfont` | 129 | 8.4s |  |
| 508 | `framelabel_constr` | 5 | 7.5s |  |
| 509 | `function_call` | 12 | 2.9s |  |
| 510 | `function_call_arguments` | 46 | 7.4s |  |
| 511 | `function_call_arguments_enumerate` | 5 | 7.3s |  |
| 512 | `function_call_coercion` | 108 | 7.7s |  |
| 513 | `function_call_default` | 6 | 7.2s |  |
| 514 | `function_call_rest` | 22 | 7.3s |  |
| 515 | `function_call_types` | 3 | 7.3s |  |
| 516 | `function_call_via_apply` | 11 | 7.3s |  |
| 517 | `function_call_via_call` | 3 | 7.3s |  |
| 518 | `function_display_anonymous` | 7 | 2.9s |  |
| 519 | `function_length` | 6 | 7.3s |  |
| 520 | `function_object` | 2 | 7.2s |  |
| 521 | `function_proto` | 5 | 7.3s |  |
| 522 | `function_proto_created` | 61 | 7.4s |  |
| 523 | `function_to_locale_string` | 4 | 7.3s |  |
| 524 | `function_to_string` | 4 | 7.1s |  |
| 525 | `function_type` | 6 | 3.2s |  |
| 526 | `function_unbound_this` | 51 | 7.6s |  |
| 527 | `function_value_of` | 4 | 7.3s |  |
| 528 | `game_input` | 4 | 7.3s |  |
| 529 | `generate_random_bytes` | 3 | 7.3s |  |
| 530 | `geom_transform` | 74 | 24.6s |  |
| 531 | `get_definition_by_name` | 11 | 7.3s |  |
| 532 | `get_qualified_class_name` | 20 | 2.8s |  |
| 533 | `get_qualified_super_class_name` | 18 | 7.4s |  |
| 534 | `get_slot_edge_cases` | 1 | 7.2s |  |
| 535 | `get_timer` | 2 | 2.8s |  |
| 536 | `getglobalslot` | 1 | 7.2s |  |
| 537 | `getouterscope` | 8 | 7.2s |  |
| 538 | `getouterscope_two_classobjects` | 13 | 7.3s |  |
| 539 | `getter_different_namespace_setter` | 2 | 7.5s |  |
| 540 | `glow_filter` | 127 | 7.7s |  |
| 541 | `goto_button_nested_framescript` | 28 | 24.1s |  |
| 542 | `goto_framescript_queued/swf10` | 59 | 24.1s |  |
| 543 | `goto_framescript_queued/swf9` | 52 | 1.2s |  |
| 544 | `goto_framescript_queued_same_frame` | 4 | 9.6s |  |
| 545 | `goto_in_constructframe` | 12 | 10.0s |  |
| 546 | `goto_in_scene_last_frame` | 2 | 30.4s |  |
| 547 | `goto_methods` | 56 | 9.9s |  |
| 548 | `goto_methods_swfver10` | 8 | 9.5s |  |
| 549 | `goto_nested_construct_sibling` | 18 | 10.0s |  |
| 550 | `goto_nested_framescript` | 9 | 9.7s |  |
| 551 | `goto_on_orphan` | 15 | 30.6s |  |
| 552 | `goto_queued_invalid/swf10` | 34 | 30.6s |  |
| 553 | `goto_queued_invalid/swf11` | 43 | 1.5s |  |
| 554 | `goto_queued_invalid/swf9` | 32 | 1.5s |  |
| 555 | `gradient_bevel_filter` | 206 | 3.9s |  |
| 556 | `gradient_glow_filter` | 206 | 9.4s |  |
| 557 | `graphic_linkage` | 9 | 9.7s |  |
| 558 | `graphics_bad_direct_commands` | 5 | 10.4s |  |
| 559 | `graphics_bitmap_fill` | 0 | 12.3s |  |
| 560 | `graphics_bitmaps` | 0 | 10.1s |  |
| 561 | `graphics_direct_commands` | 0 | 10.0s |  |
| 562 | `graphics_draw_triangles` | 98 | 31.5s |  |
| 563 | `graphics_gradients` | 0 | 9.8s |  |
| 564 | `graphics_gradients_nulls` | 0 | 9.7s |  |
| 565 | `graphics_path` | 56 | 9.5s |  |
| 566 | `graphics_round_rects` | 0 | 9.5s |  |
| 567 | `graphics_simple_shapes` | 0 | 9.7s |  |
| 568 | `greaterequals` | 512 | 13.7s |  |
| 569 | `greaterthan` | 512 | 13.5s |  |
| 570 | `has_own_property` | 102 | 10.1s |  |
| 571 | `hasownproperty_namespaces` | 2 | 9.4s |  |
| 572 | `hello_world` | 1 | 9.5s |  |
| 573 | `hittest_morph` | 30 | 9.6s |  |
| 574 | `id3_info` | 8 | 24.4s |  |
| 575 | `if_eq` | 10 | 9.4s |  |
| 576 | `if_gt` | 1 | 9.5s |  |
| 577 | `if_gte` | 10 | 3.7s |  |
| 578 | `if_lt` | 1 | 1.4s |  |
| 579 | `if_lte` | 10 | 9.4s |  |
| 580 | `if_ne` | 7 | 3.7s |  |
| 581 | `if_stricteq` | 6 | 9.6s |  |
| 582 | `if_strictne` | 11 | 9.3s |  |
| 583 | `ime_linux_dead_keys` | 10 | 9.6s |  |
| 584 | `in` | 102 | 9.8s |  |
| 585 | `inclocal` | 46 | 9.2s |  |
| 586 | `inclocal_i` | 46 | 9.1s |  |
| 587 | `increment` | 46 | 9.2s |  |
| 588 | `increment_i` | 46 | 3.5s |  |
| 589 | `indexing_delete` | 75 | 9.1s |  |
| 590 | `indexof_xml` | 10 | 9.2s |  |
| 591 | `init_callee_cached` | 24 | 9.2s |  |
| 592 | `instanceof` | 58 | 9.6s |  |
| 593 | `instantiate_root_character` | 4 | 9.5s |  |
| 594 | `instantiation_on_enter_frame` | 7 | 30.1s |  |
| 595 | `instantiation_on_enterframe_gotoandstop` | 8 | 9.2s |  |
| 596 | `int_constr` | 92 | 9.3s |  |
| 597 | `int_edge_cases` | 19 | 9.3s |  |
| 598 | `int_instanceof` | 3 | 9.1s |  |
| 599 | `int_tofixed` | 1215 | 9.1s |  |
| 600 | `int_toprecision` | 1125 | 9.4s |  |
| 601 | `int_tostring` | 3375 | 9.5s |  |
| 602 | `interactiveobject_enabled` | 25 | 9.1s |  |
| 603 | `interface_namespaces` | 78 | 9.4s |  |
| 604 | `invalid_utf8` | 12 | 9.4s |  |
| 605 | `is_finite` | 46 | 9.3s |  |
| 606 | `is_nan` | 46 | 9.0s |  |
| 607 | `is_prototype_of` | 12 | 9.2s |  |
| 608 | `issue_10221` | 2 | 9.1s |  |
| 609 | `issue_13780` | 12 | 9.1s |  |
| 610 | `issue_14901` | 1 | 9.1s |  |
| 611 | `issue_17675_edittext_paste_maxchars` | 1 | 9.2s |  |
| 612 | `issue_5292` | 5 | 3.5s |  |
| 613 | `issue_8630` | 2 | 9.2s |  |
| 614 | `issue_8630_placeremoveplace` | 15 | 9.3s |  |
| 615 | `issue_8630_placeremoveplace_scriptremove` | 16 | 9.2s |  |
| 616 | `issue_8630_scriptremove` | 11 | 9.2s |  |
| 617 | `istype` | 24 | 3.6s |  |
| 618 | `istypelate` | 58 | 9.7s |  |
| 619 | `istypelate_coerce` | 198 | 10.6s |  |
| 620 | `jpeg_loader_context` | 6 | 9.1s |  |
| 621 | `json_errors` | 9 | 30.4s |  |
| 622 | `json_parse` | 21 | 9.3s |  |
| 623 | `json_parse_errors` | 84 | 9.2s |  |
| 624 | `json_stringify` | 12 | 9.0s |  |
| 625 | `json_stringify_function` | 12 | 8.6s |  |
| 626 | `json_stringify_order` | 1 | 8.7s |  |
| 627 | `json_version_gated` | 1 | 8.7s |  |
| 628 | `key_input_80percent` | 1812 | 9.0s |  |
| 629 | `key_input_location` | 126 | 8.7s |  |
| 630 | `key_input_numpad` | 384 | 3.3s |  |
| 631 | `large_preload_from_bytes` | 51 | 12.6s |  |
| 632 | `large_preload_from_url` | 27 | 11.1s |  |
| 633 | `large_preload_image_from_bytes` | 25 | 11.2s |  |
| 634 | `lazyinit` | 17 | 8.7s |  |
| 635 | `lessequals` | 512 | 12.8s |  |
| 636 | `lessthan` | 512 | 12.9s |  |
| 637 | `loader_bitmap_transparency` | 14 | 8.9s |  |
| 638 | `loader_bytes_unknown_content` | 14 | 8.9s |  |
| 639 | `loader_child_getdefinition` | 5 | 9.1s |  |
| 640 | `loader_duplicate_class` | 48 | 10.8s |  |
| 641 | `loader_duplicate_coerce` | 3 | 9.0s |  |
| 642 | `loader_duplicate_coerce_new_domain` | 4 | 8.9s |  |
| 643 | `loader_error_in_root_ctor` | 4 | 9.0s |  |
| 644 | `loader_events` | 92 | 9.8s |  |
| 645 | `loader_image` | 8 | 9.3s |  |
| 646 | `loader_jpegxr` | 2 | 28.8s |  |
| 647 | `loader_jpegxr_alpha` | 1 | 28.5s |  |
| 648 | `loader_loadbytes_events` | 30 | 9.5s |  |
| 649 | `loader_loadbytes_invalid_png` | 4 | 8.9s |  |
| 650 | `loader_loadbytes_url` | 12 | 9.0s |  |
| 651 | `loader_loaderurl` | 6 | 9.3s |  |
| 652 | `loader_method` | 85 | 8.8s |  |
| 653 | `loader_noninteractive_try_click_root` | 5 | 28.8s |  |
| 654 | `loader_reuse` | 38 | 9.0s |  |
| 655 | `loader_try_click_root` | 16 | 9.1s |  |
| 656 | `loader_unknown_content` | 24 | 9.0s |  |
| 657 | `loader_visibility_interactive` | 1 | 8.8s |  |
| 658 | `loaderinfo_events` | 7 | 8.7s |  |
| 659 | `loaderinfo_loadurl` | 12 | 8.7s |  |
| 660 | `loaderinfo_more` | 6 | 8.9s |  |
| 661 | `loaderinfo_properties` | 18 | 28.4s |  |
| 662 | `loaderinfo_properties_not_loaded` | 23 | 8.9s |  |
| 663 | `loaderinfo_quine` | 1005 | 7.9s |  |
| 664 | `loaderinfo_root` | 10 | 7.2s |  |
| 665 | `loaderinfo_root_allows` | 2 | 7.0s |  |
| 666 | `localconnection` | 890 | 9.7s |  |
| 667 | `localconnection_send` | 4 | 7.1s |  |
| 668 | `lshift` | 1058 | 14.5s |  |
| 669 | `mask_reapply` | 1 | 23.9s |  |
| 670 | `math` | 497 | 7.4s |  |
| 671 | `matrix` | 338 | 15.2s |  |
| 672 | `matrix3d` | 57 | 7.9s |  |
| 673 | `matrix3d_append` | 16 | 7.6s |  |
| 674 | `matrix3d_append_prepend_scale` | 86 | 7.2s |  |
| 675 | `matrix3d_append_prepend_translation` | 42 | 7.1s |  |
| 676 | `matrix3d_append_rotation` | 23 | 7.2s |  |
| 677 | `matrix3d_compose` | 34 | 7.3s |  |
| 678 | `matrix3d_constructor_clone` | 15 | 7.2s |  |
| 679 | `matrix3d_copy_column` | 83 | 7.3s |  |
| 680 | `matrix3d_copy_from` | 19 | 7.5s |  |
| 681 | `matrix3d_copy_raw_data_from` | 55 | 2.7s |  |
| 682 | `matrix3d_copy_raw_data_to` | 38 | 7.7s |  |
| 683 | `matrix3d_copy_row` | 83 | 7.0s |  |
| 684 | `matrix3d_copy_to_matrix3d` | 19 | 7.1s |  |
| 685 | `matrix3d_determinant` | 182 | 7.2s |  |
| 686 | `matrix3d_interpolate` | 21 | 7.3s |  |
| 687 | `matrix3d_invert` | 18 | 7.1s |  |
| 688 | `matrix3d_position` | 19 | 7.2s |  |
| 689 | `matrix3d_precision` | 28 | 7.2s |  |
| 690 | `matrix3d_prepend` | 16 | 6.9s |  |
| 691 | `matrix3d_raw_data` | 33 | 7.2s |  |
| 692 | `matrix3d_transform_vector` | 52 | 7.5s |  |
| 693 | `matrix3d_transpose` | 5 | 7.1s |  |
| 694 | `method_association` | 5 | 2.5s |  |
| 695 | `method_without_body` | 3 | 23.9s |  |
| 696 | `missing_external_interface` | 10 | 7.2s |  |
| 697 | `modulo` | 1058 | 14.4s |  |
| 698 | `morph_shape` | 2 | 19.8s |  |
| 699 | `mouse_children` | 192 | 25.2s |  |
| 700 | `mouse_click_events` | 90 | 24.7s |  |
| 701 | `mouse_double_click_events` | 188 | 7.2s |  |
| 702 | `mouse_empty_parent` | 4 | 7.6s |  |
| 703 | `mouse_over_while_dragging` | 3 | 7.2s |  |
| 704 | `mouse_pick_avm1_root` | 2 | 24.4s |  |
| 705 | `mouse_pick_button_mode` | 2 | 7.0s |  |
| 706 | `mouse_pick_dobj_mask` | 4 | 6.8s |  |
| 707 | `mouse_pick_loader_avm1` | 42 | 7.0s |  |
| 708 | `mouse_pick_masking` | 7 | 21.5s |  |
| 709 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 21.9s |  |
| 710 | `mouse_pick_non_interactive_dobj_mask` | 3 | 6.8s |  |
| 711 | `mouse_pick_scroll_rect` | 27 | 22.4s |  |
| 712 | `mouse_pick_scroll_rect_button` | 5 | 7.0s |  |
| 713 | `mouse_pick_scroll_rect_loader` | 5 | 7.2s |  |
| 714 | `mouse_pick_text` | 8 | 7.3s |  |
| 715 | `mouse_sibling` | 8 | 7.1s |  |
| 716 | `mouse_wheel_events` | 36 | 22.9s |  |
| 717 | `mouseevent_constr` | 66 | 6.7s |  |
| 718 | `mouseevent_stagexy` | 35 | 6.6s |  |
| 719 | `mouseevent_valueof_tostring` | 28 | 6.9s |  |
| 720 | `movieclip_addframescript` | 3 | 22.8s |  |
| 721 | `movieclip_addframescript_error` | 9 | 7.1s |  |
| 722 | `movieclip_child_property` | 16 | 7.2s |  |
| 723 | `movieclip_constr` | 21 | 7.1s |  |
| 724 | `movieclip_currentlabels` | 17 | 23.2s |  |
| 725 | `movieclip_currentlabels_dupes1` | 46 | 23.5s |  |
| 726 | `movieclip_currentlabels_dupes2` | 30 | 7.3s |  |
| 727 | `movieclip_currentlabels_dupes3` | 67 | 7.1s |  |
| 728 | `movieclip_currentscene` | 12 | 7.3s |  |
| 729 | `movieclip_dispatchevent` | 430 | 7.5s |  |
| 730 | `movieclip_dispatchevent_cancel` | 102 | 7.6s |  |
| 731 | `movieclip_dispatchevent_handlerorder` | 251 | 2.9s |  |
| 732 | `movieclip_dispatchevent_selfadd` | 80 | 6.9s |  |
| 733 | `movieclip_dispatchevent_target` | 899 | 7.1s |  |
| 734 | `movieclip_displayevents` | 96 | 22.8s |  |
| 735 | `movieclip_displayevents_clickgoto` | 676 | 7.6s |  |
| 736 | `movieclip_displayevents_clickgoto2` | 2001 | 3.3s |  |
| 737 | `movieclip_displayevents_clickplay` | 575 | 7.3s |  |
| 738 | `movieclip_displayevents_clicksymbol` | 562 | 7.2s |  |
| 739 | `movieclip_displayevents_constructframegoto` | 140 | 7.5s |  |
| 740 | `movieclip_displayevents_constructframeplay` | 50 | 7.0s |  |
| 741 | `movieclip_displayevents_constructframesymbol` | 144 | 6.9s |  |
| 742 | `movieclip_displayevents_dblhandler` | 21 | 6.9s |  |
| 743 | `movieclip_displayevents_enterframegoto` | 149 | 7.1s |  |
| 744 | `movieclip_displayevents_enterframeplay` | 48 | 7.2s |  |
| 745 | `movieclip_displayevents_enterframesymbol` | 149 | 23.4s |  |
| 746 | `movieclip_displayevents_exitframegoto` | 106 | 7.3s |  |
| 747 | `movieclip_displayevents_exitframeplay` | 44 | 7.1s |  |
| 748 | `movieclip_displayevents_exitframesymbol` | 135 | 22.1s |  |
| 749 | `movieclip_displayevents_looping` | 63 | 21.8s |  |
| 750 | `movieclip_displayevents_stopped` | 113 | 21.8s |  |
| 751 | `movieclip_displayevents_swap` | 96 | 6.9s |  |
| 752 | `movieclip_displayevents_timeline` | 128 | 22.1s |  |
| 753 | `movieclip_drawrect` | 54 | 7.0s |  |
| 754 | `movieclip_frameconstruct_skipped` | 9 | 7.0s |  |
| 755 | `movieclip_goto_during_frame_script` | 15 | 7.2s |  |
| 756 | `movieclip_goto_overwrite` | 14 | 21.9s |  |
| 757 | `movieclip_goto_scene_last_frame_int` | 1 | 21.8s |  |
| 758 | `movieclip_goto_scene_last_frame_label` | 1 | 6.8s |  |
| 759 | `movieclip_gotoandplay` | 15 | 22.5s |  |
| 760 | `movieclip_gotoandstop` | 13 | 6.8s |  |
| 761 | `movieclip_gotoandstop_children` | 4 | 6.8s |  |
| 762 | `movieclip_gotoandstop_framescripts1` | 4 | 6.8s |  |
| 763 | `movieclip_gotoandstop_framescripts2` | 4 | 2.7s |  |
| 764 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.2s |  |
| 765 | `movieclip_gotoandstop_queueing` | 12 | 6.8s |  |
| 766 | `movieclip_hittest` | 67 | 7.0s |  |
| 767 | `movieclip_next_frame` | 2 | 2.8s |  |
| 768 | `movieclip_next_scene` | 6 | 7.0s |  |
| 769 | `movieclip_play` | 3 | 6.5s |  |
| 770 | `movieclip_prev_frame` | 3 | 6.8s |  |
| 771 | `movieclip_prev_scene` | 7 | 6.8s |  |
| 772 | `movieclip_properties` | 79 | 7.0s |  |
| 773 | `movieclip_queued_noop_goto_swf10` | 9 | 6.8s |  |
| 774 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 775 | `movieclip_scenes` | 11 | 6.6s |  |
| 776 | `movieclip_soundtransform` | 831 | 22.4s |  |
| 777 | `movieclip_stop` | 1 | 6.5s |  |
| 778 | `movieclip_super_is_symbol` | 20 | 6.7s |  |
| 779 | `movieclip_symbol_constr` | 8 | 6.8s |  |
| 780 | `movieclip_text_mousedown` | 1 | 6.6s |  |
| 781 | `movieclip_willtrigger` | 5 | 6.9s |  |
| 782 | `multiply` | 1058 | 14.0s |  |
| 783 | `namespace_constr` | 253 | 7.2s |  |
| 784 | `namespace_constr_args` | 1 | 6.9s |  |
| 785 | `namespace_enumeration_order` | 7 | 6.8s |  |
| 786 | `nan_scale` | 9 | 6.7s |  |
| 787 | `native_menu_basic` | 19 | 8.5s |  |
| 788 | `navigateToURL_target_normalize` | 107 | 23.6s |  |
| 789 | `negate` | 30 | 6.8s |  |
| 790 | `negative_volume_panned` | 0 | 6.9s |  |
| 791 | `nested_iteration` | 11 | 8.0s |  |
| 792 | `net_getClassByAlias` | 3 | 7.2s |  |
| 793 | `net_navigateToURL` | 57 | 25.8s |  |
| 794 | `net_stream_play_options` | 6 | 7.4s |  |
| 795 | `netconnection_close` | 55 | 7.3s |  |
| 796 | `netconnection_properties` | 78 | 7.3s |  |
| 797 | `netconnection_send_remote` | 50 | 24.5s |  |
| 798 | `netconnection_serialize_arrays` | 6 | 7.5s |  |
| 799 | `netfilterevent` | 10 | 7.4s |  |
| 800 | `netstream_client` | 10 | 8.1s |  |
| 801 | `netstream_connect` | 7 | 7.4s |  |
| 802 | `netstream_flv_date` | 4 | 7.5s |  |
| 803 | `newactivation_in_script_init` | 3 | 7.1s |  |
| 804 | `newclass_mismatched` | 4 | 7.1s |  |
| 805 | `newclass_twice` | 3 | 7.1s |  |
| 806 | `nonconflicting_declarations` | 0 | 7.2s |  |
| 807 | `null_void_types` | 8 | 7.4s |  |
| 808 | `number_autoconv` | 21 | 7.2s |  |
| 809 | `number_autoconv_amf` | 132 | 7.3s |  |
| 810 | `number_autoconv_array_sort_32bit` | 1 | 7.1s |  |
| 811 | `number_constr` | 58 | 7.4s |  |
| 812 | `number_convert_edge_cases` | 180 | 23.8s |  |
| 813 | `number_toexponential` | 378 | 2.9s |  |
| 814 | `number_toexponential2` | 35 | 7.4s |  |
| 815 | `number_tofixed` | 378 | 7.2s |  |
| 816 | `number_toprecision` | 350 | 7.3s |  |
| 817 | `obfuscated_class_names` | 3 | 7.2s |  |
| 818 | `object_enumeration` | 10 | 7.1s |  |
| 819 | `object_prototype` | 4 | 7.2s |  |
| 820 | `object_to_locale_string` | 2 | 7.1s |  |
| 821 | `object_to_string` | 2 | 7.1s |  |
| 822 | `object_value_of` | 2 | 2.6s |  |
| 823 | `op_coerce` | 54 | 7.1s |  |
| 824 | `op_coerce_x` | 54 | 7.3s |  |
| 825 | `op_escxattr` | 2 | 7.4s |  |
| 826 | `op_escxelem` | 2 | 2.8s |  |
| 827 | `op_lookupswitch` | 4 | 7.2s |  |
| 828 | `optimize_coerce` | 1 | 9.8s |  |
| 829 | `orphan_movie_complex` | 80 | 9.8s |  |
| 830 | `orphan_movie_reorder` | 111 | 31.0s |  |
| 831 | `orphan_removeobject` | 636 | 31.4s |  |
| 832 | `package_namespace` | 7 | 9.2s |  |
| 833 | `param_default_value_has_zero_cpool_index` | 1 | 9.0s |  |
| 834 | `parent_early_access_child` | 16 | 9.5s |  |
| 835 | `parse_float` | 81 | 9.4s |  |
| 836 | `parse_float_swf10` | 81 | 9.1s |  |
| 837 | `parse_int` | 135 | 9.8s |  |
| 838 | `perspective_projection` | 1443 | 31.0s |  |
| 839 | `perspective_projection_basic` | 40 | 9.3s |  |
| 840 | `pixelbender_ceil` | 77 | 9.6s |  |
| 841 | `pixelbender_conditional` | 138 | 9.8s |  |
| 842 | `pixelbender_conversions` | 270 | 9.7s |  |
| 843 | `pixelbender_dithering` | 8 | 37.1s |  |
| 844 | `pixelbender_div` | 36 | 9.5s |  |
| 845 | `pixelbender_effect_BlurredFocus` | 0 | 39.8s |  |
| 846 | `pixelbender_effect_glassDisplace` | 0 | 16.1s |  |
| 847 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 35.4s |  |
| 848 | `pixelbender_effect_smudge` | 0 | 13.3s |  |
| 849 | `pixelbender_effect_tintype` | 0 | 12.4s |  |
| 850 | `pixelbender_effect_twirl` | 0 | 14.1s |  |
| 851 | `pixelbender_eof` | 7 | 9.3s |  |
| 852 | `pixelbender_images` | 0 | 12.1s |  |
| 853 | `pixelbender_input` | 103 | 31.4s |  |
| 854 | `pixelbender_logicalnot` | 20 | 9.3s |  |
| 855 | `pixelbender_malformed_data` | 190 | 32.0s |  |
| 856 | `pixelbender_multiple_out_params` | 1 | 9.3s |  |
| 857 | `pixelbender_no_out_param` | 6 | 9.3s |  |
| 858 | `pixelbender_outputs` | 13 | 9.5s |  |
| 859 | `pixelbender_padding_bytes` | 22 | 9.4s |  |
| 860 | `pixelbender_param_qualifier` | 512 | 9.5s |  |
| 861 | `pixelbender_parameters` | 1563 | 9.9s |  |
| 862 | `pixelbender_parameters_bool` | 240 | 9.7s |  |
| 863 | `pixelbender_parameters_int_vs_bool` | 54 | 9.4s |  |
| 864 | `pixelbender_parse_errors` | 6 | 9.3s |  |
| 865 | `pixelbender_rsqrt` | 24 | 9.4s |  |
| 866 | `pixelbender_select_kinds` | 8 | 9.7s |  |
| 867 | `pixelbender_shaderdata` | 49 | 9.4s |  |
| 868 | `pixelbender_shaderdata_setter` | 99 | 9.8s |  |
| 869 | `pixelbender_sign` | 60 | 9.6s |  |
| 870 | `pixelbender_vector_output` | 11 | 9.6s |  |
| 871 | `place_and_lookup/swf10` | 33 | 8.2s |  |
| 872 | `place_and_lookup/swf9` | 33 | 1.2s |  |
| 873 | `place_multiple` | 17 | 7.7s |  |
| 874 | `place_object_replace` | 9 | 24.9s |  |
| 875 | `place_object_replace_2` | 24 | 7.7s |  |
| 876 | `place_object_same_depth_frame` | 1 | 7.7s |  |
| 877 | `point` | 132 | 8.3s |  |
| 878 | `primitive_edge_cases` | 1 | 3.2s |  |
| 879 | `primitive_keys` | 54 | 7.8s |  |
| 880 | `primitive_toString` | 277 | 7.9s |  |
| 881 | `primitive_valueOf` | 285 | 7.6s |  |
| 882 | `print_job_options` | 3 | 7.7s |  |
| 883 | `property_is_enumerable` | 114 | 9.1s |  |
| 884 | `property_is_enumerable_reset` | 23 | 8.0s |  |
| 885 | `property_priority` | 22 | 8.0s |  |
| 886 | `property_priority_chained` | 4 | 7.7s |  |
| 887 | `property_priority_definition_names_order` | 2 | 7.9s |  |
| 888 | `property_priority_three_level` | 6 | 7.9s |  |
| 889 | `propertyisenumerable_namespaces` | 6 | 7.7s |  |
| 890 | `prototype_set_null` | 7 | 7.5s |  |
| 891 | `proxy_callproperty` | 24 | 8.2s |  |
| 892 | `proxy_deleteproperty` | 64 | 7.7s |  |
| 893 | `proxy_enumeration` | 34 | 7.8s |  |
| 894 | `proxy_getproperty` | 77 | 8.3s |  |
| 895 | `proxy_hasownproperty` | 8 | 7.7s |  |
| 896 | `proxy_hasproperty` | 32 | 7.9s |  |
| 897 | `proxy_not_overridden` | 54 | 7.9s |  |
| 898 | `proxy_serialize` | 9 | 7.6s |  |
| 899 | `proxy_setproperty` | 42 | 7.9s |  |
| 900 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.8s |  |
| 901 | `qname_constr` | 32 | 7.9s |  |
| 902 | `qname_constr_namespace` | 24 | 7.8s |  |
| 903 | `qname_enumeration` | 9 | 7.5s |  |
| 904 | `qname_indexing` | 23 | 7.7s |  |
| 905 | `qname_tostring` | 25 | 7.7s |  |
| 906 | `qname_valueof` | 29 | 7.6s |  |
| 907 | `rectangle` | 1094 | 8.0s |  |
| 908 | `regexp_constr` | 148 | 7.8s |  |
| 909 | `regexp_exec` | 19 | 7.6s |  |
| 910 | `regexp_extended` | 47 | 7.4s |  |
| 911 | `regexp_multiargs` | 1 | 7.4s |  |
| 912 | `regexp_test` | 27 | 8.0s |  |
| 913 | `regexp_toString` | 10 | 3.0s |  |
| 914 | `register_script_refresh` | 35 | 7.1s |  |
| 915 | `remove_child_clear_field` | 88 | 6.4s |  |
| 916 | `remove_dobj` | 3 | 6.2s |  |
| 917 | `resolve_order` | 4 | 6.1s |  |
| 918 | `responder_null_callbacks` | 1 | 2.4s |  |
| 919 | `rng` | 1 | 7.0s |  |
| 920 | `rootless` | 42 | 6.6s |  |
| 921 | `rshift` | 1058 | 12.5s |  |
| 922 | `rtqname_not_namespace` | 12 | 6.2s |  |
| 923 | `sandbox_type_inherited` | 2 | 6.6s |  |
| 924 | `sandbox_type_local_file` | 1 | 6.4s |  |
| 925 | `sandbox_type_local_network` | 1 | 6.4s |  |
| 926 | `scene_constr` | 8 | 6.3s |  |
| 927 | `scope_optimizations` | 4 | 6.2s |  |
| 928 | `scopes_dont_cache/order-1` | 1 | 19.7s |  |
| 929 | `scopes_dont_cache/order-2` | 1 | 0.8s |  |
| 930 | `security_domain_current` | 2 | 5.9s |  |
| 931 | `selection` | 239 | 6.6s |  |
| 932 | `set_local_0` | 31 | 6.1s |  |
| 933 | `set_property_is_enumerable` | 85 | 6.4s |  |
| 934 | `shaderparameter_value` | 4 | 5.9s |  |
| 935 | `shape_drawrect` | 54 | 6.5s |  |
| 936 | `shared_object_no_root` | 3 | 6.2s |  |
| 937 | `simplebutton_added_to_stage` | 45 | 21.2s |  |
| 938 | `simplebutton_childevents` | 86 | 21.6s |  |
| 939 | `simplebutton_childevents_nested` | 54 | 6.8s |  |
| 940 | `simplebutton_childevents_sprite` | 13 | 6.6s |  |
| 941 | `simplebutton_childprops` | 144 | 2.8s |  |
| 942 | `simplebutton_childshuffle` | 23 | 6.4s |  |
| 943 | `simplebutton_constr` | 36 | 6.7s |  |
| 944 | `simplebutton_constr_childevents` | 48 | 6.9s |  |
| 945 | `simplebutton_constr_params` | 42 | 7.1s |  |
| 946 | `simplebutton_mouseenabled` | 26 | 2.8s |  |
| 947 | `simplebutton_multi_children` | 19 | 6.7s |  |
| 948 | `simplebutton_soundtransform` | 887 | 22.3s |  |
| 949 | `simplebutton_structure` | 27 | 6.9s |  |
| 950 | `simplebutton_symbolclass` | 68 | 6.6s |  |
| 951 | `slot_disp_id_shared_numbering` | 1 | 20.3s |  |
| 952 | `slots_force_autoassigned` | 1 | 9.6s |  |
| 953 | `socket_after_disconnect` | 1 | 9.5s |  |
| 954 | `socket_close` | 2 | 9.6s |  |
| 955 | `socket_connect` | 4 | 9.5s |  |
| 956 | `socket_errors` | 56 | 10.2s |  |
| 957 | `socket_read_big` | 48 | 9.6s |  |
| 958 | `socket_read_little` | 48 | 3.5s |  |
| 959 | `socket_read_write_object` | 8 | 9.5s |  |
| 960 | `socket_write_big` | 15 | 9.7s |  |
| 961 | `socket_write_little` | 14 | 9.4s |  |
| 962 | `sound_constructor_with_args` | 6 | 9.7s |  |
| 963 | `sound_embeddedprops` | 26 | 9.8s |  |
| 964 | `sound_load_multiple` | 19 | 11.1s |  |
| 965 | `sound_play` | 19 | 9.7s |  |
| 966 | `sound_rootless` | 7 | 9.6s |  |
| 967 | `sound_valueof` | 33 | 9.8s |  |
| 968 | `soundchannel_soundtransform` | 835 | 33.3s |  |
| 969 | `soundchannel_soundtransform_exists` | 5 | 25.5s |  |
| 970 | `soundchannel_stop` | 8 | 9.9s |  |
| 971 | `soundmixer_buffertime` | 5 | 9.6s |  |
| 972 | `soundmixer_soundtransform` | 900 | 12.0s |  |
| 973 | `soundmixer_stopall` | 6 | 9.7s |  |
| 974 | `soundtransform` | 442 | 16.1s |  |
| 975 | `space_justifier_clone` | 12 | 3.7s |  |
| 976 | `sprite_with_frames` | 0 | 32.2s |  |
| 977 | `stage3d_agal_cross_product` | 0 | 13.3s |  |
| 978 | `stage3d_agal_upload_errors` | 66 | 13.0s |  |
| 979 | `stage3d_bitmap` | 0 | 38.6s |  |
| 980 | `stage3d_blend` | 81 | 36.3s |  |
| 981 | `stage3d_context3d_string_args` | 158 | 11.1s |  |
| 982 | `stage3d_errors` | 7 | 9.6s |  |
| 983 | `stage3d_errors_atf` | 3 | 11.1s |  |
| 984 | `stage3d_errors_swf_29` | 6 | 9.8s |  |
| 985 | `stage3d_float1_index` | 0 | 34.5s |  |
| 986 | `stage3d_fractal` | 0 | 35.3s |  |
| 987 | `stage3d_ignore_sampler_override` | 0 | 34.7s |  |
| 988 | `stage3d_multistage_triangle` | 3 | 13.1s |  |
| 989 | `stage3d_program_constants_bytearray_be` | 0 | 36.7s |  |
| 990 | `stage3d_program_constants_bytearray_le` | 0 | 13.6s |  |
| 991 | `stage3d_program_constants_invalid_input` | 21 | 11.1s |  |
| 992 | `stage3d_raytrace` | 0 | 38.6s |  |
| 993 | `stage3d_rotating_cube` | 0 | 13.0s |  |
| 994 | `stage3d_sampler` | 0 | 12.0s |  |
| 995 | `stage3d_sampler_partial_upload` | 0 | 11.9s |  |
| 996 | `stage3d_stencil` | 0 | 32.5s |  |
| 997 | `stage3d_texture` | 0 | 18.7s |  |
| 998 | `stage3d_texture_bytearray` | 0 | 13.9s |  |
| 999 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 12.8s |  |
| 1000 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 13.9s |  |
| 1001 | `stage3d_triangle` | 0 | 12.2s |  |
| 1002 | `stage3d_triangle_bytes4` | 0 | 12.1s |  |
| 1003 | `stage3d_triangle_float1` | 0 | 12.1s |  |
| 1004 | `stage3d_triangle_index_upload` | 0 | 12.1s |  |
| 1005 | `stage3d_x_y` | 22 | 3.3s |  |
| 1006 | `stage_access` | 10 | 8.9s |  |
| 1007 | `stage_display_state` | 6 | 8.8s |  |
| 1008 | `stage_displayobject_properties` | 24 | 3.3s |  |
| 1009 | `stage_domain_getQualifiedDefinitionNames` | 5 | 8.8s |  |
| 1010 | `stage_framerate_nan` | 7 | 9.0s |  |
| 1011 | `stage_framerate_negative` | 6 | 3.3s |  |
| 1012 | `stage_framerate_zero` | 6 | 8.8s |  |
| 1013 | `stage_invalidate` | 38 | 8.9s |  |
| 1014 | `stage_loaderinfo_properties` | 24 | 28.8s |  |
| 1015 | `stage_mousechildren` | 2 | 8.8s |  |
| 1016 | `stage_mouseenabled` | 15 | 8.7s |  |
| 1017 | `stage_overriden_setters` | 31 | 8.9s |  |
| 1018 | `stage_properties` | 30 | 8.8s |  |
| 1019 | `stage_properties2` | 213 | 9.0s |  |
| 1020 | `stage_scale_factor` | 12 | 34.5s |  |
| 1021 | `stage_stage3Ds_vector` | 1 | 8.7s |  |
| 1022 | `static_length` | 24 | 3.4s |  |
| 1023 | `static_text` | 3 | 8.9s |  |
| 1024 | `static_var_with_this_in_ctor` | 2 | 8.7s |  |
| 1025 | `statictext_text` | 8 | 8.9s |  |
| 1026 | `stored_properties` | 11 | 8.8s |  |
| 1027 | `strict_equality` | 34 | 3.4s |  |
| 1028 | `string_call` | 13 | 3.3s |  |
| 1029 | `string_case` | 23 | 8.8s |  |
| 1030 | `string_char_at` | 27 | 8.8s |  |
| 1031 | `string_char_code_at` | 28 | 8.7s |  |
| 1032 | `string_concat_fromcharcode` | 37 | 8.7s |  |
| 1033 | `string_constr` | 25 | 8.8s |  |
| 1034 | `string_indexof_lastindexof` | 87 | 7.3s |  |
| 1035 | `string_length` | 16 | 6.8s |  |
| 1036 | `string_locale_compare` | 39 | 7.1s |  |
| 1037 | `string_match` | 51 | 7.1s |  |
| 1038 | `string_relational_compare` | 4 | 2.6s |  |
| 1039 | `string_replace` | 51 | 6.8s |  |
| 1040 | `string_search` | 41 | 6.8s |  |
| 1041 | `string_slice_substr_substring` | 170 | 7.6s |  |
| 1042 | `string_split` | 29 | 6.6s |  |
| 1043 | `string_substr_negative` | 21 | 6.5s |  |
| 1044 | `string_substr_weird` | 182 | 6.6s |  |
| 1045 | `stylesheet` | 221 | 7.0s |  |
| 1046 | `stylesheet_parse_color` | 69 | 6.3s |  |
| 1047 | `stylesheet_transform` | 307 | 6.5s |  |
| 1048 | `sub_super_same_field` | 12 | 2.6s |  |
| 1049 | `subclass_superclass_linked_symbol` | 4 | 6.8s |  |
| 1050 | `subtract` | 1058 | 13.3s |  |
| 1051 | `super_get_call` | 12 | 6.2s |  |
| 1052 | `supercall_two_classobjects` | 2 | 6.2s |  |
| 1053 | `supercalls_coerce` | 8 | 2.5s |  |
| 1054 | `supercalls_weird` | 2 | 5.9s |  |
| 1055 | `superinterface_call` | 20 | 5.8s |  |
| 1056 | `superinterface_instanceof` | 18 | 6.0s |  |
| 1057 | `swf8` | 1 | 6.1s |  |
| 1058 | `swf_10_queued_goto_scripts_construct` | 52 | 6.3s |  |
| 1059 | `swf_9_goto_in_enter_frame` | 17 | 6.3s |  |
| 1060 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.7s |  |
| 1061 | `swf_9_queued_goto_scripts` | 6 | 6.6s |  |
| 1062 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 1063 | `swf_9_versioning` | 2 | 6.3s |  |
| 1064 | `swf_wrong_frame_count` | 38 | 6.3s |  |
| 1065 | `swf_wrong_frame_count_isplaying` | 22 | 6.0s |  |
| 1066 | `symbol_class_binary_data` | 8 | 6.3s |  |
| 1067 | `symbol_class_conflict` | 4 | 6.7s |  |
| 1068 | `symbol_class_root_not_zero` | 1 | 6.4s |  |
| 1069 | `symbolclass_invalid_utf8` | 2 | 6.0s |  |
| 1070 | `system_exit` | 3 | 5.8s |  |
| 1071 | `system_setclipboard_null` | 1 | 5.9s |  |
| 1072 | `tab_ordering_arrows` | 998 | 21.7s |  |
| 1073 | `tab_ordering_automatic_advanced` | 184 | 7.2s |  |
| 1074 | `tab_ordering_automatic_basic` | 45 | 6.8s |  |
| 1075 | `tab_ordering_children` | 116 | 9.9s |  |
| 1076 | `tab_ordering_custom_basic` | 34 | 8.9s |  |
| 1077 | `tab_ordering_properties` | 732 | 9.3s |  |
| 1078 | `tab_ordering_stage_tab_children` | 32 | 9.0s |  |
| 1079 | `tab_ordering_stage_tab_children_remove_root` | 5 | 8.8s |  |
| 1080 | `tab_ordering_tabbable` | 47 | 9.0s |  |
| 1081 | `tabstop_properties` | 105 | 9.3s |  |
| 1082 | `text_element_basic` | 34 | 9.0s |  |
| 1083 | `text_engine_fontdescription` | 27 | 9.0s |  |
| 1084 | `text_engine_groupelement` | 64 | 9.9s |  |
| 1085 | `text_run` | 7 | 3.3s |  |
| 1086 | `textblock_createline_errors` | 23 | 9.0s |  |
| 1087 | `textblock_createline_fte` | 9 | 29.3s |  |
| 1088 | `textblock_properties` | 118 | 9.4s |  |
| 1089 | `textbox_click` | 37 | 29.5s |  |
| 1090 | `textfield_event` | 66 | 9.4s |  |
| 1091 | `textfield_focusin_event` | 9 | 8.9s |  |
| 1092 | `textfield_input_dead_keys_windows` | 15 | 9.0s |  |
| 1093 | `textfield_input_events` | 25 | 26.5s |  |
| 1094 | `textfield_unload` | 39 | 29.5s |  |
| 1095 | `textformat` | 1134 | 9.0s |  |
| 1096 | `textformat_display` | 14 | 9.0s |  |
| 1097 | `textformat_font_max_length` | 4 | 8.9s |  |
| 1098 | `textjustifier_locale` | 132 | 9.1s |  |
| 1099 | `textline_has_tabs` | 47 | 9.0s |  |
| 1100 | `textline_inapplicable_properties` | 10 | 8.8s |  |
| 1101 | `textline_name` | 1 | 8.8s |  |
| 1102 | `textline_raw_text_length` | 30 | 8.9s |  |
| 1103 | `textline_splitting_basic` | 76 | 9.1s |  |
| 1104 | `textline_throwerror` | 30 | 8.9s |  |
| 1105 | `textline_validity` | 162 | 9.1s |  |
| 1106 | `throw` | 3 | 8.9s |  |
| 1107 | `timeline_scripts` | 3 | 8.9s |  |
| 1108 | `timer` | 90 | 10.2s |  |
| 1109 | `timer_events` | 3 | 8.8s |  |
| 1110 | `timer_finished` | 11 | 9.2s |  |
| 1111 | `timer_invalid_delay` | 30 | 4.2s |  |
| 1112 | `timer_reset` | 8 | 9.8s |  |
| 1113 | `timer_setdelay` | 5 | 9.6s |  |
| 1114 | `trace` | 12 | 9.3s |  |
| 1115 | `truthiness` | 30 | 9.4s |  |
| 1116 | `try_catch` | 11 | 9.6s |  |
| 1117 | `try_catch_typed` | 12 | 9.6s |  |
| 1118 | `typeof` | 30 | 9.6s |  |
| 1119 | `uint_constr` | 92 | 9.7s |  |
| 1120 | `uint_tofixed` | 1215 | 9.3s |  |
| 1121 | `uint_toprecision` | 1125 | 9.6s |  |
| 1122 | `uint_tostring` | 3375 | 9.7s |  |
| 1123 | `uncaught_error_basic` | 2 | 9.2s |  |
| 1124 | `unchecked_function` | 15 | 9.2s |  |
| 1125 | `unescape` | 28 | 9.3s |  |
| 1126 | `url_loader` | 25 | 9.5s |  |
| 1127 | `url_vars` | 27 | 9.5s |  |
| 1128 | `urlrequest` | 18 | 9.3s |  |
| 1129 | `urlstream_basic` | 5 | 9.3s |  |
| 1130 | `urshift` | 1058 | 20.8s |  |
| 1131 | `utils3d` | 7 | 9.2s |  |
| 1132 | `vector3d` | 397 | 14.2s |  |
| 1133 | `vector3d_near_equals` | 80 | 9.4s |  |
| 1134 | `vector_class` | 36 | 9.9s |  |
| 1135 | `vector_class_call` | 11 | 9.6s |  |
| 1136 | `vector_coercion` | 66 | 10.5s |  |
| 1137 | `vector_concat` | 90 | 10.1s |  |
| 1138 | `vector_constr` | 107 | 10.4s |  |
| 1139 | `vector_enumeration` | 5 | 9.3s |  |
| 1140 | `vector_every` | 92 | 10.3s |  |
| 1141 | `vector_filter` | 95 | 10.4s |  |
| 1142 | `vector_holes` | 24 | 9.5s |  |
| 1143 | `vector_indexof` | 302 | 14.8s |  |
| 1144 | `vector_insertat` | 270 | 10.9s |  |
| 1145 | `vector_int_access` | 4 | 9.4s |  |
| 1146 | `vector_int_delete` | 11 | 3.6s |  |
| 1147 | `vector_join` | 58 | 9.9s |  |
| 1148 | `vector_lastindexof` | 302 | 9.1s |  |
| 1149 | `vector_legacy` | 10 | 9.3s |  |
| 1150 | `vector_map` | 85 | 10.2s |  |
| 1151 | `vector_object_final` | 1 | 8.2s |  |
| 1152 | `vector_object_toString` | 10 | 7.8s |  |
| 1153 | `vector_prototype_some` | 125 | 7.8s |  |
| 1154 | `vector_pushpop` | 255 | 8.8s |  |
| 1155 | `vector_reborrow_bug` | 10 | 8.0s |  |
| 1156 | `vector_removeat` | 172 | 8.7s |  |
| 1157 | `vector_reverse` | 232 | 8.8s |  |
| 1158 | `vector_shiftunshift` | 252 | 7.7s |  |
| 1159 | `vector_slice` | 331 | 9.2s |  |
| 1160 | `vector_sort` | 905 | 15.9s |  |
| 1161 | `vector_splice` | 693 | 11.2s |  |
| 1162 | `vector_splice_fixed_bug_compat` | 4 | 7.8s |  |
| 1163 | `vector_tostring` | 79 | 8.3s |  |
| 1164 | `verification` | 8 | 7.7s |  |
| 1165 | `verify_abnormal_loop` | 1 | 7.9s |  |
| 1166 | `verify_dxns_without_flag` | 3 | 8.0s |  |
| 1167 | `verify_exception_target_two_jumps` | 1 | 3.0s |  |
| 1168 | `verify_exception_targets_edge_case` | 1 | 7.8s |  |
| 1169 | `verify_illegal_opcode` | 1 | 3.5s |  |
| 1170 | `verify_jump_to_middle_of_op` | 1 | 7.7s |  |
| 1171 | `verify_lookup_switch_edge_case` | 1 | 7.8s |  |
| 1172 | `verify_method_info_oob` | 1 | 1.2s |  |
| 1173 | `verify_stack` | 5 | 7.8s |  |
| 1174 | `verify_typecheck` | 4 | 7.9s |  |
| 1175 | `verify_unreachable_exception` | 2 | 7.9s |  |
| 1176 | `versioned_isplaying` | 2 | 7.7s |  |
| 1177 | `virtual_properties` | 16 | 7.9s |  |
| 1178 | `with` | 4 | 7.7s |  |
| 1179 | `wrong_arg_count` | 7 | 3.3s |  |
| 1180 | `xml_abstract_equality` | 36 | 7.8s |  |
| 1181 | `xml_advanced` | 52 | 7.7s |  |
| 1182 | `xml_appendchild` | 10 | 7.7s |  |
| 1183 | `xml_appendchild_swf_v21` | 13 | 8.6s |  |
| 1184 | `xml_as_attribute` | 9 | 7.6s |  |
| 1185 | `xml_attribute` | 35 | 7.8s |  |
| 1186 | `xml_attribute_name` | 40 | 7.7s |  |
| 1187 | `xml_basic` | 33 | 7.6s |  |
| 1188 | `xml_child` | 25 | 7.6s |  |
| 1189 | `xml_childindex` | 7 | 2.9s |  |
| 1190 | `xml_children` | 43 | 8.0s |  |
| 1191 | `xml_class_call` | 9 | 7.4s |  |
| 1192 | `xml_contains` | 197 | 2.5s |  |
| 1193 | `xml_copy` | 20 | 1.1s |  |
| 1194 | `xml_ctor_from_tostring` | 23 | 1.1s |  |
| 1195 | `xml_delete` | 114 | 1.1s |  |
| 1196 | `xml_descendants` | 83 | 1.1s |  |
| 1197 | `xml_duplicate_attribute` | 14 | 1.1s |  |
| 1198 | `xml_elements` | 6 | 1.1s |  |
| 1199 | `xml_equals_namespace_check` | 2 | 1.1s |  |
| 1200 | `xml_explicit_use_namespace` | 5 | 1.1s |  |
| 1201 | `xml_getdescendants_qname` | 21 | 1.1s |  |
| 1202 | `xml_has_property_via_in` | 26 | 1.1s |  |
| 1203 | `xml_hasownproperty` | 6 | 1.1s |  |
| 1204 | `xml_ignore_white` | 6 | 1.1s |  |
| 1205 | `xml_length` | 2 | 1.1s |  |
| 1206 | `xml_list_as_attribute` | 9 | 1.1s |  |
| 1207 | `xml_list_concat` | 20 | 1.1s |  |
| 1208 | `xml_list_ctor_errors` | 34 | 1.1s |  |
| 1209 | `xml_list_delete_clear_parent` | 6 | 1.1s |  |
| 1210 | `xml_list_enumerate` | 4 | 1.1s |  |
| 1211 | `xml_methods_settings` | 3 | 1.1s |  |
| 1212 | `xml_mismatched_tag` | 37 | 1.1s |  |
| 1213 | `xml_namespace` | 39 | 1.1s |  |
| 1214 | `xml_namespace_methods` | 245 | 1.1s |  |
| 1215 | `xml_namespaced_property` | 7 | 1.1s |  |
| 1216 | `xml_no_namespace` | 1 | 1.1s |  |
| 1217 | `xml_nodekind` | 3 | 1.1s |  |
| 1218 | `xml_normalize` | 35 | 1.1s |  |
| 1219 | `xml_notification_bubbling` | 361 | 1.1s |  |
| 1220 | `xml_parent` | 8 | 1.1s |  |
| 1221 | `xml_set_children` | 17 | 1.1s |  |
| 1222 | `xml_set_name` | 34 | 1.1s |  |
| 1223 | `xml_settings` | 6 | 1.1s |  |
| 1224 | `xml_simple_complex_content` | 47 | 1.1s |  |
| 1225 | `xml_socket` | 11 | 1.1s |  |
| 1226 | `xml_text` | 7 | 1.1s |  |
| 1227 | `xml_tostring` | 6 | 1.1s |  |
| 1228 | `xml_tostring_namespace` | 12 | 1.1s |  |
| 1229 | `xml_unescaping` | 23 | 1.1s |  |
| 1230 | `xml_weird_ignores` | 54 | 1.1s |  |
| 1231 | `xml_wildcard` | 11 | 1.1s |  |
| 1232 | `xmldocument` | 254 | 1.1s |  |
| 1233 | `xmlnode` | 3540 | 1.1s |  |
| 1234 | `zero_frame_clip` | 3 | 1.7s |  |

## Ruffle-Matched Tests

**42 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 1.1s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.1s |  |
| 3 | `blend_transform` | 1 | 1 | 5.7s |  |
| 4 | `bounds_mode` | 6 | 6 | 6.1s |  |
| 5 | `coerce_property` | 3 | 3 | 6.8s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.5s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 10.1s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 28.9s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 8.8s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 9.0s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 8.8s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 5.7s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.6s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 5.6s |  |
| 15 | `event_handler_exception` | 4 | 4 | 5.7s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 7.3s |  |
| 17 | `goto_framescript_queued/swf13` | 3 | 3 | 1.2s |  |
| 18 | `gradient_values_readback` | 12 | 12 | 9.9s |  |
| 19 | `graphics_draw_path` | 50 | 50 | 31.4s |  |
| 20 | `groupelement_text` | 2 | 2 | 9.7s |  |
| 21 | `html_text_img_parsing` | 95 | 95 | 9.7s |  |
| 22 | `int_toexponential` | 76 | 76 | 9.4s |  |
| 23 | `json_parse_numbers` | 4 | 79 | 9.3s |  |
| 24 | `loader_events_2` | 30 | 30 | 9.2s |  |
| 25 | `matrix3d_recompose_edge_cases` | 8 | 85 | 7.5s |  |
| 26 | `number_convert_errors` | 706 | 706 | 7.5s |  |
| 27 | `number_to_string` | 104 | 104 | 7.7s |  |
| 28 | `simplebutton_childevents_multichild` | 101 | 101 | 6.4s |  |
| 29 | `simplebutton_childevents_script_order` | 4 | 4 | 6.8s |  |
| 30 | `slot_holes_fail` | 1 | 1 | 6.3s |  |
| 31 | `slot_id_exceeds_trait_count` | 1 | 1 | 4.1s |  |
| 32 | `soundchannel_position` | 74 | 74 | 32.3s |  |
| 33 | `soundchannel_soundcomplete` | 10 | 10 | 10.1s |  |
| 34 | `sprite_dropTarget` | 15 | 15 | 9.7s |  |
| 35 | `swf_9_goto_in_construct_frame` | 12 | 12 | 20.2s |  |
| 36 | `textblock_line_changes` | 44 | 44 | 9.6s |  |
| 37 | `textblock_recreateline` | 137 | 138 | 9.5s |  |
| 38 | `textblock_releaselines` | 4 | 4 | 10.6s |  |
| 39 | `textline_atom_index_at_char_index` | 3 | 3 | 9.9s |  |
| 40 | `uint_toexponential` | 100 | 100 | 9.7s |  |
| 41 | `uncaught_errors_stringified` | 15 | 15 | 9.4s |  |
| 42 | `weird_superinterface_properties` | 1 | 1 | 7.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**8 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `array_join_reentrant` | 85.3% | 58 | 68 | 10 |  |
| 3 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 4 | `hit_test_scroll_rect` | 69.7% | 69 | 99 | 30 |  |
| 5 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 6 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 7 | `dictionary_qname_keys` | 50.9% | 29 | 57 | 28 |  |
| 8 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**24 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `array_join_reentrant` | 85.3% | 58/68 | 68 | 68 |  |
| 3 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 4 | `hit_test_scroll_rect` | 69.7% | 69/99 | 99 | 99 |  |
| 5 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 6 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 7 | `dictionary_qname_keys` | 50.9% | 29/57 | 57 | 45 |  |
| 8 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 9 | `textfield_default_text_format_null` | 35.0% | 7/20 | 12 | 20 |  |
| 10 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 11 | `focus_events_mixed_avm_edittext` | 24.5% | 12/49 | 47 | 49 |  |
| 12 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 13 | `context3d_draw_to_bitmap_data` | 13.3% | 2/15 | 11 | 15 |  |
| 14 | `vector_join_reentrant` | 10.4% | 10/96 | 84 | 96 |  |
| 15 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 16 | `array_constructor` | 9.0% | 21/234 | 181 | 234 |  |
| 17 | `textfield_get_text_format_args` | 8.8% | 50/567 | 447 | 567 |  |
| 18 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 19 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 20 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 21 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 22 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 23 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 24 | `textline_metrics` | 0.0% | 0/20 | 20 | 20 |  |
