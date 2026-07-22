# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-22 03:36 UTC

**Git SHA**: `6c040c32fc`

**Run Duration**: 158m 35s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1215 |
| Passing | **826** (68.0%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **852** (70.1%) |
| Failing | 363 |
| Total expected lines | 151085 |
| Matching lines | 103376 (68.4%) |
| Mismatched lines | 47709 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 358 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**826 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 4.3s |  |
| 2 | `agal_compiler` | 13 | 4.3s |  |
| 3 | `air_hidden_lookup` | 2 | 4.3s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.3s |  |
| 5 | `amf_custom_obj` | 26 | 4.3s |  |
| 6 | `amf_dictionary` | 9 | 4.3s |  |
| 7 | `amf_function` | 46 | 4.3s |  |
| 8 | `amf_invalid_date` | 2 | 4.3s |  |
| 9 | `amf_missing_prop` | 6 | 4.3s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 4.8s |  |
| 11 | `amf_setter_error` | 8 | 4.9s |  |
| 12 | `amf_vector` | 40 | 4.9s |  |
| 13 | `amf_xml` | 6 | 4.8s |  |
| 14 | `application_domain` | 4 | 4.8s |  |
| 15 | `array_access` | 18 | 4.8s |  |
| 16 | `array_access_interpreter` | 4 | 4.8s |  |
| 17 | `array_access_no_pubns` | 2 | 4.7s |  |
| 18 | `array_concat` | 41 | 4.8s |  |
| 19 | `array_constr` | 10 | 4.7s |  |
| 20 | `array_delete` | 44 | 4.9s |  |
| 21 | `array_enumeration` | 10 | 4.8s |  |
| 22 | `array_enumeration_elements` | 11 | 4.8s |  |
| 23 | `array_every` | 8 | 4.8s |  |
| 24 | `array_filter` | 6 | 4.8s |  |
| 25 | `array_foreach` | 18 | 4.8s |  |
| 26 | `array_hasownproperty` | 11 | 2.1s |  |
| 27 | `array_holes` | 9 | 4.7s |  |
| 28 | `array_index_max` | 84 | 4.7s |  |
| 29 | `array_indexof` | 25 | 4.8s |  |
| 30 | `array_join` | 26 | 4.8s |  |
| 31 | `array_lastindexof` | 29 | 4.8s |  |
| 32 | `array_length` | 14 | 4.8s |  |
| 33 | `array_literal` | 3 | 4.8s |  |
| 34 | `array_map` | 8 | 4.7s |  |
| 35 | `array_pop` | 52 | 4.9s |  |
| 36 | `array_push` | 24 | 4.8s |  |
| 37 | `array_reborrow_bug` | 6 | 4.7s |  |
| 38 | `array_reverse` | 28 | 4.8s |  |
| 39 | `array_shift` | 51 | 2.2s |  |
| 40 | `array_slice` | 39 | 4.8s |  |
| 41 | `array_some` | 8 | 4.8s |  |
| 42 | `array_sort` | 297 | 5.2s |  |
| 43 | `array_sort_fun_swf12` | 2 | 4.7s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.0s |  |
| 45 | `array_sort_random` | 210 | 4.8s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 4.7s |  |
| 47 | `array_sorton` | 545 | 5.6s |  |
| 48 | `array_sparse_ops` | 41 | 5.0s |  |
| 49 | `array_splice` | 133 | 5.1s |  |
| 50 | `array_splice2` | 428 | 5.2s |  |
| 51 | `array_splice_types` | 48 | 5.0s |  |
| 52 | `array_storage` | 8 | 4.9s |  |
| 53 | `array_tolocalestring` | 9 | 4.9s |  |
| 54 | `array_tostring` | 12 | 5.0s |  |
| 55 | `array_unshift` | 24 | 5.2s |  |
| 56 | `array_valueof` | 9 | 4.8s |  |
| 57 | `array_vector_null_callback` | 10 | 4.8s |  |
| 58 | `astype` | 28 | 5.3s |  |
| 59 | `astypelate` | 24 | 5.2s |  |
| 60 | `astypelate_propagates` | 1 | 5.1s |  |
| 61 | `asymmetric_key_events` | 11 | 5.9s |  |
| 62 | `avm2_catchup_dobj` | 158 | 6.0s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 77.6s |  |
| 64 | `bitand` | 1058 | 14.8s |  |
| 65 | `bitmap_constr` | 17 | 5.2s |  |
| 66 | `bitmap_data` | 1000 | 11.9s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 24.4s |  |
| 68 | `bitmap_properties` | 23 | 5.2s |  |
| 69 | `bitmap_subclass` | 7 | 6.6s |  |
| 70 | `bitmap_subclass_properties` | 9 | 5.5s |  |
| 71 | `bitmap_timeline` | 9 | 5.1s |  |
| 72 | `bitmapdata_accuracy` | 1 | 53.1s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 24.2s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.8s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 23.7s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 23.9s |  |
| 77 | `bitmapdata_clone` | 13 | 5.3s |  |
| 78 | `bitmapdata_colortransform` | 0 | 5.4s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 4.9s |  |
| 80 | `bitmapdata_constr` | 22 | 5.2s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 5.1s |  |
| 82 | `bitmapdata_copychannel` | 0 | 26.3s |  |
| 83 | `bitmapdata_copypixels` | 23 | 25.1s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.3s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.3s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.3s |  |
| 87 | `bitmapdata_draw` | 0 | 24.4s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 5.6s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 23.8s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 23.4s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 5.3s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 5.5s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 5.5s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 23.3s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 5.4s |  |
| 96 | `bitmapdata_embedded` | 9 | 5.6s |  |
| 97 | `bitmapdata_fillrect` | 0 | 5.5s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 23.7s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.2s |  |
| 100 | `bitmapdata_getpixels` | 39 | 23.2s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.6s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.6s |  |
| 103 | `bitmapdata_hittest` | 112 | 5.8s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.2s |  |
| 105 | `bitmapdata_opaque` | 0 | 5.5s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 23.4s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 5.6s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.2s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.3s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.3s |  |
| 111 | `bitmapdata_sync` | 0 | 5.5s |  |
| 112 | `bitmapdata_threshold` | 176 | 5.9s |  |
| 113 | `bitnot` | 46 | 5.2s |  |
| 114 | `bitor` | 1058 | 19.0s |  |
| 115 | `bitxor` | 1058 | 17.3s |  |
| 116 | `blend_multiply_alpha` | 0 | 5.5s |  |
| 117 | `blend_scroll` | 0 | 5.6s |  |
| 118 | `boolean_constr` | 32 | 5.4s |  |
| 119 | `boolean_negation` | 30 | 5.4s |  |
| 120 | `boolean_tostring` | 8 | 5.4s |  |
| 121 | `broadcast_event` | 7 | 5.4s |  |
| 122 | `button_nested_frame` | 48 | 24.2s |  |
| 123 | `bytearray` | 48 | 5.7s |  |
| 124 | `bytearray_compress` | 31 | 5.4s |  |
| 125 | `bytearray_errors` | 24 | 5.5s |  |
| 126 | `bytearray_method_serialization` | 1 | 5.3s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 5.4s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 5.4s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 5.4s |  |
| 130 | `bytearray_serialization` | 3 | 5.4s |  |
| 131 | `bytearray_string_null` | 19 | 5.6s |  |
| 132 | `bytearray_tostring` | 15 | 5.4s |  |
| 133 | `bytearray_utf16` | 8 | 5.3s |  |
| 134 | `bytearray_writeobject` | 24 | 5.3s |  |
| 135 | `callee_in_initializer` | 6 | 5.3s |  |
| 136 | `callproplex_class` | 1 | 5.3s |  |
| 137 | `catch_class` | 6 | 5.3s |  |
| 138 | `catch_scope_slot` | 7 | 2.8s |  |
| 139 | `checkfilter` | 4 | 2.7s |  |
| 140 | `class_call` | 32 | 23.6s |  |
| 141 | `class_cast_call` | 14 | 5.4s |  |
| 142 | `class_enumeration` | 4 | 5.4s |  |
| 143 | `class_has_own_property` | 2 | 5.4s |  |
| 144 | `class_init_interpreter_mode` | 1 | 5.3s |  |
| 145 | `class_is` | 32 | 5.4s |  |
| 146 | `class_methods` | 5 | 5.4s |  |
| 147 | `class_object_properties` | 10 | 5.4s |  |
| 148 | `class_singleton` | 18 | 5.4s |  |
| 149 | `class_supercalls_errors` | 35 | 5.6s |  |
| 150 | `class_supercalls_mismatched` | 26 | 5.5s |  |
| 151 | `class_superclass_wrong_order` | 1 | 22.8s |  |
| 152 | `class_to_locale_string` | 2 | 5.1s |  |
| 153 | `class_to_string` | 2 | 5.0s |  |
| 154 | `class_value_of` | 2 | 5.1s |  |
| 155 | `click_block` | 5 | 23.2s |  |
| 156 | `click_invisible` | 3 | 5.3s |  |
| 157 | `closures` | 12 | 5.1s |  |
| 158 | `coerce_return_type` | 40 | 5.3s |  |
| 159 | `coerce_return_type_fail` | 2 | 5.1s |  |
| 160 | `coerce_return_void` | 3 | 5.1s |  |
| 161 | `coerce_string` | 86 | 5.3s |  |
| 162 | `coerce_string_precision` | 28 | 5.2s |  |
| 163 | `coerce_to_primitive_side_effects` | 29 | 5.2s |  |
| 164 | `construct_errors_swf10` | 8 | 5.1s |  |
| 165 | `construct_frame_list` | 22 | 23.2s |  |
| 166 | `constructor_call` | 3 | 5.1s |  |
| 167 | `constructors_vs_timeline` | 5 | 23.1s |  |
| 168 | `constructprop_dynamic_primitive` | 7 | 5.2s |  |
| 169 | `control_flow_bool` | 4 | 5.1s |  |
| 170 | `control_flow_stricteq` | 8 | 5.2s |  |
| 171 | `convert_boolean` | 30 | 5.2s |  |
| 172 | `convert_integer` | 90 | 5.3s |  |
| 173 | `convert_number` | 56 | 2.7s |  |
| 174 | `convert_uinteger` | 90 | 5.3s |  |
| 175 | `cryptscore` | 11 | 5.2s |  |
| 176 | `declocal` | 46 | 5.3s |  |
| 177 | `declocal_i` | 46 | 5.3s |  |
| 178 | `decrement` | 46 | 5.3s |  |
| 179 | `decrement_i` | 46 | 2.7s |  |
| 180 | `default_values` | 7 | 5.2s |  |
| 181 | `dictionary_access` | 62 | 5.5s |  |
| 182 | `dictionary_access_no_pubns` | 2 | 5.3s |  |
| 183 | `dictionary_delete` | 101 | 5.7s |  |
| 184 | `dictionary_foreach` | 42 | 5.5s |  |
| 185 | `dictionary_hasownproperty` | 63 | 5.6s |  |
| 186 | `dictionary_in` | 62 | 5.5s |  |
| 187 | `dictionary_iter_modify` | 8 | 5.3s |  |
| 188 | `dictionary_namespaces` | 36 | 5.4s |  |
| 189 | `dictionary_primitive_keys` | 29 | 5.3s |  |
| 190 | `displayobject_alpha` | 277 | 5.3s |  |
| 191 | `displayobject_blendmode` | 0 | 23.8s |  |
| 192 | `displayobject_colortransform_nested` | 0 | 24.1s |  |
| 193 | `displayobject_from_enterframe` | 1 | 23.9s |  |
| 194 | `displayobject_getbounds_shape` | 0 | 23.9s |  |
| 195 | `displayobject_height` | 6052 | 23.8s |  |
| 196 | `displayobject_hittestobject` | 32 | 5.3s |  |
| 197 | `displayobject_invalid_floats` | 60 | 5.3s |  |
| 198 | `displayobject_invalid_props` | 3 | 5.2s |  |
| 199 | `displayobject_mask` | 3 | 5.7s |  |
| 200 | `displayobject_mask_self_referential` | 0 | 5.2s |  |
| 201 | `displayobject_metaData` | 3 | 3.7s |  |
| 202 | `displayobject_name` | 22 | 16.9s |  |
| 203 | `displayobject_name_from_timeline` | 24 | 3.7s |  |
| 204 | `displayobject_parent` | 12 | 3.6s |  |
| 205 | `displayobject_root` | 24 | 3.7s |  |
| 206 | `displayobject_rotation` | 1284 | 3.6s |  |
| 207 | `displayobject_set_matrix_nested` | 0 | 18.0s |  |
| 208 | `displayobject_subclass` | 2 | 4.0s |  |
| 209 | `displayobject_visible` | 23 | 3.5s |  |
| 210 | `displayobject_width` | 4852 | 17.6s |  |
| 211 | `displayobject_x` | 614 | 3.7s |  |
| 212 | `displayobject_y` | 617 | 3.7s |  |
| 213 | `displayobjectcontainer_addchild` | 32 | 3.6s |  |
| 214 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 3.5s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 3.9s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 3.9s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 3.6s |  |
| 218 | `displayobjectcontainer_addchildat` | 42 | 3.5s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.6s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 3.8s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.0s |  |
| 222 | `displayobjectcontainer_contains` | 66 | 17.3s |  |
| 223 | `displayobjectcontainer_getchildat` | 4 | 3.6s |  |
| 224 | `displayobjectcontainer_getchildbyname` | 9 | 3.5s |  |
| 225 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 3.5s |  |
| 226 | `displayobjectcontainer_getchildindex` | 28 | 3.5s |  |
| 227 | `displayobjectcontainer_removechild` | 10 | 3.6s |  |
| 228 | `displayobjectcontainer_removechild_errors` | 4 | 3.5s |  |
| 229 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 3.5s |  |
| 230 | `displayobjectcontainer_removechildat` | 18 | 3.4s |  |
| 231 | `displayobjectcontainer_removechildren` | 51 | 3.6s |  |
| 232 | `displayobjectcontainer_setchildindex` | 42 | 3.5s |  |
| 233 | `displayobjectcontainer_stopallmovieclips` | 2 | 17.3s |  |
| 234 | `displayobjectcontainer_swapchildren` | 42 | 3.5s |  |
| 235 | `displayobjectcontainer_swapchildrenat` | 42 | 3.5s |  |
| 236 | `displayobjectcontainer_timelineinstance` | 48 | 17.0s |  |
| 237 | `divide` | 1058 | 17.7s |  |
| 238 | `doabc_is_eager` | 1 | 23.6s |  |
| 239 | `documentclass` | 9 | 5.6s |  |
| 240 | `drag_drop` | 10 | 5.6s |  |
| 241 | `duplicate_defs` | 1 | 5.3s |  |
| 242 | `eager_init` | 1 | 5.5s |  |
| 243 | `edit_text_linkage` | 7 | 5.6s |  |
| 244 | `edittext_align` | 60 | 5.5s |  |
| 245 | `edittext_always_show_selection` | 0 | 24.5s |  |
| 246 | `edittext_antialiastype` | 296 | 5.5s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 6.5s |  |
| 248 | `edittext_autosize` | 39 | 5.4s |  |
| 249 | `edittext_autosize_align` | 0 | 24.3s |  |
| 250 | `edittext_autosize_height_dynamic` | 60 | 24.9s |  |
| 251 | `edittext_autosize_height_input` | 60 | 5.5s |  |
| 252 | `edittext_autosize_lazy_bounds_events` | 65 | 5.7s |  |
| 253 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.4s |  |
| 254 | `edittext_autosize_lazy_bounds_props` | 490 | 6.7s |  |
| 255 | `edittext_autosize_lazy_bounds_visual` | 0 | 23.8s |  |
| 256 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.5s |  |
| 257 | `edittext_bottom_scroll_v_basic` | 210 | 5.4s |  |
| 258 | `edittext_bounds_scale` | 24 | 23.2s |  |
| 259 | `edittext_bullet` | 30 | 5.3s |  |
| 260 | `edittext_default_format` | 221 | 5.3s |  |
| 261 | `edittext_default_format_empty` | 136 | 5.5s |  |
| 262 | `edittext_empty_text_format` | 7 | 5.4s |  |
| 263 | `edittext_focus_selection` | 5 | 5.3s |  |
| 264 | `edittext_font_size` | 45 | 5.4s |  |
| 265 | `edittext_format_empty_font` | 8 | 5.3s |  |
| 266 | `edittext_get_char_index_at_point` | 4 | 23.9s |  |
| 267 | `edittext_get_line_index_at_point` | 2 | 24.0s |  |
| 268 | `edittext_get_line_index_of_char` | 76 | 6.2s |  |
| 269 | `edittext_getcharboundaries` | 172 | 5.0s |  |
| 270 | `edittext_getcharboundaries_missing_glyphs` | 63 | 35.2s |  |
| 271 | `edittext_getcharboundaries_scroll` | 85 | 4.9s |  |
| 272 | `edittext_getlinemetrics` | 146 | 4.8s |  |
| 273 | `edittext_html` | 3101 | 5.2s |  |
| 274 | `edittext_html_condensewhite` | 487 | 4.8s |  |
| 275 | `edittext_html_entity` | 4 | 4.8s |  |
| 276 | `edittext_html_font_size_swf12` | 267 | 4.8s |  |
| 277 | `edittext_html_font_size_swf13` | 273 | 4.5s |  |
| 278 | `edittext_html_roundtrip` | 17 | 4.7s |  |
| 279 | `edittext_input_control` | 12 | 4.7s |  |
| 280 | `edittext_leading` | 9 | 4.7s |  |
| 281 | `edittext_letter_spacing` | 15 | 4.7s |  |
| 282 | `edittext_line_methods` | 294 | 5.2s |  |
| 283 | `edittext_line_metrics` | 11 | 23.9s |  |
| 284 | `edittext_margins` | 25 | 4.8s |  |
| 285 | `edittext_max_scroll_h_basic` | 475 | 4.9s |  |
| 286 | `edittext_max_scroll_v_basic` | 1000 | 4.8s |  |
| 287 | `edittext_mousedown` | 3 | 4.9s |  |
| 288 | `edittext_mouseenabled` | 26 | 4.7s |  |
| 289 | `edittext_newline_character` | 22 | 4.7s |  |
| 290 | `edittext_newline_stripping` | 64 | 7.4s |  |
| 291 | `edittext_newlines` | 30 | 4.8s |  |
| 292 | `edittext_paragraph_methods` | 257 | 4.7s |  |
| 293 | `edittext_paste_events` | 8 | 4.9s |  |
| 294 | `edittext_paste_maxchars` | 4 | 4.8s |  |
| 295 | `edittext_paste_restrict` | 16 | 4.7s |  |
| 296 | `edittext_restrict` | 191 | 4.8s |  |
| 297 | `edittext_restrict_events` | 22 | 4.8s |  |
| 298 | `edittext_scrollh` | 10 | 4.8s |  |
| 299 | `edittext_selected_text` | 9 | 4.8s |  |
| 300 | `edittext_set_html_same` | 17 | 4.8s |  |
| 301 | `edittext_set_text_vs_html` | 9 | 4.8s |  |
| 302 | `edittext_stylesheet` | 536 | 5.2s |  |
| 303 | `edittext_stylesheet_custom_tag` | 76 | 4.8s |  |
| 304 | `edittext_stylesheet_display` | 272 | 4.9s |  |
| 305 | `edittext_underline` | 40 | 4.8s |  |
| 306 | `edittext_width_height` | 103 | 4.8s |  |
| 307 | `edittext_wordwrap_word` | 150 | 17.2s |  |
| 308 | `edittext_wrap_breaks` | 2375 | 6.0s |  |
| 309 | `empty_bounds` | 1 | 5.3s |  |
| 310 | `equals` | 512 | 9.6s |  |
| 311 | `error_prototype` | 15 | 5.3s |  |
| 312 | `error_stack_trace_debug_swf17` | 0 | 24.4s |  |
| 313 | `error_stack_trace_debug_swf18` | 0 | 5.3s |  |
| 314 | `error_stack_trace_release_swf17` | 0 | 5.3s |  |
| 315 | `error_stack_trace_release_swf18` | 0 | 5.3s |  |
| 316 | `error_tostring` | 29 | 5.3s |  |
| 317 | `es3_inheritance` | 31 | 5.5s |  |
| 318 | `es4_inheritance` | 30 | 5.5s |  |
| 319 | `es4_interfaces` | 30 | 5.5s |  |
| 320 | `es4_method_binding` | 8 | 5.4s |  |
| 321 | `es4_oop_prototypes` | 14 | 5.6s |  |
| 322 | `es4_protected_inheritance` | 6 | 5.4s |  |
| 323 | `event_bubbles` | 2 | 5.3s |  |
| 324 | `event_cancelable` | 2 | 5.3s |  |
| 325 | `event_clone` | 20 | 5.4s |  |
| 326 | `event_clone_error_redispatch` | 3 | 5.4s |  |
| 327 | `event_clone_on_redispatch` | 10 | 5.5s |  |
| 328 | `event_formattostring` | 31 | 5.4s |  |
| 329 | `event_isdefaultprevented` | 12 | 5.4s |  |
| 330 | `event_target_getter` | 5 | 2.8s |  |
| 331 | `event_target_set` | 9 | 5.4s |  |
| 332 | `event_type` | 1 | 5.4s |  |
| 333 | `event_valueof_tostring` | 18 | 16.7s |  |
| 334 | `eventdispatcher_dispatchevent` | 12 | 5.5s |  |
| 335 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.4s |  |
| 336 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.5s |  |
| 337 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.5s |  |
| 338 | `eventdispatcher_dispatchevent_this` | 5 | 5.4s |  |
| 339 | `eventdispatcher_haseventlistener` | 25 | 5.5s |  |
| 340 | `eventdispatcher_interface_invoke` | 1 | 5.4s |  |
| 341 | `eventdispatcher_tostring` | 10 | 5.4s |  |
| 342 | `eventdispatcher_willtrigger` | 25 | 5.3s |  |
| 343 | `falsiness` | 30 | 5.5s |  |
| 344 | `fast_index_access` | 12 | 5.6s |  |
| 345 | `finddef` | 3 | 5.4s |  |
| 346 | `findprop_global_prototype` | 6 | 5.5s |  |
| 347 | `flash_xml` | 29 | 5.6s |  |
| 348 | `flash_xml_cloneNode` | 22 | 5.5s |  |
| 349 | `flash_xml_namespace` | 109 | 5.5s |  |
| 350 | `flash_xml_removeNode` | 60 | 5.6s |  |
| 351 | `focus_events_code` | 161 | 24.7s |  |
| 352 | `focus_events_key_same_object` | 26 | 5.5s |  |
| 353 | `focus_events_mixed_key_mouse` | 100 | 24.4s |  |
| 354 | `focus_events_mouse_same_object` | 40 | 25.6s |  |
| 355 | `focus_remove` | 20 | 25.8s |  |
| 356 | `focus_root_movie` | 4 | 25.7s |  |
| 357 | `focus_stage` | 1 | 5.6s |  |
| 358 | `focusrect` | 18 | 6.5s |  |
| 359 | `font_description_clone` | 14 | 5.6s |  |
| 360 | `font_embedded` | 24 | 6.0s |  |
| 361 | `font_enumeratefonts` | 41 | 6.3s |  |
| 362 | `font_enumeratefonts_filter` | 4 | 26.3s |  |
| 363 | `font_hasglyphs` | 40 | 6.0s |  |
| 364 | `framelabel_constr` | 5 | 5.7s |  |
| 365 | `function_call` | 12 | 5.6s |  |
| 366 | `function_call_arguments` | 46 | 5.7s |  |
| 367 | `function_call_arguments_enumerate` | 5 | 5.5s |  |
| 368 | `function_call_coercion` | 108 | 6.0s |  |
| 369 | `function_call_default` | 6 | 5.5s |  |
| 370 | `function_call_rest` | 22 | 5.6s |  |
| 371 | `function_call_types` | 3 | 5.5s |  |
| 372 | `function_call_via_apply` | 11 | 5.5s |  |
| 373 | `function_call_via_call` | 3 | 5.5s |  |
| 374 | `function_display_anonymous` | 7 | 2.9s |  |
| 375 | `function_length` | 6 | 5.6s |  |
| 376 | `function_object` | 2 | 5.5s |  |
| 377 | `function_proto` | 5 | 5.5s |  |
| 378 | `function_proto_created` | 61 | 5.6s |  |
| 379 | `function_to_locale_string` | 4 | 5.5s |  |
| 380 | `function_to_string` | 4 | 5.5s |  |
| 381 | `function_type` | 6 | 5.5s |  |
| 382 | `function_unbound_this` | 51 | 5.7s |  |
| 383 | `function_value_of` | 4 | 5.4s |  |
| 384 | `get_definition_by_name` | 11 | 4.9s |  |
| 385 | `get_qualified_class_name` | 20 | 4.8s |  |
| 386 | `get_qualified_super_class_name` | 18 | 15.1s |  |
| 387 | `get_slot_edge_cases` | 1 | 22.2s |  |
| 388 | `get_timer` | 2 | 4.3s |  |
| 389 | `getglobalslot` | 1 | 4.2s |  |
| 390 | `getouterscope` | 8 | 4.3s |  |
| 391 | `getter_different_namespace_setter` | 2 | 4.3s |  |
| 392 | `goto_button_nested_framescript` | 28 | 22.3s |  |
| 393 | `goto_in_constructframe` | 12 | 22.2s |  |
| 394 | `goto_in_scene_last_frame` | 2 | 22.2s |  |
| 395 | `goto_methods` | 56 | 4.4s |  |
| 396 | `goto_methods_swfver10` | 8 | 4.3s |  |
| 397 | `goto_nested_construct_sibling` | 18 | 4.6s |  |
| 398 | `goto_nested_framescript` | 9 | 4.3s |  |
| 399 | `goto_on_orphan` | 15 | 4.4s |  |
| 400 | `graphics_bad_direct_commands` | 5 | 5.0s |  |
| 401 | `graphics_bitmap_fill` | 0 | 5.9s |  |
| 402 | `graphics_bitmaps` | 0 | 4.8s |  |
| 403 | `graphics_direct_commands` | 0 | 4.9s |  |
| 404 | `graphics_draw_triangles` | 98 | 23.0s |  |
| 405 | `graphics_gradients` | 0 | 4.7s |  |
| 406 | `graphics_gradients_nulls` | 0 | 4.5s |  |
| 407 | `graphics_path` | 56 | 4.3s |  |
| 408 | `graphics_round_rects` | 0 | 4.2s |  |
| 409 | `graphics_simple_shapes` | 0 | 4.5s |  |
| 410 | `greaterequals` | 512 | 7.1s |  |
| 411 | `greaterthan` | 512 | 7.2s |  |
| 412 | `has_own_property` | 102 | 4.8s |  |
| 413 | `hasownproperty_namespaces` | 2 | 4.2s |  |
| 414 | `hello_world` | 1 | 4.2s |  |
| 415 | `hittest_morph` | 30 | 4.3s |  |
| 416 | `if_eq` | 10 | 4.8s |  |
| 417 | `if_gt` | 1 | 4.8s |  |
| 418 | `if_gte` | 10 | 2.4s |  |
| 419 | `if_lt` | 1 | 0.9s |  |
| 420 | `if_lte` | 10 | 13.4s |  |
| 421 | `if_ne` | 7 | 4.1s |  |
| 422 | `if_stricteq` | 6 | 4.1s |  |
| 423 | `if_strictne` | 11 | 4.2s |  |
| 424 | `in` | 102 | 4.5s |  |
| 425 | `inclocal` | 46 | 4.2s |  |
| 426 | `inclocal_i` | 46 | 4.1s |  |
| 427 | `increment` | 46 | 4.1s |  |
| 428 | `increment_i` | 46 | 4.1s |  |
| 429 | `instanceof` | 58 | 4.3s |  |
| 430 | `instantiation_on_enter_frame` | 7 | 19.6s |  |
| 431 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.1s |  |
| 432 | `int_constr` | 92 | 4.3s |  |
| 433 | `int_edge_cases` | 19 | 4.1s |  |
| 434 | `int_instanceof` | 3 | 4.0s |  |
| 435 | `int_tofixed` | 1215 | 4.0s |  |
| 436 | `int_tostring` | 3375 | 4.3s |  |
| 437 | `interactiveobject_enabled` | 25 | 4.0s |  |
| 438 | `interface_namespaces` | 78 | 4.3s |  |
| 439 | `is_finite` | 46 | 4.2s |  |
| 440 | `is_nan` | 46 | 4.0s |  |
| 441 | `is_prototype_of` | 12 | 4.2s |  |
| 442 | `issue_10221` | 2 | 4.1s |  |
| 443 | `issue_13780` | 12 | 4.1s |  |
| 444 | `issue_14901` | 1 | 4.0s |  |
| 445 | `issue_17675_edittext_paste_maxchars` | 1 | 4.1s |  |
| 446 | `issue_5292` | 5 | 4.1s |  |
| 447 | `issue_8630` | 2 | 19.4s |  |
| 448 | `issue_8630_scriptremove` | 11 | 4.1s |  |
| 449 | `istype` | 24 | 1.9s |  |
| 450 | `istypelate` | 58 | 4.3s |  |
| 451 | `istypelate_coerce` | 198 | 4.8s |  |
| 452 | `json_errors` | 9 | 27.7s |  |
| 453 | `json_parse` | 21 | 4.2s |  |
| 454 | `json_version_gated` | 1 | 4.4s |  |
| 455 | `key_input_80percent` | 1812 | 4.3s |  |
| 456 | `key_input_location` | 126 | 4.8s |  |
| 457 | `key_input_numpad` | 384 | 4.3s |  |
| 458 | `lazyinit` | 17 | 4.4s |  |
| 459 | `lessequals` | 512 | 7.1s |  |
| 460 | `lessthan` | 512 | 7.1s |  |
| 461 | `loaderinfo_properties` | 18 | 35.9s |  |
| 462 | `loaderinfo_root` | 10 | 5.6s |  |
| 463 | `loaderinfo_root_allows` | 2 | 5.6s |  |
| 464 | `lshift` | 1058 | 17.1s |  |
| 465 | `mask_reapply` | 1 | 24.6s |  |
| 466 | `math` | 497 | 5.7s |  |
| 467 | `missing_external_interface` | 10 | 5.5s |  |
| 468 | `modulo` | 1058 | 17.1s |  |
| 469 | `mouse_click_events` | 90 | 24.5s |  |
| 470 | `mouse_double_click_events` | 188 | 5.5s |  |
| 471 | `mouse_empty_parent` | 4 | 5.5s |  |
| 472 | `mouse_over_while_dragging` | 3 | 5.7s |  |
| 473 | `mouse_pick_button_mode` | 2 | 5.6s |  |
| 474 | `mouse_sibling` | 8 | 5.5s |  |
| 475 | `movieclip_addframescript` | 3 | 25.3s |  |
| 476 | `movieclip_child_property` | 16 | 5.9s |  |
| 477 | `movieclip_constr` | 21 | 5.6s |  |
| 478 | `movieclip_currentlabels` | 17 | 35.0s |  |
| 479 | `movieclip_currentlabels_dupes1` | 46 | 24.2s |  |
| 480 | `movieclip_currentlabels_dupes2` | 30 | 5.4s |  |
| 481 | `movieclip_currentlabels_dupes3` | 67 | 5.3s |  |
| 482 | `movieclip_currentscene` | 12 | 24.2s |  |
| 483 | `movieclip_dispatchevent` | 430 | 5.7s |  |
| 484 | `movieclip_dispatchevent_cancel` | 102 | 5.6s |  |
| 485 | `movieclip_dispatchevent_handlerorder` | 251 | 5.5s |  |
| 486 | `movieclip_dispatchevent_selfadd` | 80 | 5.4s |  |
| 487 | `movieclip_dispatchevent_target` | 899 | 5.5s |  |
| 488 | `movieclip_displayevents` | 96 | 24.5s |  |
| 489 | `movieclip_displayevents_clickgoto` | 676 | 24.7s |  |
| 490 | `movieclip_displayevents_clickgoto2` | 2001 | 5.8s |  |
| 491 | `movieclip_displayevents_clickplay` | 575 | 5.5s |  |
| 492 | `movieclip_displayevents_clicksymbol` | 562 | 5.5s |  |
| 493 | `movieclip_displayevents_constructframegoto` | 140 | 5.7s |  |
| 494 | `movieclip_displayevents_constructframeplay` | 50 | 5.7s |  |
| 495 | `movieclip_displayevents_constructframesymbol` | 144 | 5.5s |  |
| 496 | `movieclip_displayevents_dblhandler` | 21 | 5.5s |  |
| 497 | `movieclip_displayevents_enterframegoto` | 149 | 5.6s |  |
| 498 | `movieclip_displayevents_enterframeplay` | 48 | 5.5s |  |
| 499 | `movieclip_displayevents_enterframesymbol` | 149 | 24.4s |  |
| 500 | `movieclip_displayevents_exitframegoto` | 106 | 5.5s |  |
| 501 | `movieclip_displayevents_exitframeplay` | 44 | 5.5s |  |
| 502 | `movieclip_displayevents_exitframesymbol` | 135 | 5.6s |  |
| 503 | `movieclip_displayevents_looping` | 63 | 24.5s |  |
| 504 | `movieclip_displayevents_stopped` | 113 | 5.8s |  |
| 505 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 506 | `movieclip_displayevents_timeline` | 128 | 24.2s |  |
| 507 | `movieclip_drawrect` | 54 | 5.4s |  |
| 508 | `movieclip_frameconstruct_skipped` | 9 | 5.4s |  |
| 509 | `movieclip_goto_during_frame_script` | 15 | 5.4s |  |
| 510 | `movieclip_goto_overwrite` | 14 | 23.8s |  |
| 511 | `movieclip_goto_scene_last_frame_int` | 1 | 24.1s |  |
| 512 | `movieclip_goto_scene_last_frame_label` | 1 | 5.2s |  |
| 513 | `movieclip_gotoandplay` | 15 | 24.2s |  |
| 514 | `movieclip_gotoandstop` | 13 | 5.3s |  |
| 515 | `movieclip_gotoandstop_children` | 4 | 5.4s |  |
| 516 | `movieclip_gotoandstop_framescripts1` | 4 | 5.4s |  |
| 517 | `movieclip_gotoandstop_framescripts2` | 4 | 2.8s |  |
| 518 | `movieclip_gotoandstop_framescripts_self` | 7 | 35.0s |  |
| 519 | `movieclip_gotoandstop_queueing` | 12 | 23.6s |  |
| 520 | `movieclip_next_frame` | 2 | 23.6s |  |
| 521 | `movieclip_next_scene` | 6 | 23.5s |  |
| 522 | `movieclip_play` | 3 | 5.3s |  |
| 523 | `movieclip_prev_frame` | 3 | 5.2s |  |
| 524 | `movieclip_prev_scene` | 7 | 5.3s |  |
| 525 | `movieclip_properties` | 79 | 23.7s |  |
| 526 | `movieclip_queued_noop_goto_swf10` | 9 | 5.4s |  |
| 527 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 528 | `movieclip_scenes` | 11 | 5.3s |  |
| 529 | `movieclip_soundtransform` | 831 | 25.6s |  |
| 530 | `movieclip_stop` | 1 | 23.4s |  |
| 531 | `movieclip_super_is_symbol` | 20 | 5.7s |  |
| 532 | `movieclip_symbol_constr` | 8 | 5.5s |  |
| 533 | `movieclip_text_mousedown` | 1 | 5.4s |  |
| 534 | `movieclip_willtrigger` | 5 | 5.6s |  |
| 535 | `multiply` | 1058 | 16.5s |  |
| 536 | `namespace_constr` | 253 | 5.7s |  |
| 537 | `namespace_constr_args` | 1 | 5.3s |  |
| 538 | `namespace_enumeration_order` | 7 | 5.4s |  |
| 539 | `nan_scale` | 9 | 5.3s |  |
| 540 | `negate` | 30 | 5.4s |  |
| 541 | `negative_volume_panned` | 0 | 5.6s |  |
| 542 | `nested_iteration` | 11 | 5.4s |  |
| 543 | `net_getClassByAlias` | 3 | 5.4s |  |
| 544 | `newactivation_in_script_init` | 3 | 4.9s |  |
| 545 | `newclass_twice` | 3 | 4.8s |  |
| 546 | `nonconflicting_declarations` | 0 | 4.9s |  |
| 547 | `null_void_types` | 8 | 4.8s |  |
| 548 | `number_autoconv` | 21 | 4.9s |  |
| 549 | `number_autoconv_amf` | 132 | 4.9s |  |
| 550 | `number_autoconv_array_sort_32bit` | 1 | 4.9s |  |
| 551 | `number_constr` | 58 | 5.1s |  |
| 552 | `number_toexponential` | 378 | 4.9s |  |
| 553 | `number_toexponential2` | 35 | 4.9s |  |
| 554 | `number_tofixed` | 378 | 4.8s |  |
| 555 | `number_toprecision` | 350 | 4.9s |  |
| 556 | `obfuscated_class_names` | 3 | 4.8s |  |
| 557 | `object_enumeration` | 10 | 4.9s |  |
| 558 | `object_prototype` | 4 | 5.0s |  |
| 559 | `object_to_locale_string` | 2 | 4.9s |  |
| 560 | `object_to_string` | 2 | 4.8s |  |
| 561 | `object_value_of` | 2 | 2.2s |  |
| 562 | `op_coerce` | 54 | 4.9s |  |
| 563 | `op_coerce_x` | 54 | 5.0s |  |
| 564 | `op_escxattr` | 2 | 4.9s |  |
| 565 | `op_escxelem` | 2 | 4.9s |  |
| 566 | `op_lookupswitch` | 4 | 4.9s |  |
| 567 | `optimize_coerce` | 1 | 4.8s |  |
| 568 | `orphan_movie_complex` | 80 | 5.2s |  |
| 569 | `orphan_movie_reorder` | 111 | 23.7s |  |
| 570 | `package_namespace` | 7 | 4.8s |  |
| 571 | `param_default_value_has_zero_cpool_index` | 1 | 4.8s |  |
| 572 | `parent_early_access_child` | 16 | 23.7s |  |
| 573 | `pixelbender_effect_BlurredFocus` | 0 | 27.1s |  |
| 574 | `pixelbender_effect_glassDisplace` | 0 | 10.9s |  |
| 575 | `pixelbender_effect_smudge` | 0 | 9.0s |  |
| 576 | `pixelbender_effect_tintype` | 0 | 8.1s |  |
| 577 | `pixelbender_effect_twirl` | 0 | 9.1s |  |
| 578 | `pixelbender_images` | 0 | 7.7s |  |
| 579 | `place_multiple` | 17 | 23.5s |  |
| 580 | `place_object_replace` | 9 | 5.4s |  |
| 581 | `place_object_replace_2` | 24 | 5.5s |  |
| 582 | `place_object_same_depth_frame` | 1 | 5.3s |  |
| 583 | `point` | 132 | 5.8s |  |
| 584 | `primitive_edge_cases` | 1 | 5.1s |  |
| 585 | `property_priority` | 22 | 4.0s |  |
| 586 | `property_priority_three_level` | 6 | 16.9s |  |
| 587 | `propertyisenumerable_namespaces` | 6 | 3.5s |  |
| 588 | `prototype_set_null` | 7 | 3.8s |  |
| 589 | `proxy_callproperty` | 24 | 3.8s |  |
| 590 | `proxy_deleteproperty` | 64 | 3.6s |  |
| 591 | `proxy_enumeration` | 34 | 3.7s |  |
| 592 | `proxy_getproperty` | 77 | 3.9s |  |
| 593 | `proxy_hasownproperty` | 8 | 3.5s |  |
| 594 | `proxy_hasproperty` | 32 | 3.5s |  |
| 595 | `proxy_serialize` | 9 | 3.5s |  |
| 596 | `proxy_setproperty` | 42 | 3.5s |  |
| 597 | `qname_as_lazy_name_attribute_multiname` | 1 | 3.4s |  |
| 598 | `qname_constr` | 32 | 3.6s |  |
| 599 | `qname_constr_namespace` | 24 | 4.2s |  |
| 600 | `qname_enumeration` | 9 | 3.5s |  |
| 601 | `qname_indexing` | 23 | 3.9s |  |
| 602 | `qname_tostring` | 25 | 3.9s |  |
| 603 | `qname_valueof` | 29 | 3.9s |  |
| 604 | `regexp_constr` | 148 | 3.9s |  |
| 605 | `regexp_exec` | 19 | 3.7s |  |
| 606 | `regexp_extended` | 47 | 3.9s |  |
| 607 | `regexp_multiargs` | 1 | 3.6s |  |
| 608 | `regexp_test` | 27 | 3.7s |  |
| 609 | `regexp_toString` | 10 | 3.8s |  |
| 610 | `register_script_refresh` | 35 | 18.0s |  |
| 611 | `remove_child_clear_field` | 88 | 17.7s |  |
| 612 | `remove_dobj` | 3 | 4.1s |  |
| 613 | `resolve_order` | 4 | 4.1s |  |
| 614 | `rng` | 1 | 4.6s |  |
| 615 | `rootless` | 42 | 4.0s |  |
| 616 | `rshift` | 1058 | 18.8s |  |
| 617 | `sandbox_type_local_file` | 1 | 3.9s |  |
| 618 | `scene_constr` | 8 | 4.0s |  |
| 619 | `set_local_0` | 31 | 3.8s |  |
| 620 | `set_property_is_enumerable` | 85 | 3.9s |  |
| 621 | `shape_drawrect` | 54 | 3.9s |  |
| 622 | `shared_object_no_root` | 3 | 3.7s |  |
| 623 | `simplebutton_added_to_stage` | 45 | 16.7s |  |
| 624 | `simplebutton_childevents` | 86 | 17.1s |  |
| 625 | `simplebutton_childevents_nested` | 54 | 4.0s |  |
| 626 | `simplebutton_childevents_sprite` | 13 | 3.8s |  |
| 627 | `simplebutton_childprops` | 144 | 3.9s |  |
| 628 | `simplebutton_childshuffle` | 23 | 3.7s |  |
| 629 | `simplebutton_constr` | 36 | 3.8s |  |
| 630 | `simplebutton_constr_childevents` | 48 | 4.1s |  |
| 631 | `simplebutton_constr_params` | 42 | 3.8s |  |
| 632 | `simplebutton_mouseenabled` | 26 | 3.8s |  |
| 633 | `simplebutton_multi_children` | 19 | 4.0s |  |
| 634 | `simplebutton_structure` | 27 | 4.2s |  |
| 635 | `simplebutton_symbolclass` | 68 | 4.1s |  |
| 636 | `slot_disp_id_shared_numbering` | 1 | 17.5s |  |
| 637 | `slots_force_autoassigned` | 1 | 4.1s |  |
| 638 | `sound_embeddedprops` | 26 | 5.4s |  |
| 639 | `sound_play` | 19 | 5.5s |  |
| 640 | `sound_valueof` | 33 | 5.3s |  |
| 641 | `soundchannel_soundtransform` | 835 | 25.4s |  |
| 642 | `soundchannel_soundtransform_exists` | 5 | 23.9s |  |
| 643 | `soundchannel_stop` | 8 | 23.8s |  |
| 644 | `soundmixer_buffertime` | 5 | 5.2s |  |
| 645 | `soundmixer_stopall` | 6 | 23.3s |  |
| 646 | `soundtransform` | 442 | 10.8s |  |
| 647 | `sprite_with_frames` | 0 | 23.8s |  |
| 648 | `stage3d_agal_cross_product` | 0 | 7.9s |  |
| 649 | `stage3d_bitmap` | 0 | 28.5s |  |
| 650 | `stage3d_float1_index` | 0 | 26.6s |  |
| 651 | `stage3d_fractal` | 0 | 8.6s |  |
| 652 | `stage3d_ignore_sampler_override` | 0 | 28.5s |  |
| 653 | `stage3d_program_constants_bytearray_be` | 0 | 29.7s |  |
| 654 | `stage3d_program_constants_bytearray_le` | 0 | 9.5s |  |
| 655 | `stage3d_raytrace` | 0 | 41.9s |  |
| 656 | `stage3d_rotating_cube` | 0 | 9.4s |  |
| 657 | `stage3d_sampler` | 0 | 8.5s |  |
| 658 | `stage3d_sampler_partial_upload` | 0 | 8.3s |  |
| 659 | `stage3d_stencil` | 0 | 27.9s |  |
| 660 | `stage3d_texture` | 0 | 13.3s |  |
| 661 | `stage3d_texture_bytearray` | 0 | 9.5s |  |
| 662 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.8s |  |
| 663 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.1s |  |
| 664 | `stage3d_triangle` | 0 | 8.2s |  |
| 665 | `stage3d_triangle_bytes4` | 0 | 8.3s |  |
| 666 | `stage3d_triangle_float1` | 0 | 8.4s |  |
| 667 | `stage3d_triangle_index_upload` | 0 | 8.3s |  |
| 668 | `stage_access` | 10 | 5.3s |  |
| 669 | `stage_displayobject_properties` | 24 | 5.3s |  |
| 670 | `stage_framerate_nan` | 7 | 5.5s |  |
| 671 | `stage_framerate_negative` | 6 | 5.3s |  |
| 672 | `stage_framerate_zero` | 6 | 5.3s |  |
| 673 | `stage_invalidate` | 38 | 5.5s |  |
| 674 | `stage_mousechildren` | 2 | 5.3s |  |
| 675 | `stage_mouseenabled` | 15 | 5.3s |  |
| 676 | `stage_overriden_setters` | 31 | 5.5s |  |
| 677 | `stage_properties` | 30 | 5.3s |  |
| 678 | `static_var_with_this_in_ctor` | 2 | 5.3s |  |
| 679 | `stored_properties` | 11 | 5.1s |  |
| 680 | `strict_equality` | 34 | 5.2s |  |
| 681 | `string_call` | 13 | 5.1s |  |
| 682 | `string_case` | 23 | 5.0s |  |
| 683 | `string_char_at` | 27 | 5.0s |  |
| 684 | `string_char_code_at` | 28 | 5.0s |  |
| 685 | `string_constr` | 25 | 4.7s |  |
| 686 | `string_indexof_lastindexof` | 87 | 4.9s |  |
| 687 | `string_length` | 16 | 4.7s |  |
| 688 | `string_locale_compare` | 39 | 5.0s |  |
| 689 | `string_match` | 51 | 4.9s |  |
| 690 | `string_relational_compare` | 4 | 4.7s |  |
| 691 | `string_replace` | 51 | 4.9s |  |
| 692 | `string_search` | 41 | 4.9s |  |
| 693 | `string_split` | 29 | 4.8s |  |
| 694 | `string_substr_negative` | 21 | 4.7s |  |
| 695 | `string_substr_weird` | 182 | 4.6s |  |
| 696 | `subtract` | 1058 | 16.6s |  |
| 697 | `super_get_call` | 12 | 4.7s |  |
| 698 | `supercall_two_classobjects` | 2 | 4.8s |  |
| 699 | `swf8` | 1 | 4.5s |  |
| 700 | `swf_10_queued_goto_scripts_construct` | 52 | 22.8s |  |
| 701 | `swf_9_goto_in_enter_frame` | 17 | 4.8s |  |
| 702 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.7s |  |
| 703 | `swf_9_queued_goto_scripts` | 6 | 22.6s |  |
| 704 | `swf_9_queued_goto_scripts_construct` | 28 | 1.0s |  |
| 705 | `swf_9_versioning` | 2 | 4.7s |  |
| 706 | `swf_wrong_frame_count` | 38 | 4.9s |  |
| 707 | `swf_wrong_frame_count_isplaying` | 22 | 5.1s |  |
| 708 | `symbol_class_binary_data` | 8 | 5.1s |  |
| 709 | `symbol_class_conflict` | 4 | 5.6s |  |
| 710 | `symbol_class_root_not_zero` | 1 | 5.0s |  |
| 711 | `symbolclass_invalid_utf8` | 2 | 5.1s |  |
| 712 | `tab_ordering_automatic_advanced` | 184 | 4.7s |  |
| 713 | `tab_ordering_automatic_basic` | 45 | 4.2s |  |
| 714 | `tab_ordering_children` | 116 | 4.4s |  |
| 715 | `tab_ordering_custom_basic` | 34 | 4.3s |  |
| 716 | `text_engine_fontdescription` | 27 | 4.2s |  |
| 717 | `text_run` | 7 | 4.2s |  |
| 718 | `textfield_focusin_event` | 9 | 4.1s |  |
| 719 | `textfield_input_dead_keys_windows` | 15 | 4.1s |  |
| 720 | `textfield_unload` | 39 | 19.8s |  |
| 721 | `textformat` | 1134 | 4.2s |  |
| 722 | `textformat_display` | 14 | 4.3s |  |
| 723 | `textformat_font_max_length` | 4 | 4.1s |  |
| 724 | `throw` | 3 | 4.1s |  |
| 725 | `timeline_scripts` | 3 | 4.3s |  |
| 726 | `timer` | 90 | 4.7s |  |
| 727 | `timer_events` | 3 | 4.1s |  |
| 728 | `timer_finished` | 11 | 4.2s |  |
| 729 | `timer_reset` | 8 | 4.2s |  |
| 730 | `timer_setdelay` | 5 | 4.1s |  |
| 731 | `trace` | 12 | 4.1s |  |
| 732 | `truthiness` | 30 | 16.6s |  |
| 733 | `try_catch` | 11 | 5.6s |  |
| 734 | `try_catch_typed` | 12 | 5.4s |  |
| 735 | `typeof` | 30 | 5.5s |  |
| 736 | `uint_constr` | 92 | 5.6s |  |
| 737 | `uint_tofixed` | 1215 | 5.3s |  |
| 738 | `uint_tostring` | 3375 | 5.8s |  |
| 739 | `unchecked_function` | 15 | 5.3s |  |
| 740 | `urlrequest` | 18 | 5.5s |  |
| 741 | `urshift` | 1058 | 17.7s |  |
| 742 | `vector_class` | 36 | 5.8s |  |
| 743 | `vector_class_call` | 11 | 5.5s |  |
| 744 | `vector_coercion` | 66 | 6.2s |  |
| 745 | `vector_concat` | 90 | 5.8s |  |
| 746 | `vector_constr` | 107 | 6.2s |  |
| 747 | `vector_enumeration` | 5 | 5.4s |  |
| 748 | `vector_every` | 92 | 6.4s |  |
| 749 | `vector_filter` | 95 | 6.3s |  |
| 750 | `vector_holes` | 24 | 5.4s |  |
| 751 | `vector_indexof` | 302 | 10.4s |  |
| 752 | `vector_insertat` | 270 | 6.6s |  |
| 753 | `vector_int_access` | 4 | 5.5s |  |
| 754 | `vector_int_delete` | 11 | 5.4s |  |
| 755 | `vector_join` | 58 | 5.8s |  |
| 756 | `vector_lastindexof` | 302 | 5.4s |  |
| 757 | `vector_legacy` | 10 | 5.5s |  |
| 758 | `vector_map` | 85 | 6.2s |  |
| 759 | `vector_object_final` | 1 | 5.3s |  |
| 760 | `vector_object_toString` | 10 | 5.3s |  |
| 761 | `vector_pushpop` | 255 | 6.7s |  |
| 762 | `vector_reborrow_bug` | 10 | 16.2s |  |
| 763 | `vector_removeat` | 172 | 6.3s |  |
| 764 | `vector_reverse` | 232 | 6.4s |  |
| 765 | `vector_shiftunshift` | 252 | 6.5s |  |
| 766 | `vector_slice` | 331 | 7.0s |  |
| 767 | `vector_sort` | 905 | 14.6s |  |
| 768 | `vector_splice` | 693 | 9.4s |  |
| 769 | `vector_splice_fixed_bug_compat` | 4 | 5.3s |  |
| 770 | `vector_tostring` | 79 | 5.8s |  |
| 771 | `verify_abnormal_loop` | 1 | 5.0s |  |
| 772 | `verify_exception_targets_edge_case` | 1 | 5.0s |  |
| 773 | `verify_lookup_switch_edge_case` | 1 | 5.0s |  |
| 774 | `verify_unreachable_exception` | 2 | 5.0s |  |
| 775 | `versioned_isplaying` | 2 | 5.0s |  |
| 776 | `virtual_properties` | 16 | 5.1s |  |
| 777 | `with` | 4 | 5.1s |  |
| 778 | `xml_abstract_equality` | 36 | 5.2s |  |
| 779 | `xml_advanced` | 52 | 5.0s |  |
| 780 | `xml_appendchild` | 10 | 5.0s |  |
| 781 | `xml_as_attribute` | 9 | 5.0s |  |
| 782 | `xml_attribute` | 35 | 5.2s |  |
| 783 | `xml_attribute_name` | 40 | 5.1s |  |
| 784 | `xml_child` | 25 | 5.1s |  |
| 785 | `xml_childindex` | 7 | 5.1s |  |
| 786 | `xml_children` | 43 | 5.6s |  |
| 787 | `xml_class_call` | 9 | 5.1s |  |
| 788 | `xml_contains` | 197 | 5.3s |  |
| 789 | `xml_copy` | 20 | 16.7s |  |
| 790 | `xml_ctor_from_tostring` | 23 | 5.7s |  |
| 791 | `xml_delete` | 114 | 5.5s |  |
| 792 | `xml_descendants` | 83 | 5.5s |  |
| 793 | `xml_elements` | 6 | 5.4s |  |
| 794 | `xml_equals_namespace_check` | 2 | 5.3s |  |
| 795 | `xml_explicit_use_namespace` | 5 | 23.6s |  |
| 796 | `xml_getdescendants_qname` | 21 | 5.3s |  |
| 797 | `xml_has_property_via_in` | 26 | 5.4s |  |
| 798 | `xml_hasownproperty` | 6 | 5.3s |  |
| 799 | `xml_ignore_white` | 6 | 5.4s |  |
| 800 | `xml_length` | 2 | 5.3s |  |
| 801 | `xml_list_as_attribute` | 9 | 5.3s |  |
| 802 | `xml_list_concat` | 20 | 5.4s |  |
| 803 | `xml_list_enumerate` | 4 | 5.3s |  |
| 804 | `xml_methods_settings` | 3 | 5.3s |  |
| 805 | `xml_mismatched_tag` | 37 | 5.4s |  |
| 806 | `xml_namespace` | 39 | 5.4s |  |
| 807 | `xml_namespace_methods` | 245 | 5.5s |  |
| 808 | `xml_namespaced_property` | 7 | 5.4s |  |
| 809 | `xml_no_namespace` | 1 | 5.3s |  |
| 810 | `xml_nodekind` | 3 | 5.4s |  |
| 811 | `xml_normalize` | 35 | 5.5s |  |
| 812 | `xml_notification_bubbling` | 361 | 5.4s |  |
| 813 | `xml_parent` | 8 | 5.4s |  |
| 814 | `xml_set_children` | 17 | 5.5s |  |
| 815 | `xml_set_name` | 34 | 5.4s |  |
| 816 | `xml_settings` | 6 | 2.8s |  |
| 817 | `xml_simple_complex_content` | 47 | 5.4s |  |
| 818 | `xml_text` | 7 | 5.4s |  |
| 819 | `xml_tostring` | 6 | 5.4s |  |
| 820 | `xml_tostring_namespace` | 12 | 5.3s |  |
| 821 | `xml_unescaping` | 23 | 5.5s |  |
| 822 | `xml_weird_ignores` | 54 | 5.5s |  |
| 823 | `xml_wildcard` | 11 | 5.4s |  |
| 824 | `xmldocument` | 254 | 5.5s |  |
| 825 | `xmlnode` | 3540 | 5.5s |  |
| 826 | `zero_frame_clip` | 3 | 5.7s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 4.7s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 4.3s |  |
| 3 | `blend_transform` | 1 | 1 | 5.6s |  |
| 4 | `coerce_property` | 3 | 3 | 5.3s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.2s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 23.9s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.0s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 4.8s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 4.9s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.4s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 5.5s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.5s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 22.1s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 23.0s |  |
| 15 | `int_toexponential` | 76 | 76 | 4.2s |  |
| 16 | `int_toprecision` | 441 | 441 | 4.2s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 3.9s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 3.8s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 17.1s |  |
| 20 | `soundchannel_position` | 74 | 74 | 24.1s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 5.4s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 5.2s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 22.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.5s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.6s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 4.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**70 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `string_slice_substr_substring` | 99.4% | 169 | 170 | 1 |  |
| 3 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 4 | `parse_float` | 98.8% | 80 | 81 | 1 |  |
| 5 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 6 | `parse_int` | 97.8% | 132 | 135 | 3 |  |
| 7 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 8 | `string_concat_fromcharcode` | 97.3% | 36 | 37 | 1 |  |
| 9 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 10 | `xml_basic` | 97.0% | 32 | 33 | 1 |  |
| 11 | `parse_float_swf10` | 96.3% | 78 | 81 | 3 |  |
| 12 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 13 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 14 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 15 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 16 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 17 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 18 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 19 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 20 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 21 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 22 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 23 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 24 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 25 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 26 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 27 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 28 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 29 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 30 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 31 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 32 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 33 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 34 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 35 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 36 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 37 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 38 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 39 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 40 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 41 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 42 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 43 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 44 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 45 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 46 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 47 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 48 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 49 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 50 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 51 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 52 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 53 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 54 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 55 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 56 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 57 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 58 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 59 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 60 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 61 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 62 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 63 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 64 | `date` | 50.0% | 15 | 30 | 15 |  |
| 65 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 66 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 67 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 68 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 69 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 70 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 5.4s |  |
| 2 | `method_without_body` | exit code 1 | 24.3s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 3.7s |  |
| 4 | `verify_typecheck` | exit code 1 | 4.9s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 35.2s |  |

## All Output Mismatches

**358 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `string_slice_substr_substring` | 99.4% | 169/170 | 169 | 170 |  |
| 3 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 4 | `parse_float` | 98.8% | 80/81 | 80 | 81 |  |
| 5 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 6 | `parse_int` | 97.8% | 132/135 | 134 | 135 |  |
| 7 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 8 | `string_concat_fromcharcode` | 97.3% | 36/37 | 36 | 37 |  |
| 9 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 10 | `xml_basic` | 97.0% | 32/33 | 32 | 33 |  |
| 11 | `parse_float_swf10` | 96.3% | 78/81 | 80 | 81 |  |
| 12 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 13 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 14 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 15 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 16 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 17 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 18 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 19 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 20 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 21 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 22 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 23 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 24 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 25 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 26 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 27 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 28 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 29 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 30 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 31 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 32 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 33 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 34 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 35 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 36 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 37 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 38 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 39 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 40 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 41 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 42 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 43 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 44 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 45 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 46 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 47 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 48 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 49 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 50 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 51 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 52 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 53 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 54 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 55 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 56 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 57 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 58 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 59 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 60 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 61 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 62 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 63 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 64 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 65 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 66 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 67 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 68 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 69 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 70 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 71 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 72 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 73 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 74 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 75 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 76 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 77 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 78 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 79 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 80 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 81 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 82 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 83 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 84 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 85 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 86 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 87 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 88 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 89 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 90 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 91 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 92 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 93 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 94 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 95 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 96 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 97 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 98 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 99 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 100 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 101 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 102 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 103 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 104 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 105 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 106 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 107 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 108 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 109 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 110 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 111 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 112 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 113 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 114 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 115 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 116 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 117 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 118 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 119 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 120 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 121 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 122 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 123 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 124 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 125 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 126 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 127 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 128 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 129 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 130 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 131 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 132 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 133 | `loader_method` | 4.7% | 4/85 | 11 | 85 |  |
| 134 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 135 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 136 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 137 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 138 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 139 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 140 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 141 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 142 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 143 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 144 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 145 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 146 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 147 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 148 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 149 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 150 | `loader_load` | 2.3% | 3/128 | 11 | 128 |  |
| 151 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 152 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 153 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 154 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 155 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 156 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 157 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 158 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 159 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 160 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 161 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 162 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 163 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 164 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 165 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 166 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 167 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 168 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 169 | `all_classes/display/swf9` | 0.1% | 2/1959 | 242 | 1959 |  |
| 170 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 171 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 172 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 173 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 174 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 175 | `all_classes/display/swf10` | 0.0% | 1/2569 | 242 | 2569 |  |
| 176 | `all_classes/display/swf11` | 0.0% | 1/2593 | 242 | 2593 |  |
| 177 | `all_classes/display/swf12` | 0.0% | 1/2593 | 242 | 2593 |  |
| 178 | `all_classes/display/swf13` | 0.0% | 1/2671 | 242 | 2671 |  |
| 179 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 180 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 181 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 182 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 183 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 184 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 185 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 186 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 187 | `all_classes/display/swf30` | 0.0% | 0/2936 | 242 | 2936 |  |
| 188 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 189 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 190 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 191 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 192 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 193 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 194 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 195 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 196 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 197 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 198 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 199 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 200 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 201 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 202 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 203 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 204 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 205 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 206 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 207 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 208 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 209 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 210 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 211 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 212 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 213 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 214 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 215 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 216 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 217 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 218 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 219 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 220 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 221 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 222 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 223 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 224 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 225 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 226 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 227 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 228 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 229 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 230 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 231 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 232 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 233 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 234 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 235 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 236 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 237 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 238 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 239 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 240 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 241 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 242 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 243 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 244 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 245 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 246 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 247 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 248 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 249 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 250 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 251 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 252 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 253 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 254 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 255 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 256 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 257 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 258 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 259 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 260 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 261 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 262 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 263 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 264 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 265 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 266 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 267 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 268 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 269 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 270 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 271 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 272 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 273 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 274 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 275 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 276 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 277 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 278 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 279 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 280 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 281 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 282 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 283 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 284 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 285 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 286 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 287 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 288 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 289 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 290 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 291 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 292 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 293 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 294 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 295 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 296 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 297 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 298 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 299 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 300 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 301 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 302 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 303 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 304 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 305 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 306 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 307 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 308 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 309 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 310 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 311 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 312 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 313 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 314 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 315 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 316 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 317 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 318 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 319 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 320 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 321 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 322 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 323 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 324 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 325 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 326 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 327 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 328 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 329 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 330 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 331 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 332 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 333 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 334 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 335 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 336 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 337 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 338 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 339 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 340 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 341 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 342 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 343 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 344 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 345 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 346 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 347 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 348 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 349 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 350 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 351 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 352 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 353 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 354 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 355 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 356 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 357 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 358 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
