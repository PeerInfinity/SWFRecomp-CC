# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 03:40 UTC

**Git SHA**: `dfbbfc1afa`

**Run Duration**: 182m 22s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **946** (77.5%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **972** (79.6%) |
| Failing | 249 |
| Total expected lines | 151253 |
| Matching lines | 108394 (71.7%) |
| Mismatched lines | 42859 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 246 | 98.8% |
| Runtime Error | 3 | 1.2% |

## Passing Tests

**946 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 19.7s |  |
| 2 | `agal_compiler` | 13 | 9.7s |  |
| 3 | `air_datagram_socket` | 1 | 7.7s |  |
| 4 | `air_hidden_lookup` | 2 | 7.0s |  |
| 5 | `all_classes/security/swf11` | 3 | 6.7s |  |
| 6 | `amf_array_serialization` | 17 | 8.6s |  |
| 7 | `amf_custom_obj` | 26 | 6.7s |  |
| 8 | `amf_dictionary` | 9 | 6.7s |  |
| 9 | `amf_function` | 46 | 6.7s |  |
| 10 | `amf_invalid_date` | 2 | 6.6s |  |
| 11 | `amf_missing_prop` | 6 | 6.6s |  |
| 12 | `amf_nondynamic_function_prop` | 6 | 6.6s |  |
| 13 | `amf_setter_error` | 8 | 6.7s |  |
| 14 | `amf_vector` | 40 | 6.6s |  |
| 15 | `amf_xml` | 6 | 6.5s |  |
| 16 | `application_domain` | 4 | 6.6s |  |
| 17 | `array_access` | 18 | 6.5s |  |
| 18 | `array_access_interpreter` | 4 | 6.4s |  |
| 19 | `array_access_no_pubns` | 2 | 6.3s |  |
| 20 | `array_concat` | 41 | 6.5s |  |
| 21 | `array_constr` | 10 | 6.3s |  |
| 22 | `array_delete` | 44 | 6.6s |  |
| 23 | `array_enumeration` | 10 | 6.6s |  |
| 24 | `array_enumeration_elements` | 11 | 6.6s |  |
| 25 | `array_every` | 8 | 6.7s |  |
| 26 | `array_filter` | 6 | 6.6s |  |
| 27 | `array_foreach` | 18 | 6.6s |  |
| 28 | `array_hasownproperty` | 11 | 3.1s |  |
| 29 | `array_holes` | 9 | 6.6s |  |
| 30 | `array_index_max` | 84 | 6.6s |  |
| 31 | `array_indexof` | 25 | 6.7s |  |
| 32 | `array_join` | 26 | 6.7s |  |
| 33 | `array_lastindexof` | 29 | 6.6s |  |
| 34 | `array_length` | 14 | 6.7s |  |
| 35 | `array_literal` | 3 | 6.6s |  |
| 36 | `array_map` | 8 | 6.4s |  |
| 37 | `array_pop` | 52 | 6.7s |  |
| 38 | `array_push` | 24 | 6.6s |  |
| 39 | `array_reborrow_bug` | 6 | 6.6s |  |
| 40 | `array_reverse` | 28 | 6.7s |  |
| 41 | `array_shift` | 51 | 3.2s |  |
| 42 | `array_slice` | 39 | 6.7s |  |
| 43 | `array_some` | 8 | 6.6s |  |
| 44 | `array_sort` | 297 | 7.0s |  |
| 45 | `array_sort_fun_swf12` | 2 | 6.6s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 47 | `array_sort_random` | 210 | 6.6s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 6.5s |  |
| 49 | `array_sorton` | 545 | 7.2s |  |
| 50 | `array_sparse_ops` | 41 | 6.5s |  |
| 51 | `array_splice` | 133 | 6.6s |  |
| 52 | `array_splice2` | 428 | 6.7s |  |
| 53 | `array_splice_types` | 48 | 6.5s |  |
| 54 | `array_storage` | 8 | 6.4s |  |
| 55 | `array_tolocalestring` | 9 | 6.3s |  |
| 56 | `array_tostring` | 12 | 6.4s |  |
| 57 | `array_unshift` | 24 | 6.4s |  |
| 58 | `array_valueof` | 9 | 6.3s |  |
| 59 | `array_vector_null_callback` | 10 | 6.4s |  |
| 60 | `astype` | 28 | 6.5s |  |
| 61 | `astypelate` | 24 | 6.6s |  |
| 62 | `astypelate_propagates` | 1 | 6.3s |  |
| 63 | `asymmetric_key_events` | 11 | 6.5s |  |
| 64 | `av_networking_params` | 9 | 6.3s |  |
| 65 | `avm2_catchup_dobj` | 158 | 7.0s |  |
| 66 | `away3d_advanced_shallow_water_demo` | 0 | 80.2s |  |
| 67 | `bitand` | 1058 | 18.7s |  |
| 68 | `bitmap_constr` | 17 | 6.7s |  |
| 69 | `bitmap_data` | 1000 | 14.7s |  |
| 70 | `bitmap_pixelsnapping` | 2 | 25.4s |  |
| 71 | `bitmap_properties` | 23 | 6.6s |  |
| 72 | `bitmap_subclass` | 7 | 8.0s |  |
| 73 | `bitmap_subclass_properties` | 9 | 7.0s |  |
| 74 | `bitmap_timeline` | 9 | 6.6s |  |
| 75 | `bitmapdata_accuracy` | 1 | 43.4s |  |
| 76 | `bitmapdata_applyfilter_blur` | 0 | 26.1s |  |
| 77 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.3s |  |
| 78 | `bitmapdata_applyfilter_destpoint` | 0 | 26.1s |  |
| 79 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.6s |  |
| 80 | `bitmapdata_clone` | 13 | 6.9s |  |
| 81 | `bitmapdata_colortransform` | 0 | 7.2s |  |
| 82 | `bitmapdata_colortransform_oob` | 2 | 6.6s |  |
| 83 | `bitmapdata_constr` | 22 | 6.7s |  |
| 84 | `bitmapdata_constructor_from_timeline` | 1 | 6.8s |  |
| 85 | `bitmapdata_copychannel` | 0 | 29.7s |  |
| 86 | `bitmapdata_copypixels` | 23 | 28.5s |  |
| 87 | `bitmapdata_copypixels_blend_over` | 1 | 6.9s |  |
| 88 | `bitmapdata_copypixelstobytearray` | 39 | 6.8s |  |
| 89 | `bitmapdata_dispose` | 7 | 6.8s |  |
| 90 | `bitmapdata_draw` | 0 | 27.1s |  |
| 91 | `bitmapdata_draw_colortransform` | 0 | 7.0s |  |
| 92 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.8s |  |
| 93 | `bitmapdata_draw_filters` | 0 | 26.5s |  |
| 94 | `bitmapdata_draw_masks` | 0 | 6.7s |  |
| 95 | `bitmapdata_draw_rotation` | 0 | 7.0s |  |
| 96 | `bitmapdata_draw_self_via_graphic` | 0 | 7.1s |  |
| 97 | `bitmapdata_draw_stage` | 0 | 26.0s |  |
| 98 | `bitmapdata_drawwithquality` | 0 | 7.0s |  |
| 99 | `bitmapdata_embedded` | 9 | 7.1s |  |
| 100 | `bitmapdata_fillrect` | 0 | 7.0s |  |
| 101 | `bitmapdata_filter_sourcerect` | 0 | 27.2s |  |
| 102 | `bitmapdata_floodfill` | 35 | 6.7s |  |
| 103 | `bitmapdata_getpixels` | 39 | 27.0s |  |
| 104 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 105 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 106 | `bitmapdata_hittest` | 112 | 7.4s |  |
| 107 | `bitmapdata_hittest_threshold` | 18 | 6.9s |  |
| 108 | `bitmapdata_opaque` | 0 | 7.1s |  |
| 109 | `bitmapdata_pixeldissolve` | 1037 | 7.5s |  |
| 110 | `bitmapdata_pixeldissolve_image` | 0 | 7.2s |  |
| 111 | `bitmapdata_rectangle_rounding` | 16 | 6.8s |  |
| 112 | `bitmapdata_setpixels` | 286 | 6.9s |  |
| 113 | `bitmapdata_setvector` | 26 | 6.8s |  |
| 114 | `bitmapdata_sync` | 0 | 27.1s |  |
| 115 | `bitmapdata_threshold` | 176 | 7.6s |  |
| 116 | `bitnot` | 46 | 6.8s |  |
| 117 | `bitor` | 1058 | 19.0s |  |
| 118 | `bitxor` | 1058 | 19.2s |  |
| 119 | `blend_multiply_alpha` | 0 | 6.9s |  |
| 120 | `blend_scroll` | 0 | 6.9s |  |
| 121 | `boolean_constr` | 32 | 7.2s |  |
| 122 | `boolean_negation` | 30 | 7.1s |  |
| 123 | `boolean_tostring` | 8 | 7.0s |  |
| 124 | `broadcast_event` | 7 | 7.1s |  |
| 125 | `button_nested_frame` | 48 | 27.1s |  |
| 126 | `bytearray` | 48 | 7.1s |  |
| 127 | `bytearray_compress` | 31 | 6.7s |  |
| 128 | `bytearray_errors` | 24 | 6.8s |  |
| 129 | `bytearray_method_serialization` | 1 | 6.6s |  |
| 130 | `bytearray_oom` | 3 | 6.7s |  |
| 131 | `bytearray_readobject_amf0` | 50 | 6.7s |  |
| 132 | `bytearray_readobject_amf3` | 53 | 6.6s |  |
| 133 | `bytearray_readutf8bytes_with_bom` | 16 | 6.8s |  |
| 134 | `bytearray_serialization` | 3 | 6.7s |  |
| 135 | `bytearray_string_null` | 19 | 6.9s |  |
| 136 | `bytearray_tostring` | 15 | 6.6s |  |
| 137 | `bytearray_utf16` | 8 | 6.6s |  |
| 138 | `bytearray_writeobject` | 24 | 6.6s |  |
| 139 | `callee_in_initializer` | 6 | 6.5s |  |
| 140 | `callproplex_class` | 1 | 6.5s |  |
| 141 | `capabilities_resolution` | 8 | 26.4s |  |
| 142 | `catch_class` | 6 | 6.6s |  |
| 143 | `catch_scope_slot` | 7 | 3.2s |  |
| 144 | `checkfilter` | 4 | 3.2s |  |
| 145 | `class_call` | 32 | 6.9s |  |
| 146 | `class_cast_call` | 14 | 6.9s |  |
| 147 | `class_enumeration` | 4 | 6.9s |  |
| 148 | `class_has_own_property` | 2 | 6.8s |  |
| 149 | `class_init_interpreter_mode` | 1 | 6.8s |  |
| 150 | `class_is` | 32 | 6.9s |  |
| 151 | `class_methods` | 5 | 7.0s |  |
| 152 | `class_object_properties` | 10 | 6.9s |  |
| 153 | `class_singleton` | 18 | 6.7s |  |
| 154 | `class_supercalls_errors` | 35 | 6.9s |  |
| 155 | `class_supercalls_mismatched` | 26 | 6.8s |  |
| 156 | `class_superclass_wrong_order` | 1 | 25.9s |  |
| 157 | `class_to_locale_string` | 2 | 6.7s |  |
| 158 | `class_to_string` | 2 | 6.6s |  |
| 159 | `class_value_of` | 2 | 6.6s |  |
| 160 | `click_block` | 5 | 7.6s |  |
| 161 | `click_invisible` | 3 | 6.9s |  |
| 162 | `closures` | 12 | 6.8s |  |
| 163 | `coerce_return_type` | 40 | 7.1s |  |
| 164 | `coerce_return_type_fail` | 2 | 6.7s |  |
| 165 | `coerce_return_void` | 3 | 6.6s |  |
| 166 | `coerce_string` | 86 | 6.8s |  |
| 167 | `coerce_string_precision` | 28 | 6.7s |  |
| 168 | `coerce_to_primitive_side_effects` | 29 | 6.7s |  |
| 169 | `construct_errors_swf10` | 8 | 6.6s |  |
| 170 | `construct_frame_list` | 22 | 26.9s |  |
| 171 | `constructor_call` | 3 | 6.6s |  |
| 172 | `constructors_vs_timeline` | 5 | 25.7s |  |
| 173 | `constructprop_dynamic_primitive` | 7 | 6.6s |  |
| 174 | `context3d_creation` | 9 | 6.6s |  |
| 175 | `control_flow_bool` | 4 | 6.5s |  |
| 176 | `control_flow_stricteq` | 8 | 6.6s |  |
| 177 | `convert_boolean` | 30 | 6.6s |  |
| 178 | `convert_integer` | 90 | 6.7s |  |
| 179 | `convert_number` | 56 | 6.7s |  |
| 180 | `convert_uinteger` | 90 | 6.8s |  |
| 181 | `cross_api_version_call_older` | 12 | 6.9s |  |
| 182 | `cryptscore` | 11 | 6.8s |  |
| 183 | `date` | 30 | 5.9s |  |
| 184 | `date_parse` | 36 | 5.5s |  |
| 185 | `declocal` | 46 | 5.6s |  |
| 186 | `declocal_i` | 46 | 5.5s |  |
| 187 | `decode_uri` | 71 | 5.8s |  |
| 188 | `decrement` | 46 | 5.7s |  |
| 189 | `decrement_i` | 46 | 2.5s |  |
| 190 | `default_values` | 7 | 5.6s |  |
| 191 | `dictionary_access` | 62 | 5.8s |  |
| 192 | `dictionary_access_no_pubns` | 2 | 5.5s |  |
| 193 | `dictionary_delete` | 101 | 6.0s |  |
| 194 | `dictionary_foreach` | 42 | 5.8s |  |
| 195 | `dictionary_hasownproperty` | 63 | 5.8s |  |
| 196 | `dictionary_in` | 62 | 5.7s |  |
| 197 | `dictionary_iter_modify` | 8 | 5.6s |  |
| 198 | `dictionary_namespaces` | 36 | 5.6s |  |
| 199 | `dictionary_primitive_keys` | 29 | 5.5s |  |
| 200 | `displayobject_alpha` | 277 | 5.5s |  |
| 201 | `displayobject_blendmode` | 0 | 5.6s |  |
| 202 | `displayobject_colortransform_nested` | 0 | 22.9s |  |
| 203 | `displayobject_from_enterframe` | 1 | 22.5s |  |
| 204 | `displayobject_getbounds_shape` | 0 | 22.4s |  |
| 205 | `displayobject_height` | 6052 | 22.5s |  |
| 206 | `displayobject_hittestobject` | 32 | 5.7s |  |
| 207 | `displayobject_invalid_floats` | 60 | 5.7s |  |
| 208 | `displayobject_invalid_props` | 3 | 5.7s |  |
| 209 | `displayobject_mask` | 3 | 6.0s |  |
| 210 | `displayobject_mask_self_referential` | 0 | 6.4s |  |
| 211 | `displayobject_metaData` | 3 | 6.2s |  |
| 212 | `displayobject_name` | 22 | 6.7s |  |
| 213 | `displayobject_name_from_timeline` | 24 | 6.6s |  |
| 214 | `displayobject_parent` | 12 | 6.4s |  |
| 215 | `displayobject_root` | 24 | 6.4s |  |
| 216 | `displayobject_rotation` | 1284 | 6.5s |  |
| 217 | `displayobject_set_matrix_nested` | 0 | 25.1s |  |
| 218 | `displayobject_set_name_loaded` | 3 | 6.7s |  |
| 219 | `displayobject_subclass` | 2 | 6.4s |  |
| 220 | `displayobject_visible` | 23 | 6.4s |  |
| 221 | `displayobject_width` | 4852 | 24.9s |  |
| 222 | `displayobject_x` | 614 | 6.4s |  |
| 223 | `displayobject_y` | 617 | 6.4s |  |
| 224 | `displayobjectcontainer_addchild` | 32 | 6.5s |  |
| 225 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.3s |  |
| 226 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.6s |  |
| 227 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.5s |  |
| 228 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.5s |  |
| 229 | `displayobjectcontainer_addchildat` | 42 | 6.4s |  |
| 230 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.5s |  |
| 231 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.5s |  |
| 232 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.5s |  |
| 233 | `displayobjectcontainer_contains` | 66 | 24.9s |  |
| 234 | `displayobjectcontainer_getchildat` | 4 | 6.4s |  |
| 235 | `displayobjectcontainer_getchildbyname` | 9 | 6.3s |  |
| 236 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.4s |  |
| 237 | `displayobjectcontainer_getchildindex` | 28 | 6.4s |  |
| 238 | `displayobjectcontainer_removechild` | 10 | 6.4s |  |
| 239 | `displayobjectcontainer_removechild_errors` | 4 | 6.4s |  |
| 240 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.6s |  |
| 241 | `displayobjectcontainer_removechildat` | 18 | 6.5s |  |
| 242 | `displayobjectcontainer_removechildren` | 51 | 7.0s |  |
| 243 | `displayobjectcontainer_setchildindex` | 42 | 6.7s |  |
| 244 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.2s |  |
| 245 | `displayobjectcontainer_swapchildren` | 42 | 6.8s |  |
| 246 | `displayobjectcontainer_swapchildrenat` | 42 | 6.9s |  |
| 247 | `displayobjectcontainer_timelineinstance` | 48 | 25.5s |  |
| 248 | `divide` | 1058 | 18.7s |  |
| 249 | `doabc_is_eager` | 1 | 25.8s |  |
| 250 | `documentclass` | 9 | 6.6s |  |
| 251 | `domain_memory` | 133 | 7.6s |  |
| 252 | `drag_drop` | 10 | 6.8s |  |
| 253 | `duplicate_defs` | 1 | 6.3s |  |
| 254 | `eager_init` | 1 | 6.4s |  |
| 255 | `edit_text_linkage` | 7 | 6.7s |  |
| 256 | `edittext_align` | 60 | 6.9s |  |
| 257 | `edittext_always_show_selection` | 0 | 25.6s |  |
| 258 | `edittext_antialiastype` | 296 | 6.8s |  |
| 259 | `edittext_at_point_methods_basic` | 16 | 7.9s |  |
| 260 | `edittext_autosize` | 39 | 6.8s |  |
| 261 | `edittext_autosize_align` | 0 | 25.7s |  |
| 262 | `edittext_autosize_height_dynamic` | 60 | 25.5s |  |
| 263 | `edittext_autosize_height_input` | 60 | 6.6s |  |
| 264 | `edittext_autosize_lazy_bounds_events` | 65 | 6.8s |  |
| 265 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.6s |  |
| 266 | `edittext_autosize_lazy_bounds_props` | 490 | 8.0s |  |
| 267 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.4s |  |
| 268 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.7s |  |
| 269 | `edittext_bottom_scroll_v_basic` | 210 | 6.6s |  |
| 270 | `edittext_bounds_scale` | 24 | 24.9s |  |
| 271 | `edittext_bullet` | 30 | 6.6s |  |
| 272 | `edittext_default_format` | 221 | 6.8s |  |
| 273 | `edittext_default_format_empty` | 136 | 6.8s |  |
| 274 | `edittext_empty_text_format` | 7 | 6.6s |  |
| 275 | `edittext_focus_selection` | 5 | 6.5s |  |
| 276 | `edittext_font_size` | 45 | 6.6s |  |
| 277 | `edittext_format_empty_font` | 8 | 6.5s |  |
| 278 | `edittext_get_char_index_at_point` | 4 | 26.7s |  |
| 279 | `edittext_get_line_index_at_point` | 2 | 25.3s |  |
| 280 | `edittext_get_line_index_of_char` | 76 | 7.4s |  |
| 281 | `edittext_getcharboundaries` | 172 | 6.8s |  |
| 282 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.0s |  |
| 283 | `edittext_getcharboundaries_scroll` | 85 | 7.0s |  |
| 284 | `edittext_getlinemetrics` | 146 | 7.1s |  |
| 285 | `edittext_html` | 3101 | 7.2s |  |
| 286 | `edittext_html_condensewhite` | 487 | 6.9s |  |
| 287 | `edittext_html_entity` | 4 | 7.2s |  |
| 288 | `edittext_html_font_size_swf12` | 267 | 6.8s |  |
| 289 | `edittext_html_font_size_swf13` | 273 | 6.6s |  |
| 290 | `edittext_html_roundtrip` | 17 | 6.9s |  |
| 291 | `edittext_ime_focus_lost` | 9 | 26.1s |  |
| 292 | `edittext_input_control` | 12 | 6.9s |  |
| 293 | `edittext_leading` | 9 | 7.0s |  |
| 294 | `edittext_letter_spacing` | 15 | 6.8s |  |
| 295 | `edittext_line_methods` | 294 | 8.2s |  |
| 296 | `edittext_line_metrics` | 11 | 27.5s |  |
| 297 | `edittext_margins` | 25 | 6.9s |  |
| 298 | `edittext_max_scroll_h_basic` | 475 | 6.9s |  |
| 299 | `edittext_max_scroll_v_basic` | 1000 | 6.9s |  |
| 300 | `edittext_mouse_selection` | 363 | 27.2s |  |
| 301 | `edittext_mousedown` | 3 | 7.2s |  |
| 302 | `edittext_mouseenabled` | 26 | 6.8s |  |
| 303 | `edittext_newline_character` | 22 | 6.7s |  |
| 304 | `edittext_newline_stripping` | 64 | 9.4s |  |
| 305 | `edittext_newlines` | 30 | 6.8s |  |
| 306 | `edittext_paragraph_methods` | 257 | 6.8s |  |
| 307 | `edittext_paste_events` | 8 | 7.0s |  |
| 308 | `edittext_paste_maxchars` | 4 | 6.8s |  |
| 309 | `edittext_paste_restrict` | 16 | 6.7s |  |
| 310 | `edittext_restrict` | 191 | 6.8s |  |
| 311 | `edittext_restrict_events` | 22 | 6.8s |  |
| 312 | `edittext_scrollh` | 10 | 6.8s |  |
| 313 | `edittext_selected_text` | 9 | 6.7s |  |
| 314 | `edittext_set_html_same` | 17 | 6.8s |  |
| 315 | `edittext_set_text_vs_html` | 9 | 6.8s |  |
| 316 | `edittext_stylesheet` | 536 | 7.2s |  |
| 317 | `edittext_stylesheet_custom_tag` | 76 | 6.9s |  |
| 318 | `edittext_stylesheet_display` | 272 | 6.8s |  |
| 319 | `edittext_underline` | 40 | 6.9s |  |
| 320 | `edittext_width_height` | 103 | 21.1s |  |
| 321 | `edittext_wordwrap_word` | 150 | 7.1s |  |
| 322 | `edittext_wrap_breaks` | 2375 | 7.4s |  |
| 323 | `empty_bounds` | 1 | 6.7s |  |
| 324 | `encode_uri_surrogate_pair_swf11` | 15 | 6.5s |  |
| 325 | `equals` | 512 | 11.1s |  |
| 326 | `error_geterrormessage` | 779 | 6.8s |  |
| 327 | `error_prototype` | 15 | 6.8s |  |
| 328 | `error_stack_trace_debug_swf17` | 0 | 27.0s |  |
| 329 | `error_stack_trace_debug_swf18` | 0 | 6.5s |  |
| 330 | `error_stack_trace_release_swf17` | 0 | 6.5s |  |
| 331 | `error_stack_trace_release_swf18` | 0 | 6.3s |  |
| 332 | `error_tostring` | 29 | 6.9s |  |
| 333 | `es3_inheritance` | 31 | 7.0s |  |
| 334 | `es4_inheritance` | 30 | 6.9s |  |
| 335 | `es4_interfaces` | 30 | 6.9s |  |
| 336 | `es4_method_binding` | 8 | 7.0s |  |
| 337 | `es4_oop_prototypes` | 14 | 7.1s |  |
| 338 | `es4_protected_inheritance` | 6 | 6.9s |  |
| 339 | `escape` | 71 | 7.0s |  |
| 340 | `event_bubbles` | 2 | 6.8s |  |
| 341 | `event_cancelable` | 2 | 6.7s |  |
| 342 | `event_clone` | 20 | 6.8s |  |
| 343 | `event_clone_error_redispatch` | 3 | 6.9s |  |
| 344 | `event_clone_on_redispatch` | 10 | 7.0s |  |
| 345 | `event_formattostring` | 31 | 6.9s |  |
| 346 | `event_isdefaultprevented` | 12 | 6.7s |  |
| 347 | `event_target_getter` | 5 | 3.2s |  |
| 348 | `event_target_set` | 9 | 6.7s |  |
| 349 | `event_type` | 1 | 20.3s |  |
| 350 | `event_valueof_tostring` | 18 | 6.7s |  |
| 351 | `eventdispatcher_dispatchevent` | 12 | 6.6s |  |
| 352 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.7s |  |
| 353 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.7s |  |
| 354 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.7s |  |
| 355 | `eventdispatcher_dispatchevent_this` | 5 | 6.6s |  |
| 356 | `eventdispatcher_haseventlistener` | 25 | 6.7s |  |
| 357 | `eventdispatcher_interface_invoke` | 1 | 6.5s |  |
| 358 | `eventdispatcher_tostring` | 10 | 6.6s |  |
| 359 | `eventdispatcher_willtrigger` | 25 | 6.5s |  |
| 360 | `falsiness` | 30 | 6.5s |  |
| 361 | `fast_index_access` | 12 | 6.6s |  |
| 362 | `filefilter_properties` | 4 | 6.5s |  |
| 363 | `filereference_browse_cancel` | 3 | 6.6s |  |
| 364 | `filereference_browse_select` | 9 | 6.5s |  |
| 365 | `filereference_load` | 31 | 6.5s |  |
| 366 | `filereference_save` | 16 | 6.5s |  |
| 367 | `filereference_save_and_browse` | 42 | 6.7s |  |
| 368 | `filereference_save_and_load` | 22 | 6.6s |  |
| 369 | `filereference_uninitialized` | 8 | 6.5s |  |
| 370 | `filereferencelist_browse_cancel` | 6 | 6.5s |  |
| 371 | `filereferencelist_browse_select` | 7 | 6.5s |  |
| 372 | `finddef` | 3 | 6.5s |  |
| 373 | `findprop_global_prototype` | 6 | 6.6s |  |
| 374 | `flash_xml` | 29 | 6.6s |  |
| 375 | `flash_xml_cloneNode` | 22 | 6.5s |  |
| 376 | `flash_xml_namespace` | 109 | 6.5s |  |
| 377 | `flash_xml_removeNode` | 60 | 6.6s |  |
| 378 | `focus_events_code` | 161 | 25.7s |  |
| 379 | `focus_events_key_basic` | 132 | 26.0s |  |
| 380 | `focus_events_key_navigation` | 53 | 6.7s |  |
| 381 | `focus_events_key_same_object` | 26 | 6.5s |  |
| 382 | `focus_events_mixed_key_mouse` | 100 | 25.5s |  |
| 383 | `focus_events_mouse_basic` | 260 | 32.7s |  |
| 384 | `focus_events_mouse_focusable` | 112 | 21.5s |  |
| 385 | `focus_events_mouse_same_object` | 40 | 21.1s |  |
| 386 | `focus_remove` | 20 | 21.1s |  |
| 387 | `focus_root_movie` | 4 | 21.2s |  |
| 388 | `focus_stage` | 1 | 5.1s |  |
| 389 | `focusrect` | 18 | 5.8s |  |
| 390 | `focusrect_focuslost` | 9 | 5.2s |  |
| 391 | `focusrect_property` | 110 | 5.2s |  |
| 392 | `font_description_clone` | 14 | 5.1s |  |
| 393 | `font_embedded` | 24 | 5.4s |  |
| 394 | `font_enumeratefonts` | 41 | 5.9s |  |
| 395 | `font_enumeratefonts_filter` | 4 | 21.2s |  |
| 396 | `font_hasglyphs` | 40 | 5.4s |  |
| 397 | `framelabel_constr` | 5 | 5.2s |  |
| 398 | `function_call` | 12 | 5.2s |  |
| 399 | `function_call_arguments` | 46 | 5.2s |  |
| 400 | `function_call_arguments_enumerate` | 5 | 5.1s |  |
| 401 | `function_call_coercion` | 108 | 5.5s |  |
| 402 | `function_call_default` | 6 | 5.4s |  |
| 403 | `function_call_rest` | 22 | 5.2s |  |
| 404 | `function_call_types` | 3 | 5.1s |  |
| 405 | `function_call_via_apply` | 11 | 5.1s |  |
| 406 | `function_call_via_call` | 3 | 5.1s |  |
| 407 | `function_display_anonymous` | 7 | 2.7s |  |
| 408 | `function_length` | 6 | 5.3s |  |
| 409 | `function_object` | 2 | 5.2s |  |
| 410 | `function_proto` | 5 | 5.1s |  |
| 411 | `function_proto_created` | 61 | 5.2s |  |
| 412 | `function_to_locale_string` | 4 | 5.1s |  |
| 413 | `function_to_string` | 4 | 5.2s |  |
| 414 | `function_type` | 6 | 5.4s |  |
| 415 | `function_unbound_this` | 51 | 5.3s |  |
| 416 | `function_value_of` | 4 | 5.1s |  |
| 417 | `get_definition_by_name` | 11 | 5.1s |  |
| 418 | `get_qualified_class_name` | 20 | 20.2s |  |
| 419 | `get_qualified_super_class_name` | 18 | 6.5s |  |
| 420 | `get_slot_edge_cases` | 1 | 24.9s |  |
| 421 | `get_timer` | 2 | 6.5s |  |
| 422 | `getglobalslot` | 1 | 6.4s |  |
| 423 | `getouterscope` | 8 | 6.3s |  |
| 424 | `getter_different_namespace_setter` | 2 | 6.3s |  |
| 425 | `goto_button_nested_framescript` | 28 | 25.4s |  |
| 426 | `goto_in_constructframe` | 12 | 6.6s |  |
| 427 | `goto_in_scene_last_frame` | 2 | 25.0s |  |
| 428 | `goto_methods` | 56 | 6.6s |  |
| 429 | `goto_methods_swfver10` | 8 | 6.5s |  |
| 430 | `goto_nested_construct_sibling` | 18 | 6.9s |  |
| 431 | `goto_nested_framescript` | 9 | 6.6s |  |
| 432 | `goto_on_orphan` | 15 | 6.7s |  |
| 433 | `graphics_bad_direct_commands` | 5 | 7.2s |  |
| 434 | `graphics_bitmap_fill` | 0 | 8.3s |  |
| 435 | `graphics_bitmaps` | 0 | 7.2s |  |
| 436 | `graphics_direct_commands` | 0 | 7.1s |  |
| 437 | `graphics_draw_triangles` | 98 | 25.9s |  |
| 438 | `graphics_gradients` | 0 | 6.7s |  |
| 439 | `graphics_gradients_nulls` | 0 | 6.6s |  |
| 440 | `graphics_path` | 56 | 6.4s |  |
| 441 | `graphics_round_rects` | 0 | 6.4s |  |
| 442 | `graphics_simple_shapes` | 0 | 6.7s |  |
| 443 | `greaterequals` | 512 | 10.3s |  |
| 444 | `greaterthan` | 512 | 10.2s |  |
| 445 | `has_own_property` | 102 | 6.9s |  |
| 446 | `hasownproperty_namespaces` | 2 | 6.4s |  |
| 447 | `hello_world` | 1 | 6.4s |  |
| 448 | `hittest_morph` | 30 | 6.6s |  |
| 449 | `if_eq` | 10 | 6.5s |  |
| 450 | `if_gt` | 1 | 6.5s |  |
| 451 | `if_gte` | 10 | 21.0s |  |
| 452 | `if_lt` | 1 | 6.9s |  |
| 453 | `if_lte` | 10 | 6.8s |  |
| 454 | `if_ne` | 7 | 3.3s |  |
| 455 | `if_stricteq` | 6 | 6.9s |  |
| 456 | `if_strictne` | 11 | 6.9s |  |
| 457 | `ime_linux_dead_keys` | 10 | 7.0s |  |
| 458 | `in` | 102 | 7.4s |  |
| 459 | `inclocal` | 46 | 6.9s |  |
| 460 | `inclocal_i` | 46 | 7.0s |  |
| 461 | `increment` | 46 | 7.0s |  |
| 462 | `increment_i` | 46 | 7.0s |  |
| 463 | `indexing_delete` | 75 | 7.0s |  |
| 464 | `instanceof` | 58 | 7.3s |  |
| 465 | `instantiation_on_enter_frame` | 7 | 28.2s |  |
| 466 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.9s |  |
| 467 | `int_constr` | 92 | 6.8s |  |
| 468 | `int_edge_cases` | 19 | 7.0s |  |
| 469 | `int_instanceof` | 3 | 6.8s |  |
| 470 | `int_tofixed` | 1215 | 6.8s |  |
| 471 | `int_tostring` | 3375 | 6.8s |  |
| 472 | `interactiveobject_enabled` | 25 | 6.8s |  |
| 473 | `interface_namespaces` | 78 | 7.1s |  |
| 474 | `is_finite` | 46 | 7.0s |  |
| 475 | `is_nan` | 46 | 6.8s |  |
| 476 | `is_prototype_of` | 12 | 6.9s |  |
| 477 | `issue_10221` | 2 | 6.9s |  |
| 478 | `issue_13780` | 12 | 6.9s |  |
| 479 | `issue_14901` | 1 | 6.8s |  |
| 480 | `issue_17675_edittext_paste_maxchars` | 1 | 6.9s |  |
| 481 | `issue_5292` | 5 | 6.8s |  |
| 482 | `issue_8630` | 2 | 27.0s |  |
| 483 | `issue_8630_scriptremove` | 11 | 6.8s |  |
| 484 | `istype` | 24 | 3.3s |  |
| 485 | `istypelate` | 58 | 7.1s |  |
| 486 | `istypelate_coerce` | 198 | 21.9s |  |
| 487 | `jpeg_loader_context` | 6 | 6.9s |  |
| 488 | `json_errors` | 9 | 27.0s |  |
| 489 | `json_parse` | 21 | 6.9s |  |
| 490 | `json_stringify` | 12 | 7.1s |  |
| 491 | `json_stringify_order` | 1 | 7.1s |  |
| 492 | `json_version_gated` | 1 | 7.1s |  |
| 493 | `key_input_80percent` | 1812 | 7.2s |  |
| 494 | `key_input_location` | 126 | 7.1s |  |
| 495 | `key_input_numpad` | 384 | 6.9s |  |
| 496 | `lazyinit` | 17 | 6.9s |  |
| 497 | `lessequals` | 512 | 10.7s |  |
| 498 | `lessthan` | 512 | 10.9s |  |
| 499 | `loader_bitmap_transparency` | 14 | 7.2s |  |
| 500 | `loader_bytes_unknown_content` | 14 | 7.3s |  |
| 501 | `loader_child_getdefinition` | 5 | 7.4s |  |
| 502 | `loader_duplicate_coerce` | 3 | 7.2s |  |
| 503 | `loader_duplicate_coerce_new_domain` | 4 | 7.2s |  |
| 504 | `loader_error_in_root_ctor` | 4 | 7.2s |  |
| 505 | `loader_events` | 92 | 7.7s |  |
| 506 | `loader_image` | 8 | 7.3s |  |
| 507 | `loader_jpegxr` | 2 | 27.1s |  |
| 508 | `loader_jpegxr_alpha` | 1 | 26.6s |  |
| 509 | `loader_loadbytes_events` | 30 | 7.6s |  |
| 510 | `loader_loadbytes_invalid_png` | 4 | 26.1s |  |
| 511 | `loader_loadbytes_url` | 12 | 7.2s |  |
| 512 | `loader_loaderurl` | 6 | 7.3s |  |
| 513 | `loader_noninteractive_try_click_root` | 5 | 27.5s |  |
| 514 | `loader_reuse` | 38 | 7.1s |  |
| 515 | `loader_unknown_content` | 24 | 7.1s |  |
| 516 | `loader_visibility_interactive` | 1 | 7.2s |  |
| 517 | `loaderinfo_events` | 7 | 7.1s |  |
| 518 | `loaderinfo_loadurl` | 12 | 21.0s |  |
| 519 | `loaderinfo_more` | 6 | 7.4s |  |
| 520 | `loaderinfo_properties` | 18 | 6.9s |  |
| 521 | `loaderinfo_properties_not_loaded` | 23 | 7.2s |  |
| 522 | `loaderinfo_root` | 10 | 7.0s |  |
| 523 | `loaderinfo_root_allows` | 2 | 6.8s |  |
| 524 | `localconnection_send` | 4 | 6.9s |  |
| 525 | `lshift` | 1058 | 18.4s |  |
| 526 | `mask_reapply` | 1 | 6.9s |  |
| 527 | `math` | 497 | 7.1s |  |
| 528 | `matrix3d_invert` | 18 | 6.9s |  |
| 529 | `missing_external_interface` | 10 | 6.9s |  |
| 530 | `modulo` | 1058 | 18.6s |  |
| 531 | `morph_shape` | 2 | 26.4s |  |
| 532 | `mouse_children` | 192 | 26.7s |  |
| 533 | `mouse_click_events` | 90 | 26.8s |  |
| 534 | `mouse_double_click_events` | 188 | 6.9s |  |
| 535 | `mouse_empty_parent` | 4 | 7.0s |  |
| 536 | `mouse_over_while_dragging` | 3 | 7.2s |  |
| 537 | `mouse_pick_button_mode` | 2 | 7.2s |  |
| 538 | `mouse_pick_dobj_mask` | 4 | 7.3s |  |
| 539 | `mouse_pick_masking` | 7 | 27.1s |  |
| 540 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.5s |  |
| 541 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.3s |  |
| 542 | `mouse_pick_text` | 8 | 7.1s |  |
| 543 | `mouse_sibling` | 8 | 6.9s |  |
| 544 | `mouse_wheel_events` | 36 | 27.6s |  |
| 545 | `mouseevent_constr` | 66 | 6.9s |  |
| 546 | `mouseevent_stagexy` | 35 | 7.0s |  |
| 547 | `mouseevent_valueof_tostring` | 28 | 7.0s |  |
| 548 | `movieclip_addframescript` | 3 | 26.9s |  |
| 549 | `movieclip_child_property` | 16 | 7.0s |  |
| 550 | `movieclip_constr` | 21 | 20.4s |  |
| 551 | `movieclip_currentlabels` | 17 | 25.8s |  |
| 552 | `movieclip_currentlabels_dupes1` | 46 | 26.0s |  |
| 553 | `movieclip_currentlabels_dupes2` | 30 | 6.8s |  |
| 554 | `movieclip_currentlabels_dupes3` | 67 | 6.7s |  |
| 555 | `movieclip_currentscene` | 12 | 6.9s |  |
| 556 | `movieclip_dispatchevent` | 430 | 6.7s |  |
| 557 | `movieclip_dispatchevent_cancel` | 102 | 6.6s |  |
| 558 | `movieclip_dispatchevent_handlerorder` | 251 | 6.7s |  |
| 559 | `movieclip_dispatchevent_selfadd` | 80 | 6.7s |  |
| 560 | `movieclip_dispatchevent_target` | 899 | 6.7s |  |
| 561 | `movieclip_displayevents` | 96 | 26.0s |  |
| 562 | `movieclip_displayevents_clickgoto` | 676 | 7.1s |  |
| 563 | `movieclip_displayevents_clickgoto2` | 2001 | 7.2s |  |
| 564 | `movieclip_displayevents_clickplay` | 575 | 6.9s |  |
| 565 | `movieclip_displayevents_clicksymbol` | 562 | 6.8s |  |
| 566 | `movieclip_displayevents_constructframegoto` | 140 | 7.2s |  |
| 567 | `movieclip_displayevents_constructframeplay` | 50 | 7.0s |  |
| 568 | `movieclip_displayevents_constructframesymbol` | 144 | 6.9s |  |
| 569 | `movieclip_displayevents_dblhandler` | 21 | 6.8s |  |
| 570 | `movieclip_displayevents_enterframegoto` | 149 | 7.0s |  |
| 571 | `movieclip_displayevents_enterframeplay` | 48 | 6.8s |  |
| 572 | `movieclip_displayevents_enterframesymbol` | 149 | 26.0s |  |
| 573 | `movieclip_displayevents_exitframegoto` | 106 | 6.7s |  |
| 574 | `movieclip_displayevents_exitframeplay` | 44 | 6.7s |  |
| 575 | `movieclip_displayevents_exitframesymbol` | 135 | 6.8s |  |
| 576 | `movieclip_displayevents_looping` | 63 | 26.2s |  |
| 577 | `movieclip_displayevents_stopped` | 113 | 7.0s |  |
| 578 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 579 | `movieclip_displayevents_timeline` | 128 | 26.2s |  |
| 580 | `movieclip_drawrect` | 54 | 6.6s |  |
| 581 | `movieclip_frameconstruct_skipped` | 9 | 6.7s |  |
| 582 | `movieclip_goto_during_frame_script` | 15 | 6.6s |  |
| 583 | `movieclip_goto_overwrite` | 14 | 25.4s |  |
| 584 | `movieclip_goto_scene_last_frame_int` | 1 | 25.4s |  |
| 585 | `movieclip_goto_scene_last_frame_label` | 1 | 6.5s |  |
| 586 | `movieclip_gotoandplay` | 15 | 25.4s |  |
| 587 | `movieclip_gotoandstop` | 13 | 25.6s |  |
| 588 | `movieclip_gotoandstop_children` | 4 | 6.8s |  |
| 589 | `movieclip_gotoandstop_framescripts1` | 4 | 6.8s |  |
| 590 | `movieclip_gotoandstop_framescripts2` | 4 | 3.2s |  |
| 591 | `movieclip_gotoandstop_framescripts_self` | 7 | 29.0s |  |
| 592 | `movieclip_gotoandstop_queueing` | 12 | 18.8s |  |
| 593 | `movieclip_next_frame` | 2 | 4.9s |  |
| 594 | `movieclip_next_scene` | 6 | 19.0s |  |
| 595 | `movieclip_play` | 3 | 4.6s |  |
| 596 | `movieclip_prev_frame` | 3 | 4.3s |  |
| 597 | `movieclip_prev_scene` | 7 | 4.7s |  |
| 598 | `movieclip_properties` | 79 | 4.9s |  |
| 599 | `movieclip_queued_noop_goto_swf10` | 9 | 4.7s |  |
| 600 | `movieclip_queued_noop_goto_swf9` | 7 | 0.8s |  |
| 601 | `movieclip_scenes` | 11 | 4.5s |  |
| 602 | `movieclip_soundtransform` | 831 | 20.9s |  |
| 603 | `movieclip_stop` | 1 | 4.4s |  |
| 604 | `movieclip_super_is_symbol` | 20 | 5.0s |  |
| 605 | `movieclip_symbol_constr` | 8 | 4.8s |  |
| 606 | `movieclip_text_mousedown` | 1 | 4.5s |  |
| 607 | `movieclip_willtrigger` | 5 | 4.9s |  |
| 608 | `multiply` | 1058 | 12.4s |  |
| 609 | `namespace_constr` | 253 | 5.3s |  |
| 610 | `namespace_constr_args` | 1 | 4.4s |  |
| 611 | `namespace_enumeration_order` | 7 | 4.6s |  |
| 612 | `nan_scale` | 9 | 4.7s |  |
| 613 | `navigateToURL_target_normalize` | 107 | 19.6s |  |
| 614 | `negate` | 30 | 4.8s |  |
| 615 | `negative_volume_panned` | 0 | 4.7s |  |
| 616 | `nested_iteration` | 11 | 4.6s |  |
| 617 | `net_getClassByAlias` | 3 | 4.5s |  |
| 618 | `net_navigateToURL` | 57 | 4.3s |  |
| 619 | `net_stream_play_options` | 6 | 4.4s |  |
| 620 | `netconnection_close` | 55 | 4.4s |  |
| 621 | `netconnection_properties` | 78 | 4.5s |  |
| 622 | `netconnection_send_remote` | 50 | 4.8s |  |
| 623 | `netconnection_serialize_arrays` | 6 | 4.6s |  |
| 624 | `netstream_client` | 10 | 4.5s |  |
| 625 | `netstream_connect` | 7 | 4.4s |  |
| 626 | `newactivation_in_script_init` | 3 | 6.8s |  |
| 627 | `newclass_twice` | 3 | 6.5s |  |
| 628 | `nonconflicting_declarations` | 0 | 6.6s |  |
| 629 | `null_void_types` | 8 | 6.7s |  |
| 630 | `number_autoconv` | 21 | 6.7s |  |
| 631 | `number_autoconv_amf` | 132 | 6.7s |  |
| 632 | `number_autoconv_array_sort_32bit` | 1 | 6.6s |  |
| 633 | `number_constr` | 58 | 6.8s |  |
| 634 | `number_toexponential` | 378 | 6.8s |  |
| 635 | `number_toexponential2` | 35 | 6.7s |  |
| 636 | `number_tofixed` | 378 | 6.7s |  |
| 637 | `number_toprecision` | 350 | 6.8s |  |
| 638 | `obfuscated_class_names` | 3 | 6.7s |  |
| 639 | `object_enumeration` | 10 | 6.7s |  |
| 640 | `object_prototype` | 4 | 6.7s |  |
| 641 | `object_to_locale_string` | 2 | 6.7s |  |
| 642 | `object_to_string` | 2 | 6.6s |  |
| 643 | `object_value_of` | 2 | 3.0s |  |
| 644 | `op_coerce` | 54 | 6.7s |  |
| 645 | `op_coerce_x` | 54 | 6.7s |  |
| 646 | `op_escxattr` | 2 | 6.7s |  |
| 647 | `op_escxelem` | 2 | 6.7s |  |
| 648 | `op_lookupswitch` | 4 | 6.7s |  |
| 649 | `optimize_coerce` | 1 | 6.6s |  |
| 650 | `orphan_movie_complex` | 80 | 7.2s |  |
| 651 | `orphan_movie_reorder` | 111 | 26.6s |  |
| 652 | `package_namespace` | 7 | 6.8s |  |
| 653 | `param_default_value_has_zero_cpool_index` | 1 | 6.9s |  |
| 654 | `parent_early_access_child` | 16 | 7.3s |  |
| 655 | `parse_float` | 81 | 7.1s |  |
| 656 | `pixelbender_effect_BlurredFocus` | 0 | 29.1s |  |
| 657 | `pixelbender_effect_glassDisplace` | 0 | 11.9s |  |
| 658 | `pixelbender_effect_smudge` | 0 | 9.9s |  |
| 659 | `pixelbender_effect_tintype` | 0 | 9.2s |  |
| 660 | `pixelbender_effect_twirl` | 0 | 10.1s |  |
| 661 | `pixelbender_images` | 0 | 8.7s |  |
| 662 | `place_multiple` | 17 | 25.3s |  |
| 663 | `place_object_replace` | 9 | 6.7s |  |
| 664 | `place_object_replace_2` | 24 | 6.7s |  |
| 665 | `place_object_same_depth_frame` | 1 | 6.6s |  |
| 666 | `point` | 132 | 7.1s |  |
| 667 | `primitive_edge_cases` | 1 | 6.4s |  |
| 668 | `property_priority` | 22 | 6.7s |  |
| 669 | `property_priority_three_level` | 6 | 24.7s |  |
| 670 | `propertyisenumerable_namespaces` | 6 | 6.4s |  |
| 671 | `prototype_set_null` | 7 | 6.4s |  |
| 672 | `proxy_callproperty` | 24 | 6.5s |  |
| 673 | `proxy_deleteproperty` | 64 | 6.5s |  |
| 674 | `proxy_enumeration` | 34 | 6.5s |  |
| 675 | `proxy_getproperty` | 77 | 6.8s |  |
| 676 | `proxy_hasownproperty` | 8 | 6.7s |  |
| 677 | `proxy_hasproperty` | 32 | 6.7s |  |
| 678 | `proxy_serialize` | 9 | 6.7s |  |
| 679 | `proxy_setproperty` | 42 | 6.7s |  |
| 680 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.6s |  |
| 681 | `qname_constr` | 32 | 6.7s |  |
| 682 | `qname_constr_namespace` | 24 | 6.7s |  |
| 683 | `qname_enumeration` | 9 | 6.7s |  |
| 684 | `qname_indexing` | 23 | 6.8s |  |
| 685 | `qname_tostring` | 25 | 6.8s |  |
| 686 | `qname_valueof` | 29 | 6.8s |  |
| 687 | `regexp_constr` | 148 | 7.0s |  |
| 688 | `regexp_exec` | 19 | 6.7s |  |
| 689 | `regexp_extended` | 47 | 6.7s |  |
| 690 | `regexp_multiargs` | 1 | 6.7s |  |
| 691 | `regexp_test` | 27 | 6.8s |  |
| 692 | `regexp_toString` | 10 | 6.8s |  |
| 693 | `register_script_refresh` | 35 | 7.2s |  |
| 694 | `remove_child_clear_field` | 88 | 7.1s |  |
| 695 | `remove_dobj` | 3 | 6.7s |  |
| 696 | `resolve_order` | 4 | 6.7s |  |
| 697 | `responder_null_callbacks` | 1 | 6.7s |  |
| 698 | `rng` | 1 | 7.8s |  |
| 699 | `rootless` | 42 | 6.8s |  |
| 700 | `rshift` | 1058 | 19.1s |  |
| 701 | `sandbox_type_inherited` | 2 | 20.1s |  |
| 702 | `sandbox_type_local_file` | 1 | 6.5s |  |
| 703 | `sandbox_type_local_network` | 1 | 6.2s |  |
| 704 | `scene_constr` | 8 | 6.5s |  |
| 705 | `selection` | 239 | 7.0s |  |
| 706 | `set_local_0` | 31 | 6.6s |  |
| 707 | `set_property_is_enumerable` | 85 | 7.0s |  |
| 708 | `shape_drawrect` | 54 | 6.5s |  |
| 709 | `shared_object_no_root` | 3 | 6.4s |  |
| 710 | `simplebutton_added_to_stage` | 45 | 24.9s |  |
| 711 | `simplebutton_childevents` | 86 | 25.6s |  |
| 712 | `simplebutton_childevents_nested` | 54 | 6.8s |  |
| 713 | `simplebutton_childevents_sprite` | 13 | 6.6s |  |
| 714 | `simplebutton_childprops` | 144 | 6.7s |  |
| 715 | `simplebutton_childshuffle` | 23 | 6.7s |  |
| 716 | `simplebutton_constr` | 36 | 7.0s |  |
| 717 | `simplebutton_constr_childevents` | 48 | 6.8s |  |
| 718 | `simplebutton_constr_params` | 42 | 6.6s |  |
| 719 | `simplebutton_mouseenabled` | 26 | 6.5s |  |
| 720 | `simplebutton_multi_children` | 19 | 6.8s |  |
| 721 | `simplebutton_structure` | 27 | 6.8s |  |
| 722 | `simplebutton_symbolclass` | 68 | 6.9s |  |
| 723 | `slot_disp_id_shared_numbering` | 1 | 24.8s |  |
| 724 | `slots_force_autoassigned` | 1 | 6.5s |  |
| 725 | `socket_after_disconnect` | 1 | 6.5s |  |
| 726 | `socket_close` | 2 | 6.4s |  |
| 727 | `socket_connect` | 4 | 6.4s |  |
| 728 | `socket_errors` | 56 | 7.0s |  |
| 729 | `socket_read_big` | 48 | 20.3s |  |
| 730 | `socket_read_little` | 48 | 3.0s |  |
| 731 | `socket_read_write_object` | 8 | 6.5s |  |
| 732 | `socket_write_big` | 15 | 6.8s |  |
| 733 | `socket_write_little` | 14 | 6.6s |  |
| 734 | `sound_embeddedprops` | 26 | 6.9s |  |
| 735 | `sound_play` | 19 | 6.8s |  |
| 736 | `sound_valueof` | 33 | 6.7s |  |
| 737 | `soundchannel_soundtransform` | 835 | 27.7s |  |
| 738 | `soundchannel_soundtransform_exists` | 5 | 25.1s |  |
| 739 | `soundchannel_stop` | 8 | 6.7s |  |
| 740 | `soundmixer_buffertime` | 5 | 6.4s |  |
| 741 | `soundmixer_stopall` | 6 | 6.6s |  |
| 742 | `soundtransform` | 442 | 12.1s |  |
| 743 | `sprite_with_frames` | 0 | 25.9s |  |
| 744 | `stage3d_agal_cross_product` | 0 | 9.3s |  |
| 745 | `stage3d_agal_upload_errors` | 66 | 9.4s |  |
| 746 | `stage3d_bitmap` | 0 | 31.1s |  |
| 747 | `stage3d_blend` | 81 | 30.0s |  |
| 748 | `stage3d_context3d_string_args` | 158 | 7.7s |  |
| 749 | `stage3d_errors` | 7 | 6.7s |  |
| 750 | `stage3d_errors_atf` | 3 | 7.8s |  |
| 751 | `stage3d_errors_swf_29` | 6 | 6.6s |  |
| 752 | `stage3d_float1_index` | 0 | 27.4s |  |
| 753 | `stage3d_fractal` | 0 | 27.9s |  |
| 754 | `stage3d_ignore_sampler_override` | 0 | 27.8s |  |
| 755 | `stage3d_multistage_triangle` | 3 | 9.2s |  |
| 756 | `stage3d_program_constants_bytearray_be` | 0 | 29.4s |  |
| 757 | `stage3d_program_constants_bytearray_le` | 0 | 10.1s |  |
| 758 | `stage3d_program_constants_invalid_input` | 21 | 7.6s |  |
| 759 | `stage3d_raytrace` | 0 | 32.1s |  |
| 760 | `stage3d_rotating_cube` | 0 | 10.2s |  |
| 761 | `stage3d_sampler` | 0 | 23.1s |  |
| 762 | `stage3d_sampler_partial_upload` | 0 | 9.3s |  |
| 763 | `stage3d_stencil` | 0 | 29.3s |  |
| 764 | `stage3d_texture` | 0 | 14.3s |  |
| 765 | `stage3d_texture_bytearray` | 0 | 10.7s |  |
| 766 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.1s |  |
| 767 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.2s |  |
| 768 | `stage3d_triangle` | 0 | 9.4s |  |
| 769 | `stage3d_triangle_bytes4` | 0 | 9.4s |  |
| 770 | `stage3d_triangle_float1` | 0 | 9.4s |  |
| 771 | `stage3d_triangle_index_upload` | 0 | 9.4s |  |
| 772 | `stage3d_x_y` | 22 | 6.6s |  |
| 773 | `stage_access` | 10 | 6.6s |  |
| 774 | `stage_displayobject_properties` | 24 | 6.5s |  |
| 775 | `stage_framerate_nan` | 7 | 6.7s |  |
| 776 | `stage_framerate_negative` | 6 | 6.6s |  |
| 777 | `stage_framerate_zero` | 6 | 6.5s |  |
| 778 | `stage_invalidate` | 38 | 6.7s |  |
| 779 | `stage_loaderinfo_properties` | 24 | 6.8s |  |
| 780 | `stage_mousechildren` | 2 | 6.5s |  |
| 781 | `stage_mouseenabled` | 15 | 6.4s |  |
| 782 | `stage_overriden_setters` | 31 | 6.7s |  |
| 783 | `stage_properties` | 30 | 6.5s |  |
| 784 | `stage_stage3Ds_vector` | 1 | 25.2s |  |
| 785 | `static_var_with_this_in_ctor` | 2 | 6.5s |  |
| 786 | `stored_properties` | 11 | 6.6s |  |
| 787 | `strict_equality` | 34 | 6.6s |  |
| 788 | `string_call` | 13 | 6.5s |  |
| 789 | `string_case` | 23 | 6.5s |  |
| 790 | `string_char_at` | 27 | 6.5s |  |
| 791 | `string_char_code_at` | 28 | 6.5s |  |
| 792 | `string_concat_fromcharcode` | 37 | 6.5s |  |
| 793 | `string_constr` | 25 | 6.5s |  |
| 794 | `string_indexof_lastindexof` | 87 | 17.9s |  |
| 795 | `string_length` | 16 | 5.6s |  |
| 796 | `string_locale_compare` | 39 | 5.5s |  |
| 797 | `string_match` | 51 | 5.5s |  |
| 798 | `string_relational_compare` | 4 | 5.5s |  |
| 799 | `string_replace` | 51 | 5.5s |  |
| 800 | `string_search` | 41 | 5.6s |  |
| 801 | `string_slice_substr_substring` | 170 | 6.1s |  |
| 802 | `string_split` | 29 | 5.4s |  |
| 803 | `string_substr_negative` | 21 | 5.5s |  |
| 804 | `string_substr_weird` | 182 | 5.6s |  |
| 805 | `subtract` | 1058 | 13.8s |  |
| 806 | `super_get_call` | 12 | 5.6s |  |
| 807 | `supercall_two_classobjects` | 2 | 5.4s |  |
| 808 | `swf8` | 1 | 5.5s |  |
| 809 | `swf_10_queued_goto_scripts_construct` | 52 | 5.8s |  |
| 810 | `swf_9_goto_in_enter_frame` | 17 | 5.3s |  |
| 811 | `swf_9_goto_in_enter_frame_simple` | 15 | 5.4s |  |
| 812 | `swf_9_queued_goto_scripts` | 6 | 5.8s |  |
| 813 | `swf_9_queued_goto_scripts_construct` | 28 | 1.0s |  |
| 814 | `swf_9_versioning` | 2 | 5.4s |  |
| 815 | `swf_wrong_frame_count` | 38 | 5.6s |  |
| 816 | `swf_wrong_frame_count_isplaying` | 22 | 21.6s |  |
| 817 | `symbol_class_binary_data` | 8 | 5.4s |  |
| 818 | `symbol_class_conflict` | 4 | 6.0s |  |
| 819 | `symbol_class_root_not_zero` | 1 | 5.3s |  |
| 820 | `symbolclass_invalid_utf8` | 2 | 5.5s |  |
| 821 | `tab_ordering_automatic_advanced` | 184 | 6.2s |  |
| 822 | `tab_ordering_automatic_basic` | 45 | 5.5s |  |
| 823 | `tab_ordering_children` | 116 | 5.4s |  |
| 824 | `tab_ordering_custom_basic` | 34 | 5.3s |  |
| 825 | `tab_ordering_stage_tab_children` | 32 | 5.4s |  |
| 826 | `tab_ordering_stage_tab_children_remove_root` | 5 | 5.4s |  |
| 827 | `tab_ordering_tabbable` | 47 | 5.4s |  |
| 828 | `text_engine_fontdescription` | 27 | 5.3s |  |
| 829 | `text_run` | 7 | 5.2s |  |
| 830 | `textbox_click` | 37 | 24.3s |  |
| 831 | `textfield_event` | 66 | 5.4s |  |
| 832 | `textfield_focusin_event` | 9 | 5.3s |  |
| 833 | `textfield_input_dead_keys_windows` | 15 | 5.3s |  |
| 834 | `textfield_unload` | 39 | 24.3s |  |
| 835 | `textformat` | 1134 | 5.4s |  |
| 836 | `textformat_display` | 14 | 5.4s |  |
| 837 | `textformat_font_max_length` | 4 | 5.3s |  |
| 838 | `throw` | 3 | 5.5s |  |
| 839 | `timeline_scripts` | 3 | 5.7s |  |
| 840 | `timer` | 90 | 6.3s |  |
| 841 | `timer_events` | 3 | 5.7s |  |
| 842 | `timer_finished` | 11 | 5.7s |  |
| 843 | `timer_reset` | 8 | 6.0s |  |
| 844 | `timer_setdelay` | 5 | 6.0s |  |
| 845 | `trace` | 12 | 5.6s |  |
| 846 | `truthiness` | 30 | 19.4s |  |
| 847 | `try_catch` | 11 | 5.4s |  |
| 848 | `try_catch_typed` | 12 | 5.3s |  |
| 849 | `typeof` | 30 | 5.3s |  |
| 850 | `uint_constr` | 92 | 5.3s |  |
| 851 | `uint_tofixed` | 1215 | 5.4s |  |
| 852 | `uint_tostring` | 3375 | 5.4s |  |
| 853 | `unchecked_function` | 15 | 5.3s |  |
| 854 | `unescape` | 28 | 5.4s |  |
| 855 | `url_loader` | 25 | 5.4s |  |
| 856 | `urlrequest` | 18 | 5.4s |  |
| 857 | `urlstream_basic` | 5 | 5.4s |  |
| 858 | `urshift` | 1058 | 5.4s |  |
| 859 | `vector_class` | 36 | 5.4s |  |
| 860 | `vector_class_call` | 11 | 5.4s |  |
| 861 | `vector_coercion` | 66 | 5.4s |  |
| 862 | `vector_concat` | 90 | 5.4s |  |
| 863 | `vector_constr` | 107 | 5.4s |  |
| 864 | `vector_enumeration` | 5 | 5.4s |  |
| 865 | `vector_every` | 92 | 5.4s |  |
| 866 | `vector_filter` | 95 | 5.5s |  |
| 867 | `vector_holes` | 24 | 5.5s |  |
| 868 | `vector_indexof` | 302 | 5.4s |  |
| 869 | `vector_insertat` | 270 | 5.3s |  |
| 870 | `vector_int_access` | 4 | 5.3s |  |
| 871 | `vector_int_delete` | 11 | 5.4s |  |
| 872 | `vector_join` | 58 | 5.3s |  |
| 873 | `vector_lastindexof` | 302 | 5.3s |  |
| 874 | `vector_legacy` | 10 | 5.3s |  |
| 875 | `vector_map` | 85 | 5.4s |  |
| 876 | `vector_object_final` | 1 | 5.4s |  |
| 877 | `vector_object_toString` | 10 | 5.3s |  |
| 878 | `vector_pushpop` | 255 | 5.3s |  |
| 879 | `vector_reborrow_bug` | 10 | 19.8s |  |
| 880 | `vector_removeat` | 172 | 7.5s |  |
| 881 | `vector_reverse` | 232 | 7.5s |  |
| 882 | `vector_shiftunshift` | 252 | 6.4s |  |
| 883 | `vector_slice` | 331 | 8.2s |  |
| 884 | `vector_sort` | 905 | 15.8s |  |
| 885 | `vector_splice` | 693 | 10.5s |  |
| 886 | `vector_splice_fixed_bug_compat` | 4 | 6.5s |  |
| 887 | `vector_tostring` | 79 | 7.1s |  |
| 888 | `verify_abnormal_loop` | 1 | 6.3s |  |
| 889 | `verify_exception_targets_edge_case` | 1 | 6.4s |  |
| 890 | `verify_lookup_switch_edge_case` | 1 | 6.2s |  |
| 891 | `verify_unreachable_exception` | 2 | 6.2s |  |
| 892 | `versioned_isplaying` | 2 | 6.3s |  |
| 893 | `virtual_properties` | 16 | 6.4s |  |
| 894 | `with` | 4 | 6.3s |  |
| 895 | `wrong_arg_count` | 7 | 6.5s |  |
| 896 | `xml_abstract_equality` | 36 | 6.6s |  |
| 897 | `xml_advanced` | 52 | 6.4s |  |
| 898 | `xml_appendchild` | 10 | 6.3s |  |
| 899 | `xml_as_attribute` | 9 | 6.3s |  |
| 900 | `xml_attribute` | 35 | 6.7s |  |
| 901 | `xml_attribute_name` | 40 | 6.4s |  |
| 902 | `xml_basic` | 33 | 6.5s |  |
| 903 | `xml_child` | 25 | 6.5s |  |
| 904 | `xml_childindex` | 7 | 6.4s |  |
| 905 | `xml_children` | 43 | 7.0s |  |
| 906 | `xml_class_call` | 9 | 6.4s |  |
| 907 | `xml_contains` | 197 | 6.6s |  |
| 908 | `xml_copy` | 20 | 20.2s |  |
| 909 | `xml_ctor_from_tostring` | 23 | 6.9s |  |
| 910 | `xml_delete` | 114 | 6.6s |  |
| 911 | `xml_descendants` | 83 | 6.8s |  |
| 912 | `xml_elements` | 6 | 6.4s |  |
| 913 | `xml_equals_namespace_check` | 2 | 6.5s |  |
| 914 | `xml_explicit_use_namespace` | 5 | 6.8s |  |
| 915 | `xml_getdescendants_qname` | 21 | 6.7s |  |
| 916 | `xml_has_property_via_in` | 26 | 6.5s |  |
| 917 | `xml_hasownproperty` | 6 | 6.3s |  |
| 918 | `xml_ignore_white` | 6 | 6.4s |  |
| 919 | `xml_length` | 2 | 6.5s |  |
| 920 | `xml_list_as_attribute` | 9 | 6.3s |  |
| 921 | `xml_list_concat` | 20 | 6.6s |  |
| 922 | `xml_list_enumerate` | 4 | 6.3s |  |
| 923 | `xml_methods_settings` | 3 | 6.3s |  |
| 924 | `xml_mismatched_tag` | 37 | 6.3s |  |
| 925 | `xml_namespace` | 39 | 6.5s |  |
| 926 | `xml_namespace_methods` | 245 | 6.5s |  |
| 927 | `xml_namespaced_property` | 7 | 6.3s |  |
| 928 | `xml_no_namespace` | 1 | 6.4s |  |
| 929 | `xml_nodekind` | 3 | 6.3s |  |
| 930 | `xml_normalize` | 35 | 6.4s |  |
| 931 | `xml_notification_bubbling` | 361 | 6.3s |  |
| 932 | `xml_parent` | 8 | 6.4s |  |
| 933 | `xml_set_children` | 17 | 6.4s |  |
| 934 | `xml_set_name` | 34 | 6.4s |  |
| 935 | `xml_settings` | 6 | 2.8s |  |
| 936 | `xml_simple_complex_content` | 47 | 6.4s |  |
| 937 | `xml_socket` | 11 | 6.6s |  |
| 938 | `xml_text` | 7 | 6.3s |  |
| 939 | `xml_tostring` | 6 | 6.3s |  |
| 940 | `xml_tostring_namespace` | 12 | 6.4s |  |
| 941 | `xml_unescaping` | 23 | 6.4s |  |
| 942 | `xml_weird_ignores` | 54 | 6.4s |  |
| 943 | `xml_wildcard` | 11 | 6.3s |  |
| 944 | `xmldocument` | 254 | 7.0s |  |
| 945 | `xmlnode` | 3540 | 6.6s |  |
| 946 | `zero_frame_clip` | 3 | 6.8s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.3s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.4s |  |
| 3 | `blend_transform` | 1 | 1 | 7.1s |  |
| 4 | `coerce_property` | 3 | 3 | 7.0s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.7s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 5.9s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.7s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 40.2s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.9s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.7s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.8s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 5.1s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 25.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 25.8s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.8s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.8s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.7s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.4s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 24.8s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.6s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.8s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.5s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 22.1s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.3s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.4s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 24.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**59 tests** within reach

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
| 44 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 45 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 46 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 47 | `verification` | 62.5% | 5 | 8 | 3 |  |
| 48 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 49 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 50 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 51 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 52 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 53 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 54 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 55 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 56 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 57 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 58 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 59 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 26.3s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.7s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**246 tests** with output mismatch, sorted by match rate (best first)

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
| 44 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 45 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 46 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 47 | `verification` | 62.5% | 5/8 | 8 | 8 |  |
| 48 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 49 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 50 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 51 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 52 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 53 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 54 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 55 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 57 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 58 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 59 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 60 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 61 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 62 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 63 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 64 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 65 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 66 | `blend_shader_luma_lighten` | 33.3% | 1/3 | 1 | 3 |  |
| 67 | `matrix3d` | 33.3% | 19/57 | 22 | 57 |  |
| 68 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 69 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 70 | `verify_dxns_without_flag` | 33.3% | 1/3 | 3 | 3 |  |
| 71 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 72 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 73 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 74 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 75 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 76 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 77 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 78 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 79 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 80 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 81 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 82 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 83 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 84 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
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
| 103 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 104 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 105 | `pixelbender_ceil` | 6.5% | 5/77 | 16 | 77 |  |
| 106 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 107 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 108 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 109 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 110 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 111 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 112 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 113 | `pixelbender_rsqrt` | 4.2% | 1/24 | 1 | 24 |  |
| 114 | `pixelbender_input` | 3.9% | 4/103 | 4 | 103 |  |
| 115 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 116 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 117 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 118 | `pixelbender_shaderdata_setter` | 3.0% | 3/99 | 3 | 99 |  |
| 119 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 120 | `pixelbender_div` | 2.8% | 1/36 | 1 | 36 |  |
| 121 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 122 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 123 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 124 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 125 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 126 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 127 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 128 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 129 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 130 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 131 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 132 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 133 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 134 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 135 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 136 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 137 | `all_classes/display/swf9` | 0.1% | 2/1959 | 264 | 1959 |  |
| 138 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 139 | `all_classes/events/swf9` | 0.1% | 1/1030 | 178 | 1030 |  |
| 140 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 141 | `all_classes/display/swf10` | 0.1% | 2/2569 | 264 | 2569 |  |
| 142 | `all_classes/display/swf11` | 0.1% | 2/2593 | 264 | 2593 |  |
| 143 | `all_classes/display/swf12` | 0.1% | 2/2593 | 264 | 2593 |  |
| 144 | `all_classes/display/swf13` | 0.1% | 2/2671 | 264 | 2671 |  |
| 145 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 146 | `all_classes/events/swf10` | 0.1% | 1/1638 | 178 | 1638 |  |
| 147 | `all_classes/events/swf11` | 0.1% | 1/1750 | 178 | 1750 |  |
| 148 | `all_classes/events/swf12` | 0.1% | 1/1814 | 178 | 1814 |  |
| 149 | `all_classes/events/swf30` | 0.0% | 1/2353 | 178 | 2353 |  |
| 150 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 151 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 152 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 153 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 154 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 155 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 156 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 157 | `all_classes/display/swf30` | 0.0% | 0/2936 | 264 | 2936 |  |
| 158 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 159 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 160 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 161 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 162 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 163 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 164 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 165 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 166 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 167 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 168 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 169 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 170 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 171 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 172 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 173 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 174 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 175 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 176 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 177 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 178 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 179 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 180 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 181 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 182 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 183 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 184 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 185 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 186 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 187 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 188 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 189 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 190 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 191 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 192 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 193 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 194 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 195 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 196 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 197 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 198 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 199 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 200 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 201 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 202 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 203 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 204 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 205 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 206 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 207 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 208 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 209 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 210 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 211 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 212 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 213 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 214 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 215 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 216 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 217 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 218 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 219 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 220 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 221 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 222 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 223 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 224 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 225 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 226 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 227 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 228 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 229 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 230 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 231 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 232 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 233 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 234 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 235 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 236 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 237 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 238 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 239 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 240 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 241 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 242 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 243 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 244 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 245 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 246 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
