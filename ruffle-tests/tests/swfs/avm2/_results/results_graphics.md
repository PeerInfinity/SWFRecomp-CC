# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-06 23:55 UTC

**Git SHA**: `fb36ba1100`

**Run Duration**: 220m 49s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1226 |
| Passing | **1109** (90.5%) |
| Ruffle-matched | 30 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1139** (92.9%) |
| Failing | 87 |
| Total expected lines | 152155 |
| Matching lines | 121771 (80.0%) |
| Mismatched lines | 30384 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 87 | 100.0% |

## Passing Tests

**1109 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 26.7s |  |
| 2 | `accessibility` | 1 | 7.7s |  |
| 3 | `activation_class` | 6 | 7.8s |  |
| 4 | `add` | 1058 | 19.8s |  |
| 5 | `agal_compiler` | 13 | 10.2s |  |
| 6 | `air_datagram_socket` | 1 | 9.6s |  |
| 7 | `air_hidden_lookup` | 2 | 7.7s |  |
| 8 | `air_ifilepromise` | 1 | 7.6s |  |
| 9 | `all_classes/security/swf11` | 3 | 7.7s |  |
| 10 | `amf_array_serialization` | 17 | 10.1s |  |
| 11 | `amf_custom_obj` | 26 | 7.9s |  |
| 12 | `amf_dictionary` | 9 | 7.7s |  |
| 13 | `amf_function` | 46 | 7.8s |  |
| 14 | `amf_invalid_date` | 2 | 7.7s |  |
| 15 | `amf_missing_prop` | 6 | 7.8s |  |
| 16 | `amf_nondynamic_function_prop` | 6 | 7.5s |  |
| 17 | `amf_setter_error` | 8 | 7.6s |  |
| 18 | `amf_vector` | 40 | 7.7s |  |
| 19 | `amf_xml` | 6 | 7.5s |  |
| 20 | `application_domain` | 4 | 7.5s |  |
| 21 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.6s |  |
| 22 | `applicationdomain_hasdefinition_null` | 2 | 7.3s |  |
| 23 | `array_access` | 18 | 7.5s |  |
| 24 | `array_access_interpreter` | 4 | 7.4s |  |
| 25 | `array_access_no_pubns` | 2 | 7.4s |  |
| 26 | `array_concat` | 41 | 7.5s |  |
| 27 | `array_constr` | 10 | 7.4s |  |
| 28 | `array_delete` | 44 | 7.5s |  |
| 29 | `array_enumeration` | 10 | 7.4s |  |
| 30 | `array_enumeration_elements` | 11 | 7.4s |  |
| 31 | `array_every` | 8 | 7.5s |  |
| 32 | `array_filter` | 6 | 7.4s |  |
| 33 | `array_foreach` | 18 | 7.4s |  |
| 34 | `array_hasownproperty` | 11 | 3.1s |  |
| 35 | `array_holes` | 9 | 7.3s |  |
| 36 | `array_index_max` | 84 | 7.3s |  |
| 37 | `array_indexof` | 25 | 7.5s |  |
| 38 | `array_join` | 26 | 7.5s |  |
| 39 | `array_lastindexof` | 29 | 7.5s |  |
| 40 | `array_length` | 14 | 7.5s |  |
| 41 | `array_literal` | 3 | 7.5s |  |
| 42 | `array_map` | 8 | 7.4s |  |
| 43 | `array_pop` | 52 | 7.6s |  |
| 44 | `array_push` | 24 | 7.4s |  |
| 45 | `array_reborrow_bug` | 6 | 7.4s |  |
| 46 | `array_reverse` | 28 | 7.4s |  |
| 47 | `array_shift` | 51 | 3.2s |  |
| 48 | `array_slice` | 39 | 7.5s |  |
| 49 | `array_some` | 8 | 7.4s |  |
| 50 | `array_sort` | 297 | 7.9s |  |
| 51 | `array_sort_fun_swf12` | 2 | 7.4s |  |
| 52 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 53 | `array_sort_random` | 210 | 7.4s |  |
| 54 | `array_sort_swf10_32bit` | 1 | 7.5s |  |
| 55 | `array_sorton` | 545 | 8.2s |  |
| 56 | `array_sparse_ops` | 41 | 7.5s |  |
| 57 | `array_splice` | 133 | 7.7s |  |
| 58 | `array_splice2` | 428 | 7.7s |  |
| 59 | `array_splice_types` | 48 | 7.5s |  |
| 60 | `array_storage` | 8 | 7.4s |  |
| 61 | `array_tolocalestring` | 9 | 7.4s |  |
| 62 | `array_tostring` | 12 | 7.4s |  |
| 63 | `array_unshift` | 24 | 7.3s |  |
| 64 | `array_valueof` | 9 | 7.3s |  |
| 65 | `array_vector_null_callback` | 10 | 7.5s |  |
| 66 | `astype` | 28 | 7.5s |  |
| 67 | `astypelate` | 24 | 7.5s |  |
| 68 | `astypelate_propagates` | 1 | 7.3s |  |
| 69 | `asymmetric_key_events` | 11 | 7.6s |  |
| 70 | `av_classes` | 340 | 7.9s |  |
| 71 | `avm1movie_addcallback_call` | 14 | 7.9s |  |
| 72 | `avm2_catchup_dobj` | 158 | 8.1s |  |
| 73 | `away3d_advanced_shallow_water_demo` | 0 | 85.7s |  |
| 74 | `bevel_filter` | 187 | 7.5s |  |
| 75 | `bitand` | 1058 | 19.3s |  |
| 76 | `bitmap_constr` | 17 | 7.6s |  |
| 77 | `bitmap_data` | 1000 | 15.4s |  |
| 78 | `bitmap_pixelsnapping` | 2 | 26.1s |  |
| 79 | `bitmap_properties` | 23 | 7.4s |  |
| 80 | `bitmap_subclass` | 7 | 8.8s |  |
| 81 | `bitmap_subclass_properties` | 9 | 7.8s |  |
| 82 | `bitmap_timeline` | 9 | 7.6s |  |
| 83 | `bitmapdata_accuracy` | 1 | 43.5s |  |
| 84 | `bitmapdata_applyfilter_blur` | 0 | 26.7s |  |
| 85 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.2s |  |
| 86 | `bitmapdata_applyfilter_destpoint` | 0 | 26.5s |  |
| 87 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.9s |  |
| 88 | `bitmapdata_clone` | 13 | 7.6s |  |
| 89 | `bitmapdata_colortransform` | 0 | 7.9s |  |
| 90 | `bitmapdata_colortransform_oob` | 2 | 7.4s |  |
| 91 | `bitmapdata_constr` | 22 | 7.5s |  |
| 92 | `bitmapdata_constructor_from_timeline` | 1 | 7.7s |  |
| 93 | `bitmapdata_copychannel` | 0 | 30.3s |  |
| 94 | `bitmapdata_copypixels` | 23 | 28.7s |  |
| 95 | `bitmapdata_copypixels_blend_over` | 1 | 7.9s |  |
| 96 | `bitmapdata_copypixelstobytearray` | 39 | 7.8s |  |
| 97 | `bitmapdata_dispose` | 7 | 7.9s |  |
| 98 | `bitmapdata_draw` | 0 | 28.4s |  |
| 99 | `bitmapdata_draw_colortransform` | 0 | 8.2s |  |
| 100 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 27.6s |  |
| 101 | `bitmapdata_draw_filters` | 0 | 27.4s |  |
| 102 | `bitmapdata_draw_masks` | 0 | 8.0s |  |
| 103 | `bitmapdata_draw_rotation` | 0 | 8.1s |  |
| 104 | `bitmapdata_draw_self_via_graphic` | 0 | 8.1s |  |
| 105 | `bitmapdata_draw_stage` | 0 | 27.3s |  |
| 106 | `bitmapdata_drawwithquality` | 0 | 8.3s |  |
| 107 | `bitmapdata_embedded` | 9 | 8.2s |  |
| 108 | `bitmapdata_fillrect` | 0 | 8.2s |  |
| 109 | `bitmapdata_filter_sourcerect` | 0 | 28.2s |  |
| 110 | `bitmapdata_floodfill` | 35 | 7.9s |  |
| 111 | `bitmapdata_getpixels` | 39 | 27.8s |  |
| 112 | `bitmapdata_getvector` | 27 | 3.5s |  |
| 113 | `bitmapdata_histogram` | 59 | 3.4s |  |
| 114 | `bitmapdata_hittest` | 112 | 8.5s |  |
| 115 | `bitmapdata_hittest_threshold` | 18 | 7.9s |  |
| 116 | `bitmapdata_opaque` | 0 | 7.9s |  |
| 117 | `bitmapdata_pixeldissolve` | 1037 | 8.3s |  |
| 118 | `bitmapdata_pixeldissolve_image` | 0 | 8.1s |  |
| 119 | `bitmapdata_rectangle_rounding` | 16 | 7.8s |  |
| 120 | `bitmapdata_setpixels` | 286 | 7.8s |  |
| 121 | `bitmapdata_setvector` | 26 | 7.9s |  |
| 122 | `bitmapdata_sync` | 0 | 27.1s |  |
| 123 | `bitmapdata_threshold` | 176 | 8.6s |  |
| 124 | `bitmapdata_zero_size` | 8 | 7.9s |  |
| 125 | `bitnot` | 46 | 7.9s |  |
| 126 | `bitor` | 1058 | 19.2s |  |
| 127 | `bitxor` | 1058 | 19.1s |  |
| 128 | `blend_mode_null` | 1 | 7.8s |  |
| 129 | `blend_multiply_alpha` | 0 | 8.0s |  |
| 130 | `blend_scroll` | 0 | 7.9s |  |
| 131 | `blend_shader_luma_lighten` | 3 | 8.5s |  |
| 132 | `blur_filter` | 43 | 7.4s |  |
| 133 | `boolean_constr` | 32 | 7.4s |  |
| 134 | `boolean_negation` | 30 | 7.3s |  |
| 135 | `boolean_tostring` | 8 | 7.3s |  |
| 136 | `broadcast_event` | 7 | 7.5s |  |
| 137 | `button_bounds` | 1 | 7.4s |  |
| 138 | `button_hittest` | 2 | 25.5s |  |
| 139 | `button_nested_frame` | 48 | 26.4s |  |
| 140 | `bytearray` | 48 | 7.6s |  |
| 141 | `bytearray_compress` | 31 | 7.3s |  |
| 142 | `bytearray_errors` | 24 | 7.4s |  |
| 143 | `bytearray_method_serialization` | 1 | 7.3s |  |
| 144 | `bytearray_oom` | 3 | 7.3s |  |
| 145 | `bytearray_readobject_amf0` | 50 | 7.3s |  |
| 146 | `bytearray_readobject_amf3` | 53 | 7.3s |  |
| 147 | `bytearray_readutf8bytes_with_bom` | 16 | 7.4s |  |
| 148 | `bytearray_serialization` | 3 | 7.4s |  |
| 149 | `bytearray_string_null` | 19 | 7.6s |  |
| 150 | `bytearray_tostring` | 15 | 7.3s |  |
| 151 | `bytearray_utf16` | 8 | 7.2s |  |
| 152 | `bytearray_writeobject` | 24 | 7.2s |  |
| 153 | `callee_in_initializer` | 6 | 7.2s |  |
| 154 | `callproplex_class` | 1 | 7.2s |  |
| 155 | `capabilities_resolution` | 8 | 26.8s |  |
| 156 | `catch_class` | 6 | 7.3s |  |
| 157 | `catch_scope_slot` | 7 | 3.1s |  |
| 158 | `checkfilter` | 4 | 3.0s |  |
| 159 | `class_call` | 32 | 7.4s |  |
| 160 | `class_cast_call` | 14 | 7.3s |  |
| 161 | `class_enumeration` | 4 | 7.3s |  |
| 162 | `class_has_own_property` | 2 | 7.3s |  |
| 163 | `class_init_interpreter_mode` | 1 | 7.2s |  |
| 164 | `class_is` | 32 | 7.3s |  |
| 165 | `class_methods` | 5 | 7.3s |  |
| 166 | `class_object_properties` | 10 | 7.3s |  |
| 167 | `class_singleton` | 18 | 7.3s |  |
| 168 | `class_supercalls_errors` | 35 | 7.5s |  |
| 169 | `class_supercalls_mismatched` | 26 | 7.4s |  |
| 170 | `class_superclass_wrong_order` | 1 | 26.4s |  |
| 171 | `class_to_locale_string` | 2 | 7.8s |  |
| 172 | `class_to_string` | 2 | 7.6s |  |
| 173 | `class_value_of` | 2 | 7.7s |  |
| 174 | `click_block` | 5 | 8.6s |  |
| 175 | `click_invisible` | 3 | 8.0s |  |
| 176 | `closures` | 12 | 7.8s |  |
| 177 | `coerce_return_type` | 40 | 7.9s |  |
| 178 | `coerce_return_type_fail` | 2 | 7.8s |  |
| 179 | `coerce_return_void` | 3 | 7.7s |  |
| 180 | `coerce_string` | 86 | 7.9s |  |
| 181 | `coerce_string_precision` | 28 | 7.8s |  |
| 182 | `coerce_to_primitive_side_effects` | 29 | 26.6s |  |
| 183 | `color_matrix_filter` | 19 | 7.8s |  |
| 184 | `construct_errors_swf10` | 8 | 7.8s |  |
| 185 | `construct_frame_list` | 22 | 26.9s |  |
| 186 | `construct_interface` | 3 | 7.6s |  |
| 187 | `constructor_call` | 3 | 7.7s |  |
| 188 | `constructors_vs_timeline` | 5 | 27.1s |  |
| 189 | `constructprop_dynamic_primitive` | 7 | 7.8s |  |
| 190 | `constructprop_method` | 2 | 7.7s |  |
| 191 | `constructsuper_null` | 2 | 3.2s |  |
| 192 | `content_element_basic` | 50 | 8.0s |  |
| 193 | `context3d_creation` | 9 | 7.9s |  |
| 194 | `control_flow_bool` | 4 | 7.8s |  |
| 195 | `control_flow_stricteq` | 8 | 7.8s |  |
| 196 | `convert_boolean` | 30 | 7.8s |  |
| 197 | `convert_integer` | 90 | 8.0s |  |
| 198 | `convert_number` | 56 | 7.9s |  |
| 199 | `convert_uinteger` | 90 | 8.0s |  |
| 200 | `convolution_filter` | 89 | 8.0s |  |
| 201 | `core_exceptions` | 47 | 8.7s |  |
| 202 | `cpool_index_invalid_bytecode_1` | 6 | 7.9s |  |
| 203 | `cpool_index_invalid_bytecode_2` | 3 | 7.8s |  |
| 204 | `cpool_index_invalid_bytecode_3` | 1 | 7.8s |  |
| 205 | `cross_api_version_call_newer` | 12 | 8.5s |  |
| 206 | `cross_api_version_call_older` | 12 | 8.2s |  |
| 207 | `cryptscore` | 11 | 7.9s |  |
| 208 | `currency_parse_result` | 7 | 7.9s |  |
| 209 | `date` | 30 | 7.9s |  |
| 210 | `date_parse` | 36 | 7.4s |  |
| 211 | `declocal` | 46 | 7.5s |  |
| 212 | `declocal_i` | 46 | 7.4s |  |
| 213 | `decode_uri` | 71 | 7.7s |  |
| 214 | `decrement` | 46 | 7.4s |  |
| 215 | `decrement_i` | 46 | 3.1s |  |
| 216 | `default_values` | 7 | 7.4s |  |
| 217 | `describe_type_basic` | 152 | 7.5s |  |
| 218 | `describe_type_json` | 301 | 7.5s |  |
| 219 | `dictionary_access` | 62 | 7.6s |  |
| 220 | `dictionary_access_no_pubns` | 2 | 7.4s |  |
| 221 | `dictionary_delete` | 101 | 7.8s |  |
| 222 | `dictionary_foreach` | 42 | 7.6s |  |
| 223 | `dictionary_hasownproperty` | 63 | 7.6s |  |
| 224 | `dictionary_in` | 62 | 7.6s |  |
| 225 | `dictionary_iter_modify` | 8 | 7.4s |  |
| 226 | `dictionary_namespaces` | 36 | 7.5s |  |
| 227 | `dictionary_primitive_keys` | 29 | 7.4s |  |
| 228 | `displacement_map_filter` | 61 | 7.5s |  |
| 229 | `displayobject_alpha` | 277 | 7.3s |  |
| 230 | `displayobject_blendmode` | 0 | 7.6s |  |
| 231 | `displayobject_colortransform_nested` | 0 | 26.3s |  |
| 232 | `displayobject_filters` | 17 | 7.6s |  |
| 233 | `displayobject_from_enterframe` | 1 | 26.2s |  |
| 234 | `displayobject_getbounds_shape` | 0 | 26.1s |  |
| 235 | `displayobject_height` | 6052 | 26.3s |  |
| 236 | `displayobject_hittestobject` | 32 | 7.5s |  |
| 237 | `displayobject_hittestpoint` | 49 | 7.7s |  |
| 238 | `displayobject_hittestpoint_root` | 13 | 7.7s |  |
| 239 | `displayobject_invalid_floats` | 60 | 7.4s |  |
| 240 | `displayobject_invalid_props` | 3 | 7.3s |  |
| 241 | `displayobject_mask` | 3 | 7.8s |  |
| 242 | `displayobject_mask_self_referential` | 0 | 22.1s |  |
| 243 | `displayobject_metaData` | 3 | 6.1s |  |
| 244 | `displayobject_name` | 22 | 22.1s |  |
| 245 | `displayobject_name_from_timeline` | 24 | 6.1s |  |
| 246 | `displayobject_opaque_background` | 6 | 22.2s |  |
| 247 | `displayobject_parent` | 12 | 6.0s |  |
| 248 | `displayobject_root` | 24 | 6.1s |  |
| 249 | `displayobject_rotation` | 1284 | 6.2s |  |
| 250 | `displayobject_set_matrix_nested` | 0 | 22.2s |  |
| 251 | `displayobject_set_name_loaded` | 3 | 6.3s |  |
| 252 | `displayobject_subclass` | 2 | 6.1s |  |
| 253 | `displayobject_visible` | 23 | 6.1s |  |
| 254 | `displayobject_width` | 4852 | 22.4s |  |
| 255 | `displayobject_x` | 614 | 6.0s |  |
| 256 | `displayobject_y` | 617 | 6.1s |  |
| 257 | `displayobjectcontainer_addchild` | 32 | 6.1s |  |
| 258 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.0s |  |
| 259 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.2s |  |
| 260 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.1s |  |
| 261 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.2s |  |
| 262 | `displayobjectcontainer_addchildat` | 42 | 6.1s |  |
| 263 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.1s |  |
| 264 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.0s |  |
| 265 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.0s |  |
| 266 | `displayobjectcontainer_contains` | 66 | 22.2s |  |
| 267 | `displayobjectcontainer_getchildat` | 4 | 6.1s |  |
| 268 | `displayobjectcontainer_getchildbyname` | 9 | 6.0s |  |
| 269 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.0s |  |
| 270 | `displayobjectcontainer_getchildindex` | 28 | 6.0s |  |
| 271 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 6.1s |  |
| 272 | `displayobjectcontainer_removechild` | 10 | 5.9s |  |
| 273 | `displayobjectcontainer_removechild_errors` | 4 | 6.0s |  |
| 274 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.0s |  |
| 275 | `displayobjectcontainer_removechildat` | 18 | 5.9s |  |
| 276 | `displayobjectcontainer_removechildren` | 51 | 6.2s |  |
| 277 | `displayobjectcontainer_setchildindex` | 42 | 5.9s |  |
| 278 | `displayobjectcontainer_stopallmovieclips` | 2 | 22.2s |  |
| 279 | `displayobjectcontainer_swapchildren` | 42 | 6.1s |  |
| 280 | `displayobjectcontainer_swapchildrenat` | 42 | 6.0s |  |
| 281 | `displayobjectcontainer_timelineinstance` | 48 | 27.2s |  |
| 282 | `divide` | 1058 | 19.3s |  |
| 283 | `doabc_and_symbolclass_script_init_goto` | 7 | 27.2s |  |
| 284 | `doabc_and_symbolclass_script_init_normal` | 6 | 7.7s |  |
| 285 | `doabc_is_eager` | 1 | 26.6s |  |
| 286 | `documentclass` | 9 | 7.9s |  |
| 287 | `domain_memory` | 133 | 28.0s |  |
| 288 | `drag_drop` | 10 | 8.0s |  |
| 289 | `drop_shadow_filter` | 172 | 8.0s |  |
| 290 | `duplicate_defs` | 1 | 7.6s |  |
| 291 | `eager_init` | 1 | 7.8s |  |
| 292 | `east_asian_justifier_clone` | 8 | 3.3s |  |
| 293 | `edit_text_linkage` | 7 | 8.0s |  |
| 294 | `edittext_align` | 60 | 8.6s |  |
| 295 | `edittext_always_show_selection` | 0 | 27.4s |  |
| 296 | `edittext_antialiastype` | 296 | 8.2s |  |
| 297 | `edittext_at_point_methods_basic` | 16 | 9.4s |  |
| 298 | `edittext_autosize` | 39 | 8.4s |  |
| 299 | `edittext_autosize_align` | 0 | 27.4s |  |
| 300 | `edittext_autosize_height_dynamic` | 60 | 27.3s |  |
| 301 | `edittext_autosize_height_input` | 60 | 7.9s |  |
| 302 | `edittext_autosize_lazy_bounds_events` | 65 | 8.2s |  |
| 303 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.8s |  |
| 304 | `edittext_autosize_lazy_bounds_props` | 490 | 9.2s |  |
| 305 | `edittext_autosize_lazy_bounds_visual` | 0 | 27.0s |  |
| 306 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 8.1s |  |
| 307 | `edittext_bottom_scroll_v_basic` | 210 | 7.9s |  |
| 308 | `edittext_bounds_scale` | 24 | 26.6s |  |
| 309 | `edittext_bullet` | 30 | 8.0s |  |
| 310 | `edittext_default_format` | 221 | 8.3s |  |
| 311 | `edittext_default_format_empty` | 136 | 8.1s |  |
| 312 | `edittext_empty_text_format` | 7 | 7.8s |  |
| 313 | `edittext_focus_selection` | 5 | 7.7s |  |
| 314 | `edittext_font_size` | 45 | 8.0s |  |
| 315 | `edittext_format_empty_font` | 8 | 7.7s |  |
| 316 | `edittext_get_char_index_at_point` | 4 | 29.3s |  |
| 317 | `edittext_get_line_index_at_point` | 2 | 27.3s |  |
| 318 | `edittext_get_line_index_of_char` | 76 | 8.8s |  |
| 319 | `edittext_getcharboundaries` | 172 | 8.3s |  |
| 320 | `edittext_getcharboundaries_missing_glyphs` | 63 | 8.0s |  |
| 321 | `edittext_getcharboundaries_scroll` | 85 | 26.4s |  |
| 322 | `edittext_getlinemetrics` | 146 | 8.0s |  |
| 323 | `edittext_html` | 3101 | 7.9s |  |
| 324 | `edittext_html_condensewhite` | 487 | 7.6s |  |
| 325 | `edittext_html_entity` | 4 | 8.0s |  |
| 326 | `edittext_html_font_size_swf12` | 267 | 7.5s |  |
| 327 | `edittext_html_font_size_swf13` | 273 | 7.3s |  |
| 328 | `edittext_html_roundtrip` | 17 | 7.5s |  |
| 329 | `edittext_ime_focus_lost` | 9 | 26.4s |  |
| 330 | `edittext_input_control` | 12 | 7.7s |  |
| 331 | `edittext_leading` | 9 | 8.1s |  |
| 332 | `edittext_letter_spacing` | 15 | 7.7s |  |
| 333 | `edittext_line_methods` | 294 | 9.1s |  |
| 334 | `edittext_line_metrics` | 11 | 27.9s |  |
| 335 | `edittext_margins` | 25 | 7.7s |  |
| 336 | `edittext_max_scroll_h_basic` | 475 | 7.7s |  |
| 337 | `edittext_max_scroll_v_basic` | 1000 | 7.6s |  |
| 338 | `edittext_mouse_selection` | 363 | 27.7s |  |
| 339 | `edittext_mousedown` | 3 | 7.8s |  |
| 340 | `edittext_mouseenabled` | 26 | 7.5s |  |
| 341 | `edittext_newline_character` | 22 | 7.4s |  |
| 342 | `edittext_newline_stripping` | 64 | 11.5s |  |
| 343 | `edittext_newlines` | 30 | 7.7s |  |
| 344 | `edittext_paragraph_methods` | 257 | 7.5s |  |
| 345 | `edittext_paste_events` | 8 | 7.7s |  |
| 346 | `edittext_paste_maxchars` | 4 | 7.5s |  |
| 347 | `edittext_paste_restrict` | 16 | 7.3s |  |
| 348 | `edittext_restrict` | 191 | 7.5s |  |
| 349 | `edittext_restrict_events` | 22 | 7.4s |  |
| 350 | `edittext_scrollh` | 10 | 7.4s |  |
| 351 | `edittext_selected_text` | 9 | 7.4s |  |
| 352 | `edittext_set_html_same` | 17 | 7.5s |  |
| 353 | `edittext_set_text_vs_html` | 9 | 7.4s |  |
| 354 | `edittext_stylesheet` | 536 | 7.8s |  |
| 355 | `edittext_stylesheet_custom_tag` | 76 | 7.5s |  |
| 356 | `edittext_stylesheet_display` | 272 | 7.6s |  |
| 357 | `edittext_underline` | 40 | 7.7s |  |
| 358 | `edittext_width_height` | 103 | 25.3s |  |
| 359 | `edittext_wordwrap_word` | 150 | 26.8s |  |
| 360 | `edittext_wrap_breaks` | 2375 | 8.1s |  |
| 361 | `element_format_clone` | 44 | 7.8s |  |
| 362 | `element_format_constructor_order` | 64 | 7.9s |  |
| 363 | `element_format_properties` | 235 | 8.6s |  |
| 364 | `empty_bounds` | 1 | 7.6s |  |
| 365 | `encode_uri_surrogate_pair_invalid` | 8 | 7.6s |  |
| 366 | `encode_uri_surrogate_pair_swf11` | 15 | 7.2s |  |
| 367 | `equals` | 512 | 11.5s |  |
| 368 | `error_geterrormessage` | 779 | 7.6s |  |
| 369 | `error_prototype` | 15 | 7.6s |  |
| 370 | `error_stack_trace` | 45 | 7.6s |  |
| 371 | `error_stack_trace_debug_swf17` | 0 | 26.4s |  |
| 372 | `error_stack_trace_debug_swf18` | 0 | 7.3s |  |
| 373 | `error_stack_trace_edge_cases` | 6 | 7.5s |  |
| 374 | `error_stack_trace_release_swf17` | 0 | 7.5s |  |
| 375 | `error_stack_trace_release_swf18` | 0 | 7.2s |  |
| 376 | `error_throwerror` | 103 | 7.7s |  |
| 377 | `error_tostring` | 29 | 7.6s |  |
| 378 | `error_tostring_more` | 86 | 7.7s |  |
| 379 | `es3_inheritance` | 31 | 7.7s |  |
| 380 | `es4_inheritance` | 30 | 7.7s |  |
| 381 | `es4_interfaces` | 30 | 7.8s |  |
| 382 | `es4_method_binding` | 8 | 7.7s |  |
| 383 | `es4_oop_prototypes` | 14 | 7.7s |  |
| 384 | `es4_protected_inheritance` | 6 | 7.6s |  |
| 385 | `escape` | 71 | 7.6s |  |
| 386 | `escape_multi_byte` | 45 | 7.7s |  |
| 387 | `event_bubbles` | 2 | 7.6s |  |
| 388 | `event_cancelable` | 2 | 7.5s |  |
| 389 | `event_clone` | 20 | 7.6s |  |
| 390 | `event_clone_error_redispatch` | 3 | 7.6s |  |
| 391 | `event_clone_on_redispatch` | 10 | 7.7s |  |
| 392 | `event_formattostring` | 31 | 7.7s |  |
| 393 | `event_isdefaultprevented` | 12 | 7.7s |  |
| 394 | `event_target_getter` | 5 | 3.3s |  |
| 395 | `event_target_set` | 9 | 7.6s |  |
| 396 | `event_type` | 1 | 25.3s |  |
| 397 | `event_valueof_tostring` | 18 | 7.8s |  |
| 398 | `eventdispatcher_dispatchevent` | 12 | 7.8s |  |
| 399 | `eventdispatcher_dispatchevent_cancel` | 20 | 26.8s |  |
| 400 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.8s |  |
| 401 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.9s |  |
| 402 | `eventdispatcher_dispatchevent_this` | 5 | 7.7s |  |
| 403 | `eventdispatcher_haseventlistener` | 25 | 7.8s |  |
| 404 | `eventdispatcher_interface_invoke` | 1 | 7.7s |  |
| 405 | `eventdispatcher_tostring` | 10 | 7.8s |  |
| 406 | `eventdispatcher_willtrigger` | 25 | 7.7s |  |
| 407 | `falsiness` | 30 | 7.8s |  |
| 408 | `fast_index_access` | 12 | 7.9s |  |
| 409 | `filefilter_properties` | 4 | 7.7s |  |
| 410 | `filereference_browse_cancel` | 3 | 7.7s |  |
| 411 | `filereference_browse_select` | 9 | 7.7s |  |
| 412 | `filereference_load` | 31 | 7.8s |  |
| 413 | `filereference_save` | 16 | 7.8s |  |
| 414 | `filereference_save_and_browse` | 42 | 8.0s |  |
| 415 | `filereference_save_and_load` | 22 | 7.9s |  |
| 416 | `filereference_uninitialized` | 8 | 7.8s |  |
| 417 | `filereferencelist_browse_cancel` | 6 | 7.7s |  |
| 418 | `filereferencelist_browse_select` | 7 | 7.8s |  |
| 419 | `filter_rewind` | 8 | 8.1s |  |
| 420 | `filters_array_holes` | 25 | 7.8s |  |
| 421 | `finddef` | 3 | 7.8s |  |
| 422 | `findprop_global_prototype` | 6 | 8.0s |  |
| 423 | `flash_media_video_constructor` | 156 | 8.6s |  |
| 424 | `flash_media_video_rotation_probe` | 27 | 8.0s |  |
| 425 | `flash_media_video_setter` | 40 | 8.3s |  |
| 426 | `flash_trace` | 17 | 8.1s |  |
| 427 | `flash_xml` | 29 | 7.9s |  |
| 428 | `flash_xml_cloneNode` | 22 | 8.1s |  |
| 429 | `flash_xml_namespace` | 109 | 8.1s |  |
| 430 | `flash_xml_removeNode` | 60 | 8.2s |  |
| 431 | `focus_events_code` | 161 | 29.3s |  |
| 432 | `focus_events_key_basic` | 132 | 29.4s |  |
| 433 | `focus_events_key_navigation` | 53 | 8.3s |  |
| 434 | `focus_events_key_same_object` | 26 | 8.2s |  |
| 435 | `focus_events_mixed_key_mouse` | 100 | 44.5s |  |
| 436 | `focus_events_mouse_basic` | 260 | 27.4s |  |
| 437 | `focus_events_mouse_focusable` | 112 | 27.5s |  |
| 438 | `focus_events_mouse_same_object` | 40 | 27.0s |  |
| 439 | `focus_remove` | 20 | 26.8s |  |
| 440 | `focus_root_movie` | 4 | 28.6s |  |
| 441 | `focus_stage` | 1 | 7.7s |  |
| 442 | `focusrect` | 18 | 8.5s |  |
| 443 | `focusrect_focuslost` | 9 | 7.7s |  |
| 444 | `focusrect_property` | 110 | 26.7s |  |
| 445 | `font_description_clone` | 14 | 7.7s |  |
| 446 | `font_embedded` | 24 | 8.3s |  |
| 447 | `font_enumeratefonts` | 41 | 8.7s |  |
| 448 | `font_enumeratefonts_filter` | 4 | 27.1s |  |
| 449 | `font_enumeratefonts_order` | 9 | 9.0s |  |
| 450 | `font_hasglyphs` | 40 | 8.4s |  |
| 451 | `font_registerfont` | 129 | 9.1s |  |
| 452 | `framelabel_constr` | 5 | 8.0s |  |
| 453 | `function_call` | 12 | 7.8s |  |
| 454 | `function_call_arguments` | 46 | 7.9s |  |
| 455 | `function_call_arguments_enumerate` | 5 | 7.7s |  |
| 456 | `function_call_coercion` | 108 | 8.1s |  |
| 457 | `function_call_default` | 6 | 7.6s |  |
| 458 | `function_call_rest` | 22 | 7.7s |  |
| 459 | `function_call_types` | 3 | 7.6s |  |
| 460 | `function_call_via_apply` | 11 | 7.7s |  |
| 461 | `function_call_via_call` | 3 | 7.7s |  |
| 462 | `function_display_anonymous` | 7 | 3.4s |  |
| 463 | `function_length` | 6 | 7.7s |  |
| 464 | `function_object` | 2 | 7.6s |  |
| 465 | `function_proto` | 5 | 7.6s |  |
| 466 | `function_proto_created` | 61 | 7.8s |  |
| 467 | `function_to_locale_string` | 4 | 7.7s |  |
| 468 | `function_to_string` | 4 | 7.5s |  |
| 469 | `function_type` | 6 | 7.6s |  |
| 470 | `function_unbound_this` | 51 | 7.8s |  |
| 471 | `function_value_of` | 4 | 7.7s |  |
| 472 | `game_input` | 4 | 7.7s |  |
| 473 | `generate_random_bytes` | 3 | 7.7s |  |
| 474 | `get_definition_by_name` | 11 | 24.4s |  |
| 475 | `get_qualified_class_name` | 20 | 7.4s |  |
| 476 | `get_qualified_super_class_name` | 18 | 7.4s |  |
| 477 | `get_slot_edge_cases` | 1 | 25.6s |  |
| 478 | `get_timer` | 2 | 7.4s |  |
| 479 | `getglobalslot` | 1 | 7.4s |  |
| 480 | `getouterscope` | 8 | 7.3s |  |
| 481 | `getouterscope_two_classobjects` | 13 | 7.4s |  |
| 482 | `getter_different_namespace_setter` | 2 | 7.2s |  |
| 483 | `glow_filter` | 127 | 7.5s |  |
| 484 | `goto_button_nested_framescript` | 28 | 26.3s |  |
| 485 | `goto_in_constructframe` | 12 | 26.2s |  |
| 486 | `goto_in_scene_last_frame` | 2 | 25.8s |  |
| 487 | `goto_methods` | 56 | 7.6s |  |
| 488 | `goto_methods_swfver10` | 8 | 7.3s |  |
| 489 | `goto_nested_construct_sibling` | 18 | 7.9s |  |
| 490 | `goto_nested_framescript` | 9 | 7.5s |  |
| 491 | `goto_on_orphan` | 15 | 7.6s |  |
| 492 | `gradient_bevel_filter` | 206 | 7.5s |  |
| 493 | `gradient_glow_filter` | 206 | 7.4s |  |
| 494 | `graphic_linkage` | 9 | 7.6s |  |
| 495 | `graphics_bad_direct_commands` | 5 | 10.0s |  |
| 496 | `graphics_bitmap_fill` | 0 | 27.8s |  |
| 497 | `graphics_bitmaps` | 0 | 8.1s |  |
| 498 | `graphics_direct_commands` | 0 | 8.0s |  |
| 499 | `graphics_draw_triangles` | 98 | 26.7s |  |
| 500 | `graphics_gradients` | 0 | 7.7s |  |
| 501 | `graphics_gradients_nulls` | 0 | 7.6s |  |
| 502 | `graphics_path` | 56 | 7.5s |  |
| 503 | `graphics_round_rects` | 0 | 7.6s |  |
| 504 | `graphics_simple_shapes` | 0 | 7.6s |  |
| 505 | `greaterequals` | 512 | 11.3s |  |
| 506 | `greaterthan` | 512 | 11.3s |  |
| 507 | `has_own_property` | 102 | 7.9s |  |
| 508 | `hasownproperty_namespaces` | 2 | 7.3s |  |
| 509 | `hello_world` | 1 | 7.3s |  |
| 510 | `hittest_morph` | 30 | 7.5s |  |
| 511 | `if_eq` | 10 | 24.6s |  |
| 512 | `if_gt` | 1 | 7.5s |  |
| 513 | `if_gte` | 10 | 3.1s |  |
| 514 | `if_lt` | 1 | 1.2s |  |
| 515 | `if_lte` | 10 | 7.3s |  |
| 516 | `if_ne` | 7 | 3.1s |  |
| 517 | `if_stricteq` | 6 | 7.4s |  |
| 518 | `if_strictne` | 11 | 7.5s |  |
| 519 | `ime_linux_dead_keys` | 10 | 26.3s |  |
| 520 | `in` | 102 | 7.9s |  |
| 521 | `inclocal` | 46 | 7.5s |  |
| 522 | `inclocal_i` | 46 | 7.5s |  |
| 523 | `increment` | 46 | 7.5s |  |
| 524 | `increment_i` | 46 | 7.5s |  |
| 525 | `indexing_delete` | 75 | 7.5s |  |
| 526 | `instanceof` | 58 | 7.7s |  |
| 527 | `instantiate_root_character` | 4 | 7.7s |  |
| 528 | `instantiation_on_enter_frame` | 7 | 26.5s |  |
| 529 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.5s |  |
| 530 | `int_constr` | 92 | 7.8s |  |
| 531 | `int_edge_cases` | 19 | 7.7s |  |
| 532 | `int_instanceof` | 3 | 7.4s |  |
| 533 | `int_tofixed` | 1215 | 7.5s |  |
| 534 | `int_tostring` | 3375 | 7.9s |  |
| 535 | `interactiveobject_enabled` | 25 | 7.6s |  |
| 536 | `interface_namespaces` | 78 | 7.7s |  |
| 537 | `invalid_utf8` | 12 | 7.5s |  |
| 538 | `is_finite` | 46 | 7.7s |  |
| 539 | `is_nan` | 46 | 7.4s |  |
| 540 | `is_prototype_of` | 12 | 7.4s |  |
| 541 | `issue_10221` | 2 | 7.4s |  |
| 542 | `issue_13780` | 12 | 7.5s |  |
| 543 | `issue_14901` | 1 | 7.4s |  |
| 544 | `issue_17675_edittext_paste_maxchars` | 1 | 7.5s |  |
| 545 | `issue_5292` | 5 | 7.5s |  |
| 546 | `issue_8630` | 2 | 25.9s |  |
| 547 | `issue_8630_placeremoveplace` | 15 | 7.5s |  |
| 548 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.4s |  |
| 549 | `issue_8630_scriptremove` | 11 | 7.4s |  |
| 550 | `istype` | 24 | 24.9s |  |
| 551 | `istypelate` | 58 | 7.9s |  |
| 552 | `istypelate_coerce` | 198 | 8.6s |  |
| 553 | `jpeg_loader_context` | 6 | 27.1s |  |
| 554 | `json_errors` | 9 | 27.5s |  |
| 555 | `json_parse` | 21 | 7.6s |  |
| 556 | `json_stringify` | 12 | 7.8s |  |
| 557 | `json_stringify_function` | 12 | 7.6s |  |
| 558 | `json_stringify_order` | 1 | 7.6s |  |
| 559 | `json_version_gated` | 1 | 7.6s |  |
| 560 | `key_input_80percent` | 1812 | 7.9s |  |
| 561 | `key_input_location` | 126 | 7.8s |  |
| 562 | `key_input_numpad` | 384 | 7.7s |  |
| 563 | `lazyinit` | 17 | 7.7s |  |
| 564 | `lessequals` | 512 | 11.6s |  |
| 565 | `lessthan` | 512 | 11.8s |  |
| 566 | `loader_bitmap_transparency` | 14 | 7.8s |  |
| 567 | `loader_bytes_unknown_content` | 14 | 7.7s |  |
| 568 | `loader_child_getdefinition` | 5 | 8.0s |  |
| 569 | `loader_duplicate_coerce` | 3 | 8.1s |  |
| 570 | `loader_duplicate_coerce_new_domain` | 4 | 7.9s |  |
| 571 | `loader_error_in_root_ctor` | 4 | 7.9s |  |
| 572 | `loader_events` | 92 | 10.2s |  |
| 573 | `loader_image` | 8 | 8.0s |  |
| 574 | `loader_jpegxr` | 2 | 27.2s |  |
| 575 | `loader_jpegxr_alpha` | 1 | 26.6s |  |
| 576 | `loader_loadbytes_events` | 30 | 8.2s |  |
| 577 | `loader_loadbytes_invalid_png` | 4 | 26.4s |  |
| 578 | `loader_loadbytes_url` | 12 | 7.9s |  |
| 579 | `loader_loaderurl` | 6 | 8.0s |  |
| 580 | `loader_method` | 85 | 7.6s |  |
| 581 | `loader_noninteractive_try_click_root` | 5 | 26.9s |  |
| 582 | `loader_reuse` | 38 | 7.8s |  |
| 583 | `loader_unknown_content` | 24 | 7.6s |  |
| 584 | `loader_visibility_interactive` | 1 | 43.1s |  |
| 585 | `loaderinfo_events` | 7 | 25.8s |  |
| 586 | `loaderinfo_loadurl` | 12 | 26.0s |  |
| 587 | `loaderinfo_more` | 6 | 7.3s |  |
| 588 | `loaderinfo_properties` | 18 | 7.0s |  |
| 589 | `loaderinfo_properties_not_loaded` | 23 | 7.1s |  |
| 590 | `loaderinfo_quine` | 1005 | 6.9s |  |
| 591 | `loaderinfo_root` | 10 | 7.0s |  |
| 592 | `loaderinfo_root_allows` | 2 | 6.9s |  |
| 593 | `localconnection_send` | 4 | 7.0s |  |
| 594 | `lshift` | 1058 | 18.5s |  |
| 595 | `mask_reapply` | 1 | 7.0s |  |
| 596 | `math` | 497 | 7.2s |  |
| 597 | `matrix3d` | 57 | 7.7s |  |
| 598 | `matrix3d_compose` | 34 | 7.1s |  |
| 599 | `matrix3d_invert` | 18 | 6.9s |  |
| 600 | `method_without_body` | 3 | 25.7s |  |
| 601 | `missing_external_interface` | 10 | 7.0s |  |
| 602 | `modulo` | 1058 | 18.4s |  |
| 603 | `morph_shape` | 2 | 25.8s |  |
| 604 | `mouse_children` | 192 | 26.2s |  |
| 605 | `mouse_click_events` | 90 | 25.9s |  |
| 606 | `mouse_double_click_events` | 188 | 7.0s |  |
| 607 | `mouse_empty_parent` | 4 | 7.0s |  |
| 608 | `mouse_over_while_dragging` | 3 | 7.2s |  |
| 609 | `mouse_pick_button_mode` | 2 | 7.0s |  |
| 610 | `mouse_pick_dobj_mask` | 4 | 7.3s |  |
| 611 | `mouse_pick_masking` | 7 | 26.0s |  |
| 612 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.0s |  |
| 613 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.3s |  |
| 614 | `mouse_pick_text` | 8 | 7.2s |  |
| 615 | `mouse_sibling` | 8 | 7.1s |  |
| 616 | `mouse_wheel_events` | 36 | 27.1s |  |
| 617 | `mouseevent_constr` | 66 | 7.1s |  |
| 618 | `mouseevent_stagexy` | 35 | 7.1s |  |
| 619 | `mouseevent_valueof_tostring` | 28 | 7.0s |  |
| 620 | `movieclip_addframescript` | 3 | 46.1s |  |
| 621 | `movieclip_child_property` | 16 | 8.6s |  |
| 622 | `movieclip_constr` | 21 | 8.2s |  |
| 623 | `movieclip_currentlabels` | 17 | 28.2s |  |
| 624 | `movieclip_currentlabels_dupes1` | 46 | 27.6s |  |
| 625 | `movieclip_currentlabels_dupes2` | 30 | 7.8s |  |
| 626 | `movieclip_currentlabels_dupes3` | 67 | 8.0s |  |
| 627 | `movieclip_currentscene` | 12 | 27.7s |  |
| 628 | `movieclip_dispatchevent` | 430 | 7.8s |  |
| 629 | `movieclip_dispatchevent_cancel` | 102 | 7.8s |  |
| 630 | `movieclip_dispatchevent_handlerorder` | 251 | 7.7s |  |
| 631 | `movieclip_dispatchevent_selfadd` | 80 | 7.5s |  |
| 632 | `movieclip_dispatchevent_target` | 899 | 7.7s |  |
| 633 | `movieclip_displayevents` | 96 | 26.8s |  |
| 634 | `movieclip_displayevents_clickgoto` | 676 | 26.7s |  |
| 635 | `movieclip_displayevents_clickgoto2` | 2001 | 8.1s |  |
| 636 | `movieclip_displayevents_clickplay` | 575 | 7.7s |  |
| 637 | `movieclip_displayevents_clicksymbol` | 562 | 7.8s |  |
| 638 | `movieclip_displayevents_constructframegoto` | 140 | 7.9s |  |
| 639 | `movieclip_displayevents_constructframeplay` | 50 | 7.8s |  |
| 640 | `movieclip_displayevents_constructframesymbol` | 144 | 7.8s |  |
| 641 | `movieclip_displayevents_dblhandler` | 21 | 7.7s |  |
| 642 | `movieclip_displayevents_enterframegoto` | 149 | 8.0s |  |
| 643 | `movieclip_displayevents_enterframeplay` | 48 | 7.8s |  |
| 644 | `movieclip_displayevents_enterframesymbol` | 149 | 26.9s |  |
| 645 | `movieclip_displayevents_exitframegoto` | 106 | 7.8s |  |
| 646 | `movieclip_displayevents_exitframeplay` | 44 | 7.8s |  |
| 647 | `movieclip_displayevents_exitframesymbol` | 135 | 7.9s |  |
| 648 | `movieclip_displayevents_looping` | 63 | 26.8s |  |
| 649 | `movieclip_displayevents_stopped` | 113 | 8.1s |  |
| 650 | `movieclip_displayevents_swap` | 96 | 3.2s |  |
| 651 | `movieclip_displayevents_timeline` | 128 | 26.7s |  |
| 652 | `movieclip_drawrect` | 54 | 7.7s |  |
| 653 | `movieclip_frameconstruct_skipped` | 9 | 7.8s |  |
| 654 | `movieclip_goto_during_frame_script` | 15 | 7.6s |  |
| 655 | `movieclip_goto_overwrite` | 14 | 27.0s |  |
| 656 | `movieclip_goto_scene_last_frame_int` | 1 | 27.9s |  |
| 657 | `movieclip_goto_scene_last_frame_label` | 1 | 7.5s |  |
| 658 | `movieclip_gotoandplay` | 15 | 28.0s |  |
| 659 | `movieclip_gotoandstop` | 13 | 27.8s |  |
| 660 | `movieclip_gotoandstop_children` | 4 | 8.0s |  |
| 661 | `movieclip_gotoandstop_framescripts1` | 4 | 25.4s |  |
| 662 | `movieclip_gotoandstop_framescripts2` | 4 | 3.3s |  |
| 663 | `movieclip_gotoandstop_framescripts_self` | 7 | 27.0s |  |
| 664 | `movieclip_gotoandstop_queueing` | 12 | 27.0s |  |
| 665 | `movieclip_hittest` | 67 | 8.0s |  |
| 666 | `movieclip_next_frame` | 2 | 27.0s |  |
| 667 | `movieclip_next_scene` | 6 | 26.9s |  |
| 668 | `movieclip_play` | 3 | 7.7s |  |
| 669 | `movieclip_prev_frame` | 3 | 7.6s |  |
| 670 | `movieclip_prev_scene` | 7 | 7.8s |  |
| 671 | `movieclip_properties` | 79 | 27.1s |  |
| 672 | `movieclip_queued_noop_goto_swf10` | 9 | 7.8s |  |
| 673 | `movieclip_queued_noop_goto_swf9` | 7 | 1.4s |  |
| 674 | `movieclip_scenes` | 11 | 7.7s |  |
| 675 | `movieclip_soundtransform` | 831 | 29.0s |  |
| 676 | `movieclip_stop` | 1 | 26.5s |  |
| 677 | `movieclip_super_is_symbol` | 20 | 8.2s |  |
| 678 | `movieclip_symbol_constr` | 8 | 7.9s |  |
| 679 | `movieclip_text_mousedown` | 1 | 7.9s |  |
| 680 | `movieclip_willtrigger` | 5 | 8.1s |  |
| 681 | `multiply` | 1058 | 19.4s |  |
| 682 | `namespace_constr` | 253 | 8.3s |  |
| 683 | `namespace_constr_args` | 1 | 7.8s |  |
| 684 | `namespace_enumeration_order` | 7 | 27.3s |  |
| 685 | `nan_scale` | 9 | 8.0s |  |
| 686 | `navigateToURL_target_normalize` | 107 | 29.8s |  |
| 687 | `negate` | 30 | 8.1s |  |
| 688 | `negative_volume_panned` | 0 | 8.3s |  |
| 689 | `nested_iteration` | 11 | 8.0s |  |
| 690 | `net_getClassByAlias` | 3 | 8.0s |  |
| 691 | `net_navigateToURL` | 57 | 8.0s |  |
| 692 | `net_stream_play_options` | 6 | 8.0s |  |
| 693 | `netconnection_close` | 55 | 8.1s |  |
| 694 | `netconnection_properties` | 78 | 8.2s |  |
| 695 | `netconnection_send_remote` | 50 | 8.4s |  |
| 696 | `netconnection_serialize_arrays` | 6 | 8.1s |  |
| 697 | `netfilterevent` | 10 | 7.9s |  |
| 698 | `netstream_client` | 10 | 8.2s |  |
| 699 | `netstream_connect` | 7 | 8.0s |  |
| 700 | `newactivation_in_script_init` | 3 | 8.1s |  |
| 701 | `newclass_mismatched` | 4 | 7.8s |  |
| 702 | `newclass_twice` | 3 | 7.6s |  |
| 703 | `nonconflicting_declarations` | 0 | 7.8s |  |
| 704 | `null_void_types` | 8 | 7.8s |  |
| 705 | `number_autoconv` | 21 | 7.8s |  |
| 706 | `number_autoconv_amf` | 132 | 7.8s |  |
| 707 | `number_autoconv_array_sort_32bit` | 1 | 7.7s |  |
| 708 | `number_constr` | 58 | 7.9s |  |
| 709 | `number_toexponential` | 378 | 7.7s |  |
| 710 | `number_toexponential2` | 35 | 7.7s |  |
| 711 | `number_tofixed` | 378 | 7.8s |  |
| 712 | `number_toprecision` | 350 | 7.8s |  |
| 713 | `obfuscated_class_names` | 3 | 7.7s |  |
| 714 | `object_enumeration` | 10 | 7.7s |  |
| 715 | `object_prototype` | 4 | 7.8s |  |
| 716 | `object_to_locale_string` | 2 | 7.7s |  |
| 717 | `object_to_string` | 2 | 7.7s |  |
| 718 | `object_value_of` | 2 | 3.2s |  |
| 719 | `op_coerce` | 54 | 8.0s |  |
| 720 | `op_coerce_x` | 54 | 7.9s |  |
| 721 | `op_escxattr` | 2 | 7.8s |  |
| 722 | `op_escxelem` | 2 | 7.9s |  |
| 723 | `op_lookupswitch` | 4 | 7.8s |  |
| 724 | `optimize_coerce` | 1 | 7.8s |  |
| 725 | `orphan_movie_complex` | 80 | 8.5s |  |
| 726 | `orphan_movie_reorder` | 111 | 28.0s |  |
| 727 | `package_namespace` | 7 | 7.8s |  |
| 728 | `param_default_value_has_zero_cpool_index` | 1 | 7.9s |  |
| 729 | `parent_early_access_child` | 16 | 27.3s |  |
| 730 | `parse_float` | 81 | 8.0s |  |
| 731 | `parse_float_swf10` | 81 | 7.7s |  |
| 732 | `parse_int` | 135 | 8.2s |  |
| 733 | `perspective_projection` | 1443 | 7.9s |  |
| 734 | `perspective_projection_basic` | 40 | 35.0s |  |
| 735 | `pixelbender_ceil` | 77 | 6.3s |  |
| 736 | `pixelbender_conditional` | 138 | 6.3s |  |
| 737 | `pixelbender_conversions` | 270 | 6.7s |  |
| 738 | `pixelbender_dithering` | 8 | 28.1s |  |
| 739 | `pixelbender_div` | 36 | 6.5s |  |
| 740 | `pixelbender_effect_BlurredFocus` | 0 | 27.9s |  |
| 741 | `pixelbender_effect_glassDisplace` | 0 | 11.1s |  |
| 742 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 25.1s |  |
| 743 | `pixelbender_effect_smudge` | 0 | 9.2s |  |
| 744 | `pixelbender_effect_tintype` | 0 | 8.2s |  |
| 745 | `pixelbender_effect_twirl` | 0 | 10.0s |  |
| 746 | `pixelbender_eof` | 7 | 6.3s |  |
| 747 | `pixelbender_images` | 0 | 8.0s |  |
| 748 | `pixelbender_input` | 103 | 22.3s |  |
| 749 | `pixelbender_logicalnot` | 20 | 6.8s |  |
| 750 | `pixelbender_malformed_data` | 190 | 22.4s |  |
| 751 | `pixelbender_multiple_out_params` | 1 | 6.2s |  |
| 752 | `pixelbender_no_out_param` | 6 | 6.2s |  |
| 753 | `pixelbender_outputs` | 13 | 6.3s |  |
| 754 | `pixelbender_padding_bytes` | 22 | 6.2s |  |
| 755 | `pixelbender_param_qualifier` | 512 | 6.2s |  |
| 756 | `pixelbender_parameters` | 1563 | 6.4s |  |
| 757 | `pixelbender_parameters_bool` | 240 | 6.3s |  |
| 758 | `pixelbender_parameters_int_vs_bool` | 54 | 6.2s |  |
| 759 | `pixelbender_parse_errors` | 6 | 6.2s |  |
| 760 | `pixelbender_rsqrt` | 24 | 6.3s |  |
| 761 | `pixelbender_select_kinds` | 8 | 6.2s |  |
| 762 | `pixelbender_shaderdata` | 49 | 6.1s |  |
| 763 | `pixelbender_shaderdata_setter` | 99 | 6.5s |  |
| 764 | `pixelbender_sign` | 60 | 6.3s |  |
| 765 | `pixelbender_vector_output` | 11 | 6.2s |  |
| 766 | `place_and_lookup/swf10` | 33 | 6.1s |  |
| 767 | `place_and_lookup/swf9` | 33 | 1.1s |  |
| 768 | `place_multiple` | 17 | 21.0s |  |
| 769 | `place_object_replace` | 9 | 6.3s |  |
| 770 | `place_object_replace_2` | 24 | 6.2s |  |
| 771 | `place_object_same_depth_frame` | 1 | 6.1s |  |
| 772 | `point` | 132 | 6.5s |  |
| 773 | `primitive_edge_cases` | 1 | 6.1s |  |
| 774 | `primitive_toString` | 277 | 6.3s |  |
| 775 | `primitive_valueOf` | 285 | 24.6s |  |
| 776 | `print_job_options` | 3 | 25.8s |  |
| 777 | `property_is_enumerable` | 114 | 8.2s |  |
| 778 | `property_is_enumerable_reset` | 23 | 7.4s |  |
| 779 | `property_priority` | 22 | 7.7s |  |
| 780 | `property_priority_chained` | 4 | 7.3s |  |
| 781 | `property_priority_definition_names_order` | 2 | 7.6s |  |
| 782 | `property_priority_three_level` | 6 | 26.2s |  |
| 783 | `propertyisenumerable_namespaces` | 6 | 7.4s |  |
| 784 | `prototype_set_null` | 7 | 7.4s |  |
| 785 | `proxy_callproperty` | 24 | 7.6s |  |
| 786 | `proxy_deleteproperty` | 64 | 7.5s |  |
| 787 | `proxy_enumeration` | 34 | 7.4s |  |
| 788 | `proxy_getproperty` | 77 | 7.5s |  |
| 789 | `proxy_hasownproperty` | 8 | 7.3s |  |
| 790 | `proxy_hasproperty` | 32 | 7.4s |  |
| 791 | `proxy_not_overridden` | 54 | 7.4s |  |
| 792 | `proxy_serialize` | 9 | 7.4s |  |
| 793 | `proxy_setproperty` | 42 | 7.4s |  |
| 794 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.3s |  |
| 795 | `qname_constr` | 32 | 7.5s |  |
| 796 | `qname_constr_namespace` | 24 | 7.5s |  |
| 797 | `qname_enumeration` | 9 | 7.5s |  |
| 798 | `qname_indexing` | 23 | 7.7s |  |
| 799 | `qname_tostring` | 25 | 7.7s |  |
| 800 | `qname_valueof` | 29 | 7.7s |  |
| 801 | `rectangle` | 1094 | 8.3s |  |
| 802 | `regexp_constr` | 148 | 7.6s |  |
| 803 | `regexp_exec` | 19 | 7.4s |  |
| 804 | `regexp_extended` | 47 | 7.4s |  |
| 805 | `regexp_multiargs` | 1 | 7.4s |  |
| 806 | `regexp_test` | 27 | 7.4s |  |
| 807 | `regexp_toString` | 10 | 7.4s |  |
| 808 | `register_script_refresh` | 35 | 26.4s |  |
| 809 | `remove_child_clear_field` | 88 | 7.8s |  |
| 810 | `remove_dobj` | 3 | 7.3s |  |
| 811 | `resolve_order` | 4 | 7.3s |  |
| 812 | `responder_null_callbacks` | 1 | 7.3s |  |
| 813 | `rng` | 1 | 8.5s |  |
| 814 | `rootless` | 42 | 7.6s |  |
| 815 | `rshift` | 1058 | 19.6s |  |
| 816 | `rtqname_not_namespace` | 12 | 25.4s |  |
| 817 | `sandbox_type_inherited` | 2 | 8.4s |  |
| 818 | `sandbox_type_local_file` | 1 | 27.0s |  |
| 819 | `sandbox_type_local_network` | 1 | 7.6s |  |
| 820 | `scene_constr` | 8 | 8.1s |  |
| 821 | `scopes_dont_cache/order-1` | 1 | 26.8s |  |
| 822 | `scopes_dont_cache/order-2` | 1 | 1.0s |  |
| 823 | `security_domain_current` | 2 | 7.7s |  |
| 824 | `selection` | 239 | 8.3s |  |
| 825 | `set_local_0` | 31 | 7.8s |  |
| 826 | `set_property_is_enumerable` | 85 | 8.2s |  |
| 827 | `shaderparameter_value` | 4 | 7.8s |  |
| 828 | `shape_drawrect` | 54 | 7.8s |  |
| 829 | `shared_object_no_root` | 3 | 7.6s |  |
| 830 | `simplebutton_added_to_stage` | 45 | 26.6s |  |
| 831 | `simplebutton_childevents` | 86 | 27.1s |  |
| 832 | `simplebutton_childevents_nested` | 54 | 8.0s |  |
| 833 | `simplebutton_childevents_sprite` | 13 | 7.8s |  |
| 834 | `simplebutton_childprops` | 144 | 8.0s |  |
| 835 | `simplebutton_childshuffle` | 23 | 7.6s |  |
| 836 | `simplebutton_constr` | 36 | 8.0s |  |
| 837 | `simplebutton_constr_childevents` | 48 | 8.0s |  |
| 838 | `simplebutton_constr_params` | 42 | 7.8s |  |
| 839 | `simplebutton_mouseenabled` | 26 | 7.7s |  |
| 840 | `simplebutton_multi_children` | 19 | 8.1s |  |
| 841 | `simplebutton_structure` | 27 | 8.0s |  |
| 842 | `simplebutton_symbolclass` | 68 | 8.2s |  |
| 843 | `slot_disp_id_shared_numbering` | 1 | 26.3s |  |
| 844 | `slots_force_autoassigned` | 1 | 7.7s |  |
| 845 | `socket_after_disconnect` | 1 | 7.8s |  |
| 846 | `socket_close` | 2 | 7.7s |  |
| 847 | `socket_connect` | 4 | 7.7s |  |
| 848 | `socket_errors` | 56 | 8.1s |  |
| 849 | `socket_read_big` | 48 | 43.7s |  |
| 850 | `socket_read_little` | 48 | 3.0s |  |
| 851 | `socket_read_write_object` | 8 | 7.5s |  |
| 852 | `socket_write_big` | 15 | 7.7s |  |
| 853 | `socket_write_little` | 14 | 7.5s |  |
| 854 | `sound_embeddedprops` | 26 | 7.9s |  |
| 855 | `sound_play` | 19 | 7.7s |  |
| 856 | `sound_valueof` | 33 | 7.6s |  |
| 857 | `soundchannel_soundtransform` | 835 | 28.4s |  |
| 858 | `soundchannel_soundtransform_exists` | 5 | 26.3s |  |
| 859 | `soundchannel_stop` | 8 | 26.7s |  |
| 860 | `soundmixer_buffertime` | 5 | 7.4s |  |
| 861 | `soundmixer_stopall` | 6 | 26.3s |  |
| 862 | `soundtransform` | 442 | 13.2s |  |
| 863 | `space_justifier_clone` | 12 | 7.4s |  |
| 864 | `sprite_with_frames` | 0 | 29.0s |  |
| 865 | `stage3d_agal_cross_product` | 0 | 10.1s |  |
| 866 | `stage3d_agal_upload_errors` | 66 | 10.1s |  |
| 867 | `stage3d_bitmap` | 0 | 31.5s |  |
| 868 | `stage3d_blend` | 81 | 30.8s |  |
| 869 | `stage3d_context3d_string_args` | 158 | 8.5s |  |
| 870 | `stage3d_errors` | 7 | 7.5s |  |
| 871 | `stage3d_errors_atf` | 3 | 8.8s |  |
| 872 | `stage3d_errors_swf_29` | 6 | 7.7s |  |
| 873 | `stage3d_float1_index` | 0 | 28.8s |  |
| 874 | `stage3d_fractal` | 0 | 29.5s |  |
| 875 | `stage3d_ignore_sampler_override` | 0 | 29.1s |  |
| 876 | `stage3d_multistage_triangle` | 3 | 10.4s |  |
| 877 | `stage3d_program_constants_bytearray_be` | 0 | 30.9s |  |
| 878 | `stage3d_program_constants_bytearray_le` | 0 | 10.9s |  |
| 879 | `stage3d_program_constants_invalid_input` | 21 | 8.4s |  |
| 880 | `stage3d_raytrace` | 0 | 33.9s |  |
| 881 | `stage3d_rotating_cube` | 0 | 11.1s |  |
| 882 | `stage3d_sampler` | 0 | 10.3s |  |
| 883 | `stage3d_sampler_partial_upload` | 0 | 28.3s |  |
| 884 | `stage3d_stencil` | 0 | 29.3s |  |
| 885 | `stage3d_texture` | 0 | 15.1s |  |
| 886 | `stage3d_texture_bytearray` | 0 | 10.9s |  |
| 887 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.3s |  |
| 888 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.7s |  |
| 889 | `stage3d_triangle` | 0 | 9.8s |  |
| 890 | `stage3d_triangle_bytes4` | 0 | 9.8s |  |
| 891 | `stage3d_triangle_float1` | 0 | 9.6s |  |
| 892 | `stage3d_triangle_index_upload` | 0 | 9.7s |  |
| 893 | `stage3d_x_y` | 22 | 7.1s |  |
| 894 | `stage_access` | 10 | 7.1s |  |
| 895 | `stage_displayobject_properties` | 24 | 6.9s |  |
| 896 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.9s |  |
| 897 | `stage_framerate_nan` | 7 | 26.3s |  |
| 898 | `stage_framerate_negative` | 6 | 7.0s |  |
| 899 | `stage_framerate_zero` | 6 | 7.0s |  |
| 900 | `stage_invalidate` | 38 | 7.2s |  |
| 901 | `stage_loaderinfo_properties` | 24 | 26.2s |  |
| 902 | `stage_mousechildren` | 2 | 7.0s |  |
| 903 | `stage_mouseenabled` | 15 | 6.9s |  |
| 904 | `stage_overriden_setters` | 31 | 7.2s |  |
| 905 | `stage_properties` | 30 | 7.0s |  |
| 906 | `stage_properties2` | 213 | 7.2s |  |
| 907 | `stage_stage3Ds_vector` | 1 | 25.5s |  |
| 908 | `static_length` | 24 | 7.0s |  |
| 909 | `static_text` | 3 | 7.2s |  |
| 910 | `static_var_with_this_in_ctor` | 2 | 7.0s |  |
| 911 | `statictext_text` | 8 | 7.1s |  |
| 912 | `stored_properties` | 11 | 7.1s |  |
| 913 | `strict_equality` | 34 | 7.0s |  |
| 914 | `string_call` | 13 | 7.0s |  |
| 915 | `string_case` | 23 | 7.0s |  |
| 916 | `string_char_at` | 27 | 7.0s |  |
| 917 | `string_char_code_at` | 28 | 6.9s |  |
| 918 | `string_concat_fromcharcode` | 37 | 6.9s |  |
| 919 | `string_constr` | 25 | 7.0s |  |
| 920 | `string_indexof_lastindexof` | 87 | 7.2s |  |
| 921 | `string_length` | 16 | 7.0s |  |
| 922 | `string_locale_compare` | 39 | 25.7s |  |
| 923 | `string_match` | 51 | 27.3s |  |
| 924 | `string_relational_compare` | 4 | 7.8s |  |
| 925 | `string_replace` | 51 | 7.9s |  |
| 926 | `string_search` | 41 | 8.0s |  |
| 927 | `string_slice_substr_substring` | 170 | 8.8s |  |
| 928 | `string_split` | 29 | 7.8s |  |
| 929 | `string_substr_negative` | 21 | 7.8s |  |
| 930 | `string_substr_weird` | 182 | 7.7s |  |
| 931 | `stylesheet` | 221 | 8.3s |  |
| 932 | `stylesheet_parse_color` | 69 | 7.8s |  |
| 933 | `stylesheet_transform` | 307 | 8.2s |  |
| 934 | `subclass_superclass_linked_symbol` | 4 | 8.3s |  |
| 935 | `subtract` | 1058 | 19.2s |  |
| 936 | `super_get_call` | 12 | 7.9s |  |
| 937 | `supercall_two_classobjects` | 2 | 7.8s |  |
| 938 | `supercalls_weird` | 2 | 7.8s |  |
| 939 | `superinterface_call` | 20 | 7.9s |  |
| 940 | `superinterface_instanceof` | 18 | 7.9s |  |
| 941 | `swf8` | 1 | 7.8s |  |
| 942 | `swf_10_queued_goto_scripts_construct` | 52 | 27.5s |  |
| 943 | `swf_9_goto_in_enter_frame` | 17 | 8.0s |  |
| 944 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.9s |  |
| 945 | `swf_9_queued_goto_scripts` | 6 | 27.2s |  |
| 946 | `swf_9_queued_goto_scripts_construct` | 28 | 1.5s |  |
| 947 | `swf_9_versioning` | 2 | 7.9s |  |
| 948 | `swf_wrong_frame_count` | 38 | 8.2s |  |
| 949 | `swf_wrong_frame_count_isplaying` | 22 | 26.8s |  |
| 950 | `symbol_class_binary_data` | 8 | 7.8s |  |
| 951 | `symbol_class_conflict` | 4 | 10.2s |  |
| 952 | `symbol_class_root_not_zero` | 1 | 7.8s |  |
| 953 | `symbolclass_invalid_utf8` | 2 | 7.8s |  |
| 954 | `system_exit` | 3 | 7.8s |  |
| 955 | `system_setclipboard_null` | 1 | 7.7s |  |
| 956 | `tab_ordering_arrows` | 998 | 28.4s |  |
| 957 | `tab_ordering_automatic_advanced` | 184 | 8.6s |  |
| 958 | `tab_ordering_automatic_basic` | 45 | 7.8s |  |
| 959 | `tab_ordering_children` | 116 | 47.9s |  |
| 960 | `tab_ordering_custom_basic` | 34 | 7.8s |  |
| 961 | `tab_ordering_stage_tab_children` | 32 | 8.0s |  |
| 962 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.9s |  |
| 963 | `tab_ordering_tabbable` | 47 | 8.0s |  |
| 964 | `tabstop_properties` | 105 | 8.4s |  |
| 965 | `text_element_basic` | 34 | 8.1s |  |
| 966 | `text_engine_fontdescription` | 27 | 8.0s |  |
| 967 | `text_engine_groupelement` | 64 | 8.6s |  |
| 968 | `text_run` | 7 | 7.6s |  |
| 969 | `textblock_createline_errors` | 23 | 8.0s |  |
| 970 | `textblock_createline_fte` | 9 | 28.0s |  |
| 971 | `textblock_properties` | 118 | 8.1s |  |
| 972 | `textbox_click` | 37 | 28.2s |  |
| 973 | `textfield_event` | 66 | 8.3s |  |
| 974 | `textfield_focusin_event` | 9 | 7.9s |  |
| 975 | `textfield_input_dead_keys_windows` | 15 | 7.9s |  |
| 976 | `textfield_unload` | 39 | 28.4s |  |
| 977 | `textformat` | 1134 | 8.0s |  |
| 978 | `textformat_display` | 14 | 7.8s |  |
| 979 | `textformat_font_max_length` | 4 | 8.0s |  |
| 980 | `textline_inapplicable_properties` | 10 | 7.8s |  |
| 981 | `textline_name` | 1 | 7.7s |  |
| 982 | `textline_splitting_basic` | 76 | 7.8s |  |
| 983 | `textline_throwerror` | 30 | 7.7s |  |
| 984 | `textline_validity` | 162 | 7.9s |  |
| 985 | `throw` | 3 | 7.7s |  |
| 986 | `timeline_scripts` | 3 | 7.9s |  |
| 987 | `timer` | 90 | 8.7s |  |
| 988 | `timer_events` | 3 | 7.7s |  |
| 989 | `timer_finished` | 11 | 7.7s |  |
| 990 | `timer_invalid_delay` | 30 | 7.5s |  |
| 991 | `timer_reset` | 8 | 7.8s |  |
| 992 | `timer_setdelay` | 5 | 7.8s |  |
| 993 | `trace` | 12 | 7.6s |  |
| 994 | `truthiness` | 30 | 7.7s |  |
| 995 | `try_catch` | 11 | 25.0s |  |
| 996 | `try_catch_typed` | 12 | 7.4s |  |
| 997 | `typeof` | 30 | 7.5s |  |
| 998 | `uint_constr` | 92 | 7.5s |  |
| 999 | `uint_tofixed` | 1215 | 7.2s |  |
| 1000 | `uint_tostring` | 3375 | 7.6s |  |
| 1001 | `uncaught_error_basic` | 2 | 7.4s |  |
| 1002 | `unchecked_function` | 15 | 7.3s |  |
| 1003 | `unescape` | 28 | 7.4s |  |
| 1004 | `url_loader` | 25 | 7.5s |  |
| 1005 | `url_vars` | 27 | 7.5s |  |
| 1006 | `urlrequest` | 18 | 26.7s |  |
| 1007 | `urlstream_basic` | 5 | 7.4s |  |
| 1008 | `urshift` | 1058 | 18.6s |  |
| 1009 | `utils3d` | 7 | 7.3s |  |
| 1010 | `vector3d` | 397 | 11.5s |  |
| 1011 | `vector_class` | 36 | 7.8s |  |
| 1012 | `vector_class_call` | 11 | 7.6s |  |
| 1013 | `vector_coercion` | 66 | 8.2s |  |
| 1014 | `vector_concat` | 90 | 7.9s |  |
| 1015 | `vector_constr` | 107 | 8.0s |  |
| 1016 | `vector_enumeration` | 5 | 7.4s |  |
| 1017 | `vector_every` | 92 | 8.1s |  |
| 1018 | `vector_filter` | 95 | 8.2s |  |
| 1019 | `vector_holes` | 24 | 7.4s |  |
| 1020 | `vector_indexof` | 302 | 11.6s |  |
| 1021 | `vector_insertat` | 270 | 8.4s |  |
| 1022 | `vector_int_access` | 4 | 7.3s |  |
| 1023 | `vector_int_delete` | 11 | 7.3s |  |
| 1024 | `vector_join` | 58 | 7.8s |  |
| 1025 | `vector_lastindexof` | 302 | 7.2s |  |
| 1026 | `vector_legacy` | 10 | 7.4s |  |
| 1027 | `vector_map` | 85 | 8.0s |  |
| 1028 | `vector_object_final` | 1 | 7.2s |  |
| 1029 | `vector_object_toString` | 10 | 7.3s |  |
| 1030 | `vector_pushpop` | 255 | 8.5s |  |
| 1031 | `vector_reborrow_bug` | 10 | 7.2s |  |
| 1032 | `vector_removeat` | 172 | 26.5s |  |
| 1033 | `vector_reverse` | 232 | 9.0s |  |
| 1034 | `vector_shiftunshift` | 252 | 9.1s |  |
| 1035 | `vector_slice` | 331 | 9.4s |  |
| 1036 | `vector_sort` | 905 | 17.2s |  |
| 1037 | `vector_splice` | 693 | 11.8s |  |
| 1038 | `vector_splice_fixed_bug_compat` | 4 | 26.5s |  |
| 1039 | `vector_tostring` | 79 | 8.1s |  |
| 1040 | `verification` | 8 | 7.8s |  |
| 1041 | `verify_abnormal_loop` | 1 | 7.5s |  |
| 1042 | `verify_dxns_without_flag` | 3 | 8.0s |  |
| 1043 | `verify_exception_target_two_jumps` | 1 | 7.6s |  |
| 1044 | `verify_exception_targets_edge_case` | 1 | 7.6s |  |
| 1045 | `verify_illegal_opcode` | 1 | 3.5s |  |
| 1046 | `verify_jump_to_middle_of_op` | 1 | 7.6s |  |
| 1047 | `verify_lookup_switch_edge_case` | 1 | 7.6s |  |
| 1048 | `verify_method_info_oob` | 1 | 1.2s |  |
| 1049 | `verify_stack` | 5 | 7.7s |  |
| 1050 | `verify_typecheck` | 4 | 7.7s |  |
| 1051 | `verify_unreachable_exception` | 2 | 7.6s |  |
| 1052 | `versioned_isplaying` | 2 | 7.7s |  |
| 1053 | `virtual_properties` | 16 | 7.9s |  |
| 1054 | `with` | 4 | 7.8s |  |
| 1055 | `wrong_arg_count` | 7 | 7.9s |  |
| 1056 | `xml_abstract_equality` | 36 | 8.2s |  |
| 1057 | `xml_advanced` | 52 | 7.8s |  |
| 1058 | `xml_appendchild` | 10 | 7.8s |  |
| 1059 | `xml_appendchild_swf_v21` | 13 | 8.1s |  |
| 1060 | `xml_as_attribute` | 9 | 7.8s |  |
| 1061 | `xml_attribute` | 35 | 8.0s |  |
| 1062 | `xml_attribute_name` | 40 | 7.9s |  |
| 1063 | `xml_basic` | 33 | 7.8s |  |
| 1064 | `xml_child` | 25 | 7.9s |  |
| 1065 | `xml_childindex` | 7 | 7.8s |  |
| 1066 | `xml_children` | 43 | 8.4s |  |
| 1067 | `xml_class_call` | 9 | 7.8s |  |
| 1068 | `xml_contains` | 197 | 8.0s |  |
| 1069 | `xml_copy` | 20 | 3.4s |  |
| 1070 | `xml_ctor_from_tostring` | 23 | 19.8s |  |
| 1071 | `xml_delete` | 114 | 6.1s |  |
| 1072 | `xml_descendants` | 83 | 21.0s |  |
| 1073 | `xml_elements` | 6 | 6.1s |  |
| 1074 | `xml_equals_namespace_check` | 2 | 6.2s |  |
| 1075 | `xml_explicit_use_namespace` | 5 | 6.1s |  |
| 1076 | `xml_getdescendants_qname` | 21 | 6.2s |  |
| 1077 | `xml_has_property_via_in` | 26 | 6.1s |  |
| 1078 | `xml_hasownproperty` | 6 | 6.1s |  |
| 1079 | `xml_ignore_white` | 6 | 6.0s |  |
| 1080 | `xml_length` | 2 | 6.1s |  |
| 1081 | `xml_list_as_attribute` | 9 | 6.2s |  |
| 1082 | `xml_list_concat` | 20 | 6.0s |  |
| 1083 | `xml_list_ctor_errors` | 34 | 6.1s |  |
| 1084 | `xml_list_delete_clear_parent` | 6 | 6.0s |  |
| 1085 | `xml_list_enumerate` | 4 | 6.0s |  |
| 1086 | `xml_methods_settings` | 3 | 6.2s |  |
| 1087 | `xml_mismatched_tag` | 37 | 6.1s |  |
| 1088 | `xml_namespace` | 39 | 6.3s |  |
| 1089 | `xml_namespace_methods` | 245 | 6.2s |  |
| 1090 | `xml_namespaced_property` | 7 | 6.1s |  |
| 1091 | `xml_no_namespace` | 1 | 6.1s |  |
| 1092 | `xml_nodekind` | 3 | 6.0s |  |
| 1093 | `xml_normalize` | 35 | 6.3s |  |
| 1094 | `xml_notification_bubbling` | 361 | 6.5s |  |
| 1095 | `xml_parent` | 8 | 6.3s |  |
| 1096 | `xml_set_children` | 17 | 6.6s |  |
| 1097 | `xml_set_name` | 34 | 6.2s |  |
| 1098 | `xml_settings` | 6 | 2.6s |  |
| 1099 | `xml_simple_complex_content` | 47 | 6.2s |  |
| 1100 | `xml_socket` | 11 | 6.5s |  |
| 1101 | `xml_text` | 7 | 6.1s |  |
| 1102 | `xml_tostring` | 6 | 6.3s |  |
| 1103 | `xml_tostring_namespace` | 12 | 6.2s |  |
| 1104 | `xml_unescaping` | 23 | 6.4s |  |
| 1105 | `xml_weird_ignores` | 54 | 6.2s |  |
| 1106 | `xml_wildcard` | 11 | 6.2s |  |
| 1107 | `xmldocument` | 254 | 6.4s |  |
| 1108 | `xmlnode` | 3540 | 6.4s |  |
| 1109 | `zero_frame_clip` | 3 | 7.3s |  |

