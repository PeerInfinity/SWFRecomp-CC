# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-13 17:50 UTC

**Git SHA**: `1af36539fb`

**Run Duration**: 124m 54s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1204 |
| Passing | **827** (68.7%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **851** (70.7%) |
| Failing | 353 |
| Total expected lines | 149868 |
| Matching lines | 102146 (68.2%) |
| Mismatched lines | 47722 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 348 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**827 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.9s |  |
| 2 | `agal_compiler` | 13 | 4.0s |  |
| 3 | `air_hidden_lookup` | 2 | 4.0s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.0s |  |
| 5 | `amf_custom_obj` | 26 | 4.0s |  |
| 6 | `amf_dictionary` | 9 | 3.9s |  |
| 7 | `amf_function` | 46 | 4.0s |  |
| 8 | `amf_invalid_date` | 2 | 4.0s |  |
| 9 | `amf_missing_prop` | 6 | 3.9s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 5.2s |  |
| 11 | `amf_setter_error` | 8 | 4.5s |  |
| 12 | `amf_vector` | 40 | 4.5s |  |
| 13 | `amf_xml` | 6 | 4.4s |  |
| 14 | `application_domain` | 4 | 2.5s |  |
| 15 | `array_access` | 18 | 4.4s |  |
| 16 | `array_access_interpreter` | 4 | 4.4s |  |
| 17 | `array_access_no_pubns` | 2 | 4.3s |  |
| 18 | `array_concat` | 41 | 4.4s |  |
| 19 | `array_constr` | 10 | 4.4s |  |
| 20 | `array_delete` | 44 | 4.5s |  |
| 21 | `array_enumeration` | 10 | 4.4s |  |
| 22 | `array_enumeration_elements` | 11 | 2.5s |  |
| 23 | `array_every` | 8 | 2.5s |  |
| 24 | `array_filter` | 6 | 4.4s |  |
| 25 | `array_foreach` | 18 | 4.5s |  |
| 26 | `array_hasownproperty` | 11 | 2.6s |  |
| 27 | `array_holes` | 9 | 4.4s |  |
| 28 | `array_index_max` | 84 | 4.3s |  |
| 29 | `array_indexof` | 25 | 4.4s |  |
| 30 | `array_join` | 26 | 4.5s |  |
| 31 | `array_lastindexof` | 29 | 4.4s |  |
| 32 | `array_length` | 14 | 4.4s |  |
| 33 | `array_literal` | 3 | 4.4s |  |
| 34 | `array_map` | 8 | 4.3s |  |
| 35 | `array_pop` | 52 | 4.4s |  |
| 36 | `array_push` | 24 | 4.4s |  |
| 37 | `array_reborrow_bug` | 6 | 4.4s |  |
| 38 | `array_reverse` | 28 | 4.3s |  |
| 39 | `array_shift` | 51 | 2.6s |  |
| 40 | `array_slice` | 39 | 4.5s |  |
| 41 | `array_some` | 8 | 4.4s |  |
| 42 | `array_sort` | 297 | 4.6s |  |
| 43 | `array_sort_fun_swf12` | 2 | 4.4s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.0s |  |
| 45 | `array_sort_random` | 210 | 4.5s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 4.4s |  |
| 47 | `array_sorton` | 545 | 5.2s |  |
| 48 | `array_sparse_ops` | 41 | 4.7s |  |
| 49 | `array_splice` | 133 | 4.7s |  |
| 50 | `array_splice2` | 428 | 4.8s |  |
| 51 | `array_splice_types` | 48 | 4.6s |  |
| 52 | `array_storage` | 8 | 4.5s |  |
| 53 | `array_tolocalestring` | 9 | 4.5s |  |
| 54 | `array_tostring` | 12 | 4.5s |  |
| 55 | `array_unshift` | 24 | 4.5s |  |
| 56 | `array_valueof` | 9 | 4.5s |  |
| 57 | `array_vector_null_callback` | 10 | 4.5s |  |
| 58 | `astype` | 28 | 4.6s |  |
| 59 | `astypelate` | 24 | 4.7s |  |
| 60 | `astypelate_propagates` | 1 | 4.5s |  |
| 61 | `asymmetric_key_events` | 11 | 4.6s |  |
| 62 | `avm2_catchup_dobj` | 158 | 5.1s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 68.8s |  |
| 64 | `bitand` | 1058 | 7.2s |  |
| 65 | `bitmap_constr` | 17 | 5.0s |  |
| 66 | `bitmap_data` | 1000 | 9.4s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 23.9s |  |
| 68 | `bitmap_properties` | 23 | 4.6s |  |
| 69 | `bitmap_subclass` | 7 | 5.8s |  |
| 70 | `bitmap_subclass_properties` | 9 | 5.0s |  |
| 71 | `bitmap_timeline` | 9 | 4.6s |  |
| 72 | `bitmapdata_accuracy` | 1 | 39.0s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 24.3s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.4s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 24.0s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 24.2s |  |
| 77 | `bitmapdata_clone` | 13 | 5.2s |  |
| 78 | `bitmapdata_colortransform` | 0 | 5.6s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 4.9s |  |
| 80 | `bitmapdata_constr` | 22 | 4.9s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 5.2s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.6s |  |
| 83 | `bitmapdata_copypixels` | 23 | 25.6s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 4.9s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 4.6s |  |
| 86 | `bitmapdata_dispose` | 7 | 4.6s |  |
| 87 | `bitmapdata_draw` | 0 | 24.4s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 4.9s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 23.7s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 23.4s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 4.7s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 4.9s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 4.9s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 23.4s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 4.8s |  |
| 96 | `bitmapdata_embedded` | 9 | 5.0s |  |
| 97 | `bitmapdata_fillrect` | 0 | 4.9s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 24.0s |  |
| 99 | `bitmapdata_floodfill` | 35 | 4.6s |  |
| 100 | `bitmapdata_getpixels` | 39 | 23.3s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.6s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.6s |  |
| 103 | `bitmapdata_hittest` | 112 | 5.0s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 4.6s |  |
| 105 | `bitmapdata_opaque` | 0 | 4.9s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 5.0s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 5.0s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 4.6s |  |
| 109 | `bitmapdata_setpixels` | 286 | 4.7s |  |
| 110 | `bitmapdata_setvector` | 26 | 4.6s |  |
| 111 | `bitmapdata_sync` | 0 | 4.9s |  |
| 112 | `bitmapdata_threshold` | 176 | 5.1s |  |
| 113 | `bitmapdata_zero_size` | 5 | 4.6s |  |
| 114 | `bitnot` | 46 | 4.5s |  |
| 115 | `bitor` | 1058 | 6.8s |  |
| 116 | `bitxor` | 1058 | 6.7s |  |
| 117 | `blend_multiply_alpha` | 0 | 4.9s |  |
| 118 | `blend_scroll` | 0 | 5.0s |  |
| 119 | `boolean_constr` | 32 | 4.5s |  |
| 120 | `boolean_negation` | 30 | 4.5s |  |
| 121 | `boolean_tostring` | 8 | 4.6s |  |
| 122 | `broadcast_event` | 7 | 4.5s |  |
| 123 | `button_nested_frame` | 48 | 4.8s |  |
| 124 | `bytearray` | 48 | 4.9s |  |
| 125 | `bytearray_compress` | 31 | 4.6s |  |
| 126 | `bytearray_errors` | 24 | 4.6s |  |
| 127 | `bytearray_method_serialization` | 1 | 4.5s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 4.5s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 4.5s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 4.5s |  |
| 131 | `bytearray_serialization` | 3 | 4.5s |  |
| 132 | `bytearray_string_null` | 19 | 4.7s |  |
| 133 | `bytearray_tostring` | 15 | 4.5s |  |
| 134 | `bytearray_utf16` | 8 | 2.6s |  |
| 135 | `bytearray_writeobject` | 24 | 4.5s |  |
| 136 | `callee_in_initializer` | 6 | 4.5s |  |
| 137 | `callproplex_class` | 1 | 4.5s |  |
| 138 | `catch_class` | 6 | 4.5s |  |
| 139 | `catch_scope_slot` | 7 | 4.7s |  |
| 140 | `checkfilter` | 4 | 2.6s |  |
| 141 | `class_call` | 32 | 4.7s |  |
| 142 | `class_cast_call` | 14 | 4.7s |  |
| 143 | `class_enumeration` | 4 | 4.6s |  |
| 144 | `class_has_own_property` | 2 | 4.5s |  |
| 145 | `class_init_interpreter_mode` | 1 | 4.5s |  |
| 146 | `class_is` | 32 | 4.6s |  |
| 147 | `class_methods` | 5 | 4.6s |  |
| 148 | `class_object_properties` | 10 | 4.7s |  |
| 149 | `class_singleton` | 18 | 4.6s |  |
| 150 | `class_supercalls_errors` | 35 | 2.8s |  |
| 151 | `class_supercalls_mismatched` | 26 | 5.5s |  |
| 152 | `class_superclass_wrong_order` | 1 | 4.6s |  |
| 153 | `class_to_locale_string` | 2 | 4.6s |  |
| 154 | `class_to_string` | 2 | 4.6s |  |
| 155 | `class_value_of` | 2 | 4.6s |  |
| 156 | `click_block` | 5 | 23.5s |  |
| 157 | `click_invisible` | 3 | 4.7s |  |
| 158 | `closures` | 12 | 4.8s |  |
| 159 | `coerce_property` | 33 | 4.8s |  |
| 160 | `coerce_return_type` | 40 | 4.9s |  |
| 161 | `coerce_return_type_fail` | 2 | 4.6s |  |
| 162 | `coerce_return_void` | 3 | 4.7s |  |
| 163 | `coerce_string` | 86 | 4.9s |  |
| 164 | `coerce_string_precision` | 28 | 4.8s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 4.7s |  |
| 166 | `construct_errors_swf10` | 8 | 4.8s |  |
| 167 | `construct_frame_list` | 22 | 5.0s |  |
| 168 | `constructor_call` | 3 | 4.8s |  |
| 169 | `constructors_vs_timeline` | 5 | 23.7s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 4.8s |  |
| 171 | `control_flow_bool` | 4 | 4.7s |  |
| 172 | `control_flow_stricteq` | 8 | 4.6s |  |
| 173 | `convert_boolean` | 30 | 4.7s |  |
| 174 | `convert_integer` | 90 | 4.7s |  |
| 175 | `convert_number` | 56 | 4.7s |  |
| 176 | `convert_uinteger` | 90 | 4.7s |  |
| 177 | `cryptscore` | 11 | 5.4s |  |
| 178 | `declocal` | 46 | 4.6s |  |
| 179 | `declocal_i` | 46 | 4.6s |  |
| 180 | `decrement` | 46 | 4.5s |  |
| 181 | `decrement_i` | 46 | 2.6s |  |
| 182 | `default_values` | 7 | 4.6s |  |
| 183 | `dictionary_access` | 62 | 4.7s |  |
| 184 | `dictionary_access_no_pubns` | 2 | 4.4s |  |
| 185 | `dictionary_delete` | 101 | 4.7s |  |
| 186 | `dictionary_foreach` | 42 | 4.7s |  |
| 187 | `dictionary_hasownproperty` | 63 | 4.6s |  |
| 188 | `dictionary_in` | 62 | 4.8s |  |
| 189 | `dictionary_iter_modify` | 8 | 4.6s |  |
| 190 | `dictionary_namespaces` | 36 | 4.6s |  |
| 191 | `dictionary_primitive_keys` | 29 | 4.6s |  |
| 192 | `displayobject_alpha` | 277 | 4.4s |  |
| 193 | `displayobject_blendmode` | 0 | 23.1s |  |
| 194 | `displayobject_colortransform_nested` | 0 | 21.1s |  |
| 195 | `displayobject_from_enterframe` | 1 | 4.7s |  |
| 196 | `displayobject_getbounds_shape` | 0 | 24.1s |  |
| 197 | `displayobject_height` | 6052 | 24.2s |  |
| 198 | `displayobject_hittestobject` | 32 | 4.8s |  |
| 199 | `displayobject_invalid_floats` | 60 | 4.6s |  |
| 200 | `displayobject_invalid_props` | 3 | 5.3s |  |
| 201 | `displayobject_mask` | 3 | 5.0s |  |
| 202 | `displayobject_mask_self_referential` | 0 | 4.4s |  |
| 203 | `displayobject_metaData` | 3 | 4.4s |  |
| 204 | `displayobject_name` | 22 | 4.7s |  |
| 205 | `displayobject_name_from_timeline` | 24 | 4.6s |  |
| 206 | `displayobject_parent` | 12 | 4.4s |  |
| 207 | `displayobject_root` | 24 | 4.4s |  |
| 208 | `displayobject_rotation` | 1275 | 4.4s |  |
| 209 | `displayobject_set_matrix_nested` | 0 | 22.9s |  |
| 210 | `displayobject_subclass` | 2 | 4.5s |  |
| 211 | `displayobject_visible` | 23 | 4.5s |  |
| 212 | `displayobject_width` | 4852 | 22.6s |  |
| 213 | `displayobject_x` | 614 | 4.3s |  |
| 214 | `displayobject_y` | 617 | 4.4s |  |
| 215 | `displayobjectcontainer_addchild` | 32 | 4.5s |  |
| 216 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.4s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.6s |  |
| 218 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.4s |  |
| 219 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.5s |  |
| 220 | `displayobjectcontainer_addchildat` | 42 | 2.5s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.5s |  |
| 222 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.5s |  |
| 223 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.5s |  |
| 224 | `displayobjectcontainer_contains` | 66 | 4.7s |  |
| 225 | `displayobjectcontainer_getchildat` | 4 | 4.5s |  |
| 226 | `displayobjectcontainer_getchildbyname` | 9 | 4.4s |  |
| 227 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.4s |  |
| 228 | `displayobjectcontainer_getchildindex` | 28 | 4.4s |  |
| 229 | `displayobjectcontainer_removechild` | 10 | 4.4s |  |
| 230 | `displayobjectcontainer_removechild_errors` | 4 | 4.4s |  |
| 231 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.4s |  |
| 232 | `displayobjectcontainer_removechildat` | 18 | 4.4s |  |
| 233 | `displayobjectcontainer_removechildren` | 51 | 4.6s |  |
| 234 | `displayobjectcontainer_setchildindex` | 42 | 4.2s |  |
| 235 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.4s |  |
| 236 | `displayobjectcontainer_swapchildren` | 42 | 4.5s |  |
| 237 | `displayobjectcontainer_swapchildrenat` | 42 | 4.4s |  |
| 238 | `displayobjectcontainer_timelineinstance` | 48 | 22.4s |  |
| 239 | `divide` | 1058 | 6.5s |  |
| 240 | `doabc_is_eager` | 1 | 22.1s |  |
| 241 | `documentclass` | 9 | 4.5s |  |
| 242 | `drag_drop` | 10 | 4.6s |  |
| 243 | `duplicate_defs` | 1 | 4.3s |  |
| 244 | `eager_init` | 1 | 4.4s |  |
| 245 | `edit_text_linkage` | 7 | 4.6s |  |
| 246 | `edittext_align` | 60 | 4.7s |  |
| 247 | `edittext_always_show_selection` | 0 | 22.8s |  |
| 248 | `edittext_antialiastype` | 296 | 4.6s |  |
| 249 | `edittext_at_point_methods_basic` | 16 | 5.6s |  |
| 250 | `edittext_autosize` | 39 | 4.7s |  |
| 251 | `edittext_autosize_align` | 0 | 23.0s |  |
| 252 | `edittext_autosize_height_dynamic` | 60 | 22.9s |  |
| 253 | `edittext_autosize_height_input` | 60 | 4.5s |  |
| 254 | `edittext_autosize_lazy_bounds_events` | 65 | 4.7s |  |
| 255 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.5s |  |
| 256 | `edittext_autosize_lazy_bounds_props` | 490 | 5.7s |  |
| 257 | `edittext_autosize_lazy_bounds_visual` | 0 | 22.6s |  |
| 258 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.6s |  |
| 259 | `edittext_bottom_scroll_v_basic` | 210 | 4.5s |  |
| 260 | `edittext_bounds_scale` | 24 | 23.3s |  |
| 261 | `edittext_bullet` | 30 | 4.6s |  |
| 262 | `edittext_default_format` | 221 | 4.8s |  |
| 263 | `edittext_default_format_empty` | 136 | 4.8s |  |
| 264 | `edittext_empty_text_format` | 7 | 4.7s |  |
| 265 | `edittext_focus_selection` | 5 | 4.6s |  |
| 266 | `edittext_font_size` | 45 | 4.5s |  |
| 267 | `edittext_format_empty_font` | 8 | 4.5s |  |
| 268 | `edittext_get_char_index_at_point` | 4 | 24.6s |  |
| 269 | `edittext_get_line_index_at_point` | 2 | 20.6s |  |
| 270 | `edittext_get_line_index_of_char` | 76 | 4.8s |  |
| 271 | `edittext_getcharboundaries` | 172 | 4.1s |  |
| 272 | `edittext_getcharboundaries_missing_glyphs` | 63 | 4.2s |  |
| 273 | `edittext_getcharboundaries_scroll` | 85 | 4.0s |  |
| 274 | `edittext_getlinemetrics` | 146 | 4.0s |  |
| 275 | `edittext_html` | 3101 | 4.2s |  |
| 276 | `edittext_html_condensewhite` | 487 | 4.0s |  |
| 277 | `edittext_html_entity` | 4 | 4.5s |  |
| 278 | `edittext_html_font_size_swf12` | 267 | 3.9s |  |
| 279 | `edittext_html_font_size_swf13` | 273 | 3.6s |  |
| 280 | `edittext_html_roundtrip` | 17 | 3.8s |  |
| 281 | `edittext_input_control` | 12 | 3.8s |  |
| 282 | `edittext_leading` | 9 | 3.9s |  |
| 283 | `edittext_letter_spacing` | 15 | 3.8s |  |
| 284 | `edittext_line_methods` | 294 | 4.5s |  |
| 285 | `edittext_line_metrics` | 11 | 20.6s |  |
| 286 | `edittext_margins` | 25 | 3.9s |  |
| 287 | `edittext_max_scroll_h_basic` | 475 | 4.2s |  |
| 288 | `edittext_max_scroll_v_basic` | 1000 | 4.0s |  |
| 289 | `edittext_mousedown` | 3 | 4.2s |  |
| 290 | `edittext_mouseenabled` | 26 | 3.9s |  |
| 291 | `edittext_newline_character` | 22 | 3.9s |  |
| 292 | `edittext_newline_stripping` | 64 | 5.9s |  |
| 293 | `edittext_newlines` | 30 | 3.9s |  |
| 294 | `edittext_paragraph_methods` | 257 | 4.0s |  |
| 295 | `edittext_paste_events` | 8 | 3.8s |  |
| 296 | `edittext_paste_maxchars` | 4 | 3.8s |  |
| 297 | `edittext_paste_restrict` | 16 | 3.8s |  |
| 298 | `edittext_restrict` | 191 | 3.9s |  |
| 299 | `edittext_restrict_events` | 22 | 3.8s |  |
| 300 | `edittext_scrollh` | 10 | 3.8s |  |
| 301 | `edittext_selected_text` | 9 | 4.0s |  |
| 302 | `edittext_set_html_same` | 17 | 3.8s |  |
| 303 | `edittext_set_text_vs_html` | 9 | 3.9s |  |
| 304 | `edittext_stylesheet` | 536 | 4.2s |  |
| 305 | `edittext_stylesheet_custom_tag` | 76 | 5.3s |  |
| 306 | `edittext_stylesheet_display` | 272 | 4.6s |  |
| 307 | `edittext_underline` | 40 | 4.6s |  |
| 308 | `edittext_width_height` | 103 | 4.8s |  |
| 309 | `edittext_wordwrap_word` | 150 | 4.9s |  |
| 310 | `edittext_wrap_breaks` | 2375 | 5.1s |  |
| 311 | `empty_bounds` | 1 | 4.5s |  |
| 312 | `equals` | 512 | 5.5s |  |
| 313 | `error_prototype` | 15 | 4.5s |  |
| 314 | `error_stack_trace_debug_swf17` | 0 | 23.2s |  |
| 315 | `error_stack_trace_debug_swf18` | 0 | 4.4s |  |
| 316 | `error_stack_trace_release_swf17` | 0 | 4.4s |  |
| 317 | `error_stack_trace_release_swf18` | 0 | 4.4s |  |
| 318 | `error_tostring` | 29 | 4.6s |  |
| 319 | `es3_inheritance` | 31 | 4.6s |  |
| 320 | `es4_inheritance` | 30 | 4.6s |  |
| 321 | `es4_interfaces` | 30 | 4.6s |  |
| 322 | `es4_method_binding` | 8 | 4.5s |  |
| 323 | `es4_oop_prototypes` | 14 | 4.6s |  |
| 324 | `es4_protected_inheritance` | 6 | 4.5s |  |
| 325 | `event_bubbles` | 2 | 4.5s |  |
| 326 | `event_cancelable` | 2 | 4.4s |  |
| 327 | `event_clone` | 20 | 4.5s |  |
| 328 | `event_clone_error_redispatch` | 3 | 4.6s |  |
| 329 | `event_clone_on_redispatch` | 10 | 4.5s |  |
| 330 | `event_formattostring` | 31 | 3.6s |  |
| 331 | `event_handler_exception` | 4 | 3.5s |  |
| 332 | `event_isdefaultprevented` | 12 | 3.5s |  |
| 333 | `event_target_getter` | 5 | 3.5s |  |
| 334 | `event_target_set` | 9 | 3.5s |  |
| 335 | `event_type` | 1 | 3.5s |  |
| 336 | `event_valueof_tostring` | 18 | 3.5s |  |
| 337 | `eventdispatcher_dispatchevent` | 12 | 3.6s |  |
| 338 | `eventdispatcher_dispatchevent_cancel` | 20 | 1.9s |  |
| 339 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 3.7s |  |
| 340 | `eventdispatcher_dispatchevent_indirect` | 9 | 1.9s |  |
| 341 | `eventdispatcher_dispatchevent_this` | 5 | 3.5s |  |
| 342 | `eventdispatcher_haseventlistener` | 25 | 3.6s |  |
| 343 | `eventdispatcher_interface_invoke` | 1 | 3.5s |  |
| 344 | `eventdispatcher_tostring` | 10 | 3.6s |  |
| 345 | `eventdispatcher_willtrigger` | 25 | 3.5s |  |
| 346 | `falsiness` | 30 | 3.6s |  |
| 347 | `fast_index_access` | 12 | 3.6s |  |
| 348 | `finddef` | 3 | 3.5s |  |
| 349 | `findprop_global_prototype` | 6 | 3.5s |  |
| 350 | `flash_xml` | 29 | 3.6s |  |
| 351 | `flash_xml_cloneNode` | 22 | 3.5s |  |
| 352 | `flash_xml_namespace` | 109 | 3.6s |  |
| 353 | `flash_xml_removeNode` | 60 | 5.6s |  |
| 354 | `focus_events_code` | 161 | 24.3s |  |
| 355 | `focus_events_key_same_object` | 26 | 4.5s |  |
| 356 | `focus_events_mixed_key_mouse` | 100 | 23.0s |  |
| 357 | `focus_events_mouse_same_object` | 40 | 4.6s |  |
| 358 | `focus_remove` | 20 | 23.4s |  |
| 359 | `focus_root_movie` | 4 | 22.9s |  |
| 360 | `focus_stage` | 1 | 4.5s |  |
| 361 | `focusrect` | 18 | 5.2s |  |
| 362 | `font_description_clone` | 14 | 4.5s |  |
| 363 | `font_embedded` | 24 | 4.9s |  |
| 364 | `font_enumeratefonts` | 41 | 5.2s |  |
| 365 | `font_enumeratefonts_filter` | 4 | 5.3s |  |
| 366 | `font_hasglyphs` | 40 | 4.8s |  |
| 367 | `framelabel_constr` | 5 | 4.6s |  |
| 368 | `function_call` | 12 | 4.5s |  |
| 369 | `function_call_arguments` | 46 | 4.6s |  |
| 370 | `function_call_arguments_enumerate` | 5 | 4.5s |  |
| 371 | `function_call_coercion` | 108 | 4.6s |  |
| 372 | `function_call_default` | 6 | 4.5s |  |
| 373 | `function_call_rest` | 22 | 4.4s |  |
| 374 | `function_call_types` | 3 | 4.4s |  |
| 375 | `function_call_via_apply` | 11 | 4.4s |  |
| 376 | `function_call_via_call` | 3 | 4.4s |  |
| 377 | `function_display_anonymous` | 7 | 2.5s |  |
| 378 | `function_length` | 6 | 4.5s |  |
| 379 | `function_object` | 2 | 4.5s |  |
| 380 | `function_proto` | 5 | 4.4s |  |
| 381 | `function_proto_created` | 61 | 4.5s |  |
| 382 | `function_to_locale_string` | 4 | 2.5s |  |
| 383 | `function_to_string` | 4 | 5.3s |  |
| 384 | `function_type` | 6 | 4.5s |  |
| 385 | `function_unbound_this` | 51 | 4.7s |  |
| 386 | `function_value_of` | 4 | 4.5s |  |
| 387 | `get_definition_by_name` | 11 | 4.6s |  |
| 388 | `get_qualified_class_name` | 20 | 4.7s |  |
| 389 | `get_qualified_super_class_name` | 18 | 4.7s |  |
| 390 | `get_slot_edge_cases` | 1 | 2.5s |  |
| 391 | `get_timer` | 2 | 4.6s |  |
| 392 | `getglobalslot` | 1 | 4.5s |  |
| 393 | `getouterscope` | 8 | 4.5s |  |
| 394 | `getter_different_namespace_setter` | 2 | 4.5s |  |
| 395 | `goto_button_nested_framescript` | 28 | 4.8s |  |
| 396 | `goto_in_constructframe` | 12 | 2.9s |  |
| 397 | `goto_in_scene_last_frame` | 2 | 23.1s |  |
| 398 | `goto_methods` | 56 | 4.8s |  |
| 399 | `goto_methods_swfver10` | 8 | 4.6s |  |
| 400 | `goto_nested_construct_sibling` | 18 | 5.0s |  |
| 401 | `goto_nested_framescript` | 9 | 4.8s |  |
| 402 | `goto_on_orphan` | 15 | 4.8s |  |
| 403 | `graphics_bitmap_fill` | 0 | 6.1s |  |
| 404 | `graphics_bitmaps` | 0 | 5.2s |  |
| 405 | `graphics_direct_commands` | 0 | 5.2s |  |
| 406 | `graphics_gradients` | 0 | 4.9s |  |
| 407 | `graphics_gradients_nulls` | 0 | 4.8s |  |
| 408 | `graphics_round_rects` | 0 | 4.4s |  |
| 409 | `graphics_simple_shapes` | 0 | 4.8s |  |
| 410 | `greaterequals` | 512 | 5.3s |  |
| 411 | `greaterthan` | 512 | 6.6s |  |
| 412 | `has_own_property` | 102 | 4.9s |  |
| 413 | `hasownproperty_namespaces` | 2 | 4.7s |  |
| 414 | `hello_world` | 1 | 4.7s |  |
| 415 | `hittest_morph` | 30 | 4.8s |  |
| 416 | `if_eq` | 10 | 4.6s |  |
| 417 | `if_gt` | 1 | 4.7s |  |
| 418 | `if_gte` | 10 | 2.7s |  |
| 419 | `if_lt` | 1 | 1.0s |  |
| 420 | `if_lte` | 10 | 4.5s |  |
| 421 | `if_ne` | 7 | 2.7s |  |
| 422 | `if_stricteq` | 6 | 4.8s |  |
| 423 | `if_strictne` | 11 | 4.7s |  |
| 424 | `in` | 102 | 4.9s |  |
| 425 | `inclocal` | 46 | 4.7s |  |
| 426 | `inclocal_i` | 46 | 4.6s |  |
| 427 | `increment` | 46 | 4.7s |  |
| 428 | `increment_i` | 46 | 4.6s |  |
| 429 | `instanceof` | 58 | 4.8s |  |
| 430 | `instantiation_on_enter_frame` | 7 | 24.4s |  |
| 431 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.8s |  |
| 432 | `int_constr` | 92 | 5.0s |  |
| 433 | `int_edge_cases` | 19 | 4.8s |  |
| 434 | `int_instanceof` | 3 | 4.7s |  |
| 435 | `int_tofixed` | 1215 | 4.7s |  |
| 436 | `int_tostring` | 3375 | 4.9s |  |
| 437 | `interactiveobject_enabled` | 25 | 4.7s |  |
| 438 | `interface_namespaces` | 78 | 4.9s |  |
| 439 | `is_finite` | 46 | 4.8s |  |
| 440 | `is_nan` | 46 | 4.7s |  |
| 441 | `is_prototype_of` | 12 | 4.8s |  |
| 442 | `issue_10221` | 2 | 4.7s |  |
| 443 | `issue_13780` | 12 | 4.7s |  |
| 444 | `issue_14901` | 1 | 4.4s |  |
| 445 | `issue_17675_edittext_paste_maxchars` | 1 | 3.7s |  |
| 446 | `issue_5292` | 5 | 3.7s |  |
| 447 | `issue_8630` | 2 | 3.7s |  |
| 448 | `issue_8630_scriptremove` | 11 | 3.9s |  |
| 449 | `istype` | 24 | 3.8s |  |
| 450 | `istypelate` | 58 | 3.9s |  |
| 451 | `istypelate_coerce` | 198 | 4.2s |  |
| 452 | `json_errors` | 9 | 18.4s |  |
| 453 | `json_parse` | 21 | 3.8s |  |
| 454 | `json_version_gated` | 1 | 3.6s |  |
| 455 | `key_input_80percent` | 1812 | 3.8s |  |
| 456 | `key_input_location` | 126 | 3.6s |  |
| 457 | `key_input_numpad` | 384 | 3.7s |  |
| 458 | `lazyinit` | 17 | 3.7s |  |
| 459 | `lessequals` | 512 | 4.6s |  |
| 460 | `lessthan` | 512 | 4.5s |  |
| 461 | `loaderinfo_properties` | 18 | 5.1s |  |
| 462 | `loaderinfo_root` | 10 | 4.7s |  |
| 463 | `loaderinfo_root_allows` | 2 | 4.6s |  |
| 464 | `lshift` | 1058 | 6.9s |  |
| 465 | `mask_reapply` | 1 | 23.5s |  |
| 466 | `math` | 497 | 4.8s |  |
| 467 | `modulo` | 1058 | 7.0s |  |
| 468 | `mouse_click_events` | 90 | 23.2s |  |
| 469 | `mouse_double_click_events` | 188 | 4.7s |  |
| 470 | `mouse_empty_parent` | 4 | 4.7s |  |
| 471 | `mouse_over_while_dragging` | 3 | 4.7s |  |
| 472 | `mouse_pick_button_mode` | 2 | 4.7s |  |
| 473 | `mouse_sibling` | 8 | 4.6s |  |
| 474 | `movieclip_addframescript` | 3 | 25.3s |  |
| 475 | `movieclip_child_property` | 16 | 4.9s |  |
| 476 | `movieclip_constr` | 21 | 4.8s |  |
| 477 | `movieclip_currentlabels` | 17 | 24.9s |  |
| 478 | `movieclip_currentlabels_dupes1` | 46 | 24.5s |  |
| 479 | `movieclip_currentlabels_dupes2` | 30 | 4.6s |  |
| 480 | `movieclip_currentlabels_dupes3` | 67 | 4.6s |  |
| 481 | `movieclip_currentscene` | 12 | 24.0s |  |
| 482 | `movieclip_dispatchevent` | 430 | 4.7s |  |
| 483 | `movieclip_dispatchevent_cancel` | 102 | 4.7s |  |
| 484 | `movieclip_dispatchevent_handlerorder` | 251 | 4.7s |  |
| 485 | `movieclip_dispatchevent_selfadd` | 80 | 4.6s |  |
| 486 | `movieclip_dispatchevent_target` | 899 | 4.7s |  |
| 487 | `movieclip_displayevents` | 96 | 25.0s |  |
| 488 | `movieclip_displayevents_clickgoto` | 676 | 5.1s |  |
| 489 | `movieclip_displayevents_clickgoto2` | 2001 | 5.2s |  |
| 490 | `movieclip_displayevents_clickplay` | 575 | 4.9s |  |
| 491 | `movieclip_displayevents_clicksymbol` | 562 | 4.8s |  |
| 492 | `movieclip_displayevents_constructframegoto` | 140 | 5.1s |  |
| 493 | `movieclip_displayevents_constructframeplay` | 50 | 4.9s |  |
| 494 | `movieclip_displayevents_constructframesymbol` | 144 | 4.9s |  |
| 495 | `movieclip_displayevents_dblhandler` | 21 | 4.9s |  |
| 496 | `movieclip_displayevents_enterframegoto` | 149 | 5.0s |  |
| 497 | `movieclip_displayevents_enterframeplay` | 48 | 4.8s |  |
| 498 | `movieclip_displayevents_enterframesymbol` | 149 | 24.9s |  |
| 499 | `movieclip_displayevents_exitframegoto` | 106 | 4.8s |  |
| 500 | `movieclip_displayevents_exitframeplay` | 44 | 4.8s |  |
| 501 | `movieclip_displayevents_exitframesymbol` | 135 | 4.8s |  |
| 502 | `movieclip_displayevents_looping` | 63 | 24.2s |  |
| 503 | `movieclip_displayevents_stopped` | 113 | 5.0s |  |
| 504 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 505 | `movieclip_displayevents_timeline` | 128 | 23.7s |  |
| 506 | `movieclip_drawrect` | 54 | 4.5s |  |
| 507 | `movieclip_frameconstruct_skipped` | 9 | 5.4s |  |
| 508 | `movieclip_goto_during_frame_script` | 15 | 4.7s |  |
| 509 | `movieclip_goto_overwrite` | 14 | 23.4s |  |
| 510 | `movieclip_goto_scene_last_frame_int` | 1 | 23.3s |  |
| 511 | `movieclip_goto_scene_last_frame_label` | 1 | 4.6s |  |
| 512 | `movieclip_gotoandplay` | 15 | 23.4s |  |
| 513 | `movieclip_gotoandstop` | 13 | 4.7s |  |
| 514 | `movieclip_gotoandstop_children` | 4 | 4.8s |  |
| 515 | `movieclip_gotoandstop_framescripts1` | 4 | 4.7s |  |
| 516 | `movieclip_gotoandstop_framescripts2` | 4 | 2.7s |  |
| 517 | `movieclip_gotoandstop_framescripts_self` | 7 | 4.7s |  |
| 518 | `movieclip_gotoandstop_queueing` | 12 | 4.6s |  |
| 519 | `movieclip_next_frame` | 2 | 4.6s |  |
| 520 | `movieclip_next_scene` | 6 | 22.9s |  |
| 521 | `movieclip_play` | 3 | 4.5s |  |
| 522 | `movieclip_prev_frame` | 3 | 4.5s |  |
| 523 | `movieclip_prev_scene` | 7 | 4.7s |  |
| 524 | `movieclip_properties` | 79 | 23.7s |  |
| 525 | `movieclip_queued_noop_goto_swf10` | 9 | 4.8s |  |
| 526 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 527 | `movieclip_scenes` | 11 | 4.7s |  |
| 528 | `movieclip_soundtransform` | 831 | 25.0s |  |
| 529 | `movieclip_stop` | 1 | 4.6s |  |
| 530 | `movieclip_super_is_symbol` | 20 | 5.0s |  |
| 531 | `movieclip_symbol_constr` | 8 | 4.8s |  |
| 532 | `movieclip_text_mousedown` | 1 | 4.7s |  |
| 533 | `movieclip_willtrigger` | 5 | 4.8s |  |
| 534 | `multiply` | 1058 | 6.9s |  |
| 535 | `namespace_constr` | 253 | 5.0s |  |
| 536 | `namespace_constr_args` | 1 | 4.6s |  |
| 537 | `namespace_enumeration_order` | 7 | 4.6s |  |
| 538 | `nan_scale` | 9 | 4.6s |  |
| 539 | `negate` | 30 | 4.7s |  |
| 540 | `negative_volume_panned` | 0 | 4.8s |  |
| 541 | `nested_iteration` | 11 | 4.7s |  |
| 542 | `net_getClassByAlias` | 3 | 4.7s |  |
| 543 | `newactivation_in_script_init` | 3 | 3.9s |  |
| 544 | `newclass_twice` | 3 | 3.6s |  |
| 545 | `nonconflicting_declarations` | 0 | 3.9s |  |
| 546 | `null_void_types` | 8 | 3.6s |  |
| 547 | `number_autoconv` | 21 | 3.8s |  |
| 548 | `number_autoconv_amf` | 132 | 3.7s |  |
| 549 | `number_autoconv_array_sort_32bit` | 1 | 3.7s |  |
| 550 | `number_constr` | 58 | 3.8s |  |
| 551 | `number_toexponential` | 378 | 4.0s |  |
| 552 | `number_toexponential2` | 35 | 4.3s |  |
| 553 | `number_tofixed` | 378 | 2.1s |  |
| 554 | `number_toprecision` | 350 | 3.8s |  |
| 555 | `obfuscated_class_names` | 3 | 3.6s |  |
| 556 | `object_enumeration` | 10 | 3.9s |  |
| 557 | `object_prototype` | 4 | 3.8s |  |
| 558 | `object_to_locale_string` | 2 | 3.6s |  |
| 559 | `object_to_string` | 2 | 3.6s |  |
| 560 | `object_value_of` | 2 | 2.1s |  |
| 561 | `op_coerce` | 54 | 3.7s |  |
| 562 | `op_coerce_x` | 54 | 3.8s |  |
| 563 | `op_escxattr` | 2 | 3.7s |  |
| 564 | `op_escxelem` | 2 | 3.8s |  |
| 565 | `op_lookupswitch` | 4 | 3.7s |  |
| 566 | `optimize_coerce` | 1 | 3.6s |  |
| 567 | `orphan_movie_complex` | 80 | 4.1s |  |
| 568 | `orphan_movie_reorder` | 111 | 19.2s |  |
| 569 | `package_namespace` | 7 | 4.7s |  |
| 570 | `param_default_value_has_zero_cpool_index` | 1 | 4.5s |  |
| 571 | `parent_early_access_child` | 16 | 4.8s |  |
| 572 | `parse_float` | 80 | 4.8s |  |
| 573 | `pixelbender_effect_BlurredFocus` | 0 | 26.5s |  |
| 574 | `pixelbender_effect_glassDisplace` | 0 | 10.2s |  |
| 575 | `pixelbender_effect_smudge` | 0 | 8.2s |  |
| 576 | `pixelbender_effect_tintype` | 0 | 7.7s |  |
| 577 | `pixelbender_effect_twirl` | 0 | 8.3s |  |
| 578 | `pixelbender_images` | 0 | 7.3s |  |
| 579 | `place_multiple` | 17 | 4.5s |  |
| 580 | `place_object_replace` | 9 | 4.5s |  |
| 581 | `place_object_replace_2` | 24 | 22.6s |  |
| 582 | `place_object_same_depth_frame` | 1 | 4.5s |  |
| 583 | `primitive_edge_cases` | 1 | 4.3s |  |
| 584 | `property_priority` | 22 | 4.8s |  |
| 585 | `property_priority_three_level` | 6 | 4.5s |  |
| 586 | `propertyisenumerable_namespaces` | 6 | 4.4s |  |
| 587 | `prototype_set_null` | 7 | 4.4s |  |
| 588 | `proxy_callproperty` | 24 | 4.5s |  |
| 589 | `proxy_deleteproperty` | 64 | 4.5s |  |
| 590 | `proxy_enumeration` | 34 | 4.4s |  |
| 591 | `proxy_getproperty` | 77 | 4.5s |  |
| 592 | `proxy_hasownproperty` | 8 | 4.5s |  |
| 593 | `proxy_hasproperty` | 32 | 4.5s |  |
| 594 | `proxy_serialize` | 9 | 4.4s |  |
| 595 | `proxy_setproperty` | 42 | 4.5s |  |
| 596 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.4s |  |
| 597 | `qname_constr` | 32 | 4.5s |  |
| 598 | `qname_constr_namespace` | 24 | 4.5s |  |
| 599 | `qname_enumeration` | 9 | 4.5s |  |
| 600 | `qname_indexing` | 23 | 4.5s |  |
| 601 | `qname_tostring` | 25 | 4.5s |  |
| 602 | `qname_valueof` | 29 | 4.5s |  |
| 603 | `regexp_constr` | 148 | 4.7s |  |
| 604 | `regexp_exec` | 19 | 4.5s |  |
| 605 | `regexp_extended` | 47 | 4.4s |  |
| 606 | `regexp_multiargs` | 1 | 4.4s |  |
| 607 | `regexp_test` | 27 | 5.3s |  |
| 608 | `regexp_toString` | 10 | 4.5s |  |
| 609 | `register_script_refresh` | 35 | 4.9s |  |
| 610 | `remove_child_clear_field` | 88 | 4.8s |  |
| 611 | `remove_dobj` | 3 | 4.4s |  |
| 612 | `resolve_order` | 4 | 4.4s |  |
| 613 | `rng` | 1 | 5.7s |  |
| 614 | `rootless` | 42 | 4.4s |  |
| 615 | `rshift` | 1058 | 6.6s |  |
| 616 | `sandbox_type_local_file` | 1 | 4.4s |  |
| 617 | `scene_constr` | 8 | 4.5s |  |
| 618 | `set_property_is_enumerable` | 85 | 4.7s |  |
| 619 | `shape_drawrect` | 54 | 4.4s |  |
| 620 | `shared_object_no_root` | 3 | 4.5s |  |
| 621 | `simplebutton_added_to_stage` | 45 | 23.2s |  |
| 622 | `simplebutton_childevents` | 86 | 4.9s |  |
| 623 | `simplebutton_childevents_nested` | 54 | 4.8s |  |
| 624 | `simplebutton_childevents_sprite` | 13 | 4.5s |  |
| 625 | `simplebutton_childprops` | 144 | 4.6s |  |
| 626 | `simplebutton_childshuffle` | 23 | 4.3s |  |
| 627 | `simplebutton_constr` | 36 | 4.7s |  |
| 628 | `simplebutton_constr_childevents` | 48 | 4.7s |  |
| 629 | `simplebutton_constr_params` | 42 | 4.5s |  |
| 630 | `simplebutton_mouseenabled` | 26 | 4.5s |  |
| 631 | `simplebutton_multi_children` | 19 | 4.6s |  |
| 632 | `simplebutton_structure` | 27 | 4.7s |  |
| 633 | `simplebutton_symbolclass` | 68 | 4.7s |  |
| 634 | `slot_disp_id_shared_numbering` | 1 | 16.3s |  |
| 635 | `slots_force_autoassigned` | 1 | 2.9s |  |
| 636 | `sound_embeddedprops` | 26 | 3.0s |  |
| 637 | `sound_play` | 19 | 3.0s |  |
| 638 | `sound_valueof` | 33 | 2.9s |  |
| 639 | `soundchannel_soundtransform` | 835 | 16.6s |  |
| 640 | `soundchannel_soundtransform_exists` | 5 | 15.7s |  |
| 641 | `soundchannel_stop` | 8 | 3.0s |  |
| 642 | `soundmixer_buffertime` | 5 | 2.9s |  |
| 643 | `soundmixer_stopall` | 6 | 2.9s |  |
| 644 | `soundtransform` | 442 | 3.5s |  |
| 645 | `sprite_with_frames` | 0 | 3.3s |  |
| 646 | `stage3d_agal_cross_product` | 0 | 4.1s |  |
| 647 | `stage3d_bitmap` | 0 | 18.4s |  |
| 648 | `stage3d_float1_index` | 0 | 16.9s |  |
| 649 | `stage3d_fractal` | 0 | 7.6s |  |
| 650 | `stage3d_ignore_sampler_override` | 0 | 23.6s |  |
| 651 | `stage3d_program_constants_bytearray_be` | 0 | 23.5s |  |
| 652 | `stage3d_program_constants_bytearray_le` | 0 | 6.3s |  |
| 653 | `stage3d_raytrace` | 0 | 22.9s |  |
| 654 | `stage3d_rotating_cube` | 0 | 6.5s |  |
| 655 | `stage3d_sampler` | 0 | 5.9s |  |
| 656 | `stage3d_sampler_partial_upload` | 0 | 5.9s |  |
| 657 | `stage3d_stencil` | 0 | 24.1s |  |
| 658 | `stage3d_texture` | 0 | 9.8s |  |
| 659 | `stage3d_texture_bytearray` | 0 | 7.0s |  |
| 660 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 6.5s |  |
| 661 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 7.6s |  |
| 662 | `stage3d_triangle` | 0 | 6.0s |  |
| 663 | `stage3d_triangle_bytes4` | 0 | 6.0s |  |
| 664 | `stage3d_triangle_float1` | 0 | 5.8s |  |
| 665 | `stage3d_triangle_index_upload` | 0 | 5.9s |  |
| 666 | `stage_access` | 10 | 4.3s |  |
| 667 | `stage_displayobject_properties` | 24 | 4.2s |  |
| 668 | `stage_framerate_nan` | 7 | 4.4s |  |
| 669 | `stage_framerate_negative` | 6 | 4.3s |  |
| 670 | `stage_framerate_zero` | 6 | 4.3s |  |
| 671 | `stage_invalidate` | 38 | 4.4s |  |
| 672 | `stage_mousechildren` | 2 | 4.2s |  |
| 673 | `stage_mouseenabled` | 15 | 4.2s |  |
| 674 | `stage_overriden_setters` | 31 | 4.4s |  |
| 675 | `stage_properties` | 30 | 4.3s |  |
| 676 | `static_var_with_this_in_ctor` | 2 | 4.3s |  |
| 677 | `stored_properties` | 11 | 1.8s |  |
| 678 | `strict_equality` | 34 | 0.9s |  |
| 679 | `string_call` | 13 | 0.9s |  |
| 680 | `string_case` | 23 | 0.9s |  |
| 681 | `string_char_at` | 27 | 0.9s |  |
| 682 | `string_char_code_at` | 28 | 0.9s |  |
| 683 | `string_concat_fromcharcode` | 36 | 0.9s |  |
| 684 | `string_constr` | 25 | 0.9s |  |
| 685 | `string_indexof_lastindexof` | 87 | 0.9s |  |
| 686 | `string_length` | 16 | 0.9s |  |
| 687 | `string_locale_compare` | 39 | 0.9s |  |
| 688 | `string_match` | 51 | 0.9s |  |
| 689 | `string_relational_compare` | 4 | 0.9s |  |
| 690 | `string_replace` | 51 | 0.9s |  |
| 691 | `string_search` | 41 | 0.9s |  |
| 692 | `string_slice_substr_substring` | 169 | 0.9s |  |
| 693 | `string_split` | 29 | 0.9s |  |
| 694 | `string_substr_negative` | 21 | 0.9s |  |
| 695 | `string_substr_weird` | 182 | 0.9s |  |
| 696 | `subtract` | 1058 | 0.9s |  |
| 697 | `super_get_call` | 12 | 0.9s |  |
| 698 | `supercall_two_classobjects` | 2 | 0.9s |  |
| 699 | `swf8` | 1 | 0.9s |  |
| 700 | `swf_10_queued_goto_scripts_construct` | 52 | 0.9s |  |
| 701 | `swf_9_goto_in_enter_frame` | 17 | 0.9s |  |
| 702 | `swf_9_goto_in_enter_frame_simple` | 15 | 0.9s |  |
| 703 | `swf_9_queued_goto_scripts` | 6 | 0.9s |  |
| 704 | `swf_9_queued_goto_scripts_construct` | 28 | 0.9s |  |
| 705 | `swf_9_versioning` | 2 | 0.9s |  |
| 706 | `swf_wrong_frame_count` | 38 | 0.9s |  |
| 707 | `swf_wrong_frame_count_isplaying` | 22 | 5.3s |  |
| 708 | `symbol_class_conflict` | 4 | 5.1s |  |
| 709 | `symbol_class_root_not_zero` | 1 | 4.5s |  |
| 710 | `symbolclass_invalid_utf8` | 2 | 4.5s |  |
| 711 | `tab_ordering_automatic_advanced` | 184 | 5.0s |  |
| 712 | `tab_ordering_automatic_basic` | 45 | 4.6s |  |
| 713 | `tab_ordering_children` | 116 | 4.7s |  |
| 714 | `tab_ordering_custom_basic` | 34 | 4.7s |  |
| 715 | `text_engine_fontdescription` | 27 | 4.6s |  |
| 716 | `text_run` | 7 | 4.5s |  |
| 717 | `textfield_focusin_event` | 9 | 4.8s |  |
| 718 | `textfield_input_dead_keys_windows` | 15 | 4.8s |  |
| 719 | `textfield_unload` | 39 | 3.0s |  |
| 720 | `textformat` | 1134 | 4.8s |  |
| 721 | `textformat_display` | 14 | 4.8s |  |
| 722 | `textformat_font_max_length` | 4 | 4.8s |  |
| 723 | `throw` | 3 | 4.8s |  |
| 724 | `timeline_scripts` | 3 | 4.8s |  |
| 725 | `timer` | 90 | 5.3s |  |
| 726 | `timer_events` | 3 | 5.4s |  |
| 727 | `timer_finished` | 11 | 4.7s |  |
| 728 | `timer_reset` | 8 | 4.7s |  |
| 729 | `timer_setdelay` | 5 | 4.6s |  |
| 730 | `trace` | 12 | 4.5s |  |
| 731 | `truthiness` | 30 | 4.6s |  |
| 732 | `try_catch` | 11 | 4.7s |  |
| 733 | `try_catch_typed` | 12 | 4.6s |  |
| 734 | `typeof` | 30 | 4.6s |  |
| 735 | `uint_constr` | 92 | 4.7s |  |
| 736 | `uint_tofixed` | 1215 | 4.5s |  |
| 737 | `uint_tostring` | 3375 | 4.7s |  |
| 738 | `uncaught_errors_stringified` | 3 | 4.7s |  |
| 739 | `unchecked_function` | 15 | 4.6s |  |
| 740 | `urlrequest` | 18 | 4.6s |  |
| 741 | `urshift` | 1058 | 6.8s |  |
| 742 | `vector_class` | 36 | 4.9s |  |
| 743 | `vector_class_call` | 11 | 4.8s |  |
| 744 | `vector_coercion` | 66 | 5.2s |  |
| 745 | `vector_concat` | 90 | 4.9s |  |
| 746 | `vector_constr` | 107 | 4.8s |  |
| 747 | `vector_enumeration` | 5 | 4.7s |  |
| 748 | `vector_every` | 92 | 5.0s |  |
| 749 | `vector_filter` | 95 | 5.1s |  |
| 750 | `vector_holes` | 24 | 4.7s |  |
| 751 | `vector_indexof` | 302 | 5.5s |  |
| 752 | `vector_insertat` | 270 | 5.1s |  |
| 753 | `vector_int_access` | 4 | 4.6s |  |
| 754 | `vector_int_delete` | 11 | 4.6s |  |
| 755 | `vector_join` | 58 | 4.8s |  |
| 756 | `vector_lastindexof` | 302 | 4.5s |  |
| 757 | `vector_legacy` | 10 | 4.6s |  |
| 758 | `vector_map` | 85 | 5.7s |  |
| 759 | `vector_object_final` | 1 | 4.1s |  |
| 760 | `vector_object_toString` | 10 | 4.1s |  |
| 761 | `vector_pushpop` | 255 | 4.6s |  |
| 762 | `vector_reborrow_bug` | 10 | 4.0s |  |
| 763 | `vector_removeat` | 172 | 4.4s |  |
| 764 | `vector_reverse` | 232 | 4.4s |  |
| 765 | `vector_shiftunshift` | 252 | 4.1s |  |
| 766 | `vector_slice` | 331 | 4.6s |  |
| 767 | `vector_sort` | 905 | 5.8s |  |
| 768 | `vector_splice` | 693 | 4.8s |  |
| 769 | `vector_splice_fixed_bug_compat` | 4 | 4.0s |  |
| 770 | `vector_tostring` | 79 | 4.3s |  |
| 771 | `verify_abnormal_loop` | 1 | 3.9s |  |
| 772 | `verify_exception_targets_edge_case` | 1 | 4.0s |  |
| 773 | `verify_lookup_switch_edge_case` | 1 | 4.0s |  |
| 774 | `verify_unreachable_exception` | 2 | 3.9s |  |
| 775 | `versioned_isplaying` | 2 | 4.0s |  |
| 776 | `virtual_properties` | 16 | 2.1s |  |
| 777 | `with` | 4 | 4.1s |  |
| 778 | `xml_abstract_equality` | 36 | 4.2s |  |
| 779 | `xml_advanced` | 52 | 4.0s |  |
| 780 | `xml_appendchild` | 10 | 4.0s |  |
| 781 | `xml_as_attribute` | 9 | 4.0s |  |
| 782 | `xml_attribute` | 35 | 4.2s |  |
| 783 | `xml_attribute_name` | 40 | 4.1s |  |
| 784 | `xml_basic` | 32 | 4.5s |  |
| 785 | `xml_child` | 25 | 4.1s |  |
| 786 | `xml_childindex` | 7 | 2.1s |  |
| 787 | `xml_children` | 43 | 4.5s |  |
| 788 | `xml_class_call` | 9 | 4.0s |  |
| 789 | `xml_contains` | 197 | 5.4s |  |
| 790 | `xml_copy` | 20 | 4.6s |  |
| 791 | `xml_ctor_from_tostring` | 23 | 4.6s |  |
| 792 | `xml_delete` | 114 | 4.6s |  |
| 793 | `xml_descendants` | 83 | 4.4s |  |
| 794 | `xml_elements` | 6 | 4.4s |  |
| 795 | `xml_equals_namespace_check` | 2 | 4.4s |  |
| 796 | `xml_explicit_use_namespace` | 5 | 4.4s |  |
| 797 | `xml_getdescendants_qname` | 21 | 4.4s |  |
| 798 | `xml_has_property_via_in` | 26 | 4.4s |  |
| 799 | `xml_hasownproperty` | 6 | 4.5s |  |
| 800 | `xml_ignore_white` | 6 | 4.5s |  |
| 801 | `xml_length` | 2 | 4.5s |  |
| 802 | `xml_list_as_attribute` | 9 | 4.4s |  |
| 803 | `xml_list_concat` | 20 | 4.5s |  |
| 804 | `xml_list_enumerate` | 4 | 4.4s |  |
| 805 | `xml_methods_settings` | 3 | 4.5s |  |
| 806 | `xml_mismatched_tag` | 37 | 4.4s |  |
| 807 | `xml_namespace` | 39 | 4.4s |  |
| 808 | `xml_namespace_methods` | 245 | 4.5s |  |
| 809 | `xml_namespaced_property` | 7 | 4.5s |  |
| 810 | `xml_no_namespace` | 1 | 4.5s |  |
| 811 | `xml_nodekind` | 3 | 4.6s |  |
| 812 | `xml_normalize` | 35 | 4.5s |  |
| 813 | `xml_notification_bubbling` | 361 | 4.5s |  |
| 814 | `xml_parent` | 8 | 4.5s |  |
| 815 | `xml_set_children` | 17 | 4.5s |  |
| 816 | `xml_set_name` | 34 | 4.6s |  |
| 817 | `xml_settings` | 6 | 2.6s |  |
| 818 | `xml_simple_complex_content` | 47 | 4.6s |  |
| 819 | `xml_text` | 7 | 4.6s |  |
| 820 | `xml_tostring` | 6 | 4.5s |  |
| 821 | `xml_tostring_namespace` | 12 | 4.6s |  |
| 822 | `xml_unescaping` | 23 | 4.5s |  |
| 823 | `xml_weird_ignores` | 54 | 4.5s |  |
| 824 | `xml_wildcard` | 11 | 4.5s |  |
| 825 | `xmldocument` | 254 | 4.5s |  |
| 826 | `xmlnode` | 3540 | 4.5s |  |
| 827 | `zero_frame_clip` | 3 | 4.5s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 1 | 4.3s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 5.4s |  |
| 3 | `blend_transform` | 1 | 1 | 5.0s |  |
| 4 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 4.9s |  |
| 5 | `dictionary_weak_keys` | 1 | 1 | 22.7s |  |
| 6 | `edittext_getcharboundaries_culling` | 300 | 300 | 4.4s |  |
| 7 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 3.9s |  |
| 8 | `edittext_tab_stops` | 6 | 6 | 4.8s |  |
| 9 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 4.5s |  |
| 10 | `error_1034_debug_string` | 19 | 19 | 4.6s |  |
| 11 | `freestanding_superclass` | 3 | 4 | 4.4s |  |
| 12 | `goto_framescript_queued` | 5 | 5 | 4.7s |  |
| 13 | `int_toexponential` | 76 | 76 | 4.9s |  |
| 14 | `int_toprecision` | 441 | 441 | 4.9s |  |
| 15 | `simplebutton_childevents_script_order` | 4 | 4 | 4.6s |  |
| 16 | `slot_holes_fail` | 1 | 1 | 2.9s |  |
| 17 | `slot_id_exceeds_trait_count` | 1 | 1 | 2.9s |  |
| 18 | `soundchannel_position` | 74 | 74 | 16.3s |  |
| 19 | `soundchannel_soundcomplete` | 10 | 10 | 3.0s |  |
| 20 | `sprite_dropTarget` | 4 | 4 | 2.9s |  |
| 21 | `swf_9_goto_in_construct_frame` | 12 | 12 | 0.9s |  |
| 22 | `uint_toexponential` | 100 | 100 | 4.7s |  |
| 23 | `uint_toprecision` | 433 | 433 | 4.7s |  |
| 24 | `weird_superinterface_properties` | 1 | 1 | 4.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**62 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `parse_int` | 98.5% | 132 | 134 | 2 |  |
| 5 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 6 | `parse_float_swf10` | 97.5% | 78 | 80 | 2 |  |
| 7 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 8 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 9 | `selection` | 95.8% | 229 | 239 | 10 |  |
| 10 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 12 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 14 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 15 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 16 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 17 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 18 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 19 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 20 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 21 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 22 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 23 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 24 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 25 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 26 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 28 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 29 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 30 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 31 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 32 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 33 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 34 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 35 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 36 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 37 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 38 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 39 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 40 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 41 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 42 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 43 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 44 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 45 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 46 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 47 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 48 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 49 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 50 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 51 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 52 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 53 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 54 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 55 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 56 | `date` | 50.0% | 15 | 30 | 15 |  |
| 57 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 58 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 59 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 60 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 61 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 62 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 4.4s |  |
| 2 | `method_without_body` | exit code 1 | 23.0s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 4.6s |  |
| 4 | `verify_typecheck` | exit code 1 | 3.9s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 34.3s |  |

## All Output Mismatches

**348 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `parse_int` | 98.5% | 132/134 | 134 | 134 |  |
| 5 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 6 | `parse_float_swf10` | 97.5% | 78/80 | 80 | 80 |  |
| 7 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 8 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 9 | `selection` | 95.8% | 229/239 | 239 | 239 |  |
| 10 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 12 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 14 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 15 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 16 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 17 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 18 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 19 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 20 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 21 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 22 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 23 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 24 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 25 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 26 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 28 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 29 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 30 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 31 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 32 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 33 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 34 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 35 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 36 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 37 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 38 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 39 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 40 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 41 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 42 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 43 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 44 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 45 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 46 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 47 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 48 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 49 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 50 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 51 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 52 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 53 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 54 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 57 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 58 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 59 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 60 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 61 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 62 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 63 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 64 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 65 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 66 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 67 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 68 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 69 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 70 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 71 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 72 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 73 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 74 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 75 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 76 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 77 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 78 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 79 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 80 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 81 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 82 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 83 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 84 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 85 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 86 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 87 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 88 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 89 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 90 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 91 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 92 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 93 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 94 | `focus_events_key_navigation` | 17.0% | 9/53 | 12 | 53 |  |
| 95 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 96 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 97 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 98 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 99 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 100 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 101 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 102 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 103 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 104 | `point` | 12.1% | 16/132 | 16 | 132 |  |
| 105 | `focus_events_key_basic` | 11.6% | 17/147 | 147 | 132 |  |
| 106 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 107 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 108 | `geom_transform` | 10.8% | 8/74 | 9 | 74 |  |
| 109 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 110 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 111 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 112 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 113 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 114 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 115 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 116 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 117 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 118 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 119 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 120 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 121 | `pixelbender_sign` | 5.0% | 3/60 | 16 | 60 |  |
| 122 | `loader_method` | 4.8% | 4/83 | 11 | 83 |  |
| 123 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 124 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 125 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 126 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 127 | `pixelbender_ceil` | 3.9% | 3/77 | 16 | 77 |  |
| 128 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 129 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 130 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 131 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 132 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 133 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 134 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 135 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 136 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 137 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 138 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 139 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 140 | `loader_load` | 2.4% | 3/126 | 11 | 126 |  |
| 141 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 142 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 143 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 144 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 145 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 146 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 147 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 148 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 149 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 150 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 151 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 152 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 153 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 154 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 155 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 156 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 157 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 158 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 159 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 160 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 161 | `all_classes/display/swf9` | 0.2% | 3/1959 | 188 | 1959 |  |
| 162 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 163 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 164 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 165 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 166 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 167 | `all_classes/display/swf10` | 0.0% | 1/2569 | 188 | 2569 |  |
| 168 | `all_classes/display/swf11` | 0.0% | 1/2593 | 188 | 2593 |  |
| 169 | `all_classes/display/swf12` | 0.0% | 1/2593 | 188 | 2593 |  |
| 170 | `all_classes/display/swf13` | 0.0% | 1/2671 | 188 | 2671 |  |
| 171 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 172 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 173 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 174 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 175 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 176 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 177 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 178 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 179 | `all_classes/display/swf30` | 0.0% | 0/2936 | 188 | 2936 |  |
| 180 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 181 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 182 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 183 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 184 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 185 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 186 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 187 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 188 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 189 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 190 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 191 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 192 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 193 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 194 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 195 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 196 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 197 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 198 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 199 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 200 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 201 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 202 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 203 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 204 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 205 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 206 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 207 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 208 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 209 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 210 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 211 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 212 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 213 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 214 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 215 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 216 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 217 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 218 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 219 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 220 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
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
| 233 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 234 | `graphics_draw_path` | 0.0% | 0/101 | 0 | 101 |  |
| 235 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 236 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 237 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 238 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 239 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 240 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 241 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 242 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 243 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 244 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 245 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 246 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 247 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 248 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 249 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 250 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 251 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 252 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 253 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 254 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 255 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 256 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 257 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 258 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 259 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 260 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 261 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 262 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 263 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 264 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 265 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 266 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 267 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 268 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 269 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 270 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 271 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 272 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 273 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 274 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 275 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 276 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 277 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 278 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 279 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 280 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 281 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 282 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 283 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 284 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 285 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 286 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 287 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 288 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 289 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 290 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 291 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 292 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 293 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 294 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 295 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 296 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 297 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 298 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 299 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 300 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 301 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 302 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 303 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 304 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 305 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 306 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 307 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 308 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 309 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 310 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 311 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 312 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 313 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 314 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 315 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 316 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 317 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 318 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 319 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 320 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 321 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 322 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 323 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 324 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 325 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 326 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 327 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 328 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 329 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 330 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 331 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 332 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 333 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 334 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 335 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 336 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 337 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 338 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 339 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 340 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 341 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 342 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 343 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 344 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 345 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 346 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 347 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 348 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
