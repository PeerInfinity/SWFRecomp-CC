# Ruffle Test Results (Filtered)

**Date**: 2026-08-12 23:11 UTC

**Git SHA**: `bf585e4486`

**Run Duration**: 221m 53s

**Filtered**: 56 tests ignored out of 1240 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1184 |
| Passing | **1121** (94.7%) |
| Ruffle-matched | 4 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1125** (95.0%) |
| Failing | 59 |
| Total expected lines | 135513 |
| Matching lines | 115281 (85.1%) |
| Mismatched lines | 20232 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 59 | 100.0% |

## Passing Tests

**1121 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 26.8s |  |
| 2 | `accessibility` | 1 | 7.7s |  |
| 3 | `activation_class` | 6 | 7.7s |  |
| 4 | `add` | 1058 | 18.8s |  |
| 5 | `agal_compiler` | 13 | 10.0s |  |
| 6 | `air_datagram_socket` | 1 | 9.6s |  |
| 7 | `air_hidden_lookup` | 2 | 7.7s |  |
| 8 | `air_ifilepromise` | 1 | 7.6s |  |
| 9 | `all_classes/display3D/swf12` | 61 | 7.8s |  |
| 10 | `all_classes/errors/swf10` | 140 | 7.7s |  |
| 11 | `all_classes/errors/swf30` | 140 | 1.3s |  |
| 12 | `all_classes/errors/swf9` | 121 | 1.4s |  |
| 13 | `all_classes/security/swf11` | 3 | 7.8s |  |
| 14 | `all_classes/security/swf12` | 19 | 1.4s |  |
| 15 | `all_classes/security/swf13` | 53 | 1.3s |  |
| 16 | `all_classes/security/swf30` | 53 | 1.4s |  |
| 17 | `amf_array_serialization` | 17 | 10.2s |  |
| 18 | `amf_custom_obj` | 26 | 7.8s |  |
| 19 | `amf_dictionary` | 9 | 7.7s |  |
| 20 | `amf_function` | 46 | 7.8s |  |
| 21 | `amf_invalid_date` | 2 | 7.7s |  |
| 22 | `amf_missing_prop` | 6 | 7.8s |  |
| 23 | `amf_nondynamic_function_prop` | 6 | 7.7s |  |
| 24 | `amf_setter_error` | 8 | 8.0s |  |
| 25 | `amf_vector` | 40 | 8.0s |  |
| 26 | `amf_xml` | 6 | 7.8s |  |
| 27 | `application_domain` | 4 | 7.8s |  |
| 28 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.8s |  |
| 29 | `applicationdomain_hasdefinition_null` | 2 | 7.8s |  |
| 30 | `array_access` | 18 | 7.9s |  |
| 31 | `array_access_interpreter` | 4 | 7.8s |  |
| 32 | `array_access_no_pubns` | 2 | 7.7s |  |
| 33 | `array_concat` | 41 | 7.8s |  |
| 34 | `array_constr` | 10 | 7.8s |  |
| 35 | `array_delete` | 44 | 7.9s |  |
| 36 | `array_enumeration` | 10 | 7.8s |  |
| 37 | `array_enumeration_elements` | 11 | 7.8s |  |
| 38 | `array_every` | 8 | 7.8s |  |
| 39 | `array_filter` | 6 | 7.8s |  |
| 40 | `array_foreach` | 18 | 7.8s |  |
| 41 | `array_hasownproperty` | 11 | 7.8s |  |
| 42 | `array_holes` | 9 | 7.8s |  |
| 43 | `array_index_max` | 84 | 7.7s |  |
| 44 | `array_indexof` | 25 | 7.8s |  |
| 45 | `array_join` | 26 | 7.8s |  |
| 46 | `array_lastindexof` | 29 | 7.8s |  |
| 47 | `array_length` | 14 | 7.8s |  |
| 48 | `array_literal` | 3 | 7.7s |  |
| 49 | `array_map` | 8 | 7.7s |  |
| 50 | `array_pop` | 52 | 7.9s |  |
| 51 | `array_push` | 24 | 7.8s |  |
| 52 | `array_reborrow_bug` | 6 | 7.7s |  |
| 53 | `array_reverse` | 28 | 7.8s |  |
| 54 | `array_shift` | 51 | 3.5s |  |
| 55 | `array_slice` | 39 | 7.9s |  |
| 56 | `array_some` | 8 | 7.8s |  |
| 57 | `array_sort` | 297 | 8.3s |  |
| 58 | `array_sort_fun_swf12` | 2 | 7.8s |  |
| 59 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 60 | `array_sort_random` | 210 | 7.8s |  |
| 61 | `array_sort_swf10_32bit` | 1 | 7.7s |  |
| 62 | `array_sorton` | 545 | 8.5s |  |
| 63 | `array_sparse_ops` | 41 | 27.0s |  |
| 64 | `array_splice` | 133 | 8.0s |  |
| 65 | `array_splice2` | 428 | 8.0s |  |
| 66 | `array_splice_types` | 48 | 7.7s |  |
| 67 | `array_storage` | 8 | 7.7s |  |
| 68 | `array_tolocalestring` | 9 | 7.7s |  |
| 69 | `array_tostring` | 12 | 7.6s |  |
| 70 | `array_unshift` | 24 | 7.6s |  |
| 71 | `array_valueof` | 9 | 7.5s |  |
| 72 | `array_vector_null_callback` | 10 | 7.7s |  |
| 73 | `astype` | 28 | 7.7s |  |
| 74 | `astypelate` | 24 | 7.7s |  |
| 75 | `astypelate_propagates` | 1 | 7.5s |  |
| 76 | `asymmetric_key_events` | 11 | 7.8s |  |
| 77 | `av_classes` | 340 | 8.0s |  |
| 78 | `avm1movie_addcallback_call` | 14 | 7.8s |  |
| 79 | `avm2_catchup_dobj` | 158 | 8.4s |  |
| 80 | `away3d_advanced_shallow_water_demo` | 0 | 89.3s |  |
| 81 | `bevel_filter` | 187 | 7.7s |  |
| 82 | `bitand` | 1058 | 19.7s |  |
| 83 | `bitmap_constr` | 17 | 7.9s |  |
| 84 | `bitmap_data` | 1000 | 16.3s |  |
| 85 | `bitmap_pixelsnapping` | 2 | 27.3s |  |
| 86 | `bitmap_properties` | 23 | 7.7s |  |
| 87 | `bitmap_subclass` | 7 | 9.2s |  |
| 88 | `bitmap_subclass_properties` | 9 | 8.2s |  |
| 89 | `bitmap_timeline` | 9 | 7.8s |  |
| 90 | `bitmapdata_accuracy` | 1 | 46.4s |  |
| 91 | `bitmapdata_applyfilter_blur` | 0 | 27.4s |  |
| 92 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.4s |  |
| 93 | `bitmapdata_applyfilter_destpoint` | 0 | 27.0s |  |
| 94 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 27.3s |  |
| 95 | `bitmapdata_clone` | 13 | 7.7s |  |
| 96 | `bitmapdata_colortransform` | 0 | 7.9s |  |
| 97 | `bitmapdata_colortransform_oob` | 2 | 7.4s |  |
| 98 | `bitmapdata_constr` | 22 | 7.6s |  |
| 99 | `bitmapdata_constructor_from_timeline` | 1 | 7.9s |  |
| 100 | `bitmapdata_copychannel` | 0 | 28.1s |  |
| 101 | `bitmapdata_copypixels` | 23 | 9.0s |  |
| 102 | `bitmapdata_copypixels_blend_over` | 1 | 7.9s |  |
| 103 | `bitmapdata_copypixelstobytearray` | 39 | 7.5s |  |
| 104 | `bitmapdata_dispose` | 7 | 7.4s |  |
| 105 | `bitmapdata_draw` | 0 | 27.6s |  |
| 106 | `bitmapdata_draw_colortransform` | 0 | 7.8s |  |
| 107 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.9s |  |
| 108 | `bitmapdata_draw_filters` | 0 | 26.4s |  |
| 109 | `bitmapdata_draw_masks` | 0 | 7.5s |  |
| 110 | `bitmapdata_draw_rotation` | 0 | 7.3s |  |
| 111 | `bitmapdata_draw_self_via_graphic` | 0 | 8.0s |  |
| 112 | `bitmapdata_draw_stage` | 0 | 26.0s |  |
| 113 | `bitmapdata_drawwithquality` | 0 | 7.9s |  |
| 114 | `bitmapdata_embedded` | 9 | 7.6s |  |
| 115 | `bitmapdata_fillrect` | 0 | 7.4s |  |
| 116 | `bitmapdata_filter_sourcerect` | 0 | 26.6s |  |
| 117 | `bitmapdata_floodfill` | 35 | 7.2s |  |
| 118 | `bitmapdata_getpixels` | 39 | 26.2s |  |
| 119 | `bitmapdata_getvector` | 27 | 3.1s |  |
| 120 | `bitmapdata_histogram` | 59 | 2.9s |  |
| 121 | `bitmapdata_hittest` | 112 | 7.5s |  |
| 122 | `bitmapdata_hittest_threshold` | 18 | 7.0s |  |
| 123 | `bitmapdata_opaque` | 0 | 7.2s |  |
| 124 | `bitmapdata_pixeldissolve` | 1037 | 7.9s |  |
| 125 | `bitmapdata_pixeldissolve_image` | 0 | 7.7s |  |
| 126 | `bitmapdata_rectangle_rounding` | 16 | 7.2s |  |
| 127 | `bitmapdata_setpixels` | 286 | 7.0s |  |
| 128 | `bitmapdata_setvector` | 26 | 7.0s |  |
| 129 | `bitmapdata_sync` | 0 | 26.3s |  |
| 130 | `bitmapdata_threshold` | 176 | 7.7s |  |
| 131 | `bitmapdata_zero_size` | 8 | 8.4s |  |
| 132 | `bitnot` | 46 | 7.4s |  |
| 133 | `bitor` | 1058 | 16.9s |  |
| 134 | `bitxor` | 1058 | 16.3s |  |
| 135 | `blend_mode_null` | 1 | 7.1s |  |
| 136 | `blend_multiply_alpha` | 0 | 7.3s |  |
| 137 | `blend_scroll` | 0 | 7.4s |  |
| 138 | `blend_shader_luma_lighten` | 3 | 7.7s |  |
| 139 | `blur_filter` | 43 | 7.3s |  |
| 140 | `boolean_constr` | 32 | 7.1s |  |
| 141 | `boolean_negation` | 30 | 7.7s |  |
| 142 | `boolean_tostring` | 8 | 7.6s |  |
| 143 | `broadcast_event` | 7 | 7.8s |  |
| 144 | `button_bounds` | 1 | 7.7s |  |
| 145 | `button_hittest` | 2 | 26.6s |  |
| 146 | `button_nested_frame` | 48 | 27.4s |  |
| 147 | `bytearray` | 48 | 8.0s |  |
| 148 | `bytearray_compress` | 31 | 26.8s |  |
| 149 | `bytearray_errors` | 24 | 7.7s |  |
| 150 | `bytearray_method_serialization` | 1 | 7.5s |  |
| 151 | `bytearray_readobject_amf0` | 50 | 7.7s |  |
| 152 | `bytearray_readobject_amf3` | 53 | 7.6s |  |
| 153 | `bytearray_readutf8bytes_with_bom` | 16 | 7.7s |  |
| 154 | `bytearray_serialization` | 3 | 7.6s |  |
| 155 | `bytearray_string_null` | 19 | 7.9s |  |
| 156 | `bytearray_tostring` | 15 | 7.6s |  |
| 157 | `bytearray_utf16` | 8 | 7.6s |  |
| 158 | `bytearray_writeobject` | 24 | 7.5s |  |
| 159 | `callee_in_initializer` | 6 | 7.5s |  |
| 160 | `callproplex_class` | 1 | 7.5s |  |
| 161 | `capabilities_resolution` | 8 | 28.0s |  |
| 162 | `catch_class` | 6 | 7.5s |  |
| 163 | `catch_scope_slot` | 7 | 3.3s |  |
| 164 | `checkfilter` | 4 | 3.2s |  |
| 165 | `class_call` | 32 | 7.8s |  |
| 166 | `class_cast_call` | 14 | 7.6s |  |
| 167 | `class_enumeration` | 4 | 7.6s |  |
| 168 | `class_has_own_property` | 2 | 7.6s |  |
| 169 | `class_init_interpreter_mode` | 1 | 7.5s |  |
| 170 | `class_is` | 32 | 7.7s |  |
| 171 | `class_methods` | 5 | 7.6s |  |
| 172 | `class_object_properties` | 10 | 7.6s |  |
| 173 | `class_singleton` | 18 | 7.6s |  |
| 174 | `class_supercalls_errors` | 35 | 7.8s |  |
| 175 | `class_supercalls_mismatched` | 26 | 7.7s |  |
| 176 | `class_superclass_wrong_order` | 1 | 26.4s |  |
| 177 | `class_to_locale_string` | 2 | 7.5s |  |
| 178 | `class_to_string` | 2 | 7.5s |  |
| 179 | `class_value_of` | 2 | 7.5s |  |
| 180 | `click_block` | 5 | 9.0s |  |
| 181 | `click_invisible` | 3 | 8.3s |  |
| 182 | `closures` | 12 | 7.9s |  |
| 183 | `coerce_return_type` | 40 | 8.0s |  |
| 184 | `coerce_return_type_fail` | 2 | 7.9s |  |
| 185 | `coerce_return_void` | 3 | 7.8s |  |
| 186 | `coerce_string` | 86 | 8.2s |  |
| 187 | `coerce_string_precision` | 28 | 8.0s |  |
| 188 | `coerce_to_primitive_side_effects` | 29 | 27.6s |  |
| 189 | `color_matrix_filter` | 19 | 8.0s |  |
| 190 | `construct_errors_swf10` | 8 | 8.0s |  |
| 191 | `construct_frame_list` | 22 | 28.3s |  |
| 192 | `construct_interface` | 3 | 7.9s |  |
| 193 | `constructor_call` | 3 | 7.9s |  |
| 194 | `constructors_vs_timeline` | 5 | 27.8s |  |
| 195 | `constructprop_dynamic_primitive` | 7 | 8.0s |  |
| 196 | `constructprop_method` | 2 | 7.9s |  |
| 197 | `constructsuper_null` | 2 | 7.8s |  |
| 198 | `content_element_basic` | 50 | 8.2s |  |
| 199 | `context3d_creation` | 9 | 8.0s |  |
| 200 | `control_flow_bool` | 4 | 7.9s |  |
| 201 | `control_flow_stricteq` | 8 | 7.9s |  |
| 202 | `convert_boolean` | 30 | 7.9s |  |
| 203 | `convert_integer` | 90 | 8.1s |  |
| 204 | `convert_number` | 56 | 8.0s |  |
| 205 | `convert_uinteger` | 90 | 8.2s |  |
| 206 | `convolution_filter` | 89 | 8.1s |  |
| 207 | `core_exceptions` | 47 | 8.9s |  |
| 208 | `cpool_index_invalid_bytecode_1` | 6 | 8.0s |  |
| 209 | `cpool_index_invalid_bytecode_2` | 3 | 7.9s |  |
| 210 | `cpool_index_invalid_bytecode_3` | 1 | 7.9s |  |
| 211 | `cross_api_version_call_newer` | 12 | 8.7s |  |
| 212 | `cross_api_version_call_older` | 12 | 8.4s |  |
| 213 | `cryptscore` | 11 | 8.2s |  |
| 214 | `currency_parse_result` | 7 | 8.2s |  |
| 215 | `date_parse` | 36 | 8.1s |  |
| 216 | `declocal` | 46 | 8.1s |  |
| 217 | `declocal_i` | 46 | 8.1s |  |
| 218 | `decode_uri` | 71 | 8.4s |  |
| 219 | `decrement` | 46 | 7.9s |  |
| 220 | `decrement_i` | 46 | 7.8s |  |
| 221 | `default_values` | 7 | 7.8s |  |
| 222 | `describe_type_basic` | 152 | 7.9s |  |
| 223 | `describe_type_json` | 301 | 7.9s |  |
| 224 | `describe_type_metadata` | 125 | 7.9s |  |
| 225 | `describe_type_native` | 23 | 7.8s |  |
| 226 | `dictionary_access` | 62 | 8.0s |  |
| 227 | `dictionary_access_no_pubns` | 2 | 7.7s |  |
| 228 | `dictionary_delete` | 101 | 8.2s |  |
| 229 | `dictionary_foreach` | 42 | 8.0s |  |
| 230 | `dictionary_hasownproperty` | 63 | 8.0s |  |
| 231 | `dictionary_in` | 62 | 8.0s |  |
| 232 | `dictionary_iter_modify` | 8 | 7.8s |  |
| 233 | `dictionary_namespaces` | 36 | 7.9s |  |
| 234 | `dictionary_primitive_keys` | 29 | 7.8s |  |
| 235 | `displacement_map_filter` | 61 | 7.9s |  |
| 236 | `displayobject_alpha` | 277 | 7.7s |  |
| 237 | `displayobject_blendmode` | 0 | 9.0s |  |
| 238 | `displayobject_colortransform_nested` | 0 | 27.3s |  |
| 239 | `displayobject_filters` | 17 | 7.9s |  |
| 240 | `displayobject_from_enterframe` | 1 | 27.0s |  |
| 241 | `displayobject_getbounds_shape` | 0 | 27.0s |  |
| 242 | `displayobject_height` | 6052 | 27.6s |  |
| 243 | `displayobject_hittestobject` | 32 | 8.0s |  |
| 244 | `displayobject_hittestpoint` | 49 | 8.2s |  |
| 245 | `displayobject_hittestpoint_root` | 13 | 8.1s |  |
| 246 | `displayobject_invalid_floats` | 60 | 7.8s |  |
| 247 | `displayobject_invalid_props` | 3 | 7.8s |  |
| 248 | `displayobject_mask` | 3 | 8.2s |  |
| 249 | `displayobject_mask_self_referential` | 0 | 7.7s |  |
| 250 | `displayobject_metaData` | 3 | 7.7s |  |
| 251 | `displayobject_name` | 22 | 8.0s |  |
| 252 | `displayobject_name_from_timeline` | 24 | 8.1s |  |
| 253 | `displayobject_opaque_background` | 6 | 7.9s |  |
| 254 | `displayobject_parent` | 12 | 7.8s |  |
| 255 | `displayobject_root` | 24 | 27.0s |  |
| 256 | `displayobject_rotation` | 1284 | 7.9s |  |
| 257 | `displayobject_set_matrix_nested` | 0 | 27.8s |  |
| 258 | `displayobject_set_name_loaded` | 3 | 8.4s |  |
| 259 | `displayobject_subclass` | 2 | 8.1s |  |
| 260 | `displayobject_visible` | 23 | 8.1s |  |
| 261 | `displayobject_width` | 4852 | 28.4s |  |
| 262 | `displayobject_x` | 614 | 8.2s |  |
| 263 | `displayobject_y` | 617 | 8.2s |  |
| 264 | `displayobjectcontainer_addchild` | 32 | 8.3s |  |
| 265 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 8.2s |  |
| 266 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.4s |  |
| 267 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 8.3s |  |
| 268 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 8.2s |  |
| 269 | `displayobjectcontainer_addchildat` | 42 | 8.3s |  |
| 270 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 8.4s |  |
| 271 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 8.3s |  |
| 272 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.2s |  |
| 273 | `displayobjectcontainer_contains` | 66 | 28.4s |  |
| 274 | `displayobjectcontainer_getchildat` | 4 | 8.0s |  |
| 275 | `displayobjectcontainer_getchildbyname` | 9 | 7.9s |  |
| 276 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 8.1s |  |
| 277 | `displayobjectcontainer_getchildindex` | 28 | 7.9s |  |
| 278 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 8.0s |  |
| 279 | `displayobjectcontainer_removechild` | 10 | 7.8s |  |
| 280 | `displayobjectcontainer_removechild_errors` | 4 | 7.9s |  |
| 281 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 8.0s |  |
| 282 | `displayobjectcontainer_removechildat` | 18 | 7.9s |  |
| 283 | `displayobjectcontainer_removechildren` | 51 | 8.1s |  |
| 284 | `displayobjectcontainer_setchildindex` | 42 | 7.8s |  |
| 285 | `displayobjectcontainer_stopallmovieclips` | 2 | 27.8s |  |
| 286 | `displayobjectcontainer_swapchildren` | 42 | 8.0s |  |
| 287 | `displayobjectcontainer_swapchildrenat` | 42 | 7.9s |  |
| 288 | `displayobjectcontainer_timelineinstance` | 48 | 28.1s |  |
| 289 | `divide` | 1058 | 19.4s |  |
| 290 | `doabc_and_symbolclass_script_init_goto` | 7 | 27.2s |  |
| 291 | `doabc_and_symbolclass_script_init_normal` | 6 | 7.7s |  |
| 292 | `doabc_is_eager` | 1 | 27.1s |  |
| 293 | `documentclass` | 9 | 8.0s |  |
| 294 | `domain_memory` | 133 | 9.0s |  |
| 295 | `drag_drop` | 10 | 6.4s |  |
| 296 | `drop_shadow_filter` | 172 | 6.1s |  |
| 297 | `duplicate_defs` | 1 | 5.9s |  |
| 298 | `eager_init` | 1 | 5.9s |  |
| 299 | `east_asian_justifier_clone` | 8 | 18.1s |  |
| 300 | `edit_text_linkage` | 7 | 6.1s |  |
| 301 | `edittext_align` | 60 | 6.4s |  |
| 302 | `edittext_always_show_selection` | 0 | 22.9s |  |
| 303 | `edittext_antialiastype` | 296 | 6.2s |  |
| 304 | `edittext_at_point_methods_basic` | 16 | 7.2s |  |
| 305 | `edittext_autosize` | 39 | 6.4s |  |
| 306 | `edittext_autosize_align` | 0 | 22.2s |  |
| 307 | `edittext_autosize_height_dynamic` | 60 | 22.2s |  |
| 308 | `edittext_autosize_height_input` | 60 | 6.1s |  |
| 309 | `edittext_autosize_lazy_bounds_events` | 65 | 6.3s |  |
| 310 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.0s |  |
| 311 | `edittext_autosize_lazy_bounds_props` | 490 | 7.2s |  |
| 312 | `edittext_autosize_lazy_bounds_visual` | 0 | 21.9s |  |
| 313 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.2s |  |
| 314 | `edittext_bottom_scroll_v_basic` | 210 | 6.0s |  |
| 315 | `edittext_bounds_scale` | 24 | 21.6s |  |
| 316 | `edittext_bullet` | 30 | 6.1s |  |
| 317 | `edittext_default_format` | 221 | 6.3s |  |
| 318 | `edittext_default_format_empty` | 136 | 6.1s |  |
| 319 | `edittext_empty_text_format` | 7 | 6.0s |  |
| 320 | `edittext_focus_selection` | 5 | 5.9s |  |
| 321 | `edittext_font_size` | 45 | 6.1s |  |
| 322 | `edittext_format_empty_font` | 8 | 5.9s |  |
| 323 | `edittext_get_char_index_at_point` | 4 | 23.5s |  |
| 324 | `edittext_get_line_index_at_point` | 2 | 22.2s |  |
| 325 | `edittext_get_line_index_of_char` | 76 | 6.7s |  |
| 326 | `edittext_getcharboundaries` | 172 | 6.4s |  |
| 327 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.2s |  |
| 328 | `edittext_getcharboundaries_scroll` | 85 | 6.0s |  |
| 329 | `edittext_getlinemetrics` | 146 | 6.3s |  |
| 330 | `edittext_html` | 3101 | 6.4s |  |
| 331 | `edittext_html_condensewhite` | 487 | 6.1s |  |
| 332 | `edittext_html_entity` | 4 | 6.0s |  |
| 333 | `edittext_html_font_size_swf12` | 267 | 6.1s |  |
| 334 | `edittext_html_font_size_swf13` | 273 | 45.4s |  |
| 335 | `edittext_html_roundtrip` | 17 | 8.1s |  |
| 336 | `edittext_ime_focus_lost` | 9 | 27.2s |  |
| 337 | `edittext_input_control` | 12 | 8.0s |  |
| 338 | `edittext_leading` | 9 | 8.4s |  |
| 339 | `edittext_letter_spacing` | 15 | 8.4s |  |
| 340 | `edittext_line_methods` | 294 | 10.0s |  |
| 341 | `edittext_line_metrics` | 11 | 29.1s |  |
| 342 | `edittext_margins` | 25 | 8.0s |  |
| 343 | `edittext_max_scroll_h_basic` | 475 | 8.1s |  |
| 344 | `edittext_max_scroll_v_basic` | 1000 | 8.0s |  |
| 345 | `edittext_mouse_selection` | 363 | 29.2s |  |
| 346 | `edittext_mousedown` | 3 | 8.3s |  |
| 347 | `edittext_mouseenabled` | 26 | 7.8s |  |
| 348 | `edittext_newline_character` | 22 | 7.7s |  |
| 349 | `edittext_newline_stripping` | 64 | 11.6s |  |
| 350 | `edittext_newlines` | 30 | 8.0s |  |
| 351 | `edittext_paragraph_methods` | 257 | 7.8s |  |
| 352 | `edittext_paste_events` | 8 | 8.0s |  |
| 353 | `edittext_paste_maxchars` | 4 | 7.8s |  |
| 354 | `edittext_paste_restrict` | 16 | 7.6s |  |
| 355 | `edittext_restrict` | 191 | 7.7s |  |
| 356 | `edittext_restrict_events` | 22 | 7.7s |  |
| 357 | `edittext_scrollh` | 10 | 7.9s |  |
| 358 | `edittext_selected_text` | 9 | 7.8s |  |
| 359 | `edittext_set_html_same` | 17 | 7.8s |  |
| 360 | `edittext_set_text_vs_html` | 9 | 7.8s |  |
| 361 | `edittext_stylesheet` | 536 | 8.2s |  |
| 362 | `edittext_stylesheet_custom_tag` | 76 | 7.9s |  |
| 363 | `edittext_stylesheet_display` | 272 | 7.9s |  |
| 364 | `edittext_underline` | 40 | 8.0s |  |
| 365 | `edittext_width_height` | 103 | 8.2s |  |
| 366 | `edittext_wordwrap_word` | 150 | 7.8s |  |
| 367 | `edittext_wrap_breaks` | 2375 | 8.3s |  |
| 368 | `element_format_clone` | 44 | 7.9s |  |
| 369 | `element_format_constructor_order` | 64 | 3.6s |  |
| 370 | `element_format_properties` | 235 | 8.7s |  |
| 371 | `empty_bounds` | 1 | 7.6s |  |
| 372 | `encode_uri_surrogate_pair_invalid` | 8 | 7.7s |  |
| 373 | `encode_uri_surrogate_pair_swf11` | 15 | 44.7s |  |
| 374 | `equals` | 512 | 11.7s |  |
| 375 | `error_geterrormessage` | 779 | 7.8s |  |
| 376 | `error_prototype` | 15 | 7.9s |  |
| 377 | `error_stack_trace` | 45 | 7.8s |  |
| 378 | `error_stack_trace_debug_swf17` | 0 | 27.0s |  |
| 379 | `error_stack_trace_debug_swf18` | 0 | 7.5s |  |
| 380 | `error_stack_trace_edge_cases` | 6 | 7.8s |  |
| 381 | `error_stack_trace_release_swf17` | 0 | 7.7s |  |
| 382 | `error_stack_trace_release_swf18` | 0 | 7.4s |  |
| 383 | `error_throwerror` | 103 | 7.8s |  |
| 384 | `error_tostring` | 29 | 7.8s |  |
| 385 | `error_tostring_more` | 86 | 7.8s |  |
| 386 | `es3_inheritance` | 31 | 7.8s |  |
| 387 | `es4_inheritance` | 30 | 7.7s |  |
| 388 | `es4_interfaces` | 30 | 7.8s |  |
| 389 | `es4_method_binding` | 8 | 7.7s |  |
| 390 | `es4_oop_prototypes` | 14 | 7.9s |  |
| 391 | `es4_protected_inheritance` | 6 | 7.7s |  |
| 392 | `escape` | 71 | 7.8s |  |
| 393 | `escape_multi_byte` | 45 | 7.9s |  |
| 394 | `event_bubbles` | 2 | 7.8s |  |
| 395 | `event_cancelable` | 2 | 7.7s |  |
| 396 | `event_clone` | 20 | 7.9s |  |
| 397 | `event_clone_error_redispatch` | 3 | 8.0s |  |
| 398 | `event_clone_on_redispatch` | 10 | 8.0s |  |
| 399 | `event_formattostring` | 31 | 7.9s |  |
| 400 | `event_isdefaultprevented` | 12 | 7.8s |  |
| 401 | `event_target_getter` | 5 | 3.3s |  |
| 402 | `event_target_set` | 9 | 7.8s |  |
| 403 | `event_type` | 1 | 7.8s |  |
| 404 | `event_valueof_tostring` | 18 | 7.8s |  |
| 405 | `eventdispatcher_dispatchevent` | 12 | 7.8s |  |
| 406 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.9s |  |
| 407 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.9s |  |
| 408 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.8s |  |
| 409 | `eventdispatcher_dispatchevent_this` | 5 | 7.7s |  |
| 410 | `eventdispatcher_haseventlistener` | 25 | 7.8s |  |
| 411 | `eventdispatcher_interface_invoke` | 1 | 7.8s |  |
| 412 | `eventdispatcher_tostring` | 10 | 26.2s |  |
| 413 | `eventdispatcher_willtrigger` | 25 | 8.1s |  |
| 414 | `falsiness` | 30 | 8.0s |  |
| 415 | `fast_index_access` | 12 | 8.1s |  |
| 416 | `filefilter_properties` | 4 | 8.0s |  |
| 417 | `filereference_browse_cancel` | 3 | 8.0s |  |
| 418 | `filereference_browse_select` | 9 | 8.0s |  |
| 419 | `filereference_load` | 31 | 8.0s |  |
| 420 | `filereference_save` | 16 | 8.0s |  |
| 421 | `filereference_save_and_browse` | 42 | 8.0s |  |
| 422 | `filereference_save_and_load` | 22 | 8.0s |  |
| 423 | `filereference_uninitialized` | 8 | 7.9s |  |
| 424 | `filereferencelist_browse_cancel` | 6 | 7.9s |  |
| 425 | `filereferencelist_browse_select` | 7 | 8.0s |  |
| 426 | `filter_rewind` | 8 | 8.3s |  |
| 427 | `filters_array_holes` | 25 | 9.1s |  |
| 428 | `finddef` | 3 | 7.9s |  |
| 429 | `findprop_global_prototype` | 6 | 8.0s |  |
| 430 | `flash_media_video_constructor` | 156 | 8.7s |  |
| 431 | `flash_media_video_rotation_probe` | 27 | 8.0s |  |
| 432 | `flash_media_video_setter` | 40 | 8.4s |  |
| 433 | `flash_trace` | 17 | 8.2s |  |
| 434 | `flash_xml` | 29 | 8.0s |  |
| 435 | `flash_xml_cloneNode` | 22 | 8.0s |  |
| 436 | `flash_xml_namespace` | 109 | 7.8s |  |
| 437 | `flash_xml_removeNode` | 60 | 7.9s |  |
| 438 | `focus_events_code` | 161 | 28.1s |  |
| 439 | `focus_events_key_basic` | 132 | 28.2s |  |
| 440 | `focus_events_key_navigation` | 53 | 8.2s |  |
| 441 | `focus_events_key_same_object` | 26 | 7.9s |  |
| 442 | `focus_events_mixed_key_mouse` | 100 | 27.6s |  |
| 443 | `focus_events_mouse_basic` | 260 | 28.0s |  |
| 444 | `focus_events_mouse_focusable` | 112 | 28.3s |  |
| 445 | `focus_events_mouse_same_object` | 40 | 7.9s |  |
| 446 | `focus_remove` | 20 | 27.9s |  |
| 447 | `focus_root_movie` | 4 | 27.8s |  |
| 448 | `focus_stage` | 1 | 7.9s |  |
| 449 | `focusrect` | 18 | 8.8s |  |
| 450 | `focusrect_focuslost` | 9 | 8.0s |  |
| 451 | `focusrect_property` | 110 | 45.1s |  |
| 452 | `font_description_clone` | 14 | 7.9s |  |
| 453 | `font_embedded` | 24 | 8.6s |  |
| 454 | `font_enumeratefonts` | 41 | 8.8s |  |
| 455 | `font_enumeratefonts_filter` | 4 | 27.9s |  |
| 456 | `font_enumeratefonts_order` | 9 | 9.4s |  |
| 457 | `font_hasglyphs` | 40 | 8.6s |  |
| 458 | `font_registerfont` | 129 | 9.3s |  |
| 459 | `framelabel_constr` | 5 | 8.1s |  |
| 460 | `function_call` | 12 | 7.9s |  |
| 461 | `function_call_arguments` | 46 | 8.1s |  |
| 462 | `function_call_arguments_enumerate` | 5 | 7.8s |  |
| 463 | `function_call_coercion` | 108 | 8.3s |  |
| 464 | `function_call_default` | 6 | 7.8s |  |
| 465 | `function_call_rest` | 22 | 7.9s |  |
| 466 | `function_call_types` | 3 | 7.8s |  |
| 467 | `function_call_via_apply` | 11 | 7.9s |  |
| 468 | `function_call_via_call` | 3 | 7.8s |  |
| 469 | `function_display_anonymous` | 7 | 3.4s |  |
| 470 | `function_length` | 6 | 7.9s |  |
| 471 | `function_object` | 2 | 7.8s |  |
| 472 | `function_proto` | 5 | 7.8s |  |
| 473 | `function_proto_created` | 61 | 7.9s |  |
| 474 | `function_to_locale_string` | 4 | 7.8s |  |
| 475 | `function_to_string` | 4 | 7.8s |  |
| 476 | `function_type` | 6 | 7.9s |  |
| 477 | `function_unbound_this` | 51 | 7.9s |  |
| 478 | `function_value_of` | 4 | 7.8s |  |
| 479 | `game_input` | 4 | 7.8s |  |
| 480 | `generate_random_bytes` | 3 | 7.9s |  |
| 481 | `get_definition_by_name` | 11 | 7.8s |  |
| 482 | `get_qualified_class_name` | 20 | 7.9s |  |
| 483 | `get_qualified_super_class_name` | 18 | 7.9s |  |
| 484 | `get_slot_edge_cases` | 1 | 7.8s |  |
| 485 | `get_timer` | 2 | 3.4s |  |
| 486 | `getglobalslot` | 1 | 7.8s |  |
| 487 | `getouterscope` | 8 | 7.8s |  |
| 488 | `getouterscope_two_classobjects` | 13 | 7.8s |  |
| 489 | `getter_different_namespace_setter` | 2 | 7.7s |  |
| 490 | `glow_filter` | 127 | 25.4s |  |
| 491 | `goto_button_nested_framescript` | 28 | 27.6s |  |
| 492 | `goto_in_constructframe` | 12 | 28.0s |  |
| 493 | `goto_in_scene_last_frame` | 2 | 27.6s |  |
| 494 | `goto_methods` | 56 | 8.0s |  |
| 495 | `goto_methods_swfver10` | 8 | 7.8s |  |
| 496 | `goto_nested_construct_sibling` | 18 | 8.4s |  |
| 497 | `goto_nested_framescript` | 9 | 8.1s |  |
| 498 | `goto_on_orphan` | 15 | 8.0s |  |
| 499 | `gradient_bevel_filter` | 206 | 7.8s |  |
| 500 | `gradient_glow_filter` | 206 | 7.7s |  |
| 501 | `graphic_linkage` | 9 | 7.9s |  |
| 502 | `graphics_bad_direct_commands` | 5 | 11.6s |  |
| 503 | `graphics_bitmap_fill` | 0 | 29.0s |  |
| 504 | `graphics_bitmaps` | 0 | 8.5s |  |
| 505 | `graphics_direct_commands` | 0 | 8.4s |  |
| 506 | `graphics_draw_triangles` | 98 | 28.2s |  |
| 507 | `graphics_gradients` | 0 | 8.1s |  |
| 508 | `graphics_gradients_nulls` | 0 | 8.1s |  |
| 509 | `graphics_path` | 56 | 7.8s |  |
| 510 | `graphics_round_rects` | 0 | 7.7s |  |
| 511 | `graphics_simple_shapes` | 0 | 8.1s |  |
| 512 | `greaterequals` | 512 | 12.3s |  |
| 513 | `greaterthan` | 512 | 12.2s |  |
| 514 | `has_own_property` | 102 | 8.4s |  |
| 515 | `hasownproperty_namespaces` | 2 | 7.8s |  |
| 516 | `hello_world` | 1 | 7.8s |  |
| 517 | `hittest_morph` | 30 | 8.0s |  |
| 518 | `if_eq` | 10 | 7.9s |  |
| 519 | `if_gt` | 1 | 7.8s |  |
| 520 | `if_gte` | 10 | 3.3s |  |
| 521 | `if_lt` | 1 | 1.3s |  |
| 522 | `if_lte` | 10 | 7.8s |  |
| 523 | `if_ne` | 7 | 3.4s |  |
| 524 | `if_stricteq` | 6 | 7.9s |  |
| 525 | `if_strictne` | 11 | 7.8s |  |
| 526 | `ime_linux_dead_keys` | 10 | 7.9s |  |
| 527 | `in` | 102 | 26.4s |  |
| 528 | `inclocal` | 46 | 7.9s |  |
| 529 | `inclocal_i` | 46 | 8.1s |  |
| 530 | `increment` | 46 | 8.1s |  |
| 531 | `increment_i` | 46 | 8.0s |  |
| 532 | `indexing_delete` | 75 | 7.9s |  |
| 533 | `instanceof` | 58 | 8.2s |  |
| 534 | `instantiate_root_character` | 4 | 8.4s |  |
| 535 | `instantiation_on_enter_frame` | 7 | 27.2s |  |
| 536 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.9s |  |
| 537 | `int_constr` | 92 | 8.2s |  |
| 538 | `int_edge_cases` | 19 | 27.7s |  |
| 539 | `int_instanceof` | 3 | 7.9s |  |
| 540 | `int_tofixed` | 1215 | 7.9s |  |
| 541 | `int_tostring` | 3375 | 8.4s |  |
| 542 | `interactiveobject_enabled` | 25 | 8.0s |  |
| 543 | `interface_namespaces` | 78 | 8.3s |  |
| 544 | `invalid_utf8` | 12 | 8.2s |  |
| 545 | `is_finite` | 46 | 8.2s |  |
| 546 | `is_nan` | 46 | 8.1s |  |
| 547 | `is_prototype_of` | 12 | 8.2s |  |
| 548 | `issue_10221` | 2 | 8.1s |  |
| 549 | `issue_13780` | 12 | 8.2s |  |
| 550 | `issue_14901` | 1 | 8.0s |  |
| 551 | `issue_17675_edittext_paste_maxchars` | 1 | 8.1s |  |
| 552 | `issue_5292` | 5 | 8.1s |  |
| 553 | `issue_8630` | 2 | 28.2s |  |
| 554 | `issue_8630_placeremoveplace` | 15 | 8.1s |  |
| 555 | `issue_8630_placeremoveplace_scriptremove` | 16 | 8.0s |  |
| 556 | `issue_8630_scriptremove` | 11 | 7.9s |  |
| 557 | `istype` | 24 | 3.5s |  |
| 558 | `istypelate` | 58 | 8.4s |  |
| 559 | `istypelate_coerce` | 198 | 9.1s |  |
| 560 | `jpeg_loader_context` | 6 | 7.9s |  |
| 561 | `json_errors` | 9 | 27.9s |  |
| 562 | `json_parse` | 21 | 7.9s |  |
| 563 | `json_stringify` | 12 | 8.1s |  |
| 564 | `json_stringify_function` | 12 | 7.7s |  |
| 565 | `json_stringify_order` | 1 | 7.7s |  |
| 566 | `json_version_gated` | 1 | 25.3s |  |
| 567 | `key_input_80percent` | 1812 | 26.8s |  |
| 568 | `key_input_location` | 126 | 7.8s |  |
| 569 | `key_input_numpad` | 384 | 7.7s |  |
| 570 | `lazyinit` | 17 | 7.7s |  |
| 571 | `lessequals` | 512 | 11.3s |  |
| 572 | `lessthan` | 512 | 11.3s |  |
| 573 | `loader_bitmap_transparency` | 14 | 8.0s |  |
| 574 | `loader_bytes_unknown_content` | 14 | 7.9s |  |
| 575 | `loader_child_getdefinition` | 5 | 8.0s |  |
| 576 | `loader_duplicate_coerce` | 3 | 8.0s |  |
| 577 | `loader_duplicate_coerce_new_domain` | 4 | 7.8s |  |
| 578 | `loader_error_in_root_ctor` | 4 | 8.0s |  |
| 579 | `loader_events` | 92 | 11.6s |  |
| 580 | `loader_image` | 8 | 8.2s |  |
| 581 | `loader_jpegxr` | 2 | 27.0s |  |
| 582 | `loader_jpegxr_alpha` | 1 | 26.6s |  |
| 583 | `loader_loadbytes_events` | 30 | 8.4s |  |
| 584 | `loader_loadbytes_invalid_png` | 4 | 26.5s |  |
| 585 | `loader_loadbytes_url` | 12 | 8.1s |  |
| 586 | `loader_loaderurl` | 6 | 8.2s |  |
| 587 | `loader_method` | 85 | 7.8s |  |
| 588 | `loader_noninteractive_try_click_root` | 5 | 27.2s |  |
| 589 | `loader_reuse` | 38 | 8.0s |  |
| 590 | `loader_unknown_content` | 24 | 7.9s |  |
| 591 | `loader_visibility_interactive` | 1 | 7.9s |  |
| 592 | `loaderinfo_events` | 7 | 7.7s |  |
| 593 | `loaderinfo_loadurl` | 12 | 7.7s |  |
| 594 | `loaderinfo_more` | 6 | 7.9s |  |
| 595 | `loaderinfo_properties` | 18 | 7.8s |  |
| 596 | `loaderinfo_properties_not_loaded` | 23 | 7.8s |  |
| 597 | `loaderinfo_quine` | 1005 | 7.7s |  |
| 598 | `loaderinfo_root` | 10 | 7.7s |  |
| 599 | `loaderinfo_root_allows` | 2 | 7.7s |  |
| 600 | `localconnection_send` | 4 | 8.3s |  |
| 601 | `lshift` | 1058 | 19.7s |  |
| 602 | `mask_reapply` | 1 | 8.1s |  |
| 603 | `math` | 497 | 8.4s |  |
| 604 | `matrix3d` | 57 | 30.0s |  |
| 605 | `matrix3d_compose` | 34 | 8.6s |  |
| 606 | `matrix3d_invert` | 18 | 8.4s |  |
| 607 | `matrix3d_position` | 19 | 8.3s |  |
| 608 | `matrix3d_transpose` | 5 | 8.2s |  |
| 609 | `method_without_body` | 3 | 28.3s |  |
| 610 | `missing_external_interface` | 10 | 8.0s |  |
| 611 | `modulo` | 1058 | 19.7s |  |
| 612 | `morph_shape` | 2 | 28.3s |  |
| 613 | `mouse_children` | 192 | 29.0s |  |
| 614 | `mouse_click_events` | 90 | 28.0s |  |
| 615 | `mouse_double_click_events` | 188 | 8.0s |  |
| 616 | `mouse_empty_parent` | 4 | 8.1s |  |
| 617 | `mouse_over_while_dragging` | 3 | 8.1s |  |
| 618 | `mouse_pick_button_mode` | 2 | 8.1s |  |
| 619 | `mouse_pick_dobj_mask` | 4 | 8.3s |  |
| 620 | `mouse_pick_masking` | 7 | 27.7s |  |
| 621 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 27.4s |  |
| 622 | `mouse_pick_non_interactive_dobj_mask` | 3 | 8.4s |  |
| 623 | `mouse_pick_text` | 8 | 8.2s |  |
| 624 | `mouse_sibling` | 8 | 8.1s |  |
| 625 | `mouse_wheel_events` | 36 | 29.7s |  |
| 626 | `mouseevent_constr` | 66 | 8.1s |  |
| 627 | `mouseevent_stagexy` | 35 | 24.8s |  |
| 628 | `mouseevent_valueof_tostring` | 28 | 7.7s |  |
| 629 | `movieclip_addframescript` | 3 | 27.4s |  |
| 630 | `movieclip_child_property` | 16 | 7.9s |  |
| 631 | `movieclip_constr` | 21 | 7.9s |  |
| 632 | `movieclip_currentlabels` | 17 | 28.1s |  |
| 633 | `movieclip_currentlabels_dupes1` | 46 | 27.7s |  |
| 634 | `movieclip_currentlabels_dupes2` | 30 | 7.8s |  |
| 635 | `movieclip_currentlabels_dupes3` | 67 | 7.8s |  |
| 636 | `movieclip_currentscene` | 12 | 27.5s |  |
| 637 | `movieclip_dispatchevent` | 430 | 7.9s |  |
| 638 | `movieclip_dispatchevent_cancel` | 102 | 7.9s |  |
| 639 | `movieclip_dispatchevent_handlerorder` | 251 | 7.9s |  |
| 640 | `movieclip_dispatchevent_selfadd` | 80 | 7.8s |  |
| 641 | `movieclip_dispatchevent_target` | 899 | 7.8s |  |
| 642 | `movieclip_displayevents` | 96 | 27.6s |  |
| 643 | `movieclip_displayevents_clickgoto` | 676 | 27.3s |  |
| 644 | `movieclip_displayevents_clickgoto2` | 2001 | 8.4s |  |
| 645 | `movieclip_displayevents_clickplay` | 575 | 8.0s |  |
| 646 | `movieclip_displayevents_clicksymbol` | 562 | 8.0s |  |
| 647 | `movieclip_displayevents_constructframegoto` | 140 | 8.3s |  |
| 648 | `movieclip_displayevents_constructframeplay` | 50 | 8.1s |  |
| 649 | `movieclip_displayevents_constructframesymbol` | 144 | 8.0s |  |
| 650 | `movieclip_displayevents_dblhandler` | 21 | 7.9s |  |
| 651 | `movieclip_displayevents_enterframegoto` | 149 | 8.1s |  |
| 652 | `movieclip_displayevents_enterframeplay` | 48 | 7.9s |  |
| 653 | `movieclip_displayevents_enterframesymbol` | 149 | 27.4s |  |
| 654 | `movieclip_displayevents_exitframegoto` | 106 | 7.7s |  |
| 655 | `movieclip_displayevents_exitframeplay` | 44 | 7.7s |  |
| 656 | `movieclip_displayevents_exitframesymbol` | 135 | 7.8s |  |
| 657 | `movieclip_displayevents_looping` | 63 | 27.2s |  |
| 658 | `movieclip_displayevents_stopped` | 113 | 8.2s |  |
| 659 | `movieclip_displayevents_swap` | 96 | 3.1s |  |
| 660 | `movieclip_displayevents_timeline` | 128 | 27.6s |  |
| 661 | `movieclip_drawrect` | 54 | 7.7s |  |
| 662 | `movieclip_frameconstruct_skipped` | 9 | 7.9s |  |
| 663 | `movieclip_goto_during_frame_script` | 15 | 7.8s |  |
| 664 | `movieclip_goto_overwrite` | 14 | 27.6s |  |
| 665 | `movieclip_goto_scene_last_frame_int` | 1 | 28.2s |  |
| 666 | `movieclip_goto_scene_last_frame_label` | 1 | 7.6s |  |
| 667 | `movieclip_gotoandplay` | 15 | 26.3s |  |
| 668 | `movieclip_gotoandstop` | 13 | 34.7s |  |
| 669 | `movieclip_gotoandstop_children` | 4 | 6.3s |  |
| 670 | `movieclip_gotoandstop_framescripts1` | 4 | 6.1s |  |
| 671 | `movieclip_gotoandstop_framescripts2` | 4 | 2.6s |  |
| 672 | `movieclip_gotoandstop_framescripts_self` | 7 | 21.1s |  |
| 673 | `movieclip_gotoandstop_queueing` | 12 | 21.2s |  |
| 674 | `movieclip_hittest` | 67 | 6.3s |  |
| 675 | `movieclip_next_frame` | 2 | 21.1s |  |
| 676 | `movieclip_next_scene` | 6 | 21.0s |  |
| 677 | `movieclip_play` | 3 | 6.0s |  |
| 678 | `movieclip_prev_frame` | 3 | 5.8s |  |
| 679 | `movieclip_prev_scene` | 7 | 6.1s |  |
| 680 | `movieclip_properties` | 79 | 21.0s |  |
| 681 | `movieclip_queued_noop_goto_swf10` | 9 | 6.1s |  |
| 682 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 683 | `movieclip_scenes` | 11 | 6.0s |  |
| 684 | `movieclip_soundtransform` | 831 | 22.8s |  |
| 685 | `movieclip_stop` | 1 | 20.9s |  |
| 686 | `movieclip_super_is_symbol` | 20 | 6.3s |  |
| 687 | `movieclip_symbol_constr` | 8 | 6.2s |  |
| 688 | `movieclip_text_mousedown` | 1 | 6.2s |  |
| 689 | `movieclip_willtrigger` | 5 | 6.3s |  |
| 690 | `multiply` | 1058 | 15.0s |  |
| 691 | `namespace_constr` | 253 | 6.5s |  |
| 692 | `namespace_constr_args` | 1 | 6.3s |  |
| 693 | `namespace_enumeration_order` | 7 | 21.5s |  |
| 694 | `nan_scale` | 9 | 6.1s |  |
| 695 | `navigateToURL_target_normalize` | 107 | 22.7s |  |
| 696 | `negate` | 30 | 6.2s |  |
| 697 | `negative_volume_panned` | 0 | 6.6s |  |
| 698 | `nested_iteration` | 11 | 6.1s |  |
| 699 | `net_getClassByAlias` | 3 | 6.1s |  |
| 700 | `net_navigateToURL` | 57 | 6.1s |  |
| 701 | `net_stream_play_options` | 6 | 6.5s |  |
| 702 | `netconnection_close` | 55 | 6.6s |  |
| 703 | `netconnection_properties` | 78 | 6.1s |  |
| 704 | `netconnection_send_remote` | 50 | 6.6s |  |
| 705 | `netconnection_serialize_arrays` | 6 | 6.3s |  |
| 706 | `netfilterevent` | 10 | 6.0s |  |
| 707 | `netstream_client` | 10 | 6.1s |  |
| 708 | `netstream_connect` | 7 | 25.0s |  |
| 709 | `netstream_flv_date` | 4 | 7.8s |  |
| 710 | `newactivation_in_script_init` | 3 | 7.5s |  |
| 711 | `newclass_mismatched` | 4 | 7.6s |  |
| 712 | `newclass_twice` | 3 | 7.5s |  |
| 713 | `nonconflicting_declarations` | 0 | 7.5s |  |
| 714 | `null_void_types` | 8 | 7.7s |  |
| 715 | `number_autoconv` | 21 | 7.6s |  |
| 716 | `number_autoconv_amf` | 132 | 7.6s |  |
| 717 | `number_autoconv_array_sort_32bit` | 1 | 7.5s |  |
| 718 | `number_constr` | 58 | 7.6s |  |
| 719 | `number_toexponential` | 378 | 7.7s |  |
| 720 | `number_toexponential2` | 35 | 7.6s |  |
| 721 | `number_tofixed` | 378 | 7.5s |  |
| 722 | `number_toprecision` | 350 | 7.7s |  |
| 723 | `obfuscated_class_names` | 3 | 7.6s |  |
| 724 | `object_enumeration` | 10 | 7.5s |  |
| 725 | `object_prototype` | 4 | 7.7s |  |
| 726 | `object_to_locale_string` | 2 | 7.6s |  |
| 727 | `object_to_string` | 2 | 7.5s |  |
| 728 | `object_value_of` | 2 | 3.1s |  |
| 729 | `op_coerce` | 54 | 7.6s |  |
| 730 | `op_coerce_x` | 54 | 7.7s |  |
| 731 | `op_escxattr` | 2 | 7.7s |  |
| 732 | `op_escxelem` | 2 | 7.5s |  |
| 733 | `op_lookupswitch` | 4 | 7.5s |  |
| 734 | `optimize_coerce` | 1 | 7.5s |  |
| 735 | `orphan_movie_complex` | 80 | 8.1s |  |
| 736 | `orphan_movie_reorder` | 111 | 27.3s |  |
| 737 | `package_namespace` | 7 | 7.4s |  |
| 738 | `param_default_value_has_zero_cpool_index` | 1 | 7.6s |  |
| 739 | `parent_early_access_child` | 16 | 27.0s |  |
| 740 | `parse_float` | 81 | 7.9s |  |
| 741 | `parse_float_swf10` | 81 | 7.4s |  |
| 742 | `parse_int` | 135 | 46.6s |  |
| 743 | `perspective_projection` | 1443 | 27.7s |  |
| 744 | `perspective_projection_basic` | 40 | 7.8s |  |
| 745 | `pixelbender_ceil` | 77 | 8.0s |  |
| 746 | `pixelbender_conditional` | 138 | 8.2s |  |
| 747 | `pixelbender_conversions` | 270 | 8.3s |  |
| 748 | `pixelbender_dithering` | 8 | 37.0s |  |
| 749 | `pixelbender_div` | 36 | 8.1s |  |
| 750 | `pixelbender_effect_BlurredFocus` | 0 | 35.9s |  |
| 751 | `pixelbender_effect_glassDisplace` | 0 | 14.4s |  |
| 752 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 32.9s |  |
| 753 | `pixelbender_effect_smudge` | 0 | 11.3s |  |
| 754 | `pixelbender_effect_tintype` | 0 | 10.6s |  |
| 755 | `pixelbender_effect_twirl` | 0 | 12.2s |  |
| 756 | `pixelbender_eof` | 7 | 8.0s |  |
| 757 | `pixelbender_images` | 0 | 10.5s |  |
| 758 | `pixelbender_input` | 103 | 28.3s |  |
| 759 | `pixelbender_logicalnot` | 20 | 7.8s |  |
| 760 | `pixelbender_malformed_data` | 190 | 27.7s |  |
| 761 | `pixelbender_multiple_out_params` | 1 | 7.7s |  |
| 762 | `pixelbender_no_out_param` | 6 | 7.7s |  |
| 763 | `pixelbender_outputs` | 13 | 8.0s |  |
| 764 | `pixelbender_padding_bytes` | 22 | 8.0s |  |
| 765 | `pixelbender_param_qualifier` | 512 | 8.2s |  |
| 766 | `pixelbender_parameters` | 1563 | 8.5s |  |
| 767 | `pixelbender_parameters_bool` | 240 | 8.4s |  |
| 768 | `pixelbender_parameters_int_vs_bool` | 54 | 8.1s |  |
| 769 | `pixelbender_parse_errors` | 6 | 8.1s |  |
| 770 | `pixelbender_rsqrt` | 24 | 7.9s |  |
| 771 | `pixelbender_select_kinds` | 8 | 8.0s |  |
| 772 | `pixelbender_shaderdata` | 49 | 8.0s |  |
| 773 | `pixelbender_shaderdata_setter` | 99 | 8.5s |  |
| 774 | `pixelbender_sign` | 60 | 8.4s |  |
| 775 | `pixelbender_vector_output` | 11 | 8.4s |  |
| 776 | `place_and_lookup/swf10` | 33 | 8.2s |  |
| 777 | `place_and_lookup/swf9` | 33 | 1.5s |  |
| 778 | `place_multiple` | 17 | 27.4s |  |
| 779 | `place_object_replace` | 9 | 8.3s |  |
| 780 | `place_object_replace_2` | 24 | 8.2s |  |
| 781 | `place_object_same_depth_frame` | 1 | 8.1s |  |
| 782 | `point` | 132 | 8.5s |  |
| 783 | `primitive_edge_cases` | 1 | 44.5s |  |
| 784 | `primitive_toString` | 277 | 8.0s |  |
| 785 | `primitive_valueOf` | 285 | 7.6s |  |
| 786 | `print_job_options` | 3 | 7.7s |  |
| 787 | `property_is_enumerable` | 114 | 8.4s |  |
| 788 | `property_is_enumerable_reset` | 23 | 7.8s |  |
| 789 | `property_priority` | 22 | 8.1s |  |
| 790 | `property_priority_chained` | 4 | 7.7s |  |
| 791 | `property_priority_definition_names_order` | 2 | 8.0s |  |
| 792 | `property_priority_three_level` | 6 | 26.6s |  |
| 793 | `propertyisenumerable_namespaces` | 6 | 7.8s |  |
| 794 | `prototype_set_null` | 7 | 7.7s |  |
| 795 | `proxy_callproperty` | 24 | 7.7s |  |
| 796 | `proxy_deleteproperty` | 64 | 7.8s |  |
| 797 | `proxy_enumeration` | 34 | 7.9s |  |
| 798 | `proxy_getproperty` | 77 | 7.9s |  |
| 799 | `proxy_hasownproperty` | 8 | 7.7s |  |
| 800 | `proxy_hasproperty` | 32 | 8.1s |  |
| 801 | `proxy_not_overridden` | 54 | 8.2s |  |
| 802 | `proxy_serialize` | 9 | 8.2s |  |
| 803 | `proxy_setproperty` | 42 | 8.3s |  |
| 804 | `qname_as_lazy_name_attribute_multiname` | 1 | 8.1s |  |
| 805 | `qname_constr` | 32 | 8.1s |  |
| 806 | `qname_constr_namespace` | 24 | 8.3s |  |
| 807 | `qname_enumeration` | 9 | 8.0s |  |
| 808 | `qname_indexing` | 23 | 8.0s |  |
| 809 | `qname_tostring` | 25 | 8.1s |  |
| 810 | `qname_valueof` | 29 | 8.1s |  |
| 811 | `rectangle` | 1094 | 8.8s |  |
| 812 | `regexp_constr` | 148 | 8.3s |  |
| 813 | `regexp_exec` | 19 | 8.1s |  |
| 814 | `regexp_extended` | 47 | 8.0s |  |
| 815 | `regexp_multiargs` | 1 | 8.0s |  |
| 816 | `regexp_test` | 27 | 8.0s |  |
| 817 | `regexp_toString` | 10 | 8.0s |  |
| 818 | `register_script_refresh` | 35 | 28.9s |  |
| 819 | `remove_child_clear_field` | 88 | 8.5s |  |
| 820 | `remove_dobj` | 3 | 8.0s |  |
| 821 | `resolve_order` | 4 | 7.8s |  |
| 822 | `responder_null_callbacks` | 1 | 7.7s |  |
| 823 | `rng` | 1 | 9.1s |  |
| 824 | `rootless` | 42 | 25.4s |  |
| 825 | `rshift` | 1058 | 19.1s |  |
| 826 | `rtqname_not_namespace` | 12 | 7.7s |  |
| 827 | `sandbox_type_inherited` | 2 | 8.2s |  |
| 828 | `sandbox_type_local_file` | 1 | 26.7s |  |
| 829 | `sandbox_type_local_network` | 1 | 7.5s |  |
| 830 | `scene_constr` | 8 | 7.9s |  |
| 831 | `scopes_dont_cache/order-1` | 1 | 26.3s |  |
| 832 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 833 | `security_domain_current` | 2 | 7.7s |  |
| 834 | `selection` | 239 | 8.3s |  |
| 835 | `set_local_0` | 31 | 7.8s |  |
| 836 | `set_property_is_enumerable` | 85 | 8.1s |  |
| 837 | `shaderparameter_value` | 4 | 7.7s |  |
| 838 | `shape_drawrect` | 54 | 7.7s |  |
| 839 | `shared_object_no_root` | 3 | 7.7s |  |
| 840 | `simplebutton_added_to_stage` | 45 | 26.6s |  |
| 841 | `simplebutton_childevents` | 86 | 27.0s |  |
| 842 | `simplebutton_childevents_nested` | 54 | 8.1s |  |
| 843 | `simplebutton_childevents_sprite` | 13 | 7.8s |  |
| 844 | `simplebutton_childprops` | 144 | 7.9s |  |
| 845 | `simplebutton_childshuffle` | 23 | 7.6s |  |
| 846 | `simplebutton_constr` | 36 | 7.9s |  |
| 847 | `simplebutton_constr_childevents` | 48 | 8.0s |  |
| 848 | `simplebutton_constr_params` | 42 | 7.8s |  |
| 849 | `simplebutton_mouseenabled` | 26 | 7.7s |  |
| 850 | `simplebutton_multi_children` | 19 | 8.0s |  |
| 851 | `simplebutton_structure` | 27 | 8.0s |  |
| 852 | `simplebutton_symbolclass` | 68 | 8.2s |  |
| 853 | `slot_disp_id_shared_numbering` | 1 | 26.3s |  |
| 854 | `slots_force_autoassigned` | 1 | 7.7s |  |
| 855 | `socket_after_disconnect` | 1 | 7.8s |  |
| 856 | `socket_close` | 2 | 7.6s |  |
| 857 | `socket_connect` | 4 | 26.1s |  |
| 858 | `socket_errors` | 56 | 28.6s |  |
| 859 | `socket_read_big` | 48 | 7.9s |  |
| 860 | `socket_read_little` | 48 | 3.3s |  |
| 861 | `socket_read_write_object` | 8 | 7.8s |  |
| 862 | `socket_write_big` | 15 | 8.2s |  |
| 863 | `socket_write_little` | 14 | 7.8s |  |
| 864 | `sound_constructor_with_args` | 6 | 8.1s |  |
| 865 | `sound_embeddedprops` | 26 | 8.1s |  |
| 866 | `sound_play` | 19 | 8.0s |  |
| 867 | `sound_rootless` | 7 | 8.0s |  |
| 868 | `sound_valueof` | 33 | 7.8s |  |
| 869 | `soundchannel_soundtransform` | 835 | 30.3s |  |
| 870 | `soundchannel_soundtransform_exists` | 5 | 27.6s |  |
| 871 | `soundchannel_stop` | 8 | 27.8s |  |
| 872 | `soundmixer_buffertime` | 5 | 7.8s |  |
| 873 | `soundmixer_stopall` | 6 | 27.7s |  |
| 874 | `soundtransform` | 442 | 13.8s |  |
| 875 | `space_justifier_clone` | 12 | 7.8s |  |
| 876 | `sprite_with_frames` | 0 | 32.0s |  |
| 877 | `stage3d_agal_cross_product` | 0 | 10.8s |  |
| 878 | `stage3d_agal_upload_errors` | 66 | 10.8s |  |
| 879 | `stage3d_bitmap` | 0 | 32.9s |  |
| 880 | `stage3d_blend` | 81 | 31.8s |  |
| 881 | `stage3d_context3d_string_args` | 158 | 8.8s |  |
| 882 | `stage3d_errors` | 7 | 7.8s |  |
| 883 | `stage3d_errors_atf` | 3 | 9.1s |  |
| 884 | `stage3d_errors_swf_29` | 6 | 8.0s |  |
| 885 | `stage3d_float1_index` | 0 | 30.3s |  |
| 886 | `stage3d_fractal` | 0 | 31.1s |  |
| 887 | `stage3d_ignore_sampler_override` | 0 | 30.5s |  |
| 888 | `stage3d_multistage_triangle` | 3 | 10.7s |  |
| 889 | `stage3d_program_constants_bytearray_be` | 0 | 32.2s |  |
| 890 | `stage3d_program_constants_bytearray_le` | 0 | 11.4s |  |
| 891 | `stage3d_program_constants_invalid_input` | 21 | 8.9s |  |
| 892 | `stage3d_raytrace` | 0 | 35.6s |  |
| 893 | `stage3d_rotating_cube` | 0 | 28.5s |  |
| 894 | `stage3d_sampler` | 0 | 9.0s |  |
| 895 | `stage3d_sampler_partial_upload` | 0 | 8.9s |  |
| 896 | `stage3d_stencil` | 0 | 28.5s |  |
| 897 | `stage3d_texture` | 0 | 13.9s |  |
| 898 | `stage3d_texture_bytearray` | 0 | 10.0s |  |
| 899 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.0s |  |
| 900 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.8s |  |
| 901 | `stage3d_triangle` | 0 | 9.0s |  |
| 902 | `stage3d_triangle_bytes4` | 0 | 9.1s |  |
| 903 | `stage3d_triangle_float1` | 0 | 9.2s |  |
| 904 | `stage3d_triangle_index_upload` | 0 | 8.9s |  |
| 905 | `stage3d_x_y` | 22 | 6.9s |  |
| 906 | `stage_access` | 10 | 6.8s |  |
| 907 | `stage_displayobject_properties` | 24 | 6.8s |  |
| 908 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.9s |  |
| 909 | `stage_framerate_nan` | 7 | 24.7s |  |
| 910 | `stage_framerate_negative` | 6 | 6.6s |  |
| 911 | `stage_framerate_zero` | 6 | 6.8s |  |
| 912 | `stage_invalidate` | 38 | 6.9s |  |
| 913 | `stage_loaderinfo_properties` | 24 | 24.5s |  |
| 914 | `stage_mousechildren` | 2 | 6.9s |  |
| 915 | `stage_mouseenabled` | 15 | 6.9s |  |
| 916 | `stage_overriden_setters` | 31 | 6.9s |  |
| 917 | `stage_properties` | 30 | 6.4s |  |
| 918 | `stage_properties2` | 213 | 6.4s |  |
| 919 | `stage_stage3Ds_vector` | 1 | 24.0s |  |
| 920 | `static_length` | 24 | 6.5s |  |
| 921 | `static_text` | 3 | 6.6s |  |
| 922 | `static_var_with_this_in_ctor` | 2 | 6.7s |  |
| 923 | `statictext_text` | 8 | 6.9s |  |
| 924 | `stored_properties` | 11 | 6.6s |  |
| 925 | `strict_equality` | 34 | 6.5s |  |
| 926 | `string_call` | 13 | 6.5s |  |
| 927 | `string_case` | 23 | 6.3s |  |
| 928 | `string_char_at` | 27 | 6.3s |  |
| 929 | `string_char_code_at` | 28 | 6.2s |  |
| 930 | `string_concat_fromcharcode` | 37 | 6.3s |  |
| 931 | `string_constr` | 25 | 6.3s |  |
| 932 | `string_indexof_lastindexof` | 87 | 33.6s |  |
| 933 | `string_length` | 16 | 5.4s |  |
| 934 | `string_locale_compare` | 39 | 5.9s |  |
| 935 | `string_match` | 51 | 5.6s |  |
| 936 | `string_relational_compare` | 4 | 5.7s |  |
| 937 | `string_replace` | 51 | 5.5s |  |
| 938 | `string_search` | 41 | 5.7s |  |
| 939 | `string_slice_substr_substring` | 170 | 5.9s |  |
| 940 | `string_split` | 29 | 5.4s |  |
| 941 | `string_substr_negative` | 21 | 5.5s |  |
| 942 | `string_substr_weird` | 182 | 5.9s |  |
| 943 | `stylesheet` | 221 | 5.8s |  |
| 944 | `stylesheet_parse_color` | 69 | 5.5s |  |
| 945 | `stylesheet_transform` | 307 | 5.8s |  |
| 946 | `subclass_superclass_linked_symbol` | 4 | 6.2s |  |
| 947 | `subtract` | 1058 | 13.2s |  |
| 948 | `super_get_call` | 12 | 5.6s |  |
| 949 | `supercall_two_classobjects` | 2 | 5.5s |  |
| 950 | `supercalls_weird` | 2 | 5.3s |  |
| 951 | `superinterface_call` | 20 | 5.6s |  |
| 952 | `superinterface_instanceof` | 18 | 5.8s |  |
| 953 | `swf8` | 1 | 6.2s |  |
| 954 | `swf_10_queued_goto_scripts_construct` | 52 | 19.8s |  |
| 955 | `swf_9_goto_in_enter_frame` | 17 | 5.5s |  |
| 956 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.4s |  |
| 957 | `swf_9_queued_goto_scripts` | 6 | 20.1s |  |
| 958 | `swf_9_queued_goto_scripts_construct` | 28 | 0.9s |  |
| 959 | `swf_9_versioning` | 2 | 5.7s |  |
| 960 | `swf_wrong_frame_count` | 38 | 6.1s |  |
| 961 | `swf_wrong_frame_count_isplaying` | 22 | 20.1s |  |
| 962 | `symbol_class_binary_data` | 8 | 5.2s |  |
| 963 | `symbol_class_conflict` | 4 | 7.8s |  |
| 964 | `symbol_class_root_not_zero` | 1 | 5.2s |  |
| 965 | `symbolclass_invalid_utf8` | 2 | 5.4s |  |
| 966 | `system_exit` | 3 | 5.4s |  |
| 967 | `system_setclipboard_null` | 1 | 5.2s |  |
| 968 | `tab_ordering_arrows` | 998 | 21.4s |  |
| 969 | `tab_ordering_automatic_advanced` | 184 | 36.7s |  |
| 970 | `tab_ordering_automatic_basic` | 45 | 21.8s |  |
| 971 | `tab_ordering_children` | 116 | 6.0s |  |
| 972 | `tab_ordering_custom_basic` | 34 | 5.8s |  |
| 973 | `tab_ordering_stage_tab_children` | 32 | 5.8s |  |
| 974 | `tab_ordering_stage_tab_children_remove_root` | 5 | 5.8s |  |
| 975 | `tab_ordering_tabbable` | 47 | 6.0s |  |
| 976 | `tabstop_properties` | 105 | 6.2s |  |
| 977 | `text_element_basic` | 34 | 5.9s |  |
| 978 | `text_engine_fontdescription` | 27 | 5.9s |  |
| 979 | `text_engine_groupelement` | 64 | 6.5s |  |
| 980 | `text_run` | 7 | 5.8s |  |
| 981 | `textblock_createline_errors` | 23 | 6.0s |  |
| 982 | `textblock_createline_fte` | 9 | 21.7s |  |
| 983 | `textblock_properties` | 118 | 6.2s |  |
| 984 | `textbox_click` | 37 | 21.9s |  |
| 985 | `textfield_event` | 66 | 6.1s |  |
| 986 | `textfield_focusin_event` | 9 | 5.8s |  |
| 987 | `textfield_input_dead_keys_windows` | 15 | 5.8s |  |
| 988 | `textfield_unload` | 39 | 21.7s |  |
| 989 | `textformat` | 1134 | 6.0s |  |
| 990 | `textformat_display` | 14 | 5.9s |  |
| 991 | `textformat_font_max_length` | 4 | 5.8s |  |
| 992 | `textline_inapplicable_properties` | 10 | 5.9s |  |
| 993 | `textline_name` | 1 | 5.8s |  |
| 994 | `textline_splitting_basic` | 76 | 5.9s |  |
| 995 | `textline_throwerror` | 30 | 5.8s |  |
| 996 | `textline_validity` | 162 | 5.9s |  |
| 997 | `throw` | 3 | 5.9s |  |
| 998 | `timeline_scripts` | 3 | 6.0s |  |
| 999 | `timer` | 90 | 6.7s |  |
| 1000 | `timer_events` | 3 | 5.9s |  |
| 1001 | `timer_finished` | 11 | 6.0s |  |
| 1002 | `timer_invalid_delay` | 30 | 5.8s |  |
| 1003 | `timer_reset` | 8 | 6.1s |  |
| 1004 | `timer_setdelay` | 5 | 24.6s |  |
| 1005 | `trace` | 12 | 7.3s |  |
| 1006 | `truthiness` | 30 | 7.2s |  |
| 1007 | `try_catch` | 11 | 7.2s |  |
| 1008 | `try_catch_typed` | 12 | 7.2s |  |
| 1009 | `typeof` | 30 | 7.2s |  |
| 1010 | `uint_constr` | 92 | 7.3s |  |
| 1011 | `uint_tofixed` | 1215 | 7.0s |  |
| 1012 | `uint_tostring` | 3375 | 7.4s |  |
| 1013 | `uncaught_error_basic` | 2 | 7.2s |  |
| 1014 | `unchecked_function` | 15 | 7.2s |  |
| 1015 | `unescape` | 28 | 7.1s |  |
| 1016 | `url_loader` | 25 | 7.2s |  |
| 1017 | `url_vars` | 27 | 7.2s |  |
| 1018 | `urlrequest` | 18 | 25.9s |  |
| 1019 | `urlstream_basic` | 5 | 7.1s |  |
| 1020 | `urshift` | 1058 | 19.3s |  |
| 1021 | `utils3d` | 7 | 7.1s |  |
| 1022 | `vector3d` | 397 | 11.7s |  |
| 1023 | `vector_class` | 36 | 7.6s |  |
| 1024 | `vector_class_call` | 11 | 7.3s |  |
| 1025 | `vector_coercion` | 66 | 8.0s |  |
| 1026 | `vector_concat` | 90 | 7.8s |  |
| 1027 | `vector_constr` | 107 | 7.8s |  |
| 1028 | `vector_enumeration` | 5 | 7.1s |  |
| 1029 | `vector_every` | 92 | 8.0s |  |
| 1030 | `vector_filter` | 95 | 8.0s |  |
| 1031 | `vector_holes` | 24 | 7.2s |  |
| 1032 | `vector_indexof` | 302 | 11.9s |  |
| 1033 | `vector_insertat` | 270 | 8.2s |  |
| 1034 | `vector_int_access` | 4 | 7.1s |  |
| 1035 | `vector_int_delete` | 11 | 7.1s |  |
| 1036 | `vector_join` | 58 | 7.6s |  |
| 1037 | `vector_lastindexof` | 302 | 7.1s |  |
| 1038 | `vector_legacy` | 10 | 7.2s |  |
| 1039 | `vector_map` | 85 | 7.8s |  |
| 1040 | `vector_object_final` | 1 | 7.0s |  |
| 1041 | `vector_object_toString` | 10 | 7.1s |  |
| 1042 | `vector_pushpop` | 255 | 25.9s |  |
| 1043 | `vector_reborrow_bug` | 10 | 26.0s |  |
| 1044 | `vector_removeat` | 172 | 8.8s |  |
| 1045 | `vector_reverse` | 232 | 8.8s |  |
| 1046 | `vector_shiftunshift` | 252 | 7.6s |  |
| 1047 | `vector_slice` | 331 | 9.2s |  |
| 1048 | `vector_sort` | 905 | 17.0s |  |
| 1049 | `vector_splice` | 693 | 11.8s |  |
| 1050 | `vector_splice_fixed_bug_compat` | 4 | 7.7s |  |
| 1051 | `vector_tostring` | 79 | 8.3s |  |
| 1052 | `verification` | 8 | 7.9s |  |
| 1053 | `verify_abnormal_loop` | 1 | 7.6s |  |
| 1054 | `verify_dxns_without_flag` | 3 | 8.1s |  |
| 1055 | `verify_exception_target_two_jumps` | 1 | 7.4s |  |
| 1056 | `verify_exception_targets_edge_case` | 1 | 7.4s |  |
| 1057 | `verify_illegal_opcode` | 1 | 3.5s |  |
| 1058 | `verify_jump_to_middle_of_op` | 1 | 7.3s |  |
| 1059 | `verify_lookup_switch_edge_case` | 1 | 7.4s |  |
| 1060 | `verify_method_info_oob` | 1 | 1.2s |  |
| 1061 | `verify_stack` | 5 | 7.5s |  |
| 1062 | `verify_typecheck` | 4 | 7.4s |  |
| 1063 | `verify_unreachable_exception` | 2 | 7.3s |  |
| 1064 | `versioned_isplaying` | 2 | 7.5s |  |
| 1065 | `virtual_properties` | 16 | 7.5s |  |
| 1066 | `with` | 4 | 7.5s |  |
| 1067 | `wrong_arg_count` | 7 | 7.6s |  |
| 1068 | `xml_abstract_equality` | 36 | 7.7s |  |
| 1069 | `xml_advanced` | 52 | 7.5s |  |
| 1070 | `xml_appendchild` | 10 | 7.5s |  |
| 1071 | `xml_appendchild_swf_v21` | 13 | 7.7s |  |
| 1072 | `xml_as_attribute` | 9 | 7.4s |  |
| 1073 | `xml_attribute` | 35 | 7.6s |  |
| 1074 | `xml_attribute_name` | 40 | 7.5s |  |
| 1075 | `xml_basic` | 33 | 7.5s |  |
| 1076 | `xml_child` | 25 | 7.5s |  |
| 1077 | `xml_childindex` | 7 | 7.5s |  |
| 1078 | `xml_children` | 43 | 8.1s |  |
| 1079 | `xml_class_call` | 9 | 7.5s |  |
| 1080 | `xml_contains` | 197 | 7.6s |  |
| 1081 | `xml_copy` | 20 | 44.3s |  |
| 1082 | `xml_ctor_from_tostring` | 23 | 7.9s |  |
| 1083 | `xml_delete` | 114 | 7.7s |  |
| 1084 | `xml_descendants` | 83 | 7.6s |  |
| 1085 | `xml_elements` | 6 | 7.5s |  |
| 1086 | `xml_equals_namespace_check` | 2 | 7.5s |  |
| 1087 | `xml_explicit_use_namespace` | 5 | 7.6s |  |
| 1088 | `xml_getdescendants_qname` | 21 | 7.7s |  |
| 1089 | `xml_has_property_via_in` | 26 | 7.6s |  |
| 1090 | `xml_hasownproperty` | 6 | 7.5s |  |
| 1091 | `xml_ignore_white` | 6 | 7.6s |  |
| 1092 | `xml_length` | 2 | 7.5s |  |
| 1093 | `xml_list_as_attribute` | 9 | 7.5s |  |
| 1094 | `xml_list_concat` | 20 | 7.6s |  |
| 1095 | `xml_list_ctor_errors` | 34 | 7.6s |  |
| 1096 | `xml_list_delete_clear_parent` | 6 | 7.5s |  |
| 1097 | `xml_list_enumerate` | 4 | 7.5s |  |
| 1098 | `xml_methods_settings` | 3 | 7.5s |  |
| 1099 | `xml_mismatched_tag` | 37 | 7.6s |  |
| 1100 | `xml_namespace` | 39 | 7.5s |  |
| 1101 | `xml_namespace_methods` | 245 | 7.6s |  |
| 1102 | `xml_namespaced_property` | 7 | 7.5s |  |
| 1103 | `xml_no_namespace` | 1 | 7.5s |  |
| 1104 | `xml_nodekind` | 3 | 7.5s |  |
| 1105 | `xml_normalize` | 35 | 7.7s |  |
| 1106 | `xml_notification_bubbling` | 361 | 7.6s |  |
| 1107 | `xml_parent` | 8 | 7.5s |  |
| 1108 | `xml_set_children` | 17 | 7.6s |  |
| 1109 | `xml_set_name` | 34 | 7.5s |  |
| 1110 | `xml_settings` | 6 | 3.1s |  |
| 1111 | `xml_simple_complex_content` | 47 | 7.5s |  |
| 1112 | `xml_socket` | 11 | 7.8s |  |
| 1113 | `xml_text` | 7 | 7.5s |  |
| 1114 | `xml_tostring` | 6 | 7.5s |  |
| 1115 | `xml_tostring_namespace` | 12 | 7.5s |  |
| 1116 | `xml_unescaping` | 23 | 7.6s |  |
| 1117 | `xml_weird_ignores` | 54 | 7.5s |  |
| 1118 | `xml_wildcard` | 11 | 7.4s |  |
| 1119 | `xmldocument` | 254 | 7.5s |  |
| 1120 | `xmlnode` | 3540 | 7.7s |  |
| 1121 | `zero_frame_clip` | 3 | 8.2s |  |

