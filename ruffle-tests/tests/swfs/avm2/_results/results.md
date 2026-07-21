# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-21 21:05 UTC

**Git SHA**: `b36b9a2d40`

**Run Duration**: 138m 22s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1215 |
| Passing | **823** (67.7%) |
| Ruffle-matched | 25 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **848** (69.8%) |
| Failing | 367 |
| Total expected lines | 151085 |
| Matching lines | 103124 (68.3%) |
| Mismatched lines | 47961 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 362 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**823 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 0.4s |  |
| 2 | `agal_compiler` | 13 | 0.4s |  |
| 3 | `air_hidden_lookup` | 2 | 0.4s |  |
| 4 | `all_classes/security/swf11` | 3 | 0.4s |  |
| 5 | `amf_custom_obj` | 26 | 0.4s |  |
| 6 | `amf_dictionary` | 9 | 0.3s |  |
| 7 | `amf_function` | 46 | 0.3s |  |
| 8 | `amf_invalid_date` | 2 | 0.3s |  |
| 9 | `amf_missing_prop` | 6 | 0.3s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 4.2s |  |
| 11 | `amf_setter_error` | 8 | 4.3s |  |
| 12 | `amf_vector` | 40 | 4.3s |  |
| 13 | `amf_xml` | 6 | 4.2s |  |
| 14 | `application_domain` | 4 | 4.2s |  |
| 15 | `array_access` | 18 | 4.2s |  |
| 16 | `array_access_interpreter` | 4 | 4.2s |  |
| 17 | `array_access_no_pubns` | 2 | 4.1s |  |
| 18 | `array_concat` | 41 | 4.2s |  |
| 19 | `array_constr` | 10 | 4.2s |  |
| 20 | `array_delete` | 44 | 4.3s |  |
| 21 | `array_enumeration` | 10 | 4.2s |  |
| 22 | `array_enumeration_elements` | 11 | 4.2s |  |
| 23 | `array_every` | 8 | 4.2s |  |
| 24 | `array_filter` | 6 | 4.2s |  |
| 25 | `array_foreach` | 18 | 4.2s |  |
| 26 | `array_hasownproperty` | 11 | 2.0s |  |
| 27 | `array_holes` | 9 | 4.2s |  |
| 28 | `array_index_max` | 84 | 3.9s |  |
| 29 | `array_indexof` | 25 | 4.2s |  |
| 30 | `array_join` | 26 | 4.3s |  |
| 31 | `array_lastindexof` | 29 | 4.2s |  |
| 32 | `array_length` | 14 | 4.2s |  |
| 33 | `array_literal` | 3 | 4.1s |  |
| 34 | `array_map` | 8 | 4.0s |  |
| 35 | `array_pop` | 52 | 4.3s |  |
| 36 | `array_push` | 24 | 4.2s |  |
| 37 | `array_reborrow_bug` | 6 | 4.2s |  |
| 38 | `array_reverse` | 28 | 4.2s |  |
| 39 | `array_shift` | 51 | 2.1s |  |
| 40 | `array_slice` | 39 | 4.3s |  |
| 41 | `array_some` | 8 | 4.2s |  |
| 42 | `array_sort` | 297 | 4.7s |  |
| 43 | `array_sort_fun_swf12` | 2 | 4.2s |  |
| 44 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 45 | `array_sort_random` | 210 | 4.3s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 4.1s |  |
| 47 | `array_sorton` | 545 | 4.9s |  |
| 48 | `array_sparse_ops` | 41 | 4.3s |  |
| 49 | `array_splice` | 133 | 4.3s |  |
| 50 | `array_splice2` | 428 | 4.4s |  |
| 51 | `array_splice_types` | 48 | 4.2s |  |
| 52 | `array_storage` | 8 | 4.2s |  |
| 53 | `array_tolocalestring` | 9 | 4.1s |  |
| 54 | `array_tostring` | 12 | 4.2s |  |
| 55 | `array_unshift` | 24 | 4.2s |  |
| 56 | `array_valueof` | 9 | 4.1s |  |
| 57 | `array_vector_null_callback` | 10 | 4.1s |  |
| 58 | `astype` | 28 | 4.2s |  |
| 59 | `astypelate` | 24 | 4.3s |  |
| 60 | `astypelate_propagates` | 1 | 4.1s |  |
| 61 | `asymmetric_key_events` | 11 | 4.3s |  |
| 62 | `avm2_catchup_dobj` | 158 | 4.7s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 75.8s |  |
| 64 | `bitand` | 1058 | 15.3s |  |
| 65 | `bitmap_constr` | 17 | 4.3s |  |
| 66 | `bitmap_data` | 1000 | 11.9s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 22.6s |  |
| 68 | `bitmap_properties` | 23 | 4.2s |  |
| 69 | `bitmap_subclass` | 7 | 5.6s |  |
| 70 | `bitmap_subclass_properties` | 9 | 4.5s |  |
| 71 | `bitmap_timeline` | 9 | 4.2s |  |
| 72 | `bitmapdata_accuracy` | 1 | 42.4s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 22.9s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.5s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 22.7s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 23.2s |  |
| 77 | `bitmapdata_clone` | 13 | 4.3s |  |
| 78 | `bitmapdata_colortransform` | 0 | 4.4s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 4.2s |  |
| 80 | `bitmapdata_constr` | 22 | 4.3s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 4.5s |  |
| 82 | `bitmapdata_copychannel` | 0 | 25.3s |  |
| 83 | `bitmapdata_copypixels` | 23 | 22.7s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 4.2s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 4.1s |  |
| 86 | `bitmapdata_dispose` | 7 | 4.2s |  |
| 87 | `bitmapdata_draw` | 0 | 22.9s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 4.1s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 22.9s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 22.6s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 4.2s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 4.1s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 4.1s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 22.9s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 4.4s |  |
| 96 | `bitmapdata_embedded` | 9 | 4.2s |  |
| 97 | `bitmapdata_fillrect` | 0 | 4.2s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 22.7s |  |
| 99 | `bitmapdata_floodfill` | 35 | 4.1s |  |
| 100 | `bitmapdata_getpixels` | 39 | 22.9s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.0s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.0s |  |
| 103 | `bitmapdata_hittest` | 112 | 4.7s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 4.1s |  |
| 105 | `bitmapdata_opaque` | 0 | 4.1s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 23.0s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 4.3s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 4.1s |  |
| 109 | `bitmapdata_setpixels` | 286 | 4.2s |  |
| 110 | `bitmapdata_setvector` | 26 | 4.2s |  |
| 111 | `bitmapdata_sync` | 0 | 4.3s |  |
| 112 | `bitmapdata_threshold` | 176 | 4.8s |  |
| 113 | `bitnot` | 46 | 4.1s |  |
| 114 | `bitor` | 1058 | 16.5s |  |
| 115 | `bitxor` | 1058 | 16.5s |  |
| 116 | `blend_multiply_alpha` | 0 | 4.2s |  |
| 117 | `blend_scroll` | 0 | 4.2s |  |
| 118 | `boolean_constr` | 32 | 4.2s |  |
| 119 | `boolean_negation` | 30 | 4.2s |  |
| 120 | `boolean_tostring` | 8 | 4.2s |  |
| 121 | `broadcast_event` | 7 | 4.0s |  |
| 122 | `button_nested_frame` | 48 | 22.9s |  |
| 123 | `bytearray` | 48 | 4.4s |  |
| 124 | `bytearray_compress` | 31 | 4.2s |  |
| 125 | `bytearray_errors` | 24 | 4.3s |  |
| 126 | `bytearray_method_serialization` | 1 | 2.0s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 4.1s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 4.2s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 4.2s |  |
| 130 | `bytearray_serialization` | 3 | 4.1s |  |
| 131 | `bytearray_string_null` | 19 | 4.4s |  |
| 132 | `bytearray_tostring` | 15 | 4.2s |  |
| 133 | `bytearray_utf16` | 8 | 4.1s |  |
| 134 | `bytearray_writeobject` | 24 | 4.0s |  |
| 135 | `callee_in_initializer` | 6 | 4.1s |  |
| 136 | `callproplex_class` | 1 | 4.1s |  |
| 137 | `catch_class` | 6 | 4.1s |  |
| 138 | `catch_scope_slot` | 7 | 4.2s |  |
| 139 | `checkfilter` | 4 | 2.0s |  |
| 140 | `class_call` | 32 | 22.3s |  |
| 141 | `class_cast_call` | 14 | 4.2s |  |
| 142 | `class_enumeration` | 4 | 4.2s |  |
| 143 | `class_has_own_property` | 2 | 4.1s |  |
| 144 | `class_init_interpreter_mode` | 1 | 4.1s |  |
| 145 | `class_is` | 32 | 4.2s |  |
| 146 | `class_methods` | 5 | 4.2s |  |
| 147 | `class_object_properties` | 10 | 4.2s |  |
| 148 | `class_singleton` | 18 | 4.2s |  |
| 149 | `class_supercalls_errors` | 35 | 4.4s |  |
| 150 | `class_supercalls_mismatched` | 26 | 4.2s |  |
| 151 | `class_superclass_wrong_order` | 1 | 17.4s |  |
| 152 | `class_to_locale_string` | 2 | 2.9s |  |
| 153 | `class_to_string` | 2 | 3.0s |  |
| 154 | `class_value_of` | 2 | 3.2s |  |
| 155 | `click_block` | 5 | 17.9s |  |
| 156 | `click_invisible` | 3 | 3.2s |  |
| 157 | `closures` | 12 | 3.3s |  |
| 158 | `coerce_return_type` | 40 | 3.4s |  |
| 159 | `coerce_return_type_fail` | 2 | 2.9s |  |
| 160 | `coerce_return_void` | 3 | 2.9s |  |
| 161 | `coerce_string` | 86 | 3.0s |  |
| 162 | `coerce_string_precision` | 28 | 3.2s |  |
| 163 | `coerce_to_primitive_side_effects` | 29 | 3.2s |  |
| 164 | `construct_errors_swf10` | 8 | 3.2s |  |
| 165 | `construct_frame_list` | 22 | 17.6s |  |
| 166 | `constructor_call` | 3 | 2.9s |  |
| 167 | `constructors_vs_timeline` | 5 | 17.4s |  |
| 168 | `constructprop_dynamic_primitive` | 7 | 3.2s |  |
| 169 | `control_flow_bool` | 4 | 3.5s |  |
| 170 | `control_flow_stricteq` | 8 | 3.2s |  |
| 171 | `convert_boolean` | 30 | 3.0s |  |
| 172 | `convert_integer` | 90 | 2.9s |  |
| 173 | `convert_number` | 56 | 2.9s |  |
| 174 | `convert_uinteger` | 90 | 2.9s |  |
| 175 | `cryptscore` | 11 | 3.1s |  |
| 176 | `declocal` | 46 | 4.3s |  |
| 177 | `declocal_i` | 46 | 4.3s |  |
| 178 | `decrement` | 46 | 4.3s |  |
| 179 | `decrement_i` | 46 | 2.1s |  |
| 180 | `default_values` | 7 | 4.2s |  |
| 181 | `dictionary_access` | 62 | 4.4s |  |
| 182 | `dictionary_access_no_pubns` | 2 | 4.2s |  |
| 183 | `dictionary_delete` | 101 | 4.6s |  |
| 184 | `dictionary_foreach` | 42 | 4.5s |  |
| 185 | `dictionary_hasownproperty` | 63 | 4.5s |  |
| 186 | `dictionary_in` | 62 | 4.6s |  |
| 187 | `dictionary_iter_modify` | 8 | 4.2s |  |
| 188 | `dictionary_namespaces` | 36 | 4.4s |  |
| 189 | `dictionary_primitive_keys` | 29 | 4.2s |  |
| 190 | `displayobject_alpha` | 277 | 4.2s |  |
| 191 | `displayobject_blendmode` | 0 | 23.0s |  |
| 192 | `displayobject_colortransform_nested` | 0 | 23.1s |  |
| 193 | `displayobject_from_enterframe` | 1 | 22.8s |  |
| 194 | `displayobject_getbounds_shape` | 0 | 22.7s |  |
| 195 | `displayobject_height` | 6052 | 23.0s |  |
| 196 | `displayobject_hittestobject` | 32 | 4.3s |  |
| 197 | `displayobject_invalid_floats` | 60 | 4.3s |  |
| 198 | `displayobject_invalid_props` | 3 | 4.2s |  |
| 199 | `displayobject_mask` | 3 | 4.4s |  |
| 200 | `displayobject_mask_self_referential` | 0 | 4.3s |  |
| 201 | `displayobject_metaData` | 3 | 4.0s |  |
| 202 | `displayobject_name` | 22 | 22.1s |  |
| 203 | `displayobject_name_from_timeline` | 24 | 4.2s |  |
| 204 | `displayobject_parent` | 12 | 4.0s |  |
| 205 | `displayobject_root` | 24 | 4.1s |  |
| 206 | `displayobject_rotation` | 1284 | 4.2s |  |
| 207 | `displayobject_set_matrix_nested` | 0 | 22.4s |  |
| 208 | `displayobject_subclass` | 2 | 4.0s |  |
| 209 | `displayobject_visible` | 23 | 4.0s |  |
| 210 | `displayobject_width` | 4852 | 22.3s |  |
| 211 | `displayobject_x` | 614 | 4.1s |  |
| 212 | `displayobject_y` | 617 | 4.1s |  |
| 213 | `displayobjectcontainer_addchild` | 32 | 4.1s |  |
| 214 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.0s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.2s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.1s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.1s |  |
| 218 | `displayobjectcontainer_addchildat` | 42 | 4.1s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.2s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.2s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 2.1s |  |
| 222 | `displayobjectcontainer_contains` | 66 | 22.2s |  |
| 223 | `displayobjectcontainer_getchildat` | 4 | 4.1s |  |
| 224 | `displayobjectcontainer_getchildbyname` | 9 | 4.0s |  |
| 225 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.0s |  |
| 226 | `displayobjectcontainer_getchildindex` | 28 | 4.0s |  |
| 227 | `displayobjectcontainer_removechild` | 10 | 4.0s |  |
| 228 | `displayobjectcontainer_removechild_errors` | 4 | 4.0s |  |
| 229 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.1s |  |
| 230 | `displayobjectcontainer_removechildat` | 18 | 4.0s |  |
| 231 | `displayobjectcontainer_removechildren` | 51 | 4.2s |  |
| 232 | `displayobjectcontainer_setchildindex` | 42 | 3.9s |  |
| 233 | `displayobjectcontainer_stopallmovieclips` | 2 | 22.1s |  |
| 234 | `displayobjectcontainer_swapchildren` | 42 | 4.1s |  |
| 235 | `displayobjectcontainer_swapchildrenat` | 42 | 4.1s |  |
| 236 | `displayobjectcontainer_timelineinstance` | 48 | 22.3s |  |
| 237 | `divide` | 1058 | 18.3s |  |
| 238 | `doabc_is_eager` | 1 | 21.8s |  |
| 239 | `documentclass` | 9 | 4.2s |  |
| 240 | `drag_drop` | 10 | 4.2s |  |
| 241 | `duplicate_defs` | 1 | 3.9s |  |
| 242 | `eager_init` | 1 | 4.0s |  |
| 243 | `edit_text_linkage` | 7 | 4.2s |  |
| 244 | `edittext_align` | 60 | 4.3s |  |
| 245 | `edittext_always_show_selection` | 0 | 22.4s |  |
| 246 | `edittext_antialiastype` | 296 | 4.3s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 5.4s |  |
| 248 | `edittext_autosize` | 39 | 4.4s |  |
| 249 | `edittext_autosize_align` | 0 | 22.3s |  |
| 250 | `edittext_autosize_height_dynamic` | 60 | 22.1s |  |
| 251 | `edittext_autosize_height_input` | 60 | 4.2s |  |
| 252 | `edittext_autosize_lazy_bounds_events` | 65 | 4.4s |  |
| 253 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.1s |  |
| 254 | `edittext_autosize_lazy_bounds_props` | 490 | 5.4s |  |
| 255 | `edittext_autosize_lazy_bounds_visual` | 0 | 22.2s |  |
| 256 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.2s |  |
| 257 | `edittext_bottom_scroll_v_basic` | 210 | 4.2s |  |
| 258 | `edittext_bounds_scale` | 24 | 21.9s |  |
| 259 | `edittext_bullet` | 30 | 4.1s |  |
| 260 | `edittext_default_format` | 221 | 4.4s |  |
| 261 | `edittext_default_format_empty` | 136 | 4.3s |  |
| 262 | `edittext_empty_text_format` | 7 | 4.1s |  |
| 263 | `edittext_focus_selection` | 5 | 4.0s |  |
| 264 | `edittext_font_size` | 45 | 4.1s |  |
| 265 | `edittext_format_empty_font` | 8 | 4.0s |  |
| 266 | `edittext_get_char_index_at_point` | 4 | 22.4s |  |
| 267 | `edittext_get_line_index_at_point` | 2 | 22.3s |  |
| 268 | `edittext_get_line_index_of_char` | 76 | 5.0s |  |
| 269 | `edittext_getcharboundaries` | 172 | 4.5s |  |
| 270 | `edittext_getcharboundaries_missing_glyphs` | 63 | 24.5s |  |
| 271 | `edittext_getcharboundaries_scroll` | 85 | 4.2s |  |
| 272 | `edittext_getlinemetrics` | 146 | 4.3s |  |
| 273 | `edittext_html` | 3101 | 4.5s |  |
| 274 | `edittext_html_condensewhite` | 487 | 4.2s |  |
| 275 | `edittext_html_entity` | 4 | 4.3s |  |
| 276 | `edittext_html_font_size_swf12` | 267 | 4.1s |  |
| 277 | `edittext_html_font_size_swf13` | 273 | 3.7s |  |
| 278 | `edittext_html_roundtrip` | 17 | 4.1s |  |
| 279 | `edittext_input_control` | 12 | 4.2s |  |
| 280 | `edittext_leading` | 9 | 4.2s |  |
| 281 | `edittext_letter_spacing` | 15 | 4.0s |  |
| 282 | `edittext_line_methods` | 294 | 5.4s |  |
| 283 | `edittext_line_metrics` | 11 | 23.5s |  |
| 284 | `edittext_margins` | 25 | 4.0s |  |
| 285 | `edittext_max_scroll_h_basic` | 475 | 4.2s |  |
| 286 | `edittext_max_scroll_v_basic` | 1000 | 4.1s |  |
| 287 | `edittext_mousedown` | 3 | 4.4s |  |
| 288 | `edittext_mouseenabled` | 26 | 4.0s |  |
| 289 | `edittext_newline_character` | 22 | 4.0s |  |
| 290 | `edittext_newline_stripping` | 64 | 6.6s |  |
| 291 | `edittext_newlines` | 30 | 4.1s |  |
| 292 | `edittext_paragraph_methods` | 257 | 4.0s |  |
| 293 | `edittext_paste_events` | 8 | 4.2s |  |
| 294 | `edittext_paste_maxchars` | 4 | 4.0s |  |
| 295 | `edittext_paste_restrict` | 16 | 3.8s |  |
| 296 | `edittext_restrict` | 191 | 4.0s |  |
| 297 | `edittext_restrict_events` | 22 | 4.0s |  |
| 298 | `edittext_scrollh` | 10 | 4.0s |  |
| 299 | `edittext_selected_text` | 9 | 4.0s |  |
| 300 | `edittext_set_html_same` | 17 | 4.0s |  |
| 301 | `edittext_set_text_vs_html` | 9 | 4.0s |  |
| 302 | `edittext_stylesheet` | 536 | 4.4s |  |
| 303 | `edittext_stylesheet_custom_tag` | 76 | 4.1s |  |
| 304 | `edittext_stylesheet_display` | 272 | 4.1s |  |
| 305 | `edittext_underline` | 40 | 4.1s |  |
| 306 | `edittext_width_height` | 103 | 4.3s |  |
| 307 | `edittext_wordwrap_word` | 150 | 6.6s |  |
| 308 | `edittext_wrap_breaks` | 2375 | 4.7s |  |
| 309 | `empty_bounds` | 1 | 4.0s |  |
| 310 | `equals` | 512 | 8.3s |  |
| 311 | `error_prototype` | 15 | 4.1s |  |
| 312 | `error_stack_trace_debug_swf17` | 0 | 22.6s |  |
| 313 | `error_stack_trace_debug_swf18` | 0 | 3.9s |  |
| 314 | `error_stack_trace_release_swf17` | 0 | 3.9s |  |
| 315 | `error_stack_trace_release_swf18` | 0 | 3.8s |  |
| 316 | `error_tostring` | 29 | 4.1s |  |
| 317 | `es3_inheritance` | 31 | 4.2s |  |
| 318 | `es4_inheritance` | 30 | 4.2s |  |
| 319 | `es4_interfaces` | 30 | 4.2s |  |
| 320 | `es4_method_binding` | 8 | 4.2s |  |
| 321 | `es4_oop_prototypes` | 14 | 4.3s |  |
| 322 | `es4_protected_inheritance` | 6 | 4.1s |  |
| 323 | `event_bubbles` | 2 | 4.0s |  |
| 324 | `event_cancelable` | 2 | 3.9s |  |
| 325 | `event_clone` | 20 | 4.1s |  |
| 326 | `event_clone_error_redispatch` | 3 | 4.2s |  |
| 327 | `event_clone_on_redispatch` | 10 | 4.3s |  |
| 328 | `event_formattostring` | 31 | 4.2s |  |
| 329 | `event_isdefaultprevented` | 12 | 4.0s |  |
| 330 | `event_target_getter` | 5 | 1.9s |  |
| 331 | `event_target_set` | 9 | 4.0s |  |
| 332 | `event_type` | 1 | 4.0s |  |
| 333 | `event_valueof_tostring` | 18 | 6.3s |  |
| 334 | `eventdispatcher_dispatchevent` | 12 | 4.1s |  |
| 335 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.1s |  |
| 336 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.1s |  |
| 337 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.1s |  |
| 338 | `eventdispatcher_dispatchevent_this` | 5 | 4.1s |  |
| 339 | `eventdispatcher_haseventlistener` | 25 | 4.2s |  |
| 340 | `eventdispatcher_interface_invoke` | 1 | 4.1s |  |
| 341 | `eventdispatcher_tostring` | 10 | 4.1s |  |
| 342 | `eventdispatcher_willtrigger` | 25 | 4.0s |  |
| 343 | `falsiness` | 30 | 4.1s |  |
| 344 | `fast_index_access` | 12 | 4.2s |  |
| 345 | `finddef` | 3 | 4.1s |  |
| 346 | `findprop_global_prototype` | 6 | 4.1s |  |
| 347 | `flash_xml` | 29 | 4.3s |  |
| 348 | `flash_xml_cloneNode` | 22 | 4.2s |  |
| 349 | `flash_xml_namespace` | 109 | 4.1s |  |
| 350 | `flash_xml_removeNode` | 60 | 4.1s |  |
| 351 | `focus_events_code` | 161 | 22.9s |  |
| 352 | `focus_events_key_same_object` | 26 | 4.2s |  |
| 353 | `focus_events_mixed_key_mouse` | 100 | 22.8s |  |
| 354 | `focus_events_mouse_same_object` | 40 | 19.9s |  |
| 355 | `focus_remove` | 20 | 19.5s |  |
| 356 | `focus_root_movie` | 4 | 20.1s |  |
| 357 | `focus_stage` | 1 | 3.6s |  |
| 358 | `focusrect` | 18 | 4.2s |  |
| 359 | `font_description_clone` | 14 | 3.5s |  |
| 360 | `font_embedded` | 24 | 4.0s |  |
| 361 | `font_enumeratefonts` | 41 | 4.1s |  |
| 362 | `font_enumeratefonts_filter` | 4 | 20.4s |  |
| 363 | `font_hasglyphs` | 40 | 3.9s |  |
| 364 | `framelabel_constr` | 5 | 3.5s |  |
| 365 | `function_call` | 12 | 3.8s |  |
| 366 | `function_call_arguments` | 46 | 3.5s |  |
| 367 | `function_call_arguments_enumerate` | 5 | 3.4s |  |
| 368 | `function_call_coercion` | 108 | 3.8s |  |
| 369 | `function_call_default` | 6 | 3.8s |  |
| 370 | `function_call_rest` | 22 | 3.5s |  |
| 371 | `function_call_types` | 3 | 3.4s |  |
| 372 | `function_call_via_apply` | 11 | 3.6s |  |
| 373 | `function_call_via_call` | 3 | 3.5s |  |
| 374 | `function_display_anonymous` | 7 | 1.9s |  |
| 375 | `function_length` | 6 | 3.5s |  |
| 376 | `function_object` | 2 | 3.5s |  |
| 377 | `function_proto` | 5 | 3.5s |  |
| 378 | `function_proto_created` | 61 | 3.5s |  |
| 379 | `function_to_locale_string` | 4 | 3.6s |  |
| 380 | `function_to_string` | 4 | 3.4s |  |
| 381 | `function_type` | 6 | 3.4s |  |
| 382 | `function_unbound_this` | 51 | 3.6s |  |
| 383 | `function_value_of` | 4 | 3.5s |  |
| 384 | `get_definition_by_name` | 11 | 3.6s |  |
| 385 | `get_qualified_class_name` | 20 | 3.5s |  |
| 386 | `get_qualified_super_class_name` | 18 | 6.4s |  |
| 387 | `get_slot_edge_cases` | 1 | 22.2s |  |
| 388 | `get_timer` | 2 | 4.1s |  |
| 389 | `getglobalslot` | 1 | 4.0s |  |
| 390 | `getouterscope` | 8 | 4.0s |  |
| 391 | `getter_different_namespace_setter` | 2 | 4.0s |  |
| 392 | `goto_button_nested_framescript` | 28 | 23.0s |  |
| 393 | `goto_in_constructframe` | 12 | 22.8s |  |
| 394 | `goto_in_scene_last_frame` | 2 | 22.6s |  |
| 395 | `goto_methods` | 56 | 4.3s |  |
| 396 | `goto_methods_swfver10` | 8 | 4.1s |  |
| 397 | `goto_nested_construct_sibling` | 18 | 4.5s |  |
| 398 | `goto_nested_framescript` | 9 | 4.2s |  |
| 399 | `goto_on_orphan` | 15 | 4.3s |  |
| 400 | `graphics_bitmap_fill` | 0 | 5.8s |  |
| 401 | `graphics_bitmaps` | 0 | 4.4s |  |
| 402 | `graphics_direct_commands` | 0 | 4.4s |  |
| 403 | `graphics_gradients` | 0 | 4.2s |  |
| 404 | `graphics_gradients_nulls` | 0 | 2.0s |  |
| 405 | `graphics_round_rects` | 0 | 4.1s |  |
| 406 | `graphics_simple_shapes` | 0 | 4.1s |  |
| 407 | `greaterequals` | 512 | 8.1s |  |
| 408 | `greaterthan` | 512 | 8.2s |  |
| 409 | `has_own_property` | 102 | 4.6s |  |
| 410 | `hasownproperty_namespaces` | 2 | 4.0s |  |
| 411 | `hello_world` | 1 | 4.0s |  |
| 412 | `hittest_morph` | 30 | 4.2s |  |
| 413 | `if_eq` | 10 | 4.1s |  |
| 414 | `if_gt` | 1 | 4.2s |  |
| 415 | `if_gte` | 10 | 2.0s |  |
| 416 | `if_lt` | 1 | 0.5s |  |
| 417 | `if_lte` | 10 | 5.4s |  |
| 418 | `if_ne` | 7 | 3.4s |  |
| 419 | `if_stricteq` | 6 | 3.6s |  |
| 420 | `if_strictne` | 11 | 3.4s |  |
| 421 | `in` | 102 | 4.0s |  |
| 422 | `inclocal` | 46 | 3.5s |  |
| 423 | `inclocal_i` | 46 | 3.4s |  |
| 424 | `increment` | 46 | 3.5s |  |
| 425 | `increment_i` | 46 | 3.5s |  |
| 426 | `instanceof` | 58 | 3.8s |  |
| 427 | `instantiation_on_enter_frame` | 7 | 19.6s |  |
| 428 | `instantiation_on_enterframe_gotoandstop` | 8 | 3.7s |  |
| 429 | `int_constr` | 92 | 3.8s |  |
| 430 | `int_edge_cases` | 19 | 3.5s |  |
| 431 | `int_instanceof` | 3 | 3.3s |  |
| 432 | `int_tofixed` | 1215 | 3.7s |  |
| 433 | `int_tostring` | 3375 | 3.9s |  |
| 434 | `interactiveobject_enabled` | 25 | 3.4s |  |
| 435 | `interface_namespaces` | 78 | 3.6s |  |
| 436 | `is_finite` | 46 | 3.6s |  |
| 437 | `is_nan` | 46 | 3.9s |  |
| 438 | `is_prototype_of` | 12 | 3.5s |  |
| 439 | `issue_10221` | 2 | 3.5s |  |
| 440 | `issue_13780` | 12 | 3.4s |  |
| 441 | `issue_14901` | 1 | 3.3s |  |
| 442 | `issue_17675_edittext_paste_maxchars` | 1 | 4.0s |  |
| 443 | `issue_5292` | 5 | 3.6s |  |
| 444 | `issue_8630` | 2 | 19.5s |  |
| 445 | `issue_8630_scriptremove` | 11 | 3.4s |  |
| 446 | `istype` | 24 | 2.0s |  |
| 447 | `istypelate` | 58 | 3.9s |  |
| 448 | `istypelate_coerce` | 198 | 4.6s |  |
| 449 | `json_errors` | 9 | 25.8s |  |
| 450 | `json_parse` | 21 | 4.0s |  |
| 451 | `json_version_gated` | 1 | 3.9s |  |
| 452 | `key_input_80percent` | 1812 | 4.1s |  |
| 453 | `key_input_location` | 126 | 4.2s |  |
| 454 | `key_input_numpad` | 384 | 4.0s |  |
| 455 | `lazyinit` | 17 | 4.0s |  |
| 456 | `lessequals` | 512 | 7.5s |  |
| 457 | `lessthan` | 512 | 7.4s |  |
| 458 | `loaderinfo_properties` | 18 | 25.3s |  |
| 459 | `loaderinfo_root` | 10 | 4.3s |  |
| 460 | `loaderinfo_root_allows` | 2 | 4.2s |  |
| 461 | `lshift` | 1058 | 15.6s |  |
| 462 | `mask_reapply` | 1 | 23.1s |  |
| 463 | `math` | 497 | 4.6s |  |
| 464 | `missing_external_interface` | 10 | 4.4s |  |
| 465 | `modulo` | 1058 | 15.8s |  |
| 466 | `mouse_click_events` | 90 | 23.5s |  |
| 467 | `mouse_double_click_events` | 188 | 4.4s |  |
| 468 | `mouse_empty_parent` | 4 | 4.4s |  |
| 469 | `mouse_over_while_dragging` | 3 | 4.5s |  |
| 470 | `mouse_pick_button_mode` | 2 | 4.5s |  |
| 471 | `mouse_sibling` | 8 | 4.4s |  |
| 472 | `movieclip_addframescript` | 3 | 24.9s |  |
| 473 | `movieclip_child_property` | 16 | 4.6s |  |
| 474 | `movieclip_constr` | 21 | 4.5s |  |
| 475 | `movieclip_currentlabels` | 17 | 28.8s |  |
| 476 | `movieclip_currentlabels_dupes1` | 46 | 26.2s |  |
| 477 | `movieclip_currentlabels_dupes2` | 30 | 4.7s |  |
| 478 | `movieclip_currentlabels_dupes3` | 67 | 4.7s |  |
| 479 | `movieclip_currentscene` | 12 | 26.7s |  |
| 480 | `movieclip_dispatchevent` | 430 | 4.8s |  |
| 481 | `movieclip_dispatchevent_cancel` | 102 | 4.8s |  |
| 482 | `movieclip_dispatchevent_handlerorder` | 251 | 4.7s |  |
| 483 | `movieclip_dispatchevent_selfadd` | 80 | 4.7s |  |
| 484 | `movieclip_dispatchevent_target` | 899 | 4.8s |  |
| 485 | `movieclip_displayevents` | 96 | 26.7s |  |
| 486 | `movieclip_displayevents_clickgoto` | 676 | 26.1s |  |
| 487 | `movieclip_displayevents_clickgoto2` | 2001 | 5.2s |  |
| 488 | `movieclip_displayevents_clickplay` | 575 | 4.8s |  |
| 489 | `movieclip_displayevents_clicksymbol` | 562 | 4.8s |  |
| 490 | `movieclip_displayevents_constructframegoto` | 140 | 5.0s |  |
| 491 | `movieclip_displayevents_constructframeplay` | 50 | 4.8s |  |
| 492 | `movieclip_displayevents_constructframesymbol` | 144 | 4.9s |  |
| 493 | `movieclip_displayevents_dblhandler` | 21 | 4.8s |  |
| 494 | `movieclip_displayevents_enterframegoto` | 149 | 4.9s |  |
| 495 | `movieclip_displayevents_enterframeplay` | 48 | 4.8s |  |
| 496 | `movieclip_displayevents_enterframesymbol` | 149 | 26.9s |  |
| 497 | `movieclip_displayevents_exitframegoto` | 106 | 4.8s |  |
| 498 | `movieclip_displayevents_exitframeplay` | 44 | 4.8s |  |
| 499 | `movieclip_displayevents_exitframesymbol` | 135 | 4.8s |  |
| 500 | `movieclip_displayevents_looping` | 63 | 26.4s |  |
| 501 | `movieclip_displayevents_stopped` | 113 | 5.1s |  |
| 502 | `movieclip_displayevents_swap` | 96 | 2.2s |  |
| 503 | `movieclip_displayevents_timeline` | 128 | 27.1s |  |
| 504 | `movieclip_drawrect` | 54 | 4.7s |  |
| 505 | `movieclip_frameconstruct_skipped` | 9 | 4.8s |  |
| 506 | `movieclip_goto_during_frame_script` | 15 | 4.6s |  |
| 507 | `movieclip_goto_overwrite` | 14 | 25.8s |  |
| 508 | `movieclip_goto_scene_last_frame_int` | 1 | 25.7s |  |
| 509 | `movieclip_goto_scene_last_frame_label` | 1 | 4.5s |  |
| 510 | `movieclip_gotoandplay` | 15 | 25.7s |  |
| 511 | `movieclip_gotoandstop` | 13 | 4.6s |  |
| 512 | `movieclip_gotoandstop_children` | 4 | 4.6s |  |
| 513 | `movieclip_gotoandstop_framescripts1` | 4 | 4.5s |  |
| 514 | `movieclip_gotoandstop_framescripts2` | 4 | 2.2s |  |
| 515 | `movieclip_gotoandstop_framescripts_self` | 7 | 25.8s |  |
| 516 | `movieclip_gotoandstop_queueing` | 12 | 22.8s |  |
| 517 | `movieclip_next_frame` | 2 | 22.8s |  |
| 518 | `movieclip_next_scene` | 6 | 22.6s |  |
| 519 | `movieclip_play` | 3 | 4.2s |  |
| 520 | `movieclip_prev_frame` | 3 | 4.0s |  |
| 521 | `movieclip_prev_scene` | 7 | 4.3s |  |
| 522 | `movieclip_properties` | 79 | 24.2s |  |
| 523 | `movieclip_queued_noop_goto_swf10` | 9 | 4.2s |  |
| 524 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 525 | `movieclip_scenes` | 11 | 4.1s |  |
| 526 | `movieclip_soundtransform` | 831 | 24.9s |  |
| 527 | `movieclip_stop` | 1 | 23.8s |  |
| 528 | `movieclip_super_is_symbol` | 20 | 4.7s |  |
| 529 | `movieclip_symbol_constr` | 8 | 4.3s |  |
| 530 | `movieclip_text_mousedown` | 1 | 4.3s |  |
| 531 | `movieclip_willtrigger` | 5 | 4.4s |  |
| 532 | `multiply` | 1058 | 15.7s |  |
| 533 | `namespace_constr` | 253 | 4.6s |  |
| 534 | `namespace_constr_args` | 1 | 4.3s |  |
| 535 | `namespace_enumeration_order` | 7 | 4.4s |  |
| 536 | `nan_scale` | 9 | 4.3s |  |
| 537 | `negate` | 30 | 4.2s |  |
| 538 | `negative_volume_panned` | 0 | 4.4s |  |
| 539 | `nested_iteration` | 11 | 4.2s |  |
| 540 | `net_getClassByAlias` | 3 | 4.3s |  |
| 541 | `newactivation_in_script_init` | 3 | 4.7s |  |
| 542 | `newclass_twice` | 3 | 4.7s |  |
| 543 | `nonconflicting_declarations` | 0 | 4.8s |  |
| 544 | `null_void_types` | 8 | 4.8s |  |
| 545 | `number_autoconv` | 21 | 4.8s |  |
| 546 | `number_autoconv_amf` | 132 | 4.8s |  |
| 547 | `number_autoconv_array_sort_32bit` | 1 | 4.8s |  |
| 548 | `number_constr` | 58 | 5.0s |  |
| 549 | `number_toexponential` | 378 | 4.9s |  |
| 550 | `number_toexponential2` | 35 | 4.8s |  |
| 551 | `number_tofixed` | 378 | 4.7s |  |
| 552 | `number_toprecision` | 350 | 4.9s |  |
| 553 | `obfuscated_class_names` | 3 | 4.7s |  |
| 554 | `object_enumeration` | 10 | 4.8s |  |
| 555 | `object_prototype` | 4 | 4.8s |  |
| 556 | `object_to_locale_string` | 2 | 4.8s |  |
| 557 | `object_to_string` | 2 | 4.7s |  |
| 558 | `object_value_of` | 2 | 2.1s |  |
| 559 | `op_coerce` | 54 | 4.9s |  |
| 560 | `op_coerce_x` | 54 | 4.9s |  |
| 561 | `op_escxattr` | 2 | 4.8s |  |
| 562 | `op_escxelem` | 2 | 4.8s |  |
| 563 | `op_lookupswitch` | 4 | 4.8s |  |
| 564 | `optimize_coerce` | 1 | 4.7s |  |
| 565 | `orphan_movie_complex` | 80 | 5.2s |  |
| 566 | `orphan_movie_reorder` | 111 | 26.6s |  |
| 567 | `package_namespace` | 7 | 4.7s |  |
| 568 | `param_default_value_has_zero_cpool_index` | 1 | 4.8s |  |
| 569 | `parent_early_access_child` | 16 | 27.2s |  |
| 570 | `pixelbender_effect_BlurredFocus` | 0 | 26.3s |  |
| 571 | `pixelbender_effect_glassDisplace` | 0 | 9.7s |  |
| 572 | `pixelbender_effect_smudge` | 0 | 7.4s |  |
| 573 | `pixelbender_effect_tintype` | 0 | 6.6s |  |
| 574 | `pixelbender_effect_twirl` | 0 | 7.8s |  |
| 575 | `pixelbender_images` | 0 | 6.2s |  |
| 576 | `place_multiple` | 17 | 23.5s |  |
| 577 | `place_object_replace` | 9 | 4.7s |  |
| 578 | `place_object_replace_2` | 24 | 4.6s |  |
| 579 | `place_object_same_depth_frame` | 1 | 4.6s |  |
| 580 | `point` | 132 | 5.1s |  |
| 581 | `primitive_edge_cases` | 1 | 4.4s |  |
| 582 | `property_priority` | 22 | 4.2s |  |
| 583 | `property_priority_three_level` | 6 | 22.7s |  |
| 584 | `propertyisenumerable_namespaces` | 6 | 3.9s |  |
| 585 | `prototype_set_null` | 7 | 4.0s |  |
| 586 | `proxy_callproperty` | 24 | 4.0s |  |
| 587 | `proxy_deleteproperty` | 64 | 4.1s |  |
| 588 | `proxy_enumeration` | 34 | 4.0s |  |
| 589 | `proxy_getproperty` | 77 | 4.1s |  |
| 590 | `proxy_hasownproperty` | 8 | 4.0s |  |
| 591 | `proxy_hasproperty` | 32 | 4.1s |  |
| 592 | `proxy_serialize` | 9 | 4.0s |  |
| 593 | `proxy_setproperty` | 42 | 4.1s |  |
| 594 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.0s |  |
| 595 | `qname_constr` | 32 | 4.1s |  |
| 596 | `qname_constr_namespace` | 24 | 4.0s |  |
| 597 | `qname_enumeration` | 9 | 3.9s |  |
| 598 | `qname_indexing` | 23 | 4.0s |  |
| 599 | `qname_tostring` | 25 | 4.0s |  |
| 600 | `qname_valueof` | 29 | 4.0s |  |
| 601 | `regexp_constr` | 148 | 4.2s |  |
| 602 | `regexp_exec` | 19 | 4.0s |  |
| 603 | `regexp_extended` | 47 | 3.9s |  |
| 604 | `regexp_multiargs` | 1 | 3.9s |  |
| 605 | `regexp_test` | 27 | 4.0s |  |
| 606 | `regexp_toString` | 10 | 4.0s |  |
| 607 | `register_script_refresh` | 35 | 23.2s |  |
| 608 | `remove_child_clear_field` | 88 | 23.4s |  |
| 609 | `remove_dobj` | 3 | 4.0s |  |
| 610 | `resolve_order` | 4 | 4.0s |  |
| 611 | `rng` | 1 | 5.2s |  |
| 612 | `rootless` | 42 | 4.2s |  |
| 613 | `rshift` | 1058 | 18.4s |  |
| 614 | `sandbox_type_local_file` | 1 | 4.5s |  |
| 615 | `scene_constr` | 8 | 4.5s |  |
| 616 | `set_local_0` | 31 | 4.5s |  |
| 617 | `set_property_is_enumerable` | 85 | 4.9s |  |
| 618 | `shape_drawrect` | 54 | 4.6s |  |
| 619 | `shared_object_no_root` | 3 | 4.5s |  |
| 620 | `simplebutton_added_to_stage` | 45 | 25.1s |  |
| 621 | `simplebutton_childevents` | 86 | 25.2s |  |
| 622 | `simplebutton_childevents_nested` | 54 | 4.8s |  |
| 623 | `simplebutton_childevents_sprite` | 13 | 4.5s |  |
| 624 | `simplebutton_childprops` | 144 | 4.6s |  |
| 625 | `simplebutton_childshuffle` | 23 | 4.3s |  |
| 626 | `simplebutton_constr` | 36 | 4.7s |  |
| 627 | `simplebutton_constr_childevents` | 48 | 4.7s |  |
| 628 | `simplebutton_constr_params` | 42 | 4.5s |  |
| 629 | `simplebutton_mouseenabled` | 26 | 4.4s |  |
| 630 | `simplebutton_multi_children` | 19 | 4.7s |  |
| 631 | `simplebutton_structure` | 27 | 4.5s |  |
| 632 | `simplebutton_symbolclass` | 68 | 4.8s |  |
| 633 | `slot_disp_id_shared_numbering` | 1 | 23.3s |  |
| 634 | `slots_force_autoassigned` | 1 | 4.3s |  |
| 635 | `sound_embeddedprops` | 26 | 4.2s |  |
| 636 | `sound_play` | 19 | 4.2s |  |
| 637 | `sound_valueof` | 33 | 4.1s |  |
| 638 | `soundchannel_soundtransform` | 835 | 24.9s |  |
| 639 | `soundchannel_soundtransform_exists` | 5 | 23.3s |  |
| 640 | `soundchannel_stop` | 8 | 23.1s |  |
| 641 | `soundmixer_buffertime` | 5 | 4.0s |  |
| 642 | `soundmixer_stopall` | 6 | 22.9s |  |
| 643 | `soundtransform` | 442 | 8.3s |  |
| 644 | `sprite_with_frames` | 0 | 23.1s |  |
| 645 | `stage3d_agal_cross_product` | 0 | 6.2s |  |
| 646 | `stage3d_bitmap` | 0 | 27.5s |  |
| 647 | `stage3d_float1_index` | 0 | 25.3s |  |
| 648 | `stage3d_fractal` | 0 | 6.5s |  |
| 649 | `stage3d_ignore_sampler_override` | 0 | 25.4s |  |
| 650 | `stage3d_program_constants_bytearray_be` | 0 | 26.0s |  |
| 651 | `stage3d_program_constants_bytearray_le` | 0 | 7.0s |  |
| 652 | `stage3d_raytrace` | 0 | 30.6s |  |
| 653 | `stage3d_rotating_cube` | 0 | 7.5s |  |
| 654 | `stage3d_sampler` | 0 | 6.6s |  |
| 655 | `stage3d_sampler_partial_upload` | 0 | 6.6s |  |
| 656 | `stage3d_stencil` | 0 | 24.9s |  |
| 657 | `stage3d_texture` | 0 | 11.4s |  |
| 658 | `stage3d_texture_bytearray` | 0 | 7.8s |  |
| 659 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 7.2s |  |
| 660 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 8.4s |  |
| 661 | `stage3d_triangle` | 0 | 6.7s |  |
| 662 | `stage3d_triangle_bytes4` | 0 | 6.6s |  |
| 663 | `stage3d_triangle_float1` | 0 | 6.6s |  |
| 664 | `stage3d_triangle_index_upload` | 0 | 6.6s |  |
| 665 | `stage_access` | 10 | 4.1s |  |
| 666 | `stage_displayobject_properties` | 24 | 4.0s |  |
| 667 | `stage_framerate_nan` | 7 | 4.2s |  |
| 668 | `stage_framerate_negative` | 6 | 4.1s |  |
| 669 | `stage_framerate_zero` | 6 | 4.1s |  |
| 670 | `stage_invalidate` | 38 | 4.2s |  |
| 671 | `stage_mousechildren` | 2 | 4.0s |  |
| 672 | `stage_mouseenabled` | 15 | 4.0s |  |
| 673 | `stage_overriden_setters` | 31 | 4.2s |  |
| 674 | `stage_properties` | 30 | 4.0s |  |
| 675 | `static_var_with_this_in_ctor` | 2 | 4.0s |  |
| 676 | `stored_properties` | 11 | 4.1s |  |
| 677 | `strict_equality` | 34 | 3.9s |  |
| 678 | `string_call` | 13 | 3.8s |  |
| 679 | `string_case` | 23 | 3.9s |  |
| 680 | `string_char_at` | 27 | 3.9s |  |
| 681 | `string_char_code_at` | 28 | 3.7s |  |
| 682 | `string_constr` | 25 | 3.4s |  |
| 683 | `string_indexof_lastindexof` | 87 | 3.8s |  |
| 684 | `string_length` | 16 | 3.2s |  |
| 685 | `string_locale_compare` | 39 | 3.3s |  |
| 686 | `string_match` | 51 | 3.3s |  |
| 687 | `string_relational_compare` | 4 | 3.1s |  |
| 688 | `string_replace` | 51 | 3.2s |  |
| 689 | `string_search` | 41 | 3.1s |  |
| 690 | `string_split` | 29 | 3.4s |  |
| 691 | `string_substr_negative` | 21 | 3.2s |  |
| 692 | `string_substr_weird` | 182 | 3.1s |  |
| 693 | `subtract` | 1058 | 12.3s |  |
| 694 | `super_get_call` | 12 | 3.0s |  |
| 695 | `supercall_two_classobjects` | 2 | 3.0s |  |
| 696 | `swf8` | 1 | 2.8s |  |
| 697 | `swf_10_queued_goto_scripts_construct` | 52 | 18.2s |  |
| 698 | `swf_9_goto_in_enter_frame` | 17 | 3.0s |  |
| 699 | `swf_9_goto_in_enter_frame_simple` | 15 | 3.1s |  |
| 700 | `swf_9_queued_goto_scripts` | 6 | 18.4s |  |
| 701 | `swf_9_queued_goto_scripts_construct` | 28 | 0.4s |  |
| 702 | `swf_9_versioning` | 2 | 3.1s |  |
| 703 | `swf_wrong_frame_count` | 38 | 3.2s |  |
| 704 | `swf_wrong_frame_count_isplaying` | 22 | 3.1s |  |
| 705 | `symbol_class_binary_data` | 8 | 3.5s |  |
| 706 | `symbol_class_conflict` | 4 | 3.6s |  |
| 707 | `symbol_class_root_not_zero` | 1 | 3.4s |  |
| 708 | `symbolclass_invalid_utf8` | 2 | 3.5s |  |
| 709 | `tab_ordering_automatic_advanced` | 184 | 4.6s |  |
| 710 | `tab_ordering_automatic_basic` | 45 | 4.0s |  |
| 711 | `tab_ordering_children` | 116 | 4.2s |  |
| 712 | `tab_ordering_custom_basic` | 34 | 4.0s |  |
| 713 | `text_engine_fontdescription` | 27 | 4.2s |  |
| 714 | `text_run` | 7 | 4.0s |  |
| 715 | `textfield_focusin_event` | 9 | 4.0s |  |
| 716 | `textfield_input_dead_keys_windows` | 15 | 4.0s |  |
| 717 | `textfield_unload` | 39 | 22.1s |  |
| 718 | `textformat` | 1134 | 4.0s |  |
| 719 | `textformat_display` | 14 | 4.0s |  |
| 720 | `textformat_font_max_length` | 4 | 4.0s |  |
| 721 | `throw` | 3 | 4.0s |  |
| 722 | `timeline_scripts` | 3 | 4.2s |  |
| 723 | `timer` | 90 | 4.6s |  |
| 724 | `timer_events` | 3 | 4.0s |  |
| 725 | `timer_finished` | 11 | 4.2s |  |
| 726 | `timer_reset` | 8 | 4.1s |  |
| 727 | `timer_setdelay` | 5 | 4.0s |  |
| 728 | `trace` | 12 | 4.0s |  |
| 729 | `truthiness` | 30 | 6.3s |  |
| 730 | `try_catch` | 11 | 4.2s |  |
| 731 | `try_catch_typed` | 12 | 4.2s |  |
| 732 | `typeof` | 30 | 4.2s |  |
| 733 | `uint_constr` | 92 | 4.4s |  |
| 734 | `uint_tofixed` | 1215 | 4.2s |  |
| 735 | `uint_tostring` | 3375 | 4.4s |  |
| 736 | `unchecked_function` | 15 | 4.1s |  |
| 737 | `urlrequest` | 18 | 4.2s |  |
| 738 | `urshift` | 1058 | 16.4s |  |
| 739 | `vector_class` | 36 | 4.6s |  |
| 740 | `vector_class_call` | 11 | 4.3s |  |
| 741 | `vector_coercion` | 66 | 5.0s |  |
| 742 | `vector_concat` | 90 | 4.8s |  |
| 743 | `vector_constr` | 107 | 4.9s |  |
| 744 | `vector_enumeration` | 5 | 4.1s |  |
| 745 | `vector_every` | 92 | 5.0s |  |
| 746 | `vector_filter` | 95 | 5.1s |  |
| 747 | `vector_holes` | 24 | 4.3s |  |
| 748 | `vector_indexof` | 302 | 9.0s |  |
| 749 | `vector_insertat` | 270 | 5.3s |  |
| 750 | `vector_int_access` | 4 | 4.1s |  |
| 751 | `vector_int_delete` | 11 | 4.1s |  |
| 752 | `vector_join` | 58 | 4.6s |  |
| 753 | `vector_lastindexof` | 302 | 4.1s |  |
| 754 | `vector_legacy` | 10 | 4.1s |  |
| 755 | `vector_map` | 85 | 4.8s |  |
| 756 | `vector_object_final` | 1 | 3.6s |  |
| 757 | `vector_object_toString` | 10 | 3.6s |  |
| 758 | `vector_pushpop` | 255 | 4.9s |  |
| 759 | `vector_reborrow_bug` | 10 | 5.9s |  |
| 760 | `vector_removeat` | 172 | 4.7s |  |
| 761 | `vector_reverse` | 232 | 4.8s |  |
| 762 | `vector_shiftunshift` | 252 | 4.9s |  |
| 763 | `vector_slice` | 331 | 5.2s |  |
| 764 | `vector_sort` | 905 | 12.2s |  |
| 765 | `vector_splice` | 693 | 7.2s |  |
| 766 | `vector_splice_fixed_bug_compat` | 4 | 3.7s |  |
| 767 | `vector_tostring` | 79 | 4.3s |  |
| 768 | `verify_abnormal_loop` | 1 | 3.7s |  |
| 769 | `verify_exception_targets_edge_case` | 1 | 3.7s |  |
| 770 | `verify_lookup_switch_edge_case` | 1 | 3.7s |  |
| 771 | `verify_unreachable_exception` | 2 | 3.7s |  |
| 772 | `versioned_isplaying` | 2 | 3.7s |  |
| 773 | `virtual_properties` | 16 | 3.8s |  |
| 774 | `with` | 4 | 3.7s |  |
| 775 | `xml_abstract_equality` | 36 | 3.9s |  |
| 776 | `xml_advanced` | 52 | 3.8s |  |
| 777 | `xml_appendchild` | 10 | 3.7s |  |
| 778 | `xml_as_attribute` | 9 | 3.7s |  |
| 779 | `xml_attribute` | 35 | 3.9s |  |
| 780 | `xml_attribute_name` | 40 | 3.8s |  |
| 781 | `xml_child` | 25 | 3.8s |  |
| 782 | `xml_childindex` | 7 | 3.7s |  |
| 783 | `xml_children` | 43 | 4.2s |  |
| 784 | `xml_class_call` | 9 | 3.7s |  |
| 785 | `xml_contains` | 197 | 3.9s |  |
| 786 | `xml_copy` | 20 | 5.8s |  |
| 787 | `xml_ctor_from_tostring` | 23 | 3.9s |  |
| 788 | `xml_delete` | 114 | 3.7s |  |
| 789 | `xml_descendants` | 83 | 3.7s |  |
| 790 | `xml_elements` | 6 | 3.6s |  |
| 791 | `xml_equals_namespace_check` | 2 | 3.6s |  |
| 792 | `xml_explicit_use_namespace` | 5 | 21.6s |  |
| 793 | `xml_getdescendants_qname` | 21 | 3.6s |  |
| 794 | `xml_has_property_via_in` | 26 | 3.6s |  |
| 795 | `xml_hasownproperty` | 6 | 3.6s |  |
| 796 | `xml_ignore_white` | 6 | 3.6s |  |
| 797 | `xml_length` | 2 | 3.6s |  |
| 798 | `xml_list_as_attribute` | 9 | 3.5s |  |
| 799 | `xml_list_concat` | 20 | 3.6s |  |
| 800 | `xml_list_enumerate` | 4 | 3.5s |  |
| 801 | `xml_methods_settings` | 3 | 3.6s |  |
| 802 | `xml_mismatched_tag` | 37 | 3.6s |  |
| 803 | `xml_namespace` | 39 | 3.6s |  |
| 804 | `xml_namespace_methods` | 245 | 3.6s |  |
| 805 | `xml_namespaced_property` | 7 | 3.6s |  |
| 806 | `xml_no_namespace` | 1 | 3.6s |  |
| 807 | `xml_nodekind` | 3 | 3.6s |  |
| 808 | `xml_normalize` | 35 | 3.7s |  |
| 809 | `xml_notification_bubbling` | 361 | 3.6s |  |
| 810 | `xml_parent` | 8 | 3.6s |  |
| 811 | `xml_set_children` | 17 | 3.7s |  |
| 812 | `xml_set_name` | 34 | 3.6s |  |
| 813 | `xml_settings` | 6 | 1.4s |  |
| 814 | `xml_simple_complex_content` | 47 | 3.6s |  |
| 815 | `xml_text` | 7 | 3.6s |  |
| 816 | `xml_tostring` | 6 | 3.6s |  |
| 817 | `xml_tostring_namespace` | 12 | 3.6s |  |
| 818 | `xml_unescaping` | 23 | 3.6s |  |
| 819 | `xml_weird_ignores` | 54 | 3.7s |  |
| 820 | `xml_wildcard` | 11 | 3.6s |  |
| 821 | `xmldocument` | 254 | 3.7s |  |
| 822 | `xmlnode` | 3540 | 3.8s |  |
| 823 | `zero_frame_clip` | 3 | 3.8s |  |

