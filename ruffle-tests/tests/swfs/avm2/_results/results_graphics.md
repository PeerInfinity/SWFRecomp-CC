# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-28 21:16 UTC

**Git SHA**: `bbefcf3769`

**Run Duration**: 171m 55s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **900** (73.7%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **926** (75.8%) |
| Failing | 295 |
| Total expected lines | 151253 |
| Matching lines | 106863 (70.7%) |
| Mismatched lines | 44390 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 292 | 99.0% |
| Runtime Error | 3 | 1.0% |

## Passing Tests

**900 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.9s |  |
| 2 | `agal_compiler` | 13 | 8.9s |  |
| 3 | `air_hidden_lookup` | 2 | 6.6s |  |
| 4 | `all_classes/security/swf11` | 3 | 6.7s |  |
| 5 | `amf_custom_obj` | 26 | 6.7s |  |
| 6 | `amf_dictionary` | 9 | 6.6s |  |
| 7 | `amf_function` | 46 | 6.6s |  |
| 8 | `amf_invalid_date` | 2 | 6.6s |  |
| 9 | `amf_missing_prop` | 6 | 6.6s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.1s |  |
| 11 | `amf_setter_error` | 8 | 6.2s |  |
| 12 | `amf_vector` | 40 | 6.3s |  |
| 13 | `amf_xml` | 6 | 6.0s |  |
| 14 | `application_domain` | 4 | 6.2s |  |
| 15 | `array_access` | 18 | 6.2s |  |
| 16 | `array_access_interpreter` | 4 | 6.0s |  |
| 17 | `array_access_no_pubns` | 2 | 5.9s |  |
| 18 | `array_concat` | 41 | 6.1s |  |
| 19 | `array_constr` | 10 | 5.9s |  |
| 20 | `array_delete` | 44 | 6.0s |  |
| 21 | `array_enumeration` | 10 | 6.2s |  |
| 22 | `array_enumeration_elements` | 11 | 6.0s |  |
| 23 | `array_every` | 8 | 6.0s |  |
| 24 | `array_filter` | 6 | 6.0s |  |
| 25 | `array_foreach` | 18 | 6.0s |  |
| 26 | `array_hasownproperty` | 11 | 2.8s |  |
| 27 | `array_holes` | 9 | 6.0s |  |
| 28 | `array_index_max` | 84 | 6.1s |  |
| 29 | `array_indexof` | 25 | 6.1s |  |
| 30 | `array_join` | 26 | 6.1s |  |
| 31 | `array_lastindexof` | 29 | 6.1s |  |
| 32 | `array_length` | 14 | 6.0s |  |
| 33 | `array_literal` | 3 | 6.0s |  |
| 34 | `array_map` | 8 | 5.9s |  |
| 35 | `array_pop` | 52 | 6.1s |  |
| 36 | `array_push` | 24 | 6.0s |  |
| 37 | `array_reborrow_bug` | 6 | 5.9s |  |
| 38 | `array_reverse` | 28 | 6.1s |  |
| 39 | `array_shift` | 51 | 2.9s |  |
| 40 | `array_slice` | 39 | 6.2s |  |
| 41 | `array_some` | 8 | 6.1s |  |
| 42 | `array_sort` | 297 | 6.5s |  |
| 43 | `array_sort_fun_swf12` | 2 | 6.2s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 45 | `array_sort_random` | 210 | 6.2s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 6.1s |  |
| 47 | `array_sorton` | 545 | 7.3s |  |
| 48 | `array_sparse_ops` | 41 | 6.6s |  |
| 49 | `array_splice` | 133 | 6.6s |  |
| 50 | `array_splice2` | 428 | 6.7s |  |
| 51 | `array_splice_types` | 48 | 6.5s |  |
| 52 | `array_storage` | 8 | 6.4s |  |
| 53 | `array_tolocalestring` | 9 | 6.3s |  |
| 54 | `array_tostring` | 12 | 6.4s |  |
| 55 | `array_unshift` | 24 | 6.4s |  |
| 56 | `array_valueof` | 9 | 6.2s |  |
| 57 | `array_vector_null_callback` | 10 | 6.3s |  |
| 58 | `astype` | 28 | 6.4s |  |
| 59 | `astypelate` | 24 | 6.5s |  |
| 60 | `astypelate_propagates` | 1 | 6.3s |  |
| 61 | `asymmetric_key_events` | 11 | 6.5s |  |
| 62 | `avm2_catchup_dobj` | 158 | 7.0s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 80.6s |  |
| 64 | `bitand` | 1058 | 18.4s |  |
| 65 | `bitmap_constr` | 17 | 6.6s |  |
| 66 | `bitmap_data` | 1000 | 14.7s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 25.6s |  |
| 68 | `bitmap_properties` | 23 | 6.4s |  |
| 69 | `bitmap_subclass` | 7 | 7.8s |  |
| 70 | `bitmap_subclass_properties` | 9 | 6.9s |  |
| 71 | `bitmap_timeline` | 9 | 6.5s |  |
| 72 | `bitmapdata_accuracy` | 1 | 45.1s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 26.0s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.3s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 25.6s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.8s |  |
| 77 | `bitmapdata_clone` | 13 | 6.7s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.8s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 6.3s |  |
| 80 | `bitmapdata_constr` | 22 | 6.4s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 6.6s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.5s |  |
| 83 | `bitmapdata_copypixels` | 23 | 26.1s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 6.3s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 6.2s |  |
| 86 | `bitmapdata_dispose` | 7 | 6.3s |  |
| 87 | `bitmapdata_draw` | 0 | 25.3s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.5s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.0s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 25.5s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 6.4s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.7s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.7s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 25.2s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 6.6s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.7s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.7s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 25.8s |  |
| 99 | `bitmapdata_floodfill` | 35 | 6.3s |  |
| 100 | `bitmapdata_getpixels` | 39 | 25.5s |  |
| 101 | `bitmapdata_getvector` | 27 | 3.0s |  |
| 102 | `bitmapdata_histogram` | 59 | 3.0s |  |
| 103 | `bitmapdata_hittest` | 112 | 7.0s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 6.5s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.6s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 7.0s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.8s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 6.3s |  |
| 109 | `bitmapdata_setpixels` | 286 | 6.5s |  |
| 110 | `bitmapdata_setvector` | 26 | 6.4s |  |
| 111 | `bitmapdata_sync` | 0 | 6.5s |  |
| 112 | `bitmapdata_threshold` | 176 | 7.2s |  |
| 113 | `bitnot` | 46 | 6.4s |  |
| 114 | `bitor` | 1058 | 18.6s |  |
| 115 | `bitxor` | 1058 | 18.6s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.6s |  |
| 117 | `blend_scroll` | 0 | 6.7s |  |
| 118 | `boolean_constr` | 32 | 6.5s |  |
| 119 | `boolean_negation` | 30 | 6.5s |  |
| 120 | `boolean_tostring` | 8 | 6.5s |  |
| 121 | `broadcast_event` | 7 | 6.5s |  |
| 122 | `button_nested_frame` | 48 | 7.0s |  |
| 123 | `bytearray` | 48 | 6.8s |  |
| 124 | `bytearray_compress` | 31 | 6.5s |  |
| 125 | `bytearray_errors` | 24 | 6.7s |  |
| 126 | `bytearray_method_serialization` | 1 | 6.5s |  |
| 127 | `bytearray_oom` | 3 | 6.5s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 6.5s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 6.5s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 6.5s |  |
| 131 | `bytearray_serialization` | 3 | 6.5s |  |
| 132 | `bytearray_string_null` | 19 | 6.8s |  |
| 133 | `bytearray_tostring` | 15 | 6.5s |  |
| 134 | `bytearray_utf16` | 8 | 6.5s |  |
| 135 | `bytearray_writeobject` | 24 | 6.4s |  |
| 136 | `callee_in_initializer` | 6 | 6.4s |  |
| 137 | `callproplex_class` | 1 | 6.5s |  |
| 138 | `capabilities_resolution` | 8 | 26.0s |  |
| 139 | `catch_class` | 6 | 6.5s |  |
| 140 | `catch_scope_slot` | 7 | 3.1s |  |
| 141 | `checkfilter` | 4 | 3.1s |  |
| 142 | `class_call` | 32 | 6.6s |  |
| 143 | `class_cast_call` | 14 | 6.5s |  |
| 144 | `class_enumeration` | 4 | 6.5s |  |
| 145 | `class_has_own_property` | 2 | 6.5s |  |
| 146 | `class_init_interpreter_mode` | 1 | 6.4s |  |
| 147 | `class_is` | 32 | 6.7s |  |
| 148 | `class_methods` | 5 | 6.5s |  |
| 149 | `class_object_properties` | 10 | 6.5s |  |
| 150 | `class_singleton` | 18 | 6.6s |  |
| 151 | `class_supercalls_errors` | 35 | 6.7s |  |
| 152 | `class_supercalls_mismatched` | 26 | 6.6s |  |
| 153 | `class_superclass_wrong_order` | 1 | 5.3s |  |
| 154 | `class_to_locale_string` | 2 | 5.5s |  |
| 155 | `class_to_string` | 2 | 5.5s |  |
| 156 | `class_value_of` | 2 | 5.4s |  |
| 157 | `click_block` | 5 | 21.9s |  |
| 158 | `click_invisible` | 3 | 5.5s |  |
| 159 | `closures` | 12 | 5.5s |  |
| 160 | `coerce_return_type` | 40 | 5.9s |  |
| 161 | `coerce_return_type_fail` | 2 | 5.3s |  |
| 162 | `coerce_return_void` | 3 | 5.3s |  |
| 163 | `coerce_string` | 86 | 5.5s |  |
| 164 | `coerce_string_precision` | 28 | 5.5s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 5.5s |  |
| 166 | `construct_errors_swf10` | 8 | 5.9s |  |
| 167 | `construct_frame_list` | 22 | 5.9s |  |
| 168 | `constructor_call` | 3 | 5.6s |  |
| 169 | `constructors_vs_timeline` | 5 | 21.7s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 5.6s |  |
| 171 | `control_flow_bool` | 4 | 5.8s |  |
| 172 | `control_flow_stricteq` | 8 | 5.4s |  |
| 173 | `convert_boolean` | 30 | 5.5s |  |
| 174 | `convert_integer` | 90 | 5.6s |  |
| 175 | `convert_number` | 56 | 5.6s |  |
| 176 | `convert_uinteger` | 90 | 5.6s |  |
| 177 | `cross_api_version_call_older` | 12 | 5.7s |  |
| 178 | `cryptscore` | 11 | 5.6s |  |
| 179 | `date` | 30 | 6.9s |  |
| 180 | `date_parse` | 36 | 6.5s |  |
| 181 | `declocal` | 46 | 6.5s |  |
| 182 | `declocal_i` | 46 | 6.5s |  |
| 183 | `decode_uri` | 71 | 6.9s |  |
| 184 | `decrement` | 46 | 6.5s |  |
| 185 | `decrement_i` | 46 | 3.1s |  |
| 186 | `default_values` | 7 | 6.3s |  |
| 187 | `dictionary_access` | 62 | 6.6s |  |
| 188 | `dictionary_access_no_pubns` | 2 | 6.3s |  |
| 189 | `dictionary_delete` | 101 | 6.9s |  |
| 190 | `dictionary_foreach` | 42 | 6.6s |  |
| 191 | `dictionary_hasownproperty` | 63 | 6.6s |  |
| 192 | `dictionary_in` | 62 | 6.7s |  |
| 193 | `dictionary_iter_modify` | 8 | 6.4s |  |
| 194 | `dictionary_namespaces` | 36 | 6.5s |  |
| 195 | `dictionary_primitive_keys` | 29 | 6.4s |  |
| 196 | `displayobject_alpha` | 277 | 6.3s |  |
| 197 | `displayobject_blendmode` | 0 | 6.5s |  |
| 198 | `displayobject_colortransform_nested` | 0 | 25.5s |  |
| 199 | `displayobject_from_enterframe` | 1 | 6.5s |  |
| 200 | `displayobject_getbounds_shape` | 0 | 25.4s |  |
| 201 | `displayobject_height` | 6052 | 25.5s |  |
| 202 | `displayobject_hittestobject` | 32 | 6.5s |  |
| 203 | `displayobject_invalid_floats` | 60 | 6.4s |  |
| 204 | `displayobject_invalid_props` | 3 | 6.3s |  |
| 205 | `displayobject_mask` | 3 | 6.7s |  |
| 206 | `displayobject_mask_self_referential` | 0 | 6.3s |  |
| 207 | `displayobject_metaData` | 3 | 6.2s |  |
| 208 | `displayobject_name` | 22 | 6.6s |  |
| 209 | `displayobject_name_from_timeline` | 24 | 6.5s |  |
| 210 | `displayobject_parent` | 12 | 6.3s |  |
| 211 | `displayobject_root` | 24 | 6.4s |  |
| 212 | `displayobject_rotation` | 1284 | 6.5s |  |
| 213 | `displayobject_set_matrix_nested` | 0 | 26.6s |  |
| 214 | `displayobject_set_name_loaded` | 3 | 6.9s |  |
| 215 | `displayobject_subclass` | 2 | 6.6s |  |
| 216 | `displayobject_visible` | 23 | 6.5s |  |
| 217 | `displayobject_width` | 4852 | 26.2s |  |
| 218 | `displayobject_x` | 614 | 6.6s |  |
| 219 | `displayobject_y` | 617 | 6.5s |  |
| 220 | `displayobjectcontainer_addchild` | 32 | 6.7s |  |
| 221 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.5s |  |
| 222 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.8s |  |
| 223 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.7s |  |
| 224 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.7s |  |
| 225 | `displayobjectcontainer_addchildat` | 42 | 6.6s |  |
| 226 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.7s |  |
| 227 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.8s |  |
| 228 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.8s |  |
| 229 | `displayobjectcontainer_contains` | 66 | 26.7s |  |
| 230 | `displayobjectcontainer_getchildat` | 4 | 6.7s |  |
| 231 | `displayobjectcontainer_getchildbyname` | 9 | 6.6s |  |
| 232 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.6s |  |
| 233 | `displayobjectcontainer_getchildindex` | 28 | 6.6s |  |
| 234 | `displayobjectcontainer_removechild` | 10 | 6.6s |  |
| 235 | `displayobjectcontainer_removechild_errors` | 4 | 6.6s |  |
| 236 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.8s |  |
| 237 | `displayobjectcontainer_removechildat` | 18 | 6.6s |  |
| 238 | `displayobjectcontainer_removechildren` | 51 | 7.1s |  |
| 239 | `displayobjectcontainer_setchildindex` | 42 | 6.6s |  |
| 240 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.1s |  |
| 241 | `displayobjectcontainer_swapchildren` | 42 | 6.8s |  |
| 242 | `displayobjectcontainer_swapchildrenat` | 42 | 6.8s |  |
| 243 | `displayobjectcontainer_timelineinstance` | 48 | 25.7s |  |
| 244 | `divide` | 1058 | 18.1s |  |
| 245 | `doabc_is_eager` | 1 | 25.3s |  |
| 246 | `documentclass` | 9 | 6.8s |  |
| 247 | `domain_memory` | 133 | 7.8s |  |
| 248 | `drag_drop` | 10 | 6.9s |  |
| 249 | `duplicate_defs` | 1 | 6.5s |  |
| 250 | `eager_init` | 1 | 6.7s |  |
| 251 | `edit_text_linkage` | 7 | 6.8s |  |
| 252 | `edittext_align` | 60 | 7.1s |  |
| 253 | `edittext_always_show_selection` | 0 | 26.3s |  |
| 254 | `edittext_antialiastype` | 296 | 6.9s |  |
| 255 | `edittext_at_point_methods_basic` | 16 | 8.1s |  |
| 256 | `edittext_autosize` | 39 | 7.1s |  |
| 257 | `edittext_autosize_align` | 0 | 26.6s |  |
| 258 | `edittext_autosize_height_dynamic` | 60 | 26.7s |  |
| 259 | `edittext_autosize_height_input` | 60 | 6.8s |  |
| 260 | `edittext_autosize_lazy_bounds_events` | 65 | 7.0s |  |
| 261 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.8s |  |
| 262 | `edittext_autosize_lazy_bounds_props` | 490 | 8.3s |  |
| 263 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.1s |  |
| 264 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.9s |  |
| 265 | `edittext_bottom_scroll_v_basic` | 210 | 6.8s |  |
| 266 | `edittext_bounds_scale` | 24 | 25.6s |  |
| 267 | `edittext_bullet` | 30 | 6.9s |  |
| 268 | `edittext_default_format` | 221 | 7.0s |  |
| 269 | `edittext_default_format_empty` | 136 | 6.9s |  |
| 270 | `edittext_empty_text_format` | 7 | 6.8s |  |
| 271 | `edittext_focus_selection` | 5 | 6.7s |  |
| 272 | `edittext_font_size` | 45 | 6.7s |  |
| 273 | `edittext_format_empty_font` | 8 | 6.6s |  |
| 274 | `edittext_get_char_index_at_point` | 4 | 27.3s |  |
| 275 | `edittext_get_line_index_at_point` | 2 | 26.6s |  |
| 276 | `edittext_get_line_index_of_char` | 76 | 7.8s |  |
| 277 | `edittext_getcharboundaries` | 172 | 7.2s |  |
| 278 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.8s |  |
| 279 | `edittext_getcharboundaries_scroll` | 85 | 6.6s |  |
| 280 | `edittext_getlinemetrics` | 146 | 6.6s |  |
| 281 | `edittext_html` | 3101 | 6.8s |  |
| 282 | `edittext_html_condensewhite` | 487 | 6.5s |  |
| 283 | `edittext_html_entity` | 4 | 6.6s |  |
| 284 | `edittext_html_font_size_swf12` | 267 | 6.5s |  |
| 285 | `edittext_html_font_size_swf13` | 273 | 6.1s |  |
| 286 | `edittext_html_roundtrip` | 17 | 6.4s |  |
| 287 | `edittext_ime_focus_lost` | 9 | 25.0s |  |
| 288 | `edittext_input_control` | 12 | 6.5s |  |
| 289 | `edittext_leading` | 9 | 6.7s |  |
| 290 | `edittext_letter_spacing` | 15 | 6.4s |  |
| 291 | `edittext_line_methods` | 294 | 7.7s |  |
| 292 | `edittext_line_metrics` | 11 | 26.2s |  |
| 293 | `edittext_margins` | 25 | 6.4s |  |
| 294 | `edittext_max_scroll_h_basic` | 475 | 6.5s |  |
| 295 | `edittext_max_scroll_v_basic` | 1000 | 6.4s |  |
| 296 | `edittext_mouse_selection` | 363 | 25.9s |  |
| 297 | `edittext_mousedown` | 3 | 6.7s |  |
| 298 | `edittext_mouseenabled` | 26 | 6.3s |  |
| 299 | `edittext_newline_character` | 22 | 6.3s |  |
| 300 | `edittext_newline_stripping` | 64 | 8.9s |  |
| 301 | `edittext_newlines` | 30 | 6.4s |  |
| 302 | `edittext_paragraph_methods` | 257 | 6.3s |  |
| 303 | `edittext_paste_events` | 8 | 6.5s |  |
| 304 | `edittext_paste_maxchars` | 4 | 6.3s |  |
| 305 | `edittext_paste_restrict` | 16 | 6.2s |  |
| 306 | `edittext_restrict` | 191 | 6.4s |  |
| 307 | `edittext_restrict_events` | 22 | 6.3s |  |
| 308 | `edittext_scrollh` | 10 | 6.3s |  |
| 309 | `edittext_selected_text` | 9 | 6.3s |  |
| 310 | `edittext_set_html_same` | 17 | 6.3s |  |
| 311 | `edittext_set_text_vs_html` | 9 | 6.3s |  |
| 312 | `edittext_stylesheet` | 536 | 6.7s |  |
| 313 | `edittext_stylesheet_custom_tag` | 76 | 6.4s |  |
| 314 | `edittext_stylesheet_display` | 272 | 6.4s |  |
| 315 | `edittext_underline` | 40 | 6.4s |  |
| 316 | `edittext_width_height` | 103 | 19.1s |  |
| 317 | `edittext_wordwrap_word` | 150 | 6.9s |  |
| 318 | `edittext_wrap_breaks` | 2375 | 7.1s |  |
| 319 | `empty_bounds` | 1 | 6.4s |  |
| 320 | `encode_uri_surrogate_pair_swf11` | 15 | 6.3s |  |
| 321 | `equals` | 512 | 10.9s |  |
| 322 | `error_geterrormessage` | 779 | 6.5s |  |
| 323 | `error_prototype` | 15 | 6.6s |  |
| 324 | `error_stack_trace_debug_swf17` | 0 | 26.1s |  |
| 325 | `error_stack_trace_debug_swf18` | 0 | 6.3s |  |
| 326 | `error_stack_trace_release_swf17` | 0 | 6.3s |  |
| 327 | `error_stack_trace_release_swf18` | 0 | 6.2s |  |
| 328 | `error_tostring` | 29 | 6.6s |  |
| 329 | `es3_inheritance` | 31 | 6.7s |  |
| 330 | `es4_inheritance` | 30 | 6.6s |  |
| 331 | `es4_interfaces` | 30 | 6.6s |  |
| 332 | `es4_method_binding` | 8 | 6.5s |  |
| 333 | `es4_oop_prototypes` | 14 | 6.7s |  |
| 334 | `es4_protected_inheritance` | 6 | 6.5s |  |
| 335 | `escape` | 71 | 6.6s |  |
| 336 | `event_bubbles` | 2 | 6.4s |  |
| 337 | `event_cancelable` | 2 | 6.4s |  |
| 338 | `event_clone` | 20 | 6.5s |  |
| 339 | `event_clone_error_redispatch` | 3 | 6.5s |  |
| 340 | `event_clone_on_redispatch` | 10 | 6.6s |  |
| 341 | `event_formattostring` | 31 | 6.6s |  |
| 342 | `event_isdefaultprevented` | 12 | 6.5s |  |
| 343 | `event_target_getter` | 5 | 3.0s |  |
| 344 | `event_target_set` | 9 | 6.4s |  |
| 345 | `event_type` | 1 | 19.1s |  |
| 346 | `event_valueof_tostring` | 18 | 6.7s |  |
| 347 | `eventdispatcher_dispatchevent` | 12 | 6.4s |  |
| 348 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.5s |  |
| 349 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.5s |  |
| 350 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.4s |  |
| 351 | `eventdispatcher_dispatchevent_this` | 5 | 6.5s |  |
| 352 | `eventdispatcher_haseventlistener` | 25 | 6.7s |  |
| 353 | `eventdispatcher_interface_invoke` | 1 | 6.5s |  |
| 354 | `eventdispatcher_tostring` | 10 | 6.6s |  |
| 355 | `eventdispatcher_willtrigger` | 25 | 6.4s |  |
| 356 | `falsiness` | 30 | 6.5s |  |
| 357 | `fast_index_access` | 12 | 6.5s |  |
| 358 | `finddef` | 3 | 6.7s |  |
| 359 | `findprop_global_prototype` | 6 | 6.8s |  |
| 360 | `flash_xml` | 29 | 7.1s |  |
| 361 | `flash_xml_cloneNode` | 22 | 6.9s |  |
| 362 | `flash_xml_namespace` | 109 | 6.8s |  |
| 363 | `flash_xml_removeNode` | 60 | 6.8s |  |
| 364 | `focus_events_code` | 161 | 27.7s |  |
| 365 | `focus_events_key_basic` | 132 | 28.1s |  |
| 366 | `focus_events_key_navigation` | 53 | 6.9s |  |
| 367 | `focus_events_key_same_object` | 26 | 6.6s |  |
| 368 | `focus_events_mixed_key_mouse` | 100 | 27.6s |  |
| 369 | `focus_events_mouse_basic` | 260 | 38.2s |  |
| 370 | `focus_events_mouse_focusable` | 112 | 26.3s |  |
| 371 | `focus_events_mouse_same_object` | 40 | 25.8s |  |
| 372 | `focus_remove` | 20 | 25.9s |  |
| 373 | `focus_root_movie` | 4 | 25.8s |  |
| 374 | `focus_stage` | 1 | 6.5s |  |
| 375 | `focusrect` | 18 | 7.2s |  |
| 376 | `focusrect_focuslost` | 9 | 6.6s |  |
| 377 | `focusrect_property` | 110 | 6.6s |  |
| 378 | `font_description_clone` | 14 | 6.5s |  |
| 379 | `font_embedded` | 24 | 6.9s |  |
| 380 | `font_enumeratefonts` | 41 | 7.2s |  |
| 381 | `font_enumeratefonts_filter` | 4 | 7.3s |  |
| 382 | `font_hasglyphs` | 40 | 6.9s |  |
| 383 | `framelabel_constr` | 5 | 6.6s |  |
| 384 | `function_call` | 12 | 6.6s |  |
| 385 | `function_call_arguments` | 46 | 6.6s |  |
| 386 | `function_call_arguments_enumerate` | 5 | 6.5s |  |
| 387 | `function_call_coercion` | 108 | 6.9s |  |
| 388 | `function_call_default` | 6 | 6.5s |  |
| 389 | `function_call_rest` | 22 | 6.5s |  |
| 390 | `function_call_types` | 3 | 6.5s |  |
| 391 | `function_call_via_apply` | 11 | 6.5s |  |
| 392 | `function_call_via_call` | 3 | 6.5s |  |
| 393 | `function_display_anonymous` | 7 | 3.0s |  |
| 394 | `function_length` | 6 | 6.5s |  |
| 395 | `function_object` | 2 | 6.5s |  |
| 396 | `function_proto` | 5 | 6.5s |  |
| 397 | `function_proto_created` | 61 | 6.5s |  |
| 398 | `function_to_locale_string` | 4 | 6.4s |  |
| 399 | `function_to_string` | 4 | 6.4s |  |
| 400 | `function_type` | 6 | 6.6s |  |
| 401 | `function_unbound_this` | 51 | 6.7s |  |
| 402 | `function_value_of` | 4 | 6.5s |  |
| 403 | `get_definition_by_name` | 11 | 6.4s |  |
| 404 | `get_qualified_class_name` | 20 | 19.3s |  |
| 405 | `get_qualified_super_class_name` | 18 | 6.7s |  |
| 406 | `get_slot_edge_cases` | 1 | 6.5s |  |
| 407 | `get_timer` | 2 | 6.6s |  |
| 408 | `getglobalslot` | 1 | 6.5s |  |
| 409 | `getouterscope` | 8 | 6.6s |  |
| 410 | `getter_different_namespace_setter` | 2 | 6.5s |  |
| 411 | `goto_button_nested_framescript` | 28 | 7.0s |  |
| 412 | `goto_in_constructframe` | 12 | 6.9s |  |
| 413 | `goto_in_scene_last_frame` | 2 | 26.4s |  |
| 414 | `goto_methods` | 56 | 6.9s |  |
| 415 | `goto_methods_swfver10` | 8 | 6.6s |  |
| 416 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 417 | `goto_nested_framescript` | 9 | 6.8s |  |
| 418 | `goto_on_orphan` | 15 | 6.9s |  |
| 419 | `graphics_bad_direct_commands` | 5 | 7.4s |  |
| 420 | `graphics_bitmap_fill` | 0 | 8.6s |  |
| 421 | `graphics_bitmaps` | 0 | 7.4s |  |
| 422 | `graphics_direct_commands` | 0 | 7.3s |  |
| 423 | `graphics_draw_triangles` | 98 | 27.4s |  |
| 424 | `graphics_gradients` | 0 | 7.0s |  |
| 425 | `graphics_gradients_nulls` | 0 | 6.8s |  |
| 426 | `graphics_path` | 56 | 6.7s |  |
| 427 | `graphics_round_rects` | 0 | 6.7s |  |
| 428 | `graphics_simple_shapes` | 0 | 7.0s |  |
| 429 | `greaterequals` | 512 | 11.0s |  |
| 430 | `greaterthan` | 512 | 11.0s |  |
| 431 | `has_own_property` | 102 | 7.2s |  |
| 432 | `hasownproperty_namespaces` | 2 | 6.7s |  |
| 433 | `hello_world` | 1 | 6.6s |  |
| 434 | `hittest_morph` | 30 | 6.8s |  |
| 435 | `if_eq` | 10 | 6.7s |  |
| 436 | `if_gt` | 1 | 6.7s |  |
| 437 | `if_gte` | 10 | 18.5s |  |
| 438 | `if_lt` | 1 | 6.3s |  |
| 439 | `if_lte` | 10 | 6.2s |  |
| 440 | `if_ne` | 7 | 2.9s |  |
| 441 | `if_stricteq` | 6 | 6.2s |  |
| 442 | `if_strictne` | 11 | 6.3s |  |
| 443 | `ime_linux_dead_keys` | 10 | 6.4s |  |
| 444 | `in` | 102 | 6.7s |  |
| 445 | `inclocal` | 46 | 6.3s |  |
| 446 | `inclocal_i` | 46 | 6.3s |  |
| 447 | `increment` | 46 | 6.3s |  |
| 448 | `increment_i` | 46 | 6.3s |  |
| 449 | `indexing_delete` | 75 | 6.2s |  |
| 450 | `instanceof` | 58 | 6.5s |  |
| 451 | `instantiation_on_enter_frame` | 7 | 24.2s |  |
| 452 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.2s |  |
| 453 | `int_constr` | 92 | 6.1s |  |
| 454 | `int_edge_cases` | 19 | 6.3s |  |
| 455 | `int_instanceof` | 3 | 6.2s |  |
| 456 | `int_tofixed` | 1215 | 6.1s |  |
| 457 | `int_tostring` | 3375 | 6.2s |  |
| 458 | `interactiveobject_enabled` | 25 | 6.1s |  |
| 459 | `interface_namespaces` | 78 | 6.4s |  |
| 460 | `is_finite` | 46 | 6.3s |  |
| 461 | `is_nan` | 46 | 6.1s |  |
| 462 | `is_prototype_of` | 12 | 6.3s |  |
| 463 | `issue_10221` | 2 | 6.2s |  |
| 464 | `issue_13780` | 12 | 6.2s |  |
| 465 | `issue_14901` | 1 | 6.2s |  |
| 466 | `issue_17675_edittext_paste_maxchars` | 1 | 6.2s |  |
| 467 | `issue_5292` | 5 | 6.2s |  |
| 468 | `issue_8630` | 2 | 6.2s |  |
| 469 | `issue_8630_scriptremove` | 11 | 6.2s |  |
| 470 | `istype` | 24 | 2.9s |  |
| 471 | `istypelate` | 58 | 6.5s |  |
| 472 | `istypelate_coerce` | 198 | 19.6s |  |
| 473 | `jpeg_loader_context` | 6 | 6.3s |  |
| 474 | `json_errors` | 9 | 25.3s |  |
| 475 | `json_parse` | 21 | 6.5s |  |
| 476 | `json_stringify` | 12 | 6.9s |  |
| 477 | `json_stringify_order` | 1 | 6.5s |  |
| 478 | `json_version_gated` | 1 | 6.3s |  |
| 479 | `key_input_80percent` | 1812 | 6.6s |  |
| 480 | `key_input_location` | 126 | 6.5s |  |
| 481 | `key_input_numpad` | 384 | 6.5s |  |
| 482 | `lazyinit` | 17 | 6.5s |  |
| 483 | `lessequals` | 512 | 10.8s |  |
| 484 | `lessthan` | 512 | 10.7s |  |
| 485 | `loader_bitmap_transparency` | 14 | 6.5s |  |
| 486 | `loader_bytes_unknown_content` | 14 | 6.7s |  |
| 487 | `loader_child_getdefinition` | 5 | 6.7s |  |
| 488 | `loader_duplicate_coerce` | 3 | 6.8s |  |
| 489 | `loader_duplicate_coerce_new_domain` | 4 | 6.7s |  |
| 490 | `loader_error_in_root_ctor` | 4 | 6.9s |  |
| 491 | `loader_events` | 92 | 7.3s |  |
| 492 | `loader_image` | 8 | 6.8s |  |
| 493 | `loader_jpegxr` | 2 | 26.2s |  |
| 494 | `loader_jpegxr_alpha` | 1 | 25.4s |  |
| 495 | `loader_loadbytes_events` | 30 | 7.3s |  |
| 496 | `loader_loadbytes_invalid_png` | 4 | 6.7s |  |
| 497 | `loader_loadbytes_url` | 12 | 7.0s |  |
| 498 | `loader_loaderurl` | 6 | 6.9s |  |
| 499 | `loader_noninteractive_try_click_root` | 5 | 26.0s |  |
| 500 | `loader_reuse` | 38 | 6.9s |  |
| 501 | `loader_unknown_content` | 24 | 6.7s |  |
| 502 | `loader_visibility_interactive` | 1 | 6.7s |  |
| 503 | `loaderinfo_events` | 7 | 6.6s |  |
| 504 | `loaderinfo_loadurl` | 12 | 13.1s |  |
| 505 | `loaderinfo_more` | 6 | 5.0s |  |
| 506 | `loaderinfo_properties` | 18 | 4.6s |  |
| 507 | `loaderinfo_properties_not_loaded` | 23 | 4.5s |  |
| 508 | `loaderinfo_root` | 10 | 4.7s |  |
| 509 | `loaderinfo_root_allows` | 2 | 4.4s |  |
| 510 | `lshift` | 1058 | 12.1s |  |
| 511 | `mask_reapply` | 1 | 4.9s |  |
| 512 | `math` | 497 | 4.8s |  |
| 513 | `missing_external_interface` | 10 | 4.3s |  |
| 514 | `modulo` | 1058 | 12.0s |  |
| 515 | `morph_shape` | 2 | 18.4s |  |
| 516 | `mouse_children` | 192 | 19.2s |  |
| 517 | `mouse_click_events` | 90 | 18.3s |  |
| 518 | `mouse_double_click_events` | 188 | 4.5s |  |
| 519 | `mouse_empty_parent` | 4 | 4.7s |  |
| 520 | `mouse_over_while_dragging` | 3 | 4.6s |  |
| 521 | `mouse_pick_button_mode` | 2 | 4.8s |  |
| 522 | `mouse_pick_dobj_mask` | 4 | 4.8s |  |
| 523 | `mouse_pick_masking` | 7 | 18.6s |  |
| 524 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 18.7s |  |
| 525 | `mouse_pick_non_interactive_dobj_mask` | 3 | 4.9s |  |
| 526 | `mouse_pick_text` | 8 | 5.8s |  |
| 527 | `mouse_sibling` | 8 | 4.6s |  |
| 528 | `mouse_wheel_events` | 36 | 19.3s |  |
| 529 | `mouseevent_constr` | 66 | 4.5s |  |
| 530 | `mouseevent_stagexy` | 35 | 4.4s |  |
| 531 | `mouseevent_valueof_tostring` | 28 | 4.7s |  |
| 532 | `movieclip_addframescript` | 3 | 18.4s |  |
| 533 | `movieclip_child_property` | 16 | 5.0s |  |
| 534 | `movieclip_constr` | 21 | 18.6s |  |
| 535 | `movieclip_currentlabels` | 17 | 25.6s |  |
| 536 | `movieclip_currentlabels_dupes1` | 46 | 26.3s |  |
| 537 | `movieclip_currentlabels_dupes2` | 30 | 6.5s |  |
| 538 | `movieclip_currentlabels_dupes3` | 67 | 6.3s |  |
| 539 | `movieclip_currentscene` | 12 | 6.5s |  |
| 540 | `movieclip_dispatchevent` | 430 | 6.4s |  |
| 541 | `movieclip_dispatchevent_cancel` | 102 | 6.4s |  |
| 542 | `movieclip_dispatchevent_handlerorder` | 251 | 6.3s |  |
| 543 | `movieclip_dispatchevent_selfadd` | 80 | 6.3s |  |
| 544 | `movieclip_dispatchevent_target` | 899 | 6.3s |  |
| 545 | `movieclip_displayevents` | 96 | 26.0s |  |
| 546 | `movieclip_displayevents_clickgoto` | 676 | 6.8s |  |
| 547 | `movieclip_displayevents_clickgoto2` | 2001 | 6.9s |  |
| 548 | `movieclip_displayevents_clickplay` | 575 | 6.6s |  |
| 549 | `movieclip_displayevents_clicksymbol` | 562 | 6.5s |  |
| 550 | `movieclip_displayevents_constructframegoto` | 140 | 7.0s |  |
| 551 | `movieclip_displayevents_constructframeplay` | 50 | 6.9s |  |
| 552 | `movieclip_displayevents_constructframesymbol` | 144 | 7.2s |  |
| 553 | `movieclip_displayevents_dblhandler` | 21 | 7.1s |  |
| 554 | `movieclip_displayevents_enterframegoto` | 149 | 6.8s |  |
| 555 | `movieclip_displayevents_enterframeplay` | 48 | 6.4s |  |
| 556 | `movieclip_displayevents_enterframesymbol` | 149 | 26.6s |  |
| 557 | `movieclip_displayevents_exitframegoto` | 106 | 6.5s |  |
| 558 | `movieclip_displayevents_exitframeplay` | 44 | 6.4s |  |
| 559 | `movieclip_displayevents_exitframesymbol` | 135 | 6.5s |  |
| 560 | `movieclip_displayevents_looping` | 63 | 25.9s |  |
| 561 | `movieclip_displayevents_stopped` | 113 | 6.7s |  |
| 562 | `movieclip_displayevents_swap` | 96 | 2.6s |  |
| 563 | `movieclip_displayevents_timeline` | 128 | 26.1s |  |
| 564 | `movieclip_drawrect` | 54 | 6.2s |  |
| 565 | `movieclip_frameconstruct_skipped` | 9 | 6.4s |  |
| 566 | `movieclip_goto_during_frame_script` | 15 | 6.4s |  |
| 567 | `movieclip_goto_overwrite` | 14 | 25.5s |  |
| 568 | `movieclip_goto_scene_last_frame_int` | 1 | 25.8s |  |
| 569 | `movieclip_goto_scene_last_frame_label` | 1 | 6.1s |  |
| 570 | `movieclip_gotoandplay` | 15 | 25.6s |  |
| 571 | `movieclip_gotoandstop` | 13 | 6.3s |  |
| 572 | `movieclip_gotoandstop_children` | 4 | 6.6s |  |
| 573 | `movieclip_gotoandstop_framescripts1` | 4 | 6.3s |  |
| 574 | `movieclip_gotoandstop_framescripts2` | 4 | 2.7s |  |
| 575 | `movieclip_gotoandstop_framescripts_self` | 7 | 19.1s |  |
| 576 | `movieclip_gotoandstop_queueing` | 12 | 6.6s |  |
| 577 | `movieclip_next_frame` | 2 | 6.6s |  |
| 578 | `movieclip_next_scene` | 6 | 25.3s |  |
| 579 | `movieclip_play` | 3 | 6.3s |  |
| 580 | `movieclip_prev_frame` | 3 | 6.2s |  |
| 581 | `movieclip_prev_scene` | 7 | 6.5s |  |
| 582 | `movieclip_properties` | 79 | 6.7s |  |
| 583 | `movieclip_queued_noop_goto_swf10` | 9 | 6.5s |  |
| 584 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 585 | `movieclip_scenes` | 11 | 6.4s |  |
| 586 | `movieclip_soundtransform` | 831 | 27.9s |  |
| 587 | `movieclip_stop` | 1 | 6.4s |  |
| 588 | `movieclip_super_is_symbol` | 20 | 6.8s |  |
| 589 | `movieclip_symbol_constr` | 8 | 6.6s |  |
| 590 | `movieclip_text_mousedown` | 1 | 6.5s |  |
| 591 | `movieclip_willtrigger` | 5 | 6.7s |  |
| 592 | `multiply` | 1058 | 18.8s |  |
| 593 | `namespace_constr` | 253 | 6.8s |  |
| 594 | `namespace_constr_args` | 1 | 6.4s |  |
| 595 | `namespace_enumeration_order` | 7 | 6.5s |  |
| 596 | `nan_scale` | 9 | 6.5s |  |
| 597 | `navigateToURL_target_normalize` | 107 | 26.9s |  |
| 598 | `negate` | 30 | 6.5s |  |
| 599 | `negative_volume_panned` | 0 | 6.6s |  |
| 600 | `nested_iteration` | 11 | 6.4s |  |
| 601 | `net_getClassByAlias` | 3 | 6.3s |  |
| 602 | `net_navigateToURL` | 57 | 6.4s |  |
| 603 | `newactivation_in_script_init` | 3 | 6.6s |  |
| 604 | `newclass_twice` | 3 | 6.5s |  |
| 605 | `nonconflicting_declarations` | 0 | 6.6s |  |
| 606 | `null_void_types` | 8 | 6.6s |  |
| 607 | `number_autoconv` | 21 | 6.6s |  |
| 608 | `number_autoconv_amf` | 132 | 6.6s |  |
| 609 | `number_autoconv_array_sort_32bit` | 1 | 6.5s |  |
| 610 | `number_constr` | 58 | 6.7s |  |
| 611 | `number_toexponential` | 378 | 6.6s |  |
| 612 | `number_toexponential2` | 35 | 6.5s |  |
| 613 | `number_tofixed` | 378 | 6.5s |  |
| 614 | `number_toprecision` | 350 | 6.6s |  |
| 615 | `obfuscated_class_names` | 3 | 6.5s |  |
| 616 | `object_enumeration` | 10 | 6.5s |  |
| 617 | `object_prototype` | 4 | 6.5s |  |
| 618 | `object_to_locale_string` | 2 | 6.5s |  |
| 619 | `object_to_string` | 2 | 6.5s |  |
| 620 | `object_value_of` | 2 | 2.9s |  |
| 621 | `op_coerce` | 54 | 6.6s |  |
| 622 | `op_coerce_x` | 54 | 6.5s |  |
| 623 | `op_escxattr` | 2 | 6.5s |  |
| 624 | `op_escxelem` | 2 | 6.5s |  |
| 625 | `op_lookupswitch` | 4 | 6.5s |  |
| 626 | `optimize_coerce` | 1 | 6.4s |  |
| 627 | `orphan_movie_complex` | 80 | 6.9s |  |
| 628 | `orphan_movie_reorder` | 111 | 25.7s |  |
| 629 | `package_namespace` | 7 | 6.4s |  |
| 630 | `param_default_value_has_zero_cpool_index` | 1 | 6.5s |  |
| 631 | `parent_early_access_child` | 16 | 6.9s |  |
| 632 | `parse_float` | 81 | 6.8s |  |
| 633 | `pixelbender_effect_BlurredFocus` | 0 | 29.1s |  |
| 634 | `pixelbender_effect_glassDisplace` | 0 | 11.8s |  |
| 635 | `pixelbender_effect_smudge` | 0 | 9.6s |  |
| 636 | `pixelbender_effect_tintype` | 0 | 8.7s |  |
| 637 | `pixelbender_effect_twirl` | 0 | 9.9s |  |
| 638 | `pixelbender_images` | 0 | 8.2s |  |
| 639 | `place_multiple` | 17 | 6.1s |  |
| 640 | `place_object_replace` | 9 | 6.2s |  |
| 641 | `place_object_replace_2` | 24 | 6.2s |  |
| 642 | `place_object_same_depth_frame` | 1 | 6.0s |  |
| 643 | `point` | 132 | 6.5s |  |
| 644 | `primitive_edge_cases` | 1 | 5.8s |  |
| 645 | `property_priority` | 22 | 6.8s |  |
| 646 | `property_priority_three_level` | 6 | 6.6s |  |
| 647 | `propertyisenumerable_namespaces` | 6 | 6.5s |  |
| 648 | `prototype_set_null` | 7 | 6.4s |  |
| 649 | `proxy_callproperty` | 24 | 6.5s |  |
| 650 | `proxy_deleteproperty` | 64 | 6.6s |  |
| 651 | `proxy_enumeration` | 34 | 6.5s |  |
| 652 | `proxy_getproperty` | 77 | 6.6s |  |
| 653 | `proxy_hasownproperty` | 8 | 6.5s |  |
| 654 | `proxy_hasproperty` | 32 | 6.5s |  |
| 655 | `proxy_serialize` | 9 | 6.5s |  |
| 656 | `proxy_setproperty` | 42 | 6.5s |  |
| 657 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.4s |  |
| 658 | `qname_constr` | 32 | 6.6s |  |
| 659 | `qname_constr_namespace` | 24 | 6.5s |  |
| 660 | `qname_enumeration` | 9 | 6.5s |  |
| 661 | `qname_indexing` | 23 | 6.5s |  |
| 662 | `qname_tostring` | 25 | 6.5s |  |
| 663 | `qname_valueof` | 29 | 6.5s |  |
| 664 | `regexp_constr` | 148 | 6.7s |  |
| 665 | `regexp_exec` | 19 | 6.5s |  |
| 666 | `regexp_extended` | 47 | 6.5s |  |
| 667 | `regexp_multiargs` | 1 | 6.4s |  |
| 668 | `regexp_test` | 27 | 6.5s |  |
| 669 | `regexp_toString` | 10 | 6.5s |  |
| 670 | `register_script_refresh` | 35 | 7.0s |  |
| 671 | `remove_child_clear_field` | 88 | 6.9s |  |
| 672 | `remove_dobj` | 3 | 6.5s |  |
| 673 | `resolve_order` | 4 | 6.5s |  |
| 674 | `rng` | 1 | 7.8s |  |
| 675 | `rootless` | 42 | 6.6s |  |
| 676 | `rshift` | 1058 | 17.7s |  |
| 677 | `sandbox_type_inherited` | 2 | 18.7s |  |
| 678 | `sandbox_type_local_file` | 1 | 6.6s |  |
| 679 | `scene_constr` | 8 | 6.4s |  |
| 680 | `selection` | 239 | 6.8s |  |
| 681 | `set_local_0` | 31 | 6.4s |  |
| 682 | `set_property_is_enumerable` | 85 | 6.8s |  |
| 683 | `shape_drawrect` | 54 | 6.4s |  |
| 684 | `shared_object_no_root` | 3 | 6.3s |  |
| 685 | `simplebutton_added_to_stage` | 45 | 24.9s |  |
| 686 | `simplebutton_childevents` | 86 | 6.8s |  |
| 687 | `simplebutton_childevents_nested` | 54 | 6.6s |  |
| 688 | `simplebutton_childevents_sprite` | 13 | 6.4s |  |
| 689 | `simplebutton_childprops` | 144 | 6.5s |  |
| 690 | `simplebutton_childshuffle` | 23 | 6.2s |  |
| 691 | `simplebutton_constr` | 36 | 6.6s |  |
| 692 | `simplebutton_constr_childevents` | 48 | 6.6s |  |
| 693 | `simplebutton_constr_params` | 42 | 6.4s |  |
| 694 | `simplebutton_mouseenabled` | 26 | 6.3s |  |
| 695 | `simplebutton_multi_children` | 19 | 6.5s |  |
| 696 | `simplebutton_structure` | 27 | 6.5s |  |
| 697 | `simplebutton_symbolclass` | 68 | 6.8s |  |
| 698 | `slot_disp_id_shared_numbering` | 1 | 24.3s |  |
| 699 | `slots_force_autoassigned` | 1 | 6.3s |  |
| 700 | `sound_embeddedprops` | 26 | 6.7s |  |
| 701 | `sound_play` | 19 | 6.6s |  |
| 702 | `sound_valueof` | 33 | 6.5s |  |
| 703 | `soundchannel_soundtransform` | 835 | 27.1s |  |
| 704 | `soundchannel_soundtransform_exists` | 5 | 24.9s |  |
| 705 | `soundchannel_stop` | 8 | 6.5s |  |
| 706 | `soundmixer_buffertime` | 5 | 6.3s |  |
| 707 | `soundmixer_stopall` | 6 | 6.3s |  |
| 708 | `soundtransform` | 442 | 12.0s |  |
| 709 | `sprite_with_frames` | 0 | 6.9s |  |
| 710 | `stage3d_agal_cross_product` | 0 | 8.9s |  |
| 711 | `stage3d_bitmap` | 0 | 29.8s |  |
| 712 | `stage3d_float1_index` | 0 | 27.2s |  |
| 713 | `stage3d_fractal` | 0 | 27.6s |  |
| 714 | `stage3d_ignore_sampler_override` | 0 | 27.5s |  |
| 715 | `stage3d_program_constants_bytearray_be` | 0 | 28.6s |  |
| 716 | `stage3d_program_constants_bytearray_le` | 0 | 9.6s |  |
| 717 | `stage3d_raytrace` | 0 | 31.4s |  |
| 718 | `stage3d_rotating_cube` | 0 | 9.9s |  |
| 719 | `stage3d_sampler` | 0 | 15.7s |  |
| 720 | `stage3d_sampler_partial_upload` | 0 | 6.8s |  |
| 721 | `stage3d_stencil` | 0 | 20.9s |  |
| 722 | `stage3d_texture` | 0 | 9.6s |  |
| 723 | `stage3d_texture_bytearray` | 0 | 7.2s |  |
| 724 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 7.0s |  |
| 725 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 8.0s |  |
| 726 | `stage3d_triangle` | 0 | 6.3s |  |
| 727 | `stage3d_triangle_bytes4` | 0 | 6.4s |  |
| 728 | `stage3d_triangle_float1` | 0 | 6.2s |  |
| 729 | `stage3d_triangle_index_upload` | 0 | 6.8s |  |
| 730 | `stage_access` | 10 | 4.6s |  |
| 731 | `stage_displayobject_properties` | 24 | 4.3s |  |
| 732 | `stage_framerate_nan` | 7 | 4.8s |  |
| 733 | `stage_framerate_negative` | 6 | 4.6s |  |
| 734 | `stage_framerate_zero` | 6 | 4.6s |  |
| 735 | `stage_invalidate` | 38 | 4.7s |  |
| 736 | `stage_loaderinfo_properties` | 24 | 5.0s |  |
| 737 | `stage_mousechildren` | 2 | 4.5s |  |
| 738 | `stage_mouseenabled` | 15 | 4.5s |  |
| 739 | `stage_overriden_setters` | 31 | 4.3s |  |
| 740 | `stage_properties` | 30 | 4.4s |  |
| 741 | `static_var_with_this_in_ctor` | 2 | 4.7s |  |
| 742 | `stored_properties` | 11 | 4.6s |  |
| 743 | `strict_equality` | 34 | 4.5s |  |
| 744 | `string_call` | 13 | 4.4s |  |
| 745 | `string_case` | 23 | 4.4s |  |
| 746 | `string_char_at` | 27 | 4.3s |  |
| 747 | `string_char_code_at` | 28 | 4.3s |  |
| 748 | `string_concat_fromcharcode` | 37 | 4.4s |  |
| 749 | `string_constr` | 25 | 4.5s |  |
| 750 | `string_indexof_lastindexof` | 87 | 15.2s |  |
| 751 | `string_length` | 16 | 5.3s |  |
| 752 | `string_locale_compare` | 39 | 5.7s |  |
| 753 | `string_match` | 51 | 5.6s |  |
| 754 | `string_relational_compare` | 4 | 5.4s |  |
| 755 | `string_replace` | 51 | 5.5s |  |
| 756 | `string_search` | 41 | 5.4s |  |
| 757 | `string_slice_substr_substring` | 170 | 6.3s |  |
| 758 | `string_split` | 29 | 5.4s |  |
| 759 | `string_substr_negative` | 21 | 5.4s |  |
| 760 | `string_substr_weird` | 182 | 5.5s |  |
| 761 | `subtract` | 1058 | 14.8s |  |
| 762 | `super_get_call` | 12 | 5.5s |  |
| 763 | `supercall_two_classobjects` | 2 | 5.5s |  |
| 764 | `swf8` | 1 | 5.5s |  |
| 765 | `swf_10_queued_goto_scripts_construct` | 52 | 5.9s |  |
| 766 | `swf_9_goto_in_enter_frame` | 17 | 5.8s |  |
| 767 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.1s |  |
| 768 | `swf_9_queued_goto_scripts` | 6 | 5.5s |  |
| 769 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 770 | `swf_9_versioning` | 2 | 5.5s |  |
| 771 | `swf_wrong_frame_count` | 38 | 5.6s |  |
| 772 | `swf_wrong_frame_count_isplaying` | 22 | 5.7s |  |
| 773 | `symbol_class_binary_data` | 8 | 5.4s |  |
| 774 | `symbol_class_conflict` | 4 | 5.8s |  |
| 775 | `symbol_class_root_not_zero` | 1 | 5.5s |  |
| 776 | `symbolclass_invalid_utf8` | 2 | 5.5s |  |
| 777 | `tab_ordering_automatic_advanced` | 184 | 7.0s |  |
| 778 | `tab_ordering_automatic_basic` | 45 | 6.2s |  |
| 779 | `tab_ordering_children` | 116 | 6.3s |  |
| 780 | `tab_ordering_custom_basic` | 34 | 6.2s |  |
| 781 | `tab_ordering_stage_tab_children` | 32 | 6.2s |  |
| 782 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.1s |  |
| 783 | `tab_ordering_tabbable` | 47 | 6.2s |  |
| 784 | `text_engine_fontdescription` | 27 | 6.3s |  |
| 785 | `text_run` | 7 | 6.0s |  |
| 786 | `textbox_click` | 37 | 24.2s |  |
| 787 | `textfield_event` | 66 | 6.4s |  |
| 788 | `textfield_focusin_event` | 9 | 6.1s |  |
| 789 | `textfield_input_dead_keys_windows` | 15 | 6.2s |  |
| 790 | `textfield_unload` | 39 | 24.1s |  |
| 791 | `textformat` | 1134 | 6.2s |  |
| 792 | `textformat_display` | 14 | 6.2s |  |
| 793 | `textformat_font_max_length` | 4 | 6.1s |  |
| 794 | `throw` | 3 | 6.1s |  |
| 795 | `timeline_scripts` | 3 | 6.3s |  |
| 796 | `timer` | 90 | 7.1s |  |
| 797 | `timer_events` | 3 | 6.3s |  |
| 798 | `timer_finished` | 11 | 6.3s |  |
| 799 | `timer_reset` | 8 | 6.5s |  |
| 800 | `timer_setdelay` | 5 | 6.3s |  |
| 801 | `trace` | 12 | 6.1s |  |
| 802 | `truthiness` | 30 | 18.2s |  |
| 803 | `try_catch` | 11 | 5.2s |  |
| 804 | `try_catch_typed` | 12 | 5.2s |  |
| 805 | `typeof` | 30 | 5.1s |  |
| 806 | `uint_constr` | 92 | 5.2s |  |
| 807 | `uint_tofixed` | 1215 | 5.1s |  |
| 808 | `uint_tostring` | 3375 | 5.1s |  |
| 809 | `unchecked_function` | 15 | 5.1s |  |
| 810 | `unescape` | 28 | 5.1s |  |
| 811 | `url_loader` | 25 | 5.1s |  |
| 812 | `urlrequest` | 18 | 5.2s |  |
| 813 | `urshift` | 1058 | 5.1s |  |
| 814 | `vector_class` | 36 | 5.2s |  |
| 815 | `vector_class_call` | 11 | 5.2s |  |
| 816 | `vector_coercion` | 66 | 5.4s |  |
| 817 | `vector_concat` | 90 | 5.2s |  |
| 818 | `vector_constr` | 107 | 5.3s |  |
| 819 | `vector_enumeration` | 5 | 5.4s |  |
| 820 | `vector_every` | 92 | 5.3s |  |
| 821 | `vector_filter` | 95 | 5.2s |  |
| 822 | `vector_holes` | 24 | 5.2s |  |
| 823 | `vector_indexof` | 302 | 5.3s |  |
| 824 | `vector_insertat` | 270 | 5.3s |  |
| 825 | `vector_int_access` | 4 | 5.3s |  |
| 826 | `vector_int_delete` | 11 | 5.2s |  |
| 827 | `vector_join` | 58 | 5.3s |  |
| 828 | `vector_lastindexof` | 302 | 5.2s |  |
| 829 | `vector_legacy` | 10 | 5.2s |  |
| 830 | `vector_map` | 85 | 5.0s |  |
| 831 | `vector_object_final` | 1 | 5.1s |  |
| 832 | `vector_object_toString` | 10 | 5.1s |  |
| 833 | `vector_pushpop` | 255 | 5.0s |  |
| 834 | `vector_reborrow_bug` | 10 | 18.9s |  |
| 835 | `vector_removeat` | 172 | 7.5s |  |
| 836 | `vector_reverse` | 232 | 7.6s |  |
| 837 | `vector_shiftunshift` | 252 | 6.4s |  |
| 838 | `vector_slice` | 331 | 8.1s |  |
| 839 | `vector_sort` | 905 | 15.2s |  |
| 840 | `vector_splice` | 693 | 10.1s |  |
| 841 | `vector_splice_fixed_bug_compat` | 4 | 6.5s |  |
| 842 | `vector_tostring` | 79 | 7.1s |  |
| 843 | `verify_abnormal_loop` | 1 | 6.4s |  |
| 844 | `verify_exception_targets_edge_case` | 1 | 6.4s |  |
| 845 | `verify_lookup_switch_edge_case` | 1 | 6.3s |  |
| 846 | `verify_unreachable_exception` | 2 | 6.6s |  |
| 847 | `versioned_isplaying` | 2 | 6.5s |  |
| 848 | `virtual_properties` | 16 | 6.6s |  |
| 849 | `with` | 4 | 6.5s |  |
| 850 | `wrong_arg_count` | 7 | 6.7s |  |
| 851 | `xml_abstract_equality` | 36 | 6.8s |  |
| 852 | `xml_advanced` | 52 | 6.5s |  |
| 853 | `xml_appendchild` | 10 | 6.5s |  |
| 854 | `xml_as_attribute` | 9 | 6.5s |  |
| 855 | `xml_attribute` | 35 | 6.7s |  |
| 856 | `xml_attribute_name` | 40 | 6.6s |  |
| 857 | `xml_basic` | 33 | 6.6s |  |
| 858 | `xml_child` | 25 | 6.6s |  |
| 859 | `xml_childindex` | 7 | 6.5s |  |
| 860 | `xml_children` | 43 | 7.1s |  |
| 861 | `xml_class_call` | 9 | 6.6s |  |
| 862 | `xml_contains` | 197 | 6.7s |  |
| 863 | `xml_copy` | 20 | 19.4s |  |
| 864 | `xml_ctor_from_tostring` | 23 | 7.1s |  |
| 865 | `xml_delete` | 114 | 6.9s |  |
| 866 | `xml_descendants` | 83 | 6.8s |  |
| 867 | `xml_elements` | 6 | 6.7s |  |
| 868 | `xml_equals_namespace_check` | 2 | 6.7s |  |
| 869 | `xml_explicit_use_namespace` | 5 | 6.7s |  |
| 870 | `xml_getdescendants_qname` | 21 | 6.6s |  |
| 871 | `xml_has_property_via_in` | 26 | 6.7s |  |
| 872 | `xml_hasownproperty` | 6 | 6.6s |  |
| 873 | `xml_ignore_white` | 6 | 6.6s |  |
| 874 | `xml_length` | 2 | 6.4s |  |
| 875 | `xml_list_as_attribute` | 9 | 6.4s |  |
| 876 | `xml_list_concat` | 20 | 6.6s |  |
| 877 | `xml_list_enumerate` | 4 | 6.5s |  |
| 878 | `xml_methods_settings` | 3 | 6.5s |  |
| 879 | `xml_mismatched_tag` | 37 | 6.6s |  |
| 880 | `xml_namespace` | 39 | 6.6s |  |
| 881 | `xml_namespace_methods` | 245 | 6.6s |  |
| 882 | `xml_namespaced_property` | 7 | 6.5s |  |
| 883 | `xml_no_namespace` | 1 | 6.5s |  |
| 884 | `xml_nodekind` | 3 | 6.5s |  |
| 885 | `xml_normalize` | 35 | 6.7s |  |
| 886 | `xml_notification_bubbling` | 361 | 6.6s |  |
| 887 | `xml_parent` | 8 | 6.6s |  |
| 888 | `xml_set_children` | 17 | 6.7s |  |
| 889 | `xml_set_name` | 34 | 6.7s |  |
| 890 | `xml_settings` | 6 | 3.1s |  |
| 891 | `xml_simple_complex_content` | 47 | 6.7s |  |
| 892 | `xml_text` | 7 | 6.7s |  |
| 893 | `xml_tostring` | 6 | 6.6s |  |
| 894 | `xml_tostring_namespace` | 12 | 6.5s |  |
| 895 | `xml_unescaping` | 23 | 6.7s |  |
| 896 | `xml_weird_ignores` | 54 | 6.7s |  |
| 897 | `xml_wildcard` | 11 | 6.7s |  |
| 898 | `xmldocument` | 254 | 6.6s |  |
| 899 | `xmlnode` | 3540 | 6.8s |  |
| 900 | `zero_frame_clip` | 3 | 7.2s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 5.9s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.5s |  |
| 3 | `blend_transform` | 1 | 1 | 6.8s |  |
| 4 | `coerce_property` | 3 | 3 | 5.5s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.9s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 6.6s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.0s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 37.1s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.4s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.5s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.6s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 6.4s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 6.8s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 27.3s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.2s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.1s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.5s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.2s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 6.3s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.1s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.7s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.3s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 5.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.1s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.0s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 6.5s |  |

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
| 1 | `method_without_body` | exit code 1 | 18.3s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.4s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.4s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**292 tests** with output mismatch, sorted by match rate (best first)

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
| 64 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 65 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 66 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 67 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 68 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 69 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 70 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 71 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 72 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 73 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 74 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 75 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 76 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 77 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 78 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 79 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 80 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 81 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 82 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 83 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 84 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 85 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 86 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 87 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 88 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 89 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 90 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 91 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 92 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 93 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 94 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 95 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 96 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 97 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 98 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 99 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 100 | `localconnection` | 7.5% | 67/890 | 623 | 890 |  |
| 101 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 102 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 103 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 104 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 105 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 106 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 107 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 108 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 109 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 110 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 111 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 112 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 113 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 114 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 115 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 116 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 117 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 118 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 119 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 120 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 121 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 122 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 123 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 124 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 125 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 126 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 127 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 128 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 129 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 130 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 131 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 132 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 133 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 134 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 135 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 136 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 137 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 138 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 139 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 140 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 141 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 142 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 143 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 144 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 145 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 146 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 147 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 148 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 149 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 150 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 151 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 152 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 153 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 154 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 155 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 156 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 157 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 158 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 159 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 160 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 161 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 162 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 163 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 164 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 165 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 166 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 167 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 168 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 169 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 170 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 171 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 172 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 173 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 174 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 175 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 176 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 177 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 178 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 179 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 180 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 181 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 182 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 183 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 184 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 185 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 186 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 187 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 188 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 189 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 190 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 191 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 192 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 193 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 194 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 195 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 196 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 197 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 198 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 199 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 200 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 201 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 202 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 203 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 204 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 205 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 206 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 207 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 208 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 209 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 210 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 211 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 212 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 213 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 214 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 215 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 216 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 217 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 218 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 219 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 220 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 221 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 222 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 223 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 224 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 225 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 226 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 227 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 228 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 229 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 230 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 231 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 232 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 233 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 234 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 235 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 236 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 237 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 238 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 239 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 240 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 241 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 242 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 243 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 244 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 245 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 246 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 247 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 248 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 249 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 250 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 251 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 252 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 253 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 254 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 255 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 256 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 257 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 258 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 259 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 260 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 261 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 262 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 263 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 264 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 265 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 266 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 267 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 268 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 269 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 270 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 271 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 273 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 274 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 275 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 276 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 277 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 278 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 279 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 280 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 281 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 282 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 283 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 284 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 285 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 286 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 287 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 288 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 289 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 290 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 291 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 292 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
