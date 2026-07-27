# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-27 18:12 UTC

**Git SHA**: `5a7162e204`

**Run Duration**: 189m 41s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **866** (70.9%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **892** (73.1%) |
| Failing | 329 |
| Total expected lines | 151250 |
| Matching lines | 105466 (69.7%) |
| Mismatched lines | 45784 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 324 | 98.5% |
| Runtime Error | 3 | 0.9% |
| Compile Fail | 2 | 0.6% |

## Passing Tests

**866 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.8s |  |
| 2 | `agal_compiler` | 13 | 8.1s |  |
| 3 | `air_hidden_lookup` | 2 | 5.7s |  |
| 4 | `all_classes/security/swf11` | 3 | 5.7s |  |
| 5 | `amf_custom_obj` | 26 | 5.7s |  |
| 6 | `amf_dictionary` | 9 | 5.6s |  |
| 7 | `amf_function` | 46 | 5.7s |  |
| 8 | `amf_invalid_date` | 2 | 5.6s |  |
| 9 | `amf_missing_prop` | 6 | 5.7s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.1s |  |
| 11 | `amf_setter_error` | 8 | 6.2s |  |
| 12 | `amf_vector` | 40 | 6.3s |  |
| 13 | `amf_xml` | 6 | 6.2s |  |
| 14 | `application_domain` | 4 | 6.2s |  |
| 15 | `array_access` | 18 | 6.3s |  |
| 16 | `array_access_interpreter` | 4 | 6.4s |  |
| 17 | `array_access_no_pubns` | 2 | 6.3s |  |
| 18 | `array_concat` | 41 | 6.4s |  |
| 19 | `array_constr` | 10 | 6.3s |  |
| 20 | `array_delete` | 44 | 6.5s |  |
| 21 | `array_enumeration` | 10 | 6.3s |  |
| 22 | `array_enumeration_elements` | 11 | 6.3s |  |
| 23 | `array_every` | 8 | 6.3s |  |
| 24 | `array_filter` | 6 | 6.3s |  |
| 25 | `array_foreach` | 18 | 6.2s |  |
| 26 | `array_hasownproperty` | 11 | 3.0s |  |
| 27 | `array_holes` | 9 | 6.3s |  |
| 28 | `array_index_max` | 84 | 6.2s |  |
| 29 | `array_indexof` | 25 | 6.3s |  |
| 30 | `array_join` | 26 | 6.3s |  |
| 31 | `array_lastindexof` | 29 | 6.3s |  |
| 32 | `array_length` | 14 | 6.2s |  |
| 33 | `array_literal` | 3 | 6.2s |  |
| 34 | `array_map` | 8 | 6.1s |  |
| 35 | `array_pop` | 52 | 6.3s |  |
| 36 | `array_push` | 24 | 6.3s |  |
| 37 | `array_reborrow_bug` | 6 | 6.1s |  |
| 38 | `array_reverse` | 28 | 6.2s |  |
| 39 | `array_shift` | 51 | 3.1s |  |
| 40 | `array_slice` | 39 | 6.2s |  |
| 41 | `array_some` | 8 | 6.2s |  |
| 42 | `array_sort` | 297 | 6.7s |  |
| 43 | `array_sort_fun_swf12` | 2 | 6.2s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 45 | `array_sort_random` | 210 | 6.2s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 6.1s |  |
| 47 | `array_sorton` | 545 | 5.3s |  |
| 48 | `array_sparse_ops` | 41 | 4.8s |  |
| 49 | `array_splice` | 133 | 4.9s |  |
| 50 | `array_splice2` | 428 | 5.0s |  |
| 51 | `array_splice_types` | 48 | 4.8s |  |
| 52 | `array_storage` | 8 | 4.7s |  |
| 53 | `array_tolocalestring` | 9 | 4.7s |  |
| 54 | `array_tostring` | 12 | 4.7s |  |
| 55 | `array_unshift` | 24 | 4.7s |  |
| 56 | `array_valueof` | 9 | 4.6s |  |
| 57 | `array_vector_null_callback` | 10 | 4.7s |  |
| 58 | `astype` | 28 | 4.8s |  |
| 59 | `astypelate` | 24 | 4.7s |  |
| 60 | `astypelate_propagates` | 1 | 4.7s |  |
| 61 | `asymmetric_key_events` | 11 | 5.1s |  |
| 62 | `avm2_catchup_dobj` | 158 | 5.5s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 64.8s |  |
| 64 | `bitand` | 1058 | 12.8s |  |
| 65 | `bitmap_constr` | 17 | 4.8s |  |
| 66 | `bitmap_data` | 1000 | 10.0s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 20.5s |  |
| 68 | `bitmap_properties` | 23 | 4.7s |  |
| 69 | `bitmap_subclass` | 7 | 5.7s |  |
| 70 | `bitmap_subclass_properties` | 9 | 5.1s |  |
| 71 | `bitmap_timeline` | 9 | 4.7s |  |
| 72 | `bitmapdata_accuracy` | 1 | 46.4s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 20.9s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 5.4s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 20.5s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 20.9s |  |
| 77 | `bitmapdata_clone` | 13 | 4.9s |  |
| 78 | `bitmapdata_colortransform` | 0 | 5.0s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 4.6s |  |
| 80 | `bitmapdata_constr` | 22 | 4.8s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 4.8s |  |
| 82 | `bitmapdata_copychannel` | 0 | 26.9s |  |
| 83 | `bitmapdata_copypixels` | 23 | 25.3s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 6.0s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.8s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.9s |  |
| 87 | `bitmapdata_draw` | 0 | 24.8s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.3s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 24.3s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 24.0s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 5.9s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.3s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.2s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 23.9s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 6.0s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.2s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.2s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 24.2s |  |
| 99 | `bitmapdata_floodfill` | 35 | 5.8s |  |
| 100 | `bitmapdata_getpixels` | 39 | 24.5s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.9s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.8s |  |
| 103 | `bitmapdata_hittest` | 112 | 6.6s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 5.9s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.1s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 24.3s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.2s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 5.8s |  |
| 109 | `bitmapdata_setpixels` | 286 | 6.0s |  |
| 110 | `bitmapdata_setvector` | 26 | 6.0s |  |
| 111 | `bitmapdata_sync` | 0 | 6.1s |  |
| 112 | `bitmapdata_threshold` | 176 | 6.6s |  |
| 113 | `bitnot` | 46 | 5.9s |  |
| 114 | `bitor` | 1058 | 18.1s |  |
| 115 | `bitxor` | 1058 | 18.0s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.2s |  |
| 117 | `blend_scroll` | 0 | 6.2s |  |
| 118 | `boolean_constr` | 32 | 6.0s |  |
| 119 | `boolean_negation` | 30 | 5.9s |  |
| 120 | `boolean_tostring` | 8 | 5.8s |  |
| 121 | `broadcast_event` | 7 | 5.9s |  |
| 122 | `button_nested_frame` | 48 | 24.7s |  |
| 123 | `bytearray` | 48 | 6.2s |  |
| 124 | `bytearray_compress` | 31 | 6.0s |  |
| 125 | `bytearray_errors` | 24 | 6.0s |  |
| 126 | `bytearray_method_serialization` | 1 | 5.8s |  |
| 127 | `bytearray_oom` | 3 | 5.9s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 5.8s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 5.9s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 5.9s |  |
| 131 | `bytearray_serialization` | 3 | 5.8s |  |
| 132 | `bytearray_string_null` | 19 | 6.1s |  |
| 133 | `bytearray_tostring` | 15 | 5.8s |  |
| 134 | `bytearray_utf16` | 8 | 5.8s |  |
| 135 | `bytearray_writeobject` | 24 | 5.7s |  |
| 136 | `callee_in_initializer` | 6 | 5.7s |  |
| 137 | `callproplex_class` | 1 | 5.8s |  |
| 138 | `capabilities_resolution` | 8 | 24.6s |  |
| 139 | `catch_class` | 6 | 5.8s |  |
| 140 | `catch_scope_slot` | 7 | 2.8s |  |
| 141 | `checkfilter` | 4 | 2.7s |  |
| 142 | `class_call` | 32 | 23.7s |  |
| 143 | `class_cast_call` | 14 | 5.9s |  |
| 144 | `class_enumeration` | 4 | 5.8s |  |
| 145 | `class_has_own_property` | 2 | 5.8s |  |
| 146 | `class_init_interpreter_mode` | 1 | 5.7s |  |
| 147 | `class_is` | 32 | 5.9s |  |
| 148 | `class_methods` | 5 | 5.8s |  |
| 149 | `class_object_properties` | 10 | 5.9s |  |
| 150 | `class_singleton` | 18 | 5.9s |  |
| 151 | `class_supercalls_errors` | 35 | 6.0s |  |
| 152 | `class_supercalls_mismatched` | 26 | 5.9s |  |
| 153 | `class_superclass_wrong_order` | 1 | 24.5s |  |
| 154 | `class_to_locale_string` | 2 | 6.1s |  |
| 155 | `class_to_string` | 2 | 5.9s |  |
| 156 | `class_value_of` | 2 | 6.0s |  |
| 157 | `click_block` | 5 | 24.5s |  |
| 158 | `click_invisible` | 3 | 6.1s |  |
| 159 | `closures` | 12 | 6.1s |  |
| 160 | `coerce_return_type` | 40 | 6.2s |  |
| 161 | `coerce_return_type_fail` | 2 | 6.0s |  |
| 162 | `coerce_return_void` | 3 | 6.0s |  |
| 163 | `coerce_string` | 86 | 6.1s |  |
| 164 | `coerce_string_precision` | 28 | 6.1s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 24.8s |  |
| 166 | `construct_errors_swf10` | 8 | 6.1s |  |
| 167 | `construct_frame_list` | 22 | 25.3s |  |
| 168 | `constructor_call` | 3 | 6.0s |  |
| 169 | `constructors_vs_timeline` | 5 | 25.7s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 6.4s |  |
| 171 | `control_flow_bool` | 4 | 6.2s |  |
| 172 | `control_flow_stricteq` | 8 | 6.2s |  |
| 173 | `convert_boolean` | 30 | 6.3s |  |
| 174 | `convert_integer` | 90 | 6.4s |  |
| 175 | `convert_number` | 56 | 6.3s |  |
| 176 | `convert_uinteger` | 90 | 6.4s |  |
| 177 | `cryptscore` | 11 | 6.3s |  |
| 178 | `date` | 30 | 6.6s |  |
| 179 | `date_parse` | 36 | 6.3s |  |
| 180 | `declocal` | 46 | 6.3s |  |
| 181 | `declocal_i` | 46 | 6.4s |  |
| 182 | `decode_uri` | 71 | 6.8s |  |
| 183 | `decrement` | 46 | 6.5s |  |
| 184 | `decrement_i` | 46 | 3.1s |  |
| 185 | `default_values` | 7 | 6.4s |  |
| 186 | `dictionary_access` | 62 | 6.7s |  |
| 187 | `dictionary_access_no_pubns` | 2 | 6.3s |  |
| 188 | `dictionary_delete` | 101 | 7.0s |  |
| 189 | `dictionary_foreach` | 42 | 6.5s |  |
| 190 | `dictionary_hasownproperty` | 63 | 6.5s |  |
| 191 | `dictionary_in` | 62 | 6.4s |  |
| 192 | `dictionary_iter_modify` | 8 | 6.2s |  |
| 193 | `dictionary_namespaces` | 36 | 6.3s |  |
| 194 | `dictionary_primitive_keys` | 29 | 6.2s |  |
| 195 | `displayobject_alpha` | 277 | 6.2s |  |
| 196 | `displayobject_blendmode` | 0 | 6.4s |  |
| 197 | `displayobject_colortransform_nested` | 0 | 25.5s |  |
| 198 | `displayobject_from_enterframe` | 1 | 25.6s |  |
| 199 | `displayobject_getbounds_shape` | 0 | 25.8s |  |
| 200 | `displayobject_height` | 6052 | 26.3s |  |
| 201 | `displayobject_hittestobject` | 32 | 6.4s |  |
| 202 | `displayobject_invalid_floats` | 60 | 6.2s |  |
| 203 | `displayobject_invalid_props` | 3 | 6.2s |  |
| 204 | `displayobject_mask` | 3 | 6.7s |  |
| 205 | `displayobject_mask_self_referential` | 0 | 25.5s |  |
| 206 | `displayobject_metaData` | 3 | 6.2s |  |
| 207 | `displayobject_name` | 22 | 25.5s |  |
| 208 | `displayobject_name_from_timeline` | 24 | 25.3s |  |
| 209 | `displayobject_parent` | 12 | 6.0s |  |
| 210 | `displayobject_root` | 24 | 6.1s |  |
| 211 | `displayobject_rotation` | 1284 | 6.2s |  |
| 212 | `displayobject_set_matrix_nested` | 0 | 25.4s |  |
| 213 | `displayobject_set_name_loaded` | 3 | 6.5s |  |
| 214 | `displayobject_subclass` | 2 | 6.1s |  |
| 215 | `displayobject_visible` | 23 | 6.1s |  |
| 216 | `displayobject_width` | 4852 | 25.3s |  |
| 217 | `displayobject_x` | 614 | 6.1s |  |
| 218 | `displayobject_y` | 617 | 6.1s |  |
| 219 | `displayobjectcontainer_addchild` | 32 | 6.2s |  |
| 220 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.1s |  |
| 221 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.3s |  |
| 222 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.2s |  |
| 223 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.2s |  |
| 224 | `displayobjectcontainer_addchildat` | 42 | 6.1s |  |
| 225 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.2s |  |
| 226 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.1s |  |
| 227 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.1s |  |
| 228 | `displayobjectcontainer_contains` | 66 | 25.2s |  |
| 229 | `displayobjectcontainer_getchildat` | 4 | 6.1s |  |
| 230 | `displayobjectcontainer_getchildbyname` | 9 | 6.0s |  |
| 231 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.0s |  |
| 232 | `displayobjectcontainer_getchildindex` | 28 | 6.1s |  |
| 233 | `displayobjectcontainer_removechild` | 10 | 6.0s |  |
| 234 | `displayobjectcontainer_removechild_errors` | 4 | 6.1s |  |
| 235 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.1s |  |
| 236 | `displayobjectcontainer_removechildat` | 18 | 6.0s |  |
| 237 | `displayobjectcontainer_removechildren` | 51 | 6.3s |  |
| 238 | `displayobjectcontainer_setchildindex` | 42 | 6.0s |  |
| 239 | `displayobjectcontainer_stopallmovieclips` | 2 | 25.6s |  |
| 240 | `displayobjectcontainer_swapchildren` | 42 | 6.2s |  |
| 241 | `displayobjectcontainer_swapchildrenat` | 42 | 6.1s |  |
| 242 | `displayobjectcontainer_timelineinstance` | 48 | 24.0s |  |
| 243 | `divide` | 1058 | 17.9s |  |
| 244 | `doabc_is_eager` | 1 | 23.5s |  |
| 245 | `documentclass` | 9 | 6.0s |  |
| 246 | `domain_memory` | 133 | 25.1s |  |
| 247 | `drag_drop` | 10 | 6.0s |  |
| 248 | `duplicate_defs` | 1 | 5.7s |  |
| 249 | `eager_init` | 1 | 5.8s |  |
| 250 | `edit_text_linkage` | 7 | 6.0s |  |
| 251 | `edittext_align` | 60 | 6.3s |  |
| 252 | `edittext_always_show_selection` | 0 | 24.3s |  |
| 253 | `edittext_antialiastype` | 296 | 6.1s |  |
| 254 | `edittext_at_point_methods_basic` | 16 | 7.2s |  |
| 255 | `edittext_autosize` | 39 | 6.2s |  |
| 256 | `edittext_autosize_align` | 0 | 24.4s |  |
| 257 | `edittext_autosize_height_dynamic` | 60 | 24.3s |  |
| 258 | `edittext_autosize_height_input` | 60 | 6.0s |  |
| 259 | `edittext_autosize_lazy_bounds_events` | 65 | 6.2s |  |
| 260 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.9s |  |
| 261 | `edittext_autosize_lazy_bounds_props` | 490 | 7.2s |  |
| 262 | `edittext_autosize_lazy_bounds_visual` | 0 | 24.1s |  |
| 263 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.1s |  |
| 264 | `edittext_bottom_scroll_v_basic` | 210 | 6.0s |  |
| 265 | `edittext_bounds_scale` | 24 | 23.7s |  |
| 266 | `edittext_bullet` | 30 | 6.0s |  |
| 267 | `edittext_default_format` | 221 | 6.2s |  |
| 268 | `edittext_default_format_empty` | 136 | 6.1s |  |
| 269 | `edittext_empty_text_format` | 7 | 5.9s |  |
| 270 | `edittext_focus_selection` | 5 | 5.8s |  |
| 271 | `edittext_font_size` | 45 | 5.9s |  |
| 272 | `edittext_format_empty_font` | 8 | 5.8s |  |
| 273 | `edittext_get_char_index_at_point` | 4 | 24.9s |  |
| 274 | `edittext_get_line_index_at_point` | 2 | 24.3s |  |
| 275 | `edittext_get_line_index_of_char` | 76 | 6.7s |  |
| 276 | `edittext_getcharboundaries` | 172 | 6.2s |  |
| 277 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.5s |  |
| 278 | `edittext_getcharboundaries_scroll` | 85 | 24.9s |  |
| 279 | `edittext_getlinemetrics` | 146 | 6.3s |  |
| 280 | `edittext_html` | 3101 | 6.6s |  |
| 281 | `edittext_html_condensewhite` | 487 | 6.3s |  |
| 282 | `edittext_html_entity` | 4 | 6.4s |  |
| 283 | `edittext_html_font_size_swf12` | 267 | 6.2s |  |
| 284 | `edittext_html_font_size_swf13` | 273 | 5.9s |  |
| 285 | `edittext_html_roundtrip` | 17 | 6.2s |  |
| 286 | `edittext_input_control` | 12 | 6.3s |  |
| 287 | `edittext_leading` | 9 | 6.4s |  |
| 288 | `edittext_letter_spacing` | 15 | 6.2s |  |
| 289 | `edittext_line_methods` | 294 | 7.5s |  |
| 290 | `edittext_line_metrics` | 11 | 26.1s |  |
| 291 | `edittext_margins` | 25 | 6.2s |  |
| 292 | `edittext_max_scroll_h_basic` | 475 | 6.3s |  |
| 293 | `edittext_max_scroll_v_basic` | 1000 | 6.2s |  |
| 294 | `edittext_mousedown` | 3 | 6.5s |  |
| 295 | `edittext_mouseenabled` | 26 | 6.2s |  |
| 296 | `edittext_newline_character` | 22 | 6.1s |  |
| 297 | `edittext_newline_stripping` | 64 | 8.7s |  |
| 298 | `edittext_newlines` | 30 | 6.2s |  |
| 299 | `edittext_paragraph_methods` | 257 | 6.1s |  |
| 300 | `edittext_paste_events` | 8 | 6.3s |  |
| 301 | `edittext_paste_maxchars` | 4 | 6.2s |  |
| 302 | `edittext_paste_restrict` | 16 | 6.0s |  |
| 303 | `edittext_restrict` | 191 | 6.1s |  |
| 304 | `edittext_restrict_events` | 22 | 6.1s |  |
| 305 | `edittext_scrollh` | 10 | 6.1s |  |
| 306 | `edittext_selected_text` | 9 | 6.1s |  |
| 307 | `edittext_set_html_same` | 17 | 6.1s |  |
| 308 | `edittext_set_text_vs_html` | 9 | 6.1s |  |
| 309 | `edittext_stylesheet` | 536 | 6.5s |  |
| 310 | `edittext_stylesheet_custom_tag` | 76 | 6.2s |  |
| 311 | `edittext_stylesheet_display` | 272 | 6.2s |  |
| 312 | `edittext_underline` | 40 | 6.3s |  |
| 313 | `edittext_width_height` | 103 | 18.0s |  |
| 314 | `edittext_wordwrap_word` | 150 | 24.3s |  |
| 315 | `edittext_wrap_breaks` | 2375 | 6.4s |  |
| 316 | `empty_bounds` | 1 | 5.8s |  |
| 317 | `encode_uri_surrogate_pair_swf11` | 15 | 5.6s |  |
| 318 | `equals` | 512 | 9.7s |  |
| 319 | `error_geterrormessage` | 779 | 6.0s |  |
| 320 | `error_prototype` | 15 | 5.9s |  |
| 321 | `error_stack_trace_debug_swf17` | 0 | 24.1s |  |
| 322 | `error_stack_trace_debug_swf18` | 0 | 5.7s |  |
| 323 | `error_stack_trace_release_swf17` | 0 | 5.8s |  |
| 324 | `error_stack_trace_release_swf18` | 0 | 5.7s |  |
| 325 | `error_tostring` | 29 | 5.8s |  |
| 326 | `es3_inheritance` | 31 | 5.9s |  |
| 327 | `es4_inheritance` | 30 | 5.9s |  |
| 328 | `es4_interfaces` | 30 | 5.9s |  |
| 329 | `es4_method_binding` | 8 | 5.8s |  |
| 330 | `es4_oop_prototypes` | 14 | 6.0s |  |
| 331 | `es4_protected_inheritance` | 6 | 5.9s |  |
| 332 | `escape` | 71 | 6.0s |  |
| 333 | `event_bubbles` | 2 | 5.8s |  |
| 334 | `event_cancelable` | 2 | 5.7s |  |
| 335 | `event_clone` | 20 | 5.9s |  |
| 336 | `event_clone_error_redispatch` | 3 | 6.0s |  |
| 337 | `event_clone_on_redispatch` | 10 | 6.0s |  |
| 338 | `event_formattostring` | 31 | 6.0s |  |
| 339 | `event_isdefaultprevented` | 12 | 5.9s |  |
| 340 | `event_target_getter` | 5 | 2.8s |  |
| 341 | `event_target_set` | 9 | 5.8s |  |
| 342 | `event_type` | 1 | 18.6s |  |
| 343 | `event_valueof_tostring` | 18 | 6.3s |  |
| 344 | `eventdispatcher_dispatchevent` | 12 | 6.3s |  |
| 345 | `eventdispatcher_dispatchevent_cancel` | 20 | 25.4s |  |
| 346 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.3s |  |
| 347 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.4s |  |
| 348 | `eventdispatcher_dispatchevent_this` | 5 | 6.2s |  |
| 349 | `eventdispatcher_haseventlistener` | 25 | 6.3s |  |
| 350 | `eventdispatcher_interface_invoke` | 1 | 6.2s |  |
| 351 | `eventdispatcher_tostring` | 10 | 6.2s |  |
| 352 | `eventdispatcher_willtrigger` | 25 | 6.2s |  |
| 353 | `falsiness` | 30 | 6.3s |  |
| 354 | `fast_index_access` | 12 | 6.4s |  |
| 355 | `finddef` | 3 | 6.3s |  |
| 356 | `findprop_global_prototype` | 6 | 6.3s |  |
| 357 | `flash_xml` | 29 | 6.4s |  |
| 358 | `flash_xml_cloneNode` | 22 | 6.3s |  |
| 359 | `flash_xml_namespace` | 109 | 6.3s |  |
| 360 | `flash_xml_removeNode` | 60 | 6.2s |  |
| 361 | `focus_events_code` | 161 | 25.3s |  |
| 362 | `focus_events_key_same_object` | 26 | 6.2s |  |
| 363 | `focus_events_mixed_key_mouse` | 100 | 24.6s |  |
| 364 | `focus_events_mouse_same_object` | 40 | 25.2s |  |
| 365 | `focus_remove` | 20 | 25.1s |  |
| 366 | `focus_root_movie` | 4 | 26.9s |  |
| 367 | `focus_stage` | 1 | 6.3s |  |
| 368 | `focusrect` | 18 | 7.2s |  |
| 369 | `font_description_clone` | 14 | 6.3s |  |
| 370 | `font_embedded` | 24 | 25.4s |  |
| 371 | `font_enumeratefonts` | 41 | 6.8s |  |
| 372 | `font_enumeratefonts_filter` | 4 | 25.8s |  |
| 373 | `font_hasglyphs` | 40 | 6.7s |  |
| 374 | `framelabel_constr` | 5 | 6.5s |  |
| 375 | `function_call` | 12 | 6.3s |  |
| 376 | `function_call_arguments` | 46 | 6.5s |  |
| 377 | `function_call_arguments_enumerate` | 5 | 6.3s |  |
| 378 | `function_call_coercion` | 108 | 6.7s |  |
| 379 | `function_call_default` | 6 | 6.4s |  |
| 380 | `function_call_rest` | 22 | 6.3s |  |
| 381 | `function_call_types` | 3 | 6.2s |  |
| 382 | `function_call_via_apply` | 11 | 6.3s |  |
| 383 | `function_call_via_call` | 3 | 6.3s |  |
| 384 | `function_display_anonymous` | 7 | 3.1s |  |
| 385 | `function_length` | 6 | 6.3s |  |
| 386 | `function_object` | 2 | 6.3s |  |
| 387 | `function_proto` | 5 | 6.2s |  |
| 388 | `function_proto_created` | 61 | 6.3s |  |
| 389 | `function_to_locale_string` | 4 | 6.3s |  |
| 390 | `function_to_string` | 4 | 6.2s |  |
| 391 | `function_type` | 6 | 6.3s |  |
| 392 | `function_unbound_this` | 51 | 6.3s |  |
| 393 | `function_value_of` | 4 | 6.2s |  |
| 394 | `get_definition_by_name` | 11 | 6.3s |  |
| 395 | `get_qualified_class_name` | 20 | 18.1s |  |
| 396 | `get_qualified_super_class_name` | 18 | 6.0s |  |
| 397 | `get_slot_edge_cases` | 1 | 24.0s |  |
| 398 | `get_timer` | 2 | 6.0s |  |
| 399 | `getglobalslot` | 1 | 6.0s |  |
| 400 | `getouterscope` | 8 | 5.9s |  |
| 401 | `getter_different_namespace_setter` | 2 | 5.8s |  |
| 402 | `goto_button_nested_framescript` | 28 | 24.4s |  |
| 403 | `goto_in_constructframe` | 12 | 24.2s |  |
| 404 | `goto_in_scene_last_frame` | 2 | 23.8s |  |
| 405 | `goto_methods` | 56 | 6.1s |  |
| 406 | `goto_methods_swfver10` | 8 | 6.0s |  |
| 407 | `goto_nested_construct_sibling` | 18 | 6.5s |  |
| 408 | `goto_nested_framescript` | 9 | 6.2s |  |
| 409 | `goto_on_orphan` | 15 | 6.2s |  |
| 410 | `graphics_bad_direct_commands` | 5 | 8.7s |  |
| 411 | `graphics_bitmap_fill` | 0 | 26.5s |  |
| 412 | `graphics_bitmaps` | 0 | 6.8s |  |
| 413 | `graphics_direct_commands` | 0 | 6.7s |  |
| 414 | `graphics_draw_triangles` | 98 | 25.2s |  |
| 415 | `graphics_gradients` | 0 | 6.5s |  |
| 416 | `graphics_gradients_nulls` | 0 | 6.3s |  |
| 417 | `graphics_path` | 56 | 6.1s |  |
| 418 | `graphics_round_rects` | 0 | 6.0s |  |
| 419 | `graphics_simple_shapes` | 0 | 6.4s |  |
| 420 | `greaterequals` | 512 | 9.9s |  |
| 421 | `greaterthan` | 512 | 9.9s |  |
| 422 | `has_own_property` | 102 | 6.5s |  |
| 423 | `hasownproperty_namespaces` | 2 | 6.0s |  |
| 424 | `hello_world` | 1 | 6.0s |  |
| 425 | `hittest_morph` | 30 | 6.1s |  |
| 426 | `if_eq` | 10 | 6.1s |  |
| 427 | `if_gt` | 1 | 6.0s |  |
| 428 | `if_gte` | 10 | 18.9s |  |
| 429 | `if_lt` | 1 | 6.4s |  |
| 430 | `if_lte` | 10 | 6.2s |  |
| 431 | `if_ne` | 7 | 3.1s |  |
| 432 | `if_stricteq` | 6 | 6.3s |  |
| 433 | `if_strictne` | 11 | 6.3s |  |
| 434 | `in` | 102 | 6.7s |  |
| 435 | `inclocal` | 46 | 6.2s |  |
| 436 | `inclocal_i` | 46 | 6.3s |  |
| 437 | `increment` | 46 | 6.3s |  |
| 438 | `increment_i` | 46 | 6.2s |  |
| 439 | `indexing_delete` | 75 | 6.3s |  |
| 440 | `instanceof` | 58 | 6.5s |  |
| 441 | `instantiation_on_enter_frame` | 7 | 25.0s |  |
| 442 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.2s |  |
| 443 | `int_constr` | 92 | 6.5s |  |
| 444 | `int_edge_cases` | 19 | 6.4s |  |
| 445 | `int_instanceof` | 3 | 6.1s |  |
| 446 | `int_tofixed` | 1215 | 6.2s |  |
| 447 | `int_tostring` | 3375 | 6.4s |  |
| 448 | `interactiveobject_enabled` | 25 | 6.1s |  |
| 449 | `interface_namespaces` | 78 | 6.4s |  |
| 450 | `is_finite` | 46 | 6.3s |  |
| 451 | `is_nan` | 46 | 6.0s |  |
| 452 | `is_prototype_of` | 12 | 6.3s |  |
| 453 | `issue_10221` | 2 | 6.1s |  |
| 454 | `issue_13780` | 12 | 6.2s |  |
| 455 | `issue_14901` | 1 | 6.0s |  |
| 456 | `issue_17675_edittext_paste_maxchars` | 1 | 6.1s |  |
| 457 | `issue_5292` | 5 | 6.2s |  |
| 458 | `issue_8630` | 2 | 24.2s |  |
| 459 | `issue_8630_scriptremove` | 11 | 6.1s |  |
| 460 | `istype` | 24 | 2.9s |  |
| 461 | `istypelate` | 58 | 6.3s |  |
| 462 | `istypelate_coerce` | 198 | 19.2s |  |
| 463 | `jpeg_loader_context` | 6 | 24.7s |  |
| 464 | `json_errors` | 9 | 24.6s |  |
| 465 | `json_parse` | 21 | 6.1s |  |
| 466 | `json_stringify` | 12 | 6.4s |  |
| 467 | `json_stringify_order` | 1 | 6.1s |  |
| 468 | `json_version_gated` | 1 | 6.1s |  |
| 469 | `key_input_80percent` | 1812 | 6.3s |  |
| 470 | `key_input_location` | 126 | 6.2s |  |
| 471 | `key_input_numpad` | 384 | 6.1s |  |
| 472 | `lazyinit` | 17 | 6.1s |  |
| 473 | `lessequals` | 512 | 9.7s |  |
| 474 | `lessthan` | 512 | 9.7s |  |
| 475 | `loader_bitmap_transparency` | 14 | 6.3s |  |
| 476 | `loader_bytes_unknown_content` | 14 | 6.2s |  |
| 477 | `loader_events` | 92 | 8.8s |  |
| 478 | `loader_image` | 8 | 6.7s |  |
| 479 | `loader_jpegxr` | 2 | 25.0s |  |
| 480 | `loader_jpegxr_alpha` | 1 | 24.7s |  |
| 481 | `loader_loadbytes_events` | 30 | 7.0s |  |
| 482 | `loader_loadbytes_invalid_png` | 4 | 24.4s |  |
| 483 | `loader_reuse` | 38 | 6.3s |  |
| 484 | `loader_unknown_content` | 24 | 6.2s |  |
| 485 | `loader_visibility_interactive` | 1 | 6.2s |  |
| 486 | `loaderinfo_events` | 7 | 6.1s |  |
| 487 | `loaderinfo_loadurl` | 12 | 35.7s |  |
| 488 | `loaderinfo_more` | 6 | 24.3s |  |
| 489 | `loaderinfo_properties` | 18 | 5.9s |  |
| 490 | `loaderinfo_properties_not_loaded` | 23 | 6.0s |  |
| 491 | `loaderinfo_root` | 10 | 5.9s |  |
| 492 | `loaderinfo_root_allows` | 2 | 5.8s |  |
| 493 | `lshift` | 1058 | 18.0s |  |
| 494 | `mask_reapply` | 1 | 6.0s |  |
| 495 | `math` | 497 | 6.1s |  |
| 496 | `missing_external_interface` | 10 | 5.9s |  |
| 497 | `modulo` | 1058 | 17.9s |  |
| 498 | `morph_shape` | 2 | 24.0s |  |
| 499 | `mouse_click_events` | 90 | 23.9s |  |
| 500 | `mouse_double_click_events` | 188 | 5.9s |  |
| 501 | `mouse_empty_parent` | 4 | 5.9s |  |
| 502 | `mouse_over_while_dragging` | 3 | 6.0s |  |
| 503 | `mouse_pick_button_mode` | 2 | 6.0s |  |
| 504 | `mouse_sibling` | 8 | 5.9s |  |
| 505 | `movieclip_addframescript` | 3 | 23.8s |  |
| 506 | `movieclip_child_property` | 16 | 5.9s |  |
| 507 | `movieclip_constr` | 21 | 17.6s |  |
| 508 | `movieclip_currentlabels` | 17 | 23.6s |  |
| 509 | `movieclip_currentlabels_dupes1` | 46 | 23.6s |  |
| 510 | `movieclip_currentlabels_dupes2` | 30 | 5.8s |  |
| 511 | `movieclip_currentlabels_dupes3` | 67 | 5.8s |  |
| 512 | `movieclip_currentscene` | 12 | 23.5s |  |
| 513 | `movieclip_dispatchevent` | 430 | 5.9s |  |
| 514 | `movieclip_dispatchevent_cancel` | 102 | 6.0s |  |
| 515 | `movieclip_dispatchevent_handlerorder` | 251 | 5.9s |  |
| 516 | `movieclip_dispatchevent_selfadd` | 80 | 5.8s |  |
| 517 | `movieclip_dispatchevent_target` | 899 | 5.9s |  |
| 518 | `movieclip_displayevents` | 96 | 23.8s |  |
| 519 | `movieclip_displayevents_clickgoto` | 676 | 24.0s |  |
| 520 | `movieclip_displayevents_clickgoto2` | 2001 | 6.3s |  |
| 521 | `movieclip_displayevents_clickplay` | 575 | 6.0s |  |
| 522 | `movieclip_displayevents_clicksymbol` | 562 | 6.0s |  |
| 523 | `movieclip_displayevents_constructframegoto` | 140 | 6.2s |  |
| 524 | `movieclip_displayevents_constructframeplay` | 50 | 6.1s |  |
| 525 | `movieclip_displayevents_constructframesymbol` | 144 | 6.0s |  |
| 526 | `movieclip_displayevents_dblhandler` | 21 | 6.0s |  |
| 527 | `movieclip_displayevents_enterframegoto` | 149 | 6.1s |  |
| 528 | `movieclip_displayevents_enterframeplay` | 48 | 6.0s |  |
| 529 | `movieclip_displayevents_enterframesymbol` | 149 | 23.8s |  |
| 530 | `movieclip_displayevents_exitframegoto` | 106 | 5.9s |  |
| 531 | `movieclip_displayevents_exitframeplay` | 44 | 5.9s |  |
| 532 | `movieclip_displayevents_exitframesymbol` | 135 | 6.0s |  |
| 533 | `movieclip_displayevents_looping` | 63 | 23.9s |  |
| 534 | `movieclip_displayevents_stopped` | 113 | 6.2s |  |
| 535 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 536 | `movieclip_displayevents_timeline` | 128 | 23.9s |  |
| 537 | `movieclip_drawrect` | 54 | 5.9s |  |
| 538 | `movieclip_frameconstruct_skipped` | 9 | 6.0s |  |
| 539 | `movieclip_goto_during_frame_script` | 15 | 5.9s |  |
| 540 | `movieclip_goto_overwrite` | 14 | 23.6s |  |
| 541 | `movieclip_goto_scene_last_frame_int` | 1 | 23.8s |  |
| 542 | `movieclip_goto_scene_last_frame_label` | 1 | 5.7s |  |
| 543 | `movieclip_gotoandplay` | 15 | 23.5s |  |
| 544 | `movieclip_gotoandstop` | 13 | 5.8s |  |
| 545 | `movieclip_gotoandstop_children` | 4 | 5.9s |  |
| 546 | `movieclip_gotoandstop_framescripts1` | 4 | 5.8s |  |
| 547 | `movieclip_gotoandstop_framescripts2` | 4 | 2.7s |  |
| 548 | `movieclip_gotoandstop_framescripts_self` | 7 | 38.8s |  |
| 549 | `movieclip_gotoandstop_queueing` | 12 | 26.1s |  |
| 550 | `movieclip_next_frame` | 2 | 26.1s |  |
| 551 | `movieclip_next_scene` | 6 | 26.0s |  |
| 552 | `movieclip_play` | 3 | 6.3s |  |
| 553 | `movieclip_prev_frame` | 3 | 6.3s |  |
| 554 | `movieclip_prev_scene` | 7 | 6.5s |  |
| 555 | `movieclip_properties` | 79 | 26.2s |  |
| 556 | `movieclip_queued_noop_goto_swf10` | 9 | 6.5s |  |
| 557 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 558 | `movieclip_scenes` | 11 | 6.4s |  |
| 559 | `movieclip_soundtransform` | 831 | 28.2s |  |
| 560 | `movieclip_stop` | 1 | 25.6s |  |
| 561 | `movieclip_super_is_symbol` | 20 | 6.7s |  |
| 562 | `movieclip_symbol_constr` | 8 | 6.5s |  |
| 563 | `movieclip_text_mousedown` | 1 | 6.4s |  |
| 564 | `movieclip_willtrigger` | 5 | 6.7s |  |
| 565 | `multiply` | 1058 | 18.3s |  |
| 566 | `namespace_constr` | 253 | 6.8s |  |
| 567 | `namespace_constr_args` | 1 | 6.5s |  |
| 568 | `namespace_enumeration_order` | 7 | 26.9s |  |
| 569 | `nan_scale` | 9 | 6.5s |  |
| 570 | `navigateToURL_target_normalize` | 107 | 27.7s |  |
| 571 | `negate` | 30 | 6.5s |  |
| 572 | `negative_volume_panned` | 0 | 6.6s |  |
| 573 | `nested_iteration` | 11 | 6.8s |  |
| 574 | `net_getClassByAlias` | 3 | 6.5s |  |
| 575 | `net_navigateToURL` | 57 | 6.6s |  |
| 576 | `newactivation_in_script_init` | 3 | 6.5s |  |
| 577 | `newclass_twice` | 3 | 6.3s |  |
| 578 | `nonconflicting_declarations` | 0 | 6.5s |  |
| 579 | `null_void_types` | 8 | 6.4s |  |
| 580 | `number_autoconv` | 21 | 25.9s |  |
| 581 | `number_autoconv_amf` | 132 | 6.3s |  |
| 582 | `number_autoconv_array_sort_32bit` | 1 | 6.3s |  |
| 583 | `number_constr` | 58 | 6.4s |  |
| 584 | `number_toexponential` | 378 | 6.3s |  |
| 585 | `number_toexponential2` | 35 | 6.3s |  |
| 586 | `number_tofixed` | 378 | 6.3s |  |
| 587 | `number_toprecision` | 350 | 6.4s |  |
| 588 | `obfuscated_class_names` | 3 | 6.3s |  |
| 589 | `object_enumeration` | 10 | 6.4s |  |
| 590 | `object_prototype` | 4 | 6.4s |  |
| 591 | `object_to_locale_string` | 2 | 6.4s |  |
| 592 | `object_to_string` | 2 | 6.3s |  |
| 593 | `object_value_of` | 2 | 2.9s |  |
| 594 | `op_coerce` | 54 | 6.4s |  |
| 595 | `op_coerce_x` | 54 | 6.5s |  |
| 596 | `op_escxattr` | 2 | 6.4s |  |
| 597 | `op_escxelem` | 2 | 6.3s |  |
| 598 | `op_lookupswitch` | 4 | 6.4s |  |
| 599 | `optimize_coerce` | 1 | 6.3s |  |
| 600 | `orphan_movie_complex` | 80 | 6.8s |  |
| 601 | `orphan_movie_reorder` | 111 | 26.9s |  |
| 602 | `package_namespace` | 7 | 6.2s |  |
| 603 | `param_default_value_has_zero_cpool_index` | 1 | 6.2s |  |
| 604 | `parent_early_access_child` | 16 | 26.7s |  |
| 605 | `parse_float` | 81 | 6.7s |  |
| 606 | `pixelbender_effect_BlurredFocus` | 0 | 28.5s |  |
| 607 | `pixelbender_effect_glassDisplace` | 0 | 11.5s |  |
| 608 | `pixelbender_effect_smudge` | 0 | 9.3s |  |
| 609 | `pixelbender_effect_tintype` | 0 | 8.6s |  |
| 610 | `pixelbender_effect_twirl` | 0 | 9.6s |  |
| 611 | `pixelbender_images` | 0 | 8.1s |  |
| 612 | `place_multiple` | 17 | 24.6s |  |
| 613 | `place_object_replace` | 9 | 6.2s |  |
| 614 | `place_object_replace_2` | 24 | 6.2s |  |
| 615 | `place_object_same_depth_frame` | 1 | 6.0s |  |
| 616 | `point` | 132 | 6.6s |  |
| 617 | `primitive_edge_cases` | 1 | 6.0s |  |
| 618 | `property_priority` | 22 | 6.3s |  |
| 619 | `property_priority_three_level` | 6 | 24.3s |  |
| 620 | `propertyisenumerable_namespaces` | 6 | 6.0s |  |
| 621 | `prototype_set_null` | 7 | 5.9s |  |
| 622 | `proxy_callproperty` | 24 | 5.9s |  |
| 623 | `proxy_deleteproperty` | 64 | 6.0s |  |
| 624 | `proxy_enumeration` | 34 | 6.0s |  |
| 625 | `proxy_getproperty` | 77 | 6.1s |  |
| 626 | `proxy_hasownproperty` | 8 | 5.9s |  |
| 627 | `proxy_hasproperty` | 32 | 6.0s |  |
| 628 | `proxy_serialize` | 9 | 5.9s |  |
| 629 | `proxy_setproperty` | 42 | 5.9s |  |
| 630 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.9s |  |
| 631 | `qname_constr` | 32 | 6.0s |  |
| 632 | `qname_constr_namespace` | 24 | 6.0s |  |
| 633 | `qname_enumeration` | 9 | 6.0s |  |
| 634 | `qname_indexing` | 23 | 6.0s |  |
| 635 | `qname_tostring` | 25 | 6.2s |  |
| 636 | `qname_valueof` | 29 | 6.1s |  |
| 637 | `regexp_constr` | 148 | 6.4s |  |
| 638 | `regexp_exec` | 19 | 6.1s |  |
| 639 | `regexp_extended` | 47 | 6.2s |  |
| 640 | `regexp_multiargs` | 1 | 6.1s |  |
| 641 | `regexp_test` | 27 | 6.2s |  |
| 642 | `regexp_toString` | 10 | 6.1s |  |
| 643 | `register_script_refresh` | 35 | 6.4s |  |
| 644 | `remove_child_clear_field` | 88 | 25.0s |  |
| 645 | `remove_dobj` | 3 | 6.0s |  |
| 646 | `resolve_order` | 4 | 6.2s |  |
| 647 | `rng` | 1 | 7.3s |  |
| 648 | `rootless` | 42 | 6.2s |  |
| 649 | `rshift` | 1058 | 18.3s |  |
| 650 | `sandbox_type_local_file` | 1 | 24.2s |  |
| 651 | `scene_constr` | 8 | 6.1s |  |
| 652 | `set_local_0` | 31 | 6.0s |  |
| 653 | `set_property_is_enumerable` | 85 | 6.3s |  |
| 654 | `shape_drawrect` | 54 | 5.9s |  |
| 655 | `shared_object_no_root` | 3 | 5.9s |  |
| 656 | `simplebutton_added_to_stage` | 45 | 23.9s |  |
| 657 | `simplebutton_childevents` | 86 | 24.4s |  |
| 658 | `simplebutton_childevents_nested` | 54 | 6.2s |  |
| 659 | `simplebutton_childevents_sprite` | 13 | 6.0s |  |
| 660 | `simplebutton_childprops` | 144 | 6.1s |  |
| 661 | `simplebutton_childshuffle` | 23 | 5.8s |  |
| 662 | `simplebutton_constr` | 36 | 6.2s |  |
| 663 | `simplebutton_constr_childevents` | 48 | 6.2s |  |
| 664 | `simplebutton_constr_params` | 42 | 6.0s |  |
| 665 | `simplebutton_mouseenabled` | 26 | 5.9s |  |
| 666 | `simplebutton_multi_children` | 19 | 6.1s |  |
| 667 | `simplebutton_structure` | 27 | 6.1s |  |
| 668 | `simplebutton_symbolclass` | 68 | 6.4s |  |
| 669 | `slot_disp_id_shared_numbering` | 1 | 23.7s |  |
| 670 | `slots_force_autoassigned` | 1 | 6.0s |  |
| 671 | `sound_embeddedprops` | 26 | 6.2s |  |
| 672 | `sound_play` | 19 | 6.1s |  |
| 673 | `sound_valueof` | 33 | 6.0s |  |
| 674 | `soundchannel_soundtransform` | 835 | 26.0s |  |
| 675 | `soundchannel_soundtransform_exists` | 5 | 24.5s |  |
| 676 | `soundchannel_stop` | 8 | 24.5s |  |
| 677 | `soundmixer_buffertime` | 5 | 6.1s |  |
| 678 | `soundmixer_stopall` | 6 | 24.6s |  |
| 679 | `soundtransform` | 442 | 11.9s |  |
| 680 | `sprite_with_frames` | 0 | 26.4s |  |
| 681 | `stage3d_agal_cross_product` | 0 | 8.7s |  |
| 682 | `stage3d_bitmap` | 0 | 29.5s |  |
| 683 | `stage3d_float1_index` | 0 | 26.9s |  |
| 684 | `stage3d_fractal` | 0 | 27.5s |  |
| 685 | `stage3d_ignore_sampler_override` | 0 | 27.5s |  |
| 686 | `stage3d_program_constants_bytearray_be` | 0 | 28.7s |  |
| 687 | `stage3d_program_constants_bytearray_le` | 0 | 9.4s |  |
| 688 | `stage3d_raytrace` | 0 | 30.5s |  |
| 689 | `stage3d_rotating_cube` | 0 | 9.6s |  |
| 690 | `stage3d_sampler` | 0 | 22.2s |  |
| 691 | `stage3d_sampler_partial_upload` | 0 | 8.7s |  |
| 692 | `stage3d_stencil` | 0 | 27.6s |  |
| 693 | `stage3d_texture` | 0 | 13.4s |  |
| 694 | `stage3d_texture_bytearray` | 0 | 9.9s |  |
| 695 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.3s |  |
| 696 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.4s |  |
| 697 | `stage3d_triangle` | 0 | 8.7s |  |
| 698 | `stage3d_triangle_bytes4` | 0 | 8.7s |  |
| 699 | `stage3d_triangle_float1` | 0 | 8.7s |  |
| 700 | `stage3d_triangle_index_upload` | 0 | 8.6s |  |
| 701 | `stage_access` | 10 | 5.9s |  |
| 702 | `stage_displayobject_properties` | 24 | 5.8s |  |
| 703 | `stage_framerate_nan` | 7 | 24.1s |  |
| 704 | `stage_framerate_negative` | 6 | 5.8s |  |
| 705 | `stage_framerate_zero` | 6 | 5.9s |  |
| 706 | `stage_invalidate` | 38 | 6.1s |  |
| 707 | `stage_loaderinfo_properties` | 24 | 23.8s |  |
| 708 | `stage_mousechildren` | 2 | 5.8s |  |
| 709 | `stage_mouseenabled` | 15 | 5.8s |  |
| 710 | `stage_overriden_setters` | 31 | 6.0s |  |
| 711 | `stage_properties` | 30 | 5.8s |  |
| 712 | `static_var_with_this_in_ctor` | 2 | 5.8s |  |
| 713 | `stored_properties` | 11 | 5.9s |  |
| 714 | `strict_equality` | 34 | 5.9s |  |
| 715 | `string_call` | 13 | 5.9s |  |
| 716 | `string_case` | 23 | 5.9s |  |
| 717 | `string_char_at` | 27 | 5.9s |  |
| 718 | `string_char_code_at` | 28 | 5.7s |  |
| 719 | `string_concat_fromcharcode` | 37 | 5.8s |  |
| 720 | `string_constr` | 25 | 5.9s |  |
| 721 | `string_indexof_lastindexof` | 87 | 28.1s |  |
| 722 | `string_length` | 16 | 19.0s |  |
| 723 | `string_locale_compare` | 39 | 4.4s |  |
| 724 | `string_match` | 51 | 4.6s |  |
| 725 | `string_relational_compare` | 4 | 19.9s |  |
| 726 | `string_replace` | 51 | 4.4s |  |
| 727 | `string_search` | 41 | 4.3s |  |
| 728 | `string_slice_substr_substring` | 170 | 5.0s |  |
| 729 | `string_split` | 29 | 4.5s |  |
| 730 | `string_substr_negative` | 21 | 4.8s |  |
| 731 | `string_substr_weird` | 182 | 4.4s |  |
| 732 | `subtract` | 1058 | 11.8s |  |
| 733 | `super_get_call` | 12 | 4.3s |  |
| 734 | `supercall_two_classobjects` | 2 | 4.6s |  |
| 735 | `swf8` | 1 | 4.4s |  |
| 736 | `swf_10_queued_goto_scripts_construct` | 52 | 19.0s |  |
| 737 | `swf_9_goto_in_enter_frame` | 17 | 4.3s |  |
| 738 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.6s |  |
| 739 | `swf_9_queued_goto_scripts` | 6 | 19.0s |  |
| 740 | `swf_9_queued_goto_scripts_construct` | 28 | 0.9s |  |
| 741 | `swf_9_versioning` | 2 | 4.4s |  |
| 742 | `swf_wrong_frame_count` | 38 | 4.8s |  |
| 743 | `swf_wrong_frame_count_isplaying` | 22 | 4.3s |  |
| 744 | `symbol_class_binary_data` | 8 | 4.7s |  |
| 745 | `symbol_class_conflict` | 4 | 6.3s |  |
| 746 | `symbol_class_root_not_zero` | 1 | 4.5s |  |
| 747 | `symbolclass_invalid_utf8` | 2 | 4.5s |  |
| 748 | `tab_ordering_automatic_advanced` | 184 | 6.0s |  |
| 749 | `tab_ordering_automatic_basic` | 45 | 23.2s |  |
| 750 | `tab_ordering_children` | 116 | 5.5s |  |
| 751 | `tab_ordering_custom_basic` | 34 | 5.4s |  |
| 752 | `text_engine_fontdescription` | 27 | 5.5s |  |
| 753 | `text_run` | 7 | 5.3s |  |
| 754 | `textfield_focusin_event` | 9 | 5.4s |  |
| 755 | `textfield_input_dead_keys_windows` | 15 | 5.5s |  |
| 756 | `textfield_unload` | 39 | 23.2s |  |
| 757 | `textformat` | 1134 | 5.5s |  |
| 758 | `textformat_display` | 14 | 5.5s |  |
| 759 | `textformat_font_max_length` | 4 | 5.4s |  |
| 760 | `throw` | 3 | 5.4s |  |
| 761 | `timeline_scripts` | 3 | 5.6s |  |
| 762 | `timer` | 90 | 6.0s |  |
| 763 | `timer_events` | 3 | 5.6s |  |
| 764 | `timer_finished` | 11 | 5.6s |  |
| 765 | `timer_reset` | 8 | 5.6s |  |
| 766 | `timer_setdelay` | 5 | 5.4s |  |
| 767 | `trace` | 12 | 5.5s |  |
| 768 | `truthiness` | 30 | 17.6s |  |
| 769 | `try_catch` | 11 | 5.8s |  |
| 770 | `try_catch_typed` | 12 | 5.8s |  |
| 771 | `typeof` | 30 | 5.8s |  |
| 772 | `uint_constr` | 92 | 5.9s |  |
| 773 | `uint_tofixed` | 1215 | 5.6s |  |
| 774 | `uint_tostring` | 3375 | 5.9s |  |
| 775 | `unchecked_function` | 15 | 5.7s |  |
| 776 | `unescape` | 28 | 5.7s |  |
| 777 | `url_loader` | 25 | 5.8s |  |
| 778 | `urlrequest` | 18 | 24.1s |  |
| 779 | `urshift` | 1058 | 17.9s |  |
| 780 | `vector_class` | 36 | 6.2s |  |
| 781 | `vector_class_call` | 11 | 5.9s |  |
| 782 | `vector_coercion` | 66 | 6.5s |  |
| 783 | `vector_concat` | 90 | 6.4s |  |
| 784 | `vector_constr` | 107 | 6.6s |  |
| 785 | `vector_enumeration` | 5 | 5.7s |  |
| 786 | `vector_every` | 92 | 6.6s |  |
| 787 | `vector_filter` | 95 | 6.6s |  |
| 788 | `vector_holes` | 24 | 5.8s |  |
| 789 | `vector_indexof` | 302 | 10.6s |  |
| 790 | `vector_insertat` | 270 | 6.8s |  |
| 791 | `vector_int_access` | 4 | 5.7s |  |
| 792 | `vector_int_delete` | 11 | 5.8s |  |
| 793 | `vector_join` | 58 | 6.2s |  |
| 794 | `vector_lastindexof` | 302 | 5.6s |  |
| 795 | `vector_legacy` | 10 | 5.7s |  |
| 796 | `vector_map` | 85 | 6.4s |  |
| 797 | `vector_object_final` | 1 | 5.6s |  |
| 798 | `vector_object_toString` | 10 | 5.7s |  |
| 799 | `vector_pushpop` | 255 | 7.1s |  |
| 800 | `vector_reborrow_bug` | 10 | 37.6s |  |
| 801 | `vector_removeat` | 172 | 7.4s |  |
| 802 | `vector_reverse` | 232 | 7.3s |  |
| 803 | `vector_shiftunshift` | 252 | 7.5s |  |
| 804 | `vector_slice` | 331 | 7.9s |  |
| 805 | `vector_sort` | 905 | 15.6s |  |
| 806 | `vector_splice` | 693 | 10.2s |  |
| 807 | `vector_splice_fixed_bug_compat` | 4 | 6.2s |  |
| 808 | `vector_tostring` | 79 | 6.8s |  |
| 809 | `verify_abnormal_loop` | 1 | 6.0s |  |
| 810 | `verify_exception_targets_edge_case` | 1 | 6.1s |  |
| 811 | `verify_lookup_switch_edge_case` | 1 | 6.1s |  |
| 812 | `verify_unreachable_exception` | 2 | 6.1s |  |
| 813 | `versioned_isplaying` | 2 | 6.2s |  |
| 814 | `virtual_properties` | 16 | 6.3s |  |
| 815 | `with` | 4 | 6.2s |  |
| 816 | `wrong_arg_count` | 7 | 6.4s |  |
| 817 | `xml_abstract_equality` | 36 | 6.5s |  |
| 818 | `xml_advanced` | 52 | 6.3s |  |
| 819 | `xml_appendchild` | 10 | 6.3s |  |
| 820 | `xml_as_attribute` | 9 | 6.2s |  |
| 821 | `xml_attribute` | 35 | 6.4s |  |
| 822 | `xml_attribute_name` | 40 | 6.3s |  |
| 823 | `xml_basic` | 33 | 6.4s |  |
| 824 | `xml_child` | 25 | 6.4s |  |
| 825 | `xml_childindex` | 7 | 6.2s |  |
| 826 | `xml_children` | 43 | 6.9s |  |
| 827 | `xml_class_call` | 9 | 6.3s |  |
| 828 | `xml_contains` | 197 | 6.4s |  |
| 829 | `xml_copy` | 20 | 39.2s |  |
| 830 | `xml_ctor_from_tostring` | 23 | 6.9s |  |
| 831 | `xml_delete` | 114 | 6.6s |  |
| 832 | `xml_descendants` | 83 | 6.5s |  |
| 833 | `xml_elements` | 6 | 6.5s |  |
| 834 | `xml_equals_namespace_check` | 2 | 6.4s |  |
| 835 | `xml_explicit_use_namespace` | 5 | 25.8s |  |
| 836 | `xml_getdescendants_qname` | 21 | 6.5s |  |
| 837 | `xml_has_property_via_in` | 26 | 6.5s |  |
| 838 | `xml_hasownproperty` | 6 | 6.6s |  |
| 839 | `xml_ignore_white` | 6 | 6.5s |  |
| 840 | `xml_length` | 2 | 6.4s |  |
| 841 | `xml_list_as_attribute` | 9 | 6.5s |  |
| 842 | `xml_list_concat` | 20 | 6.4s |  |
| 843 | `xml_list_enumerate` | 4 | 6.3s |  |
| 844 | `xml_methods_settings` | 3 | 6.4s |  |
| 845 | `xml_mismatched_tag` | 37 | 6.4s |  |
| 846 | `xml_namespace` | 39 | 6.5s |  |
| 847 | `xml_namespace_methods` | 245 | 6.5s |  |
| 848 | `xml_namespaced_property` | 7 | 6.4s |  |
| 849 | `xml_no_namespace` | 1 | 6.4s |  |
| 850 | `xml_nodekind` | 3 | 6.5s |  |
| 851 | `xml_normalize` | 35 | 6.6s |  |
| 852 | `xml_notification_bubbling` | 361 | 6.5s |  |
| 853 | `xml_parent` | 8 | 6.4s |  |
| 854 | `xml_set_children` | 17 | 6.5s |  |
| 855 | `xml_set_name` | 34 | 6.4s |  |
| 856 | `xml_settings` | 6 | 3.1s |  |
| 857 | `xml_simple_complex_content` | 47 | 6.5s |  |
| 858 | `xml_text` | 7 | 6.4s |  |
| 859 | `xml_tostring` | 6 | 6.3s |  |
| 860 | `xml_tostring_namespace` | 12 | 6.2s |  |
| 861 | `xml_unescaping` | 23 | 6.2s |  |
| 862 | `xml_weird_ignores` | 54 | 6.3s |  |
| 863 | `xml_wildcard` | 11 | 6.2s |  |
| 864 | `xmldocument` | 254 | 6.4s |  |
| 865 | `xmlnode` | 3540 | 6.4s |  |
| 866 | `zero_frame_clip` | 3 | 6.6s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.2s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 20.2s |  |
| 3 | `blend_transform` | 1 | 1 | 6.3s |  |
| 4 | `coerce_property` | 3 | 3 | 6.1s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.2s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 25.0s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.1s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 36.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.2s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 5.9s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 5.9s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 6.3s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 24.0s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 25.2s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.4s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.3s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.1s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.8s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 23.8s |  |
| 20 | `soundchannel_position` | 74 | 74 | 24.8s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.1s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.0s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 19.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.9s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.8s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 6.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**71 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 5 | `focus_events_mouse_focusable` | 98.2% | 110 | 112 | 2 |  |
| 6 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 7 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 8 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 9 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 10 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
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
| 21 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 22 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 23 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 24 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 25 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 26 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 27 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 28 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 29 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 30 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 31 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 32 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 33 | `loader_loaderurl` | 83.3% | 5 | 6 | 1 |  |
| 34 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 35 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 36 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 37 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 38 | `mouse_wheel_events` | 80.6% | 29 | 36 | 7 |  |
| 39 | `loader_noninteractive_try_click_root` | 80.0% | 4 | 5 | 1 |  |
| 40 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 41 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 42 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 43 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 44 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 45 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 46 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 47 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 48 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 49 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 50 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 51 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 52 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 53 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 54 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 55 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 56 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 57 | `mouse_children` | 59.4% | 114 | 192 | 78 |  |
| 58 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 59 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 60 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 61 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 62 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 63 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 64 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 65 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 66 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 67 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 68 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 69 | `sandbox_type_inherited` | 50.0% | 1 | 2 | 1 |  |
| 70 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 71 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 23.9s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**324 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 5 | `focus_events_mouse_focusable` | 98.2% | 110/112 | 112 | 112 |  |
| 6 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 7 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 8 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 9 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 10 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
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
| 21 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 22 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 23 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 24 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 25 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 26 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 27 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 28 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 29 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 30 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 31 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 32 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 33 | `loader_loaderurl` | 83.3% | 5/6 | 6 | 6 |  |
| 34 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 35 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 36 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 37 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 38 | `mouse_wheel_events` | 80.6% | 29/36 | 36 | 36 |  |
| 39 | `loader_noninteractive_try_click_root` | 80.0% | 4/5 | 5 | 5 |  |
| 40 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 41 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 42 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 43 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 44 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 45 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 46 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 47 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 48 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 49 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 50 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 51 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 52 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 53 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 54 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 55 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 56 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 57 | `mouse_children` | 59.4% | 114/192 | 192 | 192 |  |
| 58 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 59 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 60 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 61 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 62 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 63 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 64 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 65 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 66 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 67 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 68 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 69 | `sandbox_type_inherited` | 50.0% | 1/2 | 1 | 2 |  |
| 70 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 71 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 72 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 73 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 74 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 75 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 76 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 77 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 78 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 79 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 80 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 81 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 82 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 83 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 84 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 85 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 86 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 87 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 88 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
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
| 101 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 102 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 103 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 104 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 105 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 106 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 107 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 108 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 109 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 110 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 111 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 112 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 113 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 114 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 115 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 116 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 117 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 118 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 119 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 120 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 121 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 122 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 123 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 124 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 125 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 126 | `font_registerfont` | 6.2% | 8/129 | 29 | 129 |  |
| 127 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 128 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 129 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 130 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 131 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 132 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 133 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 134 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 135 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 136 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 137 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 138 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 139 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 140 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 141 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 142 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 143 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 144 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 145 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 146 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 147 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 148 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 149 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 150 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 151 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 152 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 153 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 154 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 155 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 156 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 157 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 158 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 159 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 160 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 161 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 162 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 163 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 164 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 165 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 166 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 167 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 168 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 169 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 170 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 171 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 172 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 173 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 174 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 175 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 176 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 177 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 178 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 179 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 180 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 181 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 182 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 183 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 184 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 185 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 186 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 187 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 188 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 189 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 190 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 191 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 192 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 193 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 194 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 195 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 196 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
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
| 208 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 209 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 210 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 211 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 212 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 213 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 214 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 215 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 216 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 217 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 218 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 219 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 220 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 221 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 222 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 223 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 224 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 225 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 226 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 227 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 228 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 229 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 230 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 231 | `instantiate_root_character` | 0.0% | 0/4 | 3 | 4 |  |
| 232 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 233 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 234 | `loader_error_in_root_ctor` | 0.0% | 0/4 | 0 | 4 |  |
| 235 | `loader_try_click_root` | 0.0% | 0/16 | 16 | 16 |  |
| 236 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 237 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 238 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 239 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 240 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 241 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 242 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 243 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 244 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 245 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 246 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 247 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 248 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 249 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 250 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 251 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 252 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 253 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 254 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 255 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 256 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 257 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 258 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 259 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 260 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 261 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 262 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 263 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 264 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 265 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 266 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 267 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 268 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 269 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 270 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 271 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 272 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 273 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 274 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 275 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 276 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 277 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 278 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 279 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 280 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 281 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 282 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 283 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 284 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 285 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 286 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 287 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 288 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 289 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 290 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 291 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 292 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 293 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 294 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 295 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 296 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 297 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 298 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 299 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 300 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 301 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 302 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 303 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 304 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 305 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 306 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 307 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 308 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 309 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 310 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 311 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 312 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 313 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 314 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 315 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 316 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 317 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 318 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 319 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 320 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 321 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 322 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 323 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 324 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