## Ruffle-Matched Tests

**25 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 4.1s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 4.1s |  |
| 3 | `blend_transform` | 1 | 1 | 4.2s |  |
| 4 | `coerce_property` | 3 | 3 | 3.2s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 3.0s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 22.8s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 4.3s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 4.0s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 4.1s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 4.1s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 4.2s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 3.4s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 22.4s |  |
| 14 | `int_toexponential` | 76 | 76 | 4.7s |  |
| 15 | `int_toprecision` | 441 | 441 | 3.5s |  |
| 16 | `simplebutton_childevents_script_order` | 4 | 4 | 4.7s |  |
| 17 | `slot_holes_fail` | 1 | 1 | 4.2s |  |
| 18 | `slot_id_exceeds_trait_count` | 1 | 1 | 23.5s |  |
| 19 | `soundchannel_position` | 74 | 74 | 23.9s |  |
| 20 | `soundchannel_soundcomplete` | 10 | 10 | 4.2s |  |
| 21 | `sprite_dropTarget` | 4 | 15 | 4.0s |  |
| 22 | `swf_9_goto_in_construct_frame` | 12 | 12 | 18.2s |  |
| 23 | `uint_toexponential` | 100 | 100 | 4.3s |  |
| 24 | `uint_toprecision` | 433 | 433 | 4.4s |  |
| 25 | `weird_superinterface_properties` | 1 | 1 | 3.7s |  |

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
| 30 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 31 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 32 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 33 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 34 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 35 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 36 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 37 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 38 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 39 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 40 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 41 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 42 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 43 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 44 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 45 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 46 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 47 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 48 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 49 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 50 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 51 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 52 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 53 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 54 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 55 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 56 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 57 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 58 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 59 | `error_stack_trace` | 53.3% | 24 | 45 | 21 |  |
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
| 1 | `domain_memory` | exit code 1 | 4.1s |  |
| 2 | `method_without_body` | exit code 1 | 23.3s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 4.4s |  |
| 4 | `verify_typecheck` | exit code 1 | 3.8s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 34.1s |  |

