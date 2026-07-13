# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-13 01:03 UTC

**Git SHA**: `bf93755e0c`

**Run Duration**: 80m 58s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1204 |
| Passing | **801** (66.5%) |
| Ruffle-matched | 22 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **823** (68.4%) |
| Failing | 381 |
| Total expected lines | 149868 |
| Matching lines | 97905 (65.3%) |
| Mismatched lines | 51963 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 376 | 98.7% |
| Runtime Error | 4 | 1.0% |
| Timeout | 1 | 0.3% |

## Passing Tests

**801 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 0.4s |  |
| 2 | `air_hidden_lookup` | 2 | 0.3s |  |
| 3 | `all_classes/security/swf11` | 3 | 0.3s |  |
| 4 | `amf_custom_obj` | 26 | 0.3s |  |
| 5 | `amf_dictionary` | 9 | 0.3s |  |
| 6 | `amf_function` | 46 | 0.3s |  |
| 7 | `amf_invalid_date` | 2 | 0.3s |  |
| 8 | `amf_missing_prop` | 6 | 0.3s |  |
| 9 | `amf_nondynamic_function_prop` | 6 | 1.8s |  |
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
| 22 | `array_every` | 8 | 1.9s |  |
| 23 | `array_filter` | 6 | 1.9s |  |
| 24 | `array_foreach` | 18 | 1.8s |  |
| 25 | `array_hasownproperty` | 11 | 1.9s |  |
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
| 36 | `array_reborrow_bug` | 6 | 1.8s |  |
| 37 | `array_reverse` | 28 | 1.9s |  |
| 38 | `array_shift` | 51 | 1.9s |  |
| 39 | `array_slice` | 39 | 1.9s |  |
| 40 | `array_some` | 8 | 1.9s |  |
| 41 | `array_sort` | 297 | 2.1s |  |
| 42 | `array_sort_fun_swf12` | 2 | 1.8s |  |
| 43 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 44 | `array_sort_random` | 210 | 1.9s |  |
| 45 | `array_sort_swf10_32bit` | 1 | 1.9s |  |
| 46 | `array_sorton` | 545 | 1.6s |  |
| 47 | `array_sparse_ops` | 41 | 1.3s |  |
| 48 | `array_splice` | 133 | 1.3s |  |
| 49 | `array_splice2` | 428 | 1.4s |  |
| 50 | `array_splice_types` | 48 | 1.3s |  |
| 51 | `array_storage` | 8 | 1.3s |  |
| 52 | `array_tolocalestring` | 9 | 1.2s |  |
| 53 | `array_tostring` | 12 | 1.2s |  |
| 54 | `array_unshift` | 24 | 1.2s |  |
| 55 | `array_valueof` | 9 | 1.1s |  |
| 56 | `array_vector_null_callback` | 10 | 1.1s |  |
| 57 | `astype` | 28 | 1.2s |  |
| 58 | `astypelate` | 24 | 1.2s |  |
| 59 | `astypelate_propagates` | 1 | 1.1s |  |
| 60 | `asymmetric_key_events` | 11 | 1.2s |  |
| 61 | `avm2_catchup_dobj` | 158 | 1.4s |  |
| 62 | `away3d_advanced_shallow_water_demo` | 0 | 38.1s |  |
| 63 | `bitand` | 1058 | 2.4s |  |
| 64 | `bitmap_constr` | 17 | 1.3s |  |
| 65 | `bitmap_data` | 1000 | 4.0s |  |
| 66 | `bitmap_properties` | 23 | 1.2s |  |
| 67 | `bitmap_timeline` | 9 | 1.2s |  |
| 68 | `bitmapdata_accuracy` | 1 | 25.6s |  |
| 69 | `bitmapdata_applyfilter_blur` | 0 | 12.4s |  |
| 70 | `bitmapdata_applyfilter_colormatrix` | 0 | 1.3s |  |
| 71 | `bitmapdata_applyfilter_destpoint` | 0 | 12.7s |  |
| 72 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 12.7s |  |
| 73 | `bitmapdata_clone` | 13 | 1.3s |  |
| 74 | `bitmapdata_colortransform` | 0 | 1.3s |  |
| 75 | `bitmapdata_colortransform_oob` | 2 | 1.2s |  |
| 76 | `bitmapdata_constr` | 22 | 1.2s |  |
| 77 | `bitmapdata_constructor_from_timeline` | 1 | 1.3s |  |
| 78 | `bitmapdata_copychannel` | 0 | 23.0s |  |
| 79 | `bitmapdata_copypixels` | 23 | 20.0s |  |
| 80 | `bitmapdata_copypixels_blend_over` | 1 | 2.0s |  |
| 81 | `bitmapdata_copypixelstobytearray` | 39 | 1.8s |  |
| 82 | `bitmapdata_dispose` | 7 | 1.8s |  |
| 83 | `bitmapdata_draw` | 0 | 19.9s |  |
| 84 | `bitmapdata_draw_colortransform` | 0 | 1.9s |  |
| 85 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 20.2s |  |
| 86 | `bitmapdata_draw_filters` | 0 | 19.8s |  |
| 87 | `bitmapdata_draw_masks` | 0 | 1.8s |  |
| 88 | `bitmapdata_draw_rotation` | 0 | 1.8s |  |
| 89 | `bitmapdata_draw_self_via_graphic` | 0 | 1.8s |  |
| 90 | `bitmapdata_draw_stage` | 0 | 19.7s |  |
| 91 | `bitmapdata_drawwithquality` | 0 | 2.0s |  |
| 92 | `bitmapdata_embedded` | 9 | 2.0s |  |
| 93 | `bitmapdata_fillrect` | 0 | 1.8s |  |
| 94 | `bitmapdata_filter_sourcerect` | 0 | 19.9s |  |
| 95 | `bitmapdata_floodfill` | 35 | 1.8s |  |
| 96 | `bitmapdata_getpixels` | 39 | 19.8s |  |
| 97 | `bitmapdata_getvector` | 27 | 1.8s |  |
| 98 | `bitmapdata_histogram` | 59 | 1.9s |  |
| 99 | `bitmapdata_hittest` | 112 | 2.3s |  |
| 100 | `bitmapdata_hittest_threshold` | 18 | 1.9s |  |
| 101 | `bitmapdata_opaque` | 0 | 1.9s |  |
| 102 | `bitmapdata_pixeldissolve` | 1037 | 2.2s |  |
| 103 | `bitmapdata_pixeldissolve_image` | 0 | 2.0s |  |
| 104 | `bitmapdata_rectangle_rounding` | 16 | 1.8s |  |
| 105 | `bitmapdata_setpixels` | 286 | 1.9s |  |
| 106 | `bitmapdata_setvector` | 26 | 1.3s |  |
| 107 | `bitmapdata_sync` | 0 | 1.9s |  |
| 108 | `bitmapdata_threshold` | 176 | 2.4s |  |
| 109 | `bitmapdata_zero_size` | 5 | 1.7s |  |
| 110 | `bitnot` | 46 | 1.8s |  |
| 111 | `bitor` | 1058 | 3.9s |  |
| 112 | `bitxor` | 1058 | 3.9s |  |
| 113 | `blend_multiply_alpha` | 0 | 1.8s |  |
| 114 | `blend_scroll` | 0 | 1.8s |  |
| 115 | `boolean_constr` | 32 | 1.9s |  |
| 116 | `boolean_negation` | 30 | 1.9s |  |
| 117 | `boolean_tostring` | 8 | 1.9s |  |
| 118 | `broadcast_event` | 7 | 1.7s |  |
| 119 | `button_nested_frame` | 48 | 20.6s |  |
| 120 | `bytearray` | 48 | 2.0s |  |
| 121 | `bytearray_compress` | 31 | 1.8s |  |
| 122 | `bytearray_errors` | 24 | 1.9s |  |
| 123 | `bytearray_method_serialization` | 1 | 1.8s |  |
| 124 | `bytearray_readobject_amf0` | 50 | 0.8s |  |
| 125 | `bytearray_readobject_amf3` | 53 | 1.8s |  |
| 126 | `bytearray_readutf8bytes_with_bom` | 16 | 1.8s |  |
| 127 | `bytearray_serialization` | 3 | 1.8s |  |
| 128 | `bytearray_string_null` | 19 | 2.0s |  |
| 129 | `bytearray_tostring` | 15 | 1.8s |  |
| 130 | `bytearray_utf16` | 8 | 1.8s |  |
| 131 | `bytearray_writeobject` | 24 | 0.6s |  |
| 132 | `callee_in_initializer` | 6 | 1.7s |  |
| 133 | `callproplex_class` | 1 | 1.8s |  |
| 134 | `catch_class` | 6 | 1.8s |  |
| 135 | `catch_scope_slot` | 7 | 1.8s |  |
| 136 | `checkfilter` | 4 | 1.8s |  |
| 137 | `class_call` | 32 | 1.8s |  |
| 138 | `class_cast_call` | 14 | 1.8s |  |
| 139 | `class_enumeration` | 4 | 1.9s |  |
| 140 | `class_has_own_property` | 2 | 1.8s |  |
| 141 | `class_init_interpreter_mode` | 1 | 1.7s |  |
| 142 | `class_is` | 32 | 1.8s |  |
| 143 | `class_methods` | 5 | 1.8s |  |
| 144 | `class_object_properties` | 10 | 1.9s |  |
| 145 | `class_singleton` | 18 | 1.9s |  |
| 146 | `class_supercalls_errors` | 35 | 2.0s |  |
| 147 | `class_supercalls_mismatched` | 26 | 2.7s |  |
| 148 | `class_superclass_wrong_order` | 1 | 1.7s |  |
| 149 | `class_to_locale_string` | 2 | 1.8s |  |
| 150 | `class_to_string` | 2 | 1.7s |  |
| 151 | `class_value_of` | 2 | 1.8s |  |
| 152 | `click_block` | 5 | 20.2s |  |
| 153 | `click_invisible` | 3 | 1.9s |  |
| 154 | `closures` | 12 | 1.8s |  |
| 155 | `coerce_property` | 33 | 1.9s |  |
| 156 | `coerce_return_type` | 40 | 1.9s |  |
| 157 | `coerce_return_type_fail` | 2 | 1.7s |  |
| 158 | `coerce_return_void` | 3 | 1.7s |  |
| 159 | `coerce_string` | 86 | 1.9s |  |
| 160 | `coerce_string_precision` | 28 | 1.8s |  |
| 161 | `coerce_to_primitive_side_effects` | 29 | 1.9s |  |
| 162 | `construct_errors_swf10` | 8 | 1.8s |  |
| 163 | `construct_frame_list` | 22 | 20.2s |  |
| 164 | `constructor_call` | 3 | 1.8s |  |
| 165 | `constructors_vs_timeline` | 5 | 20.1s |  |
| 166 | `constructprop_dynamic_primitive` | 7 | 1.8s |  |
| 167 | `control_flow_bool` | 4 | 1.8s |  |
| 168 | `control_flow_stricteq` | 8 | 1.8s |  |
| 169 | `convert_boolean` | 30 | 1.8s |  |
| 170 | `convert_integer` | 90 | 1.9s |  |
| 171 | `convert_number` | 56 | 1.8s |  |
| 172 | `convert_uinteger` | 90 | 1.9s |  |
| 173 | `cryptscore` | 11 | 2.8s |  |
| 174 | `declocal` | 46 | 1.9s |  |
| 175 | `declocal_i` | 46 | 1.9s |  |
| 176 | `decrement` | 46 | 1.9s |  |
| 177 | `decrement_i` | 46 | 1.9s |  |
| 178 | `default_values` | 7 | 1.8s |  |
| 179 | `dictionary_access` | 62 | 2.0s |  |
| 180 | `dictionary_access_no_pubns` | 2 | 1.8s |  |
| 181 | `dictionary_delete` | 101 | 2.1s |  |
| 182 | `dictionary_foreach` | 42 | 2.0s |  |
| 183 | `dictionary_hasownproperty` | 63 | 2.0s |  |
| 184 | `dictionary_in` | 62 | 2.0s |  |
| 185 | `dictionary_iter_modify` | 8 | 1.9s |  |
| 186 | `dictionary_namespaces` | 36 | 2.0s |  |
| 187 | `dictionary_primitive_keys` | 29 | 1.9s |  |
| 188 | `displayobject_alpha` | 277 | 1.8s |  |
| 189 | `displayobject_blendmode` | 0 | 20.3s |  |
| 190 | `displayobject_colortransform_nested` | 0 | 20.5s |  |
| 191 | `displayobject_from_enterframe` | 1 | 20.3s |  |
| 192 | `displayobject_getbounds_shape` | 0 | 20.3s |  |
| 193 | `displayobject_height` | 6052 | 20.3s |  |
| 194 | `displayobject_hittestobject` | 32 | 1.9s |  |
| 195 | `displayobject_invalid_floats` | 60 | 1.9s |  |
| 196 | `displayobject_invalid_props` | 3 | 2.6s |  |
| 197 | `displayobject_mask` | 3 | 1.8s |  |
| 198 | `displayobject_mask_self_referential` | 0 | 1.7s |  |
| 199 | `displayobject_metaData` | 3 | 1.8s |  |
| 200 | `displayobject_name` | 22 | 20.0s |  |
| 201 | `displayobject_name_from_timeline` | 24 | 1.9s |  |
| 202 | `displayobject_parent` | 12 | 1.8s |  |
| 203 | `displayobject_root` | 24 | 1.8s |  |
| 204 | `displayobject_rotation` | 1275 | 1.8s |  |
| 205 | `displayobject_set_matrix_nested` | 0 | 20.2s |  |
| 206 | `displayobject_subclass` | 2 | 1.8s |  |
| 207 | `displayobject_visible` | 23 | 1.7s |  |
| 208 | `displayobject_width` | 4852 | 19.7s |  |
| 209 | `displayobject_x` | 614 | 1.5s |  |
| 210 | `displayobject_y` | 617 | 1.7s |  |
| 211 | `displayobjectcontainer_addchild` | 32 | 1.8s |  |
| 212 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 1.7s |  |
| 213 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 1.9s |  |
| 214 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 1.8s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 1.8s |  |
| 216 | `displayobjectcontainer_addchildat` | 42 | 1.8s |  |
| 217 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 1.8s |  |
| 218 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 1.8s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 1.8s |  |
| 220 | `displayobjectcontainer_contains` | 66 | 2.0s |  |
| 221 | `displayobjectcontainer_getchildat` | 4 | 1.8s |  |
| 222 | `displayobjectcontainer_getchildbyname` | 9 | 1.7s |  |
| 223 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 1.7s |  |
| 224 | `displayobjectcontainer_getchildindex` | 28 | 1.7s |  |
| 225 | `displayobjectcontainer_removechild` | 10 | 1.7s |  |
| 226 | `displayobjectcontainer_removechild_errors` | 4 | 1.7s |  |
| 227 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 1.7s |  |
| 228 | `displayobjectcontainer_removechildat` | 18 | 1.7s |  |
| 229 | `displayobjectcontainer_removechildren` | 51 | 1.9s |  |
| 230 | `displayobjectcontainer_setchildindex` | 42 | 1.6s |  |
| 231 | `displayobjectcontainer_stopallmovieclips` | 2 | 2.8s |  |
| 232 | `displayobjectcontainer_swapchildren` | 42 | 1.9s |  |
| 233 | `displayobjectcontainer_swapchildrenat` | 42 | 1.8s |  |
| 234 | `displayobjectcontainer_timelineinstance` | 48 | 19.7s |  |
| 235 | `divide` | 1058 | 3.8s |  |
| 236 | `doabc_is_eager` | 1 | 19.3s |  |
| 237 | `documentclass` | 9 | 1.9s |  |
| 238 | `drag_drop` | 10 | 1.9s |  |
| 239 | `duplicate_defs` | 1 | 0.5s |  |
| 240 | `eager_init` | 1 | 1.8s |  |
| 241 | `edit_text_linkage` | 7 | 1.9s |  |
| 242 | `edittext_align` | 60 | 2.0s |  |
| 243 | `edittext_always_show_selection` | 0 | 20.2s |  |
| 244 | `edittext_antialiastype` | 296 | 1.9s |  |
| 245 | `edittext_at_point_methods_basic` | 16 | 3.0s |  |
| 246 | `edittext_autosize` | 39 | 2.0s |  |
| 247 | `edittext_autosize_align` | 0 | 20.1s |  |
| 248 | `edittext_autosize_height_dynamic` | 60 | 20.0s |  |
| 249 | `edittext_autosize_height_input` | 60 | 1.9s |  |
| 250 | `edittext_autosize_lazy_bounds_events` | 65 | 2.0s |  |
| 251 | `edittext_autosize_lazy_bounds_interactions` | 19 | 1.8s |  |
| 252 | `edittext_autosize_lazy_bounds_props` | 490 | 3.0s |  |
| 253 | `edittext_autosize_lazy_bounds_visual` | 0 | 20.0s |  |
| 254 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 2.0s |  |
| 255 | `edittext_bottom_scroll_v_basic` | 210 | 1.9s |  |
| 256 | `edittext_bounds_scale` | 24 | 19.6s |  |
| 257 | `edittext_bullet` | 30 | 1.8s |  |
| 258 | `edittext_default_format` | 221 | 2.0s |  |
| 259 | `edittext_default_format_empty` | 136 | 2.0s |  |
| 260 | `edittext_empty_text_format` | 7 | 1.8s |  |
| 261 | `edittext_focus_selection` | 5 | 1.8s |  |
| 262 | `edittext_font_size` | 45 | 1.8s |  |
| 263 | `edittext_format_empty_font` | 8 | 1.8s |  |
| 264 | `edittext_get_char_index_at_point` | 4 | 20.6s |  |
| 265 | `edittext_get_line_index_at_point` | 2 | 21.7s |  |
| 266 | `edittext_get_line_index_of_char` | 76 | 3.0s |  |
| 267 | `edittext_getcharboundaries` | 172 | 2.2s |  |
| 268 | `edittext_getcharboundaries_missing_glyphs` | 63 | 2.0s |  |
| 269 | `edittext_getcharboundaries_scroll` | 85 | 2.0s |  |
| 270 | `edittext_getlinemetrics` | 146 | 2.1s |  |
| 271 | `edittext_html` | 3101 | 2.3s |  |
| 272 | `edittext_html_condensewhite` | 487 | 2.0s |  |
| 273 | `edittext_html_entity` | 4 | 2.1s |  |
| 274 | `edittext_html_font_size_swf12` | 267 | 2.0s |  |
| 275 | `edittext_html_font_size_swf13` | 273 | 0.5s |  |
| 276 | `edittext_html_roundtrip` | 17 | 1.9s |  |
| 277 | `edittext_input_control` | 12 | 1.9s |  |
| 278 | `edittext_leading` | 9 | 2.0s |  |
| 279 | `edittext_letter_spacing` | 15 | 1.8s |  |
| 280 | `edittext_line_methods` | 294 | 2.9s |  |
| 281 | `edittext_line_metrics` | 11 | 21.6s |  |
| 282 | `edittext_margins` | 25 | 1.8s |  |
| 283 | `edittext_max_scroll_h_basic` | 475 | 2.0s |  |
| 284 | `edittext_max_scroll_v_basic` | 1000 | 1.9s |  |
| 285 | `edittext_mousedown` | 3 | 2.2s |  |
| 286 | `edittext_mouseenabled` | 26 | 1.8s |  |
| 287 | `edittext_newline_character` | 22 | 1.8s |  |
| 288 | `edittext_newline_stripping` | 64 | 3.6s |  |
| 289 | `edittext_newlines` | 30 | 1.8s |  |
| 290 | `edittext_paragraph_methods` | 257 | 1.8s |  |
| 291 | `edittext_paste_events` | 8 | 1.9s |  |
| 292 | `edittext_paste_maxchars` | 4 | 1.8s |  |
| 293 | `edittext_paste_restrict` | 16 | 0.4s |  |
| 294 | `edittext_restrict` | 191 | 1.8s |  |
| 295 | `edittext_restrict_events` | 22 | 1.8s |  |
| 296 | `edittext_scrollh` | 10 | 1.8s |  |
| 297 | `edittext_selected_text` | 9 | 1.8s |  |
| 298 | `edittext_set_html_same` | 17 | 1.8s |  |
| 299 | `edittext_set_text_vs_html` | 9 | 1.8s |  |
| 300 | `edittext_stylesheet` | 536 | 2.1s |  |
| 301 | `edittext_stylesheet_custom_tag` | 76 | 3.0s |  |
| 302 | `edittext_stylesheet_display` | 272 | 2.1s |  |
| 303 | `edittext_underline` | 40 | 2.0s |  |
| 304 | `edittext_width_height` | 103 | 2.2s |  |
| 305 | `edittext_wordwrap_word` | 150 | 2.4s |  |
| 306 | `edittext_wrap_breaks` | 2375 | 2.7s |  |
| 307 | `empty_bounds` | 1 | 2.0s |  |
| 308 | `equals` | 512 | 3.2s |  |
| 309 | `error_prototype` | 15 | 2.0s |  |
| 310 | `error_stack_trace_debug_swf17` | 0 | 23.5s |  |
| 311 | `error_stack_trace_debug_swf18` | 0 | 0.6s |  |
| 312 | `error_stack_trace_release_swf17` | 0 | 0.4s |  |
| 313 | `error_stack_trace_release_swf18` | 0 | 0.3s |  |
| 314 | `error_tostring` | 29 | 1.9s |  |
| 315 | `es3_inheritance` | 31 | 2.0s |  |
| 316 | `es4_inheritance` | 30 | 2.0s |  |
| 317 | `es4_interfaces` | 30 | 2.0s |  |
| 318 | `es4_method_binding` | 8 | 2.0s |  |
| 319 | `es4_oop_prototypes` | 14 | 2.1s |  |
| 320 | `es4_protected_inheritance` | 6 | 2.0s |  |
| 321 | `event_bubbles` | 2 | 2.0s |  |
| 322 | `event_cancelable` | 2 | 1.9s |  |
| 323 | `event_clone` | 20 | 2.0s |  |
| 324 | `event_clone_error_redispatch` | 3 | 2.1s |  |
| 325 | `event_clone_on_redispatch` | 10 | 2.9s |  |
| 326 | `event_formattostring` | 31 | 2.0s |  |
| 327 | `event_handler_exception` | 4 | 2.0s |  |
| 328 | `event_isdefaultprevented` | 12 | 1.9s |  |
| 329 | `event_target_getter` | 5 | 1.9s |  |
| 330 | `event_target_set` | 9 | 1.9s |  |
| 331 | `event_type` | 1 | 1.9s |  |
| 332 | `event_valueof_tostring` | 18 | 1.9s |  |
| 333 | `eventdispatcher_dispatchevent` | 12 | 1.9s |  |
| 334 | `eventdispatcher_dispatchevent_cancel` | 20 | 1.9s |  |
| 335 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 1.9s |  |
| 336 | `eventdispatcher_dispatchevent_indirect` | 9 | 2.0s |  |
| 337 | `eventdispatcher_dispatchevent_this` | 5 | 1.9s |  |
| 338 | `eventdispatcher_haseventlistener` | 25 | 1.9s |  |
| 339 | `eventdispatcher_interface_invoke` | 1 | 1.9s |  |
| 340 | `eventdispatcher_tostring` | 10 | 1.9s |  |
| 341 | `eventdispatcher_willtrigger` | 25 | 1.8s |  |
| 342 | `falsiness` | 30 | 1.9s |  |
| 343 | `fast_index_access` | 12 | 2.0s |  |
| 344 | `finddef` | 3 | 1.9s |  |
| 345 | `findprop_global_prototype` | 6 | 1.9s |  |
| 346 | `flash_xml` | 29 | 1.9s |  |
| 347 | `flash_xml_cloneNode` | 22 | 1.9s |  |
| 348 | `flash_xml_namespace` | 109 | 1.9s |  |
| 349 | `flash_xml_removeNode` | 60 | 2.7s |  |
| 350 | `focus_events_code` | 161 | 20.7s |  |
| 351 | `focus_events_key_same_object` | 26 | 1.9s |  |
| 352 | `focus_events_mixed_key_mouse` | 100 | 20.1s |  |
| 353 | `focus_events_mouse_same_object` | 40 | 1.9s |  |
| 354 | `focus_remove` | 20 | 19.9s |  |
| 355 | `focus_root_movie` | 4 | 20.4s |  |
| 356 | `focus_stage` | 1 | 1.8s |  |
| 357 | `focusrect` | 18 | 2.5s |  |
| 358 | `font_description_clone` | 14 | 1.8s |  |
| 359 | `font_embedded` | 24 | 2.2s |  |
| 360 | `font_enumeratefonts` | 41 | 2.3s |  |
| 361 | `font_enumeratefonts_filter` | 4 | 2.5s |  |
| 362 | `font_hasglyphs` | 40 | 2.1s |  |
| 363 | `framelabel_constr` | 5 | 1.9s |  |
| 364 | `function_call` | 12 | 1.9s |  |
| 365 | `function_call_arguments` | 46 | 1.9s |  |
| 366 | `function_call_arguments_enumerate` | 5 | 1.8s |  |
| 367 | `function_call_coercion` | 108 | 2.0s |  |
| 368 | `function_call_default` | 6 | 1.8s |  |
| 369 | `function_call_rest` | 22 | 1.9s |  |
| 370 | `function_call_types` | 3 | 1.8s |  |
| 371 | `function_call_via_apply` | 11 | 1.8s |  |
| 372 | `function_call_via_call` | 3 | 1.8s |  |
| 373 | `function_display_anonymous` | 7 | 1.8s |  |
| 374 | `function_length` | 6 | 1.8s |  |
| 375 | `function_object` | 2 | 1.8s |  |
| 376 | `function_proto` | 5 | 1.8s |  |
| 377 | `function_proto_created` | 61 | 1.8s |  |
| 378 | `function_to_locale_string` | 4 | 1.8s |  |
| 379 | `function_to_string` | 4 | 2.1s |  |
| 380 | `function_type` | 6 | 1.5s |  |
| 381 | `function_unbound_this` | 51 | 1.6s |  |
| 382 | `function_value_of` | 4 | 1.6s |  |
| 383 | `get_definition_by_name` | 11 | 1.5s |  |
| 384 | `get_qualified_class_name` | 20 | 1.5s |  |
| 385 | `get_qualified_super_class_name` | 18 | 1.6s |  |
| 386 | `get_slot_edge_cases` | 1 | 1.4s |  |
| 387 | `getglobalslot` | 1 | 1.5s |  |
| 388 | `getouterscope` | 8 | 1.4s |  |
| 389 | `getter_different_namespace_setter` | 2 | 1.6s |  |
| 390 | `goto_button_nested_framescript` | 28 | 16.5s |  |
| 391 | `goto_in_constructframe` | 12 | 16.2s |  |
| 392 | `goto_in_scene_last_frame` | 2 | 16.0s |  |
| 393 | `goto_methods` | 56 | 1.6s |  |
| 394 | `goto_methods_swfver10` | 8 | 1.4s |  |
| 395 | `goto_nested_construct_sibling` | 18 | 1.8s |  |
| 396 | `goto_nested_framescript` | 9 | 1.6s |  |
| 397 | `goto_on_orphan` | 15 | 1.6s |  |
| 398 | `graphics_bitmap_fill` | 0 | 2.7s |  |
| 399 | `graphics_bitmaps` | 0 | 1.7s |  |
| 400 | `graphics_direct_commands` | 0 | 1.6s |  |
| 401 | `graphics_gradients` | 0 | 1.5s |  |
| 402 | `graphics_gradients_nulls` | 0 | 1.5s |  |
| 403 | `graphics_round_rects` | 0 | 1.5s |  |
| 404 | `graphics_simple_shapes` | 0 | 1.6s |  |
| 405 | `greaterequals` | 512 | 2.2s |  |
| 406 | `greaterthan` | 512 | 3.8s |  |
| 407 | `has_own_property` | 102 | 2.1s |  |
| 408 | `hasownproperty_namespaces` | 2 | 1.9s |  |
| 409 | `hello_world` | 1 | 1.9s |  |
| 410 | `hittest_morph` | 30 | 2.0s |  |
| 411 | `if_eq` | 10 | 1.9s |  |
| 412 | `if_gt` | 1 | 1.9s |  |
| 413 | `if_gte` | 10 | 1.9s |  |
| 414 | `if_lt` | 1 | 0.5s |  |
| 415 | `if_lte` | 10 | 0.5s |  |
| 416 | `if_ne` | 7 | 1.9s |  |
| 417 | `if_stricteq` | 6 | 1.9s |  |
| 418 | `if_strictne` | 11 | 1.9s |  |
| 419 | `in` | 102 | 2.1s |  |
| 420 | `inclocal` | 46 | 1.9s |  |
| 421 | `inclocal_i` | 46 | 1.9s |  |
| 422 | `increment` | 46 | 1.9s |  |
| 423 | `increment_i` | 46 | 1.9s |  |
| 424 | `instanceof` | 58 | 2.0s |  |
| 425 | `instantiation_on_enter_frame` | 7 | 20.9s |  |
| 426 | `instantiation_on_enterframe_gotoandstop` | 8 | 1.9s |  |
| 427 | `int_constr` | 92 | 2.0s |  |
| 428 | `int_edge_cases` | 19 | 2.0s |  |
| 429 | `int_instanceof` | 3 | 1.8s |  |
| 430 | `int_tofixed` | 1215 | 1.8s |  |
| 431 | `int_tostring` | 3375 | 2.1s |  |
| 432 | `interactiveobject_enabled` | 25 | 1.8s |  |
| 433 | `interface_namespaces` | 78 | 2.0s |  |
| 434 | `is_finite` | 46 | 2.0s |  |
| 435 | `is_nan` | 46 | 1.8s |  |
| 436 | `is_prototype_of` | 12 | 1.9s |  |
| 437 | `issue_10221` | 2 | 1.9s |  |
| 438 | `issue_13780` | 12 | 1.9s |  |
| 439 | `issue_14901` | 1 | 2.6s |  |
| 440 | `issue_17675_edittext_paste_maxchars` | 1 | 1.9s |  |
| 441 | `issue_5292` | 5 | 1.8s |  |
| 442 | `issue_8630` | 2 | 1.8s |  |
| 443 | `issue_8630_scriptremove` | 11 | 1.8s |  |
| 444 | `istype` | 24 | 1.8s |  |
| 445 | `istypelate` | 58 | 1.9s |  |
| 446 | `istypelate_coerce` | 198 | 2.2s |  |
| 447 | `json_errors` | 9 | 19.9s |  |
| 448 | `json_parse` | 21 | 1.8s |  |
| 449 | `json_version_gated` | 1 | 1.8s |  |
| 450 | `key_input_80percent` | 1812 | 1.9s |  |
| 451 | `key_input_location` | 126 | 1.9s |  |
| 452 | `key_input_numpad` | 384 | 1.8s |  |
| 453 | `lazyinit` | 17 | 1.8s |  |
| 454 | `lessequals` | 512 | 2.8s |  |
| 455 | `lessthan` | 512 | 2.7s |  |
| 456 | `lshift` | 1058 | 3.6s |  |
| 457 | `mask_reapply` | 1 | 16.9s |  |
| 458 | `math` | 497 | 1.6s |  |
| 459 | `modulo` | 1058 | 3.6s |  |
| 460 | `mouse_click_events` | 90 | 16.5s |  |
| 461 | `mouse_double_click_events` | 188 | 1.5s |  |
| 462 | `mouse_empty_parent` | 4 | 1.5s |  |
| 463 | `mouse_over_while_dragging` | 3 | 1.5s |  |
| 464 | `mouse_pick_button_mode` | 2 | 1.6s |  |
| 465 | `mouse_sibling` | 8 | 1.9s |  |
| 466 | `movieclip_addframescript` | 3 | 20.8s |  |
| 467 | `movieclip_child_property` | 16 | 1.9s |  |
| 468 | `movieclip_constr` | 21 | 1.9s |  |
| 469 | `movieclip_currentlabels` | 17 | 21.1s |  |
| 470 | `movieclip_currentlabels_dupes1` | 46 | 21.1s |  |
| 471 | `movieclip_currentlabels_dupes2` | 30 | 2.0s |  |
| 472 | `movieclip_currentlabels_dupes3` | 67 | 1.9s |  |
| 473 | `movieclip_currentscene` | 12 | 21.0s |  |
| 474 | `movieclip_dispatchevent` | 430 | 1.9s |  |
| 475 | `movieclip_dispatchevent_cancel` | 102 | 1.9s |  |
| 476 | `movieclip_dispatchevent_handlerorder` | 251 | 1.9s |  |
| 477 | `movieclip_dispatchevent_selfadd` | 80 | 1.9s |  |
| 478 | `movieclip_dispatchevent_target` | 899 | 1.9s |  |
| 479 | `movieclip_displayevents` | 96 | 20.6s |  |
| 480 | `movieclip_displayevents_clickgoto` | 676 | 20.9s |  |
| 481 | `movieclip_displayevents_clickgoto2` | 2001 | 2.3s |  |
| 482 | `movieclip_displayevents_clickplay` | 575 | 2.0s |  |
| 483 | `movieclip_displayevents_clicksymbol` | 562 | 2.0s |  |
| 484 | `movieclip_displayevents_constructframegoto` | 140 | 2.1s |  |
| 485 | `movieclip_displayevents_constructframeplay` | 50 | 2.0s |  |
| 486 | `movieclip_displayevents_constructframesymbol` | 144 | 2.0s |  |
| 487 | `movieclip_displayevents_dblhandler` | 21 | 1.9s |  |
| 488 | `movieclip_displayevents_enterframegoto` | 149 | 2.0s |  |
| 489 | `movieclip_displayevents_enterframeplay` | 48 | 1.9s |  |
| 490 | `movieclip_displayevents_enterframesymbol` | 149 | 20.5s |  |
| 491 | `movieclip_displayevents_exitframegoto` | 106 | 1.9s |  |
| 492 | `movieclip_displayevents_exitframeplay` | 44 | 1.9s |  |
| 493 | `movieclip_displayevents_exitframesymbol` | 135 | 2.0s |  |
| 494 | `movieclip_displayevents_looping` | 63 | 21.4s |  |
| 495 | `movieclip_displayevents_stopped` | 113 | 2.2s |  |
| 496 | `movieclip_displayevents_swap` | 96 | 1.8s |  |
| 497 | `movieclip_displayevents_timeline` | 128 | 23.1s |  |
| 498 | `movieclip_drawrect` | 54 | 1.9s |  |
| 499 | `movieclip_frameconstruct_skipped` | 9 | 2.4s |  |
| 500 | `movieclip_goto_during_frame_script` | 15 | 16.5s |  |
| 501 | `movieclip_goto_overwrite` | 14 | 17.1s |  |
| 502 | `movieclip_goto_scene_last_frame_int` | 1 | 17.1s |  |
| 503 | `movieclip_goto_scene_last_frame_label` | 1 | 1.6s |  |
| 504 | `movieclip_gotoandplay` | 15 | 16.6s |  |
| 505 | `movieclip_gotoandstop` | 13 | 1.5s |  |
| 506 | `movieclip_gotoandstop_children` | 4 | 1.6s |  |
| 507 | `movieclip_gotoandstop_framescripts1` | 4 | 1.7s |  |
| 508 | `movieclip_gotoandstop_framescripts2` | 4 | 1.6s |  |
| 509 | `movieclip_gotoandstop_framescripts_self` | 7 | 16.6s |  |
| 510 | `movieclip_gotoandstop_queueing` | 12 | 1.6s |  |
| 511 | `movieclip_next_frame` | 2 | 1.6s |  |
| 512 | `movieclip_next_scene` | 6 | 16.6s |  |
| 513 | `movieclip_play` | 3 | 1.4s |  |
| 514 | `movieclip_prev_frame` | 3 | 0.3s |  |
| 515 | `movieclip_prev_scene` | 7 | 1.7s |  |
| 516 | `movieclip_properties` | 79 | 16.1s |  |
| 517 | `movieclip_queued_noop_goto_swf10` | 9 | 1.6s |  |
| 518 | `movieclip_queued_noop_goto_swf9` | 7 | 0.4s |  |
| 519 | `movieclip_scenes` | 11 | 1.5s |  |
| 520 | `movieclip_stop` | 1 | 16.0s |  |
| 521 | `movieclip_super_is_symbol` | 20 | 1.9s |  |
| 522 | `movieclip_symbol_constr` | 8 | 1.7s |  |
| 523 | `movieclip_text_mousedown` | 1 | 1.9s |  |
| 524 | `movieclip_willtrigger` | 5 | 1.6s |  |
| 525 | `multiply` | 1058 | 3.4s |  |
| 526 | `namespace_constr` | 253 | 1.8s |  |
| 527 | `namespace_constr_args` | 1 | 1.4s |  |
| 528 | `namespace_enumeration_order` | 7 | 1.5s |  |
| 529 | `nan_scale` | 9 | 1.4s |  |
| 530 | `negate` | 30 | 1.4s |  |
| 531 | `negative_volume_panned` | 0 | 1.6s |  |
| 532 | `nested_iteration` | 11 | 1.4s |  |
| 533 | `net_getClassByAlias` | 3 | 1.5s |  |
| 534 | `newactivation_in_script_init` | 3 | 1.9s |  |
| 535 | `newclass_twice` | 3 | 1.9s |  |
| 536 | `nonconflicting_declarations` | 0 | 1.9s |  |
| 537 | `null_void_types` | 8 | 1.9s |  |
| 538 | `number_autoconv` | 21 | 1.9s |  |
| 539 | `number_autoconv_amf` | 132 | 1.9s |  |
| 540 | `number_autoconv_array_sort_32bit` | 1 | 1.9s |  |
| 541 | `number_constr` | 58 | 2.0s |  |
| 542 | `number_toexponential` | 378 | 2.0s |  |
| 543 | `number_toexponential2` | 35 | 1.9s |  |
| 544 | `number_tofixed` | 378 | 1.9s |  |
| 545 | `number_toprecision` | 350 | 2.0s |  |
| 546 | `obfuscated_class_names` | 3 | 1.9s |  |
| 547 | `object_enumeration` | 10 | 1.9s |  |
| 548 | `object_prototype` | 4 | 1.9s |  |
| 549 | `object_to_locale_string` | 2 | 2.0s |  |
| 550 | `object_to_string` | 2 | 1.9s |  |
| 551 | `object_value_of` | 2 | 1.7s |  |
| 552 | `op_coerce` | 54 | 1.3s |  |
| 553 | `op_coerce_x` | 54 | 1.9s |  |
| 554 | `op_escxattr` | 2 | 1.9s |  |
| 555 | `op_escxelem` | 2 | 1.9s |  |
| 556 | `op_lookupswitch` | 4 | 1.9s |  |
| 557 | `optimize_coerce` | 1 | 1.9s |  |
| 558 | `orphan_movie_complex` | 80 | 2.2s |  |
| 559 | `orphan_movie_reorder` | 111 | 21.4s |  |
| 560 | `package_namespace` | 7 | 2.0s |  |
| 561 | `param_default_value_has_zero_cpool_index` | 1 | 1.8s |  |
| 562 | `parent_early_access_child` | 16 | 20.9s |  |
| 563 | `parse_float` | 80 | 2.0s |  |
| 564 | `pixelbender_effect_BlurredFocus` | 0 | 24.6s |  |
| 565 | `pixelbender_effect_glassDisplace` | 0 | 8.4s |  |
| 566 | `pixelbender_effect_smudge` | 0 | 5.1s |  |
| 567 | `pixelbender_effect_tintype` | 0 | 4.3s |  |
| 568 | `pixelbender_effect_twirl` | 0 | 5.7s |  |
| 569 | `pixelbender_images` | 0 | 4.5s |  |
| 570 | `place_multiple` | 17 | 1.7s |  |
| 571 | `place_object_replace` | 9 | 1.8s |  |
| 572 | `place_object_replace_2` | 24 | 20.0s |  |
| 573 | `place_object_same_depth_frame` | 1 | 1.7s |  |
| 574 | `primitive_edge_cases` | 1 | 1.6s |  |
| 575 | `property_priority` | 22 | 1.9s |  |
| 576 | `property_priority_three_level` | 6 | 1.8s |  |
| 577 | `propertyisenumerable_namespaces` | 6 | 1.6s |  |
| 578 | `prototype_set_null` | 7 | 1.6s |  |
| 579 | `proxy_callproperty` | 24 | 1.6s |  |
| 580 | `proxy_deleteproperty` | 64 | 1.7s |  |
| 581 | `proxy_enumeration` | 34 | 1.6s |  |
| 582 | `proxy_getproperty` | 77 | 1.7s |  |
| 583 | `proxy_hasownproperty` | 8 | 1.6s |  |
| 584 | `proxy_hasproperty` | 32 | 1.7s |  |
| 585 | `proxy_serialize` | 9 | 1.6s |  |
| 586 | `proxy_setproperty` | 42 | 1.7s |  |
| 587 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.6s |  |
| 588 | `qname_constr` | 32 | 1.6s |  |
| 589 | `qname_constr_namespace` | 24 | 1.6s |  |
| 590 | `qname_enumeration` | 9 | 1.6s |  |
| 591 | `qname_indexing` | 23 | 1.7s |  |
| 592 | `qname_tostring` | 25 | 1.6s |  |
| 593 | `qname_valueof` | 29 | 1.7s |  |
| 594 | `regexp_constr` | 148 | 1.9s |  |
| 595 | `regexp_exec` | 19 | 1.6s |  |
| 596 | `regexp_extended` | 47 | 1.6s |  |
| 597 | `regexp_multiargs` | 1 | 1.5s |  |
| 598 | `regexp_test` | 27 | 2.6s |  |
| 599 | `regexp_toString` | 10 | 1.8s |  |
| 600 | `register_script_refresh` | 35 | 20.0s |  |
| 601 | `remove_child_clear_field` | 88 | 20.6s |  |
| 602 | `remove_dobj` | 3 | 1.8s |  |
| 603 | `resolve_order` | 4 | 1.8s |  |
| 604 | `rng` | 1 | 3.1s |  |
| 605 | `rootless` | 42 | 1.9s |  |
| 606 | `rshift` | 1058 | 4.0s |  |
| 607 | `scene_constr` | 8 | 1.9s |  |
| 608 | `set_property_is_enumerable` | 85 | 2.0s |  |
| 609 | `shape_drawrect` | 54 | 1.8s |  |
| 610 | `simplebutton_added_to_stage` | 45 | 20.2s |  |
| 611 | `simplebutton_childevents` | 86 | 21.0s |  |
| 612 | `simplebutton_childevents_nested` | 54 | 2.1s |  |
| 613 | `simplebutton_childevents_sprite` | 13 | 1.9s |  |
| 614 | `simplebutton_childprops` | 144 | 2.1s |  |
| 615 | `simplebutton_childshuffle` | 23 | 1.8s |  |
| 616 | `simplebutton_constr` | 36 | 2.1s |  |
| 617 | `simplebutton_constr_childevents` | 48 | 2.2s |  |
| 618 | `simplebutton_constr_params` | 42 | 2.0s |  |
| 619 | `simplebutton_mouseenabled` | 26 | 1.8s |  |
| 620 | `simplebutton_multi_children` | 19 | 2.1s |  |
| 621 | `simplebutton_structure` | 27 | 2.1s |  |
| 622 | `simplebutton_symbolclass` | 68 | 2.3s |  |
| 623 | `slot_disp_id_shared_numbering` | 1 | 17.9s |  |
| 624 | `slots_force_autoassigned` | 1 | 1.7s |  |
| 625 | `sprite_with_frames` | 0 | 17.5s |  |
| 626 | `stage3d_agal_cross_product` | 0 | 2.4s |  |
| 627 | `stage3d_bitmap` | 0 | 20.4s |  |
| 628 | `stage3d_float1_index` | 0 | 18.6s |  |
| 629 | `stage3d_fractal` | 0 | 4.7s |  |
| 630 | `stage3d_ignore_sampler_override` | 0 | 22.4s |  |
| 631 | `stage3d_program_constants_bytearray_be` | 0 | 22.5s |  |
| 632 | `stage3d_program_constants_bytearray_le` | 0 | 3.6s |  |
| 633 | `stage3d_raytrace` | 0 | 21.1s |  |
| 634 | `stage3d_rotating_cube` | 0 | 3.7s |  |
| 635 | `stage3d_sampler` | 0 | 3.2s |  |
| 636 | `stage3d_sampler_partial_upload` | 0 | 3.2s |  |
| 637 | `stage3d_stencil` | 0 | 22.3s |  |
| 638 | `stage3d_texture` | 0 | 7.4s |  |
| 639 | `stage3d_texture_bytearray` | 0 | 4.4s |  |
| 640 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 3.8s |  |
| 641 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 5.1s |  |
| 642 | `stage3d_triangle` | 0 | 3.2s |  |
| 643 | `stage3d_triangle_bytes4` | 0 | 3.3s |  |
| 644 | `stage3d_triangle_float1` | 0 | 3.2s |  |
| 645 | `stage3d_triangle_index_upload` | 0 | 3.2s |  |
| 646 | `stage_access` | 10 | 1.9s |  |
| 647 | `stage_displayobject_properties` | 24 | 1.8s |  |
| 648 | `stage_framerate_nan` | 7 | 2.0s |  |
| 649 | `stage_framerate_negative` | 6 | 1.9s |  |
| 650 | `stage_framerate_zero` | 6 | 1.9s |  |
| 651 | `stage_invalidate` | 38 | 2.0s |  |
| 652 | `stage_mousechildren` | 2 | 1.9s |  |
| 653 | `stage_mouseenabled` | 15 | 1.8s |  |
| 654 | `stage_overriden_setters` | 31 | 2.0s |  |
| 655 | `stage_properties` | 30 | 1.8s |  |
| 656 | `static_var_with_this_in_ctor` | 2 | 1.9s |  |
| 657 | `stored_properties` | 11 | 2.7s |  |
| 658 | `strict_equality` | 34 | 1.9s |  |
| 659 | `string_call` | 13 | 1.9s |  |
| 660 | `string_case` | 23 | 1.9s |  |
| 661 | `string_char_at` | 27 | 1.8s |  |
| 662 | `string_char_code_at` | 28 | 1.8s |  |
| 663 | `string_concat_fromcharcode` | 36 | 1.9s |  |
| 664 | `string_constr` | 25 | 1.8s |  |
| 665 | `string_indexof_lastindexof` | 87 | 1.9s |  |
| 666 | `string_length` | 16 | 1.8s |  |
| 667 | `string_locale_compare` | 39 | 2.0s |  |
| 668 | `string_match` | 51 | 2.0s |  |
| 669 | `string_relational_compare` | 4 | 1.8s |  |
| 670 | `string_replace` | 51 | 1.9s |  |
| 671 | `string_search` | 41 | 1.9s |  |
| 672 | `string_slice_substr_substring` | 169 | 2.1s |  |
| 673 | `string_split` | 29 | 1.9s |  |
| 674 | `string_substr_negative` | 21 | 1.8s |  |
| 675 | `string_substr_weird` | 182 | 1.8s |  |
| 676 | `subtract` | 1058 | 4.0s |  |
| 677 | `super_get_call` | 12 | 1.8s |  |
| 678 | `supercall_two_classobjects` | 2 | 1.9s |  |
| 679 | `swf8` | 1 | 1.6s |  |
| 680 | `swf_10_queued_goto_scripts_construct` | 52 | 20.6s |  |
| 681 | `swf_9_goto_in_enter_frame` | 17 | 1.9s |  |
| 682 | `swf_9_goto_in_enter_frame_simple` | 15 | 1.9s |  |
| 683 | `swf_9_queued_goto_scripts` | 6 | 20.4s |  |
| 684 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 685 | `swf_9_versioning` | 2 | 1.8s |  |
| 686 | `swf_wrong_frame_count` | 38 | 2.0s |  |
| 687 | `swf_wrong_frame_count_isplaying` | 22 | 2.8s |  |
| 688 | `symbol_class_conflict` | 4 | 21.3s |  |
| 689 | `symbol_class_root_not_zero` | 1 | 1.7s |  |
| 690 | `symbolclass_invalid_utf8` | 2 | 1.8s |  |
| 691 | `tab_ordering_automatic_advanced` | 184 | 2.4s |  |
| 692 | `tab_ordering_automatic_basic` | 45 | 1.9s |  |
| 693 | `tab_ordering_children` | 116 | 2.0s |  |
| 694 | `tab_ordering_custom_basic` | 34 | 1.9s |  |
| 695 | `text_engine_fontdescription` | 27 | 2.0s |  |
| 696 | `text_run` | 7 | 1.8s |  |
| 697 | `textfield_focusin_event` | 9 | 1.8s |  |
| 698 | `textfield_input_dead_keys_windows` | 15 | 1.9s |  |
| 699 | `textfield_unload` | 39 | 2.1s |  |
| 700 | `textformat` | 1134 | 1.9s |  |
| 701 | `textformat_display` | 14 | 1.9s |  |
| 702 | `textformat_font_max_length` | 4 | 1.8s |  |
| 703 | `throw` | 3 | 1.9s |  |
| 704 | `timeline_scripts` | 3 | 2.0s |  |
| 705 | `trace` | 12 | 2.0s |  |
| 706 | `truthiness` | 30 | 1.9s |  |
| 707 | `try_catch` | 11 | 2.0s |  |
| 708 | `try_catch_typed` | 12 | 2.0s |  |
| 709 | `typeof` | 30 | 2.0s |  |
| 710 | `uint_constr` | 92 | 2.0s |  |
| 711 | `uint_tofixed` | 1215 | 1.9s |  |
| 712 | `uint_tostring` | 3375 | 2.1s |  |
| 713 | `uncaught_errors_stringified` | 3 | 2.0s |  |
| 714 | `unchecked_function` | 15 | 1.9s |  |
| 715 | `urshift` | 1058 | 4.5s |  |
| 716 | `vector_class` | 36 | 2.3s |  |
| 717 | `vector_class_call` | 11 | 2.1s |  |
| 718 | `vector_coercion` | 66 | 2.6s |  |
| 719 | `vector_concat` | 90 | 2.2s |  |
| 720 | `vector_constr` | 107 | 2.2s |  |
| 721 | `vector_enumeration` | 5 | 1.9s |  |
| 722 | `vector_every` | 92 | 2.4s |  |
| 723 | `vector_filter` | 95 | 2.3s |  |
| 724 | `vector_holes` | 24 | 2.0s |  |
| 725 | `vector_indexof` | 302 | 3.0s |  |
| 726 | `vector_insertat` | 270 | 2.4s |  |
| 727 | `vector_int_access` | 4 | 1.9s |  |
| 728 | `vector_int_delete` | 11 | 1.9s |  |
| 729 | `vector_join` | 58 | 2.2s |  |
| 730 | `vector_lastindexof` | 302 | 1.9s |  |
| 731 | `vector_legacy` | 10 | 1.9s |  |
| 732 | `vector_map` | 85 | 3.0s |  |
| 733 | `vector_object_final` | 1 | 1.7s |  |
| 734 | `vector_object_toString` | 10 | 0.9s |  |
| 735 | `vector_pushpop` | 255 | 1.4s |  |
| 736 | `vector_reborrow_bug` | 10 | 0.9s |  |
| 737 | `vector_removeat` | 172 | 1.3s |  |
| 738 | `vector_reverse` | 232 | 1.4s |  |
| 739 | `vector_shiftunshift` | 252 | 0.9s |  |
| 740 | `vector_slice` | 331 | 1.4s |  |
| 741 | `vector_sort` | 905 | 2.8s |  |
| 742 | `vector_splice` | 693 | 2.5s |  |
| 743 | `vector_splice_fixed_bug_compat` | 4 | 1.0s |  |
| 744 | `vector_tostring` | 79 | 1.2s |  |
| 745 | `verify_abnormal_loop` | 1 | 0.9s |  |
| 746 | `verify_exception_targets_edge_case` | 1 | 0.9s |  |
| 747 | `verify_lookup_switch_edge_case` | 1 | 0.9s |  |
| 748 | `verify_unreachable_exception` | 2 | 0.9s |  |
| 749 | `versioned_isplaying` | 2 | 0.9s |  |
| 750 | `virtual_properties` | 16 | 1.0s |  |
| 751 | `with` | 4 | 0.9s |  |
| 752 | `xml_abstract_equality` | 36 | 1.1s |  |
| 753 | `xml_advanced` | 52 | 1.0s |  |
| 754 | `xml_appendchild` | 10 | 0.9s |  |
| 755 | `xml_as_attribute` | 9 | 0.9s |  |
| 756 | `xml_attribute` | 35 | 1.1s |  |
| 757 | `xml_attribute_name` | 40 | 1.0s |  |
| 758 | `xml_basic` | 32 | 1.2s |  |
| 759 | `xml_child` | 25 | 1.0s |  |
| 760 | `xml_childindex` | 7 | 0.9s |  |
| 761 | `xml_children` | 43 | 1.4s |  |
| 762 | `xml_class_call` | 9 | 1.0s |  |
| 763 | `xml_contains` | 197 | 2.0s |  |
| 764 | `xml_copy` | 20 | 2.0s |  |
| 765 | `xml_ctor_from_tostring` | 23 | 2.3s |  |
| 766 | `xml_delete` | 114 | 2.0s |  |
| 767 | `xml_descendants` | 83 | 1.9s |  |
| 768 | `xml_elements` | 6 | 1.9s |  |
| 769 | `xml_equals_namespace_check` | 2 | 1.8s |  |
| 770 | `xml_explicit_use_namespace` | 5 | 1.9s |  |
| 771 | `xml_getdescendants_qname` | 21 | 1.9s |  |
| 772 | `xml_has_property_via_in` | 26 | 1.9s |  |
| 773 | `xml_hasownproperty` | 6 | 1.9s |  |
| 774 | `xml_ignore_white` | 6 | 1.9s |  |
| 775 | `xml_length` | 2 | 1.9s |  |
| 776 | `xml_list_as_attribute` | 9 | 1.2s |  |
| 777 | `xml_list_concat` | 20 | 1.7s |  |
| 778 | `xml_list_enumerate` | 4 | 1.8s |  |
| 779 | `xml_methods_settings` | 3 | 1.9s |  |
| 780 | `xml_mismatched_tag` | 37 | 1.9s |  |
| 781 | `xml_namespace` | 39 | 1.9s |  |
| 782 | `xml_namespace_methods` | 245 | 1.9s |  |
| 783 | `xml_namespaced_property` | 7 | 1.9s |  |
| 784 | `xml_no_namespace` | 1 | 1.8s |  |
| 785 | `xml_nodekind` | 3 | 1.9s |  |
| 786 | `xml_normalize` | 35 | 1.9s |  |
| 787 | `xml_notification_bubbling` | 361 | 1.9s |  |
| 788 | `xml_parent` | 8 | 1.9s |  |
| 789 | `xml_set_children` | 17 | 1.7s |  |
| 790 | `xml_set_name` | 34 | 1.9s |  |
| 791 | `xml_settings` | 6 | 1.9s |  |
| 792 | `xml_simple_complex_content` | 47 | 1.9s |  |
| 793 | `xml_text` | 7 | 1.9s |  |
| 794 | `xml_tostring` | 6 | 1.9s |  |
| 795 | `xml_tostring_namespace` | 12 | 1.9s |  |
| 796 | `xml_unescaping` | 23 | 1.9s |  |
| 797 | `xml_weird_ignores` | 54 | 1.9s |  |
| 798 | `xml_wildcard` | 11 | 1.9s |  |
| 799 | `xmldocument` | 254 | 1.9s |  |
| 800 | `xmlnode` | 3540 | 2.0s |  |
| 801 | `zero_frame_clip` | 3 | 2.1s |  |

