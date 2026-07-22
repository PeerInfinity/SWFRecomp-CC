# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-22 19:47 UTC

**Git SHA**: `9ab376ded1`

**Run Duration**: 143m 57s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1215 |
| Passing | **827** (68.1%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **853** (70.2%) |
| Failing | 362 |
| Total expected lines | 151085 |
| Matching lines | 103389 (68.4%) |
| Mismatched lines | 47696 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 357 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**827 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 2.9s |  |
| 2 | `agal_compiler` | 13 | 3.1s |  |
| 3 | `air_hidden_lookup` | 2 | 2.9s |  |
| 4 | `all_classes/security/swf11` | 3 | 3.0s |  |
| 5 | `amf_custom_obj` | 26 | 2.9s |  |
| 6 | `amf_dictionary` | 9 | 3.0s |  |
| 7 | `amf_function` | 46 | 2.9s |  |
| 8 | `amf_invalid_date` | 2 | 3.0s |  |
| 9 | `amf_missing_prop` | 6 | 2.9s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 4.5s |  |
| 11 | `amf_setter_error` | 8 | 4.6s |  |
| 12 | `amf_vector` | 40 | 4.6s |  |
| 13 | `amf_xml` | 6 | 4.5s |  |
| 14 | `application_domain` | 4 | 4.5s |  |
| 15 | `array_access` | 18 | 4.6s |  |
| 16 | `array_access_interpreter` | 4 | 4.5s |  |
| 17 | `array_access_no_pubns` | 2 | 4.5s |  |
| 18 | `array_concat` | 41 | 4.6s |  |
| 19 | `array_constr` | 10 | 4.5s |  |
| 20 | `array_delete` | 44 | 4.8s |  |
| 21 | `array_enumeration` | 10 | 4.6s |  |
| 22 | `array_enumeration_elements` | 11 | 4.6s |  |
| 23 | `array_every` | 8 | 4.5s |  |
| 24 | `array_filter` | 6 | 4.5s |  |
| 25 | `array_foreach` | 18 | 4.5s |  |
| 26 | `array_hasownproperty` | 11 | 2.0s |  |
| 27 | `array_holes` | 9 | 4.6s |  |
| 28 | `array_index_max` | 84 | 4.4s |  |
| 29 | `array_indexof` | 25 | 4.6s |  |
| 30 | `array_join` | 26 | 4.8s |  |
| 31 | `array_lastindexof` | 29 | 4.7s |  |
| 32 | `array_length` | 14 | 4.7s |  |
| 33 | `array_literal` | 3 | 4.5s |  |
| 34 | `array_map` | 8 | 4.4s |  |
| 35 | `array_pop` | 52 | 4.8s |  |
| 36 | `array_push` | 24 | 4.7s |  |
| 37 | `array_reborrow_bug` | 6 | 4.7s |  |
| 38 | `array_reverse` | 28 | 4.8s |  |
| 39 | `array_shift` | 51 | 2.2s |  |
| 40 | `array_slice` | 39 | 4.8s |  |
| 41 | `array_some` | 8 | 4.7s |  |
| 42 | `array_sort` | 297 | 5.2s |  |
| 43 | `array_sort_fun_swf12` | 2 | 4.7s |  |
| 44 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 45 | `array_sort_random` | 210 | 4.8s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 4.7s |  |
| 47 | `array_sorton` | 545 | 5.4s |  |
| 48 | `array_sparse_ops` | 41 | 4.8s |  |
| 49 | `array_splice` | 133 | 4.9s |  |
| 50 | `array_splice2` | 428 | 5.0s |  |
| 51 | `array_splice_types` | 48 | 4.8s |  |
| 52 | `array_storage` | 8 | 4.8s |  |
| 53 | `array_tolocalestring` | 9 | 4.7s |  |
| 54 | `array_tostring` | 12 | 4.7s |  |
| 55 | `array_unshift` | 24 | 4.7s |  |
| 56 | `array_valueof` | 9 | 4.6s |  |
| 57 | `array_vector_null_callback` | 10 | 4.7s |  |
| 58 | `astype` | 28 | 4.7s |  |
| 59 | `astypelate` | 24 | 4.9s |  |
| 60 | `astypelate_propagates` | 1 | 4.6s |  |
| 61 | `asymmetric_key_events` | 11 | 4.9s |  |
| 62 | `avm2_catchup_dobj` | 158 | 5.3s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 79.2s |  |
| 64 | `bitand` | 1058 | 16.3s |  |
| 65 | `bitmap_constr` | 17 | 5.0s |  |
| 66 | `bitmap_data` | 1000 | 12.9s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 24.5s |  |
| 68 | `bitmap_properties` | 23 | 4.8s |  |
| 69 | `bitmap_subclass` | 7 | 6.3s |  |
| 70 | `bitmap_subclass_properties` | 9 | 5.2s |  |
| 71 | `bitmap_timeline` | 9 | 4.8s |  |
| 72 | `bitmapdata_accuracy` | 1 | 44.2s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 24.4s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.2s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 23.8s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 23.9s |  |
| 77 | `bitmapdata_clone` | 13 | 4.8s |  |
| 78 | `bitmapdata_colortransform` | 0 | 4.9s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 4.7s |  |
| 80 | `bitmapdata_constr` | 22 | 4.7s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 4.9s |  |
| 82 | `bitmapdata_copychannel` | 0 | 25.2s |  |
| 83 | `bitmapdata_copypixels` | 23 | 23.1s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 4.2s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 4.3s |  |
| 86 | `bitmapdata_dispose` | 7 | 4.3s |  |
| 87 | `bitmapdata_draw` | 0 | 23.0s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 4.2s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 22.7s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 22.8s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 4.3s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 4.3s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 4.2s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 22.6s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 4.5s |  |
| 96 | `bitmapdata_embedded` | 9 | 4.3s |  |
| 97 | `bitmapdata_fillrect` | 0 | 4.3s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 22.8s |  |
| 99 | `bitmapdata_floodfill` | 35 | 4.2s |  |
| 100 | `bitmapdata_getpixels` | 39 | 22.6s |  |
| 101 | `bitmapdata_getvector` | 27 | 1.8s |  |
| 102 | `bitmapdata_histogram` | 59 | 1.8s |  |
| 103 | `bitmapdata_hittest` | 112 | 4.8s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 4.3s |  |
| 105 | `bitmapdata_opaque` | 0 | 4.3s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 22.7s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 4.5s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 4.2s |  |
| 109 | `bitmapdata_setpixels` | 286 | 4.4s |  |
| 110 | `bitmapdata_setvector` | 26 | 4.4s |  |
| 111 | `bitmapdata_sync` | 0 | 4.4s |  |
| 112 | `bitmapdata_threshold` | 176 | 5.0s |  |
| 113 | `bitnot` | 46 | 4.3s |  |
| 114 | `bitor` | 1058 | 15.5s |  |
| 115 | `bitxor` | 1058 | 15.4s |  |
| 116 | `blend_multiply_alpha` | 0 | 4.3s |  |
| 117 | `blend_scroll` | 0 | 4.3s |  |
| 118 | `boolean_constr` | 32 | 4.6s |  |
| 119 | `boolean_negation` | 30 | 4.6s |  |
| 120 | `boolean_tostring` | 8 | 4.7s |  |
| 121 | `broadcast_event` | 7 | 4.5s |  |
| 122 | `button_nested_frame` | 48 | 23.4s |  |
| 123 | `bytearray` | 48 | 4.9s |  |
| 124 | `bytearray_compress` | 31 | 4.6s |  |
| 125 | `bytearray_errors` | 24 | 4.7s |  |
| 126 | `bytearray_method_serialization` | 1 | 2.0s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 4.5s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 4.6s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 4.6s |  |
| 130 | `bytearray_serialization` | 3 | 4.6s |  |
| 131 | `bytearray_string_null` | 19 | 4.8s |  |
| 132 | `bytearray_tostring` | 15 | 4.6s |  |
| 133 | `bytearray_utf16` | 8 | 4.5s |  |
| 134 | `bytearray_writeobject` | 24 | 4.4s |  |
| 135 | `callee_in_initializer` | 6 | 4.5s |  |
| 136 | `callproplex_class` | 1 | 4.5s |  |
| 137 | `catch_class` | 6 | 4.6s |  |
| 138 | `catch_scope_slot` | 7 | 4.7s |  |
| 139 | `checkfilter` | 4 | 2.0s |  |
| 140 | `class_call` | 32 | 23.0s |  |
| 141 | `class_cast_call` | 14 | 4.6s |  |
| 142 | `class_enumeration` | 4 | 4.6s |  |
| 143 | `class_has_own_property` | 2 | 4.6s |  |
| 144 | `class_init_interpreter_mode` | 1 | 4.5s |  |
| 145 | `class_is` | 32 | 4.7s |  |
| 146 | `class_methods` | 5 | 4.6s |  |
| 147 | `class_object_properties` | 10 | 4.7s |  |
| 148 | `class_singleton` | 18 | 4.6s |  |
| 149 | `class_supercalls_errors` | 35 | 4.8s |  |
| 150 | `class_supercalls_mismatched` | 26 | 4.7s |  |
| 151 | `class_superclass_wrong_order` | 1 | 24.2s |  |
| 152 | `class_to_locale_string` | 2 | 4.9s |  |
| 153 | `class_to_string` | 2 | 4.7s |  |
| 154 | `class_value_of` | 2 | 4.7s |  |
| 155 | `click_block` | 5 | 24.3s |  |
| 156 | `click_invisible` | 3 | 4.9s |  |
| 157 | `closures` | 12 | 4.8s |  |
| 158 | `coerce_return_type` | 40 | 5.0s |  |
| 159 | `coerce_return_type_fail` | 2 | 4.7s |  |
| 160 | `coerce_return_void` | 3 | 4.8s |  |
| 161 | `coerce_string` | 86 | 4.9s |  |
| 162 | `coerce_string_precision` | 28 | 4.8s |  |
| 163 | `coerce_to_primitive_side_effects` | 29 | 4.7s |  |
| 164 | `construct_errors_swf10` | 8 | 4.8s |  |
| 165 | `construct_frame_list` | 22 | 24.4s |  |
| 166 | `constructor_call` | 3 | 4.8s |  |
| 167 | `constructors_vs_timeline` | 5 | 26.4s |  |
| 168 | `constructprop_dynamic_primitive` | 7 | 4.9s |  |
| 169 | `control_flow_bool` | 4 | 4.8s |  |
| 170 | `control_flow_stricteq` | 8 | 4.8s |  |
| 171 | `convert_boolean` | 30 | 4.8s |  |
| 172 | `convert_integer` | 90 | 5.0s |  |
| 173 | `convert_number` | 56 | 2.2s |  |
| 174 | `convert_uinteger` | 90 | 5.0s |  |
| 175 | `cryptscore` | 11 | 4.9s |  |
| 176 | `declocal` | 46 | 4.7s |  |
| 177 | `declocal_i` | 46 | 4.6s |  |
| 178 | `decrement` | 46 | 4.6s |  |
| 179 | `decrement_i` | 46 | 2.0s |  |
| 180 | `default_values` | 7 | 4.5s |  |
| 181 | `dictionary_access` | 62 | 4.7s |  |
| 182 | `dictionary_access_no_pubns` | 2 | 4.4s |  |
| 183 | `dictionary_delete` | 101 | 5.0s |  |
| 184 | `dictionary_foreach` | 42 | 4.7s |  |
| 185 | `dictionary_hasownproperty` | 63 | 4.8s |  |
| 186 | `dictionary_in` | 62 | 4.8s |  |
| 187 | `dictionary_iter_modify` | 8 | 4.6s |  |
| 188 | `dictionary_namespaces` | 36 | 4.6s |  |
| 189 | `dictionary_primitive_keys` | 29 | 4.5s |  |
| 190 | `displayobject_alpha` | 277 | 4.5s |  |
| 191 | `displayobject_blendmode` | 0 | 23.1s |  |
| 192 | `displayobject_colortransform_nested` | 0 | 23.0s |  |
| 193 | `displayobject_from_enterframe` | 1 | 22.7s |  |
| 194 | `displayobject_getbounds_shape` | 0 | 22.8s |  |
| 195 | `displayobject_height` | 6052 | 23.2s |  |
| 196 | `displayobject_hittestobject` | 32 | 4.6s |  |
| 197 | `displayobject_invalid_floats` | 60 | 4.5s |  |
| 198 | `displayobject_invalid_props` | 3 | 4.4s |  |
| 199 | `displayobject_mask` | 3 | 4.5s |  |
| 200 | `displayobject_mask_self_referential` | 0 | 4.4s |  |
| 201 | `displayobject_metaData` | 3 | 3.8s |  |
| 202 | `displayobject_name` | 22 | 18.4s |  |
| 203 | `displayobject_name_from_timeline` | 24 | 4.0s |  |
| 204 | `displayobject_parent` | 12 | 3.6s |  |
| 205 | `displayobject_root` | 24 | 3.6s |  |
| 206 | `displayobject_rotation` | 1284 | 3.7s |  |
| 207 | `displayobject_set_matrix_nested` | 0 | 18.5s |  |
| 208 | `displayobject_subclass` | 2 | 3.7s |  |
| 209 | `displayobject_visible` | 23 | 3.6s |  |
| 210 | `displayobject_width` | 4852 | 18.7s |  |
| 211 | `displayobject_x` | 614 | 3.6s |  |
| 212 | `displayobject_y` | 617 | 3.6s |  |
| 213 | `displayobjectcontainer_addchild` | 32 | 3.8s |  |
| 214 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 3.9s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 3.9s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 3.7s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.0s |  |
| 218 | `displayobjectcontainer_addchildat` | 42 | 3.7s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.7s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 3.8s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 2.3s |  |
| 222 | `displayobjectcontainer_contains` | 66 | 18.1s |  |
| 223 | `displayobjectcontainer_getchildat` | 4 | 3.7s |  |
| 224 | `displayobjectcontainer_getchildbyname` | 9 | 3.6s |  |
| 225 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 3.9s |  |
| 226 | `displayobjectcontainer_getchildindex` | 28 | 4.4s |  |
| 227 | `displayobjectcontainer_removechild` | 10 | 4.0s |  |
| 228 | `displayobjectcontainer_removechild_errors` | 4 | 3.7s |  |
| 229 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 3.6s |  |
| 230 | `displayobjectcontainer_removechildat` | 18 | 3.9s |  |
| 231 | `displayobjectcontainer_removechildren` | 51 | 3.8s |  |
| 232 | `displayobjectcontainer_setchildindex` | 42 | 3.5s |  |
| 233 | `displayobjectcontainer_stopallmovieclips` | 2 | 18.7s |  |
| 234 | `displayobjectcontainer_swapchildren` | 42 | 3.8s |  |
| 235 | `displayobjectcontainer_swapchildrenat` | 42 | 3.8s |  |
| 236 | `displayobjectcontainer_timelineinstance` | 48 | 18.1s |  |
| 237 | `divide` | 1058 | 16.2s |  |
| 238 | `doabc_is_eager` | 1 | 22.2s |  |
| 239 | `documentclass` | 9 | 4.6s |  |
| 240 | `drag_drop` | 10 | 4.6s |  |
| 241 | `duplicate_defs` | 1 | 4.2s |  |
| 242 | `eager_init` | 1 | 4.4s |  |
| 243 | `edit_text_linkage` | 7 | 4.6s |  |
| 244 | `edittext_align` | 60 | 4.8s |  |
| 245 | `edittext_always_show_selection` | 0 | 22.8s |  |
| 246 | `edittext_antialiastype` | 296 | 4.7s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 5.8s |  |
| 248 | `edittext_autosize` | 39 | 4.8s |  |
| 249 | `edittext_autosize_align` | 0 | 22.5s |  |
| 250 | `edittext_autosize_height_dynamic` | 60 | 22.4s |  |
| 251 | `edittext_autosize_height_input` | 60 | 4.6s |  |
| 252 | `edittext_autosize_lazy_bounds_events` | 65 | 4.7s |  |
| 253 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.5s |  |
| 254 | `edittext_autosize_lazy_bounds_props` | 490 | 5.8s |  |
| 255 | `edittext_autosize_lazy_bounds_visual` | 0 | 22.4s |  |
| 256 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.7s |  |
| 257 | `edittext_bottom_scroll_v_basic` | 210 | 4.6s |  |
| 258 | `edittext_bounds_scale` | 24 | 22.2s |  |
| 259 | `edittext_bullet` | 30 | 4.5s |  |
| 260 | `edittext_default_format` | 221 | 4.8s |  |
| 261 | `edittext_default_format_empty` | 136 | 4.7s |  |
| 262 | `edittext_empty_text_format` | 7 | 4.5s |  |
| 263 | `edittext_focus_selection` | 5 | 4.4s |  |
| 264 | `edittext_font_size` | 45 | 4.5s |  |
| 265 | `edittext_format_empty_font` | 8 | 4.4s |  |
| 266 | `edittext_get_char_index_at_point` | 4 | 22.7s |  |
| 267 | `edittext_get_line_index_at_point` | 2 | 22.6s |  |
| 268 | `edittext_get_line_index_of_char` | 76 | 5.4s |  |
| 269 | `edittext_getcharboundaries` | 172 | 4.8s |  |
| 270 | `edittext_getcharboundaries_missing_glyphs` | 63 | 18.6s |  |
| 271 | `edittext_getcharboundaries_scroll` | 85 | 3.8s |  |
| 272 | `edittext_getlinemetrics` | 146 | 3.8s |  |
| 273 | `edittext_html` | 3101 | 4.0s |  |
| 274 | `edittext_html_condensewhite` | 487 | 3.7s |  |
| 275 | `edittext_html_entity` | 4 | 3.8s |  |
| 276 | `edittext_html_font_size_swf12` | 267 | 3.7s |  |
| 277 | `edittext_html_font_size_swf13` | 273 | 3.4s |  |
| 278 | `edittext_html_roundtrip` | 17 | 3.6s |  |
| 279 | `edittext_input_control` | 12 | 3.7s |  |
| 280 | `edittext_leading` | 9 | 3.9s |  |
| 281 | `edittext_letter_spacing` | 15 | 3.6s |  |
| 282 | `edittext_line_methods` | 294 | 4.7s |  |
| 283 | `edittext_line_metrics` | 11 | 19.4s |  |
| 284 | `edittext_margins` | 25 | 3.6s |  |
| 285 | `edittext_max_scroll_h_basic` | 475 | 3.8s |  |
| 286 | `edittext_max_scroll_v_basic` | 1000 | 3.7s |  |
| 287 | `edittext_mousedown` | 3 | 3.9s |  |
| 288 | `edittext_mouseenabled` | 26 | 3.7s |  |
| 289 | `edittext_newline_character` | 22 | 3.6s |  |
| 290 | `edittext_newline_stripping` | 64 | 5.7s |  |
| 291 | `edittext_newlines` | 30 | 3.6s |  |
| 292 | `edittext_paragraph_methods` | 257 | 3.8s |  |
| 293 | `edittext_paste_events` | 8 | 4.4s |  |
| 294 | `edittext_paste_maxchars` | 4 | 3.6s |  |
| 295 | `edittext_paste_restrict` | 16 | 3.5s |  |
| 296 | `edittext_restrict` | 191 | 3.9s |  |
| 297 | `edittext_restrict_events` | 22 | 3.6s |  |
| 298 | `edittext_scrollh` | 10 | 3.6s |  |
| 299 | `edittext_selected_text` | 9 | 3.6s |  |
| 300 | `edittext_set_html_same` | 17 | 3.6s |  |
| 301 | `edittext_set_text_vs_html` | 9 | 3.6s |  |
| 302 | `edittext_stylesheet` | 536 | 4.0s |  |
| 303 | `edittext_stylesheet_custom_tag` | 76 | 3.6s |  |
| 304 | `edittext_stylesheet_display` | 272 | 3.7s |  |
| 305 | `edittext_underline` | 40 | 3.6s |  |
| 306 | `edittext_width_height` | 103 | 3.8s |  |
| 307 | `edittext_wordwrap_word` | 150 | 6.4s |  |
| 308 | `edittext_wrap_breaks` | 2375 | 5.4s |  |
| 309 | `empty_bounds` | 1 | 4.7s |  |
| 310 | `equals` | 512 | 8.7s |  |
| 311 | `error_prototype` | 15 | 4.8s |  |
| 312 | `error_stack_trace_debug_swf17` | 0 | 23.7s |  |
| 313 | `error_stack_trace_debug_swf18` | 0 | 4.5s |  |
| 314 | `error_stack_trace_release_swf17` | 0 | 4.5s |  |
| 315 | `error_stack_trace_release_swf18` | 0 | 4.4s |  |
| 316 | `error_tostring` | 29 | 5.0s |  |
| 317 | `es3_inheritance` | 31 | 5.0s |  |
| 318 | `es4_inheritance` | 30 | 5.0s |  |
| 319 | `es4_interfaces` | 30 | 5.0s |  |
| 320 | `es4_method_binding` | 8 | 5.0s |  |
| 321 | `es4_oop_prototypes` | 14 | 5.2s |  |
| 322 | `es4_protected_inheritance` | 6 | 5.0s |  |
| 323 | `event_bubbles` | 2 | 5.0s |  |
| 324 | `event_cancelable` | 2 | 4.8s |  |
| 325 | `event_clone` | 20 | 4.8s |  |
| 326 | `event_clone_error_redispatch` | 3 | 4.8s |  |
| 327 | `event_clone_on_redispatch` | 10 | 4.8s |  |
| 328 | `event_formattostring` | 31 | 4.9s |  |
| 329 | `event_isdefaultprevented` | 12 | 4.7s |  |
| 330 | `event_target_getter` | 5 | 2.1s |  |
| 331 | `event_target_set` | 9 | 4.7s |  |
| 332 | `event_type` | 1 | 4.7s |  |
| 333 | `event_valueof_tostring` | 18 | 4.6s |  |
| 334 | `eventdispatcher_dispatchevent` | 12 | 4.6s |  |
| 335 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.6s |  |
| 336 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.6s |  |
| 337 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.6s |  |
| 338 | `eventdispatcher_dispatchevent_this` | 5 | 4.6s |  |
| 339 | `eventdispatcher_haseventlistener` | 25 | 4.7s |  |
| 340 | `eventdispatcher_interface_invoke` | 1 | 4.6s |  |
| 341 | `eventdispatcher_tostring` | 10 | 4.7s |  |
| 342 | `eventdispatcher_willtrigger` | 25 | 4.5s |  |
| 343 | `falsiness` | 30 | 5.0s |  |
| 344 | `fast_index_access` | 12 | 5.0s |  |
| 345 | `finddef` | 3 | 4.8s |  |
| 346 | `findprop_global_prototype` | 6 | 4.8s |  |
| 347 | `flash_xml` | 29 | 4.9s |  |
| 348 | `flash_xml_cloneNode` | 22 | 4.8s |  |
| 349 | `flash_xml_namespace` | 109 | 4.8s |  |
| 350 | `flash_xml_removeNode` | 60 | 4.8s |  |
| 351 | `focus_events_code` | 161 | 25.3s |  |
| 352 | `focus_events_key_same_object` | 26 | 4.5s |  |
| 353 | `focus_events_mixed_key_mouse` | 100 | 22.5s |  |
| 354 | `focus_events_mouse_same_object` | 40 | 20.0s |  |
| 355 | `focus_remove` | 20 | 20.1s |  |
| 356 | `focus_root_movie` | 4 | 20.7s |  |
| 357 | `focus_stage` | 1 | 4.1s |  |
| 358 | `focusrect` | 18 | 4.6s |  |
| 359 | `font_description_clone` | 14 | 3.9s |  |
| 360 | `font_embedded` | 24 | 4.2s |  |
| 361 | `font_enumeratefonts` | 41 | 4.5s |  |
| 362 | `font_enumeratefonts_filter` | 4 | 21.1s |  |
| 363 | `font_hasglyphs` | 40 | 4.3s |  |
| 364 | `framelabel_constr` | 5 | 5.2s |  |
| 365 | `function_call` | 12 | 3.9s |  |
| 366 | `function_call_arguments` | 46 | 3.9s |  |
| 367 | `function_call_arguments_enumerate` | 5 | 3.9s |  |
| 368 | `function_call_coercion` | 108 | 4.4s |  |
| 369 | `function_call_default` | 6 | 3.7s |  |
| 370 | `function_call_rest` | 22 | 3.9s |  |
| 371 | `function_call_types` | 3 | 3.8s |  |
| 372 | `function_call_via_apply` | 11 | 4.0s |  |
| 373 | `function_call_via_call` | 3 | 3.9s |  |
| 374 | `function_display_anonymous` | 7 | 1.5s |  |
| 375 | `function_length` | 6 | 3.9s |  |
| 376 | `function_object` | 2 | 3.8s |  |
| 377 | `function_proto` | 5 | 3.8s |  |
| 378 | `function_proto_created` | 61 | 3.9s |  |
| 379 | `function_to_locale_string` | 4 | 3.9s |  |
| 380 | `function_to_string` | 4 | 4.0s |  |
| 381 | `function_type` | 6 | 4.2s |  |
| 382 | `function_unbound_this` | 51 | 4.0s |  |
| 383 | `function_value_of` | 4 | 3.8s |  |
| 384 | `get_definition_by_name` | 11 | 4.0s |  |
| 385 | `get_qualified_class_name` | 20 | 4.0s |  |
| 386 | `get_qualified_super_class_name` | 18 | 4.4s |  |
| 387 | `get_slot_edge_cases` | 1 | 22.5s |  |
| 388 | `get_timer` | 2 | 4.3s |  |
| 389 | `getglobalslot` | 1 | 4.2s |  |
| 390 | `getouterscope` | 8 | 4.2s |  |
| 391 | `getter_different_namespace_setter` | 2 | 4.3s |  |
| 392 | `goto_button_nested_framescript` | 28 | 23.2s |  |
| 393 | `goto_in_constructframe` | 12 | 23.0s |  |
| 394 | `goto_in_scene_last_frame` | 2 | 22.6s |  |
| 395 | `goto_methods` | 56 | 4.5s |  |
| 396 | `goto_methods_swfver10` | 8 | 4.3s |  |
| 397 | `goto_nested_construct_sibling` | 18 | 4.7s |  |
| 398 | `goto_nested_framescript` | 9 | 4.4s |  |
| 399 | `goto_on_orphan` | 15 | 4.5s |  |
| 400 | `graphics_bad_direct_commands` | 5 | 4.8s |  |
| 401 | `graphics_bitmap_fill` | 0 | 5.8s |  |
| 402 | `graphics_bitmaps` | 0 | 4.5s |  |
| 403 | `graphics_direct_commands` | 0 | 4.5s |  |
| 404 | `graphics_draw_triangles` | 98 | 24.0s |  |
| 405 | `graphics_gradients` | 0 | 4.4s |  |
| 406 | `graphics_gradients_nulls` | 0 | 1.8s |  |
| 407 | `graphics_path` | 56 | 4.4s |  |
| 408 | `graphics_round_rects` | 0 | 4.3s |  |
| 409 | `graphics_simple_shapes` | 0 | 4.3s |  |
| 410 | `greaterequals` | 512 | 7.7s |  |
| 411 | `greaterthan` | 512 | 7.7s |  |
| 412 | `has_own_property` | 102 | 4.8s |  |
| 413 | `hasownproperty_namespaces` | 2 | 4.2s |  |
| 414 | `hello_world` | 1 | 4.2s |  |
| 415 | `hittest_morph` | 30 | 4.4s |  |
| 416 | `if_eq` | 10 | 4.4s |  |
| 417 | `if_gt` | 1 | 4.4s |  |
| 418 | `if_gte` | 10 | 1.8s |  |
| 419 | `if_lt` | 1 | 0.5s |  |
| 420 | `if_lte` | 10 | 4.5s |  |
| 421 | `if_ne` | 7 | 4.5s |  |
| 422 | `if_stricteq` | 6 | 4.5s |  |
| 423 | `if_strictne` | 11 | 4.5s |  |
| 424 | `in` | 102 | 4.9s |  |
| 425 | `inclocal` | 46 | 4.5s |  |
| 426 | `inclocal_i` | 46 | 4.5s |  |
| 427 | `increment` | 46 | 4.5s |  |
| 428 | `increment_i` | 46 | 4.5s |  |
| 429 | `instanceof` | 58 | 4.7s |  |
| 430 | `instantiation_on_enter_frame` | 7 | 22.2s |  |
| 431 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.4s |  |
| 432 | `int_constr` | 92 | 4.6s |  |
| 433 | `int_edge_cases` | 19 | 4.4s |  |
| 434 | `int_instanceof` | 3 | 4.3s |  |
| 435 | `int_tofixed` | 1215 | 4.3s |  |
| 436 | `int_tostring` | 3375 | 4.7s |  |
| 437 | `interactiveobject_enabled` | 25 | 4.3s |  |
| 438 | `interface_namespaces` | 78 | 4.6s |  |
| 439 | `is_finite` | 46 | 4.5s |  |
| 440 | `is_nan` | 46 | 4.3s |  |
| 441 | `is_prototype_of` | 12 | 4.4s |  |
| 442 | `issue_10221` | 2 | 4.4s |  |
| 443 | `issue_13780` | 12 | 4.4s |  |
| 444 | `issue_14901` | 1 | 4.4s |  |
| 445 | `issue_17675_edittext_paste_maxchars` | 1 | 4.4s |  |
| 446 | `issue_5292` | 5 | 4.4s |  |
| 447 | `issue_8630` | 2 | 22.0s |  |
| 448 | `issue_8630_scriptremove` | 11 | 4.4s |  |
| 449 | `istype` | 24 | 1.9s |  |
| 450 | `istypelate` | 58 | 4.7s |  |
| 451 | `istypelate_coerce` | 198 | 5.5s |  |
| 452 | `json_errors` | 9 | 22.6s |  |
| 453 | `json_parse` | 21 | 4.5s |  |
| 454 | `json_version_gated` | 1 | 4.4s |  |
| 455 | `key_input_80percent` | 1812 | 4.6s |  |
| 456 | `key_input_location` | 126 | 4.6s |  |
| 457 | `key_input_numpad` | 384 | 4.5s |  |
| 458 | `lazyinit` | 17 | 4.5s |  |
| 459 | `lessequals` | 512 | 8.4s |  |
| 460 | `lessthan` | 512 | 8.4s |  |
| 461 | `loaderinfo_properties` | 18 | 22.8s |  |
| 462 | `loaderinfo_root` | 10 | 4.6s |  |
| 463 | `loaderinfo_root_allows` | 2 | 4.5s |  |
| 464 | `lshift` | 1058 | 16.6s |  |
| 465 | `mask_reapply` | 1 | 23.0s |  |
| 466 | `math` | 497 | 4.9s |  |
| 467 | `missing_external_interface` | 10 | 4.5s |  |
| 468 | `modulo` | 1058 | 16.6s |  |
| 469 | `morph_shape` | 2 | 22.7s |  |
| 470 | `mouse_click_events` | 90 | 22.6s |  |
| 471 | `mouse_double_click_events` | 188 | 4.6s |  |
| 472 | `mouse_empty_parent` | 4 | 4.5s |  |
| 473 | `mouse_over_while_dragging` | 3 | 4.6s |  |
| 474 | `mouse_pick_button_mode` | 2 | 4.7s |  |
| 475 | `mouse_sibling` | 8 | 4.6s |  |
| 476 | `movieclip_addframescript` | 3 | 23.6s |  |
| 477 | `movieclip_child_property` | 16 | 5.1s |  |
| 478 | `movieclip_constr` | 21 | 4.8s |  |
| 479 | `movieclip_currentlabels` | 17 | 25.5s |  |
| 480 | `movieclip_currentlabels_dupes1` | 46 | 24.3s |  |
| 481 | `movieclip_currentlabels_dupes2` | 30 | 4.7s |  |
| 482 | `movieclip_currentlabels_dupes3` | 67 | 4.7s |  |
| 483 | `movieclip_currentscene` | 12 | 23.5s |  |
| 484 | `movieclip_dispatchevent` | 430 | 4.8s |  |
| 485 | `movieclip_dispatchevent_cancel` | 102 | 4.8s |  |
| 486 | `movieclip_dispatchevent_handlerorder` | 251 | 4.8s |  |
| 487 | `movieclip_dispatchevent_selfadd` | 80 | 4.6s |  |
| 488 | `movieclip_dispatchevent_target` | 899 | 4.8s |  |
| 489 | `movieclip_displayevents` | 96 | 23.7s |  |
| 490 | `movieclip_displayevents_clickgoto` | 676 | 23.5s |  |
| 491 | `movieclip_displayevents_clickgoto2` | 2001 | 5.1s |  |
| 492 | `movieclip_displayevents_clickplay` | 575 | 4.8s |  |
| 493 | `movieclip_displayevents_clicksymbol` | 562 | 4.8s |  |
| 494 | `movieclip_displayevents_constructframegoto` | 140 | 4.9s |  |
| 495 | `movieclip_displayevents_constructframeplay` | 50 | 4.9s |  |
| 496 | `movieclip_displayevents_constructframesymbol` | 144 | 4.8s |  |
| 497 | `movieclip_displayevents_dblhandler` | 21 | 4.8s |  |
| 498 | `movieclip_displayevents_enterframegoto` | 149 | 4.9s |  |
| 499 | `movieclip_displayevents_enterframeplay` | 48 | 4.7s |  |
| 500 | `movieclip_displayevents_enterframesymbol` | 149 | 23.1s |  |
| 501 | `movieclip_displayevents_exitframegoto` | 106 | 4.7s |  |
| 502 | `movieclip_displayevents_exitframeplay` | 44 | 4.7s |  |
| 503 | `movieclip_displayevents_exitframesymbol` | 135 | 4.8s |  |
| 504 | `movieclip_displayevents_looping` | 63 | 23.4s |  |
| 505 | `movieclip_displayevents_stopped` | 113 | 4.9s |  |
| 506 | `movieclip_displayevents_swap` | 96 | 2.0s |  |
| 507 | `movieclip_displayevents_timeline` | 128 | 23.2s |  |
| 508 | `movieclip_drawrect` | 54 | 4.6s |  |
| 509 | `movieclip_frameconstruct_skipped` | 9 | 4.7s |  |
| 510 | `movieclip_goto_during_frame_script` | 15 | 4.7s |  |
| 511 | `movieclip_goto_overwrite` | 14 | 23.2s |  |
| 512 | `movieclip_goto_scene_last_frame_int` | 1 | 23.7s |  |
| 513 | `movieclip_goto_scene_last_frame_label` | 1 | 4.5s |  |
| 514 | `movieclip_gotoandplay` | 15 | 22.8s |  |
| 515 | `movieclip_gotoandstop` | 13 | 4.6s |  |
| 516 | `movieclip_gotoandstop_children` | 4 | 4.6s |  |
| 517 | `movieclip_gotoandstop_framescripts1` | 4 | 4.6s |  |
| 518 | `movieclip_gotoandstop_framescripts2` | 4 | 2.0s |  |
| 519 | `movieclip_gotoandstop_framescripts_self` | 7 | 24.2s |  |
| 520 | `movieclip_gotoandstop_queueing` | 12 | 22.9s |  |
| 521 | `movieclip_next_frame` | 2 | 22.9s |  |
| 522 | `movieclip_next_scene` | 6 | 22.9s |  |
| 523 | `movieclip_play` | 3 | 4.5s |  |
| 524 | `movieclip_prev_frame` | 3 | 4.3s |  |
| 525 | `movieclip_prev_scene` | 7 | 4.6s |  |
| 526 | `movieclip_properties` | 79 | 23.1s |  |
| 527 | `movieclip_queued_noop_goto_swf10` | 9 | 4.7s |  |
| 528 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 529 | `movieclip_scenes` | 11 | 4.5s |  |
| 530 | `movieclip_soundtransform` | 831 | 25.0s |  |
| 531 | `movieclip_stop` | 1 | 22.8s |  |
| 532 | `movieclip_super_is_symbol` | 20 | 4.9s |  |
| 533 | `movieclip_symbol_constr` | 8 | 4.7s |  |
| 534 | `movieclip_text_mousedown` | 1 | 4.6s |  |
| 535 | `movieclip_willtrigger` | 5 | 4.8s |  |
| 536 | `multiply` | 1058 | 17.1s |  |
| 537 | `namespace_constr` | 253 | 4.8s |  |
| 538 | `namespace_constr_args` | 1 | 4.4s |  |
| 539 | `namespace_enumeration_order` | 7 | 4.5s |  |
| 540 | `nan_scale` | 9 | 4.5s |  |
| 541 | `negate` | 30 | 4.6s |  |
| 542 | `negative_volume_panned` | 0 | 4.7s |  |
| 543 | `nested_iteration` | 11 | 4.5s |  |
| 544 | `net_getClassByAlias` | 3 | 4.6s |  |
| 545 | `newactivation_in_script_init` | 3 | 4.6s |  |
| 546 | `newclass_twice` | 3 | 4.6s |  |
| 547 | `nonconflicting_declarations` | 0 | 4.7s |  |
| 548 | `null_void_types` | 8 | 4.7s |  |
| 549 | `number_autoconv` | 21 | 4.7s |  |
| 550 | `number_autoconv_amf` | 132 | 4.7s |  |
| 551 | `number_autoconv_array_sort_32bit` | 1 | 4.6s |  |
| 552 | `number_constr` | 58 | 4.8s |  |
| 553 | `number_toexponential` | 378 | 4.7s |  |
| 554 | `number_toexponential2` | 35 | 4.7s |  |
| 555 | `number_tofixed` | 378 | 4.5s |  |
| 556 | `number_toprecision` | 350 | 4.7s |  |
| 557 | `obfuscated_class_names` | 3 | 4.5s |  |
| 558 | `object_enumeration` | 10 | 4.6s |  |
| 559 | `object_prototype` | 4 | 4.6s |  |
| 560 | `object_to_locale_string` | 2 | 4.6s |  |
| 561 | `object_to_string` | 2 | 4.5s |  |
| 562 | `object_value_of` | 2 | 1.8s |  |
| 563 | `op_coerce` | 54 | 4.7s |  |
| 564 | `op_coerce_x` | 54 | 4.7s |  |
| 565 | `op_escxattr` | 2 | 4.7s |  |
| 566 | `op_escxelem` | 2 | 4.6s |  |
| 567 | `op_lookupswitch` | 4 | 4.7s |  |
| 568 | `optimize_coerce` | 1 | 4.6s |  |
| 569 | `orphan_movie_complex` | 80 | 5.0s |  |
| 570 | `orphan_movie_reorder` | 111 | 23.7s |  |
| 571 | `package_namespace` | 7 | 4.4s |  |
| 572 | `param_default_value_has_zero_cpool_index` | 1 | 4.5s |  |
| 573 | `parent_early_access_child` | 16 | 23.1s |  |
| 574 | `pixelbender_effect_BlurredFocus` | 0 | 27.8s |  |
| 575 | `pixelbender_effect_glassDisplace` | 0 | 10.5s |  |
| 576 | `pixelbender_effect_smudge` | 0 | 8.2s |  |
| 577 | `pixelbender_effect_tintype` | 0 | 7.3s |  |
| 578 | `pixelbender_effect_twirl` | 0 | 8.7s |  |
| 579 | `pixelbender_images` | 0 | 6.9s |  |
| 580 | `place_multiple` | 17 | 25.6s |  |
| 581 | `place_object_replace` | 9 | 5.0s |  |
| 582 | `place_object_replace_2` | 24 | 5.1s |  |
| 583 | `place_object_same_depth_frame` | 1 | 4.9s |  |
| 584 | `point` | 132 | 5.4s |  |
| 585 | `primitive_edge_cases` | 1 | 4.7s |  |
| 586 | `property_priority` | 22 | 4.1s |  |
| 587 | `property_priority_three_level` | 6 | 20.6s |  |
| 588 | `propertyisenumerable_namespaces` | 6 | 3.9s |  |
| 589 | `prototype_set_null` | 7 | 3.9s |  |
| 590 | `proxy_callproperty` | 24 | 3.9s |  |
| 591 | `proxy_deleteproperty` | 64 | 4.0s |  |
| 592 | `proxy_enumeration` | 34 | 4.0s |  |
| 593 | `proxy_getproperty` | 77 | 4.0s |  |
| 594 | `proxy_hasownproperty` | 8 | 4.0s |  |
| 595 | `proxy_hasproperty` | 32 | 3.9s |  |
| 596 | `proxy_serialize` | 9 | 4.0s |  |
| 597 | `proxy_setproperty` | 42 | 4.2s |  |
| 598 | `qname_as_lazy_name_attribute_multiname` | 1 | 3.9s |  |
| 599 | `qname_constr` | 32 | 4.1s |  |
| 600 | `qname_constr_namespace` | 24 | 3.9s |  |
| 601 | `qname_enumeration` | 9 | 3.9s |  |
| 602 | `qname_indexing` | 23 | 4.2s |  |
| 603 | `qname_tostring` | 25 | 4.0s |  |
| 604 | `qname_valueof` | 29 | 4.0s |  |
| 605 | `regexp_constr` | 148 | 4.3s |  |
| 606 | `regexp_exec` | 19 | 3.9s |  |
| 607 | `regexp_extended` | 47 | 4.0s |  |
| 608 | `regexp_multiargs` | 1 | 3.8s |  |
| 609 | `regexp_test` | 27 | 3.9s |  |
| 610 | `regexp_toString` | 10 | 4.0s |  |
| 611 | `register_script_refresh` | 35 | 21.3s |  |
| 612 | `remove_child_clear_field` | 88 | 21.1s |  |
| 613 | `remove_dobj` | 3 | 4.2s |  |
| 614 | `resolve_order` | 4 | 4.0s |  |
| 615 | `rng` | 1 | 5.1s |  |
| 616 | `rootless` | 42 | 4.0s |  |
| 617 | `rshift` | 1058 | 10.5s |  |
| 618 | `sandbox_type_local_file` | 1 | 3.2s |  |
| 619 | `scene_constr` | 8 | 3.5s |  |
| 620 | `set_local_0` | 31 | 3.4s |  |
| 621 | `set_property_is_enumerable` | 85 | 3.4s |  |
| 622 | `shape_drawrect` | 54 | 3.3s |  |
| 623 | `shared_object_no_root` | 3 | 3.2s |  |
| 624 | `simplebutton_added_to_stage` | 45 | 17.0s |  |
| 625 | `simplebutton_childevents` | 86 | 17.2s |  |
| 626 | `simplebutton_childevents_nested` | 54 | 3.4s |  |
| 627 | `simplebutton_childevents_sprite` | 13 | 3.3s |  |
| 628 | `simplebutton_childprops` | 144 | 3.6s |  |
| 629 | `simplebutton_childshuffle` | 23 | 3.4s |  |
| 630 | `simplebutton_constr` | 36 | 3.2s |  |
| 631 | `simplebutton_constr_childevents` | 48 | 3.3s |  |
| 632 | `simplebutton_constr_params` | 42 | 3.1s |  |
| 633 | `simplebutton_mouseenabled` | 26 | 3.4s |  |
| 634 | `simplebutton_multi_children` | 19 | 3.4s |  |
| 635 | `simplebutton_structure` | 27 | 3.5s |  |
| 636 | `simplebutton_symbolclass` | 68 | 3.8s |  |
| 637 | `slot_disp_id_shared_numbering` | 1 | 16.8s |  |
| 638 | `slots_force_autoassigned` | 1 | 3.6s |  |
| 639 | `sound_embeddedprops` | 26 | 4.8s |  |
| 640 | `sound_play` | 19 | 4.9s |  |
| 641 | `sound_valueof` | 33 | 4.7s |  |
| 642 | `soundchannel_soundtransform` | 835 | 25.0s |  |
| 643 | `soundchannel_soundtransform_exists` | 5 | 23.1s |  |
| 644 | `soundchannel_stop` | 8 | 23.4s |  |
| 645 | `soundmixer_buffertime` | 5 | 4.6s |  |
| 646 | `soundmixer_stopall` | 6 | 23.1s |  |
| 647 | `soundtransform` | 442 | 9.8s |  |
| 648 | `sprite_with_frames` | 0 | 23.4s |  |
| 649 | `stage3d_agal_cross_product` | 0 | 6.9s |  |
| 650 | `stage3d_bitmap` | 0 | 27.9s |  |
| 651 | `stage3d_float1_index` | 0 | 25.6s |  |
| 652 | `stage3d_fractal` | 0 | 7.1s |  |
| 653 | `stage3d_ignore_sampler_override` | 0 | 25.8s |  |
| 654 | `stage3d_program_constants_bytearray_be` | 0 | 26.1s |  |
| 655 | `stage3d_program_constants_bytearray_le` | 0 | 7.7s |  |
| 656 | `stage3d_raytrace` | 0 | 28.6s |  |
| 657 | `stage3d_rotating_cube` | 0 | 7.9s |  |
| 658 | `stage3d_sampler` | 0 | 7.0s |  |
| 659 | `stage3d_sampler_partial_upload` | 0 | 7.0s |  |
| 660 | `stage3d_stencil` | 0 | 25.5s |  |
| 661 | `stage3d_texture` | 0 | 11.8s |  |
| 662 | `stage3d_texture_bytearray` | 0 | 8.1s |  |
| 663 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 7.6s |  |
| 664 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 8.8s |  |
| 665 | `stage3d_triangle` | 0 | 7.1s |  |
| 666 | `stage3d_triangle_bytes4` | 0 | 7.0s |  |
| 667 | `stage3d_triangle_float1` | 0 | 7.0s |  |
| 668 | `stage3d_triangle_index_upload` | 0 | 7.0s |  |
| 669 | `stage_access` | 10 | 4.5s |  |
| 670 | `stage_displayobject_properties` | 24 | 4.4s |  |
| 671 | `stage_framerate_nan` | 7 | 4.6s |  |
| 672 | `stage_framerate_negative` | 6 | 4.5s |  |
| 673 | `stage_framerate_zero` | 6 | 4.5s |  |
| 674 | `stage_invalidate` | 38 | 4.7s |  |
| 675 | `stage_mousechildren` | 2 | 4.5s |  |
| 676 | `stage_mouseenabled` | 15 | 4.5s |  |
| 677 | `stage_overriden_setters` | 31 | 4.7s |  |
| 678 | `stage_properties` | 30 | 4.5s |  |
| 679 | `static_var_with_this_in_ctor` | 2 | 4.5s |  |
| 680 | `stored_properties` | 11 | 4.5s |  |
| 681 | `strict_equality` | 34 | 4.5s |  |
| 682 | `string_call` | 13 | 4.4s |  |
| 683 | `string_case` | 23 | 4.4s |  |
| 684 | `string_char_at` | 27 | 4.4s |  |
| 685 | `string_char_code_at` | 28 | 4.3s |  |
| 686 | `string_constr` | 25 | 4.3s |  |
| 687 | `string_indexof_lastindexof` | 87 | 4.6s |  |
| 688 | `string_length` | 16 | 4.5s |  |
| 689 | `string_locale_compare` | 39 | 4.6s |  |
| 690 | `string_match` | 51 | 4.6s |  |
| 691 | `string_relational_compare` | 4 | 4.3s |  |
| 692 | `string_replace` | 51 | 4.4s |  |
| 693 | `string_search` | 41 | 4.6s |  |
| 694 | `string_split` | 29 | 4.4s |  |
| 695 | `string_substr_negative` | 21 | 4.4s |  |
| 696 | `string_substr_weird` | 182 | 4.4s |  |
| 697 | `subtract` | 1058 | 15.8s |  |
| 698 | `super_get_call` | 12 | 4.4s |  |
| 699 | `supercall_two_classobjects` | 2 | 4.3s |  |
| 700 | `swf8` | 1 | 4.1s |  |
| 701 | `swf_10_queued_goto_scripts_construct` | 52 | 23.0s |  |
| 702 | `swf_9_goto_in_enter_frame` | 17 | 4.4s |  |
| 703 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.4s |  |
| 704 | `swf_9_queued_goto_scripts` | 6 | 22.7s |  |
| 705 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 706 | `swf_9_versioning` | 2 | 4.3s |  |
| 707 | `swf_wrong_frame_count` | 38 | 4.7s |  |
| 708 | `swf_wrong_frame_count_isplaying` | 22 | 4.4s |  |
| 709 | `symbol_class_binary_data` | 8 | 4.6s |  |
| 710 | `symbol_class_conflict` | 4 | 4.8s |  |
| 711 | `symbol_class_root_not_zero` | 1 | 4.5s |  |
| 712 | `symbolclass_invalid_utf8` | 2 | 4.6s |  |
| 713 | `tab_ordering_automatic_advanced` | 184 | 5.4s |  |
| 714 | `tab_ordering_automatic_basic` | 45 | 4.8s |  |
| 715 | `tab_ordering_children` | 116 | 4.8s |  |
| 716 | `tab_ordering_custom_basic` | 34 | 4.7s |  |
| 717 | `text_engine_fontdescription` | 27 | 4.8s |  |
| 718 | `text_run` | 7 | 4.6s |  |
| 719 | `textfield_focusin_event` | 9 | 4.6s |  |
| 720 | `textfield_input_dead_keys_windows` | 15 | 4.7s |  |
| 721 | `textfield_unload` | 39 | 23.7s |  |
| 722 | `textformat` | 1134 | 4.7s |  |
| 723 | `textformat_display` | 14 | 4.7s |  |
| 724 | `textformat_font_max_length` | 4 | 4.7s |  |
| 725 | `throw` | 3 | 4.8s |  |
| 726 | `timeline_scripts` | 3 | 4.9s |  |
| 727 | `timer` | 90 | 5.2s |  |
| 728 | `timer_events` | 3 | 4.6s |  |
| 729 | `timer_finished` | 11 | 4.7s |  |
| 730 | `timer_reset` | 8 | 4.7s |  |
| 731 | `timer_setdelay` | 5 | 4.6s |  |
| 732 | `trace` | 12 | 4.7s |  |
| 733 | `truthiness` | 30 | 4.5s |  |
| 734 | `try_catch` | 11 | 4.6s |  |
| 735 | `try_catch_typed` | 12 | 4.5s |  |
| 736 | `typeof` | 30 | 4.6s |  |
| 737 | `uint_constr` | 92 | 4.8s |  |
| 738 | `uint_tofixed` | 1215 | 4.5s |  |
| 739 | `uint_tostring` | 3375 | 4.9s |  |
| 740 | `unchecked_function` | 15 | 4.5s |  |
| 741 | `urlrequest` | 18 | 4.5s |  |
| 742 | `urshift` | 1058 | 16.5s |  |
| 743 | `vector_class` | 36 | 4.9s |  |
| 744 | `vector_class_call` | 11 | 4.7s |  |
| 745 | `vector_coercion` | 66 | 5.3s |  |
| 746 | `vector_concat` | 90 | 5.1s |  |
| 747 | `vector_constr` | 107 | 5.1s |  |
| 748 | `vector_enumeration` | 5 | 4.5s |  |
| 749 | `vector_every` | 92 | 5.3s |  |
| 750 | `vector_filter` | 95 | 5.3s |  |
| 751 | `vector_holes` | 24 | 4.6s |  |
| 752 | `vector_indexof` | 302 | 9.3s |  |
| 753 | `vector_insertat` | 270 | 5.7s |  |
| 754 | `vector_int_access` | 4 | 4.5s |  |
| 755 | `vector_int_delete` | 11 | 4.5s |  |
| 756 | `vector_join` | 58 | 5.0s |  |
| 757 | `vector_lastindexof` | 302 | 4.5s |  |
| 758 | `vector_legacy` | 10 | 4.5s |  |
| 759 | `vector_map` | 85 | 5.3s |  |
| 760 | `vector_object_final` | 1 | 4.0s |  |
| 761 | `vector_object_toString` | 10 | 4.1s |  |
| 762 | `vector_pushpop` | 255 | 5.4s |  |
| 763 | `vector_reborrow_bug` | 10 | 4.2s |  |
| 764 | `vector_removeat` | 172 | 5.2s |  |
| 765 | `vector_reverse` | 232 | 5.2s |  |
| 766 | `vector_shiftunshift` | 252 | 5.3s |  |
| 767 | `vector_slice` | 331 | 5.7s |  |
| 768 | `vector_sort` | 905 | 12.9s |  |
| 769 | `vector_splice` | 693 | 7.7s |  |
| 770 | `vector_splice_fixed_bug_compat` | 4 | 4.2s |  |
| 771 | `vector_tostring` | 79 | 4.7s |  |
| 772 | `verify_abnormal_loop` | 1 | 4.1s |  |
| 773 | `verify_exception_targets_edge_case` | 1 | 4.1s |  |
| 774 | `verify_lookup_switch_edge_case` | 1 | 4.1s |  |
| 775 | `verify_unreachable_exception` | 2 | 4.1s |  |
| 776 | `versioned_isplaying` | 2 | 4.1s |  |
| 777 | `virtual_properties` | 16 | 4.2s |  |
| 778 | `with` | 4 | 4.1s |  |
| 779 | `xml_abstract_equality` | 36 | 4.3s |  |
| 780 | `xml_advanced` | 52 | 4.2s |  |
| 781 | `xml_appendchild` | 10 | 4.1s |  |
| 782 | `xml_as_attribute` | 9 | 4.1s |  |
| 783 | `xml_attribute` | 35 | 4.3s |  |
| 784 | `xml_attribute_name` | 40 | 4.2s |  |
| 785 | `xml_child` | 25 | 4.2s |  |
| 786 | `xml_childindex` | 7 | 4.1s |  |
| 787 | `xml_children` | 43 | 4.7s |  |
| 788 | `xml_class_call` | 9 | 4.1s |  |
| 789 | `xml_contains` | 197 | 4.3s |  |
| 790 | `xml_copy` | 20 | 4.5s |  |
| 791 | `xml_ctor_from_tostring` | 23 | 4.6s |  |
| 792 | `xml_delete` | 114 | 4.5s |  |
| 793 | `xml_descendants` | 83 | 4.5s |  |
| 794 | `xml_elements` | 6 | 4.4s |  |
| 795 | `xml_equals_namespace_check` | 2 | 4.4s |  |
| 796 | `xml_explicit_use_namespace` | 5 | 23.9s |  |
| 797 | `xml_getdescendants_qname` | 21 | 4.4s |  |
| 798 | `xml_has_property_via_in` | 26 | 4.4s |  |
| 799 | `xml_hasownproperty` | 6 | 4.3s |  |
| 800 | `xml_ignore_white` | 6 | 4.4s |  |
| 801 | `xml_length` | 2 | 4.3s |  |
| 802 | `xml_list_as_attribute` | 9 | 4.4s |  |
| 803 | `xml_list_concat` | 20 | 4.5s |  |
| 804 | `xml_list_enumerate` | 4 | 4.3s |  |
| 805 | `xml_methods_settings` | 3 | 4.4s |  |
| 806 | `xml_mismatched_tag` | 37 | 4.4s |  |
| 807 | `xml_namespace` | 39 | 4.4s |  |
| 808 | `xml_namespace_methods` | 245 | 4.4s |  |
| 809 | `xml_namespaced_property` | 7 | 4.4s |  |
| 810 | `xml_no_namespace` | 1 | 4.3s |  |
| 811 | `xml_nodekind` | 3 | 4.4s |  |
| 812 | `xml_normalize` | 35 | 4.4s |  |
| 813 | `xml_notification_bubbling` | 361 | 4.3s |  |
| 814 | `xml_parent` | 8 | 4.3s |  |
| 815 | `xml_set_children` | 17 | 4.4s |  |
| 816 | `xml_set_name` | 34 | 4.3s |  |
| 817 | `xml_settings` | 6 | 1.6s |  |
| 818 | `xml_simple_complex_content` | 47 | 4.3s |  |
| 819 | `xml_text` | 7 | 4.4s |  |
| 820 | `xml_tostring` | 6 | 4.3s |  |
| 821 | `xml_tostring_namespace` | 12 | 4.4s |  |
| 822 | `xml_unescaping` | 23 | 4.5s |  |
| 823 | `xml_weird_ignores` | 54 | 4.5s |  |
| 824 | `xml_wildcard` | 11 | 4.4s |  |
| 825 | `xmldocument` | 254 | 4.5s |  |
| 826 | `xmlnode` | 3540 | 4.6s |  |
| 827 | `zero_frame_clip` | 3 | 4.6s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 4.5s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 4.8s |  |
| 3 | `blend_transform` | 1 | 1 | 4.3s |  |
| 4 | `coerce_property` | 3 | 3 | 4.8s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 4.9s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 22.7s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 4.7s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 4.4s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 3.7s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 4.8s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 4.9s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 4.3s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 23.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 24.1s |  |
| 15 | `int_toexponential` | 76 | 76 | 4.6s |  |
| 16 | `int_toprecision` | 441 | 441 | 4.6s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 3.4s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 3.0s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 16.2s |  |
| 20 | `soundchannel_position` | 74 | 74 | 24.0s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 4.9s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 4.7s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 22.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 4.8s |  |
| 25 | `uint_toprecision` | 433 | 433 | 4.8s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 4.1s |  |

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
| 24 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 25 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 26 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 27 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 28 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 29 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 30 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 31 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 32 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 33 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 34 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 35 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 36 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 37 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 38 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 39 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
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
| 1 | `domain_memory` | exit code 1 | 4.5s |  |
| 2 | `method_without_body` | exit code 1 | 23.4s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 3.0s |  |
| 4 | `verify_typecheck` | exit code 1 | 4.2s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 34.6s |  |

## All Output Mismatches

**357 tests** with output mismatch, sorted by match rate (best first)

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
| 24 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 25 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 26 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 27 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 28 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 29 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 30 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 31 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 32 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 33 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 34 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 35 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 36 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 37 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 38 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 39 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
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
| 169 | `all_classes/display/swf9` | 0.1% | 2/1959 | 249 | 1959 |  |
| 170 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 171 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 172 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 173 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 174 | `all_classes/display/swf10` | 0.1% | 2/2569 | 249 | 2569 |  |
| 175 | `all_classes/display/swf11` | 0.1% | 2/2593 | 249 | 2593 |  |
| 176 | `all_classes/display/swf12` | 0.1% | 2/2593 | 249 | 2593 |  |
| 177 | `all_classes/display/swf13` | 0.1% | 2/2671 | 249 | 2671 |  |
| 178 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 179 | `all_classes/display/swf30` | 0.0% | 1/2936 | 249 | 2936 |  |
| 180 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 181 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 182 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 183 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 184 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 185 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 186 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 187 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
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
| 270 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 271 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 272 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 273 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 274 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 275 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 276 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 277 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 278 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 279 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 280 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 281 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 282 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 283 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 284 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 285 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 286 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 287 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 288 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 289 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 290 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 291 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 292 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 293 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 294 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 295 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 296 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 297 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 298 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 299 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 300 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 301 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 302 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 303 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 304 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 305 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 306 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 307 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 308 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 309 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 310 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 311 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 312 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 313 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 314 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 315 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 316 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 317 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 318 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 319 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 320 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 321 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 322 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 323 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 324 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 325 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 326 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 327 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 328 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 329 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 330 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 331 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 332 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 333 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 334 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 335 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 336 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 337 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 338 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 339 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 340 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 341 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 342 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 343 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 344 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 345 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 346 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 347 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 348 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 349 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 350 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 351 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 352 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 353 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 354 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 355 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 356 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 357 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
