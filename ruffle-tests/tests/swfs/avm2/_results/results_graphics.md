# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 07:00 UTC

**Git SHA**: `9277e0e1b2`

**Run Duration**: 185m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **972** (79.6%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **998** (81.7%) |
| Failing | 223 |
| Total expected lines | 151253 |
| Matching lines | 111892 (74.0%) |
| Mismatched lines | 39361 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 220 | 98.7% |
| Runtime Error | 3 | 1.3% |

## Passing Tests

**972 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.9s |  |
| 2 | `agal_compiler` | 13 | 8.8s |  |
| 3 | `air_datagram_socket` | 1 | 7.1s |  |
| 4 | `air_hidden_lookup` | 2 | 6.5s |  |
| 5 | `all_classes/security/swf11` | 3 | 6.5s |  |
| 6 | `amf_array_serialization` | 17 | 8.3s |  |
| 7 | `amf_custom_obj` | 26 | 6.5s |  |
| 8 | `amf_dictionary` | 9 | 6.4s |  |
| 9 | `amf_function` | 46 | 6.5s |  |
| 10 | `amf_invalid_date` | 2 | 6.4s |  |
| 11 | `amf_missing_prop` | 6 | 6.4s |  |
| 12 | `amf_nondynamic_function_prop` | 6 | 6.5s |  |
| 13 | `amf_setter_error` | 8 | 6.6s |  |
| 14 | `amf_vector` | 40 | 6.6s |  |
| 15 | `amf_xml` | 6 | 6.4s |  |
| 16 | `application_domain` | 4 | 6.5s |  |
| 17 | `array_access` | 18 | 6.5s |  |
| 18 | `array_access_interpreter` | 4 | 6.5s |  |
| 19 | `array_access_no_pubns` | 2 | 6.5s |  |
| 20 | `array_concat` | 41 | 6.5s |  |
| 21 | `array_constr` | 10 | 6.4s |  |
| 22 | `array_delete` | 44 | 6.5s |  |
| 23 | `array_enumeration` | 10 | 6.5s |  |
| 24 | `array_enumeration_elements` | 11 | 6.4s |  |
| 25 | `array_every` | 8 | 6.5s |  |
| 26 | `array_filter` | 6 | 6.4s |  |
| 27 | `array_foreach` | 18 | 6.4s |  |
| 28 | `array_hasownproperty` | 11 | 3.0s |  |
| 29 | `array_holes` | 9 | 6.4s |  |
| 30 | `array_index_max` | 84 | 6.4s |  |
| 31 | `array_indexof` | 25 | 6.5s |  |
| 32 | `array_join` | 26 | 6.5s |  |
| 33 | `array_lastindexof` | 29 | 6.5s |  |
| 34 | `array_length` | 14 | 6.4s |  |
| 35 | `array_literal` | 3 | 6.4s |  |
| 36 | `array_map` | 8 | 6.3s |  |
| 37 | `array_pop` | 52 | 6.6s |  |
| 38 | `array_push` | 24 | 6.4s |  |
| 39 | `array_reborrow_bug` | 6 | 6.4s |  |
| 40 | `array_reverse` | 28 | 6.5s |  |
| 41 | `array_shift` | 51 | 3.1s |  |
| 42 | `array_slice` | 39 | 6.5s |  |
| 43 | `array_some` | 8 | 6.5s |  |
| 44 | `array_sort` | 297 | 6.9s |  |
| 45 | `array_sort_fun_swf12` | 2 | 6.5s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.2s |  |
| 47 | `array_sort_random` | 210 | 6.5s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 6.4s |  |
| 49 | `array_sorton` | 545 | 7.6s |  |
| 50 | `array_sparse_ops` | 41 | 6.9s |  |
| 51 | `array_splice` | 133 | 7.0s |  |
| 52 | `array_splice2` | 428 | 7.0s |  |
| 53 | `array_splice_types` | 48 | 6.9s |  |
| 54 | `array_storage` | 8 | 6.8s |  |
| 55 | `array_tolocalestring` | 9 | 6.7s |  |
| 56 | `array_tostring` | 12 | 6.8s |  |
| 57 | `array_unshift` | 24 | 6.7s |  |
| 58 | `array_valueof` | 9 | 6.7s |  |
| 59 | `array_vector_null_callback` | 10 | 6.8s |  |
| 60 | `astype` | 28 | 6.9s |  |
| 61 | `astypelate` | 24 | 7.0s |  |
| 62 | `astypelate_propagates` | 1 | 6.8s |  |
| 63 | `asymmetric_key_events` | 11 | 7.0s |  |
| 64 | `av_networking_params` | 9 | 6.8s |  |
| 65 | `avm2_catchup_dobj` | 158 | 7.4s |  |
| 66 | `away3d_advanced_shallow_water_demo` | 0 | 83.0s |  |
| 67 | `bitand` | 1058 | 18.1s |  |
| 68 | `bitmap_constr` | 17 | 7.0s |  |
| 69 | `bitmap_data` | 1000 | 14.8s |  |
| 70 | `bitmap_pixelsnapping` | 2 | 26.3s |  |
| 71 | `bitmap_properties` | 23 | 6.8s |  |
| 72 | `bitmap_subclass` | 7 | 8.2s |  |
| 73 | `bitmap_subclass_properties` | 9 | 7.3s |  |
| 74 | `bitmap_timeline` | 9 | 6.9s |  |
| 75 | `bitmapdata_accuracy` | 1 | 46.3s |  |
| 76 | `bitmapdata_applyfilter_blur` | 0 | 26.8s |  |
| 77 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.7s |  |
| 78 | `bitmapdata_applyfilter_destpoint` | 0 | 26.6s |  |
| 79 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.5s |  |
| 80 | `bitmapdata_clone` | 13 | 7.0s |  |
| 81 | `bitmapdata_colortransform` | 0 | 7.2s |  |
| 82 | `bitmapdata_colortransform_oob` | 2 | 6.6s |  |
| 83 | `bitmapdata_constr` | 22 | 6.8s |  |
| 84 | `bitmapdata_constructor_from_timeline` | 1 | 7.1s |  |
| 85 | `bitmapdata_copychannel` | 0 | 28.9s |  |
| 86 | `bitmapdata_copypixels` | 23 | 27.3s |  |
| 87 | `bitmapdata_copypixels_blend_over` | 1 | 6.8s |  |
| 88 | `bitmapdata_copypixelstobytearray` | 39 | 6.8s |  |
| 89 | `bitmapdata_dispose` | 7 | 6.8s |  |
| 90 | `bitmapdata_draw` | 0 | 26.6s |  |
| 91 | `bitmapdata_draw_colortransform` | 0 | 7.0s |  |
| 92 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.7s |  |
| 93 | `bitmapdata_draw_filters` | 0 | 25.6s |  |
| 94 | `bitmapdata_draw_masks` | 0 | 6.7s |  |
| 95 | `bitmapdata_draw_rotation` | 0 | 7.0s |  |
| 96 | `bitmapdata_draw_self_via_graphic` | 0 | 7.0s |  |
| 97 | `bitmapdata_draw_stage` | 0 | 25.7s |  |
| 98 | `bitmapdata_drawwithquality` | 0 | 7.0s |  |
| 99 | `bitmapdata_embedded` | 9 | 7.1s |  |
| 100 | `bitmapdata_fillrect` | 0 | 7.0s |  |
| 101 | `bitmapdata_filter_sourcerect` | 0 | 26.1s |  |
| 102 | `bitmapdata_floodfill` | 35 | 6.7s |  |
| 103 | `bitmapdata_getpixels` | 39 | 25.8s |  |
| 104 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 105 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 106 | `bitmapdata_hittest` | 112 | 7.3s |  |
| 107 | `bitmapdata_hittest_threshold` | 18 | 6.8s |  |
| 108 | `bitmapdata_opaque` | 0 | 7.0s |  |
| 109 | `bitmapdata_pixeldissolve` | 1037 | 7.4s |  |
| 110 | `bitmapdata_pixeldissolve_image` | 0 | 7.2s |  |
| 111 | `bitmapdata_rectangle_rounding` | 16 | 6.6s |  |
| 112 | `bitmapdata_setpixels` | 286 | 6.8s |  |
| 113 | `bitmapdata_setvector` | 26 | 6.7s |  |
| 114 | `bitmapdata_sync` | 0 | 25.6s |  |
| 115 | `bitmapdata_threshold` | 176 | 7.4s |  |
| 116 | `bitnot` | 46 | 6.8s |  |
| 117 | `bitor` | 1058 | 17.9s |  |
| 118 | `bitxor` | 1058 | 18.0s |  |
| 119 | `blend_multiply_alpha` | 0 | 7.0s |  |
| 120 | `blend_scroll` | 0 | 7.0s |  |
| 121 | `blend_shader_luma_lighten` | 3 | 7.4s |  |
| 122 | `boolean_constr` | 32 | 6.9s |  |
| 123 | `boolean_negation` | 30 | 6.8s |  |
| 124 | `boolean_tostring` | 8 | 6.7s |  |
| 125 | `broadcast_event` | 7 | 6.9s |  |
| 126 | `button_nested_frame` | 48 | 27.0s |  |
| 127 | `bytearray` | 48 | 7.0s |  |
| 128 | `bytearray_compress` | 31 | 6.8s |  |
| 129 | `bytearray_errors` | 24 | 6.9s |  |
| 130 | `bytearray_method_serialization` | 1 | 6.8s |  |
| 131 | `bytearray_oom` | 3 | 6.8s |  |
| 132 | `bytearray_readobject_amf0` | 50 | 6.8s |  |
| 133 | `bytearray_readobject_amf3` | 53 | 6.8s |  |
| 134 | `bytearray_readutf8bytes_with_bom` | 16 | 6.8s |  |
| 135 | `bytearray_serialization` | 3 | 6.7s |  |
| 136 | `bytearray_string_null` | 19 | 7.0s |  |
| 137 | `bytearray_tostring` | 15 | 6.8s |  |
| 138 | `bytearray_utf16` | 8 | 6.7s |  |
| 139 | `bytearray_writeobject` | 24 | 6.7s |  |
| 140 | `callee_in_initializer` | 6 | 6.7s |  |
| 141 | `callproplex_class` | 1 | 6.8s |  |
| 142 | `capabilities_resolution` | 8 | 27.2s |  |
| 143 | `catch_class` | 6 | 6.7s |  |
| 144 | `catch_scope_slot` | 7 | 3.3s |  |
| 145 | `checkfilter` | 4 | 3.2s |  |
| 146 | `class_call` | 32 | 6.9s |  |
| 147 | `class_cast_call` | 14 | 6.8s |  |
| 148 | `class_enumeration` | 4 | 6.8s |  |
| 149 | `class_has_own_property` | 2 | 6.7s |  |
| 150 | `class_init_interpreter_mode` | 1 | 6.7s |  |
| 151 | `class_is` | 32 | 6.8s |  |
| 152 | `class_methods` | 5 | 6.8s |  |
| 153 | `class_object_properties` | 10 | 6.8s |  |
| 154 | `class_singleton` | 18 | 6.8s |  |
| 155 | `class_supercalls_errors` | 35 | 7.0s |  |
| 156 | `class_supercalls_mismatched` | 26 | 6.9s |  |
| 157 | `class_superclass_wrong_order` | 1 | 26.1s |  |
| 158 | `class_to_locale_string` | 2 | 6.6s |  |
| 159 | `class_to_string` | 2 | 6.6s |  |
| 160 | `class_value_of` | 2 | 6.7s |  |
| 161 | `click_block` | 5 | 7.7s |  |
| 162 | `click_invisible` | 3 | 7.0s |  |
| 163 | `closures` | 12 | 6.8s |  |
| 164 | `coerce_return_type` | 40 | 6.9s |  |
| 165 | `coerce_return_type_fail` | 2 | 6.7s |  |
| 166 | `coerce_return_void` | 3 | 6.6s |  |
| 167 | `coerce_string` | 86 | 6.8s |  |
| 168 | `coerce_string_precision` | 28 | 6.8s |  |
| 169 | `coerce_to_primitive_side_effects` | 29 | 6.9s |  |
| 170 | `construct_errors_swf10` | 8 | 6.7s |  |
| 171 | `construct_frame_list` | 22 | 26.4s |  |
| 172 | `constructor_call` | 3 | 6.7s |  |
| 173 | `constructors_vs_timeline` | 5 | 26.1s |  |
| 174 | `constructprop_dynamic_primitive` | 7 | 6.8s |  |
| 175 | `context3d_creation` | 9 | 6.6s |  |
| 176 | `control_flow_bool` | 4 | 6.6s |  |
| 177 | `control_flow_stricteq` | 8 | 6.6s |  |
| 178 | `convert_boolean` | 30 | 6.6s |  |
| 179 | `convert_integer` | 90 | 6.7s |  |
| 180 | `convert_number` | 56 | 6.6s |  |
| 181 | `convert_uinteger` | 90 | 6.7s |  |
| 182 | `cross_api_version_call_older` | 12 | 7.0s |  |
| 183 | `cryptscore` | 11 | 6.7s |  |
| 184 | `date` | 30 | 7.2s |  |
| 185 | `date_parse` | 36 | 6.8s |  |
| 186 | `declocal` | 46 | 6.9s |  |
| 187 | `declocal_i` | 46 | 6.9s |  |
| 188 | `decode_uri` | 71 | 7.1s |  |
| 189 | `decrement` | 46 | 6.9s |  |
| 190 | `decrement_i` | 46 | 3.3s |  |
| 191 | `default_values` | 7 | 6.8s |  |
| 192 | `dictionary_access` | 62 | 7.0s |  |
| 193 | `dictionary_access_no_pubns` | 2 | 6.7s |  |
| 194 | `dictionary_delete` | 101 | 7.2s |  |
| 195 | `dictionary_foreach` | 42 | 7.0s |  |
| 196 | `dictionary_hasownproperty` | 63 | 7.0s |  |
| 197 | `dictionary_in` | 62 | 7.0s |  |
| 198 | `dictionary_iter_modify` | 8 | 6.7s |  |
| 199 | `dictionary_namespaces` | 36 | 6.8s |  |
| 200 | `dictionary_primitive_keys` | 29 | 6.7s |  |
| 201 | `displayobject_alpha` | 277 | 6.6s |  |
| 202 | `displayobject_blendmode` | 0 | 6.8s |  |
| 203 | `displayobject_colortransform_nested` | 0 | 25.8s |  |
| 204 | `displayobject_from_enterframe` | 1 | 25.6s |  |
| 205 | `displayobject_getbounds_shape` | 0 | 25.7s |  |
| 206 | `displayobject_height` | 6052 | 25.8s |  |
| 207 | `displayobject_hittestobject` | 32 | 6.8s |  |
| 208 | `displayobject_invalid_floats` | 60 | 6.7s |  |
| 209 | `displayobject_invalid_props` | 3 | 6.6s |  |
| 210 | `displayobject_mask` | 3 | 7.0s |  |
| 211 | `displayobject_mask_self_referential` | 0 | 6.5s |  |
| 212 | `displayobject_metaData` | 3 | 6.4s |  |
| 213 | `displayobject_name` | 22 | 6.8s |  |
| 214 | `displayobject_name_from_timeline` | 24 | 6.7s |  |
| 215 | `displayobject_parent` | 12 | 6.5s |  |
| 216 | `displayobject_root` | 24 | 6.5s |  |
| 217 | `displayobject_rotation` | 1284 | 6.6s |  |
| 218 | `displayobject_set_matrix_nested` | 0 | 25.7s |  |
| 219 | `displayobject_set_name_loaded` | 3 | 6.8s |  |
| 220 | `displayobject_subclass` | 2 | 6.6s |  |
| 221 | `displayobject_visible` | 23 | 6.5s |  |
| 222 | `displayobject_width` | 4852 | 25.8s |  |
| 223 | `displayobject_x` | 614 | 6.5s |  |
| 224 | `displayobject_y` | 617 | 6.6s |  |
| 225 | `displayobjectcontainer_addchild` | 32 | 6.6s |  |
| 226 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.5s |  |
| 227 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.8s |  |
| 228 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.6s |  |
| 229 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.7s |  |
| 230 | `displayobjectcontainer_addchildat` | 42 | 6.6s |  |
| 231 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.7s |  |
| 232 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.7s |  |
| 233 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.7s |  |
| 234 | `displayobjectcontainer_contains` | 66 | 25.5s |  |
| 235 | `displayobjectcontainer_getchildat` | 4 | 6.6s |  |
| 236 | `displayobjectcontainer_getchildbyname` | 9 | 6.5s |  |
| 237 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.5s |  |
| 238 | `displayobjectcontainer_getchildindex` | 28 | 6.5s |  |
| 239 | `displayobjectcontainer_removechild` | 10 | 6.5s |  |
| 240 | `displayobjectcontainer_removechild_errors` | 4 | 6.5s |  |
| 241 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.6s |  |
| 242 | `displayobjectcontainer_removechildat` | 18 | 6.5s |  |
| 243 | `displayobjectcontainer_removechildren` | 51 | 6.8s |  |
| 244 | `displayobjectcontainer_setchildindex` | 42 | 6.4s |  |
| 245 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.9s |  |
| 246 | `displayobjectcontainer_swapchildren` | 42 | 6.6s |  |
| 247 | `displayobjectcontainer_swapchildrenat` | 42 | 6.6s |  |
| 248 | `displayobjectcontainer_timelineinstance` | 48 | 24.9s |  |
| 249 | `divide` | 1058 | 18.4s |  |
| 250 | `doabc_is_eager` | 1 | 24.6s |  |
| 251 | `documentclass` | 9 | 6.6s |  |
| 252 | `domain_memory` | 133 | 7.5s |  |
| 253 | `drag_drop` | 10 | 6.7s |  |
| 254 | `duplicate_defs` | 1 | 6.3s |  |
| 255 | `eager_init` | 1 | 6.4s |  |
| 256 | `edit_text_linkage` | 7 | 6.6s |  |
| 257 | `edittext_align` | 60 | 6.8s |  |
| 258 | `edittext_always_show_selection` | 0 | 25.0s |  |
| 259 | `edittext_antialiastype` | 296 | 6.7s |  |
| 260 | `edittext_at_point_methods_basic` | 16 | 7.8s |  |
| 261 | `edittext_autosize` | 39 | 6.8s |  |
| 262 | `edittext_autosize_align` | 0 | 25.9s |  |
| 263 | `edittext_autosize_height_dynamic` | 60 | 25.6s |  |
| 264 | `edittext_autosize_height_input` | 60 | 6.6s |  |
| 265 | `edittext_autosize_lazy_bounds_events` | 65 | 6.8s |  |
| 266 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.6s |  |
| 267 | `edittext_autosize_lazy_bounds_props` | 490 | 8.0s |  |
| 268 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.0s |  |
| 269 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.7s |  |
| 270 | `edittext_bottom_scroll_v_basic` | 210 | 6.5s |  |
| 271 | `edittext_bounds_scale` | 24 | 24.9s |  |
| 272 | `edittext_bullet` | 30 | 6.6s |  |
| 273 | `edittext_default_format` | 221 | 6.8s |  |
| 274 | `edittext_default_format_empty` | 136 | 6.8s |  |
| 275 | `edittext_empty_text_format` | 7 | 6.5s |  |
| 276 | `edittext_focus_selection` | 5 | 6.5s |  |
| 277 | `edittext_font_size` | 45 | 6.6s |  |
| 278 | `edittext_format_empty_font` | 8 | 6.5s |  |
| 279 | `edittext_get_char_index_at_point` | 4 | 26.3s |  |
| 280 | `edittext_get_line_index_at_point` | 2 | 25.5s |  |
| 281 | `edittext_get_line_index_of_char` | 76 | 7.4s |  |
| 282 | `edittext_getcharboundaries` | 172 | 6.8s |  |
| 283 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.7s |  |
| 284 | `edittext_getcharboundaries_scroll` | 85 | 6.7s |  |
| 285 | `edittext_getlinemetrics` | 146 | 6.9s |  |
| 286 | `edittext_html` | 3101 | 7.1s |  |
| 287 | `edittext_html_condensewhite` | 487 | 6.8s |  |
| 288 | `edittext_html_entity` | 4 | 7.0s |  |
| 289 | `edittext_html_font_size_swf12` | 267 | 6.8s |  |
| 290 | `edittext_html_font_size_swf13` | 273 | 6.4s |  |
| 291 | `edittext_html_roundtrip` | 17 | 6.7s |  |
| 292 | `edittext_ime_focus_lost` | 9 | 25.6s |  |
| 293 | `edittext_input_control` | 12 | 6.8s |  |
| 294 | `edittext_leading` | 9 | 6.8s |  |
| 295 | `edittext_letter_spacing` | 15 | 6.7s |  |
| 296 | `edittext_line_methods` | 294 | 8.0s |  |
| 297 | `edittext_line_metrics` | 11 | 27.0s |  |
| 298 | `edittext_margins` | 25 | 6.6s |  |
| 299 | `edittext_max_scroll_h_basic` | 475 | 6.8s |  |
| 300 | `edittext_max_scroll_v_basic` | 1000 | 6.7s |  |
| 301 | `edittext_mouse_selection` | 363 | 26.8s |  |
| 302 | `edittext_mousedown` | 3 | 7.0s |  |
| 303 | `edittext_mouseenabled` | 26 | 6.6s |  |
| 304 | `edittext_newline_character` | 22 | 6.6s |  |
| 305 | `edittext_newline_stripping` | 64 | 9.2s |  |
| 306 | `edittext_newlines` | 30 | 6.7s |  |
| 307 | `edittext_paragraph_methods` | 257 | 6.7s |  |
| 308 | `edittext_paste_events` | 8 | 6.8s |  |
| 309 | `edittext_paste_maxchars` | 4 | 6.6s |  |
| 310 | `edittext_paste_restrict` | 16 | 6.5s |  |
| 311 | `edittext_restrict` | 191 | 6.6s |  |
| 312 | `edittext_restrict_events` | 22 | 6.6s |  |
| 313 | `edittext_scrollh` | 10 | 6.5s |  |
| 314 | `edittext_selected_text` | 9 | 6.6s |  |
| 315 | `edittext_set_html_same` | 17 | 6.6s |  |
| 316 | `edittext_set_text_vs_html` | 9 | 6.5s |  |
| 317 | `edittext_stylesheet` | 536 | 7.0s |  |
| 318 | `edittext_stylesheet_custom_tag` | 76 | 6.6s |  |
| 319 | `edittext_stylesheet_display` | 272 | 6.7s |  |
| 320 | `edittext_underline` | 40 | 6.7s |  |
| 321 | `edittext_width_height` | 103 | 21.1s |  |
| 322 | `edittext_wordwrap_word` | 150 | 6.8s |  |
| 323 | `edittext_wrap_breaks` | 2375 | 7.2s |  |
| 324 | `empty_bounds` | 1 | 6.5s |  |
| 325 | `encode_uri_surrogate_pair_swf11` | 15 | 6.2s |  |
| 326 | `equals` | 512 | 10.8s |  |
| 327 | `error_geterrormessage` | 779 | 6.6s |  |
| 328 | `error_prototype` | 15 | 6.5s |  |
| 329 | `error_stack_trace_debug_swf17` | 0 | 25.3s |  |
| 330 | `error_stack_trace_debug_swf18` | 0 | 6.4s |  |
| 331 | `error_stack_trace_release_swf17` | 0 | 6.3s |  |
| 332 | `error_stack_trace_release_swf18` | 0 | 6.3s |  |
| 333 | `error_tostring` | 29 | 6.5s |  |
| 334 | `es3_inheritance` | 31 | 6.7s |  |
| 335 | `es4_inheritance` | 30 | 6.6s |  |
| 336 | `es4_interfaces` | 30 | 6.6s |  |
| 337 | `es4_method_binding` | 8 | 6.5s |  |
| 338 | `es4_oop_prototypes` | 14 | 6.6s |  |
| 339 | `es4_protected_inheritance` | 6 | 6.4s |  |
| 340 | `escape` | 71 | 6.5s |  |
| 341 | `event_bubbles` | 2 | 6.4s |  |
| 342 | `event_cancelable` | 2 | 6.4s |  |
| 343 | `event_clone` | 20 | 6.5s |  |
| 344 | `event_clone_error_redispatch` | 3 | 6.6s |  |
| 345 | `event_clone_on_redispatch` | 10 | 6.7s |  |
| 346 | `event_formattostring` | 31 | 6.6s |  |
| 347 | `event_isdefaultprevented` | 12 | 6.5s |  |
| 348 | `event_target_getter` | 5 | 3.1s |  |
| 349 | `event_target_set` | 9 | 6.5s |  |
| 350 | `event_type` | 1 | 21.3s |  |
| 351 | `event_valueof_tostring` | 18 | 6.7s |  |
| 352 | `eventdispatcher_dispatchevent` | 12 | 6.7s |  |
| 353 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.8s |  |
| 354 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.9s |  |
| 355 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.9s |  |
| 356 | `eventdispatcher_dispatchevent_this` | 5 | 6.8s |  |
| 357 | `eventdispatcher_haseventlistener` | 25 | 6.9s |  |
| 358 | `eventdispatcher_interface_invoke` | 1 | 6.8s |  |
| 359 | `eventdispatcher_tostring` | 10 | 6.9s |  |
| 360 | `eventdispatcher_willtrigger` | 25 | 6.7s |  |
| 361 | `falsiness` | 30 | 6.9s |  |
| 362 | `fast_index_access` | 12 | 7.1s |  |
| 363 | `filefilter_properties` | 4 | 7.0s |  |
| 364 | `filereference_browse_cancel` | 3 | 7.0s |  |
| 365 | `filereference_browse_select` | 9 | 7.0s |  |
| 366 | `filereference_load` | 31 | 7.0s |  |
| 367 | `filereference_save` | 16 | 7.0s |  |
| 368 | `filereference_save_and_browse` | 42 | 7.0s |  |
| 369 | `filereference_save_and_load` | 22 | 7.0s |  |
| 370 | `filereference_uninitialized` | 8 | 6.9s |  |
| 371 | `filereferencelist_browse_cancel` | 6 | 6.9s |  |
| 372 | `filereferencelist_browse_select` | 7 | 7.0s |  |
| 373 | `finddef` | 3 | 6.9s |  |
| 374 | `findprop_global_prototype` | 6 | 7.0s |  |
| 375 | `flash_xml` | 29 | 7.0s |  |
| 376 | `flash_xml_cloneNode` | 22 | 7.0s |  |
| 377 | `flash_xml_namespace` | 109 | 6.9s |  |
| 378 | `flash_xml_removeNode` | 60 | 7.0s |  |
| 379 | `focus_events_code` | 161 | 26.8s |  |
| 380 | `focus_events_key_basic` | 132 | 27.0s |  |
| 381 | `focus_events_key_navigation` | 53 | 7.1s |  |
| 382 | `focus_events_key_same_object` | 26 | 6.9s |  |
| 383 | `focus_events_mixed_key_mouse` | 100 | 26.4s |  |
| 384 | `focus_events_mouse_basic` | 260 | 39.2s |  |
| 385 | `focus_events_mouse_focusable` | 112 | 25.4s |  |
| 386 | `focus_events_mouse_same_object` | 40 | 24.9s |  |
| 387 | `focus_remove` | 20 | 25.1s |  |
| 388 | `focus_root_movie` | 4 | 25.2s |  |
| 389 | `focus_stage` | 1 | 6.5s |  |
| 390 | `focusrect` | 18 | 7.3s |  |
| 391 | `focusrect_focuslost` | 9 | 6.6s |  |
| 392 | `focusrect_property` | 110 | 6.5s |  |
| 393 | `font_description_clone` | 14 | 6.5s |  |
| 394 | `font_embedded` | 24 | 6.9s |  |
| 395 | `font_enumeratefonts` | 41 | 7.3s |  |
| 396 | `font_enumeratefonts_filter` | 4 | 26.1s |  |
| 397 | `font_hasglyphs` | 40 | 6.9s |  |
| 398 | `framelabel_constr` | 5 | 6.6s |  |
| 399 | `function_call` | 12 | 6.5s |  |
| 400 | `function_call_arguments` | 46 | 6.6s |  |
| 401 | `function_call_arguments_enumerate` | 5 | 6.5s |  |
| 402 | `function_call_coercion` | 108 | 6.9s |  |
| 403 | `function_call_default` | 6 | 6.5s |  |
| 404 | `function_call_rest` | 22 | 6.5s |  |
| 405 | `function_call_types` | 3 | 6.5s |  |
| 406 | `function_call_via_apply` | 11 | 6.6s |  |
| 407 | `function_call_via_call` | 3 | 6.7s |  |
| 408 | `function_display_anonymous` | 7 | 3.2s |  |
| 409 | `function_length` | 6 | 6.6s |  |
| 410 | `function_object` | 2 | 6.6s |  |
| 411 | `function_proto` | 5 | 6.6s |  |
| 412 | `function_proto_created` | 61 | 6.7s |  |
| 413 | `function_to_locale_string` | 4 | 6.6s |  |
| 414 | `function_to_string` | 4 | 6.5s |  |
| 415 | `function_type` | 6 | 6.6s |  |
| 416 | `function_unbound_this` | 51 | 6.7s |  |
| 417 | `function_value_of` | 4 | 6.6s |  |
| 418 | `get_definition_by_name` | 11 | 6.6s |  |
| 419 | `get_qualified_class_name` | 20 | 21.9s |  |
| 420 | `get_qualified_super_class_name` | 18 | 6.8s |  |
| 421 | `get_slot_edge_cases` | 1 | 26.0s |  |
| 422 | `get_timer` | 2 | 6.7s |  |
| 423 | `getglobalslot` | 1 | 6.7s |  |
| 424 | `getouterscope` | 8 | 6.7s |  |
| 425 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 426 | `goto_button_nested_framescript` | 28 | 26.7s |  |
| 427 | `goto_in_constructframe` | 12 | 7.0s |  |
| 428 | `goto_in_scene_last_frame` | 2 | 26.1s |  |
| 429 | `goto_methods` | 56 | 7.2s |  |
| 430 | `goto_methods_swfver10` | 8 | 6.9s |  |
| 431 | `goto_nested_construct_sibling` | 18 | 7.4s |  |
| 432 | `goto_nested_framescript` | 9 | 7.0s |  |
| 433 | `goto_on_orphan` | 15 | 7.1s |  |
| 434 | `graphics_bad_direct_commands` | 5 | 7.7s |  |
| 435 | `graphics_bitmap_fill` | 0 | 9.0s |  |
| 436 | `graphics_bitmaps` | 0 | 7.6s |  |
| 437 | `graphics_direct_commands` | 0 | 7.7s |  |
| 438 | `graphics_draw_triangles` | 98 | 28.4s |  |
| 439 | `graphics_gradients` | 0 | 7.6s |  |
| 440 | `graphics_gradients_nulls` | 0 | 7.2s |  |
| 441 | `graphics_path` | 56 | 7.0s |  |
| 442 | `graphics_round_rects` | 0 | 7.0s |  |
| 443 | `graphics_simple_shapes` | 0 | 7.4s |  |
| 444 | `greaterequals` | 512 | 10.9s |  |
| 445 | `greaterthan` | 512 | 10.8s |  |
| 446 | `has_own_property` | 102 | 7.3s |  |
| 447 | `hasownproperty_namespaces` | 2 | 7.0s |  |
| 448 | `hello_world` | 1 | 6.9s |  |
| 449 | `hittest_morph` | 30 | 7.1s |  |
| 450 | `if_eq` | 10 | 6.9s |  |
| 451 | `if_gt` | 1 | 6.9s |  |
| 452 | `if_gte` | 10 | 17.0s |  |
| 453 | `if_lt` | 1 | 5.5s |  |
| 454 | `if_lte` | 10 | 5.4s |  |
| 455 | `if_ne` | 7 | 2.6s |  |
| 456 | `if_stricteq` | 6 | 5.4s |  |
| 457 | `if_strictne` | 11 | 5.3s |  |
| 458 | `ime_linux_dead_keys` | 10 | 5.7s |  |
| 459 | `in` | 102 | 5.6s |  |
| 460 | `inclocal` | 46 | 5.2s |  |
| 461 | `inclocal_i` | 46 | 5.3s |  |
| 462 | `increment` | 46 | 5.3s |  |
| 463 | `increment_i` | 46 | 5.3s |  |
| 464 | `indexing_delete` | 75 | 5.3s |  |
| 465 | `instanceof` | 58 | 5.5s |  |
| 466 | `instantiation_on_enter_frame` | 7 | 20.4s |  |
| 467 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.5s |  |
| 468 | `int_constr` | 92 | 5.2s |  |
| 469 | `int_edge_cases` | 19 | 5.4s |  |
| 470 | `int_instanceof` | 3 | 5.2s |  |
| 471 | `int_tofixed` | 1215 | 5.2s |  |
| 472 | `int_tostring` | 3375 | 5.2s |  |
| 473 | `interactiveobject_enabled` | 25 | 5.3s |  |
| 474 | `interface_namespaces` | 78 | 5.5s |  |
| 475 | `is_finite` | 46 | 5.3s |  |
| 476 | `is_nan` | 46 | 5.5s |  |
| 477 | `is_prototype_of` | 12 | 5.3s |  |
| 478 | `issue_10221` | 2 | 5.4s |  |
| 479 | `issue_13780` | 12 | 5.5s |  |
| 480 | `issue_14901` | 1 | 5.2s |  |
| 481 | `issue_17675_edittext_paste_maxchars` | 1 | 5.4s |  |
| 482 | `issue_5292` | 5 | 5.5s |  |
| 483 | `issue_8630` | 2 | 20.5s |  |
| 484 | `issue_8630_scriptremove` | 11 | 5.3s |  |
| 485 | `istype` | 24 | 2.6s |  |
| 486 | `istypelate` | 58 | 5.5s |  |
| 487 | `istypelate_coerce` | 198 | 24.1s |  |
| 488 | `jpeg_loader_context` | 6 | 7.2s |  |
| 489 | `json_errors` | 9 | 28.3s |  |
| 490 | `json_parse` | 21 | 7.2s |  |
| 491 | `json_stringify` | 12 | 7.3s |  |
| 492 | `json_stringify_order` | 1 | 6.9s |  |
| 493 | `json_version_gated` | 1 | 6.9s |  |
| 494 | `key_input_80percent` | 1812 | 7.2s |  |
| 495 | `key_input_location` | 126 | 7.2s |  |
| 496 | `key_input_numpad` | 384 | 7.0s |  |
| 497 | `lazyinit` | 17 | 7.0s |  |
| 498 | `lessequals` | 512 | 10.7s |  |
| 499 | `lessthan` | 512 | 10.7s |  |
| 500 | `loader_bitmap_transparency` | 14 | 6.9s |  |
| 501 | `loader_bytes_unknown_content` | 14 | 7.0s |  |
| 502 | `loader_child_getdefinition` | 5 | 7.1s |  |
| 503 | `loader_duplicate_coerce` | 3 | 7.1s |  |
| 504 | `loader_duplicate_coerce_new_domain` | 4 | 7.0s |  |
| 505 | `loader_error_in_root_ctor` | 4 | 7.2s |  |
| 506 | `loader_events` | 92 | 7.7s |  |
| 507 | `loader_image` | 8 | 7.4s |  |
| 508 | `loader_jpegxr` | 2 | 27.0s |  |
| 509 | `loader_jpegxr_alpha` | 1 | 26.9s |  |
| 510 | `loader_loadbytes_events` | 30 | 7.7s |  |
| 511 | `loader_loadbytes_invalid_png` | 4 | 26.3s |  |
| 512 | `loader_loadbytes_url` | 12 | 7.3s |  |
| 513 | `loader_loaderurl` | 6 | 7.3s |  |
| 514 | `loader_noninteractive_try_click_root` | 5 | 26.7s |  |
| 515 | `loader_reuse` | 38 | 7.1s |  |
| 516 | `loader_unknown_content` | 24 | 7.0s |  |
| 517 | `loader_visibility_interactive` | 1 | 6.9s |  |
| 518 | `loaderinfo_events` | 7 | 6.8s |  |
| 519 | `loaderinfo_loadurl` | 12 | 20.6s |  |
| 520 | `loaderinfo_more` | 6 | 6.9s |  |
| 521 | `loaderinfo_properties` | 18 | 6.6s |  |
| 522 | `loaderinfo_properties_not_loaded` | 23 | 6.7s |  |
| 523 | `loaderinfo_root` | 10 | 6.5s |  |
| 524 | `loaderinfo_root_allows` | 2 | 6.4s |  |
| 525 | `localconnection_send` | 4 | 6.4s |  |
| 526 | `lshift` | 1058 | 18.6s |  |
| 527 | `mask_reapply` | 1 | 6.6s |  |
| 528 | `math` | 497 | 6.7s |  |
| 529 | `matrix3d_invert` | 18 | 6.7s |  |
| 530 | `missing_external_interface` | 10 | 6.5s |  |
| 531 | `modulo` | 1058 | 18.4s |  |
| 532 | `morph_shape` | 2 | 25.2s |  |
| 533 | `mouse_children` | 192 | 25.5s |  |
| 534 | `mouse_click_events` | 90 | 25.0s |  |
| 535 | `mouse_double_click_events` | 188 | 6.4s |  |
| 536 | `mouse_empty_parent` | 4 | 6.5s |  |
| 537 | `mouse_over_while_dragging` | 3 | 6.6s |  |
| 538 | `mouse_pick_button_mode` | 2 | 6.5s |  |
| 539 | `mouse_pick_dobj_mask` | 4 | 6.8s |  |
| 540 | `mouse_pick_masking` | 7 | 25.1s |  |
| 541 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 24.9s |  |
| 542 | `mouse_pick_non_interactive_dobj_mask` | 3 | 6.7s |  |
| 543 | `mouse_pick_text` | 8 | 6.6s |  |
| 544 | `mouse_sibling` | 8 | 6.5s |  |
| 545 | `mouse_wheel_events` | 36 | 25.9s |  |
| 546 | `mouseevent_constr` | 66 | 6.5s |  |
| 547 | `mouseevent_stagexy` | 35 | 6.5s |  |
| 548 | `mouseevent_valueof_tostring` | 28 | 6.5s |  |
| 549 | `movieclip_addframescript` | 3 | 25.3s |  |
| 550 | `movieclip_child_property` | 16 | 6.7s |  |
| 551 | `movieclip_constr` | 21 | 20.6s |  |
| 552 | `movieclip_currentlabels` | 17 | 25.0s |  |
| 553 | `movieclip_currentlabels_dupes1` | 46 | 25.1s |  |
| 554 | `movieclip_currentlabels_dupes2` | 30 | 6.7s |  |
| 555 | `movieclip_currentlabels_dupes3` | 67 | 6.9s |  |
| 556 | `movieclip_currentscene` | 12 | 7.0s |  |
| 557 | `movieclip_dispatchevent` | 430 | 7.0s |  |
| 558 | `movieclip_dispatchevent_cancel` | 102 | 6.9s |  |
| 559 | `movieclip_dispatchevent_handlerorder` | 251 | 6.8s |  |
| 560 | `movieclip_dispatchevent_selfadd` | 80 | 6.8s |  |
| 561 | `movieclip_dispatchevent_target` | 899 | 6.8s |  |
| 562 | `movieclip_displayevents` | 96 | 26.3s |  |
| 563 | `movieclip_displayevents_clickgoto` | 676 | 7.2s |  |
| 564 | `movieclip_displayevents_clickgoto2` | 2001 | 7.3s |  |
| 565 | `movieclip_displayevents_clickplay` | 575 | 6.9s |  |
| 566 | `movieclip_displayevents_clicksymbol` | 562 | 6.9s |  |
| 567 | `movieclip_displayevents_constructframegoto` | 140 | 7.0s |  |
| 568 | `movieclip_displayevents_constructframeplay` | 50 | 6.9s |  |
| 569 | `movieclip_displayevents_constructframesymbol` | 144 | 6.8s |  |
| 570 | `movieclip_displayevents_dblhandler` | 21 | 6.8s |  |
| 571 | `movieclip_displayevents_enterframegoto` | 149 | 7.0s |  |
| 572 | `movieclip_displayevents_enterframeplay` | 48 | 6.7s |  |
| 573 | `movieclip_displayevents_enterframesymbol` | 149 | 26.8s |  |
| 574 | `movieclip_displayevents_exitframegoto` | 106 | 7.1s |  |
| 575 | `movieclip_displayevents_exitframeplay` | 44 | 7.0s |  |
| 576 | `movieclip_displayevents_exitframesymbol` | 135 | 7.1s |  |
| 577 | `movieclip_displayevents_looping` | 63 | 27.2s |  |
| 578 | `movieclip_displayevents_stopped` | 113 | 7.2s |  |
| 579 | `movieclip_displayevents_swap` | 96 | 3.1s |  |
| 580 | `movieclip_displayevents_timeline` | 128 | 26.0s |  |
| 581 | `movieclip_drawrect` | 54 | 6.6s |  |
| 582 | `movieclip_frameconstruct_skipped` | 9 | 6.8s |  |
| 583 | `movieclip_goto_during_frame_script` | 15 | 6.7s |  |
| 584 | `movieclip_goto_overwrite` | 14 | 27.2s |  |
| 585 | `movieclip_goto_scene_last_frame_int` | 1 | 27.7s |  |
| 586 | `movieclip_goto_scene_last_frame_label` | 1 | 6.9s |  |
| 587 | `movieclip_gotoandplay` | 15 | 26.6s |  |
| 588 | `movieclip_gotoandstop` | 13 | 25.3s |  |
| 589 | `movieclip_gotoandstop_children` | 4 | 6.5s |  |
| 590 | `movieclip_gotoandstop_framescripts1` | 4 | 6.5s |  |
| 591 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 592 | `movieclip_gotoandstop_framescripts_self` | 7 | 37.3s |  |
| 593 | `movieclip_gotoandstop_queueing` | 12 | 23.9s |  |
| 594 | `movieclip_next_frame` | 2 | 6.0s |  |
| 595 | `movieclip_next_scene` | 6 | 23.4s |  |
| 596 | `movieclip_play` | 3 | 5.7s |  |
| 597 | `movieclip_prev_frame` | 3 | 5.7s |  |
| 598 | `movieclip_prev_scene` | 7 | 6.3s |  |
| 599 | `movieclip_properties` | 79 | 6.2s |  |
| 600 | `movieclip_queued_noop_goto_swf10` | 9 | 6.0s |  |
| 601 | `movieclip_queued_noop_goto_swf9` | 7 | 1.0s |  |
| 602 | `movieclip_scenes` | 11 | 6.0s |  |
| 603 | `movieclip_soundtransform` | 831 | 25.6s |  |
| 604 | `movieclip_stop` | 1 | 5.8s |  |
| 605 | `movieclip_super_is_symbol` | 20 | 6.2s |  |
| 606 | `movieclip_symbol_constr` | 8 | 6.2s |  |
| 607 | `movieclip_text_mousedown` | 1 | 6.1s |  |
| 608 | `movieclip_willtrigger` | 5 | 6.1s |  |
| 609 | `multiply` | 1058 | 15.0s |  |
| 610 | `namespace_constr` | 253 | 6.2s |  |
| 611 | `namespace_constr_args` | 1 | 5.7s |  |
| 612 | `namespace_enumeration_order` | 7 | 5.9s |  |
| 613 | `nan_scale` | 9 | 5.9s |  |
| 614 | `navigateToURL_target_normalize` | 107 | 25.9s |  |
| 615 | `negate` | 30 | 6.1s |  |
| 616 | `negative_volume_panned` | 0 | 6.4s |  |
| 617 | `nested_iteration` | 11 | 6.3s |  |
| 618 | `net_getClassByAlias` | 3 | 5.9s |  |
| 619 | `net_navigateToURL` | 57 | 6.1s |  |
| 620 | `net_stream_play_options` | 6 | 5.9s |  |
| 621 | `netconnection_close` | 55 | 6.0s |  |
| 622 | `netconnection_properties` | 78 | 6.3s |  |
| 623 | `netconnection_send_remote` | 50 | 6.2s |  |
| 624 | `netconnection_serialize_arrays` | 6 | 5.9s |  |
| 625 | `netstream_client` | 10 | 6.1s |  |
| 626 | `netstream_connect` | 7 | 5.8s |  |
| 627 | `newactivation_in_script_init` | 3 | 6.9s |  |
| 628 | `newclass_twice` | 3 | 6.8s |  |
| 629 | `nonconflicting_declarations` | 0 | 6.8s |  |
| 630 | `null_void_types` | 8 | 6.9s |  |
| 631 | `number_autoconv` | 21 | 6.9s |  |
| 632 | `number_autoconv_amf` | 132 | 6.9s |  |
| 633 | `number_autoconv_array_sort_32bit` | 1 | 6.8s |  |
| 634 | `number_constr` | 58 | 7.0s |  |
| 635 | `number_toexponential` | 378 | 6.9s |  |
| 636 | `number_toexponential2` | 35 | 6.7s |  |
| 637 | `number_tofixed` | 378 | 6.6s |  |
| 638 | `number_toprecision` | 350 | 6.8s |  |
| 639 | `obfuscated_class_names` | 3 | 6.8s |  |
| 640 | `object_enumeration` | 10 | 6.8s |  |
| 641 | `object_prototype` | 4 | 6.9s |  |
| 642 | `object_to_locale_string` | 2 | 6.8s |  |
| 643 | `object_to_string` | 2 | 6.8s |  |
| 644 | `object_value_of` | 2 | 3.2s |  |
| 645 | `op_coerce` | 54 | 6.9s |  |
| 646 | `op_coerce_x` | 54 | 6.9s |  |
| 647 | `op_escxattr` | 2 | 6.8s |  |
| 648 | `op_escxelem` | 2 | 6.8s |  |
| 649 | `op_lookupswitch` | 4 | 6.9s |  |
| 650 | `optimize_coerce` | 1 | 6.9s |  |
| 651 | `orphan_movie_complex` | 80 | 7.3s |  |
| 652 | `orphan_movie_reorder` | 111 | 26.2s |  |
| 653 | `package_namespace` | 7 | 6.6s |  |
| 654 | `param_default_value_has_zero_cpool_index` | 1 | 6.7s |  |
| 655 | `parent_early_access_child` | 16 | 7.1s |  |
| 656 | `parse_float` | 81 | 7.0s |  |
| 657 | `pixelbender_ceil` | 77 | 6.9s |  |
| 658 | `pixelbender_conditional` | 138 | 21.2s |  |
| 659 | `pixelbender_conversions` | 270 | 6.9s |  |
| 660 | `pixelbender_dithering` | 8 | 30.4s |  |
| 661 | `pixelbender_div` | 36 | 6.8s |  |
| 662 | `pixelbender_effect_BlurredFocus` | 0 | 32.6s |  |
| 663 | `pixelbender_effect_glassDisplace` | 0 | 12.5s |  |
| 664 | `pixelbender_effect_smudge` | 0 | 10.2s |  |
| 665 | `pixelbender_effect_tintype` | 0 | 9.3s |  |
| 666 | `pixelbender_effect_twirl` | 0 | 10.4s |  |
| 667 | `pixelbender_eof` | 7 | 6.6s |  |
| 668 | `pixelbender_images` | 0 | 9.1s |  |
| 669 | `pixelbender_input` | 103 | 26.4s |  |
| 670 | `pixelbender_logicalnot` | 20 | 6.7s |  |
| 671 | `pixelbender_malformed_data` | 190 | 26.7s |  |
| 672 | `pixelbender_multiple_out_params` | 1 | 6.7s |  |
| 673 | `pixelbender_no_out_param` | 6 | 6.8s |  |
| 674 | `pixelbender_outputs` | 13 | 6.9s |  |
| 675 | `pixelbender_padding_bytes` | 22 | 6.8s |  |
| 676 | `pixelbender_param_qualifier` | 512 | 6.8s |  |
| 677 | `pixelbender_parameters` | 1563 | 7.0s |  |
| 678 | `pixelbender_parameters_bool` | 240 | 7.0s |  |
| 679 | `pixelbender_parameters_int_vs_bool` | 54 | 6.9s |  |
| 680 | `pixelbender_parse_errors` | 6 | 6.7s |  |
| 681 | `pixelbender_rsqrt` | 24 | 6.8s |  |
| 682 | `pixelbender_select_kinds` | 8 | 6.9s |  |
| 683 | `pixelbender_shaderdata` | 49 | 6.8s |  |
| 684 | `pixelbender_shaderdata_setter` | 99 | 7.2s |  |
| 685 | `pixelbender_sign` | 60 | 6.9s |  |
| 686 | `pixelbender_vector_output` | 11 | 7.0s |  |
| 687 | `place_multiple` | 17 | 25.9s |  |
| 688 | `place_object_replace` | 9 | 6.9s |  |
| 689 | `place_object_replace_2` | 24 | 6.9s |  |
| 690 | `place_object_same_depth_frame` | 1 | 6.8s |  |
| 691 | `point` | 132 | 7.2s |  |
| 692 | `primitive_edge_cases` | 1 | 6.7s |  |
| 693 | `property_priority` | 22 | 5.6s |  |
| 694 | `property_priority_three_level` | 6 | 22.1s |  |
| 695 | `propertyisenumerable_namespaces` | 6 | 5.4s |  |
| 696 | `prototype_set_null` | 7 | 5.4s |  |
| 697 | `proxy_callproperty` | 24 | 5.4s |  |
| 698 | `proxy_deleteproperty` | 64 | 5.4s |  |
| 699 | `proxy_enumeration` | 34 | 5.4s |  |
| 700 | `proxy_getproperty` | 77 | 5.9s |  |
| 701 | `proxy_hasownproperty` | 8 | 5.8s |  |
| 702 | `proxy_hasproperty` | 32 | 6.6s |  |
| 703 | `proxy_serialize` | 9 | 6.7s |  |
| 704 | `proxy_setproperty` | 42 | 5.7s |  |
| 705 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.2s |  |
| 706 | `qname_constr` | 32 | 5.3s |  |
| 707 | `qname_constr_namespace` | 24 | 5.6s |  |
| 708 | `qname_enumeration` | 9 | 5.6s |  |
| 709 | `qname_indexing` | 23 | 6.3s |  |
| 710 | `qname_tostring` | 25 | 5.8s |  |
| 711 | `qname_valueof` | 29 | 5.4s |  |
| 712 | `regexp_constr` | 148 | 5.4s |  |
| 713 | `regexp_exec` | 19 | 5.3s |  |
| 714 | `regexp_extended` | 47 | 5.5s |  |
| 715 | `regexp_multiargs` | 1 | 5.3s |  |
| 716 | `regexp_test` | 27 | 5.4s |  |
| 717 | `regexp_toString` | 10 | 5.3s |  |
| 718 | `register_script_refresh` | 35 | 6.0s |  |
| 719 | `remove_child_clear_field` | 88 | 5.6s |  |
| 720 | `remove_dobj` | 3 | 5.4s |  |
| 721 | `resolve_order` | 4 | 5.5s |  |
| 722 | `responder_null_callbacks` | 1 | 5.3s |  |
| 723 | `rng` | 1 | 6.2s |  |
| 724 | `rootless` | 42 | 5.4s |  |
| 725 | `rshift` | 1058 | 13.6s |  |
| 726 | `sandbox_type_inherited` | 2 | 21.6s |  |
| 727 | `sandbox_type_local_file` | 1 | 6.9s |  |
| 728 | `sandbox_type_local_network` | 1 | 6.5s |  |
| 729 | `scene_constr` | 8 | 7.0s |  |
| 730 | `selection` | 239 | 7.2s |  |
| 731 | `set_local_0` | 31 | 6.9s |  |
| 732 | `set_property_is_enumerable` | 85 | 7.2s |  |
| 733 | `shaderparameter_value` | 4 | 6.7s |  |
| 734 | `shape_drawrect` | 54 | 6.8s |  |
| 735 | `shared_object_no_root` | 3 | 6.8s |  |
| 736 | `simplebutton_added_to_stage` | 45 | 26.0s |  |
| 737 | `simplebutton_childevents` | 86 | 26.4s |  |
| 738 | `simplebutton_childevents_nested` | 54 | 7.2s |  |
| 739 | `simplebutton_childevents_sprite` | 13 | 6.8s |  |
| 740 | `simplebutton_childprops` | 144 | 7.1s |  |
| 741 | `simplebutton_childshuffle` | 23 | 6.8s |  |
| 742 | `simplebutton_constr` | 36 | 7.1s |  |
| 743 | `simplebutton_constr_childevents` | 48 | 7.1s |  |
| 744 | `simplebutton_constr_params` | 42 | 7.0s |  |
| 745 | `simplebutton_mouseenabled` | 26 | 6.8s |  |
| 746 | `simplebutton_multi_children` | 19 | 7.0s |  |
| 747 | `simplebutton_structure` | 27 | 7.1s |  |
| 748 | `simplebutton_symbolclass` | 68 | 7.3s |  |
| 749 | `slot_disp_id_shared_numbering` | 1 | 25.5s |  |
| 750 | `slots_force_autoassigned` | 1 | 6.8s |  |
| 751 | `socket_after_disconnect` | 1 | 7.0s |  |
| 752 | `socket_close` | 2 | 6.8s |  |
| 753 | `socket_connect` | 4 | 6.8s |  |
| 754 | `socket_errors` | 56 | 7.2s |  |
| 755 | `socket_read_big` | 48 | 21.3s |  |
| 756 | `socket_read_little` | 48 | 3.2s |  |
| 757 | `socket_read_write_object` | 8 | 6.8s |  |
| 758 | `socket_write_big` | 15 | 7.1s |  |
| 759 | `socket_write_little` | 14 | 6.8s |  |
| 760 | `sound_embeddedprops` | 26 | 7.2s |  |
| 761 | `sound_play` | 19 | 7.0s |  |
| 762 | `sound_valueof` | 33 | 6.9s |  |
| 763 | `soundchannel_soundtransform` | 835 | 27.8s |  |
| 764 | `soundchannel_soundtransform_exists` | 5 | 25.7s |  |
| 765 | `soundchannel_stop` | 8 | 7.0s |  |
| 766 | `soundmixer_buffertime` | 5 | 6.7s |  |
| 767 | `soundmixer_stopall` | 6 | 6.9s |  |
| 768 | `soundtransform` | 442 | 11.9s |  |
| 769 | `sprite_with_frames` | 0 | 26.8s |  |
| 770 | `stage3d_agal_cross_product` | 0 | 9.5s |  |
| 771 | `stage3d_agal_upload_errors` | 66 | 9.5s |  |
| 772 | `stage3d_bitmap` | 0 | 31.0s |  |
| 773 | `stage3d_blend` | 81 | 30.0s |  |
| 774 | `stage3d_context3d_string_args` | 158 | 7.8s |  |
| 775 | `stage3d_errors` | 7 | 6.9s |  |
| 776 | `stage3d_errors_atf` | 3 | 8.2s |  |
| 777 | `stage3d_errors_swf_29` | 6 | 7.0s |  |
| 778 | `stage3d_float1_index` | 0 | 28.1s |  |
| 779 | `stage3d_fractal` | 0 | 28.9s |  |
| 780 | `stage3d_ignore_sampler_override` | 0 | 28.8s |  |
| 781 | `stage3d_multistage_triangle` | 3 | 9.8s |  |
| 782 | `stage3d_program_constants_bytearray_be` | 0 | 30.1s |  |
| 783 | `stage3d_program_constants_bytearray_le` | 0 | 10.1s |  |
| 784 | `stage3d_program_constants_invalid_input` | 21 | 7.7s |  |
| 785 | `stage3d_raytrace` | 0 | 32.0s |  |
| 786 | `stage3d_rotating_cube` | 0 | 10.4s |  |
| 787 | `stage3d_sampler` | 0 | 23.5s |  |
| 788 | `stage3d_sampler_partial_upload` | 0 | 9.2s |  |
| 789 | `stage3d_stencil` | 0 | 28.5s |  |
| 790 | `stage3d_texture` | 0 | 14.3s |  |
| 791 | `stage3d_texture_bytearray` | 0 | 10.6s |  |
| 792 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.9s |  |
| 793 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.2s |  |
| 794 | `stage3d_triangle` | 0 | 9.3s |  |
| 795 | `stage3d_triangle_bytes4` | 0 | 9.2s |  |
| 796 | `stage3d_triangle_float1` | 0 | 9.2s |  |
| 797 | `stage3d_triangle_index_upload` | 0 | 9.2s |  |
| 798 | `stage3d_x_y` | 22 | 6.5s |  |
| 799 | `stage_access` | 10 | 6.5s |  |
| 800 | `stage_displayobject_properties` | 24 | 6.4s |  |
| 801 | `stage_framerate_nan` | 7 | 6.6s |  |
| 802 | `stage_framerate_negative` | 6 | 6.4s |  |
| 803 | `stage_framerate_zero` | 6 | 6.5s |  |
| 804 | `stage_invalidate` | 38 | 6.7s |  |
| 805 | `stage_loaderinfo_properties` | 24 | 6.8s |  |
| 806 | `stage_mousechildren` | 2 | 6.4s |  |
| 807 | `stage_mouseenabled` | 15 | 6.4s |  |
| 808 | `stage_overriden_setters` | 31 | 6.6s |  |
| 809 | `stage_properties` | 30 | 6.4s |  |
| 810 | `stage_stage3Ds_vector` | 1 | 24.9s |  |
| 811 | `static_var_with_this_in_ctor` | 2 | 6.5s |  |
| 812 | `stored_properties` | 11 | 6.6s |  |
| 813 | `strict_equality` | 34 | 6.5s |  |
| 814 | `string_call` | 13 | 6.5s |  |
| 815 | `string_case` | 23 | 6.6s |  |
| 816 | `string_char_at` | 27 | 6.5s |  |
| 817 | `string_char_code_at` | 28 | 6.4s |  |
| 818 | `string_concat_fromcharcode` | 37 | 6.4s |  |
| 819 | `string_constr` | 25 | 6.5s |  |
| 820 | `string_indexof_lastindexof` | 87 | 20.9s |  |
| 821 | `string_length` | 16 | 6.6s |  |
| 822 | `string_locale_compare` | 39 | 7.0s |  |
| 823 | `string_match` | 51 | 7.0s |  |
| 824 | `string_relational_compare` | 4 | 6.6s |  |
| 825 | `string_replace` | 51 | 6.9s |  |
| 826 | `string_search` | 41 | 7.0s |  |
| 827 | `string_slice_substr_substring` | 170 | 8.0s |  |
| 828 | `string_split` | 29 | 6.8s |  |
| 829 | `string_substr_negative` | 21 | 6.5s |  |
| 830 | `string_substr_weird` | 182 | 6.6s |  |
| 831 | `subtract` | 1058 | 18.9s |  |
| 832 | `super_get_call` | 12 | 6.7s |  |
| 833 | `supercall_two_classobjects` | 2 | 6.7s |  |
| 834 | `swf8` | 1 | 6.5s |  |
| 835 | `swf_10_queued_goto_scripts_construct` | 52 | 6.8s |  |
| 836 | `swf_9_goto_in_enter_frame` | 17 | 6.6s |  |
| 837 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.6s |  |
| 838 | `swf_9_queued_goto_scripts` | 6 | 6.7s |  |
| 839 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 840 | `swf_9_versioning` | 2 | 6.6s |  |
| 841 | `swf_wrong_frame_count` | 38 | 7.0s |  |
| 842 | `swf_wrong_frame_count_isplaying` | 22 | 25.9s |  |
| 843 | `symbol_class_binary_data` | 8 | 6.7s |  |
| 844 | `symbol_class_conflict` | 4 | 7.2s |  |
| 845 | `symbol_class_root_not_zero` | 1 | 6.7s |  |
| 846 | `symbolclass_invalid_utf8` | 2 | 6.7s |  |
| 847 | `tab_ordering_automatic_advanced` | 184 | 6.7s |  |
| 848 | `tab_ordering_automatic_basic` | 45 | 5.8s |  |
| 849 | `tab_ordering_children` | 116 | 5.9s |  |
| 850 | `tab_ordering_custom_basic` | 34 | 5.8s |  |
| 851 | `tab_ordering_stage_tab_children` | 32 | 5.9s |  |
| 852 | `tab_ordering_stage_tab_children_remove_root` | 5 | 5.9s |  |
| 853 | `tab_ordering_tabbable` | 47 | 6.1s |  |
| 854 | `text_engine_fontdescription` | 27 | 5.8s |  |
| 855 | `text_run` | 7 | 5.7s |  |
| 856 | `textbox_click` | 37 | 24.1s |  |
| 857 | `textfield_event` | 66 | 5.9s |  |
| 858 | `textfield_focusin_event` | 9 | 5.7s |  |
| 859 | `textfield_input_dead_keys_windows` | 15 | 5.6s |  |
| 860 | `textfield_unload` | 39 | 23.7s |  |
| 861 | `textformat` | 1134 | 5.7s |  |
| 862 | `textformat_display` | 14 | 5.6s |  |
| 863 | `textformat_font_max_length` | 4 | 5.6s |  |
| 864 | `throw` | 3 | 5.7s |  |
| 865 | `timeline_scripts` | 3 | 5.9s |  |
| 866 | `timer` | 90 | 6.3s |  |
| 867 | `timer_events` | 3 | 5.9s |  |
| 868 | `timer_finished` | 11 | 6.0s |  |
| 869 | `timer_reset` | 8 | 6.1s |  |
| 870 | `timer_setdelay` | 5 | 6.0s |  |
| 871 | `trace` | 12 | 5.8s |  |
| 872 | `truthiness` | 30 | 19.9s |  |
| 873 | `try_catch` | 11 | 5.1s |  |
| 874 | `try_catch_typed` | 12 | 5.1s |  |
| 875 | `typeof` | 30 | 5.1s |  |
| 876 | `uint_constr` | 92 | 5.2s |  |
| 877 | `uint_tofixed` | 1215 | 5.2s |  |
| 878 | `uint_tostring` | 3375 | 5.2s |  |
| 879 | `unchecked_function` | 15 | 5.2s |  |
| 880 | `unescape` | 28 | 5.2s |  |
| 881 | `url_loader` | 25 | 5.2s |  |
| 882 | `urlrequest` | 18 | 5.2s |  |
| 883 | `urlstream_basic` | 5 | 5.2s |  |
| 884 | `urshift` | 1058 | 5.2s |  |
| 885 | `vector_class` | 36 | 5.1s |  |
| 886 | `vector_class_call` | 11 | 5.1s |  |
| 887 | `vector_coercion` | 66 | 5.1s |  |
| 888 | `vector_concat` | 90 | 5.2s |  |
| 889 | `vector_constr` | 107 | 5.2s |  |
| 890 | `vector_enumeration` | 5 | 5.2s |  |
| 891 | `vector_every` | 92 | 5.1s |  |
| 892 | `vector_filter` | 95 | 5.1s |  |
| 893 | `vector_holes` | 24 | 5.1s |  |
| 894 | `vector_indexof` | 302 | 5.1s |  |
| 895 | `vector_insertat` | 270 | 5.1s |  |
| 896 | `vector_int_access` | 4 | 5.2s |  |
| 897 | `vector_int_delete` | 11 | 5.1s |  |
| 898 | `vector_join` | 58 | 5.2s |  |
| 899 | `vector_lastindexof` | 302 | 5.1s |  |
| 900 | `vector_legacy` | 10 | 5.1s |  |
| 901 | `vector_map` | 85 | 5.1s |  |
| 902 | `vector_object_final` | 1 | 5.1s |  |
| 903 | `vector_object_toString` | 10 | 5.1s |  |
| 904 | `vector_pushpop` | 255 | 5.1s |  |
| 905 | `vector_reborrow_bug` | 10 | 21.6s |  |
| 906 | `vector_removeat` | 172 | 8.0s |  |
| 907 | `vector_reverse` | 232 | 8.1s |  |
| 908 | `vector_shiftunshift` | 252 | 6.8s |  |
| 909 | `vector_slice` | 331 | 8.7s |  |
| 910 | `vector_sort` | 905 | 16.9s |  |
| 911 | `vector_splice` | 693 | 11.1s |  |
| 912 | `vector_splice_fixed_bug_compat` | 4 | 6.9s |  |
| 913 | `vector_tostring` | 79 | 7.5s |  |
| 914 | `verify_abnormal_loop` | 1 | 6.8s |  |
| 915 | `verify_exception_targets_edge_case` | 1 | 6.8s |  |
| 916 | `verify_lookup_switch_edge_case` | 1 | 6.7s |  |
| 917 | `verify_unreachable_exception` | 2 | 6.8s |  |
| 918 | `versioned_isplaying` | 2 | 6.8s |  |
| 919 | `virtual_properties` | 16 | 6.9s |  |
| 920 | `with` | 4 | 6.9s |  |
| 921 | `wrong_arg_count` | 7 | 7.1s |  |
| 922 | `xml_abstract_equality` | 36 | 7.1s |  |
| 923 | `xml_advanced` | 52 | 6.9s |  |
| 924 | `xml_appendchild` | 10 | 6.8s |  |
| 925 | `xml_as_attribute` | 9 | 6.8s |  |
| 926 | `xml_attribute` | 35 | 7.0s |  |
| 927 | `xml_attribute_name` | 40 | 6.9s |  |
| 928 | `xml_basic` | 33 | 7.0s |  |
| 929 | `xml_child` | 25 | 6.9s |  |
| 930 | `xml_childindex` | 7 | 6.8s |  |
| 931 | `xml_children` | 43 | 7.5s |  |
| 932 | `xml_class_call` | 9 | 6.9s |  |
| 933 | `xml_contains` | 197 | 7.0s |  |
| 934 | `xml_copy` | 20 | 16.8s |  |
| 935 | `xml_ctor_from_tostring` | 23 | 5.5s |  |
| 936 | `xml_delete` | 114 | 5.5s |  |
| 937 | `xml_descendants` | 83 | 5.5s |  |
| 938 | `xml_elements` | 6 | 5.4s |  |
| 939 | `xml_equals_namespace_check` | 2 | 5.6s |  |
| 940 | `xml_explicit_use_namespace` | 5 | 5.7s |  |
| 941 | `xml_getdescendants_qname` | 21 | 5.4s |  |
| 942 | `xml_has_property_via_in` | 26 | 5.7s |  |
| 943 | `xml_hasownproperty` | 6 | 5.4s |  |
| 944 | `xml_ignore_white` | 6 | 5.4s |  |
| 945 | `xml_length` | 2 | 5.4s |  |
| 946 | `xml_list_as_attribute` | 9 | 5.3s |  |
| 947 | `xml_list_concat` | 20 | 5.4s |  |
| 948 | `xml_list_enumerate` | 4 | 5.5s |  |
| 949 | `xml_methods_settings` | 3 | 5.3s |  |
| 950 | `xml_mismatched_tag` | 37 | 5.3s |  |
| 951 | `xml_namespace` | 39 | 5.7s |  |
| 952 | `xml_namespace_methods` | 245 | 5.4s |  |
| 953 | `xml_namespaced_property` | 7 | 5.4s |  |
| 954 | `xml_no_namespace` | 1 | 5.3s |  |
| 955 | `xml_nodekind` | 3 | 5.4s |  |
| 956 | `xml_normalize` | 35 | 5.6s |  |
| 957 | `xml_notification_bubbling` | 361 | 5.8s |  |
| 958 | `xml_parent` | 8 | 5.3s |  |
| 959 | `xml_set_children` | 17 | 5.4s |  |
| 960 | `xml_set_name` | 34 | 5.4s |  |
| 961 | `xml_settings` | 6 | 2.6s |  |
| 962 | `xml_simple_complex_content` | 47 | 5.4s |  |
| 963 | `xml_socket` | 11 | 5.8s |  |
| 964 | `xml_text` | 7 | 5.3s |  |
| 965 | `xml_tostring` | 6 | 5.4s |  |
| 966 | `xml_tostring_namespace` | 12 | 5.3s |  |
| 967 | `xml_unescaping` | 23 | 5.3s |  |
| 968 | `xml_weird_ignores` | 54 | 5.4s |  |
| 969 | `xml_wildcard` | 11 | 5.3s |  |
| 970 | `xmldocument` | 254 | 5.5s |  |
| 971 | `xmlnode` | 3540 | 5.4s |  |
| 972 | `zero_frame_clip` | 3 | 5.8s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.8s |  |
| 3 | `blend_transform` | 1 | 1 | 7.1s |  |
| 4 | `coerce_property` | 3 | 3 | 6.9s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.9s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 7.0s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.7s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 39.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.6s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.5s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.6s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 6.5s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 25.9s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 28.7s |  |
| 15 | `int_toexponential` | 76 | 76 | 5.2s |  |
| 16 | `int_toprecision` | 441 | 441 | 5.2s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.0s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.7s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 25.7s |  |
| 20 | `soundchannel_position` | 74 | 74 | 27.1s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 7.1s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.9s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 25.8s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.2s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.2s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 26.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**60 tests** within reach

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
| 58 | `pixelbender_effect_glassDisplace_shaderfilter` | 50.0% | 2 | 4 | 2 |  |
| 59 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 60 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 26.9s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 5.2s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**220 tests** with output mismatch, sorted by match rate (best first)

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
| 58 | `pixelbender_effect_glassDisplace_shaderfilter` | 50.0% | 2/4 | 2 | 4 |  |
| 59 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 60 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 61 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 62 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 63 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 64 | `verify_stack` | 40.0% | 2/5 | 5 | 5 |  |
| 65 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 66 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
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
| 88 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 89 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 90 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 91 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 92 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 93 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 94 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 95 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 96 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 97 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 98 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 99 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 100 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 101 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 102 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 103 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 104 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 105 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 106 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 107 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 108 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 109 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 110 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 111 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 112 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 113 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 114 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 115 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 116 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 117 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 118 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 119 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 120 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 121 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 122 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 123 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 124 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 125 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 126 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 127 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 128 | `all_classes/display/swf9` | 0.1% | 2/1959 | 315 | 1959 |  |
| 129 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 130 | `all_classes/events/swf9` | 0.1% | 1/1030 | 178 | 1030 |  |
| 131 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 132 | `all_classes/events/swf10` | 0.1% | 1/1638 | 178 | 1638 |  |
| 133 | `all_classes/events/swf11` | 0.1% | 1/1750 | 178 | 1750 |  |
| 134 | `all_classes/events/swf12` | 0.1% | 1/1814 | 178 | 1814 |  |
| 135 | `all_classes/events/swf30` | 0.0% | 1/2353 | 178 | 2353 |  |
| 136 | `all_classes/display/swf10` | 0.0% | 1/2569 | 315 | 2569 |  |
| 137 | `all_classes/display/swf11` | 0.0% | 1/2593 | 315 | 2593 |  |
| 138 | `all_classes/display/swf12` | 0.0% | 1/2593 | 315 | 2593 |  |
| 139 | `all_classes/display/swf13` | 0.0% | 1/2671 | 315 | 2671 |  |
| 140 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 141 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 142 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 143 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 144 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 145 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 146 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 147 | `all_classes/display/swf30` | 0.0% | 0/2936 | 315 | 2936 |  |
| 148 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 149 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 150 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 151 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 152 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 153 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 154 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 155 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 156 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 157 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 158 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 159 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 160 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 161 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 162 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 163 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 164 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 165 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 166 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 167 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 168 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 169 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 170 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 171 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 172 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 173 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 174 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 175 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 176 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 177 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 178 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 179 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 180 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 181 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 182 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 183 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 184 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 185 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 186 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 187 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 188 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 189 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 190 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 191 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 192 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 193 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 194 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 195 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 196 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 197 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 198 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 199 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 200 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 201 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 202 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 203 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 204 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 205 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 206 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 207 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 208 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 209 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 210 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 211 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 212 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 213 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 214 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 215 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 216 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 217 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 218 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 219 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 220 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
