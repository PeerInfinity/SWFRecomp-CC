# Ruffle Test Results (Filtered)

**Date**: 2026-11-21 19:30 UTC

**Git SHA**: `bc91565cea`

**Run Duration**: 184m 40s

**Filtered**: 38 tests ignored out of 1334 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1251 |
| Passing | **1197** (95.7%) |
| Ruffle-matched | 18 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1215** (97.1%) |
| Failing | 36 |
| Total expected lines | 156494 |
| Matching lines | 151878 (97.1%) |
| Mismatched lines | 4616 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 36 | 100.0% |

## Passing Tests

**1197 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 21.5s |  |
| 2 | `accessibility` | 1 | 5.6s |  |
| 3 | `accessibilityimplementation` | 18 | 21.8s |  |
| 4 | `activation_class` | 6 | 5.6s |  |
| 5 | `add` | 1058 | 13.0s |  |
| 6 | `agal_compiler` | 13 | 7.8s |  |
| 7 | `air_datagram_socket` | 1 | 7.4s |  |
| 8 | `air_hidden_lookup` | 2 | 5.6s |  |
| 9 | `air_ifilepromise` | 1 | 5.6s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 5.7s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.4s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.4s |  |
| 13 | `all_classes/display/swf10` | 2569 | 5.7s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.5s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.5s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.5s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.4s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.4s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 5.7s |  |
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
| 30 | `all_classes/security/swf11` | 3 | 5.6s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.4s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.4s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.4s |  |
| 34 | `all_classes/xml/swf30` | 116 | 5.7s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.4s |  |
| 36 | `amf_array_serialization` | 17 | 23.9s |  |
| 37 | `amf_custom_obj` | 26 | 5.7s |  |
| 38 | `amf_dictionary` | 9 | 5.6s |  |
| 39 | `amf_function` | 46 | 5.8s |  |
| 40 | `amf_invalid_date` | 2 | 5.7s |  |
| 41 | `amf_missing_prop` | 6 | 5.7s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 5.7s |  |
| 43 | `amf_sealed_class_dynamic_properties` | 16 | 5.8s |  |
| 44 | `amf_setter_error` | 8 | 5.8s |  |
| 45 | `amf_vector` | 40 | 5.9s |  |
| 46 | `amf_xml` | 6 | 5.7s |  |
| 47 | `appdomain_lookup_edge_cases` | 32 | 6.1s |  |
| 48 | `application_domain` | 4 | 5.7s |  |
| 49 | `applicationdomain_getqualifieddefinitionnames` | 9 | 5.7s |  |
| 50 | `applicationdomain_hasdefinition_null` | 2 | 5.6s |  |
| 51 | `array_access` | 18 | 5.7s |  |
| 52 | `array_access_interpreter` | 4 | 5.6s |  |
| 53 | `array_access_no_pubns` | 2 | 5.5s |  |
| 54 | `array_concat` | 41 | 5.6s |  |
| 55 | `array_constr` | 10 | 1.4s |  |
| 56 | `array_delete` | 44 | 5.7s |  |
| 57 | `array_enumeration` | 10 | 5.6s |  |
| 58 | `array_enumeration_elements` | 11 | 5.6s |  |
| 59 | `array_every` | 8 | 5.6s |  |
| 60 | `array_filter` | 6 | 5.5s |  |
| 61 | `array_foreach` | 18 | 5.5s |  |
| 62 | `array_hasownproperty` | 11 | 5.5s |  |
| 63 | `array_holes` | 9 | 5.6s |  |
| 64 | `array_index_max` | 84 | 5.5s |  |
| 65 | `array_indexof` | 25 | 5.6s |  |
| 66 | `array_join` | 26 | 5.6s |  |
| 67 | `array_lastindexof` | 29 | 5.6s |  |
| 68 | `array_length` | 14 | 5.6s |  |
| 69 | `array_literal` | 3 | 5.5s |  |
| 70 | `array_map` | 8 | 5.4s |  |
| 71 | `array_pop` | 52 | 5.7s |  |
| 72 | `array_push` | 24 | 5.6s |  |
| 73 | `array_reborrow_bug` | 6 | 5.6s |  |
| 74 | `array_reverse` | 28 | 1.7s |  |
| 75 | `array_shift` | 51 | 1.7s |  |
| 76 | `array_slice` | 39 | 5.7s |  |
| 77 | `array_some` | 8 | 5.6s |  |
| 78 | `array_sort` | 297 | 6.1s |  |
| 79 | `array_sort_fun_swf12` | 2 | 5.6s |  |
| 80 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 81 | `array_sort_random` | 210 | 5.7s |  |
| 82 | `array_sort_swf10_32bit` | 1 | 5.6s |  |
| 83 | `array_sorton` | 545 | 6.5s |  |
| 84 | `array_sparse_ops` | 41 | 5.8s |  |
| 85 | `array_splice` | 133 | 22.9s |  |
| 86 | `array_splice2` | 428 | 23.9s |  |
| 87 | `array_splice_types` | 48 | 6.5s |  |
| 88 | `array_storage` | 8 | 6.6s |  |
| 89 | `array_tolocalestring` | 9 | 6.5s |  |
| 90 | `array_tostring` | 12 | 6.4s |  |
| 91 | `array_unshift` | 24 | 6.4s |  |
| 92 | `array_valueof` | 9 | 6.2s |  |
| 93 | `array_vector_null_callback` | 10 | 6.3s |  |
| 94 | `astype` | 28 | 6.7s |  |
| 95 | `astypelate` | 24 | 6.5s |  |
| 96 | `astypelate_propagates` | 1 | 6.3s |  |
| 97 | `asymmetric_key_events` | 11 | 6.5s |  |
| 98 | `automation_classes` | 122 | 6.7s |  |
| 99 | `av_classes` | 340 | 6.6s |  |
| 100 | `avm1movie_addcallback_call` | 14 | 6.7s |  |
| 101 | `avm2_catchup_dobj` | 158 | 7.1s |  |
| 102 | `away3d_advanced_shallow_water_demo` | 0 | 82.6s |  |
| 103 | `bevel_filter` | 187 | 6.5s |  |
| 104 | `bitand` | 1058 | 14.9s |  |
| 105 | `bitmap_constr` | 17 | 6.5s |  |
| 106 | `bitmap_data` | 1000 | 15.8s |  |
| 107 | `bitmap_filter_abstract` | 6 | 6.3s |  |
| 108 | `bitmap_pixelsnapping` | 2 | 23.4s |  |
| 109 | `bitmap_properties` | 23 | 6.5s |  |
| 110 | `bitmap_subclass` | 7 | 8.5s |  |
| 111 | `bitmap_subclass_properties` | 9 | 7.0s |  |
| 112 | `bitmap_timeline` | 9 | 6.4s |  |
| 113 | `bitmapdata_accuracy` | 1 | 41.6s |  |
| 114 | `bitmapdata_applyfilter_blur` | 0 | 23.3s |  |
| 115 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.5s |  |
| 116 | `bitmapdata_applyfilter_destpoint` | 0 | 23.2s |  |
| 117 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 23.6s |  |
| 118 | `bitmapdata_applyfilter_identity` | 4 | 22.9s |  |
| 119 | `bitmapdata_clone` | 13 | 6.4s |  |
| 120 | `bitmapdata_colortransform` | 0 | 6.6s |  |
| 121 | `bitmapdata_colortransform_oob` | 2 | 6.4s |  |
| 122 | `bitmapdata_constr` | 22 | 6.3s |  |
| 123 | `bitmapdata_constructor_from_timeline` | 1 | 6.6s |  |
| 124 | `bitmapdata_copychannel` | 0 | 24.4s |  |
| 125 | `bitmapdata_copypixels` | 23 | 23.4s |  |
| 126 | `bitmapdata_copypixels_alpha_combine` | 13 | 6.3s |  |
| 127 | `bitmapdata_copypixels_alpha_merge` | 9 | 6.3s |  |
| 128 | `bitmapdata_copypixels_blend` | 1029 | 6.2s |  |
| 129 | `bitmapdata_copypixels_blend_over` | 1 | 5.8s |  |
| 130 | `bitmapdata_copypixels_self` | 612 | 5.8s |  |
| 131 | `bitmapdata_copypixelstobytearray` | 39 | 5.8s |  |
| 132 | `bitmapdata_dispose` | 7 | 5.8s |  |
| 133 | `bitmapdata_draw` | 0 | 22.1s |  |
| 134 | `bitmapdata_draw_alpha_erase` | 8 | 5.7s |  |
| 135 | `bitmapdata_draw_cab_quality` | 0 | 23.0s |  |
| 136 | `bitmapdata_draw_colortransform` | 0 | 5.7s |  |
| 137 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 5.8s |  |
| 138 | `bitmapdata_draw_filters` | 0 | 21.9s |  |
| 139 | `bitmapdata_draw_masks` | 0 | 5.6s |  |
| 140 | `bitmapdata_draw_rotation` | 0 | 1.6s |  |
| 141 | `bitmapdata_draw_self_via_graphic` | 0 | 5.6s |  |
| 142 | `bitmapdata_draw_stage` | 0 | 21.8s |  |
| 143 | `bitmapdata_drawwithquality` | 0 | 5.8s |  |
| 144 | `bitmapdata_embedded` | 9 | 5.7s |  |
| 145 | `bitmapdata_fillrect` | 0 | 5.7s |  |
| 146 | `bitmapdata_filter_sourcerect` | 0 | 21.8s |  |
| 147 | `bitmapdata_floodfill` | 35 | 5.6s |  |
| 148 | `bitmapdata_getpixels` | 39 | 21.7s |  |
| 149 | `bitmapdata_getvector` | 27 | 1.6s |  |
| 150 | `bitmapdata_histogram` | 59 | 1.6s |  |
| 151 | `bitmapdata_hittest` | 112 | 6.1s |  |
| 152 | `bitmapdata_hittest_threshold` | 18 | 5.7s |  |
| 153 | `bitmapdata_opaque` | 0 | 5.7s |  |
| 154 | `bitmapdata_pixeldissolve` | 1037 | 6.2s |  |
| 155 | `bitmapdata_pixeldissolve_image` | 0 | 5.8s |  |
| 156 | `bitmapdata_rectangle_rounding` | 16 | 5.7s |  |
| 157 | `bitmapdata_setpixels` | 286 | 5.7s |  |
| 158 | `bitmapdata_setvector` | 26 | 5.9s |  |
| 159 | `bitmapdata_sync` | 0 | 18.0s |  |
| 160 | `bitmapdata_threshold` | 176 | 6.2s |  |
| 161 | `bitmapdata_zero_size` | 8 | 5.7s |  |
| 162 | `bitnot` | 46 | 5.7s |  |
| 163 | `bitor` | 1058 | 12.8s |  |
| 164 | `bitxor` | 1058 | 12.9s |  |
| 165 | `blend_mode_null` | 1 | 5.6s |  |
| 166 | `blend_multiply_alpha` | 0 | 5.7s |  |
| 167 | `blend_scroll` | 0 | 5.7s |  |
| 168 | `blend_shader_luma_lighten` | 3 | 5.8s |  |
| 169 | `blur_filter` | 43 | 5.6s |  |
| 170 | `boolean_constr` | 32 | 5.5s |  |
| 171 | `boolean_negation` | 30 | 5.5s |  |
| 172 | `boolean_tostring` | 8 | 5.5s |  |
| 173 | `broadcast_event` | 7 | 5.3s |  |
| 174 | `button_bounds` | 1 | 5.5s |  |
| 175 | `button_hittest` | 2 | 21.3s |  |
| 176 | `button_nested_frame` | 48 | 21.4s |  |
| 177 | `button_nested_frame_simple` | 27 | 5.8s |  |
| 178 | `bytearray` | 48 | 5.7s |  |
| 179 | `bytearray_amf3_shared_references` | 4 | 5.5s |  |
| 180 | `bytearray_bad_symbol_class` | 3 | 5.5s |  |
| 181 | `bytearray_bad_symbol_class_other_movie` | 6 | 5.7s |  |
| 182 | `bytearray_compress` | 31 | 5.5s |  |
| 183 | `bytearray_errors` | 24 | 5.6s |  |
| 184 | `bytearray_insertion_reborrow` | 5 | 5.5s |  |
| 185 | `bytearray_method_serialization` | 1 | 5.5s |  |
| 186 | `bytearray_readobject_amf0` | 50 | 5.5s |  |
| 187 | `bytearray_readobject_amf3` | 53 | 5.6s |  |
| 188 | `bytearray_readutf8bytes_with_bom` | 16 | 5.5s |  |
| 189 | `bytearray_serialization` | 3 | 5.5s |  |
| 190 | `bytearray_string_null` | 19 | 5.7s |  |
| 191 | `bytearray_tostring` | 15 | 5.5s |  |
| 192 | `bytearray_utf16` | 8 | 5.5s |  |
| 193 | `bytearray_writeobject` | 24 | 5.3s |  |
| 194 | `callee_in_initializer` | 6 | 5.4s |  |
| 195 | `callproplex_class` | 1 | 5.4s |  |
| 196 | `capabilities_resolution` | 8 | 22.2s |  |
| 197 | `casi32` | 166 | 5.5s |  |
| 198 | `catch_class` | 6 | 5.5s |  |
| 199 | `catch_scope_slot` | 7 | 5.5s |  |
| 200 | `checkfilter` | 4 | 1.6s |  |
| 201 | `class_call` | 32 | 5.7s |  |
| 202 | `class_cast_call` | 14 | 5.5s |  |
| 203 | `class_enumeration` | 4 | 5.5s |  |
| 204 | `class_has_own_property` | 2 | 5.5s |  |
| 205 | `class_init_interpreter_mode` | 1 | 5.4s |  |
| 206 | `class_is` | 32 | 5.4s |  |
| 207 | `class_methods` | 5 | 5.5s |  |
| 208 | `class_object_properties` | 10 | 5.5s |  |
| 209 | `class_singleton` | 18 | 5.5s |  |
| 210 | `class_supercalls_errors` | 35 | 5.9s |  |
| 211 | `class_supercalls_mismatched` | 26 | 5.8s |  |
| 212 | `class_superclass_wrong_order` | 1 | 5.6s |  |
| 213 | `class_to_locale_string` | 2 | 5.6s |  |
| 214 | `class_to_string` | 2 | 5.6s |  |
| 215 | `class_value_of` | 2 | 5.6s |  |
| 216 | `click_block` | 5 | 22.5s |  |
| 217 | `click_invisible` | 3 | 5.8s |  |
| 218 | `closures` | 12 | 5.7s |  |
| 219 | `coerce_return_type` | 40 | 5.8s |  |
| 220 | `coerce_return_type_fail` | 2 | 5.6s |  |
| 221 | `coerce_return_void` | 3 | 5.6s |  |
| 222 | `coerce_string` | 86 | 5.8s |  |
| 223 | `coerce_string_precision` | 28 | 5.7s |  |
| 224 | `coerce_to_primitive_side_effects` | 29 | 5.8s |  |
| 225 | `collator_compare_basic` | 93 | 5.8s |  |
| 226 | `collator_flags` | 111 | 5.7s |  |
| 227 | `collator_locale_ids_windows` | 120 | 5.8s |  |
| 228 | `color_matrix_filter` | 19 | 5.8s |  |
| 229 | `construct_errors_swf10` | 8 | 5.8s |  |
| 230 | `construct_frame_list` | 22 | 5.8s |  |
| 231 | `construct_interface` | 3 | 5.7s |  |
| 232 | `constructor_call` | 3 | 5.7s |  |
| 233 | `constructors_vs_timeline` | 5 | 22.3s |  |
| 234 | `constructprop_dynamic_primitive` | 7 | 5.8s |  |
| 235 | `constructprop_method` | 2 | 5.7s |  |
| 236 | `constructsuper_null` | 2 | 1.7s |  |
| 237 | `content_element_basic` | 50 | 6.0s |  |
| 238 | `context3d_clear_mask` | 4 | 5.7s |  |
| 239 | `context3d_creation` | 9 | 5.8s |  |
| 240 | `control_flow_bool` | 4 | 5.8s |  |
| 241 | `control_flow_stricteq` | 8 | 5.8s |  |
| 242 | `convert_boolean` | 30 | 5.8s |  |
| 243 | `convert_integer` | 90 | 5.9s |  |
| 244 | `convert_number` | 56 | 5.8s |  |
| 245 | `convert_uinteger` | 90 | 5.8s |  |
| 246 | `convolution_filter` | 89 | 5.9s |  |
| 247 | `core_exceptions` | 47 | 6.8s |  |
| 248 | `cpool_index_invalid_bytecode_1` | 6 | 5.8s |  |
| 249 | `cpool_index_invalid_bytecode_2` | 3 | 5.8s |  |
| 250 | `cpool_index_invalid_bytecode_3` | 1 | 5.8s |  |
| 251 | `cross_api_version_call_newer` | 12 | 6.3s |  |
| 252 | `cross_api_version_call_older` | 12 | 6.1s |  |
| 253 | `cryptscore` | 11 | 5.8s |  |
| 254 | `currency_parse_result` | 7 | 5.6s |  |
| 255 | `date` | 30 | 6.1s |  |
| 256 | `date_parse` | 36 | 5.6s |  |
| 257 | `date_set_time_out_of_range` | 62 | 5.6s |  |
| 258 | `declocal` | 46 | 5.7s |  |
| 259 | `declocal_i` | 46 | 5.7s |  |
| 260 | `decode_uri` | 71 | 5.9s |  |
| 261 | `decrement` | 46 | 5.7s |  |
| 262 | `decrement_i` | 46 | 1.7s |  |
| 263 | `default_values` | 7 | 5.7s |  |
| 264 | `delayed_symbolclass` | 28 | 5.9s |  |
| 265 | `describe_type_basic` | 152 | 5.8s |  |
| 266 | `describe_type_json` | 301 | 5.9s |  |
| 267 | `describe_type_metadata` | 125 | 5.8s |  |
| 268 | `describe_type_native` | 23 | 5.7s |  |
| 269 | `dictionary_access` | 62 | 5.9s |  |
| 270 | `dictionary_access_no_pubns` | 2 | 5.6s |  |
| 271 | `dictionary_delete` | 101 | 6.1s |  |
| 272 | `dictionary_foreach` | 42 | 6.0s |  |
| 273 | `dictionary_hasownproperty` | 63 | 5.9s |  |
| 274 | `dictionary_in` | 62 | 5.9s |  |
| 275 | `dictionary_iter_modify` | 8 | 5.7s |  |
| 276 | `dictionary_namespaces` | 36 | 5.8s |  |
| 277 | `displacement_map_filter` | 61 | 1.8s |  |
| 278 | `displayobject_alpha` | 277 | 5.7s |  |
| 279 | `displayobject_blendmode` | 0 | 5.7s |  |
| 280 | `displayobject_colortransform_nested` | 0 | 5.8s |  |
| 281 | `displayobject_early_init` | 54 | 7.1s |  |
| 282 | `displayobject_filters` | 17 | 5.8s |  |
| 283 | `displayobject_from_enterframe` | 1 | 5.8s |  |
| 284 | `displayobject_getbounds_shape` | 0 | 22.0s |  |
| 285 | `displayobject_getrect` | 16 | 5.9s |  |
| 286 | `displayobject_height` | 6052 | 5.9s |  |
| 287 | `displayobject_hittestobject` | 32 | 5.8s |  |
| 288 | `displayobject_hittestpoint` | 49 | 1.8s |  |
| 289 | `displayobject_hittestpoint_boundary` | 65 | 22.4s |  |
| 290 | `displayobject_hittestpoint_root` | 13 | 5.9s |  |
| 291 | `displayobject_invalid_floats` | 60 | 5.7s |  |
| 292 | `displayobject_invalid_props` | 3 | 5.7s |  |
| 293 | `displayobject_mask` | 3 | 5.7s |  |
| 294 | `displayobject_mask_self_referential` | 0 | 21.6s |  |
| 295 | `displayobject_metaData` | 3 | 5.6s |  |
| 296 | `displayobject_name` | 22 | 22.2s |  |
| 297 | `displayobject_name_from_timeline` | 24 | 5.9s |  |
| 298 | `displayobject_opaque_background` | 6 | 22.1s |  |
| 299 | `displayobject_parent` | 12 | 5.7s |  |
| 300 | `displayobject_root` | 24 | 5.7s |  |
| 301 | `displayobject_rotation` | 1284 | 5.7s |  |
| 302 | `displayobject_scrollrect` | 33 | 6.0s |  |
| 303 | `displayobject_set_matrix_nested` | 0 | 21.9s |  |
| 304 | `displayobject_set_name_loaded` | 3 | 6.0s |  |
| 305 | `displayobject_subclass` | 2 | 5.6s |  |
| 306 | `displayobject_transform` | 89 | 5.7s |  |
| 307 | `displayobject_visible` | 23 | 5.7s |  |
| 308 | `displayobject_width` | 4852 | 22.0s |  |
| 309 | `displayobject_x` | 614 | 5.6s |  |
| 310 | `displayobject_y` | 617 | 5.6s |  |
| 311 | `displayobject_z` | 38 | 21.6s |  |
| 312 | `displayobjectcontainer_addchild` | 32 | 5.6s |  |
| 313 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.5s |  |
| 314 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.8s |  |
| 315 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.7s |  |
| 316 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.7s |  |
| 317 | `displayobjectcontainer_addchildat` | 42 | 5.6s |  |
| 318 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.7s |  |
| 319 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.6s |  |
| 320 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.6s |  |
| 321 | `displayobjectcontainer_contains` | 66 | 21.5s |  |
| 322 | `displayobjectcontainer_getchildat` | 4 | 5.6s |  |
| 323 | `displayobjectcontainer_getchildbyname` | 9 | 5.5s |  |
| 324 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.5s |  |
| 325 | `displayobjectcontainer_getchildindex` | 28 | 5.5s |  |
| 326 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 21.4s |  |
| 327 | `displayobjectcontainer_removechild` | 10 | 5.5s |  |
| 328 | `displayobjectcontainer_removechild_errors` | 4 | 5.5s |  |
| 329 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.6s |  |
| 330 | `displayobjectcontainer_removechildat` | 18 | 5.5s |  |
| 331 | `displayobjectcontainer_removechildren` | 51 | 5.7s |  |
| 332 | `displayobjectcontainer_setchildindex` | 42 | 5.4s |  |
| 333 | `displayobjectcontainer_stopallmovieclips` | 2 | 21.4s |  |
| 334 | `displayobjectcontainer_swapchildren` | 42 | 5.6s |  |
| 335 | `displayobjectcontainer_swapchildrenat` | 42 | 5.6s |  |
| 336 | `displayobjectcontainer_timelineinstance` | 48 | 21.8s |  |
| 337 | `divide` | 1058 | 12.9s |  |
| 338 | `doabc_and_symbolclass_script_init_goto` | 7 | 22.0s |  |
| 339 | `doabc_and_symbolclass_script_init_normal` | 6 | 5.6s |  |
| 340 | `doabc_is_eager` | 1 | 21.6s |  |
| 341 | `documentclass` | 9 | 5.7s |  |
| 342 | `domain_memory` | 133 | 6.5s |  |
| 343 | `drag_drop` | 10 | 5.7s |  |
| 344 | `drop_shadow_filter` | 172 | 5.7s |  |
| 345 | `duplicate_defs` | 1 | 5.4s |  |
| 346 | `eager_init` | 1 | 5.6s |  |
| 347 | `east_asian_justifier_clone` | 8 | 5.6s |  |
| 348 | `edit_text_linkage` | 7 | 5.7s |  |
| 349 | `edittext_align` | 60 | 6.0s |  |
| 350 | `edittext_always_show_selection` | 0 | 21.8s |  |
| 351 | `edittext_antialiastype` | 296 | 6.0s |  |
| 352 | `edittext_at_point_methods_basic` | 16 | 6.6s |  |
| 353 | `edittext_autosize` | 39 | 6.1s |  |
| 354 | `edittext_autosize_align` | 0 | 22.0s |  |
| 355 | `edittext_autosize_height_dynamic` | 60 | 21.9s |  |
| 356 | `edittext_autosize_height_input` | 60 | 5.7s |  |
| 357 | `edittext_autosize_lazy_bounds_events` | 65 | 5.8s |  |
| 358 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.7s |  |
| 359 | `edittext_autosize_lazy_bounds_props` | 490 | 7.0s |  |
| 360 | `edittext_autosize_lazy_bounds_visual` | 0 | 5.7s |  |
| 361 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.8s |  |
| 362 | `edittext_bottom_scroll_v_basic` | 210 | 5.7s |  |
| 363 | `edittext_bounds_scale` | 24 | 5.7s |  |
| 364 | `edittext_bullet` | 30 | 5.8s |  |
| 365 | `edittext_default_format` | 221 | 6.1s |  |
| 366 | `edittext_default_format_empty` | 136 | 5.9s |  |
| 367 | `edittext_empty_text_format` | 7 | 5.7s |  |
| 368 | `edittext_focus_selection` | 5 | 5.6s |  |
| 369 | `edittext_font_size` | 45 | 5.8s |  |
| 370 | `edittext_format_empty_font` | 8 | 5.5s |  |
| 371 | `edittext_get_char_index_at_point` | 4 | 23.3s |  |
| 372 | `edittext_get_line_index_at_point` | 2 | 22.3s |  |
| 373 | `edittext_get_line_index_of_char` | 76 | 6.5s |  |
| 374 | `edittext_getcharboundaries` | 172 | 6.0s |  |
| 375 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.7s |  |
| 376 | `edittext_getcharboundaries_scroll` | 85 | 5.8s |  |
| 377 | `edittext_getlinemetrics` | 146 | 5.9s |  |
| 378 | `edittext_html` | 3101 | 6.0s |  |
| 379 | `edittext_html_condensewhite` | 487 | 5.7s |  |
| 380 | `edittext_html_entity` | 4 | 5.9s |  |
| 381 | `edittext_html_font_size_swf12` | 267 | 5.7s |  |
| 382 | `edittext_html_font_size_swf13` | 273 | 5.3s |  |
| 383 | `edittext_html_roundtrip` | 17 | 5.7s |  |
| 384 | `edittext_ime_focus_lost` | 9 | 5.6s |  |
| 385 | `edittext_input_control` | 12 | 5.6s |  |
| 386 | `edittext_leading` | 9 | 5.9s |  |
| 387 | `edittext_letter_spacing` | 15 | 5.6s |  |
| 388 | `edittext_line_methods` | 294 | 6.7s |  |
| 389 | `edittext_line_metrics` | 11 | 22.8s |  |
| 390 | `edittext_margins` | 25 | 5.7s |  |
| 391 | `edittext_max_scroll_h_basic` | 475 | 5.8s |  |
| 392 | `edittext_max_scroll_v_basic` | 1000 | 5.7s |  |
| 393 | `edittext_mouse_selection` | 363 | 22.6s |  |
| 394 | `edittext_mousedown` | 3 | 5.8s |  |
| 395 | `edittext_mouseenabled` | 26 | 5.7s |  |
| 396 | `edittext_newline_character` | 22 | 5.6s |  |
| 397 | `edittext_newline_stripping` | 64 | 11.1s |  |
| 398 | `edittext_newlines` | 30 | 5.7s |  |
| 399 | `edittext_paragraph_methods` | 257 | 5.6s |  |
| 400 | `edittext_paste_events` | 8 | 5.6s |  |
| 401 | `edittext_paste_maxchars` | 4 | 5.7s |  |
| 402 | `edittext_paste_restrict` | 16 | 5.5s |  |
| 403 | `edittext_restrict` | 191 | 1.7s |  |
| 404 | `edittext_restrict_events` | 22 | 5.6s |  |
| 405 | `edittext_scroll_event` | 37 | 5.8s |  |
| 406 | `edittext_scrollh` | 10 | 5.6s |  |
| 407 | `edittext_selected_text` | 9 | 5.6s |  |
| 408 | `edittext_set_html_same` | 17 | 5.6s |  |
| 409 | `edittext_set_text_vs_html` | 9 | 5.5s |  |
| 410 | `edittext_stylesheet` | 536 | 6.0s |  |
| 411 | `edittext_stylesheet_custom_tag` | 76 | 5.7s |  |
| 412 | `edittext_stylesheet_display` | 272 | 5.7s |  |
| 413 | `edittext_tag_indent` | 49 | 17.9s |  |
| 414 | `edittext_underline` | 40 | 5.8s |  |
| 415 | `edittext_width_height` | 103 | 5.9s |  |
| 416 | `edittext_wordwrap_word` | 150 | 5.7s |  |
| 417 | `edittext_wrap_breaks` | 2375 | 6.1s |  |
| 418 | `element_format_clone` | 44 | 7.8s |  |
| 419 | `element_format_constructor_order` | 64 | 7.9s |  |
| 420 | `element_format_properties` | 235 | 9.0s |  |
| 421 | `empty_bounds` | 1 | 7.4s |  |
| 422 | `encode_uri_surrogate_pair_invalid` | 8 | 7.3s |  |
| 423 | `encode_uri_surrogate_pair_swf11` | 15 | 7.0s |  |
| 424 | `equals` | 512 | 10.6s |  |
| 425 | `error_geterrormessage` | 779 | 7.5s |  |
| 426 | `error_prototype` | 15 | 7.4s |  |
| 427 | `error_stack_trace` | 45 | 7.3s |  |
| 428 | `error_stack_trace_debug_swf17` | 0 | 27.3s |  |
| 429 | `error_stack_trace_debug_swf18` | 0 | 7.0s |  |
| 430 | `error_stack_trace_edge_cases` | 6 | 7.3s |  |
| 431 | `error_stack_trace_release_swf17` | 0 | 2.2s |  |
| 432 | `error_stack_trace_release_swf18` | 0 | 7.0s |  |
| 433 | `error_throwerror` | 103 | 7.4s |  |
| 434 | `error_tostring` | 29 | 7.3s |  |
| 435 | `error_tostring_more` | 86 | 7.4s |  |
| 436 | `es3_inheritance` | 31 | 7.5s |  |
| 437 | `es4_inheritance` | 30 | 7.4s |  |
| 438 | `es4_interfaces` | 30 | 7.4s |  |
| 439 | `es4_method_binding` | 8 | 7.3s |  |
| 440 | `es4_oop_prototypes` | 14 | 7.5s |  |
| 441 | `es4_protected_inheritance` | 6 | 7.5s |  |
| 442 | `escape` | 71 | 7.8s |  |
| 443 | `escape_multi_byte` | 45 | 7.9s |  |
| 444 | `event_bubbles` | 2 | 7.5s |  |
| 445 | `event_cancelable` | 2 | 7.4s |  |
| 446 | `event_clone` | 20 | 7.6s |  |
| 447 | `event_clone_error_redispatch` | 3 | 7.7s |  |
| 448 | `event_clone_on_redispatch` | 10 | 7.7s |  |
| 449 | `event_formattostring` | 31 | 7.7s |  |
| 450 | `event_isdefaultprevented` | 12 | 7.6s |  |
| 451 | `event_target_getter` | 5 | 2.4s |  |
| 452 | `event_target_set` | 9 | 7.5s |  |
| 453 | `event_type` | 1 | 7.5s |  |
| 454 | `event_valueof_tostring` | 18 | 7.7s |  |
| 455 | `eventdispatcher_dispatchevent` | 12 | 7.6s |  |
| 456 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.5s |  |
| 457 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.7s |  |
| 458 | `focusrect_focuslost` | 9 | 21.9s |  |
| 459 | `focusrect_property` | 110 | 21.7s |  |
| 460 | `font_description_clone` | 14 | 5.6s |  |
| 461 | `font_embedded` | 24 | 6.0s |  |
| 462 | `font_enumeratefonts` | 41 | 6.1s |  |
| 463 | `font_enumeratefonts_filter` | 4 | 6.1s |  |
| 464 | `font_enumeratefonts_order` | 9 | 6.5s |  |
| 465 | `font_hasglyphs` | 40 | 6.0s |  |
| 466 | `font_registerfont` | 129 | 6.4s |  |
| 467 | `framelabel_constr` | 5 | 5.5s |  |
| 468 | `function_call` | 12 | 1.6s |  |
| 469 | `function_call_arguments` | 46 | 5.7s |  |
| 470 | `function_call_arguments_enumerate` | 5 | 5.5s |  |
| 471 | `function_call_coercion` | 108 | 5.8s |  |
| 472 | `function_call_default` | 6 | 5.5s |  |
| 473 | `function_call_rest` | 22 | 5.6s |  |
| 474 | `function_call_types` | 3 | 5.5s |  |
| 475 | `function_call_via_apply` | 11 | 5.6s |  |
| 476 | `function_call_via_call` | 3 | 5.5s |  |
| 477 | `function_display_anonymous` | 7 | 1.6s |  |
| 478 | `function_length` | 6 | 5.5s |  |
| 479 | `function_object` | 2 | 5.5s |  |
| 480 | `function_proto` | 5 | 5.5s |  |
| 481 | `function_proto_created` | 61 | 5.6s |  |
| 482 | `function_to_locale_string` | 4 | 5.5s |  |
| 483 | `function_to_string` | 4 | 5.4s |  |
| 484 | `function_type` | 6 | 5.5s |  |
| 485 | `function_unbound_this` | 51 | 5.7s |  |
| 486 | `function_value_of` | 4 | 5.5s |  |
| 487 | `game_input` | 4 | 5.5s |  |
| 488 | `generate_random_bytes` | 3 | 5.5s |  |
| 489 | `geom_transform` | 74 | 21.8s |  |
| 490 | `get_definition_by_name` | 11 | 5.5s |  |
| 491 | `get_qualified_class_name` | 20 | 5.5s |  |
| 492 | `get_qualified_super_class_name` | 18 | 5.5s |  |
| 493 | `get_slot_edge_cases` | 1 | 5.5s |  |
| 494 | `get_timer` | 2 | 1.6s |  |
| 495 | `getglobalslot` | 1 | 5.5s |  |
| 496 | `getouterscope` | 8 | 5.5s |  |
| 497 | `getouterscope_two_classobjects` | 13 | 5.5s |  |
| 498 | `getter_different_namespace_setter` | 2 | 5.4s |  |
| 499 | `glow_filter` | 127 | 5.7s |  |
| 500 | `goto_button_nested_framescript` | 28 | 21.4s |  |
| 501 | `goto_framescript_queued/swf10` | 59 | 21.5s |  |
| 502 | `goto_framescript_queued/swf9` | 52 | 0.4s |  |
| 503 | `goto_framescript_queued_same_frame` | 4 | 21.6s |  |
| 504 | `goto_in_constructframe` | 12 | 21.5s |  |
| 505 | `goto_in_scene_last_frame` | 2 | 21.4s |  |
| 506 | `goto_methods` | 56 | 5.9s |  |
| 507 | `goto_methods_swfver10` | 8 | 5.7s |  |
| 508 | `goto_nested_construct_sibling` | 18 | 5.9s |  |
| 509 | `goto_nested_framescript` | 9 | 5.7s |  |
| 510 | `goto_on_orphan` | 15 | 21.7s |  |
| 511 | `goto_queued_invalid/swf10` | 34 | 21.9s |  |
| 512 | `goto_queued_invalid/swf11` | 43 | 0.4s |  |
| 513 | `goto_queued_invalid/swf9` | 32 | 0.4s |  |
| 514 | `gradient_bevel_filter` | 206 | 5.7s |  |
| 515 | `gradient_glow_filter` | 206 | 5.5s |  |
| 516 | `graphic_linkage` | 9 | 5.7s |  |
| 517 | `graphics_bad_direct_commands` | 5 | 6.0s |  |
| 518 | `graphics_bitmap_fill` | 0 | 22.8s |  |
| 519 | `graphics_bitmaps` | 0 | 5.8s |  |
| 520 | `graphics_direct_commands` | 0 | 5.7s |  |
| 521 | `graphics_draw_triangles` | 98 | 22.1s |  |
| 522 | `graphics_gradients` | 0 | 5.7s |  |
| 523 | `graphics_gradients_nulls` | 0 | 5.5s |  |
| 524 | `graphics_path` | 56 | 5.6s |  |
| 525 | `graphics_round_rects` | 0 | 5.5s |  |
| 526 | `graphics_simple_shapes` | 0 | 5.5s |  |
| 527 | `greaterequals` | 512 | 7.9s |  |
| 528 | `greaterthan` | 512 | 7.9s |  |
| 529 | `has_own_property` | 102 | 6.0s |  |
| 530 | `hasownproperty_namespaces` | 2 | 5.5s |  |
| 531 | `hello_world` | 1 | 5.5s |  |
| 532 | `hittest_morph` | 30 | 5.6s |  |
| 533 | `id3_info` | 8 | 21.2s |  |
| 534 | `if_eq` | 10 | 5.6s |  |
| 535 | `if_gt` | 1 | 5.6s |  |
| 536 | `if_gte` | 10 | 1.6s |  |
| 537 | `if_lt` | 1 | 0.4s |  |
| 538 | `if_lte` | 10 | 5.4s |  |
| 539 | `if_ne` | 7 | 1.6s |  |
| 540 | `if_stricteq` | 6 | 5.5s |  |
| 541 | `if_strictne` | 11 | 7.9s |  |
| 542 | `ime_linux_dead_keys` | 10 | 28.2s |  |
| 543 | `in` | 102 | 8.5s |  |
| 544 | `inclocal` | 46 | 7.9s |  |
| 545 | `inclocal_i` | 46 | 7.9s |  |
| 546 | `increment` | 46 | 7.8s |  |
| 547 | `increment_i` | 46 | 7.8s |  |
| 548 | `indexing_delete` | 75 | 7.9s |  |
| 549 | `indexof_xml` | 10 | 7.9s |  |
| 550 | `init_callee_cached` | 24 | 7.9s |  |
| 551 | `instanceof` | 58 | 8.5s |  |
| 552 | `instantiate_root_character` | 4 | 8.2s |  |
| 553 | `instantiation_on_enter_frame` | 7 | 29.3s |  |
| 554 | `instantiation_on_enterframe_gotoandstop` | 8 | 8.2s |  |
| 555 | `int_constr` | 92 | 8.5s |  |
| 556 | `int_edge_cases` | 19 | 8.3s |  |
| 557 | `int_instanceof` | 3 | 8.2s |  |
| 558 | `int_tofixed` | 1215 | 7.8s |  |
| 559 | `int_toprecision` | 1125 | 8.0s |  |
| 560 | `int_tostring` | 3375 | 8.1s |  |
| 561 | `interactiveobject_enabled` | 25 | 7.8s |  |
| 562 | `interface_namespaces` | 78 | 8.2s |  |
| 563 | `invalid_utf8` | 12 | 8.1s |  |
| 564 | `is_finite` | 46 | 8.0s |  |
| 565 | `is_nan` | 46 | 7.7s |  |
| 566 | `is_prototype_of` | 12 | 7.9s |  |
| 567 | `issue_10221` | 2 | 7.9s |  |
| 568 | `issue_13780` | 12 | 7.9s |  |
| 569 | `issue_14901` | 1 | 7.8s |  |
| 570 | `issue_17675_edittext_paste_maxchars` | 1 | 8.0s |  |
| 571 | `issue_5292` | 5 | 7.9s |  |
| 572 | `issue_8630` | 2 | 8.0s |  |
| 573 | `issue_8630_placeremoveplace` | 15 | 8.1s |  |
| 574 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.9s |  |
| 575 | `issue_8630_scriptremove` | 11 | 7.9s |  |
| 576 | `istype` | 24 | 2.8s |  |
| 577 | `istypelate` | 58 | 8.3s |  |
| 578 | `istypelate_coerce` | 198 | 9.3s |  |
| 579 | `jpeg_loader_context` | 6 | 7.9s |  |
| 580 | `json_errors` | 9 | 28.5s |  |
| 581 | `json_parse` | 21 | 7.8s |  |
| 582 | `json_parse_errors` | 84 | 7.8s |  |
| 583 | `json_stringify` | 12 | 30.4s |  |
| 584 | `json_stringify_function` | 12 | 8.3s |  |
| 585 | `json_stringify_order` | 1 | 8.2s |  |
| 586 | `json_version_gated` | 1 | 8.1s |  |
| 587 | `key_input_80percent` | 1812 | 30.2s |  |
| 588 | `key_input_location` | 126 | 8.2s |  |
| 589 | `key_input_numpad` | 384 | 8.0s |  |
| 590 | `large_preload_from_bytes` | 51 | 12.7s |  |
| 591 | `large_preload_from_url` | 27 | 10.6s |  |
| 592 | `large_preload_image_from_bytes` | 25 | 8.9s |  |
| 593 | `lazyinit` | 17 | 8.1s |  |
| 594 | `lessequals` | 512 | 12.8s |  |
| 595 | `lessthan` | 512 | 12.7s |  |
| 596 | `loader_bitmap_transparency` | 14 | 8.1s |  |
| 597 | `loader_bytes_unknown_content` | 14 | 8.2s |  |
| 598 | `loader_child_getdefinition` | 5 | 8.3s |  |
| 599 | `loader_duplicate_class` | 48 | 10.3s |  |
| 600 | `loader_duplicate_coerce` | 3 | 8.2s |  |
| 601 | `loader_duplicate_coerce_new_domain` | 4 | 7.9s |  |
| 602 | `loader_error_in_root_ctor` | 4 | 8.1s |  |
| 603 | `loader_events` | 92 | 8.5s |  |
| 604 | `loader_image` | 8 | 8.0s |  |
| 605 | `loader_jpegxr` | 2 | 28.6s |  |
| 606 | `loader_jpegxr_alpha` | 1 | 28.8s |  |
| 607 | `loader_loadbytes_events` | 30 | 8.5s |  |
| 608 | `loader_loadbytes_invalid_png` | 4 | 8.0s |  |
| 609 | `loader_loadbytes_url` | 12 | 8.1s |  |
| 610 | `loader_loaderurl` | 6 | 8.4s |  |
| 611 | `loader_method` | 85 | 7.9s |  |
| 612 | `loader_noninteractive_try_click_root` | 5 | 28.6s |  |
| 613 | `loader_reuse` | 38 | 8.1s |  |
| 614 | `loader_try_click_root` | 16 | 8.1s |  |
| 615 | `loader_unknown_content` | 24 | 8.1s |  |
| 616 | `loader_unloadandstop_subclass` | 1 | 8.0s |  |
| 617 | `loader_visibility_interactive` | 1 | 8.0s |  |
| 618 | `loaderinfo_child_progress` | 9 | 8.5s |  |
| 619 | `loaderinfo_events` | 7 | 7.9s |  |
| 620 | `loaderinfo_loadurl` | 12 | 8.0s |  |
| 621 | `loaderinfo_more` | 6 | 8.3s |  |
| 622 | `loaderinfo_properties` | 18 | 28.6s |  |
| 623 | `loaderinfo_properties_not_loaded` | 23 | 8.0s |  |
| 624 | `loaderinfo_quine` | 1005 | 22.2s |  |
| 625 | `loaderinfo_root` | 10 | 5.8s |  |
| 626 | `loaderinfo_root_allows` | 2 | 5.7s |  |
| 627 | `localconnection` | 890 | 7.4s |  |
| 628 | `localconnection_send` | 4 | 5.7s |  |
| 629 | `lshift` | 1058 | 13.0s |  |
| 630 | `mask_reapply` | 1 | 22.0s |  |
| 631 | `math` | 497 | 6.0s |  |
| 632 | `matrix` | 338 | 13.8s |  |
| 633 | `matrix3d` | 57 | 22.8s |  |
| 634 | `matrix3d_append` | 16 | 5.8s |  |
| 635 | `matrix3d_append_prepend_scale` | 86 | 5.8s |  |
| 636 | `matrix3d_append_prepend_translation` | 42 | 5.7s |  |
| 637 | `matrix3d_append_rotation` | 23 | 5.8s |  |
| 638 | `matrix3d_compose` | 34 | 5.9s |  |
| 639 | `matrix3d_constructor_clone` | 15 | 5.7s |  |
| 640 | `matrix3d_copy_column` | 83 | 5.9s |  |
| 641 | `matrix3d_copy_from` | 19 | 5.8s |  |
| 642 | `matrix3d_copy_raw_data_from` | 55 | 1.9s |  |
| 643 | `matrix3d_copy_raw_data_to` | 38 | 5.9s |  |
| 644 | `matrix3d_copy_row` | 83 | 5.6s |  |
| 645 | `matrix3d_copy_to_matrix3d` | 19 | 5.8s |  |
| 646 | `matrix3d_determinant` | 182 | 5.8s |  |
| 647 | `matrix3d_interpolate` | 21 | 5.8s |  |
| 648 | `matrix3d_invert` | 18 | 5.7s |  |
| 649 | `matrix3d_position` | 19 | 5.7s |  |
| 650 | `matrix3d_precision` | 28 | 5.8s |  |
| 651 | `matrix3d_prepend` | 16 | 5.5s |  |
| 652 | `matrix3d_raw_data` | 33 | 5.7s |  |
| 653 | `matrix3d_transform_vector` | 52 | 5.9s |  |
| 654 | `matrix3d_transpose` | 5 | 5.6s |  |
| 655 | `method_association` | 5 | 5.6s |  |
| 656 | `method_without_body` | 3 | 21.5s |  |
| 657 | `missing_external_interface` | 10 | 5.6s |  |
| 658 | `modulo` | 1058 | 12.7s |  |
| 659 | `morph_shape` | 2 | 21.6s |  |
| 660 | `mouse_children` | 192 | 21.7s |  |
| 661 | `mouse_click_events` | 90 | 21.5s |  |
| 662 | `mouse_double_click_events` | 188 | 5.6s |  |
| 663 | `mouse_empty_parent` | 4 | 5.6s |  |
| 664 | `mouse_over_while_dragging` | 3 | 5.6s |  |
| 665 | `mouse_pick_avm1_root` | 2 | 22.0s |  |
| 666 | `mouse_pick_button_mode` | 2 | 21.7s |  |
| 667 | `mouse_pick_dobj_mask` | 4 | 5.7s |  |
| 668 | `mouse_pick_loader_avm1` | 42 | 5.9s |  |
| 669 | `mouse_pick_masking` | 7 | 21.7s |  |
| 670 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 21.2s |  |
| 671 | `mouse_pick_non_interactive_dobj_mask` | 3 | 5.6s |  |
| 672 | `mouse_pick_scroll_rect` | 27 | 21.6s |  |
| 673 | `mouse_pick_scroll_rect_button` | 5 | 5.7s |  |
| 674 | `mouse_pick_scroll_rect_loader` | 5 | 5.8s |  |
| 675 | `mouse_pick_text` | 8 | 5.7s |  |
| 676 | `mouse_sibling` | 8 | 5.6s |  |
| 677 | `mouse_wheel_events` | 36 | 22.4s |  |
| 678 | `mouseevent_constr` | 66 | 5.5s |  |
| 679 | `mouseevent_stagexy` | 35 | 5.6s |  |
| 680 | `mouseevent_valueof_tostring` | 28 | 5.6s |  |
| 681 | `movieclip_addframescript` | 3 | 21.3s |  |
| 682 | `movieclip_addframescript_error` | 9 | 5.6s |  |
| 683 | `movieclip_child_property` | 16 | 5.7s |  |
| 684 | `movieclip_constr` | 21 | 5.7s |  |
| 685 | `movieclip_currentlabels` | 17 | 21.6s |  |
| 686 | `movieclip_currentlabels_dupes1` | 46 | 22.0s |  |
| 687 | `movieclip_currentlabels_dupes2` | 30 | 5.7s |  |
| 688 | `movieclip_currentlabels_dupes3` | 67 | 5.7s |  |
| 689 | `movieclip_currentscene` | 12 | 22.0s |  |
| 690 | `movieclip_dispatchevent` | 430 | 5.8s |  |
| 691 | `movieclip_dispatchevent_cancel` | 102 | 5.8s |  |
| 692 | `movieclip_dispatchevent_handlerorder` | 251 | 5.8s |  |
| 693 | `movieclip_dispatchevent_selfadd` | 80 | 5.7s |  |
| 694 | `movieclip_dispatchevent_target` | 899 | 5.8s |  |
| 695 | `movieclip_displayevents` | 96 | 22.2s |  |
| 696 | `movieclip_displayevents_clickgoto` | 676 | 22.1s |  |
| 697 | `movieclip_displayevents_clickgoto2` | 2001 | 6.2s |  |
| 698 | `movieclip_displayevents_clickplay` | 575 | 5.9s |  |
| 699 | `movieclip_displayevents_clicksymbol` | 562 | 6.0s |  |
| 700 | `movieclip_displayevents_constructframegoto` | 140 | 6.0s |  |
| 701 | `movieclip_displayevents_constructframeplay` | 50 | 5.9s |  |
| 702 | `movieclip_displayevents_constructframesymbol` | 144 | 6.0s |  |
| 703 | `movieclip_displayevents_dblhandler` | 21 | 5.7s |  |
| 704 | `movieclip_displayevents_enterframegoto` | 149 | 6.0s |  |
| 705 | `movieclip_displayevents_enterframeplay` | 48 | 5.8s |  |
| 706 | `movieclip_displayevents_enterframesymbol` | 149 | 22.1s |  |
| 707 | `movieclip_displayevents_exitframegoto` | 106 | 5.8s |  |
| 708 | `movieclip_displayevents_exitframeplay` | 44 | 5.8s |  |
| 709 | `movieclip_displayevents_exitframesymbol` | 135 | 21.9s |  |
| 710 | `movieclip_displayevents_looping` | 63 | 21.7s |  |
| 711 | `movieclip_displayevents_stopped` | 113 | 21.6s |  |
| 712 | `movieclip_displayevents_swap` | 96 | 5.7s |  |
| 713 | `movieclip_displayevents_timeline` | 128 | 21.8s |  |
| 714 | `movieclip_drawrect` | 54 | 21.3s |  |
| 715 | `movieclip_frameconstruct_skipped` | 9 | 5.6s |  |
| 716 | `movieclip_goto_during_frame_script` | 15 | 21.4s |  |
| 717 | `movieclip_goto_overwrite` | 14 | 21.5s |  |
| 718 | `movieclip_goto_scene_last_frame_int` | 1 | 21.4s |  |
| 719 | `movieclip_goto_scene_last_frame_label` | 1 | 5.6s |  |
| 720 | `movieclip_gotoandplay` | 15 | 21.8s |  |
| 721 | `movieclip_gotoandstop` | 13 | 5.6s |  |
| 722 | `movieclip_gotoandstop_children` | 4 | 5.7s |  |
| 723 | `movieclip_gotoandstop_framescripts1` | 4 | 5.6s |  |
| 724 | `movieclip_gotoandstop_framescripts2` | 4 | 1.6s |  |
| 725 | `movieclip_gotoandstop_framescripts_self` | 7 | 21.8s |  |
| 726 | `movieclip_gotoandstop_queueing` | 12 | 5.7s |  |
| 727 | `movieclip_hittest` | 67 | 5.8s |  |
| 728 | `movieclip_next_frame` | 2 | 5.5s |  |
| 729 | `movieclip_next_scene` | 6 | 5.6s |  |
| 730 | `movieclip_play` | 3 | 5.5s |  |
| 731 | `movieclip_prev_frame` | 3 | 5.3s |  |
| 732 | `movieclip_prev_scene` | 7 | 5.6s |  |
| 733 | `movieclip_properties` | 79 | 21.4s |  |
| 734 | `movieclip_queued_noop_goto_swf10` | 9 | 5.6s |  |
| 735 | `movieclip_queued_noop_goto_swf9` | 7 | 0.4s |  |
| 736 | `movieclip_scenes` | 11 | 5.5s |  |
| 737 | `movieclip_soundtransform` | 831 | 23.1s |  |
| 738 | `movieclip_stop` | 1 | 5.5s |  |
| 739 | `movieclip_super_is_symbol` | 20 | 5.7s |  |
| 740 | `movieclip_symbol_constr` | 8 | 5.7s |  |
| 741 | `movieclip_text_mousedown` | 1 | 5.6s |  |
| 742 | `movieclip_willtrigger` | 5 | 5.6s |  |
| 743 | `multiply` | 1058 | 12.9s |  |
| 744 | `namespace_constr` | 253 | 5.8s |  |
| 745 | `namespace_constr_args` | 1 | 5.6s |  |
| 746 | `namespace_enumeration_order` | 7 | 21.7s |  |
| 747 | `nan_scale` | 9 | 5.6s |  |
| 748 | `native_menu_basic` | 19 | 7.5s |  |
| 749 | `navigateToURL_target_normalize` | 107 | 23.4s |  |
| 750 | `negate` | 30 | 5.6s |  |
| 751 | `negative_volume_panned` | 0 | 5.8s |  |
| 752 | `nested_iteration` | 11 | 5.6s |  |
| 753 | `net_getClassByAlias` | 3 | 22.2s |  |
| 754 | `net_navigateToURL` | 57 | 24.2s |  |
| 755 | `net_stream_play_options` | 6 | 5.8s |  |
| 756 | `netconnection_call_with_responder` | 6 | 22.1s |  |
| 757 | `netconnection_close` | 55 | 22.0s |  |
| 758 | `netconnection_properties` | 78 | 5.8s |  |
| 759 | `netconnection_send_remote` | 50 | 5.9s |  |
| 760 | `netconnection_serialize_arrays` | 6 | 5.8s |  |
| 761 | `netfilterevent` | 10 | 5.7s |  |
| 762 | `netstream_client` | 10 | 5.9s |  |
| 763 | `netstream_connect` | 7 | 5.7s |  |
| 764 | `netstream_flv_date` | 4 | 5.7s |  |
| 765 | `newactivation_in_script_init` | 3 | 5.7s |  |
| 766 | `newclass_mismatched` | 4 | 5.7s |  |
| 767 | `newclass_twice` | 3 | 5.7s |  |
| 768 | `nonconflicting_declarations` | 0 | 5.8s |  |
| 769 | `null_void_types` | 8 | 5.8s |  |
| 770 | `number_autoconv` | 21 | 5.8s |  |
| 771 | `number_autoconv_amf` | 132 | 5.8s |  |
| 772 | `number_autoconv_array_sort_32bit` | 1 | 5.8s |  |
| 773 | `number_constr` | 58 | 5.9s |  |
| 774 | `number_convert_edge_cases` | 180 | 22.5s |  |
| 775 | `number_toexponential` | 378 | 5.9s |  |
| 776 | `number_toexponential2` | 35 | 5.9s |  |
| 777 | `number_tofixed` | 378 | 5.8s |  |
| 778 | `number_toprecision` | 350 | 5.9s |  |
| 779 | `obfuscated_class_names` | 3 | 5.8s |  |
| 780 | `object_enumeration` | 10 | 5.7s |  |
| 781 | `object_prototype` | 4 | 5.8s |  |
| 782 | `object_to_locale_string` | 2 | 5.7s |  |
| 783 | `object_to_string` | 2 | 5.7s |  |
| 784 | `object_value_of` | 2 | 1.5s |  |
| 785 | `op_coerce` | 54 | 5.8s |  |
| 786 | `op_coerce_x` | 54 | 5.8s |  |
| 787 | `op_escxattr` | 2 | 5.7s |  |
| 788 | `op_escxelem` | 2 | 5.7s |  |
| 789 | `op_lookupswitch` | 4 | 5.7s |  |
| 790 | `optimize_coerce` | 1 | 5.7s |  |
| 791 | `orphan_movie_complex` | 80 | 22.1s |  |
| 792 | `orphan_movie_reorder` | 111 | 22.2s |  |
| 793 | `orphan_removeobject` | 636 | 22.6s |  |
| 794 | `package_namespace` | 7 | 21.9s |  |
| 795 | `param_default_value_has_zero_cpool_index` | 1 | 5.6s |  |
| 796 | `parent_early_access_child` | 16 | 22.1s |  |
| 797 | `parse_float` | 81 | 5.9s |  |
| 798 | `parse_float_swf10` | 81 | 5.6s |  |
| 799 | `parse_int` | 135 | 6.0s |  |
| 800 | `perspective_projection` | 1443 | 22.3s |  |
| 801 | `perspective_projection_basic` | 40 | 5.7s |  |
| 802 | `pixelbender_ceil` | 77 | 5.8s |  |
| 803 | `pixelbender_conditional` | 138 | 6.0s |  |
| 804 | `pixelbender_conversions` | 270 | 6.0s |  |
| 805 | `pixelbender_dithering` | 8 | 26.2s |  |
| 806 | `pixelbender_div` | 36 | 5.7s |  |
| 807 | `pixelbender_effect_BlurredFocus` | 0 | 28.6s |  |
| 808 | `pixelbender_effect_glassDisplace` | 0 | 10.6s |  |
| 809 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 24.9s |  |
| 810 | `pixelbender_effect_smudge` | 0 | 8.5s |  |
| 811 | `pixelbender_effect_tintype` | 0 | 7.8s |  |
| 812 | `pixelbender_effect_twirl` | 0 | 8.9s |  |
| 813 | `pixelbender_eof` | 7 | 5.7s |  |
| 814 | `pixelbender_images` | 0 | 7.6s |  |
| 815 | `pixelbender_input` | 103 | 22.7s |  |
| 816 | `pixelbender_logicalnot` | 20 | 5.7s |  |
| 817 | `pixelbender_malformed_data` | 190 | 22.7s |  |
| 818 | `pixelbender_multiple_out_params` | 1 | 5.7s |  |
| 819 | `pixelbender_no_out_param` | 6 | 5.7s |  |
| 820 | `pixelbender_outputs` | 13 | 5.9s |  |
| 821 | `pixelbender_padding_bytes` | 22 | 5.8s |  |
| 822 | `pixelbender_param_qualifier` | 512 | 5.8s |  |
| 823 | `pixelbender_parameters` | 1563 | 6.1s |  |
| 824 | `pixelbender_parameters_bool` | 240 | 6.0s |  |
| 825 | `pixelbender_parameters_int_vs_bool` | 54 | 5.8s |  |
| 826 | `pixelbender_parse_errors` | 6 | 5.7s |  |
| 827 | `pixelbender_rsqrt` | 24 | 5.8s |  |
| 828 | `pixelbender_select_kinds` | 8 | 5.9s |  |
| 829 | `pixelbender_shaderdata` | 49 | 5.8s |  |
| 830 | `pixelbender_shaderdata_setter` | 99 | 6.0s |  |
| 831 | `pixelbender_sign` | 60 | 5.9s |  |
| 832 | `pixelbender_vector_output` | 11 | 5.9s |  |
| 833 | `place_and_lookup/swf10` | 33 | 5.7s |  |
| 834 | `place_and_lookup/swf9` | 33 | 29.6s |  |
| 835 | `place_multiple` | 17 | 29.7s |  |
| 836 | `place_object_replace` | 9 | 30.0s |  |
| 837 | `place_object_replace_2` | 24 | 29.9s |  |
| 838 | `place_object_same_depth_frame` | 1 | 8.2s |  |
| 839 | `point` | 132 | 8.8s |  |
| 840 | `primitive_edge_cases` | 1 | 8.0s |  |
| 841 | `primitive_keys` | 54 | 8.0s |  |
| 842 | `primitive_toString` | 277 | 8.3s |  |
| 843 | `primitive_valueOf` | 285 | 7.9s |  |
| 844 | `print_job_options` | 3 | 8.0s |  |
| 845 | `property_is_enumerable` | 114 | 9.3s |  |
| 846 | `property_is_enumerable_reset` | 23 | 8.1s |  |
| 847 | `property_priority` | 22 | 8.4s |  |
| 848 | `property_priority_chained` | 4 | 8.0s |  |
| 849 | `property_priority_definition_names_order` | 2 | 8.4s |  |
| 850 | `property_priority_three_level` | 6 | 8.2s |  |
| 851 | `propertyisenumerable_namespaces` | 6 | 8.0s |  |
| 852 | `prototype_set_null` | 7 | 8.0s |  |
| 853 | `proxy_callproperty` | 24 | 8.1s |  |
| 854 | `proxy_deleteproperty` | 64 | 8.2s |  |
| 855 | `proxy_enumeration` | 34 | 8.1s |  |
| 856 | `proxy_getproperty` | 77 | 8.2s |  |
| 857 | `proxy_hasownproperty` | 8 | 8.0s |  |
| 858 | `proxy_hasproperty` | 32 | 8.3s |  |
| 859 | `proxy_not_overridden` | 54 | 8.1s |  |
| 860 | `proxy_serialize` | 9 | 8.0s |  |
| 861 | `proxy_setproperty` | 42 | 8.1s |  |
| 862 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.0s |  |
| 863 | `qname_constr` | 32 | 8.2s |  |
| 864 | `qname_constr_namespace` | 24 | 8.1s |  |
| 865 | `qname_enumeration` | 9 | 8.1s |  |
| 866 | `qname_indexing` | 23 | 8.2s |  |
| 867 | `qname_tostring` | 25 | 8.2s |  |
| 868 | `qname_valueof` | 29 | 8.2s |  |
| 869 | `rectangle` | 1094 | 8.8s |  |
| 870 | `regexp_constr` | 148 | 8.5s |  |
| 871 | `regexp_exec` | 19 | 8.2s |  |
| 872 | `regexp_extended` | 47 | 8.0s |  |
| 873 | `regexp_multiargs` | 1 | 7.9s |  |
| 874 | `regexp_test` | 27 | 8.0s |  |
| 875 | `regexp_toString` | 10 | 8.0s |  |
| 876 | `register_script_refresh` | 35 | 29.4s |  |
| 877 | `remove_child_clear_field` | 88 | 5.9s |  |
| 878 | `remove_dobj` | 3 | 1.6s |  |
| 879 | `resolve_order` | 4 | 5.6s |  |
| 880 | `responder_null_callbacks` | 1 | 5.5s |  |
| 881 | `rng` | 1 | 6.5s |  |
| 882 | `rootless` | 42 | 5.6s |  |
| 883 | `rshift` | 1058 | 12.8s |  |
| 884 | `rtqname_not_namespace` | 12 | 5.6s |  |
| 885 | `sandbox_type_inherited` | 2 | 5.8s |  |
| 886 | `sandbox_type_local_file` | 1 | 5.5s |  |
| 887 | `sandbox_type_local_network` | 1 | 5.3s |  |
| 888 | `scene_constr` | 8 | 5.6s |  |
| 889 | `scope_optimizations` | 4 | 5.5s |  |
| 890 | `scopes_dont_cache/order-1` | 1 | 21.5s |  |
| 891 | `scopes_dont_cache/order-2` | 1 | 0.3s |  |
| 892 | `security_domain_current` | 2 | 5.6s |  |
| 893 | `selection` | 239 | 5.9s |  |
| 894 | `selection_onsetfocus_mixed_avm` | 5 | 21.9s |  |
| 895 | `set_local_0` | 31 | 5.7s |  |
| 896 | `set_property_is_enumerable` | 85 | 6.0s |  |
| 897 | `shaderparameter_value` | 4 | 5.6s |  |
| 898 | `shape_drawrect` | 54 | 5.7s |  |
| 899 | `shared_object_no_root` | 3 | 5.6s |  |
| 900 | `simplebutton_added_to_stage` | 45 | 17.9s |  |
| 901 | `simplebutton_childevents` | 86 | 6.1s |  |
| 902 | `simplebutton_childevents_nested` | 54 | 6.0s |  |
| 903 | `simplebutton_childevents_sprite` | 13 | 5.8s |  |
| 904 | `simplebutton_childprops` | 144 | 5.9s |  |
| 905 | `simplebutton_childshuffle` | 23 | 5.6s |  |
| 906 | `simplebutton_constr` | 36 | 5.9s |  |
| 907 | `simplebutton_constr_childevents` | 48 | 6.0s |  |
| 908 | `simplebutton_constr_params` | 42 | 5.8s |  |
| 909 | `simplebutton_mouseenabled` | 26 | 5.7s |  |
| 910 | `simplebutton_multi_children` | 19 | 5.8s |  |
| 911 | `simplebutton_soundtransform` | 887 | 23.6s |  |
| 912 | `simplebutton_structure` | 27 | 5.9s |  |
| 913 | `simplebutton_symbolclass` | 68 | 6.0s |  |
| 914 | `slot_disp_id_shared_numbering` | 1 | 21.7s |  |
| 915 | `slots_force_autoassigned` | 1 | 7.8s |  |
| 916 | `socket_after_disconnect` | 1 | 7.6s |  |
| 917 | `socket_close` | 2 | 7.8s |  |
| 918 | `socket_connect` | 4 | 7.6s |  |
| 919 | `socket_errors` | 56 | 8.1s |  |
| 920 | `socket_read_big` | 48 | 7.6s |  |
| 921 | `socket_read_little` | 48 | 2.2s |  |
| 922 | `socket_read_write_object` | 8 | 7.5s |  |
| 923 | `socket_write_big` | 15 | 7.5s |  |
| 924 | `socket_write_little` | 14 | 7.4s |  |
| 925 | `sound_constructor_with_args` | 6 | 2.6s |  |
| 926 | `sound_embeddedprops` | 26 | 7.8s |  |
| 927 | `sound_load_multiple` | 19 | 8.6s |  |
| 928 | `sound_play` | 19 | 7.8s |  |
| 929 | `sound_rootless` | 7 | 7.5s |  |
| 930 | `sound_valueof` | 33 | 7.6s |  |
| 931 | `soundchannel_soundtransform` | 835 | 29.5s |  |
| 932 | `soundchannel_soundtransform_exists` | 5 | 27.8s |  |
| 933 | `soundchannel_stop` | 8 | 7.5s |  |
| 934 | `soundmixer_buffertime` | 5 | 7.4s |  |
| 935 | `soundmixer_soundtransform` | 900 | 9.5s |  |
| 936 | `soundmixer_stopall` | 6 | 7.5s |  |
| 937 | `soundtransform` | 442 | 12.0s |  |
| 938 | `space_justifier_clone` | 12 | 7.6s |  |
| 939 | `sprite_with_frames` | 0 | 7.7s |  |
| 940 | `stage3d_agal_cross_product` | 0 | 10.2s |  |
| 941 | `stage3d_agal_upload_errors` | 66 | 10.8s |  |
| 942 | `stage3d_bitmap` | 0 | 34.4s |  |
| 943 | `stage3d_blend` | 81 | 31.1s |  |
| 944 | `stage3d_context3d_string_args` | 158 | 9.0s |  |
| 945 | `stage3d_errors` | 7 | 7.7s |  |
| 946 | `stage3d_errors_atf` | 3 | 9.1s |  |
| 947 | `stage3d_errors_swf_29` | 6 | 7.8s |  |
| 948 | `stage3d_float1_index` | 0 | 31.1s |  |
| 949 | `stage3d_fractal` | 0 | 31.9s |  |
| 950 | `stage3d_ignore_sampler_override` | 0 | 32.2s |  |
| 951 | `stage3d_multistage_triangle` | 3 | 10.8s |  |
| 952 | `stage3d_program_constants_bytearray_be` | 0 | 33.7s |  |
| 953 | `stage3d_program_constants_bytearray_le` | 0 | 11.0s |  |
| 954 | `stage3d_program_constants_invalid_input` | 21 | 8.6s |  |
| 955 | `stage3d_raytrace` | 0 | 61.4s |  |
| 956 | `stage3d_rotating_cube` | 0 | 12.3s |  |
| 957 | `stage3d_sampler` | 0 | 11.6s |  |
| 958 | `stage3d_sampler_partial_upload` | 0 | 11.4s |  |
| 959 | `stage3d_stencil` | 0 | 33.6s |  |
| 960 | `stage3d_texture` | 0 | 18.2s |  |
| 961 | `stage3d_texture_bytearray` | 0 | 13.3s |  |
| 962 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 12.5s |  |
| 963 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 13.8s |  |
| 964 | `stage3d_triangle` | 0 | 11.7s |  |
| 965 | `stage3d_triangle_bytes4` | 0 | 11.7s |  |
| 966 | `stage3d_triangle_float1` | 0 | 11.6s |  |
| 967 | `stage3d_triangle_index_upload` | 0 | 11.7s |  |
| 968 | `stage3d_x_y` | 22 | 8.4s |  |
| 969 | `stage_access` | 10 | 8.6s |  |
| 970 | `stage_display_state` | 6 | 8.4s |  |
| 971 | `stage_displayobject_properties` | 24 | 8.3s |  |
| 972 | `stage_domain_getQualifiedDefinitionNames` | 5 | 8.4s |  |
| 973 | `stage_framerate_nan` | 7 | 31.1s |  |
| 974 | `stage_framerate_negative` | 6 | 8.4s |  |
| 975 | `stage_framerate_zero` | 6 | 8.5s |  |
| 976 | `stage_invalidate` | 38 | 8.8s |  |
| 977 | `stage_loaderinfo_properties` | 24 | 31.7s |  |
| 978 | `stage_mousechildren` | 2 | 8.6s |  |
| 979 | `stage_mouseenabled` | 15 | 8.6s |  |
| 980 | `stage_overriden_setters` | 31 | 8.8s |  |
| 981 | `stage_properties` | 30 | 8.7s |  |
| 982 | `stage_properties2` | 213 | 9.1s |  |
| 983 | `stage_scale_factor` | 12 | 37.9s |  |
| 984 | `stage_stage3Ds_vector` | 1 | 8.3s |  |
| 985 | `static_length` | 24 | 8.8s |  |
| 986 | `static_text` | 3 | 8.8s |  |
| 987 | `static_var_with_this_in_ctor` | 2 | 8.5s |  |
| 988 | `statictext_text` | 8 | 8.7s |  |
| 989 | `stored_properties` | 11 | 8.6s |  |
| 990 | `strict_equality` | 34 | 8.7s |  |
| 991 | `string_call` | 13 | 8.6s |  |
| 992 | `string_case` | 23 | 8.6s |  |
| 993 | `string_char_at` | 27 | 8.6s |  |
| 994 | `string_char_code_at` | 28 | 8.4s |  |
| 995 | `string_concat_fromcharcode` | 37 | 8.4s |  |
| 996 | `string_constr` | 25 | 8.5s |  |
| 997 | `string_indexof_lastindexof` | 87 | 8.8s |  |
| 998 | `string_length` | 16 | 8.6s |  |
| 999 | `string_locale_compare` | 39 | 22.1s |  |
| 1000 | `string_match` | 51 | 22.2s |  |
| 1001 | `string_relational_compare` | 4 | 5.6s |  |
| 1002 | `string_replace` | 51 | 5.8s |  |
| 1003 | `string_search` | 41 | 5.8s |  |
| 1004 | `string_slice_substr_substring` | 170 | 6.4s |  |
| 1005 | `string_split` | 29 | 5.7s |  |
| 1006 | `string_substr_negative` | 21 | 5.6s |  |
| 1007 | `string_substr_weird` | 182 | 5.6s |  |
| 1008 | `stylesheet` | 221 | 6.3s |  |
| 1009 | `stylesheet_parse_color` | 69 | 5.6s |  |
| 1010 | `stylesheet_transform` | 307 | 5.9s |  |
| 1011 | `sub_super_same_field` | 12 | 1.7s |  |
| 1012 | `subclass_superclass_linked_symbol` | 4 | 6.1s |  |
| 1013 | `subtract` | 1058 | 13.0s |  |
| 1014 | `super_get_call` | 12 | 5.7s |  |
| 1015 | `supercall_two_classobjects` | 2 | 5.7s |  |
| 1016 | `supercalls_coerce` | 8 | 5.7s |  |
| 1017 | `supercalls_weird` | 2 | 5.4s |  |
| 1018 | `superinterface_call` | 20 | 5.7s |  |
| 1019 | `superinterface_instanceof` | 18 | 5.7s |  |
| 1020 | `swf8` | 1 | 5.6s |  |
| 1021 | `swf_10_queued_goto_scripts_construct` | 52 | 21.9s |  |
| 1022 | `swf_9_goto_in_enter_frame` | 17 | 5.7s |  |
| 1023 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.7s |  |
| 1024 | `swf_9_queued_goto_scripts` | 6 | 21.9s |  |
| 1025 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 1026 | `swf_9_versioning` | 2 | 5.6s |  |
| 1027 | `swf_wrong_frame_count` | 38 | 6.0s |  |
| 1028 | `swf_wrong_frame_count_isplaying` | 22 | 5.7s |  |
| 1029 | `symbol_class_binary_data` | 8 | 5.7s |  |
| 1030 | `symbol_class_conflict` | 4 | 5.8s |  |
| 1031 | `symbol_class_root_not_zero` | 1 | 5.6s |  |
| 1032 | `symbolclass_invalid_utf8` | 2 | 5.7s |  |
| 1033 | `system_exit` | 3 | 5.6s |  |
| 1034 | `system_setclipboard_null` | 1 | 5.6s |  |
| 1035 | `tab_ordering_arrows` | 998 | 23.1s |  |
| 1036 | `tab_ordering_automatic_advanced` | 184 | 6.3s |  |
| 1037 | `tab_ordering_automatic_basic` | 45 | 5.8s |  |
| 1038 | `tab_ordering_children` | 116 | 6.0s |  |
| 1039 | `tab_ordering_custom_basic` | 34 | 5.8s |  |
| 1040 | `tab_ordering_properties` | 732 | 6.0s |  |
| 1041 | `tab_ordering_stage_tab_children` | 32 | 26.5s |  |
| 1042 | `tab_ordering_stage_tab_children_remove_root` | 5 | 5.9s |  |
| 1043 | `tab_ordering_tabbable` | 47 | 5.9s |  |
| 1044 | `tabstop_properties` | 105 | 26.6s |  |
| 1045 | `text_element_basic` | 34 | 5.9s |  |
| 1046 | `text_engine_fontdescription` | 27 | 5.9s |  |
| 1047 | `text_engine_groupelement` | 64 | 5.9s |  |
| 1048 | `text_run` | 7 | 5.9s |  |
| 1049 | `textblock_createline_errors` | 23 | 6.0s |  |
| 1050 | `textblock_createline_fte` | 9 | 26.6s |  |
| 1051 | `textblock_properties` | 118 | 6.0s |  |
| 1052 | `textbox_click` | 37 | 26.7s |  |
| 1053 | `textfield_event` | 66 | 6.0s |  |
| 1054 | `textfield_focusin_event` | 9 | 5.9s |  |
| 1055 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 1056 | `textfield_input_events` | 25 | 9.0s |  |
| 1057 | `textfield_unload` | 39 | 26.8s |  |
| 1058 | `textformat` | 1134 | 5.9s |  |
| 1059 | `textformat_display` | 14 | 5.9s |  |
| 1060 | `textformat_font_max_length` | 4 | 5.9s |  |
| 1061 | `textjustifier_locale` | 132 | 5.9s |  |
| 1062 | `textline_has_tabs` | 47 | 5.9s |  |
| 1063 | `textline_inapplicable_properties` | 10 | 5.9s |  |
| 1064 | `textline_name` | 1 | 5.9s |  |
| 1065 | `textline_raw_text_length` | 30 | 5.9s |  |
| 1066 | `textline_splitting_basic` | 76 | 5.9s |  |
| 1067 | `textline_throwerror` | 30 | 5.9s |  |
| 1068 | `textline_validity` | 162 | 5.9s |  |
| 1069 | `throw` | 3 | 6.0s |  |
| 1070 | `timeline_scripts` | 3 | 26.7s |  |
| 1071 | `timer` | 90 | 5.9s |  |
| 1072 | `timer_events` | 3 | 5.9s |  |
| 1073 | `timer_finished` | 11 | 5.8s |  |
| 1074 | `timer_invalid_delay` | 30 | 5.9s |  |
| 1075 | `timer_reset` | 8 | 5.9s |  |
| 1076 | `timer_setdelay` | 5 | 5.9s |  |
| 1077 | `trace` | 12 | 21.8s |  |
| 1078 | `truthiness` | 30 | 5.7s |  |
| 1079 | `try_catch` | 11 | 5.8s |  |
| 1080 | `try_catch_typed` | 12 | 5.8s |  |
| 1081 | `typeof` | 30 | 5.7s |  |
| 1082 | `uint_constr` | 92 | 5.9s |  |
| 1083 | `uint_tofixed` | 1215 | 5.6s |  |
| 1084 | `uint_toprecision` | 1125 | 5.8s |  |
| 1085 | `uint_tostring` | 3375 | 5.9s |  |
| 1086 | `uncaught_error_basic` | 2 | 5.6s |  |
| 1087 | `unchecked_function` | 15 | 5.7s |  |
| 1088 | `unescape` | 28 | 5.8s |  |
| 1089 | `url_loader` | 25 | 5.9s |  |
| 1090 | `url_vars` | 27 | 5.8s |  |
| 1091 | `urlrequest` | 18 | 21.5s |  |
| 1092 | `urlstream_basic` | 5 | 5.7s |  |
| 1093 | `urshift` | 1058 | 12.8s |  |
| 1094 | `utils3d` | 7 | 5.6s |  |
| 1095 | `vector3d` | 397 | 8.5s |  |
| 1096 | `vector3d_near_equals` | 80 | 5.7s |  |
| 1097 | `vector_class` | 36 | 6.0s |  |
| 1098 | `vector_class_call` | 11 | 5.8s |  |
| 1099 | `vector_coercion` | 66 | 6.3s |  |
| 1100 | `vector_concat` | 90 | 6.1s |  |
| 1101 | `vector_constr` | 107 | 6.2s |  |
| 1102 | `vector_enumeration` | 5 | 5.6s |  |
| 1103 | `vector_every` | 92 | 6.3s |  |
| 1104 | `vector_filter` | 95 | 6.3s |  |
| 1105 | `vector_holes` | 24 | 5.7s |  |
| 1106 | `vector_indexof` | 302 | 8.5s |  |
| 1107 | `vector_insertat` | 270 | 6.4s |  |
| 1108 | `vector_int_access` | 4 | 5.5s |  |
| 1109 | `vector_int_delete` | 11 | 5.5s |  |
| 1110 | `vector_join` | 58 | 5.9s |  |
| 1111 | `vector_lastindexof` | 302 | 5.5s |  |
| 1112 | `vector_legacy` | 10 | 5.6s |  |
| 1113 | `vector_map` | 85 | 6.1s |  |
| 1114 | `vector_object_final` | 1 | 5.4s |  |
| 1115 | `vector_object_toString` | 10 | 5.5s |  |
| 1116 | `vector_prototype_some` | 125 | 5.6s |  |
| 1117 | `vector_pushpop` | 255 | 5.8s |  |
| 1118 | `vector_reborrow_bug` | 10 | 4.9s |  |
| 1119 | `vector_removeat` | 172 | 5.5s |  |
| 1120 | `vector_reverse` | 232 | 5.5s |  |
| 1121 | `vector_shiftunshift` | 252 | 1.6s |  |
| 1122 | `vector_slice` | 331 | 5.9s |  |
| 1123 | `vector_sort` | 905 | 10.4s |  |
| 1124 | `vector_splice` | 693 | 7.0s |  |
| 1125 | `vector_splice_fixed_bug_compat` | 4 | 4.8s |  |
| 1126 | `vector_tostring` | 79 | 5.2s |  |
| 1127 | `verification` | 8 | 4.9s |  |
| 1128 | `verify_abnormal_loop` | 1 | 4.8s |  |
| 1129 | `verify_dxns_without_flag` | 3 | 5.2s |  |
| 1130 | `verify_exception_target_two_jumps` | 1 | 4.9s |  |
| 1131 | `verify_exception_targets_edge_case` | 1 | 4.9s |  |
| 1132 | `verify_illegal_opcode` | 1 | 1.8s |  |
| 1133 | `verify_jump_to_middle_of_op` | 1 | 4.9s |  |
| 1134 | `verify_lookup_switch_edge_case` | 1 | 4.8s |  |
| 1135 | `verify_method_info_oob` | 1 | 0.4s |  |
| 1136 | `verify_stack` | 5 | 4.9s |  |
| 1137 | `verify_typecheck` | 4 | 4.9s |  |
| 1138 | `verify_unreachable_exception` | 2 | 4.8s |  |
| 1139 | `versioned_isplaying` | 2 | 4.9s |  |
| 1140 | `virtual_properties` | 16 | 4.9s |  |
| 1141 | `with` | 4 | 4.9s |  |
| 1142 | `wrong_arg_count` | 7 | 4.9s |  |
| 1143 | `xml_abstract_equality` | 36 | 5.0s |  |
| 1144 | `xml_advanced` | 52 | 1.6s |  |
| 1145 | `xml_appendchild` | 10 | 4.8s |  |
| 1146 | `xml_appendchild_swf_v21` | 13 | 5.1s |  |
| 1147 | `xml_as_attribute` | 9 | 4.9s |  |
| 1148 | `xml_attribute` | 35 | 5.0s |  |
| 1149 | `xml_attribute_name` | 40 | 5.0s |  |
| 1150 | `xml_basic` | 33 | 5.0s |  |
| 1151 | `xml_child` | 25 | 5.0s |  |
| 1152 | `xml_childindex` | 7 | 5.0s |  |
| 1153 | `xml_children` | 43 | 5.3s |  |
| 1154 | `xml_class_call` | 9 | 4.8s |  |
| 1155 | `xml_contains` | 197 | 5.0s |  |
| 1156 | `xml_copy` | 20 | 5.6s |  |
| 1157 | `xml_ctor_from_tostring` | 23 | 5.6s |  |
| 1158 | `xml_delete` | 114 | 5.7s |  |
| 1159 | `xml_descendants` | 83 | 5.6s |  |
| 1160 | `xml_duplicate_attribute` | 14 | 5.5s |  |
| 1161 | `xml_elements` | 6 | 5.5s |  |
| 1162 | `xml_equals_namespace_check` | 2 | 5.5s |  |
| 1163 | `xml_explicit_use_namespace` | 5 | 5.4s |  |
| 1164 | `xml_getdescendants_qname` | 21 | 5.5s |  |
| 1165 | `xml_has_property_via_in` | 26 | 5.5s |  |
| 1166 | `xml_hasownproperty` | 6 | 5.5s |  |
| 1167 | `xml_ignore_white` | 6 | 5.5s |  |
| 1168 | `xml_length` | 2 | 5.5s |  |
| 1169 | `xml_list_as_attribute` | 9 | 5.5s |  |
| 1170 | `xml_list_concat` | 20 | 5.6s |  |
| 1171 | `xml_list_ctor_errors` | 34 | 5.5s |  |
| 1172 | `xml_list_delete_clear_parent` | 6 | 5.5s |  |
| 1173 | `xml_list_enumerate` | 4 | 5.5s |  |
| 1174 | `xml_methods_settings` | 3 | 5.5s |  |
| 1175 | `xml_mismatched_tag` | 45 | 5.5s |  |
| 1176 | `xml_namespace` | 39 | 5.5s |  |
| 1177 | `xml_namespace_methods` | 245 | 5.6s |  |
| 1178 | `xml_namespaced_property` | 7 | 5.5s |  |
| 1179 | `xml_no_namespace` | 1 | 5.5s |  |
| 1180 | `xml_nodekind` | 3 | 5.5s |  |
| 1181 | `xml_normalize` | 35 | 5.6s |  |
| 1182 | `xml_notification_bubbling` | 361 | 5.6s |  |
| 1183 | `xml_parent` | 8 | 5.6s |  |
| 1184 | `xml_set_children` | 17 | 5.6s |  |
| 1185 | `xml_set_name` | 34 | 1.6s |  |
| 1186 | `xml_settings` | 6 | 1.6s |  |
| 1187 | `xml_simple_complex_content` | 47 | 5.6s |  |
| 1188 | `xml_socket` | 11 | 5.6s |  |
| 1189 | `xml_text` | 7 | 5.5s |  |
| 1190 | `xml_tostring` | 6 | 5.5s |  |
| 1191 | `xml_tostring_namespace` | 12 | 5.3s |  |
| 1192 | `xml_unescaping` | 23 | 5.5s |  |
| 1193 | `xml_weird_ignores` | 54 | 5.8s |  |
| 1194 | `xml_wildcard` | 11 | 5.8s |  |
| 1195 | `xmldocument` | 254 | 5.9s |  |
| 1196 | `xmlnode` | 3540 | 6.0s |  |
| 1197 | `zero_frame_clip` | 3 | 5.9s |  |

