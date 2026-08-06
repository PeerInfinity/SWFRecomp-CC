# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-06 10:26 UTC

**Git SHA**: `1f8396f579`

**Run Duration**: 223m 9s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1226 |
| Passing | **1105** (90.1%) |
| Ruffle-matched | 30 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1135** (92.6%) |
| Failing | 91 |
| Total expected lines | 152155 |
| Matching lines | 120144 (79.0%) |
| Mismatched lines | 32011 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 91 | 100.0% |

## Passing Tests

**1105 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 26.1s |  |
| 2 | `accessibility` | 1 | 7.4s |  |
| 3 | `activation_class` | 6 | 7.4s |  |
| 4 | `add` | 1058 | 19.8s |  |
| 5 | `agal_compiler` | 13 | 10.0s |  |
| 6 | `air_datagram_socket` | 1 | 9.3s |  |
| 7 | `air_hidden_lookup` | 2 | 7.5s |  |
| 8 | `air_ifilepromise` | 1 | 7.7s |  |
| 9 | `all_classes/security/swf11` | 3 | 7.4s |  |
| 10 | `amf_array_serialization` | 17 | 9.7s |  |
| 11 | `amf_custom_obj` | 26 | 7.6s |  |
| 12 | `amf_dictionary` | 9 | 7.6s |  |
| 13 | `amf_function` | 46 | 7.7s |  |
| 14 | `amf_invalid_date` | 2 | 7.5s |  |
| 15 | `amf_missing_prop` | 6 | 7.5s |  |
| 16 | `amf_nondynamic_function_prop` | 6 | 7.6s |  |
| 17 | `amf_setter_error` | 8 | 7.6s |  |
| 18 | `amf_vector` | 40 | 7.7s |  |
| 19 | `amf_xml` | 6 | 7.5s |  |
| 20 | `application_domain` | 4 | 7.5s |  |
| 21 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.6s |  |
| 22 | `applicationdomain_hasdefinition_null` | 2 | 7.4s |  |
| 23 | `array_access` | 18 | 7.5s |  |
| 24 | `array_access_interpreter` | 4 | 7.5s |  |
| 25 | `array_access_no_pubns` | 2 | 7.4s |  |
| 26 | `array_concat` | 41 | 7.6s |  |
| 27 | `array_constr` | 10 | 7.5s |  |
| 28 | `array_delete` | 44 | 7.6s |  |
| 29 | `array_enumeration` | 10 | 7.5s |  |
| 30 | `array_enumeration_elements` | 11 | 7.5s |  |
| 31 | `array_every` | 8 | 7.5s |  |
| 32 | `array_filter` | 6 | 7.5s |  |
| 33 | `array_foreach` | 18 | 7.5s |  |
| 34 | `array_hasownproperty` | 11 | 3.1s |  |
| 35 | `array_holes` | 9 | 7.5s |  |
| 36 | `array_index_max` | 84 | 7.4s |  |
| 37 | `array_indexof` | 25 | 7.5s |  |
| 38 | `array_join` | 26 | 7.5s |  |
| 39 | `array_lastindexof` | 29 | 7.5s |  |
| 40 | `array_length` | 14 | 7.5s |  |
| 41 | `array_literal` | 3 | 7.4s |  |
| 42 | `array_map` | 8 | 7.4s |  |
| 43 | `array_pop` | 52 | 7.6s |  |
| 44 | `array_push` | 24 | 7.5s |  |
| 45 | `array_reborrow_bug` | 6 | 7.5s |  |
| 46 | `array_reverse` | 28 | 7.5s |  |
| 47 | `array_shift` | 51 | 3.2s |  |
| 48 | `array_slice` | 39 | 7.6s |  |
| 49 | `array_some` | 8 | 7.5s |  |
| 50 | `array_sort` | 297 | 8.0s |  |
| 51 | `array_sort_fun_swf12` | 2 | 7.5s |  |
| 52 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 53 | `array_sort_random` | 210 | 7.6s |  |
| 54 | `array_sort_swf10_32bit` | 1 | 7.5s |  |
| 55 | `array_sorton` | 545 | 8.4s |  |
| 56 | `array_sparse_ops` | 41 | 7.7s |  |
| 57 | `array_splice` | 133 | 7.8s |  |
| 58 | `array_splice2` | 428 | 7.8s |  |
| 59 | `array_splice_types` | 48 | 7.6s |  |
| 60 | `array_storage` | 8 | 7.5s |  |
| 61 | `array_tolocalestring` | 9 | 7.6s |  |
| 62 | `array_tostring` | 12 | 7.7s |  |
| 63 | `array_unshift` | 24 | 7.5s |  |
| 64 | `array_valueof` | 9 | 7.5s |  |
| 65 | `array_vector_null_callback` | 10 | 7.6s |  |
| 66 | `astype` | 28 | 7.6s |  |
| 67 | `astypelate` | 24 | 7.7s |  |
| 68 | `astypelate_propagates` | 1 | 7.6s |  |
| 69 | `asymmetric_key_events` | 11 | 8.0s |  |
| 70 | `av_classes` | 340 | 8.2s |  |
| 71 | `avm1movie_addcallback_call` | 14 | 7.9s |  |
| 72 | `avm2_catchup_dobj` | 158 | 8.4s |  |
| 73 | `away3d_advanced_shallow_water_demo` | 0 | 87.7s |  |
| 74 | `bevel_filter` | 187 | 7.7s |  |
| 75 | `bitand` | 1058 | 20.1s |  |
| 76 | `bitmap_constr` | 17 | 7.8s |  |
| 77 | `bitmap_data` | 1000 | 16.4s |  |
| 78 | `bitmap_pixelsnapping` | 2 | 28.2s |  |
| 79 | `bitmap_properties` | 23 | 7.8s |  |
| 80 | `bitmap_subclass` | 7 | 9.2s |  |
| 81 | `bitmap_subclass_properties` | 9 | 8.1s |  |
| 82 | `bitmap_timeline` | 9 | 7.9s |  |
| 83 | `bitmapdata_accuracy` | 1 | 47.3s |  |
| 84 | `bitmapdata_applyfilter_blur` | 0 | 27.6s |  |
| 85 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.4s |  |
| 86 | `bitmapdata_applyfilter_destpoint` | 0 | 27.6s |  |
| 87 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 27.5s |  |
| 88 | `bitmapdata_clone` | 13 | 7.8s |  |
| 89 | `bitmapdata_colortransform` | 0 | 8.1s |  |
| 90 | `bitmapdata_colortransform_oob` | 2 | 7.5s |  |
| 91 | `bitmapdata_constr` | 22 | 7.5s |  |
| 92 | `bitmapdata_constructor_from_timeline` | 1 | 7.9s |  |
| 93 | `bitmapdata_copychannel` | 0 | 29.1s |  |
| 94 | `bitmapdata_copypixels` | 23 | 27.7s |  |
| 95 | `bitmapdata_copypixels_blend_over` | 1 | 7.6s |  |
| 96 | `bitmapdata_copypixelstobytearray` | 39 | 7.5s |  |
| 97 | `bitmapdata_dispose` | 7 | 7.5s |  |
| 98 | `bitmapdata_draw` | 0 | 27.4s |  |
| 99 | `bitmapdata_draw_colortransform` | 0 | 7.7s |  |
| 100 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.2s |  |
| 101 | `bitmapdata_draw_filters` | 0 | 26.2s |  |
| 102 | `bitmapdata_draw_masks` | 0 | 7.9s |  |
| 103 | `bitmapdata_draw_rotation` | 0 | 7.7s |  |
| 104 | `bitmapdata_draw_self_via_graphic` | 0 | 7.7s |  |
| 105 | `bitmapdata_draw_stage` | 0 | 26.6s |  |
| 106 | `bitmapdata_drawwithquality` | 0 | 7.9s |  |
| 107 | `bitmapdata_embedded` | 9 | 7.8s |  |
| 108 | `bitmapdata_fillrect` | 0 | 7.7s |  |
| 109 | `bitmapdata_filter_sourcerect` | 0 | 26.8s |  |
| 110 | `bitmapdata_floodfill` | 35 | 7.5s |  |
| 111 | `bitmapdata_getpixels` | 39 | 27.2s |  |
| 112 | `bitmapdata_getvector` | 27 | 3.4s |  |
| 113 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 114 | `bitmapdata_hittest` | 112 | 8.2s |  |
| 115 | `bitmapdata_hittest_threshold` | 18 | 7.7s |  |
| 116 | `bitmapdata_opaque` | 0 | 7.8s |  |
| 117 | `bitmapdata_pixeldissolve` | 1037 | 8.1s |  |
| 118 | `bitmapdata_pixeldissolve_image` | 0 | 7.9s |  |
| 119 | `bitmapdata_rectangle_rounding` | 16 | 7.5s |  |
| 120 | `bitmapdata_setpixels` | 286 | 7.7s |  |
| 121 | `bitmapdata_setvector` | 26 | 7.6s |  |
| 122 | `bitmapdata_sync` | 0 | 26.5s |  |
| 123 | `bitmapdata_threshold` | 176 | 8.3s |  |
| 124 | `bitmapdata_zero_size` | 8 | 7.6s |  |
| 125 | `bitnot` | 46 | 7.7s |  |
| 126 | `bitor` | 1058 | 20.3s |  |
| 127 | `bitxor` | 1058 | 20.1s |  |
| 128 | `blend_mode_null` | 1 | 7.5s |  |
| 129 | `blend_multiply_alpha` | 0 | 7.7s |  |
| 130 | `blend_scroll` | 0 | 7.7s |  |
| 131 | `blend_shader_luma_lighten` | 3 | 8.4s |  |
| 132 | `blur_filter` | 43 | 7.6s |  |
| 133 | `boolean_constr` | 32 | 7.5s |  |
| 134 | `boolean_negation` | 30 | 7.4s |  |
| 135 | `boolean_tostring` | 8 | 7.4s |  |
| 136 | `broadcast_event` | 7 | 7.6s |  |
| 137 | `button_bounds` | 1 | 7.5s |  |
| 138 | `button_hittest` | 2 | 25.8s |  |
| 139 | `button_nested_frame` | 48 | 26.5s |  |
| 140 | `bytearray` | 48 | 7.7s |  |
| 141 | `bytearray_compress` | 31 | 7.4s |  |
| 142 | `bytearray_errors` | 24 | 7.5s |  |
| 143 | `bytearray_method_serialization` | 1 | 7.4s |  |
| 144 | `bytearray_oom` | 3 | 7.5s |  |
| 145 | `bytearray_readobject_amf0` | 50 | 7.4s |  |
| 146 | `bytearray_readobject_amf3` | 53 | 7.5s |  |
| 147 | `bytearray_readutf8bytes_with_bom` | 16 | 7.5s |  |
| 148 | `bytearray_serialization` | 3 | 7.5s |  |
| 149 | `bytearray_string_null` | 19 | 7.7s |  |
| 150 | `bytearray_tostring` | 15 | 7.4s |  |
| 151 | `bytearray_utf16` | 8 | 7.3s |  |
| 152 | `bytearray_writeobject` | 24 | 7.3s |  |
| 153 | `callee_in_initializer` | 6 | 7.3s |  |
| 154 | `callproplex_class` | 1 | 7.4s |  |
| 155 | `capabilities_resolution` | 8 | 27.3s |  |
| 156 | `catch_class` | 6 | 7.4s |  |
| 157 | `catch_scope_slot` | 7 | 3.2s |  |
| 158 | `checkfilter` | 4 | 3.1s |  |
| 159 | `class_call` | 32 | 7.7s |  |
| 160 | `class_cast_call` | 14 | 7.5s |  |
| 161 | `class_enumeration` | 4 | 7.5s |  |
| 162 | `class_has_own_property` | 2 | 7.5s |  |
| 163 | `class_init_interpreter_mode` | 1 | 7.3s |  |
| 164 | `class_is` | 32 | 7.7s |  |
| 165 | `class_methods` | 5 | 7.5s |  |
| 166 | `class_object_properties` | 10 | 7.5s |  |
| 167 | `class_singleton` | 18 | 7.5s |  |
| 168 | `class_supercalls_errors` | 35 | 7.7s |  |
| 169 | `class_supercalls_mismatched` | 26 | 7.6s |  |
| 170 | `class_superclass_wrong_order` | 1 | 26.2s |  |
| 171 | `class_to_locale_string` | 2 | 7.6s |  |
| 172 | `class_to_string` | 2 | 7.4s |  |
| 173 | `class_value_of` | 2 | 7.4s |  |
| 174 | `click_block` | 5 | 8.4s |  |
| 175 | `click_invisible` | 3 | 7.7s |  |
| 176 | `closures` | 12 | 7.5s |  |
| 177 | `coerce_return_type` | 40 | 7.6s |  |
| 178 | `coerce_return_type_fail` | 2 | 7.5s |  |
| 179 | `coerce_return_void` | 3 | 7.4s |  |
| 180 | `coerce_string` | 86 | 7.7s |  |
| 181 | `coerce_string_precision` | 28 | 7.5s |  |
| 182 | `coerce_to_primitive_side_effects` | 29 | 26.5s |  |
| 183 | `color_matrix_filter` | 19 | 7.6s |  |
| 184 | `construct_errors_swf10` | 8 | 7.5s |  |
| 185 | `construct_frame_list` | 22 | 26.7s |  |
| 186 | `construct_interface` | 3 | 7.5s |  |
| 187 | `constructor_call` | 3 | 7.5s |  |
| 188 | `constructors_vs_timeline` | 5 | 26.6s |  |
| 189 | `constructprop_dynamic_primitive` | 7 | 7.5s |  |
| 190 | `constructprop_method` | 2 | 7.5s |  |
| 191 | `constructsuper_null` | 2 | 3.1s |  |
| 192 | `content_element_basic` | 50 | 7.9s |  |
| 193 | `context3d_creation` | 9 | 7.5s |  |
| 194 | `control_flow_bool` | 4 | 7.4s |  |
| 195 | `control_flow_stricteq` | 8 | 7.5s |  |
| 196 | `convert_boolean` | 30 | 7.5s |  |
| 197 | `convert_integer` | 90 | 7.6s |  |
| 198 | `convert_number` | 56 | 7.6s |  |
| 199 | `convert_uinteger` | 90 | 7.7s |  |
| 200 | `convolution_filter` | 89 | 7.6s |  |
| 201 | `core_exceptions` | 47 | 8.4s |  |
| 202 | `cpool_index_invalid_bytecode_1` | 6 | 7.5s |  |
| 203 | `cpool_index_invalid_bytecode_2` | 3 | 7.4s |  |
| 204 | `cpool_index_invalid_bytecode_3` | 1 | 7.4s |  |
| 205 | `cross_api_version_call_newer` | 12 | 8.1s |  |
| 206 | `cross_api_version_call_older` | 12 | 7.8s |  |
| 207 | `cryptscore` | 11 | 7.5s |  |
| 208 | `currency_parse_result` | 7 | 7.5s |  |
| 209 | `date` | 30 | 8.5s |  |
| 210 | `date_parse` | 36 | 8.0s |  |
| 211 | `declocal` | 46 | 8.1s |  |
| 212 | `declocal_i` | 46 | 8.0s |  |
| 213 | `decode_uri` | 71 | 8.3s |  |
| 214 | `decrement` | 46 | 7.9s |  |
| 215 | `decrement_i` | 46 | 3.4s |  |
| 216 | `default_values` | 7 | 7.8s |  |
| 217 | `dictionary_access` | 62 | 8.2s |  |
| 218 | `dictionary_access_no_pubns` | 2 | 7.9s |  |
| 219 | `dictionary_delete` | 101 | 8.4s |  |
| 220 | `dictionary_foreach` | 42 | 8.2s |  |
| 221 | `dictionary_hasownproperty` | 63 | 8.2s |  |
| 222 | `dictionary_in` | 62 | 8.1s |  |
| 223 | `dictionary_iter_modify` | 8 | 7.9s |  |
| 224 | `dictionary_namespaces` | 36 | 7.9s |  |
| 225 | `dictionary_primitive_keys` | 29 | 7.8s |  |
| 226 | `displacement_map_filter` | 61 | 7.8s |  |
| 227 | `displayobject_alpha` | 277 | 7.5s |  |
| 228 | `displayobject_blendmode` | 0 | 8.8s |  |
| 229 | `displayobject_colortransform_nested` | 0 | 27.4s |  |
| 230 | `displayobject_filters` | 17 | 7.8s |  |
| 231 | `displayobject_from_enterframe` | 1 | 27.7s |  |
| 232 | `displayobject_getbounds_shape` | 0 | 27.2s |  |
| 233 | `displayobject_height` | 6052 | 27.4s |  |
| 234 | `displayobject_hittestobject` | 32 | 7.8s |  |
| 235 | `displayobject_hittestpoint` | 49 | 8.1s |  |
| 236 | `displayobject_hittestpoint_root` | 13 | 8.1s |  |
| 237 | `displayobject_invalid_floats` | 60 | 7.9s |  |
| 238 | `displayobject_invalid_props` | 3 | 7.8s |  |
| 239 | `displayobject_mask` | 3 | 8.3s |  |
| 240 | `displayobject_mask_self_referential` | 0 | 27.8s |  |
| 241 | `displayobject_metaData` | 3 | 7.9s |  |
| 242 | `displayobject_name` | 22 | 27.2s |  |
| 243 | `displayobject_name_from_timeline` | 24 | 7.9s |  |
| 244 | `displayobject_opaque_background` | 6 | 29.1s |  |
| 245 | `displayobject_parent` | 12 | 7.7s |  |
| 246 | `displayobject_root` | 24 | 8.0s |  |
| 247 | `displayobject_rotation` | 1284 | 8.1s |  |
| 248 | `displayobject_set_matrix_nested` | 0 | 28.3s |  |
| 249 | `displayobject_set_name_loaded` | 3 | 8.1s |  |
| 250 | `displayobject_subclass` | 2 | 7.8s |  |
| 251 | `displayobject_visible` | 23 | 7.7s |  |
| 252 | `displayobject_width` | 4852 | 27.9s |  |
| 253 | `displayobject_x` | 614 | 7.6s |  |
| 254 | `displayobject_y` | 617 | 7.7s |  |
| 255 | `displayobjectcontainer_addchild` | 32 | 7.8s |  |
| 256 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.6s |  |
| 257 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.8s |  |
| 258 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.7s |  |
| 259 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.7s |  |
| 260 | `displayobjectcontainer_addchildat` | 42 | 7.7s |  |
| 261 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.9s |  |
| 262 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.9s |  |
| 263 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.0s |  |
| 264 | `displayobjectcontainer_contains` | 66 | 28.3s |  |
| 265 | `displayobjectcontainer_getchildat` | 4 | 7.7s |  |
| 266 | `displayobjectcontainer_getchildbyname` | 9 | 7.6s |  |
| 267 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.7s |  |
| 268 | `displayobjectcontainer_getchildindex` | 28 | 7.7s |  |
| 269 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.8s |  |
| 270 | `displayobjectcontainer_removechild` | 10 | 7.6s |  |
| 271 | `displayobjectcontainer_removechild_errors` | 4 | 7.6s |  |
| 272 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.7s |  |
| 273 | `displayobjectcontainer_removechildat` | 18 | 7.6s |  |
| 274 | `displayobjectcontainer_removechildren` | 51 | 7.8s |  |
| 275 | `displayobjectcontainer_setchildindex` | 42 | 7.5s |  |
| 276 | `displayobjectcontainer_stopallmovieclips` | 2 | 27.3s |  |
| 277 | `displayobjectcontainer_swapchildren` | 42 | 7.7s |  |
| 278 | `displayobjectcontainer_swapchildrenat` | 42 | 7.6s |  |
| 279 | `displayobjectcontainer_timelineinstance` | 48 | 27.9s |  |
| 280 | `divide` | 1058 | 20.4s |  |
| 281 | `doabc_and_symbolclass_script_init_goto` | 7 | 28.1s |  |
| 282 | `doabc_and_symbolclass_script_init_normal` | 6 | 7.8s |  |
| 283 | `doabc_is_eager` | 1 | 27.6s |  |
| 284 | `documentclass` | 9 | 8.2s |  |
| 285 | `domain_memory` | 133 | 30.1s |  |
| 286 | `drag_drop` | 10 | 8.3s |  |
| 287 | `drop_shadow_filter` | 172 | 8.2s |  |
| 288 | `duplicate_defs` | 1 | 7.8s |  |
| 289 | `eager_init` | 1 | 7.8s |  |
| 290 | `east_asian_justifier_clone` | 8 | 3.4s |  |
| 291 | `edit_text_linkage` | 7 | 8.1s |  |
| 292 | `edittext_align` | 60 | 8.6s |  |
| 293 | `edittext_always_show_selection` | 0 | 29.9s |  |
| 294 | `edittext_antialiastype` | 296 | 8.3s |  |
| 295 | `edittext_at_point_methods_basic` | 16 | 9.7s |  |
| 296 | `edittext_autosize` | 39 | 8.6s |  |
| 297 | `edittext_autosize_align` | 0 | 29.4s |  |
| 298 | `edittext_autosize_height_dynamic` | 60 | 29.3s |  |
| 299 | `edittext_autosize_height_input` | 60 | 8.4s |  |
| 300 | `edittext_autosize_lazy_bounds_events` | 65 | 8.6s |  |
| 301 | `edittext_autosize_lazy_bounds_interactions` | 19 | 8.2s |  |
| 302 | `edittext_autosize_lazy_bounds_props` | 490 | 9.7s |  |
| 303 | `edittext_autosize_lazy_bounds_visual` | 0 | 29.1s |  |
| 304 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 8.4s |  |
| 305 | `edittext_bottom_scroll_v_basic` | 210 | 8.4s |  |
| 306 | `edittext_bounds_scale` | 24 | 29.4s |  |
| 307 | `edittext_bullet` | 30 | 8.2s |  |
| 308 | `edittext_default_format` | 221 | 8.3s |  |
| 309 | `edittext_default_format_empty` | 136 | 8.4s |  |
| 310 | `edittext_empty_text_format` | 7 | 8.2s |  |
| 311 | `edittext_focus_selection` | 5 | 8.1s |  |
| 312 | `edittext_font_size` | 45 | 8.4s |  |
| 313 | `edittext_format_empty_font` | 8 | 8.1s |  |
| 314 | `edittext_get_char_index_at_point` | 4 | 31.2s |  |
| 315 | `edittext_get_line_index_at_point` | 2 | 30.8s |  |
| 316 | `edittext_get_line_index_of_char` | 76 | 9.3s |  |
| 317 | `edittext_getcharboundaries` | 172 | 8.7s |  |
| 318 | `edittext_getcharboundaries_missing_glyphs` | 63 | 8.3s |  |
| 319 | `edittext_getcharboundaries_scroll` | 85 | 28.0s |  |
| 320 | `edittext_getlinemetrics` | 146 | 8.3s |  |
| 321 | `edittext_html` | 3101 | 8.4s |  |
| 322 | `edittext_html_condensewhite` | 487 | 8.0s |  |
| 323 | `edittext_html_entity` | 4 | 8.2s |  |
| 324 | `edittext_html_font_size_swf12` | 267 | 7.9s |  |
| 325 | `edittext_html_font_size_swf13` | 273 | 7.6s |  |
| 326 | `edittext_html_roundtrip` | 17 | 8.0s |  |
| 327 | `edittext_ime_focus_lost` | 9 | 28.3s |  |
| 328 | `edittext_input_control` | 12 | 8.1s |  |
| 329 | `edittext_leading` | 9 | 8.2s |  |
| 330 | `edittext_letter_spacing` | 15 | 7.9s |  |
| 331 | `edittext_line_methods` | 294 | 9.4s |  |
| 332 | `edittext_line_metrics` | 11 | 29.3s |  |
| 333 | `edittext_margins` | 25 | 7.8s |  |
| 334 | `edittext_max_scroll_h_basic` | 475 | 7.8s |  |
| 335 | `edittext_max_scroll_v_basic` | 1000 | 7.8s |  |
| 336 | `edittext_mouse_selection` | 363 | 29.3s |  |
| 337 | `edittext_mousedown` | 3 | 8.4s |  |
| 338 | `edittext_mouseenabled` | 26 | 8.0s |  |
| 339 | `edittext_newline_character` | 22 | 7.9s |  |
| 340 | `edittext_newline_stripping` | 64 | 10.6s |  |
| 341 | `edittext_newlines` | 30 | 8.0s |  |
| 342 | `edittext_paragraph_methods` | 257 | 7.9s |  |
| 343 | `edittext_paste_events` | 8 | 8.2s |  |
| 344 | `edittext_paste_maxchars` | 4 | 7.9s |  |
| 345 | `edittext_paste_restrict` | 16 | 7.7s |  |
| 346 | `edittext_restrict` | 191 | 7.8s |  |
| 347 | `edittext_restrict_events` | 22 | 7.8s |  |
| 348 | `edittext_scrollh` | 10 | 7.8s |  |
| 349 | `edittext_selected_text` | 9 | 7.8s |  |
| 350 | `edittext_set_html_same` | 17 | 8.0s |  |
| 351 | `edittext_set_text_vs_html` | 9 | 7.8s |  |
| 352 | `edittext_stylesheet` | 536 | 8.3s |  |
| 353 | `edittext_stylesheet_custom_tag` | 76 | 8.0s |  |
| 354 | `edittext_stylesheet_display` | 272 | 8.0s |  |
| 355 | `edittext_underline` | 40 | 7.9s |  |
| 356 | `edittext_width_height` | 103 | 25.0s |  |
| 357 | `edittext_wordwrap_word` | 150 | 26.8s |  |
| 358 | `edittext_wrap_breaks` | 2375 | 8.2s |  |
| 359 | `element_format_clone` | 44 | 7.9s |  |
| 360 | `element_format_constructor_order` | 64 | 8.0s |  |
| 361 | `element_format_properties` | 235 | 8.6s |  |
| 362 | `empty_bounds` | 1 | 7.6s |  |
| 363 | `encode_uri_surrogate_pair_invalid` | 8 | 7.7s |  |
| 364 | `encode_uri_surrogate_pair_swf11` | 15 | 7.4s |  |
| 365 | `equals` | 512 | 11.3s |  |
| 366 | `error_geterrormessage` | 779 | 7.8s |  |
| 367 | `error_prototype` | 15 | 7.7s |  |
| 368 | `error_stack_trace_debug_swf17` | 0 | 26.5s |  |
| 369 | `error_stack_trace_debug_swf18` | 0 | 7.4s |  |
| 370 | `error_stack_trace_edge_cases` | 6 | 7.7s |  |
| 371 | `error_stack_trace_release_swf17` | 0 | 7.4s |  |
| 372 | `error_stack_trace_release_swf18` | 0 | 7.3s |  |
| 373 | `error_throwerror` | 103 | 7.7s |  |
| 374 | `error_tostring` | 29 | 7.6s |  |
| 375 | `error_tostring_more` | 86 | 7.7s |  |
| 376 | `es3_inheritance` | 31 | 7.7s |  |
| 377 | `es4_inheritance` | 30 | 7.7s |  |
| 378 | `es4_interfaces` | 30 | 7.7s |  |
| 379 | `es4_method_binding` | 8 | 7.7s |  |
| 380 | `es4_oop_prototypes` | 14 | 7.8s |  |
| 381 | `es4_protected_inheritance` | 6 | 7.6s |  |
| 382 | `escape` | 71 | 7.7s |  |
| 383 | `escape_multi_byte` | 45 | 7.8s |  |
| 384 | `event_bubbles` | 2 | 7.6s |  |
| 385 | `event_cancelable` | 2 | 7.5s |  |
| 386 | `event_clone` | 20 | 7.7s |  |
| 387 | `event_clone_error_redispatch` | 3 | 7.8s |  |
| 388 | `event_clone_on_redispatch` | 10 | 7.8s |  |
| 389 | `event_formattostring` | 31 | 7.7s |  |
| 390 | `event_isdefaultprevented` | 12 | 7.6s |  |
| 391 | `event_target_getter` | 5 | 3.2s |  |
| 392 | `event_target_set` | 9 | 7.5s |  |
| 393 | `event_type` | 1 | 25.1s |  |
| 394 | `event_valueof_tostring` | 18 | 8.0s |  |
| 395 | `eventdispatcher_dispatchevent` | 12 | 7.9s |  |
| 396 | `eventdispatcher_dispatchevent_cancel` | 20 | 28.2s |  |
| 397 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 8.0s |  |
| 398 | `eventdispatcher_dispatchevent_indirect` | 9 | 8.4s |  |
| 399 | `eventdispatcher_dispatchevent_this` | 5 | 8.0s |  |
| 400 | `eventdispatcher_haseventlistener` | 25 | 8.1s |  |
| 401 | `eventdispatcher_interface_invoke` | 1 | 7.9s |  |
| 402 | `eventdispatcher_tostring` | 10 | 8.1s |  |
| 403 | `eventdispatcher_willtrigger` | 25 | 8.0s |  |
| 404 | `falsiness` | 30 | 8.0s |  |
| 405 | `fast_index_access` | 12 | 8.1s |  |
| 406 | `filefilter_properties` | 4 | 7.9s |  |
| 407 | `filereference_browse_cancel` | 3 | 7.9s |  |
| 408 | `filereference_browse_select` | 9 | 7.9s |  |
| 409 | `filereference_load` | 31 | 7.9s |  |
| 410 | `filereference_save` | 16 | 7.9s |  |
| 411 | `filereference_save_and_browse` | 42 | 8.0s |  |
| 412 | `filereference_save_and_load` | 22 | 8.0s |  |
| 413 | `filereference_uninitialized` | 8 | 7.9s |  |
| 414 | `filereferencelist_browse_cancel` | 6 | 7.7s |  |
| 415 | `filereferencelist_browse_select` | 7 | 7.7s |  |
| 416 | `filter_rewind` | 8 | 8.1s |  |
| 417 | `filters_array_holes` | 25 | 8.9s |  |
| 418 | `finddef` | 3 | 7.8s |  |
| 419 | `findprop_global_prototype` | 6 | 8.0s |  |
| 420 | `flash_media_video_constructor` | 156 | 8.7s |  |
| 421 | `flash_media_video_rotation_probe` | 27 | 8.0s |  |
| 422 | `flash_media_video_setter` | 40 | 8.3s |  |
| 423 | `flash_trace` | 17 | 7.9s |  |
| 424 | `flash_xml` | 29 | 8.2s |  |
| 425 | `flash_xml_cloneNode` | 22 | 7.7s |  |
| 426 | `flash_xml_namespace` | 109 | 7.8s |  |
| 427 | `flash_xml_removeNode` | 60 | 7.8s |  |
| 428 | `focus_events_code` | 161 | 26.6s |  |
| 429 | `focus_events_key_basic` | 132 | 26.7s |  |
| 430 | `focus_events_key_navigation` | 53 | 7.5s |  |
| 431 | `focus_events_key_same_object` | 26 | 7.5s |  |
| 432 | `focus_events_mixed_key_mouse` | 100 | 44.2s |  |
| 433 | `focus_events_mouse_basic` | 260 | 27.5s |  |
| 434 | `focus_events_mouse_focusable` | 112 | 27.3s |  |
| 435 | `focus_events_mouse_same_object` | 40 | 27.0s |  |
| 436 | `focus_remove` | 20 | 27.5s |  |
| 437 | `focus_root_movie` | 4 | 30.7s |  |
| 438 | `focus_stage` | 1 | 7.6s |  |
| 439 | `focusrect` | 18 | 8.6s |  |
| 440 | `focusrect_focuslost` | 9 | 7.7s |  |
| 441 | `focusrect_property` | 110 | 27.9s |  |
| 442 | `font_description_clone` | 14 | 7.9s |  |
| 443 | `font_embedded` | 24 | 8.4s |  |
| 444 | `font_enumeratefonts` | 41 | 8.5s |  |
| 445 | `font_enumeratefonts_filter` | 4 | 29.1s |  |
| 446 | `font_enumeratefonts_order` | 9 | 9.4s |  |
| 447 | `font_hasglyphs` | 40 | 8.5s |  |
| 448 | `font_registerfont` | 129 | 9.0s |  |
| 449 | `framelabel_constr` | 5 | 8.3s |  |
| 450 | `function_call` | 12 | 8.1s |  |
| 451 | `function_call_arguments` | 46 | 8.2s |  |
| 452 | `function_call_arguments_enumerate` | 5 | 8.0s |  |
| 453 | `function_call_coercion` | 108 | 8.4s |  |
| 454 | `function_call_default` | 6 | 8.0s |  |
| 455 | `function_call_rest` | 22 | 8.1s |  |
| 456 | `function_call_types` | 3 | 7.9s |  |
| 457 | `function_call_via_apply` | 11 | 7.9s |  |
| 458 | `function_call_via_call` | 3 | 7.9s |  |
| 459 | `function_display_anonymous` | 7 | 3.4s |  |
| 460 | `function_length` | 6 | 7.9s |  |
| 461 | `function_object` | 2 | 7.9s |  |
| 462 | `function_proto` | 5 | 7.9s |  |
| 463 | `function_proto_created` | 61 | 8.0s |  |
| 464 | `function_to_locale_string` | 4 | 7.8s |  |
| 465 | `function_to_string` | 4 | 7.8s |  |
| 466 | `function_type` | 6 | 7.9s |  |
| 467 | `function_unbound_this` | 51 | 7.9s |  |
| 468 | `function_value_of` | 4 | 7.8s |  |
| 469 | `game_input` | 4 | 7.9s |  |
| 470 | `generate_random_bytes` | 3 | 7.8s |  |
| 471 | `get_definition_by_name` | 11 | 25.1s |  |
| 472 | `get_qualified_class_name` | 20 | 7.7s |  |
| 473 | `get_qualified_super_class_name` | 18 | 7.8s |  |
| 474 | `get_slot_edge_cases` | 1 | 27.5s |  |
| 475 | `get_timer` | 2 | 7.8s |  |
| 476 | `getglobalslot` | 1 | 7.8s |  |
| 477 | `getouterscope` | 8 | 7.7s |  |
| 478 | `getouterscope_two_classobjects` | 13 | 7.7s |  |
| 479 | `getter_different_namespace_setter` | 2 | 7.6s |  |
| 480 | `glow_filter` | 127 | 7.9s |  |
| 481 | `goto_button_nested_framescript` | 28 | 27.8s |  |
| 482 | `goto_in_constructframe` | 12 | 28.0s |  |
| 483 | `goto_in_scene_last_frame` | 2 | 27.2s |  |
| 484 | `goto_methods` | 56 | 8.0s |  |
| 485 | `goto_methods_swfver10` | 8 | 7.7s |  |
| 486 | `goto_nested_construct_sibling` | 18 | 8.3s |  |
| 487 | `goto_nested_framescript` | 9 | 8.0s |  |
| 488 | `goto_on_orphan` | 15 | 8.0s |  |
| 489 | `gradient_bevel_filter` | 206 | 7.9s |  |
| 490 | `gradient_glow_filter` | 206 | 7.7s |  |
| 491 | `graphic_linkage` | 9 | 7.9s |  |
| 492 | `graphics_bad_direct_commands` | 5 | 11.5s |  |
| 493 | `graphics_bitmap_fill` | 0 | 29.6s |  |
| 494 | `graphics_bitmaps` | 0 | 8.5s |  |
| 495 | `graphics_direct_commands` | 0 | 8.6s |  |
| 496 | `graphics_draw_triangles` | 98 | 28.9s |  |
| 497 | `graphics_gradients` | 0 | 8.1s |  |
| 498 | `graphics_gradients_nulls` | 0 | 8.1s |  |
| 499 | `graphics_path` | 56 | 8.1s |  |
| 500 | `graphics_round_rects` | 0 | 7.7s |  |
| 501 | `graphics_simple_shapes` | 0 | 8.1s |  |
| 502 | `greaterequals` | 512 | 12.2s |  |
| 503 | `greaterthan` | 512 | 12.2s |  |
| 504 | `has_own_property` | 102 | 8.4s |  |
| 505 | `hasownproperty_namespaces` | 2 | 7.8s |  |
| 506 | `hello_world` | 1 | 7.8s |  |
| 507 | `hittest_morph` | 30 | 7.8s |  |
| 508 | `if_eq` | 10 | 19.8s |  |
| 509 | `if_gt` | 1 | 6.1s |  |
| 510 | `if_gte` | 10 | 2.6s |  |
| 511 | `if_lt` | 1 | 1.0s |  |
| 512 | `if_lte` | 10 | 6.0s |  |
| 513 | `if_ne` | 7 | 2.6s |  |
| 514 | `if_stricteq` | 6 | 6.0s |  |
| 515 | `if_strictne` | 11 | 6.1s |  |
| 516 | `ime_linux_dead_keys` | 10 | 21.2s |  |
| 517 | `in` | 102 | 6.4s |  |
| 518 | `inclocal` | 46 | 6.0s |  |
| 519 | `inclocal_i` | 46 | 6.1s |  |
| 520 | `increment` | 46 | 6.0s |  |
| 521 | `increment_i` | 46 | 6.0s |  |
| 522 | `indexing_delete` | 75 | 6.1s |  |
| 523 | `instanceof` | 58 | 6.3s |  |
| 524 | `instantiate_root_character` | 4 | 6.3s |  |
| 525 | `instantiation_on_enter_frame` | 7 | 20.9s |  |
| 526 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.0s |  |
| 527 | `int_constr` | 92 | 6.3s |  |
| 528 | `int_edge_cases` | 19 | 6.2s |  |
| 529 | `int_instanceof` | 3 | 5.9s |  |
| 530 | `int_tofixed` | 1215 | 5.9s |  |
| 531 | `int_tostring` | 3375 | 6.2s |  |
| 532 | `interactiveobject_enabled` | 25 | 5.9s |  |
| 533 | `interface_namespaces` | 78 | 6.2s |  |
| 534 | `invalid_utf8` | 12 | 6.1s |  |
| 535 | `is_finite` | 46 | 6.1s |  |
| 536 | `is_nan` | 46 | 6.0s |  |
| 537 | `is_prototype_of` | 12 | 6.0s |  |
| 538 | `issue_10221` | 2 | 6.0s |  |
| 539 | `issue_13780` | 12 | 6.0s |  |
| 540 | `issue_14901` | 1 | 6.1s |  |
| 541 | `issue_17675_edittext_paste_maxchars` | 1 | 6.1s |  |
| 542 | `issue_5292` | 5 | 6.0s |  |
| 543 | `issue_8630` | 2 | 20.8s |  |
| 544 | `issue_8630_placeremoveplace` | 15 | 6.2s |  |
| 545 | `issue_8630_placeremoveplace_scriptremove` | 16 | 6.0s |  |
| 546 | `issue_8630_scriptremove` | 11 | 6.0s |  |
| 547 | `istype` | 24 | 25.4s |  |
| 548 | `istypelate` | 58 | 8.1s |  |
| 549 | `istypelate_coerce` | 198 | 8.8s |  |
| 550 | `jpeg_loader_context` | 6 | 27.3s |  |
| 551 | `json_errors` | 9 | 27.4s |  |
| 552 | `json_parse` | 21 | 7.7s |  |
| 553 | `json_stringify` | 12 | 8.2s |  |
| 554 | `json_stringify_function` | 12 | 7.9s |  |
| 555 | `json_stringify_order` | 1 | 8.0s |  |
| 556 | `json_version_gated` | 1 | 7.9s |  |
| 557 | `key_input_80percent` | 1812 | 8.2s |  |
| 558 | `key_input_location` | 126 | 8.1s |  |
| 559 | `key_input_numpad` | 384 | 8.0s |  |
| 560 | `lazyinit` | 17 | 7.9s |  |
| 561 | `lessequals` | 512 | 11.6s |  |
| 562 | `lessthan` | 512 | 11.7s |  |
| 563 | `loader_bitmap_transparency` | 14 | 8.1s |  |
| 564 | `loader_bytes_unknown_content` | 14 | 7.9s |  |
| 565 | `loader_child_getdefinition` | 5 | 8.1s |  |
| 566 | `loader_duplicate_coerce` | 3 | 8.1s |  |
| 567 | `loader_duplicate_coerce_new_domain` | 4 | 7.9s |  |
| 568 | `loader_error_in_root_ctor` | 4 | 8.1s |  |
| 569 | `loader_events` | 92 | 11.7s |  |
| 570 | `loader_image` | 8 | 8.5s |  |
| 571 | `loader_jpegxr` | 2 | 28.0s |  |
| 572 | `loader_jpegxr_alpha` | 1 | 27.7s |  |
| 573 | `loader_loadbytes_events` | 30 | 8.6s |  |
| 574 | `loader_loadbytes_invalid_png` | 4 | 28.0s |  |
| 575 | `loader_loadbytes_url` | 12 | 8.3s |  |
| 576 | `loader_loaderurl` | 6 | 8.4s |  |
| 577 | `loader_method` | 85 | 7.9s |  |
| 578 | `loader_noninteractive_try_click_root` | 5 | 27.8s |  |
| 579 | `loader_reuse` | 38 | 8.1s |  |
| 580 | `loader_unknown_content` | 24 | 8.1s |  |
| 581 | `loader_visibility_interactive` | 1 | 43.9s |  |
| 582 | `loaderinfo_events` | 7 | 26.6s |  |
| 583 | `loaderinfo_loadurl` | 12 | 27.2s |  |
| 584 | `loaderinfo_more` | 6 | 7.5s |  |
| 585 | `loaderinfo_properties` | 18 | 7.3s |  |
| 586 | `loaderinfo_properties_not_loaded` | 23 | 7.6s |  |
| 587 | `loaderinfo_root` | 10 | 7.4s |  |
| 588 | `loaderinfo_root_allows` | 2 | 7.2s |  |
| 589 | `localconnection_send` | 4 | 7.2s |  |
| 590 | `lshift` | 1058 | 19.1s |  |
| 591 | `mask_reapply` | 1 | 7.3s |  |
| 592 | `math` | 497 | 7.5s |  |
| 593 | `matrix3d` | 57 | 8.2s |  |
| 594 | `matrix3d_compose` | 34 | 7.6s |  |
| 595 | `matrix3d_invert` | 18 | 7.3s |  |
| 596 | `method_without_body` | 3 | 27.0s |  |
| 597 | `missing_external_interface` | 10 | 7.3s |  |
| 598 | `modulo` | 1058 | 19.3s |  |
| 599 | `morph_shape` | 2 | 27.5s |  |
| 600 | `mouse_children` | 192 | 27.2s |  |
| 601 | `mouse_click_events` | 90 | 26.4s |  |
| 602 | `mouse_double_click_events` | 188 | 7.2s |  |
| 603 | `mouse_empty_parent` | 4 | 7.2s |  |
| 604 | `mouse_over_while_dragging` | 3 | 7.3s |  |
| 605 | `mouse_pick_button_mode` | 2 | 7.4s |  |
| 606 | `mouse_pick_dobj_mask` | 4 | 7.6s |  |
| 607 | `mouse_pick_masking` | 7 | 26.9s |  |
| 608 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.8s |  |
| 609 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.4s |  |
| 610 | `mouse_pick_text` | 8 | 7.4s |  |
| 611 | `mouse_sibling` | 8 | 7.2s |  |
| 612 | `mouse_wheel_events` | 36 | 28.0s |  |
| 613 | `mouseevent_constr` | 66 | 7.2s |  |
| 614 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 615 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 616 | `movieclip_addframescript` | 3 | 43.2s |  |
| 617 | `movieclip_child_property` | 16 | 7.5s |  |
| 618 | `movieclip_constr` | 21 | 7.2s |  |
| 619 | `movieclip_currentlabels` | 17 | 25.0s |  |
| 620 | `movieclip_currentlabels_dupes1` | 46 | 24.4s |  |
| 621 | `movieclip_currentlabels_dupes2` | 30 | 7.9s |  |
| 622 | `movieclip_currentlabels_dupes3` | 67 | 7.1s |  |
| 623 | `movieclip_currentscene` | 12 | 25.8s |  |
| 624 | `movieclip_dispatchevent` | 430 | 7.6s |  |
| 625 | `movieclip_dispatchevent_cancel` | 102 | 7.4s |  |
| 626 | `movieclip_dispatchevent_handlerorder` | 251 | 7.4s |  |
| 627 | `movieclip_dispatchevent_selfadd` | 80 | 7.1s |  |
| 628 | `movieclip_dispatchevent_target` | 899 | 7.4s |  |
| 629 | `movieclip_displayevents` | 96 | 26.0s |  |
| 630 | `movieclip_displayevents_clickgoto` | 676 | 26.6s |  |
| 631 | `movieclip_displayevents_clickgoto2` | 2001 | 8.0s |  |
| 632 | `movieclip_displayevents_clickplay` | 575 | 7.1s |  |
| 633 | `movieclip_displayevents_clicksymbol` | 562 | 7.2s |  |
| 634 | `movieclip_displayevents_constructframegoto` | 140 | 7.7s |  |
| 635 | `movieclip_displayevents_constructframeplay` | 50 | 7.1s |  |
| 636 | `movieclip_displayevents_constructframesymbol` | 144 | 7.5s |  |
| 637 | `movieclip_displayevents_dblhandler` | 21 | 7.3s |  |
| 638 | `movieclip_displayevents_enterframegoto` | 149 | 7.2s |  |
| 639 | `movieclip_displayevents_enterframeplay` | 48 | 6.9s |  |
| 640 | `movieclip_displayevents_enterframesymbol` | 149 | 23.3s |  |
| 641 | `movieclip_displayevents_exitframegoto` | 106 | 6.4s |  |
| 642 | `movieclip_displayevents_exitframeplay` | 44 | 6.9s |  |
| 643 | `movieclip_displayevents_exitframesymbol` | 135 | 7.4s |  |
| 644 | `movieclip_displayevents_looping` | 63 | 26.5s |  |
| 645 | `movieclip_displayevents_stopped` | 113 | 7.8s |  |
| 646 | `movieclip_displayevents_swap` | 96 | 2.7s |  |
| 647 | `movieclip_displayevents_timeline` | 128 | 26.9s |  |
| 648 | `movieclip_drawrect` | 54 | 7.3s |  |
| 649 | `movieclip_frameconstruct_skipped` | 9 | 7.5s |  |
| 650 | `movieclip_goto_during_frame_script` | 15 | 7.4s |  |
| 651 | `movieclip_goto_overwrite` | 14 | 26.6s |  |
| 652 | `movieclip_goto_scene_last_frame_int` | 1 | 26.8s |  |
| 653 | `movieclip_goto_scene_last_frame_label` | 1 | 6.8s |  |
| 654 | `movieclip_gotoandplay` | 15 | 25.1s |  |
| 655 | `movieclip_gotoandstop` | 13 | 24.2s |  |
| 656 | `movieclip_gotoandstop_children` | 4 | 6.8s |  |
| 657 | `movieclip_gotoandstop_framescripts1` | 4 | 19.3s |  |
| 658 | `movieclip_gotoandstop_framescripts2` | 4 | 2.5s |  |
| 659 | `movieclip_gotoandstop_framescripts_self` | 7 | 20.8s |  |
| 660 | `movieclip_gotoandstop_queueing` | 12 | 20.8s |  |
| 661 | `movieclip_hittest` | 67 | 6.1s |  |
| 662 | `movieclip_next_frame` | 2 | 20.8s |  |
| 663 | `movieclip_next_scene` | 6 | 20.6s |  |
| 664 | `movieclip_play` | 3 | 5.9s |  |
| 665 | `movieclip_prev_frame` | 3 | 5.8s |  |
| 666 | `movieclip_prev_scene` | 7 | 6.0s |  |
| 667 | `movieclip_properties` | 79 | 20.9s |  |
| 668 | `movieclip_queued_noop_goto_swf10` | 9 | 6.0s |  |
| 669 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 670 | `movieclip_scenes` | 11 | 5.9s |  |
| 671 | `movieclip_soundtransform` | 831 | 22.4s |  |
| 672 | `movieclip_stop` | 1 | 20.5s |  |
| 673 | `movieclip_super_is_symbol` | 20 | 6.2s |  |
| 674 | `movieclip_symbol_constr` | 8 | 6.4s |  |
| 675 | `movieclip_text_mousedown` | 1 | 6.0s |  |
| 676 | `movieclip_willtrigger` | 5 | 6.2s |  |
| 677 | `multiply` | 1058 | 14.9s |  |
| 678 | `namespace_constr` | 253 | 6.2s |  |
| 679 | `namespace_constr_args` | 1 | 5.9s |  |
| 680 | `namespace_enumeration_order` | 7 | 20.8s |  |
| 681 | `nan_scale` | 9 | 5.9s |  |
| 682 | `navigateToURL_target_normalize` | 107 | 22.1s |  |
| 683 | `negate` | 30 | 6.0s |  |
| 684 | `negative_volume_panned` | 0 | 6.3s |  |
| 685 | `nested_iteration` | 11 | 6.0s |  |
| 686 | `net_getClassByAlias` | 3 | 6.0s |  |
| 687 | `net_navigateToURL` | 57 | 6.0s |  |
| 688 | `net_stream_play_options` | 6 | 6.0s |  |
| 689 | `netconnection_close` | 55 | 6.1s |  |
| 690 | `netconnection_properties` | 78 | 6.0s |  |
| 691 | `netconnection_send_remote` | 50 | 6.3s |  |
| 692 | `netconnection_serialize_arrays` | 6 | 6.1s |  |
| 693 | `netfilterevent` | 10 | 6.0s |  |
| 694 | `netstream_client` | 10 | 6.1s |  |
| 695 | `netstream_connect` | 7 | 6.0s |  |
| 696 | `newactivation_in_script_init` | 3 | 8.0s |  |
| 697 | `newclass_mismatched` | 4 | 7.8s |  |
| 698 | `newclass_twice` | 3 | 7.8s |  |
| 699 | `nonconflicting_declarations` | 0 | 7.8s |  |
| 700 | `null_void_types` | 8 | 7.9s |  |
| 701 | `number_autoconv` | 21 | 7.9s |  |
| 702 | `number_autoconv_amf` | 132 | 7.9s |  |
| 703 | `number_autoconv_array_sort_32bit` | 1 | 7.9s |  |
| 704 | `number_constr` | 58 | 8.2s |  |
| 705 | `number_toexponential` | 378 | 8.0s |  |
| 706 | `number_toexponential2` | 35 | 7.8s |  |
| 707 | `number_tofixed` | 378 | 7.8s |  |
| 708 | `number_toprecision` | 350 | 7.9s |  |
| 709 | `obfuscated_class_names` | 3 | 7.8s |  |
| 710 | `object_enumeration` | 10 | 7.8s |  |
| 711 | `object_prototype` | 4 | 7.9s |  |
| 712 | `object_to_locale_string` | 2 | 7.8s |  |
| 713 | `object_to_string` | 2 | 7.8s |  |
| 714 | `object_value_of` | 2 | 3.2s |  |
| 715 | `op_coerce` | 54 | 7.8s |  |
| 716 | `op_coerce_x` | 54 | 7.8s |  |
| 717 | `op_escxattr` | 2 | 7.9s |  |
| 718 | `op_escxelem` | 2 | 7.7s |  |
| 719 | `op_lookupswitch` | 4 | 7.8s |  |
| 720 | `optimize_coerce` | 1 | 7.6s |  |
| 721 | `orphan_movie_complex` | 80 | 8.2s |  |
| 722 | `orphan_movie_reorder` | 111 | 26.9s |  |
| 723 | `package_namespace` | 7 | 7.5s |  |
| 724 | `param_default_value_has_zero_cpool_index` | 1 | 7.6s |  |
| 725 | `parent_early_access_child` | 16 | 27.1s |  |
| 726 | `parse_float` | 81 | 7.9s |  |
| 727 | `parse_float_swf10` | 81 | 7.7s |  |
| 728 | `parse_int` | 135 | 8.2s |  |
| 729 | `perspective_projection` | 1443 | 8.0s |  |
| 730 | `perspective_projection_basic` | 40 | 44.1s |  |
| 731 | `pixelbender_ceil` | 77 | 7.7s |  |
| 732 | `pixelbender_conditional` | 138 | 7.8s |  |
| 733 | `pixelbender_conversions` | 270 | 7.8s |  |
| 734 | `pixelbender_dithering` | 8 | 35.6s |  |
| 735 | `pixelbender_div` | 36 | 7.8s |  |
| 736 | `pixelbender_effect_BlurredFocus` | 0 | 34.3s |  |
| 737 | `pixelbender_effect_glassDisplace` | 0 | 13.9s |  |
| 738 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 31.0s |  |
| 739 | `pixelbender_effect_smudge` | 0 | 11.0s |  |
| 740 | `pixelbender_effect_tintype` | 0 | 10.1s |  |
| 741 | `pixelbender_effect_twirl` | 0 | 11.8s |  |
| 742 | `pixelbender_eof` | 7 | 7.5s |  |
| 743 | `pixelbender_images` | 0 | 9.8s |  |
| 744 | `pixelbender_input` | 103 | 26.8s |  |
| 745 | `pixelbender_logicalnot` | 20 | 7.5s |  |
| 746 | `pixelbender_malformed_data` | 190 | 27.3s |  |
| 747 | `pixelbender_multiple_out_params` | 1 | 7.5s |  |
| 748 | `pixelbender_no_out_param` | 6 | 7.7s |  |
| 749 | `pixelbender_outputs` | 13 | 8.0s |  |
| 750 | `pixelbender_padding_bytes` | 22 | 7.9s |  |
| 751 | `pixelbender_param_qualifier` | 512 | 8.0s |  |
| 752 | `pixelbender_parameters` | 1563 | 8.1s |  |
| 753 | `pixelbender_parameters_bool` | 240 | 8.0s |  |
| 754 | `pixelbender_parameters_int_vs_bool` | 54 | 7.8s |  |
| 755 | `pixelbender_parse_errors` | 6 | 7.9s |  |
| 756 | `pixelbender_rsqrt` | 24 | 7.9s |  |
| 757 | `pixelbender_select_kinds` | 8 | 7.9s |  |
| 758 | `pixelbender_shaderdata` | 49 | 7.9s |  |
| 759 | `pixelbender_shaderdata_setter` | 99 | 8.1s |  |
| 760 | `pixelbender_sign` | 60 | 8.0s |  |
| 761 | `pixelbender_vector_output` | 11 | 8.1s |  |
| 762 | `place_and_lookup/swf10` | 33 | 7.9s |  |
| 763 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 764 | `place_multiple` | 17 | 26.9s |  |
| 765 | `place_object_replace` | 9 | 7.7s |  |
| 766 | `place_object_replace_2` | 24 | 7.7s |  |
| 767 | `place_object_same_depth_frame` | 1 | 7.5s |  |
| 768 | `point` | 132 | 8.1s |  |
| 769 | `primitive_edge_cases` | 1 | 7.5s |  |
| 770 | `primitive_toString` | 277 | 7.7s |  |
| 771 | `primitive_valueOf` | 285 | 24.6s |  |
| 772 | `print_job_options` | 3 | 26.3s |  |
| 773 | `property_is_enumerable` | 114 | 8.3s |  |
| 774 | `property_is_enumerable_reset` | 23 | 7.5s |  |
| 775 | `property_priority` | 22 | 7.9s |  |
| 776 | `property_priority_chained` | 4 | 7.4s |  |
| 777 | `property_priority_definition_names_order` | 2 | 7.7s |  |
| 778 | `property_priority_three_level` | 6 | 26.2s |  |
| 779 | `propertyisenumerable_namespaces` | 6 | 7.5s |  |
| 780 | `prototype_set_null` | 7 | 7.4s |  |
| 781 | `proxy_callproperty` | 24 | 7.4s |  |
| 782 | `proxy_deleteproperty` | 64 | 7.5s |  |
| 783 | `proxy_enumeration` | 34 | 7.5s |  |
| 784 | `proxy_getproperty` | 77 | 7.6s |  |
| 785 | `proxy_hasownproperty` | 8 | 7.4s |  |
| 786 | `proxy_hasproperty` | 32 | 7.5s |  |
| 787 | `proxy_not_overridden` | 54 | 7.5s |  |
| 788 | `proxy_serialize` | 9 | 7.5s |  |
| 789 | `proxy_setproperty` | 42 | 7.5s |  |
| 790 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.4s |  |
| 791 | `qname_constr` | 32 | 7.5s |  |
| 792 | `qname_constr_namespace` | 24 | 7.5s |  |
| 793 | `qname_enumeration` | 9 | 7.5s |  |
| 794 | `qname_indexing` | 23 | 7.5s |  |
| 795 | `qname_tostring` | 25 | 7.6s |  |
| 796 | `qname_valueof` | 29 | 7.6s |  |
| 797 | `rectangle` | 1094 | 8.3s |  |
| 798 | `regexp_constr` | 148 | 7.8s |  |
| 799 | `regexp_exec` | 19 | 7.5s |  |
| 800 | `regexp_extended` | 47 | 7.4s |  |
| 801 | `regexp_multiargs` | 1 | 7.3s |  |
| 802 | `regexp_test` | 27 | 7.5s |  |
| 803 | `regexp_toString` | 10 | 7.5s |  |
| 804 | `register_script_refresh` | 35 | 26.9s |  |
| 805 | `remove_child_clear_field` | 88 | 7.9s |  |
| 806 | `remove_dobj` | 3 | 7.5s |  |
| 807 | `resolve_order` | 4 | 7.4s |  |
| 808 | `responder_null_callbacks` | 1 | 7.5s |  |
| 809 | `rng` | 1 | 8.6s |  |
| 810 | `rootless` | 42 | 7.7s |  |
| 811 | `rshift` | 1058 | 19.6s |  |
| 812 | `rtqname_not_namespace` | 12 | 25.4s |  |
| 813 | `sandbox_type_inherited` | 2 | 8.4s |  |
| 814 | `sandbox_type_local_file` | 1 | 26.9s |  |
| 815 | `sandbox_type_local_network` | 1 | 7.6s |  |
| 816 | `scene_constr` | 8 | 8.2s |  |
| 817 | `scopes_dont_cache/order-1` | 1 | 27.5s |  |
| 818 | `scopes_dont_cache/order-2` | 1 | 1.1s |  |
| 819 | `security_domain_current` | 2 | 8.0s |  |
| 820 | `selection` | 239 | 8.6s |  |
| 821 | `set_local_0` | 31 | 8.0s |  |
| 822 | `set_property_is_enumerable` | 85 | 8.3s |  |
| 823 | `shaderparameter_value` | 4 | 7.9s |  |
| 824 | `shape_drawrect` | 54 | 8.0s |  |
| 825 | `shared_object_no_root` | 3 | 7.9s |  |
| 826 | `simplebutton_added_to_stage` | 45 | 27.6s |  |
| 827 | `simplebutton_childevents` | 86 | 29.1s |  |
| 828 | `simplebutton_childevents_nested` | 54 | 8.5s |  |
| 829 | `simplebutton_childevents_sprite` | 13 | 8.2s |  |
| 830 | `simplebutton_childprops` | 144 | 8.4s |  |
| 831 | `simplebutton_childshuffle` | 23 | 8.1s |  |
| 832 | `simplebutton_constr` | 36 | 8.3s |  |
| 833 | `simplebutton_constr_childevents` | 48 | 8.4s |  |
| 834 | `simplebutton_constr_params` | 42 | 8.3s |  |
| 835 | `simplebutton_mouseenabled` | 26 | 8.0s |  |
| 836 | `simplebutton_multi_children` | 19 | 8.3s |  |
| 837 | `simplebutton_structure` | 27 | 8.4s |  |
| 838 | `simplebutton_symbolclass` | 68 | 8.6s |  |
| 839 | `slot_disp_id_shared_numbering` | 1 | 27.8s |  |
| 840 | `slots_force_autoassigned` | 1 | 8.1s |  |
| 841 | `socket_after_disconnect` | 1 | 8.1s |  |
| 842 | `socket_close` | 2 | 8.0s |  |
| 843 | `socket_connect` | 4 | 8.1s |  |
| 844 | `socket_errors` | 56 | 8.4s |  |
| 845 | `socket_read_big` | 48 | 44.6s |  |
| 846 | `socket_read_little` | 48 | 3.3s |  |
| 847 | `socket_read_write_object` | 8 | 8.0s |  |
| 848 | `socket_write_big` | 15 | 8.3s |  |
| 849 | `socket_write_little` | 14 | 8.1s |  |
| 850 | `sound_embeddedprops` | 26 | 8.5s |  |
| 851 | `sound_play` | 19 | 8.1s |  |
| 852 | `sound_valueof` | 33 | 8.2s |  |
| 853 | `soundchannel_soundtransform` | 835 | 30.2s |  |
| 854 | `soundchannel_soundtransform_exists` | 5 | 27.9s |  |
| 855 | `soundchannel_stop` | 8 | 27.6s |  |
| 856 | `soundmixer_buffertime` | 5 | 7.8s |  |
| 857 | `soundmixer_stopall` | 6 | 26.7s |  |
| 858 | `soundtransform` | 442 | 13.2s |  |
| 859 | `space_justifier_clone` | 12 | 7.8s |  |
| 860 | `sprite_with_frames` | 0 | 31.2s |  |
| 861 | `stage3d_agal_cross_product` | 0 | 10.5s |  |
| 862 | `stage3d_agal_upload_errors` | 66 | 10.6s |  |
| 863 | `stage3d_bitmap` | 0 | 32.5s |  |
| 864 | `stage3d_blend` | 81 | 32.0s |  |
| 865 | `stage3d_context3d_string_args` | 158 | 8.8s |  |
| 866 | `stage3d_errors` | 7 | 7.9s |  |
| 867 | `stage3d_errors_atf` | 3 | 9.2s |  |
| 868 | `stage3d_errors_swf_29` | 6 | 8.0s |  |
| 869 | `stage3d_float1_index` | 0 | 29.1s |  |
| 870 | `stage3d_fractal` | 0 | 29.9s |  |
| 871 | `stage3d_ignore_sampler_override` | 0 | 29.6s |  |
| 872 | `stage3d_multistage_triangle` | 3 | 10.5s |  |
| 873 | `stage3d_program_constants_bytearray_be` | 0 | 31.0s |  |
| 874 | `stage3d_program_constants_bytearray_le` | 0 | 11.1s |  |
| 875 | `stage3d_program_constants_invalid_input` | 21 | 8.6s |  |
| 876 | `stage3d_raytrace` | 0 | 34.2s |  |
| 877 | `stage3d_rotating_cube` | 0 | 11.4s |  |
| 878 | `stage3d_sampler` | 0 | 10.6s |  |
| 879 | `stage3d_sampler_partial_upload` | 0 | 29.5s |  |
| 880 | `stage3d_stencil` | 0 | 31.5s |  |
| 881 | `stage3d_texture` | 0 | 15.9s |  |
| 882 | `stage3d_texture_bytearray` | 0 | 11.6s |  |
| 883 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 11.2s |  |
| 884 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 12.1s |  |
| 885 | `stage3d_triangle` | 0 | 10.4s |  |
| 886 | `stage3d_triangle_bytes4` | 0 | 10.3s |  |
| 887 | `stage3d_triangle_float1` | 0 | 10.4s |  |
| 888 | `stage3d_triangle_index_upload` | 0 | 10.6s |  |
| 889 | `stage3d_x_y` | 22 | 7.7s |  |
| 890 | `stage_access` | 10 | 7.6s |  |
| 891 | `stage_displayobject_properties` | 24 | 7.5s |  |
| 892 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.5s |  |
| 893 | `stage_framerate_nan` | 7 | 26.6s |  |
| 894 | `stage_framerate_negative` | 6 | 7.5s |  |
| 895 | `stage_framerate_zero` | 6 | 7.5s |  |
| 896 | `stage_invalidate` | 38 | 7.8s |  |
| 897 | `stage_loaderinfo_properties` | 24 | 26.4s |  |
| 898 | `stage_mousechildren` | 2 | 7.5s |  |
| 899 | `stage_mouseenabled` | 15 | 7.4s |  |
| 900 | `stage_overriden_setters` | 31 | 7.7s |  |
| 901 | `stage_properties` | 30 | 7.5s |  |
| 902 | `stage_properties2` | 213 | 7.7s |  |
| 903 | `stage_stage3Ds_vector` | 1 | 27.0s |  |
| 904 | `static_length` | 24 | 7.7s |  |
| 905 | `static_text` | 3 | 7.9s |  |
| 906 | `static_var_with_this_in_ctor` | 2 | 7.8s |  |
| 907 | `statictext_text` | 8 | 7.9s |  |
| 908 | `stored_properties` | 11 | 7.8s |  |
| 909 | `strict_equality` | 34 | 7.7s |  |
| 910 | `string_call` | 13 | 7.5s |  |
| 911 | `string_case` | 23 | 7.5s |  |
| 912 | `string_char_at` | 27 | 7.5s |  |
| 913 | `string_char_code_at` | 28 | 7.4s |  |
| 914 | `string_concat_fromcharcode` | 37 | 7.5s |  |
| 915 | `string_constr` | 25 | 7.5s |  |
| 916 | `string_indexof_lastindexof` | 87 | 7.8s |  |
| 917 | `string_length` | 16 | 7.6s |  |
| 918 | `string_locale_compare` | 39 | 24.5s |  |
| 919 | `string_match` | 51 | 26.5s |  |
| 920 | `string_relational_compare` | 4 | 7.5s |  |
| 921 | `string_replace` | 51 | 7.5s |  |
| 922 | `string_search` | 41 | 7.5s |  |
| 923 | `string_slice_substr_substring` | 170 | 8.7s |  |
| 924 | `string_split` | 29 | 7.4s |  |
| 925 | `string_substr_negative` | 21 | 7.4s |  |
| 926 | `string_substr_weird` | 182 | 7.3s |  |
| 927 | `stylesheet` | 221 | 7.9s |  |
| 928 | `stylesheet_parse_color` | 69 | 7.4s |  |
| 929 | `stylesheet_transform` | 307 | 7.7s |  |
| 930 | `subclass_superclass_linked_symbol` | 4 | 7.8s |  |
| 931 | `subtract` | 1058 | 19.5s |  |
| 932 | `super_get_call` | 12 | 7.4s |  |
| 933 | `supercall_two_classobjects` | 2 | 7.4s |  |
| 934 | `supercalls_weird` | 2 | 7.4s |  |
| 935 | `superinterface_call` | 20 | 7.4s |  |
| 936 | `superinterface_instanceof` | 18 | 7.4s |  |
| 937 | `swf8` | 1 | 7.3s |  |
| 938 | `swf_10_queued_goto_scripts_construct` | 52 | 26.1s |  |
| 939 | `swf_9_goto_in_enter_frame` | 17 | 7.5s |  |
| 940 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.5s |  |
| 941 | `swf_9_queued_goto_scripts` | 6 | 26.2s |  |
| 942 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 943 | `swf_9_versioning` | 2 | 7.5s |  |
| 944 | `swf_wrong_frame_count` | 38 | 7.8s |  |
| 945 | `swf_wrong_frame_count_isplaying` | 22 | 26.7s |  |
| 946 | `symbol_class_binary_data` | 8 | 7.6s |  |
| 947 | `symbol_class_conflict` | 4 | 10.7s |  |
| 948 | `symbol_class_root_not_zero` | 1 | 7.4s |  |
| 949 | `symbolclass_invalid_utf8` | 2 | 7.4s |  |
| 950 | `system_exit` | 3 | 7.4s |  |
| 951 | `system_setclipboard_null` | 1 | 7.3s |  |
| 952 | `tab_ordering_arrows` | 998 | 27.4s |  |
| 953 | `tab_ordering_automatic_advanced` | 184 | 8.2s |  |
| 954 | `tab_ordering_automatic_basic` | 45 | 7.5s |  |
| 955 | `tab_ordering_children` | 116 | 43.0s |  |
| 956 | `tab_ordering_custom_basic` | 34 | 7.0s |  |
| 957 | `tab_ordering_stage_tab_children` | 32 | 7.1s |  |
| 958 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.1s |  |
| 959 | `tab_ordering_tabbable` | 47 | 7.1s |  |
| 960 | `tabstop_properties` | 105 | 7.5s |  |
| 961 | `text_element_basic` | 34 | 7.3s |  |
| 962 | `text_engine_fontdescription` | 27 | 7.3s |  |
| 963 | `text_engine_groupelement` | 64 | 8.0s |  |
| 964 | `text_run` | 7 | 7.1s |  |
| 965 | `textblock_createline_errors` | 23 | 7.4s |  |
| 966 | `textblock_createline_fte` | 9 | 26.3s |  |
| 967 | `textblock_properties` | 118 | 7.5s |  |
| 968 | `textbox_click` | 37 | 26.2s |  |
| 969 | `textfield_event` | 66 | 7.2s |  |
| 970 | `textfield_focusin_event` | 9 | 7.0s |  |
| 971 | `textfield_input_dead_keys_windows` | 15 | 7.1s |  |
| 972 | `textfield_unload` | 39 | 25.9s |  |
| 973 | `textformat` | 1134 | 7.2s |  |
| 974 | `textformat_display` | 14 | 7.1s |  |
| 975 | `textformat_font_max_length` | 4 | 7.0s |  |
| 976 | `textline_inapplicable_properties` | 10 | 7.0s |  |
| 977 | `textline_name` | 1 | 7.0s |  |
| 978 | `textline_splitting_basic` | 76 | 7.2s |  |
| 979 | `textline_throwerror` | 30 | 7.0s |  |
| 980 | `textline_validity` | 162 | 7.2s |  |
| 981 | `throw` | 3 | 7.1s |  |
| 982 | `timeline_scripts` | 3 | 7.3s |  |
| 983 | `timer` | 90 | 8.1s |  |
| 984 | `timer_events` | 3 | 7.3s |  |
| 985 | `timer_finished` | 11 | 7.3s |  |
| 986 | `timer_invalid_delay` | 30 | 7.0s |  |
| 987 | `timer_reset` | 8 | 7.4s |  |
| 988 | `timer_setdelay` | 5 | 7.3s |  |
| 989 | `trace` | 12 | 7.0s |  |
| 990 | `truthiness` | 30 | 7.0s |  |
| 991 | `try_catch` | 11 | 24.1s |  |
| 992 | `try_catch_typed` | 12 | 7.1s |  |
| 993 | `typeof` | 30 | 7.2s |  |
| 994 | `uint_constr` | 92 | 7.2s |  |
| 995 | `uint_tofixed` | 1215 | 6.9s |  |
| 996 | `uint_tostring` | 3375 | 7.3s |  |
| 997 | `uncaught_error_basic` | 2 | 7.0s |  |
| 998 | `unchecked_function` | 15 | 7.0s |  |
| 999 | `unescape` | 28 | 7.0s |  |
| 1000 | `url_loader` | 25 | 7.1s |  |
| 1001 | `url_vars` | 27 | 7.2s |  |
| 1002 | `urlrequest` | 18 | 25.8s |  |
| 1003 | `urlstream_basic` | 5 | 7.0s |  |
| 1004 | `urshift` | 1058 | 19.3s |  |
| 1005 | `utils3d` | 7 | 7.0s |  |
| 1006 | `vector3d` | 397 | 11.8s |  |
| 1007 | `vector_class` | 36 | 7.5s |  |
| 1008 | `vector_class_call` | 11 | 7.4s |  |
| 1009 | `vector_coercion` | 66 | 7.9s |  |
| 1010 | `vector_concat` | 90 | 7.8s |  |
| 1011 | `vector_constr` | 107 | 7.8s |  |
| 1012 | `vector_enumeration` | 5 | 7.1s |  |
| 1013 | `vector_every` | 92 | 7.9s |  |
| 1014 | `vector_filter` | 95 | 7.9s |  |
| 1015 | `vector_holes` | 24 | 7.1s |  |
| 1016 | `vector_indexof` | 302 | 11.8s |  |
| 1017 | `vector_insertat` | 270 | 8.1s |  |
| 1018 | `vector_int_access` | 4 | 7.0s |  |
| 1019 | `vector_int_delete` | 11 | 7.0s |  |
| 1020 | `vector_join` | 58 | 7.5s |  |
| 1021 | `vector_lastindexof` | 302 | 7.0s |  |
| 1022 | `vector_legacy` | 10 | 7.1s |  |
| 1023 | `vector_map` | 85 | 7.7s |  |
| 1024 | `vector_object_final` | 1 | 7.0s |  |
| 1025 | `vector_object_toString` | 10 | 7.0s |  |
| 1026 | `vector_pushpop` | 255 | 8.3s |  |
| 1027 | `vector_reborrow_bug` | 10 | 7.0s |  |
| 1028 | `vector_removeat` | 172 | 27.3s |  |
| 1029 | `vector_reverse` | 232 | 9.3s |  |
| 1030 | `vector_shiftunshift` | 252 | 9.6s |  |
| 1031 | `vector_slice` | 331 | 9.8s |  |
| 1032 | `vector_sort` | 905 | 17.2s |  |
| 1033 | `vector_splice` | 693 | 11.9s |  |
| 1034 | `vector_splice_fixed_bug_compat` | 4 | 28.4s |  |
| 1035 | `vector_tostring` | 79 | 8.8s |  |
| 1036 | `verification` | 8 | 8.4s |  |
| 1037 | `verify_abnormal_loop` | 1 | 8.0s |  |
| 1038 | `verify_dxns_without_flag` | 3 | 8.6s |  |
| 1039 | `verify_exception_target_two_jumps` | 1 | 8.1s |  |
| 1040 | `verify_exception_targets_edge_case` | 1 | 8.1s |  |
| 1041 | `verify_illegal_opcode` | 1 | 3.9s |  |
| 1042 | `verify_jump_to_middle_of_op` | 1 | 8.1s |  |
| 1043 | `verify_lookup_switch_edge_case` | 1 | 8.1s |  |
| 1044 | `verify_method_info_oob` | 1 | 1.4s |  |
| 1045 | `verify_stack` | 5 | 8.2s |  |
| 1046 | `verify_typecheck` | 4 | 8.1s |  |
| 1047 | `verify_unreachable_exception` | 2 | 8.0s |  |
| 1048 | `versioned_isplaying` | 2 | 8.2s |  |
| 1049 | `virtual_properties` | 16 | 8.3s |  |
| 1050 | `with` | 4 | 8.4s |  |
| 1051 | `wrong_arg_count` | 7 | 8.4s |  |
| 1052 | `xml_abstract_equality` | 36 | 8.6s |  |
| 1053 | `xml_advanced` | 52 | 8.2s |  |
| 1054 | `xml_appendchild` | 10 | 8.3s |  |
| 1055 | `xml_appendchild_swf_v21` | 13 | 8.5s |  |
| 1056 | `xml_as_attribute` | 9 | 8.1s |  |
| 1057 | `xml_attribute` | 35 | 8.3s |  |
| 1058 | `xml_attribute_name` | 40 | 8.1s |  |
| 1059 | `xml_basic` | 33 | 8.0s |  |
| 1060 | `xml_child` | 25 | 8.0s |  |
| 1061 | `xml_childindex` | 7 | 8.1s |  |
| 1062 | `xml_children` | 43 | 8.6s |  |
| 1063 | `xml_class_call` | 9 | 8.1s |  |
| 1064 | `xml_contains` | 197 | 8.1s |  |
| 1065 | `xml_copy` | 20 | 3.5s |  |
| 1066 | `xml_ctor_from_tostring` | 23 | 20.5s |  |
| 1067 | `xml_delete` | 114 | 6.3s |  |
| 1068 | `xml_descendants` | 83 | 21.8s |  |
| 1069 | `xml_elements` | 6 | 6.5s |  |
| 1070 | `xml_equals_namespace_check` | 2 | 6.2s |  |
| 1071 | `xml_explicit_use_namespace` | 5 | 6.3s |  |
| 1072 | `xml_getdescendants_qname` | 21 | 6.3s |  |
| 1073 | `xml_has_property_via_in` | 26 | 6.3s |  |
| 1074 | `xml_hasownproperty` | 6 | 6.2s |  |
| 1075 | `xml_ignore_white` | 6 | 6.5s |  |
| 1076 | `xml_length` | 2 | 6.2s |  |
| 1077 | `xml_list_as_attribute` | 9 | 6.3s |  |
| 1078 | `xml_list_concat` | 20 | 6.3s |  |
| 1079 | `xml_list_ctor_errors` | 34 | 6.6s |  |
| 1080 | `xml_list_delete_clear_parent` | 6 | 6.4s |  |
| 1081 | `xml_list_enumerate` | 4 | 6.2s |  |
| 1082 | `xml_methods_settings` | 3 | 6.2s |  |
| 1083 | `xml_mismatched_tag` | 37 | 6.8s |  |
| 1084 | `xml_namespace` | 39 | 6.2s |  |
| 1085 | `xml_namespace_methods` | 245 | 6.4s |  |
| 1086 | `xml_namespaced_property` | 7 | 6.3s |  |
| 1087 | `xml_no_namespace` | 1 | 6.3s |  |
| 1088 | `xml_nodekind` | 3 | 6.1s |  |
| 1089 | `xml_normalize` | 35 | 6.6s |  |
| 1090 | `xml_notification_bubbling` | 361 | 6.6s |  |
| 1091 | `xml_parent` | 8 | 6.3s |  |
| 1092 | `xml_set_children` | 17 | 6.3s |  |
| 1093 | `xml_set_name` | 34 | 6.3s |  |
| 1094 | `xml_settings` | 6 | 2.7s |  |
| 1095 | `xml_simple_complex_content` | 47 | 6.3s |  |
| 1096 | `xml_socket` | 11 | 6.5s |  |
| 1097 | `xml_text` | 7 | 6.2s |  |
| 1098 | `xml_tostring` | 6 | 6.0s |  |
| 1099 | `xml_tostring_namespace` | 12 | 6.0s |  |
| 1100 | `xml_unescaping` | 23 | 6.0s |  |
| 1101 | `xml_weird_ignores` | 54 | 6.1s |  |
| 1102 | `xml_wildcard` | 11 | 6.2s |  |
| 1103 | `xmldocument` | 254 | 6.3s |  |
| 1104 | `xmlnode` | 3540 | 6.5s |  |
| 1105 | `zero_frame_clip` | 3 | 6.7s |  |

