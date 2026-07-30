# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 18:36 UTC

**Git SHA**: `2358a37b1c`

**Run Duration**: 182m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1222 |
| Passing | **1000** (81.8%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1026** (84.0%) |
| Failing | 196 |
| Total expected lines | 151259 |
| Matching lines | 116130 (76.8%) |
| Mismatched lines | 35129 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 193 | 98.5% |
| Runtime Error | 3 | 1.5% |

## Passing Tests

**1000 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.4s |  |
| 2 | `agal_compiler` | 13 | 9.6s |  |
| 3 | `air_datagram_socket` | 1 | 8.0s |  |
| 4 | `air_hidden_lookup` | 2 | 7.3s |  |
| 5 | `all_classes/security/swf11` | 3 | 7.2s |  |
| 6 | `amf_array_serialization` | 17 | 9.3s |  |
| 7 | `amf_custom_obj` | 26 | 7.4s |  |
| 8 | `amf_dictionary` | 9 | 7.4s |  |
| 9 | `amf_function` | 46 | 7.4s |  |
| 10 | `amf_invalid_date` | 2 | 7.5s |  |
| 11 | `amf_missing_prop` | 6 | 7.4s |  |
| 12 | `amf_nondynamic_function_prop` | 6 | 6.9s |  |
| 13 | `amf_setter_error` | 8 | 7.0s |  |
| 14 | `amf_vector` | 40 | 7.1s |  |
| 15 | `amf_xml` | 6 | 6.9s |  |
| 16 | `application_domain` | 4 | 7.0s |  |
| 17 | `array_access` | 18 | 7.0s |  |
| 18 | `array_access_interpreter` | 4 | 7.0s |  |
| 19 | `array_access_no_pubns` | 2 | 6.9s |  |
| 20 | `array_concat` | 41 | 6.9s |  |
| 21 | `array_constr` | 10 | 6.8s |  |
| 22 | `array_delete` | 44 | 7.0s |  |
| 23 | `array_enumeration` | 10 | 7.0s |  |
| 24 | `array_enumeration_elements` | 11 | 6.9s |  |
| 25 | `array_every` | 8 | 6.9s |  |
| 26 | `array_filter` | 6 | 6.9s |  |
| 27 | `array_foreach` | 18 | 6.9s |  |
| 28 | `array_hasownproperty` | 11 | 3.0s |  |
| 29 | `array_holes` | 9 | 6.9s |  |
| 30 | `array_index_max` | 84 | 6.9s |  |
| 31 | `array_indexof` | 25 | 7.0s |  |
| 32 | `array_join` | 26 | 7.0s |  |
| 33 | `array_lastindexof` | 29 | 7.0s |  |
| 34 | `array_length` | 14 | 7.0s |  |
| 35 | `array_literal` | 3 | 7.0s |  |
| 36 | `array_map` | 8 | 6.8s |  |
| 37 | `array_pop` | 52 | 7.0s |  |
| 38 | `array_push` | 24 | 6.9s |  |
| 39 | `array_reborrow_bug` | 6 | 6.9s |  |
| 40 | `array_reverse` | 28 | 7.0s |  |
| 41 | `array_shift` | 51 | 3.2s |  |
| 42 | `array_slice` | 39 | 7.0s |  |
| 43 | `array_some` | 8 | 7.0s |  |
| 44 | `array_sort` | 297 | 7.4s |  |
| 45 | `array_sort_fun_swf12` | 2 | 7.0s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 47 | `array_sort_random` | 210 | 7.0s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 6.9s |  |
| 49 | `array_sorton` | 545 | 7.8s |  |
| 50 | `array_sparse_ops` | 41 | 7.1s |  |
| 51 | `array_splice` | 133 | 7.2s |  |
| 52 | `array_splice2` | 428 | 7.2s |  |
| 53 | `array_splice_types` | 48 | 7.1s |  |
| 54 | `array_storage` | 8 | 7.0s |  |
| 55 | `array_tolocalestring` | 9 | 7.0s |  |
| 56 | `array_tostring` | 12 | 7.0s |  |
| 57 | `array_unshift` | 24 | 7.0s |  |
| 58 | `array_valueof` | 9 | 6.9s |  |
| 59 | `array_vector_null_callback` | 10 | 6.9s |  |
| 60 | `astype` | 28 | 7.0s |  |
| 61 | `astypelate` | 24 | 7.1s |  |
| 62 | `astypelate_propagates` | 1 | 6.9s |  |
| 63 | `asymmetric_key_events` | 11 | 7.0s |  |
| 64 | `av_networking_params` | 9 | 7.0s |  |
| 65 | `avm2_catchup_dobj` | 158 | 7.5s |  |
| 66 | `away3d_advanced_shallow_water_demo` | 0 | 81.0s |  |
| 67 | `bevel_filter` | 187 | 7.2s |  |
| 68 | `bitand` | 1058 | 19.2s |  |
| 69 | `bitmap_constr` | 17 | 7.2s |  |
| 70 | `bitmap_data` | 1000 | 15.2s |  |
| 71 | `bitmap_pixelsnapping` | 2 | 26.0s |  |
| 72 | `bitmap_properties` | 23 | 7.1s |  |
| 73 | `bitmap_subclass` | 7 | 8.4s |  |
| 74 | `bitmap_subclass_properties` | 9 | 7.5s |  |
| 75 | `bitmap_timeline` | 9 | 7.1s |  |
| 76 | `bitmapdata_accuracy` | 1 | 43.2s |  |
| 77 | `bitmapdata_applyfilter_blur` | 0 | 26.5s |  |
| 78 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.8s |  |
| 79 | `bitmapdata_applyfilter_destpoint` | 0 | 26.2s |  |
| 80 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.5s |  |
| 81 | `bitmapdata_clone` | 13 | 7.3s |  |
| 82 | `bitmapdata_colortransform` | 0 | 7.5s |  |
| 83 | `bitmapdata_colortransform_oob` | 2 | 7.0s |  |
| 84 | `bitmapdata_constr` | 22 | 3.1s |  |
| 85 | `bitmapdata_constructor_from_timeline` | 1 | 7.2s |  |
| 86 | `bitmapdata_copychannel` | 0 | 29.4s |  |
| 87 | `bitmapdata_copypixels` | 23 | 27.9s |  |
| 88 | `bitmapdata_copypixels_blend_over` | 1 | 7.2s |  |
| 89 | `bitmapdata_copypixelstobytearray` | 39 | 7.1s |  |
| 90 | `bitmapdata_dispose` | 7 | 7.2s |  |
| 91 | `bitmapdata_draw` | 0 | 27.1s |  |
| 92 | `bitmapdata_draw_colortransform` | 0 | 7.4s |  |
| 93 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.6s |  |
| 94 | `bitmapdata_draw_filters` | 0 | 26.1s |  |
| 95 | `bitmapdata_draw_masks` | 0 | 7.1s |  |
| 96 | `bitmapdata_draw_rotation` | 0 | 7.4s |  |
| 97 | `bitmapdata_draw_self_via_graphic` | 0 | 7.5s |  |
| 98 | `bitmapdata_draw_stage` | 0 | 26.3s |  |
| 99 | `bitmapdata_drawwithquality` | 0 | 7.5s |  |
| 100 | `bitmapdata_embedded` | 9 | 7.6s |  |
| 101 | `bitmapdata_fillrect` | 0 | 7.4s |  |
| 102 | `bitmapdata_filter_sourcerect` | 0 | 22.9s |  |
| 103 | `bitmapdata_floodfill` | 35 | 7.1s |  |
| 104 | `bitmapdata_getpixels` | 39 | 26.4s |  |
| 105 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 106 | `bitmapdata_histogram` | 59 | 3.1s |  |
| 107 | `bitmapdata_hittest` | 112 | 7.8s |  |
| 108 | `bitmapdata_hittest_threshold` | 18 | 7.2s |  |
| 109 | `bitmapdata_opaque` | 0 | 7.4s |  |
| 110 | `bitmapdata_pixeldissolve` | 1037 | 7.8s |  |
| 111 | `bitmapdata_pixeldissolve_image` | 0 | 7.6s |  |
| 112 | `bitmapdata_rectangle_rounding` | 16 | 7.3s |  |
| 113 | `bitmapdata_setpixels` | 286 | 7.4s |  |
| 114 | `bitmapdata_setvector` | 26 | 7.2s |  |
| 115 | `bitmapdata_sync` | 0 | 26.1s |  |
| 116 | `bitmapdata_threshold` | 176 | 7.8s |  |
| 117 | `bitnot` | 46 | 7.0s |  |
| 118 | `bitor` | 1058 | 19.0s |  |
| 119 | `bitxor` | 1058 | 19.3s |  |
| 120 | `blend_multiply_alpha` | 0 | 7.3s |  |
| 121 | `blend_scroll` | 0 | 7.4s |  |
| 122 | `blend_shader_luma_lighten` | 3 | 7.9s |  |
| 123 | `blur_filter` | 43 | 7.2s |  |
| 124 | `boolean_constr` | 32 | 7.1s |  |
| 125 | `boolean_negation` | 30 | 7.0s |  |
| 126 | `boolean_tostring` | 8 | 7.0s |  |
| 127 | `broadcast_event` | 7 | 7.2s |  |
| 128 | `button_nested_frame` | 48 | 28.5s |  |
| 129 | `bytearray` | 48 | 7.8s |  |
| 130 | `bytearray_compress` | 31 | 7.5s |  |
| 131 | `bytearray_errors` | 24 | 7.7s |  |
| 132 | `bytearray_method_serialization` | 1 | 7.3s |  |
| 133 | `bytearray_oom` | 3 | 7.2s |  |
| 134 | `bytearray_readobject_amf0` | 50 | 7.3s |  |
| 135 | `bytearray_readobject_amf3` | 53 | 7.3s |  |
| 136 | `bytearray_readutf8bytes_with_bom` | 16 | 7.4s |  |
| 137 | `bytearray_serialization` | 3 | 7.5s |  |
| 138 | `bytearray_string_null` | 19 | 7.8s |  |
| 139 | `bytearray_tostring` | 15 | 7.4s |  |
| 140 | `bytearray_utf16` | 8 | 7.2s |  |
| 141 | `bytearray_writeobject` | 24 | 7.3s |  |
| 142 | `callee_in_initializer` | 6 | 7.3s |  |
| 143 | `callproplex_class` | 1 | 7.3s |  |
| 144 | `capabilities_resolution` | 8 | 27.6s |  |
| 145 | `catch_class` | 6 | 7.2s |  |
| 146 | `catch_scope_slot` | 7 | 3.2s |  |
| 147 | `checkfilter` | 4 | 3.1s |  |
| 148 | `class_call` | 32 | 7.2s |  |
| 149 | `class_cast_call` | 14 | 7.2s |  |
| 150 | `class_enumeration` | 4 | 7.0s |  |
| 151 | `class_has_own_property` | 2 | 7.0s |  |
| 152 | `class_init_interpreter_mode` | 1 | 6.9s |  |
| 153 | `class_is` | 32 | 7.0s |  |
| 154 | `class_methods` | 5 | 7.0s |  |
| 155 | `class_object_properties` | 10 | 6.9s |  |
| 156 | `class_singleton` | 18 | 7.0s |  |
| 157 | `class_supercalls_errors` | 35 | 7.2s |  |
| 158 | `class_supercalls_mismatched` | 26 | 7.1s |  |
| 159 | `class_superclass_wrong_order` | 1 | 25.9s |  |
| 160 | `class_to_locale_string` | 2 | 7.2s |  |
| 161 | `class_to_string` | 2 | 7.1s |  |
| 162 | `class_value_of` | 2 | 7.2s |  |
| 163 | `click_block` | 5 | 8.0s |  |
| 164 | `click_invisible` | 3 | 7.4s |  |
| 165 | `closures` | 12 | 7.2s |  |
| 166 | `coerce_return_type` | 40 | 7.3s |  |
| 167 | `coerce_return_type_fail` | 2 | 7.1s |  |
| 168 | `coerce_return_void` | 3 | 7.1s |  |
| 169 | `coerce_string` | 86 | 7.3s |  |
| 170 | `coerce_string_precision` | 28 | 7.2s |  |
| 171 | `coerce_to_primitive_side_effects` | 29 | 7.2s |  |
| 172 | `color_matrix_filter` | 19 | 7.3s |  |
| 173 | `construct_errors_swf10` | 8 | 7.3s |  |
| 174 | `construct_frame_list` | 22 | 26.2s |  |
| 175 | `construct_interface` | 3 | 7.2s |  |
| 176 | `constructor_call` | 3 | 7.2s |  |
| 177 | `constructors_vs_timeline` | 5 | 26.4s |  |
| 178 | `constructprop_dynamic_primitive` | 7 | 7.3s |  |
| 179 | `context3d_creation` | 9 | 7.3s |  |
| 180 | `control_flow_bool` | 4 | 7.2s |  |
| 181 | `control_flow_stricteq` | 8 | 7.2s |  |
| 182 | `convert_boolean` | 30 | 7.2s |  |
| 183 | `convert_integer` | 90 | 7.3s |  |
| 184 | `convert_number` | 56 | 7.3s |  |
| 185 | `convert_uinteger` | 90 | 7.4s |  |
| 186 | `convolution_filter` | 89 | 7.4s |  |
| 187 | `cpool_index_invalid_bytecode_1` | 6 | 7.2s |  |
| 188 | `cpool_index_invalid_bytecode_2` | 3 | 7.2s |  |
| 189 | `cpool_index_invalid_bytecode_3` | 1 | 7.1s |  |
| 190 | `cross_api_version_call_older` | 12 | 7.7s |  |
| 191 | `cryptscore` | 11 | 7.5s |  |
| 192 | `date` | 30 | 7.7s |  |
| 193 | `date_parse` | 36 | 7.4s |  |
| 194 | `declocal` | 46 | 7.4s |  |
| 195 | `declocal_i` | 46 | 7.5s |  |
| 196 | `decode_uri` | 71 | 7.7s |  |
| 197 | `decrement` | 46 | 7.4s |  |
| 198 | `decrement_i` | 46 | 3.3s |  |
| 199 | `default_values` | 7 | 7.4s |  |
| 200 | `dictionary_access` | 62 | 7.6s |  |
| 201 | `dictionary_access_no_pubns` | 2 | 7.3s |  |
| 202 | `dictionary_delete` | 101 | 7.7s |  |
| 203 | `dictionary_foreach` | 42 | 7.6s |  |
| 204 | `dictionary_hasownproperty` | 63 | 7.6s |  |
| 205 | `dictionary_in` | 62 | 7.6s |  |
| 206 | `dictionary_iter_modify` | 8 | 7.3s |  |
| 207 | `dictionary_namespaces` | 36 | 7.4s |  |
| 208 | `dictionary_primitive_keys` | 29 | 7.4s |  |
| 209 | `displacement_map_filter` | 61 | 7.4s |  |
| 210 | `displayobject_alpha` | 277 | 7.4s |  |
| 211 | `displayobject_blendmode` | 0 | 7.4s |  |
| 212 | `displayobject_colortransform_nested` | 0 | 26.9s |  |
| 213 | `displayobject_filters` | 17 | 7.5s |  |
| 214 | `displayobject_from_enterframe` | 1 | 26.6s |  |
| 215 | `displayobject_getbounds_shape` | 0 | 26.7s |  |
| 216 | `displayobject_height` | 6052 | 27.3s |  |
| 217 | `displayobject_hittestobject` | 32 | 7.5s |  |
| 218 | `displayobject_invalid_floats` | 60 | 7.5s |  |
| 219 | `displayobject_invalid_props` | 3 | 3.4s |  |
| 220 | `displayobject_mask` | 3 | 7.7s |  |
| 221 | `displayobject_mask_self_referential` | 0 | 6.1s |  |
| 222 | `displayobject_metaData` | 3 | 5.8s |  |
| 223 | `displayobject_name` | 22 | 6.3s |  |
| 224 | `displayobject_name_from_timeline` | 24 | 6.5s |  |
| 225 | `displayobject_parent` | 12 | 6.3s |  |
| 226 | `displayobject_root` | 24 | 6.7s |  |
| 227 | `displayobject_rotation` | 1284 | 6.7s |  |
| 228 | `displayobject_set_matrix_nested` | 0 | 23.7s |  |
| 229 | `displayobject_set_name_loaded` | 3 | 6.5s |  |
| 230 | `displayobject_subclass` | 2 | 6.1s |  |
| 231 | `displayobject_visible` | 23 | 6.1s |  |
| 232 | `displayobject_width` | 4852 | 23.3s |  |
| 233 | `displayobject_x` | 614 | 6.2s |  |
| 234 | `displayobject_y` | 617 | 5.9s |  |
| 235 | `displayobjectcontainer_addchild` | 32 | 6.4s |  |
| 236 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.1s |  |
| 237 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.3s |  |
| 238 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.0s |  |
| 239 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.1s |  |
| 240 | `displayobjectcontainer_addchildat` | 42 | 6.2s |  |
| 241 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 2.5s |  |
| 242 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.2s |  |
| 243 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.2s |  |
| 244 | `displayobjectcontainer_contains` | 66 | 24.0s |  |
| 245 | `displayobjectcontainer_getchildat` | 4 | 6.2s |  |
| 246 | `displayobjectcontainer_getchildbyname` | 9 | 6.0s |  |
| 247 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.2s |  |
| 248 | `displayobjectcontainer_getchildindex` | 28 | 6.2s |  |
| 249 | `displayobjectcontainer_removechild` | 10 | 6.1s |  |
| 250 | `displayobjectcontainer_removechild_errors` | 4 | 6.0s |  |
| 251 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.2s |  |
| 252 | `displayobjectcontainer_removechildat` | 18 | 5.8s |  |
| 253 | `displayobjectcontainer_removechildren` | 51 | 6.2s |  |
| 254 | `displayobjectcontainer_setchildindex` | 42 | 5.9s |  |
| 255 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.2s |  |
| 256 | `displayobjectcontainer_swapchildren` | 42 | 5.8s |  |
| 257 | `displayobjectcontainer_swapchildrenat` | 42 | 6.0s |  |
| 258 | `displayobjectcontainer_timelineinstance` | 48 | 26.0s |  |
| 259 | `divide` | 1058 | 18.3s |  |
| 260 | `doabc_is_eager` | 1 | 25.5s |  |
| 261 | `documentclass` | 9 | 7.3s |  |
| 262 | `domain_memory` | 133 | 8.2s |  |
| 263 | `drag_drop` | 10 | 7.4s |  |
| 264 | `drop_shadow_filter` | 172 | 7.3s |  |
| 265 | `duplicate_defs` | 1 | 7.0s |  |
| 266 | `eager_init` | 1 | 7.1s |  |
| 267 | `edit_text_linkage` | 7 | 7.3s |  |
| 268 | `edittext_align` | 60 | 7.6s |  |
| 269 | `edittext_always_show_selection` | 0 | 26.3s |  |
| 270 | `edittext_antialiastype` | 296 | 7.4s |  |
| 271 | `edittext_at_point_methods_basic` | 16 | 8.5s |  |
| 272 | `edittext_autosize` | 39 | 7.5s |  |
| 273 | `edittext_autosize_align` | 0 | 26.4s |  |
| 274 | `edittext_autosize_height_dynamic` | 60 | 26.4s |  |
| 275 | `edittext_autosize_height_input` | 60 | 7.3s |  |
| 276 | `edittext_autosize_lazy_bounds_events` | 65 | 7.5s |  |
| 277 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.2s |  |
| 278 | `edittext_autosize_lazy_bounds_props` | 490 | 8.6s |  |
| 279 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.0s |  |
| 280 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.4s |  |
| 281 | `edittext_bottom_scroll_v_basic` | 210 | 7.3s |  |
| 282 | `edittext_bounds_scale` | 24 | 25.7s |  |
| 283 | `edittext_bullet` | 30 | 7.3s |  |
| 284 | `edittext_default_format` | 221 | 7.5s |  |
| 285 | `edittext_default_format_empty` | 136 | 7.5s |  |
| 286 | `edittext_empty_text_format` | 7 | 7.2s |  |
| 287 | `edittext_focus_selection` | 5 | 7.2s |  |
| 288 | `edittext_font_size` | 45 | 7.3s |  |
| 289 | `edittext_format_empty_font` | 8 | 7.1s |  |
| 290 | `edittext_get_char_index_at_point` | 4 | 27.2s |  |
| 291 | `edittext_get_line_index_at_point` | 2 | 26.3s |  |
| 292 | `edittext_get_line_index_of_char` | 76 | 8.1s |  |
| 293 | `edittext_getcharboundaries` | 172 | 7.6s |  |
| 294 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.2s |  |
| 295 | `edittext_getcharboundaries_scroll` | 85 | 4.9s |  |
| 296 | `edittext_getlinemetrics` | 146 | 4.9s |  |
| 297 | `edittext_html` | 3101 | 5.0s |  |
| 298 | `edittext_html_condensewhite` | 487 | 4.8s |  |
| 299 | `edittext_html_entity` | 4 | 5.0s |  |
| 300 | `edittext_html_font_size_swf12` | 267 | 5.0s |  |
| 301 | `edittext_html_font_size_swf13` | 273 | 4.9s |  |
| 302 | `edittext_html_roundtrip` | 17 | 4.8s |  |
| 303 | `edittext_ime_focus_lost` | 9 | 17.1s |  |
| 304 | `edittext_input_control` | 12 | 4.9s |  |
| 305 | `edittext_leading` | 9 | 5.0s |  |
| 306 | `edittext_letter_spacing` | 15 | 4.8s |  |
| 307 | `edittext_line_methods` | 294 | 5.8s |  |
| 308 | `edittext_line_metrics` | 11 | 17.9s |  |
| 309 | `edittext_margins` | 25 | 4.8s |  |
| 310 | `edittext_max_scroll_h_basic` | 475 | 5.0s |  |
| 311 | `edittext_max_scroll_v_basic` | 1000 | 4.7s |  |
| 312 | `edittext_mouse_selection` | 363 | 17.3s |  |
| 313 | `edittext_mousedown` | 3 | 4.9s |  |
| 314 | `edittext_mouseenabled` | 26 | 5.0s |  |
| 315 | `edittext_newline_character` | 22 | 4.7s |  |
| 316 | `edittext_newline_stripping` | 64 | 6.4s |  |
| 317 | `edittext_newlines` | 30 | 4.8s |  |
| 318 | `edittext_paragraph_methods` | 257 | 5.0s |  |
| 319 | `edittext_paste_events` | 8 | 4.7s |  |
| 320 | `edittext_paste_maxchars` | 4 | 4.7s |  |
| 321 | `edittext_paste_restrict` | 16 | 4.6s |  |
| 322 | `edittext_restrict` | 191 | 4.8s |  |
| 323 | `edittext_restrict_events` | 22 | 4.7s |  |
| 324 | `edittext_scrollh` | 10 | 2.1s |  |
| 325 | `edittext_selected_text` | 9 | 4.8s |  |
| 326 | `edittext_set_html_same` | 17 | 4.9s |  |
| 327 | `edittext_set_text_vs_html` | 9 | 4.9s |  |
| 328 | `edittext_stylesheet` | 536 | 5.2s |  |
| 329 | `edittext_stylesheet_custom_tag` | 76 | 4.8s |  |
| 330 | `edittext_stylesheet_display` | 272 | 5.0s |  |
| 331 | `edittext_underline` | 40 | 5.1s |  |
| 332 | `edittext_width_height` | 103 | 10.1s |  |
| 333 | `edittext_wordwrap_word` | 150 | 7.4s |  |
| 334 | `edittext_wrap_breaks` | 2375 | 7.5s |  |
| 335 | `empty_bounds` | 1 | 6.9s |  |
| 336 | `encode_uri_surrogate_pair_swf11` | 15 | 6.7s |  |
| 337 | `equals` | 512 | 11.1s |  |
| 338 | `error_geterrormessage` | 779 | 7.2s |  |
| 339 | `error_prototype` | 15 | 7.3s |  |
| 340 | `error_stack_trace_debug_swf17` | 0 | 26.0s |  |
| 341 | `error_stack_trace_debug_swf18` | 0 | 6.8s |  |
| 342 | `error_stack_trace_release_swf17` | 0 | 6.8s |  |
| 343 | `error_stack_trace_release_swf18` | 0 | 6.7s |  |
| 344 | `error_tostring` | 29 | 6.9s |  |
| 345 | `es3_inheritance` | 31 | 7.0s |  |
| 346 | `es4_inheritance` | 30 | 7.0s |  |
| 347 | `es4_interfaces` | 30 | 7.1s |  |
| 348 | `es4_method_binding` | 8 | 7.0s |  |
| 349 | `es4_oop_prototypes` | 14 | 7.2s |  |
| 350 | `es4_protected_inheritance` | 6 | 7.0s |  |
| 351 | `escape` | 71 | 7.1s |  |
| 352 | `event_bubbles` | 2 | 7.2s |  |
| 353 | `event_cancelable` | 2 | 7.2s |  |
| 354 | `event_clone` | 20 | 7.2s |  |
| 355 | `event_clone_error_redispatch` | 3 | 7.3s |  |
| 356 | `event_clone_on_redispatch` | 10 | 7.4s |  |
| 357 | `event_formattostring` | 31 | 7.3s |  |
| 358 | `event_isdefaultprevented` | 12 | 7.2s |  |
| 359 | `event_target_getter` | 5 | 3.2s |  |
| 360 | `event_target_set` | 9 | 7.1s |  |
| 361 | `event_type` | 1 | 10.5s |  |
| 362 | `event_valueof_tostring` | 18 | 7.7s |  |
| 363 | `eventdispatcher_dispatchevent` | 12 | 7.7s |  |
| 364 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.5s |  |
| 365 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.4s |  |
| 366 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.2s |  |
| 367 | `eventdispatcher_dispatchevent_this` | 5 | 7.2s |  |
| 368 | `eventdispatcher_haseventlistener` | 25 | 7.2s |  |
| 369 | `eventdispatcher_interface_invoke` | 1 | 7.2s |  |
| 370 | `eventdispatcher_tostring` | 10 | 7.2s |  |
| 371 | `eventdispatcher_willtrigger` | 25 | 7.1s |  |
| 372 | `falsiness` | 30 | 7.2s |  |
| 373 | `fast_index_access` | 12 | 7.3s |  |
| 374 | `filefilter_properties` | 4 | 7.2s |  |
| 375 | `filereference_browse_cancel` | 3 | 7.2s |  |
| 376 | `filereference_browse_select` | 9 | 7.2s |  |
| 377 | `filereference_load` | 31 | 3.3s |  |
| 378 | `filereference_save` | 16 | 7.3s |  |
| 379 | `filereference_save_and_browse` | 42 | 7.3s |  |
| 380 | `filereference_save_and_load` | 22 | 7.3s |  |
| 381 | `filereference_uninitialized` | 8 | 7.2s |  |
| 382 | `filereferencelist_browse_cancel` | 6 | 7.2s |  |
| 383 | `filereferencelist_browse_select` | 7 | 7.2s |  |
| 384 | `filter_rewind` | 8 | 7.5s |  |
| 385 | `filters_array_holes` | 25 | 7.4s |  |
| 386 | `finddef` | 3 | 7.6s |  |
| 387 | `findprop_global_prototype` | 6 | 7.6s |  |
| 388 | `flash_media_video_constructor` | 156 | 8.2s |  |
| 389 | `flash_xml` | 29 | 7.7s |  |
| 390 | `flash_xml_cloneNode` | 22 | 7.6s |  |
| 391 | `flash_xml_namespace` | 109 | 7.5s |  |
| 392 | `flash_xml_removeNode` | 60 | 7.3s |  |
| 393 | `focus_events_code` | 161 | 26.8s |  |
| 394 | `focus_events_key_basic` | 132 | 26.6s |  |
| 395 | `focus_events_key_navigation` | 53 | 7.4s |  |
| 396 | `focus_events_key_same_object` | 26 | 7.2s |  |
| 397 | `focus_events_mixed_key_mouse` | 100 | 26.4s |  |
| 398 | `focus_events_mouse_basic` | 260 | 30.1s |  |
| 399 | `focus_events_mouse_focusable` | 112 | 27.5s |  |
| 400 | `focus_events_mouse_same_object` | 40 | 26.7s |  |
| 401 | `focus_remove` | 20 | 26.3s |  |
| 402 | `focus_root_movie` | 4 | 26.5s |  |
| 403 | `focus_stage` | 1 | 7.3s |  |
| 404 | `focusrect` | 18 | 8.1s |  |
| 405 | `focusrect_focuslost` | 9 | 7.3s |  |
| 406 | `focusrect_property` | 110 | 7.4s |  |
| 407 | `font_description_clone` | 14 | 7.3s |  |
| 408 | `font_embedded` | 24 | 7.7s |  |
| 409 | `font_enumeratefonts` | 41 | 7.9s |  |
| 410 | `font_enumeratefonts_filter` | 4 | 26.9s |  |
| 411 | `font_hasglyphs` | 40 | 7.7s |  |
| 412 | `framelabel_constr` | 5 | 7.3s |  |
| 413 | `function_call` | 12 | 7.4s |  |
| 414 | `function_call_arguments` | 46 | 3.4s |  |
| 415 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 416 | `function_call_coercion` | 108 | 7.7s |  |
| 417 | `function_call_default` | 6 | 7.3s |  |
| 418 | `function_call_rest` | 22 | 7.3s |  |
| 419 | `function_call_types` | 3 | 7.4s |  |
| 420 | `function_call_via_apply` | 11 | 7.3s |  |
| 421 | `function_call_via_call` | 3 | 7.4s |  |
| 422 | `function_display_anonymous` | 7 | 3.3s |  |
| 423 | `function_length` | 6 | 7.4s |  |
| 424 | `function_object` | 2 | 7.4s |  |
| 425 | `function_proto` | 5 | 7.3s |  |
| 426 | `function_proto_created` | 61 | 7.5s |  |
| 427 | `function_to_locale_string` | 4 | 7.3s |  |
| 428 | `function_to_string` | 4 | 7.2s |  |
| 429 | `function_type` | 6 | 7.3s |  |
| 430 | `function_unbound_this` | 51 | 7.4s |  |
| 431 | `function_value_of` | 4 | 7.3s |  |
| 432 | `get_definition_by_name` | 11 | 7.2s |  |
| 433 | `get_qualified_class_name` | 20 | 9.7s |  |
| 434 | `get_qualified_super_class_name` | 18 | 6.9s |  |
| 435 | `get_slot_edge_cases` | 1 | 25.0s |  |
| 436 | `get_timer` | 2 | 6.9s |  |
| 437 | `getglobalslot` | 1 | 6.8s |  |
| 438 | `getouterscope` | 8 | 6.9s |  |
| 439 | `getter_different_namespace_setter` | 2 | 6.8s |  |
| 440 | `glow_filter` | 127 | 7.1s |  |
| 441 | `goto_button_nested_framescript` | 28 | 25.7s |  |
| 442 | `goto_in_constructframe` | 12 | 7.1s |  |
| 443 | `goto_in_scene_last_frame` | 2 | 25.1s |  |
| 444 | `goto_methods` | 56 | 7.1s |  |
| 445 | `goto_methods_swfver10` | 8 | 6.9s |  |
| 446 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 447 | `goto_nested_framescript` | 9 | 7.1s |  |
| 448 | `goto_on_orphan` | 15 | 7.1s |  |
| 449 | `gradient_bevel_filter` | 206 | 7.0s |  |
| 450 | `gradient_glow_filter` | 206 | 6.8s |  |
| 451 | `graphics_bad_direct_commands` | 5 | 7.6s |  |
| 452 | `graphics_bitmap_fill` | 0 | 8.7s |  |
| 453 | `graphics_bitmaps` | 0 | 7.6s |  |
| 454 | `graphics_direct_commands` | 0 | 7.5s |  |
| 455 | `graphics_draw_triangles` | 98 | 26.0s |  |
| 456 | `graphics_gradients` | 0 | 7.3s |  |
| 457 | `graphics_gradients_nulls` | 0 | 7.1s |  |
| 458 | `graphics_path` | 56 | 6.9s |  |
| 459 | `graphics_round_rects` | 0 | 6.9s |  |
| 460 | `graphics_simple_shapes` | 0 | 7.1s |  |
| 461 | `greaterequals` | 512 | 10.7s |  |
| 462 | `greaterthan` | 512 | 10.8s |  |
| 463 | `has_own_property` | 102 | 7.4s |  |
| 464 | `hasownproperty_namespaces` | 2 | 6.8s |  |
| 465 | `hello_world` | 1 | 6.8s |  |
| 466 | `hittest_morph` | 30 | 7.0s |  |
| 467 | `if_eq` | 10 | 6.9s |  |
| 468 | `if_gt` | 1 | 7.0s |  |
| 469 | `if_gte` | 10 | 10.1s |  |
| 470 | `if_lt` | 1 | 7.3s |  |
| 471 | `if_lte` | 10 | 7.1s |  |
| 472 | `if_ne` | 7 | 3.3s |  |
| 473 | `if_stricteq` | 6 | 7.2s |  |
| 474 | `if_strictne` | 11 | 7.2s |  |
| 475 | `ime_linux_dead_keys` | 10 | 7.3s |  |
| 476 | `in` | 102 | 7.6s |  |
| 477 | `inclocal` | 46 | 7.2s |  |
| 478 | `inclocal_i` | 46 | 7.2s |  |
| 479 | `increment` | 46 | 7.2s |  |
| 480 | `increment_i` | 46 | 7.2s |  |
| 481 | `indexing_delete` | 75 | 7.2s |  |
| 482 | `instanceof` | 58 | 7.4s |  |
| 483 | `instantiation_on_enter_frame` | 7 | 25.8s |  |
| 484 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.1s |  |
| 485 | `int_constr` | 92 | 7.1s |  |
| 486 | `int_edge_cases` | 19 | 7.2s |  |
| 487 | `int_instanceof` | 3 | 7.0s |  |
| 488 | `int_tofixed` | 1215 | 7.1s |  |
| 489 | `int_tostring` | 3375 | 7.1s |  |
| 490 | `interactiveobject_enabled` | 25 | 7.1s |  |
| 491 | `interface_namespaces` | 78 | 7.4s |  |
| 492 | `is_finite` | 46 | 7.2s |  |
| 493 | `is_nan` | 46 | 7.1s |  |
| 494 | `is_prototype_of` | 12 | 7.2s |  |
| 495 | `issue_10221` | 2 | 7.1s |  |
| 496 | `issue_13780` | 12 | 7.2s |  |
| 497 | `issue_14901` | 1 | 7.2s |  |
| 498 | `issue_17675_edittext_paste_maxchars` | 1 | 7.2s |  |
| 499 | `issue_5292` | 5 | 7.2s |  |
| 500 | `issue_8630` | 2 | 25.9s |  |
| 501 | `issue_8630_scriptremove` | 11 | 7.3s |  |
| 502 | `istype` | 24 | 3.4s |  |
| 503 | `istypelate` | 58 | 7.6s |  |
| 504 | `istypelate_coerce` | 198 | 11.1s |  |
| 505 | `jpeg_loader_context` | 6 | 7.3s |  |
| 506 | `json_errors` | 9 | 27.3s |  |
| 507 | `json_parse` | 21 | 7.4s |  |
| 508 | `json_stringify` | 12 | 7.6s |  |
| 509 | `json_stringify_order` | 1 | 7.1s |  |
| 510 | `json_version_gated` | 1 | 7.0s |  |
| 511 | `key_input_80percent` | 1812 | 7.2s |  |
| 512 | `key_input_location` | 126 | 7.0s |  |
| 513 | `key_input_numpad` | 384 | 6.9s |  |
| 514 | `lazyinit` | 17 | 7.2s |  |
| 515 | `lessequals` | 512 | 11.6s |  |
| 516 | `lessthan` | 512 | 11.4s |  |
| 517 | `loader_bitmap_transparency` | 14 | 7.3s |  |
| 518 | `loader_bytes_unknown_content` | 14 | 7.3s |  |
| 519 | `loader_child_getdefinition` | 5 | 7.4s |  |
| 520 | `loader_duplicate_coerce` | 3 | 7.4s |  |
| 521 | `loader_duplicate_coerce_new_domain` | 4 | 7.3s |  |
| 522 | `loader_error_in_root_ctor` | 4 | 7.5s |  |
| 523 | `loader_events` | 92 | 8.1s |  |
| 524 | `loader_image` | 8 | 7.7s |  |
| 525 | `loader_jpegxr` | 2 | 26.5s |  |
| 526 | `loader_jpegxr_alpha` | 1 | 26.8s |  |
| 527 | `loader_loadbytes_events` | 30 | 7.8s |  |
| 528 | `loader_loadbytes_invalid_png` | 4 | 25.9s |  |
| 529 | `loader_loadbytes_url` | 12 | 7.4s |  |
| 530 | `loader_loaderurl` | 6 | 7.5s |  |
| 531 | `loader_noninteractive_try_click_root` | 5 | 26.9s |  |
| 532 | `loader_reuse` | 38 | 7.3s |  |
| 533 | `loader_unknown_content` | 24 | 7.3s |  |
| 534 | `loader_visibility_interactive` | 1 | 7.4s |  |
| 535 | `loaderinfo_events` | 7 | 7.3s |  |
| 536 | `loaderinfo_loadurl` | 12 | 9.7s |  |
| 537 | `loaderinfo_more` | 6 | 7.3s |  |
| 538 | `loaderinfo_properties` | 18 | 7.1s |  |
| 539 | `loaderinfo_properties_not_loaded` | 23 | 7.1s |  |
| 540 | `loaderinfo_root` | 10 | 7.0s |  |
| 541 | `loaderinfo_root_allows` | 2 | 6.9s |  |
| 542 | `localconnection_send` | 4 | 6.9s |  |
| 543 | `lshift` | 1058 | 19.0s |  |
| 544 | `mask_reapply` | 1 | 7.0s |  |
| 545 | `math` | 497 | 7.2s |  |
| 546 | `matrix3d` | 57 | 7.7s |  |
| 547 | `matrix3d_compose` | 34 | 7.3s |  |
| 548 | `matrix3d_invert` | 18 | 3.1s |  |
| 549 | `missing_external_interface` | 10 | 7.1s |  |
| 550 | `modulo` | 1058 | 19.4s |  |
| 551 | `morph_shape` | 2 | 26.6s |  |
| 552 | `mouse_children` | 192 | 26.5s |  |
| 553 | `mouse_click_events` | 90 | 26.2s |  |
| 554 | `mouse_double_click_events` | 188 | 7.1s |  |
| 555 | `mouse_empty_parent` | 4 | 7.1s |  |
| 556 | `mouse_over_while_dragging` | 3 | 7.0s |  |
| 557 | `mouse_pick_button_mode` | 2 | 7.1s |  |
| 558 | `mouse_pick_dobj_mask` | 4 | 7.3s |  |
| 559 | `mouse_pick_masking` | 7 | 25.8s |  |
| 560 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 25.6s |  |
| 561 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.3s |  |
| 562 | `mouse_pick_text` | 8 | 7.1s |  |
| 563 | `mouse_sibling` | 8 | 7.0s |  |
| 564 | `mouse_wheel_events` | 36 | 26.7s |  |
| 565 | `mouseevent_constr` | 66 | 7.0s |  |
| 566 | `mouseevent_stagexy` | 35 | 7.0s |  |
| 567 | `mouseevent_valueof_tostring` | 28 | 7.0s |  |
| 568 | `movieclip_addframescript` | 3 | 25.6s |  |
| 569 | `movieclip_child_property` | 16 | 7.1s |  |
| 570 | `movieclip_constr` | 21 | 9.6s |  |
| 571 | `movieclip_currentlabels` | 17 | 25.5s |  |
| 572 | `movieclip_currentlabels_dupes1` | 46 | 25.6s |  |
| 573 | `movieclip_currentlabels_dupes2` | 30 | 6.9s |  |
| 574 | `movieclip_currentlabels_dupes3` | 67 | 7.0s |  |
| 575 | `movieclip_currentscene` | 12 | 7.0s |  |
| 576 | `movieclip_dispatchevent` | 430 | 7.1s |  |
| 577 | `movieclip_dispatchevent_cancel` | 102 | 7.1s |  |
| 578 | `movieclip_dispatchevent_handlerorder` | 251 | 7.0s |  |
| 579 | `movieclip_dispatchevent_selfadd` | 80 | 6.9s |  |
| 580 | `movieclip_dispatchevent_target` | 899 | 7.0s |  |
| 581 | `movieclip_displayevents` | 96 | 25.7s |  |
| 582 | `movieclip_displayevents_clickgoto` | 676 | 7.5s |  |
| 583 | `movieclip_displayevents_clickgoto2` | 2001 | 7.5s |  |
| 584 | `movieclip_displayevents_clickplay` | 575 | 7.2s |  |
| 585 | `movieclip_displayevents_clicksymbol` | 562 | 7.2s |  |
| 586 | `movieclip_displayevents_constructframegoto` | 140 | 7.4s |  |
| 587 | `movieclip_displayevents_constructframeplay` | 50 | 7.2s |  |
| 588 | `movieclip_displayevents_constructframesymbol` | 144 | 7.2s |  |
| 589 | `movieclip_displayevents_dblhandler` | 21 | 7.2s |  |
| 590 | `movieclip_displayevents_enterframegoto` | 149 | 7.2s |  |
| 591 | `movieclip_displayevents_enterframeplay` | 48 | 7.1s |  |
| 592 | `movieclip_displayevents_enterframesymbol` | 149 | 25.7s |  |
| 593 | `movieclip_displayevents_exitframegoto` | 106 | 7.1s |  |
| 594 | `movieclip_displayevents_exitframeplay` | 44 | 7.2s |  |
| 595 | `movieclip_displayevents_exitframesymbol` | 135 | 7.2s |  |
| 596 | `movieclip_displayevents_looping` | 63 | 26.4s |  |
| 597 | `movieclip_displayevents_stopped` | 113 | 7.5s |  |
| 598 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 599 | `movieclip_displayevents_timeline` | 128 | 26.8s |  |
| 600 | `movieclip_drawrect` | 54 | 7.3s |  |
| 601 | `movieclip_frameconstruct_skipped` | 9 | 7.2s |  |
| 602 | `movieclip_goto_during_frame_script` | 15 | 7.2s |  |
| 603 | `movieclip_goto_overwrite` | 14 | 25.6s |  |
| 604 | `movieclip_goto_scene_last_frame_int` | 1 | 25.9s |  |
| 605 | `movieclip_goto_scene_last_frame_label` | 1 | 3.0s |  |
| 606 | `movieclip_gotoandplay` | 15 | 25.4s |  |
| 607 | `movieclip_gotoandstop` | 13 | 25.2s |  |
| 608 | `movieclip_gotoandstop_children` | 4 | 7.1s |  |
| 609 | `movieclip_gotoandstop_framescripts1` | 4 | 7.0s |  |
| 610 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 611 | `movieclip_gotoandstop_framescripts_self` | 7 | 29.7s |  |
| 612 | `movieclip_gotoandstop_queueing` | 12 | 27.6s |  |
| 613 | `movieclip_next_frame` | 2 | 7.4s |  |
| 614 | `movieclip_next_scene` | 6 | 26.8s |  |
| 615 | `movieclip_play` | 3 | 3.3s |  |
| 616 | `movieclip_prev_frame` | 3 | 7.2s |  |
| 617 | `movieclip_prev_scene` | 7 | 7.4s |  |
| 618 | `movieclip_properties` | 79 | 7.7s |  |
| 619 | `movieclip_queued_noop_goto_swf10` | 9 | 7.3s |  |
| 620 | `movieclip_queued_noop_goto_swf9` | 7 | 1.4s |  |
| 621 | `movieclip_scenes` | 11 | 7.3s |  |
| 622 | `movieclip_soundtransform` | 831 | 28.8s |  |
| 623 | `movieclip_stop` | 1 | 7.3s |  |
| 624 | `movieclip_super_is_symbol` | 20 | 7.6s |  |
| 625 | `movieclip_symbol_constr` | 8 | 7.4s |  |
| 626 | `movieclip_text_mousedown` | 1 | 7.4s |  |
| 627 | `movieclip_willtrigger` | 5 | 7.4s |  |
| 628 | `multiply` | 1058 | 18.7s |  |
| 629 | `namespace_constr` | 253 | 7.6s |  |
| 630 | `namespace_constr_args` | 1 | 7.2s |  |
| 631 | `namespace_enumeration_order` | 7 | 7.3s |  |
| 632 | `nan_scale` | 9 | 7.2s |  |
| 633 | `navigateToURL_target_normalize` | 107 | 28.9s |  |
| 634 | `negate` | 30 | 7.4s |  |
| 635 | `negative_volume_panned` | 0 | 7.6s |  |
| 636 | `nested_iteration` | 11 | 7.2s |  |
| 637 | `net_getClassByAlias` | 3 | 7.2s |  |
| 638 | `net_navigateToURL` | 57 | 7.3s |  |
| 639 | `net_stream_play_options` | 6 | 7.3s |  |
| 640 | `netconnection_close` | 55 | 7.3s |  |
| 641 | `netconnection_properties` | 78 | 7.4s |  |
| 642 | `netconnection_send_remote` | 50 | 7.6s |  |
| 643 | `netconnection_serialize_arrays` | 6 | 7.4s |  |
| 644 | `netstream_client` | 10 | 7.5s |  |
| 645 | `netstream_connect` | 7 | 7.4s |  |
| 646 | `newactivation_in_script_init` | 3 | 7.3s |  |
| 647 | `newclass_twice` | 3 | 7.3s |  |
| 648 | `nonconflicting_declarations` | 0 | 7.4s |  |
| 649 | `null_void_types` | 8 | 7.5s |  |
| 650 | `number_autoconv` | 21 | 3.4s |  |
| 651 | `number_autoconv_amf` | 132 | 7.3s |  |
| 652 | `number_autoconv_array_sort_32bit` | 1 | 7.3s |  |
| 653 | `number_constr` | 58 | 7.5s |  |
| 654 | `number_toexponential` | 378 | 7.4s |  |
| 655 | `number_toexponential2` | 35 | 7.4s |  |
| 656 | `number_tofixed` | 378 | 7.4s |  |
| 657 | `number_toprecision` | 350 | 7.6s |  |
| 658 | `obfuscated_class_names` | 3 | 7.6s |  |
| 659 | `object_enumeration` | 10 | 7.5s |  |
| 660 | `object_prototype` | 4 | 7.5s |  |
| 661 | `object_to_locale_string` | 2 | 7.6s |  |
| 662 | `object_to_string` | 2 | 7.5s |  |
| 663 | `object_value_of` | 2 | 3.4s |  |
| 664 | `op_coerce` | 54 | 3.5s |  |
| 665 | `op_coerce_x` | 54 | 7.7s |  |
| 666 | `op_escxattr` | 2 | 7.6s |  |
| 667 | `op_escxelem` | 2 | 7.6s |  |
| 668 | `op_lookupswitch` | 4 | 7.6s |  |
| 669 | `optimize_coerce` | 1 | 7.6s |  |
| 670 | `orphan_movie_complex` | 80 | 8.0s |  |
| 671 | `orphan_movie_reorder` | 111 | 28.1s |  |
| 672 | `package_namespace` | 7 | 7.4s |  |
| 673 | `param_default_value_has_zero_cpool_index` | 1 | 7.5s |  |
| 674 | `parent_early_access_child` | 16 | 7.8s |  |
| 675 | `parse_float` | 81 | 7.9s |  |
| 676 | `perspective_projection_basic` | 40 | 7.5s |  |
| 677 | `pixelbender_ceil` | 77 | 7.7s |  |
| 678 | `pixelbender_conditional` | 138 | 7.2s |  |
| 679 | `pixelbender_conversions` | 270 | 5.0s |  |
| 680 | `pixelbender_dithering` | 8 | 22.8s |  |
| 681 | `pixelbender_div` | 36 | 5.5s |  |
| 682 | `pixelbender_effect_BlurredFocus` | 0 | 24.7s |  |
| 683 | `pixelbender_effect_glassDisplace` | 0 | 10.3s |  |
| 684 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 22.9s |  |
| 685 | `pixelbender_effect_smudge` | 0 | 8.0s |  |
| 686 | `pixelbender_effect_tintype` | 0 | 7.1s |  |
| 687 | `pixelbender_effect_twirl` | 0 | 8.1s |  |
| 688 | `pixelbender_eof` | 7 | 4.9s |  |
| 689 | `pixelbender_images` | 0 | 7.1s |  |
| 690 | `pixelbender_input` | 103 | 19.8s |  |
| 691 | `pixelbender_logicalnot` | 20 | 5.0s |  |
| 692 | `pixelbender_malformed_data` | 190 | 19.5s |  |
| 693 | `pixelbender_multiple_out_params` | 1 | 2.0s |  |
| 694 | `pixelbender_no_out_param` | 6 | 5.2s |  |
| 695 | `pixelbender_outputs` | 13 | 5.0s |  |
| 696 | `pixelbender_padding_bytes` | 22 | 4.9s |  |
| 697 | `pixelbender_param_qualifier` | 512 | 5.7s |  |
| 698 | `pixelbender_parameters` | 1563 | 5.3s |  |
| 699 | `pixelbender_parameters_bool` | 240 | 5.8s |  |
| 700 | `pixelbender_parameters_int_vs_bool` | 54 | 5.3s |  |
| 701 | `pixelbender_parse_errors` | 6 | 5.4s |  |
| 702 | `pixelbender_rsqrt` | 24 | 5.1s |  |
| 703 | `pixelbender_select_kinds` | 8 | 5.1s |  |
| 704 | `pixelbender_shaderdata` | 49 | 5.1s |  |
| 705 | `pixelbender_shaderdata_setter` | 99 | 5.7s |  |
| 706 | `pixelbender_sign` | 60 | 5.0s |  |
| 707 | `pixelbender_vector_output` | 11 | 5.1s |  |
| 708 | `place_multiple` | 17 | 19.5s |  |
| 709 | `place_object_replace` | 9 | 5.3s |  |
| 710 | `place_object_replace_2` | 24 | 5.6s |  |
| 711 | `place_object_same_depth_frame` | 1 | 5.2s |  |
| 712 | `point` | 132 | 5.3s |  |
| 713 | `primitive_edge_cases` | 1 | 5.0s |  |
| 714 | `property_priority` | 22 | 7.3s |  |
| 715 | `property_priority_three_level` | 6 | 25.6s |  |
| 716 | `propertyisenumerable_namespaces` | 6 | 7.0s |  |
| 717 | `prototype_set_null` | 7 | 7.0s |  |
| 718 | `proxy_callproperty` | 24 | 7.0s |  |
| 719 | `proxy_deleteproperty` | 64 | 7.1s |  |
| 720 | `proxy_enumeration` | 34 | 7.0s |  |
| 721 | `proxy_getproperty` | 77 | 7.2s |  |
| 722 | `proxy_hasownproperty` | 8 | 7.1s |  |
| 723 | `proxy_hasproperty` | 32 | 7.2s |  |
| 724 | `proxy_serialize` | 9 | 7.0s |  |
| 725 | `proxy_setproperty` | 42 | 7.1s |  |
| 726 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.1s |  |
| 727 | `qname_constr` | 32 | 7.1s |  |
| 728 | `qname_constr_namespace` | 24 | 7.1s |  |
| 729 | `qname_enumeration` | 9 | 7.1s |  |
| 730 | `qname_indexing` | 23 | 7.0s |  |
| 731 | `qname_tostring` | 25 | 7.1s |  |
| 732 | `qname_valueof` | 29 | 7.0s |  |
| 733 | `rectangle` | 1094 | 7.7s |  |
| 734 | `regexp_constr` | 148 | 7.2s |  |
| 735 | `regexp_exec` | 19 | 7.1s |  |
| 736 | `regexp_extended` | 47 | 7.2s |  |
| 737 | `regexp_multiargs` | 1 | 7.0s |  |
| 738 | `regexp_test` | 27 | 3.2s |  |
| 739 | `regexp_toString` | 10 | 7.0s |  |
| 740 | `register_script_refresh` | 35 | 7.4s |  |
| 741 | `remove_child_clear_field` | 88 | 7.4s |  |
| 742 | `remove_dobj` | 3 | 7.0s |  |
| 743 | `resolve_order` | 4 | 7.0s |  |
| 744 | `responder_null_callbacks` | 1 | 7.0s |  |
| 745 | `rng` | 1 | 8.3s |  |
| 746 | `rootless` | 42 | 7.2s |  |
| 747 | `rshift` | 1058 | 19.1s |  |
| 748 | `sandbox_type_inherited` | 2 | 7.4s |  |
| 749 | `sandbox_type_local_file` | 1 | 8.2s |  |
| 750 | `sandbox_type_local_network` | 1 | 5.6s |  |
| 751 | `scene_constr` | 8 | 5.8s |  |
| 752 | `selection` | 239 | 6.7s |  |
| 753 | `set_local_0` | 31 | 6.0s |  |
| 754 | `set_property_is_enumerable` | 85 | 6.2s |  |
| 755 | `shaderparameter_value` | 4 | 6.1s |  |
| 756 | `shape_drawrect` | 54 | 6.1s |  |
| 757 | `shared_object_no_root` | 3 | 5.9s |  |
| 758 | `simplebutton_added_to_stage` | 45 | 21.1s |  |
| 759 | `simplebutton_childevents` | 86 | 21.5s |  |
| 760 | `simplebutton_childevents_nested` | 54 | 6.2s |  |
| 761 | `simplebutton_childevents_sprite` | 13 | 6.2s |  |
| 762 | `simplebutton_childprops` | 144 | 6.4s |  |
| 763 | `simplebutton_childshuffle` | 23 | 5.8s |  |
| 764 | `simplebutton_constr` | 36 | 6.2s |  |
| 765 | `simplebutton_constr_childevents` | 48 | 6.2s |  |
| 766 | `simplebutton_constr_params` | 42 | 6.1s |  |
| 767 | `simplebutton_mouseenabled` | 26 | 5.9s |  |
| 768 | `simplebutton_multi_children` | 19 | 6.3s |  |
| 769 | `simplebutton_structure` | 27 | 6.5s |  |
| 770 | `simplebutton_symbolclass` | 68 | 6.4s |  |
| 771 | `slot_disp_id_shared_numbering` | 1 | 21.3s |  |
| 772 | `slots_force_autoassigned` | 1 | 6.1s |  |
| 773 | `socket_after_disconnect` | 1 | 6.0s |  |
| 774 | `socket_close` | 2 | 5.9s |  |
| 775 | `socket_connect` | 4 | 6.0s |  |
| 776 | `socket_errors` | 56 | 6.6s |  |
| 777 | `socket_read_big` | 48 | 5.9s |  |
| 778 | `socket_read_little` | 48 | 10.5s |  |
| 779 | `socket_read_write_object` | 8 | 7.3s |  |
| 780 | `socket_write_big` | 15 | 7.6s |  |
| 781 | `socket_write_little` | 14 | 7.5s |  |
| 782 | `sound_embeddedprops` | 26 | 7.5s |  |
| 783 | `sound_play` | 19 | 7.6s |  |
| 784 | `sound_valueof` | 33 | 7.6s |  |
| 785 | `soundchannel_soundtransform` | 835 | 29.2s |  |
| 786 | `soundchannel_soundtransform_exists` | 5 | 26.9s |  |
| 787 | `soundchannel_stop` | 8 | 7.6s |  |
| 788 | `soundmixer_buffertime` | 5 | 7.3s |  |
| 789 | `soundmixer_stopall` | 6 | 7.5s |  |
| 790 | `soundtransform` | 442 | 8.6s |  |
| 791 | `sprite_with_frames` | 0 | 27.2s |  |
| 792 | `stage3d_agal_cross_product` | 0 | 9.9s |  |
| 793 | `stage3d_agal_upload_errors` | 66 | 10.0s |  |
| 794 | `stage3d_bitmap` | 0 | 31.6s |  |
| 795 | `stage3d_blend` | 81 | 30.9s |  |
| 796 | `stage3d_context3d_string_args` | 158 | 8.3s |  |
| 797 | `stage3d_errors` | 7 | 7.4s |  |
| 798 | `stage3d_errors_atf` | 3 | 8.7s |  |
| 799 | `stage3d_errors_swf_29` | 6 | 7.5s |  |
| 800 | `stage3d_float1_index` | 0 | 28.7s |  |
| 801 | `stage3d_fractal` | 0 | 29.7s |  |
| 802 | `stage3d_ignore_sampler_override` | 0 | 29.3s |  |
| 803 | `stage3d_multistage_triangle` | 3 | 10.1s |  |
| 804 | `stage3d_program_constants_bytearray_be` | 0 | 30.3s |  |
| 805 | `stage3d_program_constants_bytearray_le` | 0 | 10.8s |  |
| 806 | `stage3d_program_constants_invalid_input` | 21 | 8.2s |  |
| 807 | `stage3d_raytrace` | 0 | 32.8s |  |
| 808 | `stage3d_rotating_cube` | 0 | 11.1s |  |
| 809 | `stage3d_sampler` | 0 | 10.4s |  |
| 810 | `stage3d_sampler_partial_upload` | 0 | 10.9s |  |
| 811 | `stage3d_stencil` | 0 | 24.8s |  |
| 812 | `stage3d_texture` | 0 | 12.0s |  |
| 813 | `stage3d_texture_bytearray` | 0 | 9.1s |  |
| 814 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.5s |  |
| 815 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.3s |  |
| 816 | `stage3d_triangle` | 0 | 7.8s |  |
| 817 | `stage3d_triangle_bytes4` | 0 | 7.9s |  |
| 818 | `stage3d_triangle_float1` | 0 | 7.7s |  |
| 819 | `stage3d_triangle_index_upload` | 0 | 7.8s |  |
| 820 | `stage3d_x_y` | 22 | 5.7s |  |
| 821 | `stage_access` | 10 | 2.6s |  |
| 822 | `stage_displayobject_properties` | 24 | 5.8s |  |
| 823 | `stage_framerate_nan` | 7 | 2.5s |  |
| 824 | `stage_framerate_negative` | 6 | 5.7s |  |
| 825 | `stage_framerate_zero` | 6 | 5.8s |  |
| 826 | `stage_invalidate` | 38 | 6.3s |  |
| 827 | `stage_loaderinfo_properties` | 24 | 6.2s |  |
| 828 | `stage_mousechildren` | 2 | 5.6s |  |
| 829 | `stage_mouseenabled` | 15 | 5.6s |  |
| 830 | `stage_overriden_setters` | 31 | 5.9s |  |
| 831 | `stage_properties` | 30 | 5.7s |  |
| 832 | `stage_stage3Ds_vector` | 1 | 21.6s |  |
| 833 | `static_var_with_this_in_ctor` | 2 | 5.6s |  |
| 834 | `stored_properties` | 11 | 5.8s |  |
| 835 | `strict_equality` | 34 | 5.9s |  |
| 836 | `string_call` | 13 | 5.6s |  |
| 837 | `string_case` | 23 | 5.6s |  |
| 838 | `string_char_at` | 27 | 5.6s |  |
| 839 | `string_char_code_at` | 28 | 5.5s |  |
| 840 | `string_concat_fromcharcode` | 37 | 5.6s |  |
| 841 | `string_constr` | 25 | 6.0s |  |
| 842 | `string_indexof_lastindexof` | 87 | 5.8s |  |
| 843 | `string_length` | 16 | 10.3s |  |
| 844 | `string_locale_compare` | 39 | 7.8s |  |
| 845 | `string_match` | 51 | 7.8s |  |
| 846 | `string_relational_compare` | 4 | 7.5s |  |
| 847 | `string_replace` | 51 | 7.7s |  |
| 848 | `string_search` | 41 | 7.6s |  |
| 849 | `string_slice_substr_substring` | 170 | 8.6s |  |
| 850 | `string_split` | 29 | 7.5s |  |
| 851 | `string_substr_negative` | 21 | 7.3s |  |
| 852 | `string_substr_weird` | 182 | 7.5s |  |
| 853 | `subtract` | 1058 | 19.4s |  |
| 854 | `super_get_call` | 12 | 7.6s |  |
| 855 | `supercall_two_classobjects` | 2 | 7.7s |  |
| 856 | `swf8` | 1 | 7.6s |  |
| 857 | `swf_10_queued_goto_scripts_construct` | 52 | 8.0s |  |
| 858 | `swf_9_goto_in_enter_frame` | 17 | 7.5s |  |
| 859 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.5s |  |
| 860 | `swf_9_queued_goto_scripts` | 6 | 7.5s |  |
| 861 | `swf_9_queued_goto_scripts_construct` | 28 | 1.5s |  |
| 862 | `swf_9_versioning` | 2 | 7.4s |  |
| 863 | `swf_wrong_frame_count` | 38 | 7.7s |  |
| 864 | `swf_wrong_frame_count_isplaying` | 22 | 26.4s |  |
| 865 | `symbol_class_binary_data` | 8 | 7.3s |  |
| 866 | `symbol_class_conflict` | 4 | 7.8s |  |
| 867 | `symbol_class_root_not_zero` | 1 | 7.3s |  |
| 868 | `symbolclass_invalid_utf8` | 2 | 7.4s |  |
| 869 | `tab_ordering_automatic_advanced` | 184 | 31.2s |  |
| 870 | `tab_ordering_automatic_basic` | 45 | 7.0s |  |
| 871 | `tab_ordering_children` | 116 | 7.2s |  |
| 872 | `tab_ordering_custom_basic` | 34 | 6.9s |  |
| 873 | `tab_ordering_stage_tab_children` | 32 | 7.0s |  |
| 874 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.0s |  |
| 875 | `tab_ordering_tabbable` | 47 | 7.2s |  |
| 876 | `text_engine_fontdescription` | 27 | 7.2s |  |
| 877 | `text_run` | 7 | 6.8s |  |
| 878 | `textbox_click` | 37 | 26.3s |  |
| 879 | `textfield_event` | 66 | 7.0s |  |
| 880 | `textfield_focusin_event` | 9 | 6.9s |  |
| 881 | `textfield_input_dead_keys_windows` | 15 | 6.7s |  |
| 882 | `textfield_unload` | 39 | 25.8s |  |
| 883 | `textformat` | 1134 | 6.9s |  |
| 884 | `textformat_display` | 14 | 6.9s |  |
| 885 | `textformat_font_max_length` | 4 | 2.7s |  |
| 886 | `throw` | 3 | 6.8s |  |
| 887 | `timeline_scripts` | 3 | 6.8s |  |
| 888 | `timer` | 90 | 7.8s |  |
| 889 | `timer_events` | 3 | 6.8s |  |
| 890 | `timer_finished` | 11 | 3.1s |  |
| 891 | `timer_reset` | 8 | 7.0s |  |
| 892 | `timer_setdelay` | 5 | 7.2s |  |
| 893 | `trace` | 12 | 6.7s |  |
| 894 | `truthiness` | 30 | 5.9s |  |
| 895 | `try_catch` | 11 | 4.0s |  |
| 896 | `try_catch_typed` | 12 | 0.7s |  |
| 897 | `typeof` | 30 | 0.7s |  |
| 898 | `uint_constr` | 92 | 0.8s |  |
| 899 | `uint_tofixed` | 1215 | 0.8s |  |
| 900 | `uint_tostring` | 3375 | 1.8s |  |
| 901 | `unchecked_function` | 15 | 0.7s |  |
| 902 | `unescape` | 28 | 0.7s |  |
| 903 | `url_loader` | 25 | 0.7s |  |
| 904 | `urlrequest` | 18 | 0.7s |  |
| 905 | `urlstream_basic` | 5 | 0.7s |  |
| 906 | `urshift` | 1058 | 0.8s |  |
| 907 | `utils3d` | 7 | 0.7s |  |
| 908 | `vector3d` | 397 | 0.7s |  |
| 909 | `vector_class` | 36 | 0.8s |  |
| 910 | `vector_class_call` | 11 | 0.7s |  |
| 911 | `vector_coercion` | 66 | 1.0s |  |
| 912 | `vector_concat` | 90 | 0.7s |  |
| 913 | `vector_constr` | 107 | 0.8s |  |
| 914 | `vector_enumeration` | 5 | 0.7s |  |
| 915 | `vector_every` | 92 | 0.8s |  |
| 916 | `vector_filter` | 95 | 0.7s |  |
| 917 | `vector_holes` | 24 | 0.7s |  |
| 918 | `vector_indexof` | 302 | 0.7s |  |
| 919 | `vector_insertat` | 270 | 0.8s |  |
| 920 | `vector_int_access` | 4 | 0.8s |  |
| 921 | `vector_int_delete` | 11 | 0.8s |  |
| 922 | `vector_join` | 58 | 0.8s |  |
| 923 | `vector_lastindexof` | 302 | 0.7s |  |
| 924 | `vector_legacy` | 10 | 0.8s |  |
| 925 | `vector_map` | 85 | 0.8s |  |
| 926 | `vector_object_final` | 1 | 0.8s |  |
| 927 | `vector_object_toString` | 10 | 0.7s |  |
| 928 | `vector_pushpop` | 255 | 0.8s |  |
| 929 | `vector_reborrow_bug` | 10 | 0.7s |  |
| 930 | `vector_removeat` | 172 | 11.2s |  |
| 931 | `vector_reverse` | 232 | 8.4s |  |
| 932 | `vector_shiftunshift` | 252 | 7.2s |  |
| 933 | `vector_slice` | 331 | 8.9s |  |
| 934 | `vector_sort` | 905 | 15.9s |  |
| 935 | `vector_splice` | 693 | 10.8s |  |
| 936 | `vector_splice_fixed_bug_compat` | 4 | 7.3s |  |
| 937 | `vector_tostring` | 79 | 7.8s |  |
| 938 | `verification` | 8 | 7.4s |  |
| 939 | `verify_abnormal_loop` | 1 | 7.2s |  |
| 940 | `verify_dxns_without_flag` | 3 | 7.5s |  |
| 941 | `verify_exception_targets_edge_case` | 1 | 7.2s |  |
| 942 | `verify_jump_to_middle_of_op` | 1 | 7.2s |  |
| 943 | `verify_lookup_switch_edge_case` | 1 | 7.1s |  |
| 944 | `verify_stack` | 5 | 7.2s |  |
| 945 | `verify_unreachable_exception` | 2 | 7.2s |  |
| 946 | `versioned_isplaying` | 2 | 7.2s |  |
| 947 | `virtual_properties` | 16 | 7.3s |  |
| 948 | `with` | 4 | 7.2s |  |
| 949 | `wrong_arg_count` | 7 | 7.3s |  |
| 950 | `xml_abstract_equality` | 36 | 7.4s |  |
| 951 | `xml_advanced` | 52 | 7.2s |  |
| 952 | `xml_appendchild` | 10 | 7.2s |  |
| 953 | `xml_as_attribute` | 9 | 7.1s |  |
| 954 | `xml_attribute` | 35 | 7.4s |  |
| 955 | `xml_attribute_name` | 40 | 7.2s |  |
| 956 | `xml_basic` | 33 | 7.3s |  |
| 957 | `xml_child` | 25 | 7.3s |  |
| 958 | `xml_childindex` | 7 | 7.2s |  |
| 959 | `xml_children` | 43 | 7.8s |  |
| 960 | `xml_class_call` | 9 | 7.3s |  |
| 961 | `xml_contains` | 197 | 7.3s |  |
| 962 | `xml_copy` | 20 | 3.3s |  |
| 963 | `xml_ctor_from_tostring` | 23 | 9.9s |  |
| 964 | `xml_delete` | 114 | 7.1s |  |
| 965 | `xml_descendants` | 83 | 7.0s |  |
| 966 | `xml_elements` | 6 | 6.9s |  |
| 967 | `xml_equals_namespace_check` | 2 | 6.8s |  |
| 968 | `xml_explicit_use_namespace` | 5 | 7.0s |  |
| 969 | `xml_getdescendants_qname` | 21 | 6.9s |  |
| 970 | `xml_has_property_via_in` | 26 | 7.0s |  |
| 971 | `xml_hasownproperty` | 6 | 6.9s |  |
| 972 | `xml_ignore_white` | 6 | 6.9s |  |
| 973 | `xml_length` | 2 | 6.9s |  |
| 974 | `xml_list_as_attribute` | 9 | 6.9s |  |
| 975 | `xml_list_concat` | 20 | 6.9s |  |
| 976 | `xml_list_enumerate` | 4 | 6.8s |  |
| 977 | `xml_methods_settings` | 3 | 6.9s |  |
| 978 | `xml_mismatched_tag` | 37 | 7.0s |  |
| 979 | `xml_namespace` | 39 | 3.0s |  |
| 980 | `xml_namespace_methods` | 245 | 7.0s |  |
| 981 | `xml_namespaced_property` | 7 | 6.9s |  |
| 982 | `xml_no_namespace` | 1 | 6.8s |  |
| 983 | `xml_nodekind` | 3 | 6.9s |  |
| 984 | `xml_normalize` | 35 | 7.0s |  |
| 985 | `xml_notification_bubbling` | 361 | 6.9s |  |
| 986 | `xml_parent` | 8 | 6.9s |  |
| 987 | `xml_set_children` | 17 | 7.0s |  |
| 988 | `xml_set_name` | 34 | 6.9s |  |
| 989 | `xml_settings` | 6 | 3.0s |  |
| 990 | `xml_simple_complex_content` | 47 | 6.9s |  |
| 991 | `xml_socket` | 11 | 7.1s |  |
| 992 | `xml_text` | 7 | 6.9s |  |
| 993 | `xml_tostring` | 6 | 6.9s |  |
| 994 | `xml_tostring_namespace` | 12 | 6.9s |  |
| 995 | `xml_unescaping` | 23 | 7.0s |  |
| 996 | `xml_weird_ignores` | 54 | 7.0s |  |
| 997 | `xml_wildcard` | 11 | 7.0s |  |
| 998 | `xmldocument` | 254 | 7.0s |  |
| 999 | `xmlnode` | 3540 | 7.1s |  |
| 1000 | `zero_frame_clip` | 3 | 7.4s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.8s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.9s |  |
| 3 | `blend_transform` | 1 | 1 | 7.3s |  |
| 4 | `coerce_property` | 3 | 3 | 7.3s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 3.3s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 7.6s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.4s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 18.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 5.2s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.0s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 7.3s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 7.3s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 25.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 26.1s |  |
| 15 | `int_toexponential` | 76 | 76 | 7.1s |  |
| 16 | `int_toprecision` | 441 | 441 | 7.1s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.1s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.9s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 21.0s |  |
| 20 | `soundchannel_position` | 74 | 74 | 27.7s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 7.6s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 7.4s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 27.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 0.7s |  |
| 25 | `uint_toprecision` | 433 | 433 | 0.8s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 25.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**60 tests** within reach

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
| 12 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 14 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 15 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 16 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 17 | `place_and_lookup/swf10` | 90.9% | 30 | 33 | 3 |  |
| 18 | `place_and_lookup/swf9` | 90.9% | 30 | 33 | 3 |  |
| 19 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 22 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 23 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 24 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 25 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 26 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 27 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 28 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 29 | `flash_media_video_setter` | 82.5% | 33 | 40 | 7 |  |
| 30 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 31 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 32 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 33 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 34 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 35 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 36 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 37 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 38 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 39 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 40 | `flash_media_video_rotation_probe` | 74.1% | 20 | 27 | 7 |  |
| 41 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 42 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 43 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 44 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 45 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 46 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 47 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
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

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.8s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.9s |  |
| 3 | `verify_typecheck` | exit code 1 | 3.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**193 tests** with output mismatch, sorted by match rate (best first)

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
| 12 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 14 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 15 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 16 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 17 | `place_and_lookup/swf10` | 90.9% | 30/33 | 33 | 33 |  |
| 18 | `place_and_lookup/swf9` | 90.9% | 30/33 | 33 | 33 |  |
| 19 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 22 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 23 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 24 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 25 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 26 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 27 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 28 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 29 | `flash_media_video_setter` | 82.5% | 33/40 | 40 | 40 |  |
| 30 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 31 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 32 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 33 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 34 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 35 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 36 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 37 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 38 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 39 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 40 | `flash_media_video_rotation_probe` | 74.1% | 20/27 | 27 | 27 |  |
| 41 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 42 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 43 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 44 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 45 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 46 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 47 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 48 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
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
| 61 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 62 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 63 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 64 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 65 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 66 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 67 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 68 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 69 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 70 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 71 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 72 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 73 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 74 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 75 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 76 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 77 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 78 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 79 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 80 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 81 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 82 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 83 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 84 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 85 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 86 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 87 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 88 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 89 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 90 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 91 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 92 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 93 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 94 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 95 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 96 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 97 | `textline_validity` | 4.3% | 7/162 | 7 | 162 |  |
| 98 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 99 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 100 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 101 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 102 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 103 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 104 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 105 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 106 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 107 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 108 | `all_classes/display/swf9` | 0.1% | 2/1959 | 350 | 1959 |  |
| 109 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 110 | `all_classes/events/swf9` | 0.1% | 1/1030 | 184 | 1030 |  |
| 111 | `all_classes/events/swf30` | 0.1% | 2/2353 | 184 | 2353 |  |
| 112 | `all_classes/display/swf10` | 0.1% | 2/2569 | 350 | 2569 |  |
| 113 | `all_classes/display/swf11` | 0.1% | 2/2593 | 350 | 2593 |  |
| 114 | `all_classes/display/swf12` | 0.1% | 2/2593 | 350 | 2593 |  |
| 115 | `all_classes/display/swf13` | 0.1% | 2/2671 | 350 | 2671 |  |
| 116 | `all_classes/events/swf10` | 0.1% | 1/1638 | 184 | 1638 |  |
| 117 | `all_classes/events/swf11` | 0.1% | 1/1750 | 184 | 1750 |  |
| 118 | `all_classes/events/swf12` | 0.1% | 1/1814 | 184 | 1814 |  |
| 119 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 120 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 121 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 122 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 123 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 124 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 125 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 126 | `all_classes/display/swf30` | 0.0% | 0/2936 | 350 | 2936 |  |
| 127 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 128 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 129 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 130 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 131 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 132 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 133 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 134 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 135 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 136 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 137 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 138 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 139 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 140 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 141 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 142 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 143 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 144 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 145 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 146 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 147 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 148 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 149 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 150 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 151 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 152 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 153 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 154 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 155 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 156 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 157 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 158 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 159 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 160 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 161 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 162 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 163 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 164 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 165 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 166 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 167 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 168 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 169 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 170 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 171 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 172 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 173 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 174 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 175 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 176 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 177 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 178 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 179 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 180 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 181 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 182 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 183 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 184 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 185 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 186 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 187 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 188 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 189 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 190 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 191 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 192 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 193 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
