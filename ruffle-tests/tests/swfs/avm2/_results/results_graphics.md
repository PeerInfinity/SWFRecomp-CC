# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-14 00:42 UTC

**Git SHA**: `9e27d9d61b`

**Run Duration**: 130m 53s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1204 |
| Passing | **828** (68.8%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **852** (70.8%) |
| Failing | 352 |
| Total expected lines | 149868 |
| Matching lines | 102544 (68.4%) |
| Mismatched lines | 47324 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 347 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**828 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 4.6s |  |
| 2 | `agal_compiler` | 13 | 4.6s |  |
| 3 | `air_hidden_lookup` | 2 | 4.5s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.4s |  |
| 5 | `amf_custom_obj` | 26 | 4.5s |  |
| 6 | `amf_dictionary` | 9 | 4.5s |  |
| 7 | `amf_function` | 46 | 4.5s |  |
| 8 | `amf_invalid_date` | 2 | 4.5s |  |
| 9 | `amf_missing_prop` | 6 | 4.6s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.0s |  |
| 11 | `amf_setter_error` | 8 | 5.2s |  |
| 12 | `amf_vector` | 40 | 5.2s |  |
| 13 | `amf_xml` | 6 | 5.0s |  |
| 14 | `application_domain` | 4 | 5.1s |  |
| 15 | `array_access` | 18 | 5.1s |  |
| 16 | `array_access_interpreter` | 4 | 5.1s |  |
| 17 | `array_access_no_pubns` | 2 | 5.0s |  |
| 18 | `array_concat` | 41 | 5.1s |  |
| 19 | `array_constr` | 10 | 5.1s |  |
| 20 | `array_delete` | 44 | 5.2s |  |
| 21 | `array_enumeration` | 10 | 5.1s |  |
| 22 | `array_enumeration_elements` | 11 | 5.1s |  |
| 23 | `array_every` | 8 | 5.1s |  |
| 24 | `array_filter` | 6 | 5.1s |  |
| 25 | `array_foreach` | 18 | 5.1s |  |
| 26 | `array_hasownproperty` | 11 | 2.8s |  |
| 27 | `array_holes` | 9 | 5.1s |  |
| 28 | `array_index_max` | 84 | 4.9s |  |
| 29 | `array_indexof` | 25 | 5.4s |  |
| 30 | `array_join` | 26 | 5.2s |  |
| 31 | `array_lastindexof` | 29 | 5.1s |  |
| 32 | `array_length` | 14 | 5.1s |  |
| 33 | `array_literal` | 3 | 5.1s |  |
| 34 | `array_map` | 8 | 5.0s |  |
| 35 | `array_pop` | 52 | 5.1s |  |
| 36 | `array_push` | 24 | 5.2s |  |
| 37 | `array_reborrow_bug` | 6 | 5.2s |  |
| 38 | `array_reverse` | 28 | 5.0s |  |
| 39 | `array_shift` | 51 | 2.9s |  |
| 40 | `array_slice` | 39 | 5.1s |  |
| 41 | `array_some` | 8 | 5.1s |  |
| 42 | `array_sort` | 297 | 5.3s |  |
| 43 | `array_sort_fun_swf12` | 2 | 5.1s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 45 | `array_sort_random` | 210 | 5.2s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 5.1s |  |
| 47 | `array_sorton` | 545 | 5.4s |  |
| 48 | `array_sparse_ops` | 41 | 5.1s |  |
| 49 | `array_splice` | 133 | 5.2s |  |
| 50 | `array_splice2` | 428 | 5.2s |  |
| 51 | `array_splice_types` | 48 | 5.1s |  |
| 52 | `array_storage` | 8 | 5.1s |  |
| 53 | `array_tolocalestring` | 9 | 5.0s |  |
| 54 | `array_tostring` | 12 | 5.0s |  |
| 55 | `array_unshift` | 24 | 5.1s |  |
| 56 | `array_valueof` | 9 | 4.9s |  |
| 57 | `array_vector_null_callback` | 10 | 5.0s |  |
| 58 | `astype` | 28 | 5.0s |  |
| 59 | `astypelate` | 24 | 5.2s |  |
| 60 | `astypelate_propagates` | 1 | 5.0s |  |
| 61 | `asymmetric_key_events` | 11 | 5.0s |  |
| 62 | `avm2_catchup_dobj` | 158 | 5.5s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 69.8s |  |
| 64 | `bitand` | 1058 | 7.4s |  |
| 65 | `bitmap_constr` | 17 | 5.2s |  |
| 66 | `bitmap_data` | 1000 | 10.0s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 24.7s |  |
| 68 | `bitmap_properties` | 23 | 5.0s |  |
| 69 | `bitmap_subclass` | 7 | 6.2s |  |
| 70 | `bitmap_subclass_properties` | 9 | 5.6s |  |
| 71 | `bitmap_timeline` | 9 | 5.1s |  |
| 72 | `bitmapdata_accuracy` | 1 | 47.3s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 25.1s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.9s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 24.9s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 24.9s |  |
| 77 | `bitmapdata_clone` | 13 | 5.4s |  |
| 78 | `bitmapdata_colortransform` | 0 | 5.6s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 5.0s |  |
| 80 | `bitmapdata_constr` | 22 | 5.1s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 5.3s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.7s |  |
| 83 | `bitmapdata_copypixels` | 23 | 26.2s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.3s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.0s |  |
| 86 | `bitmapdata_dispose` | 7 | 4.9s |  |
| 87 | `bitmapdata_draw` | 0 | 25.5s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 5.5s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.5s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 24.4s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 5.1s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 5.4s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 5.3s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 24.2s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 5.2s |  |
| 96 | `bitmapdata_embedded` | 9 | 5.4s |  |
| 97 | `bitmapdata_fillrect` | 0 | 5.3s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 24.4s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.0s |  |
| 100 | `bitmapdata_getpixels` | 39 | 23.9s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.7s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.7s |  |
| 103 | `bitmapdata_hittest` | 112 | 5.5s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 4.9s |  |
| 105 | `bitmapdata_opaque` | 0 | 5.3s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 5.3s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 5.4s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 4.9s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.0s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.0s |  |
| 111 | `bitmapdata_sync` | 0 | 5.2s |  |
| 112 | `bitmapdata_threshold` | 176 | 5.5s |  |
| 113 | `bitmapdata_zero_size` | 5 | 4.8s |  |
| 114 | `bitnot` | 46 | 4.8s |  |
| 115 | `bitor` | 1058 | 7.1s |  |
| 116 | `bitxor` | 1058 | 7.2s |  |
| 117 | `blend_multiply_alpha` | 0 | 5.4s |  |
| 118 | `blend_scroll` | 0 | 5.5s |  |
| 119 | `boolean_constr` | 32 | 4.7s |  |
| 120 | `boolean_negation` | 30 | 4.8s |  |
| 121 | `boolean_tostring` | 8 | 4.7s |  |
| 122 | `broadcast_event` | 7 | 4.6s |  |
| 123 | `button_nested_frame` | 48 | 5.0s |  |
| 124 | `bytearray` | 48 | 4.9s |  |
| 125 | `bytearray_compress` | 31 | 4.7s |  |
| 126 | `bytearray_errors` | 24 | 4.9s |  |
| 127 | `bytearray_method_serialization` | 1 | 4.7s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 4.7s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 4.7s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 4.7s |  |
| 131 | `bytearray_serialization` | 3 | 4.6s |  |
| 132 | `bytearray_string_null` | 19 | 4.8s |  |
| 133 | `bytearray_tostring` | 15 | 4.7s |  |
| 134 | `bytearray_utf16` | 8 | 2.5s |  |
| 135 | `bytearray_writeobject` | 24 | 4.5s |  |
| 136 | `callee_in_initializer` | 6 | 4.6s |  |
| 137 | `callproplex_class` | 1 | 4.6s |  |
| 138 | `catch_class` | 6 | 4.6s |  |
| 139 | `catch_scope_slot` | 7 | 4.7s |  |
| 140 | `checkfilter` | 4 | 2.5s |  |
| 141 | `class_call` | 32 | 4.7s |  |
| 142 | `class_cast_call` | 14 | 4.6s |  |
| 143 | `class_enumeration` | 4 | 4.6s |  |
| 144 | `class_has_own_property` | 2 | 4.6s |  |
| 145 | `class_init_interpreter_mode` | 1 | 4.5s |  |
| 146 | `class_is` | 32 | 4.6s |  |
| 147 | `class_methods` | 5 | 4.6s |  |
| 148 | `class_object_properties` | 10 | 4.7s |  |
| 149 | `class_singleton` | 18 | 4.6s |  |
| 150 | `class_supercalls_errors` | 35 | 2.7s |  |
| 151 | `class_supercalls_mismatched` | 26 | 3.7s |  |
| 152 | `class_superclass_wrong_order` | 1 | 3.2s |  |
| 153 | `class_to_locale_string` | 2 | 3.2s |  |
| 154 | `class_to_string` | 2 | 3.2s |  |
| 155 | `class_value_of` | 2 | 3.1s |  |
| 156 | `click_block` | 5 | 16.5s |  |
| 157 | `click_invisible` | 3 | 3.4s |  |
| 158 | `closures` | 12 | 3.2s |  |
| 159 | `coerce_property` | 33 | 3.2s |  |
| 160 | `coerce_return_type` | 40 | 3.2s |  |
| 161 | `coerce_return_type_fail` | 2 | 3.0s |  |
| 162 | `coerce_return_void` | 3 | 3.1s |  |
| 163 | `coerce_string` | 86 | 3.6s |  |
| 164 | `coerce_string_precision` | 28 | 3.1s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 3.1s |  |
| 166 | `construct_errors_swf10` | 8 | 3.1s |  |
| 167 | `construct_frame_list` | 22 | 3.7s |  |
| 168 | `constructor_call` | 3 | 3.2s |  |
| 169 | `constructors_vs_timeline` | 5 | 16.3s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 3.1s |  |
| 171 | `control_flow_bool` | 4 | 3.0s |  |
| 172 | `control_flow_stricteq` | 8 | 3.0s |  |
| 173 | `convert_boolean` | 30 | 3.0s |  |
| 174 | `convert_integer` | 90 | 3.1s |  |
| 175 | `convert_number` | 56 | 3.1s |  |
| 176 | `convert_uinteger` | 90 | 3.1s |  |
| 177 | `cryptscore` | 11 | 4.8s |  |
| 178 | `declocal` | 46 | 4.7s |  |
| 179 | `declocal_i` | 46 | 4.7s |  |
| 180 | `decrement` | 46 | 4.7s |  |
| 181 | `decrement_i` | 46 | 2.6s |  |
| 182 | `default_values` | 7 | 4.6s |  |
| 183 | `dictionary_access` | 62 | 5.0s |  |
| 184 | `dictionary_access_no_pubns` | 2 | 4.8s |  |
| 185 | `dictionary_delete` | 101 | 5.0s |  |
| 186 | `dictionary_foreach` | 42 | 5.0s |  |
| 187 | `dictionary_hasownproperty` | 63 | 4.9s |  |
| 188 | `dictionary_in` | 62 | 4.8s |  |
| 189 | `dictionary_iter_modify` | 8 | 4.9s |  |
| 190 | `dictionary_namespaces` | 36 | 4.9s |  |
| 191 | `dictionary_primitive_keys` | 29 | 4.8s |  |
| 192 | `displayobject_alpha` | 277 | 4.8s |  |
| 193 | `displayobject_blendmode` | 0 | 24.3s |  |
| 194 | `displayobject_colortransform_nested` | 0 | 22.2s |  |
| 195 | `displayobject_from_enterframe` | 1 | 4.9s |  |
| 196 | `displayobject_getbounds_shape` | 0 | 24.4s |  |
| 197 | `displayobject_height` | 6052 | 24.5s |  |
| 198 | `displayobject_hittestobject` | 32 | 4.9s |  |
| 199 | `displayobject_invalid_floats` | 60 | 4.9s |  |
| 200 | `displayobject_invalid_props` | 3 | 5.6s |  |
| 201 | `displayobject_mask` | 3 | 5.4s |  |
| 202 | `displayobject_mask_self_referential` | 0 | 4.9s |  |
| 203 | `displayobject_metaData` | 3 | 4.9s |  |
| 204 | `displayobject_name` | 22 | 5.2s |  |
| 205 | `displayobject_name_from_timeline` | 24 | 5.0s |  |
| 206 | `displayobject_parent` | 12 | 4.9s |  |
| 207 | `displayobject_root` | 24 | 4.9s |  |
| 208 | `displayobject_rotation` | 1275 | 4.8s |  |
| 209 | `displayobject_set_matrix_nested` | 0 | 23.6s |  |
| 210 | `displayobject_subclass` | 2 | 4.9s |  |
| 211 | `displayobject_visible` | 23 | 4.8s |  |
| 212 | `displayobject_width` | 4852 | 23.4s |  |
| 213 | `displayobject_x` | 614 | 4.7s |  |
| 214 | `displayobject_y` | 617 | 4.8s |  |
| 215 | `displayobjectcontainer_addchild` | 32 | 4.9s |  |
| 216 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.8s |  |
| 217 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.0s |  |
| 218 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.9s |  |
| 219 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.9s |  |
| 220 | `displayobjectcontainer_addchildat` | 42 | 4.8s |  |
| 221 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.9s |  |
| 222 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.9s |  |
| 223 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.9s |  |
| 224 | `displayobjectcontainer_contains` | 66 | 5.1s |  |
| 225 | `displayobjectcontainer_getchildat` | 4 | 4.9s |  |
| 226 | `displayobjectcontainer_getchildbyname` | 9 | 4.8s |  |
| 227 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.8s |  |
| 228 | `displayobjectcontainer_getchildindex` | 28 | 4.8s |  |
| 229 | `displayobjectcontainer_removechild` | 10 | 4.8s |  |
| 230 | `displayobjectcontainer_removechild_errors` | 4 | 4.8s |  |
| 231 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.8s |  |
| 232 | `displayobjectcontainer_removechildat` | 18 | 4.8s |  |
| 233 | `displayobjectcontainer_removechildren` | 51 | 5.1s |  |
| 234 | `displayobjectcontainer_setchildindex` | 42 | 4.6s |  |
| 235 | `displayobjectcontainer_stopallmovieclips` | 2 | 4.9s |  |
| 236 | `displayobjectcontainer_swapchildren` | 42 | 4.7s |  |
| 237 | `displayobjectcontainer_swapchildrenat` | 42 | 4.7s |  |
| 238 | `displayobjectcontainer_timelineinstance` | 48 | 23.0s |  |
| 239 | `divide` | 1058 | 6.8s |  |
| 240 | `doabc_is_eager` | 1 | 22.6s |  |
| 241 | `documentclass` | 9 | 4.8s |  |
| 242 | `drag_drop` | 10 | 4.8s |  |
| 243 | `duplicate_defs` | 1 | 4.5s |  |
| 244 | `eager_init` | 1 | 4.7s |  |
| 245 | `edit_text_linkage` | 7 | 4.9s |  |
| 246 | `edittext_align` | 60 | 4.9s |  |
| 247 | `edittext_always_show_selection` | 0 | 23.4s |  |
| 248 | `edittext_antialiastype` | 296 | 4.8s |  |
| 249 | `edittext_at_point_methods_basic` | 16 | 5.8s |  |
| 250 | `edittext_autosize` | 39 | 4.9s |  |
| 251 | `edittext_autosize_align` | 0 | 23.4s |  |
| 252 | `edittext_autosize_height_dynamic` | 60 | 23.5s |  |
| 253 | `edittext_autosize_height_input` | 60 | 4.8s |  |
| 254 | `edittext_autosize_lazy_bounds_events` | 65 | 4.9s |  |
| 255 | `edittext_autosize_lazy_bounds_interactions` | 19 | 4.7s |  |
| 256 | `edittext_autosize_lazy_bounds_props` | 490 | 6.0s |  |
| 257 | `edittext_autosize_lazy_bounds_visual` | 0 | 23.1s |  |
| 258 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 4.8s |  |
| 259 | `edittext_bottom_scroll_v_basic` | 210 | 4.8s |  |
| 260 | `edittext_bounds_scale` | 24 | 22.7s |  |
| 261 | `edittext_bullet` | 30 | 4.7s |  |
| 262 | `edittext_default_format` | 221 | 4.9s |  |
| 263 | `edittext_default_format_empty` | 136 | 4.9s |  |
| 264 | `edittext_empty_text_format` | 7 | 4.7s |  |
| 265 | `edittext_focus_selection` | 5 | 4.7s |  |
| 266 | `edittext_font_size` | 45 | 4.8s |  |
| 267 | `edittext_format_empty_font` | 8 | 4.6s |  |
| 268 | `edittext_get_char_index_at_point` | 4 | 24.1s |  |
| 269 | `edittext_get_line_index_at_point` | 2 | 19.3s |  |
| 270 | `edittext_get_line_index_of_char` | 76 | 4.7s |  |
| 271 | `edittext_getcharboundaries` | 172 | 4.1s |  |
| 272 | `edittext_getcharboundaries_missing_glyphs` | 63 | 4.1s |  |
| 273 | `edittext_getcharboundaries_scroll` | 85 | 3.9s |  |
| 274 | `edittext_getlinemetrics` | 146 | 3.9s |  |
| 275 | `edittext_html` | 3101 | 4.1s |  |
| 276 | `edittext_html_condensewhite` | 487 | 3.9s |  |
| 277 | `edittext_html_entity` | 4 | 4.0s |  |
| 278 | `edittext_html_font_size_swf12` | 267 | 3.8s |  |
| 279 | `edittext_html_font_size_swf13` | 273 | 3.6s |  |
| 280 | `edittext_html_roundtrip` | 17 | 4.1s |  |
| 281 | `edittext_input_control` | 12 | 3.8s |  |
| 282 | `edittext_leading` | 9 | 3.9s |  |
| 283 | `edittext_letter_spacing` | 15 | 3.8s |  |
| 284 | `edittext_line_methods` | 294 | 4.6s |  |
| 285 | `edittext_line_metrics` | 11 | 19.8s |  |
| 286 | `edittext_margins` | 25 | 3.8s |  |
| 287 | `edittext_max_scroll_h_basic` | 475 | 4.0s |  |
| 288 | `edittext_max_scroll_v_basic` | 1000 | 3.9s |  |
| 289 | `edittext_mousedown` | 3 | 4.0s |  |
| 290 | `edittext_mouseenabled` | 26 | 3.8s |  |
| 291 | `edittext_newline_character` | 22 | 3.8s |  |
| 292 | `edittext_newline_stripping` | 64 | 5.3s |  |
| 293 | `edittext_newlines` | 30 | 4.0s |  |
| 294 | `edittext_paragraph_methods` | 257 | 3.9s |  |
| 295 | `edittext_paste_events` | 8 | 3.8s |  |
| 296 | `edittext_paste_maxchars` | 4 | 3.8s |  |
| 297 | `edittext_paste_restrict` | 16 | 3.7s |  |
| 298 | `edittext_restrict` | 191 | 3.8s |  |
| 299 | `edittext_restrict_events` | 22 | 3.8s |  |
| 300 | `edittext_scrollh` | 10 | 3.7s |  |
| 301 | `edittext_selected_text` | 9 | 3.8s |  |
| 302 | `edittext_set_html_same` | 17 | 3.9s |  |
| 303 | `edittext_set_text_vs_html` | 9 | 3.8s |  |
| 304 | `edittext_stylesheet` | 536 | 4.0s |  |
| 305 | `edittext_stylesheet_custom_tag` | 76 | 5.1s |  |
| 306 | `edittext_stylesheet_display` | 272 | 5.2s |  |
| 307 | `edittext_underline` | 40 | 5.0s |  |
| 308 | `edittext_width_height` | 103 | 5.2s |  |
| 309 | `edittext_wordwrap_word` | 150 | 5.3s |  |
| 310 | `edittext_wrap_breaks` | 2375 | 5.5s |  |
| 311 | `empty_bounds` | 1 | 4.8s |  |
| 312 | `equals` | 512 | 5.8s |  |
| 313 | `error_prototype` | 15 | 4.8s |  |
| 314 | `error_stack_trace_debug_swf17` | 0 | 24.1s |  |
| 315 | `error_stack_trace_debug_swf18` | 0 | 4.9s |  |
| 316 | `error_stack_trace_release_swf17` | 0 | 4.8s |  |
| 317 | `error_stack_trace_release_swf18` | 0 | 4.8s |  |
| 318 | `error_tostring` | 29 | 4.8s |  |
| 319 | `es3_inheritance` | 31 | 4.9s |  |
| 320 | `es4_inheritance` | 30 | 4.9s |  |
| 321 | `es4_interfaces` | 30 | 4.9s |  |
| 322 | `es4_method_binding` | 8 | 4.8s |  |
| 323 | `es4_oop_prototypes` | 14 | 5.2s |  |
| 324 | `es4_protected_inheritance` | 6 | 4.9s |  |
| 325 | `event_bubbles` | 2 | 4.8s |  |
| 326 | `event_cancelable` | 2 | 4.8s |  |
| 327 | `event_clone` | 20 | 4.9s |  |
| 328 | `event_clone_error_redispatch` | 3 | 5.0s |  |
| 329 | `event_clone_on_redispatch` | 10 | 5.8s |  |
| 330 | `event_formattostring` | 31 | 5.0s |  |
| 331 | `event_handler_exception` | 4 | 4.9s |  |
| 332 | `event_isdefaultprevented` | 12 | 4.9s |  |
| 333 | `event_target_getter` | 5 | 4.9s |  |
| 334 | `event_target_set` | 9 | 4.8s |  |
| 335 | `event_type` | 1 | 4.8s |  |
| 336 | `event_valueof_tostring` | 18 | 4.8s |  |
| 337 | `eventdispatcher_dispatchevent` | 12 | 4.8s |  |
| 338 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.9s |  |
| 339 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 4.9s |  |
| 340 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.9s |  |
| 341 | `eventdispatcher_dispatchevent_this` | 5 | 4.8s |  |
| 342 | `eventdispatcher_haseventlistener` | 25 | 4.9s |  |
| 343 | `eventdispatcher_interface_invoke` | 1 | 4.8s |  |
| 344 | `eventdispatcher_tostring` | 10 | 4.9s |  |
| 345 | `eventdispatcher_willtrigger` | 25 | 4.8s |  |
| 346 | `falsiness` | 30 | 4.9s |  |
| 347 | `fast_index_access` | 12 | 5.0s |  |
| 348 | `finddef` | 3 | 4.9s |  |
| 349 | `findprop_global_prototype` | 6 | 4.9s |  |
| 350 | `flash_xml` | 29 | 4.9s |  |
| 351 | `flash_xml_cloneNode` | 22 | 4.9s |  |
| 352 | `flash_xml_namespace` | 109 | 4.9s |  |
| 353 | `flash_xml_removeNode` | 60 | 5.1s |  |
| 354 | `focus_events_code` | 161 | 21.1s |  |
| 355 | `focus_events_key_same_object` | 26 | 4.4s |  |
| 356 | `focus_events_mixed_key_mouse` | 100 | 21.0s |  |
| 357 | `focus_events_mouse_same_object` | 40 | 4.4s |  |
| 358 | `focus_remove` | 20 | 20.9s |  |
| 359 | `focus_root_movie` | 4 | 20.9s |  |
| 360 | `focus_stage` | 1 | 4.3s |  |
| 361 | `focusrect` | 18 | 5.0s |  |
| 362 | `font_description_clone` | 14 | 4.3s |  |
| 363 | `font_embedded` | 24 | 4.6s |  |
| 364 | `font_enumeratefonts` | 41 | 4.8s |  |
| 365 | `font_enumeratefonts_filter` | 4 | 4.9s |  |
| 366 | `font_hasglyphs` | 40 | 4.7s |  |
| 367 | `framelabel_constr` | 5 | 4.4s |  |
| 368 | `function_call` | 12 | 4.5s |  |
| 369 | `function_call_arguments` | 46 | 4.5s |  |
| 370 | `function_call_arguments_enumerate` | 5 | 4.3s |  |
| 371 | `function_call_coercion` | 108 | 4.6s |  |
| 372 | `function_call_default` | 6 | 4.3s |  |
| 373 | `function_call_rest` | 22 | 4.4s |  |
| 374 | `function_call_types` | 3 | 4.4s |  |
| 375 | `function_call_via_apply` | 11 | 4.3s |  |
| 376 | `function_call_via_call` | 3 | 4.3s |  |
| 377 | `function_display_anonymous` | 7 | 2.4s |  |
| 378 | `function_length` | 6 | 4.4s |  |
| 379 | `function_object` | 2 | 4.4s |  |
| 380 | `function_proto` | 5 | 4.3s |  |
| 381 | `function_proto_created` | 61 | 4.4s |  |
| 382 | `function_to_locale_string` | 4 | 4.4s |  |
| 383 | `function_to_string` | 4 | 5.7s |  |
| 384 | `function_type` | 6 | 4.9s |  |
| 385 | `function_unbound_this` | 51 | 5.0s |  |
| 386 | `function_value_of` | 4 | 4.8s |  |
| 387 | `get_definition_by_name` | 11 | 4.8s |  |
| 388 | `get_qualified_class_name` | 20 | 4.8s |  |
| 389 | `get_qualified_super_class_name` | 18 | 4.8s |  |
| 390 | `get_slot_edge_cases` | 1 | 4.7s |  |
| 391 | `get_timer` | 2 | 4.7s |  |
| 392 | `getglobalslot` | 1 | 4.6s |  |
| 393 | `getouterscope` | 8 | 4.6s |  |
| 394 | `getter_different_namespace_setter` | 2 | 4.7s |  |
| 395 | `goto_button_nested_framescript` | 28 | 4.9s |  |
| 396 | `goto_in_constructframe` | 12 | 4.9s |  |
| 397 | `goto_in_scene_last_frame` | 2 | 23.0s |  |
| 398 | `goto_methods` | 56 | 4.9s |  |
| 399 | `goto_methods_swfver10` | 8 | 4.8s |  |
| 400 | `goto_nested_construct_sibling` | 18 | 5.1s |  |
| 401 | `goto_nested_framescript` | 9 | 4.9s |  |
| 402 | `goto_on_orphan` | 15 | 5.0s |  |
| 403 | `graphics_bitmap_fill` | 0 | 6.6s |  |
| 404 | `graphics_bitmaps` | 0 | 5.5s |  |
| 405 | `graphics_direct_commands` | 0 | 5.5s |  |
| 406 | `graphics_gradients` | 0 | 5.3s |  |
| 407 | `graphics_gradients_nulls` | 0 | 5.1s |  |
| 408 | `graphics_round_rects` | 0 | 5.0s |  |
| 409 | `graphics_simple_shapes` | 0 | 5.2s |  |
| 410 | `greaterequals` | 512 | 5.9s |  |
| 411 | `greaterthan` | 512 | 5.9s |  |
| 412 | `has_own_property` | 102 | 5.1s |  |
| 413 | `hasownproperty_namespaces` | 2 | 4.8s |  |
| 414 | `hello_world` | 1 | 4.8s |  |
| 415 | `hittest_morph` | 30 | 5.0s |  |
| 416 | `if_eq` | 10 | 4.8s |  |
| 417 | `if_gt` | 1 | 4.9s |  |
| 418 | `if_gte` | 10 | 2.7s |  |
| 419 | `if_lt` | 1 | 1.1s |  |
| 420 | `if_lte` | 10 | 4.8s |  |
| 421 | `if_ne` | 7 | 2.7s |  |
| 422 | `if_stricteq` | 6 | 4.9s |  |
| 423 | `if_strictne` | 11 | 4.9s |  |
| 424 | `in` | 102 | 5.1s |  |
| 425 | `inclocal` | 46 | 4.9s |  |
| 426 | `inclocal_i` | 46 | 4.9s |  |
| 427 | `increment` | 46 | 4.9s |  |
| 428 | `increment_i` | 46 | 4.9s |  |
| 429 | `instanceof` | 58 | 5.0s |  |
| 430 | `instantiation_on_enter_frame` | 7 | 23.3s |  |
| 431 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.8s |  |
| 432 | `int_constr` | 92 | 4.9s |  |
| 433 | `int_edge_cases` | 19 | 4.9s |  |
| 434 | `int_instanceof` | 3 | 4.7s |  |
| 435 | `int_tofixed` | 1215 | 4.8s |  |
| 436 | `int_tostring` | 3375 | 5.0s |  |
| 437 | `interactiveobject_enabled` | 25 | 4.8s |  |
| 438 | `interface_namespaces` | 78 | 5.0s |  |
| 439 | `is_finite` | 46 | 4.9s |  |
| 440 | `is_nan` | 46 | 4.8s |  |
| 441 | `is_prototype_of` | 12 | 4.9s |  |
| 442 | `issue_10221` | 2 | 4.8s |  |
| 443 | `issue_13780` | 12 | 4.8s |  |
| 444 | `issue_14901` | 1 | 5.0s |  |
| 445 | `issue_17675_edittext_paste_maxchars` | 1 | 5.0s |  |
| 446 | `issue_5292` | 5 | 5.0s |  |
| 447 | `issue_8630` | 2 | 5.1s |  |
| 448 | `issue_8630_scriptremove` | 11 | 5.1s |  |
| 449 | `istype` | 24 | 5.0s |  |
| 450 | `istypelate` | 58 | 5.2s |  |
| 451 | `istypelate_coerce` | 198 | 5.5s |  |
| 452 | `json_errors` | 9 | 24.4s |  |
| 453 | `json_parse` | 21 | 4.9s |  |
| 454 | `json_version_gated` | 1 | 4.8s |  |
| 455 | `key_input_80percent` | 1812 | 5.0s |  |
| 456 | `key_input_location` | 126 | 5.0s |  |
| 457 | `key_input_numpad` | 384 | 5.0s |  |
| 458 | `lazyinit` | 17 | 4.9s |  |
| 459 | `lessequals` | 512 | 6.1s |  |
| 460 | `lessthan` | 512 | 6.1s |  |
| 461 | `loaderinfo_properties` | 18 | 4.7s |  |
| 462 | `loaderinfo_root` | 10 | 4.6s |  |
| 463 | `loaderinfo_root_allows` | 2 | 4.7s |  |
| 464 | `lshift` | 1058 | 6.9s |  |
| 465 | `mask_reapply` | 1 | 23.2s |  |
| 466 | `math` | 497 | 4.8s |  |
| 467 | `modulo` | 1058 | 6.8s |  |
| 468 | `mouse_click_events` | 90 | 23.1s |  |
| 469 | `mouse_double_click_events` | 188 | 4.7s |  |
| 470 | `mouse_empty_parent` | 4 | 4.7s |  |
| 471 | `mouse_over_while_dragging` | 3 | 4.7s |  |
| 472 | `mouse_pick_button_mode` | 2 | 4.8s |  |
| 473 | `mouse_sibling` | 8 | 4.6s |  |
| 474 | `movieclip_addframescript` | 3 | 22.6s |  |
| 475 | `movieclip_child_property` | 16 | 4.7s |  |
| 476 | `movieclip_constr` | 21 | 4.6s |  |
| 477 | `movieclip_currentlabels` | 17 | 22.3s |  |
| 478 | `movieclip_currentlabels_dupes1` | 46 | 22.5s |  |
| 479 | `movieclip_currentlabels_dupes2` | 30 | 4.6s |  |
| 480 | `movieclip_currentlabels_dupes3` | 67 | 4.6s |  |
| 481 | `movieclip_currentscene` | 12 | 22.2s |  |
| 482 | `movieclip_dispatchevent` | 430 | 4.7s |  |
| 483 | `movieclip_dispatchevent_cancel` | 102 | 4.6s |  |
| 484 | `movieclip_dispatchevent_handlerorder` | 251 | 4.6s |  |
| 485 | `movieclip_dispatchevent_selfadd` | 80 | 4.5s |  |
| 486 | `movieclip_dispatchevent_target` | 899 | 4.6s |  |
| 487 | `movieclip_displayevents` | 96 | 22.6s |  |
| 488 | `movieclip_displayevents_clickgoto` | 676 | 5.0s |  |
| 489 | `movieclip_displayevents_clickgoto2` | 2001 | 5.0s |  |
| 490 | `movieclip_displayevents_clickplay` | 575 | 4.7s |  |
| 491 | `movieclip_displayevents_clicksymbol` | 562 | 4.7s |  |
| 492 | `movieclip_displayevents_constructframegoto` | 140 | 4.9s |  |
| 493 | `movieclip_displayevents_constructframeplay` | 50 | 4.8s |  |
| 494 | `movieclip_displayevents_constructframesymbol` | 144 | 4.7s |  |
| 495 | `movieclip_displayevents_dblhandler` | 21 | 4.7s |  |
| 496 | `movieclip_displayevents_enterframegoto` | 149 | 4.8s |  |
| 497 | `movieclip_displayevents_enterframeplay` | 48 | 4.7s |  |
| 498 | `movieclip_displayevents_enterframesymbol` | 149 | 22.7s |  |
| 499 | `movieclip_displayevents_exitframegoto` | 106 | 4.7s |  |
| 500 | `movieclip_displayevents_exitframeplay` | 44 | 4.7s |  |
| 501 | `movieclip_displayevents_exitframesymbol` | 135 | 4.7s |  |
| 502 | `movieclip_displayevents_looping` | 63 | 22.6s |  |
| 503 | `movieclip_displayevents_stopped` | 113 | 5.0s |  |
| 504 | `movieclip_displayevents_swap` | 96 | 2.4s |  |
| 505 | `movieclip_displayevents_timeline` | 128 | 22.8s |  |
| 506 | `movieclip_drawrect` | 54 | 4.6s |  |
| 507 | `movieclip_frameconstruct_skipped` | 9 | 5.1s |  |
| 508 | `movieclip_goto_during_frame_script` | 15 | 5.2s |  |
| 509 | `movieclip_goto_overwrite` | 14 | 25.3s |  |
| 510 | `movieclip_goto_scene_last_frame_int` | 1 | 25.2s |  |
| 511 | `movieclip_goto_scene_last_frame_label` | 1 | 5.0s |  |
| 512 | `movieclip_gotoandplay` | 15 | 25.1s |  |
| 513 | `movieclip_gotoandstop` | 13 | 5.1s |  |
| 514 | `movieclip_gotoandstop_children` | 4 | 5.2s |  |
| 515 | `movieclip_gotoandstop_framescripts1` | 4 | 5.0s |  |
| 516 | `movieclip_gotoandstop_framescripts2` | 4 | 2.8s |  |
| 517 | `movieclip_gotoandstop_framescripts_self` | 7 | 5.1s |  |
| 518 | `movieclip_gotoandstop_queueing` | 12 | 5.0s |  |
| 519 | `movieclip_next_frame` | 2 | 5.1s |  |
| 520 | `movieclip_next_scene` | 6 | 25.3s |  |
| 521 | `movieclip_play` | 3 | 5.0s |  |
| 522 | `movieclip_prev_frame` | 3 | 4.8s |  |
| 523 | `movieclip_prev_scene` | 7 | 5.0s |  |
| 524 | `movieclip_properties` | 79 | 25.4s |  |
| 525 | `movieclip_queued_noop_goto_swf10` | 9 | 5.0s |  |
| 526 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 527 | `movieclip_scenes` | 11 | 4.9s |  |
| 528 | `movieclip_soundtransform` | 831 | 26.3s |  |
| 529 | `movieclip_stop` | 1 | 4.9s |  |
| 530 | `movieclip_super_is_symbol` | 20 | 5.3s |  |
| 531 | `movieclip_symbol_constr` | 8 | 5.1s |  |
| 532 | `movieclip_text_mousedown` | 1 | 5.1s |  |
| 533 | `movieclip_willtrigger` | 5 | 5.1s |  |
| 534 | `multiply` | 1058 | 7.3s |  |
| 535 | `namespace_constr` | 253 | 5.4s |  |
| 536 | `namespace_constr_args` | 1 | 4.9s |  |
| 537 | `namespace_enumeration_order` | 7 | 5.0s |  |
| 538 | `nan_scale` | 9 | 5.0s |  |
| 539 | `negate` | 30 | 5.0s |  |
| 540 | `negative_volume_panned` | 0 | 5.2s |  |
| 541 | `nested_iteration` | 11 | 5.0s |  |
| 542 | `net_getClassByAlias` | 3 | 5.0s |  |
| 543 | `newactivation_in_script_init` | 3 | 4.6s |  |
| 544 | `newclass_twice` | 3 | 4.6s |  |
| 545 | `nonconflicting_declarations` | 0 | 4.7s |  |
| 546 | `null_void_types` | 8 | 4.6s |  |
| 547 | `number_autoconv` | 21 | 4.7s |  |
| 548 | `number_autoconv_amf` | 132 | 4.7s |  |
| 549 | `number_autoconv_array_sort_32bit` | 1 | 4.7s |  |
| 550 | `number_constr` | 58 | 4.8s |  |
| 551 | `number_toexponential` | 378 | 4.8s |  |
| 552 | `number_toexponential2` | 35 | 4.7s |  |
| 553 | `number_tofixed` | 378 | 2.5s |  |
| 554 | `number_toprecision` | 350 | 4.7s |  |
| 555 | `obfuscated_class_names` | 3 | 4.6s |  |
| 556 | `object_enumeration` | 10 | 4.7s |  |
| 557 | `object_prototype` | 4 | 4.7s |  |
| 558 | `object_to_locale_string` | 2 | 4.7s |  |
| 559 | `object_to_string` | 2 | 4.6s |  |
| 560 | `object_value_of` | 2 | 2.4s |  |
| 561 | `op_coerce` | 54 | 4.6s |  |
| 562 | `op_coerce_x` | 54 | 4.7s |  |
| 563 | `op_escxattr` | 2 | 4.6s |  |
| 564 | `op_escxelem` | 2 | 4.7s |  |
| 565 | `op_lookupswitch` | 4 | 4.7s |  |
| 566 | `optimize_coerce` | 1 | 4.6s |  |
| 567 | `orphan_movie_complex` | 80 | 5.0s |  |
| 568 | `orphan_movie_reorder` | 111 | 23.5s |  |
| 569 | `package_namespace` | 7 | 4.8s |  |
| 570 | `param_default_value_has_zero_cpool_index` | 1 | 4.6s |  |
| 571 | `parent_early_access_child` | 16 | 4.9s |  |
| 572 | `parse_float` | 80 | 4.8s |  |
| 573 | `pixelbender_effect_BlurredFocus` | 0 | 27.4s |  |
| 574 | `pixelbender_effect_glassDisplace` | 0 | 10.7s |  |
| 575 | `pixelbender_effect_smudge` | 0 | 8.3s |  |
| 576 | `pixelbender_effect_tintype` | 0 | 7.5s |  |
| 577 | `pixelbender_effect_twirl` | 0 | 8.5s |  |
| 578 | `pixelbender_images` | 0 | 7.1s |  |
| 579 | `place_multiple` | 17 | 4.2s |  |
| 580 | `place_object_replace` | 9 | 4.2s |  |
| 581 | `place_object_replace_2` | 24 | 21.6s |  |
| 582 | `place_object_same_depth_frame` | 1 | 4.3s |  |
| 583 | `point` | 132 | 4.4s |  |
| 584 | `primitive_edge_cases` | 1 | 4.1s |  |
| 585 | `property_priority` | 22 | 4.4s |  |
| 586 | `property_priority_three_level` | 6 | 4.3s |  |
| 587 | `propertyisenumerable_namespaces` | 6 | 4.2s |  |
| 588 | `prototype_set_null` | 7 | 4.2s |  |
| 589 | `proxy_callproperty` | 24 | 4.2s |  |
| 590 | `proxy_deleteproperty` | 64 | 4.2s |  |
| 591 | `proxy_enumeration` | 34 | 4.1s |  |
| 592 | `proxy_getproperty` | 77 | 4.2s |  |
| 593 | `proxy_hasownproperty` | 8 | 4.2s |  |
| 594 | `proxy_hasproperty` | 32 | 4.2s |  |
| 595 | `proxy_serialize` | 9 | 4.1s |  |
| 596 | `proxy_setproperty` | 42 | 4.2s |  |
| 597 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.2s |  |
| 598 | `qname_constr` | 32 | 4.2s |  |
| 599 | `qname_constr_namespace` | 24 | 4.2s |  |
| 600 | `qname_enumeration` | 9 | 4.2s |  |
| 601 | `qname_indexing` | 23 | 4.4s |  |
| 602 | `qname_tostring` | 25 | 4.2s |  |
| 603 | `qname_valueof` | 29 | 4.2s |  |
| 604 | `regexp_constr` | 148 | 4.4s |  |
| 605 | `regexp_exec` | 19 | 4.2s |  |
| 606 | `regexp_extended` | 47 | 4.2s |  |
| 607 | `regexp_multiargs` | 1 | 4.1s |  |
| 608 | `regexp_test` | 27 | 4.4s |  |
| 609 | `regexp_toString` | 10 | 4.1s |  |
| 610 | `register_script_refresh` | 35 | 4.4s |  |
| 611 | `remove_child_clear_field` | 88 | 4.3s |  |
| 612 | `remove_dobj` | 3 | 4.0s |  |
| 613 | `resolve_order` | 4 | 4.1s |  |
| 614 | `rng` | 1 | 5.2s |  |
| 615 | `rootless` | 42 | 4.1s |  |
| 616 | `rshift` | 1058 | 5.8s |  |
| 617 | `sandbox_type_local_file` | 1 | 4.0s |  |
| 618 | `scene_constr` | 8 | 4.0s |  |
| 619 | `set_property_is_enumerable` | 85 | 4.3s |  |
| 620 | `shape_drawrect` | 54 | 4.0s |  |
| 621 | `shared_object_no_root` | 3 | 4.0s |  |
| 622 | `simplebutton_added_to_stage` | 45 | 21.4s |  |
| 623 | `simplebutton_childevents` | 86 | 4.5s |  |
| 624 | `simplebutton_childevents_nested` | 54 | 4.4s |  |
| 625 | `simplebutton_childevents_sprite` | 13 | 4.2s |  |
| 626 | `simplebutton_childprops` | 144 | 4.3s |  |
| 627 | `simplebutton_childshuffle` | 23 | 4.3s |  |
| 628 | `simplebutton_constr` | 36 | 4.5s |  |
| 629 | `simplebutton_constr_childevents` | 48 | 4.7s |  |
| 630 | `simplebutton_constr_params` | 42 | 4.2s |  |
| 631 | `simplebutton_mouseenabled` | 26 | 4.0s |  |
| 632 | `simplebutton_multi_children` | 19 | 4.3s |  |
| 633 | `simplebutton_structure` | 27 | 4.2s |  |
| 634 | `simplebutton_symbolclass` | 68 | 4.3s |  |
| 635 | `slot_disp_id_shared_numbering` | 1 | 23.5s |  |
| 636 | `slots_force_autoassigned` | 1 | 4.4s |  |
| 637 | `sound_embeddedprops` | 26 | 4.5s |  |
| 638 | `sound_play` | 19 | 4.6s |  |
| 639 | `sound_valueof` | 33 | 4.4s |  |
| 640 | `soundchannel_soundtransform` | 835 | 24.1s |  |
| 641 | `soundchannel_soundtransform_exists` | 5 | 23.1s |  |
| 642 | `soundchannel_stop` | 8 | 4.6s |  |
| 643 | `soundmixer_buffertime` | 5 | 4.5s |  |
| 644 | `soundmixer_stopall` | 6 | 4.5s |  |
| 645 | `soundtransform` | 442 | 5.4s |  |
| 646 | `sprite_with_frames` | 0 | 4.9s |  |
| 647 | `stage3d_agal_cross_product` | 0 | 6.0s |  |
| 648 | `stage3d_bitmap` | 0 | 26.8s |  |
| 649 | `stage3d_float1_index` | 0 | 24.6s |  |
| 650 | `stage3d_fractal` | 0 | 7.3s |  |
| 651 | `stage3d_ignore_sampler_override` | 0 | 24.7s |  |
| 652 | `stage3d_program_constants_bytearray_be` | 0 | 24.7s |  |
| 653 | `stage3d_program_constants_bytearray_le` | 0 | 6.6s |  |
| 654 | `stage3d_raytrace` | 0 | 23.8s |  |
| 655 | `stage3d_rotating_cube` | 0 | 6.9s |  |
| 656 | `stage3d_sampler` | 0 | 6.2s |  |
| 657 | `stage3d_sampler_partial_upload` | 0 | 6.3s |  |
| 658 | `stage3d_stencil` | 0 | 25.1s |  |
| 659 | `stage3d_texture` | 0 | 10.4s |  |
| 660 | `stage3d_texture_bytearray` | 0 | 7.4s |  |
| 661 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 6.9s |  |
| 662 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 8.1s |  |
| 663 | `stage3d_triangle` | 0 | 6.2s |  |
| 664 | `stage3d_triangle_bytes4` | 0 | 6.3s |  |
| 665 | `stage3d_triangle_float1` | 0 | 6.3s |  |
| 666 | `stage3d_triangle_index_upload` | 0 | 6.3s |  |
| 667 | `stage_access` | 10 | 4.7s |  |
| 668 | `stage_displayobject_properties` | 24 | 4.6s |  |
| 669 | `stage_framerate_nan` | 7 | 4.8s |  |
| 670 | `stage_framerate_negative` | 6 | 4.6s |  |
| 671 | `stage_framerate_zero` | 6 | 4.6s |  |
| 672 | `stage_invalidate` | 38 | 4.8s |  |
| 673 | `stage_mousechildren` | 2 | 4.6s |  |
| 674 | `stage_mouseenabled` | 15 | 4.5s |  |
| 675 | `stage_overriden_setters` | 31 | 4.7s |  |
| 676 | `stage_properties` | 30 | 4.6s |  |
| 677 | `static_var_with_this_in_ctor` | 2 | 4.6s |  |
| 678 | `stored_properties` | 11 | 4.2s |  |
| 679 | `strict_equality` | 34 | 3.0s |  |
| 680 | `string_call` | 13 | 3.0s |  |
| 681 | `string_case` | 23 | 3.0s |  |
| 682 | `string_char_at` | 27 | 3.0s |  |
| 683 | `string_char_code_at` | 28 | 3.0s |  |
| 684 | `string_concat_fromcharcode` | 36 | 3.0s |  |
| 685 | `string_constr` | 25 | 3.0s |  |
| 686 | `string_indexof_lastindexof` | 87 | 3.0s |  |
| 687 | `string_length` | 16 | 3.0s |  |
| 688 | `string_locale_compare` | 39 | 3.0s |  |
| 689 | `string_match` | 51 | 3.0s |  |
| 690 | `string_relational_compare` | 4 | 3.0s |  |
| 691 | `string_replace` | 51 | 3.0s |  |
| 692 | `string_search` | 41 | 3.0s |  |
| 693 | `string_slice_substr_substring` | 169 | 3.0s |  |
| 694 | `string_split` | 29 | 3.0s |  |
| 695 | `string_substr_negative` | 21 | 3.0s |  |
| 696 | `string_substr_weird` | 182 | 3.0s |  |
| 697 | `subtract` | 1058 | 3.0s |  |
| 698 | `super_get_call` | 12 | 3.0s |  |
| 699 | `supercall_two_classobjects` | 2 | 3.0s |  |
| 700 | `swf8` | 1 | 3.0s |  |
| 701 | `swf_10_queued_goto_scripts_construct` | 52 | 3.0s |  |
| 702 | `swf_9_goto_in_enter_frame` | 17 | 3.0s |  |
| 703 | `swf_9_goto_in_enter_frame_simple` | 15 | 3.0s |  |
| 704 | `swf_9_queued_goto_scripts` | 6 | 3.0s |  |
| 705 | `swf_9_queued_goto_scripts_construct` | 28 | 0.8s |  |
| 706 | `swf_9_versioning` | 2 | 3.0s |  |
| 707 | `swf_wrong_frame_count` | 38 | 3.0s |  |
| 708 | `swf_wrong_frame_count_isplaying` | 22 | 5.1s |  |
| 709 | `symbol_class_conflict` | 4 | 5.7s |  |
| 710 | `symbol_class_root_not_zero` | 1 | 5.0s |  |
| 711 | `symbolclass_invalid_utf8` | 2 | 5.1s |  |
| 712 | `tab_ordering_automatic_advanced` | 184 | 5.5s |  |
| 713 | `tab_ordering_automatic_basic` | 45 | 5.1s |  |
| 714 | `tab_ordering_children` | 116 | 5.1s |  |
| 715 | `tab_ordering_custom_basic` | 34 | 5.0s |  |
| 716 | `text_engine_fontdescription` | 27 | 5.1s |  |
| 717 | `text_run` | 7 | 5.0s |  |
| 718 | `textfield_focusin_event` | 9 | 5.0s |  |
| 719 | `textfield_input_dead_keys_windows` | 15 | 5.1s |  |
| 720 | `textfield_unload` | 39 | 3.1s |  |
| 721 | `textformat` | 1134 | 5.0s |  |
| 722 | `textformat_display` | 14 | 5.0s |  |
| 723 | `textformat_font_max_length` | 4 | 5.0s |  |
| 724 | `throw` | 3 | 5.0s |  |
| 725 | `timeline_scripts` | 3 | 5.0s |  |
| 726 | `timer` | 90 | 5.5s |  |
| 727 | `timer_events` | 3 | 4.8s |  |
| 728 | `timer_finished` | 11 | 4.8s |  |
| 729 | `timer_reset` | 8 | 4.7s |  |
| 730 | `timer_setdelay` | 5 | 4.6s |  |
| 731 | `trace` | 12 | 4.6s |  |
| 732 | `truthiness` | 30 | 4.6s |  |
| 733 | `try_catch` | 11 | 4.7s |  |
| 734 | `try_catch_typed` | 12 | 4.7s |  |
| 735 | `typeof` | 30 | 4.7s |  |
| 736 | `uint_constr` | 92 | 4.7s |  |
| 737 | `uint_tofixed` | 1215 | 4.5s |  |
| 738 | `uint_tostring` | 3375 | 4.8s |  |
| 739 | `uncaught_errors_stringified` | 3 | 4.7s |  |
| 740 | `unchecked_function` | 15 | 4.6s |  |
| 741 | `urlrequest` | 18 | 4.6s |  |
| 742 | `urshift` | 1058 | 6.6s |  |
| 743 | `vector_class` | 36 | 5.0s |  |
| 744 | `vector_class_call` | 11 | 4.8s |  |
| 745 | `vector_coercion` | 66 | 5.2s |  |
| 746 | `vector_concat` | 90 | 4.9s |  |
| 747 | `vector_constr` | 107 | 4.8s |  |
| 748 | `vector_enumeration` | 5 | 4.6s |  |
| 749 | `vector_every` | 92 | 5.0s |  |
| 750 | `vector_filter` | 95 | 5.0s |  |
| 751 | `vector_holes` | 24 | 4.7s |  |
| 752 | `vector_indexof` | 302 | 5.5s |  |
| 753 | `vector_insertat` | 270 | 5.0s |  |
| 754 | `vector_int_access` | 4 | 4.6s |  |
| 755 | `vector_int_delete` | 11 | 4.6s |  |
| 756 | `vector_join` | 58 | 4.8s |  |
| 757 | `vector_lastindexof` | 302 | 4.6s |  |
| 758 | `vector_legacy` | 10 | 4.6s |  |
| 759 | `vector_map` | 85 | 3.1s |  |
| 760 | `vector_object_final` | 1 | 3.1s |  |
| 761 | `vector_object_toString` | 10 | 3.1s |  |
| 762 | `vector_pushpop` | 255 | 3.0s |  |
| 763 | `vector_reborrow_bug` | 10 | 2.9s |  |
| 764 | `vector_removeat` | 172 | 2.9s |  |
| 765 | `vector_reverse` | 232 | 3.0s |  |
| 766 | `vector_shiftunshift` | 252 | 2.9s |  |
| 767 | `vector_slice` | 331 | 3.0s |  |
| 768 | `vector_sort` | 905 | 3.0s |  |
| 769 | `vector_splice` | 693 | 3.0s |  |
| 770 | `vector_splice_fixed_bug_compat` | 4 | 2.9s |  |
| 771 | `vector_tostring` | 79 | 3.0s |  |
| 772 | `verify_abnormal_loop` | 1 | 2.9s |  |
| 773 | `verify_exception_targets_edge_case` | 1 | 2.9s |  |
| 774 | `verify_lookup_switch_edge_case` | 1 | 2.9s |  |
| 775 | `verify_unreachable_exception` | 2 | 2.9s |  |
| 776 | `versioned_isplaying` | 2 | 2.9s |  |
| 777 | `virtual_properties` | 16 | 0.8s |  |
| 778 | `with` | 4 | 2.9s |  |
| 779 | `xml_abstract_equality` | 36 | 2.9s |  |
| 780 | `xml_advanced` | 52 | 2.9s |  |
| 781 | `xml_appendchild` | 10 | 3.0s |  |
| 782 | `xml_as_attribute` | 9 | 2.9s |  |
| 783 | `xml_attribute` | 35 | 3.0s |  |
| 784 | `xml_attribute_name` | 40 | 2.9s |  |
| 785 | `xml_basic` | 32 | 2.9s |  |
| 786 | `xml_child` | 25 | 2.9s |  |
| 787 | `xml_childindex` | 7 | 0.8s |  |
| 788 | `xml_children` | 43 | 3.0s |  |
| 789 | `xml_class_call` | 9 | 3.0s |  |
| 790 | `xml_contains` | 197 | 4.8s |  |
| 791 | `xml_copy` | 20 | 4.5s |  |
| 792 | `xml_ctor_from_tostring` | 23 | 4.4s |  |
| 793 | `xml_delete` | 114 | 4.3s |  |
| 794 | `xml_descendants` | 83 | 4.4s |  |
| 795 | `xml_elements` | 6 | 4.3s |  |
| 796 | `xml_equals_namespace_check` | 2 | 4.4s |  |
| 797 | `xml_explicit_use_namespace` | 5 | 4.3s |  |
| 798 | `xml_getdescendants_qname` | 21 | 4.4s |  |
| 799 | `xml_has_property_via_in` | 26 | 4.3s |  |
| 800 | `xml_hasownproperty` | 6 | 4.3s |  |
| 801 | `xml_ignore_white` | 6 | 4.3s |  |
| 802 | `xml_length` | 2 | 4.3s |  |
| 803 | `xml_list_as_attribute` | 9 | 4.3s |  |
| 804 | `xml_list_concat` | 20 | 4.3s |  |
| 805 | `xml_list_enumerate` | 4 | 4.3s |  |
| 806 | `xml_methods_settings` | 3 | 4.3s |  |
| 807 | `xml_mismatched_tag` | 37 | 4.3s |  |
| 808 | `xml_namespace` | 39 | 4.3s |  |
| 809 | `xml_namespace_methods` | 245 | 4.3s |  |
| 810 | `xml_namespaced_property` | 7 | 4.3s |  |
| 811 | `xml_no_namespace` | 1 | 4.3s |  |
| 812 | `xml_nodekind` | 3 | 4.4s |  |
| 813 | `xml_normalize` | 35 | 4.4s |  |
| 814 | `xml_notification_bubbling` | 361 | 4.3s |  |
| 815 | `xml_parent` | 8 | 4.4s |  |
| 816 | `xml_set_children` | 17 | 4.4s |  |
| 817 | `xml_set_name` | 34 | 4.4s |  |
| 818 | `xml_settings` | 6 | 2.3s |  |
| 819 | `xml_simple_complex_content` | 47 | 4.4s |  |
| 820 | `xml_text` | 7 | 4.4s |  |
| 821 | `xml_tostring` | 6 | 4.3s |  |
| 822 | `xml_tostring_namespace` | 12 | 4.3s |  |
| 823 | `xml_unescaping` | 23 | 4.3s |  |
| 824 | `xml_weird_ignores` | 54 | 4.3s |  |
| 825 | `xml_wildcard` | 11 | 4.4s |  |
| 826 | `xmldocument` | 254 | 4.4s |  |
| 827 | `xmlnode` | 3540 | 4.5s |  |
| 828 | `zero_frame_clip` | 3 | 4.4s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 1 | 5.0s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 5.8s |  |
| 3 | `blend_transform` | 1 | 1 | 5.4s |  |
| 4 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 3.1s |  |
| 5 | `dictionary_weak_keys` | 1 | 1 | 23.6s |  |
| 6 | `edittext_getcharboundaries_culling` | 300 | 300 | 4.0s |  |
| 7 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 3.8s |  |
| 8 | `edittext_tab_stops` | 6 | 6 | 5.2s |  |
| 9 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 4.9s |  |
| 10 | `error_1034_debug_string` | 19 | 19 | 5.0s |  |
| 11 | `freestanding_superclass` | 3 | 4 | 4.4s |  |
| 12 | `goto_framescript_queued` | 5 | 5 | 4.8s |  |
| 13 | `int_toexponential` | 76 | 76 | 4.9s |  |
| 14 | `int_toprecision` | 441 | 441 | 5.0s |  |
| 15 | `simplebutton_childevents_script_order` | 4 | 4 | 4.4s |  |
| 16 | `slot_holes_fail` | 1 | 1 | 4.3s |  |
| 17 | `slot_id_exceeds_trait_count` | 1 | 1 | 4.4s |  |
| 18 | `soundchannel_position` | 74 | 74 | 23.6s |  |
| 19 | `soundchannel_soundcomplete` | 10 | 10 | 4.6s |  |
| 20 | `sprite_dropTarget` | 4 | 4 | 4.5s |  |
| 21 | `swf_9_goto_in_construct_frame` | 12 | 12 | 3.0s |  |
| 22 | `uint_toexponential` | 100 | 100 | 4.7s |  |
| 23 | `uint_toprecision` | 433 | 433 | 4.8s |  |
| 24 | `weird_superinterface_properties` | 1 | 1 | 2.9s |  |

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
| 24 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 25 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 26 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 27 | `matrix` | 83.1% | 281 | 338 | 57 |  |
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
| 1 | `domain_memory` | exit code 1 | 4.7s |  |
| 2 | `method_without_body` | exit code 1 | 23.0s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 4.1s |  |
| 4 | `verify_typecheck` | exit code 1 | 2.8s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 34.5s |  |

## All Output Mismatches

**347 tests** with output mismatch, sorted by match rate (best first)

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
| 27 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
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
| 83 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 84 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 85 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 86 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 87 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 88 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 89 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
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
| 106 | `focus_events_key_basic` | 11.6% | 17/147 | 147 | 132 |  |
| 107 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 108 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
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
| 138 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 139 | `loader_load` | 2.4% | 3/126 | 11 | 126 |  |
| 140 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 141 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 142 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 143 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 144 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 145 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 146 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 147 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 148 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 149 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 150 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 151 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 152 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 153 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 154 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 155 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 156 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 157 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 158 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 159 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 160 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 161 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 162 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 163 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 164 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 165 | `all_classes/display/swf9` | 0.1% | 1/1959 | 198 | 1959 |  |
| 166 | `all_classes/display/swf10` | 0.0% | 1/2569 | 198 | 2569 |  |
| 167 | `all_classes/display/swf11` | 0.0% | 1/2593 | 198 | 2593 |  |
| 168 | `all_classes/display/swf12` | 0.0% | 1/2593 | 198 | 2593 |  |
| 169 | `all_classes/display/swf13` | 0.0% | 1/2671 | 198 | 2671 |  |
| 170 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 171 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 172 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 173 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 174 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 175 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 176 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 177 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 178 | `all_classes/display/swf30` | 0.0% | 0/2936 | 198 | 2936 |  |
| 179 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 180 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 181 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 182 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 183 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 184 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 185 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 186 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 187 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 188 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 189 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 190 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 191 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 192 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 193 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 194 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 195 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 196 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 197 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 198 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 199 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 200 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 201 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 202 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 203 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 204 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 205 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 206 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 207 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 208 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 209 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 210 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 211 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 212 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 213 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 214 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 215 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 216 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 217 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 218 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 219 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 220 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 221 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 222 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 223 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 224 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 225 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 226 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 227 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 228 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 229 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 230 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 231 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 232 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 233 | `graphics_draw_path` | 0.0% | 0/101 | 0 | 101 |  |
| 234 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 235 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 236 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 237 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 238 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 239 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 240 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 241 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 242 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 243 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 244 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 245 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 246 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 247 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 248 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 249 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 250 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 251 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 252 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 253 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 254 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 255 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 256 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 257 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 258 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 259 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 260 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 261 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 262 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 263 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 264 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 265 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 266 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 267 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 268 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 269 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 270 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 271 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 272 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 273 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 274 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 275 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 276 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 277 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 278 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 279 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 280 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 281 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 282 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 283 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 284 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 285 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 286 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 287 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 288 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 289 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 290 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 291 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 292 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 293 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 294 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 295 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 296 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 297 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 298 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 299 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 300 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 301 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
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
| 342 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 343 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 344 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 345 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 346 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 347 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
