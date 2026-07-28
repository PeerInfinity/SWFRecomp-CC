# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-28 19:19 UTC

**Git SHA**: `b279092977`

**Run Duration**: 171m 56s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **894** (73.2%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **920** (75.3%) |
| Failing | 301 |
| Total expected lines | 151253 |
| Matching lines | 105861 (70.0%) |
| Mismatched lines | 45392 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 298 | 99.0% |
| Runtime Error | 3 | 1.0% |

## Passing Tests

**894 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.4s |  |
| 2 | `agal_compiler` | 13 | 9.2s |  |
| 3 | `air_hidden_lookup` | 2 | 6.3s |  |
| 4 | `all_classes/security/swf11` | 3 | 6.4s |  |
| 5 | `amf_custom_obj` | 26 | 6.5s |  |
| 6 | `amf_dictionary` | 9 | 6.4s |  |
| 7 | `amf_function` | 46 | 6.4s |  |
| 8 | `amf_invalid_date` | 2 | 6.3s |  |
| 9 | `amf_missing_prop` | 6 | 6.5s |  |
| 10 | `amf_nondynamic_function_prop` | 6 | 6.4s |  |
| 11 | `amf_setter_error` | 8 | 6.5s |  |
| 12 | `amf_vector` | 40 | 6.5s |  |
| 13 | `amf_xml` | 6 | 6.4s |  |
| 14 | `application_domain` | 4 | 6.5s |  |
| 15 | `array_access` | 18 | 6.5s |  |
| 16 | `array_access_interpreter` | 4 | 6.5s |  |
| 17 | `array_access_no_pubns` | 2 | 6.4s |  |
| 18 | `array_concat` | 41 | 6.5s |  |
| 19 | `array_constr` | 10 | 6.3s |  |
| 20 | `array_delete` | 44 | 6.5s |  |
| 21 | `array_enumeration` | 10 | 6.4s |  |
| 22 | `array_enumeration_elements` | 11 | 6.4s |  |
| 23 | `array_every` | 8 | 6.5s |  |
| 24 | `array_filter` | 6 | 6.4s |  |
| 25 | `array_foreach` | 18 | 6.4s |  |
| 26 | `array_hasownproperty` | 11 | 3.0s |  |
| 27 | `array_holes` | 9 | 6.4s |  |
| 28 | `array_index_max` | 84 | 6.3s |  |
| 29 | `array_indexof` | 25 | 6.4s |  |
| 30 | `array_join` | 26 | 6.5s |  |
| 31 | `array_lastindexof` | 29 | 6.5s |  |
| 32 | `array_length` | 14 | 6.4s |  |
| 33 | `array_literal` | 3 | 6.4s |  |
| 34 | `array_map` | 8 | 6.4s |  |
| 35 | `array_pop` | 52 | 6.6s |  |
| 36 | `array_push` | 24 | 6.4s |  |
| 37 | `array_reborrow_bug` | 6 | 6.4s |  |
| 38 | `array_reverse` | 28 | 6.4s |  |
| 39 | `array_shift` | 51 | 3.1s |  |
| 40 | `array_slice` | 39 | 6.5s |  |
| 41 | `array_some` | 8 | 6.4s |  |
| 42 | `array_sort` | 297 | 6.8s |  |
| 43 | `array_sort_fun_swf12` | 2 | 6.5s |  |
| 44 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 45 | `array_sort_random` | 210 | 6.5s |  |
| 46 | `array_sort_swf10_32bit` | 1 | 6.3s |  |
| 47 | `array_sorton` | 545 | 7.1s |  |
| 48 | `array_sparse_ops` | 41 | 6.4s |  |
| 49 | `array_splice` | 133 | 6.5s |  |
| 50 | `array_splice2` | 428 | 6.6s |  |
| 51 | `array_splice_types` | 48 | 6.4s |  |
| 52 | `array_storage` | 8 | 6.3s |  |
| 53 | `array_tolocalestring` | 9 | 6.3s |  |
| 54 | `array_tostring` | 12 | 6.3s |  |
| 55 | `array_unshift` | 24 | 6.3s |  |
| 56 | `array_valueof` | 9 | 6.2s |  |
| 57 | `array_vector_null_callback` | 10 | 6.3s |  |
| 58 | `astype` | 28 | 6.4s |  |
| 59 | `astypelate` | 24 | 6.4s |  |
| 60 | `astypelate_propagates` | 1 | 6.2s |  |
| 61 | `asymmetric_key_events` | 11 | 6.5s |  |
| 62 | `avm2_catchup_dobj` | 158 | 6.8s |  |
| 63 | `away3d_advanced_shallow_water_demo` | 0 | 80.4s |  |
| 64 | `bitand` | 1058 | 18.5s |  |
| 65 | `bitmap_constr` | 17 | 6.5s |  |
| 66 | `bitmap_data` | 1000 | 14.7s |  |
| 67 | `bitmap_pixelsnapping` | 2 | 25.4s |  |
| 68 | `bitmap_properties` | 23 | 6.3s |  |
| 69 | `bitmap_subclass` | 7 | 7.8s |  |
| 70 | `bitmap_subclass_properties` | 9 | 6.8s |  |
| 71 | `bitmap_timeline` | 9 | 6.4s |  |
| 72 | `bitmapdata_accuracy` | 1 | 43.7s |  |
| 73 | `bitmapdata_applyfilter_blur` | 0 | 25.7s |  |
| 74 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.1s |  |
| 75 | `bitmapdata_applyfilter_destpoint` | 0 | 25.6s |  |
| 76 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.7s |  |
| 77 | `bitmapdata_clone` | 13 | 6.6s |  |
| 78 | `bitmapdata_colortransform` | 0 | 6.8s |  |
| 79 | `bitmapdata_colortransform_oob` | 2 | 6.2s |  |
| 80 | `bitmapdata_constr` | 22 | 6.3s |  |
| 81 | `bitmapdata_constructor_from_timeline` | 1 | 6.5s |  |
| 82 | `bitmapdata_copychannel` | 0 | 29.1s |  |
| 83 | `bitmapdata_copypixels` | 23 | 27.5s |  |
| 84 | `bitmapdata_copypixels_blend_over` | 1 | 6.5s |  |
| 85 | `bitmapdata_copypixelstobytearray` | 39 | 6.5s |  |
| 86 | `bitmapdata_dispose` | 7 | 6.5s |  |
| 87 | `bitmapdata_draw` | 0 | 26.9s |  |
| 88 | `bitmapdata_draw_colortransform` | 0 | 6.7s |  |
| 89 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.3s |  |
| 90 | `bitmapdata_draw_filters` | 0 | 25.5s |  |
| 91 | `bitmapdata_draw_masks` | 0 | 6.4s |  |
| 92 | `bitmapdata_draw_rotation` | 0 | 6.7s |  |
| 93 | `bitmapdata_draw_self_via_graphic` | 0 | 6.8s |  |
| 94 | `bitmapdata_draw_stage` | 0 | 25.6s |  |
| 95 | `bitmapdata_drawwithquality` | 0 | 6.8s |  |
| 96 | `bitmapdata_embedded` | 9 | 6.8s |  |
| 97 | `bitmapdata_fillrect` | 0 | 6.6s |  |
| 98 | `bitmapdata_filter_sourcerect` | 0 | 25.4s |  |
| 99 | `bitmapdata_floodfill` | 35 | 6.4s |  |
| 100 | `bitmapdata_getpixels` | 39 | 25.8s |  |
| 101 | `bitmapdata_getvector` | 27 | 3.0s |  |
| 102 | `bitmapdata_histogram` | 59 | 3.0s |  |
| 103 | `bitmapdata_hittest` | 112 | 7.1s |  |
| 104 | `bitmapdata_hittest_threshold` | 18 | 6.5s |  |
| 105 | `bitmapdata_opaque` | 0 | 6.7s |  |
| 106 | `bitmapdata_pixeldissolve` | 1037 | 7.1s |  |
| 107 | `bitmapdata_pixeldissolve_image` | 0 | 6.9s |  |
| 108 | `bitmapdata_rectangle_rounding` | 16 | 6.5s |  |
| 109 | `bitmapdata_setpixels` | 286 | 6.6s |  |
| 110 | `bitmapdata_setvector` | 26 | 6.6s |  |
| 111 | `bitmapdata_sync` | 0 | 6.5s |  |
| 112 | `bitmapdata_threshold` | 176 | 7.3s |  |
| 113 | `bitnot` | 46 | 6.6s |  |
| 114 | `bitor` | 1058 | 18.9s |  |
| 115 | `bitxor` | 1058 | 18.8s |  |
| 116 | `blend_multiply_alpha` | 0 | 6.7s |  |
| 117 | `blend_scroll` | 0 | 6.7s |  |
| 118 | `boolean_constr` | 32 | 6.7s |  |
| 119 | `boolean_negation` | 30 | 6.7s |  |
| 120 | `boolean_tostring` | 8 | 6.6s |  |
| 121 | `broadcast_event` | 7 | 6.6s |  |
| 122 | `button_nested_frame` | 48 | 7.0s |  |
| 123 | `bytearray` | 48 | 6.9s |  |
| 124 | `bytearray_compress` | 31 | 6.5s |  |
| 125 | `bytearray_errors` | 24 | 6.6s |  |
| 126 | `bytearray_method_serialization` | 1 | 6.5s |  |
| 127 | `bytearray_oom` | 3 | 6.5s |  |
| 128 | `bytearray_readobject_amf0` | 50 | 6.5s |  |
| 129 | `bytearray_readobject_amf3` | 53 | 6.6s |  |
| 130 | `bytearray_readutf8bytes_with_bom` | 16 | 6.6s |  |
| 131 | `bytearray_serialization` | 3 | 6.5s |  |
| 132 | `bytearray_string_null` | 19 | 6.8s |  |
| 133 | `bytearray_tostring` | 15 | 6.6s |  |
| 134 | `bytearray_utf16` | 8 | 6.6s |  |
| 135 | `bytearray_writeobject` | 24 | 6.5s |  |
| 136 | `callee_in_initializer` | 6 | 6.5s |  |
| 137 | `callproplex_class` | 1 | 6.6s |  |
| 138 | `capabilities_resolution` | 8 | 26.5s |  |
| 139 | `catch_class` | 6 | 6.7s |  |
| 140 | `catch_scope_slot` | 7 | 3.3s |  |
| 141 | `checkfilter` | 4 | 3.2s |  |
| 142 | `class_call` | 32 | 6.8s |  |
| 143 | `class_cast_call` | 14 | 6.6s |  |
| 144 | `class_enumeration` | 4 | 6.7s |  |
| 145 | `class_has_own_property` | 2 | 6.8s |  |
| 146 | `class_init_interpreter_mode` | 1 | 6.5s |  |
| 147 | `class_is` | 32 | 6.7s |  |
| 148 | `class_methods` | 5 | 6.6s |  |
| 149 | `class_object_properties` | 10 | 6.7s |  |
| 150 | `class_singleton` | 18 | 6.7s |  |
| 151 | `class_supercalls_errors` | 35 | 6.9s |  |
| 152 | `class_supercalls_mismatched` | 26 | 6.8s |  |
| 153 | `class_superclass_wrong_order` | 1 | 6.2s |  |
| 154 | `class_to_locale_string` | 2 | 6.2s |  |
| 155 | `class_to_string` | 2 | 6.1s |  |
| 156 | `class_value_of` | 2 | 6.2s |  |
| 157 | `click_block` | 5 | 25.2s |  |
| 158 | `click_invisible` | 3 | 6.4s |  |
| 159 | `closures` | 12 | 6.3s |  |
| 160 | `coerce_return_type` | 40 | 6.4s |  |
| 161 | `coerce_return_type_fail` | 2 | 6.1s |  |
| 162 | `coerce_return_void` | 3 | 6.1s |  |
| 163 | `coerce_string` | 86 | 6.4s |  |
| 164 | `coerce_string_precision` | 28 | 6.2s |  |
| 165 | `coerce_to_primitive_side_effects` | 29 | 6.3s |  |
| 166 | `construct_errors_swf10` | 8 | 6.3s |  |
| 167 | `construct_frame_list` | 22 | 6.5s |  |
| 168 | `constructor_call` | 3 | 6.2s |  |
| 169 | `constructors_vs_timeline` | 5 | 24.8s |  |
| 170 | `constructprop_dynamic_primitive` | 7 | 6.4s |  |
| 171 | `control_flow_bool` | 4 | 6.2s |  |
| 172 | `control_flow_stricteq` | 8 | 6.3s |  |
| 173 | `convert_boolean` | 30 | 6.3s |  |
| 174 | `convert_integer` | 90 | 6.4s |  |
| 175 | `convert_number` | 56 | 6.3s |  |
| 176 | `convert_uinteger` | 90 | 6.4s |  |
| 177 | `cross_api_version_call_older` | 12 | 6.5s |  |
| 178 | `cryptscore` | 11 | 6.3s |  |
| 179 | `date` | 30 | 7.0s |  |
| 180 | `date_parse` | 36 | 6.7s |  |
| 181 | `declocal` | 46 | 6.7s |  |
| 182 | `declocal_i` | 46 | 6.7s |  |
| 183 | `decode_uri` | 71 | 7.0s |  |
| 184 | `decrement` | 46 | 6.7s |  |
| 185 | `decrement_i` | 46 | 3.2s |  |
| 186 | `default_values` | 7 | 6.6s |  |
| 187 | `dictionary_access` | 62 | 6.9s |  |
| 188 | `dictionary_access_no_pubns` | 2 | 6.5s |  |
| 189 | `dictionary_delete` | 101 | 7.2s |  |
| 190 | `dictionary_foreach` | 42 | 7.0s |  |
| 191 | `dictionary_hasownproperty` | 63 | 7.0s |  |
| 192 | `dictionary_in` | 62 | 7.0s |  |
| 193 | `dictionary_iter_modify` | 8 | 6.8s |  |
| 194 | `dictionary_namespaces` | 36 | 6.9s |  |
| 195 | `dictionary_primitive_keys` | 29 | 6.7s |  |
| 196 | `displayobject_alpha` | 277 | 6.5s |  |
| 197 | `displayobject_blendmode` | 0 | 6.7s |  |
| 198 | `displayobject_colortransform_nested` | 0 | 25.9s |  |
| 199 | `displayobject_from_enterframe` | 1 | 6.7s |  |
| 200 | `displayobject_getbounds_shape` | 0 | 25.8s |  |
| 201 | `displayobject_height` | 6052 | 25.8s |  |
| 202 | `displayobject_hittestobject` | 32 | 6.7s |  |
| 203 | `displayobject_invalid_floats` | 60 | 6.6s |  |
| 204 | `displayobject_invalid_props` | 3 | 6.6s |  |
| 205 | `displayobject_mask` | 3 | 6.9s |  |
| 206 | `displayobject_mask_self_referential` | 0 | 6.1s |  |
| 207 | `displayobject_metaData` | 3 | 6.0s |  |
| 208 | `displayobject_name` | 22 | 6.4s |  |
| 209 | `displayobject_name_from_timeline` | 24 | 6.3s |  |
| 210 | `displayobject_parent` | 12 | 6.1s |  |
| 211 | `displayobject_root` | 24 | 6.1s |  |
| 212 | `displayobject_rotation` | 1284 | 6.3s |  |
| 213 | `displayobject_set_matrix_nested` | 0 | 24.5s |  |
| 214 | `displayobject_set_name_loaded` | 3 | 6.4s |  |
| 215 | `displayobject_subclass` | 2 | 6.2s |  |
| 216 | `displayobject_visible` | 23 | 6.2s |  |
| 217 | `displayobject_width` | 4852 | 24.4s |  |
| 218 | `displayobject_x` | 614 | 6.1s |  |
| 219 | `displayobject_y` | 617 | 6.1s |  |
| 220 | `displayobjectcontainer_addchild` | 32 | 6.2s |  |
| 221 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.1s |  |
| 222 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.3s |  |
| 223 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.2s |  |
| 224 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.2s |  |
| 225 | `displayobjectcontainer_addchildat` | 42 | 6.2s |  |
| 226 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.3s |  |
| 227 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.2s |  |
| 228 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.2s |  |
| 229 | `displayobjectcontainer_contains` | 66 | 6.5s |  |
| 230 | `displayobjectcontainer_getchildat` | 4 | 6.2s |  |
| 231 | `displayobjectcontainer_getchildbyname` | 9 | 6.1s |  |
| 232 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.1s |  |
| 233 | `displayobjectcontainer_getchildindex` | 28 | 6.1s |  |
| 234 | `displayobjectcontainer_removechild` | 10 | 6.1s |  |
| 235 | `displayobjectcontainer_removechild_errors` | 4 | 6.1s |  |
| 236 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.1s |  |
| 237 | `displayobjectcontainer_removechildat` | 18 | 6.1s |  |
| 238 | `displayobjectcontainer_removechildren` | 51 | 6.3s |  |
| 239 | `displayobjectcontainer_setchildindex` | 42 | 6.0s |  |
| 240 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.5s |  |
| 241 | `displayobjectcontainer_swapchildren` | 42 | 6.2s |  |
| 242 | `displayobjectcontainer_swapchildrenat` | 42 | 6.2s |  |
| 243 | `displayobjectcontainer_timelineinstance` | 48 | 25.4s |  |
| 244 | `divide` | 1058 | 18.7s |  |
| 245 | `doabc_is_eager` | 1 | 24.4s |  |
| 246 | `documentclass` | 9 | 6.4s |  |
| 247 | `domain_memory` | 133 | 7.4s |  |
| 248 | `drag_drop` | 10 | 6.7s |  |
| 249 | `duplicate_defs` | 1 | 6.3s |  |
| 250 | `eager_init` | 1 | 6.4s |  |
| 251 | `edit_text_linkage` | 7 | 6.5s |  |
| 252 | `edittext_align` | 60 | 6.7s |  |
| 253 | `edittext_always_show_selection` | 0 | 25.4s |  |
| 254 | `edittext_antialiastype` | 296 | 6.6s |  |
| 255 | `edittext_at_point_methods_basic` | 16 | 7.8s |  |
| 256 | `edittext_autosize` | 39 | 6.6s |  |
| 257 | `edittext_autosize_align` | 0 | 25.1s |  |
| 258 | `edittext_autosize_height_dynamic` | 60 | 25.4s |  |
| 259 | `edittext_autosize_height_input` | 60 | 6.4s |  |
| 260 | `edittext_autosize_lazy_bounds_events` | 65 | 6.6s |  |
| 261 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.3s |  |
| 262 | `edittext_autosize_lazy_bounds_props` | 490 | 7.7s |  |
| 263 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.1s |  |
| 264 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.5s |  |
| 265 | `edittext_bottom_scroll_v_basic` | 210 | 6.4s |  |
| 266 | `edittext_bounds_scale` | 24 | 24.6s |  |
| 267 | `edittext_bullet` | 30 | 6.4s |  |
| 268 | `edittext_default_format` | 221 | 6.8s |  |
| 269 | `edittext_default_format_empty` | 136 | 6.8s |  |
| 270 | `edittext_empty_text_format` | 7 | 6.5s |  |
| 271 | `edittext_focus_selection` | 5 | 6.5s |  |
| 272 | `edittext_font_size` | 45 | 6.5s |  |
| 273 | `edittext_format_empty_font` | 8 | 6.3s |  |
| 274 | `edittext_get_char_index_at_point` | 4 | 26.5s |  |
| 275 | `edittext_get_line_index_at_point` | 2 | 25.9s |  |
| 276 | `edittext_get_line_index_of_char` | 76 | 7.5s |  |
| 277 | `edittext_getcharboundaries` | 172 | 6.8s |  |
| 278 | `edittext_getcharboundaries_missing_glyphs` | 63 | 5.3s |  |
| 279 | `edittext_getcharboundaries_scroll` | 85 | 5.4s |  |
| 280 | `edittext_getlinemetrics` | 146 | 5.3s |  |
| 281 | `edittext_html` | 3101 | 5.4s |  |
| 282 | `edittext_html_condensewhite` | 487 | 5.1s |  |
| 283 | `edittext_html_entity` | 4 | 5.3s |  |
| 284 | `edittext_html_font_size_swf12` | 267 | 5.1s |  |
| 285 | `edittext_html_font_size_swf13` | 273 | 4.8s |  |
| 286 | `edittext_html_roundtrip` | 17 | 5.1s |  |
| 287 | `edittext_input_control` | 12 | 5.2s |  |
| 288 | `edittext_leading` | 9 | 5.2s |  |
| 289 | `edittext_letter_spacing` | 15 | 5.1s |  |
| 290 | `edittext_line_methods` | 294 | 6.1s |  |
| 291 | `edittext_line_metrics` | 11 | 22.0s |  |
| 292 | `edittext_margins` | 25 | 5.2s |  |
| 293 | `edittext_max_scroll_h_basic` | 475 | 5.2s |  |
| 294 | `edittext_max_scroll_v_basic` | 1000 | 5.2s |  |
| 295 | `edittext_mouse_selection` | 363 | 22.7s |  |
| 296 | `edittext_mousedown` | 3 | 5.4s |  |
| 297 | `edittext_mouseenabled` | 26 | 5.1s |  |
| 298 | `edittext_newline_character` | 22 | 5.1s |  |
| 299 | `edittext_newline_stripping` | 64 | 7.1s |  |
| 300 | `edittext_newlines` | 30 | 5.2s |  |
| 301 | `edittext_paragraph_methods` | 257 | 5.1s |  |
| 302 | `edittext_paste_events` | 8 | 5.4s |  |
| 303 | `edittext_paste_maxchars` | 4 | 5.1s |  |
| 304 | `edittext_paste_restrict` | 16 | 5.2s |  |
| 305 | `edittext_restrict` | 191 | 5.2s |  |
| 306 | `edittext_restrict_events` | 22 | 5.1s |  |
| 307 | `edittext_scrollh` | 10 | 5.2s |  |
| 308 | `edittext_selected_text` | 9 | 5.2s |  |
| 309 | `edittext_set_html_same` | 17 | 5.3s |  |
| 310 | `edittext_set_text_vs_html` | 9 | 5.1s |  |
| 311 | `edittext_stylesheet` | 536 | 5.6s |  |
| 312 | `edittext_stylesheet_custom_tag` | 76 | 5.2s |  |
| 313 | `edittext_stylesheet_display` | 272 | 5.5s |  |
| 314 | `edittext_underline` | 40 | 5.3s |  |
| 315 | `edittext_width_height` | 103 | 18.6s |  |
| 316 | `edittext_wordwrap_word` | 150 | 6.6s |  |
| 317 | `edittext_wrap_breaks` | 2375 | 6.8s |  |
| 318 | `empty_bounds` | 1 | 6.1s |  |
| 319 | `encode_uri_surrogate_pair_swf11` | 15 | 6.0s |  |
| 320 | `equals` | 512 | 10.4s |  |
| 321 | `error_geterrormessage` | 779 | 6.3s |  |
| 322 | `error_prototype` | 15 | 6.3s |  |
| 323 | `error_stack_trace_debug_swf17` | 0 | 25.0s |  |
| 324 | `error_stack_trace_debug_swf18` | 0 | 6.0s |  |
| 325 | `error_stack_trace_release_swf17` | 0 | 6.0s |  |
| 326 | `error_stack_trace_release_swf18` | 0 | 6.0s |  |
| 327 | `error_tostring` | 29 | 6.3s |  |
| 328 | `es3_inheritance` | 31 | 6.3s |  |
| 329 | `es4_inheritance` | 30 | 6.3s |  |
| 330 | `es4_interfaces` | 30 | 6.3s |  |
| 331 | `es4_method_binding` | 8 | 6.3s |  |
| 332 | `es4_oop_prototypes` | 14 | 6.6s |  |
| 333 | `es4_protected_inheritance` | 6 | 6.4s |  |
| 334 | `escape` | 71 | 6.5s |  |
| 335 | `event_bubbles` | 2 | 6.5s |  |
| 336 | `event_cancelable` | 2 | 6.4s |  |
| 337 | `event_clone` | 20 | 6.6s |  |
| 338 | `event_clone_error_redispatch` | 3 | 6.6s |  |
| 339 | `event_clone_on_redispatch` | 10 | 6.8s |  |
| 340 | `event_formattostring` | 31 | 6.6s |  |
| 341 | `event_isdefaultprevented` | 12 | 6.6s |  |
| 342 | `event_target_getter` | 5 | 3.1s |  |
| 343 | `event_target_set` | 9 | 6.2s |  |
| 344 | `event_type` | 1 | 15.5s |  |
| 345 | `event_valueof_tostring` | 18 | 4.9s |  |
| 346 | `eventdispatcher_dispatchevent` | 12 | 5.2s |  |
| 347 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.1s |  |
| 348 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.1s |  |
| 349 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.1s |  |
| 350 | `eventdispatcher_dispatchevent_this` | 5 | 5.0s |  |
| 351 | `eventdispatcher_haseventlistener` | 25 | 5.3s |  |
| 352 | `eventdispatcher_interface_invoke` | 1 | 4.9s |  |
| 353 | `eventdispatcher_tostring` | 10 | 4.9s |  |
| 354 | `eventdispatcher_willtrigger` | 25 | 4.9s |  |
| 355 | `falsiness` | 30 | 5.0s |  |
| 356 | `fast_index_access` | 12 | 5.0s |  |
| 357 | `finddef` | 3 | 5.0s |  |
| 358 | `findprop_global_prototype` | 6 | 4.9s |  |
| 359 | `flash_xml` | 29 | 5.1s |  |
| 360 | `flash_xml_cloneNode` | 22 | 5.1s |  |
| 361 | `flash_xml_namespace` | 109 | 4.9s |  |
| 362 | `flash_xml_removeNode` | 60 | 5.1s |  |
| 363 | `focus_events_code` | 161 | 20.9s |  |
| 364 | `focus_events_key_basic` | 132 | 20.9s |  |
| 365 | `focus_events_key_same_object` | 26 | 5.0s |  |
| 366 | `focus_events_mixed_key_mouse` | 100 | 20.7s |  |
| 367 | `focus_events_mouse_same_object` | 40 | 25.4s |  |
| 368 | `focus_remove` | 20 | 25.5s |  |
| 369 | `focus_root_movie` | 4 | 25.5s |  |
| 370 | `focus_stage` | 1 | 6.5s |  |
| 371 | `focusrect` | 18 | 7.3s |  |
| 372 | `focusrect_focuslost` | 9 | 6.6s |  |
| 373 | `focusrect_property` | 110 | 6.5s |  |
| 374 | `font_description_clone` | 14 | 6.5s |  |
| 375 | `font_embedded` | 24 | 6.9s |  |
| 376 | `font_enumeratefonts` | 41 | 7.2s |  |
| 377 | `font_enumeratefonts_filter` | 4 | 7.3s |  |
| 378 | `font_hasglyphs` | 40 | 6.9s |  |
| 379 | `framelabel_constr` | 5 | 6.7s |  |
| 380 | `function_call` | 12 | 6.7s |  |
| 381 | `function_call_arguments` | 46 | 6.7s |  |
| 382 | `function_call_arguments_enumerate` | 5 | 6.5s |  |
| 383 | `function_call_coercion` | 108 | 7.0s |  |
| 384 | `function_call_default` | 6 | 6.7s |  |
| 385 | `function_call_rest` | 22 | 6.8s |  |
| 386 | `function_call_types` | 3 | 6.6s |  |
| 387 | `function_call_via_apply` | 11 | 6.6s |  |
| 388 | `function_call_via_call` | 3 | 6.6s |  |
| 389 | `function_display_anonymous` | 7 | 3.2s |  |
| 390 | `function_length` | 6 | 6.6s |  |
| 391 | `function_object` | 2 | 6.5s |  |
| 392 | `function_proto` | 5 | 6.5s |  |
| 393 | `function_proto_created` | 61 | 6.5s |  |
| 394 | `function_to_locale_string` | 4 | 6.5s |  |
| 395 | `function_to_string` | 4 | 6.5s |  |
| 396 | `function_type` | 6 | 6.5s |  |
| 397 | `function_unbound_this` | 51 | 6.6s |  |
| 398 | `function_value_of` | 4 | 6.6s |  |
| 399 | `get_definition_by_name` | 11 | 6.6s |  |
| 400 | `get_qualified_class_name` | 20 | 19.1s |  |
| 401 | `get_qualified_super_class_name` | 18 | 6.7s |  |
| 402 | `get_slot_edge_cases` | 1 | 6.5s |  |
| 403 | `get_timer` | 2 | 6.5s |  |
| 404 | `getglobalslot` | 1 | 6.4s |  |
| 405 | `getouterscope` | 8 | 6.4s |  |
| 406 | `getter_different_namespace_setter` | 2 | 6.5s |  |
| 407 | `goto_button_nested_framescript` | 28 | 6.8s |  |
| 408 | `goto_in_constructframe` | 12 | 6.6s |  |
| 409 | `goto_in_scene_last_frame` | 2 | 24.8s |  |
| 410 | `goto_methods` | 56 | 6.7s |  |
| 411 | `goto_methods_swfver10` | 8 | 6.5s |  |
| 412 | `goto_nested_construct_sibling` | 18 | 7.0s |  |
| 413 | `goto_nested_framescript` | 9 | 6.6s |  |
| 414 | `goto_on_orphan` | 15 | 6.7s |  |
| 415 | `graphics_bad_direct_commands` | 5 | 7.2s |  |
| 416 | `graphics_bitmap_fill` | 0 | 8.4s |  |
| 417 | `graphics_bitmaps` | 0 | 7.2s |  |
| 418 | `graphics_direct_commands` | 0 | 7.1s |  |
| 419 | `graphics_draw_triangles` | 98 | 26.3s |  |
| 420 | `graphics_gradients` | 0 | 7.1s |  |
| 421 | `graphics_gradients_nulls` | 0 | 7.0s |  |
| 422 | `graphics_path` | 56 | 6.8s |  |
| 423 | `graphics_round_rects` | 0 | 6.5s |  |
| 424 | `graphics_simple_shapes` | 0 | 7.0s |  |
| 425 | `greaterequals` | 512 | 10.5s |  |
| 426 | `greaterthan` | 512 | 11.1s |  |
| 427 | `has_own_property` | 102 | 7.2s |  |
| 428 | `hasownproperty_namespaces` | 2 | 6.7s |  |
| 429 | `hello_world` | 1 | 6.7s |  |
| 430 | `hittest_morph` | 30 | 6.7s |  |
| 431 | `if_eq` | 10 | 6.5s |  |
| 432 | `if_gt` | 1 | 6.5s |  |
| 433 | `if_gte` | 10 | 19.1s |  |
| 434 | `if_lt` | 1 | 6.5s |  |
| 435 | `if_lte` | 10 | 6.5s |  |
| 436 | `if_ne` | 7 | 3.1s |  |
| 437 | `if_stricteq` | 6 | 6.6s |  |
| 438 | `if_strictne` | 11 | 6.5s |  |
| 439 | `in` | 102 | 6.9s |  |
| 440 | `inclocal` | 46 | 6.5s |  |
| 441 | `inclocal_i` | 46 | 6.5s |  |
| 442 | `increment` | 46 | 6.5s |  |
| 443 | `increment_i` | 46 | 6.5s |  |
| 444 | `indexing_delete` | 75 | 6.5s |  |
| 445 | `instanceof` | 58 | 6.8s |  |
| 446 | `instantiation_on_enter_frame` | 7 | 25.6s |  |
| 447 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.6s |  |
| 448 | `int_constr` | 92 | 6.6s |  |
| 449 | `int_edge_cases` | 19 | 6.6s |  |
| 450 | `int_instanceof` | 3 | 6.5s |  |
| 451 | `int_tofixed` | 1215 | 6.4s |  |
| 452 | `int_tostring` | 3375 | 6.5s |  |
| 453 | `interactiveobject_enabled` | 25 | 6.5s |  |
| 454 | `interface_namespaces` | 78 | 6.8s |  |
| 455 | `is_finite` | 46 | 6.6s |  |
| 456 | `is_nan` | 46 | 6.4s |  |
| 457 | `is_prototype_of` | 12 | 6.5s |  |
| 458 | `issue_10221` | 2 | 6.4s |  |
| 459 | `issue_13780` | 12 | 6.5s |  |
| 460 | `issue_14901` | 1 | 6.6s |  |
| 461 | `issue_17675_edittext_paste_maxchars` | 1 | 6.5s |  |
| 462 | `issue_5292` | 5 | 6.5s |  |
| 463 | `issue_8630` | 2 | 6.5s |  |
| 464 | `issue_8630_scriptremove` | 11 | 6.5s |  |
| 465 | `istype` | 24 | 3.1s |  |
| 466 | `istypelate` | 58 | 6.8s |  |
| 467 | `istypelate_coerce` | 198 | 17.1s |  |
| 468 | `jpeg_loader_context` | 6 | 5.2s |  |
| 469 | `json_errors` | 9 | 21.8s |  |
| 470 | `json_parse` | 21 | 5.5s |  |
| 471 | `json_stringify` | 12 | 5.4s |  |
| 472 | `json_stringify_order` | 1 | 5.2s |  |
| 473 | `json_version_gated` | 1 | 5.3s |  |
| 474 | `key_input_80percent` | 1812 | 5.5s |  |
| 475 | `key_input_location` | 126 | 5.4s |  |
| 476 | `key_input_numpad` | 384 | 5.7s |  |
| 477 | `lazyinit` | 17 | 5.2s |  |
| 478 | `lessequals` | 512 | 7.9s |  |
| 479 | `lessthan` | 512 | 7.8s |  |
| 480 | `loader_bitmap_transparency` | 14 | 5.4s |  |
| 481 | `loader_bytes_unknown_content` | 14 | 5.3s |  |
| 482 | `loader_child_getdefinition` | 5 | 5.5s |  |
| 483 | `loader_duplicate_coerce` | 3 | 5.5s |  |
| 484 | `loader_duplicate_coerce_new_domain` | 4 | 5.4s |  |
| 485 | `loader_error_in_root_ctor` | 4 | 5.5s |  |
| 486 | `loader_events` | 92 | 6.1s |  |
| 487 | `loader_image` | 8 | 5.9s |  |
| 488 | `loader_jpegxr` | 2 | 22.1s |  |
| 489 | `loader_jpegxr_alpha` | 1 | 22.1s |  |
| 490 | `loader_loadbytes_events` | 30 | 5.8s |  |
| 491 | `loader_loadbytes_invalid_png` | 4 | 5.4s |  |
| 492 | `loader_loadbytes_url` | 12 | 5.7s |  |
| 493 | `loader_loaderurl` | 6 | 5.6s |  |
| 494 | `loader_noninteractive_try_click_root` | 5 | 22.9s |  |
| 495 | `loader_reuse` | 38 | 5.7s |  |
| 496 | `loader_unknown_content` | 24 | 5.7s |  |
| 497 | `loader_visibility_interactive` | 1 | 5.4s |  |
| 498 | `loaderinfo_events` | 7 | 5.3s |  |
| 499 | `loaderinfo_loadurl` | 12 | 18.1s |  |
| 500 | `loaderinfo_more` | 6 | 6.5s |  |
| 501 | `loaderinfo_properties` | 18 | 6.2s |  |
| 502 | `loaderinfo_properties_not_loaded` | 23 | 6.3s |  |
| 503 | `loaderinfo_root` | 10 | 6.2s |  |
| 504 | `loaderinfo_root_allows` | 2 | 6.1s |  |
| 505 | `lshift` | 1058 | 18.0s |  |
| 506 | `mask_reapply` | 1 | 6.2s |  |
| 507 | `math` | 497 | 6.4s |  |
| 508 | `missing_external_interface` | 10 | 6.5s |  |
| 509 | `modulo` | 1058 | 18.8s |  |
| 510 | `morph_shape` | 2 | 24.8s |  |
| 511 | `mouse_children` | 192 | 24.9s |  |
| 512 | `mouse_click_events` | 90 | 24.3s |  |
| 513 | `mouse_double_click_events` | 188 | 6.2s |  |
| 514 | `mouse_empty_parent` | 4 | 6.2s |  |
| 515 | `mouse_over_while_dragging` | 3 | 6.3s |  |
| 516 | `mouse_pick_button_mode` | 2 | 6.3s |  |
| 517 | `mouse_pick_dobj_mask` | 4 | 6.5s |  |
| 518 | `mouse_pick_masking` | 7 | 24.6s |  |
| 519 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 24.4s |  |
| 520 | `mouse_pick_non_interactive_dobj_mask` | 3 | 6.5s |  |
| 521 | `mouse_pick_text` | 8 | 6.4s |  |
| 522 | `mouse_sibling` | 8 | 6.3s |  |
| 523 | `mouse_wheel_events` | 36 | 25.4s |  |
| 524 | `mouseevent_constr` | 66 | 6.2s |  |
| 525 | `mouseevent_stagexy` | 35 | 6.2s |  |
| 526 | `mouseevent_valueof_tostring` | 28 | 6.2s |  |
| 527 | `movieclip_addframescript` | 3 | 24.4s |  |
| 528 | `movieclip_child_property` | 16 | 6.2s |  |
| 529 | `movieclip_constr` | 21 | 19.1s |  |
| 530 | `movieclip_currentlabels` | 17 | 25.3s |  |
| 531 | `movieclip_currentlabels_dupes1` | 46 | 25.7s |  |
| 532 | `movieclip_currentlabels_dupes2` | 30 | 6.7s |  |
| 533 | `movieclip_currentlabels_dupes3` | 67 | 6.6s |  |
| 534 | `movieclip_currentscene` | 12 | 6.8s |  |
| 535 | `movieclip_dispatchevent` | 430 | 6.7s |  |
| 536 | `movieclip_dispatchevent_cancel` | 102 | 6.7s |  |
| 537 | `movieclip_dispatchevent_handlerorder` | 251 | 6.7s |  |
| 538 | `movieclip_dispatchevent_selfadd` | 80 | 6.6s |  |
| 539 | `movieclip_dispatchevent_target` | 899 | 6.6s |  |
| 540 | `movieclip_displayevents` | 96 | 25.7s |  |
| 541 | `movieclip_displayevents_clickgoto` | 676 | 7.1s |  |
| 542 | `movieclip_displayevents_clickgoto2` | 2001 | 7.2s |  |
| 543 | `movieclip_displayevents_clickplay` | 575 | 6.8s |  |
| 544 | `movieclip_displayevents_clicksymbol` | 562 | 6.8s |  |
| 545 | `movieclip_displayevents_constructframegoto` | 140 | 7.0s |  |
| 546 | `movieclip_displayevents_constructframeplay` | 50 | 6.9s |  |
| 547 | `movieclip_displayevents_constructframesymbol` | 144 | 6.8s |  |
| 548 | `movieclip_displayevents_dblhandler` | 21 | 6.8s |  |
| 549 | `movieclip_displayevents_enterframegoto` | 149 | 6.9s |  |
| 550 | `movieclip_displayevents_enterframeplay` | 48 | 6.7s |  |
| 551 | `movieclip_displayevents_enterframesymbol` | 149 | 25.8s |  |
| 552 | `movieclip_displayevents_exitframegoto` | 106 | 6.7s |  |
| 553 | `movieclip_displayevents_exitframeplay` | 44 | 6.7s |  |
| 554 | `movieclip_displayevents_exitframesymbol` | 135 | 6.8s |  |
| 555 | `movieclip_displayevents_looping` | 63 | 25.9s |  |
| 556 | `movieclip_displayevents_stopped` | 113 | 7.2s |  |
| 557 | `movieclip_displayevents_swap` | 96 | 3.1s |  |
| 558 | `movieclip_displayevents_timeline` | 128 | 26.3s |  |
| 559 | `movieclip_drawrect` | 54 | 6.7s |  |
| 560 | `movieclip_frameconstruct_skipped` | 9 | 6.8s |  |
| 561 | `movieclip_goto_during_frame_script` | 15 | 6.7s |  |
| 562 | `movieclip_goto_overwrite` | 14 | 25.7s |  |
| 563 | `movieclip_goto_scene_last_frame_int` | 1 | 25.9s |  |
| 564 | `movieclip_goto_scene_last_frame_label` | 1 | 6.5s |  |
| 565 | `movieclip_gotoandplay` | 15 | 25.7s |  |
| 566 | `movieclip_gotoandstop` | 13 | 6.6s |  |
| 567 | `movieclip_gotoandstop_children` | 4 | 6.7s |  |
| 568 | `movieclip_gotoandstop_framescripts1` | 4 | 6.6s |  |
| 569 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 570 | `movieclip_gotoandstop_framescripts_self` | 7 | 18.4s |  |
| 571 | `movieclip_gotoandstop_queueing` | 12 | 6.5s |  |
| 572 | `movieclip_next_frame` | 2 | 6.4s |  |
| 573 | `movieclip_next_scene` | 6 | 24.3s |  |
| 574 | `movieclip_play` | 3 | 6.1s |  |
| 575 | `movieclip_prev_frame` | 3 | 6.0s |  |
| 576 | `movieclip_prev_scene` | 7 | 6.2s |  |
| 577 | `movieclip_properties` | 79 | 6.5s |  |
| 578 | `movieclip_queued_noop_goto_swf10` | 9 | 6.2s |  |
| 579 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 580 | `movieclip_scenes` | 11 | 6.2s |  |
| 581 | `movieclip_soundtransform` | 831 | 26.8s |  |
| 582 | `movieclip_stop` | 1 | 6.1s |  |
| 583 | `movieclip_super_is_symbol` | 20 | 6.5s |  |
| 584 | `movieclip_symbol_constr` | 8 | 6.3s |  |
| 585 | `movieclip_text_mousedown` | 1 | 6.2s |  |
| 586 | `movieclip_willtrigger` | 5 | 6.4s |  |
| 587 | `multiply` | 1058 | 18.2s |  |
| 588 | `namespace_constr` | 253 | 6.5s |  |
| 589 | `namespace_constr_args` | 1 | 6.1s |  |
| 590 | `namespace_enumeration_order` | 7 | 6.2s |  |
| 591 | `nan_scale` | 9 | 6.2s |  |
| 592 | `navigateToURL_target_normalize` | 107 | 25.4s |  |
| 593 | `negate` | 30 | 6.3s |  |
| 594 | `negative_volume_panned` | 0 | 6.6s |  |
| 595 | `nested_iteration` | 11 | 6.3s |  |
| 596 | `net_getClassByAlias` | 3 | 6.3s |  |
| 597 | `net_navigateToURL` | 57 | 6.3s |  |
| 598 | `newactivation_in_script_init` | 3 | 7.0s |  |
| 599 | `newclass_twice` | 3 | 6.8s |  |
| 600 | `nonconflicting_declarations` | 0 | 6.8s |  |
| 601 | `null_void_types` | 8 | 6.8s |  |
| 602 | `number_autoconv` | 21 | 6.8s |  |
| 603 | `number_autoconv_amf` | 132 | 6.8s |  |
| 604 | `number_autoconv_array_sort_32bit` | 1 | 6.7s |  |
| 605 | `number_constr` | 58 | 6.8s |  |
| 606 | `number_toexponential` | 378 | 6.6s |  |
| 607 | `number_toexponential2` | 35 | 6.5s |  |
| 608 | `number_tofixed` | 378 | 6.4s |  |
| 609 | `number_toprecision` | 350 | 6.6s |  |
| 610 | `obfuscated_class_names` | 3 | 6.5s |  |
| 611 | `object_enumeration` | 10 | 6.7s |  |
| 612 | `object_prototype` | 4 | 6.8s |  |
| 613 | `object_to_locale_string` | 2 | 6.7s |  |
| 614 | `object_to_string` | 2 | 6.7s |  |
| 615 | `object_value_of` | 2 | 3.1s |  |
| 616 | `op_coerce` | 54 | 6.8s |  |
| 617 | `op_coerce_x` | 54 | 6.7s |  |
| 618 | `op_escxattr` | 2 | 6.9s |  |
| 619 | `op_escxelem` | 2 | 7.0s |  |
| 620 | `op_lookupswitch` | 4 | 6.9s |  |
| 621 | `optimize_coerce` | 1 | 6.9s |  |
| 622 | `orphan_movie_complex` | 80 | 7.1s |  |
| 623 | `orphan_movie_reorder` | 111 | 25.9s |  |
| 624 | `package_namespace` | 7 | 6.4s |  |
| 625 | `param_default_value_has_zero_cpool_index` | 1 | 6.6s |  |
| 626 | `parent_early_access_child` | 16 | 7.0s |  |
| 627 | `parse_float` | 81 | 6.8s |  |
| 628 | `pixelbender_effect_BlurredFocus` | 0 | 29.8s |  |
| 629 | `pixelbender_effect_glassDisplace` | 0 | 12.2s |  |
| 630 | `pixelbender_effect_smudge` | 0 | 9.9s |  |
| 631 | `pixelbender_effect_tintype` | 0 | 9.2s |  |
| 632 | `pixelbender_effect_twirl` | 0 | 10.2s |  |
| 633 | `pixelbender_images` | 0 | 8.7s |  |
| 634 | `place_multiple` | 17 | 6.5s |  |
| 635 | `place_object_replace` | 9 | 6.6s |  |
| 636 | `place_object_replace_2` | 24 | 6.7s |  |
| 637 | `place_object_same_depth_frame` | 1 | 6.5s |  |
| 638 | `point` | 132 | 7.0s |  |
| 639 | `primitive_edge_cases` | 1 | 6.3s |  |
| 640 | `property_priority` | 22 | 7.0s |  |
| 641 | `property_priority_three_level` | 6 | 6.7s |  |
| 642 | `propertyisenumerable_namespaces` | 6 | 6.7s |  |
| 643 | `prototype_set_null` | 7 | 6.6s |  |
| 644 | `proxy_callproperty` | 24 | 6.8s |  |
| 645 | `proxy_deleteproperty` | 64 | 6.7s |  |
| 646 | `proxy_enumeration` | 34 | 6.8s |  |
| 647 | `proxy_getproperty` | 77 | 6.8s |  |
| 648 | `proxy_hasownproperty` | 8 | 6.7s |  |
| 649 | `proxy_hasproperty` | 32 | 6.8s |  |
| 650 | `proxy_serialize` | 9 | 6.6s |  |
| 651 | `proxy_setproperty` | 42 | 6.8s |  |
| 652 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.5s |  |
| 653 | `qname_constr` | 32 | 6.6s |  |
| 654 | `qname_constr_namespace` | 24 | 6.5s |  |
| 655 | `qname_enumeration` | 9 | 6.5s |  |
| 656 | `qname_indexing` | 23 | 6.6s |  |
| 657 | `qname_tostring` | 25 | 6.6s |  |
| 658 | `qname_valueof` | 29 | 6.7s |  |
| 659 | `regexp_constr` | 148 | 6.9s |  |
| 660 | `regexp_exec` | 19 | 6.7s |  |
| 661 | `regexp_extended` | 47 | 6.7s |  |
| 662 | `regexp_multiargs` | 1 | 6.6s |  |
| 663 | `regexp_test` | 27 | 6.7s |  |
| 664 | `regexp_toString` | 10 | 6.8s |  |
| 665 | `register_script_refresh` | 35 | 7.1s |  |
| 666 | `remove_child_clear_field` | 88 | 7.0s |  |
| 667 | `remove_dobj` | 3 | 6.6s |  |
| 668 | `resolve_order` | 4 | 6.6s |  |
| 669 | `rng` | 1 | 8.0s |  |
| 670 | `rootless` | 42 | 6.9s |  |
| 671 | `rshift` | 1058 | 18.9s |  |
| 672 | `sandbox_type_inherited` | 2 | 19.0s |  |
| 673 | `sandbox_type_local_file` | 1 | 6.6s |  |
| 674 | `scene_constr` | 8 | 6.6s |  |
| 675 | `selection` | 239 | 7.0s |  |
| 676 | `set_local_0` | 31 | 6.5s |  |
| 677 | `set_property_is_enumerable` | 85 | 7.0s |  |
| 678 | `shape_drawrect` | 54 | 6.5s |  |
| 679 | `shared_object_no_root` | 3 | 6.5s |  |
| 680 | `simplebutton_added_to_stage` | 45 | 26.0s |  |
| 681 | `simplebutton_childevents` | 86 | 7.0s |  |
| 682 | `simplebutton_childevents_nested` | 54 | 6.8s |  |
| 683 | `simplebutton_childevents_sprite` | 13 | 6.5s |  |
| 684 | `simplebutton_childprops` | 144 | 6.7s |  |
| 685 | `simplebutton_childshuffle` | 23 | 6.3s |  |
| 686 | `simplebutton_constr` | 36 | 6.7s |  |
| 687 | `simplebutton_constr_childevents` | 48 | 6.8s |  |
| 688 | `simplebutton_constr_params` | 42 | 6.5s |  |
| 689 | `simplebutton_mouseenabled` | 26 | 6.3s |  |
| 690 | `simplebutton_multi_children` | 19 | 6.5s |  |
| 691 | `simplebutton_structure` | 27 | 6.6s |  |
| 692 | `simplebutton_symbolclass` | 68 | 6.8s |  |
| 693 | `slot_disp_id_shared_numbering` | 1 | 24.9s |  |
| 694 | `slots_force_autoassigned` | 1 | 6.4s |  |
| 695 | `sound_embeddedprops` | 26 | 6.6s |  |
| 696 | `sound_play` | 19 | 6.5s |  |
| 697 | `sound_valueof` | 33 | 6.3s |  |
| 698 | `soundchannel_soundtransform` | 835 | 26.4s |  |
| 699 | `soundchannel_soundtransform_exists` | 5 | 24.5s |  |
| 700 | `soundchannel_stop` | 8 | 6.4s |  |
| 701 | `soundmixer_buffertime` | 5 | 6.2s |  |
| 702 | `soundmixer_stopall` | 6 | 6.3s |  |
| 703 | `soundtransform` | 442 | 11.8s |  |
| 704 | `sprite_with_frames` | 0 | 6.8s |  |
| 705 | `stage3d_agal_cross_product` | 0 | 8.8s |  |
| 706 | `stage3d_bitmap` | 0 | 29.6s |  |
| 707 | `stage3d_float1_index` | 0 | 26.9s |  |
| 708 | `stage3d_fractal` | 0 | 27.5s |  |
| 709 | `stage3d_ignore_sampler_override` | 0 | 27.3s |  |
| 710 | `stage3d_program_constants_bytearray_be` | 0 | 28.4s |  |
| 711 | `stage3d_program_constants_bytearray_le` | 0 | 9.5s |  |
| 712 | `stage3d_raytrace` | 0 | 30.6s |  |
| 713 | `stage3d_rotating_cube` | 0 | 9.7s |  |
| 714 | `stage3d_sampler` | 0 | 17.9s |  |
| 715 | `stage3d_sampler_partial_upload` | 0 | 7.5s |  |
| 716 | `stage3d_stencil` | 0 | 24.3s |  |
| 717 | `stage3d_texture` | 0 | 11.5s |  |
| 718 | `stage3d_texture_bytearray` | 0 | 8.3s |  |
| 719 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 7.9s |  |
| 720 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.0s |  |
| 721 | `stage3d_triangle` | 0 | 7.4s |  |
| 722 | `stage3d_triangle_bytes4` | 0 | 7.5s |  |
| 723 | `stage3d_triangle_float1` | 0 | 7.3s |  |
| 724 | `stage3d_triangle_index_upload` | 0 | 7.4s |  |
| 725 | `stage_access` | 10 | 5.2s |  |
| 726 | `stage_displayobject_properties` | 24 | 5.1s |  |
| 727 | `stage_framerate_nan` | 7 | 5.6s |  |
| 728 | `stage_framerate_negative` | 6 | 5.2s |  |
| 729 | `stage_framerate_zero` | 6 | 5.2s |  |
| 730 | `stage_invalidate` | 38 | 5.3s |  |
| 731 | `stage_loaderinfo_properties` | 24 | 5.5s |  |
| 732 | `stage_mousechildren` | 2 | 5.1s |  |
| 733 | `stage_mouseenabled` | 15 | 5.0s |  |
| 734 | `stage_overriden_setters` | 31 | 5.3s |  |
| 735 | `stage_properties` | 30 | 5.2s |  |
| 736 | `static_var_with_this_in_ctor` | 2 | 5.1s |  |
| 737 | `stored_properties` | 11 | 5.2s |  |
| 738 | `strict_equality` | 34 | 5.3s |  |
| 739 | `string_call` | 13 | 5.2s |  |
| 740 | `string_case` | 23 | 5.1s |  |
| 741 | `string_char_at` | 27 | 5.2s |  |
| 742 | `string_char_code_at` | 28 | 5.1s |  |
| 743 | `string_concat_fromcharcode` | 37 | 5.1s |  |
| 744 | `string_constr` | 25 | 5.2s |  |
| 745 | `string_indexof_lastindexof` | 87 | 19.4s |  |
| 746 | `string_length` | 16 | 6.7s |  |
| 747 | `string_locale_compare` | 39 | 7.0s |  |
| 748 | `string_match` | 51 | 6.9s |  |
| 749 | `string_relational_compare` | 4 | 6.6s |  |
| 750 | `string_replace` | 51 | 6.9s |  |
| 751 | `string_search` | 41 | 6.7s |  |
| 752 | `string_slice_substr_substring` | 170 | 7.6s |  |
| 753 | `string_split` | 29 | 6.6s |  |
| 754 | `string_substr_negative` | 21 | 6.5s |  |
| 755 | `string_substr_weird` | 182 | 6.5s |  |
| 756 | `subtract` | 1058 | 18.2s |  |
| 757 | `super_get_call` | 12 | 6.6s |  |
| 758 | `supercall_two_classobjects` | 2 | 6.6s |  |
| 759 | `swf8` | 1 | 6.5s |  |
| 760 | `swf_10_queued_goto_scripts_construct` | 52 | 6.8s |  |
| 761 | `swf_9_goto_in_enter_frame` | 17 | 6.6s |  |
| 762 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.7s |  |
| 763 | `swf_9_queued_goto_scripts` | 6 | 6.6s |  |
| 764 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 765 | `swf_9_versioning` | 2 | 6.4s |  |
| 766 | `swf_wrong_frame_count` | 38 | 6.7s |  |
| 767 | `swf_wrong_frame_count_isplaying` | 22 | 6.5s |  |
| 768 | `symbol_class_binary_data` | 8 | 6.5s |  |
| 769 | `symbol_class_conflict` | 4 | 6.9s |  |
| 770 | `symbol_class_root_not_zero` | 1 | 6.6s |  |
| 771 | `symbolclass_invalid_utf8` | 2 | 6.6s |  |
| 772 | `tab_ordering_automatic_advanced` | 184 | 7.0s |  |
| 773 | `tab_ordering_automatic_basic` | 45 | 6.3s |  |
| 774 | `tab_ordering_children` | 116 | 6.4s |  |
| 775 | `tab_ordering_custom_basic` | 34 | 6.2s |  |
| 776 | `tab_ordering_stage_tab_children` | 32 | 6.4s |  |
| 777 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.2s |  |
| 778 | `tab_ordering_tabbable` | 47 | 6.4s |  |
| 779 | `text_engine_fontdescription` | 27 | 6.4s |  |
| 780 | `text_run` | 7 | 6.1s |  |
| 781 | `textbox_click` | 37 | 24.7s |  |
| 782 | `textfield_focusin_event` | 9 | 6.2s |  |
| 783 | `textfield_input_dead_keys_windows` | 15 | 6.3s |  |
| 784 | `textfield_unload` | 39 | 6.7s |  |
| 785 | `textformat` | 1134 | 6.3s |  |
| 786 | `textformat_display` | 14 | 6.3s |  |
| 787 | `textformat_font_max_length` | 4 | 6.3s |  |
| 788 | `throw` | 3 | 6.3s |  |
| 789 | `timeline_scripts` | 3 | 6.3s |  |
| 790 | `timer` | 90 | 7.3s |  |
| 791 | `timer_events` | 3 | 6.3s |  |
| 792 | `timer_finished` | 11 | 6.5s |  |
| 793 | `timer_reset` | 8 | 6.6s |  |
| 794 | `timer_setdelay` | 5 | 6.5s |  |
| 795 | `trace` | 12 | 6.2s |  |
| 796 | `truthiness` | 30 | 17.7s |  |
| 797 | `try_catch` | 11 | 5.2s |  |
| 798 | `try_catch_typed` | 12 | 5.2s |  |
| 799 | `typeof` | 30 | 5.2s |  |
| 800 | `uint_constr` | 92 | 5.3s |  |
| 801 | `uint_tofixed` | 1215 | 5.4s |  |
| 802 | `uint_tostring` | 3375 | 5.3s |  |
| 803 | `unchecked_function` | 15 | 5.3s |  |
| 804 | `unescape` | 28 | 5.2s |  |
| 805 | `url_loader` | 25 | 5.3s |  |
| 806 | `urlrequest` | 18 | 5.3s |  |
| 807 | `urshift` | 1058 | 5.2s |  |
| 808 | `vector_class` | 36 | 5.2s |  |
| 809 | `vector_class_call` | 11 | 5.2s |  |
| 810 | `vector_coercion` | 66 | 5.2s |  |
| 811 | `vector_concat` | 90 | 5.2s |  |
| 812 | `vector_constr` | 107 | 5.2s |  |
| 813 | `vector_enumeration` | 5 | 5.2s |  |
| 814 | `vector_every` | 92 | 5.2s |  |
| 815 | `vector_filter` | 95 | 5.2s |  |
| 816 | `vector_holes` | 24 | 5.3s |  |
| 817 | `vector_indexof` | 302 | 5.2s |  |
| 818 | `vector_insertat` | 270 | 5.3s |  |
| 819 | `vector_int_access` | 4 | 5.3s |  |
| 820 | `vector_int_delete` | 11 | 5.3s |  |
| 821 | `vector_join` | 58 | 5.3s |  |
| 822 | `vector_lastindexof` | 302 | 5.3s |  |
| 823 | `vector_legacy` | 10 | 5.3s |  |
| 824 | `vector_map` | 85 | 5.3s |  |
| 825 | `vector_object_final` | 1 | 5.3s |  |
| 826 | `vector_object_toString` | 10 | 5.2s |  |
| 827 | `vector_pushpop` | 255 | 5.2s |  |
| 828 | `vector_reborrow_bug` | 10 | 19.0s |  |
| 829 | `vector_removeat` | 172 | 7.5s |  |
| 830 | `vector_reverse` | 232 | 7.5s |  |
| 831 | `vector_shiftunshift` | 252 | 6.4s |  |
| 832 | `vector_slice` | 331 | 8.0s |  |
| 833 | `vector_sort` | 905 | 15.0s |  |
| 834 | `vector_splice` | 693 | 10.1s |  |
| 835 | `vector_splice_fixed_bug_compat` | 4 | 6.5s |  |
| 836 | `vector_tostring` | 79 | 7.0s |  |
| 837 | `verify_abnormal_loop` | 1 | 6.4s |  |
| 838 | `verify_exception_targets_edge_case` | 1 | 6.4s |  |
| 839 | `verify_lookup_switch_edge_case` | 1 | 6.2s |  |
| 840 | `verify_unreachable_exception` | 2 | 6.4s |  |
| 841 | `versioned_isplaying` | 2 | 6.4s |  |
| 842 | `virtual_properties` | 16 | 6.5s |  |
| 843 | `with` | 4 | 6.4s |  |
| 844 | `wrong_arg_count` | 7 | 6.6s |  |
| 845 | `xml_abstract_equality` | 36 | 6.6s |  |
| 846 | `xml_advanced` | 52 | 6.5s |  |
| 847 | `xml_appendchild` | 10 | 6.5s |  |
| 848 | `xml_as_attribute` | 9 | 6.4s |  |
| 849 | `xml_attribute` | 35 | 6.7s |  |
| 850 | `xml_attribute_name` | 40 | 6.4s |  |
| 851 | `xml_basic` | 33 | 6.5s |  |
| 852 | `xml_child` | 25 | 6.5s |  |
| 853 | `xml_childindex` | 7 | 6.4s |  |
| 854 | `xml_children` | 43 | 7.0s |  |
| 855 | `xml_class_call` | 9 | 6.4s |  |
| 856 | `xml_contains` | 197 | 6.6s |  |
| 857 | `xml_copy` | 20 | 18.8s |  |
| 858 | `xml_ctor_from_tostring` | 23 | 6.6s |  |
| 859 | `xml_delete` | 114 | 6.4s |  |
| 860 | `xml_descendants` | 83 | 6.4s |  |
| 861 | `xml_elements` | 6 | 6.2s |  |
| 862 | `xml_equals_namespace_check` | 2 | 6.2s |  |
| 863 | `xml_explicit_use_namespace` | 5 | 6.4s |  |
| 864 | `xml_getdescendants_qname` | 21 | 6.4s |  |
| 865 | `xml_has_property_via_in` | 26 | 6.4s |  |
| 866 | `xml_hasownproperty` | 6 | 6.2s |  |
| 867 | `xml_ignore_white` | 6 | 6.2s |  |
| 868 | `xml_length` | 2 | 6.3s |  |
| 869 | `xml_list_as_attribute` | 9 | 6.3s |  |
| 870 | `xml_list_concat` | 20 | 6.4s |  |
| 871 | `xml_list_enumerate` | 4 | 6.3s |  |
| 872 | `xml_methods_settings` | 3 | 6.3s |  |
| 873 | `xml_mismatched_tag` | 37 | 6.3s |  |
| 874 | `xml_namespace` | 39 | 6.3s |  |
| 875 | `xml_namespace_methods` | 245 | 6.4s |  |
| 876 | `xml_namespaced_property` | 7 | 6.3s |  |
| 877 | `xml_no_namespace` | 1 | 6.2s |  |
| 878 | `xml_nodekind` | 3 | 6.3s |  |
| 879 | `xml_normalize` | 35 | 6.4s |  |
| 880 | `xml_notification_bubbling` | 361 | 6.4s |  |
| 881 | `xml_parent` | 8 | 6.2s |  |
| 882 | `xml_set_children` | 17 | 6.7s |  |
| 883 | `xml_set_name` | 34 | 6.7s |  |
| 884 | `xml_settings` | 6 | 3.1s |  |
| 885 | `xml_simple_complex_content` | 47 | 6.9s |  |
| 886 | `xml_text` | 7 | 6.7s |  |
| 887 | `xml_tostring` | 6 | 7.1s |  |
| 888 | `xml_tostring_namespace` | 12 | 7.0s |  |
| 889 | `xml_unescaping` | 23 | 7.3s |  |
| 890 | `xml_weird_ignores` | 54 | 7.3s |  |
| 891 | `xml_wildcard` | 11 | 7.2s |  |
| 892 | `xmldocument` | 254 | 7.0s |  |
| 893 | `xmlnode` | 3540 | 7.3s |  |
| 894 | `zero_frame_clip` | 3 | 7.7s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.3s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.3s |  |
| 3 | `blend_transform` | 1 | 1 | 6.8s |  |
| 4 | `coerce_property` | 3 | 3 | 6.3s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.4s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 6.8s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.6s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 31.2s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 5.3s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.2s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.4s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 6.4s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 6.6s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 25.9s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.4s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.4s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.6s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.3s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 6.4s |  |
| 20 | `soundchannel_position` | 74 | 74 | 25.3s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.5s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.3s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 6.9s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.3s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.3s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 6.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**58 tests** within reach

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
| 12 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 14 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 15 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 16 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 17 | `place_and_lookup/swf10` | 87.9% | 29 | 33 | 4 |  |
| 18 | `place_and_lookup/swf9` | 87.9% | 29 | 33 | 4 |  |
| 19 | `perspective_projection_basic` | 87.5% | 35 | 40 | 5 |  |
| 20 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 21 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13 | 15 | 2 |  |
| 22 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 23 | `bounds_mode` | 86.6% | 233 | 269 | 36 |  |
| 24 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 25 | `displayobject_hittestpoint_root` | 84.6% | 11 | 13 | 2 |  |
| 26 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 27 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 28 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 29 | `matrix` | 83.1% | 281 | 338 | 57 |  |
| 30 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 31 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 32 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 33 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 34 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 35 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 36 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 37 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 38 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 39 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 40 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 41 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 42 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 43 | `construct_interface` | 66.7% | 2 | 3 | 1 |  |
| 44 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
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
| 1 | `method_without_body` | exit code 1 | 25.7s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 6.5s |  |
| 3 | `verify_typecheck` | exit code 1 | 6.4s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**298 tests** with output mismatch, sorted by match rate (best first)

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
| 12 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 13 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 14 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 15 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 16 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 17 | `place_and_lookup/swf10` | 87.9% | 29/33 | 32 | 33 |  |
| 18 | `place_and_lookup/swf9` | 87.9% | 29/33 | 32 | 33 |  |
| 19 | `perspective_projection_basic` | 87.5% | 35/40 | 40 | 40 |  |
| 20 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 21 | `displayobjectcontainer_getobjectsunderpoint` | 86.7% | 13/15 | 13 | 15 |  |
| 22 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 23 | `bounds_mode` | 86.6% | 233/269 | 269 | 269 |  |
| 24 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 25 | `displayobject_hittestpoint_root` | 84.6% | 11/13 | 13 | 13 |  |
| 26 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 27 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 28 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 29 | `matrix` | 83.1% | 281/338 | 283 | 338 |  |
| 30 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 31 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 32 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 33 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 34 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 35 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 36 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 37 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 38 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 39 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 40 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 41 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 42 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 43 | `construct_interface` | 66.7% | 2/3 | 3 | 3 |  |
| 44 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
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
| 75 | `focus_events_key_navigation` | 22.6% | 12/53 | 23 | 53 |  |
| 76 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 77 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 78 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 79 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 80 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 81 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 82 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 83 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 84 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 85 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 86 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 87 | `pixelbender_eof` | 14.3% | 1/7 | 3 | 7 |  |
| 88 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 89 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 90 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 91 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 92 | `focus_events_mouse_basic` | 11.5% | 30/260 | 244 | 260 |  |
| 93 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 94 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 95 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 96 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 97 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 98 | `pixelbender_vector_output` | 9.1% | 1/11 | 1 | 11 |  |
| 99 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 100 | `pixelbender_sign` | 8.3% | 5/60 | 16 | 60 |  |
| 101 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 102 | `localconnection` | 7.5% | 67/890 | 623 | 890 |  |
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
| 125 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 25 | 49 |  |
| 126 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 127 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 128 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 129 | `matrix3d` | 1.8% | 1/57 | 2 | 57 |  |
| 130 | `all_classes/display3D/swf12` | 1.6% | 1/61 | 18 | 61 |  |
| 131 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 132 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 133 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 134 | `pixelbender_conversions` | 0.4% | 1/270 | 1 | 270 |  |
| 135 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 136 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 137 | `all_classes/events/swf10` | 0.2% | 4/1638 | 165 | 1638 |  |
| 138 | `all_classes/events/swf11` | 0.2% | 4/1750 | 165 | 1750 |  |
| 139 | `all_classes/events/swf12` | 0.2% | 4/1814 | 165 | 1814 |  |
| 140 | `all_classes/display/swf9` | 0.1% | 2/1959 | 258 | 1959 |  |
| 141 | `tab_ordering_arrows` | 0.1% | 1/998 | 7 | 998 |  |
| 142 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 143 | `all_classes/events/swf9` | 0.1% | 1/1030 | 165 | 1030 |  |
| 144 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 145 | `all_classes/display/swf10` | 0.1% | 2/2569 | 258 | 2569 |  |
| 146 | `all_classes/display/swf11` | 0.1% | 2/2593 | 258 | 2593 |  |
| 147 | `all_classes/display/swf12` | 0.1% | 2/2593 | 258 | 2593 |  |
| 148 | `all_classes/display/swf13` | 0.1% | 2/2671 | 258 | 2671 |  |
| 149 | `pixelbender_parameters` | 0.1% | 1/1563 | 1 | 1563 |  |
| 150 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 151 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 152 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 153 | `air_datagram_socket` | 0.0% | 0/1 | 0 | 1 |  |
| 154 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 155 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 156 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 157 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 158 | `all_classes/display/swf30` | 0.0% | 0/2936 | 258 | 2936 |  |
| 159 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 18 | 326 |  |
| 160 | `all_classes/display3D/swf30` | 0.0% | 0/412 | 18 | 412 |  |
| 161 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 162 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 163 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 164 | `all_classes/events/swf30` | 0.0% | 0/2353 | 165 | 2353 |  |
| 165 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 166 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 167 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 168 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 169 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 170 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 171 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 172 | `av_networking_params` | 0.0% | 0/9 | 0 | 9 |  |
| 173 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 174 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 175 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 176 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 177 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 178 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 179 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 180 | `context3d_creation` | 0.0% | 0/9 | 0 | 9 |  |
| 181 | `cpool_index_invalid_bytecode_1` | 0.0% | 0/6 | 6 | 6 |  |
| 182 | `cpool_index_invalid_bytecode_2` | 0.0% | 0/3 | 3 | 3 |  |
| 183 | `cpool_index_invalid_bytecode_3` | 0.0% | 0/1 | 1 | 1 |  |
| 184 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 185 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 186 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 187 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 188 | `edittext_ime_focus_lost` | 0.0% | 0/9 | 8 | 9 |  |
| 189 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 190 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 191 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 192 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 193 | `filefilter_properties` | 0.0% | 0/4 | 1 | 4 |  |
| 194 | `filereference_browse_cancel` | 0.0% | 0/3 | 0 | 3 |  |
| 195 | `filereference_browse_select` | 0.0% | 0/9 | 0 | 9 |  |
| 196 | `filereference_load` | 0.0% | 0/31 | 0 | 31 |  |
| 197 | `filereference_save` | 0.0% | 0/16 | 0 | 16 |  |
| 198 | `filereference_save_and_browse` | 0.0% | 0/42 | 0 | 42 |  |
| 199 | `filereference_save_and_load` | 0.0% | 0/22 | 0 | 22 |  |
| 200 | `filereference_uninitialized` | 0.0% | 0/8 | 0 | 8 |  |
| 201 | `filereferencelist_browse_cancel` | 0.0% | 0/6 | 0 | 6 |  |
| 202 | `filereferencelist_browse_select` | 0.0% | 0/7 | 0 | 7 |  |
| 203 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 204 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 205 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 206 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 207 | `ime_linux_dead_keys` | 0.0% | 0/13 | 13 | 10 |  |
| 208 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 209 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 210 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 211 | `localconnection_send` | 0.0% | 0/4 | 0 | 4 |  |
| 212 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 213 | `matrix3d_invert` | 0.0% | 0/18 | 0 | 18 |  |
| 214 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 215 | `net_stream_play_options` | 0.0% | 0/6 | 0 | 6 |  |
| 216 | `netconnection_close` | 0.0% | 0/55 | 0 | 55 |  |
| 217 | `netconnection_properties` | 0.0% | 0/78 | 0 | 78 |  |
| 218 | `netconnection_send_remote` | 0.0% | 0/50 | 0 | 50 |  |
| 219 | `netconnection_serialize_arrays` | 0.0% | 0/6 | 0 | 6 |  |
| 220 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 221 | `netstream_client` | 0.0% | 0/10 | 0 | 10 |  |
| 222 | `netstream_connect` | 0.0% | 0/7 | 0 | 7 |  |
| 223 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 224 | `netstream_play_stop_replay` | 0.0% | 0/11 | 0 | 11 |  |
| 225 | `netstream_seek_flv` | 0.0% | 0/49 | 2 | 49 |  |
| 226 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 227 | `pixelbender_conditional` | 0.0% | 0/138 | 0 | 138 |  |
| 228 | `pixelbender_dithering` | 0.0% | 0/8 | 0 | 8 |  |
| 229 | `pixelbender_effect_glassDisplace_shaderfilter` | 0.0% | 0/4 | 0 | 4 |  |
| 230 | `pixelbender_logicalnot` | 0.0% | 0/20 | 0 | 20 |  |
| 231 | `pixelbender_malformed_data` | 0.0% | 0/190 | 0 | 190 |  |
| 232 | `pixelbender_multiple_out_params` | 0.0% | 0/1 | 0 | 1 |  |
| 233 | `pixelbender_no_out_param` | 0.0% | 0/6 | 2 | 6 |  |
| 234 | `pixelbender_outputs` | 0.0% | 0/13 | 5 | 13 |  |
| 235 | `pixelbender_padding_bytes` | 0.0% | 0/66 | 66 | 22 |  |
| 236 | `pixelbender_param_qualifier` | 0.0% | 0/512 | 256 | 512 |  |
| 237 | `pixelbender_parameters_bool` | 0.0% | 0/240 | 0 | 240 |  |
| 238 | `pixelbender_parameters_int_vs_bool` | 0.0% | 0/54 | 0 | 54 |  |
| 239 | `pixelbender_parse_errors` | 0.0% | 0/6 | 6 | 6 |  |
| 240 | `pixelbender_select_kinds` | 0.0% | 0/8 | 8 | 8 |  |
| 241 | `pixelbender_shaderdata` | 0.0% | 0/49 | 0 | 49 |  |
| 242 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 243 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 244 | `responder_null_callbacks` | 0.0% | 0/1 | 0 | 1 |  |
| 245 | `sandbox_type_local_network` | 0.0% | 0/1 | 1 | 1 |  |
| 246 | `sandbox_type_remote` | 0.0% | 0/3 | 1 | 3 |  |
| 247 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 248 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 249 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 250 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 251 | `shaderparameter_value` | 0.0% | 0/4 | 0 | 4 |  |
| 252 | `socket_after_disconnect` | 0.0% | 0/1 | 0 | 1 |  |
| 253 | `socket_close` | 0.0% | 0/2 | 0 | 2 |  |
| 254 | `socket_connect` | 0.0% | 0/4 | 0 | 4 |  |
| 255 | `socket_errors` | 0.0% | 0/56 | 0 | 56 |  |
| 256 | `socket_read_big` | 0.0% | 0/48 | 0 | 48 |  |
| 257 | `socket_read_little` | 0.0% | 0/48 | 0 | 48 |  |
| 258 | `socket_read_write_object` | 0.0% | 0/8 | 0 | 8 |  |
| 259 | `socket_write_big` | 0.0% | 0/15 | 0 | 15 |  |
| 260 | `socket_write_little` | 0.0% | 0/14 | 0 | 14 |  |
| 261 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 262 | `stage3d_agal_upload_errors` | 0.0% | 0/66 | 0 | 66 |  |
| 263 | `stage3d_blend` | 0.0% | 0/81 | 0 | 81 |  |
| 264 | `stage3d_context3d_string_args` | 0.0% | 0/158 | 0 | 158 |  |
| 265 | `stage3d_errors` | 0.0% | 0/7 | 0 | 7 |  |
| 266 | `stage3d_errors_atf` | 0.0% | 0/3 | 0 | 3 |  |
| 267 | `stage3d_errors_swf_29` | 0.0% | 0/6 | 0 | 6 |  |
| 268 | `stage3d_multistage_triangle` | 0.0% | 0/3 | 0 | 3 |  |
| 269 | `stage3d_program_constants_invalid_input` | 0.0% | 0/21 | 0 | 21 |  |
| 270 | `stage3d_x_y` | 0.0% | 0/22 | 0 | 22 |  |
| 271 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 272 | `stage_stage3Ds_vector` | 0.0% | 0/1 | 0 | 1 |  |
| 273 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 274 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 275 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 276 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 277 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 278 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 279 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 280 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 281 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 282 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 283 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 284 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 285 | `textfield_event` | 0.0% | 0/66 | 0 | 66 |  |
| 286 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 287 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 288 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 289 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 290 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 291 | `urlstream_basic` | 0.0% | 0/5 | 0 | 5 |  |
| 292 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 293 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 294 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 295 | `verify_jump_to_middle_of_op` | 0.0% | 0/1 | 1 | 1 |  |
| 296 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 297 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
| 298 | `xml_socket` | 0.0% | 0/11 | 0 | 11 |  |
