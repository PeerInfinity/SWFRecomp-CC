# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-23 00:32 UTC

**Git SHA**: `b8b5efbcdd`

**Run Duration**: 145m 6s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1215 |
| Passing | **827** (68.1%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **853** (70.2%) |
| Failing | 362 |
| Total expected lines | 151085 |
| Matching lines | 103606 (68.6%) |
| Mismatched lines | 47479 |

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
| 2 | `agal_compiler` | 13 | 2.9s |  |
| 3 | `air_hidden_lookup` | 2 | 2.9s |  |
| 4 | `all_classes/security/swf11` | 3 | 2.9s |  |
| 5 | `amf_custom_obj` | 26 | 2.9s |  |
| 6 | `amf_dictionary` | 9 | 2.9s |  |
| 7 | `amf_function` | 46 | 2.9s |  |
| 8 | `amf_invalid_date` | 2 | 2.9s |  |
| 9 | `amf_missing_prop` | 6 | 2.9s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 4.5s |  |
| 11 | `amf_setter_error` | 8 | 4.7s |  |
| 12 | `amf_vector` | 40 | 4.7s |  |
| 13 | `amf_xml` | 6 | 4.5s |  |
| 14 | `application_domain` | 4 | 4.5s |  |
| 15 | `array_access` | 18 | 4.6s |  |
| 16 | `array_access_interpreter` | 4 | 4.5s |  |
| 17 | `array_access_no_pubns` | 2 | 4.5s |  |
| 18 | `array_concat` | 41 | 4.6s |  |
| 19 | `array_constr` | 10 | 4.5s |  |
| 20 | `array_delete` | 44 | 4.6s |  |
| 21 | `array_enumeration` | 10 | 4.6s |  |
| 22 | `array_enumeration_elements` | 11 | 4.6s |  |
| 23 | `array_every` | 8 | 4.6s |  |
| 24 | `array_filter` | 6 | 4.5s |  |
| 25 | `array_foreach` | 18 | 4.5s |  |
| 26 | `array_hasownproperty` | 11 | 1.9s |  |
| 27 | `array_holes` | 9 | 4.5s |  |
| 28 | `array_index_max` | 84 | 4.3s |  |
| 29 | `array_indexof` | 25 | 4.5s |  |
| 30 | `array_join` | 26 | 4.6s |  |
| 31 | `array_lastindexof` | 29 | 4.6s |  |
| 32 | `array_length` | 14 | 4.5s |  |
| 33 | `array_literal` | 3 | 4.5s |  |
| 34 | `array_map` | 8 | 4.3s |  |
| 35 | `array_pop` | 52 | 4.7s |  |
| 36 | `array_push` | 24 | 4.6s |  |
| 37 | `array_reborrow_bug` | 6 | 4.5s |  |
| 38 | `array_reverse` | 28 | 4.6s |  |
| 39 | `array_shift` | 51 | 2.1s |  |
| 40 | `array_slice` | 39 | 4.6s |  |
| 41 | `array_some` | 8 | 4.6s |  |
| 42 | `array_sort` | 297 | 5.1s |  |
| 43 | `array_sort_fun_swf12` | 2 | 4.5s |  |
| 44 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 45 | `array_sort_random` | 210 | 4.6s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 4.5s |  |
| 47 | `array_sorton` | 545 | 5.3s |  |
| 48 | `array_sparse_ops` | 41 | 4.7s |  |
| 49 | `array_splice` | 133 | 4.8s |  |
| 50 | `array_splice2` | 428 | 4.8s |  |
| 51 | `array_splice_types` | 48 | 4.7s |  |
| 52 | `array_storage` | 8 | 4.6s |  |
| 53 | `array_tolocalestring` | 9 | 4.6s |  |
| 54 | `array_tostring` | 12 | 4.6s |  |
| 55 | `array_unshift` | 24 | 4.6s |  |
| 56 | `array_valueof` | 9 | 4.5s |  |
| 57 | `array_vector_null_callback` | 10 | 4.6s |  |
| 58 | `astype` | 28 | 4.7s |  |
| 59 | `astypelate` | 24 | 4.8s |  |
| 60 | `astypelate_propagates` | 1 | 4.5s |  |
| 61 | `asymmetric_key_events` | 11 | 4.8s |  |
| 62 | `avm2_catchup_dobj` | 158 | 5.0s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 75.0s |  |
| 64 | `bitand` | 1058 | 16.6s |  |
| 65 | `bitmap_constr` | 17 | 4.7s |  |
| 66 | `bitmap_data` | 1000 | 12.6s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 22.5s |  |
| 68 | `bitmap_properties` | 23 | 4.6s |  |
| 69 | `bitmap_subclass` | 7 | 5.9s |  |
| 70 | `bitmap_subclass_properties` | 9 | 4.8s |  |
| 71 | `bitmap_timeline` | 9 | 4.6s |  |
| 72 | `bitmapdata_accuracy` | 1 | 40.4s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 22.8s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.9s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 22.7s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 22.9s |  |
| 77 | `bitmapdata_clone` | 13 | 4.6s |  |
| 78 | `bitmapdata_colortransform` | 0 | 4.7s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 4.5s |  |
| 80 | `bitmapdata_constr` | 22 | 4.6s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 4.8s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.0s |  |
| 83 | `bitmapdata_copypixels` | 23 | 24.4s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.0s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 4.9s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.0s |  |
| 87 | `bitmapdata_draw` | 0 | 24.6s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 4.9s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 23.8s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 23.9s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 4.9s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 5.0s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 4.8s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 24.4s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 5.2s |  |
| 96 | `bitmapdata_embedded` | 9 | 5.1s |  |
| 97 | `bitmapdata_fillrect` | 0 | 5.0s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 24.3s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.1s |  |
| 100 | `bitmapdata_getpixels` | 39 | 26.2s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.5s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.3s |  |
| 103 | `bitmapdata_hittest` | 112 | 5.8s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.1s |  |
| 105 | `bitmapdata_opaque` | 0 | 5.1s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 24.9s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 5.5s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.1s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.2s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.2s |  |
| 111 | `bitmapdata_sync` | 0 | 5.1s |  |
| 112 | `bitmapdata_threshold` | 176 | 5.9s |  |
| 113 | `bitnot` | 46 | 5.1s |  |
| 114 | `bitor` | 1058 | 17.0s |  |
| 115 | `bitxor` | 1058 | 17.0s |  |
| 116 | `blend_multiply_alpha` | 0 | 5.2s |  |
| 117 | `blend_scroll` | 0 | 5.3s |  |
| 118 | `boolean_constr` | 32 | 4.6s |  |
| 119 | `boolean_negation` | 30 | 4.6s |  |
| 120 | `boolean_tostring` | 8 | 4.6s |  |
| 121 | `broadcast_event` | 7 | 4.4s |  |
| 122 | `button_nested_frame` | 48 | 23.0s |  |
| 123 | `bytearray` | 48 | 4.8s |  |
| 124 | `bytearray_compress` | 31 | 4.6s |  |
| 125 | `bytearray_errors` | 24 | 4.7s |  |
| 126 | `bytearray_method_serialization` | 1 | 4.5s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 4.6s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 4.7s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 4.7s |  |
| 130 | `bytearray_serialization` | 3 | 4.7s |  |
| 131 | `bytearray_string_null` | 19 | 5.0s |  |
| 132 | `bytearray_tostring` | 15 | 4.7s |  |
| 133 | `bytearray_utf16` | 8 | 4.6s |  |
| 134 | `bytearray_writeobject` | 24 | 4.4s |  |
| 135 | `callee_in_initializer` | 6 | 4.6s |  |
| 136 | `callproplex_class` | 1 | 4.6s |  |
| 137 | `catch_class` | 6 | 4.7s |  |
| 138 | `catch_scope_slot` | 7 | 2.2s |  |
| 139 | `checkfilter` | 4 | 2.0s |  |
| 140 | `class_call` | 32 | 23.6s |  |
| 141 | `class_cast_call` | 14 | 4.8s |  |
| 142 | `class_enumeration` | 4 | 4.8s |  |
| 143 | `class_has_own_property` | 2 | 4.7s |  |
| 144 | `class_init_interpreter_mode` | 1 | 4.5s |  |
| 145 | `class_is` | 32 | 4.7s |  |
| 146 | `class_methods` | 5 | 4.5s |  |
| 147 | `class_object_properties` | 10 | 4.7s |  |
| 148 | `class_singleton` | 18 | 4.8s |  |
| 149 | `class_supercalls_errors` | 35 | 5.0s |  |
| 150 | `class_supercalls_mismatched` | 26 | 4.8s |  |
| 151 | `class_superclass_wrong_order` | 1 | 24.6s |  |
| 152 | `class_to_locale_string` | 2 | 4.9s |  |
| 153 | `class_to_string` | 2 | 4.8s |  |
| 154 | `class_value_of` | 2 | 4.9s |  |
| 155 | `click_block` | 5 | 25.0s |  |
| 156 | `click_invisible` | 3 | 5.1s |  |
| 157 | `closures` | 12 | 5.0s |  |
| 158 | `coerce_return_type` | 40 | 5.1s |  |
| 159 | `coerce_return_type_fail` | 2 | 4.9s |  |
| 160 | `coerce_return_void` | 3 | 4.8s |  |
| 161 | `coerce_string` | 86 | 5.1s |  |
| 162 | `coerce_string_precision` | 28 | 5.0s |  |
| 163 | `coerce_to_primitive_side_effects` | 29 | 5.0s |  |
| 164 | `construct_errors_swf10` | 8 | 4.9s |  |
| 165 | `construct_frame_list` | 22 | 25.0s |  |
| 166 | `constructor_call` | 3 | 4.9s |  |
| 167 | `constructors_vs_timeline` | 5 | 25.1s |  |
| 168 | `constructprop_dynamic_primitive` | 7 | 5.0s |  |
| 169 | `control_flow_bool` | 4 | 5.0s |  |
| 170 | `control_flow_stricteq` | 8 | 5.0s |  |
| 171 | `convert_boolean` | 30 | 5.0s |  |
| 172 | `convert_integer` | 90 | 5.1s |  |
| 173 | `convert_number` | 56 | 5.0s |  |
| 174 | `convert_uinteger` | 90 | 5.1s |  |
| 175 | `cryptscore` | 11 | 5.1s |  |
| 176 | `declocal` | 46 | 3.3s |  |
| 177 | `declocal_i` | 46 | 3.1s |  |
| 178 | `decrement` | 46 | 3.5s |  |
| 179 | `decrement_i` | 46 | 1.3s |  |
| 180 | `default_values` | 7 | 3.4s |  |
| 181 | `dictionary_access` | 62 | 3.6s |  |
| 182 | `dictionary_access_no_pubns` | 2 | 3.2s |  |
| 183 | `dictionary_delete` | 101 | 3.7s |  |
| 184 | `dictionary_foreach` | 42 | 3.3s |  |
| 185 | `dictionary_hasownproperty` | 63 | 3.2s |  |
| 186 | `dictionary_in` | 62 | 3.2s |  |
| 187 | `dictionary_iter_modify` | 8 | 3.1s |  |
| 188 | `dictionary_namespaces` | 36 | 3.1s |  |
| 189 | `dictionary_primitive_keys` | 29 | 3.0s |  |
| 190 | `displayobject_alpha` | 277 | 3.2s |  |
| 191 | `displayobject_blendmode` | 0 | 3.2s |  |
| 192 | `displayobject_colortransform_nested` | 0 | 16.7s |  |
| 193 | `displayobject_from_enterframe` | 1 | 16.5s |  |
| 194 | `displayobject_getbounds_shape` | 0 | 16.7s |  |
| 195 | `displayobject_height` | 6052 | 16.3s |  |
| 196 | `displayobject_hittestobject` | 32 | 3.6s |  |
| 197 | `displayobject_invalid_floats` | 60 | 3.3s |  |
| 198 | `displayobject_invalid_props` | 3 | 3.1s |  |
| 199 | `displayobject_mask` | 3 | 3.5s |  |
| 200 | `displayobject_mask_self_referential` | 0 | 3.0s |  |
| 201 | `displayobject_metaData` | 3 | 4.3s |  |
| 202 | `displayobject_name` | 22 | 22.5s |  |
| 203 | `displayobject_name_from_timeline` | 24 | 4.5s |  |
| 204 | `displayobject_parent` | 12 | 4.3s |  |
| 205 | `displayobject_root` | 24 | 4.3s |  |
| 206 | `displayobject_rotation` | 1284 | 4.5s |  |
| 207 | `displayobject_set_matrix_nested` | 0 | 22.7s |  |
| 208 | `displayobject_subclass` | 2 | 4.3s |  |
| 209 | `displayobject_visible` | 23 | 4.3s |  |
| 210 | `displayobject_width` | 4852 | 22.4s |  |
| 211 | `displayobject_x` | 614 | 4.4s |  |
| 212 | `displayobject_y` | 617 | 4.3s |  |
| 213 | `displayobjectcontainer_addchild` | 32 | 4.4s |  |
| 214 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.2s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.4s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.3s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.4s |  |
| 218 | `displayobjectcontainer_addchildat` | 42 | 4.3s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.3s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.3s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.3s |  |
| 222 | `displayobjectcontainer_contains` | 66 | 22.1s |  |
| 223 | `displayobjectcontainer_getchildat` | 4 | 4.3s |  |
| 224 | `displayobjectcontainer_getchildbyname` | 9 | 4.2s |  |
| 225 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.2s |  |
| 226 | `displayobjectcontainer_getchildindex` | 28 | 4.2s |  |
| 227 | `displayobjectcontainer_removechild` | 10 | 4.2s |  |
| 228 | `displayobjectcontainer_removechild_errors` | 4 | 4.2s |  |
| 229 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.3s |  |
| 230 | `displayobjectcontainer_removechildat` | 18 | 4.2s |  |
| 231 | `displayobjectcontainer_removechildren` | 51 | 4.4s |  |
| 232 | `displayobjectcontainer_setchildindex` | 42 | 4.1s |  |
| 233 | `displayobjectcontainer_stopallmovieclips` | 2 | 22.2s |  |
| 234 | `displayobjectcontainer_swapchildren` | 42 | 4.3s |  |
| 235 | `displayobjectcontainer_swapchildrenat` | 42 | 4.3s |  |
| 236 | `displayobjectcontainer_timelineinstance` | 48 | 22.0s |  |
| 237 | `divide` | 1058 | 16.8s |  |
| 238 | `doabc_is_eager` | 1 | 22.4s |  |
| 239 | `documentclass` | 9 | 4.7s |  |
| 240 | `drag_drop` | 10 | 4.7s |  |
| 241 | `duplicate_defs` | 1 | 4.3s |  |
| 242 | `eager_init` | 1 | 4.5s |  |
| 243 | `edit_text_linkage` | 7 | 4.8s |  |
| 244 | `edittext_align` | 60 | 4.9s |  |
| 245 | `edittext_always_show_selection` | 0 | 23.0s |  |
| 246 | `edittext_antialiastype` | 296 | 4.8s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 5.9s |  |
| 248 | `edittext_autosize` | 39 | 4.9s |  |
| 249 | `edittext_autosize_align` | 0 | 22.9s |  |
| 250 | `edittext_autosize_height_dynamic` | 60 | 22.9s |  |
| 251 | `edittext_autosize_height_input` | 60 | 4.7s |  |
| 252 | `edittext_autosize_lazy_bounds_events` | 65 | 4.9s |  |
| 253 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.6s |  |
| 254 | `edittext_autosize_lazy_bounds_props` | 490 | 6.0s |  |
| 255 | `edittext_autosize_lazy_bounds_visual` | 0 | 22.8s |  |
| 256 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.8s |  |
| 257 | `edittext_bottom_scroll_v_basic` | 210 | 4.7s |  |
| 258 | `edittext_bounds_scale` | 24 | 22.6s |  |
| 259 | `edittext_bullet` | 30 | 4.6s |  |
| 260 | `edittext_default_format` | 221 | 5.0s |  |
| 261 | `edittext_default_format_empty` | 136 | 4.8s |  |
| 262 | `edittext_empty_text_format` | 7 | 4.6s |  |
| 263 | `edittext_focus_selection` | 5 | 4.6s |  |
| 264 | `edittext_font_size` | 45 | 4.6s |  |
| 265 | `edittext_format_empty_font` | 8 | 4.6s |  |
| 266 | `edittext_get_char_index_at_point` | 4 | 23.2s |  |
| 267 | `edittext_get_line_index_at_point` | 2 | 23.1s |  |
| 268 | `edittext_get_line_index_of_char` | 76 | 5.5s |  |
| 269 | `edittext_getcharboundaries` | 172 | 5.0s |  |
| 270 | `edittext_getcharboundaries_missing_glyphs` | 63 | 23.7s |  |
| 271 | `edittext_getcharboundaries_scroll` | 85 | 5.0s |  |
| 272 | `edittext_getlinemetrics` | 146 | 5.0s |  |
| 273 | `edittext_html` | 3101 | 5.2s |  |
| 274 | `edittext_html_condensewhite` | 487 | 4.8s |  |
| 275 | `edittext_html_entity` | 4 | 5.0s |  |
| 276 | `edittext_html_font_size_swf12` | 267 | 4.9s |  |
| 277 | `edittext_html_font_size_swf13` | 273 | 4.5s |  |
| 278 | `edittext_html_roundtrip` | 17 | 4.9s |  |
| 279 | `edittext_input_control` | 12 | 5.0s |  |
| 280 | `edittext_leading` | 9 | 5.1s |  |
| 281 | `edittext_letter_spacing` | 15 | 4.8s |  |
| 282 | `edittext_line_methods` | 294 | 6.1s |  |
| 283 | `edittext_line_metrics` | 11 | 25.1s |  |
| 284 | `edittext_margins` | 25 | 4.8s |  |
| 285 | `edittext_max_scroll_h_basic` | 475 | 5.0s |  |
| 286 | `edittext_max_scroll_v_basic` | 1000 | 4.9s |  |
| 287 | `edittext_mousedown` | 3 | 5.1s |  |
| 288 | `edittext_mouseenabled` | 26 | 4.8s |  |
| 289 | `edittext_newline_character` | 22 | 4.7s |  |
| 290 | `edittext_newline_stripping` | 64 | 7.4s |  |
| 291 | `edittext_newlines` | 30 | 4.8s |  |
| 292 | `edittext_paragraph_methods` | 257 | 4.8s |  |
| 293 | `edittext_paste_events` | 8 | 5.0s |  |
| 294 | `edittext_paste_maxchars` | 4 | 4.9s |  |
| 295 | `edittext_paste_restrict` | 16 | 4.7s |  |
| 296 | `edittext_restrict` | 191 | 4.9s |  |
| 297 | `edittext_restrict_events` | 22 | 4.9s |  |
| 298 | `edittext_scrollh` | 10 | 4.8s |  |
| 299 | `edittext_selected_text` | 9 | 4.8s |  |
| 300 | `edittext_set_html_same` | 17 | 4.8s |  |
| 301 | `edittext_set_text_vs_html` | 9 | 4.8s |  |
| 302 | `edittext_stylesheet` | 536 | 5.2s |  |
| 303 | `edittext_stylesheet_custom_tag` | 76 | 4.9s |  |
| 304 | `edittext_stylesheet_display` | 272 | 4.9s |  |
| 305 | `edittext_underline` | 40 | 4.9s |  |
| 306 | `edittext_width_height` | 103 | 5.1s |  |
| 307 | `edittext_wordwrap_word` | 150 | 4.9s |  |
| 308 | `edittext_wrap_breaks` | 2375 | 5.3s |  |
| 309 | `empty_bounds` | 1 | 4.6s |  |
| 310 | `equals` | 512 | 9.0s |  |
| 311 | `error_prototype` | 15 | 4.6s |  |
| 312 | `error_stack_trace_debug_swf17` | 0 | 22.8s |  |
| 313 | `error_stack_trace_debug_swf18` | 0 | 4.4s |  |
| 314 | `error_stack_trace_release_swf17` | 0 | 4.4s |  |
| 315 | `error_stack_trace_release_swf18` | 0 | 4.4s |  |
| 316 | `error_tostring` | 29 | 4.6s |  |
| 317 | `es3_inheritance` | 31 | 4.7s |  |
| 318 | `es4_inheritance` | 30 | 4.7s |  |
| 319 | `es4_interfaces` | 30 | 4.7s |  |
| 320 | `es4_method_binding` | 8 | 4.6s |  |
| 321 | `es4_oop_prototypes` | 14 | 4.8s |  |
| 322 | `es4_protected_inheritance` | 6 | 4.6s |  |
| 323 | `event_bubbles` | 2 | 4.7s |  |
| 324 | `event_cancelable` | 2 | 4.5s |  |
| 325 | `event_clone` | 20 | 4.7s |  |
| 326 | `event_clone_error_redispatch` | 3 | 4.7s |  |
| 327 | `event_clone_on_redispatch` | 10 | 4.7s |  |
| 328 | `event_formattostring` | 31 | 4.7s |  |
| 329 | `event_isdefaultprevented` | 12 | 4.6s |  |
| 330 | `event_target_getter` | 5 | 2.0s |  |
| 331 | `event_target_set` | 9 | 4.6s |  |
| 332 | `event_type` | 1 | 4.6s |  |
| 333 | `event_valueof_tostring` | 18 | 4.7s |  |
| 334 | `eventdispatcher_dispatchevent` | 12 | 4.6s |  |
| 335 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.6s |  |
| 336 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.6s |  |
| 337 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.7s |  |
| 338 | `eventdispatcher_dispatchevent_this` | 5 | 4.6s |  |
| 339 | `eventdispatcher_haseventlistener` | 25 | 4.6s |  |
| 340 | `eventdispatcher_interface_invoke` | 1 | 4.7s |  |
| 341 | `eventdispatcher_tostring` | 10 | 4.8s |  |
| 342 | `eventdispatcher_willtrigger` | 25 | 4.6s |  |
| 343 | `falsiness` | 30 | 4.6s |  |
| 344 | `fast_index_access` | 12 | 4.8s |  |
| 345 | `finddef` | 3 | 4.6s |  |
| 346 | `findprop_global_prototype` | 6 | 4.6s |  |
| 347 | `flash_xml` | 29 | 4.8s |  |
| 348 | `flash_xml_cloneNode` | 22 | 4.7s |  |
| 349 | `flash_xml_namespace` | 109 | 4.6s |  |
| 350 | `flash_xml_removeNode` | 60 | 4.6s |  |
| 351 | `focus_events_code` | 161 | 23.1s |  |
| 352 | `focus_events_key_same_object` | 26 | 4.7s |  |
| 353 | `focus_events_mixed_key_mouse` | 100 | 23.6s |  |
| 354 | `focus_events_mouse_same_object` | 40 | 22.2s |  |
| 355 | `focus_remove` | 20 | 22.2s |  |
| 356 | `focus_root_movie` | 4 | 22.2s |  |
| 357 | `focus_stage` | 1 | 4.2s |  |
| 358 | `focusrect` | 18 | 4.9s |  |
| 359 | `font_description_clone` | 14 | 4.3s |  |
| 360 | `font_embedded` | 24 | 4.6s |  |
| 361 | `font_enumeratefonts` | 41 | 4.8s |  |
| 362 | `font_enumeratefonts_filter` | 4 | 22.7s |  |
| 363 | `font_hasglyphs` | 40 | 4.6s |  |
| 364 | `framelabel_constr` | 5 | 4.3s |  |
| 365 | `function_call` | 12 | 4.3s |  |
| 366 | `function_call_arguments` | 46 | 4.3s |  |
| 367 | `function_call_arguments_enumerate` | 5 | 4.2s |  |
| 368 | `function_call_coercion` | 108 | 4.6s |  |
| 369 | `function_call_default` | 6 | 4.2s |  |
| 370 | `function_call_rest` | 22 | 4.2s |  |
| 371 | `function_call_types` | 3 | 4.2s |  |
| 372 | `function_call_via_apply` | 11 | 4.2s |  |
| 373 | `function_call_via_call` | 3 | 4.2s |  |
| 374 | `function_display_anonymous` | 7 | 1.7s |  |
| 375 | `function_length` | 6 | 4.2s |  |
| 376 | `function_object` | 2 | 4.2s |  |
| 377 | `function_proto` | 5 | 4.2s |  |
| 378 | `function_proto_created` | 61 | 4.3s |  |
| 379 | `function_to_locale_string` | 4 | 4.2s |  |
| 380 | `function_to_string` | 4 | 4.1s |  |
| 381 | `function_type` | 6 | 4.2s |  |
| 382 | `function_unbound_this` | 51 | 4.3s |  |
| 383 | `function_value_of` | 4 | 4.2s |  |
| 384 | `get_definition_by_name` | 11 | 4.2s |  |
| 385 | `get_qualified_class_name` | 20 | 4.2s |  |
| 386 | `get_qualified_super_class_name` | 18 | 4.7s |  |
| 387 | `get_slot_edge_cases` | 1 | 22.2s |  |
| 388 | `get_timer` | 2 | 4.5s |  |
| 389 | `getglobalslot` | 1 | 4.4s |  |
| 390 | `getouterscope` | 8 | 4.5s |  |
| 391 | `getter_different_namespace_setter` | 2 | 4.7s |  |
| 392 | `goto_button_nested_framescript` | 28 | 23.0s |  |
| 393 | `goto_in_constructframe` | 12 | 23.4s |  |
| 394 | `goto_in_scene_last_frame` | 2 | 23.3s |  |
| 395 | `goto_methods` | 56 | 4.9s |  |
| 396 | `goto_methods_swfver10` | 8 | 4.8s |  |
| 397 | `goto_nested_construct_sibling` | 18 | 5.2s |  |
| 398 | `goto_nested_framescript` | 9 | 4.8s |  |
| 399 | `goto_on_orphan` | 15 | 4.9s |  |
| 400 | `graphics_bad_direct_commands` | 5 | 5.2s |  |
| 401 | `graphics_bitmap_fill` | 0 | 6.3s |  |
| 402 | `graphics_bitmaps` | 0 | 5.0s |  |
| 403 | `graphics_direct_commands` | 0 | 4.8s |  |
| 404 | `graphics_draw_triangles` | 98 | 24.1s |  |
| 405 | `graphics_gradients` | 0 | 4.8s |  |
| 406 | `graphics_gradients_nulls` | 0 | 4.9s |  |
| 407 | `graphics_path` | 56 | 4.8s |  |
| 408 | `graphics_round_rects` | 0 | 4.7s |  |
| 409 | `graphics_simple_shapes` | 0 | 4.8s |  |
| 410 | `greaterequals` | 512 | 8.8s |  |
| 411 | `greaterthan` | 512 | 8.8s |  |
| 412 | `has_own_property` | 102 | 5.2s |  |
| 413 | `hasownproperty_namespaces` | 2 | 4.6s |  |
| 414 | `hello_world` | 1 | 4.5s |  |
| 415 | `hittest_morph` | 30 | 4.7s |  |
| 416 | `if_eq` | 10 | 4.7s |  |
| 417 | `if_gt` | 1 | 4.7s |  |
| 418 | `if_gte` | 10 | 2.0s |  |
| 419 | `if_lt` | 1 | 0.5s |  |
| 420 | `if_lte` | 10 | 4.6s |  |
| 421 | `if_ne` | 7 | 4.5s |  |
| 422 | `if_stricteq` | 6 | 4.6s |  |
| 423 | `if_strictne` | 11 | 4.5s |  |
| 424 | `in` | 102 | 5.0s |  |
| 425 | `inclocal` | 46 | 4.6s |  |
| 426 | `inclocal_i` | 46 | 4.6s |  |
| 427 | `increment` | 46 | 4.6s |  |
| 428 | `increment_i` | 46 | 4.6s |  |
| 429 | `instanceof` | 58 | 4.8s |  |
| 430 | `instantiation_on_enter_frame` | 7 | 22.3s |  |
| 431 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.5s |  |
| 432 | `int_constr` | 92 | 4.8s |  |
| 433 | `int_edge_cases` | 19 | 4.5s |  |
| 434 | `int_instanceof` | 3 | 4.5s |  |
| 435 | `int_tofixed` | 1215 | 4.4s |  |
| 436 | `int_tostring` | 3375 | 4.8s |  |
| 437 | `interactiveobject_enabled` | 25 | 4.5s |  |
| 438 | `interface_namespaces` | 78 | 4.8s |  |
| 439 | `is_finite` | 46 | 4.7s |  |
| 440 | `is_nan` | 46 | 4.5s |  |
| 441 | `is_prototype_of` | 12 | 4.6s |  |
| 442 | `issue_10221` | 2 | 4.5s |  |
| 443 | `issue_13780` | 12 | 4.5s |  |
| 444 | `issue_14901` | 1 | 4.5s |  |
| 445 | `issue_17675_edittext_paste_maxchars` | 1 | 4.5s |  |
| 446 | `issue_5292` | 5 | 4.5s |  |
| 447 | `issue_8630` | 2 | 22.1s |  |
| 448 | `issue_8630_scriptremove` | 11 | 4.5s |  |
| 449 | `istype` | 24 | 2.0s |  |
| 450 | `istypelate` | 58 | 4.8s |  |
| 451 | `istypelate_coerce` | 198 | 5.5s |  |
| 452 | `json_errors` | 9 | 23.0s |  |
| 453 | `json_parse` | 21 | 4.7s |  |
| 454 | `json_version_gated` | 1 | 4.6s |  |
| 455 | `key_input_80percent` | 1812 | 4.8s |  |
| 456 | `key_input_location` | 126 | 4.8s |  |
| 457 | `key_input_numpad` | 384 | 4.7s |  |
| 458 | `lazyinit` | 17 | 4.7s |  |
| 459 | `lessequals` | 512 | 8.2s |  |
| 460 | `lessthan` | 512 | 8.2s |  |
| 461 | `loaderinfo_properties` | 18 | 22.4s |  |
| 462 | `loaderinfo_root` | 10 | 4.6s |  |
| 463 | `loaderinfo_root_allows` | 2 | 4.5s |  |
| 464 | `lshift` | 1058 | 16.4s |  |
| 465 | `mask_reapply` | 1 | 22.6s |  |
| 466 | `math` | 497 | 4.8s |  |
| 467 | `missing_external_interface` | 10 | 4.6s |  |
| 468 | `modulo` | 1058 | 16.6s |  |
| 469 | `morph_shape` | 2 | 22.7s |  |
| 470 | `mouse_click_events` | 90 | 22.6s |  |
| 471 | `mouse_double_click_events` | 188 | 4.6s |  |
| 472 | `mouse_empty_parent` | 4 | 4.6s |  |
| 473 | `mouse_over_while_dragging` | 3 | 4.7s |  |
| 474 | `mouse_pick_button_mode` | 2 | 4.6s |  |
| 475 | `mouse_sibling` | 8 | 4.6s |  |
| 476 | `movieclip_addframescript` | 3 | 22.5s |  |
| 477 | `movieclip_child_property` | 16 | 4.6s |  |
| 478 | `movieclip_constr` | 21 | 4.5s |  |
| 479 | `movieclip_currentlabels` | 17 | 21.3s |  |
| 480 | `movieclip_currentlabels_dupes1` | 46 | 21.2s |  |
| 481 | `movieclip_currentlabels_dupes2` | 30 | 4.0s |  |
| 482 | `movieclip_currentlabels_dupes3` | 67 | 4.0s |  |
| 483 | `movieclip_currentscene` | 12 | 21.2s |  |
| 484 | `movieclip_dispatchevent` | 430 | 4.2s |  |
| 485 | `movieclip_dispatchevent_cancel` | 102 | 4.2s |  |
| 486 | `movieclip_dispatchevent_handlerorder` | 251 | 4.1s |  |
| 487 | `movieclip_dispatchevent_selfadd` | 80 | 4.0s |  |
| 488 | `movieclip_dispatchevent_target` | 899 | 4.4s |  |
| 489 | `movieclip_displayevents` | 96 | 20.9s |  |
| 490 | `movieclip_displayevents_clickgoto` | 676 | 21.4s |  |
| 491 | `movieclip_displayevents_clickgoto2` | 2001 | 4.4s |  |
| 492 | `movieclip_displayevents_clickplay` | 575 | 4.1s |  |
| 493 | `movieclip_displayevents_clicksymbol` | 562 | 4.1s |  |
| 494 | `movieclip_displayevents_constructframegoto` | 140 | 4.2s |  |
| 495 | `movieclip_displayevents_constructframeplay` | 50 | 4.5s |  |
| 496 | `movieclip_displayevents_constructframesymbol` | 144 | 4.4s |  |
| 497 | `movieclip_displayevents_dblhandler` | 21 | 4.3s |  |
| 498 | `movieclip_displayevents_enterframegoto` | 149 | 4.3s |  |
| 499 | `movieclip_displayevents_enterframeplay` | 48 | 4.2s |  |
| 500 | `movieclip_displayevents_enterframesymbol` | 149 | 21.2s |  |
| 501 | `movieclip_displayevents_exitframegoto` | 106 | 4.2s |  |
| 502 | `movieclip_displayevents_exitframeplay` | 44 | 4.2s |  |
| 503 | `movieclip_displayevents_exitframesymbol` | 135 | 4.2s |  |
| 504 | `movieclip_displayevents_looping` | 63 | 21.2s |  |
| 505 | `movieclip_displayevents_stopped` | 113 | 4.4s |  |
| 506 | `movieclip_displayevents_swap` | 96 | 2.2s |  |
| 507 | `movieclip_displayevents_timeline` | 128 | 21.6s |  |
| 508 | `movieclip_drawrect` | 54 | 4.1s |  |
| 509 | `movieclip_frameconstruct_skipped` | 9 | 4.1s |  |
| 510 | `movieclip_goto_during_frame_script` | 15 | 4.1s |  |
| 511 | `movieclip_goto_overwrite` | 14 | 21.2s |  |
| 512 | `movieclip_goto_scene_last_frame_int` | 1 | 21.6s |  |
| 513 | `movieclip_goto_scene_last_frame_label` | 1 | 3.9s |  |
| 514 | `movieclip_gotoandplay` | 15 | 21.0s |  |
| 515 | `movieclip_gotoandstop` | 13 | 4.2s |  |
| 516 | `movieclip_gotoandstop_children` | 4 | 4.2s |  |
| 517 | `movieclip_gotoandstop_framescripts1` | 4 | 4.3s |  |
| 518 | `movieclip_gotoandstop_framescripts2` | 4 | 1.8s |  |
| 519 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.4s |  |
| 520 | `movieclip_gotoandstop_queueing` | 12 | 22.3s |  |
| 521 | `movieclip_next_frame` | 2 | 22.2s |  |
| 522 | `movieclip_next_scene` | 6 | 22.1s |  |
| 523 | `movieclip_play` | 3 | 4.4s |  |
| 524 | `movieclip_prev_frame` | 3 | 4.2s |  |
| 525 | `movieclip_prev_scene` | 7 | 4.5s |  |
| 526 | `movieclip_properties` | 79 | 22.4s |  |
| 527 | `movieclip_queued_noop_goto_swf10` | 9 | 4.5s |  |
| 528 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 529 | `movieclip_scenes` | 11 | 4.4s |  |
| 530 | `movieclip_soundtransform` | 831 | 24.3s |  |
| 531 | `movieclip_stop` | 1 | 22.1s |  |
| 532 | `movieclip_super_is_symbol` | 20 | 4.8s |  |
| 533 | `movieclip_symbol_constr` | 8 | 4.6s |  |
| 534 | `movieclip_text_mousedown` | 1 | 4.5s |  |
| 535 | `movieclip_willtrigger` | 5 | 4.7s |  |
| 536 | `multiply` | 1058 | 16.3s |  |
| 537 | `namespace_constr` | 253 | 4.8s |  |
| 538 | `namespace_constr_args` | 1 | 4.4s |  |
| 539 | `namespace_enumeration_order` | 7 | 4.5s |  |
| 540 | `nan_scale` | 9 | 4.5s |  |
| 541 | `negate` | 30 | 4.5s |  |
| 542 | `negative_volume_panned` | 0 | 4.7s |  |
| 543 | `nested_iteration` | 11 | 4.5s |  |
| 544 | `net_getClassByAlias` | 3 | 4.5s |  |
| 545 | `newactivation_in_script_init` | 3 | 3.5s |  |
| 546 | `newclass_twice` | 3 | 3.5s |  |
| 547 | `nonconflicting_declarations` | 0 | 3.6s |  |
| 548 | `null_void_types` | 8 | 3.6s |  |
| 549 | `number_autoconv` | 21 | 3.6s |  |
| 550 | `number_autoconv_amf` | 132 | 3.6s |  |
| 551 | `number_autoconv_array_sort_32bit` | 1 | 3.6s |  |
| 552 | `number_constr` | 58 | 3.7s |  |
| 553 | `number_toexponential` | 378 | 3.6s |  |
| 554 | `number_toexponential2` | 35 | 3.6s |  |
| 555 | `number_tofixed` | 378 | 3.5s |  |
| 556 | `number_toprecision` | 350 | 3.6s |  |
| 557 | `obfuscated_class_names` | 3 | 3.5s |  |
| 558 | `object_enumeration` | 10 | 3.6s |  |
| 559 | `object_prototype` | 4 | 3.6s |  |
| 560 | `object_to_locale_string` | 2 | 3.6s |  |
| 561 | `object_to_string` | 2 | 3.5s |  |
| 562 | `object_value_of` | 2 | 1.2s |  |
| 563 | `op_coerce` | 54 | 3.6s |  |
| 564 | `op_coerce_x` | 54 | 3.6s |  |
| 565 | `op_escxattr` | 2 | 3.6s |  |
| 566 | `op_escxelem` | 2 | 3.6s |  |
| 567 | `op_lookupswitch` | 4 | 3.6s |  |
| 568 | `optimize_coerce` | 1 | 3.5s |  |
| 569 | `orphan_movie_complex` | 80 | 3.9s |  |
| 570 | `orphan_movie_reorder` | 111 | 19.3s |  |
| 571 | `package_namespace` | 7 | 3.4s |  |
| 572 | `param_default_value_has_zero_cpool_index` | 1 | 3.5s |  |
| 573 | `parent_early_access_child` | 16 | 19.1s |  |
| 574 | `pixelbender_effect_BlurredFocus` | 0 | 26.3s |  |
| 575 | `pixelbender_effect_glassDisplace` | 0 | 10.2s |  |
| 576 | `pixelbender_effect_smudge` | 0 | 7.8s |  |
| 577 | `pixelbender_effect_tintype` | 0 | 7.0s |  |
| 578 | `pixelbender_effect_twirl` | 0 | 8.3s |  |
| 579 | `pixelbender_images` | 0 | 6.6s |  |
| 580 | `place_multiple` | 17 | 23.0s |  |
| 581 | `place_object_replace` | 9 | 4.8s |  |
| 582 | `place_object_replace_2` | 24 | 4.8s |  |
| 583 | `place_object_same_depth_frame` | 1 | 4.7s |  |
| 584 | `point` | 132 | 5.2s |  |
| 585 | `primitive_edge_cases` | 1 | 4.5s |  |
| 586 | `property_priority` | 22 | 5.2s |  |
| 587 | `property_priority_three_level` | 6 | 24.4s |  |
| 588 | `propertyisenumerable_namespaces` | 6 | 4.8s |  |
| 589 | `prototype_set_null` | 7 | 4.8s |  |
| 590 | `proxy_callproperty` | 24 | 4.9s |  |
| 591 | `proxy_deleteproperty` | 64 | 5.0s |  |
| 592 | `proxy_enumeration` | 34 | 4.9s |  |
| 593 | `proxy_getproperty` | 77 | 5.0s |  |
| 594 | `proxy_hasownproperty` | 8 | 4.8s |  |
| 595 | `proxy_hasproperty` | 32 | 4.9s |  |
| 596 | `proxy_serialize` | 9 | 4.8s |  |
| 597 | `proxy_setproperty` | 42 | 4.9s |  |
| 598 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.8s |  |
| 599 | `qname_constr` | 32 | 4.9s |  |
| 600 | `qname_constr_namespace` | 24 | 4.9s |  |
| 601 | `qname_enumeration` | 9 | 4.8s |  |
| 602 | `qname_indexing` | 23 | 4.9s |  |
| 603 | `qname_tostring` | 25 | 4.9s |  |
| 604 | `qname_valueof` | 29 | 4.9s |  |
| 605 | `regexp_constr` | 148 | 5.1s |  |
| 606 | `regexp_exec` | 19 | 4.9s |  |
| 607 | `regexp_extended` | 47 | 4.8s |  |
| 608 | `regexp_multiargs` | 1 | 4.7s |  |
| 609 | `regexp_test` | 27 | 4.9s |  |
| 610 | `regexp_toString` | 10 | 4.9s |  |
| 611 | `register_script_refresh` | 35 | 24.9s |  |
| 612 | `remove_child_clear_field` | 88 | 24.9s |  |
| 613 | `remove_dobj` | 3 | 4.8s |  |
| 614 | `resolve_order` | 4 | 4.8s |  |
| 615 | `rng` | 1 | 6.0s |  |
| 616 | `rootless` | 42 | 5.0s |  |
| 617 | `rshift` | 1058 | 16.7s |  |
| 618 | `sandbox_type_local_file` | 1 | 4.5s |  |
| 619 | `scene_constr` | 8 | 4.8s |  |
| 620 | `set_local_0` | 31 | 4.6s |  |
| 621 | `set_property_is_enumerable` | 85 | 5.0s |  |
| 622 | `shape_drawrect` | 54 | 4.6s |  |
| 623 | `shared_object_no_root` | 3 | 4.5s |  |
| 624 | `simplebutton_added_to_stage` | 45 | 22.7s |  |
| 625 | `simplebutton_childevents` | 86 | 23.1s |  |
| 626 | `simplebutton_childevents_nested` | 54 | 5.0s |  |
| 627 | `simplebutton_childevents_sprite` | 13 | 4.7s |  |
| 628 | `simplebutton_childprops` | 144 | 4.9s |  |
| 629 | `simplebutton_childshuffle` | 23 | 4.5s |  |
| 630 | `simplebutton_constr` | 36 | 4.8s |  |
| 631 | `simplebutton_constr_childevents` | 48 | 4.9s |  |
| 632 | `simplebutton_constr_params` | 42 | 4.7s |  |
| 633 | `simplebutton_mouseenabled` | 26 | 4.6s |  |
| 634 | `simplebutton_multi_children` | 19 | 4.8s |  |
| 635 | `simplebutton_structure` | 27 | 4.8s |  |
| 636 | `simplebutton_symbolclass` | 68 | 5.0s |  |
| 637 | `slot_disp_id_shared_numbering` | 1 | 22.5s |  |
| 638 | `slots_force_autoassigned` | 1 | 4.6s |  |
| 639 | `sound_embeddedprops` | 26 | 5.0s |  |
| 640 | `sound_play` | 19 | 5.1s |  |
| 641 | `sound_valueof` | 33 | 4.9s |  |
| 642 | `soundchannel_soundtransform` | 835 | 25.8s |  |
| 643 | `soundchannel_soundtransform_exists` | 5 | 23.3s |  |
| 644 | `soundchannel_stop` | 8 | 23.6s |  |
| 645 | `soundmixer_buffertime` | 5 | 4.8s |  |
| 646 | `soundmixer_stopall` | 6 | 23.8s |  |
| 647 | `soundtransform` | 442 | 10.1s |  |
| 648 | `sprite_with_frames` | 0 | 24.3s |  |
| 649 | `stage3d_agal_cross_product` | 0 | 7.1s |  |
| 650 | `stage3d_bitmap` | 0 | 28.3s |  |
| 651 | `stage3d_float1_index` | 0 | 26.1s |  |
| 652 | `stage3d_fractal` | 0 | 7.3s |  |
| 653 | `stage3d_ignore_sampler_override` | 0 | 26.4s |  |
| 654 | `stage3d_program_constants_bytearray_be` | 0 | 26.8s |  |
| 655 | `stage3d_program_constants_bytearray_le` | 0 | 7.8s |  |
| 656 | `stage3d_raytrace` | 0 | 30.1s |  |
| 657 | `stage3d_rotating_cube` | 0 | 8.4s |  |
| 658 | `stage3d_sampler` | 0 | 7.4s |  |
| 659 | `stage3d_sampler_partial_upload` | 0 | 7.3s |  |
| 660 | `stage3d_stencil` | 0 | 26.8s |  |
| 661 | `stage3d_texture` | 0 | 12.4s |  |
| 662 | `stage3d_texture_bytearray` | 0 | 8.5s |  |
| 663 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.0s |  |
| 664 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.3s |  |
| 665 | `stage3d_triangle` | 0 | 7.5s |  |
| 666 | `stage3d_triangle_bytes4` | 0 | 7.4s |  |
| 667 | `stage3d_triangle_float1` | 0 | 7.3s |  |
| 668 | `stage3d_triangle_index_upload` | 0 | 7.5s |  |
| 669 | `stage_access` | 10 | 4.9s |  |
| 670 | `stage_displayobject_properties` | 24 | 4.7s |  |
| 671 | `stage_framerate_nan` | 7 | 4.9s |  |
| 672 | `stage_framerate_negative` | 6 | 4.8s |  |
| 673 | `stage_framerate_zero` | 6 | 4.8s |  |
| 674 | `stage_invalidate` | 38 | 4.9s |  |
| 675 | `stage_mousechildren` | 2 | 4.8s |  |
| 676 | `stage_mouseenabled` | 15 | 4.7s |  |
| 677 | `stage_overriden_setters` | 31 | 5.0s |  |
| 678 | `stage_properties` | 30 | 4.7s |  |
| 679 | `static_var_with_this_in_ctor` | 2 | 4.8s |  |
| 680 | `stored_properties` | 11 | 4.8s |  |
| 681 | `strict_equality` | 34 | 4.8s |  |
| 682 | `string_call` | 13 | 4.7s |  |
| 683 | `string_case` | 23 | 4.7s |  |
| 684 | `string_char_at` | 27 | 4.7s |  |
| 685 | `string_char_code_at` | 28 | 4.6s |  |
| 686 | `string_constr` | 25 | 3.9s |  |
| 687 | `string_indexof_lastindexof` | 87 | 4.1s |  |
| 688 | `string_length` | 16 | 3.9s |  |
| 689 | `string_locale_compare` | 39 | 4.1s |  |
| 690 | `string_match` | 51 | 4.0s |  |
| 691 | `string_relational_compare` | 4 | 3.9s |  |
| 692 | `string_replace` | 51 | 3.9s |  |
| 693 | `string_search` | 41 | 4.0s |  |
| 694 | `string_split` | 29 | 3.9s |  |
| 695 | `string_substr_negative` | 21 | 3.8s |  |
| 696 | `string_substr_weird` | 182 | 3.9s |  |
| 697 | `subtract` | 1058 | 13.5s |  |
| 698 | `super_get_call` | 12 | 4.0s |  |
| 699 | `supercall_two_classobjects` | 2 | 4.0s |  |
| 700 | `swf8` | 1 | 3.7s |  |
| 701 | `swf_10_queued_goto_scripts_construct` | 52 | 20.8s |  |
| 702 | `swf_9_goto_in_enter_frame` | 17 | 3.9s |  |
| 703 | `swf_9_goto_in_enter_frame_simple` | 15 | 3.9s |  |
| 704 | `swf_9_queued_goto_scripts` | 6 | 20.5s |  |
| 705 | `swf_9_queued_goto_scripts_construct` | 28 | 0.4s |  |
| 706 | `swf_9_versioning` | 2 | 3.8s |  |
| 707 | `swf_wrong_frame_count` | 38 | 4.1s |  |
| 708 | `swf_wrong_frame_count_isplaying` | 22 | 3.9s |  |
| 709 | `symbol_class_binary_data` | 8 | 4.0s |  |
| 710 | `symbol_class_conflict` | 4 | 4.1s |  |
| 711 | `symbol_class_root_not_zero` | 1 | 3.9s |  |
| 712 | `symbolclass_invalid_utf8` | 2 | 4.0s |  |
| 713 | `tab_ordering_automatic_advanced` | 184 | 5.4s |  |
| 714 | `tab_ordering_automatic_basic` | 45 | 5.0s |  |
| 715 | `tab_ordering_children` | 116 | 5.0s |  |
| 716 | `tab_ordering_custom_basic` | 34 | 4.9s |  |
| 717 | `text_engine_fontdescription` | 27 | 5.1s |  |
| 718 | `text_run` | 7 | 4.8s |  |
| 719 | `textfield_focusin_event` | 9 | 4.9s |  |
| 720 | `textfield_input_dead_keys_windows` | 15 | 4.9s |  |
| 721 | `textfield_unload` | 39 | 24.3s |  |
| 722 | `textformat` | 1134 | 4.8s |  |
| 723 | `textformat_display` | 14 | 4.7s |  |
| 724 | `textformat_font_max_length` | 4 | 4.6s |  |
| 725 | `throw` | 3 | 4.6s |  |
| 726 | `timeline_scripts` | 3 | 4.8s |  |
| 727 | `timer` | 90 | 5.3s |  |
| 728 | `timer_events` | 3 | 4.9s |  |
| 729 | `timer_finished` | 11 | 5.1s |  |
| 730 | `timer_reset` | 8 | 4.9s |  |
| 731 | `timer_setdelay` | 5 | 4.7s |  |
| 732 | `trace` | 12 | 4.7s |  |
| 733 | `truthiness` | 30 | 4.5s |  |
| 734 | `try_catch` | 11 | 4.6s |  |
| 735 | `try_catch_typed` | 12 | 4.5s |  |
| 736 | `typeof` | 30 | 4.5s |  |
| 737 | `uint_constr` | 92 | 4.7s |  |
| 738 | `uint_tofixed` | 1215 | 4.3s |  |
| 739 | `uint_tostring` | 3375 | 4.8s |  |
| 740 | `unchecked_function` | 15 | 4.5s |  |
| 741 | `urlrequest` | 18 | 4.5s |  |
| 742 | `urshift` | 1058 | 16.2s |  |
| 743 | `vector_class` | 36 | 4.9s |  |
| 744 | `vector_class_call` | 11 | 4.7s |  |
| 745 | `vector_coercion` | 66 | 5.2s |  |
| 746 | `vector_concat` | 90 | 5.0s |  |
| 747 | `vector_constr` | 107 | 5.1s |  |
| 748 | `vector_enumeration` | 5 | 4.4s |  |
| 749 | `vector_every` | 92 | 5.2s |  |
| 750 | `vector_filter` | 95 | 5.3s |  |
| 751 | `vector_holes` | 24 | 4.5s |  |
| 752 | `vector_indexof` | 302 | 9.2s |  |
| 753 | `vector_insertat` | 270 | 5.6s |  |
| 754 | `vector_int_access` | 4 | 4.4s |  |
| 755 | `vector_int_delete` | 11 | 4.5s |  |
| 756 | `vector_join` | 58 | 4.9s |  |
| 757 | `vector_lastindexof` | 302 | 4.4s |  |
| 758 | `vector_legacy` | 10 | 4.4s |  |
| 759 | `vector_map` | 85 | 5.1s |  |
| 760 | `vector_object_final` | 1 | 4.0s |  |
| 761 | `vector_object_toString` | 10 | 4.1s |  |
| 762 | `vector_pushpop` | 255 | 5.3s |  |
| 763 | `vector_reborrow_bug` | 10 | 4.2s |  |
| 764 | `vector_removeat` | 172 | 5.3s |  |
| 765 | `vector_reverse` | 232 | 5.3s |  |
| 766 | `vector_shiftunshift` | 252 | 5.4s |  |
| 767 | `vector_slice` | 331 | 5.9s |  |
| 768 | `vector_sort` | 905 | 13.7s |  |
| 769 | `vector_splice` | 693 | 8.2s |  |
| 770 | `vector_splice_fixed_bug_compat` | 4 | 4.2s |  |
| 771 | `vector_tostring` | 79 | 4.8s |  |
| 772 | `verify_abnormal_loop` | 1 | 4.2s |  |
| 773 | `verify_exception_targets_edge_case` | 1 | 4.2s |  |
| 774 | `verify_lookup_switch_edge_case` | 1 | 4.2s |  |
| 775 | `verify_unreachable_exception` | 2 | 4.2s |  |
| 776 | `versioned_isplaying` | 2 | 4.2s |  |
| 777 | `virtual_properties` | 16 | 4.2s |  |
| 778 | `with` | 4 | 4.2s |  |
| 779 | `xml_abstract_equality` | 36 | 4.4s |  |
| 780 | `xml_advanced` | 52 | 4.2s |  |
| 781 | `xml_appendchild` | 10 | 4.2s |  |
| 782 | `xml_as_attribute` | 9 | 4.2s |  |
| 783 | `xml_attribute` | 35 | 4.3s |  |
| 784 | `xml_attribute_name` | 40 | 4.2s |  |
| 785 | `xml_child` | 25 | 4.2s |  |
| 786 | `xml_childindex` | 7 | 4.2s |  |
| 787 | `xml_children` | 43 | 4.7s |  |
| 788 | `xml_class_call` | 9 | 4.2s |  |
| 789 | `xml_contains` | 197 | 4.4s |  |
| 790 | `xml_copy` | 20 | 4.4s |  |
| 791 | `xml_ctor_from_tostring` | 23 | 4.5s |  |
| 792 | `xml_delete` | 114 | 4.3s |  |
| 793 | `xml_descendants` | 83 | 4.3s |  |
| 794 | `xml_elements` | 6 | 4.2s |  |
| 795 | `xml_equals_namespace_check` | 2 | 4.2s |  |
| 796 | `xml_explicit_use_namespace` | 5 | 22.5s |  |
| 797 | `xml_getdescendants_qname` | 21 | 4.2s |  |
| 798 | `xml_has_property_via_in` | 26 | 4.3s |  |
| 799 | `xml_hasownproperty` | 6 | 4.2s |  |
| 800 | `xml_ignore_white` | 6 | 4.2s |  |
| 801 | `xml_length` | 2 | 4.3s |  |
| 802 | `xml_list_as_attribute` | 9 | 4.2s |  |
| 803 | `xml_list_concat` | 20 | 4.3s |  |
| 804 | `xml_list_enumerate` | 4 | 4.1s |  |
| 805 | `xml_methods_settings` | 3 | 4.1s |  |
| 806 | `xml_mismatched_tag` | 37 | 4.3s |  |
| 807 | `xml_namespace` | 39 | 4.2s |  |
| 808 | `xml_namespace_methods` | 245 | 4.3s |  |
| 809 | `xml_namespaced_property` | 7 | 4.1s |  |
| 810 | `xml_no_namespace` | 1 | 4.1s |  |
| 811 | `xml_nodekind` | 3 | 4.1s |  |
| 812 | `xml_normalize` | 35 | 4.2s |  |
| 813 | `xml_notification_bubbling` | 361 | 4.1s |  |
| 814 | `xml_parent` | 8 | 4.1s |  |
| 815 | `xml_set_children` | 17 | 4.2s |  |
| 816 | `xml_set_name` | 34 | 4.1s |  |
| 817 | `xml_settings` | 6 | 1.5s |  |
| 818 | `xml_simple_complex_content` | 47 | 4.1s |  |
| 819 | `xml_text` | 7 | 4.1s |  |
| 820 | `xml_tostring` | 6 | 4.1s |  |
| 821 | `xml_tostring_namespace` | 12 | 4.1s |  |
| 822 | `xml_unescaping` | 23 | 4.2s |  |
| 823 | `xml_weird_ignores` | 54 | 4.2s |  |
| 824 | `xml_wildcard` | 11 | 4.2s |  |
| 825 | `xmldocument` | 254 | 4.2s |  |
| 826 | `xmlnode` | 3540 | 4.3s |  |
| 827 | `zero_frame_clip` | 3 | 4.3s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 4.5s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 4.5s |  |
| 3 | `blend_transform` | 1 | 1 | 5.1s |  |
| 4 | `coerce_property` | 3 | 3 | 5.1s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.1s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 16.0s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 4.8s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 4.6s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 4.9s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 4.6s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 4.7s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 4.2s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 22.5s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 24.0s |  |
| 15 | `int_toexponential` | 76 | 76 | 4.7s |  |
| 16 | `int_toprecision` | 441 | 441 | 4.7s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 4.9s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 4.5s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 22.6s |  |
| 20 | `soundchannel_position` | 74 | 74 | 24.9s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 5.1s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 4.8s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 20.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 4.6s |  |
| 25 | `uint_toprecision` | 433 | 433 | 4.7s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 4.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**73 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `string_slice_substr_substring` | 99.4% | 169 | 170 | 1 |  |
| 3 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 4 | `parse_float` | 98.8% | 80 | 81 | 1 |  |
| 5 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 6 | `focus_events_mouse_focusable` | 98.2% | 110 | 112 | 2 |  |
| 7 | `parse_int` | 97.8% | 132 | 135 | 3 |  |
| 8 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 9 | `string_concat_fromcharcode` | 97.3% | 36 | 37 | 1 |  |
| 10 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 11 | `xml_basic` | 97.0% | 32 | 33 | 1 |  |
| 12 | `parse_float_swf10` | 96.3% | 78 | 81 | 3 |  |
| 13 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 14 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 15 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 16 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 17 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 18 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 19 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 20 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 21 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 22 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 23 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 24 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 25 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 26 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 27 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 28 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 29 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 30 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 31 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 32 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 33 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 34 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 35 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 36 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 37 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 38 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 39 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 40 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 41 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 42 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 43 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 44 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 45 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 46 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 47 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 48 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 49 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 50 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 51 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 52 | `loaderinfo_loadurl` | 66.7% | 8 | 12 | 4 |  |
| 53 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 54 | `loaderinfo_properties_not_loaded` | 65.2% | 15 | 23 | 8 |  |
| 55 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 56 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 57 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 58 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 59 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 60 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 61 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 62 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 63 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 64 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 65 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 66 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 67 | `date` | 50.0% | 15 | 30 | 15 |  |
| 68 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 69 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 70 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 71 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 72 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 73 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 4.6s |  |
| 2 | `method_without_body` | exit code 1 | 22.3s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 4.6s |  |
| 4 | `verify_typecheck` | exit code 1 | 4.3s |  |

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
| 6 | `focus_events_mouse_focusable` | 98.2% | 110/112 | 112 | 112 |  |
| 7 | `parse_int` | 97.8% | 132/135 | 134 | 135 |  |
| 8 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 9 | `string_concat_fromcharcode` | 97.3% | 36/37 | 36 | 37 |  |
| 10 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 11 | `xml_basic` | 97.0% | 32/33 | 32 | 33 |  |
| 12 | `parse_float_swf10` | 96.3% | 78/81 | 80 | 81 |  |
| 13 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 14 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 15 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 16 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 17 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 18 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 19 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 20 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 21 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 22 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 23 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 24 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 25 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 26 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 27 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 28 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 29 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 30 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 31 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 32 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 33 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 34 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 35 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 36 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 37 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 38 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 39 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 40 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 41 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 42 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 43 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 44 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 45 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 46 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 47 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 48 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 49 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 50 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 51 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 52 | `loaderinfo_loadurl` | 66.7% | 8/12 | 12 | 12 |  |
| 53 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 54 | `loaderinfo_properties_not_loaded` | 65.2% | 15/23 | 23 | 23 |  |
| 55 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 56 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 57 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 58 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 59 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 60 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 61 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 62 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 63 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 64 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 65 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 66 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 67 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 68 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 69 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 70 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 71 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 72 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 73 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 74 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 75 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 76 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 77 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 78 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 79 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 80 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 81 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 82 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 83 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 84 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 85 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 86 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 87 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 88 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 89 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 90 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 91 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 92 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 93 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 94 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 95 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 96 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 97 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 98 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 99 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 100 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 101 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 102 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 103 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 104 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 105 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 106 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 107 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 108 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 109 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 110 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 111 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 112 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 113 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 114 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 115 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 116 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 117 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 118 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 119 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 120 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 121 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 122 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 123 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 124 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 125 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 126 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 127 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 128 | `loader_events` | 8.7% | 8/92 | 20 | 92 |  |
| 129 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 130 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 131 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 132 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 133 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 134 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 135 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 136 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 137 | `loader_loadbytes_events` | 6.7% | 2/30 | 7 | 30 |  |
| 138 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 139 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 140 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 141 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 142 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 143 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 144 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 145 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 146 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 147 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 148 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 149 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 150 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 151 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 152 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 153 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 154 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 155 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 156 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 157 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 158 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 159 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 160 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 161 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 162 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 163 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 164 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 165 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 166 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 167 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 168 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 169 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 170 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 171 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 172 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 173 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 174 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 175 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 176 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 177 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 178 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 179 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 180 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 181 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 182 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 183 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 184 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 185 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 186 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 187 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 188 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 189 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 190 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 191 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 192 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 193 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 194 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 195 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 196 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 197 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 198 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 199 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 200 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 201 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 202 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 203 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 204 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 205 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 206 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 207 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 208 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 209 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 210 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 211 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 212 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 213 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 214 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 215 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 216 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 217 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 218 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 219 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 220 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 221 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 222 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 223 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 224 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 225 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 226 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 227 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 228 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 229 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 230 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 231 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 232 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 233 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 234 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 235 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 236 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 237 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 238 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 239 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 240 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 241 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 242 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 243 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 244 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 245 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 246 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 247 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 248 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 249 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 250 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 251 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 252 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 253 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 254 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 255 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 256 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 257 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 258 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 259 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 260 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 261 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 262 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 263 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 264 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 265 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 266 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 267 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 268 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 269 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 270 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
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
