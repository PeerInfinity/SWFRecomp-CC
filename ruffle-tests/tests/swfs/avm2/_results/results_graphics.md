# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-15 09:18 UTC

**Git SHA**: `86434112a7`

**Run Duration**: 250m 47s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1243 |
| Passing | **1154** (92.8%) |
| Ruffle-matched | 31 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1185** (95.3%) |
| Failing | 58 |
| Total expected lines | 154168 |
| Matching lines | 141995 (92.1%) |
| Mismatched lines | 12173 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 58 | 100.0% |

## Passing Tests

**1154 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 27.9s |  |
| 2 | `accessibility` | 1 | 8.1s |  |
| 3 | `accessibilityimplementation` | 18 | 8.3s |  |
| 4 | `activation_class` | 6 | 27.8s |  |
| 5 | `add` | 1058 | 20.4s |  |
| 6 | `agal_compiler` | 13 | 10.5s |  |
| 7 | `air_datagram_socket` | 1 | 10.1s |  |
| 8 | `air_hidden_lookup` | 2 | 8.1s |  |
| 9 | `air_ifilepromise` | 1 | 8.0s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 8.2s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 1.5s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 1.5s |  |
| 13 | `all_classes/display/swf10` | 2569 | 8.1s |  |
| 14 | `all_classes/display/swf11` | 2593 | 1.5s |  |
| 15 | `all_classes/display/swf12` | 2593 | 1.5s |  |
| 16 | `all_classes/display/swf13` | 2671 | 1.5s |  |
| 17 | `all_classes/display/swf30` | 2936 | 1.4s |  |
| 18 | `all_classes/display/swf9` | 1959 | 1.4s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 8.1s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 1.4s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 1.4s |  |
| 22 | `all_classes/errors/swf10` | 140 | 8.0s |  |
| 23 | `all_classes/errors/swf30` | 140 | 1.4s |  |
| 24 | `all_classes/errors/swf9` | 121 | 1.4s |  |
| 25 | `all_classes/security/swf11` | 3 | 8.0s |  |
| 26 | `all_classes/security/swf12` | 19 | 1.4s |  |
| 27 | `all_classes/security/swf13` | 53 | 1.4s |  |
| 28 | `all_classes/security/swf30` | 53 | 1.4s |  |
| 29 | `all_classes/xml/swf30` | 116 | 8.0s |  |
| 30 | `all_classes/xml/swf9` | 116 | 1.4s |  |
| 31 | `amf_array_serialization` | 17 | 30.2s |  |
| 32 | `amf_custom_obj` | 26 | 8.1s |  |
| 33 | `amf_dictionary` | 9 | 8.0s |  |
| 34 | `amf_function` | 46 | 8.0s |  |
| 35 | `amf_invalid_date` | 2 | 8.0s |  |
| 36 | `amf_missing_prop` | 6 | 8.1s |  |
| 37 | `amf_nondynamic_function_prop` | 6 | 8.0s |  |
| 38 | `amf_setter_error` | 8 | 8.7s |  |
| 39 | `amf_vector` | 40 | 8.6s |  |
| 40 | `amf_xml` | 6 | 8.4s |  |
| 41 | `application_domain` | 4 | 8.6s |  |
| 42 | `applicationdomain_getqualifieddefinitionnames` | 9 | 8.7s |  |
| 43 | `applicationdomain_hasdefinition_null` | 2 | 30.0s |  |
| 44 | `array_access` | 18 | 8.5s |  |
| 45 | `array_access_interpreter` | 4 | 8.5s |  |
| 46 | `array_access_no_pubns` | 2 | 8.5s |  |
| 47 | `array_concat` | 41 | 8.5s |  |
| 48 | `array_constr` | 10 | 8.4s |  |
| 49 | `array_delete` | 44 | 8.4s |  |
| 50 | `array_enumeration` | 10 | 8.3s |  |
| 51 | `array_enumeration_elements` | 11 | 8.2s |  |
| 52 | `array_every` | 8 | 8.3s |  |
| 53 | `array_filter` | 6 | 8.2s |  |
| 54 | `array_foreach` | 18 | 8.1s |  |
| 55 | `array_hasownproperty` | 11 | 8.1s |  |
| 56 | `array_holes` | 9 | 8.1s |  |
| 57 | `array_index_max` | 84 | 8.2s |  |
| 58 | `array_indexof` | 25 | 8.2s |  |
| 59 | `array_join` | 26 | 8.2s |  |
| 60 | `array_lastindexof` | 29 | 8.1s |  |
| 61 | `array_length` | 14 | 8.1s |  |
| 62 | `array_literal` | 3 | 8.1s |  |
| 63 | `array_map` | 8 | 8.0s |  |
| 64 | `array_pop` | 52 | 8.2s |  |
| 65 | `array_push` | 24 | 8.1s |  |
| 66 | `array_reborrow_bug` | 6 | 8.0s |  |
| 67 | `array_reverse` | 28 | 8.2s |  |
| 68 | `array_shift` | 51 | 3.6s |  |
| 69 | `array_slice` | 39 | 8.2s |  |
| 70 | `array_some` | 8 | 8.2s |  |
| 71 | `array_sort` | 297 | 8.7s |  |
| 72 | `array_sort_fun_swf12` | 2 | 8.1s |  |
| 73 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 74 | `array_sort_random` | 210 | 8.1s |  |
| 75 | `array_sort_swf10_32bit` | 1 | 8.1s |  |
| 76 | `array_sorton` | 545 | 8.8s |  |
| 77 | `array_sparse_ops` | 41 | 27.6s |  |
| 78 | `array_splice` | 133 | 8.2s |  |
| 79 | `array_splice2` | 428 | 8.3s |  |
| 80 | `array_splice_types` | 48 | 8.0s |  |
| 81 | `array_storage` | 8 | 8.0s |  |
| 82 | `array_tolocalestring` | 9 | 7.9s |  |
| 83 | `array_tostring` | 12 | 8.0s |  |
| 84 | `array_unshift` | 24 | 8.0s |  |
| 85 | `array_valueof` | 9 | 7.9s |  |
| 86 | `array_vector_null_callback` | 10 | 8.0s |  |
| 87 | `astype` | 28 | 27.2s |  |
| 88 | `astypelate` | 24 | 8.1s |  |
| 89 | `astypelate_propagates` | 1 | 7.9s |  |
| 90 | `asymmetric_key_events` | 11 | 8.2s |  |
| 91 | `av_classes` | 340 | 8.3s |  |
| 92 | `avm1movie_addcallback_call` | 14 | 8.1s |  |
| 93 | `avm2_catchup_dobj` | 158 | 8.8s |  |
| 94 | `away3d_advanced_shallow_water_demo` | 0 | 96.5s |  |
| 95 | `bevel_filter` | 187 | 8.3s |  |
| 96 | `bitand` | 1058 | 19.9s |  |
| 97 | `bitmap_constr` | 17 | 8.2s |  |
| 98 | `bitmap_data` | 1000 | 16.2s |  |
| 99 | `bitmap_pixelsnapping` | 2 | 27.7s |  |
| 100 | `bitmap_properties` | 23 | 8.0s |  |
| 101 | `bitmap_subclass` | 7 | 9.4s |  |
| 102 | `bitmap_subclass_properties` | 9 | 8.4s |  |
| 103 | `bitmap_timeline` | 9 | 8.2s |  |
| 104 | `bitmapdata_accuracy` | 1 | 48.6s |  |
| 105 | `bitmapdata_applyfilter_blur` | 0 | 28.5s |  |
| 106 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.8s |  |
| 107 | `bitmapdata_applyfilter_destpoint` | 0 | 27.9s |  |
| 108 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 28.6s |  |
| 109 | `bitmapdata_clone` | 13 | 8.2s |  |
| 110 | `bitmapdata_colortransform` | 0 | 8.4s |  |
| 111 | `bitmapdata_colortransform_oob` | 2 | 7.9s |  |
| 112 | `bitmapdata_constr` | 22 | 8.1s |  |
| 113 | `bitmapdata_constructor_from_timeline` | 1 | 8.3s |  |
| 114 | `bitmapdata_copychannel` | 0 | 29.5s |  |
| 115 | `bitmapdata_copypixels` | 23 | 29.2s |  |
| 116 | `bitmapdata_copypixels_blend_over` | 1 | 8.8s |  |
| 117 | `bitmapdata_copypixelstobytearray` | 39 | 8.5s |  |
| 118 | `bitmapdata_dispose` | 7 | 8.5s |  |
| 119 | `bitmapdata_draw` | 0 | 31.1s |  |
| 120 | `bitmapdata_draw_alpha_erase` | 8 | 8.7s |  |
| 121 | `bitmapdata_draw_colortransform` | 0 | 29.9s |  |
| 122 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 30.2s |  |
| 123 | `bitmapdata_draw_filters` | 0 | 29.8s |  |
| 124 | `bitmapdata_draw_masks` | 0 | 8.5s |  |
| 125 | `bitmapdata_draw_rotation` | 0 | 8.8s |  |
| 126 | `bitmapdata_draw_self_via_graphic` | 0 | 8.7s |  |
| 127 | `bitmapdata_draw_stage` | 0 | 29.6s |  |
| 128 | `bitmapdata_drawwithquality` | 0 | 8.8s |  |
| 129 | `bitmapdata_embedded` | 9 | 8.8s |  |
| 130 | `bitmapdata_fillrect` | 0 | 8.6s |  |
| 131 | `bitmapdata_filter_sourcerect` | 0 | 30.1s |  |
| 132 | `bitmapdata_floodfill` | 35 | 8.4s |  |
| 133 | `bitmapdata_getpixels` | 39 | 30.1s |  |
| 134 | `bitmapdata_getvector` | 27 | 3.6s |  |
| 135 | `bitmapdata_histogram` | 59 | 3.5s |  |
| 136 | `bitmapdata_hittest` | 112 | 9.2s |  |
| 137 | `bitmapdata_hittest_threshold` | 18 | 8.5s |  |
| 138 | `bitmapdata_opaque` | 0 | 8.7s |  |
| 139 | `bitmapdata_pixeldissolve` | 1037 | 9.1s |  |
| 140 | `bitmapdata_pixeldissolve_image` | 0 | 8.7s |  |
| 141 | `bitmapdata_rectangle_rounding` | 16 | 8.4s |  |
| 142 | `bitmapdata_setpixels` | 286 | 8.5s |  |
| 143 | `bitmapdata_setvector` | 26 | 8.6s |  |
| 144 | `bitmapdata_sync` | 0 | 30.0s |  |
| 145 | `bitmapdata_threshold` | 176 | 9.2s |  |
| 146 | `bitmapdata_zero_size` | 8 | 29.8s |  |
| 147 | `bitnot` | 46 | 8.5s |  |
| 148 | `bitor` | 1058 | 20.9s |  |
| 149 | `bitxor` | 1058 | 20.9s |  |
| 150 | `blend_mode_null` | 1 | 8.4s |  |
| 151 | `blend_multiply_alpha` | 0 | 8.6s |  |
| 152 | `blend_scroll` | 0 | 8.7s |  |
| 153 | `blend_shader_luma_lighten` | 3 | 9.1s |  |
| 154 | `blur_filter` | 43 | 8.7s |  |
| 155 | `boolean_constr` | 32 | 8.5s |  |
| 156 | `boolean_negation` | 30 | 7.8s |  |
| 157 | `boolean_tostring` | 8 | 7.7s |  |
| 158 | `broadcast_event` | 7 | 26.3s |  |
| 159 | `button_bounds` | 1 | 7.7s |  |
| 160 | `button_hittest` | 2 | 26.2s |  |
| 161 | `button_nested_frame` | 48 | 26.9s |  |
| 162 | `bytearray` | 48 | 8.1s |  |
| 163 | `bytearray_compress` | 31 | 26.4s |  |
| 164 | `bytearray_errors` | 24 | 7.8s |  |
| 165 | `bytearray_method_serialization` | 1 | 7.6s |  |
| 166 | `bytearray_oom` | 3 | 7.7s |  |
| 167 | `bytearray_readobject_amf0` | 50 | 7.8s |  |
| 168 | `bytearray_readobject_amf3` | 53 | 7.7s |  |
| 169 | `bytearray_readutf8bytes_with_bom` | 16 | 7.7s |  |
| 170 | `bytearray_serialization` | 3 | 7.7s |  |
| 171 | `bytearray_string_null` | 19 | 7.9s |  |
| 172 | `bytearray_tostring` | 15 | 7.6s |  |
| 173 | `bytearray_utf16` | 8 | 7.6s |  |
| 174 | `bytearray_writeobject` | 24 | 7.6s |  |
| 175 | `callee_in_initializer` | 6 | 7.6s |  |
| 176 | `callproplex_class` | 1 | 7.6s |  |
| 177 | `capabilities_resolution` | 8 | 27.6s |  |
| 178 | `catch_class` | 6 | 7.7s |  |
| 179 | `catch_scope_slot` | 7 | 3.2s |  |
| 180 | `checkfilter` | 4 | 3.2s |  |
| 181 | `class_call` | 32 | 7.8s |  |
| 182 | `class_cast_call` | 14 | 7.7s |  |
| 183 | `class_enumeration` | 4 | 7.7s |  |
| 184 | `class_has_own_property` | 2 | 7.7s |  |
| 185 | `class_init_interpreter_mode` | 1 | 7.5s |  |
| 186 | `class_is` | 32 | 7.8s |  |
| 187 | `class_methods` | 5 | 7.7s |  |
| 188 | `class_object_properties` | 10 | 7.7s |  |
| 189 | `class_singleton` | 18 | 7.7s |  |
| 190 | `class_supercalls_errors` | 35 | 7.9s |  |
| 191 | `class_supercalls_mismatched` | 26 | 7.8s |  |
| 192 | `class_superclass_wrong_order` | 1 | 25.9s |  |
| 193 | `class_to_locale_string` | 2 | 7.7s |  |
| 194 | `class_to_string` | 2 | 7.5s |  |
| 195 | `class_value_of` | 2 | 7.7s |  |
| 196 | `click_block` | 5 | 27.4s |  |
| 197 | `click_invisible` | 3 | 8.2s |  |
| 198 | `closures` | 12 | 7.9s |  |
| 199 | `coerce_return_type` | 40 | 7.9s |  |
| 200 | `coerce_return_type_fail` | 2 | 26.1s |  |
| 201 | `coerce_return_void` | 3 | 7.6s |  |
| 202 | `coerce_string` | 86 | 7.8s |  |
| 203 | `coerce_string_precision` | 28 | 7.7s |  |
| 204 | `coerce_to_primitive_side_effects` | 29 | 26.7s |  |
| 205 | `color_matrix_filter` | 19 | 7.9s |  |
| 206 | `construct_errors_swf10` | 8 | 7.8s |  |
| 207 | `construct_frame_list` | 22 | 27.1s |  |
| 208 | `construct_interface` | 3 | 7.8s |  |
| 209 | `constructor_call` | 3 | 7.7s |  |
| 210 | `constructors_vs_timeline` | 5 | 26.7s |  |
| 211 | `constructprop_dynamic_primitive` | 7 | 7.8s |  |
| 212 | `constructprop_method` | 2 | 7.6s |  |
| 213 | `constructsuper_null` | 2 | 7.7s |  |
| 214 | `content_element_basic` | 50 | 8.0s |  |
| 215 | `context3d_creation` | 9 | 7.7s |  |
| 216 | `control_flow_bool` | 4 | 7.6s |  |
| 217 | `control_flow_stricteq` | 8 | 7.7s |  |
| 218 | `convert_boolean` | 30 | 7.7s |  |
| 219 | `convert_integer` | 90 | 7.8s |  |
| 220 | `convert_number` | 56 | 7.8s |  |
| 221 | `convert_uinteger` | 90 | 7.9s |  |
| 222 | `convolution_filter` | 89 | 7.9s |  |
| 223 | `core_exceptions` | 47 | 8.6s |  |
| 224 | `cpool_index_invalid_bytecode_1` | 6 | 7.8s |  |
| 225 | `cpool_index_invalid_bytecode_2` | 3 | 7.8s |  |
| 226 | `cpool_index_invalid_bytecode_3` | 1 | 7.8s |  |
| 227 | `cross_api_version_call_newer` | 12 | 8.5s |  |
| 228 | `cross_api_version_call_older` | 12 | 8.2s |  |
| 229 | `cryptscore` | 11 | 7.9s |  |
| 230 | `currency_parse_result` | 7 | 7.8s |  |
| 231 | `date` | 30 | 8.2s |  |
| 232 | `date_parse` | 36 | 7.8s |  |
| 233 | `declocal` | 46 | 7.9s |  |
| 234 | `declocal_i` | 46 | 7.9s |  |
| 235 | `decode_uri` | 71 | 8.2s |  |
| 236 | `decrement` | 46 | 7.8s |  |
| 237 | `decrement_i` | 46 | 7.7s |  |
| 238 | `default_values` | 7 | 7.7s |  |
| 239 | `delayed_symbolclass` | 28 | 26.6s |  |
| 240 | `describe_type_basic` | 152 | 7.8s |  |
| 241 | `describe_type_json` | 301 | 7.8s |  |
| 242 | `describe_type_metadata` | 125 | 7.8s |  |
| 243 | `describe_type_native` | 23 | 7.7s |  |
| 244 | `dictionary_access` | 62 | 7.9s |  |
| 245 | `dictionary_access_no_pubns` | 2 | 26.1s |  |
| 246 | `dictionary_delete` | 101 | 8.2s |  |
| 247 | `dictionary_foreach` | 42 | 7.9s |  |
| 248 | `dictionary_hasownproperty` | 63 | 7.9s |  |
| 249 | `dictionary_in` | 62 | 7.9s |  |
| 250 | `dictionary_iter_modify` | 8 | 7.7s |  |
| 251 | `dictionary_namespaces` | 36 | 7.8s |  |
| 252 | `dictionary_primitive_keys` | 29 | 7.7s |  |
| 253 | `displacement_map_filter` | 61 | 7.9s |  |
| 254 | `displayobject_alpha` | 277 | 7.7s |  |
| 255 | `displayobject_blendmode` | 0 | 8.9s |  |
| 256 | `displayobject_colortransform_nested` | 0 | 26.6s |  |
| 257 | `displayobject_filters` | 17 | 7.8s |  |
| 258 | `displayobject_from_enterframe` | 1 | 26.5s |  |
| 259 | `displayobject_getbounds_shape` | 0 | 26.5s |  |
| 260 | `displayobject_height` | 6052 | 26.6s |  |
| 261 | `displayobject_hittestobject` | 32 | 7.7s |  |
| 262 | `displayobject_hittestpoint` | 49 | 26.4s |  |
| 263 | `displayobject_hittestpoint_root` | 13 | 8.0s |  |
| 264 | `displayobject_invalid_floats` | 60 | 7.7s |  |
| 265 | `displayobject_invalid_props` | 3 | 7.7s |  |
| 266 | `displayobject_mask` | 3 | 8.0s |  |
| 267 | `displayobject_mask_self_referential` | 0 | 7.6s |  |
| 268 | `displayobject_metaData` | 3 | 7.6s |  |
| 269 | `displayobject_name` | 22 | 26.3s |  |
| 270 | `displayobject_name_from_timeline` | 24 | 7.8s |  |
| 271 | `displayobject_opaque_background` | 6 | 7.7s |  |
| 272 | `displayobject_parent` | 12 | 7.7s |  |
| 273 | `displayobject_root` | 24 | 19.5s |  |
| 274 | `displayobject_rotation` | 1284 | 21.0s |  |
| 275 | `displayobject_set_matrix_nested` | 0 | 21.8s |  |
| 276 | `displayobject_set_name_loaded` | 3 | 6.7s |  |
| 277 | `displayobject_subclass` | 2 | 5.6s |  |
| 278 | `displayobject_visible` | 23 | 5.9s |  |
| 279 | `displayobject_width` | 4852 | 20.6s |  |
| 280 | `displayobject_x` | 614 | 20.5s |  |
| 281 | `displayobject_y` | 617 | 5.4s |  |
| 282 | `displayobjectcontainer_addchild` | 32 | 5.2s |  |
| 283 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.3s |  |
| 284 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.8s |  |
| 285 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.7s |  |
| 286 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.6s |  |
| 287 | `displayobjectcontainer_addchildat` | 42 | 5.2s |  |
| 288 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.4s |  |
| 289 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.3s |  |
| 290 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.4s |  |
| 291 | `displayobjectcontainer_contains` | 66 | 20.6s |  |
| 292 | `displayobjectcontainer_getchildat` | 4 | 5.6s |  |
| 293 | `displayobjectcontainer_getchildbyname` | 9 | 5.7s |  |
| 294 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.7s |  |
| 295 | `displayobjectcontainer_getchildindex` | 28 | 6.1s |  |
| 296 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 20.4s |  |
| 297 | `displayobjectcontainer_removechild` | 10 | 6.5s |  |
| 298 | `displayobjectcontainer_removechild_errors` | 4 | 5.6s |  |
| 299 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.5s |  |
| 300 | `displayobjectcontainer_removechildat` | 18 | 5.7s |  |
| 301 | `displayobjectcontainer_removechildren` | 51 | 5.5s |  |
| 302 | `displayobjectcontainer_setchildindex` | 42 | 5.1s |  |
| 303 | `displayobjectcontainer_stopallmovieclips` | 2 | 19.5s |  |
| 304 | `displayobjectcontainer_swapchildren` | 42 | 5.5s |  |
| 305 | `displayobjectcontainer_swapchildrenat` | 42 | 5.7s |  |
| 306 | `displayobjectcontainer_timelineinstance` | 48 | 19.6s |  |
| 307 | `divide` | 1058 | 12.5s |  |
| 308 | `doabc_and_symbolclass_script_init_goto` | 7 | 19.3s |  |
| 309 | `doabc_and_symbolclass_script_init_normal` | 6 | 5.2s |  |
| 310 | `doabc_is_eager` | 1 | 19.2s |  |
| 311 | `documentclass` | 9 | 5.3s |  |
| 312 | `domain_memory` | 133 | 6.2s |  |
| 313 | `drag_drop` | 10 | 26.2s |  |
| 314 | `drop_shadow_filter` | 172 | 8.0s |  |
| 315 | `duplicate_defs` | 1 | 7.7s |  |
| 316 | `eager_init` | 1 | 7.7s |  |
| 317 | `east_asian_justifier_clone` | 8 | 21.7s |  |
| 318 | `edit_text_linkage` | 7 | 7.8s |  |
| 319 | `edittext_align` | 60 | 8.1s |  |
| 320 | `edittext_always_show_selection` | 0 | 27.6s |  |
| 321 | `edittext_antialiastype` | 296 | 8.0s |  |
| 322 | `edittext_at_point_methods_basic` | 16 | 9.0s |  |
| 323 | `edittext_autosize` | 39 | 8.0s |  |
| 324 | `edittext_autosize_align` | 0 | 26.7s |  |
| 325 | `edittext_autosize_height_dynamic` | 60 | 26.5s |  |
| 326 | `edittext_autosize_height_input` | 60 | 7.7s |  |
| 327 | `edittext_autosize_lazy_bounds_events` | 65 | 8.0s |  |
| 328 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.7s |  |
| 329 | `edittext_autosize_lazy_bounds_props` | 490 | 9.0s |  |
| 330 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.2s |  |
| 331 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.8s |  |
| 332 | `edittext_bottom_scroll_v_basic` | 210 | 7.7s |  |
| 333 | `edittext_bounds_scale` | 24 | 25.6s |  |
| 334 | `edittext_bullet` | 30 | 7.8s |  |
| 335 | `edittext_default_format` | 221 | 8.0s |  |
| 336 | `edittext_default_format_empty` | 136 | 7.8s |  |
| 337 | `edittext_empty_text_format` | 7 | 7.7s |  |
| 338 | `edittext_focus_selection` | 5 | 7.6s |  |
| 339 | `edittext_font_size` | 45 | 7.7s |  |
| 340 | `edittext_format_empty_font` | 8 | 7.6s |  |
| 341 | `edittext_get_char_index_at_point` | 4 | 28.6s |  |
| 342 | `edittext_get_line_index_at_point` | 2 | 26.4s |  |
| 343 | `edittext_get_line_index_of_char` | 76 | 8.5s |  |
| 344 | `edittext_getcharboundaries` | 172 | 7.9s |  |
| 345 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.6s |  |
| 346 | `edittext_getcharboundaries_scroll` | 85 | 7.7s |  |
| 347 | `edittext_getlinemetrics` | 146 | 8.0s |  |
| 348 | `edittext_html` | 3101 | 8.1s |  |
| 349 | `edittext_html_condensewhite` | 487 | 7.7s |  |
| 350 | `edittext_html_entity` | 4 | 7.7s |  |
| 351 | `edittext_html_font_size_swf12` | 267 | 7.7s |  |
| 352 | `edittext_html_font_size_swf13` | 273 | 44.0s |  |
| 353 | `edittext_html_roundtrip` | 17 | 26.4s |  |
| 354 | `edittext_ime_focus_lost` | 9 | 26.3s |  |
| 355 | `edittext_input_control` | 12 | 7.9s |  |
| 356 | `edittext_leading` | 9 | 8.1s |  |
| 357 | `edittext_letter_spacing` | 15 | 8.1s |  |
| 358 | `edittext_line_methods` | 294 | 9.3s |  |
| 359 | `edittext_line_metrics` | 11 | 27.7s |  |
| 360 | `edittext_margins` | 25 | 7.8s |  |
| 361 | `edittext_max_scroll_h_basic` | 475 | 8.0s |  |
| 362 | `edittext_max_scroll_v_basic` | 1000 | 7.7s |  |
| 363 | `edittext_mouse_selection` | 363 | 27.3s |  |
| 364 | `edittext_mousedown` | 3 | 8.1s |  |
| 365 | `edittext_mouseenabled` | 26 | 26.3s |  |
| 366 | `edittext_newline_character` | 22 | 7.7s |  |
| 367 | `edittext_newline_stripping` | 64 | 10.5s |  |
| 368 | `edittext_newlines` | 30 | 7.8s |  |
| 369 | `edittext_paragraph_methods` | 257 | 7.7s |  |
| 370 | `edittext_paste_events` | 8 | 7.9s |  |
| 371 | `edittext_paste_maxchars` | 4 | 7.7s |  |
| 372 | `edittext_paste_restrict` | 16 | 7.5s |  |
| 373 | `edittext_restrict` | 191 | 7.6s |  |
| 374 | `edittext_restrict_events` | 22 | 7.7s |  |
| 375 | `edittext_scrollh` | 10 | 7.7s |  |
| 376 | `edittext_selected_text` | 9 | 7.6s |  |
| 377 | `edittext_set_html_same` | 17 | 7.6s |  |
| 378 | `edittext_set_text_vs_html` | 9 | 7.6s |  |
| 379 | `edittext_stylesheet` | 536 | 8.0s |  |
| 380 | `edittext_stylesheet_custom_tag` | 76 | 7.7s |  |
| 381 | `edittext_stylesheet_display` | 272 | 7.7s |  |
| 382 | `edittext_tag_indent` | 49 | 28.4s |  |
| 383 | `edittext_underline` | 40 | 7.9s |  |
| 384 | `edittext_width_height` | 103 | 8.0s |  |
| 385 | `edittext_wordwrap_word` | 150 | 7.8s |  |
| 386 | `edittext_wrap_breaks` | 2375 | 8.2s |  |
| 387 | `element_format_clone` | 44 | 7.8s |  |
| 388 | `element_format_constructor_order` | 64 | 3.4s |  |
| 389 | `element_format_properties` | 235 | 8.7s |  |
| 390 | `empty_bounds` | 1 | 7.6s |  |
| 391 | `encode_uri_surrogate_pair_invalid` | 8 | 7.7s |  |
| 392 | `encode_uri_surrogate_pair_swf11` | 15 | 45.2s |  |
| 393 | `equals` | 512 | 31.7s |  |
| 394 | `error_geterrormessage` | 779 | 8.0s |  |
| 395 | `error_prototype` | 15 | 8.1s |  |
| 396 | `error_stack_trace` | 45 | 8.0s |  |
| 397 | `error_stack_trace_debug_swf17` | 0 | 27.1s |  |
| 398 | `error_stack_trace_debug_swf18` | 0 | 7.7s |  |
| 399 | `error_stack_trace_edge_cases` | 6 | 8.1s |  |
| 400 | `error_stack_trace_release_swf17` | 0 | 8.0s |  |
| 401 | `error_stack_trace_release_swf18` | 0 | 7.7s |  |
| 402 | `error_throwerror` | 103 | 8.1s |  |
| 403 | `error_tostring` | 29 | 8.0s |  |
| 404 | `error_tostring_more` | 86 | 8.1s |  |
| 405 | `es3_inheritance` | 31 | 8.0s |  |
| 406 | `es4_inheritance` | 30 | 8.1s |  |
| 407 | `es4_interfaces` | 30 | 8.1s |  |
| 408 | `es4_method_binding` | 8 | 8.0s |  |
| 409 | `es4_oop_prototypes` | 14 | 8.2s |  |
| 410 | `es4_protected_inheritance` | 6 | 8.0s |  |
| 411 | `escape` | 71 | 8.1s |  |
| 412 | `escape_multi_byte` | 45 | 8.1s |  |
| 413 | `event_bubbles` | 2 | 8.0s |  |
| 414 | `event_cancelable` | 2 | 7.9s |  |
| 415 | `event_clone` | 20 | 8.1s |  |
| 416 | `event_clone_error_redispatch` | 3 | 8.2s |  |
| 417 | `event_clone_on_redispatch` | 10 | 8.1s |  |
| 418 | `event_formattostring` | 31 | 8.1s |  |
| 419 | `event_isdefaultprevented` | 12 | 8.0s |  |
| 420 | `event_target_getter` | 5 | 3.3s |  |
| 421 | `event_target_set` | 9 | 26.8s |  |
| 422 | `event_type` | 1 | 8.0s |  |
| 423 | `event_valueof_tostring` | 18 | 8.0s |  |
| 424 | `eventdispatcher_dispatchevent` | 12 | 8.0s |  |
| 425 | `eventdispatcher_dispatchevent_cancel` | 20 | 8.0s |  |
| 426 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 8.0s |  |
| 427 | `eventdispatcher_dispatchevent_indirect` | 9 | 8.0s |  |
| 428 | `eventdispatcher_dispatchevent_this` | 5 | 8.0s |  |
| 429 | `eventdispatcher_haseventlistener` | 25 | 8.1s |  |
| 430 | `eventdispatcher_interface_invoke` | 1 | 8.0s |  |
| 431 | `eventdispatcher_tostring` | 10 | 8.1s |  |
| 432 | `eventdispatcher_willtrigger` | 25 | 46.1s |  |
| 433 | `falsiness` | 30 | 8.2s |  |
| 434 | `fast_index_access` | 12 | 8.2s |  |
| 435 | `filefilter_properties` | 4 | 8.1s |  |
| 436 | `filereference_browse_cancel` | 3 | 8.0s |  |
| 437 | `filereference_browse_select` | 9 | 8.1s |  |
| 438 | `filereference_load` | 31 | 8.2s |  |
| 439 | `filereference_save` | 16 | 8.3s |  |
| 440 | `filereference_save_and_browse` | 42 | 8.3s |  |
| 441 | `filereference_save_and_load` | 22 | 8.2s |  |
| 442 | `filereference_uninitialized` | 8 | 8.0s |  |
| 443 | `filereferencelist_browse_cancel` | 6 | 7.9s |  |
| 444 | `filereferencelist_browse_select` | 7 | 8.0s |  |
| 445 | `filter_rewind` | 8 | 28.6s |  |
| 446 | `filters_array_holes` | 25 | 9.2s |  |
| 447 | `finddef` | 3 | 8.1s |  |
| 448 | `findprop_global_prototype` | 6 | 8.2s |  |
| 449 | `flash_media_video_constructor` | 156 | 8.9s |  |
| 450 | `flash_media_video_rotation_probe` | 27 | 8.2s |  |
| 451 | `flash_media_video_setter` | 40 | 8.6s |  |
| 452 | `flash_trace` | 17 | 8.3s |  |
| 453 | `flash_xml` | 29 | 8.2s |  |
| 454 | `flash_xml_cloneNode` | 22 | 8.2s |  |
| 455 | `flash_xml_namespace` | 109 | 8.1s |  |
| 456 | `flash_xml_removeNode` | 60 | 8.2s |  |
| 457 | `focus_events_code` | 161 | 28.9s |  |
| 458 | `focus_events_key_basic` | 132 | 29.1s |  |
| 459 | `focus_events_key_navigation` | 53 | 28.4s |  |
| 460 | `focus_events_key_same_object` | 26 | 8.1s |  |
| 461 | `focus_events_mixed_key_mouse` | 100 | 27.7s |  |
| 462 | `focus_events_mouse_basic` | 260 | 27.4s |  |
| 463 | `focus_events_mouse_focusable` | 112 | 28.1s |  |
| 464 | `focus_events_mouse_same_object` | 40 | 7.9s |  |
| 465 | `focus_remove` | 20 | 27.1s |  |
| 466 | `focus_root_movie` | 4 | 29.1s |  |
| 467 | `focus_stage` | 1 | 7.7s |  |
| 468 | `focusrect` | 18 | 8.4s |  |
| 469 | `focusrect_focuslost` | 9 | 7.8s |  |
| 470 | `focusrect_property` | 110 | 3.2s |  |
| 471 | `font_description_clone` | 14 | 7.8s |  |
| 472 | `font_embedded` | 24 | 47.4s |  |
| 473 | `font_enumeratefonts` | 41 | 9.2s |  |
| 474 | `font_enumeratefonts_filter` | 4 | 29.8s |  |
| 475 | `font_enumeratefonts_order` | 9 | 30.6s |  |
| 476 | `font_hasglyphs` | 40 | 9.0s |  |
| 477 | `font_registerfont` | 129 | 9.6s |  |
| 478 | `framelabel_constr` | 5 | 8.8s |  |
| 479 | `function_call` | 12 | 8.6s |  |
| 480 | `function_call_arguments` | 46 | 8.7s |  |
| 481 | `function_call_arguments_enumerate` | 5 | 8.6s |  |
| 482 | `function_call_coercion` | 108 | 9.1s |  |
| 483 | `function_call_default` | 6 | 8.6s |  |
| 484 | `function_call_rest` | 22 | 8.5s |  |
| 485 | `function_call_types` | 3 | 8.5s |  |
| 486 | `function_call_via_apply` | 11 | 8.6s |  |
| 487 | `function_call_via_call` | 3 | 8.5s |  |
| 488 | `function_display_anonymous` | 7 | 3.8s |  |
| 489 | `function_length` | 6 | 8.6s |  |
| 490 | `function_object` | 2 | 8.6s |  |
| 491 | `function_proto` | 5 | 8.5s |  |
| 492 | `function_proto_created` | 61 | 8.6s |  |
| 493 | `function_to_locale_string` | 4 | 8.6s |  |
| 494 | `function_to_string` | 4 | 8.5s |  |
| 495 | `function_type` | 6 | 8.5s |  |
| 496 | `function_unbound_this` | 51 | 8.5s |  |
| 497 | `function_value_of` | 4 | 8.5s |  |
| 498 | `game_input` | 4 | 8.5s |  |
| 499 | `generate_random_bytes` | 3 | 8.4s |  |
| 500 | `geom_transform` | 74 | 31.6s |  |
| 501 | `get_definition_by_name` | 11 | 8.4s |  |
| 502 | `get_qualified_class_name` | 20 | 8.4s |  |
| 503 | `get_qualified_super_class_name` | 18 | 8.4s |  |
| 504 | `get_slot_edge_cases` | 1 | 8.3s |  |
| 505 | `get_timer` | 2 | 3.5s |  |
| 506 | `getglobalslot` | 1 | 8.3s |  |
| 507 | `getouterscope` | 8 | 8.3s |  |
| 508 | `getouterscope_two_classobjects` | 13 | 8.3s |  |
| 509 | `getter_different_namespace_setter` | 2 | 8.1s |  |
| 510 | `glow_filter` | 127 | 8.7s |  |
| 511 | `goto_button_nested_framescript` | 28 | 28.9s |  |
| 512 | `goto_in_constructframe` | 12 | 43.9s |  |
| 513 | `goto_in_scene_last_frame` | 2 | 26.4s |  |
| 514 | `goto_methods` | 56 | 26.1s |  |
| 515 | `goto_methods_swfver10` | 8 | 7.3s |  |
| 516 | `goto_nested_construct_sibling` | 18 | 26.6s |  |
| 517 | `goto_nested_framescript` | 9 | 7.4s |  |
| 518 | `goto_on_orphan` | 15 | 26.2s |  |
| 519 | `gradient_bevel_filter` | 206 | 7.4s |  |
| 520 | `gradient_glow_filter` | 206 | 7.2s |  |
| 521 | `graphic_linkage` | 9 | 7.4s |  |
| 522 | `graphics_bad_direct_commands` | 5 | 11.0s |  |
| 523 | `graphics_bitmap_fill` | 0 | 27.7s |  |
| 524 | `graphics_bitmaps` | 0 | 7.8s |  |
| 525 | `graphics_direct_commands` | 0 | 7.8s |  |
| 526 | `graphics_draw_triangles` | 98 | 27.0s |  |
| 527 | `graphics_gradients` | 0 | 7.7s |  |
| 528 | `graphics_gradients_nulls` | 0 | 7.5s |  |
| 529 | `graphics_path` | 56 | 7.4s |  |
| 530 | `graphics_round_rects` | 0 | 7.2s |  |
| 531 | `graphics_simple_shapes` | 0 | 7.5s |  |
| 532 | `greaterequals` | 512 | 10.2s |  |
| 533 | `greaterthan` | 512 | 10.2s |  |
| 534 | `has_own_property` | 102 | 7.8s |  |
| 535 | `hasownproperty_namespaces` | 2 | 7.3s |  |
| 536 | `hello_world` | 1 | 7.3s |  |
| 537 | `hittest_morph` | 30 | 7.4s |  |
| 538 | `if_eq` | 10 | 7.3s |  |
| 539 | `if_gt` | 1 | 7.3s |  |
| 540 | `if_gte` | 10 | 2.8s |  |
| 541 | `if_lt` | 1 | 1.1s |  |
| 542 | `if_lte` | 10 | 7.2s |  |
| 543 | `if_ne` | 7 | 2.8s |  |
| 544 | `if_stricteq` | 6 | 7.3s |  |
| 545 | `if_strictne` | 11 | 7.2s |  |
| 546 | `ime_linux_dead_keys` | 10 | 7.3s |  |
| 547 | `in` | 102 | 7.6s |  |
| 548 | `inclocal` | 46 | 7.2s |  |
| 549 | `inclocal_i` | 46 | 7.2s |  |
| 550 | `increment` | 46 | 46.6s |  |
| 551 | `increment_i` | 46 | 8.2s |  |
| 552 | `indexing_delete` | 75 | 8.2s |  |
| 553 | `instanceof` | 58 | 8.4s |  |
| 554 | `instantiate_root_character` | 4 | 8.6s |  |
| 555 | `instantiation_on_enter_frame` | 7 | 28.0s |  |
| 556 | `instantiation_on_enterframe_gotoandstop` | 8 | 8.0s |  |
| 557 | `int_constr` | 92 | 8.4s |  |
| 558 | `int_edge_cases` | 19 | 27.4s |  |
| 559 | `int_instanceof` | 3 | 27.3s |  |
| 560 | `int_tofixed` | 1215 | 8.0s |  |
| 561 | `int_toprecision` | 1125 | 8.3s |  |
| 562 | `int_tostring` | 3375 | 8.4s |  |
| 563 | `interactiveobject_enabled` | 25 | 8.0s |  |
| 564 | `interface_namespaces` | 78 | 8.3s |  |
| 565 | `invalid_utf8` | 12 | 8.2s |  |
| 566 | `is_finite` | 46 | 8.2s |  |
| 567 | `is_nan` | 46 | 8.0s |  |
| 568 | `is_prototype_of` | 12 | 8.0s |  |
| 569 | `issue_10221` | 2 | 7.9s |  |
| 570 | `issue_13780` | 12 | 8.1s |  |
| 571 | `issue_14901` | 1 | 7.9s |  |
| 572 | `issue_17675_edittext_paste_maxchars` | 1 | 8.0s |  |
| 573 | `issue_5292` | 5 | 8.0s |  |
| 574 | `issue_8630` | 2 | 27.2s |  |
| 575 | `issue_8630_placeremoveplace` | 15 | 8.2s |  |
| 576 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.9s |  |
| 577 | `issue_8630_scriptremove` | 11 | 7.9s |  |
| 578 | `istype` | 24 | 3.5s |  |
| 579 | `istypelate` | 58 | 8.2s |  |
| 580 | `istypelate_coerce` | 198 | 9.0s |  |
| 581 | `jpeg_loader_context` | 6 | 7.8s |  |
| 582 | `json_errors` | 9 | 27.6s |  |
| 583 | `json_parse` | 21 | 8.1s |  |
| 584 | `json_stringify` | 12 | 8.3s |  |
| 585 | `json_stringify_function` | 12 | 8.1s |  |
| 586 | `json_stringify_order` | 1 | 8.0s |  |
| 587 | `json_version_gated` | 1 | 8.0s |  |
| 588 | `key_input_80percent` | 1812 | 8.2s |  |
| 589 | `key_input_location` | 126 | 3.5s |  |
| 590 | `key_input_numpad` | 384 | 44.9s |  |
| 591 | `lazyinit` | 17 | 8.2s |  |
| 592 | `lessequals` | 512 | 11.6s |  |
| 593 | `lessthan` | 512 | 11.7s |  |
| 594 | `loader_bitmap_transparency` | 14 | 8.3s |  |
| 595 | `loader_bytes_unknown_content` | 14 | 8.1s |  |
| 596 | `loader_child_getdefinition` | 5 | 8.3s |  |
| 597 | `loader_duplicate_coerce` | 3 | 8.2s |  |
| 598 | `loader_duplicate_coerce_new_domain` | 4 | 8.1s |  |
| 599 | `loader_error_in_root_ctor` | 4 | 8.3s |  |
| 600 | `loader_events` | 92 | 9.9s |  |
| 601 | `loader_image` | 8 | 8.5s |  |
| 602 | `loader_jpegxr` | 2 | 27.4s |  |
| 603 | `loader_jpegxr_alpha` | 1 | 26.9s |  |
| 604 | `loader_loadbytes_events` | 30 | 8.7s |  |
| 605 | `loader_loadbytes_invalid_png` | 4 | 26.9s |  |
| 606 | `loader_loadbytes_url` | 12 | 8.4s |  |
| 607 | `loader_loaderurl` | 6 | 8.5s |  |
| 608 | `loader_method` | 85 | 8.1s |  |
| 609 | `loader_noninteractive_try_click_root` | 5 | 27.9s |  |
| 610 | `loader_reuse` | 38 | 27.1s |  |
| 611 | `loader_unknown_content` | 24 | 8.1s |  |
| 612 | `loader_visibility_interactive` | 1 | 8.3s |  |
| 613 | `loaderinfo_events` | 7 | 8.0s |  |
| 614 | `loaderinfo_loadurl` | 12 | 8.0s |  |
| 615 | `loaderinfo_more` | 6 | 8.2s |  |
| 616 | `loaderinfo_properties` | 18 | 27.0s |  |
| 617 | `loaderinfo_properties_not_loaded` | 23 | 8.1s |  |
| 618 | `loaderinfo_quine` | 1005 | 8.0s |  |
| 619 | `loaderinfo_root` | 10 | 8.0s |  |
| 620 | `loaderinfo_root_allows` | 2 | 8.0s |  |
| 621 | `localconnection` | 890 | 10.3s |  |
| 622 | `localconnection_send` | 4 | 8.0s |  |
| 623 | `lshift` | 1058 | 19.2s |  |
| 624 | `mask_reapply` | 1 | 43.9s |  |
| 625 | `math` | 497 | 26.8s |  |
| 626 | `matrix` | 338 | 18.6s |  |
| 627 | `matrix3d` | 57 | 27.4s |  |
| 628 | `matrix3d_append` | 16 | 7.9s |  |
| 629 | `matrix3d_compose` | 34 | 8.0s |  |
| 630 | `matrix3d_copy_column` | 83 | 7.9s |  |
| 631 | `matrix3d_copy_raw_data_from` | 55 | 3.3s |  |
| 632 | `matrix3d_copy_raw_data_to` | 38 | 7.8s |  |
| 633 | `matrix3d_copy_row` | 83 | 7.6s |  |
| 634 | `matrix3d_invert` | 18 | 7.7s |  |
| 635 | `matrix3d_position` | 19 | 7.7s |  |
| 636 | `matrix3d_prepend` | 16 | 7.6s |  |
| 637 | `matrix3d_transform_vector` | 52 | 8.1s |  |
| 638 | `matrix3d_transpose` | 5 | 7.8s |  |
| 639 | `method_without_body` | 3 | 27.3s |  |
| 640 | `missing_external_interface` | 10 | 8.0s |  |
| 641 | `modulo` | 1058 | 20.3s |  |
| 642 | `morph_shape` | 2 | 27.5s |  |
| 643 | `mouse_children` | 192 | 28.1s |  |
| 644 | `mouse_click_events` | 90 | 26.7s |  |
| 645 | `mouse_double_click_events` | 188 | 7.8s |  |
| 646 | `mouse_empty_parent` | 4 | 7.9s |  |
| 647 | `mouse_over_while_dragging` | 3 | 8.0s |  |
| 648 | `mouse_pick_button_mode` | 2 | 7.9s |  |
| 649 | `mouse_pick_dobj_mask` | 4 | 8.2s |  |
| 650 | `mouse_pick_masking` | 7 | 26.8s |  |
| 651 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.3s |  |
| 652 | `mouse_pick_non_interactive_dobj_mask` | 3 | 8.0s |  |
| 653 | `mouse_pick_text` | 8 | 7.8s |  |
| 654 | `mouse_sibling` | 8 | 7.8s |  |
| 655 | `mouse_wheel_events` | 36 | 27.6s |  |
| 656 | `mouseevent_constr` | 66 | 7.7s |  |
| 657 | `mouseevent_stagexy` | 35 | 48.5s |  |
| 658 | `mouseevent_valueof_tostring` | 28 | 8.6s |  |
| 659 | `movieclip_addframescript` | 3 | 29.8s |  |
| 660 | `movieclip_child_property` | 16 | 8.8s |  |
| 661 | `movieclip_constr` | 21 | 29.2s |  |
| 662 | `movieclip_currentlabels` | 17 | 29.6s |  |
| 663 | `movieclip_currentlabels_dupes1` | 46 | 30.8s |  |
| 664 | `movieclip_currentlabels_dupes2` | 30 | 8.9s |  |
| 665 | `movieclip_currentlabels_dupes3` | 67 | 8.8s |  |
| 666 | `movieclip_currentscene` | 12 | 29.6s |  |
| 667 | `movieclip_dispatchevent` | 430 | 8.6s |  |
| 668 | `movieclip_dispatchevent_cancel` | 102 | 8.6s |  |
| 669 | `movieclip_dispatchevent_handlerorder` | 251 | 8.4s |  |
| 670 | `movieclip_dispatchevent_selfadd` | 80 | 8.6s |  |
| 671 | `movieclip_dispatchevent_target` | 899 | 9.0s |  |
| 672 | `movieclip_displayevents` | 96 | 32.0s |  |
| 673 | `movieclip_displayevents_clickgoto` | 676 | 33.0s |  |
| 674 | `movieclip_displayevents_clickgoto2` | 2001 | 9.8s |  |
| 675 | `movieclip_displayevents_clickplay` | 575 | 9.4s |  |
| 676 | `movieclip_displayevents_clicksymbol` | 562 | 9.4s |  |
| 677 | `movieclip_displayevents_constructframegoto` | 140 | 9.7s |  |
| 678 | `movieclip_displayevents_constructframeplay` | 50 | 9.5s |  |
| 679 | `movieclip_displayevents_constructframesymbol` | 144 | 9.6s |  |
| 680 | `movieclip_displayevents_dblhandler` | 21 | 9.9s |  |
| 681 | `movieclip_displayevents_enterframegoto` | 149 | 9.6s |  |
| 682 | `movieclip_displayevents_enterframeplay` | 48 | 9.3s |  |
| 683 | `movieclip_displayevents_enterframesymbol` | 149 | 32.2s |  |
| 684 | `movieclip_displayevents_exitframegoto` | 106 | 9.2s |  |
| 685 | `movieclip_displayevents_exitframeplay` | 44 | 9.2s |  |
| 686 | `movieclip_displayevents_exitframesymbol` | 135 | 9.3s |  |
| 687 | `movieclip_displayevents_looping` | 63 | 30.4s |  |
| 688 | `movieclip_displayevents_stopped` | 113 | 9.0s |  |
| 689 | `movieclip_displayevents_swap` | 96 | 3.7s |  |
| 690 | `movieclip_displayevents_timeline` | 128 | 32.0s |  |
| 691 | `movieclip_drawrect` | 54 | 8.7s |  |
| 692 | `movieclip_frameconstruct_skipped` | 9 | 8.3s |  |
| 693 | `movieclip_goto_during_frame_script` | 15 | 29.2s |  |
| 694 | `movieclip_goto_overwrite` | 14 | 29.5s |  |
| 695 | `movieclip_goto_scene_last_frame_int` | 1 | 30.4s |  |
| 696 | `movieclip_goto_scene_last_frame_label` | 1 | 8.8s |  |
| 697 | `movieclip_gotoandplay` | 15 | 29.2s |  |
| 698 | `movieclip_gotoandstop` | 13 | 43.5s |  |
| 699 | `movieclip_gotoandstop_children` | 4 | 26.6s |  |
| 700 | `movieclip_gotoandstop_framescripts1` | 4 | 7.7s |  |
| 701 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 702 | `movieclip_gotoandstop_framescripts_self` | 7 | 26.3s |  |
| 703 | `movieclip_gotoandstop_queueing` | 12 | 26.4s |  |
| 704 | `movieclip_hittest` | 67 | 26.3s |  |
| 705 | `movieclip_next_frame` | 2 | 26.1s |  |
| 706 | `movieclip_next_scene` | 6 | 26.1s |  |
| 707 | `movieclip_play` | 3 | 7.6s |  |
| 708 | `movieclip_prev_frame` | 3 | 7.5s |  |
| 709 | `movieclip_prev_scene` | 7 | 7.7s |  |
| 710 | `movieclip_properties` | 79 | 26.4s |  |
| 711 | `movieclip_queued_noop_goto_swf10` | 9 | 7.7s |  |
| 712 | `movieclip_queued_noop_goto_swf9` | 7 | 1.4s |  |
| 713 | `movieclip_scenes` | 11 | 7.6s |  |
| 714 | `movieclip_soundtransform` | 831 | 28.5s |  |
| 715 | `movieclip_stop` | 1 | 25.9s |  |
| 716 | `movieclip_super_is_symbol` | 20 | 8.0s |  |
| 717 | `movieclip_symbol_constr` | 8 | 7.8s |  |
| 718 | `movieclip_text_mousedown` | 1 | 7.8s |  |
| 719 | `movieclip_willtrigger` | 5 | 7.9s |  |
| 720 | `multiply` | 1058 | 19.6s |  |
| 721 | `namespace_constr` | 253 | 8.1s |  |
| 722 | `namespace_constr_args` | 1 | 7.6s |  |
| 723 | `namespace_enumeration_order` | 7 | 26.2s |  |
| 724 | `nan_scale` | 9 | 7.6s |  |
| 725 | `navigateToURL_target_normalize` | 107 | 28.3s |  |
| 726 | `negate` | 30 | 7.7s |  |
| 727 | `negative_volume_panned` | 0 | 7.9s |  |
| 728 | `nested_iteration` | 11 | 7.7s |  |
| 729 | `net_getClassByAlias` | 3 | 7.7s |  |
| 730 | `net_navigateToURL` | 57 | 7.7s |  |
| 731 | `net_stream_play_options` | 6 | 7.7s |  |
| 732 | `netconnection_close` | 55 | 7.7s |  |
| 733 | `netconnection_properties` | 78 | 7.8s |  |
| 734 | `netconnection_send_remote` | 50 | 26.6s |  |
| 735 | `netconnection_serialize_arrays` | 6 | 7.8s |  |
| 736 | `netfilterevent` | 10 | 7.6s |  |
| 737 | `netstream_client` | 10 | 7.8s |  |
| 738 | `netstream_connect` | 7 | 47.8s |  |
| 739 | `netstream_flv_date` | 4 | 8.4s |  |
| 740 | `newactivation_in_script_init` | 3 | 28.8s |  |
| 741 | `newclass_mismatched` | 4 | 8.3s |  |
| 742 | `newclass_twice` | 3 | 8.2s |  |
| 743 | `nonconflicting_declarations` | 0 | 8.2s |  |
| 744 | `null_void_types` | 8 | 8.2s |  |
| 745 | `number_autoconv` | 21 | 8.4s |  |
| 746 | `number_autoconv_amf` | 132 | 8.3s |  |
| 747 | `number_autoconv_array_sort_32bit` | 1 | 8.2s |  |
| 748 | `number_constr` | 58 | 8.3s |  |
| 749 | `number_convert_edge_cases` | 180 | 28.5s |  |
| 750 | `number_toexponential` | 378 | 8.2s |  |
| 751 | `number_toexponential2` | 35 | 8.0s |  |
| 752 | `number_tofixed` | 378 | 8.1s |  |
| 753 | `number_toprecision` | 350 | 8.3s |  |
| 754 | `obfuscated_class_names` | 3 | 8.2s |  |
| 755 | `object_enumeration` | 10 | 8.2s |  |
| 756 | `object_prototype` | 4 | 8.2s |  |
| 757 | `object_to_locale_string` | 2 | 8.2s |  |
| 758 | `object_to_string` | 2 | 8.1s |  |
| 759 | `object_value_of` | 2 | 3.3s |  |
| 760 | `op_coerce` | 54 | 8.2s |  |
| 761 | `op_coerce_x` | 54 | 8.2s |  |
| 762 | `op_escxattr` | 2 | 8.3s |  |
| 763 | `op_escxelem` | 2 | 8.2s |  |
| 764 | `op_lookupswitch` | 4 | 8.3s |  |
| 765 | `optimize_coerce` | 1 | 8.1s |  |
| 766 | `orphan_movie_complex` | 80 | 8.7s |  |
| 767 | `orphan_movie_reorder` | 111 | 29.1s |  |
| 768 | `package_namespace` | 7 | 8.1s |  |
| 769 | `param_default_value_has_zero_cpool_index` | 1 | 8.2s |  |
| 770 | `parent_early_access_child` | 16 | 29.2s |  |
| 771 | `parse_float` | 81 | 8.5s |  |
| 772 | `parse_float_swf10` | 81 | 8.2s |  |
| 773 | `parse_int` | 135 | 36.5s |  |
| 774 | `perspective_projection` | 1443 | 22.4s |  |
| 775 | `perspective_projection_basic` | 40 | 6.4s |  |
| 776 | `pixelbender_ceil` | 77 | 6.6s |  |
| 777 | `pixelbender_conditional` | 138 | 6.7s |  |
| 778 | `pixelbender_conversions` | 270 | 6.8s |  |
| 779 | `pixelbender_dithering` | 8 | 30.7s |  |
| 780 | `pixelbender_div` | 36 | 7.1s |  |
| 781 | `pixelbender_effect_BlurredFocus` | 0 | 28.8s |  |
| 782 | `pixelbender_effect_glassDisplace` | 0 | 11.8s |  |
| 783 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 26.0s |  |
| 784 | `pixelbender_effect_smudge` | 0 | 24.9s |  |
| 785 | `pixelbender_effect_tintype` | 0 | 8.5s |  |
| 786 | `pixelbender_effect_twirl` | 0 | 9.9s |  |
| 787 | `pixelbender_eof` | 7 | 6.4s |  |
| 788 | `pixelbender_images` | 0 | 8.3s |  |
| 789 | `pixelbender_input` | 103 | 22.4s |  |
| 790 | `pixelbender_logicalnot` | 20 | 6.4s |  |
| 791 | `pixelbender_malformed_data` | 190 | 22.6s |  |
| 792 | `pixelbender_multiple_out_params` | 1 | 6.5s |  |
| 793 | `pixelbender_no_out_param` | 6 | 6.4s |  |
| 794 | `pixelbender_outputs` | 13 | 6.7s |  |
| 795 | `pixelbender_padding_bytes` | 22 | 6.5s |  |
| 796 | `pixelbender_param_qualifier` | 512 | 6.6s |  |
| 797 | `pixelbender_parameters` | 1563 | 6.9s |  |
| 798 | `pixelbender_parameters_bool` | 240 | 6.9s |  |
| 799 | `pixelbender_parameters_int_vs_bool` | 54 | 6.6s |  |
| 800 | `pixelbender_parse_errors` | 6 | 6.5s |  |
| 801 | `pixelbender_rsqrt` | 24 | 6.5s |  |
| 802 | `pixelbender_select_kinds` | 8 | 6.5s |  |
| 803 | `pixelbender_shaderdata` | 49 | 6.5s |  |
| 804 | `pixelbender_shaderdata_setter` | 99 | 7.0s |  |
| 805 | `pixelbender_sign` | 60 | 7.8s |  |
| 806 | `pixelbender_vector_output` | 11 | 7.7s |  |
| 807 | `place_and_lookup/swf10` | 33 | 22.1s |  |
| 808 | `place_and_lookup/swf9` | 33 | 1.2s |  |
| 809 | `place_multiple` | 17 | 22.0s |  |
| 810 | `place_object_replace` | 9 | 22.0s |  |
| 811 | `place_object_replace_2` | 24 | 22.1s |  |
| 812 | `place_object_same_depth_frame` | 1 | 6.5s |  |
| 813 | `point` | 132 | 6.9s |  |
| 814 | `primitive_edge_cases` | 1 | 45.3s |  |
| 815 | `primitive_toString` | 277 | 27.9s |  |
| 816 | `primitive_valueOf` | 285 | 8.0s |  |
| 817 | `print_job_options` | 3 | 8.1s |  |
| 818 | `property_is_enumerable` | 114 | 8.7s |  |
| 819 | `property_is_enumerable_reset` | 23 | 8.1s |  |
| 820 | `property_priority` | 22 | 8.5s |  |
| 821 | `property_priority_chained` | 4 | 27.6s |  |
| 822 | `property_priority_definition_names_order` | 2 | 8.3s |  |
| 823 | `property_priority_three_level` | 6 | 27.3s |  |
| 824 | `propertyisenumerable_namespaces` | 6 | 8.1s |  |
| 825 | `prototype_set_null` | 7 | 8.0s |  |
| 826 | `proxy_callproperty` | 24 | 8.1s |  |
| 827 | `proxy_deleteproperty` | 64 | 8.1s |  |
| 828 | `proxy_enumeration` | 34 | 8.1s |  |
| 829 | `proxy_getproperty` | 77 | 8.2s |  |
| 830 | `proxy_hasownproperty` | 8 | 8.0s |  |
| 831 | `proxy_hasproperty` | 32 | 8.2s |  |
| 832 | `proxy_not_overridden` | 54 | 8.2s |  |
| 833 | `proxy_serialize` | 9 | 8.1s |  |
| 834 | `proxy_setproperty` | 42 | 8.1s |  |
| 835 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.0s |  |
| 836 | `qname_constr` | 32 | 8.1s |  |
| 837 | `qname_constr_namespace` | 24 | 8.1s |  |
| 838 | `qname_enumeration` | 9 | 8.0s |  |
| 839 | `qname_indexing` | 23 | 8.0s |  |
| 840 | `qname_tostring` | 25 | 8.1s |  |
| 841 | `qname_valueof` | 29 | 8.2s |  |
| 842 | `rectangle` | 1094 | 8.7s |  |
| 843 | `regexp_constr` | 148 | 8.3s |  |
| 844 | `regexp_exec` | 19 | 8.1s |  |
| 845 | `regexp_extended` | 47 | 8.0s |  |
| 846 | `regexp_multiargs` | 1 | 7.9s |  |
| 847 | `regexp_test` | 27 | 8.1s |  |
| 848 | `regexp_toString` | 10 | 8.1s |  |
| 849 | `register_script_refresh` | 35 | 28.1s |  |
| 850 | `remove_child_clear_field` | 88 | 8.6s |  |
| 851 | `remove_dobj` | 3 | 8.2s |  |
| 852 | `resolve_order` | 4 | 8.0s |  |
| 853 | `responder_null_callbacks` | 1 | 8.1s |  |
| 854 | `rng` | 1 | 9.4s |  |
| 855 | `rootless` | 42 | 45.7s |  |
| 856 | `rshift` | 1058 | 20.6s |  |
| 857 | `rtqname_not_namespace` | 12 | 27.2s |  |
| 858 | `sandbox_type_inherited` | 2 | 8.6s |  |
| 859 | `sandbox_type_local_file` | 1 | 27.4s |  |
| 860 | `sandbox_type_local_network` | 1 | 7.7s |  |
| 861 | `scene_constr` | 8 | 8.2s |  |
| 862 | `scopes_dont_cache/order-1` | 1 | 27.2s |  |
| 863 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 864 | `security_domain_current` | 2 | 8.0s |  |
| 865 | `selection` | 239 | 8.6s |  |
| 866 | `set_local_0` | 31 | 8.0s |  |
| 867 | `set_property_is_enumerable` | 85 | 8.4s |  |
| 868 | `shaderparameter_value` | 4 | 8.0s |  |
| 869 | `shape_drawrect` | 54 | 8.0s |  |
| 870 | `shared_object_no_root` | 3 | 8.0s |  |
| 871 | `simplebutton_added_to_stage` | 45 | 27.5s |  |
| 872 | `simplebutton_childevents` | 86 | 27.8s |  |
| 873 | `simplebutton_childevents_nested` | 54 | 8.4s |  |
| 874 | `simplebutton_childevents_sprite` | 13 | 8.1s |  |
| 875 | `simplebutton_childprops` | 144 | 8.2s |  |
| 876 | `simplebutton_childshuffle` | 23 | 7.9s |  |
| 877 | `simplebutton_constr` | 36 | 8.3s |  |
| 878 | `simplebutton_constr_childevents` | 48 | 8.3s |  |
| 879 | `simplebutton_constr_params` | 42 | 8.2s |  |
| 880 | `simplebutton_mouseenabled` | 26 | 8.0s |  |
| 881 | `simplebutton_multi_children` | 19 | 8.3s |  |
| 882 | `simplebutton_structure` | 27 | 8.2s |  |
| 883 | `simplebutton_symbolclass` | 68 | 8.4s |  |
| 884 | `slot_disp_id_shared_numbering` | 1 | 27.1s |  |
| 885 | `slots_force_autoassigned` | 1 | 8.1s |  |
| 886 | `socket_after_disconnect` | 1 | 8.2s |  |
| 887 | `socket_close` | 2 | 8.1s |  |
| 888 | `socket_connect` | 4 | 44.4s |  |
| 889 | `socket_errors` | 56 | 27.1s |  |
| 890 | `socket_read_big` | 48 | 7.4s |  |
| 891 | `socket_read_little` | 48 | 2.7s |  |
| 892 | `socket_read_write_object` | 8 | 7.2s |  |
| 893 | `socket_write_big` | 15 | 7.7s |  |
| 894 | `socket_write_little` | 14 | 7.2s |  |
| 895 | `sound_constructor_with_args` | 6 | 7.4s |  |
| 896 | `sound_embeddedprops` | 26 | 7.4s |  |
| 897 | `sound_play` | 19 | 7.6s |  |
| 898 | `sound_rootless` | 7 | 7.3s |  |
| 899 | `sound_valueof` | 33 | 7.4s |  |
| 900 | `soundchannel_soundtransform` | 835 | 28.2s |  |
| 901 | `soundchannel_soundtransform_exists` | 5 | 26.3s |  |
| 902 | `soundchannel_stop` | 8 | 26.5s |  |
| 903 | `soundmixer_buffertime` | 5 | 7.4s |  |
| 904 | `soundmixer_stopall` | 6 | 26.5s |  |
| 905 | `soundtransform` | 442 | 11.5s |  |
| 906 | `space_justifier_clone` | 12 | 7.3s |  |
| 907 | `sprite_with_frames` | 0 | 29.9s |  |
| 908 | `stage3d_agal_cross_product` | 0 | 9.7s |  |
| 909 | `stage3d_agal_upload_errors` | 66 | 9.8s |  |
| 910 | `stage3d_bitmap` | 0 | 31.3s |  |
| 911 | `stage3d_blend` | 81 | 30.6s |  |
| 912 | `stage3d_context3d_string_args` | 158 | 8.5s |  |
| 913 | `stage3d_errors` | 7 | 7.5s |  |
| 914 | `stage3d_errors_atf` | 3 | 8.7s |  |
| 915 | `stage3d_errors_swf_29` | 6 | 7.7s |  |
| 916 | `stage3d_float1_index` | 0 | 28.9s |  |
| 917 | `stage3d_fractal` | 0 | 29.6s |  |
| 918 | `stage3d_ignore_sampler_override` | 0 | 29.1s |  |
| 919 | `stage3d_multistage_triangle` | 3 | 9.9s |  |
| 920 | `stage3d_program_constants_bytearray_be` | 0 | 30.9s |  |
| 921 | `stage3d_program_constants_bytearray_le` | 0 | 10.4s |  |
| 922 | `stage3d_program_constants_invalid_input` | 21 | 8.2s |  |
| 923 | `stage3d_raytrace` | 0 | 34.5s |  |
| 924 | `stage3d_rotating_cube` | 0 | 50.0s |  |
| 925 | `stage3d_sampler` | 0 | 10.8s |  |
| 926 | `stage3d_sampler_partial_upload` | 0 | 10.7s |  |
| 927 | `stage3d_stencil` | 0 | 31.5s |  |
| 928 | `stage3d_texture` | 0 | 16.0s |  |
| 929 | `stage3d_texture_bytearray` | 0 | 11.9s |  |
| 930 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 11.2s |  |
| 931 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 12.3s |  |
| 932 | `stage3d_triangle` | 0 | 10.6s |  |
| 933 | `stage3d_triangle_bytes4` | 0 | 10.6s |  |
| 934 | `stage3d_triangle_float1` | 0 | 10.6s |  |
| 935 | `stage3d_triangle_index_upload` | 0 | 10.5s |  |
| 936 | `stage3d_x_y` | 22 | 7.9s |  |
| 937 | `stage_access` | 10 | 26.5s |  |
| 938 | `stage_displayobject_properties` | 24 | 7.7s |  |
| 939 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.8s |  |
| 940 | `stage_framerate_nan` | 7 | 26.9s |  |
| 941 | `stage_framerate_negative` | 6 | 7.8s |  |
| 942 | `stage_framerate_zero` | 6 | 7.8s |  |
| 943 | `stage_invalidate` | 38 | 8.0s |  |
| 944 | `stage_loaderinfo_properties` | 24 | 26.6s |  |
| 945 | `stage_mousechildren` | 2 | 7.7s |  |
| 946 | `stage_mouseenabled` | 15 | 7.7s |  |
| 947 | `stage_overriden_setters` | 31 | 8.0s |  |
| 948 | `stage_properties` | 30 | 7.8s |  |
| 949 | `stage_properties2` | 213 | 8.0s |  |
| 950 | `stage_stage3Ds_vector` | 1 | 26.4s |  |
| 951 | `static_length` | 24 | 7.8s |  |
| 952 | `static_text` | 3 | 8.0s |  |
| 953 | `static_var_with_this_in_ctor` | 2 | 7.8s |  |
| 954 | `statictext_text` | 8 | 7.9s |  |
| 955 | `stored_properties` | 11 | 7.8s |  |
| 956 | `strict_equality` | 34 | 7.9s |  |
| 957 | `string_call` | 13 | 7.7s |  |
| 958 | `string_case` | 23 | 7.8s |  |
| 959 | `string_char_at` | 27 | 7.8s |  |
| 960 | `string_char_code_at` | 28 | 7.7s |  |
| 961 | `string_concat_fromcharcode` | 37 | 7.7s |  |
| 962 | `string_constr` | 25 | 7.8s |  |
| 963 | `string_indexof_lastindexof` | 87 | 44.1s |  |
| 964 | `string_length` | 16 | 26.8s |  |
| 965 | `string_locale_compare` | 39 | 7.6s |  |
| 966 | `string_match` | 51 | 7.5s |  |
| 967 | `string_relational_compare` | 4 | 7.2s |  |
| 968 | `string_replace` | 51 | 7.4s |  |
| 969 | `string_search` | 41 | 7.4s |  |
| 970 | `string_slice_substr_substring` | 170 | 8.3s |  |
| 971 | `string_split` | 29 | 7.4s |  |
| 972 | `string_substr_negative` | 21 | 25.8s |  |
| 973 | `string_substr_weird` | 182 | 7.2s |  |
| 974 | `stylesheet` | 221 | 7.8s |  |
| 975 | `stylesheet_parse_color` | 69 | 7.3s |  |
| 976 | `stylesheet_transform` | 307 | 7.6s |  |
| 977 | `sub_super_same_field` | 12 | 2.9s |  |
| 978 | `subclass_superclass_linked_symbol` | 4 | 7.8s |  |
| 979 | `subtract` | 1058 | 18.5s |  |
| 980 | `super_get_call` | 12 | 7.3s |  |
| 981 | `supercall_two_classobjects` | 2 | 7.3s |  |
| 982 | `supercalls_weird` | 2 | 7.2s |  |
| 983 | `superinterface_call` | 20 | 7.4s |  |
| 984 | `superinterface_instanceof` | 18 | 7.3s |  |
| 985 | `swf8` | 1 | 7.2s |  |
| 986 | `swf_10_queued_goto_scripts_construct` | 52 | 26.8s |  |
| 987 | `swf_9_goto_in_enter_frame` | 17 | 7.4s |  |
| 988 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 989 | `swf_9_queued_goto_scripts` | 6 | 26.5s |  |
| 990 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 991 | `swf_9_versioning` | 2 | 7.3s |  |
| 992 | `swf_wrong_frame_count` | 38 | 7.6s |  |
| 993 | `swf_wrong_frame_count_isplaying` | 22 | 26.2s |  |
| 994 | `symbol_class_binary_data` | 8 | 7.3s |  |
| 995 | `symbol_class_conflict` | 4 | 10.6s |  |
| 996 | `symbol_class_root_not_zero` | 1 | 7.2s |  |
| 997 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 998 | `system_exit` | 3 | 7.2s |  |
| 999 | `system_setclipboard_null` | 1 | 7.2s |  |
| 1000 | `tab_ordering_arrows` | 998 | 27.6s |  |
| 1001 | `tab_ordering_automatic_advanced` | 184 | 45.5s |  |
| 1002 | `tab_ordering_automatic_basic` | 45 | 26.9s |  |
| 1003 | `tab_ordering_children` | 116 | 7.7s |  |
| 1004 | `tab_ordering_custom_basic` | 34 | 7.6s |  |
| 1005 | `tab_ordering_stage_tab_children` | 32 | 7.6s |  |
| 1006 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.5s |  |
| 1007 | `tab_ordering_tabbable` | 47 | 7.6s |  |
| 1008 | `tabstop_properties` | 105 | 27.3s |  |
| 1009 | `text_element_basic` | 34 | 7.7s |  |
| 1010 | `text_engine_fontdescription` | 27 | 7.7s |  |
| 1011 | `text_engine_groupelement` | 64 | 8.4s |  |
| 1012 | `text_run` | 7 | 7.5s |  |
| 1013 | `textblock_createline_errors` | 23 | 7.8s |  |
| 1014 | `textblock_createline_fte` | 9 | 27.1s |  |
| 1015 | `textblock_properties` | 118 | 8.0s |  |
| 1016 | `textbox_click` | 37 | 27.0s |  |
| 1017 | `textfield_event` | 66 | 7.9s |  |
| 1018 | `textfield_focusin_event` | 9 | 7.5s |  |
| 1019 | `textfield_input_dead_keys_windows` | 15 | 7.6s |  |
| 1020 | `textfield_unload` | 39 | 26.8s |  |
| 1021 | `textformat` | 1134 | 26.7s |  |
| 1022 | `textformat_display` | 14 | 7.7s |  |
| 1023 | `textformat_font_max_length` | 4 | 7.5s |  |
| 1024 | `textline_inapplicable_properties` | 10 | 7.5s |  |
| 1025 | `textline_name` | 1 | 7.5s |  |
| 1026 | `textline_raw_text_length` | 30 | 7.6s |  |
| 1027 | `textline_splitting_basic` | 76 | 7.7s |  |
| 1028 | `textline_throwerror` | 30 | 7.6s |  |
| 1029 | `textline_validity` | 162 | 7.7s |  |
| 1030 | `throw` | 3 | 7.6s |  |
| 1031 | `timeline_scripts` | 3 | 26.8s |  |
| 1032 | `timer` | 90 | 8.7s |  |
| 1033 | `timer_events` | 3 | 7.8s |  |
| 1034 | `timer_finished` | 11 | 7.8s |  |
| 1035 | `timer_invalid_delay` | 30 | 7.6s |  |
| 1036 | `timer_reset` | 8 | 7.9s |  |
| 1037 | `timer_setdelay` | 5 | 36.6s |  |
| 1038 | `trace` | 12 | 6.6s |  |
| 1039 | `truthiness` | 30 | 6.5s |  |
| 1040 | `try_catch` | 11 | 6.3s |  |
| 1041 | `try_catch_typed` | 12 | 6.4s |  |
| 1042 | `typeof` | 30 | 6.3s |  |
| 1043 | `uint_constr` | 92 | 6.4s |  |
| 1044 | `uint_tofixed` | 1215 | 6.2s |  |
| 1045 | `uint_toprecision` | 1125 | 6.4s |  |
| 1046 | `uint_tostring` | 3375 | 6.4s |  |
| 1047 | `uncaught_error_basic` | 2 | 6.3s |  |
| 1048 | `unchecked_function` | 15 | 6.2s |  |
| 1049 | `unescape` | 28 | 6.3s |  |
| 1050 | `url_loader` | 25 | 6.5s |  |
| 1051 | `url_vars` | 27 | 6.4s |  |
| 1052 | `urlrequest` | 18 | 22.2s |  |
| 1053 | `urlstream_basic` | 5 | 6.3s |  |
| 1054 | `urshift` | 1058 | 15.6s |  |
| 1055 | `utils3d` | 7 | 6.6s |  |
| 1056 | `vector3d` | 397 | 9.9s |  |
| 1057 | `vector_class` | 36 | 6.7s |  |
| 1058 | `vector_class_call` | 11 | 21.9s |  |
| 1059 | `vector_coercion` | 66 | 7.0s |  |
| 1060 | `vector_concat` | 90 | 6.8s |  |
| 1061 | `vector_constr` | 107 | 6.8s |  |
| 1062 | `vector_enumeration` | 5 | 6.4s |  |
| 1063 | `vector_every` | 92 | 7.0s |  |
| 1064 | `vector_filter` | 95 | 7.2s |  |
| 1065 | `vector_holes` | 24 | 6.5s |  |
| 1066 | `vector_indexof` | 302 | 10.0s |  |
| 1067 | `vector_insertat` | 270 | 7.2s |  |
| 1068 | `vector_int_access` | 4 | 6.3s |  |
| 1069 | `vector_int_delete` | 11 | 6.5s |  |
| 1070 | `vector_join` | 58 | 6.8s |  |
| 1071 | `vector_lastindexof` | 302 | 6.2s |  |
| 1072 | `vector_legacy` | 10 | 6.4s |  |
| 1073 | `vector_map` | 85 | 6.8s |  |
| 1074 | `vector_object_final` | 1 | 6.3s |  |
| 1075 | `vector_object_toString` | 10 | 6.3s |  |
| 1076 | `vector_pushpop` | 255 | 45.6s |  |
| 1077 | `vector_reborrow_bug` | 10 | 26.5s |  |
| 1078 | `vector_removeat` | 172 | 8.7s |  |
| 1079 | `vector_reverse` | 232 | 8.7s |  |
| 1080 | `vector_shiftunshift` | 252 | 7.4s |  |
| 1081 | `vector_slice` | 331 | 9.2s |  |
| 1082 | `vector_sort` | 905 | 17.2s |  |
| 1083 | `vector_splice` | 693 | 11.6s |  |
| 1084 | `vector_splice_fixed_bug_compat` | 4 | 7.5s |  |
| 1085 | `vector_tostring` | 79 | 8.2s |  |
| 1086 | `verification` | 8 | 26.2s |  |
| 1087 | `verify_abnormal_loop` | 1 | 7.4s |  |
| 1088 | `verify_dxns_without_flag` | 3 | 7.9s |  |
| 1089 | `verify_exception_target_two_jumps` | 1 | 7.4s |  |
| 1090 | `verify_exception_targets_edge_case` | 1 | 7.4s |  |
| 1091 | `verify_illegal_opcode` | 1 | 3.3s |  |
| 1092 | `verify_jump_to_middle_of_op` | 1 | 7.4s |  |
| 1093 | `verify_lookup_switch_edge_case` | 1 | 7.4s |  |
| 1094 | `verify_stack` | 5 | 7.6s |  |
| 1095 | `verify_typecheck` | 4 | 7.5s |  |
| 1096 | `verify_unreachable_exception` | 2 | 7.5s |  |
| 1097 | `versioned_isplaying` | 2 | 7.6s |  |
| 1098 | `virtual_properties` | 16 | 7.6s |  |
| 1099 | `with` | 4 | 7.5s |  |
| 1100 | `wrong_arg_count` | 7 | 7.6s |  |
| 1101 | `xml_abstract_equality` | 36 | 7.7s |  |
| 1102 | `xml_advanced` | 52 | 7.5s |  |
| 1103 | `xml_appendchild` | 10 | 7.5s |  |
| 1104 | `xml_appendchild_swf_v21` | 13 | 7.8s |  |
| 1105 | `xml_as_attribute` | 9 | 7.4s |  |
| 1106 | `xml_attribute` | 35 | 7.7s |  |
| 1107 | `xml_attribute_name` | 40 | 7.5s |  |
| 1108 | `xml_basic` | 33 | 7.6s |  |
| 1109 | `xml_child` | 25 | 7.5s |  |
| 1110 | `xml_childindex` | 7 | 7.5s |  |
| 1111 | `xml_children` | 43 | 8.1s |  |
| 1112 | `xml_class_call` | 9 | 7.5s |  |
| 1113 | `xml_contains` | 197 | 7.6s |  |
| 1114 | `xml_copy` | 20 | 46.8s |  |
| 1115 | `xml_ctor_from_tostring` | 23 | 28.7s |  |
| 1116 | `xml_delete` | 114 | 8.4s |  |
| 1117 | `xml_descendants` | 83 | 8.3s |  |
| 1118 | `xml_elements` | 6 | 8.2s |  |
| 1119 | `xml_equals_namespace_check` | 2 | 28.3s |  |
| 1120 | `xml_explicit_use_namespace` | 5 | 8.3s |  |
| 1121 | `xml_getdescendants_qname` | 21 | 8.4s |  |
| 1122 | `xml_has_property_via_in` | 26 | 8.3s |  |
| 1123 | `xml_hasownproperty` | 6 | 8.2s |  |
| 1124 | `xml_ignore_white` | 6 | 8.3s |  |
| 1125 | `xml_length` | 2 | 8.3s |  |
| 1126 | `xml_list_as_attribute` | 9 | 8.2s |  |
| 1127 | `xml_list_concat` | 20 | 8.2s |  |
| 1128 | `xml_list_ctor_errors` | 34 | 8.4s |  |
| 1129 | `xml_list_delete_clear_parent` | 6 | 8.3s |  |
| 1130 | `xml_list_enumerate` | 4 | 8.2s |  |
| 1131 | `xml_methods_settings` | 3 | 8.2s |  |
| 1132 | `xml_mismatched_tag` | 37 | 8.3s |  |
| 1133 | `xml_namespace` | 39 | 8.2s |  |
| 1134 | `xml_namespace_methods` | 245 | 8.4s |  |
| 1135 | `xml_namespaced_property` | 7 | 8.3s |  |
| 1136 | `xml_no_namespace` | 1 | 8.4s |  |
| 1137 | `xml_nodekind` | 3 | 8.4s |  |
| 1138 | `xml_normalize` | 35 | 8.2s |  |
| 1139 | `xml_notification_bubbling` | 361 | 8.1s |  |
| 1140 | `xml_parent` | 8 | 8.0s |  |
| 1141 | `xml_set_children` | 17 | 8.1s |  |
| 1142 | `xml_set_name` | 34 | 8.0s |  |
| 1143 | `xml_settings` | 6 | 3.4s |  |
| 1144 | `xml_simple_complex_content` | 47 | 8.0s |  |
| 1145 | `xml_socket` | 11 | 8.4s |  |
| 1146 | `xml_text` | 7 | 8.0s |  |
| 1147 | `xml_tostring` | 6 | 8.1s |  |
| 1148 | `xml_tostring_namespace` | 12 | 8.0s |  |
| 1149 | `xml_unescaping` | 23 | 8.2s |  |
| 1150 | `xml_weird_ignores` | 54 | 8.3s |  |
| 1151 | `xml_wildcard` | 11 | 8.2s |  |
| 1152 | `xmldocument` | 254 | 8.2s |  |
| 1153 | `xmlnode` | 3540 | 8.4s |  |
| 1154 | `zero_frame_clip` | 3 | 8.9s |  |