## Ruffle-Matched Tests

**22 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 1 | 1.8s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 1.8s |  |
| 3 | `blend_transform` | 1 | 1 | 1.8s |  |
| 4 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 1.9s |  |
| 5 | `dictionary_weak_keys` | 1 | 1 | 20.4s |  |
| 6 | `edittext_getcharboundaries_culling` | 300 | 300 | 2.0s |  |
| 7 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 1.9s |  |
| 8 | `edittext_tab_stops` | 6 | 6 | 2.3s |  |
| 9 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 2.0s |  |
| 10 | `error_1034_debug_string` | 19 | 19 | 2.1s |  |
| 11 | `freestanding_superclass` | 3 | 4 | 1.8s |  |
| 12 | `goto_framescript_queued` | 5 | 5 | 1.9s |  |
| 13 | `int_toexponential` | 76 | 76 | 2.0s |  |
| 14 | `int_toprecision` | 441 | 441 | 2.0s |  |
| 15 | `simplebutton_childevents_script_order` | 4 | 4 | 2.1s |  |
| 16 | `slot_holes_fail` | 1 | 1 | 1.4s |  |
| 17 | `slot_id_exceeds_trait_count` | 1 | 1 | 1.3s |  |
| 18 | `sprite_dropTarget` | 4 | 4 | 1.6s |  |
| 19 | `swf_9_goto_in_construct_frame` | 12 | 12 | 20.6s |  |
| 20 | `uint_toexponential` | 100 | 100 | 2.0s |  |
| 21 | `uint_toprecision` | 433 | 433 | 2.1s |  |
| 22 | `weird_superinterface_properties` | 1 | 1 | 0.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**57 tests** within reach

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
| 9 | `tab_ordering_tabbable` | 95.7% | 45 | 47 | 2 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 11 | `focusrect_property` | 94.5% | 104 | 110 | 6 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 13 | `mouseevent_constr` | 93.9% | 62 | 66 | 4 |  |
| 14 | `json_stringify` | 92.9% | 13 | 14 | 1 |  |
| 15 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 16 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 17 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 18 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 19 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 20 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 21 | `bitmap_subclass` | 85.7% | 6 | 7 | 1 |  |
| 22 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 23 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 24 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 25 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 26 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 27 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 28 | `place_and_lookup/swf10` | 78.8% | 26 | 33 | 7 |  |
| 29 | `place_and_lookup/swf9` | 78.8% | 26 | 33 | 7 |  |
| 30 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 31 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 32 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 33 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 34 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 35 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 36 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 37 | `symbol_class_binary_data` | 75.0% | 6 | 8 | 2 |  |
| 38 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 39 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 40 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 41 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 42 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 43 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 44 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 45 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 46 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 47 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 48 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 49 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 50 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 51 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 52 | `date` | 50.0% | 15 | 30 | 15 |  |
| 53 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 54 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 55 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 56 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 57 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 1.8s |  |
| 2 | `method_without_body` | exit code 1 | 16.0s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 1.9s |  |
| 4 | `verify_typecheck` | exit code 1 | 1.0s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 31.8s |  |

