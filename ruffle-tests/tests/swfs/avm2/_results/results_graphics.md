# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-24 23:01 UTC

**Git SHA**: `17c19040c9`

**Run Duration**: 142m 28s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1177 |
| Passing | **805** (68.4%) |
| Ruffle-matched | 25 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **830** (70.5%) |
| Failing | 347 |
| Total expected lines | 147848 |
| Matching lines | 100406 (67.9%) |
| Mismatched lines | 47442 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 343 | 98.8% |
| Runtime Error | 3 | 0.9% |
| Timeout | 1 | 0.3% |

## Passing Tests

**805 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 16.7s |  |
| 2 | `agal_compiler` | 13 | 7.0s |  |
| 3 | `air_hidden_lookup` | 2 | 4.5s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.6s |  |
| 5 | `amf_custom_obj` | 26 | 4.6s |  |
| 6 | `amf_dictionary` | 9 | 4.5s |  |
| 7 | `amf_function` | 46 | 4.6s |  |
| 8 | `amf_invalid_date` | 2 | 4.6s |  |
| 9 | `amf_missing_prop` | 6 | 4.6s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 5.5s |  |
| 11 | `amf_setter_error` | 8 | 5.7s |  |
| 12 | `amf_vector` | 40 | 5.7s |  |
| 13 | `amf_xml` | 6 | 5.5s |  |
| 14 | `application_domain` | 4 | 5.5s |  |
| 15 | `array_access` | 18 | 5.6s |  |
| 16 | `array_access_interpreter` | 4 | 5.5s |  |
| 17 | `array_access_no_pubns` | 2 | 5.5s |  |
| 18 | `array_concat` | 41 | 5.5s |  |
| 19 | `array_constr` | 10 | 5.4s |  |
| 20 | `array_delete` | 44 | 5.6s |  |
| 21 | `array_enumeration` | 10 | 5.5s |  |
| 22 | `array_enumeration_elements` | 11 | 5.5s |  |
| 23 | `array_every` | 8 | 5.5s |  |
| 24 | `array_filter` | 6 | 5.5s |  |
| 25 | `array_foreach` | 18 | 5.4s |  |
| 26 | `array_hasownproperty` | 11 | 2.6s |  |
| 27 | `array_holes` | 9 | 5.5s |  |
| 28 | `array_index_max` | 84 | 5.3s |  |
| 29 | `array_indexof` | 25 | 5.5s |  |
| 30 | `array_join` | 26 | 5.5s |  |
| 31 | `array_lastindexof` | 29 | 5.5s |  |
| 32 | `array_length` | 14 | 5.5s |  |
| 33 | `array_literal` | 3 | 5.4s |  |
| 34 | `array_map` | 8 | 5.4s |  |
| 35 | `array_pop` | 52 | 5.5s |  |
| 36 | `array_push` | 24 | 5.5s |  |
| 37 | `array_reborrow_bug` | 6 | 5.5s |  |
| 38 | `array_reverse` | 28 | 5.5s |  |
| 39 | `array_shift` | 51 | 2.7s |  |
| 40 | `array_slice` | 39 | 5.6s |  |
| 41 | `array_some` | 8 | 5.5s |  |
| 42 | `array_sort` | 297 | 5.9s |  |
| 43 | `array_sort_fun_swf12` | 2 | 5.5s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 45 | `array_sort_random` | 210 | 5.5s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 5.5s |  |
| 47 | `array_sorton` | 545 | 4.2s |  |
| 48 | `array_sparse_ops` | 41 | 3.7s |  |
| 49 | `array_splice` | 133 | 3.8s |  |
| 50 | `array_splice2` | 428 | 3.8s |  |
| 51 | `array_splice_types` | 48 | 3.7s |  |
| 52 | `array_storage` | 8 | 3.6s |  |
| 53 | `array_tolocalestring` | 9 | 3.6s |  |
| 54 | `array_tostring` | 12 | 3.8s |  |
| 55 | `array_unshift` | 24 | 3.6s |  |
| 56 | `array_valueof` | 9 | 3.6s |  |
| 57 | `array_vector_null_callback` | 10 | 3.6s |  |
| 58 | `astype` | 28 | 3.7s |  |
| 59 | `astypelate` | 24 | 3.8s |  |
| 60 | `astypelate_propagates` | 1 | 3.7s |  |
| 61 | `asymmetric_key_events` | 11 | 3.7s |  |
| 62 | `avm2_catchup_dobj` | 158 | 4.0s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 55.7s |  |
| 64 | `bitand` | 1058 | 11.1s |  |
| 65 | `bitmap_constr` | 17 | 3.8s |  |
| 66 | `bitmap_data` | 1000 | 8.3s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 17.5s |  |
| 68 | `bitmap_properties` | 23 | 3.7s |  |
| 69 | `bitmap_subclass` | 7 | 4.5s |  |
| 70 | `bitmap_subclass_properties` | 9 | 4.0s |  |
| 71 | `bitmap_timeline` | 9 | 3.7s |  |
| 72 | `bitmapdata_accuracy` | 1 | 43.8s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 17.5s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.2s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 17.9s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 17.5s |  |
| 77 | `bitmapdata_clone` | 13 | 3.9s |  |
| 78 | `bitmapdata_colortransform` | 0 | 4.0s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 3.7s |  |
| 80 | `bitmapdata_constr` | 22 | 1.7s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 3.8s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.0s |  |
| 83 | `bitmapdata_copypixels` | 23 | 25.6s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.6s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.6s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.6s |  |
| 87 | `bitmapdata_draw` | 0 | 25.1s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.0s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 24.5s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 24.3s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 5.7s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 5.9s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.0s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 24.2s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 5.8s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.0s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.0s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 24.5s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.5s |  |
| 100 | `bitmapdata_getpixels` | 39 | 23.8s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.7s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.7s |  |
| 103 | `bitmapdata_hittest` | 112 | 6.1s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.5s |  |
| 105 | `bitmapdata_opaque` | 0 | 5.8s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 24.1s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.0s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.4s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.6s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.6s |  |
| 111 | `bitmapdata_sync` | 0 | 5.7s |  |
| 112 | `bitmapdata_threshold` | 176 | 6.2s |  |
| 113 | `bitnot` | 46 | 5.6s |  |
| 114 | `bitor` | 1058 | 17.8s |  |
| 115 | `bitxor` | 1058 | 17.6s |  |
| 116 | `blend_multiply_alpha` | 0 | 5.8s |  |
| 117 | `blend_scroll` | 0 | 5.9s |  |
| 118 | `boolean_constr` | 32 | 5.5s |  |
| 119 | `boolean_negation` | 30 | 5.4s |  |
| 120 | `boolean_tostring` | 8 | 5.4s |  |
| 121 | `broadcast_event` | 7 | 5.4s |  |
| 122 | `button_nested_frame` | 48 | 5.7s |  |
| 123 | `bytearray` | 48 | 5.6s |  |
| 124 | `bytearray_compress` | 31 | 5.5s |  |
| 125 | `bytearray_errors` | 24 | 5.5s |  |
| 126 | `bytearray_method_serialization` | 1 | 5.3s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 5.4s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 5.5s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 5.4s |  |
| 130 | `bytearray_serialization` | 3 | 5.4s |  |
| 131 | `bytearray_string_null` | 19 | 5.7s |  |
| 132 | `bytearray_tostring` | 15 | 5.4s |  |
| 133 | `bytearray_utf16` | 8 | 5.4s |  |
| 134 | `bytearray_writeobject` | 24 | 5.3s |  |
| 135 | `callee_in_initializer` | 6 | 5.3s |  |
| 136 | `callproplex_class` | 1 | 5.3s |  |
| 137 | `catch_class` | 6 | 5.4s |  |
| 138 | `catch_scope_slot` | 7 | 2.7s |  |
| 139 | `checkfilter` | 4 | 2.6s |  |
| 140 | `class_call` | 32 | 23.1s |  |
| 141 | `class_cast_call` | 14 | 5.4s |  |
| 142 | `class_enumeration` | 4 | 5.4s |  |
| 143 | `class_has_own_property` | 2 | 5.4s |  |
| 144 | `class_init_interpreter_mode` | 1 | 5.4s |  |
| 145 | `class_is` | 32 | 5.5s |  |
| 146 | `class_methods` | 5 | 5.4s |  |
| 147 | `class_object_properties` | 10 | 5.4s |  |
| 148 | `class_singleton` | 18 | 5.5s |  |
| 149 | `class_supercalls_errors` | 35 | 5.6s |  |
| 150 | `class_supercalls_mismatched` | 26 | 5.5s |  |
| 151 | `class_superclass_wrong_order` | 1 | 24.6s |  |
| 152 | `class_to_locale_string` | 2 | 5.8s |  |
| 153 | `class_to_string` | 2 | 5.7s |  |
| 154 | `class_value_of` | 2 | 5.7s |  |
| 155 | `click_block` | 5 | 24.8s |  |
| 156 | `click_invisible` | 3 | 6.0s |  |
| 157 | `closures` | 12 | 5.8s |  |
| 158 | `coerce_return_type` | 40 | 6.0s |  |
| 159 | `coerce_return_type_fail` | 2 | 5.8s |  |
| 160 | `coerce_return_void` | 3 | 5.7s |  |
| 161 | `coerce_string` | 86 | 6.1s |  |
| 162 | `coerce_string_precision` | 28 | 6.0s |  |
| 163 | `coerce_to_primitive_side_effects` | 29 | 6.0s |  |
| 164 | `construct_errors_swf10` | 8 | 5.9s |  |
| 165 | `construct_frame_list` | 22 | 6.1s |  |
| 166 | `constructor_call` | 3 | 5.9s |  |
| 167 | `constructors_vs_timeline` | 5 | 25.7s |  |
| 168 | `constructprop_dynamic_primitive` | 7 | 6.0s |  |
| 169 | `control_flow_bool` | 4 | 5.9s |  |
| 170 | `control_flow_stricteq` | 8 | 6.0s |  |
| 171 | `convert_boolean` | 30 | 5.9s |  |
| 172 | `convert_integer` | 90 | 6.0s |  |
| 173 | `convert_number` | 56 | 6.0s |  |
| 174 | `convert_uinteger` | 90 | 6.1s |  |
| 175 | `cryptscore` | 11 | 6.1s |  |
| 176 | `declocal` | 46 | 5.7s |  |
| 177 | `declocal_i` | 46 | 5.7s |  |
| 178 | `decrement` | 46 | 5.7s |  |
| 179 | `decrement_i` | 46 | 2.8s |  |
| 180 | `default_values` | 7 | 5.7s |  |
| 181 | `dictionary_access` | 62 | 5.8s |  |
| 182 | `dictionary_access_no_pubns` | 2 | 5.5s |  |
| 183 | `dictionary_delete` | 101 | 6.0s |  |
| 184 | `dictionary_foreach` | 42 | 5.8s |  |
| 185 | `dictionary_hasownproperty` | 63 | 6.0s |  |
| 186 | `dictionary_in` | 62 | 5.7s |  |
| 187 | `dictionary_iter_modify` | 8 | 5.5s |  |
| 188 | `dictionary_namespaces` | 36 | 5.6s |  |
| 189 | `dictionary_primitive_keys` | 29 | 5.5s |  |
| 190 | `displayobject_alpha` | 277 | 5.4s |  |
| 191 | `displayobject_blendmode` | 0 | 5.7s |  |
| 192 | `displayobject_colortransform_nested` | 0 | 23.9s |  |
| 193 | `displayobject_from_enterframe` | 1 | 5.6s |  |
| 194 | `displayobject_getbounds_shape` | 0 | 24.0s |  |
| 195 | `displayobject_height` | 6052 | 24.3s |  |
| 196 | `displayobject_hittestobject` | 32 | 5.7s |  |
| 197 | `displayobject_invalid_floats` | 60 | 5.7s |  |
| 198 | `displayobject_invalid_props` | 3 | 2.8s |  |
| 199 | `displayobject_mask` | 3 | 6.0s |  |
| 200 | `displayobject_mask_self_referential` | 0 | 5.6s |  |
| 201 | `displayobject_metaData` | 3 | 5.6s |  |
| 202 | `displayobject_name` | 22 | 6.1s |  |
| 203 | `displayobject_name_from_timeline` | 24 | 6.1s |  |
| 204 | `displayobject_parent` | 12 | 5.8s |  |
| 205 | `displayobject_root` | 24 | 6.0s |  |
| 206 | `displayobject_rotation` | 1284 | 6.0s |  |
| 207 | `displayobject_set_matrix_nested` | 0 | 25.1s |  |
| 208 | `displayobject_subclass` | 2 | 5.9s |  |
| 209 | `displayobject_visible` | 23 | 5.7s |  |
| 210 | `displayobject_width` | 4852 | 24.9s |  |
| 211 | `displayobject_x` | 614 | 5.8s |  |
| 212 | `displayobject_y` | 617 | 5.9s |  |
| 213 | `displayobjectcontainer_addchild` | 32 | 6.0s |  |
| 214 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.8s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.1s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.9s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.9s |  |
| 218 | `displayobjectcontainer_addchildat` | 42 | 5.8s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.0s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.8s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.9s |  |
| 222 | `displayobjectcontainer_contains` | 66 | 25.1s |  |
| 223 | `displayobjectcontainer_getchildat` | 4 | 6.0s |  |
| 224 | `displayobjectcontainer_getchildbyname` | 9 | 6.0s |  |
| 225 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.9s |  |
| 226 | `displayobjectcontainer_getchildindex` | 28 | 6.0s |  |
| 227 | `displayobjectcontainer_removechild` | 10 | 6.0s |  |
| 228 | `displayobjectcontainer_removechild_errors` | 4 | 6.0s |  |
| 229 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.9s |  |
| 230 | `displayobjectcontainer_removechildat` | 18 | 5.8s |  |
| 231 | `displayobjectcontainer_removechildren` | 51 | 6.1s |  |
| 232 | `displayobjectcontainer_setchildindex` | 42 | 5.7s |  |
| 233 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.2s |  |
| 234 | `displayobjectcontainer_swapchildren` | 42 | 5.9s |  |
| 235 | `displayobjectcontainer_swapchildrenat` | 42 | 5.9s |  |
| 236 | `displayobjectcontainer_timelineinstance` | 48 | 25.2s |  |
| 237 | `divide` | 1058 | 17.0s |  |
| 238 | `doabc_is_eager` | 1 | 23.8s |  |
| 239 | `documentclass` | 9 | 5.8s |  |
| 240 | `drag_drop` | 10 | 5.8s |  |
| 241 | `duplicate_defs` | 1 | 5.5s |  |
| 242 | `eager_init` | 1 | 5.7s |  |
| 243 | `edit_text_linkage` | 7 | 5.9s |  |
| 244 | `edittext_align` | 60 | 6.1s |  |
| 245 | `edittext_always_show_selection` | 0 | 24.6s |  |
| 246 | `edittext_antialiastype` | 296 | 5.9s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 7.0s |  |
| 248 | `edittext_autosize` | 39 | 6.0s |  |
| 249 | `edittext_autosize_align` | 0 | 24.7s |  |
| 250 | `edittext_autosize_height_dynamic` | 60 | 24.8s |  |
| 251 | `edittext_autosize_height_input` | 60 | 5.8s |  |
| 252 | `edittext_autosize_lazy_bounds_events` | 65 | 6.0s |  |
| 253 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.7s |  |
| 254 | `edittext_autosize_lazy_bounds_props` | 490 | 7.1s |  |
| 255 | `edittext_autosize_lazy_bounds_visual` | 0 | 6.0s |  |
| 256 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.9s |  |
| 257 | `edittext_bottom_scroll_v_basic` | 210 | 5.8s |  |
| 258 | `edittext_bounds_scale` | 24 | 24.0s |  |
| 259 | `edittext_bullet` | 30 | 5.8s |  |
| 260 | `edittext_default_format` | 221 | 6.0s |  |
| 261 | `edittext_default_format_empty` | 136 | 6.0s |  |
| 262 | `edittext_empty_text_format` | 7 | 5.8s |  |
| 263 | `edittext_focus_selection` | 5 | 5.7s |  |
| 264 | `edittext_font_size` | 45 | 5.8s |  |
| 265 | `edittext_format_empty_font` | 8 | 5.7s |  |
| 266 | `edittext_get_char_index_at_point` | 4 | 24.7s |  |
| 267 | `edittext_get_line_index_at_point` | 2 | 24.6s |  |
| 268 | `edittext_get_line_index_of_char` | 76 | 6.6s |  |
| 269 | `edittext_getcharboundaries` | 172 | 6.1s |  |
| 270 | `edittext_getcharboundaries_missing_glyphs` | 63 | 21.5s |  |
| 271 | `edittext_getcharboundaries_scroll` | 85 | 4.7s |  |
| 272 | `edittext_getlinemetrics` | 146 | 4.9s |  |
| 273 | `edittext_html` | 3101 | 5.0s |  |
| 274 | `edittext_html_condensewhite` | 487 | 4.8s |  |
| 275 | `edittext_html_entity` | 4 | 4.7s |  |
| 276 | `edittext_html_font_size_swf12` | 267 | 4.7s |  |
| 277 | `edittext_html_font_size_swf13` | 273 | 4.4s |  |
| 278 | `edittext_html_roundtrip` | 17 | 4.9s |  |
| 279 | `edittext_input_control` | 12 | 4.7s |  |
| 280 | `edittext_leading` | 9 | 4.7s |  |
| 281 | `edittext_letter_spacing` | 15 | 4.5s |  |
| 282 | `edittext_line_methods` | 294 | 5.8s |  |
| 283 | `edittext_line_metrics` | 11 | 21.8s |  |
| 284 | `edittext_margins` | 25 | 4.6s |  |
| 285 | `edittext_max_scroll_h_basic` | 475 | 4.7s |  |
| 286 | `edittext_max_scroll_v_basic` | 1000 | 4.6s |  |
| 287 | `edittext_mousedown` | 3 | 4.8s |  |
| 288 | `edittext_mouseenabled` | 26 | 4.5s |  |
| 289 | `edittext_newline_character` | 22 | 4.5s |  |
| 290 | `edittext_newline_stripping` | 64 | 6.7s |  |
| 291 | `edittext_newlines` | 30 | 4.6s |  |
| 292 | `edittext_paragraph_methods` | 257 | 4.5s |  |
| 293 | `edittext_paste_events` | 8 | 4.5s |  |
| 294 | `edittext_paste_maxchars` | 4 | 4.7s |  |
| 295 | `edittext_paste_restrict` | 16 | 4.5s |  |
| 296 | `edittext_restrict` | 191 | 4.5s |  |
| 297 | `edittext_restrict_events` | 22 | 4.5s |  |
| 298 | `edittext_scrollh` | 10 | 1.9s |  |
| 299 | `edittext_selected_text` | 9 | 4.4s |  |
| 300 | `edittext_set_html_same` | 17 | 4.5s |  |
| 301 | `edittext_set_text_vs_html` | 9 | 4.5s |  |
| 302 | `edittext_stylesheet` | 536 | 4.9s |  |
| 303 | `edittext_stylesheet_custom_tag` | 76 | 4.5s |  |
| 304 | `edittext_stylesheet_display` | 272 | 4.6s |  |
| 305 | `edittext_underline` | 40 | 4.7s |  |
| 306 | `edittext_width_height` | 103 | 4.7s |  |
| 307 | `edittext_wordwrap_word` | 150 | 6.8s |  |
| 308 | `edittext_wrap_breaks` | 2375 | 6.6s |  |
| 309 | `empty_bounds` | 1 | 6.0s |  |
| 310 | `equals` | 512 | 10.3s |  |
| 311 | `error_prototype` | 15 | 6.0s |  |
| 312 | `error_stack_trace_debug_swf17` | 0 | 25.9s |  |
| 313 | `error_stack_trace_debug_swf18` | 0 | 5.8s |  |
| 314 | `error_stack_trace_release_swf17` | 0 | 5.9s |  |
| 315 | `error_stack_trace_release_swf18` | 0 | 5.8s |  |
| 316 | `error_tostring` | 29 | 5.9s |  |
| 317 | `es3_inheritance` | 31 | 6.1s |  |
| 318 | `es4_inheritance` | 30 | 6.0s |  |
| 319 | `es4_interfaces` | 30 | 5.8s |  |
| 320 | `es4_method_binding` | 8 | 2.9s |  |
| 321 | `es4_oop_prototypes` | 14 | 6.1s |  |
| 322 | `es4_protected_inheritance` | 6 | 5.9s |  |
| 323 | `event_bubbles` | 2 | 5.8s |  |
| 324 | `event_cancelable` | 2 | 5.7s |  |
| 325 | `event_clone` | 20 | 5.8s |  |
| 326 | `event_clone_error_redispatch` | 3 | 5.9s |  |
| 327 | `event_clone_on_redispatch` | 10 | 6.0s |  |
| 328 | `event_formattostring` | 31 | 5.8s |  |
| 329 | `event_isdefaultprevented` | 12 | 5.7s |  |
| 330 | `event_target_getter` | 5 | 2.9s |  |
| 331 | `event_target_set` | 9 | 5.7s |  |
| 332 | `event_type` | 1 | 5.8s |  |
| 333 | `event_valueof_tostring` | 18 | 5.9s |  |
| 334 | `eventdispatcher_dispatchevent` | 12 | 5.5s |  |
| 335 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.5s |  |
| 336 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.5s |  |
| 337 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.6s |  |
| 338 | `eventdispatcher_dispatchevent_this` | 5 | 5.5s |  |
| 339 | `eventdispatcher_haseventlistener` | 25 | 5.6s |  |
| 340 | `eventdispatcher_interface_invoke` | 1 | 5.5s |  |
| 341 | `eventdispatcher_tostring` | 10 | 5.5s |  |
| 342 | `eventdispatcher_willtrigger` | 25 | 5.4s |  |
| 343 | `falsiness` | 30 | 5.6s |  |
| 344 | `fast_index_access` | 12 | 5.7s |  |
| 345 | `finddef` | 3 | 5.8s |  |
| 346 | `findprop_global_prototype` | 6 | 5.8s |  |
| 347 | `flash_xml` | 29 | 5.8s |  |
| 348 | `flash_xml_cloneNode` | 22 | 5.8s |  |
| 349 | `flash_xml_namespace` | 109 | 5.7s |  |
| 350 | `flash_xml_removeNode` | 60 | 5.8s |  |
| 351 | `focus_events_code` | 161 | 26.3s |  |
| 352 | `focus_events_key_same_object` | 26 | 5.7s |  |
| 353 | `focus_events_mixed_key_mouse` | 100 | 24.3s |  |
| 354 | `focus_events_mouse_same_object` | 40 | 5.5s |  |
| 355 | `focus_remove` | 20 | 23.1s |  |
| 356 | `focus_root_movie` | 4 | 23.5s |  |
| 357 | `focus_stage` | 1 | 5.4s |  |
| 358 | `focusrect` | 18 | 6.2s |  |
| 359 | `font_description_clone` | 14 | 5.4s |  |
| 360 | `font_embedded` | 24 | 5.7s |  |
| 361 | `font_enumeratefonts` | 41 | 6.0s |  |
| 362 | `font_enumeratefonts_filter` | 4 | 23.4s |  |
| 363 | `font_hasglyphs` | 40 | 5.8s |  |
| 364 | `framelabel_constr` | 5 | 5.3s |  |
| 365 | `function_call` | 12 | 5.4s |  |
| 366 | `function_call_arguments` | 46 | 5.4s |  |
| 367 | `function_call_arguments_enumerate` | 5 | 5.3s |  |
| 368 | `function_call_coercion` | 108 | 5.8s |  |
| 369 | `function_call_default` | 6 | 5.3s |  |
| 370 | `function_call_rest` | 22 | 5.4s |  |
| 371 | `function_call_types` | 3 | 5.3s |  |
| 372 | `function_call_via_apply` | 11 | 5.4s |  |
| 373 | `function_call_via_call` | 3 | 5.3s |  |
| 374 | `function_display_anonymous` | 7 | 2.6s |  |
| 375 | `function_length` | 6 | 5.4s |  |
| 376 | `function_object` | 2 | 5.4s |  |
| 377 | `function_proto` | 5 | 5.3s |  |
| 378 | `function_proto_created` | 61 | 5.4s |  |
| 379 | `function_to_locale_string` | 4 | 5.3s |  |
| 380 | `function_to_string` | 4 | 5.2s |  |
| 381 | `function_type` | 6 | 5.4s |  |
| 382 | `function_unbound_this` | 51 | 5.5s |  |
| 383 | `function_value_of` | 4 | 5.4s |  |
| 384 | `get_definition_by_name` | 11 | 5.4s |  |
| 385 | `get_qualified_class_name` | 20 | 5.4s |  |
| 386 | `get_qualified_super_class_name` | 18 | 5.8s |  |
| 387 | `get_slot_edge_cases` | 1 | 23.2s |  |
| 388 | `get_timer` | 2 | 5.2s |  |
| 389 | `getglobalslot` | 1 | 5.1s |  |
| 390 | `getouterscope` | 8 | 5.2s |  |
| 391 | `getter_different_namespace_setter` | 2 | 5.2s |  |
| 392 | `goto_button_nested_framescript` | 28 | 5.6s |  |
| 393 | `goto_in_constructframe` | 12 | 5.4s |  |
| 394 | `goto_in_scene_last_frame` | 2 | 23.2s |  |
| 395 | `goto_methods` | 56 | 5.4s |  |
| 396 | `goto_methods_swfver10` | 8 | 5.2s |  |
| 397 | `goto_nested_construct_sibling` | 18 | 5.5s |  |
| 398 | `goto_nested_framescript` | 9 | 5.4s |  |
| 399 | `goto_on_orphan` | 15 | 5.5s |  |
| 400 | `graphics_bad_direct_commands` | 5 | 6.0s |  |
| 401 | `graphics_bitmap_fill` | 0 | 7.1s |  |
| 402 | `graphics_bitmaps` | 0 | 5.9s |  |
| 403 | `graphics_direct_commands` | 0 | 5.9s |  |
| 404 | `graphics_draw_triangles` | 98 | 24.3s |  |
| 405 | `graphics_gradients` | 0 | 5.6s |  |
| 406 | `graphics_gradients_nulls` | 0 | 5.5s |  |
| 407 | `graphics_path` | 56 | 5.3s |  |
| 408 | `graphics_round_rects` | 0 | 5.2s |  |
| 409 | `graphics_simple_shapes` | 0 | 5.5s |  |
| 410 | `greaterequals` | 512 | 9.3s |  |
| 411 | `greaterthan` | 512 | 9.2s |  |
| 412 | `has_own_property` | 102 | 5.8s |  |
| 413 | `hasownproperty_namespaces` | 2 | 5.2s |  |
| 414 | `hello_world` | 1 | 5.2s |  |
| 415 | `hittest_morph` | 30 | 5.3s |  |
| 416 | `if_eq` | 10 | 5.3s |  |
| 417 | `if_gt` | 1 | 5.3s |  |
| 418 | `if_gte` | 10 | 2.4s |  |
| 419 | `if_lt` | 1 | 5.8s |  |
| 420 | `if_lte` | 10 | 5.6s |  |
| 421 | `if_ne` | 7 | 2.8s |  |
| 422 | `if_stricteq` | 6 | 5.7s |  |
| 423 | `if_strictne` | 11 | 5.7s |  |
| 424 | `in` | 102 | 6.0s |  |
| 425 | `inclocal` | 46 | 5.6s |  |
| 426 | `inclocal_i` | 46 | 5.6s |  |
| 427 | `increment` | 46 | 5.5s |  |
| 428 | `increment_i` | 46 | 5.6s |  |
| 429 | `instanceof` | 58 | 5.8s |  |
| 430 | `instantiation_on_enter_frame` | 7 | 23.6s |  |
| 431 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.5s |  |
| 432 | `int_constr` | 92 | 5.4s |  |
| 433 | `int_edge_cases` | 19 | 5.6s |  |
| 434 | `int_instanceof` | 3 | 5.5s |  |
| 435 | `int_tofixed` | 1215 | 5.5s |  |
| 436 | `int_tostring` | 3375 | 5.6s |  |
| 437 | `interactiveobject_enabled` | 25 | 5.6s |  |
| 438 | `interface_namespaces` | 78 | 6.0s |  |
| 439 | `is_finite` | 46 | 5.9s |  |
| 440 | `is_nan` | 46 | 5.6s |  |
| 441 | `is_prototype_of` | 12 | 5.8s |  |
| 442 | `issue_10221` | 2 | 5.8s |  |
| 443 | `issue_13780` | 12 | 5.8s |  |
| 444 | `issue_14901` | 1 | 5.7s |  |
| 445 | `issue_17675_edittext_paste_maxchars` | 1 | 5.8s |  |
| 446 | `issue_5292` | 5 | 5.7s |  |
| 447 | `issue_8630` | 2 | 24.5s |  |
| 448 | `issue_8630_scriptremove` | 11 | 5.6s |  |
| 449 | `istype` | 24 | 2.7s |  |
| 450 | `istypelate` | 58 | 5.9s |  |
| 451 | `istypelate_coerce` | 198 | 6.8s |  |
| 452 | `json_errors` | 9 | 17.8s |  |
| 453 | `json_parse` | 21 | 4.0s |  |
| 454 | `json_stringify` | 12 | 4.1s |  |
| 455 | `json_stringify_order` | 1 | 3.7s |  |
| 456 | `json_version_gated` | 1 | 4.3s |  |
| 457 | `key_input_80percent` | 1812 | 4.3s |  |
| 458 | `key_input_location` | 126 | 4.0s |  |
| 459 | `key_input_numpad` | 384 | 4.0s |  |
| 460 | `lazyinit` | 17 | 4.1s |  |
| 461 | `lessequals` | 512 | 6.2s |  |
| 462 | `lessthan` | 512 | 6.3s |  |
| 463 | `loaderinfo_properties` | 18 | 4.6s |  |
| 464 | `loaderinfo_root` | 10 | 4.4s |  |
| 465 | `loaderinfo_root_allows` | 2 | 4.3s |  |
| 466 | `lshift` | 1058 | 13.2s |  |
| 467 | `mask_reapply` | 1 | 4.5s |  |
| 468 | `math` | 497 | 4.5s |  |
| 469 | `missing_external_interface` | 10 | 4.4s |  |
| 470 | `modulo` | 1058 | 13.3s |  |
| 471 | `morph_shape` | 2 | 19.6s |  |
| 472 | `mouse_click_events` | 90 | 18.8s |  |
| 473 | `mouse_double_click_events` | 188 | 4.4s |  |
| 474 | `mouse_empty_parent` | 4 | 4.4s |  |
| 475 | `mouse_over_while_dragging` | 3 | 4.4s |  |
| 476 | `mouse_pick_button_mode` | 2 | 4.5s |  |
| 477 | `mouse_sibling` | 8 | 4.5s |  |
| 478 | `movieclip_addframescript` | 3 | 18.7s |  |
| 479 | `movieclip_child_property` | 16 | 4.4s |  |
| 480 | `movieclip_constr` | 21 | 4.4s |  |
| 481 | `movieclip_currentlabels` | 17 | 23.5s |  |
| 482 | `movieclip_currentlabels_dupes1` | 46 | 23.0s |  |
| 483 | `movieclip_currentlabels_dupes2` | 30 | 5.4s |  |
| 484 | `movieclip_currentlabels_dupes3` | 67 | 5.4s |  |
| 485 | `movieclip_currentscene` | 12 | 5.4s |  |
| 486 | `movieclip_dispatchevent` | 430 | 5.5s |  |
| 487 | `movieclip_dispatchevent_cancel` | 102 | 5.5s |  |
| 488 | `movieclip_dispatchevent_handlerorder` | 251 | 5.4s |  |
| 489 | `movieclip_dispatchevent_selfadd` | 80 | 5.4s |  |
| 490 | `movieclip_dispatchevent_target` | 899 | 5.5s |  |
| 491 | `movieclip_displayevents` | 96 | 23.3s |  |
| 492 | `movieclip_displayevents_clickgoto` | 676 | 5.8s |  |
| 493 | `movieclip_displayevents_clickgoto2` | 2001 | 5.9s |  |
| 494 | `movieclip_displayevents_clickplay` | 575 | 5.6s |  |
| 495 | `movieclip_displayevents_clicksymbol` | 562 | 5.6s |  |
| 496 | `movieclip_displayevents_constructframegoto` | 140 | 5.8s |  |
| 497 | `movieclip_displayevents_constructframeplay` | 50 | 5.7s |  |
| 498 | `movieclip_displayevents_constructframesymbol` | 144 | 5.6s |  |
| 499 | `movieclip_displayevents_dblhandler` | 21 | 5.5s |  |
| 500 | `movieclip_displayevents_enterframegoto` | 149 | 5.7s |  |
| 501 | `movieclip_displayevents_enterframeplay` | 48 | 5.5s |  |
| 502 | `movieclip_displayevents_enterframesymbol` | 149 | 23.3s |  |
| 503 | `movieclip_displayevents_exitframegoto` | 106 | 5.5s |  |
| 504 | `movieclip_displayevents_exitframeplay` | 44 | 5.5s |  |
| 505 | `movieclip_displayevents_exitframesymbol` | 135 | 5.6s |  |
| 506 | `movieclip_displayevents_looping` | 63 | 23.5s |  |
| 507 | `movieclip_displayevents_stopped` | 113 | 5.8s |  |
| 508 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 509 | `movieclip_displayevents_timeline` | 128 | 23.4s |  |
| 510 | `movieclip_drawrect` | 54 | 5.4s |  |
| 511 | `movieclip_frameconstruct_skipped` | 9 | 5.4s |  |
| 512 | `movieclip_goto_during_frame_script` | 15 | 5.4s |  |
| 513 | `movieclip_goto_overwrite` | 14 | 23.0s |  |
| 514 | `movieclip_goto_scene_last_frame_int` | 1 | 23.2s |  |
| 515 | `movieclip_goto_scene_last_frame_label` | 1 | 2.5s |  |
| 516 | `movieclip_gotoandplay` | 15 | 23.1s |  |
| 517 | `movieclip_gotoandstop` | 13 | 5.3s |  |
| 518 | `movieclip_gotoandstop_children` | 4 | 5.5s |  |
| 519 | `movieclip_gotoandstop_framescripts1` | 4 | 5.4s |  |
| 520 | `movieclip_gotoandstop_framescripts2` | 4 | 2.6s |  |
| 521 | `movieclip_gotoandstop_framescripts_self` | 7 | 4.9s |  |
| 522 | `movieclip_gotoandstop_queueing` | 12 | 20.5s |  |
| 523 | `movieclip_next_frame` | 2 | 4.4s |  |
| 524 | `movieclip_next_scene` | 6 | 20.3s |  |
| 525 | `movieclip_play` | 3 | 1.9s |  |
| 526 | `movieclip_prev_frame` | 3 | 4.3s |  |
| 527 | `movieclip_prev_scene` | 7 | 4.5s |  |
| 528 | `movieclip_properties` | 79 | 4.6s |  |
| 529 | `movieclip_queued_noop_goto_swf10` | 9 | 4.5s |  |
| 530 | `movieclip_queued_noop_goto_swf9` | 7 | 0.8s |  |
| 531 | `movieclip_scenes` | 11 | 4.4s |  |
| 532 | `movieclip_soundtransform` | 831 | 22.0s |  |
| 533 | `movieclip_stop` | 1 | 4.4s |  |
| 534 | `movieclip_super_is_symbol` | 20 | 4.7s |  |
| 535 | `movieclip_symbol_constr` | 8 | 4.5s |  |
| 536 | `movieclip_text_mousedown` | 1 | 4.5s |  |
| 537 | `movieclip_willtrigger` | 5 | 4.5s |  |
| 538 | `multiply` | 1058 | 12.7s |  |
| 539 | `namespace_constr` | 253 | 4.7s |  |
| 540 | `namespace_constr_args` | 1 | 4.4s |  |
| 541 | `namespace_enumeration_order` | 7 | 4.4s |  |
| 542 | `nan_scale` | 9 | 4.4s |  |
| 543 | `negate` | 30 | 5.2s |  |
| 544 | `negative_volume_panned` | 0 | 4.6s |  |
| 545 | `nested_iteration` | 11 | 6.0s |  |
| 546 | `net_getClassByAlias` | 3 | 5.1s |  |
| 547 | `newactivation_in_script_init` | 3 | 5.4s |  |
| 548 | `newclass_twice` | 3 | 5.4s |  |
| 549 | `nonconflicting_declarations` | 0 | 5.4s |  |
| 550 | `null_void_types` | 8 | 5.5s |  |
| 551 | `number_autoconv` | 21 | 2.7s |  |
| 552 | `number_autoconv_amf` | 132 | 5.5s |  |
| 553 | `number_autoconv_array_sort_32bit` | 1 | 5.5s |  |
| 554 | `number_constr` | 58 | 5.7s |  |
| 555 | `number_toexponential` | 378 | 5.5s |  |
| 556 | `number_toexponential2` | 35 | 5.4s |  |
| 557 | `number_tofixed` | 378 | 5.4s |  |
| 558 | `number_toprecision` | 350 | 5.5s |  |
| 559 | `obfuscated_class_names` | 3 | 5.5s |  |
| 560 | `object_enumeration` | 10 | 5.6s |  |
| 561 | `object_prototype` | 4 | 5.6s |  |
| 562 | `object_to_locale_string` | 2 | 5.7s |  |
| 563 | `object_to_string` | 2 | 5.7s |  |
| 564 | `object_value_of` | 2 | 2.7s |  |
| 565 | `op_coerce` | 54 | 2.9s |  |
| 566 | `op_coerce_x` | 54 | 5.7s |  |
| 567 | `op_escxattr` | 2 | 5.6s |  |
| 568 | `op_escxelem` | 2 | 5.7s |  |
| 569 | `op_lookupswitch` | 4 | 5.6s |  |
| 570 | `optimize_coerce` | 1 | 5.5s |  |
| 571 | `orphan_movie_complex` | 80 | 5.9s |  |
| 572 | `orphan_movie_reorder` | 111 | 23.9s |  |
| 573 | `package_namespace` | 7 | 5.4s |  |
| 574 | `param_default_value_has_zero_cpool_index` | 1 | 5.5s |  |
| 575 | `parent_early_access_child` | 16 | 5.8s |  |
| 576 | `parse_float` | 81 | 5.7s |  |
| 577 | `pixelbender_effect_BlurredFocus` | 0 | 27.6s |  |
| 578 | `pixelbender_effect_glassDisplace` | 0 | 11.3s |  |
| 579 | `pixelbender_effect_smudge` | 0 | 9.2s |  |
| 580 | `pixelbender_effect_tintype` | 0 | 8.5s |  |
| 581 | `pixelbender_effect_twirl` | 0 | 9.4s |  |
| 582 | `pixelbender_images` | 0 | 8.1s |  |
| 583 | `place_multiple` | 17 | 24.1s |  |
| 584 | `place_object_replace` | 9 | 5.9s |  |
| 585 | `place_object_replace_2` | 24 | 5.8s |  |
| 586 | `place_object_same_depth_frame` | 1 | 5.8s |  |
| 587 | `point` | 132 | 6.2s |  |
| 588 | `primitive_edge_cases` | 1 | 5.6s |  |
| 589 | `property_priority` | 22 | 6.0s |  |
| 590 | `property_priority_three_level` | 6 | 24.1s |  |
| 591 | `propertyisenumerable_namespaces` | 6 | 5.6s |  |
| 592 | `prototype_set_null` | 7 | 5.5s |  |
| 593 | `proxy_callproperty` | 24 | 5.6s |  |
| 594 | `proxy_deleteproperty` | 64 | 5.7s |  |
| 595 | `proxy_enumeration` | 34 | 5.6s |  |
| 596 | `proxy_getproperty` | 77 | 5.7s |  |
| 597 | `proxy_hasownproperty` | 8 | 5.6s |  |
| 598 | `proxy_hasproperty` | 32 | 5.7s |  |
| 599 | `proxy_serialize` | 9 | 5.6s |  |
| 600 | `proxy_setproperty` | 42 | 5.7s |  |
| 601 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.5s |  |
| 602 | `qname_constr` | 32 | 5.7s |  |
| 603 | `qname_constr_namespace` | 24 | 5.7s |  |
| 604 | `qname_enumeration` | 9 | 5.6s |  |
| 605 | `qname_indexing` | 23 | 5.7s |  |
| 606 | `qname_tostring` | 25 | 5.7s |  |
| 607 | `qname_valueof` | 29 | 5.7s |  |
| 608 | `regexp_constr` | 148 | 5.8s |  |
| 609 | `regexp_exec` | 19 | 5.6s |  |
| 610 | `regexp_extended` | 47 | 5.6s |  |
| 611 | `regexp_multiargs` | 1 | 5.6s |  |
| 612 | `regexp_test` | 27 | 2.8s |  |
| 613 | `regexp_toString` | 10 | 5.6s |  |
| 614 | `register_script_refresh` | 35 | 6.0s |  |
| 615 | `remove_child_clear_field` | 88 | 6.0s |  |
| 616 | `remove_dobj` | 3 | 5.5s |  |
| 617 | `resolve_order` | 4 | 5.6s |  |
| 618 | `rng` | 1 | 6.8s |  |
| 619 | `rootless` | 42 | 5.7s |  |
| 620 | `rshift` | 1058 | 17.4s |  |
| 621 | `sandbox_type_local_file` | 1 | 5.7s |  |
| 622 | `scene_constr` | 8 | 5.7s |  |
| 623 | `set_local_0` | 31 | 5.8s |  |
| 624 | `set_property_is_enumerable` | 85 | 6.2s |  |
| 625 | `shape_drawrect` | 54 | 5.7s |  |
| 626 | `shared_object_no_root` | 3 | 5.7s |  |
| 627 | `simplebutton_added_to_stage` | 45 | 24.6s |  |
| 628 | `simplebutton_childevents` | 86 | 6.2s |  |
| 629 | `simplebutton_childevents_nested` | 54 | 6.1s |  |
| 630 | `simplebutton_childevents_sprite` | 13 | 5.9s |  |
| 631 | `simplebutton_childprops` | 144 | 6.1s |  |
| 632 | `simplebutton_childshuffle` | 23 | 5.8s |  |
| 633 | `simplebutton_constr` | 36 | 6.0s |  |
| 634 | `simplebutton_constr_childevents` | 48 | 6.1s |  |
| 635 | `simplebutton_constr_params` | 42 | 6.0s |  |
| 636 | `simplebutton_mouseenabled` | 26 | 5.8s |  |
| 637 | `simplebutton_multi_children` | 19 | 6.0s |  |
| 638 | `simplebutton_structure` | 27 | 6.0s |  |
| 639 | `simplebutton_symbolclass` | 68 | 6.0s |  |
| 640 | `slot_disp_id_shared_numbering` | 1 | 24.1s |  |
| 641 | `slots_force_autoassigned` | 1 | 5.7s |  |
| 642 | `sound_embeddedprops` | 26 | 6.0s |  |
| 643 | `sound_play` | 19 | 6.1s |  |
| 644 | `sound_valueof` | 33 | 6.0s |  |
| 645 | `soundchannel_soundtransform` | 835 | 26.1s |  |
| 646 | `soundchannel_soundtransform_exists` | 5 | 24.3s |  |
| 647 | `soundchannel_stop` | 8 | 5.9s |  |
| 648 | `soundmixer_buffertime` | 5 | 5.7s |  |
| 649 | `soundmixer_stopall` | 6 | 5.9s |  |
| 650 | `soundtransform` | 442 | 8.1s |  |
| 651 | `sprite_with_frames` | 0 | 6.4s |  |
| 652 | `stage3d_agal_cross_product` | 0 | 8.4s |  |
| 653 | `stage3d_bitmap` | 0 | 29.7s |  |
| 654 | `stage3d_float1_index` | 0 | 26.7s |  |
| 655 | `stage3d_fractal` | 0 | 8.9s |  |
| 656 | `stage3d_ignore_sampler_override` | 0 | 27.2s |  |
| 657 | `stage3d_program_constants_bytearray_be` | 0 | 27.9s |  |
| 658 | `stage3d_program_constants_bytearray_le` | 0 | 9.1s |  |
| 659 | `stage3d_raytrace` | 0 | 32.0s |  |
| 660 | `stage3d_rotating_cube` | 0 | 9.9s |  |
| 661 | `stage3d_sampler` | 0 | 8.9s |  |
| 662 | `stage3d_sampler_partial_upload` | 0 | 8.9s |  |
| 663 | `stage3d_stencil` | 0 | 29.1s |  |
| 664 | `stage3d_texture` | 0 | 13.6s |  |
| 665 | `stage3d_texture_bytearray` | 0 | 10.0s |  |
| 666 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.2s |  |
| 667 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.4s |  |
| 668 | `stage3d_triangle` | 0 | 8.7s |  |
| 669 | `stage3d_triangle_bytes4` | 0 | 8.7s |  |
| 670 | `stage3d_triangle_float1` | 0 | 8.5s |  |
| 671 | `stage3d_triangle_index_upload` | 0 | 8.5s |  |
| 672 | `stage_access` | 10 | 3.0s |  |
| 673 | `stage_displayobject_properties` | 24 | 5.7s |  |
| 674 | `stage_framerate_nan` | 7 | 3.0s |  |
| 675 | `stage_framerate_negative` | 6 | 5.7s |  |
| 676 | `stage_framerate_zero` | 6 | 5.7s |  |
| 677 | `stage_invalidate` | 38 | 6.0s |  |
| 678 | `stage_mousechildren` | 2 | 5.9s |  |
| 679 | `stage_mouseenabled` | 15 | 5.8s |  |
| 680 | `stage_overriden_setters` | 31 | 6.0s |  |
| 681 | `stage_properties` | 30 | 5.8s |  |
| 682 | `static_var_with_this_in_ctor` | 2 | 5.8s |  |
| 683 | `stored_properties` | 11 | 5.8s |  |
| 684 | `strict_equality` | 34 | 5.9s |  |
| 685 | `string_call` | 13 | 5.9s |  |
| 686 | `string_case` | 23 | 5.8s |  |
| 687 | `string_char_at` | 27 | 5.8s |  |
| 688 | `string_char_code_at` | 28 | 5.7s |  |
| 689 | `string_concat_fromcharcode` | 37 | 25.1s |  |
| 690 | `string_constr` | 25 | 5.6s |  |
| 691 | `string_indexof_lastindexof` | 87 | 5.8s |  |
| 692 | `string_length` | 16 | 5.8s |  |
| 693 | `string_locale_compare` | 39 | 6.0s |  |
| 694 | `string_match` | 51 | 5.8s |  |
| 695 | `string_relational_compare` | 4 | 5.6s |  |
| 696 | `string_replace` | 51 | 5.9s |  |
| 697 | `string_search` | 41 | 5.8s |  |
| 698 | `string_slice_substr_substring` | 170 | 6.9s |  |
| 699 | `string_split` | 29 | 5.6s |  |
| 700 | `string_substr_negative` | 21 | 5.4s |  |
| 701 | `string_substr_weird` | 182 | 5.5s |  |
| 702 | `subtract` | 1058 | 18.1s |  |
| 703 | `super_get_call` | 12 | 5.6s |  |
| 704 | `supercall_two_classobjects` | 2 | 5.6s |  |
| 705 | `swf8` | 1 | 5.4s |  |
| 706 | `swf_10_queued_goto_scripts_construct` | 52 | 6.0s |  |
| 707 | `swf_9_goto_in_enter_frame` | 17 | 5.7s |  |
| 708 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.7s |  |
| 709 | `swf_9_queued_goto_scripts` | 6 | 5.6s |  |
| 710 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 711 | `swf_9_versioning` | 2 | 5.6s |  |
| 712 | `swf_wrong_frame_count` | 38 | 5.8s |  |
| 713 | `swf_wrong_frame_count_isplaying` | 22 | 5.6s |  |
| 714 | `symbol_class_binary_data` | 8 | 5.7s |  |
| 715 | `symbol_class_conflict` | 4 | 6.3s |  |
| 716 | `symbol_class_root_not_zero` | 1 | 5.6s |  |
| 717 | `symbolclass_invalid_utf8` | 2 | 5.5s |  |
| 718 | `tab_ordering_automatic_advanced` | 184 | 5.0s |  |
| 719 | `tab_ordering_automatic_basic` | 45 | 4.5s |  |
| 720 | `tab_ordering_children` | 116 | 4.5s |  |
| 721 | `tab_ordering_custom_basic` | 34 | 4.4s |  |
| 722 | `text_engine_fontdescription` | 27 | 4.7s |  |
| 723 | `text_run` | 7 | 4.7s |  |
| 724 | `textfield_focusin_event` | 9 | 4.6s |  |
| 725 | `textfield_input_dead_keys_windows` | 15 | 4.7s |  |
| 726 | `textfield_unload` | 39 | 20.2s |  |
| 727 | `textformat` | 1134 | 4.7s |  |
| 728 | `textformat_display` | 14 | 4.7s |  |
| 729 | `textformat_font_max_length` | 4 | 2.5s |  |
| 730 | `throw` | 3 | 4.7s |  |
| 731 | `timeline_scripts` | 3 | 4.8s |  |
| 732 | `timer` | 90 | 5.2s |  |
| 733 | `timer_events` | 3 | 4.5s |  |
| 734 | `timer_finished` | 11 | 2.3s |  |
| 735 | `timer_reset` | 8 | 4.5s |  |
| 736 | `timer_setdelay` | 5 | 4.4s |  |
| 737 | `trace` | 12 | 4.4s |  |
| 738 | `truthiness` | 30 | 1.1s |  |
| 739 | `try_catch` | 11 | 0.7s |  |
| 740 | `try_catch_typed` | 12 | 0.7s |  |
| 741 | `typeof` | 30 | 0.7s |  |
| 742 | `uint_constr` | 92 | 0.7s |  |
| 743 | `uint_tofixed` | 1215 | 0.7s |  |
| 744 | `uint_tostring` | 3375 | 0.7s |  |
| 745 | `unchecked_function` | 15 | 0.7s |  |
| 746 | `urlrequest` | 18 | 0.7s |  |
| 747 | `urshift` | 1058 | 0.7s |  |
| 748 | `vector_class` | 36 | 0.7s |  |
| 749 | `vector_class_call` | 11 | 0.7s |  |
| 750 | `vector_coercion` | 66 | 0.7s |  |
| 751 | `vector_concat` | 90 | 0.7s |  |
| 752 | `vector_constr` | 107 | 0.7s |  |
| 753 | `vector_enumeration` | 5 | 0.7s |  |
| 754 | `vector_every` | 92 | 0.7s |  |
| 755 | `vector_filter` | 95 | 0.7s |  |
| 756 | `vector_holes` | 24 | 0.7s |  |
| 757 | `vector_indexof` | 302 | 0.7s |  |
| 758 | `vector_insertat` | 270 | 0.7s |  |
| 759 | `vector_int_access` | 4 | 0.7s |  |
| 760 | `vector_int_delete` | 11 | 0.7s |  |
| 761 | `vector_join` | 58 | 0.7s |  |
| 762 | `vector_lastindexof` | 302 | 0.7s |  |
| 763 | `vector_legacy` | 10 | 0.7s |  |
| 764 | `vector_map` | 85 | 0.7s |  |
| 765 | `vector_object_final` | 1 | 0.7s |  |
| 766 | `vector_object_toString` | 10 | 0.7s |  |
| 767 | `vector_pushpop` | 255 | 0.7s |  |
| 768 | `xml_copy` | 20 | 6.2s |  |
| 769 | `xml_ctor_from_tostring` | 23 | 6.0s |  |
| 770 | `xml_delete` | 114 | 5.9s |  |
| 771 | `xml_descendants` | 83 | 5.9s |  |
| 772 | `xml_elements` | 6 | 5.7s |  |
| 773 | `xml_equals_namespace_check` | 2 | 5.7s |  |
| 774 | `xml_explicit_use_namespace` | 5 | 24.2s |  |
| 775 | `xml_getdescendants_qname` | 21 | 5.7s |  |
| 776 | `xml_has_property_via_in` | 26 | 5.8s |  |
| 777 | `xml_hasownproperty` | 6 | 5.7s |  |
| 778 | `xml_ignore_white` | 6 | 5.7s |  |
| 779 | `xml_length` | 2 | 5.8s |  |
| 780 | `xml_list_as_attribute` | 9 | 5.7s |  |
| 781 | `xml_list_concat` | 20 | 5.7s |  |
| 782 | `xml_list_enumerate` | 4 | 5.7s |  |
| 783 | `xml_methods_settings` | 3 | 5.7s |  |
| 784 | `xml_mismatched_tag` | 37 | 5.8s |  |
| 785 | `xml_namespace` | 39 | 2.8s |  |
| 786 | `xml_namespace_methods` | 245 | 5.8s |  |
| 787 | `xml_namespaced_property` | 7 | 5.7s |  |
| 788 | `xml_no_namespace` | 1 | 5.6s |  |
| 789 | `xml_nodekind` | 3 | 5.7s |  |
| 790 | `xml_normalize` | 35 | 5.8s |  |
| 791 | `xml_notification_bubbling` | 361 | 5.7s |  |
| 792 | `xml_parent` | 8 | 5.7s |  |
| 793 | `xml_set_children` | 17 | 5.8s |  |
| 794 | `xml_set_name` | 34 | 5.8s |  |
| 795 | `xml_settings` | 6 | 2.9s |  |
| 796 | `xml_simple_complex_content` | 47 | 5.8s |  |
| 797 | `xml_text` | 7 | 5.8s |  |
| 798 | `xml_tostring` | 6 | 5.7s |  |
| 799 | `xml_tostring_namespace` | 12 | 5.7s |  |
| 800 | `xml_unescaping` | 23 | 5.8s |  |
| 801 | `xml_weird_ignores` | 54 | 5.8s |  |
| 802 | `xml_wildcard` | 11 | 5.7s |  |
| 803 | `xmldocument` | 254 | 5.8s |  |
| 804 | `xmlnode` | 3540 | 5.9s |  |
| 805 | `zero_frame_clip` | 3 | 5.9s |  |

