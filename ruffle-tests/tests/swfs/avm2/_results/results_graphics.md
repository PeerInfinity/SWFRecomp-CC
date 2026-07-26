# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-26 02:00 UTC

**Git SHA**: `ffe48dff67`

**Run Duration**: 159m 6s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1218 |
| Passing | **842** (69.1%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **868** (71.3%) |
| Failing | 350 |
| Total expected lines | 151151 |
| Matching lines | 104002 (68.8%) |
| Mismatched lines | 47149 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 346 | 98.9% |
| Runtime Error | 3 | 0.9% |
| Timeout | 1 | 0.3% |

## Passing Tests

**842 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.2s |  |
| 2 | `agal_compiler` | 13 | 6.9s |  |
| 3 | `air_hidden_lookup` | 2 | 4.4s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.5s |  |
| 5 | `amf_custom_obj` | 26 | 4.5s |  |
| 6 | `amf_dictionary` | 9 | 4.5s |  |
| 7 | `amf_function` | 46 | 4.5s |  |
| 8 | `amf_invalid_date` | 2 | 4.4s |  |
| 9 | `amf_missing_prop` | 6 | 4.5s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 5.7s |  |
| 11 | `amf_setter_error` | 8 | 5.8s |  |
| 12 | `amf_vector` | 40 | 5.8s |  |
| 13 | `amf_xml` | 6 | 5.7s |  |
| 14 | `application_domain` | 4 | 5.7s |  |
| 15 | `array_access` | 18 | 5.8s |  |
| 16 | `array_access_interpreter` | 4 | 5.8s |  |
| 17 | `array_access_no_pubns` | 2 | 5.7s |  |
| 18 | `array_concat` | 41 | 5.8s |  |
| 19 | `array_constr` | 10 | 5.6s |  |
| 20 | `array_delete` | 44 | 5.7s |  |
| 21 | `array_enumeration` | 10 | 5.7s |  |
| 22 | `array_enumeration_elements` | 11 | 5.6s |  |
| 23 | `array_every` | 8 | 5.6s |  |
| 24 | `array_filter` | 6 | 5.6s |  |
| 25 | `array_foreach` | 18 | 5.7s |  |
| 26 | `array_hasownproperty` | 11 | 2.7s |  |
| 27 | `array_holes` | 9 | 5.6s |  |
| 28 | `array_index_max` | 84 | 5.4s |  |
| 29 | `array_indexof` | 25 | 5.5s |  |
| 30 | `array_join` | 26 | 5.6s |  |
| 31 | `array_lastindexof` | 29 | 5.5s |  |
| 32 | `array_length` | 14 | 5.5s |  |
| 33 | `array_literal` | 3 | 5.5s |  |
| 34 | `array_map` | 8 | 5.5s |  |
| 35 | `array_pop` | 52 | 5.7s |  |
| 36 | `array_push` | 24 | 5.6s |  |
| 37 | `array_reborrow_bug` | 6 | 5.5s |  |
| 38 | `array_reverse` | 28 | 5.6s |  |
| 39 | `array_shift` | 51 | 2.8s |  |
| 40 | `array_slice` | 39 | 5.7s |  |
| 41 | `array_some` | 8 | 5.7s |  |
| 42 | `array_sort` | 297 | 6.1s |  |
| 43 | `array_sort_fun_swf12` | 2 | 5.7s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 45 | `array_sort_random` | 210 | 5.8s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 5.7s |  |
| 47 | `array_sorton` | 545 | 6.4s |  |
| 48 | `array_sparse_ops` | 41 | 5.7s |  |
| 49 | `array_splice` | 133 | 5.9s |  |
| 50 | `array_splice2` | 428 | 6.0s |  |
| 51 | `array_splice_types` | 48 | 5.9s |  |
| 52 | `array_storage` | 8 | 5.7s |  |
| 53 | `array_tolocalestring` | 9 | 5.6s |  |
| 54 | `array_tostring` | 12 | 5.7s |  |
| 55 | `array_unshift` | 24 | 5.7s |  |
| 56 | `array_valueof` | 9 | 5.6s |  |
| 57 | `array_vector_null_callback` | 10 | 5.6s |  |
| 58 | `astype` | 28 | 5.7s |  |
| 59 | `astypelate` | 24 | 5.9s |  |
| 60 | `astypelate_propagates` | 1 | 5.6s |  |
| 61 | `asymmetric_key_events` | 11 | 5.8s |  |
| 62 | `avm2_catchup_dobj` | 158 | 6.1s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 78.8s |  |
| 64 | `bitand` | 1058 | 17.8s |  |
| 65 | `bitmap_constr` | 17 | 5.8s |  |
| 66 | `bitmap_data` | 1000 | 13.9s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 24.5s |  |
| 68 | `bitmap_properties` | 23 | 5.6s |  |
| 69 | `bitmap_subclass` | 7 | 7.0s |  |
| 70 | `bitmap_subclass_properties` | 9 | 6.2s |  |
| 71 | `bitmap_timeline` | 9 | 5.7s |  |
| 72 | `bitmapdata_accuracy` | 1 | 43.7s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 25.6s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.6s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 24.8s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.3s |  |
| 77 | `bitmapdata_clone` | 13 | 6.1s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.2s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 5.6s |  |
| 80 | `bitmapdata_constr` | 22 | 5.7s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 5.8s |  |
| 82 | `bitmapdata_copychannel` | 0 | 26.3s |  |
| 83 | `bitmapdata_copypixels` | 23 | 24.9s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.5s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.4s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.5s |  |
| 87 | `bitmapdata_draw` | 0 | 24.2s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 5.8s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 23.6s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 23.3s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 5.5s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 5.8s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 5.7s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 23.1s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 5.6s |  |
| 96 | `bitmapdata_embedded` | 9 | 5.8s |  |
| 97 | `bitmapdata_fillrect` | 0 | 5.8s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 23.7s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.4s |  |
| 100 | `bitmapdata_getpixels` | 39 | 23.2s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.7s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.7s |  |
| 103 | `bitmapdata_hittest` | 112 | 6.0s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.4s |  |
| 105 | `bitmapdata_opaque` | 0 | 5.7s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 23.4s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 5.8s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.3s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.5s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.4s |  |
| 111 | `bitmapdata_sync` | 0 | 5.6s |  |
| 112 | `bitmapdata_threshold` | 176 | 6.1s |  |
| 113 | `bitnot` | 46 | 5.4s |  |
| 114 | `bitor` | 1058 | 17.3s |  |
| 115 | `bitxor` | 1058 | 17.4s |  |
| 116 | `blend_multiply_alpha` | 0 | 5.7s |  |
| 117 | `blend_scroll` | 0 | 5.7s |  |
| 118 | `boolean_constr` | 32 | 5.7s |  |
| 119 | `boolean_negation` | 30 | 5.7s |  |
| 120 | `boolean_tostring` | 8 | 5.7s |  |
| 121 | `broadcast_event` | 7 | 5.7s |  |
| 122 | `button_nested_frame` | 48 | 6.2s |  |
| 123 | `bytearray` | 48 | 6.0s |  |
| 124 | `bytearray_compress` | 31 | 5.9s |  |
| 125 | `bytearray_errors` | 24 | 6.0s |  |
| 126 | `bytearray_method_serialization` | 1 | 5.9s |  |
| 127 | `bytearray_readobject_amf0` | 50 | 5.9s |  |
| 128 | `bytearray_readobject_amf3` | 53 | 6.1s |  |
| 129 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 130 | `bytearray_serialization` | 3 | 6.0s |  |
| 131 | `bytearray_string_null` | 19 | 6.1s |  |
| 132 | `bytearray_tostring` | 15 | 5.9s |  |
| 133 | `bytearray_utf16` | 8 | 5.9s |  |
| 134 | `bytearray_writeobject` | 24 | 5.8s |  |
| 135 | `callee_in_initializer` | 6 | 5.8s |  |
| 136 | `callproplex_class` | 1 | 5.9s |  |
| 137 | `capabilities_resolution` | 8 | 25.8s |  |
| 138 | `catch_class` | 6 | 5.8s |  |
| 139 | `catch_scope_slot` | 7 | 3.0s |  |
| 140 | `checkfilter` | 4 | 3.0s |  |
| 141 | `class_call` | 32 | 25.4s |  |
| 142 | `class_cast_call` | 14 | 5.9s |  |
| 143 | `class_enumeration` | 4 | 5.8s |  |
| 144 | `class_has_own_property` | 2 | 5.8s |  |
| 145 | `class_init_interpreter_mode` | 1 | 5.8s |  |
| 146 | `class_is` | 32 | 5.9s |  |
| 147 | `class_methods` | 5 | 5.8s |  |
| 148 | `class_object_properties` | 10 | 5.9s |  |
| 149 | `class_singleton` | 18 | 5.8s |  |
| 150 | `class_supercalls_errors` | 35 | 6.1s |  |
| 151 | `class_supercalls_mismatched` | 26 | 5.9s |  |
| 152 | `class_superclass_wrong_order` | 1 | 26.3s |  |
| 153 | `class_to_locale_string` | 2 | 6.1s |  |
| 154 | `class_to_string` | 2 | 6.0s |  |
| 155 | `class_value_of` | 2 | 6.1s |  |
| 156 | `click_block` | 5 | 26.6s |  |
| 157 | `click_invisible` | 3 | 6.3s |  |
| 158 | `closures` | 12 | 6.2s |  |
| 159 | `coerce_return_type` | 40 | 6.3s |  |
| 160 | `coerce_return_type_fail` | 2 | 6.0s |  |
| 161 | `coerce_return_void` | 3 | 6.0s |  |
| 162 | `coerce_string` | 86 | 6.2s |  |
| 163 | `coerce_string_precision` | 28 | 6.1s |  |
| 164 | `coerce_to_primitive_side_effects` | 29 | 6.2s |  |
| 165 | `construct_errors_swf10` | 8 | 6.1s |  |
| 166 | `construct_frame_list` | 22 | 6.3s |  |
| 167 | `constructor_call` | 3 | 6.1s |  |
| 168 | `constructors_vs_timeline` | 5 | 26.3s |  |
| 169 | `constructprop_dynamic_primitive` | 7 | 6.2s |  |
| 170 | `control_flow_bool` | 4 | 6.2s |  |
| 171 | `control_flow_stricteq` | 8 | 6.1s |  |
| 172 | `convert_boolean` | 30 | 6.1s |  |
| 173 | `convert_integer` | 90 | 6.2s |  |
| 174 | `convert_number` | 56 | 6.2s |  |
| 175 | `convert_uinteger` | 90 | 6.3s |  |
| 176 | `cryptscore` | 11 | 6.3s |  |
| 177 | `date` | 30 | 6.4s |  |
| 178 | `date_parse` | 36 | 6.0s |  |
| 179 | `declocal` | 46 | 6.0s |  |
| 180 | `declocal_i` | 46 | 6.0s |  |
| 181 | `decode_uri` | 71 | 6.3s |  |
| 182 | `decrement` | 46 | 6.0s |  |
| 183 | `decrement_i` | 46 | 3.0s |  |
| 184 | `default_values` | 7 | 5.9s |  |
| 185 | `dictionary_access` | 62 | 6.1s |  |
| 186 | `dictionary_access_no_pubns` | 2 | 5.9s |  |
| 187 | `dictionary_delete` | 101 | 6.4s |  |
| 188 | `dictionary_foreach` | 42 | 6.2s |  |
| 189 | `dictionary_hasownproperty` | 63 | 6.2s |  |
| 190 | `dictionary_in` | 62 | 6.2s |  |
| 191 | `dictionary_iter_modify` | 8 | 6.0s |  |
| 192 | `dictionary_namespaces` | 36 | 6.1s |  |
| 193 | `dictionary_primitive_keys` | 29 | 6.0s |  |
| 194 | `displayobject_alpha` | 277 | 5.9s |  |
| 195 | `displayobject_blendmode` | 0 | 6.1s |  |
| 196 | `displayobject_colortransform_nested` | 0 | 25.5s |  |
| 197 | `displayobject_from_enterframe` | 1 | 6.1s |  |
| 198 | `displayobject_getbounds_shape` | 0 | 26.6s |  |
| 199 | `displayobject_height` | 6052 | 26.0s |  |
| 200 | `displayobject_hittestobject` | 32 | 6.0s |  |
| 201 | `displayobject_invalid_floats` | 60 | 6.0s |  |
| 202 | `displayobject_invalid_props` | 3 | 6.0s |  |
| 203 | `displayobject_mask` | 3 | 6.4s |  |
| 204 | `displayobject_mask_self_referential` | 0 | 5.9s |  |
| 205 | `displayobject_metaData` | 3 | 4.0s |  |
| 206 | `displayobject_name` | 22 | 4.2s |  |
| 207 | `displayobject_name_from_timeline` | 24 | 4.2s |  |
| 208 | `displayobject_parent` | 12 | 3.9s |  |
| 209 | `displayobject_root` | 24 | 4.0s |  |
| 210 | `displayobject_rotation` | 1284 | 4.5s |  |
| 211 | `displayobject_set_matrix_nested` | 0 | 18.4s |  |
| 212 | `displayobject_subclass` | 2 | 3.9s |  |
| 213 | `displayobject_visible` | 23 | 3.9s |  |
| 214 | `displayobject_width` | 4852 | 18.5s |  |
| 215 | `displayobject_x` | 614 | 3.9s |  |
| 216 | `displayobject_y` | 617 | 4.2s |  |
| 217 | `displayobjectcontainer_addchild` | 32 | 4.1s |  |
| 218 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.1s |  |
| 219 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.0s |  |
| 220 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.1s |  |
| 221 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.1s |  |
| 222 | `displayobjectcontainer_addchildat` | 42 | 4.2s |  |
| 223 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.0s |  |
| 224 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.2s |  |
| 225 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 3.9s |  |
| 226 | `displayobjectcontainer_contains` | 66 | 18.3s |  |
| 227 | `displayobjectcontainer_getchildat` | 4 | 4.5s |  |
| 228 | `displayobjectcontainer_getchildbyname` | 9 | 3.9s |  |
| 229 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 3.9s |  |
| 230 | `displayobjectcontainer_getchildindex` | 28 | 4.1s |  |
| 231 | `displayobjectcontainer_removechild` | 10 | 4.1s |  |
| 232 | `displayobjectcontainer_removechild_errors` | 4 | 4.3s |  |
| 233 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.4s |  |
| 234 | `displayobjectcontainer_removechildat` | 18 | 3.9s |  |
| 235 | `displayobjectcontainer_removechildren` | 51 | 4.1s |  |
| 236 | `displayobjectcontainer_setchildindex` | 42 | 3.9s |  |
| 237 | `displayobjectcontainer_stopallmovieclips` | 2 | 4.3s |  |
| 238 | `displayobjectcontainer_swapchildren` | 42 | 4.1s |  |
| 239 | `displayobjectcontainer_swapchildrenat` | 42 | 4.0s |  |
| 240 | `displayobjectcontainer_timelineinstance` | 48 | 18.2s |  |
| 241 | `divide` | 1058 | 17.7s |  |
| 242 | `doabc_is_eager` | 1 | 23.1s |  |
| 243 | `documentclass` | 9 | 5.6s |  |
| 244 | `domain_memory` | 133 | 6.6s |  |
| 245 | `drag_drop` | 10 | 5.7s |  |
| 246 | `duplicate_defs` | 1 | 5.4s |  |
| 247 | `eager_init` | 1 | 5.5s |  |
| 248 | `edit_text_linkage` | 7 | 5.7s |  |
| 249 | `edittext_align` | 60 | 6.0s |  |
| 250 | `edittext_always_show_selection` | 0 | 24.1s |  |
| 251 | `edittext_antialiastype` | 296 | 5.7s |  |
| 252 | `edittext_at_point_methods_basic` | 16 | 6.9s |  |
| 253 | `edittext_autosize` | 39 | 5.8s |  |
| 254 | `edittext_autosize_align` | 0 | 24.3s |  |
| 255 | `edittext_autosize_height_dynamic` | 60 | 24.1s |  |
| 256 | `edittext_autosize_height_input` | 60 | 5.6s |  |
| 257 | `edittext_autosize_lazy_bounds_events` | 65 | 5.8s |  |
| 258 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.5s |  |
| 259 | `edittext_autosize_lazy_bounds_props` | 490 | 6.9s |  |
| 260 | `edittext_autosize_lazy_bounds_visual` | 0 | 5.8s |  |
| 261 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 5.7s |  |
| 262 | `edittext_bottom_scroll_v_basic` | 210 | 5.7s |  |
| 263 | `edittext_bounds_scale` | 24 | 23.4s |  |
| 264 | `edittext_bullet` | 30 | 5.7s |  |
| 265 | `edittext_default_format` | 221 | 5.9s |  |
| 266 | `edittext_default_format_empty` | 136 | 5.8s |  |
| 267 | `edittext_empty_text_format` | 7 | 5.6s |  |
| 268 | `edittext_focus_selection` | 5 | 5.5s |  |
| 269 | `edittext_font_size` | 45 | 5.6s |  |
| 270 | `edittext_format_empty_font` | 8 | 5.5s |  |
| 271 | `edittext_get_char_index_at_point` | 4 | 24.8s |  |
| 272 | `edittext_get_line_index_at_point` | 2 | 24.1s |  |
| 273 | `edittext_get_line_index_of_char` | 76 | 6.4s |  |
| 274 | `edittext_getcharboundaries` | 172 | 5.9s |  |
| 275 | `edittext_getcharboundaries_missing_glyphs` | 63 | 37.1s |  |
| 276 | `edittext_getcharboundaries_scroll` | 85 | 5.9s |  |
| 277 | `edittext_getlinemetrics` | 146 | 6.0s |  |
| 278 | `edittext_html` | 3101 | 6.3s |  |
| 279 | `edittext_html_condensewhite` | 487 | 5.8s |  |
| 280 | `edittext_html_entity` | 4 | 6.0s |  |
| 281 | `edittext_html_font_size_swf12` | 267 | 5.8s |  |
| 282 | `edittext_html_font_size_swf13` | 273 | 5.5s |  |
| 283 | `edittext_html_roundtrip` | 17 | 5.8s |  |
| 284 | `edittext_input_control` | 12 | 5.9s |  |
| 285 | `edittext_leading` | 9 | 6.0s |  |
| 286 | `edittext_letter_spacing` | 15 | 5.8s |  |
| 287 | `edittext_line_methods` | 294 | 7.1s |  |
| 288 | `edittext_line_metrics` | 11 | 25.9s |  |
| 289 | `edittext_margins` | 25 | 5.8s |  |
| 290 | `edittext_max_scroll_h_basic` | 475 | 6.0s |  |
| 291 | `edittext_max_scroll_v_basic` | 1000 | 5.8s |  |
| 292 | `edittext_mousedown` | 3 | 6.1s |  |
| 293 | `edittext_mouseenabled` | 26 | 5.8s |  |
| 294 | `edittext_newline_character` | 22 | 5.7s |  |
| 295 | `edittext_newline_stripping` | 64 | 8.4s |  |
| 296 | `edittext_newlines` | 30 | 5.9s |  |
| 297 | `edittext_paragraph_methods` | 257 | 5.8s |  |
| 298 | `edittext_paste_events` | 8 | 5.9s |  |
| 299 | `edittext_paste_maxchars` | 4 | 5.8s |  |
| 300 | `edittext_paste_restrict` | 16 | 5.6s |  |
| 301 | `edittext_restrict` | 191 | 5.7s |  |
| 302 | `edittext_restrict_events` | 22 | 5.7s |  |
| 303 | `edittext_scrollh` | 10 | 5.7s |  |
| 304 | `edittext_selected_text` | 9 | 5.7s |  |
| 305 | `edittext_set_html_same` | 17 | 5.7s |  |
| 306 | `edittext_set_text_vs_html` | 9 | 5.7s |  |
| 307 | `edittext_stylesheet` | 536 | 6.1s |  |
| 308 | `edittext_stylesheet_custom_tag` | 76 | 5.8s |  |
| 309 | `edittext_stylesheet_display` | 272 | 5.8s |  |
| 310 | `edittext_underline` | 40 | 5.9s |  |
| 311 | `edittext_width_height` | 103 | 6.0s |  |
| 312 | `edittext_wordwrap_word` | 150 | 18.3s |  |
| 313 | `edittext_wrap_breaks` | 2375 | 6.6s |  |
| 314 | `empty_bounds` | 1 | 5.9s |  |
| 315 | `encode_uri_surrogate_pair_swf11` | 15 | 5.6s |  |
| 316 | `equals` | 512 | 9.9s |  |
| 317 | `error_prototype` | 15 | 5.9s |  |
| 318 | `error_stack_trace_debug_swf17` | 0 | 24.9s |  |
| 319 | `error_stack_trace_debug_swf18` | 0 | 5.7s |  |
| 320 | `error_stack_trace_release_swf17` | 0 | 5.8s |  |
| 321 | `error_stack_trace_release_swf18` | 0 | 5.7s |  |
| 322 | `error_tostring` | 29 | 5.9s |  |
| 323 | `es3_inheritance` | 31 | 6.0s |  |
| 324 | `es4_inheritance` | 30 | 6.0s |  |
| 325 | `es4_interfaces` | 30 | 5.9s |  |
| 326 | `es4_method_binding` | 8 | 5.9s |  |
| 327 | `es4_oop_prototypes` | 14 | 6.0s |  |
| 328 | `es4_protected_inheritance` | 6 | 5.9s |  |
| 329 | `escape` | 71 | 6.0s |  |
| 330 | `event_bubbles` | 2 | 5.8s |  |
| 331 | `event_cancelable` | 2 | 5.8s |  |
| 332 | `event_clone` | 20 | 5.9s |  |
| 333 | `event_clone_error_redispatch` | 3 | 6.0s |  |
| 334 | `event_clone_on_redispatch` | 10 | 6.1s |  |
| 335 | `event_formattostring` | 31 | 6.0s |  |
| 336 | `event_isdefaultprevented` | 12 | 5.8s |  |
| 337 | `event_target_getter` | 5 | 3.0s |  |
| 338 | `event_target_set` | 9 | 5.8s |  |
| 339 | `event_type` | 1 | 5.9s |  |
| 340 | `event_valueof_tostring` | 18 | 17.2s |  |
| 341 | `eventdispatcher_dispatchevent` | 12 | 5.6s |  |
| 342 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.6s |  |
| 343 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.6s |  |
| 344 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.6s |  |
| 345 | `eventdispatcher_dispatchevent_this` | 5 | 5.5s |  |
| 346 | `eventdispatcher_haseventlistener` | 25 | 5.6s |  |
| 347 | `eventdispatcher_interface_invoke` | 1 | 5.5s |  |
| 348 | `eventdispatcher_tostring` | 10 | 5.6s |  |
| 349 | `eventdispatcher_willtrigger` | 25 | 5.5s |  |
| 350 | `falsiness` | 30 | 5.6s |  |
| 351 | `fast_index_access` | 12 | 5.7s |  |
| 352 | `finddef` | 3 | 5.5s |  |
| 353 | `findprop_global_prototype` | 6 | 5.6s |  |
| 354 | `flash_xml` | 29 | 5.6s |  |
| 355 | `flash_xml_cloneNode` | 22 | 5.6s |  |
| 356 | `flash_xml_namespace` | 109 | 5.5s |  |
| 357 | `flash_xml_removeNode` | 60 | 5.6s |  |
| 358 | `focus_events_code` | 161 | 24.4s |  |
| 359 | `focus_events_key_same_object` | 26 | 5.7s |  |
| 360 | `focus_events_mixed_key_mouse` | 100 | 24.2s |  |
| 361 | `focus_events_mouse_same_object` | 40 | 5.8s |  |
| 362 | `focus_remove` | 20 | 24.9s |  |
| 363 | `focus_root_movie` | 4 | 25.1s |  |
| 364 | `focus_stage` | 1 | 5.9s |  |
| 365 | `focusrect` | 18 | 6.7s |  |
| 366 | `font_description_clone` | 14 | 5.8s |  |
| 367 | `font_embedded` | 24 | 6.1s |  |
| 368 | `font_enumeratefonts` | 41 | 6.3s |  |
| 369 | `font_enumeratefonts_filter` | 4 | 25.5s |  |
| 370 | `font_hasglyphs` | 40 | 6.2s |  |
| 371 | `framelabel_constr` | 5 | 5.8s |  |
| 372 | `function_call` | 12 | 5.9s |  |
| 373 | `function_call_arguments` | 46 | 5.9s |  |
| 374 | `function_call_arguments_enumerate` | 5 | 5.8s |  |
| 375 | `function_call_coercion` | 108 | 6.2s |  |
| 376 | `function_call_default` | 6 | 5.8s |  |
| 377 | `function_call_rest` | 22 | 5.8s |  |
| 378 | `function_call_types` | 3 | 5.8s |  |
| 379 | `function_call_via_apply` | 11 | 5.8s |  |
| 380 | `function_call_via_call` | 3 | 5.8s |  |
| 381 | `function_display_anonymous` | 7 | 2.9s |  |
| 382 | `function_length` | 6 | 5.8s |  |
| 383 | `function_object` | 2 | 5.8s |  |
| 384 | `function_proto` | 5 | 5.8s |  |
| 385 | `function_proto_created` | 61 | 6.0s |  |
| 386 | `function_to_locale_string` | 4 | 5.9s |  |
| 387 | `function_to_string` | 4 | 5.8s |  |
| 388 | `function_type` | 6 | 5.8s |  |
| 389 | `function_unbound_this` | 51 | 5.9s |  |
| 390 | `function_value_of` | 4 | 5.8s |  |
| 391 | `get_definition_by_name` | 11 | 5.8s |  |
| 392 | `get_qualified_class_name` | 20 | 5.9s |  |
| 393 | `get_qualified_super_class_name` | 18 | 16.4s |  |
| 394 | `get_slot_edge_cases` | 1 | 22.6s |  |
| 395 | `get_timer` | 2 | 5.1s |  |
| 396 | `getglobalslot` | 1 | 4.9s |  |
| 397 | `getouterscope` | 8 | 4.9s |  |
| 398 | `getter_different_namespace_setter` | 2 | 4.9s |  |
| 399 | `goto_button_nested_framescript` | 28 | 5.3s |  |
| 400 | `goto_in_constructframe` | 12 | 5.1s |  |
| 401 | `goto_in_scene_last_frame` | 2 | 22.7s |  |
| 402 | `goto_methods` | 56 | 5.2s |  |
| 403 | `goto_methods_swfver10` | 8 | 5.0s |  |
| 404 | `goto_nested_construct_sibling` | 18 | 5.4s |  |
| 405 | `goto_nested_framescript` | 9 | 5.1s |  |
| 406 | `goto_on_orphan` | 15 | 5.2s |  |
| 407 | `graphics_bad_direct_commands` | 5 | 5.7s |  |
| 408 | `graphics_bitmap_fill` | 0 | 6.6s |  |
| 409 | `graphics_bitmaps` | 0 | 5.7s |  |
| 410 | `graphics_direct_commands` | 0 | 5.6s |  |
| 411 | `graphics_draw_triangles` | 98 | 23.6s |  |
| 412 | `graphics_gradients` | 0 | 5.3s |  |
| 413 | `graphics_gradients_nulls` | 0 | 5.3s |  |
| 414 | `graphics_path` | 56 | 5.0s |  |
| 415 | `graphics_round_rects` | 0 | 5.0s |  |
| 416 | `graphics_simple_shapes` | 0 | 5.2s |  |
| 417 | `greaterequals` | 512 | 7.8s |  |
| 418 | `greaterthan` | 512 | 7.8s |  |
| 419 | `has_own_property` | 102 | 5.4s |  |
| 420 | `hasownproperty_namespaces` | 2 | 4.9s |  |
| 421 | `hello_world` | 1 | 5.0s |  |
| 422 | `hittest_morph` | 30 | 5.1s |  |
| 423 | `if_eq` | 10 | 5.0s |  |
| 424 | `if_gt` | 1 | 5.0s |  |
| 425 | `if_gte` | 10 | 2.2s |  |
| 426 | `if_lt` | 1 | 14.1s |  |
| 427 | `if_lte` | 10 | 4.8s |  |
| 428 | `if_ne` | 7 | 2.5s |  |
| 429 | `if_stricteq` | 6 | 5.0s |  |
| 430 | `if_strictne` | 11 | 4.8s |  |
| 431 | `in` | 102 | 5.1s |  |
| 432 | `inclocal` | 46 | 4.8s |  |
| 433 | `inclocal_i` | 46 | 4.8s |  |
| 434 | `increment` | 46 | 4.8s |  |
| 435 | `increment_i` | 46 | 4.8s |  |
| 436 | `indexing_delete` | 75 | 4.7s |  |
| 437 | `instanceof` | 58 | 5.0s |  |
| 438 | `instantiation_on_enter_frame` | 7 | 20.3s |  |
| 439 | `instantiation_on_enterframe_gotoandstop` | 8 | 4.8s |  |
| 440 | `int_constr` | 92 | 4.9s |  |
| 441 | `int_edge_cases` | 19 | 4.7s |  |
| 442 | `int_instanceof` | 3 | 4.7s |  |
| 443 | `int_tofixed` | 1215 | 4.7s |  |
| 444 | `int_tostring` | 3375 | 4.9s |  |
| 445 | `interactiveobject_enabled` | 25 | 4.7s |  |
| 446 | `interface_namespaces` | 78 | 4.9s |  |
| 447 | `is_finite` | 46 | 4.8s |  |
| 448 | `is_nan` | 46 | 4.7s |  |
| 449 | `is_prototype_of` | 12 | 4.7s |  |
| 450 | `issue_10221` | 2 | 4.6s |  |
| 451 | `issue_13780` | 12 | 4.7s |  |
| 452 | `issue_14901` | 1 | 4.7s |  |
| 453 | `issue_17675_edittext_paste_maxchars` | 1 | 4.7s |  |
| 454 | `issue_5292` | 5 | 4.7s |  |
| 455 | `issue_8630` | 2 | 20.4s |  |
| 456 | `issue_8630_scriptremove` | 11 | 4.8s |  |
| 457 | `istype` | 24 | 2.4s |  |
| 458 | `istypelate` | 58 | 5.0s |  |
| 459 | `istypelate_coerce` | 198 | 5.6s |  |
| 460 | `json_errors` | 9 | 21.5s |  |
| 461 | `json_parse` | 21 | 5.0s |  |
| 462 | `json_stringify` | 12 | 5.1s |  |
| 463 | `json_stringify_order` | 1 | 4.9s |  |
| 464 | `json_version_gated` | 1 | 4.9s |  |
| 465 | `key_input_80percent` | 1812 | 5.1s |  |
| 466 | `key_input_location` | 126 | 5.0s |  |
| 467 | `key_input_numpad` | 384 | 5.0s |  |
| 468 | `lazyinit` | 17 | 5.0s |  |
| 469 | `lessequals` | 512 | 8.3s |  |
| 470 | `lessthan` | 512 | 8.3s |  |
| 471 | `loaderinfo_properties` | 18 | 5.8s |  |
| 472 | `loaderinfo_root` | 10 | 5.8s |  |
| 473 | `loaderinfo_root_allows` | 2 | 5.8s |  |
| 474 | `lshift` | 1058 | 18.4s |  |
| 475 | `mask_reapply` | 1 | 6.0s |  |
| 476 | `math` | 497 | 6.1s |  |
| 477 | `missing_external_interface` | 10 | 5.8s |  |
| 478 | `modulo` | 1058 | 18.4s |  |
| 479 | `morph_shape` | 2 | 25.1s |  |
| 480 | `mouse_click_events` | 90 | 25.5s |  |
| 481 | `mouse_double_click_events` | 188 | 5.9s |  |
| 482 | `mouse_empty_parent` | 4 | 5.9s |  |
| 483 | `mouse_over_while_dragging` | 3 | 6.0s |  |
| 484 | `mouse_pick_button_mode` | 2 | 6.0s |  |
| 485 | `mouse_sibling` | 8 | 5.9s |  |
| 486 | `movieclip_addframescript` | 3 | 25.1s |  |
| 487 | `movieclip_child_property` | 16 | 5.9s |  |
| 488 | `movieclip_constr` | 21 | 5.8s |  |
| 489 | `movieclip_currentlabels` | 17 | 35.0s |  |
| 490 | `movieclip_currentlabels_dupes1` | 46 | 23.6s |  |
| 491 | `movieclip_currentlabels_dupes2` | 30 | 5.5s |  |
| 492 | `movieclip_currentlabels_dupes3` | 67 | 5.5s |  |
| 493 | `movieclip_currentscene` | 12 | 5.6s |  |
| 494 | `movieclip_dispatchevent` | 430 | 5.8s |  |
| 495 | `movieclip_dispatchevent_cancel` | 102 | 5.6s |  |
| 496 | `movieclip_dispatchevent_handlerorder` | 251 | 5.6s |  |
| 497 | `movieclip_dispatchevent_selfadd` | 80 | 5.5s |  |
| 498 | `movieclip_dispatchevent_target` | 899 | 5.6s |  |
| 499 | `movieclip_displayevents` | 96 | 23.9s |  |
| 500 | `movieclip_displayevents_clickgoto` | 676 | 5.9s |  |
| 501 | `movieclip_displayevents_clickgoto2` | 2001 | 6.0s |  |
| 502 | `movieclip_displayevents_clickplay` | 575 | 5.7s |  |
| 503 | `movieclip_displayevents_clicksymbol` | 562 | 5.7s |  |
| 504 | `movieclip_displayevents_constructframegoto` | 140 | 5.9s |  |
| 505 | `movieclip_displayevents_constructframeplay` | 50 | 5.8s |  |
| 506 | `movieclip_displayevents_constructframesymbol` | 144 | 5.7s |  |
| 507 | `movieclip_displayevents_dblhandler` | 21 | 5.7s |  |
| 508 | `movieclip_displayevents_enterframegoto` | 149 | 5.8s |  |
| 509 | `movieclip_displayevents_enterframeplay` | 48 | 5.6s |  |
| 510 | `movieclip_displayevents_enterframesymbol` | 149 | 23.9s |  |
| 511 | `movieclip_displayevents_exitframegoto` | 106 | 5.6s |  |
| 512 | `movieclip_displayevents_exitframeplay` | 44 | 5.6s |  |
| 513 | `movieclip_displayevents_exitframesymbol` | 135 | 5.7s |  |
| 514 | `movieclip_displayevents_looping` | 63 | 23.8s |  |
| 515 | `movieclip_displayevents_stopped` | 113 | 5.9s |  |
| 516 | `movieclip_displayevents_swap` | 96 | 2.5s |  |
| 517 | `movieclip_displayevents_timeline` | 128 | 24.0s |  |
| 518 | `movieclip_drawrect` | 54 | 5.5s |  |
| 519 | `movieclip_frameconstruct_skipped` | 9 | 5.7s |  |
| 520 | `movieclip_goto_during_frame_script` | 15 | 5.6s |  |
| 521 | `movieclip_goto_overwrite` | 14 | 23.6s |  |
| 522 | `movieclip_goto_scene_last_frame_int` | 1 | 23.8s |  |
| 523 | `movieclip_goto_scene_last_frame_label` | 1 | 5.4s |  |
| 524 | `movieclip_gotoandplay` | 15 | 23.5s |  |
| 525 | `movieclip_gotoandstop` | 13 | 5.5s |  |
| 526 | `movieclip_gotoandstop_children` | 4 | 5.6s |  |
| 527 | `movieclip_gotoandstop_framescripts1` | 4 | 5.5s |  |
| 528 | `movieclip_gotoandstop_framescripts2` | 4 | 2.6s |  |
| 529 | `movieclip_gotoandstop_framescripts_self` | 7 | 5.5s |  |
| 530 | `movieclip_gotoandstop_queueing` | 12 | 36.0s |  |
| 531 | `movieclip_next_frame` | 2 | 5.8s |  |
| 532 | `movieclip_next_scene` | 6 | 24.0s |  |
| 533 | `movieclip_play` | 3 | 5.6s |  |
| 534 | `movieclip_prev_frame` | 3 | 5.5s |  |
| 535 | `movieclip_prev_scene` | 7 | 5.8s |  |
| 536 | `movieclip_properties` | 79 | 6.0s |  |
| 537 | `movieclip_queued_noop_goto_swf10` | 9 | 5.7s |  |
| 538 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 539 | `movieclip_scenes` | 11 | 5.5s |  |
| 540 | `movieclip_soundtransform` | 831 | 26.0s |  |
| 541 | `movieclip_stop` | 1 | 5.5s |  |
| 542 | `movieclip_super_is_symbol` | 20 | 5.8s |  |
| 543 | `movieclip_symbol_constr` | 8 | 5.6s |  |
| 544 | `movieclip_text_mousedown` | 1 | 5.5s |  |
| 545 | `movieclip_willtrigger` | 5 | 5.7s |  |
| 546 | `multiply` | 1058 | 17.7s |  |
| 547 | `namespace_constr` | 253 | 5.8s |  |
| 548 | `namespace_constr_args` | 1 | 5.4s |  |
| 549 | `namespace_enumeration_order` | 7 | 5.4s |  |
| 550 | `nan_scale` | 9 | 5.5s |  |
| 551 | `negate` | 30 | 5.6s |  |
| 552 | `negative_volume_panned` | 0 | 5.8s |  |
| 553 | `nested_iteration` | 11 | 5.6s |  |
| 554 | `net_getClassByAlias` | 3 | 5.7s |  |
| 555 | `newactivation_in_script_init` | 3 | 5.6s |  |
| 556 | `newclass_twice` | 3 | 5.4s |  |
| 557 | `nonconflicting_declarations` | 0 | 5.5s |  |
| 558 | `null_void_types` | 8 | 5.5s |  |
| 559 | `number_autoconv` | 21 | 5.5s |  |
| 560 | `number_autoconv_amf` | 132 | 5.5s |  |
| 561 | `number_autoconv_array_sort_32bit` | 1 | 5.5s |  |
| 562 | `number_constr` | 58 | 5.6s |  |
| 563 | `number_toexponential` | 378 | 5.6s |  |
| 564 | `number_toexponential2` | 35 | 5.5s |  |
| 565 | `number_tofixed` | 378 | 5.4s |  |
| 566 | `number_toprecision` | 350 | 5.5s |  |
| 567 | `obfuscated_class_names` | 3 | 5.4s |  |
| 568 | `object_enumeration` | 10 | 5.5s |  |
| 569 | `object_prototype` | 4 | 5.5s |  |
| 570 | `object_to_locale_string` | 2 | 5.5s |  |
| 571 | `object_to_string` | 2 | 5.4s |  |
| 572 | `object_value_of` | 2 | 2.5s |  |
| 573 | `op_coerce` | 54 | 5.6s |  |
| 574 | `op_coerce_x` | 54 | 5.6s |  |
| 575 | `op_escxattr` | 2 | 5.5s |  |
| 576 | `op_escxelem` | 2 | 5.5s |  |
| 577 | `op_lookupswitch` | 4 | 5.5s |  |
| 578 | `optimize_coerce` | 1 | 5.4s |  |
| 579 | `orphan_movie_complex` | 80 | 5.8s |  |
| 580 | `orphan_movie_reorder` | 111 | 24.0s |  |
| 581 | `package_namespace` | 7 | 5.4s |  |
| 582 | `param_default_value_has_zero_cpool_index` | 1 | 5.3s |  |
| 583 | `parent_early_access_child` | 16 | 5.8s |  |
| 584 | `parse_float` | 81 | 5.8s |  |
| 585 | `pixelbender_effect_BlurredFocus` | 0 | 22.3s |  |
| 586 | `pixelbender_effect_glassDisplace` | 0 | 9.8s |  |
| 587 | `pixelbender_effect_smudge` | 0 | 7.4s |  |
| 588 | `pixelbender_effect_tintype` | 0 | 6.7s |  |
| 589 | `pixelbender_effect_twirl` | 0 | 7.4s |  |
| 590 | `pixelbender_images` | 0 | 6.4s |  |
| 591 | `place_multiple` | 17 | 18.7s |  |
| 592 | `place_object_replace` | 9 | 4.5s |  |
| 593 | `place_object_replace_2` | 24 | 4.6s |  |
| 594 | `place_object_same_depth_frame` | 1 | 4.5s |  |
| 595 | `point` | 132 | 4.9s |  |
| 596 | `primitive_edge_cases` | 1 | 4.3s |  |
| 597 | `property_priority` | 22 | 5.9s |  |
| 598 | `property_priority_three_level` | 6 | 24.4s |  |
| 599 | `propertyisenumerable_namespaces` | 6 | 5.7s |  |
| 600 | `prototype_set_null` | 7 | 5.6s |  |
| 601 | `proxy_callproperty` | 24 | 5.6s |  |
| 602 | `proxy_deleteproperty` | 64 | 5.6s |  |
| 603 | `proxy_enumeration` | 34 | 5.7s |  |
| 604 | `proxy_getproperty` | 77 | 5.8s |  |
| 605 | `proxy_hasownproperty` | 8 | 5.6s |  |
| 606 | `proxy_hasproperty` | 32 | 5.6s |  |
| 607 | `proxy_serialize` | 9 | 5.7s |  |
| 608 | `proxy_setproperty` | 42 | 5.6s |  |
| 609 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.5s |  |
| 610 | `qname_constr` | 32 | 5.6s |  |
| 611 | `qname_constr_namespace` | 24 | 5.6s |  |
| 612 | `qname_enumeration` | 9 | 5.6s |  |
| 613 | `qname_indexing` | 23 | 5.6s |  |
| 614 | `qname_tostring` | 25 | 5.6s |  |
| 615 | `qname_valueof` | 29 | 5.6s |  |
| 616 | `regexp_constr` | 148 | 5.8s |  |
| 617 | `regexp_exec` | 19 | 5.6s |  |
| 618 | `regexp_extended` | 47 | 5.6s |  |
| 619 | `regexp_multiargs` | 1 | 5.5s |  |
| 620 | `regexp_test` | 27 | 5.7s |  |
| 621 | `regexp_toString` | 10 | 5.6s |  |
| 622 | `register_script_refresh` | 35 | 6.1s |  |
| 623 | `remove_child_clear_field` | 88 | 5.9s |  |
| 624 | `remove_dobj` | 3 | 5.5s |  |
| 625 | `resolve_order` | 4 | 5.5s |  |
| 626 | `rng` | 1 | 6.8s |  |
| 627 | `rootless` | 42 | 5.7s |  |
| 628 | `rshift` | 1058 | 29.5s |  |
| 629 | `sandbox_type_local_file` | 1 | 5.5s |  |
| 630 | `scene_constr` | 8 | 5.7s |  |
| 631 | `set_local_0` | 31 | 5.7s |  |
| 632 | `set_property_is_enumerable` | 85 | 6.1s |  |
| 633 | `shape_drawrect` | 54 | 5.5s |  |
| 634 | `shared_object_no_root` | 3 | 5.5s |  |
| 635 | `simplebutton_added_to_stage` | 45 | 23.5s |  |
| 636 | `simplebutton_childevents` | 86 | 6.0s |  |
| 637 | `simplebutton_childevents_nested` | 54 | 5.8s |  |
| 638 | `simplebutton_childevents_sprite` | 13 | 5.6s |  |
| 639 | `simplebutton_childprops` | 144 | 5.8s |  |
| 640 | `simplebutton_childshuffle` | 23 | 5.5s |  |
| 641 | `simplebutton_constr` | 36 | 5.8s |  |
| 642 | `simplebutton_constr_childevents` | 48 | 5.8s |  |
| 643 | `simplebutton_constr_params` | 42 | 5.7s |  |
| 644 | `simplebutton_mouseenabled` | 26 | 5.6s |  |
| 645 | `simplebutton_multi_children` | 19 | 5.8s |  |
| 646 | `simplebutton_structure` | 27 | 5.8s |  |
| 647 | `simplebutton_symbolclass` | 68 | 5.9s |  |
| 648 | `slot_disp_id_shared_numbering` | 1 | 23.4s |  |
| 649 | `slots_force_autoassigned` | 1 | 5.5s |  |
| 650 | `sound_embeddedprops` | 26 | 5.4s |  |
| 651 | `sound_play` | 19 | 5.5s |  |
| 652 | `sound_valueof` | 33 | 5.4s |  |
| 653 | `soundchannel_soundtransform` | 835 | 25.4s |  |
| 654 | `soundchannel_soundtransform_exists` | 5 | 23.6s |  |
| 655 | `soundchannel_stop` | 8 | 5.4s |  |
| 656 | `soundmixer_buffertime` | 5 | 5.1s |  |
| 657 | `soundmixer_stopall` | 6 | 5.3s |  |
| 658 | `soundtransform` | 442 | 9.4s |  |
| 659 | `sprite_with_frames` | 0 | 5.9s |  |
| 660 | `stage3d_agal_cross_product` | 0 | 7.6s |  |
| 661 | `stage3d_bitmap` | 0 | 28.5s |  |
| 662 | `stage3d_float1_index` | 0 | 25.9s |  |
| 663 | `stage3d_fractal` | 0 | 8.2s |  |
| 664 | `stage3d_ignore_sampler_override` | 0 | 26.4s |  |
| 665 | `stage3d_program_constants_bytearray_be` | 0 | 27.4s |  |
| 666 | `stage3d_program_constants_bytearray_le` | 0 | 8.4s |  |
| 667 | `stage3d_raytrace` | 0 | 41.3s |  |
| 668 | `stage3d_rotating_cube` | 0 | 8.9s |  |
| 669 | `stage3d_sampler` | 0 | 8.2s |  |
| 670 | `stage3d_sampler_partial_upload` | 0 | 8.1s |  |
| 671 | `stage3d_stencil` | 0 | 28.4s |  |
| 672 | `stage3d_texture` | 0 | 12.8s |  |
| 673 | `stage3d_texture_bytearray` | 0 | 9.3s |  |
| 674 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.7s |  |
| 675 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.9s |  |
| 676 | `stage3d_triangle` | 0 | 8.2s |  |
| 677 | `stage3d_triangle_bytes4` | 0 | 8.2s |  |
| 678 | `stage3d_triangle_float1` | 0 | 8.1s |  |
| 679 | `stage3d_triangle_index_upload` | 0 | 8.1s |  |
| 680 | `stage_access` | 10 | 5.4s |  |
| 681 | `stage_displayobject_properties` | 24 | 5.4s |  |
| 682 | `stage_framerate_nan` | 7 | 5.6s |  |
| 683 | `stage_framerate_negative` | 6 | 5.5s |  |
| 684 | `stage_framerate_zero` | 6 | 5.5s |  |
| 685 | `stage_invalidate` | 38 | 5.6s |  |
| 686 | `stage_mousechildren` | 2 | 5.4s |  |
| 687 | `stage_mouseenabled` | 15 | 5.4s |  |
| 688 | `stage_overriden_setters` | 31 | 5.6s |  |
| 689 | `stage_properties` | 30 | 5.4s |  |
| 690 | `static_var_with_this_in_ctor` | 2 | 5.4s |  |
| 691 | `stored_properties` | 11 | 5.5s |  |
| 692 | `strict_equality` | 34 | 5.5s |  |
| 693 | `string_call` | 13 | 5.5s |  |
| 694 | `string_case` | 23 | 5.4s |  |
| 695 | `string_char_at` | 27 | 5.5s |  |
| 696 | `string_char_code_at` | 28 | 5.4s |  |
| 697 | `string_concat_fromcharcode` | 37 | 36.2s |  |
| 698 | `string_constr` | 25 | 5.8s |  |
| 699 | `string_indexof_lastindexof` | 87 | 5.9s |  |
| 700 | `string_length` | 16 | 5.7s |  |
| 701 | `string_locale_compare` | 39 | 6.0s |  |
| 702 | `string_match` | 51 | 5.9s |  |
| 703 | `string_relational_compare` | 4 | 5.7s |  |
| 704 | `string_replace` | 51 | 5.9s |  |
| 705 | `string_search` | 41 | 5.9s |  |
| 706 | `string_slice_substr_substring` | 170 | 6.7s |  |
| 707 | `string_split` | 29 | 5.8s |  |
| 708 | `string_substr_negative` | 21 | 5.7s |  |
| 709 | `string_substr_weird` | 182 | 5.7s |  |
| 710 | `subtract` | 1058 | 17.0s |  |
| 711 | `super_get_call` | 12 | 5.8s |  |
| 712 | `supercall_two_classobjects` | 2 | 5.7s |  |
| 713 | `swf8` | 1 | 5.6s |  |
| 714 | `swf_10_queued_goto_scripts_construct` | 52 | 6.0s |  |
| 715 | `swf_9_goto_in_enter_frame` | 17 | 5.9s |  |
| 716 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.8s |  |
| 717 | `swf_9_queued_goto_scripts` | 6 | 5.9s |  |
| 718 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 719 | `swf_9_versioning` | 2 | 5.8s |  |
| 720 | `swf_wrong_frame_count` | 38 | 6.0s |  |
| 721 | `swf_wrong_frame_count_isplaying` | 22 | 5.8s |  |
| 722 | `symbol_class_binary_data` | 8 | 5.8s |  |
| 723 | `symbol_class_conflict` | 4 | 6.4s |  |
| 724 | `symbol_class_root_not_zero` | 1 | 5.7s |  |
| 725 | `symbolclass_invalid_utf8` | 2 | 5.8s |  |
| 726 | `tab_ordering_automatic_advanced` | 184 | 6.1s |  |
| 727 | `tab_ordering_automatic_basic` | 45 | 5.6s |  |
| 728 | `tab_ordering_children` | 116 | 5.7s |  |
| 729 | `tab_ordering_custom_basic` | 34 | 5.5s |  |
| 730 | `text_engine_fontdescription` | 27 | 5.7s |  |
| 731 | `text_run` | 7 | 5.4s |  |
| 732 | `textfield_focusin_event` | 9 | 5.5s |  |
| 733 | `textfield_input_dead_keys_windows` | 15 | 5.6s |  |
| 734 | `textfield_unload` | 39 | 23.6s |  |
| 735 | `textformat` | 1134 | 5.6s |  |
| 736 | `textformat_display` | 14 | 5.6s |  |
| 737 | `textformat_font_max_length` | 4 | 5.5s |  |
| 738 | `throw` | 3 | 5.5s |  |
| 739 | `timeline_scripts` | 3 | 5.7s |  |
| 740 | `timer` | 90 | 6.1s |  |
| 741 | `timer_events` | 3 | 5.7s |  |
| 742 | `timer_finished` | 11 | 5.7s |  |
| 743 | `timer_reset` | 8 | 5.7s |  |
| 744 | `timer_setdelay` | 5 | 5.5s |  |
| 745 | `trace` | 12 | 5.5s |  |
| 746 | `truthiness` | 30 | 16.5s |  |
| 747 | `try_catch` | 11 | 4.7s |  |
| 748 | `try_catch_typed` | 12 | 4.6s |  |
| 749 | `typeof` | 30 | 4.5s |  |
| 750 | `uint_constr` | 92 | 4.7s |  |
| 751 | `uint_tofixed` | 1215 | 4.4s |  |
| 752 | `uint_tostring` | 3375 | 4.8s |  |
| 753 | `unchecked_function` | 15 | 4.5s |  |
| 754 | `unescape` | 28 | 4.6s |  |
| 755 | `urlrequest` | 18 | 4.5s |  |
| 756 | `urshift` | 1058 | 16.4s |  |
| 757 | `vector_class` | 36 | 4.9s |  |
| 758 | `vector_class_call` | 11 | 4.7s |  |
| 759 | `vector_coercion` | 66 | 5.3s |  |
| 760 | `vector_concat` | 90 | 5.1s |  |
| 761 | `vector_constr` | 107 | 5.2s |  |
| 762 | `vector_enumeration` | 5 | 4.5s |  |
| 763 | `vector_every` | 92 | 5.3s |  |
| 764 | `vector_filter` | 95 | 5.4s |  |
| 765 | `vector_holes` | 24 | 4.6s |  |
| 766 | `vector_indexof` | 302 | 9.3s |  |
| 767 | `vector_insertat` | 270 | 5.6s |  |
| 768 | `vector_int_access` | 4 | 4.5s |  |
| 769 | `vector_int_delete` | 11 | 4.5s |  |
| 770 | `vector_join` | 58 | 4.9s |  |
| 771 | `vector_lastindexof` | 302 | 4.4s |  |
| 772 | `vector_legacy` | 10 | 4.5s |  |
| 773 | `vector_map` | 85 | 5.2s |  |
| 774 | `vector_object_final` | 1 | 4.4s |  |
| 775 | `vector_object_toString` | 10 | 4.5s |  |
| 776 | `vector_pushpop` | 255 | 5.8s |  |
| 777 | `vector_reborrow_bug` | 10 | 20.1s |  |
| 778 | `vector_removeat` | 172 | 6.9s |  |
| 779 | `vector_reverse` | 232 | 6.9s |  |
| 780 | `vector_shiftunshift` | 252 | 7.0s |  |
| 781 | `vector_slice` | 331 | 7.5s |  |
| 782 | `vector_sort` | 905 | 15.3s |  |
| 783 | `vector_splice` | 693 | 9.7s |  |
| 784 | `vector_splice_fixed_bug_compat` | 4 | 5.7s |  |
| 785 | `vector_tostring` | 79 | 6.3s |  |
| 786 | `verify_abnormal_loop` | 1 | 5.5s |  |
| 787 | `verify_exception_targets_edge_case` | 1 | 5.6s |  |
| 788 | `verify_lookup_switch_edge_case` | 1 | 5.5s |  |
| 789 | `verify_unreachable_exception` | 2 | 5.4s |  |
| 790 | `versioned_isplaying` | 2 | 5.5s |  |
| 791 | `virtual_properties` | 16 | 5.5s |  |
| 792 | `with` | 4 | 5.5s |  |
| 793 | `xml_abstract_equality` | 36 | 5.7s |  |
| 794 | `xml_advanced` | 52 | 5.5s |  |
| 795 | `xml_appendchild` | 10 | 5.5s |  |
| 796 | `xml_as_attribute` | 9 | 5.4s |  |
| 797 | `xml_attribute` | 35 | 5.6s |  |
| 798 | `xml_attribute_name` | 40 | 5.5s |  |
| 799 | `xml_basic` | 33 | 5.5s |  |
| 800 | `xml_child` | 25 | 5.6s |  |
| 801 | `xml_childindex` | 7 | 5.5s |  |
| 802 | `xml_children` | 43 | 6.0s |  |
| 803 | `xml_class_call` | 9 | 5.5s |  |
| 804 | `xml_contains` | 197 | 5.7s |  |
| 805 | `xml_copy` | 20 | 18.3s |  |
| 806 | `xml_ctor_from_tostring` | 23 | 6.2s |  |
| 807 | `xml_delete` | 114 | 5.9s |  |
| 808 | `xml_descendants` | 83 | 5.8s |  |
| 809 | `xml_elements` | 6 | 5.7s |  |
| 810 | `xml_equals_namespace_check` | 2 | 5.5s |  |
| 811 | `xml_explicit_use_namespace` | 5 | 23.7s |  |
| 812 | `xml_getdescendants_qname` | 21 | 5.5s |  |
| 813 | `xml_has_property_via_in` | 26 | 5.7s |  |
| 814 | `xml_hasownproperty` | 6 | 5.6s |  |
| 815 | `xml_ignore_white` | 6 | 5.6s |  |
| 816 | `xml_length` | 2 | 5.5s |  |
| 817 | `xml_list_as_attribute` | 9 | 5.5s |  |
| 818 | `xml_list_concat` | 20 | 5.7s |  |
| 819 | `xml_list_enumerate` | 4 | 5.7s |  |
| 820 | `xml_methods_settings` | 3 | 5.7s |  |
| 821 | `xml_mismatched_tag` | 37 | 5.8s |  |
| 822 | `xml_namespace` | 39 | 5.7s |  |
| 823 | `xml_namespace_methods` | 245 | 5.7s |  |
| 824 | `xml_namespaced_property` | 7 | 5.6s |  |
| 825 | `xml_no_namespace` | 1 | 5.5s |  |
| 826 | `xml_nodekind` | 3 | 5.6s |  |
| 827 | `xml_normalize` | 35 | 5.6s |  |
| 828 | `xml_notification_bubbling` | 361 | 5.6s |  |
| 829 | `xml_parent` | 8 | 5.6s |  |
| 830 | `xml_set_children` | 17 | 5.8s |  |
| 831 | `xml_set_name` | 34 | 5.6s |  |
| 832 | `xml_settings` | 6 | 2.7s |  |
| 833 | `xml_simple_complex_content` | 47 | 5.6s |  |
| 834 | `xml_text` | 7 | 5.7s |  |
| 835 | `xml_tostring` | 6 | 5.6s |  |
| 836 | `xml_tostring_namespace` | 12 | 5.5s |  |
| 837 | `xml_unescaping` | 23 | 5.6s |  |
| 838 | `xml_weird_ignores` | 54 | 5.7s |  |
| 839 | `xml_wildcard` | 11 | 5.6s |  |
| 840 | `xmldocument` | 254 | 5.7s |  |
| 841 | `xmlnode` | 3540 | 5.8s |  |
| 842 | `zero_frame_clip` | 3 | 6.0s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 5.6s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 5.6s |  |
| 3 | `blend_transform` | 1 | 1 | 5.8s |  |
| 4 | `coerce_property` | 3 | 3 | 6.3s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.2s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 6.2s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 5.8s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 5.5s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 5.8s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.9s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.0s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.7s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 22.8s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 23.6s |  |
| 15 | `int_toexponential` | 76 | 76 | 4.8s |  |
| 16 | `int_toprecision` | 441 | 441 | 4.9s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 5.8s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.5s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 23.5s |  |
| 20 | `soundchannel_position` | 74 | 74 | 24.5s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 5.4s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 5.2s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 6.1s |  |
| 24 | `uint_toexponential` | 100 | 100 | 4.7s |  |
| 25 | `uint_toprecision` | 433 | 433 | 4.7s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 5.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**67 tests** within reach

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
| 18 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 19 | `stage_loaderinfo_properties` | 91.7% | 22 | 24 | 2 |  |
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
| 35 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 36 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 37 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 38 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 39 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 40 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 41 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 42 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 43 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 44 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 45 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 46 | `loaderinfo_loadurl` | 66.7% | 8 | 12 | 4 |  |
| 47 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 48 | `loaderinfo_properties_not_loaded` | 65.2% | 15 | 23 | 8 |  |
| 49 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 50 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 51 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 52 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 53 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 54 | `loaderinfo_events` | 57.1% | 4 | 7 | 3 |  |
| 55 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 56 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 57 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 58 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 59 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 60 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 61 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 62 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 63 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 64 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 65 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 66 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 67 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.0s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 5.6s |  |
| 3 | `verify_typecheck` | exit code 1 | 5.4s |  |

## Timeouts

**1 tests** timed out

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `bytearray_oom` | runtime timeout (>10s) | 35.8s |  |

## All Output Mismatches

**346 tests** with output mismatch, sorted by match rate (best first)

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
| 18 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 19 | `stage_loaderinfo_properties` | 91.7% | 22/24 | 24 | 24 |  |
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
| 35 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 36 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 37 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 38 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 39 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 40 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 41 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 42 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 43 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 44 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 45 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 46 | `loaderinfo_loadurl` | 66.7% | 8/12 | 12 | 12 |  |
| 47 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 48 | `loaderinfo_properties_not_loaded` | 65.2% | 15/23 | 23 | 23 |  |
| 49 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 50 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 51 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 52 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 53 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 54 | `loaderinfo_events` | 57.1% | 4/7 | 6 | 7 |  |
| 55 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 56 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 57 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 58 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 59 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 60 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 61 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 62 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 63 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 64 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 65 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 66 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 67 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 68 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
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
| 84 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 85 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 86 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 87 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 88 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 89 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 90 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 91 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 92 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 93 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 94 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 95 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 96 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 97 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 98 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 99 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 100 | `loader_reuse` | 18.4% | 7/38 | 13 | 38 |  |
| 101 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 102 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 103 | `large_preload_image_from_bytes` | 16.0% | 4/25 | 19 | 25 |  |
| 104 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 105 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 106 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 107 | `wrong_arg_count` | 14.3% | 1/7 | 7 | 7 |  |
| 108 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 109 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 110 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 111 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 112 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 113 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 114 | `delayed_symbolclass` | 10.7% | 3/28 | 26 | 28 |  |
| 115 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 116 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 117 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 118 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 119 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 120 | `loader_events` | 8.7% | 8/92 | 20 | 92 |  |
| 121 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 122 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 123 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 124 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 125 | `large_preload_from_bytes` | 7.8% | 4/51 | 20 | 51 |  |
| 126 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 127 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 128 | `loader_bitmap_transparency` | 7.1% | 1/14 | 1 | 14 |  |
| 129 | `loader_bytes_unknown_content` | 7.1% | 1/14 | 4 | 14 |  |
| 130 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 131 | `loader_loadbytes_events` | 6.7% | 2/30 | 7 | 30 |  |
| 132 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 133 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 134 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 135 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 136 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 137 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 138 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 139 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 140 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 141 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 142 | `font_registerfont` | 3.9% | 5/129 | 5 | 129 |  |
| 143 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 144 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 145 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 146 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 147 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 148 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 149 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 150 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 151 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 152 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 153 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 154 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 155 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 156 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 157 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 158 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 159 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 160 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 161 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 162 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 163 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 164 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 165 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 166 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 167 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 168 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 169 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 170 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 171 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 172 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 173 | `loaderinfo_quine` | 0.1% | 1/1005 | 1 | 1005 |  |
| 174 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 175 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 176 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 177 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 178 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 179 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 180 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 181 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 182 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 183 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 184 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 185 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 186 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 187 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 188 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 189 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 190 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 191 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 192 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 193 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 194 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 195 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 196 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 197 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 198 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 199 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 200 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 201 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 202 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 203 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 204 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 205 | `avm1_root` | 0.0% | 0/6 | 0 | 6 |  |
| 206 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 207 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 208 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 209 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 210 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 211 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 212 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 213 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 214 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 215 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 216 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 217 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 218 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 219 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 220 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 221 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 222 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 223 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 224 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 225 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 226 | `error_geterrormessage` | 0.0% | 0/779 | 0 | 779 |  |
| 227 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 228 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 229 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 230 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 231 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 232 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 233 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 234 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 235 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 236 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 237 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 238 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 239 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 240 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 241 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 242 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 243 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 244 | `jpeg_loader_context` | 0.0% | 0/6 | 0 | 6 |  |
| 245 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 246 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 247 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 248 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 249 | `loader_jpegxr` | 0.0% | 0/2 | 0 | 2 |  |
| 250 | `loader_jpegxr_alpha` | 0.0% | 0/1 | 0 | 1 |  |
| 251 | `loader_loadbytes_invalid_png` | 0.0% | 0/4 | 0 | 4 |  |
| 252 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 253 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 254 | `loader_unknown_content` | 0.0% | 0/24 | 0 | 24 |  |
| 255 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 256 | `loaderinfo_more` | 0.0% | 0/6 | 1 | 6 |  |
| 257 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 258 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 259 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 260 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 261 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 262 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 263 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 264 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 265 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 266 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 267 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 268 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 269 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 270 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 271 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 272 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 273 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 274 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 275 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 276 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 277 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 278 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 279 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 280 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 281 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 282 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 283 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 284 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 285 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 286 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 287 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 288 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 289 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 290 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 291 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 292 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 293 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 294 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 295 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 296 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 297 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 298 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 299 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 300 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 301 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 302 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 303 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 304 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 305 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 306 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 307 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 308 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 309 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 310 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 311 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 312 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 313 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 314 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 315 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 316 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 317 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 318 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 319 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 320 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 321 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 322 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 323 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 324 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 325 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 326 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 327 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 328 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 329 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 330 | `textblock_createline_fte` | 0.0% | 0/4 | 0 | 4 |  |
| 331 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 332 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 333 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 334 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 335 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 336 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 337 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 338 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 339 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 340 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 341 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 342 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 343 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 344 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 345 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 346 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
