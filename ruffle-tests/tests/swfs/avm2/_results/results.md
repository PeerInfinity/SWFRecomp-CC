# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-12 21:26 UTC

**Git SHA**: `2efd025eaf`

**Run Duration**: 89m 40s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1204 |
| Passing | **754** (62.6%) |
| Ruffle-matched | 21 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **775** (64.4%) |
| Failing | 429 |
| Total expected lines | 149868 |
| Matching lines | 89945 (60.0%) |
| Mismatched lines | 59923 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 424 | 98.8% |
| Runtime Error | 4 | 0.9% |
| Timeout | 1 | 0.2% |

## Passing Tests

**754 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.6s |  |
| 2 | `air_hidden_lookup` | 2 | 1.0s |  |
| 3 | `all_classes/security/swf11` | 3 | 1.1s |  |
| 4 | `amf_custom_obj` | 26 | 1.0s |  |
| 5 | `amf_dictionary` | 9 | 1.0s |  |
| 6 | `amf_function` | 46 | 1.1s |  |
| 7 | `amf_invalid_date` | 2 | 0.9s |  |
| 8 | `amf_missing_prop` | 6 | 1.0s |  |
| 9 | `amf_nondynamic_function_prop` | 6 | 11.7s |  |
| 10 | `amf_setter_error` | 8 | 2.0s |  |
| 11 | `amf_vector` | 40 | 2.0s |  |
| 12 | `amf_xml` | 6 | 1.9s |  |
| 13 | `application_domain` | 4 | 1.9s |  |
| 14 | `array_access` | 18 | 1.9s |  |
| 15 | `array_access_interpreter` | 4 | 1.9s |  |
| 16 | `array_access_no_pubns` | 2 | 1.8s |  |
| 17 | `array_concat` | 41 | 1.9s |  |
| 18 | `array_constr` | 10 | 1.9s |  |
| 19 | `array_delete` | 44 | 1.9s |  |
| 20 | `array_enumeration` | 10 | 1.9s |  |
| 21 | `array_enumeration_elements` | 11 | 1.9s |  |
| 22 | `array_every` | 8 | 1.8s |  |
| 23 | `array_filter` | 6 | 1.9s |  |
| 24 | `array_foreach` | 18 | 1.9s |  |
| 25 | `array_hasownproperty` | 11 | 1.8s |  |
| 26 | `array_holes` | 9 | 1.9s |  |
| 27 | `array_index_max` | 84 | 1.6s |  |
| 28 | `array_indexof` | 25 | 1.9s |  |
| 29 | `array_join` | 26 | 1.9s |  |
| 30 | `array_lastindexof` | 29 | 1.9s |  |
| 31 | `array_length` | 14 | 1.9s |  |
| 32 | `array_literal` | 3 | 1.8s |  |
| 33 | `array_map` | 8 | 0.4s |  |
| 34 | `array_pop` | 52 | 1.9s |  |
| 35 | `array_push` | 24 | 1.9s |  |
| 36 | `array_reborrow_bug` | 6 | 1.9s |  |
| 37 | `array_reverse` | 28 | 1.9s |  |
| 38 | `array_shift` | 51 | 1.9s |  |
| 39 | `array_slice` | 39 | 1.9s |  |
| 40 | `array_some` | 8 | 1.9s |  |
| 41 | `array_sort` | 297 | 2.2s |  |
| 42 | `array_sort_fun_swf12` | 2 | 1.9s |  |
| 43 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 44 | `array_sort_random` | 210 | 1.9s |  |
| 45 | `array_sort_swf10_32bit` | 1 | 1.9s |  |
| 46 | `array_sorton` | 545 | 2.4s |  |
| 47 | `array_sparse_ops` | 41 | 1.9s |  |
| 48 | `array_splice` | 133 | 2.0s |  |
| 49 | `array_splice2` | 428 | 2.1s |  |
| 50 | `array_splice_types` | 48 | 1.9s |  |
| 51 | `array_storage` | 8 | 1.9s |  |
| 52 | `array_tolocalestring` | 9 | 1.9s |  |
| 53 | `array_tostring` | 12 | 1.8s |  |
| 54 | `array_unshift` | 24 | 1.9s |  |
| 55 | `array_valueof` | 9 | 1.8s |  |
| 56 | `array_vector_null_callback` | 10 | 1.8s |  |
| 57 | `astype` | 28 | 1.9s |  |
| 58 | `astypelate` | 24 | 1.9s |  |
| 59 | `astypelate_propagates` | 1 | 1.8s |  |
| 60 | `away3d_advanced_shallow_water_demo` | 0 | 64.0s |  |
| 61 | `bitand` | 1058 | 4.0s |  |
| 62 | `bitmap_constr` | 17 | 2.0s |  |
| 63 | `bitmap_data` | 1000 | 6.4s |  |
| 64 | `bitmap_properties` | 23 | 1.9s |  |
| 65 | `bitmap_timeline` | 9 | 1.9s |  |
| 66 | `bitmapdata_accuracy` | 1 | 37.6s |  |
| 67 | `bitmapdata_applyfilter_blur` | 0 | 21.0s |  |
| 68 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.1s |  |
| 69 | `bitmapdata_applyfilter_destpoint` | 0 | 20.9s |  |
| 70 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 20.9s |  |
| 71 | `bitmapdata_clone` | 13 | 1.9s |  |
| 72 | `bitmapdata_colortransform` | 0 | 2.0s |  |
| 73 | `bitmapdata_colortransform_oob` | 2 | 1.8s |  |
| 74 | `bitmapdata_constr` | 22 | 1.9s |  |
| 75 | `bitmapdata_constructor_from_timeline` | 1 | 2.1s |  |
| 76 | `bitmapdata_copychannel` | 0 | 33.8s |  |
| 77 | `bitmapdata_copypixels` | 23 | 20.9s |  |
| 78 | `bitmapdata_copypixels_blend_over` | 1 | 2.1s |  |
| 79 | `bitmapdata_copypixelstobytearray` | 39 | 1.8s |  |
| 80 | `bitmapdata_dispose` | 7 | 1.8s |  |
| 81 | `bitmapdata_draw` | 0 | 20.6s |  |
| 82 | `bitmapdata_draw_colortransform` | 0 | 1.8s |  |
| 83 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 21.7s |  |
| 84 | `bitmapdata_draw_filters` | 0 | 21.4s |  |
| 85 | `bitmapdata_draw_masks` | 0 | 1.9s |  |
| 86 | `bitmapdata_draw_rotation` | 0 | 1.9s |  |
| 87 | `bitmapdata_draw_self_via_graphic` | 0 | 1.9s |  |
| 88 | `bitmapdata_draw_stage` | 0 | 21.2s |  |
| 89 | `bitmapdata_drawwithquality` | 0 | 2.1s |  |
| 90 | `bitmapdata_embedded` | 9 | 2.0s |  |
| 91 | `bitmapdata_fillrect` | 0 | 1.9s |  |
| 92 | `bitmapdata_filter_sourcerect` | 0 | 21.3s |  |
| 93 | `bitmapdata_floodfill` | 35 | 1.9s |  |
| 94 | `bitmapdata_getpixels` | 39 | 21.3s |  |
| 95 | `bitmapdata_getvector` | 27 | 1.9s |  |
| 96 | `bitmapdata_histogram` | 59 | 1.9s |  |
| 97 | `bitmapdata_hittest` | 112 | 2.3s |  |
| 98 | `bitmapdata_hittest_threshold` | 18 | 1.9s |  |
| 99 | `bitmapdata_opaque` | 0 | 1.9s |  |
| 100 | `bitmapdata_pixeldissolve` | 1037 | 2.3s |  |
| 101 | `bitmapdata_pixeldissolve_image` | 0 | 2.1s |  |
| 102 | `bitmapdata_rectangle_rounding` | 16 | 1.9s |  |
| 103 | `bitmapdata_setpixels` | 286 | 1.9s |  |
| 104 | `bitmapdata_setvector` | 26 | 1.3s |  |
| 105 | `bitmapdata_sync` | 0 | 2.0s |  |
| 106 | `bitmapdata_threshold` | 176 | 2.4s |  |
| 107 | `bitmapdata_zero_size` | 5 | 1.8s |  |
| 108 | `bitnot` | 46 | 1.9s |  |
| 109 | `bitor` | 1058 | 4.1s |  |
| 110 | `bitxor` | 1058 | 4.1s |  |
| 111 | `blend_multiply_alpha` | 0 | 1.9s |  |
| 112 | `blend_scroll` | 0 | 1.9s |  |
| 113 | `boolean_constr` | 32 | 2.1s |  |
| 114 | `boolean_negation` | 30 | 2.0s |  |
| 115 | `boolean_tostring` | 8 | 2.0s |  |
| 116 | `broadcast_event` | 7 | 1.9s |  |
| 117 | `button_nested_frame` | 48 | 23.6s |  |
| 118 | `bytearray` | 48 | 2.2s |  |
| 119 | `bytearray_compress` | 31 | 2.0s |  |
| 120 | `bytearray_errors` | 24 | 2.1s |  |
| 121 | `bytearray_method_serialization` | 1 | 1.9s |  |
| 122 | `bytearray_readobject_amf0` | 50 | 0.8s |  |
| 123 | `bytearray_readobject_amf3` | 53 | 1.9s |  |
| 124 | `bytearray_readutf8bytes_with_bom` | 16 | 1.9s |  |
| 125 | `bytearray_serialization` | 3 | 1.9s |  |
| 126 | `bytearray_string_null` | 19 | 2.1s |  |
| 127 | `bytearray_tostring` | 15 | 1.9s |  |
| 128 | `bytearray_utf16` | 8 | 1.9s |  |
| 129 | `bytearray_writeobject` | 24 | 0.7s |  |
| 130 | `callee_in_initializer` | 6 | 1.8s |  |
| 131 | `callproplex_class` | 1 | 1.9s |  |
| 132 | `catch_class` | 6 | 1.9s |  |
| 133 | `catch_scope_slot` | 7 | 2.0s |  |
| 134 | `checkfilter` | 4 | 1.9s |  |
| 135 | `class_call` | 32 | 1.9s |  |
| 136 | `class_cast_call` | 14 | 1.9s |  |
| 137 | `class_enumeration` | 4 | 1.9s |  |
| 138 | `class_has_own_property` | 2 | 1.9s |  |
| 139 | `class_init_interpreter_mode` | 1 | 1.8s |  |
| 140 | `class_is` | 32 | 2.0s |  |
| 141 | `class_methods` | 5 | 1.9s |  |
| 142 | `class_object_properties` | 10 | 1.9s |  |
| 143 | `class_singleton` | 18 | 1.9s |  |
| 144 | `class_supercalls_errors` | 35 | 2.1s |  |
| 145 | `class_supercalls_mismatched` | 26 | 12.6s |  |
| 146 | `class_superclass_wrong_order` | 1 | 1.8s |  |
| 147 | `class_to_locale_string` | 2 | 1.9s |  |
| 148 | `class_to_string` | 2 | 1.7s |  |
| 149 | `class_value_of` | 2 | 1.8s |  |
| 150 | `closures` | 12 | 1.8s |  |
| 151 | `coerce_property` | 33 | 1.9s |  |
| 152 | `coerce_return_type` | 40 | 2.0s |  |
| 153 | `coerce_return_type_fail` | 2 | 1.8s |  |
| 154 | `coerce_return_void` | 3 | 1.8s |  |
| 155 | `coerce_string` | 86 | 2.0s |  |
| 156 | `coerce_string_precision` | 28 | 1.9s |  |
| 157 | `coerce_to_primitive_side_effects` | 29 | 1.9s |  |
| 158 | `construct_errors_swf10` | 8 | 1.9s |  |
| 159 | `construct_frame_list` | 22 | 20.8s |  |
| 160 | `constructor_call` | 3 | 1.9s |  |
| 161 | `constructors_vs_timeline` | 5 | 21.2s |  |
| 162 | `constructprop_dynamic_primitive` | 7 | 2.0s |  |
| 163 | `control_flow_bool` | 4 | 1.9s |  |
| 164 | `control_flow_stricteq` | 8 | 1.9s |  |
| 165 | `convert_boolean` | 30 | 1.9s |  |
| 166 | `convert_integer` | 90 | 1.9s |  |
| 167 | `convert_number` | 56 | 1.9s |  |
| 168 | `convert_uinteger` | 90 | 1.9s |  |
| 169 | `cryptscore` | 11 | 12.4s |  |
| 170 | `declocal` | 46 | 1.8s |  |
| 171 | `declocal_i` | 46 | 1.8s |  |
| 172 | `decrement` | 46 | 1.9s |  |
| 173 | `decrement_i` | 46 | 1.8s |  |
| 174 | `default_values` | 7 | 1.8s |  |
| 175 | `dictionary_access` | 62 | 2.0s |  |
| 176 | `dictionary_access_no_pubns` | 2 | 1.8s |  |
| 177 | `dictionary_delete` | 101 | 2.0s |  |
| 178 | `dictionary_foreach` | 42 | 1.9s |  |
| 179 | `dictionary_hasownproperty` | 63 | 2.0s |  |
| 180 | `dictionary_in` | 62 | 1.9s |  |
| 181 | `dictionary_iter_modify` | 8 | 1.8s |  |
| 182 | `dictionary_namespaces` | 36 | 1.9s |  |
| 183 | `dictionary_primitive_keys` | 29 | 1.8s |  |
| 184 | `displayobject_alpha` | 277 | 1.7s |  |
| 185 | `displayobject_blendmode` | 0 | 20.4s |  |
| 186 | `displayobject_colortransform_nested` | 0 | 20.8s |  |
| 187 | `displayobject_from_enterframe` | 1 | 20.6s |  |
| 188 | `displayobject_getbounds_shape` | 0 | 20.8s |  |
| 189 | `displayobject_height` | 6052 | 20.8s |  |
| 190 | `displayobject_hittestobject` | 32 | 1.9s |  |
| 191 | `displayobject_invalid_floats` | 60 | 1.9s |  |
| 192 | `displayobject_invalid_props` | 3 | 12.4s |  |
| 193 | `displayobject_mask` | 3 | 1.9s |  |
| 194 | `displayobject_mask_self_referential` | 0 | 1.8s |  |
| 195 | `displayobject_metaData` | 3 | 1.8s |  |
| 196 | `displayobject_name` | 22 | 20.7s |  |
| 197 | `displayobject_name_from_timeline` | 24 | 2.0s |  |
| 198 | `displayobject_parent` | 12 | 1.8s |  |
| 199 | `displayobject_root` | 24 | 1.8s |  |
| 200 | `displayobject_rotation` | 1275 | 1.9s |  |
| 201 | `displayobject_set_matrix_nested` | 0 | 21.1s |  |
| 202 | `displayobject_subclass` | 2 | 1.9s |  |
| 203 | `displayobject_visible` | 23 | 1.9s |  |
| 204 | `displayobject_width` | 4852 | 20.9s |  |
| 205 | `displayobject_x` | 614 | 1.7s |  |
| 206 | `displayobject_y` | 617 | 1.9s |  |
| 207 | `displayobjectcontainer_addchild` | 32 | 1.9s |  |
| 208 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 1.9s |  |
| 209 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 2.0s |  |
| 210 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 1.9s |  |
| 211 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 1.9s |  |
| 212 | `displayobjectcontainer_addchildat` | 42 | 1.9s |  |
| 213 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 2.0s |  |
| 214 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 1.9s |  |
| 215 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 1.9s |  |
| 216 | `displayobjectcontainer_contains` | 66 | 2.1s |  |
| 217 | `displayobjectcontainer_getchildat` | 4 | 1.9s |  |
| 218 | `displayobjectcontainer_getchildbyname` | 9 | 1.8s |  |
| 219 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 1.8s |  |
| 220 | `displayobjectcontainer_getchildindex` | 28 | 1.8s |  |
| 221 | `displayobjectcontainer_removechild` | 10 | 1.9s |  |
| 222 | `displayobjectcontainer_removechild_errors` | 4 | 1.8s |  |
| 223 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 1.9s |  |
| 224 | `displayobjectcontainer_removechildat` | 18 | 1.8s |  |
| 225 | `displayobjectcontainer_removechildren` | 51 | 2.0s |  |
| 226 | `displayobjectcontainer_setchildindex` | 42 | 1.7s |  |
| 227 | `displayobjectcontainer_stopallmovieclips` | 2 | 12.4s |  |
| 228 | `displayobjectcontainer_swapchildren` | 42 | 1.9s |  |
| 229 | `displayobjectcontainer_swapchildrenat` | 42 | 1.8s |  |
| 230 | `displayobjectcontainer_timelineinstance` | 48 | 19.9s |  |
| 231 | `divide` | 1058 | 3.9s |  |
| 232 | `doabc_is_eager` | 1 | 19.4s |  |
| 233 | `documentclass` | 9 | 1.9s |  |
| 234 | `duplicate_defs` | 1 | 0.5s |  |
| 235 | `eager_init` | 1 | 1.8s |  |
| 236 | `edit_text_linkage` | 7 | 1.9s |  |
| 237 | `edittext_align` | 60 | 2.0s |  |
| 238 | `edittext_always_show_selection` | 0 | 20.3s |  |
| 239 | `edittext_antialiastype` | 296 | 1.9s |  |
| 240 | `edittext_autosize` | 39 | 2.0s |  |
| 241 | `edittext_autosize_align` | 0 | 20.2s |  |
| 242 | `edittext_autosize_height_dynamic` | 60 | 20.1s |  |
| 243 | `edittext_autosize_height_input` | 60 | 1.9s |  |
| 244 | `edittext_autosize_lazy_bounds_events` | 65 | 2.0s |  |
| 245 | `edittext_autosize_lazy_bounds_interactions` | 19 | 1.8s |  |
| 246 | `edittext_autosize_lazy_bounds_props` | 490 | 3.0s |  |
| 247 | `edittext_autosize_lazy_bounds_visual` | 0 | 20.0s |  |
| 248 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 2.0s |  |
| 249 | `edittext_bottom_scroll_v_basic` | 210 | 1.9s |  |
| 250 | `edittext_bounds_scale` | 24 | 19.7s |  |
| 251 | `edittext_bullet` | 30 | 1.8s |  |
| 252 | `edittext_default_format` | 221 | 2.1s |  |
| 253 | `edittext_default_format_empty` | 136 | 2.0s |  |
| 254 | `edittext_empty_text_format` | 7 | 1.8s |  |
| 255 | `edittext_focus_selection` | 5 | 1.8s |  |
| 256 | `edittext_font_size` | 45 | 1.8s |  |
| 257 | `edittext_format_empty_font` | 8 | 1.8s |  |
| 258 | `edittext_get_char_index_at_point` | 4 | 20.8s |  |
| 259 | `edittext_get_line_index_at_point` | 2 | 31.8s |  |
| 260 | `edittext_get_line_index_of_char` | 76 | 3.0s |  |
| 261 | `edittext_getcharboundaries` | 172 | 2.3s |  |
| 262 | `edittext_getcharboundaries_missing_glyphs` | 63 | 2.0s |  |
| 263 | `edittext_getcharboundaries_scroll` | 85 | 1.9s |  |
| 264 | `edittext_getlinemetrics` | 146 | 2.1s |  |
| 265 | `edittext_html` | 3101 | 2.2s |  |
| 266 | `edittext_html_condensewhite` | 487 | 1.9s |  |
| 267 | `edittext_html_entity` | 4 | 2.1s |  |
| 268 | `edittext_html_font_size_swf12` | 267 | 1.9s |  |
| 269 | `edittext_html_font_size_swf13` | 273 | 0.5s |  |
| 270 | `edittext_html_roundtrip` | 17 | 1.9s |  |
| 271 | `edittext_leading` | 9 | 2.1s |  |
| 272 | `edittext_letter_spacing` | 15 | 1.9s |  |
| 273 | `edittext_line_methods` | 294 | 2.9s |  |
| 274 | `edittext_line_metrics` | 11 | 21.8s |  |
| 275 | `edittext_margins` | 25 | 1.9s |  |
| 276 | `edittext_max_scroll_h_basic` | 475 | 2.1s |  |
| 277 | `edittext_max_scroll_v_basic` | 1000 | 2.0s |  |
| 278 | `edittext_mouseenabled` | 26 | 1.9s |  |
| 279 | `edittext_newline_stripping` | 64 | 3.7s |  |
| 280 | `edittext_newlines` | 30 | 1.9s |  |
| 281 | `edittext_paragraph_methods` | 257 | 1.9s |  |
| 282 | `edittext_scrollh` | 10 | 1.9s |  |
| 283 | `edittext_set_html_same` | 17 | 1.8s |  |
| 284 | `edittext_set_text_vs_html` | 9 | 1.8s |  |
| 285 | `edittext_stylesheet` | 536 | 2.2s |  |
| 286 | `edittext_stylesheet_custom_tag` | 76 | 12.3s |  |
| 287 | `edittext_stylesheet_display` | 272 | 1.9s |  |
| 288 | `edittext_underline` | 40 | 1.8s |  |
| 289 | `edittext_width_height` | 103 | 2.0s |  |
| 290 | `edittext_wordwrap_word` | 150 | 2.1s |  |
| 291 | `edittext_wrap_breaks` | 2375 | 2.4s |  |
| 292 | `empty_bounds` | 1 | 1.8s |  |
| 293 | `equals` | 512 | 2.7s |  |
| 294 | `error_prototype` | 15 | 1.8s |  |
| 295 | `error_stack_trace_debug_swf17` | 0 | 20.0s |  |
| 296 | `error_stack_trace_debug_swf18` | 0 | 0.5s |  |
| 297 | `error_stack_trace_release_swf17` | 0 | 0.4s |  |
| 298 | `error_stack_trace_release_swf18` | 0 | 0.3s |  |
| 299 | `error_tostring` | 29 | 1.8s |  |
| 300 | `es3_inheritance` | 31 | 1.8s |  |
| 301 | `es4_inheritance` | 30 | 1.8s |  |
| 302 | `es4_interfaces` | 30 | 1.8s |  |
| 303 | `es4_method_binding` | 8 | 1.8s |  |
| 304 | `es4_oop_prototypes` | 14 | 1.9s |  |
| 305 | `es4_protected_inheritance` | 6 | 1.8s |  |
| 306 | `event_bubbles` | 2 | 1.8s |  |
| 307 | `event_cancelable` | 2 | 1.7s |  |
| 308 | `event_clone` | 20 | 1.8s |  |
| 309 | `event_clone_error_redispatch` | 3 | 1.9s |  |
| 310 | `event_clone_on_redispatch` | 10 | 12.1s |  |
| 311 | `event_formattostring` | 31 | 1.9s |  |
| 312 | `event_handler_exception` | 4 | 1.9s |  |
| 313 | `event_isdefaultprevented` | 12 | 1.8s |  |
| 314 | `event_target_getter` | 5 | 1.8s |  |
| 315 | `event_target_set` | 9 | 1.7s |  |
| 316 | `event_type` | 1 | 1.7s |  |
| 317 | `event_valueof_tostring` | 18 | 1.8s |  |
| 318 | `eventdispatcher_dispatchevent` | 12 | 1.7s |  |
| 319 | `eventdispatcher_dispatchevent_cancel` | 20 | 1.8s |  |
| 320 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 1.8s |  |
| 321 | `eventdispatcher_dispatchevent_indirect` | 9 | 1.8s |  |
| 322 | `eventdispatcher_dispatchevent_this` | 5 | 1.7s |  |
| 323 | `eventdispatcher_haseventlistener` | 25 | 1.8s |  |
| 324 | `eventdispatcher_interface_invoke` | 1 | 1.7s |  |
| 325 | `eventdispatcher_tostring` | 10 | 1.8s |  |
| 326 | `eventdispatcher_willtrigger` | 25 | 1.7s |  |
| 327 | `falsiness` | 30 | 1.8s |  |
| 328 | `fast_index_access` | 12 | 1.9s |  |
| 329 | `finddef` | 3 | 1.7s |  |
| 330 | `findprop_global_prototype` | 6 | 1.8s |  |
| 331 | `flash_xml` | 29 | 1.8s |  |
| 332 | `flash_xml_cloneNode` | 22 | 1.8s |  |
| 333 | `flash_xml_namespace` | 109 | 1.8s |  |
| 334 | `flash_xml_removeNode` | 60 | 10.0s |  |
| 335 | `focus_remove` | 20 | 16.3s |  |
| 336 | `font_description_clone` | 14 | 1.2s |  |
| 337 | `font_embedded` | 24 | 1.5s |  |
| 338 | `font_enumeratefonts` | 41 | 1.6s |  |
| 339 | `font_enumeratefonts_filter` | 4 | 1.7s |  |
| 340 | `font_hasglyphs` | 40 | 1.5s |  |
| 341 | `framelabel_constr` | 5 | 1.3s |  |
| 342 | `function_call` | 12 | 1.3s |  |
| 343 | `function_call_arguments` | 46 | 1.4s |  |
| 344 | `function_call_arguments_enumerate` | 5 | 1.2s |  |
| 345 | `function_call_coercion` | 108 | 1.5s |  |
| 346 | `function_call_default` | 6 | 1.2s |  |
| 347 | `function_call_rest` | 22 | 1.2s |  |
| 348 | `function_call_types` | 3 | 1.2s |  |
| 349 | `function_call_via_apply` | 11 | 1.2s |  |
| 350 | `function_call_via_call` | 3 | 1.2s |  |
| 351 | `function_display_anonymous` | 7 | 1.3s |  |
| 352 | `function_length` | 6 | 1.2s |  |
| 353 | `function_object` | 2 | 1.2s |  |
| 354 | `function_proto` | 5 | 1.2s |  |
| 355 | `function_proto_created` | 61 | 1.3s |  |
| 356 | `function_to_locale_string` | 4 | 1.2s |  |
| 357 | `function_to_string` | 4 | 12.4s |  |
| 358 | `function_type` | 6 | 1.8s |  |
| 359 | `function_unbound_this` | 51 | 2.0s |  |
| 360 | `function_value_of` | 4 | 1.8s |  |
| 361 | `get_definition_by_name` | 11 | 1.9s |  |
| 362 | `get_qualified_class_name` | 20 | 1.9s |  |
| 363 | `get_qualified_super_class_name` | 18 | 1.9s |  |
| 364 | `get_slot_edge_cases` | 1 | 1.8s |  |
| 365 | `getglobalslot` | 1 | 1.8s |  |
| 366 | `getouterscope` | 8 | 1.8s |  |
| 367 | `getter_different_namespace_setter` | 2 | 1.8s |  |
| 368 | `goto_button_nested_framescript` | 28 | 21.1s |  |
| 369 | `goto_in_constructframe` | 12 | 21.0s |  |
| 370 | `goto_in_scene_last_frame` | 2 | 20.4s |  |
| 371 | `goto_methods` | 56 | 2.0s |  |
| 372 | `goto_methods_swfver10` | 8 | 1.9s |  |
| 373 | `goto_nested_construct_sibling` | 18 | 2.2s |  |
| 374 | `goto_nested_framescript` | 9 | 2.0s |  |
| 375 | `goto_on_orphan` | 15 | 2.0s |  |
| 376 | `graphics_bitmap_fill` | 0 | 3.3s |  |
| 377 | `graphics_bitmaps` | 0 | 2.2s |  |
| 378 | `graphics_direct_commands` | 0 | 2.0s |  |
| 379 | `graphics_gradients` | 0 | 1.9s |  |
| 380 | `graphics_gradients_nulls` | 0 | 1.9s |  |
| 381 | `graphics_round_rects` | 0 | 1.9s |  |
| 382 | `graphics_simple_shapes` | 0 | 1.9s |  |
| 383 | `greaterequals` | 512 | 2.9s |  |
| 384 | `greaterthan` | 512 | 13.9s |  |
| 385 | `has_own_property` | 102 | 2.2s |  |
| 386 | `hasownproperty_namespaces` | 2 | 1.9s |  |
| 387 | `hello_world` | 1 | 1.9s |  |
| 388 | `hittest_morph` | 30 | 2.0s |  |
| 389 | `if_eq` | 10 | 1.9s |  |
| 390 | `if_gt` | 1 | 1.9s |  |
| 391 | `if_gte` | 10 | 1.9s |  |
| 392 | `if_lt` | 1 | 0.5s |  |
| 393 | `if_lte` | 10 | 0.5s |  |
| 394 | `if_ne` | 7 | 1.9s |  |
| 395 | `if_stricteq` | 6 | 1.9s |  |
| 396 | `if_strictne` | 11 | 1.9s |  |
| 397 | `in` | 102 | 2.1s |  |
| 398 | `inclocal` | 46 | 2.0s |  |
| 399 | `inclocal_i` | 46 | 2.0s |  |
| 400 | `increment` | 46 | 2.0s |  |
| 401 | `increment_i` | 46 | 1.9s |  |
| 402 | `instanceof` | 58 | 2.1s |  |
| 403 | `instantiation_on_enter_frame` | 7 | 21.3s |  |
| 404 | `instantiation_on_enterframe_gotoandstop` | 8 | 1.9s |  |
| 405 | `int_constr` | 92 | 2.0s |  |
| 406 | `int_edge_cases` | 19 | 2.0s |  |
| 407 | `int_instanceof` | 3 | 1.8s |  |
| 408 | `int_tofixed` | 1215 | 1.9s |  |
| 409 | `int_tostring` | 3375 | 2.1s |  |
| 410 | `interactiveobject_enabled` | 25 | 1.9s |  |
| 411 | `interface_namespaces` | 78 | 2.1s |  |
| 412 | `is_finite` | 46 | 2.0s |  |
| 413 | `is_nan` | 46 | 1.9s |  |
| 414 | `is_prototype_of` | 12 | 1.9s |  |
| 415 | `issue_10221` | 2 | 1.9s |  |
| 416 | `issue_13780` | 12 | 1.9s |  |
| 417 | `issue_14901` | 1 | 10.8s |  |
| 418 | `issue_5292` | 5 | 1.3s |  |
| 419 | `issue_8630` | 2 | 1.3s |  |
| 420 | `issue_8630_scriptremove` | 11 | 1.3s |  |
| 421 | `istype` | 24 | 1.3s |  |
| 422 | `istypelate` | 58 | 1.4s |  |
| 423 | `istypelate_coerce` | 198 | 1.6s |  |
| 424 | `json_errors` | 9 | 16.6s |  |
| 425 | `json_parse` | 21 | 1.3s |  |
| 426 | `json_version_gated` | 1 | 1.2s |  |
| 427 | `lazyinit` | 17 | 1.3s |  |
| 428 | `lessequals` | 512 | 2.0s |  |
| 429 | `lessthan` | 512 | 2.0s |  |
| 430 | `lshift` | 1058 | 4.0s |  |
| 431 | `mask_reapply` | 1 | 20.3s |  |
| 432 | `math` | 497 | 1.9s |  |
| 433 | `modulo` | 1058 | 4.0s |  |
| 434 | `movieclip_addframescript` | 3 | 21.8s |  |
| 435 | `movieclip_child_property` | 16 | 2.2s |  |
| 436 | `movieclip_constr` | 21 | 2.0s |  |
| 437 | `movieclip_currentlabels` | 17 | 21.7s |  |
| 438 | `movieclip_currentlabels_dupes1` | 46 | 22.8s |  |
| 439 | `movieclip_currentlabels_dupes2` | 30 | 1.9s |  |
| 440 | `movieclip_currentlabels_dupes3` | 67 | 1.9s |  |
| 441 | `movieclip_currentscene` | 12 | 21.5s |  |
| 442 | `movieclip_dispatchevent` | 430 | 2.0s |  |
| 443 | `movieclip_dispatchevent_cancel` | 102 | 2.0s |  |
| 444 | `movieclip_dispatchevent_handlerorder` | 251 | 1.9s |  |
| 445 | `movieclip_dispatchevent_selfadd` | 80 | 1.9s |  |
| 446 | `movieclip_dispatchevent_target` | 899 | 2.0s |  |
| 447 | `movieclip_displayevents` | 96 | 23.2s |  |
| 448 | `movieclip_displayevents_constructframegoto` | 140 | 2.3s |  |
| 449 | `movieclip_displayevents_constructframeplay` | 50 | 2.2s |  |
| 450 | `movieclip_displayevents_constructframesymbol` | 144 | 2.2s |  |
| 451 | `movieclip_displayevents_dblhandler` | 21 | 2.2s |  |
| 452 | `movieclip_displayevents_enterframegoto` | 149 | 2.2s |  |
| 453 | `movieclip_displayevents_enterframeplay` | 48 | 2.1s |  |
| 454 | `movieclip_displayevents_enterframesymbol` | 149 | 21.9s |  |
| 455 | `movieclip_displayevents_exitframegoto` | 106 | 2.0s |  |
| 456 | `movieclip_displayevents_exitframeplay` | 44 | 2.0s |  |
| 457 | `movieclip_displayevents_exitframesymbol` | 135 | 2.0s |  |
| 458 | `movieclip_displayevents_looping` | 63 | 22.3s |  |
| 459 | `movieclip_displayevents_stopped` | 113 | 2.3s |  |
| 460 | `movieclip_displayevents_swap` | 96 | 1.8s |  |
| 461 | `movieclip_displayevents_timeline` | 128 | 22.4s |  |
| 462 | `movieclip_frameconstruct_skipped` | 9 | 12.2s |  |
| 463 | `movieclip_goto_during_frame_script` | 15 | 19.9s |  |
| 464 | `movieclip_goto_overwrite` | 14 | 19.9s |  |
| 465 | `movieclip_goto_scene_last_frame_int` | 1 | 20.1s |  |
| 466 | `movieclip_goto_scene_last_frame_label` | 1 | 1.7s |  |
| 467 | `movieclip_gotoandplay` | 15 | 19.9s |  |
| 468 | `movieclip_gotoandstop` | 13 | 1.8s |  |
| 469 | `movieclip_gotoandstop_children` | 4 | 1.9s |  |
| 470 | `movieclip_gotoandstop_framescripts1` | 4 | 1.8s |  |
| 471 | `movieclip_gotoandstop_framescripts2` | 4 | 1.8s |  |
| 472 | `movieclip_gotoandstop_framescripts_self` | 7 | 20.0s |  |
| 473 | `movieclip_gotoandstop_queueing` | 12 | 1.9s |  |
| 474 | `movieclip_next_frame` | 2 | 1.8s |  |
| 475 | `movieclip_next_scene` | 6 | 19.7s |  |
| 476 | `movieclip_play` | 3 | 1.7s |  |
| 477 | `movieclip_prev_frame` | 3 | 0.3s |  |
| 478 | `movieclip_prev_scene` | 7 | 1.8s |  |
| 479 | `movieclip_properties` | 79 | 19.9s |  |
| 480 | `movieclip_queued_noop_goto_swf10` | 9 | 1.8s |  |
| 481 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 482 | `movieclip_scenes` | 11 | 1.7s |  |
| 483 | `movieclip_stop` | 1 | 19.6s |  |
| 484 | `movieclip_super_is_symbol` | 20 | 2.1s |  |
| 485 | `movieclip_symbol_constr` | 8 | 1.9s |  |
| 486 | `movieclip_willtrigger` | 5 | 1.9s |  |
| 487 | `multiply` | 1058 | 3.9s |  |
| 488 | `namespace_constr` | 253 | 2.2s |  |
| 489 | `namespace_constr_args` | 1 | 1.7s |  |
| 490 | `namespace_enumeration_order` | 7 | 1.8s |  |
| 491 | `nan_scale` | 9 | 1.8s |  |
| 492 | `negate` | 30 | 1.8s |  |
| 493 | `negative_volume_panned` | 0 | 1.9s |  |
| 494 | `nested_iteration` | 11 | 1.8s |  |
| 495 | `net_getClassByAlias` | 3 | 1.8s |  |
| 496 | `newactivation_in_script_init` | 3 | 1.7s |  |
| 497 | `newclass_twice` | 3 | 1.6s |  |
| 498 | `nonconflicting_declarations` | 0 | 1.7s |  |
| 499 | `null_void_types` | 8 | 1.7s |  |
| 500 | `number_autoconv` | 21 | 1.7s |  |
| 501 | `number_autoconv_amf` | 132 | 1.7s |  |
| 502 | `number_autoconv_array_sort_32bit` | 1 | 1.7s |  |
| 503 | `number_constr` | 58 | 1.8s |  |
| 504 | `number_toexponential` | 378 | 1.8s |  |
| 505 | `number_toexponential2` | 35 | 1.7s |  |
| 506 | `number_tofixed` | 378 | 1.7s |  |
| 507 | `number_toprecision` | 350 | 1.8s |  |
| 508 | `obfuscated_class_names` | 3 | 1.7s |  |
| 509 | `object_enumeration` | 10 | 1.7s |  |
| 510 | `object_prototype` | 4 | 1.8s |  |
| 511 | `object_to_locale_string` | 2 | 1.7s |  |
| 512 | `object_to_string` | 2 | 1.7s |  |
| 513 | `object_value_of` | 2 | 1.5s |  |
| 514 | `op_coerce` | 54 | 1.2s |  |
| 515 | `op_coerce_x` | 54 | 1.8s |  |
| 516 | `op_escxattr` | 2 | 1.8s |  |
| 517 | `op_escxelem` | 2 | 1.7s |  |
| 518 | `op_lookupswitch` | 4 | 1.7s |  |
| 519 | `optimize_coerce` | 1 | 1.6s |  |
| 520 | `orphan_movie_complex` | 80 | 2.0s |  |
| 521 | `orphan_movie_reorder` | 111 | 20.0s |  |
| 522 | `param_default_value_has_zero_cpool_index` | 1 | 1.8s |  |
| 523 | `parent_early_access_child` | 16 | 21.2s |  |
| 524 | `parse_float` | 80 | 2.0s |  |
| 525 | `pixelbender_effect_BlurredFocus` | 0 | 24.5s |  |
| 526 | `pixelbender_effect_glassDisplace` | 0 | 8.3s |  |
| 527 | `pixelbender_effect_smudge` | 0 | 5.0s |  |
| 528 | `pixelbender_effect_tintype` | 0 | 4.2s |  |
| 529 | `pixelbender_effect_twirl` | 0 | 5.6s |  |
| 530 | `pixelbender_images` | 0 | 4.5s |  |
| 531 | `place_multiple` | 17 | 1.7s |  |
| 532 | `place_object_replace` | 9 | 1.6s |  |
| 533 | `place_object_replace_2` | 24 | 15.9s |  |
| 534 | `place_object_same_depth_frame` | 1 | 1.7s |  |
| 535 | `primitive_edge_cases` | 1 | 1.4s |  |
| 536 | `property_priority` | 22 | 1.8s |  |
| 537 | `property_priority_three_level` | 6 | 1.6s |  |
| 538 | `propertyisenumerable_namespaces` | 6 | 1.5s |  |
| 539 | `prototype_set_null` | 7 | 1.4s |  |
| 540 | `proxy_callproperty` | 24 | 1.5s |  |
| 541 | `proxy_deleteproperty` | 64 | 1.6s |  |
| 542 | `proxy_enumeration` | 34 | 1.6s |  |
| 543 | `proxy_getproperty` | 77 | 1.6s |  |
| 544 | `proxy_hasownproperty` | 8 | 1.5s |  |
| 545 | `proxy_hasproperty` | 32 | 1.6s |  |
| 546 | `proxy_serialize` | 9 | 1.6s |  |
| 547 | `proxy_setproperty` | 42 | 1.6s |  |
| 548 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.5s |  |
| 549 | `qname_constr` | 32 | 1.4s |  |
| 550 | `qname_constr_namespace` | 24 | 1.5s |  |
| 551 | `qname_enumeration` | 9 | 1.5s |  |
| 552 | `qname_indexing` | 23 | 1.6s |  |
| 553 | `qname_tostring` | 25 | 1.5s |  |
| 554 | `qname_valueof` | 29 | 1.5s |  |
| 555 | `regexp_constr` | 148 | 1.6s |  |
| 556 | `regexp_exec` | 19 | 1.4s |  |
| 557 | `regexp_extended` | 47 | 1.5s |  |
| 558 | `regexp_multiargs` | 1 | 1.5s |  |
| 559 | `regexp_test` | 27 | 13.1s |  |
| 560 | `regexp_toString` | 10 | 2.1s |  |
| 561 | `register_script_refresh` | 35 | 22.6s |  |
| 562 | `remove_child_clear_field` | 88 | 22.8s |  |
| 563 | `remove_dobj` | 3 | 2.0s |  |
| 564 | `resolve_order` | 4 | 1.9s |  |
| 565 | `rng` | 1 | 3.4s |  |
| 566 | `rootless` | 42 | 2.1s |  |
| 567 | `rshift` | 1058 | 4.3s |  |
| 568 | `scene_constr` | 8 | 1.9s |  |
| 569 | `set_property_is_enumerable` | 85 | 2.1s |  |
| 570 | `shape_drawrect` | 54 | 1.9s |  |
| 571 | `simplebutton_added_to_stage` | 45 | 22.1s |  |
| 572 | `simplebutton_childevents` | 86 | 22.4s |  |
| 573 | `simplebutton_childevents_nested` | 54 | 2.4s |  |
| 574 | `simplebutton_childevents_sprite` | 13 | 2.1s |  |
| 575 | `simplebutton_childprops` | 144 | 2.2s |  |
| 576 | `simplebutton_childshuffle` | 23 | 1.9s |  |
| 577 | `simplebutton_constr` | 36 | 2.2s |  |
| 578 | `simplebutton_constr_childevents` | 48 | 2.2s |  |
| 579 | `simplebutton_constr_params` | 42 | 2.0s |  |
| 580 | `simplebutton_mouseenabled` | 26 | 1.9s |  |
| 581 | `simplebutton_multi_children` | 19 | 2.2s |  |
| 582 | `simplebutton_structure` | 27 | 2.1s |  |
| 583 | `simplebutton_symbolclass` | 68 | 2.3s |  |
| 584 | `slot_disp_id_shared_numbering` | 1 | 32.0s |  |
| 585 | `slots_force_autoassigned` | 1 | 2.0s |  |
| 586 | `sprite_with_frames` | 0 | 21.1s |  |
| 587 | `stage3d_agal_cross_product` | 0 | 3.2s |  |
| 588 | `stage3d_bitmap` | 0 | 24.2s |  |
| 589 | `stage3d_float1_index` | 0 | 22.5s |  |
| 590 | `stage3d_fractal` | 0 | 15.0s |  |
| 591 | `stage3d_ignore_sampler_override` | 0 | 23.6s |  |
| 592 | `stage3d_program_constants_bytearray_be` | 0 | 23.2s |  |
| 593 | `stage3d_program_constants_bytearray_le` | 0 | 3.7s |  |
| 594 | `stage3d_raytrace` | 0 | 22.0s |  |
| 595 | `stage3d_rotating_cube` | 0 | 3.8s |  |
| 596 | `stage3d_sampler` | 0 | 3.3s |  |
| 597 | `stage3d_sampler_partial_upload` | 0 | 3.4s |  |
| 598 | `stage3d_stencil` | 0 | 23.3s |  |
| 599 | `stage3d_texture` | 0 | 7.5s |  |
| 600 | `stage3d_texture_bytearray` | 0 | 4.6s |  |
| 601 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 4.0s |  |
| 602 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 5.2s |  |
| 603 | `stage3d_triangle` | 0 | 3.4s |  |
| 604 | `stage3d_triangle_bytes4` | 0 | 3.4s |  |
| 605 | `stage3d_triangle_float1` | 0 | 3.5s |  |
| 606 | `stage3d_triangle_index_upload` | 0 | 3.4s |  |
| 607 | `stage_access` | 10 | 2.0s |  |
| 608 | `stage_displayobject_properties` | 24 | 1.9s |  |
| 609 | `stage_framerate_nan` | 7 | 2.1s |  |
| 610 | `stage_framerate_negative` | 6 | 1.9s |  |
| 611 | `stage_framerate_zero` | 6 | 1.9s |  |
| 612 | `stage_invalidate` | 38 | 2.1s |  |
| 613 | `stage_mouseenabled` | 15 | 1.9s |  |
| 614 | `stage_overriden_setters` | 31 | 2.1s |  |
| 615 | `stage_properties` | 30 | 2.0s |  |
| 616 | `static_var_with_this_in_ctor` | 2 | 1.9s |  |
| 617 | `stored_properties` | 11 | 12.2s |  |
| 618 | `strict_equality` | 34 | 1.8s |  |
| 619 | `string_call` | 13 | 1.8s |  |
| 620 | `string_case` | 23 | 1.8s |  |
| 621 | `string_char_at` | 27 | 1.8s |  |
| 622 | `string_char_code_at` | 28 | 1.7s |  |
| 623 | `string_concat_fromcharcode` | 36 | 1.8s |  |
| 624 | `string_constr` | 25 | 1.8s |  |
| 625 | `string_indexof_lastindexof` | 87 | 1.8s |  |
| 626 | `string_length` | 16 | 1.8s |  |
| 627 | `string_locale_compare` | 39 | 1.9s |  |
| 628 | `string_match` | 51 | 1.9s |  |
| 629 | `string_relational_compare` | 4 | 1.7s |  |
| 630 | `string_replace` | 51 | 1.9s |  |
| 631 | `string_search` | 41 | 1.8s |  |
| 632 | `string_slice_substr_substring` | 169 | 2.0s |  |
| 633 | `string_split` | 29 | 1.8s |  |
| 634 | `string_substr_negative` | 21 | 1.7s |  |
| 635 | `string_substr_weird` | 182 | 1.7s |  |
| 636 | `subtract` | 1058 | 3.8s |  |
| 637 | `super_get_call` | 12 | 1.8s |  |
| 638 | `supercall_two_classobjects` | 2 | 1.8s |  |
| 639 | `swf8` | 1 | 1.5s |  |
| 640 | `swf_10_queued_goto_scripts_construct` | 52 | 19.9s |  |
| 641 | `swf_9_goto_in_enter_frame` | 17 | 1.8s |  |
| 642 | `swf_9_goto_in_enter_frame_simple` | 15 | 1.8s |  |
| 643 | `swf_9_queued_goto_scripts` | 6 | 19.8s |  |
| 644 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 645 | `swf_wrong_frame_count` | 38 | 2.0s |  |
| 646 | `swf_wrong_frame_count_isplaying` | 22 | 12.7s |  |
| 647 | `symbol_class_conflict` | 4 | 21.4s |  |
| 648 | `symbol_class_root_not_zero` | 1 | 1.8s |  |
| 649 | `symbolclass_invalid_utf8` | 2 | 1.9s |  |
| 650 | `text_engine_fontdescription` | 27 | 2.0s |  |
| 651 | `text_run` | 7 | 1.8s |  |
| 652 | `textfield_unload` | 39 | 2.2s |  |
| 653 | `textformat` | 1134 | 1.9s |  |
| 654 | `textformat_display` | 14 | 1.9s |  |
| 655 | `textformat_font_max_length` | 4 | 1.8s |  |
| 656 | `throw` | 3 | 1.8s |  |
| 657 | `timeline_scripts` | 3 | 1.9s |  |
| 658 | `trace` | 12 | 2.0s |  |
| 659 | `truthiness` | 30 | 2.0s |  |
| 660 | `try_catch` | 11 | 2.1s |  |
| 661 | `try_catch_typed` | 12 | 2.1s |  |
| 662 | `typeof` | 30 | 2.0s |  |
| 663 | `uint_constr` | 92 | 2.1s |  |
| 664 | `uint_tofixed` | 1215 | 1.9s |  |
| 665 | `uint_tostring` | 3375 | 2.1s |  |
| 666 | `uncaught_errors_stringified` | 3 | 2.1s |  |
| 667 | `unchecked_function` | 15 | 2.0s |  |
| 668 | `urshift` | 1058 | 4.3s |  |
| 669 | `vector_class` | 36 | 2.3s |  |
| 670 | `vector_class_call` | 11 | 2.1s |  |
| 671 | `vector_coercion` | 66 | 2.6s |  |
| 672 | `vector_concat` | 90 | 2.2s |  |
| 673 | `vector_constr` | 107 | 2.1s |  |
| 674 | `vector_enumeration` | 5 | 1.9s |  |
| 675 | `vector_every` | 92 | 2.4s |  |
| 676 | `vector_filter` | 95 | 2.4s |  |
| 677 | `vector_holes` | 24 | 2.0s |  |
| 678 | `vector_indexof` | 302 | 3.1s |  |
| 679 | `vector_insertat` | 270 | 2.4s |  |
| 680 | `vector_int_access` | 4 | 1.8s |  |
| 681 | `vector_int_delete` | 11 | 1.8s |  |
| 682 | `vector_join` | 58 | 2.0s |  |
| 683 | `vector_lastindexof` | 302 | 1.8s |  |
| 684 | `vector_legacy` | 10 | 1.9s |  |
| 685 | `vector_map` | 85 | 14.7s |  |
| 686 | `vector_object_final` | 1 | 1.7s |  |
| 687 | `vector_object_toString` | 10 | 0.9s |  |
| 688 | `vector_pushpop` | 255 | 1.4s |  |
| 689 | `vector_reborrow_bug` | 10 | 0.9s |  |
| 690 | `vector_removeat` | 172 | 1.3s |  |
| 691 | `vector_reverse` | 232 | 1.3s |  |
| 692 | `vector_shiftunshift` | 252 | 0.8s |  |
| 693 | `vector_slice` | 331 | 1.4s |  |
| 694 | `vector_sort` | 905 | 2.6s |  |
| 695 | `vector_splice` | 693 | 1.7s |  |
| 696 | `vector_splice_fixed_bug_compat` | 4 | 0.9s |  |
| 697 | `vector_tostring` | 79 | 1.1s |  |
| 698 | `verify_abnormal_loop` | 1 | 0.9s |  |
| 699 | `verify_exception_targets_edge_case` | 1 | 0.9s |  |
| 700 | `verify_lookup_switch_edge_case` | 1 | 0.8s |  |
| 701 | `verify_unreachable_exception` | 2 | 0.8s |  |
| 702 | `versioned_isplaying` | 2 | 0.9s |  |
| 703 | `virtual_properties` | 16 | 0.9s |  |
| 704 | `with` | 4 | 0.9s |  |
| 705 | `xml_abstract_equality` | 36 | 1.0s |  |
| 706 | `xml_advanced` | 52 | 0.9s |  |
| 707 | `xml_appendchild` | 10 | 0.9s |  |
| 708 | `xml_as_attribute` | 9 | 0.9s |  |
| 709 | `xml_attribute` | 35 | 1.0s |  |
| 710 | `xml_attribute_name` | 40 | 0.9s |  |
| 711 | `xml_basic` | 32 | 1.2s |  |
| 712 | `xml_child` | 25 | 1.0s |  |
| 713 | `xml_childindex` | 7 | 0.9s |  |
| 714 | `xml_children` | 43 | 1.4s |  |
| 715 | `xml_class_call` | 9 | 0.9s |  |
| 716 | `xml_contains` | 197 | 7.5s |  |
| 717 | `xml_copy` | 20 | 1.5s |  |
| 718 | `xml_ctor_from_tostring` | 23 | 1.4s |  |
| 719 | `xml_delete` | 114 | 1.3s |  |
| 720 | `xml_descendants` | 83 | 1.2s |  |
| 721 | `xml_elements` | 6 | 1.1s |  |
| 722 | `xml_equals_namespace_check` | 2 | 1.1s |  |
| 723 | `xml_explicit_use_namespace` | 5 | 1.2s |  |
| 724 | `xml_getdescendants_qname` | 21 | 1.3s |  |
| 725 | `xml_has_property_via_in` | 26 | 1.2s |  |
| 726 | `xml_hasownproperty` | 6 | 1.1s |  |
| 727 | `xml_ignore_white` | 6 | 1.1s |  |
| 728 | `xml_length` | 2 | 1.2s |  |
| 729 | `xml_list_as_attribute` | 9 | 0.8s |  |
| 730 | `xml_list_concat` | 20 | 1.1s |  |
| 731 | `xml_list_enumerate` | 4 | 1.1s |  |
| 732 | `xml_methods_settings` | 3 | 1.1s |  |
| 733 | `xml_mismatched_tag` | 37 | 1.2s |  |
| 734 | `xml_namespace` | 39 | 1.3s |  |
| 735 | `xml_namespace_methods` | 245 | 1.2s |  |
| 736 | `xml_namespaced_property` | 7 | 1.1s |  |
| 737 | `xml_no_namespace` | 1 | 1.1s |  |
| 738 | `xml_nodekind` | 3 | 1.3s |  |
| 739 | `xml_normalize` | 35 | 1.3s |  |
| 740 | `xml_notification_bubbling` | 361 | 1.2s |  |
| 741 | `xml_parent` | 8 | 1.2s |  |
| 742 | `xml_set_children` | 17 | 1.2s |  |
| 743 | `xml_set_name` | 34 | 1.3s |  |
| 744 | `xml_settings` | 6 | 1.4s |  |
| 745 | `xml_simple_complex_content` | 47 | 1.2s |  |
| 746 | `xml_text` | 7 | 1.4s |  |
| 747 | `xml_tostring` | 6 | 1.2s |  |
| 748 | `xml_tostring_namespace` | 12 | 1.3s |  |
| 749 | `xml_unescaping` | 23 | 1.3s |  |
| 750 | `xml_weird_ignores` | 54 | 1.3s |  |
| 751 | `xml_wildcard` | 11 | 1.3s |  |
| 752 | `xmldocument` | 254 | 1.2s |  |
| 753 | `xmlnode` | 3540 | 1.3s |  |
| 754 | `zero_frame_clip` | 3 | 1.4s |  |

