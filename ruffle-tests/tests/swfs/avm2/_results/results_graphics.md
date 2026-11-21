# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 18:24 UTC

**Git SHA**: `bc91565cea`

**Run Duration**: 234m 30s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1334 |
| Passing | **1242** (93.1%) |
| Ruffle-matched | 42 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1284** (96.3%) |
| Failing | 50 |
| Total expected lines | 163871 |
| Matching lines | 157993 (96.4%) |
| Mismatched lines | 5878 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 50 | 100.0% |

## Passing Tests

**1242 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 22.3s |  |
| 2 | `accessibility` | 1 | 6.4s |  |
| 3 | `accessibilityimplementation` | 18 | 22.2s |  |
| 4 | `activation_class` | 6 | 6.5s |  |
| 5 | `add` | 1058 | 13.5s |  |
| 6 | `agal_compiler` | 13 | 8.8s |  |
| 7 | `air_datagram_socket` | 1 | 8.2s |  |
| 8 | `air_hidden_lookup` | 2 | 6.5s |  |
| 9 | `air_ifilepromise` | 1 | 6.5s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 6.6s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.9s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.9s |  |
| 13 | `all_classes/display/swf10` | 2569 | 6.6s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.0s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.9s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.9s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.9s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.9s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 6.6s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.9s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.9s |  |
| 22 | `all_classes/errors/swf10` | 140 | 6.6s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.9s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.9s |  |
| 25 | `all_classes/events/swf10` | 1638 | 6.7s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.9s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.9s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.9s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.9s |  |
| 30 | `all_classes/security/swf11` | 3 | 6.5s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.8s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.8s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.9s |  |
| 34 | `all_classes/xml/swf30` | 116 | 6.5s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.9s |  |
| 36 | `amf_array_serialization` | 17 | 24.2s |  |
| 37 | `amf_custom_obj` | 26 | 6.6s |  |
| 38 | `amf_dictionary` | 9 | 6.5s |  |
| 39 | `amf_function` | 46 | 6.6s |  |
| 40 | `amf_invalid_date` | 2 | 6.5s |  |
| 41 | `amf_missing_prop` | 6 | 6.5s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 6.5s |  |
| 43 | `amf_sealed_class_dynamic_properties` | 16 | 6.6s |  |
| 44 | `amf_setter_error` | 8 | 6.6s |  |
| 45 | `amf_vector` | 40 | 6.7s |  |
| 46 | `amf_xml` | 6 | 28.7s |  |
| 47 | `appdomain_lookup_edge_cases` | 32 | 8.9s |  |
| 48 | `application_domain` | 4 | 8.3s |  |
| 49 | `applicationdomain_getqualifieddefinitionnames` | 9 | 28.3s |  |
| 50 | `applicationdomain_hasdefinition_null` | 2 | 8.2s |  |
| 51 | `array_access` | 18 | 8.0s |  |
| 52 | `array_access_interpreter` | 4 | 8.1s |  |
| 53 | `array_access_no_pubns` | 2 | 8.4s |  |
| 54 | `array_concat` | 41 | 8.5s |  |
| 55 | `array_constr` | 10 | 8.4s |  |
| 56 | `array_delete` | 44 | 8.1s |  |
| 57 | `array_enumeration` | 10 | 8.0s |  |
| 58 | `array_enumeration_elements` | 11 | 8.3s |  |
| 59 | `array_every` | 8 | 8.4s |  |
| 60 | `array_filter` | 6 | 8.0s |  |
| 61 | `array_foreach` | 18 | 8.1s |  |
| 62 | `array_hasownproperty` | 11 | 8.0s |  |
| 63 | `array_holes` | 9 | 8.1s |  |
| 64 | `array_index_max` | 84 | 8.1s |  |
| 65 | `array_indexof` | 25 | 8.1s |  |
| 66 | `array_join` | 26 | 8.2s |  |
| 67 | `array_lastindexof` | 29 | 8.1s |  |
| 68 | `array_length` | 14 | 8.0s |  |
| 69 | `array_literal` | 3 | 8.0s |  |
| 70 | `array_map` | 8 | 7.8s |  |
| 71 | `array_pop` | 52 | 7.9s |  |
| 72 | `array_push` | 24 | 8.2s |  |
| 73 | `array_reborrow_bug` | 6 | 7.8s |  |
| 74 | `array_reverse` | 28 | 8.3s |  |
| 75 | `array_shift` | 51 | 2.6s |  |
| 76 | `array_slice` | 39 | 8.2s |  |
| 77 | `array_some` | 8 | 7.9s |  |
| 78 | `array_sort` | 297 | 8.9s |  |
| 79 | `array_sort_fun_swf12` | 2 | 8.2s |  |
| 80 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 81 | `array_sort_random` | 210 | 8.0s |  |
| 82 | `array_sort_swf10_32bit` | 1 | 8.2s |  |
| 83 | `array_sorton` | 545 | 8.2s |  |
| 84 | `array_sparse_ops` | 41 | 8.3s |  |
| 85 | `array_splice` | 133 | 28.6s |  |
| 86 | `array_splice2` | 428 | 30.5s |  |
| 87 | `array_splice_types` | 48 | 9.4s |  |
| 88 | `array_storage` | 8 | 9.3s |  |
| 89 | `array_tolocalestring` | 9 | 9.3s |  |
| 90 | `array_tostring` | 12 | 9.3s |  |
| 91 | `array_unshift` | 24 | 9.4s |  |
| 92 | `array_valueof` | 9 | 9.2s |  |
| 93 | `array_vector_null_callback` | 10 | 9.3s |  |
| 94 | `astype` | 28 | 9.4s |  |
| 95 | `astypelate` | 24 | 9.5s |  |
| 96 | `astypelate_propagates` | 1 | 9.2s |  |
| 97 | `asymmetric_key_events` | 11 | 9.5s |  |
| 98 | `automation_classes` | 122 | 9.9s |  |
| 99 | `av_classes` | 340 | 9.8s |  |
| 100 | `avm1movie_addcallback_call` | 14 | 9.5s |  |
| 101 | `avm2_catchup_dobj` | 158 | 10.5s |  |
| 102 | `away3d_advanced_shallow_water_demo` | 0 | 115.1s |  |
| 103 | `bevel_filter` | 187 | 9.7s |  |
| 104 | `bitand` | 1058 | 20.7s |  |
| 105 | `bitmap_constr` | 17 | 9.6s |  |
| 106 | `bitmap_data` | 1000 | 20.8s |  |
| 107 | `bitmap_filter_abstract` | 6 | 9.4s |  |
| 108 | `bitmap_pixelsnapping` | 2 | 30.8s |  |
| 109 | `bitmap_properties` | 23 | 9.4s |  |
| 110 | `bitmap_subclass` | 7 | 11.4s |  |
| 111 | `bitmap_subclass_properties` | 9 | 9.9s |  |
| 112 | `bitmap_timeline` | 9 | 9.8s |  |
| 113 | `bitmapdata_accuracy` | 1 | 50.2s |  |
| 114 | `bitmapdata_applyfilter_blur` | 0 | 31.5s |  |
| 115 | `bitmapdata_applyfilter_colormatrix` | 0 | 10.3s |  |
| 116 | `bitmapdata_applyfilter_destpoint` | 0 | 33.0s |  |
| 117 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 31.0s |  |
| 118 | `bitmapdata_applyfilter_identity` | 4 | 30.3s |  |
| 119 | `bitmapdata_clone` | 13 | 9.6s |  |
| 120 | `bitmapdata_colortransform` | 0 | 9.8s |  |
| 121 | `bitmapdata_colortransform_oob` | 2 | 9.3s |  |
| 122 | `bitmapdata_constr` | 22 | 9.5s |  |
| 123 | `bitmapdata_constructor_from_timeline` | 1 | 9.7s |  |
| 124 | `bitmapdata_copychannel` | 0 | 32.6s |  |
| 125 | `bitmapdata_copypixels` | 23 | 31.2s |  |
| 126 | `bitmapdata_copypixels_alpha_combine` | 13 | 9.4s |  |
| 127 | `bitmapdata_copypixels_alpha_merge` | 9 | 9.4s |  |
| 128 | `bitmapdata_copypixels_blend` | 1029 | 26.9s |  |
| 129 | `bitmapdata_copypixels_blend_over` | 1 | 8.2s |  |
| 130 | `bitmapdata_copypixels_self` | 612 | 8.3s |  |
| 131 | `bitmapdata_copypixelstobytearray` | 39 | 8.2s |  |
| 132 | `bitmapdata_dispose` | 7 | 8.2s |  |
| 133 | `bitmapdata_draw` | 0 | 27.6s |  |
| 134 | `bitmapdata_draw_alpha_erase` | 8 | 8.4s |  |
| 135 | `bitmapdata_draw_cab_quality` | 0 | 27.0s |  |
| 136 | `bitmapdata_draw_colortransform` | 0 | 26.2s |  |
| 137 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 27.0s |  |
| 138 | `bitmapdata_draw_filters` | 0 | 26.9s |  |
| 139 | `bitmapdata_draw_masks` | 0 | 8.1s |  |
| 140 | `bitmapdata_draw_rotation` | 0 | 8.1s |  |
| 141 | `bitmapdata_draw_self_via_graphic` | 0 | 8.2s |  |
| 142 | `bitmapdata_draw_stage` | 0 | 25.5s |  |
| 143 | `bitmapdata_drawwithquality` | 0 | 10.4s |  |
| 144 | `bitmapdata_embedded` | 9 | 8.5s |  |
| 145 | `bitmapdata_fillrect` | 0 | 8.1s |  |
| 146 | `bitmapdata_filter_sourcerect` | 0 | 26.2s |  |
| 147 | `bitmapdata_floodfill` | 35 | 7.9s |  |
| 148 | `bitmapdata_getpixels` | 39 | 26.8s |  |
| 149 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 150 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 151 | `bitmapdata_hittest` | 112 | 8.6s |  |
| 152 | `bitmapdata_hittest_threshold` | 18 | 8.2s |  |
| 153 | `bitmapdata_opaque` | 0 | 8.1s |  |
| 154 | `bitmapdata_pixeldissolve` | 1037 | 8.5s |  |
| 155 | `bitmapdata_pixeldissolve_image` | 0 | 8.1s |  |
| 156 | `bitmapdata_rectangle_rounding` | 16 | 8.0s |  |
| 157 | `bitmapdata_setpixels` | 286 | 8.2s |  |
| 158 | `bitmapdata_setvector` | 26 | 8.6s |  |
| 159 | `bitmapdata_sync` | 0 | 25.7s |  |
| 160 | `bitmapdata_threshold` | 176 | 8.8s |  |
| 161 | `bitmapdata_zero_size` | 8 | 8.1s |  |
| 162 | `bitnot` | 46 | 8.0s |  |
| 163 | `bitor` | 1058 | 17.3s |  |
| 164 | `bitxor` | 1058 | 17.0s |  |
| 165 | `blend_mode_null` | 1 | 8.1s |  |
| 166 | `blend_multiply_alpha` | 0 | 8.3s |  |
| 167 | `blend_scroll` | 0 | 8.5s |  |
| 168 | `blend_shader_luma_lighten` | 3 | 8.5s |  |
| 169 | `blur_filter` | 43 | 10.1s |  |
| 170 | `boolean_constr` | 32 | 9.3s |  |
| 171 | `boolean_negation` | 30 | 9.4s |  |
| 172 | `boolean_tostring` | 8 | 9.2s |  |
| 173 | `broadcast_event` | 7 | 9.1s |  |
| 174 | `button_bounds` | 1 | 9.5s |  |
| 175 | `button_hittest` | 2 | 30.9s |  |
| 176 | `button_nested_frame` | 48 | 30.7s |  |
| 177 | `button_nested_frame_simple` | 27 | 9.7s |  |
| 178 | `bytearray` | 48 | 9.6s |  |
| 179 | `bytearray_amf3_shared_references` | 4 | 9.1s |  |
| 180 | `bytearray_bad_symbol_class` | 3 | 9.3s |  |
| 181 | `bytearray_bad_symbol_class_other_movie` | 6 | 9.6s |  |
| 182 | `bytearray_compress` | 31 | 9.3s |  |
| 183 | `bytearray_errors` | 24 | 9.5s |  |
| 184 | `bytearray_insertion_reborrow` | 5 | 9.3s |  |
| 185 | `bytearray_method_serialization` | 1 | 9.2s |  |
| 186 | `bytearray_oom` | 3 | 9.2s |  |
| 187 | `bytearray_readobject_amf0` | 50 | 9.4s |  |
| 188 | `bytearray_readobject_amf3` | 53 | 9.4s |  |
| 189 | `bytearray_readutf8bytes_with_bom` | 16 | 9.4s |  |
| 190 | `bytearray_serialization` | 3 | 9.3s |  |
| 191 | `bytearray_string_null` | 19 | 9.9s |  |
| 192 | `bytearray_tostring` | 15 | 9.7s |  |
| 193 | `bytearray_utf16` | 8 | 9.5s |  |
| 194 | `bytearray_writeobject` | 24 | 9.4s |  |
| 195 | `callee_in_initializer` | 6 | 9.6s |  |
| 196 | `callproplex_class` | 1 | 9.7s |  |
| 197 | `capabilities_resolution` | 8 | 32.2s |  |
| 198 | `casi32` | 166 | 9.4s |  |
| 199 | `catch_class` | 6 | 9.3s |  |
| 200 | `catch_scope_slot` | 7 | 9.4s |  |
| 201 | `checkfilter` | 4 | 3.5s |  |
| 202 | `class_call` | 32 | 9.6s |  |
| 203 | `class_cast_call` | 14 | 9.3s |  |
| 204 | `class_enumeration` | 4 | 9.4s |  |
| 205 | `class_has_own_property` | 2 | 9.3s |  |
| 206 | `class_init_interpreter_mode` | 1 | 9.3s |  |
| 207 | `class_is` | 32 | 9.7s |  |
| 208 | `class_methods` | 5 | 9.6s |  |
| 209 | `class_object_properties` | 10 | 9.6s |  |
| 210 | `class_singleton` | 18 | 9.8s |  |
| 211 | `class_supercalls_errors` | 35 | 6.8s |  |
| 212 | `class_supercalls_mismatched` | 26 | 6.8s |  |
| 213 | `class_superclass_wrong_order` | 1 | 22.6s |  |
| 214 | `class_to_locale_string` | 2 | 6.7s |  |
| 215 | `class_to_string` | 2 | 6.6s |  |
| 216 | `class_value_of` | 2 | 6.7s |  |
| 217 | `click_block` | 5 | 23.6s |  |
| 218 | `click_invisible` | 3 | 6.7s |  |
| 219 | `closures` | 12 | 6.6s |  |
| 220 | `coerce_return_type` | 40 | 6.8s |  |
| 221 | `coerce_return_type_fail` | 2 | 6.6s |  |
| 222 | `coerce_return_void` | 3 | 6.6s |  |
| 223 | `coerce_string` | 86 | 6.8s |  |
| 224 | `coerce_string_precision` | 28 | 6.8s |  |
| 225 | `coerce_to_primitive_side_effects` | 29 | 6.8s |  |
| 226 | `collator_compare_basic` | 93 | 6.8s |  |
| 227 | `collator_flags` | 111 | 6.7s |  |
| 228 | `collator_locale_ids_windows` | 120 | 6.8s |  |
| 229 | `color_matrix_filter` | 19 | 6.7s |  |
| 230 | `construct_errors_swf10` | 8 | 6.7s |  |
| 231 | `construct_frame_list` | 22 | 22.9s |  |
| 232 | `construct_interface` | 3 | 6.6s |  |
| 233 | `constructor_call` | 3 | 6.6s |  |
| 234 | `constructors_vs_timeline` | 5 | 23.0s |  |
| 235 | `constructprop_dynamic_primitive` | 7 | 6.7s |  |
| 236 | `constructprop_method` | 2 | 6.6s |  |
| 237 | `constructsuper_null` | 2 | 2.2s |  |
| 238 | `content_element_basic` | 50 | 6.8s |  |
| 239 | `context3d_clear_mask` | 4 | 6.5s |  |
| 240 | `context3d_creation` | 9 | 8.3s |  |
| 241 | `control_flow_bool` | 4 | 6.7s |  |
| 242 | `control_flow_stricteq` | 8 | 6.7s |  |
| 243 | `convert_boolean` | 30 | 6.6s |  |
| 244 | `convert_integer` | 90 | 6.8s |  |
| 245 | `convert_number` | 56 | 6.6s |  |
| 246 | `convert_uinteger` | 90 | 6.6s |  |
| 247 | `convolution_filter` | 89 | 6.7s |  |
| 248 | `core_exceptions` | 47 | 7.5s |  |
| 249 | `cpool_index_invalid_bytecode_1` | 6 | 6.6s |  |
| 250 | `cpool_index_invalid_bytecode_2` | 3 | 6.6s |  |
| 251 | `cpool_index_invalid_bytecode_3` | 1 | 6.5s |  |
| 252 | `cross_api_version_call_newer` | 12 | 7.0s |  |
| 253 | `cross_api_version_call_older` | 12 | 7.1s |  |
| 254 | `cryptscore` | 11 | 6.7s |  |
| 255 | `currency_parse_result` | 7 | 6.5s |  |
| 256 | `date` | 30 | 7.0s |  |
| 257 | `date_parse` | 36 | 6.6s |  |
| 258 | `date_set_time_out_of_range` | 62 | 6.5s |  |
| 259 | `declocal` | 46 | 6.6s |  |
| 260 | `declocal_i` | 46 | 6.6s |  |
| 261 | `decode_uri` | 71 | 6.9s |  |
| 262 | `decrement` | 46 | 6.6s |  |
| 263 | `decrement_i` | 46 | 2.2s |  |
| 264 | `default_values` | 7 | 6.7s |  |
| 265 | `delayed_symbolclass` | 28 | 23.1s |  |
| 266 | `describe_type_basic` | 152 | 6.8s |  |
| 267 | `describe_type_json` | 301 | 6.8s |  |
| 268 | `describe_type_metadata` | 125 | 6.7s |  |
| 269 | `describe_type_native` | 23 | 6.5s |  |
| 270 | `dictionary_access` | 62 | 6.7s |  |
| 271 | `dictionary_access_no_pubns` | 2 | 6.5s |  |
| 272 | `dictionary_delete` | 101 | 7.0s |  |
| 273 | `dictionary_foreach` | 42 | 6.7s |  |
| 274 | `dictionary_hasownproperty` | 63 | 6.8s |  |
| 275 | `dictionary_in` | 62 | 6.8s |  |
| 276 | `dictionary_iter_modify` | 8 | 6.6s |  |
| 277 | `dictionary_namespaces` | 36 | 6.7s |  |
| 278 | `displacement_map_filter` | 61 | 6.7s |  |
| 279 | `displayobject_alpha` | 277 | 6.6s |  |
| 280 | `displayobject_blendmode` | 0 | 24.7s |  |
| 281 | `displayobject_colortransform_nested` | 0 | 23.1s |  |
| 282 | `displayobject_early_init` | 54 | 8.1s |  |
| 283 | `displayobject_filters` | 17 | 6.8s |  |
| 284 | `displayobject_from_enterframe` | 1 | 23.0s |  |
| 285 | `displayobject_getbounds_shape` | 0 | 22.8s |  |
| 286 | `displayobject_getrect` | 16 | 6.8s |  |
| 287 | `displayobject_height` | 6052 | 23.0s |  |
| 288 | `displayobject_hittestobject` | 32 | 6.6s |  |
| 289 | `displayobject_hittestpoint` | 49 | 6.6s |  |
| 290 | `displayobject_hittestpoint_boundary` | 65 | 22.9s |  |
| 291 | `displayobject_hittestpoint_root` | 13 | 6.7s |  |
| 292 | `displayobject_invalid_floats` | 60 | 6.5s |  |
| 293 | `displayobject_invalid_props` | 3 | 6.5s |  |
| 294 | `displayobject_mask` | 3 | 6.8s |  |
| 295 | `displayobject_mask_self_referential` | 0 | 31.1s |  |
| 296 | `displayobject_metaData` | 3 | 9.6s |  |
| 297 | `displayobject_name` | 22 | 31.8s |  |
| 298 | `displayobject_name_from_timeline` | 24 | 10.0s |  |
| 299 | `displayobject_opaque_background` | 6 | 33.5s |  |
| 300 | `displayobject_parent` | 12 | 9.6s |  |
| 301 | `displayobject_root` | 24 | 9.6s |  |
| 302 | `displayobject_rotation` | 1284 | 9.7s |  |
| 303 | `displayobject_scrollrect` | 33 | 10.6s |  |
| 304 | `displayobject_set_matrix_nested` | 0 | 33.1s |  |
| 305 | `displayobject_set_name_loaded` | 3 | 9.9s |  |
| 306 | `displayobject_subclass` | 2 | 9.5s |  |
| 307 | `displayobject_transform` | 89 | 9.6s |  |
| 308 | `displayobject_visible` | 23 | 9.5s |  |
| 309 | `displayobject_width` | 4852 | 31.3s |  |
| 310 | `displayobject_x` | 614 | 9.6s |  |
| 311 | `displayobject_y` | 617 | 9.7s |  |
| 312 | `displayobject_z` | 38 | 32.2s |  |
| 313 | `displayobjectcontainer_addchild` | 32 | 9.7s |  |
| 314 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 9.5s |  |
| 315 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 9.8s |  |
| 316 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 9.6s |  |
| 317 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 9.6s |  |
| 318 | `displayobjectcontainer_addchildat` | 42 | 9.5s |  |
| 319 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 9.7s |  |
| 320 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 9.6s |  |
| 321 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 9.6s |  |
| 322 | `displayobjectcontainer_contains` | 66 | 30.8s |  |
| 323 | `displayobjectcontainer_getchildat` | 4 | 9.6s |  |
| 324 | `displayobjectcontainer_getchildbyname` | 9 | 9.4s |  |
| 325 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 9.5s |  |
| 326 | `displayobjectcontainer_getchildindex` | 28 | 9.4s |  |
| 327 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 30.7s |  |
| 328 | `displayobjectcontainer_removechild` | 10 | 9.4s |  |
| 329 | `displayobjectcontainer_removechild_errors` | 4 | 9.3s |  |
| 330 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 9.4s |  |
| 331 | `displayobjectcontainer_removechildat` | 18 | 9.1s |  |
| 332 | `displayobjectcontainer_removechildren` | 51 | 9.5s |  |
| 333 | `displayobjectcontainer_setchildindex` | 42 | 9.0s |  |
| 334 | `displayobjectcontainer_stopallmovieclips` | 2 | 30.3s |  |
| 335 | `displayobjectcontainer_swapchildren` | 42 | 9.5s |  |
| 336 | `displayobjectcontainer_swapchildrenat` | 42 | 10.1s |  |
| 337 | `displayobjectcontainer_timelineinstance` | 48 | 33.5s |  |
| 338 | `divide` | 1058 | 22.0s |  |
| 339 | `doabc_and_symbolclass_script_init_goto` | 7 | 33.9s |  |
| 340 | `doabc_and_symbolclass_script_init_normal` | 6 | 9.7s |  |
| 341 | `doabc_is_eager` | 1 | 32.4s |  |
| 342 | `documentclass` | 9 | 9.9s |  |
| 343 | `domain_memory` | 133 | 34.4s |  |
| 344 | `drag_drop` | 10 | 9.7s |  |
| 345 | `drop_shadow_filter` | 172 | 10.3s |  |
| 346 | `duplicate_defs` | 1 | 9.7s |  |
| 347 | `eager_init` | 1 | 9.7s |  |
| 348 | `east_asian_justifier_clone` | 8 | 9.8s |  |
| 349 | `edit_text_linkage` | 7 | 10.1s |  |
| 350 | `edittext_align` | 60 | 10.8s |  |
| 351 | `edittext_always_show_selection` | 0 | 35.4s |  |
| 352 | `edittext_antialiastype` | 296 | 10.6s |  |
| 353 | `edittext_at_point_methods_basic` | 16 | 11.5s |  |
| 354 | `edittext_autosize` | 39 | 10.4s |  |
| 355 | `edittext_autosize_align` | 0 | 32.8s |  |
| 356 | `edittext_autosize_height_dynamic` | 60 | 32.2s |  |
| 357 | `edittext_autosize_height_input` | 60 | 10.1s |  |
| 358 | `edittext_autosize_lazy_bounds_events` | 65 | 10.3s |  |
| 359 | `edittext_autosize_lazy_bounds_interactions` | 19 | 9.9s |  |
| 360 | `edittext_autosize_lazy_bounds_props` | 490 | 11.8s |  |
| 361 | `edittext_autosize_lazy_bounds_visual` | 0 | 10.1s |  |
| 362 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 10.2s |  |
| 363 | `edittext_bottom_scroll_v_basic` | 210 | 9.7s |  |
| 364 | `edittext_bounds_scale` | 24 | 33.0s |  |
| 365 | `edittext_bullet` | 30 | 10.1s |  |
| 366 | `edittext_default_format` | 221 | 10.2s |  |
| 367 | `edittext_default_format_empty` | 136 | 10.1s |  |
| 368 | `edittext_empty_text_format` | 7 | 9.7s |  |
| 369 | `edittext_focus_selection` | 5 | 9.4s |  |
| 370 | `edittext_font_size` | 45 | 9.8s |  |
| 371 | `edittext_format_empty_font` | 8 | 9.5s |  |
| 372 | `edittext_get_char_index_at_point` | 4 | 34.5s |  |
| 373 | `edittext_get_line_index_at_point` | 2 | 32.5s |  |
| 374 | `edittext_get_line_index_of_char` | 76 | 11.0s |  |
| 375 | `edittext_getcharboundaries` | 172 | 10.2s |  |
| 376 | `edittext_getcharboundaries_missing_glyphs` | 63 | 9.7s |  |
| 377 | `edittext_getcharboundaries_scroll` | 85 | 30.7s |  |
| 378 | `edittext_getlinemetrics` | 146 | 9.8s |  |
| 379 | `edittext_html` | 3101 | 9.9s |  |
| 380 | `edittext_html_condensewhite` | 487 | 9.4s |  |
| 381 | `edittext_html_entity` | 4 | 9.8s |  |
| 382 | `edittext_html_font_size_swf12` | 267 | 9.4s |  |
| 383 | `edittext_html_font_size_swf13` | 273 | 9.0s |  |
| 384 | `edittext_html_roundtrip` | 17 | 9.4s |  |
| 385 | `edittext_ime_focus_lost` | 9 | 30.3s |  |
| 386 | `edittext_input_control` | 12 | 9.3s |  |
| 387 | `edittext_leading` | 9 | 9.9s |  |
| 388 | `edittext_letter_spacing` | 15 | 9.5s |  |
| 389 | `edittext_line_methods` | 294 | 11.1s |  |
| 390 | `edittext_line_metrics` | 11 | 31.9s |  |
| 391 | `edittext_margins` | 25 | 9.6s |  |
| 392 | `edittext_max_scroll_h_basic` | 475 | 9.6s |  |
| 393 | `edittext_max_scroll_v_basic` | 1000 | 9.4s |  |
| 394 | `edittext_mouse_selection` | 363 | 31.6s |  |
| 395 | `edittext_mousedown` | 3 | 9.6s |  |
| 396 | `edittext_mouseenabled` | 26 | 9.3s |  |
| 397 | `edittext_newline_character` | 22 | 9.3s |  |
| 398 | `edittext_newline_stripping` | 64 | 17.7s |  |
| 399 | `edittext_newlines` | 30 | 9.6s |  |
| 400 | `edittext_paragraph_methods` | 257 | 9.3s |  |
| 401 | `edittext_paste_events` | 8 | 9.4s |  |
| 402 | `edittext_paste_maxchars` | 4 | 9.3s |  |
| 403 | `edittext_paste_restrict` | 16 | 9.2s |  |
| 404 | `edittext_restrict` | 191 | 9.3s |  |
| 405 | `edittext_restrict_events` | 22 | 9.3s |  |
| 406 | `edittext_scroll_event` | 37 | 9.6s |  |
| 407 | `edittext_scrollh` | 10 | 9.2s |  |
| 408 | `edittext_selected_text` | 9 | 9.4s |  |
| 409 | `edittext_set_html_same` | 17 | 9.3s |  |
| 410 | `edittext_set_text_vs_html` | 9 | 9.2s |  |
| 411 | `edittext_stylesheet` | 536 | 9.8s |  |
| 412 | `edittext_stylesheet_custom_tag` | 76 | 9.4s |  |
| 413 | `edittext_stylesheet_display` | 272 | 9.5s |  |
| 414 | `edittext_tag_indent` | 49 | 30.2s |  |
| 415 | `edittext_underline` | 40 | 9.7s |  |
| 416 | `edittext_width_height` | 103 | 9.8s |  |
| 417 | `edittext_wordwrap_word` | 150 | 9.4s |  |
| 418 | `edittext_wrap_breaks` | 2375 | 10.0s |  |
| 419 | `element_format_clone` | 44 | 22.5s |  |
| 420 | `element_format_constructor_order` | 64 | 6.7s |  |
| 421 | `element_format_properties` | 235 | 7.7s |  |
| 422 | `empty_bounds` | 1 | 6.5s |  |
| 423 | `encode_uri_surrogate_pair_invalid` | 8 | 6.6s |  |
| 424 | `encode_uri_surrogate_pair_swf11` | 15 | 6.4s |  |
| 425 | `equals` | 512 | 9.1s |  |
| 426 | `error_geterrormessage` | 779 | 6.5s |  |
| 427 | `error_prototype` | 15 | 6.6s |  |
| 428 | `error_stack_trace` | 45 | 6.5s |  |
| 429 | `error_stack_trace_debug_swf17` | 0 | 22.3s |  |
| 430 | `error_stack_trace_debug_swf18` | 0 | 6.3s |  |
| 431 | `error_stack_trace_edge_cases` | 6 | 6.5s |  |
| 432 | `error_stack_trace_release_swf17` | 0 | 2.2s |  |
| 433 | `error_stack_trace_release_swf18` | 0 | 6.3s |  |
| 434 | `error_throwerror` | 103 | 6.6s |  |
| 435 | `error_tostring` | 29 | 6.5s |  |
| 436 | `error_tostring_more` | 86 | 6.6s |  |
| 437 | `es3_inheritance` | 31 | 6.7s |  |
| 438 | `es4_inheritance` | 30 | 6.7s |  |
| 439 | `es4_interfaces` | 30 | 6.6s |  |
| 440 | `es4_method_binding` | 8 | 6.6s |  |
| 441 | `es4_oop_prototypes` | 14 | 6.8s |  |
| 442 | `es4_protected_inheritance` | 6 | 6.6s |  |
| 443 | `escape` | 71 | 6.6s |  |
| 444 | `escape_multi_byte` | 45 | 6.8s |  |
| 445 | `event_bubbles` | 2 | 6.5s |  |
| 446 | `event_cancelable` | 2 | 6.4s |  |
| 447 | `event_clone` | 20 | 6.6s |  |
| 448 | `event_clone_error_redispatch` | 3 | 6.6s |  |
| 449 | `event_clone_on_redispatch` | 10 | 6.6s |  |
| 450 | `event_formattostring` | 31 | 6.7s |  |
| 451 | `event_isdefaultprevented` | 12 | 6.6s |  |
| 452 | `event_target_getter` | 5 | 2.2s |  |
| 453 | `event_target_set` | 9 | 6.5s |  |
| 454 | `event_type` | 1 | 6.6s |  |
| 455 | `event_valueof_tostring` | 18 | 6.7s |  |
| 456 | `eventdispatcher_dispatchevent` | 12 | 6.6s |  |
| 457 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.6s |  |
| 458 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.6s |  |
| 459 | `eventdispatcher_dispatchevent_indirect` | 9 | 24.4s |  |
| 460 | `eventdispatcher_dispatchevent_this` | 5 | 7.1s |  |
| 461 | `eventdispatcher_haseventlistener` | 25 | 7.1s |  |
| 462 | `eventdispatcher_interface_invoke` | 1 | 7.0s |  |
| 463 | `eventdispatcher_tostring` | 10 | 7.0s |  |
| 464 | `eventdispatcher_willtrigger` | 25 | 6.9s |  |
| 465 | `external_interface` | 105 | 7.8s |  |
| 466 | `falsiness` | 30 | 8.0s |  |
| 467 | `fast_index_access` | 12 | 8.1s |  |
| 468 | `filefilter_properties` | 4 | 7.9s |  |
| 469 | `filereference_browse_cancel` | 3 | 8.1s |  |
| 470 | `filereference_load` | 31 | 7.1s |  |
| 471 | `filereference_save` | 16 | 7.1s |  |
| 472 | `filereference_save_and_browse` | 42 | 7.1s |  |
| 473 | `filereference_save_and_load` | 22 | 7.1s |  |
| 474 | `filereference_uninitialized` | 8 | 7.0s |  |
| 475 | `filereferencelist_browse_cancel` | 6 | 7.0s |  |
| 476 | `filereferencelist_browse_select` | 7 | 7.0s |  |
| 477 | `filter_rewind` | 8 | 27.5s |  |
| 478 | `filters_array_holes` | 25 | 9.9s |  |
| 479 | `finddef` | 3 | 7.6s |  |
| 480 | `findprop_global_prototype` | 6 | 7.0s |  |
| 481 | `flash_media_video_constructor` | 156 | 7.6s |  |
| 482 | `flash_media_video_rotation_probe` | 27 | 7.0s |  |
| 483 | `flash_media_video_setter` | 40 | 7.3s |  |
| 484 | `flash_trace` | 17 | 7.1s |  |
| 485 | `flash_ui_mouse_cursor` | 35 | 7.3s |  |
| 486 | `flash_xml` | 29 | 7.1s |  |
| 487 | `flash_xml_cloneNode` | 22 | 7.0s |  |
| 488 | `flash_xml_namespace` | 109 | 7.0s |  |
| 489 | `flash_xml_removeNode` | 60 | 7.3s |  |
| 490 | `focus_events_code` | 161 | 30.4s |  |
| 491 | `focus_events_key_basic` | 132 | 24.2s |  |
| 492 | `focus_events_key_navigation` | 53 | 23.3s |  |
| 493 | `focus_events_key_same_object` | 26 | 7.2s |  |
| 494 | `focus_events_mixed_avm_edittext` | 49 | 7.1s |  |
| 495 | `focus_events_mixed_key_mouse` | 100 | 24.1s |  |
| 496 | `focus_events_mouse_basic` | 260 | 24.1s |  |
| 497 | `focus_events_mouse_focusable` | 112 | 24.1s |  |
| 498 | `focus_events_mouse_same_object` | 40 | 7.6s |  |
| 499 | `focus_remove` | 20 | 29.7s |  |
| 500 | `focus_root_movie` | 4 | 26.2s |  |
| 501 | `focus_stage` | 1 | 6.9s |  |
| 502 | `focusrect` | 18 | 7.6s |  |
| 503 | `focusrect_focuslost` | 9 | 24.8s |  |
| 504 | `focusrect_property` | 110 | 22.6s |  |
| 505 | `font_description_clone` | 14 | 6.6s |  |
| 506 | `font_embedded` | 24 | 7.1s |  |
| 507 | `font_enumeratefonts` | 41 | 7.3s |  |
| 508 | `font_enumeratefonts_filter` | 4 | 7.2s |  |
| 509 | `font_enumeratefonts_order` | 9 | 7.8s |  |
| 510 | `font_hasglyphs` | 40 | 7.1s |  |
| 511 | `font_registerfont` | 129 | 7.6s |  |
| 512 | `framelabel_constr` | 5 | 6.9s |  |
| 513 | `function_call` | 12 | 2.3s |  |
| 514 | `function_call_arguments` | 46 | 6.9s |  |
| 515 | `function_call_arguments_enumerate` | 5 | 6.7s |  |
| 516 | `function_call_coercion` | 108 | 7.1s |  |
| 517 | `function_call_default` | 6 | 6.8s |  |
| 518 | `function_call_rest` | 22 | 6.8s |  |
| 519 | `function_call_types` | 3 | 6.8s |  |
| 520 | `function_call_via_apply` | 11 | 6.8s |  |
| 521 | `function_call_via_call` | 3 | 6.7s |  |
| 522 | `function_display_anonymous` | 7 | 2.3s |  |
| 523 | `function_length` | 6 | 6.8s |  |
| 524 | `function_object` | 2 | 6.8s |  |
| 525 | `function_proto` | 5 | 6.8s |  |
| 526 | `function_proto_created` | 61 | 6.9s |  |
| 527 | `function_to_locale_string` | 4 | 6.7s |  |
| 528 | `function_to_string` | 4 | 6.6s |  |
| 529 | `function_type` | 6 | 6.8s |  |
| 530 | `function_unbound_this` | 51 | 6.9s |  |
| 531 | `function_value_of` | 4 | 6.8s |  |
| 532 | `game_input` | 4 | 6.8s |  |
| 533 | `generate_random_bytes` | 3 | 6.8s |  |
| 534 | `geom_transform` | 74 | 23.4s |  |
| 535 | `get_definition_by_name` | 11 | 6.7s |  |
| 536 | `get_qualified_class_name` | 20 | 6.7s |  |
| 537 | `get_qualified_super_class_name` | 18 | 6.8s |  |
| 538 | `get_slot_edge_cases` | 1 | 6.7s |  |
| 539 | `get_timer` | 2 | 2.2s |  |
| 540 | `getglobalslot` | 1 | 6.6s |  |
| 541 | `getouterscope` | 8 | 6.6s |  |
| 542 | `getouterscope_two_classobjects` | 13 | 6.7s |  |
| 543 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 544 | `glow_filter` | 127 | 6.9s |  |
| 545 | `goto_button_nested_framescript` | 28 | 23.5s |  |
| 546 | `goto_framescript_queued/swf10` | 59 | 23.7s |  |
| 547 | `goto_framescript_queued/swf9` | 52 | 1.0s |  |
| 548 | `goto_framescript_queued_same_frame` | 4 | 22.9s |  |
| 549 | `goto_in_constructframe` | 12 | 23.2s |  |
| 550 | `goto_in_scene_last_frame` | 2 | 23.3s |  |
| 551 | `goto_methods` | 56 | 7.0s |  |
| 552 | `goto_methods_swfver10` | 8 | 6.8s |  |
| 553 | `goto_nested_construct_sibling` | 18 | 7.0s |  |
| 554 | `goto_nested_framescript` | 9 | 6.9s |  |
| 555 | `goto_on_orphan` | 15 | 23.3s |  |
| 556 | `goto_queued_invalid/swf10` | 34 | 23.5s |  |
| 557 | `goto_queued_invalid/swf11` | 43 | 1.0s |  |
| 558 | `goto_queued_invalid/swf9` | 32 | 0.9s |  |
| 559 | `gradient_bevel_filter` | 206 | 6.8s |  |
| 560 | `gradient_glow_filter` | 206 | 6.6s |  |
| 561 | `graphic_linkage` | 9 | 6.9s |  |
| 562 | `graphics_bad_direct_commands` | 5 | 9.1s |  |
| 563 | `graphics_bitmap_fill` | 0 | 24.9s |  |
| 564 | `graphics_bitmaps` | 0 | 7.2s |  |
| 565 | `graphics_direct_commands` | 0 | 7.1s |  |
| 566 | `graphics_draw_triangles` | 98 | 24.3s |  |
| 567 | `graphics_gradients` | 0 | 7.0s |  |
| 568 | `graphics_gradients_nulls` | 0 | 6.9s |  |
| 569 | `graphics_path` | 56 | 6.8s |  |
| 570 | `graphics_round_rects` | 0 | 8.4s |  |
| 571 | `graphics_simple_shapes` | 0 | 6.8s |  |
| 572 | `greaterequals` | 512 | 9.3s |  |
| 573 | `greaterthan` | 512 | 9.4s |  |
| 574 | `has_own_property` | 102 | 7.2s |  |
| 575 | `hasownproperty_namespaces` | 2 | 6.7s |  |
| 576 | `hello_world` | 1 | 6.7s |  |
| 577 | `hittest_morph` | 30 | 6.8s |  |
| 578 | `id3_info` | 8 | 22.9s |  |
| 579 | `if_eq` | 10 | 6.7s |  |
| 580 | `if_gt` | 1 | 6.7s |  |
| 581 | `if_gte` | 10 | 2.3s |  |
| 582 | `if_lt` | 1 | 0.9s |  |
| 583 | `if_lte` | 10 | 6.6s |  |
| 584 | `if_ne` | 7 | 2.2s |  |
| 585 | `if_stricteq` | 6 | 6.7s |  |
| 586 | `if_strictne` | 11 | 6.8s |  |
| 587 | `ime_linux_dead_keys` | 10 | 23.3s |  |
| 588 | `in` | 102 | 7.2s |  |
| 589 | `inclocal` | 46 | 6.9s |  |
| 590 | `inclocal_i` | 46 | 6.9s |  |
| 591 | `increment` | 46 | 6.8s |  |
| 592 | `increment_i` | 46 | 6.8s |  |
| 593 | `indexing_delete` | 75 | 6.8s |  |
| 594 | `indexof_xml` | 10 | 6.8s |  |
| 595 | `init_callee_cached` | 24 | 6.8s |  |
| 596 | `instanceof` | 58 | 7.1s |  |
| 597 | `instantiate_root_character` | 4 | 7.0s |  |
| 598 | `instantiation_on_enter_frame` | 7 | 23.4s |  |
| 599 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.8s |  |
| 600 | `int_constr` | 92 | 6.9s |  |
| 601 | `int_edge_cases` | 19 | 6.9s |  |
| 602 | `int_instanceof` | 3 | 6.7s |  |
| 603 | `int_tofixed` | 1215 | 6.7s |  |
| 604 | `int_toprecision` | 1125 | 6.9s |  |
| 605 | `int_tostring` | 3375 | 7.0s |  |
| 606 | `interactiveobject_enabled` | 25 | 6.7s |  |
| 607 | `interface_namespaces` | 78 | 7.0s |  |
| 608 | `invalid_utf8` | 12 | 6.9s |  |
| 609 | `is_finite` | 46 | 6.8s |  |
| 610 | `is_nan` | 46 | 6.7s |  |
| 611 | `is_prototype_of` | 12 | 6.8s |  |
| 612 | `issue_10221` | 2 | 6.8s |  |
| 613 | `issue_13780` | 12 | 6.8s |  |
| 614 | `issue_14901` | 1 | 6.7s |  |
| 615 | `issue_17675_edittext_paste_maxchars` | 1 | 6.8s |  |
| 616 | `issue_5292` | 5 | 6.8s |  |
| 617 | `issue_8630` | 2 | 6.8s |  |
| 618 | `issue_8630_placeremoveplace` | 15 | 6.9s |  |
| 619 | `issue_8630_placeremoveplace_scriptremove` | 16 | 6.8s |  |
| 620 | `issue_8630_scriptremove` | 11 | 6.8s |  |
| 621 | `istype` | 24 | 2.4s |  |
| 622 | `istypelate` | 58 | 7.1s |  |
| 623 | `istypelate_coerce` | 198 | 7.6s |  |
| 624 | `jpeg_loader_context` | 6 | 6.7s |  |
| 625 | `json_errors` | 9 | 23.6s |  |
| 626 | `json_parse` | 21 | 6.9s |  |
| 627 | `json_parse_errors` | 84 | 6.8s |  |
| 628 | `json_stringify` | 12 | 23.5s |  |
| 629 | `json_stringify_function` | 12 | 6.7s |  |
| 630 | `json_stringify_order` | 1 | 6.8s |  |
| 631 | `json_version_gated` | 1 | 6.7s |  |
| 632 | `key_input_80percent` | 1812 | 23.2s |  |
| 633 | `key_input_location` | 126 | 6.8s |  |
| 634 | `key_input_numpad` | 384 | 6.7s |  |
| 635 | `large_preload_from_bytes` | 51 | 9.7s |  |
| 636 | `large_preload_from_url` | 27 | 8.3s |  |
| 637 | `large_preload_image_from_bytes` | 25 | 8.5s |  |
| 638 | `lazyinit` | 17 | 6.7s |  |
| 639 | `lessequals` | 512 | 9.5s |  |
| 640 | `lessthan` | 512 | 9.5s |  |
| 641 | `loader_bitmap_transparency` | 14 | 6.8s |  |
| 642 | `loader_bytes_unknown_content` | 14 | 6.8s |  |
| 643 | `loader_child_getdefinition` | 5 | 6.9s |  |
| 644 | `loader_duplicate_class` | 48 | 8.1s |  |
| 645 | `loader_duplicate_coerce` | 3 | 6.8s |  |
| 646 | `loader_duplicate_coerce_new_domain` | 4 | 6.8s |  |
| 647 | `loader_error_in_root_ctor` | 4 | 6.8s |  |
| 648 | `loader_events` | 92 | 9.0s |  |
| 649 | `loader_image` | 8 | 7.0s |  |
| 650 | `loader_jpegxr` | 2 | 25.0s |  |
| 651 | `loader_jpegxr_alpha` | 1 | 23.1s |  |
| 652 | `loader_loadbytes_events` | 30 | 7.2s |  |
| 653 | `loader_loadbytes_invalid_png` | 4 | 6.8s |  |
| 654 | `loader_loadbytes_url` | 12 | 7.1s |  |
| 655 | `loader_loaderurl` | 6 | 7.2s |  |
| 656 | `loader_method` | 85 | 6.8s |  |
| 657 | `loader_noninteractive_try_click_root` | 5 | 23.3s |  |
| 658 | `loader_reuse` | 38 | 6.9s |  |
| 659 | `loader_try_click_root` | 16 | 6.9s |  |
| 660 | `loader_unknown_content` | 24 | 6.9s |  |
| 661 | `loader_unloadandstop_subclass` | 1 | 6.7s |  |
| 662 | `loader_visibility_interactive` | 1 | 6.8s |  |
| 663 | `loaderinfo_child_progress` | 9 | 7.1s |  |
| 664 | `loaderinfo_events` | 7 | 6.7s |  |
| 665 | `loaderinfo_loadurl` | 12 | 6.7s |  |
| 666 | `loaderinfo_more` | 6 | 6.8s |  |
| 667 | `loaderinfo_properties` | 18 | 23.1s |  |
| 668 | `loaderinfo_properties_not_loaded` | 23 | 6.8s |  |
| 669 | `loaderinfo_quine` | 1005 | 24.1s |  |
| 670 | `loaderinfo_root` | 10 | 7.6s |  |
| 671 | `loaderinfo_root_allows` | 2 | 7.6s |  |
| 672 | `localconnection` | 890 | 10.3s |  |
| 673 | `localconnection_send` | 4 | 7.5s |  |
| 674 | `lshift` | 1058 | 16.2s |  |
| 675 | `mask_reapply` | 1 | 24.5s |  |
| 676 | `math` | 497 | 7.8s |  |
| 677 | `matrix` | 338 | 16.5s |  |
| 678 | `matrix3d` | 57 | 25.5s |  |
| 679 | `matrix3d_append` | 16 | 7.7s |  |
| 680 | `matrix3d_append_prepend_scale` | 86 | 8.0s |  |
| 681 | `matrix3d_append_prepend_translation` | 42 | 7.9s |  |
| 682 | `matrix3d_append_rotation` | 23 | 7.9s |  |
| 683 | `matrix3d_compose` | 34 | 8.3s |  |
| 684 | `matrix3d_constructor_clone` | 15 | 8.0s |  |
| 685 | `matrix3d_copy_column` | 83 | 8.1s |  |
| 686 | `matrix3d_copy_from` | 19 | 8.2s |  |
| 687 | `matrix3d_copy_raw_data_from` | 55 | 3.1s |  |
| 688 | `matrix3d_copy_raw_data_to` | 38 | 7.7s |  |
| 689 | `matrix3d_copy_row` | 83 | 7.5s |  |
| 690 | `matrix3d_copy_to_matrix3d` | 19 | 7.6s |  |
| 691 | `matrix3d_determinant` | 182 | 7.7s |  |
| 692 | `matrix3d_interpolate` | 21 | 7.7s |  |
| 693 | `matrix3d_invert` | 18 | 7.5s |  |
| 694 | `matrix3d_position` | 19 | 7.7s |  |
| 695 | `matrix3d_precision` | 28 | 8.4s |  |
| 696 | `matrix3d_prepend` | 16 | 7.5s |  |
| 697 | `matrix3d_raw_data` | 33 | 7.8s |  |
| 698 | `matrix3d_transform_vector` | 52 | 8.7s |  |
| 699 | `matrix3d_transpose` | 5 | 7.9s |  |
| 700 | `method_association` | 5 | 7.7s |  |
| 701 | `method_without_body` | 3 | 24.6s |  |
| 702 | `missing_external_interface` | 10 | 7.9s |  |
| 703 | `modulo` | 1058 | 16.1s |  |
| 704 | `morph_shape` | 2 | 24.6s |  |
| 705 | `mouse_children` | 192 | 24.6s |  |
| 706 | `mouse_click_events` | 90 | 24.3s |  |
| 707 | `mouse_double_click_events` | 188 | 7.6s |  |
| 708 | `mouse_empty_parent` | 4 | 8.0s |  |
| 709 | `mouse_over_while_dragging` | 3 | 8.2s |  |
| 710 | `mouse_pick_avm1_root` | 2 | 22.6s |  |
| 711 | `mouse_pick_button_mode` | 2 | 22.4s |  |
| 712 | `mouse_pick_dobj_mask` | 4 | 6.9s |  |
| 713 | `mouse_pick_loader_avm1` | 42 | 6.8s |  |
| 714 | `mouse_pick_masking` | 7 | 22.6s |  |
| 715 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 22.8s |  |
| 716 | `mouse_pick_non_interactive_dobj_mask` | 3 | 6.8s |  |
| 717 | `mouse_pick_scroll_rect` | 27 | 23.0s |  |
| 718 | `mouse_pick_scroll_rect_button` | 5 | 6.8s |  |
| 719 | `mouse_pick_scroll_rect_loader` | 5 | 6.9s |  |
| 720 | `mouse_pick_text` | 8 | 6.7s |  |
| 721 | `mouse_sibling` | 8 | 6.6s |  |
| 722 | `mouse_wheel_events` | 36 | 23.4s |  |
| 723 | `mouseevent_constr` | 66 | 6.6s |  |
| 724 | `mouseevent_stagexy` | 35 | 6.7s |  |
| 725 | `mouseevent_valueof_tostring` | 28 | 6.6s |  |
| 726 | `movieclip_addframescript` | 3 | 22.9s |  |
| 727 | `movieclip_addframescript_error` | 9 | 6.7s |  |
| 728 | `movieclip_child_property` | 16 | 6.7s |  |
| 729 | `movieclip_constr` | 21 | 6.7s |  |
| 730 | `movieclip_currentlabels` | 17 | 22.9s |  |
| 731 | `movieclip_currentlabels_dupes1` | 46 | 22.9s |  |
| 732 | `movieclip_currentlabels_dupes2` | 30 | 6.7s |  |
| 733 | `movieclip_currentlabels_dupes3` | 67 | 6.7s |  |
| 734 | `movieclip_currentscene` | 12 | 22.6s |  |
| 735 | `movieclip_dispatchevent` | 430 | 6.7s |  |
| 736 | `movieclip_dispatchevent_cancel` | 102 | 6.8s |  |
| 737 | `movieclip_dispatchevent_handlerorder` | 251 | 6.7s |  |
| 738 | `movieclip_dispatchevent_selfadd` | 80 | 6.6s |  |
| 739 | `movieclip_dispatchevent_target` | 899 | 6.7s |  |
| 740 | `movieclip_displayevents` | 96 | 22.7s |  |
| 741 | `movieclip_displayevents_clickgoto` | 676 | 22.9s |  |
| 742 | `movieclip_displayevents_clickgoto2` | 2001 | 7.1s |  |
| 743 | `movieclip_displayevents_clickplay` | 575 | 6.8s |  |
| 744 | `movieclip_displayevents_clicksymbol` | 562 | 6.8s |  |
| 745 | `movieclip_displayevents_constructframegoto` | 140 | 6.8s |  |
| 746 | `movieclip_displayevents_constructframeplay` | 50 | 6.7s |  |
| 747 | `movieclip_displayevents_constructframesymbol` | 144 | 6.8s |  |
| 748 | `movieclip_displayevents_dblhandler` | 21 | 6.5s |  |
| 749 | `movieclip_displayevents_enterframegoto` | 149 | 6.8s |  |
| 750 | `movieclip_displayevents_enterframeplay` | 48 | 6.7s |  |
| 751 | `movieclip_displayevents_enterframesymbol` | 149 | 22.6s |  |
| 752 | `movieclip_displayevents_exitframegoto` | 106 | 6.7s |  |
| 753 | `movieclip_displayevents_exitframeplay` | 44 | 6.7s |  |
| 754 | `movieclip_displayevents_exitframesymbol` | 135 | 22.8s |  |
| 755 | `movieclip_displayevents_looping` | 63 | 23.0s |  |
| 756 | `movieclip_displayevents_stopped` | 113 | 22.9s |  |
| 757 | `movieclip_displayevents_swap` | 96 | 6.8s |  |
| 758 | `movieclip_displayevents_timeline` | 128 | 23.0s |  |
| 759 | `movieclip_drawrect` | 54 | 22.5s |  |
| 760 | `movieclip_frameconstruct_skipped` | 9 | 6.5s |  |
| 761 | `movieclip_goto_during_frame_script` | 15 | 22.2s |  |
| 762 | `movieclip_goto_overwrite` | 14 | 22.3s |  |
| 763 | `movieclip_goto_scene_last_frame_int` | 1 | 22.2s |  |
| 764 | `movieclip_goto_scene_last_frame_label` | 1 | 6.4s |  |
| 765 | `movieclip_gotoandplay` | 15 | 22.4s |  |
| 766 | `movieclip_gotoandstop` | 13 | 6.5s |  |
| 767 | `movieclip_gotoandstop_children` | 4 | 6.6s |  |
| 768 | `movieclip_gotoandstop_framescripts1` | 4 | 6.5s |  |
| 769 | `movieclip_gotoandstop_framescripts2` | 4 | 2.1s |  |
| 770 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.3s |  |
| 771 | `movieclip_gotoandstop_queueing` | 12 | 6.6s |  |
| 772 | `movieclip_hittest` | 67 | 6.7s |  |
| 773 | `movieclip_next_frame` | 2 | 6.6s |  |
| 774 | `movieclip_next_scene` | 6 | 6.6s |  |
| 775 | `movieclip_play` | 3 | 6.5s |  |
| 776 | `movieclip_prev_frame` | 3 | 6.4s |  |
| 777 | `movieclip_prev_scene` | 7 | 6.5s |  |
| 778 | `movieclip_properties` | 79 | 22.5s |  |
| 779 | `movieclip_queued_noop_goto_swf10` | 9 | 6.5s |  |
| 780 | `movieclip_queued_noop_goto_swf9` | 7 | 0.9s |  |
| 781 | `movieclip_scenes` | 11 | 6.4s |  |
| 782 | `movieclip_soundtransform` | 831 | 23.6s |  |
| 783 | `movieclip_stop` | 1 | 6.4s |  |
| 784 | `movieclip_super_is_symbol` | 20 | 6.7s |  |
| 785 | `movieclip_symbol_constr` | 8 | 6.5s |  |
| 786 | `movieclip_text_mousedown` | 1 | 6.5s |  |
| 787 | `movieclip_willtrigger` | 5 | 6.6s |  |
| 788 | `multiply` | 1058 | 13.5s |  |
| 789 | `namespace_constr` | 253 | 6.8s |  |
| 790 | `namespace_constr_args` | 1 | 6.4s |  |
| 791 | `namespace_enumeration_order` | 7 | 22.2s |  |
| 792 | `nan_scale` | 9 | 6.5s |  |
| 793 | `native_menu_basic` | 19 | 8.4s |  |
| 794 | `navigateToURL_target_normalize` | 107 | 23.9s |  |
| 795 | `negate` | 30 | 6.5s |  |
| 796 | `negative_volume_panned` | 0 | 6.6s |  |
| 797 | `nested_iteration` | 11 | 6.5s |  |
| 798 | `net_getClassByAlias` | 3 | 23.0s |  |
| 799 | `net_navigateToURL` | 57 | 24.4s |  |
| 800 | `net_stream_play_options` | 6 | 6.7s |  |
| 801 | `netconnection_call_with_responder` | 6 | 22.5s |  |
| 802 | `netconnection_close` | 55 | 22.4s |  |
| 803 | `netconnection_properties` | 78 | 6.6s |  |
| 804 | `netconnection_send_remote` | 50 | 6.7s |  |
| 805 | `netconnection_serialize_arrays` | 6 | 6.5s |  |
| 806 | `netfilterevent` | 10 | 6.5s |  |
| 807 | `netstream_client` | 10 | 6.7s |  |
| 808 | `netstream_connect` | 7 | 6.5s |  |
| 809 | `netstream_flv_date` | 4 | 6.6s |  |
| 810 | `newactivation_in_script_init` | 3 | 6.5s |  |
| 811 | `newclass_mismatched` | 4 | 6.5s |  |
| 812 | `newclass_twice` | 3 | 6.5s |  |
| 813 | `nonconflicting_declarations` | 0 | 6.6s |  |
| 814 | `null_void_types` | 8 | 6.6s |  |
| 815 | `number_autoconv` | 21 | 6.7s |  |
| 816 | `number_autoconv_amf` | 132 | 6.5s |  |
| 817 | `number_autoconv_array_sort_32bit` | 1 | 6.5s |  |
| 818 | `number_constr` | 58 | 6.5s |  |
| 819 | `number_convert_edge_cases` | 180 | 22.2s |  |
| 820 | `number_toexponential` | 378 | 6.6s |  |
| 821 | `number_toexponential2` | 35 | 6.5s |  |
| 822 | `number_tofixed` | 378 | 6.4s |  |
| 823 | `number_toprecision` | 350 | 6.5s |  |
| 824 | `obfuscated_class_names` | 3 | 6.5s |  |
| 825 | `object_enumeration` | 10 | 6.5s |  |
| 826 | `object_prototype` | 4 | 6.5s |  |
| 827 | `object_to_locale_string` | 2 | 6.5s |  |
| 828 | `object_to_string` | 2 | 6.3s |  |
| 829 | `object_value_of` | 2 | 2.0s |  |
| 830 | `op_coerce` | 54 | 6.5s |  |
| 831 | `op_coerce_x` | 54 | 6.5s |  |
| 832 | `op_escxattr` | 2 | 6.4s |  |
| 833 | `op_escxelem` | 2 | 6.5s |  |
| 834 | `op_lookupswitch` | 4 | 6.5s |  |
| 835 | `optimize_coerce` | 1 | 6.4s |  |
| 836 | `orphan_movie_complex` | 80 | 22.7s |  |
| 837 | `orphan_movie_reorder` | 111 | 23.2s |  |
| 838 | `orphan_removeobject` | 636 | 23.5s |  |
| 839 | `package_namespace` | 7 | 23.1s |  |
| 840 | `param_default_value_has_zero_cpool_index` | 1 | 7.7s |  |
| 841 | `parent_early_access_child` | 16 | 22.4s |  |
| 842 | `parse_float` | 81 | 7.8s |  |
| 843 | `parse_float_swf10` | 81 | 7.8s |  |
| 844 | `parse_int` | 135 | 8.0s |  |
| 845 | `perspective_projection` | 1443 | 22.7s |  |
| 846 | `perspective_projection_basic` | 40 | 7.8s |  |
| 847 | `pixelbender_ceil` | 77 | 7.9s |  |
| 848 | `pixelbender_conditional` | 138 | 8.1s |  |
| 849 | `pixelbender_conversions` | 270 | 8.4s |  |
| 850 | `pixelbender_dithering` | 8 | 28.8s |  |
| 851 | `pixelbender_div` | 36 | 7.9s |  |
| 852 | `pixelbender_effect_BlurredFocus` | 0 | 26.5s |  |
| 853 | `pixelbender_effect_glassDisplace` | 0 | 12.2s |  |
| 854 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 24.6s |  |
| 855 | `pixelbender_effect_smudge` | 0 | 10.0s |  |
| 856 | `pixelbender_effect_tintype` | 0 | 9.6s |  |
| 857 | `pixelbender_effect_twirl` | 0 | 10.9s |  |
| 858 | `pixelbender_eof` | 7 | 7.4s |  |
| 859 | `pixelbender_images` | 0 | 9.2s |  |
| 860 | `pixelbender_input` | 103 | 23.2s |  |
| 861 | `pixelbender_logicalnot` | 20 | 7.5s |  |
| 862 | `pixelbender_malformed_data` | 190 | 21.3s |  |
| 863 | `pixelbender_multiple_out_params` | 1 | 7.4s |  |
| 864 | `pixelbender_no_out_param` | 6 | 7.1s |  |
| 865 | `pixelbender_outputs` | 13 | 7.7s |  |
| 866 | `pixelbender_padding_bytes` | 22 | 7.2s |  |
| 867 | `pixelbender_param_qualifier` | 512 | 7.2s |  |
| 868 | `pixelbender_parameters` | 1563 | 7.6s |  |
| 869 | `pixelbender_parameters_bool` | 240 | 7.5s |  |
| 870 | `pixelbender_parameters_int_vs_bool` | 54 | 7.4s |  |
| 871 | `pixelbender_parse_errors` | 6 | 7.3s |  |
| 872 | `pixelbender_rsqrt` | 24 | 7.5s |  |
| 873 | `pixelbender_select_kinds` | 8 | 7.8s |  |
| 874 | `pixelbender_shaderdata` | 49 | 7.4s |  |
| 875 | `pixelbender_shaderdata_setter` | 99 | 8.0s |  |
| 876 | `pixelbender_sign` | 60 | 7.6s |  |
| 877 | `pixelbender_vector_output` | 11 | 7.4s |  |
| 878 | `place_and_lookup/swf10` | 33 | 7.5s |  |
| 879 | `place_and_lookup/swf9` | 33 | 22.9s |  |
| 880 | `place_multiple` | 17 | 22.9s |  |
| 881 | `place_object_replace` | 9 | 23.2s |  |
| 882 | `place_object_replace_2` | 24 | 23.2s |  |
| 883 | `place_object_same_depth_frame` | 1 | 6.9s |  |
| 884 | `point` | 132 | 7.2s |  |
| 885 | `primitive_edge_cases` | 1 | 6.7s |  |
| 886 | `primitive_keys` | 54 | 6.7s |  |
| 887 | `primitive_toString` | 277 | 6.8s |  |
| 888 | `primitive_valueOf` | 285 | 6.6s |  |
| 889 | `print_job_options` | 3 | 6.7s |  |
| 890 | `property_is_enumerable` | 114 | 7.5s |  |
| 891 | `property_is_enumerable_reset` | 23 | 6.6s |  |
| 892 | `property_priority` | 22 | 6.9s |  |
| 893 | `property_priority_chained` | 4 | 6.6s |  |
| 894 | `property_priority_definition_names_order` | 2 | 6.8s |  |
| 895 | `property_priority_three_level` | 6 | 6.8s |  |
| 896 | `propertyisenumerable_namespaces` | 6 | 6.6s |  |
| 897 | `prototype_set_null` | 7 | 6.6s |  |
| 898 | `proxy_callproperty` | 24 | 6.7s |  |
| 899 | `proxy_deleteproperty` | 64 | 6.8s |  |
| 900 | `proxy_enumeration` | 34 | 6.7s |  |
| 901 | `proxy_getproperty` | 77 | 6.9s |  |
| 902 | `proxy_hasownproperty` | 8 | 6.7s |  |
| 903 | `proxy_hasproperty` | 32 | 6.9s |  |
| 904 | `proxy_not_overridden` | 54 | 6.8s |  |
| 905 | `proxy_serialize` | 9 | 6.8s |  |
| 906 | `proxy_setproperty` | 42 | 6.8s |  |
| 907 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.7s |  |
| 908 | `qname_constr` | 32 | 6.8s |  |
| 909 | `qname_constr_namespace` | 24 | 6.8s |  |
| 910 | `qname_enumeration` | 9 | 6.8s |  |
| 911 | `qname_indexing` | 23 | 6.8s |  |
| 912 | `qname_tostring` | 25 | 6.9s |  |
| 913 | `qname_valueof` | 29 | 6.8s |  |
| 914 | `rectangle` | 1094 | 7.3s |  |
| 915 | `regexp_constr` | 148 | 7.0s |  |
| 916 | `regexp_exec` | 19 | 6.7s |  |
| 917 | `regexp_extended` | 47 | 6.7s |  |
| 918 | `regexp_multiargs` | 1 | 6.6s |  |
| 919 | `regexp_test` | 27 | 6.7s |  |
| 920 | `regexp_toString` | 10 | 6.6s |  |
| 921 | `register_script_refresh` | 35 | 23.9s |  |
| 922 | `remove_child_clear_field` | 88 | 32.1s |  |
| 923 | `remove_dobj` | 3 | 31.4s |  |
| 924 | `resolve_order` | 4 | 9.7s |  |
| 925 | `responder_null_callbacks` | 1 | 31.4s |  |
| 926 | `rng` | 1 | 11.1s |  |
| 927 | `rootless` | 42 | 9.8s |  |
| 928 | `rshift` | 1058 | 21.0s |  |
| 929 | `rtqname_not_namespace` | 12 | 9.6s |  |
| 930 | `sandbox_type_inherited` | 2 | 10.1s |  |
| 931 | `sandbox_type_local_file` | 1 | 9.7s |  |
| 932 | `sandbox_type_local_network` | 1 | 9.6s |  |
| 933 | `scene_constr` | 8 | 10.1s |  |
| 934 | `scope_optimizations` | 4 | 9.9s |  |
| 935 | `scopes_dont_cache/order-1` | 1 | 32.1s |  |
| 936 | `scopes_dont_cache/order-2` | 1 | 1.2s |  |
| 937 | `security_domain_current` | 2 | 9.8s |  |
| 938 | `selection` | 239 | 10.7s |  |
| 939 | `selection_onsetfocus_mixed_avm` | 5 | 31.9s |  |
| 940 | `set_local_0` | 31 | 9.8s |  |
| 941 | `set_property_is_enumerable` | 85 | 10.4s |  |
| 942 | `shaderparameter_value` | 4 | 9.8s |  |
| 943 | `shape_drawrect` | 54 | 10.0s |  |
| 944 | `shared_object_no_root` | 3 | 9.9s |  |
| 945 | `simplebutton_added_to_stage` | 45 | 32.8s |  |
| 946 | `simplebutton_childevents` | 86 | 33.3s |  |
| 947 | `simplebutton_childevents_nested` | 54 | 10.5s |  |
| 948 | `simplebutton_childevents_sprite` | 13 | 10.0s |  |
| 949 | `simplebutton_childprops` | 144 | 10.3s |  |
| 950 | `simplebutton_childshuffle` | 23 | 9.7s |  |
| 951 | `simplebutton_constr` | 36 | 10.2s |  |
| 952 | `simplebutton_constr_childevents` | 48 | 10.4s |  |
| 953 | `simplebutton_constr_params` | 42 | 10.2s |  |
| 954 | `simplebutton_mouseenabled` | 26 | 9.7s |  |
| 955 | `simplebutton_multi_children` | 19 | 10.3s |  |
| 956 | `simplebutton_soundtransform` | 887 | 34.7s |  |
| 957 | `simplebutton_structure` | 27 | 10.2s |  |
| 958 | `simplebutton_symbolclass` | 68 | 10.2s |  |
| 959 | `slot_disp_id_shared_numbering` | 1 | 32.5s |  |
| 960 | `slots_force_autoassigned` | 1 | 21.2s |  |
| 961 | `socket_after_disconnect` | 1 | 21.2s |  |
| 962 | `socket_close` | 2 | 5.3s |  |
| 963 | `socket_connect` | 4 | 5.3s |  |
| 964 | `socket_errors` | 56 | 5.3s |  |
| 965 | `socket_read_big` | 48 | 5.3s |  |
| 966 | `socket_read_little` | 48 | 0.9s |  |
| 967 | `socket_read_write_object` | 8 | 5.3s |  |
| 968 | `socket_write_big` | 15 | 5.3s |  |
| 969 | `socket_write_little` | 14 | 5.3s |  |
| 970 | `sound_constructor_with_args` | 6 | 5.3s |  |
| 971 | `sound_embeddedprops` | 26 | 5.3s |  |
| 972 | `sound_load_multiple` | 19 | 5.4s |  |
| 973 | `sound_play` | 19 | 5.3s |  |
| 974 | `sound_rootless` | 7 | 5.3s |  |
| 975 | `sound_valueof` | 33 | 5.3s |  |
| 976 | `soundchannel_soundtransform` | 835 | 21.3s |  |
| 977 | `soundchannel_soundtransform_exists` | 5 | 21.5s |  |
| 978 | `soundchannel_stop` | 8 | 21.6s |  |
| 979 | `soundmixer_buffertime` | 5 | 5.4s |  |
| 980 | `soundmixer_soundtransform` | 900 | 5.5s |  |
| 981 | `soundmixer_stopall` | 6 | 21.9s |  |
| 982 | `soundtransform` | 442 | 5.4s |  |
| 983 | `space_justifier_clone` | 12 | 5.3s |  |
| 984 | `sprite_with_frames` | 0 | 23.6s |  |
| 985 | `stage3d_agal_cross_product` | 0 | 5.6s |  |
| 986 | `stage3d_agal_upload_errors` | 66 | 7.0s |  |
| 987 | `stage3d_bitmap` | 0 | 22.0s |  |
| 988 | `stage3d_blend` | 81 | 24.2s |  |
| 989 | `stage3d_context3d_string_args` | 158 | 5.3s |  |
| 990 | `stage3d_errors` | 7 | 5.3s |  |
| 991 | `stage3d_errors_atf` | 3 | 5.3s |  |
| 992 | `stage3d_errors_swf_29` | 6 | 5.3s |  |
| 993 | `stage3d_float1_index` | 0 | 21.5s |  |
| 994 | `stage3d_fractal` | 0 | 22.2s |  |
| 995 | `stage3d_ignore_sampler_override` | 0 | 21.8s |  |
| 996 | `stage3d_multistage_triangle` | 3 | 5.5s |  |
| 997 | `stage3d_program_constants_bytearray_be` | 0 | 21.7s |  |
| 998 | `stage3d_program_constants_bytearray_le` | 0 | 5.5s |  |
| 999 | `stage3d_program_constants_invalid_input` | 21 | 5.3s |  |
| 1000 | `stage3d_raytrace` | 0 | 48.6s |  |
| 1001 | `stage3d_rotating_cube` | 0 | 11.5s |  |
| 1002 | `stage3d_sampler` | 0 | 9.3s |  |
| 1003 | `stage3d_sampler_partial_upload` | 0 | 9.3s |  |
| 1004 | `stage3d_stencil` | 0 | 26.1s |  |
| 1005 | `stage3d_texture` | 0 | 14.0s |  |
| 1006 | `stage3d_texture_bytearray` | 0 | 10.0s |  |
| 1007 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.5s |  |
| 1008 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.3s |  |
| 1009 | `stage3d_triangle` | 0 | 9.0s |  |
| 1010 | `stage3d_triangle_bytes4` | 0 | 9.1s |  |
| 1011 | `stage3d_triangle_float1` | 0 | 9.1s |  |
| 1012 | `stage3d_triangle_index_upload` | 0 | 9.0s |  |
| 1013 | `stage3d_x_y` | 22 | 6.7s |  |
| 1014 | `stage_access` | 10 | 6.8s |  |
| 1015 | `stage_display_state` | 6 | 6.7s |  |
| 1016 | `stage_displayobject_properties` | 24 | 6.6s |  |
| 1017 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.6s |  |
| 1018 | `stage_framerate_nan` | 7 | 22.9s |  |
| 1019 | `stage_framerate_negative` | 6 | 6.7s |  |
| 1020 | `stage_framerate_zero` | 6 | 6.7s |  |
| 1021 | `stage_invalidate` | 38 | 6.8s |  |
| 1022 | `stage_loaderinfo_properties` | 24 | 23.0s |  |
| 1023 | `stage_mousechildren` | 2 | 6.6s |  |
| 1024 | `stage_mouseenabled` | 15 | 6.6s |  |
| 1025 | `stage_overriden_setters` | 31 | 6.7s |  |
| 1026 | `stage_properties` | 30 | 6.7s |  |
| 1027 | `stage_properties2` | 213 | 6.8s |  |
| 1028 | `stage_scale_factor` | 12 | 27.2s |  |
| 1029 | `stage_stage3Ds_vector` | 1 | 6.7s |  |
| 1030 | `static_length` | 24 | 6.8s |  |
| 1031 | `static_text` | 3 | 6.8s |  |
| 1032 | `static_var_with_this_in_ctor` | 2 | 6.6s |  |
| 1033 | `statictext_text` | 8 | 6.8s |  |
| 1034 | `stored_properties` | 11 | 6.7s |  |
| 1035 | `strict_equality` | 34 | 6.7s |  |
| 1036 | `string_call` | 13 | 6.6s |  |
| 1037 | `string_case` | 23 | 6.7s |  |
| 1038 | `string_char_at` | 27 | 6.6s |  |
| 1039 | `string_char_code_at` | 28 | 6.6s |  |
| 1040 | `string_concat_fromcharcode` | 37 | 6.6s |  |
| 1041 | `string_constr` | 25 | 6.6s |  |
| 1042 | `string_indexof_lastindexof` | 87 | 6.7s |  |
| 1043 | `string_length` | 16 | 6.6s |  |
| 1044 | `string_locale_compare` | 39 | 22.8s |  |
| 1045 | `string_match` | 51 | 22.9s |  |
| 1046 | `string_relational_compare` | 4 | 6.5s |  |
| 1047 | `string_replace` | 51 | 6.7s |  |
| 1048 | `string_search` | 41 | 6.7s |  |
| 1049 | `string_slice_substr_substring` | 170 | 7.4s |  |
| 1050 | `string_split` | 29 | 6.7s |  |
| 1051 | `string_substr_negative` | 21 | 6.6s |  |
| 1052 | `string_substr_weird` | 182 | 6.6s |  |
| 1053 | `stylesheet` | 221 | 7.2s |  |
| 1054 | `stylesheet_parse_color` | 69 | 6.6s |  |
| 1055 | `stylesheet_transform` | 307 | 6.9s |  |
| 1056 | `sub_super_same_field` | 12 | 2.2s |  |
| 1057 | `subclass_superclass_linked_symbol` | 4 | 7.0s |  |
| 1058 | `subtract` | 1058 | 13.8s |  |
| 1059 | `super_get_call` | 12 | 6.6s |  |
| 1060 | `supercall_two_classobjects` | 2 | 6.6s |  |
| 1061 | `supercalls_coerce` | 8 | 6.6s |  |
| 1062 | `supercalls_weird` | 2 | 6.5s |  |
| 1063 | `superinterface_call` | 20 | 6.6s |  |
| 1064 | `superinterface_instanceof` | 18 | 6.6s |  |
| 1065 | `swf8` | 1 | 6.5s |  |
| 1066 | `swf_10_queued_goto_scripts_construct` | 52 | 22.7s |  |
| 1067 | `swf_9_goto_in_enter_frame` | 17 | 6.8s |  |
| 1068 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.8s |  |
| 1069 | `swf_9_queued_goto_scripts` | 6 | 22.8s |  |
| 1070 | `swf_9_queued_goto_scripts_construct` | 28 | 0.9s |  |
| 1071 | `swf_9_versioning` | 2 | 6.6s |  |
| 1072 | `swf_wrong_frame_count` | 38 | 6.9s |  |
| 1073 | `swf_wrong_frame_count_isplaying` | 22 | 6.6s |  |
| 1074 | `symbol_class_binary_data` | 8 | 6.6s |  |
| 1075 | `symbol_class_conflict` | 4 | 8.6s |  |
| 1076 | `symbol_class_root_not_zero` | 1 | 6.6s |  |
| 1077 | `symbolclass_invalid_utf8` | 2 | 6.6s |  |
| 1078 | `system_exit` | 3 | 6.6s |  |
| 1079 | `system_setclipboard_null` | 1 | 6.6s |  |
| 1080 | `tab_ordering_arrows` | 998 | 23.9s |  |
| 1081 | `tab_ordering_automatic_advanced` | 184 | 7.2s |  |
| 1082 | `tab_ordering_automatic_basic` | 45 | 6.7s |  |
| 1083 | `tab_ordering_children` | 116 | 6.9s |  |
| 1084 | `tab_ordering_custom_basic` | 34 | 6.7s |  |
| 1085 | `tab_ordering_properties` | 732 | 7.0s |  |
| 1086 | `tab_ordering_stage_tab_children` | 32 | 30.3s |  |
| 1087 | `tab_ordering_stage_tab_children_remove_root` | 5 | 8.8s |  |
| 1088 | `tab_ordering_tabbable` | 47 | 9.0s |  |
| 1089 | `tabstop_properties` | 105 | 30.7s |  |
| 1090 | `text_element_basic` | 34 | 9.1s |  |
| 1091 | `text_engine_fontdescription` | 27 | 9.1s |  |
| 1092 | `text_engine_groupelement` | 64 | 10.1s |  |
| 1093 | `text_run` | 7 | 9.1s |  |
| 1094 | `textblock_createline_errors` | 23 | 9.4s |  |
| 1095 | `textblock_createline_fte` | 9 | 31.6s |  |
| 1096 | `textblock_properties` | 118 | 9.7s |  |
| 1097 | `textbox_click` | 37 | 31.6s |  |
| 1098 | `textfield_event` | 66 | 9.5s |  |
| 1099 | `textfield_focusin_event` | 9 | 9.0s |  |
| 1100 | `textfield_input_dead_keys_windows` | 15 | 9.0s |  |
| 1101 | `textfield_input_events` | 25 | 27.9s |  |
| 1102 | `textfield_unload` | 39 | 30.7s |  |
| 1103 | `textformat` | 1134 | 9.0s |  |
| 1104 | `textformat_display` | 14 | 9.0s |  |
| 1105 | `textformat_font_max_length` | 4 | 8.9s |  |
| 1106 | `textjustifier_locale` | 132 | 9.2s |  |
| 1107 | `textline_has_tabs` | 47 | 9.0s |  |
| 1108 | `textline_inapplicable_properties` | 10 | 8.9s |  |
| 1109 | `textline_name` | 1 | 8.8s |  |
| 1110 | `textline_raw_text_length` | 30 | 9.0s |  |
| 1111 | `textline_splitting_basic` | 76 | 9.1s |  |
| 1112 | `textline_throwerror` | 30 | 8.9s |  |
| 1113 | `textline_validity` | 162 | 9.1s |  |
| 1114 | `throw` | 3 | 8.9s |  |
| 1115 | `timeline_scripts` | 3 | 30.3s |  |
| 1116 | `timer` | 90 | 10.4s |  |
| 1117 | `timer_events` | 3 | 8.9s |  |
| 1118 | `timer_finished` | 11 | 9.0s |  |
| 1119 | `timer_invalid_delay` | 30 | 9.0s |  |
| 1120 | `timer_reset` | 8 | 9.4s |  |
| 1121 | `timer_setdelay` | 5 | 9.2s |  |
| 1122 | `trace` | 12 | 22.7s |  |
| 1123 | `truthiness` | 30 | 6.6s |  |
| 1124 | `try_catch` | 11 | 6.8s |  |
| 1125 | `try_catch_typed` | 12 | 6.7s |  |
| 1126 | `typeof` | 30 | 6.7s |  |
| 1127 | `uint_constr` | 92 | 6.8s |  |
| 1128 | `uint_tofixed` | 1215 | 6.6s |  |
| 1129 | `uint_toprecision` | 1125 | 6.8s |  |
| 1130 | `uint_tostring` | 3375 | 6.9s |  |
| 1131 | `uncaught_error_basic` | 2 | 6.7s |  |
| 1132 | `unchecked_function` | 15 | 6.8s |  |
| 1133 | `unescape` | 28 | 6.8s |  |
| 1134 | `url_loader` | 25 | 7.0s |  |
| 1135 | `url_vars` | 27 | 7.0s |  |
| 1136 | `urlrequest` | 18 | 23.4s |  |
| 1137 | `urlstream_basic` | 5 | 6.8s |  |
| 1138 | `urshift` | 1058 | 14.2s |  |
| 1139 | `utils3d` | 7 | 6.7s |  |
| 1140 | `vector3d` | 397 | 9.7s |  |
| 1141 | `vector3d_near_equals` | 80 | 6.9s |  |
| 1142 | `vector_class` | 36 | 7.2s |  |
| 1143 | `vector_class_call` | 11 | 6.9s |  |
| 1144 | `vector_coercion` | 66 | 7.6s |  |
| 1145 | `vector_concat` | 90 | 7.4s |  |
| 1146 | `vector_constr` | 107 | 7.5s |  |
| 1147 | `vector_enumeration` | 5 | 6.7s |  |
| 1148 | `vector_every` | 92 | 7.4s |  |
| 1149 | `vector_filter` | 95 | 7.5s |  |
| 1150 | `vector_holes` | 24 | 6.9s |  |
| 1151 | `vector_indexof` | 302 | 9.9s |  |
| 1152 | `vector_insertat` | 270 | 7.8s |  |
| 1153 | `vector_int_access` | 4 | 6.8s |  |
| 1154 | `vector_int_delete` | 11 | 6.8s |  |
| 1155 | `vector_join` | 58 | 7.1s |  |
| 1156 | `vector_lastindexof` | 302 | 6.7s |  |
| 1157 | `vector_legacy` | 10 | 6.8s |  |
| 1158 | `vector_map` | 85 | 7.3s |  |
| 1159 | `vector_object_final` | 1 | 6.6s |  |
| 1160 | `vector_object_toString` | 10 | 6.7s |  |
| 1161 | `vector_prototype_some` | 125 | 6.9s |  |
| 1162 | `vector_pushpop` | 255 | 23.6s |  |
| 1163 | `vector_reborrow_bug` | 10 | 22.5s |  |
| 1164 | `vector_removeat` | 172 | 7.4s |  |
| 1165 | `vector_reverse` | 232 | 7.4s |  |
| 1166 | `vector_shiftunshift` | 252 | 6.5s |  |
| 1167 | `vector_slice` | 331 | 7.7s |  |
| 1168 | `vector_sort` | 905 | 13.3s |  |
| 1169 | `vector_splice` | 693 | 9.2s |  |
| 1170 | `vector_splice_fixed_bug_compat` | 4 | 6.5s |  |
| 1171 | `vector_tostring` | 79 | 7.1s |  |
| 1172 | `verification` | 8 | 6.7s |  |
| 1173 | `verify_abnormal_loop` | 1 | 6.5s |  |
| 1174 | `verify_dxns_without_flag` | 3 | 6.9s |  |
| 1175 | `verify_exception_target_two_jumps` | 1 | 6.5s |  |
| 1176 | `verify_exception_targets_edge_case` | 1 | 6.5s |  |
| 1177 | `verify_illegal_opcode` | 1 | 2.3s |  |
| 1178 | `verify_jump_to_middle_of_op` | 1 | 6.5s |  |
| 1179 | `verify_lookup_switch_edge_case` | 1 | 6.5s |  |
| 1180 | `verify_method_info_oob` | 1 | 0.8s |  |
| 1181 | `verify_stack` | 5 | 6.6s |  |
| 1182 | `verify_typecheck` | 4 | 6.6s |  |
| 1183 | `verify_unreachable_exception` | 2 | 6.5s |  |
| 1184 | `versioned_isplaying` | 2 | 6.5s |  |
| 1185 | `virtual_properties` | 16 | 6.6s |  |
| 1186 | `with` | 4 | 6.5s |  |
| 1187 | `wrong_arg_count` | 7 | 6.6s |  |
| 1188 | `xml_abstract_equality` | 36 | 6.8s |  |
| 1189 | `xml_advanced` | 52 | 6.5s |  |
| 1190 | `xml_appendchild` | 10 | 6.5s |  |
| 1191 | `xml_appendchild_swf_v21` | 13 | 6.7s |  |
| 1192 | `xml_as_attribute` | 9 | 6.5s |  |
| 1193 | `xml_attribute` | 35 | 6.8s |  |
| 1194 | `xml_attribute_name` | 40 | 6.7s |  |
| 1195 | `xml_basic` | 33 | 6.7s |  |
| 1196 | `xml_child` | 25 | 6.7s |  |
| 1197 | `xml_childindex` | 7 | 6.6s |  |
| 1198 | `xml_children` | 43 | 7.1s |  |
| 1199 | `xml_class_call` | 9 | 6.7s |  |
| 1200 | `xml_contains` | 197 | 6.7s |  |
| 1201 | `xml_copy` | 20 | 22.6s |  |
| 1202 | `xml_ctor_from_tostring` | 23 | 22.7s |  |
| 1203 | `xml_delete` | 114 | 6.5s |  |
| 1204 | `xml_descendants` | 83 | 6.5s |  |
| 1205 | `xml_duplicate_attribute` | 14 | 6.5s |  |
| 1206 | `xml_elements` | 6 | 6.3s |  |
| 1207 | `xml_equals_namespace_check` | 2 | 6.5s |  |
| 1208 | `xml_explicit_use_namespace` | 5 | 6.5s |  |
| 1209 | `xml_getdescendants_qname` | 21 | 6.5s |  |
| 1210 | `xml_has_property_via_in` | 26 | 6.5s |  |
| 1211 | `xml_hasownproperty` | 6 | 6.5s |  |
| 1212 | `xml_ignore_white` | 6 | 6.5s |  |
| 1213 | `xml_length` | 2 | 6.5s |  |
| 1214 | `xml_list_as_attribute` | 9 | 6.5s |  |
| 1215 | `xml_list_concat` | 20 | 6.4s |  |
| 1216 | `xml_list_ctor_errors` | 34 | 6.5s |  |
| 1217 | `xml_list_delete_clear_parent` | 6 | 6.5s |  |
| 1218 | `xml_list_enumerate` | 4 | 6.4s |  |
| 1219 | `xml_methods_settings` | 3 | 6.5s |  |
| 1220 | `xml_mismatched_tag` | 45 | 6.5s |  |
| 1221 | `xml_namespace` | 39 | 6.5s |  |
| 1222 | `xml_namespace_methods` | 245 | 6.5s |  |
| 1223 | `xml_namespaced_property` | 7 | 6.5s |  |
| 1224 | `xml_no_namespace` | 1 | 6.4s |  |
| 1225 | `xml_nodekind` | 3 | 6.4s |  |
| 1226 | `xml_normalize` | 35 | 6.6s |  |
| 1227 | `xml_notification_bubbling` | 361 | 6.5s |  |
| 1228 | `xml_parent` | 8 | 6.5s |  |
| 1229 | `xml_set_children` | 17 | 6.5s |  |
| 1230 | `xml_set_name` | 34 | 6.5s |  |
| 1231 | `xml_settings` | 6 | 2.1s |  |
| 1232 | `xml_simple_complex_content` | 47 | 6.5s |  |
| 1233 | `xml_socket` | 11 | 6.5s |  |
| 1234 | `xml_text` | 7 | 6.5s |  |
| 1235 | `xml_tostring` | 6 | 6.5s |  |
| 1236 | `xml_tostring_namespace` | 12 | 6.4s |  |
| 1237 | `xml_unescaping` | 23 | 6.5s |  |
| 1238 | `xml_weird_ignores` | 54 | 6.5s |  |
| 1239 | `xml_wildcard` | 11 | 6.5s |  |
| 1240 | `xmldocument` | 254 | 6.6s |  |
| 1241 | `xmlnode` | 3540 | 6.7s |  |
| 1242 | `zero_frame_clip` | 3 | 6.7s |  |

