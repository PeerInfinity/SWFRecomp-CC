# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-13 17:17 UTC

**Git SHA**: `731f6c319f`

**Run Duration**: 119m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1204 |
| Passing | **825** (68.5%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **849** (70.5%) |
| Failing | 355 |
| Total expected lines | 149868 |
| Matching lines | 102138 (68.2%) |
| Mismatched lines | 47730 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 350 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**825 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 2.2s |  |
| 2 | `agal_compiler` | 13 | 2.3s |  |
| 3 | `air_hidden_lookup` | 2 | 2.2s |  |
| 4 | `all_classes/security/swf11` | 3 | 2.2s |  |
| 5 | `amf_custom_obj` | 26 | 2.2s |  |
| 6 | `amf_dictionary` | 9 | 2.2s |  |
| 7 | `amf_function` | 46 | 2.2s |  |
| 8 | `amf_invalid_date` | 2 | 2.2s |  |
| 9 | `amf_missing_prop` | 6 | 2.2s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 3.5s |  |
| 11 | `amf_setter_error` | 8 | 3.8s |  |
| 12 | `amf_vector` | 40 | 3.8s |  |
| 13 | `amf_xml` | 6 | 3.7s |  |
| 14 | `application_domain` | 4 | 3.7s |  |
| 15 | `array_access` | 18 | 3.7s |  |
| 16 | `array_access_interpreter` | 4 | 3.7s |  |
| 17 | `array_access_no_pubns` | 2 | 3.6s |  |
| 18 | `array_concat` | 41 | 3.8s |  |
| 19 | `array_constr` | 10 | 3.6s |  |
| 20 | `array_delete` | 44 | 3.7s |  |
| 21 | `array_enumeration` | 10 | 3.7s |  |
| 22 | `array_enumeration_elements` | 11 | 3.7s |  |
| 23 | `array_every` | 8 | 3.7s |  |
| 24 | `array_filter` | 6 | 3.6s |  |
| 25 | `array_foreach` | 18 | 3.6s |  |
| 26 | `array_hasownproperty` | 11 | 1.8s |  |
| 27 | `array_holes` | 9 | 3.6s |  |
| 28 | `array_index_max` | 84 | 3.4s |  |
| 29 | `array_indexof` | 25 | 3.7s |  |
| 30 | `array_join` | 26 | 3.7s |  |
| 31 | `array_lastindexof` | 29 | 3.7s |  |
| 32 | `array_length` | 14 | 3.6s |  |
| 33 | `array_literal` | 3 | 3.6s |  |
| 34 | `array_map` | 8 | 3.5s |  |
| 35 | `array_pop` | 52 | 3.7s |  |
| 36 | `array_push` | 24 | 3.7s |  |
| 37 | `array_reborrow_bug` | 6 | 3.6s |  |
| 38 | `array_reverse` | 28 | 3.7s |  |
| 39 | `array_shift` | 51 | 1.9s |  |
| 40 | `array_slice` | 39 | 3.7s |  |
| 41 | `array_some` | 8 | 3.7s |  |
| 42 | `array_sort` | 297 | 3.9s |  |
| 43 | `array_sort_fun_swf12` | 2 | 3.6s |  |
| 44 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 45 | `array_sort_random` | 210 | 3.7s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 3.6s |  |
| 47 | `array_sorton` | 545 | 4.3s |  |
| 48 | `array_sparse_ops` | 41 | 3.8s |  |
| 49 | `array_splice` | 133 | 3.7s |  |
| 50 | `array_splice2` | 428 | 3.7s |  |
| 51 | `array_splice_types` | 48 | 3.6s |  |
| 52 | `array_storage` | 8 | 3.4s |  |
| 53 | `array_tolocalestring` | 9 | 3.5s |  |
| 54 | `array_tostring` | 12 | 4.1s |  |
| 55 | `array_unshift` | 24 | 3.4s |  |
| 56 | `array_valueof` | 9 | 3.3s |  |
| 57 | `array_vector_null_callback` | 10 | 3.4s |  |
| 58 | `astype` | 28 | 3.5s |  |
| 59 | `astypelate` | 24 | 3.6s |  |
| 60 | `astypelate_propagates` | 1 | 3.4s |  |
| 61 | `asymmetric_key_events` | 11 | 3.6s |  |
| 62 | `avm2_catchup_dobj` | 158 | 3.9s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 63.6s |  |
| 64 | `bitand` | 1058 | 5.3s |  |
| 65 | `bitmap_constr` | 17 | 3.6s |  |
| 66 | `bitmap_data` | 1000 | 7.5s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 22.0s |  |
| 68 | `bitmap_properties` | 23 | 3.5s |  |
| 69 | `bitmap_timeline` | 9 | 4.1s |  |
| 70 | `bitmapdata_accuracy` | 1 | 46.9s |  |
| 71 | `bitmapdata_applyfilter_blur` | 0 | 22.4s |  |
| 72 | `bitmapdata_applyfilter_colormatrix` | 0 | 4.0s |  |
| 73 | `bitmapdata_applyfilter_destpoint` | 0 | 22.5s |  |
| 74 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 22.0s |  |
| 75 | `bitmapdata_clone` | 13 | 3.6s |  |
| 76 | `bitmapdata_colortransform` | 0 | 3.8s |  |
| 77 | `bitmapdata_colortransform_oob` | 2 | 4.6s |  |
| 78 | `bitmapdata_constr` | 22 | 3.6s |  |
| 79 | `bitmapdata_constructor_from_timeline` | 1 | 4.0s |  |
| 80 | `bitmapdata_copychannel` | 0 | 24.1s |  |
| 81 | `bitmapdata_copypixels` | 23 | 22.1s |  |
| 82 | `bitmapdata_copypixels_blend_over` | 1 | 3.8s |  |
| 83 | `bitmapdata_copypixelstobytearray` | 39 | 3.5s |  |
| 84 | `bitmapdata_dispose` | 7 | 3.5s |  |
| 85 | `bitmapdata_draw` | 0 | 21.9s |  |
| 86 | `bitmapdata_draw_colortransform` | 0 | 3.6s |  |
| 87 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 22.0s |  |
| 88 | `bitmapdata_draw_filters` | 0 | 21.9s |  |
| 89 | `bitmapdata_draw_masks` | 0 | 3.6s |  |
| 90 | `bitmapdata_draw_rotation` | 0 | 3.5s |  |
| 91 | `bitmapdata_draw_self_via_graphic` | 0 | 3.5s |  |
| 92 | `bitmapdata_draw_stage` | 0 | 22.0s |  |
| 93 | `bitmapdata_drawwithquality` | 0 | 3.7s |  |
| 94 | `bitmapdata_embedded` | 9 | 3.6s |  |
| 95 | `bitmapdata_fillrect` | 0 | 3.5s |  |
| 96 | `bitmapdata_filter_sourcerect` | 0 | 21.8s |  |
| 97 | `bitmapdata_floodfill` | 35 | 3.4s |  |
| 98 | `bitmapdata_getpixels` | 39 | 21.6s |  |
| 99 | `bitmapdata_getvector` | 27 | 1.7s |  |
| 100 | `bitmapdata_histogram` | 59 | 1.7s |  |
| 101 | `bitmapdata_hittest` | 112 | 3.9s |  |
| 102 | `bitmapdata_hittest_threshold` | 18 | 3.5s |  |
| 103 | `bitmapdata_opaque` | 0 | 3.5s |  |
| 104 | `bitmapdata_pixeldissolve` | 1037 | 3.9s |  |
| 105 | `bitmapdata_pixeldissolve_image` | 0 | 3.6s |  |
| 106 | `bitmapdata_rectangle_rounding` | 16 | 3.5s |  |
| 107 | `bitmapdata_setpixels` | 286 | 3.5s |  |
| 108 | `bitmapdata_setvector` | 26 | 3.4s |  |
| 109 | `bitmapdata_sync` | 0 | 3.6s |  |
| 110 | `bitmapdata_threshold` | 176 | 4.0s |  |
| 111 | `bitmapdata_zero_size` | 5 | 3.4s |  |
| 112 | `bitnot` | 46 | 3.5s |  |
| 113 | `bitor` | 1058 | 5.4s |  |
| 114 | `bitxor` | 1058 | 5.4s |  |
| 115 | `blend_multiply_alpha` | 0 | 3.5s |  |
| 116 | `blend_scroll` | 0 | 3.5s |  |
| 117 | `boolean_constr` | 32 | 3.1s |  |
| 118 | `boolean_negation` | 30 | 3.0s |  |
| 119 | `boolean_tostring` | 8 | 3.1s |  |
| 120 | `broadcast_event` | 7 | 3.0s |  |
| 121 | `button_nested_frame` | 48 | 18.8s |  |
| 122 | `bytearray` | 48 | 3.4s |  |
| 123 | `bytearray_compress` | 31 | 3.0s |  |
| 124 | `bytearray_errors` | 24 | 3.1s |  |
| 125 | `bytearray_method_serialization` | 1 | 3.1s |  |
| 126 | `bytearray_readobject_amf0` | 50 | 3.6s |  |
| 127 | `bytearray_readobject_amf3` | 53 | 3.8s |  |
| 128 | `bytearray_readutf8bytes_with_bom` | 16 | 3.1s |  |
| 129 | `bytearray_serialization` | 3 | 3.2s |  |
| 130 | `bytearray_string_null` | 19 | 3.2s |  |
| 131 | `bytearray_tostring` | 15 | 3.0s |  |
| 132 | `bytearray_utf16` | 8 | 3.0s |  |
| 133 | `bytearray_writeobject` | 24 | 2.8s |  |
| 134 | `callee_in_initializer` | 6 | 2.9s |  |
| 135 | `callproplex_class` | 1 | 3.0s |  |
| 136 | `catch_class` | 6 | 3.0s |  |
| 137 | `catch_scope_slot` | 7 | 3.0s |  |
| 138 | `checkfilter` | 4 | 1.7s |  |
| 139 | `class_call` | 32 | 3.1s |  |
| 140 | `class_cast_call` | 14 | 3.0s |  |
| 141 | `class_enumeration` | 4 | 3.4s |  |
| 142 | `class_has_own_property` | 2 | 2.9s |  |
| 143 | `class_init_interpreter_mode` | 1 | 3.0s |  |
| 144 | `class_is` | 32 | 3.1s |  |
| 145 | `class_methods` | 5 | 3.1s |  |
| 146 | `class_object_properties` | 10 | 3.2s |  |
| 147 | `class_singleton` | 18 | 3.6s |  |
| 148 | `class_supercalls_errors` | 35 | 3.4s |  |
| 149 | `class_supercalls_mismatched` | 26 | 4.0s |  |
| 150 | `class_superclass_wrong_order` | 1 | 3.9s |  |
| 151 | `class_to_locale_string` | 2 | 3.9s |  |
| 152 | `class_to_string` | 2 | 3.9s |  |
| 153 | `class_value_of` | 2 | 4.0s |  |
| 154 | `click_block` | 5 | 23.2s |  |
| 155 | `click_invisible` | 3 | 4.0s |  |
| 156 | `closures` | 12 | 4.0s |  |
| 157 | `coerce_property` | 33 | 4.0s |  |
| 158 | `coerce_return_type` | 40 | 4.2s |  |
| 159 | `coerce_return_type_fail` | 2 | 4.0s |  |
| 160 | `coerce_return_void` | 3 | 3.9s |  |
| 161 | `coerce_string` | 86 | 4.1s |  |
| 162 | `coerce_string_precision` | 28 | 3.9s |  |
| 163 | `coerce_to_primitive_side_effects` | 29 | 4.0s |  |
| 164 | `construct_errors_swf10` | 8 | 4.0s |  |
| 165 | `construct_frame_list` | 22 | 24.0s |  |
| 166 | `constructor_call` | 3 | 4.0s |  |
| 167 | `constructors_vs_timeline` | 5 | 23.5s |  |
| 168 | `constructprop_dynamic_primitive` | 7 | 4.1s |  |
| 169 | `control_flow_bool` | 4 | 3.9s |  |
| 170 | `control_flow_stricteq` | 8 | 4.0s |  |
| 171 | `convert_boolean` | 30 | 3.9s |  |
| 172 | `convert_integer` | 90 | 4.0s |  |
| 173 | `convert_number` | 56 | 4.0s |  |
| 174 | `convert_uinteger` | 90 | 4.2s |  |
| 175 | `cryptscore` | 11 | 3.1s |  |
| 176 | `declocal` | 46 | 3.0s |  |
| 177 | `declocal_i` | 46 | 2.9s |  |
| 178 | `decrement` | 46 | 2.9s |  |
| 179 | `decrement_i` | 46 | 1.3s |  |
| 180 | `default_values` | 7 | 2.9s |  |
| 181 | `dictionary_access` | 62 | 3.0s |  |
| 182 | `dictionary_access_no_pubns` | 2 | 2.9s |  |
| 183 | `dictionary_delete` | 101 | 3.1s |  |
| 184 | `dictionary_foreach` | 42 | 3.0s |  |
| 185 | `dictionary_hasownproperty` | 63 | 3.0s |  |
| 186 | `dictionary_in` | 62 | 3.0s |  |
| 187 | `dictionary_iter_modify` | 8 | 2.9s |  |
| 188 | `dictionary_namespaces` | 36 | 3.2s |  |
| 189 | `dictionary_primitive_keys` | 29 | 2.9s |  |
| 190 | `displayobject_alpha` | 277 | 2.9s |  |
| 191 | `displayobject_blendmode` | 0 | 18.4s |  |
| 192 | `displayobject_colortransform_nested` | 0 | 19.8s |  |
| 193 | `displayobject_from_enterframe` | 1 | 18.6s |  |
| 194 | `displayobject_getbounds_shape` | 0 | 18.6s |  |
| 195 | `displayobject_height` | 6052 | 18.6s |  |
| 196 | `displayobject_hittestobject` | 32 | 3.0s |  |
| 197 | `displayobject_invalid_floats` | 60 | 3.0s |  |
| 198 | `displayobject_invalid_props` | 3 | 3.8s |  |
| 199 | `displayobject_mask` | 3 | 3.8s |  |
| 200 | `displayobject_mask_self_referential` | 0 | 3.7s |  |
| 201 | `displayobject_metaData` | 3 | 3.8s |  |
| 202 | `displayobject_name` | 22 | 21.9s |  |
| 203 | `displayobject_name_from_timeline` | 24 | 3.9s |  |
| 204 | `displayobject_parent` | 12 | 3.8s |  |
| 205 | `displayobject_root` | 24 | 3.7s |  |
| 206 | `displayobject_rotation` | 1275 | 3.8s |  |
| 207 | `displayobject_set_matrix_nested` | 0 | 22.5s |  |
| 208 | `displayobject_subclass` | 2 | 3.8s |  |
| 209 | `displayobject_visible` | 23 | 3.7s |  |
| 210 | `displayobject_width` | 4852 | 22.2s |  |
| 211 | `displayobject_x` | 614 | 3.5s |  |
| 212 | `displayobject_y` | 617 | 3.7s |  |
| 213 | `displayobjectcontainer_addchild` | 32 | 3.8s |  |
| 214 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 3.7s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 3.8s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 3.8s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 3.8s |  |
| 218 | `displayobjectcontainer_addchildat` | 42 | 3.7s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.9s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 3.8s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 3.8s |  |
| 222 | `displayobjectcontainer_contains` | 66 | 4.0s |  |
| 223 | `displayobjectcontainer_getchildat` | 4 | 3.8s |  |
| 224 | `displayobjectcontainer_getchildbyname` | 9 | 3.7s |  |
| 225 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 3.7s |  |
| 226 | `displayobjectcontainer_getchildindex` | 28 | 3.8s |  |
| 227 | `displayobjectcontainer_removechild` | 10 | 3.7s |  |
| 228 | `displayobjectcontainer_removechild_errors` | 4 | 3.7s |  |
| 229 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 3.7s |  |
| 230 | `displayobjectcontainer_removechildat` | 18 | 3.7s |  |
| 231 | `displayobjectcontainer_removechildren` | 51 | 3.9s |  |
| 232 | `displayobjectcontainer_setchildindex` | 42 | 3.6s |  |
| 233 | `displayobjectcontainer_stopallmovieclips` | 2 | 3.8s |  |
| 234 | `displayobjectcontainer_swapchildren` | 42 | 3.6s |  |
| 235 | `displayobjectcontainer_swapchildrenat` | 42 | 3.5s |  |
| 236 | `displayobjectcontainer_timelineinstance` | 48 | 22.1s |  |
| 237 | `divide` | 1058 | 5.7s |  |
| 238 | `doabc_is_eager` | 1 | 21.6s |  |
| 239 | `documentclass` | 9 | 3.6s |  |
| 240 | `drag_drop` | 10 | 3.7s |  |
| 241 | `duplicate_defs` | 1 | 3.3s |  |
| 242 | `eager_init` | 1 | 3.5s |  |
| 243 | `edit_text_linkage` | 7 | 3.7s |  |
| 244 | `edittext_align` | 60 | 3.8s |  |
| 245 | `edittext_always_show_selection` | 0 | 22.4s |  |
| 246 | `edittext_antialiastype` | 296 | 3.7s |  |
| 247 | `edittext_at_point_methods_basic` | 16 | 4.7s |  |
| 248 | `edittext_autosize` | 39 | 3.8s |  |
| 249 | `edittext_autosize_align` | 0 | 22.2s |  |
| 250 | `edittext_autosize_height_dynamic` | 60 | 22.3s |  |
| 251 | `edittext_autosize_height_input` | 60 | 3.6s |  |
| 252 | `edittext_autosize_lazy_bounds_events` | 65 | 3.8s |  |
| 253 | `edittext_autosize_lazy_bounds_interactions` | 19 | 3.6s |  |
| 254 | `edittext_autosize_lazy_bounds_props` | 490 | 4.7s |  |
| 255 | `edittext_autosize_lazy_bounds_visual` | 0 | 21.9s |  |
| 256 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 3.7s |  |
| 257 | `edittext_bottom_scroll_v_basic` | 210 | 3.7s |  |
| 258 | `edittext_bounds_scale` | 24 | 21.6s |  |
| 259 | `edittext_bullet` | 30 | 3.5s |  |
| 260 | `edittext_default_format` | 221 | 3.8s |  |
| 261 | `edittext_default_format_empty` | 136 | 3.7s |  |
| 262 | `edittext_empty_text_format` | 7 | 3.5s |  |
| 263 | `edittext_focus_selection` | 5 | 3.5s |  |
| 264 | `edittext_font_size` | 45 | 3.5s |  |
| 265 | `edittext_format_empty_font` | 8 | 3.5s |  |
| 266 | `edittext_get_char_index_at_point` | 4 | 23.0s |  |
| 267 | `edittext_get_line_index_at_point` | 2 | 24.3s |  |
| 268 | `edittext_get_line_index_of_char` | 76 | 5.4s |  |
| 269 | `edittext_getcharboundaries` | 172 | 4.3s |  |
| 270 | `edittext_getcharboundaries_missing_glyphs` | 63 | 4.1s |  |
| 271 | `edittext_getcharboundaries_scroll` | 85 | 4.0s |  |
| 272 | `edittext_getlinemetrics` | 146 | 4.2s |  |
| 273 | `edittext_html` | 3101 | 4.5s |  |
| 274 | `edittext_html_condensewhite` | 487 | 4.1s |  |
| 275 | `edittext_html_entity` | 4 | 4.2s |  |
| 276 | `edittext_html_font_size_swf12` | 267 | 4.1s |  |
| 277 | `edittext_html_font_size_swf13` | 273 | 3.7s |  |
| 278 | `edittext_html_roundtrip` | 17 | 4.0s |  |
| 279 | `edittext_input_control` | 12 | 4.2s |  |
| 280 | `edittext_leading` | 9 | 4.2s |  |
| 281 | `edittext_letter_spacing` | 15 | 4.0s |  |
| 282 | `edittext_line_methods` | 294 | 5.2s |  |
| 283 | `edittext_line_metrics` | 11 | 25.5s |  |
| 284 | `edittext_margins` | 25 | 3.9s |  |
| 285 | `edittext_max_scroll_h_basic` | 475 | 4.2s |  |
| 286 | `edittext_max_scroll_v_basic` | 1000 | 4.2s |  |
| 287 | `edittext_mousedown` | 3 | 4.2s |  |
| 288 | `edittext_mouseenabled` | 26 | 3.9s |  |
| 289 | `edittext_newline_character` | 22 | 4.0s |  |
| 290 | `edittext_newline_stripping` | 64 | 5.8s |  |
| 291 | `edittext_newlines` | 30 | 3.9s |  |
| 292 | `edittext_paragraph_methods` | 257 | 3.9s |  |
| 293 | `edittext_paste_events` | 8 | 4.0s |  |
| 294 | `edittext_paste_maxchars` | 4 | 3.9s |  |
| 295 | `edittext_paste_restrict` | 16 | 3.7s |  |
| 296 | `edittext_restrict` | 191 | 4.0s |  |
| 297 | `edittext_restrict_events` | 22 | 3.9s |  |
| 298 | `edittext_scrollh` | 10 | 3.9s |  |
| 299 | `edittext_selected_text` | 9 | 3.9s |  |
| 300 | `edittext_set_html_same` | 17 | 4.0s |  |
| 301 | `edittext_set_text_vs_html` | 9 | 3.9s |  |
| 302 | `edittext_stylesheet` | 536 | 4.2s |  |
| 303 | `edittext_stylesheet_custom_tag` | 76 | 4.0s |  |
| 304 | `edittext_stylesheet_display` | 272 | 4.0s |  |
| 305 | `edittext_underline` | 40 | 3.9s |  |
| 306 | `edittext_width_height` | 103 | 4.1s |  |
| 307 | `edittext_wordwrap_word` | 150 | 4.2s |  |
| 308 | `edittext_wrap_breaks` | 2375 | 4.5s |  |
| 309 | `empty_bounds` | 1 | 3.8s |  |
| 310 | `equals` | 512 | 4.8s |  |
| 311 | `error_prototype` | 15 | 3.8s |  |
| 312 | `error_stack_trace_debug_swf17` | 0 | 22.4s |  |
| 313 | `error_stack_trace_debug_swf18` | 0 | 3.6s |  |
| 314 | `error_stack_trace_release_swf17` | 0 | 3.6s |  |
| 315 | `error_stack_trace_release_swf18` | 0 | 3.6s |  |
| 316 | `error_tostring` | 29 | 3.9s |  |
| 317 | `es3_inheritance` | 31 | 3.9s |  |
| 318 | `es4_inheritance` | 30 | 3.9s |  |
| 319 | `es4_interfaces` | 30 | 3.9s |  |
| 320 | `es4_method_binding` | 8 | 3.9s |  |
| 321 | `es4_oop_prototypes` | 14 | 4.0s |  |
| 322 | `es4_protected_inheritance` | 6 | 3.9s |  |
| 323 | `event_bubbles` | 2 | 3.9s |  |
| 324 | `event_cancelable` | 2 | 3.8s |  |
| 325 | `event_clone` | 20 | 3.9s |  |
| 326 | `event_clone_error_redispatch` | 3 | 4.0s |  |
| 327 | `event_clone_on_redispatch` | 10 | 4.0s |  |
| 328 | `event_formattostring` | 31 | 4.0s |  |
| 329 | `event_handler_exception` | 4 | 4.0s |  |
| 330 | `event_isdefaultprevented` | 12 | 3.8s |  |
| 331 | `event_target_getter` | 5 | 3.9s |  |
| 332 | `event_target_set` | 9 | 3.8s |  |
| 333 | `event_type` | 1 | 3.8s |  |
| 334 | `event_valueof_tostring` | 18 | 3.9s |  |
| 335 | `eventdispatcher_dispatchevent` | 12 | 3.9s |  |
| 336 | `eventdispatcher_dispatchevent_cancel` | 20 | 3.9s |  |
| 337 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 3.9s |  |
| 338 | `eventdispatcher_dispatchevent_indirect` | 9 | 3.9s |  |
| 339 | `eventdispatcher_dispatchevent_this` | 5 | 3.8s |  |
| 340 | `eventdispatcher_haseventlistener` | 25 | 3.9s |  |
| 341 | `eventdispatcher_interface_invoke` | 1 | 3.8s |  |
| 342 | `eventdispatcher_tostring` | 10 | 3.9s |  |
| 343 | `eventdispatcher_willtrigger` | 25 | 3.8s |  |
| 344 | `falsiness` | 30 | 3.9s |  |
| 345 | `fast_index_access` | 12 | 4.0s |  |
| 346 | `finddef` | 3 | 3.9s |  |
| 347 | `findprop_global_prototype` | 6 | 3.9s |  |
| 348 | `flash_xml` | 29 | 3.9s |  |
| 349 | `flash_xml_cloneNode` | 22 | 4.0s |  |
| 350 | `flash_xml_namespace` | 109 | 3.9s |  |
| 351 | `flash_xml_removeNode` | 60 | 4.1s |  |
| 352 | `focus_events_code` | 161 | 24.1s |  |
| 353 | `focus_events_key_same_object` | 26 | 4.4s |  |
| 354 | `focus_events_mixed_key_mouse` | 100 | 25.1s |  |
| 355 | `focus_events_mouse_same_object` | 40 | 4.0s |  |
| 356 | `focus_remove` | 20 | 25.3s |  |
| 357 | `focus_root_movie` | 4 | 24.4s |  |
| 358 | `focus_stage` | 1 | 4.2s |  |
| 359 | `focusrect` | 18 | 4.9s |  |
| 360 | `font_description_clone` | 14 | 4.3s |  |
| 361 | `font_embedded` | 24 | 4.5s |  |
| 362 | `font_enumeratefonts` | 41 | 4.7s |  |
| 363 | `font_enumeratefonts_filter` | 4 | 5.0s |  |
| 364 | `font_hasglyphs` | 40 | 4.4s |  |
| 365 | `framelabel_constr` | 5 | 4.2s |  |
| 366 | `function_call` | 12 | 4.3s |  |
| 367 | `function_call_arguments` | 46 | 4.3s |  |
| 368 | `function_call_arguments_enumerate` | 5 | 4.1s |  |
| 369 | `function_call_coercion` | 108 | 4.2s |  |
| 370 | `function_call_default` | 6 | 4.1s |  |
| 371 | `function_call_rest` | 22 | 4.2s |  |
| 372 | `function_call_types` | 3 | 4.2s |  |
| 373 | `function_call_via_apply` | 11 | 4.2s |  |
| 374 | `function_call_via_call` | 3 | 4.2s |  |
| 375 | `function_display_anonymous` | 7 | 2.1s |  |
| 376 | `function_length` | 6 | 4.2s |  |
| 377 | `function_object` | 2 | 4.2s |  |
| 378 | `function_proto` | 5 | 4.1s |  |
| 379 | `function_proto_created` | 61 | 4.1s |  |
| 380 | `function_to_locale_string` | 4 | 4.2s |  |
| 381 | `function_to_string` | 4 | 3.7s |  |
| 382 | `function_type` | 6 | 3.7s |  |
| 383 | `function_unbound_this` | 51 | 3.9s |  |
| 384 | `function_value_of` | 4 | 3.7s |  |
| 385 | `get_definition_by_name` | 11 | 3.7s |  |
| 386 | `get_qualified_class_name` | 20 | 3.7s |  |
| 387 | `get_qualified_super_class_name` | 18 | 3.7s |  |
| 388 | `get_slot_edge_cases` | 1 | 3.6s |  |
| 389 | `get_timer` | 2 | 3.7s |  |
| 390 | `getglobalslot` | 1 | 3.6s |  |
| 391 | `getouterscope` | 8 | 3.6s |  |
| 392 | `getter_different_namespace_setter` | 2 | 3.7s |  |
| 393 | `goto_button_nested_framescript` | 28 | 21.9s |  |
| 394 | `goto_in_constructframe` | 12 | 21.7s |  |
| 395 | `goto_in_scene_last_frame` | 2 | 21.4s |  |
| 396 | `goto_methods` | 56 | 3.8s |  |
| 397 | `goto_methods_swfver10` | 8 | 3.7s |  |
| 398 | `goto_nested_construct_sibling` | 18 | 4.1s |  |
| 399 | `goto_nested_framescript` | 9 | 3.8s |  |
| 400 | `goto_on_orphan` | 15 | 3.9s |  |
| 401 | `graphics_bitmap_fill` | 0 | 5.0s |  |
| 402 | `graphics_bitmaps` | 0 | 3.9s |  |
| 403 | `graphics_direct_commands` | 0 | 3.8s |  |
| 404 | `graphics_gradients` | 0 | 3.8s |  |
| 405 | `graphics_gradients_nulls` | 0 | 3.7s |  |
| 406 | `graphics_round_rects` | 0 | 3.7s |  |
| 407 | `graphics_simple_shapes` | 0 | 3.7s |  |
| 408 | `greaterequals` | 512 | 4.6s |  |
| 409 | `greaterthan` | 512 | 3.3s |  |
| 410 | `has_own_property` | 102 | 2.7s |  |
| 411 | `hasownproperty_namespaces` | 2 | 2.8s |  |
| 412 | `hello_world` | 1 | 2.5s |  |
| 413 | `hittest_morph` | 30 | 3.0s |  |
| 414 | `if_eq` | 10 | 2.5s |  |
| 415 | `if_gt` | 1 | 2.5s |  |
| 416 | `if_gte` | 10 | 1.1s |  |
| 417 | `if_lt` | 1 | 0.4s |  |
| 418 | `if_lte` | 10 | 2.3s |  |
| 419 | `if_ne` | 7 | 1.5s |  |
| 420 | `if_stricteq` | 6 | 2.8s |  |
| 421 | `if_strictne` | 11 | 2.5s |  |
| 422 | `in` | 102 | 2.6s |  |
| 423 | `inclocal` | 46 | 2.7s |  |
| 424 | `inclocal_i` | 46 | 2.8s |  |
| 425 | `increment` | 46 | 2.6s |  |
| 426 | `increment_i` | 46 | 2.5s |  |
| 427 | `instanceof` | 58 | 2.6s |  |
| 428 | `instantiation_on_enter_frame` | 7 | 15.6s |  |
| 429 | `instantiation_on_enterframe_gotoandstop` | 8 | 2.4s |  |
| 430 | `int_constr` | 92 | 2.5s |  |
| 431 | `int_edge_cases` | 19 | 2.5s |  |
| 432 | `int_instanceof` | 3 | 2.8s |  |
| 433 | `int_tofixed` | 1215 | 2.4s |  |
| 434 | `int_tostring` | 3375 | 2.6s |  |
| 435 | `interactiveobject_enabled` | 25 | 2.5s |  |
| 436 | `interface_namespaces` | 78 | 2.7s |  |
| 437 | `is_finite` | 46 | 2.5s |  |
| 438 | `is_nan` | 46 | 2.5s |  |
| 439 | `is_prototype_of` | 12 | 2.7s |  |
| 440 | `issue_10221` | 2 | 2.6s |  |
| 441 | `issue_13780` | 12 | 2.5s |  |
| 442 | `issue_14901` | 1 | 2.3s |  |
| 443 | `issue_17675_edittext_paste_maxchars` | 1 | 2.4s |  |
| 444 | `issue_5292` | 5 | 2.4s |  |
| 445 | `issue_8630` | 2 | 2.4s |  |
| 446 | `issue_8630_scriptremove` | 11 | 2.4s |  |
| 447 | `istype` | 24 | 2.4s |  |
| 448 | `istypelate` | 58 | 2.4s |  |
| 449 | `istypelate_coerce` | 198 | 2.5s |  |
| 450 | `json_errors` | 9 | 13.1s |  |
| 451 | `json_parse` | 21 | 2.3s |  |
| 452 | `json_version_gated` | 1 | 2.3s |  |
| 453 | `key_input_80percent` | 1812 | 2.4s |  |
| 454 | `key_input_location` | 126 | 2.4s |  |
| 455 | `key_input_numpad` | 384 | 2.4s |  |
| 456 | `lazyinit` | 17 | 2.4s |  |
| 457 | `lessequals` | 512 | 2.9s |  |
| 458 | `lessthan` | 512 | 2.8s |  |
| 459 | `loaderinfo_properties` | 18 | 22.9s |  |
| 460 | `loaderinfo_root` | 10 | 3.6s |  |
| 461 | `loaderinfo_root_allows` | 2 | 3.6s |  |
| 462 | `lshift` | 1058 | 6.0s |  |
| 463 | `mask_reapply` | 1 | 23.4s |  |
| 464 | `math` | 497 | 3.8s |  |
| 465 | `modulo` | 1058 | 5.9s |  |
| 466 | `mouse_click_events` | 90 | 23.1s |  |
| 467 | `mouse_double_click_events` | 188 | 3.7s |  |
| 468 | `mouse_empty_parent` | 4 | 3.7s |  |
| 469 | `mouse_over_while_dragging` | 3 | 3.7s |  |
| 470 | `mouse_pick_button_mode` | 2 | 3.7s |  |
| 471 | `mouse_sibling` | 8 | 4.0s |  |
| 472 | `movieclip_addframescript` | 3 | 24.0s |  |
| 473 | `movieclip_child_property` | 16 | 4.0s |  |
| 474 | `movieclip_constr` | 21 | 3.9s |  |
| 475 | `movieclip_currentlabels` | 17 | 23.1s |  |
| 476 | `movieclip_currentlabels_dupes1` | 46 | 23.1s |  |
| 477 | `movieclip_currentlabels_dupes2` | 30 | 3.8s |  |
| 478 | `movieclip_currentlabels_dupes3` | 67 | 3.8s |  |
| 479 | `movieclip_currentscene` | 12 | 22.3s |  |
| 480 | `movieclip_dispatchevent` | 430 | 3.9s |  |
| 481 | `movieclip_dispatchevent_cancel` | 102 | 3.9s |  |
| 482 | `movieclip_dispatchevent_handlerorder` | 251 | 3.9s |  |
| 483 | `movieclip_dispatchevent_selfadd` | 80 | 3.8s |  |
| 484 | `movieclip_dispatchevent_target` | 899 | 3.9s |  |
| 485 | `movieclip_displayevents` | 96 | 22.6s |  |
| 486 | `movieclip_displayevents_clickgoto` | 676 | 22.9s |  |
| 487 | `movieclip_displayevents_clickgoto2` | 2001 | 4.2s |  |
| 488 | `movieclip_displayevents_clickplay` | 575 | 4.0s |  |
| 489 | `movieclip_displayevents_clicksymbol` | 562 | 4.0s |  |
| 490 | `movieclip_displayevents_constructframegoto` | 140 | 4.2s |  |
| 491 | `movieclip_displayevents_constructframeplay` | 50 | 4.0s |  |
| 492 | `movieclip_displayevents_constructframesymbol` | 144 | 4.0s |  |
| 493 | `movieclip_displayevents_dblhandler` | 21 | 4.0s |  |
| 494 | `movieclip_displayevents_enterframegoto` | 149 | 4.0s |  |
| 495 | `movieclip_displayevents_enterframeplay` | 48 | 3.9s |  |
| 496 | `movieclip_displayevents_enterframesymbol` | 149 | 22.7s |  |
| 497 | `movieclip_displayevents_exitframegoto` | 106 | 3.9s |  |
| 498 | `movieclip_displayevents_exitframeplay` | 44 | 3.9s |  |
| 499 | `movieclip_displayevents_exitframesymbol` | 135 | 4.0s |  |
| 500 | `movieclip_displayevents_looping` | 63 | 22.9s |  |
| 501 | `movieclip_displayevents_stopped` | 113 | 4.1s |  |
| 502 | `movieclip_displayevents_swap` | 96 | 1.8s |  |
| 503 | `movieclip_displayevents_timeline` | 128 | 23.3s |  |
| 504 | `movieclip_drawrect` | 54 | 3.9s |  |
| 505 | `movieclip_frameconstruct_skipped` | 9 | 3.9s |  |
| 506 | `movieclip_goto_during_frame_script` | 15 | 21.6s |  |
| 507 | `movieclip_goto_overwrite` | 14 | 21.4s |  |
| 508 | `movieclip_goto_scene_last_frame_int` | 1 | 21.9s |  |
| 509 | `movieclip_goto_scene_last_frame_label` | 1 | 3.6s |  |
| 510 | `movieclip_gotoandplay` | 15 | 21.4s |  |
| 511 | `movieclip_gotoandstop` | 13 | 3.4s |  |
| 512 | `movieclip_gotoandstop_children` | 4 | 3.6s |  |
| 513 | `movieclip_gotoandstop_framescripts1` | 4 | 3.7s |  |
| 514 | `movieclip_gotoandstop_framescripts2` | 4 | 1.6s |  |
| 515 | `movieclip_gotoandstop_framescripts_self` | 7 | 21.5s |  |
| 516 | `movieclip_gotoandstop_queueing` | 12 | 3.5s |  |
| 517 | `movieclip_next_frame` | 2 | 3.5s |  |
| 518 | `movieclip_next_scene` | 6 | 21.4s |  |
| 519 | `movieclip_play` | 3 | 3.4s |  |
| 520 | `movieclip_prev_frame` | 3 | 3.2s |  |
| 521 | `movieclip_prev_scene` | 7 | 3.5s |  |
| 522 | `movieclip_properties` | 79 | 21.5s |  |
| 523 | `movieclip_queued_noop_goto_swf10` | 9 | 3.5s |  |
| 524 | `movieclip_queued_noop_goto_swf9` | 7 | 0.4s |  |
| 525 | `movieclip_scenes` | 11 | 3.5s |  |
| 526 | `movieclip_soundtransform` | 831 | 22.6s |  |
| 527 | `movieclip_stop` | 1 | 21.4s |  |
| 528 | `movieclip_super_is_symbol` | 20 | 4.0s |  |
| 529 | `movieclip_symbol_constr` | 8 | 3.6s |  |
| 530 | `movieclip_text_mousedown` | 1 | 3.5s |  |
| 531 | `movieclip_willtrigger` | 5 | 3.5s |  |
| 532 | `multiply` | 1058 | 5.5s |  |
| 533 | `namespace_constr` | 253 | 3.9s |  |
| 534 | `namespace_constr_args` | 1 | 3.4s |  |
| 535 | `namespace_enumeration_order` | 7 | 3.5s |  |
| 536 | `nan_scale` | 9 | 3.5s |  |
| 537 | `negate` | 30 | 3.5s |  |
| 538 | `negative_volume_panned` | 0 | 3.6s |  |
| 539 | `nested_iteration` | 11 | 3.5s |  |
| 540 | `net_getClassByAlias` | 3 | 3.5s |  |
| 541 | `newactivation_in_script_init` | 3 | 4.0s |  |
| 542 | `newclass_twice` | 3 | 4.0s |  |
| 543 | `nonconflicting_declarations` | 0 | 4.1s |  |
| 544 | `null_void_types` | 8 | 4.1s |  |
| 545 | `number_autoconv` | 21 | 4.1s |  |
| 546 | `number_autoconv_amf` | 132 | 4.0s |  |
| 547 | `number_autoconv_array_sort_32bit` | 1 | 4.1s |  |
| 548 | `number_constr` | 58 | 4.1s |  |
| 549 | `number_toexponential` | 378 | 4.2s |  |
| 550 | `number_toexponential2` | 35 | 4.0s |  |
| 551 | `number_tofixed` | 378 | 4.0s |  |
| 552 | `number_toprecision` | 350 | 4.1s |  |
| 553 | `obfuscated_class_names` | 3 | 4.1s |  |
| 554 | `object_enumeration` | 10 | 4.1s |  |
| 555 | `object_prototype` | 4 | 4.2s |  |
| 556 | `object_to_locale_string` | 2 | 4.1s |  |
| 557 | `object_to_string` | 2 | 4.0s |  |
| 558 | `object_value_of` | 2 | 1.9s |  |
| 559 | `op_coerce` | 54 | 4.0s |  |
| 560 | `op_coerce_x` | 54 | 4.1s |  |
| 561 | `op_escxattr` | 2 | 4.1s |  |
| 562 | `op_escxelem` | 2 | 4.1s |  |
| 563 | `op_lookupswitch` | 4 | 4.1s |  |
| 564 | `optimize_coerce` | 1 | 4.0s |  |
| 565 | `orphan_movie_complex` | 80 | 4.4s |  |
| 566 | `orphan_movie_reorder` | 111 | 24.4s |  |
| 567 | `package_namespace` | 7 | 3.7s |  |
| 568 | `param_default_value_has_zero_cpool_index` | 1 | 3.7s |  |
| 569 | `parent_early_access_child` | 16 | 22.3s |  |
| 570 | `parse_float` | 80 | 3.8s |  |
| 571 | `pixelbender_effect_BlurredFocus` | 0 | 24.6s |  |
| 572 | `pixelbender_effect_glassDisplace` | 0 | 8.8s |  |
| 573 | `pixelbender_effect_smudge` | 0 | 6.5s |  |
| 574 | `pixelbender_effect_tintype` | 0 | 5.7s |  |
| 575 | `pixelbender_effect_twirl` | 0 | 6.9s |  |
| 576 | `pixelbender_images` | 0 | 5.2s |  |
| 577 | `place_multiple` | 17 | 4.0s |  |
| 578 | `place_object_replace` | 9 | 4.1s |  |
| 579 | `place_object_replace_2` | 24 | 23.9s |  |
| 580 | `place_object_same_depth_frame` | 1 | 4.0s |  |
| 581 | `primitive_edge_cases` | 1 | 3.9s |  |
| 582 | `property_priority` | 22 | 4.2s |  |
| 583 | `property_priority_three_level` | 6 | 4.0s |  |
| 584 | `propertyisenumerable_namespaces` | 6 | 3.9s |  |
| 585 | `prototype_set_null` | 7 | 3.9s |  |
| 586 | `proxy_callproperty` | 24 | 4.0s |  |
| 587 | `proxy_deleteproperty` | 64 | 3.9s |  |
| 588 | `proxy_enumeration` | 34 | 3.9s |  |
| 589 | `proxy_getproperty` | 77 | 3.9s |  |
| 590 | `proxy_hasownproperty` | 8 | 3.8s |  |
| 591 | `proxy_hasproperty` | 32 | 3.9s |  |
| 592 | `proxy_serialize` | 9 | 3.8s |  |
| 593 | `proxy_setproperty` | 42 | 3.9s |  |
| 594 | `qname_as_lazy_name_attribute_multiname` | 1 | 3.8s |  |
| 595 | `qname_constr` | 32 | 3.9s |  |
| 596 | `qname_constr_namespace` | 24 | 3.8s |  |
| 597 | `qname_enumeration` | 9 | 3.8s |  |
| 598 | `qname_indexing` | 23 | 3.9s |  |
| 599 | `qname_tostring` | 25 | 3.8s |  |
| 600 | `qname_valueof` | 29 | 3.8s |  |
| 601 | `regexp_constr` | 148 | 4.0s |  |
| 602 | `regexp_exec` | 19 | 3.8s |  |
| 603 | `regexp_extended` | 47 | 3.8s |  |
| 604 | `regexp_multiargs` | 1 | 3.7s |  |
| 605 | `regexp_test` | 27 | 3.9s |  |
| 606 | `regexp_toString` | 10 | 4.0s |  |
| 607 | `register_script_refresh` | 35 | 23.4s |  |
| 608 | `remove_child_clear_field` | 88 | 23.8s |  |
| 609 | `remove_dobj` | 3 | 4.0s |  |
| 610 | `resolve_order` | 4 | 4.0s |  |
| 611 | `rng` | 1 | 5.3s |  |
| 612 | `rootless` | 42 | 4.1s |  |
| 613 | `rshift` | 1058 | 6.3s |  |
| 614 | `sandbox_type_local_file` | 1 | 3.9s |  |
| 615 | `scene_constr` | 8 | 3.9s |  |
| 616 | `set_property_is_enumerable` | 85 | 4.1s |  |
| 617 | `shape_drawrect` | 54 | 3.9s |  |
| 618 | `shared_object_no_root` | 3 | 4.0s |  |
| 619 | `simplebutton_added_to_stage` | 45 | 23.6s |  |
| 620 | `simplebutton_childevents` | 86 | 23.8s |  |
| 621 | `simplebutton_childevents_nested` | 54 | 4.2s |  |
| 622 | `simplebutton_childevents_sprite` | 13 | 4.0s |  |
| 623 | `simplebutton_childprops` | 144 | 4.2s |  |
| 624 | `simplebutton_childshuffle` | 23 | 3.9s |  |
| 625 | `simplebutton_constr` | 36 | 4.2s |  |
| 626 | `simplebutton_constr_childevents` | 48 | 4.2s |  |
| 627 | `simplebutton_constr_params` | 42 | 4.0s |  |
| 628 | `simplebutton_mouseenabled` | 26 | 3.9s |  |
| 629 | `simplebutton_multi_children` | 19 | 4.1s |  |
| 630 | `simplebutton_structure` | 27 | 4.1s |  |
| 631 | `simplebutton_symbolclass` | 68 | 4.2s |  |
| 632 | `slot_disp_id_shared_numbering` | 1 | 22.4s |  |
| 633 | `slots_force_autoassigned` | 1 | 3.9s |  |
| 634 | `sound_embeddedprops` | 26 | 4.0s |  |
| 635 | `sound_play` | 19 | 4.1s |  |
| 636 | `sound_valueof` | 33 | 3.9s |  |
| 637 | `soundchannel_soundtransform` | 835 | 24.4s |  |
| 638 | `soundchannel_soundtransform_exists` | 5 | 23.0s |  |
| 639 | `soundchannel_stop` | 8 | 22.9s |  |
| 640 | `soundmixer_buffertime` | 5 | 3.9s |  |
| 641 | `soundmixer_stopall` | 6 | 22.5s |  |
| 642 | `soundtransform` | 442 | 4.8s |  |
| 643 | `sprite_with_frames` | 0 | 23.0s |  |
| 644 | `stage3d_agal_cross_product` | 0 | 5.2s |  |
| 645 | `stage3d_bitmap` | 0 | 26.1s |  |
| 646 | `stage3d_float1_index` | 0 | 24.1s |  |
| 647 | `stage3d_fractal` | 0 | 5.8s |  |
| 648 | `stage3d_ignore_sampler_override` | 0 | 23.4s |  |
| 649 | `stage3d_program_constants_bytearray_be` | 0 | 23.9s |  |
| 650 | `stage3d_program_constants_bytearray_le` | 0 | 5.4s |  |
| 651 | `stage3d_raytrace` | 0 | 22.5s |  |
| 652 | `stage3d_rotating_cube` | 0 | 5.5s |  |
| 653 | `stage3d_sampler` | 0 | 5.1s |  |
| 654 | `stage3d_sampler_partial_upload` | 0 | 5.0s |  |
| 655 | `stage3d_stencil` | 0 | 23.3s |  |
| 656 | `stage3d_texture` | 0 | 9.3s |  |
| 657 | `stage3d_texture_bytearray` | 0 | 6.2s |  |
| 658 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 5.7s |  |
| 659 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 6.9s |  |
| 660 | `stage3d_triangle` | 0 | 5.0s |  |
| 661 | `stage3d_triangle_bytes4` | 0 | 5.1s |  |
| 662 | `stage3d_triangle_float1` | 0 | 5.1s |  |
| 663 | `stage3d_triangle_index_upload` | 0 | 5.0s |  |
| 664 | `stage_access` | 10 | 3.8s |  |
| 665 | `stage_displayobject_properties` | 24 | 3.6s |  |
| 666 | `stage_framerate_nan` | 7 | 3.9s |  |
| 667 | `stage_framerate_negative` | 6 | 3.8s |  |
| 668 | `stage_framerate_zero` | 6 | 3.8s |  |
| 669 | `stage_invalidate` | 38 | 3.9s |  |
| 670 | `stage_mousechildren` | 2 | 3.7s |  |
| 671 | `stage_mouseenabled` | 15 | 3.7s |  |
| 672 | `stage_overriden_setters` | 31 | 3.9s |  |
| 673 | `stage_properties` | 30 | 3.7s |  |
| 674 | `static_var_with_this_in_ctor` | 2 | 3.8s |  |
| 675 | `stored_properties` | 11 | 3.9s |  |
| 676 | `strict_equality` | 34 | 3.9s |  |
| 677 | `string_call` | 13 | 3.9s |  |
| 678 | `string_case` | 23 | 4.0s |  |
| 679 | `string_char_at` | 27 | 3.9s |  |
| 680 | `string_char_code_at` | 28 | 3.8s |  |
| 681 | `string_concat_fromcharcode` | 36 | 3.9s |  |
| 682 | `string_constr` | 25 | 3.8s |  |
| 683 | `string_indexof_lastindexof` | 87 | 4.0s |  |
| 684 | `string_length` | 16 | 3.9s |  |
| 685 | `string_locale_compare` | 39 | 4.0s |  |
| 686 | `string_match` | 51 | 4.0s |  |
| 687 | `string_relational_compare` | 4 | 3.8s |  |
| 688 | `string_replace` | 51 | 4.0s |  |
| 689 | `string_search` | 41 | 3.9s |  |
| 690 | `string_slice_substr_substring` | 169 | 4.1s |  |
| 691 | `string_split` | 29 | 4.0s |  |
| 692 | `string_substr_negative` | 21 | 3.8s |  |
| 693 | `string_substr_weird` | 182 | 3.8s |  |
| 694 | `subtract` | 1058 | 6.1s |  |
| 695 | `super_get_call` | 12 | 3.9s |  |
| 696 | `supercall_two_classobjects` | 2 | 3.9s |  |
| 697 | `swf8` | 1 | 3.6s |  |
| 698 | `swf_10_queued_goto_scripts_construct` | 52 | 23.0s |  |
| 699 | `swf_9_goto_in_enter_frame` | 17 | 4.0s |  |
| 700 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.0s |  |
| 701 | `swf_9_queued_goto_scripts` | 6 | 23.0s |  |
| 702 | `swf_9_queued_goto_scripts_construct` | 28 | 0.6s |  |
| 703 | `swf_9_versioning` | 2 | 3.9s |  |
| 704 | `swf_wrong_frame_count` | 38 | 4.2s |  |
| 705 | `swf_wrong_frame_count_isplaying` | 22 | 3.2s |  |
| 706 | `symbol_class_conflict` | 4 | 18.7s |  |
| 707 | `symbol_class_root_not_zero` | 1 | 2.9s |  |
| 708 | `symbolclass_invalid_utf8` | 2 | 3.0s |  |
| 709 | `tab_ordering_automatic_advanced` | 184 | 3.8s |  |
| 710 | `tab_ordering_automatic_basic` | 45 | 3.0s |  |
| 711 | `tab_ordering_children` | 116 | 3.2s |  |
| 712 | `tab_ordering_custom_basic` | 34 | 3.1s |  |
| 713 | `text_engine_fontdescription` | 27 | 3.1s |  |
| 714 | `text_run` | 7 | 2.9s |  |
| 715 | `textfield_focusin_event` | 9 | 3.0s |  |
| 716 | `textfield_input_dead_keys_windows` | 15 | 3.0s |  |
| 717 | `textfield_unload` | 39 | 3.3s |  |
| 718 | `textformat` | 1134 | 3.0s |  |
| 719 | `textformat_display` | 14 | 3.0s |  |
| 720 | `textformat_font_max_length` | 4 | 2.9s |  |
| 721 | `throw` | 3 | 3.1s |  |
| 722 | `timeline_scripts` | 3 | 3.3s |  |
| 723 | `timer` | 90 | 3.4s |  |
| 724 | `timer_events` | 3 | 3.9s |  |
| 725 | `timer_finished` | 11 | 4.0s |  |
| 726 | `timer_reset` | 8 | 4.0s |  |
| 727 | `timer_setdelay` | 5 | 3.9s |  |
| 728 | `trace` | 12 | 3.8s |  |
| 729 | `truthiness` | 30 | 3.9s |  |
| 730 | `try_catch` | 11 | 3.9s |  |
| 731 | `try_catch_typed` | 12 | 3.9s |  |
| 732 | `typeof` | 30 | 3.9s |  |
| 733 | `uint_constr` | 92 | 4.0s |  |
| 734 | `uint_tofixed` | 1215 | 3.8s |  |
| 735 | `uint_tostring` | 3375 | 4.0s |  |
| 736 | `uncaught_errors_stringified` | 3 | 4.0s |  |
| 737 | `unchecked_function` | 15 | 3.9s |  |
| 738 | `urlrequest` | 18 | 3.9s |  |
| 739 | `urshift` | 1058 | 6.0s |  |
| 740 | `vector_class` | 36 | 4.1s |  |
| 741 | `vector_class_call` | 11 | 4.0s |  |
| 742 | `vector_coercion` | 66 | 4.4s |  |
| 743 | `vector_concat` | 90 | 4.1s |  |
| 744 | `vector_constr` | 107 | 4.0s |  |
| 745 | `vector_enumeration` | 5 | 3.8s |  |
| 746 | `vector_every` | 92 | 4.2s |  |
| 747 | `vector_filter` | 95 | 4.3s |  |
| 748 | `vector_holes` | 24 | 3.8s |  |
| 749 | `vector_indexof` | 302 | 4.8s |  |
| 750 | `vector_insertat` | 270 | 4.3s |  |
| 751 | `vector_int_access` | 4 | 3.8s |  |
| 752 | `vector_int_delete` | 11 | 3.8s |  |
| 753 | `vector_join` | 58 | 4.1s |  |
| 754 | `vector_lastindexof` | 302 | 3.8s |  |
| 755 | `vector_legacy` | 10 | 3.9s |  |
| 756 | `vector_map` | 85 | 4.3s |  |
| 757 | `vector_object_final` | 1 | 3.8s |  |
| 758 | `vector_object_toString` | 10 | 3.8s |  |
| 759 | `vector_pushpop` | 255 | 4.2s |  |
| 760 | `vector_reborrow_bug` | 10 | 3.7s |  |
| 761 | `vector_removeat` | 172 | 4.1s |  |
| 762 | `vector_reverse` | 232 | 4.1s |  |
| 763 | `vector_shiftunshift` | 252 | 3.7s |  |
| 764 | `vector_slice` | 331 | 4.2s |  |
| 765 | `vector_sort` | 905 | 5.7s |  |
| 766 | `vector_splice` | 693 | 4.5s |  |
| 767 | `vector_splice_fixed_bug_compat` | 4 | 3.7s |  |
| 768 | `vector_tostring` | 79 | 4.0s |  |
| 769 | `verify_abnormal_loop` | 1 | 3.7s |  |
| 770 | `verify_exception_targets_edge_case` | 1 | 3.7s |  |
| 771 | `verify_lookup_switch_edge_case` | 1 | 3.6s |  |
| 772 | `verify_unreachable_exception` | 2 | 3.6s |  |
| 773 | `versioned_isplaying` | 2 | 3.6s |  |
| 774 | `virtual_properties` | 16 | 3.7s |  |
| 775 | `with` | 4 | 3.7s |  |
| 776 | `xml_abstract_equality` | 36 | 3.9s |  |
| 777 | `xml_advanced` | 52 | 3.7s |  |
| 778 | `xml_appendchild` | 10 | 3.6s |  |
| 779 | `xml_as_attribute` | 9 | 3.7s |  |
| 780 | `xml_attribute` | 35 | 3.8s |  |
| 781 | `xml_attribute_name` | 40 | 3.7s |  |
| 782 | `xml_basic` | 32 | 3.9s |  |
| 783 | `xml_child` | 25 | 3.8s |  |
| 784 | `xml_childindex` | 7 | 3.7s |  |
| 785 | `xml_children` | 43 | 4.2s |  |
| 786 | `xml_class_call` | 9 | 3.7s |  |
| 787 | `xml_contains` | 197 | 3.8s |  |
| 788 | `xml_copy` | 20 | 3.8s |  |
| 789 | `xml_ctor_from_tostring` | 23 | 4.1s |  |
| 790 | `xml_delete` | 114 | 3.9s |  |
| 791 | `xml_descendants` | 83 | 3.8s |  |
| 792 | `xml_elements` | 6 | 3.7s |  |
| 793 | `xml_equals_namespace_check` | 2 | 3.7s |  |
| 794 | `xml_explicit_use_namespace` | 5 | 3.8s |  |
| 795 | `xml_getdescendants_qname` | 21 | 3.8s |  |
| 796 | `xml_has_property_via_in` | 26 | 3.8s |  |
| 797 | `xml_hasownproperty` | 6 | 3.7s |  |
| 798 | `xml_ignore_white` | 6 | 3.8s |  |
| 799 | `xml_length` | 2 | 3.8s |  |
| 800 | `xml_list_as_attribute` | 9 | 3.6s |  |
| 801 | `xml_list_concat` | 20 | 3.7s |  |
| 802 | `xml_list_enumerate` | 4 | 3.7s |  |
| 803 | `xml_methods_settings` | 3 | 3.8s |  |
| 804 | `xml_mismatched_tag` | 37 | 3.8s |  |
| 805 | `xml_namespace` | 39 | 3.8s |  |
| 806 | `xml_namespace_methods` | 245 | 3.9s |  |
| 807 | `xml_namespaced_property` | 7 | 3.8s |  |
| 808 | `xml_no_namespace` | 1 | 3.7s |  |
| 809 | `xml_nodekind` | 3 | 3.8s |  |
| 810 | `xml_normalize` | 35 | 3.9s |  |
| 811 | `xml_notification_bubbling` | 361 | 3.9s |  |
| 812 | `xml_parent` | 8 | 3.8s |  |
| 813 | `xml_set_children` | 17 | 3.6s |  |
| 814 | `xml_set_name` | 34 | 3.8s |  |
| 815 | `xml_settings` | 6 | 1.9s |  |
| 816 | `xml_simple_complex_content` | 47 | 3.8s |  |
| 817 | `xml_text` | 7 | 3.7s |  |
| 818 | `xml_tostring` | 6 | 3.8s |  |
| 819 | `xml_tostring_namespace` | 12 | 3.7s |  |
| 820 | `xml_unescaping` | 23 | 3.8s |  |
| 821 | `xml_weird_ignores` | 54 | 3.9s |  |
| 822 | `xml_wildcard` | 11 | 3.7s |  |
| 823 | `xmldocument` | 254 | 3.8s |  |
| 824 | `xmlnode` | 3540 | 3.9s |  |
| 825 | `zero_frame_clip` | 3 | 4.0s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 1 | 3.6s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 3.5s |  |
| 3 | `blend_transform` | 1 | 1 | 3.5s |  |
| 4 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 4.0s |  |
| 5 | `dictionary_weak_keys` | 1 | 1 | 18.3s |  |
| 6 | `edittext_getcharboundaries_culling` | 300 | 300 | 4.2s |  |
| 7 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 4.0s |  |
| 8 | `edittext_tab_stops` | 6 | 6 | 4.1s |  |
| 9 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 3.9s |  |
| 10 | `error_1034_debug_string` | 19 | 19 | 3.9s |  |
| 11 | `freestanding_superclass` | 3 | 4 | 4.1s |  |
| 12 | `goto_framescript_queued` | 5 | 5 | 3.8s |  |
| 13 | `int_toexponential` | 76 | 76 | 2.5s |  |
| 14 | `int_toprecision` | 441 | 441 | 2.5s |  |
| 15 | `simplebutton_childevents_script_order` | 4 | 4 | 4.2s |  |
| 16 | `slot_holes_fail` | 1 | 1 | 3.8s |  |
| 17 | `slot_id_exceeds_trait_count` | 1 | 1 | 3.9s |  |
| 18 | `soundchannel_position` | 74 | 74 | 23.6s |  |
| 19 | `soundchannel_soundcomplete` | 10 | 10 | 4.1s |  |
| 20 | `sprite_dropTarget` | 4 | 4 | 3.9s |  |
| 21 | `swf_9_goto_in_construct_frame` | 12 | 12 | 23.1s |  |
| 22 | `uint_toexponential` | 100 | 100 | 4.0s |  |
| 23 | `uint_toprecision` | 433 | 433 | 4.0s |  |
| 24 | `weird_superinterface_properties` | 1 | 1 | 3.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**63 tests** within reach

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
| 24 | `bitmap_subclass` | 85.7% | 6 | 7 | 1 |  |
| 25 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 26 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 27 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 28 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 29 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 30 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 31 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 32 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 33 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 34 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 35 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 36 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 37 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 38 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 39 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 40 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 41 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 42 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 43 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 44 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 45 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 46 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 47 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 48 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 49 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 50 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 51 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 52 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 53 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 54 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 55 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 56 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 57 | `date` | 50.0% | 15 | 30 | 15 |  |
| 58 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 59 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 60 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 61 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 62 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 63 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 3.5s |  |
| 2 | `method_without_body` | exit code 1 | 22.9s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 3.9s |  |
| 4 | `verify_typecheck` | exit code 1 | 3.7s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 33.0s |  |

## All Output Mismatches

**350 tests** with output mismatch, sorted by match rate (best first)

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
| 24 | `bitmap_subclass` | 85.7% | 6/7 | 7 | 7 |  |
| 25 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 26 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 27 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 28 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 29 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 30 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 31 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 32 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 33 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 34 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 35 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 36 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 37 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 38 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 39 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 40 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 41 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 42 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 43 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 44 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 45 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 46 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 47 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 48 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 49 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 50 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 51 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 52 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 53 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 54 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 55 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 57 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 58 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 59 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 60 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 61 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 62 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 63 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 64 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 65 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 66 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 67 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 68 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 69 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 70 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 71 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 72 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 73 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 74 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 75 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 76 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 77 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 78 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 79 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 80 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 81 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 82 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 83 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 84 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 85 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 86 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 87 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 88 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 89 | `bitmap_subclass_properties` | 22.2% | 2/9 | 2 | 9 |  |
| 90 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 91 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 92 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 93 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 94 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 95 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 96 | `focus_events_key_navigation` | 17.0% | 9/53 | 12 | 53 |  |
| 97 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 98 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 99 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 100 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 101 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 102 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 103 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 104 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 105 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 106 | `point` | 12.1% | 16/132 | 16 | 132 |  |
| 107 | `focus_events_key_basic` | 11.6% | 17/147 | 147 | 132 |  |
| 108 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 109 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 110 | `geom_transform` | 10.8% | 8/74 | 9 | 74 |  |
| 111 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 112 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 113 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 114 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 115 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 116 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 117 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 118 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 119 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 120 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 121 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 122 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 123 | `pixelbender_sign` | 5.0% | 3/60 | 16 | 60 |  |
| 124 | `loader_method` | 4.8% | 4/83 | 11 | 83 |  |
| 125 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 126 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 127 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 128 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 129 | `pixelbender_ceil` | 3.9% | 3/77 | 16 | 77 |  |
| 130 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 131 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 132 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 133 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 134 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 135 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 136 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 137 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 138 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 139 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 140 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 141 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 142 | `loader_load` | 2.4% | 3/126 | 11 | 126 |  |
| 143 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 144 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 145 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 146 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 147 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 148 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 149 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 150 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 151 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 152 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 153 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 154 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 155 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 156 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 157 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 158 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 159 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 160 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 161 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 162 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 163 | `all_classes/display/swf9` | 0.2% | 3/1959 | 188 | 1959 |  |
| 164 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 165 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 166 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 167 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 168 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 169 | `all_classes/display/swf10` | 0.0% | 1/2569 | 188 | 2569 |  |
| 170 | `all_classes/display/swf11` | 0.0% | 1/2593 | 188 | 2593 |  |
| 171 | `all_classes/display/swf12` | 0.0% | 1/2593 | 188 | 2593 |  |
| 172 | `all_classes/display/swf13` | 0.0% | 1/2671 | 188 | 2671 |  |
| 173 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 174 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 175 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 176 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 177 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 178 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 179 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 180 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 181 | `all_classes/display/swf30` | 0.0% | 0/2936 | 188 | 2936 |  |
| 182 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 183 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 184 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 185 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 186 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 187 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 188 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 189 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 190 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 191 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 192 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 193 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 194 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 195 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 196 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 197 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 198 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 199 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 200 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 201 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 202 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 203 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 204 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 205 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 206 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 207 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 208 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 209 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 210 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 211 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 212 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 213 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 214 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 215 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 216 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 217 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 218 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 219 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 220 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 221 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 222 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 223 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 224 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 225 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 226 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 227 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 228 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 229 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 230 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 231 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 232 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 233 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 234 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 235 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 236 | `graphics_draw_path` | 0.0% | 0/101 | 0 | 101 |  |
| 237 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 238 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 239 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 240 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 241 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 242 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 243 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 244 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 245 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 246 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 247 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 248 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 249 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 250 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 251 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 252 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 253 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 254 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 255 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 256 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 257 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 258 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 259 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 260 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 261 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 262 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 263 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 264 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 265 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 266 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 267 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 268 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 269 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 270 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 271 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 272 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 273 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 274 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 275 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 276 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 277 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 278 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 279 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 280 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 281 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 282 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 283 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 284 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 285 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 286 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 287 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 288 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 289 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 290 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 291 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 292 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 293 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 294 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 295 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 296 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 297 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 298 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 299 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 300 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 301 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 302 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 304 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 305 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 306 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 307 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 308 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 309 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 310 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 311 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 312 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 313 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 314 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 315 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 316 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 317 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 318 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 319 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 320 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 321 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 322 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 323 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 324 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 325 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 326 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 327 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 328 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 329 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 330 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 331 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 332 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 333 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 334 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 335 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 336 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 337 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 338 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 339 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 340 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 341 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 342 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 343 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 344 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 345 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 346 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 347 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 348 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 349 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 350 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
