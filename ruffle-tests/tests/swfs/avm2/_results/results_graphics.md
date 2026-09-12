# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-12 00:02 UTC

**Git SHA**: `f48c532bf1`

**Run Duration**: 243m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1274 |
| Passing | **1205** (94.6%) |
| Ruffle-matched | 36 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1241** (97.4%) |
| Failing | 33 |
| Total expected lines | 157153 |
| Matching lines | 153109 (97.4%) |
| Mismatched lines | 4044 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 33 | 100.0% |

## Passing Tests

**1205 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 31.7s |  |
| 2 | `accessibility` | 1 | 8.7s |  |
| 3 | `accessibilityimplementation` | 18 | 28.7s |  |
| 4 | `activation_class` | 6 | 8.8s |  |
| 5 | `add` | 1058 | 21.2s |  |
| 6 | `agal_compiler` | 13 | 11.2s |  |
| 7 | `air_datagram_socket` | 1 | 10.8s |  |
| 8 | `air_hidden_lookup` | 2 | 8.7s |  |
| 9 | `air_ifilepromise` | 1 | 8.6s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 8.8s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.4s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.3s |  |
| 13 | `all_classes/display/swf10` | 2569 | 8.8s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.4s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.4s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.4s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.3s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.3s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 8.7s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.3s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.3s |  |
| 22 | `all_classes/errors/swf10` | 140 | 8.7s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.3s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.3s |  |
| 25 | `all_classes/events/swf10` | 1638 | 8.7s |  |
| 26 | `all_classes/events/swf11` | 1750 | 1.3s |  |
| 27 | `all_classes/events/swf12` | 1814 | 1.3s |  |
| 28 | `all_classes/events/swf30` | 2353 | 1.3s |  |
| 29 | `all_classes/events/swf9` | 1030 | 1.3s |  |
| 30 | `all_classes/security/swf11` | 3 | 8.8s |  |
| 31 | `all_classes/security/swf12` | 19 | 1.3s |  |
| 32 | `all_classes/security/swf13` | 53 | 1.3s |  |
| 33 | `all_classes/security/swf30` | 53 | 1.3s |  |
| 34 | `all_classes/xml/swf30` | 116 | 8.7s |  |
| 35 | `all_classes/xml/swf9` | 116 | 1.3s |  |
| 36 | `amf_array_serialization` | 17 | 31.1s |  |
| 37 | `amf_custom_obj` | 26 | 8.8s |  |
| 38 | `amf_dictionary` | 9 | 8.7s |  |
| 39 | `amf_function` | 46 | 8.7s |  |
| 40 | `amf_invalid_date` | 2 | 8.7s |  |
| 41 | `amf_missing_prop` | 6 | 8.7s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 8.7s |  |
| 43 | `amf_setter_error` | 8 | 8.8s |  |
| 44 | `amf_vector` | 40 | 32.6s |  |
| 45 | `amf_xml` | 6 | 8.9s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 9.4s |  |
| 47 | `application_domain` | 4 | 9.0s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 30.0s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 8.9s |  |
| 50 | `array_access` | 18 | 9.0s |  |
| 51 | `array_access_interpreter` | 4 | 8.9s |  |
| 52 | `array_access_no_pubns` | 2 | 8.8s |  |
| 53 | `array_concat` | 41 | 8.9s |  |
| 54 | `array_constr` | 10 | 8.8s |  |
| 55 | `array_delete` | 44 | 9.0s |  |
| 56 | `array_enumeration` | 10 | 8.9s |  |
| 57 | `array_enumeration_elements` | 11 | 8.9s |  |
| 58 | `array_every` | 8 | 8.9s |  |
| 59 | `array_filter` | 6 | 8.8s |  |
| 60 | `array_foreach` | 18 | 8.9s |  |
| 61 | `array_hasownproperty` | 11 | 8.9s |  |
| 62 | `array_holes` | 9 | 8.9s |  |
| 63 | `array_index_max` | 84 | 8.9s |  |
| 64 | `array_indexof` | 25 | 8.9s |  |
| 65 | `array_join` | 26 | 8.9s |  |
| 66 | `array_lastindexof` | 29 | 8.9s |  |
| 67 | `array_length` | 14 | 8.9s |  |
| 68 | `array_literal` | 3 | 8.9s |  |
| 69 | `array_map` | 8 | 8.8s |  |
| 70 | `array_pop` | 52 | 9.0s |  |
| 71 | `array_push` | 24 | 8.9s |  |
| 72 | `array_reborrow_bug` | 6 | 8.8s |  |
| 73 | `array_reverse` | 28 | 8.8s |  |
| 74 | `array_shift` | 51 | 3.5s |  |
| 75 | `array_slice` | 39 | 8.9s |  |
| 76 | `array_some` | 8 | 8.9s |  |
| 77 | `array_sort` | 297 | 9.4s |  |
| 78 | `array_sort_fun_swf12` | 2 | 8.9s |  |
| 79 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 80 | `array_sort_random` | 210 | 8.9s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 8.9s |  |
| 82 | `array_sorton` | 545 | 9.8s |  |
| 83 | `array_sparse_ops` | 41 | 9.1s |  |
| 84 | `array_splice` | 133 | 9.1s |  |
| 85 | `array_splice2` | 428 | 31.9s |  |
| 86 | `array_splice_types` | 48 | 8.2s |  |
| 87 | `array_storage` | 8 | 27.5s |  |
| 88 | `array_tolocalestring` | 9 | 8.3s |  |
| 89 | `array_tostring` | 12 | 8.3s |  |
| 90 | `array_unshift` | 24 | 8.3s |  |
| 91 | `array_valueof` | 9 | 8.3s |  |
| 92 | `array_vector_null_callback` | 10 | 8.3s |  |
| 93 | `astype` | 28 | 8.3s |  |
| 94 | `astypelate` | 24 | 8.5s |  |
| 95 | `astypelate_propagates` | 1 | 8.4s |  |
| 96 | `asymmetric_key_events` | 11 | 8.7s |  |
| 97 | `automation_classes` | 122 | 8.6s |  |
| 98 | `av_classes` | 340 | 8.5s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 8.2s |  |
| 100 | `avm2_catchup_dobj` | 158 | 8.8s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 96.9s |  |
| 102 | `bevel_filter` | 187 | 8.3s |  |
| 103 | `bitand` | 1058 | 19.6s |  |
| 104 | `bitmap_constr` | 17 | 8.2s |  |
| 105 | `bitmap_data` | 1000 | 15.4s |  |
| 106 | `bitmap_filter_abstract` | 6 | 8.4s |  |
| 107 | `bitmap_pixelsnapping` | 2 | 27.8s |  |
| 108 | `bitmap_properties` | 23 | 8.1s |  |
| 109 | `bitmap_subclass` | 7 | 9.7s |  |
| 110 | `bitmap_subclass_properties` | 9 | 8.6s |  |
| 111 | `bitmap_timeline` | 9 | 8.7s |  |
| 112 | `bitmapdata_accuracy` | 1 | 48.6s |  |
| 113 | `bitmapdata_applyfilter_blur` | 0 | 28.2s |  |
| 114 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.8s |  |
| 115 | `bitmapdata_applyfilter_destpoint` | 0 | 27.8s |  |
| 116 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 28.0s |  |
| 117 | `bitmapdata_applyfilter_identity` | 4 | 28.2s |  |
| 118 | `bitmapdata_clone` | 13 | 8.4s |  |
| 119 | `bitmapdata_colortransform` | 0 | 8.6s |  |
| 120 | `bitmapdata_colortransform_oob` | 2 | 8.1s |  |
| 121 | `bitmapdata_constr` | 22 | 8.1s |  |
| 122 | `bitmapdata_constructor_from_timeline` | 1 | 8.4s |  |
| 123 | `bitmapdata_copychannel` | 0 | 29.0s |  |
| 124 | `bitmapdata_copypixels` | 23 | 28.6s |  |
| 125 | `bitmapdata_copypixels_alpha_combine` | 13 | 8.1s |  |
| 126 | `bitmapdata_copypixels_blend_over` | 1 | 8.4s |  |
| 127 | `bitmapdata_copypixelstobytearray` | 39 | 8.4s |  |
| 128 | `bitmapdata_dispose` | 7 | 8.4s |  |
| 129 | `bitmapdata_draw` | 0 | 28.7s |  |
| 130 | `bitmapdata_draw_alpha_erase` | 8 | 8.6s |  |
| 131 | `bitmapdata_draw_cab_quality` | 0 | 28.8s |  |
| 132 | `bitmapdata_draw_colortransform` | 0 | 28.4s |  |
| 133 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 28.5s |  |
| 134 | `bitmapdata_draw_filters` | 0 | 27.9s |  |
| 135 | `bitmapdata_draw_masks` | 0 | 8.8s |  |
| 136 | `bitmapdata_draw_rotation` | 0 | 8.8s |  |
| 137 | `bitmapdata_draw_self_via_graphic` | 0 | 8.6s |  |
| 138 | `bitmapdata_draw_stage` | 0 | 27.5s |  |
| 139 | `bitmapdata_drawwithquality` | 0 | 8.9s |  |
| 140 | `bitmapdata_embedded` | 9 | 8.7s |  |
| 141 | `bitmapdata_fillrect` | 0 | 8.6s |  |
| 142 | `bitmapdata_filter_sourcerect` | 0 | 28.3s |  |
| 143 | `bitmapdata_floodfill` | 35 | 8.4s |  |
| 144 | `bitmapdata_getpixels` | 39 | 27.5s |  |
| 145 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 146 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 147 | `bitmapdata_hittest` | 112 | 9.2s |  |
| 148 | `bitmapdata_hittest_threshold` | 18 | 8.7s |  |
| 149 | `bitmapdata_opaque` | 0 | 9.2s |  |
| 150 | `bitmapdata_pixeldissolve` | 1037 | 9.4s |  |
| 151 | `bitmapdata_pixeldissolve_image` | 0 | 8.8s |  |
| 152 | `bitmapdata_rectangle_rounding` | 16 | 8.5s |  |
| 153 | `bitmapdata_setpixels` | 286 | 8.6s |  |
| 154 | `bitmapdata_setvector` | 26 | 8.6s |  |
| 155 | `bitmapdata_sync` | 0 | 27.7s |  |
| 156 | `bitmapdata_threshold` | 176 | 9.2s |  |
| 157 | `bitmapdata_zero_size` | 8 | 8.4s |  |
| 158 | `bitnot` | 46 | 8.4s |  |
| 159 | `bitor` | 1058 | 20.7s |  |
| 160 | `bitxor` | 1058 | 21.0s |  |
| 161 | `blend_mode_null` | 1 | 8.5s |  |
| 162 | `blend_multiply_alpha` | 0 | 8.7s |  |
| 163 | `blend_scroll` | 0 | 8.8s |  |
| 164 | `blend_shader_luma_lighten` | 3 | 9.1s |  |
| 165 | `blur_filter` | 43 | 8.9s |  |
| 166 | `boolean_constr` | 32 | 8.5s |  |
| 167 | `boolean_negation` | 30 | 8.4s |  |
| 168 | `boolean_tostring` | 8 | 8.4s |  |
| 169 | `broadcast_event` | 7 | 8.5s |  |
| 170 | `button_bounds` | 1 | 8.6s |  |
| 171 | `button_hittest` | 2 | 27.9s |  |
| 172 | `button_nested_frame` | 48 | 28.6s |  |
| 173 | `button_nested_frame_simple` | 27 | 8.8s |  |
| 174 | `bytearray` | 48 | 8.8s |  |
| 175 | `bytearray_bad_symbol_class` | 3 | 8.5s |  |
| 176 | `bytearray_bad_symbol_class_other_movie` | 6 | 9.0s |  |
| 177 | `bytearray_compress` | 31 | 8.7s |  |
| 178 | `bytearray_errors` | 24 | 9.0s |  |
| 179 | `bytearray_method_serialization` | 1 | 8.7s |  |
| 180 | `bytearray_oom` | 3 | 8.7s |  |
| 181 | `bytearray_readobject_amf0` | 50 | 8.6s |  |
| 182 | `bytearray_readobject_amf3` | 53 | 8.6s |  |
| 183 | `bytearray_readutf8bytes_with_bom` | 16 | 8.5s |  |
| 184 | `bytearray_serialization` | 3 | 8.6s |  |
| 185 | `bytearray_string_null` | 19 | 9.1s |  |
| 186 | `bytearray_tostring` | 15 | 8.9s |  |
| 187 | `bytearray_utf16` | 8 | 8.6s |  |
| 188 | `bytearray_writeobject` | 24 | 8.4s |  |
| 189 | `callee_in_initializer` | 6 | 8.6s |  |
| 190 | `callproplex_class` | 1 | 8.8s |  |
| 191 | `capabilities_resolution` | 8 | 29.6s |  |
| 192 | `catch_class` | 6 | 8.6s |  |
| 193 | `catch_scope_slot` | 7 | 8.6s |  |
| 194 | `checkfilter` | 4 | 3.2s |  |
| 195 | `class_call` | 32 | 8.9s |  |
| 196 | `class_cast_call` | 14 | 8.8s |  |
| 197 | `class_enumeration` | 4 | 8.7s |  |
| 198 | `class_has_own_property` | 2 | 8.8s |  |
| 199 | `class_init_interpreter_mode` | 1 | 8.7s |  |
| 200 | `class_is` | 32 | 8.7s |  |
| 201 | `class_methods` | 5 | 8.8s |  |
| 202 | `class_object_properties` | 10 | 8.5s |  |
| 203 | `class_singleton` | 18 | 8.6s |  |
| 204 | `class_supercalls_errors` | 35 | 8.8s |  |
| 205 | `class_supercalls_mismatched` | 26 | 8.8s |  |
| 206 | `class_superclass_wrong_order` | 1 | 5.8s |  |
| 207 | `class_to_locale_string` | 2 | 5.8s |  |
| 208 | `class_to_string` | 2 | 6.2s |  |
| 209 | `class_value_of` | 2 | 6.0s |  |
| 210 | `click_block` | 5 | 20.9s |  |
| 211 | `click_invisible` | 3 | 6.3s |  |
| 212 | `closures` | 12 | 5.9s |  |
| 213 | `coerce_return_type` | 40 | 5.9s |  |
| 214 | `coerce_return_type_fail` | 2 | 6.0s |  |
| 215 | `coerce_return_void` | 3 | 6.0s |  |
| 216 | `coerce_string` | 86 | 6.1s |  |
| 217 | `coerce_string_precision` | 28 | 5.8s |  |
| 218 | `coerce_to_primitive_side_effects` | 29 | 5.9s |  |
| 219 | `color_matrix_filter` | 19 | 6.3s |  |
| 220 | `construct_errors_swf10` | 8 | 5.9s |  |
| 221 | `construct_frame_list` | 22 | 20.6s |  |
| 222 | `construct_interface` | 3 | 6.1s |  |
| 223 | `constructor_call` | 3 | 5.8s |  |
| 224 | `constructors_vs_timeline` | 5 | 20.1s |  |
| 225 | `constructprop_dynamic_primitive` | 7 | 6.3s |  |
| 226 | `constructprop_method` | 2 | 5.8s |  |
| 227 | `constructsuper_null` | 2 | 2.0s |  |
| 228 | `content_element_basic` | 50 | 6.1s |  |
| 229 | `context3d_creation` | 9 | 5.8s |  |
| 230 | `control_flow_bool` | 4 | 5.8s |  |
| 231 | `control_flow_stricteq` | 8 | 5.8s |  |
| 232 | `convert_boolean` | 30 | 5.8s |  |
| 233 | `convert_integer` | 90 | 6.2s |  |
| 234 | `convert_number` | 56 | 6.0s |  |
| 235 | `convert_uinteger` | 90 | 6.1s |  |
| 236 | `convolution_filter` | 89 | 6.2s |  |
| 237 | `core_exceptions` | 47 | 6.4s |  |
| 238 | `cpool_index_invalid_bytecode_1` | 6 | 6.1s |  |
| 239 | `cpool_index_invalid_bytecode_2` | 3 | 5.8s |  |
| 240 | `cpool_index_invalid_bytecode_3` | 1 | 5.8s |  |
| 241 | `cross_api_version_call_newer` | 12 | 6.5s |  |
| 242 | `cross_api_version_call_older` | 12 | 6.3s |  |
| 243 | `cryptscore` | 11 | 6.1s |  |
| 244 | `currency_parse_result` | 7 | 5.9s |  |
| 245 | `date` | 30 | 6.3s |  |
| 246 | `date_parse` | 36 | 6.0s |  |
| 247 | `declocal` | 46 | 8.8s |  |
| 248 | `declocal_i` | 46 | 8.8s |  |
| 249 | `decode_uri` | 71 | 9.1s |  |
| 250 | `decrement` | 46 | 8.8s |  |
| 251 | `decrement_i` | 46 | 3.4s |  |
| 252 | `default_values` | 7 | 8.7s |  |
| 253 | `delayed_symbolclass` | 28 | 28.4s |  |
| 254 | `describe_type_basic` | 152 | 8.9s |  |
| 255 | `describe_type_json` | 301 | 9.0s |  |
| 256 | `describe_type_metadata` | 125 | 9.0s |  |
| 257 | `describe_type_native` | 23 | 8.8s |  |
| 258 | `dictionary_access` | 62 | 9.0s |  |
| 259 | `dictionary_access_no_pubns` | 2 | 8.8s |  |
| 260 | `dictionary_delete` | 101 | 9.2s |  |
| 261 | `dictionary_foreach` | 42 | 9.0s |  |
| 262 | `dictionary_hasownproperty` | 63 | 9.1s |  |
| 263 | `dictionary_in` | 62 | 9.1s |  |
| 264 | `dictionary_iter_modify` | 8 | 8.8s |  |
| 265 | `dictionary_namespaces` | 36 | 8.9s |  |
| 266 | `displacement_map_filter` | 61 | 8.9s |  |
| 267 | `displayobject_alpha` | 277 | 8.7s |  |
| 268 | `displayobject_blendmode` | 0 | 30.0s |  |
| 269 | `displayobject_colortransform_nested` | 0 | 28.6s |  |
| 270 | `displayobject_early_init` | 54 | 10.6s |  |
| 271 | `displayobject_filters` | 17 | 8.9s |  |
| 272 | `displayobject_from_enterframe` | 1 | 28.5s |  |
| 273 | `displayobject_getbounds_shape` | 0 | 28.5s |  |
| 274 | `displayobject_height` | 6052 | 29.2s |  |
| 275 | `displayobject_hittestobject` | 32 | 8.8s |  |
| 276 | `displayobject_hittestpoint` | 49 | 9.1s |  |
| 277 | `displayobject_hittestpoint_boundary` | 65 | 29.1s |  |
| 278 | `displayobject_hittestpoint_root` | 13 | 9.1s |  |
| 279 | `displayobject_invalid_floats` | 60 | 8.8s |  |
| 280 | `displayobject_invalid_props` | 3 | 8.8s |  |
| 281 | `displayobject_mask` | 3 | 9.3s |  |
| 282 | `displayobject_mask_self_referential` | 0 | 8.7s |  |
| 283 | `displayobject_metaData` | 3 | 8.8s |  |
| 284 | `displayobject_name` | 22 | 28.8s |  |
| 285 | `displayobject_name_from_timeline` | 24 | 8.9s |  |
| 286 | `displayobject_opaque_background` | 6 | 8.9s |  |
| 287 | `displayobject_parent` | 12 | 27.4s |  |
| 288 | `displayobject_root` | 24 | 8.4s |  |
| 289 | `displayobject_rotation` | 1284 | 8.6s |  |
| 290 | `displayobject_scrollrect` | 33 | 12.7s |  |
| 291 | `displayobject_set_matrix_nested` | 0 | 27.5s |  |
| 292 | `displayobject_set_name_loaded` | 3 | 8.7s |  |
| 293 | `displayobject_subclass` | 2 | 8.4s |  |
| 294 | `displayobject_transform` | 89 | 27.2s |  |
| 295 | `displayobject_visible` | 23 | 8.4s |  |
| 296 | `displayobject_width` | 4852 | 27.6s |  |
| 297 | `displayobject_x` | 614 | 8.4s |  |
| 298 | `displayobject_y` | 617 | 8.4s |  |
| 299 | `displayobjectcontainer_addchild` | 32 | 8.5s |  |
| 300 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 8.3s |  |
| 301 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.6s |  |
| 302 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 8.5s |  |
| 303 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 8.4s |  |
| 304 | `displayobjectcontainer_addchildat` | 42 | 8.4s |  |
| 305 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 8.5s |  |
| 306 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 8.4s |  |
| 307 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.5s |  |
| 308 | `displayobjectcontainer_contains` | 66 | 27.4s |  |
| 309 | `displayobjectcontainer_getchildat` | 4 | 8.4s |  |
| 310 | `displayobjectcontainer_getchildbyname` | 9 | 8.3s |  |
| 311 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 8.3s |  |
| 312 | `displayobjectcontainer_getchildindex` | 28 | 8.3s |  |
| 313 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 27.4s |  |
| 314 | `displayobjectcontainer_removechild` | 10 | 8.3s |  |
| 315 | `displayobjectcontainer_removechild_errors` | 4 | 8.3s |  |
| 316 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 8.4s |  |
| 317 | `displayobjectcontainer_removechildat` | 18 | 8.3s |  |
| 318 | `displayobjectcontainer_removechildren` | 51 | 8.6s |  |
| 319 | `displayobjectcontainer_setchildindex` | 42 | 8.2s |  |
| 320 | `displayobjectcontainer_stopallmovieclips` | 2 | 27.7s |  |
| 321 | `displayobjectcontainer_swapchildren` | 42 | 8.4s |  |
| 322 | `displayobjectcontainer_swapchildrenat` | 42 | 8.4s |  |
| 323 | `displayobjectcontainer_timelineinstance` | 48 | 27.4s |  |
| 324 | `divide` | 1058 | 20.4s |  |
| 325 | `doabc_and_symbolclass_script_init_goto` | 7 | 27.5s |  |
| 326 | `doabc_and_symbolclass_script_init_normal` | 6 | 8.3s |  |
| 327 | `doabc_is_eager` | 1 | 27.2s |  |
| 328 | `documentclass` | 9 | 7.0s |  |
| 329 | `domain_memory` | 133 | 23.3s |  |
| 330 | `drag_drop` | 10 | 7.1s |  |
| 331 | `drop_shadow_filter` | 172 | 7.4s |  |
| 332 | `duplicate_defs` | 1 | 6.9s |  |
| 333 | `eager_init` | 1 | 6.9s |  |
| 334 | `east_asian_justifier_clone` | 8 | 6.9s |  |
| 335 | `edit_text_linkage` | 7 | 7.0s |  |
| 336 | `edittext_align` | 60 | 7.4s |  |
| 337 | `edittext_always_show_selection` | 0 | 23.7s |  |
| 338 | `edittext_antialiastype` | 296 | 7.1s |  |
| 339 | `edittext_at_point_methods_basic` | 16 | 8.1s |  |
| 340 | `edittext_autosize` | 39 | 7.2s |  |
| 341 | `edittext_autosize_align` | 0 | 22.6s |  |
| 342 | `edittext_autosize_height_dynamic` | 60 | 22.7s |  |
| 343 | `edittext_autosize_height_input` | 60 | 7.1s |  |
| 344 | `edittext_autosize_lazy_bounds_events` | 65 | 7.5s |  |
| 345 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.9s |  |
| 346 | `edittext_autosize_lazy_bounds_props` | 490 | 8.0s |  |
| 347 | `edittext_autosize_lazy_bounds_visual` | 0 | 7.3s |  |
| 348 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.1s |  |
| 349 | `edittext_bottom_scroll_v_basic` | 210 | 7.3s |  |
| 350 | `edittext_bounds_scale` | 24 | 22.5s |  |
| 351 | `edittext_bullet` | 30 | 7.0s |  |
| 352 | `edittext_default_format` | 221 | 7.3s |  |
| 353 | `edittext_default_format_empty` | 136 | 7.2s |  |
| 354 | `edittext_empty_text_format` | 7 | 7.0s |  |
| 355 | `edittext_focus_selection` | 5 | 7.0s |  |
| 356 | `edittext_font_size` | 45 | 7.0s |  |
| 357 | `edittext_format_empty_font` | 8 | 6.8s |  |
| 358 | `edittext_get_char_index_at_point` | 4 | 24.5s |  |
| 359 | `edittext_get_line_index_at_point` | 2 | 22.8s |  |
| 360 | `edittext_get_line_index_of_char` | 76 | 7.6s |  |
| 361 | `edittext_getcharboundaries` | 172 | 7.5s |  |
| 362 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.9s |  |
| 363 | `edittext_getcharboundaries_scroll` | 85 | 7.0s |  |
| 364 | `edittext_getlinemetrics` | 146 | 7.3s |  |
| 365 | `edittext_html` | 3101 | 7.3s |  |
| 366 | `edittext_html_condensewhite` | 487 | 7.0s |  |
| 367 | `edittext_html_entity` | 4 | 7.0s |  |
| 368 | `edittext_html_font_size_swf12` | 267 | 25.2s |  |
| 369 | `edittext_html_font_size_swf13` | 273 | 7.2s |  |
| 370 | `edittext_html_roundtrip` | 17 | 25.0s |  |
| 371 | `edittext_ime_focus_lost` | 9 | 24.8s |  |
| 372 | `edittext_input_control` | 12 | 7.6s |  |
| 373 | `edittext_leading` | 9 | 7.8s |  |
| 374 | `edittext_letter_spacing` | 15 | 7.8s |  |
| 375 | `edittext_line_methods` | 294 | 9.1s |  |
| 376 | `edittext_line_metrics` | 11 | 25.4s |  |
| 377 | `edittext_margins` | 25 | 7.2s |  |
| 378 | `edittext_max_scroll_h_basic` | 475 | 7.4s |  |
| 379 | `edittext_max_scroll_v_basic` | 1000 | 7.2s |  |
| 380 | `edittext_mouse_selection` | 363 | 24.2s |  |
| 381 | `edittext_mousedown` | 3 | 7.5s |  |
| 382 | `edittext_mouseenabled` | 26 | 7.1s |  |
| 383 | `edittext_newline_character` | 22 | 7.0s |  |
| 384 | `edittext_newline_stripping` | 64 | 9.4s |  |
| 385 | `edittext_newlines` | 30 | 7.1s |  |
| 386 | `edittext_paragraph_methods` | 257 | 7.0s |  |
| 387 | `edittext_paste_events` | 8 | 7.0s |  |
| 388 | `edittext_paste_maxchars` | 4 | 6.9s |  |
| 389 | `edittext_paste_restrict` | 16 | 6.8s |  |
| 390 | `edittext_restrict` | 191 | 6.8s |  |
| 391 | `edittext_restrict_events` | 22 | 6.8s |  |
| 392 | `edittext_scrollh` | 10 | 6.7s |  |
| 393 | `edittext_selected_text` | 9 | 6.9s |  |
| 394 | `edittext_set_html_same` | 17 | 6.9s |  |
| 395 | `edittext_set_text_vs_html` | 9 | 6.7s |  |
| 396 | `edittext_stylesheet` | 536 | 7.0s |  |
| 397 | `edittext_stylesheet_custom_tag` | 76 | 6.8s |  |
| 398 | `edittext_stylesheet_display` | 272 | 6.8s |  |
| 399 | `edittext_tag_indent` | 49 | 22.1s |  |
| 400 | `edittext_underline` | 40 | 7.0s |  |
| 401 | `edittext_width_height` | 103 | 7.0s |  |
| 402 | `edittext_wordwrap_word` | 150 | 6.9s |  |
| 403 | `edittext_wrap_breaks` | 2375 | 7.4s |  |
| 404 | `element_format_clone` | 44 | 6.9s |  |
| 405 | `element_format_constructor_order` | 64 | 2.8s |  |
| 406 | `element_format_properties` | 235 | 7.6s |  |
| 407 | `empty_bounds` | 1 | 6.7s |  |
| 408 | `encode_uri_surrogate_pair_invalid` | 8 | 6.8s |  |
| 409 | `encode_uri_surrogate_pair_swf11` | 15 | 6.8s |  |
| 410 | `equals` | 512 | 9.6s |  |
| 411 | `error_geterrormessage` | 779 | 7.1s |  |
| 412 | `error_prototype` | 15 | 7.0s |  |
| 413 | `error_stack_trace` | 45 | 7.0s |  |
| 414 | `error_stack_trace_debug_swf17` | 0 | 23.8s |  |
| 415 | `error_stack_trace_debug_swf18` | 0 | 6.8s |  |
| 416 | `error_stack_trace_edge_cases` | 6 | 7.0s |  |
| 417 | `error_stack_trace_release_swf17` | 0 | 2.4s |  |
| 418 | `error_stack_trace_release_swf18` | 0 | 6.8s |  |
| 419 | `error_throwerror` | 103 | 7.1s |  |
| 420 | `error_tostring` | 29 | 6.9s |  |
| 421 | `error_tostring_more` | 86 | 7.0s |  |
| 422 | `es3_inheritance` | 31 | 7.0s |  |
| 423 | `es4_inheritance` | 30 | 7.0s |  |
| 424 | `es4_interfaces` | 30 | 7.1s |  |
| 425 | `es4_method_binding` | 8 | 7.0s |  |
| 426 | `es4_oop_prototypes` | 14 | 7.2s |  |
| 427 | `es4_protected_inheritance` | 6 | 7.1s |  |
| 428 | `escape` | 71 | 7.1s |  |
| 429 | `escape_multi_byte` | 45 | 7.1s |  |
| 430 | `event_bubbles` | 2 | 7.0s |  |
| 431 | `event_cancelable` | 2 | 6.9s |  |
| 432 | `event_clone` | 20 | 7.0s |  |
| 433 | `event_clone_error_redispatch` | 3 | 7.1s |  |
| 434 | `event_clone_on_redispatch` | 10 | 7.1s |  |
| 435 | `event_formattostring` | 31 | 8.0s |  |
| 436 | `event_isdefaultprevented` | 12 | 7.4s |  |
| 437 | `event_target_getter` | 5 | 3.5s |  |
| 438 | `event_target_set` | 9 | 8.3s |  |
| 439 | `event_type` | 1 | 6.9s |  |
| 440 | `event_valueof_tostring` | 18 | 7.0s |  |
| 441 | `eventdispatcher_dispatchevent` | 12 | 7.0s |  |
| 442 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.0s |  |
| 443 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.0s |  |
| 444 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.0s |  |
| 445 | `eventdispatcher_dispatchevent_this` | 5 | 7.0s |  |
| 446 | `eventdispatcher_haseventlistener` | 25 | 7.0s |  |
| 447 | `eventdispatcher_interface_invoke` | 1 | 7.0s |  |
| 448 | `eventdispatcher_tostring` | 10 | 7.0s |  |
| 449 | `eventdispatcher_willtrigger` | 25 | 6.9s |  |
| 450 | `falsiness` | 30 | 6.8s |  |
| 451 | `fast_index_access` | 12 | 6.9s |  |
| 452 | `filefilter_properties` | 4 | 6.8s |  |
| 453 | `filereference_browse_cancel` | 3 | 6.8s |  |
| 454 | `filereference_browse_select` | 9 | 6.8s |  |
| 455 | `filereference_load` | 31 | 6.8s |  |
| 456 | `filereference_save` | 16 | 6.8s |  |
| 457 | `filereference_save_and_browse` | 42 | 6.8s |  |
| 458 | `filereference_save_and_load` | 22 | 7.2s |  |
| 459 | `filereference_uninitialized` | 8 | 6.8s |  |
| 460 | `filereferencelist_browse_cancel` | 6 | 6.8s |  |
| 461 | `filereferencelist_browse_select` | 7 | 6.8s |  |
| 462 | `filter_rewind` | 8 | 22.1s |  |
| 463 | `filters_array_holes` | 25 | 7.9s |  |
| 464 | `finddef` | 3 | 6.8s |  |
| 465 | `findprop_global_prototype` | 6 | 6.8s |  |
| 466 | `flash_media_video_constructor` | 156 | 7.4s |  |
| 467 | `flash_media_video_rotation_probe` | 27 | 7.1s |  |
| 468 | `flash_media_video_setter` | 40 | 7.2s |  |
| 469 | `flash_trace` | 17 | 6.8s |  |
| 470 | `flash_ui_mouse_cursor` | 35 | 7.1s |  |
| 471 | `flash_xml` | 29 | 6.8s |  |
| 472 | `flash_xml_cloneNode` | 22 | 6.8s |  |
| 473 | `flash_xml_namespace` | 109 | 6.8s |  |
| 474 | `flash_xml_removeNode` | 60 | 6.8s |  |
| 475 | `focus_events_code` | 161 | 22.4s |  |
| 476 | `focus_events_key_basic` | 132 | 22.3s |  |
| 477 | `focus_events_key_navigation` | 53 | 22.2s |  |
| 478 | `focus_events_key_same_object` | 26 | 6.8s |  |
| 479 | `focus_events_mixed_key_mouse` | 100 | 22.2s |  |
| 480 | `focus_events_mouse_basic` | 260 | 22.1s |  |
| 481 | `focus_events_mouse_focusable` | 112 | 22.4s |  |
| 482 | `focus_events_mouse_same_object` | 40 | 6.9s |  |
| 483 | `focus_remove` | 20 | 22.0s |  |
| 484 | `focus_root_movie` | 4 | 23.9s |  |
| 485 | `focus_stage` | 1 | 6.8s |  |
| 486 | `focusrect` | 18 | 7.4s |  |
| 487 | `focusrect_focuslost` | 9 | 6.9s |  |
| 488 | `focusrect_property` | 110 | 2.5s |  |
| 489 | `font_description_clone` | 14 | 6.8s |  |
| 490 | `font_embedded` | 24 | 7.1s |  |
| 491 | `font_enumeratefonts` | 41 | 7.2s |  |
| 492 | `font_enumeratefonts_filter` | 4 | 23.3s |  |
| 493 | `font_enumeratefonts_order` | 9 | 7.6s |  |
| 494 | `font_hasglyphs` | 40 | 7.1s |  |
| 495 | `font_registerfont` | 129 | 7.5s |  |
| 496 | `framelabel_constr` | 5 | 6.7s |  |
| 497 | `function_call` | 12 | 2.3s |  |
| 498 | `function_call_arguments` | 46 | 6.8s |  |
| 499 | `function_call_arguments_enumerate` | 5 | 6.7s |  |
| 500 | `function_call_coercion` | 108 | 7.0s |  |
| 501 | `function_call_default` | 6 | 6.7s |  |
| 502 | `function_call_rest` | 22 | 6.7s |  |
| 503 | `function_call_types` | 3 | 6.7s |  |
| 504 | `function_call_via_apply` | 11 | 6.7s |  |
| 505 | `function_call_via_call` | 3 | 6.7s |  |
| 506 | `function_display_anonymous` | 7 | 2.3s |  |
| 507 | `function_length` | 6 | 6.7s |  |
| 508 | `function_object` | 2 | 6.7s |  |
| 509 | `function_proto` | 5 | 6.7s |  |
| 510 | `function_proto_created` | 61 | 6.8s |  |
| 511 | `function_to_locale_string` | 4 | 6.7s |  |
| 512 | `function_to_string` | 4 | 6.6s |  |
| 513 | `function_type` | 6 | 6.7s |  |
| 514 | `function_unbound_this` | 51 | 6.8s |  |
| 515 | `function_value_of` | 4 | 6.7s |  |
| 516 | `game_input` | 4 | 6.7s |  |
| 517 | `generate_random_bytes` | 3 | 6.7s |  |
| 518 | `get_definition_by_name` | 11 | 6.7s |  |
| 519 | `get_qualified_class_name` | 20 | 6.7s |  |
| 520 | `get_qualified_super_class_name` | 18 | 6.7s |  |
| 521 | `get_slot_edge_cases` | 1 | 6.7s |  |
| 522 | `get_timer` | 2 | 2.2s |  |
| 523 | `getglobalslot` | 1 | 6.6s |  |
| 524 | `getouterscope` | 8 | 6.7s |  |
| 525 | `getouterscope_two_classobjects` | 13 | 6.7s |  |
| 526 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 527 | `glow_filter` | 127 | 7.0s |  |
| 528 | `goto_button_nested_framescript` | 28 | 23.1s |  |
| 529 | `goto_in_constructframe` | 12 | 28.1s |  |
| 530 | `goto_in_scene_last_frame` | 2 | 27.8s |  |
| 531 | `goto_methods` | 56 | 8.4s |  |
| 532 | `goto_methods_swfver10` | 8 | 8.1s |  |
| 533 | `goto_nested_construct_sibling` | 18 | 8.5s |  |
| 534 | `goto_nested_framescript` | 9 | 8.3s |  |
| 535 | `goto_on_orphan` | 15 | 28.1s |  |
| 536 | `gradient_bevel_filter` | 206 | 8.3s |  |
| 537 | `gradient_glow_filter` | 206 | 8.1s |  |
| 538 | `graphic_linkage` | 9 | 8.3s |  |
| 539 | `graphics_bad_direct_commands` | 5 | 10.1s |  |
| 540 | `graphics_bitmap_fill` | 0 | 29.6s |  |
| 541 | `graphics_bitmaps` | 0 | 8.6s |  |
| 542 | `graphics_direct_commands` | 0 | 8.6s |  |
| 543 | `graphics_draw_triangles` | 98 | 28.2s |  |
| 544 | `graphics_gradients` | 0 | 8.3s |  |
| 545 | `graphics_gradients_nulls` | 0 | 8.3s |  |
| 546 | `graphics_path` | 56 | 8.1s |  |
| 547 | `graphics_round_rects` | 0 | 8.0s |  |
| 548 | `graphics_simple_shapes` | 0 | 8.2s |  |
| 549 | `greaterequals` | 512 | 11.3s |  |
| 550 | `greaterthan` | 512 | 11.3s |  |
| 551 | `has_own_property` | 102 | 8.6s |  |
| 552 | `hasownproperty_namespaces` | 2 | 8.0s |  |
| 553 | `hello_world` | 1 | 8.0s |  |
| 554 | `hittest_morph` | 30 | 8.2s |  |
| 555 | `if_eq` | 10 | 8.2s |  |
| 556 | `if_gt` | 1 | 8.2s |  |
| 557 | `if_gte` | 10 | 2.9s |  |
| 558 | `if_lt` | 1 | 1.1s |  |
| 559 | `if_lte` | 10 | 8.1s |  |
| 560 | `if_ne` | 7 | 2.9s |  |
| 561 | `if_stricteq` | 6 | 8.2s |  |
| 562 | `if_strictne` | 11 | 8.2s |  |
| 563 | `ime_linux_dead_keys` | 10 | 8.2s |  |
| 564 | `in` | 102 | 8.8s |  |
| 565 | `inclocal` | 46 | 8.3s |  |
| 566 | `inclocal_i` | 46 | 8.3s |  |
| 567 | `increment` | 46 | 8.2s |  |
| 568 | `increment_i` | 46 | 8.9s |  |
| 569 | `indexing_delete` | 75 | 8.8s |  |
| 570 | `indexof_xml` | 10 | 9.0s |  |
| 571 | `init_callee_cached` | 24 | 8.8s |  |
| 572 | `instanceof` | 58 | 9.1s |  |
| 573 | `instantiate_root_character` | 4 | 9.2s |  |
| 574 | `instantiation_on_enter_frame` | 7 | 28.9s |  |
| 575 | `instantiation_on_enterframe_gotoandstop` | 8 | 8.8s |  |
| 576 | `int_constr` | 92 | 8.7s |  |
| 577 | `int_edge_cases` | 19 | 28.5s |  |
| 578 | `int_instanceof` | 3 | 8.7s |  |
| 579 | `int_tofixed` | 1215 | 8.7s |  |
| 580 | `int_toprecision` | 1125 | 8.8s |  |
| 581 | `int_tostring` | 3375 | 8.9s |  |
| 582 | `interactiveobject_enabled` | 25 | 8.8s |  |
| 583 | `interface_namespaces` | 78 | 9.1s |  |
| 584 | `invalid_utf8` | 12 | 8.9s |  |
| 585 | `is_finite` | 46 | 8.9s |  |
| 586 | `is_nan` | 46 | 8.7s |  |
| 587 | `is_prototype_of` | 12 | 8.8s |  |
| 588 | `issue_10221` | 2 | 8.8s |  |
| 589 | `issue_13780` | 12 | 8.9s |  |
| 590 | `issue_14901` | 1 | 8.8s |  |
| 591 | `issue_17675_edittext_paste_maxchars` | 1 | 8.9s |  |
| 592 | `issue_5292` | 5 | 9.0s |  |
| 593 | `issue_8630` | 2 | 8.9s |  |
| 594 | `issue_8630_placeremoveplace` | 15 | 8.9s |  |
| 595 | `issue_8630_placeremoveplace_scriptremove` | 16 | 8.8s |  |
| 596 | `issue_8630_scriptremove` | 11 | 8.8s |  |
| 597 | `istype` | 24 | 3.5s |  |
| 598 | `istypelate` | 58 | 9.1s |  |
| 599 | `istypelate_coerce` | 198 | 9.8s |  |
| 600 | `jpeg_loader_context` | 6 | 8.8s |  |
| 601 | `json_errors` | 9 | 29.0s |  |
| 602 | `json_parse` | 21 | 8.8s |  |
| 603 | `json_parse_errors` | 84 | 8.8s |  |
| 604 | `json_stringify` | 12 | 9.0s |  |
| 605 | `json_stringify_function` | 12 | 8.8s |  |
| 606 | `json_stringify_order` | 1 | 8.7s |  |
| 607 | `json_version_gated` | 1 | 8.9s |  |
| 608 | `key_input_80percent` | 1812 | 26.2s |  |
| 609 | `key_input_location` | 126 | 6.8s |  |
| 610 | `key_input_numpad` | 384 | 6.8s |  |
| 611 | `large_preload_from_bytes` | 51 | 26.4s |  |
| 612 | `large_preload_from_url` | 27 | 8.7s |  |
| 613 | `large_preload_image_from_bytes` | 25 | 7.3s |  |
| 614 | `lazyinit` | 17 | 6.9s |  |
| 615 | `lessequals` | 512 | 9.3s |  |
| 616 | `lessthan` | 512 | 9.3s |  |
| 617 | `loader_bitmap_transparency` | 14 | 7.0s |  |
| 618 | `loader_bytes_unknown_content` | 14 | 7.0s |  |
| 619 | `loader_child_getdefinition` | 5 | 7.1s |  |
| 620 | `loader_duplicate_class` | 48 | 8.5s |  |
| 621 | `loader_duplicate_coerce` | 3 | 7.1s |  |
| 622 | `loader_duplicate_coerce_new_domain` | 4 | 7.0s |  |
| 623 | `loader_error_in_root_ctor` | 4 | 7.2s |  |
| 624 | `loader_events` | 92 | 8.7s |  |
| 625 | `loader_image` | 8 | 7.3s |  |
| 626 | `loader_jpegxr` | 2 | 23.9s |  |
| 627 | `loader_jpegxr_alpha` | 1 | 24.0s |  |
| 628 | `loader_loadbytes_events` | 30 | 7.6s |  |
| 629 | `loader_loadbytes_invalid_png` | 4 | 7.2s |  |
| 630 | `loader_loadbytes_url` | 12 | 7.3s |  |
| 631 | `loader_loaderurl` | 6 | 7.4s |  |
| 632 | `loader_method` | 85 | 7.1s |  |
| 633 | `loader_noninteractive_try_click_root` | 5 | 24.2s |  |
| 634 | `loader_reuse` | 38 | 7.3s |  |
| 635 | `loader_try_click_root` | 16 | 7.3s |  |
| 636 | `loader_unknown_content` | 24 | 7.2s |  |
| 637 | `loader_visibility_interactive` | 1 | 7.1s |  |
| 638 | `loaderinfo_events` | 7 | 7.1s |  |
| 639 | `loaderinfo_loadurl` | 12 | 7.1s |  |
| 640 | `loaderinfo_more` | 6 | 7.5s |  |
| 641 | `loaderinfo_properties` | 18 | 23.8s |  |
| 642 | `loaderinfo_properties_not_loaded` | 23 | 7.1s |  |
| 643 | `loaderinfo_quine` | 1005 | 7.0s |  |
| 644 | `loaderinfo_root` | 10 | 7.3s |  |
| 645 | `loaderinfo_root_allows` | 2 | 7.3s |  |
| 646 | `localconnection` | 890 | 9.3s |  |
| 647 | `localconnection_send` | 4 | 31.9s |  |
| 648 | `lshift` | 1058 | 21.3s |  |
| 649 | `mask_reapply` | 1 | 29.7s |  |
| 650 | `math` | 497 | 9.0s |  |
| 651 | `matrix` | 338 | 20.1s |  |
| 652 | `matrix3d` | 57 | 29.8s |  |
| 653 | `matrix3d_append` | 16 | 8.9s |  |
| 654 | `matrix3d_append_prepend_scale` | 86 | 8.9s |  |
| 655 | `matrix3d_append_prepend_translation` | 42 | 8.8s |  |
| 656 | `matrix3d_append_rotation` | 23 | 8.9s |  |
| 657 | `matrix3d_compose` | 34 | 9.1s |  |
| 658 | `matrix3d_constructor_clone` | 15 | 8.8s |  |
| 659 | `matrix3d_copy_column` | 83 | 9.1s |  |
| 660 | `matrix3d_copy_from` | 19 | 8.8s |  |
| 661 | `matrix3d_copy_raw_data_from` | 55 | 3.5s |  |
| 662 | `matrix3d_copy_raw_data_to` | 38 | 9.0s |  |
| 663 | `matrix3d_copy_row` | 83 | 8.7s |  |
| 664 | `matrix3d_copy_to_matrix3d` | 19 | 8.9s |  |
| 665 | `matrix3d_determinant` | 182 | 9.0s |  |
| 666 | `matrix3d_interpolate` | 21 | 9.1s |  |
| 667 | `matrix3d_invert` | 18 | 8.8s |  |
| 668 | `matrix3d_position` | 19 | 8.9s |  |
| 669 | `matrix3d_precision` | 28 | 8.9s |  |
| 670 | `matrix3d_prepend` | 16 | 8.7s |  |
| 671 | `matrix3d_raw_data` | 33 | 8.9s |  |
| 672 | `matrix3d_transform_vector` | 52 | 9.2s |  |
| 673 | `matrix3d_transpose` | 5 | 8.8s |  |
| 674 | `method_association` | 5 | 8.9s |  |
| 675 | `method_without_body` | 3 | 29.0s |  |
| 676 | `missing_external_interface` | 10 | 8.9s |  |
| 677 | `modulo` | 1058 | 21.4s |  |
| 678 | `morph_shape` | 2 | 29.2s |  |
| 679 | `mouse_children` | 192 | 29.9s |  |
| 680 | `mouse_click_events` | 90 | 29.3s |  |
| 681 | `mouse_double_click_events` | 188 | 8.9s |  |
| 682 | `mouse_empty_parent` | 4 | 8.8s |  |
| 683 | `mouse_over_while_dragging` | 3 | 8.9s |  |
| 684 | `mouse_pick_avm1_root` | 2 | 29.4s |  |
| 685 | `mouse_pick_button_mode` | 2 | 9.1s |  |
| 686 | `mouse_pick_dobj_mask` | 4 | 9.5s |  |
| 687 | `mouse_pick_masking` | 7 | 31.6s |  |
| 688 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 28.4s |  |
| 689 | `mouse_pick_non_interactive_dobj_mask` | 3 | 28.5s |  |
| 690 | `mouse_pick_text` | 8 | 8.8s |  |
| 691 | `mouse_sibling` | 8 | 8.6s |  |
| 692 | `mouse_wheel_events` | 36 | 29.4s |  |
| 693 | `mouseevent_constr` | 66 | 8.6s |  |
| 694 | `mouseevent_stagexy` | 35 | 8.6s |  |
| 695 | `mouseevent_valueof_tostring` | 28 | 8.6s |  |
| 696 | `movieclip_addframescript` | 3 | 28.3s |  |
| 697 | `movieclip_addframescript_error` | 9 | 8.7s |  |
| 698 | `movieclip_child_property` | 16 | 8.7s |  |
| 699 | `movieclip_constr` | 21 | 8.6s |  |
| 700 | `movieclip_currentlabels` | 17 | 28.4s |  |
| 701 | `movieclip_currentlabels_dupes1` | 46 | 28.3s |  |
| 702 | `movieclip_currentlabels_dupes2` | 30 | 8.6s |  |
| 703 | `movieclip_currentlabels_dupes3` | 67 | 8.6s |  |
| 704 | `movieclip_currentscene` | 12 | 28.4s |  |
| 705 | `movieclip_dispatchevent` | 430 | 8.8s |  |
| 706 | `movieclip_dispatchevent_cancel` | 102 | 8.9s |  |
| 707 | `movieclip_dispatchevent_handlerorder` | 251 | 8.8s |  |
| 708 | `movieclip_dispatchevent_selfadd` | 80 | 8.7s |  |
| 709 | `movieclip_dispatchevent_target` | 899 | 8.8s |  |
| 710 | `movieclip_displayevents` | 96 | 28.8s |  |
| 711 | `movieclip_displayevents_clickgoto` | 676 | 29.2s |  |
| 712 | `movieclip_displayevents_clickgoto2` | 2001 | 9.4s |  |
| 713 | `movieclip_displayevents_clickplay` | 575 | 8.9s |  |
| 714 | `movieclip_displayevents_clicksymbol` | 562 | 8.9s |  |
| 715 | `movieclip_displayevents_constructframegoto` | 140 | 9.1s |  |
| 716 | `movieclip_displayevents_constructframeplay` | 50 | 9.0s |  |
| 717 | `movieclip_displayevents_constructframesymbol` | 144 | 8.8s |  |
| 718 | `movieclip_displayevents_dblhandler` | 21 | 8.9s |  |
| 719 | `movieclip_displayevents_enterframegoto` | 149 | 9.1s |  |
| 720 | `movieclip_displayevents_enterframeplay` | 48 | 8.8s |  |
| 721 | `movieclip_displayevents_enterframesymbol` | 149 | 28.9s |  |
| 722 | `movieclip_displayevents_exitframegoto` | 106 | 8.7s |  |
| 723 | `movieclip_displayevents_exitframeplay` | 44 | 8.7s |  |
| 724 | `movieclip_displayevents_exitframesymbol` | 135 | 8.8s |  |
| 725 | `movieclip_displayevents_looping` | 63 | 28.6s |  |
| 726 | `movieclip_displayevents_stopped` | 113 | 9.2s |  |
| 727 | `movieclip_displayevents_swap` | 96 | 3.2s |  |
| 728 | `movieclip_displayevents_timeline` | 128 | 9.1s |  |
| 729 | `movieclip_drawrect` | 54 | 32.7s |  |
| 730 | `movieclip_frameconstruct_skipped` | 9 | 9.1s |  |
| 731 | `movieclip_goto_during_frame_script` | 15 | 29.3s |  |
| 732 | `movieclip_goto_overwrite` | 14 | 29.7s |  |
| 733 | `movieclip_goto_scene_last_frame_int` | 1 | 29.7s |  |
| 734 | `movieclip_goto_scene_last_frame_label` | 1 | 9.1s |  |
| 735 | `movieclip_gotoandplay` | 15 | 29.5s |  |
| 736 | `movieclip_gotoandstop` | 13 | 9.0s |  |
| 737 | `movieclip_gotoandstop_children` | 4 | 9.1s |  |
| 738 | `movieclip_gotoandstop_framescripts1` | 4 | 9.1s |  |
| 739 | `movieclip_gotoandstop_framescripts2` | 4 | 3.6s |  |
| 740 | `movieclip_gotoandstop_framescripts_self` | 7 | 30.2s |  |
| 741 | `movieclip_gotoandstop_queueing` | 12 | 30.5s |  |
| 742 | `movieclip_hittest` | 67 | 9.6s |  |
| 743 | `movieclip_next_frame` | 2 | 9.4s |  |
| 744 | `movieclip_next_scene` | 6 | 31.2s |  |
| 745 | `movieclip_play` | 3 | 9.2s |  |
| 746 | `movieclip_prev_frame` | 3 | 9.1s |  |
| 747 | `movieclip_prev_scene` | 7 | 9.4s |  |
| 748 | `movieclip_properties` | 79 | 31.5s |  |
| 749 | `movieclip_queued_noop_goto_swf10` | 9 | 9.5s |  |
| 750 | `movieclip_queued_noop_goto_swf9` | 7 | 1.6s |  |
| 751 | `movieclip_scenes` | 11 | 9.6s |  |
| 752 | `movieclip_soundtransform` | 831 | 33.4s |  |
| 753 | `movieclip_stop` | 1 | 9.4s |  |
| 754 | `movieclip_super_is_symbol` | 20 | 9.7s |  |
| 755 | `movieclip_symbol_constr` | 8 | 9.5s |  |
| 756 | `movieclip_text_mousedown` | 1 | 9.5s |  |
| 757 | `movieclip_willtrigger` | 5 | 9.5s |  |
| 758 | `multiply` | 1058 | 21.3s |  |
| 759 | `namespace_constr` | 253 | 9.7s |  |
| 760 | `namespace_constr_args` | 1 | 9.4s |  |
| 761 | `namespace_enumeration_order` | 7 | 31.3s |  |
| 762 | `nan_scale` | 9 | 9.3s |  |
| 763 | `native_menu_basic` | 19 | 11.9s |  |
| 764 | `navigateToURL_target_normalize` | 107 | 33.0s |  |
| 765 | `negate` | 30 | 9.3s |  |
| 766 | `negative_volume_panned` | 0 | 9.7s |  |
| 767 | `nested_iteration` | 11 | 9.3s |  |
| 768 | `net_getClassByAlias` | 3 | 9.3s |  |
| 769 | `net_navigateToURL` | 57 | 9.2s |  |
| 770 | `net_stream_play_options` | 6 | 9.2s |  |
| 771 | `netconnection_close` | 55 | 25.8s |  |
| 772 | `netconnection_properties` | 78 | 6.9s |  |
| 773 | `netconnection_send_remote` | 50 | 25.7s |  |
| 774 | `netconnection_serialize_arrays` | 6 | 6.9s |  |
| 775 | `netfilterevent` | 10 | 23.1s |  |
| 776 | `netstream_client` | 10 | 7.0s |  |
| 777 | `netstream_connect` | 7 | 6.8s |  |
| 778 | `netstream_flv_date` | 4 | 6.8s |  |
| 779 | `newactivation_in_script_init` | 3 | 6.7s |  |
| 780 | `newclass_mismatched` | 4 | 6.8s |  |
| 781 | `newclass_twice` | 3 | 6.7s |  |
| 782 | `nonconflicting_declarations` | 0 | 6.8s |  |
| 783 | `null_void_types` | 8 | 6.8s |  |
| 784 | `number_autoconv` | 21 | 6.8s |  |
| 785 | `number_autoconv_amf` | 132 | 6.8s |  |
| 786 | `number_autoconv_array_sort_32bit` | 1 | 6.8s |  |
| 787 | `number_constr` | 58 | 6.8s |  |
| 788 | `number_convert_edge_cases` | 180 | 23.2s |  |
| 789 | `number_toexponential` | 378 | 6.9s |  |
| 790 | `number_toexponential2` | 35 | 6.8s |  |
| 791 | `number_tofixed` | 378 | 6.7s |  |
| 792 | `number_toprecision` | 350 | 6.8s |  |
| 793 | `obfuscated_class_names` | 3 | 6.8s |  |
| 794 | `object_enumeration` | 10 | 6.8s |  |
| 795 | `object_prototype` | 4 | 6.8s |  |
| 796 | `object_to_locale_string` | 2 | 6.8s |  |
| 797 | `object_to_string` | 2 | 6.8s |  |
| 798 | `object_value_of` | 2 | 2.2s |  |
| 799 | `op_coerce` | 54 | 6.8s |  |
| 800 | `op_coerce_x` | 54 | 6.8s |  |
| 801 | `op_escxattr` | 2 | 6.8s |  |
| 802 | `op_escxelem` | 2 | 6.8s |  |
| 803 | `op_lookupswitch` | 4 | 6.8s |  |
| 804 | `optimize_coerce` | 1 | 6.7s |  |
| 805 | `orphan_movie_complex` | 80 | 7.2s |  |
| 806 | `orphan_movie_reorder` | 111 | 23.5s |  |
| 807 | `orphan_removeobject` | 636 | 32.0s |  |
| 808 | `package_namespace` | 7 | 28.6s |  |
| 809 | `param_default_value_has_zero_cpool_index` | 1 | 29.3s |  |
| 810 | `parent_early_access_child` | 16 | 28.6s |  |
| 811 | `parse_float` | 81 | 9.1s |  |
| 812 | `parse_float_swf10` | 81 | 8.7s |  |
| 813 | `parse_int` | 135 | 9.2s |  |
| 814 | `perspective_projection` | 1443 | 28.4s |  |
| 815 | `perspective_projection_basic` | 40 | 8.8s |  |
| 816 | `pixelbender_ceil` | 77 | 8.9s |  |
| 817 | `pixelbender_conditional` | 138 | 9.1s |  |
| 818 | `pixelbender_conversions` | 270 | 9.1s |  |
| 819 | `pixelbender_dithering` | 8 | 35.5s |  |
| 820 | `pixelbender_div` | 36 | 8.9s |  |
| 821 | `pixelbender_effect_BlurredFocus` | 0 | 36.5s |  |
| 822 | `pixelbender_effect_glassDisplace` | 0 | 15.1s |  |
| 823 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 33.0s |  |
| 824 | `pixelbender_effect_smudge` | 0 | 12.3s |  |
| 825 | `pixelbender_effect_tintype` | 0 | 11.4s |  |
| 826 | `pixelbender_effect_twirl` | 0 | 13.0s |  |
| 827 | `pixelbender_eof` | 7 | 8.8s |  |
| 828 | `pixelbender_images` | 0 | 11.1s |  |
| 829 | `pixelbender_input` | 103 | 28.9s |  |
| 830 | `pixelbender_logicalnot` | 20 | 8.8s |  |
| 831 | `pixelbender_malformed_data` | 190 | 29.4s |  |
| 832 | `pixelbender_multiple_out_params` | 1 | 8.8s |  |
| 833 | `pixelbender_no_out_param` | 6 | 8.7s |  |
| 834 | `pixelbender_outputs` | 13 | 8.9s |  |
| 835 | `pixelbender_padding_bytes` | 22 | 8.9s |  |
| 836 | `pixelbender_param_qualifier` | 512 | 8.9s |  |
| 837 | `pixelbender_parameters` | 1563 | 9.2s |  |
| 838 | `pixelbender_parameters_bool` | 240 | 9.1s |  |
| 839 | `pixelbender_parameters_int_vs_bool` | 54 | 8.9s |  |
| 840 | `pixelbender_parse_errors` | 6 | 8.8s |  |
| 841 | `pixelbender_rsqrt` | 24 | 8.9s |  |
| 842 | `pixelbender_select_kinds` | 8 | 8.9s |  |
| 843 | `pixelbender_shaderdata` | 49 | 8.8s |  |
| 844 | `pixelbender_shaderdata_setter` | 99 | 9.2s |  |
| 845 | `pixelbender_sign` | 60 | 9.0s |  |
| 846 | `pixelbender_vector_output` | 11 | 9.1s |  |
| 847 | `place_and_lookup/swf10` | 33 | 9.0s |  |
| 848 | `place_and_lookup/swf9` | 33 | 1.4s |  |
| 849 | `place_multiple` | 17 | 31.9s |  |
| 850 | `place_object_replace` | 9 | 28.9s |  |
| 851 | `place_object_replace_2` | 24 | 28.8s |  |
| 852 | `place_object_same_depth_frame` | 1 | 28.4s |  |
| 853 | `point` | 132 | 9.1s |  |
| 854 | `primitive_edge_cases` | 1 | 8.5s |  |
| 855 | `primitive_keys` | 54 | 8.7s |  |
| 856 | `primitive_toString` | 277 | 8.6s |  |
| 857 | `primitive_valueOf` | 285 | 8.3s |  |
| 858 | `print_job_options` | 3 | 8.4s |  |
| 859 | `property_is_enumerable` | 114 | 9.2s |  |
| 860 | `property_is_enumerable_reset` | 23 | 8.6s |  |
| 861 | `property_priority` | 22 | 8.9s |  |
| 862 | `property_priority_chained` | 4 | 8.6s |  |
| 863 | `property_priority_definition_names_order` | 2 | 8.8s |  |
| 864 | `property_priority_three_level` | 6 | 8.8s |  |
| 865 | `propertyisenumerable_namespaces` | 6 | 8.5s |  |
| 866 | `prototype_set_null` | 7 | 8.5s |  |
| 867 | `proxy_callproperty` | 24 | 8.5s |  |
| 868 | `proxy_deleteproperty` | 64 | 8.6s |  |
| 869 | `proxy_enumeration` | 34 | 8.5s |  |
| 870 | `proxy_getproperty` | 77 | 8.6s |  |
| 871 | `proxy_hasownproperty` | 8 | 8.5s |  |
| 872 | `proxy_hasproperty` | 32 | 8.6s |  |
| 873 | `proxy_not_overridden` | 54 | 8.6s |  |
| 874 | `proxy_serialize` | 9 | 8.5s |  |
| 875 | `proxy_setproperty` | 42 | 8.6s |  |
| 876 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.5s |  |
| 877 | `qname_constr` | 32 | 8.6s |  |
| 878 | `qname_constr_namespace` | 24 | 8.6s |  |
| 879 | `qname_enumeration` | 9 | 8.5s |  |
| 880 | `qname_indexing` | 23 | 8.6s |  |
| 881 | `qname_tostring` | 25 | 8.7s |  |
| 882 | `qname_valueof` | 29 | 8.7s |  |
| 883 | `rectangle` | 1094 | 9.3s |  |
| 884 | `regexp_constr` | 148 | 8.8s |  |
| 885 | `regexp_exec` | 19 | 8.6s |  |
| 886 | `regexp_extended` | 47 | 8.6s |  |
| 887 | `regexp_multiargs` | 1 | 8.6s |  |
| 888 | `regexp_test` | 27 | 8.7s |  |
| 889 | `regexp_toString` | 10 | 8.7s |  |
| 890 | `register_script_refresh` | 35 | 28.9s |  |
| 891 | `remove_child_clear_field` | 88 | 32.5s |  |
| 892 | `remove_dobj` | 3 | 28.9s |  |
| 893 | `resolve_order` | 4 | 8.9s |  |
| 894 | `responder_null_callbacks` | 1 | 29.4s |  |
| 895 | `rng` | 1 | 10.1s |  |
| 896 | `rootless` | 42 | 8.9s |  |
| 897 | `rshift` | 1058 | 21.3s |  |
| 898 | `rtqname_not_namespace` | 12 | 9.0s |  |
| 899 | `sandbox_type_inherited` | 2 | 9.4s |  |
| 900 | `sandbox_type_local_file` | 1 | 8.9s |  |
| 901 | `sandbox_type_local_network` | 1 | 8.8s |  |
| 902 | `scene_constr` | 8 | 8.7s |  |
| 903 | `scope_optimizations` | 4 | 8.6s |  |
| 904 | `scopes_dont_cache/order-1` | 1 | 29.4s |  |
| 905 | `scopes_dont_cache/order-2` | 1 | 1.1s |  |
| 906 | `security_domain_current` | 2 | 8.8s |  |
| 907 | `selection` | 239 | 9.8s |  |
| 908 | `set_local_0` | 31 | 8.9s |  |
| 909 | `set_property_is_enumerable` | 85 | 9.2s |  |
| 910 | `shaderparameter_value` | 4 | 8.8s |  |
| 911 | `shape_drawrect` | 54 | 8.7s |  |
| 912 | `shared_object_no_root` | 3 | 8.7s |  |
| 913 | `simplebutton_added_to_stage` | 45 | 28.9s |  |
| 914 | `simplebutton_childevents` | 86 | 29.3s |  |
| 915 | `simplebutton_childevents_nested` | 54 | 9.2s |  |
| 916 | `simplebutton_childevents_sprite` | 13 | 8.8s |  |
| 917 | `simplebutton_childprops` | 144 | 8.9s |  |
| 918 | `simplebutton_childshuffle` | 23 | 8.6s |  |
| 919 | `simplebutton_constr` | 36 | 9.0s |  |
| 920 | `simplebutton_constr_childevents` | 48 | 8.9s |  |
| 921 | `simplebutton_constr_params` | 42 | 8.8s |  |
| 922 | `simplebutton_mouseenabled` | 26 | 8.8s |  |
| 923 | `simplebutton_multi_children` | 19 | 8.9s |  |
| 924 | `simplebutton_soundtransform` | 887 | 30.9s |  |
| 925 | `simplebutton_structure` | 27 | 8.9s |  |
| 926 | `simplebutton_symbolclass` | 68 | 9.0s |  |
| 927 | `slot_disp_id_shared_numbering` | 1 | 28.1s |  |
| 928 | `slots_force_autoassigned` | 1 | 28.0s |  |
| 929 | `socket_after_disconnect` | 1 | 8.3s |  |
| 930 | `socket_close` | 2 | 8.1s |  |
| 931 | `socket_connect` | 4 | 8.2s |  |
| 932 | `socket_errors` | 56 | 8.6s |  |
| 933 | `socket_read_big` | 48 | 8.2s |  |
| 934 | `socket_read_little` | 48 | 2.8s |  |
| 935 | `socket_read_write_object` | 8 | 8.3s |  |
| 936 | `socket_write_big` | 15 | 8.8s |  |
| 937 | `socket_write_little` | 14 | 8.9s |  |
| 938 | `sound_constructor_with_args` | 6 | 8.4s |  |
| 939 | `sound_embeddedprops` | 26 | 8.5s |  |
| 940 | `sound_play` | 19 | 8.4s |  |
| 941 | `sound_rootless` | 7 | 8.3s |  |
| 942 | `sound_valueof` | 33 | 8.4s |  |
| 943 | `soundchannel_soundtransform` | 835 | 29.4s |  |
| 944 | `soundchannel_soundtransform_exists` | 5 | 27.5s |  |
| 945 | `soundchannel_stop` | 8 | 27.6s |  |
| 946 | `soundmixer_buffertime` | 5 | 8.2s |  |
| 947 | `soundmixer_soundtransform` | 900 | 10.2s |  |
| 948 | `soundmixer_stopall` | 6 | 27.8s |  |
| 949 | `soundtransform` | 442 | 12.4s |  |
| 950 | `space_justifier_clone` | 12 | 8.2s |  |
| 951 | `sprite_with_frames` | 0 | 32.2s |  |
| 952 | `stage3d_agal_cross_product` | 0 | 10.6s |  |
| 953 | `stage3d_agal_upload_errors` | 66 | 10.7s |  |
| 954 | `stage3d_bitmap` | 0 | 32.6s |  |
| 955 | `stage3d_blend` | 81 | 31.7s |  |
| 956 | `stage3d_context3d_string_args` | 158 | 9.2s |  |
| 957 | `stage3d_errors` | 7 | 8.3s |  |
| 958 | `stage3d_errors_atf` | 3 | 9.5s |  |
| 959 | `stage3d_errors_swf_29` | 6 | 8.3s |  |
| 960 | `stage3d_float1_index` | 0 | 30.3s |  |
| 961 | `stage3d_fractal` | 0 | 31.3s |  |
| 962 | `stage3d_ignore_sampler_override` | 0 | 30.5s |  |
| 963 | `stage3d_multistage_triangle` | 3 | 10.8s |  |
| 964 | `stage3d_program_constants_bytearray_be` | 0 | 32.2s |  |
| 965 | `stage3d_program_constants_bytearray_le` | 0 | 37.7s |  |
| 966 | `stage3d_program_constants_invalid_input` | 21 | 29.8s |  |
| 967 | `stage3d_raytrace` | 0 | 54.3s |  |
| 968 | `stage3d_rotating_cube` | 0 | 12.2s |  |
| 969 | `stage3d_sampler` | 0 | 11.4s |  |
| 970 | `stage3d_sampler_partial_upload` | 0 | 11.3s |  |
| 971 | `stage3d_stencil` | 0 | 31.4s |  |
| 972 | `stage3d_texture` | 0 | 16.7s |  |
| 973 | `stage3d_texture_bytearray` | 0 | 12.6s |  |
| 974 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 11.9s |  |
| 975 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 13.0s |  |
| 976 | `stage3d_triangle` | 0 | 11.3s |  |
| 977 | `stage3d_triangle_bytes4` | 0 | 11.3s |  |
| 978 | `stage3d_triangle_float1` | 0 | 11.2s |  |
| 979 | `stage3d_triangle_index_upload` | 0 | 11.3s |  |
| 980 | `stage3d_x_y` | 22 | 8.6s |  |
| 981 | `stage_access` | 10 | 8.6s |  |
| 982 | `stage_display_state` | 6 | 8.6s |  |
| 983 | `stage_displayobject_properties` | 24 | 8.4s |  |
| 984 | `stage_domain_getQualifiedDefinitionNames` | 5 | 8.5s |  |
| 985 | `stage_framerate_nan` | 7 | 8.8s |  |
| 986 | `stage_framerate_negative` | 6 | 8.5s |  |
| 987 | `stage_framerate_zero` | 6 | 8.5s |  |
| 988 | `stage_invalidate` | 38 | 8.7s |  |
| 989 | `stage_loaderinfo_properties` | 24 | 27.9s |  |
| 990 | `stage_mousechildren` | 2 | 8.4s |  |
| 991 | `stage_mouseenabled` | 15 | 8.4s |  |
| 992 | `stage_overriden_setters` | 31 | 8.7s |  |
| 993 | `stage_properties` | 30 | 8.5s |  |
| 994 | `stage_properties2` | 213 | 8.9s |  |
| 995 | `stage_scale_factor` | 12 | 34.1s |  |
| 996 | `stage_stage3Ds_vector` | 1 | 8.6s |  |
| 997 | `static_length` | 24 | 8.7s |  |
| 998 | `static_text` | 3 | 8.8s |  |
| 999 | `static_var_with_this_in_ctor` | 2 | 8.5s |  |
| 1000 | `statictext_text` | 8 | 8.7s |  |
| 1001 | `stored_properties` | 11 | 8.7s |  |
| 1002 | `strict_equality` | 34 | 8.6s |  |
| 1003 | `string_call` | 13 | 8.5s |  |
| 1004 | `string_case` | 23 | 8.6s |  |
| 1005 | `string_char_at` | 27 | 8.5s |  |
| 1006 | `string_char_code_at` | 28 | 8.4s |  |
| 1007 | `string_concat_fromcharcode` | 37 | 31.1s |  |
| 1008 | `string_constr` | 25 | 28.1s |  |
| 1009 | `string_indexof_lastindexof` | 87 | 8.9s |  |
| 1010 | `string_length` | 16 | 8.5s |  |
| 1011 | `string_locale_compare` | 39 | 8.8s |  |
| 1012 | `string_match` | 51 | 8.8s |  |
| 1013 | `string_relational_compare` | 4 | 8.5s |  |
| 1014 | `string_replace` | 51 | 8.8s |  |
| 1015 | `string_search` | 41 | 8.7s |  |
| 1016 | `string_slice_substr_substring` | 170 | 9.9s |  |
| 1017 | `string_split` | 29 | 8.7s |  |
| 1018 | `string_substr_negative` | 21 | 8.5s |  |
| 1019 | `string_substr_weird` | 182 | 8.5s |  |
| 1020 | `stylesheet` | 221 | 9.1s |  |
| 1021 | `stylesheet_parse_color` | 69 | 8.7s |  |
| 1022 | `stylesheet_transform` | 307 | 9.0s |  |
| 1023 | `sub_super_same_field` | 12 | 3.4s |  |
| 1024 | `subclass_superclass_linked_symbol` | 4 | 9.1s |  |
| 1025 | `subtract` | 1058 | 20.8s |  |
| 1026 | `super_get_call` | 12 | 8.6s |  |
| 1027 | `supercall_two_classobjects` | 2 | 8.6s |  |
| 1028 | `supercalls_coerce` | 8 | 8.7s |  |
| 1029 | `supercalls_weird` | 2 | 8.6s |  |
| 1030 | `superinterface_call` | 20 | 8.6s |  |
| 1031 | `superinterface_instanceof` | 18 | 8.5s |  |
| 1032 | `swf8` | 1 | 8.5s |  |
| 1033 | `swf_10_queued_goto_scripts_construct` | 52 | 28.4s |  |
| 1034 | `swf_9_goto_in_enter_frame` | 17 | 8.6s |  |
| 1035 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.6s |  |
| 1036 | `swf_9_queued_goto_scripts` | 6 | 28.4s |  |
| 1037 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 1038 | `swf_9_versioning` | 2 | 8.5s |  |
| 1039 | `swf_wrong_frame_count` | 38 | 8.9s |  |
| 1040 | `swf_wrong_frame_count_isplaying` | 22 | 8.7s |  |
| 1041 | `symbol_class_binary_data` | 8 | 8.6s |  |
| 1042 | `symbol_class_conflict` | 4 | 12.4s |  |
| 1043 | `symbol_class_root_not_zero` | 1 | 8.5s |  |
| 1044 | `symbolclass_invalid_utf8` | 2 | 8.6s |  |
| 1045 | `system_exit` | 3 | 8.6s |  |
| 1046 | `system_setclipboard_null` | 1 | 8.5s |  |
| 1047 | `tab_ordering_arrows` | 998 | 31.9s |  |
| 1048 | `tab_ordering_automatic_advanced` | 184 | 9.1s |  |
| 1049 | `tab_ordering_automatic_basic` | 45 | 27.7s |  |
| 1050 | `tab_ordering_children` | 116 | 8.6s |  |
| 1051 | `tab_ordering_custom_basic` | 34 | 8.5s |  |
| 1052 | `tab_ordering_stage_tab_children` | 32 | 8.5s |  |
| 1053 | `tab_ordering_stage_tab_children_remove_root` | 5 | 8.4s |  |
| 1054 | `tab_ordering_tabbable` | 47 | 8.6s |  |
| 1055 | `tabstop_properties` | 105 | 27.9s |  |
| 1056 | `text_element_basic` | 34 | 8.6s |  |
| 1057 | `text_engine_fontdescription` | 27 | 8.6s |  |
| 1058 | `text_engine_groupelement` | 64 | 9.4s |  |
| 1059 | `text_run` | 7 | 8.4s |  |
| 1060 | `textblock_createline_errors` | 23 | 8.7s |  |
| 1061 | `textblock_createline_fte` | 9 | 28.4s |  |
| 1062 | `textblock_properties` | 118 | 8.9s |  |
| 1063 | `textbox_click` | 37 | 28.0s |  |
| 1064 | `textfield_event` | 66 | 8.8s |  |
| 1065 | `textfield_focusin_event` | 9 | 8.4s |  |
| 1066 | `textfield_input_dead_keys_windows` | 15 | 8.5s |  |
| 1067 | `textfield_input_events` | 25 | 21.1s |  |
| 1068 | `textfield_unload` | 39 | 27.8s |  |
| 1069 | `textformat` | 1134 | 8.6s |  |
| 1070 | `textformat_display` | 14 | 8.5s |  |
| 1071 | `textformat_font_max_length` | 4 | 8.4s |  |
| 1072 | `textline_inapplicable_properties` | 10 | 8.4s |  |
| 1073 | `textline_name` | 1 | 8.4s |  |
| 1074 | `textline_raw_text_length` | 30 | 8.4s |  |
| 1075 | `textline_splitting_basic` | 76 | 8.6s |  |
| 1076 | `textline_throwerror` | 30 | 8.4s |  |
| 1077 | `textline_validity` | 162 | 8.6s |  |
| 1078 | `throw` | 3 | 8.5s |  |
| 1079 | `timeline_scripts` | 3 | 27.6s |  |
| 1080 | `timer` | 90 | 9.5s |  |
| 1081 | `timer_events` | 3 | 8.6s |  |
| 1082 | `timer_finished` | 11 | 8.6s |  |
| 1083 | `timer_invalid_delay` | 30 | 8.6s |  |
| 1084 | `timer_reset` | 8 | 29.9s |  |
| 1085 | `timer_setdelay` | 5 | 27.1s |  |
| 1086 | `trace` | 12 | 7.2s |  |
| 1087 | `truthiness` | 30 | 7.2s |  |
| 1088 | `try_catch` | 11 | 7.2s |  |
| 1089 | `try_catch_typed` | 12 | 7.2s |  |
| 1090 | `typeof` | 30 | 7.2s |  |
| 1091 | `uint_constr` | 92 | 7.2s |  |
| 1092 | `uint_tofixed` | 1215 | 7.2s |  |
| 1093 | `uint_toprecision` | 1125 | 7.2s |  |
| 1094 | `uint_tostring` | 3375 | 7.2s |  |
| 1095 | `uncaught_error_basic` | 2 | 7.3s |  |
| 1096 | `unchecked_function` | 15 | 7.2s |  |
| 1097 | `unescape` | 28 | 7.2s |  |
| 1098 | `url_loader` | 25 | 7.2s |  |
| 1099 | `url_vars` | 27 | 7.2s |  |
| 1100 | `urlrequest` | 18 | 7.2s |  |
| 1101 | `urlstream_basic` | 5 | 7.2s |  |
| 1102 | `urshift` | 1058 | 7.2s |  |
| 1103 | `utils3d` | 7 | 7.2s |  |
| 1104 | `vector3d` | 397 | 7.2s |  |
| 1105 | `vector3d_near_equals` | 80 | 7.2s |  |
| 1106 | `vector_class` | 36 | 7.2s |  |
| 1107 | `vector_class_call` | 11 | 7.2s |  |
| 1108 | `vector_coercion` | 66 | 7.2s |  |
| 1109 | `vector_concat` | 90 | 7.3s |  |
| 1110 | `vector_constr` | 107 | 7.2s |  |
| 1111 | `vector_enumeration` | 5 | 7.2s |  |
| 1112 | `vector_every` | 92 | 7.2s |  |
| 1113 | `vector_filter` | 95 | 7.2s |  |
| 1114 | `vector_holes` | 24 | 7.2s |  |
| 1115 | `vector_indexof` | 302 | 7.2s |  |
| 1116 | `vector_insertat` | 270 | 7.2s |  |
| 1117 | `vector_int_access` | 4 | 7.2s |  |
| 1118 | `vector_int_delete` | 11 | 7.2s |  |
| 1119 | `vector_join` | 58 | 7.2s |  |
| 1120 | `vector_lastindexof` | 302 | 7.3s |  |
| 1121 | `vector_legacy` | 10 | 7.2s |  |
| 1122 | `vector_map` | 85 | 7.2s |  |
| 1123 | `vector_object_final` | 1 | 7.2s |  |
| 1124 | `vector_object_toString` | 10 | 34.5s |  |
| 1125 | `vector_pushpop` | 255 | 33.0s |  |
| 1126 | `vector_reborrow_bug` | 10 | 9.4s |  |
| 1127 | `vector_removeat` | 172 | 10.8s |  |
| 1128 | `vector_reverse` | 232 | 10.9s |  |
| 1129 | `vector_shiftunshift` | 252 | 9.4s |  |
| 1130 | `vector_slice` | 331 | 11.5s |  |
| 1131 | `vector_sort` | 905 | 19.4s |  |
| 1132 | `vector_splice` | 693 | 13.9s |  |
| 1133 | `vector_splice_fixed_bug_compat` | 4 | 9.6s |  |
| 1134 | `vector_tostring` | 79 | 10.3s |  |
| 1135 | `verification` | 8 | 9.6s |  |
| 1136 | `verify_abnormal_loop` | 1 | 9.3s |  |
| 1137 | `verify_dxns_without_flag` | 3 | 9.8s |  |
| 1138 | `verify_exception_target_two_jumps` | 1 | 9.3s |  |
| 1139 | `verify_exception_targets_edge_case` | 1 | 9.4s |  |
| 1140 | `verify_illegal_opcode` | 1 | 4.1s |  |
| 1141 | `verify_jump_to_middle_of_op` | 1 | 9.3s |  |
| 1142 | `verify_lookup_switch_edge_case` | 1 | 9.2s |  |
| 1143 | `verify_method_info_oob` | 1 | 1.4s |  |
| 1144 | `verify_stack` | 5 | 9.4s |  |
| 1145 | `verify_typecheck` | 4 | 9.2s |  |
| 1146 | `verify_unreachable_exception` | 2 | 9.2s |  |
| 1147 | `versioned_isplaying` | 2 | 9.3s |  |
| 1148 | `virtual_properties` | 16 | 9.3s |  |
| 1149 | `with` | 4 | 9.3s |  |
| 1150 | `wrong_arg_count` | 7 | 9.4s |  |
| 1151 | `xml_abstract_equality` | 36 | 9.4s |  |
| 1152 | `xml_advanced` | 52 | 9.3s |  |
| 1153 | `xml_appendchild` | 10 | 9.2s |  |
| 1154 | `xml_appendchild_swf_v21` | 13 | 9.7s |  |
| 1155 | `xml_as_attribute` | 9 | 9.2s |  |
| 1156 | `xml_attribute` | 35 | 9.5s |  |
| 1157 | `xml_attribute_name` | 40 | 9.3s |  |
| 1158 | `xml_basic` | 33 | 9.2s |  |
| 1159 | `xml_child` | 25 | 9.3s |  |
| 1160 | `xml_childindex` | 7 | 9.3s |  |
| 1161 | `xml_children` | 43 | 9.9s |  |
| 1162 | `xml_class_call` | 9 | 9.3s |  |
| 1163 | `xml_contains` | 197 | 9.5s |  |
| 1164 | `xml_copy` | 20 | 30.6s |  |
| 1165 | `xml_ctor_from_tostring` | 23 | 27.9s |  |
| 1166 | `xml_delete` | 114 | 8.5s |  |
| 1167 | `xml_descendants` | 83 | 8.5s |  |
| 1168 | `xml_duplicate_attribute` | 14 | 8.5s |  |
| 1169 | `xml_elements` | 6 | 8.4s |  |
| 1170 | `xml_equals_namespace_check` | 2 | 8.4s |  |
| 1171 | `xml_explicit_use_namespace` | 5 | 8.5s |  |
| 1172 | `xml_getdescendants_qname` | 21 | 8.5s |  |
| 1173 | `xml_has_property_via_in` | 26 | 8.5s |  |
| 1174 | `xml_hasownproperty` | 6 | 8.5s |  |
| 1175 | `xml_ignore_white` | 6 | 8.5s |  |
| 1176 | `xml_length` | 2 | 8.5s |  |
| 1177 | `xml_list_as_attribute` | 9 | 8.5s |  |
| 1178 | `xml_list_concat` | 20 | 8.5s |  |
| 1179 | `xml_list_ctor_errors` | 34 | 8.6s |  |
| 1180 | `xml_list_delete_clear_parent` | 6 | 8.5s |  |
| 1181 | `xml_list_enumerate` | 4 | 8.4s |  |
| 1182 | `xml_methods_settings` | 3 | 8.5s |  |
| 1183 | `xml_mismatched_tag` | 37 | 8.6s |  |
| 1184 | `xml_namespace` | 39 | 8.6s |  |
| 1185 | `xml_namespace_methods` | 245 | 8.7s |  |
| 1186 | `xml_namespaced_property` | 7 | 8.7s |  |
| 1187 | `xml_no_namespace` | 1 | 8.6s |  |
| 1188 | `xml_nodekind` | 3 | 8.6s |  |
| 1189 | `xml_normalize` | 35 | 8.7s |  |
| 1190 | `xml_notification_bubbling` | 361 | 8.6s |  |
| 1191 | `xml_parent` | 8 | 8.6s |  |
| 1192 | `xml_set_children` | 17 | 8.7s |  |
| 1193 | `xml_set_name` | 34 | 8.6s |  |
| 1194 | `xml_settings` | 6 | 3.2s |  |
| 1195 | `xml_simple_complex_content` | 47 | 8.7s |  |
| 1196 | `xml_socket` | 11 | 8.9s |  |
| 1197 | `xml_text` | 7 | 8.6s |  |
| 1198 | `xml_tostring` | 6 | 8.7s |  |
| 1199 | `xml_tostring_namespace` | 12 | 8.5s |  |
| 1200 | `xml_unescaping` | 23 | 8.6s |  |
| 1201 | `xml_weird_ignores` | 54 | 8.6s |  |
| 1202 | `xml_wildcard` | 11 | 8.6s |  |
| 1203 | `xmldocument` | 254 | 8.8s |  |
| 1204 | `xmlnode` | 3540 | 8.8s |  |
| 1205 | `zero_frame_clip` | 3 | 9.1s |  |

