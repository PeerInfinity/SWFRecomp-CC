# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 19:30 UTC

**Git SHA**: `bc91565cea`

**Run Duration**: 184m 40s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1289 |
| Passing | **1198** (92.9%) |
| Ruffle-matched | 42 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1240** (96.2%) |
| Failing | 49 |
| Total expected lines | 161988 |
| Matching lines | 156112 (96.4%) |
| Mismatched lines | 5876 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 49 | 100.0% |

## Passing Tests

**1198 tests passing**

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
| 186 | `bytearray_oom` | 3 | 5.5s |  |
| 187 | `bytearray_readobject_amf0` | 50 | 5.5s |  |
| 188 | `bytearray_readobject_amf3` | 53 | 5.6s |  |
| 189 | `bytearray_readutf8bytes_with_bom` | 16 | 5.5s |  |
| 190 | `bytearray_serialization` | 3 | 5.5s |  |
| 191 | `bytearray_string_null` | 19 | 5.7s |  |
| 192 | `bytearray_tostring` | 15 | 5.5s |  |
| 193 | `bytearray_utf16` | 8 | 5.5s |  |
| 194 | `bytearray_writeobject` | 24 | 5.3s |  |
| 195 | `callee_in_initializer` | 6 | 5.4s |  |
| 196 | `callproplex_class` | 1 | 5.4s |  |
| 197 | `capabilities_resolution` | 8 | 22.2s |  |
| 198 | `casi32` | 166 | 5.5s |  |
| 199 | `catch_class` | 6 | 5.5s |  |
| 200 | `catch_scope_slot` | 7 | 5.5s |  |
| 201 | `checkfilter` | 4 | 1.6s |  |
| 202 | `class_call` | 32 | 5.7s |  |
| 203 | `class_cast_call` | 14 | 5.5s |  |
| 204 | `class_enumeration` | 4 | 5.5s |  |
| 205 | `class_has_own_property` | 2 | 5.5s |  |
| 206 | `class_init_interpreter_mode` | 1 | 5.4s |  |
| 207 | `class_is` | 32 | 5.4s |  |
| 208 | `class_methods` | 5 | 5.5s |  |
| 209 | `class_object_properties` | 10 | 5.5s |  |
| 210 | `class_singleton` | 18 | 5.5s |  |
| 211 | `class_supercalls_errors` | 35 | 5.9s |  |
| 212 | `class_supercalls_mismatched` | 26 | 5.8s |  |
| 213 | `class_superclass_wrong_order` | 1 | 5.6s |  |
| 214 | `class_to_locale_string` | 2 | 5.6s |  |
| 215 | `class_to_string` | 2 | 5.6s |  |
| 216 | `class_value_of` | 2 | 5.6s |  |
| 217 | `click_block` | 5 | 22.5s |  |
| 218 | `click_invisible` | 3 | 5.8s |  |
| 219 | `closures` | 12 | 5.7s |  |
| 220 | `coerce_return_type` | 40 | 5.8s |  |
| 221 | `coerce_return_type_fail` | 2 | 5.6s |  |
| 222 | `coerce_return_void` | 3 | 5.6s |  |
| 223 | `coerce_string` | 86 | 5.8s |  |
| 224 | `coerce_string_precision` | 28 | 5.7s |  |
| 225 | `coerce_to_primitive_side_effects` | 29 | 5.8s |  |
| 226 | `collator_compare_basic` | 93 | 5.8s |  |
| 227 | `collator_flags` | 111 | 5.7s |  |
| 228 | `collator_locale_ids_windows` | 120 | 5.8s |  |
| 229 | `color_matrix_filter` | 19 | 5.8s |  |
| 230 | `construct_errors_swf10` | 8 | 5.8s |  |
| 231 | `construct_frame_list` | 22 | 5.8s |  |
| 232 | `construct_interface` | 3 | 5.7s |  |
| 233 | `constructor_call` | 3 | 5.7s |  |
| 234 | `constructors_vs_timeline` | 5 | 22.3s |  |
| 235 | `constructprop_dynamic_primitive` | 7 | 5.8s |  |
| 236 | `constructprop_method` | 2 | 5.7s |  |
| 237 | `constructsuper_null` | 2 | 1.7s |  |
| 238 | `content_element_basic` | 50 | 6.0s |  |
| 239 | `context3d_clear_mask` | 4 | 5.7s |  |
| 240 | `context3d_creation` | 9 | 5.8s |  |
| 241 | `control_flow_bool` | 4 | 5.8s |  |
| 242 | `control_flow_stricteq` | 8 | 5.8s |  |
| 243 | `convert_boolean` | 30 | 5.8s |  |
| 244 | `convert_integer` | 90 | 5.9s |  |
| 245 | `convert_number` | 56 | 5.8s |  |
| 246 | `convert_uinteger` | 90 | 5.8s |  |
| 247 | `convolution_filter` | 89 | 5.9s |  |
| 248 | `core_exceptions` | 47 | 6.8s |  |
| 249 | `cpool_index_invalid_bytecode_1` | 6 | 5.8s |  |
| 250 | `cpool_index_invalid_bytecode_2` | 3 | 5.8s |  |
| 251 | `cpool_index_invalid_bytecode_3` | 1 | 5.8s |  |
| 252 | `cross_api_version_call_newer` | 12 | 6.3s |  |
| 253 | `cross_api_version_call_older` | 12 | 6.1s |  |
| 254 | `cryptscore` | 11 | 5.8s |  |
| 255 | `currency_parse_result` | 7 | 5.6s |  |
| 256 | `date` | 30 | 6.1s |  |
| 257 | `date_parse` | 36 | 5.6s |  |
| 258 | `date_set_time_out_of_range` | 62 | 5.6s |  |
| 259 | `declocal` | 46 | 5.7s |  |
| 260 | `declocal_i` | 46 | 5.7s |  |
| 261 | `decode_uri` | 71 | 5.9s |  |
| 262 | `decrement` | 46 | 5.7s |  |
| 263 | `decrement_i` | 46 | 1.7s |  |
| 264 | `default_values` | 7 | 5.7s |  |
| 265 | `delayed_symbolclass` | 28 | 5.9s |  |
| 266 | `describe_type_basic` | 152 | 5.8s |  |
| 267 | `describe_type_json` | 301 | 5.9s |  |
| 268 | `describe_type_metadata` | 125 | 5.8s |  |
| 269 | `describe_type_native` | 23 | 5.7s |  |
| 270 | `dictionary_access` | 62 | 5.9s |  |
| 271 | `dictionary_access_no_pubns` | 2 | 5.6s |  |
| 272 | `dictionary_delete` | 101 | 6.1s |  |
| 273 | `dictionary_foreach` | 42 | 6.0s |  |
| 274 | `dictionary_hasownproperty` | 63 | 5.9s |  |
| 275 | `dictionary_in` | 62 | 5.9s |  |
| 276 | `dictionary_iter_modify` | 8 | 5.7s |  |
| 277 | `dictionary_namespaces` | 36 | 5.8s |  |
| 278 | `displacement_map_filter` | 61 | 1.8s |  |
| 279 | `displayobject_alpha` | 277 | 5.7s |  |
| 280 | `displayobject_blendmode` | 0 | 5.7s |  |
| 281 | `displayobject_colortransform_nested` | 0 | 5.8s |  |
| 282 | `displayobject_early_init` | 54 | 7.1s |  |
| 283 | `displayobject_filters` | 17 | 5.8s |  |
| 284 | `displayobject_from_enterframe` | 1 | 5.8s |  |
| 285 | `displayobject_getbounds_shape` | 0 | 22.0s |  |
| 286 | `displayobject_getrect` | 16 | 5.9s |  |
| 287 | `displayobject_height` | 6052 | 5.9s |  |
| 288 | `displayobject_hittestobject` | 32 | 5.8s |  |
| 289 | `displayobject_hittestpoint` | 49 | 1.8s |  |
| 290 | `displayobject_hittestpoint_boundary` | 65 | 22.4s |  |
| 291 | `displayobject_hittestpoint_root` | 13 | 5.9s |  |
| 292 | `displayobject_invalid_floats` | 60 | 5.7s |  |
| 293 | `displayobject_invalid_props` | 3 | 5.7s |  |
| 294 | `displayobject_mask` | 3 | 5.7s |  |
| 295 | `displayobject_mask_self_referential` | 0 | 21.6s |  |
| 296 | `displayobject_metaData` | 3 | 5.6s |  |
| 297 | `displayobject_name` | 22 | 22.2s |  |
| 298 | `displayobject_name_from_timeline` | 24 | 5.9s |  |
| 299 | `displayobject_opaque_background` | 6 | 22.1s |  |
| 300 | `displayobject_parent` | 12 | 5.7s |  |
| 301 | `displayobject_root` | 24 | 5.7s |  |
| 302 | `displayobject_rotation` | 1284 | 5.7s |  |
| 303 | `displayobject_scrollrect` | 33 | 6.0s |  |
| 304 | `displayobject_set_matrix_nested` | 0 | 21.9s |  |
| 305 | `displayobject_set_name_loaded` | 3 | 6.0s |  |
| 306 | `displayobject_subclass` | 2 | 5.6s |  |
| 307 | `displayobject_transform` | 89 | 5.7s |  |
| 308 | `displayobject_visible` | 23 | 5.7s |  |
| 309 | `displayobject_width` | 4852 | 22.0s |  |
| 310 | `displayobject_x` | 614 | 5.6s |  |
| 311 | `displayobject_y` | 617 | 5.6s |  |
| 312 | `displayobject_z` | 38 | 21.6s |  |
| 313 | `displayobjectcontainer_addchild` | 32 | 5.6s |  |
| 314 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.5s |  |
| 315 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.8s |  |
| 316 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.7s |  |
| 317 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.7s |  |
| 318 | `displayobjectcontainer_addchildat` | 42 | 5.6s |  |
| 319 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.7s |  |
| 320 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.6s |  |
| 321 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.6s |  |
| 322 | `displayobjectcontainer_contains` | 66 | 21.5s |  |
| 323 | `displayobjectcontainer_getchildat` | 4 | 5.6s |  |
| 324 | `displayobjectcontainer_getchildbyname` | 9 | 5.5s |  |
| 325 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.5s |  |
| 326 | `displayobjectcontainer_getchildindex` | 28 | 5.5s |  |
| 327 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 21.4s |  |
| 328 | `displayobjectcontainer_removechild` | 10 | 5.5s |  |
| 329 | `displayobjectcontainer_removechild_errors` | 4 | 5.5s |  |
| 330 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.6s |  |
| 331 | `displayobjectcontainer_removechildat` | 18 | 5.5s |  |
| 332 | `displayobjectcontainer_removechildren` | 51 | 5.7s |  |
| 333 | `displayobjectcontainer_setchildindex` | 42 | 5.4s |  |
| 334 | `displayobjectcontainer_stopallmovieclips` | 2 | 21.4s |  |
| 335 | `displayobjectcontainer_swapchildren` | 42 | 5.6s |  |
| 336 | `displayobjectcontainer_swapchildrenat` | 42 | 5.6s |  |
| 337 | `displayobjectcontainer_timelineinstance` | 48 | 21.8s |  |
| 338 | `divide` | 1058 | 12.9s |  |
| 339 | `doabc_and_symbolclass_script_init_goto` | 7 | 22.0s |  |
| 340 | `doabc_and_symbolclass_script_init_normal` | 6 | 5.6s |  |
| 341 | `doabc_is_eager` | 1 | 21.6s |  |
| 342 | `documentclass` | 9 | 5.7s |  |
| 343 | `domain_memory` | 133 | 6.5s |  |
| 344 | `drag_drop` | 10 | 5.7s |  |
| 345 | `drop_shadow_filter` | 172 | 5.7s |  |
| 346 | `duplicate_defs` | 1 | 5.4s |  |
| 347 | `eager_init` | 1 | 5.6s |  |
| 348 | `east_asian_justifier_clone` | 8 | 5.6s |  |
| 349 | `edit_text_linkage` | 7 | 5.7s |  |
| 350 | `edittext_align` | 60 | 6.0s |  |
| 351 | `edittext_always_show_selection` | 0 | 21.8s |  |
| 352 | `edittext_antialiastype` | 296 | 6.0s |  |
| 353 | `edittext_at_point_methods_basic` | 16 | 6.6s |  |
| 354 | `edittext_autosize` | 39 | 6.1s |  |
| 355 | `edittext_autosize_align` | 0 | 22.0s |  |
| 356 | `edittext_autosize_height_dynamic` | 60 | 21.9s |  |
| 357 | `edittext_autosize_height_input` | 60 | 5.7s |  |
| 358 | `edittext_autosize_lazy_bounds_events` | 65 | 5.8s |  |
| 359 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.7s |  |
| 360 | `edittext_autosize_lazy_bounds_props` | 490 | 7.0s |  |
| 361 | `edittext_autosize_lazy_bounds_visual` | 0 | 5.7s |  |
| 362 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.8s |  |
| 363 | `edittext_bottom_scroll_v_basic` | 210 | 5.7s |  |
| 364 | `edittext_bounds_scale` | 24 | 5.7s |  |
| 365 | `edittext_bullet` | 30 | 5.8s |  |
| 366 | `edittext_default_format` | 221 | 6.1s |  |
| 367 | `edittext_default_format_empty` | 136 | 5.9s |  |
| 368 | `edittext_empty_text_format` | 7 | 5.7s |  |
| 369 | `edittext_focus_selection` | 5 | 5.6s |  |
| 370 | `edittext_font_size` | 45 | 5.8s |  |
| 371 | `edittext_format_empty_font` | 8 | 5.5s |  |
| 372 | `edittext_get_char_index_at_point` | 4 | 23.3s |  |
| 373 | `edittext_get_line_index_at_point` | 2 | 22.3s |  |
| 374 | `edittext_get_line_index_of_char` | 76 | 6.5s |  |
| 375 | `edittext_getcharboundaries` | 172 | 6.0s |  |
| 376 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.7s |  |
| 377 | `edittext_getcharboundaries_scroll` | 85 | 5.8s |  |
| 378 | `edittext_getlinemetrics` | 146 | 5.9s |  |
| 379 | `edittext_html` | 3101 | 6.0s |  |
| 380 | `edittext_html_condensewhite` | 487 | 5.7s |  |
| 381 | `edittext_html_entity` | 4 | 5.9s |  |
| 382 | `edittext_html_font_size_swf12` | 267 | 5.7s |  |
| 383 | `edittext_html_font_size_swf13` | 273 | 5.3s |  |
| 384 | `edittext_html_roundtrip` | 17 | 5.7s |  |
| 385 | `edittext_ime_focus_lost` | 9 | 5.6s |  |
| 386 | `edittext_input_control` | 12 | 5.6s |  |
| 387 | `edittext_leading` | 9 | 5.9s |  |
| 388 | `edittext_letter_spacing` | 15 | 5.6s |  |
| 389 | `edittext_line_methods` | 294 | 6.7s |  |
| 390 | `edittext_line_metrics` | 11 | 22.8s |  |
| 391 | `edittext_margins` | 25 | 5.7s |  |
| 392 | `edittext_max_scroll_h_basic` | 475 | 5.8s |  |
| 393 | `edittext_max_scroll_v_basic` | 1000 | 5.7s |  |
| 394 | `edittext_mouse_selection` | 363 | 22.6s |  |
| 395 | `edittext_mousedown` | 3 | 5.8s |  |
| 396 | `edittext_mouseenabled` | 26 | 5.7s |  |
| 397 | `edittext_newline_character` | 22 | 5.6s |  |
| 398 | `edittext_newline_stripping` | 64 | 11.1s |  |
| 399 | `edittext_newlines` | 30 | 5.7s |  |
| 400 | `edittext_paragraph_methods` | 257 | 5.6s |  |
| 401 | `edittext_paste_events` | 8 | 5.6s |  |
| 402 | `edittext_paste_maxchars` | 4 | 5.7s |  |
| 403 | `edittext_paste_restrict` | 16 | 5.5s |  |
| 404 | `edittext_restrict` | 191 | 1.7s |  |
| 405 | `edittext_restrict_events` | 22 | 5.6s |  |
| 406 | `edittext_scroll_event` | 37 | 5.8s |  |
| 407 | `edittext_scrollh` | 10 | 5.6s |  |
| 408 | `edittext_selected_text` | 9 | 5.6s |  |
| 409 | `edittext_set_html_same` | 17 | 5.6s |  |
| 410 | `edittext_set_text_vs_html` | 9 | 5.5s |  |
| 411 | `edittext_stylesheet` | 536 | 6.0s |  |
| 412 | `edittext_stylesheet_custom_tag` | 76 | 5.7s |  |
| 413 | `edittext_stylesheet_display` | 272 | 5.7s |  |
| 414 | `edittext_tag_indent` | 49 | 17.9s |  |
| 415 | `edittext_underline` | 40 | 5.8s |  |
| 416 | `edittext_width_height` | 103 | 5.9s |  |
| 417 | `edittext_wordwrap_word` | 150 | 5.7s |  |
| 418 | `edittext_wrap_breaks` | 2375 | 6.1s |  |
| 419 | `element_format_clone` | 44 | 7.8s |  |
| 420 | `element_format_constructor_order` | 64 | 7.9s |  |
| 421 | `element_format_properties` | 235 | 9.0s |  |
| 422 | `empty_bounds` | 1 | 7.4s |  |
| 423 | `encode_uri_surrogate_pair_invalid` | 8 | 7.3s |  |
| 424 | `encode_uri_surrogate_pair_swf11` | 15 | 7.0s |  |
| 425 | `equals` | 512 | 10.6s |  |
| 426 | `error_geterrormessage` | 779 | 7.5s |  |
| 427 | `error_prototype` | 15 | 7.4s |  |
| 428 | `error_stack_trace` | 45 | 7.3s |  |
| 429 | `error_stack_trace_debug_swf17` | 0 | 27.3s |  |
| 430 | `error_stack_trace_debug_swf18` | 0 | 7.0s |  |
| 431 | `error_stack_trace_edge_cases` | 6 | 7.3s |  |
| 432 | `error_stack_trace_release_swf17` | 0 | 2.2s |  |
| 433 | `error_stack_trace_release_swf18` | 0 | 7.0s |  |
| 434 | `error_throwerror` | 103 | 7.4s |  |
| 435 | `error_tostring` | 29 | 7.3s |  |
| 436 | `error_tostring_more` | 86 | 7.4s |  |
| 437 | `es3_inheritance` | 31 | 7.5s |  |
| 438 | `es4_inheritance` | 30 | 7.4s |  |
| 439 | `es4_interfaces` | 30 | 7.4s |  |
| 440 | `es4_method_binding` | 8 | 7.3s |  |
| 441 | `es4_oop_prototypes` | 14 | 7.5s |  |
| 442 | `es4_protected_inheritance` | 6 | 7.5s |  |
| 443 | `escape` | 71 | 7.8s |  |
| 444 | `escape_multi_byte` | 45 | 7.9s |  |
| 445 | `event_bubbles` | 2 | 7.5s |  |
| 446 | `event_cancelable` | 2 | 7.4s |  |
| 447 | `event_clone` | 20 | 7.6s |  |
| 448 | `event_clone_error_redispatch` | 3 | 7.7s |  |
| 449 | `event_clone_on_redispatch` | 10 | 7.7s |  |
| 450 | `event_formattostring` | 31 | 7.7s |  |
| 451 | `event_isdefaultprevented` | 12 | 7.6s |  |
| 452 | `event_target_getter` | 5 | 2.4s |  |
| 453 | `event_target_set` | 9 | 7.5s |  |
| 454 | `event_type` | 1 | 7.5s |  |
| 455 | `event_valueof_tostring` | 18 | 7.7s |  |
| 456 | `eventdispatcher_dispatchevent` | 12 | 7.6s |  |
| 457 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.5s |  |
| 458 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.7s |  |
| 459 | `focusrect_focuslost` | 9 | 21.9s |  |
| 460 | `focusrect_property` | 110 | 21.7s |  |
| 461 | `font_description_clone` | 14 | 5.6s |  |
| 462 | `font_embedded` | 24 | 6.0s |  |
| 463 | `font_enumeratefonts` | 41 | 6.1s |  |
| 464 | `font_enumeratefonts_filter` | 4 | 6.1s |  |
| 465 | `font_enumeratefonts_order` | 9 | 6.5s |  |
| 466 | `font_hasglyphs` | 40 | 6.0s |  |
| 467 | `font_registerfont` | 129 | 6.4s |  |
| 468 | `framelabel_constr` | 5 | 5.5s |  |
| 469 | `function_call` | 12 | 1.6s |  |
| 470 | `function_call_arguments` | 46 | 5.7s |  |
| 471 | `function_call_arguments_enumerate` | 5 | 5.5s |  |
| 472 | `function_call_coercion` | 108 | 5.8s |  |
| 473 | `function_call_default` | 6 | 5.5s |  |
| 474 | `function_call_rest` | 22 | 5.6s |  |
| 475 | `function_call_types` | 3 | 5.5s |  |
| 476 | `function_call_via_apply` | 11 | 5.6s |  |
| 477 | `function_call_via_call` | 3 | 5.5s |  |
| 478 | `function_display_anonymous` | 7 | 1.6s |  |
| 479 | `function_length` | 6 | 5.5s |  |
| 480 | `function_object` | 2 | 5.5s |  |
| 481 | `function_proto` | 5 | 5.5s |  |
| 482 | `function_proto_created` | 61 | 5.6s |  |
| 483 | `function_to_locale_string` | 4 | 5.5s |  |
| 484 | `function_to_string` | 4 | 5.4s |  |
| 485 | `function_type` | 6 | 5.5s |  |
| 486 | `function_unbound_this` | 51 | 5.7s |  |
| 487 | `function_value_of` | 4 | 5.5s |  |
| 488 | `game_input` | 4 | 5.5s |  |
| 489 | `generate_random_bytes` | 3 | 5.5s |  |
| 490 | `geom_transform` | 74 | 21.8s |  |
| 491 | `get_definition_by_name` | 11 | 5.5s |  |
| 492 | `get_qualified_class_name` | 20 | 5.5s |  |
| 493 | `get_qualified_super_class_name` | 18 | 5.5s |  |
| 494 | `get_slot_edge_cases` | 1 | 5.5s |  |
| 495 | `get_timer` | 2 | 1.6s |  |
| 496 | `getglobalslot` | 1 | 5.5s |  |
| 497 | `getouterscope` | 8 | 5.5s |  |
| 498 | `getouterscope_two_classobjects` | 13 | 5.5s |  |
| 499 | `getter_different_namespace_setter` | 2 | 5.4s |  |
| 500 | `glow_filter` | 127 | 5.7s |  |
| 501 | `goto_button_nested_framescript` | 28 | 21.4s |  |
| 502 | `goto_framescript_queued/swf10` | 59 | 21.5s |  |
| 503 | `goto_framescript_queued/swf9` | 52 | 0.4s |  |
| 504 | `goto_framescript_queued_same_frame` | 4 | 21.6s |  |
| 505 | `goto_in_constructframe` | 12 | 21.5s |  |
| 506 | `goto_in_scene_last_frame` | 2 | 21.4s |  |
| 507 | `goto_methods` | 56 | 5.9s |  |
| 508 | `goto_methods_swfver10` | 8 | 5.7s |  |
| 509 | `goto_nested_construct_sibling` | 18 | 5.9s |  |
| 510 | `goto_nested_framescript` | 9 | 5.7s |  |
| 511 | `goto_on_orphan` | 15 | 21.7s |  |
| 512 | `goto_queued_invalid/swf10` | 34 | 21.9s |  |
| 513 | `goto_queued_invalid/swf11` | 43 | 0.4s |  |
| 514 | `goto_queued_invalid/swf9` | 32 | 0.4s |  |
| 515 | `gradient_bevel_filter` | 206 | 5.7s |  |
| 516 | `gradient_glow_filter` | 206 | 5.5s |  |
| 517 | `graphic_linkage` | 9 | 5.7s |  |
| 518 | `graphics_bad_direct_commands` | 5 | 6.0s |  |
| 519 | `graphics_bitmap_fill` | 0 | 22.8s |  |
| 520 | `graphics_bitmaps` | 0 | 5.8s |  |
| 521 | `graphics_direct_commands` | 0 | 5.7s |  |
| 522 | `graphics_draw_triangles` | 98 | 22.1s |  |
| 523 | `graphics_gradients` | 0 | 5.7s |  |
| 524 | `graphics_gradients_nulls` | 0 | 5.5s |  |
| 525 | `graphics_path` | 56 | 5.6s |  |
| 526 | `graphics_round_rects` | 0 | 5.5s |  |
| 527 | `graphics_simple_shapes` | 0 | 5.5s |  |
| 528 | `greaterequals` | 512 | 7.9s |  |
| 529 | `greaterthan` | 512 | 7.9s |  |
| 530 | `has_own_property` | 102 | 6.0s |  |
| 531 | `hasownproperty_namespaces` | 2 | 5.5s |  |
| 532 | `hello_world` | 1 | 5.5s |  |
| 533 | `hittest_morph` | 30 | 5.6s |  |
| 534 | `id3_info` | 8 | 21.2s |  |
| 535 | `if_eq` | 10 | 5.6s |  |
| 536 | `if_gt` | 1 | 5.6s |  |
| 537 | `if_gte` | 10 | 1.6s |  |
| 538 | `if_lt` | 1 | 0.4s |  |
| 539 | `if_lte` | 10 | 5.4s |  |
| 540 | `if_ne` | 7 | 1.6s |  |
| 541 | `if_stricteq` | 6 | 5.5s |  |
| 542 | `if_strictne` | 11 | 7.9s |  |
| 543 | `ime_linux_dead_keys` | 10 | 28.2s |  |
| 544 | `in` | 102 | 8.5s |  |
| 545 | `inclocal` | 46 | 7.9s |  |
| 546 | `inclocal_i` | 46 | 7.9s |  |
| 547 | `increment` | 46 | 7.8s |  |
| 548 | `increment_i` | 46 | 7.8s |  |
| 549 | `indexing_delete` | 75 | 7.9s |  |
| 550 | `indexof_xml` | 10 | 7.9s |  |
| 551 | `init_callee_cached` | 24 | 7.9s |  |
| 552 | `instanceof` | 58 | 8.5s |  |
| 553 | `instantiate_root_character` | 4 | 8.2s |  |
| 554 | `instantiation_on_enter_frame` | 7 | 29.3s |  |
| 555 | `instantiation_on_enterframe_gotoandstop` | 8 | 8.2s |  |
| 556 | `int_constr` | 92 | 8.5s |  |
| 557 | `int_edge_cases` | 19 | 8.3s |  |
| 558 | `int_instanceof` | 3 | 8.2s |  |
| 559 | `int_tofixed` | 1215 | 7.8s |  |
| 560 | `int_toprecision` | 1125 | 8.0s |  |
| 561 | `int_tostring` | 3375 | 8.1s |  |
| 562 | `interactiveobject_enabled` | 25 | 7.8s |  |
| 563 | `interface_namespaces` | 78 | 8.2s |  |
| 564 | `invalid_utf8` | 12 | 8.1s |  |
| 565 | `is_finite` | 46 | 8.0s |  |
| 566 | `is_nan` | 46 | 7.7s |  |
| 567 | `is_prototype_of` | 12 | 7.9s |  |
| 568 | `issue_10221` | 2 | 7.9s |  |
| 569 | `issue_13780` | 12 | 7.9s |  |
| 570 | `issue_14901` | 1 | 7.8s |  |
| 571 | `issue_17675_edittext_paste_maxchars` | 1 | 8.0s |  |
| 572 | `issue_5292` | 5 | 7.9s |  |
| 573 | `issue_8630` | 2 | 8.0s |  |
| 574 | `issue_8630_placeremoveplace` | 15 | 8.1s |  |
| 575 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.9s |  |
| 576 | `issue_8630_scriptremove` | 11 | 7.9s |  |
| 577 | `istype` | 24 | 2.8s |  |
| 578 | `istypelate` | 58 | 8.3s |  |
| 579 | `istypelate_coerce` | 198 | 9.3s |  |
| 580 | `jpeg_loader_context` | 6 | 7.9s |  |
| 581 | `json_errors` | 9 | 28.5s |  |
| 582 | `json_parse` | 21 | 7.8s |  |
| 583 | `json_parse_errors` | 84 | 7.8s |  |
| 584 | `json_stringify` | 12 | 30.4s |  |
| 585 | `json_stringify_function` | 12 | 8.3s |  |
| 586 | `json_stringify_order` | 1 | 8.2s |  |
| 587 | `json_version_gated` | 1 | 8.1s |  |
| 588 | `key_input_80percent` | 1812 | 30.2s |  |
| 589 | `key_input_location` | 126 | 8.2s |  |
| 590 | `key_input_numpad` | 384 | 8.0s |  |
| 591 | `large_preload_from_bytes` | 51 | 12.7s |  |
| 592 | `large_preload_from_url` | 27 | 10.6s |  |
| 593 | `large_preload_image_from_bytes` | 25 | 8.9s |  |
| 594 | `lazyinit` | 17 | 8.1s |  |
| 595 | `lessequals` | 512 | 12.8s |  |
| 596 | `lessthan` | 512 | 12.7s |  |
| 597 | `loader_bitmap_transparency` | 14 | 8.1s |  |
| 598 | `loader_bytes_unknown_content` | 14 | 8.2s |  |
| 599 | `loader_child_getdefinition` | 5 | 8.3s |  |
| 600 | `loader_duplicate_class` | 48 | 10.3s |  |
| 601 | `loader_duplicate_coerce` | 3 | 8.2s |  |
| 602 | `loader_duplicate_coerce_new_domain` | 4 | 7.9s |  |
| 603 | `loader_error_in_root_ctor` | 4 | 8.1s |  |
| 604 | `loader_events` | 92 | 8.5s |  |
| 605 | `loader_image` | 8 | 8.0s |  |
| 606 | `loader_jpegxr` | 2 | 28.6s |  |
| 607 | `loader_jpegxr_alpha` | 1 | 28.8s |  |
| 608 | `loader_loadbytes_events` | 30 | 8.5s |  |
| 609 | `loader_loadbytes_invalid_png` | 4 | 8.0s |  |
| 610 | `loader_loadbytes_url` | 12 | 8.1s |  |
| 611 | `loader_loaderurl` | 6 | 8.4s |  |
| 612 | `loader_method` | 85 | 7.9s |  |
| 613 | `loader_noninteractive_try_click_root` | 5 | 28.6s |  |
| 614 | `loader_reuse` | 38 | 8.1s |  |
| 615 | `loader_try_click_root` | 16 | 8.1s |  |
| 616 | `loader_unknown_content` | 24 | 8.1s |  |
| 617 | `loader_unloadandstop_subclass` | 1 | 8.0s |  |
| 618 | `loader_visibility_interactive` | 1 | 8.0s |  |
| 619 | `loaderinfo_child_progress` | 9 | 8.5s |  |
| 620 | `loaderinfo_events` | 7 | 7.9s |  |
| 621 | `loaderinfo_loadurl` | 12 | 8.0s |  |
| 622 | `loaderinfo_more` | 6 | 8.3s |  |
| 623 | `loaderinfo_properties` | 18 | 28.6s |  |
| 624 | `loaderinfo_properties_not_loaded` | 23 | 8.0s |  |
| 625 | `loaderinfo_quine` | 1005 | 22.2s |  |
| 626 | `loaderinfo_root` | 10 | 5.8s |  |
| 627 | `loaderinfo_root_allows` | 2 | 5.7s |  |
| 628 | `localconnection` | 890 | 7.4s |  |
| 629 | `localconnection_send` | 4 | 5.7s |  |
| 630 | `lshift` | 1058 | 13.0s |  |
| 631 | `mask_reapply` | 1 | 22.0s |  |
| 632 | `math` | 497 | 6.0s |  |
| 633 | `matrix` | 338 | 13.8s |  |
| 634 | `matrix3d` | 57 | 22.8s |  |
| 635 | `matrix3d_append` | 16 | 5.8s |  |
| 636 | `matrix3d_append_prepend_scale` | 86 | 5.8s |  |
| 637 | `matrix3d_append_prepend_translation` | 42 | 5.7s |  |
| 638 | `matrix3d_append_rotation` | 23 | 5.8s |  |
| 639 | `matrix3d_compose` | 34 | 5.9s |  |
| 640 | `matrix3d_constructor_clone` | 15 | 5.7s |  |
| 641 | `matrix3d_copy_column` | 83 | 5.9s |  |
| 642 | `matrix3d_copy_from` | 19 | 5.8s |  |
| 643 | `matrix3d_copy_raw_data_from` | 55 | 1.9s |  |
| 644 | `matrix3d_copy_raw_data_to` | 38 | 5.9s |  |
| 645 | `matrix3d_copy_row` | 83 | 5.6s |  |
| 646 | `matrix3d_copy_to_matrix3d` | 19 | 5.8s |  |
| 647 | `matrix3d_determinant` | 182 | 5.8s |  |
| 648 | `matrix3d_interpolate` | 21 | 5.8s |  |
| 649 | `matrix3d_invert` | 18 | 5.7s |  |
| 650 | `matrix3d_position` | 19 | 5.7s |  |
| 651 | `matrix3d_precision` | 28 | 5.8s |  |
| 652 | `matrix3d_prepend` | 16 | 5.5s |  |
| 653 | `matrix3d_raw_data` | 33 | 5.7s |  |
| 654 | `matrix3d_transform_vector` | 52 | 5.9s |  |
| 655 | `matrix3d_transpose` | 5 | 5.6s |  |
| 656 | `method_association` | 5 | 5.6s |  |
| 657 | `method_without_body` | 3 | 21.5s |  |
| 658 | `missing_external_interface` | 10 | 5.6s |  |
| 659 | `modulo` | 1058 | 12.7s |  |
| 660 | `morph_shape` | 2 | 21.6s |  |
| 661 | `mouse_children` | 192 | 21.7s |  |
| 662 | `mouse_click_events` | 90 | 21.5s |  |
| 663 | `mouse_double_click_events` | 188 | 5.6s |  |
| 664 | `mouse_empty_parent` | 4 | 5.6s |  |
| 665 | `mouse_over_while_dragging` | 3 | 5.6s |  |
| 666 | `mouse_pick_avm1_root` | 2 | 22.0s |  |
| 667 | `mouse_pick_button_mode` | 2 | 21.7s |  |
| 668 | `mouse_pick_dobj_mask` | 4 | 5.7s |  |
| 669 | `mouse_pick_loader_avm1` | 42 | 5.9s |  |
| 670 | `mouse_pick_masking` | 7 | 21.7s |  |
| 671 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 21.2s |  |
| 672 | `mouse_pick_non_interactive_dobj_mask` | 3 | 5.6s |  |
| 673 | `mouse_pick_scroll_rect` | 27 | 21.6s |  |
| 674 | `mouse_pick_scroll_rect_button` | 5 | 5.7s |  |
| 675 | `mouse_pick_scroll_rect_loader` | 5 | 5.8s |  |
| 676 | `mouse_pick_text` | 8 | 5.7s |  |
| 677 | `mouse_sibling` | 8 | 5.6s |  |
| 678 | `mouse_wheel_events` | 36 | 22.4s |  |
| 679 | `mouseevent_constr` | 66 | 5.5s |  |
| 680 | `mouseevent_stagexy` | 35 | 5.6s |  |
| 681 | `mouseevent_valueof_tostring` | 28 | 5.6s |  |
| 682 | `movieclip_addframescript` | 3 | 21.3s |  |
| 683 | `movieclip_addframescript_error` | 9 | 5.6s |  |
| 684 | `movieclip_child_property` | 16 | 5.7s |  |
| 685 | `movieclip_constr` | 21 | 5.7s |  |
| 686 | `movieclip_currentlabels` | 17 | 21.6s |  |
| 687 | `movieclip_currentlabels_dupes1` | 46 | 22.0s |  |
| 688 | `movieclip_currentlabels_dupes2` | 30 | 5.7s |  |
| 689 | `movieclip_currentlabels_dupes3` | 67 | 5.7s |  |
| 690 | `movieclip_currentscene` | 12 | 22.0s |  |
| 691 | `movieclip_dispatchevent` | 430 | 5.8s |  |
| 692 | `movieclip_dispatchevent_cancel` | 102 | 5.8s |  |
| 693 | `movieclip_dispatchevent_handlerorder` | 251 | 5.8s |  |
| 694 | `movieclip_dispatchevent_selfadd` | 80 | 5.7s |  |
| 695 | `movieclip_dispatchevent_target` | 899 | 5.8s |  |
| 696 | `movieclip_displayevents` | 96 | 22.2s |  |
| 697 | `movieclip_displayevents_clickgoto` | 676 | 22.1s |  |
| 698 | `movieclip_displayevents_clickgoto2` | 2001 | 6.2s |  |
| 699 | `movieclip_displayevents_clickplay` | 575 | 5.9s |  |
| 700 | `movieclip_displayevents_clicksymbol` | 562 | 6.0s |  |
| 701 | `movieclip_displayevents_constructframegoto` | 140 | 6.0s |  |
| 702 | `movieclip_displayevents_constructframeplay` | 50 | 5.9s |  |
| 703 | `movieclip_displayevents_constructframesymbol` | 144 | 6.0s |  |
| 704 | `movieclip_displayevents_dblhandler` | 21 | 5.7s |  |
| 705 | `movieclip_displayevents_enterframegoto` | 149 | 6.0s |  |
| 706 | `movieclip_displayevents_enterframeplay` | 48 | 5.8s |  |
| 707 | `movieclip_displayevents_enterframesymbol` | 149 | 22.1s |  |
| 708 | `movieclip_displayevents_exitframegoto` | 106 | 5.8s |  |
| 709 | `movieclip_displayevents_exitframeplay` | 44 | 5.8s |  |
| 710 | `movieclip_displayevents_exitframesymbol` | 135 | 21.9s |  |
| 711 | `movieclip_displayevents_looping` | 63 | 21.7s |  |
| 712 | `movieclip_displayevents_stopped` | 113 | 21.6s |  |
| 713 | `movieclip_displayevents_swap` | 96 | 5.7s |  |
| 714 | `movieclip_displayevents_timeline` | 128 | 21.8s |  |
| 715 | `movieclip_drawrect` | 54 | 21.3s |  |
| 716 | `movieclip_frameconstruct_skipped` | 9 | 5.6s |  |
| 717 | `movieclip_goto_during_frame_script` | 15 | 21.4s |  |
| 718 | `movieclip_goto_overwrite` | 14 | 21.5s |  |
| 719 | `movieclip_goto_scene_last_frame_int` | 1 | 21.4s |  |
| 720 | `movieclip_goto_scene_last_frame_label` | 1 | 5.6s |  |
| 721 | `movieclip_gotoandplay` | 15 | 21.8s |  |
| 722 | `movieclip_gotoandstop` | 13 | 5.6s |  |
| 723 | `movieclip_gotoandstop_children` | 4 | 5.7s |  |
| 724 | `movieclip_gotoandstop_framescripts1` | 4 | 5.6s |  |
| 725 | `movieclip_gotoandstop_framescripts2` | 4 | 1.6s |  |
| 726 | `movieclip_gotoandstop_framescripts_self` | 7 | 21.8s |  |
| 727 | `movieclip_gotoandstop_queueing` | 12 | 5.7s |  |
| 728 | `movieclip_hittest` | 67 | 5.8s |  |
| 729 | `movieclip_next_frame` | 2 | 5.5s |  |
| 730 | `movieclip_next_scene` | 6 | 5.6s |  |
| 731 | `movieclip_play` | 3 | 5.5s |  |
| 732 | `movieclip_prev_frame` | 3 | 5.3s |  |
| 733 | `movieclip_prev_scene` | 7 | 5.6s |  |
| 734 | `movieclip_properties` | 79 | 21.4s |  |
| 735 | `movieclip_queued_noop_goto_swf10` | 9 | 5.6s |  |
| 736 | `movieclip_queued_noop_goto_swf9` | 7 | 0.4s |  |
| 737 | `movieclip_scenes` | 11 | 5.5s |  |
| 738 | `movieclip_soundtransform` | 831 | 23.1s |  |
| 739 | `movieclip_stop` | 1 | 5.5s |  |
| 740 | `movieclip_super_is_symbol` | 20 | 5.7s |  |
| 741 | `movieclip_symbol_constr` | 8 | 5.7s |  |
| 742 | `movieclip_text_mousedown` | 1 | 5.6s |  |
| 743 | `movieclip_willtrigger` | 5 | 5.6s |  |
| 744 | `multiply` | 1058 | 12.9s |  |
| 745 | `namespace_constr` | 253 | 5.8s |  |
| 746 | `namespace_constr_args` | 1 | 5.6s |  |
| 747 | `namespace_enumeration_order` | 7 | 21.7s |  |
| 748 | `nan_scale` | 9 | 5.6s |  |
| 749 | `native_menu_basic` | 19 | 7.5s |  |
| 750 | `navigateToURL_target_normalize` | 107 | 23.4s |  |
| 751 | `negate` | 30 | 5.6s |  |
| 752 | `negative_volume_panned` | 0 | 5.8s |  |
| 753 | `nested_iteration` | 11 | 5.6s |  |
| 754 | `net_getClassByAlias` | 3 | 22.2s |  |
| 755 | `net_navigateToURL` | 57 | 24.2s |  |
| 756 | `net_stream_play_options` | 6 | 5.8s |  |
| 757 | `netconnection_call_with_responder` | 6 | 22.1s |  |
| 758 | `netconnection_close` | 55 | 22.0s |  |
| 759 | `netconnection_properties` | 78 | 5.8s |  |
| 760 | `netconnection_send_remote` | 50 | 5.9s |  |
| 761 | `netconnection_serialize_arrays` | 6 | 5.8s |  |
| 762 | `netfilterevent` | 10 | 5.7s |  |
| 763 | `netstream_client` | 10 | 5.9s |  |
| 764 | `netstream_connect` | 7 | 5.7s |  |
| 765 | `netstream_flv_date` | 4 | 5.7s |  |
| 766 | `newactivation_in_script_init` | 3 | 5.7s |  |
| 767 | `newclass_mismatched` | 4 | 5.7s |  |
| 768 | `newclass_twice` | 3 | 5.7s |  |
| 769 | `nonconflicting_declarations` | 0 | 5.8s |  |
| 770 | `null_void_types` | 8 | 5.8s |  |
| 771 | `number_autoconv` | 21 | 5.8s |  |
| 772 | `number_autoconv_amf` | 132 | 5.8s |  |
| 773 | `number_autoconv_array_sort_32bit` | 1 | 5.8s |  |
| 774 | `number_constr` | 58 | 5.9s |  |
| 775 | `number_convert_edge_cases` | 180 | 22.5s |  |
| 776 | `number_toexponential` | 378 | 5.9s |  |
| 777 | `number_toexponential2` | 35 | 5.9s |  |
| 778 | `number_tofixed` | 378 | 5.8s |  |
| 779 | `number_toprecision` | 350 | 5.9s |  |
| 780 | `obfuscated_class_names` | 3 | 5.8s |  |
| 781 | `object_enumeration` | 10 | 5.7s |  |
| 782 | `object_prototype` | 4 | 5.8s |  |
| 783 | `object_to_locale_string` | 2 | 5.7s |  |
| 784 | `object_to_string` | 2 | 5.7s |  |
| 785 | `object_value_of` | 2 | 1.5s |  |
| 786 | `op_coerce` | 54 | 5.8s |  |
| 787 | `op_coerce_x` | 54 | 5.8s |  |
| 788 | `op_escxattr` | 2 | 5.7s |  |
| 789 | `op_escxelem` | 2 | 5.7s |  |
| 790 | `op_lookupswitch` | 4 | 5.7s |  |
| 791 | `optimize_coerce` | 1 | 5.7s |  |
| 792 | `orphan_movie_complex` | 80 | 22.1s |  |
| 793 | `orphan_movie_reorder` | 111 | 22.2s |  |
| 794 | `orphan_removeobject` | 636 | 22.6s |  |
| 795 | `package_namespace` | 7 | 21.9s |  |
| 796 | `param_default_value_has_zero_cpool_index` | 1 | 5.6s |  |
| 797 | `parent_early_access_child` | 16 | 22.1s |  |
| 798 | `parse_float` | 81 | 5.9s |  |
| 799 | `parse_float_swf10` | 81 | 5.6s |  |
| 800 | `parse_int` | 135 | 6.0s |  |
| 801 | `perspective_projection` | 1443 | 22.3s |  |
| 802 | `perspective_projection_basic` | 40 | 5.7s |  |
| 803 | `pixelbender_ceil` | 77 | 5.8s |  |
| 804 | `pixelbender_conditional` | 138 | 6.0s |  |
| 805 | `pixelbender_conversions` | 270 | 6.0s |  |
| 806 | `pixelbender_dithering` | 8 | 26.2s |  |
| 807 | `pixelbender_div` | 36 | 5.7s |  |
| 808 | `pixelbender_effect_BlurredFocus` | 0 | 28.6s |  |
| 809 | `pixelbender_effect_glassDisplace` | 0 | 10.6s |  |
| 810 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 24.9s |  |
| 811 | `pixelbender_effect_smudge` | 0 | 8.5s |  |
| 812 | `pixelbender_effect_tintype` | 0 | 7.8s |  |
| 813 | `pixelbender_effect_twirl` | 0 | 8.9s |  |
| 814 | `pixelbender_eof` | 7 | 5.7s |  |
| 815 | `pixelbender_images` | 0 | 7.6s |  |
| 816 | `pixelbender_input` | 103 | 22.7s |  |
| 817 | `pixelbender_logicalnot` | 20 | 5.7s |  |
| 818 | `pixelbender_malformed_data` | 190 | 22.7s |  |
| 819 | `pixelbender_multiple_out_params` | 1 | 5.7s |  |
| 820 | `pixelbender_no_out_param` | 6 | 5.7s |  |
| 821 | `pixelbender_outputs` | 13 | 5.9s |  |
| 822 | `pixelbender_padding_bytes` | 22 | 5.8s |  |
| 823 | `pixelbender_param_qualifier` | 512 | 5.8s |  |
| 824 | `pixelbender_parameters` | 1563 | 6.1s |  |
| 825 | `pixelbender_parameters_bool` | 240 | 6.0s |  |
| 826 | `pixelbender_parameters_int_vs_bool` | 54 | 5.8s |  |
| 827 | `pixelbender_parse_errors` | 6 | 5.7s |  |
| 828 | `pixelbender_rsqrt` | 24 | 5.8s |  |
| 829 | `pixelbender_select_kinds` | 8 | 5.9s |  |
| 830 | `pixelbender_shaderdata` | 49 | 5.8s |  |
| 831 | `pixelbender_shaderdata_setter` | 99 | 6.0s |  |
| 832 | `pixelbender_sign` | 60 | 5.9s |  |
| 833 | `pixelbender_vector_output` | 11 | 5.9s |  |
| 834 | `place_and_lookup/swf10` | 33 | 5.7s |  |
| 835 | `place_and_lookup/swf9` | 33 | 29.6s |  |
| 836 | `place_multiple` | 17 | 29.7s |  |
| 837 | `place_object_replace` | 9 | 30.0s |  |
| 838 | `place_object_replace_2` | 24 | 29.9s |  |
| 839 | `place_object_same_depth_frame` | 1 | 8.2s |  |
| 840 | `point` | 132 | 8.8s |  |
| 841 | `primitive_edge_cases` | 1 | 8.0s |  |
| 842 | `primitive_keys` | 54 | 8.0s |  |
| 843 | `primitive_toString` | 277 | 8.3s |  |
| 844 | `primitive_valueOf` | 285 | 7.9s |  |
| 845 | `print_job_options` | 3 | 8.0s |  |
| 846 | `property_is_enumerable` | 114 | 9.3s |  |
| 847 | `property_is_enumerable_reset` | 23 | 8.1s |  |
| 848 | `property_priority` | 22 | 8.4s |  |
| 849 | `property_priority_chained` | 4 | 8.0s |  |
| 850 | `property_priority_definition_names_order` | 2 | 8.4s |  |
| 851 | `property_priority_three_level` | 6 | 8.2s |  |
| 852 | `propertyisenumerable_namespaces` | 6 | 8.0s |  |
| 853 | `prototype_set_null` | 7 | 8.0s |  |
| 854 | `proxy_callproperty` | 24 | 8.1s |  |
| 855 | `proxy_deleteproperty` | 64 | 8.2s |  |
| 856 | `proxy_enumeration` | 34 | 8.1s |  |
| 857 | `proxy_getproperty` | 77 | 8.2s |  |
| 858 | `proxy_hasownproperty` | 8 | 8.0s |  |
| 859 | `proxy_hasproperty` | 32 | 8.3s |  |
| 860 | `proxy_not_overridden` | 54 | 8.1s |  |
| 861 | `proxy_serialize` | 9 | 8.0s |  |
| 862 | `proxy_setproperty` | 42 | 8.1s |  |
| 863 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.0s |  |
| 864 | `qname_constr` | 32 | 8.2s |  |
| 865 | `qname_constr_namespace` | 24 | 8.1s |  |
| 866 | `qname_enumeration` | 9 | 8.1s |  |
| 867 | `qname_indexing` | 23 | 8.2s |  |
| 868 | `qname_tostring` | 25 | 8.2s |  |
| 869 | `qname_valueof` | 29 | 8.2s |  |
| 870 | `rectangle` | 1094 | 8.8s |  |
| 871 | `regexp_constr` | 148 | 8.5s |  |
| 872 | `regexp_exec` | 19 | 8.2s |  |
| 873 | `regexp_extended` | 47 | 8.0s |  |
| 874 | `regexp_multiargs` | 1 | 7.9s |  |
| 875 | `regexp_test` | 27 | 8.0s |  |
| 876 | `regexp_toString` | 10 | 8.0s |  |
| 877 | `register_script_refresh` | 35 | 29.4s |  |
| 878 | `remove_child_clear_field` | 88 | 5.9s |  |
| 879 | `remove_dobj` | 3 | 1.6s |  |
| 880 | `resolve_order` | 4 | 5.6s |  |
| 881 | `responder_null_callbacks` | 1 | 5.5s |  |
| 882 | `rng` | 1 | 6.5s |  |
| 883 | `rootless` | 42 | 5.6s |  |
| 884 | `rshift` | 1058 | 12.8s |  |
| 885 | `rtqname_not_namespace` | 12 | 5.6s |  |
| 886 | `sandbox_type_inherited` | 2 | 5.8s |  |
| 887 | `sandbox_type_local_file` | 1 | 5.5s |  |
| 888 | `sandbox_type_local_network` | 1 | 5.3s |  |
| 889 | `scene_constr` | 8 | 5.6s |  |
| 890 | `scope_optimizations` | 4 | 5.5s |  |
| 891 | `scopes_dont_cache/order-1` | 1 | 21.5s |  |
| 892 | `scopes_dont_cache/order-2` | 1 | 0.3s |  |
| 893 | `security_domain_current` | 2 | 5.6s |  |
| 894 | `selection` | 239 | 5.9s |  |
| 895 | `selection_onsetfocus_mixed_avm` | 5 | 21.9s |  |
| 896 | `set_local_0` | 31 | 5.7s |  |
| 897 | `set_property_is_enumerable` | 85 | 6.0s |  |
| 898 | `shaderparameter_value` | 4 | 5.6s |  |
| 899 | `shape_drawrect` | 54 | 5.7s |  |
| 900 | `shared_object_no_root` | 3 | 5.6s |  |
| 901 | `simplebutton_added_to_stage` | 45 | 17.9s |  |
| 902 | `simplebutton_childevents` | 86 | 6.1s |  |
| 903 | `simplebutton_childevents_nested` | 54 | 6.0s |  |
| 904 | `simplebutton_childevents_sprite` | 13 | 5.8s |  |
| 905 | `simplebutton_childprops` | 144 | 5.9s |  |
| 906 | `simplebutton_childshuffle` | 23 | 5.6s |  |
| 907 | `simplebutton_constr` | 36 | 5.9s |  |
| 908 | `simplebutton_constr_childevents` | 48 | 6.0s |  |
| 909 | `simplebutton_constr_params` | 42 | 5.8s |  |
| 910 | `simplebutton_mouseenabled` | 26 | 5.7s |  |
| 911 | `simplebutton_multi_children` | 19 | 5.8s |  |
| 912 | `simplebutton_soundtransform` | 887 | 23.6s |  |
| 913 | `simplebutton_structure` | 27 | 5.9s |  |
| 914 | `simplebutton_symbolclass` | 68 | 6.0s |  |
| 915 | `slot_disp_id_shared_numbering` | 1 | 21.7s |  |
| 916 | `slots_force_autoassigned` | 1 | 7.8s |  |
| 917 | `socket_after_disconnect` | 1 | 7.6s |  |
| 918 | `socket_close` | 2 | 7.8s |  |
| 919 | `socket_connect` | 4 | 7.6s |  |
| 920 | `socket_errors` | 56 | 8.1s |  |
| 921 | `socket_read_big` | 48 | 7.6s |  |
| 922 | `socket_read_little` | 48 | 2.2s |  |
| 923 | `socket_read_write_object` | 8 | 7.5s |  |
| 924 | `socket_write_big` | 15 | 7.5s |  |
| 925 | `socket_write_little` | 14 | 7.4s |  |
| 926 | `sound_constructor_with_args` | 6 | 2.6s |  |
| 927 | `sound_embeddedprops` | 26 | 7.8s |  |
| 928 | `sound_load_multiple` | 19 | 8.6s |  |
| 929 | `sound_play` | 19 | 7.8s |  |
| 930 | `sound_rootless` | 7 | 7.5s |  |
| 931 | `sound_valueof` | 33 | 7.6s |  |
| 932 | `soundchannel_soundtransform` | 835 | 29.5s |  |
| 933 | `soundchannel_soundtransform_exists` | 5 | 27.8s |  |
| 934 | `soundchannel_stop` | 8 | 7.5s |  |
| 935 | `soundmixer_buffertime` | 5 | 7.4s |  |
| 936 | `soundmixer_soundtransform` | 900 | 9.5s |  |
| 937 | `soundmixer_stopall` | 6 | 7.5s |  |
| 938 | `soundtransform` | 442 | 12.0s |  |
| 939 | `space_justifier_clone` | 12 | 7.6s |  |
| 940 | `sprite_with_frames` | 0 | 7.7s |  |
| 941 | `stage3d_agal_cross_product` | 0 | 10.2s |  |
| 942 | `stage3d_agal_upload_errors` | 66 | 10.8s |  |
| 943 | `stage3d_bitmap` | 0 | 34.4s |  |
| 944 | `stage3d_blend` | 81 | 31.1s |  |
| 945 | `stage3d_context3d_string_args` | 158 | 9.0s |  |
| 946 | `stage3d_errors` | 7 | 7.7s |  |
| 947 | `stage3d_errors_atf` | 3 | 9.1s |  |
| 948 | `stage3d_errors_swf_29` | 6 | 7.8s |  |
| 949 | `stage3d_float1_index` | 0 | 31.1s |  |
| 950 | `stage3d_fractal` | 0 | 31.9s |  |
| 951 | `stage3d_ignore_sampler_override` | 0 | 32.2s |  |
| 952 | `stage3d_multistage_triangle` | 3 | 10.8s |  |
| 953 | `stage3d_program_constants_bytearray_be` | 0 | 33.7s |  |
| 954 | `stage3d_program_constants_bytearray_le` | 0 | 11.0s |  |
| 955 | `stage3d_program_constants_invalid_input` | 21 | 8.6s |  |
| 956 | `stage3d_raytrace` | 0 | 61.4s |  |
| 957 | `stage3d_rotating_cube` | 0 | 12.3s |  |
| 958 | `stage3d_sampler` | 0 | 11.6s |  |
| 959 | `stage3d_sampler_partial_upload` | 0 | 11.4s |  |
| 960 | `stage3d_stencil` | 0 | 33.6s |  |
| 961 | `stage3d_texture` | 0 | 18.2s |  |
| 962 | `stage3d_texture_bytearray` | 0 | 13.3s |  |
| 963 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 12.5s |  |
| 964 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 13.8s |  |
| 965 | `stage3d_triangle` | 0 | 11.7s |  |
| 966 | `stage3d_triangle_bytes4` | 0 | 11.7s |  |
| 967 | `stage3d_triangle_float1` | 0 | 11.6s |  |
| 968 | `stage3d_triangle_index_upload` | 0 | 11.7s |  |
| 969 | `stage3d_x_y` | 22 | 8.4s |  |
| 970 | `stage_access` | 10 | 8.6s |  |
| 971 | `stage_display_state` | 6 | 8.4s |  |
| 972 | `stage_displayobject_properties` | 24 | 8.3s |  |
| 973 | `stage_domain_getQualifiedDefinitionNames` | 5 | 8.4s |  |
| 974 | `stage_framerate_nan` | 7 | 31.1s |  |
| 975 | `stage_framerate_negative` | 6 | 8.4s |  |
| 976 | `stage_framerate_zero` | 6 | 8.5s |  |
| 977 | `stage_invalidate` | 38 | 8.8s |  |
| 978 | `stage_loaderinfo_properties` | 24 | 31.7s |  |
| 979 | `stage_mousechildren` | 2 | 8.6s |  |
| 980 | `stage_mouseenabled` | 15 | 8.6s |  |
| 981 | `stage_overriden_setters` | 31 | 8.8s |  |
| 982 | `stage_properties` | 30 | 8.7s |  |
| 983 | `stage_properties2` | 213 | 9.1s |  |
| 984 | `stage_scale_factor` | 12 | 37.9s |  |
| 985 | `stage_stage3Ds_vector` | 1 | 8.3s |  |
| 986 | `static_length` | 24 | 8.8s |  |
| 987 | `static_text` | 3 | 8.8s |  |
| 988 | `static_var_with_this_in_ctor` | 2 | 8.5s |  |
| 989 | `statictext_text` | 8 | 8.7s |  |
| 990 | `stored_properties` | 11 | 8.6s |  |
| 991 | `strict_equality` | 34 | 8.7s |  |
| 992 | `string_call` | 13 | 8.6s |  |
| 993 | `string_case` | 23 | 8.6s |  |
| 994 | `string_char_at` | 27 | 8.6s |  |
| 995 | `string_char_code_at` | 28 | 8.4s |  |
| 996 | `string_concat_fromcharcode` | 37 | 8.4s |  |
| 997 | `string_constr` | 25 | 8.5s |  |
| 998 | `string_indexof_lastindexof` | 87 | 8.8s |  |
| 999 | `string_length` | 16 | 8.6s |  |
| 1000 | `string_locale_compare` | 39 | 22.1s |  |
| 1001 | `string_match` | 51 | 22.2s |  |
| 1002 | `string_relational_compare` | 4 | 5.6s |  |
| 1003 | `string_replace` | 51 | 5.8s |  |
| 1004 | `string_search` | 41 | 5.8s |  |
| 1005 | `string_slice_substr_substring` | 170 | 6.4s |  |
| 1006 | `string_split` | 29 | 5.7s |  |
| 1007 | `string_substr_negative` | 21 | 5.6s |  |
| 1008 | `string_substr_weird` | 182 | 5.6s |  |
| 1009 | `stylesheet` | 221 | 6.3s |  |
| 1010 | `stylesheet_parse_color` | 69 | 5.6s |  |
| 1011 | `stylesheet_transform` | 307 | 5.9s |  |
| 1012 | `sub_super_same_field` | 12 | 1.7s |  |
| 1013 | `subclass_superclass_linked_symbol` | 4 | 6.1s |  |
| 1014 | `subtract` | 1058 | 13.0s |  |
| 1015 | `super_get_call` | 12 | 5.7s |  |
| 1016 | `supercall_two_classobjects` | 2 | 5.7s |  |
| 1017 | `supercalls_coerce` | 8 | 5.7s |  |
| 1018 | `supercalls_weird` | 2 | 5.4s |  |
| 1019 | `superinterface_call` | 20 | 5.7s |  |
| 1020 | `superinterface_instanceof` | 18 | 5.7s |  |
| 1021 | `swf8` | 1 | 5.6s |  |
| 1022 | `swf_10_queued_goto_scripts_construct` | 52 | 21.9s |  |
| 1023 | `swf_9_goto_in_enter_frame` | 17 | 5.7s |  |
| 1024 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.7s |  |
| 1025 | `swf_9_queued_goto_scripts` | 6 | 21.9s |  |
| 1026 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 1027 | `swf_9_versioning` | 2 | 5.6s |  |
| 1028 | `swf_wrong_frame_count` | 38 | 6.0s |  |
| 1029 | `swf_wrong_frame_count_isplaying` | 22 | 5.7s |  |
| 1030 | `symbol_class_binary_data` | 8 | 5.7s |  |
| 1031 | `symbol_class_conflict` | 4 | 5.8s |  |
| 1032 | `symbol_class_root_not_zero` | 1 | 5.6s |  |
| 1033 | `symbolclass_invalid_utf8` | 2 | 5.7s |  |
| 1034 | `system_exit` | 3 | 5.6s |  |
| 1035 | `system_setclipboard_null` | 1 | 5.6s |  |
| 1036 | `tab_ordering_arrows` | 998 | 23.1s |  |
| 1037 | `tab_ordering_automatic_advanced` | 184 | 6.3s |  |
| 1038 | `tab_ordering_automatic_basic` | 45 | 5.8s |  |
| 1039 | `tab_ordering_children` | 116 | 6.0s |  |
| 1040 | `tab_ordering_custom_basic` | 34 | 5.8s |  |
| 1041 | `tab_ordering_properties` | 732 | 6.0s |  |
| 1042 | `tab_ordering_stage_tab_children` | 32 | 26.5s |  |
| 1043 | `tab_ordering_stage_tab_children_remove_root` | 5 | 5.9s |  |
| 1044 | `tab_ordering_tabbable` | 47 | 5.9s |  |
| 1045 | `tabstop_properties` | 105 | 26.6s |  |
| 1046 | `text_element_basic` | 34 | 5.9s |  |
| 1047 | `text_engine_fontdescription` | 27 | 5.9s |  |
| 1048 | `text_engine_groupelement` | 64 | 5.9s |  |
| 1049 | `text_run` | 7 | 5.9s |  |
| 1050 | `textblock_createline_errors` | 23 | 6.0s |  |
| 1051 | `textblock_createline_fte` | 9 | 26.6s |  |
| 1052 | `textblock_properties` | 118 | 6.0s |  |
| 1053 | `textbox_click` | 37 | 26.7s |  |
| 1054 | `textfield_event` | 66 | 6.0s |  |
| 1055 | `textfield_focusin_event` | 9 | 5.9s |  |
| 1056 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 1057 | `textfield_input_events` | 25 | 9.0s |  |
| 1058 | `textfield_unload` | 39 | 26.8s |  |
| 1059 | `textformat` | 1134 | 5.9s |  |
| 1060 | `textformat_display` | 14 | 5.9s |  |
| 1061 | `textformat_font_max_length` | 4 | 5.9s |  |
| 1062 | `textjustifier_locale` | 132 | 5.9s |  |
| 1063 | `textline_has_tabs` | 47 | 5.9s |  |
| 1064 | `textline_inapplicable_properties` | 10 | 5.9s |  |
| 1065 | `textline_name` | 1 | 5.9s |  |
| 1066 | `textline_raw_text_length` | 30 | 5.9s |  |
| 1067 | `textline_splitting_basic` | 76 | 5.9s |  |
| 1068 | `textline_throwerror` | 30 | 5.9s |  |
| 1069 | `textline_validity` | 162 | 5.9s |  |
| 1070 | `throw` | 3 | 6.0s |  |
| 1071 | `timeline_scripts` | 3 | 26.7s |  |
| 1072 | `timer` | 90 | 5.9s |  |
| 1073 | `timer_events` | 3 | 5.9s |  |
| 1074 | `timer_finished` | 11 | 5.8s |  |
| 1075 | `timer_invalid_delay` | 30 | 5.9s |  |
| 1076 | `timer_reset` | 8 | 5.9s |  |
| 1077 | `timer_setdelay` | 5 | 5.9s |  |
| 1078 | `trace` | 12 | 21.8s |  |
| 1079 | `truthiness` | 30 | 5.7s |  |
| 1080 | `try_catch` | 11 | 5.8s |  |
| 1081 | `try_catch_typed` | 12 | 5.8s |  |
| 1082 | `typeof` | 30 | 5.7s |  |
| 1083 | `uint_constr` | 92 | 5.9s |  |
| 1084 | `uint_tofixed` | 1215 | 5.6s |  |
| 1085 | `uint_toprecision` | 1125 | 5.8s |  |
| 1086 | `uint_tostring` | 3375 | 5.9s |  |
| 1087 | `uncaught_error_basic` | 2 | 5.6s |  |
| 1088 | `unchecked_function` | 15 | 5.7s |  |
| 1089 | `unescape` | 28 | 5.8s |  |
| 1090 | `url_loader` | 25 | 5.9s |  |
| 1091 | `url_vars` | 27 | 5.8s |  |
| 1092 | `urlrequest` | 18 | 21.5s |  |
| 1093 | `urlstream_basic` | 5 | 5.7s |  |
| 1094 | `urshift` | 1058 | 12.8s |  |
| 1095 | `utils3d` | 7 | 5.6s |  |
| 1096 | `vector3d` | 397 | 8.5s |  |
| 1097 | `vector3d_near_equals` | 80 | 5.7s |  |
| 1098 | `vector_class` | 36 | 6.0s |  |
| 1099 | `vector_class_call` | 11 | 5.8s |  |
| 1100 | `vector_coercion` | 66 | 6.3s |  |
| 1101 | `vector_concat` | 90 | 6.1s |  |
| 1102 | `vector_constr` | 107 | 6.2s |  |
| 1103 | `vector_enumeration` | 5 | 5.6s |  |
| 1104 | `vector_every` | 92 | 6.3s |  |
| 1105 | `vector_filter` | 95 | 6.3s |  |
| 1106 | `vector_holes` | 24 | 5.7s |  |
| 1107 | `vector_indexof` | 302 | 8.5s |  |
| 1108 | `vector_insertat` | 270 | 6.4s |  |
| 1109 | `vector_int_access` | 4 | 5.5s |  |
| 1110 | `vector_int_delete` | 11 | 5.5s |  |
| 1111 | `vector_join` | 58 | 5.9s |  |
| 1112 | `vector_lastindexof` | 302 | 5.5s |  |
| 1113 | `vector_legacy` | 10 | 5.6s |  |
| 1114 | `vector_map` | 85 | 6.1s |  |
| 1115 | `vector_object_final` | 1 | 5.4s |  |
| 1116 | `vector_object_toString` | 10 | 5.5s |  |
| 1117 | `vector_prototype_some` | 125 | 5.6s |  |
| 1118 | `vector_pushpop` | 255 | 5.8s |  |
| 1119 | `vector_reborrow_bug` | 10 | 4.9s |  |
| 1120 | `vector_removeat` | 172 | 5.5s |  |
| 1121 | `vector_reverse` | 232 | 5.5s |  |
| 1122 | `vector_shiftunshift` | 252 | 1.6s |  |
| 1123 | `vector_slice` | 331 | 5.9s |  |
| 1124 | `vector_sort` | 905 | 10.4s |  |
| 1125 | `vector_splice` | 693 | 7.0s |  |
| 1126 | `vector_splice_fixed_bug_compat` | 4 | 4.8s |  |
| 1127 | `vector_tostring` | 79 | 5.2s |  |
| 1128 | `verification` | 8 | 4.9s |  |
| 1129 | `verify_abnormal_loop` | 1 | 4.8s |  |
| 1130 | `verify_dxns_without_flag` | 3 | 5.2s |  |
| 1131 | `verify_exception_target_two_jumps` | 1 | 4.9s |  |
| 1132 | `verify_exception_targets_edge_case` | 1 | 4.9s |  |
| 1133 | `verify_illegal_opcode` | 1 | 1.8s |  |
| 1134 | `verify_jump_to_middle_of_op` | 1 | 4.9s |  |
| 1135 | `verify_lookup_switch_edge_case` | 1 | 4.8s |  |
| 1136 | `verify_method_info_oob` | 1 | 0.4s |  |
| 1137 | `verify_stack` | 5 | 4.9s |  |
| 1138 | `verify_typecheck` | 4 | 4.9s |  |
| 1139 | `verify_unreachable_exception` | 2 | 4.8s |  |
| 1140 | `versioned_isplaying` | 2 | 4.9s |  |
| 1141 | `virtual_properties` | 16 | 4.9s |  |
| 1142 | `with` | 4 | 4.9s |  |
| 1143 | `wrong_arg_count` | 7 | 4.9s |  |
| 1144 | `xml_abstract_equality` | 36 | 5.0s |  |
| 1145 | `xml_advanced` | 52 | 1.6s |  |
| 1146 | `xml_appendchild` | 10 | 4.8s |  |
| 1147 | `xml_appendchild_swf_v21` | 13 | 5.1s |  |
| 1148 | `xml_as_attribute` | 9 | 4.9s |  |
| 1149 | `xml_attribute` | 35 | 5.0s |  |
| 1150 | `xml_attribute_name` | 40 | 5.0s |  |
| 1151 | `xml_basic` | 33 | 5.0s |  |
| 1152 | `xml_child` | 25 | 5.0s |  |
| 1153 | `xml_childindex` | 7 | 5.0s |  |
| 1154 | `xml_children` | 43 | 5.3s |  |
| 1155 | `xml_class_call` | 9 | 4.8s |  |
| 1156 | `xml_contains` | 197 | 5.0s |  |
| 1157 | `xml_copy` | 20 | 5.6s |  |
| 1158 | `xml_ctor_from_tostring` | 23 | 5.6s |  |
| 1159 | `xml_delete` | 114 | 5.7s |  |
| 1160 | `xml_descendants` | 83 | 5.6s |  |
| 1161 | `xml_duplicate_attribute` | 14 | 5.5s |  |
| 1162 | `xml_elements` | 6 | 5.5s |  |
| 1163 | `xml_equals_namespace_check` | 2 | 5.5s |  |
| 1164 | `xml_explicit_use_namespace` | 5 | 5.4s |  |
| 1165 | `xml_getdescendants_qname` | 21 | 5.5s |  |
| 1166 | `xml_has_property_via_in` | 26 | 5.5s |  |
| 1167 | `xml_hasownproperty` | 6 | 5.5s |  |
| 1168 | `xml_ignore_white` | 6 | 5.5s |  |
| 1169 | `xml_length` | 2 | 5.5s |  |
| 1170 | `xml_list_as_attribute` | 9 | 5.5s |  |
| 1171 | `xml_list_concat` | 20 | 5.6s |  |
| 1172 | `xml_list_ctor_errors` | 34 | 5.5s |  |
| 1173 | `xml_list_delete_clear_parent` | 6 | 5.5s |  |
| 1174 | `xml_list_enumerate` | 4 | 5.5s |  |
| 1175 | `xml_methods_settings` | 3 | 5.5s |  |
| 1176 | `xml_mismatched_tag` | 45 | 5.5s |  |
| 1177 | `xml_namespace` | 39 | 5.5s |  |
| 1178 | `xml_namespace_methods` | 245 | 5.6s |  |
| 1179 | `xml_namespaced_property` | 7 | 5.5s |  |
| 1180 | `xml_no_namespace` | 1 | 5.5s |  |
| 1181 | `xml_nodekind` | 3 | 5.5s |  |
| 1182 | `xml_normalize` | 35 | 5.6s |  |
| 1183 | `xml_notification_bubbling` | 361 | 5.6s |  |
| 1184 | `xml_parent` | 8 | 5.6s |  |
| 1185 | `xml_set_children` | 17 | 5.6s |  |
| 1186 | `xml_set_name` | 34 | 1.6s |  |
| 1187 | `xml_settings` | 6 | 1.6s |  |
| 1188 | `xml_simple_complex_content` | 47 | 5.6s |  |
| 1189 | `xml_socket` | 11 | 5.6s |  |
| 1190 | `xml_text` | 7 | 5.5s |  |
| 1191 | `xml_tostring` | 6 | 5.5s |  |
| 1192 | `xml_tostring_namespace` | 12 | 5.3s |  |
| 1193 | `xml_unescaping` | 23 | 5.5s |  |
| 1194 | `xml_weird_ignores` | 54 | 5.8s |  |
| 1195 | `xml_wildcard` | 11 | 5.8s |  |
| 1196 | `xmldocument` | 254 | 5.9s |  |
| 1197 | `xmlnode` | 3540 | 6.0s |  |
| 1198 | `zero_frame_clip` | 3 | 5.9s |  |

