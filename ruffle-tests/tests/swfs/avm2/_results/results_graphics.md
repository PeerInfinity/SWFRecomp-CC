# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 01:47 UTC

**Git SHA**: `34171042fc`

**Run Duration**: 179m 54s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **934** (76.5%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **960** (78.6%) |
| Failing | 261 |
| Total expected lines | 151253 |
| Matching lines | 107980 (71.4%) |
| Mismatched lines | 43273 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 258 | 98.9% |
| Runtime Error | 3 | 1.1% |

## Passing Tests

**934 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 19.2s |  |
| 2 | `agal_compiler` | 13 | 9.3s |  |
| 3 | `air_datagram_socket` | 1 | 7.3s |  |
| 4 | `air_hidden_lookup` | 2 | 6.7s |  |
| 5 | `all_classes/security/swf11` | 3 | 6.7s |  |
| 6 | `amf_array_serialization` | 17 | 8.5s |  |
| 7 | `amf_custom_obj` | 26 | 6.7s |  |
| 8 | `amf_dictionary` | 9 | 6.5s |  |
| 9 | `amf_function` | 46 | 6.6s |  |
| 10 | `amf_invalid_date` | 2 | 6.5s |  |
| 11 | `amf_missing_prop` | 6 | 6.6s |  |
| 12 | `amf_nondynamic_function_prop` | 6 | 6.4s |  |
| 13 | `amf_setter_error` | 8 | 6.7s |  |
| 14 | `amf_vector` | 40 | 6.7s |  |
| 15 | `amf_xml` | 6 | 6.5s |  |
| 16 | `application_domain` | 4 | 6.6s |  |
| 17 | `array_access` | 18 | 6.5s |  |
| 18 | `array_access_interpreter` | 4 | 6.4s |  |
| 19 | `array_access_no_pubns` | 2 | 6.3s |  |
| 20 | `array_concat` | 41 | 6.5s |  |
| 21 | `array_constr` | 10 | 6.3s |  |
| 22 | `array_delete` | 44 | 6.5s |  |
| 23 | `array_enumeration` | 10 | 6.5s |  |
| 24 | `array_enumeration_elements` | 11 | 6.4s |  |
| 25 | `array_every` | 8 | 6.5s |  |
| 26 | `array_filter` | 6 | 6.5s |  |
| 27 | `array_foreach` | 18 | 6.6s |  |
| 28 | `array_hasownproperty` | 11 | 3.1s |  |
| 29 | `array_holes` | 9 | 6.6s |  |
| 30 | `array_index_max` | 84 | 6.4s |  |
| 31 | `array_indexof` | 25 | 6.6s |  |
| 32 | `array_join` | 26 | 6.7s |  |
| 33 | `array_lastindexof` | 29 | 6.8s |  |
| 34 | `array_length` | 14 | 6.6s |  |
| 35 | `array_literal` | 3 | 6.5s |  |
| 36 | `array_map` | 8 | 6.5s |  |
| 37 | `array_pop` | 52 | 6.6s |  |
| 38 | `array_push` | 24 | 6.6s |  |
| 39 | `array_reborrow_bug` | 6 | 6.7s |  |
| 40 | `array_reverse` | 28 | 6.7s |  |
| 41 | `array_shift` | 51 | 3.2s |  |
| 42 | `array_slice` | 39 | 6.8s |  |
| 43 | `array_some` | 8 | 6.7s |  |
| 44 | `array_sort` | 297 | 7.2s |  |
| 45 | `array_sort_fun_swf12` | 2 | 6.7s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 47 | `array_sort_random` | 210 | 6.8s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 6.4s |  |
| 49 | `array_sorton` | 545 | 7.3s |  |
| 50 | `array_sparse_ops` | 41 | 6.6s |  |
| 51 | `array_splice` | 133 | 6.7s |  |
| 52 | `array_splice2` | 428 | 6.8s |  |
| 53 | `array_splice_types` | 48 | 6.6s |  |
| 54 | `array_storage` | 8 | 6.5s |  |
| 55 | `array_tolocalestring` | 9 | 6.6s |  |
| 56 | `array_tostring` | 12 | 6.6s |  |
| 57 | `array_unshift` | 24 | 6.6s |  |
| 58 | `array_valueof` | 9 | 6.4s |  |
| 59 | `array_vector_null_callback` | 10 | 6.5s |  |
| 60 | `astype` | 28 | 6.6s |  |
| 61 | `astypelate` | 24 | 6.7s |  |
| 62 | `astypelate_propagates` | 1 | 6.5s |  |
| 63 | `asymmetric_key_events` | 11 | 6.7s |  |
| 64 | `av_networking_params` | 9 | 6.5s |  |
| 65 | `avm2_catchup_dobj` | 158 | 7.1s |  |
| 66 | `away3d_advanced_shallow_water_demo` | 0 | 81.4s |  |
| 67 | `bitand` | 1058 | 18.8s |  |
| 68 | `bitmap_constr` | 17 | 6.8s |  |
| 69 | `bitmap_data` | 1000 | 14.9s |  |
| 70 | `bitmap_pixelsnapping` | 2 | 26.6s |  |
| 71 | `bitmap_properties` | 23 | 6.6s |  |
| 72 | `bitmap_subclass` | 7 | 8.1s |  |
| 73 | `bitmap_subclass_properties` | 9 | 7.1s |  |
| 74 | `bitmap_timeline` | 9 | 6.7s |  |
| 75 | `bitmapdata_accuracy` | 1 | 44.7s |  |
| 76 | `bitmapdata_applyfilter_blur` | 0 | 26.8s |  |
| 77 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.4s |  |
| 78 | `bitmapdata_applyfilter_destpoint` | 0 | 26.1s |  |
| 79 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.4s |  |
| 80 | `bitmapdata_clone` | 13 | 6.8s |  |
| 81 | `bitmapdata_colortransform` | 0 | 7.0s |  |
| 82 | `bitmapdata_colortransform_oob` | 2 | 6.5s |  |
| 83 | `bitmapdata_constr` | 22 | 6.6s |  |
| 84 | `bitmapdata_constructor_from_timeline` | 1 | 6.9s |  |
| 85 | `bitmapdata_copychannel` | 0 | 30.3s |  |
| 86 | `bitmapdata_copypixels` | 23 | 28.7s |  |
| 87 | `bitmapdata_copypixels_blend_over` | 1 | 6.9s |  |
| 88 | `bitmapdata_copypixelstobytearray` | 39 | 6.9s |  |
| 89 | `bitmapdata_dispose` | 7 | 6.9s |  |
| 90 | `bitmapdata_draw` | 0 | 27.9s |  |
| 91 | `bitmapdata_draw_colortransform` | 0 | 7.0s |  |
| 92 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 27.2s |  |
| 93 | `bitmapdata_draw_filters` | 0 | 27.1s |  |
| 94 | `bitmapdata_draw_masks` | 0 | 6.8s |  |
| 95 | `bitmapdata_draw_rotation` | 0 | 7.1s |  |
| 96 | `bitmapdata_draw_self_via_graphic` | 0 | 7.0s |  |
| 97 | `bitmapdata_draw_stage` | 0 | 26.9s |  |
| 98 | `bitmapdata_drawwithquality` | 0 | 7.2s |  |
| 99 | `bitmapdata_embedded` | 9 | 7.3s |  |
| 100 | `bitmapdata_fillrect` | 0 | 7.1s |  |
| 101 | `bitmapdata_filter_sourcerect` | 0 | 27.4s |  |
| 102 | `bitmapdata_floodfill` | 35 | 6.8s |  |
| 103 | `bitmapdata_getpixels` | 39 | 27.2s |  |
| 104 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 105 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 106 | `bitmapdata_hittest` | 112 | 7.4s |  |
| 107 | `bitmapdata_hittest_threshold` | 18 | 6.8s |  |
| 108 | `bitmapdata_opaque` | 0 | 7.0s |  |
| 109 | `bitmapdata_pixeldissolve` | 1037 | 7.5s |  |
| 110 | `bitmapdata_pixeldissolve_image` | 0 | 7.2s |  |
| 111 | `bitmapdata_rectangle_rounding` | 16 | 6.7s |  |
| 112 | `bitmapdata_setpixels` | 286 | 7.0s |  |
| 113 | `bitmapdata_setvector` | 26 | 6.8s |  |
| 114 | `bitmapdata_sync` | 0 | 27.4s |  |
| 115 | `bitmapdata_threshold` | 176 | 7.6s |  |
| 116 | `bitnot` | 46 | 6.9s |  |
| 117 | `bitor` | 1058 | 19.4s |  |
| 118 | `bitxor` | 1058 | 19.4s |  |
| 119 | `blend_multiply_alpha` | 0 | 7.2s |  |
| 120 | `blend_scroll` | 0 | 7.0s |  |
| 121 | `boolean_constr` | 32 | 6.7s |  |
| 122 | `boolean_negation` | 30 | 6.7s |  |
| 123 | `boolean_tostring` | 8 | 6.6s |  |
| 124 | `broadcast_event` | 7 | 6.8s |  |
| 125 | `button_nested_frame` | 48 | 26.6s |  |
| 126 | `bytearray` | 48 | 7.0s |  |
| 127 | `bytearray_compress` | 31 | 6.7s |  |
| 128 | `bytearray_errors` | 24 | 6.8s |  |
| 129 | `bytearray_method_serialization` | 1 | 6.7s |  |
| 130 | `bytearray_oom` | 3 | 6.7s |  |
| 131 | `bytearray_readobject_amf0` | 50 | 6.9s |  |
| 132 | `bytearray_readobject_amf3` | 53 | 6.8s |  |
| 133 | `bytearray_readutf8bytes_with_bom` | 16 | 6.7s |  |
| 134 | `bytearray_serialization` | 3 | 6.7s |  |
| 135 | `bytearray_string_null` | 19 | 7.0s |  |
| 136 | `bytearray_tostring` | 15 | 6.9s |  |
| 137 | `bytearray_utf16` | 8 | 6.8s |  |
| 138 | `bytearray_writeobject` | 24 | 6.8s |  |
| 139 | `callee_in_initializer` | 6 | 6.8s |  |
| 140 | `callproplex_class` | 1 | 6.8s |  |
| 141 | `capabilities_resolution` | 8 | 27.0s |  |
| 142 | `catch_class` | 6 | 6.9s |  |
| 143 | `catch_scope_slot` | 7 | 3.5s |  |
| 144 | `checkfilter` | 4 | 3.4s |  |
| 145 | `class_call` | 32 | 7.2s |  |
| 146 | `class_cast_call` | 14 | 7.1s |  |
| 147 | `class_enumeration` | 4 | 7.1s |  |
| 148 | `class_has_own_property` | 2 | 7.1s |  |
| 149 | `class_init_interpreter_mode` | 1 | 6.9s |  |
| 150 | `class_is` | 32 | 6.9s |  |
| 151 | `class_methods` | 5 | 6.9s |  |
| 152 | `class_object_properties` | 10 | 6.9s |  |
| 153 | `class_singleton` | 18 | 6.9s |  |
| 154 | `class_supercalls_errors` | 35 | 7.2s |  |
| 155 | `class_supercalls_mismatched` | 26 | 7.0s |  |
| 156 | `class_superclass_wrong_order` | 1 | 25.2s |  |
| 157 | `class_to_locale_string` | 2 | 6.4s |  |
| 158 | `class_to_string` | 2 | 6.4s |  |
| 159 | `class_value_of` | 2 | 6.5s |  |
| 160 | `click_block` | 5 | 7.4s |  |
| 161 | `click_invisible` | 3 | 6.6s |  |
| 162 | `closures` | 12 | 6.5s |  |
| 163 | `coerce_return_type` | 40 | 6.6s |  |
| 164 | `coerce_return_type_fail` | 2 | 6.5s |  |
| 165 | `coerce_return_void` | 3 | 6.4s |  |
| 166 | `coerce_string` | 86 | 6.6s |  |
| 167 | `coerce_string_precision` | 28 | 6.5s |  |
| 168 | `coerce_to_primitive_side_effects` | 29 | 6.5s |  |
| 169 | `construct_errors_swf10` | 8 | 6.8s |  |
| 170 | `construct_frame_list` | 22 | 26.7s |  |
| 171 | `constructor_call` | 3 | 6.7s |  |
| 172 | `constructors_vs_timeline` | 5 | 26.9s |  |
| 173 | `constructprop_dynamic_primitive` | 7 | 6.8s |  |
| 174 | `control_flow_bool` | 4 | 6.7s |  |
| 175 | `control_flow_stricteq` | 8 | 6.7s |  |
| 176 | `convert_boolean` | 30 | 6.7s |  |
| 177 | `convert_integer` | 90 | 6.9s |  |
| 178 | `convert_number` | 56 | 6.8s |  |
| 179 | `convert_uinteger` | 90 | 6.8s |  |
| 180 | `cross_api_version_call_older` | 12 | 7.1s |  |
| 181 | `cryptscore` | 11 | 6.8s |  |
| 182 | `date` | 30 | 6.8s |  |
| 183 | `date_parse` | 36 | 6.4s |  |
| 184 | `declocal` | 46 | 6.4s |  |
| 185 | `declocal_i` | 46 | 6.5s |  |
| 186 | `decode_uri` | 71 | 6.8s |  |
| 187 | `decrement` | 46 | 6.5s |  |
| 188 | `decrement_i` | 46 | 3.0s |  |
| 189 | `default_values` | 7 | 6.4s |  |
| 190 | `dictionary_access` | 62 | 6.6s |  |
| 191 | `dictionary_access_no_pubns` | 2 | 6.3s |  |
| 192 | `dictionary_delete` | 101 | 6.9s |  |
| 193 | `dictionary_foreach` | 42 | 6.6s |  |
| 194 | `dictionary_hasownproperty` | 63 | 6.6s |  |
| 195 | `dictionary_in` | 62 | 6.7s |  |
| 196 | `dictionary_iter_modify` | 8 | 6.5s |  |
| 197 | `dictionary_namespaces` | 36 | 6.5s |  |
| 198 | `dictionary_primitive_keys` | 29 | 6.5s |  |
| 199 | `displayobject_alpha` | 277 | 6.5s |  |
| 200 | `displayobject_blendmode` | 0 | 6.7s |  |
| 201 | `displayobject_colortransform_nested` | 0 | 25.7s |  |
| 202 | `displayobject_from_enterframe` | 1 | 25.6s |  |
| 203 | `displayobject_getbounds_shape` | 0 | 26.0s |  |
| 204 | `displayobject_height` | 6052 | 26.0s |  |
| 205 | `displayobject_hittestobject` | 32 | 6.7s |  |
| 206 | `displayobject_invalid_floats` | 60 | 6.7s |  |
| 207 | `displayobject_invalid_props` | 3 | 6.6s |  |
| 208 | `displayobject_mask` | 3 | 7.0s |  |
| 209 | `displayobject_mask_self_referential` | 0 | 5.2s |  |
| 210 | `displayobject_metaData` | 3 | 5.1s |  |
| 211 | `displayobject_name` | 22 | 5.6s |  |
| 212 | `displayobject_name_from_timeline` | 24 | 5.4s |  |
| 213 | `displayobject_parent` | 12 | 5.2s |  |
| 214 | `displayobject_root` | 24 | 5.3s |  |
| 215 | `displayobject_rotation` | 1284 | 5.4s |  |
| 216 | `displayobject_set_matrix_nested` | 0 | 22.1s |  |
| 217 | `displayobject_set_name_loaded` | 3 | 5.5s |  |
| 218 | `displayobject_subclass` | 2 | 5.2s |  |
| 219 | `displayobject_visible` | 23 | 5.2s |  |
| 220 | `displayobject_width` | 4852 | 21.6s |  |
| 221 | `displayobject_x` | 614 | 5.3s |  |
| 222 | `displayobject_y` | 617 | 5.2s |  |
| 223 | `displayobjectcontainer_addchild` | 32 | 5.5s |  |
| 224 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.2s |  |
| 225 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.5s |  |
| 226 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.6s |  |
| 227 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.3s |  |
| 228 | `displayobjectcontainer_addchildat` | 42 | 5.3s |  |
| 229 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.4s |  |
| 230 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.3s |  |
| 231 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.3s |  |
| 232 | `displayobjectcontainer_contains` | 66 | 21.3s |  |
| 233 | `displayobjectcontainer_getchildat` | 4 | 5.2s |  |
| 234 | `displayobjectcontainer_getchildbyname` | 9 | 5.2s |  |
| 235 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.2s |  |
| 236 | `displayobjectcontainer_getchildindex` | 28 | 5.2s |  |
| 237 | `displayobjectcontainer_removechild` | 10 | 5.2s |  |
| 238 | `displayobjectcontainer_removechild_errors` | 4 | 5.2s |  |
| 239 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.3s |  |
| 240 | `displayobjectcontainer_removechildat` | 18 | 5.3s |  |
| 241 | `displayobjectcontainer_removechildren` | 51 | 5.4s |  |
| 242 | `displayobjectcontainer_setchildindex` | 42 | 5.0s |  |
| 243 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.7s |  |
| 244 | `displayobjectcontainer_swapchildren` | 42 | 5.3s |  |
| 245 | `displayobjectcontainer_swapchildrenat` | 42 | 5.3s |  |
| 246 | `displayobjectcontainer_timelineinstance` | 48 | 26.6s |  |
| 247 | `divide` | 1058 | 18.0s |  |
| 248 | `doabc_is_eager` | 1 | 25.4s |  |
| 249 | `documentclass` | 9 | 6.8s |  |
| 250 | `domain_memory` | 133 | 7.8s |  |
| 251 | `drag_drop` | 10 | 6.9s |  |
| 252 | `duplicate_defs` | 1 | 6.5s |  |
| 253 | `eager_init` | 1 | 6.7s |  |
| 254 | `edit_text_linkage` | 7 | 6.8s |  |
| 255 | `edittext_align` | 60 | 7.0s |  |
| 256 | `edittext_always_show_selection` | 0 | 25.9s |  |
| 257 | `edittext_antialiastype` | 296 | 6.9s |  |
| 258 | `edittext_at_point_methods_basic` | 16 | 8.0s |  |
| 259 | `edittext_autosize` | 39 | 7.1s |  |
| 260 | `edittext_autosize_align` | 0 | 26.4s |  |
| 261 | `edittext_autosize_height_dynamic` | 60 | 26.2s |  |
| 262 | `edittext_autosize_height_input` | 60 | 6.8s |  |
| 263 | `edittext_autosize_lazy_bounds_events` | 65 | 7.0s |  |
| 264 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.7s |  |
| 265 | `edittext_autosize_lazy_bounds_props` | 490 | 8.2s |  |
| 266 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.9s |  |
| 267 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.9s |  |
| 268 | `edittext_bottom_scroll_v_basic` | 210 | 6.8s |  |
| 269 | `edittext_bounds_scale` | 24 | 25.4s |  |
| 270 | `edittext_bullet` | 30 | 6.8s |  |
| 271 | `edittext_default_format` | 221 | 7.0s |  |
| 272 | `edittext_default_format_empty` | 136 | 7.0s |  |
| 273 | `edittext_empty_text_format` | 7 | 6.9s |  |
| 274 | `edittext_focus_selection` | 5 | 6.9s |  |
| 275 | `edittext_font_size` | 45 | 6.9s |  |
| 276 | `edittext_format_empty_font` | 8 | 6.8s |  |
| 277 | `edittext_get_char_index_at_point` | 4 | 27.3s |  |
| 278 | `edittext_get_line_index_at_point` | 2 | 27.1s |  |
| 279 | `edittext_get_line_index_of_char` | 76 | 8.0s |  |
| 280 | `edittext_getcharboundaries` | 172 | 7.4s |  |
| 281 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.5s |  |
| 282 | `edittext_getcharboundaries_scroll` | 85 | 6.6s |  |
| 283 | `edittext_getlinemetrics` | 146 | 6.7s |  |
| 284 | `edittext_html` | 3101 | 6.9s |  |
| 285 | `edittext_html_condensewhite` | 487 | 6.5s |  |
| 286 | `edittext_html_entity` | 4 | 6.7s |  |
| 287 | `edittext_html_font_size_swf12` | 267 | 6.5s |  |
| 288 | `edittext_html_font_size_swf13` | 273 | 6.2s |  |
| 289 | `edittext_html_roundtrip` | 17 | 6.4s |  |
| 290 | `edittext_ime_focus_lost` | 9 | 25.0s |  |
| 291 | `edittext_input_control` | 12 | 6.5s |  |
| 292 | `edittext_leading` | 9 | 6.7s |  |
| 293 | `edittext_letter_spacing` | 15 | 6.5s |  |
| 294 | `edittext_line_methods` | 294 | 7.8s |  |
| 295 | `edittext_line_metrics` | 11 | 26.6s |  |
| 296 | `edittext_margins` | 25 | 6.5s |  |
| 297 | `edittext_max_scroll_h_basic` | 475 | 6.7s |  |
| 298 | `edittext_max_scroll_v_basic` | 1000 | 6.6s |  |
| 299 | `edittext_mouse_selection` | 363 | 26.1s |  |
| 300 | `edittext_mousedown` | 3 | 6.8s |  |
| 301 | `edittext_mouseenabled` | 26 | 6.4s |  |
| 302 | `edittext_newline_character` | 22 | 6.3s |  |
| 303 | `edittext_newline_stripping` | 64 | 9.0s |  |
| 304 | `edittext_newlines` | 30 | 6.4s |  |
| 305 | `edittext_paragraph_methods` | 257 | 6.4s |  |
| 306 | `edittext_paste_events` | 8 | 6.6s |  |
| 307 | `edittext_paste_maxchars` | 4 | 6.4s |  |
| 308 | `edittext_paste_restrict` | 16 | 6.3s |  |
| 309 | `edittext_restrict` | 191 | 6.4s |  |
| 310 | `edittext_restrict_events` | 22 | 6.4s |  |
| 311 | `edittext_scrollh` | 10 | 6.3s |  |
| 312 | `edittext_selected_text` | 9 | 6.3s |  |
| 313 | `edittext_set_html_same` | 17 | 6.4s |  |
| 314 | `edittext_set_text_vs_html` | 9 | 6.4s |  |
| 315 | `edittext_stylesheet` | 536 | 6.9s |  |
| 316 | `edittext_stylesheet_custom_tag` | 76 | 6.5s |  |
| 317 | `edittext_stylesheet_display` | 272 | 6.5s |  |
| 318 | `edittext_underline` | 40 | 6.5s |  |
| 319 | `edittext_width_height` | 103 | 19.3s |  |
| 320 | `edittext_wordwrap_word` | 150 | 6.5s |  |
| 321 | `edittext_wrap_breaks` | 2375 | 6.9s |  |
| 322 | `empty_bounds` | 1 | 6.2s |  |
| 323 | `encode_uri_surrogate_pair_swf11` | 15 | 6.0s |  |
| 324 | `equals` | 512 | 10.0s |  |
| 325 | `error_geterrormessage` | 779 | 6.1s |  |
| 326 | `error_prototype` | 15 | 6.2s |  |
| 327 | `error_stack_trace_debug_swf17` | 0 | 23.7s |  |
| 328 | `error_stack_trace_debug_swf18` | 0 | 5.9s |  |
| 329 | `error_stack_trace_release_swf17` | 0 | 6.1s |  |
| 330 | `error_stack_trace_release_swf18` | 0 | 5.9s |  |
| 331 | `error_tostring` | 29 | 6.2s |  |
| 332 | `es3_inheritance` | 31 | 6.2s |  |
| 333 | `es4_inheritance` | 30 | 6.2s |  |
| 334 | `es4_interfaces` | 30 | 6.2s |  |
| 335 | `es4_method_binding` | 8 | 6.1s |  |
| 336 | `es4_oop_prototypes` | 14 | 6.2s |  |
| 337 | `es4_protected_inheritance` | 6 | 6.2s |  |
| 338 | `escape` | 71 | 6.2s |  |
| 339 | `event_bubbles` | 2 | 6.3s |  |
| 340 | `event_cancelable` | 2 | 6.2s |  |
| 341 | `event_clone` | 20 | 6.4s |  |
| 342 | `event_clone_error_redispatch` | 3 | 6.5s |  |
| 343 | `event_clone_on_redispatch` | 10 | 6.5s |  |
| 344 | `event_formattostring` | 31 | 6.4s |  |
| 345 | `event_isdefaultprevented` | 12 | 6.4s |  |
| 346 | `event_target_getter` | 5 | 3.0s |  |
| 347 | `event_target_set` | 9 | 6.2s |  |
| 348 | `event_type` | 1 | 19.6s |  |
| 349 | `event_valueof_tostring` | 18 | 6.7s |  |
| 350 | `eventdispatcher_dispatchevent` | 12 | 6.5s |  |
| 351 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.5s |  |
| 352 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.5s |  |
| 353 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.5s |  |
| 354 | `eventdispatcher_dispatchevent_this` | 5 | 6.4s |  |
| 355 | `eventdispatcher_haseventlistener` | 25 | 6.5s |  |
| 356 | `eventdispatcher_interface_invoke` | 1 | 6.3s |  |
| 357 | `eventdispatcher_tostring` | 10 | 6.4s |  |
| 358 | `eventdispatcher_willtrigger` | 25 | 6.3s |  |
| 359 | `falsiness` | 30 | 6.5s |  |
| 360 | `fast_index_access` | 12 | 6.6s |  |
| 361 | `filefilter_properties` | 4 | 6.4s |  |
| 362 | `filereference_browse_cancel` | 3 | 6.4s |  |
| 363 | `filereference_browse_select` | 9 | 6.5s |  |
| 364 | `filereference_load` | 31 | 6.5s |  |
| 365 | `filereference_save` | 16 | 6.5s |  |
| 366 | `filereference_save_and_browse` | 42 | 6.5s |  |
| 367 | `filereference_save_and_load` | 22 | 6.5s |  |
| 368 | `filereference_uninitialized` | 8 | 6.4s |  |
| 369 | `filereferencelist_browse_cancel` | 6 | 6.3s |  |
| 370 | `filereferencelist_browse_select` | 7 | 6.3s |  |
| 371 | `finddef` | 3 | 6.4s |  |
| 372 | `findprop_global_prototype` | 6 | 6.4s |  |
| 373 | `flash_xml` | 29 | 6.4s |  |
| 374 | `flash_xml_cloneNode` | 22 | 6.4s |  |
| 375 | `flash_xml_namespace` | 109 | 6.4s |  |
| 376 | `flash_xml_removeNode` | 60 | 6.5s |  |
| 377 | `focus_events_code` | 161 | 25.8s |  |
| 378 | `focus_events_key_basic` | 132 | 26.3s |  |
| 379 | `focus_events_key_navigation` | 53 | 6.7s |  |
| 380 | `focus_events_key_same_object` | 26 | 6.6s |  |
| 381 | `focus_events_mixed_key_mouse` | 100 | 25.8s |  |
| 382 | `focus_events_mouse_basic` | 260 | 34.1s |  |
| 383 | `focus_events_mouse_focusable` | 112 | 22.5s |  |
| 384 | `focus_events_mouse_same_object` | 40 | 22.1s |  |
| 385 | `focus_remove` | 20 | 22.4s |  |
| 386 | `focus_root_movie` | 4 | 22.1s |  |
| 387 | `focus_stage` | 1 | 5.4s |  |
| 388 | `focusrect` | 18 | 5.9s |  |
| 389 | `focusrect_focuslost` | 9 | 5.4s |  |
| 390 | `focusrect_property` | 110 | 5.4s |  |
| 391 | `font_description_clone` | 14 | 5.3s |  |
| 392 | `font_embedded` | 24 | 5.7s |  |
| 393 | `font_enumeratefonts` | 41 | 5.9s |  |
| 394 | `font_enumeratefonts_filter` | 4 | 22.2s |  |
| 395 | `font_hasglyphs` | 40 | 5.6s |  |
| 396 | `framelabel_constr` | 5 | 5.3s |  |
| 397 | `function_call` | 12 | 5.5s |  |
| 398 | `function_call_arguments` | 46 | 5.4s |  |
| 399 | `function_call_arguments_enumerate` | 5 | 5.3s |  |
| 400 | `function_call_coercion` | 108 | 5.6s |  |
| 401 | `function_call_default` | 6 | 5.2s |  |
| 402 | `function_call_rest` | 22 | 5.5s |  |
| 403 | `function_call_types` | 3 | 5.4s |  |
| 404 | `function_call_via_apply` | 11 | 5.5s |  |
| 405 | `function_call_via_call` | 3 | 5.3s |  |
| 406 | `function_display_anonymous` | 7 | 2.3s |  |
| 407 | `function_length` | 6 | 5.3s |  |
| 408 | `function_object` | 2 | 5.5s |  |
| 409 | `function_proto` | 5 | 5.5s |  |
| 410 | `function_proto_created` | 61 | 5.4s |  |
| 411 | `function_to_locale_string` | 4 | 5.4s |  |
| 412 | `function_to_string` | 4 | 5.3s |  |
| 413 | `function_type` | 6 | 5.3s |  |
| 414 | `function_unbound_this` | 51 | 5.8s |  |
| 415 | `function_value_of` | 4 | 5.3s |  |
| 416 | `get_definition_by_name` | 11 | 5.3s |  |
| 417 | `get_qualified_class_name` | 20 | 19.6s |  |
| 418 | `get_qualified_super_class_name` | 18 | 6.5s |  |
| 419 | `get_slot_edge_cases` | 1 | 25.0s |  |
| 420 | `get_timer` | 2 | 6.5s |  |
| 421 | `getglobalslot` | 1 | 6.4s |  |
| 422 | `getouterscope` | 8 | 6.4s |  |
| 423 | `getter_different_namespace_setter` | 2 | 6.3s |  |
| 424 | `goto_button_nested_framescript` | 28 | 25.6s |  |
| 425 | `goto_in_constructframe` | 12 | 6.8s |  |
| 426 | `goto_in_scene_last_frame` | 2 | 25.1s |  |
| 427 | `goto_methods` | 56 | 6.7s |  |
| 428 | `goto_methods_swfver10` | 8 | 6.5s |  |
| 429 | `goto_nested_construct_sibling` | 18 | 7.0s |  |
| 430 | `goto_nested_framescript` | 9 | 6.6s |  |
| 431 | `goto_on_orphan` | 15 | 6.7s |  |
| 432 | `graphics_bad_direct_commands` | 5 | 7.2s |  |
| 433 | `graphics_bitmap_fill` | 0 | 8.4s |  |
| 434 | `graphics_bitmaps` | 0 | 7.2s |  |
| 435 | `graphics_direct_commands` | 0 | 7.1s |  |
| 436 | `graphics_draw_triangles` | 98 | 25.9s |  |
| 437 | `graphics_gradients` | 0 | 6.8s |  |
| 438 | `graphics_gradients_nulls` | 0 | 6.7s |  |
| 439 | `graphics_path` | 56 | 6.5s |  |
| 440 | `graphics_round_rects` | 0 | 6.5s |  |
| 441 | `graphics_simple_shapes` | 0 | 6.7s |  |
| 442 | `greaterequals` | 512 | 10.5s |  |
| 443 | `greaterthan` | 512 | 10.4s |  |
| 444 | `has_own_property` | 102 | 7.0s |  |
| 445 | `hasownproperty_namespaces` | 2 | 6.4s |  |
| 446 | `hello_world` | 1 | 6.4s |  |
| 447 | `hittest_morph` | 30 | 6.6s |  |
| 448 | `if_eq` | 10 | 6.5s |  |
| 449 | `if_gt` | 1 | 6.5s |  |
| 450 | `if_gte` | 10 | 19.9s |  |
| 451 | `if_lt` | 1 | 6.7s |  |
| 452 | `if_lte` | 10 | 6.5s |  |
| 453 | `if_ne` | 7 | 3.2s |  |
| 454 | `if_stricteq` | 6 | 6.7s |  |
| 455 | `if_strictne` | 11 | 6.7s |  |
| 456 | `ime_linux_dead_keys` | 10 | 6.8s |  |
| 457 | `in` | 102 | 7.0s |  |
| 458 | `inclocal` | 46 | 6.6s |  |
| 459 | `inclocal_i` | 46 | 6.7s |  |
| 460 | `increment` | 46 | 6.6s |  |
| 461 | `increment_i` | 46 | 6.6s |  |
| 462 | `indexing_delete` | 75 | 6.6s |  |
| 463 | `instanceof` | 58 | 6.9s |  |
| 464 | `instantiation_on_enter_frame` | 7 | 25.3s |  |
| 465 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.6s |  |
| 466 | `int_constr` | 92 | 6.5s |  |
| 467 | `int_edge_cases` | 19 | 6.7s |  |
| 468 | `int_instanceof` | 3 | 6.5s |  |
| 469 | `int_tofixed` | 1215 | 6.5s |  |
| 470 | `int_tostring` | 3375 | 6.5s |  |
| 471 | `interactiveobject_enabled` | 25 | 6.5s |  |
| 472 | `interface_namespaces` | 78 | 6.8s |  |
| 473 | `is_finite` | 46 | 6.7s |  |
| 474 | `is_nan` | 46 | 6.5s |  |
| 475 | `is_prototype_of` | 12 | 6.6s |  |
| 476 | `issue_10221` | 2 | 6.6s |  |
| 477 | `issue_13780` | 12 | 6.6s |  |
| 478 | `issue_14901` | 1 | 6.5s |  |
| 479 | `issue_17675_edittext_paste_maxchars` | 1 | 6.6s |  |
| 480 | `issue_5292` | 5 | 6.6s |  |
| 481 | `issue_8630` | 2 | 25.1s |  |
| 482 | `issue_8630_scriptremove` | 11 | 6.6s |  |
| 483 | `istype` | 24 | 3.2s |  |
| 484 | `istypelate` | 58 | 6.9s |  |
| 485 | `istypelate_coerce` | 198 | 15.4s |  |
| 486 | `jpeg_loader_context` | 6 | 4.4s |  |
| 487 | `json_errors` | 9 | 19.4s |  |
| 488 | `json_parse` | 21 | 4.9s |  |
| 489 | `json_stringify` | 12 | 5.2s |  |
| 490 | `json_stringify_order` | 1 | 4.9s |  |
| 491 | `json_version_gated` | 1 | 4.7s |  |
| 492 | `key_input_80percent` | 1812 | 4.8s |  |
| 493 | `key_input_location` | 126 | 5.1s |  |
| 494 | `key_input_numpad` | 384 | 4.6s |  |
| 495 | `lazyinit` | 17 | 4.7s |  |
| 496 | `lessequals` | 512 | 7.1s |  |
| 497 | `lessthan` | 512 | 6.7s |  |
| 498 | `loader_bitmap_transparency` | 14 | 4.6s |  |
| 499 | `loader_bytes_unknown_content` | 14 | 4.7s |  |
| 500 | `loader_child_getdefinition` | 5 | 5.4s |  |
| 501 | `loader_duplicate_coerce` | 3 | 5.5s |  |
| 502 | `loader_duplicate_coerce_new_domain` | 4 | 5.4s |  |
| 503 | `loader_error_in_root_ctor` | 4 | 5.5s |  |
| 504 | `loader_events` | 92 | 6.4s |  |
| 505 | `loader_image` | 8 | 5.7s |  |
| 506 | `loader_jpegxr` | 2 | 22.3s |  |
| 507 | `loader_jpegxr_alpha` | 1 | 20.5s |  |
| 508 | `loader_loadbytes_events` | 30 | 5.0s |  |
| 509 | `loader_loadbytes_invalid_png` | 4 | 18.0s |  |
| 510 | `loader_loadbytes_url` | 12 | 4.7s |  |
| 511 | `loader_loaderurl` | 6 | 4.9s |  |
| 512 | `loader_noninteractive_try_click_root` | 5 | 19.0s |  |
| 513 | `loader_reuse` | 38 | 4.5s |  |
| 514 | `loader_unknown_content` | 24 | 4.8s |  |
| 515 | `loader_visibility_interactive` | 1 | 4.9s |  |
| 516 | `loaderinfo_events` | 7 | 4.7s |  |
| 517 | `loaderinfo_loadurl` | 12 | 14.4s |  |
| 518 | `loaderinfo_more` | 6 | 5.1s |  |
| 519 | `loaderinfo_properties` | 18 | 5.1s |  |
| 520 | `loaderinfo_properties_not_loaded` | 23 | 4.5s |  |
| 521 | `loaderinfo_root` | 10 | 4.5s |  |
| 522 | `loaderinfo_root_allows` | 2 | 4.5s |  |
| 523 | `localconnection_send` | 4 | 4.5s |  |
| 524 | `lshift` | 1058 | 12.3s |  |
| 525 | `mask_reapply` | 1 | 4.9s |  |
| 526 | `math` | 497 | 5.0s |  |
| 527 | `missing_external_interface` | 10 | 4.3s |  |
| 528 | `modulo` | 1058 | 11.5s |  |
| 529 | `morph_shape` | 2 | 18.3s |  |
| 530 | `mouse_children` | 192 | 18.9s |  |
| 531 | `mouse_click_events` | 90 | 17.9s |  |
| 532 | `mouse_double_click_events` | 188 | 4.4s |  |
| 533 | `mouse_empty_parent` | 4 | 4.7s |  |
| 534 | `mouse_over_while_dragging` | 3 | 4.5s |  |
| 535 | `mouse_pick_button_mode` | 2 | 4.7s |  |
| 536 | `mouse_pick_dobj_mask` | 4 | 4.6s |  |
| 537 | `mouse_pick_masking` | 7 | 18.4s |  |
| 538 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 18.6s |  |
| 539 | `mouse_pick_non_interactive_dobj_mask` | 3 | 4.6s |  |
| 540 | `mouse_pick_text` | 8 | 4.7s |  |
| 541 | `mouse_sibling` | 8 | 4.5s |  |
| 542 | `mouse_wheel_events` | 36 | 19.2s |  |
| 543 | `mouseevent_constr` | 66 | 4.7s |  |
| 544 | `mouseevent_stagexy` | 35 | 4.5s |  |
| 545 | `mouseevent_valueof_tostring` | 28 | 4.5s |  |
| 546 | `movieclip_addframescript` | 3 | 19.2s |  |
| 547 | `movieclip_child_property` | 16 | 4.7s |  |
| 548 | `movieclip_constr` | 21 | 19.1s |  |
| 549 | `movieclip_currentlabels` | 17 | 24.6s |  |
| 550 | `movieclip_currentlabels_dupes1` | 46 | 24.7s |  |
| 551 | `movieclip_currentlabels_dupes2` | 30 | 6.3s |  |
| 552 | `movieclip_currentlabels_dupes3` | 67 | 6.3s |  |
| 553 | `movieclip_currentscene` | 12 | 6.5s |  |
| 554 | `movieclip_dispatchevent` | 430 | 6.4s |  |
| 555 | `movieclip_dispatchevent_cancel` | 102 | 6.5s |  |
| 556 | `movieclip_dispatchevent_handlerorder` | 251 | 6.4s |  |
| 557 | `movieclip_dispatchevent_selfadd` | 80 | 6.3s |  |
| 558 | `movieclip_dispatchevent_target` | 899 | 6.4s |  |
| 559 | `movieclip_displayevents` | 96 | 24.8s |  |
| 560 | `movieclip_displayevents_clickgoto` | 676 | 6.8s |  |
| 561 | `movieclip_displayevents_clickgoto2` | 2001 | 6.9s |  |
| 562 | `movieclip_displayevents_clickplay` | 575 | 6.5s |  |
| 563 | `movieclip_displayevents_clicksymbol` | 562 | 6.6s |  |
| 564 | `movieclip_displayevents_constructframegoto` | 140 | 6.7s |  |
| 565 | `movieclip_displayevents_constructframeplay` | 50 | 6.6s |  |
| 566 | `movieclip_displayevents_constructframesymbol` | 144 | 6.5s |  |
| 567 | `movieclip_displayevents_dblhandler` | 21 | 6.5s |  |
| 568 | `movieclip_displayevents_enterframegoto` | 149 | 6.6s |  |
| 569 | `movieclip_displayevents_enterframeplay` | 48 | 6.4s |  |
| 570 | `movieclip_displayevents_enterframesymbol` | 149 | 24.8s |  |
| 571 | `movieclip_displayevents_exitframegoto` | 106 | 6.4s |  |
| 572 | `movieclip_displayevents_exitframeplay` | 44 | 6.4s |  |
| 573 | `movieclip_displayevents_exitframesymbol` | 135 | 6.5s |  |
| 574 | `movieclip_displayevents_looping` | 63 | 24.9s |  |
| 575 | `movieclip_displayevents_stopped` | 113 | 6.8s |  |
| 576 | `movieclip_displayevents_swap` | 96 | 2.8s |  |
| 577 | `movieclip_displayevents_timeline` | 128 | 24.8s |  |
| 578 | `movieclip_drawrect` | 54 | 6.3s |  |
| 579 | `movieclip_frameconstruct_skipped` | 9 | 6.5s |  |
| 580 | `movieclip_goto_during_frame_script` | 15 | 6.4s |  |
| 581 | `movieclip_goto_overwrite` | 14 | 24.7s |  |
| 582 | `movieclip_goto_scene_last_frame_int` | 1 | 24.7s |  |
| 583 | `movieclip_goto_scene_last_frame_label` | 1 | 6.2s |  |
| 584 | `movieclip_gotoandplay` | 15 | 24.5s |  |
| 585 | `movieclip_gotoandstop` | 13 | 24.4s |  |
| 586 | `movieclip_gotoandstop_children` | 4 | 6.4s |  |
| 587 | `movieclip_gotoandstop_framescripts1` | 4 | 6.3s |  |
| 588 | `movieclip_gotoandstop_framescripts2` | 4 | 2.9s |  |
| 589 | `movieclip_gotoandstop_framescripts_self` | 7 | 39.0s |  |
| 590 | `movieclip_gotoandstop_queueing` | 12 | 25.6s |  |
| 591 | `movieclip_next_frame` | 2 | 6.9s |  |
| 592 | `movieclip_next_scene` | 6 | 25.6s |  |
| 593 | `movieclip_play` | 3 | 6.6s |  |
| 594 | `movieclip_prev_frame` | 3 | 6.4s |  |
| 595 | `movieclip_prev_scene` | 7 | 6.7s |  |
| 596 | `movieclip_properties` | 79 | 6.9s |  |
| 597 | `movieclip_queued_noop_goto_swf10` | 9 | 6.7s |  |
| 598 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 599 | `movieclip_scenes` | 11 | 6.6s |  |
| 600 | `movieclip_soundtransform` | 831 | 27.5s |  |
| 601 | `movieclip_stop` | 1 | 6.5s |  |
| 602 | `movieclip_super_is_symbol` | 20 | 7.0s |  |
| 603 | `movieclip_symbol_constr` | 8 | 6.8s |  |
| 604 | `movieclip_text_mousedown` | 1 | 6.7s |  |
| 605 | `movieclip_willtrigger` | 5 | 6.9s |  |
| 606 | `multiply` | 1058 | 17.9s |  |
| 607 | `namespace_constr` | 253 | 6.9s |  |
| 608 | `namespace_constr_args` | 1 | 6.5s |  |
| 609 | `namespace_enumeration_order` | 7 | 6.7s |  |
| 610 | `nan_scale` | 9 | 6.6s |  |
| 611 | `navigateToURL_target_normalize` | 107 | 27.1s |  |
| 612 | `negate` | 30 | 6.7s |  |
| 613 | `negative_volume_panned` | 0 | 6.9s |  |
| 614 | `nested_iteration` | 11 | 6.6s |  |
| 615 | `net_getClassByAlias` | 3 | 6.7s |  |
| 616 | `net_navigateToURL` | 57 | 6.7s |  |
| 617 | `net_stream_play_options` | 6 | 6.6s |  |
| 618 | `netconnection_close` | 55 | 6.7s |  |
| 619 | `netconnection_properties` | 78 | 6.8s |  |
| 620 | `netconnection_send_remote` | 50 | 7.0s |  |
| 621 | `netconnection_serialize_arrays` | 6 | 6.7s |  |
| 622 | `netstream_client` | 10 | 6.8s |  |
| 623 | `netstream_connect` | 7 | 6.7s |  |
| 624 | `newactivation_in_script_init` | 3 | 6.4s |  |
| 625 | `newclass_twice` | 3 | 6.3s |  |
| 626 | `nonconflicting_declarations` | 0 | 6.4s |  |
| 627 | `null_void_types` | 8 | 6.4s |  |
| 628 | `number_autoconv` | 21 | 6.4s |  |
| 629 | `number_autoconv_amf` | 132 | 6.3s |  |
| 630 | `number_autoconv_array_sort_32bit` | 1 | 6.3s |  |
| 631 | `number_constr` | 58 | 6.5s |  |
| 632 | `number_toexponential` | 378 | 6.4s |  |
| 633 | `number_toexponential2` | 35 | 6.3s |  |
| 634 | `number_tofixed` | 378 | 6.3s |  |
| 635 | `number_toprecision` | 350 | 6.4s |  |
| 636 | `obfuscated_class_names` | 3 | 6.3s |  |
| 637 | `object_enumeration` | 10 | 6.5s |  |
| 638 | `object_prototype` | 4 | 6.4s |  |
| 639 | `object_to_locale_string` | 2 | 6.4s |  |
| 640 | `object_to_string` | 2 | 6.3s |  |
| 641 | `object_value_of` | 2 | 2.9s |  |
| 642 | `op_coerce` | 54 | 6.5s |  |
| 643 | `op_coerce_x` | 54 | 6.5s |  |
| 644 | `op_escxattr` | 2 | 6.4s |  |
| 645 | `op_escxelem` | 2 | 6.3s |  |
| 646 | `op_lookupswitch` | 4 | 6.3s |  |
| 647 | `optimize_coerce` | 1 | 6.2s |  |
| 648 | `orphan_movie_complex` | 80 | 6.8s |  |
| 649 | `orphan_movie_reorder` | 111 | 25.1s |  |
| 650 | `package_namespace` | 7 | 6.2s |  |
| 651 | `param_default_value_has_zero_cpool_index` | 1 | 6.3s |  |
| 652 | `parent_early_access_child` | 16 | 6.6s |  |
| 653 | `parse_float` | 81 | 6.6s |  |
| 654 | `pixelbender_effect_BlurredFocus` | 0 | 29.0s |  |
| 655 | `pixelbender_effect_glassDisplace` | 0 | 11.9s |  |
| 656 | `pixelbender_effect_smudge` | 0 | 9.8s |  |
| 657 | `pixelbender_effect_tintype` | 0 | 9.1s |  |
| 658 | `pixelbender_effect_twirl` | 0 | 10.1s |  |
| 659 | `pixelbender_images` | 0 | 8.7s |  |
| 660 | `place_multiple` | 17 | 25.0s |  |
| 661 | `place_object_replace` | 9 | 6.6s |  |
| 662 | `place_object_replace_2` | 24 | 6.7s |  |
| 663 | `place_object_same_depth_frame` | 1 | 6.5s |  |
| 664 | `point` | 132 | 7.0s |  |
| 665 | `primitive_edge_cases` | 1 | 6.4s |  |
| 666 | `property_priority` | 22 | 7.1s |  |
| 667 | `property_priority_three_level` | 6 | 25.9s |  |
| 668 | `propertyisenumerable_namespaces` | 6 | 6.7s |  |
| 669 | `prototype_set_null` | 7 | 6.7s |  |
| 670 | `proxy_callproperty` | 24 | 6.7s |  |
| 671 | `proxy_deleteproperty` | 64 | 6.8s |  |
| 672 | `proxy_enumeration` | 34 | 6.7s |  |
| 673 | `proxy_getproperty` | 77 | 6.9s |  |
| 674 | `proxy_hasownproperty` | 8 | 6.7s |  |
| 675 | `proxy_hasproperty` | 32 | 6.9s |  |
| 676 | `proxy_serialize` | 9 | 6.7s |  |
| 677 | `proxy_setproperty` | 42 | 6.8s |  |
| 678 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.7s |  |
| 679 | `qname_constr` | 32 | 6.7s |  |
| 680 | `qname_constr_namespace` | 24 | 6.7s |  |
| 681 | `qname_enumeration` | 9 | 6.7s |  |
| 682 | `qname_indexing` | 23 | 6.7s |  |
| 683 | `qname_tostring` | 25 | 6.7s |  |
| 684 | `qname_valueof` | 29 | 6.8s |  |
| 685 | `regexp_constr` | 148 | 6.9s |  |
| 686 | `regexp_exec` | 19 | 6.8s |  |
| 687 | `regexp_extended` | 47 | 6.7s |  |
| 688 | `regexp_multiargs` | 1 | 6.6s |  |
| 689 | `regexp_test` | 27 | 6.7s |  |
| 690 | `regexp_toString` | 10 | 6.7s |  |
| 691 | `register_script_refresh` | 35 | 7.3s |  |
| 692 | `remove_child_clear_field` | 88 | 7.1s |  |
| 693 | `remove_dobj` | 3 | 6.7s |  |
| 694 | `resolve_order` | 4 | 6.7s |  |
| 695 | `responder_null_callbacks` | 1 | 6.7s |  |
| 696 | `rng` | 1 | 8.0s |  |
| 697 | `rootless` | 42 | 6.9s |  |
| 698 | `rshift` | 1058 | 18.2s |  |
| 699 | `sandbox_type_inherited` | 2 | 20.2s |  |
| 700 | `sandbox_type_local_file` | 1 | 6.9s |  |
| 701 | `sandbox_type_local_network` | 1 | 6.5s |  |
| 702 | `scene_constr` | 8 | 6.8s |  |
| 703 | `selection` | 239 | 7.2s |  |
| 704 | `set_local_0` | 31 | 6.7s |  |
| 705 | `set_property_is_enumerable` | 85 | 7.2s |  |
| 706 | `shape_drawrect` | 54 | 6.8s |  |
| 707 | `shared_object_no_root` | 3 | 6.6s |  |
| 708 | `simplebutton_added_to_stage` | 45 | 26.4s |  |
| 709 | `simplebutton_childevents` | 86 | 27.0s |  |
| 710 | `simplebutton_childevents_nested` | 54 | 7.1s |  |
| 711 | `simplebutton_childevents_sprite` | 13 | 6.7s |  |
| 712 | `simplebutton_childprops` | 144 | 7.0s |  |
| 713 | `simplebutton_childshuffle` | 23 | 6.7s |  |
| 714 | `simplebutton_constr` | 36 | 7.0s |  |
| 715 | `simplebutton_constr_childevents` | 48 | 7.0s |  |
| 716 | `simplebutton_constr_params` | 42 | 6.9s |  |
| 717 | `simplebutton_mouseenabled` | 26 | 6.8s |  |
| 718 | `simplebutton_multi_children` | 19 | 6.9s |  |
| 719 | `simplebutton_structure` | 27 | 6.9s |  |
| 720 | `simplebutton_symbolclass` | 68 | 7.2s |  |
| 721 | `slot_disp_id_shared_numbering` | 1 | 26.0s |  |
| 722 | `slots_force_autoassigned` | 1 | 6.9s |  |
| 723 | `socket_after_disconnect` | 1 | 6.9s |  |
| 724 | `socket_close` | 2 | 6.8s |  |
| 725 | `socket_connect` | 4 | 6.8s |  |
| 726 | `socket_errors` | 56 | 7.3s |  |
| 727 | `socket_read_big` | 48 | 19.5s |  |
| 728 | `socket_read_little` | 48 | 2.9s |  |
| 729 | `socket_read_write_object` | 8 | 6.4s |  |
| 730 | `socket_write_big` | 15 | 6.7s |  |
| 731 | `socket_write_little` | 14 | 6.4s |  |
| 732 | `sound_embeddedprops` | 26 | 6.8s |  |
| 733 | `sound_play` | 19 | 6.7s |  |
| 734 | `sound_valueof` | 33 | 6.6s |  |
| 735 | `soundchannel_soundtransform` | 835 | 27.1s |  |
| 736 | `soundchannel_soundtransform_exists` | 5 | 25.4s |  |
| 737 | `soundchannel_stop` | 8 | 6.7s |  |
| 738 | `soundmixer_buffertime` | 5 | 6.5s |  |
| 739 | `soundmixer_stopall` | 6 | 6.5s |  |
| 740 | `soundtransform` | 442 | 12.2s |  |
| 741 | `sprite_with_frames` | 0 | 25.8s |  |
| 742 | `stage3d_agal_cross_product` | 0 | 9.1s |  |
| 743 | `stage3d_bitmap` | 0 | 30.6s |  |
| 744 | `stage3d_float1_index` | 0 | 27.6s |  |
| 745 | `stage3d_fractal` | 0 | 28.0s |  |
| 746 | `stage3d_ignore_sampler_override` | 0 | 28.3s |  |
| 747 | `stage3d_program_constants_bytearray_be` | 0 | 29.2s |  |
| 748 | `stage3d_program_constants_bytearray_le` | 0 | 9.8s |  |
| 749 | `stage3d_raytrace` | 0 | 31.3s |  |
| 750 | `stage3d_rotating_cube` | 0 | 10.0s |  |
| 751 | `stage3d_sampler` | 0 | 22.9s |  |
| 752 | `stage3d_sampler_partial_upload` | 0 | 9.4s |  |
| 753 | `stage3d_stencil` | 0 | 29.5s |  |
| 754 | `stage3d_texture` | 0 | 14.3s |  |
| 755 | `stage3d_texture_bytearray` | 0 | 10.8s |  |
| 756 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.0s |  |
| 757 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.1s |  |
| 758 | `stage3d_triangle` | 0 | 9.5s |  |
| 759 | `stage3d_triangle_bytes4` | 0 | 9.5s |  |
| 760 | `stage3d_triangle_float1` | 0 | 9.5s |  |
| 761 | `stage3d_triangle_index_upload` | 0 | 9.4s |  |
| 762 | `stage_access` | 10 | 6.8s |  |
| 763 | `stage_displayobject_properties` | 24 | 6.6s |  |
| 764 | `stage_framerate_nan` | 7 | 6.9s |  |
| 765 | `stage_framerate_negative` | 6 | 6.7s |  |
| 766 | `stage_framerate_zero` | 6 | 6.7s |  |
| 767 | `stage_invalidate` | 38 | 6.9s |  |
| 768 | `stage_loaderinfo_properties` | 24 | 7.0s |  |
| 769 | `stage_mousechildren` | 2 | 6.6s |  |
| 770 | `stage_mouseenabled` | 15 | 6.7s |  |
| 771 | `stage_overriden_setters` | 31 | 6.8s |  |
| 772 | `stage_properties` | 30 | 6.6s |  |
| 773 | `static_var_with_this_in_ctor` | 2 | 6.7s |  |
| 774 | `stored_properties` | 11 | 6.7s |  |
| 775 | `strict_equality` | 34 | 6.8s |  |
| 776 | `string_call` | 13 | 6.7s |  |
| 777 | `string_case` | 23 | 6.7s |  |
| 778 | `string_char_at` | 27 | 6.8s |  |
| 779 | `string_char_code_at` | 28 | 6.6s |  |
| 780 | `string_concat_fromcharcode` | 37 | 6.6s |  |
| 781 | `string_constr` | 25 | 6.7s |  |
| 782 | `string_indexof_lastindexof` | 87 | 19.7s |  |
| 783 | `string_length` | 16 | 6.4s |  |
| 784 | `string_locale_compare` | 39 | 6.7s |  |
| 785 | `string_match` | 51 | 6.6s |  |
| 786 | `string_relational_compare` | 4 | 6.3s |  |
| 787 | `string_replace` | 51 | 6.6s |  |
| 788 | `string_search` | 41 | 6.5s |  |
| 789 | `string_slice_substr_substring` | 170 | 7.5s |  |
| 790 | `string_split` | 29 | 6.5s |  |
| 791 | `string_substr_negative` | 21 | 6.3s |  |
| 792 | `string_substr_weird` | 182 | 6.3s |  |
| 793 | `subtract` | 1058 | 18.5s |  |
| 794 | `super_get_call` | 12 | 6.4s |  |
| 795 | `supercall_two_classobjects` | 2 | 6.4s |  |
| 796 | `swf8` | 1 | 6.3s |  |
| 797 | `swf_10_queued_goto_scripts_construct` | 52 | 6.7s |  |
| 798 | `swf_9_goto_in_enter_frame` | 17 | 6.5s |  |
| 799 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.5s |  |
| 800 | `swf_9_queued_goto_scripts` | 6 | 6.5s |  |
| 801 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 802 | `swf_9_versioning` | 2 | 6.4s |  |
| 803 | `swf_wrong_frame_count` | 38 | 6.7s |  |
| 804 | `swf_wrong_frame_count_isplaying` | 22 | 24.9s |  |
| 805 | `symbol_class_binary_data` | 8 | 6.5s |  |
| 806 | `symbol_class_conflict` | 4 | 6.9s |  |
| 807 | `symbol_class_root_not_zero` | 1 | 6.3s |  |
| 808 | `symbolclass_invalid_utf8` | 2 | 6.4s |  |
| 809 | `tab_ordering_automatic_advanced` | 184 | 6.9s |  |
| 810 | `tab_ordering_automatic_basic` | 45 | 6.0s |  |
| 811 | `tab_ordering_children` | 116 | 5.9s |  |
| 812 | `tab_ordering_custom_basic` | 34 | 6.1s |  |
| 813 | `tab_ordering_stage_tab_children` | 32 | 6.2s |  |
| 814 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.0s |  |
| 815 | `tab_ordering_tabbable` | 47 | 6.1s |  |
| 816 | `text_engine_fontdescription` | 27 | 6.1s |  |
| 817 | `text_run` | 7 | 5.9s |  |
| 818 | `textbox_click` | 37 | 26.8s |  |
| 819 | `textfield_event` | 66 | 6.1s |  |
| 820 | `textfield_focusin_event` | 9 | 6.1s |  |
| 821 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 822 | `textfield_unload` | 39 | 26.1s |  |
| 823 | `textformat` | 1134 | 5.9s |  |
| 824 | `textformat_display` | 14 | 6.2s |  |
| 825 | `textformat_font_max_length` | 4 | 5.8s |  |
| 826 | `throw` | 3 | 5.9s |  |
| 827 | `timeline_scripts` | 3 | 6.0s |  |
| 828 | `timer` | 90 | 6.6s |  |
| 829 | `timer_events` | 3 | 6.1s |  |
| 830 | `timer_finished` | 11 | 6.3s |  |
| 831 | `timer_reset` | 8 | 6.4s |  |
| 832 | `timer_setdelay` | 5 | 6.1s |  |
| 833 | `trace` | 12 | 6.2s |  |
| 834 | `truthiness` | 30 | 18.9s |  |
| 835 | `try_catch` | 11 | 5.3s |  |
| 836 | `try_catch_typed` | 12 | 5.2s |  |
| 837 | `typeof` | 30 | 5.3s |  |
| 838 | `uint_constr` | 92 | 5.3s |  |
| 839 | `uint_tofixed` | 1215 | 5.3s |  |
| 840 | `uint_tostring` | 3375 | 5.3s |  |
| 841 | `unchecked_function` | 15 | 5.2s |  |
| 842 | `unescape` | 28 | 5.2s |  |
| 843 | `url_loader` | 25 | 5.3s |  |
| 844 | `urlrequest` | 18 | 5.3s |  |
| 845 | `urlstream_basic` | 5 | 5.3s |  |
| 846 | `urshift` | 1058 | 5.3s |  |
| 847 | `vector_class` | 36 | 5.2s |  |
| 848 | `vector_class_call` | 11 | 5.2s |  |
| 849 | `vector_coercion` | 66 | 5.2s |  |
| 850 | `vector_concat` | 90 | 5.2s |  |
| 851 | `vector_constr` | 107 | 5.2s |  |
| 852 | `vector_enumeration` | 5 | 5.2s |  |
| 853 | `vector_every` | 92 | 5.2s |  |
| 854 | `vector_filter` | 95 | 5.2s |  |
| 855 | `vector_holes` | 24 | 5.2s |  |
| 856 | `vector_indexof` | 302 | 5.2s |  |
| 857 | `vector_insertat` | 270 | 5.2s |  |
| 858 | `vector_int_access` | 4 | 5.2s |  |
| 859 | `vector_int_delete` | 11 | 5.2s |  |
| 860 | `vector_join` | 58 | 5.3s |  |
| 861 | `vector_lastindexof` | 302 | 5.2s |  |
| 862 | `vector_legacy` | 10 | 5.3s |  |
| 863 | `vector_map` | 85 | 5.2s |  |
| 864 | `vector_object_final` | 1 | 5.3s |  |
| 865 | `vector_object_toString` | 10 | 5.3s |  |
| 866 | `vector_pushpop` | 255 | 5.3s |  |
| 867 | `vector_reborrow_bug` | 10 | 19.3s |  |
| 868 | `vector_removeat` | 172 | 7.1s |  |
| 869 | `vector_reverse` | 232 | 7.1s |  |
| 870 | `vector_shiftunshift` | 252 | 6.2s |  |
| 871 | `vector_slice` | 331 | 7.6s |  |
| 872 | `vector_sort` | 905 | 14.2s |  |
| 873 | `vector_splice` | 693 | 9.3s |  |
| 874 | `vector_splice_fixed_bug_compat` | 4 | 6.2s |  |
| 875 | `vector_tostring` | 79 | 6.8s |  |
| 876 | `verify_abnormal_loop` | 1 | 6.2s |  |
| 877 | `verify_exception_targets_edge_case` | 1 | 6.2s |  |
| 878 | `verify_lookup_switch_edge_case` | 1 | 6.2s |  |
| 879 | `verify_unreachable_exception` | 2 | 6.2s |  |
| 880 | `versioned_isplaying` | 2 | 6.3s |  |
| 881 | `virtual_properties` | 16 | 6.7s |  |
| 882 | `with` | 4 | 6.3s |  |
| 883 | `wrong_arg_count` | 7 | 6.4s |  |
| 884 | `xml_abstract_equality` | 36 | 6.4s |  |
| 885 | `xml_advanced` | 52 | 6.4s |  |
| 886 | `xml_appendchild` | 10 | 6.3s |  |
| 887 | `xml_as_attribute` | 9 | 6.2s |  |
| 888 | `xml_attribute` | 35 | 6.4s |  |
| 889 | `xml_attribute_name` | 40 | 6.3s |  |
| 890 | `xml_basic` | 33 | 6.3s |  |
| 891 | `xml_child` | 25 | 6.3s |  |
| 892 | `xml_childindex` | 7 | 6.2s |  |
| 893 | `xml_children` | 43 | 6.8s |  |
| 894 | `xml_class_call` | 9 | 6.2s |  |
| 895 | `xml_contains` | 197 | 6.6s |  |
| 896 | `xml_copy` | 20 | 20.9s |  |
| 897 | `xml_ctor_from_tostring` | 23 | 7.3s |  |
| 898 | `xml_delete` | 114 | 7.2s |  |
| 899 | `xml_descendants` | 83 | 7.0s |  |
| 900 | `xml_elements` | 6 | 7.0s |  |
| 901 | `xml_equals_namespace_check` | 2 | 7.0s |  |
| 902 | `xml_explicit_use_namespace` | 5 | 7.1s |  |
| 903 | `xml_getdescendants_qname` | 21 | 7.1s |  |
| 904 | `xml_has_property_via_in` | 26 | 7.1s |  |
| 905 | `xml_hasownproperty` | 6 | 7.1s |  |
| 906 | `xml_ignore_white` | 6 | 7.1s |  |
| 907 | `xml_length` | 2 | 7.0s |  |
| 908 | `xml_list_as_attribute` | 9 | 7.1s |  |
| 909 | `xml_list_concat` | 20 | 7.1s |  |
| 910 | `xml_list_enumerate` | 4 | 7.0s |  |
| 911 | `xml_methods_settings` | 3 | 7.1s |  |
| 912 | `xml_mismatched_tag` | 37 | 7.1s |  |
| 913 | `xml_namespace` | 39 | 7.1s |  |
| 914 | `xml_namespace_methods` | 245 | 7.1s |  |
| 915 | `xml_namespaced_property` | 7 | 7.0s |  |
| 916 | `xml_no_namespace` | 1 | 7.0s |  |
| 917 | `xml_nodekind` | 3 | 7.0s |  |
| 918 | `xml_normalize` | 35 | 7.1s |  |
| 919 | `xml_notification_bubbling` | 361 | 7.0s |  |
| 920 | `xml_parent` | 8 | 7.0s |  |
| 921 | `xml_set_children` | 17 | 7.2s |  |
| 922 | `xml_set_name` | 34 | 7.1s |  |
| 923 | `xml_settings` | 6 | 3.4s |  |
| 924 | `xml_simple_complex_content` | 47 | 7.1s |  |
| 925 | `xml_socket` | 11 | 7.3s |  |
| 926 | `xml_text` | 7 | 7.1s |  |
| 927 | `xml_tostring` | 6 | 7.1s |  |
| 928 | `xml_tostring_namespace` | 12 | 7.0s |  |
| 929 | `xml_unescaping` | 23 | 7.1s |  |
| 930 | `xml_weird_ignores` | 54 | 7.1s |  |
| 931 | `xml_wildcard` | 11 | 7.0s |  |
| 932 | `xmldocument` | 254 | 7.2s |  |
| 933 | `xmlnode` | 3540 | 7.2s |  |
| 934 | `zero_frame_clip` | 3 | 7.7s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.5s |  |
| 3 | `blend_transform` | 1 | 1 | 7.2s |  |
| 4 | `coerce_property` | 3 | 3 | 6.6s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.5s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 6.8s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.2s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 37.8s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.5s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.2s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.2s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.2s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 25.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 26.0s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.5s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.5s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.0s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.6s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 26.8s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.3s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.7s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.5s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 25.3s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.3s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.2s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 25.4s |  |

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
| 42 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 43 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 44 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 45 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 46 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 47 | `verification` | 62.5% | 5 | 8 | 3 |  |
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
| 58 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 59 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 18.3s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.6s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**258 tests** with output mismatch, sorted by match rate (best first)

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
| 42 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 43 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 44 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 45 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 46 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 47 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
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
| 58 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 59 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 60 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 61 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 62 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 63 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 64 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 65 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 66 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 67 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 68 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 69 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 70 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 71 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 72 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 73 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 74 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 75 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 76 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 77 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 78 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 79 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 80 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 81 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 82 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 83 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 84 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 85 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 86 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 87 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 88 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 89 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 90 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 91 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 92 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 93 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 94 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 95 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 96 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 97 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 98 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 99 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 100 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 101 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 102 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 103 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 104 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 105 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 106 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 107 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 108 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 109 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 110 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 111 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 112 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 113 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 114 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 115 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 116 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 117 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 118 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 119 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 120 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 121 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 122 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 123 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 124 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 125 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 126 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 127 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 128 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 129 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 130 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 131 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 132 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 133 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 134 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 135 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 136 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 137 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 138 | `all_classes/events/swf9` | 0.1% | 1/1030 | 178 | 1030 |  |
| 139 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 140 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 141 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 142 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 143 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 144 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 145 | `all_classes/events/swf10` | 0.1% | 1/1638 | 178 | 1638 |  |
| 146 | `all_classes/events/swf11` | 0.1% | 1/1750 | 178 | 1750 |  |
| 147 | `all_classes/events/swf12` | 0.1% | 1/1814 | 178 | 1814 |  |
| 148 | `all_classes/events/swf30` | 0.0% | 1/2353 | 178 | 2353 |  |
| 149 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 150 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 151 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 152 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 153 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 154 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 155 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 156 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 157 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 158 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 159 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 160 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 161 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 162 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 163 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 164 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 165 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 166 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 167 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 168 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 169 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 170 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 171 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 172 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 173 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 174 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 175 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 176 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 177 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 178 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 179 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 180 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 181 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 182 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 183 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 184 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 185 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 186 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 187 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 188 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 189 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 190 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 191 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 192 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 193 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 194 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 195 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 196 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 197 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 198 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 199 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 200 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 201 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 202 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 203 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 204 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 205 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 206 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 207 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 208 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 209 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 210 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 211 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 212 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 213 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 214 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 215 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 216 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 217 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 218 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 219 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 220 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 221 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 222 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 223 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 224 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 225 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 226 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 227 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 228 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 229 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 230 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 231 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 232 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 233 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 234 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 235 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 236 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 237 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 238 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 239 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 240 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 241 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 242 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 243 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 244 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 245 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 246 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 247 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 248 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 249 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 250 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 251 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 252 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 253 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 254 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 255 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 256 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 257 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 258 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
