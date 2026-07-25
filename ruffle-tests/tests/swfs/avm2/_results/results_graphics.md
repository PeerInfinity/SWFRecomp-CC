# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-25 21:37 UTC

**Git SHA**: `2b244c01b1`

**Run Duration**: 150m 40s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1218 |
| Passing | **840** (69.0%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **866** (71.1%) |
| Failing | 352 |
| Total expected lines | 151151 |
| Matching lines | 103855 (68.7%) |
| Mismatched lines | 47296 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 347 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**840 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.2s |  |
| 2 | `agal_compiler` | 13 | 7.6s |  |
| 3 | `air_hidden_lookup` | 2 | 4.9s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.9s |  |
| 5 | `amf_custom_obj` | 26 | 4.9s |  |
| 6 | `amf_dictionary` | 9 | 4.8s |  |
| 7 | `amf_function` | 46 | 4.9s |  |
| 8 | `amf_invalid_date` | 2 | 4.8s |  |
| 9 | `amf_missing_prop` | 6 | 4.9s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 5.5s |  |
| 11 | `amf_setter_error` | 8 | 5.6s |  |
| 12 | `amf_vector` | 40 | 5.6s |  |
| 13 | `amf_xml` | 6 | 5.5s |  |
| 14 | `application_domain` | 4 | 5.5s |  |
| 15 | `array_access` | 18 | 5.5s |  |
| 16 | `array_access_interpreter` | 4 | 5.4s |  |
| 17 | `array_access_no_pubns` | 2 | 5.4s |  |
| 18 | `array_concat` | 41 | 5.5s |  |
| 19 | `array_constr` | 10 | 5.3s |  |
| 20 | `array_delete` | 44 | 5.5s |  |
| 21 | `array_enumeration` | 10 | 5.4s |  |
| 22 | `array_enumeration_elements` | 11 | 5.5s |  |
| 23 | `array_every` | 8 | 5.4s |  |
| 24 | `array_filter` | 6 | 5.4s |  |
| 25 | `array_foreach` | 18 | 5.4s |  |
| 26 | `array_hasownproperty` | 11 | 2.6s |  |
| 27 | `array_holes` | 9 | 5.4s |  |
| 28 | `array_index_max` | 84 | 5.3s |  |
| 29 | `array_indexof` | 25 | 5.5s |  |
| 30 | `array_join` | 26 | 5.5s |  |
| 31 | `array_lastindexof` | 29 | 5.6s |  |
| 32 | `array_length` | 14 | 5.5s |  |
| 33 | `array_literal` | 3 | 5.4s |  |
| 34 | `array_map` | 8 | 5.3s |  |
| 35 | `array_pop` | 52 | 5.6s |  |
| 36 | `array_push` | 24 | 5.5s |  |
| 37 | `array_reborrow_bug` | 6 | 5.4s |  |
| 38 | `array_reverse` | 28 | 5.5s |  |
| 39 | `array_shift` | 51 | 2.7s |  |
| 40 | `array_slice` | 39 | 5.6s |  |
| 41 | `array_some` | 8 | 5.6s |  |
| 42 | `array_sort` | 297 | 6.0s |  |
| 43 | `array_sort_fun_swf12` | 2 | 5.5s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 45 | `array_sort_random` | 210 | 5.5s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 5.5s |  |
| 47 | `array_sorton` | 545 | 6.5s |  |
| 48 | `array_sparse_ops` | 41 | 5.8s |  |
| 49 | `array_splice` | 133 | 5.8s |  |
| 50 | `array_splice2` | 428 | 5.9s |  |
| 51 | `array_splice_types` | 48 | 5.7s |  |
| 52 | `array_storage` | 8 | 5.6s |  |
| 53 | `array_tolocalestring` | 9 | 5.6s |  |
| 54 | `array_tostring` | 12 | 5.5s |  |
| 55 | `array_unshift` | 24 | 5.6s |  |
| 56 | `array_valueof` | 9 | 5.5s |  |
| 57 | `array_vector_null_callback` | 10 | 5.7s |  |
| 58 | `astype` | 28 | 5.7s |  |
| 59 | `astypelate` | 24 | 5.8s |  |
| 60 | `astypelate_propagates` | 1 | 5.4s |  |
| 61 | `asymmetric_key_events` | 11 | 5.5s |  |
| 62 | `avm2_catchup_dobj` | 158 | 6.0s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 78.4s |  |
| 64 | `bitand` | 1058 | 17.7s |  |
| 65 | `bitmap_constr` | 17 | 5.9s |  |
| 66 | `bitmap_data` | 1000 | 14.0s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 25.0s |  |
| 68 | `bitmap_properties` | 23 | 5.7s |  |
| 69 | `bitmap_subclass` | 7 | 7.2s |  |
| 70 | `bitmap_subclass_properties` | 9 | 6.2s |  |
| 71 | `bitmap_timeline` | 9 | 5.6s |  |
| 72 | `bitmapdata_accuracy` | 1 | 42.5s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 24.6s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.4s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 24.6s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.1s |  |
| 77 | `bitmapdata_clone` | 13 | 5.9s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.1s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 5.5s |  |
| 80 | `bitmapdata_constr` | 22 | 2.8s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 5.8s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.6s |  |
| 83 | `bitmapdata_copypixels` | 23 | 26.5s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.8s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.9s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.7s |  |
| 87 | `bitmapdata_draw` | 0 | 25.4s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.0s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.2s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 24.7s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 6.0s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.1s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.1s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 24.6s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 6.0s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.1s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.0s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 25.2s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.7s |  |
| 100 | `bitmapdata_getpixels` | 39 | 24.6s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 103 | `bitmapdata_hittest` | 112 | 6.2s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.7s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.0s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 25.0s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.3s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.6s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.8s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.7s |  |
| 111 | `bitmapdata_sync` | 0 | 5.9s |  |
| 112 | `bitmapdata_threshold` | 176 | 6.5s |  |
| 113 | `bitnot` | 46 | 5.7s |  |
| 114 | `bitor` | 1058 | 17.8s |  |
| 115 | `bitxor` | 1058 | 17.6s |  |
| 116 | `blend_multiply_alpha` | 0 | 5.9s |  |
| 117 | `blend_scroll` | 0 | 5.9s |  |
| 118 | `boolean_constr` | 32 | 6.2s |  |
| 119 | `boolean_negation` | 30 | 6.1s |  |
| 120 | `boolean_tostring` | 8 | 6.0s |  |
| 121 | `broadcast_event` | 7 | 6.1s |  |
| 122 | `button_nested_frame` | 48 | 6.3s |  |
| 123 | `bytearray` | 48 | 6.4s |  |
| 124 | `bytearray_compress` | 31 | 6.1s |  |
| 125 | `bytearray_errors` | 24 | 6.1s |  |
| 126 | `bytearray_method_serialization` | 1 | 6.0s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 6.0s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 6.0s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 130 | `bytearray_serialization` | 3 | 6.0s |  |
| 131 | `bytearray_string_null` | 19 | 6.2s |  |
| 132 | `bytearray_tostring` | 15 | 6.0s |  |
| 133 | `bytearray_utf16` | 8 | 6.0s |  |
| 134 | `bytearray_writeobject` | 24 | 5.9s |  |
| 135 | `callee_in_initializer` | 6 | 5.9s |  |
| 136 | `callproplex_class` | 1 | 5.9s |  |
| 137 | `capabilities_resolution` | 8 | 26.7s |  |
| 138 | `catch_class` | 6 | 5.9s |  |
| 139 | `catch_scope_slot` | 7 | 3.0s |  |
| 140 | `checkfilter` | 4 | 3.0s |  |
| 141 | `class_call` | 32 | 25.9s |  |
| 142 | `class_cast_call` | 14 | 6.0s |  |
| 143 | `class_enumeration` | 4 | 6.1s |  |
| 144 | `class_has_own_property` | 2 | 6.1s |  |
| 145 | `class_init_interpreter_mode` | 1 | 6.2s |  |
| 146 | `class_is` | 32 | 6.2s |  |
| 147 | `class_methods` | 5 | 6.1s |  |
| 148 | `class_object_properties` | 10 | 6.1s |  |
| 149 | `class_singleton` | 18 | 6.1s |  |
| 150 | `class_supercalls_errors` | 35 | 6.2s |  |
| 151 | `class_supercalls_mismatched` | 26 | 6.1s |  |
| 152 | `class_superclass_wrong_order` | 1 | 23.8s |  |
| 153 | `class_to_locale_string` | 2 | 5.7s |  |
| 154 | `class_to_string` | 2 | 5.6s |  |
| 155 | `class_value_of` | 2 | 5.7s |  |
| 156 | `click_block` | 5 | 24.2s |  |
| 157 | `click_invisible` | 3 | 5.8s |  |
| 158 | `closures` | 12 | 5.7s |  |
| 159 | `coerce_return_type` | 40 | 5.8s |  |
| 160 | `coerce_return_type_fail` | 2 | 5.6s |  |
| 161 | `coerce_return_void` | 3 | 5.6s |  |
| 162 | `coerce_string` | 86 | 5.8s |  |
| 163 | `coerce_string_precision` | 28 | 5.7s |  |
| 164 | `coerce_to_primitive_side_effects` | 29 | 5.8s |  |
| 165 | `construct_errors_swf10` | 8 | 5.7s |  |
| 166 | `construct_frame_list` | 22 | 5.8s |  |
| 167 | `constructor_call` | 3 | 5.7s |  |
| 168 | `constructors_vs_timeline` | 5 | 24.2s |  |
| 169 | `constructprop_dynamic_primitive` | 7 | 5.8s |  |
| 170 | `control_flow_bool` | 4 | 5.7s |  |
| 171 | `control_flow_stricteq` | 8 | 5.7s |  |
| 172 | `convert_boolean` | 30 | 5.7s |  |
| 173 | `convert_integer` | 90 | 5.8s |  |
| 174 | `convert_number` | 56 | 5.8s |  |
| 175 | `convert_uinteger` | 90 | 5.8s |  |
| 176 | `cryptscore` | 11 | 5.9s |  |
| 177 | `date` | 30 | 5.9s |  |
| 178 | `date_parse` | 36 | 5.5s |  |
| 179 | `declocal` | 46 | 5.5s |  |
| 180 | `declocal_i` | 46 | 5.6s |  |
| 181 | `decode_uri` | 71 | 5.9s |  |
| 182 | `decrement` | 46 | 5.5s |  |
| 183 | `decrement_i` | 46 | 2.8s |  |
| 184 | `default_values` | 7 | 5.5s |  |
| 185 | `dictionary_access` | 62 | 5.8s |  |
| 186 | `dictionary_access_no_pubns` | 2 | 5.4s |  |
| 187 | `dictionary_delete` | 101 | 6.1s |  |
| 188 | `dictionary_foreach` | 42 | 5.8s |  |
| 189 | `dictionary_hasownproperty` | 63 | 5.8s |  |
| 190 | `dictionary_in` | 62 | 5.8s |  |
| 191 | `dictionary_iter_modify` | 8 | 5.5s |  |
| 192 | `dictionary_namespaces` | 36 | 5.7s |  |
| 193 | `dictionary_primitive_keys` | 29 | 5.6s |  |
| 194 | `displayobject_alpha` | 277 | 5.5s |  |
| 195 | `displayobject_blendmode` | 0 | 5.7s |  |
| 196 | `displayobject_colortransform_nested` | 0 | 23.8s |  |
| 197 | `displayobject_from_enterframe` | 1 | 5.6s |  |
| 198 | `displayobject_getbounds_shape` | 0 | 23.9s |  |
| 199 | `displayobject_height` | 6052 | 23.7s |  |
| 200 | `displayobject_hittestobject` | 32 | 5.5s |  |
| 201 | `displayobject_invalid_floats` | 60 | 5.5s |  |
| 202 | `displayobject_invalid_props` | 3 | 2.6s |  |
| 203 | `displayobject_mask` | 3 | 5.9s |  |
| 204 | `displayobject_mask_self_referential` | 0 | 5.5s |  |
| 205 | `displayobject_metaData` | 3 | 5.4s |  |
| 206 | `displayobject_name` | 22 | 5.8s |  |
| 207 | `displayobject_name_from_timeline` | 24 | 5.7s |  |
| 208 | `displayobject_parent` | 12 | 5.5s |  |
| 209 | `displayobject_root` | 24 | 5.5s |  |
| 210 | `displayobject_rotation` | 1284 | 5.8s |  |
| 211 | `displayobject_set_matrix_nested` | 0 | 24.4s |  |
| 212 | `displayobject_subclass` | 2 | 5.7s |  |
| 213 | `displayobject_visible` | 23 | 5.9s |  |
| 214 | `displayobject_width` | 4852 | 24.6s |  |
| 215 | `displayobject_x` | 614 | 5.7s |  |
| 216 | `displayobject_y` | 617 | 5.7s |  |
| 217 | `displayobjectcontainer_addchild` | 32 | 5.8s |  |
| 218 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.6s |  |
| 219 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.8s |  |
| 220 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.8s |  |
| 221 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.7s |  |
| 222 | `displayobjectcontainer_addchildat` | 42 | 5.7s |  |
| 223 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 2.9s |  |
| 224 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.8s |  |
| 225 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.7s |  |
| 226 | `displayobjectcontainer_contains` | 66 | 24.2s |  |
| 227 | `displayobjectcontainer_getchildat` | 4 | 5.8s |  |
| 228 | `displayobjectcontainer_getchildbyname` | 9 | 5.6s |  |
| 229 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.6s |  |
| 230 | `displayobjectcontainer_getchildindex` | 28 | 5.6s |  |
| 231 | `displayobjectcontainer_removechild` | 10 | 5.4s |  |
| 232 | `displayobjectcontainer_removechild_errors` | 4 | 5.5s |  |
| 233 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.7s |  |
| 234 | `displayobjectcontainer_removechildat` | 18 | 5.9s |  |
| 235 | `displayobjectcontainer_removechildren` | 51 | 6.2s |  |
| 236 | `displayobjectcontainer_setchildindex` | 42 | 5.9s |  |
| 237 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.3s |  |
| 238 | `displayobjectcontainer_swapchildren` | 42 | 5.9s |  |
| 239 | `displayobjectcontainer_swapchildrenat` | 42 | 5.7s |  |
| 240 | `displayobjectcontainer_timelineinstance` | 48 | 26.6s |  |
| 241 | `divide` | 1058 | 14.3s |  |
| 242 | `doabc_is_eager` | 1 | 23.0s |  |
| 243 | `documentclass` | 9 | 5.3s |  |
| 244 | `drag_drop` | 10 | 5.3s |  |
| 245 | `duplicate_defs` | 1 | 5.0s |  |
| 246 | `eager_init` | 1 | 5.2s |  |
| 247 | `edit_text_linkage` | 7 | 5.3s |  |
| 248 | `edittext_align` | 60 | 5.6s |  |
| 249 | `edittext_always_show_selection` | 0 | 23.8s |  |
| 250 | `edittext_antialiastype` | 296 | 5.4s |  |
| 251 | `edittext_at_point_methods_basic` | 16 | 6.5s |  |
| 252 | `edittext_autosize` | 39 | 5.5s |  |
| 253 | `edittext_autosize_align` | 0 | 23.8s |  |
| 254 | `edittext_autosize_height_dynamic` | 60 | 23.7s |  |
| 255 | `edittext_autosize_height_input` | 60 | 5.2s |  |
| 256 | `edittext_autosize_lazy_bounds_events` | 65 | 5.4s |  |
| 257 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.2s |  |
| 258 | `edittext_autosize_lazy_bounds_props` | 490 | 6.5s |  |
| 259 | `edittext_autosize_lazy_bounds_visual` | 0 | 5.3s |  |
| 260 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.4s |  |
| 261 | `edittext_bottom_scroll_v_basic` | 210 | 5.2s |  |
| 262 | `edittext_bounds_scale` | 24 | 23.1s |  |
| 263 | `edittext_bullet` | 30 | 5.3s |  |
| 264 | `edittext_default_format` | 221 | 5.5s |  |
| 265 | `edittext_default_format_empty` | 136 | 5.4s |  |
| 266 | `edittext_empty_text_format` | 7 | 5.2s |  |
| 267 | `edittext_focus_selection` | 5 | 5.2s |  |
| 268 | `edittext_font_size` | 45 | 5.2s |  |
| 269 | `edittext_format_empty_font` | 8 | 5.1s |  |
| 270 | `edittext_get_char_index_at_point` | 4 | 24.1s |  |
| 271 | `edittext_get_line_index_at_point` | 2 | 23.7s |  |
| 272 | `edittext_get_line_index_of_char` | 76 | 6.1s |  |
| 273 | `edittext_getcharboundaries` | 172 | 5.5s |  |
| 274 | `edittext_getcharboundaries_missing_glyphs` | 63 | 28.2s |  |
| 275 | `edittext_getcharboundaries_scroll` | 85 | 6.2s |  |
| 276 | `edittext_getlinemetrics` | 146 | 6.2s |  |
| 277 | `edittext_html` | 3101 | 6.4s |  |
| 278 | `edittext_html_condensewhite` | 487 | 6.1s |  |
| 279 | `edittext_html_entity` | 4 | 6.2s |  |
| 280 | `edittext_html_font_size_swf12` | 267 | 6.1s |  |
| 281 | `edittext_html_font_size_swf13` | 273 | 5.8s |  |
| 282 | `edittext_html_roundtrip` | 17 | 6.0s |  |
| 283 | `edittext_input_control` | 12 | 6.2s |  |
| 284 | `edittext_leading` | 9 | 6.3s |  |
| 285 | `edittext_letter_spacing` | 15 | 6.0s |  |
| 286 | `edittext_line_methods` | 294 | 7.5s |  |
| 287 | `edittext_line_metrics` | 11 | 27.2s |  |
| 288 | `edittext_margins` | 25 | 6.1s |  |
| 289 | `edittext_max_scroll_h_basic` | 475 | 6.2s |  |
| 290 | `edittext_max_scroll_v_basic` | 1000 | 6.1s |  |
| 291 | `edittext_mousedown` | 3 | 6.3s |  |
| 292 | `edittext_mouseenabled` | 26 | 6.0s |  |
| 293 | `edittext_newline_character` | 22 | 6.0s |  |
| 294 | `edittext_newline_stripping` | 64 | 8.6s |  |
| 295 | `edittext_newlines` | 30 | 6.1s |  |
| 296 | `edittext_paragraph_methods` | 257 | 6.0s |  |
| 297 | `edittext_paste_events` | 8 | 6.0s |  |
| 298 | `edittext_paste_maxchars` | 4 | 6.0s |  |
| 299 | `edittext_paste_restrict` | 16 | 5.9s |  |
| 300 | `edittext_restrict` | 191 | 6.0s |  |
| 301 | `edittext_restrict_events` | 22 | 6.0s |  |
| 302 | `edittext_scrollh` | 10 | 3.0s |  |
| 303 | `edittext_selected_text` | 9 | 5.9s |  |
| 304 | `edittext_set_html_same` | 17 | 6.0s |  |
| 305 | `edittext_set_text_vs_html` | 9 | 5.9s |  |
| 306 | `edittext_stylesheet` | 536 | 6.3s |  |
| 307 | `edittext_stylesheet_custom_tag` | 76 | 6.0s |  |
| 308 | `edittext_stylesheet_display` | 272 | 6.1s |  |
| 309 | `edittext_underline` | 40 | 6.1s |  |
| 310 | `edittext_width_height` | 103 | 6.2s |  |
| 311 | `edittext_wordwrap_word` | 150 | 8.0s |  |
| 312 | `edittext_wrap_breaks` | 2375 | 6.1s |  |
| 313 | `empty_bounds` | 1 | 5.5s |  |
| 314 | `encode_uri_surrogate_pair_swf11` | 15 | 5.4s |  |
| 315 | `equals` | 512 | 9.8s |  |
| 316 | `error_prototype` | 15 | 5.6s |  |
| 317 | `error_stack_trace_debug_swf17` | 0 | 24.0s |  |
| 318 | `error_stack_trace_debug_swf18` | 0 | 5.4s |  |
| 319 | `error_stack_trace_release_swf17` | 0 | 5.5s |  |
| 320 | `error_stack_trace_release_swf18` | 0 | 5.4s |  |
| 321 | `error_tostring` | 29 | 5.5s |  |
| 322 | `es3_inheritance` | 31 | 5.6s |  |
| 323 | `es4_inheritance` | 30 | 5.7s |  |
| 324 | `es4_interfaces` | 30 | 5.6s |  |
| 325 | `es4_method_binding` | 8 | 2.7s |  |
| 326 | `es4_oop_prototypes` | 14 | 5.7s |  |
| 327 | `es4_protected_inheritance` | 6 | 5.5s |  |
| 328 | `escape` | 71 | 5.6s |  |
| 329 | `event_bubbles` | 2 | 5.5s |  |
| 330 | `event_cancelable` | 2 | 5.5s |  |
| 331 | `event_clone` | 20 | 5.7s |  |
| 332 | `event_clone_error_redispatch` | 3 | 5.8s |  |
| 333 | `event_clone_on_redispatch` | 10 | 5.8s |  |
| 334 | `event_formattostring` | 31 | 5.7s |  |
| 335 | `event_isdefaultprevented` | 12 | 5.7s |  |
| 336 | `event_target_getter` | 5 | 2.7s |  |
| 337 | `event_target_set` | 9 | 5.5s |  |
| 338 | `event_type` | 1 | 5.5s |  |
| 339 | `event_valueof_tostring` | 18 | 6.0s |  |
| 340 | `eventdispatcher_dispatchevent` | 12 | 4.4s |  |
| 341 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.4s |  |
| 342 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.4s |  |
| 343 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.4s |  |
| 344 | `eventdispatcher_dispatchevent_this` | 5 | 4.4s |  |
| 345 | `eventdispatcher_haseventlistener` | 25 | 4.5s |  |
| 346 | `eventdispatcher_interface_invoke` | 1 | 4.4s |  |
| 347 | `eventdispatcher_tostring` | 10 | 4.4s |  |
| 348 | `eventdispatcher_willtrigger` | 25 | 4.3s |  |
| 349 | `falsiness` | 30 | 4.4s |  |
| 350 | `fast_index_access` | 12 | 4.5s |  |
| 351 | `finddef` | 3 | 4.4s |  |
| 352 | `findprop_global_prototype` | 6 | 4.5s |  |
| 353 | `flash_xml` | 29 | 4.4s |  |
| 354 | `flash_xml_cloneNode` | 22 | 4.4s |  |
| 355 | `flash_xml_namespace` | 109 | 4.5s |  |
| 356 | `flash_xml_removeNode` | 60 | 4.4s |  |
| 357 | `focus_events_code` | 161 | 18.9s |  |
| 358 | `focus_events_key_same_object` | 26 | 4.5s |  |
| 359 | `focus_events_mixed_key_mouse` | 100 | 18.8s |  |
| 360 | `focus_events_mouse_same_object` | 40 | 6.0s |  |
| 361 | `focus_remove` | 20 | 24.8s |  |
| 362 | `focus_root_movie` | 4 | 25.0s |  |
| 363 | `focus_stage` | 1 | 5.9s |  |
| 364 | `focusrect` | 18 | 6.7s |  |
| 365 | `font_description_clone` | 14 | 5.9s |  |
| 366 | `font_embedded` | 24 | 6.2s |  |
| 367 | `font_enumeratefonts` | 41 | 6.5s |  |
| 368 | `font_enumeratefonts_filter` | 4 | 25.4s |  |
| 369 | `font_hasglyphs` | 40 | 6.3s |  |
| 370 | `framelabel_constr` | 5 | 5.8s |  |
| 371 | `function_call` | 12 | 5.9s |  |
| 372 | `function_call_arguments` | 46 | 5.9s |  |
| 373 | `function_call_arguments_enumerate` | 5 | 5.8s |  |
| 374 | `function_call_coercion` | 108 | 6.2s |  |
| 375 | `function_call_default` | 6 | 5.8s |  |
| 376 | `function_call_rest` | 22 | 5.8s |  |
| 377 | `function_call_types` | 3 | 5.8s |  |
| 378 | `function_call_via_apply` | 11 | 5.8s |  |
| 379 | `function_call_via_call` | 3 | 5.8s |  |
| 380 | `function_display_anonymous` | 7 | 2.9s |  |
| 381 | `function_length` | 6 | 5.8s |  |
| 382 | `function_object` | 2 | 5.8s |  |
| 383 | `function_proto` | 5 | 5.8s |  |
| 384 | `function_proto_created` | 61 | 5.9s |  |
| 385 | `function_to_locale_string` | 4 | 5.8s |  |
| 386 | `function_to_string` | 4 | 5.8s |  |
| 387 | `function_type` | 6 | 5.8s |  |
| 388 | `function_unbound_this` | 51 | 6.0s |  |
| 389 | `function_value_of` | 4 | 5.8s |  |
| 390 | `get_definition_by_name` | 11 | 5.8s |  |
| 391 | `get_qualified_class_name` | 20 | 5.9s |  |
| 392 | `get_qualified_super_class_name` | 18 | 4.7s |  |
| 393 | `get_slot_edge_cases` | 1 | 14.1s |  |
| 394 | `get_timer` | 2 | 3.3s |  |
| 395 | `getglobalslot` | 1 | 3.2s |  |
| 396 | `getouterscope` | 8 | 3.3s |  |
| 397 | `getter_different_namespace_setter` | 2 | 3.3s |  |
| 398 | `goto_button_nested_framescript` | 28 | 3.5s |  |
| 399 | `goto_in_constructframe` | 12 | 3.4s |  |
| 400 | `goto_in_scene_last_frame` | 2 | 14.1s |  |
| 401 | `goto_methods` | 56 | 3.4s |  |
| 402 | `goto_methods_swfver10` | 8 | 3.3s |  |
| 403 | `goto_nested_construct_sibling` | 18 | 3.5s |  |
| 404 | `goto_nested_framescript` | 9 | 3.4s |  |
| 405 | `goto_on_orphan` | 15 | 3.5s |  |
| 406 | `graphics_bad_direct_commands` | 5 | 3.8s |  |
| 407 | `graphics_bitmap_fill` | 0 | 4.5s |  |
| 408 | `graphics_bitmaps` | 0 | 3.8s |  |
| 409 | `graphics_direct_commands` | 0 | 3.7s |  |
| 410 | `graphics_draw_triangles` | 98 | 14.6s |  |
| 411 | `graphics_gradients` | 0 | 3.6s |  |
| 412 | `graphics_gradients_nulls` | 0 | 3.6s |  |
| 413 | `graphics_path` | 56 | 3.3s |  |
| 414 | `graphics_round_rects` | 0 | 3.3s |  |
| 415 | `graphics_simple_shapes` | 0 | 3.5s |  |
| 416 | `greaterequals` | 512 | 5.2s |  |
| 417 | `greaterthan` | 512 | 5.3s |  |
| 418 | `has_own_property` | 102 | 3.5s |  |
| 419 | `hasownproperty_namespaces` | 2 | 3.4s |  |
| 420 | `hello_world` | 1 | 3.3s |  |
| 421 | `hittest_morph` | 30 | 3.4s |  |
| 422 | `if_eq` | 10 | 3.3s |  |
| 423 | `if_gt` | 1 | 3.3s |  |
| 424 | `if_gte` | 10 | 1.6s |  |
| 425 | `if_lt` | 1 | 7.6s |  |
| 426 | `if_lte` | 10 | 5.8s |  |
| 427 | `if_ne` | 7 | 2.9s |  |
| 428 | `if_stricteq` | 6 | 5.7s |  |
| 429 | `if_strictne` | 11 | 5.7s |  |
| 430 | `in` | 102 | 6.1s |  |
| 431 | `inclocal` | 46 | 5.8s |  |
| 432 | `inclocal_i` | 46 | 5.8s |  |
| 433 | `increment` | 46 | 5.7s |  |
| 434 | `increment_i` | 46 | 5.8s |  |
| 435 | `instanceof` | 58 | 6.0s |  |
| 436 | `instantiation_on_enter_frame` | 7 | 24.1s |  |
| 437 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.7s |  |
| 438 | `int_constr` | 92 | 5.6s |  |
| 439 | `int_edge_cases` | 19 | 5.8s |  |
| 440 | `int_instanceof` | 3 | 5.7s |  |
| 441 | `int_tofixed` | 1215 | 5.7s |  |
| 442 | `int_tostring` | 3375 | 5.6s |  |
| 443 | `interactiveobject_enabled` | 25 | 5.7s |  |
| 444 | `interface_namespaces` | 78 | 5.9s |  |
| 445 | `is_finite` | 46 | 5.8s |  |
| 446 | `is_nan` | 46 | 5.7s |  |
| 447 | `is_prototype_of` | 12 | 5.7s |  |
| 448 | `issue_10221` | 2 | 5.7s |  |
| 449 | `issue_13780` | 12 | 5.7s |  |
| 450 | `issue_14901` | 1 | 5.7s |  |
| 451 | `issue_17675_edittext_paste_maxchars` | 1 | 5.7s |  |
| 452 | `issue_5292` | 5 | 5.7s |  |
| 453 | `issue_8630` | 2 | 23.9s |  |
| 454 | `issue_8630_scriptremove` | 11 | 5.7s |  |
| 455 | `istype` | 24 | 2.9s |  |
| 456 | `istypelate` | 58 | 6.0s |  |
| 457 | `istypelate_coerce` | 198 | 6.6s |  |
| 458 | `json_errors` | 9 | 19.8s |  |
| 459 | `json_parse` | 21 | 4.6s |  |
| 460 | `json_stringify` | 12 | 5.0s |  |
| 461 | `json_stringify_order` | 1 | 4.6s |  |
| 462 | `json_version_gated` | 1 | 4.7s |  |
| 463 | `key_input_80percent` | 1812 | 4.4s |  |
| 464 | `key_input_location` | 126 | 5.7s |  |
| 465 | `key_input_numpad` | 384 | 5.2s |  |
| 466 | `lazyinit` | 17 | 4.3s |  |
| 467 | `lessequals` | 512 | 6.7s |  |
| 468 | `lessthan` | 512 | 6.7s |  |
| 469 | `loaderinfo_properties` | 18 | 6.0s |  |
| 470 | `loaderinfo_root` | 10 | 6.0s |  |
| 471 | `loaderinfo_root_allows` | 2 | 6.0s |  |
| 472 | `lshift` | 1058 | 19.4s |  |
| 473 | `mask_reapply` | 1 | 6.2s |  |
| 474 | `math` | 497 | 6.2s |  |
| 475 | `missing_external_interface` | 10 | 6.1s |  |
| 476 | `modulo` | 1058 | 18.6s |  |
| 477 | `morph_shape` | 2 | 26.7s |  |
| 478 | `mouse_click_events` | 90 | 27.1s |  |
| 479 | `mouse_double_click_events` | 188 | 6.2s |  |
| 480 | `mouse_empty_parent` | 4 | 6.1s |  |
| 481 | `mouse_over_while_dragging` | 3 | 6.1s |  |
| 482 | `mouse_pick_button_mode` | 2 | 6.1s |  |
| 483 | `mouse_sibling` | 8 | 6.0s |  |
| 484 | `movieclip_addframescript` | 3 | 26.0s |  |
| 485 | `movieclip_child_property` | 16 | 6.1s |  |
| 486 | `movieclip_constr` | 21 | 6.0s |  |
| 487 | `movieclip_currentlabels` | 17 | 25.6s |  |
| 488 | `movieclip_currentlabels_dupes1` | 46 | 23.6s |  |
| 489 | `movieclip_currentlabels_dupes2` | 30 | 5.5s |  |
| 490 | `movieclip_currentlabels_dupes3` | 67 | 5.5s |  |
| 491 | `movieclip_currentscene` | 12 | 5.5s |  |
| 492 | `movieclip_dispatchevent` | 430 | 5.6s |  |
| 493 | `movieclip_dispatchevent_cancel` | 102 | 5.7s |  |
| 494 | `movieclip_dispatchevent_handlerorder` | 251 | 5.6s |  |
| 495 | `movieclip_dispatchevent_selfadd` | 80 | 5.5s |  |
| 496 | `movieclip_dispatchevent_target` | 899 | 5.6s |  |
| 497 | `movieclip_displayevents` | 96 | 23.9s |  |
| 498 | `movieclip_displayevents_clickgoto` | 676 | 5.9s |  |
| 499 | `movieclip_displayevents_clickgoto2` | 2001 | 6.0s |  |
| 500 | `movieclip_displayevents_clickplay` | 575 | 5.7s |  |
| 501 | `movieclip_displayevents_clicksymbol` | 562 | 5.7s |  |
| 502 | `movieclip_displayevents_constructframegoto` | 140 | 5.9s |  |
| 503 | `movieclip_displayevents_constructframeplay` | 50 | 5.8s |  |
| 504 | `movieclip_displayevents_constructframesymbol` | 144 | 5.7s |  |
| 505 | `movieclip_displayevents_dblhandler` | 21 | 5.7s |  |
| 506 | `movieclip_displayevents_enterframegoto` | 149 | 5.8s |  |
| 507 | `movieclip_displayevents_enterframeplay` | 48 | 5.6s |  |
| 508 | `movieclip_displayevents_enterframesymbol` | 149 | 23.9s |  |
| 509 | `movieclip_displayevents_exitframegoto` | 106 | 5.7s |  |
| 510 | `movieclip_displayevents_exitframeplay` | 44 | 5.6s |  |
| 511 | `movieclip_displayevents_exitframesymbol` | 135 | 5.7s |  |
| 512 | `movieclip_displayevents_looping` | 63 | 23.9s |  |
| 513 | `movieclip_displayevents_stopped` | 113 | 6.0s |  |
| 514 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 515 | `movieclip_displayevents_timeline` | 128 | 24.0s |  |
| 516 | `movieclip_drawrect` | 54 | 5.5s |  |
| 517 | `movieclip_frameconstruct_skipped` | 9 | 5.5s |  |
| 518 | `movieclip_goto_during_frame_script` | 15 | 5.6s |  |
| 519 | `movieclip_goto_overwrite` | 14 | 23.5s |  |
| 520 | `movieclip_goto_scene_last_frame_int` | 1 | 23.8s |  |
| 521 | `movieclip_goto_scene_last_frame_label` | 1 | 2.6s |  |
| 522 | `movieclip_gotoandplay` | 15 | 23.5s |  |
| 523 | `movieclip_gotoandstop` | 13 | 5.5s |  |
| 524 | `movieclip_gotoandstop_children` | 4 | 5.6s |  |
| 525 | `movieclip_gotoandstop_framescripts1` | 4 | 5.5s |  |
| 526 | `movieclip_gotoandstop_framescripts2` | 4 | 2.7s |  |
| 527 | `movieclip_gotoandstop_framescripts_self` | 7 | 5.5s |  |
| 528 | `movieclip_gotoandstop_queueing` | 12 | 26.6s |  |
| 529 | `movieclip_next_frame` | 2 | 5.8s |  |
| 530 | `movieclip_next_scene` | 6 | 24.4s |  |
| 531 | `movieclip_play` | 3 | 2.8s |  |
| 532 | `movieclip_prev_frame` | 3 | 5.5s |  |
| 533 | `movieclip_prev_scene` | 7 | 5.8s |  |
| 534 | `movieclip_properties` | 79 | 6.2s |  |
| 535 | `movieclip_queued_noop_goto_swf10` | 9 | 6.0s |  |
| 536 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 537 | `movieclip_scenes` | 11 | 5.9s |  |
| 538 | `movieclip_soundtransform` | 831 | 29.2s |  |
| 539 | `movieclip_stop` | 1 | 6.0s |  |
| 540 | `movieclip_super_is_symbol` | 20 | 6.4s |  |
| 541 | `movieclip_symbol_constr` | 8 | 6.0s |  |
| 542 | `movieclip_text_mousedown` | 1 | 5.8s |  |
| 543 | `movieclip_willtrigger` | 5 | 5.8s |  |
| 544 | `multiply` | 1058 | 17.1s |  |
| 545 | `namespace_constr` | 253 | 6.1s |  |
| 546 | `namespace_constr_args` | 1 | 5.8s |  |
| 547 | `namespace_enumeration_order` | 7 | 6.1s |  |
| 548 | `nan_scale` | 9 | 6.1s |  |
| 549 | `negate` | 30 | 6.1s |  |
| 550 | `negative_volume_panned` | 0 | 6.1s |  |
| 551 | `nested_iteration` | 11 | 5.9s |  |
| 552 | `net_getClassByAlias` | 3 | 5.7s |  |
| 553 | `newactivation_in_script_init` | 3 | 5.8s |  |
| 554 | `newclass_twice` | 3 | 5.9s |  |
| 555 | `nonconflicting_declarations` | 0 | 5.9s |  |
| 556 | `null_void_types` | 8 | 5.9s |  |
| 557 | `number_autoconv` | 21 | 3.0s |  |
| 558 | `number_autoconv_amf` | 132 | 5.9s |  |
| 559 | `number_autoconv_array_sort_32bit` | 1 | 5.9s |  |
| 560 | `number_constr` | 58 | 6.0s |  |
| 561 | `number_toexponential` | 378 | 6.0s |  |
| 562 | `number_toexponential2` | 35 | 5.9s |  |
| 563 | `number_tofixed` | 378 | 5.8s |  |
| 564 | `number_toprecision` | 350 | 5.9s |  |
| 565 | `obfuscated_class_names` | 3 | 5.8s |  |
| 566 | `object_enumeration` | 10 | 5.9s |  |
| 567 | `object_prototype` | 4 | 5.9s |  |
| 568 | `object_to_locale_string` | 2 | 5.9s |  |
| 569 | `object_to_string` | 2 | 5.9s |  |
| 570 | `object_value_of` | 2 | 2.8s |  |
| 571 | `op_coerce` | 54 | 3.0s |  |
| 572 | `op_coerce_x` | 54 | 6.0s |  |
| 573 | `op_escxattr` | 2 | 5.9s |  |
| 574 | `op_escxelem` | 2 | 5.9s |  |
| 575 | `op_lookupswitch` | 4 | 5.9s |  |
| 576 | `optimize_coerce` | 1 | 5.9s |  |
| 577 | `orphan_movie_complex` | 80 | 6.3s |  |
| 578 | `orphan_movie_reorder` | 111 | 26.5s |  |
| 579 | `package_namespace` | 7 | 5.8s |  |
| 580 | `param_default_value_has_zero_cpool_index` | 1 | 5.7s |  |
| 581 | `parent_early_access_child` | 16 | 6.2s |  |
| 582 | `parse_float` | 81 | 6.3s |  |
| 583 | `pixelbender_effect_BlurredFocus` | 0 | 28.4s |  |
| 584 | `pixelbender_effect_glassDisplace` | 0 | 11.5s |  |
| 585 | `pixelbender_effect_smudge` | 0 | 9.3s |  |
| 586 | `pixelbender_effect_tintype` | 0 | 8.5s |  |
| 587 | `pixelbender_effect_twirl` | 0 | 9.6s |  |
| 588 | `pixelbender_images` | 0 | 7.9s |  |
| 589 | `place_multiple` | 17 | 24.1s |  |
| 590 | `place_object_replace` | 9 | 5.8s |  |
| 591 | `place_object_replace_2` | 24 | 5.7s |  |
| 592 | `place_object_same_depth_frame` | 1 | 5.8s |  |
| 593 | `point` | 132 | 6.2s |  |
| 594 | `primitive_edge_cases` | 1 | 5.5s |  |
| 595 | `property_priority` | 22 | 4.5s |  |
| 596 | `property_priority_three_level` | 6 | 17.6s |  |
| 597 | `propertyisenumerable_namespaces` | 6 | 4.2s |  |
| 598 | `prototype_set_null` | 7 | 4.2s |  |
| 599 | `proxy_callproperty` | 24 | 4.1s |  |
| 600 | `proxy_deleteproperty` | 64 | 4.5s |  |
| 601 | `proxy_enumeration` | 34 | 4.2s |  |
| 602 | `proxy_getproperty` | 77 | 4.3s |  |
| 603 | `proxy_hasownproperty` | 8 | 4.1s |  |
| 604 | `proxy_hasproperty` | 32 | 4.2s |  |
| 605 | `proxy_serialize` | 9 | 4.2s |  |
| 606 | `proxy_setproperty` | 42 | 4.4s |  |
| 607 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.3s |  |
| 608 | `qname_constr` | 32 | 4.2s |  |
| 609 | `qname_constr_namespace` | 24 | 4.4s |  |
| 610 | `qname_enumeration` | 9 | 4.3s |  |
| 611 | `qname_indexing` | 23 | 4.3s |  |
| 612 | `qname_tostring` | 25 | 4.3s |  |
| 613 | `qname_valueof` | 29 | 4.2s |  |
| 614 | `regexp_constr` | 148 | 4.4s |  |
| 615 | `regexp_exec` | 19 | 4.3s |  |
| 616 | `regexp_extended` | 47 | 4.3s |  |
| 617 | `regexp_multiargs` | 1 | 4.3s |  |
| 618 | `regexp_test` | 27 | 2.2s |  |
| 619 | `regexp_toString` | 10 | 4.4s |  |
| 620 | `register_script_refresh` | 35 | 4.5s |  |
| 621 | `remove_child_clear_field` | 88 | 4.6s |  |
| 622 | `remove_dobj` | 3 | 4.3s |  |
| 623 | `resolve_order` | 4 | 4.4s |  |
| 624 | `rng` | 1 | 5.2s |  |
| 625 | `rootless` | 42 | 5.1s |  |
| 626 | `rshift` | 1058 | 19.5s |  |
| 627 | `sandbox_type_local_file` | 1 | 5.5s |  |
| 628 | `scene_constr` | 8 | 5.5s |  |
| 629 | `set_local_0` | 31 | 5.6s |  |
| 630 | `set_property_is_enumerable` | 85 | 6.0s |  |
| 631 | `shape_drawrect` | 54 | 5.6s |  |
| 632 | `shared_object_no_root` | 3 | 5.5s |  |
| 633 | `simplebutton_added_to_stage` | 45 | 23.9s |  |
| 634 | `simplebutton_childevents` | 86 | 6.0s |  |
| 635 | `simplebutton_childevents_nested` | 54 | 5.9s |  |
| 636 | `simplebutton_childevents_sprite` | 13 | 5.7s |  |
| 637 | `simplebutton_childprops` | 144 | 5.8s |  |
| 638 | `simplebutton_childshuffle` | 23 | 5.5s |  |
| 639 | `simplebutton_constr` | 36 | 5.8s |  |
| 640 | `simplebutton_constr_childevents` | 48 | 5.9s |  |
| 641 | `simplebutton_constr_params` | 42 | 5.7s |  |
| 642 | `simplebutton_mouseenabled` | 26 | 5.6s |  |
| 643 | `simplebutton_multi_children` | 19 | 5.8s |  |
| 644 | `simplebutton_structure` | 27 | 5.8s |  |
| 645 | `simplebutton_symbolclass` | 68 | 5.8s |  |
| 646 | `slot_disp_id_shared_numbering` | 1 | 23.5s |  |
| 647 | `slots_force_autoassigned` | 1 | 5.6s |  |
| 648 | `sound_embeddedprops` | 26 | 6.0s |  |
| 649 | `sound_play` | 19 | 6.0s |  |
| 650 | `sound_valueof` | 33 | 5.9s |  |
| 651 | `soundchannel_soundtransform` | 835 | 26.1s |  |
| 652 | `soundchannel_soundtransform_exists` | 5 | 24.5s |  |
| 653 | `soundchannel_stop` | 8 | 5.9s |  |
| 654 | `soundmixer_buffertime` | 5 | 5.7s |  |
| 655 | `soundmixer_stopall` | 6 | 6.0s |  |
| 656 | `soundtransform` | 442 | 8.3s |  |
| 657 | `sprite_with_frames` | 0 | 6.7s |  |
| 658 | `stage3d_agal_cross_product` | 0 | 8.7s |  |
| 659 | `stage3d_bitmap` | 0 | 30.6s |  |
| 660 | `stage3d_float1_index` | 0 | 27.5s |  |
| 661 | `stage3d_fractal` | 0 | 9.1s |  |
| 662 | `stage3d_ignore_sampler_override` | 0 | 27.4s |  |
| 663 | `stage3d_program_constants_bytearray_be` | 0 | 28.3s |  |
| 664 | `stage3d_program_constants_bytearray_le` | 0 | 9.2s |  |
| 665 | `stage3d_raytrace` | 0 | 32.0s |  |
| 666 | `stage3d_rotating_cube` | 0 | 8.8s |  |
| 667 | `stage3d_sampler` | 0 | 7.9s |  |
| 668 | `stage3d_sampler_partial_upload` | 0 | 8.0s |  |
| 669 | `stage3d_stencil` | 0 | 27.4s |  |
| 670 | `stage3d_texture` | 0 | 12.5s |  |
| 671 | `stage3d_texture_bytearray` | 0 | 9.1s |  |
| 672 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.5s |  |
| 673 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.8s |  |
| 674 | `stage3d_triangle` | 0 | 8.0s |  |
| 675 | `stage3d_triangle_bytes4` | 0 | 8.0s |  |
| 676 | `stage3d_triangle_float1` | 0 | 8.0s |  |
| 677 | `stage3d_triangle_index_upload` | 0 | 7.9s |  |
| 678 | `stage_access` | 10 | 2.5s |  |
| 679 | `stage_displayobject_properties` | 24 | 5.1s |  |
| 680 | `stage_framerate_nan` | 7 | 2.6s |  |
| 681 | `stage_framerate_negative` | 6 | 5.2s |  |
| 682 | `stage_framerate_zero` | 6 | 5.2s |  |
| 683 | `stage_invalidate` | 38 | 5.4s |  |
| 684 | `stage_mousechildren` | 2 | 5.2s |  |
| 685 | `stage_mouseenabled` | 15 | 5.1s |  |
| 686 | `stage_overriden_setters` | 31 | 5.3s |  |
| 687 | `stage_properties` | 30 | 5.2s |  |
| 688 | `static_var_with_this_in_ctor` | 2 | 5.2s |  |
| 689 | `stored_properties` | 11 | 5.4s |  |
| 690 | `strict_equality` | 34 | 5.3s |  |
| 691 | `string_call` | 13 | 5.3s |  |
| 692 | `string_case` | 23 | 5.3s |  |
| 693 | `string_char_at` | 27 | 5.3s |  |
| 694 | `string_char_code_at` | 28 | 5.1s |  |
| 695 | `string_concat_fromcharcode` | 37 | 27.3s |  |
| 696 | `string_constr` | 25 | 5.8s |  |
| 697 | `string_indexof_lastindexof` | 87 | 6.0s |  |
| 698 | `string_length` | 16 | 5.8s |  |
| 699 | `string_locale_compare` | 39 | 6.0s |  |
| 700 | `string_match` | 51 | 6.0s |  |
| 701 | `string_relational_compare` | 4 | 5.8s |  |
| 702 | `string_replace` | 51 | 6.0s |  |
| 703 | `string_search` | 41 | 6.0s |  |
| 704 | `string_slice_substr_substring` | 170 | 7.0s |  |
| 705 | `string_split` | 29 | 5.9s |  |
| 706 | `string_substr_negative` | 21 | 5.7s |  |
| 707 | `string_substr_weird` | 182 | 5.8s |  |
| 708 | `subtract` | 1058 | 18.5s |  |
| 709 | `super_get_call` | 12 | 6.0s |  |
| 710 | `supercall_two_classobjects` | 2 | 5.9s |  |
| 711 | `swf8` | 1 | 5.8s |  |
| 712 | `swf_10_queued_goto_scripts_construct` | 52 | 6.2s |  |
| 713 | `swf_9_goto_in_enter_frame` | 17 | 6.0s |  |
| 714 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.0s |  |
| 715 | `swf_9_queued_goto_scripts` | 6 | 6.0s |  |
| 716 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 717 | `swf_9_versioning` | 2 | 5.9s |  |
| 718 | `swf_wrong_frame_count` | 38 | 6.2s |  |
| 719 | `swf_wrong_frame_count_isplaying` | 22 | 5.9s |  |
| 720 | `symbol_class_binary_data` | 8 | 6.0s |  |
| 721 | `symbol_class_conflict` | 4 | 6.5s |  |
| 722 | `symbol_class_root_not_zero` | 1 | 5.9s |  |
| 723 | `symbolclass_invalid_utf8` | 2 | 5.9s |  |
| 724 | `tab_ordering_automatic_advanced` | 184 | 6.2s |  |
| 725 | `tab_ordering_automatic_basic` | 45 | 5.7s |  |
| 726 | `tab_ordering_children` | 116 | 5.8s |  |
| 727 | `tab_ordering_custom_basic` | 34 | 5.7s |  |
| 728 | `text_engine_fontdescription` | 27 | 5.8s |  |
| 729 | `text_run` | 7 | 5.5s |  |
| 730 | `textfield_focusin_event` | 9 | 5.6s |  |
| 731 | `textfield_input_dead_keys_windows` | 15 | 5.7s |  |
| 732 | `textfield_unload` | 39 | 24.1s |  |
| 733 | `textformat` | 1134 | 5.7s |  |
| 734 | `textformat_display` | 14 | 5.7s |  |
| 735 | `textformat_font_max_length` | 4 | 2.8s |  |
| 736 | `throw` | 3 | 5.6s |  |
| 737 | `timeline_scripts` | 3 | 5.6s |  |
| 738 | `timer` | 90 | 6.3s |  |
| 739 | `timer_events` | 3 | 5.8s |  |
| 740 | `timer_finished` | 11 | 2.9s |  |
| 741 | `timer_reset` | 8 | 5.8s |  |
| 742 | `timer_setdelay` | 5 | 5.8s |  |
| 743 | `trace` | 12 | 5.7s |  |
| 744 | `truthiness` | 30 | 3.7s |  |
| 745 | `try_catch` | 11 | 0.9s |  |
| 746 | `try_catch_typed` | 12 | 0.9s |  |
| 747 | `typeof` | 30 | 0.9s |  |
| 748 | `uint_constr` | 92 | 1.0s |  |
| 749 | `uint_tofixed` | 1215 | 0.9s |  |
| 750 | `uint_tostring` | 3375 | 1.0s |  |
| 751 | `unchecked_function` | 15 | 0.9s |  |
| 752 | `unescape` | 28 | 0.9s |  |
| 753 | `urlrequest` | 18 | 1.0s |  |
| 754 | `urshift` | 1058 | 1.0s |  |
| 755 | `vector_class` | 36 | 0.9s |  |
| 756 | `vector_class_call` | 11 | 0.9s |  |
| 757 | `vector_coercion` | 66 | 0.9s |  |
| 758 | `vector_concat` | 90 | 0.9s |  |
| 759 | `vector_constr` | 107 | 0.9s |  |
| 760 | `vector_enumeration` | 5 | 0.9s |  |
| 761 | `vector_every` | 92 | 0.9s |  |
| 762 | `vector_filter` | 95 | 0.9s |  |
| 763 | `vector_holes` | 24 | 0.9s |  |
| 764 | `vector_indexof` | 302 | 0.9s |  |
| 765 | `vector_insertat` | 270 | 0.9s |  |
| 766 | `vector_int_access` | 4 | 0.9s |  |
| 767 | `vector_int_delete` | 11 | 0.9s |  |
| 768 | `vector_join` | 58 | 0.9s |  |
| 769 | `vector_lastindexof` | 302 | 0.9s |  |
| 770 | `vector_legacy` | 10 | 0.9s |  |
| 771 | `vector_map` | 85 | 0.9s |  |
| 772 | `vector_object_final` | 1 | 0.9s |  |
| 773 | `vector_object_toString` | 10 | 0.9s |  |
| 774 | `vector_pushpop` | 255 | 0.9s |  |
| 775 | `vector_reborrow_bug` | 10 | 6.8s |  |
| 776 | `vector_removeat` | 172 | 5.3s |  |
| 777 | `vector_reverse` | 232 | 6.0s |  |
| 778 | `vector_shiftunshift` | 252 | 4.3s |  |
| 779 | `vector_slice` | 331 | 5.6s |  |
| 780 | `vector_sort` | 905 | 11.3s |  |
| 781 | `vector_splice` | 693 | 7.2s |  |
| 782 | `vector_splice_fixed_bug_compat` | 4 | 4.5s |  |
| 783 | `vector_tostring` | 79 | 4.9s |  |
| 784 | `verify_abnormal_loop` | 1 | 4.3s |  |
| 785 | `verify_exception_targets_edge_case` | 1 | 4.3s |  |
| 786 | `verify_lookup_switch_edge_case` | 1 | 4.2s |  |
| 787 | `verify_unreachable_exception` | 2 | 4.5s |  |
| 788 | `versioned_isplaying` | 2 | 4.4s |  |
| 789 | `virtual_properties` | 16 | 4.5s |  |
| 790 | `with` | 4 | 4.4s |  |
| 791 | `xml_abstract_equality` | 36 | 4.6s |  |
| 792 | `xml_advanced` | 52 | 4.6s |  |
| 793 | `xml_appendchild` | 10 | 4.4s |  |
| 794 | `xml_as_attribute` | 9 | 4.4s |  |
| 795 | `xml_attribute` | 35 | 4.5s |  |
| 796 | `xml_attribute_name` | 40 | 4.4s |  |
| 797 | `xml_basic` | 33 | 4.5s |  |
| 798 | `xml_child` | 25 | 4.5s |  |
| 799 | `xml_childindex` | 7 | 4.4s |  |
| 800 | `xml_children` | 43 | 5.1s |  |
| 801 | `xml_class_call` | 9 | 4.6s |  |
| 802 | `xml_contains` | 197 | 4.7s |  |
| 803 | `xml_copy` | 20 | 7.8s |  |
| 804 | `xml_ctor_from_tostring` | 23 | 5.7s |  |
| 805 | `xml_delete` | 114 | 5.5s |  |
| 806 | `xml_descendants` | 83 | 5.5s |  |
| 807 | `xml_elements` | 6 | 5.4s |  |
| 808 | `xml_equals_namespace_check` | 2 | 5.3s |  |
| 809 | `xml_explicit_use_namespace` | 5 | 23.0s |  |
| 810 | `xml_getdescendants_qname` | 21 | 5.4s |  |
| 811 | `xml_has_property_via_in` | 26 | 5.5s |  |
| 812 | `xml_hasownproperty` | 6 | 5.4s |  |
| 813 | `xml_ignore_white` | 6 | 5.4s |  |
| 814 | `xml_length` | 2 | 5.4s |  |
| 815 | `xml_list_as_attribute` | 9 | 5.4s |  |
| 816 | `xml_list_concat` | 20 | 5.4s |  |
| 817 | `xml_list_enumerate` | 4 | 5.3s |  |
| 818 | `xml_methods_settings` | 3 | 5.4s |  |
| 819 | `xml_mismatched_tag` | 37 | 5.4s |  |
| 820 | `xml_namespace` | 39 | 2.6s |  |
| 821 | `xml_namespace_methods` | 245 | 5.5s |  |
| 822 | `xml_namespaced_property` | 7 | 5.4s |  |
| 823 | `xml_no_namespace` | 1 | 5.3s |  |
| 824 | `xml_nodekind` | 3 | 5.4s |  |
| 825 | `xml_normalize` | 35 | 5.5s |  |
| 826 | `xml_notification_bubbling` | 361 | 5.5s |  |
| 827 | `xml_parent` | 8 | 5.4s |  |
| 828 | `xml_set_children` | 17 | 5.5s |  |
| 829 | `xml_set_name` | 34 | 5.4s |  |
| 830 | `xml_settings` | 6 | 2.6s |  |
| 831 | `xml_simple_complex_content` | 47 | 5.4s |  |
| 832 | `xml_text` | 7 | 5.4s |  |
| 833 | `xml_tostring` | 6 | 5.4s |  |
| 834 | `xml_tostring_namespace` | 12 | 5.4s |  |
| 835 | `xml_unescaping` | 23 | 5.4s |  |
| 836 | `xml_weird_ignores` | 54 | 5.5s |  |
| 837 | `xml_wildcard` | 11 | 5.4s |  |
| 838 | `xmldocument` | 254 | 5.5s |  |
| 839 | `xmlnode` | 3540 | 5.6s |  |
| 840 | `zero_frame_clip` | 3 | 5.5s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 5.3s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 5.7s |  |
| 3 | `blend_transform` | 1 | 1 | 6.1s |  |
| 4 | `coerce_property` | 3 | 3 | 5.8s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 2.9s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 5.7s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.4s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.2s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.1s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.7s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 5.7s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.8s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 14.0s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 14.7s |  |
| 15 | `int_toexponential` | 76 | 76 | 5.7s |  |
| 16 | `int_toprecision` | 441 | 441 | 5.6s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 5.8s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.4s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 23.6s |  |
| 20 | `soundchannel_position` | 74 | 74 | 25.2s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.0s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 5.9s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 6.2s |  |
| 24 | `uint_toexponential` | 100 | 100 | 0.9s |  |
| 25 | `uint_toprecision` | 433 | 433 | 0.9s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 4.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**68 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 5 | `focus_events_mouse_focusable` | 98.2% | 110 | 112 | 2 |  |
| 6 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 7 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 8 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 9 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 10 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 11 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 12 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 13 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 14 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 15 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 16 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 17 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 18 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 19 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 20 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 21 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 22 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 23 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 24 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 25 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 26 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 27 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 28 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 29 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 30 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 31 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 32 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 33 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 34 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 35 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 36 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 37 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 38 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 39 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 40 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 41 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 42 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 43 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 44 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 45 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 46 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 47 | `loaderinfo_loadurl` | 66.7% | 8 | 12 | 4 |  |
| 48 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 49 | `loaderinfo_properties_not_loaded` | 65.2% | 15 | 23 | 8 |  |
| 50 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 51 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 52 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 53 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 54 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 55 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 56 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 57 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 58 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 59 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 60 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 61 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 62 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 63 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 64 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 65 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 66 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 67 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 68 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 5.2s |  |
| 2 | `method_without_body` | exit code 1 | 26.6s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.5s |  |
| 4 | `verify_typecheck` | exit code 1 | 2.1s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 35.9s |  |

## All Output Mismatches

**347 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 5 | `focus_events_mouse_focusable` | 98.2% | 110/112 | 112 | 112 |  |
| 6 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 7 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 8 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 9 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 10 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 11 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 12 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 13 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 14 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 15 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 16 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 17 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 18 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 19 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 20 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 21 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 22 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 23 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 24 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 25 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 26 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 27 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 28 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 29 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 30 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 31 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 32 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 33 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 34 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 35 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 36 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 37 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 38 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 39 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 40 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 41 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 42 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 43 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 44 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 45 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 46 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 47 | `loaderinfo_loadurl` | 66.7% | 8/12 | 12 | 12 |  |
| 48 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 49 | `loaderinfo_properties_not_loaded` | 65.2% | 15/23 | 23 | 23 |  |
| 50 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 51 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 52 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 53 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 54 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 55 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 56 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 57 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 58 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 59 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 60 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 61 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 62 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 63 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 64 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 65 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 66 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 67 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 68 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 69 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 70 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 71 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 72 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 73 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 74 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 75 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 76 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 77 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 78 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 79 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 80 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 81 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 82 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 83 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 84 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 85 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 86 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 87 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 88 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 89 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 90 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 91 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 92 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 93 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 94 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 95 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 96 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 97 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 98 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 99 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 100 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 101 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 102 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 103 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 104 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 105 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 106 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 107 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 108 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 109 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 110 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 111 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 112 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 113 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 114 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 115 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 116 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 117 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 118 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 119 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 120 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 121 | `loader_events` | 8.7% | 8/92 | 20 | 92 |  |
| 122 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 123 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 124 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 125 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 126 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 127 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 128 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 129 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 130 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 131 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 132 | `loader_loadbytes_events` | 6.7% | 2/30 | 7 | 30 |  |
| 133 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 134 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 135 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 136 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 137 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 138 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 139 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 140 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 141 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 142 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 143 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 144 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 145 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 146 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 147 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 148 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 149 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 150 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 151 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 152 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 153 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 154 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 155 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 156 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 157 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 158 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 159 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 160 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 161 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 162 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 163 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 164 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 165 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 166 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 167 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 168 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 169 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 170 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 171 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 172 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 173 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 174 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 175 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 176 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 177 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 178 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 179 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 180 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 181 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 182 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 183 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 184 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 185 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 186 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 187 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 188 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 189 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 190 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 191 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 192 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 193 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 194 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 195 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 196 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 197 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 198 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 199 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 200 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 201 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 202 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 203 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 204 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 205 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 206 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 207 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 208 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 209 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 210 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 211 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 212 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 213 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 214 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 215 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 216 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 217 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 218 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 219 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 220 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 221 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 222 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 223 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 224 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 225 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 226 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 227 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 228 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 229 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 230 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 231 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 232 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 233 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 234 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 235 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 236 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 237 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 238 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 239 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 240 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 241 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 242 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 243 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 244 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 245 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 246 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 247 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 248 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 249 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 250 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 251 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 252 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 253 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 254 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 255 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 256 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 257 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 258 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 259 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 260 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 261 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 262 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 263 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 264 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 265 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 266 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 267 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 268 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 269 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 270 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 271 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 272 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 273 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 274 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 275 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 276 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 277 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 278 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 279 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 280 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 281 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 282 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 283 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 284 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 285 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 286 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 287 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 288 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 289 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 290 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 291 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 292 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 293 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 294 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 295 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 296 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 297 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 298 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 299 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 300 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 301 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 302 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 303 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 304 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 305 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 306 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 307 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 308 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 309 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 310 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 311 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 312 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 313 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 314 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 315 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 316 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 317 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 318 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 319 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 320 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 321 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 322 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 323 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 324 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 325 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 326 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 327 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 328 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 329 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 330 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 331 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 332 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 333 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 334 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 335 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 336 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 337 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 338 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 339 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 340 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 341 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 342 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 343 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 344 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 345 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 346 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 347 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
