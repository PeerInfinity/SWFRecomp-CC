# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-24 18:21 UTC

**Git SHA**: `74a28f304a`

**Run Duration**: 165m 20s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1217 |
| Passing | **829** (68.1%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **855** (70.3%) |
| Failing | 362 |
| Total expected lines | 151097 |
| Matching lines | 103614 (68.6%) |
| Mismatched lines | 47483 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 357 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**829 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 0.9s |  |
| 2 | `agal_compiler` | 13 | 0.9s |  |
| 3 | `air_hidden_lookup` | 2 | 0.9s |  |
| 4 | `all_classes/security/swf11` | 3 | 0.8s |  |
| 5 | `amf_custom_obj` | 26 | 0.9s |  |
| 6 | `amf_dictionary` | 9 | 0.8s |  |
| 7 | `amf_function` | 46 | 0.9s |  |
| 8 | `amf_invalid_date` | 2 | 0.8s |  |
| 9 | `amf_missing_prop` | 6 | 0.9s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 5.4s |  |
| 11 | `amf_setter_error` | 8 | 5.5s |  |
| 12 | `amf_vector` | 40 | 5.5s |  |
| 13 | `amf_xml` | 6 | 5.4s |  |
| 14 | `application_domain` | 4 | 5.4s |  |
| 15 | `array_access` | 18 | 5.4s |  |
| 16 | `array_access_interpreter` | 4 | 5.4s |  |
| 17 | `array_access_no_pubns` | 2 | 5.4s |  |
| 18 | `array_concat` | 41 | 5.5s |  |
| 19 | `array_constr` | 10 | 5.4s |  |
| 20 | `array_delete` | 44 | 5.5s |  |
| 21 | `array_enumeration` | 10 | 5.4s |  |
| 22 | `array_enumeration_elements` | 11 | 5.4s |  |
| 23 | `array_every` | 8 | 5.4s |  |
| 24 | `array_filter` | 6 | 5.4s |  |
| 25 | `array_foreach` | 18 | 5.4s |  |
| 26 | `array_hasownproperty` | 11 | 2.5s |  |
| 27 | `array_holes` | 9 | 5.4s |  |
| 28 | `array_index_max` | 84 | 5.3s |  |
| 29 | `array_indexof` | 25 | 5.4s |  |
| 30 | `array_join` | 26 | 5.5s |  |
| 31 | `array_lastindexof` | 29 | 5.4s |  |
| 32 | `array_length` | 14 | 5.4s |  |
| 33 | `array_literal` | 3 | 5.4s |  |
| 34 | `array_map` | 8 | 5.3s |  |
| 35 | `array_pop` | 52 | 5.5s |  |
| 36 | `array_push` | 24 | 5.4s |  |
| 37 | `array_reborrow_bug` | 6 | 5.4s |  |
| 38 | `array_reverse` | 28 | 5.4s |  |
| 39 | `array_shift` | 51 | 2.6s |  |
| 40 | `array_slice` | 39 | 5.5s |  |
| 41 | `array_some` | 8 | 5.5s |  |
| 42 | `array_sort` | 297 | 5.9s |  |
| 43 | `array_sort_fun_swf12` | 2 | 5.4s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 45 | `array_sort_random` | 210 | 5.5s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 5.4s |  |
| 47 | `array_sorton` | 545 | 6.6s |  |
| 48 | `array_sparse_ops` | 41 | 5.9s |  |
| 49 | `array_splice` | 133 | 6.0s |  |
| 50 | `array_splice2` | 428 | 6.1s |  |
| 51 | `array_splice_types` | 48 | 5.8s |  |
| 52 | `array_storage` | 8 | 5.7s |  |
| 53 | `array_tolocalestring` | 9 | 5.7s |  |
| 54 | `array_tostring` | 12 | 5.8s |  |
| 55 | `array_unshift` | 24 | 5.7s |  |
| 56 | `array_valueof` | 9 | 5.6s |  |
| 57 | `array_vector_null_callback` | 10 | 5.7s |  |
| 58 | `astype` | 28 | 5.7s |  |
| 59 | `astypelate` | 24 | 5.8s |  |
| 60 | `astypelate_propagates` | 1 | 5.6s |  |
| 61 | `asymmetric_key_events` | 11 | 5.8s |  |
| 62 | `avm2_catchup_dobj` | 158 | 6.3s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 82.3s |  |
| 64 | `bitand` | 1058 | 17.9s |  |
| 65 | `bitmap_constr` | 17 | 6.3s |  |
| 66 | `bitmap_data` | 1000 | 14.3s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 26.7s |  |
| 68 | `bitmap_properties` | 23 | 6.1s |  |
| 69 | `bitmap_subclass` | 7 | 6.3s |  |
| 70 | `bitmap_subclass_properties` | 9 | 6.5s |  |
| 71 | `bitmap_timeline` | 9 | 6.0s |  |
| 72 | `bitmapdata_accuracy` | 1 | 49.4s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 25.8s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.8s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 25.6s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.6s |  |
| 77 | `bitmapdata_clone` | 13 | 6.1s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.4s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 5.8s |  |
| 80 | `bitmapdata_constr` | 22 | 5.9s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 6.0s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.2s |  |
| 83 | `bitmapdata_copypixels` | 23 | 26.7s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.7s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.7s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.7s |  |
| 87 | `bitmapdata_draw` | 0 | 25.4s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.1s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.4s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 25.0s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 5.9s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.2s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.0s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 24.6s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 5.9s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.0s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.0s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 25.4s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.6s |  |
| 100 | `bitmapdata_getpixels` | 39 | 24.6s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.9s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 103 | `bitmapdata_hittest` | 112 | 6.3s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.6s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.0s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 24.9s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.2s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.6s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.8s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.9s |  |
| 111 | `bitmapdata_sync` | 0 | 5.8s |  |
| 112 | `bitmapdata_threshold` | 176 | 6.4s |  |
| 113 | `bitnot` | 46 | 5.7s |  |
| 114 | `bitor` | 1058 | 17.8s |  |
| 115 | `bitxor` | 1058 | 18.1s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.0s |  |
| 117 | `blend_scroll` | 0 | 6.0s |  |
| 118 | `boolean_constr` | 32 | 5.8s |  |
| 119 | `boolean_negation` | 30 | 5.8s |  |
| 120 | `boolean_tostring` | 8 | 5.7s |  |
| 121 | `broadcast_event` | 7 | 5.5s |  |
| 122 | `button_nested_frame` | 48 | 24.8s |  |
| 123 | `bytearray` | 48 | 5.9s |  |
| 124 | `bytearray_compress` | 31 | 5.7s |  |
| 125 | `bytearray_errors` | 24 | 5.8s |  |
| 126 | `bytearray_method_serialization` | 1 | 2.7s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 6.0s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 6.0s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 130 | `bytearray_serialization` | 3 | 5.7s |  |
| 131 | `bytearray_string_null` | 19 | 6.3s |  |
| 132 | `bytearray_tostring` | 15 | 6.0s |  |
| 133 | `bytearray_utf16` | 8 | 5.9s |  |
| 134 | `bytearray_writeobject` | 24 | 5.8s |  |
| 135 | `callee_in_initializer` | 6 | 5.8s |  |
| 136 | `callproplex_class` | 1 | 5.9s |  |
| 137 | `catch_class` | 6 | 5.9s |  |
| 138 | `catch_scope_slot` | 7 | 3.0s |  |
| 139 | `checkfilter` | 4 | 2.9s |  |
| 140 | `class_call` | 32 | 26.2s |  |
| 141 | `class_cast_call` | 14 | 6.0s |  |
| 142 | `class_enumeration` | 4 | 5.9s |  |
| 143 | `class_has_own_property` | 2 | 5.7s |  |
| 144 | `class_init_interpreter_mode` | 1 | 5.7s |  |
| 145 | `class_is` | 32 | 5.8s |  |
| 146 | `class_methods` | 5 | 5.6s |  |
| 147 | `class_object_properties` | 10 | 5.7s |  |
| 148 | `class_singleton` | 18 | 5.7s |  |
| 149 | `class_supercalls_errors` | 35 | 5.9s |  |
| 150 | `class_supercalls_mismatched` | 26 | 6.1s |  |
| 151 | `class_superclass_wrong_order` | 1 | 23.1s |  |
| 152 | `class_to_locale_string` | 2 | 5.4s |  |
| 153 | `class_to_string` | 2 | 5.3s |  |
| 154 | `class_value_of` | 2 | 5.4s |  |
| 155 | `click_block` | 5 | 23.6s |  |
| 156 | `click_invisible` | 3 | 5.7s |  |
| 157 | `closures` | 12 | 5.5s |  |
| 158 | `coerce_return_type` | 40 | 5.7s |  |
| 159 | `coerce_return_type_fail` | 2 | 5.5s |  |
| 160 | `coerce_return_void` | 3 | 5.4s |  |
| 161 | `coerce_string` | 86 | 5.7s |  |
| 162 | `coerce_string_precision` | 28 | 5.5s |  |
| 163 | `coerce_to_primitive_side_effects` | 29 | 5.7s |  |
| 164 | `construct_errors_swf10` | 8 | 5.5s |  |
| 165 | `construct_frame_list` | 22 | 23.8s |  |
| 166 | `constructor_call` | 3 | 5.4s |  |
| 167 | `constructors_vs_timeline` | 5 | 23.8s |  |
| 168 | `constructprop_dynamic_primitive` | 7 | 5.5s |  |
| 169 | `control_flow_bool` | 4 | 5.6s |  |
| 170 | `control_flow_stricteq` | 8 | 5.6s |  |
| 171 | `convert_boolean` | 30 | 5.6s |  |
| 172 | `convert_integer` | 90 | 5.8s |  |
| 173 | `convert_number` | 56 | 5.6s |  |
| 174 | `convert_uinteger` | 90 | 5.7s |  |
| 175 | `cryptscore` | 11 | 5.7s |  |
| 176 | `declocal` | 46 | 5.5s |  |
| 177 | `declocal_i` | 46 | 5.5s |  |
| 178 | `decrement` | 46 | 5.5s |  |
| 179 | `decrement_i` | 46 | 2.7s |  |
| 180 | `default_values` | 7 | 5.6s |  |
| 181 | `dictionary_access` | 62 | 5.7s |  |
| 182 | `dictionary_access_no_pubns` | 2 | 5.4s |  |
| 183 | `dictionary_delete` | 101 | 6.0s |  |
| 184 | `dictionary_foreach` | 42 | 5.8s |  |
| 185 | `dictionary_hasownproperty` | 63 | 5.8s |  |
| 186 | `dictionary_in` | 62 | 5.7s |  |
| 187 | `dictionary_iter_modify` | 8 | 5.5s |  |
| 188 | `dictionary_namespaces` | 36 | 5.6s |  |
| 189 | `dictionary_primitive_keys` | 29 | 5.5s |  |
| 190 | `displayobject_alpha` | 277 | 5.4s |  |
| 191 | `displayobject_blendmode` | 0 | 5.7s |  |
| 192 | `displayobject_colortransform_nested` | 0 | 24.0s |  |
| 193 | `displayobject_from_enterframe` | 1 | 23.8s |  |
| 194 | `displayobject_getbounds_shape` | 0 | 23.9s |  |
| 195 | `displayobject_height` | 6052 | 23.6s |  |
| 196 | `displayobject_hittestobject` | 32 | 5.6s |  |
| 197 | `displayobject_invalid_floats` | 60 | 5.5s |  |
| 198 | `displayobject_invalid_props` | 3 | 5.5s |  |
| 199 | `displayobject_mask` | 3 | 5.9s |  |
| 200 | `displayobject_mask_self_referential` | 0 | 5.5s |  |
| 201 | `displayobject_metaData` | 3 | 5.5s |  |
| 202 | `displayobject_name` | 22 | 24.1s |  |
| 203 | `displayobject_name_from_timeline` | 24 | 5.7s |  |
| 204 | `displayobject_parent` | 12 | 5.5s |  |
| 205 | `displayobject_root` | 24 | 5.5s |  |
| 206 | `displayobject_rotation` | 1284 | 5.6s |  |
| 207 | `displayobject_set_matrix_nested` | 0 | 24.2s |  |
| 208 | `displayobject_subclass` | 2 | 5.5s |  |
| 209 | `displayobject_visible` | 23 | 5.5s |  |
| 210 | `displayobject_width` | 4852 | 23.9s |  |
| 211 | `displayobject_x` | 614 | 5.5s |  |
| 212 | `displayobject_y` | 617 | 5.5s |  |
| 213 | `displayobjectcontainer_addchild` | 32 | 5.6s |  |
| 214 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.5s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.7s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.6s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.6s |  |
| 218 | `displayobjectcontainer_addchildat` | 42 | 5.5s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.6s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.6s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 2.7s |  |
| 222 | `displayobjectcontainer_contains` | 66 | 23.9s |  |
| 223 | `displayobjectcontainer_getchildat` | 4 | 5.5s |  |
| 224 | `displayobjectcontainer_getchildbyname` | 9 | 5.4s |  |
| 225 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.4s |  |
| 226 | `displayobjectcontainer_getchildindex` | 28 | 5.4s |  |
| 227 | `displayobjectcontainer_removechild` | 10 | 5.4s |  |
| 228 | `displayobjectcontainer_removechild_errors` | 4 | 5.4s |  |
| 229 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.5s |  |
| 230 | `displayobjectcontainer_removechildat` | 18 | 5.4s |  |
| 231 | `displayobjectcontainer_removechildren` | 51 | 5.7s |  |
| 232 | `displayobjectcontainer_setchildindex` | 42 | 5.3s |  |
| 233 | `displayobjectcontainer_stopallmovieclips` | 2 | 23.7s |  |
| 234 | `displayobjectcontainer_swapchildren` | 42 | 5.5s |  |
| 235 | `displayobjectcontainer_swapchildrenat` | 42 | 5.5s |  |
| 236 | `displayobjectcontainer_timelineinstance` | 48 | 23.6s |  |
| 237 | `divide` | 1058 | 17.0s |  |
| 238 | `doabc_is_eager` | 1 | 24.0s |  |
| 239 | `documentclass` | 9 | 5.8s |  |
| 240 | `drag_drop` | 10 | 5.9s |  |
| 241 | `duplicate_defs` | 1 | 5.6s |  |
| 242 | `eager_init` | 1 | 5.7s |  |
| 243 | `edit_text_linkage` | 7 | 5.9s |  |
| 244 | `edittext_align` | 60 | 6.2s |  |
| 245 | `edittext_always_show_selection` | 0 | 24.7s |  |
| 246 | `edittext_antialiastype` | 296 | 5.9s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 7.0s |  |
| 248 | `edittext_autosize` | 39 | 6.0s |  |
| 249 | `edittext_autosize_align` | 0 | 24.9s |  |
| 250 | `edittext_autosize_height_dynamic` | 60 | 24.8s |  |
| 251 | `edittext_autosize_height_input` | 60 | 5.9s |  |
| 252 | `edittext_autosize_lazy_bounds_events` | 65 | 6.0s |  |
| 253 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.8s |  |
| 254 | `edittext_autosize_lazy_bounds_props` | 490 | 7.2s |  |
| 255 | `edittext_autosize_lazy_bounds_visual` | 0 | 24.6s |  |
| 256 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.9s |  |
| 257 | `edittext_bottom_scroll_v_basic` | 210 | 5.8s |  |
| 258 | `edittext_bounds_scale` | 24 | 24.1s |  |
| 259 | `edittext_bullet` | 30 | 5.8s |  |
| 260 | `edittext_default_format` | 221 | 6.0s |  |
| 261 | `edittext_default_format_empty` | 136 | 6.0s |  |
| 262 | `edittext_empty_text_format` | 7 | 5.8s |  |
| 263 | `edittext_focus_selection` | 5 | 5.7s |  |
| 264 | `edittext_font_size` | 45 | 5.8s |  |
| 265 | `edittext_format_empty_font` | 8 | 5.7s |  |
| 266 | `edittext_get_char_index_at_point` | 4 | 24.8s |  |
| 267 | `edittext_get_line_index_at_point` | 2 | 24.8s |  |
| 268 | `edittext_get_line_index_of_char` | 76 | 6.7s |  |
| 269 | `edittext_getcharboundaries` | 172 | 6.1s |  |
| 270 | `edittext_getcharboundaries_missing_glyphs` | 63 | 24.9s |  |
| 271 | `edittext_getcharboundaries_scroll` | 85 | 5.8s |  |
| 272 | `edittext_getlinemetrics` | 146 | 5.7s |  |
| 273 | `edittext_html` | 3101 | 6.0s |  |
| 274 | `edittext_html_condensewhite` | 487 | 5.5s |  |
| 275 | `edittext_html_entity` | 4 | 5.7s |  |
| 276 | `edittext_html_font_size_swf12` | 267 | 5.6s |  |
| 277 | `edittext_html_font_size_swf13` | 273 | 5.3s |  |
| 278 | `edittext_html_roundtrip` | 17 | 5.6s |  |
| 279 | `edittext_input_control` | 12 | 5.8s |  |
| 280 | `edittext_leading` | 9 | 5.9s |  |
| 281 | `edittext_letter_spacing` | 15 | 5.7s |  |
| 282 | `edittext_line_methods` | 294 | 6.5s |  |
| 283 | `edittext_line_metrics` | 11 | 27.7s |  |
| 284 | `edittext_margins` | 25 | 5.8s |  |
| 285 | `edittext_max_scroll_h_basic` | 475 | 5.9s |  |
| 286 | `edittext_max_scroll_v_basic` | 1000 | 5.6s |  |
| 287 | `edittext_mousedown` | 3 | 6.0s |  |
| 288 | `edittext_mouseenabled` | 26 | 5.6s |  |
| 289 | `edittext_newline_character` | 22 | 5.6s |  |
| 290 | `edittext_newline_stripping` | 64 | 8.0s |  |
| 291 | `edittext_newlines` | 30 | 5.6s |  |
| 292 | `edittext_paragraph_methods` | 257 | 5.5s |  |
| 293 | `edittext_paste_events` | 8 | 5.8s |  |
| 294 | `edittext_paste_maxchars` | 4 | 5.7s |  |
| 295 | `edittext_paste_restrict` | 16 | 5.6s |  |
| 296 | `edittext_restrict` | 191 | 5.7s |  |
| 297 | `edittext_restrict_events` | 22 | 5.6s |  |
| 298 | `edittext_scrollh` | 10 | 5.7s |  |
| 299 | `edittext_selected_text` | 9 | 5.5s |  |
| 300 | `edittext_set_html_same` | 17 | 5.7s |  |
| 301 | `edittext_set_text_vs_html` | 9 | 5.8s |  |
| 302 | `edittext_stylesheet` | 536 | 6.1s |  |
| 303 | `edittext_stylesheet_custom_tag` | 76 | 5.8s |  |
| 304 | `edittext_stylesheet_display` | 272 | 5.8s |  |
| 305 | `edittext_underline` | 40 | 5.7s |  |
| 306 | `edittext_width_height` | 103 | 5.9s |  |
| 307 | `edittext_wordwrap_word` | 150 | 6.2s |  |
| 308 | `edittext_wrap_breaks` | 2375 | 6.2s |  |
| 309 | `empty_bounds` | 1 | 5.6s |  |
| 310 | `equals` | 512 | 9.9s |  |
| 311 | `error_prototype` | 15 | 5.6s |  |
| 312 | `error_stack_trace_debug_swf17` | 0 | 24.8s |  |
| 313 | `error_stack_trace_debug_swf18` | 0 | 5.5s |  |
| 314 | `error_stack_trace_release_swf17` | 0 | 5.5s |  |
| 315 | `error_stack_trace_release_swf18` | 0 | 5.5s |  |
| 316 | `error_tostring` | 29 | 5.6s |  |
| 317 | `es3_inheritance` | 31 | 5.7s |  |
| 318 | `es4_inheritance` | 30 | 5.7s |  |
| 319 | `es4_interfaces` | 30 | 5.8s |  |
| 320 | `es4_method_binding` | 8 | 5.7s |  |
| 321 | `es4_oop_prototypes` | 14 | 5.9s |  |
| 322 | `es4_protected_inheritance` | 6 | 5.7s |  |
| 323 | `event_bubbles` | 2 | 5.7s |  |
| 324 | `event_cancelable` | 2 | 5.7s |  |
| 325 | `event_clone` | 20 | 5.8s |  |
| 326 | `event_clone_error_redispatch` | 3 | 5.9s |  |
| 327 | `event_clone_on_redispatch` | 10 | 5.9s |  |
| 328 | `event_formattostring` | 31 | 5.7s |  |
| 329 | `event_isdefaultprevented` | 12 | 5.7s |  |
| 330 | `event_target_getter` | 5 | 2.8s |  |
| 331 | `event_target_set` | 9 | 5.6s |  |
| 332 | `event_type` | 1 | 5.6s |  |
| 333 | `event_valueof_tostring` | 18 | 5.8s |  |
| 334 | `eventdispatcher_dispatchevent` | 12 | 5.7s |  |
| 335 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.7s |  |
| 336 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.8s |  |
| 337 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.8s |  |
| 338 | `eventdispatcher_dispatchevent_this` | 5 | 5.7s |  |
| 339 | `eventdispatcher_haseventlistener` | 25 | 5.7s |  |
| 340 | `eventdispatcher_interface_invoke` | 1 | 5.7s |  |
| 341 | `eventdispatcher_tostring` | 10 | 5.7s |  |
| 342 | `eventdispatcher_willtrigger` | 25 | 5.7s |  |
| 343 | `falsiness` | 30 | 5.8s |  |
| 344 | `fast_index_access` | 12 | 5.8s |  |
| 345 | `finddef` | 3 | 5.8s |  |
| 346 | `findprop_global_prototype` | 6 | 5.7s |  |
| 347 | `flash_xml` | 29 | 5.8s |  |
| 348 | `flash_xml_cloneNode` | 22 | 5.8s |  |
| 349 | `flash_xml_namespace` | 109 | 5.8s |  |
| 350 | `flash_xml_removeNode` | 60 | 5.8s |  |
| 351 | `focus_events_code` | 161 | 25.9s |  |
| 352 | `focus_events_key_same_object` | 26 | 5.8s |  |
| 353 | `focus_events_mixed_key_mouse` | 100 | 25.1s |  |
| 354 | `focus_events_mouse_same_object` | 40 | 24.5s |  |
| 355 | `focus_remove` | 20 | 24.4s |  |
| 356 | `focus_root_movie` | 4 | 24.5s |  |
| 357 | `focus_stage` | 1 | 5.8s |  |
| 358 | `focusrect` | 18 | 6.6s |  |
| 359 | `font_description_clone` | 14 | 5.8s |  |
| 360 | `font_embedded` | 24 | 6.1s |  |
| 361 | `font_enumeratefonts` | 41 | 6.3s |  |
| 362 | `font_enumeratefonts_filter` | 4 | 25.3s |  |
| 363 | `font_hasglyphs` | 40 | 6.2s |  |
| 364 | `framelabel_constr` | 5 | 5.8s |  |
| 365 | `function_call` | 12 | 5.8s |  |
| 366 | `function_call_arguments` | 46 | 5.9s |  |
| 367 | `function_call_arguments_enumerate` | 5 | 5.8s |  |
| 368 | `function_call_coercion` | 108 | 6.1s |  |
| 369 | `function_call_default` | 6 | 5.7s |  |
| 370 | `function_call_rest` | 22 | 5.8s |  |
| 371 | `function_call_types` | 3 | 5.7s |  |
| 372 | `function_call_via_apply` | 11 | 5.8s |  |
| 373 | `function_call_via_call` | 3 | 5.8s |  |
| 374 | `function_display_anonymous` | 7 | 2.9s |  |
| 375 | `function_length` | 6 | 5.8s |  |
| 376 | `function_object` | 2 | 5.7s |  |
| 377 | `function_proto` | 5 | 5.7s |  |
| 378 | `function_proto_created` | 61 | 5.7s |  |
| 379 | `function_to_locale_string` | 4 | 5.7s |  |
| 380 | `function_to_string` | 4 | 5.6s |  |
| 381 | `function_type` | 6 | 5.7s |  |
| 382 | `function_unbound_this` | 51 | 5.8s |  |
| 383 | `function_value_of` | 4 | 5.7s |  |
| 384 | `get_definition_by_name` | 11 | 5.7s |  |
| 385 | `get_qualified_class_name` | 20 | 5.7s |  |
| 386 | `get_qualified_super_class_name` | 18 | 5.4s |  |
| 387 | `get_slot_edge_cases` | 1 | 24.6s |  |
| 388 | `get_timer` | 2 | 5.5s |  |
| 389 | `getglobalslot` | 1 | 5.3s |  |
| 390 | `getouterscope` | 8 | 5.3s |  |
| 391 | `getter_different_namespace_setter` | 2 | 5.2s |  |
| 392 | `goto_button_nested_framescript` | 28 | 24.9s |  |
| 393 | `goto_in_constructframe` | 12 | 24.9s |  |
| 394 | `goto_in_scene_last_frame` | 2 | 24.6s |  |
| 395 | `goto_methods` | 56 | 5.4s |  |
| 396 | `goto_methods_swfver10` | 8 | 5.3s |  |
| 397 | `goto_nested_construct_sibling` | 18 | 5.6s |  |
| 398 | `goto_nested_framescript` | 9 | 5.5s |  |
| 399 | `goto_on_orphan` | 15 | 5.5s |  |
| 400 | `graphics_bad_direct_commands` | 5 | 5.7s |  |
| 401 | `graphics_bitmap_fill` | 0 | 5.8s |  |
| 402 | `graphics_bitmaps` | 0 | 6.0s |  |
| 403 | `graphics_direct_commands` | 0 | 5.8s |  |
| 404 | `graphics_draw_triangles` | 98 | 25.1s |  |
| 405 | `graphics_gradients` | 0 | 5.9s |  |
| 406 | `graphics_gradients_nulls` | 0 | 2.7s |  |
| 407 | `graphics_path` | 56 | 5.4s |  |
| 408 | `graphics_round_rects` | 0 | 5.4s |  |
| 409 | `graphics_simple_shapes` | 0 | 5.8s |  |
| 410 | `greaterequals` | 512 | 5.4s |  |
| 411 | `greaterthan` | 512 | 5.4s |  |
| 412 | `has_own_property` | 102 | 5.4s |  |
| 413 | `hasownproperty_namespaces` | 2 | 5.4s |  |
| 414 | `hello_world` | 1 | 5.5s |  |
| 415 | `hittest_morph` | 30 | 5.5s |  |
| 416 | `if_eq` | 10 | 5.4s |  |
| 417 | `if_gt` | 1 | 5.4s |  |
| 418 | `if_gte` | 10 | 2.4s |  |
| 419 | `if_lt` | 1 | 5.3s |  |
| 420 | `if_lte` | 10 | 5.6s |  |
| 421 | `if_ne` | 7 | 2.8s |  |
| 422 | `if_stricteq` | 6 | 5.6s |  |
| 423 | `if_strictne` | 11 | 5.5s |  |
| 424 | `in` | 102 | 6.0s |  |
| 425 | `inclocal` | 46 | 5.6s |  |
| 426 | `inclocal_i` | 46 | 5.7s |  |
| 427 | `increment` | 46 | 5.7s |  |
| 428 | `increment_i` | 46 | 5.7s |  |
| 429 | `instanceof` | 58 | 6.0s |  |
| 430 | `instantiation_on_enter_frame` | 7 | 24.8s |  |
| 431 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.7s |  |
| 432 | `int_constr` | 92 | 6.1s |  |
| 433 | `int_edge_cases` | 19 | 5.8s |  |
| 434 | `int_instanceof` | 3 | 5.7s |  |
| 435 | `int_tofixed` | 1215 | 5.6s |  |
| 436 | `int_tostring` | 3375 | 5.9s |  |
| 437 | `interactiveobject_enabled` | 25 | 5.7s |  |
| 438 | `interface_namespaces` | 78 | 6.0s |  |
| 439 | `is_finite` | 46 | 5.9s |  |
| 440 | `is_nan` | 46 | 5.7s |  |
| 441 | `is_prototype_of` | 12 | 5.7s |  |
| 442 | `issue_10221` | 2 | 5.7s |  |
| 443 | `issue_13780` | 12 | 5.7s |  |
| 444 | `issue_14901` | 1 | 5.7s |  |
| 445 | `issue_17675_edittext_paste_maxchars` | 1 | 5.8s |  |
| 446 | `issue_5292` | 5 | 5.7s |  |
| 447 | `issue_8630` | 2 | 24.8s |  |
| 448 | `issue_8630_scriptremove` | 11 | 5.7s |  |
| 449 | `istype` | 24 | 2.9s |  |
| 450 | `istypelate` | 58 | 5.9s |  |
| 451 | `istypelate_coerce` | 198 | 6.7s |  |
| 452 | `json_errors` | 9 | 23.8s |  |
| 453 | `json_parse` | 21 | 5.6s |  |
| 454 | `json_stringify` | 12 | 5.8s |  |
| 455 | `json_stringify_order` | 1 | 5.5s |  |
| 456 | `json_version_gated` | 1 | 5.5s |  |
| 457 | `key_input_80percent` | 1812 | 5.7s |  |
| 458 | `key_input_location` | 126 | 5.7s |  |
| 459 | `key_input_numpad` | 384 | 5.5s |  |
| 460 | `lazyinit` | 17 | 5.5s |  |
| 461 | `lessequals` | 512 | 9.6s |  |
| 462 | `lessthan` | 512 | 9.5s |  |
| 463 | `loaderinfo_properties` | 18 | 18.8s |  |
| 464 | `loaderinfo_root` | 10 | 4.4s |  |
| 465 | `loaderinfo_root_allows` | 2 | 4.4s |  |
| 466 | `lshift` | 1058 | 13.4s |  |
| 467 | `mask_reapply` | 1 | 19.4s |  |
| 468 | `math` | 497 | 4.8s |  |
| 469 | `missing_external_interface` | 10 | 4.4s |  |
| 470 | `modulo` | 1058 | 13.3s |  |
| 471 | `morph_shape` | 2 | 19.1s |  |
| 472 | `mouse_click_events` | 90 | 19.0s |  |
| 473 | `mouse_double_click_events` | 188 | 4.6s |  |
| 474 | `mouse_empty_parent` | 4 | 4.6s |  |
| 475 | `mouse_over_while_dragging` | 3 | 4.7s |  |
| 476 | `mouse_pick_button_mode` | 2 | 4.5s |  |
| 477 | `mouse_sibling` | 8 | 4.5s |  |
| 478 | `movieclip_addframescript` | 3 | 19.1s |  |
| 479 | `movieclip_child_property` | 16 | 4.6s |  |
| 480 | `movieclip_constr` | 21 | 4.5s |  |
| 481 | `movieclip_currentlabels` | 17 | 20.3s |  |
| 482 | `movieclip_currentlabels_dupes1` | 46 | 19.9s |  |
| 483 | `movieclip_currentlabels_dupes2` | 30 | 4.4s |  |
| 484 | `movieclip_currentlabels_dupes3` | 67 | 4.4s |  |
| 485 | `movieclip_currentscene` | 12 | 19.9s |  |
| 486 | `movieclip_dispatchevent` | 430 | 4.7s |  |
| 487 | `movieclip_dispatchevent_cancel` | 102 | 4.5s |  |
| 488 | `movieclip_dispatchevent_handlerorder` | 251 | 4.4s |  |
| 489 | `movieclip_dispatchevent_selfadd` | 80 | 4.3s |  |
| 490 | `movieclip_dispatchevent_target` | 899 | 4.4s |  |
| 491 | `movieclip_displayevents` | 96 | 20.5s |  |
| 492 | `movieclip_displayevents_clickgoto` | 676 | 21.6s |  |
| 493 | `movieclip_displayevents_clickgoto2` | 2001 | 5.0s |  |
| 494 | `movieclip_displayevents_clickplay` | 575 | 4.7s |  |
| 495 | `movieclip_displayevents_clicksymbol` | 562 | 4.6s |  |
| 496 | `movieclip_displayevents_constructframegoto` | 140 | 5.0s |  |
| 497 | `movieclip_displayevents_constructframeplay` | 50 | 4.7s |  |
| 498 | `movieclip_displayevents_constructframesymbol` | 144 | 4.7s |  |
| 499 | `movieclip_displayevents_dblhandler` | 21 | 4.7s |  |
| 500 | `movieclip_displayevents_enterframegoto` | 149 | 4.7s |  |
| 501 | `movieclip_displayevents_enterframeplay` | 48 | 4.5s |  |
| 502 | `movieclip_displayevents_enterframesymbol` | 149 | 20.6s |  |
| 503 | `movieclip_displayevents_exitframegoto` | 106 | 4.6s |  |
| 504 | `movieclip_displayevents_exitframeplay` | 44 | 4.7s |  |
| 505 | `movieclip_displayevents_exitframesymbol` | 135 | 4.6s |  |
| 506 | `movieclip_displayevents_looping` | 63 | 20.7s |  |
| 507 | `movieclip_displayevents_stopped` | 113 | 4.8s |  |
| 508 | `movieclip_displayevents_swap` | 96 | 1.9s |  |
| 509 | `movieclip_displayevents_timeline` | 128 | 20.6s |  |
| 510 | `movieclip_drawrect` | 54 | 4.5s |  |
| 511 | `movieclip_frameconstruct_skipped` | 9 | 4.5s |  |
| 512 | `movieclip_goto_during_frame_script` | 15 | 5.0s |  |
| 513 | `movieclip_goto_overwrite` | 14 | 20.9s |  |
| 514 | `movieclip_goto_scene_last_frame_int` | 1 | 20.4s |  |
| 515 | `movieclip_goto_scene_last_frame_label` | 1 | 4.4s |  |
| 516 | `movieclip_gotoandplay` | 15 | 20.3s |  |
| 517 | `movieclip_gotoandstop` | 13 | 4.8s |  |
| 518 | `movieclip_gotoandstop_children` | 4 | 4.7s |  |
| 519 | `movieclip_gotoandstop_framescripts1` | 4 | 4.5s |  |
| 520 | `movieclip_gotoandstop_framescripts2` | 4 | 1.9s |  |
| 521 | `movieclip_gotoandstop_framescripts_self` | 7 | 23.9s |  |
| 522 | `movieclip_gotoandstop_queueing` | 12 | 23.6s |  |
| 523 | `movieclip_next_frame` | 2 | 23.6s |  |
| 524 | `movieclip_next_scene` | 6 | 23.3s |  |
| 525 | `movieclip_play` | 3 | 5.4s |  |
| 526 | `movieclip_prev_frame` | 3 | 5.3s |  |
| 527 | `movieclip_prev_scene` | 7 | 5.5s |  |
| 528 | `movieclip_properties` | 79 | 23.9s |  |
| 529 | `movieclip_queued_noop_goto_swf10` | 9 | 5.5s |  |
| 530 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 531 | `movieclip_scenes` | 11 | 5.4s |  |
| 532 | `movieclip_soundtransform` | 831 | 25.7s |  |
| 533 | `movieclip_stop` | 1 | 23.4s |  |
| 534 | `movieclip_super_is_symbol` | 20 | 5.8s |  |
| 535 | `movieclip_symbol_constr` | 8 | 5.5s |  |
| 536 | `movieclip_text_mousedown` | 1 | 5.5s |  |
| 537 | `movieclip_willtrigger` | 5 | 5.6s |  |
| 538 | `multiply` | 1058 | 17.6s |  |
| 539 | `namespace_constr` | 253 | 5.8s |  |
| 540 | `namespace_constr_args` | 1 | 5.4s |  |
| 541 | `namespace_enumeration_order` | 7 | 5.5s |  |
| 542 | `nan_scale` | 9 | 5.4s |  |
| 543 | `negate` | 30 | 5.5s |  |
| 544 | `negative_volume_panned` | 0 | 5.7s |  |
| 545 | `nested_iteration` | 11 | 5.4s |  |
| 546 | `net_getClassByAlias` | 3 | 5.5s |  |
| 547 | `newactivation_in_script_init` | 3 | 4.9s |  |
| 548 | `newclass_twice` | 3 | 5.3s |  |
| 549 | `nonconflicting_declarations` | 0 | 5.1s |  |
| 550 | `null_void_types` | 8 | 4.9s |  |
| 551 | `number_autoconv` | 21 | 5.0s |  |
| 552 | `number_autoconv_amf` | 132 | 4.9s |  |
| 553 | `number_autoconv_array_sort_32bit` | 1 | 5.0s |  |
| 554 | `number_constr` | 58 | 5.2s |  |
| 555 | `number_toexponential` | 378 | 5.3s |  |
| 556 | `number_toexponential2` | 35 | 5.1s |  |
| 557 | `number_tofixed` | 378 | 5.1s |  |
| 558 | `number_toprecision` | 350 | 5.1s |  |
| 559 | `obfuscated_class_names` | 3 | 5.0s |  |
| 560 | `object_enumeration` | 10 | 5.1s |  |
| 561 | `object_prototype` | 4 | 5.1s |  |
| 562 | `object_to_locale_string` | 2 | 5.1s |  |
| 563 | `object_to_string` | 2 | 5.0s |  |
| 564 | `object_value_of` | 2 | 2.2s |  |
| 565 | `op_coerce` | 54 | 5.2s |  |
| 566 | `op_coerce_x` | 54 | 5.2s |  |
| 567 | `op_escxattr` | 2 | 5.1s |  |
| 568 | `op_escxelem` | 2 | 5.0s |  |
| 569 | `op_lookupswitch` | 4 | 5.2s |  |
| 570 | `optimize_coerce` | 1 | 4.9s |  |
| 571 | `orphan_movie_complex` | 80 | 5.4s |  |
| 572 | `orphan_movie_reorder` | 111 | 23.7s |  |
| 573 | `package_namespace` | 7 | 5.1s |  |
| 574 | `param_default_value_has_zero_cpool_index` | 1 | 5.1s |  |
| 575 | `parent_early_access_child` | 16 | 24.1s |  |
| 576 | `pixelbender_effect_BlurredFocus` | 0 | 27.4s |  |
| 577 | `pixelbender_effect_glassDisplace` | 0 | 11.2s |  |
| 578 | `pixelbender_effect_smudge` | 0 | 9.2s |  |
| 579 | `pixelbender_effect_tintype` | 0 | 8.4s |  |
| 580 | `pixelbender_effect_twirl` | 0 | 9.4s |  |
| 581 | `pixelbender_images` | 0 | 8.0s |  |
| 582 | `place_multiple` | 17 | 24.0s |  |
| 583 | `place_object_replace` | 9 | 6.2s |  |
| 584 | `place_object_replace_2` | 24 | 6.0s |  |
| 585 | `place_object_same_depth_frame` | 1 | 5.9s |  |
| 586 | `point` | 132 | 6.3s |  |
| 587 | `primitive_edge_cases` | 1 | 5.6s |  |
| 588 | `property_priority` | 22 | 5.5s |  |
| 589 | `property_priority_three_level` | 6 | 23.3s |  |
| 590 | `propertyisenumerable_namespaces` | 6 | 5.2s |  |
| 591 | `prototype_set_null` | 7 | 5.1s |  |
| 592 | `proxy_callproperty` | 24 | 5.1s |  |
| 593 | `proxy_deleteproperty` | 64 | 5.2s |  |
| 594 | `proxy_enumeration` | 34 | 5.2s |  |
| 595 | `proxy_getproperty` | 77 | 5.2s |  |
| 596 | `proxy_hasownproperty` | 8 | 5.2s |  |
| 597 | `proxy_hasproperty` | 32 | 5.2s |  |
| 598 | `proxy_serialize` | 9 | 5.2s |  |
| 599 | `proxy_setproperty` | 42 | 5.2s |  |
| 600 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.1s |  |
| 601 | `qname_constr` | 32 | 5.3s |  |
| 602 | `qname_constr_namespace` | 24 | 5.2s |  |
| 603 | `qname_enumeration` | 9 | 5.2s |  |
| 604 | `qname_indexing` | 23 | 5.2s |  |
| 605 | `qname_tostring` | 25 | 5.1s |  |
| 606 | `qname_valueof` | 29 | 5.2s |  |
| 607 | `regexp_constr` | 148 | 5.5s |  |
| 608 | `regexp_exec` | 19 | 5.2s |  |
| 609 | `regexp_extended` | 47 | 5.2s |  |
| 610 | `regexp_multiargs` | 1 | 5.2s |  |
| 611 | `regexp_test` | 27 | 5.5s |  |
| 612 | `regexp_toString` | 10 | 5.3s |  |
| 613 | `register_script_refresh` | 35 | 24.0s |  |
| 614 | `remove_child_clear_field` | 88 | 24.3s |  |
| 615 | `remove_dobj` | 3 | 5.2s |  |
| 616 | `resolve_order` | 4 | 5.2s |  |
| 617 | `rng` | 1 | 6.2s |  |
| 618 | `rootless` | 42 | 5.3s |  |
| 619 | `rshift` | 1058 | 18.1s |  |
| 620 | `sandbox_type_local_file` | 1 | 5.6s |  |
| 621 | `scene_constr` | 8 | 5.8s |  |
| 622 | `set_local_0` | 31 | 5.6s |  |
| 623 | `set_property_is_enumerable` | 85 | 6.0s |  |
| 624 | `shape_drawrect` | 54 | 5.6s |  |
| 625 | `shared_object_no_root` | 3 | 5.5s |  |
| 626 | `simplebutton_added_to_stage` | 45 | 24.0s |  |
| 627 | `simplebutton_childevents` | 86 | 24.4s |  |
| 628 | `simplebutton_childevents_nested` | 54 | 6.0s |  |
| 629 | `simplebutton_childevents_sprite` | 13 | 5.8s |  |
| 630 | `simplebutton_childprops` | 144 | 5.9s |  |
| 631 | `simplebutton_childshuffle` | 23 | 5.6s |  |
| 632 | `simplebutton_constr` | 36 | 5.8s |  |
| 633 | `simplebutton_constr_childevents` | 48 | 5.9s |  |
| 634 | `simplebutton_constr_params` | 42 | 5.7s |  |
| 635 | `simplebutton_mouseenabled` | 26 | 5.8s |  |
| 636 | `simplebutton_multi_children` | 19 | 6.0s |  |
| 637 | `simplebutton_structure` | 27 | 6.0s |  |
| 638 | `simplebutton_symbolclass` | 68 | 6.2s |  |
| 639 | `slot_disp_id_shared_numbering` | 1 | 24.6s |  |
| 640 | `slots_force_autoassigned` | 1 | 5.8s |  |
| 641 | `sound_embeddedprops` | 26 | 5.9s |  |
| 642 | `sound_play` | 19 | 5.9s |  |
| 643 | `sound_valueof` | 33 | 5.8s |  |
| 644 | `soundchannel_soundtransform` | 835 | 26.2s |  |
| 645 | `soundchannel_soundtransform_exists` | 5 | 24.4s |  |
| 646 | `soundchannel_stop` | 8 | 24.4s |  |
| 647 | `soundmixer_buffertime` | 5 | 5.7s |  |
| 648 | `soundmixer_stopall` | 6 | 25.0s |  |
| 649 | `soundtransform` | 442 | 11.2s |  |
| 650 | `sprite_with_frames` | 0 | 26.7s |  |
| 651 | `stage3d_agal_cross_product` | 0 | 8.8s |  |
| 652 | `stage3d_bitmap` | 0 | 29.6s |  |
| 653 | `stage3d_float1_index` | 0 | 26.8s |  |
| 654 | `stage3d_fractal` | 0 | 9.0s |  |
| 655 | `stage3d_ignore_sampler_override` | 0 | 27.3s |  |
| 656 | `stage3d_program_constants_bytearray_be` | 0 | 27.6s |  |
| 657 | `stage3d_program_constants_bytearray_le` | 0 | 9.1s |  |
| 658 | `stage3d_raytrace` | 0 | 29.6s |  |
| 659 | `stage3d_rotating_cube` | 0 | 9.1s |  |
| 660 | `stage3d_sampler` | 0 | 8.1s |  |
| 661 | `stage3d_sampler_partial_upload` | 0 | 8.1s |  |
| 662 | `stage3d_stencil` | 0 | 27.2s |  |
| 663 | `stage3d_texture` | 0 | 13.2s |  |
| 664 | `stage3d_texture_bytearray` | 0 | 9.5s |  |
| 665 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.9s |  |
| 666 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.0s |  |
| 667 | `stage3d_triangle` | 0 | 8.4s |  |
| 668 | `stage3d_triangle_bytes4` | 0 | 8.3s |  |
| 669 | `stage3d_triangle_float1` | 0 | 8.3s |  |
| 670 | `stage3d_triangle_index_upload` | 0 | 8.2s |  |
| 671 | `stage_access` | 10 | 5.5s |  |
| 672 | `stage_displayobject_properties` | 24 | 5.4s |  |
| 673 | `stage_framerate_nan` | 7 | 5.6s |  |
| 674 | `stage_framerate_negative` | 6 | 5.5s |  |
| 675 | `stage_framerate_zero` | 6 | 5.5s |  |
| 676 | `stage_invalidate` | 38 | 5.7s |  |
| 677 | `stage_mousechildren` | 2 | 5.4s |  |
| 678 | `stage_mouseenabled` | 15 | 5.4s |  |
| 679 | `stage_overriden_setters` | 31 | 5.6s |  |
| 680 | `stage_properties` | 30 | 5.4s |  |
| 681 | `static_var_with_this_in_ctor` | 2 | 5.5s |  |
| 682 | `stored_properties` | 11 | 5.4s |  |
| 683 | `strict_equality` | 34 | 5.5s |  |
| 684 | `string_call` | 13 | 5.4s |  |
| 685 | `string_case` | 23 | 5.6s |  |
| 686 | `string_char_at` | 27 | 5.5s |  |
| 687 | `string_char_code_at` | 28 | 5.4s |  |
| 688 | `string_constr` | 25 | 5.8s |  |
| 689 | `string_indexof_lastindexof` | 87 | 6.0s |  |
| 690 | `string_length` | 16 | 5.8s |  |
| 691 | `string_locale_compare` | 39 | 6.1s |  |
| 692 | `string_match` | 51 | 6.0s |  |
| 693 | `string_relational_compare` | 4 | 5.7s |  |
| 694 | `string_replace` | 51 | 5.8s |  |
| 695 | `string_search` | 41 | 5.8s |  |
| 696 | `string_split` | 29 | 5.7s |  |
| 697 | `string_substr_negative` | 21 | 5.6s |  |
| 698 | `string_substr_weird` | 182 | 5.6s |  |
| 699 | `subtract` | 1058 | 17.2s |  |
| 700 | `super_get_call` | 12 | 5.7s |  |
| 701 | `supercall_two_classobjects` | 2 | 5.7s |  |
| 702 | `swf8` | 1 | 5.5s |  |
| 703 | `swf_10_queued_goto_scripts_construct` | 52 | 24.7s |  |
| 704 | `swf_9_goto_in_enter_frame` | 17 | 5.8s |  |
| 705 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.8s |  |
| 706 | `swf_9_queued_goto_scripts` | 6 | 24.4s |  |
| 707 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 708 | `swf_9_versioning` | 2 | 5.8s |  |
| 709 | `swf_wrong_frame_count` | 38 | 6.0s |  |
| 710 | `swf_wrong_frame_count_isplaying` | 22 | 5.7s |  |
| 711 | `symbol_class_binary_data` | 8 | 5.7s |  |
| 712 | `symbol_class_conflict` | 4 | 6.3s |  |
| 713 | `symbol_class_root_not_zero` | 1 | 5.6s |  |
| 714 | `symbolclass_invalid_utf8` | 2 | 5.7s |  |
| 715 | `tab_ordering_automatic_advanced` | 184 | 6.1s |  |
| 716 | `tab_ordering_automatic_basic` | 45 | 5.6s |  |
| 717 | `tab_ordering_children` | 116 | 5.7s |  |
| 718 | `tab_ordering_custom_basic` | 34 | 5.6s |  |
| 719 | `text_engine_fontdescription` | 27 | 5.8s |  |
| 720 | `text_run` | 7 | 5.5s |  |
| 721 | `textfield_focusin_event` | 9 | 5.6s |  |
| 722 | `textfield_input_dead_keys_windows` | 15 | 5.7s |  |
| 723 | `textfield_unload` | 39 | 24.8s |  |
| 724 | `textformat` | 1134 | 5.7s |  |
| 725 | `textformat_display` | 14 | 5.7s |  |
| 726 | `textformat_font_max_length` | 4 | 5.6s |  |
| 727 | `throw` | 3 | 5.6s |  |
| 728 | `timeline_scripts` | 3 | 5.8s |  |
| 729 | `timer` | 90 | 6.3s |  |
| 730 | `timer_events` | 3 | 5.6s |  |
| 731 | `timer_finished` | 11 | 5.8s |  |
| 732 | `timer_reset` | 8 | 5.7s |  |
| 733 | `timer_setdelay` | 5 | 5.7s |  |
| 734 | `trace` | 12 | 5.7s |  |
| 735 | `truthiness` | 30 | 6.1s |  |
| 736 | `try_catch` | 11 | 6.1s |  |
| 737 | `try_catch_typed` | 12 | 6.2s |  |
| 738 | `typeof` | 30 | 6.1s |  |
| 739 | `uint_constr` | 92 | 6.2s |  |
| 740 | `uint_tofixed` | 1215 | 6.1s |  |
| 741 | `uint_tostring` | 3375 | 6.4s |  |
| 742 | `unchecked_function` | 15 | 6.1s |  |
| 743 | `urlrequest` | 18 | 6.1s |  |
| 744 | `urshift` | 1058 | 17.5s |  |
| 745 | `vector_class` | 36 | 6.4s |  |
| 746 | `vector_class_call` | 11 | 6.2s |  |
| 747 | `vector_coercion` | 66 | 6.7s |  |
| 748 | `vector_concat` | 90 | 6.5s |  |
| 749 | `vector_constr` | 107 | 6.6s |  |
| 750 | `vector_enumeration` | 5 | 6.0s |  |
| 751 | `vector_every` | 92 | 6.8s |  |
| 752 | `vector_filter` | 95 | 6.8s |  |
| 753 | `vector_holes` | 24 | 6.0s |  |
| 754 | `vector_indexof` | 302 | 10.6s |  |
| 755 | `vector_insertat` | 270 | 7.1s |  |
| 756 | `vector_int_access` | 4 | 6.0s |  |
| 757 | `vector_int_delete` | 11 | 3.0s |  |
| 758 | `vector_join` | 58 | 6.4s |  |
| 759 | `vector_lastindexof` | 302 | 5.8s |  |
| 760 | `vector_legacy` | 10 | 5.9s |  |
| 761 | `vector_map` | 85 | 6.6s |  |
| 762 | `vector_object_final` | 1 | 5.7s |  |
| 763 | `vector_object_toString` | 10 | 5.8s |  |
| 764 | `vector_pushpop` | 255 | 7.0s |  |
| 765 | `vector_reborrow_bug` | 10 | 5.8s |  |
| 766 | `vector_removeat` | 172 | 6.7s |  |
| 767 | `vector_reverse` | 232 | 6.8s |  |
| 768 | `vector_shiftunshift` | 252 | 6.9s |  |
| 769 | `vector_slice` | 331 | 7.3s |  |
| 770 | `vector_sort` | 905 | 14.8s |  |
| 771 | `vector_splice` | 693 | 9.6s |  |
| 772 | `vector_splice_fixed_bug_compat` | 4 | 5.8s |  |
| 773 | `vector_tostring` | 79 | 6.3s |  |
| 774 | `verify_abnormal_loop` | 1 | 5.8s |  |
| 775 | `verify_exception_targets_edge_case` | 1 | 5.8s |  |
| 776 | `verify_lookup_switch_edge_case` | 1 | 5.8s |  |
| 777 | `verify_unreachable_exception` | 2 | 5.9s |  |
| 778 | `versioned_isplaying` | 2 | 5.9s |  |
| 779 | `virtual_properties` | 16 | 6.1s |  |
| 780 | `with` | 4 | 6.0s |  |
| 781 | `xml_abstract_equality` | 36 | 6.1s |  |
| 782 | `xml_advanced` | 52 | 6.0s |  |
| 783 | `xml_appendchild` | 10 | 5.8s |  |
| 784 | `xml_as_attribute` | 9 | 5.9s |  |
| 785 | `xml_attribute` | 35 | 6.2s |  |
| 786 | `xml_attribute_name` | 40 | 6.0s |  |
| 787 | `xml_child` | 25 | 6.1s |  |
| 788 | `xml_childindex` | 7 | 6.0s |  |
| 789 | `xml_children` | 43 | 6.5s |  |
| 790 | `xml_class_call` | 9 | 6.0s |  |
| 791 | `xml_contains` | 197 | 6.0s |  |
| 792 | `xml_copy` | 20 | 5.6s |  |
| 793 | `xml_ctor_from_tostring` | 23 | 5.7s |  |
| 794 | `xml_delete` | 114 | 5.5s |  |
| 795 | `xml_descendants` | 83 | 5.5s |  |
| 796 | `xml_elements` | 6 | 5.4s |  |
| 797 | `xml_equals_namespace_check` | 2 | 5.4s |  |
| 798 | `xml_explicit_use_namespace` | 5 | 23.3s |  |
| 799 | `xml_getdescendants_qname` | 21 | 5.5s |  |
| 800 | `xml_has_property_via_in` | 26 | 5.5s |  |
| 801 | `xml_hasownproperty` | 6 | 5.4s |  |
| 802 | `xml_ignore_white` | 6 | 5.5s |  |
| 803 | `xml_length` | 2 | 5.4s |  |
| 804 | `xml_list_as_attribute` | 9 | 5.4s |  |
| 805 | `xml_list_concat` | 20 | 5.5s |  |
| 806 | `xml_list_enumerate` | 4 | 5.4s |  |
| 807 | `xml_methods_settings` | 3 | 5.4s |  |
| 808 | `xml_mismatched_tag` | 37 | 5.5s |  |
| 809 | `xml_namespace` | 39 | 2.6s |  |
| 810 | `xml_namespace_methods` | 245 | 5.5s |  |
| 811 | `xml_namespaced_property` | 7 | 5.5s |  |
| 812 | `xml_no_namespace` | 1 | 5.4s |  |
| 813 | `xml_nodekind` | 3 | 5.4s |  |
| 814 | `xml_normalize` | 35 | 5.5s |  |
| 815 | `xml_notification_bubbling` | 361 | 5.5s |  |
| 816 | `xml_parent` | 8 | 5.4s |  |
| 817 | `xml_set_children` | 17 | 5.5s |  |
| 818 | `xml_set_name` | 34 | 5.5s |  |
| 819 | `xml_settings` | 6 | 2.6s |  |
| 820 | `xml_simple_complex_content` | 47 | 5.4s |  |
| 821 | `xml_text` | 7 | 5.5s |  |
| 822 | `xml_tostring` | 6 | 5.4s |  |
| 823 | `xml_tostring_namespace` | 12 | 5.4s |  |
| 824 | `xml_unescaping` | 23 | 5.5s |  |
| 825 | `xml_weird_ignores` | 54 | 5.5s |  |
| 826 | `xml_wildcard` | 11 | 5.5s |  |
| 827 | `xmldocument` | 254 | 5.5s |  |
| 828 | `xmlnode` | 3540 | 5.6s |  |
| 829 | `zero_frame_clip` | 3 | 5.8s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 5.3s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 5.6s |  |
| 3 | `blend_transform` | 1 | 1 | 6.1s |  |
| 4 | `coerce_property` | 3 | 3 | 5.7s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.7s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 23.6s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.0s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 5.8s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.6s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 5.8s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.7s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 24.8s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 24.6s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.0s |  |
| 16 | `int_toprecision` | 441 | 441 | 5.9s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 5.9s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.6s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 23.9s |  |
| 20 | `soundchannel_position` | 74 | 74 | 25.1s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 5.9s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.2s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 24.5s |  |
| 24 | `uint_toexponential` | 100 | 100 | 6.2s |  |
| 25 | `uint_toprecision` | 433 | 433 | 6.3s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 6.0s |  |

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
| 51 | `loaderinfo_loadurl` | 66.7% | 8 | 12 | 4 |  |
| 52 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 53 | `loaderinfo_properties_not_loaded` | 65.2% | 15 | 23 | 8 |  |
| 54 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 55 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 56 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
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
| 1 | `domain_memory` | exit code 1 | 5.7s |  |
| 2 | `method_without_body` | exit code 1 | 18.9s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.6s |  |
| 4 | `verify_typecheck` | exit code 1 | 5.8s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 35.5s |  |

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
| 51 | `loaderinfo_loadurl` | 66.7% | 8/12 | 12 | 12 |  |
| 52 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 53 | `loaderinfo_properties_not_loaded` | 65.2% | 15/23 | 23 | 23 |  |
| 54 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 55 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 56 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
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