## Ruffle-Matched Tests

**25 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 5.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 3.5s |  |
| 3 | `blend_transform` | 1 | 1 | 6.0s |  |
| 4 | `coerce_property` | 3 | 3 | 5.9s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 3.0s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 5.7s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.9s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 4.7s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.1s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.1s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.3s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 23.3s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 24.4s |  |
| 15 | `int_toexponential` | 76 | 76 | 5.5s |  |
| 16 | `int_toprecision` | 441 | 441 | 5.5s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.0s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.6s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 24.0s |  |
| 20 | `soundchannel_position` | 74 | 74 | 25.7s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.1s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 5.8s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 5.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 0.7s |  |
| 25 | `uint_toprecision` | 433 | 433 | 0.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**67 tests** within reach

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
| 18 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 19 | `unescape` | 89.3% | 25 | 28 | 3 |  |
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
| 51 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 52 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 53 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 54 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 55 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 56 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 57 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 58 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 59 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 60 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 61 | `date` | 50.0% | 15 | 30 | 15 |  |
| 62 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 63 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 64 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 65 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 66 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 67 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 5.7s |  |
| 2 | `method_without_body` | exit code 1 | 18.8s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.7s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 35.3s |  |

## All Output Mismatches

**343 tests** with output mismatch, sorted by match rate (best first)

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
| 18 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 19 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
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
| 51 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 52 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 53 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 54 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 55 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 56 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 57 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 58 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 59 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 60 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 61 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 62 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 63 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 64 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 65 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 66 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 67 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 68 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 69 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 70 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 71 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 72 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 73 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 74 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 75 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 76 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 77 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 78 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 79 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 80 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 81 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 82 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 83 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 84 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 85 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 86 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 87 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 88 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 89 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 90 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 91 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 92 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 93 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 94 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 95 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 96 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 97 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 98 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 99 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 100 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 101 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 102 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 103 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 104 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 105 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 106 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 107 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 108 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 109 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 110 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 111 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 112 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 113 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 114 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 115 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 116 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 117 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 118 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 119 | `loader_events` | 8.7% | 8/92 | 20 | 92 |  |
| 120 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 121 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 122 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 123 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 124 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 125 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 126 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 127 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 128 | `loader_loadbytes_events` | 6.7% | 2/30 | 7 | 30 |  |
| 129 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 130 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 131 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 132 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 133 | `primitive_toString` | 5.8% | 16/277 | 141 | 277 |  |
| 134 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 135 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 136 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 137 | `primitive_valueOf` | 4.9% | 14/285 | 141 | 285 |  |
| 138 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 139 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 140 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 141 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 142 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 143 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 144 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 145 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 146 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 147 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 148 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 149 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 150 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 151 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 152 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 153 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 154 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 155 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 156 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 157 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 158 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 159 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 160 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 161 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 162 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 163 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 164 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 165 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 166 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 167 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 168 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 169 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 170 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 171 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 172 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 173 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 174 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 175 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 176 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 177 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 178 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 179 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 180 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 181 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 182 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 183 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 184 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 185 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 186 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 187 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 188 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 189 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 190 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 191 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 192 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 193 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 194 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 195 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 196 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 197 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 198 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 199 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 200 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 201 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 202 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 203 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 204 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 205 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 206 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 207 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 208 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 209 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 211 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 212 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 213 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 214 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 215 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 216 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 217 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 218 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 219 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 220 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 221 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 222 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 223 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 224 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 225 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 226 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 227 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 228 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 229 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 230 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 231 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 232 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 233 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 234 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 235 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 236 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 237 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 238 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 239 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 240 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 241 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 242 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 243 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 244 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 245 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 246 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 247 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 248 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 249 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 250 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 251 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 252 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 253 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 254 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 255 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 256 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 257 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 258 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 259 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 260 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 261 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 262 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 263 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 264 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 265 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 266 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 267 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 268 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 269 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 270 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 271 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 272 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 273 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 274 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 275 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 276 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 277 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 278 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 279 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 280 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 281 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 282 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 283 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 284 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 285 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 286 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 287 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 288 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 289 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 290 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 291 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 292 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 293 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 294 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 295 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 296 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 297 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 298 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 299 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 300 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 301 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 302 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 304 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 305 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 306 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 307 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 308 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 309 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 310 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 311 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 312 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 313 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 314 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 315 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 316 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 317 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 318 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 319 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 320 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 321 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 322 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 323 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 324 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 325 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 326 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 327 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 328 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 329 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 330 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 331 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 332 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 333 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 334 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 335 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 336 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 337 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 338 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 339 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 340 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 341 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 342 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 343 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
