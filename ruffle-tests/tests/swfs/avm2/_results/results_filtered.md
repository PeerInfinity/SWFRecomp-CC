# Ruffle Test Results (Filtered)

**Date**: 2026-08-09 08:51 UTC

**Git SHA**: `0a99be1a92`

**Run Duration**: 196m 15s

**Filtered**: 56 tests ignored out of 1227 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1171 |
| Passing | **1107** (94.5%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1112** (95.0%) |
| Failing | 59 |
| Total expected lines | 133862 |
| Matching lines | 114513 (85.5%) |
| Mismatched lines | 19349 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 59 | 100.0% |

## Passing Tests

**1107 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 25.9s |  |
| 2 | `accessibility` | 1 | 6.6s |  |
| 3 | `activation_class` | 6 | 6.6s |  |
| 4 | `add` | 1058 | 18.9s |  |
| 5 | `agal_compiler` | 13 | 9.2s |  |
| 6 | `air_datagram_socket` | 1 | 8.3s |  |
| 7 | `air_hidden_lookup` | 2 | 6.5s |  |
| 8 | `air_ifilepromise` | 1 | 6.4s |  |
| 9 | `all_classes/security/swf11` | 3 | 6.6s |  |
| 10 | `amf_array_serialization` | 17 | 8.6s |  |
| 11 | `amf_custom_obj` | 26 | 6.4s |  |
| 12 | `amf_dictionary` | 9 | 6.3s |  |
| 13 | `amf_function` | 46 | 6.4s |  |
| 14 | `amf_invalid_date` | 2 | 6.3s |  |
| 15 | `amf_missing_prop` | 6 | 6.5s |  |
| 16 | `amf_nondynamic_function_prop` | 6 | 6.6s |  |
| 17 | `amf_setter_error` | 8 | 6.6s |  |
| 18 | `amf_vector` | 40 | 6.8s |  |
| 19 | `amf_xml` | 6 | 6.5s |  |
| 20 | `application_domain` | 4 | 6.6s |  |
| 21 | `applicationdomain_getqualifieddefinitionnames` | 9 | 6.7s |  |
| 22 | `applicationdomain_hasdefinition_null` | 2 | 6.5s |  |
| 23 | `array_access` | 18 | 6.6s |  |
| 24 | `array_access_interpreter` | 4 | 6.5s |  |
| 25 | `array_access_no_pubns` | 2 | 6.5s |  |
| 26 | `array_concat` | 41 | 6.6s |  |
| 27 | `array_constr` | 10 | 6.5s |  |
| 28 | `array_delete` | 44 | 6.6s |  |
| 29 | `array_enumeration` | 10 | 6.5s |  |
| 30 | `array_enumeration_elements` | 11 | 6.5s |  |
| 31 | `array_every` | 8 | 6.5s |  |
| 32 | `array_filter` | 6 | 6.5s |  |
| 33 | `array_foreach` | 18 | 6.5s |  |
| 34 | `array_hasownproperty` | 11 | 2.4s |  |
| 35 | `array_holes` | 9 | 6.5s |  |
| 36 | `array_index_max` | 84 | 6.5s |  |
| 37 | `array_indexof` | 25 | 6.6s |  |
| 38 | `array_join` | 26 | 6.6s |  |
| 39 | `array_lastindexof` | 29 | 6.6s |  |
| 40 | `array_length` | 14 | 6.5s |  |
| 41 | `array_literal` | 3 | 6.5s |  |
| 42 | `array_map` | 8 | 6.3s |  |
| 43 | `array_pop` | 52 | 6.6s |  |
| 44 | `array_push` | 24 | 6.6s |  |
| 45 | `array_reborrow_bug` | 6 | 6.5s |  |
| 46 | `array_reverse` | 28 | 6.6s |  |
| 47 | `array_shift` | 51 | 2.5s |  |
| 48 | `array_slice` | 39 | 6.6s |  |
| 49 | `array_some` | 8 | 6.6s |  |
| 50 | `array_sort` | 297 | 7.0s |  |
| 51 | `array_sort_fun_swf12` | 2 | 6.6s |  |
| 52 | `array_sort_fun_swf13` | 2 | 0.7s |  |
| 53 | `array_sort_random` | 210 | 6.6s |  |
| 54 | `array_sort_swf10_32bit` | 1 | 6.6s |  |
| 55 | `array_sorton` | 545 | 7.2s |  |
| 56 | `array_sparse_ops` | 41 | 6.4s |  |
| 57 | `array_splice` | 133 | 6.6s |  |
| 58 | `array_splice2` | 428 | 6.7s |  |
| 59 | `array_splice_types` | 48 | 6.4s |  |
| 60 | `array_storage` | 8 | 6.3s |  |
| 61 | `array_tolocalestring` | 9 | 6.3s |  |
| 62 | `array_tostring` | 12 | 6.4s |  |
| 63 | `array_unshift` | 24 | 6.4s |  |
| 64 | `array_valueof` | 9 | 6.3s |  |
| 65 | `array_vector_null_callback` | 10 | 6.4s |  |
| 66 | `astype` | 28 | 6.5s |  |
| 67 | `astypelate` | 24 | 6.5s |  |
| 68 | `astypelate_propagates` | 1 | 6.3s |  |
| 69 | `asymmetric_key_events` | 11 | 6.5s |  |
| 70 | `av_classes` | 340 | 6.7s |  |
| 71 | `avm1movie_addcallback_call` | 14 | 6.5s |  |
| 72 | `avm2_catchup_dobj` | 158 | 6.9s |  |
| 73 | `away3d_advanced_shallow_water_demo` | 0 | 83.7s |  |
| 74 | `bevel_filter` | 187 | 6.5s |  |
| 75 | `bitand` | 1058 | 18.5s |  |
| 76 | `bitmap_constr` | 17 | 6.5s |  |
| 77 | `bitmap_data` | 1000 | 14.5s |  |
| 78 | `bitmap_pixelsnapping` | 2 | 25.1s |  |
| 79 | `bitmap_properties` | 23 | 6.4s |  |
| 80 | `bitmap_subclass` | 7 | 7.8s |  |
| 81 | `bitmap_subclass_properties` | 9 | 6.7s |  |
| 82 | `bitmap_timeline` | 9 | 6.5s |  |
| 83 | `bitmapdata_accuracy` | 1 | 41.8s |  |
| 84 | `bitmapdata_applyfilter_blur` | 0 | 25.2s |  |
| 85 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.7s |  |
| 86 | `bitmapdata_applyfilter_destpoint` | 0 | 25.5s |  |
| 87 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.2s |  |
| 88 | `bitmapdata_clone` | 13 | 6.4s |  |
| 89 | `bitmapdata_colortransform` | 0 | 6.5s |  |
| 90 | `bitmapdata_colortransform_oob` | 2 | 6.3s |  |
| 91 | `bitmapdata_constr` | 22 | 6.4s |  |
| 92 | `bitmapdata_constructor_from_timeline` | 1 | 7.0s |  |
| 93 | `bitmapdata_copychannel` | 0 | 28.4s |  |
| 94 | `bitmapdata_copypixels` | 23 | 26.2s |  |
| 95 | `bitmapdata_copypixels_blend_over` | 1 | 6.6s |  |
| 96 | `bitmapdata_copypixelstobytearray` | 39 | 6.5s |  |
| 97 | `bitmapdata_dispose` | 7 | 6.5s |  |
| 98 | `bitmapdata_draw` | 0 | 25.7s |  |
| 99 | `bitmapdata_draw_colortransform` | 0 | 6.6s |  |
| 100 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.7s |  |
| 101 | `bitmapdata_draw_filters` | 0 | 25.6s |  |
| 102 | `bitmapdata_draw_masks` | 0 | 6.5s |  |
| 103 | `bitmapdata_draw_rotation` | 0 | 6.5s |  |
| 104 | `bitmapdata_draw_self_via_graphic` | 0 | 6.5s |  |
| 105 | `bitmapdata_draw_stage` | 0 | 25.5s |  |
| 106 | `bitmapdata_drawwithquality` | 0 | 6.7s |  |
| 107 | `bitmapdata_embedded` | 9 | 6.6s |  |
| 108 | `bitmapdata_fillrect` | 0 | 6.5s |  |
| 109 | `bitmapdata_filter_sourcerect` | 0 | 25.4s |  |
| 110 | `bitmapdata_floodfill` | 35 | 6.4s |  |
| 111 | `bitmapdata_getpixels` | 39 | 25.3s |  |
| 112 | `bitmapdata_getvector` | 27 | 2.4s |  |
| 113 | `bitmapdata_histogram` | 59 | 2.4s |  |
| 114 | `bitmapdata_hittest` | 112 | 7.0s |  |
| 115 | `bitmapdata_hittest_threshold` | 18 | 6.5s |  |
| 116 | `bitmapdata_opaque` | 0 | 6.4s |  |
| 117 | `bitmapdata_pixeldissolve` | 1037 | 7.1s |  |
| 118 | `bitmapdata_pixeldissolve_image` | 0 | 6.7s |  |
| 119 | `bitmapdata_rectangle_rounding` | 16 | 6.5s |  |
| 120 | `bitmapdata_setpixels` | 286 | 6.6s |  |
| 121 | `bitmapdata_setvector` | 26 | 6.6s |  |
| 122 | `bitmapdata_sync` | 0 | 25.3s |  |
| 123 | `bitmapdata_threshold` | 176 | 7.2s |  |
| 124 | `bitmapdata_zero_size` | 8 | 6.4s |  |
| 125 | `bitnot` | 46 | 6.5s |  |
| 126 | `bitor` | 1058 | 18.7s |  |
| 127 | `bitxor` | 1058 | 18.8s |  |
| 128 | `blend_mode_null` | 1 | 6.4s |  |
| 129 | `blend_multiply_alpha` | 0 | 6.5s |  |
| 130 | `blend_scroll` | 0 | 6.5s |  |
| 131 | `blend_shader_luma_lighten` | 3 | 6.7s |  |
| 132 | `blur_filter` | 43 | 6.4s |  |
| 133 | `boolean_constr` | 32 | 6.3s |  |
| 134 | `boolean_negation` | 30 | 6.3s |  |
| 135 | `boolean_tostring` | 8 | 6.2s |  |
| 136 | `broadcast_event` | 7 | 6.5s |  |
| 137 | `button_bounds` | 1 | 6.4s |  |
| 138 | `button_hittest` | 2 | 24.6s |  |
| 139 | `button_nested_frame` | 48 | 25.4s |  |
| 140 | `bytearray` | 48 | 6.6s |  |
| 141 | `bytearray_compress` | 31 | 6.3s |  |
| 142 | `bytearray_errors` | 24 | 6.4s |  |
| 143 | `bytearray_method_serialization` | 1 | 6.2s |  |
| 144 | `bytearray_readobject_amf0` | 50 | 6.2s |  |
| 145 | `bytearray_readobject_amf3` | 53 | 6.3s |  |
| 146 | `bytearray_readutf8bytes_with_bom` | 16 | 6.4s |  |
| 147 | `bytearray_serialization` | 3 | 6.3s |  |
| 148 | `bytearray_string_null` | 19 | 6.6s |  |
| 149 | `bytearray_tostring` | 15 | 6.3s |  |
| 150 | `bytearray_utf16` | 8 | 6.3s |  |
| 151 | `bytearray_writeobject` | 24 | 6.1s |  |
| 152 | `callee_in_initializer` | 6 | 6.2s |  |
| 153 | `callproplex_class` | 1 | 6.3s |  |
| 154 | `capabilities_resolution` | 8 | 25.7s |  |
| 155 | `catch_class` | 6 | 6.3s |  |
| 156 | `catch_scope_slot` | 7 | 2.3s |  |
| 157 | `checkfilter` | 4 | 2.2s |  |
| 158 | `class_call` | 32 | 6.4s |  |
| 159 | `class_cast_call` | 14 | 6.3s |  |
| 160 | `class_enumeration` | 4 | 6.3s |  |
| 161 | `class_has_own_property` | 2 | 6.2s |  |
| 162 | `class_init_interpreter_mode` | 1 | 6.2s |  |
| 163 | `class_is` | 32 | 6.3s |  |
| 164 | `class_methods` | 5 | 6.3s |  |
| 165 | `class_object_properties` | 10 | 6.3s |  |
| 166 | `class_singleton` | 18 | 6.3s |  |
| 167 | `class_supercalls_errors` | 35 | 6.5s |  |
| 168 | `class_supercalls_mismatched` | 26 | 6.6s |  |
| 169 | `class_superclass_wrong_order` | 1 | 25.4s |  |
| 170 | `class_to_locale_string` | 2 | 6.3s |  |
| 171 | `class_to_string` | 2 | 6.2s |  |
| 172 | `class_value_of` | 2 | 6.3s |  |
| 173 | `click_block` | 5 | 6.8s |  |
| 174 | `click_invisible` | 3 | 6.5s |  |
| 175 | `closures` | 12 | 6.3s |  |
| 176 | `coerce_return_type` | 40 | 6.4s |  |
| 177 | `coerce_return_type_fail` | 2 | 6.3s |  |
| 178 | `coerce_return_void` | 3 | 6.2s |  |
| 179 | `coerce_string` | 86 | 6.5s |  |
| 180 | `coerce_string_precision` | 28 | 6.3s |  |
| 181 | `coerce_to_primitive_side_effects` | 29 | 25.2s |  |
| 182 | `color_matrix_filter` | 19 | 6.8s |  |
| 183 | `construct_errors_swf10` | 8 | 6.6s |  |
| 184 | `construct_frame_list` | 22 | 25.2s |  |
| 185 | `construct_interface` | 3 | 6.4s |  |
| 186 | `constructor_call` | 3 | 6.3s |  |
| 187 | `constructors_vs_timeline` | 5 | 25.2s |  |
| 188 | `constructprop_dynamic_primitive` | 7 | 6.4s |  |
| 189 | `constructprop_method` | 2 | 6.3s |  |
| 190 | `constructsuper_null` | 2 | 2.2s |  |
| 191 | `content_element_basic` | 50 | 6.7s |  |
| 192 | `context3d_creation` | 9 | 6.4s |  |
| 193 | `control_flow_bool` | 4 | 6.4s |  |
| 194 | `control_flow_stricteq` | 8 | 6.4s |  |
| 195 | `convert_boolean` | 30 | 6.5s |  |
| 196 | `convert_integer` | 90 | 6.5s |  |
| 197 | `convert_number` | 56 | 6.5s |  |
| 198 | `convert_uinteger` | 90 | 6.5s |  |
| 199 | `convolution_filter` | 89 | 6.5s |  |
| 200 | `core_exceptions` | 47 | 7.2s |  |
| 201 | `cpool_index_invalid_bytecode_1` | 6 | 6.5s |  |
| 202 | `cpool_index_invalid_bytecode_2` | 3 | 6.3s |  |
| 203 | `cpool_index_invalid_bytecode_3` | 1 | 6.3s |  |
| 204 | `cross_api_version_call_newer` | 12 | 7.0s |  |
| 205 | `cross_api_version_call_older` | 12 | 6.6s |  |
| 206 | `cryptscore` | 11 | 6.4s |  |
| 207 | `currency_parse_result` | 7 | 5.2s |  |
| 208 | `date_parse` | 36 | 5.1s |  |
| 209 | `declocal` | 46 | 5.2s |  |
| 210 | `declocal_i` | 46 | 5.4s |  |
| 211 | `decode_uri` | 71 | 5.5s |  |
| 212 | `decrement` | 46 | 5.2s |  |
| 213 | `decrement_i` | 46 | 1.9s |  |
| 214 | `default_values` | 7 | 5.1s |  |
| 215 | `describe_type_basic` | 152 | 5.2s |  |
| 216 | `describe_type_json` | 301 | 5.3s |  |
| 217 | `dictionary_access` | 62 | 5.3s |  |
| 218 | `dictionary_access_no_pubns` | 2 | 5.1s |  |
| 219 | `dictionary_delete` | 101 | 5.4s |  |
| 220 | `dictionary_foreach` | 42 | 5.3s |  |
| 221 | `dictionary_hasownproperty` | 63 | 5.3s |  |
| 222 | `dictionary_in` | 62 | 5.3s |  |
| 223 | `dictionary_iter_modify` | 8 | 5.1s |  |
| 224 | `dictionary_namespaces` | 36 | 5.2s |  |
| 225 | `dictionary_primitive_keys` | 29 | 5.1s |  |
| 226 | `displacement_map_filter` | 61 | 5.3s |  |
| 227 | `displayobject_alpha` | 277 | 5.1s |  |
| 228 | `displayobject_blendmode` | 0 | 5.3s |  |
| 229 | `displayobject_colortransform_nested` | 0 | 20.6s |  |
| 230 | `displayobject_filters` | 17 | 5.3s |  |
| 231 | `displayobject_from_enterframe` | 1 | 20.5s |  |
| 232 | `displayobject_getbounds_shape` | 0 | 20.3s |  |
| 233 | `displayobject_height` | 6052 | 20.2s |  |
| 234 | `displayobject_hittestobject` | 32 | 5.3s |  |
| 235 | `displayobject_hittestpoint` | 49 | 5.4s |  |
| 236 | `displayobject_hittestpoint_root` | 13 | 5.9s |  |
| 237 | `displayobject_invalid_floats` | 60 | 5.4s |  |
| 238 | `displayobject_invalid_props` | 3 | 5.3s |  |
| 239 | `displayobject_mask` | 3 | 6.6s |  |
| 240 | `displayobject_mask_self_referential` | 0 | 25.4s |  |
| 241 | `displayobject_metaData` | 3 | 6.5s |  |
| 242 | `displayobject_name` | 22 | 25.4s |  |
| 243 | `displayobject_name_from_timeline` | 24 | 6.5s |  |
| 244 | `displayobject_opaque_background` | 6 | 25.1s |  |
| 245 | `displayobject_parent` | 12 | 6.4s |  |
| 246 | `displayobject_root` | 24 | 6.4s |  |
| 247 | `displayobject_rotation` | 1284 | 6.6s |  |
| 248 | `displayobject_set_matrix_nested` | 0 | 25.4s |  |
| 249 | `displayobject_set_name_loaded` | 3 | 6.7s |  |
| 250 | `displayobject_subclass` | 2 | 6.4s |  |
| 251 | `displayobject_visible` | 23 | 6.4s |  |
| 252 | `displayobject_width` | 4852 | 25.3s |  |
| 253 | `displayobject_x` | 614 | 6.4s |  |
| 254 | `displayobject_y` | 617 | 6.4s |  |
| 255 | `displayobjectcontainer_addchild` | 32 | 6.5s |  |
| 256 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.4s |  |
| 257 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.8s |  |
| 258 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.5s |  |
| 259 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.5s |  |
| 260 | `displayobjectcontainer_addchildat` | 42 | 6.5s |  |
| 261 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.6s |  |
| 262 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.5s |  |
| 263 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.5s |  |
| 264 | `displayobjectcontainer_contains` | 66 | 25.6s |  |
| 265 | `displayobjectcontainer_getchildat` | 4 | 6.4s |  |
| 266 | `displayobjectcontainer_getchildbyname` | 9 | 6.4s |  |
| 267 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.4s |  |
| 268 | `displayobjectcontainer_getchildindex` | 28 | 6.4s |  |
| 269 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 6.6s |  |
| 270 | `displayobjectcontainer_removechild` | 10 | 6.4s |  |
| 271 | `displayobjectcontainer_removechild_errors` | 4 | 6.5s |  |
| 272 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.5s |  |
| 273 | `displayobjectcontainer_removechildat` | 18 | 6.4s |  |
| 274 | `displayobjectcontainer_removechildren` | 51 | 6.7s |  |
| 275 | `displayobjectcontainer_setchildindex` | 42 | 6.3s |  |
| 276 | `displayobjectcontainer_stopallmovieclips` | 2 | 25.6s |  |
| 277 | `displayobjectcontainer_swapchildren` | 42 | 6.5s |  |
| 278 | `displayobjectcontainer_swapchildrenat` | 42 | 6.8s |  |
| 279 | `displayobjectcontainer_timelineinstance` | 48 | 26.8s |  |
| 280 | `divide` | 1058 | 19.2s |  |
| 281 | `doabc_and_symbolclass_script_init_goto` | 7 | 26.1s |  |
| 282 | `doabc_and_symbolclass_script_init_normal` | 6 | 6.6s |  |
| 283 | `doabc_is_eager` | 1 | 26.2s |  |
| 284 | `documentclass` | 9 | 6.6s |  |
| 285 | `domain_memory` | 133 | 26.8s |  |
| 286 | `drag_drop` | 10 | 6.7s |  |
| 287 | `drop_shadow_filter` | 172 | 6.7s |  |
| 288 | `duplicate_defs` | 1 | 6.4s |  |
| 289 | `eager_init` | 1 | 6.7s |  |
| 290 | `east_asian_justifier_clone` | 8 | 2.5s |  |
| 291 | `edit_text_linkage` | 7 | 6.9s |  |
| 292 | `edittext_align` | 60 | 7.4s |  |
| 293 | `edittext_always_show_selection` | 0 | 27.5s |  |
| 294 | `edittext_antialiastype` | 296 | 7.1s |  |
| 295 | `edittext_at_point_methods_basic` | 16 | 8.3s |  |
| 296 | `edittext_autosize` | 39 | 7.3s |  |
| 297 | `edittext_autosize_align` | 0 | 27.0s |  |
| 298 | `edittext_autosize_height_dynamic` | 60 | 26.9s |  |
| 299 | `edittext_autosize_height_input` | 60 | 6.8s |  |
| 300 | `edittext_autosize_lazy_bounds_events` | 65 | 7.1s |  |
| 301 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.8s |  |
| 302 | `edittext_autosize_lazy_bounds_props` | 490 | 8.1s |  |
| 303 | `edittext_autosize_lazy_bounds_visual` | 0 | 27.4s |  |
| 304 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.0s |  |
| 305 | `edittext_bottom_scroll_v_basic` | 210 | 6.9s |  |
| 306 | `edittext_bounds_scale` | 24 | 26.8s |  |
| 307 | `edittext_bullet` | 30 | 7.0s |  |
| 308 | `edittext_default_format` | 221 | 7.4s |  |
| 309 | `edittext_default_format_empty` | 136 | 7.1s |  |
| 310 | `edittext_empty_text_format` | 7 | 6.8s |  |
| 311 | `edittext_focus_selection` | 5 | 6.8s |  |
| 312 | `edittext_font_size` | 45 | 7.0s |  |
| 313 | `edittext_format_empty_font` | 8 | 6.7s |  |
| 314 | `edittext_get_char_index_at_point` | 4 | 28.5s |  |
| 315 | `edittext_get_line_index_at_point` | 2 | 27.2s |  |
| 316 | `edittext_get_line_index_of_char` | 76 | 7.8s |  |
| 317 | `edittext_getcharboundaries` | 172 | 7.4s |  |
| 318 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.3s |  |
| 319 | `edittext_getcharboundaries_scroll` | 85 | 5.2s |  |
| 320 | `edittext_getlinemetrics` | 146 | 5.6s |  |
| 321 | `edittext_html` | 3101 | 5.8s |  |
| 322 | `edittext_html_condensewhite` | 487 | 5.4s |  |
| 323 | `edittext_html_entity` | 4 | 5.7s |  |
| 324 | `edittext_html_font_size_swf12` | 267 | 5.4s |  |
| 325 | `edittext_html_font_size_swf13` | 273 | 5.1s |  |
| 326 | `edittext_html_roundtrip` | 17 | 5.2s |  |
| 327 | `edittext_ime_focus_lost` | 9 | 20.5s |  |
| 328 | `edittext_input_control` | 12 | 5.3s |  |
| 329 | `edittext_leading` | 9 | 5.6s |  |
| 330 | `edittext_letter_spacing` | 15 | 5.3s |  |
| 331 | `edittext_line_methods` | 294 | 6.7s |  |
| 332 | `edittext_line_metrics` | 11 | 22.4s |  |
| 333 | `edittext_margins` | 25 | 5.5s |  |
| 334 | `edittext_max_scroll_h_basic` | 475 | 5.5s |  |
| 335 | `edittext_max_scroll_v_basic` | 1000 | 5.6s |  |
| 336 | `edittext_mouse_selection` | 363 | 22.5s |  |
| 337 | `edittext_mousedown` | 3 | 5.8s |  |
| 338 | `edittext_mouseenabled` | 26 | 5.5s |  |
| 339 | `edittext_newline_character` | 22 | 5.4s |  |
| 340 | `edittext_newline_stripping` | 64 | 8.7s |  |
| 341 | `edittext_newlines` | 30 | 5.6s |  |
| 342 | `edittext_paragraph_methods` | 257 | 5.4s |  |
| 343 | `edittext_paste_events` | 8 | 5.6s |  |
| 344 | `edittext_paste_maxchars` | 4 | 5.4s |  |
| 345 | `edittext_paste_restrict` | 16 | 5.2s |  |
| 346 | `edittext_restrict` | 191 | 5.3s |  |
| 347 | `edittext_restrict_events` | 22 | 5.3s |  |
| 348 | `edittext_scrollh` | 10 | 5.3s |  |
| 349 | `edittext_selected_text` | 9 | 5.3s |  |
| 350 | `edittext_set_html_same` | 17 | 5.3s |  |
| 351 | `edittext_set_text_vs_html` | 9 | 5.3s |  |
| 352 | `edittext_stylesheet` | 536 | 5.6s |  |
| 353 | `edittext_stylesheet_custom_tag` | 76 | 5.5s |  |
| 354 | `edittext_stylesheet_display` | 272 | 5.6s |  |
| 355 | `edittext_underline` | 40 | 23.9s |  |
| 356 | `edittext_width_height` | 103 | 6.8s |  |
| 357 | `edittext_wordwrap_word` | 150 | 25.3s |  |
| 358 | `edittext_wrap_breaks` | 2375 | 7.0s |  |
| 359 | `element_format_clone` | 44 | 6.6s |  |
| 360 | `element_format_constructor_order` | 64 | 6.6s |  |
| 361 | `element_format_properties` | 235 | 7.3s |  |
| 362 | `empty_bounds` | 1 | 6.3s |  |
| 363 | `encode_uri_surrogate_pair_invalid` | 8 | 6.4s |  |
| 364 | `encode_uri_surrogate_pair_swf11` | 15 | 6.0s |  |
| 365 | `equals` | 512 | 10.3s |  |
| 366 | `error_geterrormessage` | 779 | 6.4s |  |
| 367 | `error_prototype` | 15 | 6.4s |  |
| 368 | `error_stack_trace` | 45 | 6.4s |  |
| 369 | `error_stack_trace_debug_swf17` | 0 | 24.9s |  |
| 370 | `error_stack_trace_debug_swf18` | 0 | 6.1s |  |
| 371 | `error_stack_trace_edge_cases` | 6 | 6.3s |  |
| 372 | `error_stack_trace_release_swf17` | 0 | 6.3s |  |
| 373 | `error_stack_trace_release_swf18` | 0 | 6.1s |  |
| 374 | `error_throwerror` | 103 | 6.4s |  |
| 375 | `error_tostring` | 29 | 6.3s |  |
| 376 | `error_tostring_more` | 86 | 6.4s |  |
| 377 | `es3_inheritance` | 31 | 6.4s |  |
| 378 | `es4_inheritance` | 30 | 6.4s |  |
| 379 | `es4_interfaces` | 30 | 6.4s |  |
| 380 | `es4_method_binding` | 8 | 6.4s |  |
| 381 | `es4_oop_prototypes` | 14 | 6.5s |  |
| 382 | `es4_protected_inheritance` | 6 | 6.4s |  |
| 383 | `escape` | 71 | 6.4s |  |
| 384 | `escape_multi_byte` | 45 | 6.5s |  |
| 385 | `event_bubbles` | 2 | 6.3s |  |
| 386 | `event_cancelable` | 2 | 6.2s |  |
| 387 | `event_clone` | 20 | 6.4s |  |
| 388 | `event_clone_error_redispatch` | 3 | 6.5s |  |
| 389 | `event_clone_on_redispatch` | 10 | 6.5s |  |
| 390 | `event_formattostring` | 31 | 6.4s |  |
| 391 | `event_isdefaultprevented` | 12 | 6.4s |  |
| 392 | `event_target_getter` | 5 | 2.3s |  |
| 393 | `event_target_set` | 9 | 23.6s |  |
| 394 | `event_type` | 1 | 6.5s |  |
| 395 | `event_valueof_tostring` | 18 | 6.6s |  |
| 396 | `eventdispatcher_dispatchevent` | 12 | 6.5s |  |
| 397 | `eventdispatcher_dispatchevent_cancel` | 20 | 25.9s |  |
| 398 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.6s |  |
| 399 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.7s |  |
| 400 | `eventdispatcher_dispatchevent_this` | 5 | 6.5s |  |
| 401 | `eventdispatcher_haseventlistener` | 25 | 6.6s |  |
| 402 | `eventdispatcher_interface_invoke` | 1 | 6.5s |  |
| 403 | `eventdispatcher_tostring` | 10 | 6.5s |  |
| 404 | `eventdispatcher_willtrigger` | 25 | 6.4s |  |
| 405 | `falsiness` | 30 | 6.5s |  |
| 406 | `fast_index_access` | 12 | 6.6s |  |
| 407 | `filefilter_properties` | 4 | 6.5s |  |
| 408 | `filereference_browse_cancel` | 3 | 6.5s |  |
| 409 | `filereference_browse_select` | 9 | 6.5s |  |
| 410 | `filereference_load` | 31 | 6.6s |  |
| 411 | `filereference_save` | 16 | 6.5s |  |
| 412 | `filereference_save_and_browse` | 42 | 6.6s |  |
| 413 | `filereference_save_and_load` | 22 | 6.6s |  |
| 414 | `filereference_uninitialized` | 8 | 6.5s |  |
| 415 | `filereferencelist_browse_cancel` | 6 | 6.5s |  |
| 416 | `filereferencelist_browse_select` | 7 | 6.5s |  |
| 417 | `filter_rewind` | 8 | 6.8s |  |
| 418 | `filters_array_holes` | 25 | 6.6s |  |
| 419 | `finddef` | 3 | 6.5s |  |
| 420 | `findprop_global_prototype` | 6 | 6.6s |  |
| 421 | `flash_media_video_constructor` | 156 | 7.3s |  |
| 422 | `flash_media_video_rotation_probe` | 27 | 6.6s |  |
| 423 | `flash_media_video_setter` | 40 | 7.0s |  |
| 424 | `flash_trace` | 17 | 6.7s |  |
| 425 | `flash_xml` | 29 | 6.5s |  |
| 426 | `flash_xml_cloneNode` | 22 | 6.5s |  |
| 427 | `flash_xml_namespace` | 109 | 6.5s |  |
| 428 | `flash_xml_removeNode` | 60 | 6.6s |  |
| 429 | `focus_events_code` | 161 | 25.7s |  |
| 430 | `focus_events_key_basic` | 132 | 25.7s |  |
| 431 | `focus_events_key_navigation` | 53 | 6.7s |  |
| 432 | `focus_events_key_same_object` | 26 | 6.5s |  |
| 433 | `focus_events_mixed_key_mouse` | 100 | 25.3s |  |
| 434 | `focus_events_mouse_basic` | 260 | 25.3s |  |
| 435 | `focus_events_mouse_focusable` | 112 | 25.0s |  |
| 436 | `focus_events_mouse_same_object` | 40 | 24.7s |  |
| 437 | `focus_remove` | 20 | 25.1s |  |
| 438 | `focus_root_movie` | 4 | 24.6s |  |
| 439 | `focus_stage` | 1 | 6.0s |  |
| 440 | `focusrect` | 18 | 6.7s |  |
| 441 | `focusrect_focuslost` | 9 | 6.1s |  |
| 442 | `focusrect_property` | 110 | 24.6s |  |
| 443 | `font_description_clone` | 14 | 6.0s |  |
| 444 | `font_embedded` | 24 | 6.6s |  |
| 445 | `font_enumeratefonts` | 41 | 6.9s |  |
| 446 | `font_enumeratefonts_filter` | 4 | 24.7s |  |
| 447 | `font_enumeratefonts_order` | 9 | 7.1s |  |
| 448 | `font_hasglyphs` | 40 | 6.7s |  |
| 449 | `font_registerfont` | 129 | 7.2s |  |
| 450 | `framelabel_constr` | 5 | 6.1s |  |
| 451 | `function_call` | 12 | 6.0s |  |
| 452 | `function_call_arguments` | 46 | 6.2s |  |
| 453 | `function_call_arguments_enumerate` | 5 | 6.0s |  |
| 454 | `function_call_coercion` | 108 | 6.5s |  |
| 455 | `function_call_default` | 6 | 6.0s |  |
| 456 | `function_call_rest` | 22 | 6.0s |  |
| 457 | `function_call_types` | 3 | 6.0s |  |
| 458 | `function_call_via_apply` | 11 | 6.0s |  |
| 459 | `function_call_via_call` | 3 | 6.0s |  |
| 460 | `function_display_anonymous` | 7 | 2.0s |  |
| 461 | `function_length` | 6 | 6.0s |  |
| 462 | `function_object` | 2 | 6.0s |  |
| 463 | `function_proto` | 5 | 6.0s |  |
| 464 | `function_proto_created` | 61 | 6.0s |  |
| 465 | `function_to_locale_string` | 4 | 5.9s |  |
| 466 | `function_to_string` | 4 | 5.9s |  |
| 467 | `function_type` | 6 | 5.9s |  |
| 468 | `function_unbound_this` | 51 | 6.0s |  |
| 469 | `function_value_of` | 4 | 5.9s |  |
| 470 | `game_input` | 4 | 5.9s |  |
| 471 | `generate_random_bytes` | 3 | 5.9s |  |
| 472 | `get_definition_by_name` | 11 | 6.1s |  |
| 473 | `get_qualified_class_name` | 20 | 6.1s |  |
| 474 | `get_qualified_super_class_name` | 18 | 6.1s |  |
| 475 | `get_slot_edge_cases` | 1 | 24.2s |  |
| 476 | `get_timer` | 2 | 6.1s |  |
| 477 | `getglobalslot` | 1 | 6.0s |  |
| 478 | `getouterscope` | 8 | 6.0s |  |
| 479 | `getouterscope_two_classobjects` | 13 | 6.0s |  |
| 480 | `getter_different_namespace_setter` | 2 | 5.8s |  |
| 481 | `glow_filter` | 127 | 6.2s |  |
| 482 | `goto_button_nested_framescript` | 28 | 24.8s |  |
| 483 | `goto_in_constructframe` | 12 | 24.8s |  |
| 484 | `goto_in_scene_last_frame` | 2 | 24.3s |  |
| 485 | `goto_methods` | 56 | 6.2s |  |
| 486 | `goto_methods_swfver10` | 8 | 6.0s |  |
| 487 | `goto_nested_construct_sibling` | 18 | 6.5s |  |
| 488 | `goto_nested_framescript` | 9 | 6.2s |  |
| 489 | `goto_on_orphan` | 15 | 6.2s |  |
| 490 | `gradient_bevel_filter` | 206 | 6.1s |  |
| 491 | `gradient_glow_filter` | 206 | 6.0s |  |
| 492 | `graphic_linkage` | 9 | 6.2s |  |
| 493 | `graphics_bad_direct_commands` | 5 | 6.5s |  |
| 494 | `graphics_bitmap_fill` | 0 | 26.5s |  |
| 495 | `graphics_bitmaps` | 0 | 6.4s |  |
| 496 | `graphics_direct_commands` | 0 | 6.2s |  |
| 497 | `graphics_draw_triangles` | 98 | 25.6s |  |
| 498 | `graphics_gradients` | 0 | 6.1s |  |
| 499 | `graphics_gradients_nulls` | 0 | 6.1s |  |
| 500 | `graphics_path` | 56 | 6.1s |  |
| 501 | `graphics_round_rects` | 0 | 6.1s |  |
| 502 | `graphics_simple_shapes` | 0 | 6.1s |  |
| 503 | `greaterequals` | 512 | 9.0s |  |
| 504 | `greaterthan` | 512 | 9.0s |  |
| 505 | `has_own_property` | 102 | 6.5s |  |
| 506 | `hasownproperty_namespaces` | 2 | 6.1s |  |
| 507 | `hello_world` | 1 | 6.0s |  |
| 508 | `hittest_morph` | 30 | 6.2s |  |
| 509 | `if_eq` | 10 | 6.7s |  |
| 510 | `if_gt` | 1 | 5.3s |  |
| 511 | `if_gte` | 10 | 1.9s |  |
| 512 | `if_lt` | 1 | 0.4s |  |
| 513 | `if_lte` | 10 | 5.1s |  |
| 514 | `if_ne` | 7 | 1.8s |  |
| 515 | `if_stricteq` | 6 | 5.2s |  |
| 516 | `if_strictne` | 11 | 5.4s |  |
| 517 | `ime_linux_dead_keys` | 10 | 22.3s |  |
| 518 | `in` | 102 | 5.8s |  |
| 519 | `inclocal` | 46 | 5.3s |  |
| 520 | `inclocal_i` | 46 | 5.7s |  |
| 521 | `increment` | 46 | 5.2s |  |
| 522 | `increment_i` | 46 | 5.2s |  |
| 523 | `indexing_delete` | 75 | 5.6s |  |
| 524 | `instanceof` | 58 | 5.4s |  |
| 525 | `instantiate_root_character` | 4 | 5.6s |  |
| 526 | `instantiation_on_enter_frame` | 7 | 21.9s |  |
| 527 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.5s |  |
| 528 | `int_constr` | 92 | 5.7s |  |
| 529 | `int_edge_cases` | 19 | 6.0s |  |
| 530 | `int_instanceof` | 3 | 5.3s |  |
| 531 | `int_tofixed` | 1215 | 5.4s |  |
| 532 | `int_tostring` | 3375 | 5.6s |  |
| 533 | `interactiveobject_enabled` | 25 | 5.3s |  |
| 534 | `interface_namespaces` | 78 | 5.3s |  |
| 535 | `invalid_utf8` | 12 | 5.6s |  |
| 536 | `is_finite` | 46 | 5.2s |  |
| 537 | `is_nan` | 46 | 5.1s |  |
| 538 | `is_prototype_of` | 12 | 5.2s |  |
| 539 | `issue_10221` | 2 | 5.3s |  |
| 540 | `issue_13780` | 12 | 5.2s |  |
| 541 | `issue_14901` | 1 | 5.1s |  |
| 542 | `issue_17675_edittext_paste_maxchars` | 1 | 5.4s |  |
| 543 | `issue_5292` | 5 | 5.7s |  |
| 544 | `issue_8630` | 2 | 21.0s |  |
| 545 | `issue_8630_placeremoveplace` | 15 | 5.4s |  |
| 546 | `issue_8630_placeremoveplace_scriptremove` | 16 | 5.8s |  |
| 547 | `issue_8630_scriptremove` | 11 | 43.0s |  |
| 548 | `istype` | 24 | 6.8s |  |
| 549 | `istypelate` | 58 | 7.0s |  |
| 550 | `istypelate_coerce` | 198 | 7.6s |  |
| 551 | `jpeg_loader_context` | 6 | 25.6s |  |
| 552 | `json_errors` | 9 | 25.8s |  |
| 553 | `json_parse` | 21 | 6.6s |  |
| 554 | `json_stringify` | 12 | 6.9s |  |
| 555 | `json_stringify_function` | 12 | 6.6s |  |
| 556 | `json_stringify_order` | 1 | 6.6s |  |
| 557 | `json_version_gated` | 1 | 6.6s |  |
| 558 | `key_input_80percent` | 1812 | 6.9s |  |
| 559 | `key_input_location` | 126 | 6.8s |  |
| 560 | `key_input_numpad` | 384 | 6.6s |  |
| 561 | `lazyinit` | 17 | 6.6s |  |
| 562 | `lessequals` | 512 | 10.6s |  |
| 563 | `lessthan` | 512 | 10.5s |  |
| 564 | `loader_bitmap_transparency` | 14 | 6.8s |  |
| 565 | `loader_bytes_unknown_content` | 14 | 6.7s |  |
| 566 | `loader_child_getdefinition` | 5 | 6.9s |  |
| 567 | `loader_duplicate_coerce` | 3 | 6.8s |  |
| 568 | `loader_duplicate_coerce_new_domain` | 4 | 6.8s |  |
| 569 | `loader_error_in_root_ctor` | 4 | 6.8s |  |
| 570 | `loader_events` | 92 | 7.1s |  |
| 571 | `loader_image` | 8 | 6.8s |  |
| 572 | `loader_jpegxr` | 2 | 26.0s |  |
| 573 | `loader_jpegxr_alpha` | 1 | 25.7s |  |
| 574 | `loader_loadbytes_events` | 30 | 7.1s |  |
| 575 | `loader_loadbytes_invalid_png` | 4 | 6.7s |  |
| 576 | `loader_loadbytes_url` | 12 | 6.9s |  |
| 577 | `loader_loaderurl` | 6 | 7.1s |  |
| 578 | `loader_method` | 85 | 6.7s |  |
| 579 | `loader_noninteractive_try_click_root` | 5 | 26.0s |  |
| 580 | `loader_reuse` | 38 | 6.8s |  |
| 581 | `loader_unknown_content` | 24 | 42.8s |  |
| 582 | `loader_visibility_interactive` | 1 | 25.7s |  |
| 583 | `loaderinfo_events` | 7 | 6.4s |  |
| 584 | `loaderinfo_loadurl` | 12 | 25.7s |  |
| 585 | `loaderinfo_more` | 6 | 6.8s |  |
| 586 | `loaderinfo_properties` | 18 | 6.5s |  |
| 587 | `loaderinfo_properties_not_loaded` | 23 | 6.6s |  |
| 588 | `loaderinfo_quine` | 1005 | 6.4s |  |
| 589 | `loaderinfo_root` | 10 | 6.4s |  |
| 590 | `loaderinfo_root_allows` | 2 | 6.4s |  |
| 591 | `localconnection_send` | 4 | 6.5s |  |
| 592 | `lshift` | 1058 | 18.9s |  |
| 593 | `mask_reapply` | 1 | 6.5s |  |
| 594 | `math` | 497 | 6.7s |  |
| 595 | `matrix3d` | 57 | 7.2s |  |
| 596 | `matrix3d_compose` | 34 | 6.6s |  |
| 597 | `matrix3d_invert` | 18 | 6.5s |  |
| 598 | `method_without_body` | 3 | 25.5s |  |
| 599 | `missing_external_interface` | 10 | 6.5s |  |
| 600 | `modulo` | 1058 | 18.9s |  |
| 601 | `morph_shape` | 2 | 25.9s |  |
| 602 | `mouse_children` | 192 | 25.7s |  |
| 603 | `mouse_click_events` | 90 | 25.6s |  |
| 604 | `mouse_double_click_events` | 188 | 6.6s |  |
| 605 | `mouse_empty_parent` | 4 | 6.5s |  |
| 606 | `mouse_over_while_dragging` | 3 | 6.7s |  |
| 607 | `mouse_pick_button_mode` | 2 | 6.6s |  |
| 608 | `mouse_pick_dobj_mask` | 4 | 6.6s |  |
| 609 | `mouse_pick_masking` | 7 | 25.6s |  |
| 610 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 25.5s |  |
| 611 | `mouse_pick_non_interactive_dobj_mask` | 3 | 6.5s |  |
| 612 | `mouse_pick_text` | 8 | 6.7s |  |
| 613 | `mouse_sibling` | 8 | 6.5s |  |
| 614 | `mouse_wheel_events` | 36 | 26.7s |  |
| 615 | `mouseevent_constr` | 66 | 6.4s |  |
| 616 | `mouseevent_stagexy` | 35 | 6.5s |  |
| 617 | `mouseevent_valueof_tostring` | 28 | 24.3s |  |
| 618 | `movieclip_addframescript` | 3 | 26.2s |  |
| 619 | `movieclip_child_property` | 16 | 6.7s |  |
| 620 | `movieclip_constr` | 21 | 6.6s |  |
| 621 | `movieclip_currentlabels` | 17 | 26.2s |  |
| 622 | `movieclip_currentlabels_dupes1` | 46 | 26.1s |  |
| 623 | `movieclip_currentlabels_dupes2` | 30 | 6.7s |  |
| 624 | `movieclip_currentlabels_dupes3` | 67 | 6.6s |  |
| 625 | `movieclip_currentscene` | 12 | 26.0s |  |
| 626 | `movieclip_dispatchevent` | 430 | 6.8s |  |
| 627 | `movieclip_dispatchevent_cancel` | 102 | 6.7s |  |
| 628 | `movieclip_dispatchevent_handlerorder` | 251 | 6.7s |  |
| 629 | `movieclip_dispatchevent_selfadd` | 80 | 6.7s |  |
| 630 | `movieclip_dispatchevent_target` | 899 | 6.8s |  |
| 631 | `movieclip_displayevents` | 96 | 25.9s |  |
| 632 | `movieclip_displayevents_clickgoto` | 676 | 26.6s |  |
| 633 | `movieclip_displayevents_clickgoto2` | 2001 | 7.2s |  |
| 634 | `movieclip_displayevents_clickplay` | 575 | 6.9s |  |
| 635 | `movieclip_displayevents_clicksymbol` | 562 | 7.0s |  |
| 636 | `movieclip_displayevents_constructframegoto` | 140 | 7.1s |  |
| 637 | `movieclip_displayevents_constructframeplay` | 50 | 7.0s |  |
| 638 | `movieclip_displayevents_constructframesymbol` | 144 | 7.0s |  |
| 639 | `movieclip_displayevents_dblhandler` | 21 | 7.0s |  |
| 640 | `movieclip_displayevents_enterframegoto` | 149 | 7.0s |  |
| 641 | `movieclip_displayevents_enterframeplay` | 48 | 6.7s |  |
| 642 | `movieclip_displayevents_enterframesymbol` | 149 | 25.9s |  |
| 643 | `movieclip_displayevents_exitframegoto` | 106 | 6.7s |  |
| 644 | `movieclip_displayevents_exitframeplay` | 44 | 6.9s |  |
| 645 | `movieclip_displayevents_exitframesymbol` | 135 | 7.0s |  |
| 646 | `movieclip_displayevents_looping` | 63 | 26.1s |  |
| 647 | `movieclip_displayevents_stopped` | 113 | 7.1s |  |
| 648 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 649 | `movieclip_displayevents_timeline` | 128 | 26.4s |  |
| 650 | `movieclip_drawrect` | 54 | 6.6s |  |
| 651 | `movieclip_frameconstruct_skipped` | 9 | 6.9s |  |
| 652 | `movieclip_goto_during_frame_script` | 15 | 6.8s |  |
| 653 | `movieclip_goto_overwrite` | 14 | 25.8s |  |
| 654 | `movieclip_goto_scene_last_frame_int` | 1 | 26.2s |  |
| 655 | `movieclip_goto_scene_last_frame_label` | 1 | 6.5s |  |
| 656 | `movieclip_gotoandplay` | 15 | 25.8s |  |
| 657 | `movieclip_gotoandstop` | 13 | 25.8s |  |
| 658 | `movieclip_gotoandstop_children` | 4 | 18.6s |  |
| 659 | `movieclip_gotoandstop_framescripts1` | 4 | 5.1s |  |
| 660 | `movieclip_gotoandstop_framescripts2` | 4 | 1.8s |  |
| 661 | `movieclip_gotoandstop_framescripts_self` | 7 | 19.8s |  |
| 662 | `movieclip_gotoandstop_queueing` | 12 | 19.8s |  |
| 663 | `movieclip_hittest` | 67 | 5.2s |  |
| 664 | `movieclip_next_frame` | 2 | 19.8s |  |
| 665 | `movieclip_next_scene` | 6 | 19.6s |  |
| 666 | `movieclip_play` | 3 | 5.0s |  |
| 667 | `movieclip_prev_frame` | 3 | 4.8s |  |
| 668 | `movieclip_prev_scene` | 7 | 5.1s |  |
| 669 | `movieclip_properties` | 79 | 19.8s |  |
| 670 | `movieclip_queued_noop_goto_swf10` | 9 | 5.1s |  |
| 671 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 672 | `movieclip_scenes` | 11 | 5.0s |  |
| 673 | `movieclip_soundtransform` | 831 | 21.4s |  |
| 674 | `movieclip_stop` | 1 | 19.5s |  |
| 675 | `movieclip_super_is_symbol` | 20 | 5.3s |  |
| 676 | `movieclip_symbol_constr` | 8 | 5.2s |  |
| 677 | `movieclip_text_mousedown` | 1 | 5.1s |  |
| 678 | `movieclip_willtrigger` | 5 | 5.3s |  |
| 679 | `multiply` | 1058 | 13.9s |  |
| 680 | `namespace_constr` | 253 | 5.3s |  |
| 681 | `namespace_constr_args` | 1 | 5.0s |  |
| 682 | `namespace_enumeration_order` | 7 | 19.7s |  |
| 683 | `nan_scale` | 9 | 5.0s |  |
| 684 | `navigateToURL_target_normalize` | 107 | 21.2s |  |
| 685 | `negate` | 30 | 5.1s |  |
| 686 | `negative_volume_panned` | 0 | 5.2s |  |
| 687 | `nested_iteration` | 11 | 5.1s |  |
| 688 | `net_getClassByAlias` | 3 | 5.0s |  |
| 689 | `net_navigateToURL` | 57 | 5.1s |  |
| 690 | `net_stream_play_options` | 6 | 5.1s |  |
| 691 | `netconnection_close` | 55 | 5.1s |  |
| 692 | `netconnection_properties` | 78 | 5.1s |  |
| 693 | `netconnection_send_remote` | 50 | 5.3s |  |
| 694 | `netconnection_serialize_arrays` | 6 | 5.2s |  |
| 695 | `netfilterevent` | 10 | 5.1s |  |
| 696 | `netstream_client` | 10 | 5.2s |  |
| 697 | `netstream_connect` | 7 | 5.0s |  |
| 698 | `newactivation_in_script_init` | 3 | 6.8s |  |
| 699 | `newclass_mismatched` | 4 | 6.6s |  |
| 700 | `newclass_twice` | 3 | 6.5s |  |
| 701 | `nonconflicting_declarations` | 0 | 6.7s |  |
| 702 | `null_void_types` | 8 | 6.7s |  |
| 703 | `number_autoconv` | 21 | 6.7s |  |
| 704 | `number_autoconv_amf` | 132 | 6.6s |  |
| 705 | `number_autoconv_array_sort_32bit` | 1 | 6.5s |  |
| 706 | `number_constr` | 58 | 6.7s |  |
| 707 | `number_toexponential` | 378 | 6.7s |  |
| 708 | `number_toexponential2` | 35 | 6.5s |  |
| 709 | `number_tofixed` | 378 | 6.5s |  |
| 710 | `number_toprecision` | 350 | 6.9s |  |
| 711 | `obfuscated_class_names` | 3 | 6.7s |  |
| 712 | `object_enumeration` | 10 | 6.8s |  |
| 713 | `object_prototype` | 4 | 6.7s |  |
| 714 | `object_to_locale_string` | 2 | 6.7s |  |
| 715 | `object_to_string` | 2 | 6.6s |  |
| 716 | `object_value_of` | 2 | 2.2s |  |
| 717 | `op_coerce` | 54 | 6.7s |  |
| 718 | `op_coerce_x` | 54 | 6.7s |  |
| 719 | `op_escxattr` | 2 | 6.7s |  |
| 720 | `op_escxelem` | 2 | 6.6s |  |
| 721 | `op_lookupswitch` | 4 | 6.6s |  |
| 722 | `optimize_coerce` | 1 | 6.5s |  |
| 723 | `orphan_movie_complex` | 80 | 7.1s |  |
| 724 | `orphan_movie_reorder` | 111 | 26.1s |  |
| 725 | `package_namespace` | 7 | 6.4s |  |
| 726 | `param_default_value_has_zero_cpool_index` | 1 | 6.5s |  |
| 727 | `parent_early_access_child` | 16 | 25.7s |  |
| 728 | `parse_float` | 81 | 6.8s |  |
| 729 | `parse_float_swf10` | 81 | 6.5s |  |
| 730 | `parse_int` | 135 | 7.2s |  |
| 731 | `perspective_projection` | 1443 | 41.8s |  |
| 732 | `perspective_projection_basic` | 40 | 24.6s |  |
| 733 | `pixelbender_ceil` | 77 | 6.5s |  |
| 734 | `pixelbender_conditional` | 138 | 6.7s |  |
| 735 | `pixelbender_conversions` | 270 | 6.7s |  |
| 736 | `pixelbender_dithering` | 8 | 29.2s |  |
| 737 | `pixelbender_div` | 36 | 6.5s |  |
| 738 | `pixelbender_effect_BlurredFocus` | 0 | 32.5s |  |
| 739 | `pixelbender_effect_glassDisplace` | 0 | 11.9s |  |
| 740 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 28.1s |  |
| 741 | `pixelbender_effect_smudge` | 0 | 9.6s |  |
| 742 | `pixelbender_effect_tintype` | 0 | 8.8s |  |
| 743 | `pixelbender_effect_twirl` | 0 | 10.1s |  |
| 744 | `pixelbender_eof` | 7 | 6.4s |  |
| 745 | `pixelbender_images` | 0 | 8.4s |  |
| 746 | `pixelbender_input` | 103 | 25.4s |  |
| 747 | `pixelbender_logicalnot` | 20 | 6.3s |  |
| 748 | `pixelbender_malformed_data` | 190 | 25.4s |  |
| 749 | `pixelbender_multiple_out_params` | 1 | 6.3s |  |
| 750 | `pixelbender_no_out_param` | 6 | 6.3s |  |
| 751 | `pixelbender_outputs` | 13 | 6.5s |  |
| 752 | `pixelbender_padding_bytes` | 22 | 6.4s |  |
| 753 | `pixelbender_param_qualifier` | 512 | 6.5s |  |
| 754 | `pixelbender_parameters` | 1563 | 6.7s |  |
| 755 | `pixelbender_parameters_bool` | 240 | 6.6s |  |
| 756 | `pixelbender_parameters_int_vs_bool` | 54 | 6.5s |  |
| 757 | `pixelbender_parse_errors` | 6 | 6.4s |  |
| 758 | `pixelbender_rsqrt` | 24 | 6.5s |  |
| 759 | `pixelbender_select_kinds` | 8 | 6.5s |  |
| 760 | `pixelbender_shaderdata` | 49 | 6.4s |  |
| 761 | `pixelbender_shaderdata_setter` | 99 | 6.7s |  |
| 762 | `pixelbender_sign` | 60 | 6.5s |  |
| 763 | `pixelbender_vector_output` | 11 | 6.5s |  |
| 764 | `place_and_lookup/swf10` | 33 | 6.4s |  |
| 765 | `place_and_lookup/swf9` | 33 | 0.6s |  |
| 766 | `place_multiple` | 17 | 24.6s |  |
| 767 | `place_object_replace` | 9 | 6.5s |  |
| 768 | `place_object_replace_2` | 24 | 6.6s |  |
| 769 | `place_object_same_depth_frame` | 1 | 6.4s |  |
| 770 | `point` | 132 | 6.9s |  |
| 771 | `primitive_edge_cases` | 1 | 6.4s |  |
| 772 | `primitive_toString` | 277 | 24.1s |  |
| 773 | `primitive_valueOf` | 285 | 6.4s |  |
| 774 | `print_job_options` | 3 | 25.5s |  |
| 775 | `property_is_enumerable` | 114 | 7.4s |  |
| 776 | `property_is_enumerable_reset` | 23 | 6.6s |  |
| 777 | `property_priority` | 22 | 6.9s |  |
| 778 | `property_priority_chained` | 4 | 6.4s |  |
| 779 | `property_priority_definition_names_order` | 2 | 6.7s |  |
| 780 | `property_priority_three_level` | 6 | 25.8s |  |
| 781 | `propertyisenumerable_namespaces` | 6 | 6.5s |  |
| 782 | `prototype_set_null` | 7 | 6.4s |  |
| 783 | `proxy_callproperty` | 24 | 6.5s |  |
| 784 | `proxy_deleteproperty` | 64 | 6.5s |  |
| 785 | `proxy_enumeration` | 34 | 6.5s |  |
| 786 | `proxy_getproperty` | 77 | 6.6s |  |
| 787 | `proxy_hasownproperty` | 8 | 6.5s |  |
| 788 | `proxy_hasproperty` | 32 | 6.6s |  |
| 789 | `proxy_not_overridden` | 54 | 6.5s |  |
| 790 | `proxy_serialize` | 9 | 6.5s |  |
| 791 | `proxy_setproperty` | 42 | 6.5s |  |
| 792 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.5s |  |
| 793 | `qname_constr` | 32 | 6.5s |  |
| 794 | `qname_constr_namespace` | 24 | 6.5s |  |
| 795 | `qname_enumeration` | 9 | 6.6s |  |
| 796 | `qname_indexing` | 23 | 6.5s |  |
| 797 | `qname_tostring` | 25 | 6.6s |  |
| 798 | `qname_valueof` | 29 | 6.6s |  |
| 799 | `rectangle` | 1094 | 7.3s |  |
| 800 | `regexp_constr` | 148 | 6.7s |  |
| 801 | `regexp_exec` | 19 | 6.6s |  |
| 802 | `regexp_extended` | 47 | 6.6s |  |
| 803 | `regexp_multiargs` | 1 | 6.4s |  |
| 804 | `regexp_test` | 27 | 6.5s |  |
| 805 | `regexp_toString` | 10 | 6.5s |  |
| 806 | `register_script_refresh` | 35 | 26.1s |  |
| 807 | `remove_child_clear_field` | 88 | 6.9s |  |
| 808 | `remove_dobj` | 3 | 6.5s |  |
| 809 | `resolve_order` | 4 | 6.5s |  |
| 810 | `responder_null_callbacks` | 1 | 6.5s |  |
| 811 | `rng` | 1 | 7.8s |  |
| 812 | `rootless` | 42 | 6.8s |  |
| 813 | `rshift` | 1058 | 36.2s |  |
| 814 | `rtqname_not_namespace` | 12 | 6.6s |  |
| 815 | `sandbox_type_inherited` | 2 | 7.1s |  |
| 816 | `sandbox_type_local_file` | 1 | 25.8s |  |
| 817 | `sandbox_type_local_network` | 1 | 6.2s |  |
| 818 | `scene_constr` | 8 | 6.6s |  |
| 819 | `scopes_dont_cache/order-1` | 1 | 25.1s |  |
| 820 | `scopes_dont_cache/order-2` | 1 | 0.4s |  |
| 821 | `security_domain_current` | 2 | 6.4s |  |
| 822 | `selection` | 239 | 6.9s |  |
| 823 | `set_local_0` | 31 | 6.5s |  |
| 824 | `set_property_is_enumerable` | 85 | 6.9s |  |
| 825 | `shaderparameter_value` | 4 | 6.5s |  |
| 826 | `shape_drawrect` | 54 | 6.4s |  |
| 827 | `shared_object_no_root` | 3 | 6.3s |  |
| 828 | `simplebutton_added_to_stage` | 45 | 24.9s |  |
| 829 | `simplebutton_childevents` | 86 | 25.4s |  |
| 830 | `simplebutton_childevents_nested` | 54 | 6.7s |  |
| 831 | `simplebutton_childevents_sprite` | 13 | 6.5s |  |
| 832 | `simplebutton_childprops` | 144 | 6.6s |  |
| 833 | `simplebutton_childshuffle` | 23 | 6.3s |  |
| 834 | `simplebutton_constr` | 36 | 6.6s |  |
| 835 | `simplebutton_constr_childevents` | 48 | 6.7s |  |
| 836 | `simplebutton_constr_params` | 42 | 6.5s |  |
| 837 | `simplebutton_mouseenabled` | 26 | 6.4s |  |
| 838 | `simplebutton_multi_children` | 19 | 6.6s |  |
| 839 | `simplebutton_structure` | 27 | 6.6s |  |
| 840 | `simplebutton_symbolclass` | 68 | 6.8s |  |
| 841 | `slot_disp_id_shared_numbering` | 1 | 24.9s |  |
| 842 | `slots_force_autoassigned` | 1 | 6.6s |  |
| 843 | `socket_after_disconnect` | 1 | 6.7s |  |
| 844 | `socket_close` | 2 | 6.5s |  |
| 845 | `socket_connect` | 4 | 6.5s |  |
| 846 | `socket_errors` | 56 | 42.8s |  |
| 847 | `socket_read_big` | 48 | 6.7s |  |
| 848 | `socket_read_little` | 48 | 2.2s |  |
| 849 | `socket_read_write_object` | 8 | 6.5s |  |
| 850 | `socket_write_big` | 15 | 6.8s |  |
| 851 | `socket_write_little` | 14 | 6.5s |  |
| 852 | `sound_embeddedprops` | 26 | 6.6s |  |
| 853 | `sound_play` | 19 | 6.7s |  |
| 854 | `sound_valueof` | 33 | 6.5s |  |
| 855 | `soundchannel_soundtransform` | 835 | 27.7s |  |
| 856 | `soundchannel_soundtransform_exists` | 5 | 25.6s |  |
| 857 | `soundchannel_stop` | 8 | 26.2s |  |
| 858 | `soundmixer_buffertime` | 5 | 6.6s |  |
| 859 | `soundmixer_stopall` | 6 | 27.0s |  |
| 860 | `soundtransform` | 442 | 13.0s |  |
| 861 | `space_justifier_clone` | 12 | 6.8s |  |
| 862 | `sprite_with_frames` | 0 | 26.9s |  |
| 863 | `stage3d_agal_cross_product` | 0 | 9.2s |  |
| 864 | `stage3d_agal_upload_errors` | 66 | 9.4s |  |
| 865 | `stage3d_bitmap` | 0 | 31.8s |  |
| 866 | `stage3d_blend` | 81 | 28.2s |  |
| 867 | `stage3d_context3d_string_args` | 158 | 7.7s |  |
| 868 | `stage3d_errors` | 7 | 6.7s |  |
| 869 | `stage3d_errors_atf` | 3 | 8.0s |  |
| 870 | `stage3d_errors_swf_29` | 6 | 6.7s |  |
| 871 | `stage3d_float1_index` | 0 | 28.7s |  |
| 872 | `stage3d_fractal` | 0 | 29.0s |  |
| 873 | `stage3d_ignore_sampler_override` | 0 | 29.6s |  |
| 874 | `stage3d_multistage_triangle` | 3 | 9.6s |  |
| 875 | `stage3d_program_constants_bytearray_be` | 0 | 31.5s |  |
| 876 | `stage3d_program_constants_bytearray_le` | 0 | 10.4s |  |
| 877 | `stage3d_program_constants_invalid_input` | 21 | 8.0s |  |
| 878 | `stage3d_raytrace` | 0 | 34.7s |  |
| 879 | `stage3d_rotating_cube` | 0 | 10.5s |  |
| 880 | `stage3d_sampler` | 0 | 26.7s |  |
| 881 | `stage3d_sampler_partial_upload` | 0 | 9.3s |  |
| 882 | `stage3d_stencil` | 0 | 28.9s |  |
| 883 | `stage3d_texture` | 0 | 14.3s |  |
| 884 | `stage3d_texture_bytearray` | 0 | 10.3s |  |
| 885 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.8s |  |
| 886 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.9s |  |
| 887 | `stage3d_triangle` | 0 | 9.1s |  |
| 888 | `stage3d_triangle_bytes4` | 0 | 9.1s |  |
| 889 | `stage3d_triangle_float1` | 0 | 9.0s |  |
| 890 | `stage3d_triangle_index_upload` | 0 | 9.0s |  |
| 891 | `stage3d_x_y` | 22 | 6.5s |  |
| 892 | `stage_access` | 10 | 6.5s |  |
| 893 | `stage_displayobject_properties` | 24 | 6.4s |  |
| 894 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.5s |  |
| 895 | `stage_framerate_nan` | 7 | 25.9s |  |
| 896 | `stage_framerate_negative` | 6 | 6.6s |  |
| 897 | `stage_framerate_zero` | 6 | 6.6s |  |
| 898 | `stage_invalidate` | 38 | 6.7s |  |
| 899 | `stage_loaderinfo_properties` | 24 | 26.2s |  |
| 900 | `stage_mousechildren` | 2 | 6.4s |  |
| 901 | `stage_mouseenabled` | 15 | 6.4s |  |
| 902 | `stage_overriden_setters` | 31 | 6.7s |  |
| 903 | `stage_properties` | 30 | 6.4s |  |
| 904 | `stage_properties2` | 213 | 6.7s |  |
| 905 | `stage_stage3Ds_vector` | 1 | 25.2s |  |
| 906 | `static_length` | 24 | 6.5s |  |
| 907 | `static_text` | 3 | 6.6s |  |
| 908 | `static_var_with_this_in_ctor` | 2 | 6.4s |  |
| 909 | `statictext_text` | 8 | 6.6s |  |
| 910 | `stored_properties` | 11 | 6.4s |  |
| 911 | `strict_equality` | 34 | 6.5s |  |
| 912 | `string_call` | 13 | 6.4s |  |
| 913 | `string_case` | 23 | 6.4s |  |
| 914 | `string_char_at` | 27 | 6.4s |  |
| 915 | `string_char_code_at` | 28 | 6.3s |  |
| 916 | `string_concat_fromcharcode` | 37 | 6.3s |  |
| 917 | `string_constr` | 25 | 6.5s |  |
| 918 | `string_indexof_lastindexof` | 87 | 6.7s |  |
| 919 | `string_length` | 16 | 24.0s |  |
| 920 | `string_locale_compare` | 39 | 6.9s |  |
| 921 | `string_match` | 51 | 26.4s |  |
| 922 | `string_relational_compare` | 4 | 6.7s |  |
| 923 | `string_replace` | 51 | 6.8s |  |
| 924 | `string_search` | 41 | 6.7s |  |
| 925 | `string_slice_substr_substring` | 170 | 7.9s |  |
| 926 | `string_split` | 29 | 7.0s |  |
| 927 | `string_substr_negative` | 21 | 6.8s |  |
| 928 | `string_substr_weird` | 182 | 6.6s |  |
| 929 | `stylesheet` | 221 | 7.2s |  |
| 930 | `stylesheet_parse_color` | 69 | 6.7s |  |
| 931 | `stylesheet_transform` | 307 | 7.0s |  |
| 932 | `subclass_superclass_linked_symbol` | 4 | 7.2s |  |
| 933 | `subtract` | 1058 | 18.1s |  |
| 934 | `super_get_call` | 12 | 6.6s |  |
| 935 | `supercall_two_classobjects` | 2 | 6.6s |  |
| 936 | `supercalls_weird` | 2 | 6.6s |  |
| 937 | `superinterface_call` | 20 | 6.7s |  |
| 938 | `superinterface_instanceof` | 18 | 6.6s |  |
| 939 | `swf8` | 1 | 6.5s |  |
| 940 | `swf_10_queued_goto_scripts_construct` | 52 | 25.8s |  |
| 941 | `swf_9_goto_in_enter_frame` | 17 | 6.6s |  |
| 942 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.6s |  |
| 943 | `swf_9_queued_goto_scripts` | 6 | 25.5s |  |
| 944 | `swf_9_queued_goto_scripts_construct` | 28 | 0.7s |  |
| 945 | `swf_9_versioning` | 2 | 6.5s |  |
| 946 | `swf_wrong_frame_count` | 38 | 6.9s |  |
| 947 | `swf_wrong_frame_count_isplaying` | 22 | 25.5s |  |
| 948 | `symbol_class_binary_data` | 8 | 6.7s |  |
| 949 | `symbol_class_conflict` | 4 | 6.8s |  |
| 950 | `symbol_class_root_not_zero` | 1 | 6.5s |  |
| 951 | `symbolclass_invalid_utf8` | 2 | 6.5s |  |
| 952 | `system_exit` | 3 | 6.6s |  |
| 953 | `system_setclipboard_null` | 1 | 6.5s |  |
| 954 | `tab_ordering_arrows` | 998 | 26.9s |  |
| 955 | `tab_ordering_automatic_advanced` | 184 | 7.3s |  |
| 956 | `tab_ordering_automatic_basic` | 45 | 46.7s |  |
| 957 | `tab_ordering_children` | 116 | 6.6s |  |
| 958 | `tab_ordering_custom_basic` | 34 | 6.5s |  |
| 959 | `tab_ordering_stage_tab_children` | 32 | 6.5s |  |
| 960 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.4s |  |
| 961 | `tab_ordering_tabbable` | 47 | 6.6s |  |
| 962 | `tabstop_properties` | 105 | 6.8s |  |
| 963 | `text_element_basic` | 34 | 6.6s |  |
| 964 | `text_engine_fontdescription` | 27 | 6.6s |  |
| 965 | `text_engine_groupelement` | 64 | 7.5s |  |
| 966 | `text_run` | 7 | 6.4s |  |
| 967 | `textblock_createline_errors` | 23 | 6.7s |  |
| 968 | `textblock_createline_fte` | 9 | 27.6s |  |
| 969 | `textblock_properties` | 118 | 6.9s |  |
| 970 | `textbox_click` | 37 | 27.3s |  |
| 971 | `textfield_event` | 66 | 7.0s |  |
| 972 | `textfield_focusin_event` | 9 | 6.4s |  |
| 973 | `textfield_input_dead_keys_windows` | 15 | 6.5s |  |
| 974 | `textfield_unload` | 39 | 27.5s |  |
| 975 | `textformat` | 1134 | 6.7s |  |
| 976 | `textformat_display` | 14 | 6.5s |  |
| 977 | `textformat_font_max_length` | 4 | 6.4s |  |
| 978 | `textline_inapplicable_properties` | 10 | 6.5s |  |
| 979 | `textline_name` | 1 | 6.4s |  |
| 980 | `textline_splitting_basic` | 76 | 6.7s |  |
| 981 | `textline_throwerror` | 30 | 6.5s |  |
| 982 | `textline_validity` | 162 | 6.7s |  |
| 983 | `throw` | 3 | 6.5s |  |
| 984 | `timeline_scripts` | 3 | 6.7s |  |
| 985 | `timer` | 90 | 7.2s |  |
| 986 | `timer_events` | 3 | 6.7s |  |
| 987 | `timer_finished` | 11 | 6.7s |  |
| 988 | `timer_invalid_delay` | 30 | 6.5s |  |
| 989 | `timer_reset` | 8 | 6.6s |  |
| 990 | `timer_setdelay` | 5 | 6.4s |  |
| 991 | `trace` | 12 | 6.4s |  |
| 992 | `truthiness` | 30 | 6.5s |  |
| 993 | `try_catch` | 11 | 23.3s |  |
| 994 | `try_catch_typed` | 12 | 6.2s |  |
| 995 | `typeof` | 30 | 6.3s |  |
| 996 | `uint_constr` | 92 | 6.4s |  |
| 997 | `uint_tofixed` | 1215 | 6.0s |  |
| 998 | `uint_tostring` | 3375 | 6.4s |  |
| 999 | `uncaught_error_basic` | 2 | 6.2s |  |
| 1000 | `unchecked_function` | 15 | 6.1s |  |
| 1001 | `unescape` | 28 | 6.2s |  |
| 1002 | `url_loader` | 25 | 6.2s |  |
| 1003 | `url_vars` | 27 | 6.3s |  |
| 1004 | `urlrequest` | 18 | 25.1s |  |
| 1005 | `urlstream_basic` | 5 | 6.2s |  |
| 1006 | `urshift` | 1058 | 18.2s |  |
| 1007 | `utils3d` | 7 | 6.1s |  |
| 1008 | `vector3d` | 397 | 10.8s |  |
| 1009 | `vector_class` | 36 | 6.6s |  |
| 1010 | `vector_class_call` | 11 | 6.4s |  |
| 1011 | `vector_coercion` | 66 | 7.0s |  |
| 1012 | `vector_concat` | 90 | 6.8s |  |
| 1013 | `vector_constr` | 107 | 6.8s |  |
| 1014 | `vector_enumeration` | 5 | 6.1s |  |
| 1015 | `vector_every` | 92 | 7.0s |  |
| 1016 | `vector_filter` | 95 | 7.1s |  |
| 1017 | `vector_holes` | 24 | 6.2s |  |
| 1018 | `vector_indexof` | 302 | 10.9s |  |
| 1019 | `vector_insertat` | 270 | 7.3s |  |
| 1020 | `vector_int_access` | 4 | 6.2s |  |
| 1021 | `vector_int_delete` | 11 | 6.1s |  |
| 1022 | `vector_join` | 58 | 6.6s |  |
| 1023 | `vector_lastindexof` | 302 | 6.1s |  |
| 1024 | `vector_legacy` | 10 | 6.2s |  |
| 1025 | `vector_map` | 85 | 7.0s |  |
| 1026 | `vector_object_final` | 1 | 6.1s |  |
| 1027 | `vector_object_toString` | 10 | 6.2s |  |
| 1028 | `vector_pushpop` | 255 | 7.5s |  |
| 1029 | `vector_reborrow_bug` | 10 | 6.4s |  |
| 1030 | `vector_removeat` | 172 | 24.7s |  |
| 1031 | `vector_reverse` | 232 | 7.5s |  |
| 1032 | `vector_shiftunshift` | 252 | 7.7s |  |
| 1033 | `vector_slice` | 331 | 8.1s |  |
| 1034 | `vector_sort` | 905 | 15.8s |  |
| 1035 | `vector_splice` | 693 | 10.4s |  |
| 1036 | `vector_splice_fixed_bug_compat` | 4 | 25.3s |  |
| 1037 | `vector_tostring` | 79 | 7.0s |  |
| 1038 | `verification` | 8 | 6.5s |  |
| 1039 | `verify_abnormal_loop` | 1 | 6.3s |  |
| 1040 | `verify_dxns_without_flag` | 3 | 6.7s |  |
| 1041 | `verify_exception_target_two_jumps` | 1 | 6.3s |  |
| 1042 | `verify_exception_targets_edge_case` | 1 | 6.3s |  |
| 1043 | `verify_illegal_opcode` | 1 | 2.6s |  |
| 1044 | `verify_jump_to_middle_of_op` | 1 | 6.3s |  |
| 1045 | `verify_lookup_switch_edge_case` | 1 | 6.3s |  |
| 1046 | `verify_method_info_oob` | 1 | 0.5s |  |
| 1047 | `verify_stack` | 5 | 6.4s |  |
| 1048 | `verify_typecheck` | 4 | 6.4s |  |
| 1049 | `verify_unreachable_exception` | 2 | 6.3s |  |
| 1050 | `versioned_isplaying` | 2 | 6.4s |  |
| 1051 | `virtual_properties` | 16 | 6.4s |  |
| 1052 | `with` | 4 | 6.3s |  |
| 1053 | `wrong_arg_count` | 7 | 6.6s |  |
| 1054 | `xml_abstract_equality` | 36 | 6.8s |  |
| 1055 | `xml_advanced` | 52 | 6.4s |  |
| 1056 | `xml_appendchild` | 10 | 6.4s |  |
| 1057 | `xml_appendchild_swf_v21` | 13 | 6.7s |  |
| 1058 | `xml_as_attribute` | 9 | 6.3s |  |
| 1059 | `xml_attribute` | 35 | 6.5s |  |
| 1060 | `xml_attribute_name` | 40 | 6.4s |  |
| 1061 | `xml_basic` | 33 | 6.5s |  |
| 1062 | `xml_child` | 25 | 6.4s |  |
| 1063 | `xml_childindex` | 7 | 6.3s |  |
| 1064 | `xml_children` | 43 | 6.9s |  |
| 1065 | `xml_class_call` | 9 | 6.3s |  |
| 1066 | `xml_contains` | 197 | 6.5s |  |
| 1067 | `xml_copy` | 20 | 2.3s |  |
| 1068 | `xml_ctor_from_tostring` | 23 | 24.1s |  |
| 1069 | `xml_delete` | 114 | 6.7s |  |
| 1070 | `xml_descendants` | 83 | 26.0s |  |
| 1071 | `xml_elements` | 6 | 6.4s |  |
| 1072 | `xml_equals_namespace_check` | 2 | 6.4s |  |
| 1073 | `xml_explicit_use_namespace` | 5 | 6.5s |  |
| 1074 | `xml_getdescendants_qname` | 21 | 6.5s |  |
| 1075 | `xml_has_property_via_in` | 26 | 6.5s |  |
| 1076 | `xml_hasownproperty` | 6 | 6.4s |  |
| 1077 | `xml_ignore_white` | 6 | 6.5s |  |
| 1078 | `xml_length` | 2 | 6.4s |  |
| 1079 | `xml_list_as_attribute` | 9 | 6.4s |  |
| 1080 | `xml_list_concat` | 20 | 6.5s |  |
| 1081 | `xml_list_ctor_errors` | 34 | 6.5s |  |
| 1082 | `xml_list_delete_clear_parent` | 6 | 6.4s |  |
| 1083 | `xml_list_enumerate` | 4 | 6.3s |  |
| 1084 | `xml_methods_settings` | 3 | 6.4s |  |
| 1085 | `xml_mismatched_tag` | 37 | 6.4s |  |
| 1086 | `xml_namespace` | 39 | 6.5s |  |
| 1087 | `xml_namespace_methods` | 245 | 6.5s |  |
| 1088 | `xml_namespaced_property` | 7 | 6.4s |  |
| 1089 | `xml_no_namespace` | 1 | 6.4s |  |
| 1090 | `xml_nodekind` | 3 | 6.4s |  |
| 1091 | `xml_normalize` | 35 | 6.6s |  |
| 1092 | `xml_notification_bubbling` | 361 | 6.6s |  |
| 1093 | `xml_parent` | 8 | 6.6s |  |
| 1094 | `xml_set_children` | 17 | 6.7s |  |
| 1095 | `xml_set_name` | 34 | 6.6s |  |
| 1096 | `xml_settings` | 6 | 2.3s |  |
| 1097 | `xml_simple_complex_content` | 47 | 6.5s |  |
| 1098 | `xml_socket` | 11 | 6.7s |  |
| 1099 | `xml_text` | 7 | 6.5s |  |
| 1100 | `xml_tostring` | 6 | 6.5s |  |
| 1101 | `xml_tostring_namespace` | 12 | 6.5s |  |
| 1102 | `xml_unescaping` | 23 | 6.6s |  |
| 1103 | `xml_weird_ignores` | 54 | 6.6s |  |
| 1104 | `xml_wildcard` | 11 | 6.6s |  |
| 1105 | `xmldocument` | 254 | 6.7s |  |
| 1106 | `xmlnode` | 3540 | 7.0s |  |
| 1107 | `zero_frame_clip` | 3 | 7.1s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.4s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 6.4s |  |
| 3 | `groupelement_text` | 2 | 2 | 6.2s |  |
| 4 | `textblock_line_changes` | 42 | 42 | 7.2s |  |
| 5 | `uncaught_errors_stringified` | 15 | 15 | 6.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**15 tests** within reach

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
| 9 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 10 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 11 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 12 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 13 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 14 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 15 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

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
| 9 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 10 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 11 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 12 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 13 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 14 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 15 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 16 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 17 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 18 | `textblock_recreateline` | 39.4% | 39/99 | 99 | 98 |  |
| 19 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 20 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 21 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 22 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 23 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 24 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 25 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 26 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 27 | `all_classes/xml/swf30` | 7.8% | 9/116 | 70 | 116 |  |
| 28 | `all_classes/xml/swf9` | 7.8% | 9/116 | 70 | 116 |  |
| 29 | `all_classes/accessibility/swf9` | 6.8% | 5/73 | 36 | 73 |  |
| 30 | `all_classes/accessibility/swf10` | 5.7% | 5/88 | 36 | 88 |  |
| 31 | `all_classes/accessibility/swf30` | 5.7% | 5/88 | 36 | 88 |  |
| 32 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 33 | `describe_type_native` | 4.3% | 1/23 | 19 | 23 |  |
| 34 | `all_classes/errors/swf10` | 4.3% | 6/140 | 126 | 140 |  |
| 35 | `all_classes/errors/swf30` | 4.3% | 6/140 | 126 | 140 |  |
| 36 | `describe_type_metadata` | 4.0% | 5/125 | 36 | 125 |  |
| 37 | `all_classes/display3D/swf30` | 2.9% | 12/412 | 321 | 412 |  |
| 38 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 39 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 40 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 41 | `all_classes/display3D/swf13` | 0.9% | 3/326 | 321 | 326 |  |
| 42 | `automation_classes` | 0.8% | 1/122 | 4 | 122 |  |
| 43 | `all_classes/errors/swf9` | 0.8% | 1/126 | 126 | 121 |  |
| 44 | `all_classes/display/swf11` | 0.6% | 15/2593 | 1647 | 2593 |  |
| 45 | `all_classes/display/swf12` | 0.6% | 15/2593 | 1647 | 2593 |  |
| 46 | `all_classes/display/swf10` | 0.5% | 12/2569 | 1647 | 2569 |  |
| 47 | `all_classes/display/swf13` | 0.4% | 12/2671 | 1647 | 2671 |  |
| 48 | `all_classes/display/swf9` | 0.4% | 7/1959 | 1647 | 1959 |  |
| 49 | `all_classes/display3D/swf12` | 0.3% | 1/321 | 321 | 61 |  |
| 50 | `all_classes/display/swf30` | 0.2% | 7/2936 | 1647 | 2936 |  |
| 51 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 52 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 53 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 54 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 55 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 56 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 57 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 58 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 59 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
