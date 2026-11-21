# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 17:00 UTC

**Git SHA**: `08709f6584`

**Run Duration**: 207m 32s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1334 |
| Passing | **1240** (93.0%) |
| Ruffle-matched | 42 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1282** (96.1%) |
| Failing | 52 |
| Total expected lines | 163871 |
| Matching lines | 157951 (96.4%) |
| Mismatched lines | 5920 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 52 | 100.0% |

## Passing Tests

**1240 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 25.3s |  |
| 2 | `accessibility` | 1 | 5.6s |  |
| 3 | `accessibilityimplementation` | 18 | 21.7s |  |
| 4 | `activation_class` | 6 | 5.7s |  |
| 5 | `add` | 1058 | 13.1s |  |
| 6 | `agal_compiler` | 13 | 7.9s |  |
| 7 | `air_datagram_socket` | 1 | 7.3s |  |
| 8 | `air_hidden_lookup` | 2 | 5.6s |  |
| 9 | `air_ifilepromise` | 1 | 5.5s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 5.6s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.4s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.4s |  |
| 13 | `all_classes/display/swf10` | 2569 | 5.7s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.5s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.5s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.5s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.4s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.4s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 5.6s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.4s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.4s |  |
| 22 | `all_classes/errors/swf10` | 140 | 5.7s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.4s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.4s |  |
| 25 | `all_classes/events/swf10` | 1638 | 5.7s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.4s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.4s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.4s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.4s |  |
| 30 | `all_classes/security/swf11` | 3 | 5.7s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.4s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.4s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.4s |  |
| 34 | `all_classes/xml/swf30` | 116 | 5.7s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.4s |  |
| 36 | `amf_array_serialization` | 17 | 24.5s |  |
| 37 | `amf_custom_obj` | 26 | 5.9s |  |
| 38 | `amf_dictionary` | 9 | 5.7s |  |
| 39 | `amf_function` | 46 | 5.7s |  |
| 40 | `amf_invalid_date` | 2 | 5.6s |  |
| 41 | `amf_missing_prop` | 6 | 5.7s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 5.7s |  |
| 43 | `amf_sealed_class_dynamic_properties` | 16 | 5.8s |  |
| 44 | `amf_setter_error` | 8 | 5.8s |  |
| 45 | `amf_vector` | 40 | 5.9s |  |
| 46 | `amf_xml` | 6 | 25.1s |  |
| 47 | `appdomain_lookup_edge_cases` | 32 | 5.5s |  |
| 48 | `application_domain` | 4 | 5.5s |  |
| 49 | `applicationdomain_getqualifieddefinitionnames` | 9 | 21.6s |  |
| 50 | `applicationdomain_hasdefinition_null` | 2 | 5.4s |  |
| 51 | `array_access` | 18 | 5.4s |  |
| 52 | `array_access_interpreter` | 4 | 5.4s |  |
| 53 | `array_access_no_pubns` | 2 | 5.4s |  |
| 54 | `array_concat` | 41 | 5.5s |  |
| 55 | `array_constr` | 10 | 5.4s |  |
| 56 | `array_delete` | 44 | 5.4s |  |
| 57 | `array_enumeration` | 10 | 5.4s |  |
| 58 | `array_enumeration_elements` | 11 | 5.4s |  |
| 59 | `array_every` | 8 | 5.4s |  |
| 60 | `array_filter` | 6 | 5.4s |  |
| 61 | `array_foreach` | 18 | 5.4s |  |
| 62 | `array_hasownproperty` | 11 | 5.5s |  |
| 63 | `array_holes` | 9 | 5.5s |  |
| 64 | `array_index_max` | 84 | 5.4s |  |
| 65 | `array_indexof` | 25 | 5.5s |  |
| 66 | `array_join` | 26 | 5.4s |  |
| 67 | `array_lastindexof` | 29 | 5.4s |  |
| 68 | `array_length` | 14 | 5.5s |  |
| 69 | `array_literal` | 3 | 5.5s |  |
| 70 | `array_map` | 8 | 5.3s |  |
| 71 | `array_pop` | 52 | 5.5s |  |
| 72 | `array_push` | 24 | 5.4s |  |
| 73 | `array_reborrow_bug` | 6 | 5.4s |  |
| 74 | `array_reverse` | 28 | 5.5s |  |
| 75 | `array_shift` | 51 | 1.5s |  |
| 76 | `array_slice` | 39 | 5.5s |  |
| 77 | `array_some` | 8 | 5.5s |  |
| 78 | `array_sort` | 297 | 5.5s |  |
| 79 | `array_sort_fun_swf12` | 2 | 5.5s |  |
| 80 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 81 | `array_sort_random` | 210 | 5.5s |  |
| 82 | `array_sort_swf10_32bit` | 1 | 5.5s |  |
| 83 | `array_sorton` | 545 | 5.5s |  |
| 84 | `array_sparse_ops` | 41 | 5.5s |  |
| 85 | `array_splice` | 133 | 24.5s |  |
| 86 | `array_splice2` | 428 | 21.4s |  |
| 87 | `array_splice_types` | 48 | 5.4s |  |
| 88 | `array_storage` | 8 | 5.5s |  |
| 89 | `array_tolocalestring` | 9 | 5.5s |  |
| 90 | `array_tostring` | 12 | 5.5s |  |
| 91 | `array_unshift` | 24 | 5.4s |  |
| 92 | `array_valueof` | 9 | 5.4s |  |
| 93 | `array_vector_null_callback` | 10 | 5.5s |  |
| 94 | `astype` | 28 | 5.6s |  |
| 95 | `astypelate` | 24 | 5.6s |  |
| 96 | `astypelate_propagates` | 1 | 5.4s |  |
| 97 | `asymmetric_key_events` | 11 | 5.7s |  |
| 98 | `automation_classes` | 122 | 5.8s |  |
| 99 | `av_classes` | 340 | 5.8s |  |
| 100 | `avm1movie_addcallback_call` | 14 | 5.6s |  |
| 101 | `avm2_catchup_dobj` | 158 | 6.1s |  |
| 102 | `away3d_advanced_shallow_water_demo` | 0 | 73.8s |  |
| 103 | `bevel_filter` | 187 | 5.6s |  |
| 104 | `bitand` | 1058 | 12.3s |  |
| 105 | `bitmap_constr` | 17 | 5.6s |  |
| 106 | `bitmap_data` | 1000 | 11.8s |  |
| 107 | `bitmap_filter_abstract` | 6 | 5.5s |  |
| 108 | `bitmap_pixelsnapping` | 2 | 21.2s |  |
| 109 | `bitmap_properties` | 23 | 5.5s |  |
| 110 | `bitmap_subclass` | 7 | 6.8s |  |
| 111 | `bitmap_subclass_properties` | 9 | 5.7s |  |
| 112 | `bitmap_timeline` | 9 | 5.5s |  |
| 113 | `bitmapdata_accuracy` | 1 | 46.5s |  |
| 114 | `bitmapdata_applyfilter_blur` | 0 | 21.6s |  |
| 115 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.8s |  |
| 116 | `bitmapdata_applyfilter_destpoint` | 0 | 21.2s |  |
| 117 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 21.5s |  |
| 118 | `bitmapdata_applyfilter_identity` | 4 | 21.1s |  |
| 119 | `bitmapdata_clone` | 13 | 5.5s |  |
| 120 | `bitmapdata_colortransform` | 0 | 5.6s |  |
| 121 | `bitmapdata_colortransform_oob` | 2 | 5.4s |  |
| 122 | `bitmapdata_constr` | 22 | 5.5s |  |
| 123 | `bitmapdata_constructor_from_timeline` | 1 | 5.7s |  |
| 124 | `bitmapdata_copychannel` | 0 | 22.7s |  |
| 125 | `bitmapdata_copypixels` | 23 | 21.2s |  |
| 126 | `bitmapdata_copypixels_alpha_combine` | 13 | 5.5s |  |
| 127 | `bitmapdata_copypixels_alpha_merge` | 9 | 5.4s |  |
| 128 | `bitmapdata_copypixels_blend` | 1029 | 34.9s |  |
| 129 | `bitmapdata_copypixels_blend_over` | 1 | 8.3s |  |
| 130 | `bitmapdata_copypixels_self` | 612 | 8.3s |  |
| 131 | `bitmapdata_copypixelstobytearray` | 39 | 8.3s |  |
| 132 | `bitmapdata_dispose` | 7 | 8.4s |  |
| 133 | `bitmapdata_draw` | 0 | 30.8s |  |
| 134 | `bitmapdata_draw_alpha_erase` | 8 | 8.3s |  |
| 135 | `bitmapdata_draw_cab_quality` | 0 | 32.2s |  |
| 136 | `bitmapdata_draw_colortransform` | 0 | 30.5s |  |
| 137 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 30.2s |  |
| 138 | `bitmapdata_draw_filters` | 0 | 30.1s |  |
| 139 | `bitmapdata_draw_masks` | 0 | 8.3s |  |
| 140 | `bitmapdata_draw_rotation` | 0 | 8.3s |  |
| 141 | `bitmapdata_draw_self_via_graphic` | 0 | 8.3s |  |
| 142 | `bitmapdata_draw_stage` | 0 | 30.8s |  |
| 143 | `bitmapdata_drawwithquality` | 0 | 8.5s |  |
| 144 | `bitmapdata_embedded` | 9 | 8.4s |  |
| 145 | `bitmapdata_fillrect` | 0 | 8.1s |  |
| 146 | `bitmapdata_filter_sourcerect` | 0 | 29.0s |  |
| 147 | `bitmapdata_floodfill` | 35 | 8.0s |  |
| 148 | `bitmapdata_getpixels` | 39 | 28.8s |  |
| 149 | `bitmapdata_getvector` | 27 | 2.7s |  |
| 150 | `bitmapdata_histogram` | 59 | 2.7s |  |
| 151 | `bitmapdata_hittest` | 112 | 8.6s |  |
| 152 | `bitmapdata_hittest_threshold` | 18 | 8.0s |  |
| 153 | `bitmapdata_opaque` | 0 | 8.0s |  |
| 154 | `bitmapdata_pixeldissolve` | 1037 | 8.6s |  |
| 155 | `bitmapdata_pixeldissolve_image` | 0 | 8.2s |  |
| 156 | `bitmapdata_rectangle_rounding` | 16 | 7.9s |  |
| 157 | `bitmapdata_setpixels` | 286 | 8.0s |  |
| 158 | `bitmapdata_setvector` | 26 | 8.2s |  |
| 159 | `bitmapdata_sync` | 0 | 29.1s |  |
| 160 | `bitmapdata_threshold` | 176 | 8.7s |  |
| 161 | `bitmapdata_zero_size` | 8 | 7.9s |  |
| 162 | `bitnot` | 46 | 7.9s |  |
| 163 | `bitor` | 1058 | 19.5s |  |
| 164 | `bitxor` | 1058 | 19.5s |  |
| 165 | `blend_mode_null` | 1 | 7.8s |  |
| 166 | `blend_multiply_alpha` | 0 | 7.9s |  |
| 167 | `blend_scroll` | 0 | 8.0s |  |
| 168 | `blend_shader_luma_lighten` | 3 | 8.3s |  |
| 169 | `blur_filter` | 43 | 5.8s |  |
| 170 | `boolean_constr` | 32 | 5.8s |  |
| 171 | `boolean_negation` | 30 | 5.7s |  |
| 172 | `boolean_tostring` | 8 | 5.7s |  |
| 173 | `broadcast_event` | 7 | 5.7s |  |
| 174 | `button_bounds` | 1 | 5.8s |  |
| 175 | `button_hittest` | 2 | 22.3s |  |
| 176 | `button_nested_frame` | 48 | 23.0s |  |
| 177 | `button_nested_frame_simple` | 27 | 6.1s |  |
| 178 | `bytearray` | 48 | 6.0s |  |
| 179 | `bytearray_amf3_shared_references` | 4 | 5.8s |  |
| 180 | `bytearray_bad_symbol_class` | 3 | 5.8s |  |
| 181 | `bytearray_bad_symbol_class_other_movie` | 6 | 6.1s |  |
| 182 | `bytearray_compress` | 31 | 5.8s |  |
| 183 | `bytearray_errors` | 24 | 5.9s |  |
| 184 | `bytearray_insertion_reborrow` | 5 | 5.8s |  |
| 185 | `bytearray_method_serialization` | 1 | 5.7s |  |
| 186 | `bytearray_oom` | 3 | 5.7s |  |
| 187 | `bytearray_readobject_amf0` | 50 | 5.7s |  |
| 188 | `bytearray_readobject_amf3` | 53 | 5.8s |  |
| 189 | `bytearray_readutf8bytes_with_bom` | 16 | 5.8s |  |
| 190 | `bytearray_serialization` | 3 | 5.7s |  |
| 191 | `bytearray_string_null` | 19 | 5.9s |  |
| 192 | `bytearray_tostring` | 15 | 5.7s |  |
| 193 | `bytearray_utf16` | 8 | 5.7s |  |
| 194 | `bytearray_writeobject` | 24 | 5.5s |  |
| 195 | `callee_in_initializer` | 6 | 5.6s |  |
| 196 | `callproplex_class` | 1 | 5.6s |  |
| 197 | `capabilities_resolution` | 8 | 23.2s |  |
| 198 | `casi32` | 166 | 5.8s |  |
| 199 | `catch_class` | 6 | 5.7s |  |
| 200 | `catch_scope_slot` | 7 | 5.8s |  |
| 201 | `checkfilter` | 4 | 1.7s |  |
| 202 | `class_call` | 32 | 5.8s |  |
| 203 | `class_cast_call` | 14 | 5.7s |  |
| 204 | `class_enumeration` | 4 | 5.7s |  |
| 205 | `class_has_own_property` | 2 | 5.7s |  |
| 206 | `class_init_interpreter_mode` | 1 | 5.7s |  |
| 207 | `class_is` | 32 | 5.8s |  |
| 208 | `class_methods` | 5 | 5.8s |  |
| 209 | `class_object_properties` | 10 | 5.8s |  |
| 210 | `class_singleton` | 18 | 5.8s |  |
| 211 | `class_supercalls_errors` | 35 | 8.6s |  |
| 212 | `class_supercalls_mismatched` | 26 | 8.3s |  |
| 213 | `class_superclass_wrong_order` | 1 | 30.6s |  |
| 214 | `class_to_locale_string` | 2 | 8.2s |  |
| 215 | `class_to_string` | 2 | 8.0s |  |
| 216 | `class_value_of` | 2 | 8.1s |  |
| 217 | `click_block` | 5 | 30.6s |  |
| 218 | `click_invisible` | 3 | 8.4s |  |
| 219 | `closures` | 12 | 8.4s |  |
| 220 | `coerce_return_type` | 40 | 8.6s |  |
| 221 | `coerce_return_type_fail` | 2 | 8.2s |  |
| 222 | `coerce_return_void` | 3 | 8.1s |  |
| 223 | `coerce_string` | 86 | 8.3s |  |
| 224 | `coerce_string_precision` | 28 | 8.2s |  |
| 225 | `coerce_to_primitive_side_effects` | 29 | 8.4s |  |
| 226 | `collator_compare_basic` | 93 | 8.5s |  |
| 227 | `collator_flags` | 111 | 8.2s |  |
| 228 | `collator_locale_ids_windows` | 120 | 8.4s |  |
| 229 | `color_matrix_filter` | 19 | 8.3s |  |
| 230 | `construct_errors_swf10` | 8 | 8.2s |  |
| 231 | `construct_frame_list` | 22 | 30.6s |  |
| 232 | `construct_interface` | 3 | 8.2s |  |
| 233 | `constructor_call` | 3 | 8.2s |  |
| 234 | `constructors_vs_timeline` | 5 | 30.8s |  |
| 235 | `constructprop_dynamic_primitive` | 7 | 8.3s |  |
| 236 | `constructprop_method` | 2 | 8.2s |  |
| 237 | `constructsuper_null` | 2 | 2.8s |  |
| 238 | `content_element_basic` | 50 | 8.6s |  |
| 239 | `context3d_clear_mask` | 4 | 8.0s |  |
| 240 | `context3d_creation` | 9 | 8.3s |  |
| 241 | `control_flow_bool` | 4 | 8.2s |  |
| 242 | `control_flow_stricteq` | 8 | 8.2s |  |
| 243 | `convert_boolean` | 30 | 8.2s |  |
| 244 | `convert_integer` | 90 | 8.3s |  |
| 245 | `convert_number` | 56 | 8.4s |  |
| 246 | `convert_uinteger` | 90 | 8.3s |  |
| 247 | `convolution_filter` | 89 | 8.3s |  |
| 248 | `core_exceptions` | 47 | 9.7s |  |
| 249 | `cpool_index_invalid_bytecode_1` | 6 | 8.3s |  |
| 250 | `cpool_index_invalid_bytecode_2` | 3 | 8.2s |  |
| 251 | `cpool_index_invalid_bytecode_3` | 1 | 8.2s |  |
| 252 | `cross_api_version_call_newer` | 12 | 9.2s |  |
| 253 | `cross_api_version_call_older` | 12 | 5.7s |  |
| 254 | `cryptscore` | 11 | 5.5s |  |
| 255 | `currency_parse_result` | 7 | 5.1s |  |
| 256 | `date` | 30 | 5.5s |  |
| 257 | `date_parse` | 36 | 5.2s |  |
| 258 | `date_set_time_out_of_range` | 62 | 5.1s |  |
| 259 | `declocal` | 46 | 5.0s |  |
| 260 | `declocal_i` | 46 | 5.2s |  |
| 261 | `decode_uri` | 71 | 5.5s |  |
| 262 | `decrement` | 46 | 5.3s |  |
| 263 | `decrement_i` | 46 | 1.8s |  |
| 264 | `default_values` | 7 | 5.2s |  |
| 265 | `delayed_symbolclass` | 28 | 18.5s |  |
| 266 | `describe_type_basic` | 152 | 5.1s |  |
| 267 | `describe_type_json` | 301 | 5.2s |  |
| 268 | `describe_type_metadata` | 125 | 5.2s |  |
| 269 | `describe_type_native` | 23 | 5.2s |  |
| 270 | `dictionary_access` | 62 | 5.4s |  |
| 271 | `dictionary_access_no_pubns` | 2 | 5.0s |  |
| 272 | `dictionary_delete` | 101 | 5.6s |  |
| 273 | `dictionary_foreach` | 42 | 5.5s |  |
| 274 | `dictionary_hasownproperty` | 63 | 5.5s |  |
| 275 | `dictionary_in` | 62 | 5.3s |  |
| 276 | `dictionary_iter_modify` | 8 | 5.3s |  |
| 277 | `dictionary_namespaces` | 36 | 5.5s |  |
| 278 | `displacement_map_filter` | 61 | 5.5s |  |
| 279 | `displayobject_alpha` | 277 | 5.3s |  |
| 280 | `displayobject_blendmode` | 0 | 19.7s |  |
| 281 | `displayobject_colortransform_nested` | 0 | 19.5s |  |
| 282 | `displayobject_early_init` | 54 | 6.7s |  |
| 283 | `displayobject_filters` | 17 | 5.4s |  |
| 284 | `displayobject_from_enterframe` | 1 | 19.5s |  |
| 285 | `displayobject_getbounds_shape` | 0 | 19.4s |  |
| 286 | `displayobject_getrect` | 16 | 5.7s |  |
| 287 | `displayobject_height` | 6052 | 19.6s |  |
| 288 | `displayobject_hittestobject` | 32 | 5.3s |  |
| 289 | `displayobject_hittestpoint` | 49 | 5.4s |  |
| 290 | `displayobject_hittestpoint_boundary` | 65 | 19.3s |  |
| 291 | `displayobject_hittestpoint_root` | 13 | 5.4s |  |
| 292 | `displayobject_invalid_floats` | 60 | 5.0s |  |
| 293 | `displayobject_invalid_props` | 3 | 5.2s |  |
| 294 | `displayobject_mask` | 3 | 5.2s |  |
| 295 | `displayobject_mask_self_referential` | 0 | 22.4s |  |
| 296 | `displayobject_metaData` | 3 | 6.2s |  |
| 297 | `displayobject_name` | 22 | 22.6s |  |
| 298 | `displayobject_name_from_timeline` | 24 | 6.4s |  |
| 299 | `displayobject_opaque_background` | 6 | 22.5s |  |
| 300 | `displayobject_parent` | 12 | 6.2s |  |
| 301 | `displayobject_root` | 24 | 6.3s |  |
| 302 | `displayobject_rotation` | 1284 | 6.4s |  |
| 303 | `displayobject_scrollrect` | 33 | 6.7s |  |
| 304 | `displayobject_set_matrix_nested` | 0 | 22.8s |  |
| 305 | `displayobject_set_name_loaded` | 3 | 6.6s |  |
| 306 | `displayobject_subclass` | 2 | 6.2s |  |
| 307 | `displayobject_transform` | 89 | 6.3s |  |
| 308 | `displayobject_visible` | 23 | 6.2s |  |
| 309 | `displayobject_width` | 4852 | 22.9s |  |
| 310 | `displayobject_x` | 614 | 6.2s |  |
| 311 | `displayobject_y` | 617 | 6.3s |  |
| 312 | `displayobject_z` | 38 | 22.7s |  |
| 313 | `displayobjectcontainer_addchild` | 32 | 6.3s |  |
| 314 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.2s |  |
| 315 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.5s |  |
| 316 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.3s |  |
| 317 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.3s |  |
| 318 | `displayobjectcontainer_addchildat` | 42 | 6.3s |  |
| 319 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.3s |  |
| 320 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.3s |  |
| 321 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.3s |  |
| 322 | `displayobjectcontainer_contains` | 66 | 22.8s |  |
| 323 | `displayobjectcontainer_getchildat` | 4 | 6.3s |  |
| 324 | `displayobjectcontainer_getchildbyname` | 9 | 6.2s |  |
| 325 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.2s |  |
| 326 | `displayobjectcontainer_getchildindex` | 28 | 6.2s |  |
| 327 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 22.4s |  |
| 328 | `displayobjectcontainer_removechild` | 10 | 6.2s |  |
| 329 | `displayobjectcontainer_removechild_errors` | 4 | 6.2s |  |
| 330 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.3s |  |
| 331 | `displayobjectcontainer_removechildat` | 18 | 6.2s |  |
| 332 | `displayobjectcontainer_removechildren` | 51 | 6.5s |  |
| 333 | `displayobjectcontainer_setchildindex` | 42 | 6.1s |  |
| 334 | `displayobjectcontainer_stopallmovieclips` | 2 | 22.9s |  |
| 335 | `displayobjectcontainer_swapchildren` | 42 | 6.3s |  |
| 336 | `displayobjectcontainer_swapchildrenat` | 42 | 5.2s |  |
| 337 | `displayobjectcontainer_timelineinstance` | 48 | 17.8s |  |
| 338 | `divide` | 1058 | 10.9s |  |
| 339 | `doabc_and_symbolclass_script_init_goto` | 7 | 17.8s |  |
| 340 | `doabc_and_symbolclass_script_init_normal` | 6 | 4.9s |  |
| 341 | `doabc_is_eager` | 1 | 17.5s |  |
| 342 | `documentclass` | 9 | 5.2s |  |
| 343 | `domain_memory` | 133 | 18.9s |  |
| 344 | `drag_drop` | 10 | 5.4s |  |
| 345 | `drop_shadow_filter` | 172 | 5.3s |  |
| 346 | `duplicate_defs` | 1 | 5.0s |  |
| 347 | `eager_init` | 1 | 5.2s |  |
| 348 | `east_asian_justifier_clone` | 8 | 5.4s |  |
| 349 | `edit_text_linkage` | 7 | 5.3s |  |
| 350 | `edittext_align` | 60 | 5.5s |  |
| 351 | `edittext_always_show_selection` | 0 | 19.4s |  |
| 352 | `edittext_antialiastype` | 296 | 5.6s |  |
| 353 | `edittext_at_point_methods_basic` | 16 | 6.4s |  |
| 354 | `edittext_autosize` | 39 | 5.5s |  |
| 355 | `edittext_autosize_align` | 0 | 18.9s |  |
| 356 | `edittext_autosize_height_dynamic` | 60 | 20.1s |  |
| 357 | `edittext_autosize_height_input` | 60 | 5.6s |  |
| 358 | `edittext_autosize_lazy_bounds_events` | 65 | 5.6s |  |
| 359 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.5s |  |
| 360 | `edittext_autosize_lazy_bounds_props` | 490 | 7.0s |  |
| 361 | `edittext_autosize_lazy_bounds_visual` | 0 | 5.7s |  |
| 362 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.8s |  |
| 363 | `edittext_bottom_scroll_v_basic` | 210 | 5.4s |  |
| 364 | `edittext_bounds_scale` | 24 | 19.3s |  |
| 365 | `edittext_bullet` | 30 | 5.4s |  |
| 366 | `edittext_default_format` | 221 | 5.7s |  |
| 367 | `edittext_default_format_empty` | 136 | 5.7s |  |
| 368 | `edittext_empty_text_format` | 7 | 5.8s |  |
| 369 | `edittext_focus_selection` | 5 | 5.6s |  |
| 370 | `edittext_font_size` | 45 | 5.7s |  |
| 371 | `edittext_format_empty_font` | 8 | 5.3s |  |
| 372 | `edittext_get_char_index_at_point` | 4 | 20.4s |  |
| 373 | `edittext_get_line_index_at_point` | 2 | 18.6s |  |
| 374 | `edittext_get_line_index_of_char` | 76 | 5.9s |  |
| 375 | `edittext_getcharboundaries` | 172 | 5.7s |  |
| 376 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.5s |  |
| 377 | `edittext_getcharboundaries_scroll` | 85 | 23.4s |  |
| 378 | `edittext_getlinemetrics` | 146 | 6.3s |  |
| 379 | `edittext_html` | 3101 | 6.4s |  |
| 380 | `edittext_html_condensewhite` | 487 | 6.1s |  |
| 381 | `edittext_html_entity` | 4 | 6.3s |  |
| 382 | `edittext_html_font_size_swf12` | 267 | 6.0s |  |
| 383 | `edittext_html_font_size_swf13` | 273 | 5.6s |  |
| 384 | `edittext_html_roundtrip` | 17 | 5.9s |  |
| 385 | `edittext_ime_focus_lost` | 9 | 22.8s |  |
| 386 | `edittext_input_control` | 12 | 6.0s |  |
| 387 | `edittext_leading` | 9 | 6.0s |  |
| 388 | `edittext_letter_spacing` | 15 | 5.8s |  |
| 389 | `edittext_line_methods` | 294 | 6.9s |  |
| 390 | `edittext_line_metrics` | 11 | 23.6s |  |
| 391 | `edittext_margins` | 25 | 5.9s |  |
| 392 | `edittext_max_scroll_h_basic` | 475 | 6.1s |  |
| 393 | `edittext_max_scroll_v_basic` | 1000 | 5.9s |  |
| 394 | `edittext_mouse_selection` | 363 | 23.6s |  |
| 395 | `edittext_mousedown` | 3 | 6.2s |  |
| 396 | `edittext_mouseenabled` | 26 | 5.9s |  |
| 397 | `edittext_newline_character` | 22 | 5.8s |  |
| 398 | `edittext_newline_stripping` | 64 | 11.8s |  |
| 399 | `edittext_newlines` | 30 | 6.0s |  |
| 400 | `edittext_paragraph_methods` | 257 | 5.9s |  |
| 401 | `edittext_paste_events` | 8 | 6.1s |  |
| 402 | `edittext_paste_maxchars` | 4 | 5.8s |  |
| 403 | `edittext_paste_restrict` | 16 | 5.6s |  |
| 404 | `edittext_restrict` | 191 | 5.8s |  |
| 405 | `edittext_restrict_events` | 22 | 5.8s |  |
| 406 | `edittext_scroll_event` | 37 | 6.0s |  |
| 407 | `edittext_scrollh` | 10 | 5.8s |  |
| 408 | `edittext_selected_text` | 9 | 5.7s |  |
| 409 | `edittext_set_html_same` | 17 | 5.7s |  |
| 410 | `edittext_set_text_vs_html` | 9 | 5.7s |  |
| 411 | `edittext_stylesheet` | 536 | 6.1s |  |
| 412 | `edittext_stylesheet_custom_tag` | 76 | 5.9s |  |
| 413 | `edittext_stylesheet_display` | 272 | 5.9s |  |
| 414 | `edittext_tag_indent` | 49 | 22.8s |  |
| 415 | `edittext_underline` | 40 | 6.0s |  |
| 416 | `edittext_width_height` | 103 | 6.2s |  |
| 417 | `edittext_wordwrap_word` | 150 | 6.0s |  |
| 418 | `edittext_wrap_breaks` | 2375 | 6.4s |  |
| 419 | `element_format_clone` | 44 | 21.3s |  |
| 420 | `element_format_constructor_order` | 64 | 5.8s |  |
| 421 | `element_format_properties` | 235 | 6.6s |  |
| 422 | `empty_bounds` | 1 | 5.5s |  |
| 423 | `encode_uri_surrogate_pair_invalid` | 8 | 5.5s |  |
| 424 | `encode_uri_surrogate_pair_swf11` | 15 | 5.2s |  |
| 425 | `equals` | 512 | 8.1s |  |
| 426 | `error_geterrormessage` | 779 | 5.6s |  |
| 427 | `error_prototype` | 15 | 5.6s |  |
| 428 | `error_stack_trace` | 45 | 5.6s |  |
| 429 | `error_stack_trace_debug_swf17` | 0 | 21.4s |  |
| 430 | `error_stack_trace_debug_swf18` | 0 | 5.3s |  |
| 431 | `error_stack_trace_edge_cases` | 6 | 5.5s |  |
| 432 | `error_stack_trace_release_swf17` | 0 | 1.6s |  |
| 433 | `error_stack_trace_release_swf18` | 0 | 5.3s |  |
| 434 | `error_throwerror` | 103 | 5.6s |  |
| 435 | `error_tostring` | 29 | 5.5s |  |
| 436 | `error_tostring_more` | 86 | 5.6s |  |
| 437 | `es3_inheritance` | 31 | 5.6s |  |
| 438 | `es4_inheritance` | 30 | 5.6s |  |
| 439 | `es4_interfaces` | 30 | 5.6s |  |
| 440 | `es4_method_binding` | 8 | 5.6s |  |
| 441 | `es4_oop_prototypes` | 14 | 5.7s |  |
| 442 | `es4_protected_inheritance` | 6 | 5.5s |  |
| 443 | `escape` | 71 | 5.6s |  |
| 444 | `escape_multi_byte` | 45 | 5.8s |  |
| 445 | `event_bubbles` | 2 | 5.5s |  |
| 446 | `event_cancelable` | 2 | 5.5s |  |
| 447 | `event_clone` | 20 | 5.6s |  |
| 448 | `event_clone_error_redispatch` | 3 | 5.6s |  |
| 449 | `event_clone_on_redispatch` | 10 | 5.6s |  |
| 450 | `event_formattostring` | 31 | 5.7s |  |
| 451 | `event_isdefaultprevented` | 12 | 5.5s |  |
| 452 | `event_target_getter` | 5 | 1.6s |  |
| 453 | `event_target_set` | 9 | 5.5s |  |
| 454 | `event_type` | 1 | 5.5s |  |
| 455 | `event_valueof_tostring` | 18 | 5.6s |  |
| 456 | `eventdispatcher_dispatchevent` | 12 | 5.6s |  |
| 457 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.6s |  |
| 458 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.6s |  |
| 459 | `eventdispatcher_dispatchevent_indirect` | 9 | 21.6s |  |
| 460 | `eventdispatcher_dispatchevent_this` | 5 | 5.6s |  |
| 461 | `eventdispatcher_haseventlistener` | 25 | 5.7s |  |
| 462 | `eventdispatcher_interface_invoke` | 1 | 5.5s |  |
| 463 | `eventdispatcher_tostring` | 10 | 5.6s |  |
| 464 | `eventdispatcher_willtrigger` | 25 | 5.5s |  |
| 465 | `external_interface` | 105 | 5.8s |  |
| 466 | `falsiness` | 30 | 5.6s |  |
| 467 | `fast_index_access` | 12 | 5.7s |  |
| 468 | `filefilter_properties` | 4 | 5.6s |  |
| 469 | `filereference_browse_cancel` | 3 | 5.5s |  |
| 470 | `filereference_load` | 31 | 5.7s |  |
| 471 | `filereference_save` | 16 | 5.6s |  |
| 472 | `filereference_save_and_browse` | 42 | 5.7s |  |
| 473 | `filereference_save_and_load` | 22 | 5.6s |  |
| 474 | `filereference_uninitialized` | 8 | 5.5s |  |
| 475 | `filereferencelist_browse_cancel` | 6 | 5.5s |  |
| 476 | `filereferencelist_browse_select` | 7 | 5.6s |  |
| 477 | `filter_rewind` | 8 | 21.7s |  |
| 478 | `filters_array_holes` | 25 | 5.7s |  |
| 479 | `finddef` | 3 | 5.5s |  |
| 480 | `findprop_global_prototype` | 6 | 5.6s |  |
| 481 | `flash_media_video_constructor` | 156 | 6.3s |  |
| 482 | `flash_media_video_rotation_probe` | 27 | 5.6s |  |
| 483 | `flash_media_video_setter` | 40 | 5.9s |  |
| 484 | `flash_trace` | 17 | 5.6s |  |
| 485 | `flash_ui_mouse_cursor` | 35 | 5.9s |  |
| 486 | `flash_xml` | 29 | 5.7s |  |
| 487 | `flash_xml_cloneNode` | 22 | 5.6s |  |
| 488 | `flash_xml_namespace` | 109 | 5.6s |  |
| 489 | `flash_xml_removeNode` | 60 | 5.6s |  |
| 490 | `focus_events_code` | 161 | 22.0s |  |
| 491 | `focus_events_key_basic` | 132 | 22.0s |  |
| 492 | `focus_events_key_navigation` | 53 | 21.7s |  |
| 493 | `focus_events_key_same_object` | 26 | 5.6s |  |
| 494 | `focus_events_mixed_key_mouse` | 100 | 21.4s |  |
| 495 | `focus_events_mouse_basic` | 260 | 21.5s |  |
| 496 | `focus_events_mouse_focusable` | 112 | 21.8s |  |
| 497 | `focus_events_mouse_same_object` | 40 | 5.6s |  |
| 498 | `focus_remove` | 20 | 21.6s |  |
| 499 | `focus_root_movie` | 4 | 21.6s |  |
| 500 | `focus_stage` | 1 | 5.5s |  |
| 501 | `focusrect` | 18 | 6.1s |  |
| 502 | `focusrect_focuslost` | 9 | 22.5s |  |
| 503 | `focusrect_property` | 110 | 21.9s |  |
| 504 | `font_description_clone` | 14 | 5.6s |  |
| 505 | `font_embedded` | 24 | 6.0s |  |
| 506 | `font_enumeratefonts` | 41 | 6.2s |  |
| 507 | `font_enumeratefonts_filter` | 4 | 6.2s |  |
| 508 | `font_enumeratefonts_order` | 9 | 6.7s |  |
| 509 | `font_hasglyphs` | 40 | 6.1s |  |
| 510 | `font_registerfont` | 129 | 6.5s |  |
| 511 | `framelabel_constr` | 5 | 5.8s |  |
| 512 | `function_call` | 12 | 1.7s |  |
| 513 | `function_call_arguments` | 46 | 5.9s |  |
| 514 | `function_call_arguments_enumerate` | 5 | 5.6s |  |
| 515 | `function_call_coercion` | 108 | 6.0s |  |
| 516 | `function_call_default` | 6 | 5.7s |  |
| 517 | `function_call_rest` | 22 | 5.7s |  |
| 518 | `function_call_types` | 3 | 5.7s |  |
| 519 | `function_call_via_apply` | 11 | 5.7s |  |
| 520 | `function_call_via_call` | 3 | 5.7s |  |
| 521 | `function_display_anonymous` | 7 | 1.7s |  |
| 522 | `function_length` | 6 | 5.7s |  |
| 523 | `function_object` | 2 | 5.7s |  |
| 524 | `function_proto` | 5 | 5.7s |  |
| 525 | `function_proto_created` | 61 | 5.8s |  |
| 526 | `function_to_locale_string` | 4 | 5.7s |  |
| 527 | `function_to_string` | 4 | 5.6s |  |
| 528 | `function_type` | 6 | 5.8s |  |
| 529 | `function_unbound_this` | 51 | 5.8s |  |
| 530 | `function_value_of` | 4 | 5.6s |  |
| 531 | `game_input` | 4 | 5.7s |  |
| 532 | `generate_random_bytes` | 3 | 5.7s |  |
| 533 | `geom_transform` | 74 | 22.6s |  |
| 534 | `get_definition_by_name` | 11 | 5.7s |  |
| 535 | `get_qualified_class_name` | 20 | 5.7s |  |
| 536 | `get_qualified_super_class_name` | 18 | 5.7s |  |
| 537 | `get_slot_edge_cases` | 1 | 5.7s |  |
| 538 | `get_timer` | 2 | 1.7s |  |
| 539 | `getglobalslot` | 1 | 5.6s |  |
| 540 | `getouterscope` | 8 | 5.6s |  |
| 541 | `getouterscope_two_classobjects` | 13 | 5.6s |  |
| 542 | `getter_different_namespace_setter` | 2 | 5.4s |  |
| 543 | `glow_filter` | 127 | 5.8s |  |
| 544 | `goto_button_nested_framescript` | 28 | 22.3s |  |
| 545 | `goto_framescript_queued/swf10` | 59 | 22.4s |  |
| 546 | `goto_framescript_queued/swf9` | 52 | 0.8s |  |
| 547 | `goto_framescript_queued_same_frame` | 4 | 29.7s |  |
| 548 | `goto_in_constructframe` | 12 | 30.1s |  |
| 549 | `goto_in_scene_last_frame` | 2 | 29.6s |  |
| 550 | `goto_methods` | 56 | 8.5s |  |
| 551 | `goto_methods_swfver10` | 8 | 8.0s |  |
| 552 | `goto_nested_construct_sibling` | 18 | 8.7s |  |
| 553 | `goto_nested_framescript` | 9 | 8.3s |  |
| 554 | `goto_on_orphan` | 15 | 29.2s |  |
| 555 | `goto_queued_invalid/swf10` | 34 | 30.6s |  |
| 556 | `goto_queued_invalid/swf11` | 43 | 0.8s |  |
| 557 | `goto_queued_invalid/swf9` | 32 | 0.7s |  |
| 558 | `gradient_bevel_filter` | 206 | 8.3s |  |
| 559 | `gradient_glow_filter` | 206 | 8.1s |  |
| 560 | `graphic_linkage` | 9 | 8.4s |  |
| 561 | `graphics_bad_direct_commands` | 5 | 8.8s |  |
| 562 | `graphics_bitmap_fill` | 0 | 32.3s |  |
| 563 | `graphics_bitmaps` | 0 | 8.4s |  |
| 564 | `graphics_direct_commands` | 0 | 8.3s |  |
| 565 | `graphics_draw_triangles` | 98 | 29.8s |  |
| 566 | `graphics_gradients` | 0 | 8.0s |  |
| 567 | `graphics_gradients_nulls` | 0 | 7.9s |  |
| 568 | `graphics_path` | 56 | 7.9s |  |
| 569 | `graphics_round_rects` | 0 | 7.8s |  |
| 570 | `graphics_simple_shapes` | 0 | 8.0s |  |
| 571 | `greaterequals` | 512 | 12.4s |  |
| 572 | `greaterthan` | 512 | 12.4s |  |
| 573 | `has_own_property` | 102 | 8.5s |  |
| 574 | `hasownproperty_namespaces` | 2 | 7.9s |  |
| 575 | `hello_world` | 1 | 7.7s |  |
| 576 | `hittest_morph` | 30 | 8.1s |  |
| 577 | `id3_info` | 8 | 28.8s |  |
| 578 | `if_eq` | 10 | 8.1s |  |
| 579 | `if_gt` | 1 | 8.1s |  |
| 580 | `if_gte` | 10 | 2.8s |  |
| 581 | `if_lt` | 1 | 0.7s |  |
| 582 | `if_lte` | 10 | 7.9s |  |
| 583 | `if_ne` | 7 | 2.8s |  |
| 584 | `if_stricteq` | 6 | 8.2s |  |
| 585 | `if_strictne` | 11 | 8.7s |  |
| 586 | `ime_linux_dead_keys` | 10 | 32.1s |  |
| 587 | `in` | 102 | 9.2s |  |
| 588 | `inclocal` | 46 | 8.5s |  |
| 589 | `inclocal_i` | 46 | 8.6s |  |
| 590 | `increment` | 46 | 8.5s |  |
| 591 | `increment_i` | 46 | 8.5s |  |
| 592 | `indexing_delete` | 75 | 8.5s |  |
| 593 | `indexof_xml` | 10 | 8.6s |  |
| 594 | `init_callee_cached` | 24 | 8.5s |  |
| 595 | `instanceof` | 58 | 9.0s |  |
| 596 | `instantiate_root_character` | 4 | 8.8s |  |
| 597 | `instantiation_on_enter_frame` | 7 | 32.2s |  |
| 598 | `instantiation_on_enterframe_gotoandstop` | 8 | 8.5s |  |
| 599 | `int_constr` | 92 | 8.7s |  |
| 600 | `int_edge_cases` | 19 | 8.6s |  |
| 601 | `int_instanceof` | 3 | 8.4s |  |
| 602 | `int_tofixed` | 1215 | 8.3s |  |
| 603 | `int_toprecision` | 1125 | 8.6s |  |
| 604 | `int_tostring` | 3375 | 8.7s |  |
| 605 | `interactiveobject_enabled` | 25 | 8.4s |  |
| 606 | `interface_namespaces` | 78 | 8.7s |  |
| 607 | `invalid_utf8` | 12 | 8.7s |  |
| 608 | `is_finite` | 46 | 8.6s |  |
| 609 | `is_nan` | 46 | 8.3s |  |
| 610 | `is_prototype_of` | 12 | 8.5s |  |
| 611 | `issue_10221` | 2 | 8.5s |  |
| 612 | `issue_13780` | 12 | 8.4s |  |
| 613 | `issue_14901` | 1 | 8.3s |  |
| 614 | `issue_17675_edittext_paste_maxchars` | 1 | 8.4s |  |
| 615 | `issue_5292` | 5 | 8.4s |  |
| 616 | `issue_8630` | 2 | 8.5s |  |
| 617 | `issue_8630_placeremoveplace` | 15 | 8.7s |  |
| 618 | `issue_8630_placeremoveplace_scriptremove` | 16 | 8.4s |  |
| 619 | `issue_8630_scriptremove` | 11 | 8.5s |  |
| 620 | `istype` | 24 | 3.0s |  |
| 621 | `istypelate` | 58 | 8.9s |  |
| 622 | `istypelate_coerce` | 198 | 10.1s |  |
| 623 | `jpeg_loader_context` | 6 | 8.5s |  |
| 624 | `json_errors` | 9 | 32.0s |  |
| 625 | `json_parse` | 21 | 8.5s |  |
| 626 | `json_parse_errors` | 84 | 8.4s |  |
| 627 | `json_stringify` | 12 | 24.6s |  |
| 628 | `json_stringify_function` | 12 | 5.5s |  |
| 629 | `json_stringify_order` | 1 | 5.4s |  |
| 630 | `json_version_gated` | 1 | 5.4s |  |
| 631 | `key_input_80percent` | 1812 | 21.1s |  |
| 632 | `key_input_location` | 126 | 5.5s |  |
| 633 | `key_input_numpad` | 384 | 5.5s |  |
| 634 | `large_preload_from_bytes` | 51 | 8.3s |  |
| 635 | `large_preload_from_url` | 27 | 7.2s |  |
| 636 | `large_preload_image_from_bytes` | 25 | 5.9s |  |
| 637 | `lazyinit` | 17 | 5.5s |  |
| 638 | `lessequals` | 512 | 8.0s |  |
| 639 | `lessthan` | 512 | 8.0s |  |
| 640 | `loader_bitmap_transparency` | 14 | 5.6s |  |
| 641 | `loader_bytes_unknown_content` | 14 | 5.6s |  |
| 642 | `loader_child_getdefinition` | 5 | 5.7s |  |
| 643 | `loader_duplicate_class` | 48 | 7.0s |  |
| 644 | `loader_duplicate_coerce` | 3 | 5.7s |  |
| 645 | `loader_duplicate_coerce_new_domain` | 4 | 5.6s |  |
| 646 | `loader_error_in_root_ctor` | 4 | 5.6s |  |
| 647 | `loader_events` | 92 | 5.9s |  |
| 648 | `loader_image` | 8 | 5.6s |  |
| 649 | `loader_jpegxr` | 2 | 21.4s |  |
| 650 | `loader_jpegxr_alpha` | 1 | 21.2s |  |
| 651 | `loader_loadbytes_events` | 30 | 5.9s |  |
| 652 | `loader_loadbytes_invalid_png` | 4 | 5.6s |  |
| 653 | `loader_loadbytes_url` | 12 | 5.7s |  |
| 654 | `loader_loaderurl` | 6 | 5.8s |  |
| 655 | `loader_method` | 85 | 5.5s |  |
| 656 | `loader_noninteractive_try_click_root` | 5 | 21.5s |  |
| 657 | `loader_reuse` | 38 | 5.7s |  |
| 658 | `loader_try_click_root` | 16 | 5.7s |  |
| 659 | `loader_unknown_content` | 24 | 5.7s |  |
| 660 | `loader_unloadandstop_subclass` | 1 | 5.5s |  |
| 661 | `loader_visibility_interactive` | 1 | 5.5s |  |
| 662 | `loaderinfo_child_progress` | 9 | 5.9s |  |
| 663 | `loaderinfo_events` | 7 | 5.5s |  |
| 664 | `loaderinfo_loadurl` | 12 | 5.5s |  |
| 665 | `loaderinfo_more` | 6 | 5.6s |  |
| 666 | `loaderinfo_properties` | 18 | 21.3s |  |
| 667 | `loaderinfo_properties_not_loaded` | 23 | 5.6s |  |
| 668 | `loaderinfo_quine` | 1005 | 24.6s |  |
| 669 | `loaderinfo_root` | 10 | 5.7s |  |
| 670 | `loaderinfo_root_allows` | 2 | 5.5s |  |
| 671 | `localconnection` | 890 | 7.2s |  |
| 672 | `localconnection_send` | 4 | 5.6s |  |
| 673 | `lshift` | 1058 | 12.6s |  |
| 674 | `mask_reapply` | 1 | 21.2s |  |
| 675 | `math` | 497 | 5.8s |  |
| 676 | `matrix` | 338 | 13.4s |  |
| 677 | `matrix3d` | 57 | 21.9s |  |
| 678 | `matrix3d_append` | 16 | 5.6s |  |
| 679 | `matrix3d_append_prepend_scale` | 86 | 5.6s |  |
| 680 | `matrix3d_append_prepend_translation` | 42 | 5.6s |  |
| 681 | `matrix3d_append_rotation` | 23 | 5.6s |  |
| 682 | `matrix3d_compose` | 34 | 5.7s |  |
| 683 | `matrix3d_constructor_clone` | 15 | 5.5s |  |
| 684 | `matrix3d_copy_column` | 83 | 5.7s |  |
| 685 | `matrix3d_copy_from` | 19 | 5.5s |  |
| 686 | `matrix3d_copy_raw_data_from` | 55 | 1.8s |  |
| 687 | `matrix3d_copy_raw_data_to` | 38 | 5.7s |  |
| 688 | `matrix3d_copy_row` | 83 | 5.4s |  |
| 689 | `matrix3d_copy_to_matrix3d` | 19 | 5.5s |  |
| 690 | `matrix3d_determinant` | 182 | 5.6s |  |
| 691 | `matrix3d_interpolate` | 21 | 5.7s |  |
| 692 | `matrix3d_invert` | 18 | 5.5s |  |
| 693 | `matrix3d_position` | 19 | 5.6s |  |
| 694 | `matrix3d_precision` | 28 | 5.7s |  |
| 695 | `matrix3d_prepend` | 16 | 5.4s |  |
| 696 | `matrix3d_raw_data` | 33 | 5.6s |  |
| 697 | `matrix3d_transform_vector` | 52 | 5.8s |  |
| 698 | `matrix3d_transpose` | 5 | 5.5s |  |
| 699 | `method_association` | 5 | 5.5s |  |
| 700 | `method_without_body` | 3 | 21.0s |  |
| 701 | `missing_external_interface` | 10 | 5.5s |  |
| 702 | `modulo` | 1058 | 12.5s |  |
| 703 | `morph_shape` | 2 | 21.3s |  |
| 704 | `mouse_children` | 192 | 21.4s |  |
| 705 | `mouse_click_events` | 90 | 21.2s |  |
| 706 | `mouse_double_click_events` | 188 | 5.6s |  |
| 707 | `mouse_empty_parent` | 4 | 5.5s |  |
| 708 | `mouse_over_while_dragging` | 3 | 5.7s |  |
| 709 | `mouse_pick_avm1_root` | 2 | 25.7s |  |
| 710 | `mouse_pick_button_mode` | 2 | 22.3s |  |
| 711 | `mouse_pick_dobj_mask` | 4 | 5.8s |  |
| 712 | `mouse_pick_loader_avm1` | 42 | 6.2s |  |
| 713 | `mouse_pick_masking` | 7 | 22.2s |  |
| 714 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 22.2s |  |
| 715 | `mouse_pick_non_interactive_dobj_mask` | 3 | 5.7s |  |
| 716 | `mouse_pick_scroll_rect` | 27 | 22.4s |  |
| 717 | `mouse_pick_scroll_rect_button` | 5 | 5.8s |  |
| 718 | `mouse_pick_scroll_rect_loader` | 5 | 6.1s |  |
| 719 | `mouse_pick_text` | 8 | 5.8s |  |
| 720 | `mouse_sibling` | 8 | 5.7s |  |
| 721 | `mouse_wheel_events` | 36 | 22.8s |  |
| 722 | `mouseevent_constr` | 66 | 5.8s |  |
| 723 | `mouseevent_stagexy` | 35 | 5.7s |  |
| 724 | `mouseevent_valueof_tostring` | 28 | 5.7s |  |
| 725 | `movieclip_addframescript` | 3 | 21.9s |  |
| 726 | `movieclip_addframescript_error` | 9 | 5.6s |  |
| 727 | `movieclip_child_property` | 16 | 5.7s |  |
| 728 | `movieclip_constr` | 21 | 5.7s |  |
| 729 | `movieclip_currentlabels` | 17 | 21.7s |  |
| 730 | `movieclip_currentlabels_dupes1` | 46 | 21.9s |  |
| 731 | `movieclip_currentlabels_dupes2` | 30 | 5.7s |  |
| 732 | `movieclip_currentlabels_dupes3` | 67 | 5.7s |  |
| 733 | `movieclip_currentscene` | 12 | 21.8s |  |
| 734 | `movieclip_dispatchevent` | 430 | 5.8s |  |
| 735 | `movieclip_dispatchevent_cancel` | 102 | 5.8s |  |
| 736 | `movieclip_dispatchevent_handlerorder` | 251 | 5.8s |  |
| 737 | `movieclip_dispatchevent_selfadd` | 80 | 5.8s |  |
| 738 | `movieclip_dispatchevent_target` | 899 | 5.8s |  |
| 739 | `movieclip_displayevents` | 96 | 22.3s |  |
| 740 | `movieclip_displayevents_clickgoto` | 676 | 22.4s |  |
| 741 | `movieclip_displayevents_clickgoto2` | 2001 | 6.3s |  |
| 742 | `movieclip_displayevents_clickplay` | 575 | 6.0s |  |
| 743 | `movieclip_displayevents_clicksymbol` | 562 | 6.0s |  |
| 744 | `movieclip_displayevents_constructframegoto` | 140 | 6.2s |  |
| 745 | `movieclip_displayevents_constructframeplay` | 50 | 6.1s |  |
| 746 | `movieclip_displayevents_constructframesymbol` | 144 | 6.0s |  |
| 747 | `movieclip_displayevents_dblhandler` | 21 | 5.7s |  |
| 748 | `movieclip_displayevents_enterframegoto` | 149 | 6.0s |  |
| 749 | `movieclip_displayevents_enterframeplay` | 48 | 5.9s |  |
| 750 | `movieclip_displayevents_enterframesymbol` | 149 | 22.4s |  |
| 751 | `movieclip_displayevents_exitframegoto` | 106 | 5.9s |  |
| 752 | `movieclip_displayevents_exitframeplay` | 44 | 5.9s |  |
| 753 | `movieclip_displayevents_exitframesymbol` | 135 | 33.3s |  |
| 754 | `movieclip_displayevents_looping` | 63 | 29.1s |  |
| 755 | `movieclip_displayevents_stopped` | 113 | 29.7s |  |
| 756 | `movieclip_displayevents_swap` | 96 | 8.2s |  |
| 757 | `movieclip_displayevents_timeline` | 128 | 29.2s |  |
| 758 | `movieclip_drawrect` | 54 | 28.9s |  |
| 759 | `movieclip_frameconstruct_skipped` | 9 | 8.3s |  |
| 760 | `movieclip_goto_during_frame_script` | 15 | 28.7s |  |
| 761 | `movieclip_goto_overwrite` | 14 | 28.4s |  |
| 762 | `movieclip_goto_scene_last_frame_int` | 1 | 29.0s |  |
| 763 | `movieclip_goto_scene_last_frame_label` | 1 | 7.7s |  |
| 764 | `movieclip_gotoandplay` | 15 | 28.5s |  |
| 765 | `movieclip_gotoandstop` | 13 | 7.9s |  |
| 766 | `movieclip_gotoandstop_children` | 4 | 7.9s |  |
| 767 | `movieclip_gotoandstop_framescripts1` | 4 | 7.8s |  |
| 768 | `movieclip_gotoandstop_framescripts2` | 4 | 2.6s |  |
| 769 | `movieclip_gotoandstop_framescripts_self` | 7 | 28.8s |  |
| 770 | `movieclip_gotoandstop_queueing` | 12 | 8.1s |  |
| 771 | `movieclip_hittest` | 67 | 8.2s |  |
| 772 | `movieclip_next_frame` | 2 | 8.0s |  |
| 773 | `movieclip_next_scene` | 6 | 8.1s |  |
| 774 | `movieclip_play` | 3 | 8.0s |  |
| 775 | `movieclip_prev_frame` | 3 | 7.7s |  |
| 776 | `movieclip_prev_scene` | 7 | 8.0s |  |
| 777 | `movieclip_properties` | 79 | 29.1s |  |
| 778 | `movieclip_queued_noop_goto_swf10` | 9 | 7.9s |  |
| 779 | `movieclip_queued_noop_goto_swf9` | 7 | 0.7s |  |
| 780 | `movieclip_scenes` | 11 | 7.7s |  |
| 781 | `movieclip_soundtransform` | 831 | 31.5s |  |
| 782 | `movieclip_stop` | 1 | 8.0s |  |
| 783 | `movieclip_super_is_symbol` | 20 | 8.6s |  |
| 784 | `movieclip_symbol_constr` | 8 | 8.2s |  |
| 785 | `movieclip_text_mousedown` | 1 | 8.1s |  |
| 786 | `movieclip_willtrigger` | 5 | 8.2s |  |
| 787 | `multiply` | 1058 | 20.1s |  |
| 788 | `namespace_constr` | 253 | 8.6s |  |
| 789 | `namespace_constr_args` | 1 | 8.0s |  |
| 790 | `namespace_enumeration_order` | 7 | 29.5s |  |
| 791 | `nan_scale` | 9 | 8.1s |  |
| 792 | `native_menu_basic` | 19 | 10.7s |  |
| 793 | `navigateToURL_target_normalize` | 107 | 32.0s |  |
| 794 | `negate` | 30 | 8.0s |  |
| 795 | `negative_volume_panned` | 0 | 8.3s |  |
| 796 | `nested_iteration` | 11 | 8.0s |  |
| 797 | `net_getClassByAlias` | 3 | 25.2s |  |
| 798 | `net_navigateToURL` | 57 | 23.8s |  |
| 799 | `net_stream_play_options` | 6 | 5.6s |  |
| 800 | `netconnection_call_with_responder` | 6 | 22.0s |  |
| 801 | `netconnection_close` | 55 | 21.9s |  |
| 802 | `netconnection_properties` | 78 | 5.7s |  |
| 803 | `netconnection_send_remote` | 50 | 5.9s |  |
| 804 | `netconnection_serialize_arrays` | 6 | 5.7s |  |
| 805 | `netfilterevent` | 10 | 5.7s |  |
| 806 | `netstream_client` | 10 | 5.8s |  |
| 807 | `netstream_connect` | 7 | 5.7s |  |
| 808 | `netstream_flv_date` | 4 | 5.7s |  |
| 809 | `newactivation_in_script_init` | 3 | 5.5s |  |
| 810 | `newclass_mismatched` | 4 | 5.6s |  |
| 811 | `newclass_twice` | 3 | 5.5s |  |
| 812 | `nonconflicting_declarations` | 0 | 5.7s |  |
| 813 | `null_void_types` | 8 | 5.7s |  |
| 814 | `number_autoconv` | 21 | 5.7s |  |
| 815 | `number_autoconv_amf` | 132 | 5.7s |  |
| 816 | `number_autoconv_array_sort_32bit` | 1 | 5.6s |  |
| 817 | `number_constr` | 58 | 5.7s |  |
| 818 | `number_convert_edge_cases` | 180 | 21.9s |  |
| 819 | `number_toexponential` | 378 | 5.7s |  |
| 820 | `number_toexponential2` | 35 | 5.6s |  |
| 821 | `number_tofixed` | 378 | 5.6s |  |
| 822 | `number_toprecision` | 350 | 5.7s |  |
| 823 | `obfuscated_class_names` | 3 | 5.6s |  |
| 824 | `object_enumeration` | 10 | 5.6s |  |
| 825 | `object_prototype` | 4 | 5.6s |  |
| 826 | `object_to_locale_string` | 2 | 5.6s |  |
| 827 | `object_to_string` | 2 | 5.5s |  |
| 828 | `object_value_of` | 2 | 1.5s |  |
| 829 | `op_coerce` | 54 | 5.7s |  |
| 830 | `op_coerce_x` | 54 | 5.6s |  |
| 831 | `op_escxattr` | 2 | 5.6s |  |
| 832 | `op_escxelem` | 2 | 5.6s |  |
| 833 | `op_lookupswitch` | 4 | 5.6s |  |
| 834 | `optimize_coerce` | 1 | 5.5s |  |
| 835 | `orphan_movie_complex` | 80 | 25.1s |  |
| 836 | `orphan_movie_reorder` | 111 | 21.8s |  |
| 837 | `orphan_removeobject` | 636 | 22.1s |  |
| 838 | `package_namespace` | 7 | 21.4s |  |
| 839 | `param_default_value_has_zero_cpool_index` | 1 | 5.5s |  |
| 840 | `parent_early_access_child` | 16 | 21.5s |  |
| 841 | `parse_float` | 81 | 5.7s |  |
| 842 | `parse_float_swf10` | 81 | 5.4s |  |
| 843 | `parse_int` | 135 | 5.9s |  |
| 844 | `perspective_projection` | 1443 | 21.5s |  |
| 845 | `perspective_projection_basic` | 40 | 5.5s |  |
| 846 | `pixelbender_ceil` | 77 | 5.6s |  |
| 847 | `pixelbender_conditional` | 138 | 5.8s |  |
| 848 | `pixelbender_conversions` | 270 | 5.8s |  |
| 849 | `pixelbender_dithering` | 8 | 24.9s |  |
| 850 | `pixelbender_div` | 36 | 5.6s |  |
| 851 | `pixelbender_effect_BlurredFocus` | 0 | 27.7s |  |
| 852 | `pixelbender_effect_glassDisplace` | 0 | 10.0s |  |
| 853 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 24.2s |  |
| 854 | `pixelbender_effect_smudge` | 0 | 8.1s |  |
| 855 | `pixelbender_effect_tintype` | 0 | 7.5s |  |
| 856 | `pixelbender_effect_twirl` | 0 | 8.6s |  |
| 857 | `pixelbender_eof` | 7 | 5.5s |  |
| 858 | `pixelbender_images` | 0 | 7.3s |  |
| 859 | `pixelbender_input` | 103 | 21.9s |  |
| 860 | `pixelbender_logicalnot` | 20 | 5.5s |  |
| 861 | `pixelbender_malformed_data` | 190 | 21.9s |  |
| 862 | `pixelbender_multiple_out_params` | 1 | 5.5s |  |
| 863 | `pixelbender_no_out_param` | 6 | 5.5s |  |
| 864 | `pixelbender_outputs` | 13 | 5.7s |  |
| 865 | `pixelbender_padding_bytes` | 22 | 5.6s |  |
| 866 | `pixelbender_param_qualifier` | 512 | 5.6s |  |
| 867 | `pixelbender_parameters` | 1563 | 5.8s |  |
| 868 | `pixelbender_parameters_bool` | 240 | 5.7s |  |
| 869 | `pixelbender_parameters_int_vs_bool` | 54 | 5.6s |  |
| 870 | `pixelbender_parse_errors` | 6 | 5.5s |  |
| 871 | `pixelbender_rsqrt` | 24 | 5.6s |  |
| 872 | `pixelbender_select_kinds` | 8 | 5.7s |  |
| 873 | `pixelbender_shaderdata` | 49 | 5.6s |  |
| 874 | `pixelbender_shaderdata_setter` | 99 | 5.8s |  |
| 875 | `pixelbender_sign` | 60 | 5.7s |  |
| 876 | `pixelbender_vector_output` | 11 | 5.7s |  |
| 877 | `place_and_lookup/swf10` | 33 | 5.5s |  |
| 878 | `place_and_lookup/swf9` | 33 | 33.1s |  |
| 879 | `place_multiple` | 17 | 28.6s |  |
| 880 | `place_object_replace` | 9 | 28.8s |  |
| 881 | `place_object_replace_2` | 24 | 28.6s |  |
| 882 | `place_object_same_depth_frame` | 1 | 8.0s |  |
| 883 | `point` | 132 | 8.6s |  |
| 884 | `primitive_edge_cases` | 1 | 7.8s |  |
| 885 | `primitive_keys` | 54 | 7.8s |  |
| 886 | `primitive_toString` | 277 | 8.0s |  |
| 887 | `primitive_valueOf` | 285 | 7.7s |  |
| 888 | `print_job_options` | 3 | 7.8s |  |
| 889 | `property_is_enumerable` | 114 | 9.1s |  |
| 890 | `property_is_enumerable_reset` | 23 | 7.8s |  |
| 891 | `property_priority` | 22 | 8.3s |  |
| 892 | `property_priority_chained` | 4 | 7.8s |  |
| 893 | `property_priority_definition_names_order` | 2 | 8.1s |  |
| 894 | `property_priority_three_level` | 6 | 7.9s |  |
| 895 | `propertyisenumerable_namespaces` | 6 | 7.8s |  |
| 896 | `prototype_set_null` | 7 | 7.8s |  |
| 897 | `proxy_callproperty` | 24 | 7.8s |  |
| 898 | `proxy_deleteproperty` | 64 | 8.0s |  |
| 899 | `proxy_enumeration` | 34 | 7.8s |  |
| 900 | `proxy_getproperty` | 77 | 7.9s |  |
| 901 | `proxy_hasownproperty` | 8 | 7.8s |  |
| 902 | `proxy_hasproperty` | 32 | 8.0s |  |
| 903 | `proxy_not_overridden` | 54 | 7.9s |  |
| 904 | `proxy_serialize` | 9 | 7.9s |  |
| 905 | `proxy_setproperty` | 42 | 7.9s |  |
| 906 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.7s |  |
| 907 | `qname_constr` | 32 | 7.9s |  |
| 908 | `qname_constr_namespace` | 24 | 7.8s |  |
| 909 | `qname_enumeration` | 9 | 7.8s |  |
| 910 | `qname_indexing` | 23 | 8.0s |  |
| 911 | `qname_tostring` | 25 | 8.0s |  |
| 912 | `qname_valueof` | 29 | 8.0s |  |
| 913 | `rectangle` | 1094 | 8.7s |  |
| 914 | `regexp_constr` | 148 | 8.2s |  |
| 915 | `regexp_exec` | 19 | 7.9s |  |
| 916 | `regexp_extended` | 47 | 7.8s |  |
| 917 | `regexp_multiargs` | 1 | 7.7s |  |
| 918 | `regexp_test` | 27 | 7.9s |  |
| 919 | `regexp_toString` | 10 | 7.9s |  |
| 920 | `register_script_refresh` | 35 | 29.1s |  |
| 921 | `remove_child_clear_field` | 88 | 24.1s |  |
| 922 | `remove_dobj` | 3 | 21.3s |  |
| 923 | `resolve_order` | 4 | 6.3s |  |
| 924 | `responder_null_callbacks` | 1 | 19.9s |  |
| 925 | `rng` | 1 | 5.9s |  |
| 926 | `rootless` | 42 | 5.2s |  |
| 927 | `rshift` | 1058 | 12.5s |  |
| 928 | `rtqname_not_namespace` | 12 | 5.2s |  |
| 929 | `sandbox_type_inherited` | 2 | 5.3s |  |
| 930 | `sandbox_type_local_file` | 1 | 5.1s |  |
| 931 | `sandbox_type_local_network` | 1 | 4.7s |  |
| 932 | `scene_constr` | 8 | 5.0s |  |
| 933 | `scope_optimizations` | 4 | 4.9s |  |
| 934 | `scopes_dont_cache/order-1` | 1 | 17.3s |  |
| 935 | `scopes_dont_cache/order-2` | 1 | 0.3s |  |
| 936 | `security_domain_current` | 2 | 5.0s |  |
| 937 | `selection` | 239 | 5.2s |  |
| 938 | `set_local_0` | 31 | 5.0s |  |
| 939 | `set_property_is_enumerable` | 85 | 5.2s |  |
| 940 | `shaderparameter_value` | 4 | 5.0s |  |
| 941 | `shape_drawrect` | 54 | 5.0s |  |
| 942 | `shared_object_no_root` | 3 | 4.9s |  |
| 943 | `simplebutton_added_to_stage` | 45 | 17.8s |  |
| 944 | `simplebutton_childevents` | 86 | 18.0s |  |
| 945 | `simplebutton_childevents_nested` | 54 | 5.5s |  |
| 946 | `simplebutton_childevents_sprite` | 13 | 5.2s |  |
| 947 | `simplebutton_childprops` | 144 | 5.2s |  |
| 948 | `simplebutton_childshuffle` | 23 | 5.0s |  |
| 949 | `simplebutton_constr` | 36 | 5.3s |  |
| 950 | `simplebutton_constr_childevents` | 48 | 5.4s |  |
| 951 | `simplebutton_constr_params` | 42 | 5.3s |  |
| 952 | `simplebutton_mouseenabled` | 26 | 5.1s |  |
| 953 | `simplebutton_multi_children` | 19 | 5.1s |  |
| 954 | `simplebutton_soundtransform` | 887 | 18.8s |  |
| 955 | `simplebutton_structure` | 27 | 5.2s |  |
| 956 | `simplebutton_symbolclass` | 68 | 5.4s |  |
| 957 | `slot_disp_id_shared_numbering` | 1 | 17.6s |  |
| 958 | `slots_force_autoassigned` | 1 | 25.2s |  |
| 959 | `socket_after_disconnect` | 1 | 22.0s |  |
| 960 | `socket_close` | 2 | 5.6s |  |
| 961 | `socket_connect` | 4 | 5.6s |  |
| 962 | `socket_errors` | 56 | 6.0s |  |
| 963 | `socket_read_big` | 48 | 5.8s |  |
| 964 | `socket_read_little` | 48 | 1.6s |  |
| 965 | `socket_read_write_object` | 8 | 5.7s |  |
| 966 | `socket_write_big` | 15 | 5.8s |  |
| 967 | `socket_write_little` | 14 | 5.7s |  |
| 968 | `sound_constructor_with_args` | 6 | 5.8s |  |
| 969 | `sound_embeddedprops` | 26 | 5.8s |  |
| 970 | `sound_load_multiple` | 19 | 6.7s |  |
| 971 | `sound_play` | 19 | 5.9s |  |
| 972 | `sound_rootless` | 7 | 5.7s |  |
| 973 | `sound_valueof` | 33 | 5.8s |  |
| 974 | `soundchannel_soundtransform` | 835 | 23.9s |  |
| 975 | `soundchannel_soundtransform_exists` | 5 | 22.3s |  |
| 976 | `soundchannel_stop` | 8 | 22.4s |  |
| 977 | `soundmixer_buffertime` | 5 | 5.8s |  |
| 978 | `soundmixer_soundtransform` | 900 | 7.4s |  |
| 979 | `soundmixer_stopall` | 6 | 22.2s |  |
| 980 | `soundtransform` | 442 | 9.6s |  |
| 981 | `space_justifier_clone` | 12 | 5.7s |  |
| 982 | `sprite_with_frames` | 0 | 22.1s |  |
| 983 | `stage3d_agal_cross_product` | 0 | 8.0s |  |
| 984 | `stage3d_agal_upload_errors` | 66 | 8.1s |  |
| 985 | `stage3d_bitmap` | 0 | 26.4s |  |
| 986 | `stage3d_blend` | 81 | 24.4s |  |
| 987 | `stage3d_context3d_string_args` | 158 | 6.8s |  |
| 988 | `stage3d_errors` | 7 | 5.7s |  |
| 989 | `stage3d_errors_atf` | 3 | 6.8s |  |
| 990 | `stage3d_errors_swf_29` | 6 | 5.8s |  |
| 991 | `stage3d_float1_index` | 0 | 23.9s |  |
| 992 | `stage3d_fractal` | 0 | 24.3s |  |
| 993 | `stage3d_ignore_sampler_override` | 0 | 24.4s |  |
| 994 | `stage3d_multistage_triangle` | 3 | 8.2s |  |
| 995 | `stage3d_program_constants_bytearray_be` | 0 | 25.9s |  |
| 996 | `stage3d_program_constants_bytearray_le` | 0 | 8.4s |  |
| 997 | `stage3d_program_constants_invalid_input` | 21 | 6.5s |  |
| 998 | `stage3d_raytrace` | 0 | 48.2s |  |
| 999 | `stage3d_rotating_cube` | 0 | 8.7s |  |
| 1000 | `stage3d_sampler` | 0 | 8.1s |  |
| 1001 | `stage3d_sampler_partial_upload` | 0 | 7.9s |  |
| 1002 | `stage3d_stencil` | 0 | 24.5s |  |
| 1003 | `stage3d_texture` | 0 | 12.6s |  |
| 1004 | `stage3d_texture_bytearray` | 0 | 9.1s |  |
| 1005 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.4s |  |
| 1006 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.2s |  |
| 1007 | `stage3d_triangle` | 0 | 8.0s |  |
| 1008 | `stage3d_triangle_bytes4` | 0 | 8.1s |  |
| 1009 | `stage3d_triangle_float1` | 0 | 7.9s |  |
| 1010 | `stage3d_triangle_index_upload` | 0 | 7.9s |  |
| 1011 | `stage3d_x_y` | 22 | 5.7s |  |
| 1012 | `stage_access` | 10 | 5.7s |  |
| 1013 | `stage_display_state` | 6 | 5.6s |  |
| 1014 | `stage_displayobject_properties` | 24 | 5.6s |  |
| 1015 | `stage_domain_getQualifiedDefinitionNames` | 5 | 5.7s |  |
| 1016 | `stage_framerate_nan` | 7 | 22.0s |  |
| 1017 | `stage_framerate_negative` | 6 | 5.7s |  |
| 1018 | `stage_framerate_zero` | 6 | 5.7s |  |
| 1019 | `stage_invalidate` | 38 | 5.8s |  |
| 1020 | `stage_loaderinfo_properties` | 24 | 22.0s |  |
| 1021 | `stage_mousechildren` | 2 | 5.6s |  |
| 1022 | `stage_mouseenabled` | 15 | 5.6s |  |
| 1023 | `stage_overriden_setters` | 31 | 5.8s |  |
| 1024 | `stage_properties` | 30 | 5.6s |  |
| 1025 | `stage_properties2` | 213 | 5.9s |  |
| 1026 | `stage_scale_factor` | 12 | 25.8s |  |
| 1027 | `stage_stage3Ds_vector` | 1 | 5.5s |  |
| 1028 | `static_length` | 24 | 5.7s |  |
| 1029 | `static_text` | 3 | 5.7s |  |
| 1030 | `static_var_with_this_in_ctor` | 2 | 5.6s |  |
| 1031 | `statictext_text` | 8 | 5.7s |  |
| 1032 | `stored_properties` | 11 | 5.7s |  |
| 1033 | `strict_equality` | 34 | 5.7s |  |
| 1034 | `string_call` | 13 | 5.6s |  |
| 1035 | `string_case` | 23 | 5.6s |  |
| 1036 | `string_char_at` | 27 | 5.6s |  |
| 1037 | `string_char_code_at` | 28 | 5.5s |  |
| 1038 | `string_concat_fromcharcode` | 37 | 5.5s |  |
| 1039 | `string_constr` | 25 | 5.6s |  |
| 1040 | `string_indexof_lastindexof` | 87 | 5.7s |  |
| 1041 | `string_length` | 16 | 5.6s |  |
| 1042 | `string_locale_compare` | 39 | 25.4s |  |
| 1043 | `string_match` | 51 | 22.0s |  |
| 1044 | `string_relational_compare` | 4 | 5.6s |  |
| 1045 | `string_replace` | 51 | 5.8s |  |
| 1046 | `string_search` | 41 | 5.8s |  |
| 1047 | `string_slice_substr_substring` | 170 | 6.4s |  |
| 1048 | `string_split` | 29 | 5.7s |  |
| 1049 | `string_substr_negative` | 21 | 5.6s |  |
| 1050 | `string_substr_weird` | 182 | 5.6s |  |
| 1051 | `stylesheet` | 221 | 6.3s |  |
| 1052 | `stylesheet_parse_color` | 69 | 5.6s |  |
| 1053 | `stylesheet_transform` | 307 | 5.9s |  |
| 1054 | `sub_super_same_field` | 12 | 1.7s |  |
| 1055 | `subclass_superclass_linked_symbol` | 4 | 6.0s |  |
| 1056 | `subtract` | 1058 | 13.1s |  |
| 1057 | `super_get_call` | 12 | 5.6s |  |
| 1058 | `supercall_two_classobjects` | 2 | 5.6s |  |
| 1059 | `supercalls_coerce` | 8 | 5.7s |  |
| 1060 | `supercalls_weird` | 2 | 5.6s |  |
| 1061 | `superinterface_call` | 20 | 5.6s |  |
| 1062 | `superinterface_instanceof` | 18 | 5.7s |  |
| 1063 | `swf8` | 1 | 5.6s |  |
| 1064 | `swf_10_queued_goto_scripts_construct` | 52 | 22.0s |  |
| 1065 | `swf_9_goto_in_enter_frame` | 17 | 5.7s |  |
| 1066 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.7s |  |
| 1067 | `swf_9_queued_goto_scripts` | 6 | 21.9s |  |
| 1068 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 1069 | `swf_9_versioning` | 2 | 5.6s |  |
| 1070 | `swf_wrong_frame_count` | 38 | 5.9s |  |
| 1071 | `swf_wrong_frame_count_isplaying` | 22 | 5.6s |  |
| 1072 | `symbol_class_binary_data` | 8 | 5.6s |  |
| 1073 | `symbol_class_conflict` | 4 | 5.7s |  |
| 1074 | `symbol_class_root_not_zero` | 1 | 5.5s |  |
| 1075 | `symbolclass_invalid_utf8` | 2 | 5.6s |  |
| 1076 | `system_exit` | 3 | 5.6s |  |
| 1077 | `system_setclipboard_null` | 1 | 5.6s |  |
| 1078 | `tab_ordering_arrows` | 998 | 22.7s |  |
| 1079 | `tab_ordering_automatic_advanced` | 184 | 6.2s |  |
| 1080 | `tab_ordering_automatic_basic` | 45 | 5.7s |  |
| 1081 | `tab_ordering_children` | 116 | 5.8s |  |
| 1082 | `tab_ordering_custom_basic` | 34 | 5.7s |  |
| 1083 | `tab_ordering_properties` | 732 | 5.9s |  |
| 1084 | `tab_ordering_stage_tab_children` | 32 | 27.2s |  |
| 1085 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.0s |  |
| 1086 | `tab_ordering_tabbable` | 47 | 6.0s |  |
| 1087 | `tabstop_properties` | 105 | 23.6s |  |
| 1088 | `text_element_basic` | 34 | 6.2s |  |
| 1089 | `text_engine_fontdescription` | 27 | 6.2s |  |
| 1090 | `text_engine_groupelement` | 64 | 6.8s |  |
| 1091 | `text_run` | 7 | 5.8s |  |
| 1092 | `textblock_createline_errors` | 23 | 6.0s |  |
| 1093 | `textblock_createline_fte` | 9 | 23.4s |  |
| 1094 | `textblock_properties` | 118 | 6.4s |  |
| 1095 | `textbox_click` | 37 | 23.3s |  |
| 1096 | `textfield_event` | 66 | 6.2s |  |
| 1097 | `textfield_focusin_event` | 9 | 5.7s |  |
| 1098 | `textfield_input_dead_keys_windows` | 15 | 6.0s |  |
| 1099 | `textfield_input_events` | 25 | 19.5s |  |
| 1100 | `textfield_unload` | 39 | 23.6s |  |
| 1101 | `textformat` | 1134 | 6.0s |  |
| 1102 | `textformat_display` | 14 | 6.0s |  |
| 1103 | `textformat_font_max_length` | 4 | 6.0s |  |
| 1104 | `textjustifier_locale` | 132 | 6.2s |  |
| 1105 | `textline_has_tabs` | 47 | 5.9s |  |
| 1106 | `textline_inapplicable_properties` | 10 | 5.9s |  |
| 1107 | `textline_name` | 1 | 6.0s |  |
| 1108 | `textline_raw_text_length` | 30 | 6.0s |  |
| 1109 | `textline_splitting_basic` | 76 | 6.2s |  |
| 1110 | `textline_throwerror` | 30 | 6.0s |  |
| 1111 | `textline_validity` | 162 | 6.1s |  |
| 1112 | `throw` | 3 | 5.9s |  |
| 1113 | `timeline_scripts` | 3 | 23.1s |  |
| 1114 | `timer` | 90 | 6.5s |  |
| 1115 | `timer_events` | 3 | 6.0s |  |
| 1116 | `timer_finished` | 11 | 6.0s |  |
| 1117 | `timer_invalid_delay` | 30 | 6.0s |  |
| 1118 | `timer_reset` | 8 | 6.2s |  |
| 1119 | `timer_setdelay` | 5 | 5.9s |  |
| 1120 | `trace` | 12 | 32.6s |  |
| 1121 | `truthiness` | 30 | 7.8s |  |
| 1122 | `try_catch` | 11 | 7.9s |  |
| 1123 | `try_catch_typed` | 12 | 7.8s |  |
| 1124 | `typeof` | 30 | 7.8s |  |
| 1125 | `uint_constr` | 92 | 7.9s |  |
| 1126 | `uint_tofixed` | 1215 | 7.6s |  |
| 1127 | `uint_toprecision` | 1125 | 7.9s |  |
| 1128 | `uint_tostring` | 3375 | 8.0s |  |
| 1129 | `uncaught_error_basic` | 2 | 7.7s |  |
| 1130 | `unchecked_function` | 15 | 7.7s |  |
| 1131 | `unescape` | 28 | 7.7s |  |
| 1132 | `url_loader` | 25 | 8.0s |  |
| 1133 | `url_vars` | 27 | 7.9s |  |
| 1134 | `urlrequest` | 18 | 28.1s |  |
| 1135 | `urlstream_basic` | 5 | 7.8s |  |
| 1136 | `urshift` | 1058 | 19.1s |  |
| 1137 | `utils3d` | 7 | 7.8s |  |
| 1138 | `vector3d` | 397 | 12.5s |  |
| 1139 | `vector3d_near_equals` | 80 | 7.8s |  |
| 1140 | `vector_class` | 36 | 8.3s |  |
| 1141 | `vector_class_call` | 11 | 8.1s |  |
| 1142 | `vector_coercion` | 66 | 8.8s |  |
| 1143 | `vector_concat` | 90 | 8.5s |  |
| 1144 | `vector_constr` | 107 | 8.7s |  |
| 1145 | `vector_enumeration` | 5 | 7.7s |  |
| 1146 | `vector_every` | 92 | 8.7s |  |
| 1147 | `vector_filter` | 95 | 8.8s |  |
| 1148 | `vector_holes` | 24 | 7.9s |  |
| 1149 | `vector_indexof` | 302 | 12.9s |  |
| 1150 | `vector_insertat` | 270 | 9.1s |  |
| 1151 | `vector_int_access` | 4 | 7.7s |  |
| 1152 | `vector_int_delete` | 11 | 7.8s |  |
| 1153 | `vector_join` | 58 | 8.3s |  |
| 1154 | `vector_lastindexof` | 302 | 7.6s |  |
| 1155 | `vector_legacy` | 10 | 7.8s |  |
| 1156 | `vector_map` | 85 | 8.6s |  |
| 1157 | `vector_object_final` | 1 | 7.6s |  |
| 1158 | `vector_object_toString` | 10 | 7.7s |  |
| 1159 | `vector_prototype_some` | 125 | 7.9s |  |
| 1160 | `vector_pushpop` | 255 | 34.9s |  |
| 1161 | `vector_reborrow_bug` | 10 | 28.7s |  |
| 1162 | `vector_removeat` | 172 | 9.2s |  |
| 1163 | `vector_reverse` | 232 | 9.3s |  |
| 1164 | `vector_shiftunshift` | 252 | 7.8s |  |
| 1165 | `vector_slice` | 331 | 10.0s |  |
| 1166 | `vector_sort` | 905 | 18.9s |  |
| 1167 | `vector_splice` | 693 | 12.8s |  |
| 1168 | `vector_splice_fixed_bug_compat` | 4 | 8.1s |  |
| 1169 | `vector_tostring` | 79 | 8.7s |  |
| 1170 | `verification` | 8 | 8.0s |  |
| 1171 | `verify_abnormal_loop` | 1 | 7.8s |  |
| 1172 | `verify_dxns_without_flag` | 3 | 8.3s |  |
| 1173 | `verify_exception_target_two_jumps` | 1 | 7.8s |  |
| 1174 | `verify_exception_targets_edge_case` | 1 | 7.8s |  |
| 1175 | `verify_illegal_opcode` | 1 | 3.0s |  |
| 1176 | `verify_jump_to_middle_of_op` | 1 | 7.9s |  |
| 1177 | `verify_lookup_switch_edge_case` | 1 | 7.8s |  |
| 1178 | `verify_method_info_oob` | 1 | 0.6s |  |
| 1179 | `verify_stack` | 5 | 8.0s |  |
| 1180 | `verify_typecheck` | 4 | 8.0s |  |
| 1181 | `verify_unreachable_exception` | 2 | 7.9s |  |
| 1182 | `versioned_isplaying` | 2 | 7.9s |  |
| 1183 | `virtual_properties` | 16 | 8.1s |  |
| 1184 | `with` | 4 | 7.9s |  |
| 1185 | `wrong_arg_count` | 7 | 8.0s |  |
| 1186 | `xml_abstract_equality` | 36 | 8.1s |  |
| 1187 | `xml_advanced` | 52 | 7.9s |  |
| 1188 | `xml_appendchild` | 10 | 7.8s |  |
| 1189 | `xml_appendchild_swf_v21` | 13 | 8.2s |  |
| 1190 | `xml_as_attribute` | 9 | 7.9s |  |
| 1191 | `xml_attribute` | 35 | 8.0s |  |
| 1192 | `xml_attribute_name` | 40 | 7.8s |  |
| 1193 | `xml_basic` | 33 | 7.9s |  |
| 1194 | `xml_child` | 25 | 7.8s |  |
| 1195 | `xml_childindex` | 7 | 7.7s |  |
| 1196 | `xml_children` | 43 | 8.4s |  |
| 1197 | `xml_class_call` | 9 | 7.7s |  |
| 1198 | `xml_contains` | 197 | 7.7s |  |
| 1199 | `xml_copy` | 20 | 32.8s |  |
| 1200 | `xml_ctor_from_tostring` | 23 | 28.2s |  |
| 1201 | `xml_delete` | 114 | 7.3s |  |
| 1202 | `xml_descendants` | 83 | 7.5s |  |
| 1203 | `xml_duplicate_attribute` | 14 | 7.4s |  |
| 1204 | `xml_elements` | 6 | 7.5s |  |
| 1205 | `xml_equals_namespace_check` | 2 | 7.5s |  |
| 1206 | `xml_explicit_use_namespace` | 5 | 7.4s |  |
| 1207 | `xml_getdescendants_qname` | 21 | 7.5s |  |
| 1208 | `xml_has_property_via_in` | 26 | 7.4s |  |
| 1209 | `xml_hasownproperty` | 6 | 7.4s |  |
| 1210 | `xml_ignore_white` | 6 | 7.4s |  |
| 1211 | `xml_length` | 2 | 7.4s |  |
| 1212 | `xml_list_as_attribute` | 9 | 7.3s |  |
| 1213 | `xml_list_concat` | 20 | 7.4s |  |
| 1214 | `xml_list_ctor_errors` | 34 | 7.3s |  |
| 1215 | `xml_list_delete_clear_parent` | 6 | 7.4s |  |
| 1216 | `xml_list_enumerate` | 4 | 7.4s |  |
| 1217 | `xml_methods_settings` | 3 | 7.3s |  |
| 1218 | `xml_mismatched_tag` | 45 | 7.5s |  |
| 1219 | `xml_namespace` | 39 | 7.3s |  |
| 1220 | `xml_namespace_methods` | 245 | 7.2s |  |
| 1221 | `xml_namespaced_property` | 7 | 7.2s |  |
| 1222 | `xml_no_namespace` | 1 | 7.2s |  |
| 1223 | `xml_nodekind` | 3 | 7.2s |  |
| 1224 | `xml_normalize` | 35 | 7.5s |  |
| 1225 | `xml_notification_bubbling` | 361 | 7.2s |  |
| 1226 | `xml_parent` | 8 | 7.3s |  |
| 1227 | `xml_set_children` | 17 | 7.3s |  |
| 1228 | `xml_set_name` | 34 | 7.3s |  |
| 1229 | `xml_settings` | 6 | 2.2s |  |
| 1230 | `xml_simple_complex_content` | 47 | 7.4s |  |
| 1231 | `xml_socket` | 11 | 7.7s |  |
| 1232 | `xml_text` | 7 | 7.3s |  |
| 1233 | `xml_tostring` | 6 | 7.3s |  |
| 1234 | `xml_tostring_namespace` | 12 | 7.1s |  |
| 1235 | `xml_unescaping` | 23 | 7.4s |  |
| 1236 | `xml_weird_ignores` | 54 | 7.3s |  |
| 1237 | `xml_wildcard` | 11 | 7.3s |  |
| 1238 | `xmldocument` | 254 | 7.3s |  |
| 1239 | `xmlnode` | 3540 | 7.2s |  |
| 1240 | `zero_frame_clip` | 3 | 7.6s |  |

