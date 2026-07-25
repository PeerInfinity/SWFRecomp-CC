# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-25 20:09 UTC

**Git SHA**: `9b6bbcb575`

**Run Duration**: 159m 3s

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
| 1 | `add` | 1058 | 15.4s |  |
| 2 | `agal_compiler` | 13 | 6.2s |  |
| 3 | `air_hidden_lookup` | 2 | 4.0s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.2s |  |
| 5 | `amf_custom_obj` | 26 | 4.2s |  |
| 6 | `amf_dictionary` | 9 | 4.1s |  |
| 7 | `amf_function` | 46 | 4.2s |  |
| 8 | `amf_invalid_date` | 2 | 4.0s |  |
| 9 | `amf_missing_prop` | 6 | 4.1s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 5.7s |  |
| 11 | `amf_setter_error` | 8 | 5.7s |  |
| 12 | `amf_vector` | 40 | 5.8s |  |
| 13 | `amf_xml` | 6 | 5.6s |  |
| 14 | `application_domain` | 4 | 5.6s |  |
| 15 | `array_access` | 18 | 5.7s |  |
| 16 | `array_access_interpreter` | 4 | 5.6s |  |
| 17 | `array_access_no_pubns` | 2 | 5.6s |  |
| 18 | `array_concat` | 41 | 5.6s |  |
| 19 | `array_constr` | 10 | 5.5s |  |
| 20 | `array_delete` | 44 | 5.7s |  |
| 21 | `array_enumeration` | 10 | 5.6s |  |
| 22 | `array_enumeration_elements` | 11 | 5.6s |  |
| 23 | `array_every` | 8 | 5.6s |  |
| 24 | `array_filter` | 6 | 5.7s |  |
| 25 | `array_foreach` | 18 | 5.6s |  |
| 26 | `array_hasownproperty` | 11 | 2.7s |  |
| 27 | `array_holes` | 9 | 5.6s |  |
| 28 | `array_index_max` | 84 | 5.5s |  |
| 29 | `array_indexof` | 25 | 5.7s |  |
| 30 | `array_join` | 26 | 5.7s |  |
| 31 | `array_lastindexof` | 29 | 5.6s |  |
| 32 | `array_length` | 14 | 5.6s |  |
| 33 | `array_literal` | 3 | 5.6s |  |
| 34 | `array_map` | 8 | 5.5s |  |
| 35 | `array_pop` | 52 | 5.7s |  |
| 36 | `array_push` | 24 | 5.6s |  |
| 37 | `array_reborrow_bug` | 6 | 5.6s |  |
| 38 | `array_reverse` | 28 | 5.6s |  |
| 39 | `array_shift` | 51 | 2.8s |  |
| 40 | `array_slice` | 39 | 5.7s |  |
| 41 | `array_some` | 8 | 5.6s |  |
| 42 | `array_sort` | 297 | 6.1s |  |
| 43 | `array_sort_fun_swf12` | 2 | 5.6s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 45 | `array_sort_random` | 210 | 5.7s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 5.6s |  |
| 47 | `array_sorton` | 545 | 6.5s |  |
| 48 | `array_sparse_ops` | 41 | 5.8s |  |
| 49 | `array_splice` | 133 | 5.9s |  |
| 50 | `array_splice2` | 428 | 6.0s |  |
| 51 | `array_splice_types` | 48 | 5.8s |  |
| 52 | `array_storage` | 8 | 5.7s |  |
| 53 | `array_tolocalestring` | 9 | 5.7s |  |
| 54 | `array_tostring` | 12 | 5.7s |  |
| 55 | `array_unshift` | 24 | 5.7s |  |
| 56 | `array_valueof` | 9 | 5.6s |  |
| 57 | `array_vector_null_callback` | 10 | 5.7s |  |
| 58 | `astype` | 28 | 5.8s |  |
| 59 | `astypelate` | 24 | 5.8s |  |
| 60 | `astypelate_propagates` | 1 | 5.6s |  |
| 61 | `asymmetric_key_events` | 11 | 5.9s |  |
| 62 | `avm2_catchup_dobj` | 158 | 6.2s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 78.5s |  |
| 64 | `bitand` | 1058 | 16.9s |  |
| 65 | `bitmap_constr` | 17 | 5.9s |  |
| 66 | `bitmap_data` | 1000 | 13.5s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 24.7s |  |
| 68 | `bitmap_properties` | 23 | 5.8s |  |
| 69 | `bitmap_subclass` | 7 | 7.1s |  |
| 70 | `bitmap_subclass_properties` | 9 | 6.3s |  |
| 71 | `bitmap_timeline` | 9 | 5.8s |  |
| 72 | `bitmapdata_accuracy` | 1 | 43.5s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 25.2s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.8s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 24.8s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.0s |  |
| 77 | `bitmapdata_clone` | 13 | 6.1s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.2s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 5.6s |  |
| 80 | `bitmapdata_constr` | 22 | 5.7s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 5.9s |  |
| 82 | `bitmapdata_copychannel` | 0 | 25.3s |  |
| 83 | `bitmapdata_copypixels` | 23 | 23.6s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.0s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 4.9s |  |
| 86 | `bitmapdata_dispose` | 7 | 4.9s |  |
| 87 | `bitmapdata_draw` | 0 | 23.0s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 5.2s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 22.1s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 22.0s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 4.9s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 5.0s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 4.9s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 21.4s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 4.8s |  |
| 96 | `bitmapdata_embedded` | 9 | 5.0s |  |
| 97 | `bitmapdata_fillrect` | 0 | 5.0s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 22.5s |  |
| 99 | `bitmapdata_floodfill` | 35 | 4.9s |  |
| 100 | `bitmapdata_getpixels` | 39 | 22.4s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.2s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.3s |  |
| 103 | `bitmapdata_hittest` | 112 | 5.5s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 4.9s |  |
| 105 | `bitmapdata_opaque` | 0 | 5.2s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 21.9s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 5.2s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 4.7s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.0s |  |
| 110 | `bitmapdata_setvector` | 26 | 4.9s |  |
| 111 | `bitmapdata_sync` | 0 | 5.0s |  |
| 112 | `bitmapdata_threshold` | 176 | 5.7s |  |
| 113 | `bitnot` | 46 | 4.9s |  |
| 114 | `bitor` | 1058 | 13.9s |  |
| 115 | `bitxor` | 1058 | 13.7s |  |
| 116 | `blend_multiply_alpha` | 0 | 5.0s |  |
| 117 | `blend_scroll` | 0 | 5.0s |  |
| 118 | `boolean_constr` | 32 | 5.8s |  |
| 119 | `boolean_negation` | 30 | 5.8s |  |
| 120 | `boolean_tostring` | 8 | 5.7s |  |
| 121 | `broadcast_event` | 7 | 5.7s |  |
| 122 | `button_nested_frame` | 48 | 6.2s |  |
| 123 | `bytearray` | 48 | 5.9s |  |
| 124 | `bytearray_compress` | 31 | 5.8s |  |
| 125 | `bytearray_errors` | 24 | 5.8s |  |
| 126 | `bytearray_method_serialization` | 1 | 5.7s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 5.7s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 5.8s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 5.7s |  |
| 130 | `bytearray_serialization` | 3 | 5.7s |  |
| 131 | `bytearray_string_null` | 19 | 5.9s |  |
| 132 | `bytearray_tostring` | 15 | 5.7s |  |
| 133 | `bytearray_utf16` | 8 | 5.7s |  |
| 134 | `bytearray_writeobject` | 24 | 5.6s |  |
| 135 | `callee_in_initializer` | 6 | 5.7s |  |
| 136 | `callproplex_class` | 1 | 5.7s |  |
| 137 | `capabilities_resolution` | 8 | 24.5s |  |
| 138 | `catch_class` | 6 | 5.7s |  |
| 139 | `catch_scope_slot` | 7 | 2.9s |  |
| 140 | `checkfilter` | 4 | 2.8s |  |
| 141 | `class_call` | 32 | 24.1s |  |
| 142 | `class_cast_call` | 14 | 5.7s |  |
| 143 | `class_enumeration` | 4 | 5.7s |  |
| 144 | `class_has_own_property` | 2 | 5.7s |  |
| 145 | `class_init_interpreter_mode` | 1 | 5.6s |  |
| 146 | `class_is` | 32 | 5.8s |  |
| 147 | `class_methods` | 5 | 5.8s |  |
| 148 | `class_object_properties` | 10 | 5.8s |  |
| 149 | `class_singleton` | 18 | 5.8s |  |
| 150 | `class_supercalls_errors` | 35 | 5.9s |  |
| 151 | `class_supercalls_mismatched` | 26 | 5.8s |  |
| 152 | `class_superclass_wrong_order` | 1 | 24.7s |  |
| 153 | `class_to_locale_string` | 2 | 5.7s |  |
| 154 | `class_to_string` | 2 | 5.7s |  |
| 155 | `class_value_of` | 2 | 5.7s |  |
| 156 | `click_block` | 5 | 24.6s |  |
| 157 | `click_invisible` | 3 | 5.8s |  |
| 158 | `closures` | 12 | 5.7s |  |
| 159 | `coerce_return_type` | 40 | 5.8s |  |
| 160 | `coerce_return_type_fail` | 2 | 5.6s |  |
| 161 | `coerce_return_void` | 3 | 5.6s |  |
| 162 | `coerce_string` | 86 | 5.8s |  |
| 163 | `coerce_string_precision` | 28 | 5.7s |  |
| 164 | `coerce_to_primitive_side_effects` | 29 | 5.7s |  |
| 165 | `construct_errors_swf10` | 8 | 5.7s |  |
| 166 | `construct_frame_list` | 22 | 5.8s |  |
| 167 | `constructor_call` | 3 | 5.6s |  |
| 168 | `constructors_vs_timeline` | 5 | 25.1s |  |
| 169 | `constructprop_dynamic_primitive` | 7 | 5.8s |  |
| 170 | `control_flow_bool` | 4 | 5.7s |  |
| 171 | `control_flow_stricteq` | 8 | 5.8s |  |
| 172 | `convert_boolean` | 30 | 5.8s |  |
| 173 | `convert_integer` | 90 | 5.9s |  |
| 174 | `convert_number` | 56 | 5.9s |  |
| 175 | `convert_uinteger` | 90 | 5.9s |  |
| 176 | `cryptscore` | 11 | 6.0s |  |
| 177 | `date` | 30 | 4.8s |  |
| 178 | `date_parse` | 36 | 4.4s |  |
| 179 | `declocal` | 46 | 4.5s |  |
| 180 | `declocal_i` | 46 | 4.5s |  |
| 181 | `decode_uri` | 71 | 4.9s |  |
| 182 | `decrement` | 46 | 4.5s |  |
| 183 | `decrement_i` | 46 | 2.2s |  |
| 184 | `default_values` | 7 | 4.4s |  |
| 185 | `dictionary_access` | 62 | 4.6s |  |
| 186 | `dictionary_access_no_pubns` | 2 | 4.4s |  |
| 187 | `dictionary_delete` | 101 | 4.8s |  |
| 188 | `dictionary_foreach` | 42 | 4.6s |  |
| 189 | `dictionary_hasownproperty` | 63 | 4.7s |  |
| 190 | `dictionary_in` | 62 | 4.7s |  |
| 191 | `dictionary_iter_modify` | 8 | 4.7s |  |
| 192 | `dictionary_namespaces` | 36 | 4.5s |  |
| 193 | `dictionary_primitive_keys` | 29 | 4.8s |  |
| 194 | `displayobject_alpha` | 277 | 4.4s |  |
| 195 | `displayobject_blendmode` | 0 | 4.7s |  |
| 196 | `displayobject_colortransform_nested` | 0 | 19.2s |  |
| 197 | `displayobject_from_enterframe` | 1 | 4.5s |  |
| 198 | `displayobject_getbounds_shape` | 0 | 19.2s |  |
| 199 | `displayobject_height` | 6052 | 19.2s |  |
| 200 | `displayobject_hittestobject` | 32 | 4.6s |  |
| 201 | `displayobject_invalid_floats` | 60 | 4.5s |  |
| 202 | `displayobject_invalid_props` | 3 | 4.4s |  |
| 203 | `displayobject_mask` | 3 | 4.8s |  |
| 204 | `displayobject_mask_self_referential` | 0 | 4.4s |  |
| 205 | `displayobject_metaData` | 3 | 5.7s |  |
| 206 | `displayobject_name` | 22 | 6.2s |  |
| 207 | `displayobject_name_from_timeline` | 24 | 6.0s |  |
| 208 | `displayobject_parent` | 12 | 5.8s |  |
| 209 | `displayobject_root` | 24 | 5.9s |  |
| 210 | `displayobject_rotation` | 1284 | 6.0s |  |
| 211 | `displayobject_set_matrix_nested` | 0 | 26.3s |  |
| 212 | `displayobject_subclass` | 2 | 5.9s |  |
| 213 | `displayobject_visible` | 23 | 5.9s |  |
| 214 | `displayobject_width` | 4852 | 25.9s |  |
| 215 | `displayobject_x` | 614 | 5.9s |  |
| 216 | `displayobject_y` | 617 | 5.9s |  |
| 217 | `displayobjectcontainer_addchild` | 32 | 6.0s |  |
| 218 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.9s |  |
| 219 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.1s |  |
| 220 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.0s |  |
| 221 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.0s |  |
| 222 | `displayobjectcontainer_addchildat` | 42 | 5.9s |  |
| 223 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.0s |  |
| 224 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.9s |  |
| 225 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.9s |  |
| 226 | `displayobjectcontainer_contains` | 66 | 25.8s |  |
| 227 | `displayobjectcontainer_getchildat` | 4 | 5.9s |  |
| 228 | `displayobjectcontainer_getchildbyname` | 9 | 5.8s |  |
| 229 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.8s |  |
| 230 | `displayobjectcontainer_getchildindex` | 28 | 5.9s |  |
| 231 | `displayobjectcontainer_removechild` | 10 | 5.8s |  |
| 232 | `displayobjectcontainer_removechild_errors` | 4 | 5.8s |  |
| 233 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.9s |  |
| 234 | `displayobjectcontainer_removechildat` | 18 | 5.9s |  |
| 235 | `displayobjectcontainer_removechildren` | 51 | 6.1s |  |
| 236 | `displayobjectcontainer_setchildindex` | 42 | 5.7s |  |
| 237 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.2s |  |
| 238 | `displayobjectcontainer_swapchildren` | 42 | 5.9s |  |
| 239 | `displayobjectcontainer_swapchildrenat` | 42 | 5.9s |  |
| 240 | `displayobjectcontainer_timelineinstance` | 48 | 25.9s |  |
| 241 | `divide` | 1058 | 18.1s |  |
| 242 | `doabc_is_eager` | 1 | 24.2s |  |
| 243 | `documentclass` | 9 | 5.8s |  |
| 244 | `drag_drop` | 10 | 5.8s |  |
| 245 | `duplicate_defs` | 1 | 5.6s |  |
| 246 | `eager_init` | 1 | 5.6s |  |
| 247 | `edit_text_linkage` | 7 | 5.9s |  |
| 248 | `edittext_align` | 60 | 6.2s |  |
| 249 | `edittext_always_show_selection` | 0 | 25.5s |  |
| 250 | `edittext_antialiastype` | 296 | 6.0s |  |
| 251 | `edittext_at_point_methods_basic` | 16 | 7.2s |  |
| 252 | `edittext_autosize` | 39 | 6.1s |  |
| 253 | `edittext_autosize_align` | 0 | 25.6s |  |
| 254 | `edittext_autosize_height_dynamic` | 60 | 25.1s |  |
| 255 | `edittext_autosize_height_input` | 60 | 5.8s |  |
| 256 | `edittext_autosize_lazy_bounds_events` | 65 | 6.0s |  |
| 257 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.7s |  |
| 258 | `edittext_autosize_lazy_bounds_props` | 490 | 7.2s |  |
| 259 | `edittext_autosize_lazy_bounds_visual` | 0 | 5.9s |  |
| 260 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.9s |  |
| 261 | `edittext_bottom_scroll_v_basic` | 210 | 5.8s |  |
| 262 | `edittext_bounds_scale` | 24 | 24.2s |  |
| 263 | `edittext_bullet` | 30 | 5.8s |  |
| 264 | `edittext_default_format` | 221 | 6.0s |  |
| 265 | `edittext_default_format_empty` | 136 | 6.1s |  |
| 266 | `edittext_empty_text_format` | 7 | 5.8s |  |
| 267 | `edittext_focus_selection` | 5 | 5.7s |  |
| 268 | `edittext_font_size` | 45 | 5.7s |  |
| 269 | `edittext_format_empty_font` | 8 | 5.6s |  |
| 270 | `edittext_get_char_index_at_point` | 4 | 25.9s |  |
| 271 | `edittext_get_line_index_at_point` | 2 | 25.0s |  |
| 272 | `edittext_get_line_index_of_char` | 76 | 6.7s |  |
| 273 | `edittext_getcharboundaries` | 172 | 6.1s |  |
| 274 | `edittext_getcharboundaries_missing_glyphs` | 63 | 39.6s |  |
| 275 | `edittext_getcharboundaries_scroll` | 85 | 6.3s |  |
| 276 | `edittext_getlinemetrics` | 146 | 6.3s |  |
| 277 | `edittext_html` | 3101 | 6.6s |  |
| 278 | `edittext_html_condensewhite` | 487 | 6.1s |  |
| 279 | `edittext_html_entity` | 4 | 6.3s |  |
| 280 | `edittext_html_font_size_swf12` | 267 | 6.2s |  |
| 281 | `edittext_html_font_size_swf13` | 273 | 5.8s |  |
| 282 | `edittext_html_roundtrip` | 17 | 6.1s |  |
| 283 | `edittext_input_control` | 12 | 6.2s |  |
| 284 | `edittext_leading` | 9 | 6.3s |  |
| 285 | `edittext_letter_spacing` | 15 | 6.0s |  |
| 286 | `edittext_line_methods` | 294 | 7.6s |  |
| 287 | `edittext_line_metrics` | 11 | 28.4s |  |
| 288 | `edittext_margins` | 25 | 6.2s |  |
| 289 | `edittext_max_scroll_h_basic` | 475 | 6.3s |  |
| 290 | `edittext_max_scroll_v_basic` | 1000 | 6.2s |  |
| 291 | `edittext_mousedown` | 3 | 6.4s |  |
| 292 | `edittext_mouseenabled` | 26 | 6.1s |  |
| 293 | `edittext_newline_character` | 22 | 6.1s |  |
| 294 | `edittext_newline_stripping` | 64 | 8.8s |  |
| 295 | `edittext_newlines` | 30 | 6.1s |  |
| 296 | `edittext_paragraph_methods` | 257 | 6.1s |  |
| 297 | `edittext_paste_events` | 8 | 6.2s |  |
| 298 | `edittext_paste_maxchars` | 4 | 6.1s |  |
| 299 | `edittext_paste_restrict` | 16 | 6.0s |  |
| 300 | `edittext_restrict` | 191 | 6.1s |  |
| 301 | `edittext_restrict_events` | 22 | 6.0s |  |
| 302 | `edittext_scrollh` | 10 | 6.0s |  |
| 303 | `edittext_selected_text` | 9 | 6.0s |  |
| 304 | `edittext_set_html_same` | 17 | 6.1s |  |
| 305 | `edittext_set_text_vs_html` | 9 | 6.0s |  |
| 306 | `edittext_stylesheet` | 536 | 6.5s |  |
| 307 | `edittext_stylesheet_custom_tag` | 76 | 6.2s |  |
| 308 | `edittext_stylesheet_display` | 272 | 6.2s |  |
| 309 | `edittext_underline` | 40 | 6.2s |  |
| 310 | `edittext_width_height` | 103 | 6.4s |  |
| 311 | `edittext_wordwrap_word` | 150 | 15.4s |  |
| 312 | `edittext_wrap_breaks` | 2375 | 5.0s |  |
| 313 | `empty_bounds` | 1 | 4.6s |  |
| 314 | `encode_uri_surrogate_pair_swf11` | 15 | 4.5s |  |
| 315 | `equals` | 512 | 7.2s |  |
| 316 | `error_prototype` | 15 | 4.7s |  |
| 317 | `error_stack_trace_debug_swf17` | 0 | 21.6s |  |
| 318 | `error_stack_trace_debug_swf18` | 0 | 4.7s |  |
| 319 | `error_stack_trace_release_swf17` | 0 | 4.5s |  |
| 320 | `error_stack_trace_release_swf18` | 0 | 4.4s |  |
| 321 | `error_tostring` | 29 | 4.6s |  |
| 322 | `es3_inheritance` | 31 | 4.6s |  |
| 323 | `es4_inheritance` | 30 | 4.7s |  |
| 324 | `es4_interfaces` | 30 | 4.6s |  |
| 325 | `es4_method_binding` | 8 | 4.7s |  |
| 326 | `es4_oop_prototypes` | 14 | 5.0s |  |
| 327 | `es4_protected_inheritance` | 6 | 4.8s |  |
| 328 | `escape` | 71 | 4.8s |  |
| 329 | `event_bubbles` | 2 | 4.6s |  |
| 330 | `event_cancelable` | 2 | 4.6s |  |
| 331 | `event_clone` | 20 | 4.7s |  |
| 332 | `event_clone_error_redispatch` | 3 | 4.7s |  |
| 333 | `event_clone_on_redispatch` | 10 | 4.9s |  |
| 334 | `event_formattostring` | 31 | 4.9s |  |
| 335 | `event_isdefaultprevented` | 12 | 4.7s |  |
| 336 | `event_target_getter` | 5 | 2.3s |  |
| 337 | `event_target_set` | 9 | 4.6s |  |
| 338 | `event_type` | 1 | 4.8s |  |
| 339 | `event_valueof_tostring` | 18 | 17.5s |  |
| 340 | `eventdispatcher_dispatchevent` | 12 | 5.8s |  |
| 341 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.8s |  |
| 342 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.8s |  |
| 343 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.8s |  |
| 344 | `eventdispatcher_dispatchevent_this` | 5 | 5.7s |  |
| 345 | `eventdispatcher_haseventlistener` | 25 | 5.8s |  |
| 346 | `eventdispatcher_interface_invoke` | 1 | 5.6s |  |
| 347 | `eventdispatcher_tostring` | 10 | 5.7s |  |
| 348 | `eventdispatcher_willtrigger` | 25 | 5.6s |  |
| 349 | `falsiness` | 30 | 5.7s |  |
| 350 | `fast_index_access` | 12 | 5.9s |  |
| 351 | `finddef` | 3 | 5.7s |  |
| 352 | `findprop_global_prototype` | 6 | 5.8s |  |
| 353 | `flash_xml` | 29 | 5.8s |  |
| 354 | `flash_xml_cloneNode` | 22 | 5.8s |  |
| 355 | `flash_xml_namespace` | 109 | 5.8s |  |
| 356 | `flash_xml_removeNode` | 60 | 5.8s |  |
| 357 | `focus_events_code` | 161 | 25.1s |  |
| 358 | `focus_events_key_same_object` | 26 | 5.8s |  |
| 359 | `focus_events_mixed_key_mouse` | 100 | 25.0s |  |
| 360 | `focus_events_mouse_same_object` | 40 | 5.7s |  |
| 361 | `focus_remove` | 20 | 24.0s |  |
| 362 | `focus_root_movie` | 4 | 24.0s |  |
| 363 | `focus_stage` | 1 | 5.6s |  |
| 364 | `focusrect` | 18 | 6.4s |  |
| 365 | `font_description_clone` | 14 | 5.5s |  |
| 366 | `font_embedded` | 24 | 5.9s |  |
| 367 | `font_enumeratefonts` | 41 | 6.2s |  |
| 368 | `font_enumeratefonts_filter` | 4 | 24.3s |  |
| 369 | `font_hasglyphs` | 40 | 6.0s |  |
| 370 | `framelabel_constr` | 5 | 5.7s |  |
| 371 | `function_call` | 12 | 5.6s |  |
| 372 | `function_call_arguments` | 46 | 5.6s |  |
| 373 | `function_call_arguments_enumerate` | 5 | 5.5s |  |
| 374 | `function_call_coercion` | 108 | 5.9s |  |
| 375 | `function_call_default` | 6 | 5.5s |  |
| 376 | `function_call_rest` | 22 | 5.5s |  |
| 377 | `function_call_types` | 3 | 5.5s |  |
| 378 | `function_call_via_apply` | 11 | 5.5s |  |
| 379 | `function_call_via_call` | 3 | 5.5s |  |
| 380 | `function_display_anonymous` | 7 | 2.7s |  |
| 381 | `function_length` | 6 | 5.5s |  |
| 382 | `function_object` | 2 | 5.5s |  |
| 383 | `function_proto` | 5 | 5.5s |  |
| 384 | `function_proto_created` | 61 | 5.5s |  |
| 385 | `function_to_locale_string` | 4 | 5.5s |  |
| 386 | `function_to_string` | 4 | 5.4s |  |
| 387 | `function_type` | 6 | 5.5s |  |
| 388 | `function_unbound_this` | 51 | 5.6s |  |
| 389 | `function_value_of` | 4 | 5.5s |  |
| 390 | `get_definition_by_name` | 11 | 5.5s |  |
| 391 | `get_qualified_class_name` | 20 | 5.6s |  |
| 392 | `get_qualified_super_class_name` | 18 | 16.9s |  |
| 393 | `get_slot_edge_cases` | 1 | 23.4s |  |
| 394 | `get_timer` | 2 | 5.3s |  |
| 395 | `getglobalslot` | 1 | 5.3s |  |
| 396 | `getouterscope` | 8 | 5.3s |  |
| 397 | `getter_different_namespace_setter` | 2 | 5.2s |  |
| 398 | `goto_button_nested_framescript` | 28 | 5.6s |  |
| 399 | `goto_in_constructframe` | 12 | 5.5s |  |
| 400 | `goto_in_scene_last_frame` | 2 | 23.5s |  |
| 401 | `goto_methods` | 56 | 5.5s |  |
| 402 | `goto_methods_swfver10` | 8 | 5.4s |  |
| 403 | `goto_nested_construct_sibling` | 18 | 5.8s |  |
| 404 | `goto_nested_framescript` | 9 | 5.5s |  |
| 405 | `goto_on_orphan` | 15 | 5.5s |  |
| 406 | `graphics_bad_direct_commands` | 5 | 6.1s |  |
| 407 | `graphics_bitmap_fill` | 0 | 7.2s |  |
| 408 | `graphics_bitmaps` | 0 | 6.1s |  |
| 409 | `graphics_direct_commands` | 0 | 6.0s |  |
| 410 | `graphics_draw_triangles` | 98 | 24.4s |  |
| 411 | `graphics_gradients` | 0 | 5.7s |  |
| 412 | `graphics_gradients_nulls` | 0 | 5.7s |  |
| 413 | `graphics_path` | 56 | 5.3s |  |
| 414 | `graphics_round_rects` | 0 | 5.4s |  |
| 415 | `graphics_simple_shapes` | 0 | 5.7s |  |
| 416 | `greaterequals` | 512 | 9.3s |  |
| 417 | `greaterthan` | 512 | 9.4s |  |
| 418 | `has_own_property` | 102 | 5.8s |  |
| 419 | `hasownproperty_namespaces` | 2 | 5.3s |  |
| 420 | `hello_world` | 1 | 5.3s |  |
| 421 | `hittest_morph` | 30 | 5.5s |  |
| 422 | `if_eq` | 10 | 5.3s |  |
| 423 | `if_gt` | 1 | 5.3s |  |
| 424 | `if_gte` | 10 | 2.5s |  |
| 425 | `if_lt` | 1 | 13.6s |  |
| 426 | `if_lte` | 10 | 4.6s |  |
| 427 | `if_ne` | 7 | 2.3s |  |
| 428 | `if_stricteq` | 6 | 4.6s |  |
| 429 | `if_strictne` | 11 | 4.6s |  |
| 430 | `in` | 102 | 5.0s |  |
| 431 | `inclocal` | 46 | 4.6s |  |
| 432 | `inclocal_i` | 46 | 4.6s |  |
| 433 | `increment` | 46 | 4.6s |  |
| 434 | `increment_i` | 46 | 4.6s |  |
| 435 | `instanceof` | 58 | 4.7s |  |
| 436 | `instantiation_on_enter_frame` | 7 | 19.6s |  |
| 437 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.5s |  |
| 438 | `int_constr` | 92 | 4.7s |  |
| 439 | `int_edge_cases` | 19 | 4.6s |  |
| 440 | `int_instanceof` | 3 | 4.5s |  |
| 441 | `int_tofixed` | 1215 | 4.5s |  |
| 442 | `int_tostring` | 3375 | 4.8s |  |
| 443 | `interactiveobject_enabled` | 25 | 4.5s |  |
| 444 | `interface_namespaces` | 78 | 4.7s |  |
| 445 | `is_finite` | 46 | 4.6s |  |
| 446 | `is_nan` | 46 | 4.5s |  |
| 447 | `is_prototype_of` | 12 | 4.6s |  |
| 448 | `issue_10221` | 2 | 4.5s |  |
| 449 | `issue_13780` | 12 | 4.6s |  |
| 450 | `issue_14901` | 1 | 4.5s |  |
| 451 | `issue_17675_edittext_paste_maxchars` | 1 | 4.6s |  |
| 452 | `issue_5292` | 5 | 4.5s |  |
| 453 | `issue_8630` | 2 | 19.3s |  |
| 454 | `issue_8630_scriptremove` | 11 | 4.5s |  |
| 455 | `istype` | 24 | 2.3s |  |
| 456 | `istypelate` | 58 | 4.7s |  |
| 457 | `istypelate_coerce` | 198 | 5.2s |  |
| 458 | `json_errors` | 9 | 23.8s |  |
| 459 | `json_parse` | 21 | 5.6s |  |
| 460 | `json_stringify` | 12 | 5.8s |  |
| 461 | `json_stringify_order` | 1 | 5.5s |  |
| 462 | `json_version_gated` | 1 | 5.5s |  |
| 463 | `key_input_80percent` | 1812 | 5.8s |  |
| 464 | `key_input_location` | 126 | 5.7s |  |
| 465 | `key_input_numpad` | 384 | 5.6s |  |
| 466 | `lazyinit` | 17 | 5.6s |  |
| 467 | `lessequals` | 512 | 9.7s |  |
| 468 | `lessthan` | 512 | 9.7s |  |
| 469 | `loaderinfo_properties` | 18 | 5.9s |  |
| 470 | `loaderinfo_root` | 10 | 5.8s |  |
| 471 | `loaderinfo_root_allows` | 2 | 5.7s |  |
| 472 | `lshift` | 1058 | 18.2s |  |
| 473 | `mask_reapply` | 1 | 5.9s |  |
| 474 | `math` | 497 | 6.0s |  |
| 475 | `missing_external_interface` | 10 | 5.8s |  |
| 476 | `modulo` | 1058 | 18.3s |  |
| 477 | `morph_shape` | 2 | 25.6s |  |
| 478 | `mouse_click_events` | 90 | 25.1s |  |
| 479 | `mouse_double_click_events` | 188 | 5.8s |  |
| 480 | `mouse_empty_parent` | 4 | 5.8s |  |
| 481 | `mouse_over_while_dragging` | 3 | 5.9s |  |
| 482 | `mouse_pick_button_mode` | 2 | 6.0s |  |
| 483 | `mouse_sibling` | 8 | 5.9s |  |
| 484 | `movieclip_addframescript` | 3 | 25.1s |  |
| 485 | `movieclip_child_property` | 16 | 5.9s |  |
| 486 | `movieclip_constr` | 21 | 5.8s |  |
| 487 | `movieclip_currentlabels` | 17 | 35.3s |  |
| 488 | `movieclip_currentlabels_dupes1` | 46 | 24.6s |  |
| 489 | `movieclip_currentlabels_dupes2` | 30 | 5.6s |  |
| 490 | `movieclip_currentlabels_dupes3` | 67 | 5.6s |  |
| 491 | `movieclip_currentscene` | 12 | 5.7s |  |
| 492 | `movieclip_dispatchevent` | 430 | 5.8s |  |
| 493 | `movieclip_dispatchevent_cancel` | 102 | 5.7s |  |
| 494 | `movieclip_dispatchevent_handlerorder` | 251 | 5.7s |  |
| 495 | `movieclip_dispatchevent_selfadd` | 80 | 5.6s |  |
| 496 | `movieclip_dispatchevent_target` | 899 | 5.7s |  |
| 497 | `movieclip_displayevents` | 96 | 25.1s |  |
| 498 | `movieclip_displayevents_clickgoto` | 676 | 6.1s |  |
| 499 | `movieclip_displayevents_clickgoto2` | 2001 | 6.1s |  |
| 500 | `movieclip_displayevents_clickplay` | 575 | 5.8s |  |
| 501 | `movieclip_displayevents_clicksymbol` | 562 | 5.8s |  |
| 502 | `movieclip_displayevents_constructframegoto` | 140 | 6.0s |  |
| 503 | `movieclip_displayevents_constructframeplay` | 50 | 5.9s |  |
| 504 | `movieclip_displayevents_constructframesymbol` | 144 | 5.8s |  |
| 505 | `movieclip_displayevents_dblhandler` | 21 | 5.7s |  |
| 506 | `movieclip_displayevents_enterframegoto` | 149 | 5.9s |  |
| 507 | `movieclip_displayevents_enterframeplay` | 48 | 5.7s |  |
| 508 | `movieclip_displayevents_enterframesymbol` | 149 | 24.4s |  |
| 509 | `movieclip_displayevents_exitframegoto` | 106 | 5.9s |  |
| 510 | `movieclip_displayevents_exitframeplay` | 44 | 5.8s |  |
| 511 | `movieclip_displayevents_exitframesymbol` | 135 | 5.9s |  |
| 512 | `movieclip_displayevents_looping` | 63 | 24.4s |  |
| 513 | `movieclip_displayevents_stopped` | 113 | 6.0s |  |
| 514 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 515 | `movieclip_displayevents_timeline` | 128 | 24.8s |  |
| 516 | `movieclip_drawrect` | 54 | 5.7s |  |
| 517 | `movieclip_frameconstruct_skipped` | 9 | 5.8s |  |
| 518 | `movieclip_goto_during_frame_script` | 15 | 5.7s |  |
| 519 | `movieclip_goto_overwrite` | 14 | 23.9s |  |
| 520 | `movieclip_goto_scene_last_frame_int` | 1 | 24.7s |  |
| 521 | `movieclip_goto_scene_last_frame_label` | 1 | 5.6s |  |
| 522 | `movieclip_gotoandplay` | 15 | 23.8s |  |
| 523 | `movieclip_gotoandstop` | 13 | 5.6s |  |
| 524 | `movieclip_gotoandstop_children` | 4 | 5.7s |  |
| 525 | `movieclip_gotoandstop_framescripts1` | 4 | 5.6s |  |
| 526 | `movieclip_gotoandstop_framescripts2` | 4 | 2.7s |  |
| 527 | `movieclip_gotoandstop_framescripts_self` | 7 | 5.7s |  |
| 528 | `movieclip_gotoandstop_queueing` | 12 | 29.9s |  |
| 529 | `movieclip_next_frame` | 2 | 4.5s |  |
| 530 | `movieclip_next_scene` | 6 | 20.0s |  |
| 531 | `movieclip_play` | 3 | 4.3s |  |
| 532 | `movieclip_prev_frame` | 3 | 4.3s |  |
| 533 | `movieclip_prev_scene` | 7 | 4.4s |  |
| 534 | `movieclip_properties` | 79 | 4.6s |  |
| 535 | `movieclip_queued_noop_goto_swf10` | 9 | 4.5s |  |
| 536 | `movieclip_queued_noop_goto_swf9` | 7 | 0.8s |  |
| 537 | `movieclip_scenes` | 11 | 4.4s |  |
| 538 | `movieclip_soundtransform` | 831 | 21.7s |  |
| 539 | `movieclip_stop` | 1 | 4.4s |  |
| 540 | `movieclip_super_is_symbol` | 20 | 4.6s |  |
| 541 | `movieclip_symbol_constr` | 8 | 4.5s |  |
| 542 | `movieclip_text_mousedown` | 1 | 4.6s |  |
| 543 | `movieclip_willtrigger` | 5 | 4.6s |  |
| 544 | `multiply` | 1058 | 12.4s |  |
| 545 | `namespace_constr` | 253 | 4.7s |  |
| 546 | `namespace_constr_args` | 1 | 4.4s |  |
| 547 | `namespace_enumeration_order` | 7 | 4.3s |  |
| 548 | `nan_scale` | 9 | 4.4s |  |
| 549 | `negate` | 30 | 4.5s |  |
| 550 | `negative_volume_panned` | 0 | 4.5s |  |
| 551 | `nested_iteration` | 11 | 4.4s |  |
| 552 | `net_getClassByAlias` | 3 | 4.4s |  |
| 553 | `newactivation_in_script_init` | 3 | 5.5s |  |
| 554 | `newclass_twice` | 3 | 5.3s |  |
| 555 | `nonconflicting_declarations` | 0 | 5.5s |  |
| 556 | `null_void_types` | 8 | 5.5s |  |
| 557 | `number_autoconv` | 21 | 5.5s |  |
| 558 | `number_autoconv_amf` | 132 | 5.5s |  |
| 559 | `number_autoconv_array_sort_32bit` | 1 | 5.4s |  |
| 560 | `number_constr` | 58 | 5.6s |  |
| 561 | `number_toexponential` | 378 | 5.5s |  |
| 562 | `number_toexponential2` | 35 | 5.4s |  |
| 563 | `number_tofixed` | 378 | 5.4s |  |
| 564 | `number_toprecision` | 350 | 5.5s |  |
| 565 | `obfuscated_class_names` | 3 | 5.4s |  |
| 566 | `object_enumeration` | 10 | 5.4s |  |
| 567 | `object_prototype` | 4 | 5.5s |  |
| 568 | `object_to_locale_string` | 2 | 5.4s |  |
| 569 | `object_to_string` | 2 | 5.4s |  |
| 570 | `object_value_of` | 2 | 2.5s |  |
| 571 | `op_coerce` | 54 | 5.5s |  |
| 572 | `op_coerce_x` | 54 | 5.5s |  |
| 573 | `op_escxattr` | 2 | 5.4s |  |
| 574 | `op_escxelem` | 2 | 5.4s |  |
| 575 | `op_lookupswitch` | 4 | 5.4s |  |
| 576 | `optimize_coerce` | 1 | 5.4s |  |
| 577 | `orphan_movie_complex` | 80 | 5.8s |  |
| 578 | `orphan_movie_reorder` | 111 | 23.8s |  |
| 579 | `package_namespace` | 7 | 5.3s |  |
| 580 | `param_default_value_has_zero_cpool_index` | 1 | 5.2s |  |
| 581 | `parent_early_access_child` | 16 | 5.7s |  |
| 582 | `parse_float` | 81 | 5.7s |  |
| 583 | `pixelbender_effect_BlurredFocus` | 0 | 28.7s |  |
| 584 | `pixelbender_effect_glassDisplace` | 0 | 11.5s |  |
| 585 | `pixelbender_effect_smudge` | 0 | 9.4s |  |
| 586 | `pixelbender_effect_tintype` | 0 | 8.5s |  |
| 587 | `pixelbender_effect_twirl` | 0 | 9.4s |  |
| 588 | `pixelbender_images` | 0 | 8.1s |  |
| 589 | `place_multiple` | 17 | 23.9s |  |
| 590 | `place_object_replace` | 9 | 5.7s |  |
| 591 | `place_object_replace_2` | 24 | 5.8s |  |
| 592 | `place_object_same_depth_frame` | 1 | 5.7s |  |
| 593 | `point` | 132 | 6.2s |  |
| 594 | `primitive_edge_cases` | 1 | 5.6s |  |
| 595 | `property_priority` | 22 | 6.1s |  |
| 596 | `property_priority_three_level` | 6 | 24.8s |  |
| 597 | `propertyisenumerable_namespaces` | 6 | 5.8s |  |
| 598 | `prototype_set_null` | 7 | 5.8s |  |
| 599 | `proxy_callproperty` | 24 | 5.6s |  |
| 600 | `proxy_deleteproperty` | 64 | 5.6s |  |
| 601 | `proxy_enumeration` | 34 | 5.6s |  |
| 602 | `proxy_getproperty` | 77 | 5.7s |  |
| 603 | `proxy_hasownproperty` | 8 | 5.6s |  |
| 604 | `proxy_hasproperty` | 32 | 5.8s |  |
| 605 | `proxy_serialize` | 9 | 5.7s |  |
| 606 | `proxy_setproperty` | 42 | 5.8s |  |
| 607 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.6s |  |
| 608 | `qname_constr` | 32 | 5.8s |  |
| 609 | `qname_constr_namespace` | 24 | 5.9s |  |
| 610 | `qname_enumeration` | 9 | 5.9s |  |
| 611 | `qname_indexing` | 23 | 5.8s |  |
| 612 | `qname_tostring` | 25 | 5.7s |  |
| 613 | `qname_valueof` | 29 | 5.7s |  |
| 614 | `regexp_constr` | 148 | 5.9s |  |
| 615 | `regexp_exec` | 19 | 5.7s |  |
| 616 | `regexp_extended` | 47 | 5.6s |  |
| 617 | `regexp_multiargs` | 1 | 5.5s |  |
| 618 | `regexp_test` | 27 | 5.7s |  |
| 619 | `regexp_toString` | 10 | 5.6s |  |
| 620 | `register_script_refresh` | 35 | 5.9s |  |
| 621 | `remove_child_clear_field` | 88 | 5.9s |  |
| 622 | `remove_dobj` | 3 | 5.5s |  |
| 623 | `resolve_order` | 4 | 5.5s |  |
| 624 | `rng` | 1 | 6.7s |  |
| 625 | `rootless` | 42 | 5.6s |  |
| 626 | `rshift` | 1058 | 30.5s |  |
| 627 | `sandbox_type_local_file` | 1 | 6.1s |  |
| 628 | `scene_constr` | 8 | 6.0s |  |
| 629 | `set_local_0` | 31 | 5.6s |  |
| 630 | `set_property_is_enumerable` | 85 | 6.0s |  |
| 631 | `shape_drawrect` | 54 | 5.7s |  |
| 632 | `shared_object_no_root` | 3 | 5.5s |  |
| 633 | `simplebutton_added_to_stage` | 45 | 23.9s |  |
| 634 | `simplebutton_childevents` | 86 | 6.0s |  |
| 635 | `simplebutton_childevents_nested` | 54 | 5.9s |  |
| 636 | `simplebutton_childevents_sprite` | 13 | 5.7s |  |
| 637 | `simplebutton_childprops` | 144 | 5.8s |  |
| 638 | `simplebutton_childshuffle` | 23 | 5.5s |  |
| 639 | `simplebutton_constr` | 36 | 6.0s |  |
| 640 | `simplebutton_constr_childevents` | 48 | 6.2s |  |
| 641 | `simplebutton_constr_params` | 42 | 5.9s |  |
| 642 | `simplebutton_mouseenabled` | 26 | 5.8s |  |
| 643 | `simplebutton_multi_children` | 19 | 6.4s |  |
| 644 | `simplebutton_structure` | 27 | 6.2s |  |
| 645 | `simplebutton_symbolclass` | 68 | 6.6s |  |
| 646 | `slot_disp_id_shared_numbering` | 1 | 26.7s |  |
| 647 | `slots_force_autoassigned` | 1 | 5.7s |  |
| 648 | `sound_embeddedprops` | 26 | 5.7s |  |
| 649 | `sound_play` | 19 | 5.8s |  |
| 650 | `sound_valueof` | 33 | 5.6s |  |
| 651 | `soundchannel_soundtransform` | 835 | 25.8s |  |
| 652 | `soundchannel_soundtransform_exists` | 5 | 23.8s |  |
| 653 | `soundchannel_stop` | 8 | 5.8s |  |
| 654 | `soundmixer_buffertime` | 5 | 5.5s |  |
| 655 | `soundmixer_stopall` | 6 | 5.7s |  |
| 656 | `soundtransform` | 442 | 11.5s |  |
| 657 | `sprite_with_frames` | 0 | 6.2s |  |
| 658 | `stage3d_agal_cross_product` | 0 | 8.3s |  |
| 659 | `stage3d_bitmap` | 0 | 29.4s |  |
| 660 | `stage3d_float1_index` | 0 | 26.4s |  |
| 661 | `stage3d_fractal` | 0 | 8.7s |  |
| 662 | `stage3d_ignore_sampler_override` | 0 | 27.5s |  |
| 663 | `stage3d_program_constants_bytearray_be` | 0 | 28.6s |  |
| 664 | `stage3d_program_constants_bytearray_le` | 0 | 9.4s |  |
| 665 | `stage3d_raytrace` | 0 | 42.2s |  |
| 666 | `stage3d_rotating_cube` | 0 | 9.6s |  |
| 667 | `stage3d_sampler` | 0 | 8.2s |  |
| 668 | `stage3d_sampler_partial_upload` | 0 | 8.0s |  |
| 669 | `stage3d_stencil` | 0 | 28.2s |  |
| 670 | `stage3d_texture` | 0 | 12.9s |  |
| 671 | `stage3d_texture_bytearray` | 0 | 9.2s |  |
| 672 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.6s |  |
| 673 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.9s |  |
| 674 | `stage3d_triangle` | 0 | 8.2s |  |
| 675 | `stage3d_triangle_bytes4` | 0 | 8.1s |  |
| 676 | `stage3d_triangle_float1` | 0 | 8.0s |  |
| 677 | `stage3d_triangle_index_upload` | 0 | 8.0s |  |
| 678 | `stage_access` | 10 | 5.5s |  |
| 679 | `stage_displayobject_properties` | 24 | 5.4s |  |
| 680 | `stage_framerate_nan` | 7 | 5.5s |  |
| 681 | `stage_framerate_negative` | 6 | 5.4s |  |
| 682 | `stage_framerate_zero` | 6 | 5.4s |  |
| 683 | `stage_invalidate` | 38 | 5.6s |  |
| 684 | `stage_mousechildren` | 2 | 5.4s |  |
| 685 | `stage_mouseenabled` | 15 | 5.4s |  |
| 686 | `stage_overriden_setters` | 31 | 5.6s |  |
| 687 | `stage_properties` | 30 | 5.4s |  |
| 688 | `static_var_with_this_in_ctor` | 2 | 5.5s |  |
| 689 | `stored_properties` | 11 | 5.8s |  |
| 690 | `strict_equality` | 34 | 5.5s |  |
| 691 | `string_call` | 13 | 7.8s |  |
| 692 | `string_case` | 23 | 5.7s |  |
| 693 | `string_char_at` | 27 | 5.4s |  |
| 694 | `string_char_code_at` | 28 | 5.3s |  |
| 695 | `string_concat_fromcharcode` | 37 | 34.8s |  |
| 696 | `string_constr` | 25 | 5.5s |  |
| 697 | `string_indexof_lastindexof` | 87 | 5.6s |  |
| 698 | `string_length` | 16 | 5.5s |  |
| 699 | `string_locale_compare` | 39 | 5.8s |  |
| 700 | `string_match` | 51 | 5.7s |  |
| 701 | `string_relational_compare` | 4 | 5.5s |  |
| 702 | `string_replace` | 51 | 5.7s |  |
| 703 | `string_search` | 41 | 5.7s |  |
| 704 | `string_slice_substr_substring` | 170 | 6.6s |  |
| 705 | `string_split` | 29 | 5.5s |  |
| 706 | `string_substr_negative` | 21 | 5.4s |  |
| 707 | `string_substr_weird` | 182 | 5.4s |  |
| 708 | `subtract` | 1058 | 17.4s |  |
| 709 | `super_get_call` | 12 | 5.5s |  |
| 710 | `supercall_two_classobjects` | 2 | 5.5s |  |
| 711 | `swf8` | 1 | 5.3s |  |
| 712 | `swf_10_queued_goto_scripts_construct` | 52 | 5.8s |  |
| 713 | `swf_9_goto_in_enter_frame` | 17 | 5.6s |  |
| 714 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.6s |  |
| 715 | `swf_9_queued_goto_scripts` | 6 | 5.6s |  |
| 716 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 717 | `swf_9_versioning` | 2 | 5.4s |  |
| 718 | `swf_wrong_frame_count` | 38 | 5.7s |  |
| 719 | `swf_wrong_frame_count_isplaying` | 22 | 5.5s |  |
| 720 | `symbol_class_binary_data` | 8 | 5.5s |  |
| 721 | `symbol_class_conflict` | 4 | 6.0s |  |
| 722 | `symbol_class_root_not_zero` | 1 | 5.4s |  |
| 723 | `symbolclass_invalid_utf8` | 2 | 5.4s |  |
| 724 | `tab_ordering_automatic_advanced` | 184 | 6.5s |  |
| 725 | `tab_ordering_automatic_basic` | 45 | 5.9s |  |
| 726 | `tab_ordering_children` | 116 | 6.0s |  |
| 727 | `tab_ordering_custom_basic` | 34 | 5.9s |  |
| 728 | `text_engine_fontdescription` | 27 | 6.2s |  |
| 729 | `text_run` | 7 | 5.7s |  |
| 730 | `textfield_focusin_event` | 9 | 5.9s |  |
| 731 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 732 | `textfield_unload` | 39 | 25.0s |  |
| 733 | `textformat` | 1134 | 5.8s |  |
| 734 | `textformat_display` | 14 | 5.9s |  |
| 735 | `textformat_font_max_length` | 4 | 5.8s |  |
| 736 | `throw` | 3 | 6.0s |  |
| 737 | `timeline_scripts` | 3 | 6.1s |  |
| 738 | `timer` | 90 | 6.6s |  |
| 739 | `timer_events` | 3 | 6.2s |  |
| 740 | `timer_finished` | 11 | 6.1s |  |
| 741 | `timer_reset` | 8 | 6.0s |  |
| 742 | `timer_setdelay` | 5 | 6.0s |  |
| 743 | `trace` | 12 | 5.9s |  |
| 744 | `truthiness` | 30 | 17.0s |  |
| 745 | `try_catch` | 11 | 4.9s |  |
| 746 | `try_catch_typed` | 12 | 4.8s |  |
| 747 | `typeof` | 30 | 4.8s |  |
| 748 | `uint_constr` | 92 | 4.9s |  |
| 749 | `uint_tofixed` | 1215 | 4.5s |  |
| 750 | `uint_tostring` | 3375 | 4.9s |  |
| 751 | `unchecked_function` | 15 | 4.8s |  |
| 752 | `unescape` | 28 | 4.7s |  |
| 753 | `urlrequest` | 18 | 4.8s |  |
| 754 | `urshift` | 1058 | 17.0s |  |
| 755 | `vector_class` | 36 | 5.1s |  |
| 756 | `vector_class_call` | 11 | 4.8s |  |
| 757 | `vector_coercion` | 66 | 5.5s |  |
| 758 | `vector_concat` | 90 | 5.1s |  |
| 759 | `vector_constr` | 107 | 5.4s |  |
| 760 | `vector_enumeration` | 5 | 4.8s |  |
| 761 | `vector_every` | 92 | 5.6s |  |
| 762 | `vector_filter` | 95 | 5.6s |  |
| 763 | `vector_holes` | 24 | 4.7s |  |
| 764 | `vector_indexof` | 302 | 9.7s |  |
| 765 | `vector_insertat` | 270 | 5.9s |  |
| 766 | `vector_int_access` | 4 | 4.7s |  |
| 767 | `vector_int_delete` | 11 | 4.8s |  |
| 768 | `vector_join` | 58 | 5.2s |  |
| 769 | `vector_lastindexof` | 302 | 4.7s |  |
| 770 | `vector_legacy` | 10 | 4.8s |  |
| 771 | `vector_map` | 85 | 5.5s |  |
| 772 | `vector_object_final` | 1 | 4.7s |  |
| 773 | `vector_object_toString` | 10 | 4.7s |  |
| 774 | `vector_pushpop` | 255 | 6.0s |  |
| 775 | `vector_reborrow_bug` | 10 | 13.9s |  |
| 776 | `vector_removeat` | 172 | 5.2s |  |
| 777 | `vector_reverse` | 232 | 5.3s |  |
| 778 | `vector_shiftunshift` | 252 | 5.4s |  |
| 779 | `vector_slice` | 331 | 5.7s |  |
| 780 | `vector_sort` | 905 | 11.3s |  |
| 781 | `vector_splice` | 693 | 7.4s |  |
| 782 | `vector_splice_fixed_bug_compat` | 4 | 4.6s |  |
| 783 | `vector_tostring` | 79 | 5.0s |  |
| 784 | `verify_abnormal_loop` | 1 | 4.5s |  |
| 785 | `verify_exception_targets_edge_case` | 1 | 4.4s |  |
| 786 | `verify_lookup_switch_edge_case` | 1 | 4.3s |  |
| 787 | `verify_unreachable_exception` | 2 | 4.3s |  |
| 788 | `versioned_isplaying` | 2 | 4.4s |  |
| 789 | `virtual_properties` | 16 | 4.5s |  |
| 790 | `with` | 4 | 4.4s |  |
| 791 | `xml_abstract_equality` | 36 | 4.6s |  |
| 792 | `xml_advanced` | 52 | 4.5s |  |
| 793 | `xml_appendchild` | 10 | 4.5s |  |
| 794 | `xml_as_attribute` | 9 | 4.4s |  |
| 795 | `xml_attribute` | 35 | 4.6s |  |
| 796 | `xml_attribute_name` | 40 | 4.4s |  |
| 797 | `xml_basic` | 33 | 4.5s |  |
| 798 | `xml_child` | 25 | 4.5s |  |
| 799 | `xml_childindex` | 7 | 4.4s |  |
| 800 | `xml_children` | 43 | 4.9s |  |
| 801 | `xml_class_call` | 9 | 4.4s |  |
| 802 | `xml_contains` | 197 | 4.5s |  |
| 803 | `xml_copy` | 20 | 17.6s |  |
| 804 | `xml_ctor_from_tostring` | 23 | 5.8s |  |
| 805 | `xml_delete` | 114 | 5.7s |  |
| 806 | `xml_descendants` | 83 | 5.6s |  |
| 807 | `xml_elements` | 6 | 5.5s |  |
| 808 | `xml_equals_namespace_check` | 2 | 5.5s |  |
| 809 | `xml_explicit_use_namespace` | 5 | 23.7s |  |
| 810 | `xml_getdescendants_qname` | 21 | 5.5s |  |
| 811 | `xml_has_property_via_in` | 26 | 5.5s |  |
| 812 | `xml_hasownproperty` | 6 | 5.5s |  |
| 813 | `xml_ignore_white` | 6 | 5.5s |  |
| 814 | `xml_length` | 2 | 5.5s |  |
| 815 | `xml_list_as_attribute` | 9 | 5.5s |  |
| 816 | `xml_list_concat` | 20 | 5.6s |  |
| 817 | `xml_list_enumerate` | 4 | 5.4s |  |
| 818 | `xml_methods_settings` | 3 | 5.5s |  |
| 819 | `xml_mismatched_tag` | 37 | 5.5s |  |
| 820 | `xml_namespace` | 39 | 5.5s |  |
| 821 | `xml_namespace_methods` | 245 | 5.6s |  |
| 822 | `xml_namespaced_property` | 7 | 5.5s |  |
| 823 | `xml_no_namespace` | 1 | 5.5s |  |
| 824 | `xml_nodekind` | 3 | 5.5s |  |
| 825 | `xml_normalize` | 35 | 5.6s |  |
| 826 | `xml_notification_bubbling` | 361 | 5.5s |  |
| 827 | `xml_parent` | 8 | 5.5s |  |
| 828 | `xml_set_children` | 17 | 5.6s |  |
| 829 | `xml_set_name` | 34 | 5.5s |  |
| 830 | `xml_settings` | 6 | 2.6s |  |
| 831 | `xml_simple_complex_content` | 47 | 5.5s |  |
| 832 | `xml_text` | 7 | 5.5s |  |
| 833 | `xml_tostring` | 6 | 5.5s |  |
| 834 | `xml_tostring_namespace` | 12 | 5.5s |  |
| 835 | `xml_unescaping` | 23 | 5.6s |  |
| 836 | `xml_weird_ignores` | 54 | 5.6s |  |
| 837 | `xml_wildcard` | 11 | 5.5s |  |
| 838 | `xmldocument` | 254 | 5.6s |  |
| 839 | `xmlnode` | 3540 | 5.8s |  |
| 840 | `zero_frame_clip` | 3 | 5.8s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 5.5s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 5.7s |  |
| 3 | `blend_transform` | 1 | 1 | 5.1s |  |
| 4 | `coerce_property` | 3 | 3 | 5.8s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.7s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 4.5s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.9s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.2s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 4.6s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 4.7s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.5s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 23.6s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 24.4s |  |
| 15 | `int_toexponential` | 76 | 76 | 4.7s |  |
| 16 | `int_toprecision` | 441 | 441 | 4.7s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 5.8s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.0s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 24.7s |  |
| 20 | `soundchannel_position` | 74 | 74 | 24.6s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 5.8s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 5.6s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 5.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 4.8s |  |
| 25 | `uint_toprecision` | 433 | 433 | 4.8s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 4.5s |  |

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
| 1 | `domain_memory` | exit code 1 | 5.8s |  |
| 2 | `method_without_body` | exit code 1 | 25.0s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 6.0s |  |
| 4 | `verify_typecheck` | exit code 1 | 4.3s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 35.6s |  |

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