## All Output Mismatches

**376 tests** with output mismatch, sorted by match rate (best first)

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
| 9 | `tab_ordering_tabbable` | 95.7% | 45/47 | 47 | 47 |  |
| 10 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 11 | `focusrect_property` | 94.5% | 104/110 | 110 | 110 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 13 | `mouseevent_constr` | 93.9% | 62/66 | 66 | 66 |  |
| 14 | `json_stringify` | 92.9% | 13/14 | 14 | 14 |  |
| 15 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 16 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 17 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 18 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 19 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 20 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 21 | `bitmap_subclass` | 85.7% | 6/7 | 7 | 7 |  |
| 22 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 23 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 24 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 25 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 26 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 27 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 28 | `place_and_lookup/swf10` | 78.8% | 26/33 | 32 | 33 |  |
| 29 | `place_and_lookup/swf9` | 78.8% | 26/33 | 32 | 33 |  |
| 30 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 31 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 32 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 33 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 34 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 35 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 36 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 37 | `symbol_class_binary_data` | 75.0% | 6/8 | 8 | 8 |  |
| 38 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 39 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 40 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 41 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 42 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 43 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 44 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 45 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 46 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 47 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 48 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 49 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 50 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 52 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 53 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 55 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 56 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 57 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 58 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 59 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 60 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 61 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 62 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 63 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 64 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 65 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 66 | `displayobject_scrollrect` | 33.3% | 11/33 | 23 | 33 |  |
| 67 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 68 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 69 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 70 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 71 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 72 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 73 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 74 | `sound_rootless` | 28.6% | 2/7 | 2 | 7 |  |
| 75 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 76 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 77 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 78 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 79 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 80 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 81 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 82 | `bitmap_subclass_properties` | 22.2% | 2/9 | 2 | 9 |  |
| 83 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 84 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 85 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 86 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 87 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 88 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 89 | `timer_setdelay` | 20.0% | 1/5 | 1 | 5 |  |
| 90 | `focus_events_key_navigation` | 17.0% | 9/53 | 12 | 53 |  |
| 91 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 92 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 93 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 94 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 95 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 96 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 97 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 98 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 99 | `timer_reset` | 12.5% | 1/8 | 7 | 8 |  |
| 100 | `point` | 12.1% | 16/132 | 16 | 132 |  |
| 101 | `focus_events_key_basic` | 11.6% | 17/147 | 147 | 132 |  |
| 102 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 103 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 104 | `geom_transform` | 10.8% | 8/74 | 9 | 74 |  |
| 105 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 106 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 107 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 108 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 109 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 110 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 111 | `agal_compiler` | 7.7% | 1/13 | 1 | 13 |  |
| 112 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 113 | `date_parse` | 5.6% | 2/36 | 2 | 36 |  |
| 114 | `loaderinfo_properties` | 5.6% | 1/18 | 2 | 18 |  |
| 115 | `sound_load_multiple` | 5.3% | 1/19 | 1 | 19 |  |
| 116 | `primitive_toString` | 5.1% | 14/277 | 141 | 277 |  |
| 117 | `pixelbender_sign` | 5.0% | 3/60 | 16 | 60 |  |
| 118 | `element_format_constructor_order` | 4.7% | 3/64 | 49 | 64 |  |
| 119 | `primitive_valueOf` | 4.2% | 12/285 | 140 | 285 |  |
| 120 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 121 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 122 | `stage_loaderinfo_properties` | 4.2% | 1/24 | 2 | 24 |  |
| 123 | `pixelbender_ceil` | 3.9% | 3/77 | 16 | 77 |  |
| 124 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 125 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 126 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 127 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 128 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 129 | `error_throwerror` | 2.9% | 3/103 | 57 | 103 |  |
| 130 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 131 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 132 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 133 | `matrix` | 2.7% | 9/338 | 9 | 338 |  |
| 134 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 135 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 136 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 137 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 138 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 139 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 140 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 141 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 142 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 143 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 144 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 145 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 146 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 147 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 148 | `simplebutton_soundtransform` | 0.6% | 5/887 | 95 | 887 |  |
| 149 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 150 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 151 | `movieclip_soundtransform` | 0.4% | 3/831 | 96 | 831 |  |
| 152 | `soundmixer_soundtransform` | 0.3% | 3/900 | 48 | 900 |  |
| 153 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 154 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 155 | `soundtransform` | 0.2% | 1/442 | 1 | 442 |  |
| 156 | `all_classes/events/swf9` | 0.2% | 2/1030 | 110 | 1030 |  |
| 157 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 158 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 159 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 160 | `all_classes/display/swf10` | 0.1% | 2/2569 | 157 | 2569 |  |
| 161 | `all_classes/display/swf11` | 0.1% | 2/2593 | 157 | 2593 |  |
| 162 | `all_classes/display/swf12` | 0.1% | 2/2593 | 157 | 2593 |  |
| 163 | `all_classes/display/swf13` | 0.1% | 2/2671 | 157 | 2671 |  |
| 164 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 165 | `all_classes/events/swf10` | 0.1% | 1/1638 | 110 | 1638 |  |
| 166 | `all_classes/events/swf11` | 0.1% | 1/1750 | 110 | 1750 |  |
| 167 | `all_classes/events/swf12` | 0.1% | 1/1814 | 110 | 1814 |  |
| 168 | `all_classes/display/swf9` | 0.1% | 1/1959 | 157 | 1959 |  |
| 169 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 170 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 171 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 172 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 173 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 174 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 175 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 176 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 177 | `all_classes/display/swf30` | 0.0% | 0/2936 | 157 | 2936 |  |
| 178 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 179 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 180 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 181 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 182 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 183 | `all_classes/events/swf30` | 0.0% | 0/2353 | 110 | 2353 |  |
| 184 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 185 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 186 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 187 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 188 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 189 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 190 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 191 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 192 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 193 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 194 | `bitmap_pixelsnapping` | 0.0% | 0/2 | 0 | 2 |  |
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
| 209 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 210 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 211 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 212 | `displayobject_early_init` | 0.0% | 0/54 | 0 | 54 |  |
| 213 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 214 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 215 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 216 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 217 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 218 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 219 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 220 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 221 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 222 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 223 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 224 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 225 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 226 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 227 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 228 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 229 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 230 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 231 | `filter_rewind` | 0.0% | 0/8 | 1 | 8 |  |
| 232 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 233 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 234 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 235 | `get_timer` | 0.0% | 0/2 | 0 | 2 |  |
| 236 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 237 | `graphics_draw_path` | 0.0% | 0/101 | 0 | 101 |  |
| 238 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 239 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 240 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 241 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 242 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 243 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 244 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 245 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 246 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 247 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 248 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 249 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 250 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 251 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 252 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 253 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 254 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 255 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 256 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 257 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 258 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 259 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 260 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 261 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 262 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 263 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 264 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 265 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 266 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 267 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 268 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 269 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 270 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 271 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 272 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 273 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 274 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 275 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 276 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 277 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 278 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
| 279 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 280 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 281 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 282 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 283 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 284 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 285 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 286 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 287 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 288 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 289 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 290 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 291 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 292 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 293 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 294 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 295 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 296 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 297 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 298 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 299 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 300 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 301 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 302 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 303 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 304 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 305 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 306 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 307 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 308 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 309 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 310 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 311 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 312 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 313 | `sandbox_type_remote` | 0.0% | 0/3 | 0 | 3 |  |
| 314 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 315 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 316 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 317 | `shared_object_no_root` | 0.0% | 0/3 | 0 | 3 |  |
| 318 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 319 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 320 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 321 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 322 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 323 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 324 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 325 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 326 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 327 | `sound_constructor_with_args` | 0.0% | 0/6 | 0 | 6 |  |
| 328 | `sound_embeddedprops` | 0.0% | 0/26 | 0 | 26 |  |
| 329 | `sound_play` | 0.0% | 0/19 | 0 | 19 |  |
| 330 | `sound_valueof` | 0.0% | 0/33 | 0 | 33 |  |
| 331 | `soundchannel_position` | 0.0% | 0/140 | 0 | 140 |  |
| 332 | `soundchannel_soundcomplete` | 0.0% | 0/16 | 0 | 16 |  |
| 333 | `soundchannel_soundtransform` | 0.0% | 0/835 | 0 | 835 |  |
| 334 | `soundchannel_soundtransform_exists` | 0.0% | 0/5 | 0 | 5 |  |
| 335 | `soundchannel_stop` | 0.0% | 0/8 | 0 | 8 |  |
| 336 | `soundmixer_buffertime` | 0.0% | 0/5 | 0 | 5 |  |
| 337 | `soundmixer_stopall` | 0.0% | 0/6 | 0 | 6 |  |
| 338 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 339 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 340 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 341 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 342 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 343 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 344 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 345 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 346 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 347 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 348 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 349 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 350 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 351 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 352 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 353 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 354 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 355 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 356 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 357 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 358 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 359 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 360 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 361 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 362 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 363 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 364 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 365 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 366 | `timer` | 0.0% | 0/90 | 0 | 90 |  |
| 367 | `timer_events` | 0.0% | 0/3 | 0 | 3 |  |
| 368 | `timer_finished` | 0.0% | 0/11 | 0 | 11 |  |
| 369 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 370 | `url_vars` | 0.0% | 0/27 | 0 | 27 |  |
| 371 | `urlrequest` | 0.0% | 0/18 | 0 | 18 |  |
| 372 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 373 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 374 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 375 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 376 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
