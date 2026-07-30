# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 08:52 UTC

**Git SHA**: `c045e044c6`

**Run Duration**: 171m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **979** (80.2%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1005** (82.3%) |
| Failing | 216 |
| Total expected lines | 151253 |
| Matching lines | 111911 (74.0%) |
| Mismatched lines | 39342 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 213 | 98.6% |
| Runtime Error | 3 | 1.4% |

## Passing Tests

**979 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.5s |  |
| 2 | `agal_compiler` | 13 | 8.9s |  |
| 3 | `air_datagram_socket` | 1 | 7.1s |  |
| 4 | `air_hidden_lookup` | 2 | 6.5s |  |
| 5 | `all_classes/security/swf11` | 3 | 6.5s |  |
| 6 | `amf_array_serialization` | 17 | 8.3s |  |
| 7 | `amf_custom_obj` | 26 | 6.5s |  |
| 8 | `amf_dictionary` | 9 | 6.5s |  |
| 9 | `amf_function` | 46 | 6.5s |  |
| 10 | `amf_invalid_date` | 2 | 6.4s |  |
| 11 | `amf_missing_prop` | 6 | 6.5s |  |
| 12 | `amf_nondynamic_function_prop` | 6 | 6.9s |  |
| 13 | `amf_setter_error` | 8 | 7.0s |  |
| 14 | `amf_vector` | 40 | 6.9s |  |
| 15 | `amf_xml` | 6 | 6.7s |  |
| 16 | `application_domain` | 4 | 6.8s |  |
| 17 | `array_access` | 18 | 6.8s |  |
| 18 | `array_access_interpreter` | 4 | 6.8s |  |
| 19 | `array_access_no_pubns` | 2 | 6.8s |  |
| 20 | `array_concat` | 41 | 6.8s |  |
| 21 | `array_constr` | 10 | 6.6s |  |
| 22 | `array_delete` | 44 | 6.9s |  |
| 23 | `array_enumeration` | 10 | 6.8s |  |
| 24 | `array_enumeration_elements` | 11 | 6.6s |  |
| 25 | `array_every` | 8 | 6.7s |  |
| 26 | `array_filter` | 6 | 6.7s |  |
| 27 | `array_foreach` | 18 | 6.7s |  |
| 28 | `array_hasownproperty` | 11 | 3.2s |  |
| 29 | `array_holes` | 9 | 6.7s |  |
| 30 | `array_index_max` | 84 | 6.7s |  |
| 31 | `array_indexof` | 25 | 6.8s |  |
| 32 | `array_join` | 26 | 6.8s |  |
| 33 | `array_lastindexof` | 29 | 6.7s |  |
| 34 | `array_length` | 14 | 6.7s |  |
| 35 | `array_literal` | 3 | 6.7s |  |
| 36 | `array_map` | 8 | 6.5s |  |
| 37 | `array_pop` | 52 | 6.8s |  |
| 38 | `array_push` | 24 | 6.7s |  |
| 39 | `array_reborrow_bug` | 6 | 6.6s |  |
| 40 | `array_reverse` | 28 | 6.6s |  |
| 41 | `array_shift` | 51 | 3.2s |  |
| 42 | `array_slice` | 39 | 6.7s |  |
| 43 | `array_some` | 8 | 6.6s |  |
| 44 | `array_sort` | 297 | 7.1s |  |
| 45 | `array_sort_fun_swf12` | 2 | 6.6s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 47 | `array_sort_random` | 210 | 6.6s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 6.6s |  |
| 49 | `array_sorton` | 545 | 6.5s |  |
| 50 | `array_sparse_ops` | 41 | 5.4s |  |
| 51 | `array_splice` | 133 | 5.6s |  |
| 52 | `array_splice2` | 428 | 5.6s |  |
| 53 | `array_splice_types` | 48 | 5.5s |  |
| 54 | `array_storage` | 8 | 5.3s |  |
| 55 | `array_tolocalestring` | 9 | 5.4s |  |
| 56 | `array_tostring` | 12 | 5.3s |  |
| 57 | `array_unshift` | 24 | 5.5s |  |
| 58 | `array_valueof` | 9 | 5.3s |  |
| 59 | `array_vector_null_callback` | 10 | 5.3s |  |
| 60 | `astype` | 28 | 5.3s |  |
| 61 | `astypelate` | 24 | 5.4s |  |
| 62 | `astypelate_propagates` | 1 | 5.2s |  |
| 63 | `asymmetric_key_events` | 11 | 5.2s |  |
| 64 | `av_networking_params` | 9 | 5.2s |  |
| 65 | `avm2_catchup_dobj` | 158 | 5.7s |  |
| 66 | `away3d_advanced_shallow_water_demo` | 0 | 64.4s |  |
| 67 | `bitand` | 1058 | 14.1s |  |
| 68 | `bitmap_constr` | 17 | 5.4s |  |
| 69 | `bitmap_data` | 1000 | 11.6s |  |
| 70 | `bitmap_pixelsnapping` | 2 | 20.4s |  |
| 71 | `bitmap_properties` | 23 | 5.3s |  |
| 72 | `bitmap_subclass` | 7 | 6.4s |  |
| 73 | `bitmap_subclass_properties` | 9 | 5.6s |  |
| 74 | `bitmap_timeline` | 9 | 5.3s |  |
| 75 | `bitmapdata_accuracy` | 1 | 36.3s |  |
| 76 | `bitmapdata_applyfilter_blur` | 0 | 21.5s |  |
| 77 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.1s |  |
| 78 | `bitmapdata_applyfilter_destpoint` | 0 | 20.7s |  |
| 79 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 20.8s |  |
| 80 | `bitmapdata_clone` | 13 | 5.5s |  |
| 81 | `bitmapdata_colortransform` | 0 | 5.9s |  |
| 82 | `bitmapdata_colortransform_oob` | 2 | 5.3s |  |
| 83 | `bitmapdata_constr` | 22 | 2.5s |  |
| 84 | `bitmapdata_constructor_from_timeline` | 1 | 5.6s |  |
| 85 | `bitmapdata_copychannel` | 0 | 22.5s |  |
| 86 | `bitmapdata_copypixels` | 23 | 20.0s |  |
| 87 | `bitmapdata_copypixels_blend_over` | 1 | 4.4s |  |
| 88 | `bitmapdata_copypixelstobytearray` | 39 | 4.8s |  |
| 89 | `bitmapdata_dispose` | 7 | 5.2s |  |
| 90 | `bitmapdata_draw` | 0 | 19.1s |  |
| 91 | `bitmapdata_draw_colortransform` | 0 | 4.7s |  |
| 92 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 18.6s |  |
| 93 | `bitmapdata_draw_filters` | 0 | 19.2s |  |
| 94 | `bitmapdata_draw_masks` | 0 | 4.5s |  |
| 95 | `bitmapdata_draw_rotation` | 0 | 4.6s |  |
| 96 | `bitmapdata_draw_self_via_graphic` | 0 | 4.5s |  |
| 97 | `bitmapdata_draw_stage` | 0 | 18.2s |  |
| 98 | `bitmapdata_drawwithquality` | 0 | 5.0s |  |
| 99 | `bitmapdata_embedded` | 9 | 4.8s |  |
| 100 | `bitmapdata_fillrect` | 0 | 4.7s |  |
| 101 | `bitmapdata_filter_sourcerect` | 0 | 18.6s |  |
| 102 | `bitmapdata_floodfill` | 35 | 4.8s |  |
| 103 | `bitmapdata_getpixels` | 39 | 19.1s |  |
| 104 | `bitmapdata_getvector` | 27 | 2.3s |  |
| 105 | `bitmapdata_histogram` | 59 | 2.4s |  |
| 106 | `bitmapdata_hittest` | 112 | 5.0s |  |
| 107 | `bitmapdata_hittest_threshold` | 18 | 5.0s |  |
| 108 | `bitmapdata_opaque` | 0 | 4.6s |  |
| 109 | `bitmapdata_pixeldissolve` | 1037 | 5.2s |  |
| 110 | `bitmapdata_pixeldissolve_image` | 0 | 5.1s |  |
| 111 | `bitmapdata_rectangle_rounding` | 16 | 4.4s |  |
| 112 | `bitmapdata_setpixels` | 286 | 4.7s |  |
| 113 | `bitmapdata_setvector` | 26 | 4.7s |  |
| 114 | `bitmapdata_sync` | 0 | 18.6s |  |
| 115 | `bitmapdata_threshold` | 176 | 5.7s |  |
| 116 | `bitnot` | 46 | 4.8s |  |
| 117 | `bitor` | 1058 | 12.1s |  |
| 118 | `bitxor` | 1058 | 12.3s |  |
| 119 | `blend_multiply_alpha` | 0 | 4.8s |  |
| 120 | `blend_scroll` | 0 | 4.7s |  |
| 121 | `blend_shader_luma_lighten` | 3 | 5.1s |  |
| 122 | `boolean_constr` | 32 | 6.5s |  |
| 123 | `boolean_negation` | 30 | 6.5s |  |
| 124 | `boolean_tostring` | 8 | 6.5s |  |
| 125 | `broadcast_event` | 7 | 6.8s |  |
| 126 | `button_nested_frame` | 48 | 25.3s |  |
| 127 | `bytearray` | 48 | 6.7s |  |
| 128 | `bytearray_compress` | 31 | 6.6s |  |
| 129 | `bytearray_errors` | 24 | 6.6s |  |
| 130 | `bytearray_method_serialization` | 1 | 6.5s |  |
| 131 | `bytearray_oom` | 3 | 6.6s |  |
| 132 | `bytearray_readobject_amf0` | 50 | 6.7s |  |
| 133 | `bytearray_readobject_amf3` | 53 | 6.6s |  |
| 134 | `bytearray_readutf8bytes_with_bom` | 16 | 6.5s |  |
| 135 | `bytearray_serialization` | 3 | 6.5s |  |
| 136 | `bytearray_string_null` | 19 | 6.7s |  |
| 137 | `bytearray_tostring` | 15 | 6.5s |  |
| 138 | `bytearray_utf16` | 8 | 6.4s |  |
| 139 | `bytearray_writeobject` | 24 | 6.4s |  |
| 140 | `callee_in_initializer` | 6 | 6.4s |  |
| 141 | `callproplex_class` | 1 | 6.4s |  |
| 142 | `capabilities_resolution` | 8 | 25.7s |  |
| 143 | `catch_scope_slot` | 7 | 3.2s |  |
| 144 | `checkfilter` | 4 | 3.1s |  |
| 145 | `class_call` | 32 | 6.7s |  |
| 146 | `class_cast_call` | 14 | 6.6s |  |
| 147 | `class_enumeration` | 4 | 6.5s |  |
| 148 | `class_has_own_property` | 2 | 6.4s |  |
| 149 | `class_init_interpreter_mode` | 1 | 6.3s |  |
| 150 | `class_is` | 32 | 6.5s |  |
| 151 | `class_methods` | 5 | 6.4s |  |
| 152 | `class_object_properties` | 10 | 6.5s |  |
| 153 | `class_singleton` | 18 | 6.5s |  |
| 154 | `class_supercalls_errors` | 35 | 6.7s |  |
| 155 | `class_supercalls_mismatched` | 26 | 6.5s |  |
| 156 | `class_superclass_wrong_order` | 1 | 25.0s |  |
| 157 | `class_to_locale_string` | 2 | 6.5s |  |
| 158 | `class_to_string` | 2 | 6.4s |  |
| 159 | `class_value_of` | 2 | 6.7s |  |
| 160 | `click_block` | 5 | 7.4s |  |
| 161 | `click_invisible` | 3 | 6.8s |  |
| 162 | `closures` | 12 | 6.5s |  |
| 163 | `coerce_return_type` | 40 | 6.7s |  |
| 164 | `coerce_return_type_fail` | 2 | 6.4s |  |
| 165 | `coerce_return_void` | 3 | 6.4s |  |
| 166 | `coerce_string` | 86 | 6.6s |  |
| 167 | `coerce_string_precision` | 28 | 6.7s |  |
| 168 | `coerce_to_primitive_side_effects` | 29 | 6.5s |  |
| 169 | `construct_errors_swf10` | 8 | 6.6s |  |
| 170 | `construct_frame_list` | 22 | 25.3s |  |
| 171 | `construct_interface` | 3 | 6.5s |  |
| 172 | `constructor_call` | 3 | 6.5s |  |
| 173 | `constructors_vs_timeline` | 5 | 25.6s |  |
| 174 | `constructprop_dynamic_primitive` | 7 | 6.6s |  |
| 175 | `context3d_creation` | 9 | 6.6s |  |
| 176 | `control_flow_bool` | 4 | 6.5s |  |
| 177 | `control_flow_stricteq` | 8 | 6.7s |  |
| 178 | `convert_boolean` | 30 | 6.5s |  |
| 179 | `convert_integer` | 90 | 6.6s |  |
| 180 | `convert_number` | 56 | 6.8s |  |
| 181 | `convert_uinteger` | 90 | 6.6s |  |
| 182 | `cpool_index_invalid_bytecode_1` | 6 | 6.5s |  |
| 183 | `cpool_index_invalid_bytecode_2` | 3 | 6.5s |  |
| 184 | `cpool_index_invalid_bytecode_3` | 1 | 6.4s |  |
| 185 | `cross_api_version_call_older` | 12 | 6.8s |  |
| 186 | `cryptscore` | 11 | 6.6s |  |
| 187 | `date` | 30 | 6.8s |  |
| 188 | `date_parse` | 36 | 7.0s |  |
| 189 | `declocal` | 46 | 6.5s |  |
| 190 | `declocal_i` | 46 | 7.0s |  |
| 191 | `decode_uri` | 71 | 7.3s |  |
| 192 | `decrement` | 46 | 6.9s |  |
| 193 | `decrement_i` | 46 | 2.9s |  |
| 194 | `default_values` | 7 | 6.8s |  |
| 195 | `dictionary_access` | 62 | 6.7s |  |
| 196 | `dictionary_access_no_pubns` | 2 | 6.4s |  |
| 197 | `dictionary_delete` | 101 | 6.9s |  |
| 198 | `dictionary_foreach` | 42 | 6.8s |  |
| 199 | `dictionary_hasownproperty` | 63 | 6.7s |  |
| 200 | `dictionary_in` | 62 | 6.9s |  |
| 201 | `dictionary_iter_modify` | 8 | 6.6s |  |
| 202 | `dictionary_namespaces` | 36 | 6.5s |  |
| 203 | `dictionary_primitive_keys` | 29 | 6.6s |  |
| 204 | `displayobject_alpha` | 277 | 6.3s |  |
| 205 | `displayobject_blendmode` | 0 | 6.8s |  |
| 206 | `displayobject_colortransform_nested` | 0 | 27.1s |  |
| 207 | `displayobject_from_enterframe` | 1 | 26.1s |  |
| 208 | `displayobject_getbounds_shape` | 0 | 26.2s |  |
| 209 | `displayobject_height` | 6052 | 26.7s |  |
| 210 | `displayobject_hittestobject` | 32 | 6.8s |  |
| 211 | `displayobject_invalid_floats` | 60 | 6.4s |  |
| 212 | `displayobject_invalid_props` | 3 | 2.9s |  |
| 213 | `displayobject_mask` | 3 | 6.7s |  |
| 214 | `displayobject_mask_self_referential` | 0 | 6.9s |  |
| 215 | `displayobject_metaData` | 3 | 6.7s |  |
| 216 | `displayobject_name` | 22 | 7.2s |  |
| 217 | `displayobject_name_from_timeline` | 24 | 7.1s |  |
| 218 | `displayobject_parent` | 12 | 7.0s |  |
| 219 | `displayobject_root` | 24 | 7.0s |  |
| 220 | `displayobject_rotation` | 1284 | 7.2s |  |
| 221 | `displayobject_set_matrix_nested` | 0 | 27.6s |  |
| 222 | `displayobject_set_name_loaded` | 3 | 7.6s |  |
| 223 | `displayobject_subclass` | 2 | 7.2s |  |
| 224 | `displayobject_visible` | 23 | 7.2s |  |
| 225 | `displayobject_width` | 4852 | 28.0s |  |
| 226 | `displayobject_x` | 614 | 7.2s |  |
| 227 | `displayobject_y` | 617 | 7.2s |  |
| 228 | `displayobjectcontainer_addchild` | 32 | 7.3s |  |
| 229 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.1s |  |
| 230 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.3s |  |
| 231 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.2s |  |
| 232 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.2s |  |
| 233 | `displayobjectcontainer_addchildat` | 42 | 7.2s |  |
| 234 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.6s |  |
| 235 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.2s |  |
| 236 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.3s |  |
| 237 | `displayobjectcontainer_contains` | 66 | 28.0s |  |
| 238 | `displayobjectcontainer_getchildat` | 4 | 7.2s |  |
| 239 | `displayobjectcontainer_getchildbyname` | 9 | 7.1s |  |
| 240 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.0s |  |
| 241 | `displayobjectcontainer_getchildindex` | 28 | 7.0s |  |
| 242 | `displayobjectcontainer_removechild` | 10 | 7.0s |  |
| 243 | `displayobjectcontainer_removechild_errors` | 4 | 6.9s |  |
| 244 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.0s |  |
| 245 | `displayobjectcontainer_removechildat` | 18 | 6.9s |  |
| 246 | `displayobjectcontainer_removechildren` | 51 | 7.2s |  |
| 247 | `displayobjectcontainer_setchildindex` | 42 | 6.7s |  |
| 248 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.3s |  |
| 249 | `displayobjectcontainer_swapchildren` | 42 | 6.9s |  |
| 250 | `displayobjectcontainer_swapchildrenat` | 42 | 6.9s |  |
| 251 | `displayobjectcontainer_timelineinstance` | 48 | 25.1s |  |
| 252 | `divide` | 1058 | 18.6s |  |
| 253 | `doabc_is_eager` | 1 | 24.8s |  |
| 254 | `documentclass` | 9 | 6.6s |  |
| 255 | `domain_memory` | 133 | 7.6s |  |
| 256 | `drag_drop` | 10 | 6.7s |  |
| 257 | `duplicate_defs` | 1 | 6.3s |  |
| 258 | `eager_init` | 1 | 6.4s |  |
| 259 | `edit_text_linkage` | 7 | 6.6s |  |
| 260 | `edittext_align` | 60 | 6.8s |  |
| 261 | `edittext_always_show_selection` | 0 | 25.4s |  |
| 262 | `edittext_antialiastype` | 296 | 6.7s |  |
| 263 | `edittext_at_point_methods_basic` | 16 | 7.8s |  |
| 264 | `edittext_autosize` | 39 | 6.8s |  |
| 265 | `edittext_autosize_align` | 0 | 25.7s |  |
| 266 | `edittext_autosize_height_dynamic` | 60 | 25.5s |  |
| 267 | `edittext_autosize_height_input` | 60 | 6.6s |  |
| 268 | `edittext_autosize_lazy_bounds_events` | 65 | 6.8s |  |
| 269 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.5s |  |
| 270 | `edittext_autosize_lazy_bounds_props` | 490 | 7.9s |  |
| 271 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.4s |  |
| 272 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.7s |  |
| 273 | `edittext_bottom_scroll_v_basic` | 210 | 6.6s |  |
| 274 | `edittext_bounds_scale` | 24 | 24.7s |  |
| 275 | `edittext_bullet` | 30 | 6.5s |  |
| 276 | `edittext_default_format` | 221 | 6.8s |  |
| 277 | `edittext_default_format_empty` | 136 | 6.8s |  |
| 278 | `edittext_empty_text_format` | 7 | 6.5s |  |
| 279 | `edittext_focus_selection` | 5 | 6.5s |  |
| 280 | `edittext_font_size` | 45 | 6.5s |  |
| 281 | `edittext_format_empty_font` | 8 | 6.4s |  |
| 282 | `edittext_get_char_index_at_point` | 4 | 26.5s |  |
| 283 | `edittext_get_line_index_at_point` | 2 | 25.5s |  |
| 284 | `edittext_get_line_index_of_char` | 76 | 7.4s |  |
| 285 | `edittext_getcharboundaries` | 172 | 6.8s |  |
| 286 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.6s |  |
| 287 | `edittext_getcharboundaries_scroll` | 85 | 6.7s |  |
| 288 | `edittext_getlinemetrics` | 146 | 6.8s |  |
| 289 | `edittext_html` | 3101 | 6.9s |  |
| 290 | `edittext_html_condensewhite` | 487 | 6.6s |  |
| 291 | `edittext_html_entity` | 4 | 6.7s |  |
| 292 | `edittext_html_font_size_swf12` | 267 | 6.5s |  |
| 293 | `edittext_html_font_size_swf13` | 273 | 6.3s |  |
| 294 | `edittext_html_roundtrip` | 17 | 6.6s |  |
| 295 | `edittext_ime_focus_lost` | 9 | 25.5s |  |
| 296 | `edittext_input_control` | 12 | 6.7s |  |
| 297 | `edittext_leading` | 9 | 6.9s |  |
| 298 | `edittext_letter_spacing` | 15 | 6.7s |  |
| 299 | `edittext_line_methods` | 294 | 8.2s |  |
| 300 | `edittext_line_metrics` | 11 | 27.9s |  |
| 301 | `edittext_margins` | 25 | 6.8s |  |
| 302 | `edittext_max_scroll_h_basic` | 475 | 6.8s |  |
| 303 | `edittext_max_scroll_v_basic` | 1000 | 6.6s |  |
| 304 | `edittext_mouse_selection` | 363 | 26.1s |  |
| 305 | `edittext_mousedown` | 3 | 6.8s |  |
| 306 | `edittext_mouseenabled` | 26 | 6.4s |  |
| 307 | `edittext_newline_character` | 22 | 6.5s |  |
| 308 | `edittext_newline_stripping` | 64 | 9.1s |  |
| 309 | `edittext_newlines` | 30 | 6.5s |  |
| 310 | `edittext_paragraph_methods` | 257 | 6.5s |  |
| 311 | `edittext_paste_events` | 8 | 6.5s |  |
| 312 | `edittext_paste_maxchars` | 4 | 6.5s |  |
| 313 | `edittext_paste_restrict` | 16 | 6.3s |  |
| 314 | `edittext_restrict` | 191 | 6.5s |  |
| 315 | `edittext_restrict_events` | 22 | 6.4s |  |
| 316 | `edittext_scrollh` | 10 | 3.0s |  |
| 317 | `edittext_selected_text` | 9 | 6.4s |  |
| 318 | `edittext_set_html_same` | 17 | 6.4s |  |
| 319 | `edittext_set_text_vs_html` | 9 | 6.4s |  |
| 320 | `edittext_stylesheet` | 536 | 6.8s |  |
| 321 | `edittext_stylesheet_custom_tag` | 76 | 6.5s |  |
| 322 | `edittext_stylesheet_display` | 272 | 6.6s |  |
| 323 | `edittext_underline` | 40 | 6.6s |  |
| 324 | `edittext_width_height` | 103 | 7.0s |  |
| 325 | `edittext_wordwrap_word` | 150 | 5.7s |  |
| 326 | `edittext_wrap_breaks` | 2375 | 6.2s |  |
| 327 | `empty_bounds` | 1 | 5.3s |  |
| 328 | `encode_uri_surrogate_pair_swf11` | 15 | 5.3s |  |
| 329 | `equals` | 512 | 8.5s |  |
| 330 | `error_geterrormessage` | 779 | 5.4s |  |
| 331 | `error_prototype` | 15 | 5.5s |  |
| 332 | `error_stack_trace_debug_swf17` | 0 | 20.1s |  |
| 333 | `error_stack_trace_debug_swf18` | 0 | 5.2s |  |
| 334 | `error_stack_trace_release_swf17` | 0 | 5.1s |  |
| 335 | `error_stack_trace_release_swf18` | 0 | 5.3s |  |
| 336 | `error_tostring` | 29 | 5.4s |  |
| 337 | `es3_inheritance` | 31 | 5.4s |  |
| 338 | `es4_inheritance` | 30 | 5.6s |  |
| 339 | `es4_interfaces` | 30 | 5.5s |  |
| 340 | `es4_method_binding` | 8 | 2.6s |  |
| 341 | `es4_oop_prototypes` | 14 | 5.5s |  |
| 342 | `es4_protected_inheritance` | 6 | 5.4s |  |
| 343 | `escape` | 71 | 5.5s |  |
| 344 | `event_bubbles` | 2 | 5.4s |  |
| 345 | `event_cancelable` | 2 | 5.3s |  |
| 346 | `event_clone` | 20 | 5.6s |  |
| 347 | `event_clone_error_redispatch` | 3 | 5.5s |  |
| 348 | `event_clone_on_redispatch` | 10 | 5.4s |  |
| 349 | `event_formattostring` | 31 | 5.3s |  |
| 350 | `event_isdefaultprevented` | 12 | 5.3s |  |
| 351 | `event_target_getter` | 5 | 2.6s |  |
| 352 | `event_target_set` | 9 | 5.4s |  |
| 353 | `event_type` | 1 | 7.9s |  |
| 354 | `event_valueof_tostring` | 18 | 6.4s |  |
| 355 | `eventdispatcher_dispatchevent` | 12 | 6.4s |  |
| 356 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.4s |  |
| 357 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.5s |  |
| 358 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.4s |  |
| 359 | `eventdispatcher_dispatchevent_this` | 5 | 6.4s |  |
| 360 | `eventdispatcher_haseventlistener` | 25 | 6.4s |  |
| 361 | `eventdispatcher_interface_invoke` | 1 | 6.3s |  |
| 362 | `eventdispatcher_tostring` | 10 | 6.4s |  |
| 363 | `eventdispatcher_willtrigger` | 25 | 6.3s |  |
| 364 | `falsiness` | 30 | 6.4s |  |
| 365 | `fast_index_access` | 12 | 6.5s |  |
| 366 | `filefilter_properties` | 4 | 6.4s |  |
| 367 | `filereference_browse_cancel` | 3 | 6.4s |  |
| 368 | `filereference_browse_select` | 9 | 6.4s |  |
| 369 | `filereference_load` | 31 | 3.0s |  |
| 370 | `filereference_save` | 16 | 6.4s |  |
| 371 | `filereference_save_and_browse` | 42 | 6.5s |  |
| 372 | `filereference_save_and_load` | 22 | 6.5s |  |
| 373 | `filereference_uninitialized` | 8 | 6.4s |  |
| 374 | `filereferencelist_browse_cancel` | 6 | 3.0s |  |
| 375 | `filereferencelist_browse_select` | 7 | 6.4s |  |
| 376 | `finddef` | 3 | 6.4s |  |
| 377 | `findprop_global_prototype` | 6 | 6.4s |  |
| 378 | `flash_xml` | 29 | 6.5s |  |
| 379 | `flash_xml_cloneNode` | 22 | 6.4s |  |
| 380 | `flash_xml_namespace` | 109 | 6.4s |  |
| 381 | `flash_xml_removeNode` | 60 | 6.4s |  |
| 382 | `focus_events_code` | 161 | 25.1s |  |
| 383 | `focus_events_key_basic` | 132 | 25.1s |  |
| 384 | `focus_events_key_navigation` | 53 | 6.6s |  |
| 385 | `focus_events_key_same_object` | 26 | 6.4s |  |
| 386 | `focus_events_mixed_key_mouse` | 100 | 24.8s |  |
| 387 | `focus_events_mouse_basic` | 260 | 28.3s |  |
| 388 | `focus_events_mouse_focusable` | 112 | 26.4s |  |
| 389 | `focus_events_mouse_same_object` | 40 | 26.3s |  |
| 390 | `focus_remove` | 20 | 26.2s |  |
| 391 | `focus_root_movie` | 4 | 26.5s |  |
| 392 | `focus_stage` | 1 | 6.8s |  |
| 393 | `focusrect` | 18 | 7.7s |  |
| 394 | `focusrect_focuslost` | 9 | 7.3s |  |
| 395 | `focusrect_property` | 110 | 7.2s |  |
| 396 | `font_description_clone` | 14 | 7.2s |  |
| 397 | `font_embedded` | 24 | 7.5s |  |
| 398 | `font_enumeratefonts` | 41 | 7.7s |  |
| 399 | `font_enumeratefonts_filter` | 4 | 29.0s |  |
| 400 | `font_hasglyphs` | 40 | 7.7s |  |
| 401 | `framelabel_constr` | 5 | 7.1s |  |
| 402 | `function_call` | 12 | 7.2s |  |
| 403 | `function_call_arguments` | 46 | 7.1s |  |
| 404 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 405 | `function_call_coercion` | 108 | 7.7s |  |
| 406 | `function_call_default` | 6 | 7.3s |  |
| 407 | `function_call_rest` | 22 | 7.2s |  |
| 408 | `function_call_types` | 3 | 7.2s |  |
| 409 | `function_call_via_apply` | 11 | 7.4s |  |
| 410 | `function_call_via_call` | 3 | 7.2s |  |
| 411 | `function_display_anonymous` | 7 | 3.5s |  |
| 412 | `function_length` | 6 | 7.2s |  |
| 413 | `function_object` | 2 | 7.2s |  |
| 414 | `function_proto` | 5 | 7.1s |  |
| 415 | `function_proto_created` | 61 | 7.1s |  |
| 416 | `function_to_locale_string` | 4 | 7.0s |  |
| 417 | `function_to_string` | 4 | 7.0s |  |
| 418 | `function_type` | 6 | 7.2s |  |
| 419 | `function_unbound_this` | 51 | 7.2s |  |
| 420 | `function_value_of` | 4 | 6.9s |  |
| 421 | `get_definition_by_name` | 11 | 7.2s |  |
| 422 | `get_qualified_class_name` | 20 | 9.1s |  |
| 423 | `get_qualified_super_class_name` | 18 | 7.3s |  |
| 424 | `get_slot_edge_cases` | 1 | 29.1s |  |
| 425 | `get_timer` | 2 | 6.8s |  |
| 426 | `getglobalslot` | 1 | 6.8s |  |
| 427 | `getouterscope` | 8 | 6.7s |  |
| 428 | `getter_different_namespace_setter` | 2 | 6.8s |  |
| 429 | `goto_button_nested_framescript` | 28 | 28.4s |  |
| 430 | `goto_in_constructframe` | 12 | 7.8s |  |
| 431 | `goto_in_scene_last_frame` | 2 | 28.3s |  |
| 432 | `goto_methods` | 56 | 7.1s |  |
| 433 | `goto_methods_swfver10` | 8 | 7.2s |  |
| 434 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 435 | `goto_nested_framescript` | 9 | 6.9s |  |
| 436 | `goto_on_orphan` | 15 | 7.5s |  |
| 437 | `graphics_bad_direct_commands` | 5 | 8.0s |  |
| 438 | `graphics_bitmap_fill` | 0 | 9.2s |  |
| 439 | `graphics_bitmaps` | 0 | 7.8s |  |
| 440 | `graphics_direct_commands` | 0 | 7.7s |  |
| 441 | `graphics_draw_triangles` | 98 | 29.1s |  |
| 442 | `graphics_gradients` | 0 | 7.3s |  |
| 443 | `graphics_gradients_nulls` | 0 | 6.9s |  |
| 444 | `graphics_path` | 56 | 7.0s |  |
| 445 | `graphics_round_rects` | 0 | 6.6s |  |
| 446 | `graphics_simple_shapes` | 0 | 7.3s |  |
| 447 | `greaterequals` | 512 | 11.1s |  |
| 448 | `greaterthan` | 512 | 11.0s |  |
| 449 | `has_own_property` | 102 | 7.4s |  |
| 450 | `hasownproperty_namespaces` | 2 | 6.9s |  |
| 451 | `hello_world` | 1 | 6.8s |  |
| 452 | `hittest_morph` | 30 | 7.0s |  |
| 453 | `if_eq` | 10 | 7.0s |  |
| 454 | `if_gt` | 1 | 7.1s |  |
| 455 | `if_gte` | 10 | 7.1s |  |
| 456 | `if_lt` | 1 | 5.8s |  |
| 457 | `if_lte` | 10 | 5.7s |  |
| 458 | `if_ne` | 7 | 2.4s |  |
| 459 | `if_stricteq` | 6 | 5.5s |  |
| 460 | `if_strictne` | 11 | 5.5s |  |
| 461 | `ime_linux_dead_keys` | 10 | 5.6s |  |
| 462 | `in` | 102 | 6.3s |  |
| 463 | `inclocal` | 46 | 5.5s |  |
| 464 | `inclocal_i` | 46 | 5.6s |  |
| 465 | `increment` | 46 | 5.5s |  |
| 466 | `increment_i` | 46 | 5.5s |  |
| 467 | `indexing_delete` | 75 | 5.6s |  |
| 468 | `instanceof` | 58 | 6.0s |  |
| 469 | `instantiation_on_enter_frame` | 7 | 22.4s |  |
| 470 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.6s |  |
| 471 | `int_constr` | 92 | 5.5s |  |
| 472 | `int_edge_cases` | 19 | 5.7s |  |
| 473 | `int_instanceof` | 3 | 5.7s |  |
| 474 | `int_tofixed` | 1215 | 5.8s |  |
| 475 | `int_tostring` | 3375 | 5.8s |  |
| 476 | `interactiveobject_enabled` | 25 | 6.0s |  |
| 477 | `interface_namespaces` | 78 | 6.1s |  |
| 478 | `is_finite` | 46 | 5.9s |  |
| 479 | `is_nan` | 46 | 5.7s |  |
| 480 | `is_prototype_of` | 12 | 6.0s |  |
| 481 | `issue_10221` | 2 | 5.5s |  |
| 482 | `issue_13780` | 12 | 5.5s |  |
| 483 | `issue_14901` | 1 | 5.5s |  |
| 484 | `issue_17675_edittext_paste_maxchars` | 1 | 5.6s |  |
| 485 | `issue_5292` | 5 | 5.7s |  |
| 486 | `issue_8630` | 2 | 22.6s |  |
| 487 | `issue_8630_scriptremove` | 11 | 5.6s |  |
| 488 | `istype` | 24 | 2.5s |  |
| 489 | `istypelate` | 58 | 6.0s |  |
| 490 | `istypelate_coerce` | 198 | 7.3s |  |
| 491 | `jpeg_loader_context` | 6 | 5.1s |  |
| 492 | `json_errors` | 9 | 21.2s |  |
| 493 | `json_parse` | 21 | 5.2s |  |
| 494 | `json_stringify` | 12 | 5.3s |  |
| 495 | `json_stringify_order` | 1 | 5.3s |  |
| 496 | `json_version_gated` | 1 | 5.4s |  |
| 497 | `key_input_80percent` | 1812 | 5.5s |  |
| 498 | `key_input_location` | 126 | 5.5s |  |
| 499 | `key_input_numpad` | 384 | 5.2s |  |
| 500 | `lazyinit` | 17 | 5.6s |  |
| 501 | `lessequals` | 512 | 8.3s |  |
| 502 | `lessthan` | 512 | 8.1s |  |
| 503 | `loader_bitmap_transparency` | 14 | 5.4s |  |
| 504 | `loader_bytes_unknown_content` | 14 | 5.3s |  |
| 505 | `loader_child_getdefinition` | 5 | 5.4s |  |
| 506 | `loader_duplicate_coerce` | 3 | 5.6s |  |
| 507 | `loader_duplicate_coerce_new_domain` | 4 | 5.4s |  |
| 508 | `loader_error_in_root_ctor` | 4 | 5.8s |  |
| 509 | `loader_events` | 92 | 5.8s |  |
| 510 | `loader_image` | 8 | 5.4s |  |
| 511 | `loader_jpegxr` | 2 | 21.5s |  |
| 512 | `loader_jpegxr_alpha` | 1 | 21.1s |  |
| 513 | `loader_loadbytes_events` | 30 | 5.7s |  |
| 514 | `loader_loadbytes_invalid_png` | 4 | 21.3s |  |
| 515 | `loader_loadbytes_url` | 12 | 5.5s |  |
| 516 | `loader_loaderurl` | 6 | 6.0s |  |
| 517 | `loader_noninteractive_try_click_root` | 5 | 22.2s |  |
| 518 | `loader_reuse` | 38 | 5.8s |  |
| 519 | `loader_unknown_content` | 24 | 5.7s |  |
| 520 | `loader_visibility_interactive` | 1 | 5.4s |  |
| 521 | `loaderinfo_events` | 7 | 5.6s |  |
| 522 | `loaderinfo_loadurl` | 12 | 8.3s |  |
| 523 | `loaderinfo_more` | 6 | 7.0s |  |
| 524 | `loaderinfo_properties` | 18 | 6.8s |  |
| 525 | `loaderinfo_properties_not_loaded` | 23 | 6.9s |  |
| 526 | `loaderinfo_root` | 10 | 6.7s |  |
| 527 | `loaderinfo_root_allows` | 2 | 6.7s |  |
| 528 | `localconnection_send` | 4 | 6.8s |  |
| 529 | `lshift` | 1058 | 19.2s |  |
| 530 | `mask_reapply` | 1 | 6.7s |  |
| 531 | `math` | 497 | 6.8s |  |
| 532 | `matrix3d_invert` | 18 | 3.1s |  |
| 533 | `missing_external_interface` | 10 | 6.6s |  |
| 534 | `modulo` | 1058 | 18.9s |  |
| 535 | `morph_shape` | 2 | 25.4s |  |
| 536 | `mouse_children` | 192 | 25.6s |  |
| 537 | `mouse_click_events` | 90 | 25.6s |  |
| 538 | `mouse_double_click_events` | 188 | 6.5s |  |
| 539 | `mouse_empty_parent` | 4 | 6.5s |  |
| 540 | `mouse_over_while_dragging` | 3 | 6.5s |  |
| 541 | `mouse_pick_button_mode` | 2 | 6.6s |  |
| 542 | `mouse_pick_dobj_mask` | 4 | 6.8s |  |
| 543 | `mouse_pick_masking` | 7 | 25.7s |  |
| 544 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.4s |  |
| 545 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.1s |  |
| 546 | `mouse_pick_text` | 8 | 6.8s |  |
| 547 | `mouse_sibling` | 8 | 6.7s |  |
| 548 | `mouse_wheel_events` | 36 | 27.0s |  |
| 549 | `mouseevent_constr` | 66 | 6.5s |  |
| 550 | `mouseevent_stagexy` | 35 | 6.7s |  |
| 551 | `mouseevent_valueof_tostring` | 28 | 6.6s |  |
| 552 | `movieclip_addframescript` | 3 | 25.3s |  |
| 553 | `movieclip_child_property` | 16 | 6.6s |  |
| 554 | `movieclip_constr` | 21 | 8.1s |  |
| 555 | `movieclip_currentlabels` | 17 | 25.1s |  |
| 556 | `movieclip_currentlabels_dupes1` | 46 | 25.5s |  |
| 557 | `movieclip_currentlabels_dupes2` | 30 | 6.6s |  |
| 558 | `movieclip_currentlabels_dupes3` | 67 | 6.6s |  |
| 559 | `movieclip_currentscene` | 12 | 6.6s |  |
| 560 | `movieclip_dispatchevent` | 430 | 6.8s |  |
| 561 | `movieclip_dispatchevent_cancel` | 102 | 6.7s |  |
| 562 | `movieclip_dispatchevent_handlerorder` | 251 | 6.6s |  |
| 563 | `movieclip_dispatchevent_selfadd` | 80 | 6.5s |  |
| 564 | `movieclip_dispatchevent_target` | 899 | 6.7s |  |
| 565 | `movieclip_displayevents` | 96 | 25.4s |  |
| 566 | `movieclip_displayevents_clickgoto` | 676 | 7.2s |  |
| 567 | `movieclip_displayevents_clickgoto2` | 2001 | 7.2s |  |
| 568 | `movieclip_displayevents_clickplay` | 575 | 6.8s |  |
| 569 | `movieclip_displayevents_clicksymbol` | 562 | 6.7s |  |
| 570 | `movieclip_displayevents_constructframegoto` | 140 | 6.9s |  |
| 571 | `movieclip_displayevents_constructframeplay` | 50 | 6.8s |  |
| 572 | `movieclip_displayevents_constructframesymbol` | 144 | 6.7s |  |
| 573 | `movieclip_displayevents_dblhandler` | 21 | 6.7s |  |
| 574 | `movieclip_displayevents_enterframegoto` | 149 | 6.8s |  |
| 575 | `movieclip_displayevents_enterframeplay` | 48 | 6.6s |  |
| 576 | `movieclip_displayevents_enterframesymbol` | 149 | 25.5s |  |
| 577 | `movieclip_displayevents_exitframegoto` | 106 | 6.7s |  |
| 578 | `movieclip_displayevents_exitframeplay` | 44 | 6.6s |  |
| 579 | `movieclip_displayevents_exitframesymbol` | 135 | 6.7s |  |
| 580 | `movieclip_displayevents_looping` | 63 | 25.4s |  |
| 581 | `movieclip_displayevents_stopped` | 113 | 7.0s |  |
| 582 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 583 | `movieclip_displayevents_timeline` | 128 | 25.4s |  |
| 584 | `movieclip_drawrect` | 54 | 6.5s |  |
| 585 | `movieclip_frameconstruct_skipped` | 9 | 6.5s |  |
| 586 | `movieclip_goto_during_frame_script` | 15 | 6.6s |  |
| 587 | `movieclip_goto_overwrite` | 14 | 25.6s |  |
| 588 | `movieclip_goto_scene_last_frame_int` | 1 | 25.7s |  |
| 589 | `movieclip_goto_scene_last_frame_label` | 1 | 3.0s |  |
| 590 | `movieclip_gotoandplay` | 15 | 25.3s |  |
| 591 | `movieclip_gotoandstop` | 13 | 25.2s |  |
| 592 | `movieclip_gotoandstop_children` | 4 | 6.7s |  |
| 593 | `movieclip_gotoandstop_framescripts1` | 4 | 6.7s |  |
| 594 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 595 | `movieclip_gotoandstop_framescripts_self` | 7 | 27.4s |  |
| 596 | `movieclip_gotoandstop_queueing` | 12 | 25.8s |  |
| 597 | `movieclip_next_frame` | 2 | 6.7s |  |
| 598 | `movieclip_next_scene` | 6 | 25.1s |  |
| 599 | `movieclip_play` | 3 | 3.0s |  |
| 600 | `movieclip_prev_frame` | 3 | 6.3s |  |
| 601 | `movieclip_prev_scene` | 7 | 6.6s |  |
| 602 | `movieclip_properties` | 79 | 6.9s |  |
| 603 | `movieclip_queued_noop_goto_swf10` | 9 | 6.7s |  |
| 604 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 605 | `movieclip_scenes` | 11 | 6.6s |  |
| 606 | `movieclip_soundtransform` | 831 | 27.7s |  |
| 607 | `movieclip_stop` | 1 | 6.6s |  |
| 608 | `movieclip_super_is_symbol` | 20 | 7.0s |  |
| 609 | `movieclip_symbol_constr` | 8 | 7.0s |  |
| 610 | `movieclip_text_mousedown` | 1 | 6.9s |  |
| 611 | `movieclip_willtrigger` | 5 | 6.8s |  |
| 612 | `multiply` | 1058 | 19.3s |  |
| 613 | `namespace_constr` | 253 | 7.0s |  |
| 614 | `namespace_constr_args` | 1 | 6.6s |  |
| 615 | `namespace_enumeration_order` | 7 | 6.7s |  |
| 616 | `nan_scale` | 9 | 6.8s |  |
| 617 | `navigateToURL_target_normalize` | 107 | 27.3s |  |
| 618 | `negate` | 30 | 6.7s |  |
| 619 | `negative_volume_panned` | 0 | 7.0s |  |
| 620 | `nested_iteration` | 11 | 6.7s |  |
| 621 | `net_getClassByAlias` | 3 | 6.9s |  |
| 622 | `net_navigateToURL` | 57 | 6.8s |  |
| 623 | `net_stream_play_options` | 6 | 6.7s |  |
| 624 | `netconnection_close` | 55 | 6.6s |  |
| 625 | `netconnection_properties` | 78 | 6.7s |  |
| 626 | `netconnection_send_remote` | 50 | 7.0s |  |
| 627 | `netconnection_serialize_arrays` | 6 | 6.7s |  |
| 628 | `netstream_client` | 10 | 6.9s |  |
| 629 | `netstream_connect` | 7 | 6.7s |  |
| 630 | `newactivation_in_script_init` | 3 | 6.5s |  |
| 631 | `newclass_twice` | 3 | 6.6s |  |
| 632 | `nonconflicting_declarations` | 0 | 6.7s |  |
| 633 | `null_void_types` | 8 | 6.9s |  |
| 634 | `number_autoconv` | 21 | 3.3s |  |
| 635 | `number_autoconv_amf` | 132 | 6.8s |  |
| 636 | `number_autoconv_array_sort_32bit` | 1 | 6.6s |  |
| 637 | `number_constr` | 58 | 6.7s |  |
| 638 | `number_toexponential` | 378 | 6.6s |  |
| 639 | `number_toexponential2` | 35 | 6.6s |  |
| 640 | `number_tofixed` | 378 | 6.5s |  |
| 641 | `number_toprecision` | 350 | 6.6s |  |
| 642 | `obfuscated_class_names` | 3 | 6.5s |  |
| 643 | `object_enumeration` | 10 | 6.5s |  |
| 644 | `object_prototype` | 4 | 6.5s |  |
| 645 | `object_to_locale_string` | 2 | 6.4s |  |
| 646 | `object_to_string` | 2 | 6.3s |  |
| 647 | `object_value_of` | 2 | 2.9s |  |
| 648 | `op_coerce` | 54 | 3.2s |  |
| 649 | `op_coerce_x` | 54 | 6.6s |  |
| 650 | `op_escxattr` | 2 | 6.6s |  |
| 651 | `op_escxelem` | 2 | 6.6s |  |
| 652 | `op_lookupswitch` | 4 | 6.6s |  |
| 653 | `optimize_coerce` | 1 | 6.5s |  |
| 654 | `orphan_movie_complex` | 80 | 7.1s |  |
| 655 | `orphan_movie_reorder` | 111 | 25.7s |  |
| 656 | `package_namespace` | 7 | 6.6s |  |
| 657 | `param_default_value_has_zero_cpool_index` | 1 | 6.7s |  |
| 658 | `parent_early_access_child` | 16 | 7.0s |  |
| 659 | `parse_float` | 81 | 7.0s |  |
| 660 | `pixelbender_ceil` | 77 | 6.9s |  |
| 661 | `pixelbender_conditional` | 138 | 8.5s |  |
| 662 | `pixelbender_conversions` | 270 | 6.7s |  |
| 663 | `pixelbender_dithering` | 8 | 29.9s |  |
| 664 | `pixelbender_div` | 36 | 6.7s |  |
| 665 | `pixelbender_effect_BlurredFocus` | 0 | 32.2s |  |
| 666 | `pixelbender_effect_glassDisplace` | 0 | 12.1s |  |
| 667 | `pixelbender_effect_smudge` | 0 | 9.9s |  |
| 668 | `pixelbender_effect_tintype` | 0 | 9.1s |  |
| 669 | `pixelbender_effect_twirl` | 0 | 10.3s |  |
| 670 | `pixelbender_eof` | 7 | 6.5s |  |
| 671 | `pixelbender_images` | 0 | 8.8s |  |
| 672 | `pixelbender_input` | 103 | 25.7s |  |
| 673 | `pixelbender_logicalnot` | 20 | 6.5s |  |
| 674 | `pixelbender_malformed_data` | 190 | 25.6s |  |
| 675 | `pixelbender_multiple_out_params` | 1 | 3.0s |  |
| 676 | `pixelbender_no_out_param` | 6 | 6.4s |  |
| 677 | `pixelbender_outputs` | 13 | 6.6s |  |
| 678 | `pixelbender_padding_bytes` | 22 | 6.5s |  |
| 679 | `pixelbender_param_qualifier` | 512 | 6.6s |  |
| 680 | `pixelbender_parameters` | 1563 | 6.8s |  |
| 681 | `pixelbender_parameters_bool` | 240 | 6.7s |  |
| 682 | `pixelbender_parameters_int_vs_bool` | 54 | 6.6s |  |
| 683 | `pixelbender_parse_errors` | 6 | 6.5s |  |
| 684 | `pixelbender_rsqrt` | 24 | 6.5s |  |
| 685 | `pixelbender_select_kinds` | 8 | 6.6s |  |
| 686 | `pixelbender_shaderdata` | 49 | 6.5s |  |
| 687 | `pixelbender_shaderdata_setter` | 99 | 6.8s |  |
| 688 | `pixelbender_sign` | 60 | 6.6s |  |
| 689 | `pixelbender_vector_output` | 11 | 6.8s |  |
| 690 | `place_multiple` | 17 | 24.6s |  |
| 691 | `place_object_replace` | 9 | 6.6s |  |
| 692 | `place_object_replace_2` | 24 | 6.6s |  |
| 693 | `place_object_same_depth_frame` | 1 | 6.5s |  |
| 694 | `point` | 132 | 7.0s |  |
| 695 | `primitive_edge_cases` | 1 | 6.4s |  |
| 696 | `property_priority` | 22 | 6.3s |  |
| 697 | `property_priority_three_level` | 6 | 24.5s |  |
| 698 | `propertyisenumerable_namespaces` | 6 | 6.1s |  |
| 699 | `prototype_set_null` | 7 | 6.1s |  |
| 700 | `proxy_callproperty` | 24 | 6.2s |  |
| 701 | `proxy_deleteproperty` | 64 | 6.3s |  |
| 702 | `proxy_enumeration` | 34 | 6.2s |  |
| 703 | `proxy_getproperty` | 77 | 6.3s |  |
| 704 | `proxy_hasownproperty` | 8 | 6.2s |  |
| 705 | `proxy_hasproperty` | 32 | 6.2s |  |
| 706 | `proxy_serialize` | 9 | 6.2s |  |
| 707 | `proxy_setproperty` | 42 | 6.2s |  |
| 708 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.2s |  |
| 709 | `qname_constr` | 32 | 6.3s |  |
| 710 | `qname_constr_namespace` | 24 | 6.2s |  |
| 711 | `qname_enumeration` | 9 | 6.2s |  |
| 712 | `qname_indexing` | 23 | 6.2s |  |
| 713 | `qname_tostring` | 25 | 6.2s |  |
| 714 | `qname_valueof` | 29 | 6.2s |  |
| 715 | `regexp_constr` | 148 | 6.4s |  |
| 716 | `regexp_exec` | 19 | 6.2s |  |
| 717 | `regexp_extended` | 47 | 6.1s |  |
| 718 | `regexp_multiargs` | 1 | 6.1s |  |
| 719 | `regexp_test` | 27 | 2.8s |  |
| 720 | `regexp_toString` | 10 | 6.2s |  |
| 721 | `register_script_refresh` | 35 | 6.6s |  |
| 722 | `remove_child_clear_field` | 88 | 6.6s |  |
| 723 | `remove_dobj` | 3 | 6.1s |  |
| 724 | `resolve_order` | 4 | 6.1s |  |
| 725 | `responder_null_callbacks` | 1 | 6.1s |  |
| 726 | `rng` | 1 | 7.2s |  |
| 727 | `rootless` | 42 | 6.2s |  |
| 728 | `rshift` | 1058 | 15.7s |  |
| 729 | `sandbox_type_inherited` | 2 | 8.7s |  |
| 730 | `sandbox_type_local_file` | 1 | 6.5s |  |
| 731 | `sandbox_type_local_network` | 1 | 6.4s |  |
| 732 | `scene_constr` | 8 | 6.7s |  |
| 733 | `selection` | 239 | 7.0s |  |
| 734 | `set_local_0` | 31 | 6.6s |  |
| 735 | `set_property_is_enumerable` | 85 | 7.0s |  |
| 736 | `shaderparameter_value` | 4 | 6.6s |  |
| 737 | `shape_drawrect` | 54 | 6.7s |  |
| 738 | `shared_object_no_root` | 3 | 6.5s |  |
| 739 | `simplebutton_added_to_stage` | 45 | 25.5s |  |
| 740 | `simplebutton_childevents` | 86 | 26.0s |  |
| 741 | `simplebutton_childevents_nested` | 54 | 6.9s |  |
| 742 | `simplebutton_childevents_sprite` | 13 | 6.6s |  |
| 743 | `simplebutton_childprops` | 144 | 6.8s |  |
| 744 | `simplebutton_childshuffle` | 23 | 6.5s |  |
| 745 | `simplebutton_constr` | 36 | 6.9s |  |
| 746 | `simplebutton_constr_childevents` | 48 | 6.9s |  |
| 747 | `simplebutton_constr_params` | 42 | 6.7s |  |
| 748 | `simplebutton_mouseenabled` | 26 | 6.7s |  |
| 749 | `simplebutton_multi_children` | 19 | 6.8s |  |
| 750 | `simplebutton_structure` | 27 | 6.9s |  |
| 751 | `simplebutton_symbolclass` | 68 | 6.8s |  |
| 752 | `slot_disp_id_shared_numbering` | 1 | 25.2s |  |
| 753 | `slots_force_autoassigned` | 1 | 6.6s |  |
| 754 | `socket_after_disconnect` | 1 | 6.7s |  |
| 755 | `socket_close` | 2 | 6.6s |  |
| 756 | `socket_connect` | 4 | 6.6s |  |
| 757 | `socket_errors` | 56 | 7.1s |  |
| 758 | `socket_read_big` | 48 | 8.2s |  |
| 759 | `socket_read_little` | 48 | 3.0s |  |
| 760 | `socket_read_write_object` | 8 | 6.5s |  |
| 761 | `socket_write_big` | 15 | 6.7s |  |
| 762 | `socket_write_little` | 14 | 6.4s |  |
| 763 | `sound_embeddedprops` | 26 | 6.6s |  |
| 764 | `sound_play` | 19 | 6.7s |  |
| 765 | `sound_valueof` | 33 | 6.5s |  |
| 766 | `soundchannel_soundtransform` | 835 | 27.0s |  |
| 767 | `soundchannel_soundtransform_exists` | 5 | 25.1s |  |
| 768 | `soundchannel_stop` | 8 | 6.7s |  |
| 769 | `soundmixer_buffertime` | 5 | 6.5s |  |
| 770 | `soundmixer_stopall` | 6 | 6.5s |  |
| 771 | `soundtransform` | 442 | 8.7s |  |
| 772 | `sprite_with_frames` | 0 | 25.5s |  |
| 773 | `stage3d_agal_cross_product` | 0 | 9.1s |  |
| 774 | `stage3d_agal_upload_errors` | 66 | 9.1s |  |
| 775 | `stage3d_bitmap` | 0 | 30.3s |  |
| 776 | `stage3d_blend` | 81 | 29.3s |  |
| 777 | `stage3d_context3d_string_args` | 158 | 7.5s |  |
| 778 | `stage3d_errors` | 7 | 6.5s |  |
| 779 | `stage3d_errors_atf` | 3 | 7.8s |  |
| 780 | `stage3d_errors_swf_29` | 6 | 6.6s |  |
| 781 | `stage3d_float1_index` | 0 | 27.4s |  |
| 782 | `stage3d_fractal` | 0 | 28.1s |  |
| 783 | `stage3d_ignore_sampler_override` | 0 | 28.0s |  |
| 784 | `stage3d_multistage_triangle` | 3 | 9.3s |  |
| 785 | `stage3d_program_constants_bytearray_be` | 0 | 29.2s |  |
| 786 | `stage3d_program_constants_bytearray_le` | 0 | 9.8s |  |
| 787 | `stage3d_program_constants_invalid_input` | 21 | 7.4s |  |
| 788 | `stage3d_raytrace` | 0 | 31.5s |  |
| 789 | `stage3d_rotating_cube` | 0 | 10.0s |  |
| 790 | `stage3d_sampler` | 0 | 11.3s |  |
| 791 | `stage3d_sampler_partial_upload` | 0 | 9.6s |  |
| 792 | `stage3d_stencil` | 0 | 30.4s |  |
| 793 | `stage3d_texture` | 0 | 14.4s |  |
| 794 | `stage3d_texture_bytearray` | 0 | 11.0s |  |
| 795 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.4s |  |
| 796 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.6s |  |
| 797 | `stage3d_triangle` | 0 | 10.0s |  |
| 798 | `stage3d_triangle_bytes4` | 0 | 9.8s |  |
| 799 | `stage3d_triangle_float1` | 0 | 9.9s |  |
| 800 | `stage3d_triangle_index_upload` | 0 | 9.8s |  |
| 801 | `stage3d_x_y` | 22 | 7.1s |  |
| 802 | `stage_access` | 10 | 3.5s |  |
| 803 | `stage_displayobject_properties` | 24 | 7.0s |  |
| 804 | `stage_framerate_nan` | 7 | 3.6s |  |
| 805 | `stage_framerate_negative` | 6 | 7.0s |  |
| 806 | `stage_framerate_zero` | 6 | 7.0s |  |
| 807 | `stage_invalidate` | 38 | 7.2s |  |
| 808 | `stage_loaderinfo_properties` | 24 | 7.4s |  |
| 809 | `stage_mousechildren` | 2 | 7.0s |  |
| 810 | `stage_mouseenabled` | 15 | 6.9s |  |
| 811 | `stage_overriden_setters` | 31 | 7.1s |  |
| 812 | `stage_properties` | 30 | 6.9s |  |
| 813 | `stage_stage3Ds_vector` | 1 | 26.2s |  |
| 814 | `static_var_with_this_in_ctor` | 2 | 6.8s |  |
| 815 | `stored_properties` | 11 | 6.9s |  |
| 816 | `strict_equality` | 34 | 7.0s |  |
| 817 | `string_call` | 13 | 6.9s |  |
| 818 | `string_case` | 23 | 6.9s |  |
| 819 | `string_char_at` | 27 | 6.9s |  |
| 820 | `string_char_code_at` | 28 | 6.7s |  |
| 821 | `string_concat_fromcharcode` | 37 | 6.8s |  |
| 822 | `string_constr` | 25 | 7.0s |  |
| 823 | `string_indexof_lastindexof` | 87 | 8.8s |  |
| 824 | `string_length` | 16 | 6.8s |  |
| 825 | `string_locale_compare` | 39 | 7.1s |  |
| 826 | `string_match` | 51 | 7.0s |  |
| 827 | `string_relational_compare` | 4 | 6.7s |  |
| 828 | `string_replace` | 51 | 6.9s |  |
| 829 | `string_search` | 41 | 6.9s |  |
| 830 | `string_slice_substr_substring` | 170 | 7.9s |  |
| 831 | `string_split` | 29 | 6.8s |  |
| 832 | `string_substr_negative` | 21 | 6.7s |  |
| 833 | `string_substr_weird` | 182 | 6.6s |  |
| 834 | `subtract` | 1058 | 18.9s |  |
| 835 | `super_get_call` | 12 | 6.7s |  |
| 836 | `supercall_two_classobjects` | 2 | 6.7s |  |
| 837 | `swf8` | 1 | 6.6s |  |
| 838 | `swf_10_queued_goto_scripts_construct` | 52 | 7.1s |  |
| 839 | `swf_9_goto_in_enter_frame` | 17 | 6.8s |  |
| 840 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.0s |  |
| 841 | `swf_9_queued_goto_scripts` | 6 | 7.0s |  |
| 842 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 843 | `swf_9_versioning` | 2 | 6.8s |  |
| 844 | `swf_wrong_frame_count` | 38 | 7.2s |  |
| 845 | `swf_wrong_frame_count_isplaying` | 22 | 26.7s |  |
| 846 | `symbol_class_binary_data` | 8 | 6.9s |  |
| 847 | `symbol_class_conflict` | 4 | 7.4s |  |
| 848 | `symbol_class_root_not_zero` | 1 | 6.8s |  |
| 849 | `symbolclass_invalid_utf8` | 2 | 6.9s |  |
| 850 | `tab_ordering_automatic_advanced` | 184 | 6.7s |  |
| 851 | `tab_ordering_automatic_basic` | 45 | 5.8s |  |
| 852 | `tab_ordering_children` | 116 | 6.1s |  |
| 853 | `tab_ordering_custom_basic` | 34 | 5.7s |  |
| 854 | `tab_ordering_stage_tab_children` | 32 | 5.9s |  |
| 855 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.0s |  |
| 856 | `tab_ordering_tabbable` | 47 | 6.1s |  |
| 857 | `text_engine_fontdescription` | 27 | 5.8s |  |
| 858 | `text_run` | 7 | 5.6s |  |
| 859 | `textbox_click` | 37 | 23.9s |  |
| 860 | `textfield_event` | 66 | 5.9s |  |
| 861 | `textfield_focusin_event` | 9 | 5.7s |  |
| 862 | `textfield_input_dead_keys_windows` | 15 | 5.7s |  |
| 863 | `textfield_unload` | 39 | 23.8s |  |
| 864 | `textformat` | 1134 | 5.7s |  |
| 865 | `textformat_display` | 14 | 5.7s |  |
| 866 | `textformat_font_max_length` | 4 | 2.2s |  |
| 867 | `throw` | 3 | 5.8s |  |
| 868 | `timeline_scripts` | 3 | 5.8s |  |
| 869 | `timer` | 90 | 6.4s |  |
| 870 | `timer_events` | 3 | 5.9s |  |
| 871 | `timer_finished` | 11 | 2.5s |  |
| 872 | `timer_reset` | 8 | 6.1s |  |
| 873 | `timer_setdelay` | 5 | 5.9s |  |
| 874 | `trace` | 12 | 5.7s |  |
| 875 | `truthiness` | 30 | 2.5s |  |
| 876 | `try_catch` | 11 | 0.9s |  |
| 877 | `try_catch_typed` | 12 | 0.9s |  |
| 878 | `typeof` | 30 | 0.9s |  |
| 879 | `uint_constr` | 92 | 0.9s |  |
| 880 | `uint_tofixed` | 1215 | 0.9s |  |
| 881 | `uint_tostring` | 3375 | 0.9s |  |
| 882 | `unchecked_function` | 15 | 1.9s |  |
| 883 | `unescape` | 28 | 0.9s |  |
| 884 | `url_loader` | 25 | 0.9s |  |
| 885 | `urlrequest` | 18 | 0.9s |  |
| 886 | `urlstream_basic` | 5 | 0.9s |  |
| 887 | `urshift` | 1058 | 0.9s |  |
| 888 | `vector_class` | 36 | 0.9s |  |
| 889 | `vector_class_call` | 11 | 0.9s |  |
| 890 | `vector_coercion` | 66 | 0.9s |  |
| 891 | `vector_concat` | 90 | 0.9s |  |
| 892 | `vector_constr` | 107 | 0.9s |  |
| 893 | `vector_enumeration` | 5 | 0.9s |  |
| 894 | `vector_every` | 92 | 0.9s |  |
| 895 | `vector_filter` | 95 | 0.9s |  |
| 896 | `vector_holes` | 24 | 0.9s |  |
| 897 | `vector_indexof` | 302 | 0.9s |  |
| 898 | `vector_insertat` | 270 | 0.9s |  |
| 899 | `vector_int_access` | 4 | 0.9s |  |
| 900 | `vector_int_delete` | 11 | 0.9s |  |
| 901 | `vector_join` | 58 | 0.9s |  |
| 902 | `vector_lastindexof` | 302 | 0.9s |  |
| 903 | `vector_legacy` | 10 | 1.1s |  |
| 904 | `vector_map` | 85 | 0.9s |  |
| 905 | `vector_object_final` | 1 | 0.9s |  |
| 906 | `vector_object_toString` | 10 | 0.9s |  |
| 907 | `vector_pushpop` | 255 | 0.9s |  |
| 908 | `vector_reborrow_bug` | 10 | 7.6s |  |
| 909 | `vector_removeat` | 172 | 7.2s |  |
| 910 | `vector_reverse` | 232 | 7.2s |  |
| 911 | `vector_shiftunshift` | 252 | 6.0s |  |
| 912 | `vector_slice` | 331 | 7.7s |  |
| 913 | `vector_sort` | 905 | 14.9s |  |
| 914 | `vector_splice` | 693 | 9.9s |  |
| 915 | `vector_splice_fixed_bug_compat` | 4 | 6.1s |  |
| 916 | `vector_tostring` | 79 | 6.7s |  |
| 917 | `verification` | 8 | 6.2s |  |
| 918 | `verify_abnormal_loop` | 1 | 6.1s |  |
| 919 | `verify_dxns_without_flag` | 3 | 6.3s |  |
| 920 | `verify_exception_targets_edge_case` | 1 | 6.0s |  |
| 921 | `verify_jump_to_middle_of_op` | 1 | 6.0s |  |
| 922 | `verify_lookup_switch_edge_case` | 1 | 6.0s |  |
| 923 | `verify_stack` | 5 | 6.1s |  |
| 924 | `verify_unreachable_exception` | 2 | 6.0s |  |
| 925 | `versioned_isplaying` | 2 | 6.1s |  |
| 926 | `virtual_properties` | 16 | 6.3s |  |
| 927 | `with` | 4 | 6.1s |  |
| 928 | `wrong_arg_count` | 7 | 6.2s |  |
| 929 | `xml_abstract_equality` | 36 | 6.2s |  |
| 930 | `xml_advanced` | 52 | 6.1s |  |
| 931 | `xml_appendchild` | 10 | 6.1s |  |
| 932 | `xml_as_attribute` | 9 | 6.1s |  |
| 933 | `xml_attribute` | 35 | 6.2s |  |
| 934 | `xml_attribute_name` | 40 | 6.1s |  |
| 935 | `xml_basic` | 33 | 6.2s |  |
| 936 | `xml_child` | 25 | 6.2s |  |
| 937 | `xml_childindex` | 7 | 6.0s |  |
| 938 | `xml_children` | 43 | 6.6s |  |
| 939 | `xml_class_call` | 9 | 6.1s |  |
| 940 | `xml_contains` | 197 | 6.2s |  |
| 941 | `xml_copy` | 20 | 8.3s |  |
| 942 | `xml_ctor_from_tostring` | 23 | 6.9s |  |
| 943 | `xml_delete` | 114 | 6.8s |  |
| 944 | `xml_descendants` | 83 | 6.8s |  |
| 945 | `xml_elements` | 6 | 6.5s |  |
| 946 | `xml_equals_namespace_check` | 2 | 6.6s |  |
| 947 | `xml_explicit_use_namespace` | 5 | 6.8s |  |
| 948 | `xml_getdescendants_qname` | 21 | 6.7s |  |
| 949 | `xml_has_property_via_in` | 26 | 6.9s |  |
| 950 | `xml_hasownproperty` | 6 | 6.7s |  |
| 951 | `xml_ignore_white` | 6 | 6.7s |  |
| 952 | `xml_length` | 2 | 6.7s |  |
| 953 | `xml_list_as_attribute` | 9 | 6.7s |  |
| 954 | `xml_list_concat` | 20 | 6.8s |  |
| 955 | `xml_list_enumerate` | 4 | 6.7s |  |
| 956 | `xml_methods_settings` | 3 | 6.6s |  |
| 957 | `xml_mismatched_tag` | 37 | 6.6s |  |
| 958 | `xml_namespace` | 39 | 3.1s |  |
| 959 | `xml_namespace_methods` | 245 | 6.5s |  |
| 960 | `xml_namespaced_property` | 7 | 6.5s |  |
| 961 | `xml_no_namespace` | 1 | 6.5s |  |
| 962 | `xml_nodekind` | 3 | 6.7s |  |
| 963 | `xml_normalize` | 35 | 6.8s |  |
| 964 | `xml_notification_bubbling` | 361 | 6.8s |  |
| 965 | `xml_parent` | 8 | 6.7s |  |
| 966 | `xml_set_children` | 17 | 6.7s |  |
| 967 | `xml_set_name` | 34 | 6.8s |  |
| 968 | `xml_settings` | 6 | 3.2s |  |
| 969 | `xml_simple_complex_content` | 47 | 6.7s |  |
| 970 | `xml_socket` | 11 | 7.0s |  |
| 971 | `xml_text` | 7 | 6.8s |  |
| 972 | `xml_tostring` | 6 | 6.8s |  |
| 973 | `xml_tostring_namespace` | 12 | 6.6s |  |
| 974 | `xml_unescaping` | 23 | 6.7s |  |
| 975 | `xml_weird_ignores` | 54 | 6.8s |  |
| 976 | `xml_wildcard` | 11 | 6.7s |  |
| 977 | `xmldocument` | 254 | 6.8s |  |
| 978 | `xmlnode` | 3540 | 7.0s |  |
| 979 | `zero_frame_clip` | 3 | 7.3s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.6s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 5.5s |  |
| 3 | `blend_transform` | 1 | 1 | 4.8s |  |
| 4 | `coerce_property` | 3 | 3 | 6.8s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 3.1s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 6.6s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.7s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 26.6s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.5s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.4s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 5.4s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 7.1s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 28.8s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 28.9s |  |
| 15 | `int_toexponential` | 76 | 76 | 5.5s |  |
| 16 | `int_toprecision` | 441 | 441 | 5.8s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.8s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.5s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 25.2s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.1s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.7s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.5s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.4s |  |
| 24 | `uint_toexponential` | 100 | 100 | 0.9s |  |
| 25 | `uint_toprecision` | 433 | 433 | 0.9s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 23.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**59 tests** within reach

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
| 26 | `catch_class` | 83.3% | 5 | 6 | 1 |  |
| 27 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 28 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 29 | `matrix` | 83.1% | 281 | 338 | 57 |  |
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
| 40 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 41 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 42 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 43 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 44 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 45 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 46 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 47 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 48 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 49 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 50 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 51 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 52 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 53 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 54 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 55 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 56 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 57 | `pixelbender_effect_glassDisplace_shaderfilter` | 50.0% | 2 | 4 | 2 |  |
| 58 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 59 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.5s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 2.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**213 tests** with output mismatch, sorted by match rate (best first)

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
| 26 | `catch_class` | 83.3% | 5/6 | 6 | 6 |  |
| 27 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 28 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 29 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
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
| 40 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 41 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 42 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 43 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 44 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 45 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 46 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 47 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 48 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 49 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 50 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 51 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 52 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 53 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 54 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 57 | `pixelbender_effect_glassDisplace_shaderfilter` | 50.0% | 2/4 | 2 | 4 |  |
| 58 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 59 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 60 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 61 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 62 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 63 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 64 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 65 | `matrix3d` | 33.3% | 19/57 | 22 | 57 |  |
| 66 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 67 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 68 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 69 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 70 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 71 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 72 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 73 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 74 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 75 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 76 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 77 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 78 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 79 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 80 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 81 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 82 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 83 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 84 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 85 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 86 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 87 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 88 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 89 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 90 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 91 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 92 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 93 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 94 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 95 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 96 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 97 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 98 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 99 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 100 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 101 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 102 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 103 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 104 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 105 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 106 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 107 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 108 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 109 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 110 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 111 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 112 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 113 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 114 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 115 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 116 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 117 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 118 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 119 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 120 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 121 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 122 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 123 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 124 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 125 | `all_classes/display/swf9` | 0.1% | 2/1959 | 315 | 1959 |  |
| 126 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 127 | `all_classes/events/swf9` | 0.1% | 1/1030 | 178 | 1030 |  |
| 128 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 129 | `all_classes/events/swf10` | 0.1% | 1/1638 | 178 | 1638 |  |
| 130 | `all_classes/events/swf11` | 0.1% | 1/1750 | 178 | 1750 |  |
| 131 | `all_classes/events/swf12` | 0.1% | 1/1814 | 178 | 1814 |  |
| 132 | `all_classes/events/swf30` | 0.0% | 1/2353 | 178 | 2353 |  |
| 133 | `all_classes/display/swf10` | 0.0% | 1/2569 | 315 | 2569 |  |
| 134 | `all_classes/display/swf11` | 0.0% | 1/2593 | 315 | 2593 |  |
| 135 | `all_classes/display/swf12` | 0.0% | 1/2593 | 315 | 2593 |  |
| 136 | `all_classes/display/swf13` | 0.0% | 1/2671 | 315 | 2671 |  |
| 137 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 138 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 139 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 140 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 141 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 142 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 143 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 144 | `all_classes/display/swf30` | 0.0% | 0/2936 | 315 | 2936 |  |
| 145 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 146 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 147 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 148 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 149 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 150 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 151 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 152 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 153 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 154 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 155 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 156 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 157 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 158 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 159 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 160 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 161 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 162 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 163 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 164 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 165 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 166 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 167 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 168 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 169 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 170 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 171 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 172 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 173 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 174 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 175 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 176 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 177 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 178 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 179 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 180 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 181 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 182 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 183 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 184 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 185 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 186 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 187 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 188 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 189 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 190 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 191 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 192 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 193 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 194 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 195 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 196 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 197 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 198 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 199 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 200 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 201 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 202 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 203 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 204 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 205 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 206 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 207 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 208 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 209 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 210 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 211 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 212 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 213 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
