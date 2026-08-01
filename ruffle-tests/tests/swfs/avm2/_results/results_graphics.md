# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-01 00:14 UTC

**Git SHA**: `2ab0c01bea`

**Run Duration**: 184m 11s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1224 |
| Passing | **1052** (85.9%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1078** (88.1%) |
| Failing | 146 |
| Total expected lines | 151515 |
| Matching lines | 117941 (77.8%) |
| Mismatched lines | 33574 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 145 | 99.3% |
| Runtime Error | 1 | 0.7% |

## Passing Tests

**1052 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 7.5s |  |
| 2 | `accessibility` | 1 | 7.5s |  |
| 3 | `add` | 1058 | 19.7s |  |
| 4 | `agal_compiler` | 13 | 9.9s |  |
| 5 | `air_datagram_socket` | 1 | 9.0s |  |
| 6 | `air_hidden_lookup` | 2 | 7.4s |  |
| 7 | `air_ifilepromise` | 1 | 7.4s |  |
| 8 | `all_classes/security/swf11` | 3 | 7.7s |  |
| 9 | `amf_array_serialization` | 17 | 9.6s |  |
| 10 | `amf_custom_obj` | 26 | 7.6s |  |
| 11 | `amf_dictionary` | 9 | 7.5s |  |
| 12 | `amf_function` | 46 | 7.6s |  |
| 13 | `amf_invalid_date` | 2 | 7.5s |  |
| 14 | `amf_missing_prop` | 6 | 7.5s |  |
| 15 | `amf_nondynamic_function_prop` | 6 | 6.7s |  |
| 16 | `amf_setter_error` | 8 | 6.7s |  |
| 17 | `amf_vector` | 40 | 6.8s |  |
| 18 | `amf_xml` | 6 | 6.6s |  |
| 19 | `application_domain` | 4 | 6.6s |  |
| 20 | `applicationdomain_getqualifieddefinitionnames` | 9 | 6.7s |  |
| 21 | `applicationdomain_hasdefinition_null` | 2 | 6.5s |  |
| 22 | `array_access` | 18 | 6.7s |  |
| 23 | `array_access_interpreter` | 4 | 6.6s |  |
| 24 | `array_access_no_pubns` | 2 | 6.6s |  |
| 25 | `array_concat` | 41 | 6.7s |  |
| 26 | `array_constr` | 10 | 6.5s |  |
| 27 | `array_delete` | 44 | 6.8s |  |
| 28 | `array_enumeration` | 10 | 6.7s |  |
| 29 | `array_enumeration_elements` | 11 | 6.6s |  |
| 30 | `array_every` | 8 | 6.6s |  |
| 31 | `array_filter` | 6 | 6.6s |  |
| 32 | `array_foreach` | 18 | 6.6s |  |
| 33 | `array_hasownproperty` | 11 | 2.6s |  |
| 34 | `array_holes` | 9 | 6.6s |  |
| 35 | `array_index_max` | 84 | 6.5s |  |
| 36 | `array_indexof` | 25 | 6.6s |  |
| 37 | `array_join` | 26 | 6.7s |  |
| 38 | `array_lastindexof` | 29 | 6.7s |  |
| 39 | `array_length` | 14 | 6.6s |  |
| 40 | `array_literal` | 3 | 6.6s |  |
| 41 | `array_map` | 8 | 6.5s |  |
| 42 | `array_pop` | 52 | 6.7s |  |
| 43 | `array_push` | 24 | 6.6s |  |
| 44 | `array_reborrow_bug` | 6 | 6.6s |  |
| 45 | `array_reverse` | 28 | 6.6s |  |
| 46 | `array_shift` | 51 | 2.8s |  |
| 47 | `array_slice` | 39 | 6.7s |  |
| 48 | `array_some` | 8 | 6.7s |  |
| 49 | `array_sort` | 297 | 7.1s |  |
| 50 | `array_sort_fun_swf12` | 2 | 6.7s |  |
| 51 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 52 | `array_sort_random` | 210 | 6.7s |  |
| 53 | `array_sort_swf10_32bit` | 1 | 6.7s |  |
| 54 | `array_sorton` | 545 | 7.6s |  |
| 55 | `array_sparse_ops` | 41 | 6.9s |  |
| 56 | `array_splice` | 133 | 7.1s |  |
| 57 | `array_splice2` | 428 | 7.0s |  |
| 58 | `array_splice_types` | 48 | 6.8s |  |
| 59 | `array_storage` | 8 | 6.6s |  |
| 60 | `array_tolocalestring` | 9 | 6.7s |  |
| 61 | `array_tostring` | 12 | 6.7s |  |
| 62 | `array_unshift` | 24 | 6.8s |  |
| 63 | `array_valueof` | 9 | 6.6s |  |
| 64 | `array_vector_null_callback` | 10 | 6.8s |  |
| 65 | `astype` | 28 | 6.8s |  |
| 66 | `astypelate` | 24 | 6.9s |  |
| 67 | `astypelate_propagates` | 1 | 6.6s |  |
| 68 | `asymmetric_key_events` | 11 | 6.8s |  |
| 69 | `av_networking_params` | 9 | 6.8s |  |
| 70 | `av_tag_data` | 2 | 6.7s |  |
| 71 | `avm2_catchup_dobj` | 158 | 7.3s |  |
| 72 | `away3d_advanced_shallow_water_demo` | 0 | 84.3s |  |
| 73 | `bevel_filter` | 187 | 6.9s |  |
| 74 | `bitand` | 1058 | 18.5s |  |
| 75 | `bitmap_constr` | 17 | 6.8s |  |
| 76 | `bitmap_data` | 1000 | 13.8s |  |
| 77 | `bitmap_pixelsnapping` | 2 | 26.0s |  |
| 78 | `bitmap_properties` | 23 | 6.8s |  |
| 79 | `bitmap_subclass` | 7 | 8.0s |  |
| 80 | `bitmap_subclass_properties` | 9 | 7.1s |  |
| 81 | `bitmap_timeline` | 9 | 6.7s |  |
| 82 | `bitmapdata_accuracy` | 1 | 48.2s |  |
| 83 | `bitmapdata_applyfilter_blur` | 0 | 26.8s |  |
| 84 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.6s |  |
| 85 | `bitmapdata_applyfilter_destpoint` | 0 | 26.1s |  |
| 86 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.6s |  |
| 87 | `bitmapdata_clone` | 13 | 6.9s |  |
| 88 | `bitmapdata_colortransform` | 0 | 7.1s |  |
| 89 | `bitmapdata_colortransform_oob` | 2 | 6.7s |  |
| 90 | `bitmapdata_constr` | 22 | 2.7s |  |
| 91 | `bitmapdata_constructor_from_timeline` | 1 | 7.1s |  |
| 92 | `bitmapdata_copychannel` | 0 | 29.6s |  |
| 93 | `bitmapdata_copypixels` | 23 | 27.5s |  |
| 94 | `bitmapdata_copypixels_blend_over` | 1 | 7.1s |  |
| 95 | `bitmapdata_copypixelstobytearray` | 39 | 7.0s |  |
| 96 | `bitmapdata_dispose` | 7 | 7.2s |  |
| 97 | `bitmapdata_draw` | 0 | 26.7s |  |
| 98 | `bitmapdata_draw_colortransform` | 0 | 7.4s |  |
| 99 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.1s |  |
| 100 | `bitmapdata_draw_filters` | 0 | 25.7s |  |
| 101 | `bitmapdata_draw_masks` | 0 | 7.2s |  |
| 102 | `bitmapdata_draw_rotation` | 0 | 7.3s |  |
| 103 | `bitmapdata_draw_self_via_graphic` | 0 | 7.3s |  |
| 104 | `bitmapdata_draw_stage` | 0 | 25.3s |  |
| 105 | `bitmapdata_drawwithquality` | 0 | 7.3s |  |
| 106 | `bitmapdata_embedded` | 9 | 7.5s |  |
| 107 | `bitmapdata_fillrect` | 0 | 7.5s |  |
| 108 | `bitmapdata_filter_sourcerect` | 0 | 22.6s |  |
| 109 | `bitmapdata_floodfill` | 35 | 7.1s |  |
| 110 | `bitmapdata_getpixels` | 39 | 25.9s |  |
| 111 | `bitmapdata_getvector` | 27 | 3.1s |  |
| 112 | `bitmapdata_histogram` | 59 | 3.1s |  |
| 113 | `bitmapdata_hittest` | 112 | 7.7s |  |
| 114 | `bitmapdata_hittest_threshold` | 18 | 7.3s |  |
| 115 | `bitmapdata_opaque` | 0 | 7.5s |  |
| 116 | `bitmapdata_pixeldissolve` | 1037 | 7.8s |  |
| 117 | `bitmapdata_pixeldissolve_image` | 0 | 7.7s |  |
| 118 | `bitmapdata_rectangle_rounding` | 16 | 7.2s |  |
| 119 | `bitmapdata_setpixels` | 286 | 7.4s |  |
| 120 | `bitmapdata_setvector` | 26 | 7.3s |  |
| 121 | `bitmapdata_sync` | 0 | 25.9s |  |
| 122 | `bitmapdata_threshold` | 176 | 7.8s |  |
| 123 | `bitnot` | 46 | 7.2s |  |
| 124 | `bitor` | 1058 | 19.3s |  |
| 125 | `bitxor` | 1058 | 19.4s |  |
| 126 | `blend_mode_null` | 1 | 7.0s |  |
| 127 | `blend_multiply_alpha` | 0 | 7.4s |  |
| 128 | `blend_scroll` | 0 | 7.3s |  |
| 129 | `blend_shader_luma_lighten` | 3 | 7.6s |  |
| 130 | `blur_filter` | 43 | 5.8s |  |
| 131 | `boolean_constr` | 32 | 6.4s |  |
| 132 | `boolean_negation` | 30 | 6.1s |  |
| 133 | `boolean_tostring` | 8 | 5.7s |  |
| 134 | `broadcast_event` | 7 | 6.0s |  |
| 135 | `button_bounds` | 1 | 6.1s |  |
| 136 | `button_hittest` | 2 | 20.1s |  |
| 137 | `button_nested_frame` | 48 | 20.3s |  |
| 138 | `bytearray` | 48 | 6.0s |  |
| 139 | `bytearray_compress` | 31 | 6.0s |  |
| 140 | `bytearray_errors` | 24 | 6.1s |  |
| 141 | `bytearray_method_serialization` | 1 | 5.8s |  |
| 142 | `bytearray_oom` | 3 | 5.8s |  |
| 143 | `bytearray_readobject_amf0` | 50 | 5.8s |  |
| 144 | `bytearray_readobject_amf3` | 53 | 5.9s |  |
| 145 | `bytearray_readutf8bytes_with_bom` | 16 | 5.8s |  |
| 146 | `bytearray_serialization` | 3 | 5.8s |  |
| 147 | `bytearray_string_null` | 19 | 5.7s |  |
| 148 | `bytearray_tostring` | 15 | 5.6s |  |
| 149 | `bytearray_utf16` | 8 | 5.7s |  |
| 150 | `bytearray_writeobject` | 24 | 5.7s |  |
| 151 | `callee_in_initializer` | 6 | 5.6s |  |
| 152 | `callproplex_class` | 1 | 5.6s |  |
| 153 | `capabilities_resolution` | 8 | 20.4s |  |
| 154 | `catch_class` | 6 | 5.8s |  |
| 155 | `catch_scope_slot` | 7 | 2.5s |  |
| 156 | `checkfilter` | 4 | 2.4s |  |
| 157 | `class_call` | 32 | 5.8s |  |
| 158 | `class_cast_call` | 14 | 5.9s |  |
| 159 | `class_enumeration` | 4 | 5.8s |  |
| 160 | `class_has_own_property` | 2 | 5.8s |  |
| 161 | `class_init_interpreter_mode` | 1 | 5.7s |  |
| 162 | `class_is` | 32 | 5.7s |  |
| 163 | `class_methods` | 5 | 5.7s |  |
| 164 | `class_object_properties` | 10 | 5.7s |  |
| 165 | `class_singleton` | 18 | 5.7s |  |
| 166 | `class_supercalls_errors` | 35 | 6.0s |  |
| 167 | `class_supercalls_mismatched` | 26 | 5.6s |  |
| 168 | `class_superclass_wrong_order` | 1 | 25.7s |  |
| 169 | `class_to_locale_string` | 2 | 7.3s |  |
| 170 | `class_to_string` | 2 | 7.2s |  |
| 171 | `class_value_of` | 2 | 7.2s |  |
| 172 | `click_block` | 5 | 8.1s |  |
| 173 | `click_invisible` | 3 | 7.4s |  |
| 174 | `closures` | 12 | 7.3s |  |
| 175 | `coerce_return_type` | 40 | 7.4s |  |
| 176 | `coerce_return_type_fail` | 2 | 7.2s |  |
| 177 | `coerce_return_void` | 3 | 7.2s |  |
| 178 | `coerce_string` | 86 | 7.4s |  |
| 179 | `coerce_string_precision` | 28 | 7.3s |  |
| 180 | `coerce_to_primitive_side_effects` | 29 | 7.4s |  |
| 181 | `color_matrix_filter` | 19 | 7.4s |  |
| 182 | `construct_errors_swf10` | 8 | 7.3s |  |
| 183 | `construct_frame_list` | 22 | 26.1s |  |
| 184 | `construct_interface` | 3 | 7.3s |  |
| 185 | `constructor_call` | 3 | 7.2s |  |
| 186 | `constructors_vs_timeline` | 5 | 26.2s |  |
| 187 | `constructprop_dynamic_primitive` | 7 | 7.3s |  |
| 188 | `constructprop_method` | 2 | 7.2s |  |
| 189 | `content_element_basic` | 50 | 7.6s |  |
| 190 | `context3d_creation` | 9 | 7.4s |  |
| 191 | `control_flow_bool` | 4 | 7.3s |  |
| 192 | `control_flow_stricteq` | 8 | 7.3s |  |
| 193 | `convert_boolean` | 30 | 7.3s |  |
| 194 | `convert_integer` | 90 | 7.4s |  |
| 195 | `convert_number` | 56 | 7.3s |  |
| 196 | `convert_uinteger` | 90 | 7.4s |  |
| 197 | `convolution_filter` | 89 | 7.4s |  |
| 198 | `core_exceptions` | 47 | 8.1s |  |
| 199 | `cpool_index_invalid_bytecode_1` | 6 | 7.3s |  |
| 200 | `cpool_index_invalid_bytecode_2` | 3 | 7.2s |  |
| 201 | `cpool_index_invalid_bytecode_3` | 1 | 7.2s |  |
| 202 | `cross_api_version_call_older` | 12 | 7.6s |  |
| 203 | `cryptscore` | 11 | 7.4s |  |
| 204 | `date` | 30 | 7.5s |  |
| 205 | `date_parse` | 36 | 7.1s |  |
| 206 | `declocal` | 46 | 7.1s |  |
| 207 | `declocal_i` | 46 | 7.1s |  |
| 208 | `decode_uri` | 71 | 7.4s |  |
| 209 | `decrement` | 46 | 7.1s |  |
| 210 | `decrement_i` | 46 | 3.1s |  |
| 211 | `default_values` | 7 | 7.0s |  |
| 212 | `dictionary_access` | 62 | 7.3s |  |
| 213 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 214 | `dictionary_delete` | 101 | 7.6s |  |
| 215 | `dictionary_foreach` | 42 | 7.3s |  |
| 216 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 217 | `dictionary_in` | 62 | 7.3s |  |
| 218 | `dictionary_iter_modify` | 8 | 7.1s |  |
| 219 | `dictionary_namespaces` | 36 | 7.2s |  |
| 220 | `dictionary_primitive_keys` | 29 | 7.1s |  |
| 221 | `displacement_map_filter` | 61 | 7.3s |  |
| 222 | `displayobject_alpha` | 277 | 7.0s |  |
| 223 | `displayobject_blendmode` | 0 | 7.2s |  |
| 224 | `displayobject_colortransform_nested` | 0 | 25.9s |  |
| 225 | `displayobject_filters` | 17 | 7.2s |  |
| 226 | `displayobject_from_enterframe` | 1 | 25.8s |  |
| 227 | `displayobject_getbounds_shape` | 0 | 26.0s |  |
| 228 | `displayobject_height` | 6052 | 25.9s |  |
| 229 | `displayobject_hittestobject` | 32 | 7.2s |  |
| 230 | `displayobject_hittestpoint` | 49 | 7.4s |  |
| 231 | `displayobject_hittestpoint_root` | 13 | 7.3s |  |
| 232 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 233 | `displayobject_invalid_props` | 3 | 3.0s |  |
| 234 | `displayobject_mask` | 3 | 7.4s |  |
| 235 | `displayobject_mask_self_referential` | 0 | 7.3s |  |
| 236 | `displayobject_metaData` | 3 | 7.1s |  |
| 237 | `displayobject_name` | 22 | 7.6s |  |
| 238 | `displayobject_name_from_timeline` | 24 | 7.5s |  |
| 239 | `displayobject_opaque_background` | 6 | 26.7s |  |
| 240 | `displayobject_parent` | 12 | 7.3s |  |
| 241 | `displayobject_root` | 24 | 7.4s |  |
| 242 | `displayobject_rotation` | 1284 | 7.4s |  |
| 243 | `displayobject_set_matrix_nested` | 0 | 26.8s |  |
| 244 | `displayobject_set_name_loaded` | 3 | 7.6s |  |
| 245 | `displayobject_subclass` | 2 | 7.4s |  |
| 246 | `displayobject_visible` | 23 | 7.3s |  |
| 247 | `displayobject_width` | 4852 | 27.0s |  |
| 248 | `displayobject_x` | 614 | 7.3s |  |
| 249 | `displayobject_y` | 617 | 7.3s |  |
| 250 | `displayobjectcontainer_addchild` | 32 | 7.4s |  |
| 251 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.3s |  |
| 252 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.5s |  |
| 253 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.4s |  |
| 254 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.4s |  |
| 255 | `displayobjectcontainer_addchildat` | 42 | 7.3s |  |
| 256 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.3s |  |
| 257 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.4s |  |
| 258 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.3s |  |
| 259 | `displayobjectcontainer_contains` | 66 | 26.5s |  |
| 260 | `displayobjectcontainer_getchildat` | 4 | 7.4s |  |
| 261 | `displayobjectcontainer_getchildbyname` | 9 | 7.2s |  |
| 262 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.3s |  |
| 263 | `displayobjectcontainer_getchildindex` | 28 | 7.3s |  |
| 264 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.4s |  |
| 265 | `displayobjectcontainer_removechild` | 10 | 7.2s |  |
| 266 | `displayobjectcontainer_removechild_errors` | 4 | 7.2s |  |
| 267 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.3s |  |
| 268 | `displayobjectcontainer_removechildat` | 18 | 7.3s |  |
| 269 | `displayobjectcontainer_removechildren` | 51 | 7.6s |  |
| 270 | `displayobjectcontainer_setchildindex` | 42 | 7.2s |  |
| 271 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.7s |  |
| 272 | `displayobjectcontainer_swapchildren` | 42 | 7.3s |  |
| 273 | `displayobjectcontainer_swapchildrenat` | 42 | 7.3s |  |
| 274 | `displayobjectcontainer_timelineinstance` | 48 | 27.2s |  |
| 275 | `divide` | 1058 | 19.7s |  |
| 276 | `doabc_is_eager` | 1 | 26.6s |  |
| 277 | `documentclass` | 9 | 7.5s |  |
| 278 | `domain_memory` | 133 | 8.7s |  |
| 279 | `drag_drop` | 10 | 7.7s |  |
| 280 | `drop_shadow_filter` | 172 | 7.6s |  |
| 281 | `duplicate_defs` | 1 | 7.2s |  |
| 282 | `eager_init` | 1 | 7.4s |  |
| 283 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 284 | `edit_text_linkage` | 7 | 7.6s |  |
| 285 | `edittext_align` | 60 | 7.9s |  |
| 286 | `edittext_always_show_selection` | 0 | 27.6s |  |
| 287 | `edittext_antialiastype` | 296 | 7.7s |  |
| 288 | `edittext_at_point_methods_basic` | 16 | 8.8s |  |
| 289 | `edittext_autosize` | 39 | 7.8s |  |
| 290 | `edittext_autosize_align` | 0 | 27.6s |  |
| 291 | `edittext_autosize_height_dynamic` | 60 | 27.6s |  |
| 292 | `edittext_autosize_height_input` | 60 | 7.6s |  |
| 293 | `edittext_autosize_lazy_bounds_events` | 65 | 7.8s |  |
| 294 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.5s |  |
| 295 | `edittext_autosize_lazy_bounds_props` | 490 | 9.0s |  |
| 296 | `edittext_autosize_lazy_bounds_visual` | 0 | 27.2s |  |
| 297 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.6s |  |
| 298 | `edittext_bottom_scroll_v_basic` | 210 | 7.5s |  |
| 299 | `edittext_bounds_scale` | 24 | 26.9s |  |
| 300 | `edittext_bullet` | 30 | 7.5s |  |
| 301 | `edittext_default_format` | 221 | 7.8s |  |
| 302 | `edittext_default_format_empty` | 136 | 7.7s |  |
| 303 | `edittext_empty_text_format` | 7 | 7.5s |  |
| 304 | `edittext_focus_selection` | 5 | 7.4s |  |
| 305 | `edittext_font_size` | 45 | 7.5s |  |
| 306 | `edittext_format_empty_font` | 8 | 7.4s |  |
| 307 | `edittext_get_char_index_at_point` | 4 | 28.6s |  |
| 308 | `edittext_get_line_index_at_point` | 2 | 27.4s |  |
| 309 | `edittext_get_line_index_of_char` | 76 | 8.2s |  |
| 310 | `edittext_getcharboundaries` | 172 | 7.6s |  |
| 311 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.5s |  |
| 312 | `edittext_getcharboundaries_scroll` | 85 | 7.3s |  |
| 313 | `edittext_getlinemetrics` | 146 | 7.5s |  |
| 314 | `edittext_html` | 3101 | 7.7s |  |
| 315 | `edittext_html_condensewhite` | 487 | 7.4s |  |
| 316 | `edittext_html_entity` | 4 | 7.6s |  |
| 317 | `edittext_html_font_size_swf12` | 267 | 7.5s |  |
| 318 | `edittext_html_font_size_swf13` | 273 | 7.1s |  |
| 319 | `edittext_html_roundtrip` | 17 | 7.5s |  |
| 320 | `edittext_ime_focus_lost` | 9 | 26.6s |  |
| 321 | `edittext_input_control` | 12 | 7.6s |  |
| 322 | `edittext_leading` | 9 | 7.8s |  |
| 323 | `edittext_letter_spacing` | 15 | 7.5s |  |
| 324 | `edittext_line_methods` | 294 | 8.6s |  |
| 325 | `edittext_line_metrics` | 11 | 28.1s |  |
| 326 | `edittext_margins` | 25 | 7.3s |  |
| 327 | `edittext_max_scroll_h_basic` | 475 | 7.4s |  |
| 328 | `edittext_max_scroll_v_basic` | 1000 | 7.2s |  |
| 329 | `edittext_mouse_selection` | 363 | 27.3s |  |
| 330 | `edittext_mousedown` | 3 | 7.6s |  |
| 331 | `edittext_mouseenabled` | 26 | 7.2s |  |
| 332 | `edittext_newline_character` | 22 | 7.1s |  |
| 333 | `edittext_newline_stripping` | 64 | 9.8s |  |
| 334 | `edittext_newlines` | 30 | 7.2s |  |
| 335 | `edittext_paragraph_methods` | 257 | 7.1s |  |
| 336 | `edittext_paste_events` | 8 | 7.2s |  |
| 337 | `edittext_paste_maxchars` | 4 | 7.2s |  |
| 338 | `edittext_paste_restrict` | 16 | 7.1s |  |
| 339 | `edittext_restrict` | 191 | 7.2s |  |
| 340 | `edittext_restrict_events` | 22 | 7.1s |  |
| 341 | `edittext_scrollh` | 10 | 3.1s |  |
| 342 | `edittext_selected_text` | 9 | 7.2s |  |
| 343 | `edittext_set_html_same` | 17 | 7.2s |  |
| 344 | `edittext_set_text_vs_html` | 9 | 7.2s |  |
| 345 | `edittext_stylesheet` | 536 | 7.5s |  |
| 346 | `edittext_stylesheet_custom_tag` | 76 | 7.3s |  |
| 347 | `edittext_stylesheet_display` | 272 | 7.3s |  |
| 348 | `edittext_underline` | 40 | 7.2s |  |
| 349 | `edittext_width_height` | 103 | 7.9s |  |
| 350 | `edittext_wordwrap_word` | 150 | 7.7s |  |
| 351 | `edittext_wrap_breaks` | 2375 | 7.8s |  |
| 352 | `element_format_clone` | 44 | 7.3s |  |
| 353 | `element_format_constructor_order` | 64 | 7.4s |  |
| 354 | `element_format_properties` | 235 | 8.3s |  |
| 355 | `empty_bounds` | 1 | 7.4s |  |
| 356 | `encode_uri_surrogate_pair_swf11` | 15 | 6.9s |  |
| 357 | `equals` | 512 | 11.3s |  |
| 358 | `error_geterrormessage` | 779 | 7.2s |  |
| 359 | `error_prototype` | 15 | 7.2s |  |
| 360 | `error_stack_trace_debug_swf17` | 0 | 26.2s |  |
| 361 | `error_stack_trace_debug_swf18` | 0 | 7.1s |  |
| 362 | `error_stack_trace_release_swf17` | 0 | 7.1s |  |
| 363 | `error_stack_trace_release_swf18` | 0 | 7.0s |  |
| 364 | `error_tostring` | 29 | 7.1s |  |
| 365 | `error_tostring_more` | 86 | 7.2s |  |
| 366 | `es3_inheritance` | 31 | 7.3s |  |
| 367 | `es4_inheritance` | 30 | 7.2s |  |
| 368 | `es4_interfaces` | 30 | 7.2s |  |
| 369 | `es4_method_binding` | 8 | 7.2s |  |
| 370 | `es4_oop_prototypes` | 14 | 7.3s |  |
| 371 | `es4_protected_inheritance` | 6 | 7.2s |  |
| 372 | `escape` | 71 | 7.3s |  |
| 373 | `event_bubbles` | 2 | 7.2s |  |
| 374 | `event_cancelable` | 2 | 7.1s |  |
| 375 | `event_clone` | 20 | 7.2s |  |
| 376 | `event_clone_error_redispatch` | 3 | 7.4s |  |
| 377 | `event_clone_on_redispatch` | 10 | 7.4s |  |
| 378 | `event_formattostring` | 31 | 7.3s |  |
| 379 | `event_isdefaultprevented` | 12 | 7.3s |  |
| 380 | `event_target_getter` | 5 | 3.2s |  |
| 381 | `event_target_set` | 9 | 7.2s |  |
| 382 | `event_type` | 1 | 8.1s |  |
| 383 | `event_valueof_tostring` | 18 | 7.6s |  |
| 384 | `eventdispatcher_dispatchevent` | 12 | 7.6s |  |
| 385 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.8s |  |
| 386 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.8s |  |
| 387 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.8s |  |
| 388 | `eventdispatcher_dispatchevent_this` | 5 | 7.5s |  |
| 389 | `eventdispatcher_haseventlistener` | 25 | 7.7s |  |
| 390 | `eventdispatcher_interface_invoke` | 1 | 7.6s |  |
| 391 | `eventdispatcher_tostring` | 10 | 7.6s |  |
| 392 | `eventdispatcher_willtrigger` | 25 | 7.6s |  |
| 393 | `falsiness` | 30 | 7.9s |  |
| 394 | `fast_index_access` | 12 | 8.0s |  |
| 395 | `filefilter_properties` | 4 | 7.8s |  |
| 396 | `filereference_browse_cancel` | 3 | 7.8s |  |
| 397 | `filereference_browse_select` | 9 | 7.8s |  |
| 398 | `filereference_load` | 31 | 3.5s |  |
| 399 | `filereference_save` | 16 | 7.7s |  |
| 400 | `filereference_save_and_browse` | 42 | 7.8s |  |
| 401 | `filereference_save_and_load` | 22 | 7.7s |  |
| 402 | `filereference_uninitialized` | 8 | 7.7s |  |
| 403 | `filereferencelist_browse_cancel` | 6 | 7.7s |  |
| 404 | `filereferencelist_browse_select` | 7 | 7.6s |  |
| 405 | `filter_rewind` | 8 | 8.0s |  |
| 406 | `filters_array_holes` | 25 | 7.8s |  |
| 407 | `finddef` | 3 | 7.7s |  |
| 408 | `findprop_global_prototype` | 6 | 7.7s |  |
| 409 | `flash_media_video_constructor` | 156 | 8.5s |  |
| 410 | `flash_media_video_rotation_probe` | 27 | 7.8s |  |
| 411 | `flash_xml` | 29 | 7.8s |  |
| 412 | `flash_xml_cloneNode` | 22 | 7.8s |  |
| 413 | `flash_xml_namespace` | 109 | 7.7s |  |
| 414 | `flash_xml_removeNode` | 60 | 7.7s |  |
| 415 | `focus_events_code` | 161 | 28.5s |  |
| 416 | `focus_events_key_basic` | 132 | 28.8s |  |
| 417 | `focus_events_key_navigation` | 53 | 7.9s |  |
| 418 | `focus_events_key_same_object` | 26 | 7.8s |  |
| 419 | `focus_events_mixed_key_mouse` | 100 | 28.0s |  |
| 420 | `focus_events_mouse_basic` | 260 | 27.0s |  |
| 421 | `focus_events_mouse_focusable` | 112 | 26.6s |  |
| 422 | `focus_events_mouse_same_object` | 40 | 26.2s |  |
| 423 | `focus_remove` | 20 | 26.1s |  |
| 424 | `focus_root_movie` | 4 | 26.1s |  |
| 425 | `focus_stage` | 1 | 7.3s |  |
| 426 | `focusrect` | 18 | 8.1s |  |
| 427 | `focusrect_focuslost` | 9 | 7.4s |  |
| 428 | `focusrect_property` | 110 | 7.4s |  |
| 429 | `font_description_clone` | 14 | 7.3s |  |
| 430 | `font_embedded` | 24 | 7.7s |  |
| 431 | `font_enumeratefonts` | 41 | 7.9s |  |
| 432 | `font_enumeratefonts_filter` | 4 | 26.5s |  |
| 433 | `font_hasglyphs` | 40 | 7.7s |  |
| 434 | `framelabel_constr` | 5 | 7.3s |  |
| 435 | `function_call` | 12 | 7.4s |  |
| 436 | `function_call_arguments` | 46 | 3.3s |  |
| 437 | `function_call_arguments_enumerate` | 5 | 7.3s |  |
| 438 | `function_call_coercion` | 108 | 7.7s |  |
| 439 | `function_call_default` | 6 | 7.3s |  |
| 440 | `function_call_rest` | 22 | 7.3s |  |
| 441 | `function_call_types` | 3 | 7.3s |  |
| 442 | `function_call_via_apply` | 11 | 7.3s |  |
| 443 | `function_call_via_call` | 3 | 7.3s |  |
| 444 | `function_display_anonymous` | 7 | 3.2s |  |
| 445 | `function_length` | 6 | 7.3s |  |
| 446 | `function_object` | 2 | 7.3s |  |
| 447 | `function_proto` | 5 | 7.3s |  |
| 448 | `function_proto_created` | 61 | 7.3s |  |
| 449 | `function_to_locale_string` | 4 | 7.3s |  |
| 450 | `function_to_string` | 4 | 7.2s |  |
| 451 | `function_type` | 6 | 7.3s |  |
| 452 | `function_unbound_this` | 51 | 7.4s |  |
| 453 | `function_value_of` | 4 | 7.3s |  |
| 454 | `game_input` | 4 | 7.3s |  |
| 455 | `generate_random_bytes` | 3 | 7.3s |  |
| 456 | `get_definition_by_name` | 11 | 7.3s |  |
| 457 | `get_qualified_class_name` | 20 | 6.0s |  |
| 458 | `get_qualified_super_class_name` | 18 | 5.6s |  |
| 459 | `get_slot_edge_cases` | 1 | 21.1s |  |
| 460 | `get_timer` | 2 | 5.6s |  |
| 461 | `getglobalslot` | 1 | 5.5s |  |
| 462 | `getouterscope` | 8 | 5.5s |  |
| 463 | `getter_different_namespace_setter` | 2 | 5.7s |  |
| 464 | `glow_filter` | 127 | 6.0s |  |
| 465 | `goto_button_nested_framescript` | 28 | 21.4s |  |
| 466 | `goto_in_constructframe` | 12 | 5.8s |  |
| 467 | `goto_in_scene_last_frame` | 2 | 21.1s |  |
| 468 | `goto_methods` | 56 | 5.8s |  |
| 469 | `goto_methods_swfver10` | 8 | 5.6s |  |
| 470 | `goto_nested_construct_sibling` | 18 | 5.9s |  |
| 471 | `goto_nested_framescript` | 9 | 5.7s |  |
| 472 | `goto_on_orphan` | 15 | 5.8s |  |
| 473 | `gradient_bevel_filter` | 206 | 5.7s |  |
| 474 | `gradient_glow_filter` | 206 | 5.6s |  |
| 475 | `graphics_bad_direct_commands` | 5 | 6.2s |  |
| 476 | `graphics_bitmap_fill` | 0 | 7.0s |  |
| 477 | `graphics_bitmaps` | 0 | 6.1s |  |
| 478 | `graphics_direct_commands` | 0 | 6.1s |  |
| 479 | `graphics_draw_triangles` | 98 | 21.9s |  |
| 480 | `graphics_gradients` | 0 | 5.8s |  |
| 481 | `graphics_gradients_nulls` | 0 | 5.7s |  |
| 482 | `graphics_path` | 56 | 5.6s |  |
| 483 | `graphics_round_rects` | 0 | 5.6s |  |
| 484 | `graphics_simple_shapes` | 0 | 5.8s |  |
| 485 | `greaterequals` | 512 | 8.0s |  |
| 486 | `greaterthan` | 512 | 8.0s |  |
| 487 | `has_own_property` | 102 | 6.0s |  |
| 488 | `hasownproperty_namespaces` | 2 | 5.6s |  |
| 489 | `hello_world` | 1 | 5.6s |  |
| 490 | `hittest_morph` | 30 | 5.7s |  |
| 491 | `if_eq` | 10 | 5.6s |  |
| 492 | `if_gt` | 1 | 5.7s |  |
| 493 | `if_gte` | 10 | 8.2s |  |
| 494 | `if_lt` | 1 | 7.7s |  |
| 495 | `if_lte` | 10 | 7.6s |  |
| 496 | `if_ne` | 7 | 3.4s |  |
| 497 | `if_stricteq` | 6 | 7.7s |  |
| 498 | `if_strictne` | 11 | 7.8s |  |
| 499 | `ime_linux_dead_keys` | 10 | 7.9s |  |
| 500 | `in` | 102 | 8.2s |  |
| 501 | `inclocal` | 46 | 7.7s |  |
| 502 | `inclocal_i` | 46 | 7.7s |  |
| 503 | `increment` | 46 | 7.7s |  |
| 504 | `increment_i` | 46 | 7.7s |  |
| 505 | `indexing_delete` | 75 | 7.6s |  |
| 506 | `instanceof` | 58 | 7.9s |  |
| 507 | `instantiation_on_enter_frame` | 7 | 27.4s |  |
| 508 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.6s |  |
| 509 | `int_constr` | 92 | 7.5s |  |
| 510 | `int_edge_cases` | 19 | 7.6s |  |
| 511 | `int_instanceof` | 3 | 7.5s |  |
| 512 | `int_tofixed` | 1215 | 7.5s |  |
| 513 | `int_tostring` | 3375 | 7.6s |  |
| 514 | `interactiveobject_enabled` | 25 | 7.5s |  |
| 515 | `interface_namespaces` | 78 | 7.8s |  |
| 516 | `is_finite` | 46 | 7.8s |  |
| 517 | `is_nan` | 46 | 7.5s |  |
| 518 | `is_prototype_of` | 12 | 7.6s |  |
| 519 | `issue_10221` | 2 | 7.6s |  |
| 520 | `issue_13780` | 12 | 7.7s |  |
| 521 | `issue_14901` | 1 | 7.5s |  |
| 522 | `issue_17675_edittext_paste_maxchars` | 1 | 7.7s |  |
| 523 | `issue_5292` | 5 | 7.7s |  |
| 524 | `issue_8630` | 2 | 27.4s |  |
| 525 | `issue_8630_scriptremove` | 11 | 7.4s |  |
| 526 | `istype` | 24 | 3.3s |  |
| 527 | `istypelate` | 58 | 7.6s |  |
| 528 | `istypelate_coerce` | 198 | 8.1s |  |
| 529 | `jpeg_loader_context` | 6 | 6.7s |  |
| 530 | `json_errors` | 9 | 25.8s |  |
| 531 | `json_parse` | 21 | 6.7s |  |
| 532 | `json_stringify` | 12 | 6.9s |  |
| 533 | `json_stringify_order` | 1 | 6.7s |  |
| 534 | `json_version_gated` | 1 | 6.7s |  |
| 535 | `key_input_80percent` | 1812 | 7.0s |  |
| 536 | `key_input_location` | 126 | 6.7s |  |
| 537 | `key_input_numpad` | 384 | 6.6s |  |
| 538 | `lazyinit` | 17 | 6.7s |  |
| 539 | `lessequals` | 512 | 10.0s |  |
| 540 | `lessthan` | 512 | 10.0s |  |
| 541 | `loader_bitmap_transparency` | 14 | 6.8s |  |
| 542 | `loader_bytes_unknown_content` | 14 | 6.8s |  |
| 543 | `loader_child_getdefinition` | 5 | 6.9s |  |
| 544 | `loader_duplicate_coerce` | 3 | 6.9s |  |
| 545 | `loader_duplicate_coerce_new_domain` | 4 | 6.8s |  |
| 546 | `loader_error_in_root_ctor` | 4 | 7.0s |  |
| 547 | `loader_events` | 92 | 7.4s |  |
| 548 | `loader_image` | 8 | 7.0s |  |
| 549 | `loader_jpegxr` | 2 | 25.9s |  |
| 550 | `loader_jpegxr_alpha` | 1 | 25.5s |  |
| 551 | `loader_loadbytes_events` | 30 | 7.4s |  |
| 552 | `loader_loadbytes_invalid_png` | 4 | 25.2s |  |
| 553 | `loader_loadbytes_url` | 12 | 7.0s |  |
| 554 | `loader_loaderurl` | 6 | 7.2s |  |
| 555 | `loader_noninteractive_try_click_root` | 5 | 26.0s |  |
| 556 | `loader_reuse` | 38 | 6.9s |  |
| 557 | `loader_unknown_content` | 24 | 6.8s |  |
| 558 | `loader_visibility_interactive` | 1 | 6.9s |  |
| 559 | `loaderinfo_events` | 7 | 6.7s |  |
| 560 | `loaderinfo_loadurl` | 12 | 7.7s |  |
| 561 | `loaderinfo_more` | 6 | 7.7s |  |
| 562 | `loaderinfo_properties` | 18 | 7.3s |  |
| 563 | `loaderinfo_properties_not_loaded` | 23 | 7.4s |  |
| 564 | `loaderinfo_root` | 10 | 7.3s |  |
| 565 | `loaderinfo_root_allows` | 2 | 7.2s |  |
| 566 | `localconnection_send` | 4 | 7.1s |  |
| 567 | `lshift` | 1058 | 19.4s |  |
| 568 | `mask_reapply` | 1 | 7.3s |  |
| 569 | `math` | 497 | 7.4s |  |
| 570 | `matrix3d` | 57 | 8.0s |  |
| 571 | `matrix3d_compose` | 34 | 7.5s |  |
| 572 | `matrix3d_invert` | 18 | 3.2s |  |
| 573 | `method_without_body` | 3 | 26.4s |  |
| 574 | `missing_external_interface` | 10 | 7.2s |  |
| 575 | `modulo` | 1058 | 19.7s |  |
| 576 | `morph_shape` | 2 | 26.2s |  |
| 577 | `mouse_children` | 192 | 26.4s |  |
| 578 | `mouse_click_events` | 90 | 26.6s |  |
| 579 | `mouse_double_click_events` | 188 | 7.3s |  |
| 580 | `mouse_empty_parent` | 4 | 7.3s |  |
| 581 | `mouse_over_while_dragging` | 3 | 7.2s |  |
| 582 | `mouse_pick_button_mode` | 2 | 7.4s |  |
| 583 | `mouse_pick_dobj_mask` | 4 | 7.6s |  |
| 584 | `mouse_pick_masking` | 7 | 26.4s |  |
| 585 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 25.9s |  |
| 586 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.7s |  |
| 587 | `mouse_pick_text` | 8 | 7.3s |  |
| 588 | `mouse_sibling` | 8 | 7.3s |  |
| 589 | `mouse_wheel_events` | 36 | 27.1s |  |
| 590 | `mouseevent_constr` | 66 | 7.2s |  |
| 591 | `mouseevent_stagexy` | 35 | 7.3s |  |
| 592 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 593 | `movieclip_addframescript` | 3 | 26.0s |  |
| 594 | `movieclip_child_property` | 16 | 7.3s |  |
| 595 | `movieclip_constr` | 21 | 7.8s |  |
| 596 | `movieclip_currentlabels` | 17 | 25.8s |  |
| 597 | `movieclip_currentlabels_dupes1` | 46 | 25.9s |  |
| 598 | `movieclip_currentlabels_dupes2` | 30 | 7.2s |  |
| 599 | `movieclip_currentlabels_dupes3` | 67 | 7.2s |  |
| 600 | `movieclip_currentscene` | 12 | 7.1s |  |
| 601 | `movieclip_dispatchevent` | 430 | 7.2s |  |
| 602 | `movieclip_dispatchevent_cancel` | 102 | 7.2s |  |
| 603 | `movieclip_dispatchevent_handlerorder` | 251 | 7.2s |  |
| 604 | `movieclip_dispatchevent_selfadd` | 80 | 7.1s |  |
| 605 | `movieclip_dispatchevent_target` | 899 | 7.2s |  |
| 606 | `movieclip_displayevents` | 96 | 26.1s |  |
| 607 | `movieclip_displayevents_clickgoto` | 676 | 7.7s |  |
| 608 | `movieclip_displayevents_clickgoto2` | 2001 | 7.8s |  |
| 609 | `movieclip_displayevents_clickplay` | 575 | 7.4s |  |
| 610 | `movieclip_displayevents_clicksymbol` | 562 | 7.5s |  |
| 611 | `movieclip_displayevents_constructframegoto` | 140 | 7.6s |  |
| 612 | `movieclip_displayevents_constructframeplay` | 50 | 7.4s |  |
| 613 | `movieclip_displayevents_constructframesymbol` | 144 | 7.3s |  |
| 614 | `movieclip_displayevents_dblhandler` | 21 | 7.3s |  |
| 615 | `movieclip_displayevents_enterframegoto` | 149 | 7.4s |  |
| 616 | `movieclip_displayevents_enterframeplay` | 48 | 7.3s |  |
| 617 | `movieclip_displayevents_enterframesymbol` | 149 | 26.1s |  |
| 618 | `movieclip_displayevents_exitframegoto` | 106 | 7.2s |  |
| 619 | `movieclip_displayevents_exitframeplay` | 44 | 7.3s |  |
| 620 | `movieclip_displayevents_exitframesymbol` | 135 | 7.3s |  |
| 621 | `movieclip_displayevents_looping` | 63 | 26.1s |  |
| 622 | `movieclip_displayevents_stopped` | 113 | 7.6s |  |
| 623 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 624 | `movieclip_displayevents_timeline` | 128 | 26.1s |  |
| 625 | `movieclip_drawrect` | 54 | 7.2s |  |
| 626 | `movieclip_frameconstruct_skipped` | 9 | 7.2s |  |
| 627 | `movieclip_goto_during_frame_script` | 15 | 7.3s |  |
| 628 | `movieclip_goto_overwrite` | 14 | 25.9s |  |
| 629 | `movieclip_goto_scene_last_frame_int` | 1 | 25.9s |  |
| 630 | `movieclip_goto_scene_last_frame_label` | 1 | 3.0s |  |
| 631 | `movieclip_gotoandplay` | 15 | 25.6s |  |
| 632 | `movieclip_gotoandstop` | 13 | 25.7s |  |
| 633 | `movieclip_gotoandstop_children` | 4 | 7.2s |  |
| 634 | `movieclip_gotoandstop_framescripts1` | 4 | 7.2s |  |
| 635 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 636 | `movieclip_gotoandstop_framescripts_self` | 7 | 26.2s |  |
| 637 | `movieclip_gotoandstop_queueing` | 12 | 25.8s |  |
| 638 | `movieclip_hittest` | 67 | 6.9s |  |
| 639 | `movieclip_next_frame` | 2 | 6.8s |  |
| 640 | `movieclip_next_scene` | 6 | 25.6s |  |
| 641 | `movieclip_play` | 3 | 2.7s |  |
| 642 | `movieclip_prev_frame` | 3 | 6.6s |  |
| 643 | `movieclip_prev_scene` | 7 | 6.8s |  |
| 644 | `movieclip_properties` | 79 | 7.0s |  |
| 645 | `movieclip_queued_noop_goto_swf10` | 9 | 6.8s |  |
| 646 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 647 | `movieclip_scenes` | 11 | 6.7s |  |
| 648 | `movieclip_soundtransform` | 831 | 27.4s |  |
| 649 | `movieclip_stop` | 1 | 6.8s |  |
| 650 | `movieclip_super_is_symbol` | 20 | 7.1s |  |
| 651 | `movieclip_symbol_constr` | 8 | 6.9s |  |
| 652 | `movieclip_text_mousedown` | 1 | 6.9s |  |
| 653 | `movieclip_willtrigger` | 5 | 6.8s |  |
| 654 | `multiply` | 1058 | 16.4s |  |
| 655 | `namespace_constr` | 253 | 7.0s |  |
| 656 | `namespace_constr_args` | 1 | 6.7s |  |
| 657 | `namespace_enumeration_order` | 7 | 6.9s |  |
| 658 | `nan_scale` | 9 | 6.8s |  |
| 659 | `navigateToURL_target_normalize` | 107 | 27.3s |  |
| 660 | `negate` | 30 | 6.8s |  |
| 661 | `negative_volume_panned` | 0 | 7.0s |  |
| 662 | `nested_iteration` | 11 | 6.8s |  |
| 663 | `net_getClassByAlias` | 3 | 6.8s |  |
| 664 | `net_navigateToURL` | 57 | 6.8s |  |
| 665 | `net_stream_play_options` | 6 | 6.8s |  |
| 666 | `netconnection_close` | 55 | 6.9s |  |
| 667 | `netconnection_properties` | 78 | 6.9s |  |
| 668 | `netconnection_send_remote` | 50 | 7.2s |  |
| 669 | `netconnection_serialize_arrays` | 6 | 6.9s |  |
| 670 | `netstream_client` | 10 | 7.0s |  |
| 671 | `netstream_connect` | 7 | 6.8s |  |
| 672 | `newactivation_in_script_init` | 3 | 7.3s |  |
| 673 | `newclass_mismatched` | 4 | 7.3s |  |
| 674 | `newclass_twice` | 3 | 7.3s |  |
| 675 | `nonconflicting_declarations` | 0 | 7.3s |  |
| 676 | `null_void_types` | 8 | 7.4s |  |
| 677 | `number_autoconv` | 21 | 3.3s |  |
| 678 | `number_autoconv_amf` | 132 | 7.4s |  |
| 679 | `number_autoconv_array_sort_32bit` | 1 | 7.4s |  |
| 680 | `number_constr` | 58 | 7.5s |  |
| 681 | `number_toexponential` | 378 | 7.5s |  |
| 682 | `number_toexponential2` | 35 | 7.3s |  |
| 683 | `number_tofixed` | 378 | 7.3s |  |
| 684 | `number_toprecision` | 350 | 7.4s |  |
| 685 | `obfuscated_class_names` | 3 | 7.4s |  |
| 686 | `object_enumeration` | 10 | 7.3s |  |
| 687 | `object_prototype` | 4 | 7.4s |  |
| 688 | `object_to_locale_string` | 2 | 7.4s |  |
| 689 | `object_to_string` | 2 | 7.3s |  |
| 690 | `object_value_of` | 2 | 3.1s |  |
| 691 | `op_coerce` | 54 | 3.3s |  |
| 692 | `op_coerce_x` | 54 | 7.5s |  |
| 693 | `op_escxattr` | 2 | 7.4s |  |
| 694 | `op_escxelem` | 2 | 7.3s |  |
| 695 | `op_lookupswitch` | 4 | 7.4s |  |
| 696 | `optimize_coerce` | 1 | 7.3s |  |
| 697 | `orphan_movie_complex` | 80 | 7.9s |  |
| 698 | `orphan_movie_reorder` | 111 | 27.4s |  |
| 699 | `package_namespace` | 7 | 7.3s |  |
| 700 | `param_default_value_has_zero_cpool_index` | 1 | 7.5s |  |
| 701 | `parent_early_access_child` | 16 | 7.8s |  |
| 702 | `parse_float` | 81 | 7.8s |  |
| 703 | `parse_int` | 135 | 8.2s |  |
| 704 | `perspective_projection_basic` | 40 | 7.7s |  |
| 705 | `pixelbender_ceil` | 77 | 7.8s |  |
| 706 | `pixelbender_conditional` | 138 | 8.3s |  |
| 707 | `pixelbender_conversions` | 270 | 7.9s |  |
| 708 | `pixelbender_dithering` | 8 | 33.4s |  |
| 709 | `pixelbender_div` | 36 | 7.6s |  |
| 710 | `pixelbender_effect_BlurredFocus` | 0 | 34.9s |  |
| 711 | `pixelbender_effect_glassDisplace` | 0 | 13.5s |  |
| 712 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 32.2s |  |
| 713 | `pixelbender_effect_smudge` | 0 | 11.2s |  |
| 714 | `pixelbender_effect_tintype` | 0 | 10.3s |  |
| 715 | `pixelbender_effect_twirl` | 0 | 11.4s |  |
| 716 | `pixelbender_eof` | 7 | 7.5s |  |
| 717 | `pixelbender_images` | 0 | 10.0s |  |
| 718 | `pixelbender_input` | 103 | 27.7s |  |
| 719 | `pixelbender_logicalnot` | 20 | 7.4s |  |
| 720 | `pixelbender_malformed_data` | 190 | 27.8s |  |
| 721 | `pixelbender_multiple_out_params` | 1 | 3.2s |  |
| 722 | `pixelbender_no_out_param` | 6 | 7.4s |  |
| 723 | `pixelbender_outputs` | 13 | 7.7s |  |
| 724 | `pixelbender_padding_bytes` | 22 | 7.4s |  |
| 725 | `pixelbender_param_qualifier` | 512 | 7.5s |  |
| 726 | `pixelbender_parameters` | 1563 | 7.8s |  |
| 727 | `pixelbender_parameters_bool` | 240 | 7.8s |  |
| 728 | `pixelbender_parameters_int_vs_bool` | 54 | 7.7s |  |
| 729 | `pixelbender_parse_errors` | 6 | 7.5s |  |
| 730 | `pixelbender_rsqrt` | 24 | 7.7s |  |
| 731 | `pixelbender_select_kinds` | 8 | 7.5s |  |
| 732 | `pixelbender_shaderdata` | 49 | 7.5s |  |
| 733 | `pixelbender_shaderdata_setter` | 99 | 7.8s |  |
| 734 | `pixelbender_sign` | 60 | 7.5s |  |
| 735 | `pixelbender_vector_output` | 11 | 7.6s |  |
| 736 | `place_and_lookup/swf10` | 33 | 3.3s |  |
| 737 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 738 | `place_multiple` | 17 | 27.0s |  |
| 739 | `place_object_replace` | 9 | 7.7s |  |
| 740 | `place_object_replace_2` | 24 | 7.6s |  |
| 741 | `place_object_same_depth_frame` | 1 | 7.5s |  |
| 742 | `point` | 132 | 7.9s |  |
| 743 | `primitive_edge_cases` | 1 | 7.4s |  |
| 744 | `print_job_options` | 3 | 7.5s |  |
| 745 | `property_is_enumerable_reset` | 23 | 7.0s |  |
| 746 | `property_priority` | 22 | 7.3s |  |
| 747 | `property_priority_chained` | 4 | 6.9s |  |
| 748 | `property_priority_definition_names_order` | 2 | 7.2s |  |
| 749 | `property_priority_three_level` | 6 | 25.2s |  |
| 750 | `propertyisenumerable_namespaces` | 6 | 7.0s |  |
| 751 | `prototype_set_null` | 7 | 7.0s |  |
| 752 | `proxy_callproperty` | 24 | 7.0s |  |
| 753 | `proxy_deleteproperty` | 64 | 7.1s |  |
| 754 | `proxy_enumeration` | 34 | 7.0s |  |
| 755 | `proxy_getproperty` | 77 | 7.1s |  |
| 756 | `proxy_hasownproperty` | 8 | 7.0s |  |
| 757 | `proxy_hasproperty` | 32 | 7.1s |  |
| 758 | `proxy_serialize` | 9 | 7.0s |  |
| 759 | `proxy_setproperty` | 42 | 7.0s |  |
| 760 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.9s |  |
| 761 | `qname_constr` | 32 | 7.0s |  |
| 762 | `qname_constr_namespace` | 24 | 7.0s |  |
| 763 | `qname_enumeration` | 9 | 7.0s |  |
| 764 | `qname_indexing` | 23 | 7.0s |  |
| 765 | `qname_tostring` | 25 | 7.0s |  |
| 766 | `qname_valueof` | 29 | 7.0s |  |
| 767 | `rectangle` | 1094 | 7.7s |  |
| 768 | `regexp_constr` | 148 | 7.2s |  |
| 769 | `regexp_exec` | 19 | 7.0s |  |
| 770 | `regexp_extended` | 47 | 7.0s |  |
| 771 | `regexp_multiargs` | 1 | 6.9s |  |
| 772 | `regexp_test` | 27 | 3.0s |  |
| 773 | `regexp_toString` | 10 | 7.0s |  |
| 774 | `register_script_refresh` | 35 | 7.3s |  |
| 775 | `remove_child_clear_field` | 88 | 7.3s |  |
| 776 | `remove_dobj` | 3 | 7.0s |  |
| 777 | `resolve_order` | 4 | 7.0s |  |
| 778 | `responder_null_callbacks` | 1 | 7.0s |  |
| 779 | `rng` | 1 | 8.1s |  |
| 780 | `rootless` | 42 | 7.1s |  |
| 781 | `rshift` | 1058 | 18.9s |  |
| 782 | `sandbox_type_inherited` | 2 | 7.4s |  |
| 783 | `sandbox_type_local_file` | 1 | 7.5s |  |
| 784 | `sandbox_type_local_network` | 1 | 6.9s |  |
| 785 | `scene_constr` | 8 | 7.0s |  |
| 786 | `scopes_dont_cache/order-1` | 1 | 25.3s |  |
| 787 | `scopes_dont_cache/order-2` | 1 | 0.9s |  |
| 788 | `security_domain_current` | 2 | 3.0s |  |
| 789 | `selection` | 239 | 7.5s |  |
| 790 | `set_local_0` | 31 | 7.1s |  |
| 791 | `set_property_is_enumerable` | 85 | 7.5s |  |
| 792 | `shaderparameter_value` | 4 | 7.0s |  |
| 793 | `shape_drawrect` | 54 | 7.1s |  |
| 794 | `shared_object_no_root` | 3 | 7.0s |  |
| 795 | `simplebutton_added_to_stage` | 45 | 25.5s |  |
| 796 | `simplebutton_childevents` | 86 | 25.8s |  |
| 797 | `simplebutton_childevents_nested` | 54 | 7.4s |  |
| 798 | `simplebutton_childevents_sprite` | 13 | 7.2s |  |
| 799 | `simplebutton_childprops` | 144 | 7.3s |  |
| 800 | `simplebutton_childshuffle` | 23 | 7.0s |  |
| 801 | `simplebutton_constr` | 36 | 7.3s |  |
| 802 | `simplebutton_constr_childevents` | 48 | 7.3s |  |
| 803 | `simplebutton_constr_params` | 42 | 7.2s |  |
| 804 | `simplebutton_mouseenabled` | 26 | 7.1s |  |
| 805 | `simplebutton_multi_children` | 19 | 7.3s |  |
| 806 | `simplebutton_structure` | 27 | 7.3s |  |
| 807 | `simplebutton_symbolclass` | 68 | 7.3s |  |
| 808 | `slot_disp_id_shared_numbering` | 1 | 25.2s |  |
| 809 | `slots_force_autoassigned` | 1 | 7.1s |  |
| 810 | `socket_after_disconnect` | 1 | 7.2s |  |
| 811 | `socket_close` | 2 | 7.0s |  |
| 812 | `socket_connect` | 4 | 7.0s |  |
| 813 | `socket_errors` | 56 | 7.5s |  |
| 814 | `socket_read_big` | 48 | 7.1s |  |
| 815 | `socket_read_little` | 48 | 3.0s |  |
| 816 | `socket_read_write_object` | 8 | 7.6s |  |
| 817 | `socket_write_big` | 15 | 7.3s |  |
| 818 | `socket_write_little` | 14 | 7.0s |  |
| 819 | `sound_embeddedprops` | 26 | 7.2s |  |
| 820 | `sound_play` | 19 | 7.2s |  |
| 821 | `sound_valueof` | 33 | 7.1s |  |
| 822 | `soundchannel_soundtransform` | 835 | 27.3s |  |
| 823 | `soundchannel_soundtransform_exists` | 5 | 25.3s |  |
| 824 | `soundchannel_stop` | 8 | 7.2s |  |
| 825 | `soundmixer_buffertime` | 5 | 7.0s |  |
| 826 | `soundmixer_stopall` | 6 | 7.1s |  |
| 827 | `soundtransform` | 442 | 8.6s |  |
| 828 | `space_justifier_clone` | 12 | 3.0s |  |
| 829 | `sprite_with_frames` | 0 | 25.9s |  |
| 830 | `stage3d_agal_cross_product` | 0 | 9.6s |  |
| 831 | `stage3d_agal_upload_errors` | 66 | 9.7s |  |
| 832 | `stage3d_bitmap` | 0 | 30.5s |  |
| 833 | `stage3d_blend` | 81 | 29.7s |  |
| 834 | `stage3d_context3d_string_args` | 158 | 8.0s |  |
| 835 | `stage3d_errors` | 7 | 7.1s |  |
| 836 | `stage3d_errors_atf` | 3 | 8.4s |  |
| 837 | `stage3d_errors_swf_29` | 6 | 7.2s |  |
| 838 | `stage3d_float1_index` | 0 | 27.7s |  |
| 839 | `stage3d_fractal` | 0 | 28.5s |  |
| 840 | `stage3d_ignore_sampler_override` | 0 | 28.3s |  |
| 841 | `stage3d_multistage_triangle` | 3 | 9.9s |  |
| 842 | `stage3d_program_constants_bytearray_be` | 0 | 29.4s |  |
| 843 | `stage3d_program_constants_bytearray_le` | 0 | 10.4s |  |
| 844 | `stage3d_program_constants_invalid_input` | 21 | 8.0s |  |
| 845 | `stage3d_raytrace` | 0 | 33.0s |  |
| 846 | `stage3d_rotating_cube` | 0 | 10.6s |  |
| 847 | `stage3d_sampler` | 0 | 9.8s |  |
| 848 | `stage3d_sampler_partial_upload` | 0 | 9.7s |  |
| 849 | `stage3d_stencil` | 0 | 28.9s |  |
| 850 | `stage3d_texture` | 0 | 10.9s |  |
| 851 | `stage3d_texture_bytearray` | 0 | 7.6s |  |
| 852 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 7.1s |  |
| 853 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 8.7s |  |
| 854 | `stage3d_triangle` | 0 | 7.1s |  |
| 855 | `stage3d_triangle_bytes4` | 0 | 6.7s |  |
| 856 | `stage3d_triangle_float1` | 0 | 6.7s |  |
| 857 | `stage3d_triangle_index_upload` | 0 | 7.4s |  |
| 858 | `stage3d_x_y` | 22 | 5.0s |  |
| 859 | `stage_access` | 10 | 2.0s |  |
| 860 | `stage_displayobject_properties` | 24 | 4.7s |  |
| 861 | `stage_domain_getQualifiedDefinitionNames` | 5 | 4.7s |  |
| 862 | `stage_framerate_nan` | 7 | 2.0s |  |
| 863 | `stage_framerate_negative` | 6 | 4.9s |  |
| 864 | `stage_framerate_zero` | 6 | 4.9s |  |
| 865 | `stage_invalidate` | 38 | 5.4s |  |
| 866 | `stage_loaderinfo_properties` | 24 | 5.9s |  |
| 867 | `stage_mousechildren` | 2 | 5.2s |  |
| 868 | `stage_mouseenabled` | 15 | 5.4s |  |
| 869 | `stage_overriden_setters` | 31 | 5.0s |  |
| 870 | `stage_properties` | 30 | 5.3s |  |
| 871 | `stage_stage3Ds_vector` | 1 | 18.1s |  |
| 872 | `static_text` | 3 | 5.0s |  |
| 873 | `static_var_with_this_in_ctor` | 2 | 5.0s |  |
| 874 | `stored_properties` | 11 | 5.5s |  |
| 875 | `strict_equality` | 34 | 5.3s |  |
| 876 | `string_call` | 13 | 4.8s |  |
| 877 | `string_case` | 23 | 4.9s |  |
| 878 | `string_char_at` | 27 | 5.5s |  |
| 879 | `string_char_code_at` | 28 | 5.3s |  |
| 880 | `string_concat_fromcharcode` | 37 | 4.9s |  |
| 881 | `string_constr` | 25 | 5.0s |  |
| 882 | `string_indexof_lastindexof` | 87 | 5.0s |  |
| 883 | `string_length` | 16 | 4.8s |  |
| 884 | `string_locale_compare` | 39 | 5.3s |  |
| 885 | `string_match` | 51 | 8.1s |  |
| 886 | `string_relational_compare` | 4 | 7.3s |  |
| 887 | `string_replace` | 51 | 7.5s |  |
| 888 | `string_search` | 41 | 7.6s |  |
| 889 | `string_slice_substr_substring` | 170 | 8.7s |  |
| 890 | `string_split` | 29 | 7.5s |  |
| 891 | `string_substr_negative` | 21 | 7.4s |  |
| 892 | `string_substr_weird` | 182 | 7.3s |  |
| 893 | `subtract` | 1058 | 19.6s |  |
| 894 | `super_get_call` | 12 | 7.4s |  |
| 895 | `supercall_two_classobjects` | 2 | 7.4s |  |
| 896 | `swf8` | 1 | 7.4s |  |
| 897 | `swf_10_queued_goto_scripts_construct` | 52 | 7.8s |  |
| 898 | `swf_9_goto_in_enter_frame` | 17 | 7.7s |  |
| 899 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.6s |  |
| 900 | `swf_9_queued_goto_scripts` | 6 | 7.6s |  |
| 901 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 902 | `swf_9_versioning` | 2 | 7.4s |  |
| 903 | `swf_wrong_frame_count` | 38 | 7.8s |  |
| 904 | `swf_wrong_frame_count_isplaying` | 22 | 27.1s |  |
| 905 | `symbol_class_binary_data` | 8 | 7.6s |  |
| 906 | `symbol_class_conflict` | 4 | 8.1s |  |
| 907 | `symbol_class_root_not_zero` | 1 | 7.4s |  |
| 908 | `symbolclass_invalid_utf8` | 2 | 7.5s |  |
| 909 | `tab_ordering_arrows` | 998 | 28.6s |  |
| 910 | `tab_ordering_automatic_advanced` | 184 | 8.5s |  |
| 911 | `tab_ordering_automatic_basic` | 45 | 7.5s |  |
| 912 | `tab_ordering_children` | 116 | 8.0s |  |
| 913 | `tab_ordering_custom_basic` | 34 | 7.3s |  |
| 914 | `tab_ordering_stage_tab_children` | 32 | 7.4s |  |
| 915 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.2s |  |
| 916 | `tab_ordering_tabbable` | 47 | 7.3s |  |
| 917 | `tabstop_properties` | 105 | 7.6s |  |
| 918 | `text_element_basic` | 34 | 7.5s |  |
| 919 | `text_engine_fontdescription` | 27 | 7.4s |  |
| 920 | `text_engine_groupelement` | 64 | 8.1s |  |
| 921 | `text_run` | 7 | 7.1s |  |
| 922 | `textblock_createline_errors` | 23 | 7.6s |  |
| 923 | `textblock_createline_fte` | 9 | 27.1s |  |
| 924 | `textblock_properties` | 118 | 7.6s |  |
| 925 | `textbox_click` | 37 | 26.0s |  |
| 926 | `textfield_event` | 66 | 7.4s |  |
| 927 | `textfield_focusin_event` | 9 | 7.1s |  |
| 928 | `textfield_input_dead_keys_windows` | 15 | 7.2s |  |
| 929 | `textfield_unload` | 39 | 26.1s |  |
| 930 | `textformat` | 1134 | 7.3s |  |
| 931 | `textformat_display` | 14 | 7.2s |  |
| 932 | `textformat_font_max_length` | 4 | 3.0s |  |
| 933 | `textline_inapplicable_properties` | 10 | 7.2s |  |
| 934 | `textline_name` | 1 | 7.3s |  |
| 935 | `textline_splitting_basic` | 76 | 7.5s |  |
| 936 | `textline_throwerror` | 30 | 7.2s |  |
| 937 | `textline_validity` | 162 | 7.4s |  |
| 938 | `throw` | 3 | 7.2s |  |
| 939 | `timeline_scripts` | 3 | 7.3s |  |
| 940 | `timer` | 90 | 8.2s |  |
| 941 | `timer_events` | 3 | 7.2s |  |
| 942 | `timer_finished` | 11 | 3.2s |  |
| 943 | `timer_reset` | 8 | 7.4s |  |
| 944 | `timer_setdelay` | 5 | 7.4s |  |
| 945 | `trace` | 12 | 7.0s |  |
| 946 | `truthiness` | 30 | 6.3s |  |
| 947 | `try_catch` | 11 | 1.6s |  |
| 948 | `try_catch_typed` | 12 | 1.1s |  |
| 949 | `typeof` | 30 | 1.0s |  |
| 950 | `uint_constr` | 92 | 1.0s |  |
| 951 | `uint_tofixed` | 1215 | 1.0s |  |
| 952 | `uint_tostring` | 3375 | 1.0s |  |
| 953 | `unchecked_function` | 15 | 1.0s |  |
| 954 | `unescape` | 28 | 1.0s |  |
| 955 | `url_loader` | 25 | 1.0s |  |
| 956 | `urlrequest` | 18 | 1.0s |  |
| 957 | `urlstream_basic` | 5 | 1.0s |  |
| 958 | `urshift` | 1058 | 1.1s |  |
| 959 | `utils3d` | 7 | 1.0s |  |
| 960 | `vector3d` | 397 | 1.1s |  |
| 961 | `vector_class` | 36 | 1.0s |  |
| 962 | `vector_class_call` | 11 | 1.0s |  |
| 963 | `vector_coercion` | 66 | 1.0s |  |
| 964 | `vector_concat` | 90 | 1.0s |  |
| 965 | `vector_constr` | 107 | 1.0s |  |
| 966 | `vector_enumeration` | 5 | 1.0s |  |
| 967 | `vector_every` | 92 | 1.0s |  |
| 968 | `vector_filter` | 95 | 1.0s |  |
| 969 | `vector_holes` | 24 | 1.0s |  |
| 970 | `vector_indexof` | 302 | 1.1s |  |
| 971 | `vector_insertat` | 270 | 1.0s |  |
| 972 | `vector_int_access` | 4 | 1.0s |  |
| 973 | `vector_int_delete` | 11 | 1.0s |  |
| 974 | `vector_join` | 58 | 1.0s |  |
| 975 | `vector_lastindexof` | 302 | 1.0s |  |
| 976 | `vector_legacy` | 10 | 1.0s |  |
| 977 | `vector_map` | 85 | 1.0s |  |
| 978 | `vector_object_final` | 1 | 1.0s |  |
| 979 | `vector_object_toString` | 10 | 1.0s |  |
| 980 | `vector_pushpop` | 255 | 1.0s |  |
| 981 | `vector_reborrow_bug` | 10 | 1.0s |  |
| 982 | `vector_removeat` | 172 | 6.8s |  |
| 983 | `vector_reverse` | 232 | 6.4s |  |
| 984 | `vector_shiftunshift` | 252 | 5.6s |  |
| 985 | `vector_slice` | 331 | 6.8s |  |
| 986 | `vector_sort` | 905 | 12.1s |  |
| 987 | `vector_splice` | 693 | 8.2s |  |
| 988 | `vector_splice_fixed_bug_compat` | 4 | 5.7s |  |
| 989 | `vector_tostring` | 79 | 6.1s |  |
| 990 | `verification` | 8 | 5.8s |  |
| 991 | `verify_abnormal_loop` | 1 | 5.5s |  |
| 992 | `verify_dxns_without_flag` | 3 | 5.9s |  |
| 993 | `verify_exception_targets_edge_case` | 1 | 6.0s |  |
| 994 | `verify_jump_to_middle_of_op` | 1 | 5.6s |  |
| 995 | `verify_lookup_switch_edge_case` | 1 | 6.4s |  |
| 996 | `verify_stack` | 5 | 6.0s |  |
| 997 | `verify_unreachable_exception` | 2 | 5.6s |  |
| 998 | `versioned_isplaying` | 2 | 5.7s |  |
| 999 | `virtual_properties` | 16 | 5.7s |  |
| 1000 | `with` | 4 | 6.1s |  |
| 1001 | `wrong_arg_count` | 7 | 5.7s |  |
| 1002 | `xml_abstract_equality` | 36 | 5.9s |  |
| 1003 | `xml_advanced` | 52 | 5.8s |  |
| 1004 | `xml_appendchild` | 10 | 5.7s |  |
| 1005 | `xml_as_attribute` | 9 | 5.7s |  |
| 1006 | `xml_attribute` | 35 | 5.8s |  |
| 1007 | `xml_attribute_name` | 40 | 5.7s |  |
| 1008 | `xml_basic` | 33 | 5.7s |  |
| 1009 | `xml_child` | 25 | 5.7s |  |
| 1010 | `xml_childindex` | 7 | 5.7s |  |
| 1011 | `xml_children` | 43 | 6.1s |  |
| 1012 | `xml_class_call` | 9 | 5.9s |  |
| 1013 | `xml_contains` | 197 | 5.8s |  |
| 1014 | `xml_copy` | 20 | 2.3s |  |
| 1015 | `xml_ctor_from_tostring` | 23 | 7.9s |  |
| 1016 | `xml_delete` | 114 | 7.3s |  |
| 1017 | `xml_descendants` | 83 | 7.2s |  |
| 1018 | `xml_elements` | 6 | 7.1s |  |
| 1019 | `xml_equals_namespace_check` | 2 | 7.1s |  |
| 1020 | `xml_explicit_use_namespace` | 5 | 7.2s |  |
| 1021 | `xml_getdescendants_qname` | 21 | 7.2s |  |
| 1022 | `xml_has_property_via_in` | 26 | 7.2s |  |
| 1023 | `xml_hasownproperty` | 6 | 7.1s |  |
| 1024 | `xml_ignore_white` | 6 | 7.1s |  |
| 1025 | `xml_length` | 2 | 7.1s |  |
| 1026 | `xml_list_as_attribute` | 9 | 7.1s |  |
| 1027 | `xml_list_concat` | 20 | 7.1s |  |
| 1028 | `xml_list_enumerate` | 4 | 7.0s |  |
| 1029 | `xml_methods_settings` | 3 | 7.1s |  |
| 1030 | `xml_mismatched_tag` | 37 | 7.2s |  |
| 1031 | `xml_namespace` | 39 | 3.1s |  |
| 1032 | `xml_namespace_methods` | 245 | 7.2s |  |
| 1033 | `xml_namespaced_property` | 7 | 7.1s |  |
| 1034 | `xml_no_namespace` | 1 | 7.0s |  |
| 1035 | `xml_nodekind` | 3 | 7.1s |  |
| 1036 | `xml_normalize` | 35 | 7.2s |  |
| 1037 | `xml_notification_bubbling` | 361 | 7.1s |  |
| 1038 | `xml_parent` | 8 | 7.1s |  |
| 1039 | `xml_set_children` | 17 | 7.2s |  |
| 1040 | `xml_set_name` | 34 | 7.2s |  |
| 1041 | `xml_settings` | 6 | 3.1s |  |
| 1042 | `xml_simple_complex_content` | 47 | 7.1s |  |
| 1043 | `xml_socket` | 11 | 7.4s |  |
| 1044 | `xml_text` | 7 | 7.1s |  |
| 1045 | `xml_tostring` | 6 | 7.1s |  |
| 1046 | `xml_tostring_namespace` | 12 | 7.1s |  |
| 1047 | `xml_unescaping` | 23 | 7.2s |  |
| 1048 | `xml_weird_ignores` | 54 | 7.2s |  |
| 1049 | `xml_wildcard` | 11 | 7.2s |  |
| 1050 | `xmldocument` | 254 | 7.2s |  |
| 1051 | `xmlnode` | 3540 | 7.3s |  |
| 1052 | `zero_frame_clip` | 3 | 7.6s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.6s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.8s |  |
| 3 | `blend_transform` | 1 | 1 | 7.3s |  |
| 4 | `coerce_property` | 3 | 3 | 7.4s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 3.3s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 7.3s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.6s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 27.0s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 7.2s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.3s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 7.3s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 7.2s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 21.1s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 21.9s |  |
| 15 | `int_toexponential` | 76 | 76 | 7.6s |  |
| 16 | `int_toprecision` | 441 | 441 | 7.6s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.3s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 7.0s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 25.2s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.3s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 7.3s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 7.1s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 27.7s |  |
| 24 | `uint_toexponential` | 100 | 100 | 1.0s |  |
| 25 | `uint_toprecision` | 433 | 433 | 1.1s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 21.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**48 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 5 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 6 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 7 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 8 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 9 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 10 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 11 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 12 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 13 | `flash_media_video_setter` | 90.0% | 36 | 40 | 4 |  |
| 14 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 15 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 16 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 17 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 18 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 19 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 20 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 21 | `textblock_line_changes` | 79.1% | 125 | 158 | 33 |  |
| 22 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 23 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 24 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 25 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 26 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 27 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 28 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 29 | `rtqname_not_namespace` | 75.0% | 9 | 12 | 3 |  |
| 30 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 31 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 32 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 33 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 35 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 36 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 37 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 38 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 39 | `displayobject_scrollrect` | 57.6% | 19 | 33 | 14 |  |
| 40 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 41 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 42 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 43 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 44 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 45 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 46 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 47 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 48 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `verify_typecheck` | exit code 1 | 2.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**145 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 5 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 6 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 7 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 8 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 9 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 10 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 11 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 12 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 13 | `flash_media_video_setter` | 90.0% | 36/40 | 40 | 40 |  |
| 14 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 15 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 16 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 17 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 18 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 19 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 20 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 21 | `textblock_line_changes` | 79.1% | 125/158 | 158 | 158 |  |
| 22 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 23 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 24 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 25 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 26 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 27 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 28 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 29 | `rtqname_not_namespace` | 75.0% | 9/12 | 10 | 12 |  |
| 30 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 31 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 32 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 33 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 35 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 36 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 37 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 38 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 39 | `displayobject_scrollrect` | 57.6% | 19/33 | 33 | 33 |  |
| 40 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 41 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 42 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 43 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 44 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 45 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 46 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 47 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 48 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 49 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 50 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 51 | `textblock_recreateline` | 40.8% | 40/98 | 89 | 98 |  |
| 52 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 53 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 54 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 55 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 56 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 57 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 58 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 59 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 60 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 61 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 62 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 63 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 64 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 65 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 66 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 67 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 68 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 69 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 70 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 71 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 72 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 73 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 74 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 75 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 76 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 77 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 78 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 79 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 80 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 81 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 82 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 83 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 84 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 85 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 86 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 87 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 88 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 89 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 90 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 91 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 92 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 93 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 94 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 95 | `all_classes/events/swf9` | 0.1% | 1/1030 | 184 | 1030 |  |
| 96 | `all_classes/events/swf30` | 0.1% | 2/2353 | 184 | 2353 |  |
| 97 | `all_classes/events/swf10` | 0.1% | 1/1638 | 184 | 1638 |  |
| 98 | `all_classes/events/swf11` | 0.1% | 1/1750 | 184 | 1750 |  |
| 99 | `all_classes/events/swf12` | 0.1% | 1/1814 | 184 | 1814 |  |
| 100 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 101 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 102 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 103 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 104 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 105 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 106 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 107 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 108 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 109 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 110 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 111 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 112 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 113 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 114 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 115 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 116 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 117 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 118 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 119 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 120 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 121 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 122 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 123 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 124 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 125 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 126 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 127 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 128 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 129 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 130 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 131 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 132 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 133 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 134 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 135 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 136 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 137 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 138 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 139 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 140 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 141 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 142 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 143 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 144 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 145 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
