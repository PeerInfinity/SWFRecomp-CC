# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 22:08 UTC

**Git SHA**: `ff7151c150`

**Run Duration**: 196m 13s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1222 |
| Passing | **1009** (82.6%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1035** (84.7%) |
| Failing | 187 |
| Total expected lines | 151259 |
| Matching lines | 116537 (77.0%) |
| Mismatched lines | 34722 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 184 | 98.4% |
| Runtime Error | 3 | 1.6% |

## Passing Tests

**1009 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 14.6s |  |
| 2 | `agal_compiler` | 13 | 7.5s |  |
| 3 | `air_datagram_socket` | 1 | 6.2s |  |
| 4 | `air_hidden_lookup` | 2 | 5.7s |  |
| 5 | `all_classes/security/swf11` | 3 | 5.7s |  |
| 6 | `amf_array_serialization` | 17 | 7.2s |  |
| 7 | `amf_custom_obj` | 26 | 5.8s |  |
| 8 | `amf_dictionary` | 9 | 5.7s |  |
| 9 | `amf_function` | 46 | 5.7s |  |
| 10 | `amf_invalid_date` | 2 | 5.7s |  |
| 11 | `amf_missing_prop` | 6 | 5.7s |  |
| 12 | `amf_nondynamic_function_prop` | 6 | 6.6s |  |
| 13 | `amf_setter_error` | 8 | 6.6s |  |
| 14 | `amf_vector` | 40 | 6.7s |  |
| 15 | `amf_xml` | 6 | 6.6s |  |
| 16 | `application_domain` | 4 | 6.5s |  |
| 17 | `array_access` | 18 | 6.6s |  |
| 18 | `array_access_interpreter` | 4 | 6.5s |  |
| 19 | `array_access_no_pubns` | 2 | 6.4s |  |
| 20 | `array_concat` | 41 | 6.6s |  |
| 21 | `array_constr` | 10 | 6.4s |  |
| 22 | `array_delete` | 44 | 6.7s |  |
| 23 | `array_enumeration` | 10 | 6.6s |  |
| 24 | `array_enumeration_elements` | 11 | 6.5s |  |
| 25 | `array_every` | 8 | 6.5s |  |
| 26 | `array_filter` | 6 | 6.5s |  |
| 27 | `array_foreach` | 18 | 6.5s |  |
| 28 | `array_hasownproperty` | 11 | 2.6s |  |
| 29 | `array_holes` | 9 | 6.5s |  |
| 30 | `array_index_max` | 84 | 6.4s |  |
| 31 | `array_indexof` | 25 | 6.5s |  |
| 32 | `array_join` | 26 | 6.6s |  |
| 33 | `array_lastindexof` | 29 | 6.6s |  |
| 34 | `array_length` | 14 | 6.6s |  |
| 35 | `array_literal` | 3 | 6.5s |  |
| 36 | `array_map` | 8 | 6.4s |  |
| 37 | `array_pop` | 52 | 6.6s |  |
| 38 | `array_push` | 24 | 6.5s |  |
| 39 | `array_reborrow_bug` | 6 | 6.5s |  |
| 40 | `array_reverse` | 28 | 6.6s |  |
| 41 | `array_shift` | 51 | 2.7s |  |
| 42 | `array_slice` | 39 | 6.5s |  |
| 43 | `array_some` | 8 | 6.5s |  |
| 44 | `array_sort` | 297 | 6.9s |  |
| 45 | `array_sort_fun_swf12` | 2 | 6.5s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.0s |  |
| 47 | `array_sort_random` | 210 | 6.5s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 6.6s |  |
| 49 | `array_sorton` | 545 | 8.0s |  |
| 50 | `array_sparse_ops` | 41 | 7.2s |  |
| 51 | `array_splice` | 133 | 7.3s |  |
| 52 | `array_splice2` | 428 | 7.4s |  |
| 53 | `array_splice_types` | 48 | 7.2s |  |
| 54 | `array_storage` | 8 | 7.1s |  |
| 55 | `array_tolocalestring` | 9 | 7.1s |  |
| 56 | `array_tostring` | 12 | 7.1s |  |
| 57 | `array_unshift` | 24 | 7.1s |  |
| 58 | `array_valueof` | 9 | 7.0s |  |
| 59 | `array_vector_null_callback` | 10 | 7.1s |  |
| 60 | `astype` | 28 | 7.2s |  |
| 61 | `astypelate` | 24 | 7.2s |  |
| 62 | `astypelate_propagates` | 1 | 7.0s |  |
| 63 | `asymmetric_key_events` | 11 | 7.3s |  |
| 64 | `av_networking_params` | 9 | 7.1s |  |
| 65 | `avm2_catchup_dobj` | 158 | 7.8s |  |
| 66 | `away3d_advanced_shallow_water_demo` | 0 | 84.2s |  |
| 67 | `bevel_filter` | 187 | 7.3s |  |
| 68 | `bitand` | 1058 | 19.3s |  |
| 69 | `bitmap_constr` | 17 | 7.3s |  |
| 70 | `bitmap_data` | 1000 | 15.2s |  |
| 71 | `bitmap_pixelsnapping` | 2 | 26.2s |  |
| 72 | `bitmap_properties` | 23 | 7.2s |  |
| 73 | `bitmap_subclass` | 7 | 8.6s |  |
| 74 | `bitmap_subclass_properties` | 9 | 7.5s |  |
| 75 | `bitmap_timeline` | 9 | 7.2s |  |
| 76 | `bitmapdata_accuracy` | 1 | 42.6s |  |
| 77 | `bitmapdata_applyfilter_blur` | 0 | 26.9s |  |
| 78 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.0s |  |
| 79 | `bitmapdata_applyfilter_destpoint` | 0 | 26.2s |  |
| 80 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.6s |  |
| 81 | `bitmapdata_clone` | 13 | 7.3s |  |
| 82 | `bitmapdata_colortransform` | 0 | 7.5s |  |
| 83 | `bitmapdata_colortransform_oob` | 2 | 7.0s |  |
| 84 | `bitmapdata_constr` | 22 | 7.2s |  |
| 85 | `bitmapdata_constructor_from_timeline` | 1 | 7.5s |  |
| 86 | `bitmapdata_copychannel` | 0 | 28.6s |  |
| 87 | `bitmapdata_copypixels` | 23 | 27.1s |  |
| 88 | `bitmapdata_copypixels_blend_over` | 1 | 7.1s |  |
| 89 | `bitmapdata_copypixelstobytearray` | 39 | 7.0s |  |
| 90 | `bitmapdata_dispose` | 7 | 7.1s |  |
| 91 | `bitmapdata_draw` | 0 | 26.3s |  |
| 92 | `bitmapdata_draw_colortransform` | 0 | 7.3s |  |
| 93 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.8s |  |
| 94 | `bitmapdata_draw_filters` | 0 | 25.6s |  |
| 95 | `bitmapdata_draw_masks` | 0 | 7.0s |  |
| 96 | `bitmapdata_draw_rotation` | 0 | 7.3s |  |
| 97 | `bitmapdata_draw_self_via_graphic` | 0 | 7.2s |  |
| 98 | `bitmapdata_draw_stage` | 0 | 25.4s |  |
| 99 | `bitmapdata_drawwithquality` | 0 | 7.3s |  |
| 100 | `bitmapdata_embedded` | 9 | 7.4s |  |
| 101 | `bitmapdata_fillrect` | 0 | 7.3s |  |
| 102 | `bitmapdata_filter_sourcerect` | 0 | 25.8s |  |
| 103 | `bitmapdata_floodfill` | 35 | 7.0s |  |
| 104 | `bitmapdata_getpixels` | 39 | 25.5s |  |
| 105 | `bitmapdata_getvector` | 27 | 3.0s |  |
| 106 | `bitmapdata_histogram` | 59 | 3.0s |  |
| 107 | `bitmapdata_hittest` | 112 | 7.6s |  |
| 108 | `bitmapdata_hittest_threshold` | 18 | 7.1s |  |
| 109 | `bitmapdata_opaque` | 0 | 7.2s |  |
| 110 | `bitmapdata_pixeldissolve` | 1037 | 7.6s |  |
| 111 | `bitmapdata_pixeldissolve_image` | 0 | 7.4s |  |
| 112 | `bitmapdata_rectangle_rounding` | 16 | 6.9s |  |
| 113 | `bitmapdata_setpixels` | 286 | 7.2s |  |
| 114 | `bitmapdata_setvector` | 26 | 7.1s |  |
| 115 | `bitmapdata_sync` | 0 | 25.4s |  |
| 116 | `bitmapdata_threshold` | 176 | 7.7s |  |
| 117 | `bitnot` | 46 | 7.0s |  |
| 118 | `bitor` | 1058 | 18.8s |  |
| 119 | `bitxor` | 1058 | 18.8s |  |
| 120 | `blend_mode_null` | 1 | 7.0s |  |
| 121 | `blend_multiply_alpha` | 0 | 7.2s |  |
| 122 | `blend_scroll` | 0 | 7.2s |  |
| 123 | `blend_shader_luma_lighten` | 3 | 7.7s |  |
| 124 | `blur_filter` | 43 | 7.8s |  |
| 125 | `boolean_constr` | 32 | 7.7s |  |
| 126 | `boolean_negation` | 30 | 7.6s |  |
| 127 | `boolean_tostring` | 8 | 7.4s |  |
| 128 | `broadcast_event` | 7 | 7.6s |  |
| 129 | `button_bounds` | 1 | 7.6s |  |
| 130 | `button_hittest` | 2 | 27.3s |  |
| 131 | `button_nested_frame` | 48 | 27.8s |  |
| 132 | `bytearray` | 48 | 8.0s |  |
| 133 | `bytearray_compress` | 31 | 7.6s |  |
| 134 | `bytearray_errors` | 24 | 7.9s |  |
| 135 | `bytearray_method_serialization` | 1 | 7.7s |  |
| 136 | `bytearray_oom` | 3 | 7.7s |  |
| 137 | `bytearray_readobject_amf0` | 50 | 7.7s |  |
| 138 | `bytearray_readobject_amf3` | 53 | 7.8s |  |
| 139 | `bytearray_readutf8bytes_with_bom` | 16 | 7.9s |  |
| 140 | `bytearray_serialization` | 3 | 7.9s |  |
| 141 | `bytearray_string_null` | 19 | 8.1s |  |
| 142 | `bytearray_tostring` | 15 | 7.8s |  |
| 143 | `bytearray_utf16` | 8 | 7.8s |  |
| 144 | `bytearray_writeobject` | 24 | 7.7s |  |
| 145 | `callee_in_initializer` | 6 | 7.8s |  |
| 146 | `callproplex_class` | 1 | 7.8s |  |
| 147 | `capabilities_resolution` | 8 | 29.2s |  |
| 148 | `catch_class` | 6 | 7.4s |  |
| 149 | `catch_scope_slot` | 7 | 3.3s |  |
| 150 | `checkfilter` | 4 | 3.4s |  |
| 151 | `class_call` | 32 | 7.8s |  |
| 152 | `class_cast_call` | 14 | 7.7s |  |
| 153 | `class_enumeration` | 4 | 7.5s |  |
| 154 | `class_has_own_property` | 2 | 7.6s |  |
| 155 | `class_init_interpreter_mode` | 1 | 7.4s |  |
| 156 | `class_is` | 32 | 7.6s |  |
| 157 | `class_methods` | 5 | 7.5s |  |
| 158 | `class_object_properties` | 10 | 7.5s |  |
| 159 | `class_singleton` | 18 | 7.4s |  |
| 160 | `class_supercalls_errors` | 35 | 7.7s |  |
| 161 | `class_supercalls_mismatched` | 26 | 7.5s |  |
| 162 | `class_superclass_wrong_order` | 1 | 26.9s |  |
| 163 | `class_to_locale_string` | 2 | 7.6s |  |
| 164 | `class_to_string` | 2 | 7.5s |  |
| 165 | `class_value_of` | 2 | 7.5s |  |
| 166 | `click_block` | 5 | 8.3s |  |
| 167 | `click_invisible` | 3 | 7.6s |  |
| 168 | `closures` | 12 | 7.4s |  |
| 169 | `coerce_return_type` | 40 | 7.5s |  |
| 170 | `coerce_return_type_fail` | 2 | 7.3s |  |
| 171 | `coerce_return_void` | 3 | 7.3s |  |
| 172 | `coerce_string` | 86 | 7.5s |  |
| 173 | `coerce_string_precision` | 28 | 7.3s |  |
| 174 | `coerce_to_primitive_side_effects` | 29 | 7.4s |  |
| 175 | `color_matrix_filter` | 19 | 7.5s |  |
| 176 | `construct_errors_swf10` | 8 | 7.4s |  |
| 177 | `construct_frame_list` | 22 | 26.7s |  |
| 178 | `construct_interface` | 3 | 7.4s |  |
| 179 | `constructor_call` | 3 | 7.4s |  |
| 180 | `constructors_vs_timeline` | 5 | 26.6s |  |
| 181 | `constructprop_dynamic_primitive` | 7 | 7.4s |  |
| 182 | `context3d_creation` | 9 | 7.4s |  |
| 183 | `control_flow_bool` | 4 | 7.3s |  |
| 184 | `control_flow_stricteq` | 8 | 7.3s |  |
| 185 | `convert_boolean` | 30 | 7.3s |  |
| 186 | `convert_integer` | 90 | 7.5s |  |
| 187 | `convert_number` | 56 | 7.4s |  |
| 188 | `convert_uinteger` | 90 | 7.5s |  |
| 189 | `convolution_filter` | 89 | 7.5s |  |
| 190 | `cpool_index_invalid_bytecode_1` | 6 | 7.3s |  |
| 191 | `cpool_index_invalid_bytecode_2` | 3 | 7.3s |  |
| 192 | `cpool_index_invalid_bytecode_3` | 1 | 7.2s |  |
| 193 | `cross_api_version_call_older` | 12 | 7.7s |  |
| 194 | `cryptscore` | 11 | 7.4s |  |
| 195 | `date` | 30 | 7.7s |  |
| 196 | `date_parse` | 36 | 7.2s |  |
| 197 | `declocal` | 46 | 7.4s |  |
| 198 | `declocal_i` | 46 | 7.3s |  |
| 199 | `decode_uri` | 71 | 7.6s |  |
| 200 | `decrement` | 46 | 7.3s |  |
| 201 | `decrement_i` | 46 | 3.2s |  |
| 202 | `default_values` | 7 | 7.2s |  |
| 203 | `dictionary_access` | 62 | 7.5s |  |
| 204 | `dictionary_access_no_pubns` | 2 | 7.2s |  |
| 205 | `dictionary_delete` | 101 | 7.7s |  |
| 206 | `dictionary_foreach` | 42 | 7.4s |  |
| 207 | `dictionary_hasownproperty` | 63 | 7.6s |  |
| 208 | `dictionary_in` | 62 | 7.5s |  |
| 209 | `dictionary_iter_modify` | 8 | 7.3s |  |
| 210 | `dictionary_namespaces` | 36 | 7.4s |  |
| 211 | `dictionary_primitive_keys` | 29 | 7.3s |  |
| 212 | `displacement_map_filter` | 61 | 7.5s |  |
| 213 | `displayobject_alpha` | 277 | 7.2s |  |
| 214 | `displayobject_blendmode` | 0 | 7.4s |  |
| 215 | `displayobject_colortransform_nested` | 0 | 27.4s |  |
| 216 | `displayobject_filters` | 17 | 7.5s |  |
| 217 | `displayobject_from_enterframe` | 1 | 26.8s |  |
| 218 | `displayobject_getbounds_shape` | 0 | 27.0s |  |
| 219 | `displayobject_height` | 6052 | 27.2s |  |
| 220 | `displayobject_hittestobject` | 32 | 7.4s |  |
| 221 | `displayobject_hittestpoint` | 49 | 7.6s |  |
| 222 | `displayobject_hittestpoint_root` | 13 | 7.6s |  |
| 223 | `displayobject_invalid_floats` | 60 | 7.4s |  |
| 224 | `displayobject_invalid_props` | 3 | 7.3s |  |
| 225 | `displayobject_mask` | 3 | 7.7s |  |
| 226 | `displayobject_mask_self_referential` | 0 | 7.8s |  |
| 227 | `displayobject_metaData` | 3 | 7.3s |  |
| 228 | `displayobject_name` | 22 | 7.7s |  |
| 229 | `displayobject_name_from_timeline` | 24 | 7.5s |  |
| 230 | `displayobject_parent` | 12 | 7.3s |  |
| 231 | `displayobject_root` | 24 | 7.3s |  |
| 232 | `displayobject_rotation` | 1284 | 7.5s |  |
| 233 | `displayobject_set_matrix_nested` | 0 | 27.4s |  |
| 234 | `displayobject_set_name_loaded` | 3 | 7.8s |  |
| 235 | `displayobject_subclass` | 2 | 7.5s |  |
| 236 | `displayobject_visible` | 23 | 7.6s |  |
| 237 | `displayobject_width` | 4852 | 28.5s |  |
| 238 | `displayobject_x` | 614 | 7.6s |  |
| 239 | `displayobject_y` | 617 | 7.5s |  |
| 240 | `displayobjectcontainer_addchild` | 32 | 7.6s |  |
| 241 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.5s |  |
| 242 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.7s |  |
| 243 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.5s |  |
| 244 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.7s |  |
| 245 | `displayobjectcontainer_addchildat` | 42 | 7.5s |  |
| 246 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.6s |  |
| 247 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.5s |  |
| 248 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.5s |  |
| 249 | `displayobjectcontainer_contains` | 66 | 27.6s |  |
| 250 | `displayobjectcontainer_getchildat` | 4 | 7.5s |  |
| 251 | `displayobjectcontainer_getchildbyname` | 9 | 7.5s |  |
| 252 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.6s |  |
| 253 | `displayobjectcontainer_getchildindex` | 28 | 7.4s |  |
| 254 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.6s |  |
| 255 | `displayobjectcontainer_removechild` | 10 | 7.5s |  |
| 256 | `displayobjectcontainer_removechild_errors` | 4 | 7.5s |  |
| 257 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.6s |  |
| 258 | `displayobjectcontainer_removechildat` | 18 | 7.6s |  |
| 259 | `displayobjectcontainer_removechildren` | 51 | 7.8s |  |
| 260 | `displayobjectcontainer_setchildindex` | 42 | 7.4s |  |
| 261 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.9s |  |
| 262 | `displayobjectcontainer_swapchildren` | 42 | 7.6s |  |
| 263 | `displayobjectcontainer_swapchildrenat` | 42 | 7.5s |  |
| 264 | `displayobjectcontainer_timelineinstance` | 48 | 26.1s |  |
| 265 | `divide` | 1058 | 19.3s |  |
| 266 | `doabc_is_eager` | 1 | 25.6s |  |
| 267 | `documentclass` | 9 | 7.2s |  |
| 268 | `domain_memory` | 133 | 8.2s |  |
| 269 | `drag_drop` | 10 | 7.3s |  |
| 270 | `drop_shadow_filter` | 172 | 7.2s |  |
| 271 | `duplicate_defs` | 1 | 6.9s |  |
| 272 | `eager_init` | 1 | 7.0s |  |
| 273 | `edit_text_linkage` | 7 | 7.2s |  |
| 274 | `edittext_align` | 60 | 7.4s |  |
| 275 | `edittext_always_show_selection` | 0 | 25.9s |  |
| 276 | `edittext_antialiastype` | 296 | 7.2s |  |
| 277 | `edittext_at_point_methods_basic` | 16 | 8.3s |  |
| 278 | `edittext_autosize` | 39 | 7.3s |  |
| 279 | `edittext_autosize_align` | 0 | 25.8s |  |
| 280 | `edittext_autosize_height_dynamic` | 60 | 25.8s |  |
| 281 | `edittext_autosize_height_input` | 60 | 7.1s |  |
| 282 | `edittext_autosize_lazy_bounds_events` | 65 | 7.4s |  |
| 283 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.1s |  |
| 284 | `edittext_autosize_lazy_bounds_props` | 490 | 8.5s |  |
| 285 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.6s |  |
| 286 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.2s |  |
| 287 | `edittext_bottom_scroll_v_basic` | 210 | 7.1s |  |
| 288 | `edittext_bounds_scale` | 24 | 25.2s |  |
| 289 | `edittext_bullet` | 30 | 7.2s |  |
| 290 | `edittext_default_format` | 221 | 7.3s |  |
| 291 | `edittext_default_format_empty` | 136 | 7.3s |  |
| 292 | `edittext_empty_text_format` | 7 | 7.1s |  |
| 293 | `edittext_focus_selection` | 5 | 7.0s |  |
| 294 | `edittext_font_size` | 45 | 7.1s |  |
| 295 | `edittext_format_empty_font` | 8 | 7.0s |  |
| 296 | `edittext_get_char_index_at_point` | 4 | 26.7s |  |
| 297 | `edittext_get_line_index_at_point` | 2 | 25.9s |  |
| 298 | `edittext_get_line_index_of_char` | 76 | 8.0s |  |
| 299 | `edittext_getcharboundaries` | 172 | 7.4s |  |
| 300 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.6s |  |
| 301 | `edittext_getcharboundaries_scroll` | 85 | 7.3s |  |
| 302 | `edittext_getlinemetrics` | 146 | 7.4s |  |
| 303 | `edittext_html` | 3101 | 7.7s |  |
| 304 | `edittext_html_condensewhite` | 487 | 7.2s |  |
| 305 | `edittext_html_entity` | 4 | 7.4s |  |
| 306 | `edittext_html_font_size_swf12` | 267 | 7.2s |  |
| 307 | `edittext_html_font_size_swf13` | 273 | 6.9s |  |
| 308 | `edittext_html_roundtrip` | 17 | 7.1s |  |
| 309 | `edittext_ime_focus_lost` | 9 | 26.5s |  |
| 310 | `edittext_input_control` | 12 | 7.7s |  |
| 311 | `edittext_leading` | 9 | 7.8s |  |
| 312 | `edittext_letter_spacing` | 15 | 7.5s |  |
| 313 | `edittext_line_methods` | 294 | 8.9s |  |
| 314 | `edittext_line_metrics` | 11 | 28.4s |  |
| 315 | `edittext_margins` | 25 | 7.3s |  |
| 316 | `edittext_max_scroll_h_basic` | 475 | 7.5s |  |
| 317 | `edittext_max_scroll_v_basic` | 1000 | 7.3s |  |
| 318 | `edittext_mouse_selection` | 363 | 28.1s |  |
| 319 | `edittext_mousedown` | 3 | 8.0s |  |
| 320 | `edittext_mouseenabled` | 26 | 7.5s |  |
| 321 | `edittext_newline_character` | 22 | 7.3s |  |
| 322 | `edittext_newline_stripping` | 64 | 10.1s |  |
| 323 | `edittext_newlines` | 30 | 7.5s |  |
| 324 | `edittext_paragraph_methods` | 257 | 7.3s |  |
| 325 | `edittext_paste_events` | 8 | 7.4s |  |
| 326 | `edittext_paste_maxchars` | 4 | 7.1s |  |
| 327 | `edittext_paste_restrict` | 16 | 7.0s |  |
| 328 | `edittext_restrict` | 191 | 7.2s |  |
| 329 | `edittext_restrict_events` | 22 | 7.2s |  |
| 330 | `edittext_scrollh` | 10 | 7.2s |  |
| 331 | `edittext_selected_text` | 9 | 7.2s |  |
| 332 | `edittext_set_html_same` | 17 | 7.2s |  |
| 333 | `edittext_set_text_vs_html` | 9 | 7.1s |  |
| 334 | `edittext_stylesheet` | 536 | 7.5s |  |
| 335 | `edittext_stylesheet_custom_tag` | 76 | 7.2s |  |
| 336 | `edittext_stylesheet_display` | 272 | 7.3s |  |
| 337 | `edittext_underline` | 40 | 7.2s |  |
| 338 | `edittext_width_height` | 103 | 22.0s |  |
| 339 | `edittext_wordwrap_word` | 150 | 7.3s |  |
| 340 | `edittext_wrap_breaks` | 2375 | 7.5s |  |
| 341 | `empty_bounds` | 1 | 6.9s |  |
| 342 | `encode_uri_surrogate_pair_swf11` | 15 | 6.7s |  |
| 343 | `equals` | 512 | 10.9s |  |
| 344 | `error_geterrormessage` | 779 | 7.0s |  |
| 345 | `error_prototype` | 15 | 7.0s |  |
| 346 | `error_stack_trace_debug_swf17` | 0 | 25.2s |  |
| 347 | `error_stack_trace_debug_swf18` | 0 | 6.7s |  |
| 348 | `error_stack_trace_release_swf17` | 0 | 6.7s |  |
| 349 | `error_stack_trace_release_swf18` | 0 | 6.7s |  |
| 350 | `error_tostring` | 29 | 6.9s |  |
| 351 | `es3_inheritance` | 31 | 7.0s |  |
| 352 | `es4_inheritance` | 30 | 7.0s |  |
| 353 | `es4_interfaces` | 30 | 7.0s |  |
| 354 | `es4_method_binding` | 8 | 7.0s |  |
| 355 | `es4_oop_prototypes` | 14 | 7.1s |  |
| 356 | `es4_protected_inheritance` | 6 | 7.0s |  |
| 357 | `escape` | 71 | 7.0s |  |
| 358 | `event_bubbles` | 2 | 6.9s |  |
| 359 | `event_cancelable` | 2 | 6.8s |  |
| 360 | `event_clone` | 20 | 7.0s |  |
| 361 | `event_clone_error_redispatch` | 3 | 7.1s |  |
| 362 | `event_clone_on_redispatch` | 10 | 7.1s |  |
| 363 | `event_formattostring` | 31 | 7.0s |  |
| 364 | `event_isdefaultprevented` | 12 | 6.9s |  |
| 365 | `event_target_getter` | 5 | 3.0s |  |
| 366 | `event_target_set` | 9 | 6.9s |  |
| 367 | `event_type` | 1 | 23.2s |  |
| 368 | `event_valueof_tostring` | 18 | 7.6s |  |
| 369 | `eventdispatcher_dispatchevent` | 12 | 7.6s |  |
| 370 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.5s |  |
| 371 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.5s |  |
| 372 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.5s |  |
| 373 | `eventdispatcher_dispatchevent_this` | 5 | 7.5s |  |
| 374 | `eventdispatcher_haseventlistener` | 25 | 7.6s |  |
| 375 | `eventdispatcher_interface_invoke` | 1 | 7.4s |  |
| 376 | `eventdispatcher_tostring` | 10 | 7.5s |  |
| 377 | `eventdispatcher_willtrigger` | 25 | 7.3s |  |
| 378 | `falsiness` | 30 | 7.4s |  |
| 379 | `fast_index_access` | 12 | 7.5s |  |
| 380 | `filefilter_properties` | 4 | 7.4s |  |
| 381 | `filereference_browse_cancel` | 3 | 7.4s |  |
| 382 | `filereference_browse_select` | 9 | 7.4s |  |
| 383 | `filereference_load` | 31 | 7.5s |  |
| 384 | `filereference_save` | 16 | 7.6s |  |
| 385 | `filereference_save_and_browse` | 42 | 7.6s |  |
| 386 | `filereference_save_and_load` | 22 | 7.5s |  |
| 387 | `filereference_uninitialized` | 8 | 7.5s |  |
| 388 | `filereferencelist_browse_cancel` | 6 | 7.5s |  |
| 389 | `filereferencelist_browse_select` | 7 | 7.5s |  |
| 390 | `filter_rewind` | 8 | 7.9s |  |
| 391 | `filters_array_holes` | 25 | 7.7s |  |
| 392 | `finddef` | 3 | 7.7s |  |
| 393 | `findprop_global_prototype` | 6 | 7.6s |  |
| 394 | `flash_media_video_constructor` | 156 | 8.4s |  |
| 395 | `flash_media_video_rotation_probe` | 27 | 7.6s |  |
| 396 | `flash_xml` | 29 | 7.5s |  |
| 397 | `flash_xml_cloneNode` | 22 | 7.6s |  |
| 398 | `flash_xml_namespace` | 109 | 7.5s |  |
| 399 | `flash_xml_removeNode` | 60 | 7.5s |  |
| 400 | `focus_events_code` | 161 | 27.3s |  |
| 401 | `focus_events_key_basic` | 132 | 27.6s |  |
| 402 | `focus_events_key_navigation` | 53 | 7.6s |  |
| 403 | `focus_events_key_same_object` | 26 | 7.6s |  |
| 404 | `focus_events_mixed_key_mouse` | 100 | 26.9s |  |
| 405 | `focus_events_mouse_basic` | 260 | 43.2s |  |
| 406 | `focus_events_mouse_focusable` | 112 | 27.7s |  |
| 407 | `focus_events_mouse_same_object` | 40 | 27.2s |  |
| 408 | `focus_remove` | 20 | 27.2s |  |
| 409 | `focus_root_movie` | 4 | 27.1s |  |
| 410 | `focus_stage` | 1 | 7.4s |  |
| 411 | `focusrect` | 18 | 8.3s |  |
| 412 | `focusrect_focuslost` | 9 | 7.5s |  |
| 413 | `focusrect_property` | 110 | 7.5s |  |
| 414 | `font_description_clone` | 14 | 7.5s |  |
| 415 | `font_embedded` | 24 | 7.9s |  |
| 416 | `font_enumeratefonts` | 41 | 8.1s |  |
| 417 | `font_enumeratefonts_filter` | 4 | 27.9s |  |
| 418 | `font_hasglyphs` | 40 | 8.0s |  |
| 419 | `framelabel_constr` | 5 | 7.7s |  |
| 420 | `function_call` | 12 | 7.6s |  |
| 421 | `function_call_arguments` | 46 | 7.7s |  |
| 422 | `function_call_arguments_enumerate` | 5 | 7.4s |  |
| 423 | `function_call_coercion` | 108 | 8.0s |  |
| 424 | `function_call_default` | 6 | 7.5s |  |
| 425 | `function_call_rest` | 22 | 7.5s |  |
| 426 | `function_call_types` | 3 | 7.5s |  |
| 427 | `function_call_via_apply` | 11 | 7.6s |  |
| 428 | `function_call_via_call` | 3 | 7.5s |  |
| 429 | `function_display_anonymous` | 7 | 3.3s |  |
| 430 | `function_length` | 6 | 7.5s |  |
| 431 | `function_object` | 2 | 7.4s |  |
| 432 | `function_proto` | 5 | 7.2s |  |
| 433 | `function_proto_created` | 61 | 7.3s |  |
| 434 | `function_to_locale_string` | 4 | 7.3s |  |
| 435 | `function_to_string` | 4 | 7.2s |  |
| 436 | `function_type` | 6 | 7.3s |  |
| 437 | `function_unbound_this` | 51 | 7.5s |  |
| 438 | `function_value_of` | 4 | 7.2s |  |
| 439 | `get_definition_by_name` | 11 | 7.4s |  |
| 440 | `get_qualified_class_name` | 20 | 21.5s |  |
| 441 | `get_qualified_super_class_name` | 18 | 6.7s |  |
| 442 | `get_slot_edge_cases` | 1 | 25.2s |  |
| 443 | `get_timer` | 2 | 6.7s |  |
| 444 | `getglobalslot` | 1 | 6.6s |  |
| 445 | `getouterscope` | 8 | 6.7s |  |
| 446 | `getter_different_namespace_setter` | 2 | 6.6s |  |
| 447 | `glow_filter` | 127 | 6.9s |  |
| 448 | `goto_button_nested_framescript` | 28 | 26.7s |  |
| 449 | `goto_in_constructframe` | 12 | 7.0s |  |
| 450 | `goto_in_scene_last_frame` | 2 | 25.6s |  |
| 451 | `goto_methods` | 56 | 7.0s |  |
| 452 | `goto_methods_swfver10` | 8 | 6.7s |  |
| 453 | `goto_nested_construct_sibling` | 18 | 7.2s |  |
| 454 | `goto_nested_framescript` | 9 | 6.8s |  |
| 455 | `goto_on_orphan` | 15 | 6.9s |  |
| 456 | `gradient_bevel_filter` | 206 | 6.8s |  |
| 457 | `gradient_glow_filter` | 206 | 6.7s |  |
| 458 | `graphics_bad_direct_commands` | 5 | 7.6s |  |
| 459 | `graphics_bitmap_fill` | 0 | 8.6s |  |
| 460 | `graphics_bitmaps` | 0 | 7.4s |  |
| 461 | `graphics_direct_commands` | 0 | 7.3s |  |
| 462 | `graphics_draw_triangles` | 98 | 26.5s |  |
| 463 | `graphics_gradients` | 0 | 7.0s |  |
| 464 | `graphics_gradients_nulls` | 0 | 6.9s |  |
| 465 | `graphics_path` | 56 | 6.9s |  |
| 466 | `graphics_round_rects` | 0 | 6.8s |  |
| 467 | `graphics_simple_shapes` | 0 | 7.0s |  |
| 468 | `greaterequals` | 512 | 10.1s |  |
| 469 | `greaterthan` | 512 | 10.0s |  |
| 470 | `has_own_property` | 102 | 7.2s |  |
| 471 | `hasownproperty_namespaces` | 2 | 6.7s |  |
| 472 | `hello_world` | 1 | 6.7s |  |
| 473 | `hittest_morph` | 30 | 6.8s |  |
| 474 | `if_eq` | 10 | 6.8s |  |
| 475 | `if_gt` | 1 | 6.8s |  |
| 476 | `if_gte` | 10 | 22.8s |  |
| 477 | `if_lt` | 1 | 7.4s |  |
| 478 | `if_lte` | 10 | 7.3s |  |
| 479 | `if_ne` | 7 | 3.3s |  |
| 480 | `if_stricteq` | 6 | 7.4s |  |
| 481 | `if_strictne` | 11 | 7.4s |  |
| 482 | `ime_linux_dead_keys` | 10 | 7.5s |  |
| 483 | `in` | 102 | 7.8s |  |
| 484 | `inclocal` | 46 | 7.4s |  |
| 485 | `inclocal_i` | 46 | 7.4s |  |
| 486 | `increment` | 46 | 7.4s |  |
| 487 | `increment_i` | 46 | 7.4s |  |
| 488 | `indexing_delete` | 75 | 7.4s |  |
| 489 | `instanceof` | 58 | 7.7s |  |
| 490 | `instantiation_on_enter_frame` | 7 | 26.2s |  |
| 491 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.3s |  |
| 492 | `int_constr` | 92 | 7.6s |  |
| 493 | `int_edge_cases` | 19 | 7.4s |  |
| 494 | `int_instanceof` | 3 | 7.3s |  |
| 495 | `int_tofixed` | 1215 | 7.3s |  |
| 496 | `int_tostring` | 3375 | 7.7s |  |
| 497 | `interactiveobject_enabled` | 25 | 7.3s |  |
| 498 | `interface_namespaces` | 78 | 7.5s |  |
| 499 | `is_finite` | 46 | 7.4s |  |
| 500 | `is_nan` | 46 | 7.2s |  |
| 501 | `is_prototype_of` | 12 | 7.3s |  |
| 502 | `issue_10221` | 2 | 7.3s |  |
| 503 | `issue_13780` | 12 | 7.3s |  |
| 504 | `issue_14901` | 1 | 7.3s |  |
| 505 | `issue_17675_edittext_paste_maxchars` | 1 | 7.3s |  |
| 506 | `issue_5292` | 5 | 7.3s |  |
| 507 | `issue_8630` | 2 | 25.9s |  |
| 508 | `issue_8630_scriptremove` | 11 | 7.4s |  |
| 509 | `istype` | 24 | 3.2s |  |
| 510 | `istypelate` | 58 | 7.6s |  |
| 511 | `istypelate_coerce` | 198 | 23.8s |  |
| 512 | `jpeg_loader_context` | 6 | 7.4s |  |
| 513 | `json_errors` | 9 | 26.7s |  |
| 514 | `json_parse` | 21 | 7.5s |  |
| 515 | `json_stringify` | 12 | 7.7s |  |
| 516 | `json_stringify_order` | 1 | 7.5s |  |
| 517 | `json_version_gated` | 1 | 7.6s |  |
| 518 | `key_input_80percent` | 1812 | 7.7s |  |
| 519 | `key_input_location` | 126 | 7.5s |  |
| 520 | `key_input_numpad` | 384 | 7.4s |  |
| 521 | `lazyinit` | 17 | 7.5s |  |
| 522 | `lessequals` | 512 | 11.5s |  |
| 523 | `lessthan` | 512 | 11.2s |  |
| 524 | `loader_bitmap_transparency` | 14 | 7.6s |  |
| 525 | `loader_bytes_unknown_content` | 14 | 7.6s |  |
| 526 | `loader_child_getdefinition` | 5 | 7.8s |  |
| 527 | `loader_duplicate_coerce` | 3 | 7.7s |  |
| 528 | `loader_duplicate_coerce_new_domain` | 4 | 7.5s |  |
| 529 | `loader_error_in_root_ctor` | 4 | 7.7s |  |
| 530 | `loader_events` | 92 | 8.3s |  |
| 531 | `loader_image` | 8 | 7.9s |  |
| 532 | `loader_jpegxr` | 2 | 27.2s |  |
| 533 | `loader_jpegxr_alpha` | 1 | 26.7s |  |
| 534 | `loader_loadbytes_events` | 30 | 8.2s |  |
| 535 | `loader_loadbytes_invalid_png` | 4 | 26.5s |  |
| 536 | `loader_loadbytes_url` | 12 | 7.8s |  |
| 537 | `loader_loaderurl` | 6 | 8.0s |  |
| 538 | `loader_noninteractive_try_click_root` | 5 | 27.4s |  |
| 539 | `loader_reuse` | 38 | 7.7s |  |
| 540 | `loader_unknown_content` | 24 | 7.7s |  |
| 541 | `loader_visibility_interactive` | 1 | 7.7s |  |
| 542 | `loaderinfo_events` | 7 | 7.5s |  |
| 543 | `loaderinfo_loadurl` | 12 | 22.5s |  |
| 544 | `loaderinfo_more` | 6 | 7.7s |  |
| 545 | `loaderinfo_properties` | 18 | 7.4s |  |
| 546 | `loaderinfo_properties_not_loaded` | 23 | 7.6s |  |
| 547 | `loaderinfo_root` | 10 | 7.4s |  |
| 548 | `loaderinfo_root_allows` | 2 | 7.4s |  |
| 549 | `localconnection_send` | 4 | 7.7s |  |
| 550 | `lshift` | 1058 | 20.2s |  |
| 551 | `mask_reapply` | 1 | 7.7s |  |
| 552 | `math` | 497 | 7.9s |  |
| 553 | `matrix3d` | 57 | 8.5s |  |
| 554 | `matrix3d_compose` | 34 | 7.8s |  |
| 555 | `matrix3d_invert` | 18 | 7.5s |  |
| 556 | `missing_external_interface` | 10 | 7.7s |  |
| 557 | `modulo` | 1058 | 20.1s |  |
| 558 | `morph_shape` | 2 | 27.4s |  |
| 559 | `mouse_children` | 192 | 26.9s |  |
| 560 | `mouse_click_events` | 90 | 26.2s |  |
| 561 | `mouse_double_click_events` | 188 | 7.2s |  |
| 562 | `mouse_empty_parent` | 4 | 7.2s |  |
| 563 | `mouse_over_while_dragging` | 3 | 7.3s |  |
| 564 | `mouse_pick_button_mode` | 2 | 7.3s |  |
| 565 | `mouse_pick_dobj_mask` | 4 | 7.5s |  |
| 566 | `mouse_pick_masking` | 7 | 26.3s |  |
| 567 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 25.9s |  |
| 568 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.7s |  |
| 569 | `mouse_pick_text` | 8 | 7.6s |  |
| 570 | `mouse_sibling` | 8 | 7.4s |  |
| 571 | `mouse_wheel_events` | 36 | 27.9s |  |
| 572 | `mouseevent_constr` | 66 | 7.5s |  |
| 573 | `mouseevent_stagexy` | 35 | 7.5s |  |
| 574 | `mouseevent_valueof_tostring` | 28 | 7.6s |  |
| 575 | `movieclip_addframescript` | 3 | 27.7s |  |
| 576 | `movieclip_child_property` | 16 | 7.4s |  |
| 577 | `movieclip_constr` | 21 | 22.1s |  |
| 578 | `movieclip_currentlabels` | 17 | 25.2s |  |
| 579 | `movieclip_currentlabels_dupes1` | 46 | 25.5s |  |
| 580 | `movieclip_currentlabels_dupes2` | 30 | 7.0s |  |
| 581 | `movieclip_currentlabels_dupes3` | 67 | 7.0s |  |
| 582 | `movieclip_currentscene` | 12 | 7.2s |  |
| 583 | `movieclip_dispatchevent` | 430 | 7.2s |  |
| 584 | `movieclip_dispatchevent_cancel` | 102 | 7.2s |  |
| 585 | `movieclip_dispatchevent_handlerorder` | 251 | 7.1s |  |
| 586 | `movieclip_dispatchevent_selfadd` | 80 | 7.0s |  |
| 587 | `movieclip_dispatchevent_target` | 899 | 7.1s |  |
| 588 | `movieclip_displayevents` | 96 | 25.6s |  |
| 589 | `movieclip_displayevents_clickgoto` | 676 | 7.6s |  |
| 590 | `movieclip_displayevents_clickgoto2` | 2001 | 7.7s |  |
| 591 | `movieclip_displayevents_clickplay` | 575 | 7.3s |  |
| 592 | `movieclip_displayevents_clicksymbol` | 562 | 7.3s |  |
| 593 | `movieclip_displayevents_constructframegoto` | 140 | 7.5s |  |
| 594 | `movieclip_displayevents_constructframeplay` | 50 | 7.3s |  |
| 595 | `movieclip_displayevents_constructframesymbol` | 144 | 7.3s |  |
| 596 | `movieclip_displayevents_dblhandler` | 21 | 7.2s |  |
| 597 | `movieclip_displayevents_enterframegoto` | 149 | 7.2s |  |
| 598 | `movieclip_displayevents_enterframeplay` | 48 | 7.0s |  |
| 599 | `movieclip_displayevents_enterframesymbol` | 149 | 24.9s |  |
| 600 | `movieclip_displayevents_exitframegoto` | 106 | 7.0s |  |
| 601 | `movieclip_displayevents_exitframeplay` | 44 | 7.0s |  |
| 602 | `movieclip_displayevents_exitframesymbol` | 135 | 7.4s |  |
| 603 | `movieclip_displayevents_looping` | 63 | 24.6s |  |
| 604 | `movieclip_displayevents_stopped` | 113 | 7.1s |  |
| 605 | `movieclip_displayevents_swap` | 96 | 2.8s |  |
| 606 | `movieclip_displayevents_timeline` | 128 | 24.7s |  |
| 607 | `movieclip_drawrect` | 54 | 6.8s |  |
| 608 | `movieclip_frameconstruct_skipped` | 9 | 6.9s |  |
| 609 | `movieclip_goto_during_frame_script` | 15 | 6.8s |  |
| 610 | `movieclip_goto_overwrite` | 14 | 24.4s |  |
| 611 | `movieclip_goto_scene_last_frame_int` | 1 | 24.5s |  |
| 612 | `movieclip_goto_scene_last_frame_label` | 1 | 6.6s |  |
| 613 | `movieclip_gotoandplay` | 15 | 24.1s |  |
| 614 | `movieclip_gotoandstop` | 13 | 24.0s |  |
| 615 | `movieclip_gotoandstop_children` | 4 | 6.8s |  |
| 616 | `movieclip_gotoandstop_framescripts1` | 4 | 6.8s |  |
| 617 | `movieclip_gotoandstop_framescripts2` | 4 | 2.9s |  |
| 618 | `movieclip_gotoandstop_framescripts_self` | 7 | 41.8s |  |
| 619 | `movieclip_gotoandstop_queueing` | 12 | 26.2s |  |
| 620 | `movieclip_hittest` | 67 | 7.5s |  |
| 621 | `movieclip_next_frame` | 2 | 7.3s |  |
| 622 | `movieclip_next_scene` | 6 | 25.8s |  |
| 623 | `movieclip_play` | 3 | 7.1s |  |
| 624 | `movieclip_prev_frame` | 3 | 7.0s |  |
| 625 | `movieclip_prev_scene` | 7 | 7.1s |  |
| 626 | `movieclip_properties` | 79 | 7.4s |  |
| 627 | `movieclip_queued_noop_goto_swf10` | 9 | 7.1s |  |
| 628 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 629 | `movieclip_scenes` | 11 | 7.1s |  |
| 630 | `movieclip_soundtransform` | 831 | 29.0s |  |
| 631 | `movieclip_stop` | 1 | 7.1s |  |
| 632 | `movieclip_super_is_symbol` | 20 | 7.4s |  |
| 633 | `movieclip_symbol_constr` | 8 | 7.2s |  |
| 634 | `movieclip_text_mousedown` | 1 | 7.3s |  |
| 635 | `movieclip_willtrigger` | 5 | 7.3s |  |
| 636 | `multiply` | 1058 | 19.6s |  |
| 637 | `namespace_constr` | 253 | 7.5s |  |
| 638 | `namespace_constr_args` | 1 | 7.3s |  |
| 639 | `namespace_enumeration_order` | 7 | 7.5s |  |
| 640 | `nan_scale` | 9 | 7.2s |  |
| 641 | `navigateToURL_target_normalize` | 107 | 27.6s |  |
| 642 | `negate` | 30 | 7.3s |  |
| 643 | `negative_volume_panned` | 0 | 7.5s |  |
| 644 | `nested_iteration` | 11 | 7.3s |  |
| 645 | `net_getClassByAlias` | 3 | 7.4s |  |
| 646 | `net_navigateToURL` | 57 | 7.4s |  |
| 647 | `net_stream_play_options` | 6 | 7.5s |  |
| 648 | `netconnection_close` | 55 | 7.4s |  |
| 649 | `netconnection_properties` | 78 | 7.6s |  |
| 650 | `netconnection_send_remote` | 50 | 7.7s |  |
| 651 | `netconnection_serialize_arrays` | 6 | 7.5s |  |
| 652 | `netstream_client` | 10 | 7.5s |  |
| 653 | `netstream_connect` | 7 | 7.4s |  |
| 654 | `newactivation_in_script_init` | 3 | 5.0s |  |
| 655 | `newclass_twice` | 3 | 4.8s |  |
| 656 | `nonconflicting_declarations` | 0 | 4.9s |  |
| 657 | `null_void_types` | 8 | 5.2s |  |
| 658 | `number_autoconv` | 21 | 5.5s |  |
| 659 | `number_autoconv_amf` | 132 | 5.0s |  |
| 660 | `number_autoconv_array_sort_32bit` | 1 | 4.9s |  |
| 661 | `number_constr` | 58 | 5.8s |  |
| 662 | `number_toexponential` | 378 | 5.3s |  |
| 663 | `number_toexponential2` | 35 | 5.0s |  |
| 664 | `number_tofixed` | 378 | 5.3s |  |
| 665 | `number_toprecision` | 350 | 5.3s |  |
| 666 | `obfuscated_class_names` | 3 | 5.0s |  |
| 667 | `object_enumeration` | 10 | 4.9s |  |
| 668 | `object_prototype` | 4 | 5.0s |  |
| 669 | `object_to_locale_string` | 2 | 4.9s |  |
| 670 | `object_to_string` | 2 | 5.0s |  |
| 671 | `object_value_of` | 2 | 1.9s |  |
| 672 | `op_coerce` | 54 | 5.0s |  |
| 673 | `op_coerce_x` | 54 | 4.9s |  |
| 674 | `op_escxattr` | 2 | 5.3s |  |
| 675 | `op_escxelem` | 2 | 5.1s |  |
| 676 | `op_lookupswitch` | 4 | 4.8s |  |
| 677 | `optimize_coerce` | 1 | 5.0s |  |
| 678 | `orphan_movie_complex` | 80 | 5.9s |  |
| 679 | `orphan_movie_reorder` | 111 | 20.1s |  |
| 680 | `package_namespace` | 7 | 5.0s |  |
| 681 | `param_default_value_has_zero_cpool_index` | 1 | 4.9s |  |
| 682 | `parent_early_access_child` | 16 | 5.7s |  |
| 683 | `parse_float` | 81 | 5.0s |  |
| 684 | `perspective_projection_basic` | 40 | 5.3s |  |
| 685 | `pixelbender_ceil` | 77 | 5.2s |  |
| 686 | `pixelbender_conditional` | 138 | 22.5s |  |
| 687 | `pixelbender_conversions` | 270 | 7.5s |  |
| 688 | `pixelbender_dithering` | 8 | 31.9s |  |
| 689 | `pixelbender_div` | 36 | 7.3s |  |
| 690 | `pixelbender_effect_BlurredFocus` | 0 | 32.9s |  |
| 691 | `pixelbender_effect_glassDisplace` | 0 | 12.8s |  |
| 692 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 30.6s |  |
| 693 | `pixelbender_effect_smudge` | 0 | 10.6s |  |
| 694 | `pixelbender_effect_tintype` | 0 | 9.8s |  |
| 695 | `pixelbender_effect_twirl` | 0 | 10.9s |  |
| 696 | `pixelbender_eof` | 7 | 7.1s |  |
| 697 | `pixelbender_images` | 0 | 9.5s |  |
| 698 | `pixelbender_input` | 103 | 26.3s |  |
| 699 | `pixelbender_logicalnot` | 20 | 7.1s |  |
| 700 | `pixelbender_malformed_data` | 190 | 26.3s |  |
| 701 | `pixelbender_multiple_out_params` | 1 | 7.0s |  |
| 702 | `pixelbender_no_out_param` | 6 | 7.1s |  |
| 703 | `pixelbender_outputs` | 13 | 7.3s |  |
| 704 | `pixelbender_padding_bytes` | 22 | 7.2s |  |
| 705 | `pixelbender_param_qualifier` | 512 | 7.2s |  |
| 706 | `pixelbender_parameters` | 1563 | 7.4s |  |
| 707 | `pixelbender_parameters_bool` | 240 | 7.3s |  |
| 708 | `pixelbender_parameters_int_vs_bool` | 54 | 7.2s |  |
| 709 | `pixelbender_parse_errors` | 6 | 7.1s |  |
| 710 | `pixelbender_rsqrt` | 24 | 7.2s |  |
| 711 | `pixelbender_select_kinds` | 8 | 7.3s |  |
| 712 | `pixelbender_shaderdata` | 49 | 7.2s |  |
| 713 | `pixelbender_shaderdata_setter` | 99 | 7.5s |  |
| 714 | `pixelbender_sign` | 60 | 7.3s |  |
| 715 | `pixelbender_vector_output` | 11 | 7.3s |  |
| 716 | `place_multiple` | 17 | 25.5s |  |
| 717 | `place_object_replace` | 9 | 7.3s |  |
| 718 | `place_object_replace_2` | 24 | 7.3s |  |
| 719 | `place_object_same_depth_frame` | 1 | 7.2s |  |
| 720 | `point` | 132 | 7.7s |  |
| 721 | `primitive_edge_cases` | 1 | 7.1s |  |
| 722 | `property_priority` | 22 | 7.8s |  |
| 723 | `property_priority_three_level` | 6 | 26.6s |  |
| 724 | `propertyisenumerable_namespaces` | 6 | 7.5s |  |
| 725 | `prototype_set_null` | 7 | 7.5s |  |
| 726 | `proxy_callproperty` | 24 | 7.5s |  |
| 727 | `proxy_deleteproperty` | 64 | 7.6s |  |
| 728 | `proxy_enumeration` | 34 | 7.5s |  |
| 729 | `proxy_getproperty` | 77 | 7.5s |  |
| 730 | `proxy_hasownproperty` | 8 | 7.4s |  |
| 731 | `proxy_hasproperty` | 32 | 7.6s |  |
| 732 | `proxy_serialize` | 9 | 7.5s |  |
| 733 | `proxy_setproperty` | 42 | 7.5s |  |
| 734 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.5s |  |
| 735 | `qname_constr` | 32 | 7.5s |  |
| 736 | `qname_constr_namespace` | 24 | 7.4s |  |
| 737 | `qname_enumeration` | 9 | 7.4s |  |
| 738 | `qname_indexing` | 23 | 7.5s |  |
| 739 | `qname_tostring` | 25 | 7.4s |  |
| 740 | `qname_valueof` | 29 | 7.5s |  |
| 741 | `rectangle` | 1094 | 8.1s |  |
| 742 | `regexp_constr` | 148 | 7.7s |  |
| 743 | `regexp_exec` | 19 | 7.4s |  |
| 744 | `regexp_extended` | 47 | 7.3s |  |
| 745 | `regexp_multiargs` | 1 | 7.3s |  |
| 746 | `regexp_test` | 27 | 7.5s |  |
| 747 | `regexp_toString` | 10 | 7.5s |  |
| 748 | `register_script_refresh` | 35 | 8.1s |  |
| 749 | `remove_child_clear_field` | 88 | 7.9s |  |
| 750 | `remove_dobj` | 3 | 7.4s |  |
| 751 | `resolve_order` | 4 | 7.3s |  |
| 752 | `responder_null_callbacks` | 1 | 7.4s |  |
| 753 | `rng` | 1 | 8.8s |  |
| 754 | `rootless` | 42 | 7.5s |  |
| 755 | `rshift` | 1058 | 18.9s |  |
| 756 | `sandbox_type_inherited` | 2 | 7.8s |  |
| 757 | `sandbox_type_local_file` | 1 | 16.8s |  |
| 758 | `sandbox_type_local_network` | 1 | 5.2s |  |
| 759 | `scene_constr` | 8 | 5.5s |  |
| 760 | `selection` | 239 | 5.6s |  |
| 761 | `set_local_0` | 31 | 5.3s |  |
| 762 | `set_property_is_enumerable` | 85 | 6.0s |  |
| 763 | `shaderparameter_value` | 4 | 5.2s |  |
| 764 | `shape_drawrect` | 54 | 5.2s |  |
| 765 | `shared_object_no_root` | 3 | 5.3s |  |
| 766 | `simplebutton_added_to_stage` | 45 | 19.6s |  |
| 767 | `simplebutton_childevents` | 86 | 20.4s |  |
| 768 | `simplebutton_childevents_nested` | 54 | 5.2s |  |
| 769 | `simplebutton_childevents_sprite` | 13 | 5.0s |  |
| 770 | `simplebutton_childprops` | 144 | 5.0s |  |
| 771 | `simplebutton_childshuffle` | 23 | 5.1s |  |
| 772 | `simplebutton_constr` | 36 | 5.3s |  |
| 773 | `simplebutton_constr_childevents` | 48 | 5.2s |  |
| 774 | `simplebutton_constr_params` | 42 | 5.1s |  |
| 775 | `simplebutton_mouseenabled` | 26 | 4.8s |  |
| 776 | `simplebutton_multi_children` | 19 | 5.1s |  |
| 777 | `simplebutton_structure` | 27 | 5.0s |  |
| 778 | `simplebutton_symbolclass` | 68 | 5.3s |  |
| 779 | `slot_disp_id_shared_numbering` | 1 | 19.4s |  |
| 780 | `slots_force_autoassigned` | 1 | 5.1s |  |
| 781 | `socket_after_disconnect` | 1 | 5.4s |  |
| 782 | `socket_close` | 2 | 5.2s |  |
| 783 | `socket_connect` | 4 | 5.1s |  |
| 784 | `socket_errors` | 56 | 5.7s |  |
| 785 | `socket_read_big` | 48 | 5.2s |  |
| 786 | `socket_read_little` | 48 | 23.2s |  |
| 787 | `socket_read_write_object` | 8 | 7.5s |  |
| 788 | `socket_write_big` | 15 | 7.8s |  |
| 789 | `socket_write_little` | 14 | 7.5s |  |
| 790 | `sound_embeddedprops` | 26 | 7.9s |  |
| 791 | `sound_play` | 19 | 8.0s |  |
| 792 | `sound_valueof` | 33 | 7.7s |  |
| 793 | `soundchannel_soundtransform` | 835 | 29.7s |  |
| 794 | `soundchannel_soundtransform_exists` | 5 | 26.7s |  |
| 795 | `soundchannel_stop` | 8 | 7.8s |  |
| 796 | `soundmixer_buffertime` | 5 | 7.5s |  |
| 797 | `soundmixer_stopall` | 6 | 7.6s |  |
| 798 | `soundtransform` | 442 | 12.7s |  |
| 799 | `sprite_with_frames` | 0 | 27.8s |  |
| 800 | `stage3d_agal_cross_product` | 0 | 10.2s |  |
| 801 | `stage3d_agal_upload_errors` | 66 | 10.1s |  |
| 802 | `stage3d_bitmap` | 0 | 32.4s |  |
| 803 | `stage3d_blend` | 81 | 31.7s |  |
| 804 | `stage3d_context3d_string_args` | 158 | 8.5s |  |
| 805 | `stage3d_errors` | 7 | 7.6s |  |
| 806 | `stage3d_errors_atf` | 3 | 8.9s |  |
| 807 | `stage3d_errors_swf_29` | 6 | 7.8s |  |
| 808 | `stage3d_float1_index` | 0 | 29.8s |  |
| 809 | `stage3d_fractal` | 0 | 30.6s |  |
| 810 | `stage3d_ignore_sampler_override` | 0 | 30.7s |  |
| 811 | `stage3d_multistage_triangle` | 3 | 10.5s |  |
| 812 | `stage3d_program_constants_bytearray_be` | 0 | 31.3s |  |
| 813 | `stage3d_program_constants_bytearray_le` | 0 | 11.0s |  |
| 814 | `stage3d_program_constants_invalid_input` | 21 | 8.5s |  |
| 815 | `stage3d_raytrace` | 0 | 34.9s |  |
| 816 | `stage3d_rotating_cube` | 0 | 11.2s |  |
| 817 | `stage3d_sampler` | 0 | 10.4s |  |
| 818 | `stage3d_sampler_partial_upload` | 0 | 25.6s |  |
| 819 | `stage3d_stencil` | 0 | 30.4s |  |
| 820 | `stage3d_texture` | 0 | 15.9s |  |
| 821 | `stage3d_texture_bytearray` | 0 | 11.6s |  |
| 822 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.9s |  |
| 823 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 12.3s |  |
| 824 | `stage3d_triangle` | 0 | 10.4s |  |
| 825 | `stage3d_triangle_bytes4` | 0 | 10.2s |  |
| 826 | `stage3d_triangle_float1` | 0 | 10.2s |  |
| 827 | `stage3d_triangle_index_upload` | 0 | 10.2s |  |
| 828 | `stage3d_x_y` | 22 | 7.5s |  |
| 829 | `stage_access` | 10 | 7.4s |  |
| 830 | `stage_displayobject_properties` | 24 | 7.3s |  |
| 831 | `stage_framerate_nan` | 7 | 7.5s |  |
| 832 | `stage_framerate_negative` | 6 | 7.3s |  |
| 833 | `stage_framerate_zero` | 6 | 7.3s |  |
| 834 | `stage_invalidate` | 38 | 7.5s |  |
| 835 | `stage_loaderinfo_properties` | 24 | 7.6s |  |
| 836 | `stage_mousechildren` | 2 | 7.3s |  |
| 837 | `stage_mouseenabled` | 15 | 7.3s |  |
| 838 | `stage_overriden_setters` | 31 | 7.5s |  |
| 839 | `stage_properties` | 30 | 7.3s |  |
| 840 | `stage_stage3Ds_vector` | 1 | 26.0s |  |
| 841 | `static_var_with_this_in_ctor` | 2 | 7.2s |  |
| 842 | `stored_properties` | 11 | 7.2s |  |
| 843 | `strict_equality` | 34 | 7.2s |  |
| 844 | `string_call` | 13 | 7.2s |  |
| 845 | `string_case` | 23 | 7.2s |  |
| 846 | `string_char_at` | 27 | 7.2s |  |
| 847 | `string_char_code_at` | 28 | 7.1s |  |
| 848 | `string_concat_fromcharcode` | 37 | 7.2s |  |
| 849 | `string_constr` | 25 | 7.2s |  |
| 850 | `string_indexof_lastindexof` | 87 | 7.4s |  |
| 851 | `string_length` | 16 | 23.0s |  |
| 852 | `string_locale_compare` | 39 | 7.7s |  |
| 853 | `string_match` | 51 | 7.7s |  |
| 854 | `string_relational_compare` | 4 | 7.5s |  |
| 855 | `string_replace` | 51 | 7.6s |  |
| 856 | `string_search` | 41 | 7.5s |  |
| 857 | `string_slice_substr_substring` | 170 | 8.4s |  |
| 858 | `string_split` | 29 | 7.5s |  |
| 859 | `string_substr_negative` | 21 | 7.3s |  |
| 860 | `string_substr_weird` | 182 | 7.3s |  |
| 861 | `subtract` | 1058 | 18.9s |  |
| 862 | `super_get_call` | 12 | 7.6s |  |
| 863 | `supercall_two_classobjects` | 2 | 7.5s |  |
| 864 | `swf8` | 1 | 7.4s |  |
| 865 | `swf_10_queued_goto_scripts_construct` | 52 | 7.8s |  |
| 866 | `swf_9_goto_in_enter_frame` | 17 | 7.5s |  |
| 867 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.5s |  |
| 868 | `swf_9_queued_goto_scripts` | 6 | 7.6s |  |
| 869 | `swf_9_queued_goto_scripts_construct` | 28 | 1.4s |  |
| 870 | `swf_9_versioning` | 2 | 7.4s |  |
| 871 | `swf_wrong_frame_count` | 38 | 7.8s |  |
| 872 | `swf_wrong_frame_count_isplaying` | 22 | 26.1s |  |
| 873 | `symbol_class_binary_data` | 8 | 7.4s |  |
| 874 | `symbol_class_conflict` | 4 | 7.9s |  |
| 875 | `symbol_class_root_not_zero` | 1 | 7.3s |  |
| 876 | `symbolclass_invalid_utf8` | 2 | 7.3s |  |
| 877 | `tab_ordering_arrows` | 998 | 28.1s |  |
| 878 | `tab_ordering_automatic_advanced` | 184 | 41.3s |  |
| 879 | `tab_ordering_automatic_basic` | 45 | 6.9s |  |
| 880 | `tab_ordering_children` | 116 | 7.0s |  |
| 881 | `tab_ordering_custom_basic` | 34 | 6.8s |  |
| 882 | `tab_ordering_stage_tab_children` | 32 | 7.0s |  |
| 883 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.9s |  |
| 884 | `tab_ordering_tabbable` | 47 | 7.0s |  |
| 885 | `text_engine_fontdescription` | 27 | 7.1s |  |
| 886 | `text_run` | 7 | 6.9s |  |
| 887 | `textbox_click` | 37 | 25.8s |  |
| 888 | `textfield_event` | 66 | 6.9s |  |
| 889 | `textfield_focusin_event` | 9 | 6.8s |  |
| 890 | `textfield_input_dead_keys_windows` | 15 | 6.6s |  |
| 891 | `textfield_unload` | 39 | 25.7s |  |
| 892 | `textformat` | 1134 | 7.0s |  |
| 893 | `textformat_display` | 14 | 6.9s |  |
| 894 | `textformat_font_max_length` | 4 | 6.6s |  |
| 895 | `throw` | 3 | 6.8s |  |
| 896 | `timeline_scripts` | 3 | 6.8s |  |
| 897 | `timer` | 90 | 7.8s |  |
| 898 | `timer_events` | 3 | 6.8s |  |
| 899 | `timer_finished` | 11 | 7.1s |  |
| 900 | `timer_reset` | 8 | 7.1s |  |
| 901 | `timer_setdelay` | 5 | 7.0s |  |
| 902 | `trace` | 12 | 6.6s |  |
| 903 | `truthiness` | 30 | 6.0s |  |
| 904 | `try_catch` | 11 | 18.2s |  |
| 905 | `try_catch_typed` | 12 | 5.0s |  |
| 906 | `typeof` | 30 | 5.0s |  |
| 907 | `uint_constr` | 92 | 5.2s |  |
| 908 | `uint_tofixed` | 1215 | 4.8s |  |
| 909 | `uint_tostring` | 3375 | 5.3s |  |
| 910 | `unchecked_function` | 15 | 5.0s |  |
| 911 | `unescape` | 28 | 4.9s |  |
| 912 | `url_loader` | 25 | 5.0s |  |
| 913 | `urlrequest` | 18 | 4.9s |  |
| 914 | `urlstream_basic` | 5 | 5.0s |  |
| 915 | `urshift` | 1058 | 13.2s |  |
| 916 | `utils3d` | 7 | 5.3s |  |
| 917 | `vector3d` | 397 | 8.1s |  |
| 918 | `vector_class` | 36 | 5.7s |  |
| 919 | `vector_class_call` | 11 | 5.1s |  |
| 920 | `vector_coercion` | 66 | 5.6s |  |
| 921 | `vector_concat` | 90 | 5.4s |  |
| 922 | `vector_constr` | 107 | 5.6s |  |
| 923 | `vector_enumeration` | 5 | 4.9s |  |
| 924 | `vector_every` | 92 | 5.6s |  |
| 925 | `vector_filter` | 95 | 5.6s |  |
| 926 | `vector_holes` | 24 | 5.0s |  |
| 927 | `vector_indexof` | 302 | 7.9s |  |
| 928 | `vector_insertat` | 270 | 5.7s |  |
| 929 | `vector_int_access` | 4 | 4.9s |  |
| 930 | `vector_int_delete` | 11 | 5.0s |  |
| 931 | `vector_join` | 58 | 5.5s |  |
| 932 | `vector_lastindexof` | 302 | 5.0s |  |
| 933 | `vector_legacy` | 10 | 5.2s |  |
| 934 | `vector_map` | 85 | 5.5s |  |
| 935 | `vector_object_final` | 1 | 5.2s |  |
| 936 | `vector_object_toString` | 10 | 4.9s |  |
| 937 | `vector_pushpop` | 255 | 5.8s |  |
| 938 | `vector_reborrow_bug` | 10 | 4.9s |  |
| 939 | `vector_removeat` | 172 | 24.1s |  |
| 940 | `vector_reverse` | 232 | 8.6s |  |
| 941 | `vector_shiftunshift` | 252 | 8.7s |  |
| 942 | `vector_slice` | 331 | 9.2s |  |
| 943 | `vector_sort` | 905 | 16.6s |  |
| 944 | `vector_splice` | 693 | 11.3s |  |
| 945 | `vector_splice_fixed_bug_compat` | 4 | 7.6s |  |
| 946 | `vector_tostring` | 79 | 8.1s |  |
| 947 | `verification` | 8 | 7.7s |  |
| 948 | `verify_abnormal_loop` | 1 | 7.4s |  |
| 949 | `verify_dxns_without_flag` | 3 | 7.8s |  |
| 950 | `verify_exception_targets_edge_case` | 1 | 7.3s |  |
| 951 | `verify_jump_to_middle_of_op` | 1 | 7.3s |  |
| 952 | `verify_lookup_switch_edge_case` | 1 | 7.3s |  |
| 953 | `verify_stack` | 5 | 7.7s |  |
| 954 | `verify_unreachable_exception` | 2 | 7.4s |  |
| 955 | `versioned_isplaying` | 2 | 7.4s |  |
| 956 | `virtual_properties` | 16 | 7.5s |  |
| 957 | `with` | 4 | 7.3s |  |
| 958 | `wrong_arg_count` | 7 | 7.5s |  |
| 959 | `xml_abstract_equality` | 36 | 7.6s |  |
| 960 | `xml_advanced` | 52 | 7.3s |  |
| 961 | `xml_appendchild` | 10 | 7.3s |  |
| 962 | `xml_as_attribute` | 9 | 7.3s |  |
| 963 | `xml_attribute` | 35 | 7.5s |  |
| 964 | `xml_attribute_name` | 40 | 7.3s |  |
| 965 | `xml_basic` | 33 | 7.4s |  |
| 966 | `xml_child` | 25 | 7.4s |  |
| 967 | `xml_childindex` | 7 | 7.3s |  |
| 968 | `xml_children` | 43 | 7.9s |  |
| 969 | `xml_class_call` | 9 | 7.3s |  |
| 970 | `xml_contains` | 197 | 7.5s |  |
| 971 | `xml_copy` | 20 | 3.3s |  |
| 972 | `xml_ctor_from_tostring` | 23 | 22.4s |  |
| 973 | `xml_delete` | 114 | 7.0s |  |
| 974 | `xml_descendants` | 83 | 7.0s |  |
| 975 | `xml_elements` | 6 | 6.9s |  |
| 976 | `xml_equals_namespace_check` | 2 | 7.0s |  |
| 977 | `xml_explicit_use_namespace` | 5 | 7.0s |  |
| 978 | `xml_getdescendants_qname` | 21 | 6.9s |  |
| 979 | `xml_has_property_via_in` | 26 | 7.0s |  |
| 980 | `xml_hasownproperty` | 6 | 6.9s |  |
| 981 | `xml_ignore_white` | 6 | 7.0s |  |
| 982 | `xml_length` | 2 | 7.0s |  |
| 983 | `xml_list_as_attribute` | 9 | 7.0s |  |
| 984 | `xml_list_concat` | 20 | 7.0s |  |
| 985 | `xml_list_enumerate` | 4 | 6.8s |  |
| 986 | `xml_methods_settings` | 3 | 6.9s |  |
| 987 | `xml_mismatched_tag` | 37 | 7.0s |  |
| 988 | `xml_namespace` | 39 | 6.9s |  |
| 989 | `xml_namespace_methods` | 245 | 7.0s |  |
| 990 | `xml_namespaced_property` | 7 | 6.9s |  |
| 991 | `xml_no_namespace` | 1 | 6.8s |  |
| 992 | `xml_nodekind` | 3 | 6.9s |  |
| 993 | `xml_normalize` | 35 | 7.0s |  |
| 994 | `xml_notification_bubbling` | 361 | 6.9s |  |
| 995 | `xml_parent` | 8 | 6.8s |  |
| 996 | `xml_set_children` | 17 | 7.0s |  |
| 997 | `xml_set_name` | 34 | 6.8s |  |
| 998 | `xml_settings` | 6 | 2.8s |  |
| 999 | `xml_simple_complex_content` | 47 | 6.8s |  |
| 1000 | `xml_socket` | 11 | 7.0s |  |
| 1001 | `xml_text` | 7 | 6.8s |  |
| 1002 | `xml_tostring` | 6 | 6.8s |  |
| 1003 | `xml_tostring_namespace` | 12 | 6.9s |  |
| 1004 | `xml_unescaping` | 23 | 6.9s |  |
| 1005 | `xml_weird_ignores` | 54 | 7.0s |  |
| 1006 | `xml_wildcard` | 11 | 6.8s |  |
| 1007 | `xmldocument` | 254 | 7.0s |  |
| 1008 | `xmlnode` | 3540 | 7.1s |  |
| 1009 | `zero_frame_clip` | 3 | 7.3s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 7.1s |  |
| 3 | `blend_transform` | 1 | 1 | 7.3s |  |
| 4 | `coerce_property` | 3 | 3 | 7.5s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.4s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 7.5s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.4s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 41.0s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 7.3s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.0s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 7.1s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 7.5s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 26.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 26.7s |  |
| 15 | `int_toexponential` | 76 | 76 | 7.6s |  |
| 16 | `int_toprecision` | 441 | 441 | 7.6s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 5.0s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 5.0s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 19.0s |  |
| 20 | `soundchannel_position` | 74 | 74 | 29.1s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 8.1s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 7.6s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 27.0s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.2s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.1s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 25.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**54 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `parse_int` | 98.5% | 133 | 135 | 2 |  |
| 5 | `error_tostring_more` | 97.7% | 84 | 86 | 2 |  |
| 6 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 7 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 8 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 9 | `property_is_enumerable_reset` | 95.7% | 22 | 23 | 1 |  |
| 10 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 12 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 13 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 14 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 15 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 16 | `place_and_lookup/swf10` | 90.9% | 30 | 33 | 3 |  |
| 17 | `place_and_lookup/swf9` | 90.9% | 30 | 33 | 3 |  |
| 18 | `flash_media_video_setter` | 90.0% | 36 | 40 | 4 |  |
| 19 | `core_exceptions` | 87.2% | 41 | 47 | 6 |  |
| 20 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 21 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 22 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 23 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 24 | `displayobject_opaque_background` | 83.3% | 5 | 6 | 1 |  |
| 25 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 26 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 28 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 29 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 30 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 31 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 32 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 33 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 34 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 35 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 36 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 37 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 38 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 39 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 40 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 41 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 42 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 43 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 44 | `displayobject_scrollrect` | 57.6% | 19 | 33 | 14 |  |
| 45 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 46 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 47 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 48 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 49 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 50 | `applicationdomain_hasdefinition_null` | 50.0% | 1 | 2 | 1 |  |
| 51 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 52 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 53 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 54 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 28.1s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.3s |  |
| 3 | `verify_typecheck` | exit code 1 | 7.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**184 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `parse_int` | 98.5% | 133/135 | 135 | 135 |  |
| 5 | `error_tostring_more` | 97.7% | 84/86 | 86 | 86 |  |
| 6 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 7 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 8 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 9 | `property_is_enumerable_reset` | 95.7% | 22/23 | 23 | 23 |  |
| 10 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 11 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 12 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 13 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 14 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 15 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 16 | `place_and_lookup/swf10` | 90.9% | 30/33 | 33 | 33 |  |
| 17 | `place_and_lookup/swf9` | 90.9% | 30/33 | 33 | 33 |  |
| 18 | `flash_media_video_setter` | 90.0% | 36/40 | 40 | 40 |  |
| 19 | `core_exceptions` | 87.2% | 41/47 | 46 | 47 |  |
| 20 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 21 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 22 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 23 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 24 | `displayobject_opaque_background` | 83.3% | 5/6 | 6 | 6 |  |
| 25 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 26 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 27 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 28 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 29 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 30 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 31 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 32 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 33 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 34 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 35 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 36 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 37 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 38 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 39 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 40 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 41 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 42 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 43 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 44 | `displayobject_scrollrect` | 57.6% | 19/33 | 33 | 33 |  |
| 45 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 46 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 47 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 48 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 49 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 50 | `applicationdomain_hasdefinition_null` | 50.0% | 1/2 | 2 | 2 |  |
| 51 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 52 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 53 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 54 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 55 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 56 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 57 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 58 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 59 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 60 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 61 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 62 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 63 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 64 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 65 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 66 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 67 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 68 | `stage_domain_getQualifiedDefinitionNames` | 20.0% | 1/5 | 1 | 5 |  |
| 69 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 70 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 71 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 72 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 73 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 74 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 75 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 76 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 77 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 78 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 79 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 80 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 81 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 82 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 83 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 84 | `element_format_constructor_order` | 6.2% | 4/64 | 49 | 64 |  |
| 85 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 86 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 87 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 88 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 89 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 90 | `textline_validity` | 4.3% | 7/162 | 7 | 162 |  |
| 91 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 92 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 93 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 94 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 95 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 96 | `text_engine_groupelement` | 1.6% | 1/64 | 1 | 64 |  |
| 97 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 98 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 99 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 100 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 101 | `all_classes/display/swf9` | 0.1% | 2/1959 | 350 | 1959 |  |
| 102 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 103 | `all_classes/events/swf9` | 0.1% | 1/1030 | 184 | 1030 |  |
| 104 | `all_classes/events/swf30` | 0.1% | 2/2353 | 184 | 2353 |  |
| 105 | `all_classes/display/swf10` | 0.1% | 2/2569 | 350 | 2569 |  |
| 106 | `all_classes/display/swf11` | 0.1% | 2/2593 | 350 | 2593 |  |
| 107 | `all_classes/display/swf12` | 0.1% | 2/2593 | 350 | 2593 |  |
| 108 | `all_classes/display/swf13` | 0.1% | 2/2671 | 350 | 2671 |  |
| 109 | `all_classes/events/swf10` | 0.1% | 1/1638 | 184 | 1638 |  |
| 110 | `all_classes/events/swf11` | 0.1% | 1/1750 | 184 | 1750 |  |
| 111 | `all_classes/events/swf12` | 0.1% | 1/1814 | 184 | 1814 |  |
| 112 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 113 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 114 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 115 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 116 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 117 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 118 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 119 | `all_classes/display/swf30` | 0.0% | 0/2936 | 350 | 2936 |  |
| 120 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 121 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 122 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 123 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 124 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 125 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 126 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 127 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 128 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 129 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 130 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 131 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 132 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 133 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 134 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 135 | `content_element_basic` | 0.0% | 0/50 | 0 | 50 |  |
| 136 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 137 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 138 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 139 | `east_asian_justifier_clone` | 0.0% | 0/8 | 0 | 8 |  |
| 140 | `element_format_clone` | 0.0% | 0/44 | 0 | 44 |  |
| 141 | `element_format_properties` | 0.0% | 0/235 | 0 | 235 |  |
| 142 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 143 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 144 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 145 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 146 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 147 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 148 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 149 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 150 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 151 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 152 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 153 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 154 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 155 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 156 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 157 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 158 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 159 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 160 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 161 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 162 | `space_justifier_clone` | 0.0% | 0/12 | 0 | 12 |  |
| 163 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 164 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 165 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 166 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 167 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 168 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 169 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 170 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 171 | `tabstop_properties` | 0.0% | 0/105 | 0 | 105 |  |
| 172 | `text_element_basic` | 0.0% | 0/34 | 0 | 34 |  |
| 173 | `textblock_createline_errors` | 0.0% | 0/23 | 0 | 23 |  |
| 174 | `textblock_createline_fte` | 0.0% | 0/9 | 0 | 9 |  |
| 175 | `textblock_properties` | 0.0% | 0/118 | 0 | 118 |  |
| 176 | `textline_inapplicable_properties` | 0.0% | 0/10 | 0 | 10 |  |
| 177 | `textline_name` | 0.0% | 0/1 | 0 | 1 |  |
| 178 | `textline_splitting_basic` | 0.0% | 0/76 | 0 | 76 |  |
| 179 | `textline_throwerror` | 0.0% | 0/30 | 0 | 30 |  |
| 180 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 181 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 182 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 183 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 184 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
