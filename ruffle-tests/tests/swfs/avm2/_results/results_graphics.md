# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-28 17:38 UTC

**Git SHA**: `9263f71a0b`

**Run Duration**: 169m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **886** (72.6%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **912** (74.7%) |
| Failing | 309 |
| Total expected lines | 151253 |
| Matching lines | 105770 (69.9%) |
| Mismatched lines | 45483 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 306 | 99.0% |
| Runtime Error | 3 | 1.0% |

## Passing Tests

**886 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 19.2s |  |
| 2 | `agal_compiler` | 13 | 9.4s |  |
| 3 | `air_hidden_lookup` | 2 | 6.7s |  |
| 4 | `all_classes/security/swf11` | 3 | 6.7s |  |
| 5 | `amf_custom_obj` | 26 | 6.8s |  |
| 6 | `amf_dictionary` | 9 | 6.6s |  |
| 7 | `amf_function` | 46 | 6.8s |  |
| 8 | `amf_invalid_date` | 2 | 6.7s |  |
| 9 | `amf_missing_prop` | 6 | 6.7s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.8s |  |
| 11 | `amf_setter_error` | 8 | 7.0s |  |
| 12 | `amf_vector` | 40 | 6.9s |  |
| 13 | `amf_xml` | 6 | 6.8s |  |
| 14 | `application_domain` | 4 | 6.8s |  |
| 15 | `array_access` | 18 | 6.8s |  |
| 16 | `array_access_interpreter` | 4 | 6.8s |  |
| 17 | `array_access_no_pubns` | 2 | 6.7s |  |
| 18 | `array_concat` | 41 | 6.8s |  |
| 19 | `array_constr` | 10 | 6.7s |  |
| 20 | `array_delete` | 44 | 6.9s |  |
| 21 | `array_enumeration` | 10 | 6.8s |  |
| 22 | `array_enumeration_elements` | 11 | 6.6s |  |
| 23 | `array_every` | 8 | 6.5s |  |
| 24 | `array_filter` | 6 | 6.5s |  |
| 25 | `array_foreach` | 18 | 6.5s |  |
| 26 | `array_hasownproperty` | 11 | 3.3s |  |
| 27 | `array_holes` | 9 | 6.6s |  |
| 28 | `array_index_max` | 84 | 6.5s |  |
| 29 | `array_indexof` | 25 | 6.5s |  |
| 30 | `array_join` | 26 | 6.6s |  |
| 31 | `array_lastindexof` | 29 | 6.6s |  |
| 32 | `array_length` | 14 | 6.5s |  |
| 33 | `array_literal` | 3 | 6.6s |  |
| 34 | `array_map` | 8 | 6.5s |  |
| 35 | `array_pop` | 52 | 6.8s |  |
| 36 | `array_push` | 24 | 6.7s |  |
| 37 | `array_reborrow_bug` | 6 | 6.6s |  |
| 38 | `array_reverse` | 28 | 6.6s |  |
| 39 | `array_shift` | 51 | 3.2s |  |
| 40 | `array_slice` | 39 | 6.5s |  |
| 41 | `array_some` | 8 | 6.5s |  |
| 42 | `array_sort` | 297 | 6.9s |  |
| 43 | `array_sort_fun_swf12` | 2 | 6.6s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 45 | `array_sort_random` | 210 | 6.6s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 6.4s |  |
| 47 | `array_sorton` | 545 | 7.1s |  |
| 48 | `array_sparse_ops` | 41 | 6.5s |  |
| 49 | `array_splice` | 133 | 6.6s |  |
| 50 | `array_splice2` | 428 | 6.7s |  |
| 51 | `array_splice_types` | 48 | 6.5s |  |
| 52 | `array_storage` | 8 | 6.4s |  |
| 53 | `array_tolocalestring` | 9 | 6.4s |  |
| 54 | `array_tostring` | 12 | 6.4s |  |
| 55 | `array_unshift` | 24 | 6.4s |  |
| 56 | `array_valueof` | 9 | 6.3s |  |
| 57 | `array_vector_null_callback` | 10 | 6.4s |  |
| 58 | `astype` | 28 | 6.4s |  |
| 59 | `astypelate` | 24 | 6.5s |  |
| 60 | `astypelate_propagates` | 1 | 6.3s |  |
| 61 | `asymmetric_key_events` | 11 | 6.6s |  |
| 62 | `avm2_catchup_dobj` | 158 | 7.0s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 80.2s |  |
| 64 | `bitand` | 1058 | 17.6s |  |
| 65 | `bitmap_constr` | 17 | 6.6s |  |
| 66 | `bitmap_data` | 1000 | 14.2s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 25.5s |  |
| 68 | `bitmap_properties` | 23 | 6.5s |  |
| 69 | `bitmap_subclass` | 7 | 7.9s |  |
| 70 | `bitmap_subclass_properties` | 9 | 7.0s |  |
| 71 | `bitmap_timeline` | 9 | 6.6s |  |
| 72 | `bitmapdata_accuracy` | 1 | 44.4s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 26.0s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.3s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 25.6s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.9s |  |
| 77 | `bitmapdata_clone` | 13 | 6.7s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.9s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 6.3s |  |
| 80 | `bitmapdata_constr` | 22 | 6.5s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 6.7s |  |
| 82 | `bitmapdata_copychannel` | 0 | 23.0s |  |
| 83 | `bitmapdata_copypixels` | 23 | 21.9s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 5.2s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 5.1s |  |
| 86 | `bitmapdata_dispose` | 7 | 5.0s |  |
| 87 | `bitmapdata_draw` | 0 | 21.1s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 5.0s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 20.5s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 20.2s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 4.9s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 5.1s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 5.1s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 20.4s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 5.0s |  |
| 96 | `bitmapdata_embedded` | 9 | 5.1s |  |
| 97 | `bitmapdata_fillrect` | 0 | 5.1s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 20.5s |  |
| 99 | `bitmapdata_floodfill` | 35 | 4.9s |  |
| 100 | `bitmapdata_getpixels` | 39 | 20.3s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.1s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.1s |  |
| 103 | `bitmapdata_hittest` | 112 | 5.4s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 4.9s |  |
| 105 | `bitmapdata_opaque` | 0 | 5.0s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 5.5s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 5.2s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 4.8s |  |
| 109 | `bitmapdata_setpixels` | 286 | 5.6s |  |
| 110 | `bitmapdata_setvector` | 26 | 4.9s |  |
| 111 | `bitmapdata_sync` | 0 | 4.9s |  |
| 112 | `bitmapdata_threshold` | 176 | 5.6s |  |
| 113 | `bitnot` | 46 | 4.9s |  |
| 114 | `bitor` | 1058 | 12.8s |  |
| 115 | `bitxor` | 1058 | 12.8s |  |
| 116 | `blend_multiply_alpha` | 0 | 5.0s |  |
| 117 | `blend_scroll` | 0 | 5.2s |  |
| 118 | `boolean_constr` | 32 | 6.4s |  |
| 119 | `boolean_negation` | 30 | 6.4s |  |
| 120 | `boolean_tostring` | 8 | 6.3s |  |
| 121 | `broadcast_event` | 7 | 6.3s |  |
| 122 | `button_nested_frame` | 48 | 6.7s |  |
| 123 | `bytearray` | 48 | 6.6s |  |
| 124 | `bytearray_compress` | 31 | 6.4s |  |
| 125 | `bytearray_errors` | 24 | 6.5s |  |
| 126 | `bytearray_method_serialization` | 1 | 6.5s |  |
| 127 | `bytearray_oom` | 3 | 6.4s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 6.5s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 6.6s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 6.5s |  |
| 131 | `bytearray_serialization` | 3 | 6.3s |  |
| 132 | `bytearray_string_null` | 19 | 6.6s |  |
| 133 | `bytearray_tostring` | 15 | 6.4s |  |
| 134 | `bytearray_utf16` | 8 | 6.3s |  |
| 135 | `bytearray_writeobject` | 24 | 6.3s |  |
| 136 | `callee_in_initializer` | 6 | 6.4s |  |
| 137 | `callproplex_class` | 1 | 6.5s |  |
| 138 | `capabilities_resolution` | 8 | 26.7s |  |
| 139 | `catch_class` | 6 | 6.5s |  |
| 140 | `catch_scope_slot` | 7 | 3.2s |  |
| 141 | `checkfilter` | 4 | 3.1s |  |
| 142 | `class_call` | 32 | 6.6s |  |
| 143 | `class_cast_call` | 14 | 6.4s |  |
| 144 | `class_enumeration` | 4 | 6.5s |  |
| 145 | `class_has_own_property` | 2 | 6.4s |  |
| 146 | `class_init_interpreter_mode` | 1 | 6.3s |  |
| 147 | `class_is` | 32 | 6.6s |  |
| 148 | `class_methods` | 5 | 6.4s |  |
| 149 | `class_object_properties` | 10 | 6.5s |  |
| 150 | `class_singleton` | 18 | 6.5s |  |
| 151 | `class_supercalls_errors` | 35 | 6.7s |  |
| 152 | `class_supercalls_mismatched` | 26 | 6.5s |  |
| 153 | `class_superclass_wrong_order` | 1 | 6.4s |  |
| 154 | `class_to_locale_string` | 2 | 6.4s |  |
| 155 | `class_to_string` | 2 | 6.4s |  |
| 156 | `class_value_of` | 2 | 6.5s |  |
| 157 | `click_block` | 5 | 26.0s |  |
| 158 | `click_invisible` | 3 | 6.5s |  |
| 159 | `closures` | 12 | 6.5s |  |
| 160 | `coerce_return_type` | 40 | 6.8s |  |
| 161 | `coerce_return_type_fail` | 2 | 6.5s |  |
| 162 | `coerce_return_void` | 3 | 6.4s |  |
| 163 | `coerce_string` | 86 | 6.6s |  |
| 164 | `coerce_string_precision` | 28 | 6.5s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 6.7s |  |
| 166 | `construct_errors_swf10` | 8 | 6.5s |  |
| 167 | `construct_frame_list` | 22 | 6.6s |  |
| 168 | `constructor_call` | 3 | 6.3s |  |
| 169 | `constructors_vs_timeline` | 5 | 25.3s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 6.5s |  |
| 171 | `control_flow_bool` | 4 | 6.2s |  |
| 172 | `control_flow_stricteq` | 8 | 6.3s |  |
| 173 | `convert_boolean` | 30 | 6.3s |  |
| 174 | `convert_integer` | 90 | 6.3s |  |
| 175 | `convert_number` | 56 | 6.5s |  |
| 176 | `convert_uinteger` | 90 | 6.6s |  |
| 177 | `cross_api_version_call_older` | 12 | 6.9s |  |
| 178 | `cryptscore` | 11 | 6.6s |  |
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
| 195 | `dictionary_primitive_keys` | 29 | 6.2s |  |
| 196 | `displayobject_alpha` | 277 | 6.1s |  |
| 197 | `displayobject_blendmode` | 0 | 6.2s |  |
| 198 | `displayobject_colortransform_nested` | 0 | 24.8s |  |
| 199 | `displayobject_from_enterframe` | 1 | 6.3s |  |
| 200 | `displayobject_getbounds_shape` | 0 | 24.5s |  |
| 201 | `displayobject_height` | 6052 | 24.6s |  |
| 202 | `displayobject_hittestobject` | 32 | 6.3s |  |
| 203 | `displayobject_invalid_floats` | 60 | 6.2s |  |
| 204 | `displayobject_invalid_props` | 3 | 6.2s |  |
| 205 | `displayobject_mask` | 3 | 6.4s |  |
| 206 | `displayobject_mask_self_referential` | 0 | 6.5s |  |
| 207 | `displayobject_metaData` | 3 | 6.3s |  |
| 208 | `displayobject_name` | 22 | 6.8s |  |
| 209 | `displayobject_name_from_timeline` | 24 | 6.6s |  |
| 210 | `displayobject_parent` | 12 | 6.4s |  |
| 211 | `displayobject_root` | 24 | 6.5s |  |
| 212 | `displayobject_rotation` | 1284 | 6.4s |  |
| 213 | `displayobject_set_matrix_nested` | 0 | 26.1s |  |
| 214 | `displayobject_set_name_loaded` | 3 | 6.8s |  |
| 215 | `displayobject_subclass` | 2 | 6.5s |  |
| 216 | `displayobject_visible` | 23 | 6.3s |  |
| 217 | `displayobject_width` | 4852 | 25.6s |  |
| 218 | `displayobject_x` | 614 | 6.4s |  |
| 219 | `displayobject_y` | 617 | 6.5s |  |
| 220 | `displayobjectcontainer_addchild` | 32 | 6.6s |  |
| 221 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.5s |  |
| 222 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.7s |  |
| 223 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.6s |  |
| 224 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.5s |  |
| 225 | `displayobjectcontainer_addchildat` | 42 | 6.5s |  |
| 226 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.6s |  |
| 227 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.6s |  |
| 228 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.5s |  |
| 229 | `displayobjectcontainer_contains` | 66 | 6.8s |  |
| 230 | `displayobjectcontainer_getchildat` | 4 | 6.5s |  |
| 231 | `displayobjectcontainer_getchildbyname` | 9 | 6.4s |  |
| 232 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.3s |  |
| 233 | `displayobjectcontainer_getchildindex` | 28 | 6.3s |  |
| 234 | `displayobjectcontainer_removechild` | 10 | 6.1s |  |
| 235 | `displayobjectcontainer_removechild_errors` | 4 | 6.2s |  |
| 236 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.5s |  |
| 237 | `displayobjectcontainer_removechildat` | 18 | 6.4s |  |
| 238 | `displayobjectcontainer_removechildren` | 51 | 6.7s |  |
| 239 | `displayobjectcontainer_setchildindex` | 42 | 6.3s |  |
| 240 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.9s |  |
| 241 | `displayobjectcontainer_swapchildren` | 42 | 6.5s |  |
| 242 | `displayobjectcontainer_swapchildrenat` | 42 | 6.5s |  |
| 243 | `displayobjectcontainer_timelineinstance` | 48 | 26.1s |  |
| 244 | `divide` | 1058 | 18.7s |  |
| 245 | `doabc_is_eager` | 1 | 25.5s |  |
| 246 | `documentclass` | 9 | 6.7s |  |
| 247 | `domain_memory` | 133 | 7.7s |  |
| 248 | `drag_drop` | 10 | 6.8s |  |
| 249 | `duplicate_defs` | 1 | 6.4s |  |
| 250 | `eager_init` | 1 | 6.5s |  |
| 251 | `edit_text_linkage` | 7 | 6.6s |  |
| 252 | `edittext_align` | 60 | 6.8s |  |
| 253 | `edittext_always_show_selection` | 0 | 26.5s |  |
| 254 | `edittext_antialiastype` | 296 | 6.7s |  |
| 255 | `edittext_at_point_methods_basic` | 16 | 7.8s |  |
| 256 | `edittext_autosize` | 39 | 6.8s |  |
| 257 | `edittext_autosize_align` | 0 | 26.7s |  |
| 258 | `edittext_autosize_height_dynamic` | 60 | 26.2s |  |
| 259 | `edittext_autosize_height_input` | 60 | 6.5s |  |
| 260 | `edittext_autosize_lazy_bounds_events` | 65 | 6.7s |  |
| 261 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.5s |  |
| 262 | `edittext_autosize_lazy_bounds_props` | 490 | 7.9s |  |
| 263 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.9s |  |
| 264 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.6s |  |
| 265 | `edittext_bottom_scroll_v_basic` | 210 | 6.6s |  |
| 266 | `edittext_bounds_scale` | 24 | 25.2s |  |
| 267 | `edittext_bullet` | 30 | 6.4s |  |
| 268 | `edittext_default_format` | 221 | 6.5s |  |
| 269 | `edittext_default_format_empty` | 136 | 6.6s |  |
| 270 | `edittext_empty_text_format` | 7 | 6.3s |  |
| 271 | `edittext_focus_selection` | 5 | 6.2s |  |
| 272 | `edittext_font_size` | 45 | 6.3s |  |
| 273 | `edittext_format_empty_font` | 8 | 6.3s |  |
| 274 | `edittext_get_char_index_at_point` | 4 | 26.4s |  |
| 275 | `edittext_get_line_index_at_point` | 2 | 25.5s |  |
| 276 | `edittext_get_line_index_of_char` | 76 | 7.3s |  |
| 277 | `edittext_getcharboundaries` | 172 | 6.7s |  |
| 278 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.5s |  |
| 279 | `edittext_getcharboundaries_scroll` | 85 | 6.4s |  |
| 280 | `edittext_getlinemetrics` | 146 | 6.4s |  |
| 281 | `edittext_html` | 3101 | 6.6s |  |
| 282 | `edittext_html_condensewhite` | 487 | 6.3s |  |
| 283 | `edittext_html_entity` | 4 | 6.5s |  |
| 284 | `edittext_html_font_size_swf12` | 267 | 6.2s |  |
| 285 | `edittext_html_font_size_swf13` | 273 | 6.1s |  |
| 286 | `edittext_html_roundtrip` | 17 | 6.5s |  |
| 287 | `edittext_input_control` | 12 | 6.4s |  |
| 288 | `edittext_leading` | 9 | 6.6s |  |
| 289 | `edittext_letter_spacing` | 15 | 6.2s |  |
| 290 | `edittext_line_methods` | 294 | 7.5s |  |
| 291 | `edittext_line_metrics` | 11 | 26.0s |  |
| 292 | `edittext_margins` | 25 | 6.2s |  |
| 293 | `edittext_max_scroll_h_basic` | 475 | 6.4s |  |
| 294 | `edittext_max_scroll_v_basic` | 1000 | 6.3s |  |
| 295 | `edittext_mousedown` | 3 | 6.5s |  |
| 296 | `edittext_mouseenabled` | 26 | 6.3s |  |
| 297 | `edittext_newline_character` | 22 | 6.2s |  |
| 298 | `edittext_newline_stripping` | 64 | 8.8s |  |
| 299 | `edittext_newlines` | 30 | 6.3s |  |
| 300 | `edittext_paragraph_methods` | 257 | 6.2s |  |
| 301 | `edittext_paste_events` | 8 | 6.3s |  |
| 302 | `edittext_paste_maxchars` | 4 | 6.2s |  |
| 303 | `edittext_paste_restrict` | 16 | 6.1s |  |
| 304 | `edittext_restrict` | 191 | 6.2s |  |
| 305 | `edittext_restrict_events` | 22 | 6.4s |  |
| 306 | `edittext_scrollh` | 10 | 6.2s |  |
| 307 | `edittext_selected_text` | 9 | 6.2s |  |
| 308 | `edittext_set_html_same` | 17 | 6.4s |  |
| 309 | `edittext_set_text_vs_html` | 9 | 6.2s |  |
| 310 | `edittext_stylesheet` | 536 | 6.6s |  |
| 311 | `edittext_stylesheet_custom_tag` | 76 | 6.3s |  |
| 312 | `edittext_stylesheet_display` | 272 | 6.5s |  |
| 313 | `edittext_underline` | 40 | 6.4s |  |
| 314 | `edittext_width_height` | 103 | 19.4s |  |
| 315 | `edittext_wordwrap_word` | 150 | 7.0s |  |
| 316 | `edittext_wrap_breaks` | 2375 | 7.2s |  |
| 317 | `empty_bounds` | 1 | 6.4s |  |
| 318 | `encode_uri_surrogate_pair_swf11` | 15 | 6.2s |  |
| 319 | `equals` | 512 | 10.7s |  |
| 320 | `error_geterrormessage` | 779 | 6.4s |  |
| 321 | `error_prototype` | 15 | 6.4s |  |
| 322 | `error_stack_trace_debug_swf17` | 0 | 25.7s |  |
| 323 | `error_stack_trace_debug_swf18` | 0 | 6.0s |  |
| 324 | `error_stack_trace_release_swf17` | 0 | 6.0s |  |
| 325 | `error_stack_trace_release_swf18` | 0 | 6.0s |  |
| 326 | `error_tostring` | 29 | 6.2s |  |
| 327 | `es3_inheritance` | 31 | 6.4s |  |
| 328 | `es4_inheritance` | 30 | 6.7s |  |
| 329 | `es4_interfaces` | 30 | 6.8s |  |
| 330 | `es4_method_binding` | 8 | 6.7s |  |
| 331 | `es4_oop_prototypes` | 14 | 6.9s |  |
| 332 | `es4_protected_inheritance` | 6 | 6.6s |  |
| 333 | `escape` | 71 | 6.7s |  |
| 334 | `event_bubbles` | 2 | 6.5s |  |
| 335 | `event_cancelable` | 2 | 6.4s |  |
| 336 | `event_clone` | 20 | 6.6s |  |
| 337 | `event_clone_error_redispatch` | 3 | 6.6s |  |
| 338 | `event_clone_on_redispatch` | 10 | 6.7s |  |
| 339 | `event_formattostring` | 31 | 6.6s |  |
| 340 | `event_isdefaultprevented` | 12 | 6.5s |  |
| 341 | `event_target_getter` | 5 | 3.1s |  |
| 342 | `event_target_set` | 9 | 6.4s |  |
| 343 | `event_type` | 1 | 18.7s |  |
| 344 | `event_valueof_tostring` | 18 | 6.4s |  |
| 345 | `eventdispatcher_dispatchevent` | 12 | 6.4s |  |
| 346 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.5s |  |
| 347 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.4s |  |
| 348 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.4s |  |
| 349 | `eventdispatcher_dispatchevent_this` | 5 | 6.4s |  |
| 350 | `eventdispatcher_haseventlistener` | 25 | 6.4s |  |
| 351 | `eventdispatcher_interface_invoke` | 1 | 6.3s |  |
| 352 | `eventdispatcher_tostring` | 10 | 6.4s |  |
| 353 | `eventdispatcher_willtrigger` | 25 | 6.3s |  |
| 354 | `falsiness` | 30 | 6.5s |  |
| 355 | `fast_index_access` | 12 | 6.5s |  |
| 356 | `finddef` | 3 | 6.5s |  |
| 357 | `findprop_global_prototype` | 6 | 6.4s |  |
| 358 | `flash_xml` | 29 | 6.5s |  |
| 359 | `flash_xml_cloneNode` | 22 | 6.5s |  |
| 360 | `flash_xml_namespace` | 109 | 6.4s |  |
| 361 | `flash_xml_removeNode` | 60 | 6.5s |  |
| 362 | `focus_events_code` | 161 | 25.7s |  |
| 363 | `focus_events_key_basic` | 132 | 26.0s |  |
| 364 | `focus_events_key_same_object` | 26 | 6.5s |  |
| 365 | `focus_events_mixed_key_mouse` | 100 | 25.3s |  |
| 366 | `focus_events_mouse_same_object` | 40 | 21.4s |  |
| 367 | `focus_remove` | 20 | 21.2s |  |
| 368 | `focus_root_movie` | 4 | 21.7s |  |
| 369 | `focus_stage` | 1 | 5.0s |  |
| 370 | `focusrect` | 18 | 5.8s |  |
| 371 | `focusrect_focuslost` | 9 | 5.1s |  |
| 372 | `focusrect_property` | 110 | 5.2s |  |
| 373 | `font_description_clone` | 14 | 5.1s |  |
| 374 | `font_embedded` | 24 | 5.4s |  |
| 375 | `font_enumeratefonts` | 41 | 5.7s |  |
| 376 | `font_enumeratefonts_filter` | 4 | 5.6s |  |
| 377 | `font_hasglyphs` | 40 | 5.7s |  |
| 378 | `framelabel_constr` | 5 | 5.1s |  |
| 379 | `function_call` | 12 | 5.2s |  |
| 380 | `function_call_arguments` | 46 | 5.2s |  |
| 381 | `function_call_arguments_enumerate` | 5 | 5.0s |  |
| 382 | `function_call_coercion` | 108 | 5.3s |  |
| 383 | `function_call_default` | 6 | 5.0s |  |
| 384 | `function_call_rest` | 22 | 5.3s |  |
| 385 | `function_call_types` | 3 | 5.1s |  |
| 386 | `function_call_via_apply` | 11 | 5.1s |  |
| 387 | `function_call_via_call` | 3 | 5.1s |  |
| 388 | `function_display_anonymous` | 7 | 2.2s |  |
| 389 | `function_length` | 6 | 5.1s |  |
| 390 | `function_object` | 2 | 5.5s |  |
| 391 | `function_proto` | 5 | 5.1s |  |
| 392 | `function_proto_created` | 61 | 5.7s |  |
| 393 | `function_to_locale_string` | 4 | 5.2s |  |
| 394 | `function_to_string` | 4 | 5.0s |  |
| 395 | `function_type` | 6 | 5.4s |  |
| 396 | `function_unbound_this` | 51 | 5.1s |  |
| 397 | `function_value_of` | 4 | 5.2s |  |
| 398 | `get_definition_by_name` | 11 | 5.2s |  |
| 399 | `get_qualified_class_name` | 20 | 18.8s |  |
| 400 | `get_qualified_super_class_name` | 18 | 6.4s |  |
| 401 | `get_slot_edge_cases` | 1 | 6.4s |  |
| 402 | `get_timer` | 2 | 6.5s |  |
| 403 | `getglobalslot` | 1 | 6.5s |  |
| 404 | `getouterscope` | 8 | 6.5s |  |
| 405 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 406 | `goto_button_nested_framescript` | 28 | 7.2s |  |
| 407 | `goto_in_constructframe` | 12 | 6.9s |  |
| 408 | `goto_in_scene_last_frame` | 2 | 26.0s |  |
| 409 | `goto_methods` | 56 | 7.0s |  |
| 410 | `goto_methods_swfver10` | 8 | 6.6s |  |
| 411 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 412 | `goto_nested_framescript` | 9 | 6.8s |  |
| 413 | `goto_on_orphan` | 15 | 6.8s |  |
| 414 | `graphics_bad_direct_commands` | 5 | 7.2s |  |
| 415 | `graphics_bitmap_fill` | 0 | 8.4s |  |
| 416 | `graphics_bitmaps` | 0 | 7.2s |  |
| 417 | `graphics_direct_commands` | 0 | 7.1s |  |
| 418 | `graphics_draw_triangles` | 98 | 26.2s |  |
| 419 | `graphics_gradients` | 0 | 6.8s |  |
| 420 | `graphics_gradients_nulls` | 0 | 6.7s |  |
| 421 | `graphics_path` | 56 | 6.5s |  |
| 422 | `graphics_round_rects` | 0 | 6.5s |  |
| 423 | `graphics_simple_shapes` | 0 | 6.9s |  |
| 424 | `greaterequals` | 512 | 10.5s |  |
| 425 | `greaterthan` | 512 | 10.3s |  |
| 426 | `has_own_property` | 102 | 7.0s |  |
| 427 | `hasownproperty_namespaces` | 2 | 6.4s |  |
| 428 | `hello_world` | 1 | 6.4s |  |
| 429 | `hittest_morph` | 30 | 6.6s |  |
| 430 | `if_eq` | 10 | 6.6s |  |
| 431 | `if_gt` | 1 | 6.7s |  |
| 432 | `if_gte` | 10 | 18.5s |  |
| 433 | `if_lt` | 1 | 6.4s |  |
| 434 | `if_lte` | 10 | 6.2s |  |
| 435 | `if_ne` | 7 | 3.0s |  |
| 436 | `if_stricteq` | 6 | 6.3s |  |
| 437 | `if_strictne` | 11 | 6.3s |  |
| 438 | `in` | 102 | 6.8s |  |
| 439 | `inclocal` | 46 | 6.4s |  |
| 440 | `inclocal_i` | 46 | 6.4s |  |
| 441 | `increment` | 46 | 6.4s |  |
| 442 | `increment_i` | 46 | 6.4s |  |
| 443 | `indexing_delete` | 75 | 6.4s |  |
| 444 | `instanceof` | 58 | 6.7s |  |
| 445 | `instantiation_on_enter_frame` | 7 | 25.3s |  |
| 446 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.3s |  |
| 447 | `int_constr` | 92 | 6.2s |  |
| 448 | `int_edge_cases` | 19 | 6.3s |  |
| 449 | `int_instanceof` | 3 | 6.2s |  |
| 450 | `int_tofixed` | 1215 | 6.2s |  |
| 451 | `int_tostring` | 3375 | 6.1s |  |
| 452 | `interactiveobject_enabled` | 25 | 6.2s |  |
| 453 | `interface_namespaces` | 78 | 6.6s |  |
| 454 | `is_finite` | 46 | 6.3s |  |
| 455 | `is_nan` | 46 | 6.2s |  |
| 456 | `is_prototype_of` | 12 | 6.2s |  |
| 457 | `issue_10221` | 2 | 6.1s |  |
| 458 | `issue_13780` | 12 | 6.3s |  |
| 459 | `issue_14901` | 1 | 6.2s |  |
| 460 | `issue_17675_edittext_paste_maxchars` | 1 | 6.5s |  |
| 461 | `issue_5292` | 5 | 6.4s |  |
| 462 | `issue_8630` | 2 | 6.5s |  |
| 463 | `issue_8630_scriptremove` | 11 | 6.6s |  |
| 464 | `istype` | 24 | 3.2s |  |
| 465 | `istypelate` | 58 | 7.1s |  |
| 466 | `istypelate_coerce` | 198 | 20.2s |  |
| 467 | `jpeg_loader_context` | 6 | 6.6s |  |
| 468 | `json_errors` | 9 | 26.1s |  |
| 469 | `json_parse` | 21 | 6.5s |  |
| 470 | `json_stringify` | 12 | 6.8s |  |
| 471 | `json_stringify_order` | 1 | 6.4s |  |
| 472 | `json_version_gated` | 1 | 6.4s |  |
| 473 | `key_input_80percent` | 1812 | 6.7s |  |
| 474 | `key_input_location` | 126 | 6.7s |  |
| 475 | `key_input_numpad` | 384 | 6.5s |  |
| 476 | `lazyinit` | 17 | 6.5s |  |
| 477 | `lessequals` | 512 | 10.2s |  |
| 478 | `lessthan` | 512 | 10.2s |  |
| 479 | `loader_bitmap_transparency` | 14 | 6.6s |  |
| 480 | `loader_bytes_unknown_content` | 14 | 6.6s |  |
| 481 | `loader_child_getdefinition` | 5 | 6.7s |  |
| 482 | `loader_duplicate_coerce` | 3 | 6.7s |  |
| 483 | `loader_duplicate_coerce_new_domain` | 4 | 6.6s |  |
| 484 | `loader_error_in_root_ctor` | 4 | 6.7s |  |
| 485 | `loader_events` | 92 | 7.2s |  |
| 486 | `loader_image` | 8 | 6.9s |  |
| 487 | `loader_jpegxr` | 2 | 25.6s |  |
| 488 | `loader_jpegxr_alpha` | 1 | 25.4s |  |
| 489 | `loader_loadbytes_events` | 30 | 7.3s |  |
| 490 | `loader_loadbytes_invalid_png` | 4 | 6.5s |  |
| 491 | `loader_loadbytes_url` | 12 | 6.8s |  |
| 492 | `loader_loaderurl` | 6 | 7.0s |  |
| 493 | `loader_noninteractive_try_click_root` | 5 | 25.9s |  |
| 494 | `loader_reuse` | 38 | 6.8s |  |
| 495 | `loader_unknown_content` | 24 | 6.7s |  |
| 496 | `loader_visibility_interactive` | 1 | 6.9s |  |
| 497 | `loaderinfo_events` | 7 | 6.6s |  |
| 498 | `loaderinfo_loadurl` | 12 | 18.8s |  |
| 499 | `loaderinfo_more` | 6 | 6.9s |  |
| 500 | `loaderinfo_properties` | 18 | 6.5s |  |
| 501 | `loaderinfo_properties_not_loaded` | 23 | 6.6s |  |
| 502 | `loaderinfo_root` | 10 | 6.4s |  |
| 503 | `loaderinfo_root_allows` | 2 | 6.4s |  |
| 504 | `lshift` | 1058 | 17.7s |  |
| 505 | `mask_reapply` | 1 | 6.5s |  |
| 506 | `math` | 497 | 6.6s |  |
| 507 | `missing_external_interface` | 10 | 6.5s |  |
| 508 | `modulo` | 1058 | 17.8s |  |
| 509 | `morph_shape` | 2 | 25.5s |  |
| 510 | `mouse_children` | 192 | 25.8s |  |
| 511 | `mouse_click_events` | 90 | 25.4s |  |
| 512 | `mouse_double_click_events` | 188 | 6.5s |  |
| 513 | `mouse_empty_parent` | 4 | 6.5s |  |
| 514 | `mouse_over_while_dragging` | 3 | 6.6s |  |
| 515 | `mouse_pick_button_mode` | 2 | 6.5s |  |
| 516 | `mouse_sibling` | 8 | 6.5s |  |
| 517 | `mouse_wheel_events` | 36 | 26.4s |  |
| 518 | `mouseevent_constr` | 66 | 6.5s |  |
| 519 | `mouseevent_stagexy` | 35 | 6.5s |  |
| 520 | `mouseevent_valueof_tostring` | 28 | 6.5s |  |
| 521 | `movieclip_addframescript` | 3 | 25.7s |  |
| 522 | `movieclip_child_property` | 16 | 6.6s |  |
| 523 | `movieclip_constr` | 21 | 18.7s |  |
| 524 | `movieclip_currentlabels` | 17 | 25.4s |  |
| 525 | `movieclip_currentlabels_dupes1` | 46 | 25.4s |  |
| 526 | `movieclip_currentlabels_dupes2` | 30 | 6.4s |  |
| 527 | `movieclip_currentlabels_dupes3` | 67 | 6.4s |  |
| 528 | `movieclip_currentscene` | 12 | 6.6s |  |
| 529 | `movieclip_dispatchevent` | 430 | 6.5s |  |
| 530 | `movieclip_dispatchevent_cancel` | 102 | 6.6s |  |
| 531 | `movieclip_dispatchevent_handlerorder` | 251 | 6.5s |  |
| 532 | `movieclip_dispatchevent_selfadd` | 80 | 6.4s |  |
| 533 | `movieclip_dispatchevent_target` | 899 | 6.5s |  |
| 534 | `movieclip_displayevents` | 96 | 25.6s |  |
| 535 | `movieclip_displayevents_clickgoto` | 676 | 7.0s |  |
| 536 | `movieclip_displayevents_clickgoto2` | 2001 | 7.0s |  |
| 537 | `movieclip_displayevents_clickplay` | 575 | 6.7s |  |
| 538 | `movieclip_displayevents_clicksymbol` | 562 | 6.7s |  |
| 539 | `movieclip_displayevents_constructframegoto` | 140 | 6.8s |  |
| 540 | `movieclip_displayevents_constructframeplay` | 50 | 6.7s |  |
| 541 | `movieclip_displayevents_constructframesymbol` | 144 | 6.7s |  |
| 542 | `movieclip_displayevents_dblhandler` | 21 | 6.6s |  |
| 543 | `movieclip_displayevents_enterframegoto` | 149 | 6.8s |  |
| 544 | `movieclip_displayevents_enterframeplay` | 48 | 6.5s |  |
| 545 | `movieclip_displayevents_enterframesymbol` | 149 | 25.9s |  |
| 546 | `movieclip_displayevents_exitframegoto` | 106 | 6.5s |  |
| 547 | `movieclip_displayevents_exitframeplay` | 44 | 6.5s |  |
| 548 | `movieclip_displayevents_exitframesymbol` | 135 | 6.6s |  |
| 549 | `movieclip_displayevents_looping` | 63 | 25.9s |  |
| 550 | `movieclip_displayevents_stopped` | 113 | 7.0s |  |
| 551 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 552 | `movieclip_displayevents_timeline` | 128 | 26.9s |  |
| 553 | `movieclip_drawrect` | 54 | 6.7s |  |
| 554 | `movieclip_frameconstruct_skipped` | 9 | 6.8s |  |
| 555 | `movieclip_goto_during_frame_script` | 15 | 6.7s |  |
| 556 | `movieclip_goto_overwrite` | 14 | 26.3s |  |
| 557 | `movieclip_goto_scene_last_frame_int` | 1 | 26.8s |  |
| 558 | `movieclip_goto_scene_last_frame_label` | 1 | 6.5s |  |
| 559 | `movieclip_gotoandplay` | 15 | 26.1s |  |
| 560 | `movieclip_gotoandstop` | 13 | 6.5s |  |
| 561 | `movieclip_gotoandstop_children` | 4 | 6.6s |  |
| 562 | `movieclip_gotoandstop_framescripts1` | 4 | 6.5s |  |
| 563 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 564 | `movieclip_gotoandstop_framescripts_self` | 7 | 13.5s |  |
| 565 | `movieclip_gotoandstop_queueing` | 12 | 4.7s |  |
| 566 | `movieclip_next_frame` | 2 | 4.3s |  |
| 567 | `movieclip_next_scene` | 6 | 17.4s |  |
| 568 | `movieclip_play` | 3 | 4.1s |  |
| 569 | `movieclip_prev_frame` | 3 | 3.9s |  |
| 570 | `movieclip_prev_scene` | 7 | 4.2s |  |
| 571 | `movieclip_properties` | 79 | 4.7s |  |
| 572 | `movieclip_queued_noop_goto_swf10` | 9 | 4.2s |  |
| 573 | `movieclip_queued_noop_goto_swf9` | 7 | 0.8s |  |
| 574 | `movieclip_scenes` | 11 | 4.0s |  |
| 575 | `movieclip_soundtransform` | 831 | 18.7s |  |
| 576 | `movieclip_stop` | 1 | 4.1s |  |
| 577 | `movieclip_super_is_symbol` | 20 | 4.2s |  |
| 578 | `movieclip_symbol_constr` | 8 | 4.1s |  |
| 579 | `movieclip_text_mousedown` | 1 | 4.1s |  |
| 580 | `movieclip_willtrigger` | 5 | 4.2s |  |
| 581 | `multiply` | 1058 | 11.1s |  |
| 582 | `namespace_constr` | 253 | 4.2s |  |
| 583 | `namespace_constr_args` | 1 | 4.0s |  |
| 584 | `namespace_enumeration_order` | 7 | 4.2s |  |
| 585 | `nan_scale` | 9 | 4.5s |  |
| 586 | `navigateToURL_target_normalize` | 107 | 18.4s |  |
| 587 | `negate` | 30 | 4.4s |  |
| 588 | `negative_volume_panned` | 0 | 4.3s |  |
| 589 | `nested_iteration` | 11 | 4.2s |  |
| 590 | `net_getClassByAlias` | 3 | 4.1s |  |
| 591 | `net_navigateToURL` | 57 | 4.1s |  |
| 592 | `newactivation_in_script_init` | 3 | 6.6s |  |
| 593 | `newclass_twice` | 3 | 6.4s |  |
| 594 | `nonconflicting_declarations` | 0 | 6.5s |  |
| 595 | `null_void_types` | 8 | 6.4s |  |
| 596 | `number_autoconv` | 21 | 6.5s |  |
| 597 | `number_autoconv_amf` | 132 | 6.5s |  |
| 598 | `number_autoconv_array_sort_32bit` | 1 | 6.4s |  |
| 599 | `number_constr` | 58 | 6.6s |  |
| 600 | `number_toexponential` | 378 | 6.6s |  |
| 601 | `number_toexponential2` | 35 | 6.4s |  |
| 602 | `number_tofixed` | 378 | 6.3s |  |
| 603 | `number_toprecision` | 350 | 6.5s |  |
| 604 | `obfuscated_class_names` | 3 | 6.5s |  |
| 605 | `object_enumeration` | 10 | 6.4s |  |
| 606 | `object_prototype` | 4 | 6.5s |  |
| 607 | `object_to_locale_string` | 2 | 6.4s |  |
| 608 | `object_to_string` | 2 | 6.3s |  |
| 609 | `object_value_of` | 2 | 3.0s |  |
| 610 | `op_coerce` | 54 | 6.5s |  |
| 611 | `op_coerce_x` | 54 | 6.5s |  |
| 612 | `op_escxattr` | 2 | 6.4s |  |
| 613 | `op_escxelem` | 2 | 6.4s |  |
| 614 | `op_lookupswitch` | 4 | 6.5s |  |
| 615 | `optimize_coerce` | 1 | 6.4s |  |
| 616 | `orphan_movie_complex` | 80 | 6.9s |  |
| 617 | `orphan_movie_reorder` | 111 | 26.6s |  |
| 618 | `package_namespace` | 7 | 6.4s |  |
| 619 | `param_default_value_has_zero_cpool_index` | 1 | 6.5s |  |
| 620 | `parent_early_access_child` | 16 | 6.8s |  |
| 621 | `parse_float` | 81 | 6.8s |  |
| 622 | `pixelbender_effect_BlurredFocus` | 0 | 24.3s |  |
| 623 | `pixelbender_effect_glassDisplace` | 0 | 10.4s |  |
| 624 | `pixelbender_effect_smudge` | 0 | 8.2s |  |
| 625 | `pixelbender_effect_tintype` | 0 | 7.9s |  |
| 626 | `pixelbender_effect_twirl` | 0 | 8.2s |  |
| 627 | `pixelbender_images` | 0 | 7.0s |  |
| 628 | `place_multiple` | 17 | 5.1s |  |
| 629 | `place_object_replace` | 9 | 5.3s |  |
| 630 | `place_object_replace_2` | 24 | 5.3s |  |
| 631 | `place_object_same_depth_frame` | 1 | 5.3s |  |
| 632 | `point` | 132 | 5.7s |  |
| 633 | `primitive_edge_cases` | 1 | 5.1s |  |
| 634 | `property_priority` | 22 | 6.6s |  |
| 635 | `property_priority_three_level` | 6 | 6.4s |  |
| 636 | `propertyisenumerable_namespaces` | 6 | 6.3s |  |
| 637 | `prototype_set_null` | 7 | 6.2s |  |
| 638 | `proxy_callproperty` | 24 | 6.2s |  |
| 639 | `proxy_deleteproperty` | 64 | 6.4s |  |
| 640 | `proxy_enumeration` | 34 | 6.3s |  |
| 641 | `proxy_getproperty` | 77 | 6.4s |  |
| 642 | `proxy_hasownproperty` | 8 | 6.2s |  |
| 643 | `proxy_hasproperty` | 32 | 6.3s |  |
| 644 | `proxy_serialize` | 9 | 6.2s |  |
| 645 | `proxy_setproperty` | 42 | 6.3s |  |
| 646 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.2s |  |
| 647 | `qname_constr` | 32 | 6.3s |  |
| 648 | `qname_constr_namespace` | 24 | 6.3s |  |
| 649 | `qname_enumeration` | 9 | 6.4s |  |
| 650 | `qname_indexing` | 23 | 6.3s |  |
| 651 | `qname_tostring` | 25 | 6.3s |  |
| 652 | `qname_valueof` | 29 | 6.3s |  |
| 653 | `regexp_constr` | 148 | 6.6s |  |
| 654 | `regexp_exec` | 19 | 6.3s |  |
| 655 | `regexp_extended` | 47 | 6.2s |  |
| 656 | `regexp_multiargs` | 1 | 6.1s |  |
| 657 | `regexp_test` | 27 | 6.3s |  |
| 658 | `regexp_toString` | 10 | 6.3s |  |
| 659 | `register_script_refresh` | 35 | 6.7s |  |
| 660 | `remove_child_clear_field` | 88 | 6.6s |  |
| 661 | `remove_dobj` | 3 | 6.3s |  |
| 662 | `resolve_order` | 4 | 6.3s |  |
| 663 | `rng` | 1 | 7.4s |  |
| 664 | `rootless` | 42 | 6.4s |  |
| 665 | `rshift` | 1058 | 18.6s |  |
| 666 | `sandbox_type_inherited` | 2 | 18.5s |  |
| 667 | `sandbox_type_local_file` | 1 | 6.4s |  |
| 668 | `scene_constr` | 8 | 6.5s |  |
| 669 | `set_local_0` | 31 | 6.3s |  |
| 670 | `set_property_is_enumerable` | 85 | 6.7s |  |
| 671 | `shape_drawrect` | 54 | 6.3s |  |
| 672 | `shared_object_no_root` | 3 | 6.2s |  |
| 673 | `simplebutton_added_to_stage` | 45 | 24.9s |  |
| 674 | `simplebutton_childevents` | 86 | 6.6s |  |
| 675 | `simplebutton_childevents_nested` | 54 | 6.5s |  |
| 676 | `simplebutton_childevents_sprite` | 13 | 6.3s |  |
| 677 | `simplebutton_childprops` | 144 | 6.5s |  |
| 678 | `simplebutton_childshuffle` | 23 | 6.1s |  |
| 679 | `simplebutton_constr` | 36 | 6.4s |  |
| 680 | `simplebutton_constr_childevents` | 48 | 6.5s |  |
| 681 | `simplebutton_constr_params` | 42 | 6.4s |  |
| 682 | `simplebutton_mouseenabled` | 26 | 6.3s |  |
| 683 | `simplebutton_multi_children` | 19 | 6.5s |  |
| 684 | `simplebutton_structure` | 27 | 6.5s |  |
| 685 | `simplebutton_symbolclass` | 68 | 6.7s |  |
| 686 | `slot_disp_id_shared_numbering` | 1 | 24.7s |  |
| 687 | `slots_force_autoassigned` | 1 | 6.3s |  |
| 688 | `sound_embeddedprops` | 26 | 6.4s |  |
| 689 | `sound_play` | 19 | 6.4s |  |
| 690 | `sound_valueof` | 33 | 6.2s |  |
| 691 | `soundchannel_soundtransform` | 835 | 27.1s |  |
| 692 | `soundchannel_soundtransform_exists` | 5 | 25.2s |  |
| 693 | `soundchannel_stop` | 8 | 6.3s |  |
| 694 | `soundmixer_buffertime` | 5 | 6.1s |  |
| 695 | `soundmixer_stopall` | 6 | 6.2s |  |
| 696 | `soundtransform` | 442 | 10.4s |  |
| 697 | `sprite_with_frames` | 0 | 6.7s |  |
| 698 | `stage3d_agal_cross_product` | 0 | 8.6s |  |
| 699 | `stage3d_bitmap` | 0 | 30.4s |  |
| 700 | `stage3d_float1_index` | 0 | 27.7s |  |
| 701 | `stage3d_fractal` | 0 | 28.3s |  |
| 702 | `stage3d_ignore_sampler_override` | 0 | 28.4s |  |
| 703 | `stage3d_program_constants_bytearray_be` | 0 | 29.6s |  |
| 704 | `stage3d_program_constants_bytearray_le` | 0 | 9.2s |  |
| 705 | `stage3d_raytrace` | 0 | 31.0s |  |
| 706 | `stage3d_rotating_cube` | 0 | 9.4s |  |
| 707 | `stage3d_sampler` | 0 | 21.4s |  |
| 708 | `stage3d_sampler_partial_upload` | 0 | 9.1s |  |
| 709 | `stage3d_stencil` | 0 | 28.5s |  |
| 710 | `stage3d_texture` | 0 | 13.8s |  |
| 711 | `stage3d_texture_bytearray` | 0 | 10.3s |  |
| 712 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.7s |  |
| 713 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.8s |  |
| 714 | `stage3d_triangle` | 0 | 9.2s |  |
| 715 | `stage3d_triangle_bytes4` | 0 | 9.1s |  |
| 716 | `stage3d_triangle_float1` | 0 | 9.1s |  |
| 717 | `stage3d_triangle_index_upload` | 0 | 9.1s |  |
| 718 | `stage_access` | 10 | 6.5s |  |
| 719 | `stage_displayobject_properties` | 24 | 6.3s |  |
| 720 | `stage_framerate_nan` | 7 | 6.6s |  |
| 721 | `stage_framerate_negative` | 6 | 6.4s |  |
| 722 | `stage_framerate_zero` | 6 | 6.4s |  |
| 723 | `stage_invalidate` | 38 | 6.6s |  |
| 724 | `stage_loaderinfo_properties` | 24 | 6.8s |  |
| 725 | `stage_mousechildren` | 2 | 6.4s |  |
| 726 | `stage_mouseenabled` | 15 | 6.3s |  |
| 727 | `stage_overriden_setters` | 31 | 6.5s |  |
| 728 | `stage_properties` | 30 | 6.4s |  |
| 729 | `static_var_with_this_in_ctor` | 2 | 6.4s |  |
| 730 | `stored_properties` | 11 | 6.4s |  |
| 731 | `strict_equality` | 34 | 6.5s |  |
| 732 | `string_call` | 13 | 6.4s |  |
| 733 | `string_case` | 23 | 6.4s |  |
| 734 | `string_char_at` | 27 | 6.4s |  |
| 735 | `string_char_code_at` | 28 | 6.3s |  |
| 736 | `string_concat_fromcharcode` | 37 | 6.3s |  |
| 737 | `string_constr` | 25 | 6.5s |  |
| 738 | `string_indexof_lastindexof` | 87 | 18.3s |  |
| 739 | `string_length` | 16 | 6.0s |  |
| 740 | `string_locale_compare` | 39 | 6.2s |  |
| 741 | `string_match` | 51 | 6.2s |  |
| 742 | `string_relational_compare` | 4 | 6.0s |  |
| 743 | `string_replace` | 51 | 6.2s |  |
| 744 | `string_search` | 41 | 6.3s |  |
| 745 | `string_slice_substr_substring` | 170 | 7.3s |  |
| 746 | `string_split` | 29 | 6.1s |  |
| 747 | `string_substr_negative` | 21 | 6.0s |  |
| 748 | `string_substr_weird` | 182 | 6.0s |  |
| 749 | `subtract` | 1058 | 18.1s |  |
| 750 | `super_get_call` | 12 | 6.0s |  |
| 751 | `supercall_two_classobjects` | 2 | 6.0s |  |
| 752 | `swf8` | 1 | 6.0s |  |
| 753 | `swf_10_queued_goto_scripts_construct` | 52 | 6.3s |  |
| 754 | `swf_9_goto_in_enter_frame` | 17 | 6.1s |  |
| 755 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.1s |  |
| 756 | `swf_9_queued_goto_scripts` | 6 | 6.0s |  |
| 757 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 758 | `swf_9_versioning` | 2 | 6.0s |  |
| 759 | `swf_wrong_frame_count` | 38 | 6.3s |  |
| 760 | `swf_wrong_frame_count_isplaying` | 22 | 6.0s |  |
| 761 | `symbol_class_binary_data` | 8 | 6.0s |  |
| 762 | `symbol_class_conflict` | 4 | 6.3s |  |
| 763 | `symbol_class_root_not_zero` | 1 | 6.0s |  |
| 764 | `symbolclass_invalid_utf8` | 2 | 6.0s |  |
| 765 | `tab_ordering_automatic_advanced` | 184 | 7.2s |  |
| 766 | `tab_ordering_automatic_basic` | 45 | 6.4s |  |
| 767 | `tab_ordering_children` | 116 | 6.5s |  |
| 768 | `tab_ordering_custom_basic` | 34 | 6.3s |  |
| 769 | `tab_ordering_stage_tab_children` | 32 | 6.4s |  |
| 770 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.2s |  |
| 771 | `tab_ordering_tabbable` | 47 | 6.4s |  |
| 772 | `text_engine_fontdescription` | 27 | 6.5s |  |
| 773 | `text_run` | 7 | 6.2s |  |
| 774 | `textfield_focusin_event` | 9 | 6.3s |  |
| 775 | `textfield_input_dead_keys_windows` | 15 | 6.4s |  |
| 776 | `textfield_unload` | 39 | 6.7s |  |
| 777 | `textformat` | 1134 | 6.3s |  |
| 778 | `textformat_display` | 14 | 6.4s |  |
| 779 | `textformat_font_max_length` | 4 | 6.3s |  |
| 780 | `throw` | 3 | 6.3s |  |
| 781 | `timeline_scripts` | 3 | 6.5s |  |
| 782 | `timer` | 90 | 7.4s |  |
| 783 | `timer_events` | 3 | 6.5s |  |
| 784 | `timer_finished` | 11 | 6.6s |  |
| 785 | `timer_reset` | 8 | 6.7s |  |
| 786 | `timer_setdelay` | 5 | 6.6s |  |
| 787 | `trace` | 12 | 6.3s |  |
| 788 | `truthiness` | 30 | 17.7s |  |
| 789 | `try_catch` | 11 | 5.1s |  |
| 790 | `try_catch_typed` | 12 | 5.1s |  |
| 791 | `typeof` | 30 | 5.2s |  |
| 792 | `uint_constr` | 92 | 5.1s |  |
| 793 | `uint_tofixed` | 1215 | 5.1s |  |
| 794 | `uint_tostring` | 3375 | 5.1s |  |
| 795 | `unchecked_function` | 15 | 5.1s |  |
| 796 | `unescape` | 28 | 5.1s |  |
| 797 | `url_loader` | 25 | 5.1s |  |
| 798 | `urlrequest` | 18 | 5.1s |  |
| 799 | `urshift` | 1058 | 5.2s |  |
| 800 | `vector_class` | 36 | 5.2s |  |
| 801 | `vector_class_call` | 11 | 5.1s |  |
| 802 | `vector_coercion` | 66 | 5.1s |  |
| 803 | `vector_concat` | 90 | 5.1s |  |
| 804 | `vector_constr` | 107 | 5.1s |  |
| 805 | `vector_enumeration` | 5 | 5.2s |  |
| 806 | `vector_every` | 92 | 5.3s |  |
| 807 | `vector_filter` | 95 | 5.3s |  |
| 808 | `vector_holes` | 24 | 5.2s |  |
| 809 | `vector_indexof` | 302 | 5.2s |  |
| 810 | `vector_insertat` | 270 | 5.2s |  |
| 811 | `vector_int_access` | 4 | 5.2s |  |
| 812 | `vector_int_delete` | 11 | 5.1s |  |
| 813 | `vector_join` | 58 | 5.1s |  |
| 814 | `vector_lastindexof` | 302 | 5.1s |  |
| 815 | `vector_legacy` | 10 | 5.1s |  |
| 816 | `vector_map` | 85 | 5.1s |  |
| 817 | `vector_object_final` | 1 | 5.2s |  |
| 818 | `vector_object_toString` | 10 | 5.2s |  |
| 819 | `vector_pushpop` | 255 | 5.2s |  |
| 820 | `vector_reborrow_bug` | 10 | 19.0s |  |
| 821 | `vector_removeat` | 172 | 7.8s |  |
| 822 | `vector_reverse` | 232 | 7.8s |  |
| 823 | `vector_shiftunshift` | 252 | 6.5s |  |
| 824 | `vector_slice` | 331 | 8.4s |  |
| 825 | `vector_sort` | 905 | 16.6s |  |
| 826 | `vector_splice` | 693 | 10.9s |  |
| 827 | `vector_splice_fixed_bug_compat` | 4 | 6.6s |  |
| 828 | `vector_tostring` | 79 | 7.2s |  |
| 829 | `verify_abnormal_loop` | 1 | 6.5s |  |
| 830 | `verify_exception_targets_edge_case` | 1 | 6.4s |  |
| 831 | `verify_lookup_switch_edge_case` | 1 | 6.3s |  |
| 832 | `verify_unreachable_exception` | 2 | 6.4s |  |
| 833 | `versioned_isplaying` | 2 | 6.5s |  |
| 834 | `virtual_properties` | 16 | 6.5s |  |
| 835 | `with` | 4 | 6.5s |  |
| 836 | `wrong_arg_count` | 7 | 6.7s |  |
| 837 | `xml_abstract_equality` | 36 | 6.7s |  |
| 838 | `xml_advanced` | 52 | 6.5s |  |
| 839 | `xml_appendchild` | 10 | 6.6s |  |
| 840 | `xml_as_attribute` | 9 | 6.5s |  |
| 841 | `xml_attribute` | 35 | 6.7s |  |
| 842 | `xml_attribute_name` | 40 | 6.5s |  |
| 843 | `xml_basic` | 33 | 6.6s |  |
| 844 | `xml_child` | 25 | 6.6s |  |
| 845 | `xml_childindex` | 7 | 6.5s |  |
| 846 | `xml_children` | 43 | 7.3s |  |
| 847 | `xml_class_call` | 9 | 6.5s |  |
| 848 | `xml_contains` | 197 | 6.8s |  |
| 849 | `xml_copy` | 20 | 18.0s |  |
| 850 | `xml_ctor_from_tostring` | 23 | 6.3s |  |
| 851 | `xml_delete` | 114 | 6.2s |  |
| 852 | `xml_descendants` | 83 | 6.1s |  |
| 853 | `xml_elements` | 6 | 6.0s |  |
| 854 | `xml_equals_namespace_check` | 2 | 6.0s |  |
| 855 | `xml_explicit_use_namespace` | 5 | 6.1s |  |
| 856 | `xml_getdescendants_qname` | 21 | 6.0s |  |
| 857 | `xml_has_property_via_in` | 26 | 6.1s |  |
| 858 | `xml_hasownproperty` | 6 | 6.0s |  |
| 859 | `xml_ignore_white` | 6 | 6.1s |  |
| 860 | `xml_length` | 2 | 6.0s |  |
| 861 | `xml_list_as_attribute` | 9 | 6.2s |  |
| 862 | `xml_list_concat` | 20 | 6.2s |  |
| 863 | `xml_list_enumerate` | 4 | 6.1s |  |
| 864 | `xml_methods_settings` | 3 | 6.1s |  |
| 865 | `xml_mismatched_tag` | 37 | 6.1s |  |
| 866 | `xml_namespace` | 39 | 6.1s |  |
| 867 | `xml_namespace_methods` | 245 | 6.1s |  |
| 868 | `xml_namespaced_property` | 7 | 6.1s |  |
| 869 | `xml_no_namespace` | 1 | 6.0s |  |
| 870 | `xml_nodekind` | 3 | 6.1s |  |
| 871 | `xml_normalize` | 35 | 6.4s |  |
| 872 | `xml_notification_bubbling` | 361 | 6.2s |  |
| 873 | `xml_parent` | 8 | 6.4s |  |
| 874 | `xml_set_children` | 17 | 6.7s |  |
| 875 | `xml_set_name` | 34 | 6.2s |  |
| 876 | `xml_settings` | 6 | 3.0s |  |
| 877 | `xml_simple_complex_content` | 47 | 6.3s |  |
| 878 | `xml_text` | 7 | 6.5s |  |
| 879 | `xml_tostring` | 6 | 6.5s |  |
| 880 | `xml_tostring_namespace` | 12 | 6.5s |  |
| 881 | `xml_unescaping` | 23 | 6.5s |  |
| 882 | `xml_weird_ignores` | 54 | 6.6s |  |
| 883 | `xml_wildcard` | 11 | 6.2s |  |
| 884 | `xmldocument` | 254 | 6.1s |  |
| 885 | `xmlnode` | 3540 | 6.3s |  |
| 886 | `zero_frame_clip` | 3 | 6.7s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.7s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.4s |  |
| 3 | `blend_transform` | 1 | 1 | 5.1s |  |
| 4 | `coerce_property` | 3 | 3 | 6.7s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.7s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 6.4s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.5s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 36.8s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.2s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.5s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.5s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.0s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 6.8s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 26.3s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.1s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.2s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.4s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.2s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 6.2s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.4s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.4s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.2s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 6.3s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.1s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.2s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 6.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**62 tests** within reach

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
| 13 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 14 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 15 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 16 | `edittext_mouse_selection` | 92.0% | 334 | 363 | 29 |  |
| 17 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 18 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 19 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 20 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 21 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 22 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 23 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 24 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 25 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 26 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 27 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 28 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 29 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 30 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 31 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 32 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 33 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 34 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 35 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 36 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 37 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 38 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 39 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
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
| 50 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 51 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 52 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 53 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 54 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 55 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 56 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 57 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 58 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 59 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 60 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 61 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 62 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.3s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.2s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.4s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**306 tests** with output mismatch, sorted by match rate (best first)

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
| 13 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 14 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 15 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 16 | `edittext_mouse_selection` | 92.0% | 334/363 | 363 | 363 |  |
| 17 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 18 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 19 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 20 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 21 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 22 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 23 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 24 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 25 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 26 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 27 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 28 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 29 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 30 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 31 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 32 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 33 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 34 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 35 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 36 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 37 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 38 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 39 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
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
| 50 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 51 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 52 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 53 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 54 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 55 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 56 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 57 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 58 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 59 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 60 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 61 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 62 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 63 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 64 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 65 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 66 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 67 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 68 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 69 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 70 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 71 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 72 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 73 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 74 | `mouse_pick_masking` | 28.6% | 2/7 | 7 | 7 |  |
| 75 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 76 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 77 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 78 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 79 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 80 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 81 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 82 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 83 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 84 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 85 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 86 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 87 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 88 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 89 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 90 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 91 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 92 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 93 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 94 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 95 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 96 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 97 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 98 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 99 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 100 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 101 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 102 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 103 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 104 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 105 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 106 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 107 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 108 | `localconnection` | 7.5% | 67/890 | 623 | 890 |  |
| 109 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 110 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 111 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 112 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 113 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 114 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 115 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 116 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 117 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 118 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 119 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 120 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 121 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 122 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 123 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 124 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 125 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 126 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 127 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 128 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 129 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 130 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 131 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 132 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 133 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 134 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 135 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 136 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 137 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 138 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 139 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 140 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 141 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 142 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 143 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 144 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 145 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 146 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 147 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 148 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 149 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 150 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 151 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 152 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 153 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 154 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 155 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 156 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 157 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 158 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 159 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 160 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 161 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 162 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 163 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 164 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 165 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 166 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 167 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 168 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 169 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 170 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 171 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 172 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 173 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 174 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 175 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 176 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 177 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 178 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 179 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 180 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 181 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 182 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 183 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 184 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 185 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 186 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 187 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 188 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 189 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 190 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 191 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 192 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 193 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 194 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 195 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 196 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 197 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 198 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 199 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 200 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 201 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 202 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 203 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 204 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 205 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 206 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 207 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 208 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 209 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 210 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 211 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 212 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 213 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 214 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 215 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 216 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 217 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 218 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 219 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 220 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 221 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 222 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 223 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 224 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 225 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 226 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 227 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 228 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 229 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 230 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 231 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 232 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 233 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 234 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 235 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 236 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 237 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 238 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 239 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 240 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 241 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 242 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 243 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 244 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 245 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 246 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 247 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 248 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 249 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 250 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 251 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 252 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 253 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 254 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 255 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 256 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 257 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 258 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 259 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 260 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 261 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 262 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 263 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 264 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 265 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 266 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 267 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 268 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 269 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 270 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 271 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 272 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 273 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 274 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 275 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 276 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 277 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 278 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 279 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 280 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 281 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 282 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 283 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 284 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 285 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 286 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 287 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 288 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 289 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 290 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 291 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 292 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 293 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 294 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 295 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 296 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 297 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 298 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 299 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 300 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 301 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 302 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 303 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 304 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 305 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