## Ruffle-Matched Tests

**4 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 8.0s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 8.0s |  |
| 3 | `groupelement_text` | 2 | 2 | 8.0s |  |
| 4 | `uncaught_errors_stringified` | 15 | 15 | 7.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**14 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 2 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 3 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 4 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 5 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 6 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 7 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 8 | `delayed_symbolclass` | 71.4% | 20 | 28 | 8 |  |
| 9 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 10 | `matrix3d_transform_vector` | 69.2% | 36 | 52 | 16 |  |
| 11 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 12 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 13 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 14 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**59 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 2 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 3 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 4 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 5 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 6 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 7 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 8 | `delayed_symbolclass` | 71.4% | 20/28 | 28 | 28 |  |
| 9 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 10 | `matrix3d_transform_vector` | 69.2% | 36/52 | 52 | 52 |  |
| 11 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 12 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 13 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 14 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 15 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 16 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 17 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 18 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 19 | `matrix3d_copy_column` | 28.9% | 24/83 | 73 | 83 |  |
| 20 | `matrix3d_copy_row` | 28.9% | 24/83 | 73 | 83 |  |
| 21 | `textblock_line_changes` | 24.7% | 119/481 | 469 | 481 |  |
| 22 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 23 | `textblock_recreateline` | 21.5% | 39/181 | 181 | 180 |  |
| 24 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 25 | `textline_raw_text_length` | 13.3% | 4/30 | 27 | 30 |  |
| 26 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 27 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 28 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 29 | `all_classes/accessibility/swf9` | 9.6% | 7/73 | 27 | 73 |  |
| 30 | `all_classes/accessibility/swf10` | 8.0% | 7/88 | 27 | 88 |  |
| 31 | `all_classes/accessibility/swf30` | 8.0% | 7/88 | 27 | 88 |  |
| 32 | `textblock_releaselines` | 5.5% | 41/752 | 695 | 752 |  |
| 33 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 34 | `all_classes/xml/swf30` | 4.3% | 5/116 | 61 | 116 |  |
| 35 | `all_classes/xml/swf9` | 4.3% | 5/116 | 61 | 116 |  |
| 36 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 37 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 38 | `all_classes/display3D/swf30` | 1.9% | 8/412 | 267 | 412 |  |
| 39 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 40 | `all_classes/display3D/swf13` | 1.8% | 6/326 | 211 | 326 |  |
| 41 | `automation_classes` | 0.8% | 1/122 | 4 | 122 |  |
| 42 | `all_classes/display/swf11` | 0.7% | 19/2593 | 1497 | 2593 |  |
| 43 | `all_classes/display/swf12` | 0.7% | 19/2593 | 1497 | 2593 |  |
| 44 | `all_classes/display/swf13` | 0.6% | 16/2671 | 1497 | 2671 |  |
| 45 | `all_classes/display/swf9` | 0.5% | 9/1959 | 1497 | 1959 |  |
| 46 | `all_classes/display/swf10` | 0.4% | 11/2569 | 1497 | 2569 |  |
| 47 | `all_classes/display/swf30` | 0.3% | 10/2936 | 1497 | 2936 |  |
| 48 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 49 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 50 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 51 | `matrix3d_append` | 0.0% | 0/16 | 11 | 16 |  |
| 52 | `matrix3d_append_rotation` | 0.0% | 0/23 | 18 | 23 |  |
| 53 | `matrix3d_copy_raw_data_from` | 0.0% | 0/55 | 18 | 55 |  |
| 54 | `matrix3d_copy_raw_data_to` | 0.0% | 0/38 | 33 | 38 |  |
| 55 | `matrix3d_prepend` | 0.0% | 0/16 | 11 | 16 |  |
| 56 | `matrix3d_recompose_edge_cases` | 0.0% | 0/198 | 158 | 198 |  |
| 57 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 58 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 59 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
