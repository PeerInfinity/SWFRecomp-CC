# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-11 18:44 UTC

**Git SHA**: `ea6960eaca`

**Run Duration**: 210m 12s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1270 |
| Passing | **1200** (94.5%) |
| Ruffle-matched | 36 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1236** (97.3%) |
| Failing | 34 |
| Total expected lines | 155348 |
| Matching lines | 152229 (98.0%) |
| Mismatched lines | 3119 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 34 | 100.0% |

## Passing Tests

**1200 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 27.2s |  |
| 2 | `accessibility` | 1 | 7.5s |  |
| 3 | `accessibilityimplementation` | 18 | 27.4s |  |
| 4 | `activation_class` | 6 | 7.4s |  |
| 5 | `add` | 1058 | 18.9s |  |
| 6 | `agal_compiler` | 13 | 9.7s |  |
| 7 | `air_datagram_socket` | 1 | 9.6s |  |
| 8 | `air_hidden_lookup` | 2 | 7.5s |  |
| 9 | `air_ifilepromise` | 1 | 7.6s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 7.8s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.7s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.7s |  |
| 13 | `all_classes/display/swf10` | 2569 | 7.9s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.8s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.7s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.8s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.7s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.7s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 7.7s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.7s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.7s |  |
| 22 | `all_classes/errors/swf10` | 140 | 7.7s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.7s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.7s |  |
| 25 | `all_classes/events/swf10` | 1638 | 7.7s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.7s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.7s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.7s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.7s |  |
| 30 | `all_classes/security/swf11` | 3 | 7.5s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.6s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.6s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.7s |  |
| 34 | `all_classes/xml/swf30` | 116 | 7.5s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.6s |  |
| 36 | `amf_array_serialization` | 17 | 29.7s |  |
| 37 | `amf_custom_obj` | 26 | 7.5s |  |
| 38 | `amf_dictionary` | 9 | 7.5s |  |
| 39 | `amf_function` | 46 | 7.5s |  |
| 40 | `amf_invalid_date` | 2 | 7.3s |  |
| 41 | `amf_missing_prop` | 6 | 7.4s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 7.4s |  |
| 43 | `amf_setter_error` | 8 | 7.5s |  |
| 44 | `amf_vector` | 40 | 27.0s |  |
| 45 | `amf_xml` | 6 | 7.2s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 7.6s |  |
| 47 | `application_domain` | 4 | 7.2s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 26.8s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 6.9s |  |
| 50 | `array_access` | 18 | 7.2s |  |
| 51 | `array_access_interpreter` | 4 | 7.1s |  |
| 52 | `array_access_no_pubns` | 2 | 2.3s |  |
| 53 | `array_concat` | 41 | 7.1s |  |
| 54 | `array_constr` | 10 | 6.9s |  |
| 55 | `array_delete` | 44 | 7.2s |  |
| 56 | `array_enumeration` | 10 | 7.2s |  |
| 57 | `array_enumeration_elements` | 11 | 7.1s |  |
| 58 | `array_every` | 8 | 2.4s |  |
| 59 | `array_filter` | 6 | 7.2s |  |
| 60 | `array_foreach` | 18 | 7.2s |  |
| 61 | `array_hasownproperty` | 11 | 7.1s |  |
| 62 | `array_holes` | 9 | 7.2s |  |
| 63 | `array_index_max` | 84 | 7.1s |  |
| 64 | `array_indexof` | 25 | 7.2s |  |
| 65 | `array_join` | 26 | 7.2s |  |
| 66 | `array_lastindexof` | 29 | 7.2s |  |
| 67 | `array_length` | 14 | 7.1s |  |
| 68 | `array_literal` | 3 | 7.1s |  |
| 69 | `array_map` | 8 | 6.9s |  |
| 70 | `array_pop` | 52 | 7.2s |  |
| 71 | `array_push` | 24 | 7.2s |  |
| 72 | `array_reborrow_bug` | 6 | 7.1s |  |
| 73 | `array_reverse` | 28 | 7.2s |  |
| 74 | `array_shift` | 51 | 2.5s |  |
| 75 | `array_slice` | 39 | 7.2s |  |
| 76 | `array_some` | 8 | 7.2s |  |
| 77 | `array_sort` | 297 | 7.6s |  |
| 78 | `array_sort_fun_swf12` | 2 | 7.1s |  |
| 79 | `array_sort_fun_swf13` | 2 | 0.7s |  |
| 80 | `array_sort_random` | 210 | 7.2s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 7.1s |  |
| 82 | `array_sorton` | 545 | 8.0s |  |
| 83 | `array_sparse_ops` | 41 | 7.3s |  |
| 84 | `array_splice` | 133 | 7.4s |  |
| 85 | `array_splice2` | 428 | 27.2s |  |
| 86 | `array_splice_types` | 48 | 7.4s |  |
| 87 | `array_storage` | 8 | 27.0s |  |
| 88 | `array_tolocalestring` | 9 | 7.3s |  |
| 89 | `array_tostring` | 12 | 7.3s |  |
| 90 | `array_unshift` | 24 | 7.2s |  |
| 91 | `array_valueof` | 9 | 2.3s |  |
| 92 | `array_vector_null_callback` | 10 | 7.2s |  |
| 93 | `astype` | 28 | 7.3s |  |
| 94 | `astypelate` | 24 | 7.4s |  |
| 95 | `astypelate_propagates` | 1 | 7.3s |  |
| 96 | `asymmetric_key_events` | 11 | 7.5s |  |
| 97 | `automation_classes` | 122 | 7.6s |  |
| 98 | `av_classes` | 340 | 7.5s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 7.5s |  |
| 100 | `avm2_catchup_dobj` | 158 | 8.0s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 85.8s |  |
| 102 | `bevel_filter` | 187 | 7.3s |  |
| 103 | `bitand` | 1058 | 19.4s |  |
| 104 | `bitmap_constr` | 17 | 7.4s |  |
| 105 | `bitmap_data` | 1000 | 15.4s |  |
| 106 | `bitmap_pixelsnapping` | 2 | 26.8s |  |
| 107 | `bitmap_properties` | 23 | 7.2s |  |
| 108 | `bitmap_subclass` | 7 | 8.7s |  |
| 109 | `bitmap_subclass_properties` | 9 | 7.5s |  |
| 110 | `bitmap_timeline` | 9 | 7.2s |  |
| 111 | `bitmapdata_accuracy` | 1 | 43.4s |  |
| 112 | `bitmapdata_applyfilter_blur` | 0 | 27.3s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.8s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | 0 | 27.5s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.8s |  |
| 116 | `bitmapdata_applyfilter_identity` | 4 | 26.3s |  |
| 117 | `bitmapdata_clone` | 13 | 7.3s |  |
| 118 | `bitmapdata_colortransform` | 0 | 7.5s |  |
| 119 | `bitmapdata_colortransform_oob` | 2 | 7.1s |  |
| 120 | `bitmapdata_constr` | 22 | 7.2s |  |
| 121 | `bitmapdata_constructor_from_timeline` | 1 | 7.6s |  |
| 122 | `bitmapdata_copychannel` | 0 | 28.5s |  |
| 123 | `bitmapdata_copypixels` | 23 | 26.8s |  |
| 124 | `bitmapdata_copypixels_alpha_combine` | 13 | 7.4s |  |
| 125 | `bitmapdata_copypixels_blend_over` | 1 | 7.4s |  |
| 126 | `bitmapdata_copypixelstobytearray` | 39 | 7.4s |  |
| 127 | `bitmapdata_dispose` | 7 | 7.4s |  |
| 128 | `bitmapdata_draw` | 0 | 27.0s |  |
| 129 | `bitmapdata_draw_alpha_erase` | 8 | 7.5s |  |
| 130 | `bitmapdata_draw_cab_quality` | 0 | 28.5s |  |
| 131 | `bitmapdata_draw_colortransform` | 0 | 26.9s |  |
| 132 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 27.1s |  |
| 133 | `bitmapdata_draw_filters` | 0 | 27.0s |  |
| 134 | `bitmapdata_draw_masks` | 0 | 7.4s |  |
| 135 | `bitmapdata_draw_rotation` | 0 | 7.4s |  |
| 136 | `bitmapdata_draw_self_via_graphic` | 0 | 7.4s |  |
| 137 | `bitmapdata_draw_stage` | 0 | 26.8s |  |
| 138 | `bitmapdata_drawwithquality` | 0 | 7.6s |  |
| 139 | `bitmapdata_embedded` | 9 | 2.6s |  |
| 140 | `bitmapdata_fillrect` | 0 | 7.4s |  |
| 141 | `bitmapdata_filter_sourcerect` | 0 | 22.0s |  |
| 142 | `bitmapdata_floodfill` | 35 | 7.3s |  |
| 143 | `bitmapdata_getpixels` | 39 | 26.7s |  |
| 144 | `bitmapdata_getvector` | 27 | 2.5s |  |
| 145 | `bitmapdata_histogram` | 59 | 2.5s |  |
| 146 | `bitmapdata_hittest` | 112 | 8.0s |  |
| 147 | `bitmapdata_hittest_threshold` | 18 | 7.4s |  |
| 148 | `bitmapdata_opaque` | 0 | 7.4s |  |
| 149 | `bitmapdata_pixeldissolve` | 1037 | 8.0s |  |
| 150 | `bitmapdata_pixeldissolve_image` | 0 | 7.6s |  |
| 151 | `bitmapdata_rectangle_rounding` | 16 | 7.4s |  |
| 152 | `bitmapdata_setpixels` | 286 | 2.6s |  |
| 153 | `bitmapdata_setvector` | 26 | 7.4s |  |
| 154 | `bitmapdata_sync` | 0 | 27.2s |  |
| 155 | `bitmapdata_threshold` | 176 | 8.2s |  |
| 156 | `bitmapdata_zero_size` | 8 | 7.4s |  |
| 157 | `bitnot` | 46 | 7.4s |  |
| 158 | `bitor` | 1058 | 18.8s |  |
| 159 | `bitxor` | 1058 | 18.7s |  |
| 160 | `blend_mode_null` | 1 | 7.3s |  |
| 161 | `blend_multiply_alpha` | 0 | 7.4s |  |
| 162 | `blend_scroll` | 0 | 7.5s |  |
| 163 | `blend_shader_luma_lighten` | 3 | 7.6s |  |
| 164 | `blur_filter` | 43 | 7.5s |  |
| 165 | `boolean_constr` | 32 | 22.5s |  |
| 166 | `boolean_negation` | 30 | 5.9s |  |
| 167 | `boolean_tostring` | 8 | 6.1s |  |
| 168 | `broadcast_event` | 7 | 5.7s |  |
| 169 | `button_bounds` | 1 | 5.9s |  |
| 170 | `button_hittest` | 2 | 21.7s |  |
| 171 | `button_nested_frame` | 48 | 22.2s |  |
| 172 | `button_nested_frame_simple` | 27 | 6.0s |  |
| 173 | `bytearray` | 48 | 6.0s |  |
| 174 | `bytearray_compress` | 31 | 21.1s |  |
| 175 | `bytearray_errors` | 24 | 5.8s |  |
| 176 | `bytearray_method_serialization` | 1 | 5.7s |  |
| 177 | `bytearray_oom` | 3 | 5.8s |  |
| 178 | `bytearray_readobject_amf0` | 50 | 5.9s |  |
| 179 | `bytearray_readobject_amf3` | 53 | 5.8s |  |
| 180 | `bytearray_readutf8bytes_with_bom` | 16 | 5.8s |  |
| 181 | `bytearray_serialization` | 3 | 5.8s |  |
| 182 | `bytearray_string_null` | 19 | 6.0s |  |
| 183 | `bytearray_tostring` | 15 | 5.9s |  |
| 184 | `bytearray_utf16` | 8 | 6.0s |  |
| 185 | `bytearray_writeobject` | 24 | 5.7s |  |
| 186 | `callee_in_initializer` | 6 | 5.8s |  |
| 187 | `callproplex_class` | 1 | 5.8s |  |
| 188 | `capabilities_resolution` | 8 | 22.5s |  |
| 189 | `catch_class` | 6 | 5.8s |  |
| 190 | `catch_scope_slot` | 7 | 5.8s |  |
| 191 | `checkfilter` | 4 | 2.0s |  |
| 192 | `class_call` | 32 | 6.0s |  |
| 193 | `class_cast_call` | 14 | 6.0s |  |
| 194 | `class_enumeration` | 4 | 5.9s |  |
| 195 | `class_has_own_property` | 2 | 5.9s |  |
| 196 | `class_init_interpreter_mode` | 1 | 6.0s |  |
| 197 | `class_is` | 32 | 6.1s |  |
| 198 | `class_methods` | 5 | 5.9s |  |
| 199 | `class_object_properties` | 10 | 5.9s |  |
| 200 | `class_singleton` | 18 | 6.2s |  |
| 201 | `class_supercalls_errors` | 35 | 6.0s |  |
| 202 | `class_supercalls_mismatched` | 26 | 5.9s |  |
| 203 | `class_superclass_wrong_order` | 1 | 5.9s |  |
| 204 | `class_to_locale_string` | 2 | 5.8s |  |
| 205 | `class_to_string` | 2 | 7.0s |  |
| 206 | `class_value_of` | 2 | 7.0s |  |
| 207 | `click_block` | 5 | 26.3s |  |
| 208 | `click_invisible` | 3 | 7.0s |  |
| 209 | `closures` | 12 | 7.1s |  |
| 210 | `coerce_return_type` | 40 | 7.2s |  |
| 211 | `coerce_return_type_fail` | 2 | 7.0s |  |
| 212 | `coerce_return_void` | 3 | 6.9s |  |
| 213 | `coerce_string` | 86 | 7.2s |  |
| 214 | `coerce_string_precision` | 28 | 7.0s |  |
| 215 | `coerce_to_primitive_side_effects` | 29 | 25.7s |  |
| 216 | `color_matrix_filter` | 19 | 7.1s |  |
| 217 | `construct_errors_swf10` | 8 | 7.1s |  |
| 218 | `construct_frame_list` | 22 | 26.0s |  |
| 219 | `construct_interface` | 3 | 7.1s |  |
| 220 | `constructor_call` | 3 | 7.1s |  |
| 221 | `constructors_vs_timeline` | 5 | 26.1s |  |
| 222 | `constructprop_dynamic_primitive` | 7 | 7.2s |  |
| 223 | `constructprop_method` | 2 | 7.2s |  |
| 224 | `constructsuper_null` | 2 | 7.1s |  |
| 225 | `content_element_basic` | 50 | 7.4s |  |
| 226 | `context3d_creation` | 9 | 7.2s |  |
| 227 | `control_flow_bool` | 4 | 7.1s |  |
| 228 | `control_flow_stricteq` | 8 | 7.1s |  |
| 229 | `convert_boolean` | 30 | 7.1s |  |
| 230 | `convert_integer` | 90 | 7.2s |  |
| 231 | `convert_number` | 56 | 7.2s |  |
| 232 | `convert_uinteger` | 90 | 7.2s |  |
| 233 | `convolution_filter` | 89 | 7.2s |  |
| 234 | `core_exceptions` | 47 | 8.0s |  |
| 235 | `cpool_index_invalid_bytecode_1` | 6 | 7.1s |  |
| 236 | `cpool_index_invalid_bytecode_2` | 3 | 7.0s |  |
| 237 | `cpool_index_invalid_bytecode_3` | 1 | 7.1s |  |
| 238 | `cross_api_version_call_newer` | 12 | 7.7s |  |
| 239 | `cross_api_version_call_older` | 12 | 7.3s |  |
| 240 | `cryptscore` | 11 | 7.2s |  |
| 241 | `currency_parse_result` | 7 | 7.1s |  |
| 242 | `date` | 30 | 7.5s |  |
| 243 | `date_parse` | 36 | 7.1s |  |
| 244 | `declocal` | 46 | 7.1s |  |
| 245 | `declocal_i` | 46 | 7.1s |  |
| 246 | `decode_uri` | 71 | 7.4s |  |
| 247 | `decrement` | 46 | 7.1s |  |
| 248 | `decrement_i` | 46 | 7.1s |  |
| 249 | `default_values` | 7 | 7.0s |  |
| 250 | `delayed_symbolclass` | 28 | 26.4s |  |
| 251 | `describe_type_basic` | 152 | 7.1s |  |
| 252 | `describe_type_json` | 301 | 7.2s |  |
| 253 | `describe_type_metadata` | 125 | 7.2s |  |
| 254 | `describe_type_native` | 23 | 7.1s |  |
| 255 | `dictionary_access` | 62 | 7.3s |  |
| 256 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 257 | `dictionary_delete` | 101 | 7.5s |  |
| 258 | `dictionary_foreach` | 42 | 7.3s |  |
| 259 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 260 | `dictionary_in` | 62 | 7.3s |  |
| 261 | `dictionary_iter_modify` | 8 | 7.1s |  |
| 262 | `dictionary_namespaces` | 36 | 7.2s |  |
| 263 | `displacement_map_filter` | 61 | 7.3s |  |
| 264 | `displayobject_alpha` | 277 | 7.0s |  |
| 265 | `displayobject_blendmode` | 0 | 25.9s |  |
| 266 | `displayobject_colortransform_nested` | 0 | 26.2s |  |
| 267 | `displayobject_early_init` | 54 | 8.6s |  |
| 268 | `displayobject_filters` | 17 | 7.2s |  |
| 269 | `displayobject_from_enterframe` | 1 | 26.1s |  |
| 270 | `displayobject_getbounds_shape` | 0 | 26.0s |  |
| 271 | `displayobject_height` | 6052 | 26.5s |  |
| 272 | `displayobject_hittestobject` | 32 | 7.2s |  |
| 273 | `displayobject_hittestpoint` | 49 | 7.2s |  |
| 274 | `displayobject_hittestpoint_boundary` | 65 | 26.4s |  |
| 275 | `displayobject_hittestpoint_root` | 13 | 7.3s |  |
| 276 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 277 | `displayobject_invalid_props` | 3 | 7.1s |  |
| 278 | `displayobject_mask` | 3 | 7.1s |  |
| 279 | `displayobject_mask_self_referential` | 0 | 7.0s |  |
| 280 | `displayobject_metaData` | 3 | 6.8s |  |
| 281 | `displayobject_name` | 22 | 26.0s |  |
| 282 | `displayobject_name_from_timeline` | 24 | 7.2s |  |
| 283 | `displayobject_opaque_background` | 6 | 7.1s |  |
| 284 | `displayobject_parent` | 12 | 7.1s |  |
| 285 | `displayobject_root` | 24 | 7.1s |  |
| 286 | `displayobject_rotation` | 1284 | 7.1s |  |
| 287 | `displayobject_scrollrect` | 33 | 7.4s |  |
| 288 | `displayobject_set_matrix_nested` | 0 | 26.8s |  |
| 289 | `displayobject_set_name_loaded` | 3 | 7.4s |  |
| 290 | `displayobject_subclass` | 2 | 7.0s |  |
| 291 | `displayobject_transform` | 89 | 26.7s |  |
| 292 | `displayobject_visible` | 23 | 26.9s |  |
| 293 | `displayobject_width` | 4852 | 27.1s |  |
| 294 | `displayobject_x` | 614 | 7.0s |  |
| 295 | `displayobject_y` | 617 | 7.0s |  |
| 296 | `displayobjectcontainer_addchild` | 32 | 7.1s |  |
| 297 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.0s |  |
| 298 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.2s |  |
| 299 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.1s |  |
| 300 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.1s |  |
| 301 | `displayobjectcontainer_addchildat` | 42 | 7.0s |  |
| 302 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.2s |  |
| 303 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.0s |  |
| 304 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.1s |  |
| 305 | `displayobjectcontainer_contains` | 66 | 27.1s |  |
| 306 | `displayobjectcontainer_getchildat` | 4 | 7.2s |  |
| 307 | `displayobjectcontainer_getchildbyname` | 9 | 7.1s |  |
| 308 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.1s |  |
| 309 | `displayobjectcontainer_getchildindex` | 28 | 7.1s |  |
| 310 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 27.1s |  |
| 311 | `displayobjectcontainer_removechild` | 10 | 7.1s |  |
| 312 | `displayobjectcontainer_removechild_errors` | 4 | 7.0s |  |
| 313 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.1s |  |
| 314 | `displayobjectcontainer_removechildat` | 18 | 7.0s |  |
| 315 | `displayobjectcontainer_removechildren` | 51 | 7.3s |  |
| 316 | `displayobjectcontainer_setchildindex` | 42 | 7.0s |  |
| 317 | `displayobjectcontainer_stopallmovieclips` | 2 | 27.0s |  |
| 318 | `displayobjectcontainer_swapchildren` | 42 | 7.1s |  |
| 319 | `displayobjectcontainer_swapchildrenat` | 42 | 7.1s |  |
| 320 | `displayobjectcontainer_timelineinstance` | 48 | 27.0s |  |
| 321 | `divide` | 1058 | 16.8s |  |
| 322 | `doabc_and_symbolclass_script_init_goto` | 7 | 26.8s |  |
| 323 | `doabc_and_symbolclass_script_init_normal` | 6 | 7.0s |  |
| 324 | `doabc_is_eager` | 1 | 26.4s |  |
| 325 | `documentclass` | 9 | 7.1s |  |
| 326 | `domain_memory` | 133 | 8.0s |  |
| 327 | `drag_drop` | 10 | 7.3s |  |
| 328 | `drop_shadow_filter` | 172 | 7.3s |  |
| 329 | `duplicate_defs` | 1 | 7.1s |  |
| 330 | `eager_init` | 1 | 7.1s |  |
| 331 | `east_asian_justifier_clone` | 8 | 27.0s |  |
| 332 | `edit_text_linkage` | 7 | 7.2s |  |
| 333 | `edittext_align` | 60 | 7.5s |  |
| 334 | `edittext_always_show_selection` | 0 | 27.0s |  |
| 335 | `edittext_antialiastype` | 296 | 7.4s |  |
| 336 | `edittext_at_point_methods_basic` | 16 | 8.4s |  |
| 337 | `edittext_autosize` | 39 | 7.5s |  |
| 338 | `edittext_autosize_align` | 0 | 27.1s |  |
| 339 | `edittext_autosize_height_dynamic` | 60 | 27.2s |  |
| 340 | `edittext_autosize_height_input` | 60 | 7.2s |  |
| 341 | `edittext_autosize_lazy_bounds_events` | 65 | 7.5s |  |
| 342 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.1s |  |
| 343 | `edittext_autosize_lazy_bounds_props` | 490 | 8.6s |  |
| 344 | `edittext_autosize_lazy_bounds_visual` | 0 | 7.2s |  |
| 345 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.3s |  |
| 346 | `edittext_bottom_scroll_v_basic` | 210 | 7.3s |  |
| 347 | `edittext_bounds_scale` | 24 | 27.1s |  |
| 348 | `edittext_bullet` | 30 | 7.2s |  |
| 349 | `edittext_default_format` | 221 | 7.6s |  |
| 350 | `edittext_default_format_empty` | 136 | 7.5s |  |
| 351 | `edittext_empty_text_format` | 7 | 7.2s |  |
| 352 | `edittext_focus_selection` | 5 | 7.1s |  |
| 353 | `edittext_font_size` | 45 | 7.3s |  |
| 354 | `edittext_format_empty_font` | 8 | 7.1s |  |
| 355 | `edittext_get_char_index_at_point` | 4 | 28.7s |  |
| 356 | `edittext_get_line_index_at_point` | 2 | 27.1s |  |
| 357 | `edittext_get_line_index_of_char` | 76 | 8.1s |  |
| 358 | `edittext_getcharboundaries` | 172 | 7.6s |  |
| 359 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.2s |  |
| 360 | `edittext_getcharboundaries_scroll` | 85 | 7.2s |  |
| 361 | `edittext_getlinemetrics` | 146 | 7.5s |  |
| 362 | `edittext_html` | 3101 | 7.7s |  |
| 363 | `edittext_html_condensewhite` | 487 | 7.3s |  |
| 364 | `edittext_html_entity` | 4 | 7.3s |  |
| 365 | `edittext_html_font_size_swf12` | 267 | 7.3s |  |
| 366 | `edittext_html_font_size_swf13` | 273 | 6.9s |  |
| 367 | `edittext_html_roundtrip` | 17 | 7.8s |  |
| 368 | `edittext_ime_focus_lost` | 9 | 28.1s |  |
| 369 | `edittext_input_control` | 12 | 28.1s |  |
| 370 | `edittext_leading` | 9 | 7.9s |  |
| 371 | `edittext_letter_spacing` | 15 | 8.0s |  |
| 372 | `edittext_line_methods` | 294 | 9.1s |  |
| 373 | `edittext_line_metrics` | 11 | 29.8s |  |
| 374 | `edittext_margins` | 25 | 7.7s |  |
| 375 | `edittext_max_scroll_h_basic` | 475 | 8.1s |  |
| 376 | `edittext_max_scroll_v_basic` | 1000 | 7.8s |  |
| 377 | `edittext_mouse_selection` | 363 | 30.2s |  |
| 378 | `edittext_mousedown` | 3 | 8.2s |  |
| 379 | `edittext_mouseenabled` | 26 | 7.8s |  |
| 380 | `edittext_newline_character` | 22 | 7.8s |  |
| 381 | `edittext_newline_stripping` | 64 | 10.8s |  |
| 382 | `edittext_newlines` | 30 | 8.0s |  |
| 383 | `edittext_paragraph_methods` | 257 | 7.9s |  |
| 384 | `edittext_paste_events` | 8 | 8.1s |  |
| 385 | `edittext_paste_maxchars` | 4 | 7.8s |  |
| 386 | `edittext_paste_restrict` | 16 | 7.7s |  |
| 387 | `edittext_restrict` | 191 | 7.9s |  |
| 388 | `edittext_restrict_events` | 22 | 8.0s |  |
| 389 | `edittext_scrollh` | 10 | 2.6s |  |
| 390 | `edittext_selected_text` | 9 | 2.6s |  |
| 391 | `edittext_set_html_same` | 17 | 7.8s |  |
| 392 | `edittext_set_text_vs_html` | 9 | 7.8s |  |
| 393 | `edittext_stylesheet` | 536 | 8.2s |  |
| 394 | `edittext_stylesheet_custom_tag` | 76 | 8.0s |  |
| 395 | `edittext_stylesheet_display` | 272 | 8.0s |  |
| 396 | `edittext_tag_indent` | 49 | 29.2s |  |
| 397 | `edittext_underline` | 40 | 8.0s |  |
| 398 | `edittext_width_height` | 103 | 8.2s |  |
| 399 | `edittext_wordwrap_word` | 150 | 8.1s |  |
| 400 | `edittext_wrap_breaks` | 2375 | 8.5s |  |
| 401 | `element_format_clone` | 44 | 8.0s |  |
| 402 | `element_format_constructor_order` | 64 | 2.9s |  |
| 403 | `element_format_properties` | 235 | 9.0s |  |
| 404 | `empty_bounds` | 1 | 7.8s |  |
| 405 | `encode_uri_surrogate_pair_invalid` | 8 | 7.9s |  |
| 406 | `encode_uri_surrogate_pair_swf11` | 15 | 7.6s |  |
| 407 | `equals` | 512 | 30.3s |  |
| 408 | `error_geterrormessage` | 779 | 7.4s |  |
| 409 | `error_prototype` | 15 | 7.3s |  |
| 410 | `error_stack_trace` | 45 | 7.4s |  |
| 411 | `error_stack_trace_debug_swf17` | 0 | 26.8s |  |
| 412 | `error_stack_trace_debug_swf18` | 0 | 7.1s |  |
| 413 | `error_stack_trace_edge_cases` | 6 | 7.4s |  |
| 414 | `error_stack_trace_release_swf17` | 0 | 2.4s |  |
| 415 | `error_stack_trace_release_swf18` | 0 | 7.0s |  |
| 416 | `error_throwerror` | 103 | 7.4s |  |
| 417 | `error_tostring` | 29 | 7.3s |  |
| 418 | `error_tostring_more` | 86 | 26.6s |  |
| 419 | `es3_inheritance` | 31 | 7.4s |  |
| 420 | `es4_inheritance` | 30 | 7.4s |  |
| 421 | `es4_interfaces` | 30 | 7.4s |  |
| 422 | `es4_method_binding` | 8 | 7.4s |  |
| 423 | `es4_oop_prototypes` | 14 | 7.5s |  |
| 424 | `es4_protected_inheritance` | 6 | 7.4s |  |
| 425 | `escape` | 71 | 7.4s |  |
| 426 | `escape_multi_byte` | 45 | 7.5s |  |
| 427 | `event_bubbles` | 2 | 7.3s |  |
| 428 | `event_cancelable` | 2 | 7.0s |  |
| 429 | `event_clone` | 20 | 7.4s |  |
| 430 | `event_clone_error_redispatch` | 3 | 2.6s |  |
| 431 | `event_clone_on_redispatch` | 10 | 7.5s |  |
| 432 | `event_formattostring` | 31 | 7.4s |  |
| 433 | `event_isdefaultprevented` | 12 | 7.3s |  |
| 434 | `event_target_getter` | 5 | 2.5s |  |
| 435 | `event_target_set` | 9 | 7.3s |  |
| 436 | `event_type` | 1 | 7.3s |  |
| 437 | `event_valueof_tostring` | 18 | 7.4s |  |
| 438 | `eventdispatcher_dispatchevent` | 12 | 7.3s |  |
| 439 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.4s |  |
| 440 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.4s |  |
| 441 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.4s |  |
| 442 | `eventdispatcher_dispatchevent_this` | 5 | 7.4s |  |
| 443 | `eventdispatcher_haseventlistener` | 25 | 7.4s |  |
| 444 | `eventdispatcher_interface_invoke` | 1 | 7.3s |  |
| 445 | `eventdispatcher_tostring` | 10 | 7.3s |  |
| 446 | `eventdispatcher_willtrigger` | 25 | 7.2s |  |
| 447 | `falsiness` | 30 | 7.3s |  |
| 448 | `fast_index_access` | 12 | 7.3s |  |
| 449 | `filefilter_properties` | 4 | 7.2s |  |
| 450 | `filereference_browse_cancel` | 3 | 7.2s |  |
| 451 | `filereference_browse_select` | 9 | 2.4s |  |
| 452 | `filereference_load` | 31 | 7.2s |  |
| 453 | `filereference_save` | 16 | 7.2s |  |
| 454 | `filereference_save_and_browse` | 42 | 7.3s |  |
| 455 | `filereference_save_and_load` | 22 | 7.4s |  |
| 456 | `filereference_uninitialized` | 8 | 7.2s |  |
| 457 | `filereferencelist_browse_cancel` | 6 | 7.2s |  |
| 458 | `filereferencelist_browse_select` | 7 | 7.2s |  |
| 459 | `filter_rewind` | 8 | 27.0s |  |
| 460 | `filters_array_holes` | 25 | 7.4s |  |
| 461 | `finddef` | 3 | 7.3s |  |
| 462 | `findprop_global_prototype` | 6 | 7.4s |  |
| 463 | `flash_media_video_constructor` | 156 | 8.2s |  |
| 464 | `flash_media_video_rotation_probe` | 27 | 7.3s |  |
| 465 | `flash_media_video_setter` | 40 | 7.8s |  |
| 466 | `flash_trace` | 17 | 7.4s |  |
| 467 | `flash_ui_mouse_cursor` | 35 | 7.7s |  |
| 468 | `flash_xml` | 29 | 7.4s |  |
| 469 | `flash_xml_cloneNode` | 22 | 7.3s |  |
| 470 | `flash_xml_namespace` | 109 | 7.3s |  |
| 471 | `flash_xml_removeNode` | 60 | 7.3s |  |
| 472 | `focus_events_code` | 161 | 27.0s |  |
| 473 | `focus_events_key_basic` | 132 | 27.0s |  |
| 474 | `focus_events_key_navigation` | 53 | 27.1s |  |
| 475 | `focus_events_key_same_object` | 26 | 7.4s |  |
| 476 | `focus_events_mixed_key_mouse` | 100 | 27.0s |  |
| 477 | `focus_events_mouse_basic` | 260 | 27.1s |  |
| 478 | `focus_events_mouse_focusable` | 112 | 27.6s |  |
| 479 | `focus_events_mouse_same_object` | 40 | 7.4s |  |
| 480 | `focus_remove` | 20 | 27.4s |  |
| 481 | `focus_root_movie` | 4 | 27.5s |  |
| 482 | `focus_stage` | 1 | 7.4s |  |
| 483 | `focusrect` | 18 | 8.2s |  |
| 484 | `focusrect_focuslost` | 9 | 7.4s |  |
| 485 | `focusrect_property` | 110 | 2.3s |  |
| 486 | `font_description_clone` | 14 | 7.3s |  |
| 487 | `font_embedded` | 24 | 8.2s |  |
| 488 | `font_enumeratefonts` | 41 | 8.3s |  |
| 489 | `font_enumeratefonts_filter` | 4 | 28.8s |  |
| 490 | `font_enumeratefonts_order` | 9 | 9.2s |  |
| 491 | `font_hasglyphs` | 40 | 8.1s |  |
| 492 | `font_registerfont` | 129 | 8.7s |  |
| 493 | `framelabel_constr` | 5 | 7.8s |  |
| 494 | `function_call` | 12 | 2.6s |  |
| 495 | `function_call_arguments` | 46 | 2.7s |  |
| 496 | `function_call_arguments_enumerate` | 5 | 7.5s |  |
| 497 | `function_call_coercion` | 108 | 8.0s |  |
| 498 | `function_call_default` | 6 | 7.6s |  |
| 499 | `function_call_rest` | 22 | 7.6s |  |
| 500 | `function_call_types` | 3 | 7.6s |  |
| 501 | `function_call_via_apply` | 11 | 7.6s |  |
| 502 | `function_call_via_call` | 3 | 7.6s |  |
| 503 | `function_display_anonymous` | 7 | 2.6s |  |
| 504 | `function_length` | 6 | 7.6s |  |
| 505 | `function_object` | 2 | 7.6s |  |
| 506 | `function_proto` | 5 | 7.6s |  |
| 507 | `function_proto_created` | 61 | 7.7s |  |
| 508 | `function_to_locale_string` | 4 | 7.6s |  |
| 509 | `function_to_string` | 4 | 7.6s |  |
| 510 | `function_type` | 6 | 7.6s |  |
| 511 | `function_unbound_this` | 51 | 7.8s |  |
| 512 | `function_value_of` | 4 | 7.6s |  |
| 513 | `game_input` | 4 | 7.6s |  |
| 514 | `generate_random_bytes` | 3 | 7.7s |  |
| 515 | `get_definition_by_name` | 11 | 7.6s |  |
| 516 | `get_qualified_class_name` | 20 | 7.7s |  |
| 517 | `get_qualified_super_class_name` | 18 | 7.7s |  |
| 518 | `get_slot_edge_cases` | 1 | 7.6s |  |
| 519 | `get_timer` | 2 | 2.6s |  |
| 520 | `getglobalslot` | 1 | 7.6s |  |
| 521 | `getouterscope` | 8 | 7.6s |  |
| 522 | `getouterscope_two_classobjects` | 13 | 7.6s |  |
| 523 | `getter_different_namespace_setter` | 2 | 7.4s |  |
| 524 | `glow_filter` | 127 | 7.8s |  |
| 525 | `goto_button_nested_framescript` | 28 | 28.5s |  |
| 526 | `goto_in_constructframe` | 12 | 27.1s |  |
| 527 | `goto_in_scene_last_frame` | 2 | 26.7s |  |
| 528 | `goto_methods` | 56 | 26.6s |  |
| 529 | `goto_methods_swfver10` | 8 | 7.0s |  |
| 530 | `goto_nested_construct_sibling` | 18 | 7.5s |  |
| 531 | `goto_nested_framescript` | 9 | 7.1s |  |
| 532 | `goto_on_orphan` | 15 | 26.3s |  |
| 533 | `gradient_bevel_filter` | 206 | 7.1s |  |
| 534 | `gradient_glow_filter` | 206 | 6.8s |  |
| 535 | `graphic_linkage` | 9 | 7.1s |  |
| 536 | `graphics_bad_direct_commands` | 5 | 7.3s |  |
| 537 | `graphics_bitmap_fill` | 0 | 28.0s |  |
| 538 | `graphics_bitmaps` | 0 | 7.3s |  |
| 539 | `graphics_direct_commands` | 0 | 7.2s |  |
| 540 | `graphics_draw_triangles` | 98 | 27.5s |  |
| 541 | `graphics_gradients` | 0 | 7.2s |  |
| 542 | `graphics_gradients_nulls` | 0 | 7.0s |  |
| 543 | `graphics_path` | 56 | 7.1s |  |
| 544 | `graphics_round_rects` | 0 | 7.0s |  |
| 545 | `graphics_simple_shapes` | 0 | 7.0s |  |
| 546 | `greaterequals` | 512 | 10.0s |  |
| 547 | `greaterthan` | 512 | 10.1s |  |
| 548 | `has_own_property` | 102 | 7.4s |  |
| 549 | `hasownproperty_namespaces` | 2 | 6.9s |  |
| 550 | `hello_world` | 1 | 6.9s |  |
| 551 | `hittest_morph` | 30 | 7.1s |  |
| 552 | `if_eq` | 10 | 7.0s |  |
| 553 | `if_gt` | 1 | 7.0s |  |
| 554 | `if_gte` | 10 | 2.1s |  |
| 555 | `if_lt` | 1 | 0.5s |  |
| 556 | `if_lte` | 10 | 6.8s |  |
| 557 | `if_ne` | 7 | 2.1s |  |
| 558 | `if_stricteq` | 6 | 7.0s |  |
| 559 | `if_strictne` | 11 | 7.0s |  |
| 560 | `ime_linux_dead_keys` | 10 | 6.9s |  |
| 561 | `in` | 102 | 7.3s |  |
| 562 | `inclocal` | 46 | 7.0s |  |
| 563 | `inclocal_i` | 46 | 7.0s |  |
| 564 | `increment` | 46 | 7.0s |  |
| 565 | `increment_i` | 46 | 7.2s |  |
| 566 | `indexing_delete` | 75 | 11.0s |  |
| 567 | `indexof_xml` | 10 | 9.6s |  |
| 568 | `init_callee_cached` | 24 | 7.0s |  |
| 569 | `instanceof` | 58 | 7.3s |  |
| 570 | `instantiate_root_character` | 4 | 7.3s |  |
| 571 | `instantiation_on_enter_frame` | 7 | 27.2s |  |
| 572 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.2s |  |
| 573 | `int_constr` | 92 | 7.4s |  |
| 574 | `int_edge_cases` | 19 | 27.4s |  |
| 575 | `int_instanceof` | 3 | 7.1s |  |
| 576 | `int_tofixed` | 1215 | 7.1s |  |
| 577 | `int_toprecision` | 1125 | 7.3s |  |
| 578 | `int_tostring` | 3375 | 7.3s |  |
| 579 | `interactiveobject_enabled` | 25 | 2.1s |  |
| 580 | `interface_namespaces` | 78 | 7.2s |  |
| 581 | `invalid_utf8` | 12 | 7.2s |  |
| 582 | `is_finite` | 46 | 7.2s |  |
| 583 | `is_nan` | 46 | 7.1s |  |
| 584 | `is_prototype_of` | 12 | 7.2s |  |
| 585 | `issue_10221` | 2 | 7.1s |  |
| 586 | `issue_13780` | 12 | 7.1s |  |
| 587 | `issue_14901` | 1 | 7.1s |  |
| 588 | `issue_17675_edittext_paste_maxchars` | 1 | 7.1s |  |
| 589 | `issue_5292` | 5 | 7.2s |  |
| 590 | `issue_8630` | 2 | 7.2s |  |
| 591 | `issue_8630_placeremoveplace` | 15 | 7.3s |  |
| 592 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.1s |  |
| 593 | `issue_8630_scriptremove` | 11 | 7.2s |  |
| 594 | `istype` | 24 | 2.3s |  |
| 595 | `istypelate` | 58 | 7.4s |  |
| 596 | `istypelate_coerce` | 198 | 8.0s |  |
| 597 | `jpeg_loader_context` | 6 | 7.1s |  |
| 598 | `json_errors` | 9 | 27.4s |  |
| 599 | `json_parse` | 21 | 7.2s |  |
| 600 | `json_stringify` | 12 | 7.3s |  |
| 601 | `json_stringify_function` | 12 | 7.0s |  |
| 602 | `json_stringify_order` | 1 | 2.2s |  |
| 603 | `json_version_gated` | 1 | 7.0s |  |
| 604 | `key_input_80percent` | 1812 | 22.7s |  |
| 605 | `key_input_location` | 126 | 6.2s |  |
| 606 | `key_input_numpad` | 384 | 6.1s |  |
| 607 | `large_preload_from_bytes` | 51 | 25.3s |  |
| 608 | `large_preload_from_url` | 27 | 7.9s |  |
| 609 | `large_preload_image_from_bytes` | 25 | 6.5s |  |
| 610 | `lazyinit` | 17 | 6.0s |  |
| 611 | `lessequals` | 512 | 9.3s |  |
| 612 | `lessthan` | 512 | 9.7s |  |
| 613 | `loader_bitmap_transparency` | 14 | 6.3s |  |
| 614 | `loader_bytes_unknown_content` | 14 | 6.2s |  |
| 615 | `loader_child_getdefinition` | 5 | 6.6s |  |
| 616 | `loader_duplicate_class` | 48 | 7.7s |  |
| 617 | `loader_duplicate_coerce` | 3 | 6.4s |  |
| 618 | `loader_duplicate_coerce_new_domain` | 4 | 6.2s |  |
| 619 | `loader_error_in_root_ctor` | 4 | 6.3s |  |
| 620 | `loader_events` | 92 | 6.7s |  |
| 621 | `loader_image` | 8 | 6.3s |  |
| 622 | `loader_jpegxr` | 2 | 22.3s |  |
| 623 | `loader_jpegxr_alpha` | 1 | 22.1s |  |
| 624 | `loader_loadbytes_events` | 30 | 6.2s |  |
| 625 | `loader_loadbytes_invalid_png` | 4 | 5.9s |  |
| 626 | `loader_loadbytes_url` | 12 | 6.1s |  |
| 627 | `loader_loaderurl` | 6 | 6.3s |  |
| 628 | `loader_method` | 85 | 5.8s |  |
| 629 | `loader_noninteractive_try_click_root` | 5 | 21.5s |  |
| 630 | `loader_reuse` | 38 | 5.9s |  |
| 631 | `loader_try_click_root` | 16 | 5.9s |  |
| 632 | `loader_unknown_content` | 24 | 6.0s |  |
| 633 | `loader_visibility_interactive` | 1 | 5.8s |  |
| 634 | `loaderinfo_events` | 7 | 5.8s |  |
| 635 | `loaderinfo_loadurl` | 12 | 5.7s |  |
| 636 | `loaderinfo_more` | 6 | 5.9s |  |
| 637 | `loaderinfo_properties` | 18 | 21.5s |  |
| 638 | `loaderinfo_properties_not_loaded` | 23 | 5.9s |  |
| 639 | `loaderinfo_quine` | 1005 | 5.8s |  |
| 640 | `loaderinfo_root` | 10 | 6.0s |  |
| 641 | `loaderinfo_root_allows` | 2 | 5.9s |  |
| 642 | `localconnection` | 890 | 7.3s |  |
| 643 | `localconnection_send` | 4 | 27.7s |  |
| 644 | `lshift` | 1058 | 19.0s |  |
| 645 | `mask_reapply` | 1 | 27.9s |  |
| 646 | `math` | 497 | 7.9s |  |
| 647 | `matrix` | 338 | 17.9s |  |
| 648 | `matrix3d` | 57 | 28.6s |  |
| 649 | `matrix3d_append` | 16 | 7.7s |  |
| 650 | `matrix3d_append_prepend_scale` | 86 | 7.7s |  |
| 651 | `matrix3d_append_prepend_translation` | 42 | 7.7s |  |
| 652 | `matrix3d_compose` | 34 | 7.9s |  |
| 653 | `matrix3d_constructor_clone` | 15 | 7.6s |  |
| 654 | `matrix3d_copy_column` | 83 | 7.9s |  |
| 655 | `matrix3d_copy_from` | 19 | 7.6s |  |
| 656 | `matrix3d_copy_raw_data_from` | 55 | 2.8s |  |
| 657 | `matrix3d_copy_raw_data_to` | 38 | 7.9s |  |
| 658 | `matrix3d_copy_row` | 83 | 7.5s |  |
| 659 | `matrix3d_copy_to_matrix3d` | 19 | 7.6s |  |
| 660 | `matrix3d_determinant` | 182 | 7.8s |  |
| 661 | `matrix3d_interpolate` | 21 | 7.8s |  |
| 662 | `matrix3d_invert` | 18 | 7.6s |  |
| 663 | `matrix3d_position` | 19 | 7.7s |  |
| 664 | `matrix3d_precision` | 28 | 7.7s |  |
| 665 | `matrix3d_prepend` | 16 | 7.5s |  |
| 666 | `matrix3d_raw_data` | 33 | 7.7s |  |
| 667 | `matrix3d_transform_vector` | 52 | 8.0s |  |
| 668 | `matrix3d_transpose` | 5 | 7.6s |  |
| 669 | `method_association` | 5 | 7.6s |  |
| 670 | `method_without_body` | 3 | 27.8s |  |
| 671 | `missing_external_interface` | 10 | 7.6s |  |
| 672 | `modulo` | 1058 | 19.2s |  |
| 673 | `morph_shape` | 2 | 28.1s |  |
| 674 | `mouse_children` | 192 | 28.1s |  |
| 675 | `mouse_click_events` | 90 | 28.0s |  |
| 676 | `mouse_double_click_events` | 188 | 7.7s |  |
| 677 | `mouse_empty_parent` | 4 | 7.6s |  |
| 678 | `mouse_over_while_dragging` | 3 | 7.8s |  |
| 679 | `mouse_pick_avm1_root` | 2 | 28.1s |  |
| 680 | `mouse_pick_button_mode` | 2 | 2.7s |  |
| 681 | `mouse_pick_dobj_mask` | 4 | 7.7s |  |
| 682 | `mouse_pick_masking` | 7 | 27.4s |  |
| 683 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 28.1s |  |
| 684 | `mouse_pick_non_interactive_dobj_mask` | 3 | 27.9s |  |
| 685 | `mouse_pick_text` | 8 | 7.9s |  |
| 686 | `mouse_sibling` | 8 | 8.0s |  |
| 687 | `mouse_wheel_events` | 36 | 28.5s |  |
| 688 | `mouseevent_constr` | 66 | 7.5s |  |
| 689 | `mouseevent_stagexy` | 35 | 7.5s |  |
| 690 | `mouseevent_valueof_tostring` | 28 | 7.6s |  |
| 691 | `movieclip_addframescript` | 3 | 28.2s |  |
| 692 | `movieclip_addframescript_error` | 9 | 7.6s |  |
| 693 | `movieclip_child_property` | 16 | 7.8s |  |
| 694 | `movieclip_constr` | 21 | 7.8s |  |
| 695 | `movieclip_currentlabels` | 17 | 27.6s |  |
| 696 | `movieclip_currentlabels_dupes1` | 46 | 27.4s |  |
| 697 | `movieclip_currentlabels_dupes2` | 30 | 7.7s |  |
| 698 | `movieclip_currentlabels_dupes3` | 67 | 7.6s |  |
| 699 | `movieclip_currentscene` | 12 | 27.8s |  |
| 700 | `movieclip_dispatchevent` | 430 | 7.9s |  |
| 701 | `movieclip_dispatchevent_cancel` | 102 | 7.8s |  |
| 702 | `movieclip_dispatchevent_handlerorder` | 251 | 7.7s |  |
| 703 | `movieclip_dispatchevent_selfadd` | 80 | 7.5s |  |
| 704 | `movieclip_dispatchevent_target` | 899 | 7.5s |  |
| 705 | `movieclip_displayevents` | 96 | 27.2s |  |
| 706 | `movieclip_displayevents_clickgoto` | 676 | 27.1s |  |
| 707 | `movieclip_displayevents_clickgoto2` | 2001 | 7.9s |  |
| 708 | `movieclip_displayevents_clickplay` | 575 | 7.5s |  |
| 709 | `movieclip_displayevents_clicksymbol` | 562 | 7.6s |  |
| 710 | `movieclip_displayevents_constructframegoto` | 140 | 7.8s |  |
| 711 | `movieclip_displayevents_constructframeplay` | 50 | 7.7s |  |
| 712 | `movieclip_displayevents_constructframesymbol` | 144 | 7.6s |  |
| 713 | `movieclip_displayevents_dblhandler` | 21 | 7.7s |  |
| 714 | `movieclip_displayevents_enterframegoto` | 149 | 7.5s |  |
| 715 | `movieclip_displayevents_enterframeplay` | 48 | 7.5s |  |
| 716 | `movieclip_displayevents_enterframesymbol` | 149 | 27.0s |  |
| 717 | `movieclip_displayevents_exitframegoto` | 106 | 7.5s |  |
| 718 | `movieclip_displayevents_exitframeplay` | 44 | 7.5s |  |
| 719 | `movieclip_displayevents_exitframesymbol` | 135 | 7.6s |  |
| 720 | `movieclip_displayevents_looping` | 63 | 27.0s |  |
| 721 | `movieclip_displayevents_stopped` | 113 | 7.7s |  |
| 722 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 723 | `movieclip_displayevents_timeline` | 128 | 7.7s |  |
| 724 | `movieclip_drawrect` | 54 | 21.7s |  |
| 725 | `movieclip_frameconstruct_skipped` | 9 | 6.1s |  |
| 726 | `movieclip_goto_during_frame_script` | 15 | 22.3s |  |
| 727 | `movieclip_goto_overwrite` | 14 | 22.1s |  |
| 728 | `movieclip_goto_scene_last_frame_int` | 1 | 21.9s |  |
| 729 | `movieclip_goto_scene_last_frame_label` | 1 | 5.9s |  |
| 730 | `movieclip_gotoandplay` | 15 | 22.3s |  |
| 731 | `movieclip_gotoandstop` | 13 | 6.1s |  |
| 732 | `movieclip_gotoandstop_children` | 4 | 6.2s |  |
| 733 | `movieclip_gotoandstop_framescripts1` | 4 | 6.0s |  |
| 734 | `movieclip_gotoandstop_framescripts2` | 4 | 2.1s |  |
| 735 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.4s |  |
| 736 | `movieclip_gotoandstop_queueing` | 12 | 22.4s |  |
| 737 | `movieclip_hittest` | 67 | 6.1s |  |
| 738 | `movieclip_next_frame` | 2 | 5.9s |  |
| 739 | `movieclip_next_scene` | 6 | 21.8s |  |
| 740 | `movieclip_play` | 3 | 5.8s |  |
| 741 | `movieclip_prev_frame` | 3 | 6.1s |  |
| 742 | `movieclip_prev_scene` | 7 | 5.9s |  |
| 743 | `movieclip_properties` | 79 | 22.1s |  |
| 744 | `movieclip_queued_noop_goto_swf10` | 9 | 6.0s |  |
| 745 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 746 | `movieclip_scenes` | 11 | 5.9s |  |
| 747 | `movieclip_soundtransform` | 831 | 23.1s |  |
| 748 | `movieclip_stop` | 1 | 5.8s |  |
| 749 | `movieclip_super_is_symbol` | 20 | 6.1s |  |
| 750 | `movieclip_symbol_constr` | 8 | 5.9s |  |
| 751 | `movieclip_text_mousedown` | 1 | 5.9s |  |
| 752 | `movieclip_willtrigger` | 5 | 5.9s |  |
| 753 | `multiply` | 1058 | 14.9s |  |
| 754 | `namespace_constr` | 253 | 6.2s |  |
| 755 | `namespace_constr_args` | 1 | 5.7s |  |
| 756 | `namespace_enumeration_order` | 7 | 21.5s |  |
| 757 | `nan_scale` | 9 | 5.8s |  |
| 758 | `native_menu_basic` | 19 | 7.6s |  |
| 759 | `navigateToURL_target_normalize` | 107 | 23.0s |  |
| 760 | `negate` | 30 | 5.8s |  |
| 761 | `negative_volume_panned` | 0 | 6.0s |  |
| 762 | `nested_iteration` | 11 | 6.3s |  |
| 763 | `net_getClassByAlias` | 3 | 5.8s |  |
| 764 | `net_navigateToURL` | 57 | 5.8s |  |
| 765 | `net_stream_play_options` | 6 | 5.8s |  |
| 766 | `netconnection_close` | 55 | 21.1s |  |
| 767 | `netconnection_properties` | 78 | 5.3s |  |
| 768 | `netconnection_send_remote` | 50 | 23.1s |  |
| 769 | `netconnection_serialize_arrays` | 6 | 5.5s |  |
| 770 | `netfilterevent` | 10 | 20.8s |  |
| 771 | `netstream_client` | 10 | 5.5s |  |
| 772 | `netstream_connect` | 7 | 5.3s |  |
| 773 | `netstream_flv_date` | 4 | 5.6s |  |
| 774 | `newactivation_in_script_init` | 3 | 5.4s |  |
| 775 | `newclass_mismatched` | 4 | 1.7s |  |
| 776 | `newclass_twice` | 3 | 5.3s |  |
| 777 | `nonconflicting_declarations` | 0 | 5.7s |  |
| 778 | `null_void_types` | 8 | 5.9s |  |
| 779 | `number_autoconv` | 21 | 5.3s |  |
| 780 | `number_autoconv_amf` | 132 | 5.5s |  |
| 781 | `number_autoconv_array_sort_32bit` | 1 | 5.7s |  |
| 782 | `number_constr` | 58 | 5.6s |  |
| 783 | `number_convert_edge_cases` | 180 | 20.5s |  |
| 784 | `number_toexponential` | 378 | 5.3s |  |
| 785 | `number_toexponential2` | 35 | 5.5s |  |
| 786 | `number_tofixed` | 378 | 5.2s |  |
| 787 | `number_toprecision` | 350 | 5.2s |  |
| 788 | `obfuscated_class_names` | 3 | 5.4s |  |
| 789 | `object_enumeration` | 10 | 1.8s |  |
| 790 | `object_prototype` | 4 | 5.3s |  |
| 791 | `object_to_locale_string` | 2 | 5.9s |  |
| 792 | `object_to_string` | 2 | 5.1s |  |
| 793 | `object_value_of` | 2 | 1.5s |  |
| 794 | `op_coerce` | 54 | 1.6s |  |
| 795 | `op_coerce_x` | 54 | 5.3s |  |
| 796 | `op_escxattr` | 2 | 5.5s |  |
| 797 | `op_escxelem` | 2 | 5.2s |  |
| 798 | `op_lookupswitch` | 4 | 5.3s |  |
| 799 | `optimize_coerce` | 1 | 5.3s |  |
| 800 | `orphan_movie_complex` | 80 | 5.5s |  |
| 801 | `orphan_movie_reorder` | 111 | 20.6s |  |
| 802 | `orphan_removeobject` | 636 | 27.0s |  |
| 803 | `package_namespace` | 7 | 26.2s |  |
| 804 | `param_default_value_has_zero_cpool_index` | 1 | 26.2s |  |
| 805 | `parent_early_access_child` | 16 | 26.7s |  |
| 806 | `parse_float` | 81 | 7.4s |  |
| 807 | `parse_float_swf10` | 81 | 7.1s |  |
| 808 | `parse_int` | 135 | 7.8s |  |
| 809 | `perspective_projection` | 1443 | 26.7s |  |
| 810 | `perspective_projection_basic` | 40 | 7.2s |  |
| 811 | `pixelbender_ceil` | 77 | 7.4s |  |
| 812 | `pixelbender_conditional` | 138 | 7.7s |  |
| 813 | `pixelbender_conversions` | 270 | 7.6s |  |
| 814 | `pixelbender_dithering` | 8 | 31.2s |  |
| 815 | `pixelbender_div` | 36 | 7.4s |  |
| 816 | `pixelbender_effect_BlurredFocus` | 0 | 34.5s |  |
| 817 | `pixelbender_effect_glassDisplace` | 0 | 12.8s |  |
| 818 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 29.6s |  |
| 819 | `pixelbender_effect_smudge` | 0 | 10.5s |  |
| 820 | `pixelbender_effect_tintype` | 0 | 9.7s |  |
| 821 | `pixelbender_effect_twirl` | 0 | 11.1s |  |
| 822 | `pixelbender_eof` | 7 | 7.3s |  |
| 823 | `pixelbender_images` | 0 | 9.4s |  |
| 824 | `pixelbender_input` | 103 | 27.1s |  |
| 825 | `pixelbender_logicalnot` | 20 | 7.2s |  |
| 826 | `pixelbender_malformed_data` | 190 | 27.2s |  |
| 827 | `pixelbender_multiple_out_params` | 1 | 7.2s |  |
| 828 | `pixelbender_no_out_param` | 6 | 7.2s |  |
| 829 | `pixelbender_outputs` | 13 | 7.5s |  |
| 830 | `pixelbender_padding_bytes` | 22 | 7.3s |  |
| 831 | `pixelbender_param_qualifier` | 512 | 7.4s |  |
| 832 | `pixelbender_parameters` | 1563 | 7.6s |  |
| 833 | `pixelbender_parameters_bool` | 240 | 7.5s |  |
| 834 | `pixelbender_parameters_int_vs_bool` | 54 | 7.3s |  |
| 835 | `pixelbender_parse_errors` | 6 | 7.2s |  |
| 836 | `pixelbender_rsqrt` | 24 | 7.3s |  |
| 837 | `pixelbender_select_kinds` | 8 | 7.4s |  |
| 838 | `pixelbender_shaderdata` | 49 | 7.3s |  |
| 839 | `pixelbender_shaderdata_setter` | 99 | 7.7s |  |
| 840 | `pixelbender_sign` | 60 | 7.4s |  |
| 841 | `pixelbender_vector_output` | 11 | 7.5s |  |
| 842 | `place_and_lookup/swf10` | 33 | 2.4s |  |
| 843 | `place_and_lookup/swf9` | 33 | 0.7s |  |
| 844 | `place_multiple` | 17 | 20.4s |  |
| 845 | `place_object_replace` | 9 | 19.1s |  |
| 846 | `place_object_replace_2` | 24 | 20.0s |  |
| 847 | `place_object_same_depth_frame` | 1 | 19.6s |  |
| 848 | `point` | 132 | 5.5s |  |
| 849 | `primitive_edge_cases` | 1 | 5.0s |  |
| 850 | `primitive_keys` | 54 | 5.3s |  |
| 851 | `primitive_toString` | 277 | 5.6s |  |
| 852 | `primitive_valueOf` | 285 | 5.4s |  |
| 853 | `print_job_options` | 3 | 6.1s |  |
| 854 | `property_is_enumerable` | 114 | 5.9s |  |
| 855 | `property_is_enumerable_reset` | 23 | 6.0s |  |
| 856 | `property_priority` | 22 | 5.9s |  |
| 857 | `property_priority_chained` | 4 | 5.4s |  |
| 858 | `property_priority_definition_names_order` | 2 | 5.4s |  |
| 859 | `property_priority_three_level` | 6 | 5.3s |  |
| 860 | `propertyisenumerable_namespaces` | 6 | 5.2s |  |
| 861 | `prototype_set_null` | 7 | 5.0s |  |
| 862 | `proxy_callproperty` | 24 | 5.0s |  |
| 863 | `proxy_deleteproperty` | 64 | 5.1s |  |
| 864 | `proxy_enumeration` | 34 | 5.1s |  |
| 865 | `proxy_getproperty` | 77 | 5.7s |  |
| 866 | `proxy_hasownproperty` | 8 | 5.2s |  |
| 867 | `proxy_hasproperty` | 32 | 5.1s |  |
| 868 | `proxy_not_overridden` | 54 | 5.3s |  |
| 869 | `proxy_serialize` | 9 | 5.2s |  |
| 870 | `proxy_setproperty` | 42 | 5.3s |  |
| 871 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.5s |  |
| 872 | `qname_constr` | 32 | 5.2s |  |
| 873 | `qname_constr_namespace` | 24 | 5.0s |  |
| 874 | `qname_enumeration` | 9 | 4.9s |  |
| 875 | `qname_indexing` | 23 | 5.1s |  |
| 876 | `qname_tostring` | 25 | 5.0s |  |
| 877 | `qname_valueof` | 29 | 5.2s |  |
| 878 | `rectangle` | 1094 | 5.7s |  |
| 879 | `regexp_constr` | 148 | 5.2s |  |
| 880 | `regexp_exec` | 19 | 4.9s |  |
| 881 | `regexp_extended` | 47 | 5.3s |  |
| 882 | `regexp_multiargs` | 1 | 4.9s |  |
| 883 | `regexp_test` | 27 | 5.1s |  |
| 884 | `regexp_toString` | 10 | 5.3s |  |
| 885 | `register_script_refresh` | 35 | 19.7s |  |
| 886 | `remove_child_clear_field` | 88 | 27.6s |  |
| 887 | `remove_dobj` | 3 | 26.8s |  |
| 888 | `resolve_order` | 4 | 7.2s |  |
| 889 | `responder_null_callbacks` | 1 | 27.2s |  |
| 890 | `rng` | 1 | 8.6s |  |
| 891 | `rootless` | 42 | 7.3s |  |
| 892 | `rshift` | 1058 | 19.4s |  |
| 893 | `rtqname_not_namespace` | 12 | 7.2s |  |
| 894 | `sandbox_type_inherited` | 2 | 7.7s |  |
| 895 | `sandbox_type_local_file` | 1 | 7.2s |  |
| 896 | `sandbox_type_local_network` | 1 | 7.0s |  |
| 897 | `scene_constr` | 8 | 7.4s |  |
| 898 | `scope_optimizations` | 4 | 7.2s |  |
| 899 | `scopes_dont_cache/order-1` | 1 | 26.9s |  |
| 900 | `scopes_dont_cache/order-2` | 1 | 0.4s |  |
| 901 | `security_domain_current` | 2 | 7.3s |  |
| 902 | `selection` | 239 | 7.8s |  |
| 903 | `set_local_0` | 31 | 7.5s |  |
| 904 | `set_property_is_enumerable` | 85 | 7.9s |  |
| 905 | `shaderparameter_value` | 4 | 7.3s |  |
| 906 | `shape_drawrect` | 54 | 7.5s |  |
| 907 | `shared_object_no_root` | 3 | 7.3s |  |
| 908 | `simplebutton_added_to_stage` | 45 | 27.8s |  |
| 909 | `simplebutton_childevents` | 86 | 27.8s |  |
| 910 | `simplebutton_childevents_nested` | 54 | 7.7s |  |
| 911 | `simplebutton_childevents_sprite` | 13 | 7.5s |  |
| 912 | `simplebutton_childprops` | 144 | 7.7s |  |
| 913 | `simplebutton_childshuffle` | 23 | 7.5s |  |
| 914 | `simplebutton_constr` | 36 | 7.9s |  |
| 915 | `simplebutton_constr_childevents` | 48 | 7.8s |  |
| 916 | `simplebutton_constr_params` | 42 | 7.5s |  |
| 917 | `simplebutton_mouseenabled` | 26 | 7.4s |  |
| 918 | `simplebutton_multi_children` | 19 | 7.6s |  |
| 919 | `simplebutton_soundtransform` | 887 | 29.2s |  |
| 920 | `simplebutton_structure` | 27 | 7.5s |  |
| 921 | `simplebutton_symbolclass` | 68 | 7.8s |  |
| 922 | `slot_disp_id_shared_numbering` | 1 | 26.9s |  |
| 923 | `slots_force_autoassigned` | 1 | 26.8s |  |
| 924 | `socket_after_disconnect` | 1 | 7.2s |  |
| 925 | `socket_close` | 2 | 7.2s |  |
| 926 | `socket_connect` | 4 | 7.2s |  |
| 927 | `socket_errors` | 56 | 7.8s |  |
| 928 | `socket_read_big` | 48 | 7.3s |  |
| 929 | `socket_read_little` | 48 | 2.4s |  |
| 930 | `socket_read_write_object` | 8 | 7.3s |  |
| 931 | `socket_write_big` | 15 | 7.7s |  |
| 932 | `socket_write_little` | 14 | 7.3s |  |
| 933 | `sound_constructor_with_args` | 6 | 7.5s |  |
| 934 | `sound_embeddedprops` | 26 | 7.5s |  |
| 935 | `sound_play` | 19 | 7.5s |  |
| 936 | `sound_rootless` | 7 | 7.2s |  |
| 937 | `sound_valueof` | 33 | 7.4s |  |
| 938 | `soundchannel_soundtransform` | 835 | 29.0s |  |
| 939 | `soundchannel_soundtransform_exists` | 5 | 26.9s |  |
| 940 | `soundchannel_stop` | 8 | 27.2s |  |
| 941 | `soundmixer_buffertime` | 5 | 7.3s |  |
| 942 | `soundmixer_soundtransform` | 900 | 9.3s |  |
| 943 | `soundmixer_stopall` | 6 | 27.1s |  |
| 944 | `soundtransform` | 442 | 13.1s |  |
| 945 | `space_justifier_clone` | 12 | 7.3s |  |
| 946 | `sprite_with_frames` | 0 | 27.3s |  |
| 947 | `stage3d_agal_cross_product` | 0 | 9.8s |  |
| 948 | `stage3d_agal_upload_errors` | 66 | 10.0s |  |
| 949 | `stage3d_bitmap` | 0 | 31.9s |  |
| 950 | `stage3d_blend` | 81 | 29.5s |  |
| 951 | `stage3d_context3d_string_args` | 158 | 8.3s |  |
| 952 | `stage3d_errors` | 7 | 7.4s |  |
| 953 | `stage3d_errors_atf` | 3 | 8.7s |  |
| 954 | `stage3d_errors_swf_29` | 6 | 7.5s |  |
| 955 | `stage3d_float1_index` | 0 | 29.6s |  |
| 956 | `stage3d_fractal` | 0 | 29.4s |  |
| 957 | `stage3d_ignore_sampler_override` | 0 | 29.6s |  |
| 958 | `stage3d_multistage_triangle` | 3 | 9.9s |  |
| 959 | `stage3d_program_constants_bytearray_be` | 0 | 31.7s |  |
| 960 | `stage3d_program_constants_bytearray_le` | 0 | 31.7s |  |
| 961 | `stage3d_program_constants_invalid_input` | 21 | 28.0s |  |
| 962 | `stage3d_raytrace` | 0 | 53.3s |  |
| 963 | `stage3d_rotating_cube` | 0 | 10.5s |  |
| 964 | `stage3d_sampler` | 0 | 9.8s |  |
| 965 | `stage3d_sampler_partial_upload` | 0 | 9.8s |  |
| 966 | `stage3d_stencil` | 0 | 29.2s |  |
| 967 | `stage3d_texture` | 0 | 15.0s |  |
| 968 | `stage3d_texture_bytearray` | 0 | 11.1s |  |
| 969 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.5s |  |
| 970 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.8s |  |
| 971 | `stage3d_triangle` | 0 | 10.0s |  |
| 972 | `stage3d_triangle_bytes4` | 0 | 9.9s |  |
| 973 | `stage3d_triangle_float1` | 0 | 10.1s |  |
| 974 | `stage3d_triangle_index_upload` | 0 | 10.0s |  |
| 975 | `stage3d_x_y` | 22 | 7.5s |  |
| 976 | `stage_access` | 10 | 7.5s |  |
| 977 | `stage_display_state` | 6 | 7.5s |  |
| 978 | `stage_displayobject_properties` | 24 | 7.3s |  |
| 979 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.2s |  |
| 980 | `stage_framerate_nan` | 7 | 7.3s |  |
| 981 | `stage_framerate_negative` | 6 | 7.1s |  |
| 982 | `stage_framerate_zero` | 6 | 7.2s |  |
| 983 | `stage_invalidate` | 38 | 7.4s |  |
| 984 | `stage_loaderinfo_properties` | 24 | 26.4s |  |
| 985 | `stage_mousechildren` | 2 | 7.1s |  |
| 986 | `stage_mouseenabled` | 15 | 7.0s |  |
| 987 | `stage_overriden_setters` | 31 | 7.2s |  |
| 988 | `stage_properties` | 30 | 7.1s |  |
| 989 | `stage_properties2` | 213 | 7.2s |  |
| 990 | `stage_scale_factor` | 12 | 29.8s |  |
| 991 | `stage_stage3Ds_vector` | 1 | 7.0s |  |
| 992 | `static_length` | 24 | 7.2s |  |
| 993 | `static_text` | 3 | 7.3s |  |
| 994 | `static_var_with_this_in_ctor` | 2 | 7.1s |  |
| 995 | `statictext_text` | 8 | 7.2s |  |
| 996 | `stored_properties` | 11 | 2.4s |  |
| 997 | `strict_equality` | 34 | 7.1s |  |
| 998 | `string_call` | 13 | 7.1s |  |
| 999 | `string_case` | 23 | 7.2s |  |
| 1000 | `string_char_at` | 27 | 7.2s |  |
| 1001 | `string_char_code_at` | 28 | 2.3s |  |
| 1002 | `string_concat_fromcharcode` | 37 | 27.7s |  |
| 1003 | `string_constr` | 25 | 27.7s |  |
| 1004 | `string_indexof_lastindexof` | 87 | 7.7s |  |
| 1005 | `string_length` | 16 | 7.4s |  |
| 1006 | `string_locale_compare` | 39 | 7.8s |  |
| 1007 | `string_match` | 51 | 7.7s |  |
| 1008 | `string_relational_compare` | 4 | 7.6s |  |
| 1009 | `string_replace` | 51 | 7.7s |  |
| 1010 | `string_search` | 41 | 7.5s |  |
| 1011 | `string_slice_substr_substring` | 170 | 8.5s |  |
| 1012 | `string_split` | 29 | 7.5s |  |
| 1013 | `string_substr_negative` | 21 | 7.3s |  |
| 1014 | `string_substr_weird` | 182 | 7.3s |  |
| 1015 | `stylesheet` | 221 | 7.9s |  |
| 1016 | `stylesheet_parse_color` | 69 | 7.3s |  |
| 1017 | `stylesheet_transform` | 307 | 7.6s |  |
| 1018 | `sub_super_same_field` | 12 | 2.4s |  |
| 1019 | `subclass_superclass_linked_symbol` | 4 | 7.7s |  |
| 1020 | `subtract` | 1058 | 19.4s |  |
| 1021 | `super_get_call` | 12 | 7.2s |  |
| 1022 | `supercall_two_classobjects` | 2 | 7.2s |  |
| 1023 | `supercalls_coerce` | 8 | 2.5s |  |
| 1024 | `supercalls_weird` | 2 | 7.2s |  |
| 1025 | `superinterface_call` | 20 | 7.3s |  |
| 1026 | `superinterface_instanceof` | 18 | 7.4s |  |
| 1027 | `swf8` | 1 | 7.3s |  |
| 1028 | `swf_10_queued_goto_scripts_construct` | 52 | 26.2s |  |
| 1029 | `swf_9_goto_in_enter_frame` | 17 | 7.2s |  |
| 1030 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.2s |  |
| 1031 | `swf_9_queued_goto_scripts` | 6 | 26.1s |  |
| 1032 | `swf_9_queued_goto_scripts_construct` | 28 | 0.7s |  |
| 1033 | `swf_9_versioning` | 2 | 7.1s |  |
| 1034 | `swf_wrong_frame_count` | 38 | 7.5s |  |
| 1035 | `swf_wrong_frame_count_isplaying` | 22 | 7.2s |  |
| 1036 | `symbol_class_binary_data` | 8 | 7.1s |  |
| 1037 | `symbol_class_conflict` | 4 | 7.3s |  |
| 1038 | `symbol_class_root_not_zero` | 1 | 7.1s |  |
| 1039 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 1040 | `system_exit` | 3 | 2.3s |  |
| 1041 | `system_setclipboard_null` | 1 | 7.1s |  |
| 1042 | `tab_ordering_arrows` | 998 | 23.2s |  |
| 1043 | `tab_ordering_automatic_advanced` | 184 | 1.5s |  |
| 1044 | `tab_ordering_automatic_basic` | 45 | 22.2s |  |
| 1045 | `tab_ordering_children` | 116 | 5.8s |  |
| 1046 | `tab_ordering_custom_basic` | 34 | 5.6s |  |
| 1047 | `tab_ordering_stage_tab_children` | 32 | 5.7s |  |
| 1048 | `tab_ordering_stage_tab_children_remove_root` | 5 | 5.6s |  |
| 1049 | `tab_ordering_tabbable` | 47 | 5.6s |  |
| 1050 | `tabstop_properties` | 105 | 22.2s |  |
| 1051 | `text_element_basic` | 34 | 5.7s |  |
| 1052 | `text_engine_fontdescription` | 27 | 5.8s |  |
| 1053 | `text_engine_groupelement` | 64 | 5.6s |  |
| 1054 | `text_run` | 7 | 5.6s |  |
| 1055 | `textblock_createline_errors` | 23 | 5.6s |  |
| 1056 | `textblock_createline_fte` | 9 | 22.2s |  |
| 1057 | `textblock_properties` | 118 | 6.0s |  |
| 1058 | `textbox_click` | 37 | 22.3s |  |
| 1059 | `textfield_event` | 66 | 5.8s |  |
| 1060 | `textfield_focusin_event` | 9 | 5.6s |  |
| 1061 | `textfield_input_dead_keys_windows` | 15 | 5.6s |  |
| 1062 | `textfield_input_events` | 25 | 14.8s |  |
| 1063 | `textfield_unload` | 39 | 18.3s |  |
| 1064 | `textformat` | 1134 | 5.5s |  |
| 1065 | `textformat_display` | 14 | 5.6s |  |
| 1066 | `textformat_font_max_length` | 4 | 5.6s |  |
| 1067 | `textline_inapplicable_properties` | 10 | 5.5s |  |
| 1068 | `textline_name` | 1 | 5.6s |  |
| 1069 | `textline_raw_text_length` | 30 | 5.6s |  |
| 1070 | `textline_splitting_basic` | 76 | 5.6s |  |
| 1071 | `textline_throwerror` | 30 | 5.5s |  |
| 1072 | `textline_validity` | 162 | 5.6s |  |
| 1073 | `throw` | 3 | 5.5s |  |
| 1074 | `timeline_scripts` | 3 | 22.1s |  |
| 1075 | `timer` | 90 | 5.7s |  |
| 1076 | `timer_events` | 3 | 5.6s |  |
| 1077 | `timer_finished` | 11 | 1.6s |  |
| 1078 | `timer_invalid_delay` | 30 | 5.6s |  |
| 1079 | `timer_reset` | 8 | 27.9s |  |
| 1080 | `timer_setdelay` | 5 | 27.8s |  |
| 1081 | `trace` | 12 | 7.6s |  |
| 1082 | `truthiness` | 30 | 7.6s |  |
| 1083 | `try_catch` | 11 | 7.7s |  |
| 1084 | `try_catch_typed` | 12 | 7.6s |  |
| 1085 | `typeof` | 30 | 7.7s |  |
| 1086 | `uint_constr` | 92 | 7.8s |  |
| 1087 | `uint_tofixed` | 1215 | 7.5s |  |
| 1088 | `uint_toprecision` | 1125 | 7.9s |  |
| 1089 | `uint_tostring` | 3375 | 7.9s |  |
| 1090 | `uncaught_error_basic` | 2 | 7.5s |  |
| 1091 | `unchecked_function` | 15 | 7.5s |  |
| 1092 | `unescape` | 28 | 7.6s |  |
| 1093 | `url_loader` | 25 | 7.8s |  |
| 1094 | `url_vars` | 27 | 7.8s |  |
| 1095 | `urlrequest` | 18 | 7.6s |  |
| 1096 | `urlstream_basic` | 5 | 7.7s |  |
| 1097 | `urshift` | 1058 | 19.2s |  |
| 1098 | `utils3d` | 7 | 2.5s |  |
| 1099 | `vector3d` | 397 | 11.9s |  |
| 1100 | `vector3d_near_equals` | 80 | 7.7s |  |
| 1101 | `vector_class` | 36 | 8.1s |  |
| 1102 | `vector_class_call` | 11 | 7.8s |  |
| 1103 | `vector_coercion` | 66 | 8.4s |  |
| 1104 | `vector_concat` | 90 | 8.1s |  |
| 1105 | `vector_constr` | 107 | 8.2s |  |
| 1106 | `vector_enumeration` | 5 | 7.5s |  |
| 1107 | `vector_every` | 92 | 8.4s |  |
| 1108 | `vector_filter` | 95 | 8.5s |  |
| 1109 | `vector_holes` | 24 | 7.7s |  |
| 1110 | `vector_indexof` | 302 | 12.0s |  |
| 1111 | `vector_insertat` | 270 | 8.6s |  |
| 1112 | `vector_int_access` | 4 | 7.6s |  |
| 1113 | `vector_int_delete` | 11 | 7.5s |  |
| 1114 | `vector_join` | 58 | 8.0s |  |
| 1115 | `vector_lastindexof` | 302 | 7.5s |  |
| 1116 | `vector_legacy` | 10 | 7.6s |  |
| 1117 | `vector_map` | 85 | 8.3s |  |
| 1118 | `vector_object_final` | 1 | 7.4s |  |
| 1119 | `vector_object_toString` | 10 | 13.3s |  |
| 1120 | `vector_pushpop` | 255 | 12.9s |  |
| 1121 | `vector_reborrow_bug` | 10 | 0.4s |  |
| 1122 | `vector_removeat` | 172 | 0.4s |  |
| 1123 | `vector_reverse` | 232 | 0.4s |  |
| 1124 | `vector_shiftunshift` | 252 | 0.4s |  |
| 1125 | `vector_slice` | 331 | 0.4s |  |
| 1126 | `vector_sort` | 905 | 0.4s |  |
| 1127 | `vector_splice` | 693 | 0.4s |  |
| 1128 | `vector_splice_fixed_bug_compat` | 4 | 0.4s |  |
| 1129 | `vector_tostring` | 79 | 0.4s |  |
| 1130 | `verification` | 8 | 0.4s |  |
| 1131 | `verify_abnormal_loop` | 1 | 0.4s |  |
| 1132 | `verify_dxns_without_flag` | 3 | 0.4s |  |
| 1133 | `verify_exception_target_two_jumps` | 1 | 0.4s |  |
| 1134 | `verify_exception_targets_edge_case` | 1 | 0.4s |  |
| 1135 | `verify_illegal_opcode` | 1 | 0.4s |  |
| 1136 | `verify_jump_to_middle_of_op` | 1 | 0.4s |  |
| 1137 | `verify_lookup_switch_edge_case` | 1 | 0.4s |  |
| 1138 | `verify_method_info_oob` | 1 | 0.3s |  |
| 1139 | `verify_stack` | 5 | 0.4s |  |
| 1140 | `verify_typecheck` | 4 | 0.4s |  |
| 1141 | `verify_unreachable_exception` | 2 | 0.4s |  |
| 1142 | `versioned_isplaying` | 2 | 0.4s |  |
| 1143 | `virtual_properties` | 16 | 0.4s |  |
| 1144 | `with` | 4 | 0.4s |  |
| 1145 | `wrong_arg_count` | 7 | 0.4s |  |
| 1146 | `xml_abstract_equality` | 36 | 0.4s |  |
| 1147 | `xml_advanced` | 52 | 0.4s |  |
| 1148 | `xml_appendchild` | 10 | 0.4s |  |
| 1149 | `xml_appendchild_swf_v21` | 13 | 0.4s |  |
| 1150 | `xml_as_attribute` | 9 | 0.4s |  |
| 1151 | `xml_attribute` | 35 | 0.4s |  |
| 1152 | `xml_attribute_name` | 40 | 0.4s |  |
| 1153 | `xml_basic` | 33 | 0.4s |  |
| 1154 | `xml_child` | 25 | 0.4s |  |
| 1155 | `xml_childindex` | 7 | 0.4s |  |
| 1156 | `xml_children` | 43 | 0.4s |  |
| 1157 | `xml_class_call` | 9 | 0.4s |  |
| 1158 | `xml_contains` | 197 | 0.4s |  |
| 1159 | `xml_copy` | 20 | 20.8s |  |
| 1160 | `xml_ctor_from_tostring` | 23 | 24.9s |  |
| 1161 | `xml_delete` | 114 | 6.4s |  |
| 1162 | `xml_descendants` | 83 | 6.6s |  |
| 1163 | `xml_duplicate_attribute` | 14 | 6.6s |  |
| 1164 | `xml_elements` | 6 | 6.4s |  |
| 1165 | `xml_equals_namespace_check` | 2 | 6.4s |  |
| 1166 | `xml_explicit_use_namespace` | 5 | 2.2s |  |
| 1167 | `xml_getdescendants_qname` | 21 | 6.3s |  |
| 1168 | `xml_has_property_via_in` | 26 | 6.3s |  |
| 1169 | `xml_hasownproperty` | 6 | 6.2s |  |
| 1170 | `xml_ignore_white` | 6 | 6.4s |  |
| 1171 | `xml_length` | 2 | 6.4s |  |
| 1172 | `xml_list_as_attribute` | 9 | 6.2s |  |
| 1173 | `xml_list_concat` | 20 | 6.5s |  |
| 1174 | `xml_list_ctor_errors` | 34 | 6.7s |  |
| 1175 | `xml_list_delete_clear_parent` | 6 | 6.3s |  |
| 1176 | `xml_list_enumerate` | 4 | 6.3s |  |
| 1177 | `xml_methods_settings` | 3 | 6.3s |  |
| 1178 | `xml_mismatched_tag` | 37 | 6.5s |  |
| 1179 | `xml_namespace` | 39 | 6.7s |  |
| 1180 | `xml_namespace_methods` | 245 | 6.3s |  |
| 1181 | `xml_namespaced_property` | 7 | 6.2s |  |
| 1182 | `xml_no_namespace` | 1 | 6.3s |  |
| 1183 | `xml_nodekind` | 3 | 6.2s |  |
| 1184 | `xml_normalize` | 35 | 6.3s |  |
| 1185 | `xml_notification_bubbling` | 361 | 6.6s |  |
| 1186 | `xml_parent` | 8 | 6.5s |  |
| 1187 | `xml_set_children` | 17 | 6.4s |  |
| 1188 | `xml_set_name` | 34 | 6.5s |  |
| 1189 | `xml_settings` | 6 | 2.1s |  |
| 1190 | `xml_simple_complex_content` | 47 | 6.3s |  |
| 1191 | `xml_socket` | 11 | 6.5s |  |
| 1192 | `xml_text` | 7 | 6.3s |  |
| 1193 | `xml_tostring` | 6 | 6.3s |  |
| 1194 | `xml_tostring_namespace` | 12 | 6.0s |  |
| 1195 | `xml_unescaping` | 23 | 6.2s |  |
| 1196 | `xml_weird_ignores` | 54 | 6.5s |  |
| 1197 | `xml_wildcard` | 11 | 6.4s |  |
| 1198 | `xmldocument` | 254 | 6.4s |  |
| 1199 | `xmlnode` | 3540 | 6.6s |  |
| 1200 | `zero_frame_clip` | 3 | 7.0s |  |

