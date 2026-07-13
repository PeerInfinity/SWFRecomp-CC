# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-13 05:09 UTC

**Git SHA**: `b5695059b2`

**Run Duration**: 83m 8s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1204 |
| Passing | **819** (68.0%) |
| Ruffle-matched | 24 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **843** (70.0%) |
| Failing | 361 |
| Total expected lines | 149868 |
| Matching lines | 102030 (68.1%) |
| Mismatched lines | 47838 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 356 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**819 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 0.3s |  |
| 2 | `agal_compiler` | 13 | 0.4s |  |
| 3 | `air_hidden_lookup` | 2 | 0.3s |  |
| 4 | `all_classes/security/swf11` | 3 | 0.3s |  |
| 5 | `amf_custom_obj` | 26 | 0.3s |  |
| 6 | `amf_dictionary` | 9 | 0.3s |  |
| 7 | `amf_function` | 46 | 0.3s |  |
| 8 | `amf_invalid_date` | 2 | 0.3s |  |
| 9 | `amf_missing_prop` | 6 | 0.3s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 1.5s |  |
| 11 | `amf_setter_error` | 8 | 2.1s |  |
| 12 | `amf_vector` | 40 | 2.1s |  |
| 13 | `amf_xml` | 6 | 2.0s |  |
| 14 | `application_domain` | 4 | 2.0s |  |
| 15 | `array_access` | 18 | 2.1s |  |
| 16 | `array_access_interpreter` | 4 | 2.0s |  |
| 17 | `array_access_no_pubns` | 2 | 1.9s |  |
| 18 | `array_concat` | 41 | 2.1s |  |
| 19 | `array_constr` | 10 | 2.0s |  |
| 20 | `array_delete` | 44 | 2.1s |  |
| 21 | `array_enumeration` | 10 | 2.0s |  |
| 22 | `array_enumeration_elements` | 11 | 2.0s |  |
| 23 | `array_every` | 8 | 2.0s |  |
| 24 | `array_filter` | 6 | 2.0s |  |
| 25 | `array_foreach` | 18 | 2.0s |  |
| 26 | `array_hasownproperty` | 11 | 2.0s |  |
| 27 | `array_holes` | 9 | 2.0s |  |
| 28 | `array_index_max` | 84 | 1.8s |  |
| 29 | `array_indexof` | 25 | 2.1s |  |
| 30 | `array_join` | 26 | 2.0s |  |
| 31 | `array_lastindexof` | 29 | 2.0s |  |
| 32 | `array_length` | 14 | 2.1s |  |
| 33 | `array_literal` | 3 | 2.0s |  |
| 34 | `array_map` | 8 | 0.5s |  |
| 35 | `array_pop` | 52 | 2.1s |  |
| 36 | `array_push` | 24 | 2.0s |  |
| 37 | `array_reborrow_bug` | 6 | 2.0s |  |
| 38 | `array_reverse` | 28 | 2.0s |  |
| 39 | `array_shift` | 51 | 2.1s |  |
| 40 | `array_slice` | 39 | 2.1s |  |
| 41 | `array_some` | 8 | 2.0s |  |
| 42 | `array_sort` | 297 | 2.3s |  |
| 43 | `array_sort_fun_swf12` | 2 | 2.0s |  |
| 44 | `array_sort_fun_swf13` | 2 | 0.5s |  |
| 45 | `array_sort_random` | 210 | 2.1s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 1.9s |  |
| 47 | `array_sorton` | 545 | 2.4s |  |
| 48 | `array_sparse_ops` | 41 | 2.0s |  |
| 49 | `array_splice` | 133 | 2.0s |  |
| 50 | `array_splice2` | 428 | 2.2s |  |
| 51 | `array_splice_types` | 48 | 2.1s |  |
| 52 | `array_storage` | 8 | 2.0s |  |
| 53 | `array_tolocalestring` | 9 | 2.0s |  |
| 54 | `array_tostring` | 12 | 2.0s |  |
| 55 | `array_unshift` | 24 | 2.0s |  |
| 56 | `array_valueof` | 9 | 1.9s |  |
| 57 | `array_vector_null_callback` | 10 | 1.9s |  |
| 58 | `astype` | 28 | 1.9s |  |
| 59 | `astypelate` | 24 | 2.0s |  |
| 60 | `astypelate_propagates` | 1 | 1.9s |  |
| 61 | `asymmetric_key_events` | 11 | 2.1s |  |
| 62 | `avm2_catchup_dobj` | 158 | 2.5s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 64.8s |  |
| 64 | `bitand` | 1058 | 4.4s |  |
| 65 | `bitmap_constr` | 17 | 2.2s |  |
| 66 | `bitmap_data` | 1000 | 6.9s |  |
| 67 | `bitmap_properties` | 23 | 2.1s |  |
| 68 | `bitmap_timeline` | 9 | 2.1s |  |
| 69 | `bitmapdata_accuracy` | 1 | 41.2s |  |
| 70 | `bitmapdata_applyfilter_blur` | 0 | 21.6s |  |
| 71 | `bitmapdata_applyfilter_colormatrix` | 0 | 2.3s |  |
| 72 | `bitmapdata_applyfilter_destpoint` | 0 | 21.4s |  |
| 73 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 21.6s |  |
| 74 | `bitmapdata_clone` | 13 | 2.1s |  |
| 75 | `bitmapdata_colortransform` | 0 | 2.2s |  |
| 76 | `bitmapdata_colortransform_oob` | 2 | 2.0s |  |
| 77 | `bitmapdata_constr` | 22 | 2.1s |  |
| 78 | `bitmapdata_constructor_from_timeline` | 1 | 2.3s |  |
| 79 | `bitmapdata_copychannel` | 0 | 22.6s |  |
| 80 | `bitmapdata_copypixels` | 23 | 20.1s |  |
| 81 | `bitmapdata_copypixels_blend_over` | 1 | 2.1s |  |
| 82 | `bitmapdata_copypixelstobytearray` | 39 | 1.8s |  |
| 83 | `bitmapdata_dispose` | 7 | 1.9s |  |
| 84 | `bitmapdata_draw` | 0 | 20.0s |  |
| 85 | `bitmapdata_draw_colortransform` | 0 | 1.9s |  |
| 86 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 20.2s |  |
| 87 | `bitmapdata_draw_filters` | 0 | 19.8s |  |
| 88 | `bitmapdata_draw_masks` | 0 | 1.9s |  |
| 89 | `bitmapdata_draw_rotation` | 0 | 1.9s |  |
| 90 | `bitmapdata_draw_self_via_graphic` | 0 | 1.8s |  |
| 91 | `bitmapdata_draw_stage` | 0 | 19.8s |  |
| 92 | `bitmapdata_drawwithquality` | 0 | 2.0s |  |
| 93 | `bitmapdata_embedded` | 9 | 1.9s |  |
| 94 | `bitmapdata_fillrect` | 0 | 1.9s |  |
| 95 | `bitmapdata_filter_sourcerect` | 0 | 19.8s |  |
| 96 | `bitmapdata_floodfill` | 35 | 1.8s |  |
| 97 | `bitmapdata_getpixels` | 39 | 19.7s |  |
| 98 | `bitmapdata_getvector` | 27 | 1.9s |  |
| 99 | `bitmapdata_histogram` | 59 | 1.8s |  |
| 100 | `bitmapdata_hittest` | 112 | 2.2s |  |
| 101 | `bitmapdata_hittest_threshold` | 18 | 1.9s |  |
| 102 | `bitmapdata_opaque` | 0 | 1.9s |  |
| 103 | `bitmapdata_pixeldissolve` | 1037 | 2.3s |  |
| 104 | `bitmapdata_pixeldissolve_image` | 0 | 2.0s |  |
| 105 | `bitmapdata_rectangle_rounding` | 16 | 1.8s |  |
| 106 | `bitmapdata_setpixels` | 286 | 1.9s |  |
| 107 | `bitmapdata_setvector` | 26 | 1.3s |  |
| 108 | `bitmapdata_sync` | 0 | 2.0s |  |
| 109 | `bitmapdata_threshold` | 176 | 2.4s |  |
| 110 | `bitmapdata_zero_size` | 5 | 1.8s |  |
| 111 | `bitnot` | 46 | 1.8s |  |
| 112 | `bitor` | 1058 | 3.8s |  |
| 113 | `bitxor` | 1058 | 3.8s |  |
| 114 | `blend_multiply_alpha` | 0 | 1.9s |  |
| 115 | `blend_scroll` | 0 | 1.9s |  |
| 116 | `boolean_constr` | 32 | 2.1s |  |
| 117 | `boolean_negation` | 30 | 2.0s |  |
| 118 | `boolean_tostring` | 8 | 2.0s |  |
| 119 | `broadcast_event` | 7 | 1.9s |  |
| 120 | `button_nested_frame` | 48 | 21.4s |  |
| 121 | `bytearray` | 48 | 2.2s |  |
| 122 | `bytearray_compress` | 31 | 2.0s |  |
| 123 | `bytearray_errors` | 24 | 2.1s |  |
| 124 | `bytearray_method_serialization` | 1 | 1.9s |  |
| 125 | `bytearray_readobject_amf0` | 50 | 0.8s |  |
| 126 | `bytearray_readobject_amf3` | 53 | 2.0s |  |
| 127 | `bytearray_readutf8bytes_with_bom` | 16 | 2.1s |  |
| 128 | `bytearray_serialization` | 3 | 2.0s |  |
| 129 | `bytearray_string_null` | 19 | 2.2s |  |
| 130 | `bytearray_tostring` | 15 | 2.0s |  |
| 131 | `bytearray_utf16` | 8 | 2.0s |  |
| 132 | `bytearray_writeobject` | 24 | 0.7s |  |
| 133 | `callee_in_initializer` | 6 | 1.9s |  |
| 134 | `callproplex_class` | 1 | 2.0s |  |
| 135 | `catch_class` | 6 | 1.9s |  |
| 136 | `catch_scope_slot` | 7 | 2.0s |  |
| 137 | `checkfilter` | 4 | 2.0s |  |
| 138 | `class_call` | 32 | 2.0s |  |
| 139 | `class_cast_call` | 14 | 2.0s |  |
| 140 | `class_enumeration` | 4 | 2.0s |  |
| 141 | `class_has_own_property` | 2 | 2.0s |  |
| 142 | `class_init_interpreter_mode` | 1 | 1.9s |  |
| 143 | `class_is` | 32 | 2.0s |  |
| 144 | `class_methods` | 5 | 2.0s |  |
| 145 | `class_object_properties` | 10 | 2.0s |  |
| 146 | `class_singleton` | 18 | 2.0s |  |
| 147 | `class_supercalls_errors` | 35 | 2.1s |  |
| 148 | `class_supercalls_mismatched` | 26 | 1.9s |  |
| 149 | `class_superclass_wrong_order` | 1 | 1.5s |  |
| 150 | `class_to_locale_string` | 2 | 1.7s |  |
| 151 | `class_to_string` | 2 | 1.5s |  |
| 152 | `class_value_of` | 2 | 1.5s |  |
| 153 | `click_block` | 5 | 16.4s |  |
| 154 | `click_invisible` | 3 | 1.6s |  |
| 155 | `closures` | 12 | 1.6s |  |
| 156 | `coerce_property` | 33 | 1.5s |  |
| 157 | `coerce_return_type` | 40 | 1.6s |  |
| 158 | `coerce_return_type_fail` | 2 | 1.6s |  |
| 159 | `coerce_return_void` | 3 | 1.4s |  |
| 160 | `coerce_string` | 86 | 1.5s |  |
| 161 | `coerce_string_precision` | 28 | 1.5s |  |
| 162 | `coerce_to_primitive_side_effects` | 29 | 1.6s |  |
| 163 | `construct_errors_swf10` | 8 | 1.5s |  |
| 164 | `construct_frame_list` | 22 | 16.4s |  |
| 165 | `constructor_call` | 3 | 1.5s |  |
| 166 | `constructors_vs_timeline` | 5 | 16.3s |  |
| 167 | `constructprop_dynamic_primitive` | 7 | 1.5s |  |
| 168 | `control_flow_bool` | 4 | 1.5s |  |
| 169 | `control_flow_stricteq` | 8 | 1.5s |  |
| 170 | `convert_boolean` | 30 | 1.5s |  |
| 171 | `convert_integer` | 90 | 1.6s |  |
| 172 | `convert_number` | 56 | 1.6s |  |
| 173 | `convert_uinteger` | 90 | 1.6s |  |
| 174 | `cryptscore` | 11 | 2.4s |  |
| 175 | `declocal` | 46 | 1.8s |  |
| 176 | `declocal_i` | 46 | 1.9s |  |
| 177 | `decrement` | 46 | 1.9s |  |
| 178 | `decrement_i` | 46 | 1.9s |  |
| 179 | `default_values` | 7 | 1.8s |  |
| 180 | `dictionary_access` | 62 | 1.9s |  |
| 181 | `dictionary_access_no_pubns` | 2 | 1.8s |  |
| 182 | `dictionary_delete` | 101 | 2.0s |  |
| 183 | `dictionary_foreach` | 42 | 1.9s |  |
| 184 | `dictionary_hasownproperty` | 63 | 2.0s |  |
| 185 | `dictionary_in` | 62 | 2.0s |  |
| 186 | `dictionary_iter_modify` | 8 | 1.9s |  |
| 187 | `dictionary_namespaces` | 36 | 1.9s |  |
| 188 | `dictionary_primitive_keys` | 29 | 1.8s |  |
| 189 | `displayobject_alpha` | 277 | 1.8s |  |
| 190 | `displayobject_blendmode` | 0 | 20.0s |  |
| 191 | `displayobject_colortransform_nested` | 0 | 20.2s |  |
| 192 | `displayobject_from_enterframe` | 1 | 20.0s |  |
| 193 | `displayobject_getbounds_shape` | 0 | 19.9s |  |
| 194 | `displayobject_height` | 6052 | 19.9s |  |
| 195 | `displayobject_hittestobject` | 32 | 1.9s |  |
| 196 | `displayobject_invalid_floats` | 60 | 1.9s |  |
| 197 | `displayobject_invalid_props` | 3 | 2.1s |  |
| 198 | `displayobject_mask` | 3 | 1.8s |  |
| 199 | `displayobject_mask_self_referential` | 0 | 1.7s |  |
| 200 | `displayobject_metaData` | 3 | 1.7s |  |
| 201 | `displayobject_name` | 22 | 20.7s |  |
| 202 | `displayobject_name_from_timeline` | 24 | 1.9s |  |
| 203 | `displayobject_parent` | 12 | 1.7s |  |
| 204 | `displayobject_root` | 24 | 1.7s |  |
| 205 | `displayobject_rotation` | 1275 | 1.7s |  |
| 206 | `displayobject_set_matrix_nested` | 0 | 21.1s |  |
| 207 | `displayobject_subclass` | 2 | 1.7s |  |
| 208 | `displayobject_visible` | 23 | 1.7s |  |
| 209 | `displayobject_width` | 4852 | 20.6s |  |
| 210 | `displayobject_x` | 614 | 1.5s |  |
| 211 | `displayobject_y` | 617 | 1.7s |  |
| 212 | `displayobjectcontainer_addchild` | 32 | 1.8s |  |
| 213 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 1.7s |  |
| 214 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 1.8s |  |
| 215 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 1.7s |  |
| 216 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 1.7s |  |
| 217 | `displayobjectcontainer_addchildat` | 42 | 1.7s |  |
| 218 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 1.8s |  |
| 219 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 1.7s |  |
| 220 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 1.8s |  |
| 221 | `displayobjectcontainer_contains` | 66 | 1.9s |  |
| 222 | `displayobjectcontainer_getchildat` | 4 | 1.8s |  |
| 223 | `displayobjectcontainer_getchildbyname` | 9 | 1.6s |  |
| 224 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 1.6s |  |
| 225 | `displayobjectcontainer_getchildindex` | 28 | 1.7s |  |
| 226 | `displayobjectcontainer_removechild` | 10 | 1.6s |  |
| 227 | `displayobjectcontainer_removechild_errors` | 4 | 1.7s |  |
| 228 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 1.7s |  |
| 229 | `displayobjectcontainer_removechildat` | 18 | 1.6s |  |
| 230 | `displayobjectcontainer_removechildren` | 51 | 1.9s |  |
| 231 | `displayobjectcontainer_setchildindex` | 42 | 1.6s |  |
| 232 | `displayobjectcontainer_stopallmovieclips` | 2 | 2.1s |  |
| 233 | `displayobjectcontainer_swapchildren` | 42 | 1.8s |  |
| 234 | `displayobjectcontainer_swapchildrenat` | 42 | 1.6s |  |
| 235 | `displayobjectcontainer_timelineinstance` | 48 | 19.4s |  |
| 236 | `divide` | 1058 | 3.3s |  |
| 237 | `doabc_is_eager` | 1 | 19.0s |  |
| 238 | `documentclass` | 9 | 1.7s |  |
| 239 | `drag_drop` | 10 | 1.7s |  |
| 240 | `duplicate_defs` | 1 | 0.4s |  |
| 241 | `eager_init` | 1 | 1.6s |  |
| 242 | `edit_text_linkage` | 7 | 1.7s |  |
| 243 | `edittext_align` | 60 | 1.8s |  |
| 244 | `edittext_always_show_selection` | 0 | 19.8s |  |
| 245 | `edittext_antialiastype` | 296 | 1.7s |  |
| 246 | `edittext_at_point_methods_basic` | 16 | 2.6s |  |
| 247 | `edittext_autosize` | 39 | 1.8s |  |
| 248 | `edittext_autosize_align` | 0 | 19.5s |  |
| 249 | `edittext_autosize_height_dynamic` | 60 | 19.6s |  |
| 250 | `edittext_autosize_height_input` | 60 | 1.7s |  |
| 251 | `edittext_autosize_lazy_bounds_events` | 65 | 1.9s |  |
| 252 | `edittext_autosize_lazy_bounds_interactions` | 19 | 1.7s |  |
| 253 | `edittext_autosize_lazy_bounds_props` | 490 | 2.9s |  |
| 254 | `edittext_autosize_lazy_bounds_visual` | 0 | 19.9s |  |
| 255 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 1.8s |  |
| 256 | `edittext_bottom_scroll_v_basic` | 210 | 1.8s |  |
| 257 | `edittext_bounds_scale` | 24 | 19.5s |  |
| 258 | `edittext_bullet` | 30 | 1.6s |  |
| 259 | `edittext_default_format` | 221 | 1.8s |  |
| 260 | `edittext_default_format_empty` | 136 | 1.8s |  |
| 261 | `edittext_empty_text_format` | 7 | 1.6s |  |
| 262 | `edittext_focus_selection` | 5 | 1.6s |  |
| 263 | `edittext_font_size` | 45 | 1.6s |  |
| 264 | `edittext_format_empty_font` | 8 | 1.6s |  |
| 265 | `edittext_get_char_index_at_point` | 4 | 20.3s |  |
| 266 | `edittext_get_line_index_at_point` | 2 | 17.0s |  |
| 267 | `edittext_get_line_index_of_char` | 76 | 2.4s |  |
| 268 | `edittext_getcharboundaries` | 172 | 1.8s |  |
| 269 | `edittext_getcharboundaries_missing_glyphs` | 63 | 1.6s |  |
| 270 | `edittext_getcharboundaries_scroll` | 85 | 1.5s |  |
| 271 | `edittext_getlinemetrics` | 146 | 1.7s |  |
| 272 | `edittext_html` | 3101 | 1.8s |  |
| 273 | `edittext_html_condensewhite` | 487 | 1.5s |  |
| 274 | `edittext_html_entity` | 4 | 1.7s |  |
| 275 | `edittext_html_font_size_swf12` | 267 | 1.6s |  |
| 276 | `edittext_html_font_size_swf13` | 273 | 0.4s |  |
| 277 | `edittext_html_roundtrip` | 17 | 1.6s |  |
| 278 | `edittext_input_control` | 12 | 1.6s |  |
| 279 | `edittext_leading` | 9 | 1.6s |  |
| 280 | `edittext_letter_spacing` | 15 | 1.4s |  |
| 281 | `edittext_line_methods` | 294 | 2.3s |  |
| 282 | `edittext_line_metrics` | 11 | 17.2s |  |
| 283 | `edittext_margins` | 25 | 1.5s |  |
| 284 | `edittext_max_scroll_h_basic` | 475 | 1.7s |  |
| 285 | `edittext_max_scroll_v_basic` | 1000 | 1.8s |  |
| 286 | `edittext_mousedown` | 3 | 1.8s |  |
| 287 | `edittext_mouseenabled` | 26 | 1.5s |  |
| 288 | `edittext_newline_character` | 22 | 1.6s |  |
| 289 | `edittext_newline_stripping` | 64 | 3.1s |  |
| 290 | `edittext_newlines` | 30 | 1.7s |  |
| 291 | `edittext_paragraph_methods` | 257 | 1.5s |  |
| 292 | `edittext_paste_events` | 8 | 1.6s |  |
| 293 | `edittext_paste_maxchars` | 4 | 1.6s |  |
| 294 | `edittext_paste_restrict` | 16 | 0.4s |  |
| 295 | `edittext_restrict` | 191 | 1.8s |  |
| 296 | `edittext_restrict_events` | 22 | 1.9s |  |
| 297 | `edittext_scrollh` | 10 | 1.8s |  |
| 298 | `edittext_selected_text` | 9 | 1.8s |  |
| 299 | `edittext_set_html_same` | 17 | 1.5s |  |
| 300 | `edittext_set_text_vs_html` | 9 | 1.5s |  |
| 301 | `edittext_stylesheet` | 536 | 1.7s |  |
| 302 | `edittext_stylesheet_custom_tag` | 76 | 2.3s |  |
| 303 | `edittext_stylesheet_display` | 272 | 1.9s |  |
| 304 | `edittext_underline` | 40 | 1.9s |  |
| 305 | `edittext_width_height` | 103 | 2.0s |  |
| 306 | `edittext_wordwrap_word` | 150 | 2.2s |  |
| 307 | `edittext_wrap_breaks` | 2375 | 2.5s |  |
| 308 | `empty_bounds` | 1 | 1.8s |  |
| 309 | `equals` | 512 | 2.7s |  |
| 310 | `error_prototype` | 15 | 1.8s |  |
| 311 | `error_stack_trace_debug_swf17` | 0 | 19.9s |  |
| 312 | `error_stack_trace_debug_swf18` | 0 | 0.5s |  |
| 313 | `error_stack_trace_release_swf17` | 0 | 0.4s |  |
| 314 | `error_stack_trace_release_swf18` | 0 | 0.3s |  |
| 315 | `error_tostring` | 29 | 1.8s |  |
| 316 | `es3_inheritance` | 31 | 1.9s |  |
| 317 | `es4_inheritance` | 30 | 1.9s |  |
| 318 | `es4_interfaces` | 30 | 1.9s |  |
| 319 | `es4_method_binding` | 8 | 1.8s |  |
| 320 | `es4_oop_prototypes` | 14 | 2.0s |  |
| 321 | `es4_protected_inheritance` | 6 | 1.9s |  |
| 322 | `event_bubbles` | 2 | 1.8s |  |
| 323 | `event_cancelable` | 2 | 1.8s |  |
| 324 | `event_clone` | 20 | 1.9s |  |
| 325 | `event_clone_error_redispatch` | 3 | 1.9s |  |
| 326 | `event_clone_on_redispatch` | 10 | 1.8s |  |
| 327 | `event_formattostring` | 31 | 1.4s |  |
| 328 | `event_handler_exception` | 4 | 1.4s |  |
| 329 | `event_isdefaultprevented` | 12 | 1.3s |  |
| 330 | `event_target_getter` | 5 | 1.3s |  |
| 331 | `event_target_set` | 9 | 1.3s |  |
| 332 | `event_type` | 1 | 1.3s |  |
| 333 | `event_valueof_tostring` | 18 | 1.3s |  |
| 334 | `eventdispatcher_dispatchevent` | 12 | 1.3s |  |
| 335 | `eventdispatcher_dispatchevent_cancel` | 20 | 1.3s |  |
| 336 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 1.3s |  |
| 337 | `eventdispatcher_dispatchevent_indirect` | 9 | 1.3s |  |
| 338 | `eventdispatcher_dispatchevent_this` | 5 | 1.3s |  |
| 339 | `eventdispatcher_haseventlistener` | 25 | 1.3s |  |
| 340 | `eventdispatcher_interface_invoke` | 1 | 1.3s |  |
| 341 | `eventdispatcher_tostring` | 10 | 1.3s |  |
| 342 | `eventdispatcher_willtrigger` | 25 | 1.2s |  |
| 343 | `falsiness` | 30 | 1.3s |  |
| 344 | `fast_index_access` | 12 | 1.4s |  |
| 345 | `finddef` | 3 | 1.3s |  |
| 346 | `findprop_global_prototype` | 6 | 1.3s |  |
| 347 | `flash_xml` | 29 | 1.4s |  |
| 348 | `flash_xml_cloneNode` | 22 | 1.3s |  |
| 349 | `flash_xml_namespace` | 109 | 1.3s |  |
| 350 | `flash_xml_removeNode` | 60 | 1.9s |  |
| 351 | `focus_events_code` | 161 | 16.1s |  |
| 352 | `focus_events_key_same_object` | 26 | 1.6s |  |
| 353 | `focus_events_mixed_key_mouse` | 100 | 16.4s |  |
| 354 | `focus_events_mouse_same_object` | 40 | 1.5s |  |
| 355 | `focus_remove` | 20 | 16.0s |  |
| 356 | `focus_root_movie` | 4 | 16.0s |  |
| 357 | `focus_stage` | 1 | 1.5s |  |
| 358 | `focusrect` | 18 | 2.2s |  |
| 359 | `font_description_clone` | 14 | 1.5s |  |
| 360 | `font_embedded` | 24 | 1.8s |  |
| 361 | `font_enumeratefonts` | 41 | 1.9s |  |
| 362 | `font_enumeratefonts_filter` | 4 | 2.0s |  |
| 363 | `font_hasglyphs` | 40 | 1.7s |  |
| 364 | `framelabel_constr` | 5 | 1.6s |  |
| 365 | `function_call` | 12 | 1.5s |  |
| 366 | `function_call_arguments` | 46 | 1.6s |  |
| 367 | `function_call_arguments_enumerate` | 5 | 1.5s |  |
| 368 | `function_call_coercion` | 108 | 1.7s |  |
| 369 | `function_call_default` | 6 | 1.6s |  |
| 370 | `function_call_rest` | 22 | 1.5s |  |
| 371 | `function_call_types` | 3 | 1.5s |  |
| 372 | `function_call_via_apply` | 11 | 1.5s |  |
| 373 | `function_call_via_call` | 3 | 1.5s |  |
| 374 | `function_display_anonymous` | 7 | 1.5s |  |
| 375 | `function_length` | 6 | 1.5s |  |
| 376 | `function_object` | 2 | 1.5s |  |
| 377 | `function_proto` | 5 | 1.5s |  |
| 378 | `function_proto_created` | 61 | 1.5s |  |
| 379 | `function_to_locale_string` | 4 | 1.5s |  |
| 380 | `function_to_string` | 4 | 2.4s |  |
| 381 | `function_type` | 6 | 2.0s |  |
| 382 | `function_unbound_this` | 51 | 2.2s |  |
| 383 | `function_value_of` | 4 | 1.9s |  |
| 384 | `get_definition_by_name` | 11 | 2.0s |  |
| 385 | `get_qualified_class_name` | 20 | 2.0s |  |
| 386 | `get_qualified_super_class_name` | 18 | 2.0s |  |
| 387 | `get_slot_edge_cases` | 1 | 1.9s |  |
| 388 | `get_timer` | 2 | 2.0s |  |
| 389 | `getglobalslot` | 1 | 1.9s |  |
| 390 | `getouterscope` | 8 | 1.9s |  |
| 391 | `getter_different_namespace_setter` | 2 | 1.9s |  |
| 392 | `goto_button_nested_framescript` | 28 | 22.1s |  |
| 393 | `goto_in_constructframe` | 12 | 21.9s |  |
| 394 | `goto_in_scene_last_frame` | 2 | 21.3s |  |
| 395 | `goto_methods` | 56 | 2.1s |  |
| 396 | `goto_methods_swfver10` | 8 | 2.0s |  |
| 397 | `goto_nested_construct_sibling` | 18 | 2.4s |  |
| 398 | `goto_nested_framescript` | 9 | 2.1s |  |
| 399 | `goto_on_orphan` | 15 | 2.2s |  |
| 400 | `graphics_bitmap_fill` | 0 | 3.4s |  |
| 401 | `graphics_bitmaps` | 0 | 2.2s |  |
| 402 | `graphics_direct_commands` | 0 | 2.1s |  |
| 403 | `graphics_gradients` | 0 | 2.0s |  |
| 404 | `graphics_gradients_nulls` | 0 | 2.0s |  |
| 405 | `graphics_round_rects` | 0 | 2.0s |  |
| 406 | `graphics_simple_shapes` | 0 | 2.0s |  |
| 407 | `greaterequals` | 512 | 3.0s |  |
| 408 | `greaterthan` | 512 | 3.1s |  |
| 409 | `has_own_property` | 102 | 2.0s |  |
| 410 | `hasownproperty_namespaces` | 2 | 1.8s |  |
| 411 | `hello_world` | 1 | 1.8s |  |
| 412 | `hittest_morph` | 30 | 1.9s |  |
| 413 | `if_eq` | 10 | 1.8s |  |
| 414 | `if_gt` | 1 | 1.8s |  |
| 415 | `if_gte` | 10 | 1.8s |  |
| 416 | `if_lt` | 1 | 0.5s |  |
| 417 | `if_lte` | 10 | 0.5s |  |
| 418 | `if_ne` | 7 | 1.8s |  |
| 419 | `if_stricteq` | 6 | 1.8s |  |
| 420 | `if_strictne` | 11 | 1.8s |  |
| 421 | `in` | 102 | 2.0s |  |
| 422 | `inclocal` | 46 | 1.8s |  |
| 423 | `inclocal_i` | 46 | 1.8s |  |
| 424 | `increment` | 46 | 1.8s |  |
| 425 | `increment_i` | 46 | 1.8s |  |
| 426 | `instanceof` | 58 | 1.9s |  |
| 427 | `instantiation_on_enter_frame` | 7 | 19.5s |  |
| 428 | `instantiation_on_enterframe_gotoandstop` | 8 | 1.8s |  |
| 429 | `int_constr` | 92 | 1.9s |  |
| 430 | `int_edge_cases` | 19 | 1.9s |  |
| 431 | `int_instanceof` | 3 | 1.7s |  |
| 432 | `int_tofixed` | 1215 | 1.7s |  |
| 433 | `int_tostring` | 3375 | 1.9s |  |
| 434 | `interactiveobject_enabled` | 25 | 1.7s |  |
| 435 | `interface_namespaces` | 78 | 1.9s |  |
| 436 | `is_finite` | 46 | 1.8s |  |
| 437 | `is_nan` | 46 | 1.7s |  |
| 438 | `is_prototype_of` | 12 | 1.8s |  |
| 439 | `issue_10221` | 2 | 1.8s |  |
| 440 | `issue_13780` | 12 | 1.8s |  |
| 441 | `issue_14901` | 1 | 2.4s |  |
| 442 | `issue_17675_edittext_paste_maxchars` | 1 | 2.1s |  |
| 443 | `issue_5292` | 5 | 1.8s |  |
| 444 | `issue_8630` | 2 | 1.8s |  |
| 445 | `issue_8630_scriptremove` | 11 | 1.8s |  |
| 446 | `istype` | 24 | 1.8s |  |
| 447 | `istypelate` | 58 | 2.0s |  |
| 448 | `istypelate_coerce` | 198 | 2.2s |  |
| 449 | `json_errors` | 9 | 20.4s |  |
| 450 | `json_parse` | 21 | 1.9s |  |
| 451 | `json_version_gated` | 1 | 1.9s |  |
| 452 | `key_input_80percent` | 1812 | 2.2s |  |
| 453 | `key_input_location` | 126 | 2.1s |  |
| 454 | `key_input_numpad` | 384 | 2.0s |  |
| 455 | `lazyinit` | 17 | 2.0s |  |
| 456 | `lessequals` | 512 | 2.8s |  |
| 457 | `lessthan` | 512 | 2.8s |  |
| 458 | `lshift` | 1058 | 3.8s |  |
| 459 | `mask_reapply` | 1 | 19.8s |  |
| 460 | `math` | 497 | 1.9s |  |
| 461 | `modulo` | 1058 | 3.8s |  |
| 462 | `mouse_click_events` | 90 | 19.7s |  |
| 463 | `mouse_double_click_events` | 188 | 1.8s |  |
| 464 | `mouse_empty_parent` | 4 | 1.8s |  |
| 465 | `mouse_over_while_dragging` | 3 | 1.8s |  |
| 466 | `mouse_pick_button_mode` | 2 | 1.9s |  |
| 467 | `mouse_sibling` | 8 | 1.9s |  |
| 468 | `movieclip_addframescript` | 3 | 20.2s |  |
| 469 | `movieclip_child_property` | 16 | 2.0s |  |
| 470 | `movieclip_constr` | 21 | 1.9s |  |
| 471 | `movieclip_currentlabels` | 17 | 20.4s |  |
| 472 | `movieclip_currentlabels_dupes1` | 46 | 20.5s |  |
| 473 | `movieclip_currentlabels_dupes2` | 30 | 1.9s |  |
| 474 | `movieclip_currentlabels_dupes3` | 67 | 1.9s |  |
| 475 | `movieclip_currentscene` | 12 | 20.1s |  |
| 476 | `movieclip_dispatchevent` | 430 | 2.0s |  |
| 477 | `movieclip_dispatchevent_cancel` | 102 | 2.0s |  |
| 478 | `movieclip_dispatchevent_handlerorder` | 251 | 1.9s |  |
| 479 | `movieclip_dispatchevent_selfadd` | 80 | 1.9s |  |
| 480 | `movieclip_dispatchevent_target` | 899 | 1.9s |  |
| 481 | `movieclip_displayevents` | 96 | 20.7s |  |
| 482 | `movieclip_displayevents_clickgoto` | 676 | 20.9s |  |
| 483 | `movieclip_displayevents_clickgoto2` | 2001 | 2.4s |  |
| 484 | `movieclip_displayevents_clickplay` | 575 | 2.1s |  |
| 485 | `movieclip_displayevents_clicksymbol` | 562 | 2.2s |  |
| 486 | `movieclip_displayevents_constructframegoto` | 140 | 2.3s |  |
| 487 | `movieclip_displayevents_constructframeplay` | 50 | 2.1s |  |
| 488 | `movieclip_displayevents_constructframesymbol` | 144 | 2.1s |  |
| 489 | `movieclip_displayevents_dblhandler` | 21 | 2.1s |  |
| 490 | `movieclip_displayevents_enterframegoto` | 149 | 2.2s |  |
| 491 | `movieclip_displayevents_enterframeplay` | 48 | 2.0s |  |
| 492 | `movieclip_displayevents_enterframesymbol` | 149 | 20.6s |  |
| 493 | `movieclip_displayevents_exitframegoto` | 106 | 2.0s |  |
| 494 | `movieclip_displayevents_exitframeplay` | 44 | 2.0s |  |
| 495 | `movieclip_displayevents_exitframesymbol` | 135 | 2.0s |  |
| 496 | `movieclip_displayevents_looping` | 63 | 20.7s |  |
| 497 | `movieclip_displayevents_stopped` | 113 | 2.3s |  |
| 498 | `movieclip_displayevents_swap` | 96 | 1.8s |  |
| 499 | `movieclip_displayevents_timeline` | 128 | 21.3s |  |
| 500 | `movieclip_drawrect` | 54 | 1.9s |  |
| 501 | `movieclip_frameconstruct_skipped` | 9 | 2.4s |  |
| 502 | `movieclip_goto_during_frame_script` | 15 | 20.6s |  |
| 503 | `movieclip_goto_overwrite` | 14 | 20.7s |  |
| 504 | `movieclip_goto_scene_last_frame_int` | 1 | 20.6s |  |
| 505 | `movieclip_goto_scene_last_frame_label` | 1 | 1.9s |  |
| 506 | `movieclip_gotoandplay` | 15 | 20.4s |  |
| 507 | `movieclip_gotoandstop` | 13 | 1.9s |  |
| 508 | `movieclip_gotoandstop_children` | 4 | 2.0s |  |
| 509 | `movieclip_gotoandstop_framescripts1` | 4 | 1.9s |  |
| 510 | `movieclip_gotoandstop_framescripts2` | 4 | 1.9s |  |
| 511 | `movieclip_gotoandstop_framescripts_self` | 7 | 20.6s |  |
| 512 | `movieclip_gotoandstop_queueing` | 12 | 2.1s |  |
| 513 | `movieclip_next_frame` | 2 | 2.0s |  |
| 514 | `movieclip_next_scene` | 6 | 20.3s |  |
| 515 | `movieclip_play` | 3 | 1.9s |  |
| 516 | `movieclip_prev_frame` | 3 | 0.4s |  |
| 517 | `movieclip_prev_scene` | 7 | 2.0s |  |
| 518 | `movieclip_properties` | 79 | 20.5s |  |
| 519 | `movieclip_queued_noop_goto_swf10` | 9 | 2.0s |  |
| 520 | `movieclip_queued_noop_goto_swf9` | 7 | 0.5s |  |
| 521 | `movieclip_scenes` | 11 | 1.9s |  |
| 522 | `movieclip_soundtransform` | 831 | 21.7s |  |
| 523 | `movieclip_stop` | 1 | 20.1s |  |
| 524 | `movieclip_super_is_symbol` | 20 | 2.2s |  |
| 525 | `movieclip_symbol_constr` | 8 | 2.0s |  |
| 526 | `movieclip_text_mousedown` | 1 | 2.0s |  |
| 527 | `movieclip_willtrigger` | 5 | 2.0s |  |
| 528 | `multiply` | 1058 | 4.2s |  |
| 529 | `namespace_constr` | 253 | 2.3s |  |
| 530 | `namespace_constr_args` | 1 | 1.8s |  |
| 531 | `namespace_enumeration_order` | 7 | 1.9s |  |
| 532 | `nan_scale` | 9 | 1.9s |  |
| 533 | `negate` | 30 | 1.9s |  |
| 534 | `negative_volume_panned` | 0 | 2.1s |  |
| 535 | `nested_iteration` | 11 | 1.9s |  |
| 536 | `net_getClassByAlias` | 3 | 1.9s |  |
| 537 | `newactivation_in_script_init` | 3 | 1.3s |  |
| 538 | `newclass_twice` | 3 | 1.2s |  |
| 539 | `nonconflicting_declarations` | 0 | 1.3s |  |
| 540 | `null_void_types` | 8 | 1.3s |  |
| 541 | `number_autoconv` | 21 | 1.3s |  |
| 542 | `number_autoconv_amf` | 132 | 1.3s |  |
| 543 | `number_autoconv_array_sort_32bit` | 1 | 1.3s |  |
| 544 | `number_constr` | 58 | 1.4s |  |
| 545 | `number_toexponential` | 378 | 1.3s |  |
| 546 | `number_toexponential2` | 35 | 1.3s |  |
| 547 | `number_tofixed` | 378 | 1.2s |  |
| 548 | `number_toprecision` | 350 | 1.3s |  |
| 549 | `obfuscated_class_names` | 3 | 1.2s |  |
| 550 | `object_enumeration` | 10 | 1.3s |  |
| 551 | `object_prototype` | 4 | 1.3s |  |
| 552 | `object_to_locale_string` | 2 | 1.3s |  |
| 553 | `object_to_string` | 2 | 1.2s |  |
| 554 | `object_value_of` | 2 | 1.1s |  |
| 555 | `op_coerce` | 54 | 0.9s |  |
| 556 | `op_coerce_x` | 54 | 1.3s |  |
| 557 | `op_escxattr` | 2 | 1.3s |  |
| 558 | `op_escxelem` | 2 | 1.3s |  |
| 559 | `op_lookupswitch` | 4 | 1.3s |  |
| 560 | `optimize_coerce` | 1 | 1.2s |  |
| 561 | `orphan_movie_complex` | 80 | 1.5s |  |
| 562 | `orphan_movie_reorder` | 111 | 16.8s |  |
| 563 | `package_namespace` | 7 | 2.0s |  |
| 564 | `param_default_value_has_zero_cpool_index` | 1 | 1.8s |  |
| 565 | `parent_early_access_child` | 16 | 20.6s |  |
| 566 | `parse_float` | 80 | 2.0s |  |
| 567 | `pixelbender_effect_BlurredFocus` | 0 | 23.5s |  |
| 568 | `pixelbender_effect_glassDisplace` | 0 | 7.0s |  |
| 569 | `pixelbender_effect_smudge` | 0 | 4.7s |  |
| 570 | `pixelbender_effect_tintype` | 0 | 4.0s |  |
| 571 | `pixelbender_effect_twirl` | 0 | 5.2s |  |
| 572 | `pixelbender_images` | 0 | 3.6s |  |
| 573 | `place_multiple` | 17 | 2.1s |  |
| 574 | `place_object_replace` | 9 | 2.2s |  |
| 575 | `place_object_replace_2` | 24 | 21.2s |  |
| 576 | `place_object_same_depth_frame` | 1 | 2.1s |  |
| 577 | `primitive_edge_cases` | 1 | 2.0s |  |
| 578 | `property_priority` | 22 | 2.3s |  |
| 579 | `property_priority_three_level` | 6 | 2.1s |  |
| 580 | `propertyisenumerable_namespaces` | 6 | 2.0s |  |
| 581 | `prototype_set_null` | 7 | 2.0s |  |
| 582 | `proxy_callproperty` | 24 | 2.0s |  |
| 583 | `proxy_deleteproperty` | 64 | 2.0s |  |
| 584 | `proxy_enumeration` | 34 | 2.0s |  |
| 585 | `proxy_getproperty` | 77 | 2.0s |  |
| 586 | `proxy_hasownproperty` | 8 | 2.0s |  |
| 587 | `proxy_hasproperty` | 32 | 2.1s |  |
| 588 | `proxy_serialize` | 9 | 2.0s |  |
| 589 | `proxy_setproperty` | 42 | 2.0s |  |
| 590 | `qname_as_lazy_name_attribute_multiname` | 1 | 1.9s |  |
| 591 | `qname_constr` | 32 | 2.0s |  |
| 592 | `qname_constr_namespace` | 24 | 2.0s |  |
| 593 | `qname_enumeration` | 9 | 2.0s |  |
| 594 | `qname_indexing` | 23 | 2.1s |  |
| 595 | `qname_tostring` | 25 | 1.9s |  |
| 596 | `qname_valueof` | 29 | 1.9s |  |
| 597 | `regexp_constr` | 148 | 2.1s |  |
| 598 | `regexp_exec` | 19 | 1.9s |  |
| 599 | `regexp_extended` | 47 | 1.9s |  |
| 600 | `regexp_multiargs` | 1 | 1.8s |  |
| 601 | `regexp_test` | 27 | 2.3s |  |
| 602 | `regexp_toString` | 10 | 2.0s |  |
| 603 | `register_script_refresh` | 35 | 21.0s |  |
| 604 | `remove_child_clear_field` | 88 | 21.8s |  |
| 605 | `remove_dobj` | 3 | 1.9s |  |
| 606 | `resolve_order` | 4 | 1.9s |  |
| 607 | `rng` | 1 | 3.3s |  |
| 608 | `rootless` | 42 | 2.1s |  |
| 609 | `rshift` | 1058 | 4.0s |  |
| 610 | `scene_constr` | 8 | 1.9s |  |
| 611 | `set_property_is_enumerable` | 85 | 2.1s |  |
| 612 | `shape_drawrect` | 54 | 1.9s |  |
| 613 | `shared_object_no_root` | 3 | 1.9s |  |
| 614 | `simplebutton_added_to_stage` | 45 | 20.2s |  |
| 615 | `simplebutton_childevents` | 86 | 21.0s |  |
| 616 | `simplebutton_childevents_nested` | 54 | 2.2s |  |
| 617 | `simplebutton_childevents_sprite` | 13 | 1.9s |  |
| 618 | `simplebutton_childprops` | 144 | 2.1s |  |
| 619 | `simplebutton_childshuffle` | 23 | 1.9s |  |
| 620 | `simplebutton_constr` | 36 | 2.1s |  |
| 621 | `simplebutton_constr_childevents` | 48 | 2.2s |  |
| 622 | `simplebutton_constr_params` | 42 | 2.0s |  |
| 623 | `simplebutton_mouseenabled` | 26 | 1.9s |  |
| 624 | `simplebutton_multi_children` | 19 | 2.1s |  |
| 625 | `simplebutton_structure` | 27 | 2.1s |  |
| 626 | `simplebutton_symbolclass` | 68 | 2.2s |  |
| 627 | `slot_disp_id_shared_numbering` | 1 | 20.1s |  |
| 628 | `slots_force_autoassigned` | 1 | 1.9s |  |
| 629 | `sound_embeddedprops` | 26 | 2.0s |  |
| 630 | `sound_play` | 19 | 2.0s |  |
| 631 | `sound_valueof` | 33 | 1.9s |  |
| 632 | `soundchannel_soundtransform` | 835 | 21.2s |  |
| 633 | `soundchannel_soundtransform_exists` | 5 | 20.0s |  |
| 634 | `soundchannel_stop` | 8 | 20.3s |  |
| 635 | `soundmixer_buffertime` | 5 | 1.9s |  |
| 636 | `soundmixer_stopall` | 6 | 20.0s |  |
| 637 | `soundtransform` | 442 | 2.8s |  |
| 638 | `sprite_with_frames` | 0 | 20.1s |  |
| 639 | `stage3d_agal_cross_product` | 0 | 3.1s |  |
| 640 | `stage3d_bitmap` | 0 | 23.0s |  |
| 641 | `stage3d_float1_index` | 0 | 21.3s |  |
| 642 | `stage3d_fractal` | 0 | 4.2s |  |
| 643 | `stage3d_ignore_sampler_override` | 0 | 21.5s |  |
| 644 | `stage3d_program_constants_bytearray_be` | 0 | 21.8s |  |
| 645 | `stage3d_program_constants_bytearray_le` | 0 | 3.6s |  |
| 646 | `stage3d_raytrace` | 0 | 20.7s |  |
| 647 | `stage3d_rotating_cube` | 0 | 3.6s |  |
| 648 | `stage3d_sampler` | 0 | 3.2s |  |
| 649 | `stage3d_sampler_partial_upload` | 0 | 3.1s |  |
| 650 | `stage3d_stencil` | 0 | 21.3s |  |
| 651 | `stage3d_texture` | 0 | 7.2s |  |
| 652 | `stage3d_texture_bytearray` | 0 | 4.2s |  |
| 653 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 3.7s |  |
| 654 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 4.9s |  |
| 655 | `stage3d_triangle` | 0 | 3.1s |  |
| 656 | `stage3d_triangle_bytes4` | 0 | 3.2s |  |
| 657 | `stage3d_triangle_float1` | 0 | 3.1s |  |
| 658 | `stage3d_triangle_index_upload` | 0 | 3.1s |  |
| 659 | `stage_access` | 10 | 1.9s |  |
| 660 | `stage_displayobject_properties` | 24 | 1.8s |  |
| 661 | `stage_framerate_nan` | 7 | 1.9s |  |
| 662 | `stage_framerate_negative` | 6 | 1.8s |  |
| 663 | `stage_framerate_zero` | 6 | 1.8s |  |
| 664 | `stage_invalidate` | 38 | 2.0s |  |
| 665 | `stage_mousechildren` | 2 | 1.8s |  |
| 666 | `stage_mouseenabled` | 15 | 1.8s |  |
| 667 | `stage_overriden_setters` | 31 | 1.9s |  |
| 668 | `stage_properties` | 30 | 1.8s |  |
| 669 | `static_var_with_this_in_ctor` | 2 | 1.8s |  |
| 670 | `stored_properties` | 11 | 2.5s |  |
| 671 | `strict_equality` | 34 | 2.0s |  |
| 672 | `string_call` | 13 | 2.0s |  |
| 673 | `string_case` | 23 | 2.0s |  |
| 674 | `string_char_at` | 27 | 2.0s |  |
| 675 | `string_char_code_at` | 28 | 1.9s |  |
| 676 | `string_concat_fromcharcode` | 36 | 2.0s |  |
| 677 | `string_constr` | 25 | 2.0s |  |
| 678 | `string_indexof_lastindexof` | 87 | 2.1s |  |
| 679 | `string_length` | 16 | 2.0s |  |
| 680 | `string_locale_compare` | 39 | 2.0s |  |
| 681 | `string_match` | 51 | 2.0s |  |
| 682 | `string_relational_compare` | 4 | 1.9s |  |
| 683 | `string_replace` | 51 | 2.0s |  |
| 684 | `string_search` | 41 | 2.0s |  |
| 685 | `string_slice_substr_substring` | 169 | 2.2s |  |
| 686 | `string_split` | 29 | 1.9s |  |
| 687 | `string_substr_negative` | 21 | 1.9s |  |
| 688 | `string_substr_weird` | 182 | 1.9s |  |
| 689 | `subtract` | 1058 | 4.1s |  |
| 690 | `super_get_call` | 12 | 2.0s |  |
| 691 | `supercall_two_classobjects` | 2 | 1.9s |  |
| 692 | `swf8` | 1 | 1.7s |  |
| 693 | `swf_10_queued_goto_scripts_construct` | 52 | 20.6s |  |
| 694 | `swf_9_goto_in_enter_frame` | 17 | 2.0s |  |
| 695 | `swf_9_goto_in_enter_frame_simple` | 15 | 2.0s |  |
| 696 | `swf_9_queued_goto_scripts` | 6 | 20.4s |  |
| 697 | `swf_9_queued_goto_scripts_construct` | 28 | 0.6s |  |
| 698 | `swf_9_versioning` | 2 | 1.9s |  |
| 699 | `swf_wrong_frame_count` | 38 | 2.1s |  |
| 700 | `swf_wrong_frame_count_isplaying` | 22 | 2.4s |  |
| 701 | `symbol_class_conflict` | 4 | 21.4s |  |
| 702 | `symbol_class_root_not_zero` | 1 | 1.9s |  |
| 703 | `symbolclass_invalid_utf8` | 2 | 1.9s |  |
| 704 | `tab_ordering_automatic_advanced` | 184 | 2.5s |  |
| 705 | `tab_ordering_automatic_basic` | 45 | 2.0s |  |
| 706 | `tab_ordering_children` | 116 | 2.1s |  |
| 707 | `tab_ordering_custom_basic` | 34 | 2.0s |  |
| 708 | `text_engine_fontdescription` | 27 | 2.1s |  |
| 709 | `text_run` | 7 | 1.9s |  |
| 710 | `textfield_focusin_event` | 9 | 1.9s |  |
| 711 | `textfield_input_dead_keys_windows` | 15 | 1.9s |  |
| 712 | `textfield_unload` | 39 | 2.2s |  |
| 713 | `textformat` | 1134 | 2.0s |  |
| 714 | `textformat_display` | 14 | 2.0s |  |
| 715 | `textformat_font_max_length` | 4 | 1.9s |  |
| 716 | `throw` | 3 | 1.9s |  |
| 717 | `timeline_scripts` | 3 | 2.0s |  |
| 718 | `timer` | 90 | 2.4s |  |
| 719 | `timer_events` | 3 | 2.3s |  |
| 720 | `timer_finished` | 11 | 2.1s |  |
| 721 | `timer_reset` | 8 | 1.9s |  |
| 722 | `timer_setdelay` | 5 | 1.9s |  |
| 723 | `trace` | 12 | 1.9s |  |
| 724 | `truthiness` | 30 | 1.9s |  |
| 725 | `try_catch` | 11 | 2.0s |  |
| 726 | `try_catch_typed` | 12 | 2.0s |  |
| 727 | `typeof` | 30 | 1.9s |  |
| 728 | `uint_constr` | 92 | 2.0s |  |
| 729 | `uint_tofixed` | 1215 | 1.8s |  |
| 730 | `uint_tostring` | 3375 | 2.0s |  |
| 731 | `uncaught_errors_stringified` | 3 | 2.0s |  |
| 732 | `unchecked_function` | 15 | 1.9s |  |
| 733 | `urshift` | 1058 | 4.3s |  |
| 734 | `vector_class` | 36 | 2.2s |  |
| 735 | `vector_class_call` | 11 | 2.0s |  |
| 736 | `vector_coercion` | 66 | 2.5s |  |
| 737 | `vector_concat` | 90 | 2.1s |  |
| 738 | `vector_constr` | 107 | 2.1s |  |
| 739 | `vector_enumeration` | 5 | 1.9s |  |
| 740 | `vector_every` | 92 | 2.3s |  |
| 741 | `vector_filter` | 95 | 2.3s |  |
| 742 | `vector_holes` | 24 | 1.9s |  |
| 743 | `vector_indexof` | 302 | 2.8s |  |
| 744 | `vector_insertat` | 270 | 2.3s |  |
| 745 | `vector_int_access` | 4 | 1.9s |  |
| 746 | `vector_int_delete` | 11 | 1.9s |  |
| 747 | `vector_join` | 58 | 2.1s |  |
| 748 | `vector_lastindexof` | 302 | 1.8s |  |
| 749 | `vector_legacy` | 10 | 1.9s |  |
| 750 | `vector_map` | 85 | 2.7s |  |
| 751 | `vector_object_final` | 1 | 1.8s |  |
| 752 | `vector_object_toString` | 10 | 1.0s |  |
| 753 | `vector_pushpop` | 255 | 1.5s |  |
| 754 | `vector_reborrow_bug` | 10 | 1.0s |  |
| 755 | `vector_removeat` | 172 | 1.4s |  |
| 756 | `vector_reverse` | 232 | 1.4s |  |
| 757 | `vector_shiftunshift` | 252 | 0.9s |  |
| 758 | `vector_slice` | 331 | 1.5s |  |
| 759 | `vector_sort` | 905 | 2.9s |  |
| 760 | `vector_splice` | 693 | 1.9s |  |
| 761 | `vector_splice_fixed_bug_compat` | 4 | 1.1s |  |
| 762 | `vector_tostring` | 79 | 1.3s |  |
| 763 | `verify_abnormal_loop` | 1 | 1.0s |  |
| 764 | `verify_exception_targets_edge_case` | 1 | 1.0s |  |
| 765 | `verify_lookup_switch_edge_case` | 1 | 1.0s |  |
| 766 | `verify_unreachable_exception` | 2 | 1.0s |  |
| 767 | `versioned_isplaying` | 2 | 1.0s |  |
| 768 | `virtual_properties` | 16 | 1.1s |  |
| 769 | `with` | 4 | 1.0s |  |
| 770 | `xml_abstract_equality` | 36 | 1.1s |  |
| 771 | `xml_advanced` | 52 | 1.0s |  |
| 772 | `xml_appendchild` | 10 | 1.0s |  |
| 773 | `xml_as_attribute` | 9 | 1.0s |  |
| 774 | `xml_attribute` | 35 | 1.1s |  |
| 775 | `xml_attribute_name` | 40 | 1.0s |  |
| 776 | `xml_basic` | 32 | 1.3s |  |
| 777 | `xml_child` | 25 | 1.1s |  |
| 778 | `xml_childindex` | 7 | 1.0s |  |
| 779 | `xml_children` | 43 | 1.5s |  |
| 780 | `xml_class_call` | 9 | 1.0s |  |
| 781 | `xml_contains` | 197 | 1.6s |  |
| 782 | `xml_copy` | 20 | 2.0s |  |
| 783 | `xml_ctor_from_tostring` | 23 | 2.3s |  |
| 784 | `xml_delete` | 114 | 2.0s |  |
| 785 | `xml_descendants` | 83 | 2.0s |  |
| 786 | `xml_elements` | 6 | 1.9s |  |
| 787 | `xml_equals_namespace_check` | 2 | 1.9s |  |
| 788 | `xml_explicit_use_namespace` | 5 | 1.9s |  |
| 789 | `xml_getdescendants_qname` | 21 | 1.9s |  |
| 790 | `xml_has_property_via_in` | 26 | 1.9s |  |
| 791 | `xml_hasownproperty` | 6 | 1.9s |  |
| 792 | `xml_ignore_white` | 6 | 1.9s |  |
| 793 | `xml_length` | 2 | 1.9s |  |
| 794 | `xml_list_as_attribute` | 9 | 1.2s |  |
| 795 | `xml_list_concat` | 20 | 1.8s |  |
| 796 | `xml_list_enumerate` | 4 | 1.9s |  |
| 797 | `xml_methods_settings` | 3 | 1.9s |  |
| 798 | `xml_mismatched_tag` | 37 | 2.0s |  |
| 799 | `xml_namespace` | 39 | 1.9s |  |
| 800 | `xml_namespace_methods` | 245 | 2.0s |  |
| 801 | `xml_namespaced_property` | 7 | 1.9s |  |
| 802 | `xml_no_namespace` | 1 | 1.9s |  |
| 803 | `xml_nodekind` | 3 | 1.9s |  |
| 804 | `xml_normalize` | 35 | 1.9s |  |
| 805 | `xml_notification_bubbling` | 361 | 1.9s |  |
| 806 | `xml_parent` | 8 | 1.9s |  |
| 807 | `xml_set_children` | 17 | 1.8s |  |
| 808 | `xml_set_name` | 34 | 1.9s |  |
| 809 | `xml_settings` | 6 | 1.9s |  |
| 810 | `xml_simple_complex_content` | 47 | 2.0s |  |
| 811 | `xml_text` | 7 | 1.9s |  |
| 812 | `xml_tostring` | 6 | 1.9s |  |
| 813 | `xml_tostring_namespace` | 12 | 1.9s |  |
| 814 | `xml_unescaping` | 23 | 2.0s |  |
| 815 | `xml_weird_ignores` | 54 | 2.0s |  |
| 816 | `xml_wildcard` | 11 | 1.9s |  |
| 817 | `xmldocument` | 254 | 2.0s |  |
| 818 | `xmlnode` | 3540 | 2.0s |  |
| 819 | `zero_frame_clip` | 3 | 2.2s |  |

