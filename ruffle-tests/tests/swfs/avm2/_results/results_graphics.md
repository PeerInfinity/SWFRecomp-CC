# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-25 19:28 UTC

**Git SHA**: `e4d1e78f66`

**Run Duration**: 158m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1218 |
| Passing | **829** (68.1%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **855** (70.2%) |
| Failing | 363 |
| Total expected lines | 151151 |
| Matching lines | 103194 (68.3%) |
| Mismatched lines | 47957 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 358 | 98.6% |
| Runtime Error | 4 | 1.1% |
| Timeout | 1 | 0.3% |

## Passing Tests

**829 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 16.5s |  |
| 2 | `agal_compiler` | 13 | 6.8s |  |
| 3 | `air_hidden_lookup` | 2 | 4.4s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.5s |  |
| 5 | `amf_custom_obj` | 26 | 4.5s |  |
| 6 | `amf_dictionary` | 9 | 4.4s |  |
| 7 | `amf_function` | 46 | 4.5s |  |
| 8 | `amf_invalid_date` | 2 | 4.4s |  |
| 9 | `amf_missing_prop` | 6 | 4.4s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.0s |  |
| 11 | `amf_setter_error` | 8 | 6.1s |  |
| 12 | `amf_vector` | 40 | 6.2s |  |
| 13 | `amf_xml` | 6 | 6.0s |  |
| 14 | `application_domain` | 4 | 6.0s |  |
| 15 | `array_access` | 18 | 5.9s |  |
| 16 | `array_access_interpreter` | 4 | 6.0s |  |
| 17 | `array_access_no_pubns` | 2 | 6.0s |  |
| 18 | `array_concat` | 41 | 6.2s |  |
| 19 | `array_constr` | 10 | 5.9s |  |
| 20 | `array_delete` | 44 | 6.1s |  |
| 21 | `array_enumeration` | 10 | 6.0s |  |
| 22 | `array_enumeration_elements` | 11 | 5.9s |  |
| 23 | `array_every` | 8 | 6.0s |  |
| 24 | `array_filter` | 6 | 6.0s |  |
| 25 | `array_foreach` | 18 | 6.0s |  |
| 26 | `array_hasownproperty` | 11 | 3.0s |  |
| 27 | `array_index_max` | 84 | 5.8s |  |
| 28 | `array_indexof` | 25 | 6.1s |  |
| 29 | `array_join` | 26 | 6.1s |  |
| 30 | `array_lastindexof` | 29 | 6.0s |  |
| 31 | `array_length` | 14 | 6.0s |  |
| 32 | `array_literal` | 3 | 6.0s |  |
| 33 | `array_map` | 8 | 5.9s |  |
| 34 | `array_reborrow_bug` | 6 | 5.9s |  |
| 35 | `array_some` | 8 | 6.1s |  |
| 36 | `array_sort_fun_swf12` | 2 | 6.0s |  |
| 37 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 38 | `array_sort_random` | 210 | 6.2s |  |
| 39 | `array_sort_swf10_32bit` | 1 | 6.1s |  |
| 40 | `array_sparse_ops` | 41 | 4.7s |  |
| 41 | `array_splice2` | 428 | 5.1s |  |
| 42 | `array_splice_types` | 48 | 4.6s |  |
| 43 | `array_storage` | 8 | 4.6s |  |
| 44 | `array_tolocalestring` | 9 | 4.6s |  |
| 45 | `array_tostring` | 12 | 4.9s |  |
| 46 | `array_valueof` | 9 | 4.5s |  |
| 47 | `array_vector_null_callback` | 10 | 4.6s |  |
| 48 | `astype` | 28 | 4.8s |  |
| 49 | `astypelate` | 24 | 4.9s |  |
| 50 | `astypelate_propagates` | 1 | 4.6s |  |
| 51 | `asymmetric_key_events` | 11 | 4.7s |  |
| 52 | `avm2_catchup_dobj` | 158 | 5.4s |  |
| 53 | `away3d_advanced_shallow_water_demo` | 0 | 65.2s |  |
| 54 | `bitand` | 1058 | 13.8s |  |
| 55 | `bitmap_constr` | 17 | 4.8s |  |
| 56 | `bitmap_data` | 1000 | 11.4s |  |
| 57 | `bitmap_pixelsnapping` | 2 | 20.1s |  |
| 58 | `bitmap_properties` | 23 | 4.7s |  |
| 59 | `bitmap_subclass` | 7 | 5.8s |  |
| 60 | `bitmap_subclass_properties` | 9 | 5.2s |  |
| 61 | `bitmap_timeline` | 9 | 4.6s |  |
| 62 | `bitmapdata_accuracy` | 1 | 38.2s |  |
| 63 | `bitmapdata_applyfilter_blur` | 0 | 20.5s |  |
| 64 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.3s |  |
| 65 | `bitmapdata_applyfilter_destpoint` | 0 | 19.9s |  |
| 66 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 20.3s |  |
| 67 | `bitmapdata_clone` | 13 | 5.4s |  |
| 68 | `bitmapdata_colortransform` | 0 | 5.6s |  |
| 69 | `bitmapdata_colortransform_oob` | 2 | 4.7s |  |
| 70 | `bitmapdata_constr` | 22 | 4.6s |  |
| 71 | `bitmapdata_constructor_from_timeline` | 1 | 4.9s |  |
| 72 | `bitmapdata_copychannel` | 0 | 27.5s |  |
| 73 | `bitmapdata_copypixels` | 23 | 26.0s |  |
| 74 | `bitmapdata_copypixels_blend_over` | 1 | 5.6s |  |
| 75 | `bitmapdata_copypixelstobytearray` | 39 | 5.6s |  |
| 76 | `bitmapdata_dispose` | 7 | 5.6s |  |
| 77 | `bitmapdata_draw` | 0 | 24.7s |  |
| 78 | `bitmapdata_draw_colortransform` | 0 | 5.8s |  |
| 79 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 24.2s |  |
| 80 | `bitmapdata_draw_filters` | 0 | 23.9s |  |
| 81 | `bitmapdata_draw_masks` | 0 | 5.7s |  |
| 82 | `bitmapdata_draw_rotation` | 0 | 5.9s |  |
| 83 | `bitmapdata_draw_self_via_graphic` | 0 | 5.9s |  |
| 84 | `bitmapdata_draw_stage` | 0 | 23.9s |  |
| 85 | `bitmapdata_drawwithquality` | 0 | 5.8s |  |
| 86 | `bitmapdata_embedded` | 9 | 6.1s |  |
| 87 | `bitmapdata_fillrect` | 0 | 6.0s |  |
| 88 | `bitmapdata_filter_sourcerect` | 0 | 24.4s |  |
| 89 | `bitmapdata_floodfill` | 35 | 5.5s |  |
| 90 | `bitmapdata_getpixels` | 39 | 24.4s |  |
| 91 | `bitmapdata_getvector` | 27 | 2.8s |  |
| 92 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 93 | `bitmapdata_hittest` | 112 | 6.2s |  |
| 94 | `bitmapdata_hittest_threshold` | 18 | 5.5s |  |
| 95 | `bitmapdata_opaque` | 0 | 5.8s |  |
| 96 | `bitmapdata_pixeldissolve` | 1037 | 24.4s |  |
| 97 | `bitmapdata_pixeldissolve_image` | 0 | 6.2s |  |
| 98 | `bitmapdata_rectangle_rounding` | 16 | 5.5s |  |
| 99 | `bitmapdata_setpixels` | 286 | 5.7s |  |
| 100 | `bitmapdata_setvector` | 26 | 5.6s |  |
| 101 | `bitmapdata_sync` | 0 | 5.7s |  |
| 102 | `bitmapdata_threshold` | 176 | 6.3s |  |
| 103 | `bitnot` | 46 | 5.6s |  |
| 104 | `bitor` | 1058 | 17.9s |  |
| 105 | `bitxor` | 1058 | 17.9s |  |
| 106 | `blend_multiply_alpha` | 0 | 5.8s |  |
| 107 | `blend_scroll` | 0 | 5.8s |  |
| 108 | `boolean_constr` | 32 | 6.1s |  |
| 109 | `boolean_negation` | 30 | 6.0s |  |
| 110 | `boolean_tostring` | 8 | 6.0s |  |
| 111 | `broadcast_event` | 7 | 6.0s |  |
| 112 | `button_nested_frame` | 48 | 6.4s |  |
| 113 | `bytearray` | 48 | 6.3s |  |
| 114 | `bytearray_compress` | 31 | 6.0s |  |
| 115 | `bytearray_errors` | 24 | 6.1s |  |
| 116 | `bytearray_method_serialization` | 1 | 6.0s |  |
| 117 | `bytearray_readobject_amf0` | 50 | 6.0s |  |
| 118 | `bytearray_readobject_amf3` | 53 | 6.1s |  |
| 119 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 120 | `bytearray_serialization` | 3 | 6.0s |  |
| 121 | `bytearray_string_null` | 19 | 6.3s |  |
| 122 | `bytearray_tostring` | 15 | 6.1s |  |
| 123 | `bytearray_utf16` | 8 | 6.0s |  |
| 124 | `bytearray_writeobject` | 24 | 5.9s |  |
| 125 | `callee_in_initializer` | 6 | 5.9s |  |
| 126 | `callproplex_class` | 1 | 6.0s |  |
| 127 | `capabilities_resolution` | 8 | 27.2s |  |
| 128 | `catch_class` | 6 | 6.0s |  |
| 129 | `catch_scope_slot` | 7 | 3.1s |  |
| 130 | `checkfilter` | 4 | 3.0s |  |
| 131 | `class_call` | 32 | 26.8s |  |
| 132 | `class_cast_call` | 14 | 6.1s |  |
| 133 | `class_enumeration` | 4 | 6.0s |  |
| 134 | `class_has_own_property` | 2 | 6.0s |  |
| 135 | `class_init_interpreter_mode` | 1 | 5.9s |  |
| 136 | `class_is` | 32 | 6.1s |  |
| 137 | `class_methods` | 5 | 6.1s |  |
| 138 | `class_object_properties` | 10 | 6.1s |  |
| 139 | `class_singleton` | 18 | 6.1s |  |
| 140 | `class_supercalls_errors` | 35 | 6.3s |  |
| 141 | `class_supercalls_mismatched` | 26 | 6.1s |  |
| 142 | `class_superclass_wrong_order` | 1 | 25.2s |  |
| 143 | `class_to_locale_string` | 2 | 6.0s |  |
| 144 | `class_to_string` | 2 | 5.9s |  |
| 145 | `class_value_of` | 2 | 5.9s |  |
| 146 | `click_block` | 5 | 25.6s |  |
| 147 | `click_invisible` | 3 | 6.0s |  |
| 148 | `closures` | 12 | 6.0s |  |
| 149 | `coerce_return_type` | 40 | 6.1s |  |
| 150 | `coerce_return_type_fail` | 2 | 5.9s |  |
| 151 | `coerce_return_void` | 3 | 5.8s |  |
| 152 | `coerce_string` | 86 | 6.1s |  |
| 153 | `coerce_string_precision` | 28 | 5.9s |  |
| 154 | `coerce_to_primitive_side_effects` | 29 | 5.9s |  |
| 155 | `construct_errors_swf10` | 8 | 5.9s |  |
| 156 | `construct_frame_list` | 22 | 6.2s |  |
| 157 | `constructor_call` | 3 | 6.0s |  |
| 158 | `constructors_vs_timeline` | 5 | 25.6s |  |
| 159 | `constructprop_dynamic_primitive` | 7 | 6.0s |  |
| 160 | `control_flow_bool` | 4 | 6.0s |  |
| 161 | `control_flow_stricteq` | 8 | 6.0s |  |
| 162 | `convert_boolean` | 30 | 5.9s |  |
| 163 | `convert_integer` | 90 | 6.0s |  |
| 164 | `convert_number` | 56 | 6.0s |  |
| 165 | `convert_uinteger` | 90 | 6.0s |  |
| 166 | `cryptscore` | 11 | 6.0s |  |
| 167 | `date` | 30 | 6.0s |  |
| 168 | `date_parse` | 36 | 5.6s |  |
| 169 | `declocal` | 46 | 5.7s |  |
| 170 | `declocal_i` | 46 | 5.7s |  |
| 171 | `decode_uri` | 71 | 5.9s |  |
| 172 | `decrement` | 46 | 5.6s |  |
| 173 | `decrement_i` | 46 | 2.8s |  |
| 174 | `default_values` | 7 | 5.6s |  |
| 175 | `dictionary_access` | 62 | 5.9s |  |
| 176 | `dictionary_access_no_pubns` | 2 | 5.7s |  |
| 177 | `dictionary_delete` | 101 | 6.2s |  |
| 178 | `dictionary_foreach` | 42 | 6.0s |  |
| 179 | `dictionary_hasownproperty` | 63 | 6.1s |  |
| 180 | `dictionary_in` | 62 | 6.0s |  |
| 181 | `dictionary_iter_modify` | 8 | 5.8s |  |
| 182 | `dictionary_namespaces` | 36 | 5.9s |  |
| 183 | `dictionary_primitive_keys` | 29 | 5.8s |  |
| 184 | `displayobject_alpha` | 277 | 5.7s |  |
| 185 | `displayobject_blendmode` | 0 | 6.0s |  |
| 186 | `displayobject_colortransform_nested` | 0 | 25.3s |  |
| 187 | `displayobject_from_enterframe` | 1 | 5.9s |  |
| 188 | `displayobject_getbounds_shape` | 0 | 24.9s |  |
| 189 | `displayobject_height` | 6052 | 24.8s |  |
| 190 | `displayobject_hittestobject` | 32 | 5.5s |  |
| 191 | `displayobject_invalid_floats` | 60 | 5.5s |  |
| 192 | `displayobject_invalid_props` | 3 | 5.5s |  |
| 193 | `displayobject_mask` | 3 | 5.8s |  |
| 194 | `displayobject_mask_self_referential` | 0 | 5.5s |  |
| 195 | `displayobject_metaData` | 3 | 5.5s |  |
| 196 | `displayobject_name` | 22 | 5.9s |  |
| 197 | `displayobject_name_from_timeline` | 24 | 5.8s |  |
| 198 | `displayobject_parent` | 12 | 5.7s |  |
| 199 | `displayobject_root` | 24 | 5.8s |  |
| 200 | `displayobject_rotation` | 1284 | 5.8s |  |
| 201 | `displayobject_set_matrix_nested` | 0 | 24.9s |  |
| 202 | `displayobject_subclass` | 2 | 5.7s |  |
| 203 | `displayobject_visible` | 23 | 5.7s |  |
| 204 | `displayobject_width` | 4852 | 24.6s |  |
| 205 | `displayobject_x` | 614 | 5.6s |  |
| 206 | `displayobject_y` | 617 | 5.7s |  |
| 207 | `displayobjectcontainer_addchild` | 32 | 5.7s |  |
| 208 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.6s |  |
| 209 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.8s |  |
| 210 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.7s |  |
| 211 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.7s |  |
| 212 | `displayobjectcontainer_addchildat` | 42 | 5.7s |  |
| 213 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.8s |  |
| 214 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.7s |  |
| 215 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.7s |  |
| 216 | `displayobjectcontainer_contains` | 66 | 24.4s |  |
| 217 | `displayobjectcontainer_getchildat` | 4 | 5.7s |  |
| 218 | `displayobjectcontainer_getchildbyname` | 9 | 5.6s |  |
| 219 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.6s |  |
| 220 | `displayobjectcontainer_getchildindex` | 28 | 5.6s |  |
| 221 | `displayobjectcontainer_removechild` | 10 | 5.6s |  |
| 222 | `displayobjectcontainer_removechild_errors` | 4 | 5.7s |  |
| 223 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.7s |  |
| 224 | `displayobjectcontainer_removechildat` | 18 | 5.6s |  |
| 225 | `displayobjectcontainer_removechildren` | 51 | 5.9s |  |
| 226 | `displayobjectcontainer_setchildindex` | 42 | 5.5s |  |
| 227 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.0s |  |
| 228 | `displayobjectcontainer_swapchildren` | 42 | 5.7s |  |
| 229 | `displayobjectcontainer_swapchildrenat` | 42 | 5.7s |  |
| 230 | `displayobjectcontainer_timelineinstance` | 48 | 24.5s |  |
| 231 | `divide` | 1058 | 17.3s |  |
| 232 | `doabc_is_eager` | 1 | 22.9s |  |
| 233 | `documentclass` | 9 | 5.6s |  |
| 234 | `drag_drop` | 10 | 5.6s |  |
| 235 | `duplicate_defs` | 1 | 5.4s |  |
| 236 | `eager_init` | 1 | 5.4s |  |
| 237 | `edit_text_linkage` | 7 | 5.6s |  |
| 238 | `edittext_align` | 60 | 5.9s |  |
| 239 | `edittext_always_show_selection` | 0 | 23.8s |  |
| 240 | `edittext_antialiastype` | 296 | 5.7s |  |
| 241 | `edittext_at_point_methods_basic` | 16 | 6.7s |  |
| 242 | `edittext_autosize` | 39 | 5.8s |  |
| 243 | `edittext_autosize_align` | 0 | 24.6s |  |
| 244 | `edittext_autosize_height_dynamic` | 60 | 24.9s |  |
| 245 | `edittext_autosize_height_input` | 60 | 5.8s |  |
| 246 | `edittext_autosize_lazy_bounds_events` | 65 | 5.9s |  |
| 247 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.7s |  |
| 248 | `edittext_autosize_lazy_bounds_props` | 490 | 7.0s |  |
| 249 | `edittext_autosize_lazy_bounds_visual` | 0 | 5.9s |  |
| 250 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.9s |  |
| 251 | `edittext_bottom_scroll_v_basic` | 210 | 5.8s |  |
| 252 | `edittext_bounds_scale` | 24 | 23.1s |  |
| 253 | `edittext_bullet` | 30 | 5.5s |  |
| 254 | `edittext_default_format` | 221 | 5.8s |  |
| 255 | `edittext_default_format_empty` | 136 | 5.7s |  |
| 256 | `edittext_empty_text_format` | 7 | 5.5s |  |
| 257 | `edittext_focus_selection` | 5 | 5.4s |  |
| 258 | `edittext_font_size` | 45 | 5.5s |  |
| 259 | `edittext_format_empty_font` | 8 | 5.4s |  |
| 260 | `edittext_get_char_index_at_point` | 4 | 24.7s |  |
| 261 | `edittext_get_line_index_at_point` | 2 | 24.1s |  |
| 262 | `edittext_get_line_index_of_char` | 76 | 6.5s |  |
| 263 | `edittext_getcharboundaries` | 172 | 5.9s |  |
| 264 | `edittext_getcharboundaries_missing_glyphs` | 63 | 35.6s |  |
| 265 | `edittext_getcharboundaries_scroll` | 85 | 5.4s |  |
| 266 | `edittext_getlinemetrics` | 146 | 5.5s |  |
| 267 | `edittext_html` | 3101 | 5.7s |  |
| 268 | `edittext_html_condensewhite` | 487 | 5.3s |  |
| 269 | `edittext_html_entity` | 4 | 5.5s |  |
| 270 | `edittext_html_font_size_swf12` | 267 | 5.3s |  |
| 271 | `edittext_html_font_size_swf13` | 273 | 5.0s |  |
| 272 | `edittext_html_roundtrip` | 17 | 5.2s |  |
| 273 | `edittext_input_control` | 12 | 5.3s |  |
| 274 | `edittext_leading` | 9 | 5.4s |  |
| 275 | `edittext_letter_spacing` | 15 | 5.2s |  |
| 276 | `edittext_line_methods` | 294 | 6.5s |  |
| 277 | `edittext_line_metrics` | 11 | 24.9s |  |
| 278 | `edittext_margins` | 25 | 5.3s |  |
| 279 | `edittext_max_scroll_h_basic` | 475 | 5.4s |  |
| 280 | `edittext_max_scroll_v_basic` | 1000 | 5.3s |  |
| 281 | `edittext_mousedown` | 3 | 5.5s |  |
| 282 | `edittext_mouseenabled` | 26 | 5.2s |  |
| 283 | `edittext_newline_character` | 22 | 5.1s |  |
| 284 | `edittext_newline_stripping` | 64 | 7.7s |  |
| 285 | `edittext_newlines` | 30 | 5.2s |  |
| 286 | `edittext_paragraph_methods` | 257 | 5.2s |  |
| 287 | `edittext_paste_events` | 8 | 5.3s |  |
| 288 | `edittext_paste_maxchars` | 4 | 5.2s |  |
| 289 | `edittext_paste_restrict` | 16 | 5.0s |  |
| 290 | `edittext_restrict` | 191 | 5.1s |  |
| 291 | `edittext_restrict_events` | 22 | 5.1s |  |
| 292 | `edittext_scrollh` | 10 | 5.1s |  |
| 293 | `edittext_selected_text` | 9 | 5.1s |  |
| 294 | `edittext_set_html_same` | 17 | 5.1s |  |
| 295 | `edittext_set_text_vs_html` | 9 | 5.1s |  |
| 296 | `edittext_stylesheet` | 536 | 5.5s |  |
| 297 | `edittext_stylesheet_custom_tag` | 76 | 5.2s |  |
| 298 | `edittext_stylesheet_display` | 272 | 5.3s |  |
| 299 | `edittext_underline` | 40 | 5.3s |  |
| 300 | `edittext_width_height` | 103 | 5.4s |  |
| 301 | `edittext_wordwrap_word` | 150 | 17.6s |  |
| 302 | `edittext_wrap_breaks` | 2375 | 6.3s |  |
| 303 | `empty_bounds` | 1 | 5.7s |  |
| 304 | `encode_uri_surrogate_pair_swf11` | 15 | 5.4s |  |
| 305 | `equals` | 512 | 10.0s |  |
| 306 | `error_prototype` | 15 | 5.7s |  |
| 307 | `error_stack_trace_debug_swf17` | 0 | 24.4s |  |
| 308 | `error_stack_trace_debug_swf18` | 0 | 5.5s |  |
| 309 | `error_stack_trace_release_swf17` | 0 | 5.5s |  |
| 310 | `error_stack_trace_release_swf18` | 0 | 5.4s |  |
| 311 | `error_tostring` | 29 | 5.5s |  |
| 312 | `es3_inheritance` | 31 | 5.6s |  |
| 313 | `es4_inheritance` | 30 | 5.6s |  |
| 314 | `es4_interfaces` | 30 | 5.7s |  |
| 315 | `es4_method_binding` | 8 | 5.5s |  |
| 316 | `es4_oop_prototypes` | 14 | 5.8s |  |
| 317 | `es4_protected_inheritance` | 6 | 5.5s |  |
| 318 | `escape` | 71 | 5.6s |  |
| 319 | `event_bubbles` | 2 | 5.5s |  |
| 320 | `event_cancelable` | 2 | 5.5s |  |
| 321 | `event_clone` | 20 | 5.7s |  |
| 322 | `event_clone_error_redispatch` | 3 | 5.7s |  |
| 323 | `event_clone_on_redispatch` | 10 | 5.8s |  |
| 324 | `event_formattostring` | 31 | 5.7s |  |
| 325 | `event_isdefaultprevented` | 12 | 5.7s |  |
| 326 | `event_target_getter` | 5 | 2.8s |  |
| 327 | `event_target_set` | 9 | 5.6s |  |
| 328 | `event_type` | 1 | 5.6s |  |
| 329 | `event_valueof_tostring` | 18 | 17.8s |  |
| 330 | `eventdispatcher_dispatchevent` | 12 | 5.8s |  |
| 331 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.8s |  |
| 332 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.8s |  |
| 333 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.9s |  |
| 334 | `eventdispatcher_dispatchevent_this` | 5 | 5.8s |  |
| 335 | `eventdispatcher_haseventlistener` | 25 | 5.9s |  |
| 336 | `eventdispatcher_interface_invoke` | 1 | 5.8s |  |
| 337 | `eventdispatcher_tostring` | 10 | 5.8s |  |
| 338 | `eventdispatcher_willtrigger` | 25 | 5.7s |  |
| 339 | `falsiness` | 30 | 5.9s |  |
| 340 | `fast_index_access` | 12 | 6.0s |  |
| 341 | `finddef` | 3 | 5.8s |  |
| 342 | `findprop_global_prototype` | 6 | 5.8s |  |
| 343 | `flash_xml` | 29 | 5.9s |  |
| 344 | `flash_xml_cloneNode` | 22 | 5.8s |  |
| 345 | `flash_xml_namespace` | 109 | 5.8s |  |
| 346 | `flash_xml_removeNode` | 60 | 5.8s |  |
| 347 | `focus_events_code` | 161 | 24.9s |  |
| 348 | `focus_events_key_same_object` | 26 | 5.9s |  |
| 349 | `focus_events_mixed_key_mouse` | 100 | 24.8s |  |
| 350 | `focus_events_mouse_same_object` | 40 | 4.5s |  |
| 351 | `focus_remove` | 20 | 19.0s |  |
| 352 | `focus_root_movie` | 4 | 18.9s |  |
| 353 | `focus_stage` | 1 | 4.5s |  |
| 354 | `focusrect` | 18 | 5.1s |  |
| 355 | `font_description_clone` | 14 | 4.5s |  |
| 356 | `font_embedded` | 24 | 4.7s |  |
| 357 | `font_enumeratefonts` | 41 | 4.9s |  |
| 358 | `font_enumeratefonts_filter` | 4 | 19.2s |  |
| 359 | `font_hasglyphs` | 40 | 4.7s |  |
| 360 | `framelabel_constr` | 5 | 4.5s |  |
| 361 | `function_call` | 12 | 4.7s |  |
| 362 | `function_call_arguments` | 46 | 4.5s |  |
| 363 | `function_call_arguments_enumerate` | 5 | 4.4s |  |
| 364 | `function_call_coercion` | 108 | 5.1s |  |
| 365 | `function_call_default` | 6 | 4.4s |  |
| 366 | `function_call_rest` | 22 | 4.5s |  |
| 367 | `function_call_types` | 3 | 4.4s |  |
| 368 | `function_call_via_call` | 3 | 4.6s |  |
| 369 | `function_display_anonymous` | 7 | 2.4s |  |
| 370 | `function_length` | 6 | 4.4s |  |
| 371 | `function_object` | 2 | 4.4s |  |
| 372 | `function_proto` | 5 | 4.4s |  |
| 373 | `function_proto_created` | 61 | 4.4s |  |
| 374 | `function_to_locale_string` | 4 | 4.4s |  |
| 375 | `function_to_string` | 4 | 4.4s |  |
| 376 | `function_type` | 6 | 4.8s |  |
| 377 | `function_unbound_this` | 51 | 4.5s |  |
| 378 | `function_value_of` | 4 | 4.4s |  |
| 379 | `get_definition_by_name` | 11 | 4.4s |  |
| 380 | `get_qualified_class_name` | 20 | 4.6s |  |
| 381 | `get_qualified_super_class_name` | 18 | 13.7s |  |
| 382 | `get_slot_edge_cases` | 1 | 18.9s |  |
| 383 | `get_timer` | 2 | 4.2s |  |
| 384 | `getglobalslot` | 1 | 4.4s |  |
| 385 | `getouterscope` | 8 | 4.3s |  |
| 386 | `getter_different_namespace_setter` | 2 | 4.2s |  |
| 387 | `goto_button_nested_framescript` | 28 | 4.8s |  |
| 388 | `goto_in_constructframe` | 12 | 4.6s |  |
| 389 | `goto_in_scene_last_frame` | 2 | 19.4s |  |
| 390 | `goto_methods` | 56 | 4.9s |  |
| 391 | `goto_methods_swfver10` | 8 | 4.5s |  |
| 392 | `goto_nested_construct_sibling` | 18 | 4.8s |  |
| 393 | `goto_nested_framescript` | 9 | 4.5s |  |
| 394 | `goto_on_orphan` | 15 | 4.6s |  |
| 395 | `graphics_bad_direct_commands` | 5 | 5.2s |  |
| 396 | `graphics_bitmap_fill` | 0 | 5.9s |  |
| 397 | `graphics_bitmaps` | 0 | 5.1s |  |
| 398 | `graphics_direct_commands` | 0 | 5.1s |  |
| 399 | `graphics_draw_triangles` | 98 | 20.0s |  |
| 400 | `graphics_gradients` | 0 | 4.7s |  |
| 401 | `graphics_gradients_nulls` | 0 | 4.5s |  |
| 402 | `graphics_path` | 56 | 4.3s |  |
| 403 | `graphics_round_rects` | 0 | 4.3s |  |
| 404 | `graphics_simple_shapes` | 0 | 4.6s |  |
| 405 | `greaterequals` | 512 | 7.4s |  |
| 406 | `greaterthan` | 512 | 7.4s |  |
| 407 | `has_own_property` | 102 | 4.7s |  |
| 408 | `hasownproperty_namespaces` | 2 | 4.3s |  |
| 409 | `hello_world` | 1 | 4.3s |  |
| 410 | `hittest_morph` | 30 | 4.5s |  |
| 411 | `if_eq` | 10 | 4.6s |  |
| 412 | `if_gt` | 1 | 4.4s |  |
| 413 | `if_gte` | 10 | 2.5s |  |
| 414 | `if_lt` | 1 | 17.4s |  |
| 415 | `if_lte` | 10 | 5.9s |  |
| 416 | `if_ne` | 7 | 2.9s |  |
| 417 | `if_stricteq` | 6 | 5.9s |  |
| 418 | `if_strictne` | 11 | 5.9s |  |
| 419 | `in` | 102 | 6.3s |  |
| 420 | `inclocal` | 46 | 5.9s |  |
| 421 | `inclocal_i` | 46 | 5.8s |  |
| 422 | `increment` | 46 | 5.8s |  |
| 423 | `increment_i` | 46 | 5.9s |  |
| 424 | `instanceof` | 58 | 6.1s |  |
| 425 | `instantiation_on_enter_frame` | 7 | 25.2s |  |
| 426 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.8s |  |
| 427 | `int_constr` | 92 | 6.0s |  |
| 428 | `int_edge_cases` | 19 | 5.9s |  |
| 429 | `int_instanceof` | 3 | 5.7s |  |
| 430 | `int_tofixed` | 1215 | 5.8s |  |
| 431 | `int_tostring` | 3375 | 6.1s |  |
| 432 | `interactiveobject_enabled` | 25 | 5.7s |  |
| 433 | `interface_namespaces` | 78 | 6.0s |  |
| 434 | `is_finite` | 46 | 6.0s |  |
| 435 | `is_nan` | 46 | 5.8s |  |
| 436 | `is_prototype_of` | 12 | 5.8s |  |
| 437 | `issue_10221` | 2 | 5.8s |  |
| 438 | `issue_13780` | 12 | 5.8s |  |
| 439 | `issue_14901` | 1 | 5.8s |  |
| 440 | `issue_17675_edittext_paste_maxchars` | 1 | 5.8s |  |
| 441 | `issue_5292` | 5 | 5.8s |  |
| 442 | `issue_8630` | 2 | 25.0s |  |
| 443 | `issue_8630_scriptremove` | 11 | 5.8s |  |
| 444 | `istype` | 24 | 2.9s |  |
| 445 | `istypelate` | 58 | 6.1s |  |
| 446 | `istypelate_coerce` | 198 | 6.9s |  |
| 447 | `json_errors` | 9 | 25.0s |  |
| 448 | `json_parse` | 21 | 5.7s |  |
| 449 | `json_stringify` | 12 | 5.8s |  |
| 450 | `json_stringify_order` | 1 | 5.5s |  |
| 451 | `json_version_gated` | 1 | 5.5s |  |
| 452 | `key_input_80percent` | 1812 | 5.7s |  |
| 453 | `key_input_location` | 126 | 5.6s |  |
| 454 | `key_input_numpad` | 384 | 5.5s |  |
| 455 | `lazyinit` | 17 | 5.6s |  |
| 456 | `lessequals` | 512 | 9.6s |  |
| 457 | `lessthan` | 512 | 9.6s |  |
| 458 | `loaderinfo_properties` | 18 | 5.7s |  |
| 459 | `loaderinfo_root` | 10 | 5.7s |  |
| 460 | `loaderinfo_root_allows` | 2 | 5.6s |  |
| 461 | `lshift` | 1058 | 17.9s |  |
| 462 | `mask_reapply` | 1 | 5.8s |  |
| 463 | `math` | 497 | 6.0s |  |
| 464 | `missing_external_interface` | 10 | 5.6s |  |
| 465 | `modulo` | 1058 | 17.7s |  |
| 466 | `morph_shape` | 2 | 24.2s |  |
| 467 | `mouse_click_events` | 90 | 24.3s |  |
| 468 | `mouse_double_click_events` | 188 | 5.7s |  |
| 469 | `mouse_empty_parent` | 4 | 5.6s |  |
| 470 | `mouse_over_while_dragging` | 3 | 5.8s |  |
| 471 | `mouse_pick_button_mode` | 2 | 5.7s |  |
| 472 | `mouse_sibling` | 8 | 5.7s |  |
| 473 | `movieclip_addframescript` | 3 | 25.0s |  |
| 474 | `movieclip_child_property` | 16 | 5.8s |  |
| 475 | `movieclip_constr` | 21 | 5.7s |  |
| 476 | `movieclip_currentlabels` | 17 | 34.9s |  |
| 477 | `movieclip_currentlabels_dupes1` | 46 | 23.8s |  |
| 478 | `movieclip_currentlabels_dupes2` | 30 | 5.2s |  |
| 479 | `movieclip_currentlabels_dupes3` | 67 | 5.2s |  |
| 480 | `movieclip_currentscene` | 12 | 5.3s |  |
| 481 | `movieclip_dispatchevent` | 430 | 5.5s |  |
| 482 | `movieclip_dispatchevent_cancel` | 102 | 5.4s |  |
| 483 | `movieclip_dispatchevent_handlerorder` | 251 | 5.3s |  |
| 484 | `movieclip_dispatchevent_selfadd` | 80 | 5.3s |  |
| 485 | `movieclip_dispatchevent_target` | 899 | 5.4s |  |
| 486 | `movieclip_displayevents` | 96 | 23.8s |  |
| 487 | `movieclip_displayevents_clickgoto` | 676 | 5.6s |  |
| 488 | `movieclip_displayevents_clickgoto2` | 2001 | 5.7s |  |
| 489 | `movieclip_displayevents_clickplay` | 575 | 5.4s |  |
| 490 | `movieclip_displayevents_clicksymbol` | 562 | 5.4s |  |
| 491 | `movieclip_displayevents_constructframegoto` | 140 | 5.5s |  |
| 492 | `movieclip_displayevents_constructframeplay` | 50 | 5.5s |  |
| 493 | `movieclip_displayevents_constructframesymbol` | 144 | 5.5s |  |
| 494 | `movieclip_displayevents_dblhandler` | 21 | 5.4s |  |
| 495 | `movieclip_displayevents_enterframegoto` | 149 | 5.5s |  |
| 496 | `movieclip_displayevents_enterframeplay` | 48 | 5.3s |  |
| 497 | `movieclip_displayevents_enterframesymbol` | 149 | 23.9s |  |
| 498 | `movieclip_displayevents_exitframegoto` | 106 | 5.3s |  |
| 499 | `movieclip_displayevents_exitframeplay` | 44 | 5.4s |  |
| 500 | `movieclip_displayevents_exitframesymbol` | 135 | 5.4s |  |
| 501 | `movieclip_displayevents_looping` | 63 | 23.6s |  |
| 502 | `movieclip_displayevents_stopped` | 113 | 5.6s |  |
| 503 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 504 | `movieclip_displayevents_timeline` | 128 | 24.0s |  |
| 505 | `movieclip_drawrect` | 54 | 5.3s |  |
| 506 | `movieclip_frameconstruct_skipped` | 9 | 5.4s |  |
| 507 | `movieclip_goto_during_frame_script` | 15 | 5.3s |  |
| 508 | `movieclip_goto_overwrite` | 14 | 23.2s |  |
| 509 | `movieclip_goto_scene_last_frame_int` | 1 | 23.9s |  |
| 510 | `movieclip_goto_scene_last_frame_label` | 1 | 5.1s |  |
| 511 | `movieclip_gotoandplay` | 15 | 23.6s |  |
| 512 | `movieclip_gotoandstop` | 13 | 5.2s |  |
| 513 | `movieclip_gotoandstop_children` | 4 | 5.3s |  |
| 514 | `movieclip_gotoandstop_framescripts1` | 4 | 5.2s |  |
| 515 | `movieclip_gotoandstop_framescripts2` | 4 | 2.4s |  |
| 516 | `movieclip_gotoandstop_framescripts_self` | 7 | 5.2s |  |
| 517 | `movieclip_gotoandstop_queueing` | 12 | 26.6s |  |
| 518 | `movieclip_next_frame` | 2 | 4.2s |  |
| 519 | `movieclip_next_scene` | 6 | 18.2s |  |
| 520 | `movieclip_play` | 3 | 3.9s |  |
| 521 | `movieclip_prev_frame` | 3 | 4.3s |  |
| 522 | `movieclip_prev_scene` | 7 | 4.3s |  |
| 523 | `movieclip_properties` | 79 | 4.3s |  |
| 524 | `movieclip_queued_noop_goto_swf10` | 9 | 4.1s |  |
| 525 | `movieclip_queued_noop_goto_swf9` | 7 | 0.7s |  |
| 526 | `movieclip_scenes` | 11 | 3.8s |  |
| 527 | `movieclip_soundtransform` | 831 | 19.7s |  |
| 528 | `movieclip_stop` | 1 | 4.0s |  |
| 529 | `movieclip_super_is_symbol` | 20 | 4.2s |  |
| 530 | `movieclip_symbol_constr` | 8 | 4.2s |  |
| 531 | `movieclip_text_mousedown` | 1 | 4.0s |  |
| 532 | `movieclip_willtrigger` | 5 | 4.1s |  |
| 533 | `multiply` | 1058 | 11.4s |  |
| 534 | `namespace_constr` | 253 | 4.0s |  |
| 535 | `namespace_constr_args` | 1 | 3.8s |  |
| 536 | `namespace_enumeration_order` | 7 | 3.9s |  |
| 537 | `nan_scale` | 9 | 4.0s |  |
| 538 | `negate` | 30 | 4.1s |  |
| 539 | `negative_volume_panned` | 0 | 4.0s |  |
| 540 | `nested_iteration` | 11 | 4.1s |  |
| 541 | `net_getClassByAlias` | 3 | 4.0s |  |
| 542 | `newactivation_in_script_init` | 3 | 5.5s |  |
| 543 | `newclass_twice` | 3 | 5.4s |  |
| 544 | `nonconflicting_declarations` | 0 | 5.5s |  |
| 545 | `null_void_types` | 8 | 5.5s |  |
| 546 | `number_autoconv` | 21 | 5.5s |  |
| 547 | `number_autoconv_amf` | 132 | 5.5s |  |
| 548 | `number_autoconv_array_sort_32bit` | 1 | 5.5s |  |
| 549 | `number_constr` | 58 | 5.6s |  |
| 550 | `number_toexponential` | 378 | 5.5s |  |
| 551 | `number_toexponential2` | 35 | 5.4s |  |
| 552 | `number_tofixed` | 378 | 5.4s |  |
| 553 | `number_toprecision` | 350 | 5.5s |  |
| 554 | `obfuscated_class_names` | 3 | 5.4s |  |
| 555 | `object_enumeration` | 10 | 5.5s |  |
| 556 | `object_prototype` | 4 | 5.5s |  |
| 557 | `object_to_locale_string` | 2 | 5.4s |  |
| 558 | `object_to_string` | 2 | 5.4s |  |
| 559 | `object_value_of` | 2 | 2.5s |  |
| 560 | `op_coerce` | 54 | 5.5s |  |
| 561 | `op_coerce_x` | 54 | 5.5s |  |
| 562 | `op_escxattr` | 2 | 5.5s |  |
| 563 | `op_escxelem` | 2 | 5.4s |  |
| 564 | `op_lookupswitch` | 4 | 5.5s |  |
| 565 | `optimize_coerce` | 1 | 5.4s |  |
| 566 | `orphan_movie_complex` | 80 | 5.8s |  |
| 567 | `orphan_movie_reorder` | 111 | 23.9s |  |
| 568 | `package_namespace` | 7 | 5.3s |  |
| 569 | `param_default_value_has_zero_cpool_index` | 1 | 5.3s |  |
| 570 | `parent_early_access_child` | 16 | 5.8s |  |
| 571 | `parse_float` | 81 | 5.7s |  |
| 572 | `pixelbender_effect_BlurredFocus` | 0 | 28.6s |  |
| 573 | `pixelbender_effect_glassDisplace` | 0 | 11.3s |  |
| 574 | `pixelbender_effect_smudge` | 0 | 9.2s |  |
| 575 | `pixelbender_effect_tintype` | 0 | 8.4s |  |
| 576 | `pixelbender_effect_twirl` | 0 | 9.5s |  |
| 577 | `pixelbender_images` | 0 | 8.0s |  |
| 578 | `place_multiple` | 17 | 23.6s |  |
| 579 | `place_object_replace` | 9 | 5.7s |  |
| 580 | `place_object_replace_2` | 24 | 5.8s |  |
| 581 | `place_object_same_depth_frame` | 1 | 5.6s |  |
| 582 | `point` | 132 | 6.1s |  |
| 583 | `primitive_edge_cases` | 1 | 5.5s |  |
| 584 | `property_priority` | 22 | 6.0s |  |
| 585 | `property_priority_three_level` | 6 | 24.5s |  |
| 586 | `propertyisenumerable_namespaces` | 6 | 5.7s |  |
| 587 | `prototype_set_null` | 7 | 5.6s |  |
| 588 | `proxy_callproperty` | 24 | 5.7s |  |
| 589 | `proxy_deleteproperty` | 64 | 5.7s |  |
| 590 | `proxy_enumeration` | 34 | 5.7s |  |
| 591 | `proxy_getproperty` | 77 | 5.8s |  |
| 592 | `proxy_hasownproperty` | 8 | 5.7s |  |
| 593 | `proxy_hasproperty` | 32 | 5.7s |  |
| 594 | `proxy_serialize` | 9 | 5.7s |  |
| 595 | `proxy_setproperty` | 42 | 5.7s |  |
| 596 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.6s |  |
| 597 | `qname_constr` | 32 | 5.7s |  |
| 598 | `qname_constr_namespace` | 24 | 5.7s |  |
| 599 | `qname_enumeration` | 9 | 5.7s |  |
| 600 | `qname_indexing` | 23 | 5.8s |  |
| 601 | `qname_tostring` | 25 | 5.7s |  |
| 602 | `qname_valueof` | 29 | 5.7s |  |
| 603 | `regexp_constr` | 148 | 6.0s |  |
| 604 | `regexp_exec` | 19 | 5.7s |  |
| 605 | `regexp_extended` | 47 | 5.8s |  |
| 606 | `regexp_multiargs` | 1 | 5.6s |  |
| 607 | `regexp_test` | 27 | 5.7s |  |
| 608 | `regexp_toString` | 10 | 5.7s |  |
| 609 | `register_script_refresh` | 35 | 6.2s |  |
| 610 | `remove_child_clear_field` | 88 | 6.0s |  |
| 611 | `remove_dobj` | 3 | 5.7s |  |
| 612 | `resolve_order` | 4 | 5.6s |  |
| 613 | `rng` | 1 | 6.9s |  |
| 614 | `rootless` | 42 | 5.8s |  |
| 615 | `rshift` | 1058 | 27.8s |  |
| 616 | `sandbox_type_local_file` | 1 | 5.1s |  |
| 617 | `scene_constr` | 8 | 5.3s |  |
| 618 | `set_local_0` | 31 | 5.2s |  |
| 619 | `set_property_is_enumerable` | 85 | 5.6s |  |
| 620 | `shape_drawrect` | 54 | 5.2s |  |
| 621 | `shared_object_no_root` | 3 | 5.1s |  |
| 622 | `simplebutton_added_to_stage` | 45 | 23.5s |  |
| 623 | `simplebutton_childevents` | 86 | 5.6s |  |
| 624 | `simplebutton_childevents_nested` | 54 | 5.5s |  |
| 625 | `simplebutton_childevents_sprite` | 13 | 5.2s |  |
| 626 | `simplebutton_childprops` | 144 | 5.3s |  |
| 627 | `simplebutton_childshuffle` | 23 | 5.0s |  |
| 628 | `simplebutton_constr` | 36 | 5.3s |  |
| 629 | `simplebutton_constr_childevents` | 48 | 5.4s |  |
| 630 | `simplebutton_constr_params` | 42 | 5.2s |  |
| 631 | `simplebutton_mouseenabled` | 26 | 5.2s |  |
| 632 | `simplebutton_multi_children` | 19 | 5.4s |  |
| 633 | `simplebutton_structure` | 27 | 5.3s |  |
| 634 | `simplebutton_symbolclass` | 68 | 5.5s |  |
| 635 | `slot_disp_id_shared_numbering` | 1 | 23.1s |  |
| 636 | `slots_force_autoassigned` | 1 | 5.2s |  |
| 637 | `sound_embeddedprops` | 26 | 5.5s |  |
| 638 | `sound_play` | 19 | 5.5s |  |
| 639 | `sound_valueof` | 33 | 5.4s |  |
| 640 | `soundchannel_soundtransform` | 835 | 25.8s |  |
| 641 | `soundchannel_soundtransform_exists` | 5 | 23.8s |  |
| 642 | `soundchannel_stop` | 8 | 5.4s |  |
| 643 | `soundmixer_buffertime` | 5 | 5.2s |  |
| 644 | `soundmixer_stopall` | 6 | 5.3s |  |
| 645 | `soundtransform` | 442 | 10.2s |  |
| 646 | `sprite_with_frames` | 0 | 5.8s |  |
| 647 | `stage3d_agal_cross_product` | 0 | 7.9s |  |
| 648 | `stage3d_bitmap` | 0 | 29.1s |  |
| 649 | `stage3d_float1_index` | 0 | 26.3s |  |
| 650 | `stage3d_fractal` | 0 | 8.3s |  |
| 651 | `stage3d_ignore_sampler_override` | 0 | 26.7s |  |
| 652 | `stage3d_program_constants_bytearray_be` | 0 | 27.7s |  |
| 653 | `stage3d_program_constants_bytearray_le` | 0 | 8.6s |  |
| 654 | `stage3d_raytrace` | 0 | 41.7s |  |
| 655 | `stage3d_rotating_cube` | 0 | 9.4s |  |
| 656 | `stage3d_sampler` | 0 | 8.4s |  |
| 657 | `stage3d_sampler_partial_upload` | 0 | 8.3s |  |
| 658 | `stage3d_stencil` | 0 | 27.2s |  |
| 659 | `stage3d_texture` | 0 | 13.2s |  |
| 660 | `stage3d_texture_bytearray` | 0 | 9.6s |  |
| 661 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.9s |  |
| 662 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.1s |  |
| 663 | `stage3d_triangle` | 0 | 8.4s |  |
| 664 | `stage3d_triangle_bytes4` | 0 | 8.3s |  |
| 665 | `stage3d_triangle_float1` | 0 | 8.3s |  |
| 666 | `stage3d_triangle_index_upload` | 0 | 8.3s |  |
| 667 | `stage_access` | 10 | 5.6s |  |
| 668 | `stage_displayobject_properties` | 24 | 5.5s |  |
| 669 | `stage_framerate_nan` | 7 | 5.7s |  |
| 670 | `stage_framerate_negative` | 6 | 5.6s |  |
| 671 | `stage_framerate_zero` | 6 | 5.6s |  |
| 672 | `stage_invalidate` | 38 | 5.7s |  |
| 673 | `stage_mousechildren` | 2 | 5.7s |  |
| 674 | `stage_mouseenabled` | 15 | 5.5s |  |
| 675 | `stage_overriden_setters` | 31 | 5.7s |  |
| 676 | `stage_properties` | 30 | 5.5s |  |
| 677 | `static_var_with_this_in_ctor` | 2 | 5.6s |  |
| 678 | `stored_properties` | 11 | 5.7s |  |
| 679 | `strict_equality` | 34 | 5.7s |  |
| 680 | `string_call` | 13 | 5.6s |  |
| 681 | `string_case` | 23 | 5.6s |  |
| 682 | `string_char_at` | 27 | 5.6s |  |
| 683 | `string_char_code_at` | 28 | 5.5s |  |
| 684 | `string_concat_fromcharcode` | 37 | 35.9s |  |
| 685 | `string_constr` | 25 | 5.7s |  |
| 686 | `string_indexof_lastindexof` | 87 | 5.8s |  |
| 687 | `string_length` | 16 | 5.6s |  |
| 688 | `string_locale_compare` | 39 | 5.8s |  |
| 689 | `string_match` | 51 | 5.8s |  |
| 690 | `string_relational_compare` | 4 | 5.5s |  |
| 691 | `string_replace` | 51 | 5.8s |  |
| 692 | `string_search` | 41 | 5.7s |  |
| 693 | `string_slice_substr_substring` | 170 | 6.7s |  |
| 694 | `string_split` | 29 | 5.6s |  |
| 695 | `string_substr_negative` | 21 | 5.6s |  |
| 696 | `string_substr_weird` | 182 | 5.7s |  |
| 697 | `subtract` | 1058 | 18.2s |  |
| 698 | `super_get_call` | 12 | 5.7s |  |
| 699 | `supercall_two_classobjects` | 2 | 5.8s |  |
| 700 | `swf8` | 1 | 5.6s |  |
| 701 | `swf_10_queued_goto_scripts_construct` | 52 | 6.0s |  |
| 702 | `swf_9_goto_in_enter_frame` | 17 | 5.8s |  |
| 703 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.8s |  |
| 704 | `swf_9_queued_goto_scripts` | 6 | 5.8s |  |
| 705 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 706 | `swf_9_versioning` | 2 | 5.7s |  |
| 707 | `swf_wrong_frame_count` | 38 | 5.9s |  |
| 708 | `swf_wrong_frame_count_isplaying` | 22 | 5.7s |  |
| 709 | `symbol_class_binary_data` | 8 | 5.8s |  |
| 710 | `symbol_class_conflict` | 4 | 6.2s |  |
| 711 | `symbol_class_root_not_zero` | 1 | 5.6s |  |
| 712 | `symbolclass_invalid_utf8` | 2 | 5.7s |  |
| 713 | `tab_ordering_automatic_advanced` | 184 | 6.3s |  |
| 714 | `tab_ordering_automatic_basic` | 45 | 5.7s |  |
| 715 | `tab_ordering_children` | 116 | 5.7s |  |
| 716 | `tab_ordering_custom_basic` | 34 | 5.7s |  |
| 717 | `text_engine_fontdescription` | 27 | 5.8s |  |
| 718 | `text_run` | 7 | 5.5s |  |
| 719 | `textfield_focusin_event` | 9 | 5.8s |  |
| 720 | `textfield_input_dead_keys_windows` | 15 | 5.8s |  |
| 721 | `textfield_unload` | 39 | 24.6s |  |
| 722 | `textformat` | 1134 | 5.8s |  |
| 723 | `textformat_display` | 14 | 5.6s |  |
| 724 | `textformat_font_max_length` | 4 | 5.5s |  |
| 725 | `throw` | 3 | 5.6s |  |
| 726 | `timeline_scripts` | 3 | 5.7s |  |
| 727 | `timer` | 90 | 6.2s |  |
| 728 | `timer_events` | 3 | 5.7s |  |
| 729 | `timer_finished` | 11 | 5.8s |  |
| 730 | `timer_reset` | 8 | 5.7s |  |
| 731 | `timer_setdelay` | 5 | 5.7s |  |
| 732 | `trace` | 12 | 5.6s |  |
| 733 | `truthiness` | 30 | 15.9s |  |
| 734 | `try_catch` | 11 | 4.3s |  |
| 735 | `try_catch_typed` | 12 | 4.2s |  |
| 736 | `typeof` | 30 | 4.2s |  |
| 737 | `uint_constr` | 92 | 4.4s |  |
| 738 | `uint_tofixed` | 1215 | 4.1s |  |
| 739 | `uint_tostring` | 3375 | 4.4s |  |
| 740 | `unchecked_function` | 15 | 4.2s |  |
| 741 | `unescape` | 28 | 4.2s |  |
| 742 | `urlrequest` | 18 | 4.2s |  |
| 743 | `urshift` | 1058 | 13.4s |  |
| 744 | `vector_class` | 36 | 4.6s |  |
| 745 | `vector_class_call` | 11 | 4.4s |  |
| 746 | `vector_coercion` | 66 | 4.9s |  |
| 747 | `vector_concat` | 90 | 4.7s |  |
| 748 | `vector_constr` | 107 | 4.7s |  |
| 749 | `vector_enumeration` | 5 | 4.2s |  |
| 750 | `vector_every` | 92 | 4.9s |  |
| 751 | `vector_filter` | 95 | 5.0s |  |
| 752 | `vector_holes` | 24 | 4.3s |  |
| 753 | `vector_indexof` | 302 | 7.6s |  |
| 754 | `vector_insertat` | 270 | 5.1s |  |
| 755 | `vector_int_access` | 4 | 4.1s |  |
| 756 | `vector_int_delete` | 11 | 4.2s |  |
| 757 | `vector_join` | 58 | 4.6s |  |
| 758 | `vector_lastindexof` | 302 | 4.1s |  |
| 759 | `vector_legacy` | 10 | 4.2s |  |
| 760 | `vector_map` | 85 | 4.9s |  |
| 761 | `vector_object_final` | 1 | 4.1s |  |
| 762 | `vector_object_toString` | 10 | 4.2s |  |
| 763 | `vector_pushpop` | 255 | 5.2s |  |
| 764 | `vector_reborrow_bug` | 10 | 17.4s |  |
| 765 | `vector_removeat` | 172 | 6.8s |  |
| 766 | `vector_reverse` | 232 | 6.9s |  |
| 767 | `vector_shiftunshift` | 252 | 7.0s |  |
| 768 | `vector_slice` | 331 | 7.4s |  |
| 769 | `vector_sort` | 905 | 15.4s |  |
| 770 | `vector_splice` | 693 | 9.8s |  |
| 771 | `vector_splice_fixed_bug_compat` | 4 | 5.8s |  |
| 772 | `vector_tostring` | 79 | 6.4s |  |
| 773 | `verify_abnormal_loop` | 1 | 5.7s |  |
| 774 | `verify_exception_targets_edge_case` | 1 | 5.7s |  |
| 775 | `verify_lookup_switch_edge_case` | 1 | 5.5s |  |
| 776 | `verify_unreachable_exception` | 2 | 5.7s |  |
| 777 | `versioned_isplaying` | 2 | 5.8s |  |
| 778 | `virtual_properties` | 16 | 5.7s |  |
| 779 | `with` | 4 | 5.8s |  |
| 780 | `xml_abstract_equality` | 36 | 5.9s |  |
| 781 | `xml_advanced` | 52 | 5.7s |  |
| 782 | `xml_appendchild` | 10 | 5.7s |  |
| 783 | `xml_as_attribute` | 9 | 5.7s |  |
| 784 | `xml_attribute` | 35 | 5.9s |  |
| 785 | `xml_attribute_name` | 40 | 5.7s |  |
| 786 | `xml_basic` | 33 | 5.8s |  |
| 787 | `xml_child` | 25 | 5.7s |  |
| 788 | `xml_childindex` | 7 | 5.6s |  |
| 789 | `xml_children` | 43 | 6.2s |  |
| 790 | `xml_class_call` | 9 | 5.7s |  |
| 791 | `xml_contains` | 197 | 5.8s |  |
| 792 | `xml_copy` | 20 | 19.8s |  |
| 793 | `xml_ctor_from_tostring` | 23 | 6.1s |  |
| 794 | `xml_delete` | 114 | 5.9s |  |
| 795 | `xml_descendants` | 83 | 5.9s |  |
| 796 | `xml_elements` | 6 | 5.8s |  |
| 797 | `xml_equals_namespace_check` | 2 | 5.8s |  |
| 798 | `xml_explicit_use_namespace` | 5 | 25.1s |  |
| 799 | `xml_getdescendants_qname` | 21 | 5.9s |  |
| 800 | `xml_has_property_via_in` | 26 | 6.0s |  |
| 801 | `xml_hasownproperty` | 6 | 5.9s |  |
| 802 | `xml_ignore_white` | 6 | 5.9s |  |
| 803 | `xml_length` | 2 | 5.9s |  |
| 804 | `xml_list_as_attribute` | 9 | 5.8s |  |
| 805 | `xml_list_concat` | 20 | 5.7s |  |
| 806 | `xml_list_enumerate` | 4 | 5.7s |  |
| 807 | `xml_methods_settings` | 3 | 5.7s |  |
| 808 | `xml_mismatched_tag` | 37 | 6.0s |  |
| 809 | `xml_namespace` | 39 | 5.9s |  |
| 810 | `xml_namespace_methods` | 245 | 5.9s |  |
| 811 | `xml_namespaced_property` | 7 | 5.8s |  |
| 812 | `xml_no_namespace` | 1 | 5.7s |  |
| 813 | `xml_nodekind` | 3 | 5.8s |  |
| 814 | `xml_normalize` | 35 | 5.9s |  |
| 815 | `xml_notification_bubbling` | 361 | 5.9s |  |
| 816 | `xml_parent` | 8 | 5.9s |  |
| 817 | `xml_set_children` | 17 | 6.0s |  |
| 818 | `xml_set_name` | 34 | 5.8s |  |
| 819 | `xml_settings` | 6 | 2.8s |  |
| 820 | `xml_simple_complex_content` | 47 | 5.8s |  |
| 821 | `xml_text` | 7 | 5.7s |  |
| 822 | `xml_tostring` | 6 | 5.7s |  |
| 823 | `xml_tostring_namespace` | 12 | 5.7s |  |
| 824 | `xml_unescaping` | 23 | 5.8s |  |
| 825 | `xml_weird_ignores` | 54 | 5.8s |  |
| 826 | `xml_wildcard` | 11 | 5.8s |  |
| 827 | `xmldocument` | 254 | 5.9s |  |
| 828 | `xmlnode` | 3540 | 6.0s |  |
| 829 | `zero_frame_clip` | 3 | 6.1s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 5.9s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 4.7s |  |
| 3 | `blend_transform` | 1 | 1 | 6.0s |  |
| 4 | `coerce_property` | 3 | 3 | 6.1s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.0s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 6.0s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.7s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.5s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 5.2s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.8s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 5.8s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 4.5s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 19.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 20.4s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.1s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.0s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 5.4s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.0s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 23.2s |  |
| 20 | `soundchannel_position` | 74 | 74 | 24.8s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 5.5s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 5.3s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 6.0s |  |
| 24 | `uint_toexponential` | 100 | 100 | 4.3s |  |
| 25 | `uint_toprecision` | 433 | 433 | 4.3s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 5.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**78 tests** within reach

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
| 9 | `array_pop` | 96.2% | 50 | 52 | 2 |  |
| 10 | `array_shift` | 96.1% | 49 | 51 | 2 |  |
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
| 21 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
| 22 | `function_call_via_apply` | 90.9% | 10 | 11 | 1 |  |
| 23 | `array_reverse` | 89.3% | 25 | 28 | 3 |  |
| 24 | `array_holes` | 88.9% | 8 | 9 | 1 |  |
| 25 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 26 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 27 | `array_push` | 87.5% | 21 | 24 | 3 |  |
| 28 | `array_unshift` | 87.5% | 21 | 24 | 3 |  |
| 29 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 30 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 31 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 32 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 33 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 34 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 35 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 36 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 37 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 38 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 39 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 40 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 41 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 42 | `indexing_delete` | 80.0% | 60 | 75 | 15 |  |
| 43 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 44 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 45 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 46 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 47 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 48 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 49 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 50 | `array_sort` | 74.1% | 220 | 297 | 77 |  |
| 51 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 52 | `array_slice` | 71.8% | 28 | 39 | 11 |  |
| 53 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 54 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 55 | `array_splice` | 69.2% | 92 | 133 | 41 |  |
| 56 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 57 | `loaderinfo_loadurl` | 66.7% | 8 | 12 | 4 |  |
| 58 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 59 | `loaderinfo_properties_not_loaded` | 65.2% | 15 | 23 | 8 |  |
| 60 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 61 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 62 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 63 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 64 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 65 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 66 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 67 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 68 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 69 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 70 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 71 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 72 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 73 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 74 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 75 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 76 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 77 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 78 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `domain_memory` | exit code 1 | 5.5s |  |
| 2 | `method_without_body` | exit code 1 | 23.9s |  |
| 3 | `rtqname_not_namespace` | exit code 1 | 5.2s |  |
| 4 | `verify_typecheck` | exit code 1 | 5.7s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 36.0s |  |

## All Output Mismatches

**358 tests** with output mismatch, sorted by match rate (best first)

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
| 9 | `array_pop` | 96.2% | 50/52 | 52 | 52 |  |
| 10 | `array_shift` | 96.1% | 49/51 | 51 | 51 |  |
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
| 21 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
| 22 | `function_call_via_apply` | 90.9% | 10/11 | 11 | 11 |  |
| 23 | `array_reverse` | 89.3% | 25/28 | 28 | 28 |  |
| 24 | `array_holes` | 88.9% | 8/9 | 9 | 9 |  |
| 25 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 26 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 27 | `array_push` | 87.5% | 21/24 | 24 | 24 |  |
| 28 | `array_unshift` | 87.5% | 21/24 | 24 | 24 |  |
| 29 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 30 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 31 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 32 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 33 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 34 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 35 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 36 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 37 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 38 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 39 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 40 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 41 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 42 | `indexing_delete` | 80.0% | 60/75 | 75 | 75 |  |
| 43 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 44 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 45 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 46 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 47 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 48 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 49 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 50 | `array_sort` | 74.1% | 220/297 | 297 | 297 |  |
| 51 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 52 | `array_slice` | 71.8% | 28/39 | 39 | 39 |  |
| 53 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 54 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 55 | `array_splice` | 69.2% | 92/133 | 133 | 133 |  |
| 56 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 57 | `loaderinfo_loadurl` | 66.7% | 8/12 | 12 | 12 |  |
| 58 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 59 | `loaderinfo_properties_not_loaded` | 65.2% | 15/23 | 23 | 23 |  |
| 60 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 61 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 62 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 63 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 64 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 65 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 66 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 67 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 68 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 69 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 70 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 71 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 72 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 73 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 74 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 75 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 76 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 77 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 78 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 79 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 80 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 81 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 82 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 83 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 84 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 85 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 86 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 87 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 88 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 89 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 90 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 91 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 92 | `displayobject_hittestpoint_root` | 30.8% | 4/13 | 6 | 13 |  |
| 93 | `large_preload_from_url` | 29.6% | 8/27 | 17 | 27 |  |
| 94 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 95 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 96 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 97 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 98 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 99 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 100 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 101 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 102 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 103 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 104 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 105 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 106 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 107 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 108 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 109 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 110 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 111 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 112 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 113 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 114 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 115 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 116 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 117 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 118 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 119 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 120 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 121 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 122 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 123 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 124 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 125 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 126 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 127 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 128 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 129 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 130 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 131 | `loader_events` | 8.7% | 8/92 | 20 | 92 |  |
| 132 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 133 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 134 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 135 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 136 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 137 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 138 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 139 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 140 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 141 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 142 | `loader_loadbytes_events` | 6.7% | 2/30 | 7 | 30 |  |
| 143 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 144 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 145 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 146 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 147 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 148 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 149 | `array_sorton` | 5.1% | 28/545 | 515 | 545 |  |
| 150 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 151 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 152 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 153 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 154 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 155 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 156 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 157 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 158 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 159 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 160 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 161 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 162 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 163 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 164 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 165 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 166 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 167 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 168 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 169 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 170 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 171 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 172 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 173 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 174 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 175 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 176 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 177 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 178 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 179 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 180 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 181 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 182 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 183 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 184 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 185 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 186 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 187 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 188 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 189 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 190 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 191 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 192 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 193 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 194 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 195 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 196 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 197 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 198 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 199 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 200 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 201 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 202 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 203 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 204 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 205 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 206 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 207 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 208 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 209 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 210 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 211 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 212 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 213 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 214 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 215 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 216 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 217 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 218 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 219 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 220 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 221 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 222 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 223 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 224 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 225 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 226 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 227 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 228 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 229 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 230 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 231 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 232 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 233 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 234 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 235 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 236 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 237 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 238 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 239 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 240 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 241 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 242 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 243 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 244 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 245 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 246 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 247 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 248 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 249 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 250 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 251 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 252 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 253 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 254 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 255 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 256 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 257 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 258 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 259 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 260 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 261 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 262 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 263 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 264 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 265 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 266 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 267 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 268 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 269 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 270 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 271 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 272 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 273 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 274 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 275 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 276 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 277 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 278 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 279 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 280 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 281 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 282 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 283 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 284 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 285 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 286 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 287 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 288 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 289 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 290 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 291 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 292 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 293 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 294 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 295 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 296 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 297 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 298 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 299 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 300 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 301 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 302 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 303 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 304 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 305 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 306 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 307 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 308 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 309 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 310 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 311 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 312 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 313 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 314 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 315 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 316 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 317 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 318 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 319 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 320 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
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
| 332 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
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
| 349 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 350 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 351 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 352 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 353 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 354 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 355 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 356 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 357 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 358 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
