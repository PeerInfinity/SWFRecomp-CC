# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-27 05:37 UTC

**Git SHA**: `dfef7a9d69`

**Run Duration**: 162m 8s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **861** (70.5%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **887** (72.6%) |
| Failing | 334 |
| Total expected lines | 151253 |
| Matching lines | 105331 (69.6%) |
| Mismatched lines | 45922 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 330 | 98.8% |
| Runtime Error | 3 | 0.9% |
| Runtime Segfault | 1 | 0.3% |

## Passing Tests

**861 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 11.3s |  |
| 2 | `agal_compiler` | 13 | 5.5s |  |
| 3 | `air_hidden_lookup` | 2 | 3.9s |  |
| 4 | `all_classes/security/swf11` | 3 | 3.8s |  |
| 5 | `amf_custom_obj` | 26 | 4.0s |  |
| 6 | `amf_dictionary` | 9 | 3.9s |  |
| 7 | `amf_function` | 46 | 3.8s |  |
| 8 | `amf_invalid_date` | 2 | 4.0s |  |
| 9 | `amf_missing_prop` | 6 | 4.0s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.5s |  |
| 11 | `amf_setter_error` | 8 | 6.6s |  |
| 12 | `amf_vector` | 40 | 6.6s |  |
| 13 | `amf_xml` | 6 | 6.5s |  |
| 14 | `application_domain` | 4 | 6.6s |  |
| 15 | `array_access` | 18 | 6.6s |  |
| 16 | `array_access_interpreter` | 4 | 6.6s |  |
| 17 | `array_access_no_pubns` | 2 | 6.6s |  |
| 18 | `array_concat` | 41 | 6.5s |  |
| 19 | `array_constr` | 10 | 6.3s |  |
| 20 | `array_delete` | 44 | 6.7s |  |
| 21 | `array_enumeration` | 10 | 6.7s |  |
| 22 | `array_enumeration_elements` | 11 | 6.7s |  |
| 23 | `array_every` | 8 | 6.7s |  |
| 24 | `array_filter` | 6 | 6.5s |  |
| 25 | `array_foreach` | 18 | 6.6s |  |
| 26 | `array_hasownproperty` | 11 | 3.2s |  |
| 27 | `array_holes` | 9 | 6.5s |  |
| 28 | `array_index_max` | 84 | 6.5s |  |
| 29 | `array_indexof` | 25 | 6.4s |  |
| 30 | `array_join` | 26 | 6.4s |  |
| 31 | `array_lastindexof` | 29 | 6.3s |  |
| 32 | `array_length` | 14 | 6.4s |  |
| 33 | `array_literal` | 3 | 6.3s |  |
| 34 | `array_map` | 8 | 6.4s |  |
| 35 | `array_pop` | 52 | 6.6s |  |
| 36 | `array_push` | 24 | 6.4s |  |
| 37 | `array_reborrow_bug` | 6 | 6.3s |  |
| 38 | `array_reverse` | 28 | 6.3s |  |
| 39 | `array_shift` | 51 | 3.1s |  |
| 40 | `array_slice` | 39 | 6.4s |  |
| 41 | `array_some` | 8 | 6.3s |  |
| 42 | `array_sort` | 297 | 6.7s |  |
| 43 | `array_sort_fun_swf12` | 2 | 6.3s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 45 | `array_sort_random` | 210 | 6.3s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 6.3s |  |
| 47 | `array_sorton` | 545 | 4.4s |  |
| 48 | `array_sparse_ops` | 41 | 4.5s |  |
| 49 | `array_splice` | 133 | 4.0s |  |
| 50 | `array_splice2` | 428 | 4.1s |  |
| 51 | `array_splice_types` | 48 | 4.1s |  |
| 52 | `array_storage` | 8 | 3.9s |  |
| 53 | `array_tolocalestring` | 9 | 3.9s |  |
| 54 | `array_tostring` | 12 | 4.0s |  |
| 55 | `array_unshift` | 24 | 4.2s |  |
| 56 | `array_valueof` | 9 | 3.8s |  |
| 57 | `array_vector_null_callback` | 10 | 3.9s |  |
| 58 | `astype` | 28 | 4.0s |  |
| 59 | `astypelate` | 24 | 4.1s |  |
| 60 | `astypelate_propagates` | 1 | 4.0s |  |
| 61 | `asymmetric_key_events` | 11 | 4.2s |  |
| 62 | `avm2_catchup_dobj` | 158 | 4.5s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 56.9s |  |
| 64 | `bitand` | 1058 | 11.2s |  |
| 65 | `bitmap_constr` | 17 | 4.4s |  |
| 66 | `bitmap_data` | 1000 | 9.8s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 18.4s |  |
| 68 | `bitmap_properties` | 23 | 3.9s |  |
| 69 | `bitmap_subclass` | 7 | 5.0s |  |
| 70 | `bitmap_subclass_properties` | 9 | 4.9s |  |
| 71 | `bitmap_timeline` | 9 | 4.0s |  |
| 72 | `bitmapdata_accuracy` | 1 | 45.0s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 18.2s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.0s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 18.0s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 18.6s |  |
| 77 | `bitmapdata_clone` | 13 | 4.4s |  |
| 78 | `bitmapdata_colortransform` | 0 | 4.5s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 4.6s |  |
| 80 | `bitmapdata_constr` | 22 | 2.2s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 4.4s |  |
| 82 | `bitmapdata_copychannel` | 0 | 26.9s |  |
| 83 | `bitmapdata_copypixels` | 23 | 25.5s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.8s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.8s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.8s |  |
| 87 | `bitmapdata_draw` | 0 | 24.8s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.2s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 24.1s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 24.0s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 5.9s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.1s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.1s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 23.9s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 6.0s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.2s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.2s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 24.2s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.8s |  |
| 100 | `bitmapdata_getpixels` | 39 | 23.9s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 103 | `bitmapdata_hittest` | 112 | 6.3s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.8s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.1s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 24.0s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.2s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.7s |  |
| 109 | `bitmapdata_setpixels` | 286 | 6.0s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.8s |  |
| 111 | `bitmapdata_sync` | 0 | 6.0s |  |
| 112 | `bitmapdata_threshold` | 176 | 6.5s |  |
| 113 | `bitnot` | 46 | 5.8s |  |
| 114 | `bitor` | 1058 | 17.7s |  |
| 115 | `bitxor` | 1058 | 17.7s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.1s |  |
| 117 | `blend_scroll` | 0 | 6.1s |  |
| 118 | `boolean_constr` | 32 | 6.4s |  |
| 119 | `boolean_negation` | 30 | 6.3s |  |
| 120 | `boolean_tostring` | 8 | 6.3s |  |
| 121 | `broadcast_event` | 7 | 6.3s |  |
| 122 | `button_nested_frame` | 48 | 26.4s |  |
| 123 | `bytearray` | 48 | 6.5s |  |
| 124 | `bytearray_compress` | 31 | 6.5s |  |
| 125 | `bytearray_errors` | 24 | 6.5s |  |
| 126 | `bytearray_method_serialization` | 1 | 6.3s |  |
| 127 | `bytearray_oom` | 3 | 6.3s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 6.3s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 6.4s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 6.4s |  |
| 131 | `bytearray_serialization` | 3 | 6.3s |  |
| 132 | `bytearray_string_null` | 19 | 6.6s |  |
| 133 | `bytearray_tostring` | 15 | 6.4s |  |
| 134 | `bytearray_utf16` | 8 | 6.2s |  |
| 135 | `bytearray_writeobject` | 24 | 6.2s |  |
| 136 | `callee_in_initializer` | 6 | 6.2s |  |
| 137 | `callproplex_class` | 1 | 6.3s |  |
| 138 | `capabilities_resolution` | 8 | 27.7s |  |
| 139 | `catch_class` | 6 | 6.4s |  |
| 140 | `catch_scope_slot` | 7 | 3.2s |  |
| 141 | `checkfilter` | 4 | 3.1s |  |
| 142 | `class_call` | 32 | 26.6s |  |
| 143 | `class_cast_call` | 14 | 6.3s |  |
| 144 | `class_enumeration` | 4 | 6.3s |  |
| 145 | `class_has_own_property` | 2 | 6.4s |  |
| 146 | `class_init_interpreter_mode` | 1 | 6.2s |  |
| 147 | `class_is` | 32 | 6.6s |  |
| 148 | `class_methods` | 5 | 6.3s |  |
| 149 | `class_object_properties` | 10 | 6.3s |  |
| 150 | `class_singleton` | 18 | 6.4s |  |
| 151 | `class_supercalls_errors` | 35 | 6.6s |  |
| 152 | `class_supercalls_mismatched` | 26 | 6.6s |  |
| 153 | `class_superclass_wrong_order` | 1 | 24.4s |  |
| 154 | `class_to_locale_string` | 2 | 6.0s |  |
| 155 | `class_to_string` | 2 | 5.9s |  |
| 156 | `class_value_of` | 2 | 5.9s |  |
| 157 | `click_block` | 5 | 25.6s |  |
| 158 | `click_invisible` | 3 | 6.3s |  |
| 159 | `closures` | 12 | 6.2s |  |
| 160 | `coerce_return_type` | 40 | 6.3s |  |
| 161 | `coerce_return_type_fail` | 2 | 6.0s |  |
| 162 | `coerce_return_void` | 3 | 6.1s |  |
| 163 | `coerce_string` | 86 | 6.2s |  |
| 164 | `coerce_string_precision` | 28 | 6.1s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 6.2s |  |
| 166 | `construct_errors_swf10` | 8 | 6.2s |  |
| 167 | `construct_frame_list` | 22 | 25.4s |  |
| 168 | `constructor_call` | 3 | 6.1s |  |
| 169 | `constructors_vs_timeline` | 5 | 25.6s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 6.2s |  |
| 171 | `control_flow_bool` | 4 | 6.0s |  |
| 172 | `control_flow_stricteq` | 8 | 6.0s |  |
| 173 | `convert_boolean` | 30 | 6.0s |  |
| 174 | `convert_integer` | 90 | 6.2s |  |
| 175 | `convert_number` | 56 | 6.1s |  |
| 176 | `convert_uinteger` | 90 | 6.2s |  |
| 177 | `cryptscore` | 11 | 6.1s |  |
| 178 | `date` | 30 | 6.5s |  |
| 179 | `date_parse` | 36 | 6.2s |  |
| 180 | `declocal` | 46 | 6.2s |  |
| 181 | `declocal_i` | 46 | 6.2s |  |
| 182 | `decode_uri` | 71 | 6.5s |  |
| 183 | `decrement` | 46 | 6.1s |  |
| 184 | `decrement_i` | 46 | 3.0s |  |
| 185 | `default_values` | 7 | 6.1s |  |
| 186 | `dictionary_access` | 62 | 6.2s |  |
| 187 | `dictionary_access_no_pubns` | 2 | 5.9s |  |
| 188 | `dictionary_delete` | 101 | 6.5s |  |
| 189 | `dictionary_foreach` | 42 | 6.2s |  |
| 190 | `dictionary_hasownproperty` | 63 | 6.3s |  |
| 191 | `dictionary_in` | 62 | 6.2s |  |
| 192 | `dictionary_iter_modify` | 8 | 6.0s |  |
| 193 | `dictionary_namespaces` | 36 | 6.1s |  |
| 194 | `dictionary_primitive_keys` | 29 | 6.0s |  |
| 195 | `displayobject_alpha` | 277 | 6.0s |  |
| 196 | `displayobject_blendmode` | 0 | 6.2s |  |
| 197 | `displayobject_colortransform_nested` | 0 | 25.1s |  |
| 198 | `displayobject_from_enterframe` | 1 | 24.9s |  |
| 199 | `displayobject_getbounds_shape` | 0 | 23.7s |  |
| 200 | `displayobject_height` | 6052 | 24.0s |  |
| 201 | `displayobject_hittestobject` | 32 | 5.8s |  |
| 202 | `displayobject_invalid_floats` | 60 | 5.8s |  |
| 203 | `displayobject_invalid_props` | 3 | 2.7s |  |
| 204 | `displayobject_mask` | 3 | 6.2s |  |
| 205 | `displayobject_mask_self_referential` | 0 | 6.3s |  |
| 206 | `displayobject_metaData` | 3 | 6.2s |  |
| 207 | `displayobject_name` | 22 | 6.6s |  |
| 208 | `displayobject_name_from_timeline` | 24 | 6.5s |  |
| 209 | `displayobject_parent` | 12 | 6.3s |  |
| 210 | `displayobject_root` | 24 | 6.4s |  |
| 211 | `displayobject_rotation` | 1284 | 6.5s |  |
| 212 | `displayobject_set_matrix_nested` | 0 | 27.4s |  |
| 213 | `displayobject_subclass` | 2 | 6.3s |  |
| 214 | `displayobject_visible` | 23 | 6.3s |  |
| 215 | `displayobject_width` | 4852 | 26.9s |  |
| 216 | `displayobject_x` | 614 | 6.5s |  |
| 217 | `displayobject_y` | 617 | 6.4s |  |
| 218 | `displayobjectcontainer_addchild` | 32 | 6.5s |  |
| 219 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.3s |  |
| 220 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.6s |  |
| 221 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.5s |  |
| 222 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.5s |  |
| 223 | `displayobjectcontainer_addchildat` | 42 | 6.5s |  |
| 224 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.2s |  |
| 225 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.5s |  |
| 226 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.5s |  |
| 227 | `displayobjectcontainer_contains` | 66 | 27.0s |  |
| 228 | `displayobjectcontainer_getchildat` | 4 | 6.5s |  |
| 229 | `displayobjectcontainer_getchildbyname` | 9 | 6.4s |  |
| 230 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.4s |  |
| 231 | `displayobjectcontainer_getchildindex` | 28 | 6.3s |  |
| 232 | `displayobjectcontainer_removechild` | 10 | 6.3s |  |
| 233 | `displayobjectcontainer_removechild_errors` | 4 | 6.4s |  |
| 234 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.5s |  |
| 235 | `displayobjectcontainer_removechildat` | 18 | 6.5s |  |
| 236 | `displayobjectcontainer_removechildren` | 51 | 6.8s |  |
| 237 | `displayobjectcontainer_setchildindex` | 42 | 6.4s |  |
| 238 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.9s |  |
| 239 | `displayobjectcontainer_swapchildren` | 42 | 6.5s |  |
| 240 | `displayobjectcontainer_swapchildrenat` | 42 | 6.5s |  |
| 241 | `displayobjectcontainer_timelineinstance` | 48 | 25.6s |  |
| 242 | `divide` | 1058 | 18.7s |  |
| 243 | `doabc_is_eager` | 1 | 24.6s |  |
| 244 | `documentclass` | 9 | 6.1s |  |
| 245 | `domain_memory` | 133 | 7.2s |  |
| 246 | `drag_drop` | 10 | 6.2s |  |
| 247 | `duplicate_defs` | 1 | 5.8s |  |
| 248 | `eager_init` | 1 | 6.0s |  |
| 249 | `edit_text_linkage` | 7 | 6.1s |  |
| 250 | `edittext_always_show_selection` | 0 | 25.9s |  |
| 251 | `edittext_antialiastype` | 296 | 6.3s |  |
| 252 | `edittext_at_point_methods_basic` | 16 | 7.4s |  |
| 253 | `edittext_autosize` | 39 | 6.4s |  |
| 254 | `edittext_autosize_align` | 0 | 26.1s |  |
| 255 | `edittext_autosize_height_dynamic` | 60 | 25.6s |  |
| 256 | `edittext_autosize_height_input` | 60 | 6.1s |  |
| 257 | `edittext_autosize_lazy_bounds_events` | 65 | 6.4s |  |
| 258 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.2s |  |
| 259 | `edittext_autosize_lazy_bounds_props` | 490 | 7.5s |  |
| 260 | `edittext_autosize_lazy_bounds_visual` | 0 | 24.8s |  |
| 261 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.3s |  |
| 262 | `edittext_bottom_scroll_v_basic` | 210 | 6.2s |  |
| 263 | `edittext_bounds_scale` | 24 | 25.1s |  |
| 264 | `edittext_bullet` | 30 | 6.3s |  |
| 265 | `edittext_default_format` | 221 | 6.4s |  |
| 266 | `edittext_default_format_empty` | 136 | 6.3s |  |
| 267 | `edittext_empty_text_format` | 7 | 6.2s |  |
| 268 | `edittext_focus_selection` | 5 | 6.1s |  |
| 269 | `edittext_font_size` | 45 | 6.2s |  |
| 270 | `edittext_format_empty_font` | 8 | 6.0s |  |
| 271 | `edittext_get_char_index_at_point` | 4 | 26.3s |  |
| 272 | `edittext_get_line_index_at_point` | 2 | 25.6s |  |
| 273 | `edittext_get_line_index_of_char` | 76 | 7.1s |  |
| 274 | `edittext_getcharboundaries` | 172 | 6.5s |  |
| 275 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.2s |  |
| 276 | `edittext_getcharboundaries_scroll` | 85 | 6.0s |  |
| 277 | `edittext_getlinemetrics` | 146 | 6.0s |  |
| 278 | `edittext_html` | 3101 | 6.3s |  |
| 279 | `edittext_html_condensewhite` | 487 | 5.9s |  |
| 280 | `edittext_html_entity` | 4 | 6.1s |  |
| 281 | `edittext_html_font_size_swf12` | 267 | 5.9s |  |
| 282 | `edittext_html_font_size_swf13` | 273 | 5.6s |  |
| 283 | `edittext_html_roundtrip` | 17 | 5.8s |  |
| 284 | `edittext_input_control` | 12 | 6.0s |  |
| 285 | `edittext_leading` | 9 | 6.1s |  |
| 286 | `edittext_letter_spacing` | 15 | 5.8s |  |
| 287 | `edittext_line_methods` | 294 | 7.1s |  |
| 288 | `edittext_line_metrics` | 11 | 25.4s |  |
| 289 | `edittext_margins` | 25 | 5.9s |  |
| 290 | `edittext_max_scroll_h_basic` | 475 | 6.1s |  |
| 291 | `edittext_max_scroll_v_basic` | 1000 | 6.0s |  |
| 292 | `edittext_mousedown` | 3 | 6.2s |  |
| 293 | `edittext_mouseenabled` | 26 | 5.9s |  |
| 294 | `edittext_newline_character` | 22 | 5.8s |  |
| 295 | `edittext_newline_stripping` | 64 | 8.4s |  |
| 296 | `edittext_newlines` | 30 | 6.0s |  |
| 297 | `edittext_paragraph_methods` | 257 | 5.9s |  |
| 298 | `edittext_paste_events` | 8 | 5.9s |  |
| 299 | `edittext_paste_maxchars` | 4 | 5.9s |  |
| 300 | `edittext_paste_restrict` | 16 | 5.8s |  |
| 301 | `edittext_restrict` | 191 | 5.9s |  |
| 302 | `edittext_restrict_events` | 22 | 5.9s |  |
| 303 | `edittext_scrollh` | 10 | 2.7s |  |
| 304 | `edittext_selected_text` | 9 | 5.8s |  |
| 305 | `edittext_set_html_same` | 17 | 5.8s |  |
| 306 | `edittext_set_text_vs_html` | 9 | 5.8s |  |
| 307 | `edittext_stylesheet` | 536 | 6.2s |  |
| 308 | `edittext_stylesheet_custom_tag` | 76 | 5.9s |  |
| 309 | `edittext_stylesheet_display` | 272 | 5.9s |  |
| 310 | `edittext_underline` | 40 | 5.9s |  |
| 311 | `edittext_width_height` | 103 | 6.5s |  |
| 312 | `edittext_wordwrap_word` | 150 | 6.6s |  |
| 313 | `edittext_wrap_breaks` | 2375 | 6.8s |  |
| 314 | `empty_bounds` | 1 | 6.1s |  |
| 315 | `encode_uri_surrogate_pair_swf11` | 15 | 5.9s |  |
| 316 | `equals` | 512 | 10.6s |  |
| 317 | `error_geterrormessage` | 779 | 6.2s |  |
| 318 | `error_prototype` | 15 | 6.2s |  |
| 319 | `error_stack_trace_debug_swf17` | 0 | 26.1s |  |
| 320 | `error_stack_trace_debug_swf18` | 0 | 6.0s |  |
| 321 | `error_stack_trace_release_swf17` | 0 | 6.1s |  |
| 322 | `error_stack_trace_release_swf18` | 0 | 6.0s |  |
| 323 | `error_tostring` | 29 | 6.1s |  |
| 324 | `es3_inheritance` | 31 | 6.2s |  |
| 325 | `es4_inheritance` | 30 | 6.2s |  |
| 326 | `es4_interfaces` | 30 | 6.2s |  |
| 327 | `es4_method_binding` | 8 | 3.0s |  |
| 328 | `es4_oop_prototypes` | 14 | 6.4s |  |
| 329 | `es4_protected_inheritance` | 6 | 6.2s |  |
| 330 | `escape` | 71 | 6.2s |  |
| 331 | `event_bubbles` | 2 | 6.2s |  |
| 332 | `event_cancelable` | 2 | 6.1s |  |
| 333 | `event_clone` | 20 | 6.2s |  |
| 334 | `event_clone_error_redispatch` | 3 | 6.3s |  |
| 335 | `event_clone_on_redispatch` | 10 | 6.3s |  |
| 336 | `event_formattostring` | 31 | 6.2s |  |
| 337 | `event_isdefaultprevented` | 12 | 6.2s |  |
| 338 | `event_target_getter` | 5 | 3.0s |  |
| 339 | `event_target_set` | 9 | 6.1s |  |
| 340 | `event_type` | 1 | 5.7s |  |
| 341 | `event_valueof_tostring` | 18 | 5.7s |  |
| 342 | `eventdispatcher_dispatchevent` | 12 | 5.7s |  |
| 343 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.8s |  |
| 344 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.6s |  |
| 345 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.6s |  |
| 346 | `eventdispatcher_dispatchevent_this` | 5 | 5.5s |  |
| 347 | `eventdispatcher_haseventlistener` | 25 | 5.6s |  |
| 348 | `eventdispatcher_interface_invoke` | 1 | 5.5s |  |
| 349 | `eventdispatcher_tostring` | 10 | 5.7s |  |
| 350 | `eventdispatcher_willtrigger` | 25 | 5.6s |  |
| 351 | `falsiness` | 30 | 5.8s |  |
| 352 | `fast_index_access` | 12 | 5.8s |  |
| 353 | `finddef` | 3 | 5.8s |  |
| 354 | `findprop_global_prototype` | 6 | 5.8s |  |
| 355 | `flash_xml` | 29 | 5.7s |  |
| 356 | `flash_xml_cloneNode` | 22 | 5.8s |  |
| 357 | `flash_xml_namespace` | 109 | 5.7s |  |
| 358 | `flash_xml_removeNode` | 60 | 5.8s |  |
| 359 | `focus_events_code` | 161 | 25.5s |  |
| 360 | `focus_events_key_same_object` | 26 | 5.9s |  |
| 361 | `focus_events_mixed_key_mouse` | 100 | 25.1s |  |
| 362 | `focus_events_mouse_same_object` | 40 | 24.1s |  |
| 363 | `focus_remove` | 20 | 24.1s |  |
| 364 | `focus_root_movie` | 4 | 24.1s |  |
| 365 | `focus_stage` | 1 | 5.9s |  |
| 366 | `focusrect` | 18 | 6.7s |  |
| 367 | `font_description_clone` | 14 | 5.8s |  |
| 368 | `font_embedded` | 24 | 6.2s |  |
| 369 | `font_enumeratefonts` | 41 | 6.5s |  |
| 370 | `font_enumeratefonts_filter` | 4 | 25.1s |  |
| 371 | `font_hasglyphs` | 40 | 6.2s |  |
| 372 | `framelabel_constr` | 5 | 5.8s |  |
| 373 | `function_call` | 12 | 5.9s |  |
| 374 | `function_call_arguments` | 46 | 6.0s |  |
| 375 | `function_call_arguments_enumerate` | 5 | 5.8s |  |
| 376 | `function_call_coercion` | 108 | 6.3s |  |
| 377 | `function_call_default` | 6 | 5.9s |  |
| 378 | `function_call_rest` | 22 | 5.8s |  |
| 379 | `function_call_types` | 3 | 5.8s |  |
| 380 | `function_call_via_apply` | 11 | 5.8s |  |
| 381 | `function_call_via_call` | 3 | 5.8s |  |
| 382 | `function_display_anonymous` | 7 | 2.8s |  |
| 383 | `function_length` | 6 | 5.9s |  |
| 384 | `function_object` | 2 | 5.8s |  |
| 385 | `function_proto` | 5 | 5.8s |  |
| 386 | `function_proto_created` | 61 | 5.9s |  |
| 387 | `function_to_locale_string` | 4 | 5.8s |  |
| 388 | `function_to_string` | 4 | 5.7s |  |
| 389 | `function_type` | 6 | 5.8s |  |
| 390 | `function_unbound_this` | 51 | 5.9s |  |
| 391 | `function_value_of` | 4 | 5.8s |  |
| 392 | `get_definition_by_name` | 11 | 5.8s |  |
| 393 | `get_qualified_class_name` | 20 | 6.0s |  |
| 394 | `get_qualified_super_class_name` | 18 | 6.0s |  |
| 395 | `get_slot_edge_cases` | 1 | 24.3s |  |
| 396 | `get_timer` | 2 | 6.0s |  |
| 397 | `getglobalslot` | 1 | 5.9s |  |
| 398 | `getouterscope` | 8 | 5.8s |  |
| 399 | `getter_different_namespace_setter` | 2 | 5.6s |  |
| 400 | `goto_button_nested_framescript` | 28 | 24.5s |  |
| 401 | `goto_in_constructframe` | 12 | 6.2s |  |
| 402 | `goto_in_scene_last_frame` | 2 | 24.4s |  |
| 403 | `goto_methods` | 56 | 6.2s |  |
| 404 | `goto_methods_swfver10` | 8 | 5.9s |  |
| 405 | `goto_nested_construct_sibling` | 18 | 6.3s |  |
| 406 | `goto_nested_framescript` | 9 | 6.1s |  |
| 407 | `goto_on_orphan` | 15 | 6.2s |  |
| 408 | `graphics_bad_direct_commands` | 5 | 6.7s |  |
| 409 | `graphics_bitmap_fill` | 0 | 7.9s |  |
| 410 | `graphics_bitmaps` | 0 | 6.7s |  |
| 411 | `graphics_direct_commands` | 0 | 6.6s |  |
| 412 | `graphics_draw_triangles` | 98 | 25.9s |  |
| 413 | `graphics_gradients` | 0 | 6.4s |  |
| 414 | `graphics_gradients_nulls` | 0 | 6.2s |  |
| 415 | `graphics_path` | 56 | 6.0s |  |
| 416 | `graphics_round_rects` | 0 | 6.0s |  |
| 417 | `graphics_simple_shapes` | 0 | 6.4s |  |
| 418 | `greaterequals` | 512 | 10.3s |  |
| 419 | `greaterthan` | 512 | 10.1s |  |
| 420 | `has_own_property` | 102 | 6.4s |  |
| 421 | `hasownproperty_namespaces` | 2 | 5.9s |  |
| 422 | `hello_world` | 1 | 5.8s |  |
| 423 | `hittest_morph` | 30 | 6.1s |  |
| 424 | `if_eq` | 10 | 6.0s |  |
| 425 | `if_gt` | 1 | 6.0s |  |
| 426 | `if_gte` | 10 | 6.1s |  |
| 427 | `if_lt` | 1 | 6.2s |  |
| 428 | `if_lte` | 10 | 6.0s |  |
| 429 | `if_ne` | 7 | 3.0s |  |
| 430 | `if_stricteq` | 6 | 6.1s |  |
| 431 | `if_strictne` | 11 | 6.0s |  |
| 432 | `in` | 102 | 6.4s |  |
| 433 | `inclocal` | 46 | 6.0s |  |
| 434 | `inclocal_i` | 46 | 6.1s |  |
| 435 | `increment` | 46 | 6.1s |  |
| 436 | `increment_i` | 46 | 6.0s |  |
| 437 | `indexing_delete` | 75 | 6.0s |  |
| 438 | `instanceof` | 58 | 6.2s |  |
| 439 | `instantiation_on_enter_frame` | 7 | 24.8s |  |
| 440 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.9s |  |
| 441 | `int_constr` | 92 | 5.9s |  |
| 442 | `int_edge_cases` | 19 | 6.0s |  |
| 443 | `int_instanceof` | 3 | 5.9s |  |
| 444 | `int_tofixed` | 1215 | 5.9s |  |
| 445 | `int_tostring` | 3375 | 5.9s |  |
| 446 | `interactiveobject_enabled` | 25 | 5.9s |  |
| 447 | `interface_namespaces` | 78 | 6.2s |  |
| 448 | `is_finite` | 46 | 6.1s |  |
| 449 | `is_nan` | 46 | 5.9s |  |
| 450 | `is_prototype_of` | 12 | 6.0s |  |
| 451 | `issue_10221` | 2 | 6.0s |  |
| 452 | `issue_13780` | 12 | 6.0s |  |
| 453 | `issue_14901` | 1 | 6.0s |  |
| 454 | `issue_17675_edittext_paste_maxchars` | 1 | 6.0s |  |
| 455 | `issue_5292` | 5 | 6.0s |  |
| 456 | `issue_8630` | 2 | 24.4s |  |
| 457 | `issue_8630_scriptremove` | 11 | 5.9s |  |
| 458 | `istype` | 24 | 2.9s |  |
| 459 | `istypelate` | 58 | 6.3s |  |
| 460 | `istypelate_coerce` | 198 | 7.5s |  |
| 461 | `jpeg_loader_context` | 6 | 6.4s |  |
| 462 | `json_errors` | 9 | 25.9s |  |
| 463 | `json_parse` | 21 | 6.4s |  |
| 464 | `json_stringify` | 12 | 6.5s |  |
| 465 | `json_stringify_order` | 1 | 6.3s |  |
| 466 | `json_version_gated` | 1 | 6.2s |  |
| 467 | `key_input_80percent` | 1812 | 6.4s |  |
| 468 | `key_input_location` | 126 | 6.2s |  |
| 469 | `key_input_numpad` | 384 | 6.3s |  |
| 470 | `lazyinit` | 17 | 6.3s |  |
| 471 | `lessequals` | 512 | 10.2s |  |
| 472 | `lessthan` | 512 | 10.4s |  |
| 473 | `loader_bitmap_transparency` | 14 | 6.5s |  |
| 474 | `loader_bytes_unknown_content` | 14 | 6.4s |  |
| 475 | `loader_image` | 8 | 7.1s |  |
| 476 | `loader_jpegxr` | 2 | 26.3s |  |
| 477 | `loader_jpegxr_alpha` | 1 | 26.1s |  |
| 478 | `loader_loadbytes_invalid_png` | 4 | 25.8s |  |
| 479 | `loader_unknown_content` | 24 | 6.4s |  |
| 480 | `loader_visibility_interactive` | 1 | 6.3s |  |
| 481 | `loaderinfo_events` | 7 | 6.1s |  |
| 482 | `loaderinfo_loadurl` | 12 | 5.8s |  |
| 483 | `loaderinfo_more` | 6 | 6.1s |  |
| 484 | `loaderinfo_properties` | 18 | 5.8s |  |
| 485 | `loaderinfo_properties_not_loaded` | 23 | 6.0s |  |
| 486 | `loaderinfo_root` | 10 | 5.8s |  |
| 487 | `loaderinfo_root_allows` | 2 | 5.8s |  |
| 488 | `lshift` | 1058 | 17.9s |  |
| 489 | `mask_reapply` | 1 | 6.0s |  |
| 490 | `math` | 497 | 6.1s |  |
| 491 | `missing_external_interface` | 10 | 5.9s |  |
| 492 | `modulo` | 1058 | 17.9s |  |
| 493 | `morph_shape` | 2 | 24.0s |  |
| 494 | `mouse_click_events` | 90 | 24.1s |  |
| 495 | `mouse_double_click_events` | 188 | 5.9s |  |
| 496 | `mouse_empty_parent` | 4 | 5.9s |  |
| 497 | `mouse_over_while_dragging` | 3 | 5.8s |  |
| 498 | `mouse_pick_button_mode` | 2 | 5.9s |  |
| 499 | `mouse_sibling` | 8 | 5.9s |  |
| 500 | `movieclip_addframescript` | 3 | 23.8s |  |
| 501 | `movieclip_child_property` | 16 | 5.9s |  |
| 502 | `movieclip_constr` | 21 | 4.7s |  |
| 503 | `movieclip_currentlabels` | 17 | 20.5s |  |
| 504 | `movieclip_currentlabels_dupes1` | 46 | 20.8s |  |
| 505 | `movieclip_currentlabels_dupes2` | 30 | 4.8s |  |
| 506 | `movieclip_currentlabels_dupes3` | 67 | 4.7s |  |
| 507 | `movieclip_currentscene` | 12 | 4.7s |  |
| 508 | `movieclip_dispatchevent` | 430 | 4.8s |  |
| 509 | `movieclip_dispatchevent_cancel` | 102 | 4.8s |  |
| 510 | `movieclip_dispatchevent_handlerorder` | 251 | 4.8s |  |
| 511 | `movieclip_dispatchevent_selfadd` | 80 | 4.7s |  |
| 512 | `movieclip_dispatchevent_target` | 899 | 4.8s |  |
| 513 | `movieclip_displayevents` | 96 | 20.6s |  |
| 514 | `movieclip_displayevents_clickgoto` | 676 | 5.0s |  |
| 515 | `movieclip_displayevents_clickgoto2` | 2001 | 5.1s |  |
| 516 | `movieclip_displayevents_clickplay` | 575 | 4.8s |  |
| 517 | `movieclip_displayevents_clicksymbol` | 562 | 4.9s |  |
| 518 | `movieclip_displayevents_constructframegoto` | 140 | 4.9s |  |
| 519 | `movieclip_displayevents_constructframeplay` | 50 | 4.9s |  |
| 520 | `movieclip_displayevents_constructframesymbol` | 144 | 4.8s |  |
| 521 | `movieclip_displayevents_dblhandler` | 21 | 4.8s |  |
| 522 | `movieclip_displayevents_enterframegoto` | 149 | 5.0s |  |
| 523 | `movieclip_displayevents_enterframeplay` | 48 | 4.8s |  |
| 524 | `movieclip_displayevents_enterframesymbol` | 149 | 20.5s |  |
| 525 | `movieclip_displayevents_exitframegoto` | 106 | 4.8s |  |
| 526 | `movieclip_displayevents_exitframeplay` | 44 | 4.9s |  |
| 527 | `movieclip_displayevents_exitframesymbol` | 135 | 4.8s |  |
| 528 | `movieclip_displayevents_looping` | 63 | 20.6s |  |
| 529 | `movieclip_displayevents_stopped` | 113 | 5.2s |  |
| 530 | `movieclip_displayevents_swap` | 96 | 1.9s |  |
| 531 | `movieclip_displayevents_timeline` | 128 | 20.7s |  |
| 532 | `movieclip_drawrect` | 54 | 4.7s |  |
| 533 | `movieclip_frameconstruct_skipped` | 9 | 4.8s |  |
| 534 | `movieclip_goto_during_frame_script` | 15 | 4.8s |  |
| 535 | `movieclip_goto_overwrite` | 14 | 20.4s |  |
| 536 | `movieclip_goto_scene_last_frame_int` | 1 | 20.6s |  |
| 537 | `movieclip_goto_scene_last_frame_label` | 1 | 2.3s |  |
| 538 | `movieclip_gotoandplay` | 15 | 20.5s |  |
| 539 | `movieclip_gotoandstop` | 13 | 4.7s |  |
| 540 | `movieclip_gotoandstop_children` | 4 | 4.8s |  |
| 541 | `movieclip_gotoandstop_framescripts1` | 4 | 4.8s |  |
| 542 | `movieclip_gotoandstop_framescripts2` | 4 | 2.2s |  |
| 543 | `movieclip_gotoandstop_framescripts_self` | 7 | 25.6s |  |
| 544 | `movieclip_gotoandstop_queueing` | 12 | 25.5s |  |
| 545 | `movieclip_next_frame` | 2 | 6.2s |  |
| 546 | `movieclip_next_scene` | 6 | 25.3s |  |
| 547 | `movieclip_play` | 3 | 2.9s |  |
| 548 | `movieclip_prev_frame` | 3 | 5.9s |  |
| 549 | `movieclip_prev_scene` | 7 | 6.1s |  |
| 550 | `movieclip_properties` | 79 | 6.4s |  |
| 551 | `movieclip_queued_noop_goto_swf10` | 9 | 6.2s |  |
| 552 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 553 | `movieclip_scenes` | 11 | 6.1s |  |
| 554 | `movieclip_soundtransform` | 831 | 27.7s |  |
| 555 | `movieclip_stop` | 1 | 6.1s |  |
| 556 | `movieclip_super_is_symbol` | 20 | 6.5s |  |
| 557 | `movieclip_symbol_constr` | 8 | 6.2s |  |
| 558 | `movieclip_text_mousedown` | 1 | 6.2s |  |
| 559 | `movieclip_willtrigger` | 5 | 6.1s |  |
| 560 | `multiply` | 1058 | 18.4s |  |
| 561 | `namespace_constr` | 253 | 6.4s |  |
| 562 | `namespace_constr_args` | 1 | 6.0s |  |
| 563 | `namespace_enumeration_order` | 7 | 6.1s |  |
| 564 | `nan_scale` | 9 | 6.0s |  |
| 565 | `navigateToURL_target_normalize` | 107 | 26.0s |  |
| 566 | `negate` | 30 | 6.2s |  |
| 567 | `negative_volume_panned` | 0 | 6.3s |  |
| 568 | `nested_iteration` | 11 | 6.2s |  |
| 569 | `net_getClassByAlias` | 3 | 6.2s |  |
| 570 | `net_navigateToURL` | 57 | 6.2s |  |
| 571 | `newactivation_in_script_init` | 3 | 5.7s |  |
| 572 | `newclass_twice` | 3 | 5.8s |  |
| 573 | `nonconflicting_declarations` | 0 | 5.8s |  |
| 574 | `null_void_types` | 8 | 5.8s |  |
| 575 | `number_autoconv` | 21 | 2.8s |  |
| 576 | `number_autoconv_amf` | 132 | 5.8s |  |
| 577 | `number_autoconv_array_sort_32bit` | 1 | 5.8s |  |
| 578 | `number_constr` | 58 | 5.9s |  |
| 579 | `number_toexponential` | 378 | 5.8s |  |
| 580 | `number_toexponential2` | 35 | 5.8s |  |
| 581 | `number_tofixed` | 378 | 5.7s |  |
| 582 | `number_toprecision` | 350 | 5.8s |  |
| 583 | `obfuscated_class_names` | 3 | 5.8s |  |
| 584 | `object_enumeration` | 10 | 5.8s |  |
| 585 | `object_prototype` | 4 | 5.8s |  |
| 586 | `object_to_locale_string` | 2 | 5.8s |  |
| 587 | `object_to_string` | 2 | 5.7s |  |
| 588 | `object_value_of` | 2 | 2.6s |  |
| 589 | `op_coerce` | 54 | 2.8s |  |
| 590 | `op_coerce_x` | 54 | 5.9s |  |
| 591 | `op_escxattr` | 2 | 5.8s |  |
| 592 | `op_escxelem` | 2 | 5.8s |  |
| 593 | `op_lookupswitch` | 4 | 5.8s |  |
| 594 | `optimize_coerce` | 1 | 5.7s |  |
| 595 | `orphan_movie_complex` | 80 | 6.2s |  |
| 596 | `orphan_movie_reorder` | 111 | 24.4s |  |
| 597 | `package_namespace` | 7 | 5.7s |  |
| 598 | `param_default_value_has_zero_cpool_index` | 1 | 5.8s |  |
| 599 | `parent_early_access_child` | 16 | 5.9s |  |
| 600 | `parse_float` | 81 | 6.0s |  |
| 601 | `pixelbender_effect_BlurredFocus` | 0 | 23.4s |  |
| 602 | `pixelbender_effect_glassDisplace` | 0 | 8.9s |  |
| 603 | `pixelbender_effect_smudge` | 0 | 7.4s |  |
| 604 | `pixelbender_effect_tintype` | 0 | 6.8s |  |
| 605 | `pixelbender_effect_twirl` | 0 | 7.6s |  |
| 606 | `pixelbender_images` | 0 | 6.5s |  |
| 607 | `place_multiple` | 17 | 20.3s |  |
| 608 | `place_object_replace` | 9 | 4.7s |  |
| 609 | `place_object_replace_2` | 24 | 4.6s |  |
| 610 | `place_object_same_depth_frame` | 1 | 4.7s |  |
| 611 | `point` | 132 | 5.0s |  |
| 612 | `primitive_edge_cases` | 1 | 4.5s |  |
| 613 | `property_priority` | 22 | 6.3s |  |
| 614 | `property_priority_three_level` | 6 | 24.4s |  |
| 615 | `propertyisenumerable_namespaces` | 6 | 6.0s |  |
| 616 | `prototype_set_null` | 7 | 6.0s |  |
| 617 | `proxy_callproperty` | 24 | 6.0s |  |
| 618 | `proxy_deleteproperty` | 64 | 6.1s |  |
| 619 | `proxy_enumeration` | 34 | 6.1s |  |
| 620 | `proxy_getproperty` | 77 | 6.2s |  |
| 621 | `proxy_hasownproperty` | 8 | 6.0s |  |
| 622 | `proxy_hasproperty` | 32 | 6.0s |  |
| 623 | `proxy_serialize` | 9 | 5.9s |  |
| 624 | `proxy_setproperty` | 42 | 6.1s |  |
| 625 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.9s |  |
| 626 | `qname_constr` | 32 | 6.0s |  |
| 627 | `qname_constr_namespace` | 24 | 6.2s |  |
| 628 | `qname_enumeration` | 9 | 6.0s |  |
| 629 | `qname_indexing` | 23 | 6.0s |  |
| 630 | `qname_tostring` | 25 | 6.0s |  |
| 631 | `qname_valueof` | 29 | 6.0s |  |
| 632 | `regexp_constr` | 148 | 6.2s |  |
| 633 | `regexp_exec` | 19 | 6.1s |  |
| 634 | `regexp_extended` | 47 | 6.1s |  |
| 635 | `regexp_multiargs` | 1 | 5.9s |  |
| 636 | `regexp_test` | 27 | 2.9s |  |
| 637 | `regexp_toString` | 10 | 6.0s |  |
| 638 | `register_script_refresh` | 35 | 6.3s |  |
| 639 | `remove_child_clear_field` | 88 | 6.3s |  |
| 640 | `remove_dobj` | 3 | 5.9s |  |
| 641 | `resolve_order` | 4 | 5.9s |  |
| 642 | `rng` | 1 | 7.2s |  |
| 643 | `rootless` | 42 | 6.1s |  |
| 644 | `rshift` | 1058 | 18.5s |  |
| 645 | `sandbox_type_local_file` | 1 | 5.8s |  |
| 646 | `scene_constr` | 8 | 5.8s |  |
| 647 | `set_local_0` | 31 | 5.9s |  |
| 648 | `set_property_is_enumerable` | 85 | 6.3s |  |
| 649 | `shape_drawrect` | 54 | 5.9s |  |
| 650 | `shared_object_no_root` | 3 | 5.8s |  |
| 651 | `simplebutton_added_to_stage` | 45 | 24.0s |  |
| 652 | `simplebutton_childevents` | 86 | 24.5s |  |
| 653 | `simplebutton_childevents_nested` | 54 | 6.2s |  |
| 654 | `simplebutton_childevents_sprite` | 13 | 5.9s |  |
| 655 | `simplebutton_childprops` | 144 | 6.1s |  |
| 656 | `simplebutton_childshuffle` | 23 | 5.8s |  |
| 657 | `simplebutton_constr` | 36 | 6.1s |  |
| 658 | `simplebutton_constr_childevents` | 48 | 6.1s |  |
| 659 | `simplebutton_constr_params` | 42 | 6.0s |  |
| 660 | `simplebutton_mouseenabled` | 26 | 5.8s |  |
| 661 | `simplebutton_multi_children` | 19 | 6.0s |  |
| 662 | `simplebutton_structure` | 27 | 6.1s |  |
| 663 | `simplebutton_symbolclass` | 68 | 6.1s |  |
| 664 | `slot_disp_id_shared_numbering` | 1 | 23.7s |  |
| 665 | `slots_force_autoassigned` | 1 | 5.9s |  |
| 666 | `sound_embeddedprops` | 26 | 6.1s |  |
| 667 | `sound_play` | 19 | 6.1s |  |
| 668 | `sound_valueof` | 33 | 6.0s |  |
| 669 | `soundchannel_soundtransform` | 835 | 26.2s |  |
| 670 | `soundchannel_soundtransform_exists` | 5 | 24.2s |  |
| 671 | `soundchannel_stop` | 8 | 6.1s |  |
| 672 | `soundmixer_buffertime` | 5 | 5.9s |  |
| 673 | `soundmixer_stopall` | 6 | 6.0s |  |
| 674 | `soundtransform` | 442 | 8.6s |  |
| 675 | `sprite_with_frames` | 0 | 24.9s |  |
| 676 | `stage3d_agal_cross_product` | 0 | 8.6s |  |
| 677 | `stage3d_bitmap` | 0 | 29.6s |  |
| 678 | `stage3d_float1_index` | 0 | 26.8s |  |
| 679 | `stage3d_fractal` | 0 | 27.4s |  |
| 680 | `stage3d_ignore_sampler_override` | 0 | 27.4s |  |
| 681 | `stage3d_program_constants_bytearray_be` | 0 | 28.4s |  |
| 682 | `stage3d_program_constants_bytearray_le` | 0 | 9.3s |  |
| 683 | `stage3d_raytrace` | 0 | 30.5s |  |
| 684 | `stage3d_rotating_cube` | 0 | 9.6s |  |
| 685 | `stage3d_sampler` | 0 | 8.8s |  |
| 686 | `stage3d_sampler_partial_upload` | 0 | 8.7s |  |
| 687 | `stage3d_stencil` | 0 | 27.7s |  |
| 688 | `stage3d_texture` | 0 | 13.3s |  |
| 689 | `stage3d_texture_bytearray` | 0 | 9.9s |  |
| 690 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.3s |  |
| 691 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.4s |  |
| 692 | `stage3d_triangle` | 0 | 8.9s |  |
| 693 | `stage3d_triangle_bytes4` | 0 | 8.9s |  |
| 694 | `stage3d_triangle_float1` | 0 | 8.9s |  |
| 695 | `stage3d_triangle_index_upload` | 0 | 8.8s |  |
| 696 | `stage_access` | 10 | 2.8s |  |
| 697 | `stage_displayobject_properties` | 24 | 5.8s |  |
| 698 | `stage_framerate_nan` | 7 | 2.9s |  |
| 699 | `stage_framerate_negative` | 6 | 5.9s |  |
| 700 | `stage_framerate_zero` | 6 | 5.9s |  |
| 701 | `stage_invalidate` | 38 | 6.0s |  |
| 702 | `stage_loaderinfo_properties` | 24 | 6.0s |  |
| 703 | `stage_mousechildren` | 2 | 5.8s |  |
| 704 | `stage_mouseenabled` | 15 | 5.7s |  |
| 705 | `stage_overriden_setters` | 31 | 6.0s |  |
| 706 | `stage_properties` | 30 | 5.8s |  |
| 707 | `static_var_with_this_in_ctor` | 2 | 5.9s |  |
| 708 | `stored_properties` | 11 | 6.0s |  |
| 709 | `strict_equality` | 34 | 6.0s |  |
| 710 | `string_call` | 13 | 6.0s |  |
| 711 | `string_case` | 23 | 5.9s |  |
| 712 | `string_char_at` | 27 | 5.9s |  |
| 713 | `string_char_code_at` | 28 | 5.8s |  |
| 714 | `string_concat_fromcharcode` | 37 | 5.7s |  |
| 715 | `string_constr` | 25 | 5.9s |  |
| 716 | `string_indexof_lastindexof` | 87 | 25.7s |  |
| 717 | `string_length` | 16 | 6.1s |  |
| 718 | `string_locale_compare` | 39 | 6.5s |  |
| 719 | `string_match` | 51 | 6.3s |  |
| 720 | `string_relational_compare` | 4 | 6.1s |  |
| 721 | `string_replace` | 51 | 6.3s |  |
| 722 | `string_search` | 41 | 6.3s |  |
| 723 | `string_slice_substr_substring` | 170 | 7.4s |  |
| 724 | `string_split` | 29 | 6.4s |  |
| 725 | `string_substr_negative` | 21 | 6.1s |  |
| 726 | `string_substr_weird` | 182 | 6.1s |  |
| 727 | `subtract` | 1058 | 18.6s |  |
| 728 | `super_get_call` | 12 | 6.2s |  |
| 729 | `supercall_two_classobjects` | 2 | 6.1s |  |
| 730 | `swf8` | 1 | 6.1s |  |
| 731 | `swf_10_queued_goto_scripts_construct` | 52 | 6.5s |  |
| 732 | `swf_9_goto_in_enter_frame` | 17 | 6.1s |  |
| 733 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.0s |  |
| 734 | `swf_9_queued_goto_scripts` | 6 | 6.0s |  |
| 735 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 736 | `swf_9_versioning` | 2 | 5.8s |  |
| 737 | `swf_wrong_frame_count` | 38 | 6.2s |  |
| 738 | `swf_wrong_frame_count_isplaying` | 22 | 5.9s |  |
| 739 | `symbol_class_binary_data` | 8 | 5.9s |  |
| 740 | `symbol_class_conflict` | 4 | 6.4s |  |
| 741 | `symbol_class_root_not_zero` | 1 | 5.8s |  |
| 742 | `symbolclass_invalid_utf8` | 2 | 5.9s |  |
| 743 | `tab_ordering_automatic_advanced` | 184 | 6.5s |  |
| 744 | `tab_ordering_automatic_basic` | 45 | 6.0s |  |
| 745 | `tab_ordering_children` | 116 | 6.1s |  |
| 746 | `tab_ordering_custom_basic` | 34 | 6.0s |  |
| 747 | `text_engine_fontdescription` | 27 | 6.0s |  |
| 748 | `text_run` | 7 | 5.7s |  |
| 749 | `textfield_focusin_event` | 9 | 5.9s |  |
| 750 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 751 | `textfield_unload` | 39 | 24.2s |  |
| 752 | `textformat` | 1134 | 6.0s |  |
| 753 | `textformat_display` | 14 | 5.9s |  |
| 754 | `textformat_font_max_length` | 4 | 2.8s |  |
| 755 | `throw` | 3 | 5.9s |  |
| 756 | `timeline_scripts` | 3 | 5.9s |  |
| 757 | `timer` | 90 | 6.5s |  |
| 758 | `timer_events` | 3 | 6.0s |  |
| 759 | `timer_finished` | 11 | 3.0s |  |
| 760 | `timer_reset` | 8 | 6.0s |  |
| 761 | `timer_setdelay` | 5 | 5.9s |  |
| 762 | `trace` | 12 | 5.9s |  |
| 763 | `truthiness` | 30 | 0.9s |  |
| 764 | `try_catch` | 11 | 0.9s |  |
| 765 | `try_catch_typed` | 12 | 0.9s |  |
| 766 | `typeof` | 30 | 0.9s |  |
| 767 | `uint_constr` | 92 | 0.9s |  |
| 768 | `uint_tofixed` | 1215 | 0.9s |  |
| 769 | `uint_tostring` | 3375 | 0.9s |  |
| 770 | `unchecked_function` | 15 | 0.9s |  |
| 771 | `unescape` | 28 | 0.9s |  |
| 772 | `url_loader` | 25 | 0.9s |  |
| 773 | `urlrequest` | 18 | 0.9s |  |
| 774 | `urshift` | 1058 | 0.9s |  |
| 775 | `vector_class` | 36 | 0.9s |  |
| 776 | `vector_class_call` | 11 | 0.9s |  |
| 777 | `vector_coercion` | 66 | 0.9s |  |
| 778 | `vector_concat` | 90 | 0.9s |  |
| 779 | `vector_constr` | 107 | 0.9s |  |
| 780 | `vector_enumeration` | 5 | 0.9s |  |
| 781 | `vector_every` | 92 | 0.9s |  |
| 782 | `vector_filter` | 95 | 0.9s |  |
| 783 | `vector_holes` | 24 | 0.9s |  |
| 784 | `vector_indexof` | 302 | 0.9s |  |
| 785 | `vector_insertat` | 270 | 0.9s |  |
| 786 | `vector_int_access` | 4 | 0.9s |  |
| 787 | `vector_int_delete` | 11 | 0.9s |  |
| 788 | `vector_join` | 58 | 0.9s |  |
| 789 | `vector_lastindexof` | 302 | 0.9s |  |
| 790 | `vector_legacy` | 10 | 0.9s |  |
| 791 | `vector_map` | 85 | 0.9s |  |
| 792 | `vector_object_final` | 1 | 0.9s |  |
| 793 | `vector_object_toString` | 10 | 0.9s |  |
| 794 | `vector_pushpop` | 255 | 0.9s |  |
| 795 | `vector_reborrow_bug` | 10 | 6.0s |  |
| 796 | `vector_removeat` | 172 | 7.1s |  |
| 797 | `vector_reverse` | 232 | 7.1s |  |
| 798 | `vector_shiftunshift` | 252 | 5.9s |  |
| 799 | `vector_slice` | 331 | 7.8s |  |
| 800 | `vector_sort` | 905 | 15.7s |  |
| 801 | `vector_splice` | 693 | 10.1s |  |
| 802 | `vector_splice_fixed_bug_compat` | 4 | 6.0s |  |
| 803 | `vector_tostring` | 79 | 6.6s |  |
| 804 | `verify_abnormal_loop` | 1 | 5.9s |  |
| 805 | `verify_exception_targets_edge_case` | 1 | 5.8s |  |
| 806 | `verify_lookup_switch_edge_case` | 1 | 5.7s |  |
| 807 | `verify_unreachable_exception` | 2 | 5.9s |  |
| 808 | `versioned_isplaying` | 2 | 6.0s |  |
| 809 | `virtual_properties` | 16 | 6.0s |  |
| 810 | `with` | 4 | 5.9s |  |
| 811 | `wrong_arg_count` | 7 | 6.1s |  |
| 812 | `xml_abstract_equality` | 36 | 6.1s |  |
| 813 | `xml_advanced` | 52 | 6.0s |  |
| 814 | `xml_appendchild` | 10 | 5.9s |  |
| 815 | `xml_as_attribute` | 9 | 5.8s |  |
| 816 | `xml_attribute` | 35 | 6.0s |  |
| 817 | `xml_attribute_name` | 40 | 5.8s |  |
| 818 | `xml_basic` | 33 | 6.0s |  |
| 819 | `xml_child` | 25 | 5.9s |  |
| 820 | `xml_childindex` | 7 | 5.8s |  |
| 821 | `xml_children` | 43 | 6.4s |  |
| 822 | `xml_class_call` | 9 | 5.8s |  |
| 823 | `xml_contains` | 197 | 6.0s |  |
| 824 | `xml_copy` | 20 | 6.1s |  |
| 825 | `xml_ctor_from_tostring` | 23 | 6.2s |  |
| 826 | `xml_delete` | 114 | 6.1s |  |
| 827 | `xml_descendants` | 83 | 6.0s |  |
| 828 | `xml_elements` | 6 | 6.0s |  |
| 829 | `xml_equals_namespace_check` | 2 | 5.9s |  |
| 830 | `xml_explicit_use_namespace` | 5 | 24.4s |  |
| 831 | `xml_getdescendants_qname` | 21 | 5.9s |  |
| 832 | `xml_has_property_via_in` | 26 | 6.0s |  |
| 833 | `xml_hasownproperty` | 6 | 5.9s |  |
| 834 | `xml_ignore_white` | 6 | 5.9s |  |
| 835 | `xml_length` | 2 | 5.9s |  |
| 836 | `xml_list_as_attribute` | 9 | 5.9s |  |
| 837 | `xml_list_concat` | 20 | 6.1s |  |
| 838 | `xml_list_enumerate` | 4 | 5.9s |  |
| 839 | `xml_methods_settings` | 3 | 6.0s |  |
| 840 | `xml_mismatched_tag` | 37 | 6.0s |  |
| 841 | `xml_namespace` | 39 | 2.8s |  |
| 842 | `xml_namespace_methods` | 245 | 6.0s |  |
| 843 | `xml_namespaced_property` | 7 | 5.9s |  |
| 844 | `xml_no_namespace` | 1 | 5.9s |  |
| 845 | `xml_nodekind` | 3 | 5.9s |  |
| 846 | `xml_normalize` | 35 | 6.0s |  |
| 847 | `xml_notification_bubbling` | 361 | 6.0s |  |
| 848 | `xml_parent` | 8 | 5.9s |  |
| 849 | `xml_set_children` | 17 | 6.0s |  |
| 850 | `xml_set_name` | 34 | 6.0s |  |
| 851 | `xml_settings` | 6 | 2.8s |  |
| 852 | `xml_simple_complex_content` | 47 | 6.0s |  |
| 853 | `xml_text` | 7 | 5.9s |  |
| 854 | `xml_tostring` | 6 | 6.0s |  |
| 855 | `xml_tostring_namespace` | 12 | 5.9s |  |
| 856 | `xml_unescaping` | 23 | 6.0s |  |
| 857 | `xml_weird_ignores` | 54 | 6.0s |  |
| 858 | `xml_wildcard` | 11 | 6.0s |  |
| 859 | `xmldocument` | 254 | 6.1s |  |
| 860 | `xmlnode` | 3540 | 6.1s |  |
| 861 | `zero_frame_clip` | 3 | 6.1s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.6s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 3.9s |  |
| 3 | `blend_transform` | 1 | 1 | 6.3s |  |
| 4 | `coerce_property` | 3 | 3 | 6.2s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 3.1s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 6.2s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.2s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 24.1s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 5.9s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.2s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.3s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.9s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 24.0s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 25.7s |  |
| 15 | `int_toexponential` | 76 | 76 | 5.9s |  |
| 16 | `int_toprecision` | 441 | 441 | 5.9s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.1s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.7s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 23.8s |  |
| 20 | `soundchannel_position` | 74 | 74 | 25.0s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.1s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 5.9s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 25.6s |  |
| 24 | `uint_toexponential` | 100 | 100 | 0.9s |  |
| 25 | `uint_toprecision` | 433 | 433 | 0.9s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 5.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**69 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 5 | `focus_events_mouse_focusable` | 98.2% | 110 | 112 | 2 |  |
| 6 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 7 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 8 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 9 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 10 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 11 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 12 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 13 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 14 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 15 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 16 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 17 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 18 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 19 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 20 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 21 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 22 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 23 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 24 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 25 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 26 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 27 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 28 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 29 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 30 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 31 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 32 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 33 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 34 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 35 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 36 | `loader_noninteractive_try_click_root` | 80.0% | 4 | 5 | 1 |  |
| 37 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 38 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 39 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 40 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 41 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 42 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 43 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 44 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 45 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 46 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 47 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 48 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 49 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 50 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 51 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 52 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 53 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 54 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 55 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 56 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 57 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 58 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 59 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 60 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 61 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 62 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 63 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 64 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 65 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 66 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 67 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 68 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 69 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

**1 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `edittext_align` | 18.0s |  |

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 23.9s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 2.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**330 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 5 | `focus_events_mouse_focusable` | 98.2% | 110/112 | 112 | 112 |  |
| 6 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 7 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 8 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 9 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 10 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 11 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 12 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 13 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 14 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 15 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 16 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 17 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 18 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 19 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 20 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 21 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 22 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 23 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 24 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 25 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 26 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 27 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 28 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 29 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 30 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 31 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 32 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 33 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 34 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 35 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 36 | `loader_noninteractive_try_click_root` | 80.0% | 4/5 | 5 | 5 |  |
| 37 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 38 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 39 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 40 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 41 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 42 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 43 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 44 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 45 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 46 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 47 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 48 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 49 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 50 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 51 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 52 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 53 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 54 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 55 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 56 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 57 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 58 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 59 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 60 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 61 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 62 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 63 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 64 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 65 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 66 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 67 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 68 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 69 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 70 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 71 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 72 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 73 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 74 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 75 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 76 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 77 | `displayobject_hittestpoint_root` | 38.5% | 5/13 | 7 | 13 |  |
| 78 | `loader_reuse` | 36.8% | 14/38 | 36 | 38 |  |
| 79 | `loader_loadbytes_events` | 36.7% | 11/30 | 16 | 30 |  |
| 80 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 81 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 82 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 83 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 84 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 85 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 86 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 87 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 88 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 89 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 90 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 91 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 92 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 93 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 94 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 95 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 96 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 97 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 98 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 99 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 100 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 101 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 102 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 103 | `loader_events` | 20.7% | 19/92 | 20 | 92 |  |
| 104 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 105 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 106 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 107 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 108 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 109 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 110 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 111 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 112 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 113 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 114 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 115 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 116 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 117 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 118 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 119 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 120 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 121 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 122 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 123 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 124 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 125 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 126 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 127 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 128 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 129 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 130 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 131 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 132 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 133 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 134 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 135 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 136 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 137 | `font_registerfont` | 3.9% | 5/129 | 17 | 129 |  |
| 138 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 139 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 140 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 141 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 142 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 143 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 144 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 145 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 146 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 147 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 148 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 149 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 150 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 151 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 152 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 153 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 154 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 155 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 156 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 157 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 158 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 159 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 160 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 161 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 162 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 163 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 164 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 165 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 166 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 167 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 168 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 169 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 170 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 171 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 172 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 173 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 174 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 175 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 176 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 177 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 178 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 179 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 180 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 181 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 182 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 183 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 184 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 185 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 186 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 187 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 188 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 189 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 190 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 191 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 192 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 193 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 194 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 195 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 196 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 197 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 198 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 199 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 200 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 201 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 202 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 203 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 204 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 205 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 206 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 207 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 208 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 209 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 210 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 211 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 212 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 213 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 214 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 215 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 216 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 217 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 218 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 219 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 220 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 221 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 222 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 223 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 224 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 225 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 226 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 227 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 228 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 229 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 230 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 231 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 232 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 233 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 234 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 235 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 236 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 237 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 238 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 239 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 240 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 241 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 242 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 243 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 244 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 245 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 246 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 247 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 248 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 249 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 250 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 251 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 252 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 253 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 254 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 255 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 256 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 257 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 258 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 259 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 260 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 261 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 262 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 263 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 264 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 265 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 266 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 267 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 268 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 269 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 270 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 271 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 272 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 273 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 274 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 275 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 276 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 277 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 278 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 279 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 280 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 281 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 282 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 283 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 284 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 285 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 286 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 287 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 288 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 289 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 290 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 291 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 292 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 293 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 294 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 295 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 296 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 297 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 298 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 299 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 300 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 301 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 302 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 303 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 304 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 305 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 306 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 307 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 308 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 309 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 310 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 311 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 312 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 313 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 314 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 315 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 316 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 317 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 318 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 319 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 320 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 321 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 322 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 323 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 324 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 325 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 326 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 327 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 328 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 329 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 330 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
