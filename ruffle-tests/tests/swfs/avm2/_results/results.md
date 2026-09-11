# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-06 08:47 UTC

**Git SHA**: `bf907d0023`

**Run Duration**: 186m 28s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1262 |
| Passing | **1199** (95.0%) |
| Ruffle-matched | 36 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1235** (97.9%) |
| Failing | 27 |
| Total expected lines | 155033 |
| Matching lines | 152158 (98.1%) |
| Mismatched lines | 2875 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 27 | 100.0% |

## Passing Tests

**1199 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 5.9s |  |
| 2 | `accessibility` | 1 | 6.0s |  |
| 3 | `accessibilityimplementation` | 18 | 5.9s |  |
| 4 | `activation_class` | 6 | 5.9s |  |
| 5 | `add` | 1058 | 14.5s |  |
| 6 | `agal_compiler` | 13 | 7.4s |  |
| 7 | `air_datagram_socket` | 1 | 7.3s |  |
| 8 | `air_hidden_lookup` | 2 | 5.8s |  |
| 9 | `air_ifilepromise` | 1 | 5.5s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 5.9s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.4s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.4s |  |
| 13 | `all_classes/display/swf10` | 2569 | 5.8s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.5s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.5s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.5s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.4s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.5s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 5.7s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.4s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.4s |  |
| 22 | `all_classes/errors/swf10` | 140 | 5.7s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.4s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.4s |  |
| 25 | `all_classes/events/swf10` | 1638 | 5.8s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.4s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.4s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.5s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.5s |  |
| 30 | `all_classes/security/swf11` | 3 | 6.2s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.4s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.5s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.5s |  |
| 34 | `all_classes/xml/swf30` | 116 | 6.2s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.4s |  |
| 36 | `amf_array_serialization` | 17 | 24.5s |  |
| 37 | `amf_custom_obj` | 26 | 5.8s |  |
| 38 | `amf_dictionary` | 9 | 5.7s |  |
| 39 | `amf_function` | 46 | 5.7s |  |
| 40 | `amf_invalid_date` | 2 | 5.9s |  |
| 41 | `amf_missing_prop` | 6 | 6.0s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 5.8s |  |
| 43 | `amf_setter_error` | 8 | 5.7s |  |
| 44 | `amf_vector` | 40 | 5.4s |  |
| 45 | `amf_xml` | 6 | 5.5s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 5.3s |  |
| 47 | `application_domain` | 4 | 5.0s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 5.2s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 4.9s |  |
| 50 | `array_access` | 18 | 5.0s |  |
| 51 | `array_access_interpreter` | 4 | 4.9s |  |
| 52 | `array_access_no_pubns` | 2 | 1.5s |  |
| 53 | `array_concat` | 41 | 5.1s |  |
| 54 | `array_constr` | 10 | 5.0s |  |
| 55 | `array_delete` | 44 | 5.0s |  |
| 56 | `array_enumeration` | 10 | 5.1s |  |
| 57 | `array_enumeration_elements` | 11 | 5.2s |  |
| 58 | `array_every` | 8 | 1.6s |  |
| 59 | `array_filter` | 6 | 5.1s |  |
| 60 | `array_foreach` | 18 | 5.3s |  |
| 61 | `array_hasownproperty` | 11 | 5.9s |  |
| 62 | `array_holes` | 9 | 5.1s |  |
| 63 | `array_index_max` | 84 | 5.3s |  |
| 64 | `array_indexof` | 25 | 5.1s |  |
| 65 | `array_join` | 26 | 5.5s |  |
| 66 | `array_lastindexof` | 29 | 5.6s |  |
| 67 | `array_length` | 14 | 5.4s |  |
| 68 | `array_literal` | 3 | 5.2s |  |
| 69 | `array_map` | 8 | 5.1s |  |
| 70 | `array_pop` | 52 | 5.3s |  |
| 71 | `array_push` | 24 | 5.3s |  |
| 72 | `array_reborrow_bug` | 6 | 5.8s |  |
| 73 | `array_reverse` | 28 | 5.6s |  |
| 74 | `array_shift` | 51 | 1.9s |  |
| 75 | `array_slice` | 39 | 5.4s |  |
| 76 | `array_some` | 8 | 5.2s |  |
| 77 | `array_sort` | 297 | 5.9s |  |
| 78 | `array_sort_fun_swf12` | 2 | 5.5s |  |
| 79 | `array_sort_fun_swf13` | 2 | 0.4s |  |
| 80 | `array_sort_random` | 210 | 5.4s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 5.0s |  |
| 82 | `array_sorton` | 545 | 5.7s |  |
| 83 | `array_sparse_ops` | 41 | 5.4s |  |
| 84 | `array_splice` | 133 | 5.4s |  |
| 85 | `array_splice2` | 428 | 7.5s |  |
| 86 | `array_splice_types` | 48 | 7.2s |  |
| 87 | `array_storage` | 8 | 7.1s |  |
| 88 | `array_tolocalestring` | 9 | 7.1s |  |
| 89 | `array_tostring` | 12 | 7.1s |  |
| 90 | `array_unshift` | 24 | 7.1s |  |
| 91 | `array_valueof` | 9 | 2.3s |  |
| 92 | `array_vector_null_callback` | 10 | 7.1s |  |
| 93 | `astype` | 28 | 7.2s |  |
| 94 | `astypelate` | 24 | 7.2s |  |
| 95 | `astypelate_propagates` | 1 | 7.0s |  |
| 96 | `asymmetric_key_events` | 11 | 7.3s |  |
| 97 | `automation_classes` | 122 | 7.5s |  |
| 98 | `av_classes` | 340 | 7.5s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 7.3s |  |
| 100 | `avm2_catchup_dobj` | 158 | 7.8s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 85.2s |  |
| 102 | `bevel_filter` | 187 | 7.5s |  |
| 103 | `bitand` | 1058 | 19.5s |  |
| 104 | `bitmap_constr` | 17 | 7.5s |  |
| 105 | `bitmap_data` | 1000 | 15.6s |  |
| 106 | `bitmap_pixelsnapping` | 2 | 26.9s |  |
| 107 | `bitmap_properties` | 23 | 7.2s |  |
| 108 | `bitmap_subclass` | 7 | 8.7s |  |
| 109 | `bitmap_subclass_properties` | 9 | 7.5s |  |
| 110 | `bitmap_timeline` | 9 | 7.3s |  |
| 111 | `bitmapdata_accuracy` | 1 | 42.5s |  |
| 112 | `bitmapdata_applyfilter_blur` | 0 | 28.0s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.9s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | 0 | 28.6s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 29.3s |  |
| 116 | `bitmapdata_applyfilter_identity` | 4 | 29.0s |  |
| 117 | `bitmapdata_clone` | 13 | 7.7s |  |
| 118 | `bitmapdata_colortransform` | 0 | 7.9s |  |
| 119 | `bitmapdata_colortransform_oob` | 2 | 7.6s |  |
| 120 | `bitmapdata_constr` | 22 | 7.7s |  |
| 121 | `bitmapdata_constructor_from_timeline` | 1 | 8.1s |  |
| 122 | `bitmapdata_copychannel` | 0 | 30.4s |  |
| 123 | `bitmapdata_copypixels` | 23 | 28.5s |  |
| 124 | `bitmapdata_copypixels_alpha_combine` | 13 | 7.7s |  |
| 125 | `bitmapdata_copypixels_blend_over` | 1 | 7.2s |  |
| 126 | `bitmapdata_copypixelstobytearray` | 39 | 7.1s |  |
| 127 | `bitmapdata_dispose` | 7 | 7.1s |  |
| 128 | `bitmapdata_draw` | 0 | 26.4s |  |
| 129 | `bitmapdata_draw_alpha_erase` | 8 | 7.2s |  |
| 130 | `bitmapdata_draw_cab_quality` | 0 | 27.5s |  |
| 131 | `bitmapdata_draw_colortransform` | 0 | 7.2s |  |
| 132 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.3s |  |
| 133 | `bitmapdata_draw_filters` | 0 | 26.0s |  |
| 134 | `bitmapdata_draw_masks` | 0 | 7.1s |  |
| 135 | `bitmapdata_draw_rotation` | 0 | 7.1s |  |
| 136 | `bitmapdata_draw_self_via_graphic` | 0 | 7.1s |  |
| 137 | `bitmapdata_draw_stage` | 0 | 26.2s |  |
| 138 | `bitmapdata_drawwithquality` | 0 | 7.4s |  |
| 139 | `bitmapdata_embedded` | 9 | 2.5s |  |
| 140 | `bitmapdata_fillrect` | 0 | 7.2s |  |
| 141 | `bitmapdata_filter_sourcerect` | 0 | 21.3s |  |
| 142 | `bitmapdata_floodfill` | 35 | 7.1s |  |
| 143 | `bitmapdata_getpixels` | 39 | 26.1s |  |
| 144 | `bitmapdata_getvector` | 27 | 2.3s |  |
| 145 | `bitmapdata_histogram` | 59 | 2.3s |  |
| 146 | `bitmapdata_hittest` | 112 | 7.7s |  |
| 147 | `bitmapdata_hittest_threshold` | 18 | 7.2s |  |
| 148 | `bitmapdata_opaque` | 0 | 7.1s |  |
| 149 | `bitmapdata_pixeldissolve` | 1037 | 7.7s |  |
| 150 | `bitmapdata_pixeldissolve_image` | 0 | 7.4s |  |
| 151 | `bitmapdata_rectangle_rounding` | 16 | 7.1s |  |
| 152 | `bitmapdata_setpixels` | 286 | 2.5s |  |
| 153 | `bitmapdata_setvector` | 26 | 7.0s |  |
| 154 | `bitmapdata_sync` | 0 | 26.2s |  |
| 155 | `bitmapdata_threshold` | 176 | 7.8s |  |
| 156 | `bitmapdata_zero_size` | 8 | 7.1s |  |
| 157 | `bitnot` | 46 | 7.1s |  |
| 158 | `bitor` | 1058 | 19.2s |  |
| 159 | `bitxor` | 1058 | 19.1s |  |
| 160 | `blend_mode_null` | 1 | 7.0s |  |
| 161 | `blend_multiply_alpha` | 0 | 7.1s |  |
| 162 | `blend_scroll` | 0 | 7.1s |  |
| 163 | `blend_shader_luma_lighten` | 3 | 7.3s |  |
| 164 | `blur_filter` | 43 | 7.2s |  |
| 165 | `boolean_constr` | 32 | 7.4s |  |
| 166 | `boolean_negation` | 30 | 7.3s |  |
| 167 | `boolean_tostring` | 8 | 7.2s |  |
| 168 | `broadcast_event` | 7 | 7.0s |  |
| 169 | `button_bounds` | 1 | 7.3s |  |
| 170 | `button_hittest` | 2 | 26.4s |  |
| 171 | `button_nested_frame` | 48 | 26.5s |  |
| 172 | `button_nested_frame_simple` | 27 | 7.3s |  |
| 173 | `bytearray` | 48 | 7.3s |  |
| 174 | `bytearray_compress` | 31 | 7.2s |  |
| 175 | `bytearray_errors` | 24 | 7.3s |  |
| 176 | `bytearray_method_serialization` | 1 | 7.1s |  |
| 177 | `bytearray_oom` | 3 | 7.1s |  |
| 178 | `bytearray_readobject_amf0` | 50 | 7.0s |  |
| 179 | `bytearray_readobject_amf3` | 53 | 7.1s |  |
| 180 | `bytearray_readutf8bytes_with_bom` | 16 | 7.1s |  |
| 181 | `bytearray_serialization` | 3 | 7.2s |  |
| 182 | `bytearray_string_null` | 19 | 7.4s |  |
| 183 | `bytearray_tostring` | 15 | 7.2s |  |
| 184 | `bytearray_utf16` | 8 | 7.2s |  |
| 185 | `bytearray_writeobject` | 24 | 6.9s |  |
| 186 | `callee_in_initializer` | 6 | 7.1s |  |
| 187 | `callproplex_class` | 1 | 7.1s |  |
| 188 | `capabilities_resolution` | 8 | 27.3s |  |
| 189 | `catch_class` | 6 | 7.0s |  |
| 190 | `catch_scope_slot` | 7 | 7.2s |  |
| 191 | `checkfilter` | 4 | 2.3s |  |
| 192 | `class_call` | 32 | 7.2s |  |
| 193 | `class_cast_call` | 14 | 7.1s |  |
| 194 | `class_enumeration` | 4 | 7.0s |  |
| 195 | `class_has_own_property` | 2 | 7.0s |  |
| 196 | `class_init_interpreter_mode` | 1 | 7.0s |  |
| 197 | `class_is` | 32 | 7.2s |  |
| 198 | `class_methods` | 5 | 7.0s |  |
| 199 | `class_object_properties` | 10 | 7.1s |  |
| 200 | `class_singleton` | 18 | 7.2s |  |
| 201 | `class_supercalls_errors` | 35 | 7.3s |  |
| 202 | `class_supercalls_mismatched` | 26 | 7.2s |  |
| 203 | `class_superclass_wrong_order` | 1 | 7.1s |  |
| 204 | `class_to_locale_string` | 2 | 7.1s |  |
| 205 | `class_to_string` | 2 | 7.1s |  |
| 206 | `class_value_of` | 2 | 7.0s |  |
| 207 | `click_block` | 5 | 7.7s |  |
| 208 | `click_invisible` | 3 | 7.3s |  |
| 209 | `closures` | 12 | 7.2s |  |
| 210 | `coerce_return_type` | 40 | 7.4s |  |
| 211 | `coerce_return_type_fail` | 2 | 7.2s |  |
| 212 | `coerce_return_void` | 3 | 7.0s |  |
| 213 | `coerce_string` | 86 | 7.2s |  |
| 214 | `coerce_string_precision` | 28 | 7.2s |  |
| 215 | `coerce_to_primitive_side_effects` | 29 | 7.2s |  |
| 216 | `color_matrix_filter` | 19 | 7.3s |  |
| 217 | `construct_errors_swf10` | 8 | 7.3s |  |
| 218 | `construct_frame_list` | 22 | 27.9s |  |
| 219 | `construct_interface` | 3 | 7.3s |  |
| 220 | `constructor_call` | 3 | 7.2s |  |
| 221 | `constructors_vs_timeline` | 5 | 27.5s |  |
| 222 | `constructprop_dynamic_primitive` | 7 | 7.3s |  |
| 223 | `constructprop_method` | 2 | 7.3s |  |
| 224 | `constructsuper_null` | 2 | 7.2s |  |
| 225 | `content_element_basic` | 50 | 7.4s |  |
| 226 | `context3d_creation` | 9 | 7.2s |  |
| 227 | `control_flow_bool` | 4 | 7.2s |  |
| 228 | `control_flow_stricteq` | 8 | 7.1s |  |
| 229 | `convert_boolean` | 30 | 7.2s |  |
| 230 | `convert_integer` | 90 | 7.1s |  |
| 231 | `convert_number` | 56 | 7.2s |  |
| 232 | `convert_uinteger` | 90 | 7.2s |  |
| 233 | `convolution_filter` | 89 | 7.2s |  |
| 234 | `core_exceptions` | 47 | 8.1s |  |
| 235 | `cpool_index_invalid_bytecode_1` | 6 | 7.2s |  |
| 236 | `cpool_index_invalid_bytecode_2` | 3 | 7.1s |  |
| 237 | `cpool_index_invalid_bytecode_3` | 1 | 7.2s |  |
| 238 | `cross_api_version_call_newer` | 12 | 7.6s |  |
| 239 | `cross_api_version_call_older` | 12 | 7.4s |  |
| 240 | `cryptscore` | 11 | 7.3s |  |
| 241 | `currency_parse_result` | 7 | 7.1s |  |
| 242 | `date` | 30 | 7.6s |  |
| 243 | `date_parse` | 36 | 7.0s |  |
| 244 | `declocal` | 46 | 7.2s |  |
| 245 | `declocal_i` | 46 | 4.7s |  |
| 246 | `decode_uri` | 71 | 4.9s |  |
| 247 | `decrement` | 46 | 4.5s |  |
| 248 | `decrement_i` | 46 | 1.6s |  |
| 249 | `default_values` | 7 | 4.7s |  |
| 250 | `delayed_symbolclass` | 28 | 17.7s |  |
| 251 | `describe_type_basic` | 152 | 5.0s |  |
| 252 | `describe_type_json` | 301 | 4.9s |  |
| 253 | `describe_type_metadata` | 125 | 5.2s |  |
| 254 | `describe_type_native` | 23 | 5.5s |  |
| 255 | `dictionary_access` | 62 | 5.2s |  |
| 256 | `dictionary_access_no_pubns` | 2 | 4.9s |  |
| 257 | `dictionary_delete` | 101 | 5.1s |  |
| 258 | `dictionary_foreach` | 42 | 5.1s |  |
| 259 | `dictionary_hasownproperty` | 63 | 4.8s |  |
| 260 | `dictionary_in` | 62 | 5.1s |  |
| 261 | `dictionary_iter_modify` | 8 | 5.1s |  |
| 262 | `dictionary_namespaces` | 36 | 5.0s |  |
| 263 | `displacement_map_filter` | 61 | 4.8s |  |
| 264 | `displayobject_alpha` | 277 | 4.8s |  |
| 265 | `displayobject_blendmode` | 0 | 16.6s |  |
| 266 | `displayobject_colortransform_nested` | 0 | 17.6s |  |
| 267 | `displayobject_early_init` | 54 | 6.0s |  |
| 268 | `displayobject_filters` | 17 | 5.5s |  |
| 269 | `displayobject_from_enterframe` | 1 | 19.9s |  |
| 270 | `displayobject_getbounds_shape` | 0 | 19.1s |  |
| 271 | `displayobject_height` | 6052 | 17.7s |  |
| 272 | `displayobject_hittestobject` | 32 | 5.0s |  |
| 273 | `displayobject_hittestpoint` | 49 | 5.0s |  |
| 274 | `displayobject_hittestpoint_boundary` | 65 | 17.6s |  |
| 275 | `displayobject_hittestpoint_root` | 13 | 5.1s |  |
| 276 | `displayobject_invalid_floats` | 60 | 4.9s |  |
| 277 | `displayobject_invalid_props` | 3 | 4.8s |  |
| 278 | `displayobject_mask` | 3 | 5.0s |  |
| 279 | `displayobject_mask_self_referential` | 0 | 4.8s |  |
| 280 | `displayobject_metaData` | 3 | 4.8s |  |
| 281 | `displayobject_name` | 22 | 17.8s |  |
| 282 | `displayobject_name_from_timeline` | 24 | 5.4s |  |
| 283 | `displayobject_opaque_background` | 6 | 5.2s |  |
| 284 | `displayobject_parent` | 12 | 26.4s |  |
| 285 | `displayobject_root` | 24 | 7.1s |  |
| 286 | `displayobject_rotation` | 1284 | 7.3s |  |
| 287 | `displayobject_scrollrect` | 33 | 7.6s |  |
| 288 | `displayobject_set_matrix_nested` | 0 | 26.6s |  |
| 289 | `displayobject_set_name_loaded` | 3 | 7.5s |  |
| 290 | `displayobject_subclass` | 2 | 7.1s |  |
| 291 | `displayobject_transform` | 89 | 7.3s |  |
| 292 | `displayobject_visible` | 23 | 7.2s |  |
| 293 | `displayobject_width` | 4852 | 26.7s |  |
| 294 | `displayobject_x` | 614 | 7.1s |  |
| 295 | `displayobject_y` | 617 | 7.2s |  |
| 296 | `displayobjectcontainer_addchild` | 32 | 7.3s |  |
| 297 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.1s |  |
| 298 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.3s |  |
| 299 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.2s |  |
| 300 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.3s |  |
| 301 | `displayobjectcontainer_addchildat` | 42 | 7.2s |  |
| 302 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.3s |  |
| 303 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.2s |  |
| 304 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.2s |  |
| 305 | `displayobjectcontainer_contains` | 66 | 26.5s |  |
| 306 | `displayobjectcontainer_getchildat` | 4 | 7.2s |  |
| 307 | `displayobjectcontainer_getchildbyname` | 9 | 7.2s |  |
| 308 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.1s |  |
| 309 | `displayobjectcontainer_getchildindex` | 28 | 7.1s |  |
| 310 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.3s |  |
| 311 | `displayobjectcontainer_removechild` | 10 | 7.1s |  |
| 312 | `displayobjectcontainer_removechild_errors` | 4 | 7.1s |  |
| 313 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.2s |  |
| 314 | `displayobjectcontainer_removechildat` | 18 | 7.1s |  |
| 315 | `displayobjectcontainer_removechildren` | 51 | 7.4s |  |
| 316 | `displayobjectcontainer_setchildindex` | 42 | 7.0s |  |
| 317 | `displayobjectcontainer_stopallmovieclips` | 2 | 26.5s |  |
| 318 | `displayobjectcontainer_swapchildren` | 42 | 7.2s |  |
| 319 | `displayobjectcontainer_swapchildrenat` | 42 | 7.2s |  |
| 320 | `displayobjectcontainer_timelineinstance` | 48 | 26.4s |  |
| 321 | `divide` | 1058 | 19.2s |  |
| 322 | `doabc_and_symbolclass_script_init_goto` | 7 | 26.4s |  |
| 323 | `doabc_and_symbolclass_script_init_normal` | 6 | 7.1s |  |
| 324 | `doabc_is_eager` | 1 | 26.2s |  |
| 325 | `documentclass` | 9 | 7.5s |  |
| 326 | `domain_memory` | 133 | 8.4s |  |
| 327 | `drag_drop` | 10 | 7.5s |  |
| 328 | `drop_shadow_filter` | 172 | 7.5s |  |
| 329 | `duplicate_defs` | 1 | 7.1s |  |
| 330 | `eager_init` | 1 | 7.3s |  |
| 331 | `east_asian_justifier_clone` | 8 | 7.4s |  |
| 332 | `edit_text_linkage` | 7 | 7.6s |  |
| 333 | `edittext_align` | 60 | 7.8s |  |
| 334 | `edittext_always_show_selection` | 0 | 27.4s |  |
| 335 | `edittext_antialiastype` | 296 | 7.5s |  |
| 336 | `edittext_at_point_methods_basic` | 16 | 8.6s |  |
| 337 | `edittext_autosize` | 39 | 7.8s |  |
| 338 | `edittext_autosize_align` | 0 | 27.1s |  |
| 339 | `edittext_autosize_height_dynamic` | 60 | 27.1s |  |
| 340 | `edittext_autosize_height_input` | 60 | 7.3s |  |
| 341 | `edittext_autosize_lazy_bounds_events` | 65 | 7.6s |  |
| 342 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.3s |  |
| 343 | `edittext_autosize_lazy_bounds_props` | 490 | 8.7s |  |
| 344 | `edittext_autosize_lazy_bounds_visual` | 0 | 7.3s |  |
| 345 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.4s |  |
| 346 | `edittext_bottom_scroll_v_basic` | 210 | 7.3s |  |
| 347 | `edittext_bounds_scale` | 24 | 7.2s |  |
| 348 | `edittext_bullet` | 30 | 7.5s |  |
| 349 | `edittext_default_format` | 221 | 7.8s |  |
| 350 | `edittext_default_format_empty` | 136 | 7.6s |  |
| 351 | `edittext_empty_text_format` | 7 | 7.4s |  |
| 352 | `edittext_focus_selection` | 5 | 7.4s |  |
| 353 | `edittext_font_size` | 45 | 7.4s |  |
| 354 | `edittext_format_empty_font` | 8 | 7.3s |  |
| 355 | `edittext_get_char_index_at_point` | 4 | 29.0s |  |
| 356 | `edittext_get_line_index_at_point` | 2 | 26.9s |  |
| 357 | `edittext_get_line_index_of_char` | 76 | 8.3s |  |
| 358 | `edittext_getcharboundaries` | 172 | 7.7s |  |
| 359 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.4s |  |
| 360 | `edittext_getcharboundaries_scroll` | 85 | 7.5s |  |
| 361 | `edittext_getlinemetrics` | 146 | 7.9s |  |
| 362 | `edittext_html` | 3101 | 8.0s |  |
| 363 | `edittext_html_condensewhite` | 487 | 7.6s |  |
| 364 | `edittext_html_entity` | 4 | 5.2s |  |
| 365 | `edittext_html_font_size_swf12` | 267 | 5.0s |  |
| 366 | `edittext_html_font_size_swf13` | 273 | 4.5s |  |
| 367 | `edittext_html_roundtrip` | 17 | 4.8s |  |
| 368 | `edittext_ime_focus_lost` | 9 | 5.0s |  |
| 369 | `edittext_input_control` | 12 | 4.8s |  |
| 370 | `edittext_leading` | 9 | 5.1s |  |
| 371 | `edittext_letter_spacing` | 15 | 4.8s |  |
| 372 | `edittext_line_methods` | 294 | 5.8s |  |
| 373 | `edittext_line_metrics` | 11 | 18.1s |  |
| 374 | `edittext_margins` | 25 | 4.9s |  |
| 375 | `edittext_max_scroll_h_basic` | 475 | 5.1s |  |
| 376 | `edittext_max_scroll_v_basic` | 1000 | 4.9s |  |
| 377 | `edittext_mouse_selection` | 363 | 17.9s |  |
| 378 | `edittext_mousedown` | 3 | 5.1s |  |
| 379 | `edittext_mouseenabled` | 26 | 4.7s |  |
| 380 | `edittext_newline_character` | 22 | 4.8s |  |
| 381 | `edittext_newline_stripping` | 64 | 6.5s |  |
| 382 | `edittext_newlines` | 30 | 5.0s |  |
| 383 | `edittext_paragraph_methods` | 257 | 5.2s |  |
| 384 | `edittext_paste_events` | 8 | 5.1s |  |
| 385 | `edittext_paste_maxchars` | 4 | 5.0s |  |
| 386 | `edittext_paste_restrict` | 16 | 4.7s |  |
| 387 | `edittext_restrict` | 191 | 4.6s |  |
| 388 | `edittext_restrict_events` | 22 | 4.7s |  |
| 389 | `edittext_scrollh` | 10 | 1.5s |  |
| 390 | `edittext_selected_text` | 9 | 1.6s |  |
| 391 | `edittext_set_html_same` | 17 | 4.8s |  |
| 392 | `edittext_set_text_vs_html` | 9 | 4.8s |  |
| 393 | `edittext_stylesheet` | 536 | 5.4s |  |
| 394 | `edittext_stylesheet_custom_tag` | 76 | 4.8s |  |
| 395 | `edittext_stylesheet_display` | 272 | 4.9s |  |
| 396 | `edittext_tag_indent` | 49 | 17.1s |  |
| 397 | `edittext_underline` | 40 | 4.9s |  |
| 398 | `edittext_width_height` | 103 | 5.2s |  |
| 399 | `edittext_wordwrap_word` | 150 | 4.8s |  |
| 400 | `edittext_wrap_breaks` | 2375 | 5.2s |  |
| 401 | `element_format_clone` | 44 | 4.8s |  |
| 402 | `element_format_constructor_order` | 64 | 1.6s |  |
| 403 | `element_format_properties` | 235 | 5.3s |  |
| 404 | `empty_bounds` | 1 | 4.7s |  |
| 405 | `encode_uri_surrogate_pair_invalid` | 8 | 6.7s |  |
| 406 | `encode_uri_surrogate_pair_swf11` | 15 | 5.9s |  |
| 407 | `equals` | 512 | 8.9s |  |
| 408 | `error_geterrormessage` | 779 | 6.3s |  |
| 409 | `error_prototype` | 15 | 6.4s |  |
| 410 | `error_stack_trace` | 45 | 6.4s |  |
| 411 | `error_stack_trace_debug_swf17` | 0 | 24.1s |  |
| 412 | `error_stack_trace_debug_swf18` | 0 | 6.1s |  |
| 413 | `error_stack_trace_edge_cases` | 6 | 6.5s |  |
| 414 | `error_stack_trace_release_swf17` | 0 | 1.8s |  |
| 415 | `error_stack_trace_release_swf18` | 0 | 6.3s |  |
| 416 | `error_throwerror` | 103 | 6.7s |  |
| 417 | `error_tostring` | 29 | 6.2s |  |
| 418 | `error_tostring_more` | 86 | 6.5s |  |
| 419 | `es3_inheritance` | 31 | 6.4s |  |
| 420 | `es4_inheritance` | 30 | 6.5s |  |
| 421 | `es4_interfaces` | 30 | 6.3s |  |
| 422 | `es4_method_binding` | 8 | 6.4s |  |
| 423 | `es4_oop_prototypes` | 14 | 6.4s |  |
| 424 | `es4_protected_inheritance` | 6 | 6.3s |  |
| 425 | `escape` | 71 | 6.4s |  |
| 426 | `escape_multi_byte` | 45 | 6.6s |  |
| 427 | `event_bubbles` | 2 | 6.6s |  |
| 428 | `event_cancelable` | 2 | 6.3s |  |
| 429 | `event_clone` | 20 | 6.6s |  |
| 430 | `event_clone_error_redispatch` | 3 | 2.1s |  |
| 431 | `event_clone_on_redispatch` | 10 | 6.7s |  |
| 432 | `event_formattostring` | 31 | 6.7s |  |
| 433 | `event_isdefaultprevented` | 12 | 6.3s |  |
| 434 | `event_target_getter` | 5 | 1.9s |  |
| 435 | `event_target_set` | 9 | 6.3s |  |
| 436 | `event_type` | 1 | 6.3s |  |
| 437 | `event_valueof_tostring` | 18 | 6.4s |  |
| 438 | `eventdispatcher_dispatchevent` | 12 | 6.3s |  |
| 439 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.3s |  |
| 440 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.5s |  |
| 441 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.4s |  |
| 442 | `eventdispatcher_dispatchevent_this` | 5 | 6.6s |  |
| 443 | `eventdispatcher_haseventlistener` | 25 | 6.6s |  |
| 444 | `eventdispatcher_interface_invoke` | 1 | 6.6s |  |
| 445 | `eventdispatcher_tostring` | 10 | 6.6s |  |
| 446 | `eventdispatcher_willtrigger` | 25 | 6.7s |  |
| 447 | `falsiness` | 30 | 6.6s |  |
| 448 | `fast_index_access` | 12 | 6.8s |  |
| 449 | `filefilter_properties` | 4 | 6.6s |  |
| 450 | `filereference_browse_cancel` | 3 | 6.6s |  |
| 451 | `filereference_browse_select` | 9 | 2.0s |  |
| 452 | `filereference_load` | 31 | 6.7s |  |
| 453 | `filereference_save` | 16 | 6.7s |  |
| 454 | `filereference_save_and_browse` | 42 | 6.7s |  |
| 455 | `filereference_save_and_load` | 22 | 6.8s |  |
| 456 | `filereference_uninitialized` | 8 | 6.6s |  |
| 457 | `filereferencelist_browse_cancel` | 6 | 6.6s |  |
| 458 | `filereferencelist_browse_select` | 7 | 6.6s |  |
| 459 | `filter_rewind` | 8 | 25.3s |  |
| 460 | `filters_array_holes` | 25 | 6.7s |  |
| 461 | `finddef` | 3 | 6.7s |  |
| 462 | `findprop_global_prototype` | 6 | 6.7s |  |
| 463 | `flash_media_video_constructor` | 156 | 7.5s |  |
| 464 | `flash_media_video_rotation_probe` | 27 | 6.7s |  |
| 465 | `flash_media_video_setter` | 40 | 7.1s |  |
| 466 | `flash_trace` | 17 | 6.7s |  |
| 467 | `flash_ui_mouse_cursor` | 35 | 7.0s |  |
| 468 | `flash_xml` | 29 | 6.7s |  |
| 469 | `flash_xml_cloneNode` | 22 | 6.7s |  |
| 470 | `flash_xml_namespace` | 109 | 6.6s |  |
| 471 | `flash_xml_removeNode` | 60 | 6.7s |  |
| 472 | `focus_events_code` | 161 | 25.4s |  |
| 473 | `focus_events_key_basic` | 132 | 25.3s |  |
| 474 | `focus_events_key_navigation` | 53 | 25.2s |  |
| 475 | `focus_events_key_same_object` | 26 | 6.7s |  |
| 476 | `focus_events_mixed_key_mouse` | 100 | 25.3s |  |
| 477 | `focus_events_mouse_basic` | 260 | 25.8s |  |
| 478 | `focus_events_mouse_focusable` | 112 | 25.7s |  |
| 479 | `focus_events_mouse_same_object` | 40 | 6.7s |  |
| 480 | `focus_remove` | 20 | 25.4s |  |
| 481 | `focus_root_movie` | 4 | 25.3s |  |
| 482 | `focus_stage` | 1 | 6.6s |  |
| 483 | `focusrect` | 18 | 7.3s |  |
| 484 | `focusrect_focuslost` | 9 | 26.6s |  |
| 485 | `focusrect_property` | 110 | 7.1s |  |
| 486 | `font_description_clone` | 14 | 7.1s |  |
| 487 | `font_embedded` | 24 | 7.7s |  |
| 488 | `font_enumeratefonts` | 41 | 7.8s |  |
| 489 | `font_enumeratefonts_filter` | 4 | 7.9s |  |
| 490 | `font_enumeratefonts_order` | 9 | 8.4s |  |
| 491 | `font_hasglyphs` | 40 | 7.7s |  |
| 492 | `font_registerfont` | 129 | 8.2s |  |
| 493 | `framelabel_constr` | 5 | 7.3s |  |
| 494 | `function_call` | 12 | 2.5s |  |
| 495 | `function_call_arguments` | 46 | 2.5s |  |
| 496 | `function_call_arguments_enumerate` | 5 | 7.3s |  |
| 497 | `function_call_coercion` | 108 | 7.6s |  |
| 498 | `function_call_default` | 6 | 7.2s |  |
| 499 | `function_call_rest` | 22 | 7.2s |  |
| 500 | `function_call_types` | 3 | 7.2s |  |
| 501 | `function_call_via_apply` | 11 | 7.2s |  |
| 502 | `function_call_via_call` | 3 | 7.2s |  |
| 503 | `function_display_anonymous` | 7 | 2.4s |  |
| 504 | `function_length` | 6 | 7.3s |  |
| 505 | `function_object` | 2 | 7.3s |  |
| 506 | `function_proto` | 5 | 7.2s |  |
| 507 | `function_proto_created` | 61 | 7.2s |  |
| 508 | `function_to_locale_string` | 4 | 7.1s |  |
| 509 | `function_to_string` | 4 | 7.0s |  |
| 510 | `function_type` | 6 | 7.1s |  |
| 511 | `function_unbound_this` | 51 | 7.2s |  |
| 512 | `function_value_of` | 4 | 7.0s |  |
| 513 | `game_input` | 4 | 7.1s |  |
| 514 | `generate_random_bytes` | 3 | 7.1s |  |
| 515 | `geom_transform` | 74 | 26.8s |  |
| 516 | `get_definition_by_name` | 11 | 7.1s |  |
| 517 | `get_qualified_class_name` | 20 | 7.1s |  |
| 518 | `get_qualified_super_class_name` | 18 | 7.1s |  |
| 519 | `get_slot_edge_cases` | 1 | 7.0s |  |
| 520 | `get_timer` | 2 | 2.3s |  |
| 521 | `getglobalslot` | 1 | 7.0s |  |
| 522 | `getouterscope` | 8 | 7.0s |  |
| 523 | `getouterscope_two_classobjects` | 13 | 7.0s |  |
| 524 | `getter_different_namespace_setter` | 2 | 6.8s |  |
| 525 | `glow_filter` | 127 | 7.5s |  |
| 526 | `goto_button_nested_framescript` | 28 | 27.6s |  |
| 527 | `goto_in_constructframe` | 12 | 27.2s |  |
| 528 | `goto_in_scene_last_frame` | 2 | 27.0s |  |
| 529 | `goto_methods` | 56 | 7.6s |  |
| 530 | `goto_methods_swfver10` | 8 | 7.3s |  |
| 531 | `goto_nested_construct_sibling` | 18 | 7.8s |  |
| 532 | `goto_nested_framescript` | 9 | 7.5s |  |
| 533 | `goto_on_orphan` | 15 | 7.5s |  |
| 534 | `gradient_bevel_filter` | 206 | 7.4s |  |
| 535 | `gradient_glow_filter` | 206 | 7.2s |  |
| 536 | `graphic_linkage` | 9 | 7.5s |  |
| 537 | `graphics_bad_direct_commands` | 5 | 7.8s |  |
| 538 | `graphics_bitmap_fill` | 0 | 9.0s |  |
| 539 | `graphics_bitmaps` | 0 | 7.7s |  |
| 540 | `graphics_direct_commands` | 0 | 7.5s |  |
| 541 | `graphics_draw_triangles` | 98 | 27.8s |  |
| 542 | `graphics_gradients` | 0 | 7.4s |  |
| 543 | `graphics_gradients_nulls` | 0 | 7.3s |  |
| 544 | `graphics_path` | 56 | 7.3s |  |
| 545 | `graphics_round_rects` | 0 | 7.2s |  |
| 546 | `graphics_simple_shapes` | 0 | 7.2s |  |
| 547 | `greaterequals` | 512 | 11.3s |  |
| 548 | `greaterthan` | 512 | 11.2s |  |
| 549 | `has_own_property` | 102 | 7.7s |  |
| 550 | `hasownproperty_namespaces` | 2 | 7.2s |  |
| 551 | `hello_world` | 1 | 7.1s |  |
| 552 | `hittest_morph` | 30 | 7.3s |  |
| 553 | `if_eq` | 10 | 7.2s |  |
| 554 | `if_gt` | 1 | 7.2s |  |
| 555 | `if_gte` | 10 | 2.4s |  |
| 556 | `if_lt` | 1 | 0.6s |  |
| 557 | `if_lte` | 10 | 7.0s |  |
| 558 | `if_ne` | 7 | 2.4s |  |
| 559 | `if_stricteq` | 6 | 7.2s |  |
| 560 | `if_strictne` | 11 | 7.2s |  |
| 561 | `ime_linux_dead_keys` | 10 | 7.2s |  |
| 562 | `in` | 102 | 7.7s |  |
| 563 | `inclocal` | 46 | 7.7s |  |
| 564 | `inclocal_i` | 46 | 7.7s |  |
| 565 | `increment` | 46 | 7.7s |  |
| 566 | `increment_i` | 46 | 7.7s |  |
| 567 | `indexing_delete` | 75 | 7.6s |  |
| 568 | `init_callee_cached` | 24 | 7.6s |  |
| 569 | `instanceof` | 58 | 7.9s |  |
| 570 | `instantiate_root_character` | 4 | 7.9s |  |
| 571 | `instantiation_on_enter_frame` | 7 | 28.0s |  |
| 572 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.5s |  |
| 573 | `int_constr` | 92 | 7.8s |  |
| 574 | `int_edge_cases` | 19 | 7.7s |  |
| 575 | `int_instanceof` | 3 | 7.5s |  |
| 576 | `int_tofixed` | 1215 | 7.4s |  |
| 577 | `int_toprecision` | 1125 | 7.7s |  |
| 578 | `int_tostring` | 3375 | 7.8s |  |
| 579 | `interactiveobject_enabled` | 25 | 2.5s |  |
| 580 | `interface_namespaces` | 78 | 7.8s |  |
| 581 | `invalid_utf8` | 12 | 7.7s |  |
| 582 | `is_finite` | 46 | 7.6s |  |
| 583 | `is_nan` | 46 | 7.5s |  |
| 584 | `is_prototype_of` | 12 | 7.6s |  |
| 585 | `issue_10221` | 2 | 7.5s |  |
| 586 | `issue_13780` | 12 | 7.6s |  |
| 587 | `issue_14901` | 1 | 7.6s |  |
| 588 | `issue_17675_edittext_paste_maxchars` | 1 | 7.6s |  |
| 589 | `issue_5292` | 5 | 7.6s |  |
| 590 | `issue_8630` | 2 | 7.6s |  |
| 591 | `issue_8630_placeremoveplace` | 15 | 7.7s |  |
| 592 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.6s |  |
| 593 | `issue_8630_scriptremove` | 11 | 7.6s |  |
| 594 | `istype` | 24 | 2.7s |  |
| 595 | `istypelate` | 58 | 7.9s |  |
| 596 | `istypelate_coerce` | 198 | 8.5s |  |
| 597 | `jpeg_loader_context` | 6 | 7.5s |  |
| 598 | `json_errors` | 9 | 28.0s |  |
| 599 | `json_parse` | 21 | 7.6s |  |
| 600 | `json_stringify` | 12 | 7.8s |  |
| 601 | `json_stringify_function` | 12 | 7.5s |  |
| 602 | `json_stringify_order` | 1 | 2.6s |  |
| 603 | `json_version_gated` | 1 | 7.6s |  |
| 604 | `key_input_80percent` | 1812 | 7.5s |  |
| 605 | `key_input_location` | 126 | 7.4s |  |
| 606 | `key_input_numpad` | 384 | 7.4s |  |
| 607 | `large_preload_from_bytes` | 51 | 11.0s |  |
| 608 | `large_preload_from_url` | 27 | 9.5s |  |
| 609 | `large_preload_image_from_bytes` | 25 | 7.8s |  |
| 610 | `lazyinit` | 17 | 7.3s |  |
| 611 | `lessequals` | 512 | 11.3s |  |
| 612 | `lessthan` | 512 | 11.2s |  |
| 613 | `loader_bitmap_transparency` | 14 | 7.3s |  |
| 614 | `loader_bytes_unknown_content` | 14 | 7.3s |  |
| 615 | `loader_child_getdefinition` | 5 | 7.5s |  |
| 616 | `loader_duplicate_coerce` | 3 | 7.6s |  |
| 617 | `loader_duplicate_coerce_new_domain` | 4 | 7.4s |  |
| 618 | `loader_error_in_root_ctor` | 4 | 7.5s |  |
| 619 | `loader_events` | 92 | 7.8s |  |
| 620 | `loader_image` | 8 | 7.4s |  |
| 621 | `loader_jpegxr` | 2 | 27.1s |  |
| 622 | `loader_jpegxr_alpha` | 1 | 7.3s |  |
| 623 | `loader_loadbytes_events` | 30 | 7.9s |  |
| 624 | `loader_loadbytes_invalid_png` | 4 | 7.5s |  |
| 625 | `loader_loadbytes_url` | 12 | 7.6s |  |
| 626 | `loader_loaderurl` | 6 | 7.8s |  |
| 627 | `loader_method` | 85 | 7.4s |  |
| 628 | `loader_noninteractive_try_click_root` | 5 | 27.1s |  |
| 629 | `loader_reuse` | 38 | 7.6s |  |
| 630 | `loader_try_click_root` | 16 | 7.5s |  |
| 631 | `loader_unknown_content` | 24 | 7.4s |  |
| 632 | `loader_visibility_interactive` | 1 | 7.3s |  |
| 633 | `loaderinfo_events` | 7 | 7.2s |  |
| 634 | `loaderinfo_loadurl` | 12 | 7.2s |  |
| 635 | `loaderinfo_more` | 6 | 7.5s |  |
| 636 | `loaderinfo_properties` | 18 | 26.9s |  |
| 637 | `loaderinfo_properties_not_loaded` | 23 | 7.4s |  |
| 638 | `loaderinfo_quine` | 1005 | 7.3s |  |
| 639 | `loaderinfo_root` | 10 | 7.4s |  |
| 640 | `loaderinfo_root_allows` | 2 | 7.4s |  |
| 641 | `localconnection` | 890 | 9.4s |  |
| 642 | `localconnection_send` | 4 | 7.2s |  |
| 643 | `lshift` | 1058 | 19.0s |  |
| 644 | `mask_reapply` | 1 | 26.4s |  |
| 645 | `math` | 497 | 7.4s |  |
| 646 | `matrix` | 338 | 18.2s |  |
| 647 | `matrix3d` | 57 | 7.9s |  |
| 648 | `matrix3d_append` | 16 | 7.3s |  |
| 649 | `matrix3d_append_prepend_scale` | 86 | 7.3s |  |
| 650 | `matrix3d_append_prepend_translation` | 42 | 7.2s |  |
| 651 | `matrix3d_compose` | 34 | 7.4s |  |
| 652 | `matrix3d_constructor_clone` | 15 | 7.1s |  |
| 653 | `matrix3d_copy_column` | 83 | 7.4s |  |
| 654 | `matrix3d_copy_from` | 19 | 7.2s |  |
| 655 | `matrix3d_copy_raw_data_from` | 55 | 2.5s |  |
| 656 | `matrix3d_copy_raw_data_to` | 38 | 7.3s |  |
| 657 | `matrix3d_copy_row` | 83 | 7.0s |  |
| 658 | `matrix3d_copy_to_matrix3d` | 19 | 7.2s |  |
| 659 | `matrix3d_determinant` | 182 | 7.3s |  |
| 660 | `matrix3d_interpolate` | 21 | 7.4s |  |
| 661 | `matrix3d_invert` | 18 | 7.2s |  |
| 662 | `matrix3d_position` | 19 | 7.2s |  |
| 663 | `matrix3d_precision` | 28 | 7.3s |  |
| 664 | `matrix3d_prepend` | 16 | 7.0s |  |
| 665 | `matrix3d_raw_data` | 33 | 7.2s |  |
| 666 | `matrix3d_transform_vector` | 52 | 7.5s |  |
| 667 | `matrix3d_transpose` | 5 | 7.1s |  |
| 668 | `method_association` | 5 | 7.2s |  |
| 669 | `method_without_body` | 3 | 26.2s |  |
| 670 | `missing_external_interface` | 10 | 7.2s |  |
| 671 | `modulo` | 1058 | 19.1s |  |
| 672 | `morph_shape` | 2 | 26.4s |  |
| 673 | `mouse_children` | 192 | 26.4s |  |
| 674 | `mouse_click_events` | 90 | 26.2s |  |
| 675 | `mouse_double_click_events` | 188 | 7.2s |  |
| 676 | `mouse_empty_parent` | 4 | 7.2s |  |
| 677 | `mouse_over_while_dragging` | 3 | 7.3s |  |
| 678 | `mouse_pick_avm1_root` | 2 | 26.6s |  |
| 679 | `mouse_pick_button_mode` | 2 | 2.4s |  |
| 680 | `mouse_pick_dobj_mask` | 4 | 7.2s |  |
| 681 | `mouse_pick_masking` | 7 | 26.8s |  |
| 682 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.5s |  |
| 683 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.3s |  |
| 684 | `mouse_pick_text` | 8 | 7.4s |  |
| 685 | `mouse_sibling` | 8 | 7.3s |  |
| 686 | `mouse_wheel_events` | 36 | 27.5s |  |
| 687 | `mouseevent_constr` | 66 | 7.2s |  |
| 688 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 689 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 690 | `movieclip_addframescript` | 3 | 26.9s |  |
| 691 | `movieclip_addframescript_error` | 9 | 7.2s |  |
| 692 | `movieclip_child_property` | 16 | 7.3s |  |
| 693 | `movieclip_constr` | 21 | 7.2s |  |
| 694 | `movieclip_currentlabels` | 17 | 26.7s |  |
| 695 | `movieclip_currentlabels_dupes1` | 46 | 26.8s |  |
| 696 | `movieclip_currentlabels_dupes2` | 30 | 7.2s |  |
| 697 | `movieclip_currentlabels_dupes3` | 67 | 7.2s |  |
| 698 | `movieclip_currentscene` | 12 | 26.7s |  |
| 699 | `movieclip_dispatchevent` | 430 | 7.3s |  |
| 700 | `movieclip_dispatchevent_cancel` | 102 | 7.1s |  |
| 701 | `movieclip_dispatchevent_handlerorder` | 251 | 7.2s |  |
| 702 | `movieclip_dispatchevent_selfadd` | 80 | 7.3s |  |
| 703 | `movieclip_dispatchevent_target` | 899 | 7.3s |  |
| 704 | `movieclip_displayevents` | 96 | 26.9s |  |
| 705 | `movieclip_displayevents_clickgoto` | 676 | 27.0s |  |
| 706 | `movieclip_displayevents_clickgoto2` | 2001 | 7.7s |  |
| 707 | `movieclip_displayevents_clickplay` | 575 | 7.5s |  |
| 708 | `movieclip_displayevents_clicksymbol` | 562 | 7.4s |  |
| 709 | `movieclip_displayevents_constructframegoto` | 140 | 7.7s |  |
| 710 | `movieclip_displayevents_constructframeplay` | 50 | 7.5s |  |
| 711 | `movieclip_displayevents_constructframesymbol` | 144 | 7.4s |  |
| 712 | `movieclip_displayevents_dblhandler` | 21 | 7.4s |  |
| 713 | `movieclip_displayevents_enterframegoto` | 149 | 7.3s |  |
| 714 | `movieclip_displayevents_enterframeplay` | 48 | 7.3s |  |
| 715 | `movieclip_displayevents_enterframesymbol` | 149 | 7.5s |  |
| 716 | `movieclip_displayevents_exitframegoto` | 106 | 7.3s |  |
| 717 | `movieclip_displayevents_exitframeplay` | 44 | 7.3s |  |
| 718 | `movieclip_displayevents_exitframesymbol` | 135 | 7.4s |  |
| 719 | `movieclip_displayevents_looping` | 63 | 26.6s |  |
| 720 | `movieclip_displayevents_stopped` | 113 | 7.5s |  |
| 721 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 722 | `movieclip_displayevents_timeline` | 128 | 7.6s |  |
| 723 | `movieclip_drawrect` | 54 | 7.5s |  |
| 724 | `movieclip_frameconstruct_skipped` | 9 | 7.7s |  |
| 725 | `movieclip_goto_during_frame_script` | 15 | 27.2s |  |
| 726 | `movieclip_goto_overwrite` | 14 | 7.8s |  |
| 727 | `movieclip_goto_scene_last_frame_int` | 1 | 27.2s |  |
| 728 | `movieclip_goto_scene_last_frame_label` | 1 | 7.3s |  |
| 729 | `movieclip_gotoandplay` | 15 | 27.1s |  |
| 730 | `movieclip_gotoandstop` | 13 | 7.4s |  |
| 731 | `movieclip_gotoandstop_children` | 4 | 7.5s |  |
| 732 | `movieclip_gotoandstop_framescripts1` | 4 | 7.5s |  |
| 733 | `movieclip_gotoandstop_framescripts2` | 4 | 2.5s |  |
| 734 | `movieclip_gotoandstop_framescripts_self` | 7 | 27.0s |  |
| 735 | `movieclip_gotoandstop_queueing` | 12 | 27.1s |  |
| 736 | `movieclip_hittest` | 67 | 7.6s |  |
| 737 | `movieclip_next_frame` | 2 | 7.4s |  |
| 738 | `movieclip_next_scene` | 6 | 27.1s |  |
| 739 | `movieclip_play` | 3 | 7.5s |  |
| 740 | `movieclip_prev_frame` | 3 | 7.3s |  |
| 741 | `movieclip_prev_scene` | 7 | 7.7s |  |
| 742 | `movieclip_properties` | 79 | 28.4s |  |
| 743 | `movieclip_queued_noop_goto_swf10` | 9 | 7.7s |  |
| 744 | `movieclip_queued_noop_goto_swf9` | 7 | 0.7s |  |
| 745 | `movieclip_scenes` | 11 | 7.6s |  |
| 746 | `movieclip_soundtransform` | 831 | 30.1s |  |
| 747 | `movieclip_stop` | 1 | 7.6s |  |
| 748 | `movieclip_super_is_symbol` | 20 | 8.0s |  |
| 749 | `movieclip_symbol_constr` | 8 | 7.8s |  |
| 750 | `movieclip_text_mousedown` | 1 | 7.8s |  |
| 751 | `movieclip_willtrigger` | 5 | 7.7s |  |
| 752 | `multiply` | 1058 | 19.3s |  |
| 753 | `namespace_constr` | 253 | 8.0s |  |
| 754 | `namespace_constr_args` | 1 | 7.5s |  |
| 755 | `namespace_enumeration_order` | 7 | 7.6s |  |
| 756 | `nan_scale` | 9 | 7.6s |  |
| 757 | `native_menu_basic` | 19 | 9.7s |  |
| 758 | `navigateToURL_target_normalize` | 107 | 29.3s |  |
| 759 | `negate` | 30 | 7.4s |  |
| 760 | `negative_volume_panned` | 0 | 7.7s |  |
| 761 | `nested_iteration` | 11 | 7.4s |  |
| 762 | `net_getClassByAlias` | 3 | 7.4s |  |
| 763 | `net_navigateToURL` | 57 | 7.4s |  |
| 764 | `net_stream_play_options` | 6 | 7.4s |  |
| 765 | `netconnection_close` | 55 | 6.8s |  |
| 766 | `netconnection_properties` | 78 | 6.9s |  |
| 767 | `netconnection_send_remote` | 50 | 28.6s |  |
| 768 | `netconnection_serialize_arrays` | 6 | 6.8s |  |
| 769 | `netfilterevent` | 10 | 6.7s |  |
| 770 | `netstream_client` | 10 | 6.8s |  |
| 771 | `netstream_connect` | 7 | 6.7s |  |
| 772 | `netstream_flv_date` | 4 | 6.9s |  |
| 773 | `newactivation_in_script_init` | 3 | 6.8s |  |
| 774 | `newclass_mismatched` | 4 | 2.0s |  |
| 775 | `newclass_twice` | 3 | 6.7s |  |
| 776 | `nonconflicting_declarations` | 0 | 6.7s |  |
| 777 | `null_void_types` | 8 | 6.8s |  |
| 778 | `number_autoconv` | 21 | 6.8s |  |
| 779 | `number_autoconv_amf` | 132 | 6.7s |  |
| 780 | `number_autoconv_array_sort_32bit` | 1 | 6.6s |  |
| 781 | `number_constr` | 58 | 6.8s |  |
| 782 | `number_convert_edge_cases` | 180 | 25.7s |  |
| 783 | `number_toexponential` | 378 | 6.8s |  |
| 784 | `number_toexponential2` | 35 | 6.7s |  |
| 785 | `number_tofixed` | 378 | 6.7s |  |
| 786 | `number_toprecision` | 350 | 6.8s |  |
| 787 | `obfuscated_class_names` | 3 | 6.7s |  |
| 788 | `object_enumeration` | 10 | 2.0s |  |
| 789 | `object_prototype` | 4 | 6.7s |  |
| 790 | `object_to_locale_string` | 2 | 6.7s |  |
| 791 | `object_to_string` | 2 | 6.6s |  |
| 792 | `object_value_of` | 2 | 1.8s |  |
| 793 | `op_coerce` | 54 | 1.9s |  |
| 794 | `op_coerce_x` | 54 | 6.7s |  |
| 795 | `op_escxattr` | 2 | 6.7s |  |
| 796 | `op_escxelem` | 2 | 6.7s |  |
| 797 | `op_lookupswitch` | 4 | 6.7s |  |
| 798 | `optimize_coerce` | 1 | 6.7s |  |
| 799 | `orphan_movie_complex` | 80 | 7.1s |  |
| 800 | `orphan_movie_reorder` | 111 | 7.0s |  |
| 801 | `orphan_removeobject` | 636 | 25.8s |  |
| 802 | `package_namespace` | 7 | 6.6s |  |
| 803 | `param_default_value_has_zero_cpool_index` | 1 | 6.7s |  |
| 804 | `parent_early_access_child` | 16 | 25.5s |  |
| 805 | `parse_float` | 81 | 6.8s |  |
| 806 | `parse_float_swf10` | 81 | 6.6s |  |
| 807 | `parse_int` | 135 | 7.1s |  |
| 808 | `perspective_projection` | 1443 | 25.3s |  |
| 809 | `perspective_projection_basic` | 40 | 6.6s |  |
| 810 | `pixelbender_ceil` | 77 | 6.8s |  |
| 811 | `pixelbender_conditional` | 138 | 7.0s |  |
| 812 | `pixelbender_conversions` | 270 | 6.9s |  |
| 813 | `pixelbender_dithering` | 8 | 29.4s |  |
| 814 | `pixelbender_div` | 36 | 6.8s |  |
| 815 | `pixelbender_effect_BlurredFocus` | 0 | 32.7s |  |
| 816 | `pixelbender_effect_glassDisplace` | 0 | 11.8s |  |
| 817 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 28.1s |  |
| 818 | `pixelbender_effect_smudge` | 0 | 9.7s |  |
| 819 | `pixelbender_effect_tintype` | 0 | 8.9s |  |
| 820 | `pixelbender_effect_twirl` | 0 | 10.2s |  |
| 821 | `pixelbender_eof` | 7 | 6.7s |  |
| 822 | `pixelbender_images` | 0 | 8.7s |  |
| 823 | `pixelbender_input` | 103 | 25.9s |  |
| 824 | `pixelbender_logicalnot` | 20 | 6.7s |  |
| 825 | `pixelbender_malformed_data` | 190 | 25.9s |  |
| 826 | `pixelbender_multiple_out_params` | 1 | 6.7s |  |
| 827 | `pixelbender_no_out_param` | 6 | 6.7s |  |
| 828 | `pixelbender_outputs` | 13 | 6.8s |  |
| 829 | `pixelbender_padding_bytes` | 22 | 6.7s |  |
| 830 | `pixelbender_param_qualifier` | 512 | 6.8s |  |
| 831 | `pixelbender_parameters` | 1563 | 7.0s |  |
| 832 | `pixelbender_parameters_bool` | 240 | 6.9s |  |
| 833 | `pixelbender_parameters_int_vs_bool` | 54 | 6.8s |  |
| 834 | `pixelbender_parse_errors` | 6 | 6.7s |  |
| 835 | `pixelbender_rsqrt` | 24 | 6.7s |  |
| 836 | `pixelbender_select_kinds` | 8 | 6.8s |  |
| 837 | `pixelbender_shaderdata` | 49 | 6.7s |  |
| 838 | `pixelbender_shaderdata_setter` | 99 | 7.0s |  |
| 839 | `pixelbender_sign` | 60 | 6.9s |  |
| 840 | `pixelbender_vector_output` | 11 | 6.9s |  |
| 841 | `place_and_lookup/swf10` | 33 | 2.0s |  |
| 842 | `place_and_lookup/swf9` | 33 | 0.5s |  |
| 843 | `place_multiple` | 17 | 7.5s |  |
| 844 | `place_object_replace` | 9 | 26.7s |  |
| 845 | `place_object_replace_2` | 24 | 27.0s |  |
| 846 | `place_object_same_depth_frame` | 1 | 7.4s |  |
| 847 | `point` | 132 | 7.9s |  |
| 848 | `primitive_edge_cases` | 1 | 7.3s |  |
| 849 | `primitive_keys` | 54 | 7.4s |  |
| 850 | `primitive_toString` | 277 | 7.5s |  |
| 851 | `primitive_valueOf` | 285 | 7.2s |  |
| 852 | `print_job_options` | 3 | 7.3s |  |
| 853 | `property_is_enumerable` | 114 | 8.0s |  |
| 854 | `property_is_enumerable_reset` | 23 | 7.3s |  |
| 855 | `property_priority` | 22 | 7.7s |  |
| 856 | `property_priority_chained` | 4 | 7.3s |  |
| 857 | `property_priority_definition_names_order` | 2 | 7.5s |  |
| 858 | `property_priority_three_level` | 6 | 7.5s |  |
| 859 | `propertyisenumerable_namespaces` | 6 | 7.3s |  |
| 860 | `prototype_set_null` | 7 | 7.3s |  |
| 861 | `proxy_callproperty` | 24 | 7.3s |  |
| 862 | `proxy_deleteproperty` | 64 | 7.4s |  |
| 863 | `proxy_enumeration` | 34 | 7.3s |  |
| 864 | `proxy_getproperty` | 77 | 7.4s |  |
| 865 | `proxy_hasownproperty` | 8 | 7.3s |  |
| 866 | `proxy_hasproperty` | 32 | 7.4s |  |
| 867 | `proxy_not_overridden` | 54 | 7.4s |  |
| 868 | `proxy_serialize` | 9 | 7.4s |  |
| 869 | `proxy_setproperty` | 42 | 7.4s |  |
| 870 | `qname_as_lazy_name_attribute_multiname` | 1 | 2.4s |  |
| 871 | `qname_constr` | 32 | 7.4s |  |
| 872 | `qname_constr_namespace` | 24 | 7.4s |  |
| 873 | `qname_enumeration` | 9 | 7.3s |  |
| 874 | `qname_indexing` | 23 | 7.4s |  |
| 875 | `qname_tostring` | 25 | 7.4s |  |
| 876 | `qname_valueof` | 29 | 7.4s |  |
| 877 | `rectangle` | 1094 | 8.0s |  |
| 878 | `regexp_constr` | 148 | 7.6s |  |
| 879 | `regexp_exec` | 19 | 7.3s |  |
| 880 | `regexp_extended` | 47 | 7.3s |  |
| 881 | `regexp_multiargs` | 1 | 7.2s |  |
| 882 | `regexp_test` | 27 | 7.4s |  |
| 883 | `regexp_toString` | 10 | 7.4s |  |
| 884 | `register_script_refresh` | 35 | 27.2s |  |
| 885 | `remove_child_clear_field` | 88 | 21.3s |  |
| 886 | `remove_dobj` | 3 | 5.7s |  |
| 887 | `resolve_order` | 4 | 5.7s |  |
| 888 | `responder_null_callbacks` | 1 | 5.7s |  |
| 889 | `rng` | 1 | 6.8s |  |
| 890 | `rootless` | 42 | 5.7s |  |
| 891 | `rshift` | 1058 | 14.6s |  |
| 892 | `rtqname_not_namespace` | 12 | 5.7s |  |
| 893 | `sandbox_type_inherited` | 2 | 6.1s |  |
| 894 | `sandbox_type_local_file` | 1 | 5.7s |  |
| 895 | `sandbox_type_local_network` | 1 | 5.5s |  |
| 896 | `scene_constr` | 8 | 5.8s |  |
| 897 | `scope_optimizations` | 4 | 5.7s |  |
| 898 | `scopes_dont_cache/order-1` | 1 | 21.1s |  |
| 899 | `scopes_dont_cache/order-2` | 1 | 0.3s |  |
| 900 | `security_domain_current` | 2 | 5.7s |  |
| 901 | `selection` | 239 | 6.1s |  |
| 902 | `set_local_0` | 31 | 5.8s |  |
| 903 | `set_property_is_enumerable` | 85 | 6.1s |  |
| 904 | `shaderparameter_value` | 4 | 5.7s |  |
| 905 | `shape_drawrect` | 54 | 5.8s |  |
| 906 | `shared_object_no_root` | 3 | 5.8s |  |
| 907 | `simplebutton_added_to_stage` | 45 | 21.1s |  |
| 908 | `simplebutton_childevents` | 86 | 21.3s |  |
| 909 | `simplebutton_childevents_nested` | 54 | 6.0s |  |
| 910 | `simplebutton_childevents_sprite` | 13 | 5.8s |  |
| 911 | `simplebutton_childprops` | 144 | 6.0s |  |
| 912 | `simplebutton_childshuffle` | 23 | 5.7s |  |
| 913 | `simplebutton_constr` | 36 | 5.9s |  |
| 914 | `simplebutton_constr_childevents` | 48 | 6.0s |  |
| 915 | `simplebutton_constr_params` | 42 | 5.8s |  |
| 916 | `simplebutton_mouseenabled` | 26 | 5.7s |  |
| 917 | `simplebutton_multi_children` | 19 | 5.9s |  |
| 918 | `simplebutton_soundtransform` | 887 | 22.9s |  |
| 919 | `simplebutton_structure` | 27 | 5.9s |  |
| 920 | `simplebutton_symbolclass` | 68 | 6.1s |  |
| 921 | `slot_disp_id_shared_numbering` | 1 | 20.9s |  |
| 922 | `slots_force_autoassigned` | 1 | 7.2s |  |
| 923 | `socket_after_disconnect` | 1 | 7.1s |  |
| 924 | `socket_close` | 2 | 7.1s |  |
| 925 | `socket_connect` | 4 | 7.2s |  |
| 926 | `socket_errors` | 56 | 7.7s |  |
| 927 | `socket_read_big` | 48 | 7.2s |  |
| 928 | `socket_read_little` | 48 | 2.3s |  |
| 929 | `socket_read_write_object` | 8 | 7.1s |  |
| 930 | `socket_write_big` | 15 | 7.6s |  |
| 931 | `socket_write_little` | 14 | 7.2s |  |
| 932 | `sound_constructor_with_args` | 6 | 7.3s |  |
| 933 | `sound_embeddedprops` | 26 | 7.3s |  |
| 934 | `sound_play` | 19 | 7.4s |  |
| 935 | `sound_rootless` | 7 | 7.2s |  |
| 936 | `sound_valueof` | 33 | 7.3s |  |
| 937 | `soundchannel_soundtransform` | 835 | 28.5s |  |
| 938 | `soundchannel_soundtransform_exists` | 5 | 26.2s |  |
| 939 | `soundchannel_stop` | 8 | 26.4s |  |
| 940 | `soundmixer_buffertime` | 5 | 7.1s |  |
| 941 | `soundmixer_soundtransform` | 900 | 9.1s |  |
| 942 | `soundmixer_stopall` | 6 | 26.1s |  |
| 943 | `soundtransform` | 442 | 12.8s |  |
| 944 | `space_justifier_clone` | 12 | 7.1s |  |
| 945 | `sprite_with_frames` | 0 | 26.3s |  |
| 946 | `stage3d_agal_cross_product` | 0 | 9.6s |  |
| 947 | `stage3d_agal_upload_errors` | 66 | 9.8s |  |
| 948 | `stage3d_bitmap` | 0 | 31.0s |  |
| 949 | `stage3d_blend` | 81 | 28.7s |  |
| 950 | `stage3d_context3d_string_args` | 158 | 8.2s |  |
| 951 | `stage3d_errors` | 7 | 7.3s |  |
| 952 | `stage3d_errors_atf` | 3 | 8.6s |  |
| 953 | `stage3d_errors_swf_29` | 6 | 7.5s |  |
| 954 | `stage3d_float1_index` | 0 | 29.1s |  |
| 955 | `stage3d_fractal` | 0 | 29.3s |  |
| 956 | `stage3d_ignore_sampler_override` | 0 | 29.5s |  |
| 957 | `stage3d_multistage_triangle` | 3 | 10.0s |  |
| 958 | `stage3d_program_constants_bytearray_be` | 0 | 31.6s |  |
| 959 | `stage3d_program_constants_bytearray_le` | 0 | 31.0s |  |
| 960 | `stage3d_program_constants_invalid_input` | 21 | 8.2s |  |
| 961 | `stage3d_raytrace` | 0 | 33.8s |  |
| 962 | `stage3d_rotating_cube` | 0 | 10.6s |  |
| 963 | `stage3d_sampler` | 0 | 9.9s |  |
| 964 | `stage3d_sampler_partial_upload` | 0 | 9.8s |  |
| 965 | `stage3d_stencil` | 0 | 29.7s |  |
| 966 | `stage3d_texture` | 0 | 15.3s |  |
| 967 | `stage3d_texture_bytearray` | 0 | 11.5s |  |
| 968 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.8s |  |
| 969 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 12.0s |  |
| 970 | `stage3d_triangle` | 0 | 10.3s |  |
| 971 | `stage3d_triangle_bytes4` | 0 | 10.3s |  |
| 972 | `stage3d_triangle_float1` | 0 | 10.2s |  |
| 973 | `stage3d_triangle_index_upload` | 0 | 10.2s |  |
| 974 | `stage3d_x_y` | 22 | 7.8s |  |
| 975 | `stage_access` | 10 | 7.8s |  |
| 976 | `stage_display_state` | 6 | 7.7s |  |
| 977 | `stage_displayobject_properties` | 24 | 7.7s |  |
| 978 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.7s |  |
| 979 | `stage_framerate_nan` | 7 | 7.9s |  |
| 980 | `stage_framerate_negative` | 6 | 7.8s |  |
| 981 | `stage_framerate_zero` | 6 | 7.7s |  |
| 982 | `stage_invalidate` | 38 | 8.0s |  |
| 983 | `stage_loaderinfo_properties` | 24 | 29.0s |  |
| 984 | `stage_mousechildren` | 2 | 7.6s |  |
| 985 | `stage_mouseenabled` | 15 | 7.6s |  |
| 986 | `stage_overriden_setters` | 31 | 7.8s |  |
| 987 | `stage_properties` | 30 | 7.6s |  |
| 988 | `stage_properties2` | 213 | 7.8s |  |
| 989 | `stage_scale_factor` | 12 | 33.2s |  |
| 990 | `stage_stage3Ds_vector` | 1 | 7.6s |  |
| 991 | `static_length` | 24 | 7.9s |  |
| 992 | `static_text` | 3 | 7.8s |  |
| 993 | `static_var_with_this_in_ctor` | 2 | 7.7s |  |
| 994 | `statictext_text` | 8 | 7.8s |  |
| 995 | `stored_properties` | 11 | 2.6s |  |
| 996 | `strict_equality` | 34 | 7.8s |  |
| 997 | `string_call` | 13 | 7.8s |  |
| 998 | `string_case` | 23 | 7.8s |  |
| 999 | `string_char_at` | 27 | 7.9s |  |
| 1000 | `string_char_code_at` | 28 | 2.5s |  |
| 1001 | `string_concat_fromcharcode` | 37 | 8.0s |  |
| 1002 | `string_constr` | 25 | 7.8s |  |
| 1003 | `string_indexof_lastindexof` | 87 | 7.5s |  |
| 1004 | `string_length` | 16 | 7.1s |  |
| 1005 | `string_locale_compare` | 39 | 7.5s |  |
| 1006 | `string_match` | 51 | 7.5s |  |
| 1007 | `string_relational_compare` | 4 | 7.3s |  |
| 1008 | `string_replace` | 51 | 7.4s |  |
| 1009 | `string_search` | 41 | 7.3s |  |
| 1010 | `string_slice_substr_substring` | 170 | 9.5s |  |
| 1011 | `string_split` | 29 | 7.5s |  |
| 1012 | `string_substr_negative` | 21 | 7.4s |  |
| 1013 | `string_substr_weird` | 182 | 7.7s |  |
| 1014 | `stylesheet` | 221 | 8.2s |  |
| 1015 | `stylesheet_parse_color` | 69 | 7.6s |  |
| 1016 | `stylesheet_transform` | 307 | 7.9s |  |
| 1017 | `sub_super_same_field` | 12 | 2.6s |  |
| 1018 | `subclass_superclass_linked_symbol` | 4 | 8.1s |  |
| 1019 | `subtract` | 1058 | 19.4s |  |
| 1020 | `super_get_call` | 12 | 7.3s |  |
| 1021 | `supercall_two_classobjects` | 2 | 7.2s |  |
| 1022 | `supercalls_coerce` | 8 | 2.5s |  |
| 1023 | `supercalls_weird` | 2 | 7.2s |  |
| 1024 | `superinterface_call` | 20 | 7.2s |  |
| 1025 | `superinterface_instanceof` | 18 | 7.2s |  |
| 1026 | `swf8` | 1 | 7.1s |  |
| 1027 | `swf_10_queued_goto_scripts_construct` | 52 | 26.7s |  |
| 1028 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 1029 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 1030 | `swf_9_queued_goto_scripts` | 6 | 26.6s |  |
| 1031 | `swf_9_queued_goto_scripts_construct` | 28 | 0.7s |  |
| 1032 | `swf_9_versioning` | 2 | 7.2s |  |
| 1033 | `swf_wrong_frame_count` | 38 | 7.9s |  |
| 1034 | `swf_wrong_frame_count_isplaying` | 22 | 7.2s |  |
| 1035 | `symbol_class_binary_data` | 8 | 7.3s |  |
| 1036 | `symbol_class_conflict` | 4 | 7.5s |  |
| 1037 | `symbol_class_root_not_zero` | 1 | 7.2s |  |
| 1038 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 1039 | `system_exit` | 3 | 2.4s |  |
| 1040 | `system_setclipboard_null` | 1 | 7.3s |  |
| 1041 | `tab_ordering_arrows` | 998 | 20.6s |  |
| 1042 | `tab_ordering_automatic_advanced` | 184 | 0.9s |  |
| 1043 | `tab_ordering_automatic_basic` | 45 | 4.7s |  |
| 1044 | `tab_ordering_children` | 116 | 4.6s |  |
| 1045 | `tab_ordering_custom_basic` | 34 | 5.1s |  |
| 1046 | `tab_ordering_stage_tab_children` | 32 | 4.7s |  |
| 1047 | `tab_ordering_stage_tab_children_remove_root` | 5 | 4.7s |  |
| 1048 | `tab_ordering_tabbable` | 47 | 4.7s |  |
| 1049 | `tabstop_properties` | 105 | 4.8s |  |
| 1050 | `text_element_basic` | 34 | 4.7s |  |
| 1051 | `text_engine_fontdescription` | 27 | 4.5s |  |
| 1052 | `text_engine_groupelement` | 64 | 4.8s |  |
| 1053 | `text_run` | 7 | 4.8s |  |
| 1054 | `textblock_createline_errors` | 23 | 4.7s |  |
| 1055 | `textblock_createline_fte` | 9 | 4.9s |  |
| 1056 | `textblock_properties` | 118 | 5.1s |  |
| 1057 | `textbox_click` | 37 | 20.1s |  |
| 1058 | `textfield_event` | 66 | 4.8s |  |
| 1059 | `textfield_focusin_event` | 9 | 5.0s |  |
| 1060 | `textfield_input_dead_keys_windows` | 15 | 4.8s |  |
| 1061 | `textfield_input_events` | 25 | 12.7s |  |
| 1062 | `textfield_unload` | 39 | 16.6s |  |
| 1063 | `textformat` | 1134 | 4.7s |  |
| 1064 | `textformat_display` | 14 | 4.8s |  |
| 1065 | `textformat_font_max_length` | 4 | 4.6s |  |
| 1066 | `textline_inapplicable_properties` | 10 | 4.5s |  |
| 1067 | `textline_name` | 1 | 4.6s |  |
| 1068 | `textline_raw_text_length` | 30 | 4.5s |  |
| 1069 | `textline_splitting_basic` | 76 | 4.6s |  |
| 1070 | `textline_throwerror` | 30 | 4.6s |  |
| 1071 | `textline_validity` | 162 | 4.7s |  |
| 1072 | `throw` | 3 | 4.6s |  |
| 1073 | `timeline_scripts` | 3 | 19.6s |  |
| 1074 | `timer` | 90 | 4.8s |  |
| 1075 | `timer_events` | 3 | 4.7s |  |
| 1076 | `timer_finished` | 11 | 1.0s |  |
| 1077 | `timer_invalid_delay` | 30 | 4.7s |  |
| 1078 | `timer_reset` | 8 | 7.5s |  |
| 1079 | `timer_setdelay` | 5 | 7.3s |  |
| 1080 | `trace` | 12 | 7.2s |  |
| 1081 | `truthiness` | 30 | 7.3s |  |
| 1082 | `try_catch` | 11 | 7.4s |  |
| 1083 | `try_catch_typed` | 12 | 7.4s |  |
| 1084 | `typeof` | 30 | 7.3s |  |
| 1085 | `uint_constr` | 92 | 7.5s |  |
| 1086 | `uint_tofixed` | 1215 | 7.2s |  |
| 1087 | `uint_toprecision` | 1125 | 7.5s |  |
| 1088 | `uint_tostring` | 3375 | 7.6s |  |
| 1089 | `uncaught_error_basic` | 2 | 7.3s |  |
| 1090 | `unchecked_function` | 15 | 7.3s |  |
| 1091 | `unescape` | 28 | 7.3s |  |
| 1092 | `url_loader` | 25 | 7.4s |  |
| 1093 | `url_vars` | 27 | 7.5s |  |
| 1094 | `urlrequest` | 18 | 7.3s |  |
| 1095 | `urlstream_basic` | 5 | 7.3s |  |
| 1096 | `urshift` | 1058 | 19.4s |  |
| 1097 | `utils3d` | 7 | 2.4s |  |
| 1098 | `vector3d` | 397 | 11.9s |  |
| 1099 | `vector3d_near_equals` | 80 | 7.4s |  |
| 1100 | `vector_class` | 36 | 7.8s |  |
| 1101 | `vector_class_call` | 11 | 7.5s |  |
| 1102 | `vector_coercion` | 66 | 8.1s |  |
| 1103 | `vector_concat` | 90 | 7.9s |  |
| 1104 | `vector_constr` | 107 | 8.0s |  |
| 1105 | `vector_enumeration` | 5 | 7.2s |  |
| 1106 | `vector_every` | 92 | 8.1s |  |
| 1107 | `vector_filter` | 95 | 8.2s |  |
| 1108 | `vector_holes` | 24 | 7.4s |  |
| 1109 | `vector_indexof` | 302 | 12.1s |  |
| 1110 | `vector_insertat` | 270 | 8.5s |  |
| 1111 | `vector_int_access` | 4 | 7.2s |  |
| 1112 | `vector_int_delete` | 11 | 7.3s |  |
| 1113 | `vector_join` | 58 | 7.7s |  |
| 1114 | `vector_lastindexof` | 302 | 7.2s |  |
| 1115 | `vector_legacy` | 10 | 7.3s |  |
| 1116 | `vector_map` | 85 | 8.0s |  |
| 1117 | `vector_object_final` | 1 | 7.2s |  |
| 1118 | `vector_object_toString` | 10 | 0.4s |  |
| 1119 | `vector_pushpop` | 255 | 0.4s |  |
| 1120 | `vector_reborrow_bug` | 10 | 0.4s |  |
| 1121 | `vector_removeat` | 172 | 0.4s |  |
| 1122 | `vector_reverse` | 232 | 0.4s |  |
| 1123 | `vector_shiftunshift` | 252 | 0.4s |  |
| 1124 | `vector_slice` | 331 | 0.4s |  |
| 1125 | `vector_sort` | 905 | 0.4s |  |
| 1126 | `vector_splice` | 693 | 0.4s |  |
| 1127 | `vector_splice_fixed_bug_compat` | 4 | 0.4s |  |
| 1128 | `vector_tostring` | 79 | 0.4s |  |
| 1129 | `verification` | 8 | 0.4s |  |
| 1130 | `verify_abnormal_loop` | 1 | 0.4s |  |
| 1131 | `verify_dxns_without_flag` | 3 | 0.5s |  |
| 1132 | `verify_exception_target_two_jumps` | 1 | 0.4s |  |
| 1133 | `verify_exception_targets_edge_case` | 1 | 0.4s |  |
| 1134 | `verify_illegal_opcode` | 1 | 0.4s |  |
| 1135 | `verify_jump_to_middle_of_op` | 1 | 0.4s |  |
| 1136 | `verify_lookup_switch_edge_case` | 1 | 0.4s |  |
| 1137 | `verify_method_info_oob` | 1 | 0.4s |  |
| 1138 | `verify_stack` | 5 | 0.4s |  |
| 1139 | `verify_typecheck` | 4 | 0.4s |  |
| 1140 | `verify_unreachable_exception` | 2 | 0.4s |  |
| 1141 | `versioned_isplaying` | 2 | 0.4s |  |
| 1142 | `virtual_properties` | 16 | 0.4s |  |
| 1143 | `with` | 4 | 0.4s |  |
| 1144 | `wrong_arg_count` | 7 | 0.4s |  |
| 1145 | `xml_abstract_equality` | 36 | 0.4s |  |
| 1146 | `xml_advanced` | 52 | 0.4s |  |
| 1147 | `xml_appendchild` | 10 | 0.4s |  |
| 1148 | `xml_appendchild_swf_v21` | 13 | 0.4s |  |
| 1149 | `xml_as_attribute` | 9 | 0.4s |  |
| 1150 | `xml_attribute` | 35 | 0.4s |  |
| 1151 | `xml_attribute_name` | 40 | 0.4s |  |
| 1152 | `xml_basic` | 33 | 0.4s |  |
| 1153 | `xml_child` | 25 | 0.4s |  |
| 1154 | `xml_childindex` | 7 | 0.4s |  |
| 1155 | `xml_children` | 43 | 0.4s |  |
| 1156 | `xml_class_call` | 9 | 0.4s |  |
| 1157 | `xml_contains` | 197 | 0.4s |  |
| 1158 | `xml_copy` | 20 | 2.5s |  |
| 1159 | `xml_ctor_from_tostring` | 23 | 7.5s |  |
| 1160 | `xml_delete` | 114 | 7.3s |  |
| 1161 | `xml_descendants` | 83 | 7.2s |  |
| 1162 | `xml_duplicate_attribute` | 14 | 7.2s |  |
| 1163 | `xml_elements` | 6 | 7.2s |  |
| 1164 | `xml_equals_namespace_check` | 2 | 7.2s |  |
| 1165 | `xml_explicit_use_namespace` | 5 | 2.4s |  |
| 1166 | `xml_getdescendants_qname` | 21 | 7.2s |  |
| 1167 | `xml_has_property_via_in` | 26 | 7.2s |  |
| 1168 | `xml_hasownproperty` | 6 | 7.2s |  |
| 1169 | `xml_ignore_white` | 6 | 7.2s |  |
| 1170 | `xml_length` | 2 | 7.2s |  |
| 1171 | `xml_list_as_attribute` | 9 | 6.9s |  |
| 1172 | `xml_list_concat` | 20 | 7.2s |  |
| 1173 | `xml_list_ctor_errors` | 34 | 7.2s |  |
| 1174 | `xml_list_delete_clear_parent` | 6 | 7.1s |  |
| 1175 | `xml_list_enumerate` | 4 | 7.2s |  |
| 1176 | `xml_methods_settings` | 3 | 7.1s |  |
| 1177 | `xml_mismatched_tag` | 37 | 7.2s |  |
| 1178 | `xml_namespace` | 39 | 7.1s |  |
| 1179 | `xml_namespace_methods` | 245 | 7.2s |  |
| 1180 | `xml_namespaced_property` | 7 | 7.1s |  |
| 1181 | `xml_no_namespace` | 1 | 7.2s |  |
| 1182 | `xml_nodekind` | 3 | 7.1s |  |
| 1183 | `xml_normalize` | 35 | 7.2s |  |
| 1184 | `xml_notification_bubbling` | 361 | 7.1s |  |
| 1185 | `xml_parent` | 8 | 7.2s |  |
| 1186 | `xml_set_children` | 17 | 7.2s |  |
| 1187 | `xml_set_name` | 34 | 7.2s |  |
| 1188 | `xml_settings` | 6 | 2.3s |  |
| 1189 | `xml_simple_complex_content` | 47 | 7.2s |  |
| 1190 | `xml_socket` | 11 | 7.2s |  |
| 1191 | `xml_text` | 7 | 7.1s |  |
| 1192 | `xml_tostring` | 6 | 7.2s |  |
| 1193 | `xml_tostring_namespace` | 12 | 6.9s |  |
| 1194 | `xml_unescaping` | 23 | 7.2s |  |
| 1195 | `xml_weird_ignores` | 54 | 7.2s |  |
| 1196 | `xml_wildcard` | 11 | 7.2s |  |
| 1197 | `xmldocument` | 254 | 7.3s |  |
| 1198 | `xmlnode` | 3540 | 7.4s |  |
| 1199 | `zero_frame_clip` | 3 | 7.5s |  |