## Ruffle-Matched Tests

**21 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 1 | 1.8s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 12.6s |  |
| 3 | `blend_transform` | 1 | 1 | 1.9s |  |
| 4 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 2.0s |  |
| 5 | `dictionary_weak_keys` | 1 | 1 | 20.1s |  |
| 6 | `edittext_getcharboundaries_culling` | 300 | 300 | 2.1s |  |
| 7 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 1.9s |  |
| 8 | `edittext_tab_stops` | 6 | 6 | 2.1s |  |
| 9 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 1.8s |  |
| 10 | `error_1034_debug_string` | 19 | 19 | 1.9s |  |
| 11 | `freestanding_superclass` | 3 | 4 | 1.2s |  |
| 12 | `goto_framescript_queued` | 5 | 5 | 2.0s |  |
| 13 | `int_toexponential` | 76 | 76 | 2.0s |  |
| 14 | `int_toprecision` | 441 | 441 | 2.0s |  |
| 15 | `simplebutton_childevents_script_order` | 4 | 4 | 2.2s |  |
| 16 | `slot_holes_fail` | 1 | 1 | 1.9s |  |
| 17 | `slot_id_exceeds_trait_count` | 1 | 1 | 1.9s |  |
| 18 | `swf_9_goto_in_construct_frame` | 12 | 12 | 19.9s |  |
| 19 | `uint_toexponential` | 100 | 100 | 2.1s |  |
| 20 | `uint_toprecision` | 433 | 433 | 2.1s |  |
| 21 | `weird_superinterface_properties` | 1 | 1 | 0.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**49 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `parse_int` | 98.5% | 132 | 134 | 2 |  |
| 4 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 5 | `parse_float_swf10` | 97.5% | 78 | 80 | 2 |  |
| 6 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 7 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 8 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 9 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 10 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 12 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 13 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 14 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 15 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 16 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 17 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 18 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 19 | `bitmap_subclass` | 85.7% | 6 | 7 | 1 |  |
| 20 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 21 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 22 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 23 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 24 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 25 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 26 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 27 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 28 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 29 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 30 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 31 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 32 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 33 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 35 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 36 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 37 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 38 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 39 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 40 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 41 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 42 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 43 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 44 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 45 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 46 | `date` | 50.0% | 15 | 30 | 15 |  |
| 47 | `mouse_pick_text` | 50.0% | 4 | 8 | 4 |  |
| 48 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 49 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 1.8s |  |
| 2 | `method_without_body` | exit code 1 | 19.4s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 2.0s |  |
| 4 | `verify_typecheck` | exit code 1 | 0.9s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 31.9s |  |

