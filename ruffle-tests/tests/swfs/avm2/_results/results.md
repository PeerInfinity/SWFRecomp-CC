# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 21:08 UTC

**Git SHA**: `f0fd711c71`

**Run Duration**: 203m 2s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1261 |
| Passing | **1180** (93.6%) |
| Ruffle-matched | 33 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1213** (96.2%) |
| Failing | 48 |
| Total expected lines | 155033 |
| Matching lines | 151384 (97.6%) |
| Mismatched lines | 3649 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 48 | 100.0% |

## Passing Tests

**1180 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 26.3s |  |
| 2 | `accessibility` | 1 | 7.1s |  |
| 3 | `accessibilityimplementation` | 18 | 26.2s |  |
| 4 | `activation_class` | 6 | 7.2s |  |
| 5 | `add` | 1058 | 18.3s |  |
| 6 | `agal_compiler` | 13 | 9.4s |  |
| 7 | `air_datagram_socket` | 1 | 9.2s |  |
| 8 | `air_hidden_lookup` | 2 | 7.1s |  |
| 9 | `air_ifilepromise` | 1 | 7.1s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 7.2s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.6s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.7s |  |
| 13 | `all_classes/display/swf10` | 2569 | 7.2s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.7s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.7s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.7s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.7s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.7s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 7.2s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.6s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.6s |  |
| 22 | `all_classes/errors/swf10` | 140 | 7.2s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.6s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.6s |  |
| 25 | `all_classes/events/swf10` | 1638 | 7.2s |  |
| 26 | `all_classes/events/swf11` | 1750 | 0.7s |  |
| 27 | `all_classes/events/swf12` | 1814 | 0.6s |  |
| 28 | `all_classes/events/swf30` | 2353 | 0.7s |  |
| 29 | `all_classes/events/swf9` | 1030 | 0.6s |  |
| 30 | `all_classes/security/swf11` | 3 | 7.2s |  |
| 31 | `all_classes/security/swf12` | 19 | 0.6s |  |
| 32 | `all_classes/security/swf13` | 53 | 0.6s |  |
| 33 | `all_classes/security/swf30` | 53 | 0.6s |  |
| 34 | `all_classes/xml/swf30` | 116 | 7.2s |  |
| 35 | `all_classes/xml/swf9` | 116 | 0.6s |  |
| 36 | `amf_array_serialization` | 17 | 28.6s |  |
| 37 | `amf_custom_obj` | 26 | 7.2s |  |
| 38 | `amf_dictionary` | 9 | 7.1s |  |
| 39 | `amf_function` | 46 | 7.2s |  |
| 40 | `amf_invalid_date` | 2 | 7.1s |  |
| 41 | `amf_missing_prop` | 6 | 7.1s |  |
| 42 | `amf_nondynamic_function_prop` | 6 | 7.1s |  |
| 43 | `amf_setter_error` | 8 | 7.2s |  |
| 44 | `amf_vector` | 40 | 26.1s |  |
| 45 | `amf_xml` | 6 | 7.0s |  |
| 46 | `appdomain_lookup_edge_cases` | 32 | 7.4s |  |
| 47 | `application_domain` | 4 | 7.0s |  |
| 48 | `applicationdomain_getqualifieddefinitionnames` | 9 | 26.0s |  |
| 49 | `applicationdomain_hasdefinition_null` | 2 | 7.0s |  |
| 50 | `array_access` | 18 | 7.1s |  |
| 51 | `array_access_interpreter` | 4 | 7.0s |  |
| 52 | `array_access_no_pubns` | 2 | 7.0s |  |
| 53 | `array_concat` | 41 | 7.0s |  |
| 54 | `array_constr` | 10 | 7.0s |  |
| 55 | `array_delete` | 44 | 7.1s |  |
| 56 | `array_enumeration` | 10 | 7.0s |  |
| 57 | `array_enumeration_elements` | 11 | 7.0s |  |
| 58 | `array_every` | 8 | 7.0s |  |
| 59 | `array_filter` | 6 | 7.0s |  |
| 60 | `array_foreach` | 18 | 7.0s |  |
| 61 | `array_hasownproperty` | 11 | 7.0s |  |
| 62 | `array_holes` | 9 | 7.0s |  |
| 63 | `array_index_max` | 84 | 6.9s |  |
| 64 | `array_indexof` | 25 | 7.0s |  |
| 65 | `array_join` | 26 | 7.0s |  |
| 66 | `array_lastindexof` | 29 | 7.0s |  |
| 67 | `array_length` | 14 | 7.0s |  |
| 68 | `array_literal` | 3 | 7.0s |  |
| 69 | `array_map` | 8 | 2.1s |  |
| 70 | `array_pop` | 52 | 7.0s |  |
| 71 | `array_push` | 24 | 7.0s |  |
| 72 | `array_reborrow_bug` | 6 | 7.0s |  |
| 73 | `array_reverse` | 28 | 7.0s |  |
| 74 | `array_shift` | 51 | 2.4s |  |
| 75 | `array_slice` | 39 | 7.0s |  |
| 76 | `array_some` | 8 | 7.0s |  |
| 77 | `array_sort` | 297 | 7.5s |  |
| 78 | `array_sort_fun_swf12` | 2 | 7.0s |  |
| 79 | `array_sort_fun_swf13` | 2 | 0.7s |  |
| 80 | `array_sort_random` | 210 | 7.0s |  |
| 81 | `array_sort_swf10_32bit` | 1 | 6.9s |  |
| 82 | `array_sorton` | 545 | 7.8s |  |
| 83 | `array_sparse_ops` | 41 | 7.1s |  |
| 84 | `array_splice` | 133 | 26.9s |  |
| 85 | `array_splice2` | 428 | 26.9s |  |
| 86 | `array_splice_types` | 48 | 7.3s |  |
| 87 | `array_storage` | 8 | 7.1s |  |
| 88 | `array_tolocalestring` | 9 | 7.1s |  |
| 89 | `array_tostring` | 12 | 7.1s |  |
| 90 | `array_unshift` | 24 | 7.1s |  |
| 91 | `array_valueof` | 9 | 7.0s |  |
| 92 | `array_vector_null_callback` | 10 | 7.2s |  |
| 93 | `astype` | 28 | 7.2s |  |
| 94 | `astypelate` | 24 | 7.3s |  |
| 95 | `astypelate_propagates` | 1 | 7.1s |  |
| 96 | `asymmetric_key_events` | 11 | 7.1s |  |
| 97 | `automation_classes` | 122 | 7.5s |  |
| 98 | `av_classes` | 340 | 7.3s |  |
| 99 | `avm1movie_addcallback_call` | 14 | 7.1s |  |
| 100 | `avm2_catchup_dobj` | 158 | 7.6s |  |
| 101 | `away3d_advanced_shallow_water_demo` | 0 | 85.0s |  |
| 102 | `bevel_filter` | 187 | 7.2s |  |
| 103 | `bitand` | 1058 | 19.0s |  |
| 104 | `bitmap_constr` | 17 | 7.3s |  |
| 105 | `bitmap_data` | 1000 | 15.6s |  |
| 106 | `bitmap_pixelsnapping` | 2 | 26.3s |  |
| 107 | `bitmap_properties` | 23 | 7.1s |  |
| 108 | `bitmap_subclass` | 7 | 8.5s |  |
| 109 | `bitmap_subclass_properties` | 9 | 7.4s |  |
| 110 | `bitmap_timeline` | 9 | 7.1s |  |
| 111 | `bitmapdata_accuracy` | 1 | 42.8s |  |
| 112 | `bitmapdata_applyfilter_blur` | 0 | 26.6s |  |
| 113 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.3s |  |
| 114 | `bitmapdata_applyfilter_destpoint` | 0 | 26.4s |  |
| 115 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.3s |  |
| 116 | `bitmapdata_clone` | 13 | 7.1s |  |
| 117 | `bitmapdata_colortransform` | 0 | 7.2s |  |
| 118 | `bitmapdata_colortransform_oob` | 2 | 6.9s |  |
| 119 | `bitmapdata_constr` | 22 | 7.0s |  |
| 120 | `bitmapdata_constructor_from_timeline` | 1 | 7.4s |  |
| 121 | `bitmapdata_copychannel` | 0 | 27.9s |  |
| 122 | `bitmapdata_copypixels` | 23 | 26.4s |  |
| 123 | `bitmapdata_copypixels_blend_over` | 1 | 7.1s |  |
| 124 | `bitmapdata_copypixelstobytearray` | 39 | 7.0s |  |
| 125 | `bitmapdata_dispose` | 7 | 7.0s |  |
| 126 | `bitmapdata_draw` | 0 | 26.2s |  |
| 127 | `bitmapdata_draw_alpha_erase` | 8 | 7.0s |  |
| 128 | `bitmapdata_draw_colortransform` | 0 | 26.0s |  |
| 129 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.0s |  |
| 130 | `bitmapdata_draw_filters` | 0 | 26.0s |  |
| 131 | `bitmapdata_draw_masks` | 0 | 7.0s |  |
| 132 | `bitmapdata_draw_rotation` | 0 | 7.0s |  |
| 133 | `bitmapdata_draw_self_via_graphic` | 0 | 7.0s |  |
| 134 | `bitmapdata_draw_stage` | 0 | 26.0s |  |
| 135 | `bitmapdata_drawwithquality` | 0 | 7.2s |  |
| 136 | `bitmapdata_embedded` | 9 | 7.1s |  |
| 137 | `bitmapdata_fillrect` | 0 | 7.0s |  |
| 138 | `bitmapdata_filter_sourcerect` | 0 | 25.9s |  |
| 139 | `bitmapdata_floodfill` | 35 | 6.9s |  |
| 140 | `bitmapdata_getpixels` | 39 | 26.0s |  |
| 141 | `bitmapdata_getvector` | 27 | 2.4s |  |
| 142 | `bitmapdata_histogram` | 59 | 2.4s |  |
| 143 | `bitmapdata_hittest` | 112 | 7.5s |  |
| 144 | `bitmapdata_hittest_threshold` | 18 | 7.0s |  |
| 145 | `bitmapdata_opaque` | 0 | 7.0s |  |
| 146 | `bitmapdata_pixeldissolve` | 1037 | 7.6s |  |
| 147 | `bitmapdata_pixeldissolve_image` | 0 | 7.2s |  |
| 148 | `bitmapdata_rectangle_rounding` | 16 | 7.0s |  |
| 149 | `bitmapdata_setpixels` | 286 | 7.1s |  |
| 150 | `bitmapdata_setvector` | 26 | 7.1s |  |
| 151 | `bitmapdata_sync` | 0 | 26.1s |  |
| 152 | `bitmapdata_threshold` | 176 | 7.7s |  |
| 153 | `bitmapdata_zero_size` | 8 | 7.0s |  |
| 154 | `bitnot` | 46 | 7.0s |  |
| 155 | `bitor` | 1058 | 18.9s |  |
| 156 | `bitxor` | 1058 | 18.9s |  |
| 157 | `blend_mode_null` | 1 | 6.9s |  |
| 158 | `blend_multiply_alpha` | 0 | 7.0s |  |
| 159 | `blend_scroll` | 0 | 7.0s |  |
| 160 | `blend_shader_luma_lighten` | 3 | 7.2s |  |
| 161 | `blur_filter` | 43 | 7.1s |  |
| 162 | `boolean_constr` | 32 | 26.0s |  |
| 163 | `boolean_negation` | 30 | 6.7s |  |
| 164 | `boolean_tostring` | 8 | 6.7s |  |
| 165 | `broadcast_event` | 7 | 6.5s |  |
| 166 | `button_bounds` | 1 | 6.8s |  |
| 167 | `button_hittest` | 2 | 26.1s |  |
| 168 | `button_nested_frame` | 48 | 26.9s |  |
| 169 | `button_nested_frame_simple` | 27 | 7.1s |  |
| 170 | `bytearray` | 48 | 7.1s |  |
| 171 | `bytearray_compress` | 31 | 6.9s |  |
| 172 | `bytearray_errors` | 24 | 6.9s |  |
| 173 | `bytearray_method_serialization` | 1 | 6.8s |  |
| 174 | `bytearray_oom` | 3 | 6.8s |  |
| 175 | `bytearray_readobject_amf0` | 50 | 6.7s |  |
| 176 | `bytearray_readobject_amf3` | 53 | 6.9s |  |
| 177 | `bytearray_readutf8bytes_with_bom` | 16 | 6.8s |  |
| 178 | `bytearray_serialization` | 3 | 6.8s |  |
| 179 | `bytearray_string_null` | 19 | 7.1s |  |
| 180 | `bytearray_tostring` | 15 | 6.8s |  |
| 181 | `bytearray_utf16` | 8 | 6.8s |  |
| 182 | `bytearray_writeobject` | 24 | 6.6s |  |
| 183 | `callee_in_initializer` | 6 | 6.8s |  |
| 184 | `callproplex_class` | 1 | 6.7s |  |
| 185 | `capabilities_resolution` | 8 | 27.7s |  |
| 186 | `catch_class` | 6 | 6.8s |  |
| 187 | `catch_scope_slot` | 7 | 6.9s |  |
| 188 | `checkfilter` | 4 | 2.2s |  |
| 189 | `class_call` | 32 | 6.9s |  |
| 190 | `class_cast_call` | 14 | 6.8s |  |
| 191 | `class_enumeration` | 4 | 6.8s |  |
| 192 | `class_has_own_property` | 2 | 6.7s |  |
| 193 | `class_init_interpreter_mode` | 1 | 6.7s |  |
| 194 | `class_is` | 32 | 6.9s |  |
| 195 | `class_methods` | 5 | 6.8s |  |
| 196 | `class_object_properties` | 10 | 6.8s |  |
| 197 | `class_singleton` | 18 | 6.8s |  |
| 198 | `class_supercalls_errors` | 35 | 6.9s |  |
| 199 | `class_supercalls_mismatched` | 26 | 6.8s |  |
| 200 | `class_superclass_wrong_order` | 1 | 6.6s |  |
| 201 | `class_to_locale_string` | 2 | 6.7s |  |
| 202 | `class_to_string` | 2 | 7.0s |  |
| 203 | `class_value_of` | 2 | 7.0s |  |
| 204 | `click_block` | 5 | 26.5s |  |
| 205 | `click_invisible` | 3 | 7.0s |  |
| 206 | `closures` | 12 | 7.0s |  |
| 207 | `coerce_return_type` | 40 | 2.5s |  |
| 208 | `coerce_return_type_fail` | 2 | 7.0s |  |
| 209 | `coerce_return_void` | 3 | 6.9s |  |
| 210 | `coerce_string` | 86 | 7.1s |  |
| 211 | `coerce_string_precision` | 28 | 7.0s |  |
| 212 | `coerce_to_primitive_side_effects` | 29 | 26.2s |  |
| 213 | `color_matrix_filter` | 19 | 7.1s |  |
| 214 | `construct_errors_swf10` | 8 | 6.9s |  |
| 215 | `construct_frame_list` | 22 | 25.8s |  |
| 216 | `construct_interface` | 3 | 6.9s |  |
| 217 | `constructor_call` | 3 | 6.8s |  |
| 218 | `constructors_vs_timeline` | 5 | 25.8s |  |
| 219 | `constructprop_dynamic_primitive` | 7 | 7.0s |  |
| 220 | `constructprop_method` | 2 | 6.8s |  |
| 221 | `constructsuper_null` | 2 | 6.9s |  |
| 222 | `content_element_basic` | 50 | 7.2s |  |
| 223 | `context3d_creation` | 9 | 7.0s |  |
| 224 | `control_flow_bool` | 4 | 6.9s |  |
| 225 | `control_flow_stricteq` | 8 | 6.9s |  |
| 226 | `convert_boolean` | 30 | 6.9s |  |
| 227 | `convert_integer` | 90 | 7.0s |  |
| 228 | `convert_number` | 56 | 2.4s |  |
| 229 | `convert_uinteger` | 90 | 7.0s |  |
| 230 | `convolution_filter` | 89 | 7.0s |  |
| 231 | `core_exceptions` | 47 | 7.7s |  |
| 232 | `cpool_index_invalid_bytecode_1` | 6 | 6.9s |  |
| 233 | `cpool_index_invalid_bytecode_2` | 3 | 6.9s |  |
| 234 | `cpool_index_invalid_bytecode_3` | 1 | 6.8s |  |
| 235 | `cross_api_version_call_newer` | 12 | 7.5s |  |
| 236 | `cross_api_version_call_older` | 12 | 7.1s |  |
| 237 | `cryptscore` | 11 | 7.0s |  |
| 238 | `currency_parse_result` | 7 | 6.9s |  |
| 239 | `date` | 30 | 7.3s |  |
| 240 | `date_parse` | 36 | 6.9s |  |
| 241 | `declocal` | 46 | 7.0s |  |
| 242 | `declocal_i` | 46 | 7.1s |  |
| 243 | `decode_uri` | 71 | 7.4s |  |
| 244 | `decrement` | 46 | 7.1s |  |
| 245 | `decrement_i` | 46 | 2.4s |  |
| 246 | `default_values` | 7 | 6.9s |  |
| 247 | `delayed_symbolclass` | 28 | 26.2s |  |
| 248 | `describe_type_basic` | 152 | 7.3s |  |
| 249 | `describe_type_json` | 301 | 7.2s |  |
| 250 | `describe_type_metadata` | 125 | 7.1s |  |
| 251 | `describe_type_native` | 23 | 7.0s |  |
| 252 | `dictionary_access` | 62 | 7.2s |  |
| 253 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 254 | `dictionary_delete` | 101 | 7.4s |  |
| 255 | `dictionary_foreach` | 42 | 7.2s |  |
| 256 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 257 | `dictionary_in` | 62 | 7.2s |  |
| 258 | `dictionary_iter_modify` | 8 | 7.0s |  |
| 259 | `dictionary_namespaces` | 36 | 7.1s |  |
| 260 | `displacement_map_filter` | 61 | 7.1s |  |
| 261 | `displayobject_alpha` | 277 | 6.9s |  |
| 262 | `displayobject_blendmode` | 0 | 25.9s |  |
| 263 | `displayobject_colortransform_nested` | 0 | 26.0s |  |
| 264 | `displayobject_early_init` | 54 | 8.5s |  |
| 265 | `displayobject_filters` | 17 | 7.1s |  |
| 266 | `displayobject_from_enterframe` | 1 | 26.1s |  |
| 267 | `displayobject_getbounds_shape` | 0 | 26.1s |  |
| 268 | `displayobject_height` | 6052 | 26.6s |  |
| 269 | `displayobject_hittestobject` | 32 | 7.0s |  |
| 270 | `displayobject_hittestpoint` | 49 | 7.1s |  |
| 271 | `displayobject_hittestpoint_boundary` | 65 | 26.4s |  |
| 272 | `displayobject_hittestpoint_root` | 13 | 7.2s |  |
| 273 | `displayobject_invalid_floats` | 60 | 7.0s |  |
| 274 | `displayobject_invalid_props` | 3 | 7.0s |  |
| 275 | `displayobject_mask` | 3 | 7.0s |  |
| 276 | `displayobject_mask_self_referential` | 0 | 6.9s |  |
| 277 | `displayobject_metaData` | 3 | 6.9s |  |
| 278 | `displayobject_name` | 22 | 25.9s |  |
| 279 | `displayobject_name_from_timeline` | 24 | 7.1s |  |
| 280 | `displayobject_opaque_background` | 6 | 7.0s |  |
| 281 | `displayobject_parent` | 12 | 26.0s |  |
| 282 | `displayobject_root` | 24 | 6.7s |  |
| 283 | `displayobject_rotation` | 1284 | 6.7s |  |
| 284 | `displayobject_scrollrect` | 33 | 7.1s |  |
| 285 | `displayobject_set_matrix_nested` | 0 | 26.7s |  |
| 286 | `displayobject_set_name_loaded` | 3 | 7.2s |  |
| 287 | `displayobject_subclass` | 2 | 6.8s |  |
| 288 | `displayobject_transform` | 89 | 26.2s |  |
| 289 | `displayobject_visible` | 23 | 6.8s |  |
| 290 | `displayobject_width` | 4852 | 26.3s |  |
| 291 | `displayobject_x` | 614 | 6.6s |  |
| 292 | `displayobject_y` | 617 | 6.6s |  |
| 293 | `displayobjectcontainer_addchild` | 32 | 6.8s |  |
| 294 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.6s |  |
| 295 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.9s |  |
| 296 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.8s |  |
| 297 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.8s |  |
| 298 | `displayobjectcontainer_addchildat` | 42 | 6.8s |  |
| 299 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.8s |  |
| 300 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.7s |  |
| 301 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.7s |  |
| 302 | `displayobjectcontainer_contains` | 66 | 25.8s |  |
| 303 | `displayobjectcontainer_getchildat` | 4 | 6.8s |  |
| 304 | `displayobjectcontainer_getchildbyname` | 9 | 6.7s |  |
| 305 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.7s |  |
| 306 | `displayobjectcontainer_getchildindex` | 28 | 6.7s |  |
| 307 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 25.8s |  |
| 308 | `displayobjectcontainer_removechild` | 10 | 6.7s |  |
| 309 | `displayobjectcontainer_removechild_errors` | 4 | 6.8s |  |
| 310 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.8s |  |
| 311 | `displayobjectcontainer_removechildat` | 18 | 6.6s |  |
| 312 | `displayobjectcontainer_removechildren` | 51 | 7.0s |  |
| 313 | `displayobjectcontainer_setchildindex` | 42 | 6.7s |  |
| 314 | `displayobjectcontainer_stopallmovieclips` | 2 | 26.1s |  |
| 315 | `displayobjectcontainer_swapchildren` | 42 | 6.8s |  |
| 316 | `displayobjectcontainer_swapchildrenat` | 42 | 6.9s |  |
| 317 | `displayobjectcontainer_timelineinstance` | 48 | 26.2s |  |
| 318 | `divide` | 1058 | 15.9s |  |
| 319 | `doabc_and_symbolclass_script_init_goto` | 7 | 25.8s |  |
| 320 | `doabc_and_symbolclass_script_init_normal` | 6 | 6.7s |  |
| 321 | `doabc_is_eager` | 1 | 25.4s |  |
| 322 | `documentclass` | 9 | 7.2s |  |
| 323 | `domain_memory` | 133 | 27.5s |  |
| 324 | `drag_drop` | 10 | 7.1s |  |
| 325 | `drop_shadow_filter` | 172 | 7.3s |  |
| 326 | `duplicate_defs` | 1 | 6.9s |  |
| 327 | `eager_init` | 1 | 7.2s |  |
| 328 | `east_asian_justifier_clone` | 8 | 7.1s |  |
| 329 | `edit_text_linkage` | 7 | 7.2s |  |
| 330 | `edittext_align` | 60 | 7.4s |  |
| 331 | `edittext_always_show_selection` | 0 | 26.2s |  |
| 332 | `edittext_antialiastype` | 296 | 7.4s |  |
| 333 | `edittext_at_point_methods_basic` | 16 | 8.4s |  |
| 334 | `edittext_autosize` | 39 | 7.5s |  |
| 335 | `edittext_autosize_align` | 0 | 26.6s |  |
| 336 | `edittext_autosize_height_dynamic` | 60 | 27.3s |  |
| 337 | `edittext_autosize_height_input` | 60 | 7.4s |  |
| 338 | `edittext_autosize_lazy_bounds_events` | 65 | 7.4s |  |
| 339 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.4s |  |
| 340 | `edittext_autosize_lazy_bounds_props` | 490 | 8.7s |  |
| 341 | `edittext_autosize_lazy_bounds_visual` | 0 | 7.4s |  |
| 342 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.4s |  |
| 343 | `edittext_bottom_scroll_v_basic` | 210 | 7.4s |  |
| 344 | `edittext_bounds_scale` | 24 | 26.9s |  |
| 345 | `edittext_bullet` | 30 | 7.2s |  |
| 346 | `edittext_default_format` | 221 | 7.5s |  |
| 347 | `edittext_default_format_empty` | 136 | 7.3s |  |
| 348 | `edittext_empty_text_format` | 7 | 7.0s |  |
| 349 | `edittext_focus_selection` | 5 | 7.0s |  |
| 350 | `edittext_font_size` | 45 | 7.3s |  |
| 351 | `edittext_format_empty_font` | 8 | 7.0s |  |
| 352 | `edittext_get_char_index_at_point` | 4 | 28.0s |  |
| 353 | `edittext_get_line_index_at_point` | 2 | 26.9s |  |
| 354 | `edittext_get_line_index_of_char` | 76 | 8.2s |  |
| 355 | `edittext_getcharboundaries` | 172 | 7.6s |  |
| 356 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.1s |  |
| 357 | `edittext_getcharboundaries_scroll` | 85 | 7.2s |  |
| 358 | `edittext_getlinemetrics` | 146 | 7.5s |  |
| 359 | `edittext_html` | 3101 | 7.6s |  |
| 360 | `edittext_html_condensewhite` | 487 | 7.2s |  |
| 361 | `edittext_html_entity` | 4 | 5.5s |  |
| 362 | `edittext_html_font_size_swf12` | 267 | 19.3s |  |
| 363 | `edittext_html_font_size_swf13` | 273 | 5.2s |  |
| 364 | `edittext_html_roundtrip` | 17 | 5.1s |  |
| 365 | `edittext_ime_focus_lost` | 9 | 19.8s |  |
| 366 | `edittext_input_control` | 12 | 5.2s |  |
| 367 | `edittext_leading` | 9 | 5.2s |  |
| 368 | `edittext_letter_spacing` | 15 | 4.9s |  |
| 369 | `edittext_line_methods` | 294 | 6.3s |  |
| 370 | `edittext_line_metrics` | 11 | 21.0s |  |
| 371 | `edittext_margins` | 25 | 5.2s |  |
| 372 | `edittext_max_scroll_h_basic` | 475 | 5.2s |  |
| 373 | `edittext_max_scroll_v_basic` | 1000 | 5.2s |  |
| 374 | `edittext_mouse_selection` | 363 | 20.6s |  |
| 375 | `edittext_mousedown` | 3 | 5.3s |  |
| 376 | `edittext_mouseenabled` | 26 | 5.0s |  |
| 377 | `edittext_newline_character` | 22 | 5.5s |  |
| 378 | `edittext_newline_stripping` | 64 | 6.8s |  |
| 379 | `edittext_newlines` | 30 | 5.1s |  |
| 380 | `edittext_paragraph_methods` | 257 | 5.0s |  |
| 381 | `edittext_paste_events` | 8 | 5.0s |  |
| 382 | `edittext_paste_maxchars` | 4 | 4.8s |  |
| 383 | `edittext_paste_restrict` | 16 | 4.9s |  |
| 384 | `edittext_restrict` | 191 | 5.6s |  |
| 385 | `edittext_restrict_events` | 22 | 5.0s |  |
| 386 | `edittext_scrollh` | 10 | 1.6s |  |
| 387 | `edittext_selected_text` | 9 | 4.8s |  |
| 388 | `edittext_set_html_same` | 17 | 5.2s |  |
| 389 | `edittext_set_text_vs_html` | 9 | 5.2s |  |
| 390 | `edittext_stylesheet` | 536 | 5.6s |  |
| 391 | `edittext_stylesheet_custom_tag` | 76 | 5.0s |  |
| 392 | `edittext_stylesheet_display` | 272 | 5.2s |  |
| 393 | `edittext_tag_indent` | 49 | 19.5s |  |
| 394 | `edittext_underline` | 40 | 5.6s |  |
| 395 | `edittext_width_height` | 103 | 5.2s |  |
| 396 | `edittext_wordwrap_word` | 150 | 5.1s |  |
| 397 | `edittext_wrap_breaks` | 2375 | 5.6s |  |
| 398 | `element_format_clone` | 44 | 5.2s |  |
| 399 | `element_format_constructor_order` | 64 | 1.8s |  |
| 400 | `element_format_properties` | 235 | 6.1s |  |
| 401 | `empty_bounds` | 1 | 4.9s |  |
| 402 | `encode_uri_surrogate_pair_invalid` | 8 | 22.6s |  |
| 403 | `encode_uri_surrogate_pair_swf11` | 15 | 1.5s |  |
| 404 | `equals` | 512 | 8.5s |  |
| 405 | `error_geterrormessage` | 779 | 6.2s |  |
| 406 | `error_prototype` | 15 | 5.9s |  |
| 407 | `error_stack_trace` | 45 | 5.9s |  |
| 408 | `error_stack_trace_debug_swf17` | 0 | 22.5s |  |
| 409 | `error_stack_trace_debug_swf18` | 0 | 5.5s |  |
| 410 | `error_stack_trace_edge_cases` | 6 | 6.0s |  |
| 411 | `error_stack_trace_release_swf17` | 0 | 5.8s |  |
| 412 | `error_stack_trace_release_swf18` | 0 | 5.6s |  |
| 413 | `error_throwerror` | 103 | 5.9s |  |
| 414 | `error_tostring` | 29 | 5.8s |  |
| 415 | `error_tostring_more` | 86 | 5.9s |  |
| 416 | `es3_inheritance` | 31 | 5.9s |  |
| 417 | `es4_inheritance` | 30 | 5.9s |  |
| 418 | `es4_interfaces` | 30 | 6.0s |  |
| 419 | `es4_method_binding` | 8 | 6.2s |  |
| 420 | `es4_oop_prototypes` | 14 | 6.1s |  |
| 421 | `es4_protected_inheritance` | 6 | 5.9s |  |
| 422 | `escape` | 71 | 5.9s |  |
| 423 | `escape_multi_byte` | 45 | 6.0s |  |
| 424 | `event_bubbles` | 2 | 5.8s |  |
| 425 | `event_cancelable` | 2 | 5.8s |  |
| 426 | `event_clone` | 20 | 5.9s |  |
| 427 | `event_clone_error_redispatch` | 3 | 6.0s |  |
| 428 | `event_clone_on_redispatch` | 10 | 5.9s |  |
| 429 | `event_formattostring` | 31 | 5.9s |  |
| 430 | `event_isdefaultprevented` | 12 | 5.8s |  |
| 431 | `event_target_getter` | 5 | 1.8s |  |
| 432 | `event_target_set` | 9 | 5.9s |  |
| 433 | `event_type` | 1 | 5.8s |  |
| 434 | `event_valueof_tostring` | 18 | 5.8s |  |
| 435 | `eventdispatcher_dispatchevent` | 12 | 5.8s |  |
| 436 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.9s |  |
| 437 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.0s |  |
| 438 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.8s |  |
| 439 | `eventdispatcher_dispatchevent_this` | 5 | 5.8s |  |
| 440 | `eventdispatcher_haseventlistener` | 25 | 5.9s |  |
| 441 | `eventdispatcher_interface_invoke` | 1 | 4.9s |  |
| 442 | `eventdispatcher_tostring` | 10 | 4.9s |  |
| 443 | `eventdispatcher_willtrigger` | 25 | 5.0s |  |
| 444 | `falsiness` | 30 | 5.0s |  |
| 445 | `fast_index_access` | 12 | 5.4s |  |
| 446 | `filefilter_properties` | 4 | 5.2s |  |
| 447 | `filereference_browse_cancel` | 3 | 4.9s |  |
| 448 | `filereference_browse_select` | 9 | 1.8s |  |
| 449 | `filereference_load` | 31 | 5.0s |  |
| 450 | `filereference_save` | 16 | 5.3s |  |
| 451 | `filereference_save_and_browse` | 42 | 5.1s |  |
| 452 | `filereference_save_and_load` | 22 | 5.3s |  |
| 453 | `filereference_uninitialized` | 8 | 5.2s |  |
| 454 | `filereferencelist_browse_cancel` | 6 | 5.1s |  |
| 455 | `filereferencelist_browse_select` | 7 | 5.0s |  |
| 456 | `filter_rewind` | 8 | 18.7s |  |
| 457 | `filters_array_holes` | 25 | 5.3s |  |
| 458 | `finddef` | 3 | 5.2s |  |
| 459 | `findprop_global_prototype` | 6 | 5.4s |  |
| 460 | `flash_media_video_constructor` | 156 | 5.9s |  |
| 461 | `flash_media_video_rotation_probe` | 27 | 5.2s |  |
| 462 | `flash_media_video_setter` | 40 | 5.6s |  |
| 463 | `flash_trace` | 17 | 5.6s |  |
| 464 | `flash_xml` | 29 | 5.4s |  |
| 465 | `flash_xml_cloneNode` | 22 | 5.3s |  |
| 466 | `flash_xml_namespace` | 109 | 5.5s |  |
| 467 | `flash_xml_removeNode` | 60 | 5.4s |  |
| 468 | `focus_events_code` | 161 | 19.6s |  |
| 469 | `focus_events_key_basic` | 132 | 19.0s |  |
| 470 | `focus_events_key_navigation` | 53 | 18.3s |  |
| 471 | `focus_events_key_same_object` | 26 | 5.0s |  |
| 472 | `focus_events_mixed_key_mouse` | 100 | 18.5s |  |
| 473 | `focus_events_mouse_basic` | 260 | 18.4s |  |
| 474 | `focus_events_mouse_focusable` | 112 | 19.1s |  |
| 475 | `focus_events_mouse_same_object` | 40 | 5.0s |  |
| 476 | `focus_remove` | 20 | 18.0s |  |
| 477 | `focus_root_movie` | 4 | 18.0s |  |
| 478 | `focus_stage` | 1 | 4.8s |  |
| 479 | `focusrect` | 18 | 5.5s |  |
| 480 | `focusrect_focuslost` | 9 | 27.5s |  |
| 481 | `focusrect_property` | 110 | 26.6s |  |
| 482 | `font_description_clone` | 14 | 7.4s |  |
| 483 | `font_embedded` | 24 | 7.9s |  |
| 484 | `font_enumeratefonts` | 41 | 8.0s |  |
| 485 | `font_enumeratefonts_filter` | 4 | 8.2s |  |
| 486 | `font_enumeratefonts_order` | 9 | 8.7s |  |
| 487 | `font_hasglyphs` | 40 | 7.9s |  |
| 488 | `font_registerfont` | 129 | 8.3s |  |
| 489 | `framelabel_constr` | 5 | 7.3s |  |
| 490 | `function_call` | 12 | 2.5s |  |
| 491 | `function_call_arguments` | 46 | 7.3s |  |
| 492 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 493 | `function_call_coercion` | 108 | 7.7s |  |
| 494 | `function_call_default` | 6 | 7.2s |  |
| 495 | `function_call_rest` | 22 | 7.3s |  |
| 496 | `function_call_types` | 3 | 7.3s |  |
| 497 | `function_call_via_apply` | 11 | 7.4s |  |
| 498 | `function_call_via_call` | 3 | 7.3s |  |
| 499 | `function_display_anonymous` | 7 | 2.6s |  |
| 500 | `function_length` | 6 | 7.5s |  |
| 501 | `function_object` | 2 | 7.4s |  |
| 502 | `function_proto` | 5 | 7.3s |  |
| 503 | `function_proto_created` | 61 | 7.4s |  |
| 504 | `function_to_locale_string` | 4 | 7.4s |  |
| 505 | `function_to_string` | 4 | 7.4s |  |
| 506 | `function_type` | 6 | 7.4s |  |
| 507 | `function_unbound_this` | 51 | 7.5s |  |
| 508 | `function_value_of` | 4 | 7.6s |  |
| 509 | `game_input` | 4 | 7.6s |  |
| 510 | `generate_random_bytes` | 3 | 7.6s |  |
| 511 | `geom_transform` | 74 | 28.9s |  |
| 512 | `get_definition_by_name` | 11 | 7.6s |  |
| 513 | `get_qualified_class_name` | 20 | 7.5s |  |
| 514 | `get_qualified_super_class_name` | 18 | 7.5s |  |
| 515 | `get_slot_edge_cases` | 1 | 7.5s |  |
| 516 | `get_timer` | 2 | 2.6s |  |
| 517 | `getglobalslot` | 1 | 7.5s |  |
| 518 | `getouterscope` | 8 | 7.4s |  |
| 519 | `getouterscope_two_classobjects` | 13 | 7.4s |  |
| 520 | `getter_different_namespace_setter` | 2 | 7.4s |  |
| 521 | `glow_filter` | 127 | 6.2s |  |
| 522 | `goto_button_nested_framescript` | 28 | 24.0s |  |
| 523 | `goto_in_constructframe` | 12 | 23.6s |  |
| 524 | `goto_in_scene_last_frame` | 2 | 23.3s |  |
| 525 | `goto_methods` | 56 | 6.2s |  |
| 526 | `goto_methods_swfver10` | 8 | 6.1s |  |
| 527 | `goto_nested_construct_sibling` | 18 | 6.5s |  |
| 528 | `goto_nested_framescript` | 9 | 6.3s |  |
| 529 | `goto_on_orphan` | 15 | 6.3s |  |
| 530 | `gradient_bevel_filter` | 206 | 6.2s |  |
| 531 | `gradient_glow_filter` | 206 | 6.1s |  |
| 532 | `graphic_linkage` | 9 | 6.3s |  |
| 533 | `graphics_bad_direct_commands` | 5 | 6.6s |  |
| 534 | `graphics_bitmap_fill` | 0 | 24.7s |  |
| 535 | `graphics_bitmaps` | 0 | 6.4s |  |
| 536 | `graphics_direct_commands` | 0 | 6.2s |  |
| 537 | `graphics_draw_triangles` | 98 | 24.4s |  |
| 538 | `graphics_gradients` | 0 | 6.3s |  |
| 539 | `graphics_gradients_nulls` | 0 | 6.2s |  |
| 540 | `graphics_path` | 56 | 6.4s |  |
| 541 | `graphics_round_rects` | 0 | 6.2s |  |
| 542 | `graphics_simple_shapes` | 0 | 6.1s |  |
| 543 | `greaterequals` | 512 | 8.7s |  |
| 544 | `greaterthan` | 512 | 9.3s |  |
| 545 | `has_own_property` | 102 | 7.6s |  |
| 546 | `hasownproperty_namespaces` | 2 | 6.6s |  |
| 547 | `hello_world` | 1 | 6.3s |  |
| 548 | `hittest_morph` | 30 | 6.3s |  |
| 549 | `if_eq` | 10 | 6.2s |  |
| 550 | `if_gt` | 1 | 6.2s |  |
| 551 | `if_gte` | 10 | 1.9s |  |
| 552 | `if_lt` | 1 | 0.5s |  |
| 553 | `if_lte` | 10 | 6.0s |  |
| 554 | `if_ne` | 7 | 1.9s |  |
| 555 | `if_stricteq` | 6 | 6.1s |  |
| 556 | `if_strictne` | 11 | 6.1s |  |
| 557 | `ime_linux_dead_keys` | 10 | 6.1s |  |
| 558 | `in` | 102 | 6.5s |  |
| 559 | `inclocal` | 46 | 7.3s |  |
| 560 | `inclocal_i` | 46 | 7.4s |  |
| 561 | `increment` | 46 | 7.2s |  |
| 562 | `increment_i` | 46 | 7.3s |  |
| 563 | `indexing_delete` | 75 | 7.3s |  |
| 564 | `init_callee_cached` | 24 | 7.2s |  |
| 565 | `instanceof` | 58 | 7.4s |  |
| 566 | `instantiate_root_character` | 4 | 7.5s |  |
| 567 | `instantiation_on_enter_frame` | 7 | 26.8s |  |
| 568 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.2s |  |
| 569 | `int_constr` | 92 | 7.5s |  |
| 570 | `int_edge_cases` | 19 | 26.7s |  |
| 571 | `int_instanceof` | 3 | 7.1s |  |
| 572 | `int_tofixed` | 1215 | 7.2s |  |
| 573 | `int_toprecision` | 1125 | 7.3s |  |
| 574 | `int_tostring` | 3375 | 7.5s |  |
| 575 | `interactiveobject_enabled` | 25 | 7.1s |  |
| 576 | `interface_namespaces` | 78 | 7.4s |  |
| 577 | `invalid_utf8` | 12 | 7.2s |  |
| 578 | `is_finite` | 46 | 7.2s |  |
| 579 | `is_nan` | 46 | 7.1s |  |
| 580 | `is_prototype_of` | 12 | 7.2s |  |
| 581 | `issue_10221` | 2 | 7.2s |  |
| 582 | `issue_13780` | 12 | 7.2s |  |
| 583 | `issue_14901` | 1 | 7.2s |  |
| 584 | `issue_17675_edittext_paste_maxchars` | 1 | 7.2s |  |
| 585 | `issue_5292` | 5 | 7.2s |  |
| 586 | `issue_8630` | 2 | 7.3s |  |
| 587 | `issue_8630_placeremoveplace` | 15 | 7.3s |  |
| 588 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.2s |  |
| 589 | `issue_8630_scriptremove` | 11 | 7.2s |  |
| 590 | `istype` | 24 | 2.5s |  |
| 591 | `istypelate` | 58 | 7.5s |  |
| 592 | `istypelate_coerce` | 198 | 8.2s |  |
| 593 | `jpeg_loader_context` | 6 | 2.5s |  |
| 594 | `json_errors` | 9 | 26.9s |  |
| 595 | `json_parse` | 21 | 2.5s |  |
| 596 | `json_stringify` | 12 | 7.5s |  |
| 597 | `json_stringify_function` | 12 | 7.3s |  |
| 598 | `json_stringify_order` | 1 | 7.4s |  |
| 599 | `json_version_gated` | 1 | 7.3s |  |
| 600 | `key_input_80percent` | 1812 | 26.7s |  |
| 601 | `key_input_location` | 126 | 7.1s |  |
| 602 | `key_input_numpad` | 384 | 7.0s |  |
| 603 | `large_preload_from_url` | 27 | 9.2s |  |
| 604 | `large_preload_image_from_bytes` | 25 | 7.7s |  |
| 605 | `lazyinit` | 17 | 7.8s |  |
| 606 | `lessequals` | 512 | 12.4s |  |
| 607 | `lessthan` | 512 | 12.5s |  |
| 608 | `loader_bitmap_transparency` | 14 | 7.9s |  |
| 609 | `loader_bytes_unknown_content` | 14 | 7.8s |  |
| 610 | `loader_child_getdefinition` | 5 | 7.9s |  |
| 611 | `loader_duplicate_coerce` | 3 | 8.0s |  |
| 612 | `loader_duplicate_coerce_new_domain` | 4 | 7.7s |  |
| 613 | `loader_error_in_root_ctor` | 4 | 7.8s |  |
| 614 | `loader_events` | 92 | 8.0s |  |
| 615 | `loader_image` | 8 | 7.6s |  |
| 616 | `loader_jpegxr` | 2 | 27.0s |  |
| 617 | `loader_jpegxr_alpha` | 1 | 27.0s |  |
| 618 | `loader_loadbytes_events` | 30 | 7.7s |  |
| 619 | `loader_loadbytes_invalid_png` | 4 | 7.4s |  |
| 620 | `loader_loadbytes_url` | 12 | 7.5s |  |
| 621 | `loader_loaderurl` | 6 | 7.6s |  |
| 622 | `loader_method` | 85 | 7.2s |  |
| 623 | `loader_noninteractive_try_click_root` | 5 | 27.3s |  |
| 624 | `loader_reuse` | 38 | 7.5s |  |
| 625 | `loader_unknown_content` | 24 | 7.3s |  |
| 626 | `loader_visibility_interactive` | 1 | 7.2s |  |
| 627 | `loaderinfo_events` | 7 | 7.2s |  |
| 628 | `loaderinfo_loadurl` | 12 | 7.1s |  |
| 629 | `loaderinfo_more` | 6 | 7.4s |  |
| 630 | `loaderinfo_properties` | 18 | 26.9s |  |
| 631 | `loaderinfo_properties_not_loaded` | 23 | 7.2s |  |
| 632 | `loaderinfo_quine` | 1005 | 7.0s |  |
| 633 | `loaderinfo_root` | 10 | 7.1s |  |
| 634 | `loaderinfo_root_allows` | 2 | 7.0s |  |
| 635 | `localconnection` | 890 | 9.0s |  |
| 636 | `localconnection_send` | 4 | 25.7s |  |
| 637 | `lshift` | 1058 | 18.8s |  |
| 638 | `mask_reapply` | 1 | 25.8s |  |
| 639 | `math` | 497 | 7.2s |  |
| 640 | `matrix` | 338 | 17.8s |  |
| 641 | `matrix3d` | 57 | 26.5s |  |
| 642 | `matrix3d_append` | 16 | 7.0s |  |
| 643 | `matrix3d_append_prepend_translation` | 42 | 7.0s |  |
| 644 | `matrix3d_compose` | 34 | 7.1s |  |
| 645 | `matrix3d_constructor_clone` | 15 | 6.9s |  |
| 646 | `matrix3d_copy_column` | 83 | 7.2s |  |
| 647 | `matrix3d_copy_raw_data_from` | 55 | 2.5s |  |
| 648 | `matrix3d_copy_raw_data_to` | 38 | 7.1s |  |
| 649 | `matrix3d_copy_row` | 83 | 6.8s |  |
| 650 | `matrix3d_determinant` | 182 | 7.1s |  |
| 651 | `matrix3d_invert` | 18 | 6.9s |  |
| 652 | `matrix3d_position` | 19 | 7.0s |  |
| 653 | `matrix3d_precision` | 28 | 7.1s |  |
| 654 | `matrix3d_prepend` | 16 | 6.8s |  |
| 655 | `matrix3d_raw_data` | 33 | 7.0s |  |
| 656 | `matrix3d_transform_vector` | 52 | 7.3s |  |
| 657 | `matrix3d_transpose` | 5 | 6.9s |  |
| 658 | `method_association` | 5 | 7.0s |  |
| 659 | `method_without_body` | 3 | 25.8s |  |
| 660 | `missing_external_interface` | 10 | 6.9s |  |
| 661 | `modulo` | 1058 | 18.8s |  |
| 662 | `morph_shape` | 2 | 25.8s |  |
| 663 | `mouse_children` | 192 | 25.9s |  |
| 664 | `mouse_click_events` | 90 | 25.7s |  |
| 665 | `mouse_double_click_events` | 188 | 7.0s |  |
| 666 | `mouse_empty_parent` | 4 | 6.9s |  |
| 667 | `mouse_over_while_dragging` | 3 | 6.9s |  |
| 668 | `mouse_pick_avm1_root` | 2 | 25.9s |  |
| 669 | `mouse_pick_button_mode` | 2 | 7.0s |  |
| 670 | `mouse_pick_dobj_mask` | 4 | 7.0s |  |
| 671 | `mouse_pick_masking` | 7 | 21.9s |  |
| 672 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 22.2s |  |
| 673 | `mouse_pick_non_interactive_dobj_mask` | 3 | 21.8s |  |
| 674 | `mouse_pick_text` | 8 | 5.8s |  |
| 675 | `mouse_sibling` | 8 | 5.7s |  |
| 676 | `mouse_wheel_events` | 36 | 22.9s |  |
| 677 | `mouseevent_constr` | 66 | 5.7s |  |
| 678 | `mouseevent_stagexy` | 35 | 5.8s |  |
| 679 | `mouseevent_valueof_tostring` | 28 | 5.7s |  |
| 680 | `movieclip_addframescript` | 3 | 22.0s |  |
| 681 | `movieclip_child_property` | 16 | 5.8s |  |
| 682 | `movieclip_constr` | 21 | 5.8s |  |
| 683 | `movieclip_currentlabels` | 17 | 21.9s |  |
| 684 | `movieclip_currentlabels_dupes1` | 46 | 23.3s |  |
| 685 | `movieclip_currentlabels_dupes2` | 30 | 6.1s |  |
| 686 | `movieclip_currentlabels_dupes3` | 67 | 6.0s |  |
| 687 | `movieclip_currentscene` | 12 | 22.0s |  |
| 688 | `movieclip_dispatchevent` | 430 | 5.8s |  |
| 689 | `movieclip_dispatchevent_cancel` | 102 | 5.9s |  |
| 690 | `movieclip_dispatchevent_handlerorder` | 251 | 6.2s |  |
| 691 | `movieclip_dispatchevent_selfadd` | 80 | 5.7s |  |
| 692 | `movieclip_dispatchevent_target` | 899 | 5.8s |  |
| 693 | `movieclip_displayevents` | 96 | 22.1s |  |
| 694 | `movieclip_displayevents_clickgoto` | 676 | 22.3s |  |
| 695 | `movieclip_displayevents_clickgoto2` | 2001 | 6.3s |  |
| 696 | `movieclip_displayevents_clickplay` | 575 | 5.9s |  |
| 697 | `movieclip_displayevents_clicksymbol` | 562 | 1.9s |  |
| 698 | `movieclip_displayevents_constructframegoto` | 140 | 6.0s |  |
| 699 | `movieclip_displayevents_constructframeplay` | 50 | 6.0s |  |
| 700 | `movieclip_displayevents_constructframesymbol` | 144 | 5.8s |  |
| 701 | `movieclip_displayevents_dblhandler` | 21 | 5.8s |  |
| 702 | `movieclip_displayevents_enterframegoto` | 149 | 6.0s |  |
| 703 | `movieclip_displayevents_enterframeplay` | 48 | 5.8s |  |
| 704 | `movieclip_displayevents_enterframesymbol` | 149 | 22.1s |  |
| 705 | `movieclip_displayevents_exitframegoto` | 106 | 5.8s |  |
| 706 | `movieclip_displayevents_exitframeplay` | 44 | 5.7s |  |
| 707 | `movieclip_displayevents_exitframesymbol` | 135 | 5.8s |  |
| 708 | `movieclip_displayevents_looping` | 63 | 22.0s |  |
| 709 | `movieclip_displayevents_stopped` | 113 | 5.8s |  |
| 710 | `movieclip_displayevents_swap` | 96 | 1.8s |  |
| 711 | `movieclip_displayevents_timeline` | 128 | 5.9s |  |
| 712 | `movieclip_drawrect` | 54 | 26.6s |  |
| 713 | `movieclip_frameconstruct_skipped` | 9 | 7.3s |  |
| 714 | `movieclip_goto_during_frame_script` | 15 | 26.8s |  |
| 715 | `movieclip_goto_overwrite` | 14 | 27.0s |  |
| 716 | `movieclip_goto_scene_last_frame_int` | 1 | 26.7s |  |
| 717 | `movieclip_goto_scene_last_frame_label` | 1 | 2.5s |  |
| 718 | `movieclip_gotoandplay` | 15 | 27.1s |  |
| 719 | `movieclip_gotoandstop` | 13 | 7.4s |  |
| 720 | `movieclip_gotoandstop_children` | 4 | 7.5s |  |
| 721 | `movieclip_gotoandstop_framescripts1` | 4 | 7.3s |  |
| 722 | `movieclip_gotoandstop_framescripts2` | 4 | 2.5s |  |
| 723 | `movieclip_gotoandstop_framescripts_self` | 7 | 27.1s |  |
| 724 | `movieclip_gotoandstop_queueing` | 12 | 27.4s |  |
| 725 | `movieclip_hittest` | 67 | 7.4s |  |
| 726 | `movieclip_next_frame` | 2 | 7.2s |  |
| 727 | `movieclip_next_scene` | 6 | 26.9s |  |
| 728 | `movieclip_play` | 3 | 7.2s |  |
| 729 | `movieclip_prev_frame` | 3 | 7.0s |  |
| 730 | `movieclip_prev_scene` | 7 | 7.3s |  |
| 731 | `movieclip_properties` | 79 | 26.8s |  |
| 732 | `movieclip_queued_noop_goto_swf10` | 9 | 7.2s |  |
| 733 | `movieclip_queued_noop_goto_swf9` | 7 | 0.7s |  |
| 734 | `movieclip_scenes` | 11 | 7.1s |  |
| 735 | `movieclip_soundtransform` | 831 | 28.7s |  |
| 736 | `movieclip_stop` | 1 | 7.1s |  |
| 737 | `movieclip_super_is_symbol` | 20 | 7.5s |  |
| 738 | `movieclip_symbol_constr` | 8 | 7.3s |  |
| 739 | `movieclip_text_mousedown` | 1 | 7.3s |  |
| 740 | `movieclip_willtrigger` | 5 | 7.3s |  |
| 741 | `multiply` | 1058 | 18.5s |  |
| 742 | `namespace_constr` | 253 | 7.5s |  |
| 743 | `namespace_constr_args` | 1 | 7.2s |  |
| 744 | `namespace_enumeration_order` | 7 | 26.5s |  |
| 745 | `nan_scale` | 9 | 7.2s |  |
| 746 | `native_menu_basic` | 19 | 9.6s |  |
| 747 | `navigateToURL_target_normalize` | 107 | 28.8s |  |
| 748 | `negate` | 30 | 7.2s |  |
| 749 | `negative_volume_panned` | 0 | 7.5s |  |
| 750 | `nested_iteration` | 11 | 7.2s |  |
| 751 | `net_getClassByAlias` | 3 | 7.2s |  |
| 752 | `net_navigateToURL` | 57 | 7.2s |  |
| 753 | `net_stream_play_options` | 6 | 7.2s |  |
| 754 | `netconnection_close` | 55 | 19.9s |  |
| 755 | `netconnection_properties` | 78 | 5.1s |  |
| 756 | `netconnection_send_remote` | 50 | 21.2s |  |
| 757 | `netconnection_serialize_arrays` | 6 | 5.0s |  |
| 758 | `netfilterevent` | 10 | 19.1s |  |
| 759 | `netstream_client` | 10 | 5.0s |  |
| 760 | `netstream_connect` | 7 | 4.9s |  |
| 761 | `netstream_flv_date` | 4 | 5.0s |  |
| 762 | `newactivation_in_script_init` | 3 | 4.7s |  |
| 763 | `newclass_mismatched` | 4 | 4.9s |  |
| 764 | `newclass_twice` | 3 | 4.8s |  |
| 765 | `nonconflicting_declarations` | 0 | 1.5s |  |
| 766 | `null_void_types` | 8 | 4.8s |  |
| 767 | `number_autoconv` | 21 | 1.5s |  |
| 768 | `number_autoconv_amf` | 132 | 4.8s |  |
| 769 | `number_autoconv_array_sort_32bit` | 1 | 4.9s |  |
| 770 | `number_constr` | 58 | 5.0s |  |
| 771 | `number_convert_edge_cases` | 180 | 19.0s |  |
| 772 | `number_toexponential` | 378 | 4.8s |  |
| 773 | `number_toexponential2` | 35 | 1.5s |  |
| 774 | `number_tofixed` | 378 | 4.7s |  |
| 775 | `number_toprecision` | 350 | 4.8s |  |
| 776 | `obfuscated_class_names` | 3 | 4.8s |  |
| 777 | `object_enumeration` | 10 | 5.0s |  |
| 778 | `object_prototype` | 4 | 5.1s |  |
| 779 | `object_to_locale_string` | 2 | 4.8s |  |
| 780 | `object_to_string` | 2 | 4.8s |  |
| 781 | `object_value_of` | 2 | 1.3s |  |
| 782 | `op_coerce` | 54 | 5.0s |  |
| 783 | `op_coerce_x` | 54 | 4.9s |  |
| 784 | `op_escxattr` | 2 | 4.8s |  |
| 785 | `op_escxelem` | 2 | 4.8s |  |
| 786 | `op_lookupswitch` | 4 | 4.8s |  |
| 787 | `optimize_coerce` | 1 | 5.0s |  |
| 788 | `orphan_movie_complex` | 80 | 5.3s |  |
| 789 | `orphan_movie_reorder` | 111 | 19.5s |  |
| 790 | `package_namespace` | 7 | 26.4s |  |
| 791 | `param_default_value_has_zero_cpool_index` | 1 | 26.1s |  |
| 792 | `parent_early_access_child` | 16 | 26.6s |  |
| 793 | `parse_float` | 81 | 7.3s |  |
| 794 | `parse_float_swf10` | 81 | 7.2s |  |
| 795 | `parse_int` | 135 | 7.8s |  |
| 796 | `perspective_projection` | 1443 | 26.7s |  |
| 797 | `perspective_projection_basic` | 40 | 7.3s |  |
| 798 | `pixelbender_ceil` | 77 | 7.5s |  |
| 799 | `pixelbender_conditional` | 138 | 7.7s |  |
| 800 | `pixelbender_conversions` | 270 | 7.7s |  |
| 801 | `pixelbender_dithering` | 8 | 33.0s |  |
| 802 | `pixelbender_div` | 36 | 7.5s |  |
| 803 | `pixelbender_effect_BlurredFocus` | 0 | 35.6s |  |
| 804 | `pixelbender_effect_glassDisplace` | 0 | 13.2s |  |
| 805 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 30.2s |  |
| 806 | `pixelbender_effect_smudge` | 0 | 10.5s |  |
| 807 | `pixelbender_effect_tintype` | 0 | 10.0s |  |
| 808 | `pixelbender_effect_twirl` | 0 | 11.2s |  |
| 809 | `pixelbender_eof` | 7 | 7.2s |  |
| 810 | `pixelbender_images` | 0 | 9.4s |  |
| 811 | `pixelbender_input` | 103 | 26.8s |  |
| 812 | `pixelbender_logicalnot` | 20 | 7.0s |  |
| 813 | `pixelbender_malformed_data` | 190 | 26.6s |  |
| 814 | `pixelbender_multiple_out_params` | 1 | 6.9s |  |
| 815 | `pixelbender_no_out_param` | 6 | 6.9s |  |
| 816 | `pixelbender_outputs` | 13 | 7.1s |  |
| 817 | `pixelbender_padding_bytes` | 22 | 7.0s |  |
| 818 | `pixelbender_param_qualifier` | 512 | 7.0s |  |
| 819 | `pixelbender_parameters` | 1563 | 7.3s |  |
| 820 | `pixelbender_parameters_bool` | 240 | 7.2s |  |
| 821 | `pixelbender_parameters_int_vs_bool` | 54 | 7.0s |  |
| 822 | `pixelbender_parse_errors` | 6 | 7.0s |  |
| 823 | `pixelbender_rsqrt` | 24 | 7.1s |  |
| 824 | `pixelbender_select_kinds` | 8 | 7.3s |  |
| 825 | `pixelbender_shaderdata` | 49 | 7.1s |  |
| 826 | `pixelbender_shaderdata_setter` | 99 | 7.4s |  |
| 827 | `pixelbender_sign` | 60 | 7.2s |  |
| 828 | `pixelbender_vector_output` | 11 | 7.2s |  |
| 829 | `place_and_lookup/swf10` | 33 | 7.1s |  |
| 830 | `place_and_lookup/swf9` | 33 | 0.7s |  |
| 831 | `place_multiple` | 17 | 27.1s |  |
| 832 | `place_object_replace` | 9 | 26.9s |  |
| 833 | `place_object_replace_2` | 24 | 27.5s |  |
| 834 | `place_object_same_depth_frame` | 1 | 27.0s |  |
| 835 | `point` | 132 | 7.9s |  |
| 836 | `primitive_edge_cases` | 1 | 7.3s |  |
| 837 | `primitive_toString` | 277 | 7.5s |  |
| 838 | `primitive_valueOf` | 285 | 7.2s |  |
| 839 | `print_job_options` | 3 | 7.2s |  |
| 840 | `property_is_enumerable` | 114 | 8.0s |  |
| 841 | `property_is_enumerable_reset` | 23 | 7.3s |  |
| 842 | `property_priority` | 22 | 7.7s |  |
| 843 | `property_priority_chained` | 4 | 7.3s |  |
| 844 | `property_priority_definition_names_order` | 2 | 7.7s |  |
| 845 | `property_priority_three_level` | 6 | 7.5s |  |
| 846 | `propertyisenumerable_namespaces` | 6 | 7.3s |  |
| 847 | `prototype_set_null` | 7 | 7.2s |  |
| 848 | `proxy_callproperty` | 24 | 7.3s |  |
| 849 | `proxy_deleteproperty` | 64 | 7.4s |  |
| 850 | `proxy_enumeration` | 34 | 7.3s |  |
| 851 | `proxy_getproperty` | 77 | 7.4s |  |
| 852 | `proxy_hasownproperty` | 8 | 2.5s |  |
| 853 | `proxy_hasproperty` | 32 | 7.3s |  |
| 854 | `proxy_not_overridden` | 54 | 7.3s |  |
| 855 | `proxy_serialize` | 9 | 7.3s |  |
| 856 | `proxy_setproperty` | 42 | 7.3s |  |
| 857 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.2s |  |
| 858 | `qname_constr` | 32 | 7.3s |  |
| 859 | `qname_constr_namespace` | 24 | 7.3s |  |
| 860 | `qname_enumeration` | 9 | 7.3s |  |
| 861 | `qname_indexing` | 23 | 2.5s |  |
| 862 | `qname_tostring` | 25 | 7.3s |  |
| 863 | `qname_valueof` | 29 | 7.3s |  |
| 864 | `rectangle` | 1094 | 8.0s |  |
| 865 | `regexp_constr` | 148 | 7.5s |  |
| 866 | `regexp_exec` | 19 | 7.3s |  |
| 867 | `regexp_extended` | 47 | 7.3s |  |
| 868 | `regexp_multiargs` | 1 | 7.2s |  |
| 869 | `regexp_test` | 27 | 2.5s |  |
| 870 | `regexp_toString` | 10 | 7.3s |  |
| 871 | `register_script_refresh` | 35 | 27.4s |  |
| 872 | `remove_child_clear_field` | 88 | 26.0s |  |
| 873 | `remove_dobj` | 3 | 25.5s |  |
| 874 | `resolve_order` | 4 | 6.9s |  |
| 875 | `responder_null_callbacks` | 1 | 25.4s |  |
| 876 | `rng` | 1 | 8.2s |  |
| 877 | `rootless` | 42 | 6.9s |  |
| 878 | `rshift` | 1058 | 18.8s |  |
| 879 | `rtqname_not_namespace` | 12 | 7.0s |  |
| 880 | `sandbox_type_inherited` | 2 | 7.1s |  |
| 881 | `sandbox_type_local_file` | 1 | 6.8s |  |
| 882 | `sandbox_type_local_network` | 1 | 6.6s |  |
| 883 | `scene_constr` | 8 | 6.9s |  |
| 884 | `scope_optimizations` | 4 | 6.8s |  |
| 885 | `scopes_dont_cache/order-1` | 1 | 25.5s |  |
| 886 | `scopes_dont_cache/order-2` | 1 | 0.4s |  |
| 887 | `security_domain_current` | 2 | 6.9s |  |
| 888 | `selection` | 239 | 7.3s |  |
| 889 | `set_local_0` | 31 | 2.4s |  |
| 890 | `set_property_is_enumerable` | 85 | 7.4s |  |
| 891 | `shaderparameter_value` | 4 | 6.9s |  |
| 892 | `shape_drawrect` | 54 | 7.0s |  |
| 893 | `shared_object_no_root` | 3 | 6.9s |  |
| 894 | `simplebutton_added_to_stage` | 45 | 26.0s |  |
| 895 | `simplebutton_childevents` | 86 | 26.2s |  |
| 896 | `simplebutton_childevents_nested` | 54 | 7.3s |  |
| 897 | `simplebutton_childevents_sprite` | 13 | 7.1s |  |
| 898 | `simplebutton_childprops` | 144 | 7.2s |  |
| 899 | `simplebutton_childshuffle` | 23 | 6.9s |  |
| 900 | `simplebutton_constr` | 36 | 7.2s |  |
| 901 | `simplebutton_constr_childevents` | 48 | 7.3s |  |
| 902 | `simplebutton_constr_params` | 42 | 7.1s |  |
| 903 | `simplebutton_mouseenabled` | 26 | 7.0s |  |
| 904 | `simplebutton_multi_children` | 19 | 7.2s |  |
| 905 | `simplebutton_structure` | 27 | 7.1s |  |
| 906 | `simplebutton_symbolclass` | 68 | 7.2s |  |
| 907 | `slot_disp_id_shared_numbering` | 1 | 25.5s |  |
| 908 | `slots_force_autoassigned` | 1 | 28.0s |  |
| 909 | `socket_after_disconnect` | 1 | 7.4s |  |
| 910 | `socket_close` | 2 | 7.5s |  |
| 911 | `socket_connect` | 4 | 7.5s |  |
| 912 | `socket_errors` | 56 | 8.0s |  |
| 913 | `socket_read_big` | 48 | 7.4s |  |
| 914 | `socket_read_little` | 48 | 2.4s |  |
| 915 | `socket_read_write_object` | 8 | 7.3s |  |
| 916 | `socket_write_big` | 15 | 7.6s |  |
| 917 | `socket_write_little` | 14 | 7.3s |  |
| 918 | `sound_constructor_with_args` | 6 | 7.6s |  |
| 919 | `sound_embeddedprops` | 26 | 7.6s |  |
| 920 | `sound_play` | 19 | 7.6s |  |
| 921 | `sound_rootless` | 7 | 7.3s |  |
| 922 | `sound_valueof` | 33 | 7.3s |  |
| 923 | `soundchannel_soundtransform` | 835 | 28.8s |  |
| 924 | `soundchannel_soundtransform_exists` | 5 | 26.6s |  |
| 925 | `soundchannel_stop` | 8 | 26.7s |  |
| 926 | `soundmixer_buffertime` | 5 | 7.3s |  |
| 927 | `soundmixer_stopall` | 6 | 26.9s |  |
| 928 | `soundtransform` | 442 | 12.7s |  |
| 929 | `space_justifier_clone` | 12 | 7.3s |  |
| 930 | `sprite_with_frames` | 0 | 26.7s |  |
| 931 | `stage3d_agal_cross_product` | 0 | 9.6s |  |
| 932 | `stage3d_agal_upload_errors` | 66 | 9.8s |  |
| 933 | `stage3d_bitmap` | 0 | 31.3s |  |
| 934 | `stage3d_blend` | 81 | 28.9s |  |
| 935 | `stage3d_context3d_string_args` | 158 | 8.3s |  |
| 936 | `stage3d_errors` | 7 | 7.3s |  |
| 937 | `stage3d_errors_atf` | 3 | 8.6s |  |
| 938 | `stage3d_errors_swf_29` | 6 | 7.5s |  |
| 939 | `stage3d_float1_index` | 0 | 29.2s |  |
| 940 | `stage3d_fractal` | 0 | 29.7s |  |
| 941 | `stage3d_ignore_sampler_override` | 0 | 30.7s |  |
| 942 | `stage3d_multistage_triangle` | 3 | 10.3s |  |
| 943 | `stage3d_program_constants_bytearray_be` | 0 | 32.6s |  |
| 944 | `stage3d_program_constants_bytearray_le` | 0 | 29.9s |  |
| 945 | `stage3d_program_constants_invalid_input` | 21 | 26.6s |  |
| 946 | `stage3d_raytrace` | 0 | 51.3s |  |
| 947 | `stage3d_rotating_cube` | 0 | 9.7s |  |
| 948 | `stage3d_sampler` | 0 | 8.9s |  |
| 949 | `stage3d_sampler_partial_upload` | 0 | 8.9s |  |
| 950 | `stage3d_stencil` | 0 | 28.4s |  |
| 951 | `stage3d_texture` | 0 | 14.0s |  |
| 952 | `stage3d_texture_bytearray` | 0 | 10.3s |  |
| 953 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.7s |  |
| 954 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.8s |  |
| 955 | `stage3d_triangle` | 0 | 9.1s |  |
| 956 | `stage3d_triangle_bytes4` | 0 | 9.1s |  |
| 957 | `stage3d_triangle_float1` | 0 | 9.0s |  |
| 958 | `stage3d_triangle_index_upload` | 0 | 9.0s |  |
| 959 | `stage3d_x_y` | 22 | 6.8s |  |
| 960 | `stage_access` | 10 | 6.9s |  |
| 961 | `stage_displayobject_properties` | 24 | 6.7s |  |
| 962 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.8s |  |
| 963 | `stage_framerate_nan` | 7 | 6.8s |  |
| 964 | `stage_framerate_negative` | 6 | 6.7s |  |
| 965 | `stage_framerate_zero` | 6 | 6.8s |  |
| 966 | `stage_invalidate` | 38 | 7.0s |  |
| 967 | `stage_loaderinfo_properties` | 24 | 26.3s |  |
| 968 | `stage_mousechildren` | 2 | 6.7s |  |
| 969 | `stage_mouseenabled` | 15 | 6.6s |  |
| 970 | `stage_overriden_setters` | 31 | 6.9s |  |
| 971 | `stage_properties` | 30 | 6.8s |  |
| 972 | `stage_properties2` | 213 | 7.0s |  |
| 973 | `stage_stage3Ds_vector` | 1 | 6.7s |  |
| 974 | `static_length` | 24 | 7.0s |  |
| 975 | `static_text` | 3 | 7.0s |  |
| 976 | `static_var_with_this_in_ctor` | 2 | 6.8s |  |
| 977 | `statictext_text` | 8 | 6.9s |  |
| 978 | `stored_properties` | 11 | 6.8s |  |
| 979 | `strict_equality` | 34 | 6.8s |  |
| 980 | `string_call` | 13 | 6.7s |  |
| 981 | `string_case` | 23 | 6.7s |  |
| 982 | `string_char_at` | 27 | 6.7s |  |
| 983 | `string_char_code_at` | 28 | 2.0s |  |
| 984 | `string_concat_fromcharcode` | 37 | 26.2s |  |
| 985 | `string_constr` | 25 | 25.9s |  |
| 986 | `string_indexof_lastindexof` | 87 | 7.3s |  |
| 987 | `string_length` | 16 | 7.0s |  |
| 988 | `string_locale_compare` | 39 | 7.3s |  |
| 989 | `string_match` | 51 | 7.3s |  |
| 990 | `string_relational_compare` | 4 | 7.0s |  |
| 991 | `string_replace` | 51 | 7.3s |  |
| 992 | `string_search` | 41 | 7.1s |  |
| 993 | `string_slice_substr_substring` | 170 | 8.1s |  |
| 994 | `string_split` | 29 | 7.1s |  |
| 995 | `string_substr_negative` | 21 | 7.0s |  |
| 996 | `string_substr_weird` | 182 | 6.9s |  |
| 997 | `stylesheet` | 221 | 7.7s |  |
| 998 | `stylesheet_parse_color` | 69 | 7.2s |  |
| 999 | `stylesheet_transform` | 307 | 7.6s |  |
| 1000 | `sub_super_same_field` | 12 | 2.5s |  |
| 1001 | `subclass_superclass_linked_symbol` | 4 | 7.7s |  |
| 1002 | `subtract` | 1058 | 19.3s |  |
| 1003 | `super_get_call` | 12 | 7.0s |  |
| 1004 | `supercall_two_classobjects` | 2 | 7.0s |  |
| 1005 | `supercalls_coerce` | 8 | 7.2s |  |
| 1006 | `supercalls_weird` | 2 | 6.7s |  |
| 1007 | `superinterface_call` | 20 | 7.1s |  |
| 1008 | `superinterface_instanceof` | 18 | 7.1s |  |
| 1009 | `swf8` | 1 | 7.0s |  |
| 1010 | `swf_10_queued_goto_scripts_construct` | 52 | 26.3s |  |
| 1011 | `swf_9_goto_in_enter_frame` | 17 | 7.1s |  |
| 1012 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.1s |  |
| 1013 | `swf_9_queued_goto_scripts` | 6 | 26.4s |  |
| 1014 | `swf_9_queued_goto_scripts_construct` | 28 | 0.7s |  |
| 1015 | `swf_9_versioning` | 2 | 7.1s |  |
| 1016 | `swf_wrong_frame_count` | 38 | 7.3s |  |
| 1017 | `swf_wrong_frame_count_isplaying` | 22 | 7.0s |  |
| 1018 | `symbol_class_binary_data` | 8 | 7.0s |  |
| 1019 | `symbol_class_conflict` | 4 | 7.2s |  |
| 1020 | `symbol_class_root_not_zero` | 1 | 6.9s |  |
| 1021 | `symbolclass_invalid_utf8` | 2 | 7.0s |  |
| 1022 | `system_exit` | 3 | 7.0s |  |
| 1023 | `system_setclipboard_null` | 1 | 7.1s |  |
| 1024 | `tab_ordering_arrows` | 998 | 19.5s |  |
| 1025 | `tab_ordering_automatic_advanced` | 184 | 0.5s |  |
| 1026 | `tab_ordering_automatic_basic` | 45 | 19.8s |  |
| 1027 | `tab_ordering_children` | 116 | 0.5s |  |
| 1028 | `tab_ordering_custom_basic` | 34 | 0.4s |  |
| 1029 | `tab_ordering_stage_tab_children` | 32 | 0.5s |  |
| 1030 | `tab_ordering_stage_tab_children_remove_root` | 5 | 0.5s |  |
| 1031 | `tab_ordering_tabbable` | 47 | 0.4s |  |
| 1032 | `tabstop_properties` | 105 | 19.6s |  |
| 1033 | `text_element_basic` | 34 | 0.4s |  |
| 1034 | `text_engine_fontdescription` | 27 | 0.4s |  |
| 1035 | `text_engine_groupelement` | 64 | 0.4s |  |
| 1036 | `text_run` | 7 | 0.4s |  |
| 1037 | `textblock_createline_errors` | 23 | 0.4s |  |
| 1038 | `textblock_createline_fte` | 9 | 19.8s |  |
| 1039 | `textblock_properties` | 118 | 0.5s |  |
| 1040 | `textbox_click` | 37 | 19.9s |  |
| 1041 | `textfield_event` | 66 | 0.5s |  |
| 1042 | `textfield_focusin_event` | 9 | 0.4s |  |
| 1043 | `textfield_input_dead_keys_windows` | 15 | 0.4s |  |
| 1044 | `textfield_input_events` | 25 | 11.4s |  |
| 1045 | `textfield_unload` | 39 | 19.6s |  |
| 1046 | `textformat` | 1134 | 0.4s |  |
| 1047 | `textformat_display` | 14 | 0.4s |  |
| 1048 | `textformat_font_max_length` | 4 | 0.4s |  |
| 1049 | `textline_inapplicable_properties` | 10 | 0.4s |  |
| 1050 | `textline_name` | 1 | 0.4s |  |
| 1051 | `textline_raw_text_length` | 30 | 0.4s |  |
| 1052 | `textline_splitting_basic` | 76 | 0.5s |  |
| 1053 | `textline_throwerror` | 30 | 0.4s |  |
| 1054 | `textline_validity` | 162 | 0.4s |  |
| 1055 | `throw` | 3 | 0.4s |  |
| 1056 | `timeline_scripts` | 3 | 19.7s |  |
| 1057 | `timer` | 90 | 0.5s |  |
| 1058 | `timer_events` | 3 | 0.4s |  |
| 1059 | `timer_finished` | 11 | 0.4s |  |
| 1060 | `timer_invalid_delay` | 30 | 0.4s |  |
| 1061 | `timer_reset` | 8 | 26.4s |  |
| 1062 | `timer_setdelay` | 5 | 25.9s |  |
| 1063 | `trace` | 12 | 7.0s |  |
| 1064 | `truthiness` | 30 | 7.0s |  |
| 1065 | `try_catch` | 11 | 7.1s |  |
| 1066 | `try_catch_typed` | 12 | 7.1s |  |
| 1067 | `typeof` | 30 | 7.1s |  |
| 1068 | `uint_constr` | 92 | 7.2s |  |
| 1069 | `uint_tofixed` | 1215 | 6.9s |  |
| 1070 | `uint_toprecision` | 1125 | 7.2s |  |
| 1071 | `uint_tostring` | 3375 | 7.3s |  |
| 1072 | `uncaught_error_basic` | 2 | 7.0s |  |
| 1073 | `unchecked_function` | 15 | 7.0s |  |
| 1074 | `unescape` | 28 | 7.0s |  |
| 1075 | `url_loader` | 25 | 7.1s |  |
| 1076 | `url_vars` | 27 | 7.2s |  |
| 1077 | `urlrequest` | 18 | 2.2s |  |
| 1078 | `urlstream_basic` | 5 | 7.1s |  |
| 1079 | `urshift` | 1058 | 19.3s |  |
| 1080 | `utils3d` | 7 | 2.4s |  |
| 1081 | `vector3d` | 397 | 11.7s |  |
| 1082 | `vector_class` | 36 | 7.4s |  |
| 1083 | `vector_class_call` | 11 | 7.2s |  |
| 1084 | `vector_coercion` | 66 | 7.8s |  |
| 1085 | `vector_concat` | 90 | 7.6s |  |
| 1086 | `vector_constr` | 107 | 7.7s |  |
| 1087 | `vector_enumeration` | 5 | 7.0s |  |
| 1088 | `vector_every` | 92 | 7.8s |  |
| 1089 | `vector_filter` | 95 | 7.9s |  |
| 1090 | `vector_holes` | 24 | 7.0s |  |
| 1091 | `vector_indexof` | 302 | 11.8s |  |
| 1092 | `vector_insertat` | 270 | 8.1s |  |
| 1093 | `vector_int_access` | 4 | 7.0s |  |
| 1094 | `vector_int_delete` | 11 | 7.0s |  |
| 1095 | `vector_join` | 58 | 7.5s |  |
| 1096 | `vector_lastindexof` | 302 | 6.9s |  |
| 1097 | `vector_legacy` | 10 | 7.0s |  |
| 1098 | `vector_map` | 85 | 7.7s |  |
| 1099 | `vector_object_final` | 1 | 6.9s |  |
| 1100 | `vector_object_toString` | 10 | 26.4s |  |
| 1101 | `vector_pushpop` | 255 | 27.2s |  |
| 1102 | `vector_reborrow_bug` | 10 | 7.0s |  |
| 1103 | `vector_removeat` | 172 | 8.1s |  |
| 1104 | `vector_reverse` | 232 | 8.2s |  |
| 1105 | `vector_shiftunshift` | 252 | 6.9s |  |
| 1106 | `vector_slice` | 331 | 8.8s |  |
| 1107 | `vector_sort` | 905 | 16.6s |  |
| 1108 | `vector_splice` | 693 | 11.2s |  |
| 1109 | `vector_splice_fixed_bug_compat` | 4 | 7.2s |  |
| 1110 | `vector_tostring` | 79 | 7.6s |  |
| 1111 | `verification` | 8 | 7.2s |  |
| 1112 | `verify_abnormal_loop` | 1 | 6.9s |  |
| 1113 | `verify_dxns_without_flag` | 3 | 7.4s |  |
| 1114 | `verify_exception_target_two_jumps` | 1 | 6.9s |  |
| 1115 | `verify_exception_targets_edge_case` | 1 | 6.9s |  |
| 1116 | `verify_illegal_opcode` | 1 | 2.6s |  |
| 1117 | `verify_jump_to_middle_of_op` | 1 | 7.0s |  |
| 1118 | `verify_lookup_switch_edge_case` | 1 | 6.9s |  |
| 1119 | `verify_method_info_oob` | 1 | 0.6s |  |
| 1120 | `verify_stack` | 5 | 7.0s |  |
| 1121 | `verify_typecheck` | 4 | 6.9s |  |
| 1122 | `verify_unreachable_exception` | 2 | 6.9s |  |
| 1123 | `versioned_isplaying` | 2 | 7.1s |  |
| 1124 | `virtual_properties` | 16 | 2.6s |  |
| 1125 | `with` | 4 | 7.0s |  |
| 1126 | `wrong_arg_count` | 7 | 7.1s |  |
| 1127 | `xml_abstract_equality` | 36 | 7.2s |  |
| 1128 | `xml_advanced` | 52 | 7.0s |  |
| 1129 | `xml_appendchild` | 10 | 6.9s |  |
| 1130 | `xml_appendchild_swf_v21` | 13 | 2.6s |  |
| 1131 | `xml_as_attribute` | 9 | 6.9s |  |
| 1132 | `xml_attribute` | 35 | 7.1s |  |
| 1133 | `xml_attribute_name` | 40 | 7.0s |  |
| 1134 | `xml_basic` | 33 | 7.0s |  |
| 1135 | `xml_child` | 25 | 7.0s |  |
| 1136 | `xml_childindex` | 7 | 7.0s |  |
| 1137 | `xml_children` | 43 | 7.5s |  |
| 1138 | `xml_class_call` | 9 | 7.1s |  |
| 1139 | `xml_contains` | 197 | 7.2s |  |
| 1140 | `xml_copy` | 20 | 25.5s |  |
| 1141 | `xml_ctor_from_tostring` | 23 | 25.6s |  |
| 1142 | `xml_delete` | 114 | 7.0s |  |
| 1143 | `xml_descendants` | 83 | 6.9s |  |
| 1144 | `xml_elements` | 6 | 6.8s |  |
| 1145 | `xml_equals_namespace_check` | 2 | 6.9s |  |
| 1146 | `xml_explicit_use_namespace` | 5 | 6.8s |  |
| 1147 | `xml_getdescendants_qname` | 21 | 6.9s |  |
| 1148 | `xml_has_property_via_in` | 26 | 6.9s |  |
| 1149 | `xml_hasownproperty` | 6 | 6.9s |  |
| 1150 | `xml_ignore_white` | 6 | 6.9s |  |
| 1151 | `xml_length` | 2 | 6.8s |  |
| 1152 | `xml_list_as_attribute` | 9 | 6.8s |  |
| 1153 | `xml_list_concat` | 20 | 6.9s |  |
| 1154 | `xml_list_ctor_errors` | 34 | 6.9s |  |
| 1155 | `xml_list_delete_clear_parent` | 6 | 6.8s |  |
| 1156 | `xml_list_enumerate` | 4 | 6.8s |  |
| 1157 | `xml_methods_settings` | 3 | 6.8s |  |
| 1158 | `xml_mismatched_tag` | 37 | 6.9s |  |
| 1159 | `xml_namespace` | 39 | 6.8s |  |
| 1160 | `xml_namespace_methods` | 245 | 6.9s |  |
| 1161 | `xml_namespaced_property` | 7 | 6.9s |  |
| 1162 | `xml_no_namespace` | 1 | 6.8s |  |
| 1163 | `xml_nodekind` | 3 | 6.8s |  |
| 1164 | `xml_normalize` | 35 | 6.9s |  |
| 1165 | `xml_notification_bubbling` | 361 | 6.9s |  |
| 1166 | `xml_parent` | 8 | 6.8s |  |
| 1167 | `xml_set_children` | 17 | 6.9s |  |
| 1168 | `xml_set_name` | 34 | 6.8s |  |
| 1169 | `xml_settings` | 6 | 2.3s |  |
| 1170 | `xml_simple_complex_content` | 47 | 6.9s |  |
| 1171 | `xml_socket` | 11 | 6.9s |  |
| 1172 | `xml_text` | 7 | 6.8s |  |
| 1173 | `xml_tostring` | 6 | 6.8s |  |
| 1174 | `xml_tostring_namespace` | 12 | 6.6s |  |
| 1175 | `xml_unescaping` | 23 | 6.9s |  |
| 1176 | `xml_weird_ignores` | 54 | 2.4s |  |
| 1177 | `xml_wildcard` | 11 | 6.9s |  |
| 1178 | `xmldocument` | 254 | 7.0s |  |
| 1179 | `xmlnode` | 3540 | 7.1s |  |
| 1180 | `zero_frame_clip` | 3 | 7.0s |  |