## Ruffle-Matched Tests

**30 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 7.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 26.5s |  |
| 3 | `blend_transform` | 1 | 1 | 7.8s |  |
| 4 | `coerce_property` | 3 | 3 | 7.6s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.5s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 27.3s |  |
| 7 | `edittext_device_transform_layout` | 20 | 20 | 8.3s |  |
| 8 | `edittext_getcharboundaries_culling` | 300 | 300 | 8.5s |  |
| 9 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 45.1s |  |
| 10 | `edittext_tab_stops` | 6 | 6 | 8.0s |  |
| 11 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.7s |  |
| 12 | `error_1034_debug_string` | 19 | 19 | 7.7s |  |
| 13 | `freestanding_superclass` | 2 | 4 | 8.0s |  |
| 14 | `goto_framescript_queued` | 5 | 5 | 27.5s |  |
| 15 | `graphics_draw_path` | 50 | 50 | 29.8s |  |
| 16 | `groupelement_text` | 2 | 2 | 8.1s |  |
| 17 | `int_toexponential` | 76 | 76 | 6.2s |  |
| 18 | `int_toprecision` | 441 | 441 | 6.2s |  |
| 19 | `simplebutton_childevents_script_order` | 4 | 4 | 8.2s |  |
| 20 | `slot_holes_fail` | 1 | 1 | 8.0s |  |
| 21 | `slot_id_exceeds_trait_count` | 1 | 1 | 28.1s |  |
| 22 | `soundchannel_position` | 74 | 74 | 29.2s |  |
| 23 | `soundchannel_soundcomplete` | 10 | 10 | 8.4s |  |
| 24 | `sprite_dropTarget` | 15 | 15 | 7.9s |  |
| 25 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.5s |  |
| 26 | `textblock_line_changes` | 42 | 42 | 7.6s |  |
| 27 | `uint_toexponential` | 100 | 100 | 7.2s |  |
| 28 | `uint_toprecision` | 433 | 433 | 7.2s |  |
| 29 | `uncaught_errors_stringified` | 15 | 15 | 7.2s |  |
| 30 | `weird_superinterface_properties` | 1 | 1 | 28.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**29 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 2 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 3 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 4 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 5 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 6 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 7 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 8 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 9 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 10 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 11 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 12 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 13 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 14 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 15 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 16 | `delayed_symbolclass` | 71.4% | 20 | 28 | 8 |  |
| 17 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 18 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 19 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 20 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 21 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 22 | `displayobject_scrollrect` | 57.6% | 19 | 33 | 14 |  |
| 23 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 24 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 25 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 26 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 27 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 28 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 29 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**91 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 2 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 3 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 4 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 5 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 6 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 7 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 8 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 9 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 10 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 11 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 12 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 13 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 14 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 15 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 16 | `delayed_symbolclass` | 71.4% | 20/28 | 28 | 28 |  |
| 17 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 18 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 19 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 20 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 21 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 22 | `displayobject_scrollrect` | 57.6% | 19/33 | 33 | 33 |  |
| 23 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 24 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 25 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 26 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 27 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 28 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 29 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 30 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 31 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 32 | `textblock_recreateline` | 39.4% | 39/99 | 99 | 98 |  |
| 33 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 34 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 35 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 36 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 37 | `geom_transform` | 28.4% | 21/74 | 26 | 74 |  |
| 38 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 39 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 40 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 41 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 42 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 43 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 44 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 45 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 46 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 47 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 48 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 49 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 50 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 51 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 52 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 53 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 54 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 55 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 56 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 57 | `all_classes/events/swf10` | 0.2% | 3/1638 | 196 | 1638 |  |
| 58 | `all_classes/events/swf11` | 0.2% | 3/1750 | 196 | 1750 |  |
| 59 | `all_classes/events/swf12` | 0.2% | 3/1814 | 196 | 1814 |  |
| 60 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 61 | `all_classes/events/swf9` | 0.1% | 1/1030 | 196 | 1030 |  |
| 62 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 63 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 64 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 65 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 66 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 67 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 68 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 69 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 70 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 71 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 72 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 73 | `all_classes/events/swf30` | 0.0% | 0/2353 | 196 | 2353 |  |
| 74 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 75 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 76 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 77 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 78 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 79 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 80 | `avm1_root` | 0.0% | 0/58 | 7 | 58 |  |
| 81 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 82 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 83 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 84 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 85 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 86 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 87 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 88 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 89 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 90 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 91 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
