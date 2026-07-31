# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-31 23:26 UTC

**Git SHA**: `569a215e41`

**Run Duration**: 199m 2s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1224 |
| Passing | **1051** (85.9%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1078** (88.1%) |
| Failing | 146 |
| Total expected lines | 151515 |
| Matching lines | 117939 (77.8%) |
| Mismatched lines | 33576 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 145 | 99.3% |
| Runtime Error | 1 | 0.7% |

## Passing Tests

**1051 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 7.3s |  |
| 2 | `accessibility` | 1 | 7.2s |  |
| 3 | `add` | 1058 | 19.6s |  |
| 4 | `agal_compiler` | 13 | 9.6s |  |
| 5 | `air_datagram_socket` | 1 | 8.7s |  |
| 6 | `air_hidden_lookup` | 2 | 7.2s |  |
| 7 | `air_ifilepromise` | 1 | 7.2s |  |
| 8 | `all_classes/security/swf11` | 3 | 7.2s |  |
| 9 | `amf_array_serialization` | 17 | 9.2s |  |
| 10 | `amf_custom_obj` | 26 | 7.4s |  |
| 11 | `amf_dictionary` | 9 | 7.2s |  |
| 12 | `amf_function` | 46 | 7.3s |  |
| 13 | `amf_invalid_date` | 2 | 7.1s |  |
| 14 | `amf_missing_prop` | 6 | 7.2s |  |
| 15 | `amf_nondynamic_function_prop` | 6 | 6.7s |  |
| 16 | `amf_setter_error` | 8 | 6.7s |  |
| 17 | `amf_vector` | 40 | 6.7s |  |
| 18 | `amf_xml` | 6 | 6.6s |  |
| 19 | `application_domain` | 4 | 6.7s |  |
| 20 | `applicationdomain_getqualifieddefinitionnames` | 9 | 6.7s |  |
| 21 | `applicationdomain_hasdefinition_null` | 2 | 6.5s |  |
| 22 | `array_access` | 18 | 6.7s |  |
| 23 | `array_access_interpreter` | 4 | 6.6s |  |
| 24 | `array_access_no_pubns` | 2 | 6.5s |  |
| 25 | `array_concat` | 41 | 6.7s |  |
| 26 | `array_constr` | 10 | 6.5s |  |
| 27 | `array_delete` | 44 | 6.8s |  |
| 28 | `array_enumeration` | 10 | 6.7s |  |
| 29 | `array_enumeration_elements` | 11 | 6.7s |  |
| 30 | `array_every` | 8 | 6.7s |  |
| 31 | `array_filter` | 6 | 6.7s |  |
| 32 | `array_foreach` | 18 | 6.7s |  |
| 33 | `array_hasownproperty` | 11 | 2.7s |  |
| 34 | `array_holes` | 9 | 6.7s |  |
| 35 | `array_index_max` | 84 | 6.7s |  |
| 36 | `array_indexof` | 25 | 6.8s |  |
| 37 | `array_join` | 26 | 6.7s |  |
| 38 | `array_lastindexof` | 29 | 6.7s |  |
| 39 | `array_length` | 14 | 6.6s |  |
| 40 | `array_literal` | 3 | 6.6s |  |
| 41 | `array_map` | 8 | 6.6s |  |
| 42 | `array_pop` | 52 | 6.7s |  |
| 43 | `array_push` | 24 | 6.7s |  |
| 44 | `array_reborrow_bug` | 6 | 6.6s |  |
| 45 | `array_reverse` | 28 | 6.7s |  |
| 46 | `array_shift` | 51 | 2.8s |  |
| 47 | `array_slice` | 39 | 6.8s |  |
| 48 | `array_some` | 8 | 6.7s |  |
| 49 | `array_sort` | 297 | 7.1s |  |
| 50 | `array_sort_fun_swf12` | 2 | 6.6s |  |
| 51 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 52 | `array_sort_random` | 210 | 6.6s |  |
| 53 | `array_sort_swf10_32bit` | 1 | 6.6s |  |
| 54 | `array_sorton` | 545 | 7.9s |  |
| 55 | `array_sparse_ops` | 41 | 7.2s |  |
| 56 | `array_splice` | 133 | 7.3s |  |
| 57 | `array_splice2` | 428 | 7.3s |  |
| 58 | `array_splice_types` | 48 | 7.2s |  |
| 59 | `array_storage` | 8 | 7.0s |  |
| 60 | `array_tolocalestring` | 9 | 7.0s |  |
| 61 | `array_tostring` | 12 | 7.0s |  |
| 62 | `array_unshift` | 24 | 7.0s |  |
| 63 | `array_valueof` | 9 | 6.9s |  |
| 64 | `array_vector_null_callback` | 10 | 7.0s |  |
| 65 | `astype` | 28 | 7.1s |  |
| 66 | `astypelate` | 24 | 7.2s |  |
| 67 | `astypelate_propagates` | 1 | 7.0s |  |
| 68 | `asymmetric_key_events` | 11 | 7.2s |  |
| 69 | `av_networking_params` | 9 | 7.1s |  |
| 70 | `av_tag_data` | 2 | 7.0s |  |
| 71 | `avm2_catchup_dobj` | 158 | 7.6s |  |
| 72 | `away3d_advanced_shallow_water_demo` | 0 | 83.0s |  |
| 73 | `bevel_filter` | 187 | 7.2s |  |
| 74 | `bitand` | 1058 | 18.9s |  |
| 75 | `bitmap_constr` | 17 | 7.3s |  |
| 76 | `bitmap_data` | 1000 | 15.2s |  |
| 77 | `bitmap_pixelsnapping` | 2 | 26.0s |  |
| 78 | `bitmap_properties` | 23 | 7.1s |  |
| 79 | `bitmap_subclass` | 7 | 8.5s |  |
| 80 | `bitmap_subclass_properties` | 9 | 7.5s |  |
| 81 | `bitmap_timeline` | 9 | 7.1s |  |
| 82 | `bitmapdata_accuracy` | 1 | 43.6s |  |
| 83 | `bitmapdata_applyfilter_blur` | 0 | 26.5s |  |
| 84 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.9s |  |
| 85 | `bitmapdata_applyfilter_destpoint` | 0 | 25.9s |  |
| 86 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.3s |  |
| 87 | `bitmapdata_clone` | 13 | 7.3s |  |
| 88 | `bitmapdata_colortransform` | 0 | 7.5s |  |
| 89 | `bitmapdata_colortransform_oob` | 2 | 7.0s |  |
| 90 | `bitmapdata_constr` | 22 | 7.1s |  |
| 91 | `bitmapdata_constructor_from_timeline` | 1 | 7.4s |  |
| 92 | `bitmapdata_copychannel` | 0 | 28.7s |  |
| 93 | `bitmapdata_copypixels` | 23 | 27.0s |  |
| 94 | `bitmapdata_copypixels_blend_over` | 1 | 6.9s |  |
| 95 | `bitmapdata_copypixelstobytearray` | 39 | 6.8s |  |
| 96 | `bitmapdata_dispose` | 7 | 6.8s |  |
| 97 | `bitmapdata_draw` | 0 | 26.5s |  |
| 98 | `bitmapdata_draw_colortransform` | 0 | 7.0s |  |
| 99 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.8s |  |
| 100 | `bitmapdata_draw_filters` | 0 | 25.7s |  |
| 101 | `bitmapdata_draw_masks` | 0 | 6.8s |  |
| 102 | `bitmapdata_draw_rotation` | 0 | 7.0s |  |
| 103 | `bitmapdata_draw_self_via_graphic` | 0 | 7.0s |  |
| 104 | `bitmapdata_draw_stage` | 0 | 25.5s |  |
| 105 | `bitmapdata_drawwithquality` | 0 | 7.0s |  |
| 106 | `bitmapdata_embedded` | 9 | 7.1s |  |
| 107 | `bitmapdata_fillrect` | 0 | 7.0s |  |
| 108 | `bitmapdata_filter_sourcerect` | 0 | 25.9s |  |
| 109 | `bitmapdata_floodfill` | 35 | 6.8s |  |
| 110 | `bitmapdata_getpixels` | 39 | 25.8s |  |
| 111 | `bitmapdata_getvector` | 27 | 2.7s |  |
| 112 | `bitmapdata_histogram` | 59 | 2.7s |  |
| 113 | `bitmapdata_hittest` | 112 | 7.3s |  |
| 114 | `bitmapdata_hittest_threshold` | 18 | 6.8s |  |
| 115 | `bitmapdata_opaque` | 0 | 7.0s |  |
| 116 | `bitmapdata_pixeldissolve` | 1037 | 7.4s |  |
| 117 | `bitmapdata_pixeldissolve_image` | 0 | 7.2s |  |
| 118 | `bitmapdata_rectangle_rounding` | 16 | 6.7s |  |
| 119 | `bitmapdata_setpixels` | 286 | 6.9s |  |
| 120 | `bitmapdata_setvector` | 26 | 6.9s |  |
| 121 | `bitmapdata_sync` | 0 | 25.8s |  |
| 122 | `bitmapdata_threshold` | 176 | 7.5s |  |
| 123 | `bitnot` | 46 | 6.8s |  |
| 124 | `bitor` | 1058 | 16.1s |  |
| 125 | `bitxor` | 1058 | 16.1s |  |
| 126 | `blend_mode_null` | 1 | 6.8s |  |
| 127 | `blend_multiply_alpha` | 0 | 6.9s |  |
| 128 | `blend_scroll` | 0 | 7.0s |  |
| 129 | `blend_shader_luma_lighten` | 3 | 7.4s |  |
| 130 | `blur_filter` | 43 | 8.1s |  |
| 131 | `boolean_constr` | 32 | 7.7s |  |
| 132 | `boolean_negation` | 30 | 7.7s |  |
| 133 | `boolean_tostring` | 8 | 7.7s |  |
| 134 | `broadcast_event` | 7 | 7.8s |  |
| 135 | `button_bounds` | 1 | 7.8s |  |
| 136 | `button_hittest` | 2 | 28.2s |  |
| 137 | `button_nested_frame` | 48 | 28.8s |  |
| 138 | `bytearray` | 48 | 8.1s |  |
| 139 | `bytearray_compress` | 31 | 7.6s |  |
| 140 | `bytearray_errors` | 24 | 7.9s |  |
| 141 | `bytearray_method_serialization` | 1 | 7.6s |  |
| 142 | `bytearray_oom` | 3 | 7.8s |  |
| 143 | `bytearray_readobject_amf0` | 50 | 7.7s |  |
| 144 | `bytearray_readobject_amf3` | 53 | 7.7s |  |
| 145 | `bytearray_readutf8bytes_with_bom` | 16 | 7.9s |  |
| 146 | `bytearray_serialization` | 3 | 7.7s |  |
| 147 | `bytearray_string_null` | 19 | 7.9s |  |
| 148 | `bytearray_tostring` | 15 | 7.7s |  |
| 149 | `bytearray_utf16` | 8 | 7.7s |  |
| 150 | `bytearray_writeobject` | 24 | 7.5s |  |
| 151 | `callee_in_initializer` | 6 | 7.7s |  |
| 152 | `callproplex_class` | 1 | 7.7s |  |
| 153 | `capabilities_resolution` | 8 | 29.4s |  |
| 154 | `catch_class` | 6 | 7.7s |  |
| 155 | `catch_scope_slot` | 7 | 3.4s |  |
| 156 | `checkfilter` | 4 | 3.4s |  |
| 157 | `class_call` | 32 | 7.9s |  |
| 158 | `class_cast_call` | 14 | 7.7s |  |
| 159 | `class_enumeration` | 4 | 7.8s |  |
| 160 | `class_has_own_property` | 2 | 7.7s |  |
| 161 | `class_init_interpreter_mode` | 1 | 7.6s |  |
| 162 | `class_is` | 32 | 7.7s |  |
| 163 | `class_methods` | 5 | 7.7s |  |
| 164 | `class_object_properties` | 10 | 7.7s |  |
| 165 | `class_singleton` | 18 | 7.7s |  |
| 166 | `class_supercalls_errors` | 35 | 7.9s |  |
| 167 | `class_supercalls_mismatched` | 26 | 7.7s |  |
| 168 | `class_superclass_wrong_order` | 1 | 25.5s |  |
| 169 | `class_to_locale_string` | 2 | 7.1s |  |
| 170 | `class_to_string` | 2 | 7.0s |  |
| 171 | `class_value_of` | 2 | 7.1s |  |
| 172 | `click_block` | 5 | 8.0s |  |
| 173 | `click_invisible` | 3 | 7.4s |  |
| 174 | `closures` | 12 | 7.3s |  |
| 175 | `coerce_return_type` | 40 | 7.3s |  |
| 176 | `coerce_return_type_fail` | 2 | 7.1s |  |
| 177 | `coerce_return_void` | 3 | 7.0s |  |
| 178 | `coerce_string` | 86 | 7.3s |  |
| 179 | `coerce_string_precision` | 28 | 7.1s |  |
| 180 | `coerce_to_primitive_side_effects` | 29 | 7.2s |  |
| 181 | `color_matrix_filter` | 19 | 7.3s |  |
| 182 | `construct_errors_swf10` | 8 | 7.2s |  |
| 183 | `construct_frame_list` | 22 | 26.1s |  |
| 184 | `construct_interface` | 3 | 7.2s |  |
| 185 | `constructor_call` | 3 | 7.1s |  |
| 186 | `constructors_vs_timeline` | 5 | 26.1s |  |
| 187 | `constructprop_dynamic_primitive` | 7 | 7.2s |  |
| 188 | `constructprop_method` | 2 | 7.1s |  |
| 189 | `content_element_basic` | 50 | 7.5s |  |
| 190 | `context3d_creation` | 9 | 7.3s |  |
| 191 | `control_flow_bool` | 4 | 7.1s |  |
| 192 | `control_flow_stricteq` | 8 | 7.2s |  |
| 193 | `convert_boolean` | 30 | 7.2s |  |
| 194 | `convert_integer` | 90 | 7.3s |  |
| 195 | `convert_number` | 56 | 7.2s |  |
| 196 | `convert_uinteger` | 90 | 7.3s |  |
| 197 | `convolution_filter` | 89 | 7.3s |  |
| 198 | `core_exceptions` | 47 | 8.0s |  |
| 199 | `cpool_index_invalid_bytecode_1` | 6 | 7.2s |  |
| 200 | `cpool_index_invalid_bytecode_2` | 3 | 7.1s |  |
| 201 | `cpool_index_invalid_bytecode_3` | 1 | 7.1s |  |
| 202 | `cross_api_version_call_older` | 12 | 7.5s |  |
| 203 | `cryptscore` | 11 | 7.3s |  |
| 204 | `date` | 30 | 7.6s |  |
| 205 | `date_parse` | 36 | 7.1s |  |
| 206 | `declocal` | 46 | 7.2s |  |
| 207 | `declocal_i` | 46 | 7.2s |  |
| 208 | `decode_uri` | 71 | 7.5s |  |
| 209 | `decrement` | 46 | 7.2s |  |
| 210 | `decrement_i` | 46 | 3.1s |  |
| 211 | `default_values` | 7 | 7.1s |  |
| 212 | `dictionary_access` | 62 | 7.3s |  |
| 213 | `dictionary_access_no_pubns` | 2 | 7.1s |  |
| 214 | `dictionary_delete` | 101 | 7.6s |  |
| 215 | `dictionary_foreach` | 42 | 7.3s |  |
| 216 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 217 | `dictionary_in` | 62 | 7.3s |  |
| 218 | `dictionary_iter_modify` | 8 | 7.2s |  |
| 219 | `dictionary_namespaces` | 36 | 7.2s |  |
| 220 | `dictionary_primitive_keys` | 29 | 7.1s |  |
| 221 | `displacement_map_filter` | 61 | 7.3s |  |
| 222 | `displayobject_alpha` | 277 | 7.1s |  |
| 223 | `displayobject_blendmode` | 0 | 7.2s |  |
| 224 | `displayobject_colortransform_nested` | 0 | 26.2s |  |
| 225 | `displayobject_filters` | 17 | 7.3s |  |
| 226 | `displayobject_from_enterframe` | 1 | 25.9s |  |
| 227 | `displayobject_getbounds_shape` | 0 | 25.9s |  |
| 228 | `displayobject_height` | 6052 | 26.1s |  |
| 229 | `displayobject_hittestobject` | 32 | 7.2s |  |
| 230 | `displayobject_hittestpoint` | 49 | 7.4s |  |
| 231 | `displayobject_hittestpoint_root` | 13 | 7.4s |  |
| 232 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 233 | `displayobject_invalid_props` | 3 | 7.1s |  |
| 234 | `displayobject_mask` | 3 | 7.4s |  |
| 235 | `displayobject_mask_self_referential` | 0 | 7.1s |  |
| 236 | `displayobject_metaData` | 3 | 6.9s |  |
| 237 | `displayobject_name` | 22 | 7.3s |  |
| 238 | `displayobject_name_from_timeline` | 24 | 7.2s |  |
| 239 | `displayobject_opaque_background` | 6 | 25.6s |  |
| 240 | `displayobject_parent` | 12 | 7.0s |  |
| 241 | `displayobject_root` | 24 | 7.1s |  |
| 242 | `displayobject_rotation` | 1284 | 7.2s |  |
| 243 | `displayobject_set_matrix_nested` | 0 | 25.8s |  |
| 244 | `displayobject_set_name_loaded` | 3 | 7.4s |  |
| 245 | `displayobject_subclass` | 2 | 7.0s |  |
| 246 | `displayobject_visible` | 23 | 7.0s |  |
| 247 | `displayobject_width` | 4852 | 25.7s |  |
| 248 | `displayobject_x` | 614 | 7.1s |  |
| 249 | `displayobject_y` | 617 | 7.1s |  |
| 250 | `displayobjectcontainer_addchild` | 32 | 7.1s |  |
| 251 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.0s |  |
| 252 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.2s |  |
| 253 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.1s |  |
| 254 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.1s |  |
| 255 | `displayobjectcontainer_addchildat` | 42 | 7.1s |  |
| 256 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.2s |  |
| 257 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.1s |  |
| 258 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.1s |  |
| 259 | `displayobjectcontainer_contains` | 66 | 25.6s |  |
| 260 | `displayobjectcontainer_getchildat` | 4 | 7.1s |  |
| 261 | `displayobjectcontainer_getchildbyname` | 9 | 7.0s |  |
| 262 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.0s |  |
| 263 | `displayobjectcontainer_getchildindex` | 28 | 7.0s |  |
| 264 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.2s |  |
| 265 | `displayobjectcontainer_removechild` | 10 | 7.0s |  |
| 266 | `displayobjectcontainer_removechild_errors` | 4 | 7.0s |  |
| 267 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.1s |  |
| 268 | `displayobjectcontainer_removechildat` | 18 | 7.0s |  |
| 269 | `displayobjectcontainer_removechildren` | 51 | 7.3s |  |
| 270 | `displayobjectcontainer_setchildindex` | 42 | 6.9s |  |
| 271 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.4s |  |
| 272 | `displayobjectcontainer_swapchildren` | 42 | 7.1s |  |
| 273 | `displayobjectcontainer_swapchildrenat` | 42 | 7.1s |  |
| 274 | `displayobjectcontainer_timelineinstance` | 48 | 26.6s |  |
| 275 | `divide` | 1058 | 19.6s |  |
| 276 | `doabc_is_eager` | 1 | 25.5s |  |
| 277 | `documentclass` | 9 | 7.3s |  |
| 278 | `domain_memory` | 133 | 8.3s |  |
| 279 | `drag_drop` | 10 | 7.4s |  |
| 280 | `drop_shadow_filter` | 172 | 7.3s |  |
| 281 | `duplicate_defs` | 1 | 7.0s |  |
| 282 | `eager_init` | 1 | 7.1s |  |
| 283 | `east_asian_justifier_clone` | 8 | 3.1s |  |
| 284 | `edit_text_linkage` | 7 | 7.4s |  |
| 285 | `edittext_align` | 60 | 7.6s |  |
| 286 | `edittext_always_show_selection` | 0 | 26.7s |  |
| 287 | `edittext_antialiastype` | 296 | 7.4s |  |
| 288 | `edittext_at_point_methods_basic` | 16 | 8.6s |  |
| 289 | `edittext_autosize` | 39 | 7.5s |  |
| 290 | `edittext_autosize_align` | 0 | 26.5s |  |
| 291 | `edittext_autosize_height_dynamic` | 60 | 26.2s |  |
| 292 | `edittext_autosize_height_input` | 60 | 7.3s |  |
| 293 | `edittext_autosize_lazy_bounds_events` | 65 | 7.6s |  |
| 294 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.3s |  |
| 295 | `edittext_autosize_lazy_bounds_props` | 490 | 8.8s |  |
| 296 | `edittext_autosize_lazy_bounds_visual` | 0 | 27.0s |  |
| 297 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.7s |  |
| 298 | `edittext_bottom_scroll_v_basic` | 210 | 7.5s |  |
| 299 | `edittext_bounds_scale` | 24 | 26.5s |  |
| 300 | `edittext_bullet` | 30 | 7.6s |  |
| 301 | `edittext_default_format` | 221 | 7.8s |  |
| 302 | `edittext_default_format_empty` | 136 | 7.8s |  |
| 303 | `edittext_empty_text_format` | 7 | 7.7s |  |
| 304 | `edittext_focus_selection` | 5 | 7.6s |  |
| 305 | `edittext_font_size` | 45 | 7.4s |  |
| 306 | `edittext_format_empty_font` | 8 | 7.2s |  |
| 307 | `edittext_get_char_index_at_point` | 4 | 28.0s |  |
| 308 | `edittext_get_line_index_at_point` | 2 | 27.1s |  |
| 309 | `edittext_get_line_index_of_char` | 76 | 8.4s |  |
| 310 | `edittext_getcharboundaries` | 172 | 7.8s |  |
| 311 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.6s |  |
| 312 | `edittext_getcharboundaries_scroll` | 85 | 7.4s |  |
| 313 | `edittext_getlinemetrics` | 146 | 7.5s |  |
| 314 | `edittext_html` | 3101 | 7.8s |  |
| 315 | `edittext_html_condensewhite` | 487 | 7.4s |  |
| 316 | `edittext_html_entity` | 4 | 7.6s |  |
| 317 | `edittext_html_font_size_swf12` | 267 | 7.4s |  |
| 318 | `edittext_html_font_size_swf13` | 273 | 7.0s |  |
| 319 | `edittext_html_roundtrip` | 17 | 7.2s |  |
| 320 | `edittext_ime_focus_lost` | 9 | 26.2s |  |
| 321 | `edittext_input_control` | 12 | 7.3s |  |
| 322 | `edittext_leading` | 9 | 7.5s |  |
| 323 | `edittext_letter_spacing` | 15 | 7.2s |  |
| 324 | `edittext_line_methods` | 294 | 8.5s |  |
| 325 | `edittext_line_metrics` | 11 | 27.7s |  |
| 326 | `edittext_margins` | 25 | 7.2s |  |
| 327 | `edittext_max_scroll_h_basic` | 475 | 7.5s |  |
| 328 | `edittext_max_scroll_v_basic` | 1000 | 7.3s |  |
| 329 | `edittext_mouse_selection` | 363 | 27.1s |  |
| 330 | `edittext_mousedown` | 3 | 7.6s |  |
| 331 | `edittext_mouseenabled` | 26 | 7.2s |  |
| 332 | `edittext_newline_character` | 22 | 7.2s |  |
| 333 | `edittext_newline_stripping` | 64 | 9.9s |  |
| 334 | `edittext_newlines` | 30 | 7.3s |  |
| 335 | `edittext_paragraph_methods` | 257 | 7.2s |  |
| 336 | `edittext_paste_events` | 8 | 7.4s |  |
| 337 | `edittext_paste_maxchars` | 4 | 7.3s |  |
| 338 | `edittext_paste_restrict` | 16 | 7.1s |  |
| 339 | `edittext_restrict` | 191 | 7.2s |  |
| 340 | `edittext_restrict_events` | 22 | 7.3s |  |
| 341 | `edittext_scrollh` | 10 | 7.3s |  |
| 342 | `edittext_selected_text` | 9 | 7.2s |  |
| 343 | `edittext_set_html_same` | 17 | 7.3s |  |
| 344 | `edittext_set_text_vs_html` | 9 | 7.4s |  |
| 345 | `edittext_stylesheet` | 536 | 7.8s |  |
| 346 | `edittext_stylesheet_custom_tag` | 76 | 7.4s |  |
| 347 | `edittext_stylesheet_display` | 272 | 7.5s |  |
| 348 | `edittext_underline` | 40 | 7.5s |  |
| 349 | `edittext_width_height` | 103 | 20.2s |  |
| 350 | `edittext_wordwrap_word` | 150 | 7.9s |  |
| 351 | `edittext_wrap_breaks` | 2375 | 8.1s |  |
| 352 | `element_format_clone` | 44 | 7.7s |  |
| 353 | `element_format_constructor_order` | 64 | 7.8s |  |
| 354 | `element_format_properties` | 235 | 8.5s |  |
| 355 | `empty_bounds` | 1 | 7.6s |  |
| 356 | `encode_uri_surrogate_pair_swf11` | 15 | 7.3s |  |
| 357 | `equals` | 512 | 11.9s |  |
| 358 | `error_geterrormessage` | 779 | 7.6s |  |
| 359 | `error_prototype` | 15 | 7.5s |  |
| 360 | `error_stack_trace_debug_swf17` | 0 | 27.5s |  |
| 361 | `error_stack_trace_debug_swf18` | 0 | 7.3s |  |
| 362 | `error_stack_trace_release_swf17` | 0 | 7.3s |  |
| 363 | `error_stack_trace_release_swf18` | 0 | 7.3s |  |
| 364 | `error_tostring` | 29 | 7.5s |  |
| 365 | `error_tostring_more` | 86 | 7.6s |  |
| 366 | `es3_inheritance` | 31 | 7.5s |  |
| 367 | `es4_inheritance` | 30 | 7.6s |  |
| 368 | `es4_interfaces` | 30 | 7.5s |  |
| 369 | `es4_method_binding` | 8 | 7.5s |  |
| 370 | `es4_oop_prototypes` | 14 | 7.7s |  |
| 371 | `es4_protected_inheritance` | 6 | 7.5s |  |
| 372 | `escape` | 71 | 7.6s |  |
| 373 | `event_bubbles` | 2 | 7.5s |  |
| 374 | `event_cancelable` | 2 | 7.3s |  |
| 375 | `event_clone` | 20 | 7.5s |  |
| 376 | `event_clone_error_redispatch` | 3 | 7.6s |  |
| 377 | `event_clone_on_redispatch` | 10 | 7.7s |  |
| 378 | `event_formattostring` | 31 | 7.6s |  |
| 379 | `event_isdefaultprevented` | 12 | 7.5s |  |
| 380 | `event_target_getter` | 5 | 3.3s |  |
| 381 | `event_target_set` | 9 | 7.5s |  |
| 382 | `event_type` | 1 | 19.8s |  |
| 383 | `event_valueof_tostring` | 18 | 7.6s |  |
| 384 | `eventdispatcher_dispatchevent` | 12 | 7.5s |  |
| 385 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.6s |  |
| 386 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.5s |  |
| 387 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.5s |  |
| 388 | `eventdispatcher_dispatchevent_this` | 5 | 7.4s |  |
| 389 | `eventdispatcher_haseventlistener` | 25 | 7.5s |  |
| 390 | `eventdispatcher_interface_invoke` | 1 | 7.4s |  |
| 391 | `eventdispatcher_tostring` | 10 | 7.4s |  |
| 392 | `eventdispatcher_willtrigger` | 25 | 7.2s |  |
| 393 | `falsiness` | 30 | 7.3s |  |
| 394 | `fast_index_access` | 12 | 7.5s |  |
| 395 | `filefilter_properties` | 4 | 7.3s |  |
| 396 | `filereference_browse_cancel` | 3 | 7.4s |  |
| 397 | `filereference_browse_select` | 9 | 7.3s |  |
| 398 | `filereference_load` | 31 | 7.4s |  |
| 399 | `filereference_save` | 16 | 7.5s |  |
| 400 | `filereference_save_and_browse` | 42 | 7.5s |  |
| 401 | `filereference_save_and_load` | 22 | 7.5s |  |
| 402 | `filereference_uninitialized` | 8 | 7.4s |  |
| 403 | `filereferencelist_browse_cancel` | 6 | 7.3s |  |
| 404 | `filereferencelist_browse_select` | 7 | 7.3s |  |
| 405 | `filter_rewind` | 8 | 7.6s |  |
| 406 | `filters_array_holes` | 25 | 7.4s |  |
| 407 | `finddef` | 3 | 7.3s |  |
| 408 | `findprop_global_prototype` | 6 | 7.4s |  |
| 409 | `flash_media_video_constructor` | 156 | 8.2s |  |
| 410 | `flash_media_video_rotation_probe` | 27 | 7.5s |  |
| 411 | `flash_xml` | 29 | 7.5s |  |
| 412 | `flash_xml_cloneNode` | 22 | 7.5s |  |
| 413 | `flash_xml_namespace` | 109 | 7.5s |  |
| 414 | `flash_xml_removeNode` | 60 | 7.4s |  |
| 415 | `focus_events_code` | 161 | 26.9s |  |
| 416 | `focus_events_key_basic` | 132 | 27.2s |  |
| 417 | `focus_events_key_navigation` | 53 | 7.6s |  |
| 418 | `focus_events_key_same_object` | 26 | 7.5s |  |
| 419 | `focus_events_mixed_key_mouse` | 100 | 26.3s |  |
| 420 | `focus_events_mouse_basic` | 260 | 40.6s |  |
| 421 | `focus_events_mouse_focusable` | 112 | 28.6s |  |
| 422 | `focus_events_mouse_same_object` | 40 | 28.0s |  |
| 423 | `focus_remove` | 20 | 27.4s |  |
| 424 | `focus_root_movie` | 4 | 27.2s |  |
| 425 | `focus_stage` | 1 | 7.4s |  |
| 426 | `focusrect` | 18 | 8.3s |  |
| 427 | `focusrect_focuslost` | 9 | 7.5s |  |
| 428 | `focusrect_property` | 110 | 7.4s |  |
| 429 | `font_description_clone` | 14 | 7.4s |  |
| 430 | `font_embedded` | 24 | 7.9s |  |
| 431 | `font_enumeratefonts` | 41 | 8.1s |  |
| 432 | `font_enumeratefonts_filter` | 4 | 27.6s |  |
| 433 | `font_hasglyphs` | 40 | 7.8s |  |
| 434 | `framelabel_constr` | 5 | 7.6s |  |
| 435 | `function_call` | 12 | 7.5s |  |
| 436 | `function_call_arguments` | 46 | 7.6s |  |
| 437 | `function_call_arguments_enumerate` | 5 | 7.4s |  |
| 438 | `function_call_coercion` | 108 | 8.1s |  |
| 439 | `function_call_default` | 6 | 7.5s |  |
| 440 | `function_call_rest` | 22 | 7.4s |  |
| 441 | `function_call_types` | 3 | 7.4s |  |
| 442 | `function_call_via_apply` | 11 | 7.4s |  |
| 443 | `function_call_via_call` | 3 | 7.3s |  |
| 444 | `function_display_anonymous` | 7 | 3.2s |  |
| 445 | `function_length` | 6 | 7.5s |  |
| 446 | `function_object` | 2 | 7.5s |  |
| 447 | `function_proto` | 5 | 7.5s |  |
| 448 | `function_proto_created` | 61 | 7.5s |  |
| 449 | `function_to_locale_string` | 4 | 7.4s |  |
| 450 | `function_to_string` | 4 | 7.4s |  |
| 451 | `function_type` | 6 | 7.3s |  |
| 452 | `function_unbound_this` | 51 | 7.4s |  |
| 453 | `function_value_of` | 4 | 7.3s |  |
| 454 | `game_input` | 4 | 7.4s |  |
| 455 | `generate_random_bytes` | 3 | 7.4s |  |
| 456 | `get_definition_by_name` | 11 | 7.5s |  |
| 457 | `get_qualified_class_name` | 20 | 19.2s |  |
| 458 | `get_qualified_super_class_name` | 18 | 7.2s |  |
| 459 | `get_slot_edge_cases` | 1 | 25.8s |  |
| 460 | `get_timer` | 2 | 7.2s |  |
| 461 | `getglobalslot` | 1 | 7.1s |  |
| 462 | `getouterscope` | 8 | 7.1s |  |
| 463 | `glow_filter` | 127 | 7.4s |  |
| 464 | `goto_button_nested_framescript` | 28 | 26.2s |  |
| 465 | `goto_in_constructframe` | 12 | 7.4s |  |
| 466 | `goto_in_scene_last_frame` | 2 | 25.9s |  |
| 467 | `goto_methods` | 56 | 7.4s |  |
| 468 | `goto_methods_swfver10` | 8 | 7.2s |  |
| 469 | `goto_nested_construct_sibling` | 18 | 7.7s |  |
| 470 | `goto_nested_framescript` | 9 | 7.4s |  |
| 471 | `goto_on_orphan` | 15 | 7.4s |  |
| 472 | `gradient_bevel_filter` | 206 | 7.4s |  |
| 473 | `gradient_glow_filter` | 206 | 7.3s |  |
| 474 | `graphics_bad_direct_commands` | 5 | 7.9s |  |
| 475 | `graphics_bitmap_fill` | 0 | 9.0s |  |
| 476 | `graphics_bitmaps` | 0 | 7.9s |  |
| 477 | `graphics_direct_commands` | 0 | 7.8s |  |
| 478 | `graphics_draw_triangles` | 98 | 27.1s |  |
| 479 | `graphics_gradients` | 0 | 7.6s |  |
| 480 | `graphics_gradients_nulls` | 0 | 7.4s |  |
| 481 | `graphics_path` | 56 | 7.3s |  |
| 482 | `graphics_round_rects` | 0 | 7.3s |  |
| 483 | `graphics_simple_shapes` | 0 | 7.5s |  |
| 484 | `greaterequals` | 512 | 11.3s |  |
| 485 | `greaterthan` | 512 | 11.3s |  |
| 486 | `has_own_property` | 102 | 7.8s |  |
| 487 | `hasownproperty_namespaces` | 2 | 7.2s |  |
| 488 | `hello_world` | 1 | 7.2s |  |
| 489 | `hittest_morph` | 30 | 7.4s |  |
| 490 | `if_eq` | 10 | 7.3s |  |
| 491 | `if_gt` | 1 | 7.3s |  |
| 492 | `if_gte` | 10 | 19.4s |  |
| 493 | `if_lt` | 1 | 7.5s |  |
| 494 | `if_lte` | 10 | 7.2s |  |
| 495 | `if_ne` | 7 | 3.3s |  |
| 496 | `if_stricteq` | 6 | 7.2s |  |
| 497 | `if_strictne` | 11 | 7.2s |  |
| 498 | `ime_linux_dead_keys` | 10 | 7.5s |  |
| 499 | `in` | 102 | 7.7s |  |
| 500 | `inclocal` | 46 | 7.3s |  |
| 501 | `inclocal_i` | 46 | 7.3s |  |
| 502 | `increment` | 46 | 7.2s |  |
| 503 | `increment_i` | 46 | 7.3s |  |
| 504 | `indexing_delete` | 75 | 7.3s |  |
| 505 | `instanceof` | 58 | 7.6s |  |
| 506 | `instantiation_on_enter_frame` | 7 | 26.6s |  |
| 507 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.3s |  |
| 508 | `int_constr` | 92 | 7.4s |  |
| 509 | `int_edge_cases` | 19 | 7.3s |  |
| 510 | `int_instanceof` | 3 | 7.1s |  |
| 511 | `int_tofixed` | 1215 | 7.1s |  |
| 512 | `int_tostring` | 3375 | 7.4s |  |
| 513 | `interactiveobject_enabled` | 25 | 7.2s |  |
| 514 | `interface_namespaces` | 78 | 7.5s |  |
| 515 | `is_finite` | 46 | 7.4s |  |
| 516 | `is_nan` | 46 | 7.3s |  |
| 517 | `is_prototype_of` | 12 | 7.3s |  |
| 518 | `issue_10221` | 2 | 7.3s |  |
| 519 | `issue_13780` | 12 | 7.3s |  |
| 520 | `issue_14901` | 1 | 7.2s |  |
| 521 | `issue_17675_edittext_paste_maxchars` | 1 | 7.3s |  |
| 522 | `issue_5292` | 5 | 7.2s |  |
| 523 | `issue_8630` | 2 | 26.4s |  |
| 524 | `issue_8630_scriptremove` | 11 | 7.3s |  |
| 525 | `istype` | 24 | 3.3s |  |
| 526 | `istypelate` | 58 | 7.6s |  |
| 527 | `istypelate_coerce` | 198 | 20.4s |  |
| 528 | `jpeg_loader_context` | 6 | 7.3s |  |
| 529 | `json_errors` | 9 | 26.7s |  |
| 530 | `json_parse` | 21 | 7.2s |  |
| 531 | `json_stringify` | 12 | 7.5s |  |
| 532 | `json_stringify_order` | 1 | 7.2s |  |
| 533 | `json_version_gated` | 1 | 7.2s |  |
| 534 | `key_input_80percent` | 1812 | 7.4s |  |
| 535 | `key_input_location` | 126 | 7.3s |  |
| 536 | `key_input_numpad` | 384 | 7.2s |  |
| 537 | `lazyinit` | 17 | 7.1s |  |
| 538 | `lessequals` | 512 | 11.3s |  |
| 539 | `lessthan` | 512 | 11.5s |  |
| 540 | `loader_bitmap_transparency` | 14 | 7.3s |  |
| 541 | `loader_bytes_unknown_content` | 14 | 7.1s |  |
| 542 | `loader_child_getdefinition` | 5 | 7.3s |  |
| 543 | `loader_duplicate_coerce` | 3 | 7.3s |  |
| 544 | `loader_duplicate_coerce_new_domain` | 4 | 7.2s |  |
| 545 | `loader_error_in_root_ctor` | 4 | 7.3s |  |
| 546 | `loader_events` | 92 | 7.9s |  |
| 547 | `loader_image` | 8 | 7.6s |  |
| 548 | `loader_jpegxr` | 2 | 26.2s |  |
| 549 | `loader_jpegxr_alpha` | 1 | 25.9s |  |
| 550 | `loader_loadbytes_events` | 30 | 7.8s |  |
| 551 | `loader_loadbytes_invalid_png` | 4 | 25.7s |  |
| 552 | `loader_loadbytes_url` | 12 | 7.4s |  |
| 553 | `loader_loaderurl` | 6 | 7.5s |  |
| 554 | `loader_noninteractive_try_click_root` | 5 | 26.1s |  |
| 555 | `loader_reuse` | 38 | 7.3s |  |
| 556 | `loader_unknown_content` | 24 | 7.2s |  |
| 557 | `loader_visibility_interactive` | 1 | 7.2s |  |
| 558 | `loaderinfo_events` | 7 | 7.2s |  |
| 559 | `loaderinfo_loadurl` | 12 | 18.9s |  |
| 560 | `loaderinfo_more` | 6 | 7.5s |  |
| 561 | `loaderinfo_properties` | 18 | 7.2s |  |
| 562 | `loaderinfo_properties_not_loaded` | 23 | 7.2s |  |
| 563 | `loaderinfo_root` | 10 | 7.1s |  |
| 564 | `loaderinfo_root_allows` | 2 | 7.0s |  |
| 565 | `localconnection_send` | 4 | 7.0s |  |
| 566 | `lshift` | 1058 | 19.0s |  |
| 567 | `mask_reapply` | 1 | 7.1s |  |
| 568 | `math` | 497 | 7.3s |  |
| 569 | `matrix3d` | 57 | 7.8s |  |
| 570 | `matrix3d_compose` | 34 | 7.3s |  |
| 571 | `matrix3d_invert` | 18 | 7.1s |  |
| 572 | `method_without_body` | 3 | 25.5s |  |
| 573 | `missing_external_interface` | 10 | 7.1s |  |
| 574 | `modulo` | 1058 | 19.0s |  |
| 575 | `morph_shape` | 2 | 25.6s |  |
| 576 | `mouse_children` | 192 | 25.9s |  |
| 577 | `mouse_click_events` | 90 | 25.6s |  |
| 578 | `mouse_double_click_events` | 188 | 7.1s |  |
| 579 | `mouse_empty_parent` | 4 | 7.1s |  |
| 580 | `mouse_over_while_dragging` | 3 | 7.2s |  |
| 581 | `mouse_pick_button_mode` | 2 | 7.2s |  |
| 582 | `mouse_pick_dobj_mask` | 4 | 7.4s |  |
| 583 | `mouse_pick_masking` | 7 | 25.6s |  |
| 584 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 25.4s |  |
| 585 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.4s |  |
| 586 | `mouse_pick_text` | 8 | 7.2s |  |
| 587 | `mouse_sibling` | 8 | 7.1s |  |
| 588 | `mouse_wheel_events` | 36 | 26.7s |  |
| 589 | `mouseevent_constr` | 66 | 7.1s |  |
| 590 | `mouseevent_stagexy` | 35 | 7.1s |  |
| 591 | `mouseevent_valueof_tostring` | 28 | 7.0s |  |
| 592 | `movieclip_addframescript` | 3 | 25.6s |  |
| 593 | `movieclip_child_property` | 16 | 7.2s |  |
| 594 | `movieclip_constr` | 21 | 18.8s |  |
| 595 | `movieclip_currentlabels` | 17 | 25.2s |  |
| 596 | `movieclip_currentlabels_dupes1` | 46 | 25.3s |  |
| 597 | `movieclip_currentlabels_dupes2` | 30 | 7.0s |  |
| 598 | `movieclip_currentlabels_dupes3` | 67 | 7.0s |  |
| 599 | `movieclip_currentscene` | 12 | 7.2s |  |
| 600 | `movieclip_dispatchevent` | 430 | 7.2s |  |
| 601 | `movieclip_dispatchevent_cancel` | 102 | 7.2s |  |
| 602 | `movieclip_dispatchevent_handlerorder` | 251 | 7.1s |  |
| 603 | `movieclip_dispatchevent_selfadd` | 80 | 7.0s |  |
| 604 | `movieclip_dispatchevent_target` | 899 | 7.1s |  |
| 605 | `movieclip_displayevents` | 96 | 25.4s |  |
| 606 | `movieclip_displayevents_clickgoto` | 676 | 7.5s |  |
| 607 | `movieclip_displayevents_clickgoto2` | 2001 | 7.6s |  |
| 608 | `movieclip_displayevents_clickplay` | 575 | 7.2s |  |
| 609 | `movieclip_displayevents_clicksymbol` | 562 | 7.3s |  |
| 610 | `movieclip_displayevents_constructframegoto` | 140 | 7.4s |  |
| 611 | `movieclip_displayevents_constructframeplay` | 50 | 7.3s |  |
| 612 | `movieclip_displayevents_constructframesymbol` | 144 | 7.2s |  |
| 613 | `movieclip_displayevents_dblhandler` | 21 | 7.2s |  |
| 614 | `movieclip_displayevents_enterframegoto` | 149 | 7.4s |  |
| 615 | `movieclip_displayevents_enterframeplay` | 48 | 7.2s |  |
| 616 | `movieclip_displayevents_enterframesymbol` | 149 | 25.6s |  |
| 617 | `movieclip_displayevents_exitframegoto` | 106 | 7.1s |  |
| 618 | `movieclip_displayevents_exitframeplay` | 44 | 7.1s |  |
| 619 | `movieclip_displayevents_exitframesymbol` | 135 | 7.2s |  |
| 620 | `movieclip_displayevents_looping` | 63 | 25.6s |  |
| 621 | `movieclip_displayevents_stopped` | 113 | 7.5s |  |
| 622 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 623 | `movieclip_displayevents_timeline` | 128 | 25.7s |  |
| 624 | `movieclip_drawrect` | 54 | 7.1s |  |
| 625 | `movieclip_frameconstruct_skipped` | 9 | 7.2s |  |
| 626 | `movieclip_goto_during_frame_script` | 15 | 7.1s |  |
| 627 | `movieclip_goto_overwrite` | 14 | 25.5s |  |
| 628 | `movieclip_goto_scene_last_frame_int` | 1 | 25.4s |  |
| 629 | `movieclip_goto_scene_last_frame_label` | 1 | 7.0s |  |
| 630 | `movieclip_gotoandplay` | 15 | 25.3s |  |
| 631 | `movieclip_gotoandstop` | 13 | 25.1s |  |
| 632 | `movieclip_gotoandstop_children` | 4 | 7.1s |  |
| 633 | `movieclip_gotoandstop_framescripts1` | 4 | 7.1s |  |
| 634 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 635 | `movieclip_gotoandstop_framescripts_self` | 7 | 38.5s |  |
| 636 | `movieclip_gotoandstop_queueing` | 12 | 26.4s |  |
| 637 | `movieclip_hittest` | 67 | 7.4s |  |
| 638 | `movieclip_next_frame` | 2 | 7.4s |  |
| 639 | `movieclip_next_scene` | 6 | 26.1s |  |
| 640 | `movieclip_play` | 3 | 7.1s |  |
| 641 | `movieclip_prev_frame` | 3 | 7.0s |  |
| 642 | `movieclip_prev_scene` | 7 | 7.2s |  |
| 643 | `movieclip_properties` | 79 | 7.5s |  |
| 644 | `movieclip_queued_noop_goto_swf10` | 9 | 7.2s |  |
| 645 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 646 | `movieclip_scenes` | 11 | 7.2s |  |
| 647 | `movieclip_soundtransform` | 831 | 28.3s |  |
| 648 | `movieclip_stop` | 1 | 7.1s |  |
| 649 | `movieclip_super_is_symbol` | 20 | 7.5s |  |
| 650 | `movieclip_symbol_constr` | 8 | 7.3s |  |
| 651 | `movieclip_text_mousedown` | 1 | 7.3s |  |
| 652 | `movieclip_willtrigger` | 5 | 7.5s |  |
| 653 | `multiply` | 1058 | 19.6s |  |
| 654 | `namespace_constr` | 253 | 7.5s |  |
| 655 | `namespace_constr_args` | 1 | 7.1s |  |
| 656 | `namespace_enumeration_order` | 7 | 7.2s |  |
| 657 | `nan_scale` | 9 | 7.2s |  |
| 658 | `navigateToURL_target_normalize` | 107 | 27.8s |  |
| 659 | `negate` | 30 | 7.2s |  |
| 660 | `negative_volume_panned` | 0 | 7.5s |  |
| 661 | `nested_iteration` | 11 | 7.2s |  |
| 662 | `net_getClassByAlias` | 3 | 7.2s |  |
| 663 | `net_navigateToURL` | 57 | 7.2s |  |
| 664 | `net_stream_play_options` | 6 | 7.3s |  |
| 665 | `netconnection_close` | 55 | 7.2s |  |
| 666 | `netconnection_properties` | 78 | 7.3s |  |
| 667 | `netconnection_send_remote` | 50 | 7.5s |  |
| 668 | `netconnection_serialize_arrays` | 6 | 7.2s |  |
| 669 | `netstream_client` | 10 | 7.4s |  |
| 670 | `netstream_connect` | 7 | 7.3s |  |
| 671 | `newactivation_in_script_init` | 3 | 5.1s |  |
| 672 | `newclass_mismatched` | 4 | 5.0s |  |
| 673 | `newclass_twice` | 3 | 4.9s |  |
| 674 | `nonconflicting_declarations` | 0 | 5.1s |  |
| 675 | `null_void_types` | 8 | 5.0s |  |
| 676 | `number_autoconv` | 21 | 5.5s |  |
| 677 | `number_autoconv_amf` | 132 | 5.0s |  |
| 678 | `number_autoconv_array_sort_32bit` | 1 | 5.0s |  |
| 679 | `number_constr` | 58 | 5.1s |  |
| 680 | `number_toexponential` | 378 | 5.0s |  |
| 681 | `number_toexponential2` | 35 | 5.3s |  |
| 682 | `number_tofixed` | 378 | 5.0s |  |
| 683 | `number_toprecision` | 350 | 5.3s |  |
| 684 | `obfuscated_class_names` | 3 | 5.0s |  |
| 685 | `object_enumeration` | 10 | 4.9s |  |
| 686 | `object_prototype` | 4 | 5.0s |  |
| 687 | `object_to_locale_string` | 2 | 5.0s |  |
| 688 | `object_to_string` | 2 | 5.2s |  |
| 689 | `object_value_of` | 2 | 1.9s |  |
| 690 | `op_coerce` | 54 | 5.1s |  |
| 691 | `op_coerce_x` | 54 | 5.2s |  |
| 692 | `op_escxattr` | 2 | 5.6s |  |
| 693 | `op_escxelem` | 2 | 5.6s |  |
| 694 | `op_lookupswitch` | 4 | 5.6s |  |
| 695 | `optimize_coerce` | 1 | 5.5s |  |
| 696 | `orphan_movie_complex` | 80 | 6.3s |  |
| 697 | `orphan_movie_reorder` | 111 | 21.1s |  |
| 698 | `package_namespace` | 7 | 5.2s |  |
| 699 | `param_default_value_has_zero_cpool_index` | 1 | 5.2s |  |
| 700 | `parent_early_access_child` | 16 | 5.5s |  |
| 701 | `parse_float` | 81 | 5.6s |  |
| 702 | `parse_int` | 135 | 5.9s |  |
| 703 | `perspective_projection_basic` | 40 | 5.2s |  |
| 704 | `pixelbender_ceil` | 77 | 5.2s |  |
| 705 | `pixelbender_conditional` | 138 | 19.4s |  |
| 706 | `pixelbender_conversions` | 270 | 7.5s |  |
| 707 | `pixelbender_dithering` | 8 | 32.3s |  |
| 708 | `pixelbender_div` | 36 | 7.3s |  |
| 709 | `pixelbender_effect_BlurredFocus` | 0 | 33.6s |  |
| 710 | `pixelbender_effect_glassDisplace` | 0 | 12.8s |  |
| 711 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 30.6s |  |
| 712 | `pixelbender_effect_smudge` | 0 | 10.6s |  |
| 713 | `pixelbender_effect_tintype` | 0 | 9.8s |  |
| 714 | `pixelbender_effect_twirl` | 0 | 11.0s |  |
| 715 | `pixelbender_eof` | 7 | 7.1s |  |
| 716 | `pixelbender_images` | 0 | 9.6s |  |
| 717 | `pixelbender_input` | 103 | 26.4s |  |
| 718 | `pixelbender_logicalnot` | 20 | 7.1s |  |
| 719 | `pixelbender_malformed_data` | 190 | 26.3s |  |
| 720 | `pixelbender_multiple_out_params` | 1 | 7.1s |  |
| 721 | `pixelbender_no_out_param` | 6 | 7.1s |  |
| 722 | `pixelbender_outputs` | 13 | 7.3s |  |
| 723 | `pixelbender_padding_bytes` | 22 | 7.2s |  |
| 724 | `pixelbender_param_qualifier` | 512 | 7.2s |  |
| 725 | `pixelbender_parameters` | 1563 | 7.5s |  |
| 726 | `pixelbender_parameters_bool` | 240 | 7.4s |  |
| 727 | `pixelbender_parameters_int_vs_bool` | 54 | 7.3s |  |
| 728 | `pixelbender_parse_errors` | 6 | 7.1s |  |
| 729 | `pixelbender_rsqrt` | 24 | 7.2s |  |
| 730 | `pixelbender_select_kinds` | 8 | 7.3s |  |
| 731 | `pixelbender_shaderdata` | 49 | 7.2s |  |
| 732 | `pixelbender_shaderdata_setter` | 99 | 7.5s |  |
| 733 | `pixelbender_sign` | 60 | 7.4s |  |
| 734 | `pixelbender_vector_output` | 11 | 7.3s |  |
| 735 | `place_and_lookup/swf10` | 33 | 7.2s |  |
| 736 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 737 | `place_multiple` | 17 | 25.5s |  |
| 738 | `place_object_replace` | 9 | 7.3s |  |
| 739 | `place_object_replace_2` | 24 | 7.4s |  |
| 740 | `place_object_same_depth_frame` | 1 | 7.2s |  |
| 741 | `point` | 132 | 7.6s |  |
| 742 | `primitive_edge_cases` | 1 | 7.1s |  |
| 743 | `print_job_options` | 3 | 7.0s |  |
| 744 | `property_is_enumerable_reset` | 23 | 7.5s |  |
| 745 | `property_priority` | 22 | 7.9s |  |
| 746 | `property_priority_chained` | 4 | 7.5s |  |
| 747 | `property_priority_definition_names_order` | 2 | 7.8s |  |
| 748 | `property_priority_three_level` | 6 | 27.1s |  |
| 749 | `propertyisenumerable_namespaces` | 6 | 7.7s |  |
| 750 | `prototype_set_null` | 7 | 7.5s |  |
| 751 | `proxy_callproperty` | 24 | 7.6s |  |
| 752 | `proxy_deleteproperty` | 64 | 7.7s |  |
| 753 | `proxy_enumeration` | 34 | 7.7s |  |
| 754 | `proxy_getproperty` | 77 | 7.6s |  |
| 755 | `proxy_hasownproperty` | 8 | 7.5s |  |
| 756 | `proxy_hasproperty` | 32 | 7.6s |  |
| 757 | `proxy_serialize` | 9 | 7.5s |  |
| 758 | `proxy_setproperty` | 42 | 7.7s |  |
| 759 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.4s |  |
| 760 | `qname_constr` | 32 | 7.6s |  |
| 761 | `qname_constr_namespace` | 24 | 7.5s |  |
| 762 | `qname_enumeration` | 9 | 7.6s |  |
| 763 | `qname_indexing` | 23 | 7.6s |  |
| 764 | `qname_tostring` | 25 | 7.5s |  |
| 765 | `qname_valueof` | 29 | 7.6s |  |
| 766 | `rectangle` | 1094 | 8.2s |  |
| 767 | `regexp_constr` | 148 | 7.8s |  |
| 768 | `regexp_exec` | 19 | 7.5s |  |
| 769 | `regexp_extended` | 47 | 7.5s |  |
| 770 | `regexp_multiargs` | 1 | 7.5s |  |
| 771 | `regexp_test` | 27 | 7.5s |  |
| 772 | `regexp_toString` | 10 | 7.5s |  |
| 773 | `register_script_refresh` | 35 | 8.1s |  |
| 774 | `remove_child_clear_field` | 88 | 8.0s |  |
| 775 | `remove_dobj` | 3 | 7.5s |  |
| 776 | `resolve_order` | 4 | 7.5s |  |
| 777 | `responder_null_callbacks` | 1 | 7.5s |  |
| 778 | `rng` | 1 | 8.9s |  |
| 779 | `rootless` | 42 | 7.7s |  |
| 780 | `rshift` | 1058 | 19.1s |  |
| 781 | `sandbox_type_inherited` | 2 | 8.0s |  |
| 782 | `sandbox_type_local_file` | 1 | 20.8s |  |
| 783 | `sandbox_type_local_network` | 1 | 7.6s |  |
| 784 | `scene_constr` | 8 | 8.1s |  |
| 785 | `scopes_dont_cache/order-1` | 1 | 29.3s |  |
| 786 | `scopes_dont_cache/order-2` | 1 | 1.1s |  |
| 787 | `security_domain_current` | 2 | 8.1s |  |
| 788 | `selection` | 239 | 8.7s |  |
| 789 | `set_local_0` | 31 | 8.1s |  |
| 790 | `set_property_is_enumerable` | 85 | 8.3s |  |
| 791 | `shaderparameter_value` | 4 | 7.9s |  |
| 792 | `shape_drawrect` | 54 | 8.0s |  |
| 793 | `shared_object_no_root` | 3 | 7.8s |  |
| 794 | `simplebutton_added_to_stage` | 45 | 28.7s |  |
| 795 | `simplebutton_childevents` | 86 | 29.7s |  |
| 796 | `simplebutton_childevents_nested` | 54 | 8.6s |  |
| 797 | `simplebutton_childevents_sprite` | 13 | 8.3s |  |
| 798 | `simplebutton_childprops` | 144 | 8.4s |  |
| 799 | `simplebutton_childshuffle` | 23 | 8.1s |  |
| 800 | `simplebutton_constr` | 36 | 8.5s |  |
| 801 | `simplebutton_constr_childevents` | 48 | 8.4s |  |
| 802 | `simplebutton_constr_params` | 42 | 8.2s |  |
| 803 | `simplebutton_mouseenabled` | 26 | 8.1s |  |
| 804 | `simplebutton_multi_children` | 19 | 8.4s |  |
| 805 | `simplebutton_structure` | 27 | 8.3s |  |
| 806 | `simplebutton_symbolclass` | 68 | 8.6s |  |
| 807 | `slot_disp_id_shared_numbering` | 1 | 29.6s |  |
| 808 | `slots_force_autoassigned` | 1 | 8.3s |  |
| 809 | `socket_after_disconnect` | 1 | 8.3s |  |
| 810 | `socket_close` | 2 | 8.2s |  |
| 811 | `socket_connect` | 4 | 8.1s |  |
| 812 | `socket_errors` | 56 | 8.9s |  |
| 813 | `socket_read_big` | 48 | 8.5s |  |
| 814 | `socket_read_little` | 48 | 3.7s |  |
| 815 | `socket_read_write_object` | 8 | 19.2s |  |
| 816 | `socket_write_big` | 15 | 7.5s |  |
| 817 | `socket_write_little` | 14 | 7.2s |  |
| 818 | `sound_embeddedprops` | 26 | 7.7s |  |
| 819 | `sound_play` | 19 | 7.5s |  |
| 820 | `sound_valueof` | 33 | 7.3s |  |
| 821 | `soundchannel_soundtransform` | 835 | 28.4s |  |
| 822 | `soundchannel_soundtransform_exists` | 5 | 26.5s |  |
| 823 | `soundchannel_stop` | 8 | 7.5s |  |
| 824 | `soundmixer_buffertime` | 5 | 7.2s |  |
| 825 | `soundmixer_stopall` | 6 | 7.3s |  |
| 826 | `soundtransform` | 442 | 13.1s |  |
| 827 | `space_justifier_clone` | 12 | 7.2s |  |
| 828 | `sprite_with_frames` | 0 | 27.0s |  |
| 829 | `stage3d_agal_cross_product` | 0 | 10.0s |  |
| 830 | `stage3d_agal_upload_errors` | 66 | 10.0s |  |
| 831 | `stage3d_bitmap` | 0 | 31.7s |  |
| 832 | `stage3d_blend` | 81 | 30.8s |  |
| 833 | `stage3d_context3d_string_args` | 158 | 8.3s |  |
| 834 | `stage3d_errors` | 7 | 7.3s |  |
| 835 | `stage3d_errors_atf` | 3 | 8.6s |  |
| 836 | `stage3d_errors_swf_29` | 6 | 7.4s |  |
| 837 | `stage3d_float1_index` | 0 | 28.7s |  |
| 838 | `stage3d_fractal` | 0 | 29.7s |  |
| 839 | `stage3d_ignore_sampler_override` | 0 | 29.6s |  |
| 840 | `stage3d_multistage_triangle` | 3 | 10.2s |  |
| 841 | `stage3d_program_constants_bytearray_be` | 0 | 30.8s |  |
| 842 | `stage3d_program_constants_bytearray_le` | 0 | 10.7s |  |
| 843 | `stage3d_program_constants_invalid_input` | 21 | 8.3s |  |
| 844 | `stage3d_raytrace` | 0 | 33.7s |  |
| 845 | `stage3d_rotating_cube` | 0 | 10.9s |  |
| 846 | `stage3d_sampler` | 0 | 9.9s |  |
| 847 | `stage3d_sampler_partial_upload` | 0 | 10.0s |  |
| 848 | `stage3d_stencil` | 0 | 29.9s |  |
| 849 | `stage3d_texture` | 0 | 27.0s |  |
| 850 | `stage3d_texture_bytearray` | 0 | 11.5s |  |
| 851 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.6s |  |
| 852 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.8s |  |
| 853 | `stage3d_triangle` | 0 | 10.0s |  |
| 854 | `stage3d_triangle_bytes4` | 0 | 10.0s |  |
| 855 | `stage3d_triangle_float1` | 0 | 9.9s |  |
| 856 | `stage3d_triangle_index_upload` | 0 | 10.0s |  |
| 857 | `stage3d_x_y` | 22 | 7.2s |  |
| 858 | `stage_access` | 10 | 7.2s |  |
| 859 | `stage_displayobject_properties` | 24 | 7.1s |  |
| 860 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.2s |  |
| 861 | `stage_framerate_nan` | 7 | 7.4s |  |
| 862 | `stage_framerate_negative` | 6 | 7.2s |  |
| 863 | `stage_framerate_zero` | 6 | 7.2s |  |
| 864 | `stage_invalidate` | 38 | 7.5s |  |
| 865 | `stage_loaderinfo_properties` | 24 | 7.5s |  |
| 866 | `stage_mousechildren` | 2 | 7.1s |  |
| 867 | `stage_mouseenabled` | 15 | 7.2s |  |
| 868 | `stage_overriden_setters` | 31 | 7.3s |  |
| 869 | `stage_properties` | 30 | 7.1s |  |
| 870 | `stage_stage3Ds_vector` | 1 | 25.9s |  |
| 871 | `static_text` | 3 | 7.4s |  |
| 872 | `static_var_with_this_in_ctor` | 2 | 7.2s |  |
| 873 | `stored_properties` | 11 | 7.2s |  |
| 874 | `strict_equality` | 34 | 7.2s |  |
| 875 | `string_call` | 13 | 7.2s |  |
| 876 | `string_case` | 23 | 7.2s |  |
| 877 | `string_char_at` | 27 | 7.1s |  |
| 878 | `string_char_code_at` | 28 | 7.1s |  |
| 879 | `string_concat_fromcharcode` | 37 | 7.1s |  |
| 880 | `string_constr` | 25 | 7.2s |  |
| 881 | `string_indexof_lastindexof` | 87 | 7.4s |  |
| 882 | `string_length` | 16 | 7.1s |  |
| 883 | `string_locale_compare` | 39 | 7.4s |  |
| 884 | `string_match` | 51 | 7.7s |  |
| 885 | `string_relational_compare` | 4 | 7.3s |  |
| 886 | `string_replace` | 51 | 7.6s |  |
| 887 | `string_search` | 41 | 7.5s |  |
| 888 | `string_slice_substr_substring` | 170 | 8.6s |  |
| 889 | `string_split` | 29 | 7.5s |  |
| 890 | `string_substr_negative` | 21 | 7.3s |  |
| 891 | `string_substr_weird` | 182 | 7.3s |  |
| 892 | `subtract` | 1058 | 19.9s |  |
| 893 | `super_get_call` | 12 | 7.4s |  |
| 894 | `supercall_two_classobjects` | 2 | 7.4s |  |
| 895 | `swf8` | 1 | 7.3s |  |
| 896 | `swf_10_queued_goto_scripts_construct` | 52 | 7.7s |  |
| 897 | `swf_9_goto_in_enter_frame` | 17 | 7.5s |  |
| 898 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.5s |  |
| 899 | `swf_9_queued_goto_scripts` | 6 | 7.4s |  |
| 900 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 901 | `swf_9_versioning` | 2 | 7.3s |  |
| 902 | `swf_wrong_frame_count` | 38 | 7.7s |  |
| 903 | `swf_wrong_frame_count_isplaying` | 22 | 26.6s |  |
| 904 | `symbol_class_binary_data` | 8 | 7.4s |  |
| 905 | `symbol_class_conflict` | 4 | 7.8s |  |
| 906 | `symbol_class_root_not_zero` | 1 | 7.3s |  |
| 907 | `symbolclass_invalid_utf8` | 2 | 7.5s |  |
| 908 | `tab_ordering_arrows` | 998 | 28.9s |  |
| 909 | `tab_ordering_automatic_advanced` | 184 | 8.3s |  |
| 910 | `tab_ordering_automatic_basic` | 45 | 7.6s |  |
| 911 | `tab_ordering_children` | 116 | 19.8s |  |
| 912 | `tab_ordering_custom_basic` | 34 | 7.5s |  |
| 913 | `tab_ordering_stage_tab_children` | 32 | 7.5s |  |
| 914 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.4s |  |
| 915 | `tab_ordering_tabbable` | 47 | 7.6s |  |
| 916 | `tabstop_properties` | 105 | 7.8s |  |
| 917 | `text_element_basic` | 34 | 7.5s |  |
| 918 | `text_engine_fontdescription` | 27 | 7.6s |  |
| 919 | `text_engine_groupelement` | 64 | 8.5s |  |
| 920 | `text_run` | 7 | 7.4s |  |
| 921 | `textblock_createline_errors` | 23 | 7.7s |  |
| 922 | `textblock_createline_fte` | 9 | 27.9s |  |
| 923 | `textblock_properties` | 118 | 7.8s |  |
| 924 | `textbox_click` | 37 | 27.2s |  |
| 925 | `textfield_event` | 66 | 7.6s |  |
| 926 | `textfield_focusin_event` | 9 | 7.2s |  |
| 927 | `textfield_input_dead_keys_windows` | 15 | 7.2s |  |
| 928 | `textfield_unload` | 39 | 26.3s |  |
| 929 | `textformat` | 1134 | 7.1s |  |
| 930 | `textformat_display` | 14 | 7.3s |  |
| 931 | `textformat_font_max_length` | 4 | 7.1s |  |
| 932 | `textline_inapplicable_properties` | 10 | 7.2s |  |
| 933 | `textline_name` | 1 | 7.0s |  |
| 934 | `textline_splitting_basic` | 76 | 7.3s |  |
| 935 | `textline_throwerror` | 30 | 7.1s |  |
| 936 | `textline_validity` | 162 | 7.3s |  |
| 937 | `throw` | 3 | 7.0s |  |
| 938 | `timeline_scripts` | 3 | 7.3s |  |
| 939 | `timer` | 90 | 8.1s |  |
| 940 | `timer_events` | 3 | 7.3s |  |
| 941 | `timer_finished` | 11 | 7.3s |  |
| 942 | `timer_reset` | 8 | 7.4s |  |
| 943 | `timer_setdelay` | 5 | 7.3s |  |
| 944 | `trace` | 12 | 7.0s |  |
| 945 | `truthiness` | 30 | 6.3s |  |
| 946 | `try_catch` | 11 | 21.3s |  |
| 947 | `try_catch_typed` | 12 | 6.5s |  |
| 948 | `typeof` | 30 | 6.5s |  |
| 949 | `uint_constr` | 92 | 6.6s |  |
| 950 | `uint_tofixed` | 1215 | 6.1s |  |
| 951 | `uint_tostring` | 3375 | 6.3s |  |
| 952 | `unchecked_function` | 15 | 6.0s |  |
| 953 | `unescape` | 28 | 6.0s |  |
| 954 | `url_loader` | 25 | 6.1s |  |
| 955 | `urlrequest` | 18 | 6.1s |  |
| 956 | `urlstream_basic` | 5 | 6.0s |  |
| 957 | `urshift` | 1058 | 17.6s |  |
| 958 | `utils3d` | 7 | 6.2s |  |
| 959 | `vector3d` | 397 | 10.7s |  |
| 960 | `vector_class` | 36 | 6.7s |  |
| 961 | `vector_class_call` | 11 | 6.5s |  |
| 962 | `vector_coercion` | 66 | 7.1s |  |
| 963 | `vector_concat` | 90 | 6.9s |  |
| 964 | `vector_constr` | 107 | 7.0s |  |
| 965 | `vector_enumeration` | 5 | 6.2s |  |
| 966 | `vector_every` | 92 | 7.1s |  |
| 967 | `vector_filter` | 95 | 7.1s |  |
| 968 | `vector_holes` | 24 | 6.3s |  |
| 969 | `vector_indexof` | 302 | 10.7s |  |
| 970 | `vector_insertat` | 270 | 7.3s |  |
| 971 | `vector_int_access` | 4 | 6.2s |  |
| 972 | `vector_int_delete` | 11 | 6.2s |  |
| 973 | `vector_join` | 58 | 6.7s |  |
| 974 | `vector_lastindexof` | 302 | 6.1s |  |
| 975 | `vector_legacy` | 10 | 6.2s |  |
| 976 | `vector_map` | 85 | 7.1s |  |
| 977 | `vector_object_final` | 1 | 6.2s |  |
| 978 | `vector_object_toString` | 10 | 6.2s |  |
| 979 | `vector_pushpop` | 255 | 7.5s |  |
| 980 | `vector_reborrow_bug` | 10 | 6.2s |  |
| 981 | `vector_removeat` | 172 | 19.9s |  |
| 982 | `vector_reverse` | 232 | 8.2s |  |
| 983 | `vector_shiftunshift` | 252 | 8.3s |  |
| 984 | `vector_slice` | 331 | 8.8s |  |
| 985 | `vector_sort` | 905 | 16.4s |  |
| 986 | `vector_splice` | 693 | 11.1s |  |
| 987 | `vector_splice_fixed_bug_compat` | 4 | 7.1s |  |
| 988 | `vector_tostring` | 79 | 7.7s |  |
| 989 | `verification` | 8 | 7.3s |  |
| 990 | `verify_abnormal_loop` | 1 | 7.1s |  |
| 991 | `verify_dxns_without_flag` | 3 | 7.4s |  |
| 992 | `verify_exception_targets_edge_case` | 1 | 7.1s |  |
| 993 | `verify_jump_to_middle_of_op` | 1 | 7.1s |  |
| 994 | `verify_lookup_switch_edge_case` | 1 | 7.1s |  |
| 995 | `verify_stack` | 5 | 7.2s |  |
| 996 | `verify_unreachable_exception` | 2 | 7.0s |  |
| 997 | `versioned_isplaying` | 2 | 7.1s |  |
| 998 | `virtual_properties` | 16 | 7.2s |  |
| 999 | `with` | 4 | 7.0s |  |
| 1000 | `wrong_arg_count` | 7 | 7.2s |  |
| 1001 | `xml_abstract_equality` | 36 | 7.3s |  |
| 1002 | `xml_advanced` | 52 | 7.0s |  |
| 1003 | `xml_appendchild` | 10 | 7.0s |  |
| 1004 | `xml_as_attribute` | 9 | 7.0s |  |
| 1005 | `xml_attribute` | 35 | 7.3s |  |
| 1006 | `xml_attribute_name` | 40 | 7.1s |  |
| 1007 | `xml_basic` | 33 | 7.2s |  |
| 1008 | `xml_child` | 25 | 7.2s |  |
| 1009 | `xml_childindex` | 7 | 7.1s |  |
| 1010 | `xml_children` | 43 | 7.7s |  |
| 1011 | `xml_class_call` | 9 | 7.0s |  |
| 1012 | `xml_contains` | 197 | 7.2s |  |
| 1013 | `xml_copy` | 20 | 3.1s |  |
| 1014 | `xml_ctor_from_tostring` | 23 | 19.2s |  |
| 1015 | `xml_delete` | 114 | 7.2s |  |
| 1016 | `xml_descendants` | 83 | 7.2s |  |
| 1017 | `xml_elements` | 6 | 7.0s |  |
| 1018 | `xml_equals_namespace_check` | 2 | 7.1s |  |
| 1019 | `xml_explicit_use_namespace` | 5 | 7.2s |  |
| 1020 | `xml_getdescendants_qname` | 21 | 7.1s |  |
| 1021 | `xml_has_property_via_in` | 26 | 7.1s |  |
| 1022 | `xml_hasownproperty` | 6 | 7.1s |  |
| 1023 | `xml_ignore_white` | 6 | 7.1s |  |
| 1024 | `xml_length` | 2 | 7.1s |  |
| 1025 | `xml_list_as_attribute` | 9 | 7.1s |  |
| 1026 | `xml_list_concat` | 20 | 7.1s |  |
| 1027 | `xml_list_enumerate` | 4 | 7.0s |  |
| 1028 | `xml_methods_settings` | 3 | 7.1s |  |
| 1029 | `xml_mismatched_tag` | 37 | 7.1s |  |
| 1030 | `xml_namespace` | 39 | 7.1s |  |
| 1031 | `xml_namespace_methods` | 245 | 7.1s |  |
| 1032 | `xml_namespaced_property` | 7 | 7.1s |  |
| 1033 | `xml_no_namespace` | 1 | 7.0s |  |
| 1034 | `xml_nodekind` | 3 | 7.0s |  |
| 1035 | `xml_normalize` | 35 | 7.2s |  |
| 1036 | `xml_notification_bubbling` | 361 | 7.1s |  |
| 1037 | `xml_parent` | 8 | 7.1s |  |
| 1038 | `xml_set_children` | 17 | 7.2s |  |
| 1039 | `xml_set_name` | 34 | 7.1s |  |
| 1040 | `xml_settings` | 6 | 3.0s |  |
| 1041 | `xml_simple_complex_content` | 47 | 7.1s |  |
| 1042 | `xml_socket` | 11 | 7.3s |  |
| 1043 | `xml_text` | 7 | 7.1s |  |
| 1044 | `xml_tostring` | 6 | 7.1s |  |
| 1045 | `xml_tostring_namespace` | 12 | 7.1s |  |
| 1046 | `xml_unescaping` | 23 | 7.1s |  |
| 1047 | `xml_weird_ignores` | 54 | 7.2s |  |
| 1048 | `xml_wildcard` | 11 | 7.1s |  |
| 1049 | `xmldocument` | 254 | 7.1s |  |
| 1050 | `xmlnode` | 3540 | 7.3s |  |
| 1051 | `zero_frame_clip` | 3 | 7.7s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.5s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 7.1s |  |
| 3 | `blend_transform` | 1 | 1 | 7.1s |  |
| 4 | `coerce_property` | 3 | 3 | 7.3s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.2s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 7.4s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.6s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 38.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 7.5s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.6s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 7.5s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 7.4s |  |
| 13 | `getter_different_namespace_setter` | 2 | 2 | 7.1s |  |
| 14 | `goto_framescript_queued` | 5 | 5 | 25.9s |  |
| 15 | `graphics_draw_path` | 50 | 50 | 26.9s |  |
| 16 | `int_toexponential` | 76 | 76 | 7.4s |  |
| 17 | `int_toprecision` | 441 | 441 | 7.3s |  |
| 18 | `simplebutton_childevents_script_order` | 4 | 4 | 8.4s |  |
| 19 | `slot_holes_fail` | 1 | 1 | 8.1s |  |
| 20 | `slot_id_exceeds_trait_count` | 1 | 1 | 29.4s |  |
| 21 | `soundchannel_position` | 74 | 74 | 27.4s |  |
| 22 | `soundchannel_soundcomplete` | 10 | 10 | 7.6s |  |
| 23 | `sprite_dropTarget` | 4 | 15 | 7.4s |  |
| 24 | `swf_9_goto_in_construct_frame` | 12 | 12 | 27.1s |  |
| 25 | `uint_toexponential` | 100 | 100 | 6.5s |  |
| 26 | `uint_toprecision` | 433 | 433 | 6.2s |  |
| 27 | `weird_superinterface_properties` | 1 | 1 | 25.3s |  |

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
| 1 | `verify_typecheck` | exit code 1 | 7.0s |  |

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