## All Output Mismatches

**362 tests** with output mismatch, sorted by match rate (best first)

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
| 30 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 31 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 32 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 33 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 34 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 35 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 36 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 37 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 38 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 39 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 40 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 41 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 42 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 43 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 44 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 45 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 46 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 47 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 48 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 49 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 50 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 51 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 52 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 53 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 54 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 55 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 56 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 57 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 58 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 59 | `error_stack_trace` | 53.3% | 24/45 | 45 | 45 |  |
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
| 106 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 107 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 108 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 109 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 110 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 111 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 112 | `xml_list_ctor_errors` | 11.8% | 4/34 | 28 | 34 |  |
| 113 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 114 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 115 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 116 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 117 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 118 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 119 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 120 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 121 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 122 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 123 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 124 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 125 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 126 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 127 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 128 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 129 | `pixelbender_sign` | 5.0% | 3/60 | 16 | 60 |  |
| 130 | `loader_method` | 4.7% | 4/85 | 11 | 85 |  |
| 131 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 132 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 133 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 134 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 135 | `pixelbender_ceil` | 3.9% | 3/77 | 16 | 77 |  |
| 136 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 137 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 138 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 139 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 140 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 141 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 142 | `number_convert_errors` | 3.1% | 27/871 | 685 | 871 |  |
| 143 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 144 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
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
| 169 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 170 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 171 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 172 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 173 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 174 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 175 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 176 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 177 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 178 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 179 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 180 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 181 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 182 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 183 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 184 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 185 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 186 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 187 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
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
| 241 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 242 | `graphics_draw_path` | 0.0% | 0/101 | 0 | 101 |  |
| 243 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 244 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 245 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 246 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 247 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 248 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 249 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 250 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 251 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 252 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 253 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 254 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 255 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 256 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 257 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 258 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 259 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 260 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 261 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 262 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 263 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 264 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 265 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 266 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 267 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 268 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 269 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 270 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 271 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 272 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 273 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 274 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 275 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 276 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 277 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 278 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 279 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 280 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 281 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 282 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 283 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 284 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 285 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 286 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 287 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 288 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 289 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 290 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 291 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 292 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 293 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 294 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 295 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 296 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 297 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 298 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 299 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 300 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 301 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 302 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 303 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 304 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 305 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 306 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 307 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 308 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 309 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 310 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 311 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 312 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 313 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 314 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 315 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 316 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 317 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 318 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 319 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 320 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 321 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 322 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 323 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 324 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 325 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 326 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 327 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 328 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 329 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 330 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 331 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 332 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 333 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 334 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 335 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 336 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 337 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 338 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 339 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 340 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 341 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 342 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 343 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 344 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 345 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 346 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 347 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 348 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 349 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 350 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 351 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 352 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 353 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 354 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 355 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 356 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 357 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 358 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 359 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 360 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 361 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 362 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