## Ruffle-Matched Tests

**24 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 1 | 1.9s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 2.3s |  |
| 3 | `blend_transform` | 1 | 1 | 1.9s |  |
| 4 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 1.6s |  |
| 5 | `dictionary_weak_keys` | 1 | 1 | 19.8s |  |
| 6 | `edittext_getcharboundaries_culling` | 300 | 300 | 1.7s |  |
| 7 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 1.8s |  |
| 8 | `edittext_tab_stops` | 6 | 6 | 2.1s |  |
| 9 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 1.8s |  |
| 10 | `error_1034_debug_string` | 19 | 19 | 1.9s |  |
| 11 | `freestanding_superclass` | 3 | 4 | 1.4s |  |
| 12 | `goto_framescript_queued` | 5 | 5 | 2.1s |  |
| 13 | `int_toexponential` | 76 | 76 | 1.9s |  |
| 14 | `int_toprecision` | 441 | 441 | 1.9s |  |
| 15 | `simplebutton_childevents_script_order` | 4 | 4 | 2.1s |  |
| 16 | `slot_holes_fail` | 1 | 1 | 1.8s |  |
| 17 | `slot_id_exceeds_trait_count` | 1 | 1 | 1.9s |  |
| 18 | `soundchannel_position` | 74 | 74 | 20.8s |  |
| 19 | `soundchannel_soundcomplete` | 10 | 10 | 2.0s |  |
| 20 | `sprite_dropTarget` | 4 | 4 | 1.9s |  |
| 21 | `swf_9_goto_in_construct_frame` | 12 | 12 | 20.6s |  |
| 22 | `uint_toexponential` | 100 | 100 | 2.0s |  |
| 23 | `uint_toprecision` | 433 | 433 | 2.0s |  |
| 24 | `weird_superinterface_properties` | 1 | 1 | 1.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**59 tests** within reach

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
| 17 | `unescape` | 89.3% | 25 | 28 | 3 |  |
| 18 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 19 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 22 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 23 | `bitmap_subclass` | 85.7% | 6 | 7 | 1 |  |
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
| 41 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 42 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 43 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 44 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 45 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 46 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 47 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 48 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 49 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 50 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 51 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 52 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 53 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 54 | `date` | 50.0% | 15 | 30 | 15 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 56 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 57 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 58 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 59 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 1.6s |  |
| 2 | `method_without_body` | exit code 1 | 18.5s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 1.9s |  |
| 4 | `verify_typecheck` | exit code 1 | 1.1s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 32.0s |  |