## Ruffle-Matched Tests

**42 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 7.9s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.1s |  |
| 3 | `blend_transform` | 1 | 1 | 35.9s |  |
| 4 | `bounds_mode` | 6 | 6 | 9.7s |  |
| 5 | `coerce_property` | 3 | 3 | 6.8s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.7s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 22.6s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 30.6s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 10.0s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 9.8s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 9.6s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 9.6s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.5s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 6.6s |  |
| 15 | `freestanding_superclass` | 2 | 4 | 6.7s |  |
| 16 | `goto_framescript_queued/swf13` | 3 | 3 | 23.3s |  |
| 17 | `gradient_values_readback` | 12 | 12 | 7.0s |  |
| 18 | `graphics_draw_path` | 50 | 50 | 24.0s |  |
| 19 | `groupelement_text` | 2 | 2 | 6.9s |  |
| 20 | `html_text_img_parsing` | 95 | 95 | 6.9s |  |
| 21 | `int_toexponential` | 76 | 76 | 6.9s |  |
| 22 | `json_parse_numbers` | 4 | 79 | 6.8s |  |
| 23 | `loader_events_2` | 30 | 30 | 7.1s |  |
| 24 | `matrix3d_recompose_edge_cases` | 8 | 85 | 8.2s |  |
| 25 | `number_convert_errors` | 706 | 706 | 6.7s |  |
| 26 | `number_to_string` | 104 | 104 | 6.9s |  |
| 27 | `simplebutton_childevents_multichild` | 101 | 101 | 10.1s |  |
| 28 | `simplebutton_childevents_script_order` | 4 | 4 | 10.2s |  |
| 29 | `slot_holes_fail` | 1 | 1 | 9.9s |  |
| 30 | `slot_id_exceeds_trait_count` | 1 | 1 | 9.8s |  |
| 31 | `soundchannel_position` | 74 | 74 | 21.4s |  |
| 32 | `soundchannel_soundcomplete` | 10 | 10 | 5.3s |  |
| 33 | `sprite_dropTarget` | 15 | 15 | 5.3s |  |
| 34 | `swf_9_goto_in_construct_frame` | 12 | 12 | 22.9s |  |
| 35 | `textblock_line_changes` | 44 | 44 | 10.0s |  |
| 36 | `textblock_recreateline` | 137 | 138 | 9.9s |  |
| 37 | `textblock_releaselines` | 4 | 4 | 11.1s |  |
| 38 | `textline_atom_index_at_char_index` | 3 | 3 | 10.0s |  |
| 39 | `uint_toexponential` | 100 | 100 | 6.8s |  |
| 40 | `uncaught_errors_stringified` | 15 | 15 | 6.8s |  |
| 41 | `vector_indexing_cutoffs` | 1 | 1 | 6.9s |  |
| 42 | `weird_superinterface_properties` | 1 | 1 | 6.5s |  |

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

