# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-27 20:41 UTC

**Git SHA**: `3c0d4817f8`

**Run Duration**: 191m 25s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **871** (71.3%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **897** (73.5%) |
| Failing | 324 |
| Total expected lines | 151253 |
| Matching lines | 105555 (69.8%) |
| Mismatched lines | 45698 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 321 | 99.1% |
| Runtime Error | 3 | 0.9% |

## Passing Tests

**871 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 13.3s |  |
| 2 | `agal_compiler` | 13 | 6.9s |  |
| 3 | `air_hidden_lookup` | 2 | 4.7s |  |
| 4 | `all_classes/security/swf11` | 3 | 4.6s |  |
| 5 | `amf_custom_obj` | 26 | 4.8s |  |
| 6 | `amf_dictionary` | 9 | 4.6s |  |
| 7 | `amf_function` | 46 | 4.6s |  |
| 8 | `amf_invalid_date` | 2 | 4.5s |  |
| 9 | `amf_missing_prop` | 6 | 4.7s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.2s |  |
| 11 | `amf_setter_error` | 8 | 6.2s |  |
| 12 | `amf_vector` | 40 | 6.3s |  |
| 13 | `amf_xml` | 6 | 6.1s |  |
| 14 | `application_domain` | 4 | 6.1s |  |
| 15 | `array_access` | 18 | 6.2s |  |
| 16 | `array_access_interpreter` | 4 | 6.1s |  |
| 17 | `array_access_no_pubns` | 2 | 6.1s |  |
| 18 | `array_concat` | 41 | 6.2s |  |
| 19 | `array_constr` | 10 | 6.1s |  |
| 20 | `array_delete` | 44 | 6.2s |  |
| 21 | `array_enumeration` | 10 | 6.2s |  |
| 22 | `array_enumeration_elements` | 11 | 6.1s |  |
| 23 | `array_every` | 8 | 6.1s |  |
| 24 | `array_filter` | 6 | 6.1s |  |
| 25 | `array_foreach` | 18 | 6.1s |  |
| 26 | `array_hasownproperty` | 11 | 2.9s |  |
| 27 | `array_holes` | 9 | 6.1s |  |
| 28 | `array_index_max` | 84 | 6.0s |  |
| 29 | `array_indexof` | 25 | 6.2s |  |
| 30 | `array_join` | 26 | 6.1s |  |
| 31 | `array_lastindexof` | 29 | 6.2s |  |
| 32 | `array_length` | 14 | 6.1s |  |
| 33 | `array_literal` | 3 | 6.1s |  |
| 34 | `array_map` | 8 | 6.0s |  |
| 35 | `array_pop` | 52 | 6.2s |  |
| 36 | `array_push` | 24 | 6.1s |  |
| 37 | `array_reborrow_bug` | 6 | 6.1s |  |
| 38 | `array_reverse` | 28 | 6.1s |  |
| 39 | `array_shift` | 51 | 3.0s |  |
| 40 | `array_slice` | 39 | 6.2s |  |
| 41 | `array_some` | 8 | 6.2s |  |
| 42 | `array_sort` | 297 | 6.7s |  |
| 43 | `array_sort_fun_swf12` | 2 | 6.1s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 45 | `array_sort_random` | 210 | 6.2s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 6.1s |  |
| 47 | `array_sorton` | 545 | 6.7s |  |
| 48 | `array_sparse_ops` | 41 | 6.0s |  |
| 49 | `array_splice` | 133 | 6.2s |  |
| 50 | `array_splice2` | 428 | 6.2s |  |
| 51 | `array_splice_types` | 48 | 6.0s |  |
| 52 | `array_storage` | 8 | 5.9s |  |
| 53 | `array_tolocalestring` | 9 | 5.9s |  |
| 54 | `array_tostring` | 12 | 5.9s |  |
| 55 | `array_unshift` | 24 | 5.9s |  |
| 56 | `array_valueof` | 9 | 5.8s |  |
| 57 | `array_vector_null_callback` | 10 | 5.9s |  |
| 58 | `astype` | 28 | 6.0s |  |
| 59 | `astypelate` | 24 | 6.0s |  |
| 60 | `astypelate_propagates` | 1 | 5.8s |  |
| 61 | `asymmetric_key_events` | 11 | 6.1s |  |
| 62 | `avm2_catchup_dobj` | 158 | 6.4s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 78.0s |  |
| 64 | `bitand` | 1058 | 18.1s |  |
| 65 | `bitmap_constr` | 17 | 6.2s |  |
| 66 | `bitmap_data` | 1000 | 14.1s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 24.9s |  |
| 68 | `bitmap_properties` | 23 | 6.0s |  |
| 69 | `bitmap_subclass` | 7 | 7.5s |  |
| 70 | `bitmap_subclass_properties` | 9 | 6.5s |  |
| 71 | `bitmap_timeline` | 9 | 6.1s |  |
| 72 | `bitmapdata_accuracy` | 1 | 44.8s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 25.6s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.9s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 24.9s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.5s |  |
| 77 | `bitmapdata_clone` | 13 | 6.3s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.6s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 6.0s |  |
| 80 | `bitmapdata_constr` | 22 | 6.0s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 6.2s |  |
| 82 | `bitmapdata_copychannel` | 0 | 29.1s |  |
| 83 | `bitmapdata_copypixels` | 23 | 27.6s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 6.5s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 6.4s |  |
| 86 | `bitmapdata_dispose` | 7 | 6.3s |  |
| 87 | `bitmapdata_draw` | 0 | 26.7s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.7s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.8s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 26.1s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 6.5s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.8s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.8s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 25.8s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 6.8s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.7s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.7s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 26.2s |  |
| 99 | `bitmapdata_floodfill` | 35 | 6.4s |  |
| 100 | `bitmapdata_getpixels` | 39 | 26.0s |  |
| 101 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 102 | `bitmapdata_histogram` | 59 | 3.1s |  |
| 103 | `bitmapdata_hittest` | 112 | 7.0s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 6.3s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.8s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 25.6s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.9s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 6.3s |  |
| 109 | `bitmapdata_setpixels` | 286 | 6.4s |  |
| 110 | `bitmapdata_setvector` | 26 | 6.5s |  |
| 111 | `bitmapdata_sync` | 0 | 6.7s |  |
| 112 | `bitmapdata_threshold` | 176 | 7.0s |  |
| 113 | `bitnot` | 46 | 6.5s |  |
| 114 | `bitor` | 1058 | 18.7s |  |
| 115 | `bitxor` | 1058 | 18.6s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.8s |  |
| 117 | `blend_scroll` | 0 | 6.8s |  |
| 118 | `boolean_constr` | 32 | 6.0s |  |
| 119 | `boolean_negation` | 30 | 5.9s |  |
| 120 | `boolean_tostring` | 8 | 5.9s |  |
| 121 | `broadcast_event` | 7 | 5.9s |  |
| 122 | `button_nested_frame` | 48 | 24.5s |  |
| 123 | `bytearray` | 48 | 6.2s |  |
| 124 | `bytearray_compress` | 31 | 5.9s |  |
| 125 | `bytearray_errors` | 24 | 6.0s |  |
| 126 | `bytearray_method_serialization` | 1 | 5.8s |  |
| 127 | `bytearray_oom` | 3 | 6.0s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 5.9s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 5.9s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 6.0s |  |
| 131 | `bytearray_serialization` | 3 | 5.9s |  |
| 132 | `bytearray_string_null` | 19 | 6.2s |  |
| 133 | `bytearray_tostring` | 15 | 5.9s |  |
| 134 | `bytearray_utf16` | 8 | 5.8s |  |
| 135 | `bytearray_writeobject` | 24 | 5.8s |  |
| 136 | `callee_in_initializer` | 6 | 5.8s |  |
| 137 | `callproplex_class` | 1 | 5.9s |  |
| 138 | `capabilities_resolution` | 8 | 24.7s |  |
| 139 | `catch_class` | 6 | 5.9s |  |
| 140 | `catch_scope_slot` | 7 | 2.8s |  |
| 141 | `checkfilter` | 4 | 2.8s |  |
| 142 | `class_call` | 32 | 23.9s |  |
| 143 | `class_cast_call` | 14 | 5.9s |  |
| 144 | `class_enumeration` | 4 | 6.0s |  |
| 145 | `class_has_own_property` | 2 | 5.9s |  |
| 146 | `class_init_interpreter_mode` | 1 | 5.8s |  |
| 147 | `class_is` | 32 | 6.0s |  |
| 148 | `class_methods` | 5 | 5.9s |  |
| 149 | `class_object_properties` | 10 | 5.9s |  |
| 150 | `class_singleton` | 18 | 5.9s |  |
| 151 | `class_supercalls_errors` | 35 | 6.1s |  |
| 152 | `class_supercalls_mismatched` | 26 | 6.0s |  |
| 153 | `class_superclass_wrong_order` | 1 | 19.3s |  |
| 154 | `class_to_locale_string` | 2 | 4.9s |  |
| 155 | `class_to_string` | 2 | 4.7s |  |
| 156 | `class_value_of` | 2 | 4.8s |  |
| 157 | `click_block` | 5 | 19.8s |  |
| 158 | `click_invisible` | 3 | 5.1s |  |
| 159 | `closures` | 12 | 4.8s |  |
| 160 | `coerce_return_type` | 40 | 5.0s |  |
| 161 | `coerce_return_type_fail` | 2 | 4.7s |  |
| 162 | `coerce_return_void` | 3 | 5.7s |  |
| 163 | `coerce_string` | 86 | 4.9s |  |
| 164 | `coerce_string_precision` | 28 | 5.0s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 19.6s |  |
| 166 | `construct_errors_swf10` | 8 | 4.8s |  |
| 167 | `construct_frame_list` | 22 | 19.8s |  |
| 168 | `constructor_call` | 3 | 5.0s |  |
| 169 | `constructors_vs_timeline` | 5 | 19.6s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 4.9s |  |
| 171 | `control_flow_bool` | 4 | 5.1s |  |
| 172 | `control_flow_stricteq` | 8 | 4.9s |  |
| 173 | `convert_boolean` | 30 | 5.1s |  |
| 174 | `convert_integer` | 90 | 5.2s |  |
| 175 | `convert_number` | 56 | 5.3s |  |
| 176 | `convert_uinteger` | 90 | 5.3s |  |
| 177 | `cryptscore` | 11 | 5.5s |  |
| 178 | `date` | 30 | 6.0s |  |
| 179 | `date_parse` | 36 | 5.6s |  |
| 180 | `declocal` | 46 | 5.7s |  |
| 181 | `declocal_i` | 46 | 5.6s |  |
| 182 | `decode_uri` | 71 | 6.0s |  |
| 183 | `decrement` | 46 | 5.6s |  |
| 184 | `decrement_i` | 46 | 2.5s |  |
| 185 | `default_values` | 7 | 5.6s |  |
| 186 | `dictionary_access` | 62 | 5.9s |  |
| 187 | `dictionary_access_no_pubns` | 2 | 5.9s |  |
| 188 | `dictionary_delete` | 101 | 6.1s |  |
| 189 | `dictionary_foreach` | 42 | 5.8s |  |
| 190 | `dictionary_hasownproperty` | 63 | 5.9s |  |
| 191 | `dictionary_in` | 62 | 5.9s |  |
| 192 | `dictionary_iter_modify` | 8 | 5.6s |  |
| 193 | `dictionary_namespaces` | 36 | 5.7s |  |
| 194 | `dictionary_primitive_keys` | 29 | 5.6s |  |
| 195 | `displayobject_alpha` | 277 | 5.6s |  |
| 196 | `displayobject_blendmode` | 0 | 5.8s |  |
| 197 | `displayobject_colortransform_nested` | 0 | 24.9s |  |
| 198 | `displayobject_from_enterframe` | 1 | 24.5s |  |
| 199 | `displayobject_getbounds_shape` | 0 | 24.6s |  |
| 200 | `displayobject_height` | 6052 | 24.7s |  |
| 201 | `displayobject_hittestobject` | 32 | 5.7s |  |
| 202 | `displayobject_invalid_floats` | 60 | 5.6s |  |
| 203 | `displayobject_invalid_props` | 3 | 5.6s |  |
| 204 | `displayobject_mask` | 3 | 6.0s |  |
| 205 | `displayobject_mask_self_referential` | 0 | 24.4s |  |
| 206 | `displayobject_metaData` | 3 | 6.1s |  |
| 207 | `displayobject_name` | 22 | 24.3s |  |
| 208 | `displayobject_name_from_timeline` | 24 | 24.5s |  |
| 209 | `displayobject_parent` | 12 | 6.1s |  |
| 210 | `displayobject_root` | 24 | 6.1s |  |
| 211 | `displayobject_rotation` | 1284 | 6.3s |  |
| 212 | `displayobject_set_matrix_nested` | 0 | 25.1s |  |
| 213 | `displayobject_set_name_loaded` | 3 | 6.4s |  |
| 214 | `displayobject_subclass` | 2 | 6.0s |  |
| 215 | `displayobject_visible` | 23 | 6.0s |  |
| 216 | `displayobject_width` | 4852 | 24.8s |  |
| 217 | `displayobject_x` | 614 | 6.0s |  |
| 218 | `displayobject_y` | 617 | 6.0s |  |
| 219 | `displayobjectcontainer_addchild` | 32 | 6.1s |  |
| 220 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.0s |  |
| 221 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.3s |  |
| 222 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.3s |  |
| 223 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.3s |  |
| 224 | `displayobjectcontainer_addchildat` | 42 | 6.2s |  |
| 225 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.3s |  |
| 226 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.5s |  |
| 227 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.2s |  |
| 228 | `displayobjectcontainer_contains` | 66 | 25.2s |  |
| 229 | `displayobjectcontainer_getchildat` | 4 | 6.2s |  |
| 230 | `displayobjectcontainer_getchildbyname` | 9 | 6.1s |  |
| 231 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.2s |  |
| 232 | `displayobjectcontainer_getchildindex` | 28 | 6.2s |  |
| 233 | `displayobjectcontainer_removechild` | 10 | 6.3s |  |
| 234 | `displayobjectcontainer_removechild_errors` | 4 | 6.1s |  |
| 235 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.3s |  |
| 236 | `displayobjectcontainer_removechildat` | 18 | 6.3s |  |
| 237 | `displayobjectcontainer_removechildren` | 51 | 6.5s |  |
| 238 | `displayobjectcontainer_setchildindex` | 42 | 6.2s |  |
| 239 | `displayobjectcontainer_stopallmovieclips` | 2 | 26.1s |  |
| 240 | `displayobjectcontainer_swapchildren` | 42 | 6.4s |  |
| 241 | `displayobjectcontainer_swapchildrenat` | 42 | 6.3s |  |
| 242 | `displayobjectcontainer_timelineinstance` | 48 | 26.1s |  |
| 243 | `divide` | 1058 | 18.8s |  |
| 244 | `doabc_is_eager` | 1 | 25.6s |  |
| 245 | `documentclass` | 9 | 6.3s |  |
| 246 | `domain_memory` | 133 | 26.8s |  |
| 247 | `drag_drop` | 10 | 6.3s |  |
| 248 | `duplicate_defs` | 1 | 6.1s |  |
| 249 | `eager_init` | 1 | 6.2s |  |
| 250 | `edit_text_linkage` | 7 | 6.3s |  |
| 251 | `edittext_align` | 60 | 6.7s |  |
| 252 | `edittext_always_show_selection` | 0 | 26.1s |  |
| 253 | `edittext_antialiastype` | 296 | 6.4s |  |
| 254 | `edittext_at_point_methods_basic` | 16 | 7.7s |  |
| 255 | `edittext_autosize` | 39 | 6.5s |  |
| 256 | `edittext_autosize_align` | 0 | 26.1s |  |
| 257 | `edittext_autosize_height_dynamic` | 60 | 26.1s |  |
| 258 | `edittext_autosize_height_input` | 60 | 6.3s |  |
| 259 | `edittext_autosize_lazy_bounds_events` | 65 | 6.6s |  |
| 260 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.2s |  |
| 261 | `edittext_autosize_lazy_bounds_props` | 490 | 7.7s |  |
| 262 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.0s |  |
| 263 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.4s |  |
| 264 | `edittext_bottom_scroll_v_basic` | 210 | 6.4s |  |
| 265 | `edittext_bounds_scale` | 24 | 25.4s |  |
| 266 | `edittext_bullet` | 30 | 6.4s |  |
| 267 | `edittext_default_format` | 221 | 6.7s |  |
| 268 | `edittext_default_format_empty` | 136 | 6.6s |  |
| 269 | `edittext_empty_text_format` | 7 | 6.3s |  |
| 270 | `edittext_focus_selection` | 5 | 6.2s |  |
| 271 | `edittext_font_size` | 45 | 6.2s |  |
| 272 | `edittext_format_empty_font` | 8 | 6.2s |  |
| 273 | `edittext_get_char_index_at_point` | 4 | 26.8s |  |
| 274 | `edittext_get_line_index_at_point` | 2 | 25.9s |  |
| 275 | `edittext_get_line_index_of_char` | 76 | 7.2s |  |
| 276 | `edittext_getcharboundaries` | 172 | 6.6s |  |
| 277 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.8s |  |
| 278 | `edittext_getcharboundaries_scroll` | 85 | 26.6s |  |
| 279 | `edittext_getlinemetrics` | 146 | 6.7s |  |
| 280 | `edittext_html` | 3101 | 6.9s |  |
| 281 | `edittext_html_condensewhite` | 487 | 6.5s |  |
| 282 | `edittext_html_entity` | 4 | 6.8s |  |
| 283 | `edittext_html_font_size_swf12` | 267 | 6.6s |  |
| 284 | `edittext_html_font_size_swf13` | 273 | 6.1s |  |
| 285 | `edittext_html_roundtrip` | 17 | 6.4s |  |
| 286 | `edittext_input_control` | 12 | 6.7s |  |
| 287 | `edittext_leading` | 9 | 6.8s |  |
| 288 | `edittext_letter_spacing` | 15 | 6.5s |  |
| 289 | `edittext_line_methods` | 294 | 7.9s |  |
| 290 | `edittext_line_metrics` | 11 | 28.6s |  |
| 291 | `edittext_margins` | 25 | 6.6s |  |
| 292 | `edittext_max_scroll_h_basic` | 475 | 6.6s |  |
| 293 | `edittext_max_scroll_v_basic` | 1000 | 6.6s |  |
| 294 | `edittext_mousedown` | 3 | 6.9s |  |
| 295 | `edittext_mouseenabled` | 26 | 6.6s |  |
| 296 | `edittext_newline_character` | 22 | 6.4s |  |
| 297 | `edittext_newline_stripping` | 64 | 9.2s |  |
| 298 | `edittext_newlines` | 30 | 6.6s |  |
| 299 | `edittext_paragraph_methods` | 257 | 6.5s |  |
| 300 | `edittext_paste_events` | 8 | 6.7s |  |
| 301 | `edittext_paste_maxchars` | 4 | 6.5s |  |
| 302 | `edittext_paste_restrict` | 16 | 6.4s |  |
| 303 | `edittext_restrict` | 191 | 6.5s |  |
| 304 | `edittext_restrict_events` | 22 | 6.5s |  |
| 305 | `edittext_scrollh` | 10 | 6.5s |  |
| 306 | `edittext_selected_text` | 9 | 6.5s |  |
| 307 | `edittext_set_html_same` | 17 | 6.4s |  |
| 308 | `edittext_set_text_vs_html` | 9 | 6.4s |  |
| 309 | `edittext_stylesheet` | 536 | 6.9s |  |
| 310 | `edittext_stylesheet_custom_tag` | 76 | 6.6s |  |
| 311 | `edittext_stylesheet_display` | 272 | 6.6s |  |
| 312 | `edittext_underline` | 40 | 6.6s |  |
| 313 | `edittext_width_height` | 103 | 17.9s |  |
| 314 | `edittext_wordwrap_word` | 150 | 24.9s |  |
| 315 | `edittext_wrap_breaks` | 2375 | 6.7s |  |
| 316 | `empty_bounds` | 1 | 6.1s |  |
| 317 | `encode_uri_surrogate_pair_swf11` | 15 | 5.8s |  |
| 318 | `equals` | 512 | 9.7s |  |
| 319 | `error_geterrormessage` | 779 | 6.2s |  |
| 320 | `error_prototype` | 15 | 6.2s |  |
| 321 | `error_stack_trace_debug_swf17` | 0 | 24.5s |  |
| 322 | `error_stack_trace_debug_swf18` | 0 | 6.0s |  |
| 323 | `error_stack_trace_release_swf17` | 0 | 6.0s |  |
| 324 | `error_stack_trace_release_swf18` | 0 | 5.9s |  |
| 325 | `error_tostring` | 29 | 6.1s |  |
| 326 | `es3_inheritance` | 31 | 6.2s |  |
| 327 | `es4_inheritance` | 30 | 6.2s |  |
| 328 | `es4_interfaces` | 30 | 6.2s |  |
| 329 | `es4_method_binding` | 8 | 6.1s |  |
| 330 | `es4_oop_prototypes` | 14 | 6.3s |  |
| 331 | `es4_protected_inheritance` | 6 | 6.1s |  |
| 332 | `escape` | 71 | 6.2s |  |
| 333 | `event_bubbles` | 2 | 6.1s |  |
| 334 | `event_cancelable` | 2 | 6.0s |  |
| 335 | `event_clone` | 20 | 6.2s |  |
| 336 | `event_clone_error_redispatch` | 3 | 6.2s |  |
| 337 | `event_clone_on_redispatch` | 10 | 6.2s |  |
| 338 | `event_formattostring` | 31 | 6.2s |  |
| 339 | `event_isdefaultprevented` | 12 | 6.1s |  |
| 340 | `event_target_getter` | 5 | 2.9s |  |
| 341 | `event_target_set` | 9 | 6.0s |  |
| 342 | `event_type` | 1 | 17.2s |  |
| 343 | `event_valueof_tostring` | 18 | 6.0s |  |
| 344 | `eventdispatcher_dispatchevent` | 12 | 6.0s |  |
| 345 | `eventdispatcher_dispatchevent_cancel` | 20 | 24.1s |  |
| 346 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.0s |  |
| 347 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.0s |  |
| 348 | `eventdispatcher_dispatchevent_this` | 5 | 5.9s |  |
| 349 | `eventdispatcher_haseventlistener` | 25 | 6.0s |  |
| 350 | `eventdispatcher_interface_invoke` | 1 | 5.8s |  |
| 351 | `eventdispatcher_tostring` | 10 | 5.9s |  |
| 352 | `eventdispatcher_willtrigger` | 25 | 5.8s |  |
| 353 | `falsiness` | 30 | 6.0s |  |
| 354 | `fast_index_access` | 12 | 6.1s |  |
| 355 | `finddef` | 3 | 5.9s |  |
| 356 | `findprop_global_prototype` | 6 | 6.0s |  |
| 357 | `flash_xml` | 29 | 6.0s |  |
| 358 | `flash_xml_cloneNode` | 22 | 6.0s |  |
| 359 | `flash_xml_namespace` | 109 | 5.9s |  |
| 360 | `flash_xml_removeNode` | 60 | 5.9s |  |
| 361 | `focus_events_code` | 161 | 24.3s |  |
| 362 | `focus_events_key_same_object` | 26 | 6.0s |  |
| 363 | `focus_events_mixed_key_mouse` | 100 | 24.3s |  |
| 364 | `focus_events_mouse_same_object` | 40 | 24.9s |  |
| 365 | `focus_remove` | 20 | 25.0s |  |
| 366 | `focus_root_movie` | 4 | 26.7s |  |
| 367 | `focus_stage` | 1 | 6.2s |  |
| 368 | `focusrect` | 18 | 7.0s |  |
| 369 | `font_description_clone` | 14 | 6.2s |  |
| 370 | `font_embedded` | 24 | 25.1s |  |
| 371 | `font_enumeratefonts` | 41 | 6.8s |  |
| 372 | `font_enumeratefonts_filter` | 4 | 25.4s |  |
| 373 | `font_hasglyphs` | 40 | 6.6s |  |
| 374 | `framelabel_constr` | 5 | 6.3s |  |
| 375 | `function_call` | 12 | 6.2s |  |
| 376 | `function_call_arguments` | 46 | 6.3s |  |
| 377 | `function_call_arguments_enumerate` | 5 | 6.2s |  |
| 378 | `function_call_coercion` | 108 | 6.5s |  |
| 379 | `function_call_default` | 6 | 6.2s |  |
| 380 | `function_call_rest` | 22 | 6.2s |  |
| 381 | `function_call_types` | 3 | 6.1s |  |
| 382 | `function_call_via_apply` | 11 | 6.2s |  |
| 383 | `function_call_via_call` | 3 | 6.1s |  |
| 384 | `function_display_anonymous` | 7 | 3.0s |  |
| 385 | `function_length` | 6 | 6.2s |  |
| 386 | `function_object` | 2 | 6.4s |  |
| 387 | `function_proto` | 5 | 6.2s |  |
| 388 | `function_proto_created` | 61 | 6.2s |  |
| 389 | `function_to_locale_string` | 4 | 6.2s |  |
| 390 | `function_to_string` | 4 | 6.1s |  |
| 391 | `function_type` | 6 | 6.2s |  |
| 392 | `function_unbound_this` | 51 | 6.3s |  |
| 393 | `function_value_of` | 4 | 6.2s |  |
| 394 | `get_definition_by_name` | 11 | 6.2s |  |
| 395 | `get_qualified_class_name` | 20 | 18.4s |  |
| 396 | `get_qualified_super_class_name` | 18 | 6.4s |  |
| 397 | `get_slot_edge_cases` | 1 | 26.5s |  |
| 398 | `get_timer` | 2 | 6.5s |  |
| 399 | `getglobalslot` | 1 | 6.4s |  |
| 400 | `getouterscope` | 8 | 6.3s |  |
| 401 | `getter_different_namespace_setter` | 2 | 6.2s |  |
| 402 | `goto_button_nested_framescript` | 28 | 26.9s |  |
| 403 | `goto_in_constructframe` | 12 | 26.3s |  |
| 404 | `goto_in_scene_last_frame` | 2 | 26.0s |  |
| 405 | `goto_methods` | 56 | 6.7s |  |
| 406 | `goto_methods_swfver10` | 8 | 6.4s |  |
| 407 | `goto_nested_construct_sibling` | 18 | 6.8s |  |
| 408 | `goto_nested_framescript` | 9 | 6.5s |  |
| 409 | `goto_on_orphan` | 15 | 6.7s |  |
| 410 | `graphics_bad_direct_commands` | 5 | 9.3s |  |
| 411 | `graphics_bitmap_fill` | 0 | 28.7s |  |
| 412 | `graphics_bitmaps` | 0 | 7.2s |  |
| 413 | `graphics_direct_commands` | 0 | 7.2s |  |
| 414 | `graphics_draw_triangles` | 98 | 27.7s |  |
| 415 | `graphics_gradients` | 0 | 6.9s |  |
| 416 | `graphics_gradients_nulls` | 0 | 6.8s |  |
| 417 | `graphics_path` | 56 | 6.6s |  |
| 418 | `graphics_round_rects` | 0 | 6.5s |  |
| 419 | `graphics_simple_shapes` | 0 | 7.0s |  |
| 420 | `greaterequals` | 512 | 11.0s |  |
| 421 | `greaterthan` | 512 | 11.1s |  |
| 422 | `has_own_property` | 102 | 7.1s |  |
| 423 | `hasownproperty_namespaces` | 2 | 6.7s |  |
| 424 | `hello_world` | 1 | 6.4s |  |
| 425 | `hittest_morph` | 30 | 6.8s |  |
| 426 | `if_eq` | 10 | 6.6s |  |
| 427 | `if_gt` | 1 | 6.7s |  |
| 428 | `if_gte` | 10 | 17.8s |  |
| 429 | `if_lt` | 1 | 6.2s |  |
| 430 | `if_lte` | 10 | 6.1s |  |
| 431 | `if_ne` | 7 | 3.0s |  |
| 432 | `if_stricteq` | 6 | 6.2s |  |
| 433 | `if_strictne` | 11 | 6.2s |  |
| 434 | `in` | 102 | 6.6s |  |
| 435 | `inclocal` | 46 | 6.2s |  |
| 436 | `inclocal_i` | 46 | 6.3s |  |
| 437 | `increment` | 46 | 6.2s |  |
| 438 | `increment_i` | 46 | 6.2s |  |
| 439 | `indexing_delete` | 75 | 6.2s |  |
| 440 | `instanceof` | 58 | 6.4s |  |
| 441 | `instantiation_on_enter_frame` | 7 | 24.4s |  |
| 442 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.1s |  |
| 443 | `int_constr` | 92 | 6.3s |  |
| 444 | `int_edge_cases` | 19 | 6.2s |  |
| 445 | `int_instanceof` | 3 | 6.0s |  |
| 446 | `int_tofixed` | 1215 | 6.0s |  |
| 447 | `int_tostring` | 3375 | 6.4s |  |
| 448 | `interactiveobject_enabled` | 25 | 6.0s |  |
| 449 | `interface_namespaces` | 78 | 6.3s |  |
| 450 | `is_finite` | 46 | 6.2s |  |
| 451 | `is_nan` | 46 | 6.0s |  |
| 452 | `is_prototype_of` | 12 | 6.1s |  |
| 453 | `issue_10221` | 2 | 6.1s |  |
| 454 | `issue_13780` | 12 | 6.1s |  |
| 455 | `issue_14901` | 1 | 6.1s |  |
| 456 | `issue_17675_edittext_paste_maxchars` | 1 | 6.1s |  |
| 457 | `issue_5292` | 5 | 6.1s |  |
| 458 | `issue_8630` | 2 | 24.2s |  |
| 459 | `issue_8630_scriptremove` | 11 | 6.1s |  |
| 460 | `istype` | 24 | 3.0s |  |
| 461 | `istypelate` | 58 | 6.4s |  |
| 462 | `istypelate_coerce` | 198 | 19.1s |  |
| 463 | `jpeg_loader_context` | 6 | 25.9s |  |
| 464 | `json_errors` | 9 | 26.0s |  |
| 465 | `json_parse` | 21 | 6.4s |  |
| 466 | `json_stringify` | 12 | 6.7s |  |
| 467 | `json_stringify_order` | 1 | 6.3s |  |
| 468 | `json_version_gated` | 1 | 6.2s |  |
| 469 | `key_input_80percent` | 1812 | 6.4s |  |
| 470 | `key_input_location` | 126 | 6.4s |  |
| 471 | `key_input_numpad` | 384 | 6.3s |  |
| 472 | `lazyinit` | 17 | 6.3s |  |
| 473 | `lessequals` | 512 | 10.1s |  |
| 474 | `lessthan` | 512 | 10.1s |  |
| 475 | `loader_bitmap_transparency` | 14 | 6.4s |  |
| 476 | `loader_bytes_unknown_content` | 14 | 6.4s |  |
| 477 | `loader_error_in_root_ctor` | 4 | 6.6s |  |
| 478 | `loader_events` | 92 | 8.8s |  |
| 479 | `loader_image` | 8 | 6.8s |  |
| 480 | `loader_jpegxr` | 2 | 25.7s |  |
| 481 | `loader_jpegxr_alpha` | 1 | 25.2s |  |
| 482 | `loader_loadbytes_events` | 30 | 7.1s |  |
| 483 | `loader_loadbytes_invalid_png` | 4 | 24.8s |  |
| 484 | `loader_loaderurl` | 6 | 6.8s |  |
| 485 | `loader_noninteractive_try_click_root` | 5 | 25.5s |  |
| 486 | `loader_reuse` | 38 | 6.4s |  |
| 487 | `loader_unknown_content` | 24 | 6.3s |  |
| 488 | `loader_visibility_interactive` | 1 | 6.3s |  |
| 489 | `loaderinfo_events` | 7 | 6.2s |  |
| 490 | `loaderinfo_loadurl` | 12 | 30.9s |  |
| 491 | `loaderinfo_more` | 6 | 21.9s |  |
| 492 | `loaderinfo_properties` | 18 | 5.3s |  |
| 493 | `loaderinfo_properties_not_loaded` | 23 | 6.5s |  |
| 494 | `loaderinfo_root` | 10 | 5.1s |  |
| 495 | `loaderinfo_root_allows` | 2 | 5.1s |  |
| 496 | `lshift` | 1058 | 14.5s |  |
| 497 | `mask_reapply` | 1 | 5.3s |  |
| 498 | `math` | 497 | 5.2s |  |
| 499 | `missing_external_interface` | 10 | 5.1s |  |
| 500 | `modulo` | 1058 | 14.4s |  |
| 501 | `morph_shape` | 2 | 21.1s |  |
| 502 | `mouse_children` | 192 | 20.7s |  |
| 503 | `mouse_click_events` | 90 | 20.7s |  |
| 504 | `mouse_double_click_events` | 188 | 5.0s |  |
| 505 | `mouse_empty_parent` | 4 | 5.3s |  |
| 506 | `mouse_over_while_dragging` | 3 | 5.2s |  |
| 507 | `mouse_pick_button_mode` | 2 | 5.3s |  |
| 508 | `mouse_sibling` | 8 | 5.2s |  |
| 509 | `movieclip_addframescript` | 3 | 21.1s |  |
| 510 | `movieclip_child_property` | 16 | 5.5s |  |
| 511 | `movieclip_constr` | 21 | 19.0s |  |
| 512 | `movieclip_currentlabels` | 17 | 26.7s |  |
| 513 | `movieclip_currentlabels_dupes1` | 46 | 27.1s |  |
| 514 | `movieclip_currentlabels_dupes2` | 30 | 6.2s |  |
| 515 | `movieclip_currentlabels_dupes3` | 67 | 6.2s |  |
| 516 | `movieclip_currentscene` | 12 | 27.4s |  |
| 517 | `movieclip_dispatchevent` | 430 | 6.9s |  |
| 518 | `movieclip_dispatchevent_cancel` | 102 | 6.7s |  |
| 519 | `movieclip_dispatchevent_handlerorder` | 251 | 6.5s |  |
| 520 | `movieclip_dispatchevent_selfadd` | 80 | 6.9s |  |
| 521 | `movieclip_dispatchevent_target` | 899 | 6.3s |  |
| 522 | `movieclip_displayevents` | 96 | 26.9s |  |
| 523 | `movieclip_displayevents_clickgoto` | 676 | 26.9s |  |
| 524 | `movieclip_displayevents_clickgoto2` | 2001 | 6.7s |  |
| 525 | `movieclip_displayevents_clickplay` | 575 | 6.4s |  |
| 526 | `movieclip_displayevents_clicksymbol` | 562 | 6.4s |  |
| 527 | `movieclip_displayevents_constructframegoto` | 140 | 6.5s |  |
| 528 | `movieclip_displayevents_constructframeplay` | 50 | 6.5s |  |
| 529 | `movieclip_displayevents_constructframesymbol` | 144 | 6.4s |  |
| 530 | `movieclip_displayevents_dblhandler` | 21 | 6.4s |  |
| 531 | `movieclip_displayevents_enterframegoto` | 149 | 6.5s |  |
| 532 | `movieclip_displayevents_enterframeplay` | 48 | 6.3s |  |
| 533 | `movieclip_displayevents_enterframesymbol` | 149 | 27.0s |  |
| 534 | `movieclip_displayevents_exitframegoto` | 106 | 6.4s |  |
| 535 | `movieclip_displayevents_exitframeplay` | 44 | 6.5s |  |
| 536 | `movieclip_displayevents_exitframesymbol` | 135 | 6.4s |  |
| 537 | `movieclip_displayevents_looping` | 63 | 27.2s |  |
| 538 | `movieclip_displayevents_stopped` | 113 | 6.9s |  |
| 539 | `movieclip_displayevents_swap` | 96 | 2.7s |  |
| 540 | `movieclip_displayevents_timeline` | 128 | 27.5s |  |
| 541 | `movieclip_drawrect` | 54 | 6.4s |  |
| 542 | `movieclip_frameconstruct_skipped` | 9 | 6.5s |  |
| 543 | `movieclip_goto_during_frame_script` | 15 | 6.3s |  |
| 544 | `movieclip_goto_overwrite` | 14 | 27.1s |  |
| 545 | `movieclip_goto_scene_last_frame_int` | 1 | 27.3s |  |
| 546 | `movieclip_goto_scene_last_frame_label` | 1 | 6.2s |  |
| 547 | `movieclip_gotoandplay` | 15 | 26.6s |  |
| 548 | `movieclip_gotoandstop` | 13 | 6.2s |  |
| 549 | `movieclip_gotoandstop_children` | 4 | 6.3s |  |
| 550 | `movieclip_gotoandstop_framescripts1` | 4 | 6.2s |  |
| 551 | `movieclip_gotoandstop_framescripts2` | 4 | 2.9s |  |
| 552 | `movieclip_gotoandstop_framescripts_self` | 7 | 36.6s |  |
| 553 | `movieclip_gotoandstop_queueing` | 12 | 25.0s |  |
| 554 | `movieclip_next_frame` | 2 | 24.9s |  |
| 555 | `movieclip_next_scene` | 6 | 24.9s |  |
| 556 | `movieclip_play` | 3 | 6.2s |  |
| 557 | `movieclip_prev_frame` | 3 | 6.0s |  |
| 558 | `movieclip_prev_scene` | 7 | 6.2s |  |
| 559 | `movieclip_properties` | 79 | 25.1s |  |
| 560 | `movieclip_queued_noop_goto_swf10` | 9 | 6.3s |  |
| 561 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 562 | `movieclip_scenes` | 11 | 6.2s |  |
| 563 | `movieclip_soundtransform` | 831 | 27.0s |  |
| 564 | `movieclip_stop` | 1 | 24.7s |  |
| 565 | `movieclip_super_is_symbol` | 20 | 6.5s |  |
| 566 | `movieclip_symbol_constr` | 8 | 6.4s |  |
| 567 | `movieclip_text_mousedown` | 1 | 6.3s |  |
| 568 | `movieclip_willtrigger` | 5 | 6.5s |  |
| 569 | `multiply` | 1058 | 17.6s |  |
| 570 | `namespace_constr` | 253 | 6.6s |  |
| 571 | `namespace_constr_args` | 1 | 6.2s |  |
| 572 | `namespace_enumeration_order` | 7 | 25.1s |  |
| 573 | `nan_scale` | 9 | 6.2s |  |
| 574 | `navigateToURL_target_normalize` | 107 | 25.8s |  |
| 575 | `negate` | 30 | 6.3s |  |
| 576 | `negative_volume_panned` | 0 | 6.5s |  |
| 577 | `nested_iteration` | 11 | 6.2s |  |
| 578 | `net_getClassByAlias` | 3 | 6.3s |  |
| 579 | `net_navigateToURL` | 57 | 6.3s |  |
| 580 | `newactivation_in_script_init` | 3 | 6.0s |  |
| 581 | `newclass_twice` | 3 | 5.8s |  |
| 582 | `nonconflicting_declarations` | 0 | 6.0s |  |
| 583 | `null_void_types` | 8 | 6.0s |  |
| 584 | `number_autoconv` | 21 | 24.4s |  |
| 585 | `number_autoconv_amf` | 132 | 6.0s |  |
| 586 | `number_autoconv_array_sort_32bit` | 1 | 6.0s |  |
| 587 | `number_constr` | 58 | 6.0s |  |
| 588 | `number_toexponential` | 378 | 6.0s |  |
| 589 | `number_toexponential2` | 35 | 6.0s |  |
| 590 | `number_tofixed` | 378 | 5.9s |  |
| 591 | `number_toprecision` | 350 | 6.0s |  |
| 592 | `obfuscated_class_names` | 3 | 5.9s |  |
| 593 | `object_enumeration` | 10 | 6.0s |  |
| 594 | `object_prototype` | 4 | 6.0s |  |
| 595 | `object_to_locale_string` | 2 | 5.9s |  |
| 596 | `object_to_string` | 2 | 5.8s |  |
| 597 | `object_value_of` | 2 | 2.7s |  |
| 598 | `op_coerce` | 54 | 6.0s |  |
| 599 | `op_coerce_x` | 54 | 5.9s |  |
| 600 | `op_escxattr` | 2 | 5.9s |  |
| 601 | `op_escxelem` | 2 | 5.9s |  |
| 602 | `op_lookupswitch` | 4 | 5.9s |  |
| 603 | `optimize_coerce` | 1 | 5.8s |  |
| 604 | `orphan_movie_complex` | 80 | 6.3s |  |
| 605 | `orphan_movie_reorder` | 111 | 24.7s |  |
| 606 | `package_namespace` | 7 | 5.8s |  |
| 607 | `param_default_value_has_zero_cpool_index` | 1 | 5.8s |  |
| 608 | `parent_early_access_child` | 16 | 24.5s |  |
| 609 | `parse_float` | 81 | 6.2s |  |
| 610 | `pixelbender_effect_BlurredFocus` | 0 | 28.7s |  |
| 611 | `pixelbender_effect_glassDisplace` | 0 | 11.8s |  |
| 612 | `pixelbender_effect_smudge` | 0 | 9.7s |  |
| 613 | `pixelbender_effect_tintype` | 0 | 8.9s |  |
| 614 | `pixelbender_effect_twirl` | 0 | 9.9s |  |
| 615 | `pixelbender_images` | 0 | 8.5s |  |
| 616 | `place_multiple` | 17 | 24.5s |  |
| 617 | `place_object_replace` | 9 | 6.3s |  |
| 618 | `place_object_replace_2` | 24 | 6.4s |  |
| 619 | `place_object_same_depth_frame` | 1 | 6.2s |  |
| 620 | `point` | 132 | 6.7s |  |
| 621 | `primitive_edge_cases` | 1 | 6.1s |  |
| 622 | `property_priority` | 22 | 5.4s |  |
| 623 | `property_priority_three_level` | 6 | 19.9s |  |
| 624 | `propertyisenumerable_namespaces` | 6 | 4.9s |  |
| 625 | `prototype_set_null` | 7 | 4.9s |  |
| 626 | `proxy_callproperty` | 24 | 5.0s |  |
| 627 | `proxy_deleteproperty` | 64 | 5.1s |  |
| 628 | `proxy_enumeration` | 34 | 5.0s |  |
| 629 | `proxy_getproperty` | 77 | 5.1s |  |
| 630 | `proxy_hasownproperty` | 8 | 5.2s |  |
| 631 | `proxy_hasproperty` | 32 | 5.4s |  |
| 632 | `proxy_serialize` | 9 | 5.3s |  |
| 633 | `proxy_setproperty` | 42 | 5.0s |  |
| 634 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.1s |  |
| 635 | `qname_constr` | 32 | 5.2s |  |
| 636 | `qname_constr_namespace` | 24 | 5.0s |  |
| 637 | `qname_enumeration` | 9 | 4.9s |  |
| 638 | `qname_indexing` | 23 | 5.0s |  |
| 639 | `qname_tostring` | 25 | 5.0s |  |
| 640 | `qname_valueof` | 29 | 5.0s |  |
| 641 | `regexp_constr` | 148 | 5.5s |  |
| 642 | `regexp_exec` | 19 | 5.1s |  |
| 643 | `regexp_extended` | 47 | 4.8s |  |
| 644 | `regexp_multiargs` | 1 | 4.8s |  |
| 645 | `regexp_test` | 27 | 4.9s |  |
| 646 | `regexp_toString` | 10 | 5.0s |  |
| 647 | `register_script_refresh` | 35 | 5.6s |  |
| 648 | `remove_child_clear_field` | 88 | 19.8s |  |
| 649 | `remove_dobj` | 3 | 4.8s |  |
| 650 | `resolve_order` | 4 | 5.0s |  |
| 651 | `rng` | 1 | 6.1s |  |
| 652 | `rootless` | 42 | 5.2s |  |
| 653 | `rshift` | 1058 | 14.1s |  |
| 654 | `sandbox_type_inherited` | 2 | 16.8s |  |
| 655 | `sandbox_type_local_file` | 1 | 24.0s |  |
| 656 | `scene_constr` | 8 | 5.7s |  |
| 657 | `set_local_0` | 31 | 5.5s |  |
| 658 | `set_property_is_enumerable` | 85 | 5.9s |  |
| 659 | `shape_drawrect` | 54 | 5.5s |  |
| 660 | `shared_object_no_root` | 3 | 5.4s |  |
| 661 | `simplebutton_added_to_stage` | 45 | 23.7s |  |
| 662 | `simplebutton_childevents` | 86 | 24.0s |  |
| 663 | `simplebutton_childevents_nested` | 54 | 5.8s |  |
| 664 | `simplebutton_childevents_sprite` | 13 | 5.5s |  |
| 665 | `simplebutton_childprops` | 144 | 5.7s |  |
| 666 | `simplebutton_childshuffle` | 23 | 5.4s |  |
| 667 | `simplebutton_constr` | 36 | 5.7s |  |
| 668 | `simplebutton_constr_childevents` | 48 | 5.8s |  |
| 669 | `simplebutton_constr_params` | 42 | 5.6s |  |
| 670 | `simplebutton_mouseenabled` | 26 | 5.5s |  |
| 671 | `simplebutton_multi_children` | 19 | 5.7s |  |
| 672 | `simplebutton_structure` | 27 | 5.7s |  |
| 673 | `simplebutton_symbolclass` | 68 | 5.9s |  |
| 674 | `slot_disp_id_shared_numbering` | 1 | 23.2s |  |
| 675 | `slots_force_autoassigned` | 1 | 5.5s |  |
| 676 | `sound_embeddedprops` | 26 | 6.2s |  |
| 677 | `sound_play` | 19 | 6.2s |  |
| 678 | `sound_valueof` | 33 | 6.0s |  |
| 679 | `soundchannel_soundtransform` | 835 | 26.8s |  |
| 680 | `soundchannel_soundtransform_exists` | 5 | 24.4s |  |
| 681 | `soundchannel_stop` | 8 | 24.5s |  |
| 682 | `soundmixer_buffertime` | 5 | 6.0s |  |
| 683 | `soundmixer_stopall` | 6 | 24.1s |  |
| 684 | `soundtransform` | 442 | 11.7s |  |
| 685 | `sprite_with_frames` | 0 | 26.6s |  |
| 686 | `stage3d_agal_cross_product` | 0 | 8.9s |  |
| 687 | `stage3d_bitmap` | 0 | 30.0s |  |
| 688 | `stage3d_float1_index` | 0 | 27.4s |  |
| 689 | `stage3d_fractal` | 0 | 28.2s |  |
| 690 | `stage3d_ignore_sampler_override` | 0 | 27.9s |  |
| 691 | `stage3d_program_constants_bytearray_be` | 0 | 29.2s |  |
| 692 | `stage3d_program_constants_bytearray_le` | 0 | 9.5s |  |
| 693 | `stage3d_raytrace` | 0 | 30.8s |  |
| 694 | `stage3d_rotating_cube` | 0 | 9.7s |  |
| 695 | `stage3d_sampler` | 0 | 22.8s |  |
| 696 | `stage3d_sampler_partial_upload` | 0 | 9.3s |  |
| 697 | `stage3d_stencil` | 0 | 29.9s |  |
| 698 | `stage3d_texture` | 0 | 14.2s |  |
| 699 | `stage3d_texture_bytearray` | 0 | 10.4s |  |
| 700 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.8s |  |
| 701 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.1s |  |
| 702 | `stage3d_triangle` | 0 | 9.1s |  |
| 703 | `stage3d_triangle_bytes4` | 0 | 9.2s |  |
| 704 | `stage3d_triangle_float1` | 0 | 9.1s |  |
| 705 | `stage3d_triangle_index_upload` | 0 | 9.1s |  |
| 706 | `stage_access` | 10 | 6.1s |  |
| 707 | `stage_displayobject_properties` | 24 | 6.1s |  |
| 708 | `stage_framerate_nan` | 7 | 25.5s |  |
| 709 | `stage_framerate_negative` | 6 | 6.0s |  |
| 710 | `stage_framerate_zero` | 6 | 6.0s |  |
| 711 | `stage_invalidate` | 38 | 6.5s |  |
| 712 | `stage_loaderinfo_properties` | 24 | 25.4s |  |
| 713 | `stage_mousechildren` | 2 | 6.1s |  |
| 714 | `stage_mouseenabled` | 15 | 6.0s |  |
| 715 | `stage_overriden_setters` | 31 | 6.2s |  |
| 716 | `stage_properties` | 30 | 6.1s |  |
| 717 | `static_var_with_this_in_ctor` | 2 | 6.2s |  |
| 718 | `stored_properties` | 11 | 6.0s |  |
| 719 | `strict_equality` | 34 | 6.0s |  |
| 720 | `string_call` | 13 | 6.0s |  |
| 721 | `string_case` | 23 | 6.0s |  |
| 722 | `string_char_at` | 27 | 6.0s |  |
| 723 | `string_char_code_at` | 28 | 5.9s |  |
| 724 | `string_concat_fromcharcode` | 37 | 5.9s |  |
| 725 | `string_constr` | 25 | 6.1s |  |
| 726 | `string_indexof_lastindexof` | 87 | 38.8s |  |
| 727 | `string_length` | 16 | 25.8s |  |
| 728 | `string_locale_compare` | 39 | 6.8s |  |
| 729 | `string_match` | 51 | 6.6s |  |
| 730 | `string_relational_compare` | 4 | 26.4s |  |
| 731 | `string_replace` | 51 | 6.7s |  |
| 732 | `string_search` | 41 | 6.6s |  |
| 733 | `string_slice_substr_substring` | 170 | 7.5s |  |
| 734 | `string_split` | 29 | 6.6s |  |
| 735 | `string_substr_negative` | 21 | 6.5s |  |
| 736 | `string_substr_weird` | 182 | 6.4s |  |
| 737 | `subtract` | 1058 | 18.2s |  |
| 738 | `super_get_call` | 12 | 6.5s |  |
| 739 | `supercall_two_classobjects` | 2 | 6.5s |  |
| 740 | `swf8` | 1 | 6.4s |  |
| 741 | `swf_10_queued_goto_scripts_construct` | 52 | 27.0s |  |
| 742 | `swf_9_goto_in_enter_frame` | 17 | 6.6s |  |
| 743 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.5s |  |
| 744 | `swf_9_queued_goto_scripts` | 6 | 26.0s |  |
| 745 | `swf_9_queued_goto_scripts_construct` | 28 | 1.2s |  |
| 746 | `swf_9_versioning` | 2 | 6.5s |  |
| 747 | `swf_wrong_frame_count` | 38 | 6.8s |  |
| 748 | `swf_wrong_frame_count_isplaying` | 22 | 6.4s |  |
| 749 | `symbol_class_binary_data` | 8 | 6.5s |  |
| 750 | `symbol_class_conflict` | 4 | 8.9s |  |
| 751 | `symbol_class_root_not_zero` | 1 | 6.4s |  |
| 752 | `symbolclass_invalid_utf8` | 2 | 6.4s |  |
| 753 | `tab_ordering_automatic_advanced` | 184 | 6.5s |  |
| 754 | `tab_ordering_automatic_basic` | 45 | 24.9s |  |
| 755 | `tab_ordering_children` | 116 | 6.0s |  |
| 756 | `tab_ordering_custom_basic` | 34 | 5.8s |  |
| 757 | `text_engine_fontdescription` | 27 | 6.0s |  |
| 758 | `text_run` | 7 | 5.7s |  |
| 759 | `textfield_focusin_event` | 9 | 5.8s |  |
| 760 | `textfield_input_dead_keys_windows` | 15 | 5.8s |  |
| 761 | `textfield_unload` | 39 | 24.7s |  |
| 762 | `textformat` | 1134 | 5.9s |  |
| 763 | `textformat_display` | 14 | 5.9s |  |
| 764 | `textformat_font_max_length` | 4 | 5.8s |  |
| 765 | `throw` | 3 | 5.8s |  |
| 766 | `timeline_scripts` | 3 | 5.9s |  |
| 767 | `timer` | 90 | 6.4s |  |
| 768 | `timer_events` | 3 | 5.9s |  |
| 769 | `timer_finished` | 11 | 6.0s |  |
| 770 | `timer_reset` | 8 | 5.9s |  |
| 771 | `timer_setdelay` | 5 | 5.8s |  |
| 772 | `trace` | 12 | 5.7s |  |
| 773 | `truthiness` | 30 | 17.0s |  |
| 774 | `try_catch` | 11 | 5.7s |  |
| 775 | `try_catch_typed` | 12 | 5.7s |  |
| 776 | `typeof` | 30 | 5.7s |  |
| 777 | `uint_constr` | 92 | 5.8s |  |
| 778 | `uint_tofixed` | 1215 | 5.5s |  |
| 779 | `uint_tostring` | 3375 | 5.9s |  |
| 780 | `unchecked_function` | 15 | 5.6s |  |
| 781 | `unescape` | 28 | 5.6s |  |
| 782 | `url_loader` | 25 | 5.7s |  |
| 783 | `urlrequest` | 18 | 23.8s |  |
| 784 | `urshift` | 1058 | 17.5s |  |
| 785 | `vector_class` | 36 | 6.0s |  |
| 786 | `vector_class_call` | 11 | 5.8s |  |
| 787 | `vector_coercion` | 66 | 6.4s |  |
| 788 | `vector_concat` | 90 | 6.3s |  |
| 789 | `vector_constr` | 107 | 6.3s |  |
| 790 | `vector_enumeration` | 5 | 5.6s |  |
| 791 | `vector_every` | 92 | 6.5s |  |
| 792 | `vector_filter` | 95 | 6.5s |  |
| 793 | `vector_holes` | 24 | 5.7s |  |
| 794 | `vector_indexof` | 302 | 10.3s |  |
| 795 | `vector_insertat` | 270 | 6.8s |  |
| 796 | `vector_int_access` | 4 | 5.6s |  |
| 797 | `vector_int_delete` | 11 | 5.6s |  |
| 798 | `vector_join` | 58 | 6.0s |  |
| 799 | `vector_lastindexof` | 302 | 5.5s |  |
| 800 | `vector_legacy` | 10 | 5.7s |  |
| 801 | `vector_map` | 85 | 6.3s |  |
| 802 | `vector_object_final` | 1 | 5.5s |  |
| 803 | `vector_object_toString` | 10 | 5.6s |  |
| 804 | `vector_pushpop` | 255 | 6.9s |  |
| 805 | `vector_reborrow_bug` | 10 | 37.3s |  |
| 806 | `vector_removeat` | 172 | 7.5s |  |
| 807 | `vector_reverse` | 232 | 7.4s |  |
| 808 | `vector_shiftunshift` | 252 | 7.5s |  |
| 809 | `vector_slice` | 331 | 8.0s |  |
| 810 | `vector_sort` | 905 | 15.9s |  |
| 811 | `vector_splice` | 693 | 10.5s |  |
| 812 | `vector_splice_fixed_bug_compat` | 4 | 6.2s |  |
| 813 | `vector_tostring` | 79 | 6.8s |  |
| 814 | `verify_abnormal_loop` | 1 | 6.1s |  |
| 815 | `verify_exception_targets_edge_case` | 1 | 6.1s |  |
| 816 | `verify_lookup_switch_edge_case` | 1 | 6.1s |  |
| 817 | `verify_unreachable_exception` | 2 | 6.1s |  |
| 818 | `versioned_isplaying` | 2 | 6.2s |  |
| 819 | `virtual_properties` | 16 | 6.3s |  |
| 820 | `with` | 4 | 6.3s |  |
| 821 | `wrong_arg_count` | 7 | 6.4s |  |
| 822 | `xml_abstract_equality` | 36 | 6.6s |  |
| 823 | `xml_advanced` | 52 | 6.3s |  |
| 824 | `xml_appendchild` | 10 | 6.3s |  |
| 825 | `xml_as_attribute` | 9 | 6.3s |  |
| 826 | `xml_attribute` | 35 | 6.5s |  |
| 827 | `xml_attribute_name` | 40 | 6.3s |  |
| 828 | `xml_basic` | 33 | 6.4s |  |
| 829 | `xml_child` | 25 | 6.4s |  |
| 830 | `xml_childindex` | 7 | 6.2s |  |
| 831 | `xml_children` | 43 | 6.7s |  |
| 832 | `xml_class_call` | 9 | 6.2s |  |
| 833 | `xml_contains` | 197 | 6.3s |  |
| 834 | `xml_copy` | 20 | 36.8s |  |
| 835 | `xml_ctor_from_tostring` | 23 | 6.4s |  |
| 836 | `xml_delete` | 114 | 6.2s |  |
| 837 | `xml_descendants` | 83 | 6.1s |  |
| 838 | `xml_elements` | 6 | 6.1s |  |
| 839 | `xml_equals_namespace_check` | 2 | 6.0s |  |
| 840 | `xml_explicit_use_namespace` | 5 | 24.0s |  |
| 841 | `xml_getdescendants_qname` | 21 | 6.0s |  |
| 842 | `xml_has_property_via_in` | 26 | 6.1s |  |
| 843 | `xml_hasownproperty` | 6 | 6.0s |  |
| 844 | `xml_ignore_white` | 6 | 6.1s |  |
| 845 | `xml_length` | 2 | 6.0s |  |
| 846 | `xml_list_as_attribute` | 9 | 6.0s |  |
| 847 | `xml_list_concat` | 20 | 6.0s |  |
| 848 | `xml_list_enumerate` | 4 | 5.9s |  |
| 849 | `xml_methods_settings` | 3 | 6.0s |  |
| 850 | `xml_mismatched_tag` | 37 | 6.0s |  |
| 851 | `xml_namespace` | 39 | 6.0s |  |
| 852 | `xml_namespace_methods` | 245 | 6.1s |  |
| 853 | `xml_namespaced_property` | 7 | 6.0s |  |
| 854 | `xml_no_namespace` | 1 | 6.0s |  |
| 855 | `xml_nodekind` | 3 | 6.0s |  |
| 856 | `xml_normalize` | 35 | 6.2s |  |
| 857 | `xml_notification_bubbling` | 361 | 6.0s |  |
| 858 | `xml_parent` | 8 | 6.1s |  |
| 859 | `xml_set_children` | 17 | 6.2s |  |
| 860 | `xml_set_name` | 34 | 6.1s |  |
| 861 | `xml_settings` | 6 | 2.8s |  |
| 862 | `xml_simple_complex_content` | 47 | 6.1s |  |
| 863 | `xml_text` | 7 | 6.1s |  |
| 864 | `xml_tostring` | 6 | 6.1s |  |
| 865 | `xml_tostring_namespace` | 12 | 6.2s |  |
| 866 | `xml_unescaping` | 23 | 6.2s |  |
| 867 | `xml_weird_ignores` | 54 | 6.2s |  |
| 868 | `xml_wildcard` | 11 | 6.0s |  |
| 869 | `xmldocument` | 254 | 6.2s |  |
| 870 | `xmlnode` | 3540 | 6.2s |  |
| 871 | `zero_frame_clip` | 3 | 6.4s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.0s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 24.0s |  |
| 3 | `blend_transform` | 1 | 1 | 6.8s |  |
| 4 | `coerce_property` | 3 | 3 | 5.1s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.0s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 24.1s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.5s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 38.3s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.6s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.2s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.2s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 6.2s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 26.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 27.7s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.3s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.3s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 5.7s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.4s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 23.2s |  |
| 20 | `soundchannel_position` | 74 | 74 | 25.5s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.2s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.0s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.8s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.8s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 6.1s |  |

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
| 21 | `mouse_wheel_events` | 91.7% | 33 | 36 | 3 |  |
| 22 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 23 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 24 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 25 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 26 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 27 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 28 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 29 | `mouseevent_valueof_tostring` | 85.7% | 24 | 28 | 4 |  |
| 30 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 31 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 32 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 33 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 34 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 35 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 36 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 37 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 38 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 39 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 40 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 41 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 42 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 43 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 44 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 45 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 46 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 47 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 48 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 49 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 50 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 51 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 52 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 53 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 54 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3 | 5 | 2 |  |
| 55 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 56 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 57 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 58 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 59 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 60 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 61 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 62 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 63 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 64 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 65 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 66 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 67 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 20.6s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 5.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**321 tests** with output mismatch, sorted by match rate (best first)

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
| 21 | `mouse_wheel_events` | 91.7% | 33/36 | 36 | 36 |  |
| 22 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 23 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 24 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 25 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 26 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 27 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 28 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 29 | `mouseevent_valueof_tostring` | 85.7% | 24/28 | 28 | 28 |  |
| 30 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 31 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 32 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 33 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 34 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 35 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 36 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 37 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 38 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 39 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 40 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 41 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 42 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 43 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 44 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 45 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 46 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 47 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 48 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 49 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 50 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 51 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 52 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 53 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 54 | `tab_ordering_stage_tab_children_remove_root` | 60.0% | 3/5 | 5 | 5 |  |
| 55 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 56 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 57 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 58 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 59 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 60 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 61 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 62 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 63 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 64 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 65 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 66 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 67 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 68 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 69 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 70 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 71 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 72 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 73 | `loader_child_getdefinition` | 40.0% | 2/5 | 2 | 5 |  |
| 74 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 75 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 76 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 77 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 78 | `loader_duplicate_coerce` | 33.3% | 1/3 | 1 | 3 |  |
| 79 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 80 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 81 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 82 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 83 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 84 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 85 | `loader_duplicate_coerce_new_domain` | 25.0% | 1/4 | 1 | 4 |  |
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
| 114 | `localconnection` | 8.5% | 76/890 | 621 | 890 |  |
| 115 | `loader_loadbytes_url` | 8.3% | 1/12 | 1 | 12 |  |
| 116 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 117 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 118 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 119 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 120 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 121 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 122 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 123 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 124 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 125 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 126 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 127 | `loader_duplicate_class` | 4.2% | 2/48 | 2 | 48 |  |
| 128 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 129 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 130 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 131 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 132 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 133 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 134 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 135 | `mouseevent_stagexy` | 2.9% | 1/35 | 11 | 35 |  |
| 136 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 137 | `textbox_click` | 2.7% | 1/37 | 1 | 37 |  |
| 138 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 139 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 140 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 141 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 142 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 143 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 144 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 145 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 146 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 147 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 148 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 149 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 150 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 151 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 152 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 153 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 154 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 155 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 156 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 157 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 158 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 159 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 160 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 161 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 162 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 163 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 164 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 165 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 166 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 167 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 168 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 169 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 170 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 171 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 172 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 173 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 174 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 175 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 176 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 177 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 178 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 179 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 180 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 181 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 182 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 183 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 184 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 185 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 186 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 187 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 188 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 189 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 190 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 191 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 192 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 193 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 194 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 195 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 196 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 197 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 198 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 199 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 200 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 201 | `cross_api_version_call_newer` | 0.0% | 0/12 | 0 | 12 |  |
| 202 | `cross_api_version_call_older` | 0.0% | 0/12 | 0 | 12 |  |
| 203 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 204 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 205 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 206 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 207 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 208 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 209 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 210 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 211 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 212 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 213 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 214 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 215 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 216 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 217 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 218 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 219 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 220 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 221 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 222 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 223 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 224 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 225 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 226 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 227 | `instantiate_root_character` | 0.0% | 0/4 | 3 | 4 |  |
| 228 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 229 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 230 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 231 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 232 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 233 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 234 | `mouse_pick_masking` | 0.0% | 0/7 | 7 | 7 |  |
| 235 | `mouse_pick_non_interactive_dobj_mask` | 0.0% | 0/3 | 3 | 3 |  |
| 236 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 237 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 238 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 239 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 240 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 241 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 242 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 243 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 244 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 245 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 246 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 247 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 248 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 249 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 250 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 251 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 252 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 253 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 254 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 255 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 256 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 257 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 258 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 259 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 260 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 261 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 262 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 263 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 264 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 265 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 266 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 267 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 268 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 269 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 270 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 271 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 272 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 273 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 274 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 275 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 276 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 277 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 278 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 279 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 280 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 281 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 282 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 283 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 284 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 285 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 286 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 287 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 288 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 289 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 290 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 291 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 292 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 293 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 294 | `stage_domain_getQualifiedDefinitionNames` | 0.0% | 0/5 | 1 | 5 |  |
| 295 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 296 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 297 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 298 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 299 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 300 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 301 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 302 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 303 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 304 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 305 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 306 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 307 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 308 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 309 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 310 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 311 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 312 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 313 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 314 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 315 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 316 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 317 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 318 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 319 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 320 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 321 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
