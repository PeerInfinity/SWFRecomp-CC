# Ruffle Test Results (Filtered)

**Date**: 2026-07-29 03:45 UTC

**Git SHA**: `72fdc5e933`

**Run Duration**: 165m 27s

**Filtered**: 53 tests ignored out of 1221 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1168 |
| Passing | **927** (79.4%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **929** (79.5%) |
| Failing | 239 |
| Total expected lines | 133050 |
| Matching lines | 100990 (75.9%) |
| Mismatched lines | 32060 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 236 | 98.7% |
| Runtime Error | 3 | 1.3% |

## Passing Tests

**927 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.3s |  |
| 2 | `agal_compiler` | 13 | 7.7s |  |
| 3 | `air_datagram_socket` | 1 | 5.8s |  |
| 4 | `air_hidden_lookup` | 2 | 5.3s |  |
| 5 | `all_classes/security/swf11` | 3 | 5.4s |  |
| 6 | `amf_custom_obj` | 26 | 5.4s |  |
| 7 | `amf_dictionary` | 9 | 5.3s |  |
| 8 | `amf_function` | 46 | 5.4s |  |
| 9 | `amf_invalid_date` | 2 | 5.3s |  |
| 10 | `amf_missing_prop` | 6 | 5.3s |  |
| 11 | `amf_nondynamic_function_prop` | 6 | 5.4s |  |
| 12 | `amf_setter_error` | 8 | 5.8s |  |
| 13 | `amf_vector` | 40 | 5.7s |  |
| 14 | `amf_xml` | 6 | 5.7s |  |
| 15 | `application_domain` | 4 | 5.7s |  |
| 16 | `array_access` | 18 | 5.5s |  |
| 17 | `array_access_interpreter` | 4 | 5.5s |  |
| 18 | `array_access_no_pubns` | 2 | 5.4s |  |
| 19 | `array_concat` | 41 | 5.5s |  |
| 20 | `array_constr` | 10 | 5.5s |  |
| 21 | `array_delete` | 44 | 5.6s |  |
| 22 | `array_enumeration` | 10 | 5.5s |  |
| 23 | `array_enumeration_elements` | 11 | 5.5s |  |
| 24 | `array_every` | 8 | 5.5s |  |
| 25 | `array_filter` | 6 | 5.5s |  |
| 26 | `array_foreach` | 18 | 5.5s |  |
| 27 | `array_hasownproperty` | 11 | 2.2s |  |
| 28 | `array_holes` | 9 | 5.4s |  |
| 29 | `array_index_max` | 84 | 5.4s |  |
| 30 | `array_indexof` | 25 | 5.5s |  |
| 31 | `array_join` | 26 | 5.5s |  |
| 32 | `array_lastindexof` | 29 | 5.5s |  |
| 33 | `array_length` | 14 | 5.4s |  |
| 34 | `array_literal` | 3 | 5.5s |  |
| 35 | `array_map` | 8 | 5.5s |  |
| 36 | `array_pop` | 52 | 6.0s |  |
| 37 | `array_push` | 24 | 5.7s |  |
| 38 | `array_reborrow_bug` | 6 | 5.7s |  |
| 39 | `array_reverse` | 28 | 5.8s |  |
| 40 | `array_shift` | 51 | 2.5s |  |
| 41 | `array_slice` | 39 | 5.8s |  |
| 42 | `array_some` | 8 | 5.8s |  |
| 43 | `array_sort` | 297 | 6.3s |  |
| 44 | `array_sort_fun_swf12` | 2 | 5.8s |  |
| 45 | `array_sort_fun_swf13` | 2 | 0.7s |  |
| 46 | `array_sort_random` | 210 | 5.8s |  |
| 47 | `array_sort_swf10_32bit` | 1 | 5.8s |  |
| 48 | `array_sorton` | 545 | 6.2s |  |
| 49 | `array_sparse_ops` | 41 | 5.5s |  |
| 50 | `array_splice` | 133 | 5.6s |  |
| 51 | `array_splice2` | 428 | 5.7s |  |
| 52 | `array_splice_types` | 48 | 5.5s |  |
| 53 | `array_storage` | 8 | 5.4s |  |
| 54 | `array_tolocalestring` | 9 | 5.3s |  |
| 55 | `array_tostring` | 12 | 5.4s |  |
| 56 | `array_unshift` | 24 | 5.4s |  |
| 57 | `array_valueof` | 9 | 5.3s |  |
| 58 | `array_vector_null_callback` | 10 | 5.3s |  |
| 59 | `astype` | 28 | 5.5s |  |
| 60 | `astypelate` | 24 | 5.5s |  |
| 61 | `astypelate_propagates` | 1 | 5.3s |  |
| 62 | `asymmetric_key_events` | 11 | 5.4s |  |
| 63 | `av_networking_params` | 9 | 5.4s |  |
| 64 | `avm2_catchup_dobj` | 158 | 6.0s |  |
| 65 | `away3d_advanced_shallow_water_demo` | 0 | 77.7s |  |
| 66 | `bitand` | 1058 | 17.4s |  |
| 67 | `bitmap_constr` | 17 | 5.7s |  |
| 68 | `bitmap_data` | 1000 | 13.6s |  |
| 69 | `bitmap_pixelsnapping` | 2 | 24.6s |  |
| 70 | `bitmap_properties` | 23 | 5.5s |  |
| 71 | `bitmap_subclass` | 7 | 7.0s |  |
| 72 | `bitmap_subclass_properties` | 9 | 5.9s |  |
| 73 | `bitmap_timeline` | 9 | 5.7s |  |
| 74 | `bitmapdata_accuracy` | 1 | 42.3s |  |
| 75 | `bitmapdata_applyfilter_blur` | 0 | 24.7s |  |
| 76 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.8s |  |
| 77 | `bitmapdata_applyfilter_destpoint` | 0 | 25.1s |  |
| 78 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.6s |  |
| 79 | `bitmapdata_clone` | 13 | 5.7s |  |
| 80 | `bitmapdata_colortransform` | 0 | 5.8s |  |
| 81 | `bitmapdata_colortransform_oob` | 2 | 5.5s |  |
| 82 | `bitmapdata_constr` | 22 | 5.7s |  |
| 83 | `bitmapdata_constructor_from_timeline` | 1 | 5.9s |  |
| 84 | `bitmapdata_copychannel` | 0 | 21.9s |  |
| 85 | `bitmapdata_copypixels` | 23 | 19.5s |  |
| 86 | `bitmapdata_copypixels_blend_over` | 1 | 4.6s |  |
| 87 | `bitmapdata_copypixelstobytearray` | 39 | 4.3s |  |
| 88 | `bitmapdata_dispose` | 7 | 4.3s |  |
| 89 | `bitmapdata_draw` | 0 | 19.1s |  |
| 90 | `bitmapdata_draw_colortransform` | 0 | 4.4s |  |
| 91 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 19.2s |  |
| 92 | `bitmapdata_draw_filters` | 0 | 19.1s |  |
| 93 | `bitmapdata_draw_masks` | 0 | 4.4s |  |
| 94 | `bitmapdata_draw_rotation` | 0 | 4.3s |  |
| 95 | `bitmapdata_draw_self_via_graphic` | 0 | 4.3s |  |
| 96 | `bitmapdata_draw_stage` | 0 | 18.9s |  |
| 97 | `bitmapdata_drawwithquality` | 0 | 4.5s |  |
| 98 | `bitmapdata_embedded` | 9 | 4.4s |  |
| 99 | `bitmapdata_fillrect` | 0 | 4.4s |  |
| 100 | `bitmapdata_filter_sourcerect` | 0 | 18.9s |  |
| 101 | `bitmapdata_floodfill` | 35 | 4.3s |  |
| 102 | `bitmapdata_getpixels` | 39 | 18.9s |  |
| 103 | `bitmapdata_getvector` | 27 | 1.7s |  |
| 104 | `bitmapdata_histogram` | 59 | 1.7s |  |
| 105 | `bitmapdata_hittest` | 112 | 4.8s |  |
| 106 | `bitmapdata_hittest_threshold` | 18 | 4.3s |  |
| 107 | `bitmapdata_opaque` | 0 | 4.3s |  |
| 108 | `bitmapdata_pixeldissolve` | 1037 | 19.2s |  |
| 109 | `bitmapdata_pixeldissolve_image` | 0 | 4.5s |  |
| 110 | `bitmapdata_rectangle_rounding` | 16 | 4.5s |  |
| 111 | `bitmapdata_setpixels` | 286 | 4.4s |  |
| 112 | `bitmapdata_setvector` | 26 | 4.4s |  |
| 113 | `bitmapdata_sync` | 0 | 4.4s |  |
| 114 | `bitmapdata_threshold` | 176 | 4.9s |  |
| 115 | `bitnot` | 46 | 4.3s |  |
| 116 | `bitor` | 1058 | 13.1s |  |
| 117 | `bitxor` | 1058 | 13.1s |  |
| 118 | `blend_multiply_alpha` | 0 | 5.0s |  |
| 119 | `blend_scroll` | 0 | 5.5s |  |
| 120 | `boolean_constr` | 32 | 5.4s |  |
| 121 | `boolean_negation` | 30 | 5.4s |  |
| 122 | `boolean_tostring` | 8 | 5.4s |  |
| 123 | `broadcast_event` | 7 | 5.3s |  |
| 124 | `button_nested_frame` | 48 | 24.3s |  |
| 125 | `bytearray` | 48 | 5.7s |  |
| 126 | `bytearray_compress` | 31 | 5.4s |  |
| 127 | `bytearray_errors` | 24 | 5.5s |  |
| 128 | `bytearray_method_serialization` | 1 | 5.4s |  |
| 129 | `bytearray_readobject_amf0` | 50 | 5.3s |  |
| 130 | `bytearray_readobject_amf3` | 53 | 5.5s |  |
| 131 | `bytearray_readutf8bytes_with_bom` | 16 | 5.4s |  |
| 132 | `bytearray_serialization` | 3 | 5.4s |  |
| 133 | `bytearray_string_null` | 19 | 5.7s |  |
| 134 | `bytearray_tostring` | 15 | 5.5s |  |
| 135 | `bytearray_utf16` | 8 | 5.4s |  |
| 136 | `bytearray_writeobject` | 24 | 5.2s |  |
| 137 | `callee_in_initializer` | 6 | 5.3s |  |
| 138 | `callproplex_class` | 1 | 5.3s |  |
| 139 | `capabilities_resolution` | 8 | 25.0s |  |
| 140 | `catch_class` | 6 | 5.5s |  |
| 141 | `catch_scope_slot` | 7 | 2.2s |  |
| 142 | `checkfilter` | 4 | 2.2s |  |
| 143 | `class_call` | 32 | 24.2s |  |
| 144 | `class_cast_call` | 14 | 5.6s |  |
| 145 | `class_enumeration` | 4 | 5.5s |  |
| 146 | `class_has_own_property` | 2 | 5.5s |  |
| 147 | `class_init_interpreter_mode` | 1 | 5.4s |  |
| 148 | `class_is` | 32 | 5.6s |  |
| 149 | `class_methods` | 5 | 5.5s |  |
| 150 | `class_object_properties` | 10 | 5.6s |  |
| 151 | `class_singleton` | 18 | 5.6s |  |
| 152 | `class_supercalls_errors` | 35 | 5.8s |  |
| 153 | `class_supercalls_mismatched` | 26 | 5.7s |  |
| 154 | `class_superclass_wrong_order` | 1 | 23.4s |  |
| 155 | `class_to_locale_string` | 2 | 5.3s |  |
| 156 | `class_to_string` | 2 | 5.2s |  |
| 157 | `class_value_of` | 2 | 5.3s |  |
| 158 | `click_block` | 5 | 23.8s |  |
| 159 | `click_invisible` | 3 | 5.5s |  |
| 160 | `closures` | 12 | 5.4s |  |
| 161 | `coerce_return_type` | 40 | 5.5s |  |
| 162 | `coerce_return_type_fail` | 2 | 5.3s |  |
| 163 | `coerce_return_void` | 3 | 5.3s |  |
| 164 | `coerce_string` | 86 | 5.5s |  |
| 165 | `coerce_string_precision` | 28 | 5.4s |  |
| 166 | `coerce_to_primitive_side_effects` | 29 | 23.8s |  |
| 167 | `construct_errors_swf10` | 8 | 5.4s |  |
| 168 | `construct_frame_list` | 22 | 23.7s |  |
| 169 | `constructor_call` | 3 | 5.3s |  |
| 170 | `constructors_vs_timeline` | 5 | 23.9s |  |
| 171 | `constructprop_dynamic_primitive` | 7 | 5.4s |  |
| 172 | `control_flow_bool` | 4 | 5.4s |  |
| 173 | `control_flow_stricteq` | 8 | 5.4s |  |
| 174 | `convert_boolean` | 30 | 5.4s |  |
| 175 | `convert_integer` | 90 | 5.6s |  |
| 176 | `convert_number` | 56 | 5.5s |  |
| 177 | `convert_uinteger` | 90 | 5.5s |  |
| 178 | `cross_api_version_call_older` | 12 | 5.6s |  |
| 179 | `cryptscore` | 11 | 5.5s |  |
| 180 | `date_parse` | 36 | 5.5s |  |
| 181 | `declocal` | 46 | 5.5s |  |
| 182 | `declocal_i` | 46 | 5.5s |  |
| 183 | `decode_uri` | 71 | 5.9s |  |
| 184 | `decrement` | 46 | 5.6s |  |
| 185 | `decrement_i` | 46 | 2.2s |  |
| 186 | `default_values` | 7 | 5.5s |  |
| 187 | `dictionary_access` | 62 | 5.9s |  |
| 188 | `dictionary_access_no_pubns` | 2 | 5.6s |  |
| 189 | `dictionary_delete` | 101 | 6.0s |  |
| 190 | `dictionary_foreach` | 42 | 5.7s |  |
| 191 | `dictionary_hasownproperty` | 63 | 5.7s |  |
| 192 | `dictionary_in` | 62 | 5.7s |  |
| 193 | `dictionary_iter_modify` | 8 | 5.5s |  |
| 194 | `dictionary_namespaces` | 36 | 5.5s |  |
| 195 | `dictionary_primitive_keys` | 29 | 5.5s |  |
| 196 | `displayobject_alpha` | 277 | 5.5s |  |
| 197 | `displayobject_blendmode` | 0 | 5.5s |  |
| 198 | `displayobject_colortransform_nested` | 0 | 24.4s |  |
| 199 | `displayobject_from_enterframe` | 1 | 24.4s |  |
| 200 | `displayobject_getbounds_shape` | 0 | 24.3s |  |
| 201 | `displayobject_height` | 6052 | 24.2s |  |
| 202 | `displayobject_hittestobject` | 32 | 5.5s |  |
| 203 | `displayobject_invalid_floats` | 60 | 5.5s |  |
| 204 | `displayobject_invalid_props` | 3 | 5.5s |  |
| 205 | `displayobject_mask` | 3 | 5.5s |  |
| 206 | `displayobject_mask_self_referential` | 0 | 24.1s |  |
| 207 | `displayobject_metaData` | 3 | 5.4s |  |
| 208 | `displayobject_name` | 22 | 24.1s |  |
| 209 | `displayobject_name_from_timeline` | 24 | 24.3s |  |
| 210 | `displayobject_parent` | 12 | 5.3s |  |
| 211 | `displayobject_root` | 24 | 5.4s |  |
| 212 | `displayobject_rotation` | 1284 | 5.5s |  |
| 213 | `displayobject_set_matrix_nested` | 0 | 24.1s |  |
| 214 | `displayobject_set_name_loaded` | 3 | 5.7s |  |
| 215 | `displayobject_subclass` | 2 | 5.4s |  |
| 216 | `displayobject_visible` | 23 | 5.4s |  |
| 217 | `displayobject_width` | 4852 | 24.0s |  |
| 218 | `displayobject_x` | 614 | 5.4s |  |
| 219 | `displayobject_y` | 617 | 5.5s |  |
| 220 | `displayobjectcontainer_addchild` | 32 | 5.5s |  |
| 221 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.4s |  |
| 222 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.6s |  |
| 223 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.5s |  |
| 224 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.5s |  |
| 225 | `displayobjectcontainer_addchildat` | 42 | 5.5s |  |
| 226 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.6s |  |
| 227 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.6s |  |
| 228 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.6s |  |
| 229 | `displayobjectcontainer_contains` | 66 | 24.4s |  |
| 230 | `displayobjectcontainer_getchildat` | 4 | 5.6s |  |
| 231 | `displayobjectcontainer_getchildbyname` | 9 | 5.5s |  |
| 232 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.5s |  |
| 233 | `displayobjectcontainer_getchildindex` | 28 | 5.5s |  |
| 234 | `displayobjectcontainer_removechild` | 10 | 5.4s |  |
| 235 | `displayobjectcontainer_removechild_errors` | 4 | 5.5s |  |
| 236 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.5s |  |
| 237 | `displayobjectcontainer_removechildat` | 18 | 5.5s |  |
| 238 | `displayobjectcontainer_removechildren` | 51 | 5.7s |  |
| 239 | `displayobjectcontainer_setchildindex` | 42 | 5.5s |  |
| 240 | `displayobjectcontainer_stopallmovieclips` | 2 | 24.8s |  |
| 241 | `displayobjectcontainer_swapchildren` | 42 | 5.6s |  |
| 242 | `displayobjectcontainer_swapchildrenat` | 42 | 5.6s |  |
| 243 | `displayobjectcontainer_timelineinstance` | 48 | 24.4s |  |
| 244 | `divide` | 1058 | 17.6s |  |
| 245 | `doabc_is_eager` | 1 | 23.8s |  |
| 246 | `documentclass` | 9 | 5.6s |  |
| 247 | `domain_memory` | 133 | 25.2s |  |
| 248 | `drag_drop` | 10 | 5.6s |  |
| 249 | `duplicate_defs` | 1 | 5.2s |  |
| 250 | `eager_init` | 1 | 5.4s |  |
| 251 | `edit_text_linkage` | 7 | 5.6s |  |
| 252 | `edittext_align` | 60 | 5.8s |  |
| 253 | `edittext_always_show_selection` | 0 | 24.4s |  |
| 254 | `edittext_antialiastype` | 296 | 5.7s |  |
| 255 | `edittext_at_point_methods_basic` | 16 | 6.9s |  |
| 256 | `edittext_autosize` | 39 | 5.8s |  |
| 257 | `edittext_autosize_align` | 0 | 25.4s |  |
| 258 | `edittext_autosize_height_dynamic` | 60 | 24.2s |  |
| 259 | `edittext_autosize_height_input` | 60 | 5.5s |  |
| 260 | `edittext_autosize_lazy_bounds_events` | 65 | 5.9s |  |
| 261 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.5s |  |
| 262 | `edittext_autosize_lazy_bounds_props` | 490 | 6.8s |  |
| 263 | `edittext_autosize_lazy_bounds_visual` | 0 | 24.2s |  |
| 264 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.6s |  |
| 265 | `edittext_bottom_scroll_v_basic` | 210 | 5.6s |  |
| 266 | `edittext_bounds_scale` | 24 | 23.8s |  |
| 267 | `edittext_bullet` | 30 | 5.5s |  |
| 268 | `edittext_default_format` | 221 | 5.7s |  |
| 269 | `edittext_default_format_empty` | 136 | 5.8s |  |
| 270 | `edittext_empty_text_format` | 7 | 5.7s |  |
| 271 | `edittext_focus_selection` | 5 | 5.7s |  |
| 272 | `edittext_font_size` | 45 | 5.6s |  |
| 273 | `edittext_format_empty_font` | 8 | 5.4s |  |
| 274 | `edittext_get_char_index_at_point` | 4 | 25.9s |  |
| 275 | `edittext_get_line_index_at_point` | 2 | 25.8s |  |
| 276 | `edittext_get_line_index_of_char` | 76 | 6.6s |  |
| 277 | `edittext_getcharboundaries` | 172 | 6.0s |  |
| 278 | `edittext_getcharboundaries_missing_glyphs` | 63 | 4.8s |  |
| 279 | `edittext_getcharboundaries_scroll` | 85 | 19.9s |  |
| 280 | `edittext_getlinemetrics` | 146 | 4.6s |  |
| 281 | `edittext_html` | 3101 | 4.8s |  |
| 282 | `edittext_html_condensewhite` | 487 | 4.6s |  |
| 283 | `edittext_html_entity` | 4 | 4.7s |  |
| 284 | `edittext_html_font_size_swf12` | 267 | 4.7s |  |
| 285 | `edittext_html_font_size_swf13` | 273 | 4.2s |  |
| 286 | `edittext_html_roundtrip` | 17 | 4.5s |  |
| 287 | `edittext_ime_focus_lost` | 9 | 19.9s |  |
| 288 | `edittext_input_control` | 12 | 4.7s |  |
| 289 | `edittext_leading` | 9 | 4.7s |  |
| 290 | `edittext_letter_spacing` | 15 | 4.5s |  |
| 291 | `edittext_line_methods` | 294 | 5.5s |  |
| 292 | `edittext_line_metrics` | 11 | 21.4s |  |
| 293 | `edittext_margins` | 25 | 4.5s |  |
| 294 | `edittext_max_scroll_h_basic` | 475 | 4.6s |  |
| 295 | `edittext_max_scroll_v_basic` | 1000 | 4.5s |  |
| 296 | `edittext_mouse_selection` | 363 | 20.8s |  |
| 297 | `edittext_mousedown` | 3 | 5.0s |  |
| 298 | `edittext_mouseenabled` | 26 | 4.5s |  |
| 299 | `edittext_newline_character` | 22 | 4.4s |  |
| 300 | `edittext_newline_stripping` | 64 | 6.5s |  |
| 301 | `edittext_newlines` | 30 | 4.5s |  |
| 302 | `edittext_paragraph_methods` | 257 | 4.5s |  |
| 303 | `edittext_paste_events` | 8 | 4.4s |  |
| 304 | `edittext_paste_maxchars` | 4 | 4.5s |  |
| 305 | `edittext_paste_restrict` | 16 | 4.3s |  |
| 306 | `edittext_restrict` | 191 | 4.5s |  |
| 307 | `edittext_restrict_events` | 22 | 4.4s |  |
| 308 | `edittext_scrollh` | 10 | 4.5s |  |
| 309 | `edittext_selected_text` | 9 | 4.4s |  |
| 310 | `edittext_set_html_same` | 17 | 4.4s |  |
| 311 | `edittext_set_text_vs_html` | 9 | 4.5s |  |
| 312 | `edittext_stylesheet` | 536 | 4.7s |  |
| 313 | `edittext_stylesheet_custom_tag` | 76 | 4.5s |  |
| 314 | `edittext_stylesheet_display` | 272 | 5.0s |  |
| 315 | `edittext_underline` | 40 | 4.6s |  |
| 316 | `edittext_width_height` | 103 | 6.4s |  |
| 317 | `edittext_wordwrap_word` | 150 | 25.7s |  |
| 318 | `edittext_wrap_breaks` | 2375 | 6.4s |  |
| 319 | `empty_bounds` | 1 | 5.6s |  |
| 320 | `encode_uri_surrogate_pair_swf11` | 15 | 5.2s |  |
| 321 | `equals` | 512 | 9.7s |  |
| 322 | `error_geterrormessage` | 779 | 5.6s |  |
| 323 | `error_prototype` | 15 | 5.6s |  |
| 324 | `error_stack_trace_debug_swf17` | 0 | 25.0s |  |
| 325 | `error_stack_trace_debug_swf18` | 0 | 5.4s |  |
| 326 | `error_stack_trace_release_swf17` | 0 | 5.5s |  |
| 327 | `error_stack_trace_release_swf18` | 0 | 5.4s |  |
| 328 | `error_tostring` | 29 | 5.7s |  |
| 329 | `es3_inheritance` | 31 | 5.7s |  |
| 330 | `es4_inheritance` | 30 | 5.6s |  |
| 331 | `es4_interfaces` | 30 | 5.7s |  |
| 332 | `es4_method_binding` | 8 | 5.6s |  |
| 333 | `es4_oop_prototypes` | 14 | 5.8s |  |
| 334 | `es4_protected_inheritance` | 6 | 5.6s |  |
| 335 | `escape` | 71 | 5.7s |  |
| 336 | `event_bubbles` | 2 | 5.5s |  |
| 337 | `event_cancelable` | 2 | 5.5s |  |
| 338 | `event_clone` | 20 | 5.6s |  |
| 339 | `event_clone_error_redispatch` | 3 | 5.7s |  |
| 340 | `event_clone_on_redispatch` | 10 | 5.7s |  |
| 341 | `event_formattostring` | 31 | 5.6s |  |
| 342 | `event_isdefaultprevented` | 12 | 5.6s |  |
| 343 | `event_target_getter` | 5 | 2.3s |  |
| 344 | `event_target_set` | 9 | 5.5s |  |
| 345 | `event_type` | 1 | 6.0s |  |
| 346 | `event_valueof_tostring` | 18 | 5.6s |  |
| 347 | `eventdispatcher_dispatchevent` | 12 | 5.5s |  |
| 348 | `eventdispatcher_dispatchevent_cancel` | 20 | 24.3s |  |
| 349 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.4s |  |
| 350 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.5s |  |
| 351 | `eventdispatcher_dispatchevent_this` | 5 | 5.4s |  |
| 352 | `eventdispatcher_haseventlistener` | 25 | 5.6s |  |
| 353 | `eventdispatcher_interface_invoke` | 1 | 5.4s |  |
| 354 | `eventdispatcher_tostring` | 10 | 5.5s |  |
| 355 | `eventdispatcher_willtrigger` | 25 | 5.3s |  |
| 356 | `falsiness` | 30 | 5.4s |  |
| 357 | `fast_index_access` | 12 | 5.6s |  |
| 358 | `filefilter_properties` | 4 | 5.5s |  |
| 359 | `filereference_browse_cancel` | 3 | 5.5s |  |
| 360 | `filereference_browse_select` | 9 | 5.6s |  |
| 361 | `filereference_load` | 31 | 5.5s |  |
| 362 | `filereference_save` | 16 | 5.5s |  |
| 363 | `filereference_save_and_browse` | 42 | 5.5s |  |
| 364 | `filereference_save_and_load` | 22 | 5.5s |  |
| 365 | `filereference_uninitialized` | 8 | 5.4s |  |
| 366 | `filereferencelist_browse_cancel` | 6 | 5.4s |  |
| 367 | `filereferencelist_browse_select` | 7 | 5.5s |  |
| 368 | `finddef` | 3 | 5.4s |  |
| 369 | `findprop_global_prototype` | 6 | 5.4s |  |
| 370 | `flash_xml` | 29 | 5.5s |  |
| 371 | `flash_xml_cloneNode` | 22 | 5.5s |  |
| 372 | `flash_xml_namespace` | 109 | 5.4s |  |
| 373 | `flash_xml_removeNode` | 60 | 5.5s |  |
| 374 | `focus_events_code` | 161 | 24.2s |  |
| 375 | `focus_events_key_basic` | 132 | 24.5s |  |
| 376 | `focus_events_key_navigation` | 53 | 5.6s |  |
| 377 | `focus_events_key_same_object` | 26 | 5.5s |  |
| 378 | `focus_events_mixed_key_mouse` | 100 | 24.4s |  |
| 379 | `focus_events_mouse_basic` | 260 | 24.8s |  |
| 380 | `focus_events_mouse_focusable` | 112 | 24.2s |  |
| 381 | `focus_events_mouse_same_object` | 40 | 23.9s |  |
| 382 | `focus_remove` | 20 | 23.8s |  |
| 383 | `focus_root_movie` | 4 | 23.8s |  |
| 384 | `focus_stage` | 1 | 5.4s |  |
| 385 | `focusrect` | 18 | 6.1s |  |
| 386 | `focusrect_focuslost` | 9 | 5.5s |  |
| 387 | `focusrect_property` | 110 | 23.8s |  |
| 388 | `font_description_clone` | 14 | 5.4s |  |
| 389 | `font_embedded` | 24 | 24.0s |  |
| 390 | `font_enumeratefonts` | 41 | 6.0s |  |
| 391 | `font_enumeratefonts_filter` | 4 | 24.2s |  |
| 392 | `font_hasglyphs` | 40 | 5.8s |  |
| 393 | `framelabel_constr` | 5 | 5.3s |  |
| 394 | `function_call` | 12 | 5.4s |  |
| 395 | `function_call_arguments` | 46 | 5.4s |  |
| 396 | `function_call_arguments_enumerate` | 5 | 5.4s |  |
| 397 | `function_call_coercion` | 108 | 5.8s |  |
| 398 | `function_call_default` | 6 | 5.3s |  |
| 399 | `function_call_rest` | 22 | 5.3s |  |
| 400 | `function_call_types` | 3 | 5.3s |  |
| 401 | `function_call_via_apply` | 11 | 5.3s |  |
| 402 | `function_call_via_call` | 3 | 5.3s |  |
| 403 | `function_display_anonymous` | 7 | 2.1s |  |
| 404 | `function_length` | 6 | 5.4s |  |
| 405 | `function_object` | 2 | 5.3s |  |
| 406 | `function_proto` | 5 | 5.3s |  |
| 407 | `function_proto_created` | 61 | 5.4s |  |
| 408 | `function_to_locale_string` | 4 | 5.3s |  |
| 409 | `function_to_string` | 4 | 5.3s |  |
| 410 | `function_type` | 6 | 5.3s |  |
| 411 | `function_unbound_this` | 51 | 5.6s |  |
| 412 | `function_value_of` | 4 | 5.4s |  |
| 413 | `get_definition_by_name` | 11 | 5.4s |  |
| 414 | `get_qualified_class_name` | 20 | 6.0s |  |
| 415 | `get_qualified_super_class_name` | 18 | 5.4s |  |
| 416 | `get_slot_edge_cases` | 1 | 23.5s |  |
| 417 | `get_timer` | 2 | 5.3s |  |
| 418 | `getglobalslot` | 1 | 5.3s |  |
| 419 | `getouterscope` | 8 | 5.3s |  |
| 420 | `getter_different_namespace_setter` | 2 | 5.2s |  |
| 421 | `goto_button_nested_framescript` | 28 | 24.3s |  |
| 422 | `goto_in_constructframe` | 12 | 24.2s |  |
| 423 | `goto_in_scene_last_frame` | 2 | 23.8s |  |
| 424 | `goto_methods` | 56 | 5.6s |  |
| 425 | `goto_methods_swfver10` | 8 | 5.4s |  |
| 426 | `goto_nested_construct_sibling` | 18 | 5.7s |  |
| 427 | `goto_nested_framescript` | 9 | 5.6s |  |
| 428 | `goto_on_orphan` | 15 | 5.6s |  |
| 429 | `graphics_bad_direct_commands` | 5 | 5.9s |  |
| 430 | `graphics_bitmap_fill` | 0 | 25.7s |  |
| 431 | `graphics_bitmaps` | 0 | 5.7s |  |
| 432 | `graphics_direct_commands` | 0 | 5.6s |  |
| 433 | `graphics_draw_triangles` | 98 | 24.6s |  |
| 434 | `graphics_gradients` | 0 | 5.5s |  |
| 435 | `graphics_gradients_nulls` | 0 | 5.4s |  |
| 436 | `graphics_path` | 56 | 5.5s |  |
| 437 | `graphics_round_rects` | 0 | 5.5s |  |
| 438 | `graphics_simple_shapes` | 0 | 5.5s |  |
| 439 | `greaterequals` | 512 | 9.6s |  |
| 440 | `greaterthan` | 512 | 9.7s |  |
| 441 | `has_own_property` | 102 | 6.0s |  |
| 442 | `hasownproperty_namespaces` | 2 | 5.4s |  |
| 443 | `hello_world` | 1 | 5.3s |  |
| 444 | `hittest_morph` | 30 | 5.5s |  |
| 445 | `if_eq` | 10 | 5.5s |  |
| 446 | `if_gt` | 1 | 5.5s |  |
| 447 | `if_gte` | 10 | 5.8s |  |
| 448 | `if_lt` | 1 | 5.3s |  |
| 449 | `if_lte` | 10 | 5.2s |  |
| 450 | `if_ne` | 7 | 2.1s |  |
| 451 | `if_stricteq` | 6 | 5.3s |  |
| 452 | `if_strictne` | 11 | 5.3s |  |
| 453 | `ime_linux_dead_keys` | 10 | 23.5s |  |
| 454 | `in` | 102 | 5.8s |  |
| 455 | `inclocal` | 46 | 5.4s |  |
| 456 | `inclocal_i` | 46 | 5.4s |  |
| 457 | `increment` | 46 | 5.4s |  |
| 458 | `increment_i` | 46 | 5.5s |  |
| 459 | `indexing_delete` | 75 | 5.4s |  |
| 460 | `instanceof` | 58 | 5.7s |  |
| 461 | `instantiation_on_enter_frame` | 7 | 23.4s |  |
| 462 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.3s |  |
| 463 | `int_constr` | 92 | 5.2s |  |
| 464 | `int_edge_cases` | 19 | 5.3s |  |
| 465 | `int_instanceof` | 3 | 5.2s |  |
| 466 | `int_tofixed` | 1215 | 5.2s |  |
| 467 | `int_tostring` | 3375 | 5.4s |  |
| 468 | `interactiveobject_enabled` | 25 | 5.4s |  |
| 469 | `interface_namespaces` | 78 | 5.5s |  |
| 470 | `is_finite` | 46 | 5.5s |  |
| 471 | `is_nan` | 46 | 5.3s |  |
| 472 | `is_prototype_of` | 12 | 5.4s |  |
| 473 | `issue_10221` | 2 | 5.3s |  |
| 474 | `issue_13780` | 12 | 5.4s |  |
| 475 | `issue_14901` | 1 | 5.3s |  |
| 476 | `issue_17675_edittext_paste_maxchars` | 1 | 5.3s |  |
| 477 | `issue_5292` | 5 | 5.3s |  |
| 478 | `issue_8630` | 2 | 23.3s |  |
| 479 | `issue_8630_scriptremove` | 11 | 5.3s |  |
| 480 | `istype` | 24 | 2.1s |  |
| 481 | `istypelate` | 58 | 5.6s |  |
| 482 | `istypelate_coerce` | 198 | 7.0s |  |
| 483 | `jpeg_loader_context` | 6 | 24.2s |  |
| 484 | `json_errors` | 9 | 24.8s |  |
| 485 | `json_parse` | 21 | 5.8s |  |
| 486 | `json_stringify` | 12 | 6.0s |  |
| 487 | `json_stringify_order` | 1 | 5.5s |  |
| 488 | `json_version_gated` | 1 | 5.4s |  |
| 489 | `key_input_80percent` | 1812 | 5.7s |  |
| 490 | `key_input_location` | 126 | 5.5s |  |
| 491 | `key_input_numpad` | 384 | 5.3s |  |
| 492 | `lazyinit` | 17 | 5.4s |  |
| 493 | `lessequals` | 512 | 10.0s |  |
| 494 | `lessthan` | 512 | 10.1s |  |
| 495 | `loader_bitmap_transparency` | 14 | 5.6s |  |
| 496 | `loader_bytes_unknown_content` | 14 | 5.5s |  |
| 497 | `loader_child_getdefinition` | 5 | 5.7s |  |
| 498 | `loader_duplicate_coerce` | 3 | 6.0s |  |
| 499 | `loader_duplicate_coerce_new_domain` | 4 | 5.8s |  |
| 500 | `loader_error_in_root_ctor` | 4 | 5.7s |  |
| 501 | `loader_events` | 92 | 5.9s |  |
| 502 | `loader_image` | 8 | 5.5s |  |
| 503 | `loader_jpegxr` | 2 | 25.8s |  |
| 504 | `loader_jpegxr_alpha` | 1 | 24.4s |  |
| 505 | `loader_loadbytes_events` | 30 | 5.9s |  |
| 506 | `loader_loadbytes_invalid_png` | 4 | 24.6s |  |
| 507 | `loader_loadbytes_url` | 12 | 6.0s |  |
| 508 | `loader_loaderurl` | 6 | 6.0s |  |
| 509 | `loader_noninteractive_try_click_root` | 5 | 24.3s |  |
| 510 | `loader_reuse` | 38 | 5.7s |  |
| 511 | `loader_unknown_content` | 24 | 5.6s |  |
| 512 | `loader_visibility_interactive` | 1 | 5.6s |  |
| 513 | `loaderinfo_events` | 7 | 5.7s |  |
| 514 | `loaderinfo_loadurl` | 12 | 21.3s |  |
| 515 | `loaderinfo_more` | 6 | 21.1s |  |
| 516 | `loaderinfo_properties` | 18 | 4.5s |  |
| 517 | `loaderinfo_properties_not_loaded` | 23 | 4.7s |  |
| 518 | `loaderinfo_root` | 10 | 4.5s |  |
| 519 | `loaderinfo_root_allows` | 2 | 4.5s |  |
| 520 | `lshift` | 1058 | 13.0s |  |
| 521 | `mask_reapply` | 1 | 4.7s |  |
| 522 | `math` | 497 | 4.7s |  |
| 523 | `missing_external_interface` | 10 | 4.7s |  |
| 524 | `modulo` | 1058 | 13.4s |  |
| 525 | `morph_shape` | 2 | 21.5s |  |
| 526 | `mouse_children` | 192 | 21.2s |  |
| 527 | `mouse_click_events` | 90 | 21.1s |  |
| 528 | `mouse_double_click_events` | 188 | 4.5s |  |
| 529 | `mouse_empty_parent` | 4 | 4.5s |  |
| 530 | `mouse_over_while_dragging` | 3 | 4.5s |  |
| 531 | `mouse_pick_button_mode` | 2 | 4.6s |  |
| 532 | `mouse_pick_dobj_mask` | 4 | 4.6s |  |
| 533 | `mouse_pick_masking` | 7 | 21.1s |  |
| 534 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 20.9s |  |
| 535 | `mouse_pick_non_interactive_dobj_mask` | 3 | 4.5s |  |
| 536 | `mouse_pick_text` | 8 | 4.6s |  |
| 537 | `mouse_sibling` | 8 | 4.5s |  |
| 538 | `mouse_wheel_events` | 36 | 21.4s |  |
| 539 | `mouseevent_constr` | 66 | 4.6s |  |
| 540 | `mouseevent_stagexy` | 35 | 4.6s |  |
| 541 | `mouseevent_valueof_tostring` | 28 | 4.5s |  |
| 542 | `movieclip_addframescript` | 3 | 21.0s |  |
| 543 | `movieclip_child_property` | 16 | 4.6s |  |
| 544 | `movieclip_constr` | 21 | 5.5s |  |
| 545 | `movieclip_currentlabels` | 17 | 23.3s |  |
| 546 | `movieclip_currentlabels_dupes1` | 46 | 23.5s |  |
| 547 | `movieclip_currentlabels_dupes2` | 30 | 5.0s |  |
| 548 | `movieclip_currentlabels_dupes3` | 67 | 5.0s |  |
| 549 | `movieclip_currentscene` | 12 | 23.2s |  |
| 550 | `movieclip_dispatchevent` | 430 | 5.2s |  |
| 551 | `movieclip_dispatchevent_cancel` | 102 | 5.2s |  |
| 552 | `movieclip_dispatchevent_handlerorder` | 251 | 5.1s |  |
| 553 | `movieclip_dispatchevent_selfadd` | 80 | 5.1s |  |
| 554 | `movieclip_dispatchevent_target` | 899 | 5.0s |  |
| 555 | `movieclip_displayevents` | 96 | 23.2s |  |
| 556 | `movieclip_displayevents_clickgoto` | 676 | 23.8s |  |
| 557 | `movieclip_displayevents_clickgoto2` | 2001 | 5.4s |  |
| 558 | `movieclip_displayevents_clickplay` | 575 | 5.2s |  |
| 559 | `movieclip_displayevents_clicksymbol` | 562 | 5.2s |  |
| 560 | `movieclip_displayevents_constructframegoto` | 140 | 5.4s |  |
| 561 | `movieclip_displayevents_constructframeplay` | 50 | 5.3s |  |
| 562 | `movieclip_displayevents_constructframesymbol` | 144 | 5.2s |  |
| 563 | `movieclip_displayevents_dblhandler` | 21 | 5.2s |  |
| 564 | `movieclip_displayevents_enterframegoto` | 149 | 5.3s |  |
| 565 | `movieclip_displayevents_enterframeplay` | 48 | 5.1s |  |
| 566 | `movieclip_displayevents_enterframesymbol` | 149 | 23.5s |  |
| 567 | `movieclip_displayevents_exitframegoto` | 106 | 5.1s |  |
| 568 | `movieclip_displayevents_exitframeplay` | 44 | 5.2s |  |
| 569 | `movieclip_displayevents_exitframesymbol` | 135 | 5.2s |  |
| 570 | `movieclip_displayevents_looping` | 63 | 23.4s |  |
| 571 | `movieclip_displayevents_stopped` | 113 | 5.4s |  |
| 572 | `movieclip_displayevents_swap` | 96 | 1.7s |  |
| 573 | `movieclip_displayevents_timeline` | 128 | 23.6s |  |
| 574 | `movieclip_drawrect` | 54 | 5.0s |  |
| 575 | `movieclip_frameconstruct_skipped` | 9 | 5.0s |  |
| 576 | `movieclip_goto_during_frame_script` | 15 | 5.1s |  |
| 577 | `movieclip_goto_overwrite` | 14 | 22.7s |  |
| 578 | `movieclip_goto_scene_last_frame_int` | 1 | 23.0s |  |
| 579 | `movieclip_goto_scene_last_frame_label` | 1 | 4.9s |  |
| 580 | `movieclip_gotoandplay` | 15 | 22.8s |  |
| 581 | `movieclip_gotoandstop` | 13 | 5.0s |  |
| 582 | `movieclip_gotoandstop_children` | 4 | 5.0s |  |
| 583 | `movieclip_gotoandstop_framescripts1` | 4 | 5.0s |  |
| 584 | `movieclip_gotoandstop_framescripts2` | 4 | 1.8s |  |
| 585 | `movieclip_gotoandstop_framescripts_self` | 7 | 24.9s |  |
| 586 | `movieclip_gotoandstop_queueing` | 12 | 24.4s |  |
| 587 | `movieclip_next_frame` | 2 | 24.6s |  |
| 588 | `movieclip_next_scene` | 6 | 24.5s |  |
| 589 | `movieclip_play` | 3 | 5.5s |  |
| 590 | `movieclip_prev_frame` | 3 | 5.4s |  |
| 591 | `movieclip_prev_scene` | 7 | 5.7s |  |
| 592 | `movieclip_properties` | 79 | 24.8s |  |
| 593 | `movieclip_queued_noop_goto_swf10` | 9 | 5.6s |  |
| 594 | `movieclip_queued_noop_goto_swf9` | 7 | 0.6s |  |
| 595 | `movieclip_scenes` | 11 | 5.5s |  |
| 596 | `movieclip_soundtransform` | 831 | 26.5s |  |
| 597 | `movieclip_stop` | 1 | 24.3s |  |
| 598 | `movieclip_super_is_symbol` | 20 | 6.0s |  |
| 599 | `movieclip_symbol_constr` | 8 | 5.8s |  |
| 600 | `movieclip_text_mousedown` | 1 | 5.7s |  |
| 601 | `movieclip_willtrigger` | 5 | 5.7s |  |
| 602 | `multiply` | 1058 | 17.1s |  |
| 603 | `namespace_constr` | 253 | 5.9s |  |
| 604 | `namespace_constr_args` | 1 | 5.5s |  |
| 605 | `namespace_enumeration_order` | 7 | 24.5s |  |
| 606 | `nan_scale` | 9 | 5.5s |  |
| 607 | `navigateToURL_target_normalize` | 107 | 25.3s |  |
| 608 | `negate` | 30 | 5.6s |  |
| 609 | `negative_volume_panned` | 0 | 5.8s |  |
| 610 | `nested_iteration` | 11 | 5.6s |  |
| 611 | `net_getClassByAlias` | 3 | 5.6s |  |
| 612 | `net_navigateToURL` | 57 | 5.6s |  |
| 613 | `net_stream_play_options` | 6 | 5.6s |  |
| 614 | `netconnection_close` | 55 | 5.6s |  |
| 615 | `netconnection_properties` | 78 | 5.7s |  |
| 616 | `netstream_client` | 10 | 5.7s |  |
| 617 | `netstream_connect` | 7 | 5.5s |  |
| 618 | `newactivation_in_script_init` | 3 | 4.5s |  |
| 619 | `newclass_twice` | 3 | 4.4s |  |
| 620 | `nonconflicting_declarations` | 0 | 4.4s |  |
| 621 | `null_void_types` | 8 | 4.5s |  |
| 622 | `number_autoconv` | 21 | 20.7s |  |
| 623 | `number_autoconv_amf` | 132 | 4.5s |  |
| 624 | `number_autoconv_array_sort_32bit` | 1 | 4.5s |  |
| 625 | `number_constr` | 58 | 4.5s |  |
| 626 | `number_toexponential` | 378 | 4.5s |  |
| 627 | `number_toexponential2` | 35 | 4.9s |  |
| 628 | `number_tofixed` | 378 | 4.4s |  |
| 629 | `number_toprecision` | 350 | 4.6s |  |
| 630 | `obfuscated_class_names` | 3 | 4.8s |  |
| 631 | `object_enumeration` | 10 | 4.6s |  |
| 632 | `object_prototype` | 4 | 4.5s |  |
| 633 | `object_to_locale_string` | 2 | 4.9s |  |
| 634 | `object_to_string` | 2 | 4.4s |  |
| 635 | `object_value_of` | 2 | 1.4s |  |
| 636 | `op_coerce` | 54 | 4.5s |  |
| 637 | `op_coerce_x` | 54 | 4.5s |  |
| 638 | `op_escxattr` | 2 | 4.4s |  |
| 639 | `op_escxelem` | 2 | 4.5s |  |
| 640 | `op_lookupswitch` | 4 | 4.4s |  |
| 641 | `optimize_coerce` | 1 | 4.3s |  |
| 642 | `orphan_movie_complex` | 80 | 4.7s |  |
| 643 | `orphan_movie_reorder` | 111 | 20.7s |  |
| 644 | `package_namespace` | 7 | 4.2s |  |
| 645 | `param_default_value_has_zero_cpool_index` | 1 | 4.4s |  |
| 646 | `parent_early_access_child` | 16 | 20.6s |  |
| 647 | `parse_float` | 81 | 4.6s |  |
| 648 | `pixelbender_effect_BlurredFocus` | 0 | 26.9s |  |
| 649 | `pixelbender_effect_glassDisplace` | 0 | 10.6s |  |
| 650 | `pixelbender_effect_smudge` | 0 | 8.2s |  |
| 651 | `pixelbender_effect_tintype` | 0 | 7.2s |  |
| 652 | `pixelbender_effect_twirl` | 0 | 8.3s |  |
| 653 | `pixelbender_images` | 0 | 6.8s |  |
| 654 | `place_multiple` | 17 | 21.7s |  |
| 655 | `place_object_replace` | 9 | 5.0s |  |
| 656 | `place_object_replace_2` | 24 | 4.9s |  |
| 657 | `place_object_same_depth_frame` | 1 | 5.1s |  |
| 658 | `point` | 132 | 5.1s |  |
| 659 | `primitive_edge_cases` | 1 | 5.2s |  |
| 660 | `property_priority` | 22 | 4.6s |  |
| 661 | `property_priority_three_level` | 6 | 19.7s |  |
| 662 | `propertyisenumerable_namespaces` | 6 | 4.2s |  |
| 663 | `prototype_set_null` | 7 | 4.2s |  |
| 664 | `proxy_callproperty` | 24 | 4.3s |  |
| 665 | `proxy_deleteproperty` | 64 | 4.3s |  |
| 666 | `proxy_enumeration` | 34 | 4.3s |  |
| 667 | `proxy_getproperty` | 77 | 4.3s |  |
| 668 | `proxy_hasownproperty` | 8 | 4.3s |  |
| 669 | `proxy_hasproperty` | 32 | 4.4s |  |
| 670 | `proxy_serialize` | 9 | 4.3s |  |
| 671 | `proxy_setproperty` | 42 | 4.3s |  |
| 672 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.3s |  |
| 673 | `qname_constr` | 32 | 4.3s |  |
| 674 | `qname_constr_namespace` | 24 | 4.3s |  |
| 675 | `qname_enumeration` | 9 | 4.3s |  |
| 676 | `qname_indexing` | 23 | 4.3s |  |
| 677 | `qname_tostring` | 25 | 4.3s |  |
| 678 | `qname_valueof` | 29 | 4.4s |  |
| 679 | `regexp_constr` | 148 | 4.5s |  |
| 680 | `regexp_exec` | 19 | 4.3s |  |
| 681 | `regexp_extended` | 47 | 4.2s |  |
| 682 | `regexp_multiargs` | 1 | 4.2s |  |
| 683 | `regexp_test` | 27 | 4.3s |  |
| 684 | `regexp_toString` | 10 | 4.3s |  |
| 685 | `register_script_refresh` | 35 | 4.6s |  |
| 686 | `remove_child_clear_field` | 88 | 20.1s |  |
| 687 | `remove_dobj` | 3 | 4.2s |  |
| 688 | `resolve_order` | 4 | 4.3s |  |
| 689 | `responder_null_callbacks` | 1 | 4.4s |  |
| 690 | `rng` | 1 | 5.2s |  |
| 691 | `rootless` | 42 | 4.7s |  |
| 692 | `rshift` | 1058 | 12.2s |  |
| 693 | `sandbox_type_inherited` | 2 | 6.4s |  |
| 694 | `sandbox_type_local_file` | 1 | 24.3s |  |
| 695 | `sandbox_type_local_network` | 1 | 5.2s |  |
| 696 | `scene_constr` | 8 | 5.5s |  |
| 697 | `selection` | 239 | 5.9s |  |
| 698 | `set_local_0` | 31 | 5.5s |  |
| 699 | `set_property_is_enumerable` | 85 | 5.8s |  |
| 700 | `shape_drawrect` | 54 | 5.5s |  |
| 701 | `shared_object_no_root` | 3 | 5.3s |  |
| 702 | `simplebutton_added_to_stage` | 45 | 23.8s |  |
| 703 | `simplebutton_childevents` | 86 | 24.1s |  |
| 704 | `simplebutton_childevents_nested` | 54 | 5.8s |  |
| 705 | `simplebutton_childevents_sprite` | 13 | 5.5s |  |
| 706 | `simplebutton_childprops` | 144 | 5.7s |  |
| 707 | `simplebutton_childshuffle` | 23 | 5.4s |  |
| 708 | `simplebutton_constr` | 36 | 5.7s |  |
| 709 | `simplebutton_constr_childevents` | 48 | 5.7s |  |
| 710 | `simplebutton_constr_params` | 42 | 5.6s |  |
| 711 | `simplebutton_mouseenabled` | 26 | 5.5s |  |
| 712 | `simplebutton_multi_children` | 19 | 5.7s |  |
| 713 | `simplebutton_structure` | 27 | 5.7s |  |
| 714 | `simplebutton_symbolclass` | 68 | 5.7s |  |
| 715 | `slot_disp_id_shared_numbering` | 1 | 23.8s |  |
| 716 | `slots_force_autoassigned` | 1 | 5.5s |  |
| 717 | `socket_after_disconnect` | 1 | 5.6s |  |
| 718 | `socket_close` | 2 | 5.4s |  |
| 719 | `socket_connect` | 4 | 5.6s |  |
| 720 | `socket_errors` | 56 | 6.0s |  |
| 721 | `socket_read_big` | 48 | 25.5s |  |
| 722 | `socket_read_little` | 48 | 2.2s |  |
| 723 | `socket_read_write_object` | 8 | 5.6s |  |
| 724 | `socket_write_big` | 15 | 6.0s |  |
| 725 | `socket_write_little` | 14 | 5.7s |  |
| 726 | `sound_embeddedprops` | 26 | 5.8s |  |
| 727 | `sound_play` | 19 | 5.9s |  |
| 728 | `sound_valueof` | 33 | 5.8s |  |
| 729 | `soundchannel_soundtransform` | 835 | 26.8s |  |
| 730 | `soundchannel_soundtransform_exists` | 5 | 24.9s |  |
| 731 | `soundchannel_stop` | 8 | 25.0s |  |
| 732 | `soundmixer_buffertime` | 5 | 5.6s |  |
| 733 | `soundmixer_stopall` | 6 | 25.4s |  |
| 734 | `soundtransform` | 442 | 11.1s |  |
| 735 | `sprite_with_frames` | 0 | 25.1s |  |
| 736 | `stage3d_agal_cross_product` | 0 | 8.2s |  |
| 737 | `stage3d_bitmap` | 0 | 30.4s |  |
| 738 | `stage3d_float1_index` | 0 | 27.4s |  |
| 739 | `stage3d_fractal` | 0 | 27.0s |  |
| 740 | `stage3d_ignore_sampler_override` | 0 | 27.1s |  |
| 741 | `stage3d_program_constants_bytearray_be` | 0 | 28.3s |  |
| 742 | `stage3d_program_constants_bytearray_le` | 0 | 8.7s |  |
| 743 | `stage3d_raytrace` | 0 | 30.3s |  |
| 744 | `stage3d_rotating_cube` | 0 | 8.8s |  |
| 745 | `stage3d_sampler` | 0 | 6.9s |  |
| 746 | `stage3d_sampler_partial_upload` | 0 | 6.6s |  |
| 747 | `stage3d_stencil` | 0 | 21.9s |  |
| 748 | `stage3d_texture` | 0 | 10.2s |  |
| 749 | `stage3d_texture_bytearray` | 0 | 7.4s |  |
| 750 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 6.8s |  |
| 751 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 7.7s |  |
| 752 | `stage3d_triangle` | 0 | 6.7s |  |
| 753 | `stage3d_triangle_bytes4` | 0 | 6.7s |  |
| 754 | `stage3d_triangle_float1` | 0 | 6.3s |  |
| 755 | `stage3d_triangle_index_upload` | 0 | 6.3s |  |
| 756 | `stage_access` | 10 | 4.4s |  |
| 757 | `stage_displayobject_properties` | 24 | 4.3s |  |
| 758 | `stage_framerate_nan` | 7 | 20.1s |  |
| 759 | `stage_framerate_negative` | 6 | 4.6s |  |
| 760 | `stage_framerate_zero` | 6 | 4.6s |  |
| 761 | `stage_invalidate` | 38 | 4.7s |  |
| 762 | `stage_loaderinfo_properties` | 24 | 19.9s |  |
| 763 | `stage_mousechildren` | 2 | 4.5s |  |
| 764 | `stage_mouseenabled` | 15 | 4.4s |  |
| 765 | `stage_overriden_setters` | 31 | 4.5s |  |
| 766 | `stage_properties` | 30 | 4.3s |  |
| 767 | `static_var_with_this_in_ctor` | 2 | 4.3s |  |
| 768 | `stored_properties` | 11 | 4.4s |  |
| 769 | `strict_equality` | 34 | 4.4s |  |
| 770 | `string_call` | 13 | 4.3s |  |
| 771 | `string_case` | 23 | 4.5s |  |
| 772 | `string_char_at` | 27 | 4.4s |  |
| 773 | `string_char_code_at` | 28 | 4.3s |  |
| 774 | `string_concat_fromcharcode` | 37 | 4.3s |  |
| 775 | `string_constr` | 25 | 4.5s |  |
| 776 | `string_indexof_lastindexof` | 87 | 24.5s |  |
| 777 | `string_length` | 16 | 23.8s |  |
| 778 | `string_locale_compare` | 39 | 5.4s |  |
| 779 | `string_match` | 51 | 5.4s |  |
| 780 | `string_relational_compare` | 4 | 24.0s |  |
| 781 | `string_replace` | 51 | 5.4s |  |
| 782 | `string_search` | 41 | 5.4s |  |
| 783 | `string_slice_substr_substring` | 170 | 6.2s |  |
| 784 | `string_split` | 29 | 5.3s |  |
| 785 | `string_substr_negative` | 21 | 5.2s |  |
| 786 | `string_substr_weird` | 182 | 5.1s |  |
| 787 | `subtract` | 1058 | 14.7s |  |
| 788 | `super_get_call` | 12 | 5.2s |  |
| 789 | `supercall_two_classobjects` | 2 | 5.2s |  |
| 790 | `swf8` | 1 | 5.2s |  |
| 791 | `swf_10_queued_goto_scripts_construct` | 52 | 24.6s |  |
| 792 | `swf_9_goto_in_enter_frame` | 17 | 5.4s |  |
| 793 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.4s |  |
| 794 | `swf_9_queued_goto_scripts` | 6 | 24.4s |  |
| 795 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 796 | `swf_9_versioning` | 2 | 5.2s |  |
| 797 | `swf_wrong_frame_count` | 38 | 5.5s |  |
| 798 | `swf_wrong_frame_count_isplaying` | 22 | 5.2s |  |
| 799 | `symbol_class_binary_data` | 8 | 5.3s |  |
| 800 | `symbol_class_conflict` | 4 | 5.4s |  |
| 801 | `symbol_class_root_not_zero` | 1 | 5.1s |  |
| 802 | `symbolclass_invalid_utf8` | 2 | 5.2s |  |
| 803 | `tab_ordering_automatic_advanced` | 184 | 6.0s |  |
| 804 | `tab_ordering_automatic_basic` | 45 | 23.7s |  |
| 805 | `tab_ordering_children` | 116 | 5.5s |  |
| 806 | `tab_ordering_custom_basic` | 34 | 5.4s |  |
| 807 | `tab_ordering_stage_tab_children` | 32 | 5.4s |  |
| 808 | `tab_ordering_stage_tab_children_remove_root` | 5 | 5.3s |  |
| 809 | `tab_ordering_tabbable` | 47 | 5.5s |  |
| 810 | `text_engine_fontdescription` | 27 | 5.5s |  |
| 811 | `text_run` | 7 | 5.3s |  |
| 812 | `textbox_click` | 37 | 23.7s |  |
| 813 | `textfield_event` | 66 | 5.6s |  |
| 814 | `textfield_focusin_event` | 9 | 5.4s |  |
| 815 | `textfield_input_dead_keys_windows` | 15 | 5.4s |  |
| 816 | `textfield_unload` | 39 | 23.8s |  |
| 817 | `textformat` | 1134 | 5.4s |  |
| 818 | `textformat_display` | 14 | 5.4s |  |
| 819 | `textformat_font_max_length` | 4 | 5.3s |  |
| 820 | `throw` | 3 | 5.4s |  |
| 821 | `timeline_scripts` | 3 | 5.4s |  |
| 822 | `timer` | 90 | 6.0s |  |
| 823 | `timer_events` | 3 | 5.5s |  |
| 824 | `timer_finished` | 11 | 5.5s |  |
| 825 | `timer_reset` | 8 | 5.5s |  |
| 826 | `timer_setdelay` | 5 | 5.4s |  |
| 827 | `trace` | 12 | 5.3s |  |
| 828 | `truthiness` | 30 | 4.5s |  |
| 829 | `try_catch` | 11 | 4.0s |  |
| 830 | `try_catch_typed` | 12 | 4.0s |  |
| 831 | `typeof` | 30 | 4.0s |  |
| 832 | `uint_constr` | 92 | 4.0s |  |
| 833 | `uint_tofixed` | 1215 | 4.0s |  |
| 834 | `uint_tostring` | 3375 | 4.0s |  |
| 835 | `unchecked_function` | 15 | 4.0s |  |
| 836 | `unescape` | 28 | 4.0s |  |
| 837 | `url_loader` | 25 | 4.0s |  |
| 838 | `urlrequest` | 18 | 22.3s |  |
| 839 | `urshift` | 1058 | 4.0s |  |
| 840 | `vector_class` | 36 | 4.0s |  |
| 841 | `vector_class_call` | 11 | 4.1s |  |
| 842 | `vector_coercion` | 66 | 4.0s |  |
| 843 | `vector_concat` | 90 | 4.0s |  |
| 844 | `vector_constr` | 107 | 4.0s |  |
| 845 | `vector_enumeration` | 5 | 4.0s |  |
| 846 | `vector_every` | 92 | 4.0s |  |
| 847 | `vector_filter` | 95 | 4.0s |  |
| 848 | `vector_holes` | 24 | 4.0s |  |
| 849 | `vector_indexof` | 302 | 4.0s |  |
| 850 | `vector_insertat` | 270 | 4.0s |  |
| 851 | `vector_int_access` | 4 | 4.0s |  |
| 852 | `vector_int_delete` | 11 | 4.1s |  |
| 853 | `vector_join` | 58 | 4.0s |  |
| 854 | `vector_lastindexof` | 302 | 4.0s |  |
| 855 | `vector_legacy` | 10 | 4.1s |  |
| 856 | `vector_map` | 85 | 4.0s |  |
| 857 | `vector_object_final` | 1 | 4.0s |  |
| 858 | `vector_object_toString` | 10 | 4.1s |  |
| 859 | `vector_pushpop` | 255 | 4.0s |  |
| 860 | `vector_reborrow_bug` | 10 | 17.9s |  |
| 861 | `vector_removeat` | 172 | 4.3s |  |
| 862 | `vector_reverse` | 232 | 4.6s |  |
| 863 | `vector_shiftunshift` | 252 | 3.8s |  |
| 864 | `vector_slice` | 331 | 4.6s |  |
| 865 | `vector_sort` | 905 | 9.5s |  |
| 866 | `vector_splice` | 693 | 5.8s |  |
| 867 | `vector_splice_fixed_bug_compat` | 4 | 3.7s |  |
| 868 | `vector_tostring` | 79 | 4.3s |  |
| 869 | `verify_abnormal_loop` | 1 | 3.5s |  |
| 870 | `verify_exception_targets_edge_case` | 1 | 3.7s |  |
| 871 | `verify_lookup_switch_edge_case` | 1 | 3.7s |  |
| 872 | `verify_unreachable_exception` | 2 | 3.7s |  |
| 873 | `versioned_isplaying` | 2 | 3.8s |  |
| 874 | `virtual_properties` | 16 | 3.7s |  |
| 875 | `with` | 4 | 3.8s |  |
| 876 | `wrong_arg_count` | 7 | 3.9s |  |
| 877 | `xml_abstract_equality` | 36 | 3.9s |  |
| 878 | `xml_advanced` | 52 | 3.6s |  |
| 879 | `xml_appendchild` | 10 | 3.8s |  |
| 880 | `xml_as_attribute` | 9 | 3.7s |  |
| 881 | `xml_attribute` | 35 | 3.8s |  |
| 882 | `xml_attribute_name` | 40 | 3.7s |  |
| 883 | `xml_basic` | 33 | 3.8s |  |
| 884 | `xml_child` | 25 | 3.9s |  |
| 885 | `xml_childindex` | 7 | 4.0s |  |
| 886 | `xml_children` | 43 | 4.2s |  |
| 887 | `xml_class_call` | 9 | 3.7s |  |
| 888 | `xml_contains` | 197 | 3.8s |  |
| 889 | `xml_copy` | 20 | 19.8s |  |
| 890 | `xml_ctor_from_tostring` | 23 | 4.6s |  |
| 891 | `xml_delete` | 114 | 4.4s |  |
| 892 | `xml_descendants` | 83 | 4.4s |  |
| 893 | `xml_elements` | 6 | 4.3s |  |
| 894 | `xml_equals_namespace_check` | 2 | 4.3s |  |
| 895 | `xml_explicit_use_namespace` | 5 | 19.3s |  |
| 896 | `xml_getdescendants_qname` | 21 | 4.3s |  |
| 897 | `xml_has_property_via_in` | 26 | 4.4s |  |
| 898 | `xml_hasownproperty` | 6 | 4.3s |  |
| 899 | `xml_ignore_white` | 6 | 4.4s |  |
| 900 | `xml_length` | 2 | 4.3s |  |
| 901 | `xml_list_as_attribute` | 9 | 4.3s |  |
| 902 | `xml_list_concat` | 20 | 4.4s |  |
| 903 | `xml_list_enumerate` | 4 | 4.3s |  |
| 904 | `xml_methods_settings` | 3 | 4.3s |  |
| 905 | `xml_mismatched_tag` | 37 | 4.4s |  |
| 906 | `xml_namespace` | 39 | 4.4s |  |
| 907 | `xml_namespace_methods` | 245 | 4.4s |  |
| 908 | `xml_namespaced_property` | 7 | 4.3s |  |
| 909 | `xml_no_namespace` | 1 | 4.3s |  |
| 910 | `xml_nodekind` | 3 | 4.3s |  |
| 911 | `xml_normalize` | 35 | 4.4s |  |
| 912 | `xml_notification_bubbling` | 361 | 4.4s |  |
| 913 | `xml_parent` | 8 | 4.3s |  |
| 914 | `xml_set_children` | 17 | 4.4s |  |
| 915 | `xml_set_name` | 34 | 4.5s |  |
| 916 | `xml_settings` | 6 | 1.8s |  |
| 917 | `xml_simple_complex_content` | 47 | 4.3s |  |
| 918 | `xml_socket` | 11 | 4.5s |  |
| 919 | `xml_text` | 7 | 4.4s |  |
| 920 | `xml_tostring` | 6 | 4.3s |  |
| 921 | `xml_tostring_namespace` | 12 | 4.3s |  |
| 922 | `xml_unescaping` | 23 | 4.4s |  |
| 923 | `xml_weird_ignores` | 54 | 4.4s |  |
| 924 | `xml_wildcard` | 11 | 4.3s |  |
| 925 | `xmldocument` | 254 | 4.4s |  |
| 926 | `xmlnode` | 3540 | 4.5s |  |
| 927 | `zero_frame_clip` | 3 | 4.5s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 5.5s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 5.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**49 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 4 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 5 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 6 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 7 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 8 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 9 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 12 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 13 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 14 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 15 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 16 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 17 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 18 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 19 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 20 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 21 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 22 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 23 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 24 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 25 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 26 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 28 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 29 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 30 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 31 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 32 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 33 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 35 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 36 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 37 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 38 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 39 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 40 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 41 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 42 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 43 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 44 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 45 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 46 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 47 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 48 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 49 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 21.3s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 4.3s |  |
| 3 | `verify_typecheck` | exit code 1 | 3.9s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**236 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 4 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 5 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 6 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 7 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 8 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 9 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 12 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 13 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 14 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 15 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 16 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 17 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 18 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 19 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 20 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 21 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 22 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 23 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 24 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 25 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 26 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 28 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 29 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 30 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 31 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 32 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 33 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 35 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 37 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 38 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 39 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 40 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 41 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 42 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 43 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 44 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 45 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 46 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 47 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 48 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 49 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 50 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 51 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 52 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 53 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 54 | `amf_array_serialization` | 35.3% | 6/17 | 6 | 17 |  |
| 55 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 56 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 57 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 58 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 59 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 60 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 61 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 62 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 63 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 64 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 65 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 66 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 67 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 68 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 69 | `netconnection_serialize_arrays` | 16.7% | 1/6 | 1 | 6 |  |
| 70 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 71 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 72 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 73 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 74 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 75 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 76 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 77 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 78 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 79 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 80 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 81 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 82 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 83 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 84 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 85 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 86 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 87 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 88 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 89 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 90 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 91 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 92 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 93 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 94 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 95 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 96 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 97 | `netconnection_send_remote` | 4.0% | 2/50 | 2 | 50 |  |
| 98 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 99 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 100 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 101 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 102 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 103 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 104 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 105 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 106 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 107 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 108 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 109 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 110 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 111 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 112 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 113 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 114 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 115 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 116 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 117 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 118 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 119 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 120 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 121 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 122 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 123 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 124 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 125 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 126 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 127 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 128 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 129 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 130 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 131 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 132 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 133 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 134 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 135 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 136 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 137 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 138 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 139 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 140 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 141 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 142 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 143 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 144 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 145 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 146 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 147 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 148 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 149 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 150 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 151 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 152 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 153 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 154 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 155 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 156 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 157 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 158 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 159 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 160 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 161 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 162 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 163 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 164 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 165 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 166 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 167 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 168 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 169 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 170 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 171 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 172 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 173 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 174 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 175 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 176 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 177 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 178 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 179 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 180 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 181 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 182 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 183 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 184 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 185 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 186 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 187 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 188 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 189 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 190 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 191 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 192 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 193 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 194 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 195 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 196 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 197 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 198 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 199 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 200 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 201 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 202 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 203 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 204 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 205 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 206 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 207 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 208 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 209 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 210 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 211 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 212 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 213 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 214 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 215 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 216 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 217 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 218 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 219 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 220 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 221 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 222 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 223 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 224 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 225 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 226 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 227 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 228 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 229 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 230 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 231 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 232 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 233 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 234 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 235 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 236 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