## Ruffle-Matched Tests

**36 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.8s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.1s |  |
| 3 | `blend_transform` | 1 | 1 | 8.8s |  |
| 4 | `bounds_mode` | 6 | 6 | 8.9s |  |
| 5 | `coerce_property` | 3 | 3 | 5.9s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.2s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 28.7s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 27.4s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 7.2s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.0s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 6.9s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 7.0s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 23.8s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 7.2s |  |
| 15 | `event_handler_exception` | 4 | 4 | 7.3s |  |
| 16 | `freestanding_superclass` | 2 | 4 | 6.7s |  |
| 17 | `goto_framescript_queued/swf13` | 42 | 42 | 1.0s |  |
| 18 | `graphics_draw_path` | 50 | 50 | 28.2s |  |
| 19 | `groupelement_text` | 2 | 2 | 8.2s |  |
| 20 | `int_toexponential` | 76 | 76 | 8.7s |  |
| 21 | `json_parse_numbers` | 4 | 79 | 8.8s |  |
| 22 | `loader_events_2` | 30 | 30 | 7.5s |  |
| 23 | `matrix3d_recompose_edge_cases` | 8 | 85 | 9.3s |  |
| 24 | `number_convert_errors` | 706 | 706 | 7.0s |  |
| 25 | `simplebutton_childevents_script_order` | 4 | 4 | 9.0s |  |
| 26 | `slot_holes_fail` | 1 | 1 | 8.6s |  |
| 27 | `slot_id_exceeds_trait_count` | 1 | 1 | 30.4s |  |
| 28 | `soundchannel_position` | 74 | 74 | 28.9s |  |
| 29 | `soundchannel_soundcomplete` | 10 | 10 | 8.5s |  |
| 30 | `sprite_dropTarget` | 15 | 15 | 8.2s |  |
| 31 | `swf_9_goto_in_construct_frame` | 12 | 12 | 28.2s |  |
| 32 | `textblock_line_changes` | 44 | 44 | 9.2s |  |
| 33 | `textblock_releaselines` | 4 | 4 | 10.2s |  |
| 34 | `uint_toexponential` | 100 | 100 | 7.2s |  |
| 35 | `uncaught_errors_stringified` | 15 | 15 | 7.3s |  |
| 36 | `weird_superinterface_properties` | 1 | 1 | 9.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**12 tests** within reach

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
| 9 | `bitmapdata_copypixels_alpha_merge` | 55.6% | 5 | 9 | 4 |  |
| 10 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 11 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 12 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**33 tests** with output mismatch, sorted by match rate (best first)

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
| 9 | `bitmapdata_copypixels_alpha_merge` | 55.6% | 5/9 | 9 | 9 |  |
| 10 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 11 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 12 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 13 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 14 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 15 | `goto_framescript_queued/swf10` | 25.4% | 15/59 | 48 | 59 |  |
| 16 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 17 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 18 | `goto_framescript_queued/swf9` | 21.2% | 11/52 | 46 | 52 |  |
| 19 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 20 | `displayobject_z` | 15.8% | 6/38 | 11 | 38 |  |
| 21 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 22 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 23 | `edittext_scroll_event` | 5.4% | 2/37 | 7 | 37 |  |
| 24 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 25 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 26 | `bitmapdata_copypixels_blend` | 0.0% | 0/1049 | 1049 | 1029 |  |
| 27 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 28 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 29 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 30 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 31 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 32 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 33 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