## Ruffle-Matched Tests

**42 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 5.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.3s |  |
| 3 | `blend_transform` | 1 | 1 | 25.9s |  |
| 4 | `bounds_mode` | 6 | 6 | 6.1s |  |
| 5 | `coerce_property` | 3 | 3 | 8.6s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 8.4s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 19.1s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 22.5s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 5.9s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.6s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.5s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 6.0s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.5s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 5.6s |  |
| 15 | `freestanding_superclass` | 2 | 4 | 5.6s |  |
| 16 | `goto_framescript_queued/swf13` | 3 | 3 | 30.0s |  |
| 17 | `gradient_values_readback` | 12 | 12 | 8.6s |  |
| 18 | `graphics_draw_path` | 50 | 50 | 30.8s |  |
| 19 | `groupelement_text` | 2 | 2 | 8.1s |  |
| 20 | `html_text_img_parsing` | 95 | 95 | 7.9s |  |
| 21 | `int_toexponential` | 76 | 76 | 8.7s |  |
| 22 | `json_parse_numbers` | 4 | 79 | 8.5s |  |
| 23 | `loader_events_2` | 30 | 30 | 5.9s |  |
| 24 | `matrix3d_recompose_edge_cases` | 8 | 85 | 5.9s |  |
| 25 | `number_convert_errors` | 706 | 706 | 5.9s |  |
| 26 | `number_to_string` | 104 | 104 | 6.0s |  |
| 27 | `simplebutton_childevents_multichild` | 101 | 101 | 5.1s |  |
| 28 | `simplebutton_childevents_script_order` | 4 | 4 | 5.3s |  |
| 29 | `slot_holes_fail` | 1 | 1 | 5.0s |  |
| 30 | `slot_id_exceeds_trait_count` | 1 | 1 | 5.1s |  |
| 31 | `soundchannel_position` | 74 | 74 | 23.4s |  |
| 32 | `soundchannel_soundcomplete` | 10 | 10 | 5.9s |  |
| 33 | `sprite_dropTarget` | 15 | 15 | 5.7s |  |
| 34 | `swf_9_goto_in_construct_frame` | 12 | 12 | 22.1s |  |
| 35 | `textblock_line_changes` | 44 | 44 | 6.3s |  |
| 36 | `textblock_recreateline` | 137 | 138 | 6.4s |  |
| 37 | `textblock_releaselines` | 4 | 4 | 7.4s |  |
| 38 | `textline_atom_index_at_char_index` | 3 | 3 | 6.8s |  |
| 39 | `uint_toexponential` | 100 | 100 | 7.9s |  |
| 40 | `uncaught_errors_stringified` | 15 | 15 | 7.9s |  |
| 41 | `vector_indexing_cutoffs` | 1 | 1 | 7.9s |  |
| 42 | `weird_superinterface_properties` | 1 | 1 | 7.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**16 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `error_stack_trace_class_names` | 94.1% | 127 | 135 | 8 |  |
| 3 | `array_join_reentrant` | 85.3% | 58 | 68 | 10 |  |
| 4 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 5 | `edittext_set_text_same` | 80.0% | 92 | 115 | 23 |  |
| 6 | `filereference_browse_select` | 77.8% | 7 | 9 | 2 |  |
| 7 | `weird_number_bound_methods` | 75.0% | 9 | 12 | 3 |  |
| 8 | `hit_test_scroll_rect` | 69.7% | 69 | 99 | 30 |  |
| 9 | `error_stack_trace_limit` | 69.1% | 600 | 868 | 268 |  |
| 10 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 11 | `event_handler_exception` | 63.6% | 7 | 11 | 4 |  |
| 12 | `edittext_set_text_same_after_edits` | 60.9% | 84 | 138 | 54 |  |
| 13 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 14 | `dictionary_qname_keys` | 50.9% | 29 | 57 | 28 |  |
| 15 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |
| 16 | `xml_many_namespace_declarations` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**52 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `error_stack_trace_class_names` | 94.1% | 127/135 | 135 | 135 |  |
| 3 | `array_join_reentrant` | 85.3% | 58/68 | 68 | 68 |  |
| 4 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 5 | `edittext_set_text_same` | 80.0% | 92/115 | 115 | 115 |  |
| 6 | `filereference_browse_select` | 77.8% | 7/9 | 9 | 9 |  |
| 7 | `weird_number_bound_methods` | 75.0% | 9/12 | 12 | 12 |  |
| 8 | `hit_test_scroll_rect` | 69.7% | 69/99 | 99 | 99 |  |
| 9 | `error_stack_trace_limit` | 69.1% | 600/868 | 868 | 674 |  |
| 10 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 11 | `event_handler_exception` | 63.6% | 7/11 | 11 | 11 |  |
| 12 | `edittext_set_text_same_after_edits` | 60.9% | 84/138 | 138 | 138 |  |
| 13 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 14 | `dictionary_qname_keys` | 50.9% | 29/57 | 57 | 45 |  |
| 15 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 16 | `xml_many_namespace_declarations` | 50.0% | 1/2 | 2 | 2 |  |
| 17 | `primitive_bound_methods` | 45.5% | 5/11 | 11 | 11 |  |
| 18 | `loaderinfo_root_progress` | 42.9% | 3/7 | 6 | 7 |  |
| 19 | `loaderinfo_root_progress_goto` | 40.0% | 4/10 | 6 | 10 |  |
| 20 | `displayobjectcontainer_removechildren_events` | 36.2% | 21/58 | 58 | 56 |  |
| 21 | `stage3d_missing_vertex_stream` | 35.1% | 13/37 | 27 | 37 |  |
| 22 | `textfield_default_text_format_null` | 35.0% | 7/20 | 12 | 20 |  |
| 23 | `amf_xmllist` | 33.3% | 4/12 | 12 | 12 |  |
| 24 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 25 | `displayobjectcontainer_remove_reparent` | 31.2% | 59/189 | 185 | 189 |  |
| 26 | `focus_events_mixed_avm_edittext` | 24.5% | 12/49 | 47 | 49 |  |
| 27 | `xml_unescaping_nul_char_ref` | 21.1% | 4/19 | 19 | 19 |  |
| 28 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 29 | `perspective_projection_center` | 17.6% | 6/34 | 26 | 34 |  |
| 30 | `context3d_draw_to_bitmap_data` | 13.3% | 2/15 | 11 | 15 |  |
| 31 | `vector_join_reentrant` | 10.4% | 10/96 | 84 | 96 |  |
| 32 | `array_sort_arguments` | 9.5% | 42/442 | 277 | 442 |  |
| 33 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 34 | `array_constructor` | 9.0% | 21/234 | 181 | 234 |  |
| 35 | `textfield_set_text_format_args` | 9.0% | 81/904 | 638 | 904 |  |
| 36 | `textfield_get_text_format_args` | 8.8% | 50/567 | 447 | 567 |  |
| 37 | `shared_object_get_local_error` | 4.8% | 1/21 | 5 | 21 |  |
| 38 | `bitmapdata_encode_png_roundtrip` | 3.0% | 1/33 | 4 | 33 |  |
| 39 | `worker_terminate` | 1.8% | 1/56 | 3 | 56 |  |
| 40 | `bitmapdata_encode` | 0.7% | 1/147 | 5 | 147 |  |
| 41 | `vector_sort_arguments` | 0.3% | 1/355 | 198 | 355 |  |
| 42 | `displayobjectcontainer_remove_reentrant` | 0.0% | 2/27942 | 27942 | 257 |  |
| 43 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 44 | `bitmapdata_encode_jpeg_visual` | 0.0% | 0/3 | 3 | 0 |  |
| 45 | `bitmapdata_encode_png_visual` | 0.0% | 0/3 | 3 | 0 |  |
| 46 | `edittext_event_link_case_insensitive` | 0.0% | 0/1 | 0 | 1 |  |
| 47 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 48 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 49 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 50 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 51 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 52 | `textline_metrics` | 0.0% | 0/20 | 20 | 20 |  |