## Ruffle-Matched Tests

**36 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 4.9s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.2s |  |
| 3 | `bitmapdata_copypixels_alpha_merge` | 4 | 4 | 7.1s |  |
| 4 | `blend_transform` | 1 | 1 | 7.1s |  |
| 5 | `bounds_mode` | 6 | 6 | 7.7s |  |
| 6 | `coerce_property` | 3 | 3 | 7.4s |  |
| 7 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 2.4s |  |
| 8 | `dictionary_weak_keys` | 1 | 1 | 17.3s |  |
| 9 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 26.2s |  |
| 10 | `edittext_device_transform_layout` | 20 | 20 | 7.5s |  |
| 11 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.6s |  |
| 12 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 7.3s |  |
| 13 | `edittext_tab_stops` | 6 | 6 | 4.9s |  |
| 14 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.5s |  |
| 15 | `error_1034_debug_string` | 19 | 19 | 6.2s |  |
| 16 | `event_handler_exception` | 4 | 4 | 6.4s |  |
| 17 | `freestanding_superclass` | 2 | 4 | 7.1s |  |
| 18 | `goto_framescript_queued` | 5 | 5 | 27.5s |  |
| 19 | `graphics_draw_path` | 50 | 50 | 28.2s |  |
| 20 | `groupelement_text` | 2 | 2 | 7.3s |  |
| 21 | `int_toexponential` | 76 | 76 | 7.7s |  |
| 22 | `matrix3d_append_rotation` | 1 | 3 | 7.3s |  |
| 23 | `matrix3d_recompose_edge_cases` | 85 | 85 | 7.6s |  |
| 24 | `number_convert_errors` | 706 | 706 | 7.0s |  |
| 25 | `simplebutton_childevents_script_order` | 4 | 4 | 5.9s |  |
| 26 | `slot_holes_fail` | 1 | 1 | 5.8s |  |
| 27 | `slot_id_exceeds_trait_count` | 1 | 1 | 7.2s |  |
| 28 | `soundchannel_position` | 74 | 74 | 27.2s |  |
| 29 | `soundchannel_soundcomplete` | 10 | 10 | 7.4s |  |
| 30 | `sprite_dropTarget` | 15 | 15 | 7.2s |  |
| 31 | `swf_9_goto_in_construct_frame` | 12 | 12 | 27.5s |  |
| 32 | `textblock_line_changes` | 44 | 44 | 4.7s |  |
| 33 | `textblock_releaselines` | 4 | 4 | 4.7s |  |
| 34 | `uint_toexponential` | 100 | 100 | 7.5s |  |
| 35 | `uncaught_errors_stringified` | 15 | 15 | 2.6s |  |
| 36 | `weird_superinterface_properties` | 1 | 1 | 0.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 3 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 4 | `displayobject_getrect` | 68.8% | 11 | 16 | 5 |  |
| 5 | `number_to_string` | 67.1% | 237 | 353 | 116 |  |
| 6 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 7 | `loader_duplicate_class` | 66.7% | 32 | 48 | 16 |  |
| 8 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 9 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 10 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

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
| 4 | `displayobject_getrect` | 68.8% | 11/16 | 16 | 16 |  |
| 5 | `number_to_string` | 67.1% | 237/353 | 353 | 353 |  |
| 6 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 7 | `loader_duplicate_class` | 66.7% | 32/48 | 48 | 48 |  |
| 8 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 9 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 10 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 11 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 12 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 13 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 14 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 15 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 16 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 17 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 18 | `loader_events_2` | 5.7% | 2/35 | 31 | 35 |  |
| 19 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 20 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 21 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 22 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 23 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 24 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 25 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 26 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 27 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
