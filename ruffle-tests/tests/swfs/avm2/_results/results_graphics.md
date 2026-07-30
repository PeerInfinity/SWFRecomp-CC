# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 17:36 UTC

**Git SHA**: `1ca0ab117c`

**Run Duration**: 197m 7s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1222 |
| Passing | **997** (81.6%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1023** (83.7%) |
| Failing | 199 |
| Total expected lines | 151259 |
| Matching lines | 115508 (76.4%) |
| Mismatched lines | 35751 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 196 | 98.5% |
| Runtime Error | 3 | 1.5% |

## Passing Tests

**997 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 15.0s |  |
| 2 | `agal_compiler` | 13 | 7.5s |  |
| 3 | `air_datagram_socket` | 1 | 6.8s |  |
| 4 | `air_hidden_lookup` | 2 | 5.7s |  |
| 5 | `all_classes/security/swf11` | 3 | 5.5s |  |
| 6 | `amf_array_serialization` | 17 | 7.0s |  |
| 7 | `amf_custom_obj` | 26 | 5.8s |  |
| 8 | `amf_dictionary` | 9 | 5.5s |  |
| 9 | `amf_function` | 46 | 5.6s |  |
| 10 | `amf_invalid_date` | 2 | 5.5s |  |
| 11 | `amf_missing_prop` | 6 | 5.5s |  |
| 12 | `amf_nondynamic_function_prop` | 6 | 7.0s |  |
| 13 | `amf_setter_error` | 8 | 7.0s |  |
| 14 | `amf_vector` | 40 | 7.4s |  |
| 15 | `amf_xml` | 6 | 6.9s |  |
| 16 | `application_domain` | 4 | 7.1s |  |
| 17 | `array_access` | 18 | 7.1s |  |
| 18 | `array_access_interpreter` | 4 | 7.0s |  |
| 19 | `array_access_no_pubns` | 2 | 7.0s |  |
| 20 | `array_concat` | 41 | 7.2s |  |
| 21 | `array_constr` | 10 | 6.9s |  |
| 22 | `array_delete` | 44 | 7.2s |  |
| 23 | `array_enumeration` | 10 | 7.2s |  |
| 24 | `array_enumeration_elements` | 11 | 7.1s |  |
| 25 | `array_every` | 8 | 7.2s |  |
| 26 | `array_filter` | 6 | 7.2s |  |
| 27 | `array_foreach` | 18 | 7.2s |  |
| 28 | `array_hasownproperty` | 11 | 3.2s |  |
| 29 | `array_holes` | 9 | 7.2s |  |
| 30 | `array_index_max` | 84 | 7.0s |  |
| 31 | `array_indexof` | 25 | 7.2s |  |
| 32 | `array_join` | 26 | 7.2s |  |
| 33 | `array_lastindexof` | 29 | 7.2s |  |
| 34 | `array_length` | 14 | 7.2s |  |
| 35 | `array_literal` | 3 | 7.1s |  |
| 36 | `array_map` | 8 | 7.0s |  |
| 37 | `array_pop` | 52 | 7.3s |  |
| 38 | `array_push` | 24 | 7.1s |  |
| 39 | `array_reborrow_bug` | 6 | 7.1s |  |
| 40 | `array_reverse` | 28 | 7.2s |  |
| 41 | `array_shift` | 51 | 3.3s |  |
| 42 | `array_slice` | 39 | 7.2s |  |
| 43 | `array_some` | 8 | 7.2s |  |
| 44 | `array_sort` | 297 | 7.7s |  |
| 45 | `array_sort_fun_swf12` | 2 | 7.2s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 47 | `array_sort_random` | 210 | 7.2s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 7.1s |  |
| 49 | `array_sorton` | 545 | 6.2s |  |
| 50 | `array_sparse_ops` | 41 | 5.7s |  |
| 51 | `array_splice` | 133 | 5.8s |  |
| 52 | `array_splice2` | 428 | 6.0s |  |
| 53 | `array_splice_types` | 48 | 5.8s |  |
| 54 | `array_storage` | 8 | 5.6s |  |
| 55 | `array_tolocalestring` | 9 | 5.8s |  |
| 56 | `array_tostring` | 12 | 5.6s |  |
| 57 | `array_unshift` | 24 | 5.8s |  |
| 58 | `array_valueof` | 9 | 5.6s |  |
| 59 | `array_vector_null_callback` | 10 | 5.7s |  |
| 60 | `astype` | 28 | 5.7s |  |
| 61 | `astypelate` | 24 | 5.7s |  |
| 62 | `astypelate_propagates` | 1 | 5.5s |  |
| 63 | `asymmetric_key_events` | 11 | 5.8s |  |
| 64 | `av_networking_params` | 9 | 5.8s |  |
| 65 | `avm2_catchup_dobj` | 158 | 6.5s |  |
| 66 | `bevel_filter` | 187 | 5.7s |  |
| 67 | `bitand` | 1058 | 14.6s |  |
| 68 | `bitmap_constr` | 17 | 5.8s |  |
| 69 | `bitmap_data` | 1000 | 11.8s |  |
| 70 | `bitmap_pixelsnapping` | 2 | 20.8s |  |
| 71 | `bitmap_properties` | 23 | 6.0s |  |
| 72 | `bitmap_subclass` | 7 | 7.0s |  |
| 73 | `bitmap_subclass_properties` | 9 | 6.2s |  |
| 74 | `bitmap_timeline` | 9 | 5.7s |  |
| 75 | `bitmapdata_accuracy` | 1 | 37.4s |  |
| 76 | `bitmapdata_applyfilter_blur` | 0 | 21.4s |  |
| 77 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.4s |  |
| 78 | `bitmapdata_applyfilter_destpoint` | 0 | 21.1s |  |
| 79 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 21.1s |  |
| 80 | `bitmapdata_clone` | 13 | 6.2s |  |
| 81 | `bitmapdata_colortransform` | 0 | 6.1s |  |
| 82 | `bitmapdata_colortransform_oob` | 2 | 5.6s |  |
| 83 | `bitmapdata_constr` | 22 | 5.8s |  |
| 84 | `bitmapdata_constructor_from_timeline` | 1 | 6.0s |  |
| 85 | `bitmapdata_copychannel` | 0 | 29.7s |  |
| 86 | `bitmapdata_copypixels` | 23 | 28.4s |  |
| 87 | `bitmapdata_copypixels_blend_over` | 1 | 7.2s |  |
| 88 | `bitmapdata_copypixelstobytearray` | 39 | 7.0s |  |
| 89 | `bitmapdata_dispose` | 7 | 7.3s |  |
| 90 | `bitmapdata_draw` | 0 | 27.1s |  |
| 91 | `bitmapdata_draw_colortransform` | 0 | 7.3s |  |
| 92 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.3s |  |
| 93 | `bitmapdata_draw_filters` | 0 | 26.1s |  |
| 94 | `bitmapdata_draw_masks` | 0 | 7.1s |  |
| 95 | `bitmapdata_draw_rotation` | 0 | 7.3s |  |
| 96 | `bitmapdata_draw_self_via_graphic` | 0 | 7.3s |  |
| 97 | `bitmapdata_draw_stage` | 0 | 26.1s |  |
| 98 | `bitmapdata_drawwithquality` | 0 | 7.5s |  |
| 99 | `bitmapdata_embedded` | 9 | 7.6s |  |
| 100 | `bitmapdata_fillrect` | 0 | 7.4s |  |
| 101 | `bitmapdata_filter_sourcerect` | 0 | 26.6s |  |
| 102 | `bitmapdata_floodfill` | 35 | 7.1s |  |
| 103 | `bitmapdata_getpixels` | 39 | 26.3s |  |
| 104 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 105 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 106 | `bitmapdata_hittest` | 112 | 7.7s |  |
| 107 | `bitmapdata_hittest_threshold` | 18 | 7.2s |  |
| 108 | `bitmapdata_opaque` | 0 | 7.3s |  |
| 109 | `bitmapdata_pixeldissolve` | 1037 | 7.7s |  |
| 110 | `bitmapdata_pixeldissolve_image` | 0 | 7.6s |  |
| 111 | `bitmapdata_rectangle_rounding` | 16 | 7.0s |  |
| 112 | `bitmapdata_setpixels` | 286 | 7.3s |  |
| 113 | `bitmapdata_setvector` | 26 | 7.1s |  |
| 114 | `bitmapdata_sync` | 0 | 26.4s |  |
| 115 | `bitmapdata_threshold` | 176 | 7.9s |  |
| 116 | `bitnot` | 46 | 7.0s |  |
| 117 | `bitor` | 1058 | 18.9s |  |
| 118 | `bitxor` | 1058 | 19.2s |  |
| 119 | `blend_multiply_alpha` | 0 | 7.3s |  |
| 120 | `blend_scroll` | 0 | 7.4s |  |
| 121 | `blend_shader_luma_lighten` | 3 | 7.8s |  |
| 122 | `blur_filter` | 43 | 7.3s |  |
| 123 | `boolean_constr` | 32 | 7.2s |  |
| 124 | `boolean_negation` | 30 | 7.2s |  |
| 125 | `boolean_tostring` | 8 | 7.1s |  |
| 126 | `broadcast_event` | 7 | 7.3s |  |
| 127 | `button_nested_frame` | 48 | 26.4s |  |
| 128 | `bytearray` | 48 | 7.4s |  |
| 129 | `bytearray_compress` | 31 | 7.2s |  |
| 130 | `bytearray_errors` | 24 | 7.3s |  |
| 131 | `bytearray_method_serialization` | 1 | 7.1s |  |
| 132 | `bytearray_oom` | 3 | 7.2s |  |
| 133 | `bytearray_readobject_amf0` | 50 | 7.2s |  |
| 134 | `bytearray_readobject_amf3` | 53 | 7.2s |  |
| 135 | `bytearray_readutf8bytes_with_bom` | 16 | 7.2s |  |
| 136 | `bytearray_serialization` | 3 | 7.2s |  |
| 137 | `bytearray_string_null` | 19 | 7.4s |  |
| 138 | `bytearray_tostring` | 15 | 7.2s |  |
| 139 | `bytearray_utf16` | 8 | 7.1s |  |
| 140 | `bytearray_writeobject` | 24 | 7.0s |  |
| 141 | `callee_in_initializer` | 6 | 7.1s |  |
| 142 | `callproplex_class` | 1 | 7.1s |  |
| 143 | `capabilities_resolution` | 8 | 26.7s |  |
| 144 | `catch_class` | 6 | 7.1s |  |
| 145 | `catch_scope_slot` | 7 | 3.3s |  |
| 146 | `checkfilter` | 4 | 3.2s |  |
| 147 | `class_call` | 32 | 7.3s |  |
| 148 | `class_cast_call` | 14 | 7.2s |  |
| 149 | `class_enumeration` | 4 | 7.1s |  |
| 150 | `class_has_own_property` | 2 | 7.1s |  |
| 151 | `class_init_interpreter_mode` | 1 | 7.0s |  |
| 152 | `class_is` | 32 | 7.2s |  |
| 153 | `class_methods` | 5 | 7.1s |  |
| 154 | `class_object_properties` | 10 | 7.2s |  |
| 155 | `class_singleton` | 18 | 7.2s |  |
| 156 | `class_supercalls_errors` | 35 | 7.3s |  |
| 157 | `class_supercalls_mismatched` | 26 | 7.2s |  |
| 158 | `class_superclass_wrong_order` | 1 | 25.9s |  |
| 159 | `class_to_locale_string` | 2 | 7.1s |  |
| 160 | `class_to_string` | 2 | 7.0s |  |
| 161 | `class_value_of` | 2 | 7.1s |  |
| 162 | `click_block` | 5 | 8.0s |  |
| 163 | `click_invisible` | 3 | 7.3s |  |
| 164 | `closures` | 12 | 7.1s |  |
| 165 | `coerce_return_type` | 40 | 7.3s |  |
| 166 | `coerce_return_type_fail` | 2 | 7.2s |  |
| 167 | `coerce_return_void` | 3 | 7.0s |  |
| 168 | `coerce_string` | 86 | 7.3s |  |
| 169 | `coerce_string_precision` | 28 | 7.2s |  |
| 170 | `coerce_to_primitive_side_effects` | 29 | 7.2s |  |
| 171 | `color_matrix_filter` | 19 | 7.3s |  |
| 172 | `construct_errors_swf10` | 8 | 7.2s |  |
| 173 | `construct_frame_list` | 22 | 27.0s |  |
| 174 | `construct_interface` | 3 | 7.2s |  |
| 175 | `constructor_call` | 3 | 7.2s |  |
| 176 | `constructors_vs_timeline` | 5 | 26.7s |  |
| 177 | `constructprop_dynamic_primitive` | 7 | 7.3s |  |
| 178 | `context3d_creation` | 9 | 7.3s |  |
| 179 | `control_flow_bool` | 4 | 7.2s |  |
| 180 | `control_flow_stricteq` | 8 | 7.2s |  |
| 181 | `convert_boolean` | 30 | 7.3s |  |
| 182 | `convert_integer` | 90 | 7.3s |  |
| 183 | `convert_number` | 56 | 7.2s |  |
| 184 | `convert_uinteger` | 90 | 7.2s |  |
| 185 | `convolution_filter` | 89 | 7.3s |  |
| 186 | `cpool_index_invalid_bytecode_1` | 6 | 7.2s |  |
| 187 | `cpool_index_invalid_bytecode_2` | 3 | 7.1s |  |
| 188 | `cpool_index_invalid_bytecode_3` | 1 | 7.0s |  |
| 189 | `cross_api_version_call_older` | 12 | 7.3s |  |
| 190 | `cryptscore` | 11 | 7.0s |  |
| 191 | `date` | 30 | 7.6s |  |
| 192 | `date_parse` | 36 | 7.2s |  |
| 193 | `declocal` | 46 | 7.3s |  |
| 194 | `declocal_i` | 46 | 7.2s |  |
| 195 | `decode_uri` | 71 | 7.4s |  |
| 196 | `decrement` | 46 | 7.2s |  |
| 197 | `decrement_i` | 46 | 3.3s |  |
| 198 | `default_values` | 7 | 7.2s |  |
| 199 | `dictionary_access` | 62 | 7.3s |  |
| 200 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 201 | `dictionary_delete` | 101 | 7.6s |  |
| 202 | `dictionary_foreach` | 42 | 7.3s |  |
| 203 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 204 | `dictionary_in` | 62 | 7.3s |  |
| 205 | `dictionary_iter_modify` | 8 | 7.1s |  |
| 206 | `dictionary_namespaces` | 36 | 7.2s |  |
| 207 | `dictionary_primitive_keys` | 29 | 7.1s |  |
| 208 | `displacement_map_filter` | 61 | 7.2s |  |
| 209 | `displayobject_alpha` | 277 | 7.1s |  |
| 210 | `displayobject_blendmode` | 0 | 7.2s |  |
| 211 | `displayobject_colortransform_nested` | 0 | 26.4s |  |
| 212 | `displayobject_filters` | 17 | 7.2s |  |
| 213 | `displayobject_from_enterframe` | 1 | 26.2s |  |
| 214 | `displayobject_getbounds_shape` | 0 | 26.4s |  |
| 215 | `displayobject_height` | 6052 | 26.9s |  |
| 216 | `displayobject_hittestobject` | 32 | 7.2s |  |
| 217 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 218 | `displayobject_invalid_props` | 3 | 7.0s |  |
| 219 | `displayobject_mask` | 3 | 7.4s |  |
| 220 | `displayobject_mask_self_referential` | 0 | 7.1s |  |
| 221 | `displayobject_metaData` | 3 | 6.9s |  |
| 222 | `displayobject_name` | 22 | 7.3s |  |
| 223 | `displayobject_name_from_timeline` | 24 | 7.2s |  |
| 224 | `displayobject_parent` | 12 | 6.9s |  |
| 225 | `displayobject_root` | 24 | 7.0s |  |
| 226 | `displayobject_rotation` | 1284 | 7.2s |  |
| 227 | `displayobject_set_matrix_nested` | 0 | 26.4s |  |
| 228 | `displayobject_set_name_loaded` | 3 | 7.5s |  |
| 229 | `displayobject_subclass` | 2 | 7.1s |  |
| 230 | `displayobject_visible` | 23 | 7.1s |  |
| 231 | `displayobject_width` | 4852 | 26.3s |  |
| 232 | `displayobject_x` | 614 | 7.0s |  |
| 233 | `displayobject_y` | 617 | 7.1s |  |
| 234 | `displayobjectcontainer_addchild` | 32 | 7.1s |  |
| 235 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.0s |  |
| 236 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.2s |  |
| 237 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.1s |  |
| 238 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.2s |  |
| 239 | `displayobjectcontainer_addchildat` | 42 | 7.1s |  |
| 240 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.2s |  |
| 241 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.1s |  |
| 242 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.1s |  |
| 243 | `displayobjectcontainer_contains` | 66 | 25.8s |  |
| 244 | `displayobjectcontainer_getchildat` | 4 | 7.1s |  |
| 245 | `displayobjectcontainer_getchildbyname` | 9 | 7.0s |  |
| 246 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.0s |  |
| 247 | `displayobjectcontainer_getchildindex` | 28 | 7.1s |  |
| 248 | `displayobjectcontainer_removechild` | 10 | 7.0s |  |
| 249 | `displayobjectcontainer_removechild_errors` | 4 | 7.0s |  |
| 250 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.1s |  |
| 251 | `displayobjectcontainer_removechildat` | 18 | 7.0s |  |
| 252 | `displayobjectcontainer_removechildren` | 51 | 7.4s |  |
| 253 | `displayobjectcontainer_setchildindex` | 42 | 7.1s |  |
| 254 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.6s |  |
| 255 | `displayobjectcontainer_swapchildren` | 42 | 7.1s |  |
| 256 | `displayobjectcontainer_swapchildrenat` | 42 | 7.1s |  |
| 257 | `displayobjectcontainer_timelineinstance` | 48 | 25.5s |  |
| 258 | `divide` | 1058 | 19.0s |  |
| 259 | `doabc_is_eager` | 1 | 25.1s |  |
| 260 | `documentclass` | 9 | 7.0s |  |
| 261 | `domain_memory` | 133 | 8.1s |  |
| 262 | `drag_drop` | 10 | 7.1s |  |
| 263 | `drop_shadow_filter` | 172 | 7.1s |  |
| 264 | `duplicate_defs` | 1 | 6.8s |  |
| 265 | `eager_init` | 1 | 6.9s |  |
| 266 | `edit_text_linkage` | 7 | 7.1s |  |
| 267 | `edittext_align` | 60 | 7.3s |  |
| 268 | `edittext_always_show_selection` | 0 | 25.8s |  |
| 269 | `edittext_antialiastype` | 296 | 7.2s |  |
| 270 | `edittext_at_point_methods_basic` | 16 | 8.2s |  |
| 271 | `edittext_autosize` | 39 | 7.3s |  |
| 272 | `edittext_autosize_align` | 0 | 25.9s |  |
| 273 | `edittext_autosize_height_dynamic` | 60 | 25.8s |  |
| 274 | `edittext_autosize_height_input` | 60 | 7.0s |  |
| 275 | `edittext_autosize_lazy_bounds_events` | 65 | 7.2s |  |
| 276 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.0s |  |
| 277 | `edittext_autosize_lazy_bounds_props` | 490 | 8.4s |  |
| 278 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.6s |  |
| 279 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.1s |  |
| 280 | `edittext_bottom_scroll_v_basic` | 210 | 7.0s |  |
| 281 | `edittext_bounds_scale` | 24 | 25.1s |  |
| 282 | `edittext_bullet` | 30 | 7.1s |  |
| 283 | `edittext_default_format` | 221 | 7.2s |  |
| 284 | `edittext_default_format_empty` | 136 | 7.2s |  |
| 285 | `edittext_empty_text_format` | 7 | 7.0s |  |
| 286 | `edittext_focus_selection` | 5 | 7.0s |  |
| 287 | `edittext_font_size` | 45 | 7.0s |  |
| 288 | `edittext_format_empty_font` | 8 | 6.9s |  |
| 289 | `edittext_get_char_index_at_point` | 4 | 26.6s |  |
| 290 | `edittext_get_line_index_at_point` | 2 | 25.6s |  |
| 291 | `edittext_get_line_index_of_char` | 76 | 7.8s |  |
| 292 | `edittext_getcharboundaries` | 172 | 7.3s |  |
| 293 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.7s |  |
| 294 | `edittext_getcharboundaries_scroll` | 85 | 7.5s |  |
| 295 | `edittext_getlinemetrics` | 146 | 7.7s |  |
| 296 | `edittext_html` | 3101 | 7.9s |  |
| 297 | `edittext_html_condensewhite` | 487 | 7.6s |  |
| 298 | `edittext_html_entity` | 4 | 7.8s |  |
| 299 | `edittext_html_font_size_swf12` | 267 | 7.6s |  |
| 300 | `edittext_html_font_size_swf13` | 273 | 7.3s |  |
| 301 | `edittext_html_roundtrip` | 17 | 7.5s |  |
| 302 | `edittext_ime_focus_lost` | 9 | 27.2s |  |
| 303 | `edittext_input_control` | 12 | 7.4s |  |
| 304 | `edittext_leading` | 9 | 7.6s |  |
| 305 | `edittext_letter_spacing` | 15 | 7.4s |  |
| 306 | `edittext_line_methods` | 294 | 8.9s |  |
| 307 | `edittext_line_metrics` | 11 | 28.1s |  |
| 308 | `edittext_margins` | 25 | 7.6s |  |
| 309 | `edittext_max_scroll_h_basic` | 475 | 7.7s |  |
| 310 | `edittext_max_scroll_v_basic` | 1000 | 7.5s |  |
| 311 | `edittext_mouse_selection` | 363 | 27.6s |  |
| 312 | `edittext_mousedown` | 3 | 7.6s |  |
| 313 | `edittext_mouseenabled` | 26 | 7.3s |  |
| 314 | `edittext_newline_character` | 22 | 7.2s |  |
| 315 | `edittext_newline_stripping` | 64 | 10.0s |  |
| 316 | `edittext_newlines` | 30 | 7.3s |  |
| 317 | `edittext_paragraph_methods` | 257 | 7.2s |  |
| 318 | `edittext_paste_events` | 8 | 7.4s |  |
| 319 | `edittext_paste_maxchars` | 4 | 7.2s |  |
| 320 | `edittext_paste_restrict` | 16 | 7.1s |  |
| 321 | `edittext_restrict` | 191 | 7.2s |  |
| 322 | `edittext_restrict_events` | 22 | 7.3s |  |
| 323 | `edittext_scrollh` | 10 | 7.2s |  |
| 324 | `edittext_selected_text` | 9 | 7.2s |  |
| 325 | `edittext_set_html_same` | 17 | 7.2s |  |
| 326 | `edittext_set_text_vs_html` | 9 | 7.2s |  |
| 327 | `edittext_stylesheet` | 536 | 7.7s |  |
| 328 | `edittext_stylesheet_custom_tag` | 76 | 7.3s |  |
| 329 | `edittext_stylesheet_display` | 272 | 7.3s |  |
| 330 | `edittext_underline` | 40 | 7.3s |  |
| 331 | `edittext_width_height` | 103 | 21.5s |  |
| 332 | `edittext_wordwrap_word` | 150 | 7.3s |  |
| 333 | `edittext_wrap_breaks` | 2375 | 7.5s |  |
| 334 | `empty_bounds` | 1 | 7.0s |  |
| 335 | `encode_uri_surrogate_pair_swf11` | 15 | 6.6s |  |
| 336 | `equals` | 512 | 10.8s |  |
| 337 | `error_geterrormessage` | 779 | 6.9s |  |
| 338 | `error_prototype` | 15 | 6.9s |  |
| 339 | `error_stack_trace_debug_swf17` | 0 | 25.2s |  |
| 340 | `error_stack_trace_debug_swf18` | 0 | 6.7s |  |
| 341 | `error_stack_trace_release_swf17` | 0 | 6.7s |  |
| 342 | `error_stack_trace_release_swf18` | 0 | 6.6s |  |
| 343 | `error_tostring` | 29 | 6.9s |  |
| 344 | `es3_inheritance` | 31 | 6.9s |  |
| 345 | `es4_inheritance` | 30 | 6.9s |  |
| 346 | `es4_interfaces` | 30 | 6.9s |  |
| 347 | `es4_method_binding` | 8 | 6.9s |  |
| 348 | `es4_oop_prototypes` | 14 | 7.0s |  |
| 349 | `es4_protected_inheritance` | 6 | 6.9s |  |
| 350 | `escape` | 71 | 7.0s |  |
| 351 | `event_bubbles` | 2 | 6.9s |  |
| 352 | `event_cancelable` | 2 | 6.8s |  |
| 353 | `event_clone` | 20 | 6.9s |  |
| 354 | `event_clone_error_redispatch` | 3 | 7.0s |  |
| 355 | `event_clone_on_redispatch` | 10 | 7.0s |  |
| 356 | `event_formattostring` | 31 | 7.0s |  |
| 357 | `event_isdefaultprevented` | 12 | 6.9s |  |
| 358 | `event_target_getter` | 5 | 3.0s |  |
| 359 | `event_target_set` | 9 | 6.8s |  |
| 360 | `event_type` | 1 | 22.2s |  |
| 361 | `event_valueof_tostring` | 18 | 7.3s |  |
| 362 | `eventdispatcher_dispatchevent` | 12 | 7.2s |  |
| 363 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.3s |  |
| 364 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.2s |  |
| 365 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.3s |  |
| 366 | `eventdispatcher_dispatchevent_this` | 5 | 7.2s |  |
| 367 | `eventdispatcher_haseventlistener` | 25 | 7.3s |  |
| 368 | `eventdispatcher_interface_invoke` | 1 | 7.2s |  |
| 369 | `eventdispatcher_tostring` | 10 | 7.2s |  |
| 370 | `eventdispatcher_willtrigger` | 25 | 7.2s |  |
| 371 | `falsiness` | 30 | 7.3s |  |
| 372 | `fast_index_access` | 12 | 7.4s |  |
| 373 | `filefilter_properties` | 4 | 7.2s |  |
| 374 | `filereference_browse_cancel` | 3 | 7.2s |  |
| 375 | `filereference_browse_select` | 9 | 7.3s |  |
| 376 | `filereference_load` | 31 | 7.3s |  |
| 377 | `filereference_save` | 16 | 7.3s |  |
| 378 | `filereference_save_and_browse` | 42 | 7.4s |  |
| 379 | `filereference_save_and_load` | 22 | 7.3s |  |
| 380 | `filereference_uninitialized` | 8 | 7.2s |  |
| 381 | `filereferencelist_browse_cancel` | 6 | 7.2s |  |
| 382 | `filereferencelist_browse_select` | 7 | 7.2s |  |
| 383 | `filter_rewind` | 8 | 7.6s |  |
| 384 | `filters_array_holes` | 25 | 7.4s |  |
| 385 | `finddef` | 3 | 7.3s |  |
| 386 | `findprop_global_prototype` | 6 | 7.4s |  |
| 387 | `flash_media_video_constructor` | 156 | 8.2s |  |
| 388 | `flash_xml` | 29 | 7.4s |  |
| 389 | `flash_xml_cloneNode` | 22 | 7.4s |  |
| 390 | `flash_xml_namespace` | 109 | 7.2s |  |
| 391 | `flash_xml_removeNode` | 60 | 7.2s |  |
| 392 | `focus_events_code` | 161 | 27.0s |  |
| 393 | `focus_events_key_basic` | 132 | 26.9s |  |
| 394 | `focus_events_key_navigation` | 53 | 7.4s |  |
| 395 | `focus_events_key_same_object` | 26 | 7.3s |  |
| 396 | `focus_events_mixed_key_mouse` | 100 | 26.9s |  |
| 397 | `focus_events_mouse_basic` | 260 | 40.7s |  |
| 398 | `focus_events_mouse_focusable` | 112 | 26.3s |  |
| 399 | `focus_events_mouse_same_object` | 40 | 25.8s |  |
| 400 | `focus_remove` | 20 | 25.7s |  |
| 401 | `focus_root_movie` | 4 | 25.8s |  |
| 402 | `focus_stage` | 1 | 7.0s |  |
| 403 | `focusrect` | 18 | 7.7s |  |
| 404 | `focusrect_focuslost` | 9 | 7.1s |  |
| 405 | `focusrect_property` | 110 | 7.1s |  |
| 406 | `font_description_clone` | 14 | 7.0s |  |
| 407 | `font_embedded` | 24 | 7.4s |  |
| 408 | `font_enumeratefonts_filter` | 4 | 26.4s |  |
| 409 | `font_hasglyphs` | 40 | 7.4s |  |
| 410 | `framelabel_constr` | 5 | 7.2s |  |
| 411 | `function_call` | 12 | 7.1s |  |
| 412 | `function_call_arguments` | 46 | 7.1s |  |
| 413 | `function_call_arguments_enumerate` | 5 | 7.0s |  |
| 414 | `function_call_coercion` | 108 | 7.4s |  |
| 415 | `function_call_default` | 6 | 6.9s |  |
| 416 | `function_call_rest` | 22 | 7.0s |  |
| 417 | `function_call_types` | 3 | 6.9s |  |
| 418 | `function_call_via_apply` | 11 | 7.0s |  |
| 419 | `function_call_via_call` | 3 | 7.0s |  |
| 420 | `function_display_anonymous` | 7 | 3.1s |  |
| 421 | `function_length` | 6 | 7.0s |  |
| 422 | `function_object` | 2 | 7.0s |  |
| 423 | `function_proto` | 5 | 6.9s |  |
| 424 | `function_proto_created` | 61 | 7.0s |  |
| 425 | `function_to_locale_string` | 4 | 7.0s |  |
| 426 | `function_to_string` | 4 | 6.9s |  |
| 427 | `function_type` | 6 | 7.0s |  |
| 428 | `function_unbound_this` | 51 | 7.1s |  |
| 429 | `function_value_of` | 4 | 7.0s |  |
| 430 | `get_definition_by_name` | 11 | 7.0s |  |
| 431 | `get_qualified_class_name` | 20 | 21.2s |  |
| 432 | `get_qualified_super_class_name` | 18 | 6.9s |  |
| 433 | `get_slot_edge_cases` | 1 | 24.9s |  |
| 434 | `get_timer` | 2 | 6.9s |  |
| 435 | `getglobalslot` | 1 | 6.8s |  |
| 436 | `getouterscope` | 8 | 6.8s |  |
| 437 | `getter_different_namespace_setter` | 2 | 6.7s |  |
| 438 | `glow_filter` | 127 | 7.0s |  |
| 439 | `goto_button_nested_framescript` | 28 | 25.6s |  |
| 440 | `goto_in_constructframe` | 12 | 7.1s |  |
| 441 | `goto_in_scene_last_frame` | 2 | 25.0s |  |
| 442 | `goto_methods` | 56 | 7.1s |  |
| 443 | `goto_methods_swfver10` | 8 | 6.9s |  |
| 444 | `goto_nested_construct_sibling` | 18 | 7.3s |  |
| 445 | `goto_nested_framescript` | 9 | 7.0s |  |
| 446 | `goto_on_orphan` | 15 | 7.1s |  |
| 447 | `gradient_bevel_filter` | 206 | 7.0s |  |
| 448 | `gradient_glow_filter` | 206 | 6.9s |  |
| 449 | `graphics_bad_direct_commands` | 5 | 7.6s |  |
| 450 | `graphics_bitmap_fill` | 0 | 8.7s |  |
| 451 | `graphics_bitmaps` | 0 | 7.6s |  |
| 452 | `graphics_direct_commands` | 0 | 7.5s |  |
| 453 | `graphics_draw_triangles` | 98 | 26.1s |  |
| 454 | `graphics_gradients` | 0 | 7.2s |  |
| 455 | `graphics_gradients_nulls` | 0 | 7.1s |  |
| 456 | `graphics_path` | 56 | 6.9s |  |
| 457 | `graphics_round_rects` | 0 | 6.9s |  |
| 458 | `graphics_simple_shapes` | 0 | 7.2s |  |
| 459 | `greaterequals` | 512 | 10.7s |  |
| 460 | `greaterthan` | 512 | 10.7s |  |
| 461 | `has_own_property` | 102 | 7.5s |  |
| 462 | `hasownproperty_namespaces` | 2 | 6.8s |  |
| 463 | `hello_world` | 1 | 6.8s |  |
| 464 | `hittest_morph` | 30 | 7.0s |  |
| 465 | `if_eq` | 10 | 6.9s |  |
| 466 | `if_gt` | 1 | 6.9s |  |
| 467 | `if_gte` | 10 | 21.8s |  |
| 468 | `if_lt` | 1 | 7.0s |  |
| 469 | `if_lte` | 10 | 6.9s |  |
| 470 | `if_ne` | 7 | 3.1s |  |
| 471 | `if_stricteq` | 6 | 7.0s |  |
| 472 | `if_strictne` | 11 | 7.1s |  |
| 473 | `ime_linux_dead_keys` | 10 | 7.2s |  |
| 474 | `in` | 102 | 7.5s |  |
| 475 | `inclocal` | 46 | 7.0s |  |
| 476 | `inclocal_i` | 46 | 7.0s |  |
| 477 | `increment` | 46 | 7.0s |  |
| 478 | `increment_i` | 46 | 7.0s |  |
| 479 | `indexing_delete` | 75 | 7.0s |  |
| 480 | `instanceof` | 58 | 7.2s |  |
| 481 | `instantiation_on_enter_frame` | 7 | 25.5s |  |
| 482 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.9s |  |
| 483 | `int_constr` | 92 | 7.2s |  |
| 484 | `int_edge_cases` | 19 | 7.0s |  |
| 485 | `int_instanceof` | 3 | 6.9s |  |
| 486 | `int_tofixed` | 1215 | 6.9s |  |
| 487 | `int_tostring` | 3375 | 7.2s |  |
| 488 | `interactiveobject_enabled` | 25 | 6.9s |  |
| 489 | `interface_namespaces` | 78 | 7.2s |  |
| 490 | `is_finite` | 46 | 7.0s |  |
| 491 | `is_nan` | 46 | 6.8s |  |
| 492 | `is_prototype_of` | 12 | 6.9s |  |
| 493 | `issue_10221` | 2 | 7.0s |  |
| 494 | `issue_13780` | 12 | 7.0s |  |
| 495 | `issue_14901` | 1 | 6.9s |  |
| 496 | `issue_17675_edittext_paste_maxchars` | 1 | 7.0s |  |
| 497 | `issue_5292` | 5 | 7.0s |  |
| 498 | `issue_8630` | 2 | 26.1s |  |
| 499 | `issue_8630_scriptremove` | 11 | 7.1s |  |
| 500 | `istype` | 24 | 3.2s |  |
| 501 | `istypelate` | 58 | 7.5s |  |
| 502 | `istypelate_coerce` | 198 | 22.6s |  |
| 503 | `jpeg_loader_context` | 6 | 7.1s |  |
| 504 | `json_errors` | 9 | 26.0s |  |
| 505 | `json_parse` | 21 | 7.0s |  |
| 506 | `json_stringify` | 12 | 7.3s |  |
| 507 | `json_stringify_order` | 1 | 7.1s |  |
| 508 | `json_version_gated` | 1 | 7.1s |  |
| 509 | `key_input_80percent` | 1812 | 7.3s |  |
| 510 | `key_input_location` | 126 | 7.2s |  |
| 511 | `key_input_numpad` | 384 | 7.1s |  |
| 512 | `lazyinit` | 17 | 7.2s |  |
| 513 | `lessequals` | 512 | 11.2s |  |
| 514 | `lessthan` | 512 | 11.1s |  |
| 515 | `loader_bitmap_transparency` | 14 | 7.2s |  |
| 516 | `loader_bytes_unknown_content` | 14 | 7.2s |  |
| 517 | `loader_child_getdefinition` | 5 | 7.3s |  |
| 518 | `loader_duplicate_coerce` | 3 | 7.3s |  |
| 519 | `loader_duplicate_coerce_new_domain` | 4 | 7.2s |  |
| 520 | `loader_error_in_root_ctor` | 4 | 7.3s |  |
| 521 | `loader_events` | 92 | 7.9s |  |
| 522 | `loader_image` | 8 | 7.6s |  |
| 523 | `loader_jpegxr` | 2 | 26.2s |  |
| 524 | `loader_jpegxr_alpha` | 1 | 25.8s |  |
| 525 | `loader_loadbytes_events` | 30 | 7.8s |  |
| 526 | `loader_loadbytes_invalid_png` | 4 | 25.9s |  |
| 527 | `loader_loadbytes_url` | 12 | 7.4s |  |
| 528 | `loader_loaderurl` | 6 | 7.5s |  |
| 529 | `loader_method` | 85 | 7.2s |  |
| 530 | `loader_noninteractive_try_click_root` | 5 | 26.8s |  |
| 531 | `loader_reuse` | 38 | 7.3s |  |
| 532 | `loader_unknown_content` | 24 | 7.2s |  |
| 533 | `loader_visibility_interactive` | 1 | 7.2s |  |
| 534 | `loaderinfo_events` | 7 | 7.0s |  |
| 535 | `loaderinfo_loadurl` | 12 | 21.6s |  |
| 536 | `loaderinfo_more` | 6 | 7.5s |  |
| 537 | `loaderinfo_properties` | 18 | 7.1s |  |
| 538 | `loaderinfo_properties_not_loaded` | 23 | 7.2s |  |
| 539 | `loaderinfo_root` | 10 | 7.0s |  |
| 540 | `loaderinfo_root_allows` | 2 | 6.9s |  |
| 541 | `localconnection_send` | 4 | 7.0s |  |
| 542 | `lshift` | 1058 | 18.9s |  |
| 543 | `mask_reapply` | 1 | 7.0s |  |
| 544 | `math` | 497 | 7.2s |  |
| 545 | `matrix3d` | 57 | 7.8s |  |
| 546 | `matrix3d_compose` | 34 | 7.3s |  |
| 547 | `matrix3d_invert` | 18 | 7.0s |  |
| 548 | `missing_external_interface` | 10 | 7.1s |  |
| 549 | `modulo` | 1058 | 19.1s |  |
| 550 | `morph_shape` | 2 | 26.0s |  |
| 551 | `mouse_children` | 192 | 25.8s |  |
| 552 | `mouse_click_events` | 90 | 25.6s |  |
| 553 | `mouse_double_click_events` | 188 | 7.0s |  |
| 554 | `mouse_empty_parent` | 4 | 7.1s |  |
| 555 | `mouse_over_while_dragging` | 3 | 7.2s |  |
| 556 | `mouse_pick_button_mode` | 2 | 7.0s |  |
| 557 | `mouse_pick_dobj_mask` | 4 | 7.2s |  |
| 558 | `mouse_pick_masking` | 7 | 25.5s |  |
| 559 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 25.4s |  |
| 560 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.2s |  |
| 561 | `mouse_pick_text` | 8 | 7.1s |  |
| 562 | `mouse_sibling` | 8 | 6.9s |  |
| 563 | `mouse_wheel_events` | 36 | 26.5s |  |
| 564 | `mouseevent_constr` | 66 | 7.0s |  |
| 565 | `mouseevent_stagexy` | 35 | 7.0s |  |
| 566 | `mouseevent_valueof_tostring` | 28 | 6.9s |  |
| 567 | `movieclip_addframescript` | 3 | 26.0s |  |
| 568 | `movieclip_child_property` | 16 | 7.1s |  |
| 569 | `movieclip_constr` | 21 | 22.1s |  |
| 570 | `movieclip_currentlabels` | 17 | 27.0s |  |
| 571 | `movieclip_currentlabels_dupes1` | 46 | 26.9s |  |
| 572 | `movieclip_currentlabels_dupes2` | 30 | 7.3s |  |
| 573 | `movieclip_currentlabels_dupes3` | 67 | 7.2s |  |
| 574 | `movieclip_currentscene` | 12 | 7.5s |  |
| 575 | `movieclip_dispatchevent` | 430 | 7.4s |  |
| 576 | `movieclip_dispatchevent_cancel` | 102 | 7.4s |  |
| 577 | `movieclip_dispatchevent_handlerorder` | 251 | 7.3s |  |
| 578 | `movieclip_dispatchevent_selfadd` | 80 | 7.2s |  |
| 579 | `movieclip_dispatchevent_target` | 899 | 7.4s |  |
| 580 | `movieclip_displayevents` | 96 | 27.3s |  |
| 581 | `movieclip_displayevents_clickgoto` | 676 | 7.8s |  |
| 582 | `movieclip_displayevents_clickgoto2` | 2001 | 7.9s |  |
| 583 | `movieclip_displayevents_clickplay` | 575 | 7.5s |  |
| 584 | `movieclip_displayevents_clicksymbol` | 562 | 7.5s |  |
| 585 | `movieclip_displayevents_constructframegoto` | 140 | 7.7s |  |
| 586 | `movieclip_displayevents_constructframeplay` | 50 | 7.5s |  |
| 587 | `movieclip_displayevents_constructframesymbol` | 144 | 7.5s |  |
| 588 | `movieclip_displayevents_dblhandler` | 21 | 7.5s |  |
| 589 | `movieclip_displayevents_enterframegoto` | 149 | 7.6s |  |
| 590 | `movieclip_displayevents_enterframeplay` | 48 | 7.3s |  |
| 591 | `movieclip_displayevents_enterframesymbol` | 149 | 27.7s |  |
| 592 | `movieclip_displayevents_exitframegoto` | 106 | 7.4s |  |
| 593 | `movieclip_displayevents_exitframeplay` | 44 | 7.3s |  |
| 594 | `movieclip_displayevents_exitframesymbol` | 135 | 7.5s |  |
| 595 | `movieclip_displayevents_looping` | 63 | 27.1s |  |
| 596 | `movieclip_displayevents_stopped` | 113 | 7.8s |  |
| 597 | `movieclip_displayevents_swap` | 96 | 3.1s |  |
| 598 | `movieclip_displayevents_timeline` | 128 | 27.2s |  |
| 599 | `movieclip_drawrect` | 54 | 7.3s |  |
| 600 | `movieclip_frameconstruct_skipped` | 9 | 7.5s |  |
| 601 | `movieclip_goto_during_frame_script` | 15 | 7.4s |  |
| 602 | `movieclip_goto_overwrite` | 14 | 27.1s |  |
| 603 | `movieclip_goto_scene_last_frame_int` | 1 | 27.3s |  |
| 604 | `movieclip_goto_scene_last_frame_label` | 1 | 7.3s |  |
| 605 | `movieclip_gotoandplay` | 15 | 27.1s |  |
| 606 | `movieclip_gotoandstop` | 13 | 27.3s |  |
| 607 | `movieclip_gotoandstop_children` | 4 | 7.4s |  |
| 608 | `movieclip_gotoandstop_framescripts1` | 4 | 7.3s |  |
| 609 | `movieclip_gotoandstop_framescripts2` | 4 | 3.3s |  |
| 610 | `movieclip_gotoandstop_framescripts_self` | 7 | 42.8s |  |
| 611 | `movieclip_gotoandstop_queueing` | 12 | 27.3s |  |
| 612 | `movieclip_next_frame` | 2 | 7.6s |  |
| 613 | `movieclip_next_scene` | 6 | 26.9s |  |
| 614 | `movieclip_play` | 3 | 7.2s |  |
| 615 | `movieclip_prev_frame` | 3 | 7.2s |  |
| 616 | `movieclip_prev_scene` | 7 | 7.5s |  |
| 617 | `movieclip_properties` | 79 | 7.7s |  |
| 618 | `movieclip_queued_noop_goto_swf10` | 9 | 7.5s |  |
| 619 | `movieclip_queued_noop_goto_swf9` | 7 | 1.4s |  |
| 620 | `movieclip_scenes` | 11 | 7.3s |  |
| 621 | `movieclip_soundtransform` | 831 | 29.0s |  |
| 622 | `movieclip_stop` | 1 | 7.3s |  |
| 623 | `movieclip_super_is_symbol` | 20 | 7.6s |  |
| 624 | `movieclip_symbol_constr` | 8 | 7.4s |  |
| 625 | `movieclip_text_mousedown` | 1 | 7.4s |  |
| 626 | `movieclip_willtrigger` | 5 | 7.6s |  |
| 627 | `multiply` | 1058 | 18.9s |  |
| 628 | `namespace_constr` | 253 | 7.7s |  |
| 629 | `namespace_constr_args` | 1 | 7.4s |  |
| 630 | `namespace_enumeration_order` | 7 | 7.5s |  |
| 631 | `nan_scale` | 9 | 7.4s |  |
| 632 | `navigateToURL_target_normalize` | 107 | 28.3s |  |
| 633 | `negate` | 30 | 7.4s |  |
| 634 | `negative_volume_panned` | 0 | 7.7s |  |
| 635 | `nested_iteration` | 11 | 7.5s |  |
| 636 | `net_getClassByAlias` | 3 | 7.4s |  |
| 637 | `net_navigateToURL` | 57 | 7.4s |  |
| 638 | `net_stream_play_options` | 6 | 7.7s |  |
| 639 | `netconnection_close` | 55 | 7.7s |  |
| 640 | `netconnection_properties` | 78 | 7.7s |  |
| 641 | `netconnection_send_remote` | 50 | 7.9s |  |
| 642 | `netconnection_serialize_arrays` | 6 | 7.5s |  |
| 643 | `netstream_client` | 10 | 7.4s |  |
| 644 | `netstream_connect` | 7 | 7.2s |  |
| 645 | `newactivation_in_script_init` | 3 | 7.2s |  |
| 646 | `newclass_twice` | 3 | 6.9s |  |
| 647 | `nonconflicting_declarations` | 0 | 7.0s |  |
| 648 | `null_void_types` | 8 | 7.1s |  |
| 649 | `number_autoconv` | 21 | 7.2s |  |
| 650 | `number_autoconv_amf` | 132 | 7.1s |  |
| 651 | `number_autoconv_array_sort_32bit` | 1 | 7.0s |  |
| 652 | `number_constr` | 58 | 7.1s |  |
| 653 | `number_toexponential` | 378 | 7.0s |  |
| 654 | `number_toexponential2` | 35 | 7.0s |  |
| 655 | `number_tofixed` | 378 | 7.0s |  |
| 656 | `number_toprecision` | 350 | 7.1s |  |
| 657 | `obfuscated_class_names` | 3 | 7.0s |  |
| 658 | `object_enumeration` | 10 | 7.1s |  |
| 659 | `object_prototype` | 4 | 7.0s |  |
| 660 | `object_to_locale_string` | 2 | 7.0s |  |
| 661 | `object_to_string` | 2 | 6.8s |  |
| 662 | `object_value_of` | 2 | 3.0s |  |
| 663 | `op_coerce` | 54 | 7.0s |  |
| 664 | `op_coerce_x` | 54 | 7.0s |  |
| 665 | `op_escxattr` | 2 | 7.0s |  |
| 666 | `op_escxelem` | 2 | 6.9s |  |
| 667 | `op_lookupswitch` | 4 | 7.0s |  |
| 668 | `optimize_coerce` | 1 | 6.9s |  |
| 669 | `orphan_movie_complex` | 80 | 7.4s |  |
| 670 | `orphan_movie_reorder` | 111 | 25.9s |  |
| 671 | `package_namespace` | 7 | 6.8s |  |
| 672 | `param_default_value_has_zero_cpool_index` | 1 | 6.9s |  |
| 673 | `parent_early_access_child` | 16 | 7.3s |  |
| 674 | `parse_float` | 81 | 7.2s |  |
| 675 | `perspective_projection_basic` | 40 | 7.0s |  |
| 676 | `pixelbender_ceil` | 77 | 7.2s |  |
| 677 | `pixelbender_conditional` | 138 | 22.3s |  |
| 678 | `pixelbender_conversions` | 270 | 7.6s |  |
| 679 | `pixelbender_dithering` | 8 | 31.3s |  |
| 680 | `pixelbender_div` | 36 | 7.4s |  |
| 681 | `pixelbender_effect_BlurredFocus` | 0 | 33.7s |  |
| 682 | `pixelbender_effect_glassDisplace` | 0 | 12.9s |  |
| 683 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 31.3s |  |
| 684 | `pixelbender_effect_smudge` | 0 | 10.8s |  |
| 685 | `pixelbender_effect_tintype` | 0 | 9.9s |  |
| 686 | `pixelbender_effect_twirl` | 0 | 11.1s |  |
| 687 | `pixelbender_eof` | 7 | 7.2s |  |
| 688 | `pixelbender_images` | 0 | 9.7s |  |
| 689 | `pixelbender_input` | 103 | 27.1s |  |
| 690 | `pixelbender_logicalnot` | 20 | 7.2s |  |
| 691 | `pixelbender_malformed_data` | 190 | 26.8s |  |
| 692 | `pixelbender_multiple_out_params` | 1 | 7.2s |  |
| 693 | `pixelbender_no_out_param` | 6 | 7.2s |  |
| 694 | `pixelbender_outputs` | 13 | 7.4s |  |
| 695 | `pixelbender_padding_bytes` | 22 | 7.3s |  |
| 696 | `pixelbender_param_qualifier` | 512 | 7.3s |  |
| 697 | `pixelbender_parameters` | 1563 | 7.6s |  |
| 698 | `pixelbender_parameters_bool` | 240 | 7.5s |  |
| 699 | `pixelbender_parameters_int_vs_bool` | 54 | 7.3s |  |
| 700 | `pixelbender_parse_errors` | 6 | 7.3s |  |
| 701 | `pixelbender_rsqrt` | 24 | 7.3s |  |
| 702 | `pixelbender_select_kinds` | 8 | 7.4s |  |
| 703 | `pixelbender_shaderdata` | 49 | 7.4s |  |
| 704 | `pixelbender_shaderdata_setter` | 99 | 7.7s |  |
| 705 | `pixelbender_sign` | 60 | 7.5s |  |
| 706 | `pixelbender_vector_output` | 11 | 7.5s |  |
| 707 | `place_multiple` | 17 | 25.9s |  |
| 708 | `place_object_replace` | 9 | 7.4s |  |
| 709 | `place_object_replace_2` | 24 | 7.5s |  |
| 710 | `place_object_same_depth_frame` | 1 | 7.3s |  |
| 711 | `point` | 132 | 7.7s |  |
| 712 | `primitive_edge_cases` | 1 | 7.2s |  |
| 713 | `property_priority` | 22 | 7.5s |  |
| 714 | `property_priority_three_level` | 6 | 25.7s |  |
| 715 | `propertyisenumerable_namespaces` | 6 | 7.0s |  |
| 716 | `prototype_set_null` | 7 | 7.0s |  |
| 717 | `proxy_callproperty` | 24 | 7.0s |  |
| 718 | `proxy_deleteproperty` | 64 | 7.1s |  |
| 719 | `proxy_enumeration` | 34 | 7.0s |  |
| 720 | `proxy_getproperty` | 77 | 7.1s |  |
| 721 | `proxy_hasownproperty` | 8 | 7.0s |  |
| 722 | `proxy_hasproperty` | 32 | 7.0s |  |
| 723 | `proxy_serialize` | 9 | 7.0s |  |
| 724 | `proxy_setproperty` | 42 | 7.0s |  |
| 725 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.0s |  |
| 726 | `qname_constr` | 32 | 7.0s |  |
| 727 | `qname_constr_namespace` | 24 | 7.0s |  |
| 728 | `qname_enumeration` | 9 | 7.0s |  |
| 729 | `qname_indexing` | 23 | 7.0s |  |
| 730 | `qname_tostring` | 25 | 7.0s |  |
| 731 | `qname_valueof` | 29 | 7.1s |  |
| 732 | `regexp_constr` | 148 | 7.2s |  |
| 733 | `regexp_exec` | 19 | 7.0s |  |
| 734 | `regexp_extended` | 47 | 7.0s |  |
| 735 | `regexp_multiargs` | 1 | 6.9s |  |
| 736 | `regexp_test` | 27 | 7.0s |  |
| 737 | `regexp_toString` | 10 | 7.0s |  |
| 738 | `register_script_refresh` | 35 | 7.5s |  |
| 739 | `remove_child_clear_field` | 88 | 7.3s |  |
| 740 | `remove_dobj` | 3 | 6.9s |  |
| 741 | `resolve_order` | 4 | 7.0s |  |
| 742 | `responder_null_callbacks` | 1 | 7.0s |  |
| 743 | `rng` | 1 | 8.2s |  |
| 744 | `rootless` | 42 | 7.2s |  |
| 745 | `rshift` | 1058 | 19.2s |  |
| 746 | `sandbox_type_inherited` | 2 | 7.3s |  |
| 747 | `sandbox_type_local_file` | 1 | 22.6s |  |
| 748 | `sandbox_type_local_network` | 1 | 7.1s |  |
| 749 | `scene_constr` | 8 | 7.7s |  |
| 750 | `selection` | 239 | 7.8s |  |
| 751 | `set_local_0` | 31 | 7.6s |  |
| 752 | `set_property_is_enumerable` | 85 | 8.0s |  |
| 753 | `shaderparameter_value` | 4 | 7.4s |  |
| 754 | `shape_drawrect` | 54 | 7.5s |  |
| 755 | `shared_object_no_root` | 3 | 7.4s |  |
| 756 | `simplebutton_added_to_stage` | 45 | 27.8s |  |
| 757 | `simplebutton_childevents` | 86 | 27.4s |  |
| 758 | `simplebutton_childevents_nested` | 54 | 7.7s |  |
| 759 | `simplebutton_childevents_sprite` | 13 | 7.4s |  |
| 760 | `simplebutton_childprops` | 144 | 7.6s |  |
| 761 | `simplebutton_childshuffle` | 23 | 7.3s |  |
| 762 | `simplebutton_constr` | 36 | 7.6s |  |
| 763 | `simplebutton_constr_childevents` | 48 | 7.7s |  |
| 764 | `simplebutton_constr_params` | 42 | 7.5s |  |
| 765 | `simplebutton_mouseenabled` | 26 | 7.3s |  |
| 766 | `simplebutton_multi_children` | 19 | 7.5s |  |
| 767 | `simplebutton_structure` | 27 | 7.6s |  |
| 768 | `simplebutton_symbolclass` | 68 | 7.8s |  |
| 769 | `slot_disp_id_shared_numbering` | 1 | 27.4s |  |
| 770 | `slots_force_autoassigned` | 1 | 7.4s |  |
| 771 | `socket_after_disconnect` | 1 | 7.5s |  |
| 772 | `socket_close` | 2 | 7.4s |  |
| 773 | `socket_connect` | 4 | 7.4s |  |
| 774 | `socket_errors` | 56 | 8.1s |  |
| 775 | `socket_read_big` | 48 | 7.6s |  |
| 776 | `socket_read_little` | 48 | 21.3s |  |
| 777 | `socket_read_write_object` | 8 | 7.0s |  |
| 778 | `socket_write_big` | 15 | 7.2s |  |
| 779 | `socket_write_little` | 14 | 7.0s |  |
| 780 | `sound_embeddedprops` | 26 | 7.2s |  |
| 781 | `sound_play` | 19 | 7.2s |  |
| 782 | `sound_valueof` | 33 | 7.0s |  |
| 783 | `soundchannel_soundtransform` | 835 | 27.4s |  |
| 784 | `soundchannel_soundtransform_exists` | 5 | 25.5s |  |
| 785 | `soundchannel_stop` | 8 | 7.3s |  |
| 786 | `soundmixer_buffertime` | 5 | 7.1s |  |
| 787 | `soundmixer_stopall` | 6 | 7.3s |  |
| 788 | `soundtransform` | 442 | 13.2s |  |
| 789 | `sprite_with_frames` | 0 | 26.2s |  |
| 790 | `stage3d_agal_cross_product` | 0 | 9.6s |  |
| 791 | `stage3d_agal_upload_errors` | 66 | 9.7s |  |
| 792 | `stage3d_bitmap` | 0 | 31.2s |  |
| 793 | `stage3d_blend` | 81 | 30.3s |  |
| 794 | `stage3d_context3d_string_args` | 158 | 8.0s |  |
| 795 | `stage3d_errors` | 7 | 7.1s |  |
| 796 | `stage3d_errors_atf` | 3 | 8.3s |  |
| 797 | `stage3d_errors_swf_29` | 6 | 7.1s |  |
| 798 | `stage3d_float1_index` | 0 | 28.1s |  |
| 799 | `stage3d_fractal` | 0 | 28.5s |  |
| 800 | `stage3d_ignore_sampler_override` | 0 | 28.6s |  |
| 801 | `stage3d_multistage_triangle` | 3 | 9.9s |  |
| 802 | `stage3d_program_constants_bytearray_be` | 0 | 29.6s |  |
| 803 | `stage3d_program_constants_bytearray_le` | 0 | 10.2s |  |
| 804 | `stage3d_program_constants_invalid_input` | 21 | 7.9s |  |
| 805 | `stage3d_rotating_cube` | 0 | 10.7s |  |
| 806 | `stage3d_sampler` | 0 | 9.9s |  |
| 807 | `stage3d_sampler_partial_upload` | 0 | 24.6s |  |
| 808 | `stage3d_stencil` | 0 | 29.7s |  |
| 809 | `stage3d_texture_bytearray` | 0 | 11.2s |  |
| 810 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.5s |  |
| 811 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.5s |  |
| 812 | `stage3d_triangle` | 0 | 9.9s |  |
| 813 | `stage3d_triangle_bytes4` | 0 | 9.9s |  |
| 814 | `stage3d_triangle_float1` | 0 | 9.8s |  |
| 815 | `stage3d_triangle_index_upload` | 0 | 9.8s |  |
| 816 | `stage3d_x_y` | 22 | 7.2s |  |
| 817 | `stage_access` | 10 | 7.2s |  |
| 818 | `stage_displayobject_properties` | 24 | 7.1s |  |
| 819 | `stage_framerate_nan` | 7 | 7.4s |  |
| 820 | `stage_framerate_negative` | 6 | 7.2s |  |
| 821 | `stage_framerate_zero` | 6 | 7.2s |  |
| 822 | `stage_invalidate` | 38 | 7.4s |  |
| 823 | `stage_loaderinfo_properties` | 24 | 7.5s |  |
| 824 | `stage_mousechildren` | 2 | 7.2s |  |
| 825 | `stage_mouseenabled` | 15 | 7.1s |  |
| 826 | `stage_overriden_setters` | 31 | 7.3s |  |
| 827 | `stage_properties` | 30 | 7.1s |  |
| 828 | `stage_stage3Ds_vector` | 1 | 25.6s |  |
| 829 | `static_var_with_this_in_ctor` | 2 | 7.2s |  |
| 830 | `stored_properties` | 11 | 7.2s |  |
| 831 | `strict_equality` | 34 | 7.2s |  |
| 832 | `string_call` | 13 | 7.1s |  |
| 833 | `string_case` | 23 | 7.2s |  |
| 834 | `string_char_at` | 27 | 7.2s |  |
| 835 | `string_char_code_at` | 28 | 7.1s |  |
| 836 | `string_concat_fromcharcode` | 37 | 7.1s |  |
| 837 | `string_constr` | 25 | 7.2s |  |
| 838 | `string_indexof_lastindexof` | 87 | 7.4s |  |
| 839 | `string_length` | 16 | 22.3s |  |
| 840 | `string_locale_compare` | 39 | 7.8s |  |
| 841 | `string_match` | 51 | 7.8s |  |
| 842 | `string_relational_compare` | 4 | 7.3s |  |
| 843 | `string_replace` | 51 | 7.7s |  |
| 844 | `string_search` | 41 | 7.6s |  |
| 845 | `string_slice_substr_substring` | 170 | 8.6s |  |
| 846 | `string_split` | 29 | 7.4s |  |
| 847 | `string_substr_negative` | 21 | 7.3s |  |
| 848 | `string_substr_weird` | 182 | 7.2s |  |
| 849 | `subtract` | 1058 | 19.9s |  |
| 850 | `super_get_call` | 12 | 7.3s |  |
| 851 | `supercall_two_classobjects` | 2 | 7.3s |  |
| 852 | `swf8` | 1 | 7.2s |  |
| 853 | `swf_10_queued_goto_scripts_construct` | 52 | 7.7s |  |
| 854 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 855 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 856 | `swf_9_queued_goto_scripts` | 6 | 7.3s |  |
| 857 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 858 | `swf_9_versioning` | 2 | 7.2s |  |
| 859 | `swf_wrong_frame_count` | 38 | 7.6s |  |
| 860 | `swf_wrong_frame_count_isplaying` | 22 | 26.1s |  |
| 861 | `symbol_class_binary_data` | 8 | 7.2s |  |
| 862 | `symbol_class_conflict` | 4 | 7.8s |  |
| 863 | `symbol_class_root_not_zero` | 1 | 7.2s |  |
| 864 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 865 | `tab_ordering_automatic_advanced` | 184 | 42.4s |  |
| 866 | `tab_ordering_automatic_basic` | 45 | 7.2s |  |
| 867 | `tab_ordering_children` | 116 | 7.1s |  |
| 868 | `tab_ordering_custom_basic` | 34 | 6.9s |  |
| 869 | `tab_ordering_stage_tab_children` | 32 | 7.0s |  |
| 870 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.3s |  |
| 871 | `tab_ordering_tabbable` | 47 | 7.3s |  |
| 872 | `text_engine_fontdescription` | 27 | 7.3s |  |
| 873 | `text_run` | 7 | 6.9s |  |
| 874 | `textbox_click` | 37 | 27.1s |  |
| 875 | `textfield_event` | 66 | 7.3s |  |
| 876 | `textfield_focusin_event` | 9 | 7.1s |  |
| 877 | `textfield_input_dead_keys_windows` | 15 | 7.1s |  |
| 878 | `textfield_unload` | 39 | 28.5s |  |
| 879 | `textformat` | 1134 | 7.6s |  |
| 880 | `textformat_display` | 14 | 7.3s |  |
| 881 | `textformat_font_max_length` | 4 | 7.0s |  |
| 882 | `throw` | 3 | 7.2s |  |
| 883 | `timeline_scripts` | 3 | 7.3s |  |
| 884 | `timer` | 90 | 8.3s |  |
| 885 | `timer_events` | 3 | 7.1s |  |
| 886 | `timer_finished` | 11 | 7.4s |  |
| 887 | `timer_reset` | 8 | 7.4s |  |
| 888 | `timer_setdelay` | 5 | 7.4s |  |
| 889 | `trace` | 12 | 7.2s |  |
| 890 | `truthiness` | 30 | 6.2s |  |
| 891 | `try_catch` | 11 | 21.2s |  |
| 892 | `try_catch_typed` | 12 | 5.8s |  |
| 893 | `typeof` | 30 | 5.8s |  |
| 894 | `uint_constr` | 92 | 6.0s |  |
| 895 | `uint_tofixed` | 1215 | 5.6s |  |
| 896 | `uint_tostring` | 3375 | 6.1s |  |
| 897 | `uncaught_error_basic` | 2 | 5.8s |  |
| 898 | `unchecked_function` | 15 | 5.8s |  |
| 899 | `unescape` | 28 | 5.8s |  |
| 900 | `url_loader` | 25 | 5.8s |  |
| 901 | `urlrequest` | 18 | 5.7s |  |
| 902 | `urlstream_basic` | 5 | 5.8s |  |
| 903 | `urshift` | 1058 | 15.6s |  |
| 904 | `utils3d` | 7 | 5.8s |  |
| 905 | `vector3d` | 397 | 9.5s |  |
| 906 | `vector_class` | 36 | 6.3s |  |
| 907 | `vector_class_call` | 11 | 6.0s |  |
| 908 | `vector_coercion` | 66 | 7.0s |  |
| 909 | `vector_concat` | 90 | 6.3s |  |
| 910 | `vector_constr` | 107 | 6.4s |  |
| 911 | `vector_enumeration` | 5 | 6.0s |  |
| 912 | `vector_every` | 92 | 6.6s |  |
| 913 | `vector_filter` | 95 | 6.7s |  |
| 914 | `vector_holes` | 24 | 5.9s |  |
| 915 | `vector_indexof` | 302 | 9.4s |  |
| 916 | `vector_insertat` | 270 | 6.8s |  |
| 917 | `vector_int_access` | 4 | 5.8s |  |
| 918 | `vector_int_delete` | 11 | 5.8s |  |
| 919 | `vector_join` | 58 | 6.2s |  |
| 920 | `vector_lastindexof` | 302 | 5.8s |  |
| 921 | `vector_legacy` | 10 | 5.8s |  |
| 922 | `vector_map` | 85 | 6.5s |  |
| 923 | `vector_object_final` | 1 | 5.8s |  |
| 924 | `vector_object_toString` | 10 | 5.7s |  |
| 925 | `vector_pushpop` | 255 | 6.9s |  |
| 926 | `vector_reborrow_bug` | 10 | 6.8s |  |
| 927 | `vector_removeat` | 172 | 23.4s |  |
| 928 | `vector_reverse` | 232 | 8.6s |  |
| 929 | `vector_shiftunshift` | 252 | 8.8s |  |
| 930 | `vector_slice` | 331 | 9.0s |  |
| 931 | `vector_sort` | 905 | 17.3s |  |
| 932 | `vector_splice` | 693 | 11.7s |  |
| 933 | `vector_splice_fixed_bug_compat` | 4 | 7.3s |  |
| 934 | `vector_tostring` | 79 | 7.8s |  |
| 935 | `verification` | 8 | 7.4s |  |
| 936 | `verify_abnormal_loop` | 1 | 7.1s |  |
| 937 | `verify_dxns_without_flag` | 3 | 7.6s |  |
| 938 | `verify_exception_targets_edge_case` | 1 | 7.3s |  |
| 939 | `verify_jump_to_middle_of_op` | 1 | 7.2s |  |
| 940 | `verify_lookup_switch_edge_case` | 1 | 7.2s |  |
| 941 | `verify_stack` | 5 | 7.3s |  |
| 942 | `verify_unreachable_exception` | 2 | 7.2s |  |
| 943 | `versioned_isplaying` | 2 | 7.3s |  |
| 944 | `virtual_properties` | 16 | 7.3s |  |
| 945 | `with` | 4 | 7.2s |  |
| 946 | `wrong_arg_count` | 7 | 7.1s |  |
| 947 | `xml_abstract_equality` | 36 | 7.2s |  |
| 948 | `xml_advanced` | 52 | 7.0s |  |
| 949 | `xml_appendchild` | 10 | 7.2s |  |
| 950 | `xml_as_attribute` | 9 | 7.0s |  |
| 951 | `xml_attribute` | 35 | 7.2s |  |
| 952 | `xml_attribute_name` | 40 | 7.1s |  |
| 953 | `xml_basic` | 33 | 7.3s |  |
| 954 | `xml_child` | 25 | 7.3s |  |
| 955 | `xml_childindex` | 7 | 7.1s |  |
| 956 | `xml_children` | 43 | 7.6s |  |
| 957 | `xml_class_call` | 9 | 6.9s |  |
| 958 | `xml_contains` | 197 | 7.1s |  |
| 959 | `xml_copy` | 20 | 3.1s |  |
| 960 | `xml_ctor_from_tostring` | 23 | 22.9s |  |
| 961 | `xml_delete` | 114 | 7.7s |  |
| 962 | `xml_descendants` | 83 | 7.6s |  |
| 963 | `xml_elements` | 6 | 7.6s |  |
| 964 | `xml_equals_namespace_check` | 2 | 7.6s |  |
| 965 | `xml_explicit_use_namespace` | 5 | 7.7s |  |
| 966 | `xml_getdescendants_qname` | 21 | 7.7s |  |
| 967 | `xml_has_property_via_in` | 26 | 7.6s |  |
| 968 | `xml_hasownproperty` | 6 | 7.5s |  |
| 969 | `xml_ignore_white` | 6 | 7.6s |  |
| 970 | `xml_length` | 2 | 7.5s |  |
| 971 | `xml_list_as_attribute` | 9 | 7.4s |  |
| 972 | `xml_list_concat` | 20 | 7.3s |  |
| 973 | `xml_list_enumerate` | 4 | 7.2s |  |
| 974 | `xml_methods_settings` | 3 | 7.5s |  |
| 975 | `xml_mismatched_tag` | 37 | 7.6s |  |
| 976 | `xml_namespace` | 39 | 7.6s |  |
| 977 | `xml_namespace_methods` | 245 | 7.8s |  |
| 978 | `xml_namespaced_property` | 7 | 7.7s |  |
| 979 | `xml_no_namespace` | 1 | 7.8s |  |
| 980 | `xml_nodekind` | 3 | 7.8s |  |
| 981 | `xml_normalize` | 35 | 7.8s |  |
| 982 | `xml_notification_bubbling` | 361 | 7.7s |  |
| 983 | `xml_parent` | 8 | 7.8s |  |
| 984 | `xml_set_children` | 17 | 7.8s |  |
| 985 | `xml_set_name` | 34 | 7.7s |  |
| 986 | `xml_settings` | 6 | 3.4s |  |
| 987 | `xml_simple_complex_content` | 47 | 7.7s |  |
| 988 | `xml_socket` | 11 | 7.9s |  |
| 989 | `xml_text` | 7 | 7.7s |  |
| 990 | `xml_tostring` | 6 | 7.6s |  |
| 991 | `xml_tostring_namespace` | 12 | 7.5s |  |
| 992 | `xml_unescaping` | 23 | 7.7s |  |
| 993 | `xml_weird_ignores` | 54 | 7.8s |  |
| 994 | `xml_wildcard` | 11 | 7.7s |  |
| 995 | `xmldocument` | 254 | 7.8s |  |
| 996 | `xmlnode` | 3540 | 7.9s |  |
| 997 | `zero_frame_clip` | 3 | 8.4s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 7.0s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 5.6s |  |
| 3 | `blend_transform` | 1 | 1 | 7.4s |  |
| 4 | `coerce_property` | 3 | 3 | 7.3s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.2s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 7.4s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.2s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 41.9s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 7.5s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.0s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 7.0s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 7.0s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 25.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 26.1s |  |
| 15 | `int_toexponential` | 76 | 76 | 7.2s |  |
| 16 | `int_toprecision` | 441 | 441 | 7.1s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.7s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 7.2s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 27.8s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.4s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 7.2s |  |
| 22 | `sprite_dropTarget` | 15 | 15 | 7.1s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.9s |  |
| 24 | `uint_toexponential` | 100 | 100 | 6.0s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.9s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 25.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**61 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 5 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 6 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 7 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 8 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 9 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 11 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 13 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 14 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 15 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 16 | `place_and_lookup/swf10` | 90.9% | 30 | 33 | 3 |  |
| 17 | `place_and_lookup/swf9` | 90.9% | 30 | 33 | 3 |  |
| 18 | `font_enumeratefonts` | 89.1% | 41 | 46 | 5 |  |
| 19 | `bitmapdata_zero_size` | 87.5% | 7 | 8 | 1 |  |
| 20 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 21 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 22 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 23 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 24 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 25 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 26 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 27 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 28 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 29 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 30 | `flash_media_video_setter` | 82.5% | 33 | 40 | 7 |  |
| 31 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 32 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 33 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 34 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 35 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 36 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 37 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 38 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 39 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 40 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 41 | `flash_media_video_rotation_probe` | 74.1% | 20 | 27 | 7 |  |
| 42 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 43 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 44 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 45 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 46 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 47 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 48 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 49 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 50 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 51 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 52 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 53 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 54 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 55 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 56 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 57 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 58 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 59 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 60 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 61 | `verify_illegal_opcode` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.8s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.8s |  |
| 3 | `verify_typecheck` | exit code 1 | 7.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**196 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 5 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 6 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 7 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 8 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 9 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 11 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 13 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 14 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 15 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 16 | `place_and_lookup/swf10` | 90.9% | 30/33 | 33 | 33 |  |
| 17 | `place_and_lookup/swf9` | 90.9% | 30/33 | 33 | 33 |  |
| 18 | `font_enumeratefonts` | 89.1% | 41/46 | 46 | 41 |  |
| 19 | `bitmapdata_zero_size` | 87.5% | 7/8 | 8 | 8 |  |
| 20 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 21 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 15 | 15 |  |
| 22 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 23 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 24 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 25 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 26 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 27 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 28 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 29 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 30 | `flash_media_video_setter` | 82.5% | 33/40 | 40 | 40 |  |
| 31 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 32 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 33 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 34 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 35 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 36 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 37 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 38 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 39 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 40 | `superinterface_call` | 75.0% | 15/20 | 18 | 20 |  |
| 41 | `flash_media_video_rotation_probe` | 74.1% | 20/27 | 27 | 27 |  |
| 42 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 43 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 44 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 45 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 46 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 47 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 48 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 13 | 13 |  |
| 49 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 50 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 51 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 52 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 53 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 54 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 55 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 57 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 58 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 59 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 60 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 61 | `verify_illegal_opcode` | 50.0% | 1/2 | 2 | 1 |  |
| 62 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 63 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 64 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 65 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 66 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 67 | `rectangle` | 40.9% | 447/1094 | 451 | 1094 |  |
| 68 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 69 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 70 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 71 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 72 | `geom_transform` | 27.0% | 20/74 | 26 | 74 |  |
| 73 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 74 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 75 | `property_is_enumerable` | 21.9% | 25/114 | 27 | 114 |  |
| 76 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 77 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 78 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 79 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 4 | 5 |  |
| 80 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 81 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 82 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 83 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 84 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 85 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 86 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 87 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 88 | `uncaught_errors_stringified` | 11.1% | 2/18 | 7 | 18 |  |
| 89 | `url_vars` | 11.1% | 3/27 | 5 | 27 |  |
| 90 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 91 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 92 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 93 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 94 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 95 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 96 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 97 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 98 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 99 | `textline_validity` | 4.3% | 7/162 | 12 | 162 |  |
| 100 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 101 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 102 | `escape_multi_byte` | 2.2% | 1/45 | 3 | 45 |  |
| 103 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 104 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 105 | `text_engine_groupelement` | 1.6% | 1/64 | 4 | 64 |  |
| 106 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 107 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 108 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 109 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 110 | `all_classes/display/swf9` | 0.1% | 2/1959 | 350 | 1959 |  |
| 111 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 112 | `all_classes/events/swf9` | 0.1% | 1/1030 | 184 | 1030 |  |
| 113 | `all_classes/events/swf30` | 0.1% | 2/2353 | 184 | 2353 |  |
| 114 | `all_classes/display/swf10` | 0.1% | 2/2569 | 350 | 2569 |  |
| 115 | `all_classes/display/swf11` | 0.1% | 2/2593 | 350 | 2593 |  |
| 116 | `all_classes/display/swf12` | 0.1% | 2/2593 | 350 | 2593 |  |
| 117 | `all_classes/display/swf13` | 0.1% | 2/2671 | 350 | 2671 |  |
| 118 | `all_classes/events/swf10` | 0.1% | 1/1638 | 184 | 1638 |  |
| 119 | `all_classes/events/swf11` | 0.1% | 1/1750 | 184 | 1750 |  |
| 120 | `all_classes/events/swf12` | 0.1% | 1/1814 | 184 | 1814 |  |
| 121 | `abstract_classes` | 0.0% | 0/132 | 2 | 132 |  |
| 122 | `accessibility` | 0.0% | 0/2 | 2 | 1 |  |
| 123 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 124 | `air_ifilepromise` | 0.0% | 0/3 | 3 | 1 |  |
| 125 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 126 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 127 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 128 | `all_classes/display/swf30` | 0.0% | 0/2936 | 350 | 2936 |  |
| 129 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 130 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 131 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 132 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 133 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 134 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 135 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 136 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 137 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 138 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 2 | 9 |  |
| 139 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 140 | `av_tag_data` | 0.0% | 0/2 | 2 | 2 |  |
| 141 | `avm1_root` | 0.0% | 0/58 | 6 | 58 |  |
| 142 | `away3d_advanced_shallow_water_demo` | 0.0% | 0/7 | 7 | 0 |  |
| 143 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 144 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 145 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 146 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 147 | `content_element_basic` | 0.0% | 0/50 | 2 | 50 |  |
| 148 | `currency_parse_result` | 0.0% | 0/7 | 2 | 7 |  |
| 149 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 150 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 151 | `east_asian_justifier_clone` | 0.0% | 0/8 | 2 | 8 |  |
| 152 | `element_format_clone` | 0.0% | 0/44 | 2 | 44 |  |
| 153 | `element_format_properties` | 0.0% | 0/235 | 2 | 235 |  |
| 154 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 155 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 156 | `font_enumeratefonts_order` | 0.0% | 0/9 | 3 | 9 |  |
| 157 | `game_input` | 0.0% | 0/4 | 2 | 4 |  |
| 158 | `generate_random_bytes` | 0.0% | 0/3 | 3 | 3 |  |
| 159 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 160 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 161 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 162 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 163 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 164 | `netfilterevent` | 0.0% | 0/10 | 2 | 10 |  |
| 165 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 166 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 167 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 168 | `print_job_options` | 0.0% | 0/3 | 2 | 3 |  |
| 169 | `property_priority_definition_names_order` | 0.0% | 0/2 | 2 | 2 |  |
| 170 | `scopes_dont_cache/order-1` | 0.0% | 0/3 | 3 | 1 |  |
| 171 | `scopes_dont_cache/order-2` | 0.0% | 0/3 | 3 | 1 |  |
| 172 | `security_domain_current` | 0.0% | 0/2 | 2 | 2 |  |
| 173 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 174 | `space_justifier_clone` | 0.0% | 0/12 | 2 | 12 |  |
| 175 | `stage3d_raytrace` | 0.0% | 0/4 | 4 | 0 |  |
| 176 | `stage3d_texture` | 0.0% | 0/2 | 2 | 0 |  |
| 177 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 178 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 179 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 180 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 181 | `supercalls_weird` | 0.0% | 0/2 | 2 | 2 |  |
| 182 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 183 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 184 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 185 | `tabstop_properties` | 0.0% | 0/105 | 2 | 105 |  |
| 186 | `text_element_basic` | 0.0% | 0/34 | 2 | 34 |  |
| 187 | `textblock_createline_errors` | 0.0% | 0/23 | 2 | 23 |  |
| 188 | `textblock_createline_fte` | 0.0% | 0/9 | 2 | 9 |  |
| 189 | `textblock_properties` | 0.0% | 0/118 | 2 | 118 |  |
| 190 | `textline_inapplicable_properties` | 0.0% | 0/10 | 2 | 10 |  |
| 191 | `textline_name` | 0.0% | 0/2 | 2 | 1 |  |
| 192 | `textline_splitting_basic` | 0.0% | 0/76 | 2 | 76 |  |
| 193 | `textline_throwerror` | 0.0% | 0/30 | 3 | 30 |  |
| 194 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 195 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 196 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
