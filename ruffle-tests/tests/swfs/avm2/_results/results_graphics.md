# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-29 19:07 UTC

**Git SHA**: `6cf854900e`

**Run Duration**: 188m 39s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **930** (76.2%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **956** (78.3%) |
| Failing | 265 |
| Total expected lines | 151253 |
| Matching lines | 107390 (71.0%) |
| Mismatched lines | 43863 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 262 | 98.9% |
| Runtime Error | 3 | 1.1% |

## Passing Tests

**930 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.8s |  |
| 2 | `agal_compiler` | 13 | 8.9s |  |
| 3 | `air_datagram_socket` | 1 | 6.9s |  |
| 4 | `air_hidden_lookup` | 2 | 6.5s |  |
| 5 | `all_classes/security/swf11` | 3 | 6.8s |  |
| 6 | `amf_custom_obj` | 26 | 6.8s |  |
| 7 | `amf_dictionary` | 9 | 6.8s |  |
| 8 | `amf_function` | 46 | 6.9s |  |
| 9 | `amf_invalid_date` | 2 | 6.7s |  |
| 10 | `amf_missing_prop` | 6 | 6.8s |  |
| 11 | `amf_nondynamic_function_prop` | 6 | 7.2s |  |
| 12 | `amf_setter_error` | 8 | 7.4s |  |
| 13 | `amf_vector` | 40 | 7.2s |  |
| 14 | `amf_xml` | 6 | 6.7s |  |
| 15 | `application_domain` | 4 | 7.1s |  |
| 16 | `array_access` | 18 | 7.1s |  |
| 17 | `array_access_interpreter` | 4 | 7.0s |  |
| 18 | `array_access_no_pubns` | 2 | 7.0s |  |
| 19 | `array_concat` | 41 | 7.0s |  |
| 20 | `array_constr` | 10 | 6.9s |  |
| 21 | `array_delete` | 44 | 7.2s |  |
| 22 | `array_enumeration` | 10 | 6.9s |  |
| 23 | `array_enumeration_elements` | 11 | 6.9s |  |
| 24 | `array_every` | 8 | 6.7s |  |
| 25 | `array_filter` | 6 | 6.6s |  |
| 26 | `array_foreach` | 18 | 6.7s |  |
| 27 | `array_hasownproperty` | 11 | 3.2s |  |
| 28 | `array_holes` | 9 | 6.7s |  |
| 29 | `array_index_max` | 84 | 6.6s |  |
| 30 | `array_indexof` | 25 | 6.7s |  |
| 31 | `array_join` | 26 | 6.8s |  |
| 32 | `array_lastindexof` | 29 | 6.8s |  |
| 33 | `array_length` | 14 | 6.7s |  |
| 34 | `array_literal` | 3 | 6.6s |  |
| 35 | `array_map` | 8 | 6.5s |  |
| 36 | `array_pop` | 52 | 6.8s |  |
| 37 | `array_push` | 24 | 6.7s |  |
| 38 | `array_reborrow_bug` | 6 | 6.6s |  |
| 39 | `array_reverse` | 28 | 6.7s |  |
| 40 | `array_shift` | 51 | 3.3s |  |
| 41 | `array_slice` | 39 | 6.8s |  |
| 42 | `array_some` | 8 | 6.7s |  |
| 43 | `array_sort` | 297 | 7.2s |  |
| 44 | `array_sort_fun_swf12` | 2 | 6.7s |  |
| 45 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 46 | `array_sort_random` | 210 | 6.8s |  |
| 47 | `array_sort_swf10_32bit` | 1 | 6.8s |  |
| 48 | `array_sorton` | 545 | 7.5s |  |
| 49 | `array_sparse_ops` | 41 | 6.6s |  |
| 50 | `array_splice` | 133 | 6.7s |  |
| 51 | `array_splice2` | 428 | 6.7s |  |
| 52 | `array_splice_types` | 48 | 6.6s |  |
| 53 | `array_storage` | 8 | 6.4s |  |
| 54 | `array_tolocalestring` | 9 | 6.4s |  |
| 55 | `array_tostring` | 12 | 6.4s |  |
| 56 | `array_unshift` | 24 | 6.4s |  |
| 57 | `array_valueof` | 9 | 6.3s |  |
| 58 | `array_vector_null_callback` | 10 | 6.4s |  |
| 59 | `astype` | 28 | 6.5s |  |
| 60 | `astypelate` | 24 | 6.6s |  |
| 61 | `astypelate_propagates` | 1 | 6.3s |  |
| 62 | `asymmetric_key_events` | 11 | 6.4s |  |
| 63 | `av_networking_params` | 9 | 6.5s |  |
| 64 | `avm2_catchup_dobj` | 158 | 7.0s |  |
| 65 | `away3d_advanced_shallow_water_demo` | 0 | 80.5s |  |
| 66 | `bitand` | 1058 | 18.7s |  |
| 67 | `bitmap_constr` | 17 | 6.8s |  |
| 68 | `bitmap_data` | 1000 | 15.2s |  |
| 69 | `bitmap_pixelsnapping` | 2 | 25.9s |  |
| 70 | `bitmap_properties` | 23 | 6.5s |  |
| 71 | `bitmap_subclass` | 7 | 7.9s |  |
| 72 | `bitmap_subclass_properties` | 9 | 7.0s |  |
| 73 | `bitmap_timeline` | 9 | 6.7s |  |
| 74 | `bitmapdata_accuracy` | 1 | 42.9s |  |
| 75 | `bitmapdata_applyfilter_blur` | 0 | 26.3s |  |
| 76 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.3s |  |
| 77 | `bitmapdata_applyfilter_destpoint` | 0 | 26.2s |  |
| 78 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.6s |  |
| 79 | `bitmapdata_clone` | 13 | 6.7s |  |
| 80 | `bitmapdata_colortransform` | 0 | 7.0s |  |
| 81 | `bitmapdata_colortransform_oob` | 2 | 6.5s |  |
| 82 | `bitmapdata_constr` | 22 | 3.1s |  |
| 83 | `bitmapdata_constructor_from_timeline` | 1 | 6.8s |  |
| 84 | `bitmapdata_copychannel` | 0 | 29.1s |  |
| 85 | `bitmapdata_copypixels` | 23 | 28.0s |  |
| 86 | `bitmapdata_copypixels_blend_over` | 1 | 6.6s |  |
| 87 | `bitmapdata_copypixelstobytearray` | 39 | 6.6s |  |
| 88 | `bitmapdata_dispose` | 7 | 6.7s |  |
| 89 | `bitmapdata_draw` | 0 | 26.8s |  |
| 90 | `bitmapdata_draw_colortransform` | 0 | 6.8s |  |
| 91 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.9s |  |
| 92 | `bitmapdata_draw_filters` | 0 | 25.5s |  |
| 93 | `bitmapdata_draw_masks` | 0 | 6.6s |  |
| 94 | `bitmapdata_draw_rotation` | 0 | 6.8s |  |
| 95 | `bitmapdata_draw_self_via_graphic` | 0 | 6.7s |  |
| 96 | `bitmapdata_draw_stage` | 0 | 25.4s |  |
| 97 | `bitmapdata_drawwithquality` | 0 | 6.8s |  |
| 98 | `bitmapdata_embedded` | 9 | 6.8s |  |
| 99 | `bitmapdata_fillrect` | 0 | 6.7s |  |
| 100 | `bitmapdata_filter_sourcerect` | 0 | 25.5s |  |
| 101 | `bitmapdata_floodfill` | 35 | 6.5s |  |
| 102 | `bitmapdata_getpixels` | 39 | 25.4s |  |
| 103 | `bitmapdata_getvector` | 27 | 3.0s |  |
| 104 | `bitmapdata_histogram` | 59 | 3.0s |  |
| 105 | `bitmapdata_hittest` | 112 | 7.0s |  |
| 106 | `bitmapdata_hittest_threshold` | 18 | 6.4s |  |
| 107 | `bitmapdata_opaque` | 0 | 6.7s |  |
| 108 | `bitmapdata_pixeldissolve` | 1037 | 7.1s |  |
| 109 | `bitmapdata_pixeldissolve_image` | 0 | 6.9s |  |
| 110 | `bitmapdata_rectangle_rounding` | 16 | 6.4s |  |
| 111 | `bitmapdata_setpixels` | 286 | 6.6s |  |
| 112 | `bitmapdata_setvector` | 26 | 6.4s |  |
| 113 | `bitmapdata_sync` | 0 | 6.6s |  |
| 114 | `bitmapdata_threshold` | 176 | 7.2s |  |
| 115 | `bitnot` | 46 | 6.7s |  |
| 116 | `bitor` | 1058 | 19.0s |  |
| 117 | `bitxor` | 1058 | 18.4s |  |
| 118 | `blend_multiply_alpha` | 0 | 6.7s |  |
| 119 | `blend_scroll` | 0 | 6.6s |  |
| 120 | `boolean_constr` | 32 | 7.0s |  |
| 121 | `boolean_negation` | 30 | 7.0s |  |
| 122 | `boolean_tostring` | 8 | 7.0s |  |
| 123 | `broadcast_event` | 7 | 7.1s |  |
| 124 | `button_nested_frame` | 48 | 27.8s |  |
| 125 | `bytearray` | 48 | 7.3s |  |
| 126 | `bytearray_compress` | 31 | 7.1s |  |
| 127 | `bytearray_errors` | 24 | 7.2s |  |
| 128 | `bytearray_method_serialization` | 1 | 7.0s |  |
| 129 | `bytearray_oom` | 3 | 7.0s |  |
| 130 | `bytearray_readobject_amf0` | 50 | 7.1s |  |
| 131 | `bytearray_readobject_amf3` | 53 | 7.1s |  |
| 132 | `bytearray_readutf8bytes_with_bom` | 16 | 7.1s |  |
| 133 | `bytearray_serialization` | 3 | 7.0s |  |
| 134 | `bytearray_string_null` | 19 | 7.3s |  |
| 135 | `bytearray_tostring` | 15 | 7.0s |  |
| 136 | `bytearray_utf16` | 8 | 7.1s |  |
| 137 | `bytearray_writeobject` | 24 | 7.0s |  |
| 138 | `callee_in_initializer` | 6 | 7.0s |  |
| 139 | `callproplex_class` | 1 | 7.0s |  |
| 140 | `capabilities_resolution` | 8 | 28.8s |  |
| 141 | `catch_class` | 6 | 7.0s |  |
| 142 | `catch_scope_slot` | 7 | 3.5s |  |
| 143 | `checkfilter` | 4 | 3.4s |  |
| 144 | `class_call` | 32 | 7.1s |  |
| 145 | `class_cast_call` | 14 | 7.0s |  |
| 146 | `class_enumeration` | 4 | 7.1s |  |
| 147 | `class_has_own_property` | 2 | 7.0s |  |
| 148 | `class_init_interpreter_mode` | 1 | 6.9s |  |
| 149 | `class_is` | 32 | 7.0s |  |
| 150 | `class_methods` | 5 | 6.9s |  |
| 151 | `class_object_properties` | 10 | 7.1s |  |
| 152 | `class_singleton` | 18 | 7.0s |  |
| 153 | `class_supercalls_errors` | 35 | 7.2s |  |
| 154 | `class_supercalls_mismatched` | 26 | 7.1s |  |
| 155 | `class_superclass_wrong_order` | 1 | 25.7s |  |
| 156 | `class_to_locale_string` | 2 | 6.2s |  |
| 157 | `class_to_string` | 2 | 6.2s |  |
| 158 | `class_value_of` | 2 | 6.2s |  |
| 159 | `click_block` | 5 | 27.0s |  |
| 160 | `click_invisible` | 3 | 6.4s |  |
| 161 | `closures` | 12 | 6.3s |  |
| 162 | `coerce_return_type` | 40 | 6.5s |  |
| 163 | `coerce_return_type_fail` | 2 | 6.2s |  |
| 164 | `coerce_return_void` | 3 | 6.2s |  |
| 165 | `coerce_string` | 86 | 6.4s |  |
| 166 | `coerce_string_precision` | 28 | 6.3s |  |
| 167 | `coerce_to_primitive_side_effects` | 29 | 26.4s |  |
| 168 | `construct_errors_swf10` | 8 | 6.3s |  |
| 169 | `construct_frame_list` | 22 | 26.1s |  |
| 170 | `constructor_call` | 3 | 6.2s |  |
| 171 | `constructors_vs_timeline` | 5 | 26.0s |  |
| 172 | `constructprop_dynamic_primitive` | 7 | 6.2s |  |
| 173 | `control_flow_bool` | 4 | 6.2s |  |
| 174 | `control_flow_stricteq` | 8 | 6.2s |  |
| 175 | `convert_boolean` | 30 | 6.2s |  |
| 176 | `convert_integer` | 90 | 6.3s |  |
| 177 | `convert_number` | 56 | 6.3s |  |
| 178 | `convert_uinteger` | 90 | 6.3s |  |
| 179 | `cross_api_version_call_older` | 12 | 6.5s |  |
| 180 | `cryptscore` | 11 | 6.3s |  |
| 181 | `date` | 30 | 6.8s |  |
| 182 | `date_parse` | 36 | 6.4s |  |
| 183 | `declocal` | 46 | 6.5s |  |
| 184 | `declocal_i` | 46 | 6.4s |  |
| 185 | `decode_uri` | 71 | 6.8s |  |
| 186 | `decrement` | 46 | 6.4s |  |
| 187 | `decrement_i` | 46 | 3.0s |  |
| 188 | `default_values` | 7 | 6.3s |  |
| 189 | `dictionary_access` | 62 | 6.6s |  |
| 190 | `dictionary_access_no_pubns` | 2 | 6.3s |  |
| 191 | `dictionary_delete` | 101 | 6.8s |  |
| 192 | `dictionary_foreach` | 42 | 6.6s |  |
| 193 | `dictionary_hasownproperty` | 63 | 6.6s |  |
| 194 | `dictionary_in` | 62 | 6.6s |  |
| 195 | `dictionary_iter_modify` | 8 | 6.4s |  |
| 196 | `dictionary_namespaces` | 36 | 6.5s |  |
| 197 | `dictionary_primitive_keys` | 29 | 6.4s |  |
| 198 | `displayobject_alpha` | 277 | 6.3s |  |
| 199 | `displayobject_blendmode` | 0 | 6.5s |  |
| 200 | `displayobject_colortransform_nested` | 0 | 25.2s |  |
| 201 | `displayobject_from_enterframe` | 1 | 25.1s |  |
| 202 | `displayobject_getbounds_shape` | 0 | 25.3s |  |
| 203 | `displayobject_height` | 6052 | 25.2s |  |
| 204 | `displayobject_hittestobject` | 32 | 6.5s |  |
| 205 | `displayobject_invalid_floats` | 60 | 6.4s |  |
| 206 | `displayobject_invalid_props` | 3 | 2.9s |  |
| 207 | `displayobject_mask` | 3 | 6.7s |  |
| 208 | `displayobject_mask_self_referential` | 0 | 26.2s |  |
| 209 | `displayobject_metaData` | 3 | 6.4s |  |
| 210 | `displayobject_name` | 22 | 25.8s |  |
| 211 | `displayobject_name_from_timeline` | 24 | 6.6s |  |
| 212 | `displayobject_parent` | 12 | 6.5s |  |
| 213 | `displayobject_root` | 24 | 6.5s |  |
| 214 | `displayobject_rotation` | 1284 | 6.7s |  |
| 215 | `displayobject_set_matrix_nested` | 0 | 25.9s |  |
| 216 | `displayobject_set_name_loaded` | 3 | 7.0s |  |
| 217 | `displayobject_subclass` | 2 | 6.6s |  |
| 218 | `displayobject_visible` | 23 | 6.6s |  |
| 219 | `displayobject_width` | 4852 | 26.8s |  |
| 220 | `displayobject_x` | 614 | 6.7s |  |
| 221 | `displayobject_y` | 617 | 6.8s |  |
| 222 | `displayobjectcontainer_addchild` | 32 | 6.9s |  |
| 223 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.9s |  |
| 224 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.1s |  |
| 225 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.8s |  |
| 226 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.8s |  |
| 227 | `displayobjectcontainer_addchildat` | 42 | 6.7s |  |
| 228 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.2s |  |
| 229 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.7s |  |
| 230 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.7s |  |
| 231 | `displayobjectcontainer_contains` | 66 | 26.0s |  |
| 232 | `displayobjectcontainer_getchildat` | 4 | 6.6s |  |
| 233 | `displayobjectcontainer_getchildbyname` | 9 | 6.6s |  |
| 234 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.5s |  |
| 235 | `displayobjectcontainer_getchildindex` | 28 | 6.6s |  |
| 236 | `displayobjectcontainer_removechild` | 10 | 6.5s |  |
| 237 | `displayobjectcontainer_removechild_errors` | 4 | 6.4s |  |
| 238 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.4s |  |
| 239 | `displayobjectcontainer_removechildat` | 18 | 6.4s |  |
| 240 | `displayobjectcontainer_removechildren` | 51 | 6.6s |  |
| 241 | `displayobjectcontainer_setchildindex` | 42 | 6.4s |  |
| 242 | `displayobjectcontainer_stopallmovieclips` | 2 | 25.6s |  |
| 243 | `displayobjectcontainer_swapchildren` | 42 | 6.5s |  |
| 244 | `displayobjectcontainer_swapchildrenat` | 42 | 6.4s |  |
| 245 | `displayobjectcontainer_timelineinstance` | 48 | 20.0s |  |
| 246 | `divide` | 1058 | 14.0s |  |
| 247 | `doabc_is_eager` | 1 | 19.9s |  |
| 248 | `documentclass` | 9 | 5.7s |  |
| 249 | `domain_memory` | 133 | 21.9s |  |
| 250 | `drag_drop` | 10 | 5.7s |  |
| 251 | `duplicate_defs` | 1 | 5.3s |  |
| 252 | `eager_init` | 1 | 5.1s |  |
| 253 | `edit_text_linkage` | 7 | 5.3s |  |
| 254 | `edittext_align` | 60 | 5.4s |  |
| 255 | `edittext_always_show_selection` | 0 | 20.0s |  |
| 256 | `edittext_antialiastype` | 296 | 5.4s |  |
| 257 | `edittext_at_point_methods_basic` | 16 | 6.4s |  |
| 258 | `edittext_autosize` | 39 | 5.5s |  |
| 259 | `edittext_autosize_align` | 0 | 20.8s |  |
| 260 | `edittext_autosize_height_dynamic` | 60 | 20.3s |  |
| 261 | `edittext_autosize_height_input` | 60 | 5.2s |  |
| 262 | `edittext_autosize_lazy_bounds_events` | 65 | 5.4s |  |
| 263 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.2s |  |
| 264 | `edittext_autosize_lazy_bounds_props` | 490 | 6.2s |  |
| 265 | `edittext_autosize_lazy_bounds_visual` | 0 | 20.1s |  |
| 266 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.3s |  |
| 267 | `edittext_bottom_scroll_v_basic` | 210 | 5.3s |  |
| 268 | `edittext_bounds_scale` | 24 | 19.8s |  |
| 269 | `edittext_bullet` | 30 | 5.2s |  |
| 270 | `edittext_default_format` | 221 | 5.4s |  |
| 271 | `edittext_default_format_empty` | 136 | 5.3s |  |
| 272 | `edittext_empty_text_format` | 7 | 5.2s |  |
| 273 | `edittext_focus_selection` | 5 | 5.2s |  |
| 274 | `edittext_font_size` | 45 | 5.2s |  |
| 275 | `edittext_format_empty_font` | 8 | 5.1s |  |
| 276 | `edittext_get_char_index_at_point` | 4 | 20.9s |  |
| 277 | `edittext_get_line_index_at_point` | 2 | 20.2s |  |
| 278 | `edittext_get_line_index_of_char` | 76 | 6.1s |  |
| 279 | `edittext_getcharboundaries` | 172 | 5.5s |  |
| 280 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.8s |  |
| 281 | `edittext_getcharboundaries_scroll` | 85 | 26.2s |  |
| 282 | `edittext_getlinemetrics` | 146 | 6.8s |  |
| 283 | `edittext_html` | 3101 | 7.0s |  |
| 284 | `edittext_html_condensewhite` | 487 | 6.7s |  |
| 285 | `edittext_html_entity` | 4 | 6.9s |  |
| 286 | `edittext_html_font_size_swf12` | 267 | 6.7s |  |
| 287 | `edittext_html_font_size_swf13` | 273 | 6.4s |  |
| 288 | `edittext_html_roundtrip` | 17 | 6.6s |  |
| 289 | `edittext_ime_focus_lost` | 9 | 26.0s |  |
| 290 | `edittext_input_control` | 12 | 6.8s |  |
| 291 | `edittext_leading` | 9 | 7.0s |  |
| 292 | `edittext_letter_spacing` | 15 | 6.6s |  |
| 293 | `edittext_line_methods` | 294 | 8.0s |  |
| 294 | `edittext_line_metrics` | 11 | 27.5s |  |
| 295 | `edittext_margins` | 25 | 6.6s |  |
| 296 | `edittext_max_scroll_h_basic` | 475 | 6.8s |  |
| 297 | `edittext_max_scroll_v_basic` | 1000 | 6.7s |  |
| 298 | `edittext_mouse_selection` | 363 | 26.5s |  |
| 299 | `edittext_mousedown` | 3 | 6.7s |  |
| 300 | `edittext_mouseenabled` | 26 | 6.4s |  |
| 301 | `edittext_newline_character` | 22 | 6.3s |  |
| 302 | `edittext_newline_stripping` | 64 | 8.9s |  |
| 303 | `edittext_newlines` | 30 | 6.4s |  |
| 304 | `edittext_paragraph_methods` | 257 | 6.4s |  |
| 305 | `edittext_paste_events` | 8 | 6.3s |  |
| 306 | `edittext_paste_maxchars` | 4 | 6.3s |  |
| 307 | `edittext_paste_restrict` | 16 | 6.2s |  |
| 308 | `edittext_restrict` | 191 | 6.3s |  |
| 309 | `edittext_restrict_events` | 22 | 6.3s |  |
| 310 | `edittext_scrollh` | 10 | 2.9s |  |
| 311 | `edittext_selected_text` | 9 | 6.3s |  |
| 312 | `edittext_set_html_same` | 17 | 6.3s |  |
| 313 | `edittext_set_text_vs_html` | 9 | 6.3s |  |
| 314 | `edittext_stylesheet` | 536 | 6.7s |  |
| 315 | `edittext_stylesheet_custom_tag` | 76 | 6.4s |  |
| 316 | `edittext_stylesheet_display` | 272 | 6.4s |  |
| 317 | `edittext_underline` | 40 | 6.4s |  |
| 318 | `edittext_width_height` | 103 | 7.0s |  |
| 319 | `edittext_wordwrap_word` | 150 | 25.7s |  |
| 320 | `edittext_wrap_breaks` | 2375 | 7.2s |  |
| 321 | `empty_bounds` | 1 | 6.6s |  |
| 322 | `encode_uri_surrogate_pair_swf11` | 15 | 6.3s |  |
| 323 | `equals` | 512 | 10.7s |  |
| 324 | `error_geterrormessage` | 779 | 6.5s |  |
| 325 | `error_prototype` | 15 | 6.5s |  |
| 326 | `error_stack_trace_debug_swf17` | 0 | 25.9s |  |
| 327 | `error_stack_trace_debug_swf18` | 0 | 6.3s |  |
| 328 | `error_stack_trace_release_swf17` | 0 | 6.2s |  |
| 329 | `error_stack_trace_release_swf18` | 0 | 6.2s |  |
| 330 | `error_tostring` | 29 | 6.4s |  |
| 331 | `es3_inheritance` | 31 | 6.5s |  |
| 332 | `es4_inheritance` | 30 | 6.5s |  |
| 333 | `es4_interfaces` | 30 | 6.7s |  |
| 334 | `es4_method_binding` | 8 | 3.1s |  |
| 335 | `es4_oop_prototypes` | 14 | 6.8s |  |
| 336 | `es4_protected_inheritance` | 6 | 6.5s |  |
| 337 | `escape` | 71 | 6.6s |  |
| 338 | `event_bubbles` | 2 | 6.5s |  |
| 339 | `event_cancelable` | 2 | 6.4s |  |
| 340 | `event_clone` | 20 | 6.6s |  |
| 341 | `event_clone_error_redispatch` | 3 | 6.7s |  |
| 342 | `event_clone_on_redispatch` | 10 | 6.8s |  |
| 343 | `event_formattostring` | 31 | 6.7s |  |
| 344 | `event_isdefaultprevented` | 12 | 6.5s |  |
| 345 | `event_target_getter` | 5 | 3.0s |  |
| 346 | `event_target_set` | 9 | 6.4s |  |
| 347 | `event_type` | 1 | 6.7s |  |
| 348 | `event_valueof_tostring` | 18 | 6.8s |  |
| 349 | `eventdispatcher_dispatchevent` | 12 | 6.7s |  |
| 350 | `eventdispatcher_dispatchevent_cancel` | 20 | 26.3s |  |
| 351 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.8s |  |
| 352 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.8s |  |
| 353 | `eventdispatcher_dispatchevent_this` | 5 | 6.7s |  |
| 354 | `eventdispatcher_haseventlistener` | 25 | 6.7s |  |
| 355 | `eventdispatcher_interface_invoke` | 1 | 6.6s |  |
| 356 | `eventdispatcher_tostring` | 10 | 6.7s |  |
| 357 | `eventdispatcher_willtrigger` | 25 | 6.6s |  |
| 358 | `falsiness` | 30 | 6.7s |  |
| 359 | `fast_index_access` | 12 | 6.8s |  |
| 360 | `filefilter_properties` | 4 | 6.7s |  |
| 361 | `filereference_browse_cancel` | 3 | 6.7s |  |
| 362 | `filereference_browse_select` | 9 | 6.7s |  |
| 363 | `filereference_load` | 31 | 3.2s |  |
| 364 | `filereference_save` | 16 | 6.8s |  |
| 365 | `filereference_save_and_browse` | 42 | 6.7s |  |
| 366 | `filereference_save_and_load` | 22 | 6.8s |  |
| 367 | `filereference_uninitialized` | 8 | 6.7s |  |
| 368 | `filereferencelist_browse_cancel` | 6 | 3.2s |  |
| 369 | `filereferencelist_browse_select` | 7 | 6.7s |  |
| 370 | `finddef` | 3 | 6.6s |  |
| 371 | `findprop_global_prototype` | 6 | 6.7s |  |
| 372 | `flash_xml` | 29 | 6.7s |  |
| 373 | `flash_xml_cloneNode` | 22 | 6.7s |  |
| 374 | `flash_xml_namespace` | 109 | 6.7s |  |
| 375 | `flash_xml_removeNode` | 60 | 6.7s |  |
| 376 | `focus_events_code` | 161 | 26.5s |  |
| 377 | `focus_events_key_basic` | 132 | 27.5s |  |
| 378 | `focus_events_key_navigation` | 53 | 7.0s |  |
| 379 | `focus_events_key_same_object` | 26 | 6.9s |  |
| 380 | `focus_events_mixed_key_mouse` | 100 | 27.5s |  |
| 381 | `focus_events_mouse_basic` | 260 | 25.2s |  |
| 382 | `focus_events_mouse_focusable` | 112 | 25.2s |  |
| 383 | `focus_events_mouse_same_object` | 40 | 24.8s |  |
| 384 | `focus_remove` | 20 | 24.6s |  |
| 385 | `focus_root_movie` | 4 | 24.6s |  |
| 386 | `focus_stage` | 1 | 6.3s |  |
| 387 | `focusrect` | 18 | 7.0s |  |
| 388 | `focusrect_focuslost` | 9 | 6.4s |  |
| 389 | `focusrect_property` | 110 | 24.5s |  |
| 390 | `font_description_clone` | 14 | 6.3s |  |
| 391 | `font_embedded` | 24 | 6.7s |  |
| 392 | `font_enumeratefonts` | 41 | 6.9s |  |
| 393 | `font_enumeratefonts_filter` | 4 | 25.1s |  |
| 394 | `font_hasglyphs` | 40 | 6.7s |  |
| 395 | `framelabel_constr` | 5 | 6.3s |  |
| 396 | `function_call` | 12 | 6.4s |  |
| 397 | `function_call_arguments` | 46 | 6.4s |  |
| 398 | `function_call_arguments_enumerate` | 5 | 6.3s |  |
| 399 | `function_call_coercion` | 108 | 6.7s |  |
| 400 | `function_call_default` | 6 | 6.3s |  |
| 401 | `function_call_rest` | 22 | 6.3s |  |
| 402 | `function_call_types` | 3 | 6.3s |  |
| 403 | `function_call_via_apply` | 11 | 6.3s |  |
| 404 | `function_call_via_call` | 3 | 6.3s |  |
| 405 | `function_display_anonymous` | 7 | 2.9s |  |
| 406 | `function_length` | 6 | 6.3s |  |
| 407 | `function_object` | 2 | 6.3s |  |
| 408 | `function_proto` | 5 | 6.3s |  |
| 409 | `function_proto_created` | 61 | 6.4s |  |
| 410 | `function_to_locale_string` | 4 | 6.4s |  |
| 411 | `function_to_string` | 4 | 6.3s |  |
| 412 | `function_type` | 6 | 6.3s |  |
| 413 | `function_unbound_this` | 51 | 6.4s |  |
| 414 | `function_value_of` | 4 | 6.3s |  |
| 415 | `get_definition_by_name` | 11 | 6.3s |  |
| 416 | `get_qualified_class_name` | 20 | 6.9s |  |
| 417 | `get_qualified_super_class_name` | 18 | 6.7s |  |
| 418 | `get_slot_edge_cases` | 1 | 25.7s |  |
| 419 | `get_timer` | 2 | 6.6s |  |
| 420 | `getglobalslot` | 1 | 6.5s |  |
| 421 | `getouterscope` | 8 | 6.6s |  |
| 422 | `getter_different_namespace_setter` | 2 | 6.5s |  |
| 423 | `goto_button_nested_framescript` | 28 | 26.1s |  |
| 424 | `goto_in_constructframe` | 12 | 26.0s |  |
| 425 | `goto_in_scene_last_frame` | 2 | 25.8s |  |
| 426 | `goto_methods` | 56 | 6.9s |  |
| 427 | `goto_methods_swfver10` | 8 | 6.7s |  |
| 428 | `goto_nested_construct_sibling` | 18 | 7.1s |  |
| 429 | `goto_nested_framescript` | 9 | 6.8s |  |
| 430 | `goto_on_orphan` | 15 | 6.8s |  |
| 431 | `graphics_bad_direct_commands` | 5 | 7.3s |  |
| 432 | `graphics_bitmap_fill` | 0 | 27.2s |  |
| 433 | `graphics_bitmaps` | 0 | 7.3s |  |
| 434 | `graphics_direct_commands` | 0 | 7.2s |  |
| 435 | `graphics_draw_triangles` | 98 | 26.2s |  |
| 436 | `graphics_gradients` | 0 | 7.0s |  |
| 437 | `graphics_gradients_nulls` | 0 | 6.8s |  |
| 438 | `graphics_path` | 56 | 6.6s |  |
| 439 | `graphics_round_rects` | 0 | 6.7s |  |
| 440 | `graphics_simple_shapes` | 0 | 7.0s |  |
| 441 | `greaterequals` | 512 | 10.5s |  |
| 442 | `greaterthan` | 512 | 10.4s |  |
| 443 | `has_own_property` | 102 | 7.2s |  |
| 444 | `hasownproperty_namespaces` | 2 | 6.6s |  |
| 445 | `hello_world` | 1 | 6.6s |  |
| 446 | `hittest_morph` | 30 | 6.9s |  |
| 447 | `if_eq` | 10 | 6.8s |  |
| 448 | `if_gt` | 1 | 6.8s |  |
| 449 | `if_gte` | 10 | 6.5s |  |
| 450 | `if_lt` | 1 | 6.5s |  |
| 451 | `if_lte` | 10 | 6.3s |  |
| 452 | `if_ne` | 7 | 3.0s |  |
| 453 | `if_stricteq` | 6 | 6.5s |  |
| 454 | `if_strictne` | 11 | 6.5s |  |
| 455 | `ime_linux_dead_keys` | 10 | 25.1s |  |
| 456 | `in` | 102 | 6.8s |  |
| 457 | `inclocal` | 46 | 6.4s |  |
| 458 | `inclocal_i` | 46 | 6.4s |  |
| 459 | `increment` | 46 | 6.4s |  |
| 460 | `increment_i` | 46 | 6.4s |  |
| 461 | `indexing_delete` | 75 | 6.4s |  |
| 462 | `instanceof` | 58 | 6.7s |  |
| 463 | `instantiation_on_enter_frame` | 7 | 24.8s |  |
| 464 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.3s |  |
| 465 | `int_constr` | 92 | 6.3s |  |
| 466 | `int_edge_cases` | 19 | 6.4s |  |
| 467 | `int_instanceof` | 3 | 6.3s |  |
| 468 | `int_tofixed` | 1215 | 6.3s |  |
| 469 | `int_tostring` | 3375 | 6.3s |  |
| 470 | `interactiveobject_enabled` | 25 | 6.3s |  |
| 471 | `interface_namespaces` | 78 | 6.6s |  |
| 472 | `is_finite` | 46 | 6.5s |  |
| 473 | `is_nan` | 46 | 6.3s |  |
| 474 | `is_prototype_of` | 12 | 6.4s |  |
| 475 | `issue_10221` | 2 | 6.4s |  |
| 476 | `issue_13780` | 12 | 6.4s |  |
| 477 | `issue_14901` | 1 | 6.3s |  |
| 478 | `issue_17675_edittext_paste_maxchars` | 1 | 6.4s |  |
| 479 | `issue_5292` | 5 | 6.4s |  |
| 480 | `issue_8630` | 2 | 24.6s |  |
| 481 | `issue_8630_scriptremove` | 11 | 6.3s |  |
| 482 | `istype` | 24 | 3.0s |  |
| 483 | `istypelate` | 58 | 6.7s |  |
| 484 | `istypelate_coerce` | 198 | 7.9s |  |
| 485 | `jpeg_loader_context` | 6 | 25.9s |  |
| 486 | `json_errors` | 9 | 26.1s |  |
| 487 | `json_parse` | 21 | 6.5s |  |
| 488 | `json_stringify` | 12 | 6.7s |  |
| 489 | `json_stringify_order` | 1 | 6.5s |  |
| 490 | `json_version_gated` | 1 | 6.4s |  |
| 491 | `key_input_80percent` | 1812 | 6.7s |  |
| 492 | `key_input_location` | 126 | 6.5s |  |
| 493 | `key_input_numpad` | 384 | 6.4s |  |
| 494 | `lazyinit` | 17 | 6.5s |  |
| 495 | `lessequals` | 512 | 10.8s |  |
| 496 | `lessthan` | 512 | 10.8s |  |
| 497 | `loader_bitmap_transparency` | 14 | 6.7s |  |
| 498 | `loader_bytes_unknown_content` | 14 | 6.8s |  |
| 499 | `loader_child_getdefinition` | 5 | 6.8s |  |
| 500 | `loader_duplicate_coerce` | 3 | 6.6s |  |
| 501 | `loader_duplicate_coerce_new_domain` | 4 | 6.6s |  |
| 502 | `loader_error_in_root_ctor` | 4 | 6.6s |  |
| 503 | `loader_events` | 92 | 7.1s |  |
| 504 | `loader_image` | 8 | 6.8s |  |
| 505 | `loader_jpegxr` | 2 | 25.6s |  |
| 506 | `loader_jpegxr_alpha` | 1 | 25.0s |  |
| 507 | `loader_loadbytes_events` | 30 | 7.1s |  |
| 508 | `loader_loadbytes_invalid_png` | 4 | 25.0s |  |
| 509 | `loader_loadbytes_url` | 12 | 6.7s |  |
| 510 | `loader_loaderurl` | 6 | 6.9s |  |
| 511 | `loader_noninteractive_try_click_root` | 5 | 25.4s |  |
| 512 | `loader_reuse` | 38 | 6.6s |  |
| 513 | `loader_unknown_content` | 24 | 6.5s |  |
| 514 | `loader_visibility_interactive` | 1 | 6.5s |  |
| 515 | `loaderinfo_events` | 7 | 6.3s |  |
| 516 | `loaderinfo_loadurl` | 12 | 27.8s |  |
| 517 | `loaderinfo_more` | 6 | 28.4s |  |
| 518 | `loaderinfo_properties` | 18 | 6.9s |  |
| 519 | `loaderinfo_properties_not_loaded` | 23 | 7.0s |  |
| 520 | `loaderinfo_root` | 10 | 6.9s |  |
| 521 | `loaderinfo_root_allows` | 2 | 6.9s |  |
| 522 | `lshift` | 1058 | 19.5s |  |
| 523 | `mask_reapply` | 1 | 7.0s |  |
| 524 | `math` | 497 | 7.2s |  |
| 525 | `missing_external_interface` | 10 | 6.9s |  |
| 526 | `modulo` | 1058 | 19.5s |  |
| 527 | `morph_shape` | 2 | 28.1s |  |
| 528 | `mouse_children` | 192 | 28.6s |  |
| 529 | `mouse_click_events` | 90 | 27.7s |  |
| 530 | `mouse_double_click_events` | 188 | 6.9s |  |
| 531 | `mouse_empty_parent` | 4 | 6.9s |  |
| 532 | `mouse_over_while_dragging` | 3 | 6.9s |  |
| 533 | `mouse_pick_button_mode` | 2 | 7.0s |  |
| 534 | `mouse_pick_dobj_mask` | 4 | 7.3s |  |
| 535 | `mouse_pick_masking` | 7 | 28.0s |  |
| 536 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 27.8s |  |
| 537 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.3s |  |
| 538 | `mouse_pick_text` | 8 | 7.1s |  |
| 539 | `mouse_sibling` | 8 | 6.9s |  |
| 540 | `mouse_wheel_events` | 36 | 29.3s |  |
| 541 | `mouseevent_constr` | 66 | 7.0s |  |
| 542 | `mouseevent_stagexy` | 35 | 7.0s |  |
| 543 | `mouseevent_valueof_tostring` | 28 | 7.0s |  |
| 544 | `movieclip_addframescript` | 3 | 28.1s |  |
| 545 | `movieclip_child_property` | 16 | 7.1s |  |
| 546 | `movieclip_constr` | 21 | 6.2s |  |
| 547 | `movieclip_currentlabels` | 17 | 25.6s |  |
| 548 | `movieclip_currentlabels_dupes1` | 46 | 25.3s |  |
| 549 | `movieclip_currentlabels_dupes2` | 30 | 6.1s |  |
| 550 | `movieclip_currentlabels_dupes3` | 67 | 6.1s |  |
| 551 | `movieclip_currentscene` | 12 | 24.9s |  |
| 552 | `movieclip_dispatchevent` | 430 | 6.2s |  |
| 553 | `movieclip_dispatchevent_cancel` | 102 | 6.1s |  |
| 554 | `movieclip_dispatchevent_handlerorder` | 251 | 6.1s |  |
| 555 | `movieclip_dispatchevent_selfadd` | 80 | 6.1s |  |
| 556 | `movieclip_dispatchevent_target` | 899 | 6.1s |  |
| 557 | `movieclip_displayevents` | 96 | 25.4s |  |
| 558 | `movieclip_displayevents_clickgoto` | 676 | 25.3s |  |
| 559 | `movieclip_displayevents_clickgoto2` | 2001 | 6.6s |  |
| 560 | `movieclip_displayevents_clickplay` | 575 | 6.2s |  |
| 561 | `movieclip_displayevents_clicksymbol` | 562 | 6.2s |  |
| 562 | `movieclip_displayevents_constructframegoto` | 140 | 6.5s |  |
| 563 | `movieclip_displayevents_constructframeplay` | 50 | 6.2s |  |
| 564 | `movieclip_displayevents_constructframesymbol` | 144 | 6.3s |  |
| 565 | `movieclip_displayevents_dblhandler` | 21 | 6.3s |  |
| 566 | `movieclip_displayevents_enterframegoto` | 149 | 6.3s |  |
| 567 | `movieclip_displayevents_enterframeplay` | 48 | 6.2s |  |
| 568 | `movieclip_displayevents_enterframesymbol` | 149 | 25.2s |  |
| 569 | `movieclip_displayevents_exitframegoto` | 106 | 6.1s |  |
| 570 | `movieclip_displayevents_exitframeplay` | 44 | 6.1s |  |
| 571 | `movieclip_displayevents_exitframesymbol` | 135 | 6.2s |  |
| 572 | `movieclip_displayevents_looping` | 63 | 26.1s |  |
| 573 | `movieclip_displayevents_stopped` | 113 | 6.6s |  |
| 574 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 575 | `movieclip_displayevents_timeline` | 128 | 25.3s |  |
| 576 | `movieclip_drawrect` | 54 | 6.1s |  |
| 577 | `movieclip_frameconstruct_skipped` | 9 | 6.1s |  |
| 578 | `movieclip_goto_during_frame_script` | 15 | 6.2s |  |
| 579 | `movieclip_goto_overwrite` | 14 | 24.9s |  |
| 580 | `movieclip_goto_scene_last_frame_int` | 1 | 24.9s |  |
| 581 | `movieclip_goto_scene_last_frame_label` | 1 | 2.5s |  |
| 582 | `movieclip_gotoandplay` | 15 | 25.2s |  |
| 583 | `movieclip_gotoandstop` | 13 | 6.0s |  |
| 584 | `movieclip_gotoandstop_children` | 4 | 6.2s |  |
| 585 | `movieclip_gotoandstop_framescripts1` | 4 | 6.0s |  |
| 586 | `movieclip_gotoandstop_framescripts2` | 4 | 2.6s |  |
| 587 | `movieclip_gotoandstop_framescripts_self` | 7 | 25.6s |  |
| 588 | `movieclip_gotoandstop_queueing` | 12 | 25.7s |  |
| 589 | `movieclip_next_frame` | 2 | 25.1s |  |
| 590 | `movieclip_next_scene` | 6 | 25.5s |  |
| 591 | `movieclip_play` | 3 | 3.0s |  |
| 592 | `movieclip_prev_frame` | 3 | 6.3s |  |
| 593 | `movieclip_prev_scene` | 7 | 6.6s |  |
| 594 | `movieclip_properties` | 79 | 26.0s |  |
| 595 | `movieclip_queued_noop_goto_swf10` | 9 | 6.6s |  |
| 596 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 597 | `movieclip_scenes` | 11 | 6.5s |  |
| 598 | `movieclip_soundtransform` | 831 | 28.3s |  |
| 599 | `movieclip_stop` | 1 | 25.7s |  |
| 600 | `movieclip_super_is_symbol` | 20 | 6.9s |  |
| 601 | `movieclip_symbol_constr` | 8 | 6.8s |  |
| 602 | `movieclip_text_mousedown` | 1 | 6.7s |  |
| 603 | `movieclip_willtrigger` | 5 | 6.7s |  |
| 604 | `multiply` | 1058 | 18.9s |  |
| 605 | `namespace_constr` | 253 | 6.8s |  |
| 606 | `namespace_constr_args` | 1 | 6.4s |  |
| 607 | `namespace_enumeration_order` | 7 | 25.8s |  |
| 608 | `nan_scale` | 9 | 6.5s |  |
| 609 | `navigateToURL_target_normalize` | 107 | 27.0s |  |
| 610 | `negate` | 30 | 6.6s |  |
| 611 | `negative_volume_panned` | 0 | 6.9s |  |
| 612 | `nested_iteration` | 11 | 6.6s |  |
| 613 | `net_getClassByAlias` | 3 | 6.6s |  |
| 614 | `net_navigateToURL` | 57 | 6.6s |  |
| 615 | `net_stream_play_options` | 6 | 6.5s |  |
| 616 | `netconnection_close` | 55 | 6.6s |  |
| 617 | `netconnection_properties` | 78 | 6.7s |  |
| 618 | `netstream_client` | 10 | 6.7s |  |
| 619 | `netstream_connect` | 7 | 6.5s |  |
| 620 | `newactivation_in_script_init` | 3 | 6.9s |  |
| 621 | `newclass_twice` | 3 | 6.8s |  |
| 622 | `nonconflicting_declarations` | 0 | 6.8s |  |
| 623 | `null_void_types` | 8 | 6.9s |  |
| 624 | `number_autoconv` | 21 | 23.4s |  |
| 625 | `number_autoconv_amf` | 132 | 6.8s |  |
| 626 | `number_autoconv_array_sort_32bit` | 1 | 6.8s |  |
| 627 | `number_constr` | 58 | 7.2s |  |
| 628 | `number_toexponential` | 378 | 7.1s |  |
| 629 | `number_toexponential2` | 35 | 6.9s |  |
| 630 | `number_tofixed` | 378 | 7.0s |  |
| 631 | `number_toprecision` | 350 | 7.0s |  |
| 632 | `obfuscated_class_names` | 3 | 6.8s |  |
| 633 | `object_enumeration` | 10 | 7.1s |  |
| 634 | `object_prototype` | 4 | 7.1s |  |
| 635 | `object_to_locale_string` | 2 | 7.1s |  |
| 636 | `object_to_string` | 2 | 6.8s |  |
| 637 | `object_value_of` | 2 | 3.2s |  |
| 638 | `op_coerce` | 54 | 3.2s |  |
| 639 | `op_coerce_x` | 54 | 6.9s |  |
| 640 | `op_escxattr` | 2 | 6.8s |  |
| 641 | `op_escxelem` | 2 | 6.8s |  |
| 642 | `op_lookupswitch` | 4 | 6.9s |  |
| 643 | `optimize_coerce` | 1 | 6.8s |  |
| 644 | `orphan_movie_complex` | 80 | 7.3s |  |
| 645 | `orphan_movie_reorder` | 111 | 27.1s |  |
| 646 | `package_namespace` | 7 | 6.5s |  |
| 647 | `param_default_value_has_zero_cpool_index` | 1 | 6.6s |  |
| 648 | `parent_early_access_child` | 16 | 26.6s |  |
| 649 | `parse_float` | 81 | 7.1s |  |
| 650 | `pixelbender_effect_BlurredFocus` | 0 | 30.4s |  |
| 651 | `pixelbender_effect_glassDisplace` | 0 | 12.7s |  |
| 652 | `pixelbender_effect_smudge` | 0 | 10.2s |  |
| 653 | `pixelbender_effect_tintype` | 0 | 9.4s |  |
| 654 | `pixelbender_effect_twirl` | 0 | 10.5s |  |
| 655 | `pixelbender_images` | 0 | 9.0s |  |
| 656 | `place_multiple` | 17 | 26.1s |  |
| 657 | `place_object_replace` | 9 | 7.0s |  |
| 658 | `place_object_replace_2` | 24 | 6.9s |  |
| 659 | `place_object_same_depth_frame` | 1 | 6.9s |  |
| 660 | `point` | 132 | 7.3s |  |
| 661 | `primitive_edge_cases` | 1 | 6.6s |  |
| 662 | `property_priority` | 22 | 6.9s |  |
| 663 | `property_priority_three_level` | 6 | 26.0s |  |
| 664 | `propertyisenumerable_namespaces` | 6 | 6.4s |  |
| 665 | `prototype_set_null` | 7 | 6.3s |  |
| 666 | `proxy_callproperty` | 24 | 6.4s |  |
| 667 | `proxy_deleteproperty` | 64 | 6.5s |  |
| 668 | `proxy_enumeration` | 34 | 6.4s |  |
| 669 | `proxy_getproperty` | 77 | 6.5s |  |
| 670 | `proxy_hasownproperty` | 8 | 6.4s |  |
| 671 | `proxy_hasproperty` | 32 | 6.5s |  |
| 672 | `proxy_serialize` | 9 | 6.4s |  |
| 673 | `proxy_setproperty` | 42 | 6.4s |  |
| 674 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.3s |  |
| 675 | `qname_constr` | 32 | 6.4s |  |
| 676 | `qname_constr_namespace` | 24 | 6.4s |  |
| 677 | `qname_enumeration` | 9 | 6.3s |  |
| 678 | `qname_indexing` | 23 | 6.5s |  |
| 679 | `qname_tostring` | 25 | 6.4s |  |
| 680 | `qname_valueof` | 29 | 6.6s |  |
| 681 | `regexp_constr` | 148 | 6.7s |  |
| 682 | `regexp_exec` | 19 | 6.5s |  |
| 683 | `regexp_extended` | 47 | 6.5s |  |
| 684 | `regexp_multiargs` | 1 | 6.4s |  |
| 685 | `regexp_test` | 27 | 3.1s |  |
| 686 | `regexp_toString` | 10 | 6.6s |  |
| 687 | `register_script_refresh` | 35 | 6.9s |  |
| 688 | `remove_child_clear_field` | 88 | 25.5s |  |
| 689 | `remove_dobj` | 3 | 6.4s |  |
| 690 | `resolve_order` | 4 | 6.3s |  |
| 691 | `responder_null_callbacks` | 1 | 6.4s |  |
| 692 | `rng` | 1 | 7.6s |  |
| 693 | `rootless` | 42 | 6.6s |  |
| 694 | `rshift` | 1058 | 18.5s |  |
| 695 | `sandbox_type_inherited` | 2 | 7.4s |  |
| 696 | `sandbox_type_local_file` | 1 | 26.3s |  |
| 697 | `sandbox_type_local_network` | 1 | 6.7s |  |
| 698 | `scene_constr` | 8 | 7.0s |  |
| 699 | `selection` | 239 | 7.3s |  |
| 700 | `set_local_0` | 31 | 7.0s |  |
| 701 | `set_property_is_enumerable` | 85 | 7.5s |  |
| 702 | `shape_drawrect` | 54 | 7.1s |  |
| 703 | `shared_object_no_root` | 3 | 7.0s |  |
| 704 | `simplebutton_added_to_stage` | 45 | 27.3s |  |
| 705 | `simplebutton_childevents` | 86 | 27.8s |  |
| 706 | `simplebutton_childevents_nested` | 54 | 7.4s |  |
| 707 | `simplebutton_childevents_sprite` | 13 | 7.1s |  |
| 708 | `simplebutton_childprops` | 144 | 7.3s |  |
| 709 | `simplebutton_childshuffle` | 23 | 7.0s |  |
| 710 | `simplebutton_constr` | 36 | 7.4s |  |
| 711 | `simplebutton_constr_childevents` | 48 | 7.4s |  |
| 712 | `simplebutton_constr_params` | 42 | 7.3s |  |
| 713 | `simplebutton_mouseenabled` | 26 | 7.0s |  |
| 714 | `simplebutton_multi_children` | 19 | 7.4s |  |
| 715 | `simplebutton_structure` | 27 | 7.3s |  |
| 716 | `simplebutton_symbolclass` | 68 | 7.4s |  |
| 717 | `slot_disp_id_shared_numbering` | 1 | 27.7s |  |
| 718 | `slots_force_autoassigned` | 1 | 7.2s |  |
| 719 | `socket_after_disconnect` | 1 | 7.1s |  |
| 720 | `socket_close` | 2 | 7.0s |  |
| 721 | `socket_connect` | 4 | 7.1s |  |
| 722 | `socket_errors` | 56 | 7.6s |  |
| 723 | `socket_read_big` | 48 | 25.1s |  |
| 724 | `socket_read_little` | 48 | 2.8s |  |
| 725 | `socket_read_write_object` | 8 | 6.4s |  |
| 726 | `socket_write_big` | 15 | 6.7s |  |
| 727 | `socket_write_little` | 14 | 6.4s |  |
| 728 | `sound_embeddedprops` | 26 | 6.6s |  |
| 729 | `sound_play` | 19 | 6.6s |  |
| 730 | `sound_valueof` | 33 | 6.5s |  |
| 731 | `soundchannel_soundtransform` | 835 | 27.0s |  |
| 732 | `soundchannel_soundtransform_exists` | 5 | 25.2s |  |
| 733 | `soundchannel_stop` | 8 | 25.2s |  |
| 734 | `soundmixer_buffertime` | 5 | 6.4s |  |
| 735 | `soundmixer_stopall` | 6 | 25.3s |  |
| 736 | `soundtransform` | 442 | 8.7s |  |
| 737 | `sprite_with_frames` | 0 | 25.6s |  |
| 738 | `stage3d_agal_cross_product` | 0 | 9.1s |  |
| 739 | `stage3d_bitmap` | 0 | 30.4s |  |
| 740 | `stage3d_float1_index` | 0 | 27.8s |  |
| 741 | `stage3d_fractal` | 0 | 28.1s |  |
| 742 | `stage3d_ignore_sampler_override` | 0 | 28.1s |  |
| 743 | `stage3d_program_constants_bytearray_be` | 0 | 29.0s |  |
| 744 | `stage3d_program_constants_bytearray_le` | 0 | 9.7s |  |
| 745 | `stage3d_raytrace` | 0 | 31.1s |  |
| 746 | `stage3d_rotating_cube` | 0 | 10.0s |  |
| 747 | `stage3d_sampler` | 0 | 9.5s |  |
| 748 | `stage3d_sampler_partial_upload` | 0 | 9.4s |  |
| 749 | `stage3d_stencil` | 0 | 29.3s |  |
| 750 | `stage3d_texture` | 0 | 14.1s |  |
| 751 | `stage3d_texture_bytearray` | 0 | 10.7s |  |
| 752 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.1s |  |
| 753 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.2s |  |
| 754 | `stage3d_triangle` | 0 | 9.5s |  |
| 755 | `stage3d_triangle_bytes4` | 0 | 9.4s |  |
| 756 | `stage3d_triangle_float1` | 0 | 9.4s |  |
| 757 | `stage3d_triangle_index_upload` | 0 | 9.4s |  |
| 758 | `stage_access` | 10 | 3.1s |  |
| 759 | `stage_displayobject_properties` | 24 | 6.5s |  |
| 760 | `stage_framerate_nan` | 7 | 22.5s |  |
| 761 | `stage_framerate_negative` | 6 | 6.5s |  |
| 762 | `stage_framerate_zero` | 6 | 6.6s |  |
| 763 | `stage_invalidate` | 38 | 6.8s |  |
| 764 | `stage_loaderinfo_properties` | 24 | 25.6s |  |
| 765 | `stage_mousechildren` | 2 | 6.5s |  |
| 766 | `stage_mouseenabled` | 15 | 6.4s |  |
| 767 | `stage_overriden_setters` | 31 | 6.6s |  |
| 768 | `stage_properties` | 30 | 6.5s |  |
| 769 | `static_var_with_this_in_ctor` | 2 | 6.5s |  |
| 770 | `stored_properties` | 11 | 6.6s |  |
| 771 | `strict_equality` | 34 | 6.6s |  |
| 772 | `string_call` | 13 | 6.5s |  |
| 773 | `string_case` | 23 | 6.5s |  |
| 774 | `string_char_at` | 27 | 6.5s |  |
| 775 | `string_char_code_at` | 28 | 6.4s |  |
| 776 | `string_concat_fromcharcode` | 37 | 6.5s |  |
| 777 | `string_constr` | 25 | 6.6s |  |
| 778 | `string_indexof_lastindexof` | 87 | 27.2s |  |
| 779 | `string_length` | 16 | 6.8s |  |
| 780 | `string_locale_compare` | 39 | 7.1s |  |
| 781 | `string_match` | 51 | 7.2s |  |
| 782 | `string_relational_compare` | 4 | 6.8s |  |
| 783 | `string_replace` | 51 | 7.0s |  |
| 784 | `string_search` | 41 | 7.0s |  |
| 785 | `string_slice_substr_substring` | 170 | 7.9s |  |
| 786 | `string_split` | 29 | 6.9s |  |
| 787 | `string_substr_negative` | 21 | 6.9s |  |
| 788 | `string_substr_weird` | 182 | 6.9s |  |
| 789 | `subtract` | 1058 | 18.1s |  |
| 790 | `super_get_call` | 12 | 6.7s |  |
| 791 | `supercall_two_classobjects` | 2 | 6.7s |  |
| 792 | `swf8` | 1 | 6.6s |  |
| 793 | `swf_10_queued_goto_scripts_construct` | 52 | 25.8s |  |
| 794 | `swf_9_goto_in_enter_frame` | 17 | 6.8s |  |
| 795 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.8s |  |
| 796 | `swf_9_queued_goto_scripts` | 6 | 25.5s |  |
| 797 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 798 | `swf_9_versioning` | 2 | 6.6s |  |
| 799 | `swf_wrong_frame_count` | 38 | 7.0s |  |
| 800 | `swf_wrong_frame_count_isplaying` | 22 | 25.4s |  |
| 801 | `symbol_class_binary_data` | 8 | 6.6s |  |
| 802 | `symbol_class_conflict` | 4 | 7.1s |  |
| 803 | `symbol_class_root_not_zero` | 1 | 6.5s |  |
| 804 | `symbolclass_invalid_utf8` | 2 | 6.6s |  |
| 805 | `tab_ordering_automatic_advanced` | 184 | 3.9s |  |
| 806 | `tab_ordering_automatic_basic` | 45 | 15.2s |  |
| 807 | `tab_ordering_children` | 116 | 3.4s |  |
| 808 | `tab_ordering_custom_basic` | 34 | 3.5s |  |
| 809 | `tab_ordering_stage_tab_children` | 32 | 3.4s |  |
| 810 | `tab_ordering_stage_tab_children_remove_root` | 5 | 3.4s |  |
| 811 | `tab_ordering_tabbable` | 47 | 3.4s |  |
| 812 | `text_engine_fontdescription` | 27 | 3.5s |  |
| 813 | `text_run` | 7 | 3.4s |  |
| 814 | `textbox_click` | 37 | 15.6s |  |
| 815 | `textfield_event` | 66 | 3.5s |  |
| 816 | `textfield_focusin_event` | 9 | 3.5s |  |
| 817 | `textfield_input_dead_keys_windows` | 15 | 3.5s |  |
| 818 | `textfield_unload` | 39 | 15.1s |  |
| 819 | `textformat` | 1134 | 3.5s |  |
| 820 | `textformat_display` | 14 | 3.5s |  |
| 821 | `textformat_font_max_length` | 4 | 1.2s |  |
| 822 | `throw` | 3 | 3.5s |  |
| 823 | `timeline_scripts` | 3 | 3.5s |  |
| 824 | `timer` | 90 | 3.8s |  |
| 825 | `timer_events` | 3 | 3.6s |  |
| 826 | `timer_finished` | 11 | 1.4s |  |
| 827 | `timer_reset` | 8 | 3.7s |  |
| 828 | `timer_setdelay` | 5 | 3.6s |  |
| 829 | `trace` | 12 | 3.5s |  |
| 830 | `truthiness` | 30 | 1.1s |  |
| 831 | `try_catch` | 11 | 1.1s |  |
| 832 | `try_catch_typed` | 12 | 1.2s |  |
| 833 | `typeof` | 30 | 1.2s |  |
| 834 | `uint_constr` | 92 | 1.2s |  |
| 835 | `uint_tofixed` | 1215 | 1.1s |  |
| 836 | `uint_tostring` | 3375 | 1.1s |  |
| 837 | `unchecked_function` | 15 | 1.1s |  |
| 838 | `unescape` | 28 | 1.1s |  |
| 839 | `url_loader` | 25 | 1.1s |  |
| 840 | `urlrequest` | 18 | 20.2s |  |
| 841 | `urlstream_basic` | 5 | 1.1s |  |
| 842 | `urshift` | 1058 | 1.1s |  |
| 843 | `vector_class` | 36 | 1.1s |  |
| 844 | `vector_class_call` | 11 | 1.1s |  |
| 845 | `vector_coercion` | 66 | 1.1s |  |
| 846 | `vector_concat` | 90 | 1.1s |  |
| 847 | `vector_constr` | 107 | 1.1s |  |
| 848 | `vector_enumeration` | 5 | 1.1s |  |
| 849 | `vector_every` | 92 | 1.1s |  |
| 850 | `vector_filter` | 95 | 1.1s |  |
| 851 | `vector_holes` | 24 | 1.1s |  |
| 852 | `vector_indexof` | 302 | 1.2s |  |
| 853 | `vector_insertat` | 270 | 1.1s |  |
| 854 | `vector_int_access` | 4 | 1.1s |  |
| 855 | `vector_int_delete` | 11 | 1.1s |  |
| 856 | `vector_join` | 58 | 1.1s |  |
| 857 | `vector_lastindexof` | 302 | 1.1s |  |
| 858 | `vector_legacy` | 10 | 1.1s |  |
| 859 | `vector_map` | 85 | 1.1s |  |
| 860 | `vector_object_final` | 1 | 1.1s |  |
| 861 | `vector_object_toString` | 10 | 1.1s |  |
| 862 | `vector_pushpop` | 255 | 1.1s |  |
| 863 | `vector_reborrow_bug` | 10 | 26.7s |  |
| 864 | `vector_removeat` | 172 | 7.8s |  |
| 865 | `vector_reverse` | 232 | 7.8s |  |
| 866 | `vector_shiftunshift` | 252 | 6.6s |  |
| 867 | `vector_slice` | 331 | 8.7s |  |
| 868 | `vector_sort` | 905 | 16.6s |  |
| 869 | `vector_splice` | 693 | 11.1s |  |
| 870 | `vector_splice_fixed_bug_compat` | 4 | 6.9s |  |
| 871 | `vector_tostring` | 79 | 7.4s |  |
| 872 | `verify_abnormal_loop` | 1 | 6.5s |  |
| 873 | `verify_exception_targets_edge_case` | 1 | 6.6s |  |
| 874 | `verify_lookup_switch_edge_case` | 1 | 6.7s |  |
| 875 | `verify_unreachable_exception` | 2 | 6.6s |  |
| 876 | `versioned_isplaying` | 2 | 6.6s |  |
| 877 | `virtual_properties` | 16 | 6.7s |  |
| 878 | `with` | 4 | 6.7s |  |
| 879 | `wrong_arg_count` | 7 | 6.9s |  |
| 880 | `xml_abstract_equality` | 36 | 7.0s |  |
| 881 | `xml_advanced` | 52 | 6.7s |  |
| 882 | `xml_appendchild` | 10 | 6.7s |  |
| 883 | `xml_as_attribute` | 9 | 6.6s |  |
| 884 | `xml_attribute` | 35 | 6.8s |  |
| 885 | `xml_attribute_name` | 40 | 6.8s |  |
| 886 | `xml_basic` | 33 | 7.0s |  |
| 887 | `xml_child` | 25 | 7.0s |  |
| 888 | `xml_childindex` | 7 | 6.8s |  |
| 889 | `xml_children` | 43 | 7.5s |  |
| 890 | `xml_class_call` | 9 | 6.7s |  |
| 891 | `xml_contains` | 197 | 6.8s |  |
| 892 | `xml_copy` | 20 | 26.3s |  |
| 893 | `xml_ctor_from_tostring` | 23 | 7.2s |  |
| 894 | `xml_delete` | 114 | 6.9s |  |
| 895 | `xml_descendants` | 83 | 6.9s |  |
| 896 | `xml_elements` | 6 | 6.9s |  |
| 897 | `xml_equals_namespace_check` | 2 | 6.8s |  |
| 898 | `xml_explicit_use_namespace` | 5 | 25.9s |  |
| 899 | `xml_getdescendants_qname` | 21 | 6.8s |  |
| 900 | `xml_has_property_via_in` | 26 | 6.8s |  |
| 901 | `xml_hasownproperty` | 6 | 6.8s |  |
| 902 | `xml_ignore_white` | 6 | 6.7s |  |
| 903 | `xml_length` | 2 | 6.8s |  |
| 904 | `xml_list_as_attribute` | 9 | 6.8s |  |
| 905 | `xml_list_concat` | 20 | 6.8s |  |
| 906 | `xml_list_enumerate` | 4 | 6.6s |  |
| 907 | `xml_methods_settings` | 3 | 6.6s |  |
| 908 | `xml_mismatched_tag` | 37 | 6.7s |  |
| 909 | `xml_namespace` | 39 | 3.1s |  |
| 910 | `xml_namespace_methods` | 245 | 6.8s |  |
| 911 | `xml_namespaced_property` | 7 | 6.6s |  |
| 912 | `xml_no_namespace` | 1 | 6.6s |  |
| 913 | `xml_nodekind` | 3 | 6.8s |  |
| 914 | `xml_normalize` | 35 | 6.9s |  |
| 915 | `xml_notification_bubbling` | 361 | 6.8s |  |
| 916 | `xml_parent` | 8 | 6.7s |  |
| 917 | `xml_set_children` | 17 | 6.9s |  |
| 918 | `xml_set_name` | 34 | 6.8s |  |
| 919 | `xml_settings` | 6 | 3.2s |  |
| 920 | `xml_simple_complex_content` | 47 | 6.8s |  |
| 921 | `xml_socket` | 11 | 6.9s |  |
| 922 | `xml_text` | 7 | 6.7s |  |
| 923 | `xml_tostring` | 6 | 6.7s |  |
| 924 | `xml_tostring_namespace` | 12 | 6.8s |  |
| 925 | `xml_unescaping` | 23 | 6.8s |  |
| 926 | `xml_weird_ignores` | 54 | 6.8s |  |
| 927 | `xml_wildcard` | 11 | 6.7s |  |
| 928 | `xmldocument` | 254 | 6.8s |  |
| 929 | `xmlnode` | 3540 | 6.8s |  |
| 930 | `zero_frame_clip` | 3 | 7.2s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.9s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 25.2s |  |
| 3 | `blend_transform` | 1 | 1 | 7.0s |  |
| 4 | `coerce_property` | 3 | 3 | 6.4s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 2.8s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 25.0s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.6s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 26.1s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.4s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.5s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.6s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 6.2s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 25.7s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 26.1s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.3s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.3s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.3s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 7.0s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 27.5s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.1s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.7s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.5s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 25.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 1.2s |  |
| 25 | `uint_toprecision` | 433 | 433 | 1.1s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 26.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**58 tests** within reach

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
| 44 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 46 | `verification` | 62.5% | 5 | 8 | 3 |  |
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
| 57 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 58 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 27.9s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.3s |  |
| 3 | `verify_typecheck` | exit code 1 | 3.0s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**262 tests** with output mismatch, sorted by match rate (best first)

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
| 44 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 46 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
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
| 57 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 58 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 59 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 60 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 61 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 62 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 63 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 64 | `amf_array_serialization` | 35.3% | 6/17 | 6 | 17 |  |
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
| 84 | `netconnection_serialize_arrays` | 16.7% | 1/6 | 1 | 6 |  |
| 85 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 86 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 87 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 88 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 89 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 90 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 91 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 92 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 93 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 94 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 95 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 96 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 97 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 98 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 99 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 100 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 101 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 102 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 103 | `localconnection` | 7.5% | 67/890 | 623 | 890 |  |
| 104 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 105 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 106 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 107 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 108 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 109 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 110 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 111 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 112 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 113 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 114 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 115 | `netconnection_send_remote` | 4.0% | 2/50 | 2 | 50 |  |
| 116 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 117 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 118 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 119 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 120 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 121 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 122 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 123 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 124 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 125 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 126 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 127 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 128 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 129 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 130 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 131 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 132 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 133 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 134 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 135 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 136 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 137 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 138 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 139 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 140 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 141 | `all_classes/events/swf9` | 0.1% | 1/1030 | 178 | 1030 |  |
| 142 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 143 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 144 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 145 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 146 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 147 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 148 | `all_classes/events/swf10` | 0.1% | 1/1638 | 178 | 1638 |  |
| 149 | `all_classes/events/swf11` | 0.1% | 1/1750 | 178 | 1750 |  |
| 150 | `all_classes/events/swf12` | 0.1% | 1/1814 | 178 | 1814 |  |
| 151 | `all_classes/events/swf30` | 0.0% | 1/2353 | 178 | 2353 |  |
| 152 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 153 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 154 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 155 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 156 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 157 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 158 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 159 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 160 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 161 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 162 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 163 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 164 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 165 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 166 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 167 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 168 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 169 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 170 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 171 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 172 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 173 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 174 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 175 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 176 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 177 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 178 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 179 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 180 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 181 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 182 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 183 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 184 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 185 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 186 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 187 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 188 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 189 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 190 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 191 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 192 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 193 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 194 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 195 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 196 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 197 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 198 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 199 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 200 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 201 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 202 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 203 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 204 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 205 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 206 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 207 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 208 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 209 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 210 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 211 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 212 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 213 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 214 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 215 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 216 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 217 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 218 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 219 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 220 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 221 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 222 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 223 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 224 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 225 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 226 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 227 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 228 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 229 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 230 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 231 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 232 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 233 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 234 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 235 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 236 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 237 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 238 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 239 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 240 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 241 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 242 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 243 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 244 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 245 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 246 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 247 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 248 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 249 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 250 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 251 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 252 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 253 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 254 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 255 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 256 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 257 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 258 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 259 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 260 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 261 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 262 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