## Ruffle-Matched Tests

**30 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 7.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 25.8s |  |
| 3 | `blend_transform` | 1 | 1 | 8.1s |  |
| 4 | `coerce_property` | 3 | 3 | 7.9s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.8s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 26.1s |  |
| 7 | `edittext_device_transform_layout` | 20 | 20 | 7.9s |  |
| 8 | `edittext_getcharboundaries_culling` | 300 | 300 | 8.0s |  |
| 9 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 43.3s |  |
| 10 | `edittext_tab_stops` | 6 | 6 | 7.7s |  |
| 11 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.6s |  |
| 12 | `error_1034_debug_string` | 19 | 19 | 7.6s |  |
| 13 | `freestanding_superclass` | 2 | 4 | 7.7s |  |
| 14 | `goto_framescript_queued` | 5 | 5 | 25.9s |  |
| 15 | `graphics_draw_path` | 50 | 50 | 26.6s |  |
| 16 | `groupelement_text` | 2 | 2 | 7.6s |  |
| 17 | `int_toexponential` | 76 | 76 | 7.8s |  |
| 18 | `int_toprecision` | 441 | 441 | 7.8s |  |
| 19 | `simplebutton_childevents_script_order` | 4 | 4 | 8.0s |  |
| 20 | `slot_holes_fail` | 1 | 1 | 7.7s |  |
| 21 | `slot_id_exceeds_trait_count` | 1 | 1 | 26.5s |  |
| 22 | `soundchannel_position` | 74 | 74 | 27.2s |  |
| 23 | `soundchannel_soundcomplete` | 10 | 10 | 7.8s |  |
| 24 | `sprite_dropTarget` | 15 | 15 | 7.6s |  |
| 25 | `swf_9_goto_in_construct_frame` | 12 | 12 | 27.6s |  |
| 26 | `textblock_line_changes` | 42 | 42 | 8.1s |  |
| 27 | `uint_toexponential` | 100 | 100 | 7.5s |  |
| 28 | `uint_toprecision` | 433 | 433 | 7.5s |  |
| 29 | `uncaught_errors_stringified` | 15 | 15 | 7.6s |  |
| 30 | `weird_superinterface_properties` | 1 | 1 | 27.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**28 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 2 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 3 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 4 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 5 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 6 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 7 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 8 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 9 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 10 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 11 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 12 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 13 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 14 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 15 | `delayed_symbolclass` | 71.4% | 20 | 28 | 8 |  |
| 16 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 17 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 18 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 19 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 20 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 21 | `displayobject_scrollrect` | 57.6% | 19 | 33 | 14 |  |
| 22 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 23 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 24 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 25 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 26 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 27 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 28 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**87 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 2 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 3 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 4 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 5 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 6 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 7 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 8 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 9 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 10 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 11 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 12 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 13 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 14 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 15 | `delayed_symbolclass` | 71.4% | 20/28 | 28 | 28 |  |
| 16 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 17 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 18 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 19 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 20 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 21 | `displayobject_scrollrect` | 57.6% | 19/33 | 33 | 33 |  |
| 22 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 23 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 24 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 25 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 26 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 27 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 28 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 29 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 30 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 31 | `textblock_recreateline` | 39.4% | 39/99 | 99 | 98 |  |
| 32 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 33 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 34 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 35 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 36 | `geom_transform` | 28.4% | 21/74 | 26 | 74 |  |
| 37 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 38 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 39 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 40 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 41 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 42 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 43 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 44 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 45 | `all_classes/xml/swf30` | 7.8% | 9/116 | 70 | 116 |  |
| 46 | `all_classes/xml/swf9` | 7.8% | 9/116 | 70 | 116 |  |
| 47 | `all_classes/accessibility/swf9` | 6.8% | 5/73 | 36 | 73 |  |
| 48 | `all_classes/accessibility/swf10` | 5.7% | 5/88 | 36 | 88 |  |
| 49 | `all_classes/accessibility/swf30` | 5.7% | 5/88 | 36 | 88 |  |
| 50 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 51 | `describe_type_native` | 4.3% | 1/23 | 19 | 23 |  |
| 52 | `all_classes/errors/swf10` | 4.3% | 6/140 | 126 | 140 |  |
| 53 | `all_classes/errors/swf30` | 4.3% | 6/140 | 126 | 140 |  |
| 54 | `describe_type_metadata` | 4.0% | 5/125 | 36 | 125 |  |
| 55 | `all_classes/display3D/swf30` | 2.9% | 12/412 | 321 | 412 |  |
| 56 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 57 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 58 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 59 | `all_classes/events/swf9` | 1.1% | 11/1030 | 718 | 1030 |  |
| 60 | `all_classes/display3D/swf13` | 0.9% | 3/326 | 321 | 326 |  |
| 61 | `all_classes/errors/swf9` | 0.8% | 1/126 | 126 | 121 |  |
| 62 | `all_classes/events/swf10` | 0.8% | 13/1638 | 718 | 1638 |  |
| 63 | `all_classes/events/swf11` | 0.7% | 13/1750 | 718 | 1750 |  |
| 64 | `all_classes/events/swf12` | 0.7% | 13/1814 | 718 | 1814 |  |
| 65 | `all_classes/display/swf11` | 0.6% | 15/2593 | 1647 | 2593 |  |
| 66 | `all_classes/display/swf12` | 0.6% | 15/2593 | 1647 | 2593 |  |
| 67 | `all_classes/display/swf10` | 0.5% | 12/2569 | 1647 | 2569 |  |
| 68 | `all_classes/display/swf13` | 0.4% | 12/2671 | 1647 | 2671 |  |
| 69 | `all_classes/display/swf9` | 0.4% | 7/1959 | 1647 | 1959 |  |
| 70 | `all_classes/display3D/swf12` | 0.3% | 1/321 | 321 | 61 |  |
| 71 | `all_classes/display/swf30` | 0.2% | 7/2936 | 1647 | 2936 |  |
| 72 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 73 | `all_classes/events/swf30` | 0.0% | 0/2353 | 722 | 2353 |  |
| 74 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 75 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 76 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 77 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 78 | `avm1_root` | 0.0% | 0/58 | 7 | 58 |  |
| 79 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 80 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 81 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 82 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 83 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 84 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 85 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 86 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 87 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
