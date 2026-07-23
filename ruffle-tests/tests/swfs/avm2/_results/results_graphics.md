# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-23 17:18 UTC

**Git SHA**: `8cf9ce9e48`

**Run Duration**: 177m 56s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1216 |
| Passing | **829** (68.2%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **855** (70.3%) |
| Failing | 361 |
| Total expected lines | 151084 |
| Matching lines | 103606 (68.6%) |
| Mismatched lines | 47478 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 356 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**829 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 4.8s |  |
| 2 | `agal_compiler` | 13 | 4.8s |  |
| 3 | `air_hidden_lookup` | 2 | 4.7s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.7s |  |
| 5 | `amf_custom_obj` | 26 | 4.7s |  |
| 6 | `amf_dictionary` | 9 | 4.7s |  |
| 7 | `amf_function` | 46 | 4.7s |  |
| 8 | `amf_invalid_date` | 2 | 4.7s |  |
| 9 | `amf_missing_prop` | 6 | 4.7s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 5.4s |  |
| 11 | `amf_setter_error` | 8 | 5.5s |  |
| 12 | `amf_vector` | 40 | 5.6s |  |
| 13 | `amf_xml` | 6 | 5.5s |  |
| 14 | `application_domain` | 4 | 5.5s |  |
| 15 | `array_access` | 18 | 5.6s |  |
| 16 | `array_access_interpreter` | 4 | 5.6s |  |
| 17 | `array_access_no_pubns` | 2 | 5.5s |  |
| 18 | `array_concat` | 41 | 5.7s |  |
| 19 | `array_constr` | 10 | 5.6s |  |
| 20 | `array_delete` | 44 | 5.8s |  |
| 21 | `array_enumeration` | 10 | 5.6s |  |
| 22 | `array_enumeration_elements` | 11 | 5.5s |  |
| 23 | `array_every` | 8 | 5.6s |  |
| 24 | `array_filter` | 6 | 5.5s |  |
| 25 | `array_foreach` | 18 | 5.4s |  |
| 26 | `array_hasownproperty` | 11 | 2.5s |  |
| 27 | `array_holes` | 9 | 5.4s |  |
| 28 | `array_index_max` | 84 | 5.2s |  |
| 29 | `array_indexof` | 25 | 5.5s |  |
| 30 | `array_join` | 26 | 5.4s |  |
| 31 | `array_lastindexof` | 29 | 5.5s |  |
| 32 | `array_length` | 14 | 5.6s |  |
| 33 | `array_literal` | 3 | 5.4s |  |
| 34 | `array_map` | 8 | 5.4s |  |
| 35 | `array_pop` | 52 | 5.6s |  |
| 36 | `array_push` | 24 | 5.5s |  |
| 37 | `array_reborrow_bug` | 6 | 5.4s |  |
| 38 | `array_reverse` | 28 | 5.4s |  |
| 39 | `array_shift` | 51 | 2.6s |  |
| 40 | `array_slice` | 39 | 5.5s |  |
| 41 | `array_some` | 8 | 5.6s |  |
| 42 | `array_sort` | 297 | 6.0s |  |
| 43 | `array_sort_fun_swf12` | 2 | 5.5s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 45 | `array_sort_random` | 210 | 5.6s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 5.5s |  |
| 47 | `array_sorton` | 545 | 6.6s |  |
| 48 | `array_sparse_ops` | 41 | 6.0s |  |
| 49 | `array_splice` | 133 | 6.0s |  |
| 50 | `array_splice2` | 428 | 6.1s |  |
| 51 | `array_splice_types` | 48 | 6.0s |  |
| 52 | `array_storage` | 8 | 5.7s |  |
| 53 | `array_tolocalestring` | 9 | 5.7s |  |
| 54 | `array_tostring` | 12 | 5.7s |  |
| 55 | `array_unshift` | 24 | 5.8s |  |
| 56 | `array_valueof` | 9 | 5.6s |  |
| 57 | `array_vector_null_callback` | 10 | 5.8s |  |
| 58 | `astype` | 28 | 5.8s |  |
| 59 | `astypelate` | 24 | 5.9s |  |
| 60 | `astypelate_propagates` | 1 | 5.7s |  |
| 61 | `asymmetric_key_events` | 11 | 6.1s |  |
| 62 | `avm2_catchup_dobj` | 158 | 6.4s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 79.0s |  |
| 64 | `bitand` | 1058 | 16.9s |  |
| 65 | `bitmap_constr` | 17 | 5.9s |  |
| 66 | `bitmap_data` | 1000 | 13.4s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 24.8s |  |
| 68 | `bitmap_properties` | 23 | 5.8s |  |
| 69 | `bitmap_subclass` | 7 | 6.1s |  |
| 70 | `bitmap_subclass_properties` | 9 | 6.3s |  |
| 71 | `bitmap_timeline` | 9 | 5.8s |  |
| 72 | `bitmapdata_accuracy` | 1 | 44.5s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 25.3s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.7s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 25.1s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.4s |  |
| 77 | `bitmapdata_clone` | 13 | 6.1s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.3s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 5.7s |  |
| 80 | `bitmapdata_constr` | 22 | 5.8s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 6.1s |  |
| 82 | `bitmapdata_copychannel` | 0 | 26.8s |  |
| 83 | `bitmapdata_copypixels` | 23 | 26.4s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.9s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.8s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.8s |  |
| 87 | `bitmapdata_draw` | 0 | 25.8s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 25.0s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 24.7s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 25.0s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 6.1s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.3s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.4s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 25.8s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 6.2s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.5s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.1s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 24.7s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.7s |  |
| 100 | `bitmapdata_getpixels` | 39 | 24.1s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 103 | `bitmapdata_hittest` | 112 | 6.2s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.7s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.0s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 24.5s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.2s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.7s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.8s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.8s |  |
| 111 | `bitmapdata_sync` | 0 | 5.9s |  |
| 112 | `bitmapdata_threshold` | 176 | 6.4s |  |
| 113 | `bitnot` | 46 | 5.7s |  |
| 114 | `bitor` | 1058 | 16.8s |  |
| 115 | `bitxor` | 1058 | 16.8s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.0s |  |
| 117 | `blend_scroll` | 0 | 6.0s |  |
| 118 | `boolean_constr` | 32 | 5.5s |  |
| 119 | `boolean_negation` | 30 | 5.5s |  |
| 120 | `boolean_tostring` | 8 | 5.4s |  |
| 121 | `broadcast_event` | 7 | 5.5s |  |
| 122 | `button_nested_frame` | 48 | 24.2s |  |
| 123 | `bytearray` | 48 | 5.7s |  |
| 124 | `bytearray_compress` | 31 | 5.5s |  |
| 125 | `bytearray_errors` | 24 | 5.6s |  |
| 126 | `bytearray_method_serialization` | 1 | 5.4s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 5.5s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 5.5s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 5.5s |  |
| 130 | `bytearray_serialization` | 3 | 5.4s |  |
| 131 | `bytearray_string_null` | 19 | 5.7s |  |
| 132 | `bytearray_tostring` | 15 | 5.5s |  |
| 133 | `bytearray_utf16` | 8 | 5.4s |  |
| 134 | `bytearray_writeobject` | 24 | 5.3s |  |
| 135 | `callee_in_initializer` | 6 | 5.4s |  |
| 136 | `callproplex_class` | 1 | 5.4s |  |
| 137 | `catch_class` | 6 | 5.4s |  |
| 138 | `catch_scope_slot` | 7 | 2.7s |  |
| 139 | `checkfilter` | 4 | 2.6s |  |
| 140 | `class_call` | 32 | 23.2s |  |
| 141 | `class_cast_call` | 14 | 5.4s |  |
| 142 | `class_enumeration` | 4 | 5.5s |  |
| 143 | `class_has_own_property` | 2 | 5.4s |  |
| 144 | `class_init_interpreter_mode` | 1 | 5.3s |  |
| 145 | `class_is` | 32 | 5.5s |  |
| 146 | `class_methods` | 5 | 5.4s |  |
| 147 | `class_object_properties` | 10 | 5.5s |  |
| 148 | `class_singleton` | 18 | 5.5s |  |
| 149 | `class_supercalls_errors` | 35 | 5.7s |  |
| 150 | `class_supercalls_mismatched` | 26 | 5.5s |  |
| 151 | `class_superclass_wrong_order` | 1 | 24.4s |  |
| 152 | `class_to_locale_string` | 2 | 5.8s |  |
| 153 | `class_to_string` | 2 | 5.8s |  |
| 154 | `class_value_of` | 2 | 5.8s |  |
| 155 | `click_block` | 5 | 25.2s |  |
| 156 | `click_invisible` | 3 | 6.0s |  |
| 157 | `closures` | 12 | 5.9s |  |
| 158 | `coerce_return_type` | 40 | 6.0s |  |
| 159 | `coerce_return_type_fail` | 2 | 5.7s |  |
| 160 | `coerce_return_void` | 3 | 5.7s |  |
| 161 | `coerce_string` | 86 | 6.0s |  |
| 162 | `coerce_string_precision` | 28 | 5.9s |  |
| 163 | `coerce_to_primitive_side_effects` | 29 | 5.9s |  |
| 164 | `construct_errors_swf10` | 8 | 5.8s |  |
| 165 | `construct_frame_list` | 22 | 25.2s |  |
| 166 | `constructor_call` | 3 | 5.7s |  |
| 167 | `constructors_vs_timeline` | 5 | 24.8s |  |
| 168 | `constructprop_dynamic_primitive` | 7 | 6.0s |  |
| 169 | `control_flow_bool` | 4 | 5.7s |  |
| 170 | `control_flow_stricteq` | 8 | 5.8s |  |
| 171 | `convert_boolean` | 30 | 5.9s |  |
| 172 | `convert_integer` | 90 | 5.9s |  |
| 173 | `convert_number` | 56 | 5.9s |  |
| 174 | `convert_uinteger` | 90 | 5.9s |  |
| 175 | `cryptscore` | 11 | 5.9s |  |
| 176 | `declocal` | 46 | 6.0s |  |
| 177 | `declocal_i` | 46 | 6.1s |  |
| 178 | `decrement` | 46 | 6.1s |  |
| 179 | `decrement_i` | 46 | 3.0s |  |
| 180 | `default_values` | 7 | 6.0s |  |
| 181 | `dictionary_access` | 62 | 6.3s |  |
| 182 | `dictionary_access_no_pubns` | 2 | 6.0s |  |
| 183 | `dictionary_delete` | 101 | 6.7s |  |
| 184 | `dictionary_foreach` | 42 | 6.4s |  |
| 185 | `dictionary_hasownproperty` | 63 | 6.4s |  |
| 186 | `dictionary_in` | 62 | 6.3s |  |
| 187 | `dictionary_iter_modify` | 8 | 6.1s |  |
| 188 | `dictionary_namespaces` | 36 | 6.1s |  |
| 189 | `dictionary_primitive_keys` | 29 | 6.1s |  |
| 190 | `displayobject_alpha` | 277 | 6.0s |  |
| 191 | `displayobject_blendmode` | 0 | 6.2s |  |
| 192 | `displayobject_colortransform_nested` | 0 | 26.4s |  |
| 193 | `displayobject_from_enterframe` | 1 | 26.2s |  |
| 194 | `displayobject_getbounds_shape` | 0 | 26.5s |  |
| 195 | `displayobject_height` | 6052 | 26.3s |  |
| 196 | `displayobject_hittestobject` | 32 | 6.0s |  |
| 197 | `displayobject_invalid_floats` | 60 | 5.8s |  |
| 198 | `displayobject_invalid_props` | 3 | 5.8s |  |
| 199 | `displayobject_mask` | 3 | 6.2s |  |
| 200 | `displayobject_mask_self_referential` | 0 | 5.7s |  |
| 201 | `displayobject_metaData` | 3 | 25.1s |  |
| 202 | `displayobject_name` | 22 | 25.7s |  |
| 203 | `displayobject_name_from_timeline` | 24 | 26.2s |  |
| 204 | `displayobject_parent` | 12 | 5.8s |  |
| 205 | `displayobject_root` | 24 | 6.0s |  |
| 206 | `displayobject_rotation` | 1284 | 6.2s |  |
| 207 | `displayobject_set_matrix_nested` | 0 | 26.2s |  |
| 208 | `displayobject_subclass` | 2 | 6.0s |  |
| 209 | `displayobject_visible` | 23 | 6.0s |  |
| 210 | `displayobject_width` | 4852 | 26.3s |  |
| 211 | `displayobject_x` | 614 | 6.0s |  |
| 212 | `displayobject_y` | 617 | 6.0s |  |
| 213 | `displayobjectcontainer_addchild` | 32 | 6.1s |  |
| 214 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.0s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.2s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.0s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.1s |  |
| 218 | `displayobjectcontainer_addchildat` | 42 | 6.0s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.1s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.1s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.1s |  |
| 222 | `displayobjectcontainer_contains` | 66 | 25.9s |  |
| 223 | `displayobjectcontainer_getchildat` | 4 | 6.0s |  |
| 224 | `displayobjectcontainer_getchildbyname` | 9 | 6.0s |  |
| 225 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.9s |  |
| 226 | `displayobjectcontainer_getchildindex` | 28 | 6.0s |  |
| 227 | `displayobjectcontainer_removechild` | 10 | 5.8s |  |
| 228 | `displayobjectcontainer_removechild_errors` | 4 | 5.7s |  |
| 229 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.9s |  |
| 230 | `displayobjectcontainer_removechildat` | 18 | 5.8s |  |
| 231 | `displayobjectcontainer_removechildren` | 51 | 6.1s |  |
| 232 | `displayobjectcontainer_setchildindex` | 42 | 5.7s |  |
| 233 | `displayobjectcontainer_stopallmovieclips` | 2 | 25.2s |  |
| 234 | `displayobjectcontainer_swapchildren` | 42 | 5.7s |  |
| 235 | `displayobjectcontainer_swapchildrenat` | 42 | 5.7s |  |
| 236 | `displayobjectcontainer_timelineinstance` | 48 | 24.6s |  |
| 237 | `divide` | 1058 | 17.3s |  |
| 238 | `doabc_is_eager` | 1 | 24.2s |  |
| 239 | `documentclass` | 9 | 5.8s |  |
| 240 | `drag_drop` | 10 | 5.9s |  |
| 241 | `duplicate_defs` | 1 | 5.6s |  |
| 242 | `eager_init` | 1 | 5.8s |  |
| 243 | `edit_text_linkage` | 7 | 5.9s |  |
| 244 | `edittext_align` | 60 | 6.2s |  |
| 245 | `edittext_always_show_selection` | 0 | 24.9s |  |
| 246 | `edittext_antialiastype` | 296 | 6.0s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 7.1s |  |
| 248 | `edittext_autosize` | 39 | 6.1s |  |
| 249 | `edittext_autosize_align` | 0 | 25.0s |  |
| 250 | `edittext_autosize_height_dynamic` | 60 | 24.9s |  |
| 251 | `edittext_autosize_height_input` | 60 | 5.9s |  |
| 252 | `edittext_autosize_lazy_bounds_events` | 65 | 6.0s |  |
| 253 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.8s |  |
| 254 | `edittext_autosize_lazy_bounds_props` | 490 | 7.2s |  |
| 255 | `edittext_autosize_lazy_bounds_visual` | 0 | 24.5s |  |
| 256 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.0s |  |
| 257 | `edittext_bottom_scroll_v_basic` | 210 | 5.9s |  |
| 258 | `edittext_bounds_scale` | 24 | 24.2s |  |
| 259 | `edittext_bullet` | 30 | 5.8s |  |
| 260 | `edittext_default_format` | 221 | 6.1s |  |
| 261 | `edittext_default_format_empty` | 136 | 6.0s |  |
| 262 | `edittext_empty_text_format` | 7 | 5.8s |  |
| 263 | `edittext_focus_selection` | 5 | 5.9s |  |
| 264 | `edittext_font_size` | 45 | 5.8s |  |
| 265 | `edittext_format_empty_font` | 8 | 5.7s |  |
| 266 | `edittext_get_char_index_at_point` | 4 | 25.0s |  |
| 267 | `edittext_get_line_index_at_point` | 2 | 24.9s |  |
| 268 | `edittext_get_line_index_of_char` | 76 | 6.7s |  |
| 269 | `edittext_getcharboundaries` | 172 | 6.1s |  |
| 270 | `edittext_getcharboundaries_missing_glyphs` | 63 | 24.2s |  |
| 271 | `edittext_getcharboundaries_scroll` | 85 | 5.5s |  |
| 272 | `edittext_getlinemetrics` | 146 | 5.6s |  |
| 273 | `edittext_html` | 3101 | 5.8s |  |
| 274 | `edittext_html_condensewhite` | 487 | 5.3s |  |
| 275 | `edittext_html_entity` | 4 | 5.6s |  |
| 276 | `edittext_html_font_size_swf12` | 267 | 5.5s |  |
| 277 | `edittext_html_font_size_swf13` | 273 | 5.1s |  |
| 278 | `edittext_html_roundtrip` | 17 | 5.5s |  |
| 279 | `edittext_input_control` | 12 | 5.5s |  |
| 280 | `edittext_leading` | 9 | 5.8s |  |
| 281 | `edittext_letter_spacing` | 15 | 5.4s |  |
| 282 | `edittext_line_methods` | 294 | 6.3s |  |
| 283 | `edittext_line_metrics` | 11 | 24.8s |  |
| 284 | `edittext_margins` | 25 | 5.4s |  |
| 285 | `edittext_max_scroll_h_basic` | 475 | 5.6s |  |
| 286 | `edittext_max_scroll_v_basic` | 1000 | 5.4s |  |
| 287 | `edittext_mousedown` | 3 | 5.7s |  |
| 288 | `edittext_mouseenabled` | 26 | 5.3s |  |
| 289 | `edittext_newline_character` | 22 | 5.3s |  |
| 290 | `edittext_newline_stripping` | 64 | 7.9s |  |
| 291 | `edittext_newlines` | 30 | 5.5s |  |
| 292 | `edittext_paragraph_methods` | 257 | 5.4s |  |
| 293 | `edittext_paste_events` | 8 | 5.5s |  |
| 294 | `edittext_paste_maxchars` | 4 | 5.3s |  |
| 295 | `edittext_paste_restrict` | 16 | 5.2s |  |
| 296 | `edittext_restrict` | 191 | 5.3s |  |
| 297 | `edittext_restrict_events` | 22 | 5.3s |  |
| 298 | `edittext_scrollh` | 10 | 5.3s |  |
| 299 | `edittext_selected_text` | 9 | 5.3s |  |
| 300 | `edittext_set_html_same` | 17 | 5.3s |  |
| 301 | `edittext_set_text_vs_html` | 9 | 5.2s |  |
| 302 | `edittext_stylesheet` | 536 | 5.6s |  |
| 303 | `edittext_stylesheet_custom_tag` | 76 | 5.4s |  |
| 304 | `edittext_stylesheet_display` | 272 | 5.4s |  |
| 305 | `edittext_underline` | 40 | 5.4s |  |
| 306 | `edittext_width_height` | 103 | 5.6s |  |
| 307 | `edittext_wordwrap_word` | 150 | 5.8s |  |
| 308 | `edittext_wrap_breaks` | 2375 | 6.0s |  |
| 309 | `empty_bounds` | 1 | 5.4s |  |
| 310 | `equals` | 512 | 9.5s |  |
| 311 | `error_prototype` | 15 | 5.4s |  |
| 312 | `error_stack_trace_debug_swf17` | 0 | 23.6s |  |
| 313 | `error_stack_trace_debug_swf18` | 0 | 5.3s |  |
| 314 | `error_stack_trace_release_swf17` | 0 | 5.3s |  |
| 315 | `error_stack_trace_release_swf18` | 0 | 5.3s |  |
| 316 | `error_tostring` | 29 | 5.4s |  |
| 317 | `es3_inheritance` | 31 | 5.5s |  |
| 318 | `es4_inheritance` | 30 | 5.5s |  |
| 319 | `es4_interfaces` | 30 | 5.5s |  |
| 320 | `es4_method_binding` | 8 | 5.4s |  |
| 321 | `es4_oop_prototypes` | 14 | 5.6s |  |
| 322 | `es4_protected_inheritance` | 6 | 5.4s |  |
| 323 | `event_bubbles` | 2 | 5.4s |  |
| 324 | `event_cancelable` | 2 | 5.3s |  |
| 325 | `event_clone` | 20 | 5.4s |  |
| 326 | `event_clone_error_redispatch` | 3 | 5.5s |  |
| 327 | `event_clone_on_redispatch` | 10 | 5.6s |  |
| 328 | `event_formattostring` | 31 | 5.5s |  |
| 329 | `event_isdefaultprevented` | 12 | 5.4s |  |
| 330 | `event_target_getter` | 5 | 2.6s |  |
| 331 | `event_target_set` | 9 | 5.3s |  |
| 332 | `event_type` | 1 | 5.4s |  |
| 333 | `event_valueof_tostring` | 18 | 5.9s |  |
| 334 | `eventdispatcher_dispatchevent` | 12 | 5.8s |  |
| 335 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.0s |  |
| 336 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.9s |  |
| 337 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.9s |  |
| 338 | `eventdispatcher_dispatchevent_this` | 5 | 5.8s |  |
| 339 | `eventdispatcher_haseventlistener` | 25 | 5.8s |  |
| 340 | `eventdispatcher_interface_invoke` | 1 | 5.9s |  |
| 341 | `eventdispatcher_tostring` | 10 | 6.0s |  |
| 342 | `eventdispatcher_willtrigger` | 25 | 5.8s |  |
| 343 | `falsiness` | 30 | 5.8s |  |
| 344 | `fast_index_access` | 12 | 6.0s |  |
| 345 | `finddef` | 3 | 5.8s |  |
| 346 | `findprop_global_prototype` | 6 | 5.8s |  |
| 347 | `flash_xml` | 29 | 6.0s |  |
| 348 | `flash_xml_cloneNode` | 22 | 5.9s |  |
| 349 | `flash_xml_namespace` | 109 | 6.0s |  |
| 350 | `flash_xml_removeNode` | 60 | 5.9s |  |
| 351 | `focus_events_code` | 161 | 25.4s |  |
| 352 | `focus_events_key_same_object` | 26 | 5.9s |  |
| 353 | `focus_events_mixed_key_mouse` | 100 | 27.0s |  |
| 354 | `focus_events_mouse_same_object` | 40 | 25.3s |  |
| 355 | `focus_remove` | 20 | 25.6s |  |
| 356 | `focus_root_movie` | 4 | 27.6s |  |
| 357 | `focus_stage` | 1 | 5.9s |  |
| 358 | `focusrect` | 18 | 6.7s |  |
| 359 | `font_description_clone` | 14 | 5.9s |  |
| 360 | `font_embedded` | 24 | 6.2s |  |
| 361 | `font_enumeratefonts` | 41 | 6.4s |  |
| 362 | `font_enumeratefonts_filter` | 4 | 25.6s |  |
| 363 | `font_hasglyphs` | 40 | 6.2s |  |
| 364 | `framelabel_constr` | 5 | 5.9s |  |
| 365 | `function_call` | 12 | 5.8s |  |
| 366 | `function_call_arguments` | 46 | 5.9s |  |
| 367 | `function_call_arguments_enumerate` | 5 | 5.7s |  |
| 368 | `function_call_coercion` | 108 | 6.2s |  |
| 369 | `function_call_default` | 6 | 5.7s |  |
| 370 | `function_call_rest` | 22 | 5.7s |  |
| 371 | `function_call_types` | 3 | 5.7s |  |
| 372 | `function_call_via_apply` | 11 | 5.7s |  |
| 373 | `function_call_via_call` | 3 | 5.7s |  |
| 374 | `function_display_anonymous` | 7 | 2.8s |  |
| 375 | `function_length` | 6 | 5.8s |  |
| 376 | `function_object` | 2 | 5.8s |  |
| 377 | `function_proto` | 5 | 5.7s |  |
| 378 | `function_proto_created` | 61 | 5.8s |  |
| 379 | `function_to_locale_string` | 4 | 5.7s |  |
| 380 | `function_to_string` | 4 | 5.7s |  |
| 381 | `function_type` | 6 | 5.7s |  |
| 382 | `function_unbound_this` | 51 | 5.8s |  |
| 383 | `function_value_of` | 4 | 5.7s |  |
| 384 | `get_definition_by_name` | 11 | 5.6s |  |
| 385 | `get_qualified_class_name` | 20 | 5.6s |  |
| 386 | `get_qualified_super_class_name` | 18 | 5.0s |  |
| 387 | `get_slot_edge_cases` | 1 | 23.0s |  |
| 388 | `get_timer` | 2 | 4.8s |  |
| 389 | `getglobalslot` | 1 | 4.8s |  |
| 390 | `getouterscope` | 8 | 4.8s |  |
| 391 | `getter_different_namespace_setter` | 2 | 4.8s |  |
| 392 | `goto_button_nested_framescript` | 28 | 23.1s |  |
| 393 | `goto_in_constructframe` | 12 | 22.9s |  |
| 394 | `goto_in_scene_last_frame` | 2 | 22.8s |  |
| 395 | `goto_methods` | 56 | 4.8s |  |
| 396 | `goto_methods_swfver10` | 8 | 4.8s |  |
| 397 | `goto_nested_construct_sibling` | 18 | 5.1s |  |
| 398 | `goto_nested_framescript` | 9 | 4.9s |  |
| 399 | `goto_on_orphan` | 15 | 4.8s |  |
| 400 | `graphics_bad_direct_commands` | 5 | 6.7s |  |
| 401 | `graphics_bitmap_fill` | 0 | 23.0s |  |
| 402 | `graphics_bitmaps` | 0 | 5.3s |  |
| 403 | `graphics_direct_commands` | 0 | 5.2s |  |
| 404 | `graphics_draw_triangles` | 98 | 23.0s |  |
| 405 | `graphics_gradients` | 0 | 5.1s |  |
| 406 | `graphics_gradients_nulls` | 0 | 5.0s |  |
| 407 | `graphics_path` | 56 | 5.0s |  |
| 408 | `graphics_round_rects` | 0 | 4.8s |  |
| 409 | `graphics_simple_shapes` | 0 | 5.3s |  |
| 410 | `greaterequals` | 512 | 4.8s |  |
| 411 | `greaterthan` | 512 | 4.8s |  |
| 412 | `has_own_property` | 102 | 4.8s |  |
| 413 | `hasownproperty_namespaces` | 2 | 4.8s |  |
| 414 | `hello_world` | 1 | 4.8s |  |
| 415 | `hittest_morph` | 30 | 5.0s |  |
| 416 | `if_eq` | 10 | 4.8s |  |
| 417 | `if_gt` | 1 | 4.8s |  |
| 418 | `if_gte` | 10 | 2.0s |  |
| 419 | `if_lt` | 1 | 0.8s |  |
| 420 | `if_lte` | 10 | 4.8s |  |
| 421 | `if_ne` | 7 | 4.8s |  |
| 422 | `if_stricteq` | 6 | 4.8s |  |
| 423 | `if_strictne` | 11 | 4.8s |  |
| 424 | `in` | 102 | 5.1s |  |
| 425 | `inclocal` | 46 | 4.8s |  |
| 426 | `inclocal_i` | 46 | 4.8s |  |
| 427 | `increment` | 46 | 4.8s |  |
| 428 | `increment_i` | 46 | 4.8s |  |
| 429 | `instanceof` | 58 | 5.0s |  |
| 430 | `instantiation_on_enter_frame` | 7 | 20.7s |  |
| 431 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.7s |  |
| 432 | `int_constr` | 92 | 5.1s |  |
| 433 | `int_edge_cases` | 19 | 5.0s |  |
| 434 | `int_instanceof` | 3 | 5.1s |  |
| 435 | `int_tofixed` | 1215 | 4.7s |  |
| 436 | `int_tostring` | 3375 | 5.1s |  |
| 437 | `interactiveobject_enabled` | 25 | 4.9s |  |
| 438 | `interface_namespaces` | 78 | 5.0s |  |
| 439 | `is_finite` | 46 | 5.0s |  |
| 440 | `is_nan` | 46 | 4.8s |  |
| 441 | `is_prototype_of` | 12 | 4.9s |  |
| 442 | `issue_10221` | 2 | 4.9s |  |
| 443 | `issue_13780` | 12 | 5.0s |  |
| 444 | `issue_14901` | 1 | 4.9s |  |
| 445 | `issue_17675_edittext_paste_maxchars` | 1 | 4.9s |  |
| 446 | `issue_5292` | 5 | 4.9s |  |
| 447 | `issue_8630` | 2 | 21.5s |  |
| 448 | `issue_8630_scriptremove` | 11 | 4.9s |  |
| 449 | `istype` | 24 | 2.5s |  |
| 450 | `istypelate` | 58 | 5.1s |  |
| 451 | `istypelate_coerce` | 198 | 5.7s |  |
| 452 | `json_errors` | 9 | 23.7s |  |
| 453 | `json_parse` | 21 | 5.6s |  |
| 454 | `json_stringify` | 12 | 5.7s |  |
| 455 | `json_stringify_order` | 1 | 5.5s |  |
| 456 | `json_version_gated` | 1 | 5.4s |  |
| 457 | `key_input_80percent` | 1812 | 23.9s |  |
| 458 | `key_input_location` | 126 | 5.6s |  |
| 459 | `key_input_numpad` | 384 | 5.5s |  |
| 460 | `lazyinit` | 17 | 5.5s |  |
| 461 | `lessequals` | 512 | 9.3s |  |
| 462 | `lessthan` | 512 | 9.4s |  |
| 463 | `loaderinfo_properties` | 18 | 23.8s |  |
| 464 | `loaderinfo_root` | 10 | 5.5s |  |
| 465 | `loaderinfo_root_allows` | 2 | 5.5s |  |
| 466 | `lshift` | 1058 | 17.6s |  |
| 467 | `mask_reapply` | 1 | 24.2s |  |
| 468 | `math` | 497 | 5.8s |  |
| 469 | `missing_external_interface` | 10 | 5.5s |  |
| 470 | `modulo` | 1058 | 17.5s |  |
| 471 | `morph_shape` | 2 | 23.9s |  |
| 472 | `mouse_click_events` | 90 | 24.0s |  |
| 473 | `mouse_double_click_events` | 188 | 5.6s |  |
| 474 | `mouse_empty_parent` | 4 | 5.5s |  |
| 475 | `mouse_over_while_dragging` | 3 | 5.6s |  |
| 476 | `mouse_pick_button_mode` | 2 | 5.6s |  |
| 477 | `mouse_sibling` | 8 | 5.5s |  |
| 478 | `movieclip_addframescript` | 3 | 24.0s |  |
| 479 | `movieclip_child_property` | 16 | 5.6s |  |
| 480 | `movieclip_constr` | 21 | 5.5s |  |
| 481 | `movieclip_currentlabels` | 17 | 24.7s |  |
| 482 | `movieclip_currentlabels_dupes1` | 46 | 24.6s |  |
| 483 | `movieclip_currentlabels_dupes2` | 30 | 5.8s |  |
| 484 | `movieclip_currentlabels_dupes3` | 67 | 5.7s |  |
| 485 | `movieclip_currentscene` | 12 | 24.6s |  |
| 486 | `movieclip_dispatchevent` | 430 | 5.9s |  |
| 487 | `movieclip_dispatchevent_cancel` | 102 | 5.9s |  |
| 488 | `movieclip_dispatchevent_handlerorder` | 251 | 5.8s |  |
| 489 | `movieclip_dispatchevent_selfadd` | 80 | 5.7s |  |
| 490 | `movieclip_dispatchevent_target` | 899 | 5.8s |  |
| 491 | `movieclip_displayevents` | 96 | 24.6s |  |
| 492 | `movieclip_displayevents_clickgoto` | 676 | 24.9s |  |
| 493 | `movieclip_displayevents_clickgoto2` | 2001 | 6.3s |  |
| 494 | `movieclip_displayevents_clickplay` | 575 | 6.0s |  |
| 495 | `movieclip_displayevents_clicksymbol` | 562 | 5.9s |  |
| 496 | `movieclip_displayevents_constructframegoto` | 140 | 6.2s |  |
| 497 | `movieclip_displayevents_constructframeplay` | 50 | 6.0s |  |
| 498 | `movieclip_displayevents_constructframesymbol` | 144 | 6.0s |  |
| 499 | `movieclip_displayevents_dblhandler` | 21 | 5.9s |  |
| 500 | `movieclip_displayevents_enterframegoto` | 149 | 6.0s |  |
| 501 | `movieclip_displayevents_enterframeplay` | 48 | 5.9s |  |
| 502 | `movieclip_displayevents_enterframesymbol` | 149 | 24.8s |  |
| 503 | `movieclip_displayevents_exitframegoto` | 106 | 5.9s |  |
| 504 | `movieclip_displayevents_exitframeplay` | 44 | 5.9s |  |
| 505 | `movieclip_displayevents_exitframesymbol` | 135 | 5.9s |  |
| 506 | `movieclip_displayevents_looping` | 63 | 24.7s |  |
| 507 | `movieclip_displayevents_stopped` | 113 | 6.1s |  |
| 508 | `movieclip_displayevents_swap` | 96 | 2.7s |  |
| 509 | `movieclip_displayevents_timeline` | 128 | 25.0s |  |
| 510 | `movieclip_drawrect` | 54 | 5.9s |  |
| 511 | `movieclip_frameconstruct_skipped` | 9 | 5.9s |  |
| 512 | `movieclip_goto_during_frame_script` | 15 | 5.8s |  |
| 513 | `movieclip_goto_overwrite` | 14 | 24.2s |  |
| 514 | `movieclip_goto_scene_last_frame_int` | 1 | 24.4s |  |
| 515 | `movieclip_goto_scene_last_frame_label` | 1 | 5.6s |  |
| 516 | `movieclip_gotoandplay` | 15 | 24.1s |  |
| 517 | `movieclip_gotoandstop` | 13 | 5.7s |  |
| 518 | `movieclip_gotoandstop_children` | 4 | 5.8s |  |
| 519 | `movieclip_gotoandstop_framescripts1` | 4 | 5.8s |  |
| 520 | `movieclip_gotoandstop_framescripts2` | 4 | 2.8s |  |
| 521 | `movieclip_gotoandstop_framescripts_self` | 7 | 25.6s |  |
| 522 | `movieclip_gotoandstop_queueing` | 12 | 25.4s |  |
| 523 | `movieclip_next_frame` | 2 | 26.2s |  |
| 524 | `movieclip_next_scene` | 6 | 25.4s |  |
| 525 | `movieclip_play` | 3 | 5.9s |  |
| 526 | `movieclip_prev_frame` | 3 | 5.8s |  |
| 527 | `movieclip_prev_scene` | 7 | 6.0s |  |
| 528 | `movieclip_properties` | 79 | 25.9s |  |
| 529 | `movieclip_queued_noop_goto_swf10` | 9 | 6.1s |  |
| 530 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 531 | `movieclip_scenes` | 11 | 5.9s |  |
| 532 | `movieclip_soundtransform` | 831 | 27.8s |  |
| 533 | `movieclip_stop` | 1 | 25.2s |  |
| 534 | `movieclip_super_is_symbol` | 20 | 6.5s |  |
| 535 | `movieclip_symbol_constr` | 8 | 6.1s |  |
| 536 | `movieclip_text_mousedown` | 1 | 6.0s |  |
| 537 | `movieclip_willtrigger` | 5 | 6.2s |  |
| 538 | `multiply` | 1058 | 17.7s |  |
| 539 | `namespace_constr` | 253 | 6.4s |  |
| 540 | `namespace_constr_args` | 1 | 5.9s |  |
| 541 | `namespace_enumeration_order` | 7 | 25.5s |  |
| 542 | `nan_scale` | 9 | 5.9s |  |
| 543 | `negate` | 30 | 6.2s |  |
| 544 | `negative_volume_panned` | 0 | 6.2s |  |
| 545 | `nested_iteration` | 11 | 6.1s |  |
| 546 | `net_getClassByAlias` | 3 | 6.1s |  |
| 547 | `newactivation_in_script_init` | 3 | 5.7s |  |
| 548 | `newclass_twice` | 3 | 5.6s |  |
| 549 | `nonconflicting_declarations` | 0 | 5.7s |  |
| 550 | `null_void_types` | 8 | 5.7s |  |
| 551 | `number_autoconv` | 21 | 5.8s |  |
| 552 | `number_autoconv_amf` | 132 | 5.7s |  |
| 553 | `number_autoconv_array_sort_32bit` | 1 | 5.7s |  |
| 554 | `number_constr` | 58 | 5.8s |  |
| 555 | `number_toexponential` | 378 | 5.7s |  |
| 556 | `number_toexponential2` | 35 | 5.7s |  |
| 557 | `number_tofixed` | 378 | 5.6s |  |
| 558 | `number_toprecision` | 350 | 5.7s |  |
| 559 | `obfuscated_class_names` | 3 | 5.6s |  |
| 560 | `object_enumeration` | 10 | 5.7s |  |
| 561 | `object_prototype` | 4 | 5.7s |  |
| 562 | `object_to_locale_string` | 2 | 5.6s |  |
| 563 | `object_to_string` | 2 | 5.6s |  |
| 564 | `object_value_of` | 2 | 2.7s |  |
| 565 | `op_coerce` | 54 | 5.8s |  |
| 566 | `op_coerce_x` | 54 | 5.7s |  |
| 567 | `op_escxattr` | 2 | 5.7s |  |
| 568 | `op_escxelem` | 2 | 5.7s |  |
| 569 | `op_lookupswitch` | 4 | 5.7s |  |
| 570 | `optimize_coerce` | 1 | 5.6s |  |
| 571 | `orphan_movie_complex` | 80 | 6.1s |  |
| 572 | `orphan_movie_reorder` | 111 | 24.5s |  |
| 573 | `package_namespace` | 7 | 5.5s |  |
| 574 | `param_default_value_has_zero_cpool_index` | 1 | 5.6s |  |
| 575 | `parent_early_access_child` | 16 | 24.5s |  |
| 576 | `pixelbender_effect_BlurredFocus` | 0 | 27.5s |  |
| 577 | `pixelbender_effect_glassDisplace` | 0 | 11.4s |  |
| 578 | `pixelbender_effect_smudge` | 0 | 9.3s |  |
| 579 | `pixelbender_effect_tintype` | 0 | 8.6s |  |
| 580 | `pixelbender_effect_twirl` | 0 | 9.6s |  |
| 581 | `pixelbender_images` | 0 | 8.1s |  |
| 582 | `place_multiple` | 17 | 24.8s |  |
| 583 | `place_object_replace` | 9 | 6.0s |  |
| 584 | `place_object_replace_2` | 24 | 6.0s |  |
| 585 | `place_object_same_depth_frame` | 1 | 6.0s |  |
| 586 | `point` | 132 | 6.4s |  |
| 587 | `primitive_edge_cases` | 1 | 5.7s |  |
| 588 | `property_priority` | 22 | 5.6s |  |
| 589 | `property_priority_three_level` | 6 | 24.4s |  |
| 590 | `propertyisenumerable_namespaces` | 6 | 5.4s |  |
| 591 | `prototype_set_null` | 7 | 5.3s |  |
| 592 | `proxy_callproperty` | 24 | 5.3s |  |
| 593 | `proxy_deleteproperty` | 64 | 5.4s |  |
| 594 | `proxy_enumeration` | 34 | 5.3s |  |
| 595 | `proxy_getproperty` | 77 | 5.4s |  |
| 596 | `proxy_hasownproperty` | 8 | 5.3s |  |
| 597 | `proxy_hasproperty` | 32 | 5.4s |  |
| 598 | `proxy_serialize` | 9 | 5.3s |  |
| 599 | `proxy_setproperty` | 42 | 5.3s |  |
| 600 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.3s |  |
| 601 | `qname_constr` | 32 | 5.3s |  |
| 602 | `qname_constr_namespace` | 24 | 5.4s |  |
| 603 | `qname_enumeration` | 9 | 5.4s |  |
| 604 | `qname_indexing` | 23 | 5.4s |  |
| 605 | `qname_tostring` | 25 | 5.4s |  |
| 606 | `qname_valueof` | 29 | 5.4s |  |
| 607 | `regexp_constr` | 148 | 5.7s |  |
| 608 | `regexp_exec` | 19 | 5.4s |  |
| 609 | `regexp_extended` | 47 | 5.4s |  |
| 610 | `regexp_multiargs` | 1 | 5.3s |  |
| 611 | `regexp_test` | 27 | 5.4s |  |
| 612 | `regexp_toString` | 10 | 5.4s |  |
| 613 | `register_script_refresh` | 35 | 24.4s |  |
| 614 | `remove_child_clear_field` | 88 | 24.2s |  |
| 615 | `remove_dobj` | 3 | 5.3s |  |
| 616 | `resolve_order` | 4 | 5.3s |  |
| 617 | `rng` | 1 | 6.4s |  |
| 618 | `rootless` | 42 | 5.4s |  |
| 619 | `rshift` | 1058 | 16.9s |  |
| 620 | `sandbox_type_local_file` | 1 | 5.6s |  |
| 621 | `scene_constr` | 8 | 5.8s |  |
| 622 | `set_local_0` | 31 | 5.7s |  |
| 623 | `set_property_is_enumerable` | 85 | 6.1s |  |
| 624 | `shape_drawrect` | 54 | 5.7s |  |
| 625 | `shared_object_no_root` | 3 | 5.6s |  |
| 626 | `simplebutton_added_to_stage` | 45 | 24.0s |  |
| 627 | `simplebutton_childevents` | 86 | 24.4s |  |
| 628 | `simplebutton_childevents_nested` | 54 | 6.0s |  |
| 629 | `simplebutton_childevents_sprite` | 13 | 5.8s |  |
| 630 | `simplebutton_childprops` | 144 | 5.9s |  |
| 631 | `simplebutton_childshuffle` | 23 | 5.6s |  |
| 632 | `simplebutton_constr` | 36 | 5.9s |  |
| 633 | `simplebutton_constr_childevents` | 48 | 6.0s |  |
| 634 | `simplebutton_constr_params` | 42 | 5.8s |  |
| 635 | `simplebutton_mouseenabled` | 26 | 5.7s |  |
| 636 | `simplebutton_multi_children` | 19 | 5.9s |  |
| 637 | `simplebutton_structure` | 27 | 5.9s |  |
| 638 | `simplebutton_symbolclass` | 68 | 6.1s |  |
| 639 | `slot_disp_id_shared_numbering` | 1 | 24.1s |  |
| 640 | `slots_force_autoassigned` | 1 | 5.7s |  |
| 641 | `sound_embeddedprops` | 26 | 5.8s |  |
| 642 | `sound_play` | 19 | 5.9s |  |
| 643 | `sound_valueof` | 33 | 5.8s |  |
| 644 | `soundchannel_soundtransform` | 835 | 26.5s |  |
| 645 | `soundchannel_soundtransform_exists` | 5 | 24.4s |  |
| 646 | `soundchannel_stop` | 8 | 24.4s |  |
| 647 | `soundmixer_buffertime` | 5 | 5.6s |  |
| 648 | `soundmixer_stopall` | 6 | 24.3s |  |
| 649 | `soundtransform` | 442 | 11.4s |  |
| 650 | `sprite_with_frames` | 0 | 26.5s |  |
| 651 | `stage3d_agal_cross_product` | 0 | 8.3s |  |
| 652 | `stage3d_bitmap` | 0 | 29.7s |  |
| 653 | `stage3d_float1_index` | 0 | 26.8s |  |
| 654 | `stage3d_fractal` | 0 | 27.4s |  |
| 655 | `stage3d_ignore_sampler_override` | 0 | 27.3s |  |
| 656 | `stage3d_program_constants_bytearray_be` | 0 | 28.0s |  |
| 657 | `stage3d_program_constants_bytearray_le` | 0 | 9.4s |  |
| 658 | `stage3d_raytrace` | 0 | 30.9s |  |
| 659 | `stage3d_rotating_cube` | 0 | 9.6s |  |
| 660 | `stage3d_sampler` | 0 | 8.6s |  |
| 661 | `stage3d_sampler_partial_upload` | 0 | 8.7s |  |
| 662 | `stage3d_stencil` | 0 | 29.8s |  |
| 663 | `stage3d_texture` | 0 | 13.6s |  |
| 664 | `stage3d_texture_bytearray` | 0 | 10.0s |  |
| 665 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.5s |  |
| 666 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.4s |  |
| 667 | `stage3d_triangle` | 0 | 8.7s |  |
| 668 | `stage3d_triangle_bytes4` | 0 | 8.7s |  |
| 669 | `stage3d_triangle_float1` | 0 | 8.7s |  |
| 670 | `stage3d_triangle_index_upload` | 0 | 8.7s |  |
| 671 | `stage_access` | 10 | 5.8s |  |
| 672 | `stage_displayobject_properties` | 24 | 5.7s |  |
| 673 | `stage_framerate_nan` | 7 | 6.0s |  |
| 674 | `stage_framerate_negative` | 6 | 5.8s |  |
| 675 | `stage_framerate_zero` | 6 | 5.7s |  |
| 676 | `stage_invalidate` | 38 | 5.9s |  |
| 677 | `stage_mousechildren` | 2 | 5.8s |  |
| 678 | `stage_mouseenabled` | 15 | 5.7s |  |
| 679 | `stage_overriden_setters` | 31 | 5.9s |  |
| 680 | `stage_properties` | 30 | 5.8s |  |
| 681 | `static_var_with_this_in_ctor` | 2 | 5.7s |  |
| 682 | `stored_properties` | 11 | 5.7s |  |
| 683 | `strict_equality` | 34 | 5.7s |  |
| 684 | `string_call` | 13 | 5.7s |  |
| 685 | `string_case` | 23 | 5.7s |  |
| 686 | `string_char_at` | 27 | 5.7s |  |
| 687 | `string_char_code_at` | 28 | 5.6s |  |
| 688 | `string_constr` | 25 | 23.0s |  |
| 689 | `string_indexof_lastindexof` | 87 | 5.3s |  |
| 690 | `string_length` | 16 | 5.0s |  |
| 691 | `string_locale_compare` | 39 | 5.3s |  |
| 692 | `string_match` | 51 | 5.2s |  |
| 693 | `string_relational_compare` | 4 | 23.2s |  |
| 694 | `string_replace` | 51 | 5.2s |  |
| 695 | `string_search` | 41 | 5.2s |  |
| 696 | `string_split` | 29 | 5.1s |  |
| 697 | `string_substr_negative` | 21 | 5.0s |  |
| 698 | `string_substr_weird` | 182 | 4.9s |  |
| 699 | `subtract` | 1058 | 14.2s |  |
| 700 | `super_get_call` | 12 | 5.1s |  |
| 701 | `supercall_two_classobjects` | 2 | 5.0s |  |
| 702 | `swf8` | 1 | 5.0s |  |
| 703 | `swf_10_queued_goto_scripts_construct` | 52 | 23.3s |  |
| 704 | `swf_9_goto_in_enter_frame` | 17 | 5.2s |  |
| 705 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.1s |  |
| 706 | `swf_9_queued_goto_scripts` | 6 | 23.5s |  |
| 707 | `swf_9_queued_goto_scripts_construct` | 28 | 1.0s |  |
| 708 | `swf_9_versioning` | 2 | 5.1s |  |
| 709 | `swf_wrong_frame_count` | 38 | 5.3s |  |
| 710 | `swf_wrong_frame_count_isplaying` | 22 | 5.2s |  |
| 711 | `symbol_class_binary_data` | 8 | 5.1s |  |
| 712 | `symbol_class_conflict` | 4 | 7.3s |  |
| 713 | `symbol_class_root_not_zero` | 1 | 5.1s |  |
| 714 | `symbolclass_invalid_utf8` | 2 | 5.2s |  |
| 715 | `tab_ordering_automatic_advanced` | 184 | 6.3s |  |
| 716 | `tab_ordering_automatic_basic` | 45 | 24.6s |  |
| 717 | `tab_ordering_children` | 116 | 5.9s |  |
| 718 | `tab_ordering_custom_basic` | 34 | 5.8s |  |
| 719 | `text_engine_fontdescription` | 27 | 6.0s |  |
| 720 | `text_run` | 7 | 5.7s |  |
| 721 | `textfield_focusin_event` | 9 | 5.8s |  |
| 722 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 723 | `textfield_unload` | 39 | 24.7s |  |
| 724 | `textformat` | 1134 | 5.8s |  |
| 725 | `textformat_display` | 14 | 5.8s |  |
| 726 | `textformat_font_max_length` | 4 | 5.8s |  |
| 727 | `throw` | 3 | 5.9s |  |
| 728 | `timeline_scripts` | 3 | 6.0s |  |
| 729 | `timer` | 90 | 6.6s |  |
| 730 | `timer_events` | 3 | 5.9s |  |
| 731 | `timer_finished` | 11 | 6.1s |  |
| 732 | `timer_reset` | 8 | 6.0s |  |
| 733 | `timer_setdelay` | 5 | 5.9s |  |
| 734 | `trace` | 12 | 5.9s |  |
| 735 | `truthiness` | 30 | 5.6s |  |
| 736 | `try_catch` | 11 | 5.6s |  |
| 737 | `try_catch_typed` | 12 | 5.6s |  |
| 738 | `typeof` | 30 | 5.6s |  |
| 739 | `uint_constr` | 92 | 5.7s |  |
| 740 | `uint_tofixed` | 1215 | 5.5s |  |
| 741 | `uint_tostring` | 3375 | 6.0s |  |
| 742 | `unchecked_function` | 15 | 5.8s |  |
| 743 | `urlrequest` | 18 | 5.8s |  |
| 744 | `urshift` | 1058 | 18.2s |  |
| 745 | `vector_class` | 36 | 6.2s |  |
| 746 | `vector_class_call` | 11 | 5.8s |  |
| 747 | `vector_coercion` | 66 | 6.5s |  |
| 748 | `vector_concat` | 90 | 6.2s |  |
| 749 | `vector_constr` | 107 | 6.3s |  |
| 750 | `vector_enumeration` | 5 | 5.6s |  |
| 751 | `vector_every` | 92 | 6.5s |  |
| 752 | `vector_filter` | 95 | 6.6s |  |
| 753 | `vector_holes` | 24 | 5.7s |  |
| 754 | `vector_indexof` | 302 | 10.8s |  |
| 755 | `vector_insertat` | 270 | 6.9s |  |
| 756 | `vector_int_access` | 4 | 5.8s |  |
| 757 | `vector_int_delete` | 11 | 2.9s |  |
| 758 | `vector_join` | 58 | 6.2s |  |
| 759 | `vector_lastindexof` | 302 | 5.8s |  |
| 760 | `vector_legacy` | 10 | 5.8s |  |
| 761 | `vector_map` | 85 | 6.6s |  |
| 762 | `vector_object_final` | 1 | 5.7s |  |
| 763 | `vector_object_toString` | 10 | 5.7s |  |
| 764 | `vector_pushpop` | 255 | 7.0s |  |
| 765 | `vector_reborrow_bug` | 10 | 24.1s |  |
| 766 | `vector_removeat` | 172 | 6.7s |  |
| 767 | `vector_reverse` | 232 | 6.6s |  |
| 768 | `vector_shiftunshift` | 252 | 6.8s |  |
| 769 | `vector_slice` | 331 | 7.2s |  |
| 770 | `vector_sort` | 905 | 15.1s |  |
| 771 | `vector_splice` | 693 | 9.6s |  |
| 772 | `vector_splice_fixed_bug_compat` | 4 | 5.6s |  |
| 773 | `vector_tostring` | 79 | 6.1s |  |
| 774 | `verify_abnormal_loop` | 1 | 5.4s |  |
| 775 | `verify_exception_targets_edge_case` | 1 | 5.4s |  |
| 776 | `verify_lookup_switch_edge_case` | 1 | 5.4s |  |
| 777 | `verify_unreachable_exception` | 2 | 5.4s |  |
| 778 | `versioned_isplaying` | 2 | 5.4s |  |
| 779 | `virtual_properties` | 16 | 5.5s |  |
| 780 | `with` | 4 | 5.5s |  |
| 781 | `xml_abstract_equality` | 36 | 5.7s |  |
| 782 | `xml_advanced` | 52 | 5.5s |  |
| 783 | `xml_appendchild` | 10 | 5.5s |  |
| 784 | `xml_as_attribute` | 9 | 5.5s |  |
| 785 | `xml_attribute` | 35 | 5.6s |  |
| 786 | `xml_attribute_name` | 40 | 5.5s |  |
| 787 | `xml_child` | 25 | 5.5s |  |
| 788 | `xml_childindex` | 7 | 5.5s |  |
| 789 | `xml_children` | 43 | 6.0s |  |
| 790 | `xml_class_call` | 9 | 5.4s |  |
| 791 | `xml_contains` | 197 | 5.6s |  |
| 792 | `xml_copy` | 20 | 25.2s |  |
| 793 | `xml_ctor_from_tostring` | 23 | 6.0s |  |
| 794 | `xml_delete` | 114 | 5.7s |  |
| 795 | `xml_descendants` | 83 | 5.7s |  |
| 796 | `xml_elements` | 6 | 5.5s |  |
| 797 | `xml_equals_namespace_check` | 2 | 5.5s |  |
| 798 | `xml_explicit_use_namespace` | 5 | 23.7s |  |
| 799 | `xml_getdescendants_qname` | 21 | 5.6s |  |
| 800 | `xml_has_property_via_in` | 26 | 5.7s |  |
| 801 | `xml_hasownproperty` | 6 | 5.5s |  |
| 802 | `xml_ignore_white` | 6 | 5.5s |  |
| 803 | `xml_length` | 2 | 5.5s |  |
| 804 | `xml_list_as_attribute` | 9 | 5.5s |  |
| 805 | `xml_list_concat` | 20 | 5.5s |  |
| 806 | `xml_list_enumerate` | 4 | 5.5s |  |
| 807 | `xml_methods_settings` | 3 | 5.5s |  |
| 808 | `xml_mismatched_tag` | 37 | 5.6s |  |
| 809 | `xml_namespace` | 39 | 5.5s |  |
| 810 | `xml_namespace_methods` | 245 | 5.6s |  |
| 811 | `xml_namespaced_property` | 7 | 5.5s |  |
| 812 | `xml_no_namespace` | 1 | 5.5s |  |
| 813 | `xml_nodekind` | 3 | 5.5s |  |
| 814 | `xml_normalize` | 35 | 5.6s |  |
| 815 | `xml_notification_bubbling` | 361 | 5.5s |  |
| 816 | `xml_parent` | 8 | 5.5s |  |
| 817 | `xml_set_children` | 17 | 5.6s |  |
| 818 | `xml_set_name` | 34 | 5.7s |  |
| 819 | `xml_settings` | 6 | 2.7s |  |
| 820 | `xml_simple_complex_content` | 47 | 5.6s |  |
| 821 | `xml_text` | 7 | 5.6s |  |
| 822 | `xml_tostring` | 6 | 5.6s |  |
| 823 | `xml_tostring_namespace` | 12 | 5.6s |  |
| 824 | `xml_unescaping` | 23 | 5.7s |  |
| 825 | `xml_weird_ignores` | 54 | 5.7s |  |
| 826 | `xml_wildcard` | 11 | 5.8s |  |
| 827 | `xmldocument` | 254 | 5.8s |  |
| 828 | `xmlnode` | 3540 | 6.0s |  |
| 829 | `zero_frame_clip` | 3 | 6.1s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 5.5s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 5.5s |  |
| 3 | `blend_transform` | 1 | 1 | 6.1s |  |
| 4 | `coerce_property` | 3 | 3 | 6.0s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.9s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 26.0s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.9s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 5.4s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.5s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 5.5s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.7s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 23.0s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 23.0s |  |
| 15 | `int_toexponential` | 76 | 76 | 5.0s |  |
| 16 | `int_toprecision` | 441 | 441 | 4.9s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 5.9s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.6s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 23.8s |  |
| 20 | `soundchannel_position` | 74 | 74 | 25.9s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 5.9s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 5.6s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 23.3s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.7s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.9s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 5.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**72 tests** within reach

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
| 56 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 57 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 58 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 59 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 60 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 61 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 62 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 63 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 64 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 65 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 66 | `date` | 50.0% | 15 | 30 | 15 |  |
| 67 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 68 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 69 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 70 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 71 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 72 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 24.3s |  |
| 2 | `method_without_body` | exit code 1 | 23.9s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.7s |  |
| 4 | `verify_typecheck` | exit code 1 | 5.3s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 35.3s |  |

## All Output Mismatches

**356 tests** with output mismatch, sorted by match rate (best first)

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
| 56 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 57 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 58 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 59 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 60 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 61 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 62 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 63 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 64 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 65 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 66 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 67 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 68 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 69 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 70 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 71 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 72 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 73 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 74 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 75 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 76 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 77 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 78 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 79 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 80 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 81 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 82 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 83 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 84 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 85 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 86 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 87 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 88 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 89 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 90 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 91 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 92 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 93 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 94 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 95 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 96 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 97 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 98 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 99 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 100 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 101 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 102 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 103 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 104 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 105 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 106 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 107 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 108 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 109 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 110 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 111 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 112 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 113 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 114 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 115 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 116 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 117 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 118 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 119 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 120 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 121 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 122 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 123 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 124 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 125 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 126 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 127 | `loader_events` | 8.7% | 8/92 | 20 | 92 |  |
| 128 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 129 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 130 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 131 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 132 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 133 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 134 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 135 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 136 | `loader_loadbytes_events` | 6.7% | 2/30 | 7 | 30 |  |
| 137 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 138 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 139 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 140 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 141 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 142 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 143 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 144 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 145 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 146 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 147 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 148 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 149 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 150 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 151 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 152 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 153 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 154 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 155 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 156 | `external_interface` | 2.9% | 3/105 | 4 | 105 |  |
| 157 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 158 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 159 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 160 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 161 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 162 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 163 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 164 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 165 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 166 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 167 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 168 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 169 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 170 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 171 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 172 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 173 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 174 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 175 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 176 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 177 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 178 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 179 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 180 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 181 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 182 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 183 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 184 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 185 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 186 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 187 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 188 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 189 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 190 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 191 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 192 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 193 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 194 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 195 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 196 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 197 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 198 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 199 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 200 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 201 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 202 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 203 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 204 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 205 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 206 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 207 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 208 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 209 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 210 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 211 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 212 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 213 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 214 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 215 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 216 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 217 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 218 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 219 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 220 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 221 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 222 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 223 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 224 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 225 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 226 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 227 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 228 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 229 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 230 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 231 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 232 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 233 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 234 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 235 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 236 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 237 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 238 | `filefilter_properties` | 0.0% | 0/4 | 0 | 4 |  |
| 239 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 240 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 241 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 242 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 243 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 244 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 245 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 246 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 247 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 248 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 249 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 250 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 251 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 252 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 253 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 254 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 255 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 256 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 257 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 258 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 259 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 260 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 261 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 262 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 263 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 264 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 265 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 266 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 267 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 268 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 269 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 270 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 271 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 272 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 273 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 274 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 275 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 276 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 277 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 278 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 279 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 280 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 281 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 282 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 283 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 284 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 285 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 286 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 287 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 288 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 289 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 290 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 291 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 292 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 293 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 294 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 295 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 296 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 297 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 298 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 299 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 300 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 301 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 302 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 304 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 305 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 307 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 308 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 309 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 310 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 311 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 312 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 313 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 314 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 315 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 316 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 317 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 318 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 319 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 320 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 321 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 322 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 323 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 324 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 325 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 326 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 327 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 328 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 329 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 330 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 331 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 332 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 333 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 334 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 335 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 336 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 337 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 338 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 339 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 340 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 341 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 342 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 343 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 344 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 345 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 346 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 347 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 348 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 349 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 350 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 351 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 352 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 353 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 354 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 355 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 356 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