**50 tests** with output mismatch, sorted by match rate (best first)

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
| 26 | `xml_unescaping_nul_char_ref` | 21.1% | 4/19 | 19 | 19 |  |
| 27 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 28 | `perspective_projection_center` | 17.6% | 6/34 | 26 | 34 |  |
| 29 | `context3d_draw_to_bitmap_data` | 13.3% | 2/15 | 11 | 15 |  |
| 30 | `vector_join_reentrant` | 10.4% | 10/96 | 84 | 96 |  |
| 31 | `array_sort_arguments` | 9.5% | 42/442 | 277 | 442 |  |
| 32 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 33 | `array_constructor` | 9.0% | 21/234 | 181 | 234 |  |
| 34 | `textfield_set_text_format_args` | 9.0% | 81/904 | 638 | 904 |  |
| 35 | `textfield_get_text_format_args` | 8.8% | 50/567 | 447 | 567 |  |
| 36 | `shared_object_get_local_error` | 4.8% | 1/21 | 5 | 21 |  |
| 37 | `bitmapdata_encode_png_roundtrip` | 3.0% | 1/33 | 4 | 33 |  |
| 38 | `worker_terminate` | 1.8% | 1/56 | 3 | 56 |  |
| 39 | `bitmapdata_encode` | 0.7% | 1/147 | 5 | 147 |  |
| 40 | `vector_sort_arguments` | 0.3% | 1/355 | 198 | 355 |  |
| 41 | `displayobjectcontainer_remove_reentrant` | 0.0% | 2/27942 | 27942 | 257 |  |
| 42 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 43 | `bitmapdata_encode_jpeg_visual` | 0.0% | 0/3 | 3 | 0 |  |
| 44 | `bitmapdata_encode_png_visual` | 0.0% | 0/3 | 3 | 0 |  |
| 45 | `edittext_event_link_case_insensitive` | 0.0% | 0/1 | 0 | 1 |  |
| 46 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 47 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 48 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 49 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 50 | `textline_metrics` | 0.0% | 0/20 | 20 | 20 |  |
