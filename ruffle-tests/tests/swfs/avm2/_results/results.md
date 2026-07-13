# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-13 16:41 UTC

**Git SHA**: `278cc359c4`

**Run Duration**: 124m 59s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1204 |
| Passing | **824** (68.4%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **848** (70.4%) |
| Failing | 356 |
| Total expected lines | 149868 |
| Matching lines | 102134 (68.1%) |
| Mismatched lines | 47734 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 351 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**824 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 3.5s |  |
| 2 | `agal_compiler` | 13 | 3.5s |  |
| 3 | `air_hidden_lookup` | 2 | 3.4s |  |
| 4 | `all_classes/security/swf11` | 3 | 3.5s |  |
| 5 | `amf_custom_obj` | 26 | 3.4s |  |
| 6 | `amf_dictionary` | 9 | 3.5s |  |
| 7 | `amf_function` | 46 | 3.5s |  |
| 8 | `amf_invalid_date` | 2 | 3.5s |  |
| 9 | `amf_missing_prop` | 6 | 3.5s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 13.3s |  |
| 11 | `amf_setter_error` | 8 | 3.8s |  |
| 12 | `amf_vector` | 40 | 3.8s |  |
| 13 | `amf_xml` | 6 | 3.7s |  |
| 14 | `application_domain` | 4 | 3.8s |  |
| 15 | `array_access` | 18 | 3.7s |  |
| 16 | `array_access_interpreter` | 4 | 3.7s |  |
| 17 | `array_access_no_pubns` | 2 | 3.7s |  |
| 18 | `array_concat` | 41 | 3.9s |  |
| 19 | `array_constr` | 10 | 3.7s |  |
| 20 | `array_delete` | 44 | 3.9s |  |
| 21 | `array_enumeration` | 10 | 3.7s |  |
| 22 | `array_enumeration_elements` | 11 | 3.7s |  |
| 23 | `array_every` | 8 | 3.7s |  |
| 24 | `array_filter` | 6 | 3.8s |  |
| 25 | `array_foreach` | 18 | 3.7s |  |
| 26 | `array_hasownproperty` | 11 | 1.9s |  |
| 27 | `array_holes` | 9 | 3.8s |  |
| 28 | `array_index_max` | 84 | 3.5s |  |
| 29 | `array_indexof` | 25 | 3.8s |  |
| 30 | `array_join` | 26 | 3.7s |  |
| 31 | `array_lastindexof` | 29 | 3.7s |  |
| 32 | `array_length` | 14 | 3.7s |  |
| 33 | `array_literal` | 3 | 3.8s |  |
| 34 | `array_map` | 8 | 3.5s |  |
| 35 | `array_pop` | 52 | 3.8s |  |
| 36 | `array_push` | 24 | 3.7s |  |
| 37 | `array_reborrow_bug` | 6 | 3.7s |  |
| 38 | `array_reverse` | 28 | 3.7s |  |
| 39 | `array_shift` | 51 | 1.9s |  |
| 40 | `array_slice` | 39 | 3.8s |  |
| 41 | `array_some` | 8 | 3.7s |  |
| 42 | `array_sort` | 297 | 4.0s |  |
| 43 | `array_sort_fun_swf12` | 2 | 3.7s |  |
| 44 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 45 | `array_sort_random` | 210 | 3.8s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 3.7s |  |
| 47 | `array_sorton` | 545 | 3.3s |  |
| 48 | `array_sparse_ops` | 41 | 3.0s |  |
| 49 | `array_splice` | 133 | 3.0s |  |
| 50 | `array_splice2` | 428 | 3.1s |  |
| 51 | `array_splice_types` | 48 | 3.1s |  |
| 52 | `array_storage` | 8 | 2.9s |  |
| 53 | `array_tolocalestring` | 9 | 2.9s |  |
| 54 | `array_tostring` | 12 | 2.9s |  |
| 55 | `array_unshift` | 24 | 2.9s |  |
| 56 | `array_valueof` | 9 | 2.9s |  |
| 57 | `array_vector_null_callback` | 10 | 2.9s |  |
| 58 | `astype` | 28 | 2.9s |  |
| 59 | `astypelate` | 24 | 3.0s |  |
| 60 | `astypelate_propagates` | 1 | 3.0s |  |
| 61 | `asymmetric_key_events` | 11 | 3.0s |  |
| 62 | `avm2_catchup_dobj` | 158 | 3.4s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 52.8s |  |
| 64 | `bitand` | 1058 | 4.4s |  |
| 65 | `bitmap_constr` | 17 | 3.0s |  |
| 66 | `bitmap_data` | 1000 | 6.1s |  |
| 67 | `bitmap_properties` | 23 | 3.0s |  |
| 68 | `bitmap_timeline` | 9 | 3.0s |  |
| 69 | `bitmapdata_accuracy` | 1 | 40.9s |  |
| 70 | `bitmapdata_applyfilter_blur` | 0 | 18.4s |  |
| 71 | `bitmapdata_applyfilter_colormatrix` | 0 | 3.1s |  |
| 72 | `bitmapdata_applyfilter_destpoint` | 0 | 18.4s |  |
| 73 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 18.4s |  |
| 74 | `bitmapdata_clone` | 13 | 3.0s |  |
| 75 | `bitmapdata_colortransform` | 0 | 3.0s |  |
| 76 | `bitmapdata_colortransform_oob` | 2 | 2.9s |  |
| 77 | `bitmapdata_constr` | 22 | 2.9s |  |
| 78 | `bitmapdata_constructor_from_timeline` | 1 | 3.1s |  |
| 79 | `bitmapdata_copychannel` | 0 | 34.1s |  |
| 80 | `bitmapdata_copypixels` | 23 | 22.0s |  |
| 81 | `bitmapdata_copypixels_blend_over` | 1 | 3.9s |  |
| 82 | `bitmapdata_copypixelstobytearray` | 39 | 3.7s |  |
| 83 | `bitmapdata_dispose` | 7 | 3.7s |  |
| 84 | `bitmapdata_draw` | 0 | 22.0s |  |
| 85 | `bitmapdata_draw_colortransform` | 0 | 3.8s |  |
| 86 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 22.3s |  |
| 87 | `bitmapdata_draw_filters` | 0 | 22.1s |  |
| 88 | `bitmapdata_draw_masks` | 0 | 3.7s |  |
| 89 | `bitmapdata_draw_rotation` | 0 | 3.7s |  |
| 90 | `bitmapdata_draw_self_via_graphic` | 0 | 3.7s |  |
| 91 | `bitmapdata_draw_stage` | 0 | 21.8s |  |
| 92 | `bitmapdata_drawwithquality` | 0 | 4.0s |  |
| 93 | `bitmapdata_embedded` | 9 | 3.8s |  |
| 94 | `bitmapdata_fillrect` | 0 | 3.8s |  |
| 95 | `bitmapdata_filter_sourcerect` | 0 | 21.9s |  |
| 96 | `bitmapdata_floodfill` | 35 | 3.7s |  |
| 97 | `bitmapdata_getpixels` | 39 | 21.9s |  |
| 98 | `bitmapdata_getvector` | 27 | 2.0s |  |
| 99 | `bitmapdata_histogram` | 59 | 1.8s |  |
| 100 | `bitmapdata_hittest` | 112 | 4.1s |  |
| 101 | `bitmapdata_hittest_threshold` | 18 | 3.7s |  |
| 102 | `bitmapdata_opaque` | 0 | 3.8s |  |
| 103 | `bitmapdata_pixeldissolve` | 1037 | 4.2s |  |
| 104 | `bitmapdata_pixeldissolve_image` | 0 | 4.0s |  |
| 105 | `bitmapdata_rectangle_rounding` | 16 | 3.8s |  |
| 106 | `bitmapdata_setpixels` | 286 | 3.8s |  |
| 107 | `bitmapdata_setvector` | 26 | 3.6s |  |
| 108 | `bitmapdata_sync` | 0 | 3.9s |  |
| 109 | `bitmapdata_threshold` | 176 | 4.3s |  |
| 110 | `bitmapdata_zero_size` | 5 | 3.6s |  |
| 111 | `bitnot` | 46 | 3.7s |  |
| 112 | `bitor` | 1058 | 5.8s |  |
| 113 | `bitxor` | 1058 | 5.8s |  |
| 114 | `blend_multiply_alpha` | 0 | 3.7s |  |
| 115 | `blend_scroll` | 0 | 3.7s |  |
| 116 | `boolean_constr` | 32 | 4.1s |  |
| 117 | `boolean_negation` | 30 | 4.0s |  |
| 118 | `boolean_tostring` | 8 | 4.0s |  |
| 119 | `broadcast_event` | 7 | 3.9s |  |
| 120 | `button_nested_frame` | 48 | 24.3s |  |
| 121 | `bytearray` | 48 | 4.3s |  |
| 122 | `bytearray_compress` | 31 | 4.1s |  |
| 123 | `bytearray_errors` | 24 | 4.1s |  |
| 124 | `bytearray_method_serialization` | 1 | 4.0s |  |
| 125 | `bytearray_readobject_amf0` | 50 | 4.0s |  |
| 126 | `bytearray_readobject_amf3` | 53 | 4.0s |  |
| 127 | `bytearray_readutf8bytes_with_bom` | 16 | 4.1s |  |
| 128 | `bytearray_serialization` | 3 | 4.0s |  |
| 129 | `bytearray_string_null` | 19 | 4.2s |  |
| 130 | `bytearray_tostring` | 15 | 4.0s |  |
| 131 | `bytearray_utf16` | 8 | 4.0s |  |
| 132 | `bytearray_writeobject` | 24 | 3.8s |  |
| 133 | `callee_in_initializer` | 6 | 3.9s |  |
| 134 | `callproplex_class` | 1 | 4.0s |  |
| 135 | `catch_class` | 6 | 3.9s |  |
| 136 | `catch_scope_slot` | 7 | 4.1s |  |
| 137 | `checkfilter` | 4 | 2.0s |  |
| 138 | `class_call` | 32 | 4.0s |  |
| 139 | `class_cast_call` | 14 | 4.0s |  |
| 140 | `class_enumeration` | 4 | 4.0s |  |
| 141 | `class_has_own_property` | 2 | 4.0s |  |
| 142 | `class_init_interpreter_mode` | 1 | 3.9s |  |
| 143 | `class_is` | 32 | 4.1s |  |
| 144 | `class_methods` | 5 | 4.0s |  |
| 145 | `class_object_properties` | 10 | 4.1s |  |
| 146 | `class_singleton` | 18 | 4.0s |  |
| 147 | `class_supercalls_errors` | 35 | 4.2s |  |
| 148 | `class_supercalls_mismatched` | 26 | 13.8s |  |
| 149 | `class_superclass_wrong_order` | 1 | 3.8s |  |
| 150 | `class_to_locale_string` | 2 | 3.8s |  |
| 151 | `class_to_string` | 2 | 3.7s |  |
| 152 | `class_value_of` | 2 | 3.8s |  |
| 153 | `click_block` | 5 | 22.7s |  |
| 154 | `click_invisible` | 3 | 3.9s |  |
| 155 | `closures` | 12 | 3.8s |  |
| 156 | `coerce_property` | 33 | 3.9s |  |
| 157 | `coerce_return_type` | 40 | 3.9s |  |
| 158 | `coerce_return_type_fail` | 2 | 3.7s |  |
| 159 | `coerce_return_void` | 3 | 3.7s |  |
| 160 | `coerce_string` | 86 | 3.9s |  |
| 161 | `coerce_string_precision` | 28 | 3.8s |  |
| 162 | `coerce_to_primitive_side_effects` | 29 | 3.9s |  |
| 163 | `construct_errors_swf10` | 8 | 3.8s |  |
| 164 | `construct_frame_list` | 22 | 23.0s |  |
| 165 | `constructor_call` | 3 | 3.8s |  |
| 166 | `constructors_vs_timeline` | 5 | 22.8s |  |
| 167 | `constructprop_dynamic_primitive` | 7 | 3.9s |  |
| 168 | `control_flow_bool` | 4 | 3.8s |  |
| 169 | `control_flow_stricteq` | 8 | 3.8s |  |
| 170 | `convert_boolean` | 30 | 3.8s |  |
| 171 | `convert_integer` | 90 | 3.9s |  |
| 172 | `convert_number` | 56 | 3.9s |  |
| 173 | `convert_uinteger` | 90 | 3.9s |  |
| 174 | `cryptscore` | 11 | 14.3s |  |
| 175 | `declocal` | 46 | 4.0s |  |
| 176 | `declocal_i` | 46 | 4.0s |  |
| 177 | `decrement` | 46 | 4.0s |  |
| 178 | `decrement_i` | 46 | 2.0s |  |
| 179 | `default_values` | 7 | 4.0s |  |
| 180 | `dictionary_access` | 62 | 4.1s |  |
| 181 | `dictionary_access_no_pubns` | 2 | 4.0s |  |
| 182 | `dictionary_delete` | 101 | 4.2s |  |
| 183 | `dictionary_foreach` | 42 | 4.1s |  |
| 184 | `dictionary_hasownproperty` | 63 | 4.1s |  |
| 185 | `dictionary_in` | 62 | 4.1s |  |
| 186 | `dictionary_iter_modify` | 8 | 4.0s |  |
| 187 | `dictionary_namespaces` | 36 | 4.0s |  |
| 188 | `dictionary_primitive_keys` | 29 | 4.0s |  |
| 189 | `displayobject_alpha` | 277 | 3.9s |  |
| 190 | `displayobject_blendmode` | 0 | 24.2s |  |
| 191 | `displayobject_colortransform_nested` | 0 | 24.6s |  |
| 192 | `displayobject_from_enterframe` | 1 | 24.2s |  |
| 193 | `displayobject_getbounds_shape` | 0 | 24.1s |  |
| 194 | `displayobject_height` | 6052 | 24.0s |  |
| 195 | `displayobject_hittestobject` | 32 | 4.0s |  |
| 196 | `displayobject_invalid_floats` | 60 | 4.0s |  |
| 197 | `displayobject_invalid_props` | 3 | 13.0s |  |
| 198 | `displayobject_mask` | 3 | 3.6s |  |
| 199 | `displayobject_mask_self_referential` | 0 | 3.6s |  |
| 200 | `displayobject_metaData` | 3 | 3.6s |  |
| 201 | `displayobject_name` | 22 | 21.0s |  |
| 202 | `displayobject_name_from_timeline` | 24 | 3.7s |  |
| 203 | `displayobject_parent` | 12 | 3.6s |  |
| 204 | `displayobject_root` | 24 | 3.5s |  |
| 205 | `displayobject_rotation` | 1275 | 3.6s |  |
| 206 | `displayobject_set_matrix_nested` | 0 | 21.4s |  |
| 207 | `displayobject_subclass` | 2 | 3.7s |  |
| 208 | `displayobject_visible` | 23 | 3.6s |  |
| 209 | `displayobject_width` | 4852 | 21.7s |  |
| 210 | `displayobject_x` | 614 | 3.5s |  |
| 211 | `displayobject_y` | 617 | 3.7s |  |
| 212 | `displayobjectcontainer_addchild` | 32 | 3.7s |  |
| 213 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 3.6s |  |
| 214 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 3.8s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 3.7s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 3.7s |  |
| 217 | `displayobjectcontainer_addchildat` | 42 | 3.7s |  |
| 218 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.7s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 3.8s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 3.8s |  |
| 221 | `displayobjectcontainer_contains` | 66 | 3.9s |  |
| 222 | `displayobjectcontainer_getchildat` | 4 | 3.7s |  |
| 223 | `displayobjectcontainer_getchildbyname` | 9 | 3.6s |  |
| 224 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 3.6s |  |
| 225 | `displayobjectcontainer_getchildindex` | 28 | 3.6s |  |
| 226 | `displayobjectcontainer_removechild` | 10 | 3.6s |  |
| 227 | `displayobjectcontainer_removechild_errors` | 4 | 3.6s |  |
| 228 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 3.6s |  |
| 229 | `displayobjectcontainer_removechildat` | 18 | 3.6s |  |
| 230 | `displayobjectcontainer_removechildren` | 51 | 3.8s |  |
| 231 | `displayobjectcontainer_setchildindex` | 42 | 3.4s |  |
| 232 | `displayobjectcontainer_stopallmovieclips` | 2 | 11.5s |  |
| 233 | `displayobjectcontainer_swapchildren` | 42 | 3.8s |  |
| 234 | `displayobjectcontainer_swapchildrenat` | 42 | 3.5s |  |
| 235 | `displayobjectcontainer_timelineinstance` | 48 | 18.5s |  |
| 236 | `divide` | 1058 | 4.7s |  |
| 237 | `doabc_is_eager` | 1 | 17.6s |  |
| 238 | `documentclass` | 9 | 3.3s |  |
| 239 | `drag_drop` | 10 | 3.3s |  |
| 240 | `duplicate_defs` | 1 | 3.1s |  |
| 241 | `eager_init` | 1 | 3.0s |  |
| 242 | `edit_text_linkage` | 7 | 3.4s |  |
| 243 | `edittext_align` | 60 | 3.6s |  |
| 244 | `edittext_always_show_selection` | 0 | 19.7s |  |
| 245 | `edittext_antialiastype` | 296 | 3.4s |  |
| 246 | `edittext_at_point_methods_basic` | 16 | 4.1s |  |
| 247 | `edittext_autosize` | 39 | 3.7s |  |
| 248 | `edittext_autosize_align` | 0 | 18.5s |  |
| 249 | `edittext_autosize_height_dynamic` | 60 | 17.7s |  |
| 250 | `edittext_autosize_height_input` | 60 | 3.6s |  |
| 251 | `edittext_autosize_lazy_bounds_events` | 65 | 3.8s |  |
| 252 | `edittext_autosize_lazy_bounds_interactions` | 19 | 3.0s |  |
| 253 | `edittext_autosize_lazy_bounds_props` | 490 | 4.7s |  |
| 254 | `edittext_autosize_lazy_bounds_visual` | 0 | 17.7s |  |
| 255 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 3.4s |  |
| 256 | `edittext_bottom_scroll_v_basic` | 210 | 4.0s |  |
| 257 | `edittext_bounds_scale` | 24 | 17.6s |  |
| 258 | `edittext_bullet` | 30 | 3.1s |  |
| 259 | `edittext_default_format` | 221 | 3.3s |  |
| 260 | `edittext_default_format_empty` | 136 | 3.6s |  |
| 261 | `edittext_empty_text_format` | 7 | 3.2s |  |
| 262 | `edittext_focus_selection` | 5 | 3.2s |  |
| 263 | `edittext_font_size` | 45 | 3.4s |  |
| 264 | `edittext_format_empty_font` | 8 | 3.1s |  |
| 265 | `edittext_get_char_index_at_point` | 4 | 19.1s |  |
| 266 | `edittext_get_line_index_at_point` | 2 | 33.5s |  |
| 267 | `edittext_get_line_index_of_char` | 76 | 5.1s |  |
| 268 | `edittext_getcharboundaries` | 172 | 4.3s |  |
| 269 | `edittext_getcharboundaries_missing_glyphs` | 63 | 4.0s |  |
| 270 | `edittext_getcharboundaries_scroll` | 85 | 4.0s |  |
| 271 | `edittext_getlinemetrics` | 146 | 4.1s |  |
| 272 | `edittext_html` | 3101 | 4.2s |  |
| 273 | `edittext_html_condensewhite` | 487 | 4.0s |  |
| 274 | `edittext_html_entity` | 4 | 4.0s |  |
| 275 | `edittext_html_font_size_swf12` | 267 | 4.0s |  |
| 276 | `edittext_html_font_size_swf13` | 273 | 3.6s |  |
| 277 | `edittext_html_roundtrip` | 17 | 4.0s |  |
| 278 | `edittext_input_control` | 12 | 4.1s |  |
| 279 | `edittext_leading` | 9 | 4.1s |  |
| 280 | `edittext_letter_spacing` | 15 | 3.9s |  |
| 281 | `edittext_line_methods` | 294 | 5.0s |  |
| 282 | `edittext_line_metrics` | 11 | 24.6s |  |
| 283 | `edittext_margins` | 25 | 4.0s |  |
| 284 | `edittext_max_scroll_h_basic` | 475 | 4.3s |  |
| 285 | `edittext_max_scroll_v_basic` | 1000 | 4.1s |  |
| 286 | `edittext_mousedown` | 3 | 4.4s |  |
| 287 | `edittext_mouseenabled` | 26 | 3.9s |  |
| 288 | `edittext_newline_character` | 22 | 4.0s |  |
| 289 | `edittext_newline_stripping` | 64 | 5.8s |  |
| 290 | `edittext_newlines` | 30 | 4.0s |  |
| 291 | `edittext_paragraph_methods` | 257 | 4.0s |  |
| 292 | `edittext_paste_events` | 8 | 4.1s |  |
| 293 | `edittext_paste_maxchars` | 4 | 3.9s |  |
| 294 | `edittext_paste_restrict` | 16 | 3.8s |  |
| 295 | `edittext_restrict` | 191 | 4.0s |  |
| 296 | `edittext_restrict_events` | 22 | 3.9s |  |
| 297 | `edittext_scrollh` | 10 | 3.8s |  |
| 298 | `edittext_selected_text` | 9 | 3.9s |  |
| 299 | `edittext_set_html_same` | 17 | 3.9s |  |
| 300 | `edittext_set_text_vs_html` | 9 | 3.9s |  |
| 301 | `edittext_stylesheet` | 536 | 4.2s |  |
| 302 | `edittext_stylesheet_custom_tag` | 76 | 14.0s |  |
| 303 | `edittext_stylesheet_display` | 272 | 4.0s |  |
| 304 | `edittext_underline` | 40 | 3.9s |  |
| 305 | `edittext_width_height` | 103 | 4.0s |  |
| 306 | `edittext_wordwrap_word` | 150 | 4.2s |  |
| 307 | `edittext_wrap_breaks` | 2375 | 4.5s |  |
| 308 | `empty_bounds` | 1 | 3.8s |  |
| 309 | `equals` | 512 | 4.9s |  |
| 310 | `error_prototype` | 15 | 4.0s |  |
| 311 | `error_stack_trace_debug_swf17` | 0 | 22.6s |  |
| 312 | `error_stack_trace_debug_swf18` | 0 | 3.7s |  |
| 313 | `error_stack_trace_release_swf17` | 0 | 3.7s |  |
| 314 | `error_stack_trace_release_swf18` | 0 | 3.6s |  |
| 315 | `error_tostring` | 29 | 4.0s |  |
| 316 | `es3_inheritance` | 31 | 4.0s |  |
| 317 | `es4_inheritance` | 30 | 4.0s |  |
| 318 | `es4_interfaces` | 30 | 4.0s |  |
| 319 | `es4_method_binding` | 8 | 3.9s |  |
| 320 | `es4_oop_prototypes` | 14 | 4.0s |  |
| 321 | `es4_protected_inheritance` | 6 | 4.0s |  |
| 322 | `event_bubbles` | 2 | 3.9s |  |
| 323 | `event_cancelable` | 2 | 3.9s |  |
| 324 | `event_clone` | 20 | 4.0s |  |
| 325 | `event_clone_error_redispatch` | 3 | 4.1s |  |
| 326 | `event_clone_on_redispatch` | 10 | 14.0s |  |
| 327 | `event_formattostring` | 31 | 3.9s |  |
| 328 | `event_handler_exception` | 4 | 3.9s |  |
| 329 | `event_isdefaultprevented` | 12 | 3.8s |  |
| 330 | `event_target_getter` | 5 | 3.9s |  |
| 331 | `event_target_set` | 9 | 3.8s |  |
| 332 | `event_type` | 1 | 3.8s |  |
| 333 | `event_valueof_tostring` | 18 | 3.9s |  |
| 334 | `eventdispatcher_dispatchevent` | 12 | 3.8s |  |
| 335 | `eventdispatcher_dispatchevent_cancel` | 20 | 3.8s |  |
| 336 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 3.8s |  |
| 337 | `eventdispatcher_dispatchevent_indirect` | 9 | 3.9s |  |
| 338 | `eventdispatcher_dispatchevent_this` | 5 | 3.8s |  |
| 339 | `eventdispatcher_haseventlistener` | 25 | 3.9s |  |
| 340 | `eventdispatcher_interface_invoke` | 1 | 3.8s |  |
| 341 | `eventdispatcher_tostring` | 10 | 3.8s |  |
| 342 | `eventdispatcher_willtrigger` | 25 | 3.7s |  |
| 343 | `falsiness` | 30 | 3.8s |  |
| 344 | `fast_index_access` | 12 | 4.0s |  |
| 345 | `finddef` | 3 | 3.8s |  |
| 346 | `findprop_global_prototype` | 6 | 3.9s |  |
| 347 | `flash_xml` | 29 | 3.9s |  |
| 348 | `flash_xml_cloneNode` | 22 | 3.8s |  |
| 349 | `flash_xml_namespace` | 109 | 3.8s |  |
| 350 | `flash_xml_removeNode` | 60 | 14.0s |  |
| 351 | `focus_events_code` | 161 | 22.7s |  |
| 352 | `focus_events_key_same_object` | 26 | 4.1s |  |
| 353 | `focus_events_mixed_key_mouse` | 100 | 22.4s |  |
| 354 | `focus_events_mouse_same_object` | 40 | 3.9s |  |
| 355 | `focus_remove` | 20 | 22.5s |  |
| 356 | `focus_root_movie` | 4 | 22.7s |  |
| 357 | `focus_stage` | 1 | 4.0s |  |
| 358 | `focusrect` | 18 | 4.7s |  |
| 359 | `font_description_clone` | 14 | 3.9s |  |
| 360 | `font_embedded` | 24 | 4.2s |  |
| 361 | `font_enumeratefonts` | 41 | 4.5s |  |
| 362 | `font_enumeratefonts_filter` | 4 | 4.7s |  |
| 363 | `font_hasglyphs` | 40 | 4.3s |  |
| 364 | `framelabel_constr` | 5 | 4.0s |  |
| 365 | `function_call` | 12 | 4.0s |  |
| 366 | `function_call_arguments` | 46 | 4.1s |  |
| 367 | `function_call_arguments_enumerate` | 5 | 4.0s |  |
| 368 | `function_call_coercion` | 108 | 4.2s |  |
| 369 | `function_call_default` | 6 | 3.9s |  |
| 370 | `function_call_rest` | 22 | 4.0s |  |
| 371 | `function_call_types` | 3 | 3.9s |  |
| 372 | `function_call_via_apply` | 11 | 3.9s |  |
| 373 | `function_call_via_call` | 3 | 3.9s |  |
| 374 | `function_display_anonymous` | 7 | 2.0s |  |
| 375 | `function_length` | 6 | 3.9s |  |
| 376 | `function_object` | 2 | 3.9s |  |
| 377 | `function_proto` | 5 | 3.9s |  |
| 378 | `function_proto_created` | 61 | 4.0s |  |
| 379 | `function_to_locale_string` | 4 | 3.9s |  |
| 380 | `function_to_string` | 4 | 13.6s |  |
| 381 | `function_type` | 6 | 3.8s |  |
| 382 | `function_unbound_this` | 51 | 3.9s |  |
| 383 | `function_value_of` | 4 | 3.7s |  |
| 384 | `get_definition_by_name` | 11 | 3.7s |  |
| 385 | `get_qualified_class_name` | 20 | 3.8s |  |
| 386 | `get_qualified_super_class_name` | 18 | 3.8s |  |
| 387 | `get_slot_edge_cases` | 1 | 3.7s |  |
| 388 | `get_timer` | 2 | 3.8s |  |
| 389 | `getglobalslot` | 1 | 3.6s |  |
| 390 | `getouterscope` | 8 | 3.7s |  |
| 391 | `getter_different_namespace_setter` | 2 | 3.8s |  |
| 392 | `goto_button_nested_framescript` | 28 | 22.5s |  |
| 393 | `goto_in_constructframe` | 12 | 22.5s |  |
| 394 | `goto_in_scene_last_frame` | 2 | 22.0s |  |
| 395 | `goto_methods` | 56 | 3.9s |  |
| 396 | `goto_methods_swfver10` | 8 | 3.7s |  |
| 397 | `goto_nested_construct_sibling` | 18 | 4.2s |  |
| 398 | `goto_nested_framescript` | 9 | 3.9s |  |
| 399 | `goto_on_orphan` | 15 | 3.9s |  |
| 400 | `graphics_bitmap_fill` | 0 | 5.1s |  |
| 401 | `graphics_bitmaps` | 0 | 4.0s |  |
| 402 | `graphics_direct_commands` | 0 | 3.9s |  |
| 403 | `graphics_gradients` | 0 | 3.8s |  |
| 404 | `graphics_gradients_nulls` | 0 | 3.8s |  |
| 405 | `graphics_round_rects` | 0 | 3.8s |  |
| 406 | `graphics_simple_shapes` | 0 | 3.8s |  |
| 407 | `greaterequals` | 512 | 4.8s |  |
| 408 | `greaterthan` | 512 | 15.3s |  |
| 409 | `has_own_property` | 102 | 4.1s |  |
| 410 | `hasownproperty_namespaces` | 2 | 3.9s |  |
| 411 | `hello_world` | 1 | 3.8s |  |
| 412 | `hittest_morph` | 30 | 4.0s |  |
| 413 | `if_eq` | 10 | 3.9s |  |
| 414 | `if_gt` | 1 | 3.9s |  |
| 415 | `if_gte` | 10 | 2.0s |  |
| 416 | `if_lt` | 1 | 0.5s |  |
| 417 | `if_lte` | 10 | 3.7s |  |
| 418 | `if_ne` | 7 | 2.0s |  |
| 419 | `if_stricteq` | 6 | 4.0s |  |
| 420 | `if_strictne` | 11 | 4.0s |  |
| 421 | `in` | 102 | 4.1s |  |
| 422 | `inclocal` | 46 | 3.9s |  |
| 423 | `inclocal_i` | 46 | 3.9s |  |
| 424 | `increment` | 46 | 4.0s |  |
| 425 | `increment_i` | 46 | 3.9s |  |
| 426 | `instanceof` | 58 | 4.0s |  |
| 427 | `instantiation_on_enter_frame` | 7 | 23.6s |  |
| 428 | `instantiation_on_enterframe_gotoandstop` | 8 | 3.9s |  |
| 429 | `int_constr` | 92 | 4.0s |  |
| 430 | `int_edge_cases` | 19 | 4.0s |  |
| 431 | `int_instanceof` | 3 | 3.8s |  |
| 432 | `int_tofixed` | 1215 | 3.8s |  |
| 433 | `int_tostring` | 3375 | 4.0s |  |
| 434 | `interactiveobject_enabled` | 25 | 3.9s |  |
| 435 | `interface_namespaces` | 78 | 4.1s |  |
| 436 | `is_finite` | 46 | 4.0s |  |
| 437 | `is_nan` | 46 | 3.9s |  |
| 438 | `is_prototype_of` | 12 | 4.0s |  |
| 439 | `issue_10221` | 2 | 3.9s |  |
| 440 | `issue_13780` | 12 | 3.9s |  |
| 441 | `issue_14901` | 1 | 13.9s |  |
| 442 | `issue_17675_edittext_paste_maxchars` | 1 | 4.0s |  |
| 443 | `issue_5292` | 5 | 3.9s |  |
| 444 | `issue_8630` | 2 | 3.9s |  |
| 445 | `issue_8630_scriptremove` | 11 | 3.9s |  |
| 446 | `istype` | 24 | 3.9s |  |
| 447 | `istypelate` | 58 | 4.0s |  |
| 448 | `istypelate_coerce` | 198 | 4.3s |  |
| 449 | `json_errors` | 9 | 23.6s |  |
| 450 | `json_parse` | 21 | 3.8s |  |
| 451 | `json_version_gated` | 1 | 3.8s |  |
| 452 | `key_input_80percent` | 1812 | 4.0s |  |
| 453 | `key_input_location` | 126 | 4.0s |  |
| 454 | `key_input_numpad` | 384 | 3.9s |  |
| 455 | `lazyinit` | 17 | 3.9s |  |
| 456 | `lessequals` | 512 | 4.9s |  |
| 457 | `lessthan` | 512 | 4.8s |  |
| 458 | `loaderinfo_properties` | 18 | 23.1s |  |
| 459 | `loaderinfo_root` | 10 | 4.0s |  |
| 460 | `loaderinfo_root_allows` | 2 | 4.0s |  |
| 461 | `lshift` | 1058 | 6.4s |  |
| 462 | `mask_reapply` | 1 | 23.4s |  |
| 463 | `math` | 497 | 4.2s |  |
| 464 | `modulo` | 1058 | 6.4s |  |
| 465 | `mouse_click_events` | 90 | 23.1s |  |
| 466 | `mouse_double_click_events` | 188 | 4.0s |  |
| 467 | `mouse_empty_parent` | 4 | 3.9s |  |
| 468 | `mouse_over_while_dragging` | 3 | 4.0s |  |
| 469 | `mouse_pick_button_mode` | 2 | 4.0s |  |
| 470 | `mouse_sibling` | 8 | 4.2s |  |
| 471 | `movieclip_addframescript` | 3 | 24.3s |  |
| 472 | `movieclip_child_property` | 16 | 4.2s |  |
| 473 | `movieclip_constr` | 21 | 4.0s |  |
| 474 | `movieclip_currentlabels` | 17 | 24.1s |  |
| 475 | `movieclip_currentlabels_dupes1` | 46 | 23.1s |  |
| 476 | `movieclip_currentlabels_dupes2` | 30 | 4.0s |  |
| 477 | `movieclip_currentlabels_dupes3` | 67 | 4.0s |  |
| 478 | `movieclip_currentscene` | 12 | 23.3s |  |
| 479 | `movieclip_dispatchevent` | 430 | 4.1s |  |
| 480 | `movieclip_dispatchevent_cancel` | 102 | 4.1s |  |
| 481 | `movieclip_dispatchevent_handlerorder` | 251 | 4.1s |  |
| 482 | `movieclip_dispatchevent_selfadd` | 80 | 4.1s |  |
| 483 | `movieclip_dispatchevent_target` | 899 | 4.1s |  |
| 484 | `movieclip_displayevents` | 96 | 24.0s |  |
| 485 | `movieclip_displayevents_clickgoto` | 676 | 24.4s |  |
| 486 | `movieclip_displayevents_clickgoto2` | 2001 | 4.5s |  |
| 487 | `movieclip_displayevents_clickplay` | 575 | 4.2s |  |
| 488 | `movieclip_displayevents_clicksymbol` | 562 | 4.3s |  |
| 489 | `movieclip_displayevents_constructframegoto` | 140 | 4.4s |  |
| 490 | `movieclip_displayevents_constructframeplay` | 50 | 4.3s |  |
| 491 | `movieclip_displayevents_constructframesymbol` | 144 | 4.2s |  |
| 492 | `movieclip_displayevents_dblhandler` | 21 | 4.2s |  |
| 493 | `movieclip_displayevents_enterframegoto` | 149 | 4.3s |  |
| 494 | `movieclip_displayevents_enterframeplay` | 48 | 4.2s |  |
| 495 | `movieclip_displayevents_enterframesymbol` | 149 | 23.9s |  |
| 496 | `movieclip_displayevents_exitframegoto` | 106 | 4.1s |  |
| 497 | `movieclip_displayevents_exitframeplay` | 44 | 4.1s |  |
| 498 | `movieclip_displayevents_exitframesymbol` | 135 | 4.2s |  |
| 499 | `movieclip_displayevents_looping` | 63 | 23.7s |  |
| 500 | `movieclip_displayevents_stopped` | 113 | 4.4s |  |
| 501 | `movieclip_displayevents_swap` | 96 | 1.9s |  |
| 502 | `movieclip_displayevents_timeline` | 128 | 23.1s |  |
| 503 | `movieclip_drawrect` | 54 | 3.9s |  |
| 504 | `movieclip_frameconstruct_skipped` | 9 | 13.5s |  |
| 505 | `movieclip_goto_during_frame_script` | 15 | 21.7s |  |
| 506 | `movieclip_goto_overwrite` | 14 | 21.7s |  |
| 507 | `movieclip_goto_scene_last_frame_int` | 1 | 22.1s |  |
| 508 | `movieclip_goto_scene_last_frame_label` | 1 | 3.6s |  |
| 509 | `movieclip_gotoandplay` | 15 | 21.6s |  |
| 510 | `movieclip_gotoandstop` | 13 | 3.7s |  |
| 511 | `movieclip_gotoandstop_children` | 4 | 3.9s |  |
| 512 | `movieclip_gotoandstop_framescripts1` | 4 | 3.7s |  |
| 513 | `movieclip_gotoandstop_framescripts2` | 4 | 1.8s |  |
| 514 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.1s |  |
| 515 | `movieclip_gotoandstop_queueing` | 12 | 3.8s |  |
| 516 | `movieclip_next_frame` | 2 | 3.7s |  |
| 517 | `movieclip_next_scene` | 6 | 21.5s |  |
| 518 | `movieclip_play` | 3 | 3.6s |  |
| 519 | `movieclip_prev_frame` | 3 | 3.4s |  |
| 520 | `movieclip_prev_scene` | 7 | 3.7s |  |
| 521 | `movieclip_properties` | 79 | 21.6s |  |
| 522 | `movieclip_queued_noop_goto_swf10` | 9 | 3.7s |  |
| 523 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 524 | `movieclip_scenes` | 11 | 3.6s |  |
| 525 | `movieclip_soundtransform` | 831 | 22.9s |  |
| 526 | `movieclip_stop` | 1 | 21.3s |  |
| 527 | `movieclip_super_is_symbol` | 20 | 4.0s |  |
| 528 | `movieclip_symbol_constr` | 8 | 3.8s |  |
| 529 | `movieclip_text_mousedown` | 1 | 3.7s |  |
| 530 | `movieclip_willtrigger` | 5 | 3.8s |  |
| 531 | `multiply` | 1058 | 5.7s |  |
| 532 | `namespace_constr` | 253 | 4.0s |  |
| 533 | `namespace_constr_args` | 1 | 3.6s |  |
| 534 | `namespace_enumeration_order` | 7 | 3.7s |  |
| 535 | `nan_scale` | 9 | 3.6s |  |
| 536 | `negate` | 30 | 3.7s |  |
| 537 | `negative_volume_panned` | 0 | 3.8s |  |
| 538 | `nested_iteration` | 11 | 3.7s |  |
| 539 | `net_getClassByAlias` | 3 | 3.7s |  |
| 540 | `newactivation_in_script_init` | 3 | 2.6s |  |
| 541 | `newclass_twice` | 3 | 2.4s |  |
| 542 | `nonconflicting_declarations` | 0 | 3.0s |  |
| 543 | `null_void_types` | 8 | 2.6s |  |
| 544 | `number_autoconv` | 21 | 2.6s |  |
| 545 | `number_autoconv_amf` | 132 | 2.7s |  |
| 546 | `number_autoconv_array_sort_32bit` | 1 | 2.6s |  |
| 547 | `number_constr` | 58 | 2.6s |  |
| 548 | `number_toexponential` | 378 | 2.7s |  |
| 549 | `number_toexponential2` | 35 | 2.5s |  |
| 550 | `number_tofixed` | 378 | 2.4s |  |
| 551 | `number_toprecision` | 350 | 2.5s |  |
| 552 | `obfuscated_class_names` | 3 | 2.6s |  |
| 553 | `object_enumeration` | 10 | 2.7s |  |
| 554 | `object_prototype` | 4 | 2.5s |  |
| 555 | `object_to_locale_string` | 2 | 2.4s |  |
| 556 | `object_to_string` | 2 | 2.4s |  |
| 557 | `object_value_of` | 2 | 0.9s |  |
| 558 | `op_coerce` | 54 | 2.6s |  |
| 559 | `op_coerce_x` | 54 | 2.8s |  |
| 560 | `op_escxattr` | 2 | 2.5s |  |
| 561 | `op_escxelem` | 2 | 2.4s |  |
| 562 | `op_lookupswitch` | 4 | 2.9s |  |
| 563 | `optimize_coerce` | 1 | 2.4s |  |
| 564 | `orphan_movie_complex` | 80 | 2.7s |  |
| 565 | `orphan_movie_reorder` | 111 | 16.0s |  |
| 566 | `package_namespace` | 7 | 3.9s |  |
| 567 | `param_default_value_has_zero_cpool_index` | 1 | 3.7s |  |
| 568 | `parent_early_access_child` | 16 | 22.7s |  |
| 569 | `parse_float` | 80 | 4.0s |  |
| 570 | `pixelbender_effect_BlurredFocus` | 0 | 25.1s |  |
| 571 | `pixelbender_effect_glassDisplace` | 0 | 8.9s |  |
| 572 | `pixelbender_effect_smudge` | 0 | 6.5s |  |
| 573 | `pixelbender_effect_tintype` | 0 | 5.8s |  |
| 574 | `pixelbender_effect_twirl` | 0 | 7.1s |  |
| 575 | `pixelbender_images` | 0 | 5.4s |  |
| 576 | `place_multiple` | 17 | 2.8s |  |
| 577 | `place_object_replace` | 9 | 2.7s |  |
| 578 | `place_object_replace_2` | 24 | 15.5s |  |
| 579 | `place_object_same_depth_frame` | 1 | 2.9s |  |
| 580 | `primitive_edge_cases` | 1 | 2.5s |  |
| 581 | `property_priority` | 22 | 3.3s |  |
| 582 | `property_priority_three_level` | 6 | 3.1s |  |
| 583 | `propertyisenumerable_namespaces` | 6 | 2.8s |  |
| 584 | `prototype_set_null` | 7 | 3.2s |  |
| 585 | `proxy_callproperty` | 24 | 2.8s |  |
| 586 | `proxy_deleteproperty` | 64 | 2.6s |  |
| 587 | `proxy_enumeration` | 34 | 2.4s |  |
| 588 | `proxy_getproperty` | 77 | 2.5s |  |
| 589 | `proxy_hasownproperty` | 8 | 2.5s |  |
| 590 | `proxy_hasproperty` | 32 | 2.6s |  |
| 591 | `proxy_serialize` | 9 | 2.5s |  |
| 592 | `proxy_setproperty` | 42 | 2.5s |  |
| 593 | `qname_as_lazy_name_attribute_multiname` | 1 | 2.4s |  |
| 594 | `qname_constr` | 32 | 2.5s |  |
| 595 | `qname_constr_namespace` | 24 | 2.9s |  |
| 596 | `qname_enumeration` | 9 | 3.0s |  |
| 597 | `qname_indexing` | 23 | 2.8s |  |
| 598 | `qname_tostring` | 25 | 2.6s |  |
| 599 | `qname_valueof` | 29 | 2.9s |  |
| 600 | `regexp_constr` | 148 | 3.2s |  |
| 601 | `regexp_exec` | 19 | 3.0s |  |
| 602 | `regexp_extended` | 47 | 2.6s |  |
| 603 | `regexp_multiargs` | 1 | 2.9s |  |
| 604 | `regexp_test` | 27 | 11.1s |  |
| 605 | `regexp_toString` | 10 | 3.2s |  |
| 606 | `register_script_refresh` | 35 | 18.4s |  |
| 607 | `remove_child_clear_field` | 88 | 18.4s |  |
| 608 | `remove_dobj` | 3 | 3.0s |  |
| 609 | `resolve_order` | 4 | 3.1s |  |
| 610 | `rng` | 1 | 4.4s |  |
| 611 | `rootless` | 42 | 3.1s |  |
| 612 | `rshift` | 1058 | 5.0s |  |
| 613 | `sandbox_type_local_file` | 1 | 3.2s |  |
| 614 | `scene_constr` | 8 | 3.0s |  |
| 615 | `set_property_is_enumerable` | 85 | 3.2s |  |
| 616 | `shape_drawrect` | 54 | 3.3s |  |
| 617 | `shared_object_no_root` | 3 | 3.0s |  |
| 618 | `simplebutton_added_to_stage` | 45 | 17.4s |  |
| 619 | `simplebutton_childevents` | 86 | 17.7s |  |
| 620 | `simplebutton_childevents_nested` | 54 | 3.2s |  |
| 621 | `simplebutton_childevents_sprite` | 13 | 3.1s |  |
| 622 | `simplebutton_childprops` | 144 | 3.2s |  |
| 623 | `simplebutton_childshuffle` | 23 | 3.0s |  |
| 624 | `simplebutton_constr` | 36 | 3.4s |  |
| 625 | `simplebutton_constr_childevents` | 48 | 3.2s |  |
| 626 | `simplebutton_constr_params` | 42 | 3.1s |  |
| 627 | `simplebutton_mouseenabled` | 26 | 3.0s |  |
| 628 | `simplebutton_multi_children` | 19 | 3.2s |  |
| 629 | `simplebutton_structure` | 27 | 3.2s |  |
| 630 | `simplebutton_symbolclass` | 68 | 3.3s |  |
| 631 | `slot_disp_id_shared_numbering` | 1 | 31.1s |  |
| 632 | `slots_force_autoassigned` | 1 | 3.7s |  |
| 633 | `sound_embeddedprops` | 26 | 3.8s |  |
| 634 | `sound_play` | 19 | 3.9s |  |
| 635 | `sound_valueof` | 33 | 3.7s |  |
| 636 | `soundchannel_soundtransform` | 835 | 22.9s |  |
| 637 | `soundchannel_soundtransform_exists` | 5 | 21.7s |  |
| 638 | `soundchannel_stop` | 8 | 21.6s |  |
| 639 | `soundmixer_buffertime` | 5 | 3.7s |  |
| 640 | `soundmixer_stopall` | 6 | 21.6s |  |
| 641 | `soundtransform` | 442 | 4.5s |  |
| 642 | `sprite_with_frames` | 0 | 21.7s |  |
| 643 | `stage3d_agal_cross_product` | 0 | 4.9s |  |
| 644 | `stage3d_bitmap` | 0 | 24.6s |  |
| 645 | `stage3d_float1_index` | 0 | 23.1s |  |
| 646 | `stage3d_fractal` | 0 | 16.0s |  |
| 647 | `stage3d_ignore_sampler_override` | 0 | 23.6s |  |
| 648 | `stage3d_program_constants_bytearray_be` | 0 | 23.3s |  |
| 649 | `stage3d_program_constants_bytearray_le` | 0 | 5.5s |  |
| 650 | `stage3d_raytrace` | 0 | 22.4s |  |
| 651 | `stage3d_rotating_cube` | 0 | 5.5s |  |
| 652 | `stage3d_sampler` | 0 | 5.1s |  |
| 653 | `stage3d_sampler_partial_upload` | 0 | 5.0s |  |
| 654 | `stage3d_stencil` | 0 | 23.1s |  |
| 655 | `stage3d_texture` | 0 | 9.1s |  |
| 656 | `stage3d_texture_bytearray` | 0 | 6.0s |  |
| 657 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 5.6s |  |
| 658 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 6.8s |  |
| 659 | `stage3d_triangle` | 0 | 5.0s |  |
| 660 | `stage3d_triangle_bytes4` | 0 | 5.0s |  |
| 661 | `stage3d_triangle_float1` | 0 | 5.0s |  |
| 662 | `stage3d_triangle_index_upload` | 0 | 5.0s |  |
| 663 | `stage_access` | 10 | 3.8s |  |
| 664 | `stage_displayobject_properties` | 24 | 3.6s |  |
| 665 | `stage_framerate_nan` | 7 | 3.9s |  |
| 666 | `stage_framerate_negative` | 6 | 3.7s |  |
| 667 | `stage_framerate_zero` | 6 | 3.7s |  |
| 668 | `stage_invalidate` | 38 | 3.8s |  |
| 669 | `stage_mousechildren` | 2 | 3.7s |  |
| 670 | `stage_mouseenabled` | 15 | 3.6s |  |
| 671 | `stage_overriden_setters` | 31 | 3.8s |  |
| 672 | `stage_properties` | 30 | 3.6s |  |
| 673 | `static_var_with_this_in_ctor` | 2 | 3.7s |  |
| 674 | `stored_properties` | 11 | 13.5s |  |
| 675 | `strict_equality` | 34 | 3.6s |  |
| 676 | `string_call` | 13 | 3.7s |  |
| 677 | `string_case` | 23 | 3.6s |  |
| 678 | `string_char_at` | 27 | 3.6s |  |
| 679 | `string_char_code_at` | 28 | 3.6s |  |
| 680 | `string_concat_fromcharcode` | 36 | 3.7s |  |
| 681 | `string_constr` | 25 | 3.6s |  |
| 682 | `string_indexof_lastindexof` | 87 | 3.7s |  |
| 683 | `string_length` | 16 | 3.6s |  |
| 684 | `string_locale_compare` | 39 | 3.7s |  |
| 685 | `string_match` | 51 | 3.7s |  |
| 686 | `string_relational_compare` | 4 | 3.5s |  |
| 687 | `string_replace` | 51 | 3.7s |  |
| 688 | `string_search` | 41 | 3.8s |  |
| 689 | `string_slice_substr_substring` | 169 | 4.0s |  |
| 690 | `string_split` | 29 | 3.6s |  |
| 691 | `string_substr_negative` | 21 | 3.5s |  |
| 692 | `string_substr_weird` | 182 | 3.5s |  |
| 693 | `subtract` | 1058 | 5.7s |  |
| 694 | `super_get_call` | 12 | 3.6s |  |
| 695 | `supercall_two_classobjects` | 2 | 3.6s |  |
| 696 | `swf8` | 1 | 3.4s |  |
| 697 | `swf_10_queued_goto_scripts_construct` | 52 | 22.4s |  |
| 698 | `swf_9_goto_in_enter_frame` | 17 | 3.7s |  |
| 699 | `swf_9_goto_in_enter_frame_simple` | 15 | 3.7s |  |
| 700 | `swf_9_queued_goto_scripts` | 6 | 22.0s |  |
| 701 | `swf_9_queued_goto_scripts_construct` | 28 | 0.5s |  |
| 702 | `swf_9_versioning` | 2 | 3.6s |  |
| 703 | `swf_wrong_frame_count` | 38 | 3.9s |  |
| 704 | `swf_wrong_frame_count_isplaying` | 22 | 13.5s |  |
| 705 | `symbol_class_conflict` | 4 | 22.1s |  |
| 706 | `symbol_class_root_not_zero` | 1 | 3.6s |  |
| 707 | `symbolclass_invalid_utf8` | 2 | 3.7s |  |
| 708 | `tab_ordering_automatic_advanced` | 184 | 4.2s |  |
| 709 | `tab_ordering_automatic_basic` | 45 | 3.7s |  |
| 710 | `tab_ordering_children` | 116 | 3.8s |  |
| 711 | `tab_ordering_custom_basic` | 34 | 3.7s |  |
| 712 | `text_engine_fontdescription` | 27 | 3.8s |  |
| 713 | `text_run` | 7 | 3.6s |  |
| 714 | `textfield_focusin_event` | 9 | 3.7s |  |
| 715 | `textfield_input_dead_keys_windows` | 15 | 3.8s |  |
| 716 | `textfield_unload` | 39 | 4.1s |  |
| 717 | `textformat` | 1134 | 3.9s |  |
| 718 | `textformat_display` | 14 | 3.8s |  |
| 719 | `textformat_font_max_length` | 4 | 3.8s |  |
| 720 | `throw` | 3 | 3.7s |  |
| 721 | `timeline_scripts` | 3 | 3.9s |  |
| 722 | `timer` | 90 | 4.2s |  |
| 723 | `timer_events` | 3 | 14.1s |  |
| 724 | `timer_finished` | 11 | 4.1s |  |
| 725 | `timer_reset` | 8 | 4.1s |  |
| 726 | `timer_setdelay` | 5 | 4.0s |  |
| 727 | `trace` | 12 | 4.1s |  |
| 728 | `truthiness` | 30 | 4.0s |  |
| 729 | `try_catch` | 11 | 4.1s |  |
| 730 | `try_catch_typed` | 12 | 4.0s |  |
| 731 | `typeof` | 30 | 4.0s |  |
| 732 | `uint_constr` | 92 | 4.0s |  |
| 733 | `uint_tofixed` | 1215 | 3.8s |  |
| 734 | `uint_tostring` | 3375 | 4.0s |  |
| 735 | `uncaught_errors_stringified` | 3 | 4.0s |  |
| 736 | `unchecked_function` | 15 | 3.9s |  |
| 737 | `urlrequest` | 18 | 4.0s |  |
| 738 | `urshift` | 1058 | 6.2s |  |
| 739 | `vector_class` | 36 | 4.2s |  |
| 740 | `vector_class_call` | 11 | 4.0s |  |
| 741 | `vector_coercion` | 66 | 4.5s |  |
| 742 | `vector_concat` | 90 | 4.1s |  |
| 743 | `vector_constr` | 107 | 4.1s |  |
| 744 | `vector_enumeration` | 5 | 3.8s |  |
| 745 | `vector_every` | 92 | 4.3s |  |
| 746 | `vector_filter` | 95 | 4.3s |  |
| 747 | `vector_holes` | 24 | 3.9s |  |
| 748 | `vector_indexof` | 302 | 4.7s |  |
| 749 | `vector_insertat` | 270 | 4.2s |  |
| 750 | `vector_int_access` | 4 | 3.8s |  |
| 751 | `vector_int_delete` | 11 | 3.8s |  |
| 752 | `vector_join` | 58 | 4.0s |  |
| 753 | `vector_lastindexof` | 302 | 3.8s |  |
| 754 | `vector_legacy` | 10 | 3.8s |  |
| 755 | `vector_map` | 85 | 15.0s |  |
| 756 | `vector_object_final` | 1 | 4.0s |  |
| 757 | `vector_object_toString` | 10 | 3.8s |  |
| 758 | `vector_pushpop` | 255 | 4.3s |  |
| 759 | `vector_reborrow_bug` | 10 | 3.7s |  |
| 760 | `vector_removeat` | 172 | 4.1s |  |
| 761 | `vector_reverse` | 232 | 4.1s |  |
| 762 | `vector_shiftunshift` | 252 | 3.6s |  |
| 763 | `vector_slice` | 331 | 4.4s |  |
| 764 | `vector_sort` | 905 | 5.8s |  |
| 765 | `vector_splice` | 693 | 4.8s |  |
| 766 | `vector_splice_fixed_bug_compat` | 4 | 3.8s |  |
| 767 | `vector_tostring` | 79 | 4.1s |  |
| 768 | `verify_abnormal_loop` | 1 | 3.7s |  |
| 769 | `verify_exception_targets_edge_case` | 1 | 3.7s |  |
| 770 | `verify_lookup_switch_edge_case` | 1 | 3.7s |  |
| 771 | `verify_unreachable_exception` | 2 | 3.7s |  |
| 772 | `versioned_isplaying` | 2 | 3.7s |  |
| 773 | `virtual_properties` | 16 | 3.8s |  |
| 774 | `with` | 4 | 3.7s |  |
| 775 | `xml_abstract_equality` | 36 | 4.0s |  |
| 776 | `xml_advanced` | 52 | 3.8s |  |
| 777 | `xml_appendchild` | 10 | 3.8s |  |
| 778 | `xml_as_attribute` | 9 | 3.7s |  |
| 779 | `xml_attribute` | 35 | 3.9s |  |
| 780 | `xml_attribute_name` | 40 | 3.8s |  |
| 781 | `xml_basic` | 32 | 4.1s |  |
| 782 | `xml_child` | 25 | 3.8s |  |
| 783 | `xml_childindex` | 7 | 3.8s |  |
| 784 | `xml_children` | 43 | 4.3s |  |
| 785 | `xml_class_call` | 9 | 3.7s |  |
| 786 | `xml_contains` | 197 | 13.6s |  |
| 787 | `xml_copy` | 20 | 3.9s |  |
| 788 | `xml_ctor_from_tostring` | 23 | 4.1s |  |
| 789 | `xml_delete` | 114 | 3.8s |  |
| 790 | `xml_descendants` | 83 | 3.8s |  |
| 791 | `xml_elements` | 6 | 3.7s |  |
| 792 | `xml_equals_namespace_check` | 2 | 3.8s |  |
| 793 | `xml_explicit_use_namespace` | 5 | 3.8s |  |
| 794 | `xml_getdescendants_qname` | 21 | 3.8s |  |
| 795 | `xml_has_property_via_in` | 26 | 3.8s |  |
| 796 | `xml_hasownproperty` | 6 | 3.8s |  |
| 797 | `xml_ignore_white` | 6 | 3.8s |  |
| 798 | `xml_length` | 2 | 3.7s |  |
| 799 | `xml_list_as_attribute` | 9 | 3.6s |  |
| 800 | `xml_list_concat` | 20 | 3.6s |  |
| 801 | `xml_list_enumerate` | 4 | 3.7s |  |
| 802 | `xml_methods_settings` | 3 | 3.7s |  |
| 803 | `xml_mismatched_tag` | 37 | 3.8s |  |
| 804 | `xml_namespace` | 39 | 3.8s |  |
| 805 | `xml_namespace_methods` | 245 | 3.8s |  |
| 806 | `xml_namespaced_property` | 7 | 3.8s |  |
| 807 | `xml_no_namespace` | 1 | 3.8s |  |
| 808 | `xml_nodekind` | 3 | 3.9s |  |
| 809 | `xml_normalize` | 35 | 4.0s |  |
| 810 | `xml_notification_bubbling` | 361 | 3.9s |  |
| 811 | `xml_parent` | 8 | 3.9s |  |
| 812 | `xml_set_children` | 17 | 3.7s |  |
| 813 | `xml_set_name` | 34 | 3.9s |  |
| 814 | `xml_settings` | 6 | 1.9s |  |
| 815 | `xml_simple_complex_content` | 47 | 4.0s |  |
| 816 | `xml_text` | 7 | 3.9s |  |
| 817 | `xml_tostring` | 6 | 3.9s |  |
| 818 | `xml_tostring_namespace` | 12 | 3.8s |  |
| 819 | `xml_unescaping` | 23 | 4.0s |  |
| 820 | `xml_weird_ignores` | 54 | 3.9s |  |
| 821 | `xml_wildcard` | 11 | 3.9s |  |
| 822 | `xmldocument` | 254 | 3.9s |  |
| 823 | `xmlnode` | 3540 | 4.0s |  |
| 824 | `zero_frame_clip` | 3 | 4.2s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 1 | 3.6s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 11.0s |  |
| 3 | `blend_transform` | 1 | 1 | 3.8s |  |
| 4 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 3.9s |  |
| 5 | `dictionary_weak_keys` | 1 | 1 | 24.2s |  |
| 6 | `edittext_getcharboundaries_culling` | 300 | 300 | 4.1s |  |
| 7 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 3.9s |  |
| 8 | `edittext_tab_stops` | 6 | 6 | 4.1s |  |
| 9 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 3.9s |  |
| 10 | `error_1034_debug_string` | 19 | 19 | 4.0s |  |
| 11 | `freestanding_superclass` | 3 | 4 | 3.9s |  |
| 12 | `goto_framescript_queued` | 5 | 5 | 3.9s |  |
| 13 | `int_toexponential` | 76 | 76 | 4.0s |  |
| 14 | `int_toprecision` | 441 | 441 | 4.0s |  |
| 15 | `simplebutton_childevents_script_order` | 4 | 4 | 3.3s |  |
| 16 | `slot_holes_fail` | 1 | 1 | 3.6s |  |
| 17 | `slot_id_exceeds_trait_count` | 1 | 1 | 3.7s |  |
| 18 | `soundchannel_position` | 74 | 74 | 22.2s |  |
| 19 | `soundchannel_soundcomplete` | 10 | 10 | 3.9s |  |
| 20 | `sprite_dropTarget` | 4 | 4 | 3.7s |  |
| 21 | `swf_9_goto_in_construct_frame` | 12 | 12 | 23.1s |  |
| 22 | `uint_toexponential` | 100 | 100 | 4.0s |  |
| 23 | `uint_toprecision` | 433 | 433 | 3.9s |  |
| 24 | `weird_superinterface_properties` | 1 | 1 | 3.7s |  |

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
| 1 | `domain_memory` | exit code 1 | 3.4s |  |
| 2 | `method_without_body` | exit code 1 | 23.1s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 3.2s |  |
| 4 | `verify_typecheck` | exit code 1 | 3.8s |  |

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
| 163 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 164 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 165 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 166 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 167 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 168 | `all_classes/display/swf9` | 0.1% | 1/1959 | 163 | 1959 |  |
| 169 | `all_classes/display/swf10` | 0.0% | 1/2569 | 163 | 2569 |  |
| 170 | `all_classes/display/swf11` | 0.0% | 1/2593 | 163 | 2593 |  |
| 171 | `all_classes/display/swf12` | 0.0% | 1/2593 | 163 | 2593 |  |
| 172 | `all_classes/display/swf13` | 0.0% | 1/2671 | 163 | 2671 |  |
| 173 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 174 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 175 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 176 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 177 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 178 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 179 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 180 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 181 | `all_classes/display/swf30` | 0.0% | 0/2936 | 163 | 2936 |  |
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
| 198 | `bitmap_pixelsnapping` | 0.0% | 0/2 | 0 | 2 |  |
| 199 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 200 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
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
| 212 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 213 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 214 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 215 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 216 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 217 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 218 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 219 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 220 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 221 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 222 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 223 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 224 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 225 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 226 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 227 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 228 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 229 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 230 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 231 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 232 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 233 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 234 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 235 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
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
| 255 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 256 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 257 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 258 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 259 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 260 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 261 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 262 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 263 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 264 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 265 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 266 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 267 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 268 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 269 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
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
| 302 | `property_priority_scope_cache_order` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 304 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 305 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 306 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 307 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 308 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 309 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 310 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 311 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 312 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 313 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 314 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 315 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 316 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 317 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 318 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 319 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 320 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 321 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 322 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 323 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 324 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 325 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 326 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 327 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 328 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 329 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 330 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 331 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 332 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 333 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 334 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 335 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 336 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 337 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 338 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 339 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 340 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 341 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 342 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 343 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 344 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 345 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 346 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 347 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 348 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 349 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 350 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 351 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