## Ruffle-Matched Tests

**36 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 7.0s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.4s |  |
| 3 | `bitmapdata_copypixels_alpha_merge` | 4 | 4 | 27.1s |  |
| 4 | `blend_transform` | 1 | 1 | 7.5s |  |
| 5 | `bounds_mode` | 6 | 6 | 6.1s |  |
| 6 | `coerce_property` | 3 | 3 | 7.2s |  |
| 7 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 2.4s |  |
| 8 | `dictionary_weak_keys` | 1 | 1 | 26.3s |  |
| 9 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 26.9s |  |
| 10 | `edittext_device_transform_layout` | 20 | 20 | 7.4s |  |
| 11 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.4s |  |
| 12 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 7.2s |  |
| 13 | `edittext_tab_stops` | 6 | 6 | 8.0s |  |
| 14 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.9s |  |
| 15 | `error_1034_debug_string` | 19 | 19 | 7.4s |  |
| 16 | `event_handler_exception` | 4 | 4 | 7.3s |  |
| 17 | `freestanding_superclass` | 2 | 4 | 7.6s |  |
| 18 | `goto_framescript_queued` | 5 | 5 | 27.9s |  |
| 19 | `graphics_draw_path` | 50 | 50 | 27.1s |  |
| 20 | `groupelement_text` | 2 | 2 | 7.2s |  |
| 21 | `int_toexponential` | 76 | 76 | 7.3s |  |
| 22 | `matrix3d_append_rotation` | 1 | 3 | 7.8s |  |
| 23 | `matrix3d_recompose_edge_cases` | 85 | 85 | 8.1s |  |
| 24 | `number_convert_errors` | 706 | 706 | 5.6s |  |
| 25 | `simplebutton_childevents_script_order` | 4 | 4 | 7.6s |  |
| 26 | `slot_holes_fail` | 1 | 1 | 7.2s |  |
| 27 | `slot_id_exceeds_trait_count` | 1 | 1 | 26.9s |  |
| 28 | `soundchannel_position` | 74 | 74 | 27.9s |  |
| 29 | `soundchannel_soundcomplete` | 10 | 10 | 7.5s |  |
| 30 | `sprite_dropTarget` | 15 | 15 | 7.3s |  |
| 31 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.4s |  |
| 32 | `textblock_line_changes` | 44 | 44 | 5.5s |  |
| 33 | `textblock_releaselines` | 4 | 4 | 5.6s |  |
| 34 | `uint_toexponential` | 100 | 100 | 7.8s |  |
| 35 | `uncaught_errors_stringified` | 15 | 15 | 2.7s |  |
| 36 | `weird_superinterface_properties` | 1 | 1 | 0.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `geom_transform` | 95.9% | 71 | 74 | 3 |  |
| 3 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 4 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 5 | `displayobject_getrect` | 68.8% | 11 | 16 | 5 |  |
| 6 | `number_to_string` | 67.1% | 237 | 353 | 116 |  |
| 7 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 8 | `bytearray_bad_symbol_class_other_movie` | 66.7% | 4 | 6 | 2 |  |
| 9 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 10 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 11 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**34 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `geom_transform` | 95.9% | 71/74 | 74 | 74 |  |
| 3 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 4 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 5 | `displayobject_getrect` | 68.8% | 11/16 | 16 | 16 |  |
| 6 | `number_to_string` | 67.1% | 237/353 | 353 | 353 |  |
| 7 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 8 | `bytearray_bad_symbol_class_other_movie` | 66.7% | 4/6 | 5 | 6 |  |
| 9 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 10 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 11 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 12 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 13 | `bytearray_bad_symbol_class` | 33.3% | 1/3 | 2 | 3 |  |
| 14 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 15 | `json_parse_numbers` | 23.7% | 31/131 | 118 | 131 |  |
| 16 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 17 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 18 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 19 | `displayobject_z` | 15.8% | 6/38 | 11 | 38 |  |
| 20 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 21 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 22 | `loader_events_2` | 5.7% | 2/35 | 31 | 35 |  |
| 23 | `edittext_scroll_event` | 5.4% | 2/37 | 7 | 37 |  |
| 24 | `json_parse_errors` | 4.8% | 4/84 | 64 | 84 |  |
| 25 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 26 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 27 | `bitmap_filter_abstract` | 0.0% | 0/6 | 4 | 6 |  |
| 28 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 29 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 30 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 31 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 32 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 33 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 34 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
