# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-29 01:25 UTC

**Git SHA**: `767a301d2b`

**Run Duration**: 197m 55s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **919** (75.3%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **945** (77.4%) |
| Failing | 276 |
| Total expected lines | 151253 |
| Matching lines | 107237 (70.9%) |
| Mismatched lines | 44016 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 273 | 98.9% |
| Runtime Error | 3 | 1.1% |

## Passing Tests

**919 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.8s |  |
| 2 | `agal_compiler` | 13 | 8.8s |  |
| 3 | `air_datagram_socket` | 1 | 6.7s |  |
| 4 | `air_hidden_lookup` | 2 | 6.4s |  |
| 5 | `all_classes/security/swf11` | 3 | 6.5s |  |
| 6 | `amf_custom_obj` | 26 | 6.5s |  |
| 7 | `amf_dictionary` | 9 | 6.4s |  |
| 8 | `amf_function` | 46 | 6.5s |  |
| 9 | `amf_invalid_date` | 2 | 6.4s |  |
| 10 | `amf_missing_prop` | 6 | 6.4s |  |
| 11 | `amf_nondynamic_function_prop` | 6 | 6.5s |  |
| 12 | `amf_setter_error` | 8 | 6.7s |  |
| 13 | `amf_vector` | 40 | 6.7s |  |
| 14 | `amf_xml` | 6 | 6.5s |  |
| 15 | `application_domain` | 4 | 6.5s |  |
| 16 | `array_access` | 18 | 6.6s |  |
| 17 | `array_access_interpreter` | 4 | 6.5s |  |
| 18 | `array_access_no_pubns` | 2 | 6.5s |  |
| 19 | `array_concat` | 41 | 6.6s |  |
| 20 | `array_constr` | 10 | 6.5s |  |
| 21 | `array_delete` | 44 | 6.7s |  |
| 22 | `array_enumeration` | 10 | 6.6s |  |
| 23 | `array_enumeration_elements` | 11 | 6.5s |  |
| 24 | `array_every` | 8 | 6.5s |  |
| 25 | `array_filter` | 6 | 6.5s |  |
| 26 | `array_foreach` | 18 | 6.5s |  |
| 27 | `array_hasownproperty` | 11 | 3.1s |  |
| 28 | `array_holes` | 9 | 6.6s |  |
| 29 | `array_index_max` | 84 | 6.5s |  |
| 30 | `array_indexof` | 25 | 6.6s |  |
| 31 | `array_join` | 26 | 6.6s |  |
| 32 | `array_lastindexof` | 29 | 6.6s |  |
| 33 | `array_length` | 14 | 6.6s |  |
| 34 | `array_literal` | 3 | 6.5s |  |
| 35 | `array_map` | 8 | 6.5s |  |
| 36 | `array_pop` | 52 | 6.7s |  |
| 37 | `array_push` | 24 | 6.6s |  |
| 38 | `array_reborrow_bug` | 6 | 6.5s |  |
| 39 | `array_reverse` | 28 | 6.6s |  |
| 40 | `array_shift` | 51 | 3.2s |  |
| 41 | `array_slice` | 39 | 6.6s |  |
| 42 | `array_some` | 8 | 6.5s |  |
| 43 | `array_sort` | 297 | 7.0s |  |
| 44 | `array_sort_fun_swf12` | 2 | 6.6s |  |
| 45 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 46 | `array_sort_random` | 210 | 6.6s |  |
| 47 | `array_sort_swf10_32bit` | 1 | 6.5s |  |
| 48 | `array_sorton` | 545 | 6.8s |  |
| 49 | `array_sparse_ops` | 41 | 6.2s |  |
| 50 | `array_splice` | 133 | 6.4s |  |
| 51 | `array_splice2` | 428 | 6.5s |  |
| 52 | `array_splice_types` | 48 | 6.2s |  |
| 53 | `array_storage` | 8 | 6.1s |  |
| 54 | `array_tolocalestring` | 9 | 6.2s |  |
| 55 | `array_tostring` | 12 | 6.4s |  |
| 56 | `array_unshift` | 24 | 6.1s |  |
| 57 | `array_valueof` | 9 | 6.1s |  |
| 58 | `array_vector_null_callback` | 10 | 6.1s |  |
| 59 | `astype` | 28 | 6.2s |  |
| 60 | `astypelate` | 24 | 6.2s |  |
| 61 | `astypelate_propagates` | 1 | 6.0s |  |
| 62 | `asymmetric_key_events` | 11 | 6.3s |  |
| 63 | `av_networking_params` | 9 | 6.2s |  |
| 64 | `avm2_catchup_dobj` | 158 | 6.7s |  |
| 65 | `away3d_advanced_shallow_water_demo` | 0 | 80.2s |  |
| 66 | `bitand` | 1058 | 16.0s |  |
| 67 | `bitmap_constr` | 17 | 6.5s |  |
| 68 | `bitmap_data` | 1000 | 12.8s |  |
| 69 | `bitmap_pixelsnapping` | 2 | 26.0s |  |
| 70 | `bitmap_properties` | 23 | 6.4s |  |
| 71 | `bitmap_subclass` | 7 | 7.6s |  |
| 72 | `bitmap_subclass_properties` | 9 | 6.7s |  |
| 73 | `bitmap_timeline` | 9 | 6.4s |  |
| 74 | `bitmapdata_accuracy` | 1 | 54.5s |  |
| 75 | `bitmapdata_applyfilter_blur` | 0 | 26.2s |  |
| 76 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.9s |  |
| 77 | `bitmapdata_applyfilter_destpoint` | 0 | 25.8s |  |
| 78 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.3s |  |
| 79 | `bitmapdata_clone` | 13 | 6.6s |  |
| 80 | `bitmapdata_colortransform` | 0 | 6.5s |  |
| 81 | `bitmapdata_colortransform_oob` | 2 | 6.0s |  |
| 82 | `bitmapdata_constr` | 22 | 6.2s |  |
| 83 | `bitmapdata_constructor_from_timeline` | 1 | 6.4s |  |
| 84 | `bitmapdata_copychannel` | 0 | 27.6s |  |
| 85 | `bitmapdata_copypixels` | 23 | 25.6s |  |
| 86 | `bitmapdata_copypixels_blend_over` | 1 | 6.0s |  |
| 87 | `bitmapdata_copypixelstobytearray` | 39 | 5.9s |  |
| 88 | `bitmapdata_dispose` | 7 | 5.9s |  |
| 89 | `bitmapdata_draw` | 0 | 25.2s |  |
| 90 | `bitmapdata_draw_colortransform` | 0 | 6.1s |  |
| 91 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 24.7s |  |
| 92 | `bitmapdata_draw_filters` | 0 | 24.4s |  |
| 93 | `bitmapdata_draw_masks` | 0 | 5.8s |  |
| 94 | `bitmapdata_draw_rotation` | 0 | 6.1s |  |
| 95 | `bitmapdata_draw_self_via_graphic` | 0 | 6.1s |  |
| 96 | `bitmapdata_draw_stage` | 0 | 24.5s |  |
| 97 | `bitmapdata_drawwithquality` | 0 | 6.2s |  |
| 98 | `bitmapdata_embedded` | 9 | 6.2s |  |
| 99 | `bitmapdata_fillrect` | 0 | 6.1s |  |
| 100 | `bitmapdata_filter_sourcerect` | 0 | 24.9s |  |
| 101 | `bitmapdata_floodfill` | 35 | 5.9s |  |
| 102 | `bitmapdata_getpixels` | 39 | 24.7s |  |
| 103 | `bitmapdata_getvector` | 27 | 2.6s |  |
| 104 | `bitmapdata_histogram` | 59 | 2.6s |  |
| 105 | `bitmapdata_hittest` | 112 | 6.5s |  |
| 106 | `bitmapdata_hittest_threshold` | 18 | 5.9s |  |
| 107 | `bitmapdata_opaque` | 0 | 6.1s |  |
| 108 | `bitmapdata_pixeldissolve` | 1037 | 24.8s |  |
| 109 | `bitmapdata_pixeldissolve_image` | 0 | 6.3s |  |
| 110 | `bitmapdata_rectangle_rounding` | 16 | 6.0s |  |
| 111 | `bitmapdata_setpixels` | 286 | 6.0s |  |
| 112 | `bitmapdata_setvector` | 26 | 6.1s |  |
| 113 | `bitmapdata_sync` | 0 | 6.1s |  |
| 114 | `bitmapdata_threshold` | 176 | 6.7s |  |
| 115 | `bitnot` | 46 | 5.9s |  |
| 116 | `bitor` | 1058 | 17.4s |  |
| 117 | `bitxor` | 1058 | 17.5s |  |
| 118 | `blend_multiply_alpha` | 0 | 6.1s |  |
| 119 | `blend_scroll` | 0 | 6.1s |  |
| 120 | `boolean_constr` | 32 | 6.7s |  |
| 121 | `boolean_negation` | 30 | 6.7s |  |
| 122 | `boolean_tostring` | 8 | 6.6s |  |
| 123 | `broadcast_event` | 7 | 6.8s |  |
| 124 | `button_nested_frame` | 48 | 26.8s |  |
| 125 | `bytearray` | 48 | 7.1s |  |
| 126 | `bytearray_compress` | 31 | 6.8s |  |
| 127 | `bytearray_errors` | 24 | 6.9s |  |
| 128 | `bytearray_method_serialization` | 1 | 6.7s |  |
| 129 | `bytearray_oom` | 3 | 6.8s |  |
| 130 | `bytearray_readobject_amf0` | 50 | 6.8s |  |
| 131 | `bytearray_readobject_amf3` | 53 | 6.8s |  |
| 132 | `bytearray_readutf8bytes_with_bom` | 16 | 6.8s |  |
| 133 | `bytearray_serialization` | 3 | 6.8s |  |
| 134 | `bytearray_string_null` | 19 | 7.0s |  |
| 135 | `bytearray_tostring` | 15 | 6.8s |  |
| 136 | `bytearray_utf16` | 8 | 6.8s |  |
| 137 | `bytearray_writeobject` | 24 | 6.8s |  |
| 138 | `callee_in_initializer` | 6 | 6.7s |  |
| 139 | `callproplex_class` | 1 | 6.7s |  |
| 140 | `capabilities_resolution` | 8 | 27.0s |  |
| 141 | `catch_class` | 6 | 6.8s |  |
| 142 | `catch_scope_slot` | 7 | 3.4s |  |
| 143 | `checkfilter` | 4 | 3.3s |  |
| 144 | `class_call` | 32 | 26.7s |  |
| 145 | `class_cast_call` | 14 | 6.9s |  |
| 146 | `class_enumeration` | 4 | 6.9s |  |
| 147 | `class_has_own_property` | 2 | 6.8s |  |
| 148 | `class_init_interpreter_mode` | 1 | 6.8s |  |
| 149 | `class_is` | 32 | 6.9s |  |
| 150 | `class_methods` | 5 | 6.8s |  |
| 151 | `class_object_properties` | 10 | 6.8s |  |
| 152 | `class_singleton` | 18 | 6.9s |  |
| 153 | `class_supercalls_errors` | 35 | 7.1s |  |
| 154 | `class_supercalls_mismatched` | 26 | 7.0s |  |
| 155 | `class_superclass_wrong_order` | 1 | 24.3s |  |
| 156 | `class_to_locale_string` | 2 | 6.3s |  |
| 157 | `class_to_string` | 2 | 6.3s |  |
| 158 | `class_value_of` | 2 | 6.5s |  |
| 159 | `click_block` | 5 | 26.2s |  |
| 160 | `click_invisible` | 3 | 6.7s |  |
| 161 | `closures` | 12 | 6.5s |  |
| 162 | `coerce_return_type` | 40 | 6.6s |  |
| 163 | `coerce_return_type_fail` | 2 | 6.4s |  |
| 164 | `coerce_return_void` | 3 | 6.5s |  |
| 165 | `coerce_string` | 86 | 6.7s |  |
| 166 | `coerce_string_precision` | 28 | 6.5s |  |
| 167 | `coerce_to_primitive_side_effects` | 29 | 25.6s |  |
| 168 | `construct_errors_swf10` | 8 | 6.7s |  |
| 169 | `construct_frame_list` | 22 | 25.8s |  |
| 170 | `constructor_call` | 3 | 6.5s |  |
| 171 | `constructors_vs_timeline` | 5 | 26.0s |  |
| 172 | `constructprop_dynamic_primitive` | 7 | 6.6s |  |
| 173 | `control_flow_bool` | 4 | 6.6s |  |
| 174 | `control_flow_stricteq` | 8 | 6.6s |  |
| 175 | `convert_boolean` | 30 | 6.6s |  |
| 176 | `convert_integer` | 90 | 6.7s |  |
| 177 | `convert_number` | 56 | 6.7s |  |
| 178 | `convert_uinteger` | 90 | 6.7s |  |
| 179 | `cross_api_version_call_older` | 12 | 6.9s |  |
| 180 | `cryptscore` | 11 | 6.6s |  |
| 181 | `date` | 30 | 7.3s |  |
| 182 | `date_parse` | 36 | 6.9s |  |
| 183 | `declocal` | 46 | 6.9s |  |
| 184 | `declocal_i` | 46 | 6.9s |  |
| 185 | `decode_uri` | 71 | 7.2s |  |
| 186 | `decrement` | 46 | 6.7s |  |
| 187 | `decrement_i` | 46 | 3.1s |  |
| 188 | `default_values` | 7 | 6.4s |  |
| 189 | `dictionary_access` | 62 | 6.7s |  |
| 190 | `dictionary_access_no_pubns` | 2 | 6.4s |  |
| 191 | `dictionary_delete` | 101 | 7.0s |  |
| 192 | `dictionary_foreach` | 42 | 6.8s |  |
| 193 | `dictionary_hasownproperty` | 63 | 6.8s |  |
| 194 | `dictionary_in` | 62 | 6.7s |  |
| 195 | `dictionary_iter_modify` | 8 | 6.5s |  |
| 196 | `dictionary_namespaces` | 36 | 6.6s |  |
| 197 | `dictionary_primitive_keys` | 29 | 6.4s |  |
| 198 | `displayobject_alpha` | 277 | 6.4s |  |
| 199 | `displayobject_blendmode` | 0 | 6.6s |  |
| 200 | `displayobject_colortransform_nested` | 0 | 25.7s |  |
| 201 | `displayobject_from_enterframe` | 1 | 25.4s |  |
| 202 | `displayobject_getbounds_shape` | 0 | 25.7s |  |
| 203 | `displayobject_height` | 6052 | 25.6s |  |
| 204 | `displayobject_hittestobject` | 32 | 6.5s |  |
| 205 | `displayobject_invalid_floats` | 60 | 6.9s |  |
| 206 | `displayobject_invalid_props` | 3 | 6.9s |  |
| 207 | `displayobject_mask` | 3 | 7.0s |  |
| 208 | `displayobject_mask_self_referential` | 0 | 25.6s |  |
| 209 | `displayobject_metaData` | 3 | 6.5s |  |
| 210 | `displayobject_name` | 22 | 25.6s |  |
| 211 | `displayobject_name_from_timeline` | 24 | 25.6s |  |
| 212 | `displayobject_parent` | 12 | 6.6s |  |
| 213 | `displayobject_root` | 24 | 6.6s |  |
| 214 | `displayobject_rotation` | 1284 | 6.7s |  |
| 215 | `displayobject_set_matrix_nested` | 0 | 26.4s |  |
| 216 | `displayobject_set_name_loaded` | 3 | 7.0s |  |
| 217 | `displayobject_subclass` | 2 | 6.6s |  |
| 218 | `displayobject_visible` | 23 | 6.7s |  |
| 219 | `displayobject_width` | 4852 | 25.8s |  |
| 220 | `displayobject_x` | 614 | 6.6s |  |
| 221 | `displayobject_y` | 617 | 6.5s |  |
| 222 | `displayobjectcontainer_addchild` | 32 | 6.7s |  |
| 223 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.6s |  |
| 224 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.8s |  |
| 225 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.7s |  |
| 226 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.8s |  |
| 227 | `displayobjectcontainer_addchildat` | 42 | 6.6s |  |
| 228 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.7s |  |
| 229 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.7s |  |
| 230 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.7s |  |
| 231 | `displayobjectcontainer_contains` | 66 | 25.5s |  |
| 232 | `displayobjectcontainer_getchildat` | 4 | 6.6s |  |
| 233 | `displayobjectcontainer_getchildbyname` | 9 | 6.5s |  |
| 234 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.6s |  |
| 235 | `displayobjectcontainer_getchildindex` | 28 | 6.6s |  |
| 236 | `displayobjectcontainer_removechild` | 10 | 6.5s |  |
| 237 | `displayobjectcontainer_removechild_errors` | 4 | 6.5s |  |
| 238 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.7s |  |
| 239 | `displayobjectcontainer_removechildat` | 18 | 6.5s |  |
| 240 | `displayobjectcontainer_removechildren` | 51 | 6.9s |  |
| 241 | `displayobjectcontainer_setchildindex` | 42 | 6.4s |  |
| 242 | `displayobjectcontainer_stopallmovieclips` | 2 | 25.5s |  |
| 243 | `displayobjectcontainer_swapchildren` | 42 | 6.7s |  |
| 244 | `displayobjectcontainer_swapchildrenat` | 42 | 6.6s |  |
| 245 | `displayobjectcontainer_timelineinstance` | 48 | 23.9s |  |
| 246 | `divide` | 1058 | 16.7s |  |
| 247 | `doabc_is_eager` | 1 | 23.6s |  |
| 248 | `documentclass` | 9 | 5.9s |  |
| 249 | `domain_memory` | 133 | 24.8s |  |
| 250 | `drag_drop` | 10 | 6.0s |  |
| 251 | `duplicate_defs` | 1 | 5.6s |  |
| 252 | `eager_init` | 1 | 5.7s |  |
| 253 | `edit_text_linkage` | 7 | 5.9s |  |
| 254 | `edittext_align` | 60 | 6.2s |  |
| 255 | `edittext_always_show_selection` | 0 | 24.3s |  |
| 256 | `edittext_antialiastype` | 296 | 6.1s |  |
| 257 | `edittext_at_point_methods_basic` | 16 | 7.2s |  |
| 258 | `edittext_autosize` | 39 | 6.1s |  |
| 259 | `edittext_autosize_align` | 0 | 24.3s |  |
| 260 | `edittext_autosize_height_dynamic` | 60 | 24.4s |  |
| 261 | `edittext_autosize_height_input` | 60 | 5.8s |  |
| 262 | `edittext_autosize_lazy_bounds_events` | 65 | 6.1s |  |
| 263 | `edittext_autosize_lazy_bounds_interactions` | 19 | 5.8s |  |
| 264 | `edittext_autosize_lazy_bounds_props` | 490 | 7.1s |  |
| 265 | `edittext_autosize_lazy_bounds_visual` | 0 | 24.2s |  |
| 266 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.0s |  |
| 267 | `edittext_bottom_scroll_v_basic` | 210 | 6.0s |  |
| 268 | `edittext_bounds_scale` | 24 | 24.0s |  |
| 269 | `edittext_bullet` | 30 | 5.9s |  |
| 270 | `edittext_default_format` | 221 | 6.1s |  |
| 271 | `edittext_default_format_empty` | 136 | 6.1s |  |
| 272 | `edittext_empty_text_format` | 7 | 5.8s |  |
| 273 | `edittext_focus_selection` | 5 | 5.8s |  |
| 274 | `edittext_font_size` | 45 | 5.9s |  |
| 275 | `edittext_format_empty_font` | 8 | 5.8s |  |
| 276 | `edittext_get_char_index_at_point` | 4 | 25.2s |  |
| 277 | `edittext_get_line_index_at_point` | 2 | 24.4s |  |
| 278 | `edittext_get_line_index_of_char` | 76 | 6.8s |  |
| 279 | `edittext_getcharboundaries` | 172 | 6.2s |  |
| 280 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.7s |  |
| 281 | `edittext_getcharboundaries_scroll` | 85 | 24.9s |  |
| 282 | `edittext_getlinemetrics` | 146 | 6.6s |  |
| 283 | `edittext_html` | 3101 | 6.8s |  |
| 284 | `edittext_html_condensewhite` | 487 | 6.4s |  |
| 285 | `edittext_html_entity` | 4 | 6.6s |  |
| 286 | `edittext_html_font_size_swf12` | 267 | 6.5s |  |
| 287 | `edittext_html_font_size_swf13` | 273 | 6.3s |  |
| 288 | `edittext_html_roundtrip` | 17 | 6.5s |  |
| 289 | `edittext_ime_focus_lost` | 9 | 25.8s |  |
| 290 | `edittext_input_control` | 12 | 6.7s |  |
| 291 | `edittext_leading` | 9 | 6.7s |  |
| 292 | `edittext_letter_spacing` | 15 | 6.4s |  |
| 293 | `edittext_line_methods` | 294 | 7.7s |  |
| 294 | `edittext_line_metrics` | 11 | 27.0s |  |
| 295 | `edittext_margins` | 25 | 6.5s |  |
| 296 | `edittext_max_scroll_h_basic` | 475 | 6.6s |  |
| 297 | `edittext_max_scroll_v_basic` | 1000 | 6.5s |  |
| 298 | `edittext_mouse_selection` | 363 | 26.0s |  |
| 299 | `edittext_mousedown` | 3 | 6.8s |  |
| 300 | `edittext_mouseenabled` | 26 | 6.3s |  |
| 301 | `edittext_newline_character` | 22 | 6.3s |  |
| 302 | `edittext_newline_stripping` | 64 | 8.9s |  |
| 303 | `edittext_newlines` | 30 | 6.3s |  |
| 304 | `edittext_paragraph_methods` | 257 | 6.3s |  |
| 305 | `edittext_paste_events` | 8 | 6.5s |  |
| 306 | `edittext_paste_maxchars` | 4 | 6.4s |  |
| 307 | `edittext_paste_restrict` | 16 | 6.2s |  |
| 308 | `edittext_restrict` | 191 | 6.3s |  |
| 309 | `edittext_restrict_events` | 22 | 6.3s |  |
| 310 | `edittext_scrollh` | 10 | 6.3s |  |
| 311 | `edittext_selected_text` | 9 | 6.4s |  |
| 312 | `edittext_set_html_same` | 17 | 6.4s |  |
| 313 | `edittext_set_text_vs_html` | 9 | 6.4s |  |
| 314 | `edittext_stylesheet` | 536 | 6.8s |  |
| 315 | `edittext_stylesheet_custom_tag` | 76 | 6.3s |  |
| 316 | `edittext_stylesheet_display` | 272 | 6.4s |  |
| 317 | `edittext_underline` | 40 | 6.4s |  |
| 318 | `edittext_width_height` | 103 | 19.6s |  |
| 319 | `edittext_wordwrap_word` | 150 | 25.6s |  |
| 320 | `edittext_wrap_breaks` | 2375 | 7.2s |  |
| 321 | `empty_bounds` | 1 | 6.5s |  |
| 322 | `encode_uri_surrogate_pair_swf11` | 15 | 6.3s |  |
| 323 | `equals` | 512 | 10.2s |  |
| 324 | `error_geterrormessage` | 779 | 6.6s |  |
| 325 | `error_prototype` | 15 | 6.6s |  |
| 326 | `error_stack_trace_debug_swf17` | 0 | 25.6s |  |
| 327 | `error_stack_trace_debug_swf18` | 0 | 6.3s |  |
| 328 | `error_stack_trace_release_swf17` | 0 | 6.3s |  |
| 329 | `error_stack_trace_release_swf18` | 0 | 6.2s |  |
| 330 | `error_tostring` | 29 | 6.5s |  |
| 331 | `es3_inheritance` | 31 | 6.6s |  |
| 332 | `es4_inheritance` | 30 | 6.6s |  |
| 333 | `es4_interfaces` | 30 | 6.6s |  |
| 334 | `es4_method_binding` | 8 | 6.6s |  |
| 335 | `es4_oop_prototypes` | 14 | 6.7s |  |
| 336 | `es4_protected_inheritance` | 6 | 6.5s |  |
| 337 | `escape` | 71 | 6.6s |  |
| 338 | `event_bubbles` | 2 | 6.5s |  |
| 339 | `event_cancelable` | 2 | 6.4s |  |
| 340 | `event_clone` | 20 | 6.5s |  |
| 341 | `event_clone_error_redispatch` | 3 | 6.6s |  |
| 342 | `event_clone_on_redispatch` | 10 | 6.7s |  |
| 343 | `event_formattostring` | 31 | 6.6s |  |
| 344 | `event_isdefaultprevented` | 12 | 6.5s |  |
| 345 | `event_target_getter` | 5 | 3.1s |  |
| 346 | `event_target_set` | 9 | 6.5s |  |
| 347 | `event_type` | 1 | 18.6s |  |
| 348 | `event_valueof_tostring` | 18 | 6.2s |  |
| 349 | `eventdispatcher_dispatchevent` | 12 | 6.2s |  |
| 350 | `eventdispatcher_dispatchevent_cancel` | 20 | 24.4s |  |
| 351 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.3s |  |
| 352 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.3s |  |
| 353 | `eventdispatcher_dispatchevent_this` | 5 | 6.2s |  |
| 354 | `eventdispatcher_haseventlistener` | 25 | 6.3s |  |
| 355 | `eventdispatcher_interface_invoke` | 1 | 6.2s |  |
| 356 | `eventdispatcher_tostring` | 10 | 6.3s |  |
| 357 | `eventdispatcher_willtrigger` | 25 | 6.1s |  |
| 358 | `falsiness` | 30 | 6.3s |  |
| 359 | `fast_index_access` | 12 | 6.4s |  |
| 360 | `finddef` | 3 | 6.2s |  |
| 361 | `findprop_global_prototype` | 6 | 6.2s |  |
| 362 | `flash_xml` | 29 | 6.3s |  |
| 363 | `flash_xml_cloneNode` | 22 | 6.3s |  |
| 364 | `flash_xml_namespace` | 109 | 6.2s |  |
| 365 | `flash_xml_removeNode` | 60 | 6.2s |  |
| 366 | `focus_events_code` | 161 | 24.8s |  |
| 367 | `focus_events_key_basic` | 132 | 24.9s |  |
| 368 | `focus_events_key_navigation` | 53 | 6.4s |  |
| 369 | `focus_events_key_same_object` | 26 | 6.2s |  |
| 370 | `focus_events_mixed_key_mouse` | 100 | 24.5s |  |
| 371 | `focus_events_mouse_basic` | 260 | 37.9s |  |
| 372 | `focus_events_mouse_focusable` | 112 | 25.8s |  |
| 373 | `focus_events_mouse_same_object` | 40 | 25.3s |  |
| 374 | `focus_remove` | 20 | 25.3s |  |
| 375 | `focus_root_movie` | 4 | 26.9s |  |
| 376 | `focus_stage` | 1 | 6.3s |  |
| 377 | `focusrect` | 18 | 7.1s |  |
| 378 | `focusrect_focuslost` | 9 | 6.4s |  |
| 379 | `focusrect_property` | 110 | 25.2s |  |
| 380 | `font_description_clone` | 14 | 6.4s |  |
| 381 | `font_embedded` | 24 | 25.6s |  |
| 382 | `font_enumeratefonts` | 41 | 7.1s |  |
| 383 | `font_enumeratefonts_filter` | 4 | 25.7s |  |
| 384 | `font_hasglyphs` | 40 | 6.8s |  |
| 385 | `framelabel_constr` | 5 | 6.6s |  |
| 386 | `function_call` | 12 | 6.5s |  |
| 387 | `function_call_arguments` | 46 | 6.6s |  |
| 388 | `function_call_arguments_enumerate` | 5 | 6.5s |  |
| 389 | `function_call_coercion` | 108 | 7.0s |  |
| 390 | `function_call_default` | 6 | 6.5s |  |
| 391 | `function_call_rest` | 22 | 6.5s |  |
| 392 | `function_call_types` | 3 | 6.5s |  |
| 393 | `function_call_via_apply` | 11 | 6.5s |  |
| 394 | `function_call_via_call` | 3 | 6.5s |  |
| 395 | `function_display_anonymous` | 7 | 3.1s |  |
| 396 | `function_length` | 6 | 6.6s |  |
| 397 | `function_object` | 2 | 6.5s |  |
| 398 | `function_proto` | 5 | 6.5s |  |
| 399 | `function_proto_created` | 61 | 6.5s |  |
| 400 | `function_to_locale_string` | 4 | 6.4s |  |
| 401 | `function_to_string` | 4 | 6.4s |  |
| 402 | `function_type` | 6 | 6.5s |  |
| 403 | `function_unbound_this` | 51 | 6.6s |  |
| 404 | `function_value_of` | 4 | 6.4s |  |
| 405 | `get_definition_by_name` | 11 | 6.4s |  |
| 406 | `get_qualified_class_name` | 20 | 19.1s |  |
| 407 | `get_qualified_super_class_name` | 18 | 6.4s |  |
| 408 | `get_slot_edge_cases` | 1 | 25.6s |  |
| 409 | `get_timer` | 2 | 6.5s |  |
| 410 | `getglobalslot` | 1 | 6.5s |  |
| 411 | `getouterscope` | 8 | 6.3s |  |
| 412 | `getter_different_namespace_setter` | 2 | 6.2s |  |
| 413 | `goto_button_nested_framescript` | 28 | 25.6s |  |
| 414 | `goto_in_constructframe` | 12 | 25.3s |  |
| 415 | `goto_in_scene_last_frame` | 2 | 25.2s |  |
| 416 | `goto_methods` | 56 | 6.6s |  |
| 417 | `goto_methods_swfver10` | 8 | 6.4s |  |
| 418 | `goto_nested_construct_sibling` | 18 | 7.0s |  |
| 419 | `goto_nested_framescript` | 9 | 6.6s |  |
| 420 | `goto_on_orphan` | 15 | 6.6s |  |
| 421 | `graphics_bad_direct_commands` | 5 | 8.8s |  |
| 422 | `graphics_bitmap_fill` | 0 | 27.9s |  |
| 423 | `graphics_bitmaps` | 0 | 7.4s |  |
| 424 | `graphics_direct_commands` | 0 | 7.2s |  |
| 425 | `graphics_draw_triangles` | 98 | 26.8s |  |
| 426 | `graphics_gradients` | 0 | 7.0s |  |
| 427 | `graphics_gradients_nulls` | 0 | 6.7s |  |
| 428 | `graphics_path` | 56 | 6.6s |  |
| 429 | `graphics_round_rects` | 0 | 6.6s |  |
| 430 | `graphics_simple_shapes` | 0 | 6.9s |  |
| 431 | `greaterequals` | 512 | 10.8s |  |
| 432 | `greaterthan` | 512 | 11.1s |  |
| 433 | `has_own_property` | 102 | 7.1s |  |
| 434 | `hasownproperty_namespaces` | 2 | 6.6s |  |
| 435 | `hello_world` | 1 | 6.5s |  |
| 436 | `hittest_morph` | 30 | 6.7s |  |
| 437 | `if_eq` | 10 | 6.6s |  |
| 438 | `if_gt` | 1 | 6.7s |  |
| 439 | `if_gte` | 10 | 19.6s |  |
| 440 | `if_lt` | 1 | 6.7s |  |
| 441 | `if_lte` | 10 | 6.5s |  |
| 442 | `if_ne` | 7 | 3.2s |  |
| 443 | `if_stricteq` | 6 | 6.7s |  |
| 444 | `if_strictne` | 11 | 6.7s |  |
| 445 | `ime_linux_dead_keys` | 10 | 26.4s |  |
| 446 | `in` | 102 | 7.1s |  |
| 447 | `inclocal` | 46 | 6.7s |  |
| 448 | `inclocal_i` | 46 | 6.7s |  |
| 449 | `increment` | 46 | 6.6s |  |
| 450 | `increment_i` | 46 | 6.7s |  |
| 451 | `indexing_delete` | 75 | 6.6s |  |
| 452 | `instanceof` | 58 | 6.9s |  |
| 453 | `instantiation_on_enter_frame` | 7 | 26.2s |  |
| 454 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.6s |  |
| 455 | `int_constr` | 92 | 6.5s |  |
| 456 | `int_edge_cases` | 19 | 6.7s |  |
| 457 | `int_instanceof` | 3 | 6.5s |  |
| 458 | `int_tofixed` | 1215 | 6.5s |  |
| 459 | `int_tostring` | 3375 | 6.6s |  |
| 460 | `interactiveobject_enabled` | 25 | 6.5s |  |
| 461 | `interface_namespaces` | 78 | 6.8s |  |
| 462 | `is_finite` | 46 | 6.7s |  |
| 463 | `is_nan` | 46 | 6.5s |  |
| 464 | `is_prototype_of` | 12 | 6.7s |  |
| 465 | `issue_10221` | 2 | 6.7s |  |
| 466 | `issue_13780` | 12 | 6.7s |  |
| 467 | `issue_14901` | 1 | 6.7s |  |
| 468 | `issue_17675_edittext_paste_maxchars` | 1 | 6.7s |  |
| 469 | `issue_5292` | 5 | 6.7s |  |
| 470 | `issue_8630` | 2 | 26.3s |  |
| 471 | `issue_8630_scriptremove` | 11 | 6.6s |  |
| 472 | `istype` | 24 | 3.2s |  |
| 473 | `istypelate` | 58 | 7.0s |  |
| 474 | `istypelate_coerce` | 198 | 20.1s |  |
| 475 | `jpeg_loader_context` | 6 | 25.6s |  |
| 476 | `json_errors` | 9 | 25.1s |  |
| 477 | `json_parse` | 21 | 6.4s |  |
| 478 | `json_stringify` | 12 | 6.8s |  |
| 479 | `json_stringify_order` | 1 | 6.4s |  |
| 480 | `json_version_gated` | 1 | 6.3s |  |
| 481 | `key_input_80percent` | 1812 | 6.7s |  |
| 482 | `key_input_location` | 126 | 6.5s |  |
| 483 | `key_input_numpad` | 384 | 6.4s |  |
| 484 | `lazyinit` | 17 | 6.5s |  |
| 485 | `lessequals` | 512 | 10.7s |  |
| 486 | `lessthan` | 512 | 10.5s |  |
| 487 | `loader_bitmap_transparency` | 14 | 6.6s |  |
| 488 | `loader_bytes_unknown_content` | 14 | 6.6s |  |
| 489 | `loader_child_getdefinition` | 5 | 6.7s |  |
| 490 | `loader_duplicate_coerce` | 3 | 6.8s |  |
| 491 | `loader_duplicate_coerce_new_domain` | 4 | 6.6s |  |
| 492 | `loader_error_in_root_ctor` | 4 | 6.7s |  |
| 493 | `loader_events` | 92 | 8.9s |  |
| 494 | `loader_image` | 8 | 6.9s |  |
| 495 | `loader_jpegxr` | 2 | 25.6s |  |
| 496 | `loader_jpegxr_alpha` | 1 | 25.3s |  |
| 497 | `loader_loadbytes_events` | 30 | 7.0s |  |
| 498 | `loader_loadbytes_invalid_png` | 4 | 24.6s |  |
| 499 | `loader_loadbytes_url` | 12 | 6.8s |  |
| 500 | `loader_loaderurl` | 6 | 7.0s |  |
| 501 | `loader_noninteractive_try_click_root` | 5 | 25.7s |  |
| 502 | `loader_reuse` | 38 | 6.7s |  |
| 503 | `loader_unknown_content` | 24 | 6.6s |  |
| 504 | `loader_visibility_interactive` | 1 | 6.5s |  |
| 505 | `loaderinfo_events` | 7 | 6.4s |  |
| 506 | `loaderinfo_loadurl` | 12 | 36.5s |  |
| 507 | `loaderinfo_more` | 6 | 24.5s |  |
| 508 | `loaderinfo_properties` | 18 | 5.9s |  |
| 509 | `loaderinfo_properties_not_loaded` | 23 | 6.0s |  |
| 510 | `loaderinfo_root` | 10 | 5.9s |  |
| 511 | `loaderinfo_root_allows` | 2 | 5.8s |  |
| 512 | `lshift` | 1058 | 15.3s |  |
| 513 | `mask_reapply` | 1 | 5.9s |  |
| 514 | `math` | 497 | 6.1s |  |
| 515 | `missing_external_interface` | 10 | 5.8s |  |
| 516 | `modulo` | 1058 | 15.1s |  |
| 517 | `morph_shape` | 2 | 24.1s |  |
| 518 | `mouse_children` | 192 | 24.4s |  |
| 519 | `mouse_click_events` | 90 | 24.0s |  |
| 520 | `mouse_double_click_events` | 188 | 5.8s |  |
| 521 | `mouse_empty_parent` | 4 | 5.8s |  |
| 522 | `mouse_over_while_dragging` | 3 | 5.9s |  |
| 523 | `mouse_pick_button_mode` | 2 | 5.9s |  |
| 524 | `mouse_pick_dobj_mask` | 4 | 6.1s |  |
| 525 | `mouse_pick_masking` | 7 | 24.0s |  |
| 526 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 24.2s |  |
| 527 | `mouse_pick_non_interactive_dobj_mask` | 3 | 6.2s |  |
| 528 | `mouse_pick_text` | 8 | 6.1s |  |
| 529 | `mouse_sibling` | 8 | 5.9s |  |
| 530 | `mouse_wheel_events` | 36 | 25.3s |  |
| 531 | `mouseevent_constr` | 66 | 5.8s |  |
| 532 | `mouseevent_stagexy` | 35 | 5.9s |  |
| 533 | `mouseevent_valueof_tostring` | 28 | 5.9s |  |
| 534 | `movieclip_addframescript` | 3 | 24.2s |  |
| 535 | `movieclip_child_property` | 16 | 5.9s |  |
| 536 | `movieclip_constr` | 21 | 19.5s |  |
| 537 | `movieclip_currentlabels` | 17 | 25.6s |  |
| 538 | `movieclip_currentlabels_dupes1` | 46 | 25.6s |  |
| 539 | `movieclip_currentlabels_dupes2` | 30 | 6.8s |  |
| 540 | `movieclip_currentlabels_dupes3` | 67 | 6.7s |  |
| 541 | `movieclip_currentscene` | 12 | 25.8s |  |
| 542 | `movieclip_dispatchevent` | 430 | 6.7s |  |
| 543 | `movieclip_dispatchevent_cancel` | 102 | 6.8s |  |
| 544 | `movieclip_dispatchevent_handlerorder` | 251 | 6.6s |  |
| 545 | `movieclip_dispatchevent_selfadd` | 80 | 6.6s |  |
| 546 | `movieclip_dispatchevent_target` | 899 | 6.7s |  |
| 547 | `movieclip_displayevents` | 96 | 25.7s |  |
| 548 | `movieclip_displayevents_clickgoto` | 676 | 25.8s |  |
| 549 | `movieclip_displayevents_clickgoto2` | 2001 | 7.2s |  |
| 550 | `movieclip_displayevents_clickplay` | 575 | 6.8s |  |
| 551 | `movieclip_displayevents_clicksymbol` | 562 | 6.8s |  |
| 552 | `movieclip_displayevents_constructframegoto` | 140 | 7.0s |  |
| 553 | `movieclip_displayevents_constructframeplay` | 50 | 6.9s |  |
| 554 | `movieclip_displayevents_constructframesymbol` | 144 | 6.8s |  |
| 555 | `movieclip_displayevents_dblhandler` | 21 | 6.8s |  |
| 556 | `movieclip_displayevents_enterframegoto` | 149 | 6.9s |  |
| 557 | `movieclip_displayevents_enterframeplay` | 48 | 6.7s |  |
| 558 | `movieclip_displayevents_enterframesymbol` | 149 | 25.8s |  |
| 559 | `movieclip_displayevents_exitframegoto` | 106 | 6.8s |  |
| 560 | `movieclip_displayevents_exitframeplay` | 44 | 6.7s |  |
| 561 | `movieclip_displayevents_exitframesymbol` | 135 | 6.8s |  |
| 562 | `movieclip_displayevents_looping` | 63 | 26.1s |  |
| 563 | `movieclip_displayevents_stopped` | 113 | 7.1s |  |
| 564 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 565 | `movieclip_displayevents_timeline` | 128 | 25.7s |  |
| 566 | `movieclip_drawrect` | 54 | 6.6s |  |
| 567 | `movieclip_frameconstruct_skipped` | 9 | 6.7s |  |
| 568 | `movieclip_goto_during_frame_script` | 15 | 6.6s |  |
| 569 | `movieclip_goto_overwrite` | 14 | 25.3s |  |
| 570 | `movieclip_goto_scene_last_frame_int` | 1 | 25.6s |  |
| 571 | `movieclip_goto_scene_last_frame_label` | 1 | 6.5s |  |
| 572 | `movieclip_gotoandplay` | 15 | 25.3s |  |
| 573 | `movieclip_gotoandstop` | 13 | 6.6s |  |
| 574 | `movieclip_gotoandstop_children` | 4 | 6.7s |  |
| 575 | `movieclip_gotoandstop_framescripts1` | 4 | 6.6s |  |
| 576 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 577 | `movieclip_gotoandstop_framescripts_self` | 7 | 29.9s |  |
| 578 | `movieclip_gotoandstop_queueing` | 12 | 19.7s |  |
| 579 | `movieclip_next_frame` | 2 | 19.9s |  |
| 580 | `movieclip_next_scene` | 6 | 19.7s |  |
| 581 | `movieclip_play` | 3 | 5.0s |  |
| 582 | `movieclip_prev_frame` | 3 | 5.0s |  |
| 583 | `movieclip_prev_scene` | 7 | 5.2s |  |
| 584 | `movieclip_properties` | 79 | 19.8s |  |
| 585 | `movieclip_queued_noop_goto_swf10` | 9 | 5.1s |  |
| 586 | `movieclip_queued_noop_goto_swf9` | 7 | 1.0s |  |
| 587 | `movieclip_scenes` | 11 | 5.0s |  |
| 588 | `movieclip_soundtransform` | 831 | 21.4s |  |
| 589 | `movieclip_stop` | 1 | 19.4s |  |
| 590 | `movieclip_super_is_symbol` | 20 | 5.3s |  |
| 591 | `movieclip_symbol_constr` | 8 | 5.2s |  |
| 592 | `movieclip_text_mousedown` | 1 | 5.2s |  |
| 593 | `movieclip_willtrigger` | 5 | 5.2s |  |
| 594 | `multiply` | 1058 | 13.9s |  |
| 595 | `namespace_constr` | 253 | 5.3s |  |
| 596 | `namespace_constr_args` | 1 | 5.0s |  |
| 597 | `namespace_enumeration_order` | 7 | 19.8s |  |
| 598 | `nan_scale` | 9 | 5.0s |  |
| 599 | `navigateToURL_target_normalize` | 107 | 20.5s |  |
| 600 | `negate` | 30 | 5.1s |  |
| 601 | `negative_volume_panned` | 0 | 5.3s |  |
| 602 | `nested_iteration` | 11 | 5.1s |  |
| 603 | `net_getClassByAlias` | 3 | 5.1s |  |
| 604 | `net_navigateToURL` | 57 | 5.2s |  |
| 605 | `net_stream_play_options` | 6 | 5.1s |  |
| 606 | `netconnection_close` | 55 | 5.2s |  |
| 607 | `netconnection_properties` | 78 | 5.2s |  |
| 608 | `netstream_client` | 10 | 5.2s |  |
| 609 | `netstream_connect` | 7 | 5.2s |  |
| 610 | `newactivation_in_script_init` | 3 | 6.8s |  |
| 611 | `newclass_twice` | 3 | 6.6s |  |
| 612 | `nonconflicting_declarations` | 0 | 6.8s |  |
| 613 | `null_void_types` | 8 | 6.7s |  |
| 614 | `number_autoconv` | 21 | 26.3s |  |
| 615 | `number_autoconv_amf` | 132 | 6.6s |  |
| 616 | `number_autoconv_array_sort_32bit` | 1 | 6.5s |  |
| 617 | `number_constr` | 58 | 6.7s |  |
| 618 | `number_toexponential` | 378 | 6.6s |  |
| 619 | `number_toexponential2` | 35 | 6.5s |  |
| 620 | `number_tofixed` | 378 | 6.5s |  |
| 621 | `number_toprecision` | 350 | 6.6s |  |
| 622 | `obfuscated_class_names` | 3 | 6.5s |  |
| 623 | `object_enumeration` | 10 | 6.6s |  |
| 624 | `object_prototype` | 4 | 6.6s |  |
| 625 | `object_to_locale_string` | 2 | 6.5s |  |
| 626 | `object_to_string` | 2 | 6.5s |  |
| 627 | `object_value_of` | 2 | 3.0s |  |
| 628 | `op_coerce` | 54 | 6.7s |  |
| 629 | `op_coerce_x` | 54 | 6.7s |  |
| 630 | `op_escxattr` | 2 | 6.6s |  |
| 631 | `op_escxelem` | 2 | 6.6s |  |
| 632 | `op_lookupswitch` | 4 | 6.6s |  |
| 633 | `optimize_coerce` | 1 | 6.6s |  |
| 634 | `orphan_movie_complex` | 80 | 7.2s |  |
| 635 | `orphan_movie_reorder` | 111 | 27.2s |  |
| 636 | `package_namespace` | 7 | 6.5s |  |
| 637 | `param_default_value_has_zero_cpool_index` | 1 | 6.5s |  |
| 638 | `parent_early_access_child` | 16 | 26.3s |  |
| 639 | `parse_float` | 81 | 6.8s |  |
| 640 | `pixelbender_effect_BlurredFocus` | 0 | 29.6s |  |
| 641 | `pixelbender_effect_glassDisplace` | 0 | 12.2s |  |
| 642 | `pixelbender_effect_smudge` | 0 | 9.9s |  |
| 643 | `pixelbender_effect_tintype` | 0 | 9.2s |  |
| 644 | `pixelbender_effect_twirl` | 0 | 10.2s |  |
| 645 | `pixelbender_images` | 0 | 8.6s |  |
| 646 | `place_multiple` | 17 | 25.0s |  |
| 647 | `place_object_replace` | 9 | 6.7s |  |
| 648 | `place_object_replace_2` | 24 | 6.7s |  |
| 649 | `place_object_same_depth_frame` | 1 | 6.5s |  |
| 650 | `point` | 132 | 7.0s |  |
| 651 | `primitive_edge_cases` | 1 | 6.2s |  |
| 652 | `property_priority` | 22 | 5.3s |  |
| 653 | `property_priority_three_level` | 6 | 19.6s |  |
| 654 | `propertyisenumerable_namespaces` | 6 | 5.0s |  |
| 655 | `prototype_set_null` | 7 | 5.0s |  |
| 656 | `proxy_callproperty` | 24 | 5.1s |  |
| 657 | `proxy_deleteproperty` | 64 | 5.2s |  |
| 658 | `proxy_enumeration` | 34 | 5.1s |  |
| 659 | `proxy_getproperty` | 77 | 5.1s |  |
| 660 | `proxy_hasownproperty` | 8 | 5.0s |  |
| 661 | `proxy_hasproperty` | 32 | 5.1s |  |
| 662 | `proxy_serialize` | 9 | 5.1s |  |
| 663 | `proxy_setproperty` | 42 | 5.2s |  |
| 664 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.0s |  |
| 665 | `qname_constr` | 32 | 5.1s |  |
| 666 | `qname_constr_namespace` | 24 | 5.1s |  |
| 667 | `qname_enumeration` | 9 | 5.2s |  |
| 668 | `qname_indexing` | 23 | 5.2s |  |
| 669 | `qname_tostring` | 25 | 5.3s |  |
| 670 | `qname_valueof` | 29 | 5.1s |  |
| 671 | `regexp_constr` | 148 | 5.3s |  |
| 672 | `regexp_exec` | 19 | 5.1s |  |
| 673 | `regexp_extended` | 47 | 5.0s |  |
| 674 | `regexp_multiargs` | 1 | 5.0s |  |
| 675 | `regexp_test` | 27 | 5.1s |  |
| 676 | `regexp_toString` | 10 | 5.1s |  |
| 677 | `register_script_refresh` | 35 | 5.7s |  |
| 678 | `remove_child_clear_field` | 88 | 20.1s |  |
| 679 | `remove_dobj` | 3 | 5.0s |  |
| 680 | `resolve_order` | 4 | 6.0s |  |
| 681 | `responder_null_callbacks` | 1 | 5.3s |  |
| 682 | `rng` | 1 | 6.2s |  |
| 683 | `rootless` | 42 | 5.2s |  |
| 684 | `rshift` | 1058 | 14.1s |  |
| 685 | `sandbox_type_inherited` | 2 | 19.7s |  |
| 686 | `sandbox_type_local_file` | 1 | 26.1s |  |
| 687 | `sandbox_type_local_network` | 1 | 6.6s |  |
| 688 | `scene_constr` | 8 | 7.0s |  |
| 689 | `selection` | 239 | 7.0s |  |
| 690 | `set_local_0` | 31 | 6.6s |  |
| 691 | `set_property_is_enumerable` | 85 | 7.0s |  |
| 692 | `shape_drawrect` | 54 | 6.6s |  |
| 693 | `shared_object_no_root` | 3 | 6.5s |  |
| 694 | `simplebutton_added_to_stage` | 45 | 25.1s |  |
| 695 | `simplebutton_childevents` | 86 | 25.4s |  |
| 696 | `simplebutton_childevents_nested` | 54 | 6.9s |  |
| 697 | `simplebutton_childevents_sprite` | 13 | 6.6s |  |
| 698 | `simplebutton_childprops` | 144 | 6.8s |  |
| 699 | `simplebutton_childshuffle` | 23 | 6.5s |  |
| 700 | `simplebutton_constr` | 36 | 6.8s |  |
| 701 | `simplebutton_constr_childevents` | 48 | 6.9s |  |
| 702 | `simplebutton_constr_params` | 42 | 6.7s |  |
| 703 | `simplebutton_mouseenabled` | 26 | 6.6s |  |
| 704 | `simplebutton_multi_children` | 19 | 6.8s |  |
| 705 | `simplebutton_structure` | 27 | 6.8s |  |
| 706 | `simplebutton_symbolclass` | 68 | 7.1s |  |
| 707 | `slot_disp_id_shared_numbering` | 1 | 24.9s |  |
| 708 | `slots_force_autoassigned` | 1 | 6.6s |  |
| 709 | `socket_after_disconnect` | 1 | 6.7s |  |
| 710 | `socket_close` | 2 | 6.5s |  |
| 711 | `socket_connect` | 4 | 6.6s |  |
| 712 | `socket_errors` | 56 | 7.0s |  |
| 713 | `socket_read_big` | 48 | 38.8s |  |
| 714 | `socket_read_little` | 48 | 3.0s |  |
| 715 | `socket_read_write_object` | 8 | 6.5s |  |
| 716 | `socket_write_big` | 15 | 6.8s |  |
| 717 | `socket_write_little` | 14 | 6.5s |  |
| 718 | `sound_embeddedprops` | 26 | 7.0s |  |
| 719 | `sound_play` | 19 | 6.8s |  |
| 720 | `sound_valueof` | 33 | 6.7s |  |
| 721 | `soundchannel_soundtransform` | 835 | 28.0s |  |
| 722 | `soundchannel_soundtransform_exists` | 5 | 25.6s |  |
| 723 | `soundchannel_stop` | 8 | 26.2s |  |
| 724 | `soundmixer_buffertime` | 5 | 6.6s |  |
| 725 | `soundmixer_stopall` | 6 | 26.1s |  |
| 726 | `soundtransform` | 442 | 12.5s |  |
| 727 | `sprite_with_frames` | 0 | 28.3s |  |
| 728 | `stage3d_agal_cross_product` | 0 | 9.4s |  |
| 729 | `stage3d_bitmap` | 0 | 31.4s |  |
| 730 | `stage3d_float1_index` | 0 | 28.8s |  |
| 731 | `stage3d_fractal` | 0 | 29.4s |  |
| 732 | `stage3d_ignore_sampler_override` | 0 | 29.1s |  |
| 733 | `stage3d_program_constants_bytearray_be` | 0 | 30.3s |  |
| 734 | `stage3d_program_constants_bytearray_le` | 0 | 10.1s |  |
| 735 | `stage3d_raytrace` | 0 | 32.4s |  |
| 736 | `stage3d_rotating_cube` | 0 | 10.6s |  |
| 737 | `stage3d_sampler` | 0 | 23.0s |  |
| 738 | `stage3d_sampler_partial_upload` | 0 | 9.0s |  |
| 739 | `stage3d_stencil` | 0 | 28.3s |  |
| 740 | `stage3d_texture` | 0 | 14.0s |  |
| 741 | `stage3d_texture_bytearray` | 0 | 10.3s |  |
| 742 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.7s |  |
| 743 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.9s |  |
| 744 | `stage3d_triangle` | 0 | 9.2s |  |
| 745 | `stage3d_triangle_bytes4` | 0 | 9.1s |  |
| 746 | `stage3d_triangle_float1` | 0 | 9.0s |  |
| 747 | `stage3d_triangle_index_upload` | 0 | 9.0s |  |
| 748 | `stage_access` | 10 | 6.3s |  |
| 749 | `stage_displayobject_properties` | 24 | 6.3s |  |
| 750 | `stage_framerate_nan` | 7 | 24.7s |  |
| 751 | `stage_framerate_negative` | 6 | 6.3s |  |
| 752 | `stage_framerate_zero` | 6 | 6.3s |  |
| 753 | `stage_invalidate` | 38 | 6.5s |  |
| 754 | `stage_loaderinfo_properties` | 24 | 24.7s |  |
| 755 | `stage_mousechildren` | 2 | 6.2s |  |
| 756 | `stage_mouseenabled` | 15 | 6.3s |  |
| 757 | `stage_overriden_setters` | 31 | 6.4s |  |
| 758 | `stage_properties` | 30 | 6.2s |  |
| 759 | `static_var_with_this_in_ctor` | 2 | 6.2s |  |
| 760 | `stored_properties` | 11 | 6.3s |  |
| 761 | `strict_equality` | 34 | 6.3s |  |
| 762 | `string_call` | 13 | 6.3s |  |
| 763 | `string_case` | 23 | 6.3s |  |
| 764 | `string_char_at` | 27 | 6.3s |  |
| 765 | `string_char_code_at` | 28 | 6.2s |  |
| 766 | `string_concat_fromcharcode` | 37 | 6.1s |  |
| 767 | `string_constr` | 25 | 6.3s |  |
| 768 | `string_indexof_lastindexof` | 87 | 38.4s |  |
| 769 | `string_length` | 16 | 25.9s |  |
| 770 | `string_locale_compare` | 39 | 7.2s |  |
| 771 | `string_match` | 51 | 7.2s |  |
| 772 | `string_relational_compare` | 4 | 26.7s |  |
| 773 | `string_replace` | 51 | 7.0s |  |
| 774 | `string_search` | 41 | 6.9s |  |
| 775 | `string_slice_substr_substring` | 170 | 8.0s |  |
| 776 | `string_split` | 29 | 6.6s |  |
| 777 | `string_substr_negative` | 21 | 6.4s |  |
| 778 | `string_substr_weird` | 182 | 6.4s |  |
| 779 | `subtract` | 1058 | 18.9s |  |
| 780 | `super_get_call` | 12 | 6.5s |  |
| 781 | `supercall_two_classobjects` | 2 | 6.5s |  |
| 782 | `swf8` | 1 | 6.4s |  |
| 783 | `swf_10_queued_goto_scripts_construct` | 52 | 25.8s |  |
| 784 | `swf_9_goto_in_enter_frame` | 17 | 6.5s |  |
| 785 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.5s |  |
| 786 | `swf_9_queued_goto_scripts` | 6 | 25.7s |  |
| 787 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 788 | `swf_9_versioning` | 2 | 6.5s |  |
| 789 | `swf_wrong_frame_count` | 38 | 6.8s |  |
| 790 | `swf_wrong_frame_count_isplaying` | 22 | 6.5s |  |
| 791 | `symbol_class_binary_data` | 8 | 6.5s |  |
| 792 | `symbol_class_conflict` | 4 | 8.4s |  |
| 793 | `symbol_class_root_not_zero` | 1 | 6.4s |  |
| 794 | `symbolclass_invalid_utf8` | 2 | 6.5s |  |
| 795 | `tab_ordering_automatic_advanced` | 184 | 7.4s |  |
| 796 | `tab_ordering_automatic_basic` | 45 | 25.9s |  |
| 797 | `tab_ordering_children` | 116 | 6.7s |  |
| 798 | `tab_ordering_custom_basic` | 34 | 6.6s |  |
| 799 | `tab_ordering_stage_tab_children` | 32 | 6.6s |  |
| 800 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.5s |  |
| 801 | `tab_ordering_tabbable` | 47 | 6.7s |  |
| 802 | `text_engine_fontdescription` | 27 | 6.8s |  |
| 803 | `text_run` | 7 | 6.6s |  |
| 804 | `textbox_click` | 37 | 26.6s |  |
| 805 | `textfield_event` | 66 | 6.9s |  |
| 806 | `textfield_focusin_event` | 9 | 6.7s |  |
| 807 | `textfield_input_dead_keys_windows` | 15 | 6.7s |  |
| 808 | `textfield_unload` | 39 | 26.6s |  |
| 809 | `textformat` | 1134 | 6.8s |  |
| 810 | `textformat_display` | 14 | 6.7s |  |
| 811 | `textformat_font_max_length` | 4 | 6.7s |  |
| 812 | `throw` | 3 | 6.6s |  |
| 813 | `timeline_scripts` | 3 | 6.7s |  |
| 814 | `timer` | 90 | 7.7s |  |
| 815 | `timer_events` | 3 | 6.8s |  |
| 816 | `timer_finished` | 11 | 6.9s |  |
| 817 | `timer_reset` | 8 | 6.9s |  |
| 818 | `timer_setdelay` | 5 | 6.8s |  |
| 819 | `trace` | 12 | 6.6s |  |
| 820 | `truthiness` | 30 | 18.1s |  |
| 821 | `try_catch` | 11 | 5.4s |  |
| 822 | `try_catch_typed` | 12 | 5.4s |  |
| 823 | `typeof` | 30 | 5.4s |  |
| 824 | `uint_constr` | 92 | 5.4s |  |
| 825 | `uint_tofixed` | 1215 | 5.4s |  |
| 826 | `uint_tostring` | 3375 | 5.5s |  |
| 827 | `unchecked_function` | 15 | 5.5s |  |
| 828 | `unescape` | 28 | 5.4s |  |
| 829 | `url_loader` | 25 | 5.4s |  |
| 830 | `urlrequest` | 18 | 24.2s |  |
| 831 | `urshift` | 1058 | 5.5s |  |
| 832 | `vector_class` | 36 | 5.4s |  |
| 833 | `vector_class_call` | 11 | 5.5s |  |
| 834 | `vector_coercion` | 66 | 5.4s |  |
| 835 | `vector_concat` | 90 | 5.4s |  |
| 836 | `vector_constr` | 107 | 5.4s |  |
| 837 | `vector_enumeration` | 5 | 5.4s |  |
| 838 | `vector_every` | 92 | 5.4s |  |
| 839 | `vector_filter` | 95 | 5.4s |  |
| 840 | `vector_holes` | 24 | 5.4s |  |
| 841 | `vector_indexof` | 302 | 5.4s |  |
| 842 | `vector_insertat` | 270 | 5.4s |  |
| 843 | `vector_int_access` | 4 | 5.4s |  |
| 844 | `vector_int_delete` | 11 | 5.4s |  |
| 845 | `vector_join` | 58 | 5.4s |  |
| 846 | `vector_lastindexof` | 302 | 5.4s |  |
| 847 | `vector_legacy` | 10 | 5.4s |  |
| 848 | `vector_map` | 85 | 5.4s |  |
| 849 | `vector_object_final` | 1 | 5.4s |  |
| 850 | `vector_object_toString` | 10 | 5.4s |  |
| 851 | `vector_pushpop` | 255 | 5.5s |  |
| 852 | `vector_reborrow_bug` | 10 | 37.5s |  |
| 853 | `vector_removeat` | 172 | 7.5s |  |
| 854 | `vector_reverse` | 232 | 7.5s |  |
| 855 | `vector_shiftunshift` | 252 | 6.3s |  |
| 856 | `vector_slice` | 331 | 8.1s |  |
| 857 | `vector_sort` | 905 | 15.9s |  |
| 858 | `vector_splice` | 693 | 10.5s |  |
| 859 | `vector_splice_fixed_bug_compat` | 4 | 6.4s |  |
| 860 | `vector_tostring` | 79 | 7.0s |  |
| 861 | `verify_abnormal_loop` | 1 | 6.3s |  |
| 862 | `verify_exception_targets_edge_case` | 1 | 6.3s |  |
| 863 | `verify_lookup_switch_edge_case` | 1 | 6.2s |  |
| 864 | `verify_unreachable_exception` | 2 | 6.3s |  |
| 865 | `versioned_isplaying` | 2 | 6.3s |  |
| 866 | `virtual_properties` | 16 | 6.4s |  |
| 867 | `with` | 4 | 6.3s |  |
| 868 | `wrong_arg_count` | 7 | 6.5s |  |
| 869 | `xml_abstract_equality` | 36 | 6.6s |  |
| 870 | `xml_advanced` | 52 | 6.4s |  |
| 871 | `xml_appendchild` | 10 | 6.3s |  |
| 872 | `xml_as_attribute` | 9 | 6.3s |  |
| 873 | `xml_attribute` | 35 | 6.5s |  |
| 874 | `xml_attribute_name` | 40 | 6.4s |  |
| 875 | `xml_basic` | 33 | 6.4s |  |
| 876 | `xml_child` | 25 | 6.5s |  |
| 877 | `xml_childindex` | 7 | 6.3s |  |
| 878 | `xml_children` | 43 | 7.0s |  |
| 879 | `xml_class_call` | 9 | 6.3s |  |
| 880 | `xml_contains` | 197 | 6.5s |  |
| 881 | `xml_copy` | 20 | 37.9s |  |
| 882 | `xml_ctor_from_tostring` | 23 | 6.7s |  |
| 883 | `xml_delete` | 114 | 6.6s |  |
| 884 | `xml_descendants` | 83 | 6.5s |  |
| 885 | `xml_elements` | 6 | 6.4s |  |
| 886 | `xml_equals_namespace_check` | 2 | 6.3s |  |
| 887 | `xml_explicit_use_namespace` | 5 | 25.2s |  |
| 888 | `xml_getdescendants_qname` | 21 | 6.3s |  |
| 889 | `xml_has_property_via_in` | 26 | 6.5s |  |
| 890 | `xml_hasownproperty` | 6 | 6.4s |  |
| 891 | `xml_ignore_white` | 6 | 6.4s |  |
| 892 | `xml_length` | 2 | 6.3s |  |
| 893 | `xml_list_as_attribute` | 9 | 6.3s |  |
| 894 | `xml_list_concat` | 20 | 6.4s |  |
| 895 | `xml_list_enumerate` | 4 | 6.3s |  |
| 896 | `xml_methods_settings` | 3 | 6.4s |  |
| 897 | `xml_mismatched_tag` | 37 | 6.5s |  |
| 898 | `xml_namespace` | 39 | 6.4s |  |
| 899 | `xml_namespace_methods` | 245 | 6.4s |  |
| 900 | `xml_namespaced_property` | 7 | 6.4s |  |
| 901 | `xml_no_namespace` | 1 | 6.3s |  |
| 902 | `xml_nodekind` | 3 | 6.3s |  |
| 903 | `xml_normalize` | 35 | 6.5s |  |
| 904 | `xml_notification_bubbling` | 361 | 6.4s |  |
| 905 | `xml_parent` | 8 | 6.4s |  |
| 906 | `xml_set_children` | 17 | 6.5s |  |
| 907 | `xml_set_name` | 34 | 6.4s |  |
| 908 | `xml_settings` | 6 | 3.0s |  |
| 909 | `xml_simple_complex_content` | 47 | 6.4s |  |
| 910 | `xml_socket` | 11 | 6.6s |  |
| 911 | `xml_text` | 7 | 6.4s |  |
| 912 | `xml_tostring` | 6 | 6.4s |  |
| 913 | `xml_tostring_namespace` | 12 | 6.4s |  |
| 914 | `xml_unescaping` | 23 | 6.5s |  |
| 915 | `xml_weird_ignores` | 54 | 6.5s |  |
| 916 | `xml_wildcard` | 11 | 6.5s |  |
| 917 | `xmldocument` | 254 | 6.5s |  |
| 918 | `xmlnode` | 3540 | 6.6s |  |
| 919 | `zero_frame_clip` | 3 | 7.0s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.5s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 25.3s |  |
| 3 | `blend_transform` | 1 | 1 | 6.2s |  |
| 4 | `coerce_property` | 3 | 3 | 6.6s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.7s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 25.6s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.0s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 37.5s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.3s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.6s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.7s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 6.4s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 25.0s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 27.1s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.5s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.6s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.8s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.4s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 25.0s |  |
| 20 | `soundchannel_position` | 74 | 74 | 27.0s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.8s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.7s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 25.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.4s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.4s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 6.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**58 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 5 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 6 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 7 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 8 | `movieclip_hittest` | 97.0% | 65 | 67 | 2 |  |
| 9 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 10 | `displayobject_hittestpoint` | 95.9% | 47 | 49 | 2 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 13 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 14 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 15 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 16 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 17 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 18 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 19 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 22 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 23 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 24 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 25 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 26 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 27 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 28 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 29 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 30 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 31 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 32 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 33 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 34 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 35 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 36 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 37 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 38 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 39 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 40 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 41 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 42 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 43 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 44 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 46 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 47 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 48 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 49 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 50 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 51 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 52 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 53 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 54 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 55 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 56 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 57 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 58 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 24.0s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 5.0s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**273 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 5 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 6 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 7 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 8 | `movieclip_hittest` | 97.0% | 65/67 | 67 | 67 |  |
| 9 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 10 | `displayobject_hittestpoint` | 95.9% | 47/49 | 49 | 49 |  |
| 11 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 12 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 13 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 14 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 15 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 16 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 17 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 18 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 19 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 20 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 21 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 22 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 23 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 24 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 25 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 26 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 27 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 28 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 29 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 30 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 31 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 32 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 33 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 34 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 35 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 36 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 37 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 38 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 39 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 40 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 41 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 42 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 43 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 44 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 46 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 47 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 48 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 49 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 50 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 51 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 52 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 53 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 54 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 57 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 58 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 59 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 60 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 61 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 62 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 63 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 64 | `amf_array_serialization` | 35.3% | 6/17 | 6 | 17 |  |
| 65 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 66 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 67 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 68 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 69 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 70 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 71 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 72 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 73 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 74 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 75 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 76 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 77 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 78 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 79 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 80 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 81 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 82 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 83 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 84 | `netconnection_serialize_arrays` | 16.7% | 1/6 | 1 | 6 |  |
| 85 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 86 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 87 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 88 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 89 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 90 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 91 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 92 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 93 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 94 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 95 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 96 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 97 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 98 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 99 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 100 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 101 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 102 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 103 | `localconnection` | 7.5% | 67/890 | 623 | 890 |  |
| 104 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 105 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 106 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 107 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 108 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 109 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 110 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 111 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 112 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 113 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 114 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 115 | `netconnection_send_remote` | 4.0% | 2/50 | 2 | 50 |  |
| 116 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 117 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 118 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 119 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 120 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 121 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 122 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 123 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 124 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 125 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 126 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 127 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 128 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 129 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 130 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 131 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 132 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 133 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 134 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 135 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 136 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 137 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 138 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 139 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 140 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 141 | `all_classes/events/swf9` | 0.1% | 1/1030 | 178 | 1030 |  |
| 142 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 143 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 144 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 145 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 146 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 147 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 148 | `all_classes/events/swf10` | 0.1% | 1/1638 | 178 | 1638 |  |
| 149 | `all_classes/events/swf11` | 0.1% | 1/1750 | 178 | 1750 |  |
| 150 | `all_classes/events/swf12` | 0.1% | 1/1814 | 178 | 1814 |  |
| 151 | `all_classes/events/swf30` | 0.0% | 1/2353 | 178 | 2353 |  |
| 152 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 153 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 154 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 155 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 156 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 157 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 158 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 159 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 160 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 161 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 162 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 163 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 164 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 165 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 166 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 167 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 168 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 169 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 170 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 171 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 172 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 173 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 174 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 175 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 176 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 177 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 178 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 179 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 180 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 181 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 182 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 183 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 184 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 185 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 186 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 187 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 188 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 189 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 190 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 191 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 192 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 193 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 194 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 195 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 196 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 197 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 198 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 199 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 200 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 201 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 202 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 203 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 204 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 205 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 206 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 207 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 208 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 209 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 210 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 211 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 212 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 213 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 214 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 215 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 216 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 217 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 218 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 219 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 220 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 221 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 222 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 223 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 224 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 225 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 226 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 227 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 228 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 229 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 230 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 231 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 232 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 233 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 234 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 235 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 236 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 237 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 238 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 239 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 240 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 241 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 242 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 243 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 244 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 245 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 246 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 247 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 248 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 249 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 250 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 251 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 252 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 253 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 254 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 255 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 256 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 257 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 258 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 259 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 260 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 261 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 262 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 263 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 264 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 265 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 266 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 267 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 268 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 269 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 270 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 271 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 272 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 273 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