## Ruffle-Matched Tests

**31 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 8.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.1s |  |
| 3 | `blend_transform` | 1 | 1 | 8.7s |  |
| 4 | `coerce_property` | 3 | 3 | 8.0s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.8s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 26.5s |  |
| 7 | `edittext_device_transform_layout` | 20 | 20 | 7.7s |  |
| 8 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.8s |  |
| 9 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 7.6s |  |
| 10 | `edittext_tab_stops` | 6 | 6 | 7.9s |  |
| 11 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.7s |  |
| 12 | `error_1034_debug_string` | 19 | 19 | 8.2s |  |
| 13 | `freestanding_superclass` | 2 | 4 | 29.2s |  |
| 14 | `goto_framescript_queued` | 5 | 5 | 28.5s |  |
| 15 | `graphics_draw_path` | 50 | 50 | 27.0s |  |
| 16 | `groupelement_text` | 2 | 2 | 7.5s |  |
| 17 | `int_toexponential` | 76 | 76 | 8.2s |  |
| 18 | `matrix3d_append_rotation` | 1 | 3 | 7.8s |  |
| 19 | `matrix3d_recompose_edge_cases` | 85 | 85 | 8.3s |  |
| 20 | `simplebutton_childevents_script_order` | 4 | 4 | 8.3s |  |
| 21 | `slot_holes_fail` | 1 | 1 | 8.0s |  |
| 22 | `slot_id_exceeds_trait_count` | 1 | 1 | 27.8s |  |
| 23 | `soundchannel_position` | 74 | 74 | 27.2s |  |
| 24 | `soundchannel_soundcomplete` | 10 | 10 | 7.6s |  |
| 25 | `sprite_dropTarget` | 15 | 15 | 26.3s |  |
| 26 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.7s |  |
| 27 | `textblock_line_changes` | 44 | 44 | 8.3s |  |
| 28 | `textblock_releaselines` | 4 | 4 | 9.3s |  |
| 29 | `uint_toexponential` | 100 | 100 | 6.4s |  |
| 30 | `uncaught_errors_stringified` | 15 | 15 | 6.6s |  |
| 31 | `weird_superinterface_properties` | 1 | 1 | 26.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**21 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 2 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 3 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 4 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 5 | `matrix3d_raw_data` | 84.8% | 28 | 33 | 5 |  |
| 6 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 7 | `matrix3d_determinant` | 81.9% | 149 | 182 | 33 |  |
| 8 | `displayobject_scrollrect` | 81.8% | 27 | 33 | 6 |  |
| 9 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 10 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 11 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 12 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 13 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 14 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 15 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 16 | `loader_duplicate_class` | 60.4% | 29 | 48 | 19 |  |
| 17 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 18 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 19 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 20 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 21 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**58 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 2 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 3 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 4 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 5 | `matrix3d_raw_data` | 84.8% | 28/33 | 33 | 33 |  |
| 6 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 7 | `matrix3d_determinant` | 81.9% | 149/182 | 182 | 182 |  |
| 8 | `displayobject_scrollrect` | 81.8% | 27/33 | 33 | 33 |  |
| 9 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 10 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 11 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 12 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 13 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 14 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 15 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 16 | `loader_duplicate_class` | 60.4% | 29/48 | 48 | 48 |  |
| 17 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 18 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 19 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 20 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 21 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 22 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 23 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 24 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 25 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 26 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 27 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 28 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 29 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 30 | `matrix3d_precision` | 20.0% | 5/25 | 25 | 25 |  |
| 31 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 32 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 33 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 34 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 35 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 36 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 37 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 38 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 39 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 40 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 41 | `all_classes/events/swf30` | 1.1% | 25/2353 | 735 | 2353 |  |
| 42 | `all_classes/events/swf9` | 1.0% | 10/1030 | 731 | 1030 |  |
| 43 | `all_classes/events/swf10` | 0.9% | 15/1638 | 731 | 1638 |  |
| 44 | `all_classes/events/swf11` | 0.9% | 15/1750 | 731 | 1750 |  |
| 45 | `all_classes/events/swf12` | 0.8% | 15/1814 | 731 | 1814 |  |
| 46 | `automation_classes` | 0.8% | 1/122 | 4 | 122 |  |
| 47 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 48 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 49 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 50 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 51 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 52 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 53 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 54 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 55 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 56 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 57 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 58 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