## Ruffle-Matched Tests

**42 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 5.5s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.3s |  |
| 3 | `blend_transform` | 1 | 1 | 21.1s |  |
| 4 | `bounds_mode` | 6 | 6 | 5.8s |  |
| 5 | `coerce_property` | 3 | 3 | 5.8s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.8s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 6.0s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 21.3s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 5.8s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.8s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.7s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 5.8s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.4s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 7.5s |  |
| 15 | `freestanding_superclass` | 2 | 4 | 5.6s |  |
| 16 | `goto_framescript_queued/swf13` | 3 | 3 | 21.9s |  |
| 17 | `gradient_values_readback` | 12 | 12 | 5.9s |  |
| 18 | `graphics_draw_path` | 50 | 50 | 22.1s |  |
| 19 | `groupelement_text` | 2 | 2 | 5.6s |  |
| 20 | `html_text_img_parsing` | 95 | 95 | 5.6s |  |
| 21 | `int_toexponential` | 76 | 76 | 8.2s |  |
| 22 | `json_parse_numbers` | 4 | 79 | 8.1s |  |
| 23 | `loader_events_2` | 30 | 30 | 8.5s |  |
| 24 | `matrix3d_recompose_edge_cases` | 8 | 85 | 6.0s |  |
| 25 | `number_convert_errors` | 706 | 706 | 6.1s |  |
| 26 | `number_to_string` | 104 | 104 | 6.3s |  |
| 27 | `simplebutton_childevents_multichild` | 101 | 101 | 5.8s |  |
| 28 | `simplebutton_childevents_script_order` | 4 | 4 | 6.0s |  |
| 29 | `slot_holes_fail` | 1 | 1 | 5.5s |  |
| 30 | `slot_id_exceeds_trait_count` | 1 | 1 | 5.6s |  |
| 31 | `soundchannel_position` | 74 | 74 | 29.3s |  |
| 32 | `soundchannel_soundcomplete` | 10 | 10 | 7.6s |  |
| 33 | `sprite_dropTarget` | 15 | 15 | 7.7s |  |
| 34 | `swf_9_goto_in_construct_frame` | 12 | 12 | 22.1s |  |
| 35 | `textblock_line_changes` | 44 | 44 | 6.0s |  |
| 36 | `textblock_recreateline` | 137 | 138 | 5.9s |  |
| 37 | `textblock_releaselines` | 4 | 4 | 5.9s |  |
| 38 | `textline_atom_index_at_char_index` | 3 | 3 | 6.2s |  |
| 39 | `uint_toexponential` | 100 | 100 | 5.8s |  |
| 40 | `uncaught_errors_stringified` | 15 | 15 | 5.7s |  |
| 41 | `vector_indexing_cutoffs` | 1 | 1 | 5.7s |  |
| 42 | `weird_superinterface_properties` | 1 | 1 | 5.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**15 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `error_stack_trace_class_names` | 94.1% | 127 | 135 | 8 |  |
| 3 | `array_join_reentrant` | 85.3% | 58 | 68 | 10 |  |
| 4 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 5 | `edittext_set_text_same` | 80.0% | 92 | 115 | 23 |  |
| 6 | `weird_number_bound_methods` | 75.0% | 9 | 12 | 3 |  |
| 7 | `hit_test_scroll_rect` | 69.7% | 69 | 99 | 30 |  |
| 8 | `error_stack_trace_limit` | 69.1% | 600 | 868 | 268 |  |
| 9 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 10 | `event_handler_exception` | 63.6% | 7 | 11 | 4 |  |
| 11 | `edittext_set_text_same_after_edits` | 60.9% | 84 | 138 | 54 |  |
| 12 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 13 | `dictionary_qname_keys` | 50.9% | 29 | 57 | 28 |  |
| 14 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |
| 15 | `xml_many_namespace_declarations` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**49 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `error_stack_trace_class_names` | 94.1% | 127/135 | 135 | 135 |  |
| 3 | `array_join_reentrant` | 85.3% | 58/68 | 68 | 68 |  |
| 4 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 5 | `edittext_set_text_same` | 80.0% | 92/115 | 115 | 115 |  |
| 6 | `weird_number_bound_methods` | 75.0% | 9/12 | 12 | 12 |  |
| 7 | `hit_test_scroll_rect` | 69.7% | 69/99 | 99 | 99 |  |
| 8 | `error_stack_trace_limit` | 69.1% | 600/868 | 868 | 674 |  |
| 9 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 10 | `event_handler_exception` | 63.6% | 7/11 | 11 | 11 |  |
| 11 | `edittext_set_text_same_after_edits` | 60.9% | 84/138 | 138 | 138 |  |
| 12 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 13 | `dictionary_qname_keys` | 50.9% | 29/57 | 57 | 45 |  |
| 14 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 15 | `xml_many_namespace_declarations` | 50.0% | 1/2 | 2 | 2 |  |
| 16 | `primitive_bound_methods` | 45.5% | 5/11 | 11 | 11 |  |
| 17 | `loaderinfo_root_progress` | 42.9% | 3/7 | 6 | 7 |  |
| 18 | `loaderinfo_root_progress_goto` | 40.0% | 4/10 | 6 | 10 |  |
| 19 | `displayobjectcontainer_removechildren_events` | 36.2% | 21/58 | 58 | 56 |  |
| 20 | `stage3d_missing_vertex_stream` | 35.1% | 13/37 | 27 | 37 |  |
| 21 | `textfield_default_text_format_null` | 35.0% | 7/20 | 12 | 20 |  |
| 22 | `amf_xmllist` | 33.3% | 4/12 | 12 | 12 |  |
| 23 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 24 | `displayobjectcontainer_remove_reparent` | 31.2% | 59/189 | 185 | 189 |  |
| 25 | `xml_unescaping_nul_char_ref` | 21.1% | 4/19 | 19 | 19 |  |
| 26 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 27 | `perspective_projection_center` | 17.6% | 6/34 | 26 | 34 |  |
| 28 | `context3d_draw_to_bitmap_data` | 13.3% | 2/15 | 11 | 15 |  |
| 29 | `vector_join_reentrant` | 10.4% | 10/96 | 84 | 96 |  |
| 30 | `array_sort_arguments` | 9.5% | 42/442 | 277 | 442 |  |
| 31 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 32 | `array_constructor` | 9.0% | 21/234 | 181 | 234 |  |
| 33 | `textfield_set_text_format_args` | 9.0% | 81/904 | 638 | 904 |  |
| 34 | `textfield_get_text_format_args` | 8.8% | 50/567 | 447 | 567 |  |
| 35 | `shared_object_get_local_error` | 4.8% | 1/21 | 5 | 21 |  |
| 36 | `bitmapdata_encode_png_roundtrip` | 3.0% | 1/33 | 4 | 33 |  |
| 37 | `worker_terminate` | 1.8% | 1/56 | 3 | 56 |  |
| 38 | `bitmapdata_encode` | 0.7% | 1/147 | 5 | 147 |  |
| 39 | `vector_sort_arguments` | 0.3% | 1/355 | 198 | 355 |  |
| 40 | `displayobjectcontainer_remove_reentrant` | 0.0% | 2/27942 | 27942 | 257 |  |
| 41 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 42 | `bitmapdata_encode_jpeg_visual` | 0.0% | 0/3 | 3 | 0 |  |
| 43 | `bitmapdata_encode_png_visual` | 0.0% | 0/3 | 3 | 0 |  |
| 44 | `edittext_event_link_case_insensitive` | 0.0% | 0/1 | 0 | 1 |  |
| 45 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 46 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 47 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 48 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 49 | `textline_metrics` | 0.0% | 0/20 | 20 | 20 |  |
