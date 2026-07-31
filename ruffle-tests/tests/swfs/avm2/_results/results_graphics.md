# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-31 05:17 UTC

**Git SHA**: `c146dc66ef`

**Run Duration**: 185m 22s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1222 |
| Passing | **1039** (85.0%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1065** (87.2%) |
| Failing | 157 |
| Total expected lines | 151259 |
| Matching lines | 117730 (77.8%) |
| Mismatched lines | 33529 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 154 | 98.1% |
| Runtime Error | 3 | 1.9% |

## Passing Tests

**1039 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 7.7s |  |
| 2 | `accessibility` | 1 | 7.5s |  |
| 3 | `add` | 1058 | 20.0s |  |
| 4 | `agal_compiler` | 13 | 9.9s |  |
| 5 | `air_datagram_socket` | 1 | 9.0s |  |
| 6 | `air_hidden_lookup` | 2 | 7.5s |  |
| 7 | `air_ifilepromise` | 1 | 7.5s |  |
| 8 | `all_classes/security/swf11` | 3 | 7.4s |  |
| 9 | `amf_array_serialization` | 17 | 9.1s |  |
| 10 | `amf_custom_obj` | 26 | 7.4s |  |
| 11 | `amf_dictionary` | 9 | 7.3s |  |
| 12 | `amf_function` | 46 | 7.3s |  |
| 13 | `amf_invalid_date` | 2 | 7.1s |  |
| 14 | `amf_missing_prop` | 6 | 7.2s |  |
| 15 | `amf_nondynamic_function_prop` | 6 | 7.1s |  |
| 16 | `amf_setter_error` | 8 | 7.2s |  |
| 17 | `amf_vector` | 40 | 7.2s |  |
| 18 | `amf_xml` | 6 | 7.1s |  |
| 19 | `application_domain` | 4 | 7.2s |  |
| 20 | `array_access` | 18 | 7.2s |  |
| 21 | `array_access_interpreter` | 4 | 7.1s |  |
| 22 | `array_access_no_pubns` | 2 | 7.0s |  |
| 23 | `array_concat` | 41 | 7.2s |  |
| 24 | `array_constr` | 10 | 7.0s |  |
| 25 | `array_delete` | 44 | 7.2s |  |
| 26 | `array_enumeration` | 10 | 7.2s |  |
| 27 | `array_enumeration_elements` | 11 | 7.2s |  |
| 28 | `array_every` | 8 | 7.1s |  |
| 29 | `array_filter` | 6 | 7.1s |  |
| 30 | `array_foreach` | 18 | 7.1s |  |
| 31 | `array_hasownproperty` | 11 | 3.1s |  |
| 32 | `array_holes` | 9 | 7.1s |  |
| 33 | `array_index_max` | 84 | 7.0s |  |
| 34 | `array_indexof` | 25 | 7.2s |  |
| 35 | `array_join` | 26 | 7.2s |  |
| 36 | `array_lastindexof` | 29 | 7.1s |  |
| 37 | `array_length` | 14 | 7.1s |  |
| 38 | `array_literal` | 3 | 7.1s |  |
| 39 | `array_map` | 8 | 7.0s |  |
| 40 | `array_pop` | 52 | 7.2s |  |
| 41 | `array_push` | 24 | 7.1s |  |
| 42 | `array_reborrow_bug` | 6 | 7.1s |  |
| 43 | `array_reverse` | 28 | 7.2s |  |
| 44 | `array_shift` | 51 | 3.2s |  |
| 45 | `array_slice` | 39 | 7.2s |  |
| 46 | `array_some` | 8 | 7.1s |  |
| 47 | `array_sort` | 297 | 7.6s |  |
| 48 | `array_sort_fun_swf12` | 2 | 7.1s |  |
| 49 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 50 | `array_sort_random` | 210 | 7.2s |  |
| 51 | `array_sort_swf10_32bit` | 1 | 7.1s |  |
| 52 | `array_sorton` | 545 | 8.1s |  |
| 53 | `array_sparse_ops` | 41 | 7.4s |  |
| 54 | `array_splice` | 133 | 7.3s |  |
| 55 | `array_splice2` | 428 | 7.5s |  |
| 56 | `array_splice_types` | 48 | 7.4s |  |
| 57 | `array_storage` | 8 | 7.1s |  |
| 58 | `array_tolocalestring` | 9 | 7.3s |  |
| 59 | `array_tostring` | 12 | 7.2s |  |
| 60 | `array_unshift` | 24 | 7.1s |  |
| 61 | `array_valueof` | 9 | 7.1s |  |
| 62 | `array_vector_null_callback` | 10 | 7.2s |  |
| 63 | `astype` | 28 | 7.3s |  |
| 64 | `astypelate` | 24 | 7.3s |  |
| 65 | `astypelate_propagates` | 1 | 7.1s |  |
| 66 | `asymmetric_key_events` | 11 | 7.2s |  |
| 67 | `av_networking_params` | 9 | 7.3s |  |
| 68 | `av_tag_data` | 2 | 7.2s |  |
| 69 | `avm2_catchup_dobj` | 158 | 7.8s |  |
| 70 | `away3d_advanced_shallow_water_demo` | 0 | 84.9s |  |
| 71 | `bevel_filter` | 187 | 7.3s |  |
| 72 | `bitand` | 1058 | 19.5s |  |
| 73 | `bitmap_constr` | 17 | 7.4s |  |
| 74 | `bitmap_data` | 1000 | 15.6s |  |
| 75 | `bitmap_pixelsnapping` | 2 | 26.7s |  |
| 76 | `bitmap_properties` | 23 | 7.3s |  |
| 77 | `bitmap_subclass` | 7 | 8.6s |  |
| 78 | `bitmap_subclass_properties` | 9 | 7.6s |  |
| 79 | `bitmap_timeline` | 9 | 7.2s |  |
| 80 | `bitmapdata_accuracy` | 1 | 43.4s |  |
| 81 | `bitmapdata_applyfilter_blur` | 0 | 26.8s |  |
| 82 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.0s |  |
| 83 | `bitmapdata_applyfilter_destpoint` | 0 | 26.2s |  |
| 84 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.7s |  |
| 85 | `bitmapdata_clone` | 13 | 7.4s |  |
| 86 | `bitmapdata_colortransform` | 0 | 7.5s |  |
| 87 | `bitmapdata_colortransform_oob` | 2 | 7.0s |  |
| 88 | `bitmapdata_constr` | 22 | 3.1s |  |
| 89 | `bitmapdata_constructor_from_timeline` | 1 | 7.5s |  |
| 90 | `bitmapdata_copychannel` | 0 | 30.3s |  |
| 91 | `bitmapdata_copypixels` | 23 | 28.7s |  |
| 92 | `bitmapdata_copypixels_blend_over` | 1 | 7.7s |  |
| 93 | `bitmapdata_copypixelstobytearray` | 39 | 7.6s |  |
| 94 | `bitmapdata_dispose` | 7 | 7.6s |  |
| 95 | `bitmapdata_draw` | 0 | 28.0s |  |
| 96 | `bitmapdata_draw_colortransform` | 0 | 7.9s |  |
| 97 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 27.3s |  |
| 98 | `bitmapdata_draw_filters` | 0 | 27.1s |  |
| 99 | `bitmapdata_draw_masks` | 0 | 7.6s |  |
| 100 | `bitmapdata_draw_rotation` | 0 | 7.8s |  |
| 101 | `bitmapdata_draw_self_via_graphic` | 0 | 7.9s |  |
| 102 | `bitmapdata_draw_stage` | 0 | 27.0s |  |
| 103 | `bitmapdata_drawwithquality` | 0 | 7.8s |  |
| 104 | `bitmapdata_embedded` | 9 | 8.0s |  |
| 105 | `bitmapdata_fillrect` | 0 | 7.9s |  |
| 106 | `bitmapdata_filter_sourcerect` | 0 | 23.4s |  |
| 107 | `bitmapdata_floodfill` | 35 | 7.5s |  |
| 108 | `bitmapdata_getpixels` | 39 | 27.3s |  |
| 109 | `bitmapdata_getvector` | 27 | 3.3s |  |
| 110 | `bitmapdata_histogram` | 59 | 3.4s |  |
| 111 | `bitmapdata_hittest` | 112 | 8.1s |  |
| 112 | `bitmapdata_hittest_threshold` | 18 | 7.6s |  |
| 113 | `bitmapdata_opaque` | 0 | 7.8s |  |
| 114 | `bitmapdata_pixeldissolve` | 1037 | 8.2s |  |
| 115 | `bitmapdata_pixeldissolve_image` | 0 | 8.0s |  |
| 116 | `bitmapdata_rectangle_rounding` | 16 | 7.4s |  |
| 117 | `bitmapdata_setpixels` | 286 | 7.6s |  |
| 118 | `bitmapdata_setvector` | 26 | 7.6s |  |
| 119 | `bitmapdata_sync` | 0 | 27.1s |  |
| 120 | `bitmapdata_threshold` | 176 | 8.3s |  |
| 121 | `bitnot` | 46 | 7.6s |  |
| 122 | `bitor` | 1058 | 19.1s |  |
| 123 | `bitxor` | 1058 | 19.1s |  |
| 124 | `blend_mode_null` | 1 | 7.4s |  |
| 125 | `blend_multiply_alpha` | 0 | 7.8s |  |
| 126 | `blend_scroll` | 0 | 7.8s |  |
| 127 | `blend_shader_luma_lighten` | 3 | 8.2s |  |
| 128 | `blur_filter` | 43 | 7.7s |  |
| 129 | `boolean_constr` | 32 | 7.4s |  |
| 130 | `boolean_negation` | 30 | 7.5s |  |
| 131 | `boolean_tostring` | 8 | 7.4s |  |
| 132 | `broadcast_event` | 7 | 7.5s |  |
| 133 | `button_bounds` | 1 | 7.4s |  |
| 134 | `button_hittest` | 2 | 26.2s |  |
| 135 | `button_nested_frame` | 48 | 26.5s |  |
| 136 | `bytearray` | 48 | 7.6s |  |
| 137 | `bytearray_compress` | 31 | 7.3s |  |
| 138 | `bytearray_errors` | 24 | 7.5s |  |
| 139 | `bytearray_method_serialization` | 1 | 7.3s |  |
| 140 | `bytearray_oom` | 3 | 7.4s |  |
| 141 | `bytearray_readobject_amf0` | 50 | 7.3s |  |
| 142 | `bytearray_readobject_amf3` | 53 | 7.4s |  |
| 143 | `bytearray_readutf8bytes_with_bom` | 16 | 7.4s |  |
| 144 | `bytearray_serialization` | 3 | 7.4s |  |
| 145 | `bytearray_string_null` | 19 | 7.5s |  |
| 146 | `bytearray_tostring` | 15 | 7.3s |  |
| 147 | `bytearray_utf16` | 8 | 7.3s |  |
| 148 | `bytearray_writeobject` | 24 | 7.2s |  |
| 149 | `callee_in_initializer` | 6 | 7.2s |  |
| 150 | `callproplex_class` | 1 | 7.3s |  |
| 151 | `capabilities_resolution` | 8 | 26.9s |  |
| 152 | `catch_class` | 6 | 7.3s |  |
| 153 | `catch_scope_slot` | 7 | 3.3s |  |
| 154 | `checkfilter` | 4 | 3.2s |  |
| 155 | `class_call` | 32 | 7.5s |  |
| 156 | `class_cast_call` | 14 | 7.4s |  |
| 157 | `class_enumeration` | 4 | 7.3s |  |
| 158 | `class_has_own_property` | 2 | 7.3s |  |
| 159 | `class_init_interpreter_mode` | 1 | 7.2s |  |
| 160 | `class_is` | 32 | 7.4s |  |
| 161 | `class_methods` | 5 | 7.3s |  |
| 162 | `class_object_properties` | 10 | 7.5s |  |
| 163 | `class_singleton` | 18 | 7.5s |  |
| 164 | `class_supercalls_errors` | 35 | 7.6s |  |
| 165 | `class_supercalls_mismatched` | 26 | 7.5s |  |
| 166 | `class_superclass_wrong_order` | 1 | 25.8s |  |
| 167 | `class_to_locale_string` | 2 | 6.8s |  |
| 168 | `class_to_string` | 2 | 6.7s |  |
| 169 | `class_value_of` | 2 | 6.8s |  |
| 170 | `click_block` | 5 | 7.7s |  |
| 171 | `click_invisible` | 3 | 6.9s |  |
| 172 | `closures` | 12 | 6.8s |  |
| 173 | `coerce_return_type` | 40 | 6.9s |  |
| 174 | `coerce_return_type_fail` | 2 | 6.7s |  |
| 175 | `coerce_return_void` | 3 | 6.7s |  |
| 176 | `coerce_string` | 86 | 6.8s |  |
| 177 | `coerce_string_precision` | 28 | 6.7s |  |
| 178 | `coerce_to_primitive_side_effects` | 29 | 6.7s |  |
| 179 | `color_matrix_filter` | 19 | 6.9s |  |
| 180 | `construct_errors_swf10` | 8 | 6.8s |  |
| 181 | `construct_frame_list` | 22 | 25.9s |  |
| 182 | `construct_interface` | 3 | 6.7s |  |
| 183 | `constructor_call` | 3 | 6.7s |  |
| 184 | `constructors_vs_timeline` | 5 | 26.1s |  |
| 185 | `constructprop_dynamic_primitive` | 7 | 6.9s |  |
| 186 | `content_element_basic` | 50 | 7.0s |  |
| 187 | `context3d_creation` | 9 | 6.9s |  |
| 188 | `control_flow_bool` | 4 | 6.8s |  |
| 189 | `control_flow_stricteq` | 8 | 6.9s |  |
| 190 | `convert_boolean` | 30 | 6.8s |  |
| 191 | `convert_integer` | 90 | 6.9s |  |
| 192 | `convert_number` | 56 | 6.9s |  |
| 193 | `convert_uinteger` | 90 | 7.0s |  |
| 194 | `convolution_filter` | 89 | 6.9s |  |
| 195 | `cpool_index_invalid_bytecode_1` | 6 | 6.7s |  |
| 196 | `cpool_index_invalid_bytecode_2` | 3 | 6.8s |  |
| 197 | `cpool_index_invalid_bytecode_3` | 1 | 6.7s |  |
| 198 | `cross_api_version_call_older` | 12 | 7.0s |  |
| 199 | `cryptscore` | 11 | 6.9s |  |
| 200 | `date` | 30 | 7.6s |  |
| 201 | `date_parse` | 36 | 7.2s |  |
| 202 | `declocal` | 46 | 7.2s |  |
| 203 | `declocal_i` | 46 | 7.2s |  |
| 204 | `decode_uri` | 71 | 7.5s |  |
| 205 | `decrement` | 46 | 7.2s |  |
| 206 | `decrement_i` | 46 | 3.2s |  |
| 207 | `default_values` | 7 | 7.2s |  |
| 208 | `dictionary_access` | 62 | 7.4s |  |
| 209 | `dictionary_access_no_pubns` | 2 | 7.1s |  |
| 210 | `dictionary_delete` | 101 | 7.8s |  |
| 211 | `dictionary_foreach` | 42 | 7.4s |  |
| 212 | `dictionary_hasownproperty` | 63 | 7.5s |  |
| 213 | `dictionary_in` | 62 | 7.5s |  |
| 214 | `dictionary_iter_modify` | 8 | 7.2s |  |
| 215 | `dictionary_namespaces` | 36 | 7.3s |  |
| 216 | `dictionary_primitive_keys` | 29 | 7.2s |  |
| 217 | `displacement_map_filter` | 61 | 7.4s |  |
| 218 | `displayobject_alpha` | 277 | 7.2s |  |
| 219 | `displayobject_blendmode` | 0 | 7.4s |  |
| 220 | `displayobject_colortransform_nested` | 0 | 26.7s |  |
| 221 | `displayobject_filters` | 17 | 7.5s |  |
| 222 | `displayobject_from_enterframe` | 1 | 26.8s |  |
| 223 | `displayobject_getbounds_shape` | 0 | 26.8s |  |
| 224 | `displayobject_height` | 6052 | 27.5s |  |
| 225 | `displayobject_hittestobject` | 32 | 7.5s |  |
| 226 | `displayobject_hittestpoint` | 49 | 7.8s |  |
| 227 | `displayobject_hittestpoint_root` | 13 | 7.6s |  |
| 228 | `displayobject_invalid_floats` | 60 | 7.2s |  |
| 229 | `displayobject_invalid_props` | 3 | 3.1s |  |
| 230 | `displayobject_mask` | 3 | 7.6s |  |
| 231 | `displayobject_mask_self_referential` | 0 | 6.7s |  |
| 232 | `displayobject_metaData` | 3 | 6.6s |  |
| 233 | `displayobject_name` | 22 | 7.4s |  |
| 234 | `displayobject_name_from_timeline` | 24 | 6.9s |  |
| 235 | `displayobject_parent` | 12 | 6.8s |  |
| 236 | `displayobject_root` | 24 | 6.8s |  |
| 237 | `displayobject_rotation` | 1284 | 6.9s |  |
| 238 | `displayobject_set_matrix_nested` | 0 | 26.2s |  |
| 239 | `displayobject_set_name_loaded` | 3 | 7.0s |  |
| 240 | `displayobject_subclass` | 2 | 6.8s |  |
| 241 | `displayobject_visible` | 23 | 6.7s |  |
| 242 | `displayobject_width` | 4852 | 26.1s |  |
| 243 | `displayobject_x` | 614 | 6.8s |  |
| 244 | `displayobject_y` | 617 | 6.8s |  |
| 245 | `displayobjectcontainer_addchild` | 32 | 6.9s |  |
| 246 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.7s |  |
| 247 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.0s |  |
| 248 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.0s |  |
| 249 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.0s |  |
| 250 | `displayobjectcontainer_addchildat` | 42 | 6.9s |  |
| 251 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 2.9s |  |
| 252 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.9s |  |
| 253 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.9s |  |
| 254 | `displayobjectcontainer_contains` | 66 | 26.3s |  |
| 255 | `displayobjectcontainer_getchildat` | 4 | 6.9s |  |
| 256 | `displayobjectcontainer_getchildbyname` | 9 | 6.8s |  |
| 257 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.7s |  |
| 258 | `displayobjectcontainer_getchildindex` | 28 | 6.8s |  |
| 259 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 6.9s |  |
| 260 | `displayobjectcontainer_removechild` | 10 | 6.8s |  |
| 261 | `displayobjectcontainer_removechild_errors` | 4 | 6.8s |  |
| 262 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.9s |  |
| 263 | `displayobjectcontainer_removechildat` | 18 | 6.8s |  |
| 264 | `displayobjectcontainer_removechildren` | 51 | 7.0s |  |
| 265 | `displayobjectcontainer_setchildindex` | 42 | 6.7s |  |
| 266 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.2s |  |
| 267 | `displayobjectcontainer_swapchildren` | 42 | 6.8s |  |
| 268 | `displayobjectcontainer_swapchildrenat` | 42 | 6.8s |  |
| 269 | `displayobjectcontainer_timelineinstance` | 48 | 26.0s |  |
| 270 | `divide` | 1058 | 19.1s |  |
| 271 | `doabc_is_eager` | 1 | 25.7s |  |
| 272 | `documentclass` | 9 | 7.2s |  |
| 273 | `domain_memory` | 133 | 8.3s |  |
| 274 | `drag_drop` | 10 | 7.4s |  |
| 275 | `drop_shadow_filter` | 172 | 7.3s |  |
| 276 | `duplicate_defs` | 1 | 7.0s |  |
| 277 | `eager_init` | 1 | 7.1s |  |
| 278 | `east_asian_justifier_clone` | 8 | 3.0s |  |
| 279 | `edit_text_linkage` | 7 | 7.3s |  |
| 280 | `edittext_align` | 60 | 7.4s |  |
| 281 | `edittext_always_show_selection` | 0 | 26.3s |  |
| 282 | `edittext_antialiastype` | 296 | 7.4s |  |
| 283 | `edittext_at_point_methods_basic` | 16 | 8.5s |  |
| 284 | `edittext_autosize` | 39 | 7.5s |  |
| 285 | `edittext_autosize_align` | 0 | 26.5s |  |
| 286 | `edittext_autosize_height_dynamic` | 60 | 26.8s |  |
| 287 | `edittext_autosize_height_input` | 60 | 7.3s |  |
| 288 | `edittext_autosize_lazy_bounds_events` | 65 | 7.6s |  |
| 289 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.2s |  |
| 290 | `edittext_autosize_lazy_bounds_props` | 490 | 8.6s |  |
| 291 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.9s |  |
| 292 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.4s |  |
| 293 | `edittext_bottom_scroll_v_basic` | 210 | 7.3s |  |
| 294 | `edittext_bounds_scale` | 24 | 25.6s |  |
| 295 | `edittext_bullet` | 30 | 7.2s |  |
| 296 | `edittext_default_format` | 221 | 7.4s |  |
| 297 | `edittext_default_format_empty` | 136 | 7.5s |  |
| 298 | `edittext_empty_text_format` | 7 | 7.2s |  |
| 299 | `edittext_focus_selection` | 5 | 7.2s |  |
| 300 | `edittext_font_size` | 45 | 7.2s |  |
| 301 | `edittext_format_empty_font` | 8 | 7.1s |  |
| 302 | `edittext_get_char_index_at_point` | 4 | 27.2s |  |
| 303 | `edittext_get_line_index_at_point` | 2 | 26.3s |  |
| 304 | `edittext_get_line_index_of_char` | 76 | 8.1s |  |
| 305 | `edittext_getcharboundaries` | 172 | 7.6s |  |
| 306 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.6s |  |
| 307 | `edittext_getcharboundaries_scroll` | 85 | 7.4s |  |
| 308 | `edittext_getlinemetrics` | 146 | 7.5s |  |
| 309 | `edittext_html` | 3101 | 7.7s |  |
| 310 | `edittext_html_condensewhite` | 487 | 7.3s |  |
| 311 | `edittext_html_entity` | 4 | 7.5s |  |
| 312 | `edittext_html_font_size_swf12` | 267 | 7.3s |  |
| 313 | `edittext_html_font_size_swf13` | 273 | 7.0s |  |
| 314 | `edittext_html_roundtrip` | 17 | 7.2s |  |
| 315 | `edittext_ime_focus_lost` | 9 | 26.2s |  |
| 316 | `edittext_input_control` | 12 | 7.4s |  |
| 317 | `edittext_leading` | 9 | 7.5s |  |
| 318 | `edittext_letter_spacing` | 15 | 7.2s |  |
| 319 | `edittext_line_methods` | 294 | 8.6s |  |
| 320 | `edittext_line_metrics` | 11 | 27.5s |  |
| 321 | `edittext_margins` | 25 | 7.3s |  |
| 322 | `edittext_max_scroll_h_basic` | 475 | 7.4s |  |
| 323 | `edittext_max_scroll_v_basic` | 1000 | 7.3s |  |
| 324 | `edittext_mouse_selection` | 363 | 27.1s |  |
| 325 | `edittext_mousedown` | 3 | 7.5s |  |
| 326 | `edittext_mouseenabled` | 26 | 7.2s |  |
| 327 | `edittext_newline_character` | 22 | 7.1s |  |
| 328 | `edittext_newline_stripping` | 64 | 9.8s |  |
| 329 | `edittext_newlines` | 30 | 7.2s |  |
| 330 | `edittext_paragraph_methods` | 257 | 7.2s |  |
| 331 | `edittext_paste_events` | 8 | 7.2s |  |
| 332 | `edittext_paste_maxchars` | 4 | 7.2s |  |
| 333 | `edittext_paste_restrict` | 16 | 7.0s |  |
| 334 | `edittext_restrict` | 191 | 7.2s |  |
| 335 | `edittext_restrict_events` | 22 | 7.2s |  |
| 336 | `edittext_scrollh` | 10 | 3.1s |  |
| 337 | `edittext_selected_text` | 9 | 7.1s |  |
| 338 | `edittext_set_html_same` | 17 | 7.1s |  |
| 339 | `edittext_set_text_vs_html` | 9 | 7.1s |  |
| 340 | `edittext_stylesheet` | 536 | 7.5s |  |
| 341 | `edittext_stylesheet_custom_tag` | 76 | 7.2s |  |
| 342 | `edittext_stylesheet_display` | 272 | 7.2s |  |
| 343 | `edittext_underline` | 40 | 7.3s |  |
| 344 | `edittext_width_height` | 103 | 7.3s |  |
| 345 | `edittext_wordwrap_word` | 150 | 7.3s |  |
| 346 | `edittext_wrap_breaks` | 2375 | 7.5s |  |
| 347 | `element_format_clone` | 44 | 7.2s |  |
| 348 | `element_format_constructor_order` | 64 | 7.2s |  |
| 349 | `element_format_properties` | 235 | 8.0s |  |
| 350 | `empty_bounds` | 1 | 7.0s |  |
| 351 | `encode_uri_surrogate_pair_swf11` | 15 | 6.8s |  |
| 352 | `equals` | 512 | 10.9s |  |
| 353 | `error_geterrormessage` | 779 | 7.1s |  |
| 354 | `error_prototype` | 15 | 7.0s |  |
| 355 | `error_stack_trace_debug_swf17` | 0 | 25.5s |  |
| 356 | `error_stack_trace_debug_swf18` | 0 | 6.8s |  |
| 357 | `error_stack_trace_release_swf17` | 0 | 6.8s |  |
| 358 | `error_stack_trace_release_swf18` | 0 | 6.8s |  |
| 359 | `error_tostring` | 29 | 7.0s |  |
| 360 | `error_tostring_more` | 86 | 7.1s |  |
| 361 | `es3_inheritance` | 31 | 7.1s |  |
| 362 | `es4_inheritance` | 30 | 7.1s |  |
| 363 | `es4_interfaces` | 30 | 7.0s |  |
| 364 | `es4_method_binding` | 8 | 7.0s |  |
| 365 | `es4_oop_prototypes` | 14 | 7.2s |  |
| 366 | `es4_protected_inheritance` | 6 | 7.0s |  |
| 367 | `escape` | 71 | 7.1s |  |
| 368 | `event_bubbles` | 2 | 7.0s |  |
| 369 | `event_cancelable` | 2 | 6.9s |  |
| 370 | `event_clone` | 20 | 7.0s |  |
| 371 | `event_clone_error_redispatch` | 3 | 7.2s |  |
| 372 | `event_clone_on_redispatch` | 10 | 7.2s |  |
| 373 | `event_formattostring` | 31 | 7.1s |  |
| 374 | `event_isdefaultprevented` | 12 | 7.0s |  |
| 375 | `event_target_getter` | 5 | 3.0s |  |
| 376 | `event_target_set` | 9 | 6.9s |  |
| 377 | `event_type` | 1 | 7.4s |  |
| 378 | `event_valueof_tostring` | 18 | 7.3s |  |
| 379 | `eventdispatcher_dispatchevent` | 12 | 7.4s |  |
| 380 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.4s |  |
| 381 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.4s |  |
| 382 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.4s |  |
| 383 | `eventdispatcher_dispatchevent_this` | 5 | 7.3s |  |
| 384 | `eventdispatcher_haseventlistener` | 25 | 7.4s |  |
| 385 | `eventdispatcher_interface_invoke` | 1 | 7.3s |  |
| 386 | `eventdispatcher_tostring` | 10 | 7.4s |  |
| 387 | `eventdispatcher_willtrigger` | 25 | 7.3s |  |
| 388 | `falsiness` | 30 | 7.4s |  |
| 389 | `fast_index_access` | 12 | 7.5s |  |
| 390 | `filefilter_properties` | 4 | 7.4s |  |
| 391 | `filereference_browse_cancel` | 3 | 7.4s |  |
| 392 | `filereference_browse_select` | 9 | 7.4s |  |
| 393 | `filereference_load` | 31 | 3.3s |  |
| 394 | `filereference_save` | 16 | 7.4s |  |
| 395 | `filereference_save_and_browse` | 42 | 7.4s |  |
| 396 | `filereference_save_and_load` | 22 | 7.4s |  |
| 397 | `filereference_uninitialized` | 8 | 7.3s |  |
| 398 | `filereferencelist_browse_cancel` | 6 | 7.3s |  |
| 399 | `filereferencelist_browse_select` | 7 | 7.3s |  |
| 400 | `filter_rewind` | 8 | 7.6s |  |
| 401 | `filters_array_holes` | 25 | 7.5s |  |
| 402 | `finddef` | 3 | 7.3s |  |
| 403 | `findprop_global_prototype` | 6 | 7.3s |  |
| 404 | `flash_media_video_constructor` | 156 | 8.2s |  |
| 405 | `flash_media_video_rotation_probe` | 27 | 7.4s |  |
| 406 | `flash_xml` | 29 | 7.4s |  |
| 407 | `flash_xml_cloneNode` | 22 | 7.4s |  |
| 408 | `flash_xml_namespace` | 109 | 7.3s |  |
| 409 | `flash_xml_removeNode` | 60 | 7.4s |  |
| 410 | `focus_events_code` | 161 | 26.8s |  |
| 411 | `focus_events_key_basic` | 132 | 26.6s |  |
| 412 | `focus_events_key_navigation` | 53 | 7.5s |  |
| 413 | `focus_events_key_same_object` | 26 | 7.4s |  |
| 414 | `focus_events_mixed_key_mouse` | 100 | 26.3s |  |
| 415 | `focus_events_mouse_basic` | 260 | 26.5s |  |
| 416 | `focus_events_mouse_focusable` | 112 | 26.5s |  |
| 417 | `focus_events_mouse_same_object` | 40 | 26.0s |  |
| 418 | `focus_remove` | 20 | 26.1s |  |
| 419 | `focus_root_movie` | 4 | 26.2s |  |
| 420 | `focus_stage` | 1 | 7.3s |  |
| 421 | `focusrect` | 18 | 8.1s |  |
| 422 | `focusrect_focuslost` | 9 | 7.4s |  |
| 423 | `focusrect_property` | 110 | 7.4s |  |
| 424 | `font_description_clone` | 14 | 7.3s |  |
| 425 | `font_embedded` | 24 | 7.7s |  |
| 426 | `font_enumeratefonts` | 41 | 7.9s |  |
| 427 | `font_enumeratefonts_filter` | 4 | 26.7s |  |
| 428 | `font_hasglyphs` | 40 | 7.7s |  |
| 429 | `framelabel_constr` | 5 | 7.3s |  |
| 430 | `function_call` | 12 | 7.4s |  |
| 431 | `function_call_arguments` | 46 | 3.3s |  |
| 432 | `function_call_arguments_enumerate` | 5 | 7.3s |  |
| 433 | `function_call_coercion` | 108 | 7.7s |  |
| 434 | `function_call_default` | 6 | 7.3s |  |
| 435 | `function_call_rest` | 22 | 7.3s |  |
| 436 | `function_call_types` | 3 | 7.3s |  |
| 437 | `function_call_via_apply` | 11 | 7.3s |  |
| 438 | `function_call_via_call` | 3 | 7.3s |  |
| 439 | `function_display_anonymous` | 7 | 3.2s |  |
| 440 | `function_length` | 6 | 7.3s |  |
| 441 | `function_object` | 2 | 7.3s |  |
| 442 | `function_proto` | 5 | 7.3s |  |
| 443 | `function_proto_created` | 61 | 7.3s |  |
| 444 | `function_to_locale_string` | 4 | 7.3s |  |
| 445 | `function_to_string` | 4 | 7.2s |  |
| 446 | `function_type` | 6 | 7.3s |  |
| 447 | `function_unbound_this` | 51 | 7.4s |  |
| 448 | `function_value_of` | 4 | 7.3s |  |
| 449 | `game_input` | 4 | 7.3s |  |
| 450 | `generate_random_bytes` | 3 | 7.3s |  |
| 451 | `get_definition_by_name` | 11 | 7.3s |  |
| 452 | `get_qualified_class_name` | 20 | 7.3s |  |
| 453 | `get_qualified_super_class_name` | 18 | 7.2s |  |
| 454 | `get_slot_edge_cases` | 1 | 25.7s |  |
| 455 | `get_timer` | 2 | 7.1s |  |
| 456 | `getglobalslot` | 1 | 7.0s |  |
| 457 | `getouterscope` | 8 | 7.1s |  |
| 458 | `getter_different_namespace_setter` | 2 | 7.0s |  |
| 459 | `glow_filter` | 127 | 7.3s |  |
| 460 | `goto_button_nested_framescript` | 28 | 26.2s |  |
| 461 | `goto_in_constructframe` | 12 | 7.3s |  |
| 462 | `goto_in_scene_last_frame` | 2 | 25.7s |  |
| 463 | `goto_methods` | 56 | 7.4s |  |
| 464 | `goto_methods_swfver10` | 8 | 7.2s |  |
| 465 | `goto_nested_construct_sibling` | 18 | 7.5s |  |
| 466 | `goto_nested_framescript` | 9 | 7.3s |  |
| 467 | `goto_on_orphan` | 15 | 7.4s |  |
| 468 | `gradient_bevel_filter` | 206 | 7.2s |  |
| 469 | `gradient_glow_filter` | 206 | 7.1s |  |
| 470 | `graphics_bad_direct_commands` | 5 | 7.9s |  |
| 471 | `graphics_bitmap_fill` | 0 | 9.0s |  |
| 472 | `graphics_bitmaps` | 0 | 7.8s |  |
| 473 | `graphics_direct_commands` | 0 | 7.7s |  |
| 474 | `graphics_draw_triangles` | 98 | 26.8s |  |
| 475 | `graphics_gradients` | 0 | 7.5s |  |
| 476 | `graphics_gradients_nulls` | 0 | 7.4s |  |
| 477 | `graphics_path` | 56 | 7.2s |  |
| 478 | `graphics_round_rects` | 0 | 7.2s |  |
| 479 | `graphics_simple_shapes` | 0 | 7.4s |  |
| 480 | `greaterequals` | 512 | 11.1s |  |
| 481 | `greaterthan` | 512 | 11.2s |  |
| 482 | `has_own_property` | 102 | 7.7s |  |
| 483 | `hasownproperty_namespaces` | 2 | 7.1s |  |
| 484 | `hello_world` | 1 | 7.1s |  |
| 485 | `hittest_morph` | 30 | 7.3s |  |
| 486 | `if_eq` | 10 | 7.2s |  |
| 487 | `if_gt` | 1 | 7.2s |  |
| 488 | `if_gte` | 10 | 7.2s |  |
| 489 | `if_lt` | 1 | 7.1s |  |
| 490 | `if_lte` | 10 | 7.0s |  |
| 491 | `if_ne` | 7 | 3.1s |  |
| 492 | `if_stricteq` | 6 | 7.1s |  |
| 493 | `if_strictne` | 11 | 7.1s |  |
| 494 | `ime_linux_dead_keys` | 10 | 7.3s |  |
| 495 | `in` | 102 | 7.6s |  |
| 496 | `inclocal` | 46 | 7.1s |  |
| 497 | `inclocal_i` | 46 | 7.2s |  |
| 498 | `increment` | 46 | 7.2s |  |
| 499 | `increment_i` | 46 | 7.2s |  |
| 500 | `indexing_delete` | 75 | 7.1s |  |
| 501 | `instanceof` | 58 | 7.3s |  |
| 502 | `instantiation_on_enter_frame` | 7 | 25.6s |  |
| 503 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.0s |  |
| 504 | `int_constr` | 92 | 7.0s |  |
| 505 | `int_edge_cases` | 19 | 7.1s |  |
| 506 | `int_instanceof` | 3 | 7.1s |  |
| 507 | `int_tofixed` | 1215 | 7.0s |  |
| 508 | `int_tostring` | 3375 | 7.0s |  |
| 509 | `interactiveobject_enabled` | 25 | 7.0s |  |
| 510 | `interface_namespaces` | 78 | 7.3s |  |
| 511 | `is_finite` | 46 | 7.1s |  |
| 512 | `is_nan` | 46 | 7.0s |  |
| 513 | `is_prototype_of` | 12 | 7.1s |  |
| 514 | `issue_10221` | 2 | 7.0s |  |
| 515 | `issue_13780` | 12 | 7.1s |  |
| 516 | `issue_14901` | 1 | 7.0s |  |
| 517 | `issue_17675_edittext_paste_maxchars` | 1 | 7.0s |  |
| 518 | `issue_5292` | 5 | 7.0s |  |
| 519 | `issue_8630` | 2 | 25.4s |  |
| 520 | `issue_8630_scriptremove` | 11 | 7.1s |  |
| 521 | `istype` | 24 | 3.1s |  |
| 522 | `istypelate` | 58 | 7.3s |  |
| 523 | `istypelate_coerce` | 198 | 8.2s |  |
| 524 | `jpeg_loader_context` | 6 | 7.1s |  |
| 525 | `json_errors` | 9 | 25.7s |  |
| 526 | `json_parse` | 21 | 7.1s |  |
| 527 | `json_stringify` | 12 | 7.3s |  |
| 528 | `json_stringify_order` | 1 | 7.0s |  |
| 529 | `json_version_gated` | 1 | 7.0s |  |
| 530 | `key_input_80percent` | 1812 | 7.3s |  |
| 531 | `key_input_location` | 126 | 7.1s |  |
| 532 | `key_input_numpad` | 384 | 6.9s |  |
| 533 | `lazyinit` | 17 | 7.1s |  |
| 534 | `lessequals` | 512 | 11.0s |  |
| 535 | `lessthan` | 512 | 10.9s |  |
| 536 | `loader_bitmap_transparency` | 14 | 7.2s |  |
| 537 | `loader_bytes_unknown_content` | 14 | 7.2s |  |
| 538 | `loader_child_getdefinition` | 5 | 7.3s |  |
| 539 | `loader_duplicate_coerce` | 3 | 7.3s |  |
| 540 | `loader_duplicate_coerce_new_domain` | 4 | 7.2s |  |
| 541 | `loader_error_in_root_ctor` | 4 | 7.4s |  |
| 542 | `loader_events` | 92 | 7.8s |  |
| 543 | `loader_image` | 8 | 7.5s |  |
| 544 | `loader_jpegxr` | 2 | 25.9s |  |
| 545 | `loader_jpegxr_alpha` | 1 | 25.5s |  |
| 546 | `loader_loadbytes_events` | 30 | 7.8s |  |
| 547 | `loader_loadbytes_invalid_png` | 4 | 25.4s |  |
| 548 | `loader_loadbytes_url` | 12 | 7.4s |  |
| 549 | `loader_loaderurl` | 6 | 7.5s |  |
| 550 | `loader_noninteractive_try_click_root` | 5 | 25.9s |  |
| 551 | `loader_reuse` | 38 | 7.3s |  |
| 552 | `loader_unknown_content` | 24 | 7.2s |  |
| 553 | `loader_visibility_interactive` | 1 | 7.2s |  |
| 554 | `loaderinfo_events` | 7 | 7.0s |  |
| 555 | `loaderinfo_loadurl` | 12 | 5.3s |  |
| 556 | `loaderinfo_more` | 6 | 5.0s |  |
| 557 | `loaderinfo_properties` | 18 | 5.0s |  |
| 558 | `loaderinfo_properties_not_loaded` | 23 | 5.2s |  |
| 559 | `loaderinfo_root` | 10 | 5.2s |  |
| 560 | `loaderinfo_root_allows` | 2 | 4.7s |  |
| 561 | `localconnection_send` | 4 | 5.3s |  |
| 562 | `lshift` | 1058 | 12.1s |  |
| 563 | `mask_reapply` | 1 | 5.0s |  |
| 564 | `math` | 497 | 5.2s |  |
| 565 | `matrix3d` | 57 | 5.3s |  |
| 566 | `matrix3d_compose` | 34 | 5.0s |  |
| 567 | `matrix3d_invert` | 18 | 1.9s |  |
| 568 | `missing_external_interface` | 10 | 4.8s |  |
| 569 | `modulo` | 1058 | 12.0s |  |
| 570 | `morph_shape` | 2 | 18.9s |  |
| 571 | `mouse_children` | 192 | 18.9s |  |
| 572 | `mouse_click_events` | 90 | 18.3s |  |
| 573 | `mouse_double_click_events` | 188 | 4.8s |  |
| 574 | `mouse_empty_parent` | 4 | 4.8s |  |
| 575 | `mouse_over_while_dragging` | 3 | 4.7s |  |
| 576 | `mouse_pick_button_mode` | 2 | 5.2s |  |
| 577 | `mouse_pick_dobj_mask` | 4 | 5.0s |  |
| 578 | `mouse_pick_masking` | 7 | 19.1s |  |
| 579 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 19.1s |  |
| 580 | `mouse_pick_non_interactive_dobj_mask` | 3 | 5.7s |  |
| 581 | `mouse_pick_text` | 8 | 5.6s |  |
| 582 | `mouse_sibling` | 8 | 5.1s |  |
| 583 | `mouse_wheel_events` | 36 | 20.8s |  |
| 584 | `mouseevent_constr` | 66 | 4.8s |  |
| 585 | `mouseevent_stagexy` | 35 | 4.7s |  |
| 586 | `mouseevent_valueof_tostring` | 28 | 4.8s |  |
| 587 | `movieclip_addframescript` | 3 | 19.0s |  |
| 588 | `movieclip_child_property` | 16 | 5.1s |  |
| 589 | `movieclip_constr` | 21 | 6.6s |  |
| 590 | `movieclip_currentlabels` | 17 | 24.9s |  |
| 591 | `movieclip_currentlabels_dupes1` | 46 | 24.9s |  |
| 592 | `movieclip_currentlabels_dupes2` | 30 | 6.6s |  |
| 593 | `movieclip_currentlabels_dupes3` | 67 | 6.5s |  |
| 594 | `movieclip_currentscene` | 12 | 6.6s |  |
| 595 | `movieclip_dispatchevent` | 430 | 6.8s |  |
| 596 | `movieclip_dispatchevent_cancel` | 102 | 6.8s |  |
| 597 | `movieclip_dispatchevent_handlerorder` | 251 | 6.7s |  |
| 598 | `movieclip_dispatchevent_selfadd` | 80 | 6.6s |  |
| 599 | `movieclip_dispatchevent_target` | 899 | 6.7s |  |
| 600 | `movieclip_displayevents` | 96 | 25.2s |  |
| 601 | `movieclip_displayevents_clickgoto` | 676 | 7.0s |  |
| 602 | `movieclip_displayevents_clickgoto2` | 2001 | 7.2s |  |
| 603 | `movieclip_displayevents_clickplay` | 575 | 7.0s |  |
| 604 | `movieclip_displayevents_clicksymbol` | 562 | 7.0s |  |
| 605 | `movieclip_displayevents_constructframegoto` | 140 | 7.1s |  |
| 606 | `movieclip_displayevents_constructframeplay` | 50 | 6.9s |  |
| 607 | `movieclip_displayevents_constructframesymbol` | 144 | 6.9s |  |
| 608 | `movieclip_displayevents_dblhandler` | 21 | 6.9s |  |
| 609 | `movieclip_displayevents_enterframegoto` | 149 | 7.0s |  |
| 610 | `movieclip_displayevents_enterframeplay` | 48 | 6.8s |  |
| 611 | `movieclip_displayevents_enterframesymbol` | 149 | 25.6s |  |
| 612 | `movieclip_displayevents_exitframegoto` | 106 | 6.8s |  |
| 613 | `movieclip_displayevents_exitframeplay` | 44 | 6.8s |  |
| 614 | `movieclip_displayevents_exitframesymbol` | 135 | 6.8s |  |
| 615 | `movieclip_displayevents_looping` | 63 | 25.7s |  |
| 616 | `movieclip_displayevents_stopped` | 113 | 7.2s |  |
| 617 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 618 | `movieclip_displayevents_timeline` | 128 | 25.8s |  |
| 619 | `movieclip_drawrect` | 54 | 6.6s |  |
| 620 | `movieclip_frameconstruct_skipped` | 9 | 6.7s |  |
| 621 | `movieclip_goto_during_frame_script` | 15 | 6.8s |  |
| 622 | `movieclip_goto_overwrite` | 14 | 25.4s |  |
| 623 | `movieclip_goto_scene_last_frame_int` | 1 | 25.3s |  |
| 624 | `movieclip_goto_scene_last_frame_label` | 1 | 2.6s |  |
| 625 | `movieclip_gotoandplay` | 15 | 25.3s |  |
| 626 | `movieclip_gotoandstop` | 13 | 25.1s |  |
| 627 | `movieclip_gotoandstop_children` | 4 | 6.7s |  |
| 628 | `movieclip_gotoandstop_framescripts1` | 4 | 6.7s |  |
| 629 | `movieclip_gotoandstop_framescripts2` | 4 | 2.7s |  |
| 630 | `movieclip_gotoandstop_framescripts_self` | 7 | 26.1s |  |
| 631 | `movieclip_gotoandstop_queueing` | 12 | 26.2s |  |
| 632 | `movieclip_hittest` | 67 | 7.4s |  |
| 633 | `movieclip_next_frame` | 2 | 7.2s |  |
| 634 | `movieclip_next_scene` | 6 | 25.9s |  |
| 635 | `movieclip_play` | 3 | 3.0s |  |
| 636 | `movieclip_prev_frame` | 3 | 7.1s |  |
| 637 | `movieclip_prev_scene` | 7 | 7.2s |  |
| 638 | `movieclip_properties` | 79 | 7.4s |  |
| 639 | `movieclip_queued_noop_goto_swf10` | 9 | 7.3s |  |
| 640 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 641 | `movieclip_scenes` | 11 | 7.2s |  |
| 642 | `movieclip_soundtransform` | 831 | 28.2s |  |
| 643 | `movieclip_stop` | 1 | 7.1s |  |
| 644 | `movieclip_super_is_symbol` | 20 | 7.7s |  |
| 645 | `movieclip_symbol_constr` | 8 | 7.4s |  |
| 646 | `movieclip_text_mousedown` | 1 | 7.3s |  |
| 647 | `movieclip_willtrigger` | 5 | 7.3s |  |
| 648 | `multiply` | 1058 | 19.7s |  |
| 649 | `namespace_constr` | 253 | 7.5s |  |
| 650 | `namespace_constr_args` | 1 | 7.1s |  |
| 651 | `namespace_enumeration_order` | 7 | 7.2s |  |
| 652 | `nan_scale` | 9 | 7.1s |  |
| 653 | `navigateToURL_target_normalize` | 107 | 27.8s |  |
| 654 | `negate` | 30 | 7.1s |  |
| 655 | `negative_volume_panned` | 0 | 7.5s |  |
| 656 | `nested_iteration` | 11 | 7.3s |  |
| 657 | `net_getClassByAlias` | 3 | 7.2s |  |
| 658 | `net_navigateToURL` | 57 | 7.2s |  |
| 659 | `net_stream_play_options` | 6 | 7.2s |  |
| 660 | `netconnection_close` | 55 | 7.3s |  |
| 661 | `netconnection_properties` | 78 | 7.4s |  |
| 662 | `netconnection_send_remote` | 50 | 7.5s |  |
| 663 | `netconnection_serialize_arrays` | 6 | 7.4s |  |
| 664 | `netstream_client` | 10 | 7.3s |  |
| 665 | `netstream_connect` | 7 | 7.4s |  |
| 666 | `newactivation_in_script_init` | 3 | 7.2s |  |
| 667 | `newclass_twice` | 3 | 7.4s |  |
| 668 | `nonconflicting_declarations` | 0 | 7.6s |  |
| 669 | `null_void_types` | 8 | 7.5s |  |
| 670 | `number_autoconv` | 21 | 3.4s |  |
| 671 | `number_autoconv_amf` | 132 | 7.6s |  |
| 672 | `number_autoconv_array_sort_32bit` | 1 | 7.3s |  |
| 673 | `number_constr` | 58 | 7.6s |  |
| 674 | `number_toexponential` | 378 | 7.6s |  |
| 675 | `number_toexponential2` | 35 | 7.6s |  |
| 676 | `number_tofixed` | 378 | 7.6s |  |
| 677 | `number_toprecision` | 350 | 7.7s |  |
| 678 | `obfuscated_class_names` | 3 | 7.7s |  |
| 679 | `object_enumeration` | 10 | 7.6s |  |
| 680 | `object_prototype` | 4 | 7.8s |  |
| 681 | `object_to_locale_string` | 2 | 7.6s |  |
| 682 | `object_to_string` | 2 | 7.5s |  |
| 683 | `object_value_of` | 2 | 3.2s |  |
| 684 | `op_coerce` | 54 | 3.4s |  |
| 685 | `op_coerce_x` | 54 | 7.5s |  |
| 686 | `op_escxattr` | 2 | 7.7s |  |
| 687 | `op_escxelem` | 2 | 7.7s |  |
| 688 | `op_lookupswitch` | 4 | 7.7s |  |
| 689 | `optimize_coerce` | 1 | 7.4s |  |
| 690 | `orphan_movie_complex` | 80 | 7.8s |  |
| 691 | `orphan_movie_reorder` | 111 | 28.1s |  |
| 692 | `package_namespace` | 7 | 7.6s |  |
| 693 | `param_default_value_has_zero_cpool_index` | 1 | 7.6s |  |
| 694 | `parent_early_access_child` | 16 | 7.8s |  |
| 695 | `parse_float` | 81 | 7.9s |  |
| 696 | `parse_int` | 135 | 8.1s |  |
| 697 | `perspective_projection_basic` | 40 | 7.6s |  |
| 698 | `pixelbender_ceil` | 77 | 7.8s |  |
| 699 | `pixelbender_conditional` | 138 | 7.9s |  |
| 700 | `pixelbender_conversions` | 270 | 7.9s |  |
| 701 | `pixelbender_dithering` | 8 | 34.1s |  |
| 702 | `pixelbender_div` | 36 | 7.7s |  |
| 703 | `pixelbender_effect_BlurredFocus` | 0 | 34.7s |  |
| 704 | `pixelbender_effect_glassDisplace` | 0 | 13.6s |  |
| 705 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 32.2s |  |
| 706 | `pixelbender_effect_smudge` | 0 | 11.4s |  |
| 707 | `pixelbender_effect_tintype` | 0 | 10.5s |  |
| 708 | `pixelbender_effect_twirl` | 0 | 11.5s |  |
| 709 | `pixelbender_eof` | 7 | 7.5s |  |
| 710 | `pixelbender_images` | 0 | 10.1s |  |
| 711 | `pixelbender_input` | 103 | 27.9s |  |
| 712 | `pixelbender_logicalnot` | 20 | 7.5s |  |
| 713 | `pixelbender_malformed_data` | 190 | 28.1s |  |
| 714 | `pixelbender_multiple_out_params` | 1 | 3.3s |  |
| 715 | `pixelbender_no_out_param` | 6 | 7.7s |  |
| 716 | `pixelbender_outputs` | 13 | 7.9s |  |
| 717 | `pixelbender_padding_bytes` | 22 | 7.8s |  |
| 718 | `pixelbender_param_qualifier` | 512 | 7.8s |  |
| 719 | `pixelbender_parameters` | 1563 | 8.1s |  |
| 720 | `pixelbender_parameters_bool` | 240 | 8.0s |  |
| 721 | `pixelbender_parameters_int_vs_bool` | 54 | 7.9s |  |
| 722 | `pixelbender_parse_errors` | 6 | 7.8s |  |
| 723 | `pixelbender_rsqrt` | 24 | 7.8s |  |
| 724 | `pixelbender_select_kinds` | 8 | 7.8s |  |
| 725 | `pixelbender_shaderdata` | 49 | 7.6s |  |
| 726 | `pixelbender_shaderdata_setter` | 99 | 8.2s |  |
| 727 | `pixelbender_sign` | 60 | 7.9s |  |
| 728 | `pixelbender_vector_output` | 11 | 7.9s |  |
| 729 | `place_and_lookup/swf10` | 33 | 3.4s |  |
| 730 | `place_and_lookup/swf9` | 33 | 1.4s |  |
| 731 | `place_multiple` | 17 | 28.3s |  |
| 732 | `place_object_replace` | 9 | 7.8s |  |
| 733 | `place_object_replace_2` | 24 | 7.7s |  |
| 734 | `place_object_same_depth_frame` | 1 | 7.7s |  |
| 735 | `point` | 132 | 8.1s |  |
| 736 | `primitive_edge_cases` | 1 | 7.6s |  |
| 737 | `print_job_options` | 3 | 7.6s |  |
| 738 | `property_priority` | 22 | 7.5s |  |
| 739 | `property_priority_three_level` | 6 | 25.5s |  |
| 740 | `propertyisenumerable_namespaces` | 6 | 7.1s |  |
| 741 | `prototype_set_null` | 7 | 7.0s |  |
| 742 | `proxy_callproperty` | 24 | 7.1s |  |
| 743 | `proxy_deleteproperty` | 64 | 7.2s |  |
| 744 | `proxy_enumeration` | 34 | 7.1s |  |
| 745 | `proxy_getproperty` | 77 | 7.2s |  |
| 746 | `proxy_hasownproperty` | 8 | 7.0s |  |
| 747 | `proxy_hasproperty` | 32 | 7.2s |  |
| 748 | `proxy_serialize` | 9 | 7.1s |  |
| 749 | `proxy_setproperty` | 42 | 7.1s |  |
| 750 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.0s |  |
| 751 | `qname_constr` | 32 | 7.1s |  |
| 752 | `qname_constr_namespace` | 24 | 7.1s |  |
| 753 | `qname_enumeration` | 9 | 7.1s |  |
| 754 | `qname_indexing` | 23 | 7.1s |  |
| 755 | `qname_tostring` | 25 | 7.1s |  |
| 756 | `qname_valueof` | 29 | 7.1s |  |
| 757 | `rectangle` | 1094 | 7.8s |  |
| 758 | `regexp_constr` | 148 | 7.3s |  |
| 759 | `regexp_exec` | 19 | 7.1s |  |
| 760 | `regexp_extended` | 47 | 7.0s |  |
| 761 | `regexp_multiargs` | 1 | 7.0s |  |
| 762 | `regexp_test` | 27 | 3.1s |  |
| 763 | `regexp_toString` | 10 | 7.2s |  |
| 764 | `register_script_refresh` | 35 | 7.5s |  |
| 765 | `remove_child_clear_field` | 88 | 7.4s |  |
| 766 | `remove_dobj` | 3 | 7.0s |  |
| 767 | `resolve_order` | 4 | 7.0s |  |
| 768 | `responder_null_callbacks` | 1 | 7.0s |  |
| 769 | `rng` | 1 | 8.2s |  |
| 770 | `rootless` | 42 | 7.2s |  |
| 771 | `rshift` | 1058 | 19.1s |  |
| 772 | `sandbox_type_inherited` | 2 | 7.5s |  |
| 773 | `sandbox_type_local_file` | 1 | 7.2s |  |
| 774 | `sandbox_type_local_network` | 1 | 7.0s |  |
| 775 | `scene_constr` | 8 | 7.1s |  |
| 776 | `security_domain_current` | 2 | 3.2s |  |
| 777 | `selection` | 239 | 7.7s |  |
| 778 | `set_local_0` | 31 | 7.3s |  |
| 779 | `set_property_is_enumerable` | 85 | 7.7s |  |
| 780 | `shaderparameter_value` | 4 | 7.2s |  |
| 781 | `shape_drawrect` | 54 | 7.2s |  |
| 782 | `shared_object_no_root` | 3 | 7.1s |  |
| 783 | `simplebutton_added_to_stage` | 45 | 26.8s |  |
| 784 | `simplebutton_childevents` | 86 | 26.4s |  |
| 785 | `simplebutton_childevents_nested` | 54 | 7.6s |  |
| 786 | `simplebutton_childevents_sprite` | 13 | 7.3s |  |
| 787 | `simplebutton_childprops` | 144 | 7.4s |  |
| 788 | `simplebutton_childshuffle` | 23 | 7.1s |  |
| 789 | `simplebutton_constr` | 36 | 7.5s |  |
| 790 | `simplebutton_constr_childevents` | 48 | 7.6s |  |
| 791 | `simplebutton_constr_params` | 42 | 7.4s |  |
| 792 | `simplebutton_mouseenabled` | 26 | 7.1s |  |
| 793 | `simplebutton_multi_children` | 19 | 7.4s |  |
| 794 | `simplebutton_structure` | 27 | 7.5s |  |
| 795 | `simplebutton_symbolclass` | 68 | 7.5s |  |
| 796 | `slot_disp_id_shared_numbering` | 1 | 25.6s |  |
| 797 | `slots_force_autoassigned` | 1 | 7.2s |  |
| 798 | `socket_after_disconnect` | 1 | 7.3s |  |
| 799 | `socket_close` | 2 | 7.1s |  |
| 800 | `socket_connect` | 4 | 7.2s |  |
| 801 | `socket_errors` | 56 | 7.7s |  |
| 802 | `socket_read_big` | 48 | 7.3s |  |
| 803 | `socket_read_little` | 48 | 7.2s |  |
| 804 | `socket_read_write_object` | 8 | 6.9s |  |
| 805 | `socket_write_big` | 15 | 7.5s |  |
| 806 | `socket_write_little` | 14 | 6.8s |  |
| 807 | `sound_embeddedprops` | 26 | 7.0s |  |
| 808 | `sound_play` | 19 | 7.1s |  |
| 809 | `sound_valueof` | 33 | 6.9s |  |
| 810 | `soundchannel_soundtransform` | 835 | 27.9s |  |
| 811 | `soundchannel_soundtransform_exists` | 5 | 25.9s |  |
| 812 | `soundchannel_stop` | 8 | 7.0s |  |
| 813 | `soundmixer_buffertime` | 5 | 6.8s |  |
| 814 | `soundmixer_stopall` | 6 | 6.9s |  |
| 815 | `soundtransform` | 442 | 7.0s |  |
| 816 | `space_justifier_clone` | 12 | 2.7s |  |
| 817 | `sprite_with_frames` | 0 | 26.2s |  |
| 818 | `stage3d_agal_cross_product` | 0 | 9.2s |  |
| 819 | `stage3d_agal_upload_errors` | 66 | 9.2s |  |
| 820 | `stage3d_bitmap` | 0 | 30.5s |  |
| 821 | `stage3d_blend` | 81 | 29.5s |  |
| 822 | `stage3d_context3d_string_args` | 158 | 7.8s |  |
| 823 | `stage3d_errors` | 7 | 6.9s |  |
| 824 | `stage3d_errors_atf` | 3 | 8.1s |  |
| 825 | `stage3d_errors_swf_29` | 6 | 7.0s |  |
| 826 | `stage3d_float1_index` | 0 | 27.9s |  |
| 827 | `stage3d_fractal` | 0 | 28.5s |  |
| 828 | `stage3d_ignore_sampler_override` | 0 | 28.6s |  |
| 829 | `stage3d_multistage_triangle` | 3 | 9.5s |  |
| 830 | `stage3d_program_constants_bytearray_be` | 0 | 29.8s |  |
| 831 | `stage3d_program_constants_bytearray_le` | 0 | 10.0s |  |
| 832 | `stage3d_program_constants_invalid_input` | 21 | 7.8s |  |
| 833 | `stage3d_raytrace` | 0 | 33.1s |  |
| 834 | `stage3d_rotating_cube` | 0 | 10.2s |  |
| 835 | `stage3d_sampler` | 0 | 9.4s |  |
| 836 | `stage3d_sampler_partial_upload` | 0 | 9.5s |  |
| 837 | `stage3d_stencil` | 0 | 29.1s |  |
| 838 | `stage3d_texture` | 0 | 14.7s |  |
| 839 | `stage3d_texture_bytearray` | 0 | 10.7s |  |
| 840 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.0s |  |
| 841 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.3s |  |
| 842 | `stage3d_triangle` | 0 | 9.5s |  |
| 843 | `stage3d_triangle_bytes4` | 0 | 9.5s |  |
| 844 | `stage3d_triangle_float1` | 0 | 9.3s |  |
| 845 | `stage3d_triangle_index_upload` | 0 | 9.4s |  |
| 846 | `stage3d_x_y` | 22 | 6.8s |  |
| 847 | `stage_access` | 10 | 2.8s |  |
| 848 | `stage_displayobject_properties` | 24 | 6.7s |  |
| 849 | `stage_framerate_nan` | 7 | 2.9s |  |
| 850 | `stage_framerate_negative` | 6 | 6.7s |  |
| 851 | `stage_framerate_zero` | 6 | 6.7s |  |
| 852 | `stage_invalidate` | 38 | 6.9s |  |
| 853 | `stage_loaderinfo_properties` | 24 | 7.0s |  |
| 854 | `stage_mousechildren` | 2 | 6.7s |  |
| 855 | `stage_mouseenabled` | 15 | 6.6s |  |
| 856 | `stage_overriden_setters` | 31 | 6.8s |  |
| 857 | `stage_properties` | 30 | 6.7s |  |
| 858 | `stage_stage3Ds_vector` | 1 | 25.2s |  |
| 859 | `static_text` | 3 | 6.9s |  |
| 860 | `static_var_with_this_in_ctor` | 2 | 6.7s |  |
| 861 | `stored_properties` | 11 | 6.8s |  |
| 862 | `strict_equality` | 34 | 6.8s |  |
| 863 | `string_call` | 13 | 6.7s |  |
| 864 | `string_case` | 23 | 6.7s |  |
| 865 | `string_char_at` | 27 | 6.8s |  |
| 866 | `string_char_code_at` | 28 | 6.6s |  |
| 867 | `string_concat_fromcharcode` | 37 | 6.8s |  |
| 868 | `string_constr` | 25 | 6.8s |  |
| 869 | `string_indexof_lastindexof` | 87 | 7.0s |  |
| 870 | `string_length` | 16 | 5.9s |  |
| 871 | `string_locale_compare` | 39 | 6.2s |  |
| 872 | `string_match` | 51 | 6.1s |  |
| 873 | `string_relational_compare` | 4 | 6.0s |  |
| 874 | `string_replace` | 51 | 6.1s |  |
| 875 | `string_search` | 41 | 6.1s |  |
| 876 | `string_slice_substr_substring` | 170 | 7.2s |  |
| 877 | `string_split` | 29 | 6.0s |  |
| 878 | `string_substr_negative` | 21 | 6.0s |  |
| 879 | `string_substr_weird` | 182 | 5.9s |  |
| 880 | `subtract` | 1058 | 14.6s |  |
| 881 | `super_get_call` | 12 | 6.0s |  |
| 882 | `supercall_two_classobjects` | 2 | 6.0s |  |
| 883 | `swf8` | 1 | 5.9s |  |
| 884 | `swf_10_queued_goto_scripts_construct` | 52 | 6.2s |  |
| 885 | `swf_9_goto_in_enter_frame` | 17 | 6.0s |  |
| 886 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.1s |  |
| 887 | `swf_9_queued_goto_scripts` | 6 | 6.4s |  |
| 888 | `swf_9_queued_goto_scripts_construct` | 28 | 1.0s |  |
| 889 | `swf_9_versioning` | 2 | 6.0s |  |
| 890 | `swf_wrong_frame_count` | 38 | 6.2s |  |
| 891 | `swf_wrong_frame_count_isplaying` | 22 | 22.8s |  |
| 892 | `symbol_class_binary_data` | 8 | 5.9s |  |
| 893 | `symbol_class_conflict` | 4 | 6.4s |  |
| 894 | `symbol_class_root_not_zero` | 1 | 5.8s |  |
| 895 | `symbolclass_invalid_utf8` | 2 | 6.0s |  |
| 896 | `tab_ordering_arrows` | 998 | 23.6s |  |
| 897 | `tab_ordering_automatic_advanced` | 184 | 27.4s |  |
| 898 | `tab_ordering_automatic_basic` | 45 | 7.3s |  |
| 899 | `tab_ordering_children` | 116 | 7.4s |  |
| 900 | `tab_ordering_custom_basic` | 34 | 7.2s |  |
| 901 | `tab_ordering_stage_tab_children` | 32 | 7.3s |  |
| 902 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.2s |  |
| 903 | `tab_ordering_tabbable` | 47 | 7.3s |  |
| 904 | `tabstop_properties` | 105 | 7.5s |  |
| 905 | `text_element_basic` | 34 | 7.4s |  |
| 906 | `text_engine_fontdescription` | 27 | 7.3s |  |
| 907 | `text_engine_groupelement` | 64 | 8.2s |  |
| 908 | `text_run` | 7 | 7.1s |  |
| 909 | `textblock_createline_errors` | 23 | 7.5s |  |
| 910 | `textblock_createline_fte` | 9 | 26.8s |  |
| 911 | `textblock_properties` | 118 | 7.7s |  |
| 912 | `textbox_click` | 37 | 26.5s |  |
| 913 | `textfield_event` | 66 | 7.5s |  |
| 914 | `textfield_focusin_event` | 9 | 7.2s |  |
| 915 | `textfield_input_dead_keys_windows` | 15 | 7.2s |  |
| 916 | `textfield_unload` | 39 | 26.2s |  |
| 917 | `textformat` | 1134 | 7.2s |  |
| 918 | `textformat_display` | 14 | 7.3s |  |
| 919 | `textformat_font_max_length` | 4 | 3.1s |  |
| 920 | `textline_inapplicable_properties` | 10 | 7.2s |  |
| 921 | `textline_name` | 1 | 7.1s |  |
| 922 | `textline_splitting_basic` | 76 | 7.4s |  |
| 923 | `textline_throwerror` | 30 | 7.2s |  |
| 924 | `textline_validity` | 162 | 7.3s |  |
| 925 | `throw` | 3 | 7.0s |  |
| 926 | `timeline_scripts` | 3 | 7.2s |  |
| 927 | `timer` | 90 | 8.2s |  |
| 928 | `timer_events` | 3 | 7.4s |  |
| 929 | `timer_finished` | 11 | 3.3s |  |
| 930 | `timer_reset` | 8 | 7.5s |  |
| 931 | `timer_setdelay` | 5 | 7.4s |  |
| 932 | `trace` | 12 | 7.1s |  |
| 933 | `truthiness` | 30 | 6.2s |  |
| 934 | `try_catch` | 11 | 0.9s |  |
| 935 | `try_catch_typed` | 12 | 0.8s |  |
| 936 | `typeof` | 30 | 0.9s |  |
| 937 | `uint_constr` | 92 | 0.9s |  |
| 938 | `uint_tofixed` | 1215 | 0.8s |  |
| 939 | `uint_tostring` | 3375 | 0.9s |  |
| 940 | `unchecked_function` | 15 | 0.8s |  |
| 941 | `unescape` | 28 | 0.9s |  |
| 942 | `url_loader` | 25 | 0.9s |  |
| 943 | `urlrequest` | 18 | 1.8s |  |
| 944 | `urlstream_basic` | 5 | 0.8s |  |
| 945 | `urshift` | 1058 | 0.8s |  |
| 946 | `utils3d` | 7 | 0.8s |  |
| 947 | `vector3d` | 397 | 0.8s |  |
| 948 | `vector_class` | 36 | 0.8s |  |
| 949 | `vector_class_call` | 11 | 0.8s |  |
| 950 | `vector_coercion` | 66 | 0.8s |  |
| 951 | `vector_concat` | 90 | 0.8s |  |
| 952 | `vector_constr` | 107 | 0.8s |  |
| 953 | `vector_enumeration` | 5 | 0.8s |  |
| 954 | `vector_every` | 92 | 0.8s |  |
| 955 | `vector_filter` | 95 | 0.8s |  |
| 956 | `vector_holes` | 24 | 0.8s |  |
| 957 | `vector_indexof` | 302 | 0.8s |  |
| 958 | `vector_insertat` | 270 | 0.8s |  |
| 959 | `vector_int_access` | 4 | 0.8s |  |
| 960 | `vector_int_delete` | 11 | 0.9s |  |
| 961 | `vector_join` | 58 | 0.8s |  |
| 962 | `vector_lastindexof` | 302 | 0.8s |  |
| 963 | `vector_legacy` | 10 | 0.9s |  |
| 964 | `vector_map` | 85 | 0.8s |  |
| 965 | `vector_object_final` | 1 | 0.9s |  |
| 966 | `vector_object_toString` | 10 | 0.8s |  |
| 967 | `vector_pushpop` | 255 | 0.8s |  |
| 968 | `vector_reborrow_bug` | 10 | 0.8s |  |
| 969 | `vector_removeat` | 172 | 8.3s |  |
| 970 | `vector_reverse` | 232 | 8.3s |  |
| 971 | `vector_shiftunshift` | 252 | 7.1s |  |
| 972 | `vector_slice` | 331 | 8.9s |  |
| 973 | `vector_sort` | 905 | 16.7s |  |
| 974 | `vector_splice` | 693 | 11.2s |  |
| 975 | `vector_splice_fixed_bug_compat` | 4 | 7.2s |  |
| 976 | `vector_tostring` | 79 | 7.8s |  |
| 977 | `verification` | 8 | 7.3s |  |
| 978 | `verify_abnormal_loop` | 1 | 7.0s |  |
| 979 | `verify_dxns_without_flag` | 3 | 7.5s |  |
| 980 | `verify_exception_targets_edge_case` | 1 | 7.1s |  |
| 981 | `verify_jump_to_middle_of_op` | 1 | 7.1s |  |
| 982 | `verify_lookup_switch_edge_case` | 1 | 7.0s |  |
| 983 | `verify_stack` | 5 | 7.2s |  |
| 984 | `verify_unreachable_exception` | 2 | 7.0s |  |
| 985 | `versioned_isplaying` | 2 | 7.1s |  |
| 986 | `virtual_properties` | 16 | 7.2s |  |
| 987 | `with` | 4 | 7.1s |  |
| 988 | `wrong_arg_count` | 7 | 7.3s |  |
| 989 | `xml_abstract_equality` | 36 | 7.3s |  |
| 990 | `xml_advanced` | 52 | 7.2s |  |
| 991 | `xml_appendchild` | 10 | 7.2s |  |
| 992 | `xml_as_attribute` | 9 | 7.1s |  |
| 993 | `xml_attribute` | 35 | 7.2s |  |
| 994 | `xml_attribute_name` | 40 | 7.2s |  |
| 995 | `xml_basic` | 33 | 7.2s |  |
| 996 | `xml_child` | 25 | 7.2s |  |
| 997 | `xml_childindex` | 7 | 7.1s |  |
| 998 | `xml_children` | 43 | 7.7s |  |
| 999 | `xml_class_call` | 9 | 7.1s |  |
| 1000 | `xml_contains` | 197 | 7.3s |  |
| 1001 | `xml_copy` | 20 | 3.1s |  |
| 1002 | `xml_ctor_from_tostring` | 23 | 7.3s |  |
| 1003 | `xml_delete` | 114 | 7.1s |  |
| 1004 | `xml_descendants` | 83 | 7.1s |  |
| 1005 | `xml_elements` | 6 | 7.0s |  |
| 1006 | `xml_equals_namespace_check` | 2 | 6.9s |  |
| 1007 | `xml_explicit_use_namespace` | 5 | 7.2s |  |
| 1008 | `xml_getdescendants_qname` | 21 | 7.1s |  |
| 1009 | `xml_has_property_via_in` | 26 | 7.1s |  |
| 1010 | `xml_hasownproperty` | 6 | 7.0s |  |
| 1011 | `xml_ignore_white` | 6 | 7.0s |  |
| 1012 | `xml_length` | 2 | 7.0s |  |
| 1013 | `xml_list_as_attribute` | 9 | 7.0s |  |
| 1014 | `xml_list_concat` | 20 | 7.0s |  |
| 1015 | `xml_list_enumerate` | 4 | 6.9s |  |
| 1016 | `xml_methods_settings` | 3 | 7.0s |  |
| 1017 | `xml_mismatched_tag` | 37 | 7.1s |  |
| 1018 | `xml_namespace` | 39 | 3.0s |  |
| 1019 | `xml_namespace_methods` | 245 | 7.1s |  |
| 1020 | `xml_namespaced_property` | 7 | 7.1s |  |
| 1021 | `xml_no_namespace` | 1 | 7.0s |  |
| 1022 | `xml_nodekind` | 3 | 7.0s |  |
| 1023 | `xml_normalize` | 35 | 7.1s |  |
| 1024 | `xml_notification_bubbling` | 361 | 7.0s |  |
| 1025 | `xml_parent` | 8 | 7.0s |  |
| 1026 | `xml_set_children` | 17 | 7.1s |  |
| 1027 | `xml_set_name` | 34 | 7.0s |  |
| 1028 | `xml_settings` | 6 | 3.0s |  |
| 1029 | `xml_simple_complex_content` | 47 | 7.0s |  |
| 1030 | `xml_socket` | 11 | 7.2s |  |
| 1031 | `xml_text` | 7 | 7.0s |  |
| 1032 | `xml_tostring` | 6 | 7.0s |  |
| 1033 | `xml_tostring_namespace` | 12 | 7.0s |  |
| 1034 | `xml_unescaping` | 23 | 7.0s |  |
| 1035 | `xml_weird_ignores` | 54 | 7.1s |  |
| 1036 | `xml_wildcard` | 11 | 7.0s |  |
| 1037 | `xmldocument` | 254 | 7.1s |  |
| 1038 | `xmlnode` | 3540 | 7.2s |  |
| 1039 | `zero_frame_clip` | 3 | 7.5s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 7.0s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 7.3s |  |
| 3 | `blend_transform` | 1 | 1 | 7.9s |  |
| 4 | `coerce_property` | 3 | 3 | 6.9s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 2.8s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 7.5s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.4s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 26.2s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 7.2s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.1s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 7.1s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 7.3s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 25.7s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 26.6s |  |
| 15 | `int_toexponential` | 76 | 76 | 7.0s |  |
| 16 | `int_toprecision` | 441 | 441 | 7.0s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.5s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 7.0s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 25.4s |  |
| 20 | `soundchannel_position` | 74 | 74 | 27.0s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 7.1s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.8s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 23.1s |  |
| 24 | `uint_toexponential` | 100 | 100 | 0.8s |  |
| 25 | `uint_toprecision` | 433 | 433 | 0.9s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 25.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**50 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 5 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 6 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 7 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 8 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 9 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 10 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 11 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 12 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 13 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 14 | `flash_media_video_setter` | 90.0% | 36 | 40 | 4 |  |
| 15 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 16 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 17 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 18 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 19 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 20 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 21 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 22 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 23 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 24 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 25 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 26 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 27 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 28 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 29 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 30 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 31 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 32 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 33 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 34 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 35 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 36 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 37 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 38 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 39 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 40 | `displayobject_scrollrect` | 57.6% | 19 | 33 | 14 |  |
| 41 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 42 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 43 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 44 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 45 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 46 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 47 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 48 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 49 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 50 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 18.8s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.0s |  |
| 3 | `verify_typecheck` | exit code 1 | 3.0s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**154 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 5 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 6 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 7 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 8 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 9 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 10 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 11 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 12 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 13 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 14 | `flash_media_video_setter` | 90.0% | 36/40 | 40 | 40 |  |
| 15 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 16 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 17 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 18 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 19 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 20 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 21 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 22 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 23 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 24 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 25 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 26 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 27 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 28 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 29 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 30 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 31 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 32 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 33 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 34 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 35 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 36 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 37 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 38 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 39 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 40 | `displayobject_scrollrect` | 57.6% | 19/33 | 33 | 33 |  |
| 41 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 42 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 43 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 44 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 45 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 46 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 47 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 48 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 49 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 50 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 51 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 52 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 53 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 54 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 55 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 56 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 57 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 58 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 59 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 60 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 61 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 62 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 63 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 64 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 65 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 66 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 67 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 68 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 69 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 70 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 71 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 72 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 73 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 74 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 75 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 76 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 77 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 78 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 79 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 80 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 81 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 82 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 83 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 84 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 85 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 86 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 87 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 88 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 89 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 90 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 91 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 92 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 93 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 94 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 95 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 96 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 97 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 98 | `all_classes/events/swf9` | 0.1% | 1/1030 | 184 | 1030 |  |
| 99 | `all_classes/events/swf30` | 0.1% | 2/2353 | 184 | 2353 |  |
| 100 | `all_classes/events/swf10` | 0.1% | 1/1638 | 184 | 1638 |  |
| 101 | `all_classes/events/swf11` | 0.1% | 1/1750 | 184 | 1750 |  |
| 102 | `all_classes/events/swf12` | 0.1% | 1/1814 | 184 | 1814 |  |
| 103 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 104 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 105 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 106 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 107 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 108 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 109 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 110 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 111 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 112 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 113 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 114 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 115 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 116 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 117 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 118 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 119 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 120 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 121 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 122 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 123 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 124 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 125 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 126 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 127 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 128 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 129 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 130 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 131 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 132 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 133 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 134 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 135 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 136 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 137 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 138 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 139 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 140 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 141 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 142 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 143 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 144 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 145 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 146 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 147 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 148 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 149 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 150 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 151 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 152 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 153 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 154 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