## Ruffle-Matched Tests

**18 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.8s |  |
| 2 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 21.3s |  |
| 3 | `error_1034_debug_string` | 19 | 19 | 7.5s |  |
| 4 | `goto_framescript_queued/swf13` | 3 | 3 | 21.9s |  |
| 5 | `gradient_values_readback` | 12 | 12 | 5.9s |  |
| 6 | `groupelement_text` | 2 | 2 | 5.6s |  |
| 7 | `html_text_img_parsing` | 95 | 95 | 5.6s |  |
| 8 | `json_parse_numbers` | 4 | 79 | 8.1s |  |
| 9 | `loader_events_2` | 30 | 30 | 8.5s |  |
| 10 | `matrix3d_recompose_edge_cases` | 8 | 85 | 6.0s |  |
| 11 | `number_convert_errors` | 706 | 706 | 6.1s |  |
| 12 | `number_to_string` | 104 | 104 | 6.3s |  |
| 13 | `textblock_line_changes` | 44 | 44 | 6.0s |  |
| 14 | `textblock_recreateline` | 137 | 138 | 5.9s |  |
| 15 | `textblock_releaselines` | 4 | 4 | 5.9s |  |
| 16 | `textline_atom_index_at_char_index` | 3 | 3 | 6.2s |  |
| 17 | `uncaught_errors_stringified` | 15 | 15 | 5.7s |  |
| 18 | `vector_indexing_cutoffs` | 1 | 1 | 5.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `error_stack_trace_class_names` | 94.1% | 127 | 135 | 8 |  |
| 2 | `array_join_reentrant` | 85.3% | 58 | 68 | 10 |  |
| 3 | `edittext_set_text_same` | 80.0% | 92 | 115 | 23 |  |
| 4 | `weird_number_bound_methods` | 75.0% | 9 | 12 | 3 |  |
| 5 | `hit_test_scroll_rect` | 69.7% | 69 | 99 | 30 |  |
| 6 | `error_stack_trace_limit` | 69.1% | 600 | 868 | 268 |  |
| 7 | `event_handler_exception` | 63.6% | 7 | 11 | 4 |  |
| 8 | `edittext_set_text_same_after_edits` | 60.9% | 84 | 138 | 54 |  |
| 9 | `dictionary_qname_keys` | 50.9% | 29 | 57 | 28 |  |
| 10 | `xml_many_namespace_declarations` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**36 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `error_stack_trace_class_names` | 94.1% | 127/135 | 135 | 135 |  |
| 2 | `array_join_reentrant` | 85.3% | 58/68 | 68 | 68 |  |
| 3 | `edittext_set_text_same` | 80.0% | 92/115 | 115 | 115 |  |
| 4 | `weird_number_bound_methods` | 75.0% | 9/12 | 12 | 12 |  |
| 5 | `hit_test_scroll_rect` | 69.7% | 69/99 | 99 | 99 |  |
| 6 | `error_stack_trace_limit` | 69.1% | 600/868 | 868 | 674 |  |
| 7 | `event_handler_exception` | 63.6% | 7/11 | 11 | 11 |  |
| 8 | `edittext_set_text_same_after_edits` | 60.9% | 84/138 | 138 | 138 |  |
| 9 | `dictionary_qname_keys` | 50.9% | 29/57 | 57 | 45 |  |
| 10 | `xml_many_namespace_declarations` | 50.0% | 1/2 | 2 | 2 |  |
| 11 | `primitive_bound_methods` | 45.5% | 5/11 | 11 | 11 |  |
| 12 | `loaderinfo_root_progress` | 42.9% | 3/7 | 6 | 7 |  |
| 13 | `loaderinfo_root_progress_goto` | 40.0% | 4/10 | 6 | 10 |  |
| 14 | `displayobjectcontainer_removechildren_events` | 36.2% | 21/58 | 58 | 56 |  |
| 15 | `stage3d_missing_vertex_stream` | 35.1% | 13/37 | 27 | 37 |  |
| 16 | `textfield_default_text_format_null` | 35.0% | 7/20 | 12 | 20 |  |
| 17 | `amf_xmllist` | 33.3% | 4/12 | 12 | 12 |  |
| 18 | `displayobjectcontainer_remove_reparent` | 31.2% | 59/189 | 185 | 189 |  |
| 19 | `xml_unescaping_nul_char_ref` | 21.1% | 4/19 | 19 | 19 |  |
| 20 | `perspective_projection_center` | 17.6% | 6/34 | 26 | 34 |  |
| 21 | `context3d_draw_to_bitmap_data` | 13.3% | 2/15 | 11 | 15 |  |
| 22 | `vector_join_reentrant` | 10.4% | 10/96 | 84 | 96 |  |
| 23 | `array_sort_arguments` | 9.5% | 42/442 | 277 | 442 |  |
| 24 | `array_constructor` | 9.0% | 21/234 | 181 | 234 |  |
| 25 | `textfield_set_text_format_args` | 9.0% | 81/904 | 638 | 904 |  |
| 26 | `textfield_get_text_format_args` | 8.8% | 50/567 | 447 | 567 |  |
| 27 | `shared_object_get_local_error` | 4.8% | 1/21 | 5 | 21 |  |
| 28 | `bitmapdata_encode_png_roundtrip` | 3.0% | 1/33 | 4 | 33 |  |
| 29 | `worker_terminate` | 1.8% | 1/56 | 3 | 56 |  |
| 30 | `bitmapdata_encode` | 0.7% | 1/147 | 5 | 147 |  |
| 31 | `vector_sort_arguments` | 0.3% | 1/355 | 198 | 355 |  |
| 32 | `displayobjectcontainer_remove_reentrant` | 0.0% | 2/27942 | 27942 | 257 |  |
| 33 | `bitmapdata_encode_jpeg_visual` | 0.0% | 0/3 | 3 | 0 |  |
| 34 | `bitmapdata_encode_png_visual` | 0.0% | 0/3 | 3 | 0 |  |
| 35 | `edittext_event_link_case_insensitive` | 0.0% | 0/1 | 0 | 1 |  |
| 36 | `textline_metrics` | 0.0% | 0/20 | 20 | 20 |  |
