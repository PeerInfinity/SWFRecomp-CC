# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-27 00:30 UTC

**Git SHA**: `8213dd4d61`

**Run Duration**: 168m 9s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **855** (70.0%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **881** (72.2%) |
| Failing | 340 |
| Total expected lines | 151253 |
| Matching lines | 104941 (69.4%) |
| Mismatched lines | 46312 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 337 | 99.1% |
| Runtime Error | 3 | 0.9% |

## Passing Tests

**855 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.3s |  |
| 2 | `agal_compiler` | 13 | 7.9s |  |
| 3 | `air_hidden_lookup` | 2 | 5.6s |  |
| 4 | `all_classes/security/swf11` | 3 | 5.6s |  |
| 5 | `amf_custom_obj` | 26 | 5.6s |  |
| 6 | `amf_dictionary` | 9 | 5.5s |  |
| 7 | `amf_function` | 46 | 5.6s |  |
| 8 | `amf_invalid_date` | 2 | 5.5s |  |
| 9 | `amf_missing_prop` | 6 | 5.6s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.4s |  |
| 11 | `amf_setter_error` | 8 | 6.6s |  |
| 12 | `amf_vector` | 40 | 6.6s |  |
| 13 | `amf_xml` | 6 | 6.4s |  |
| 14 | `application_domain` | 4 | 6.4s |  |
| 15 | `array_access` | 18 | 6.5s |  |
| 16 | `array_access_interpreter` | 4 | 6.4s |  |
| 17 | `array_access_no_pubns` | 2 | 6.4s |  |
| 18 | `array_concat` | 41 | 6.5s |  |
| 19 | `array_constr` | 10 | 6.3s |  |
| 20 | `array_delete` | 44 | 6.6s |  |
| 21 | `array_enumeration` | 10 | 6.5s |  |
| 22 | `array_enumeration_elements` | 11 | 6.5s |  |
| 23 | `array_every` | 8 | 6.5s |  |
| 24 | `array_filter` | 6 | 6.5s |  |
| 25 | `array_foreach` | 18 | 6.6s |  |
| 26 | `array_hasownproperty` | 11 | 3.3s |  |
| 27 | `array_holes` | 9 | 6.5s |  |
| 28 | `array_index_max` | 84 | 6.4s |  |
| 29 | `array_indexof` | 25 | 6.5s |  |
| 30 | `array_join` | 26 | 6.5s |  |
| 31 | `array_lastindexof` | 29 | 6.5s |  |
| 32 | `array_length` | 14 | 6.4s |  |
| 33 | `array_literal` | 3 | 6.4s |  |
| 34 | `array_map` | 8 | 6.3s |  |
| 35 | `array_pop` | 52 | 6.6s |  |
| 36 | `array_push` | 24 | 6.5s |  |
| 37 | `array_reborrow_bug` | 6 | 6.5s |  |
| 38 | `array_reverse` | 28 | 6.5s |  |
| 39 | `array_shift` | 51 | 3.3s |  |
| 40 | `array_slice` | 39 | 6.5s |  |
| 41 | `array_some` | 8 | 6.5s |  |
| 42 | `array_sort` | 297 | 6.9s |  |
| 43 | `array_sort_fun_swf12` | 2 | 6.5s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 45 | `array_sort_random` | 210 | 6.5s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 6.4s |  |
| 47 | `array_sorton` | 545 | 5.3s |  |
| 48 | `array_sparse_ops` | 41 | 4.8s |  |
| 49 | `array_splice` | 133 | 4.8s |  |
| 50 | `array_splice2` | 428 | 5.1s |  |
| 51 | `array_splice_types` | 48 | 4.8s |  |
| 52 | `array_storage` | 8 | 5.1s |  |
| 53 | `array_tolocalestring` | 9 | 5.1s |  |
| 54 | `array_tostring` | 12 | 4.7s |  |
| 55 | `array_unshift` | 24 | 4.7s |  |
| 56 | `array_valueof` | 9 | 4.5s |  |
| 57 | `array_vector_null_callback` | 10 | 4.6s |  |
| 58 | `astype` | 28 | 4.7s |  |
| 59 | `astypelate` | 24 | 4.7s |  |
| 60 | `astypelate_propagates` | 1 | 4.6s |  |
| 61 | `asymmetric_key_events` | 11 | 4.8s |  |
| 62 | `avm2_catchup_dobj` | 158 | 5.1s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 62.8s |  |
| 64 | `bitand` | 1058 | 13.6s |  |
| 65 | `bitmap_constr` | 17 | 4.9s |  |
| 66 | `bitmap_data` | 1000 | 10.9s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 19.6s |  |
| 68 | `bitmap_properties` | 23 | 4.7s |  |
| 69 | `bitmap_subclass` | 7 | 5.9s |  |
| 70 | `bitmap_subclass_properties` | 9 | 5.2s |  |
| 71 | `bitmap_timeline` | 9 | 4.8s |  |
| 72 | `bitmapdata_accuracy` | 1 | 36.8s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 20.1s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.6s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 20.1s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 20.2s |  |
| 77 | `bitmapdata_clone` | 13 | 5.1s |  |
| 78 | `bitmapdata_colortransform` | 0 | 5.4s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 4.8s |  |
| 80 | `bitmapdata_constr` | 22 | 5.0s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 5.2s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.8s |  |
| 83 | `bitmapdata_copypixels` | 23 | 26.1s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.9s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.9s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.9s |  |
| 87 | `bitmapdata_draw` | 0 | 25.7s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.3s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.2s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 25.1s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 6.1s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.3s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.3s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 25.4s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 6.2s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.4s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.4s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 25.6s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.9s |  |
| 100 | `bitmapdata_getpixels` | 39 | 25.1s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.9s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.9s |  |
| 103 | `bitmapdata_hittest` | 112 | 6.6s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 6.0s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.3s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 25.5s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.5s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.9s |  |
| 109 | `bitmapdata_setpixels` | 286 | 6.1s |  |
| 110 | `bitmapdata_setvector` | 26 | 5.9s |  |
| 111 | `bitmapdata_sync` | 0 | 6.1s |  |
| 112 | `bitmapdata_threshold` | 176 | 6.7s |  |
| 113 | `bitnot` | 46 | 5.9s |  |
| 114 | `bitor` | 1058 | 18.0s |  |
| 115 | `bitxor` | 1058 | 18.1s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.2s |  |
| 117 | `blend_scroll` | 0 | 6.2s |  |
| 118 | `boolean_constr` | 32 | 6.1s |  |
| 119 | `boolean_negation` | 30 | 6.0s |  |
| 120 | `boolean_tostring` | 8 | 6.0s |  |
| 121 | `broadcast_event` | 7 | 6.0s |  |
| 122 | `button_nested_frame` | 48 | 24.8s |  |
| 123 | `bytearray` | 48 | 6.2s |  |
| 124 | `bytearray_compress` | 31 | 6.0s |  |
| 125 | `bytearray_errors` | 24 | 6.1s |  |
| 126 | `bytearray_method_serialization` | 1 | 5.9s |  |
| 127 | `bytearray_oom` | 3 | 6.0s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 6.0s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 6.0s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 131 | `bytearray_serialization` | 3 | 6.0s |  |
| 132 | `bytearray_string_null` | 19 | 6.2s |  |
| 133 | `bytearray_tostring` | 15 | 6.0s |  |
| 134 | `bytearray_utf16` | 8 | 5.9s |  |
| 135 | `bytearray_writeobject` | 24 | 5.8s |  |
| 136 | `callee_in_initializer` | 6 | 5.9s |  |
| 137 | `callproplex_class` | 1 | 5.9s |  |
| 138 | `capabilities_resolution` | 8 | 25.1s |  |
| 139 | `catch_class` | 6 | 5.9s |  |
| 140 | `catch_scope_slot` | 7 | 3.0s |  |
| 141 | `checkfilter` | 4 | 2.9s |  |
| 142 | `class_call` | 32 | 24.3s |  |
| 143 | `class_cast_call` | 14 | 6.0s |  |
| 144 | `class_enumeration` | 4 | 5.9s |  |
| 145 | `class_has_own_property` | 2 | 5.9s |  |
| 146 | `class_init_interpreter_mode` | 1 | 5.9s |  |
| 147 | `class_is` | 32 | 6.0s |  |
| 148 | `class_methods` | 5 | 5.9s |  |
| 149 | `class_object_properties` | 10 | 6.0s |  |
| 150 | `class_singleton` | 18 | 6.0s |  |
| 151 | `class_supercalls_errors` | 35 | 6.2s |  |
| 152 | `class_supercalls_mismatched` | 26 | 6.1s |  |
| 153 | `class_superclass_wrong_order` | 1 | 18.7s |  |
| 154 | `class_to_locale_string` | 2 | 4.3s |  |
| 155 | `class_to_string` | 2 | 4.3s |  |
| 156 | `class_value_of` | 2 | 4.6s |  |
| 157 | `click_block` | 5 | 19.6s |  |
| 158 | `click_invisible` | 3 | 4.7s |  |
| 159 | `closures` | 12 | 4.3s |  |
| 160 | `coerce_return_type` | 40 | 4.6s |  |
| 161 | `coerce_return_type_fail` | 2 | 4.6s |  |
| 162 | `coerce_return_void` | 3 | 4.5s |  |
| 163 | `coerce_string` | 86 | 4.7s |  |
| 164 | `coerce_string_precision` | 28 | 4.7s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 4.9s |  |
| 166 | `construct_errors_swf10` | 8 | 4.5s |  |
| 167 | `construct_frame_list` | 22 | 20.5s |  |
| 168 | `constructor_call` | 3 | 4.5s |  |
| 169 | `constructors_vs_timeline` | 5 | 20.4s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 4.6s |  |
| 171 | `control_flow_bool` | 4 | 4.8s |  |
| 172 | `control_flow_stricteq` | 8 | 4.6s |  |
| 173 | `convert_boolean` | 30 | 4.3s |  |
| 174 | `convert_integer` | 90 | 4.6s |  |
| 175 | `convert_number` | 56 | 5.0s |  |
| 176 | `convert_uinteger` | 90 | 5.0s |  |
| 177 | `cryptscore` | 11 | 4.9s |  |
| 178 | `date` | 30 | 6.2s |  |
| 179 | `date_parse` | 36 | 5.8s |  |
| 180 | `declocal` | 46 | 5.8s |  |
| 181 | `declocal_i` | 46 | 5.9s |  |
| 182 | `decode_uri` | 71 | 6.1s |  |
| 183 | `decrement` | 46 | 5.8s |  |
| 184 | `decrement_i` | 46 | 2.8s |  |
| 185 | `default_values` | 7 | 5.8s |  |
| 186 | `dictionary_access` | 62 | 6.0s |  |
| 187 | `dictionary_access_no_pubns` | 2 | 5.7s |  |
| 188 | `dictionary_delete` | 101 | 6.3s |  |
| 189 | `dictionary_foreach` | 42 | 6.0s |  |
| 190 | `dictionary_hasownproperty` | 63 | 6.0s |  |
| 191 | `dictionary_in` | 62 | 6.0s |  |
| 192 | `dictionary_iter_modify` | 8 | 5.9s |  |
| 193 | `dictionary_namespaces` | 36 | 5.9s |  |
| 194 | `dictionary_primitive_keys` | 29 | 5.8s |  |
| 195 | `displayobject_alpha` | 277 | 5.7s |  |
| 196 | `displayobject_blendmode` | 0 | 6.0s |  |
| 197 | `displayobject_colortransform_nested` | 0 | 24.6s |  |
| 198 | `displayobject_from_enterframe` | 1 | 24.2s |  |
| 199 | `displayobject_getbounds_shape` | 0 | 24.5s |  |
| 200 | `displayobject_height` | 6052 | 24.4s |  |
| 201 | `displayobject_hittestobject` | 32 | 5.9s |  |
| 202 | `displayobject_invalid_floats` | 60 | 5.9s |  |
| 203 | `displayobject_invalid_props` | 3 | 5.8s |  |
| 204 | `displayobject_mask` | 3 | 6.2s |  |
| 205 | `displayobject_mask_self_referential` | 0 | 5.3s |  |
| 206 | `displayobject_metaData` | 3 | 5.2s |  |
| 207 | `displayobject_name` | 22 | 5.6s |  |
| 208 | `displayobject_name_from_timeline` | 24 | 5.5s |  |
| 209 | `displayobject_parent` | 12 | 5.4s |  |
| 210 | `displayobject_root` | 24 | 5.4s |  |
| 211 | `displayobject_rotation` | 1284 | 5.4s |  |
| 212 | `displayobject_set_matrix_nested` | 0 | 23.6s |  |
| 213 | `displayobject_subclass` | 2 | 5.4s |  |
| 214 | `displayobject_visible` | 23 | 5.4s |  |
| 215 | `displayobject_width` | 4852 | 23.8s |  |
| 216 | `displayobject_x` | 614 | 5.4s |  |
| 217 | `displayobject_y` | 617 | 5.4s |  |
| 218 | `displayobjectcontainer_addchild` | 32 | 5.4s |  |
| 219 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.3s |  |
| 220 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.7s |  |
| 221 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.5s |  |
| 222 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.5s |  |
| 223 | `displayobjectcontainer_addchildat` | 42 | 5.4s |  |
| 224 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.5s |  |
| 225 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.5s |  |
| 226 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.5s |  |
| 227 | `displayobjectcontainer_contains` | 66 | 23.8s |  |
| 228 | `displayobjectcontainer_getchildat` | 4 | 5.5s |  |
| 229 | `displayobjectcontainer_getchildbyname` | 9 | 5.4s |  |
| 230 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.4s |  |
| 231 | `displayobjectcontainer_getchildindex` | 28 | 5.4s |  |
| 232 | `displayobjectcontainer_removechild` | 10 | 5.4s |  |
| 233 | `displayobjectcontainer_removechild_errors` | 4 | 5.4s |  |
| 234 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.4s |  |
| 235 | `displayobjectcontainer_removechildat` | 18 | 5.4s |  |
| 236 | `displayobjectcontainer_removechildren` | 51 | 5.6s |  |
| 237 | `displayobjectcontainer_setchildindex` | 42 | 5.3s |  |
| 238 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.8s |  |
| 239 | `displayobjectcontainer_swapchildren` | 42 | 5.5s |  |
| 240 | `displayobjectcontainer_swapchildrenat` | 42 | 5.5s |  |
| 241 | `displayobjectcontainer_timelineinstance` | 48 | 24.7s |  |
| 242 | `divide` | 1058 | 18.1s |  |
| 243 | `doabc_is_eager` | 1 | 24.0s |  |
| 244 | `documentclass` | 9 | 5.9s |  |
| 245 | `domain_memory` | 133 | 7.0s |  |
| 246 | `drag_drop` | 10 | 6.0s |  |
| 247 | `duplicate_defs` | 1 | 5.7s |  |
| 248 | `eager_init` | 1 | 5.8s |  |
| 249 | `edit_text_linkage` | 7 | 6.0s |  |
| 250 | `edittext_align` | 60 | 6.3s |  |
| 251 | `edittext_always_show_selection` | 0 | 24.7s |  |
| 252 | `edittext_antialiastype` | 296 | 6.0s |  |
| 253 | `edittext_at_point_methods_basic` | 16 | 7.1s |  |
| 254 | `edittext_autosize` | 39 | 6.1s |  |
| 255 | `edittext_autosize_align` | 0 | 24.8s |  |
| 256 | `edittext_autosize_height_dynamic` | 60 | 24.7s |  |
| 257 | `edittext_autosize_height_input` | 60 | 5.9s |  |
| 258 | `edittext_autosize_lazy_bounds_events` | 65 | 6.1s |  |
| 259 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.9s |  |
| 260 | `edittext_autosize_lazy_bounds_props` | 490 | 7.2s |  |
| 261 | `edittext_autosize_lazy_bounds_visual` | 0 | 24.3s |  |
| 262 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.1s |  |
| 263 | `edittext_bottom_scroll_v_basic` | 210 | 6.1s |  |
| 264 | `edittext_bounds_scale` | 24 | 24.2s |  |
| 265 | `edittext_bullet` | 30 | 5.9s |  |
| 266 | `edittext_default_format` | 221 | 6.2s |  |
| 267 | `edittext_default_format_empty` | 136 | 6.1s |  |
| 268 | `edittext_empty_text_format` | 7 | 5.9s |  |
| 269 | `edittext_focus_selection` | 5 | 5.9s |  |
| 270 | `edittext_font_size` | 45 | 5.8s |  |
| 271 | `edittext_format_empty_font` | 8 | 5.8s |  |
| 272 | `edittext_get_char_index_at_point` | 4 | 25.6s |  |
| 273 | `edittext_get_line_index_at_point` | 2 | 24.8s |  |
| 274 | `edittext_get_line_index_of_char` | 76 | 6.9s |  |
| 275 | `edittext_getcharboundaries` | 172 | 6.4s |  |
| 276 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.5s |  |
| 277 | `edittext_getcharboundaries_scroll` | 85 | 6.3s |  |
| 278 | `edittext_getlinemetrics` | 146 | 6.3s |  |
| 279 | `edittext_html` | 3101 | 6.6s |  |
| 280 | `edittext_html_condensewhite` | 487 | 6.2s |  |
| 281 | `edittext_html_entity` | 4 | 6.4s |  |
| 282 | `edittext_html_font_size_swf12` | 267 | 6.2s |  |
| 283 | `edittext_html_font_size_swf13` | 273 | 6.0s |  |
| 284 | `edittext_html_roundtrip` | 17 | 6.2s |  |
| 285 | `edittext_input_control` | 12 | 6.2s |  |
| 286 | `edittext_leading` | 9 | 6.4s |  |
| 287 | `edittext_letter_spacing` | 15 | 6.2s |  |
| 288 | `edittext_line_methods` | 294 | 7.6s |  |
| 289 | `edittext_line_metrics` | 11 | 28.1s |  |
| 290 | `edittext_margins` | 25 | 6.3s |  |
| 291 | `edittext_max_scroll_h_basic` | 475 | 6.5s |  |
| 292 | `edittext_max_scroll_v_basic` | 1000 | 6.3s |  |
| 293 | `edittext_mousedown` | 3 | 6.6s |  |
| 294 | `edittext_mouseenabled` | 26 | 6.2s |  |
| 295 | `edittext_newline_character` | 22 | 6.2s |  |
| 296 | `edittext_newline_stripping` | 64 | 9.0s |  |
| 297 | `edittext_newlines` | 30 | 6.4s |  |
| 298 | `edittext_paragraph_methods` | 257 | 6.2s |  |
| 299 | `edittext_paste_events` | 8 | 6.4s |  |
| 300 | `edittext_paste_maxchars` | 4 | 6.1s |  |
| 301 | `edittext_paste_restrict` | 16 | 6.0s |  |
| 302 | `edittext_restrict` | 191 | 6.1s |  |
| 303 | `edittext_restrict_events` | 22 | 6.1s |  |
| 304 | `edittext_scrollh` | 10 | 6.1s |  |
| 305 | `edittext_selected_text` | 9 | 6.3s |  |
| 306 | `edittext_set_html_same` | 17 | 6.1s |  |
| 307 | `edittext_set_text_vs_html` | 9 | 6.0s |  |
| 308 | `edittext_stylesheet` | 536 | 6.5s |  |
| 309 | `edittext_stylesheet_custom_tag` | 76 | 6.2s |  |
| 310 | `edittext_stylesheet_display` | 272 | 6.2s |  |
| 311 | `edittext_underline` | 40 | 6.2s |  |
| 312 | `edittext_width_height` | 103 | 17.3s |  |
| 313 | `edittext_wordwrap_word` | 150 | 5.8s |  |
| 314 | `edittext_wrap_breaks` | 2375 | 6.0s |  |
| 315 | `empty_bounds` | 1 | 5.4s |  |
| 316 | `encode_uri_surrogate_pair_swf11` | 15 | 5.2s |  |
| 317 | `equals` | 512 | 8.9s |  |
| 318 | `error_geterrormessage` | 779 | 5.5s |  |
| 319 | `error_prototype` | 15 | 5.5s |  |
| 320 | `error_stack_trace_debug_swf17` | 0 | 24.1s |  |
| 321 | `error_stack_trace_debug_swf18` | 0 | 5.3s |  |
| 322 | `error_stack_trace_release_swf17` | 0 | 5.3s |  |
| 323 | `error_stack_trace_release_swf18` | 0 | 5.2s |  |
| 324 | `error_tostring` | 29 | 5.5s |  |
| 325 | `es3_inheritance` | 31 | 5.5s |  |
| 326 | `es4_inheritance` | 30 | 5.5s |  |
| 327 | `es4_interfaces` | 30 | 5.5s |  |
| 328 | `es4_method_binding` | 8 | 5.5s |  |
| 329 | `es4_oop_prototypes` | 14 | 5.6s |  |
| 330 | `es4_protected_inheritance` | 6 | 5.4s |  |
| 331 | `escape` | 71 | 5.5s |  |
| 332 | `event_bubbles` | 2 | 5.4s |  |
| 333 | `event_cancelable` | 2 | 5.4s |  |
| 334 | `event_clone` | 20 | 5.5s |  |
| 335 | `event_clone_error_redispatch` | 3 | 5.5s |  |
| 336 | `event_clone_on_redispatch` | 10 | 5.6s |  |
| 337 | `event_formattostring` | 31 | 5.5s |  |
| 338 | `event_isdefaultprevented` | 12 | 5.4s |  |
| 339 | `event_target_getter` | 5 | 2.5s |  |
| 340 | `event_target_set` | 9 | 5.4s |  |
| 341 | `event_type` | 1 | 14.1s |  |
| 342 | `event_valueof_tostring` | 18 | 4.8s |  |
| 343 | `eventdispatcher_dispatchevent` | 12 | 4.8s |  |
| 344 | `eventdispatcher_dispatchevent_cancel` | 20 | 4.9s |  |
| 345 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.3s |  |
| 346 | `eventdispatcher_dispatchevent_indirect` | 9 | 4.7s |  |
| 347 | `eventdispatcher_dispatchevent_this` | 5 | 5.0s |  |
| 348 | `eventdispatcher_haseventlistener` | 25 | 4.9s |  |
| 349 | `eventdispatcher_interface_invoke` | 1 | 4.7s |  |
| 350 | `eventdispatcher_tostring` | 10 | 4.9s |  |
| 351 | `eventdispatcher_willtrigger` | 25 | 4.6s |  |
| 352 | `falsiness` | 30 | 4.9s |  |
| 353 | `fast_index_access` | 12 | 5.1s |  |
| 354 | `finddef` | 3 | 4.9s |  |
| 355 | `findprop_global_prototype` | 6 | 4.9s |  |
| 356 | `flash_xml` | 29 | 4.8s |  |
| 357 | `flash_xml_cloneNode` | 22 | 4.8s |  |
| 358 | `flash_xml_namespace` | 109 | 4.8s |  |
| 359 | `flash_xml_removeNode` | 60 | 5.0s |  |
| 360 | `focus_events_code` | 161 | 19.7s |  |
| 361 | `focus_events_key_same_object` | 26 | 4.7s |  |
| 362 | `focus_events_mixed_key_mouse` | 100 | 19.3s |  |
| 363 | `focus_events_mouse_same_object` | 40 | 24.0s |  |
| 364 | `focus_remove` | 20 | 23.8s |  |
| 365 | `focus_root_movie` | 4 | 23.9s |  |
| 366 | `focus_stage` | 1 | 5.9s |  |
| 367 | `focusrect` | 18 | 6.6s |  |
| 368 | `font_description_clone` | 14 | 5.8s |  |
| 369 | `font_embedded` | 24 | 6.1s |  |
| 370 | `font_enumeratefonts` | 41 | 6.3s |  |
| 371 | `font_enumeratefonts_filter` | 4 | 24.4s |  |
| 372 | `font_hasglyphs` | 40 | 6.2s |  |
| 373 | `framelabel_constr` | 5 | 5.8s |  |
| 374 | `function_call` | 12 | 5.8s |  |
| 375 | `function_call_arguments` | 46 | 5.8s |  |
| 376 | `function_call_arguments_enumerate` | 5 | 5.7s |  |
| 377 | `function_call_coercion` | 108 | 6.1s |  |
| 378 | `function_call_default` | 6 | 5.7s |  |
| 379 | `function_call_rest` | 22 | 5.7s |  |
| 380 | `function_call_types` | 3 | 5.7s |  |
| 381 | `function_call_via_apply` | 11 | 5.7s |  |
| 382 | `function_call_via_call` | 3 | 5.7s |  |
| 383 | `function_display_anonymous` | 7 | 2.7s |  |
| 384 | `function_length` | 6 | 5.7s |  |
| 385 | `function_object` | 2 | 5.7s |  |
| 386 | `function_proto` | 5 | 5.7s |  |
| 387 | `function_proto_created` | 61 | 5.7s |  |
| 388 | `function_to_locale_string` | 4 | 5.7s |  |
| 389 | `function_to_string` | 4 | 5.7s |  |
| 390 | `function_type` | 6 | 5.8s |  |
| 391 | `function_unbound_this` | 51 | 5.9s |  |
| 392 | `function_value_of` | 4 | 5.8s |  |
| 393 | `get_definition_by_name` | 11 | 5.8s |  |
| 394 | `get_qualified_class_name` | 20 | 17.7s |  |
| 395 | `get_qualified_super_class_name` | 18 | 5.8s |  |
| 396 | `get_slot_edge_cases` | 1 | 23.8s |  |
| 397 | `get_timer` | 2 | 5.7s |  |
| 398 | `getglobalslot` | 1 | 5.7s |  |
| 399 | `getouterscope` | 8 | 5.7s |  |
| 400 | `getter_different_namespace_setter` | 2 | 5.6s |  |
| 401 | `goto_button_nested_framescript` | 28 | 24.7s |  |
| 402 | `goto_in_constructframe` | 12 | 6.0s |  |
| 403 | `goto_in_scene_last_frame` | 2 | 24.5s |  |
| 404 | `goto_methods` | 56 | 6.1s |  |
| 405 | `goto_methods_swfver10` | 8 | 5.8s |  |
| 406 | `goto_nested_construct_sibling` | 18 | 6.3s |  |
| 407 | `goto_nested_framescript` | 9 | 6.0s |  |
| 408 | `goto_on_orphan` | 15 | 6.1s |  |
| 409 | `graphics_bad_direct_commands` | 5 | 6.7s |  |
| 410 | `graphics_bitmap_fill` | 0 | 7.8s |  |
| 411 | `graphics_bitmaps` | 0 | 6.6s |  |
| 412 | `graphics_direct_commands` | 0 | 6.5s |  |
| 413 | `graphics_draw_triangles` | 98 | 25.4s |  |
| 414 | `graphics_gradients` | 0 | 6.3s |  |
| 415 | `graphics_gradients_nulls` | 0 | 6.2s |  |
| 416 | `graphics_path` | 56 | 6.0s |  |
| 417 | `graphics_round_rects` | 0 | 5.8s |  |
| 418 | `graphics_simple_shapes` | 0 | 6.3s |  |
| 419 | `greaterequals` | 512 | 10.0s |  |
| 420 | `greaterthan` | 512 | 10.0s |  |
| 421 | `has_own_property` | 102 | 6.3s |  |
| 422 | `hasownproperty_namespaces` | 2 | 5.8s |  |
| 423 | `hello_world` | 1 | 5.8s |  |
| 424 | `hittest_morph` | 30 | 6.0s |  |
| 425 | `if_eq` | 10 | 5.8s |  |
| 426 | `if_gt` | 1 | 5.8s |  |
| 427 | `if_gte` | 10 | 17.5s |  |
| 428 | `if_lt` | 1 | 5.8s |  |
| 429 | `if_lte` | 10 | 5.7s |  |
| 430 | `if_ne` | 7 | 2.9s |  |
| 431 | `if_stricteq` | 6 | 5.8s |  |
| 432 | `if_strictne` | 11 | 5.8s |  |
| 433 | `in` | 102 | 6.3s |  |
| 434 | `inclocal` | 46 | 5.9s |  |
| 435 | `inclocal_i` | 46 | 5.9s |  |
| 436 | `increment` | 46 | 5.9s |  |
| 437 | `increment_i` | 46 | 5.9s |  |
| 438 | `indexing_delete` | 75 | 5.8s |  |
| 439 | `instanceof` | 58 | 6.1s |  |
| 440 | `instantiation_on_enter_frame` | 7 | 24.2s |  |
| 441 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.8s |  |
| 442 | `int_constr` | 92 | 5.7s |  |
| 443 | `int_edge_cases` | 19 | 5.8s |  |
| 444 | `int_instanceof` | 3 | 5.7s |  |
| 445 | `int_tofixed` | 1215 | 5.7s |  |
| 446 | `int_tostring` | 3375 | 5.8s |  |
| 447 | `interactiveobject_enabled` | 25 | 5.8s |  |
| 448 | `interface_namespaces` | 78 | 6.0s |  |
| 449 | `is_finite` | 46 | 5.9s |  |
| 450 | `is_nan` | 46 | 5.7s |  |
| 451 | `is_prototype_of` | 12 | 5.8s |  |
| 452 | `issue_10221` | 2 | 5.8s |  |
| 453 | `issue_13780` | 12 | 5.9s |  |
| 454 | `issue_14901` | 1 | 5.8s |  |
| 455 | `issue_17675_edittext_paste_maxchars` | 1 | 5.8s |  |
| 456 | `issue_5292` | 5 | 5.8s |  |
| 457 | `issue_8630` | 2 | 23.9s |  |
| 458 | `issue_8630_scriptremove` | 11 | 5.8s |  |
| 459 | `istype` | 24 | 2.9s |  |
| 460 | `istypelate` | 58 | 6.1s |  |
| 461 | `istypelate_coerce` | 198 | 15.9s |  |
| 462 | `jpeg_loader_context` | 6 | 5.1s |  |
| 463 | `json_errors` | 9 | 20.9s |  |
| 464 | `json_parse` | 21 | 5.0s |  |
| 465 | `json_stringify` | 12 | 5.4s |  |
| 466 | `json_stringify_order` | 1 | 5.0s |  |
| 467 | `json_version_gated` | 1 | 5.0s |  |
| 468 | `key_input_80percent` | 1812 | 5.2s |  |
| 469 | `key_input_location` | 126 | 5.2s |  |
| 470 | `key_input_numpad` | 384 | 5.2s |  |
| 471 | `lazyinit` | 17 | 5.1s |  |
| 472 | `lessequals` | 512 | 8.4s |  |
| 473 | `lessthan` | 512 | 8.4s |  |
| 474 | `loader_bytes_unknown_content` | 14 | 5.0s |  |
| 475 | `loader_jpegxr` | 2 | 20.9s |  |
| 476 | `loader_jpegxr_alpha` | 1 | 20.5s |  |
| 477 | `loader_unknown_content` | 24 | 5.0s |  |
| 478 | `loaderinfo_events` | 7 | 5.0s |  |
| 479 | `loaderinfo_loadurl` | 12 | 17.6s |  |
| 480 | `loaderinfo_more` | 6 | 6.0s |  |
| 481 | `loaderinfo_properties` | 18 | 5.8s |  |
| 482 | `loaderinfo_properties_not_loaded` | 23 | 6.0s |  |
| 483 | `loaderinfo_root` | 10 | 5.8s |  |
| 484 | `loaderinfo_root_allows` | 2 | 5.8s |  |
| 485 | `lshift` | 1058 | 18.2s |  |
| 486 | `mask_reapply` | 1 | 6.0s |  |
| 487 | `math` | 497 | 6.0s |  |
| 488 | `missing_external_interface` | 10 | 5.8s |  |
| 489 | `modulo` | 1058 | 17.8s |  |
| 490 | `morph_shape` | 2 | 24.0s |  |
| 491 | `mouse_click_events` | 90 | 24.0s |  |
| 492 | `mouse_double_click_events` | 188 | 5.8s |  |
| 493 | `mouse_empty_parent` | 4 | 5.8s |  |
| 494 | `mouse_over_while_dragging` | 3 | 5.9s |  |
| 495 | `mouse_pick_button_mode` | 2 | 5.8s |  |
| 496 | `mouse_sibling` | 8 | 5.8s |  |
| 497 | `movieclip_addframescript` | 3 | 23.9s |  |
| 498 | `movieclip_child_property` | 16 | 5.8s |  |
| 499 | `movieclip_constr` | 21 | 18.3s |  |
| 500 | `movieclip_currentlabels` | 17 | 25.2s |  |
| 501 | `movieclip_currentlabels_dupes1` | 46 | 25.1s |  |
| 502 | `movieclip_currentlabels_dupes2` | 30 | 6.2s |  |
| 503 | `movieclip_currentlabels_dupes3` | 67 | 6.1s |  |
| 504 | `movieclip_currentscene` | 12 | 6.4s |  |
| 505 | `movieclip_dispatchevent` | 430 | 6.3s |  |
| 506 | `movieclip_dispatchevent_cancel` | 102 | 6.3s |  |
| 507 | `movieclip_dispatchevent_handlerorder` | 251 | 6.3s |  |
| 508 | `movieclip_dispatchevent_selfadd` | 80 | 6.2s |  |
| 509 | `movieclip_dispatchevent_target` | 899 | 6.3s |  |
| 510 | `movieclip_displayevents` | 96 | 25.9s |  |
| 511 | `movieclip_displayevents_clickgoto` | 676 | 6.7s |  |
| 512 | `movieclip_displayevents_clickgoto2` | 2001 | 6.7s |  |
| 513 | `movieclip_displayevents_clickplay` | 575 | 6.4s |  |
| 514 | `movieclip_displayevents_clicksymbol` | 562 | 6.4s |  |
| 515 | `movieclip_displayevents_constructframegoto` | 140 | 6.6s |  |
| 516 | `movieclip_displayevents_constructframeplay` | 50 | 6.5s |  |
| 517 | `movieclip_displayevents_constructframesymbol` | 144 | 6.4s |  |
| 518 | `movieclip_displayevents_dblhandler` | 21 | 6.4s |  |
| 519 | `movieclip_displayevents_enterframegoto` | 149 | 6.5s |  |
| 520 | `movieclip_displayevents_enterframeplay` | 48 | 6.3s |  |
| 521 | `movieclip_displayevents_enterframesymbol` | 149 | 25.1s |  |
| 522 | `movieclip_displayevents_exitframegoto` | 106 | 6.2s |  |
| 523 | `movieclip_displayevents_exitframeplay` | 44 | 6.2s |  |
| 524 | `movieclip_displayevents_exitframesymbol` | 135 | 6.2s |  |
| 525 | `movieclip_displayevents_looping` | 63 | 25.1s |  |
| 526 | `movieclip_displayevents_stopped` | 113 | 6.6s |  |
| 527 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 528 | `movieclip_displayevents_timeline` | 128 | 25.4s |  |
| 529 | `movieclip_drawrect` | 54 | 6.1s |  |
| 530 | `movieclip_frameconstruct_skipped` | 9 | 6.4s |  |
| 531 | `movieclip_goto_during_frame_script` | 15 | 6.3s |  |
| 532 | `movieclip_goto_overwrite` | 14 | 25.3s |  |
| 533 | `movieclip_goto_scene_last_frame_int` | 1 | 24.9s |  |
| 534 | `movieclip_goto_scene_last_frame_label` | 1 | 6.0s |  |
| 535 | `movieclip_gotoandplay` | 15 | 24.8s |  |
| 536 | `movieclip_gotoandstop` | 13 | 6.1s |  |
| 537 | `movieclip_gotoandstop_children` | 4 | 6.2s |  |
| 538 | `movieclip_gotoandstop_framescripts1` | 4 | 6.1s |  |
| 539 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 540 | `movieclip_gotoandstop_framescripts_self` | 7 | 35.8s |  |
| 541 | `movieclip_gotoandstop_queueing` | 12 | 24.4s |  |
| 542 | `movieclip_next_frame` | 2 | 5.9s |  |
| 543 | `movieclip_next_scene` | 6 | 24.0s |  |
| 544 | `movieclip_play` | 3 | 5.7s |  |
| 545 | `movieclip_prev_frame` | 3 | 5.7s |  |
| 546 | `movieclip_prev_scene` | 7 | 5.8s |  |
| 547 | `movieclip_properties` | 79 | 6.0s |  |
| 548 | `movieclip_queued_noop_goto_swf10` | 9 | 5.8s |  |
| 549 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 550 | `movieclip_scenes` | 11 | 5.7s |  |
| 551 | `movieclip_soundtransform` | 831 | 26.1s |  |
| 552 | `movieclip_stop` | 1 | 5.7s |  |
| 553 | `movieclip_super_is_symbol` | 20 | 6.1s |  |
| 554 | `movieclip_symbol_constr` | 8 | 5.9s |  |
| 555 | `movieclip_text_mousedown` | 1 | 5.8s |  |
| 556 | `movieclip_willtrigger` | 5 | 6.0s |  |
| 557 | `multiply` | 1058 | 18.1s |  |
| 558 | `namespace_constr` | 253 | 6.1s |  |
| 559 | `namespace_constr_args` | 1 | 5.7s |  |
| 560 | `namespace_enumeration_order` | 7 | 5.9s |  |
| 561 | `nan_scale` | 9 | 5.8s |  |
| 562 | `negate` | 30 | 5.8s |  |
| 563 | `negative_volume_panned` | 0 | 5.9s |  |
| 564 | `nested_iteration` | 11 | 5.8s |  |
| 565 | `net_getClassByAlias` | 3 | 5.8s |  |
| 566 | `newactivation_in_script_init` | 3 | 5.7s |  |
| 567 | `newclass_twice` | 3 | 5.5s |  |
| 568 | `nonconflicting_declarations` | 0 | 5.6s |  |
| 569 | `null_void_types` | 8 | 5.7s |  |
| 570 | `number_autoconv` | 21 | 5.7s |  |
| 571 | `number_autoconv_amf` | 132 | 5.7s |  |
| 572 | `number_autoconv_array_sort_32bit` | 1 | 5.6s |  |
| 573 | `number_constr` | 58 | 5.8s |  |
| 574 | `number_toexponential` | 378 | 5.7s |  |
| 575 | `number_toexponential2` | 35 | 5.6s |  |
| 576 | `number_tofixed` | 378 | 5.6s |  |
| 577 | `number_toprecision` | 350 | 5.7s |  |
| 578 | `obfuscated_class_names` | 3 | 5.6s |  |
| 579 | `object_enumeration` | 10 | 5.6s |  |
| 580 | `object_prototype` | 4 | 5.6s |  |
| 581 | `object_to_locale_string` | 2 | 5.6s |  |
| 582 | `object_to_string` | 2 | 5.6s |  |
| 583 | `object_value_of` | 2 | 2.6s |  |
| 584 | `op_coerce` | 54 | 5.7s |  |
| 585 | `op_coerce_x` | 54 | 5.7s |  |
| 586 | `op_escxattr` | 2 | 5.6s |  |
| 587 | `op_escxelem` | 2 | 5.6s |  |
| 588 | `op_lookupswitch` | 4 | 5.7s |  |
| 589 | `optimize_coerce` | 1 | 5.6s |  |
| 590 | `orphan_movie_complex` | 80 | 6.0s |  |
| 591 | `orphan_movie_reorder` | 111 | 23.8s |  |
| 592 | `package_namespace` | 7 | 5.5s |  |
| 593 | `param_default_value_has_zero_cpool_index` | 1 | 5.6s |  |
| 594 | `parent_early_access_child` | 16 | 5.9s |  |
| 595 | `parse_float` | 81 | 5.9s |  |
| 596 | `pixelbender_effect_BlurredFocus` | 0 | 30.5s |  |
| 597 | `pixelbender_effect_glassDisplace` | 0 | 12.4s |  |
| 598 | `pixelbender_effect_smudge` | 0 | 10.1s |  |
| 599 | `pixelbender_effect_tintype` | 0 | 9.2s |  |
| 600 | `pixelbender_effect_twirl` | 0 | 10.3s |  |
| 601 | `pixelbender_images` | 0 | 8.8s |  |
| 602 | `place_multiple` | 17 | 26.2s |  |
| 603 | `place_object_replace` | 9 | 6.5s |  |
| 604 | `place_object_replace_2` | 24 | 6.5s |  |
| 605 | `place_object_same_depth_frame` | 1 | 6.4s |  |
| 606 | `point` | 132 | 6.9s |  |
| 607 | `primitive_edge_cases` | 1 | 6.2s |  |
| 608 | `property_priority` | 22 | 6.1s |  |
| 609 | `property_priority_three_level` | 6 | 24.9s |  |
| 610 | `propertyisenumerable_namespaces` | 6 | 5.9s |  |
| 611 | `prototype_set_null` | 7 | 5.8s |  |
| 612 | `proxy_callproperty` | 24 | 5.8s |  |
| 613 | `proxy_deleteproperty` | 64 | 5.9s |  |
| 614 | `proxy_enumeration` | 34 | 5.9s |  |
| 615 | `proxy_getproperty` | 77 | 6.0s |  |
| 616 | `proxy_hasownproperty` | 8 | 5.9s |  |
| 617 | `proxy_hasproperty` | 32 | 6.2s |  |
| 618 | `proxy_serialize` | 9 | 6.0s |  |
| 619 | `proxy_setproperty` | 42 | 6.2s |  |
| 620 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.0s |  |
| 621 | `qname_constr` | 32 | 6.1s |  |
| 622 | `qname_constr_namespace` | 24 | 6.0s |  |
| 623 | `qname_enumeration` | 9 | 6.0s |  |
| 624 | `qname_indexing` | 23 | 5.9s |  |
| 625 | `qname_tostring` | 25 | 6.0s |  |
| 626 | `qname_valueof` | 29 | 6.1s |  |
| 627 | `regexp_constr` | 148 | 6.2s |  |
| 628 | `regexp_exec` | 19 | 5.9s |  |
| 629 | `regexp_extended` | 47 | 5.9s |  |
| 630 | `regexp_multiargs` | 1 | 5.9s |  |
| 631 | `regexp_test` | 27 | 6.0s |  |
| 632 | `regexp_toString` | 10 | 6.0s |  |
| 633 | `register_script_refresh` | 35 | 6.4s |  |
| 634 | `remove_child_clear_field` | 88 | 6.4s |  |
| 635 | `remove_dobj` | 3 | 6.1s |  |
| 636 | `resolve_order` | 4 | 5.9s |  |
| 637 | `rng` | 1 | 7.2s |  |
| 638 | `rootless` | 42 | 6.2s |  |
| 639 | `rshift` | 1058 | 18.4s |  |
| 640 | `sandbox_type_local_file` | 1 | 6.0s |  |
| 641 | `scene_constr` | 8 | 6.0s |  |
| 642 | `set_local_0` | 31 | 6.2s |  |
| 643 | `set_property_is_enumerable` | 85 | 6.6s |  |
| 644 | `shape_drawrect` | 54 | 6.1s |  |
| 645 | `shared_object_no_root` | 3 | 6.0s |  |
| 646 | `simplebutton_added_to_stage` | 45 | 25.6s |  |
| 647 | `simplebutton_childevents` | 86 | 26.1s |  |
| 648 | `simplebutton_childevents_nested` | 54 | 6.4s |  |
| 649 | `simplebutton_childevents_sprite` | 13 | 6.2s |  |
| 650 | `simplebutton_childprops` | 144 | 6.4s |  |
| 651 | `simplebutton_childshuffle` | 23 | 6.0s |  |
| 652 | `simplebutton_constr` | 36 | 6.4s |  |
| 653 | `simplebutton_constr_childevents` | 48 | 6.4s |  |
| 654 | `simplebutton_constr_params` | 42 | 6.2s |  |
| 655 | `simplebutton_mouseenabled` | 26 | 6.1s |  |
| 656 | `simplebutton_multi_children` | 19 | 6.3s |  |
| 657 | `simplebutton_structure` | 27 | 6.3s |  |
| 658 | `simplebutton_symbolclass` | 68 | 6.5s |  |
| 659 | `slot_disp_id_shared_numbering` | 1 | 25.4s |  |
| 660 | `slots_force_autoassigned` | 1 | 6.1s |  |
| 661 | `sound_embeddedprops` | 26 | 6.4s |  |
| 662 | `sound_play` | 19 | 6.3s |  |
| 663 | `sound_valueof` | 33 | 6.2s |  |
| 664 | `soundchannel_soundtransform` | 835 | 27.5s |  |
| 665 | `soundchannel_soundtransform_exists` | 5 | 25.3s |  |
| 666 | `soundchannel_stop` | 8 | 6.2s |  |
| 667 | `soundmixer_buffertime` | 5 | 6.0s |  |
| 668 | `soundmixer_stopall` | 6 | 6.2s |  |
| 669 | `soundtransform` | 442 | 12.2s |  |
| 670 | `sprite_with_frames` | 0 | 25.9s |  |
| 671 | `stage3d_agal_cross_product` | 0 | 8.9s |  |
| 672 | `stage3d_bitmap` | 0 | 30.8s |  |
| 673 | `stage3d_float1_index` | 0 | 27.9s |  |
| 674 | `stage3d_fractal` | 0 | 28.1s |  |
| 675 | `stage3d_ignore_sampler_override` | 0 | 28.4s |  |
| 676 | `stage3d_program_constants_bytearray_be` | 0 | 29.1s |  |
| 677 | `stage3d_program_constants_bytearray_le` | 0 | 9.5s |  |
| 678 | `stage3d_raytrace` | 0 | 31.6s |  |
| 679 | `stage3d_rotating_cube` | 0 | 9.8s |  |
| 680 | `stage3d_sampler` | 0 | 19.7s |  |
| 681 | `stage3d_sampler_partial_upload` | 0 | 8.2s |  |
| 682 | `stage3d_stencil` | 0 | 27.4s |  |
| 683 | `stage3d_texture` | 0 | 13.0s |  |
| 684 | `stage3d_texture_bytearray` | 0 | 9.3s |  |
| 685 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.8s |  |
| 686 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.0s |  |
| 687 | `stage3d_triangle` | 0 | 8.2s |  |
| 688 | `stage3d_triangle_bytes4` | 0 | 8.1s |  |
| 689 | `stage3d_triangle_float1` | 0 | 8.1s |  |
| 690 | `stage3d_triangle_index_upload` | 0 | 8.0s |  |
| 691 | `stage_access` | 10 | 5.4s |  |
| 692 | `stage_displayobject_properties` | 24 | 5.3s |  |
| 693 | `stage_framerate_nan` | 7 | 5.5s |  |
| 694 | `stage_framerate_negative` | 6 | 5.3s |  |
| 695 | `stage_framerate_zero` | 6 | 5.4s |  |
| 696 | `stage_invalidate` | 38 | 5.6s |  |
| 697 | `stage_loaderinfo_properties` | 24 | 5.6s |  |
| 698 | `stage_mousechildren` | 2 | 5.4s |  |
| 699 | `stage_mouseenabled` | 15 | 5.4s |  |
| 700 | `stage_overriden_setters` | 31 | 5.5s |  |
| 701 | `stage_properties` | 30 | 5.4s |  |
| 702 | `static_var_with_this_in_ctor` | 2 | 5.4s |  |
| 703 | `stored_properties` | 11 | 5.4s |  |
| 704 | `strict_equality` | 34 | 5.4s |  |
| 705 | `string_call` | 13 | 5.4s |  |
| 706 | `string_case` | 23 | 5.4s |  |
| 707 | `string_char_at` | 27 | 5.4s |  |
| 708 | `string_char_code_at` | 28 | 5.3s |  |
| 709 | `string_concat_fromcharcode` | 37 | 5.3s |  |
| 710 | `string_constr` | 25 | 5.4s |  |
| 711 | `string_indexof_lastindexof` | 87 | 36.7s |  |
| 712 | `string_length` | 16 | 6.0s |  |
| 713 | `string_locale_compare` | 39 | 6.2s |  |
| 714 | `string_match` | 51 | 6.0s |  |
| 715 | `string_relational_compare` | 4 | 5.8s |  |
| 716 | `string_replace` | 51 | 6.0s |  |
| 717 | `string_search` | 41 | 6.0s |  |
| 718 | `string_slice_substr_substring` | 170 | 7.1s |  |
| 719 | `string_split` | 29 | 6.0s |  |
| 720 | `string_substr_negative` | 21 | 5.8s |  |
| 721 | `string_substr_weird` | 182 | 5.7s |  |
| 722 | `subtract` | 1058 | 17.9s |  |
| 723 | `super_get_call` | 12 | 5.8s |  |
| 724 | `supercall_two_classobjects` | 2 | 5.8s |  |
| 725 | `swf8` | 1 | 5.8s |  |
| 726 | `swf_10_queued_goto_scripts_construct` | 52 | 6.1s |  |
| 727 | `swf_9_goto_in_enter_frame` | 17 | 5.9s |  |
| 728 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.8s |  |
| 729 | `swf_9_queued_goto_scripts` | 6 | 5.8s |  |
| 730 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 731 | `swf_9_versioning` | 2 | 5.7s |  |
| 732 | `swf_wrong_frame_count` | 38 | 6.0s |  |
| 733 | `swf_wrong_frame_count_isplaying` | 22 | 5.8s |  |
| 734 | `symbol_class_binary_data` | 8 | 5.7s |  |
| 735 | `symbol_class_conflict` | 4 | 6.2s |  |
| 736 | `symbol_class_root_not_zero` | 1 | 5.6s |  |
| 737 | `symbolclass_invalid_utf8` | 2 | 5.7s |  |
| 738 | `tab_ordering_automatic_advanced` | 184 | 6.4s |  |
| 739 | `tab_ordering_automatic_basic` | 45 | 5.9s |  |
| 740 | `tab_ordering_children` | 116 | 5.9s |  |
| 741 | `tab_ordering_custom_basic` | 34 | 5.8s |  |
| 742 | `text_engine_fontdescription` | 27 | 6.1s |  |
| 743 | `text_run` | 7 | 5.8s |  |
| 744 | `textfield_focusin_event` | 9 | 5.9s |  |
| 745 | `textfield_input_dead_keys_windows` | 15 | 6.0s |  |
| 746 | `textfield_unload` | 39 | 24.9s |  |
| 747 | `textformat` | 1134 | 6.0s |  |
| 748 | `textformat_display` | 14 | 6.0s |  |
| 749 | `textformat_font_max_length` | 4 | 6.0s |  |
| 750 | `throw` | 3 | 6.0s |  |
| 751 | `timeline_scripts` | 3 | 6.2s |  |
| 752 | `timer` | 90 | 6.6s |  |
| 753 | `timer_events` | 3 | 6.1s |  |
| 754 | `timer_finished` | 11 | 6.1s |  |
| 755 | `timer_reset` | 8 | 6.0s |  |
| 756 | `timer_setdelay` | 5 | 5.9s |  |
| 757 | `trace` | 12 | 5.8s |  |
| 758 | `truthiness` | 30 | 18.1s |  |
| 759 | `try_catch` | 11 | 4.9s |  |
| 760 | `try_catch_typed` | 12 | 4.9s |  |
| 761 | `typeof` | 30 | 4.8s |  |
| 762 | `uint_constr` | 92 | 4.8s |  |
| 763 | `uint_tofixed` | 1215 | 4.8s |  |
| 764 | `uint_tostring` | 3375 | 4.8s |  |
| 765 | `unchecked_function` | 15 | 4.8s |  |
| 766 | `unescape` | 28 | 4.8s |  |
| 767 | `urlrequest` | 18 | 4.8s |  |
| 768 | `urshift` | 1058 | 4.8s |  |
| 769 | `vector_class` | 36 | 4.8s |  |
| 770 | `vector_class_call` | 11 | 4.8s |  |
| 771 | `vector_coercion` | 66 | 4.8s |  |
| 772 | `vector_concat` | 90 | 4.8s |  |
| 773 | `vector_constr` | 107 | 4.8s |  |
| 774 | `vector_enumeration` | 5 | 4.8s |  |
| 775 | `vector_every` | 92 | 4.8s |  |
| 776 | `vector_filter` | 95 | 4.8s |  |
| 777 | `vector_holes` | 24 | 4.8s |  |
| 778 | `vector_indexof` | 302 | 4.8s |  |
| 779 | `vector_insertat` | 270 | 4.8s |  |
| 780 | `vector_int_access` | 4 | 4.8s |  |
| 781 | `vector_int_delete` | 11 | 4.8s |  |
| 782 | `vector_join` | 58 | 4.8s |  |
| 783 | `vector_lastindexof` | 302 | 4.8s |  |
| 784 | `vector_legacy` | 10 | 4.8s |  |
| 785 | `vector_map` | 85 | 4.8s |  |
| 786 | `vector_object_final` | 1 | 4.9s |  |
| 787 | `vector_object_toString` | 10 | 4.8s |  |
| 788 | `vector_pushpop` | 255 | 4.9s |  |
| 789 | `vector_reborrow_bug` | 10 | 17.6s |  |
| 790 | `vector_removeat` | 172 | 6.9s |  |
| 791 | `vector_reverse` | 232 | 6.9s |  |
| 792 | `vector_shiftunshift` | 252 | 5.7s |  |
| 793 | `vector_slice` | 331 | 7.5s |  |
| 794 | `vector_sort` | 905 | 15.3s |  |
| 795 | `vector_splice` | 693 | 9.8s |  |
| 796 | `vector_splice_fixed_bug_compat` | 4 | 5.8s |  |
| 797 | `vector_tostring` | 79 | 6.4s |  |
| 798 | `verify_abnormal_loop` | 1 | 5.7s |  |
| 799 | `verify_exception_targets_edge_case` | 1 | 5.7s |  |
| 800 | `verify_lookup_switch_edge_case` | 1 | 5.6s |  |
| 801 | `verify_unreachable_exception` | 2 | 5.7s |  |
| 802 | `versioned_isplaying` | 2 | 5.8s |  |
| 803 | `virtual_properties` | 16 | 5.8s |  |
| 804 | `with` | 4 | 5.8s |  |
| 805 | `wrong_arg_count` | 7 | 5.9s |  |
| 806 | `xml_abstract_equality` | 36 | 6.0s |  |
| 807 | `xml_advanced` | 52 | 5.8s |  |
| 808 | `xml_appendchild` | 10 | 5.7s |  |
| 809 | `xml_as_attribute` | 9 | 5.7s |  |
| 810 | `xml_attribute` | 35 | 5.9s |  |
| 811 | `xml_attribute_name` | 40 | 5.8s |  |
| 812 | `xml_basic` | 33 | 5.8s |  |
| 813 | `xml_child` | 25 | 5.8s |  |
| 814 | `xml_childindex` | 7 | 5.7s |  |
| 815 | `xml_children` | 43 | 6.3s |  |
| 816 | `xml_class_call` | 9 | 5.7s |  |
| 817 | `xml_contains` | 197 | 5.9s |  |
| 818 | `xml_copy` | 20 | 17.7s |  |
| 819 | `xml_ctor_from_tostring` | 23 | 6.1s |  |
| 820 | `xml_delete` | 114 | 5.9s |  |
| 821 | `xml_descendants` | 83 | 5.9s |  |
| 822 | `xml_elements` | 6 | 5.8s |  |
| 823 | `xml_equals_namespace_check` | 2 | 5.7s |  |
| 824 | `xml_explicit_use_namespace` | 5 | 23.9s |  |
| 825 | `xml_getdescendants_qname` | 21 | 5.7s |  |
| 826 | `xml_has_property_via_in` | 26 | 5.8s |  |
| 827 | `xml_hasownproperty` | 6 | 5.8s |  |
| 828 | `xml_ignore_white` | 6 | 5.8s |  |
| 829 | `xml_length` | 2 | 5.7s |  |
| 830 | `xml_list_as_attribute` | 9 | 5.7s |  |
| 831 | `xml_list_concat` | 20 | 5.8s |  |
| 832 | `xml_list_enumerate` | 4 | 5.7s |  |
| 833 | `xml_methods_settings` | 3 | 5.7s |  |
| 834 | `xml_mismatched_tag` | 37 | 5.8s |  |
| 835 | `xml_namespace` | 39 | 5.8s |  |
| 836 | `xml_namespace_methods` | 245 | 5.8s |  |
| 837 | `xml_namespaced_property` | 7 | 5.8s |  |
| 838 | `xml_no_namespace` | 1 | 5.7s |  |
| 839 | `xml_nodekind` | 3 | 5.7s |  |
| 840 | `xml_normalize` | 35 | 5.9s |  |
| 841 | `xml_notification_bubbling` | 361 | 5.8s |  |
| 842 | `xml_parent` | 8 | 5.8s |  |
| 843 | `xml_set_children` | 17 | 5.8s |  |
| 844 | `xml_set_name` | 34 | 5.8s |  |
| 845 | `xml_settings` | 6 | 2.7s |  |
| 846 | `xml_simple_complex_content` | 47 | 5.8s |  |
| 847 | `xml_text` | 7 | 5.8s |  |
| 848 | `xml_tostring` | 6 | 5.8s |  |
| 849 | `xml_tostring_namespace` | 12 | 5.7s |  |
| 850 | `xml_unescaping` | 23 | 5.8s |  |
| 851 | `xml_weird_ignores` | 54 | 5.8s |  |
| 852 | `xml_wildcard` | 11 | 5.8s |  |
| 853 | `xmldocument` | 254 | 5.9s |  |
| 854 | `xmlnode` | 3540 | 6.0s |  |
| 855 | `zero_frame_clip` | 3 | 6.0s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.3s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 4.7s |  |
| 3 | `blend_transform` | 1 | 1 | 6.2s |  |
| 4 | `coerce_property` | 3 | 3 | 4.5s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 4.5s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 6.0s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.0s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 37.8s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.1s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.5s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 5.6s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.6s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 24.4s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 25.5s |  |
| 15 | `int_toexponential` | 76 | 76 | 5.7s |  |
| 16 | `int_toprecision` | 441 | 441 | 5.7s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.4s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.0s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 25.4s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.2s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.3s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.1s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 24.4s |  |
| 24 | `uint_toexponential` | 100 | 100 | 4.8s |  |
| 25 | `uint_toprecision` | 433 | 433 | 4.8s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 5.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**66 tests** within reach

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
| 19 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 20 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 21 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 22 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 23 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 24 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 25 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 26 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 27 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 28 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 29 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 30 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 31 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 32 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 33 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 34 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 35 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 36 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 37 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 38 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 39 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 40 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 41 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 42 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 43 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 44 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 45 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 46 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 47 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 48 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 49 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 50 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 51 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 52 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 53 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 54 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 55 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 56 | `xml_appendchild_swf_v21` | 53.8% | 7 | 13 | 6 |  |
| 57 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 58 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 59 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 60 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 61 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 62 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 63 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 64 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 65 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 66 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 24.4s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.0s |  |
| 3 | `verify_typecheck` | exit code 1 | 5.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**337 tests** with output mismatch, sorted by match rate (best first)

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
| 19 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 20 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 21 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 22 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 23 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 24 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 25 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 26 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 27 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 28 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 29 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 30 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 31 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 32 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 33 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 34 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 35 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 36 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 37 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 38 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 24 | 25 |  |
| 39 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 40 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 41 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 42 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 43 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 44 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 45 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 46 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 47 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 48 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 49 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 50 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 51 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 52 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 53 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 54 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 55 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 56 | `xml_appendchild_swf_v21` | 53.8% | 7/13 | 7 | 13 |  |
| 57 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 58 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 59 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 60 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 61 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 62 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 63 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 64 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 65 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 66 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 67 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 68 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 69 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 70 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 71 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 72 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 73 | `displayobject_hittestpoint_root` | 38.5% | 5/13 | 7 | 13 |  |
| 74 | `loader_reuse` | 36.8% | 14/38 | 36 | 38 |  |
| 75 | `loader_loadbytes_events` | 36.7% | 11/30 | 16 | 30 |  |
| 76 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 77 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 78 | `bom` | 33.3% | 3/9 | 3 | 9 |  |
| 79 | `displayobject_set_name_loaded` | 33.3% | 1/3 | 1 | 3 |  |
| 80 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 81 | `loader_loaderurl` | 33.3% | 2/6 | 2 | 6 |  |
| 82 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 83 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 84 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 85 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 86 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 87 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 88 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
| 89 | `loader_loadbytes_invalid_png` | 25.0% | 1/4 | 3 | 4 |  |
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
| 100 | `loader_events` | 20.7% | 19/92 | 20 | 92 |  |
| 101 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 102 | `loader_method` | 18.8% | 16/85 | 66 | 85 |  |
| 103 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 104 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 105 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 106 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 107 | `loader_bitmap_transparency` | 14.3% | 2/14 | 3 | 14 |  |
| 108 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 109 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 110 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 111 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 112 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 113 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 114 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 115 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 116 | `loader_load` | 9.4% | 12/128 | 66 | 128 |  |
| 117 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 118 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 119 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 120 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 121 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 122 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 123 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 124 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 125 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 126 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 127 | `net_navigateToURL` | 7.0% | 4/57 | 23 | 57 |  |
| 128 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 129 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 130 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 131 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 132 | `navigateToURL_target_normalize` | 5.6% | 6/107 | 35 | 107 |  |
| 133 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 134 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 135 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 136 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 137 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 138 | `font_registerfont` | 3.9% | 5/129 | 17 | 129 |  |
| 139 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 140 | `url_vars` | 3.7% | 1/27 | 3 | 27 |  |
| 141 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 142 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 143 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 144 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 145 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 146 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 147 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 148 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 149 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 150 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 151 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 152 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 153 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 154 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 155 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 156 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 157 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 158 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 159 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 160 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 161 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 162 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 163 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 164 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 165 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 166 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 167 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 168 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 169 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 170 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 171 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 172 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 173 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 174 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 175 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 176 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 177 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 178 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 179 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 180 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 181 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 182 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 183 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 184 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 185 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 186 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 187 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 188 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 189 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 190 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 191 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 192 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 193 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 194 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 195 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 196 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 197 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 198 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 199 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 200 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 201 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 202 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 203 | `blend_shader_luma_lighten` | 0.0% | 0/3 | 0 | 3 |  |
| 204 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 205 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 206 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 207 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 208 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 209 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 210 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 211 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 212 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 213 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 214 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 215 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 216 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 217 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 218 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 219 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 220 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 221 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 222 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 223 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
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
| 236 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 237 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 238 | `instantiate_root_character` | 0.0% | 0/4 | 0 | 4 |  |
| 239 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 240 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 241 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 242 | `loader_image` | 0.0% | 0/8 | 0 | 8 |  |
| 243 | `loader_noninteractive_try_click_root` | 0.0% | 0/5 | 5 | 5 |  |
| 244 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 245 | `loader_visibility_interactive` | 0.0% | 0/1 | 0 | 1 |  |
| 246 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 247 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 248 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 249 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 250 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 251 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 252 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 253 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 254 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 255 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 256 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 257 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 258 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 259 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 260 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 261 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 262 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 263 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 264 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 265 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 266 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 267 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 268 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 269 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 270 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 271 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 272 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 273 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 274 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 275 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 276 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 277 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 278 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 279 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 280 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 281 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 282 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 283 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 284 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 285 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 286 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 287 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 288 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 289 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 290 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 291 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 292 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 293 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 294 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 295 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 296 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 297 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 298 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 299 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 300 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 301 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 302 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 303 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 304 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 305 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 306 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 307 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 308 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 309 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 310 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 311 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 312 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 313 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 314 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 315 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 316 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 317 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 318 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 319 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 320 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 321 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 322 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 323 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 324 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 325 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 326 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 327 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 328 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 329 | `url_loader` | 0.0% | 0/25 | 0 | 25 |  |
| 330 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 331 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 332 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 333 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 334 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 335 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 336 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 337 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
