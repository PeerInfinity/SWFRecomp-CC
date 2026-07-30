# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 15:55 UTC

**Git SHA**: `0612bc78e6`

**Run Duration**: 200m 3s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **993** (81.3%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1019** (83.5%) |
| Failing | 202 |
| Total expected lines | 151253 |
| Matching lines | 113018 (74.7%) |
| Mismatched lines | 38235 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 199 | 98.5% |
| Runtime Error | 3 | 1.5% |

## Passing Tests

**993 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.6s |  |
| 2 | `agal_compiler` | 13 | 9.0s |  |
| 3 | `air_datagram_socket` | 1 | 7.4s |  |
| 4 | `air_hidden_lookup` | 2 | 6.7s |  |
| 5 | `all_classes/security/swf11` | 3 | 6.7s |  |
| 6 | `amf_array_serialization` | 17 | 8.5s |  |
| 7 | `amf_custom_obj` | 26 | 6.8s |  |
| 8 | `amf_dictionary` | 9 | 6.7s |  |
| 9 | `amf_function` | 46 | 6.7s |  |
| 10 | `amf_invalid_date` | 2 | 6.6s |  |
| 11 | `amf_missing_prop` | 6 | 6.7s |  |
| 12 | `amf_nondynamic_function_prop` | 6 | 6.8s |  |
| 13 | `amf_setter_error` | 8 | 6.9s |  |
| 14 | `amf_vector` | 40 | 6.9s |  |
| 15 | `amf_xml` | 6 | 6.7s |  |
| 16 | `application_domain` | 4 | 6.8s |  |
| 17 | `array_access` | 18 | 6.9s |  |
| 18 | `array_access_interpreter` | 4 | 6.8s |  |
| 19 | `array_access_no_pubns` | 2 | 6.8s |  |
| 20 | `array_concat` | 41 | 6.8s |  |
| 21 | `array_constr` | 10 | 6.7s |  |
| 22 | `array_delete` | 44 | 6.9s |  |
| 23 | `array_enumeration` | 10 | 6.9s |  |
| 24 | `array_enumeration_elements` | 11 | 6.9s |  |
| 25 | `array_every` | 8 | 6.9s |  |
| 26 | `array_filter` | 6 | 6.9s |  |
| 27 | `array_foreach` | 18 | 6.8s |  |
| 28 | `array_hasownproperty` | 11 | 3.2s |  |
| 29 | `array_holes` | 9 | 6.8s |  |
| 30 | `array_index_max` | 84 | 6.7s |  |
| 31 | `array_indexof` | 25 | 6.9s |  |
| 32 | `array_join` | 26 | 6.8s |  |
| 33 | `array_lastindexof` | 29 | 6.8s |  |
| 34 | `array_length` | 14 | 6.8s |  |
| 35 | `array_literal` | 3 | 6.8s |  |
| 36 | `array_map` | 8 | 6.6s |  |
| 37 | `array_pop` | 52 | 6.9s |  |
| 38 | `array_push` | 24 | 6.8s |  |
| 39 | `array_reborrow_bug` | 6 | 6.8s |  |
| 40 | `array_reverse` | 28 | 6.8s |  |
| 41 | `array_shift` | 51 | 3.3s |  |
| 42 | `array_slice` | 39 | 6.9s |  |
| 43 | `array_some` | 8 | 6.8s |  |
| 44 | `array_sort` | 297 | 7.5s |  |
| 45 | `array_sort_fun_swf12` | 2 | 6.8s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 47 | `array_sort_random` | 210 | 6.8s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 6.7s |  |
| 49 | `array_sorton` | 545 | 6.8s |  |
| 50 | `array_sparse_ops` | 41 | 6.1s |  |
| 51 | `array_splice` | 133 | 6.2s |  |
| 52 | `array_splice2` | 428 | 6.3s |  |
| 53 | `array_splice_types` | 48 | 6.1s |  |
| 54 | `array_storage` | 8 | 5.9s |  |
| 55 | `array_tolocalestring` | 9 | 5.9s |  |
| 56 | `array_tostring` | 12 | 6.0s |  |
| 57 | `array_unshift` | 24 | 6.0s |  |
| 58 | `array_valueof` | 9 | 5.8s |  |
| 59 | `array_vector_null_callback` | 10 | 6.0s |  |
| 60 | `astype` | 28 | 6.0s |  |
| 61 | `astypelate` | 24 | 6.1s |  |
| 62 | `astypelate_propagates` | 1 | 5.9s |  |
| 63 | `asymmetric_key_events` | 11 | 6.2s |  |
| 64 | `av_networking_params` | 9 | 6.0s |  |
| 65 | `avm2_catchup_dobj` | 158 | 6.5s |  |
| 66 | `away3d_advanced_shallow_water_demo` | 0 | 77.8s |  |
| 67 | `bevel_filter` | 187 | 6.1s |  |
| 68 | `bitand` | 1058 | 17.1s |  |
| 69 | `bitmap_constr` | 17 | 6.2s |  |
| 70 | `bitmap_data` | 1000 | 13.1s |  |
| 71 | `bitmap_pixelsnapping` | 2 | 24.7s |  |
| 72 | `bitmap_properties` | 23 | 6.0s |  |
| 73 | `bitmap_subclass` | 7 | 7.3s |  |
| 74 | `bitmap_subclass_properties` | 9 | 6.3s |  |
| 75 | `bitmap_timeline` | 9 | 6.1s |  |
| 76 | `bitmapdata_accuracy` | 1 | 45.3s |  |
| 77 | `bitmapdata_applyfilter_blur` | 0 | 25.2s |  |
| 78 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.8s |  |
| 79 | `bitmapdata_applyfilter_destpoint` | 0 | 24.7s |  |
| 80 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 24.9s |  |
| 81 | `bitmapdata_clone` | 13 | 6.2s |  |
| 82 | `bitmapdata_colortransform` | 0 | 6.4s |  |
| 83 | `bitmapdata_colortransform_oob` | 2 | 5.9s |  |
| 84 | `bitmapdata_constr` | 22 | 6.0s |  |
| 85 | `bitmapdata_constructor_from_timeline` | 1 | 6.2s |  |
| 86 | `bitmapdata_copychannel` | 0 | 30.1s |  |
| 87 | `bitmapdata_copypixels` | 23 | 27.8s |  |
| 88 | `bitmapdata_copypixels_blend_over` | 1 | 6.5s |  |
| 89 | `bitmapdata_copypixelstobytearray` | 39 | 6.4s |  |
| 90 | `bitmapdata_dispose` | 7 | 6.5s |  |
| 91 | `bitmapdata_draw` | 0 | 27.1s |  |
| 92 | `bitmapdata_draw_colortransform` | 0 | 6.7s |  |
| 93 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.6s |  |
| 94 | `bitmapdata_draw_filters` | 0 | 26.1s |  |
| 95 | `bitmapdata_draw_masks` | 0 | 6.4s |  |
| 96 | `bitmapdata_draw_rotation` | 0 | 6.7s |  |
| 97 | `bitmapdata_draw_self_via_graphic` | 0 | 6.7s |  |
| 98 | `bitmapdata_draw_stage` | 0 | 26.6s |  |
| 99 | `bitmapdata_drawwithquality` | 0 | 6.7s |  |
| 100 | `bitmapdata_embedded` | 9 | 6.8s |  |
| 101 | `bitmapdata_fillrect` | 0 | 6.6s |  |
| 102 | `bitmapdata_filter_sourcerect` | 0 | 26.8s |  |
| 103 | `bitmapdata_floodfill` | 35 | 6.3s |  |
| 104 | `bitmapdata_getpixels` | 39 | 26.2s |  |
| 105 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 106 | `bitmapdata_histogram` | 59 | 2.9s |  |
| 107 | `bitmapdata_hittest` | 112 | 7.0s |  |
| 108 | `bitmapdata_hittest_threshold` | 18 | 6.5s |  |
| 109 | `bitmapdata_opaque` | 0 | 6.7s |  |
| 110 | `bitmapdata_pixeldissolve` | 1037 | 7.1s |  |
| 111 | `bitmapdata_pixeldissolve_image` | 0 | 6.8s |  |
| 112 | `bitmapdata_rectangle_rounding` | 16 | 6.3s |  |
| 113 | `bitmapdata_setpixels` | 286 | 6.5s |  |
| 114 | `bitmapdata_setvector` | 26 | 6.5s |  |
| 115 | `bitmapdata_sync` | 0 | 26.3s |  |
| 116 | `bitmapdata_threshold` | 176 | 7.2s |  |
| 117 | `bitnot` | 46 | 6.4s |  |
| 118 | `bitor` | 1058 | 18.0s |  |
| 119 | `bitxor` | 1058 | 17.6s |  |
| 120 | `blend_multiply_alpha` | 0 | 6.7s |  |
| 121 | `blend_scroll` | 0 | 6.7s |  |
| 122 | `blend_shader_luma_lighten` | 3 | 7.1s |  |
| 123 | `blur_filter` | 43 | 7.0s |  |
| 124 | `boolean_constr` | 32 | 6.9s |  |
| 125 | `boolean_negation` | 30 | 6.8s |  |
| 126 | `boolean_tostring` | 8 | 6.8s |  |
| 127 | `broadcast_event` | 7 | 7.0s |  |
| 128 | `button_nested_frame` | 48 | 26.2s |  |
| 129 | `bytearray` | 48 | 7.1s |  |
| 130 | `bytearray_compress` | 31 | 6.8s |  |
| 131 | `bytearray_errors` | 24 | 6.9s |  |
| 132 | `bytearray_method_serialization` | 1 | 6.8s |  |
| 133 | `bytearray_oom` | 3 | 7.0s |  |
| 134 | `bytearray_readobject_amf0` | 50 | 6.9s |  |
| 135 | `bytearray_readobject_amf3` | 53 | 7.0s |  |
| 136 | `bytearray_readutf8bytes_with_bom` | 16 | 6.9s |  |
| 137 | `bytearray_serialization` | 3 | 7.0s |  |
| 138 | `bytearray_string_null` | 19 | 7.2s |  |
| 139 | `bytearray_tostring` | 15 | 6.9s |  |
| 140 | `bytearray_utf16` | 8 | 6.9s |  |
| 141 | `bytearray_writeobject` | 24 | 6.7s |  |
| 142 | `callee_in_initializer` | 6 | 6.8s |  |
| 143 | `callproplex_class` | 1 | 6.7s |  |
| 144 | `capabilities_resolution` | 8 | 26.6s |  |
| 145 | `catch_class` | 6 | 6.8s |  |
| 146 | `catch_scope_slot` | 7 | 3.3s |  |
| 147 | `checkfilter` | 4 | 3.2s |  |
| 148 | `class_call` | 32 | 6.9s |  |
| 149 | `class_cast_call` | 14 | 6.8s |  |
| 150 | `class_enumeration` | 4 | 6.8s |  |
| 151 | `class_has_own_property` | 2 | 6.8s |  |
| 152 | `class_init_interpreter_mode` | 1 | 6.7s |  |
| 153 | `class_is` | 32 | 6.9s |  |
| 154 | `class_methods` | 5 | 6.8s |  |
| 155 | `class_object_properties` | 10 | 6.8s |  |
| 156 | `class_singleton` | 18 | 6.8s |  |
| 157 | `class_supercalls_errors` | 35 | 7.0s |  |
| 158 | `class_supercalls_mismatched` | 26 | 6.9s |  |
| 159 | `class_superclass_wrong_order` | 1 | 25.9s |  |
| 160 | `class_to_locale_string` | 2 | 6.9s |  |
| 161 | `class_to_string` | 2 | 6.7s |  |
| 162 | `class_value_of` | 2 | 6.8s |  |
| 163 | `click_block` | 5 | 7.7s |  |
| 164 | `click_invisible` | 3 | 7.2s |  |
| 165 | `closures` | 12 | 6.8s |  |
| 166 | `coerce_return_type` | 40 | 7.0s |  |
| 167 | `coerce_return_type_fail` | 2 | 6.8s |  |
| 168 | `coerce_return_void` | 3 | 6.8s |  |
| 169 | `coerce_string` | 86 | 7.0s |  |
| 170 | `coerce_string_precision` | 28 | 6.8s |  |
| 171 | `coerce_to_primitive_side_effects` | 29 | 26.1s |  |
| 172 | `color_matrix_filter` | 19 | 6.9s |  |
| 173 | `construct_errors_swf10` | 8 | 6.9s |  |
| 174 | `construct_frame_list` | 22 | 26.4s |  |
| 175 | `construct_interface` | 3 | 6.9s |  |
| 176 | `constructor_call` | 3 | 6.8s |  |
| 177 | `constructors_vs_timeline` | 5 | 26.1s |  |
| 178 | `constructprop_dynamic_primitive` | 7 | 6.9s |  |
| 179 | `context3d_creation` | 9 | 7.0s |  |
| 180 | `control_flow_bool` | 4 | 6.9s |  |
| 181 | `control_flow_stricteq` | 8 | 6.9s |  |
| 182 | `convert_boolean` | 30 | 6.8s |  |
| 183 | `convert_integer` | 90 | 7.0s |  |
| 184 | `convert_number` | 56 | 7.0s |  |
| 185 | `convert_uinteger` | 90 | 7.0s |  |
| 186 | `convolution_filter` | 89 | 7.0s |  |
| 187 | `cpool_index_invalid_bytecode_1` | 6 | 6.9s |  |
| 188 | `cpool_index_invalid_bytecode_2` | 3 | 6.8s |  |
| 189 | `cpool_index_invalid_bytecode_3` | 1 | 6.8s |  |
| 190 | `cross_api_version_call_older` | 12 | 7.2s |  |
| 191 | `cryptscore` | 11 | 7.0s |  |
| 192 | `date` | 30 | 7.2s |  |
| 193 | `date_parse` | 36 | 6.8s |  |
| 194 | `declocal` | 46 | 6.8s |  |
| 195 | `declocal_i` | 46 | 6.8s |  |
| 196 | `decode_uri` | 71 | 7.1s |  |
| 197 | `decrement` | 46 | 6.8s |  |
| 198 | `decrement_i` | 46 | 3.3s |  |
| 199 | `default_values` | 7 | 6.8s |  |
| 200 | `dictionary_access` | 62 | 7.0s |  |
| 201 | `dictionary_access_no_pubns` | 2 | 6.7s |  |
| 202 | `dictionary_delete` | 101 | 7.2s |  |
| 203 | `dictionary_foreach` | 42 | 7.0s |  |
| 204 | `dictionary_hasownproperty` | 63 | 7.0s |  |
| 205 | `dictionary_in` | 62 | 7.0s |  |
| 206 | `dictionary_iter_modify` | 8 | 6.8s |  |
| 207 | `dictionary_namespaces` | 36 | 6.9s |  |
| 208 | `dictionary_primitive_keys` | 29 | 6.8s |  |
| 209 | `displacement_map_filter` | 61 | 6.9s |  |
| 210 | `displayobject_alpha` | 277 | 6.7s |  |
| 211 | `displayobject_blendmode` | 0 | 6.9s |  |
| 212 | `displayobject_colortransform_nested` | 0 | 25.9s |  |
| 213 | `displayobject_filters` | 17 | 6.9s |  |
| 214 | `displayobject_from_enterframe` | 1 | 25.7s |  |
| 215 | `displayobject_getbounds_shape` | 0 | 25.8s |  |
| 216 | `displayobject_height` | 6052 | 25.8s |  |
| 217 | `displayobject_hittestobject` | 32 | 6.8s |  |
| 218 | `displayobject_invalid_floats` | 60 | 6.8s |  |
| 219 | `displayobject_invalid_props` | 3 | 6.7s |  |
| 220 | `displayobject_mask` | 3 | 7.1s |  |
| 221 | `displayobject_mask_self_referential` | 0 | 28.7s |  |
| 222 | `displayobject_metaData` | 3 | 7.1s |  |
| 223 | `displayobject_name` | 22 | 28.4s |  |
| 224 | `displayobject_name_from_timeline` | 24 | 7.2s |  |
| 225 | `displayobject_parent` | 12 | 7.0s |  |
| 226 | `displayobject_root` | 24 | 7.1s |  |
| 227 | `displayobject_rotation` | 1284 | 7.2s |  |
| 228 | `displayobject_set_matrix_nested` | 0 | 27.6s |  |
| 229 | `displayobject_set_name_loaded` | 3 | 7.6s |  |
| 230 | `displayobject_subclass` | 2 | 7.2s |  |
| 231 | `displayobject_visible` | 23 | 7.2s |  |
| 232 | `displayobject_width` | 4852 | 27.0s |  |
| 233 | `displayobject_x` | 614 | 7.0s |  |
| 234 | `displayobject_y` | 617 | 7.0s |  |
| 235 | `displayobjectcontainer_addchild` | 32 | 7.1s |  |
| 236 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.9s |  |
| 237 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.2s |  |
| 238 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.0s |  |
| 239 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.0s |  |
| 240 | `displayobjectcontainer_addchildat` | 42 | 7.1s |  |
| 241 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.1s |  |
| 242 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.0s |  |
| 243 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.0s |  |
| 244 | `displayobjectcontainer_contains` | 66 | 26.6s |  |
| 245 | `displayobjectcontainer_getchildat` | 4 | 7.0s |  |
| 246 | `displayobjectcontainer_getchildbyname` | 9 | 6.9s |  |
| 247 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.0s |  |
| 248 | `displayobjectcontainer_getchildindex` | 28 | 7.1s |  |
| 249 | `displayobjectcontainer_removechild` | 10 | 7.0s |  |
| 250 | `displayobjectcontainer_removechild_errors` | 4 | 7.1s |  |
| 251 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.1s |  |
| 252 | `displayobjectcontainer_removechildat` | 18 | 7.1s |  |
| 253 | `displayobjectcontainer_removechildren` | 51 | 7.4s |  |
| 254 | `displayobjectcontainer_setchildindex` | 42 | 7.0s |  |
| 255 | `displayobjectcontainer_stopallmovieclips` | 2 | 28.0s |  |
| 256 | `displayobjectcontainer_swapchildren` | 42 | 7.3s |  |
| 257 | `displayobjectcontainer_swapchildrenat` | 42 | 7.3s |  |
| 258 | `displayobjectcontainer_timelineinstance` | 48 | 20.6s |  |
| 259 | `divide` | 1058 | 14.3s |  |
| 260 | `doabc_is_eager` | 1 | 20.9s |  |
| 261 | `documentclass` | 9 | 5.6s |  |
| 262 | `domain_memory` | 133 | 21.6s |  |
| 263 | `drag_drop` | 10 | 5.6s |  |
| 264 | `drop_shadow_filter` | 172 | 5.7s |  |
| 265 | `duplicate_defs` | 1 | 5.4s |  |
| 266 | `eager_init` | 1 | 5.3s |  |
| 267 | `edit_text_linkage` | 7 | 5.5s |  |
| 268 | `edittext_align` | 60 | 5.5s |  |
| 269 | `edittext_always_show_selection` | 0 | 20.4s |  |
| 270 | `edittext_antialiastype` | 296 | 5.5s |  |
| 271 | `edittext_at_point_methods_basic` | 16 | 7.0s |  |
| 272 | `edittext_autosize` | 39 | 5.8s |  |
| 273 | `edittext_autosize_align` | 0 | 21.2s |  |
| 274 | `edittext_autosize_height_dynamic` | 60 | 21.9s |  |
| 275 | `edittext_autosize_height_input` | 60 | 5.6s |  |
| 276 | `edittext_autosize_lazy_bounds_events` | 65 | 6.0s |  |
| 277 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.8s |  |
| 278 | `edittext_autosize_lazy_bounds_props` | 490 | 6.5s |  |
| 279 | `edittext_autosize_lazy_bounds_visual` | 0 | 20.4s |  |
| 280 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.4s |  |
| 281 | `edittext_bottom_scroll_v_basic` | 210 | 5.5s |  |
| 282 | `edittext_bounds_scale` | 24 | 20.2s |  |
| 283 | `edittext_bullet` | 30 | 5.5s |  |
| 284 | `edittext_default_format` | 221 | 5.5s |  |
| 285 | `edittext_default_format_empty` | 136 | 5.5s |  |
| 286 | `edittext_empty_text_format` | 7 | 5.6s |  |
| 287 | `edittext_focus_selection` | 5 | 5.4s |  |
| 288 | `edittext_font_size` | 45 | 5.4s |  |
| 289 | `edittext_format_empty_font` | 8 | 5.4s |  |
| 290 | `edittext_get_char_index_at_point` | 4 | 21.1s |  |
| 291 | `edittext_get_line_index_at_point` | 2 | 20.7s |  |
| 292 | `edittext_get_line_index_of_char` | 76 | 6.2s |  |
| 293 | `edittext_getcharboundaries` | 172 | 6.0s |  |
| 294 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.0s |  |
| 295 | `edittext_getcharboundaries_scroll` | 85 | 25.7s |  |
| 296 | `edittext_getlinemetrics` | 146 | 6.9s |  |
| 297 | `edittext_html` | 3101 | 7.2s |  |
| 298 | `edittext_html_condensewhite` | 487 | 6.6s |  |
| 299 | `edittext_html_entity` | 4 | 6.9s |  |
| 300 | `edittext_html_font_size_swf12` | 267 | 6.7s |  |
| 301 | `edittext_html_font_size_swf13` | 273 | 6.5s |  |
| 302 | `edittext_html_roundtrip` | 17 | 6.7s |  |
| 303 | `edittext_ime_focus_lost` | 9 | 25.8s |  |
| 304 | `edittext_input_control` | 12 | 6.9s |  |
| 305 | `edittext_leading` | 9 | 7.1s |  |
| 306 | `edittext_letter_spacing` | 15 | 6.9s |  |
| 307 | `edittext_line_methods` | 294 | 8.1s |  |
| 308 | `edittext_line_metrics` | 11 | 27.5s |  |
| 309 | `edittext_margins` | 25 | 6.7s |  |
| 310 | `edittext_max_scroll_h_basic` | 475 | 6.8s |  |
| 311 | `edittext_max_scroll_v_basic` | 1000 | 6.7s |  |
| 312 | `edittext_mouse_selection` | 363 | 27.3s |  |
| 313 | `edittext_mousedown` | 3 | 7.0s |  |
| 314 | `edittext_mouseenabled` | 26 | 6.6s |  |
| 315 | `edittext_newline_character` | 22 | 6.5s |  |
| 316 | `edittext_newline_stripping` | 64 | 9.1s |  |
| 317 | `edittext_newlines` | 30 | 6.6s |  |
| 318 | `edittext_paragraph_methods` | 257 | 6.5s |  |
| 319 | `edittext_paste_events` | 8 | 6.7s |  |
| 320 | `edittext_paste_maxchars` | 4 | 6.5s |  |
| 321 | `edittext_paste_restrict` | 16 | 6.4s |  |
| 322 | `edittext_restrict` | 191 | 6.6s |  |
| 323 | `edittext_restrict_events` | 22 | 6.5s |  |
| 324 | `edittext_scrollh` | 10 | 6.5s |  |
| 325 | `edittext_selected_text` | 9 | 6.5s |  |
| 326 | `edittext_set_html_same` | 17 | 6.5s |  |
| 327 | `edittext_set_text_vs_html` | 9 | 6.5s |  |
| 328 | `edittext_stylesheet` | 536 | 6.9s |  |
| 329 | `edittext_stylesheet_custom_tag` | 76 | 6.6s |  |
| 330 | `edittext_stylesheet_display` | 272 | 6.7s |  |
| 331 | `edittext_underline` | 40 | 6.6s |  |
| 332 | `edittext_width_height` | 103 | 20.9s |  |
| 333 | `edittext_wordwrap_word` | 150 | 25.3s |  |
| 334 | `edittext_wrap_breaks` | 2375 | 6.7s |  |
| 335 | `empty_bounds` | 1 | 6.2s |  |
| 336 | `encode_uri_surrogate_pair_swf11` | 15 | 5.9s |  |
| 337 | `equals` | 512 | 9.6s |  |
| 338 | `error_geterrormessage` | 779 | 6.3s |  |
| 339 | `error_prototype` | 15 | 6.2s |  |
| 340 | `error_stack_trace_debug_swf17` | 0 | 25.4s |  |
| 341 | `error_stack_trace_debug_swf18` | 0 | 6.0s |  |
| 342 | `error_stack_trace_release_swf17` | 0 | 6.0s |  |
| 343 | `error_stack_trace_release_swf18` | 0 | 5.9s |  |
| 344 | `error_tostring` | 29 | 6.2s |  |
| 345 | `es3_inheritance` | 31 | 6.2s |  |
| 346 | `es4_inheritance` | 30 | 6.3s |  |
| 347 | `es4_interfaces` | 30 | 6.2s |  |
| 348 | `es4_method_binding` | 8 | 6.2s |  |
| 349 | `es4_oop_prototypes` | 14 | 6.4s |  |
| 350 | `es4_protected_inheritance` | 6 | 6.2s |  |
| 351 | `escape` | 71 | 6.3s |  |
| 352 | `event_bubbles` | 2 | 6.2s |  |
| 353 | `event_cancelable` | 2 | 6.1s |  |
| 354 | `event_clone` | 20 | 6.2s |  |
| 355 | `event_clone_error_redispatch` | 3 | 6.3s |  |
| 356 | `event_clone_on_redispatch` | 10 | 6.3s |  |
| 357 | `event_formattostring` | 31 | 6.3s |  |
| 358 | `event_isdefaultprevented` | 12 | 6.2s |  |
| 359 | `event_target_getter` | 5 | 2.8s |  |
| 360 | `event_target_set` | 9 | 6.2s |  |
| 361 | `event_type` | 1 | 17.5s |  |
| 362 | `event_valueof_tostring` | 18 | 5.5s |  |
| 363 | `eventdispatcher_dispatchevent` | 12 | 5.3s |  |
| 364 | `eventdispatcher_dispatchevent_cancel` | 20 | 20.6s |  |
| 365 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.8s |  |
| 366 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.9s |  |
| 367 | `eventdispatcher_dispatchevent_this` | 5 | 5.2s |  |
| 368 | `eventdispatcher_haseventlistener` | 25 | 5.4s |  |
| 369 | `eventdispatcher_interface_invoke` | 1 | 5.2s |  |
| 370 | `eventdispatcher_tostring` | 10 | 5.4s |  |
| 371 | `eventdispatcher_willtrigger` | 25 | 5.2s |  |
| 372 | `falsiness` | 30 | 5.3s |  |
| 373 | `fast_index_access` | 12 | 5.4s |  |
| 374 | `filefilter_properties` | 4 | 5.4s |  |
| 375 | `filereference_browse_cancel` | 3 | 5.3s |  |
| 376 | `filereference_browse_select` | 9 | 5.3s |  |
| 377 | `filereference_load` | 31 | 5.3s |  |
| 378 | `filereference_save` | 16 | 5.3s |  |
| 379 | `filereference_save_and_browse` | 42 | 5.3s |  |
| 380 | `filereference_save_and_load` | 22 | 5.3s |  |
| 381 | `filereference_uninitialized` | 8 | 5.2s |  |
| 382 | `filereferencelist_browse_cancel` | 6 | 5.3s |  |
| 383 | `filereferencelist_browse_select` | 7 | 5.2s |  |
| 384 | `filter_rewind` | 8 | 5.4s |  |
| 385 | `filters_array_holes` | 25 | 5.3s |  |
| 386 | `finddef` | 3 | 5.3s |  |
| 387 | `findprop_global_prototype` | 6 | 5.3s |  |
| 388 | `flash_xml` | 29 | 5.3s |  |
| 389 | `flash_xml_cloneNode` | 22 | 5.4s |  |
| 390 | `flash_xml_namespace` | 109 | 5.4s |  |
| 391 | `flash_xml_removeNode` | 60 | 5.4s |  |
| 392 | `focus_events_code` | 161 | 20.4s |  |
| 393 | `focus_events_key_basic` | 132 | 20.7s |  |
| 394 | `focus_events_key_navigation` | 53 | 5.8s |  |
| 395 | `focus_events_key_same_object` | 26 | 5.4s |  |
| 396 | `focus_events_mixed_key_mouse` | 100 | 20.1s |  |
| 397 | `focus_events_mouse_basic` | 260 | 39.7s |  |
| 398 | `focus_events_mouse_focusable` | 112 | 25.2s |  |
| 399 | `focus_events_mouse_same_object` | 40 | 25.0s |  |
| 400 | `focus_remove` | 20 | 25.1s |  |
| 401 | `focus_root_movie` | 4 | 24.9s |  |
| 402 | `focus_stage` | 1 | 6.5s |  |
| 403 | `focusrect` | 18 | 7.2s |  |
| 404 | `focusrect_focuslost` | 9 | 6.5s |  |
| 405 | `focusrect_property` | 110 | 24.9s |  |
| 406 | `font_description_clone` | 14 | 6.5s |  |
| 407 | `font_embedded` | 24 | 6.9s |  |
| 408 | `font_enumeratefonts` | 41 | 7.1s |  |
| 409 | `font_enumeratefonts_filter` | 4 | 25.4s |  |
| 410 | `font_hasglyphs` | 40 | 6.9s |  |
| 411 | `framelabel_constr` | 5 | 6.6s |  |
| 412 | `function_call` | 12 | 6.5s |  |
| 413 | `function_call_arguments` | 46 | 6.6s |  |
| 414 | `function_call_arguments_enumerate` | 5 | 6.4s |  |
| 415 | `function_call_coercion` | 108 | 6.9s |  |
| 416 | `function_call_default` | 6 | 6.4s |  |
| 417 | `function_call_rest` | 22 | 6.5s |  |
| 418 | `function_call_types` | 3 | 6.4s |  |
| 419 | `function_call_via_apply` | 11 | 6.4s |  |
| 420 | `function_call_via_call` | 3 | 6.4s |  |
| 421 | `function_display_anonymous` | 7 | 3.0s |  |
| 422 | `function_length` | 6 | 6.5s |  |
| 423 | `function_object` | 2 | 6.4s |  |
| 424 | `function_proto` | 5 | 6.5s |  |
| 425 | `function_proto_created` | 61 | 6.5s |  |
| 426 | `function_to_locale_string` | 4 | 6.4s |  |
| 427 | `function_to_string` | 4 | 6.3s |  |
| 428 | `function_type` | 6 | 6.5s |  |
| 429 | `function_unbound_this` | 51 | 6.5s |  |
| 430 | `function_value_of` | 4 | 6.4s |  |
| 431 | `get_definition_by_name` | 11 | 6.5s |  |
| 432 | `get_qualified_class_name` | 20 | 21.6s |  |
| 433 | `get_qualified_super_class_name` | 18 | 6.8s |  |
| 434 | `get_slot_edge_cases` | 1 | 25.6s |  |
| 435 | `get_timer` | 2 | 6.7s |  |
| 436 | `getglobalslot` | 1 | 6.7s |  |
| 437 | `getouterscope` | 8 | 6.7s |  |
| 438 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 439 | `glow_filter` | 127 | 6.9s |  |
| 440 | `goto_button_nested_framescript` | 28 | 26.5s |  |
| 441 | `goto_in_constructframe` | 12 | 26.0s |  |
| 442 | `goto_in_scene_last_frame` | 2 | 26.0s |  |
| 443 | `goto_methods` | 56 | 7.0s |  |
| 444 | `goto_methods_swfver10` | 8 | 6.8s |  |
| 445 | `goto_nested_construct_sibling` | 18 | 7.3s |  |
| 446 | `goto_nested_framescript` | 9 | 6.9s |  |
| 447 | `goto_on_orphan` | 15 | 7.0s |  |
| 448 | `gradient_bevel_filter` | 206 | 6.9s |  |
| 449 | `gradient_glow_filter` | 206 | 6.7s |  |
| 450 | `graphics_bad_direct_commands` | 5 | 7.6s |  |
| 451 | `graphics_bitmap_fill` | 0 | 28.1s |  |
| 452 | `graphics_bitmaps` | 0 | 7.4s |  |
| 453 | `graphics_direct_commands` | 0 | 7.4s |  |
| 454 | `graphics_draw_triangles` | 98 | 26.6s |  |
| 455 | `graphics_gradients` | 0 | 7.1s |  |
| 456 | `graphics_gradients_nulls` | 0 | 7.0s |  |
| 457 | `graphics_path` | 56 | 6.8s |  |
| 458 | `graphics_round_rects` | 0 | 6.7s |  |
| 459 | `graphics_simple_shapes` | 0 | 7.1s |  |
| 460 | `greaterequals` | 512 | 11.0s |  |
| 461 | `greaterthan` | 512 | 11.0s |  |
| 462 | `has_own_property` | 102 | 7.3s |  |
| 463 | `hasownproperty_namespaces` | 2 | 6.7s |  |
| 464 | `hello_world` | 1 | 6.7s |  |
| 465 | `hittest_morph` | 30 | 6.8s |  |
| 466 | `if_eq` | 10 | 6.7s |  |
| 467 | `if_gt` | 1 | 6.8s |  |
| 468 | `if_gte` | 10 | 21.3s |  |
| 469 | `if_lt` | 1 | 6.6s |  |
| 470 | `if_lte` | 10 | 6.5s |  |
| 471 | `if_ne` | 7 | 3.1s |  |
| 472 | `if_stricteq` | 6 | 6.6s |  |
| 473 | `if_strictne` | 11 | 6.5s |  |
| 474 | `ime_linux_dead_keys` | 10 | 25.2s |  |
| 475 | `in` | 102 | 7.0s |  |
| 476 | `inclocal` | 46 | 6.6s |  |
| 477 | `inclocal_i` | 46 | 6.6s |  |
| 478 | `increment` | 46 | 6.6s |  |
| 479 | `increment_i` | 46 | 6.6s |  |
| 480 | `indexing_delete` | 75 | 6.6s |  |
| 481 | `instanceof` | 58 | 6.8s |  |
| 482 | `instantiation_on_enter_frame` | 7 | 24.9s |  |
| 483 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.5s |  |
| 484 | `int_constr` | 92 | 6.7s |  |
| 485 | `int_edge_cases` | 19 | 6.5s |  |
| 486 | `int_instanceof` | 3 | 6.4s |  |
| 487 | `int_tofixed` | 1215 | 6.4s |  |
| 488 | `int_tostring` | 3375 | 6.8s |  |
| 489 | `interactiveobject_enabled` | 25 | 6.4s |  |
| 490 | `interface_namespaces` | 78 | 6.7s |  |
| 491 | `is_finite` | 46 | 6.6s |  |
| 492 | `is_nan` | 46 | 6.4s |  |
| 493 | `is_prototype_of` | 12 | 6.5s |  |
| 494 | `issue_10221` | 2 | 6.5s |  |
| 495 | `issue_13780` | 12 | 6.5s |  |
| 496 | `issue_14901` | 1 | 6.5s |  |
| 497 | `issue_17675_edittext_paste_maxchars` | 1 | 6.5s |  |
| 498 | `issue_5292` | 5 | 6.6s |  |
| 499 | `issue_8630` | 2 | 25.0s |  |
| 500 | `issue_8630_scriptremove` | 11 | 6.5s |  |
| 501 | `istype` | 24 | 3.1s |  |
| 502 | `istypelate` | 58 | 6.8s |  |
| 503 | `istypelate_coerce` | 198 | 22.8s |  |
| 504 | `jpeg_loader_context` | 6 | 25.8s |  |
| 505 | `json_errors` | 9 | 25.8s |  |
| 506 | `json_parse` | 21 | 6.8s |  |
| 507 | `json_stringify` | 12 | 7.0s |  |
| 508 | `json_stringify_order` | 1 | 6.7s |  |
| 509 | `json_version_gated` | 1 | 6.8s |  |
| 510 | `key_input_80percent` | 1812 | 7.1s |  |
| 511 | `key_input_location` | 126 | 7.0s |  |
| 512 | `key_input_numpad` | 384 | 6.8s |  |
| 513 | `lazyinit` | 17 | 6.8s |  |
| 514 | `lessequals` | 512 | 10.8s |  |
| 515 | `lessthan` | 512 | 10.7s |  |
| 516 | `loader_bitmap_transparency` | 14 | 6.8s |  |
| 517 | `loader_bytes_unknown_content` | 14 | 6.7s |  |
| 518 | `loader_child_getdefinition` | 5 | 6.9s |  |
| 519 | `loader_duplicate_coerce` | 3 | 6.9s |  |
| 520 | `loader_duplicate_coerce_new_domain` | 4 | 6.8s |  |
| 521 | `loader_error_in_root_ctor` | 4 | 6.9s |  |
| 522 | `loader_events` | 92 | 7.4s |  |
| 523 | `loader_image` | 8 | 7.0s |  |
| 524 | `loader_jpegxr` | 2 | 25.6s |  |
| 525 | `loader_jpegxr_alpha` | 1 | 25.5s |  |
| 526 | `loader_loadbytes_events` | 30 | 7.5s |  |
| 527 | `loader_loadbytes_invalid_png` | 4 | 25.1s |  |
| 528 | `loader_loadbytes_url` | 12 | 6.9s |  |
| 529 | `loader_loaderurl` | 6 | 7.1s |  |
| 530 | `loader_noninteractive_try_click_root` | 5 | 25.9s |  |
| 531 | `loader_reuse` | 38 | 6.8s |  |
| 532 | `loader_unknown_content` | 24 | 6.7s |  |
| 533 | `loader_visibility_interactive` | 1 | 6.7s |  |
| 534 | `loaderinfo_events` | 7 | 6.6s |  |
| 535 | `loaderinfo_loadurl` | 12 | 40.8s |  |
| 536 | `loaderinfo_more` | 6 | 26.3s |  |
| 537 | `loaderinfo_properties` | 18 | 6.9s |  |
| 538 | `loaderinfo_properties_not_loaded` | 23 | 7.0s |  |
| 539 | `loaderinfo_root` | 10 | 6.9s |  |
| 540 | `loaderinfo_root_allows` | 2 | 6.8s |  |
| 541 | `localconnection_send` | 4 | 6.8s |  |
| 542 | `lshift` | 1058 | 18.1s |  |
| 543 | `mask_reapply` | 1 | 6.9s |  |
| 544 | `math` | 497 | 7.0s |  |
| 545 | `matrix3d_invert` | 18 | 6.8s |  |
| 546 | `missing_external_interface` | 10 | 6.8s |  |
| 547 | `modulo` | 1058 | 18.1s |  |
| 548 | `morph_shape` | 2 | 26.0s |  |
| 549 | `mouse_children` | 192 | 26.3s |  |
| 550 | `mouse_click_events` | 90 | 25.9s |  |
| 551 | `mouse_double_click_events` | 188 | 6.8s |  |
| 552 | `mouse_empty_parent` | 4 | 6.8s |  |
| 553 | `mouse_over_while_dragging` | 3 | 7.0s |  |
| 554 | `mouse_pick_button_mode` | 2 | 6.9s |  |
| 555 | `mouse_pick_dobj_mask` | 4 | 7.2s |  |
| 556 | `mouse_pick_masking` | 7 | 26.0s |  |
| 557 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 25.9s |  |
| 558 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.2s |  |
| 559 | `mouse_pick_text` | 8 | 7.0s |  |
| 560 | `mouse_sibling` | 8 | 6.9s |  |
| 561 | `mouse_wheel_events` | 36 | 27.0s |  |
| 562 | `mouseevent_constr` | 66 | 6.9s |  |
| 563 | `mouseevent_stagexy` | 35 | 6.9s |  |
| 564 | `mouseevent_valueof_tostring` | 28 | 6.8s |  |
| 565 | `movieclip_addframescript` | 3 | 26.0s |  |
| 566 | `movieclip_child_property` | 16 | 7.0s |  |
| 567 | `movieclip_constr` | 21 | 22.1s |  |
| 568 | `movieclip_currentlabels` | 17 | 26.3s |  |
| 569 | `movieclip_currentlabels_dupes1` | 46 | 26.2s |  |
| 570 | `movieclip_currentlabels_dupes2` | 30 | 7.0s |  |
| 571 | `movieclip_currentlabels_dupes3` | 67 | 7.0s |  |
| 572 | `movieclip_currentscene` | 12 | 26.2s |  |
| 573 | `movieclip_dispatchevent` | 430 | 7.0s |  |
| 574 | `movieclip_dispatchevent_cancel` | 102 | 7.1s |  |
| 575 | `movieclip_dispatchevent_handlerorder` | 251 | 7.0s |  |
| 576 | `movieclip_dispatchevent_selfadd` | 80 | 7.0s |  |
| 577 | `movieclip_dispatchevent_target` | 899 | 7.1s |  |
| 578 | `movieclip_displayevents` | 96 | 26.7s |  |
| 579 | `movieclip_displayevents_clickgoto` | 676 | 27.0s |  |
| 580 | `movieclip_displayevents_clickgoto2` | 2001 | 7.5s |  |
| 581 | `movieclip_displayevents_clickplay` | 575 | 7.1s |  |
| 582 | `movieclip_displayevents_clicksymbol` | 562 | 7.1s |  |
| 583 | `movieclip_displayevents_constructframegoto` | 140 | 7.3s |  |
| 584 | `movieclip_displayevents_constructframeplay` | 50 | 7.1s |  |
| 585 | `movieclip_displayevents_constructframesymbol` | 144 | 7.0s |  |
| 586 | `movieclip_displayevents_dblhandler` | 21 | 7.1s |  |
| 587 | `movieclip_displayevents_enterframegoto` | 149 | 7.2s |  |
| 588 | `movieclip_displayevents_enterframeplay` | 48 | 7.0s |  |
| 589 | `movieclip_displayevents_enterframesymbol` | 149 | 26.5s |  |
| 590 | `movieclip_displayevents_exitframegoto` | 106 | 7.0s |  |
| 591 | `movieclip_displayevents_exitframeplay` | 44 | 7.1s |  |
| 592 | `movieclip_displayevents_exitframesymbol` | 135 | 7.2s |  |
| 593 | `movieclip_displayevents_looping` | 63 | 27.1s |  |
| 594 | `movieclip_displayevents_stopped` | 113 | 7.6s |  |
| 595 | `movieclip_displayevents_swap` | 96 | 3.3s |  |
| 596 | `movieclip_displayevents_timeline` | 128 | 27.4s |  |
| 597 | `movieclip_drawrect` | 54 | 7.1s |  |
| 598 | `movieclip_frameconstruct_skipped` | 9 | 7.4s |  |
| 599 | `movieclip_goto_during_frame_script` | 15 | 7.2s |  |
| 600 | `movieclip_goto_overwrite` | 14 | 27.5s |  |
| 601 | `movieclip_goto_scene_last_frame_int` | 1 | 26.0s |  |
| 602 | `movieclip_goto_scene_last_frame_label` | 1 | 6.7s |  |
| 603 | `movieclip_gotoandplay` | 15 | 25.7s |  |
| 604 | `movieclip_gotoandstop` | 13 | 25.7s |  |
| 605 | `movieclip_gotoandstop_children` | 4 | 7.0s |  |
| 606 | `movieclip_gotoandstop_framescripts1` | 4 | 6.9s |  |
| 607 | `movieclip_gotoandstop_framescripts2` | 4 | 3.2s |  |
| 608 | `movieclip_gotoandstop_framescripts_self` | 7 | 39.7s |  |
| 609 | `movieclip_gotoandstop_queueing` | 12 | 25.2s |  |
| 610 | `movieclip_next_frame` | 2 | 25.5s |  |
| 611 | `movieclip_next_scene` | 6 | 25.0s |  |
| 612 | `movieclip_play` | 3 | 6.5s |  |
| 613 | `movieclip_prev_frame` | 3 | 6.3s |  |
| 614 | `movieclip_prev_scene` | 7 | 6.5s |  |
| 615 | `movieclip_properties` | 79 | 25.1s |  |
| 616 | `movieclip_queued_noop_goto_swf10` | 9 | 6.6s |  |
| 617 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 618 | `movieclip_scenes` | 11 | 6.4s |  |
| 619 | `movieclip_soundtransform` | 831 | 27.1s |  |
| 620 | `movieclip_stop` | 1 | 24.9s |  |
| 621 | `movieclip_super_is_symbol` | 20 | 6.8s |  |
| 622 | `movieclip_symbol_constr` | 8 | 6.7s |  |
| 623 | `movieclip_text_mousedown` | 1 | 6.6s |  |
| 624 | `movieclip_willtrigger` | 5 | 6.8s |  |
| 625 | `multiply` | 1058 | 18.7s |  |
| 626 | `namespace_constr` | 253 | 6.9s |  |
| 627 | `namespace_constr_args` | 1 | 6.5s |  |
| 628 | `namespace_enumeration_order` | 7 | 25.3s |  |
| 629 | `nan_scale` | 9 | 6.6s |  |
| 630 | `navigateToURL_target_normalize` | 107 | 26.7s |  |
| 631 | `negate` | 30 | 6.5s |  |
| 632 | `negative_volume_panned` | 0 | 6.8s |  |
| 633 | `nested_iteration` | 11 | 6.5s |  |
| 634 | `net_getClassByAlias` | 3 | 6.5s |  |
| 635 | `net_navigateToURL` | 57 | 6.6s |  |
| 636 | `net_stream_play_options` | 6 | 6.5s |  |
| 637 | `netconnection_close` | 55 | 6.6s |  |
| 638 | `netconnection_properties` | 78 | 6.7s |  |
| 639 | `netconnection_send_remote` | 50 | 6.9s |  |
| 640 | `netconnection_serialize_arrays` | 6 | 6.6s |  |
| 641 | `netstream_client` | 10 | 6.7s |  |
| 642 | `netstream_connect` | 7 | 6.5s |  |
| 643 | `newactivation_in_script_init` | 3 | 5.5s |  |
| 644 | `newclass_twice` | 3 | 5.3s |  |
| 645 | `nonconflicting_declarations` | 0 | 5.4s |  |
| 646 | `null_void_types` | 8 | 5.5s |  |
| 647 | `number_autoconv` | 21 | 22.0s |  |
| 648 | `number_autoconv_amf` | 132 | 5.4s |  |
| 649 | `number_autoconv_array_sort_32bit` | 1 | 5.5s |  |
| 650 | `number_constr` | 58 | 5.6s |  |
| 651 | `number_toexponential` | 378 | 5.6s |  |
| 652 | `number_toexponential2` | 35 | 5.5s |  |
| 653 | `number_tofixed` | 378 | 5.7s |  |
| 654 | `number_toprecision` | 350 | 5.6s |  |
| 655 | `obfuscated_class_names` | 3 | 6.5s |  |
| 656 | `object_enumeration` | 10 | 5.5s |  |
| 657 | `object_prototype` | 4 | 5.8s |  |
| 658 | `object_to_locale_string` | 2 | 5.5s |  |
| 659 | `object_to_string` | 2 | 5.5s |  |
| 660 | `object_value_of` | 2 | 2.3s |  |
| 661 | `op_coerce` | 54 | 5.5s |  |
| 662 | `op_coerce_x` | 54 | 5.6s |  |
| 663 | `op_escxattr` | 2 | 5.5s |  |
| 664 | `op_escxelem` | 2 | 5.5s |  |
| 665 | `op_lookupswitch` | 4 | 5.5s |  |
| 666 | `optimize_coerce` | 1 | 5.4s |  |
| 667 | `orphan_movie_complex` | 80 | 6.1s |  |
| 668 | `orphan_movie_reorder` | 111 | 22.8s |  |
| 669 | `package_namespace` | 7 | 5.5s |  |
| 670 | `param_default_value_has_zero_cpool_index` | 1 | 5.5s |  |
| 671 | `parent_early_access_child` | 16 | 22.6s |  |
| 672 | `parse_float` | 81 | 5.7s |  |
| 673 | `pixelbender_ceil` | 77 | 5.8s |  |
| 674 | `pixelbender_conditional` | 138 | 41.0s |  |
| 675 | `pixelbender_conversions` | 270 | 7.2s |  |
| 676 | `pixelbender_dithering` | 8 | 31.0s |  |
| 677 | `pixelbender_div` | 36 | 7.0s |  |
| 678 | `pixelbender_effect_BlurredFocus` | 0 | 33.0s |  |
| 679 | `pixelbender_effect_glassDisplace` | 0 | 12.6s |  |
| 680 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 31.0s |  |
| 681 | `pixelbender_effect_smudge` | 0 | 10.5s |  |
| 682 | `pixelbender_effect_tintype` | 0 | 9.6s |  |
| 683 | `pixelbender_effect_twirl` | 0 | 10.8s |  |
| 684 | `pixelbender_eof` | 7 | 6.9s |  |
| 685 | `pixelbender_images` | 0 | 9.3s |  |
| 686 | `pixelbender_input` | 103 | 26.8s |  |
| 687 | `pixelbender_logicalnot` | 20 | 6.9s |  |
| 688 | `pixelbender_malformed_data` | 190 | 27.1s |  |
| 689 | `pixelbender_multiple_out_params` | 1 | 6.8s |  |
| 690 | `pixelbender_no_out_param` | 6 | 6.9s |  |
| 691 | `pixelbender_outputs` | 13 | 7.1s |  |
| 692 | `pixelbender_padding_bytes` | 22 | 7.0s |  |
| 693 | `pixelbender_param_qualifier` | 512 | 7.0s |  |
| 694 | `pixelbender_parameters` | 1563 | 7.3s |  |
| 695 | `pixelbender_parameters_bool` | 240 | 7.2s |  |
| 696 | `pixelbender_parameters_int_vs_bool` | 54 | 7.0s |  |
| 697 | `pixelbender_parse_errors` | 6 | 6.9s |  |
| 698 | `pixelbender_rsqrt` | 24 | 7.1s |  |
| 699 | `pixelbender_select_kinds` | 8 | 7.1s |  |
| 700 | `pixelbender_shaderdata` | 49 | 7.0s |  |
| 701 | `pixelbender_shaderdata_setter` | 99 | 7.3s |  |
| 702 | `pixelbender_sign` | 60 | 7.2s |  |
| 703 | `pixelbender_vector_output` | 11 | 7.2s |  |
| 704 | `place_multiple` | 17 | 25.8s |  |
| 705 | `place_object_replace` | 9 | 7.1s |  |
| 706 | `place_object_replace_2` | 24 | 7.1s |  |
| 707 | `place_object_same_depth_frame` | 1 | 7.0s |  |
| 708 | `point` | 132 | 7.5s |  |
| 709 | `primitive_edge_cases` | 1 | 6.8s |  |
| 710 | `property_priority` | 22 | 7.4s |  |
| 711 | `property_priority_three_level` | 6 | 27.9s |  |
| 712 | `propertyisenumerable_namespaces` | 6 | 7.2s |  |
| 713 | `prototype_set_null` | 7 | 7.2s |  |
| 714 | `proxy_callproperty` | 24 | 7.3s |  |
| 715 | `proxy_deleteproperty` | 64 | 7.5s |  |
| 716 | `proxy_enumeration` | 34 | 7.3s |  |
| 717 | `proxy_getproperty` | 77 | 7.4s |  |
| 718 | `proxy_hasownproperty` | 8 | 7.3s |  |
| 719 | `proxy_hasproperty` | 32 | 7.3s |  |
| 720 | `proxy_serialize` | 9 | 7.2s |  |
| 721 | `proxy_setproperty` | 42 | 7.4s |  |
| 722 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.1s |  |
| 723 | `qname_constr` | 32 | 7.3s |  |
| 724 | `qname_constr_namespace` | 24 | 7.3s |  |
| 725 | `qname_enumeration` | 9 | 7.3s |  |
| 726 | `qname_indexing` | 23 | 7.2s |  |
| 727 | `qname_tostring` | 25 | 7.2s |  |
| 728 | `qname_valueof` | 29 | 7.2s |  |
| 729 | `regexp_constr` | 148 | 7.5s |  |
| 730 | `regexp_exec` | 19 | 7.3s |  |
| 731 | `regexp_extended` | 47 | 7.2s |  |
| 732 | `regexp_multiargs` | 1 | 7.1s |  |
| 733 | `regexp_test` | 27 | 7.0s |  |
| 734 | `regexp_toString` | 10 | 6.8s |  |
| 735 | `register_script_refresh` | 35 | 26.7s |  |
| 736 | `remove_child_clear_field` | 88 | 7.3s |  |
| 737 | `remove_dobj` | 3 | 6.9s |  |
| 738 | `resolve_order` | 4 | 6.9s |  |
| 739 | `responder_null_callbacks` | 1 | 7.2s |  |
| 740 | `rng` | 1 | 8.2s |  |
| 741 | `rootless` | 42 | 7.3s |  |
| 742 | `rshift` | 1058 | 19.8s |  |
| 743 | `sandbox_type_inherited` | 2 | 21.5s |  |
| 744 | `sandbox_type_local_file` | 1 | 25.1s |  |
| 745 | `sandbox_type_local_network` | 1 | 6.3s |  |
| 746 | `scene_constr` | 8 | 6.9s |  |
| 747 | `selection` | 239 | 6.9s |  |
| 748 | `set_local_0` | 31 | 6.6s |  |
| 749 | `set_property_is_enumerable` | 85 | 7.0s |  |
| 750 | `shaderparameter_value` | 4 | 6.5s |  |
| 751 | `shape_drawrect` | 54 | 6.5s |  |
| 752 | `shared_object_no_root` | 3 | 6.5s |  |
| 753 | `simplebutton_added_to_stage` | 45 | 25.0s |  |
| 754 | `simplebutton_childevents` | 86 | 25.3s |  |
| 755 | `simplebutton_childevents_nested` | 54 | 6.8s |  |
| 756 | `simplebutton_childevents_sprite` | 13 | 6.6s |  |
| 757 | `simplebutton_childprops` | 144 | 6.8s |  |
| 758 | `simplebutton_childshuffle` | 23 | 6.5s |  |
| 759 | `simplebutton_constr` | 36 | 6.8s |  |
| 760 | `simplebutton_constr_childevents` | 48 | 6.9s |  |
| 761 | `simplebutton_constr_params` | 42 | 6.7s |  |
| 762 | `simplebutton_mouseenabled` | 26 | 6.6s |  |
| 763 | `simplebutton_multi_children` | 19 | 6.8s |  |
| 764 | `simplebutton_structure` | 27 | 6.8s |  |
| 765 | `simplebutton_symbolclass` | 68 | 7.0s |  |
| 766 | `slot_disp_id_shared_numbering` | 1 | 24.6s |  |
| 767 | `slots_force_autoassigned` | 1 | 6.7s |  |
| 768 | `socket_after_disconnect` | 1 | 6.7s |  |
| 769 | `socket_close` | 2 | 6.6s |  |
| 770 | `socket_connect` | 4 | 6.7s |  |
| 771 | `socket_errors` | 56 | 7.2s |  |
| 772 | `socket_read_big` | 48 | 39.6s |  |
| 773 | `socket_read_little` | 48 | 3.0s |  |
| 774 | `socket_read_write_object` | 8 | 6.5s |  |
| 775 | `socket_write_big` | 15 | 6.8s |  |
| 776 | `socket_write_little` | 14 | 6.5s |  |
| 777 | `sound_embeddedprops` | 26 | 6.8s |  |
| 778 | `sound_play` | 19 | 6.8s |  |
| 779 | `sound_valueof` | 33 | 6.6s |  |
| 780 | `soundchannel_soundtransform` | 835 | 26.9s |  |
| 781 | `soundchannel_soundtransform_exists` | 5 | 25.0s |  |
| 782 | `soundchannel_stop` | 8 | 25.2s |  |
| 783 | `soundmixer_buffertime` | 5 | 6.5s |  |
| 784 | `soundmixer_stopall` | 6 | 25.0s |  |
| 785 | `soundtransform` | 442 | 12.2s |  |
| 786 | `sprite_with_frames` | 0 | 25.4s |  |
| 787 | `stage3d_agal_cross_product` | 0 | 9.2s |  |
| 788 | `stage3d_agal_upload_errors` | 66 | 9.2s |  |
| 789 | `stage3d_bitmap` | 0 | 30.2s |  |
| 790 | `stage3d_blend` | 81 | 29.3s |  |
| 791 | `stage3d_context3d_string_args` | 158 | 7.5s |  |
| 792 | `stage3d_errors` | 7 | 6.6s |  |
| 793 | `stage3d_errors_atf` | 3 | 7.9s |  |
| 794 | `stage3d_errors_swf_29` | 6 | 6.8s |  |
| 795 | `stage3d_float1_index` | 0 | 27.7s |  |
| 796 | `stage3d_fractal` | 0 | 28.0s |  |
| 797 | `stage3d_ignore_sampler_override` | 0 | 28.0s |  |
| 798 | `stage3d_multistage_triangle` | 3 | 9.5s |  |
| 799 | `stage3d_program_constants_bytearray_be` | 0 | 29.2s |  |
| 800 | `stage3d_program_constants_bytearray_le` | 0 | 9.9s |  |
| 801 | `stage3d_program_constants_invalid_input` | 21 | 7.5s |  |
| 802 | `stage3d_raytrace` | 0 | 31.6s |  |
| 803 | `stage3d_rotating_cube` | 0 | 10.1s |  |
| 804 | `stage3d_sampler` | 0 | 25.3s |  |
| 805 | `stage3d_sampler_partial_upload` | 0 | 9.9s |  |
| 806 | `stage3d_stencil` | 0 | 30.9s |  |
| 807 | `stage3d_texture` | 0 | 14.9s |  |
| 808 | `stage3d_texture_bytearray` | 0 | 11.2s |  |
| 809 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.6s |  |
| 810 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.6s |  |
| 811 | `stage3d_triangle` | 0 | 9.9s |  |
| 812 | `stage3d_triangle_bytes4` | 0 | 9.8s |  |
| 813 | `stage3d_triangle_float1` | 0 | 9.7s |  |
| 814 | `stage3d_triangle_index_upload` | 0 | 9.6s |  |
| 815 | `stage3d_x_y` | 22 | 6.9s |  |
| 816 | `stage_access` | 10 | 6.9s |  |
| 817 | `stage_displayobject_properties` | 24 | 6.9s |  |
| 818 | `stage_framerate_nan` | 7 | 26.8s |  |
| 819 | `stage_framerate_negative` | 6 | 7.0s |  |
| 820 | `stage_framerate_zero` | 6 | 7.1s |  |
| 821 | `stage_invalidate` | 38 | 7.2s |  |
| 822 | `stage_loaderinfo_properties` | 24 | 26.4s |  |
| 823 | `stage_mousechildren` | 2 | 7.0s |  |
| 824 | `stage_mouseenabled` | 15 | 6.8s |  |
| 825 | `stage_overriden_setters` | 31 | 7.0s |  |
| 826 | `stage_properties` | 30 | 6.9s |  |
| 827 | `stage_stage3Ds_vector` | 1 | 26.1s |  |
| 828 | `static_var_with_this_in_ctor` | 2 | 7.0s |  |
| 829 | `stored_properties` | 11 | 6.9s |  |
| 830 | `strict_equality` | 34 | 7.0s |  |
| 831 | `string_call` | 13 | 6.8s |  |
| 832 | `string_case` | 23 | 6.8s |  |
| 833 | `string_char_at` | 27 | 6.9s |  |
| 834 | `string_char_code_at` | 28 | 6.8s |  |
| 835 | `string_concat_fromcharcode` | 37 | 6.8s |  |
| 836 | `string_constr` | 25 | 6.9s |  |
| 837 | `string_indexof_lastindexof` | 87 | 39.8s |  |
| 838 | `string_length` | 16 | 6.6s |  |
| 839 | `string_locale_compare` | 39 | 6.8s |  |
| 840 | `string_match` | 51 | 6.9s |  |
| 841 | `string_relational_compare` | 4 | 6.6s |  |
| 842 | `string_replace` | 51 | 6.8s |  |
| 843 | `string_search` | 41 | 6.7s |  |
| 844 | `string_slice_substr_substring` | 170 | 7.7s |  |
| 845 | `string_split` | 29 | 6.6s |  |
| 846 | `string_substr_negative` | 21 | 6.5s |  |
| 847 | `string_substr_weird` | 182 | 6.5s |  |
| 848 | `subtract` | 1058 | 18.7s |  |
| 849 | `super_get_call` | 12 | 6.6s |  |
| 850 | `supercall_two_classobjects` | 2 | 6.6s |  |
| 851 | `swf8` | 1 | 6.5s |  |
| 852 | `swf_10_queued_goto_scripts_construct` | 52 | 25.6s |  |
| 853 | `swf_9_goto_in_enter_frame` | 17 | 6.6s |  |
| 854 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.6s |  |
| 855 | `swf_9_queued_goto_scripts` | 6 | 25.3s |  |
| 856 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 857 | `swf_9_versioning` | 2 | 6.5s |  |
| 858 | `swf_wrong_frame_count` | 38 | 6.8s |  |
| 859 | `swf_wrong_frame_count_isplaying` | 22 | 24.8s |  |
| 860 | `symbol_class_binary_data` | 8 | 6.5s |  |
| 861 | `symbol_class_conflict` | 4 | 7.0s |  |
| 862 | `symbol_class_root_not_zero` | 1 | 6.4s |  |
| 863 | `symbolclass_invalid_utf8` | 2 | 6.5s |  |
| 864 | `tab_ordering_automatic_advanced` | 184 | 6.7s |  |
| 865 | `tab_ordering_automatic_basic` | 45 | 24.5s |  |
| 866 | `tab_ordering_children` | 116 | 6.2s |  |
| 867 | `tab_ordering_custom_basic` | 34 | 6.0s |  |
| 868 | `tab_ordering_stage_tab_children` | 32 | 6.1s |  |
| 869 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.0s |  |
| 870 | `tab_ordering_tabbable` | 47 | 6.2s |  |
| 871 | `text_engine_fontdescription` | 27 | 6.2s |  |
| 872 | `text_run` | 7 | 5.8s |  |
| 873 | `textbox_click` | 37 | 24.6s |  |
| 874 | `textfield_event` | 66 | 6.3s |  |
| 875 | `textfield_focusin_event` | 9 | 6.0s |  |
| 876 | `textfield_input_dead_keys_windows` | 15 | 6.0s |  |
| 877 | `textfield_unload` | 39 | 24.4s |  |
| 878 | `textformat` | 1134 | 6.2s |  |
| 879 | `textformat_display` | 14 | 6.0s |  |
| 880 | `textformat_font_max_length` | 4 | 6.0s |  |
| 881 | `throw` | 3 | 6.0s |  |
| 882 | `timeline_scripts` | 3 | 6.1s |  |
| 883 | `timer` | 90 | 7.1s |  |
| 884 | `timer_events` | 3 | 6.1s |  |
| 885 | `timer_finished` | 11 | 6.2s |  |
| 886 | `timer_reset` | 8 | 6.2s |  |
| 887 | `timer_setdelay` | 5 | 6.2s |  |
| 888 | `trace` | 12 | 6.0s |  |
| 889 | `truthiness` | 30 | 20.8s |  |
| 890 | `try_catch` | 11 | 5.8s |  |
| 891 | `try_catch_typed` | 12 | 5.8s |  |
| 892 | `typeof` | 30 | 5.8s |  |
| 893 | `uint_constr` | 92 | 5.9s |  |
| 894 | `uint_tofixed` | 1215 | 5.7s |  |
| 895 | `uint_tostring` | 3375 | 6.0s |  |
| 896 | `unchecked_function` | 15 | 5.7s |  |
| 897 | `unescape` | 28 | 5.8s |  |
| 898 | `url_loader` | 25 | 5.8s |  |
| 899 | `urlrequest` | 18 | 25.0s |  |
| 900 | `urlstream_basic` | 5 | 5.8s |  |
| 901 | `urshift` | 1058 | 17.1s |  |
| 902 | `vector_class` | 36 | 6.3s |  |
| 903 | `vector_class_call` | 11 | 6.0s |  |
| 904 | `vector_coercion` | 66 | 6.5s |  |
| 905 | `vector_concat` | 90 | 6.3s |  |
| 906 | `vector_constr` | 107 | 6.3s |  |
| 907 | `vector_enumeration` | 5 | 5.7s |  |
| 908 | `vector_every` | 92 | 6.6s |  |
| 909 | `vector_filter` | 95 | 6.5s |  |
| 910 | `vector_holes` | 24 | 5.7s |  |
| 911 | `vector_indexof` | 302 | 10.1s |  |
| 912 | `vector_insertat` | 270 | 6.8s |  |
| 913 | `vector_int_access` | 4 | 5.7s |  |
| 914 | `vector_int_delete` | 11 | 5.7s |  |
| 915 | `vector_join` | 58 | 6.1s |  |
| 916 | `vector_lastindexof` | 302 | 5.6s |  |
| 917 | `vector_legacy` | 10 | 5.7s |  |
| 918 | `vector_map` | 85 | 6.5s |  |
| 919 | `vector_object_final` | 1 | 5.7s |  |
| 920 | `vector_object_toString` | 10 | 5.8s |  |
| 921 | `vector_pushpop` | 255 | 7.0s |  |
| 922 | `vector_reborrow_bug` | 10 | 39.6s |  |
| 923 | `vector_removeat` | 172 | 7.7s |  |
| 924 | `vector_reverse` | 232 | 7.7s |  |
| 925 | `vector_shiftunshift` | 252 | 7.9s |  |
| 926 | `vector_slice` | 331 | 8.3s |  |
| 927 | `vector_sort` | 905 | 16.1s |  |
| 928 | `vector_splice` | 693 | 10.6s |  |
| 929 | `vector_splice_fixed_bug_compat` | 4 | 6.7s |  |
| 930 | `vector_tostring` | 79 | 7.2s |  |
| 931 | `verification` | 8 | 6.7s |  |
| 932 | `verify_abnormal_loop` | 1 | 6.4s |  |
| 933 | `verify_dxns_without_flag` | 3 | 6.8s |  |
| 934 | `verify_exception_targets_edge_case` | 1 | 6.5s |  |
| 935 | `verify_jump_to_middle_of_op` | 1 | 6.4s |  |
| 936 | `verify_lookup_switch_edge_case` | 1 | 6.4s |  |
| 937 | `verify_stack` | 5 | 6.6s |  |
| 938 | `verify_unreachable_exception` | 2 | 6.5s |  |
| 939 | `versioned_isplaying` | 2 | 6.5s |  |
| 940 | `virtual_properties` | 16 | 6.6s |  |
| 941 | `with` | 4 | 6.5s |  |
| 942 | `wrong_arg_count` | 7 | 6.7s |  |
| 943 | `xml_abstract_equality` | 36 | 6.8s |  |
| 944 | `xml_advanced` | 52 | 6.6s |  |
| 945 | `xml_appendchild` | 10 | 6.5s |  |
| 946 | `xml_as_attribute` | 9 | 6.5s |  |
| 947 | `xml_attribute` | 35 | 6.7s |  |
| 948 | `xml_attribute_name` | 40 | 6.5s |  |
| 949 | `xml_basic` | 33 | 6.8s |  |
| 950 | `xml_child` | 25 | 6.6s |  |
| 951 | `xml_childindex` | 7 | 6.5s |  |
| 952 | `xml_children` | 43 | 7.1s |  |
| 953 | `xml_class_call` | 9 | 6.5s |  |
| 954 | `xml_contains` | 197 | 6.7s |  |
| 955 | `xml_copy` | 20 | 43.1s |  |
| 956 | `xml_ctor_from_tostring` | 23 | 7.5s |  |
| 957 | `xml_delete` | 114 | 7.3s |  |
| 958 | `xml_descendants` | 83 | 7.2s |  |
| 959 | `xml_elements` | 6 | 7.1s |  |
| 960 | `xml_equals_namespace_check` | 2 | 7.2s |  |
| 961 | `xml_explicit_use_namespace` | 5 | 7.3s |  |
| 962 | `xml_getdescendants_qname` | 21 | 7.2s |  |
| 963 | `xml_has_property_via_in` | 26 | 7.2s |  |
| 964 | `xml_hasownproperty` | 6 | 7.1s |  |
| 965 | `xml_ignore_white` | 6 | 7.2s |  |
| 966 | `xml_length` | 2 | 7.2s |  |
| 967 | `xml_list_as_attribute` | 9 | 7.1s |  |
| 968 | `xml_list_concat` | 20 | 7.2s |  |
| 969 | `xml_list_enumerate` | 4 | 7.0s |  |
| 970 | `xml_methods_settings` | 3 | 7.2s |  |
| 971 | `xml_mismatched_tag` | 37 | 7.1s |  |
| 972 | `xml_namespace` | 39 | 7.1s |  |
| 973 | `xml_namespace_methods` | 245 | 7.2s |  |
| 974 | `xml_namespaced_property` | 7 | 7.2s |  |
| 975 | `xml_no_namespace` | 1 | 7.1s |  |
| 976 | `xml_nodekind` | 3 | 7.2s |  |
| 977 | `xml_normalize` | 35 | 7.2s |  |
| 978 | `xml_notification_bubbling` | 361 | 7.2s |  |
| 979 | `xml_parent` | 8 | 7.2s |  |
| 980 | `xml_set_children` | 17 | 7.2s |  |
| 981 | `xml_set_name` | 34 | 7.1s |  |
| 982 | `xml_settings` | 6 | 3.4s |  |
| 983 | `xml_simple_complex_content` | 47 | 7.1s |  |
| 984 | `xml_socket` | 11 | 7.4s |  |
| 985 | `xml_text` | 7 | 7.1s |  |
| 986 | `xml_tostring` | 6 | 7.2s |  |
| 987 | `xml_tostring_namespace` | 12 | 7.1s |  |
| 988 | `xml_unescaping` | 23 | 7.2s |  |
| 989 | `xml_weird_ignores` | 54 | 7.2s |  |
| 990 | `xml_wildcard` | 11 | 7.1s |  |
| 991 | `xmldocument` | 254 | 7.3s |  |
| 992 | `xmlnode` | 3540 | 7.3s |  |
| 993 | `zero_frame_clip` | 3 | 7.8s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.8s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 24.2s |  |
| 3 | `blend_transform` | 1 | 1 | 6.7s |  |
| 4 | `coerce_property` | 3 | 3 | 7.0s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.9s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 25.6s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.5s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 40.2s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.6s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.2s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.3s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 6.5s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 25.8s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 26.8s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.7s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.7s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.8s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.4s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 24.7s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.0s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.8s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.6s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 25.7s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.9s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.9s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 24.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**57 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 5 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 6 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 7 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 8 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 9 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 10 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 13 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 14 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 15 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 16 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 17 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 18 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 19 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 22 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 23 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 24 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 25 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 26 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 27 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 28 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 29 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 30 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 31 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 32 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 33 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 34 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 35 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 36 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 37 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 38 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 39 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 40 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 41 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 42 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 43 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 44 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 46 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 47 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 48 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 49 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 50 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 51 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 52 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 53 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 54 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 56 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 57 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.8s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.8s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.4s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**199 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 5 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 6 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 7 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 8 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 9 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 10 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 13 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 14 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 15 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 16 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 17 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 18 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 19 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 22 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 23 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 24 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 25 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 26 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 27 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 28 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 29 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 30 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 31 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 32 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 33 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 34 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 35 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 36 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 37 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 38 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 39 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 40 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 41 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 42 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 43 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 44 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 46 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 47 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 48 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 49 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 50 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 51 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 52 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 53 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 57 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 58 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 59 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 60 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 61 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 62 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 63 | `matrix3d` | 33.3% | 19/57 | 22 | 57 |  |
| 64 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 65 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 66 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 67 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 68 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 69 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 70 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 71 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 72 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 73 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 74 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 75 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 76 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 77 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 78 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 79 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 80 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 81 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 82 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 83 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 84 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 85 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 86 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 87 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 88 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 89 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 90 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 91 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 92 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 93 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 94 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 95 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 96 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 97 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 98 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 99 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 100 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 101 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 102 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 103 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 104 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 105 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 106 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 107 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 108 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 109 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 110 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 111 | `all_classes/display/swf9` | 0.1% | 2/1959 | 315 | 1959 |  |
| 112 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 113 | `all_classes/events/swf9` | 0.1% | 1/1030 | 178 | 1030 |  |
| 114 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 115 | `all_classes/events/swf10` | 0.1% | 1/1638 | 178 | 1638 |  |
| 116 | `all_classes/events/swf11` | 0.1% | 1/1750 | 178 | 1750 |  |
| 117 | `all_classes/events/swf12` | 0.1% | 1/1814 | 178 | 1814 |  |
| 118 | `all_classes/events/swf30` | 0.0% | 1/2353 | 178 | 2353 |  |
| 119 | `all_classes/display/swf10` | 0.0% | 1/2569 | 315 | 2569 |  |
| 120 | `all_classes/display/swf11` | 0.0% | 1/2593 | 315 | 2593 |  |
| 121 | `all_classes/display/swf12` | 0.0% | 1/2593 | 315 | 2593 |  |
| 122 | `all_classes/display/swf13` | 0.0% | 1/2671 | 315 | 2671 |  |
| 123 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 124 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 125 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 126 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 127 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 128 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 129 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 130 | `all_classes/display/swf30` | 0.0% | 0/2936 | 315 | 2936 |  |
| 131 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 132 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 133 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 134 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 135 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 136 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 137 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 138 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 139 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 140 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 141 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 142 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 143 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 144 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 145 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 146 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 147 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 148 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 149 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 150 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 151 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 152 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 153 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 154 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 155 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 156 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 157 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 158 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 159 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 160 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 161 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 162 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 163 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 164 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 165 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 166 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 167 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 168 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 169 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 170 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 171 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 172 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 173 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 174 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 175 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 176 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 177 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 178 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 179 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 180 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 181 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 182 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 183 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 184 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 185 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 186 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 187 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 188 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 189 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 190 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 191 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 192 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 193 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 194 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 195 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 196 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 197 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 198 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 199 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
