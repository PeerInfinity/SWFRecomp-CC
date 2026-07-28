# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-28 04:05 UTC

**Git SHA**: `1617724ebe`

**Run Duration**: 163m 15s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **875** (71.7%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **901** (73.8%) |
| Failing | 320 |
| Total expected lines | 151253 |
| Matching lines | 105591 (69.8%) |
| Mismatched lines | 45662 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 317 | 99.1% |
| Runtime Error | 3 | 0.9% |

## Passing Tests

**875 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.2s |  |
| 2 | `agal_compiler` | 13 | 8.1s |  |
| 3 | `air_hidden_lookup` | 2 | 5.8s |  |
| 4 | `all_classes/security/swf11` | 3 | 5.7s |  |
| 5 | `amf_custom_obj` | 26 | 5.8s |  |
| 6 | `amf_dictionary` | 9 | 5.7s |  |
| 7 | `amf_function` | 46 | 5.8s |  |
| 8 | `amf_invalid_date` | 2 | 5.7s |  |
| 9 | `amf_missing_prop` | 6 | 5.7s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.2s |  |
| 11 | `amf_setter_error` | 8 | 6.4s |  |
| 12 | `amf_vector` | 40 | 6.4s |  |
| 13 | `amf_xml` | 6 | 6.2s |  |
| 14 | `application_domain` | 4 | 6.3s |  |
| 15 | `array_access` | 18 | 6.3s |  |
| 16 | `array_access_interpreter` | 4 | 6.3s |  |
| 17 | `array_access_no_pubns` | 2 | 6.3s |  |
| 18 | `array_concat` | 41 | 6.4s |  |
| 19 | `array_constr` | 10 | 6.2s |  |
| 20 | `array_delete` | 44 | 6.5s |  |
| 21 | `array_enumeration` | 10 | 6.3s |  |
| 22 | `array_enumeration_elements` | 11 | 6.3s |  |
| 23 | `array_every` | 8 | 6.3s |  |
| 24 | `array_filter` | 6 | 6.3s |  |
| 25 | `array_foreach` | 18 | 6.4s |  |
| 26 | `array_hasownproperty` | 11 | 3.1s |  |
| 27 | `array_holes` | 9 | 6.4s |  |
| 28 | `array_index_max` | 84 | 6.3s |  |
| 29 | `array_indexof` | 25 | 6.4s |  |
| 30 | `array_join` | 26 | 6.4s |  |
| 31 | `array_lastindexof` | 29 | 6.4s |  |
| 32 | `array_length` | 14 | 6.4s |  |
| 33 | `array_literal` | 3 | 6.3s |  |
| 34 | `array_map` | 8 | 6.3s |  |
| 35 | `array_pop` | 52 | 6.5s |  |
| 36 | `array_push` | 24 | 6.4s |  |
| 37 | `array_reborrow_bug` | 6 | 6.4s |  |
| 38 | `array_reverse` | 28 | 6.5s |  |
| 39 | `array_shift` | 51 | 3.2s |  |
| 40 | `array_slice` | 39 | 6.5s |  |
| 41 | `array_some` | 8 | 6.4s |  |
| 42 | `array_sort` | 297 | 6.8s |  |
| 43 | `array_sort_fun_swf12` | 2 | 6.4s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 45 | `array_sort_random` | 210 | 6.5s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 6.4s |  |
| 47 | `array_sorton` | 545 | 7.0s |  |
| 48 | `array_sparse_ops` | 41 | 6.3s |  |
| 49 | `array_splice` | 133 | 6.5s |  |
| 50 | `array_splice2` | 428 | 6.5s |  |
| 51 | `array_splice_types` | 48 | 6.3s |  |
| 52 | `array_storage` | 8 | 6.1s |  |
| 53 | `array_tolocalestring` | 9 | 6.1s |  |
| 54 | `array_tostring` | 12 | 6.1s |  |
| 55 | `array_unshift` | 24 | 6.2s |  |
| 56 | `array_valueof` | 9 | 6.0s |  |
| 57 | `array_vector_null_callback` | 10 | 6.1s |  |
| 58 | `astype` | 28 | 6.2s |  |
| 59 | `astypelate` | 24 | 6.2s |  |
| 60 | `astypelate_propagates` | 1 | 6.1s |  |
| 61 | `asymmetric_key_events` | 11 | 6.2s |  |
| 62 | `avm2_catchup_dobj` | 158 | 6.7s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 79.6s |  |
| 64 | `bitand` | 1058 | 18.3s |  |
| 65 | `bitmap_constr` | 17 | 6.4s |  |
| 66 | `bitmap_data` | 1000 | 14.3s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 24.9s |  |
| 68 | `bitmap_properties` | 23 | 6.2s |  |
| 69 | `bitmap_subclass` | 7 | 7.6s |  |
| 70 | `bitmap_subclass_properties` | 9 | 6.6s |  |
| 71 | `bitmap_timeline` | 9 | 6.3s |  |
| 72 | `bitmapdata_accuracy` | 1 | 42.4s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 25.4s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.0s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 25.1s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.4s |  |
| 77 | `bitmapdata_clone` | 13 | 6.4s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.6s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 6.1s |  |
| 80 | `bitmapdata_constr` | 22 | 6.2s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 6.4s |  |
| 82 | `bitmapdata_copychannel` | 0 | 29.5s |  |
| 83 | `bitmapdata_copypixels` | 23 | 27.9s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 6.7s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 6.6s |  |
| 86 | `bitmapdata_dispose` | 7 | 6.7s |  |
| 87 | `bitmapdata_draw` | 0 | 27.3s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.9s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.2s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 26.6s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 6.7s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.9s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.8s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 26.8s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 7.0s |  |
| 96 | `bitmapdata_embedded` | 9 | 7.1s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.9s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 26.8s |  |
| 99 | `bitmapdata_floodfill` | 35 | 6.6s |  |
| 100 | `bitmapdata_getpixels` | 39 | 26.4s |  |
| 101 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 102 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 103 | `bitmapdata_hittest` | 112 | 7.3s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 6.7s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.9s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 7.3s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 7.0s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 6.4s |  |
| 109 | `bitmapdata_setpixels` | 286 | 6.8s |  |
| 110 | `bitmapdata_setvector` | 26 | 6.8s |  |
| 111 | `bitmapdata_sync` | 0 | 6.7s |  |
| 112 | `bitmapdata_threshold` | 176 | 7.4s |  |
| 113 | `bitnot` | 46 | 6.6s |  |
| 114 | `bitor` | 1058 | 17.9s |  |
| 115 | `bitxor` | 1058 | 17.8s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.7s |  |
| 117 | `blend_scroll` | 0 | 6.7s |  |
| 118 | `boolean_constr` | 32 | 5.0s |  |
| 119 | `boolean_negation` | 30 | 4.9s |  |
| 120 | `boolean_tostring` | 8 | 4.9s |  |
| 121 | `broadcast_event` | 7 | 4.9s |  |
| 122 | `button_nested_frame` | 48 | 5.2s |  |
| 123 | `bytearray` | 48 | 5.1s |  |
| 124 | `bytearray_compress` | 31 | 4.9s |  |
| 125 | `bytearray_errors` | 24 | 5.0s |  |
| 126 | `bytearray_method_serialization` | 1 | 4.9s |  |
| 127 | `bytearray_oom` | 3 | 4.9s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 4.9s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 5.0s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 5.0s |  |
| 131 | `bytearray_serialization` | 3 | 4.9s |  |
| 132 | `bytearray_string_null` | 19 | 5.1s |  |
| 133 | `bytearray_tostring` | 15 | 4.9s |  |
| 134 | `bytearray_utf16` | 8 | 4.9s |  |
| 135 | `bytearray_writeobject` | 24 | 4.8s |  |
| 136 | `callee_in_initializer` | 6 | 4.8s |  |
| 137 | `callproplex_class` | 1 | 4.9s |  |
| 138 | `capabilities_resolution` | 8 | 20.0s |  |
| 139 | `catch_class` | 6 | 4.9s |  |
| 140 | `catch_scope_slot` | 7 | 2.4s |  |
| 141 | `checkfilter` | 4 | 2.4s |  |
| 142 | `class_call` | 32 | 5.0s |  |
| 143 | `class_cast_call` | 14 | 4.9s |  |
| 144 | `class_enumeration` | 4 | 4.9s |  |
| 145 | `class_has_own_property` | 2 | 4.9s |  |
| 146 | `class_init_interpreter_mode` | 1 | 4.8s |  |
| 147 | `class_is` | 32 | 5.0s |  |
| 148 | `class_methods` | 5 | 4.9s |  |
| 149 | `class_object_properties` | 10 | 4.9s |  |
| 150 | `class_singleton` | 18 | 4.9s |  |
| 151 | `class_supercalls_errors` | 35 | 5.1s |  |
| 152 | `class_supercalls_mismatched` | 26 | 5.0s |  |
| 153 | `class_superclass_wrong_order` | 1 | 4.1s |  |
| 154 | `class_to_locale_string` | 2 | 4.5s |  |
| 155 | `class_to_string` | 2 | 4.2s |  |
| 156 | `class_value_of` | 2 | 4.3s |  |
| 157 | `click_block` | 5 | 18.9s |  |
| 158 | `click_invisible` | 3 | 4.3s |  |
| 159 | `closures` | 12 | 4.2s |  |
| 160 | `coerce_return_type` | 40 | 4.7s |  |
| 161 | `coerce_return_type_fail` | 2 | 4.4s |  |
| 162 | `coerce_return_void` | 3 | 4.7s |  |
| 163 | `coerce_string` | 86 | 4.7s |  |
| 164 | `coerce_string_precision` | 28 | 4.3s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 4.3s |  |
| 166 | `construct_errors_swf10` | 8 | 4.6s |  |
| 167 | `construct_frame_list` | 22 | 4.4s |  |
| 168 | `constructor_call` | 3 | 4.3s |  |
| 169 | `constructors_vs_timeline` | 5 | 18.7s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 4.4s |  |
| 171 | `control_flow_bool` | 4 | 4.4s |  |
| 172 | `control_flow_stricteq` | 8 | 4.3s |  |
| 173 | `convert_boolean` | 30 | 4.4s |  |
| 174 | `convert_integer` | 90 | 4.4s |  |
| 175 | `convert_number` | 56 | 4.4s |  |
| 176 | `convert_uinteger` | 90 | 4.3s |  |
| 177 | `cross_api_version_call_older` | 12 | 4.4s |  |
| 178 | `cryptscore` | 11 | 4.3s |  |
| 179 | `date` | 30 | 6.6s |  |
| 180 | `date_parse` | 36 | 6.2s |  |
| 181 | `declocal` | 46 | 6.2s |  |
| 182 | `declocal_i` | 46 | 6.2s |  |
| 183 | `decode_uri` | 71 | 6.5s |  |
| 184 | `decrement` | 46 | 6.2s |  |
| 185 | `decrement_i` | 46 | 2.9s |  |
| 186 | `default_values` | 7 | 6.1s |  |
| 187 | `dictionary_access` | 62 | 6.4s |  |
| 188 | `dictionary_access_no_pubns` | 2 | 6.1s |  |
| 189 | `dictionary_delete` | 101 | 6.6s |  |
| 190 | `dictionary_foreach` | 42 | 6.4s |  |
| 191 | `dictionary_hasownproperty` | 63 | 6.4s |  |
| 192 | `dictionary_in` | 62 | 6.4s |  |
| 193 | `dictionary_iter_modify` | 8 | 6.2s |  |
| 194 | `dictionary_namespaces` | 36 | 6.2s |  |
| 195 | `dictionary_primitive_keys` | 29 | 6.1s |  |
| 196 | `displayobject_alpha` | 277 | 6.1s |  |
| 197 | `displayobject_blendmode` | 0 | 6.3s |  |
| 198 | `displayobject_colortransform_nested` | 0 | 24.7s |  |
| 199 | `displayobject_from_enterframe` | 1 | 6.3s |  |
| 200 | `displayobject_getbounds_shape` | 0 | 24.8s |  |
| 201 | `displayobject_height` | 6052 | 24.8s |  |
| 202 | `displayobject_hittestobject` | 32 | 6.2s |  |
| 203 | `displayobject_invalid_floats` | 60 | 6.2s |  |
| 204 | `displayobject_invalid_props` | 3 | 6.1s |  |
| 205 | `displayobject_mask` | 3 | 6.5s |  |
| 206 | `displayobject_mask_self_referential` | 0 | 6.3s |  |
| 207 | `displayobject_metaData` | 3 | 6.2s |  |
| 208 | `displayobject_name` | 22 | 6.8s |  |
| 209 | `displayobject_name_from_timeline` | 24 | 6.6s |  |
| 210 | `displayobject_parent` | 12 | 6.4s |  |
| 211 | `displayobject_root` | 24 | 6.3s |  |
| 212 | `displayobject_rotation` | 1284 | 6.3s |  |
| 213 | `displayobject_set_matrix_nested` | 0 | 25.4s |  |
| 214 | `displayobject_set_name_loaded` | 3 | 6.5s |  |
| 215 | `displayobject_subclass` | 2 | 6.3s |  |
| 216 | `displayobject_visible` | 23 | 6.3s |  |
| 217 | `displayobject_width` | 4852 | 25.9s |  |
| 218 | `displayobject_x` | 614 | 6.3s |  |
| 219 | `displayobject_y` | 617 | 6.3s |  |
| 220 | `displayobjectcontainer_addchild` | 32 | 6.5s |  |
| 221 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.3s |  |
| 222 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.6s |  |
| 223 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.4s |  |
| 224 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.4s |  |
| 225 | `displayobjectcontainer_addchildat` | 42 | 6.6s |  |
| 226 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.8s |  |
| 227 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.7s |  |
| 228 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.6s |  |
| 229 | `displayobjectcontainer_contains` | 66 | 6.6s |  |
| 230 | `displayobjectcontainer_getchildat` | 4 | 6.5s |  |
| 231 | `displayobjectcontainer_getchildbyname` | 9 | 6.3s |  |
| 232 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.3s |  |
| 233 | `displayobjectcontainer_getchildindex` | 28 | 6.3s |  |
| 234 | `displayobjectcontainer_removechild` | 10 | 6.2s |  |
| 235 | `displayobjectcontainer_removechild_errors` | 4 | 6.3s |  |
| 236 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.5s |  |
| 237 | `displayobjectcontainer_removechildat` | 18 | 6.5s |  |
| 238 | `displayobjectcontainer_removechildren` | 51 | 6.8s |  |
| 239 | `displayobjectcontainer_setchildindex` | 42 | 6.5s |  |
| 240 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.0s |  |
| 241 | `displayobjectcontainer_swapchildren` | 42 | 6.6s |  |
| 242 | `displayobjectcontainer_swapchildrenat` | 42 | 6.5s |  |
| 243 | `displayobjectcontainer_timelineinstance` | 48 | 26.1s |  |
| 244 | `divide` | 1058 | 18.0s |  |
| 245 | `doabc_is_eager` | 1 | 25.5s |  |
| 246 | `documentclass` | 9 | 6.7s |  |
| 247 | `domain_memory` | 133 | 7.6s |  |
| 248 | `drag_drop` | 10 | 6.8s |  |
| 249 | `duplicate_defs` | 1 | 6.3s |  |
| 250 | `eager_init` | 1 | 6.5s |  |
| 251 | `edit_text_linkage` | 7 | 6.7s |  |
| 252 | `edittext_align` | 60 | 6.9s |  |
| 253 | `edittext_always_show_selection` | 0 | 26.2s |  |
| 254 | `edittext_antialiastype` | 296 | 6.8s |  |
| 255 | `edittext_at_point_methods_basic` | 16 | 7.9s |  |
| 256 | `edittext_autosize` | 39 | 6.9s |  |
| 257 | `edittext_autosize_align` | 0 | 26.4s |  |
| 258 | `edittext_autosize_height_dynamic` | 60 | 26.4s |  |
| 259 | `edittext_autosize_height_input` | 60 | 6.7s |  |
| 260 | `edittext_autosize_lazy_bounds_events` | 65 | 6.9s |  |
| 261 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.6s |  |
| 262 | `edittext_autosize_lazy_bounds_props` | 490 | 8.1s |  |
| 263 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.4s |  |
| 264 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.8s |  |
| 265 | `edittext_bottom_scroll_v_basic` | 210 | 6.7s |  |
| 266 | `edittext_bounds_scale` | 24 | 26.0s |  |
| 267 | `edittext_bullet` | 30 | 6.7s |  |
| 268 | `edittext_default_format` | 221 | 6.9s |  |
| 269 | `edittext_default_format_empty` | 136 | 6.9s |  |
| 270 | `edittext_empty_text_format` | 7 | 6.7s |  |
| 271 | `edittext_focus_selection` | 5 | 6.6s |  |
| 272 | `edittext_font_size` | 45 | 6.7s |  |
| 273 | `edittext_format_empty_font` | 8 | 6.6s |  |
| 274 | `edittext_get_char_index_at_point` | 4 | 27.8s |  |
| 275 | `edittext_get_line_index_at_point` | 2 | 27.0s |  |
| 276 | `edittext_get_line_index_of_char` | 76 | 7.6s |  |
| 277 | `edittext_getcharboundaries` | 172 | 7.1s |  |
| 278 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.8s |  |
| 279 | `edittext_getcharboundaries_scroll` | 85 | 6.6s |  |
| 280 | `edittext_getlinemetrics` | 146 | 6.6s |  |
| 281 | `edittext_html` | 3101 | 7.0s |  |
| 282 | `edittext_html_condensewhite` | 487 | 6.4s |  |
| 283 | `edittext_html_entity` | 4 | 6.5s |  |
| 284 | `edittext_html_font_size_swf12` | 267 | 6.4s |  |
| 285 | `edittext_html_font_size_swf13` | 273 | 6.1s |  |
| 286 | `edittext_html_roundtrip` | 17 | 6.4s |  |
| 287 | `edittext_input_control` | 12 | 6.6s |  |
| 288 | `edittext_leading` | 9 | 6.5s |  |
| 289 | `edittext_letter_spacing` | 15 | 6.2s |  |
| 290 | `edittext_line_methods` | 294 | 7.6s |  |
| 291 | `edittext_line_metrics` | 11 | 26.5s |  |
| 292 | `edittext_margins` | 25 | 6.4s |  |
| 293 | `edittext_max_scroll_h_basic` | 475 | 6.5s |  |
| 294 | `edittext_max_scroll_v_basic` | 1000 | 6.3s |  |
| 295 | `edittext_mousedown` | 3 | 6.7s |  |
| 296 | `edittext_mouseenabled` | 26 | 6.3s |  |
| 297 | `edittext_newline_character` | 22 | 6.3s |  |
| 298 | `edittext_newline_stripping` | 64 | 9.1s |  |
| 299 | `edittext_newlines` | 30 | 6.5s |  |
| 300 | `edittext_paragraph_methods` | 257 | 6.3s |  |
| 301 | `edittext_paste_events` | 8 | 6.5s |  |
| 302 | `edittext_paste_maxchars` | 4 | 6.5s |  |
| 303 | `edittext_paste_restrict` | 16 | 6.3s |  |
| 304 | `edittext_restrict` | 191 | 6.3s |  |
| 305 | `edittext_restrict_events` | 22 | 6.3s |  |
| 306 | `edittext_scrollh` | 10 | 6.3s |  |
| 307 | `edittext_selected_text` | 9 | 6.4s |  |
| 308 | `edittext_set_html_same` | 17 | 6.4s |  |
| 309 | `edittext_set_text_vs_html` | 9 | 6.4s |  |
| 310 | `edittext_stylesheet` | 536 | 6.8s |  |
| 311 | `edittext_stylesheet_custom_tag` | 76 | 6.5s |  |
| 312 | `edittext_stylesheet_display` | 272 | 6.7s |  |
| 313 | `edittext_underline` | 40 | 6.5s |  |
| 314 | `edittext_width_height` | 103 | 6.4s |  |
| 315 | `edittext_wordwrap_word` | 150 | 6.4s |  |
| 316 | `edittext_wrap_breaks` | 2375 | 6.8s |  |
| 317 | `empty_bounds` | 1 | 6.2s |  |
| 318 | `encode_uri_surrogate_pair_swf11` | 15 | 6.4s |  |
| 319 | `equals` | 512 | 10.7s |  |
| 320 | `error_geterrormessage` | 779 | 6.3s |  |
| 321 | `error_prototype` | 15 | 6.2s |  |
| 322 | `error_stack_trace_debug_swf17` | 0 | 25.6s |  |
| 323 | `error_stack_trace_debug_swf18` | 0 | 6.2s |  |
| 324 | `error_stack_trace_release_swf17` | 0 | 6.1s |  |
| 325 | `error_stack_trace_release_swf18` | 0 | 6.0s |  |
| 326 | `error_tostring` | 29 | 6.2s |  |
| 327 | `es3_inheritance` | 31 | 6.3s |  |
| 328 | `es4_inheritance` | 30 | 6.3s |  |
| 329 | `es4_interfaces` | 30 | 6.4s |  |
| 330 | `es4_method_binding` | 8 | 6.3s |  |
| 331 | `es4_oop_prototypes` | 14 | 6.5s |  |
| 332 | `es4_protected_inheritance` | 6 | 6.2s |  |
| 333 | `escape` | 71 | 6.2s |  |
| 334 | `event_bubbles` | 2 | 6.0s |  |
| 335 | `event_cancelable` | 2 | 6.0s |  |
| 336 | `event_clone` | 20 | 6.2s |  |
| 337 | `event_clone_error_redispatch` | 3 | 6.2s |  |
| 338 | `event_clone_on_redispatch` | 10 | 6.5s |  |
| 339 | `event_formattostring` | 31 | 6.3s |  |
| 340 | `event_isdefaultprevented` | 12 | 6.2s |  |
| 341 | `event_target_getter` | 5 | 3.0s |  |
| 342 | `event_target_set` | 9 | 6.1s |  |
| 343 | `event_type` | 1 | 6.7s |  |
| 344 | `event_valueof_tostring` | 18 | 6.7s |  |
| 345 | `eventdispatcher_dispatchevent` | 12 | 6.7s |  |
| 346 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.8s |  |
| 347 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.7s |  |
| 348 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.8s |  |
| 349 | `eventdispatcher_dispatchevent_this` | 5 | 6.7s |  |
| 350 | `eventdispatcher_haseventlistener` | 25 | 6.7s |  |
| 351 | `eventdispatcher_interface_invoke` | 1 | 6.5s |  |
| 352 | `eventdispatcher_tostring` | 10 | 6.6s |  |
| 353 | `eventdispatcher_willtrigger` | 25 | 6.5s |  |
| 354 | `falsiness` | 30 | 6.7s |  |
| 355 | `fast_index_access` | 12 | 6.7s |  |
| 356 | `finddef` | 3 | 6.7s |  |
| 357 | `findprop_global_prototype` | 6 | 6.7s |  |
| 358 | `flash_xml` | 29 | 7.0s |  |
| 359 | `flash_xml_cloneNode` | 22 | 6.8s |  |
| 360 | `flash_xml_namespace` | 109 | 6.7s |  |
| 361 | `flash_xml_removeNode` | 60 | 6.8s |  |
| 362 | `focus_events_code` | 161 | 27.4s |  |
| 363 | `focus_events_key_same_object` | 26 | 6.6s |  |
| 364 | `focus_events_mixed_key_mouse` | 100 | 26.5s |  |
| 365 | `focus_events_mouse_same_object` | 40 | 25.7s |  |
| 366 | `focus_remove` | 20 | 25.3s |  |
| 367 | `focus_root_movie` | 4 | 25.7s |  |
| 368 | `focus_stage` | 1 | 6.3s |  |
| 369 | `focusrect` | 18 | 7.1s |  |
| 370 | `font_description_clone` | 14 | 6.4s |  |
| 371 | `font_embedded` | 24 | 6.8s |  |
| 372 | `font_enumeratefonts` | 41 | 7.0s |  |
| 373 | `font_enumeratefonts_filter` | 4 | 7.2s |  |
| 374 | `font_hasglyphs` | 40 | 6.8s |  |
| 375 | `framelabel_constr` | 5 | 6.3s |  |
| 376 | `function_call` | 12 | 6.4s |  |
| 377 | `function_call_arguments` | 46 | 6.5s |  |
| 378 | `function_call_arguments_enumerate` | 5 | 6.3s |  |
| 379 | `function_call_coercion` | 108 | 6.8s |  |
| 380 | `function_call_default` | 6 | 6.3s |  |
| 381 | `function_call_rest` | 22 | 6.4s |  |
| 382 | `function_call_types` | 3 | 6.3s |  |
| 383 | `function_call_via_apply` | 11 | 6.4s |  |
| 384 | `function_call_via_call` | 3 | 6.3s |  |
| 385 | `function_display_anonymous` | 7 | 3.1s |  |
| 386 | `function_length` | 6 | 6.3s |  |
| 387 | `function_object` | 2 | 6.3s |  |
| 388 | `function_proto` | 5 | 6.3s |  |
| 389 | `function_proto_created` | 61 | 6.4s |  |
| 390 | `function_to_locale_string` | 4 | 6.3s |  |
| 391 | `function_to_string` | 4 | 6.3s |  |
| 392 | `function_type` | 6 | 6.4s |  |
| 393 | `function_unbound_this` | 51 | 6.5s |  |
| 394 | `function_value_of` | 4 | 6.3s |  |
| 395 | `get_definition_by_name` | 11 | 6.4s |  |
| 396 | `get_qualified_class_name` | 20 | 5.4s |  |
| 397 | `get_qualified_super_class_name` | 18 | 5.3s |  |
| 398 | `get_slot_edge_cases` | 1 | 5.5s |  |
| 399 | `get_timer` | 2 | 5.2s |  |
| 400 | `getglobalslot` | 1 | 5.2s |  |
| 401 | `getouterscope` | 8 | 5.2s |  |
| 402 | `getter_different_namespace_setter` | 2 | 5.1s |  |
| 403 | `goto_button_nested_framescript` | 28 | 5.6s |  |
| 404 | `goto_in_constructframe` | 12 | 5.5s |  |
| 405 | `goto_in_scene_last_frame` | 2 | 21.4s |  |
| 406 | `goto_methods` | 56 | 5.3s |  |
| 407 | `goto_methods_swfver10` | 8 | 5.3s |  |
| 408 | `goto_nested_construct_sibling` | 18 | 5.8s |  |
| 409 | `goto_nested_framescript` | 9 | 5.2s |  |
| 410 | `goto_on_orphan` | 15 | 5.4s |  |
| 411 | `graphics_bad_direct_commands` | 5 | 5.7s |  |
| 412 | `graphics_bitmap_fill` | 0 | 6.6s |  |
| 413 | `graphics_bitmaps` | 0 | 5.7s |  |
| 414 | `graphics_direct_commands` | 0 | 5.8s |  |
| 415 | `graphics_draw_triangles` | 98 | 22.0s |  |
| 416 | `graphics_gradients` | 0 | 5.4s |  |
| 417 | `graphics_gradients_nulls` | 0 | 5.2s |  |
| 418 | `graphics_path` | 56 | 5.1s |  |
| 419 | `graphics_round_rects` | 0 | 5.0s |  |
| 420 | `graphics_simple_shapes` | 0 | 5.3s |  |
| 421 | `greaterequals` | 512 | 7.5s |  |
| 422 | `greaterthan` | 512 | 7.7s |  |
| 423 | `has_own_property` | 102 | 5.7s |  |
| 424 | `hasownproperty_namespaces` | 2 | 5.1s |  |
| 425 | `hello_world` | 1 | 5.3s |  |
| 426 | `hittest_morph` | 30 | 5.5s |  |
| 427 | `if_eq` | 10 | 5.3s |  |
| 428 | `if_gt` | 1 | 5.1s |  |
| 429 | `if_gte` | 10 | 6.4s |  |
| 430 | `if_lt` | 1 | 6.4s |  |
| 431 | `if_lte` | 10 | 6.3s |  |
| 432 | `if_ne` | 7 | 3.1s |  |
| 433 | `if_stricteq` | 6 | 6.4s |  |
| 434 | `if_strictne` | 11 | 6.5s |  |
| 435 | `in` | 102 | 6.8s |  |
| 436 | `inclocal` | 46 | 6.4s |  |
| 437 | `inclocal_i` | 46 | 6.4s |  |
| 438 | `increment` | 46 | 6.4s |  |
| 439 | `increment_i` | 46 | 6.4s |  |
| 440 | `indexing_delete` | 75 | 6.3s |  |
| 441 | `instanceof` | 58 | 6.6s |  |
| 442 | `instantiation_on_enter_frame` | 7 | 24.8s |  |
| 443 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.3s |  |
| 444 | `int_constr` | 92 | 6.2s |  |
| 445 | `int_edge_cases` | 19 | 6.4s |  |
| 446 | `int_instanceof` | 3 | 6.2s |  |
| 447 | `int_tofixed` | 1215 | 6.3s |  |
| 448 | `int_tostring` | 3375 | 6.3s |  |
| 449 | `interactiveobject_enabled` | 25 | 6.3s |  |
| 450 | `interface_namespaces` | 78 | 6.6s |  |
| 451 | `is_finite` | 46 | 6.5s |  |
| 452 | `is_nan` | 46 | 6.2s |  |
| 453 | `is_prototype_of` | 12 | 6.4s |  |
| 454 | `issue_10221` | 2 | 6.3s |  |
| 455 | `issue_13780` | 12 | 6.4s |  |
| 456 | `issue_14901` | 1 | 6.3s |  |
| 457 | `issue_17675_edittext_paste_maxchars` | 1 | 6.3s |  |
| 458 | `issue_5292` | 5 | 6.3s |  |
| 459 | `issue_8630` | 2 | 6.4s |  |
| 460 | `issue_8630_scriptremove` | 11 | 6.4s |  |
| 461 | `istype` | 24 | 3.1s |  |
| 462 | `istypelate` | 58 | 6.6s |  |
| 463 | `istypelate_coerce` | 198 | 7.9s |  |
| 464 | `jpeg_loader_context` | 6 | 6.8s |  |
| 465 | `json_errors` | 9 | 27.7s |  |
| 466 | `json_parse` | 21 | 6.9s |  |
| 467 | `json_stringify` | 12 | 7.0s |  |
| 468 | `json_stringify_order` | 1 | 6.8s |  |
| 469 | `json_version_gated` | 1 | 6.8s |  |
| 470 | `key_input_80percent` | 1812 | 7.1s |  |
| 471 | `key_input_location` | 126 | 6.9s |  |
| 472 | `key_input_numpad` | 384 | 6.7s |  |
| 473 | `lazyinit` | 17 | 6.9s |  |
| 474 | `lessequals` | 512 | 11.3s |  |
| 475 | `lessthan` | 512 | 11.2s |  |
| 476 | `loader_bitmap_transparency` | 14 | 7.1s |  |
| 477 | `loader_bytes_unknown_content` | 14 | 7.0s |  |
| 478 | `loader_duplicate_coerce` | 3 | 7.0s |  |
| 479 | `loader_duplicate_coerce_new_domain` | 4 | 7.0s |  |
| 480 | `loader_error_in_root_ctor` | 4 | 7.1s |  |
| 481 | `loader_events` | 92 | 7.7s |  |
| 482 | `loader_image` | 8 | 7.3s |  |
| 483 | `loader_jpegxr` | 2 | 27.4s |  |
| 484 | `loader_jpegxr_alpha` | 1 | 27.0s |  |
| 485 | `loader_loadbytes_events` | 30 | 7.5s |  |
| 486 | `loader_loadbytes_invalid_png` | 4 | 6.8s |  |
| 487 | `loader_loadbytes_url` | 12 | 7.1s |  |
| 488 | `loader_loaderurl` | 6 | 7.3s |  |
| 489 | `loader_noninteractive_try_click_root` | 5 | 27.2s |  |
| 490 | `loader_reuse` | 38 | 7.0s |  |
| 491 | `loader_unknown_content` | 24 | 6.9s |  |
| 492 | `loader_visibility_interactive` | 1 | 6.9s |  |
| 493 | `loaderinfo_events` | 7 | 6.8s |  |
| 494 | `loaderinfo_loadurl` | 12 | 6.5s |  |
| 495 | `loaderinfo_more` | 6 | 7.0s |  |
| 496 | `loaderinfo_properties` | 18 | 6.5s |  |
| 497 | `loaderinfo_properties_not_loaded` | 23 | 6.6s |  |
| 498 | `loaderinfo_root` | 10 | 6.5s |  |
| 499 | `loaderinfo_root_allows` | 2 | 6.5s |  |
| 500 | `lshift` | 1058 | 18.0s |  |
| 501 | `mask_reapply` | 1 | 6.6s |  |
| 502 | `math` | 497 | 6.6s |  |
| 503 | `missing_external_interface` | 10 | 6.5s |  |
| 504 | `modulo` | 1058 | 17.8s |  |
| 505 | `morph_shape` | 2 | 25.4s |  |
| 506 | `mouse_children` | 192 | 25.8s |  |
| 507 | `mouse_click_events` | 90 | 25.5s |  |
| 508 | `mouse_double_click_events` | 188 | 6.4s |  |
| 509 | `mouse_empty_parent` | 4 | 6.5s |  |
| 510 | `mouse_over_while_dragging` | 3 | 6.5s |  |
| 511 | `mouse_pick_button_mode` | 2 | 6.5s |  |
| 512 | `mouse_sibling` | 8 | 6.6s |  |
| 513 | `movieclip_addframescript` | 3 | 25.5s |  |
| 514 | `movieclip_child_property` | 16 | 6.5s |  |
| 515 | `movieclip_constr` | 21 | 5.0s |  |
| 516 | `movieclip_currentlabels` | 17 | 19.5s |  |
| 517 | `movieclip_currentlabels_dupes1` | 46 | 19.6s |  |
| 518 | `movieclip_currentlabels_dupes2` | 30 | 5.0s |  |
| 519 | `movieclip_currentlabels_dupes3` | 67 | 5.0s |  |
| 520 | `movieclip_currentscene` | 12 | 5.0s |  |
| 521 | `movieclip_dispatchevent` | 430 | 5.1s |  |
| 522 | `movieclip_dispatchevent_cancel` | 102 | 5.1s |  |
| 523 | `movieclip_dispatchevent_handlerorder` | 251 | 5.0s |  |
| 524 | `movieclip_dispatchevent_selfadd` | 80 | 5.0s |  |
| 525 | `movieclip_dispatchevent_target` | 899 | 5.0s |  |
| 526 | `movieclip_displayevents` | 96 | 19.7s |  |
| 527 | `movieclip_displayevents_clickgoto` | 676 | 5.4s |  |
| 528 | `movieclip_displayevents_clickgoto2` | 2001 | 5.5s |  |
| 529 | `movieclip_displayevents_clickplay` | 575 | 5.2s |  |
| 530 | `movieclip_displayevents_clicksymbol` | 562 | 5.2s |  |
| 531 | `movieclip_displayevents_constructframegoto` | 140 | 5.4s |  |
| 532 | `movieclip_displayevents_constructframeplay` | 50 | 5.2s |  |
| 533 | `movieclip_displayevents_constructframesymbol` | 144 | 5.2s |  |
| 534 | `movieclip_displayevents_dblhandler` | 21 | 5.2s |  |
| 535 | `movieclip_displayevents_enterframegoto` | 149 | 5.3s |  |
| 536 | `movieclip_displayevents_enterframeplay` | 48 | 5.1s |  |
| 537 | `movieclip_displayevents_enterframesymbol` | 149 | 20.1s |  |
| 538 | `movieclip_displayevents_exitframegoto` | 106 | 5.2s |  |
| 539 | `movieclip_displayevents_exitframeplay` | 44 | 5.1s |  |
| 540 | `movieclip_displayevents_exitframesymbol` | 135 | 5.2s |  |
| 541 | `movieclip_displayevents_looping` | 63 | 20.3s |  |
| 542 | `movieclip_displayevents_stopped` | 113 | 5.5s |  |
| 543 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 544 | `movieclip_displayevents_timeline` | 128 | 20.0s |  |
| 545 | `movieclip_drawrect` | 54 | 5.0s |  |
| 546 | `movieclip_frameconstruct_skipped` | 9 | 5.0s |  |
| 547 | `movieclip_goto_during_frame_script` | 15 | 5.0s |  |
| 548 | `movieclip_goto_overwrite` | 14 | 19.5s |  |
| 549 | `movieclip_goto_scene_last_frame_int` | 1 | 19.7s |  |
| 550 | `movieclip_goto_scene_last_frame_label` | 1 | 4.9s |  |
| 551 | `movieclip_gotoandplay` | 15 | 19.4s |  |
| 552 | `movieclip_gotoandstop` | 13 | 4.9s |  |
| 553 | `movieclip_gotoandstop_children` | 4 | 5.0s |  |
| 554 | `movieclip_gotoandstop_framescripts1` | 4 | 5.0s |  |
| 555 | `movieclip_gotoandstop_framescripts2` | 4 | 2.4s |  |
| 556 | `movieclip_gotoandstop_framescripts_self` | 7 | 6.5s |  |
| 557 | `movieclip_gotoandstop_queueing` | 12 | 6.6s |  |
| 558 | `movieclip_next_frame` | 2 | 6.4s |  |
| 559 | `movieclip_next_scene` | 6 | 25.5s |  |
| 560 | `movieclip_play` | 3 | 6.2s |  |
| 561 | `movieclip_prev_frame` | 3 | 6.2s |  |
| 562 | `movieclip_prev_scene` | 7 | 6.4s |  |
| 563 | `movieclip_properties` | 79 | 6.6s |  |
| 564 | `movieclip_queued_noop_goto_swf10` | 9 | 6.4s |  |
| 565 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 566 | `movieclip_scenes` | 11 | 6.3s |  |
| 567 | `movieclip_soundtransform` | 831 | 27.8s |  |
| 568 | `movieclip_stop` | 1 | 6.3s |  |
| 569 | `movieclip_super_is_symbol` | 20 | 6.8s |  |
| 570 | `movieclip_symbol_constr` | 8 | 6.6s |  |
| 571 | `movieclip_text_mousedown` | 1 | 6.4s |  |
| 572 | `movieclip_willtrigger` | 5 | 6.4s |  |
| 573 | `multiply` | 1058 | 18.5s |  |
| 574 | `namespace_constr` | 253 | 6.6s |  |
| 575 | `namespace_constr_args` | 1 | 6.2s |  |
| 576 | `namespace_enumeration_order` | 7 | 6.4s |  |
| 577 | `nan_scale` | 9 | 6.4s |  |
| 578 | `navigateToURL_target_normalize` | 107 | 26.3s |  |
| 579 | `negate` | 30 | 6.3s |  |
| 580 | `negative_volume_panned` | 0 | 6.7s |  |
| 581 | `nested_iteration` | 11 | 6.4s |  |
| 582 | `net_getClassByAlias` | 3 | 6.4s |  |
| 583 | `net_navigateToURL` | 57 | 6.4s |  |
| 584 | `newactivation_in_script_init` | 3 | 6.2s |  |
| 585 | `newclass_twice` | 3 | 6.2s |  |
| 586 | `nonconflicting_declarations` | 0 | 6.3s |  |
| 587 | `null_void_types` | 8 | 6.4s |  |
| 588 | `number_autoconv` | 21 | 6.5s |  |
| 589 | `number_autoconv_amf` | 132 | 6.4s |  |
| 590 | `number_autoconv_array_sort_32bit` | 1 | 6.3s |  |
| 591 | `number_constr` | 58 | 6.4s |  |
| 592 | `number_toexponential` | 378 | 6.4s |  |
| 593 | `number_toexponential2` | 35 | 6.3s |  |
| 594 | `number_tofixed` | 378 | 6.2s |  |
| 595 | `number_toprecision` | 350 | 6.4s |  |
| 596 | `obfuscated_class_names` | 3 | 6.2s |  |
| 597 | `object_enumeration` | 10 | 6.3s |  |
| 598 | `object_prototype` | 4 | 6.4s |  |
| 599 | `object_to_locale_string` | 2 | 6.3s |  |
| 600 | `object_to_string` | 2 | 6.2s |  |
| 601 | `object_value_of` | 2 | 2.9s |  |
| 602 | `op_coerce` | 54 | 6.4s |  |
| 603 | `op_coerce_x` | 54 | 6.4s |  |
| 604 | `op_escxattr` | 2 | 6.3s |  |
| 605 | `op_escxelem` | 2 | 6.3s |  |
| 606 | `op_lookupswitch` | 4 | 6.3s |  |
| 607 | `optimize_coerce` | 1 | 6.2s |  |
| 608 | `orphan_movie_complex` | 80 | 6.8s |  |
| 609 | `orphan_movie_reorder` | 111 | 25.6s |  |
| 610 | `package_namespace` | 7 | 6.2s |  |
| 611 | `param_default_value_has_zero_cpool_index` | 1 | 6.3s |  |
| 612 | `parent_early_access_child` | 16 | 6.5s |  |
| 613 | `parse_float` | 81 | 6.6s |  |
| 614 | `pixelbender_effect_BlurredFocus` | 0 | 28.1s |  |
| 615 | `pixelbender_effect_glassDisplace` | 0 | 11.5s |  |
| 616 | `pixelbender_effect_smudge` | 0 | 9.4s |  |
| 617 | `pixelbender_effect_tintype` | 0 | 8.7s |  |
| 618 | `pixelbender_effect_twirl` | 0 | 9.7s |  |
| 619 | `pixelbender_images` | 0 | 8.2s |  |
| 620 | `place_multiple` | 17 | 6.2s |  |
| 621 | `place_object_replace` | 9 | 6.3s |  |
| 622 | `place_object_replace_2` | 24 | 6.2s |  |
| 623 | `place_object_same_depth_frame` | 1 | 6.2s |  |
| 624 | `point` | 132 | 6.7s |  |
| 625 | `primitive_edge_cases` | 1 | 6.0s |  |
| 626 | `property_priority` | 22 | 6.5s |  |
| 627 | `property_priority_three_level` | 6 | 6.3s |  |
| 628 | `propertyisenumerable_namespaces` | 6 | 6.2s |  |
| 629 | `prototype_set_null` | 7 | 6.1s |  |
| 630 | `proxy_callproperty` | 24 | 6.2s |  |
| 631 | `proxy_deleteproperty` | 64 | 6.2s |  |
| 632 | `proxy_enumeration` | 34 | 6.2s |  |
| 633 | `proxy_getproperty` | 77 | 6.2s |  |
| 634 | `proxy_hasownproperty` | 8 | 6.1s |  |
| 635 | `proxy_hasproperty` | 32 | 6.2s |  |
| 636 | `proxy_serialize` | 9 | 6.2s |  |
| 637 | `proxy_setproperty` | 42 | 6.2s |  |
| 638 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.1s |  |
| 639 | `qname_constr` | 32 | 6.2s |  |
| 640 | `qname_constr_namespace` | 24 | 6.2s |  |
| 641 | `qname_enumeration` | 9 | 6.2s |  |
| 642 | `qname_indexing` | 23 | 6.2s |  |
| 643 | `qname_tostring` | 25 | 6.2s |  |
| 644 | `qname_valueof` | 29 | 6.2s |  |
| 645 | `regexp_constr` | 148 | 6.4s |  |
| 646 | `regexp_exec` | 19 | 6.2s |  |
| 647 | `regexp_extended` | 47 | 6.1s |  |
| 648 | `regexp_multiargs` | 1 | 6.0s |  |
| 649 | `regexp_test` | 27 | 6.2s |  |
| 650 | `regexp_toString` | 10 | 6.2s |  |
| 651 | `register_script_refresh` | 35 | 6.5s |  |
| 652 | `remove_child_clear_field` | 88 | 6.5s |  |
| 653 | `remove_dobj` | 3 | 6.1s |  |
| 654 | `resolve_order` | 4 | 6.1s |  |
| 655 | `rng` | 1 | 7.3s |  |
| 656 | `rootless` | 42 | 6.3s |  |
| 657 | `rshift` | 1058 | 18.2s |  |
| 658 | `sandbox_type_inherited` | 2 | 4.8s |  |
| 659 | `sandbox_type_local_file` | 1 | 4.3s |  |
| 660 | `scene_constr` | 8 | 4.6s |  |
| 661 | `set_local_0` | 31 | 4.5s |  |
| 662 | `set_property_is_enumerable` | 85 | 4.7s |  |
| 663 | `shape_drawrect` | 54 | 4.5s |  |
| 664 | `shared_object_no_root` | 3 | 4.4s |  |
| 665 | `simplebutton_added_to_stage` | 45 | 18.9s |  |
| 666 | `simplebutton_childevents` | 86 | 5.0s |  |
| 667 | `simplebutton_childevents_nested` | 54 | 4.9s |  |
| 668 | `simplebutton_childevents_sprite` | 13 | 4.3s |  |
| 669 | `simplebutton_childprops` | 144 | 4.5s |  |
| 670 | `simplebutton_childshuffle` | 23 | 4.6s |  |
| 671 | `simplebutton_constr` | 36 | 5.0s |  |
| 672 | `simplebutton_constr_childevents` | 48 | 4.8s |  |
| 673 | `simplebutton_constr_params` | 42 | 4.6s |  |
| 674 | `simplebutton_mouseenabled` | 26 | 4.5s |  |
| 675 | `simplebutton_multi_children` | 19 | 4.5s |  |
| 676 | `simplebutton_structure` | 27 | 4.5s |  |
| 677 | `simplebutton_symbolclass` | 68 | 4.5s |  |
| 678 | `slot_disp_id_shared_numbering` | 1 | 18.0s |  |
| 679 | `slots_force_autoassigned` | 1 | 4.3s |  |
| 680 | `sound_embeddedprops` | 26 | 6.7s |  |
| 681 | `sound_play` | 19 | 6.8s |  |
| 682 | `sound_valueof` | 33 | 6.6s |  |
| 683 | `soundchannel_soundtransform` | 835 | 27.7s |  |
| 684 | `soundchannel_soundtransform_exists` | 5 | 25.7s |  |
| 685 | `soundchannel_stop` | 8 | 6.8s |  |
| 686 | `soundmixer_buffertime` | 5 | 6.5s |  |
| 687 | `soundmixer_stopall` | 6 | 6.7s |  |
| 688 | `soundtransform` | 442 | 12.1s |  |
| 689 | `sprite_with_frames` | 0 | 7.2s |  |
| 690 | `stage3d_agal_cross_product` | 0 | 9.2s |  |
| 691 | `stage3d_bitmap` | 0 | 31.0s |  |
| 692 | `stage3d_float1_index` | 0 | 28.7s |  |
| 693 | `stage3d_fractal` | 0 | 29.0s |  |
| 694 | `stage3d_ignore_sampler_override` | 0 | 28.7s |  |
| 695 | `stage3d_program_constants_bytearray_be` | 0 | 30.1s |  |
| 696 | `stage3d_program_constants_bytearray_le` | 0 | 10.1s |  |
| 697 | `stage3d_raytrace` | 0 | 31.8s |  |
| 698 | `stage3d_rotating_cube` | 0 | 10.3s |  |
| 699 | `stage3d_sampler` | 0 | 8.8s |  |
| 700 | `stage3d_sampler_partial_upload` | 0 | 8.7s |  |
| 701 | `stage3d_stencil` | 0 | 27.6s |  |
| 702 | `stage3d_texture` | 0 | 13.4s |  |
| 703 | `stage3d_texture_bytearray` | 0 | 10.0s |  |
| 704 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.4s |  |
| 705 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.4s |  |
| 706 | `stage3d_triangle` | 0 | 8.9s |  |
| 707 | `stage3d_triangle_bytes4` | 0 | 8.8s |  |
| 708 | `stage3d_triangle_float1` | 0 | 8.8s |  |
| 709 | `stage3d_triangle_index_upload` | 0 | 8.7s |  |
| 710 | `stage_access` | 10 | 6.1s |  |
| 711 | `stage_displayobject_properties` | 24 | 6.0s |  |
| 712 | `stage_framerate_nan` | 7 | 6.2s |  |
| 713 | `stage_framerate_negative` | 6 | 6.1s |  |
| 714 | `stage_framerate_zero` | 6 | 6.1s |  |
| 715 | `stage_invalidate` | 38 | 6.3s |  |
| 716 | `stage_loaderinfo_properties` | 24 | 6.4s |  |
| 717 | `stage_mousechildren` | 2 | 6.0s |  |
| 718 | `stage_mouseenabled` | 15 | 6.0s |  |
| 719 | `stage_overriden_setters` | 31 | 6.2s |  |
| 720 | `stage_properties` | 30 | 6.0s |  |
| 721 | `static_var_with_this_in_ctor` | 2 | 6.0s |  |
| 722 | `stored_properties` | 11 | 6.1s |  |
| 723 | `strict_equality` | 34 | 6.1s |  |
| 724 | `string_call` | 13 | 6.1s |  |
| 725 | `string_case` | 23 | 6.1s |  |
| 726 | `string_char_at` | 27 | 6.1s |  |
| 727 | `string_char_code_at` | 28 | 6.0s |  |
| 728 | `string_concat_fromcharcode` | 37 | 5.9s |  |
| 729 | `string_constr` | 25 | 6.1s |  |
| 730 | `string_indexof_lastindexof` | 87 | 6.1s |  |
| 731 | `string_length` | 16 | 6.0s |  |
| 732 | `string_locale_compare` | 39 | 6.0s |  |
| 733 | `string_match` | 51 | 6.0s |  |
| 734 | `string_relational_compare` | 4 | 6.0s |  |
| 735 | `string_replace` | 51 | 5.9s |  |
| 736 | `string_search` | 41 | 6.1s |  |
| 737 | `string_slice_substr_substring` | 170 | 6.0s |  |
| 738 | `string_split` | 29 | 6.0s |  |
| 739 | `string_substr_negative` | 21 | 6.1s |  |
| 740 | `string_substr_weird` | 182 | 6.0s |  |
| 741 | `subtract` | 1058 | 6.1s |  |
| 742 | `super_get_call` | 12 | 6.0s |  |
| 743 | `supercall_two_classobjects` | 2 | 6.2s |  |
| 744 | `swf8` | 1 | 6.1s |  |
| 745 | `swf_10_queued_goto_scripts_construct` | 52 | 6.2s |  |
| 746 | `swf_9_goto_in_enter_frame` | 17 | 6.1s |  |
| 747 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.1s |  |
| 748 | `swf_9_queued_goto_scripts` | 6 | 6.1s |  |
| 749 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 750 | `swf_9_versioning` | 2 | 6.2s |  |
| 751 | `swf_wrong_frame_count` | 38 | 6.5s |  |
| 752 | `swf_wrong_frame_count_isplaying` | 22 | 6.1s |  |
| 753 | `symbol_class_binary_data` | 8 | 6.2s |  |
| 754 | `symbol_class_conflict` | 4 | 6.5s |  |
| 755 | `symbol_class_root_not_zero` | 1 | 6.1s |  |
| 756 | `symbolclass_invalid_utf8` | 2 | 6.0s |  |
| 757 | `tab_ordering_automatic_advanced` | 184 | 7.1s |  |
| 758 | `tab_ordering_automatic_basic` | 45 | 6.3s |  |
| 759 | `tab_ordering_children` | 116 | 6.5s |  |
| 760 | `tab_ordering_custom_basic` | 34 | 6.4s |  |
| 761 | `text_engine_fontdescription` | 27 | 6.4s |  |
| 762 | `text_run` | 7 | 6.1s |  |
| 763 | `textfield_focusin_event` | 9 | 6.5s |  |
| 764 | `textfield_input_dead_keys_windows` | 15 | 6.6s |  |
| 765 | `textfield_unload` | 39 | 6.7s |  |
| 766 | `textformat` | 1134 | 6.6s |  |
| 767 | `textformat_display` | 14 | 6.5s |  |
| 768 | `textformat_font_max_length` | 4 | 6.5s |  |
| 769 | `throw` | 3 | 6.5s |  |
| 770 | `timeline_scripts` | 3 | 6.4s |  |
| 771 | `timer` | 90 | 7.5s |  |
| 772 | `timer_events` | 3 | 6.5s |  |
| 773 | `timer_finished` | 11 | 6.6s |  |
| 774 | `timer_reset` | 8 | 6.7s |  |
| 775 | `timer_setdelay` | 5 | 6.7s |  |
| 776 | `trace` | 12 | 6.3s |  |
| 777 | `truthiness` | 30 | 4.6s |  |
| 778 | `try_catch` | 11 | 4.5s |  |
| 779 | `try_catch_typed` | 12 | 4.5s |  |
| 780 | `typeof` | 30 | 4.5s |  |
| 781 | `uint_constr` | 92 | 4.5s |  |
| 782 | `uint_tofixed` | 1215 | 4.5s |  |
| 783 | `uint_tostring` | 3375 | 4.4s |  |
| 784 | `unchecked_function` | 15 | 4.5s |  |
| 785 | `unescape` | 28 | 4.5s |  |
| 786 | `url_loader` | 25 | 4.5s |  |
| 787 | `urlrequest` | 18 | 4.5s |  |
| 788 | `urshift` | 1058 | 4.7s |  |
| 789 | `vector_class` | 36 | 4.5s |  |
| 790 | `vector_class_call` | 11 | 4.5s |  |
| 791 | `vector_coercion` | 66 | 4.5s |  |
| 792 | `vector_concat` | 90 | 4.5s |  |
| 793 | `vector_constr` | 107 | 4.5s |  |
| 794 | `vector_enumeration` | 5 | 4.6s |  |
| 795 | `vector_every` | 92 | 4.5s |  |
| 796 | `vector_filter` | 95 | 4.5s |  |
| 797 | `vector_holes` | 24 | 4.5s |  |
| 798 | `vector_indexof` | 302 | 4.5s |  |
| 799 | `vector_insertat` | 270 | 4.5s |  |
| 800 | `vector_int_access` | 4 | 4.6s |  |
| 801 | `vector_int_delete` | 11 | 4.5s |  |
| 802 | `vector_join` | 58 | 4.5s |  |
| 803 | `vector_lastindexof` | 302 | 4.5s |  |
| 804 | `vector_legacy` | 10 | 4.4s |  |
| 805 | `vector_map` | 85 | 4.5s |  |
| 806 | `vector_object_final` | 1 | 4.4s |  |
| 807 | `vector_object_toString` | 10 | 4.4s |  |
| 808 | `vector_pushpop` | 255 | 4.4s |  |
| 809 | `vector_reborrow_bug` | 10 | 6.3s |  |
| 810 | `vector_removeat` | 172 | 7.4s |  |
| 811 | `vector_reverse` | 232 | 7.4s |  |
| 812 | `vector_shiftunshift` | 252 | 6.3s |  |
| 813 | `vector_slice` | 331 | 7.9s |  |
| 814 | `vector_sort` | 905 | 14.9s |  |
| 815 | `vector_splice` | 693 | 9.9s |  |
| 816 | `vector_splice_fixed_bug_compat` | 4 | 6.4s |  |
| 817 | `vector_tostring` | 79 | 6.9s |  |
| 818 | `verify_abnormal_loop` | 1 | 6.2s |  |
| 819 | `verify_exception_targets_edge_case` | 1 | 6.2s |  |
| 820 | `verify_lookup_switch_edge_case` | 1 | 6.1s |  |
| 821 | `verify_unreachable_exception` | 2 | 6.2s |  |
| 822 | `versioned_isplaying` | 2 | 6.3s |  |
| 823 | `virtual_properties` | 16 | 6.4s |  |
| 824 | `with` | 4 | 6.3s |  |
| 825 | `wrong_arg_count` | 7 | 6.5s |  |
| 826 | `xml_abstract_equality` | 36 | 6.5s |  |
| 827 | `xml_advanced` | 52 | 6.4s |  |
| 828 | `xml_appendchild` | 10 | 6.3s |  |
| 829 | `xml_as_attribute` | 9 | 6.3s |  |
| 830 | `xml_attribute` | 35 | 6.5s |  |
| 831 | `xml_attribute_name` | 40 | 6.3s |  |
| 832 | `xml_basic` | 33 | 6.4s |  |
| 833 | `xml_child` | 25 | 6.4s |  |
| 834 | `xml_childindex` | 7 | 6.3s |  |
| 835 | `xml_children` | 43 | 6.9s |  |
| 836 | `xml_class_call` | 9 | 6.3s |  |
| 837 | `xml_contains` | 197 | 6.5s |  |
| 838 | `xml_copy` | 20 | 6.5s |  |
| 839 | `xml_ctor_from_tostring` | 23 | 6.7s |  |
| 840 | `xml_delete` | 114 | 6.5s |  |
| 841 | `xml_descendants` | 83 | 6.5s |  |
| 842 | `xml_elements` | 6 | 6.4s |  |
| 843 | `xml_equals_namespace_check` | 2 | 6.4s |  |
| 844 | `xml_explicit_use_namespace` | 5 | 6.5s |  |
| 845 | `xml_getdescendants_qname` | 21 | 6.3s |  |
| 846 | `xml_has_property_via_in` | 26 | 6.4s |  |
| 847 | `xml_hasownproperty` | 6 | 6.4s |  |
| 848 | `xml_ignore_white` | 6 | 6.4s |  |
| 849 | `xml_length` | 2 | 6.3s |  |
| 850 | `xml_list_as_attribute` | 9 | 6.5s |  |
| 851 | `xml_list_concat` | 20 | 6.6s |  |
| 852 | `xml_list_enumerate` | 4 | 6.7s |  |
| 853 | `xml_methods_settings` | 3 | 6.6s |  |
| 854 | `xml_mismatched_tag` | 37 | 6.6s |  |
| 855 | `xml_namespace` | 39 | 6.5s |  |
| 856 | `xml_namespace_methods` | 245 | 6.7s |  |
| 857 | `xml_namespaced_property` | 7 | 6.7s |  |
| 858 | `xml_no_namespace` | 1 | 6.5s |  |
| 859 | `xml_nodekind` | 3 | 6.5s |  |
| 860 | `xml_normalize` | 35 | 6.4s |  |
| 861 | `xml_notification_bubbling` | 361 | 6.4s |  |
| 862 | `xml_parent` | 8 | 6.4s |  |
| 863 | `xml_set_children` | 17 | 6.5s |  |
| 864 | `xml_set_name` | 34 | 6.4s |  |
| 865 | `xml_settings` | 6 | 3.1s |  |
| 866 | `xml_simple_complex_content` | 47 | 6.4s |  |
| 867 | `xml_text` | 7 | 6.3s |  |
| 868 | `xml_tostring` | 6 | 6.4s |  |
| 869 | `xml_tostring_namespace` | 12 | 6.4s |  |
| 870 | `xml_unescaping` | 23 | 6.5s |  |
| 871 | `xml_weird_ignores` | 54 | 6.5s |  |
| 872 | `xml_wildcard` | 11 | 6.6s |  |
| 873 | `xmldocument` | 254 | 6.5s |  |
| 874 | `xmlnode` | 3540 | 6.9s |  |
| 875 | `zero_frame_clip` | 3 | 7.2s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.2s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.1s |  |
| 3 | `blend_transform` | 1 | 1 | 7.0s |  |
| 4 | `coerce_property` | 3 | 3 | 4.5s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 4.4s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 6.4s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.9s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 26.0s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.6s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.7s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.4s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 6.3s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 5.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 22.5s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.3s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.2s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 4.4s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 4.3s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 4.2s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.5s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.8s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.5s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 6.1s |  |
| 24 | `uint_toexponential` | 100 | 100 | 4.6s |  |
| 25 | `uint_toprecision` | 433 | 433 | 4.4s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 6.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**70 tests** within reach

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
| 20 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 21 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 22 | `mouse_wheel_events` | 91.7% | 33 | 36 | 3 |  |
| 23 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 24 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 25 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 26 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 27 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 28 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 29 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 30 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 31 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 32 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 33 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 34 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 35 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 36 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 37 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 38 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 39 | `loader_child_getdefinition` | 80.0% | 4 | 5 | 1 |  |
| 40 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 41 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 42 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 43 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 44 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 45 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 46 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 47 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 48 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 49 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 50 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 51 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 52 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 53 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 54 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 55 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 56 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 57 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
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
| 69 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 70 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.3s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**317 tests** with output mismatch, sorted by match rate (best first)

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
| 20 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 21 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 22 | `mouse_wheel_events` | 91.7% | 33/36 | 36 | 36 |  |
| 23 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 24 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 25 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 26 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 27 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 28 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 29 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 30 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 31 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 32 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 33 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 34 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 35 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 36 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 37 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 38 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 39 | `loader_child_getdefinition` | 80.0% | 4/5 | 5 | 5 |  |
| 40 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 41 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 42 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 43 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 44 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 45 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 46 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 47 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 48 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 49 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 50 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 51 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 52 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 53 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 54 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 55 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 56 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 57 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
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
| 69 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 70 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 71 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 72 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 73 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 74 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 75 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 76 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 77 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 78 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 79 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 80 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 81 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 82 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 83 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 84 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 85 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 86 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 87 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 88 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 89 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 90 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 91 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 92 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 93 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 94 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 95 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 96 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 97 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 98 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 99 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 100 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 101 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 102 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 103 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 104 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 105 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 106 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 107 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 108 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 109 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 110 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 111 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 112 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 113 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 114 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 115 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 116 | `localconnection` | 7.5% | 67/890 | 623 | 890 |  |
| 117 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 118 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 119 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 120 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 121 | `loader_duplicate_class` | 6.2% | 3/48 | 28 | 48 |  |
| 122 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 123 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 124 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 125 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 126 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 127 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 128 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 129 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 130 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 131 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 132 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 133 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 134 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 135 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 136 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 137 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 138 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 139 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 140 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 141 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 142 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 143 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 144 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 145 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 146 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 147 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 148 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 149 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 150 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 151 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 152 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 153 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 154 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 155 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 156 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 157 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 158 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 159 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 160 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 161 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 162 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 163 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 164 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 165 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 166 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 167 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 168 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 169 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 170 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 171 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 172 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 173 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 174 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 175 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 176 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 177 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 178 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 179 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 180 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 181 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 182 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 183 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 184 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 185 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 186 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 187 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 188 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 189 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 190 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 191 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 192 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 193 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 194 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 195 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 196 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 197 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 198 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 199 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 200 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 201 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 202 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 203 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 204 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 205 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 206 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 207 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 208 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 209 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 210 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 211 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 212 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 213 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 214 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 215 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 216 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 217 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 218 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 219 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 220 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 221 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 222 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 223 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 224 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 225 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 226 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 227 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 228 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 229 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 230 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 231 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 232 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 233 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 234 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 235 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 236 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 237 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 238 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 239 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 240 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 241 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 242 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 243 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 244 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 245 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 246 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 247 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 248 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 249 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 250 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 251 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 252 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 253 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 254 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 255 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 256 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 257 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 258 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 259 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 260 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 261 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 262 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 263 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 264 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 265 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 266 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 267 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 268 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 269 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 270 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 271 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 273 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 274 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 275 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 276 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 277 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 278 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 279 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 280 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 281 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 282 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 283 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 284 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 285 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 286 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 287 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 288 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 289 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 290 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 291 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 292 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 293 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 294 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 295 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 296 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 297 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 298 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 299 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 300 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 301 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 302 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 303 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 304 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 305 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 306 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 307 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 308 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 309 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 310 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 311 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 312 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 313 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 314 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 315 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 316 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 317 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
