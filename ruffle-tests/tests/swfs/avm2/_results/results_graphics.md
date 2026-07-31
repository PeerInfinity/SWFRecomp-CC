# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-31 01:35 UTC

**Git SHA**: `b3d9eda9f3`

**Run Duration**: 186m 12s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1222 |
| Passing | **1026** (84.0%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1052** (86.1%) |
| Failing | 170 |
| Total expected lines | 151259 |
| Matching lines | 117570 (77.7%) |
| Mismatched lines | 33689 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 167 | 98.2% |
| Runtime Error | 3 | 1.8% |

## Passing Tests

**1026 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 1058 | 18.7s |  |
| 2 | `agal_compiler` | 13 | 9.7s |  |
| 3 | `air_datagram_socket` | 1 | 8.2s |  |
| 4 | `air_hidden_lookup` | 2 | 7.4s |  |
| 5 | `all_classes/security/swf11` | 3 | 7.4s |  |
| 6 | `amf_array_serialization` | 17 | 9.4s |  |
| 7 | `amf_custom_obj` | 26 | 7.5s |  |
| 8 | `amf_dictionary` | 9 | 7.4s |  |
| 9 | `amf_function` | 46 | 7.4s |  |
| 10 | `amf_invalid_date` | 2 | 7.3s |  |
| 11 | `amf_missing_prop` | 6 | 7.4s |  |
| 12 | `amf_nondynamic_function_prop` | 6 | 7.1s |  |
| 13 | `amf_setter_error` | 8 | 7.2s |  |
| 14 | `amf_vector` | 40 | 7.3s |  |
| 15 | `amf_xml` | 6 | 7.3s |  |
| 16 | `application_domain` | 4 | 7.4s |  |
| 17 | `array_access` | 18 | 7.2s |  |
| 18 | `array_access_interpreter` | 4 | 7.1s |  |
| 19 | `array_access_no_pubns` | 2 | 7.0s |  |
| 20 | `array_concat` | 41 | 7.4s |  |
| 21 | `array_constr` | 10 | 7.3s |  |
| 22 | `array_delete` | 44 | 7.5s |  |
| 23 | `array_enumeration` | 10 | 7.2s |  |
| 24 | `array_enumeration_elements` | 11 | 7.1s |  |
| 25 | `array_every` | 8 | 7.1s |  |
| 26 | `array_filter` | 6 | 7.1s |  |
| 27 | `array_foreach` | 18 | 7.1s |  |
| 28 | `array_hasownproperty` | 11 | 3.1s |  |
| 29 | `array_holes` | 9 | 7.2s |  |
| 30 | `array_index_max` | 84 | 7.3s |  |
| 31 | `array_indexof` | 25 | 7.4s |  |
| 32 | `array_join` | 26 | 7.3s |  |
| 33 | `array_lastindexof` | 29 | 7.2s |  |
| 34 | `array_length` | 14 | 7.1s |  |
| 35 | `array_literal` | 3 | 7.1s |  |
| 36 | `array_map` | 8 | 7.0s |  |
| 37 | `array_pop` | 52 | 7.2s |  |
| 38 | `array_push` | 24 | 7.3s |  |
| 39 | `array_reborrow_bug` | 6 | 7.3s |  |
| 40 | `array_reverse` | 28 | 7.4s |  |
| 41 | `array_shift` | 51 | 3.3s |  |
| 42 | `array_slice` | 39 | 7.2s |  |
| 43 | `array_some` | 8 | 7.1s |  |
| 44 | `array_sort` | 297 | 7.6s |  |
| 45 | `array_sort_fun_swf12` | 2 | 7.2s |  |
| 46 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 47 | `array_sort_random` | 210 | 7.2s |  |
| 48 | `array_sort_swf10_32bit` | 1 | 7.2s |  |
| 49 | `array_sorton` | 545 | 8.2s |  |
| 50 | `array_sparse_ops` | 41 | 7.6s |  |
| 51 | `array_splice` | 133 | 7.6s |  |
| 52 | `array_splice2` | 428 | 7.9s |  |
| 53 | `array_splice_types` | 48 | 7.5s |  |
| 54 | `array_storage` | 8 | 7.3s |  |
| 55 | `array_tolocalestring` | 9 | 7.4s |  |
| 56 | `array_tostring` | 12 | 7.3s |  |
| 57 | `array_unshift` | 24 | 7.4s |  |
| 58 | `array_valueof` | 9 | 7.4s |  |
| 59 | `array_vector_null_callback` | 10 | 7.3s |  |
| 60 | `astype` | 28 | 7.4s |  |
| 61 | `astypelate` | 24 | 7.5s |  |
| 62 | `astypelate_propagates` | 1 | 7.4s |  |
| 63 | `asymmetric_key_events` | 11 | 7.6s |  |
| 64 | `av_networking_params` | 9 | 7.4s |  |
| 65 | `avm2_catchup_dobj` | 158 | 8.0s |  |
| 66 | `away3d_advanced_shallow_water_demo` | 0 | 85.4s |  |
| 67 | `bevel_filter` | 187 | 7.5s |  |
| 68 | `bitand` | 1058 | 18.8s |  |
| 69 | `bitmap_constr` | 17 | 7.7s |  |
| 70 | `bitmap_data` | 1000 | 15.2s |  |
| 71 | `bitmap_pixelsnapping` | 2 | 26.8s |  |
| 72 | `bitmap_properties` | 23 | 7.4s |  |
| 73 | `bitmap_subclass` | 7 | 8.9s |  |
| 74 | `bitmap_subclass_properties` | 9 | 7.9s |  |
| 75 | `bitmap_timeline` | 9 | 7.6s |  |
| 76 | `bitmapdata_accuracy` | 1 | 50.4s |  |
| 77 | `bitmapdata_applyfilter_blur` | 0 | 28.5s |  |
| 78 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.5s |  |
| 79 | `bitmapdata_applyfilter_destpoint` | 0 | 27.7s |  |
| 80 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 28.0s |  |
| 81 | `bitmapdata_clone` | 13 | 7.8s |  |
| 82 | `bitmapdata_colortransform` | 0 | 8.1s |  |
| 83 | `bitmapdata_colortransform_oob` | 2 | 7.4s |  |
| 84 | `bitmapdata_constr` | 22 | 3.4s |  |
| 85 | `bitmapdata_constructor_from_timeline` | 1 | 7.9s |  |
| 86 | `bitmapdata_copychannel` | 0 | 29.0s |  |
| 87 | `bitmapdata_copypixels` | 23 | 27.6s |  |
| 88 | `bitmapdata_copypixels_blend_over` | 1 | 7.1s |  |
| 89 | `bitmapdata_copypixelstobytearray` | 39 | 7.2s |  |
| 90 | `bitmapdata_dispose` | 7 | 7.2s |  |
| 91 | `bitmapdata_draw` | 0 | 26.8s |  |
| 92 | `bitmapdata_draw_colortransform` | 0 | 7.5s |  |
| 93 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.2s |  |
| 94 | `bitmapdata_draw_filters` | 0 | 25.9s |  |
| 95 | `bitmapdata_draw_masks` | 0 | 7.2s |  |
| 96 | `bitmapdata_draw_rotation` | 0 | 7.4s |  |
| 97 | `bitmapdata_draw_self_via_graphic` | 0 | 7.4s |  |
| 98 | `bitmapdata_draw_stage` | 0 | 25.9s |  |
| 99 | `bitmapdata_drawwithquality` | 0 | 7.4s |  |
| 100 | `bitmapdata_embedded` | 9 | 7.5s |  |
| 101 | `bitmapdata_fillrect` | 0 | 7.4s |  |
| 102 | `bitmapdata_filter_sourcerect` | 0 | 22.4s |  |
| 103 | `bitmapdata_floodfill` | 35 | 7.1s |  |
| 104 | `bitmapdata_getpixels` | 39 | 26.1s |  |
| 105 | `bitmapdata_getvector` | 27 | 3.1s |  |
| 106 | `bitmapdata_histogram` | 59 | 3.1s |  |
| 107 | `bitmapdata_hittest` | 112 | 7.7s |  |
| 108 | `bitmapdata_hittest_threshold` | 18 | 7.2s |  |
| 109 | `bitmapdata_opaque` | 0 | 7.4s |  |
| 110 | `bitmapdata_pixeldissolve` | 1037 | 7.8s |  |
| 111 | `bitmapdata_pixeldissolve_image` | 0 | 7.5s |  |
| 112 | `bitmapdata_rectangle_rounding` | 16 | 7.0s |  |
| 113 | `bitmapdata_setpixels` | 286 | 7.3s |  |
| 114 | `bitmapdata_setvector` | 26 | 7.1s |  |
| 115 | `bitmapdata_sync` | 0 | 26.2s |  |
| 116 | `bitmapdata_threshold` | 176 | 7.8s |  |
| 117 | `bitnot` | 46 | 7.2s |  |
| 118 | `bitor` | 1058 | 19.3s |  |
| 119 | `bitxor` | 1058 | 19.4s |  |
| 120 | `blend_mode_null` | 1 | 7.0s |  |
| 121 | `blend_multiply_alpha` | 0 | 7.4s |  |
| 122 | `blend_scroll` | 0 | 7.4s |  |
| 123 | `blend_shader_luma_lighten` | 3 | 7.8s |  |
| 124 | `blur_filter` | 43 | 5.8s |  |
| 125 | `boolean_constr` | 32 | 5.8s |  |
| 126 | `boolean_negation` | 30 | 5.7s |  |
| 127 | `boolean_tostring` | 8 | 5.7s |  |
| 128 | `broadcast_event` | 7 | 5.8s |  |
| 129 | `button_bounds` | 1 | 5.7s |  |
| 130 | `button_hittest` | 2 | 20.4s |  |
| 131 | `button_nested_frame` | 48 | 20.6s |  |
| 132 | `bytearray` | 48 | 6.0s |  |
| 133 | `bytearray_compress` | 31 | 5.7s |  |
| 134 | `bytearray_errors` | 24 | 5.8s |  |
| 135 | `bytearray_method_serialization` | 1 | 5.7s |  |
| 136 | `bytearray_oom` | 3 | 5.7s |  |
| 137 | `bytearray_readobject_amf0` | 50 | 5.8s |  |
| 138 | `bytearray_readobject_amf3` | 53 | 5.7s |  |
| 139 | `bytearray_readutf8bytes_with_bom` | 16 | 5.7s |  |
| 140 | `bytearray_serialization` | 3 | 5.7s |  |
| 141 | `bytearray_string_null` | 19 | 5.9s |  |
| 142 | `bytearray_tostring` | 15 | 5.7s |  |
| 143 | `bytearray_utf16` | 8 | 5.7s |  |
| 144 | `bytearray_writeobject` | 24 | 5.6s |  |
| 145 | `callee_in_initializer` | 6 | 5.6s |  |
| 146 | `callproplex_class` | 1 | 5.7s |  |
| 147 | `capabilities_resolution` | 8 | 21.1s |  |
| 148 | `catch_class` | 6 | 5.7s |  |
| 149 | `catch_scope_slot` | 7 | 2.6s |  |
| 150 | `checkfilter` | 4 | 2.6s |  |
| 151 | `class_call` | 32 | 5.8s |  |
| 152 | `class_cast_call` | 14 | 5.7s |  |
| 153 | `class_enumeration` | 4 | 5.7s |  |
| 154 | `class_has_own_property` | 2 | 5.7s |  |
| 155 | `class_init_interpreter_mode` | 1 | 5.7s |  |
| 156 | `class_is` | 32 | 5.8s |  |
| 157 | `class_methods` | 5 | 5.8s |  |
| 158 | `class_object_properties` | 10 | 6.0s |  |
| 159 | `class_singleton` | 18 | 5.9s |  |
| 160 | `class_supercalls_errors` | 35 | 5.9s |  |
| 161 | `class_supercalls_mismatched` | 26 | 5.8s |  |
| 162 | `class_superclass_wrong_order` | 1 | 25.6s |  |
| 163 | `class_to_locale_string` | 2 | 7.0s |  |
| 164 | `class_to_string` | 2 | 7.0s |  |
| 165 | `class_value_of` | 2 | 7.1s |  |
| 166 | `click_block` | 5 | 7.9s |  |
| 167 | `click_invisible` | 3 | 7.3s |  |
| 168 | `closures` | 12 | 7.1s |  |
| 169 | `coerce_return_type` | 40 | 7.3s |  |
| 170 | `coerce_return_type_fail` | 2 | 7.0s |  |
| 171 | `coerce_return_void` | 3 | 7.1s |  |
| 172 | `coerce_string` | 86 | 7.5s |  |
| 173 | `coerce_string_precision` | 28 | 7.3s |  |
| 174 | `coerce_to_primitive_side_effects` | 29 | 7.3s |  |
| 175 | `color_matrix_filter` | 19 | 7.5s |  |
| 176 | `construct_errors_swf10` | 8 | 7.6s |  |
| 177 | `construct_frame_list` | 22 | 26.3s |  |
| 178 | `construct_interface` | 3 | 7.2s |  |
| 179 | `constructor_call` | 3 | 7.2s |  |
| 180 | `constructors_vs_timeline` | 5 | 26.4s |  |
| 181 | `constructprop_dynamic_primitive` | 7 | 7.2s |  |
| 182 | `content_element_basic` | 50 | 7.5s |  |
| 183 | `context3d_creation` | 9 | 7.3s |  |
| 184 | `control_flow_bool` | 4 | 7.2s |  |
| 185 | `control_flow_stricteq` | 8 | 7.2s |  |
| 186 | `convert_boolean` | 30 | 7.3s |  |
| 187 | `convert_integer` | 90 | 7.4s |  |
| 188 | `convert_number` | 56 | 7.3s |  |
| 189 | `convert_uinteger` | 90 | 7.4s |  |
| 190 | `convolution_filter` | 89 | 7.4s |  |
| 191 | `cpool_index_invalid_bytecode_1` | 6 | 7.3s |  |
| 192 | `cpool_index_invalid_bytecode_2` | 3 | 7.2s |  |
| 193 | `cpool_index_invalid_bytecode_3` | 1 | 7.1s |  |
| 194 | `cross_api_version_call_older` | 12 | 7.7s |  |
| 195 | `cryptscore` | 11 | 7.3s |  |
| 196 | `date` | 30 | 7.5s |  |
| 197 | `date_parse` | 36 | 7.1s |  |
| 198 | `declocal` | 46 | 7.1s |  |
| 199 | `declocal_i` | 46 | 7.1s |  |
| 200 | `decode_uri` | 71 | 7.4s |  |
| 201 | `decrement` | 46 | 7.2s |  |
| 202 | `decrement_i` | 46 | 3.1s |  |
| 203 | `default_values` | 7 | 7.0s |  |
| 204 | `dictionary_access` | 62 | 7.3s |  |
| 205 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 206 | `dictionary_delete` | 101 | 7.5s |  |
| 207 | `dictionary_foreach` | 42 | 7.3s |  |
| 208 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 209 | `dictionary_in` | 62 | 7.3s |  |
| 210 | `dictionary_iter_modify` | 8 | 7.1s |  |
| 211 | `dictionary_namespaces` | 36 | 7.2s |  |
| 212 | `dictionary_primitive_keys` | 29 | 7.1s |  |
| 213 | `displacement_map_filter` | 61 | 7.2s |  |
| 214 | `displayobject_alpha` | 277 | 7.0s |  |
| 215 | `displayobject_blendmode` | 0 | 7.2s |  |
| 216 | `displayobject_colortransform_nested` | 0 | 25.8s |  |
| 217 | `displayobject_filters` | 17 | 7.2s |  |
| 218 | `displayobject_from_enterframe` | 1 | 25.7s |  |
| 219 | `displayobject_getbounds_shape` | 0 | 25.6s |  |
| 220 | `displayobject_height` | 6052 | 25.7s |  |
| 221 | `displayobject_hittestobject` | 32 | 7.1s |  |
| 222 | `displayobject_hittestpoint` | 49 | 7.3s |  |
| 223 | `displayobject_hittestpoint_root` | 13 | 7.3s |  |
| 224 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 225 | `displayobject_invalid_props` | 3 | 3.0s |  |
| 226 | `displayobject_mask` | 3 | 7.3s |  |
| 227 | `displayobject_mask_self_referential` | 0 | 7.2s |  |
| 228 | `displayobject_metaData` | 3 | 7.0s |  |
| 229 | `displayobject_name` | 22 | 7.4s |  |
| 230 | `displayobject_name_from_timeline` | 24 | 7.4s |  |
| 231 | `displayobject_parent` | 12 | 7.1s |  |
| 232 | `displayobject_root` | 24 | 7.1s |  |
| 233 | `displayobject_rotation` | 1284 | 7.2s |  |
| 234 | `displayobject_set_matrix_nested` | 0 | 26.0s |  |
| 235 | `displayobject_set_name_loaded` | 3 | 7.6s |  |
| 236 | `displayobject_subclass` | 2 | 7.3s |  |
| 237 | `displayobject_visible` | 23 | 7.2s |  |
| 238 | `displayobject_width` | 4852 | 26.8s |  |
| 239 | `displayobject_x` | 614 | 7.3s |  |
| 240 | `displayobject_y` | 617 | 7.3s |  |
| 241 | `displayobjectcontainer_addchild` | 32 | 7.4s |  |
| 242 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.2s |  |
| 243 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.5s |  |
| 244 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.3s |  |
| 245 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.3s |  |
| 246 | `displayobjectcontainer_addchildat` | 42 | 7.2s |  |
| 247 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 3.2s |  |
| 248 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.3s |  |
| 249 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.3s |  |
| 250 | `displayobjectcontainer_contains` | 66 | 25.7s |  |
| 251 | `displayobjectcontainer_getchildat` | 4 | 7.2s |  |
| 252 | `displayobjectcontainer_getchildbyname` | 9 | 7.2s |  |
| 253 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.2s |  |
| 254 | `displayobjectcontainer_getchildindex` | 28 | 7.3s |  |
| 255 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.4s |  |
| 256 | `displayobjectcontainer_removechild` | 10 | 7.1s |  |
| 257 | `displayobjectcontainer_removechild_errors` | 4 | 7.1s |  |
| 258 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.2s |  |
| 259 | `displayobjectcontainer_removechildat` | 18 | 7.1s |  |
| 260 | `displayobjectcontainer_removechildren` | 51 | 7.3s |  |
| 261 | `displayobjectcontainer_setchildindex` | 42 | 7.0s |  |
| 262 | `displayobjectcontainer_stopallmovieclips` | 2 | 7.5s |  |
| 263 | `displayobjectcontainer_swapchildren` | 42 | 7.3s |  |
| 264 | `displayobjectcontainer_swapchildrenat` | 42 | 7.3s |  |
| 265 | `displayobjectcontainer_timelineinstance` | 48 | 25.2s |  |
| 266 | `divide` | 1058 | 15.9s |  |
| 267 | `doabc_is_eager` | 1 | 24.9s |  |
| 268 | `documentclass` | 9 | 6.7s |  |
| 269 | `domain_memory` | 133 | 7.6s |  |
| 270 | `drag_drop` | 10 | 6.9s |  |
| 271 | `drop_shadow_filter` | 172 | 6.8s |  |
| 272 | `duplicate_defs` | 1 | 7.0s |  |
| 273 | `eager_init` | 1 | 6.9s |  |
| 274 | `east_asian_justifier_clone` | 8 | 2.7s |  |
| 275 | `edit_text_linkage` | 7 | 8.3s |  |
| 276 | `edittext_align` | 60 | 7.4s |  |
| 277 | `edittext_always_show_selection` | 0 | 25.7s |  |
| 278 | `edittext_antialiastype` | 296 | 6.8s |  |
| 279 | `edittext_at_point_methods_basic` | 16 | 7.9s |  |
| 280 | `edittext_autosize` | 39 | 7.0s |  |
| 281 | `edittext_autosize_align` | 0 | 25.6s |  |
| 282 | `edittext_autosize_height_dynamic` | 60 | 25.6s |  |
| 283 | `edittext_autosize_height_input` | 60 | 6.8s |  |
| 284 | `edittext_autosize_lazy_bounds_events` | 65 | 7.0s |  |
| 285 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.6s |  |
| 286 | `edittext_autosize_lazy_bounds_props` | 490 | 8.0s |  |
| 287 | `edittext_autosize_lazy_bounds_visual` | 0 | 25.3s |  |
| 288 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.8s |  |
| 289 | `edittext_bottom_scroll_v_basic` | 210 | 6.7s |  |
| 290 | `edittext_bounds_scale` | 24 | 25.1s |  |
| 291 | `edittext_bullet` | 30 | 6.8s |  |
| 292 | `edittext_default_format` | 221 | 7.3s |  |
| 293 | `edittext_default_format_empty` | 136 | 7.1s |  |
| 294 | `edittext_empty_text_format` | 7 | 6.7s |  |
| 295 | `edittext_focus_selection` | 5 | 6.7s |  |
| 296 | `edittext_font_size` | 45 | 6.7s |  |
| 297 | `edittext_format_empty_font` | 8 | 6.8s |  |
| 298 | `edittext_get_char_index_at_point` | 4 | 27.5s |  |
| 299 | `edittext_get_line_index_at_point` | 2 | 26.2s |  |
| 300 | `edittext_get_line_index_of_char` | 76 | 7.5s |  |
| 301 | `edittext_getcharboundaries` | 172 | 7.2s |  |
| 302 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.7s |  |
| 303 | `edittext_getcharboundaries_scroll` | 85 | 7.5s |  |
| 304 | `edittext_getlinemetrics` | 146 | 7.6s |  |
| 305 | `edittext_html` | 3101 | 7.8s |  |
| 306 | `edittext_html_condensewhite` | 487 | 7.5s |  |
| 307 | `edittext_html_entity` | 4 | 7.7s |  |
| 308 | `edittext_html_font_size_swf12` | 267 | 7.5s |  |
| 309 | `edittext_html_font_size_swf13` | 273 | 7.1s |  |
| 310 | `edittext_html_roundtrip` | 17 | 7.4s |  |
| 311 | `edittext_ime_focus_lost` | 9 | 26.3s |  |
| 312 | `edittext_input_control` | 12 | 7.6s |  |
| 313 | `edittext_leading` | 9 | 7.6s |  |
| 314 | `edittext_letter_spacing` | 15 | 7.4s |  |
| 315 | `edittext_line_methods` | 294 | 8.7s |  |
| 316 | `edittext_line_metrics` | 11 | 27.7s |  |
| 317 | `edittext_margins` | 25 | 7.4s |  |
| 318 | `edittext_max_scroll_h_basic` | 475 | 7.6s |  |
| 319 | `edittext_max_scroll_v_basic` | 1000 | 7.4s |  |
| 320 | `edittext_mouse_selection` | 363 | 27.2s |  |
| 321 | `edittext_mousedown` | 3 | 7.8s |  |
| 322 | `edittext_mouseenabled` | 26 | 7.3s |  |
| 323 | `edittext_newline_character` | 22 | 7.3s |  |
| 324 | `edittext_newline_stripping` | 64 | 10.0s |  |
| 325 | `edittext_newlines` | 30 | 7.4s |  |
| 326 | `edittext_paragraph_methods` | 257 | 7.3s |  |
| 327 | `edittext_paste_events` | 8 | 7.4s |  |
| 328 | `edittext_paste_maxchars` | 4 | 7.3s |  |
| 329 | `edittext_paste_restrict` | 16 | 7.2s |  |
| 330 | `edittext_restrict` | 191 | 7.4s |  |
| 331 | `edittext_restrict_events` | 22 | 7.3s |  |
| 332 | `edittext_scrollh` | 10 | 3.2s |  |
| 333 | `edittext_selected_text` | 9 | 7.3s |  |
| 334 | `edittext_set_html_same` | 17 | 7.3s |  |
| 335 | `edittext_set_text_vs_html` | 9 | 7.3s |  |
| 336 | `edittext_stylesheet` | 536 | 7.7s |  |
| 337 | `edittext_stylesheet_custom_tag` | 76 | 7.4s |  |
| 338 | `edittext_stylesheet_display` | 272 | 7.5s |  |
| 339 | `edittext_underline` | 40 | 7.4s |  |
| 340 | `edittext_width_height` | 103 | 10.6s |  |
| 341 | `edittext_wordwrap_word` | 150 | 7.5s |  |
| 342 | `edittext_wrap_breaks` | 2375 | 7.8s |  |
| 343 | `element_format_clone` | 44 | 7.2s |  |
| 344 | `element_format_constructor_order` | 64 | 7.3s |  |
| 345 | `element_format_properties` | 235 | 8.1s |  |
| 346 | `empty_bounds` | 1 | 7.0s |  |
| 347 | `encode_uri_surrogate_pair_swf11` | 15 | 6.8s |  |
| 348 | `equals` | 512 | 11.2s |  |
| 349 | `error_geterrormessage` | 779 | 7.2s |  |
| 350 | `error_prototype` | 15 | 7.2s |  |
| 351 | `error_stack_trace_debug_swf17` | 0 | 25.8s |  |
| 352 | `error_stack_trace_debug_swf18` | 0 | 6.9s |  |
| 353 | `error_stack_trace_release_swf17` | 0 | 6.9s |  |
| 354 | `error_stack_trace_release_swf18` | 0 | 6.8s |  |
| 355 | `error_tostring` | 29 | 7.1s |  |
| 356 | `es3_inheritance` | 31 | 7.1s |  |
| 357 | `es4_inheritance` | 30 | 7.2s |  |
| 358 | `es4_interfaces` | 30 | 7.2s |  |
| 359 | `es4_method_binding` | 8 | 7.1s |  |
| 360 | `es4_oop_prototypes` | 14 | 7.2s |  |
| 361 | `es4_protected_inheritance` | 6 | 7.1s |  |
| 362 | `escape` | 71 | 7.2s |  |
| 363 | `event_bubbles` | 2 | 7.0s |  |
| 364 | `event_cancelable` | 2 | 7.0s |  |
| 365 | `event_clone` | 20 | 7.2s |  |
| 366 | `event_clone_error_redispatch` | 3 | 7.2s |  |
| 367 | `event_clone_on_redispatch` | 10 | 7.2s |  |
| 368 | `event_formattostring` | 31 | 7.2s |  |
| 369 | `event_isdefaultprevented` | 12 | 7.1s |  |
| 370 | `event_target_getter` | 5 | 3.1s |  |
| 371 | `event_target_set` | 9 | 7.0s |  |
| 372 | `event_type` | 1 | 10.7s |  |
| 373 | `event_valueof_tostring` | 18 | 7.3s |  |
| 374 | `eventdispatcher_dispatchevent` | 12 | 7.3s |  |
| 375 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.4s |  |
| 376 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.4s |  |
| 377 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.3s |  |
| 378 | `eventdispatcher_dispatchevent_this` | 5 | 7.3s |  |
| 379 | `eventdispatcher_haseventlistener` | 25 | 7.4s |  |
| 380 | `eventdispatcher_interface_invoke` | 1 | 7.2s |  |
| 381 | `eventdispatcher_tostring` | 10 | 7.3s |  |
| 382 | `eventdispatcher_willtrigger` | 25 | 7.2s |  |
| 383 | `falsiness` | 30 | 7.3s |  |
| 384 | `fast_index_access` | 12 | 7.4s |  |
| 385 | `filefilter_properties` | 4 | 7.3s |  |
| 386 | `filereference_browse_cancel` | 3 | 7.3s |  |
| 387 | `filereference_browse_select` | 9 | 7.3s |  |
| 388 | `filereference_load` | 31 | 3.2s |  |
| 389 | `filereference_save` | 16 | 7.4s |  |
| 390 | `filereference_save_and_browse` | 42 | 7.3s |  |
| 391 | `filereference_save_and_load` | 22 | 7.4s |  |
| 392 | `filereference_uninitialized` | 8 | 7.3s |  |
| 393 | `filereferencelist_browse_cancel` | 6 | 7.3s |  |
| 394 | `filereferencelist_browse_select` | 7 | 7.3s |  |
| 395 | `filter_rewind` | 8 | 7.6s |  |
| 396 | `filters_array_holes` | 25 | 7.4s |  |
| 397 | `finddef` | 3 | 7.3s |  |
| 398 | `findprop_global_prototype` | 6 | 7.3s |  |
| 399 | `flash_media_video_constructor` | 156 | 8.1s |  |
| 400 | `flash_media_video_rotation_probe` | 27 | 7.4s |  |
| 401 | `flash_xml` | 29 | 7.3s |  |
| 402 | `flash_xml_cloneNode` | 22 | 7.4s |  |
| 403 | `flash_xml_namespace` | 109 | 7.3s |  |
| 404 | `flash_xml_removeNode` | 60 | 7.3s |  |
| 405 | `focus_events_code` | 161 | 26.9s |  |
| 406 | `focus_events_key_basic` | 132 | 26.9s |  |
| 407 | `focus_events_key_navigation` | 53 | 7.4s |  |
| 408 | `focus_events_key_same_object` | 26 | 7.3s |  |
| 409 | `focus_events_mixed_key_mouse` | 100 | 26.8s |  |
| 410 | `focus_events_mouse_basic` | 260 | 30.4s |  |
| 411 | `focus_events_mouse_focusable` | 112 | 27.4s |  |
| 412 | `focus_events_mouse_same_object` | 40 | 26.9s |  |
| 413 | `focus_remove` | 20 | 27.4s |  |
| 414 | `focus_root_movie` | 4 | 27.5s |  |
| 415 | `focus_stage` | 1 | 7.6s |  |
| 416 | `focusrect` | 18 | 8.3s |  |
| 417 | `focusrect_focuslost` | 9 | 7.8s |  |
| 418 | `focusrect_property` | 110 | 7.8s |  |
| 419 | `font_description_clone` | 14 | 7.7s |  |
| 420 | `font_embedded` | 24 | 8.1s |  |
| 421 | `font_enumeratefonts` | 41 | 8.4s |  |
| 422 | `font_enumeratefonts_filter` | 4 | 28.8s |  |
| 423 | `font_hasglyphs` | 40 | 8.2s |  |
| 424 | `framelabel_constr` | 5 | 7.7s |  |
| 425 | `function_call` | 12 | 7.8s |  |
| 426 | `function_call_arguments` | 46 | 3.5s |  |
| 427 | `function_call_arguments_enumerate` | 5 | 7.7s |  |
| 428 | `function_call_coercion` | 108 | 8.1s |  |
| 429 | `function_call_default` | 6 | 7.6s |  |
| 430 | `function_call_rest` | 22 | 7.6s |  |
| 431 | `function_call_types` | 3 | 7.5s |  |
| 432 | `function_call_via_apply` | 11 | 7.4s |  |
| 433 | `function_call_via_call` | 3 | 7.4s |  |
| 434 | `function_display_anonymous` | 7 | 3.3s |  |
| 435 | `function_length` | 6 | 7.5s |  |
| 436 | `function_object` | 2 | 7.4s |  |
| 437 | `function_proto` | 5 | 7.3s |  |
| 438 | `function_proto_created` | 61 | 7.5s |  |
| 439 | `function_to_locale_string` | 4 | 7.4s |  |
| 440 | `function_to_string` | 4 | 7.4s |  |
| 441 | `function_type` | 6 | 7.4s |  |
| 442 | `function_unbound_this` | 51 | 7.5s |  |
| 443 | `function_value_of` | 4 | 7.4s |  |
| 444 | `get_definition_by_name` | 11 | 7.5s |  |
| 445 | `get_qualified_class_name` | 20 | 8.9s |  |
| 446 | `get_qualified_super_class_name` | 18 | 6.0s |  |
| 447 | `get_slot_edge_cases` | 1 | 22.5s |  |
| 448 | `get_timer` | 2 | 6.0s |  |
| 449 | `getglobalslot` | 1 | 5.9s |  |
| 450 | `getouterscope` | 8 | 6.1s |  |
| 451 | `getter_different_namespace_setter` | 2 | 5.9s |  |
| 452 | `glow_filter` | 127 | 6.2s |  |
| 453 | `goto_button_nested_framescript` | 28 | 23.3s |  |
| 454 | `goto_in_constructframe` | 12 | 6.1s |  |
| 455 | `goto_in_scene_last_frame` | 2 | 22.4s |  |
| 456 | `goto_methods` | 56 | 6.2s |  |
| 457 | `goto_methods_swfver10` | 8 | 5.9s |  |
| 458 | `goto_nested_construct_sibling` | 18 | 6.3s |  |
| 459 | `goto_nested_framescript` | 9 | 6.2s |  |
| 460 | `goto_on_orphan` | 15 | 6.2s |  |
| 461 | `gradient_bevel_filter` | 206 | 6.0s |  |
| 462 | `gradient_glow_filter` | 206 | 6.0s |  |
| 463 | `graphics_bad_direct_commands` | 5 | 6.6s |  |
| 464 | `graphics_bitmap_fill` | 0 | 7.6s |  |
| 465 | `graphics_bitmaps` | 0 | 6.7s |  |
| 466 | `graphics_direct_commands` | 0 | 6.6s |  |
| 467 | `graphics_draw_triangles` | 98 | 23.5s |  |
| 468 | `graphics_gradients` | 0 | 6.2s |  |
| 469 | `graphics_gradients_nulls` | 0 | 6.3s |  |
| 470 | `graphics_path` | 56 | 6.0s |  |
| 471 | `graphics_round_rects` | 0 | 6.2s |  |
| 472 | `graphics_simple_shapes` | 0 | 6.2s |  |
| 473 | `greaterequals` | 512 | 8.5s |  |
| 474 | `greaterthan` | 512 | 8.6s |  |
| 475 | `has_own_property` | 102 | 6.4s |  |
| 476 | `hasownproperty_namespaces` | 2 | 6.0s |  |
| 477 | `hello_world` | 1 | 6.0s |  |
| 478 | `hittest_morph` | 30 | 6.2s |  |
| 479 | `if_eq` | 10 | 6.1s |  |
| 480 | `if_gt` | 1 | 6.2s |  |
| 481 | `if_gte` | 10 | 10.1s |  |
| 482 | `if_lt` | 1 | 6.8s |  |
| 483 | `if_lte` | 10 | 6.8s |  |
| 484 | `if_ne` | 7 | 2.8s |  |
| 485 | `if_stricteq` | 6 | 6.9s |  |
| 486 | `if_strictne` | 11 | 6.9s |  |
| 487 | `ime_linux_dead_keys` | 10 | 7.2s |  |
| 488 | `in` | 102 | 7.3s |  |
| 489 | `inclocal` | 46 | 6.9s |  |
| 490 | `inclocal_i` | 46 | 7.0s |  |
| 491 | `increment` | 46 | 7.1s |  |
| 492 | `increment_i` | 46 | 7.0s |  |
| 493 | `indexing_delete` | 75 | 6.8s |  |
| 494 | `instanceof` | 58 | 7.1s |  |
| 495 | `instantiation_on_enter_frame` | 7 | 26.3s |  |
| 496 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.9s |  |
| 497 | `int_constr` | 92 | 6.8s |  |
| 498 | `int_edge_cases` | 19 | 6.9s |  |
| 499 | `int_instanceof` | 3 | 6.9s |  |
| 500 | `int_tofixed` | 1215 | 7.3s |  |
| 501 | `int_tostring` | 3375 | 7.0s |  |
| 502 | `interactiveobject_enabled` | 25 | 7.1s |  |
| 503 | `interface_namespaces` | 78 | 7.5s |  |
| 504 | `is_finite` | 46 | 7.0s |  |
| 505 | `is_nan` | 46 | 7.2s |  |
| 506 | `is_prototype_of` | 12 | 7.1s |  |
| 507 | `issue_10221` | 2 | 6.8s |  |
| 508 | `issue_13780` | 12 | 7.3s |  |
| 509 | `issue_14901` | 1 | 6.8s |  |
| 510 | `issue_17675_edittext_paste_maxchars` | 1 | 7.1s |  |
| 511 | `issue_5292` | 5 | 7.3s |  |
| 512 | `issue_8630` | 2 | 26.2s |  |
| 513 | `issue_8630_scriptremove` | 11 | 6.9s |  |
| 514 | `istype` | 24 | 2.9s |  |
| 515 | `istypelate` | 58 | 7.2s |  |
| 516 | `istypelate_coerce` | 198 | 11.3s |  |
| 517 | `jpeg_loader_context` | 6 | 7.0s |  |
| 518 | `json_errors` | 9 | 25.5s |  |
| 519 | `json_parse` | 21 | 7.0s |  |
| 520 | `json_stringify` | 12 | 7.3s |  |
| 521 | `json_stringify_order` | 1 | 7.0s |  |
| 522 | `json_version_gated` | 1 | 7.0s |  |
| 523 | `key_input_80percent` | 1812 | 7.2s |  |
| 524 | `key_input_location` | 126 | 7.0s |  |
| 525 | `key_input_numpad` | 384 | 6.9s |  |
| 526 | `lazyinit` | 17 | 7.0s |  |
| 527 | `lessequals` | 512 | 11.0s |  |
| 528 | `lessthan` | 512 | 10.9s |  |
| 529 | `loader_bitmap_transparency` | 14 | 7.2s |  |
| 530 | `loader_bytes_unknown_content` | 14 | 7.1s |  |
| 531 | `loader_child_getdefinition` | 5 | 7.3s |  |
| 532 | `loader_duplicate_coerce` | 3 | 7.3s |  |
| 533 | `loader_duplicate_coerce_new_domain` | 4 | 7.1s |  |
| 534 | `loader_error_in_root_ctor` | 4 | 7.2s |  |
| 535 | `loader_events` | 92 | 7.8s |  |
| 536 | `loader_image` | 8 | 7.4s |  |
| 537 | `loader_jpegxr` | 2 | 25.6s |  |
| 538 | `loader_jpegxr_alpha` | 1 | 25.4s |  |
| 539 | `loader_loadbytes_events` | 30 | 7.8s |  |
| 540 | `loader_loadbytes_invalid_png` | 4 | 25.3s |  |
| 541 | `loader_loadbytes_url` | 12 | 7.3s |  |
| 542 | `loader_loaderurl` | 6 | 7.5s |  |
| 543 | `loader_noninteractive_try_click_root` | 5 | 25.9s |  |
| 544 | `loader_reuse` | 38 | 7.2s |  |
| 545 | `loader_unknown_content` | 24 | 7.2s |  |
| 546 | `loader_visibility_interactive` | 1 | 7.2s |  |
| 547 | `loaderinfo_events` | 7 | 7.0s |  |
| 548 | `loaderinfo_loadurl` | 12 | 11.1s |  |
| 549 | `loaderinfo_more` | 6 | 8.0s |  |
| 550 | `loaderinfo_properties` | 18 | 7.8s |  |
| 551 | `loaderinfo_properties_not_loaded` | 23 | 7.8s |  |
| 552 | `loaderinfo_root` | 10 | 7.7s |  |
| 553 | `loaderinfo_root_allows` | 2 | 7.6s |  |
| 554 | `localconnection_send` | 4 | 7.7s |  |
| 555 | `lshift` | 1058 | 20.3s |  |
| 556 | `mask_reapply` | 1 | 7.8s |  |
| 557 | `math` | 497 | 7.9s |  |
| 558 | `matrix3d` | 57 | 8.6s |  |
| 559 | `matrix3d_compose` | 34 | 8.0s |  |
| 560 | `matrix3d_invert` | 18 | 3.4s |  |
| 561 | `missing_external_interface` | 10 | 7.7s |  |
| 562 | `modulo` | 1058 | 20.5s |  |
| 563 | `morph_shape` | 2 | 28.8s |  |
| 564 | `mouse_children` | 192 | 28.9s |  |
| 565 | `mouse_click_events` | 90 | 28.7s |  |
| 566 | `mouse_double_click_events` | 188 | 7.8s |  |
| 567 | `mouse_empty_parent` | 4 | 7.8s |  |
| 568 | `mouse_over_while_dragging` | 3 | 7.7s |  |
| 569 | `mouse_pick_button_mode` | 2 | 7.8s |  |
| 570 | `mouse_pick_dobj_mask` | 4 | 7.9s |  |
| 571 | `mouse_pick_masking` | 7 | 28.5s |  |
| 572 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 28.2s |  |
| 573 | `mouse_pick_non_interactive_dobj_mask` | 3 | 8.0s |  |
| 574 | `mouse_pick_text` | 8 | 7.8s |  |
| 575 | `mouse_sibling` | 8 | 7.7s |  |
| 576 | `mouse_wheel_events` | 36 | 29.5s |  |
| 577 | `mouseevent_constr` | 66 | 7.7s |  |
| 578 | `mouseevent_stagexy` | 35 | 7.7s |  |
| 579 | `mouseevent_valueof_tostring` | 28 | 7.7s |  |
| 580 | `movieclip_addframescript` | 3 | 28.8s |  |
| 581 | `movieclip_child_property` | 16 | 7.8s |  |
| 582 | `movieclip_constr` | 21 | 11.0s |  |
| 583 | `movieclip_currentlabels` | 17 | 27.7s |  |
| 584 | `movieclip_currentlabels_dupes1` | 46 | 27.7s |  |
| 585 | `movieclip_currentlabels_dupes2` | 30 | 7.6s |  |
| 586 | `movieclip_currentlabels_dupes3` | 67 | 7.5s |  |
| 587 | `movieclip_currentscene` | 12 | 7.6s |  |
| 588 | `movieclip_dispatchevent` | 430 | 7.7s |  |
| 589 | `movieclip_dispatchevent_cancel` | 102 | 7.7s |  |
| 590 | `movieclip_dispatchevent_handlerorder` | 251 | 7.6s |  |
| 591 | `movieclip_dispatchevent_selfadd` | 80 | 7.6s |  |
| 592 | `movieclip_dispatchevent_target` | 899 | 7.7s |  |
| 593 | `movieclip_displayevents` | 96 | 28.1s |  |
| 594 | `movieclip_displayevents_clickgoto` | 676 | 8.1s |  |
| 595 | `movieclip_displayevents_clickgoto2` | 2001 | 8.2s |  |
| 596 | `movieclip_displayevents_clickplay` | 575 | 7.8s |  |
| 597 | `movieclip_displayevents_clicksymbol` | 562 | 8.0s |  |
| 598 | `movieclip_displayevents_constructframegoto` | 140 | 8.2s |  |
| 599 | `movieclip_displayevents_constructframeplay` | 50 | 7.9s |  |
| 600 | `movieclip_displayevents_constructframesymbol` | 144 | 7.9s |  |
| 601 | `movieclip_displayevents_dblhandler` | 21 | 8.0s |  |
| 602 | `movieclip_displayevents_enterframegoto` | 149 | 8.0s |  |
| 603 | `movieclip_displayevents_enterframeplay` | 48 | 7.8s |  |
| 604 | `movieclip_displayevents_enterframesymbol` | 149 | 28.4s |  |
| 605 | `movieclip_displayevents_exitframegoto` | 106 | 7.9s |  |
| 606 | `movieclip_displayevents_exitframeplay` | 44 | 7.7s |  |
| 607 | `movieclip_displayevents_exitframesymbol` | 135 | 7.7s |  |
| 608 | `movieclip_displayevents_looping` | 63 | 27.9s |  |
| 609 | `movieclip_displayevents_stopped` | 113 | 8.0s |  |
| 610 | `movieclip_displayevents_swap` | 96 | 3.1s |  |
| 611 | `movieclip_displayevents_timeline` | 128 | 27.7s |  |
| 612 | `movieclip_drawrect` | 54 | 7.5s |  |
| 613 | `movieclip_frameconstruct_skipped` | 9 | 7.6s |  |
| 614 | `movieclip_goto_during_frame_script` | 15 | 7.5s |  |
| 615 | `movieclip_goto_overwrite` | 14 | 27.4s |  |
| 616 | `movieclip_goto_scene_last_frame_int` | 1 | 27.2s |  |
| 617 | `movieclip_goto_scene_last_frame_label` | 1 | 3.2s |  |
| 618 | `movieclip_gotoandplay` | 15 | 26.9s |  |
| 619 | `movieclip_gotoandstop` | 13 | 27.0s |  |
| 620 | `movieclip_gotoandstop_children` | 4 | 7.6s |  |
| 621 | `movieclip_gotoandstop_framescripts1` | 4 | 7.5s |  |
| 622 | `movieclip_gotoandstop_framescripts2` | 4 | 3.3s |  |
| 623 | `movieclip_gotoandstop_framescripts_self` | 7 | 28.0s |  |
| 624 | `movieclip_gotoandstop_queueing` | 12 | 24.7s |  |
| 625 | `movieclip_hittest` | 67 | 6.9s |  |
| 626 | `movieclip_next_frame` | 2 | 6.8s |  |
| 627 | `movieclip_next_scene` | 6 | 24.5s |  |
| 628 | `movieclip_play` | 3 | 2.9s |  |
| 629 | `movieclip_prev_frame` | 3 | 6.7s |  |
| 630 | `movieclip_prev_scene` | 7 | 6.9s |  |
| 631 | `movieclip_properties` | 79 | 7.0s |  |
| 632 | `movieclip_queued_noop_goto_swf10` | 9 | 6.9s |  |
| 633 | `movieclip_queued_noop_goto_swf9` | 7 | 1.2s |  |
| 634 | `movieclip_scenes` | 11 | 6.7s |  |
| 635 | `movieclip_soundtransform` | 831 | 26.9s |  |
| 636 | `movieclip_stop` | 1 | 6.8s |  |
| 637 | `movieclip_super_is_symbol` | 20 | 7.1s |  |
| 638 | `movieclip_symbol_constr` | 8 | 6.8s |  |
| 639 | `movieclip_text_mousedown` | 1 | 6.8s |  |
| 640 | `movieclip_willtrigger` | 5 | 6.8s |  |
| 641 | `multiply` | 1058 | 18.3s |  |
| 642 | `namespace_constr` | 253 | 7.0s |  |
| 643 | `namespace_constr_args` | 1 | 6.6s |  |
| 644 | `namespace_enumeration_order` | 7 | 6.7s |  |
| 645 | `nan_scale` | 9 | 6.7s |  |
| 646 | `navigateToURL_target_normalize` | 107 | 25.9s |  |
| 647 | `negate` | 30 | 6.8s |  |
| 648 | `negative_volume_panned` | 0 | 7.0s |  |
| 649 | `nested_iteration` | 11 | 6.7s |  |
| 650 | `net_getClassByAlias` | 3 | 6.7s |  |
| 651 | `net_navigateToURL` | 57 | 6.7s |  |
| 652 | `net_stream_play_options` | 6 | 6.8s |  |
| 653 | `netconnection_close` | 55 | 6.9s |  |
| 654 | `netconnection_properties` | 78 | 7.0s |  |
| 655 | `netconnection_send_remote` | 50 | 7.1s |  |
| 656 | `netconnection_serialize_arrays` | 6 | 6.8s |  |
| 657 | `netstream_client` | 10 | 6.9s |  |
| 658 | `netstream_connect` | 7 | 6.9s |  |
| 659 | `newactivation_in_script_init` | 3 | 7.0s |  |
| 660 | `newclass_twice` | 3 | 7.3s |  |
| 661 | `nonconflicting_declarations` | 0 | 7.2s |  |
| 662 | `null_void_types` | 8 | 7.2s |  |
| 663 | `number_autoconv` | 21 | 3.1s |  |
| 664 | `number_autoconv_amf` | 132 | 7.4s |  |
| 665 | `number_autoconv_array_sort_32bit` | 1 | 7.2s |  |
| 666 | `number_constr` | 58 | 7.4s |  |
| 667 | `number_toexponential` | 378 | 7.4s |  |
| 668 | `number_toexponential2` | 35 | 7.2s |  |
| 669 | `number_tofixed` | 378 | 7.1s |  |
| 670 | `number_toprecision` | 350 | 7.4s |  |
| 671 | `obfuscated_class_names` | 3 | 7.2s |  |
| 672 | `object_enumeration` | 10 | 7.1s |  |
| 673 | `object_prototype` | 4 | 7.1s |  |
| 674 | `object_to_locale_string` | 2 | 7.0s |  |
| 675 | `object_to_string` | 2 | 7.0s |  |
| 676 | `object_value_of` | 2 | 2.9s |  |
| 677 | `op_coerce` | 54 | 3.1s |  |
| 678 | `op_coerce_x` | 54 | 7.1s |  |
| 679 | `op_escxattr` | 2 | 7.0s |  |
| 680 | `op_escxelem` | 2 | 7.1s |  |
| 681 | `op_lookupswitch` | 4 | 7.1s |  |
| 682 | `optimize_coerce` | 1 | 7.0s |  |
| 683 | `orphan_movie_complex` | 80 | 7.5s |  |
| 684 | `orphan_movie_reorder` | 111 | 26.1s |  |
| 685 | `package_namespace` | 7 | 7.0s |  |
| 686 | `param_default_value_has_zero_cpool_index` | 1 | 7.0s |  |
| 687 | `parent_early_access_child` | 16 | 7.2s |  |
| 688 | `parse_float` | 81 | 7.3s |  |
| 689 | `perspective_projection_basic` | 40 | 7.1s |  |
| 690 | `pixelbender_ceil` | 77 | 7.2s |  |
| 691 | `pixelbender_conditional` | 138 | 11.2s |  |
| 692 | `pixelbender_conversions` | 270 | 7.8s |  |
| 693 | `pixelbender_dithering` | 8 | 33.2s |  |
| 694 | `pixelbender_div` | 36 | 7.7s |  |
| 695 | `pixelbender_effect_BlurredFocus` | 0 | 34.1s |  |
| 696 | `pixelbender_effect_glassDisplace` | 0 | 13.1s |  |
| 697 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 31.4s |  |
| 698 | `pixelbender_effect_smudge` | 0 | 10.9s |  |
| 699 | `pixelbender_effect_tintype` | 0 | 10.1s |  |
| 700 | `pixelbender_effect_twirl` | 0 | 11.2s |  |
| 701 | `pixelbender_eof` | 7 | 7.4s |  |
| 702 | `pixelbender_images` | 0 | 9.8s |  |
| 703 | `pixelbender_input` | 103 | 26.9s |  |
| 704 | `pixelbender_logicalnot` | 20 | 7.3s |  |
| 705 | `pixelbender_malformed_data` | 190 | 26.8s |  |
| 706 | `pixelbender_multiple_out_params` | 1 | 3.2s |  |
| 707 | `pixelbender_no_out_param` | 6 | 7.3s |  |
| 708 | `pixelbender_outputs` | 13 | 7.5s |  |
| 709 | `pixelbender_padding_bytes` | 22 | 7.4s |  |
| 710 | `pixelbender_param_qualifier` | 512 | 7.5s |  |
| 711 | `pixelbender_parameters` | 1563 | 7.7s |  |
| 712 | `pixelbender_parameters_bool` | 240 | 7.6s |  |
| 713 | `pixelbender_parameters_int_vs_bool` | 54 | 7.5s |  |
| 714 | `pixelbender_parse_errors` | 6 | 7.3s |  |
| 715 | `pixelbender_rsqrt` | 24 | 7.4s |  |
| 716 | `pixelbender_select_kinds` | 8 | 7.5s |  |
| 717 | `pixelbender_shaderdata` | 49 | 7.4s |  |
| 718 | `pixelbender_shaderdata_setter` | 99 | 7.7s |  |
| 719 | `pixelbender_sign` | 60 | 7.5s |  |
| 720 | `pixelbender_vector_output` | 11 | 7.6s |  |
| 721 | `place_multiple` | 17 | 26.1s |  |
| 722 | `place_object_replace` | 9 | 7.5s |  |
| 723 | `place_object_replace_2` | 24 | 7.4s |  |
| 724 | `place_object_same_depth_frame` | 1 | 7.4s |  |
| 725 | `point` | 132 | 7.9s |  |
| 726 | `primitive_edge_cases` | 1 | 7.3s |  |
| 727 | `property_priority` | 22 | 6.0s |  |
| 728 | `property_priority_three_level` | 6 | 20.5s |  |
| 729 | `propertyisenumerable_namespaces` | 6 | 5.9s |  |
| 730 | `prototype_set_null` | 7 | 5.7s |  |
| 731 | `proxy_callproperty` | 24 | 6.0s |  |
| 732 | `proxy_deleteproperty` | 64 | 5.8s |  |
| 733 | `proxy_enumeration` | 34 | 5.8s |  |
| 734 | `proxy_getproperty` | 77 | 6.1s |  |
| 735 | `proxy_hasownproperty` | 8 | 5.7s |  |
| 736 | `proxy_hasproperty` | 32 | 5.8s |  |
| 737 | `proxy_serialize` | 9 | 5.8s |  |
| 738 | `proxy_setproperty` | 42 | 5.8s |  |
| 739 | `qname_as_lazy_name_attribute_multiname` | 1 | 5.7s |  |
| 740 | `qname_constr` | 32 | 5.9s |  |
| 741 | `qname_constr_namespace` | 24 | 5.8s |  |
| 742 | `qname_enumeration` | 9 | 5.8s |  |
| 743 | `qname_indexing` | 23 | 6.8s |  |
| 744 | `qname_tostring` | 25 | 5.9s |  |
| 745 | `qname_valueof` | 29 | 5.8s |  |
| 746 | `rectangle` | 1094 | 6.3s |  |
| 747 | `regexp_constr` | 148 | 5.9s |  |
| 748 | `regexp_exec` | 19 | 5.8s |  |
| 749 | `regexp_extended` | 47 | 6.0s |  |
| 750 | `regexp_multiargs` | 1 | 5.6s |  |
| 751 | `regexp_test` | 27 | 2.7s |  |
| 752 | `regexp_toString` | 10 | 5.8s |  |
| 753 | `register_script_refresh` | 35 | 6.2s |  |
| 754 | `remove_child_clear_field` | 88 | 6.1s |  |
| 755 | `remove_dobj` | 3 | 5.8s |  |
| 756 | `resolve_order` | 4 | 5.8s |  |
| 757 | `responder_null_callbacks` | 1 | 5.7s |  |
| 758 | `rng` | 1 | 6.8s |  |
| 759 | `rootless` | 42 | 5.8s |  |
| 760 | `rshift` | 1058 | 14.7s |  |
| 761 | `sandbox_type_inherited` | 2 | 6.0s |  |
| 762 | `sandbox_type_local_file` | 1 | 10.7s |  |
| 763 | `sandbox_type_local_network` | 1 | 7.2s |  |
| 764 | `scene_constr` | 8 | 7.4s |  |
| 765 | `selection` | 239 | 7.8s |  |
| 766 | `set_local_0` | 31 | 7.4s |  |
| 767 | `set_property_is_enumerable` | 85 | 7.8s |  |
| 768 | `shaderparameter_value` | 4 | 7.3s |  |
| 769 | `shape_drawrect` | 54 | 7.4s |  |
| 770 | `shared_object_no_root` | 3 | 7.3s |  |
| 771 | `simplebutton_added_to_stage` | 45 | 26.1s |  |
| 772 | `simplebutton_childevents` | 86 | 26.5s |  |
| 773 | `simplebutton_childevents_nested` | 54 | 7.7s |  |
| 774 | `simplebutton_childevents_sprite` | 13 | 7.5s |  |
| 775 | `simplebutton_childprops` | 144 | 7.6s |  |
| 776 | `simplebutton_childshuffle` | 23 | 7.3s |  |
| 777 | `simplebutton_constr` | 36 | 7.6s |  |
| 778 | `simplebutton_constr_childevents` | 48 | 7.7s |  |
| 779 | `simplebutton_constr_params` | 42 | 7.5s |  |
| 780 | `simplebutton_mouseenabled` | 26 | 7.3s |  |
| 781 | `simplebutton_multi_children` | 19 | 7.5s |  |
| 782 | `simplebutton_structure` | 27 | 7.6s |  |
| 783 | `simplebutton_symbolclass` | 68 | 7.7s |  |
| 784 | `slot_disp_id_shared_numbering` | 1 | 25.8s |  |
| 785 | `slots_force_autoassigned` | 1 | 7.4s |  |
| 786 | `socket_after_disconnect` | 1 | 7.4s |  |
| 787 | `socket_close` | 2 | 7.3s |  |
| 788 | `socket_connect` | 4 | 7.3s |  |
| 789 | `socket_errors` | 56 | 7.8s |  |
| 790 | `socket_read_big` | 48 | 7.4s |  |
| 791 | `socket_read_little` | 48 | 10.8s |  |
| 792 | `socket_read_write_object` | 8 | 7.3s |  |
| 793 | `socket_write_big` | 15 | 7.5s |  |
| 794 | `socket_write_little` | 14 | 7.3s |  |
| 795 | `sound_embeddedprops` | 26 | 7.5s |  |
| 796 | `sound_play` | 19 | 7.5s |  |
| 797 | `sound_valueof` | 33 | 7.4s |  |
| 798 | `soundchannel_soundtransform` | 835 | 28.7s |  |
| 799 | `soundchannel_soundtransform_exists` | 5 | 26.8s |  |
| 800 | `soundchannel_stop` | 8 | 7.5s |  |
| 801 | `soundmixer_buffertime` | 5 | 7.3s |  |
| 802 | `soundmixer_stopall` | 6 | 7.4s |  |
| 803 | `soundtransform` | 442 | 9.1s |  |
| 804 | `space_justifier_clone` | 12 | 3.2s |  |
| 805 | `sprite_with_frames` | 0 | 27.1s |  |
| 806 | `stage3d_agal_cross_product` | 0 | 10.1s |  |
| 807 | `stage3d_agal_upload_errors` | 66 | 10.1s |  |
| 808 | `stage3d_bitmap` | 0 | 32.0s |  |
| 809 | `stage3d_blend` | 81 | 31.0s |  |
| 810 | `stage3d_context3d_string_args` | 158 | 8.4s |  |
| 811 | `stage3d_errors` | 7 | 7.4s |  |
| 812 | `stage3d_errors_atf` | 3 | 8.7s |  |
| 813 | `stage3d_errors_swf_29` | 6 | 7.5s |  |
| 814 | `stage3d_float1_index` | 0 | 29.4s |  |
| 815 | `stage3d_fractal` | 0 | 29.7s |  |
| 816 | `stage3d_ignore_sampler_override` | 0 | 29.6s |  |
| 817 | `stage3d_multistage_triangle` | 3 | 10.3s |  |
| 818 | `stage3d_program_constants_bytearray_be` | 0 | 30.8s |  |
| 819 | `stage3d_program_constants_bytearray_le` | 0 | 10.8s |  |
| 820 | `stage3d_program_constants_invalid_input` | 21 | 8.3s |  |
| 821 | `stage3d_raytrace` | 0 | 34.6s |  |
| 822 | `stage3d_rotating_cube` | 0 | 11.1s |  |
| 823 | `stage3d_sampler` | 0 | 10.2s |  |
| 824 | `stage3d_sampler_partial_upload` | 0 | 12.8s |  |
| 825 | `stage3d_stencil` | 0 | 29.4s |  |
| 826 | `stage3d_texture` | 0 | 14.5s |  |
| 827 | `stage3d_texture_bytearray` | 0 | 10.6s |  |
| 828 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.9s |  |
| 829 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.1s |  |
| 830 | `stage3d_triangle` | 0 | 9.5s |  |
| 831 | `stage3d_triangle_bytes4` | 0 | 9.4s |  |
| 832 | `stage3d_triangle_float1` | 0 | 9.4s |  |
| 833 | `stage3d_triangle_index_upload` | 0 | 9.4s |  |
| 834 | `stage3d_x_y` | 22 | 7.0s |  |
| 835 | `stage_access` | 10 | 2.9s |  |
| 836 | `stage_displayobject_properties` | 24 | 6.8s |  |
| 837 | `stage_framerate_nan` | 7 | 2.9s |  |
| 838 | `stage_framerate_negative` | 6 | 6.9s |  |
| 839 | `stage_framerate_zero` | 6 | 6.9s |  |
| 840 | `stage_invalidate` | 38 | 7.1s |  |
| 841 | `stage_loaderinfo_properties` | 24 | 7.1s |  |
| 842 | `stage_mousechildren` | 2 | 6.8s |  |
| 843 | `stage_mouseenabled` | 15 | 6.8s |  |
| 844 | `stage_overriden_setters` | 31 | 6.9s |  |
| 845 | `stage_properties` | 30 | 6.8s |  |
| 846 | `stage_stage3Ds_vector` | 1 | 25.8s |  |
| 847 | `static_var_with_this_in_ctor` | 2 | 6.8s |  |
| 848 | `stored_properties` | 11 | 6.9s |  |
| 849 | `strict_equality` | 34 | 6.9s |  |
| 850 | `string_call` | 13 | 6.8s |  |
| 851 | `string_case` | 23 | 6.9s |  |
| 852 | `string_char_at` | 27 | 6.9s |  |
| 853 | `string_char_code_at` | 28 | 6.8s |  |
| 854 | `string_concat_fromcharcode` | 37 | 6.8s |  |
| 855 | `string_constr` | 25 | 6.9s |  |
| 856 | `string_indexof_lastindexof` | 87 | 7.1s |  |
| 857 | `string_length` | 16 | 8.3s |  |
| 858 | `string_locale_compare` | 39 | 6.0s |  |
| 859 | `string_match` | 51 | 5.9s |  |
| 860 | `string_relational_compare` | 4 | 5.7s |  |
| 861 | `string_replace` | 51 | 5.8s |  |
| 862 | `string_search` | 41 | 5.8s |  |
| 863 | `string_slice_substr_substring` | 170 | 6.5s |  |
| 864 | `string_split` | 29 | 6.0s |  |
| 865 | `string_substr_negative` | 21 | 5.8s |  |
| 866 | `string_substr_weird` | 182 | 5.7s |  |
| 867 | `subtract` | 1058 | 14.7s |  |
| 868 | `super_get_call` | 12 | 5.9s |  |
| 869 | `supercall_two_classobjects` | 2 | 6.2s |  |
| 870 | `swf8` | 1 | 5.8s |  |
| 871 | `swf_10_queued_goto_scripts_construct` | 52 | 6.0s |  |
| 872 | `swf_9_goto_in_enter_frame` | 17 | 5.9s |  |
| 873 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.0s |  |
| 874 | `swf_9_queued_goto_scripts` | 6 | 5.8s |  |
| 875 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 876 | `swf_9_versioning` | 2 | 5.8s |  |
| 877 | `swf_wrong_frame_count` | 38 | 6.1s |  |
| 878 | `swf_wrong_frame_count_isplaying` | 22 | 20.5s |  |
| 879 | `symbol_class_binary_data` | 8 | 5.8s |  |
| 880 | `symbol_class_conflict` | 4 | 6.1s |  |
| 881 | `symbol_class_root_not_zero` | 1 | 5.7s |  |
| 882 | `symbolclass_invalid_utf8` | 2 | 5.7s |  |
| 883 | `tab_ordering_arrows` | 998 | 22.1s |  |
| 884 | `tab_ordering_automatic_advanced` | 184 | 30.9s |  |
| 885 | `tab_ordering_automatic_basic` | 45 | 7.2s |  |
| 886 | `tab_ordering_children` | 116 | 7.2s |  |
| 887 | `tab_ordering_custom_basic` | 34 | 7.0s |  |
| 888 | `tab_ordering_stage_tab_children` | 32 | 7.1s |  |
| 889 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.9s |  |
| 890 | `tab_ordering_tabbable` | 47 | 7.2s |  |
| 891 | `tabstop_properties` | 105 | 7.3s |  |
| 892 | `text_element_basic` | 34 | 7.2s |  |
| 893 | `text_engine_fontdescription` | 27 | 7.1s |  |
| 894 | `text_engine_groupelement` | 64 | 7.8s |  |
| 895 | `text_run` | 7 | 6.9s |  |
| 896 | `textblock_createline_errors` | 23 | 7.2s |  |
| 897 | `textblock_createline_fte` | 9 | 25.6s |  |
| 898 | `textblock_properties` | 118 | 7.5s |  |
| 899 | `textbox_click` | 37 | 25.6s |  |
| 900 | `textfield_event` | 66 | 7.2s |  |
| 901 | `textfield_focusin_event` | 9 | 7.0s |  |
| 902 | `textfield_input_dead_keys_windows` | 15 | 7.0s |  |
| 903 | `textfield_unload` | 39 | 25.4s |  |
| 904 | `textformat` | 1134 | 7.0s |  |
| 905 | `textformat_display` | 14 | 7.0s |  |
| 906 | `textformat_font_max_length` | 4 | 2.8s |  |
| 907 | `textline_inapplicable_properties` | 10 | 6.9s |  |
| 908 | `textline_name` | 1 | 6.9s |  |
| 909 | `textline_splitting_basic` | 76 | 7.1s |  |
| 910 | `textline_throwerror` | 30 | 6.9s |  |
| 911 | `textline_validity` | 162 | 6.9s |  |
| 912 | `throw` | 3 | 6.7s |  |
| 913 | `timeline_scripts` | 3 | 6.9s |  |
| 914 | `timer` | 90 | 7.8s |  |
| 915 | `timer_events` | 3 | 7.1s |  |
| 916 | `timer_finished` | 11 | 3.1s |  |
| 917 | `timer_reset` | 8 | 7.1s |  |
| 918 | `timer_setdelay` | 5 | 7.1s |  |
| 919 | `trace` | 12 | 6.8s |  |
| 920 | `truthiness` | 30 | 6.0s |  |
| 921 | `try_catch` | 11 | 3.5s |  |
| 922 | `try_catch_typed` | 12 | 0.9s |  |
| 923 | `typeof` | 30 | 0.9s |  |
| 924 | `uint_constr` | 92 | 0.9s |  |
| 925 | `uint_tofixed` | 1215 | 0.9s |  |
| 926 | `uint_tostring` | 3375 | 0.9s |  |
| 927 | `unchecked_function` | 15 | 0.9s |  |
| 928 | `unescape` | 28 | 0.9s |  |
| 929 | `url_loader` | 25 | 0.9s |  |
| 930 | `urlrequest` | 18 | 0.9s |  |
| 931 | `urlstream_basic` | 5 | 0.9s |  |
| 932 | `urshift` | 1058 | 2.0s |  |
| 933 | `utils3d` | 7 | 0.9s |  |
| 934 | `vector3d` | 397 | 0.9s |  |
| 935 | `vector_class` | 36 | 0.9s |  |
| 936 | `vector_class_call` | 11 | 0.9s |  |
| 937 | `vector_coercion` | 66 | 0.9s |  |
| 938 | `vector_concat` | 90 | 0.9s |  |
| 939 | `vector_constr` | 107 | 0.9s |  |
| 940 | `vector_enumeration` | 5 | 0.9s |  |
| 941 | `vector_every` | 92 | 0.9s |  |
| 942 | `vector_filter` | 95 | 0.9s |  |
| 943 | `vector_holes` | 24 | 0.9s |  |
| 944 | `vector_indexof` | 302 | 0.9s |  |
| 945 | `vector_insertat` | 270 | 0.9s |  |
| 946 | `vector_int_access` | 4 | 0.9s |  |
| 947 | `vector_int_delete` | 11 | 0.9s |  |
| 948 | `vector_join` | 58 | 0.9s |  |
| 949 | `vector_lastindexof` | 302 | 0.9s |  |
| 950 | `vector_legacy` | 10 | 0.9s |  |
| 951 | `vector_map` | 85 | 0.9s |  |
| 952 | `vector_object_final` | 1 | 0.9s |  |
| 953 | `vector_object_toString` | 10 | 0.9s |  |
| 954 | `vector_pushpop` | 255 | 0.9s |  |
| 955 | `vector_reborrow_bug` | 10 | 0.9s |  |
| 956 | `vector_removeat` | 172 | 11.7s |  |
| 957 | `vector_reverse` | 232 | 8.4s |  |
| 958 | `vector_shiftunshift` | 252 | 7.2s |  |
| 959 | `vector_slice` | 331 | 8.8s |  |
| 960 | `vector_sort` | 905 | 15.9s |  |
| 961 | `vector_splice` | 693 | 10.9s |  |
| 962 | `vector_splice_fixed_bug_compat` | 4 | 7.4s |  |
| 963 | `vector_tostring` | 79 | 7.9s |  |
| 964 | `verification` | 8 | 7.4s |  |
| 965 | `verify_abnormal_loop` | 1 | 7.2s |  |
| 966 | `verify_dxns_without_flag` | 3 | 7.6s |  |
| 967 | `verify_exception_targets_edge_case` | 1 | 7.2s |  |
| 968 | `verify_jump_to_middle_of_op` | 1 | 7.2s |  |
| 969 | `verify_lookup_switch_edge_case` | 1 | 7.2s |  |
| 970 | `verify_stack` | 5 | 7.3s |  |
| 971 | `verify_unreachable_exception` | 2 | 7.2s |  |
| 972 | `versioned_isplaying` | 2 | 7.3s |  |
| 973 | `virtual_properties` | 16 | 7.4s |  |
| 974 | `with` | 4 | 7.3s |  |
| 975 | `wrong_arg_count` | 7 | 7.5s |  |
| 976 | `xml_abstract_equality` | 36 | 7.5s |  |
| 977 | `xml_advanced` | 52 | 7.3s |  |
| 978 | `xml_appendchild` | 10 | 7.3s |  |
| 979 | `xml_as_attribute` | 9 | 7.3s |  |
| 980 | `xml_attribute` | 35 | 7.5s |  |
| 981 | `xml_attribute_name` | 40 | 7.3s |  |
| 982 | `xml_basic` | 33 | 7.4s |  |
| 983 | `xml_child` | 25 | 7.4s |  |
| 984 | `xml_childindex` | 7 | 7.3s |  |
| 985 | `xml_children` | 43 | 7.9s |  |
| 986 | `xml_class_call` | 9 | 7.3s |  |
| 987 | `xml_contains` | 197 | 7.4s |  |
| 988 | `xml_copy` | 20 | 3.2s |  |
| 989 | `xml_ctor_from_tostring` | 23 | 9.9s |  |
| 990 | `xml_delete` | 114 | 6.5s |  |
| 991 | `xml_descendants` | 83 | 6.4s |  |
| 992 | `xml_elements` | 6 | 6.6s |  |
| 993 | `xml_equals_namespace_check` | 2 | 6.3s |  |
| 994 | `xml_explicit_use_namespace` | 5 | 7.0s |  |
| 995 | `xml_getdescendants_qname` | 21 | 6.0s |  |
| 996 | `xml_has_property_via_in` | 26 | 7.1s |  |
| 997 | `xml_hasownproperty` | 6 | 6.2s |  |
| 998 | `xml_ignore_white` | 6 | 6.2s |  |
| 999 | `xml_length` | 2 | 6.3s |  |
| 1000 | `xml_list_as_attribute` | 9 | 6.3s |  |
| 1001 | `xml_list_concat` | 20 | 6.4s |  |
| 1002 | `xml_list_enumerate` | 4 | 6.3s |  |
| 1003 | `xml_methods_settings` | 3 | 6.6s |  |
| 1004 | `xml_mismatched_tag` | 37 | 6.4s |  |
| 1005 | `xml_namespace` | 39 | 2.5s |  |
| 1006 | `xml_namespace_methods` | 245 | 6.4s |  |
| 1007 | `xml_namespaced_property` | 7 | 6.3s |  |
| 1008 | `xml_no_namespace` | 1 | 6.2s |  |
| 1009 | `xml_nodekind` | 3 | 6.3s |  |
| 1010 | `xml_normalize` | 35 | 6.2s |  |
| 1011 | `xml_notification_bubbling` | 361 | 6.3s |  |
| 1012 | `xml_parent` | 8 | 6.2s |  |
| 1013 | `xml_set_children` | 17 | 6.3s |  |
| 1014 | `xml_set_name` | 34 | 6.3s |  |
| 1015 | `xml_settings` | 6 | 2.5s |  |
| 1016 | `xml_simple_complex_content` | 47 | 6.3s |  |
| 1017 | `xml_socket` | 11 | 6.6s |  |
| 1018 | `xml_text` | 7 | 6.3s |  |
| 1019 | `xml_tostring` | 6 | 6.2s |  |
| 1020 | `xml_tostring_namespace` | 12 | 6.3s |  |
| 1021 | `xml_unescaping` | 23 | 6.3s |  |
| 1022 | `xml_weird_ignores` | 54 | 6.4s |  |
| 1023 | `xml_wildcard` | 11 | 6.4s |  |
| 1024 | `xmldocument` | 254 | 6.3s |  |
| 1025 | `xmlnode` | 3540 | 6.5s |  |
| 1026 | `zero_frame_clip` | 3 | 6.4s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 7.1s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 7.3s |  |
| 3 | `blend_transform` | 1 | 1 | 7.4s |  |
| 4 | `coerce_property` | 3 | 3 | 7.4s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 3.3s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 7.3s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.8s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 29.5s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 7.5s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.1s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 7.2s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 7.7s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 23.2s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 23.5s |  |
| 15 | `int_toexponential` | 76 | 76 | 7.1s |  |
| 16 | `int_toprecision` | 441 | 441 | 7.0s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.6s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 7.3s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 26.0s |  |
| 20 | `soundchannel_position` | 74 | 74 | 27.5s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 7.6s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 7.4s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 20.9s |  |
| 24 | `uint_toexponential` | 100 | 100 | 1.1s |  |
| 25 | `uint_toprecision` | 433 | 433 | 0.9s |  |
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
| 1 | `method_without_body` | exit code 1 | 28.5s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 5.9s |  |
| 3 | `verify_typecheck` | exit code 1 | 3.1s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**167 tests** with output mismatch, sorted by match rate (best first)

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
| 84 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 85 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 86 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 87 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 88 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 89 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 90 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 91 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 92 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 93 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 94 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 95 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 96 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 97 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 98 | `all_classes/display/swf9` | 0.1% | 2/1959 | 350 | 1959 |  |
| 99 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 100 | `all_classes/events/swf9` | 0.1% | 1/1030 | 184 | 1030 |  |
| 101 | `all_classes/events/swf30` | 0.1% | 2/2353 | 184 | 2353 |  |
| 102 | `all_classes/display/swf10` | 0.1% | 2/2569 | 350 | 2569 |  |
| 103 | `all_classes/display/swf11` | 0.1% | 2/2593 | 350 | 2593 |  |
| 104 | `all_classes/display/swf12` | 0.1% | 2/2593 | 350 | 2593 |  |
| 105 | `all_classes/display/swf13` | 0.1% | 2/2671 | 350 | 2671 |  |
| 106 | `all_classes/events/swf10` | 0.1% | 1/1638 | 184 | 1638 |  |
| 107 | `all_classes/events/swf11` | 0.1% | 1/1750 | 184 | 1750 |  |
| 108 | `all_classes/events/swf12` | 0.1% | 1/1814 | 184 | 1814 |  |
| 109 | `abstract_classes` | 0.0% | 0/132 | 0 | 132 |  |
| 110 | `accessibility` | 0.0% | 0/1 | 0 | 1 |  |
| 111 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 112 | `air_ifilepromise` | 0.0% | 0/1 | 0 | 1 |  |
| 113 | `all_classes/accessibility/swf10` | 0.0% | 0/88 | 15 | 88 |  |
| 114 | `all_classes/accessibility/swf30` | 0.0% | 0/88 | 15 | 88 |  |
| 115 | `all_classes/accessibility/swf9` | 0.0% | 0/73 | 15 | 73 |  |
| 116 | `all_classes/display/swf30` | 0.0% | 0/2936 | 350 | 2936 |  |
| 117 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 118 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 119 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 120 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 121 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 122 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 123 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 124 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 125 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 126 | `applicationdomain_getqualifieddefinitionnames` | 0.0% | 0/9 | 0 | 9 |  |
| 127 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 128 | `av_tag_data` | 0.0% | 0/2 | 0 | 2 |  |
| 129 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 130 | `constructprop_method` | 0.0% | 0/2 | 0 | 2 |  |
| 131 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 132 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 133 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 134 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 135 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 136 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 137 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 138 | `game_input` | 0.0% | 0/4 | 0 | 4 |  |
| 139 | `generate_random_bytes` | 0.0% | 0/3 | 0 | 3 |  |
| 140 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 141 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 142 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 143 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 144 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 145 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 146 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 147 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 148 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 149 | `print_job_options` | 0.0% | 0/3 | 0 | 3 |  |
| 150 | `property_priority_definition_names_order` | 0.0% | 0/2 | 0 | 2 |  |
| 151 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 152 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 153 | `security_domain_current` | 0.0% | 0/2 | 0 | 2 |  |
| 154 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 155 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 156 | `static_text` | 0.0% | 0/3 | 1 | 3 |  |
| 157 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 158 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 159 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 160 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 161 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 162 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 163 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 164 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 165 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 166 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 167 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