## Ruffle-Matched Tests

**33 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 6.9s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.4s |  |
| 3 | `blend_transform` | 1 | 1 | 7.0s |  |
| 4 | `bounds_mode` | 6 | 6 | 7.2s |  |
| 5 | `coerce_property` | 3 | 3 | 7.1s |  |
| 6 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.1s |  |
| 7 | `dictionary_weak_keys` | 1 | 1 | 26.1s |  |
| 8 | `displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 15 | 25.6s |  |
| 9 | `edittext_device_transform_layout` | 20 | 20 | 7.3s |  |
| 10 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.3s |  |
| 11 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 7.0s |  |
| 12 | `edittext_tab_stops` | 6 | 6 | 5.2s |  |
| 13 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 1.9s |  |
| 14 | `error_1034_debug_string` | 19 | 19 | 6.0s |  |
| 15 | `freestanding_superclass` | 2 | 4 | 7.3s |  |
| 16 | `goto_framescript_queued` | 5 | 5 | 23.4s |  |
| 17 | `graphics_draw_path` | 50 | 50 | 24.1s |  |
| 18 | `groupelement_text` | 2 | 2 | 6.4s |  |
| 19 | `int_toexponential` | 76 | 76 | 7.4s |  |
| 20 | `matrix3d_append_rotation` | 1 | 3 | 7.0s |  |
| 21 | `matrix3d_recompose_edge_cases` | 85 | 85 | 7.4s |  |
| 22 | `simplebutton_childevents_script_order` | 4 | 4 | 7.2s |  |
| 23 | `slot_holes_fail` | 1 | 1 | 6.9s |  |
| 24 | `slot_id_exceeds_trait_count` | 1 | 1 | 28.4s |  |
| 25 | `soundchannel_position` | 74 | 74 | 27.6s |  |
| 26 | `soundchannel_soundcomplete` | 10 | 10 | 7.5s |  |
| 27 | `sprite_dropTarget` | 15 | 15 | 7.3s |  |
| 28 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.4s |  |
| 29 | `textblock_line_changes` | 44 | 44 | 0.5s |  |
| 30 | `textblock_releaselines` | 4 | 4 | 0.5s |  |
| 31 | `uint_toexponential` | 100 | 100 | 7.2s |  |
| 32 | `uncaught_errors_stringified` | 15 | 15 | 7.0s |  |
| 33 | `weird_superinterface_properties` | 1 | 1 | 7.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**20 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 2 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 3 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 4 | `number_tostring` | 84.0% | 882 | 1050 | 168 |  |
| 5 | `vector3d_near_equals` | 83.8% | 67 | 80 | 13 |  |
| 6 | `large_preload_from_bytes` | 80.4% | 41 | 51 | 10 |  |
| 7 | `matrix3d_copy_from` | 78.9% | 15 | 19 | 4 |  |
| 8 | `matrix3d_copy_to_matrix3d` | 78.9% | 15 | 19 | 4 |  |
| 9 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 10 | `displayobject_getrect` | 68.8% | 11 | 16 | 5 |  |
| 11 | `number_to_string` | 67.1% | 237 | 353 | 116 |  |
| 12 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 13 | `primitive_keys` | 61.1% | 33 | 54 | 21 |  |
| 14 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 15 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 16 | `textline_atom_index_at_char_index` | 52.5% | 21 | 40 | 19 |  |
| 17 | `bitmapdata_applyfilter_identity` | 50.0% | 2 | 4 | 2 |  |
| 18 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 19 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |
| 20 | `xml_duplicate_attribute` | 50.0% | 7 | 14 | 7 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**48 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 2 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 3 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 4 | `number_tostring` | 84.0% | 882/1050 | 1050 | 1050 |  |
| 5 | `vector3d_near_equals` | 83.8% | 67/80 | 80 | 80 |  |
| 6 | `large_preload_from_bytes` | 80.4% | 41/51 | 51 | 51 |  |
| 7 | `matrix3d_copy_from` | 78.9% | 15/19 | 16 | 19 |  |
| 8 | `matrix3d_copy_to_matrix3d` | 78.9% | 15/19 | 16 | 19 |  |
| 9 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 10 | `displayobject_getrect` | 68.8% | 11/16 | 16 | 16 |  |
| 11 | `number_to_string` | 67.1% | 237/353 | 353 | 353 |  |
| 12 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 13 | `primitive_keys` | 61.1% | 33/54 | 54 | 54 |  |
| 14 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 15 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 16 | `textline_atom_index_at_char_index` | 52.5% | 21/40 | 37 | 40 |  |
| 17 | `bitmapdata_applyfilter_identity` | 50.0% | 2/4 | 4 | 4 |  |
| 18 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 19 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 20 | `xml_duplicate_attribute` | 50.0% | 7/14 | 14 | 14 |  |
| 21 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 22 | `mouse_pick_loader_avm1` | 38.1% | 16/42 | 40 | 42 |  |
| 23 | `bitmapdata_copypixels_alpha_merge` | 33.3% | 3/9 | 9 | 9 |  |
| 24 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 25 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 26 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 27 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 28 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 29 | `bitmapdata_copypixels_alpha_combine` | 15.4% | 2/13 | 13 | 13 |  |
| 30 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 31 | `loader_duplicate_class` | 6.2% | 3/48 | 46 | 48 |  |
| 32 | `loader_events_2` | 5.7% | 2/35 | 31 | 35 |  |
| 33 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 34 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 35 | `flash_ui_mouse_cursor` | 2.9% | 1/35 | 3 | 35 |  |
| 36 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 37 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 23 | 49 |  |
| 38 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 39 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 40 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 41 | `matrix3d_append_prepend_scale` | 0.0% | 0/86 | 46 | 86 |  |
| 42 | `matrix3d_interpolate` | 0.0% | 0/21 | 3 | 21 |  |
| 43 | `movieclip_addframescript_error` | 0.0% | 0/9 | 0 | 9 |  |
| 44 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 45 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 46 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 47 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 48 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
