# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 14:23 UTC

**Git SHA**: `0241861f4a`

**Run Duration**: 173m 2s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1221 |
| Passing | **980** (80.3%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1006** (82.4%) |
| Failing | 215 |
| Total expected lines | 151253 |
| Matching lines | 111912 (74.0%) |
| Mismatched lines | 39341 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 212 | 98.6% |
| Runtime Error | 3 | 1.4% |

## Passing Tests

**980 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 17.4s |  |
| 2 | `agal_compiler` | 13 | 8.3s |  |
| 3 | `air_datagram_socket` | 1 | 6.8s |  |
| 4 | `air_hidden_lookup` | 2 | 6.1s |  |
| 5 | `all_classes/security/swf11` | 3 | 6.1s |  |
| 6 | `amf_array_serialization` | 17 | 7.8s |  |
| 7 | `amf_custom_obj` | 26 | 6.1s |  |
| 8 | `amf_dictionary` | 9 | 6.0s |  |
| 9 | `amf_function` | 46 | 6.0s |  |
| 10 | `amf_invalid_date` | 2 | 6.0s |  |
| 11 | `amf_missing_prop` | 6 | 6.0s |  |
| 12 | `amf_nondynamic_function_prop` | 6 | 6.5s |  |
| 13 | `amf_setter_error` | 8 | 6.7s |  |
| 14 | `amf_vector` | 40 | 6.7s |  |
| 15 | `amf_xml` | 6 | 6.7s |  |
| 16 | `application_domain` | 4 | 6.8s |  |
| 17 | `array_access` | 18 | 6.8s |  |
| 18 | `array_access_interpreter` | 4 | 6.8s |  |
| 19 | `array_access_no_pubns` | 2 | 6.8s |  |
| 20 | `array_concat` | 41 | 6.9s |  |
| 21 | `array_constr` | 10 | 6.8s |  |
| 22 | `array_delete` | 44 | 6.9s |  |
| 23 | `array_enumeration` | 10 | 6.8s |  |
| 24 | `array_enumeration_elements` | 11 | 6.7s |  |
| 25 | `array_every` | 8 | 6.8s |  |
| 26 | `array_filter` | 6 | 6.7s |  |
| 27 | `array_foreach` | 18 | 6.7s |  |
| 28 | `array_hasownproperty` | 11 | 3.3s |  |
| 29 | `array_holes` | 9 | 6.8s |  |
| 30 | `array_index_max` | 84 | 6.7s |  |
| 31 | `array_indexof` | 25 | 6.7s |  |
| 32 | `array_join` | 26 | 6.8s |  |
| 33 | `array_lastindexof` | 29 | 6.8s |  |
| 34 | `array_length` | 14 | 6.7s |  |
| 35 | `array_literal` | 3 | 6.7s |  |
| 36 | `array_map` | 8 | 6.6s |  |
| 37 | `array_pop` | 52 | 6.8s |  |
| 38 | `array_push` | 24 | 6.7s |  |
| 39 | `array_reborrow_bug` | 6 | 6.6s |  |
| 40 | `array_reverse` | 28 | 6.8s |  |
| 41 | `array_shift` | 51 | 3.3s |  |
| 42 | `array_slice` | 39 | 6.8s |  |
| 43 | `array_some` | 8 | 6.6s |  |
| 44 | `array_sort` | 297 | 7.2s |  |
| 45 | `array_sort_fun_swf12` | 2 | 6.6s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 47 | `array_sort_random` | 210 | 6.7s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 6.5s |  |
| 49 | `array_sorton` | 545 | 7.8s |  |
| 50 | `array_sparse_ops` | 41 | 7.0s |  |
| 51 | `array_splice` | 133 | 7.0s |  |
| 52 | `array_splice2` | 428 | 7.0s |  |
| 53 | `array_splice_types` | 48 | 6.7s |  |
| 54 | `array_storage` | 8 | 6.7s |  |
| 55 | `array_tolocalestring` | 9 | 6.7s |  |
| 56 | `array_tostring` | 12 | 6.7s |  |
| 57 | `array_unshift` | 24 | 6.7s |  |
| 58 | `array_valueof` | 9 | 6.6s |  |
| 59 | `array_vector_null_callback` | 10 | 6.6s |  |
| 60 | `astype` | 28 | 6.8s |  |
| 61 | `astypelate` | 24 | 6.9s |  |
| 62 | `astypelate_propagates` | 1 | 6.6s |  |
| 63 | `asymmetric_key_events` | 11 | 6.7s |  |
| 64 | `av_networking_params` | 9 | 7.0s |  |
| 65 | `avm2_catchup_dobj` | 158 | 7.3s |  |
| 66 | `away3d_advanced_shallow_water_demo` | 0 | 81.1s |  |
| 67 | `bitand` | 1058 | 18.5s |  |
| 68 | `bitmap_constr` | 17 | 6.8s |  |
| 69 | `bitmap_data` | 1000 | 14.7s |  |
| 70 | `bitmap_pixelsnapping` | 2 | 25.8s |  |
| 71 | `bitmap_properties` | 23 | 6.6s |  |
| 72 | `bitmap_subclass` | 7 | 8.0s |  |
| 73 | `bitmap_subclass_properties` | 9 | 7.0s |  |
| 74 | `bitmap_timeline` | 9 | 6.6s |  |
| 75 | `bitmapdata_accuracy` | 1 | 42.2s |  |
| 76 | `bitmapdata_applyfilter_blur` | 0 | 26.7s |  |
| 77 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.5s |  |
| 78 | `bitmapdata_applyfilter_destpoint` | 0 | 26.7s |  |
| 79 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 27.5s |  |
| 80 | `bitmapdata_clone` | 13 | 7.0s |  |
| 81 | `bitmapdata_colortransform` | 0 | 7.1s |  |
| 82 | `bitmapdata_colortransform_oob` | 2 | 6.6s |  |
| 83 | `bitmapdata_constr` | 22 | 3.2s |  |
| 84 | `bitmapdata_constructor_from_timeline` | 1 | 6.8s |  |
| 85 | `bitmapdata_copychannel` | 0 | 22.5s |  |
| 86 | `bitmapdata_copypixels` | 23 | 21.4s |  |
| 87 | `bitmapdata_copypixels_blend_over` | 1 | 5.3s |  |
| 88 | `bitmapdata_copypixelstobytearray` | 39 | 5.2s |  |
| 89 | `bitmapdata_dispose` | 7 | 5.3s |  |
| 90 | `bitmapdata_draw` | 0 | 20.8s |  |
| 91 | `bitmapdata_draw_colortransform` | 0 | 5.5s |  |
| 92 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 20.2s |  |
| 93 | `bitmapdata_draw_filters` | 0 | 20.4s |  |
| 94 | `bitmapdata_draw_masks` | 0 | 5.3s |  |
| 95 | `bitmapdata_draw_rotation` | 0 | 5.5s |  |
| 96 | `bitmapdata_draw_self_via_graphic` | 0 | 5.5s |  |
| 97 | `bitmapdata_draw_stage` | 0 | 20.1s |  |
| 98 | `bitmapdata_drawwithquality` | 0 | 5.5s |  |
| 99 | `bitmapdata_embedded` | 9 | 5.5s |  |
| 100 | `bitmapdata_fillrect` | 0 | 5.5s |  |
| 101 | `bitmapdata_filter_sourcerect` | 0 | 20.4s |  |
| 102 | `bitmapdata_floodfill` | 35 | 5.2s |  |
| 103 | `bitmapdata_getpixels` | 39 | 20.1s |  |
| 104 | `bitmapdata_getvector` | 27 | 2.5s |  |
| 105 | `bitmapdata_histogram` | 59 | 2.5s |  |
| 106 | `bitmapdata_hittest` | 112 | 5.7s |  |
| 107 | `bitmapdata_hittest_threshold` | 18 | 5.4s |  |
| 108 | `bitmapdata_opaque` | 0 | 5.5s |  |
| 109 | `bitmapdata_pixeldissolve` | 1037 | 5.7s |  |
| 110 | `bitmapdata_pixeldissolve_image` | 0 | 5.5s |  |
| 111 | `bitmapdata_rectangle_rounding` | 16 | 5.1s |  |
| 112 | `bitmapdata_setpixels` | 286 | 5.3s |  |
| 113 | `bitmapdata_setvector` | 26 | 5.2s |  |
| 114 | `bitmapdata_sync` | 0 | 20.4s |  |
| 115 | `bitmapdata_threshold` | 176 | 5.9s |  |
| 116 | `bitnot` | 46 | 5.3s |  |
| 117 | `bitor` | 1058 | 14.0s |  |
| 118 | `bitxor` | 1058 | 14.0s |  |
| 119 | `blend_multiply_alpha` | 0 | 5.4s |  |
| 120 | `blend_scroll` | 0 | 5.4s |  |
| 121 | `blend_shader_luma_lighten` | 3 | 5.8s |  |
| 122 | `boolean_constr` | 32 | 6.8s |  |
| 123 | `boolean_negation` | 30 | 6.8s |  |
| 124 | `boolean_tostring` | 8 | 6.7s |  |
| 125 | `broadcast_event` | 7 | 6.9s |  |
| 126 | `button_nested_frame` | 48 | 26.0s |  |
| 127 | `bytearray` | 48 | 7.0s |  |
| 128 | `bytearray_compress` | 31 | 6.8s |  |
| 129 | `bytearray_errors` | 24 | 6.9s |  |
| 130 | `bytearray_method_serialization` | 1 | 6.7s |  |
| 131 | `bytearray_oom` | 3 | 6.7s |  |
| 132 | `bytearray_readobject_amf0` | 50 | 6.8s |  |
| 133 | `bytearray_readobject_amf3` | 53 | 6.8s |  |
| 134 | `bytearray_readutf8bytes_with_bom` | 16 | 6.8s |  |
| 135 | `bytearray_serialization` | 3 | 6.8s |  |
| 136 | `bytearray_string_null` | 19 | 7.0s |  |
| 137 | `bytearray_tostring` | 15 | 6.8s |  |
| 138 | `bytearray_utf16` | 8 | 6.7s |  |
| 139 | `bytearray_writeobject` | 24 | 6.6s |  |
| 140 | `callee_in_initializer` | 6 | 6.7s |  |
| 141 | `callproplex_class` | 1 | 6.7s |  |
| 142 | `capabilities_resolution` | 8 | 26.7s |  |
| 143 | `catch_class` | 6 | 6.8s |  |
| 144 | `catch_scope_slot` | 7 | 3.3s |  |
| 145 | `checkfilter` | 4 | 3.2s |  |
| 146 | `class_call` | 32 | 6.8s |  |
| 147 | `class_cast_call` | 14 | 6.8s |  |
| 148 | `class_enumeration` | 4 | 6.8s |  |
| 149 | `class_has_own_property` | 2 | 6.8s |  |
| 150 | `class_init_interpreter_mode` | 1 | 6.7s |  |
| 151 | `class_is` | 32 | 6.8s |  |
| 152 | `class_methods` | 5 | 6.8s |  |
| 153 | `class_object_properties` | 10 | 6.8s |  |
| 154 | `class_singleton` | 18 | 6.8s |  |
| 155 | `class_supercalls_errors` | 35 | 7.0s |  |
| 156 | `class_supercalls_mismatched` | 26 | 6.8s |  |
| 157 | `class_superclass_wrong_order` | 1 | 26.1s |  |
| 158 | `class_to_locale_string` | 2 | 6.8s |  |
| 159 | `class_to_string` | 2 | 6.8s |  |
| 160 | `class_value_of` | 2 | 6.8s |  |
| 161 | `click_block` | 5 | 7.8s |  |
| 162 | `click_invisible` | 3 | 6.9s |  |
| 163 | `closures` | 12 | 6.9s |  |
| 164 | `coerce_return_type` | 40 | 6.9s |  |
| 165 | `coerce_return_type_fail` | 2 | 6.7s |  |
| 166 | `coerce_return_void` | 3 | 6.7s |  |
| 167 | `coerce_string` | 86 | 7.0s |  |
| 168 | `coerce_string_precision` | 28 | 6.8s |  |
| 169 | `coerce_to_primitive_side_effects` | 29 | 6.8s |  |
| 170 | `construct_errors_swf10` | 8 | 6.8s |  |
| 171 | `construct_frame_list` | 22 | 26.6s |  |
| 172 | `construct_interface` | 3 | 6.9s |  |
| 173 | `constructor_call` | 3 | 6.9s |  |
| 174 | `constructors_vs_timeline` | 5 | 27.1s |  |
| 175 | `constructprop_dynamic_primitive` | 7 | 7.0s |  |
| 176 | `context3d_creation` | 9 | 7.1s |  |
| 177 | `control_flow_bool` | 4 | 7.0s |  |
| 178 | `control_flow_stricteq` | 8 | 7.0s |  |
| 179 | `convert_boolean` | 30 | 6.9s |  |
| 180 | `convert_integer` | 90 | 7.0s |  |
| 181 | `convert_number` | 56 | 6.9s |  |
| 182 | `convert_uinteger` | 90 | 7.0s |  |
| 183 | `cpool_index_invalid_bytecode_1` | 6 | 6.9s |  |
| 184 | `cpool_index_invalid_bytecode_2` | 3 | 6.8s |  |
| 185 | `cpool_index_invalid_bytecode_3` | 1 | 6.8s |  |
| 186 | `cross_api_version_call_older` | 12 | 7.4s |  |
| 187 | `cryptscore` | 11 | 7.1s |  |
| 188 | `date` | 30 | 7.0s |  |
| 189 | `date_parse` | 36 | 6.5s |  |
| 190 | `declocal` | 46 | 6.5s |  |
| 191 | `declocal_i` | 46 | 6.5s |  |
| 192 | `decode_uri` | 71 | 6.9s |  |
| 193 | `decrement` | 46 | 6.5s |  |
| 194 | `decrement_i` | 46 | 3.1s |  |
| 195 | `default_values` | 7 | 6.5s |  |
| 196 | `dictionary_access` | 62 | 7.0s |  |
| 197 | `dictionary_access_no_pubns` | 2 | 6.8s |  |
| 198 | `dictionary_delete` | 101 | 7.5s |  |
| 199 | `dictionary_foreach` | 42 | 7.0s |  |
| 200 | `dictionary_hasownproperty` | 63 | 7.1s |  |
| 201 | `dictionary_in` | 62 | 7.0s |  |
| 202 | `dictionary_iter_modify` | 8 | 6.8s |  |
| 203 | `dictionary_namespaces` | 36 | 6.8s |  |
| 204 | `dictionary_primitive_keys` | 29 | 6.8s |  |
| 205 | `displayobject_alpha` | 277 | 6.6s |  |
| 206 | `displayobject_blendmode` | 0 | 6.8s |  |
| 207 | `displayobject_colortransform_nested` | 0 | 25.6s |  |
| 208 | `displayobject_from_enterframe` | 1 | 25.4s |  |
| 209 | `displayobject_getbounds_shape` | 0 | 25.4s |  |
| 210 | `displayobject_height` | 6052 | 25.8s |  |
| 211 | `displayobject_hittestobject` | 32 | 6.6s |  |
| 212 | `displayobject_invalid_floats` | 60 | 6.6s |  |
| 213 | `displayobject_invalid_props` | 3 | 3.0s |  |
| 214 | `displayobject_mask` | 3 | 7.1s |  |
| 215 | `displayobject_mask_self_referential` | 0 | 6.4s |  |
| 216 | `displayobject_metaData` | 3 | 6.2s |  |
| 217 | `displayobject_name` | 22 | 6.7s |  |
| 218 | `displayobject_name_from_timeline` | 24 | 6.6s |  |
| 219 | `displayobject_parent` | 12 | 6.3s |  |
| 220 | `displayobject_root` | 24 | 6.4s |  |
| 221 | `displayobject_rotation` | 1284 | 6.5s |  |
| 222 | `displayobject_set_matrix_nested` | 0 | 24.9s |  |
| 223 | `displayobject_set_name_loaded` | 3 | 6.7s |  |
| 224 | `displayobject_subclass` | 2 | 6.4s |  |
| 225 | `displayobject_visible` | 23 | 6.4s |  |
| 226 | `displayobject_width` | 4852 | 24.9s |  |
| 227 | `displayobject_x` | 614 | 6.4s |  |
| 228 | `displayobject_y` | 617 | 6.4s |  |
| 229 | `displayobjectcontainer_addchild` | 32 | 6.5s |  |
| 230 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.3s |  |
| 231 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.6s |  |
| 232 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.5s |  |
| 233 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.5s |  |
| 234 | `displayobjectcontainer_addchildat` | 42 | 6.4s |  |
| 235 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.1s |  |
| 236 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.4s |  |
| 237 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.4s |  |
| 238 | `displayobjectcontainer_contains` | 66 | 24.6s |  |
| 239 | `displayobjectcontainer_getchildat` | 4 | 6.5s |  |
| 240 | `displayobjectcontainer_getchildbyname` | 9 | 6.3s |  |
| 241 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.3s |  |
| 242 | `displayobjectcontainer_getchildindex` | 28 | 6.3s |  |
| 243 | `displayobjectcontainer_removechild` | 10 | 6.3s |  |
| 244 | `displayobjectcontainer_removechild_errors` | 4 | 6.3s |  |
| 245 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.4s |  |
| 246 | `displayobjectcontainer_removechildat` | 18 | 6.3s |  |
| 247 | `displayobjectcontainer_removechildren` | 51 | 6.6s |  |
| 248 | `displayobjectcontainer_setchildindex` | 42 | 6.2s |  |
| 249 | `displayobjectcontainer_stopallmovieclips` | 2 | 6.7s |  |
| 250 | `displayobjectcontainer_swapchildren` | 42 | 6.4s |  |
| 251 | `displayobjectcontainer_swapchildrenat` | 42 | 6.4s |  |
| 252 | `displayobjectcontainer_timelineinstance` | 48 | 25.8s |  |
| 253 | `divide` | 1058 | 18.1s |  |
| 254 | `doabc_is_eager` | 1 | 25.3s |  |
| 255 | `documentclass` | 9 | 6.9s |  |
| 256 | `domain_memory` | 133 | 7.8s |  |
| 257 | `drag_drop` | 10 | 7.0s |  |
| 258 | `duplicate_defs` | 1 | 6.6s |  |
| 259 | `eager_init` | 1 | 6.7s |  |
| 260 | `edit_text_linkage` | 7 | 6.9s |  |
| 261 | `edittext_align` | 60 | 7.1s |  |
| 262 | `edittext_always_show_selection` | 0 | 26.1s |  |
| 263 | `edittext_antialiastype` | 296 | 7.0s |  |
| 264 | `edittext_at_point_methods_basic` | 16 | 8.1s |  |
| 265 | `edittext_autosize` | 39 | 7.1s |  |
| 266 | `edittext_autosize_align` | 0 | 26.3s |  |
| 267 | `edittext_autosize_height_dynamic` | 60 | 26.1s |  |
| 268 | `edittext_autosize_height_input` | 60 | 6.9s |  |
| 269 | `edittext_autosize_lazy_bounds_events` | 65 | 7.0s |  |
| 270 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.8s |  |
| 271 | `edittext_autosize_lazy_bounds_props` | 490 | 8.2s |  |
| 272 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.9s |  |
| 273 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.0s |  |
| 274 | `edittext_bottom_scroll_v_basic` | 210 | 6.9s |  |
| 275 | `edittext_bounds_scale` | 24 | 25.5s |  |
| 276 | `edittext_bullet` | 30 | 6.8s |  |
| 277 | `edittext_default_format` | 221 | 7.0s |  |
| 278 | `edittext_default_format_empty` | 136 | 7.0s |  |
| 279 | `edittext_empty_text_format` | 7 | 6.8s |  |
| 280 | `edittext_focus_selection` | 5 | 6.7s |  |
| 281 | `edittext_font_size` | 45 | 6.8s |  |
| 282 | `edittext_format_empty_font` | 8 | 6.8s |  |
| 283 | `edittext_get_char_index_at_point` | 4 | 26.9s |  |
| 284 | `edittext_get_line_index_at_point` | 2 | 26.1s |  |
| 285 | `edittext_get_line_index_of_char` | 76 | 7.6s |  |
| 286 | `edittext_getcharboundaries` | 172 | 7.2s |  |
| 287 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.9s |  |
| 288 | `edittext_getcharboundaries_scroll` | 85 | 7.3s |  |
| 289 | `edittext_getlinemetrics` | 146 | 6.8s |  |
| 290 | `edittext_html` | 3101 | 7.2s |  |
| 291 | `edittext_html_condensewhite` | 487 | 6.8s |  |
| 292 | `edittext_html_entity` | 4 | 6.9s |  |
| 293 | `edittext_html_font_size_swf12` | 267 | 6.8s |  |
| 294 | `edittext_html_font_size_swf13` | 273 | 6.5s |  |
| 295 | `edittext_html_roundtrip` | 17 | 6.7s |  |
| 296 | `edittext_ime_focus_lost` | 9 | 26.9s |  |
| 297 | `edittext_input_control` | 12 | 7.2s |  |
| 298 | `edittext_leading` | 9 | 7.1s |  |
| 299 | `edittext_letter_spacing` | 15 | 6.7s |  |
| 300 | `edittext_line_methods` | 294 | 8.3s |  |
| 301 | `edittext_line_metrics` | 11 | 29.8s |  |
| 302 | `edittext_margins` | 25 | 7.4s |  |
| 303 | `edittext_max_scroll_h_basic` | 475 | 7.5s |  |
| 304 | `edittext_max_scroll_v_basic` | 1000 | 7.2s |  |
| 305 | `edittext_mouse_selection` | 363 | 29.1s |  |
| 306 | `edittext_mousedown` | 3 | 7.3s |  |
| 307 | `edittext_mouseenabled` | 26 | 6.9s |  |
| 308 | `edittext_newline_character` | 22 | 6.8s |  |
| 309 | `edittext_newline_stripping` | 64 | 9.5s |  |
| 310 | `edittext_newlines` | 30 | 6.9s |  |
| 311 | `edittext_paragraph_methods` | 257 | 6.9s |  |
| 312 | `edittext_paste_events` | 8 | 6.8s |  |
| 313 | `edittext_paste_maxchars` | 4 | 6.7s |  |
| 314 | `edittext_paste_restrict` | 16 | 6.6s |  |
| 315 | `edittext_restrict` | 191 | 6.7s |  |
| 316 | `edittext_restrict_events` | 22 | 7.0s |  |
| 317 | `edittext_scrollh` | 10 | 3.5s |  |
| 318 | `edittext_selected_text` | 9 | 6.7s |  |
| 319 | `edittext_set_html_same` | 17 | 6.7s |  |
| 320 | `edittext_set_text_vs_html` | 9 | 6.7s |  |
| 321 | `edittext_stylesheet` | 536 | 7.1s |  |
| 322 | `edittext_stylesheet_custom_tag` | 76 | 6.9s |  |
| 323 | `edittext_stylesheet_display` | 272 | 7.0s |  |
| 324 | `edittext_underline` | 40 | 6.8s |  |
| 325 | `edittext_width_height` | 103 | 7.3s |  |
| 326 | `edittext_wordwrap_word` | 150 | 5.6s |  |
| 327 | `edittext_wrap_breaks` | 2375 | 5.7s |  |
| 328 | `empty_bounds` | 1 | 5.3s |  |
| 329 | `encode_uri_surrogate_pair_swf11` | 15 | 5.4s |  |
| 330 | `equals` | 512 | 7.8s |  |
| 331 | `error_geterrormessage` | 779 | 5.5s |  |
| 332 | `error_prototype` | 15 | 5.6s |  |
| 333 | `error_stack_trace_debug_swf17` | 0 | 21.4s |  |
| 334 | `error_stack_trace_debug_swf18` | 0 | 5.2s |  |
| 335 | `error_stack_trace_release_swf17` | 0 | 5.1s |  |
| 336 | `error_stack_trace_release_swf18` | 0 | 5.0s |  |
| 337 | `error_tostring` | 29 | 5.2s |  |
| 338 | `es3_inheritance` | 31 | 5.4s |  |
| 339 | `es4_inheritance` | 30 | 5.4s |  |
| 340 | `es4_interfaces` | 30 | 5.3s |  |
| 341 | `es4_method_binding` | 8 | 2.3s |  |
| 342 | `es4_oop_prototypes` | 14 | 5.5s |  |
| 343 | `es4_protected_inheritance` | 6 | 5.2s |  |
| 344 | `escape` | 71 | 5.3s |  |
| 345 | `event_bubbles` | 2 | 5.3s |  |
| 346 | `event_cancelable` | 2 | 5.4s |  |
| 347 | `event_clone` | 20 | 5.5s |  |
| 348 | `event_clone_error_redispatch` | 3 | 5.8s |  |
| 349 | `event_clone_on_redispatch` | 10 | 5.5s |  |
| 350 | `event_formattostring` | 31 | 5.3s |  |
| 351 | `event_isdefaultprevented` | 12 | 5.3s |  |
| 352 | `event_target_getter` | 5 | 2.3s |  |
| 353 | `event_target_set` | 9 | 5.2s |  |
| 354 | `event_type` | 1 | 6.6s |  |
| 355 | `event_valueof_tostring` | 18 | 5.1s |  |
| 356 | `eventdispatcher_dispatchevent` | 12 | 5.1s |  |
| 357 | `eventdispatcher_dispatchevent_cancel` | 20 | 5.1s |  |
| 358 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 5.1s |  |
| 359 | `eventdispatcher_dispatchevent_indirect` | 9 | 5.2s |  |
| 360 | `eventdispatcher_dispatchevent_this` | 5 | 5.1s |  |
| 361 | `eventdispatcher_haseventlistener` | 25 | 5.2s |  |
| 362 | `eventdispatcher_interface_invoke` | 1 | 5.0s |  |
| 363 | `eventdispatcher_tostring` | 10 | 5.1s |  |
| 364 | `eventdispatcher_willtrigger` | 25 | 5.0s |  |
| 365 | `falsiness` | 30 | 5.1s |  |
| 366 | `fast_index_access` | 12 | 5.2s |  |
| 367 | `filefilter_properties` | 4 | 5.1s |  |
| 368 | `filereference_browse_cancel` | 3 | 5.1s |  |
| 369 | `filereference_browse_select` | 9 | 5.1s |  |
| 370 | `filereference_load` | 31 | 2.3s |  |
| 371 | `filereference_save` | 16 | 5.1s |  |
| 372 | `filereference_save_and_browse` | 42 | 5.2s |  |
| 373 | `filereference_save_and_load` | 22 | 5.4s |  |
| 374 | `filereference_uninitialized` | 8 | 5.1s |  |
| 375 | `filereferencelist_browse_cancel` | 6 | 2.2s |  |
| 376 | `filereferencelist_browse_select` | 7 | 5.2s |  |
| 377 | `finddef` | 3 | 5.1s |  |
| 378 | `findprop_global_prototype` | 6 | 5.1s |  |
| 379 | `flash_xml` | 29 | 5.1s |  |
| 380 | `flash_xml_cloneNode` | 22 | 5.1s |  |
| 381 | `flash_xml_namespace` | 109 | 5.1s |  |
| 382 | `flash_xml_removeNode` | 60 | 5.1s |  |
| 383 | `focus_events_code` | 161 | 21.0s |  |
| 384 | `focus_events_key_basic` | 132 | 21.1s |  |
| 385 | `focus_events_key_navigation` | 53 | 5.2s |  |
| 386 | `focus_events_key_same_object` | 26 | 5.1s |  |
| 387 | `focus_events_mixed_key_mouse` | 100 | 20.9s |  |
| 388 | `focus_events_mouse_basic` | 260 | 27.1s |  |
| 389 | `focus_events_mouse_focusable` | 112 | 25.6s |  |
| 390 | `focus_events_mouse_same_object` | 40 | 25.1s |  |
| 391 | `focus_remove` | 20 | 25.0s |  |
| 392 | `focus_root_movie` | 4 | 25.2s |  |
| 393 | `focus_stage` | 1 | 6.5s |  |
| 394 | `focusrect` | 18 | 7.2s |  |
| 395 | `focusrect_focuslost` | 9 | 6.5s |  |
| 396 | `focusrect_property` | 110 | 6.5s |  |
| 397 | `font_description_clone` | 14 | 6.5s |  |
| 398 | `font_embedded` | 24 | 6.8s |  |
| 399 | `font_enumeratefonts` | 41 | 7.1s |  |
| 400 | `font_enumeratefonts_filter` | 4 | 25.6s |  |
| 401 | `font_hasglyphs` | 40 | 7.0s |  |
| 402 | `framelabel_constr` | 5 | 6.4s |  |
| 403 | `function_call` | 12 | 6.5s |  |
| 404 | `function_call_arguments` | 46 | 6.5s |  |
| 405 | `function_call_arguments_enumerate` | 5 | 6.5s |  |
| 406 | `function_call_coercion` | 108 | 6.8s |  |
| 407 | `function_call_default` | 6 | 6.4s |  |
| 408 | `function_call_rest` | 22 | 6.5s |  |
| 409 | `function_call_types` | 3 | 6.5s |  |
| 410 | `function_call_via_apply` | 11 | 6.5s |  |
| 411 | `function_call_via_call` | 3 | 6.4s |  |
| 412 | `function_display_anonymous` | 7 | 3.0s |  |
| 413 | `function_length` | 6 | 6.4s |  |
| 414 | `function_object` | 2 | 6.4s |  |
| 415 | `function_proto` | 5 | 6.4s |  |
| 416 | `function_proto_created` | 61 | 6.5s |  |
| 417 | `function_to_locale_string` | 4 | 6.4s |  |
| 418 | `function_to_string` | 4 | 6.4s |  |
| 419 | `function_type` | 6 | 6.4s |  |
| 420 | `function_unbound_this` | 51 | 6.5s |  |
| 421 | `function_value_of` | 4 | 6.4s |  |
| 422 | `get_definition_by_name` | 11 | 6.5s |  |
| 423 | `get_qualified_class_name` | 20 | 8.8s |  |
| 424 | `get_qualified_super_class_name` | 18 | 6.8s |  |
| 425 | `get_slot_edge_cases` | 1 | 26.2s |  |
| 426 | `get_timer` | 2 | 6.7s |  |
| 427 | `getglobalslot` | 1 | 6.7s |  |
| 428 | `getouterscope` | 8 | 6.7s |  |
| 429 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 430 | `goto_button_nested_framescript` | 28 | 26.9s |  |
| 431 | `goto_in_constructframe` | 12 | 7.0s |  |
| 432 | `goto_in_scene_last_frame` | 2 | 26.6s |  |
| 433 | `goto_methods` | 56 | 7.0s |  |
| 434 | `goto_methods_swfver10` | 8 | 6.8s |  |
| 435 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 436 | `goto_nested_framescript` | 9 | 6.9s |  |
| 437 | `goto_on_orphan` | 15 | 7.0s |  |
| 438 | `graphics_bad_direct_commands` | 5 | 7.6s |  |
| 439 | `graphics_bitmap_fill` | 0 | 8.7s |  |
| 440 | `graphics_bitmaps` | 0 | 7.5s |  |
| 441 | `graphics_direct_commands` | 0 | 7.5s |  |
| 442 | `graphics_draw_triangles` | 98 | 27.5s |  |
| 443 | `graphics_gradients` | 0 | 7.2s |  |
| 444 | `graphics_gradients_nulls` | 0 | 7.0s |  |
| 445 | `graphics_path` | 56 | 6.9s |  |
| 446 | `graphics_round_rects` | 0 | 6.8s |  |
| 447 | `graphics_simple_shapes` | 0 | 7.1s |  |
| 448 | `greaterequals` | 512 | 11.1s |  |
| 449 | `greaterthan` | 512 | 11.2s |  |
| 450 | `has_own_property` | 102 | 7.3s |  |
| 451 | `hasownproperty_namespaces` | 2 | 6.8s |  |
| 452 | `hello_world` | 1 | 6.8s |  |
| 453 | `hittest_morph` | 30 | 7.0s |  |
| 454 | `if_eq` | 10 | 6.9s |  |
| 455 | `if_gt` | 1 | 6.9s |  |
| 456 | `if_gte` | 10 | 8.4s |  |
| 457 | `if_lt` | 1 | 6.5s |  |
| 458 | `if_lte` | 10 | 6.4s |  |
| 459 | `if_ne` | 7 | 3.1s |  |
| 460 | `if_stricteq` | 6 | 6.5s |  |
| 461 | `if_strictne` | 11 | 6.5s |  |
| 462 | `ime_linux_dead_keys` | 10 | 6.6s |  |
| 463 | `in` | 102 | 7.0s |  |
| 464 | `inclocal` | 46 | 6.5s |  |
| 465 | `inclocal_i` | 46 | 6.5s |  |
| 466 | `increment` | 46 | 6.5s |  |
| 467 | `increment_i` | 46 | 6.6s |  |
| 468 | `indexing_delete` | 75 | 6.5s |  |
| 469 | `instanceof` | 58 | 6.8s |  |
| 470 | `instantiation_on_enter_frame` | 7 | 25.2s |  |
| 471 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.5s |  |
| 472 | `int_constr` | 92 | 6.4s |  |
| 473 | `int_edge_cases` | 19 | 6.5s |  |
| 474 | `int_instanceof` | 3 | 6.4s |  |
| 475 | `int_tofixed` | 1215 | 6.4s |  |
| 476 | `int_tostring` | 3375 | 6.4s |  |
| 477 | `interactiveobject_enabled` | 25 | 6.4s |  |
| 478 | `interface_namespaces` | 78 | 6.7s |  |
| 479 | `is_finite` | 46 | 6.6s |  |
| 480 | `is_nan` | 46 | 6.4s |  |
| 481 | `is_prototype_of` | 12 | 6.5s |  |
| 482 | `issue_10221` | 2 | 6.5s |  |
| 483 | `issue_13780` | 12 | 6.5s |  |
| 484 | `issue_14901` | 1 | 6.4s |  |
| 485 | `issue_17675_edittext_paste_maxchars` | 1 | 6.5s |  |
| 486 | `issue_5292` | 5 | 6.5s |  |
| 487 | `issue_8630` | 2 | 24.9s |  |
| 488 | `issue_8630_scriptremove` | 11 | 6.5s |  |
| 489 | `istype` | 24 | 3.1s |  |
| 490 | `istypelate` | 58 | 6.7s |  |
| 491 | `istypelate_coerce` | 198 | 9.8s |  |
| 492 | `jpeg_loader_context` | 6 | 6.7s |  |
| 493 | `json_errors` | 9 | 26.2s |  |
| 494 | `json_parse` | 21 | 6.7s |  |
| 495 | `json_stringify` | 12 | 7.0s |  |
| 496 | `json_stringify_order` | 1 | 6.8s |  |
| 497 | `json_version_gated` | 1 | 6.7s |  |
| 498 | `key_input_80percent` | 1812 | 7.0s |  |
| 499 | `key_input_location` | 126 | 6.7s |  |
| 500 | `key_input_numpad` | 384 | 6.6s |  |
| 501 | `lazyinit` | 17 | 6.8s |  |
| 502 | `lessequals` | 512 | 11.0s |  |
| 503 | `lessthan` | 512 | 10.9s |  |
| 504 | `loader_bitmap_transparency` | 14 | 6.8s |  |
| 505 | `loader_bytes_unknown_content` | 14 | 6.9s |  |
| 506 | `loader_child_getdefinition` | 5 | 7.1s |  |
| 507 | `loader_duplicate_coerce` | 3 | 7.0s |  |
| 508 | `loader_duplicate_coerce_new_domain` | 4 | 6.9s |  |
| 509 | `loader_error_in_root_ctor` | 4 | 6.9s |  |
| 510 | `loader_events` | 92 | 7.5s |  |
| 511 | `loader_image` | 8 | 7.1s |  |
| 512 | `loader_jpegxr` | 2 | 26.7s |  |
| 513 | `loader_jpegxr_alpha` | 1 | 26.4s |  |
| 514 | `loader_loadbytes_events` | 30 | 7.5s |  |
| 515 | `loader_loadbytes_invalid_png` | 4 | 26.3s |  |
| 516 | `loader_loadbytes_url` | 12 | 7.1s |  |
| 517 | `loader_loaderurl` | 6 | 7.2s |  |
| 518 | `loader_noninteractive_try_click_root` | 5 | 27.1s |  |
| 519 | `loader_reuse` | 38 | 7.0s |  |
| 520 | `loader_unknown_content` | 24 | 6.9s |  |
| 521 | `loader_visibility_interactive` | 1 | 6.8s |  |
| 522 | `loaderinfo_events` | 7 | 6.6s |  |
| 523 | `loaderinfo_loadurl` | 12 | 6.8s |  |
| 524 | `loaderinfo_more` | 6 | 5.9s |  |
| 525 | `loaderinfo_properties` | 18 | 5.4s |  |
| 526 | `loaderinfo_properties_not_loaded` | 23 | 5.4s |  |
| 527 | `loaderinfo_root` | 10 | 5.3s |  |
| 528 | `loaderinfo_root_allows` | 2 | 5.7s |  |
| 529 | `localconnection_send` | 4 | 5.2s |  |
| 530 | `lshift` | 1058 | 14.3s |  |
| 531 | `mask_reapply` | 1 | 5.3s |  |
| 532 | `math` | 497 | 5.5s |  |
| 533 | `matrix3d_invert` | 18 | 2.5s |  |
| 534 | `missing_external_interface` | 10 | 5.4s |  |
| 535 | `modulo` | 1058 | 14.3s |  |
| 536 | `morph_shape` | 2 | 20.1s |  |
| 537 | `mouse_children` | 192 | 20.8s |  |
| 538 | `mouse_click_events` | 90 | 20.6s |  |
| 539 | `mouse_double_click_events` | 188 | 5.4s |  |
| 540 | `mouse_empty_parent` | 4 | 5.5s |  |
| 541 | `mouse_over_while_dragging` | 3 | 5.6s |  |
| 542 | `mouse_pick_button_mode` | 2 | 5.5s |  |
| 543 | `mouse_pick_dobj_mask` | 4 | 5.7s |  |
| 544 | `mouse_pick_masking` | 7 | 20.6s |  |
| 545 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 20.8s |  |
| 546 | `mouse_pick_non_interactive_dobj_mask` | 3 | 5.7s |  |
| 547 | `mouse_pick_text` | 8 | 5.6s |  |
| 548 | `mouse_sibling` | 8 | 5.4s |  |
| 549 | `mouse_wheel_events` | 36 | 21.9s |  |
| 550 | `mouseevent_constr` | 66 | 5.4s |  |
| 551 | `mouseevent_stagexy` | 35 | 5.4s |  |
| 552 | `mouseevent_valueof_tostring` | 28 | 5.4s |  |
| 553 | `movieclip_addframescript` | 3 | 20.4s |  |
| 554 | `movieclip_child_property` | 16 | 5.7s |  |
| 555 | `movieclip_constr` | 21 | 8.2s |  |
| 556 | `movieclip_currentlabels` | 17 | 24.7s |  |
| 557 | `movieclip_currentlabels_dupes1` | 46 | 24.7s |  |
| 558 | `movieclip_currentlabels_dupes2` | 30 | 6.4s |  |
| 559 | `movieclip_currentlabels_dupes3` | 67 | 6.4s |  |
| 560 | `movieclip_currentscene` | 12 | 6.4s |  |
| 561 | `movieclip_dispatchevent` | 430 | 6.5s |  |
| 562 | `movieclip_dispatchevent_cancel` | 102 | 6.5s |  |
| 563 | `movieclip_dispatchevent_handlerorder` | 251 | 6.5s |  |
| 564 | `movieclip_dispatchevent_selfadd` | 80 | 6.4s |  |
| 565 | `movieclip_dispatchevent_target` | 899 | 6.5s |  |
| 566 | `movieclip_displayevents` | 96 | 24.8s |  |
| 567 | `movieclip_displayevents_clickgoto` | 676 | 6.9s |  |
| 568 | `movieclip_displayevents_clickgoto2` | 2001 | 7.0s |  |
| 569 | `movieclip_displayevents_clickplay` | 575 | 6.6s |  |
| 570 | `movieclip_displayevents_clicksymbol` | 562 | 6.6s |  |
| 571 | `movieclip_displayevents_constructframegoto` | 140 | 6.8s |  |
| 572 | `movieclip_displayevents_constructframeplay` | 50 | 6.7s |  |
| 573 | `movieclip_displayevents_constructframesymbol` | 144 | 6.6s |  |
| 574 | `movieclip_displayevents_dblhandler` | 21 | 6.6s |  |
| 575 | `movieclip_displayevents_enterframegoto` | 149 | 6.7s |  |
| 576 | `movieclip_displayevents_enterframeplay` | 48 | 6.5s |  |
| 577 | `movieclip_displayevents_enterframesymbol` | 149 | 24.8s |  |
| 578 | `movieclip_displayevents_exitframegoto` | 106 | 6.5s |  |
| 579 | `movieclip_displayevents_exitframeplay` | 44 | 6.5s |  |
| 580 | `movieclip_displayevents_exitframesymbol` | 135 | 6.5s |  |
| 581 | `movieclip_displayevents_looping` | 63 | 24.9s |  |
| 582 | `movieclip_displayevents_stopped` | 113 | 6.8s |  |
| 583 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 584 | `movieclip_displayevents_timeline` | 128 | 24.9s |  |
| 585 | `movieclip_drawrect` | 54 | 6.4s |  |
| 586 | `movieclip_frameconstruct_skipped` | 9 | 6.4s |  |
| 587 | `movieclip_goto_during_frame_script` | 15 | 6.5s |  |
| 588 | `movieclip_goto_overwrite` | 14 | 24.7s |  |
| 589 | `movieclip_goto_scene_last_frame_int` | 1 | 24.6s |  |
| 590 | `movieclip_goto_scene_last_frame_label` | 1 | 2.9s |  |
| 591 | `movieclip_gotoandplay` | 15 | 24.4s |  |
| 592 | `movieclip_gotoandstop` | 13 | 24.5s |  |
| 593 | `movieclip_gotoandstop_children` | 4 | 6.5s |  |
| 594 | `movieclip_gotoandstop_framescripts1` | 4 | 6.4s |  |
| 595 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 596 | `movieclip_gotoandstop_framescripts_self` | 7 | 22.0s |  |
| 597 | `movieclip_gotoandstop_queueing` | 12 | 20.1s |  |
| 598 | `movieclip_next_frame` | 2 | 5.1s |  |
| 599 | `movieclip_next_scene` | 6 | 19.9s |  |
| 600 | `movieclip_play` | 3 | 2.4s |  |
| 601 | `movieclip_prev_frame` | 3 | 5.1s |  |
| 602 | `movieclip_prev_scene` | 7 | 5.3s |  |
| 603 | `movieclip_properties` | 79 | 5.5s |  |
| 604 | `movieclip_queued_noop_goto_swf10` | 9 | 5.3s |  |
| 605 | `movieclip_queued_noop_goto_swf9` | 7 | 1.1s |  |
| 606 | `movieclip_scenes` | 11 | 5.5s |  |
| 607 | `movieclip_soundtransform` | 831 | 23.3s |  |
| 608 | `movieclip_stop` | 1 | 5.3s |  |
| 609 | `movieclip_super_is_symbol` | 20 | 5.8s |  |
| 610 | `movieclip_symbol_constr` | 8 | 5.6s |  |
| 611 | `movieclip_text_mousedown` | 1 | 5.4s |  |
| 612 | `movieclip_willtrigger` | 5 | 5.4s |  |
| 613 | `multiply` | 1058 | 14.2s |  |
| 614 | `namespace_constr` | 253 | 5.5s |  |
| 615 | `namespace_constr_args` | 1 | 5.2s |  |
| 616 | `namespace_enumeration_order` | 7 | 5.3s |  |
| 617 | `nan_scale` | 9 | 5.3s |  |
| 618 | `navigateToURL_target_normalize` | 107 | 21.7s |  |
| 619 | `negate` | 30 | 5.4s |  |
| 620 | `negative_volume_panned` | 0 | 5.7s |  |
| 621 | `nested_iteration` | 11 | 5.3s |  |
| 622 | `net_getClassByAlias` | 3 | 5.4s |  |
| 623 | `net_navigateToURL` | 57 | 5.6s |  |
| 624 | `net_stream_play_options` | 6 | 5.4s |  |
| 625 | `netconnection_close` | 55 | 5.4s |  |
| 626 | `netconnection_properties` | 78 | 5.4s |  |
| 627 | `netconnection_send_remote` | 50 | 5.7s |  |
| 628 | `netconnection_serialize_arrays` | 6 | 5.4s |  |
| 629 | `netstream_client` | 10 | 5.5s |  |
| 630 | `netstream_connect` | 7 | 5.3s |  |
| 631 | `newactivation_in_script_init` | 3 | 6.7s |  |
| 632 | `newclass_twice` | 3 | 6.6s |  |
| 633 | `nonconflicting_declarations` | 0 | 6.8s |  |
| 634 | `null_void_types` | 8 | 6.8s |  |
| 635 | `number_autoconv` | 21 | 3.3s |  |
| 636 | `number_autoconv_amf` | 132 | 6.7s |  |
| 637 | `number_autoconv_array_sort_32bit` | 1 | 6.8s |  |
| 638 | `number_constr` | 58 | 6.9s |  |
| 639 | `number_toexponential` | 378 | 6.8s |  |
| 640 | `number_toexponential2` | 35 | 6.8s |  |
| 641 | `number_tofixed` | 378 | 6.7s |  |
| 642 | `number_toprecision` | 350 | 6.9s |  |
| 643 | `obfuscated_class_names` | 3 | 6.8s |  |
| 644 | `object_enumeration` | 10 | 6.7s |  |
| 645 | `object_prototype` | 4 | 6.8s |  |
| 646 | `object_to_locale_string` | 2 | 6.7s |  |
| 647 | `object_to_string` | 2 | 6.7s |  |
| 648 | `object_value_of` | 2 | 3.1s |  |
| 649 | `op_coerce` | 54 | 3.3s |  |
| 650 | `op_coerce_x` | 54 | 6.9s |  |
| 651 | `op_escxattr` | 2 | 6.7s |  |
| 652 | `op_escxelem` | 2 | 6.8s |  |
| 653 | `op_lookupswitch` | 4 | 6.8s |  |
| 654 | `optimize_coerce` | 1 | 6.7s |  |
| 655 | `orphan_movie_complex` | 80 | 7.3s |  |
| 656 | `orphan_movie_reorder` | 111 | 26.9s |  |
| 657 | `package_namespace` | 7 | 6.6s |  |
| 658 | `param_default_value_has_zero_cpool_index` | 1 | 6.7s |  |
| 659 | `parent_early_access_child` | 16 | 6.9s |  |
| 660 | `parse_float` | 81 | 7.0s |  |
| 661 | `pixelbender_ceil` | 77 | 7.0s |  |
| 662 | `pixelbender_conditional` | 138 | 9.7s |  |
| 663 | `pixelbender_conversions` | 270 | 7.3s |  |
| 664 | `pixelbender_dithering` | 8 | 31.8s |  |
| 665 | `pixelbender_div` | 36 | 7.1s |  |
| 666 | `pixelbender_effect_BlurredFocus` | 0 | 34.6s |  |
| 667 | `pixelbender_effect_glassDisplace` | 0 | 13.2s |  |
| 668 | `pixelbender_effect_smudge` | 0 | 10.9s |  |
| 669 | `pixelbender_effect_tintype` | 0 | 9.9s |  |
| 670 | `pixelbender_effect_twirl` | 0 | 11.1s |  |
| 671 | `pixelbender_eof` | 7 | 7.0s |  |
| 672 | `pixelbender_images` | 0 | 9.4s |  |
| 673 | `pixelbender_input` | 103 | 27.8s |  |
| 674 | `pixelbender_logicalnot` | 20 | 7.0s |  |
| 675 | `pixelbender_malformed_data` | 190 | 27.8s |  |
| 676 | `pixelbender_multiple_out_params` | 1 | 3.4s |  |
| 677 | `pixelbender_no_out_param` | 6 | 7.0s |  |
| 678 | `pixelbender_outputs` | 13 | 7.2s |  |
| 679 | `pixelbender_padding_bytes` | 22 | 7.1s |  |
| 680 | `pixelbender_param_qualifier` | 512 | 7.1s |  |
| 681 | `pixelbender_parameters` | 1563 | 7.4s |  |
| 682 | `pixelbender_parameters_bool` | 240 | 7.2s |  |
| 683 | `pixelbender_parameters_int_vs_bool` | 54 | 7.2s |  |
| 684 | `pixelbender_parse_errors` | 6 | 7.0s |  |
| 685 | `pixelbender_rsqrt` | 24 | 7.1s |  |
| 686 | `pixelbender_select_kinds` | 8 | 7.1s |  |
| 687 | `pixelbender_shaderdata` | 49 | 7.0s |  |
| 688 | `pixelbender_shaderdata_setter` | 99 | 7.4s |  |
| 689 | `pixelbender_sign` | 60 | 7.1s |  |
| 690 | `pixelbender_vector_output` | 11 | 7.2s |  |
| 691 | `place_multiple` | 17 | 26.6s |  |
| 692 | `place_object_replace` | 9 | 7.2s |  |
| 693 | `place_object_replace_2` | 24 | 7.1s |  |
| 694 | `place_object_same_depth_frame` | 1 | 7.1s |  |
| 695 | `point` | 132 | 7.5s |  |
| 696 | `primitive_edge_cases` | 1 | 6.9s |  |
| 697 | `property_priority` | 22 | 7.0s |  |
| 698 | `property_priority_three_level` | 6 | 25.4s |  |
| 699 | `propertyisenumerable_namespaces` | 6 | 6.7s |  |
| 700 | `prototype_set_null` | 7 | 6.6s |  |
| 701 | `proxy_callproperty` | 24 | 6.7s |  |
| 702 | `proxy_deleteproperty` | 64 | 6.9s |  |
| 703 | `proxy_enumeration` | 34 | 6.8s |  |
| 704 | `proxy_getproperty` | 77 | 6.8s |  |
| 705 | `proxy_hasownproperty` | 8 | 6.7s |  |
| 706 | `proxy_hasproperty` | 32 | 6.7s |  |
| 707 | `proxy_serialize` | 9 | 6.7s |  |
| 708 | `proxy_setproperty` | 42 | 6.8s |  |
| 709 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.6s |  |
| 710 | `qname_constr` | 32 | 6.8s |  |
| 711 | `qname_constr_namespace` | 24 | 6.8s |  |
| 712 | `qname_enumeration` | 9 | 6.7s |  |
| 713 | `qname_indexing` | 23 | 6.8s |  |
| 714 | `qname_tostring` | 25 | 6.8s |  |
| 715 | `qname_valueof` | 29 | 6.9s |  |
| 716 | `regexp_constr` | 148 | 7.2s |  |
| 717 | `regexp_exec` | 19 | 6.8s |  |
| 718 | `regexp_extended` | 47 | 7.0s |  |
| 719 | `regexp_multiargs` | 1 | 7.1s |  |
| 720 | `regexp_test` | 27 | 3.5s |  |
| 721 | `regexp_toString` | 10 | 7.2s |  |
| 722 | `register_script_refresh` | 35 | 7.5s |  |
| 723 | `remove_child_clear_field` | 88 | 7.8s |  |
| 724 | `remove_dobj` | 3 | 7.1s |  |
| 725 | `resolve_order` | 4 | 7.1s |  |
| 726 | `responder_null_callbacks` | 1 | 7.1s |  |
| 727 | `rng` | 1 | 8.1s |  |
| 728 | `rootless` | 42 | 6.9s |  |
| 729 | `rshift` | 1058 | 18.6s |  |
| 730 | `sandbox_type_inherited` | 2 | 9.4s |  |
| 731 | `sandbox_type_local_file` | 1 | 7.0s |  |
| 732 | `sandbox_type_local_network` | 1 | 6.8s |  |
| 733 | `scene_constr` | 8 | 7.0s |  |
| 734 | `selection` | 239 | 7.5s |  |
| 735 | `set_local_0` | 31 | 7.1s |  |
| 736 | `set_property_is_enumerable` | 85 | 7.4s |  |
| 737 | `shaderparameter_value` | 4 | 7.0s |  |
| 738 | `shape_drawrect` | 54 | 7.0s |  |
| 739 | `shared_object_no_root` | 3 | 6.9s |  |
| 740 | `simplebutton_added_to_stage` | 45 | 26.7s |  |
| 741 | `simplebutton_childevents` | 86 | 27.0s |  |
| 742 | `simplebutton_childevents_nested` | 54 | 7.3s |  |
| 743 | `simplebutton_childevents_sprite` | 13 | 6.9s |  |
| 744 | `simplebutton_childprops` | 144 | 7.1s |  |
| 745 | `simplebutton_childshuffle` | 23 | 6.7s |  |
| 746 | `simplebutton_constr` | 36 | 7.2s |  |
| 747 | `simplebutton_constr_childevents` | 48 | 7.2s |  |
| 748 | `simplebutton_constr_params` | 42 | 7.0s |  |
| 749 | `simplebutton_mouseenabled` | 26 | 6.8s |  |
| 750 | `simplebutton_multi_children` | 19 | 7.1s |  |
| 751 | `simplebutton_structure` | 27 | 7.2s |  |
| 752 | `simplebutton_symbolclass` | 68 | 7.2s |  |
| 753 | `slot_disp_id_shared_numbering` | 1 | 25.9s |  |
| 754 | `slots_force_autoassigned` | 1 | 6.9s |  |
| 755 | `socket_after_disconnect` | 1 | 7.0s |  |
| 756 | `socket_close` | 2 | 6.8s |  |
| 757 | `socket_connect` | 4 | 6.9s |  |
| 758 | `socket_errors` | 56 | 7.3s |  |
| 759 | `socket_read_big` | 48 | 8.9s |  |
| 760 | `socket_read_little` | 48 | 3.2s |  |
| 761 | `socket_read_write_object` | 8 | 6.7s |  |
| 762 | `socket_write_big` | 15 | 7.0s |  |
| 763 | `socket_write_little` | 14 | 6.7s |  |
| 764 | `sound_embeddedprops` | 26 | 6.7s |  |
| 765 | `sound_play` | 19 | 6.8s |  |
| 766 | `sound_valueof` | 33 | 6.6s |  |
| 767 | `soundchannel_soundtransform` | 835 | 27.3s |  |
| 768 | `soundchannel_soundtransform_exists` | 5 | 25.9s |  |
| 769 | `soundchannel_stop` | 8 | 6.9s |  |
| 770 | `soundmixer_buffertime` | 5 | 6.6s |  |
| 771 | `soundmixer_stopall` | 6 | 6.7s |  |
| 772 | `soundtransform` | 442 | 9.0s |  |
| 773 | `sprite_with_frames` | 0 | 26.6s |  |
| 774 | `stage3d_agal_cross_product` | 0 | 9.6s |  |
| 775 | `stage3d_agal_upload_errors` | 66 | 9.7s |  |
| 776 | `stage3d_bitmap` | 0 | 32.5s |  |
| 777 | `stage3d_blend` | 81 | 30.8s |  |
| 778 | `stage3d_context3d_string_args` | 158 | 7.7s |  |
| 779 | `stage3d_errors` | 7 | 6.8s |  |
| 780 | `stage3d_errors_atf` | 3 | 8.1s |  |
| 781 | `stage3d_errors_swf_29` | 6 | 6.9s |  |
| 782 | `stage3d_float1_index` | 0 | 28.7s |  |
| 783 | `stage3d_fractal` | 0 | 29.2s |  |
| 784 | `stage3d_ignore_sampler_override` | 0 | 28.7s |  |
| 785 | `stage3d_multistage_triangle` | 3 | 9.6s |  |
| 786 | `stage3d_program_constants_bytearray_be` | 0 | 29.9s |  |
| 787 | `stage3d_program_constants_bytearray_le` | 0 | 10.0s |  |
| 788 | `stage3d_program_constants_invalid_input` | 21 | 7.5s |  |
| 789 | `stage3d_raytrace` | 0 | 32.4s |  |
| 790 | `stage3d_rotating_cube` | 0 | 10.1s |  |
| 791 | `stage3d_sampler` | 0 | 11.4s |  |
| 792 | `stage3d_sampler_partial_upload` | 0 | 9.6s |  |
| 793 | `stage3d_stencil` | 0 | 29.6s |  |
| 794 | `stage3d_texture` | 0 | 14.2s |  |
| 795 | `stage3d_texture_bytearray` | 0 | 10.7s |  |
| 796 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.1s |  |
| 797 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.2s |  |
| 798 | `stage3d_triangle` | 0 | 9.6s |  |
| 799 | `stage3d_triangle_bytes4` | 0 | 9.5s |  |
| 800 | `stage3d_triangle_float1` | 0 | 9.5s |  |
| 801 | `stage3d_triangle_index_upload` | 0 | 9.5s |  |
| 802 | `stage3d_x_y` | 22 | 6.9s |  |
| 803 | `stage_access` | 10 | 3.4s |  |
| 804 | `stage_displayobject_properties` | 24 | 6.7s |  |
| 805 | `stage_framerate_nan` | 7 | 3.4s |  |
| 806 | `stage_framerate_negative` | 6 | 6.8s |  |
| 807 | `stage_framerate_zero` | 6 | 6.9s |  |
| 808 | `stage_invalidate` | 38 | 7.0s |  |
| 809 | `stage_loaderinfo_properties` | 24 | 7.1s |  |
| 810 | `stage_mousechildren` | 2 | 6.8s |  |
| 811 | `stage_mouseenabled` | 15 | 6.8s |  |
| 812 | `stage_overriden_setters` | 31 | 6.9s |  |
| 813 | `stage_properties` | 30 | 6.7s |  |
| 814 | `stage_stage3Ds_vector` | 1 | 25.6s |  |
| 815 | `static_var_with_this_in_ctor` | 2 | 6.7s |  |
| 816 | `stored_properties` | 11 | 6.7s |  |
| 817 | `strict_equality` | 34 | 6.8s |  |
| 818 | `string_call` | 13 | 6.7s |  |
| 819 | `string_case` | 23 | 6.7s |  |
| 820 | `string_char_at` | 27 | 6.7s |  |
| 821 | `string_char_code_at` | 28 | 6.7s |  |
| 822 | `string_concat_fromcharcode` | 37 | 6.8s |  |
| 823 | `string_constr` | 25 | 6.8s |  |
| 824 | `string_indexof_lastindexof` | 87 | 8.6s |  |
| 825 | `string_length` | 16 | 6.5s |  |
| 826 | `string_locale_compare` | 39 | 6.8s |  |
| 827 | `string_match` | 51 | 6.7s |  |
| 828 | `string_relational_compare` | 4 | 6.4s |  |
| 829 | `string_replace` | 51 | 6.7s |  |
| 830 | `string_search` | 41 | 6.6s |  |
| 831 | `string_slice_substr_substring` | 170 | 7.6s |  |
| 832 | `string_split` | 29 | 6.5s |  |
| 833 | `string_substr_negative` | 21 | 6.5s |  |
| 834 | `string_substr_weird` | 182 | 6.5s |  |
| 835 | `subtract` | 1058 | 18.5s |  |
| 836 | `super_get_call` | 12 | 6.5s |  |
| 837 | `supercall_two_classobjects` | 2 | 6.5s |  |
| 838 | `swf8` | 1 | 6.4s |  |
| 839 | `swf_10_queued_goto_scripts_construct` | 52 | 6.8s |  |
| 840 | `swf_9_goto_in_enter_frame` | 17 | 6.5s |  |
| 841 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.5s |  |
| 842 | `swf_9_queued_goto_scripts` | 6 | 6.5s |  |
| 843 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 844 | `swf_9_versioning` | 2 | 6.5s |  |
| 845 | `swf_wrong_frame_count` | 38 | 6.8s |  |
| 846 | `swf_wrong_frame_count_isplaying` | 22 | 24.7s |  |
| 847 | `symbol_class_binary_data` | 8 | 6.5s |  |
| 848 | `symbol_class_conflict` | 4 | 7.0s |  |
| 849 | `symbol_class_root_not_zero` | 1 | 6.3s |  |
| 850 | `symbolclass_invalid_utf8` | 2 | 6.5s |  |
| 851 | `tab_ordering_automatic_advanced` | 184 | 6.7s |  |
| 852 | `tab_ordering_automatic_basic` | 45 | 5.8s |  |
| 853 | `tab_ordering_children` | 116 | 6.2s |  |
| 854 | `tab_ordering_custom_basic` | 34 | 5.8s |  |
| 855 | `tab_ordering_stage_tab_children` | 32 | 5.9s |  |
| 856 | `tab_ordering_stage_tab_children_remove_root` | 5 | 5.9s |  |
| 857 | `tab_ordering_tabbable` | 47 | 6.1s |  |
| 858 | `text_engine_fontdescription` | 27 | 5.9s |  |
| 859 | `text_run` | 7 | 5.7s |  |
| 860 | `textbox_click` | 37 | 24.6s |  |
| 861 | `textfield_event` | 66 | 6.1s |  |
| 862 | `textfield_focusin_event` | 9 | 5.8s |  |
| 863 | `textfield_input_dead_keys_windows` | 15 | 5.9s |  |
| 864 | `textfield_unload` | 39 | 24.3s |  |
| 865 | `textformat` | 1134 | 5.9s |  |
| 866 | `textformat_display` | 14 | 5.8s |  |
| 867 | `textformat_font_max_length` | 4 | 2.3s |  |
| 868 | `throw` | 3 | 5.8s |  |
| 869 | `timeline_scripts` | 3 | 5.9s |  |
| 870 | `timer` | 90 | 6.4s |  |
| 871 | `timer_events` | 3 | 6.0s |  |
| 872 | `timer_finished` | 11 | 2.5s |  |
| 873 | `timer_reset` | 8 | 6.2s |  |
| 874 | `timer_setdelay` | 5 | 6.3s |  |
| 875 | `trace` | 12 | 5.9s |  |
| 876 | `truthiness` | 30 | 3.5s |  |
| 877 | `try_catch` | 11 | 1.1s |  |
| 878 | `try_catch_typed` | 12 | 1.1s |  |
| 879 | `typeof` | 30 | 1.1s |  |
| 880 | `uint_constr` | 92 | 1.1s |  |
| 881 | `uint_tofixed` | 1215 | 1.1s |  |
| 882 | `uint_tostring` | 3375 | 1.1s |  |
| 883 | `unchecked_function` | 15 | 1.1s |  |
| 884 | `unescape` | 28 | 1.1s |  |
| 885 | `url_loader` | 25 | 1.1s |  |
| 886 | `urlrequest` | 18 | 1.1s |  |
| 887 | `urlstream_basic` | 5 | 1.1s |  |
| 888 | `urshift` | 1058 | 1.1s |  |
| 889 | `vector_class` | 36 | 1.1s |  |
| 890 | `vector_class_call` | 11 | 1.1s |  |
| 891 | `vector_coercion` | 66 | 1.1s |  |
| 892 | `vector_concat` | 90 | 1.1s |  |
| 893 | `vector_constr` | 107 | 1.1s |  |
| 894 | `vector_enumeration` | 5 | 1.1s |  |
| 895 | `vector_every` | 92 | 1.1s |  |
| 896 | `vector_filter` | 95 | 1.1s |  |
| 897 | `vector_holes` | 24 | 1.1s |  |
| 898 | `vector_indexof` | 302 | 1.1s |  |
| 899 | `vector_insertat` | 270 | 1.1s |  |
| 900 | `vector_int_access` | 4 | 1.1s |  |
| 901 | `vector_int_delete` | 11 | 1.1s |  |
| 902 | `vector_join` | 58 | 1.1s |  |
| 903 | `vector_lastindexof` | 302 | 1.1s |  |
| 904 | `vector_legacy` | 10 | 1.1s |  |
| 905 | `vector_map` | 85 | 1.1s |  |
| 906 | `vector_object_final` | 1 | 1.1s |  |
| 907 | `vector_object_toString` | 10 | 1.1s |  |
| 908 | `vector_pushpop` | 255 | 1.1s |  |
| 909 | `vector_reborrow_bug` | 10 | 8.1s |  |
| 910 | `vector_removeat` | 172 | 7.2s |  |
| 911 | `vector_reverse` | 232 | 7.2s |  |
| 912 | `vector_shiftunshift` | 252 | 6.1s |  |
| 913 | `vector_slice` | 331 | 7.7s |  |
| 914 | `vector_sort` | 905 | 15.2s |  |
| 915 | `vector_splice` | 693 | 9.7s |  |
| 916 | `vector_splice_fixed_bug_compat` | 4 | 6.3s |  |
| 917 | `vector_tostring` | 79 | 6.8s |  |
| 918 | `verification` | 8 | 6.3s |  |
| 919 | `verify_abnormal_loop` | 1 | 6.1s |  |
| 920 | `verify_dxns_without_flag` | 3 | 6.5s |  |
| 921 | `verify_exception_targets_edge_case` | 1 | 6.1s |  |
| 922 | `verify_jump_to_middle_of_op` | 1 | 6.2s |  |
| 923 | `verify_lookup_switch_edge_case` | 1 | 6.1s |  |
| 924 | `verify_stack` | 5 | 6.2s |  |
| 925 | `verify_unreachable_exception` | 2 | 6.1s |  |
| 926 | `versioned_isplaying` | 2 | 6.1s |  |
| 927 | `virtual_properties` | 16 | 6.3s |  |
| 928 | `with` | 4 | 6.3s |  |
| 929 | `wrong_arg_count` | 7 | 6.4s |  |
| 930 | `xml_abstract_equality` | 36 | 6.4s |  |
| 931 | `xml_advanced` | 52 | 6.2s |  |
| 932 | `xml_appendchild` | 10 | 6.3s |  |
| 933 | `xml_as_attribute` | 9 | 6.2s |  |
| 934 | `xml_attribute` | 35 | 6.4s |  |
| 935 | `xml_attribute_name` | 40 | 6.2s |  |
| 936 | `xml_basic` | 33 | 6.3s |  |
| 937 | `xml_child` | 25 | 6.3s |  |
| 938 | `xml_childindex` | 7 | 6.2s |  |
| 939 | `xml_children` | 43 | 6.8s |  |
| 940 | `xml_class_call` | 9 | 6.2s |  |
| 941 | `xml_contains` | 197 | 6.4s |  |
| 942 | `xml_copy` | 20 | 8.6s |  |
| 943 | `xml_ctor_from_tostring` | 23 | 7.0s |  |
| 944 | `xml_delete` | 114 | 6.8s |  |
| 945 | `xml_descendants` | 83 | 6.8s |  |
| 946 | `xml_elements` | 6 | 6.7s |  |
| 947 | `xml_equals_namespace_check` | 2 | 6.7s |  |
| 948 | `xml_explicit_use_namespace` | 5 | 6.8s |  |
| 949 | `xml_getdescendants_qname` | 21 | 6.7s |  |
| 950 | `xml_has_property_via_in` | 26 | 6.7s |  |
| 951 | `xml_hasownproperty` | 6 | 6.7s |  |
| 952 | `xml_ignore_white` | 6 | 6.7s |  |
| 953 | `xml_length` | 2 | 6.7s |  |
| 954 | `xml_list_as_attribute` | 9 | 6.7s |  |
| 955 | `xml_list_concat` | 20 | 6.7s |  |
| 956 | `xml_list_enumerate` | 4 | 6.6s |  |
| 957 | `xml_methods_settings` | 3 | 6.7s |  |
| 958 | `xml_mismatched_tag` | 37 | 6.8s |  |
| 959 | `xml_namespace` | 39 | 3.2s |  |
| 960 | `xml_namespace_methods` | 245 | 6.8s |  |
| 961 | `xml_namespaced_property` | 7 | 6.7s |  |
| 962 | `xml_no_namespace` | 1 | 6.6s |  |
| 963 | `xml_nodekind` | 3 | 6.8s |  |
| 964 | `xml_normalize` | 35 | 6.9s |  |
| 965 | `xml_notification_bubbling` | 361 | 6.7s |  |
| 966 | `xml_parent` | 8 | 6.7s |  |
| 967 | `xml_set_children` | 17 | 6.8s |  |
| 968 | `xml_set_name` | 34 | 6.7s |  |
| 969 | `xml_settings` | 6 | 3.2s |  |
| 970 | `xml_simple_complex_content` | 47 | 6.7s |  |
| 971 | `xml_socket` | 11 | 6.9s |  |
| 972 | `xml_text` | 7 | 6.7s |  |
| 973 | `xml_tostring` | 6 | 6.7s |  |
| 974 | `xml_tostring_namespace` | 12 | 6.6s |  |
| 975 | `xml_unescaping` | 23 | 6.7s |  |
| 976 | `xml_weird_ignores` | 54 | 6.7s |  |
| 977 | `xml_wildcard` | 11 | 6.7s |  |
| 978 | `xmldocument` | 254 | 6.8s |  |
| 979 | `xmlnode` | 3540 | 6.8s |  |
| 980 | `zero_frame_clip` | 3 | 7.1s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.8s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 6.7s |  |
| 3 | `blend_transform` | 1 | 1 | 5.6s |  |
| 4 | `coerce_property` | 3 | 3 | 6.9s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 3.3s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 7.1s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.0s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 28.5s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 7.1s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.0s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 5.4s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 6.4s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 26.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 27.4s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.4s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.4s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.2s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.8s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 26.3s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.2s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.7s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 6.8s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 25.1s |  |
| 24 | `uint_toexponential` | 100 | 100 | 1.1s |  |
| 25 | `uint_toprecision` | 433 | 433 | 1.1s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 25.5s |  |

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
| 42 | `displayobject_transform` | 66.3% | 59 | 89 | 30 |  |
| 43 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 44 | `tab_ordering_arrows` | 64.5% | 645 | 1000 | 355 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 46 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 47 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 48 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 49 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 50 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 51 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 52 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 53 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 54 | `button_hittest` | 50.0% | 1 | 2 | 1 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 56 | `pixelbender_effect_glassDisplace_shaderfilter` | 50.0% | 2 | 4 | 2 |  |
| 57 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 58 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 20.2s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.1s |  |
| 3 | `verify_typecheck` | exit code 1 | 2.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**212 tests** with output mismatch, sorted by match rate (best first)

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
| 42 | `displayobject_transform` | 66.3% | 59/89 | 89 | 89 |  |
| 43 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 44 | `tab_ordering_arrows` | 64.5% | 645/1000 | 1000 | 998 |  |
| 45 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 46 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 47 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 48 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 49 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 50 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 51 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 52 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 53 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 54 | `button_hittest` | 50.0% | 1/2 | 2 | 2 |  |
| 55 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 56 | `pixelbender_effect_glassDisplace_shaderfilter` | 50.0% | 2/4 | 2 | 4 |  |
| 57 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 58 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 59 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 60 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 61 | `displayobject_scrollrect` | 42.4% | 14/33 | 33 | 33 |  |
| 62 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 63 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 64 | `matrix3d` | 33.3% | 19/57 | 22 | 57 |  |
| 65 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 66 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 67 | `displayobject_filters` | 29.4% | 5/17 | 5 | 17 |  |
| 68 | `filters_array_holes` | 28.0% | 7/25 | 7 | 25 |  |
| 69 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 70 | `filter_rewind` | 25.0% | 2/8 | 8 | 8 |  |
| 71 | `netstream_flv_date` | 25.0% | 1/4 | 1 | 4 |  |
| 72 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 73 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 74 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 75 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 76 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 77 | `color_matrix_filter` | 21.1% | 4/19 | 7 | 19 |  |
| 78 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 79 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 80 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 81 | `flash_media_video_constructor` | 16.0% | 25/156 | 110 | 156 |  |
| 82 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 83 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 84 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 85 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 86 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 87 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 88 | `displacement_map_filter` | 11.5% | 7/61 | 7 | 61 |  |
| 89 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 90 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 91 | `blur_filter` | 9.3% | 4/43 | 7 | 43 |  |
| 92 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 93 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 94 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 95 | `convolution_filter` | 7.9% | 7/89 | 7 | 89 |  |
| 96 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 97 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 98 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 99 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 100 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 101 | `vector3d` | 6.0% | 24/397 | 33 | 397 |  |
| 102 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 103 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 104 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 105 | `flash_media_video_rotation_probe` | 3.7% | 1/27 | 1 | 27 |  |
| 106 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 107 | `glow_filter` | 3.1% | 4/127 | 7 | 127 |  |
| 108 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 109 | `flash_media_video_setter` | 2.5% | 1/40 | 1 | 40 |  |
| 110 | `drop_shadow_filter` | 2.3% | 4/172 | 8 | 172 |  |
| 111 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 112 | `bevel_filter` | 2.1% | 4/187 | 7 | 187 |  |
| 113 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 114 | `gradient_bevel_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 115 | `gradient_glow_filter` | 1.9% | 4/206 | 7 | 206 |  |
| 116 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 117 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 118 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 119 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 120 | `textline_validity` | 0.6% | 1/162 | 1 | 162 |  |
| 121 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 122 | `perspective_projection` | 0.3% | 4/1443 | 1245 | 1443 |  |
| 123 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 124 | `all_classes/display/swf9` | 0.1% | 2/1959 | 315 | 1959 |  |
| 125 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 126 | `all_classes/events/swf9` | 0.1% | 1/1030 | 178 | 1030 |  |
| 127 | `rectangle` | 0.1% | 1/1094 | 1 | 1094 |  |
| 128 | `all_classes/events/swf10` | 0.1% | 1/1638 | 178 | 1638 |  |
| 129 | `all_classes/events/swf11` | 0.1% | 1/1750 | 178 | 1750 |  |
| 130 | `all_classes/events/swf12` | 0.1% | 1/1814 | 178 | 1814 |  |
| 131 | `all_classes/events/swf30` | 0.0% | 1/2353 | 178 | 2353 |  |
| 132 | `all_classes/display/swf10` | 0.0% | 1/2569 | 315 | 2569 |  |
| 133 | `all_classes/display/swf11` | 0.0% | 1/2593 | 315 | 2593 |  |
| 134 | `all_classes/display/swf12` | 0.0% | 1/2593 | 315 | 2593 |  |
| 135 | `all_classes/display/swf13` | 0.0% | 1/2671 | 315 | 2671 |  |
| 136 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 137 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 138 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 139 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 140 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 141 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 142 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 143 | `all_classes/display/swf30` | 0.0% | 0/2936 | 315 | 2936 |  |
| 144 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 145 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 146 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 147 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 148 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 149 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 150 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 151 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 152 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 153 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 154 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 155 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 156 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 157 | `blend_mode_null` | 0.0% | 0/1 | 1 | 1 |  |
| 158 | `button_bounds` | 0.0% | 0/1 | 1 | 1 |  |
| 159 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 160 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 161 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 162 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 163 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 164 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 165 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 166 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 167 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 168 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 169 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 170 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 171 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 172 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 173 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 174 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 175 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 176 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 177 | `matrix3d_compose` | 0.0% | 0/34 | 0 | 34 |  |
| 178 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 179 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 180 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 181 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 182 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 183 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 184 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 185 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 186 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 187 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 188 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 189 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 190 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 191 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 192 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 193 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 194 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 195 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 196 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 197 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 198 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 199 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 200 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 201 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 202 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 203 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 204 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 205 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 206 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 207 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 208 | `utils3d` | 0.0% | 0/7 | 0 | 7 |  |
| 209 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 210 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 211 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 212 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
