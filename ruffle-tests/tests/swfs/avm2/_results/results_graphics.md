# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-28 04:41 UTC

**Git SHA**: `38aa0a3009`

**Run Duration**: 170m 3s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **876** (71.7%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **902** (73.9%) |
| Failing | 319 |
| Total expected lines | 151253 |
| Matching lines | 105593 (69.8%) |
| Mismatched lines | 45660 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 316 | 99.1% |
| Runtime Error | 3 | 0.9% |

## Passing Tests

**876 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.9s |  |
| 2 | `agal_compiler` | 13 | 8.8s |  |
| 3 | `air_hidden_lookup` | 2 | 6.2s |  |
| 4 | `all_classes/security/swf11` | 3 | 6.4s |  |
| 5 | `amf_custom_obj` | 26 | 6.4s |  |
| 6 | `amf_dictionary` | 9 | 6.3s |  |
| 7 | `amf_function` | 46 | 6.3s |  |
| 8 | `amf_invalid_date` | 2 | 6.4s |  |
| 9 | `amf_missing_prop` | 6 | 6.2s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.3s |  |
| 11 | `amf_setter_error` | 8 | 6.3s |  |
| 12 | `amf_vector` | 40 | 6.3s |  |
| 13 | `amf_xml` | 6 | 6.2s |  |
| 14 | `application_domain` | 4 | 6.2s |  |
| 15 | `array_access` | 18 | 6.4s |  |
| 16 | `array_access_interpreter` | 4 | 6.2s |  |
| 17 | `array_access_no_pubns` | 2 | 6.1s |  |
| 18 | `array_concat` | 41 | 6.3s |  |
| 19 | `array_constr` | 10 | 6.1s |  |
| 20 | `array_delete` | 44 | 6.3s |  |
| 21 | `array_enumeration` | 10 | 6.2s |  |
| 22 | `array_enumeration_elements` | 11 | 6.3s |  |
| 23 | `array_every` | 8 | 6.2s |  |
| 24 | `array_filter` | 6 | 6.2s |  |
| 25 | `array_foreach` | 18 | 6.2s |  |
| 26 | `array_hasownproperty` | 11 | 2.9s |  |
| 27 | `array_holes` | 9 | 6.2s |  |
| 28 | `array_index_max` | 84 | 6.2s |  |
| 29 | `array_indexof` | 25 | 6.4s |  |
| 30 | `array_join` | 26 | 6.4s |  |
| 31 | `array_lastindexof` | 29 | 6.3s |  |
| 32 | `array_length` | 14 | 6.3s |  |
| 33 | `array_literal` | 3 | 6.2s |  |
| 34 | `array_map` | 8 | 6.1s |  |
| 35 | `array_pop` | 52 | 6.3s |  |
| 36 | `array_push` | 24 | 6.2s |  |
| 37 | `array_reborrow_bug` | 6 | 6.2s |  |
| 38 | `array_reverse` | 28 | 6.2s |  |
| 39 | `array_shift` | 51 | 3.0s |  |
| 40 | `array_slice` | 39 | 6.2s |  |
| 41 | `array_some` | 8 | 6.1s |  |
| 42 | `array_sort` | 297 | 6.5s |  |
| 43 | `array_sort_fun_swf12` | 2 | 6.2s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 45 | `array_sort_random` | 210 | 6.2s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 6.2s |  |
| 47 | `array_sorton` | 545 | 7.0s |  |
| 48 | `array_sparse_ops` | 41 | 6.3s |  |
| 49 | `array_splice` | 133 | 6.4s |  |
| 50 | `array_splice2` | 428 | 6.5s |  |
| 51 | `array_splice_types` | 48 | 6.3s |  |
| 52 | `array_storage` | 8 | 6.2s |  |
| 53 | `array_tolocalestring` | 9 | 6.3s |  |
| 54 | `array_tostring` | 12 | 6.2s |  |
| 55 | `array_unshift` | 24 | 6.2s |  |
| 56 | `array_valueof` | 9 | 6.4s |  |
| 57 | `array_vector_null_callback` | 10 | 6.6s |  |
| 58 | `astype` | 28 | 6.4s |  |
| 59 | `astypelate` | 24 | 6.4s |  |
| 60 | `astypelate_propagates` | 1 | 6.3s |  |
| 61 | `asymmetric_key_events` | 11 | 6.5s |  |
| 62 | `avm2_catchup_dobj` | 158 | 7.0s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 84.0s |  |
| 64 | `bitand` | 1058 | 18.9s |  |
| 65 | `bitmap_constr` | 17 | 6.7s |  |
| 66 | `bitmap_data` | 1000 | 15.1s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 26.6s |  |
| 68 | `bitmap_properties` | 23 | 6.6s |  |
| 69 | `bitmap_subclass` | 7 | 8.0s |  |
| 70 | `bitmap_subclass_properties` | 9 | 7.0s |  |
| 71 | `bitmap_timeline` | 9 | 6.6s |  |
| 72 | `bitmapdata_accuracy` | 1 | 47.2s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 26.6s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.2s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 26.1s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.0s |  |
| 77 | `bitmapdata_clone` | 13 | 6.6s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.8s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 6.3s |  |
| 80 | `bitmapdata_constr` | 22 | 6.5s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 6.7s |  |
| 82 | `bitmapdata_copychannel` | 0 | 27.5s |  |
| 83 | `bitmapdata_copypixels` | 23 | 26.0s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 6.2s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 6.2s |  |
| 86 | `bitmapdata_dispose` | 7 | 6.2s |  |
| 87 | `bitmapdata_draw` | 0 | 25.3s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.3s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 24.8s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 24.3s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 6.1s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.4s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.4s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 24.4s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 6.4s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.4s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.4s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 24.9s |  |
| 99 | `bitmapdata_floodfill` | 35 | 6.1s |  |
| 100 | `bitmapdata_getpixels` | 39 | 24.6s |  |
| 101 | `bitmapdata_getvector` | 27 | 2.9s |  |
| 102 | `bitmapdata_histogram` | 59 | 2.9s |  |
| 103 | `bitmapdata_hittest` | 112 | 6.8s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 6.2s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.3s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 6.7s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.5s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 6.0s |  |
| 109 | `bitmapdata_setpixels` | 286 | 6.2s |  |
| 110 | `bitmapdata_setvector` | 26 | 6.2s |  |
| 111 | `bitmapdata_sync` | 0 | 6.2s |  |
| 112 | `bitmapdata_threshold` | 176 | 6.8s |  |
| 113 | `bitnot` | 46 | 6.2s |  |
| 114 | `bitor` | 1058 | 18.2s |  |
| 115 | `bitxor` | 1058 | 18.2s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.3s |  |
| 117 | `blend_scroll` | 0 | 6.4s |  |
| 118 | `boolean_constr` | 32 | 6.5s |  |
| 119 | `boolean_negation` | 30 | 6.4s |  |
| 120 | `boolean_tostring` | 8 | 6.4s |  |
| 121 | `broadcast_event` | 7 | 6.4s |  |
| 122 | `button_nested_frame` | 48 | 6.9s |  |
| 123 | `bytearray` | 48 | 6.6s |  |
| 124 | `bytearray_compress` | 31 | 6.3s |  |
| 125 | `bytearray_errors` | 24 | 6.4s |  |
| 126 | `bytearray_method_serialization` | 1 | 6.3s |  |
| 127 | `bytearray_oom` | 3 | 6.4s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 6.4s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 6.5s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 6.5s |  |
| 131 | `bytearray_serialization` | 3 | 6.4s |  |
| 132 | `bytearray_string_null` | 19 | 6.6s |  |
| 133 | `bytearray_tostring` | 15 | 6.3s |  |
| 134 | `bytearray_utf16` | 8 | 6.2s |  |
| 135 | `bytearray_writeobject` | 24 | 6.2s |  |
| 136 | `callee_in_initializer` | 6 | 6.2s |  |
| 137 | `callproplex_class` | 1 | 6.3s |  |
| 138 | `capabilities_resolution` | 8 | 25.6s |  |
| 139 | `catch_class` | 6 | 6.2s |  |
| 140 | `catch_scope_slot` | 7 | 3.0s |  |
| 141 | `checkfilter` | 4 | 3.0s |  |
| 142 | `class_call` | 32 | 6.3s |  |
| 143 | `class_cast_call` | 14 | 6.3s |  |
| 144 | `class_enumeration` | 4 | 6.2s |  |
| 145 | `class_has_own_property` | 2 | 6.2s |  |
| 146 | `class_init_interpreter_mode` | 1 | 6.2s |  |
| 147 | `class_is` | 32 | 6.4s |  |
| 148 | `class_methods` | 5 | 6.3s |  |
| 149 | `class_object_properties` | 10 | 6.3s |  |
| 150 | `class_singleton` | 18 | 6.3s |  |
| 151 | `class_supercalls_errors` | 35 | 6.5s |  |
| 152 | `class_supercalls_mismatched` | 26 | 6.4s |  |
| 153 | `class_superclass_wrong_order` | 1 | 6.4s |  |
| 154 | `class_to_locale_string` | 2 | 6.3s |  |
| 155 | `class_to_string` | 2 | 6.1s |  |
| 156 | `class_value_of` | 2 | 6.2s |  |
| 157 | `click_block` | 5 | 25.5s |  |
| 158 | `click_invisible` | 3 | 6.6s |  |
| 159 | `closures` | 12 | 6.2s |  |
| 160 | `coerce_return_type` | 40 | 6.6s |  |
| 161 | `coerce_return_type_fail` | 2 | 6.4s |  |
| 162 | `coerce_return_void` | 3 | 6.2s |  |
| 163 | `coerce_string` | 86 | 6.6s |  |
| 164 | `coerce_string_precision` | 28 | 6.4s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 6.5s |  |
| 166 | `construct_errors_swf10` | 8 | 6.3s |  |
| 167 | `construct_frame_list` | 22 | 6.6s |  |
| 168 | `constructor_call` | 3 | 6.2s |  |
| 169 | `constructors_vs_timeline` | 5 | 25.3s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 6.4s |  |
| 171 | `control_flow_bool` | 4 | 6.4s |  |
| 172 | `control_flow_stricteq` | 8 | 6.4s |  |
| 173 | `convert_boolean` | 30 | 6.4s |  |
| 174 | `convert_integer` | 90 | 6.4s |  |
| 175 | `convert_number` | 56 | 6.2s |  |
| 176 | `convert_uinteger` | 90 | 6.3s |  |
| 177 | `cross_api_version_call_older` | 12 | 6.5s |  |
| 178 | `cryptscore` | 11 | 6.3s |  |
| 179 | `date` | 30 | 5.4s |  |
| 180 | `date_parse` | 36 | 5.2s |  |
| 181 | `declocal` | 46 | 5.1s |  |
| 182 | `declocal_i` | 46 | 5.0s |  |
| 183 | `decode_uri` | 71 | 5.4s |  |
| 184 | `decrement` | 46 | 5.4s |  |
| 185 | `decrement_i` | 46 | 2.7s |  |
| 186 | `default_values` | 7 | 5.3s |  |
| 187 | `dictionary_access` | 62 | 5.4s |  |
| 188 | `dictionary_access_no_pubns` | 2 | 5.3s |  |
| 189 | `dictionary_delete` | 101 | 5.8s |  |
| 190 | `dictionary_foreach` | 42 | 5.4s |  |
| 191 | `dictionary_hasownproperty` | 63 | 5.3s |  |
| 192 | `dictionary_in` | 62 | 5.2s |  |
| 193 | `dictionary_iter_modify` | 8 | 5.0s |  |
| 194 | `dictionary_namespaces` | 36 | 5.1s |  |
| 195 | `dictionary_primitive_keys` | 29 | 5.0s |  |
| 196 | `displayobject_alpha` | 277 | 5.1s |  |
| 197 | `displayobject_blendmode` | 0 | 5.2s |  |
| 198 | `displayobject_colortransform_nested` | 0 | 20.3s |  |
| 199 | `displayobject_from_enterframe` | 1 | 5.2s |  |
| 200 | `displayobject_getbounds_shape` | 0 | 19.8s |  |
| 201 | `displayobject_height` | 6052 | 19.9s |  |
| 202 | `displayobject_hittestobject` | 32 | 5.0s |  |
| 203 | `displayobject_invalid_floats` | 60 | 5.0s |  |
| 204 | `displayobject_invalid_props` | 3 | 4.9s |  |
| 205 | `displayobject_mask` | 3 | 5.2s |  |
| 206 | `displayobject_mask_self_referential` | 0 | 5.1s |  |
| 207 | `displayobject_metaData` | 3 | 5.4s |  |
| 208 | `displayobject_name` | 22 | 5.3s |  |
| 209 | `displayobject_name_from_timeline` | 24 | 5.3s |  |
| 210 | `displayobject_parent` | 12 | 5.0s |  |
| 211 | `displayobject_root` | 24 | 5.1s |  |
| 212 | `displayobject_rotation` | 1284 | 5.3s |  |
| 213 | `displayobject_set_matrix_nested` | 0 | 20.2s |  |
| 214 | `displayobject_set_name_loaded` | 3 | 5.5s |  |
| 215 | `displayobject_subclass` | 2 | 5.3s |  |
| 216 | `displayobject_visible` | 23 | 5.1s |  |
| 217 | `displayobject_width` | 4852 | 20.1s |  |
| 218 | `displayobject_x` | 614 | 5.0s |  |
| 219 | `displayobject_y` | 617 | 5.0s |  |
| 220 | `displayobjectcontainer_addchild` | 32 | 5.0s |  |
| 221 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 5.3s |  |
| 222 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 5.3s |  |
| 223 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 5.2s |  |
| 224 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 5.5s |  |
| 225 | `displayobjectcontainer_addchildat` | 42 | 5.1s |  |
| 226 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 5.4s |  |
| 227 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 5.1s |  |
| 228 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 5.2s |  |
| 229 | `displayobjectcontainer_contains` | 66 | 5.3s |  |
| 230 | `displayobjectcontainer_getchildat` | 4 | 5.2s |  |
| 231 | `displayobjectcontainer_getchildbyname` | 9 | 5.2s |  |
| 232 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 5.2s |  |
| 233 | `displayobjectcontainer_getchildindex` | 28 | 5.1s |  |
| 234 | `displayobjectcontainer_removechild` | 10 | 5.4s |  |
| 235 | `displayobjectcontainer_removechild_errors` | 4 | 5.1s |  |
| 236 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 5.1s |  |
| 237 | `displayobjectcontainer_removechildat` | 18 | 5.0s |  |
| 238 | `displayobjectcontainer_removechildren` | 51 | 5.3s |  |
| 239 | `displayobjectcontainer_setchildindex` | 42 | 5.3s |  |
| 240 | `displayobjectcontainer_stopallmovieclips` | 2 | 5.6s |  |
| 241 | `displayobjectcontainer_swapchildren` | 42 | 5.1s |  |
| 242 | `displayobjectcontainer_swapchildrenat` | 42 | 5.1s |  |
| 243 | `displayobjectcontainer_timelineinstance` | 48 | 26.5s |  |
| 244 | `divide` | 1058 | 18.6s |  |
| 245 | `doabc_is_eager` | 1 | 25.7s |  |
| 246 | `documentclass` | 9 | 6.8s |  |
| 247 | `domain_memory` | 133 | 7.9s |  |
| 248 | `drag_drop` | 10 | 6.9s |  |
| 249 | `duplicate_defs` | 1 | 6.6s |  |
| 250 | `eager_init` | 1 | 6.8s |  |
| 251 | `edit_text_linkage` | 7 | 6.9s |  |
| 252 | `edittext_align` | 60 | 7.2s |  |
| 253 | `edittext_always_show_selection` | 0 | 27.0s |  |
| 254 | `edittext_antialiastype` | 296 | 7.0s |  |
| 255 | `edittext_at_point_methods_basic` | 16 | 8.1s |  |
| 256 | `edittext_autosize` | 39 | 7.0s |  |
| 257 | `edittext_autosize_align` | 0 | 26.9s |  |
| 258 | `edittext_autosize_height_dynamic` | 60 | 26.5s |  |
| 259 | `edittext_autosize_height_input` | 60 | 6.7s |  |
| 260 | `edittext_autosize_lazy_bounds_events` | 65 | 7.0s |  |
| 261 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.7s |  |
| 262 | `edittext_autosize_lazy_bounds_props` | 490 | 8.1s |  |
| 263 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.4s |  |
| 264 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.9s |  |
| 265 | `edittext_bottom_scroll_v_basic` | 210 | 6.8s |  |
| 266 | `edittext_bounds_scale` | 24 | 26.0s |  |
| 267 | `edittext_bullet` | 30 | 6.8s |  |
| 268 | `edittext_default_format` | 221 | 7.0s |  |
| 269 | `edittext_default_format_empty` | 136 | 6.9s |  |
| 270 | `edittext_empty_text_format` | 7 | 6.8s |  |
| 271 | `edittext_focus_selection` | 5 | 6.8s |  |
| 272 | `edittext_font_size` | 45 | 6.8s |  |
| 273 | `edittext_format_empty_font` | 8 | 6.7s |  |
| 274 | `edittext_get_char_index_at_point` | 4 | 27.6s |  |
| 275 | `edittext_get_line_index_at_point` | 2 | 27.1s |  |
| 276 | `edittext_get_line_index_of_char` | 76 | 7.8s |  |
| 277 | `edittext_getcharboundaries` | 172 | 7.2s |  |
| 278 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.0s |  |
| 279 | `edittext_getcharboundaries_scroll` | 85 | 6.8s |  |
| 280 | `edittext_getlinemetrics` | 146 | 6.8s |  |
| 281 | `edittext_html` | 3101 | 7.0s |  |
| 282 | `edittext_html_condensewhite` | 487 | 6.6s |  |
| 283 | `edittext_html_entity` | 4 | 6.9s |  |
| 284 | `edittext_html_font_size_swf12` | 267 | 6.6s |  |
| 285 | `edittext_html_font_size_swf13` | 273 | 6.3s |  |
| 286 | `edittext_html_roundtrip` | 17 | 6.6s |  |
| 287 | `edittext_input_control` | 12 | 6.7s |  |
| 288 | `edittext_leading` | 9 | 6.9s |  |
| 289 | `edittext_letter_spacing` | 15 | 6.6s |  |
| 290 | `edittext_line_methods` | 294 | 7.9s |  |
| 291 | `edittext_line_metrics` | 11 | 27.4s |  |
| 292 | `edittext_margins` | 25 | 6.7s |  |
| 293 | `edittext_max_scroll_h_basic` | 475 | 6.7s |  |
| 294 | `edittext_max_scroll_v_basic` | 1000 | 6.6s |  |
| 295 | `edittext_mousedown` | 3 | 6.9s |  |
| 296 | `edittext_mouseenabled` | 26 | 6.7s |  |
| 297 | `edittext_newline_character` | 22 | 6.6s |  |
| 298 | `edittext_newline_stripping` | 64 | 9.2s |  |
| 299 | `edittext_newlines` | 30 | 6.7s |  |
| 300 | `edittext_paragraph_methods` | 257 | 6.7s |  |
| 301 | `edittext_paste_events` | 8 | 6.9s |  |
| 302 | `edittext_paste_maxchars` | 4 | 6.7s |  |
| 303 | `edittext_paste_restrict` | 16 | 6.6s |  |
| 304 | `edittext_restrict` | 191 | 6.6s |  |
| 305 | `edittext_restrict_events` | 22 | 6.5s |  |
| 306 | `edittext_scrollh` | 10 | 6.5s |  |
| 307 | `edittext_selected_text` | 9 | 6.5s |  |
| 308 | `edittext_set_html_same` | 17 | 6.5s |  |
| 309 | `edittext_set_text_vs_html` | 9 | 6.6s |  |
| 310 | `edittext_stylesheet` | 536 | 7.0s |  |
| 311 | `edittext_stylesheet_custom_tag` | 76 | 6.5s |  |
| 312 | `edittext_stylesheet_display` | 272 | 6.6s |  |
| 313 | `edittext_underline` | 40 | 6.7s |  |
| 314 | `edittext_width_height` | 103 | 18.9s |  |
| 315 | `edittext_wordwrap_word` | 150 | 6.7s |  |
| 316 | `edittext_wrap_breaks` | 2375 | 6.9s |  |
| 317 | `empty_bounds` | 1 | 6.2s |  |
| 318 | `encode_uri_surrogate_pair_swf11` | 15 | 6.0s |  |
| 319 | `equals` | 512 | 10.5s |  |
| 320 | `error_geterrormessage` | 779 | 6.3s |  |
| 321 | `error_prototype` | 15 | 6.3s |  |
| 322 | `error_stack_trace_debug_swf17` | 0 | 24.9s |  |
| 323 | `error_stack_trace_debug_swf18` | 0 | 6.0s |  |
| 324 | `error_stack_trace_release_swf17` | 0 | 6.1s |  |
| 325 | `error_stack_trace_release_swf18` | 0 | 6.0s |  |
| 326 | `error_tostring` | 29 | 6.2s |  |
| 327 | `es3_inheritance` | 31 | 6.3s |  |
| 328 | `es4_inheritance` | 30 | 6.3s |  |
| 329 | `es4_interfaces` | 30 | 6.3s |  |
| 330 | `es4_method_binding` | 8 | 6.2s |  |
| 331 | `es4_oop_prototypes` | 14 | 6.4s |  |
| 332 | `es4_protected_inheritance` | 6 | 6.2s |  |
| 333 | `escape` | 71 | 6.3s |  |
| 334 | `event_bubbles` | 2 | 6.2s |  |
| 335 | `event_cancelable` | 2 | 6.2s |  |
| 336 | `event_clone` | 20 | 6.3s |  |
| 337 | `event_clone_error_redispatch` | 3 | 6.4s |  |
| 338 | `event_clone_on_redispatch` | 10 | 6.4s |  |
| 339 | `event_formattostring` | 31 | 6.3s |  |
| 340 | `event_isdefaultprevented` | 12 | 6.2s |  |
| 341 | `event_target_getter` | 5 | 2.9s |  |
| 342 | `event_target_set` | 9 | 6.2s |  |
| 343 | `event_type` | 1 | 18.5s |  |
| 344 | `event_valueof_tostring` | 18 | 6.3s |  |
| 345 | `eventdispatcher_dispatchevent` | 12 | 6.2s |  |
| 346 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.3s |  |
| 347 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.3s |  |
| 348 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.3s |  |
| 349 | `eventdispatcher_dispatchevent_this` | 5 | 6.2s |  |
| 350 | `eventdispatcher_haseventlistener` | 25 | 6.3s |  |
| 351 | `eventdispatcher_interface_invoke` | 1 | 6.2s |  |
| 352 | `eventdispatcher_tostring` | 10 | 6.3s |  |
| 353 | `eventdispatcher_willtrigger` | 25 | 6.2s |  |
| 354 | `falsiness` | 30 | 6.3s |  |
| 355 | `fast_index_access` | 12 | 6.4s |  |
| 356 | `finddef` | 3 | 6.3s |  |
| 357 | `findprop_global_prototype` | 6 | 6.3s |  |
| 358 | `flash_xml` | 29 | 6.4s |  |
| 359 | `flash_xml_cloneNode` | 22 | 6.2s |  |
| 360 | `flash_xml_namespace` | 109 | 6.1s |  |
| 361 | `flash_xml_removeNode` | 60 | 6.2s |  |
| 362 | `focus_events_code` | 161 | 24.9s |  |
| 363 | `focus_events_key_same_object` | 26 | 6.2s |  |
| 364 | `focus_events_mixed_key_mouse` | 100 | 24.4s |  |
| 365 | `focus_events_mouse_same_object` | 40 | 23.1s |  |
| 366 | `focus_remove` | 20 | 23.1s |  |
| 367 | `focus_root_movie` | 4 | 23.1s |  |
| 368 | `focus_stage` | 1 | 5.5s |  |
| 369 | `focusrect` | 18 | 6.2s |  |
| 370 | `font_description_clone` | 14 | 5.8s |  |
| 371 | `font_embedded` | 24 | 6.5s |  |
| 372 | `font_enumeratefonts` | 41 | 6.7s |  |
| 373 | `font_enumeratefonts_filter` | 4 | 6.4s |  |
| 374 | `font_hasglyphs` | 40 | 5.8s |  |
| 375 | `framelabel_constr` | 5 | 5.7s |  |
| 376 | `function_call` | 12 | 5.5s |  |
| 377 | `function_call_arguments` | 46 | 5.6s |  |
| 378 | `function_call_arguments_enumerate` | 5 | 5.4s |  |
| 379 | `function_call_coercion` | 108 | 5.8s |  |
| 380 | `function_call_default` | 6 | 5.3s |  |
| 381 | `function_call_rest` | 22 | 6.0s |  |
| 382 | `function_call_types` | 3 | 5.5s |  |
| 383 | `function_call_via_apply` | 11 | 5.6s |  |
| 384 | `function_call_via_call` | 3 | 5.3s |  |
| 385 | `function_display_anonymous` | 7 | 2.4s |  |
| 386 | `function_length` | 6 | 5.3s |  |
| 387 | `function_object` | 2 | 5.4s |  |
| 388 | `function_proto` | 5 | 5.3s |  |
| 389 | `function_proto_created` | 61 | 5.1s |  |
| 390 | `function_to_locale_string` | 4 | 5.2s |  |
| 391 | `function_to_string` | 4 | 5.1s |  |
| 392 | `function_type` | 6 | 5.3s |  |
| 393 | `function_unbound_this` | 51 | 5.3s |  |
| 394 | `function_value_of` | 4 | 5.5s |  |
| 395 | `get_definition_by_name` | 11 | 5.7s |  |
| 396 | `get_qualified_class_name` | 20 | 18.2s |  |
| 397 | `get_qualified_super_class_name` | 18 | 6.1s |  |
| 398 | `get_slot_edge_cases` | 1 | 6.1s |  |
| 399 | `get_timer` | 2 | 6.1s |  |
| 400 | `getglobalslot` | 1 | 6.1s |  |
| 401 | `getouterscope` | 8 | 6.1s |  |
| 402 | `getter_different_namespace_setter` | 2 | 6.0s |  |
| 403 | `goto_button_nested_framescript` | 28 | 6.5s |  |
| 404 | `goto_in_constructframe` | 12 | 6.3s |  |
| 405 | `goto_in_scene_last_frame` | 2 | 24.3s |  |
| 406 | `goto_methods` | 56 | 6.4s |  |
| 407 | `goto_methods_swfver10` | 8 | 6.2s |  |
| 408 | `goto_nested_construct_sibling` | 18 | 6.7s |  |
| 409 | `goto_nested_framescript` | 9 | 6.3s |  |
| 410 | `goto_on_orphan` | 15 | 6.5s |  |
| 411 | `graphics_bad_direct_commands` | 5 | 6.9s |  |
| 412 | `graphics_bitmap_fill` | 0 | 8.0s |  |
| 413 | `graphics_bitmaps` | 0 | 6.8s |  |
| 414 | `graphics_direct_commands` | 0 | 6.8s |  |
| 415 | `graphics_draw_triangles` | 98 | 25.2s |  |
| 416 | `graphics_gradients` | 0 | 6.5s |  |
| 417 | `graphics_gradients_nulls` | 0 | 6.3s |  |
| 418 | `graphics_path` | 56 | 6.2s |  |
| 419 | `graphics_round_rects` | 0 | 6.2s |  |
| 420 | `graphics_simple_shapes` | 0 | 6.4s |  |
| 421 | `greaterequals` | 512 | 10.1s |  |
| 422 | `greaterthan` | 512 | 10.0s |  |
| 423 | `has_own_property` | 102 | 6.7s |  |
| 424 | `hasownproperty_namespaces` | 2 | 6.1s |  |
| 425 | `hello_world` | 1 | 6.1s |  |
| 426 | `hittest_morph` | 30 | 6.3s |  |
| 427 | `if_eq` | 10 | 6.2s |  |
| 428 | `if_gt` | 1 | 6.2s |  |
| 429 | `if_gte` | 10 | 18.5s |  |
| 430 | `if_lt` | 1 | 6.3s |  |
| 431 | `if_lte` | 10 | 6.2s |  |
| 432 | `if_ne` | 7 | 3.0s |  |
| 433 | `if_stricteq` | 6 | 6.3s |  |
| 434 | `if_strictne` | 11 | 6.4s |  |
| 435 | `in` | 102 | 6.8s |  |
| 436 | `inclocal` | 46 | 6.3s |  |
| 437 | `inclocal_i` | 46 | 6.3s |  |
| 438 | `increment` | 46 | 6.3s |  |
| 439 | `increment_i` | 46 | 6.3s |  |
| 440 | `indexing_delete` | 75 | 6.3s |  |
| 441 | `instanceof` | 58 | 6.6s |  |
| 442 | `instantiation_on_enter_frame` | 7 | 25.0s |  |
| 443 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.3s |  |
| 444 | `int_constr` | 92 | 6.5s |  |
| 445 | `int_edge_cases` | 19 | 6.3s |  |
| 446 | `int_instanceof` | 3 | 6.2s |  |
| 447 | `int_tofixed` | 1215 | 6.2s |  |
| 448 | `int_tostring` | 3375 | 6.5s |  |
| 449 | `interactiveobject_enabled` | 25 | 6.2s |  |
| 450 | `interface_namespaces` | 78 | 6.5s |  |
| 451 | `is_finite` | 46 | 6.4s |  |
| 452 | `is_nan` | 46 | 6.2s |  |
| 453 | `is_prototype_of` | 12 | 6.3s |  |
| 454 | `issue_10221` | 2 | 6.3s |  |
| 455 | `issue_13780` | 12 | 6.3s |  |
| 456 | `issue_14901` | 1 | 6.3s |  |
| 457 | `issue_17675_edittext_paste_maxchars` | 1 | 6.3s |  |
| 458 | `issue_5292` | 5 | 6.3s |  |
| 459 | `issue_8630` | 2 | 6.3s |  |
| 460 | `issue_8630_scriptremove` | 11 | 6.3s |  |
| 461 | `istype` | 24 | 3.0s |  |
| 462 | `istypelate` | 58 | 6.7s |  |
| 463 | `istypelate_coerce` | 198 | 15.8s |  |
| 464 | `jpeg_loader_context` | 6 | 5.3s |  |
| 465 | `json_errors` | 9 | 20.1s |  |
| 466 | `json_parse` | 21 | 5.3s |  |
| 467 | `json_stringify` | 12 | 5.5s |  |
| 468 | `json_stringify_order` | 1 | 5.2s |  |
| 469 | `json_version_gated` | 1 | 5.2s |  |
| 470 | `key_input_80percent` | 1812 | 5.4s |  |
| 471 | `key_input_location` | 126 | 5.4s |  |
| 472 | `key_input_numpad` | 384 | 5.2s |  |
| 473 | `lazyinit` | 17 | 5.2s |  |
| 474 | `lessequals` | 512 | 8.6s |  |
| 475 | `lessthan` | 512 | 8.5s |  |
| 476 | `loader_bitmap_transparency` | 14 | 5.4s |  |
| 477 | `loader_bytes_unknown_content` | 14 | 5.2s |  |
| 478 | `loader_child_getdefinition` | 5 | 5.4s |  |
| 479 | `loader_duplicate_coerce` | 3 | 5.5s |  |
| 480 | `loader_duplicate_coerce_new_domain` | 4 | 5.2s |  |
| 481 | `loader_error_in_root_ctor` | 4 | 5.5s |  |
| 482 | `loader_events` | 92 | 5.9s |  |
| 483 | `loader_image` | 8 | 5.5s |  |
| 484 | `loader_jpegxr` | 2 | 20.7s |  |
| 485 | `loader_jpegxr_alpha` | 1 | 20.5s |  |
| 486 | `loader_loadbytes_events` | 30 | 5.9s |  |
| 487 | `loader_loadbytes_invalid_png` | 4 | 5.2s |  |
| 488 | `loader_loadbytes_url` | 12 | 5.5s |  |
| 489 | `loader_loaderurl` | 6 | 5.7s |  |
| 490 | `loader_noninteractive_try_click_root` | 5 | 20.6s |  |
| 491 | `loader_reuse` | 38 | 5.3s |  |
| 492 | `loader_unknown_content` | 24 | 5.2s |  |
| 493 | `loader_visibility_interactive` | 1 | 5.3s |  |
| 494 | `loaderinfo_events` | 7 | 5.1s |  |
| 495 | `loaderinfo_loadurl` | 12 | 18.3s |  |
| 496 | `loaderinfo_more` | 6 | 6.7s |  |
| 497 | `loaderinfo_properties` | 18 | 6.3s |  |
| 498 | `loaderinfo_properties_not_loaded` | 23 | 6.4s |  |
| 499 | `loaderinfo_root` | 10 | 6.2s |  |
| 500 | `loaderinfo_root_allows` | 2 | 6.2s |  |
| 501 | `lshift` | 1058 | 18.2s |  |
| 502 | `mask_reapply` | 1 | 6.2s |  |
| 503 | `math` | 497 | 6.4s |  |
| 504 | `missing_external_interface` | 10 | 6.4s |  |
| 505 | `modulo` | 1058 | 18.6s |  |
| 506 | `morph_shape` | 2 | 25.6s |  |
| 507 | `mouse_children` | 192 | 25.8s |  |
| 508 | `mouse_click_events` | 90 | 24.9s |  |
| 509 | `mouse_double_click_events` | 188 | 6.2s |  |
| 510 | `mouse_empty_parent` | 4 | 6.2s |  |
| 511 | `mouse_over_while_dragging` | 3 | 6.4s |  |
| 512 | `mouse_pick_button_mode` | 2 | 6.3s |  |
| 513 | `mouse_sibling` | 8 | 6.3s |  |
| 514 | `movieclip_addframescript` | 3 | 24.8s |  |
| 515 | `movieclip_child_property` | 16 | 6.4s |  |
| 516 | `movieclip_constr` | 21 | 18.8s |  |
| 517 | `movieclip_currentlabels` | 17 | 25.2s |  |
| 518 | `movieclip_currentlabels_dupes1` | 46 | 25.1s |  |
| 519 | `movieclip_currentlabels_dupes2` | 30 | 6.4s |  |
| 520 | `movieclip_currentlabels_dupes3` | 67 | 6.5s |  |
| 521 | `movieclip_currentscene` | 12 | 6.7s |  |
| 522 | `movieclip_dispatchevent` | 430 | 6.5s |  |
| 523 | `movieclip_dispatchevent_cancel` | 102 | 6.6s |  |
| 524 | `movieclip_dispatchevent_handlerorder` | 251 | 6.5s |  |
| 525 | `movieclip_dispatchevent_selfadd` | 80 | 6.4s |  |
| 526 | `movieclip_dispatchevent_target` | 899 | 6.5s |  |
| 527 | `movieclip_displayevents` | 96 | 25.4s |  |
| 528 | `movieclip_displayevents_clickgoto` | 676 | 7.0s |  |
| 529 | `movieclip_displayevents_clickgoto2` | 2001 | 7.0s |  |
| 530 | `movieclip_displayevents_clickplay` | 575 | 6.7s |  |
| 531 | `movieclip_displayevents_clicksymbol` | 562 | 6.7s |  |
| 532 | `movieclip_displayevents_constructframegoto` | 140 | 6.9s |  |
| 533 | `movieclip_displayevents_constructframeplay` | 50 | 6.8s |  |
| 534 | `movieclip_displayevents_constructframesymbol` | 144 | 6.6s |  |
| 535 | `movieclip_displayevents_dblhandler` | 21 | 6.6s |  |
| 536 | `movieclip_displayevents_enterframegoto` | 149 | 6.8s |  |
| 537 | `movieclip_displayevents_enterframeplay` | 48 | 6.6s |  |
| 538 | `movieclip_displayevents_enterframesymbol` | 149 | 25.3s |  |
| 539 | `movieclip_displayevents_exitframegoto` | 106 | 6.6s |  |
| 540 | `movieclip_displayevents_exitframeplay` | 44 | 6.6s |  |
| 541 | `movieclip_displayevents_exitframesymbol` | 135 | 6.7s |  |
| 542 | `movieclip_displayevents_looping` | 63 | 25.5s |  |
| 543 | `movieclip_displayevents_stopped` | 113 | 6.9s |  |
| 544 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 545 | `movieclip_displayevents_timeline` | 128 | 25.5s |  |
| 546 | `movieclip_drawrect` | 54 | 6.4s |  |
| 547 | `movieclip_frameconstruct_skipped` | 9 | 6.7s |  |
| 548 | `movieclip_goto_during_frame_script` | 15 | 6.5s |  |
| 549 | `movieclip_goto_overwrite` | 14 | 25.0s |  |
| 550 | `movieclip_goto_scene_last_frame_int` | 1 | 25.2s |  |
| 551 | `movieclip_goto_scene_last_frame_label` | 1 | 6.3s |  |
| 552 | `movieclip_gotoandplay` | 15 | 24.9s |  |
| 553 | `movieclip_gotoandstop` | 13 | 6.4s |  |
| 554 | `movieclip_gotoandstop_children` | 4 | 6.5s |  |
| 555 | `movieclip_gotoandstop_framescripts1` | 4 | 6.4s |  |
| 556 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 557 | `movieclip_gotoandstop_framescripts_self` | 7 | 17.8s |  |
| 558 | `movieclip_gotoandstop_queueing` | 12 | 5.9s |  |
| 559 | `movieclip_next_frame` | 2 | 6.0s |  |
| 560 | `movieclip_next_scene` | 6 | 24.1s |  |
| 561 | `movieclip_play` | 3 | 5.7s |  |
| 562 | `movieclip_prev_frame` | 3 | 5.5s |  |
| 563 | `movieclip_prev_scene` | 7 | 5.8s |  |
| 564 | `movieclip_properties` | 79 | 6.0s |  |
| 565 | `movieclip_queued_noop_goto_swf10` | 9 | 5.8s |  |
| 566 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 567 | `movieclip_scenes` | 11 | 5.7s |  |
| 568 | `movieclip_soundtransform` | 831 | 26.0s |  |
| 569 | `movieclip_stop` | 1 | 5.7s |  |
| 570 | `movieclip_super_is_symbol` | 20 | 6.0s |  |
| 571 | `movieclip_symbol_constr` | 8 | 5.8s |  |
| 572 | `movieclip_text_mousedown` | 1 | 5.8s |  |
| 573 | `movieclip_willtrigger` | 5 | 5.9s |  |
| 574 | `multiply` | 1058 | 14.9s |  |
| 575 | `namespace_constr` | 253 | 6.0s |  |
| 576 | `namespace_constr_args` | 1 | 5.7s |  |
| 577 | `namespace_enumeration_order` | 7 | 5.8s |  |
| 578 | `nan_scale` | 9 | 5.7s |  |
| 579 | `navigateToURL_target_normalize` | 107 | 24.9s |  |
| 580 | `negate` | 30 | 5.8s |  |
| 581 | `negative_volume_panned` | 0 | 6.0s |  |
| 582 | `nested_iteration` | 11 | 5.8s |  |
| 583 | `net_getClassByAlias` | 3 | 5.8s |  |
| 584 | `net_navigateToURL` | 57 | 5.8s |  |
| 585 | `newactivation_in_script_init` | 3 | 6.2s |  |
| 586 | `newclass_twice` | 3 | 6.0s |  |
| 587 | `nonconflicting_declarations` | 0 | 6.1s |  |
| 588 | `null_void_types` | 8 | 6.2s |  |
| 589 | `number_autoconv` | 21 | 6.2s |  |
| 590 | `number_autoconv_amf` | 132 | 6.1s |  |
| 591 | `number_autoconv_array_sort_32bit` | 1 | 6.1s |  |
| 592 | `number_constr` | 58 | 6.2s |  |
| 593 | `number_toexponential` | 378 | 6.2s |  |
| 594 | `number_toexponential2` | 35 | 6.1s |  |
| 595 | `number_tofixed` | 378 | 6.0s |  |
| 596 | `number_toprecision` | 350 | 6.1s |  |
| 597 | `obfuscated_class_names` | 3 | 6.0s |  |
| 598 | `object_enumeration` | 10 | 6.1s |  |
| 599 | `object_prototype` | 4 | 6.2s |  |
| 600 | `object_to_locale_string` | 2 | 6.1s |  |
| 601 | `object_to_string` | 2 | 6.0s |  |
| 602 | `object_value_of` | 2 | 2.7s |  |
| 603 | `op_coerce` | 54 | 6.1s |  |
| 604 | `op_coerce_x` | 54 | 6.2s |  |
| 605 | `op_escxattr` | 2 | 6.2s |  |
| 606 | `op_escxelem` | 2 | 6.1s |  |
| 607 | `op_lookupswitch` | 4 | 6.2s |  |
| 608 | `optimize_coerce` | 1 | 6.1s |  |
| 609 | `orphan_movie_complex` | 80 | 6.7s |  |
| 610 | `orphan_movie_reorder` | 111 | 25.0s |  |
| 611 | `package_namespace` | 7 | 6.2s |  |
| 612 | `param_default_value_has_zero_cpool_index` | 1 | 6.2s |  |
| 613 | `parent_early_access_child` | 16 | 6.6s |  |
| 614 | `parse_float` | 81 | 6.5s |  |
| 615 | `pixelbender_effect_BlurredFocus` | 0 | 29.1s |  |
| 616 | `pixelbender_effect_glassDisplace` | 0 | 11.8s |  |
| 617 | `pixelbender_effect_smudge` | 0 | 9.8s |  |
| 618 | `pixelbender_effect_tintype` | 0 | 9.0s |  |
| 619 | `pixelbender_effect_twirl` | 0 | 10.0s |  |
| 620 | `pixelbender_images` | 0 | 8.7s |  |
| 621 | `place_multiple` | 17 | 6.5s |  |
| 622 | `place_object_replace` | 9 | 6.6s |  |
| 623 | `place_object_replace_2` | 24 | 6.6s |  |
| 624 | `place_object_same_depth_frame` | 1 | 6.5s |  |
| 625 | `point` | 132 | 6.9s |  |
| 626 | `primitive_edge_cases` | 1 | 6.3s |  |
| 627 | `property_priority` | 22 | 5.2s |  |
| 628 | `property_priority_three_level` | 6 | 5.0s |  |
| 629 | `propertyisenumerable_namespaces` | 6 | 5.0s |  |
| 630 | `prototype_set_null` | 7 | 4.9s |  |
| 631 | `proxy_callproperty` | 24 | 4.9s |  |
| 632 | `proxy_deleteproperty` | 64 | 5.0s |  |
| 633 | `proxy_enumeration` | 34 | 5.0s |  |
| 634 | `proxy_getproperty` | 77 | 5.0s |  |
| 635 | `proxy_hasownproperty` | 8 | 5.0s |  |
| 636 | `proxy_hasproperty` | 32 | 5.1s |  |
| 637 | `proxy_serialize` | 9 | 5.0s |  |
| 638 | `proxy_setproperty` | 42 | 5.0s |  |
| 639 | `qname_as_lazy_name_attribute_multiname` | 1 | 4.9s |  |
| 640 | `qname_constr` | 32 | 5.0s |  |
| 641 | `qname_constr_namespace` | 24 | 5.0s |  |
| 642 | `qname_enumeration` | 9 | 5.0s |  |
| 643 | `qname_indexing` | 23 | 5.0s |  |
| 644 | `qname_tostring` | 25 | 5.0s |  |
| 645 | `qname_valueof` | 29 | 5.0s |  |
| 646 | `regexp_constr` | 148 | 5.2s |  |
| 647 | `regexp_exec` | 19 | 4.9s |  |
| 648 | `regexp_extended` | 47 | 4.9s |  |
| 649 | `regexp_multiargs` | 1 | 4.8s |  |
| 650 | `regexp_test` | 27 | 4.9s |  |
| 651 | `regexp_toString` | 10 | 4.9s |  |
| 652 | `register_script_refresh` | 35 | 5.3s |  |
| 653 | `remove_child_clear_field` | 88 | 5.3s |  |
| 654 | `remove_dobj` | 3 | 5.0s |  |
| 655 | `resolve_order` | 4 | 5.0s |  |
| 656 | `rng` | 1 | 6.2s |  |
| 657 | `rootless` | 42 | 5.0s |  |
| 658 | `rshift` | 1058 | 13.2s |  |
| 659 | `sandbox_type_inherited` | 2 | 19.9s |  |
| 660 | `sandbox_type_local_file` | 1 | 6.9s |  |
| 661 | `scene_constr` | 8 | 6.9s |  |
| 662 | `set_local_0` | 31 | 6.6s |  |
| 663 | `set_property_is_enumerable` | 85 | 7.0s |  |
| 664 | `shape_drawrect` | 54 | 6.6s |  |
| 665 | `shared_object_no_root` | 3 | 6.5s |  |
| 666 | `simplebutton_added_to_stage` | 45 | 26.4s |  |
| 667 | `simplebutton_childevents` | 86 | 7.4s |  |
| 668 | `simplebutton_childevents_nested` | 54 | 7.3s |  |
| 669 | `simplebutton_childevents_sprite` | 13 | 6.7s |  |
| 670 | `simplebutton_childprops` | 144 | 6.9s |  |
| 671 | `simplebutton_childshuffle` | 23 | 6.6s |  |
| 672 | `simplebutton_constr` | 36 | 7.0s |  |
| 673 | `simplebutton_constr_childevents` | 48 | 7.0s |  |
| 674 | `simplebutton_constr_params` | 42 | 6.9s |  |
| 675 | `simplebutton_mouseenabled` | 26 | 6.7s |  |
| 676 | `simplebutton_multi_children` | 19 | 7.0s |  |
| 677 | `simplebutton_structure` | 27 | 7.2s |  |
| 678 | `simplebutton_symbolclass` | 68 | 7.3s |  |
| 679 | `slot_disp_id_shared_numbering` | 1 | 26.0s |  |
| 680 | `slots_force_autoassigned` | 1 | 6.8s |  |
| 681 | `sound_embeddedprops` | 26 | 6.9s |  |
| 682 | `sound_play` | 19 | 6.8s |  |
| 683 | `sound_valueof` | 33 | 6.5s |  |
| 684 | `soundchannel_soundtransform` | 835 | 27.6s |  |
| 685 | `soundchannel_soundtransform_exists` | 5 | 25.5s |  |
| 686 | `soundchannel_stop` | 8 | 6.5s |  |
| 687 | `soundmixer_buffertime` | 5 | 6.4s |  |
| 688 | `soundmixer_stopall` | 6 | 6.5s |  |
| 689 | `soundtransform` | 442 | 12.3s |  |
| 690 | `sprite_with_frames` | 0 | 7.2s |  |
| 691 | `stage3d_agal_cross_product` | 0 | 9.3s |  |
| 692 | `stage3d_bitmap` | 0 | 31.1s |  |
| 693 | `stage3d_float1_index` | 0 | 28.5s |  |
| 694 | `stage3d_fractal` | 0 | 28.8s |  |
| 695 | `stage3d_ignore_sampler_override` | 0 | 29.0s |  |
| 696 | `stage3d_program_constants_bytearray_be` | 0 | 30.0s |  |
| 697 | `stage3d_program_constants_bytearray_le` | 0 | 9.8s |  |
| 698 | `stage3d_raytrace` | 0 | 32.2s |  |
| 699 | `stage3d_rotating_cube` | 0 | 10.3s |  |
| 700 | `stage3d_sampler` | 0 | 20.0s |  |
| 701 | `stage3d_sampler_partial_upload` | 0 | 8.2s |  |
| 702 | `stage3d_stencil` | 0 | 27.3s |  |
| 703 | `stage3d_texture` | 0 | 13.1s |  |
| 704 | `stage3d_texture_bytearray` | 0 | 9.5s |  |
| 705 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.8s |  |
| 706 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.1s |  |
| 707 | `stage3d_triangle` | 0 | 8.3s |  |
| 708 | `stage3d_triangle_bytes4` | 0 | 8.3s |  |
| 709 | `stage3d_triangle_float1` | 0 | 8.2s |  |
| 710 | `stage3d_triangle_index_upload` | 0 | 8.2s |  |
| 711 | `stage_access` | 10 | 5.7s |  |
| 712 | `stage_displayobject_properties` | 24 | 5.5s |  |
| 713 | `stage_framerate_nan` | 7 | 5.8s |  |
| 714 | `stage_framerate_negative` | 6 | 5.6s |  |
| 715 | `stage_framerate_zero` | 6 | 5.6s |  |
| 716 | `stage_invalidate` | 38 | 5.9s |  |
| 717 | `stage_loaderinfo_properties` | 24 | 5.9s |  |
| 718 | `stage_mousechildren` | 2 | 5.6s |  |
| 719 | `stage_mouseenabled` | 15 | 5.5s |  |
| 720 | `stage_overriden_setters` | 31 | 5.7s |  |
| 721 | `stage_properties` | 30 | 5.5s |  |
| 722 | `static_var_with_this_in_ctor` | 2 | 5.5s |  |
| 723 | `stored_properties` | 11 | 5.6s |  |
| 724 | `strict_equality` | 34 | 5.7s |  |
| 725 | `string_call` | 13 | 5.6s |  |
| 726 | `string_case` | 23 | 5.6s |  |
| 727 | `string_char_at` | 27 | 5.6s |  |
| 728 | `string_char_code_at` | 28 | 5.5s |  |
| 729 | `string_concat_fromcharcode` | 37 | 5.5s |  |
| 730 | `string_constr` | 25 | 5.6s |  |
| 731 | `string_indexof_lastindexof` | 87 | 19.4s |  |
| 732 | `string_length` | 16 | 6.5s |  |
| 733 | `string_locale_compare` | 39 | 6.8s |  |
| 734 | `string_match` | 51 | 6.7s |  |
| 735 | `string_relational_compare` | 4 | 6.5s |  |
| 736 | `string_replace` | 51 | 6.6s |  |
| 737 | `string_search` | 41 | 6.6s |  |
| 738 | `string_slice_substr_substring` | 170 | 7.5s |  |
| 739 | `string_split` | 29 | 6.5s |  |
| 740 | `string_substr_negative` | 21 | 6.4s |  |
| 741 | `string_substr_weird` | 182 | 6.5s |  |
| 742 | `subtract` | 1058 | 18.1s |  |
| 743 | `super_get_call` | 12 | 6.7s |  |
| 744 | `supercall_two_classobjects` | 2 | 6.3s |  |
| 745 | `swf8` | 1 | 6.3s |  |
| 746 | `swf_10_queued_goto_scripts_construct` | 52 | 6.7s |  |
| 747 | `swf_9_goto_in_enter_frame` | 17 | 6.5s |  |
| 748 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.6s |  |
| 749 | `swf_9_queued_goto_scripts` | 6 | 6.4s |  |
| 750 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 751 | `swf_9_versioning` | 2 | 6.5s |  |
| 752 | `swf_wrong_frame_count` | 38 | 6.7s |  |
| 753 | `swf_wrong_frame_count_isplaying` | 22 | 6.4s |  |
| 754 | `symbol_class_binary_data` | 8 | 6.4s |  |
| 755 | `symbol_class_conflict` | 4 | 6.8s |  |
| 756 | `symbol_class_root_not_zero` | 1 | 6.3s |  |
| 757 | `symbolclass_invalid_utf8` | 2 | 6.3s |  |
| 758 | `tab_ordering_automatic_advanced` | 184 | 7.7s |  |
| 759 | `tab_ordering_automatic_basic` | 45 | 6.8s |  |
| 760 | `tab_ordering_children` | 116 | 6.9s |  |
| 761 | `tab_ordering_custom_basic` | 34 | 6.7s |  |
| 762 | `text_engine_fontdescription` | 27 | 6.9s |  |
| 763 | `text_run` | 7 | 6.5s |  |
| 764 | `textfield_focusin_event` | 9 | 6.5s |  |
| 765 | `textfield_input_dead_keys_windows` | 15 | 6.6s |  |
| 766 | `textfield_unload` | 39 | 6.9s |  |
| 767 | `textformat` | 1134 | 6.6s |  |
| 768 | `textformat_display` | 14 | 6.7s |  |
| 769 | `textformat_font_max_length` | 4 | 6.6s |  |
| 770 | `throw` | 3 | 6.6s |  |
| 771 | `timeline_scripts` | 3 | 6.5s |  |
| 772 | `timer` | 90 | 7.5s |  |
| 773 | `timer_events` | 3 | 6.6s |  |
| 774 | `timer_finished` | 11 | 6.7s |  |
| 775 | `timer_reset` | 8 | 6.9s |  |
| 776 | `timer_setdelay` | 5 | 6.8s |  |
| 777 | `trace` | 12 | 6.6s |  |
| 778 | `truthiness` | 30 | 19.0s |  |
| 779 | `try_catch` | 11 | 5.4s |  |
| 780 | `try_catch_typed` | 12 | 5.3s |  |
| 781 | `typeof` | 30 | 5.3s |  |
| 782 | `uint_constr` | 92 | 5.5s |  |
| 783 | `uint_tofixed` | 1215 | 5.2s |  |
| 784 | `uint_tostring` | 3375 | 5.5s |  |
| 785 | `unchecked_function` | 15 | 5.2s |  |
| 786 | `unescape` | 28 | 5.2s |  |
| 787 | `url_loader` | 25 | 5.4s |  |
| 788 | `urlrequest` | 18 | 5.3s |  |
| 789 | `urshift` | 1058 | 16.9s |  |
| 790 | `vector_class` | 36 | 5.7s |  |
| 791 | `vector_class_call` | 11 | 5.5s |  |
| 792 | `vector_coercion` | 66 | 6.0s |  |
| 793 | `vector_concat` | 90 | 5.8s |  |
| 794 | `vector_constr` | 107 | 5.9s |  |
| 795 | `vector_enumeration` | 5 | 5.3s |  |
| 796 | `vector_every` | 92 | 6.0s |  |
| 797 | `vector_filter` | 95 | 6.1s |  |
| 798 | `vector_holes` | 24 | 5.3s |  |
| 799 | `vector_indexof` | 302 | 9.5s |  |
| 800 | `vector_insertat` | 270 | 6.3s |  |
| 801 | `vector_int_access` | 4 | 5.2s |  |
| 802 | `vector_int_delete` | 11 | 5.2s |  |
| 803 | `vector_join` | 58 | 5.7s |  |
| 804 | `vector_lastindexof` | 302 | 5.2s |  |
| 805 | `vector_legacy` | 10 | 5.3s |  |
| 806 | `vector_map` | 85 | 5.9s |  |
| 807 | `vector_object_final` | 1 | 5.2s |  |
| 808 | `vector_object_toString` | 10 | 5.2s |  |
| 809 | `vector_pushpop` | 255 | 6.4s |  |
| 810 | `vector_reborrow_bug` | 10 | 19.8s |  |
| 811 | `vector_removeat` | 172 | 8.1s |  |
| 812 | `vector_reverse` | 232 | 8.0s |  |
| 813 | `vector_shiftunshift` | 252 | 7.9s |  |
| 814 | `vector_slice` | 331 | 8.2s |  |
| 815 | `vector_sort` | 905 | 15.7s |  |
| 816 | `vector_splice` | 693 | 10.4s |  |
| 817 | `vector_splice_fixed_bug_compat` | 4 | 6.7s |  |
| 818 | `vector_tostring` | 79 | 7.4s |  |
| 819 | `verify_abnormal_loop` | 1 | 6.7s |  |
| 820 | `verify_exception_targets_edge_case` | 1 | 6.5s |  |
| 821 | `verify_lookup_switch_edge_case` | 1 | 6.5s |  |
| 822 | `verify_unreachable_exception` | 2 | 6.6s |  |
| 823 | `versioned_isplaying` | 2 | 6.7s |  |
| 824 | `virtual_properties` | 16 | 6.9s |  |
| 825 | `with` | 4 | 6.8s |  |
| 826 | `wrong_arg_count` | 7 | 7.0s |  |
| 827 | `xml_abstract_equality` | 36 | 7.0s |  |
| 828 | `xml_advanced` | 52 | 6.6s |  |
| 829 | `xml_appendchild` | 10 | 6.7s |  |
| 830 | `xml_as_attribute` | 9 | 6.5s |  |
| 831 | `xml_attribute` | 35 | 6.8s |  |
| 832 | `xml_attribute_name` | 40 | 6.7s |  |
| 833 | `xml_basic` | 33 | 6.7s |  |
| 834 | `xml_child` | 25 | 6.8s |  |
| 835 | `xml_childindex` | 7 | 6.9s |  |
| 836 | `xml_children` | 43 | 7.4s |  |
| 837 | `xml_class_call` | 9 | 6.8s |  |
| 838 | `xml_contains` | 197 | 6.9s |  |
| 839 | `xml_copy` | 20 | 18.4s |  |
| 840 | `xml_ctor_from_tostring` | 23 | 6.5s |  |
| 841 | `xml_delete` | 114 | 6.3s |  |
| 842 | `xml_descendants` | 83 | 6.2s |  |
| 843 | `xml_elements` | 6 | 6.1s |  |
| 844 | `xml_equals_namespace_check` | 2 | 6.1s |  |
| 845 | `xml_explicit_use_namespace` | 5 | 6.2s |  |
| 846 | `xml_getdescendants_qname` | 21 | 6.1s |  |
| 847 | `xml_has_property_via_in` | 26 | 6.2s |  |
| 848 | `xml_hasownproperty` | 6 | 6.1s |  |
| 849 | `xml_ignore_white` | 6 | 6.2s |  |
| 850 | `xml_length` | 2 | 6.1s |  |
| 851 | `xml_list_as_attribute` | 9 | 6.2s |  |
| 852 | `xml_list_concat` | 20 | 6.1s |  |
| 853 | `xml_list_enumerate` | 4 | 6.0s |  |
| 854 | `xml_methods_settings` | 3 | 6.2s |  |
| 855 | `xml_mismatched_tag` | 37 | 6.2s |  |
| 856 | `xml_namespace` | 39 | 6.1s |  |
| 857 | `xml_namespace_methods` | 245 | 6.2s |  |
| 858 | `xml_namespaced_property` | 7 | 6.1s |  |
| 859 | `xml_no_namespace` | 1 | 6.1s |  |
| 860 | `xml_nodekind` | 3 | 6.2s |  |
| 861 | `xml_normalize` | 35 | 6.2s |  |
| 862 | `xml_notification_bubbling` | 361 | 6.2s |  |
| 863 | `xml_parent` | 8 | 6.2s |  |
| 864 | `xml_set_children` | 17 | 6.3s |  |
| 865 | `xml_set_name` | 34 | 6.2s |  |
| 866 | `xml_settings` | 6 | 2.9s |  |
| 867 | `xml_simple_complex_content` | 47 | 6.3s |  |
| 868 | `xml_text` | 7 | 6.5s |  |
| 869 | `xml_tostring` | 6 | 6.5s |  |
| 870 | `xml_tostring_namespace` | 12 | 6.4s |  |
| 871 | `xml_unescaping` | 23 | 6.6s |  |
| 872 | `xml_weird_ignores` | 54 | 6.6s |  |
| 873 | `xml_wildcard` | 11 | 6.5s |  |
| 874 | `xmldocument` | 254 | 6.5s |  |
| 875 | `xmlnode` | 3540 | 6.7s |  |
| 876 | `zero_frame_clip` | 3 | 7.1s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.1s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.2s |  |
| 3 | `blend_transform` | 1 | 1 | 6.5s |  |
| 4 | `coerce_property` | 3 | 3 | 6.5s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.5s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 5.4s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.0s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 38.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.6s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.3s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.3s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.4s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 6.3s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 25.2s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.4s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.5s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.1s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.6s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 6.5s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.4s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.7s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.6s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 6.9s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.4s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.4s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 6.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**69 tests** within reach

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
| 39 | `focusrect_focuslost` | 77.8% | 7 | 9 | 2 |  |
| 40 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 41 | `tab_ordering_properties` | 76.4% | 559 | 732 | 173 |  |
| 42 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 43 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 44 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 45 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
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
| 57 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 58 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 59 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 60 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 61 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 62 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 63 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 64 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 65 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 66 | `mouse_pick_dobj_mask` | 50.0% | 2 | 4 | 2 |  |
| 67 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2 | 4 | 2 |  |
| 68 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 69 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 25.3s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 4.9s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.6s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**316 tests** with output mismatch, sorted by match rate (best first)

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
| 39 | `focusrect_focuslost` | 77.8% | 7/9 | 7 | 9 |  |
| 40 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 41 | `tab_ordering_properties` | 76.4% | 559/732 | 732 | 732 |  |
| 42 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 43 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 44 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 45 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
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
| 57 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 58 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 59 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 60 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 61 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 62 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 63 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 64 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 65 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 66 | `mouse_pick_dobj_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 67 | `mouse_pick_non_interactive_bitmap_mask` | 50.0% | 2/4 | 4 | 4 |  |
| 68 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 69 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 70 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 71 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 72 | `mouse_pick_text` | 44.4% | 4/9 | 9 | 8 |  |
| 73 | `tab_ordering_stage_tab_children` | 42.9% | 15/35 | 35 | 32 |  |
| 74 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 75 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 76 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 77 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 78 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 79 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 80 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 81 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 82 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 83 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 84 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 85 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 86 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 87 | `amf_array_serialization` | 23.5% | 4/17 | 4 | 17 |  |
| 88 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 89 | `focus_events_key_basic` | 22.3% | 33/148 | 148 | 132 |  |
| 90 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 91 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 92 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 93 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 94 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 95 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 96 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
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
| 121 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
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
| 290 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 291 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 292 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 293 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 294 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 295 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 296 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 297 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 298 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 299 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 300 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 301 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 302 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 303 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 304 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 305 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 306 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 307 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 308 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 309 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 310 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 311 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 312 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 313 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 314 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 315 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 316 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