## All Output Mismatches

**424 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `parse_int` | 98.5% | 132/134 | 134 | 134 |  |
| 4 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 5 | `parse_float_swf10` | 97.5% | 78/80 | 80 | 80 |  |
| 6 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 7 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 8 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 9 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 10 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 12 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 13 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 14 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 15 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 16 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 17 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 18 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 19 | `bitmap_subclass` | 85.7% | 6/7 | 7 | 7 |  |
| 20 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 21 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 22 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 23 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 24 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 25 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 26 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 27 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 28 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 29 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 30 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 31 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 32 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 33 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 34 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 35 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 36 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 37 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 38 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 39 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 40 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 41 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 42 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 43 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 44 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 45 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 46 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 47 | `mouse_pick_text` | 50.0% | 4/8 | 4 | 8 |  |
| 48 | `stage_scale_factor` | 50.0% | 6/12 | 10 | 12 |  |
| 49 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 50 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 51 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 52 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 53 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 54 | `displayobject_scrollrect` | 33.3% | 11/33 | 23 | 33 |  |
| 55 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 56 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 57 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 58 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 59 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 60 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 61 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 62 | `sound_rootless` | 28.6% | 2/7 | 2 | 7 |  |
| 63 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 64 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 65 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 66 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 67 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 68 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 69 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 70 | `bitmap_subclass_properties` | 22.2% | 2/9 | 2 | 9 |  |
| 71 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 72 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 73 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 74 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 75 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 76 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 77 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 78 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 79 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 80 | `tab_ordering_stage_tab_children` | 15.6% | 5/32 | 5 | 32 |  |
| 81 | `movieclip_drawrect` | 14.8% | 8/54 | 8 | 54 |  |
| 82 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 83 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 84 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 85 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 86 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 87 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 88 | `timer_reset` | 12.5% | 1/8 | 7 | 8 |  |
| 89 | `point` | 12.1% | 16/132 | 16 | 132 |  |
| 90 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 91 | `geom_transform` | 10.8% | 8/74 | 9 | 74 |  |
| 92 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 93 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 94 | `movieclip_displayevents_clicksymbol` | 8.7% | 59/680 | 680 | 562 |  |
| 95 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 96 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 97 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 98 | `movieclip_displayevents_clickgoto` | 7.9% | 54/680 | 680 | 676 |  |
| 99 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 100 | `agal_compiler` | 7.7% | 1/13 | 1 | 13 |  |
| 101 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 102 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 103 | `loaderinfo_properties` | 5.6% | 1/18 | 2 | 18 |  |
| 104 | `sound_load_multiple` | 5.3% | 1/19 | 1 | 19 |  |
| 105 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 106 | `pixelbender_sign` | 5.0% | 3/60 | 16 | 60 |  |
| 107 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 108 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 109 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 110 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 111 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 2 | 24 |  |
| 112 | `pixelbender_ceil` | 3.9% | 3/77 | 16 | 77 |  |
| 113 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 114 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 115 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 116 | `mouseevent_valueof_tostring` | 3.6% | 1/28 | 1 | 28 |  |
| 117 | `movieclip_displayevents_clickplay` | 3.5% | 24/680 | 680 | 575 |  |
| 118 | `movieclip_displayevents_clickgoto2` | 3.2% | 65/2001 | 1686 | 2001 |  |
| 119 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 120 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 121 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 122 | `mouseevent_stagexy` | 2.9% | 1/35 | 1 | 35 |  |
| 123 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 124 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 125 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 126 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 127 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 128 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 129 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 130 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 131 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 132 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 133 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 134 | `mouseevent_constr` | 1.5% | 1/66 | 1 | 66 |  |
| 135 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 136 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 137 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 138 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 139 | `simplebutton_soundtransform` | 0.6% | 5/887 | 95 | 887 |  |
| 140 | `tab_ordering_automatic_advanced` | 0.5% | 1/184 | 1 | 184 |  |
| 141 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 142 | `movieclip_soundtransform` | 0.4% | 3/831 | 96 | 831 |  |
| 143 | `soundmixer_soundtransform` | 0.3% | 3/900 | 48 | 900 |  |
| 144 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 145 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 146 | `soundtransform` | 0.2% | 1/442 | 1 | 442 |  |
| 147 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 148 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 149 | `all_classes/events/swf9` | 0.1% | 1/1030 | 86 | 1030 |  |
| 150 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 151 | `all_classes/display/swf10` | 0.1% | 2/2569 | 157 | 2569 |  |
| 152 | `all_classes/display/swf11` | 0.1% | 2/2593 | 157 | 2593 |  |
| 153 | `all_classes/display/swf12` | 0.1% | 2/2593 | 157 | 2593 |  |
| 154 | `all_classes/display/swf13` | 0.1% | 2/2671 | 157 | 2671 |  |
| 155 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 156 | `all_classes/events/swf10` | 0.1% | 1/1638 | 86 | 1638 |  |
| 157 | `all_classes/events/swf11` | 0.1% | 1/1750 | 86 | 1750 |  |
| 158 | `all_classes/events/swf12` | 0.1% | 1/1814 | 86 | 1814 |  |
| 159 | `all_classes/display/swf9` | 0.1% | 1/1959 | 157 | 1959 |  |
| 160 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 161 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 162 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 163 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 164 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 165 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 166 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 167 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 168 | `all_classes/display/swf30` | 0.0% | 0/2936 | 157 | 2936 |  |
| 169 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 170 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 171 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 172 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 173 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 174 | `all_classes/events/swf30` | 0.0% | 0/2353 | 86 | 2353 |  |
| 175 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 176 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 177 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 178 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 179 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 180 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 181 | `asymmetric_key_events` | 0.0% | 0/11 | 0 | 11 |  |
| 182 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 183 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 184 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 185 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 186 | `avm2_catchup_dobj` | 0.0% | 0/158 | 0 | 158 |  |
| 187 | `bitmap_pixelsnapping` | 0.0% | 0/2 | 0 | 2 |  |
| 188 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 189 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 190 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 191 | `click_block` | 0.0% | 0/5 | 0 | 5 |  |
| 192 | `click_invisible` | 0.0% | 0/3 | 0 | 3 |  |
| 193 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 194 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 195 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 196 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 197 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 198 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 199 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 200 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 201 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 202 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 203 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 204 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 205 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 206 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 207 | `displayobject_early_init` | 0.0% | 0/54 | 0 | 54 |  |
| 208 | `drag_drop` | 0.0% | 0/10 | 0 | 10 |  |
| 209 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 210 | `edittext_at_point_methods_basic` | 0.0% | 0/16 | 0 | 16 |  |
| 211 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 212 | `edittext_input_control` | 0.0% | 0/12 | 0 | 12 |  |
| 213 | `edittext_mouse_selection` | 0.0% | 0/363 | 0 | 363 |  |
| 214 | `edittext_mousedown` | 0.0% | 0/3 | 0 | 3 |  |
| 215 | `edittext_newline_character` | 0.0% | 0/22 | 0 | 22 |  |
| 216 | `edittext_paste_events` | 0.0% | 0/8 | 0 | 8 |  |
| 217 | `edittext_paste_maxchars` | 0.0% | 0/4 | 0 | 4 |  |
| 218 | `edittext_paste_restrict` | 0.0% | 0/16 | 0 | 16 |  |
| 219 | `edittext_restrict` | 0.0% | 0/191 | 0 | 191 |  |
| 220 | `edittext_restrict_events` | 0.0% | 0/22 | 0 | 22 |  |
| 221 | `edittext_selected_text` | 0.0% | 0/9 | 0 | 9 |  |
| 222 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 223 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 224 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 225 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 226 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 227 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 228 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 229 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 230 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 231 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 232 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 233 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 234 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 235 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 236 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 237 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 238 | `filter_rewind` | 0.0% | 0/8 | 1 | 8 |  |
| 239 | `focus_events_code` | 0.0% | 0/161 | 0 | 161 |  |
| 240 | `focus_events_key_basic` | 0.0% | 0/132 | 0 | 132 |  |
| 241 | `focus_events_key_navigation` | 0.0% | 0/53 | 0 | 53 |  |
| 242 | `focus_events_key_same_object` | 0.0% | 0/26 | 0 | 26 |  |
| 243 | `focus_events_mixed_avm_edittext` | 0.0% | 0/49 | 0 | 49 |  |
| 244 | `focus_events_mixed_key_mouse` | 0.0% | 0/100 | 0 | 100 |  |
| 245 | `focus_events_mouse_basic` | 0.0% | 0/260 | 0 | 260 |  |
| 246 | `focus_events_mouse_focusable` | 0.0% | 0/112 | 0 | 112 |  |
| 247 | `focus_events_mouse_same_object` | 0.0% | 0/40 | 0 | 40 |  |
| 248 | `focus_root_movie` | 0.0% | 0/4 | 0 | 4 |  |
| 249 | `focus_stage` | 0.0% | 0/1 | 0 | 1 |  |
| 250 | `focusrect` | 0.0% | 0/18 | 0 | 18 |  |
| 251 | `focusrect_focuslost` | 0.0% | 0/9 | 0 | 9 |  |
| 252 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 253 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 254 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 255 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 256 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 257 | `graphics_draw_path` | 0.0% | 0/101 | 0 | 101 |  |
| 258 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 259 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 260 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 261 | `ime_linux_dead_keys` | 0.0% | 0/10 | 0 | 10 |  |
| 262 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 263 | `issue_17675_edittext_paste_maxchars` | 0.0% | 0/1 | 0 | 1 |  |
| 264 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 265 | `key_input_80percent` | 0.0% | 0/1812 | 0 | 1812 |  |
| 266 | `key_input_location` | 0.0% | 0/126 | 0 | 126 |  |
| 267 | `key_input_numpad` | 0.0% | 0/384 | 0 | 384 |  |
| 268 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 269 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 270 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 271 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 272 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 273 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 274 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 275 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 276 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 277 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 279 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 280 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 281 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 282 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 283 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 284 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 0 | 5 |  |
| 285 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 286 | `loader_try_click_root` | 0.0% | 0/16 | 0 | 16 |  |
| 287 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 288 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 289 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 290 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 291 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 292 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 293 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 294 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 295 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 296 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 297 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 298 | `mouse_children` | 0.0% | 0/192 | 0 | 192 |  |
| 299 | `mouse_click_events` | 0.0% | 0/90 | 0 | 90 |  |
| 300 | `mouse_double_click_events` | 0.0% | 0/188 | 0 | 188 |  |
| 301 | `mouse_empty_parent` | 0.0% | 0/4 | 0 | 4 |  |
| 302 | `mouse_over_while_dragging` | 0.0% | 0/3 | 0 | 3 |  |
| 303 | `mouse_pick_avm1_root` | 0.0% | 0/2 | 0 | 2 |  |
| 304 | `mouse_pick_button_mode` | 0.0% | 0/2 | 0 | 2 |  |
| 305 | `mouse_pick_dobj_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 306 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 307 | `mouse_pick_masking` | 0.0% | 0/7 | 0 | 7 |  |
| 308 | `mouse_pick_non_interactive_bitmap_mask` | 0.0% | 0/4 | 0 | 4 |  |
| 309 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 0 | 3 |  |
| 310 | `mouse_sibling` | 0.0% | 0/8 | 0 | 8 |  |
| 311 | `mouse_wheel_events` | 0.0% | 0/36 | 0 | 36 |  |
| 312 | `movieclip_text_mousedown` | 0.0% | 0/1 | 0 | 1 |  |
| 313 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 314 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 315 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 316 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 317 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 318 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 319 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 320 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 321 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 322 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 323 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 324 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 325 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 326 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 327 | `package_namespace` | 0.0% | 0/7 | 0 | 7 |  |
| 328 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 329 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 330 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 331 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 332 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 333 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 334 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 335 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 336 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 337 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 338 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 339 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 340 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 341 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 342 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 343 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 344 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 345 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 346 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 347 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 348 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 349 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 350 | `sandbox_type_remote` | 0.0% | 0/3 | 0 | 3 |  |
| 351 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 352 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 353 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 354 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 355 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 356 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 357 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 358 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 359 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 360 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 361 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 362 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 363 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 364 | `sound_constructor_with_args` | 0.0% | 0/6 | 0 | 6 |  |
| 365 | `sound_embeddedprops` | 0.0% | 0/26 | 0 | 26 |  |
| 366 | `sound_play` | 0.0% | 0/19 | 0 | 19 |  |
| 367 | `sound_valueof` | 0.0% | 0/33 | 0 | 33 |  |
| 368 | `soundchannel_position` | 0.0% | 0/140 | 0 | 140 |  |
| 369 | `soundchannel_soundcomplete` | 0.0% | 0/16 | 0 | 16 |  |
| 370 | `soundchannel_soundtransform` | 0.0% | 0/835 | 0 | 835 |  |
| 371 | `soundchannel_soundtransform_exists` | 0.0% | 0/5 | 0 | 5 |  |
| 372 | `soundchannel_stop` | 0.0% | 0/8 | 0 | 8 |  |
| 373 | `soundmixer_buffertime` | 0.0% | 0/5 | 0 | 5 |  |
| 374 | `soundmixer_stopall` | 0.0% | 0/6 | 0 | 6 |  |
| 375 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 376 | `sprite_dropTarget` | 0.0% | 0/19 | 0 | 19 |  |
| 377 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 378 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 379 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 380 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 381 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 382 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 383 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 384 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 385 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 386 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 387 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 388 | `stage_mousechildren` | 0.0% | 0/2 | 0 | 2 |  |
| 389 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 390 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 391 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 392 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 393 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 394 | `swf_9_versioning` | 0.0% | 0/2 | 2 | 2 |  |
| 395 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 396 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 397 | `tab_ordering_automatic_basic` | 0.0% | 0/45 | 0 | 45 |  |
| 398 | `tab_ordering_children` | 0.0% | 0/116 | 0 | 116 |  |
| 399 | `tab_ordering_custom_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 400 | `tab_ordering_tabbable` | 0.0% | 0/47 | 0 | 47 |  |
| 401 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 402 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 403 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 404 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 405 | `textbox_click` | 0.0% | 0/37 | 0 | 37 |  |
| 406 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 407 | `textfield_focusin_event` | 0.0% | 0/9 | 0 | 9 |  |
| 408 | `textfield_input_dead_keys_windows` | 0.0% | 0/15 | 0 | 15 |  |
| 409 | `textfield_input_events` | 0.0% | 0/25 | 0 | 25 |  |
| 410 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 411 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 412 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 413 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 414 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 415 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 416 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 417 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 418 | `url_vars` | 0.0% | 0/27 | 0 | 27 |  |
| 419 | `urlrequest` | 0.0% | 0/18 | 0 | 18 |  |
| 420 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 421 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 422 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 423 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 424 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