## All Output Mismatches

**356 tests** with output mismatch, sorted by match rate (best first)

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
| 17 | `unescape` | 89.3% | 25/28 | 28 | 28 |  |
| 18 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 19 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 22 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 23 | `bitmap_subclass` | 85.7% | 6/7 | 7 | 7 |  |
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
| 41 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 42 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 43 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 44 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 45 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 46 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 47 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 48 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 49 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 50 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 51 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 52 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 53 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `date` | 50.0% | 15/30 | 21 | 30 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 57 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 58 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 59 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 60 | `error_stack_trace` | 46.7% | 21/45 | 45 | 45 |  |
| 61 | `focus_events_mouse_focusable` | 45.5% | 51/112 | 92 | 112 |  |
| 62 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 63 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 64 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 65 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 66 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 67 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 68 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 69 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 70 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 71 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 72 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 73 | `loaderinfo_root` | 30.0% | 3/10 | 6 | 10 |  |
| 74 | `missing_external_interface` | 30.0% | 3/10 | 9 | 10 |  |
| 75 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 76 | `sound_rootless` | 28.6% | 2/7 | 2 | 7 |  |
| 77 | `escape` | 28.2% | 20/71 | 23 | 71 |  |
| 78 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 79 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 80 | `invalid_utf8` | 25.0% | 3/12 | 12 | 12 |  |
| 81 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 82 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 83 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 84 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 85 | `bitmap_subclass_properties` | 22.2% | 2/9 | 2 | 9 |  |
| 86 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 87 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 88 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 89 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 90 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 91 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 92 | `focus_events_key_navigation` | 17.0% | 9/53 | 12 | 53 |  |
| 93 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 94 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 95 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 96 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 97 | `capabilities_resolution` | 12.5% | 1/8 | 1 | 8 |  |
| 98 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 99 | `static_length` | 12.5% | 3/24 | 24 | 24 |  |
| 100 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 101 | `point` | 12.1% | 16/132 | 16 | 132 |  |
| 102 | `focus_events_key_basic` | 11.6% | 17/147 | 147 | 132 |  |
| 103 | `focus_events_mouse_basic` | 11.5% | 30/260 | 203 | 260 |  |
| 104 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 105 | `geom_transform` | 10.8% | 8/74 | 9 | 74 |  |
| 106 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 107 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 108 | `stage_properties2` | 8.5% | 18/213 | 171 | 213 |  |
| 109 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 110 | `loaderinfo_loadurl` | 8.3% | 1/12 | 1 | 12 |  |
| 111 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
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
| 141 | `displayobject_early_init` | 1.9% | 1/54 | 24 | 54 |  |
| 142 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 143 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 144 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 145 | `external_interface` | 1.0% | 1/104 | 1 | 104 |  |
| 146 | `navigateToURL_target_normalize` | 0.9% | 1/107 | 1 | 107 |  |
| 147 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 148 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 149 | `edittext_mouse_selection` | 0.6% | 2/363 | 277 | 363 |  |
| 150 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 151 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 152 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 153 | `all_classes/events/swf9` | 0.2% | 2/1030 | 116 | 1030 |  |
| 154 | `tab_ordering_arrows` | 0.1% | 1/998 | 1 | 998 |  |
| 155 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 156 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 157 | `all_classes/display/swf10` | 0.1% | 2/2569 | 157 | 2569 |  |
| 158 | `all_classes/display/swf11` | 0.1% | 2/2593 | 157 | 2593 |  |
| 159 | `all_classes/display/swf12` | 0.1% | 2/2593 | 157 | 2593 |  |
| 160 | `all_classes/display/swf13` | 0.1% | 2/2671 | 157 | 2671 |  |
| 161 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 162 | `all_classes/events/swf10` | 0.1% | 1/1638 | 116 | 1638 |  |
| 163 | `all_classes/events/swf11` | 0.1% | 1/1750 | 116 | 1750 |  |
| 164 | `all_classes/events/swf12` | 0.1% | 1/1814 | 116 | 1814 |  |
| 165 | `all_classes/display/swf9` | 0.1% | 1/1959 | 157 | 1959 |  |
| 166 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 167 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 168 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 169 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 170 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 171 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 172 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 173 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 174 | `all_classes/display/swf30` | 0.0% | 0/2936 | 157 | 2936 |  |
| 175 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 176 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 177 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 178 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 179 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 180 | `all_classes/events/swf30` | 0.0% | 0/2353 | 116 | 2353 |  |
| 181 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 182 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 183 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 184 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 185 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 186 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/8 | 0 | 8 |  |
| 187 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 188 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 189 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 190 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 191 | `bitmap_pixelsnapping` | 0.0% | 0/2 | 0 | 2 |  |
| 192 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 193 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 194 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 195 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 196 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 197 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 198 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 199 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 200 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 201 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 202 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 203 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 204 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 205 | `decode_uri` | 0.0% | 0/71 | 0 | 71 |  |
| 206 | `delayed_symbolclass` | 0.0% | 0/28 | 11 | 28 |  |
| 207 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 208 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 209 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 210 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 211 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 212 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 213 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 214 | `encode_uri_surrogate_pair_swf11` | 0.0% | 0/15 | 0 | 15 |  |
| 215 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 216 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 217 | `filefilter_properties` | 0.0% | 0/3 | 0 | 3 |  |
| 218 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 219 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 220 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 221 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 222 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 223 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 224 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 225 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 226 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 227 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 228 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 229 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 230 | `graphics_bad_direct_commands` | 0.0% | 0/5 | 0 | 5 |  |
| 231 | `graphics_draw_path` | 0.0% | 0/101 | 0 | 101 |  |
| 232 | `graphics_draw_triangles` | 0.0% | 0/98 | 0 | 98 |  |
| 233 | `graphics_path` | 0.0% | 0/56 | 20 | 56 |  |
| 234 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 235 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 236 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 237 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 238 | `large_preload_from_bytes` | 0.0% | 0/51 | 0 | 51 |  |
| 239 | `large_preload_from_url` | 0.0% | 0/27 | 0 | 27 |  |
| 240 | `large_preload_image_from_bytes` | 0.0% | 0/25 | 0 | 25 |  |
| 241 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 242 | `loader_bitmap_transparency` | 0.0% | 0/14 | 0 | 14 |  |
| 243 | `loader_bytes_unknown_content` | 0.0% | 0/14 | 0 | 14 |  |
| 244 | `loader_error_in_root_ctor` | 0.0% | 0/2 | 0 | 2 |  |
| 245 | `loader_events` | 0.0% | 0/92 | 0 | 92 |  |
| 246 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 247 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 248 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 249 | `loader_load` | 0.0% | 0/126 | 0 | 126 |  |
| 250 | `loader_loadbytes_events` | 0.0% | 0/30 | 0 | 30 |  |
| 251 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 252 | `loader_loaderurl` | 0.0% | 0/6 | 0 | 6 |  |
| 253 | `loader_method` | 0.0% | 0/83 | 0 | 83 |  |
| 254 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 255 | `loader_reuse` | 0.0% | 0/38 | 0 | 38 |  |
| 256 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 257 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 258 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 259 | `loaderinfo_events` | 0.0% | 0/7 | 0 | 7 |  |
| 260 | `loaderinfo_more` | 0.0% | 0/6 | 0 | 6 |  |
| 261 | `loaderinfo_properties_not_loaded` | 0.0% | 0/23 | 0 | 23 |  |
| 262 | `loaderinfo_root_allows` | 0.0% | 0/2 | 0 | 2 |  |
| 263 | `localconnection` | 0.0% | 0/890 | 0 | 890 |  |
| 264 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 265 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 266 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 267 | `morph_shape` | 0.0% | 0/2 | 2 | 2 |  |
| 268 | `mouse_pick_loader_avm1` | 0.0% | 0/42 | 0 | 42 |  |
| 269 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 270 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 271 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 272 | `net_navigateToURL` | 0.0% | 0/57 | 0 | 57 |  |
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
| 304 | `sandbox_type_inherited` | 0.0% | 0/2 | 0 | 2 |  |
| 305 | `sandbox_type_local_file` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `sandbox_type_local_network` | 0.0% | 0/1 | 0 | 1 |  |
| 307 | `sandbox_type_remote` | 0.0% | 0/3 | 0 | 3 |  |
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
| 320 | `sound_constructor_with_args` | 0.0% | 0/6 | 0 | 6 |  |
| 321 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 322 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 323 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 324 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 325 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 326 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 327 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 328 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 329 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 330 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 331 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 332 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 0 | 5 |  |
| 333 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 334 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 335 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 336 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 337 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 338 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 339 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 340 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 341 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 342 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 343 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 344 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 345 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 346 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 347 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 348 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 349 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 350 | `url_vars` | 0.0% | 0/27 | 0 | 27 |  |
| 351 | `urlrequest` | 0.0% | 0/18 | 0 | 18 |  |
| 352 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 353 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 354 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 355 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 356 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
