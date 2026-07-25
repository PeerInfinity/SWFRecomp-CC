# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-25 00:20 UTC

**Git SHA**: `da35e5d771`

**Run Duration**: 159m 19s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1217 |
| Passing | **835** (68.6%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **861** (70.7%) |
| Failing | 356 |
| Total expected lines | 151097 |
| Matching lines | 103673 (68.6%) |
| Mismatched lines | 47424 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 351 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**835 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 12.3s |  |
| 2 | `agal_compiler` | 13 | 5.9s |  |
| 3 | `air_hidden_lookup` | 2 | 3.9s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.0s |  |
| 5 | `amf_custom_obj` | 26 | 4.1s |  |
| 6 | `amf_dictionary` | 9 | 3.8s |  |
| 7 | `amf_function` | 46 | 4.0s |  |
| 8 | `amf_invalid_date` | 2 | 4.0s |  |
| 9 | `amf_missing_prop` | 6 | 4.0s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 5.7s |  |
| 11 | `amf_setter_error` | 8 | 6.0s |  |
| 12 | `amf_vector` | 40 | 5.9s |  |
| 13 | `amf_xml` | 6 | 5.7s |  |
| 14 | `application_domain` | 4 | 5.8s |  |
| 15 | `array_access` | 18 | 5.8s |  |
| 16 | `array_access_interpreter` | 4 | 5.8s |  |
| 17 | `array_access_no_pubns` | 2 | 5.8s |  |
| 18 | `array_concat` | 41 | 5.8s |  |
| 19 | `array_constr` | 10 | 5.7s |  |
| 20 | `array_delete` | 44 | 5.9s |  |
| 21 | `array_enumeration` | 10 | 5.8s |  |
| 22 | `array_enumeration_elements` | 11 | 5.8s |  |
| 23 | `array_every` | 8 | 5.8s |  |
| 24 | `array_filter` | 6 | 5.8s |  |
| 25 | `array_foreach` | 18 | 5.7s |  |
| 26 | `array_hasownproperty` | 11 | 2.8s |  |
| 27 | `array_holes` | 9 | 5.8s |  |
| 28 | `array_index_max` | 84 | 5.7s |  |
| 29 | `array_indexof` | 25 | 5.8s |  |
| 30 | `array_join` | 26 | 5.9s |  |
| 31 | `array_lastindexof` | 29 | 5.9s |  |
| 32 | `array_length` | 14 | 5.8s |  |
| 33 | `array_literal` | 3 | 5.8s |  |
| 34 | `array_map` | 8 | 5.7s |  |
| 35 | `array_pop` | 52 | 5.8s |  |
| 36 | `array_push` | 24 | 5.8s |  |
| 37 | `array_reborrow_bug` | 6 | 5.8s |  |
| 38 | `array_reverse` | 28 | 5.8s |  |
| 39 | `array_shift` | 51 | 2.9s |  |
| 40 | `array_slice` | 39 | 5.8s |  |
| 41 | `array_some` | 8 | 5.8s |  |
| 42 | `array_sort` | 297 | 6.2s |  |
| 43 | `array_sort_fun_swf12` | 2 | 5.8s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 45 | `array_sort_random` | 210 | 5.8s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 5.7s |  |
| 47 | `array_sorton` | 545 | 6.5s |  |
| 48 | `array_sparse_ops` | 41 | 5.7s |  |
| 49 | `array_splice` | 133 | 5.8s |  |
| 50 | `array_splice2` | 428 | 5.8s |  |
| 51 | `array_splice_types` | 48 | 5.7s |  |
| 52 | `array_storage` | 8 | 5.6s |  |
| 53 | `array_tolocalestring` | 9 | 5.6s |  |
| 54 | `array_tostring` | 12 | 5.6s |  |
| 55 | `array_unshift` | 24 | 5.6s |  |
| 56 | `array_valueof` | 9 | 5.5s |  |
| 57 | `array_vector_null_callback` | 10 | 5.6s |  |
| 58 | `astype` | 28 | 5.7s |  |
| 59 | `astypelate` | 24 | 5.7s |  |
| 60 | `astypelate_propagates` | 1 | 5.5s |  |
| 61 | `asymmetric_key_events` | 11 | 5.8s |  |
| 62 | `avm2_catchup_dobj` | 158 | 6.2s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 80.6s |  |
| 64 | `bitand` | 1058 | 18.0s |  |
| 65 | `bitmap_constr` | 17 | 5.9s |  |
| 66 | `bitmap_data` | 1000 | 14.3s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 25.4s |  |
| 68 | `bitmap_properties` | 23 | 5.8s |  |
| 69 | `bitmap_subclass` | 7 | 7.2s |  |
| 70 | `bitmap_subclass_properties` | 9 | 6.3s |  |
| 71 | `bitmap_timeline` | 9 | 5.8s |  |
| 72 | `bitmapdata_accuracy` | 1 | 44.9s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 25.2s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.5s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 24.9s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.4s |  |
| 77 | `bitmapdata_clone` | 13 | 6.0s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.2s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 5.7s |  |
| 80 | `bitmapdata_constr` | 22 | 5.8s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 5.9s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.8s |  |
| 83 | `bitmapdata_copypixels` | 23 | 26.2s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.8s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.8s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.8s |  |
| 87 | `bitmapdata_draw` | 0 | 25.4s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.4s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.6s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 24.4s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 5.8s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.2s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.1s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 24.4s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 6.0s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.2s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.1s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 24.9s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.7s |  |
| 100 | `bitmapdata_getpixels` | 39 | 24.2s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 103 | `bitmapdata_hittest` | 112 | 6.3s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.7s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.1s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 24.6s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.3s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.6s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.8s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.8s |  |
| 111 | `bitmapdata_sync` | 0 | 5.9s |  |
| 112 | `bitmapdata_threshold` | 176 | 6.5s |  |
| 113 | `bitnot` | 46 | 5.8s |  |
| 114 | `bitor` | 1058 | 16.9s |  |
| 115 | `bitxor` | 1058 | 17.0s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.1s |  |
| 117 | `blend_scroll` | 0 | 6.1s |  |
| 118 | `boolean_constr` | 32 | 3.8s |  |
| 119 | `boolean_negation` | 30 | 4.0s |  |
| 120 | `boolean_tostring` | 8 | 4.0s |  |
| 121 | `broadcast_event` | 7 | 3.8s |  |
| 122 | `button_nested_frame` | 48 | 4.1s |  |
| 123 | `bytearray` | 48 | 4.3s |  |
| 124 | `bytearray_compress` | 31 | 3.8s |  |
| 125 | `bytearray_errors` | 24 | 4.3s |  |
| 126 | `bytearray_method_serialization` | 1 | 4.6s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 3.7s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 3.9s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 4.0s |  |
| 130 | `bytearray_serialization` | 3 | 3.8s |  |
| 131 | `bytearray_string_null` | 19 | 3.9s |  |
| 132 | `bytearray_tostring` | 15 | 3.7s |  |
| 133 | `bytearray_utf16` | 8 | 3.7s |  |
| 134 | `bytearray_writeobject` | 24 | 3.9s |  |
| 135 | `callee_in_initializer` | 6 | 3.8s |  |
| 136 | `callproplex_class` | 1 | 4.0s |  |
| 137 | `catch_class` | 6 | 3.7s |  |
| 138 | `catch_scope_slot` | 7 | 1.9s |  |
| 139 | `checkfilter` | 4 | 1.8s |  |
| 140 | `class_call` | 32 | 17.6s |  |
| 141 | `class_cast_call` | 14 | 4.4s |  |
| 142 | `class_enumeration` | 4 | 4.0s |  |
| 143 | `class_has_own_property` | 2 | 4.0s |  |
| 144 | `class_init_interpreter_mode` | 1 | 3.8s |  |
| 145 | `class_is` | 32 | 3.8s |  |
| 146 | `class_methods` | 5 | 3.7s |  |
| 147 | `class_object_properties` | 10 | 3.8s |  |
| 148 | `class_singleton` | 18 | 3.7s |  |
| 149 | `class_supercalls_errors` | 35 | 3.9s |  |
| 150 | `class_supercalls_mismatched` | 26 | 4.2s |  |
| 151 | `class_superclass_wrong_order` | 1 | 24.1s |  |
| 152 | `class_to_locale_string` | 2 | 5.6s |  |
| 153 | `class_to_string` | 2 | 5.5s |  |
| 154 | `class_value_of` | 2 | 5.6s |  |
| 155 | `click_block` | 5 | 24.3s |  |
| 156 | `click_invisible` | 3 | 5.8s |  |
| 157 | `closures` | 12 | 5.7s |  |
| 158 | `coerce_return_type` | 40 | 5.8s |  |
| 159 | `coerce_return_type_fail` | 2 | 5.6s |  |
| 160 | `coerce_return_void` | 3 | 5.6s |  |
| 161 | `coerce_string` | 86 | 5.8s |  |
| 162 | `coerce_string_precision` | 28 | 5.7s |  |
| 163 | `coerce_to_primitive_side_effects` | 29 | 5.8s |  |
| 164 | `construct_errors_swf10` | 8 | 5.8s |  |
| 165 | `construct_frame_list` | 22 | 5.9s |  |
| 166 | `constructor_call` | 3 | 5.6s |  |
| 167 | `constructors_vs_timeline` | 5 | 24.5s |  |
| 168 | `constructprop_dynamic_primitive` | 7 | 5.7s |  |
| 169 | `control_flow_bool` | 4 | 5.8s |  |
| 170 | `control_flow_stricteq` | 8 | 5.8s |  |
| 171 | `convert_boolean` | 30 | 5.8s |  |
| 172 | `convert_integer` | 90 | 5.8s |  |
| 173 | `convert_number` | 56 | 5.7s |  |
| 174 | `convert_uinteger` | 90 | 5.8s |  |
| 175 | `cryptscore` | 11 | 5.8s |  |
| 176 | `date` | 30 | 6.0s |  |
| 177 | `date_parse` | 36 | 5.5s |  |
| 178 | `declocal` | 46 | 5.5s |  |
| 179 | `declocal_i` | 46 | 5.5s |  |
| 180 | `decrement` | 46 | 5.7s |  |
| 181 | `decrement_i` | 46 | 2.8s |  |
| 182 | `default_values` | 7 | 5.6s |  |
| 183 | `dictionary_access` | 62 | 5.7s |  |
| 184 | `dictionary_access_no_pubns` | 2 | 5.5s |  |
| 185 | `dictionary_delete` | 101 | 6.0s |  |
| 186 | `dictionary_foreach` | 42 | 5.8s |  |
| 187 | `dictionary_hasownproperty` | 63 | 5.8s |  |
| 188 | `dictionary_in` | 62 | 5.8s |  |
| 189 | `dictionary_iter_modify` | 8 | 5.5s |  |
| 190 | `dictionary_namespaces` | 36 | 5.6s |  |
| 191 | `dictionary_primitive_keys` | 29 | 5.5s |  |
| 192 | `displayobject_alpha` | 277 | 5.5s |  |
| 193 | `displayobject_blendmode` | 0 | 5.7s |  |
| 194 | `displayobject_colortransform_nested` | 0 | 24.2s |  |
| 195 | `displayobject_from_enterframe` | 1 | 5.7s |  |
| 196 | `displayobject_getbounds_shape` | 0 | 24.1s |  |
| 197 | `displayobject_height` | 6052 | 24.6s |  |
| 198 | `displayobject_hittestobject` | 32 | 5.8s |  |
| 199 | `displayobject_invalid_floats` | 60 | 6.0s |  |
| 200 | `displayobject_invalid_props` | 3 | 6.0s |  |
| 201 | `displayobject_mask` | 3 | 6.5s |  |
| 202 | `displayobject_mask_self_referential` | 0 | 5.8s |  |
| 203 | `displayobject_metaData` | 3 | 5.5s |  |
| 204 | `displayobject_name` | 22 | 5.8s |  |
| 205 | `displayobject_name_from_timeline` | 24 | 5.7s |  |
| 206 | `displayobject_parent` | 12 | 5.5s |  |
| 207 | `displayobject_root` | 24 | 5.5s |  |
| 208 | `displayobject_rotation` | 1284 | 5.7s |  |
| 209 | `displayobject_set_matrix_nested` | 0 | 24.2s |  |
| 210 | `displayobject_subclass` | 2 | 5.6s |  |
| 211 | `displayobject_visible` | 23 | 5.5s |  |
| 212 | `displayobject_width` | 4852 | 24.0s |  |
| 213 | `displayobject_x` | 614 | 5.5s |  |
| 214 | `displayobject_y` | 617 | 5.6s |  |
| 215 | `displayobjectcontainer_addchild` | 32 | 5.7s |  |
| 216 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.5s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.8s |  |
| 218 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.8s |  |
| 219 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.7s |  |
| 220 | `displayobjectcontainer_addchildat` | 42 | 5.8s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.8s |  |
| 222 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.8s |  |
| 223 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.7s |  |
| 224 | `displayobjectcontainer_contains` | 66 | 24.2s |  |
| 225 | `displayobjectcontainer_getchildat` | 4 | 5.7s |  |
| 226 | `displayobjectcontainer_getchildbyname` | 9 | 5.6s |  |
| 227 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.7s |  |
| 228 | `displayobjectcontainer_getchildindex` | 28 | 5.7s |  |
| 229 | `displayobjectcontainer_removechild` | 10 | 5.5s |  |
| 230 | `displayobjectcontainer_removechild_errors` | 4 | 5.5s |  |
| 231 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.5s |  |
| 232 | `displayobjectcontainer_removechildat` | 18 | 5.5s |  |
| 233 | `displayobjectcontainer_removechildren` | 51 | 5.8s |  |
| 234 | `displayobjectcontainer_setchildindex` | 42 | 5.5s |  |
| 235 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.9s |  |
| 236 | `displayobjectcontainer_swapchildren` | 42 | 5.6s |  |
| 237 | `displayobjectcontainer_swapchildrenat` | 42 | 5.6s |  |
| 238 | `displayobjectcontainer_timelineinstance` | 48 | 24.2s |  |
| 239 | `divide` | 1058 | 18.2s |  |
| 240 | `doabc_is_eager` | 1 | 24.9s |  |
| 241 | `documentclass` | 9 | 5.9s |  |
| 242 | `drag_drop` | 10 | 5.9s |  |
| 243 | `duplicate_defs` | 1 | 5.4s |  |
| 244 | `eager_init` | 1 | 5.6s |  |
| 245 | `edit_text_linkage` | 7 | 5.8s |  |
| 246 | `edittext_align` | 60 | 6.1s |  |
| 247 | `edittext_always_show_selection` | 0 | 25.2s |  |
| 248 | `edittext_antialiastype` | 296 | 5.9s |  |
| 249 | `edittext_at_point_methods_basic` | 16 | 7.0s |  |
| 250 | `edittext_autosize` | 39 | 6.0s |  |
| 251 | `edittext_autosize_align` | 0 | 26.4s |  |
| 252 | `edittext_autosize_height_dynamic` | 60 | 26.3s |  |
| 253 | `edittext_autosize_height_input` | 60 | 6.0s |  |
| 254 | `edittext_autosize_lazy_bounds_events` | 65 | 6.2s |  |
| 255 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.7s |  |
| 256 | `edittext_autosize_lazy_bounds_props` | 490 | 7.0s |  |
| 257 | `edittext_autosize_lazy_bounds_visual` | 0 | 5.9s |  |
| 258 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.8s |  |
| 259 | `edittext_bottom_scroll_v_basic` | 210 | 5.7s |  |
| 260 | `edittext_bounds_scale` | 24 | 24.9s |  |
| 261 | `edittext_bullet` | 30 | 6.0s |  |
| 262 | `edittext_default_format` | 221 | 6.3s |  |
| 263 | `edittext_default_format_empty` | 136 | 6.4s |  |
| 264 | `edittext_empty_text_format` | 7 | 6.0s |  |
| 265 | `edittext_focus_selection` | 5 | 5.8s |  |
| 266 | `edittext_font_size` | 45 | 6.0s |  |
| 267 | `edittext_format_empty_font` | 8 | 6.0s |  |
| 268 | `edittext_get_char_index_at_point` | 4 | 26.2s |  |
| 269 | `edittext_get_line_index_at_point` | 2 | 25.5s |  |
| 270 | `edittext_get_line_index_of_char` | 76 | 6.8s |  |
| 271 | `edittext_getcharboundaries` | 172 | 6.1s |  |
| 272 | `edittext_getcharboundaries_missing_glyphs` | 63 | 34.4s |  |
| 273 | `edittext_getcharboundaries_scroll` | 85 | 5.2s |  |
| 274 | `edittext_getlinemetrics` | 146 | 5.3s |  |
| 275 | `edittext_html` | 3101 | 5.5s |  |
| 276 | `edittext_html_condensewhite` | 487 | 5.1s |  |
| 277 | `edittext_html_entity` | 4 | 5.3s |  |
| 278 | `edittext_html_font_size_swf12` | 267 | 5.1s |  |
| 279 | `edittext_html_font_size_swf13` | 273 | 4.8s |  |
| 280 | `edittext_html_roundtrip` | 17 | 5.1s |  |
| 281 | `edittext_input_control` | 12 | 5.2s |  |
| 282 | `edittext_leading` | 9 | 5.3s |  |
| 283 | `edittext_letter_spacing` | 15 | 5.1s |  |
| 284 | `edittext_line_methods` | 294 | 6.3s |  |
| 285 | `edittext_line_metrics` | 11 | 24.5s |  |
| 286 | `edittext_margins` | 25 | 5.2s |  |
| 287 | `edittext_max_scroll_h_basic` | 475 | 5.3s |  |
| 288 | `edittext_max_scroll_v_basic` | 1000 | 5.2s |  |
| 289 | `edittext_mousedown` | 3 | 5.4s |  |
| 290 | `edittext_mouseenabled` | 26 | 5.1s |  |
| 291 | `edittext_newline_character` | 22 | 5.0s |  |
| 292 | `edittext_newline_stripping` | 64 | 7.6s |  |
| 293 | `edittext_newlines` | 30 | 5.1s |  |
| 294 | `edittext_paragraph_methods` | 257 | 5.1s |  |
| 295 | `edittext_paste_events` | 8 | 5.3s |  |
| 296 | `edittext_paste_maxchars` | 4 | 5.1s |  |
| 297 | `edittext_paste_restrict` | 16 | 5.0s |  |
| 298 | `edittext_restrict` | 191 | 5.1s |  |
| 299 | `edittext_restrict_events` | 22 | 5.0s |  |
| 300 | `edittext_scrollh` | 10 | 5.0s |  |
| 301 | `edittext_selected_text` | 9 | 5.0s |  |
| 302 | `edittext_set_html_same` | 17 | 5.0s |  |
| 303 | `edittext_set_text_vs_html` | 9 | 5.0s |  |
| 304 | `edittext_stylesheet` | 536 | 5.4s |  |
| 305 | `edittext_stylesheet_custom_tag` | 76 | 5.1s |  |
| 306 | `edittext_stylesheet_display` | 272 | 5.2s |  |
| 307 | `edittext_underline` | 40 | 5.2s |  |
| 308 | `edittext_width_height` | 103 | 5.3s |  |
| 309 | `edittext_wordwrap_word` | 150 | 17.4s |  |
| 310 | `edittext_wrap_breaks` | 2375 | 6.3s |  |
| 311 | `empty_bounds` | 1 | 5.5s |  |
| 312 | `equals` | 512 | 9.9s |  |
| 313 | `error_prototype` | 15 | 5.7s |  |
| 314 | `error_stack_trace_debug_swf17` | 0 | 24.7s |  |
| 315 | `error_stack_trace_debug_swf18` | 0 | 5.6s |  |
| 316 | `error_stack_trace_release_swf17` | 0 | 5.5s |  |
| 317 | `error_stack_trace_release_swf18` | 0 | 5.5s |  |
| 318 | `error_tostring` | 29 | 5.7s |  |
| 319 | `es3_inheritance` | 31 | 5.7s |  |
| 320 | `es4_inheritance` | 30 | 5.7s |  |
| 321 | `es4_interfaces` | 30 | 5.7s |  |
| 322 | `es4_method_binding` | 8 | 5.7s |  |
| 323 | `es4_oop_prototypes` | 14 | 5.8s |  |
| 324 | `es4_protected_inheritance` | 6 | 5.7s |  |
| 325 | `event_bubbles` | 2 | 5.7s |  |
| 326 | `event_cancelable` | 2 | 5.5s |  |
| 327 | `event_clone` | 20 | 5.7s |  |
| 328 | `event_clone_error_redispatch` | 3 | 5.8s |  |
| 329 | `event_clone_on_redispatch` | 10 | 5.8s |  |
| 330 | `event_formattostring` | 31 | 5.7s |  |
| 331 | `event_isdefaultprevented` | 12 | 5.7s |  |
| 332 | `event_target_getter` | 5 | 2.8s |  |
| 333 | `event_target_set` | 9 | 5.6s |  |
| 334 | `event_type` | 1 | 5.7s |  |
| 335 | `event_valueof_tostring` | 18 | 16.8s |  |
| 336 | `eventdispatcher_dispatchevent` | 12 | 5.5s |  |
| 337 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.6s |  |
| 338 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.7s |  |
| 339 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.8s |  |
| 340 | `eventdispatcher_dispatchevent_this` | 5 | 5.7s |  |
| 341 | `eventdispatcher_haseventlistener` | 25 | 5.8s |  |
| 342 | `eventdispatcher_interface_invoke` | 1 | 5.7s |  |
| 343 | `eventdispatcher_tostring` | 10 | 5.7s |  |
| 344 | `eventdispatcher_willtrigger` | 25 | 5.5s |  |
| 345 | `falsiness` | 30 | 5.6s |  |
| 346 | `fast_index_access` | 12 | 5.7s |  |
| 347 | `finddef` | 3 | 5.6s |  |
| 348 | `findprop_global_prototype` | 6 | 5.8s |  |
| 349 | `flash_xml` | 29 | 5.7s |  |
| 350 | `flash_xml_cloneNode` | 22 | 5.7s |  |
| 351 | `flash_xml_namespace` | 109 | 5.6s |  |
| 352 | `flash_xml_removeNode` | 60 | 5.6s |  |
| 353 | `focus_events_code` | 161 | 24.8s |  |
| 354 | `focus_events_key_same_object` | 26 | 5.6s |  |
| 355 | `focus_events_mixed_key_mouse` | 100 | 24.2s |  |
| 356 | `focus_events_mouse_same_object` | 40 | 5.6s |  |
| 357 | `focus_remove` | 20 | 23.8s |  |
| 358 | `focus_root_movie` | 4 | 24.2s |  |
| 359 | `focus_stage` | 1 | 5.6s |  |
| 360 | `focusrect` | 18 | 6.4s |  |
| 361 | `font_description_clone` | 14 | 5.7s |  |
| 362 | `font_embedded` | 24 | 6.0s |  |
| 363 | `font_enumeratefonts` | 41 | 6.3s |  |
| 364 | `font_enumeratefonts_filter` | 4 | 24.9s |  |
| 365 | `font_hasglyphs` | 40 | 6.1s |  |
| 366 | `framelabel_constr` | 5 | 5.7s |  |
| 367 | `function_call` | 12 | 5.8s |  |
| 368 | `function_call_arguments` | 46 | 5.8s |  |
| 369 | `function_call_arguments_enumerate` | 5 | 5.6s |  |
| 370 | `function_call_coercion` | 108 | 6.0s |  |
| 371 | `function_call_default` | 6 | 5.6s |  |
| 372 | `function_call_rest` | 22 | 5.7s |  |
| 373 | `function_call_types` | 3 | 5.7s |  |
| 374 | `function_call_via_apply` | 11 | 5.7s |  |
| 375 | `function_call_via_call` | 3 | 5.7s |  |
| 376 | `function_display_anonymous` | 7 | 2.8s |  |
| 377 | `function_length` | 6 | 5.7s |  |
| 378 | `function_object` | 2 | 5.7s |  |
| 379 | `function_proto` | 5 | 5.7s |  |
| 380 | `function_proto_created` | 61 | 5.8s |  |
| 381 | `function_to_locale_string` | 4 | 5.7s |  |
| 382 | `function_to_string` | 4 | 5.6s |  |
| 383 | `function_type` | 6 | 5.7s |  |
| 384 | `function_unbound_this` | 51 | 5.8s |  |
| 385 | `function_value_of` | 4 | 5.7s |  |
| 386 | `get_definition_by_name` | 11 | 5.8s |  |
| 387 | `get_qualified_class_name` | 20 | 5.8s |  |
| 388 | `get_qualified_super_class_name` | 18 | 16.9s |  |
| 389 | `get_slot_edge_cases` | 1 | 23.5s |  |
| 390 | `get_timer` | 2 | 5.4s |  |
| 391 | `getglobalslot` | 1 | 5.3s |  |
| 392 | `getouterscope` | 8 | 5.3s |  |
| 393 | `getter_different_namespace_setter` | 2 | 5.3s |  |
| 394 | `goto_button_nested_framescript` | 28 | 5.8s |  |
| 395 | `goto_in_constructframe` | 12 | 5.6s |  |
| 396 | `goto_in_scene_last_frame` | 2 | 23.7s |  |
| 397 | `goto_methods` | 56 | 5.6s |  |
| 398 | `goto_methods_swfver10` | 8 | 5.4s |  |
| 399 | `goto_nested_construct_sibling` | 18 | 5.9s |  |
| 400 | `goto_nested_framescript` | 9 | 5.5s |  |
| 401 | `goto_on_orphan` | 15 | 5.6s |  |
| 402 | `graphics_bad_direct_commands` | 5 | 6.2s |  |
| 403 | `graphics_bitmap_fill` | 0 | 7.3s |  |
| 404 | `graphics_bitmaps` | 0 | 6.2s |  |
| 405 | `graphics_direct_commands` | 0 | 6.2s |  |
| 406 | `graphics_draw_triangles` | 98 | 24.6s |  |
| 407 | `graphics_gradients` | 0 | 5.9s |  |
| 408 | `graphics_gradients_nulls` | 0 | 5.7s |  |
| 409 | `graphics_path` | 56 | 5.5s |  |
| 410 | `graphics_round_rects` | 0 | 5.4s |  |
| 411 | `graphics_simple_shapes` | 0 | 5.8s |  |
| 412 | `greaterequals` | 512 | 8.9s |  |
| 413 | `greaterthan` | 512 | 8.9s |  |
| 414 | `has_own_property` | 102 | 5.9s |  |
| 415 | `hasownproperty_namespaces` | 2 | 5.4s |  |
| 416 | `hello_world` | 1 | 5.4s |  |
| 417 | `hittest_morph` | 30 | 5.5s |  |
| 418 | `if_eq` | 10 | 5.5s |  |
| 419 | `if_gt` | 1 | 5.5s |  |
| 420 | `if_gte` | 10 | 2.6s |  |
| 421 | `if_lt` | 1 | 16.0s |  |
| 422 | `if_lte` | 10 | 5.2s |  |
| 423 | `if_ne` | 7 | 2.5s |  |
| 424 | `if_stricteq` | 6 | 5.3s |  |
| 425 | `if_strictne` | 11 | 5.2s |  |
| 426 | `in` | 102 | 5.6s |  |
| 427 | `inclocal` | 46 | 5.3s |  |
| 428 | `inclocal_i` | 46 | 5.2s |  |
| 429 | `increment` | 46 | 5.2s |  |
| 430 | `increment_i` | 46 | 5.2s |  |
| 431 | `instanceof` | 58 | 5.5s |  |
| 432 | `instantiation_on_enter_frame` | 7 | 23.7s |  |
| 433 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.2s |  |
| 434 | `int_constr` | 92 | 5.1s |  |
| 435 | `int_edge_cases` | 19 | 5.2s |  |
| 436 | `int_instanceof` | 3 | 5.1s |  |
| 437 | `int_tofixed` | 1215 | 5.0s |  |
| 438 | `int_tostring` | 3375 | 5.1s |  |
| 439 | `interactiveobject_enabled` | 25 | 5.1s |  |
| 440 | `interface_namespaces` | 78 | 5.4s |  |
| 441 | `is_finite` | 46 | 5.2s |  |
| 442 | `is_nan` | 46 | 5.1s |  |
| 443 | `is_prototype_of` | 12 | 5.1s |  |
| 444 | `issue_10221` | 2 | 5.1s |  |
| 445 | `issue_13780` | 12 | 5.1s |  |
| 446 | `issue_14901` | 1 | 5.1s |  |
| 447 | `issue_17675_edittext_paste_maxchars` | 1 | 5.2s |  |
| 448 | `issue_5292` | 5 | 5.2s |  |
| 449 | `issue_8630` | 2 | 23.6s |  |
| 450 | `issue_8630_scriptremove` | 11 | 5.2s |  |
| 451 | `istype` | 24 | 2.5s |  |
| 452 | `istypelate` | 58 | 5.5s |  |
| 453 | `istypelate_coerce` | 198 | 6.1s |  |
| 454 | `json_errors` | 9 | 24.2s |  |
| 455 | `json_parse` | 21 | 5.7s |  |
| 456 | `json_stringify` | 12 | 5.9s |  |
| 457 | `json_stringify_order` | 1 | 5.7s |  |
| 458 | `json_version_gated` | 1 | 5.7s |  |
| 459 | `key_input_80percent` | 1812 | 5.9s |  |
| 460 | `key_input_location` | 126 | 5.8s |  |
| 461 | `key_input_numpad` | 384 | 5.8s |  |
| 462 | `lazyinit` | 17 | 5.8s |  |
| 463 | `lessequals` | 512 | 9.4s |  |
| 464 | `lessthan` | 512 | 9.3s |  |
| 465 | `loaderinfo_properties` | 18 | 5.5s |  |
| 466 | `loaderinfo_root` | 10 | 5.5s |  |
| 467 | `loaderinfo_root_allows` | 2 | 5.5s |  |
| 468 | `lshift` | 1058 | 17.7s |  |
| 469 | `mask_reapply` | 1 | 5.6s |  |
| 470 | `math` | 497 | 5.7s |  |
| 471 | `missing_external_interface` | 10 | 5.5s |  |
| 472 | `modulo` | 1058 | 17.5s |  |
| 473 | `morph_shape` | 2 | 23.7s |  |
| 474 | `mouse_click_events` | 90 | 23.9s |  |
| 475 | `mouse_double_click_events` | 188 | 5.6s |  |
| 476 | `mouse_empty_parent` | 4 | 5.5s |  |
| 477 | `mouse_over_while_dragging` | 3 | 5.7s |  |
| 478 | `mouse_pick_button_mode` | 2 | 5.6s |  |
| 479 | `mouse_sibling` | 8 | 5.6s |  |
| 480 | `movieclip_addframescript` | 3 | 23.9s |  |
| 481 | `movieclip_child_property` | 16 | 5.6s |  |
| 482 | `movieclip_constr` | 21 | 5.5s |  |
| 483 | `movieclip_currentlabels` | 17 | 35.5s |  |
| 484 | `movieclip_currentlabels_dupes1` | 46 | 24.6s |  |
| 485 | `movieclip_currentlabels_dupes2` | 30 | 5.7s |  |
| 486 | `movieclip_currentlabels_dupes3` | 67 | 5.8s |  |
| 487 | `movieclip_currentscene` | 12 | 5.9s |  |
| 488 | `movieclip_dispatchevent` | 430 | 6.0s |  |
| 489 | `movieclip_dispatchevent_cancel` | 102 | 5.9s |  |
| 490 | `movieclip_dispatchevent_handlerorder` | 251 | 5.8s |  |
| 491 | `movieclip_dispatchevent_selfadd` | 80 | 5.8s |  |
| 492 | `movieclip_dispatchevent_target` | 899 | 5.9s |  |
| 493 | `movieclip_displayevents` | 96 | 24.6s |  |
| 494 | `movieclip_displayevents_clickgoto` | 676 | 6.2s |  |
| 495 | `movieclip_displayevents_clickgoto2` | 2001 | 6.3s |  |
| 496 | `movieclip_displayevents_clickplay` | 575 | 5.9s |  |
| 497 | `movieclip_displayevents_clicksymbol` | 562 | 6.0s |  |
| 498 | `movieclip_displayevents_constructframegoto` | 140 | 6.2s |  |
| 499 | `movieclip_displayevents_constructframeplay` | 50 | 6.1s |  |
| 500 | `movieclip_displayevents_constructframesymbol` | 144 | 6.0s |  |
| 501 | `movieclip_displayevents_dblhandler` | 21 | 6.0s |  |
| 502 | `movieclip_displayevents_enterframegoto` | 149 | 6.0s |  |
| 503 | `movieclip_displayevents_enterframeplay` | 48 | 5.8s |  |
| 504 | `movieclip_displayevents_enterframesymbol` | 149 | 24.3s |  |
| 505 | `movieclip_displayevents_exitframegoto` | 106 | 5.8s |  |
| 506 | `movieclip_displayevents_exitframeplay` | 44 | 5.8s |  |
| 507 | `movieclip_displayevents_exitframesymbol` | 135 | 5.9s |  |
| 508 | `movieclip_displayevents_looping` | 63 | 24.8s |  |
| 509 | `movieclip_displayevents_stopped` | 113 | 6.3s |  |
| 510 | `movieclip_displayevents_swap` | 96 | 2.8s |  |
| 511 | `movieclip_displayevents_timeline` | 128 | 25.0s |  |
| 512 | `movieclip_drawrect` | 54 | 5.7s |  |
| 513 | `movieclip_frameconstruct_skipped` | 9 | 5.9s |  |
| 514 | `movieclip_goto_during_frame_script` | 15 | 5.9s |  |
| 515 | `movieclip_goto_overwrite` | 14 | 24.2s |  |
| 516 | `movieclip_goto_scene_last_frame_int` | 1 | 24.1s |  |
| 517 | `movieclip_goto_scene_last_frame_label` | 1 | 5.6s |  |
| 518 | `movieclip_gotoandplay` | 15 | 23.8s |  |
| 519 | `movieclip_gotoandstop` | 13 | 5.7s |  |
| 520 | `movieclip_gotoandstop_children` | 4 | 5.8s |  |
| 521 | `movieclip_gotoandstop_framescripts1` | 4 | 5.7s |  |
| 522 | `movieclip_gotoandstop_framescripts2` | 4 | 2.8s |  |
| 523 | `movieclip_gotoandstop_framescripts_self` | 7 | 14.0s |  |
| 524 | `movieclip_gotoandstop_queueing` | 12 | 20.1s |  |
| 525 | `movieclip_next_frame` | 2 | 4.5s |  |
| 526 | `movieclip_next_scene` | 6 | 19.9s |  |
| 527 | `movieclip_play` | 3 | 4.4s |  |
| 528 | `movieclip_prev_frame` | 3 | 4.3s |  |
| 529 | `movieclip_prev_scene` | 7 | 4.4s |  |
| 530 | `movieclip_properties` | 79 | 4.6s |  |
| 531 | `movieclip_queued_noop_goto_swf10` | 9 | 4.4s |  |
| 532 | `movieclip_queued_noop_goto_swf9` | 7 | 0.8s |  |
| 533 | `movieclip_scenes` | 11 | 4.4s |  |
| 534 | `movieclip_soundtransform` | 831 | 21.7s |  |
| 535 | `movieclip_stop` | 1 | 4.3s |  |
| 536 | `movieclip_super_is_symbol` | 20 | 4.7s |  |
| 537 | `movieclip_symbol_constr` | 8 | 4.5s |  |
| 538 | `movieclip_text_mousedown` | 1 | 4.5s |  |
| 539 | `movieclip_willtrigger` | 5 | 4.6s |  |
| 540 | `multiply` | 1058 | 12.5s |  |
| 541 | `namespace_constr` | 253 | 4.7s |  |
| 542 | `namespace_constr_args` | 1 | 4.3s |  |
| 543 | `namespace_enumeration_order` | 7 | 4.3s |  |
| 544 | `nan_scale` | 9 | 4.4s |  |
| 545 | `negate` | 30 | 4.4s |  |
| 546 | `negative_volume_panned` | 0 | 4.6s |  |
| 547 | `nested_iteration` | 11 | 4.4s |  |
| 548 | `net_getClassByAlias` | 3 | 4.4s |  |
| 549 | `newactivation_in_script_init` | 3 | 5.8s |  |
| 550 | `newclass_twice` | 3 | 5.6s |  |
| 551 | `nonconflicting_declarations` | 0 | 5.7s |  |
| 552 | `null_void_types` | 8 | 5.6s |  |
| 553 | `number_autoconv` | 21 | 5.7s |  |
| 554 | `number_autoconv_amf` | 132 | 5.7s |  |
| 555 | `number_autoconv_array_sort_32bit` | 1 | 5.6s |  |
| 556 | `number_constr` | 58 | 5.8s |  |
| 557 | `number_toexponential` | 378 | 5.7s |  |
| 558 | `number_toexponential2` | 35 | 5.6s |  |
| 559 | `number_tofixed` | 378 | 5.5s |  |
| 560 | `number_toprecision` | 350 | 5.7s |  |
| 561 | `obfuscated_class_names` | 3 | 5.6s |  |
| 562 | `object_enumeration` | 10 | 5.6s |  |
| 563 | `object_prototype` | 4 | 5.7s |  |
| 564 | `object_to_locale_string` | 2 | 5.5s |  |
| 565 | `object_to_string` | 2 | 5.5s |  |
| 566 | `object_value_of` | 2 | 2.6s |  |
| 567 | `op_coerce` | 54 | 5.7s |  |
| 568 | `op_coerce_x` | 54 | 5.7s |  |
| 569 | `op_escxattr` | 2 | 5.6s |  |
| 570 | `op_escxelem` | 2 | 5.6s |  |
| 571 | `op_lookupswitch` | 4 | 5.7s |  |
| 572 | `optimize_coerce` | 1 | 5.6s |  |
| 573 | `orphan_movie_complex` | 80 | 6.1s |  |
| 574 | `orphan_movie_reorder` | 111 | 25.5s |  |
| 575 | `package_namespace` | 7 | 5.6s |  |
| 576 | `param_default_value_has_zero_cpool_index` | 1 | 5.6s |  |
| 577 | `parent_early_access_child` | 16 | 6.0s |  |
| 578 | `parse_float` | 81 | 6.0s |  |
| 579 | `pixelbender_effect_BlurredFocus` | 0 | 29.2s |  |
| 580 | `pixelbender_effect_glassDisplace` | 0 | 11.8s |  |
| 581 | `pixelbender_effect_smudge` | 0 | 9.5s |  |
| 582 | `pixelbender_effect_tintype` | 0 | 8.7s |  |
| 583 | `pixelbender_effect_twirl` | 0 | 9.8s |  |
| 584 | `pixelbender_images` | 0 | 8.2s |  |
| 585 | `place_multiple` | 17 | 24.9s |  |
| 586 | `place_object_replace` | 9 | 6.0s |  |
| 587 | `place_object_replace_2` | 24 | 6.0s |  |
| 588 | `place_object_same_depth_frame` | 1 | 5.8s |  |
| 589 | `point` | 132 | 6.4s |  |
| 590 | `primitive_edge_cases` | 1 | 5.7s |  |
| 591 | `property_priority` | 22 | 6.0s |  |
| 592 | `property_priority_three_level` | 6 | 24.4s |  |
| 593 | `propertyisenumerable_namespaces` | 6 | 5.7s |  |
| 594 | `prototype_set_null` | 7 | 5.6s |  |
| 595 | `proxy_callproperty` | 24 | 5.7s |  |
| 596 | `proxy_deleteproperty` | 64 | 5.8s |  |
| 597 | `proxy_enumeration` | 34 | 5.7s |  |
| 598 | `proxy_getproperty` | 77 | 5.8s |  |
| 599 | `proxy_hasownproperty` | 8 | 5.6s |  |
| 600 | `proxy_hasproperty` | 32 | 5.7s |  |
| 601 | `proxy_serialize` | 9 | 5.6s |  |
| 602 | `proxy_setproperty` | 42 | 5.7s |  |
| 603 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.6s |  |
| 604 | `qname_constr` | 32 | 5.7s |  |
| 605 | `qname_constr_namespace` | 24 | 5.7s |  |
| 606 | `qname_enumeration` | 9 | 5.7s |  |
| 607 | `qname_indexing` | 23 | 5.8s |  |
| 608 | `qname_tostring` | 25 | 5.8s |  |
| 609 | `qname_valueof` | 29 | 5.8s |  |
| 610 | `regexp_constr` | 148 | 6.1s |  |
| 611 | `regexp_exec` | 19 | 5.7s |  |
| 612 | `regexp_extended` | 47 | 5.7s |  |
| 613 | `regexp_multiargs` | 1 | 5.7s |  |
| 614 | `regexp_test` | 27 | 5.7s |  |
| 615 | `regexp_toString` | 10 | 5.8s |  |
| 616 | `register_script_refresh` | 35 | 6.3s |  |
| 617 | `remove_child_clear_field` | 88 | 6.1s |  |
| 618 | `remove_dobj` | 3 | 5.7s |  |
| 619 | `resolve_order` | 4 | 5.7s |  |
| 620 | `rng` | 1 | 6.8s |  |
| 621 | `rootless` | 42 | 5.7s |  |
| 622 | `rshift` | 1058 | 29.1s |  |
| 623 | `sandbox_type_local_file` | 1 | 5.6s |  |
| 624 | `scene_constr` | 8 | 5.8s |  |
| 625 | `set_local_0` | 31 | 5.7s |  |
| 626 | `set_property_is_enumerable` | 85 | 6.1s |  |
| 627 | `shape_drawrect` | 54 | 5.7s |  |
| 628 | `shared_object_no_root` | 3 | 5.5s |  |
| 629 | `simplebutton_added_to_stage` | 45 | 23.9s |  |
| 630 | `simplebutton_childevents` | 86 | 6.0s |  |
| 631 | `simplebutton_childevents_nested` | 54 | 6.0s |  |
| 632 | `simplebutton_childevents_sprite` | 13 | 5.7s |  |
| 633 | `simplebutton_childprops` | 144 | 5.9s |  |
| 634 | `simplebutton_childshuffle` | 23 | 5.6s |  |
| 635 | `simplebutton_constr` | 36 | 5.9s |  |
| 636 | `simplebutton_constr_childevents` | 48 | 5.9s |  |
| 637 | `simplebutton_constr_params` | 42 | 5.8s |  |
| 638 | `simplebutton_mouseenabled` | 26 | 5.7s |  |
| 639 | `simplebutton_multi_children` | 19 | 5.9s |  |
| 640 | `simplebutton_structure` | 27 | 5.8s |  |
| 641 | `simplebutton_symbolclass` | 68 | 6.1s |  |
| 642 | `slot_disp_id_shared_numbering` | 1 | 24.2s |  |
| 643 | `slots_force_autoassigned` | 1 | 5.6s |  |
| 644 | `sound_embeddedprops` | 26 | 5.2s |  |
| 645 | `sound_play` | 19 | 5.4s |  |
| 646 | `sound_valueof` | 33 | 5.3s |  |
| 647 | `soundchannel_soundtransform` | 835 | 25.1s |  |
| 648 | `soundchannel_soundtransform_exists` | 5 | 23.2s |  |
| 649 | `soundchannel_stop` | 8 | 5.3s |  |
| 650 | `soundmixer_buffertime` | 5 | 5.1s |  |
| 651 | `soundmixer_stopall` | 6 | 5.2s |  |
| 652 | `soundtransform` | 442 | 10.1s |  |
| 653 | `sprite_with_frames` | 0 | 5.8s |  |
| 654 | `stage3d_agal_cross_product` | 0 | 7.8s |  |
| 655 | `stage3d_bitmap` | 0 | 29.0s |  |
| 656 | `stage3d_float1_index` | 0 | 26.1s |  |
| 657 | `stage3d_fractal` | 0 | 8.2s |  |
| 658 | `stage3d_ignore_sampler_override` | 0 | 26.5s |  |
| 659 | `stage3d_program_constants_bytearray_be` | 0 | 26.9s |  |
| 660 | `stage3d_program_constants_bytearray_le` | 0 | 8.6s |  |
| 661 | `stage3d_raytrace` | 0 | 38.7s |  |
| 662 | `stage3d_rotating_cube` | 0 | 8.8s |  |
| 663 | `stage3d_sampler` | 0 | 8.0s |  |
| 664 | `stage3d_sampler_partial_upload` | 0 | 7.8s |  |
| 665 | `stage3d_stencil` | 0 | 25.6s |  |
| 666 | `stage3d_texture` | 0 | 12.4s |  |
| 667 | `stage3d_texture_bytearray` | 0 | 9.0s |  |
| 668 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.4s |  |
| 669 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.5s |  |
| 670 | `stage3d_triangle` | 0 | 7.9s |  |
| 671 | `stage3d_triangle_bytes4` | 0 | 7.9s |  |
| 672 | `stage3d_triangle_float1` | 0 | 7.8s |  |
| 673 | `stage3d_triangle_index_upload` | 0 | 7.8s |  |
| 674 | `stage_access` | 10 | 5.2s |  |
| 675 | `stage_displayobject_properties` | 24 | 5.2s |  |
| 676 | `stage_framerate_nan` | 7 | 5.3s |  |
| 677 | `stage_framerate_negative` | 6 | 5.2s |  |
| 678 | `stage_framerate_zero` | 6 | 5.2s |  |
| 679 | `stage_invalidate` | 38 | 5.3s |  |
| 680 | `stage_mousechildren` | 2 | 5.1s |  |
| 681 | `stage_mouseenabled` | 15 | 5.1s |  |
| 682 | `stage_overriden_setters` | 31 | 5.3s |  |
| 683 | `stage_properties` | 30 | 5.1s |  |
| 684 | `static_var_with_this_in_ctor` | 2 | 5.2s |  |
| 685 | `stored_properties` | 11 | 5.5s |  |
| 686 | `strict_equality` | 34 | 5.5s |  |
| 687 | `string_call` | 13 | 5.3s |  |
| 688 | `string_case` | 23 | 5.3s |  |
| 689 | `string_char_at` | 27 | 5.3s |  |
| 690 | `string_char_code_at` | 28 | 5.1s |  |
| 691 | `string_concat_fromcharcode` | 37 | 34.7s |  |
| 692 | `string_constr` | 25 | 5.5s |  |
| 693 | `string_indexof_lastindexof` | 87 | 5.7s |  |
| 694 | `string_length` | 16 | 5.5s |  |
| 695 | `string_locale_compare` | 39 | 5.8s |  |
| 696 | `string_match` | 51 | 5.7s |  |
| 697 | `string_relational_compare` | 4 | 5.5s |  |
| 698 | `string_replace` | 51 | 5.7s |  |
| 699 | `string_search` | 41 | 5.7s |  |
| 700 | `string_slice_substr_substring` | 170 | 6.6s |  |
| 701 | `string_split` | 29 | 5.5s |  |
| 702 | `string_substr_negative` | 21 | 5.4s |  |
| 703 | `string_substr_weird` | 182 | 5.4s |  |
| 704 | `subtract` | 1058 | 17.3s |  |
| 705 | `super_get_call` | 12 | 5.5s |  |
| 706 | `supercall_two_classobjects` | 2 | 5.5s |  |
| 707 | `swf8` | 1 | 5.3s |  |
| 708 | `swf_10_queued_goto_scripts_construct` | 52 | 5.7s |  |
| 709 | `swf_9_goto_in_enter_frame` | 17 | 5.6s |  |
| 710 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.6s |  |
| 711 | `swf_9_queued_goto_scripts` | 6 | 5.6s |  |
| 712 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 713 | `swf_9_versioning` | 2 | 5.4s |  |
| 714 | `swf_wrong_frame_count` | 38 | 5.7s |  |
| 715 | `swf_wrong_frame_count_isplaying` | 22 | 5.5s |  |
| 716 | `symbol_class_binary_data` | 8 | 5.5s |  |
| 717 | `symbol_class_conflict` | 4 | 6.0s |  |
| 718 | `symbol_class_root_not_zero` | 1 | 5.4s |  |
| 719 | `symbolclass_invalid_utf8` | 2 | 5.4s |  |
| 720 | `tab_ordering_automatic_advanced` | 184 | 6.6s |  |
| 721 | `tab_ordering_automatic_basic` | 45 | 6.1s |  |
| 722 | `tab_ordering_children` | 116 | 6.1s |  |
| 723 | `tab_ordering_custom_basic` | 34 | 6.0s |  |
| 724 | `text_engine_fontdescription` | 27 | 6.1s |  |
| 725 | `text_run` | 7 | 5.8s |  |
| 726 | `textfield_focusin_event` | 9 | 5.8s |  |
| 727 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 728 | `textfield_unload` | 39 | 25.0s |  |
| 729 | `textformat` | 1134 | 5.8s |  |
| 730 | `textformat_display` | 14 | 5.8s |  |
| 731 | `textformat_font_max_length` | 4 | 6.0s |  |
| 732 | `throw` | 3 | 5.8s |  |
| 733 | `timeline_scripts` | 3 | 6.1s |  |
| 734 | `timer` | 90 | 6.6s |  |
| 735 | `timer_events` | 3 | 6.0s |  |
| 736 | `timer_finished` | 11 | 6.0s |  |
| 737 | `timer_reset` | 8 | 6.0s |  |
| 738 | `timer_setdelay` | 5 | 5.9s |  |
| 739 | `trace` | 12 | 5.7s |  |
| 740 | `truthiness` | 30 | 16.0s |  |
| 741 | `try_catch` | 11 | 4.5s |  |
| 742 | `try_catch_typed` | 12 | 4.5s |  |
| 743 | `typeof` | 30 | 4.5s |  |
| 744 | `uint_constr` | 92 | 4.5s |  |
| 745 | `uint_tofixed` | 1215 | 4.4s |  |
| 746 | `uint_tostring` | 3375 | 4.5s |  |
| 747 | `unchecked_function` | 15 | 4.5s |  |
| 748 | `urlrequest` | 18 | 4.5s |  |
| 749 | `urshift` | 1058 | 4.5s |  |
| 750 | `vector_class` | 36 | 4.6s |  |
| 751 | `vector_class_call` | 11 | 4.5s |  |
| 752 | `vector_coercion` | 66 | 4.4s |  |
| 753 | `vector_concat` | 90 | 4.4s |  |
| 754 | `vector_constr` | 107 | 4.4s |  |
| 755 | `vector_enumeration` | 5 | 4.4s |  |
| 756 | `vector_every` | 92 | 4.5s |  |
| 757 | `vector_filter` | 95 | 4.5s |  |
| 758 | `vector_holes` | 24 | 4.5s |  |
| 759 | `vector_indexof` | 302 | 4.5s |  |
| 760 | `vector_insertat` | 270 | 4.5s |  |
| 761 | `vector_int_access` | 4 | 4.5s |  |
| 762 | `vector_int_delete` | 11 | 4.5s |  |
| 763 | `vector_join` | 58 | 4.5s |  |
| 764 | `vector_lastindexof` | 302 | 4.4s |  |
| 765 | `vector_legacy` | 10 | 4.4s |  |
| 766 | `vector_map` | 85 | 4.4s |  |
| 767 | `vector_object_final` | 1 | 4.5s |  |
| 768 | `vector_object_toString` | 10 | 4.5s |  |
| 769 | `vector_pushpop` | 255 | 4.5s |  |
| 770 | `vector_reborrow_bug` | 10 | 16.8s |  |
| 771 | `vector_removeat` | 172 | 6.7s |  |
| 772 | `vector_reverse` | 232 | 6.7s |  |
| 773 | `vector_shiftunshift` | 252 | 5.5s |  |
| 774 | `vector_slice` | 331 | 7.4s |  |
| 775 | `vector_sort` | 905 | 15.0s |  |
| 776 | `vector_splice` | 693 | 9.5s |  |
| 777 | `vector_splice_fixed_bug_compat` | 4 | 5.5s |  |
| 778 | `vector_tostring` | 79 | 6.1s |  |
| 779 | `verify_abnormal_loop` | 1 | 5.4s |  |
| 780 | `verify_exception_targets_edge_case` | 1 | 5.5s |  |
| 781 | `verify_lookup_switch_edge_case` | 1 | 5.4s |  |
| 782 | `verify_unreachable_exception` | 2 | 5.7s |  |
| 783 | `versioned_isplaying` | 2 | 5.6s |  |
| 784 | `virtual_properties` | 16 | 5.7s |  |
| 785 | `with` | 4 | 5.5s |  |
| 786 | `xml_abstract_equality` | 36 | 5.7s |  |
| 787 | `xml_advanced` | 52 | 5.6s |  |
| 788 | `xml_appendchild` | 10 | 5.5s |  |
| 789 | `xml_as_attribute` | 9 | 5.5s |  |
| 790 | `xml_attribute` | 35 | 5.8s |  |
| 791 | `xml_attribute_name` | 40 | 5.6s |  |
| 792 | `xml_basic` | 33 | 5.7s |  |
| 793 | `xml_child` | 25 | 5.8s |  |
| 794 | `xml_childindex` | 7 | 5.7s |  |
| 795 | `xml_children` | 43 | 6.4s |  |
| 796 | `xml_class_call` | 9 | 5.7s |  |
| 797 | `xml_contains` | 197 | 6.0s |  |
| 798 | `xml_copy` | 20 | 16.7s |  |
| 799 | `xml_ctor_from_tostring` | 23 | 5.8s |  |
| 800 | `xml_delete` | 114 | 5.6s |  |
| 801 | `xml_descendants` | 83 | 5.5s |  |
| 802 | `xml_elements` | 6 | 5.4s |  |
| 803 | `xml_equals_namespace_check` | 2 | 5.4s |  |
| 804 | `xml_explicit_use_namespace` | 5 | 23.3s |  |
| 805 | `xml_getdescendants_qname` | 21 | 5.4s |  |
| 806 | `xml_has_property_via_in` | 26 | 5.5s |  |
| 807 | `xml_hasownproperty` | 6 | 5.4s |  |
| 808 | `xml_ignore_white` | 6 | 5.5s |  |
| 809 | `xml_length` | 2 | 5.4s |  |
| 810 | `xml_list_as_attribute` | 9 | 5.4s |  |
| 811 | `xml_list_concat` | 20 | 5.5s |  |
| 812 | `xml_list_enumerate` | 4 | 5.4s |  |
| 813 | `xml_methods_settings` | 3 | 5.4s |  |
| 814 | `xml_mismatched_tag` | 37 | 5.5s |  |
| 815 | `xml_namespace` | 39 | 5.4s |  |
| 816 | `xml_namespace_methods` | 245 | 5.5s |  |
| 817 | `xml_namespaced_property` | 7 | 5.4s |  |
| 818 | `xml_no_namespace` | 1 | 5.4s |  |
| 819 | `xml_nodekind` | 3 | 5.4s |  |
| 820 | `xml_normalize` | 35 | 5.6s |  |
| 821 | `xml_notification_bubbling` | 361 | 5.5s |  |
| 822 | `xml_parent` | 8 | 5.6s |  |
| 823 | `xml_set_children` | 17 | 5.5s |  |
| 824 | `xml_set_name` | 34 | 5.5s |  |
| 825 | `xml_settings` | 6 | 2.7s |  |
| 826 | `xml_simple_complex_content` | 47 | 5.5s |  |
| 827 | `xml_text` | 7 | 5.5s |  |
| 828 | `xml_tostring` | 6 | 5.5s |  |
| 829 | `xml_tostring_namespace` | 12 | 5.4s |  |
| 830 | `xml_unescaping` | 23 | 5.5s |  |
| 831 | `xml_weird_ignores` | 54 | 5.5s |  |
| 832 | `xml_wildcard` | 11 | 5.4s |  |
| 833 | `xmldocument` | 254 | 5.6s |  |
| 834 | `xmlnode` | 3540 | 5.6s |  |
| 835 | `zero_frame_clip` | 3 | 5.7s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 5.7s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 5.4s |  |
| 3 | `blend_transform` | 1 | 1 | 6.2s |  |
| 4 | `coerce_property` | 3 | 3 | 5.8s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.8s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 5.7s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.9s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 5.1s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.7s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 5.7s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.6s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 23.7s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 24.6s |  |
| 15 | `int_toexponential` | 76 | 76 | 5.1s |  |
| 16 | `int_toprecision` | 441 | 441 | 5.1s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 5.8s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.5s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 24.1s |  |
| 20 | `soundchannel_position` | 74 | 74 | 24.4s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 5.5s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 5.2s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 5.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 4.5s |  |
| 25 | `uint_toprecision` | 433 | 433 | 4.5s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 5.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**68 tests** within reach

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
| 51 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 52 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 53 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 54 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 55 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 56 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 57 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 58 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 59 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 60 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 61 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 62 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 63 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 64 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 65 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 66 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 67 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 68 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 5.8s |  |
| 2 | `method_without_body` | exit code 1 | 23.7s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.6s |  |
| 4 | `verify_typecheck` | exit code 1 | 5.6s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 34.0s |  |

## All Output Mismatches

**351 tests** with output mismatch, sorted by match rate (best first)

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
| 51 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 52 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 53 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 54 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 55 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 56 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 57 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 58 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 59 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 60 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 61 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 62 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 63 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 64 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 65 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 66 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 67 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 68 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 69 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 70 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 71 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 72 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 73 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 74 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 75 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 76 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 77 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 78 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 79 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 80 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 81 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 82 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 83 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 84 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 85 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 86 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 87 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 88 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 89 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 90 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 91 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 92 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 93 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 94 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 95 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 96 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 97 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 98 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 99 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 100 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 101 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 102 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 103 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 104 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 105 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 106 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 107 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 108 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 109 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 110 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 111 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 112 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 113 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 114 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 115 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 116 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 117 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 118 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 119 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 120 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 121 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 122 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 123 | `loader_events` | 8.7% | 8/92 | 20 | 92 |  |
| 124 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 125 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 126 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 127 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 128 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 129 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 130 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 131 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 132 | `loader_loadbytes_events` | 6.7% | 2/30 | 7 | 30 |  |
| 133 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 134 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 135 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 136 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 137 | `primitive_toString` | 5.8% | 16/277 | 141 | 277 |  |
| 138 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 139 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 140 | `primitive_valueOf` | 4.9% | 14/285 | 141 | 285 |  |
| 141 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 142 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 143 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 144 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 145 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 146 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 147 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 148 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 149 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 150 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 151 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 152 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 153 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 154 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 155 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 156 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 157 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 158 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 159 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 160 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 161 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 162 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 163 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 164 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 165 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 166 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 167 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 168 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 169 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 170 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 171 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 172 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 173 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 174 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 175 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 176 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 177 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 178 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 179 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 180 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 181 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 182 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 183 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 184 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 185 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 186 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 187 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 188 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 189 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 190 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 191 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 192 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 193 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 194 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 195 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 196 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 197 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 198 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 199 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 200 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 201 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 202 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 203 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 204 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 205 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 206 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 207 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 208 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 209 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 210 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 211 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 212 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 213 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 214 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 215 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 216 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 217 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 218 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 219 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 220 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 221 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 222 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 223 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 224 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 225 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 226 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 227 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 228 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 229 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 230 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 231 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 232 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 233 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 234 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 235 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 236 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 237 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 238 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 239 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 240 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 241 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 242 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 243 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 244 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 245 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 246 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 247 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 248 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 249 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 250 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 251 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 252 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 253 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 254 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 255 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 256 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 257 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 258 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 259 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 260 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 261 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 262 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 263 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 264 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 265 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 266 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 267 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 268 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 269 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 270 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 271 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 272 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 273 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 274 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 275 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 276 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 277 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 278 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 279 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 280 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 281 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 282 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 283 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 284 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 285 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 286 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 287 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 288 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 289 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 290 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 291 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 292 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 293 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 294 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 295 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 296 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 297 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 298 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 299 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 300 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 301 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 302 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 303 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 304 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 305 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 307 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 308 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 309 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 310 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 311 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 312 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 313 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 314 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 315 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 316 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 317 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 318 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 319 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 320 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 321 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 322 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 323 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 324 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 325 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 326 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 327 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 328 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 329 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 330 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 331 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 332 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 333 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 334 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 335 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 336 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 337 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 338 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 339 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 340 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 341 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 342 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 343 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 344 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 345 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 346 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 347 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 348 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 349 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 350 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 351 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
