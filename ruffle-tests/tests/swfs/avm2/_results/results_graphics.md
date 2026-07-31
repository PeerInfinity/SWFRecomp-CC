# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-31 14:52 UTC

**Git SHA**: `a28b3e2cbb`

**Run Duration**: 197m 21s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1222 |
| Passing | **1046** (85.6%) |
| Ruffle-matched | 26 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1072** (87.7%) |
| Failing | 150 |
| Total expected lines | 151259 |
| Matching lines | 117754 (77.8%) |
| Mismatched lines | 33505 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 147 | 98.0% |
| Runtime Error | 3 | 2.0% |

## Passing Tests

**1046 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 7.2s |  |
| 2 | `accessibility` | 1 | 7.1s |  |
| 3 | `add` | 1058 | 19.5s |  |
| 4 | `agal_compiler` | 13 | 9.7s |  |
| 5 | `air_datagram_socket` | 1 | 8.6s |  |
| 6 | `air_hidden_lookup` | 2 | 7.1s |  |
| 7 | `air_ifilepromise` | 1 | 7.1s |  |
| 8 | `all_classes/security/swf11` | 3 | 7.1s |  |
| 9 | `amf_array_serialization` | 17 | 9.0s |  |
| 10 | `amf_custom_obj` | 26 | 7.2s |  |
| 11 | `amf_dictionary` | 9 | 7.1s |  |
| 12 | `amf_function` | 46 | 7.2s |  |
| 13 | `amf_invalid_date` | 2 | 7.1s |  |
| 14 | `amf_missing_prop` | 6 | 7.1s |  |
| 15 | `amf_nondynamic_function_prop` | 6 | 6.8s |  |
| 16 | `amf_setter_error` | 8 | 7.0s |  |
| 17 | `amf_vector` | 40 | 7.3s |  |
| 18 | `amf_xml` | 6 | 6.9s |  |
| 19 | `application_domain` | 4 | 7.1s |  |
| 20 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.2s |  |
| 21 | `applicationdomain_hasdefinition_null` | 2 | 7.0s |  |
| 22 | `array_access` | 18 | 7.1s |  |
| 23 | `array_access_interpreter` | 4 | 7.1s |  |
| 24 | `array_access_no_pubns` | 2 | 6.9s |  |
| 25 | `array_concat` | 41 | 6.8s |  |
| 26 | `array_constr` | 10 | 6.5s |  |
| 27 | `array_delete` | 44 | 6.7s |  |
| 28 | `array_enumeration` | 10 | 6.7s |  |
| 29 | `array_enumeration_elements` | 11 | 6.7s |  |
| 30 | `array_every` | 8 | 6.8s |  |
| 31 | `array_filter` | 6 | 6.7s |  |
| 32 | `array_foreach` | 18 | 6.6s |  |
| 33 | `array_hasownproperty` | 11 | 2.7s |  |
| 34 | `array_holes` | 9 | 6.8s |  |
| 35 | `array_index_max` | 84 | 6.6s |  |
| 36 | `array_indexof` | 25 | 6.6s |  |
| 37 | `array_join` | 26 | 6.6s |  |
| 38 | `array_lastindexof` | 29 | 6.6s |  |
| 39 | `array_length` | 14 | 6.6s |  |
| 40 | `array_literal` | 3 | 6.7s |  |
| 41 | `array_map` | 8 | 7.2s |  |
| 42 | `array_pop` | 52 | 7.0s |  |
| 43 | `array_push` | 24 | 6.9s |  |
| 44 | `array_reborrow_bug` | 6 | 6.5s |  |
| 45 | `array_reverse` | 28 | 6.5s |  |
| 46 | `array_shift` | 51 | 2.8s |  |
| 47 | `array_slice` | 39 | 6.5s |  |
| 48 | `array_some` | 8 | 6.5s |  |
| 49 | `array_sort` | 297 | 6.9s |  |
| 50 | `array_sort_fun_swf12` | 2 | 6.7s |  |
| 51 | `array_sort_fun_swf13` | 2 | 1.1s |  |
| 52 | `array_sort_random` | 210 | 6.7s |  |
| 53 | `array_sort_swf10_32bit` | 1 | 7.0s |  |
| 54 | `array_sorton` | 545 | 8.1s |  |
| 55 | `array_sparse_ops` | 41 | 7.5s |  |
| 56 | `array_splice` | 133 | 7.6s |  |
| 57 | `array_splice2` | 428 | 7.5s |  |
| 58 | `array_splice_types` | 48 | 7.5s |  |
| 59 | `array_storage` | 8 | 7.6s |  |
| 60 | `array_tolocalestring` | 9 | 7.4s |  |
| 61 | `array_tostring` | 12 | 7.4s |  |
| 62 | `array_unshift` | 24 | 7.4s |  |
| 63 | `array_valueof` | 9 | 7.4s |  |
| 64 | `array_vector_null_callback` | 10 | 7.4s |  |
| 65 | `astype` | 28 | 7.5s |  |
| 66 | `astypelate` | 24 | 7.6s |  |
| 67 | `astypelate_propagates` | 1 | 7.5s |  |
| 68 | `asymmetric_key_events` | 11 | 7.7s |  |
| 69 | `av_networking_params` | 9 | 7.4s |  |
| 70 | `av_tag_data` | 2 | 7.3s |  |
| 71 | `avm2_catchup_dobj` | 158 | 7.9s |  |
| 72 | `away3d_advanced_shallow_water_demo` | 0 | 86.6s |  |
| 73 | `bevel_filter` | 187 | 7.6s |  |
| 74 | `bitand` | 1058 | 19.7s |  |
| 75 | `bitmap_constr` | 17 | 7.8s |  |
| 76 | `bitmap_data` | 1000 | 16.2s |  |
| 77 | `bitmap_pixelsnapping` | 2 | 27.4s |  |
| 78 | `bitmap_properties` | 23 | 7.3s |  |
| 79 | `bitmap_subclass` | 7 | 8.9s |  |
| 80 | `bitmap_subclass_properties` | 9 | 7.7s |  |
| 81 | `bitmap_timeline` | 9 | 7.5s |  |
| 82 | `bitmapdata_accuracy` | 1 | 46.8s |  |
| 83 | `bitmapdata_applyfilter_blur` | 0 | 28.9s |  |
| 84 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.2s |  |
| 85 | `bitmapdata_applyfilter_destpoint` | 0 | 28.3s |  |
| 86 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 28.2s |  |
| 87 | `bitmapdata_clone` | 13 | 7.8s |  |
| 88 | `bitmapdata_colortransform` | 0 | 7.9s |  |
| 89 | `bitmapdata_colortransform_oob` | 2 | 7.3s |  |
| 90 | `bitmapdata_constr` | 22 | 7.3s |  |
| 91 | `bitmapdata_constructor_from_timeline` | 1 | 7.5s |  |
| 92 | `bitmapdata_copychannel` | 0 | 32.5s |  |
| 93 | `bitmapdata_copypixels` | 23 | 30.8s |  |
| 94 | `bitmapdata_copypixels_blend_over` | 1 | 7.9s |  |
| 95 | `bitmapdata_copypixelstobytearray` | 39 | 7.5s |  |
| 96 | `bitmapdata_dispose` | 7 | 7.6s |  |
| 97 | `bitmapdata_draw` | 0 | 29.5s |  |
| 98 | `bitmapdata_draw_colortransform` | 0 | 7.8s |  |
| 99 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 28.3s |  |
| 100 | `bitmapdata_draw_filters` | 0 | 27.6s |  |
| 101 | `bitmapdata_draw_masks` | 0 | 7.5s |  |
| 102 | `bitmapdata_draw_rotation` | 0 | 7.8s |  |
| 103 | `bitmapdata_draw_self_via_graphic` | 0 | 7.7s |  |
| 104 | `bitmapdata_draw_stage` | 0 | 27.2s |  |
| 105 | `bitmapdata_drawwithquality` | 0 | 7.8s |  |
| 106 | `bitmapdata_embedded` | 9 | 7.8s |  |
| 107 | `bitmapdata_fillrect` | 0 | 7.7s |  |
| 108 | `bitmapdata_filter_sourcerect` | 0 | 28.3s |  |
| 109 | `bitmapdata_floodfill` | 35 | 7.5s |  |
| 110 | `bitmapdata_getpixels` | 39 | 28.2s |  |
| 111 | `bitmapdata_getvector` | 27 | 3.3s |  |
| 112 | `bitmapdata_histogram` | 59 | 3.3s |  |
| 113 | `bitmapdata_hittest` | 112 | 8.1s |  |
| 114 | `bitmapdata_hittest_threshold` | 18 | 7.6s |  |
| 115 | `bitmapdata_opaque` | 0 | 7.8s |  |
| 116 | `bitmapdata_pixeldissolve` | 1037 | 8.2s |  |
| 117 | `bitmapdata_pixeldissolve_image` | 0 | 7.9s |  |
| 118 | `bitmapdata_rectangle_rounding` | 16 | 7.3s |  |
| 119 | `bitmapdata_setpixels` | 286 | 7.6s |  |
| 120 | `bitmapdata_setvector` | 26 | 7.4s |  |
| 121 | `bitmapdata_sync` | 0 | 27.2s |  |
| 122 | `bitmapdata_threshold` | 176 | 8.5s |  |
| 123 | `bitnot` | 46 | 7.6s |  |
| 124 | `bitor` | 1058 | 19.9s |  |
| 125 | `bitxor` | 1058 | 20.0s |  |
| 126 | `blend_mode_null` | 1 | 7.6s |  |
| 127 | `blend_multiply_alpha` | 0 | 7.9s |  |
| 128 | `blend_scroll` | 0 | 7.8s |  |
| 129 | `blend_shader_luma_lighten` | 3 | 8.3s |  |
| 130 | `blur_filter` | 43 | 7.2s |  |
| 131 | `boolean_constr` | 32 | 7.1s |  |
| 132 | `boolean_negation` | 30 | 7.2s |  |
| 133 | `boolean_tostring` | 8 | 7.1s |  |
| 134 | `broadcast_event` | 7 | 7.2s |  |
| 135 | `button_bounds` | 1 | 7.2s |  |
| 136 | `button_hittest` | 2 | 25.6s |  |
| 137 | `button_nested_frame` | 48 | 26.1s |  |
| 138 | `bytearray` | 48 | 7.4s |  |
| 139 | `bytearray_compress` | 31 | 7.1s |  |
| 140 | `bytearray_errors` | 24 | 7.2s |  |
| 141 | `bytearray_method_serialization` | 1 | 7.0s |  |
| 142 | `bytearray_oom` | 3 | 7.1s |  |
| 143 | `bytearray_readobject_amf0` | 50 | 7.1s |  |
| 144 | `bytearray_readobject_amf3` | 53 | 7.1s |  |
| 145 | `bytearray_readutf8bytes_with_bom` | 16 | 7.1s |  |
| 146 | `bytearray_serialization` | 3 | 7.1s |  |
| 147 | `bytearray_string_null` | 19 | 7.3s |  |
| 148 | `bytearray_tostring` | 15 | 7.1s |  |
| 149 | `bytearray_utf16` | 8 | 7.0s |  |
| 150 | `bytearray_writeobject` | 24 | 7.0s |  |
| 151 | `callee_in_initializer` | 6 | 7.0s |  |
| 152 | `callproplex_class` | 1 | 7.0s |  |
| 153 | `capabilities_resolution` | 8 | 26.5s |  |
| 154 | `catch_class` | 6 | 7.1s |  |
| 155 | `catch_scope_slot` | 7 | 3.1s |  |
| 156 | `checkfilter` | 4 | 3.0s |  |
| 157 | `class_call` | 32 | 7.2s |  |
| 158 | `class_cast_call` | 14 | 7.1s |  |
| 159 | `class_enumeration` | 4 | 7.1s |  |
| 160 | `class_has_own_property` | 2 | 7.1s |  |
| 161 | `class_init_interpreter_mode` | 1 | 7.0s |  |
| 162 | `class_is` | 32 | 7.2s |  |
| 163 | `class_methods` | 5 | 7.1s |  |
| 164 | `class_object_properties` | 10 | 7.1s |  |
| 165 | `class_singleton` | 18 | 7.2s |  |
| 166 | `class_supercalls_errors` | 35 | 7.3s |  |
| 167 | `class_supercalls_mismatched` | 26 | 7.2s |  |
| 168 | `class_superclass_wrong_order` | 1 | 20.6s |  |
| 169 | `class_to_locale_string` | 2 | 5.7s |  |
| 170 | `class_to_string` | 2 | 5.9s |  |
| 171 | `class_value_of` | 2 | 5.7s |  |
| 172 | `click_block` | 5 | 6.5s |  |
| 173 | `click_invisible` | 3 | 5.8s |  |
| 174 | `closures` | 12 | 5.7s |  |
| 175 | `coerce_return_type` | 40 | 5.9s |  |
| 176 | `coerce_return_type_fail` | 2 | 6.7s |  |
| 177 | `coerce_return_void` | 3 | 5.7s |  |
| 178 | `coerce_string` | 86 | 5.8s |  |
| 179 | `coerce_string_precision` | 28 | 5.7s |  |
| 180 | `coerce_to_primitive_side_effects` | 29 | 5.7s |  |
| 181 | `color_matrix_filter` | 19 | 5.7s |  |
| 182 | `construct_errors_swf10` | 8 | 5.7s |  |
| 183 | `construct_frame_list` | 22 | 21.0s |  |
| 184 | `construct_interface` | 3 | 5.7s |  |
| 185 | `constructor_call` | 3 | 5.6s |  |
| 186 | `constructors_vs_timeline` | 5 | 21.4s |  |
| 187 | `constructprop_dynamic_primitive` | 7 | 6.0s |  |
| 188 | `constructprop_method` | 2 | 5.7s |  |
| 189 | `content_element_basic` | 50 | 6.1s |  |
| 190 | `context3d_creation` | 9 | 5.8s |  |
| 191 | `control_flow_bool` | 4 | 5.8s |  |
| 192 | `control_flow_stricteq` | 8 | 5.7s |  |
| 193 | `convert_boolean` | 30 | 5.7s |  |
| 194 | `convert_integer` | 90 | 5.8s |  |
| 195 | `convert_number` | 56 | 6.1s |  |
| 196 | `convert_uinteger` | 90 | 5.8s |  |
| 197 | `convolution_filter` | 89 | 6.0s |  |
| 198 | `cpool_index_invalid_bytecode_1` | 6 | 5.8s |  |
| 199 | `cpool_index_invalid_bytecode_2` | 3 | 5.6s |  |
| 200 | `cpool_index_invalid_bytecode_3` | 1 | 5.6s |  |
| 201 | `cross_api_version_call_older` | 12 | 6.2s |  |
| 202 | `cryptscore` | 11 | 5.7s |  |
| 203 | `date` | 30 | 7.8s |  |
| 204 | `date_parse` | 36 | 7.3s |  |
| 205 | `declocal` | 46 | 7.3s |  |
| 206 | `declocal_i` | 46 | 7.3s |  |
| 207 | `decode_uri` | 71 | 7.6s |  |
| 208 | `decrement` | 46 | 7.3s |  |
| 209 | `decrement_i` | 46 | 3.2s |  |
| 210 | `default_values` | 7 | 7.3s |  |
| 211 | `dictionary_access` | 62 | 7.6s |  |
| 212 | `dictionary_access_no_pubns` | 2 | 7.2s |  |
| 213 | `dictionary_delete` | 101 | 7.8s |  |
| 214 | `dictionary_foreach` | 42 | 7.5s |  |
| 215 | `dictionary_hasownproperty` | 63 | 7.6s |  |
| 216 | `dictionary_in` | 62 | 7.6s |  |
| 217 | `dictionary_iter_modify` | 8 | 7.3s |  |
| 218 | `dictionary_namespaces` | 36 | 7.4s |  |
| 219 | `dictionary_primitive_keys` | 29 | 7.3s |  |
| 220 | `displacement_map_filter` | 61 | 7.5s |  |
| 221 | `displayobject_alpha` | 277 | 7.2s |  |
| 222 | `displayobject_blendmode` | 0 | 7.5s |  |
| 223 | `displayobject_colortransform_nested` | 0 | 26.6s |  |
| 224 | `displayobject_filters` | 17 | 7.4s |  |
| 225 | `displayobject_from_enterframe` | 1 | 26.4s |  |
| 226 | `displayobject_getbounds_shape` | 0 | 26.4s |  |
| 227 | `displayobject_height` | 6052 | 26.3s |  |
| 228 | `displayobject_hittestobject` | 32 | 7.3s |  |
| 229 | `displayobject_hittestpoint` | 49 | 7.6s |  |
| 230 | `displayobject_hittestpoint_root` | 13 | 7.5s |  |
| 231 | `displayobject_invalid_floats` | 60 | 7.2s |  |
| 232 | `displayobject_invalid_props` | 3 | 7.2s |  |
| 233 | `displayobject_mask` | 3 | 7.5s |  |
| 234 | `displayobject_mask_self_referential` | 0 | 7.8s |  |
| 235 | `displayobject_metaData` | 3 | 7.7s |  |
| 236 | `displayobject_name` | 22 | 8.2s |  |
| 237 | `displayobject_name_from_timeline` | 24 | 8.1s |  |
| 238 | `displayobject_opaque_background` | 6 | 28.8s |  |
| 239 | `displayobject_parent` | 12 | 7.9s |  |
| 240 | `displayobject_root` | 24 | 7.9s |  |
| 241 | `displayobject_rotation` | 1284 | 8.0s |  |
| 242 | `displayobject_set_matrix_nested` | 0 | 28.8s |  |
| 243 | `displayobject_set_name_loaded` | 3 | 8.2s |  |
| 244 | `displayobject_subclass` | 2 | 7.8s |  |
| 245 | `displayobject_visible` | 23 | 7.7s |  |
| 246 | `displayobject_width` | 4852 | 28.4s |  |
| 247 | `displayobject_x` | 614 | 7.9s |  |
| 248 | `displayobject_y` | 617 | 7.9s |  |
| 249 | `displayobjectcontainer_addchild` | 32 | 7.9s |  |
| 250 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.8s |  |
| 251 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.0s |  |
| 252 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.9s |  |
| 253 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.9s |  |
| 254 | `displayobjectcontainer_addchildat` | 42 | 7.8s |  |
| 255 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 8.0s |  |
| 256 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.9s |  |
| 257 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.9s |  |
| 258 | `displayobjectcontainer_contains` | 66 | 28.2s |  |
| 259 | `displayobjectcontainer_getchildat` | 4 | 7.8s |  |
| 260 | `displayobjectcontainer_getchildbyname` | 9 | 7.7s |  |
| 261 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.7s |  |
| 262 | `displayobjectcontainer_getchildindex` | 28 | 7.8s |  |
| 263 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.9s |  |
| 264 | `displayobjectcontainer_removechild` | 10 | 7.7s |  |
| 265 | `displayobjectcontainer_removechild_errors` | 4 | 7.6s |  |
| 266 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.8s |  |
| 267 | `displayobjectcontainer_removechildat` | 18 | 7.7s |  |
| 268 | `displayobjectcontainer_removechildren` | 51 | 8.0s |  |
| 269 | `displayobjectcontainer_setchildindex` | 42 | 7.7s |  |
| 270 | `displayobjectcontainer_stopallmovieclips` | 2 | 8.2s |  |
| 271 | `displayobjectcontainer_swapchildren` | 42 | 7.8s |  |
| 272 | `displayobjectcontainer_swapchildrenat` | 42 | 7.8s |  |
| 273 | `displayobjectcontainer_timelineinstance` | 48 | 27.2s |  |
| 274 | `divide` | 1058 | 19.0s |  |
| 275 | `doabc_is_eager` | 1 | 26.5s |  |
| 276 | `documentclass` | 9 | 7.6s |  |
| 277 | `domain_memory` | 133 | 8.6s |  |
| 278 | `drag_drop` | 10 | 7.7s |  |
| 279 | `drop_shadow_filter` | 172 | 7.7s |  |
| 280 | `duplicate_defs` | 1 | 7.3s |  |
| 281 | `eager_init` | 1 | 7.5s |  |
| 282 | `east_asian_justifier_clone` | 8 | 3.3s |  |
| 283 | `edit_text_linkage` | 7 | 7.7s |  |
| 284 | `edittext_align` | 60 | 7.9s |  |
| 285 | `edittext_always_show_selection` | 0 | 27.4s |  |
| 286 | `edittext_antialiastype` | 296 | 7.8s |  |
| 287 | `edittext_at_point_methods_basic` | 16 | 8.9s |  |
| 288 | `edittext_autosize` | 39 | 8.0s |  |
| 289 | `edittext_autosize_align` | 0 | 27.8s |  |
| 290 | `edittext_autosize_height_dynamic` | 60 | 27.8s |  |
| 291 | `edittext_autosize_height_input` | 60 | 7.8s |  |
| 292 | `edittext_autosize_lazy_bounds_events` | 65 | 7.9s |  |
| 293 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.5s |  |
| 294 | `edittext_autosize_lazy_bounds_props` | 490 | 8.9s |  |
| 295 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.9s |  |
| 296 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.7s |  |
| 297 | `edittext_bottom_scroll_v_basic` | 210 | 7.6s |  |
| 298 | `edittext_bounds_scale` | 24 | 26.4s |  |
| 299 | `edittext_bullet` | 30 | 7.6s |  |
| 300 | `edittext_default_format` | 221 | 7.9s |  |
| 301 | `edittext_default_format_empty` | 136 | 7.8s |  |
| 302 | `edittext_empty_text_format` | 7 | 7.6s |  |
| 303 | `edittext_focus_selection` | 5 | 7.5s |  |
| 304 | `edittext_font_size` | 45 | 7.5s |  |
| 305 | `edittext_format_empty_font` | 8 | 7.5s |  |
| 306 | `edittext_get_char_index_at_point` | 4 | 28.0s |  |
| 307 | `edittext_get_line_index_at_point` | 2 | 26.8s |  |
| 308 | `edittext_get_line_index_of_char` | 76 | 8.2s |  |
| 309 | `edittext_getcharboundaries` | 172 | 7.7s |  |
| 310 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.8s |  |
| 311 | `edittext_getcharboundaries_scroll` | 85 | 7.8s |  |
| 312 | `edittext_getlinemetrics` | 146 | 7.8s |  |
| 313 | `edittext_html` | 3101 | 7.9s |  |
| 314 | `edittext_html_condensewhite` | 487 | 7.6s |  |
| 315 | `edittext_html_entity` | 4 | 7.8s |  |
| 316 | `edittext_html_font_size_swf12` | 267 | 7.6s |  |
| 317 | `edittext_html_font_size_swf13` | 273 | 7.3s |  |
| 318 | `edittext_html_roundtrip` | 17 | 7.6s |  |
| 319 | `edittext_ime_focus_lost` | 9 | 27.4s |  |
| 320 | `edittext_input_control` | 12 | 7.7s |  |
| 321 | `edittext_leading` | 9 | 7.8s |  |
| 322 | `edittext_letter_spacing` | 15 | 7.6s |  |
| 323 | `edittext_line_methods` | 294 | 9.0s |  |
| 324 | `edittext_line_metrics` | 11 | 28.2s |  |
| 325 | `edittext_margins` | 25 | 7.5s |  |
| 326 | `edittext_max_scroll_h_basic` | 475 | 7.6s |  |
| 327 | `edittext_max_scroll_v_basic` | 1000 | 7.6s |  |
| 328 | `edittext_mouse_selection` | 363 | 28.0s |  |
| 329 | `edittext_mousedown` | 3 | 7.8s |  |
| 330 | `edittext_mouseenabled` | 26 | 7.5s |  |
| 331 | `edittext_newline_character` | 22 | 7.5s |  |
| 332 | `edittext_newline_stripping` | 64 | 10.2s |  |
| 333 | `edittext_newlines` | 30 | 7.5s |  |
| 334 | `edittext_paragraph_methods` | 257 | 7.5s |  |
| 335 | `edittext_paste_events` | 8 | 7.6s |  |
| 336 | `edittext_paste_maxchars` | 4 | 7.5s |  |
| 337 | `edittext_paste_restrict` | 16 | 7.3s |  |
| 338 | `edittext_restrict` | 191 | 7.4s |  |
| 339 | `edittext_restrict_events` | 22 | 7.4s |  |
| 340 | `edittext_scrollh` | 10 | 7.3s |  |
| 341 | `edittext_selected_text` | 9 | 7.4s |  |
| 342 | `edittext_set_html_same` | 17 | 7.4s |  |
| 343 | `edittext_set_text_vs_html` | 9 | 7.3s |  |
| 344 | `edittext_stylesheet` | 536 | 7.8s |  |
| 345 | `edittext_stylesheet_custom_tag` | 76 | 7.5s |  |
| 346 | `edittext_stylesheet_display` | 272 | 7.5s |  |
| 347 | `edittext_underline` | 40 | 7.5s |  |
| 348 | `edittext_width_height` | 103 | 10.8s |  |
| 349 | `edittext_wordwrap_word` | 150 | 7.7s |  |
| 350 | `edittext_wrap_breaks` | 2375 | 7.9s |  |
| 351 | `element_format_clone` | 44 | 7.5s |  |
| 352 | `element_format_constructor_order` | 64 | 7.4s |  |
| 353 | `element_format_properties` | 235 | 8.3s |  |
| 354 | `empty_bounds` | 1 | 7.3s |  |
| 355 | `encode_uri_surrogate_pair_swf11` | 15 | 7.0s |  |
| 356 | `equals` | 512 | 11.3s |  |
| 357 | `error_geterrormessage` | 779 | 7.2s |  |
| 358 | `error_prototype` | 15 | 7.2s |  |
| 359 | `error_stack_trace_debug_swf17` | 0 | 26.1s |  |
| 360 | `error_stack_trace_debug_swf18` | 0 | 7.0s |  |
| 361 | `error_stack_trace_release_swf17` | 0 | 7.0s |  |
| 362 | `error_stack_trace_release_swf18` | 0 | 6.9s |  |
| 363 | `error_tostring` | 29 | 7.1s |  |
| 364 | `error_tostring_more` | 86 | 7.2s |  |
| 365 | `es3_inheritance` | 31 | 7.3s |  |
| 366 | `es4_inheritance` | 30 | 7.3s |  |
| 367 | `es4_interfaces` | 30 | 7.4s |  |
| 368 | `es4_method_binding` | 8 | 7.2s |  |
| 369 | `es4_oop_prototypes` | 14 | 7.4s |  |
| 370 | `es4_protected_inheritance` | 6 | 7.2s |  |
| 371 | `escape` | 71 | 7.3s |  |
| 372 | `event_bubbles` | 2 | 7.4s |  |
| 373 | `event_cancelable` | 2 | 7.3s |  |
| 374 | `event_clone` | 20 | 7.4s |  |
| 375 | `event_clone_error_redispatch` | 3 | 7.5s |  |
| 376 | `event_clone_on_redispatch` | 10 | 7.5s |  |
| 377 | `event_formattostring` | 31 | 7.3s |  |
| 378 | `event_isdefaultprevented` | 12 | 7.2s |  |
| 379 | `event_target_getter` | 5 | 3.2s |  |
| 380 | `event_target_set` | 9 | 7.2s |  |
| 381 | `event_type` | 1 | 10.6s |  |
| 382 | `event_valueof_tostring` | 18 | 7.6s |  |
| 383 | `eventdispatcher_dispatchevent` | 12 | 7.5s |  |
| 384 | `eventdispatcher_dispatchevent_cancel` | 20 | 7.6s |  |
| 385 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.6s |  |
| 386 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.5s |  |
| 387 | `eventdispatcher_dispatchevent_this` | 5 | 7.5s |  |
| 388 | `eventdispatcher_haseventlistener` | 25 | 7.5s |  |
| 389 | `eventdispatcher_interface_invoke` | 1 | 7.5s |  |
| 390 | `eventdispatcher_tostring` | 10 | 7.6s |  |
| 391 | `eventdispatcher_willtrigger` | 25 | 7.4s |  |
| 392 | `falsiness` | 30 | 7.5s |  |
| 393 | `fast_index_access` | 12 | 7.6s |  |
| 394 | `filefilter_properties` | 4 | 7.5s |  |
| 395 | `filereference_browse_cancel` | 3 | 7.5s |  |
| 396 | `filereference_browse_select` | 9 | 7.6s |  |
| 397 | `filereference_load` | 31 | 7.6s |  |
| 398 | `filereference_save` | 16 | 7.6s |  |
| 399 | `filereference_save_and_browse` | 42 | 7.5s |  |
| 400 | `filereference_save_and_load` | 22 | 7.6s |  |
| 401 | `filereference_uninitialized` | 8 | 7.5s |  |
| 402 | `filereferencelist_browse_cancel` | 6 | 7.6s |  |
| 403 | `filereferencelist_browse_select` | 7 | 7.6s |  |
| 404 | `filter_rewind` | 8 | 8.0s |  |
| 405 | `filters_array_holes` | 25 | 7.7s |  |
| 406 | `finddef` | 3 | 7.6s |  |
| 407 | `findprop_global_prototype` | 6 | 7.6s |  |
| 408 | `flash_media_video_constructor` | 156 | 8.3s |  |
| 409 | `flash_media_video_rotation_probe` | 27 | 7.6s |  |
| 410 | `flash_xml` | 29 | 7.5s |  |
| 411 | `flash_xml_cloneNode` | 22 | 7.5s |  |
| 412 | `flash_xml_namespace` | 109 | 7.5s |  |
| 413 | `flash_xml_removeNode` | 60 | 7.6s |  |
| 414 | `focus_events_code` | 161 | 27.8s |  |
| 415 | `focus_events_key_basic` | 132 | 27.9s |  |
| 416 | `focus_events_key_navigation` | 53 | 7.7s |  |
| 417 | `focus_events_key_same_object` | 26 | 7.7s |  |
| 418 | `focus_events_mixed_key_mouse` | 100 | 27.1s |  |
| 419 | `focus_events_mouse_basic` | 260 | 29.7s |  |
| 420 | `focus_events_mouse_focusable` | 112 | 26.7s |  |
| 421 | `focus_events_mouse_same_object` | 40 | 26.4s |  |
| 422 | `focus_remove` | 20 | 26.7s |  |
| 423 | `focus_root_movie` | 4 | 27.0s |  |
| 424 | `focus_stage` | 1 | 7.2s |  |
| 425 | `focusrect` | 18 | 8.0s |  |
| 426 | `focusrect_focuslost` | 9 | 7.3s |  |
| 427 | `focusrect_property` | 110 | 7.3s |  |
| 428 | `font_description_clone` | 14 | 7.3s |  |
| 429 | `font_embedded` | 24 | 7.7s |  |
| 430 | `font_enumeratefonts` | 41 | 7.9s |  |
| 431 | `font_enumeratefonts_filter` | 4 | 27.0s |  |
| 432 | `font_hasglyphs` | 40 | 7.7s |  |
| 433 | `framelabel_constr` | 5 | 7.3s |  |
| 434 | `function_call` | 12 | 7.3s |  |
| 435 | `function_call_arguments` | 46 | 7.3s |  |
| 436 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 437 | `function_call_coercion` | 108 | 7.7s |  |
| 438 | `function_call_default` | 6 | 7.2s |  |
| 439 | `function_call_rest` | 22 | 7.3s |  |
| 440 | `function_call_types` | 3 | 7.2s |  |
| 441 | `function_call_via_apply` | 11 | 7.3s |  |
| 442 | `function_call_via_call` | 3 | 7.3s |  |
| 443 | `function_display_anonymous` | 7 | 3.2s |  |
| 444 | `function_length` | 6 | 7.3s |  |
| 445 | `function_object` | 2 | 7.3s |  |
| 446 | `function_proto` | 5 | 7.3s |  |
| 447 | `function_proto_created` | 61 | 7.4s |  |
| 448 | `function_to_locale_string` | 4 | 7.3s |  |
| 449 | `function_to_string` | 4 | 7.1s |  |
| 450 | `function_type` | 6 | 7.2s |  |
| 451 | `function_unbound_this` | 51 | 7.3s |  |
| 452 | `function_value_of` | 4 | 7.2s |  |
| 453 | `game_input` | 4 | 7.2s |  |
| 454 | `generate_random_bytes` | 3 | 7.3s |  |
| 455 | `get_definition_by_name` | 11 | 7.2s |  |
| 456 | `get_qualified_class_name` | 20 | 10.7s |  |
| 457 | `get_qualified_super_class_name` | 18 | 7.2s |  |
| 458 | `get_slot_edge_cases` | 1 | 25.9s |  |
| 459 | `get_timer` | 2 | 7.3s |  |
| 460 | `getglobalslot` | 1 | 7.2s |  |
| 461 | `getouterscope` | 8 | 7.2s |  |
| 462 | `getter_different_namespace_setter` | 2 | 7.3s |  |
| 463 | `glow_filter` | 127 | 7.6s |  |
| 464 | `goto_button_nested_framescript` | 28 | 27.5s |  |
| 465 | `goto_in_constructframe` | 12 | 7.5s |  |
| 466 | `goto_in_scene_last_frame` | 2 | 26.2s |  |
| 467 | `goto_methods` | 56 | 7.5s |  |
| 468 | `goto_methods_swfver10` | 8 | 7.3s |  |
| 469 | `goto_nested_construct_sibling` | 18 | 7.5s |  |
| 470 | `goto_nested_framescript` | 9 | 7.3s |  |
| 471 | `goto_on_orphan` | 15 | 7.4s |  |
| 472 | `gradient_bevel_filter` | 206 | 7.3s |  |
| 473 | `gradient_glow_filter` | 206 | 7.1s |  |
| 474 | `graphics_bad_direct_commands` | 5 | 8.0s |  |
| 475 | `graphics_bitmap_fill` | 0 | 9.1s |  |
| 476 | `graphics_bitmaps` | 0 | 7.9s |  |
| 477 | `graphics_direct_commands` | 0 | 7.7s |  |
| 478 | `graphics_draw_triangles` | 98 | 26.6s |  |
| 479 | `graphics_gradients` | 0 | 7.5s |  |
| 480 | `graphics_gradients_nulls` | 0 | 7.3s |  |
| 481 | `graphics_path` | 56 | 7.2s |  |
| 482 | `graphics_round_rects` | 0 | 7.3s |  |
| 483 | `graphics_simple_shapes` | 0 | 7.8s |  |
| 484 | `greaterequals` | 512 | 11.6s |  |
| 485 | `greaterthan` | 512 | 11.6s |  |
| 486 | `has_own_property` | 102 | 7.9s |  |
| 487 | `hasownproperty_namespaces` | 2 | 7.3s |  |
| 488 | `hello_world` | 1 | 7.3s |  |
| 489 | `hittest_morph` | 30 | 7.5s |  |
| 490 | `if_eq` | 10 | 7.2s |  |
| 491 | `if_gt` | 1 | 7.2s |  |
| 492 | `if_gte` | 10 | 10.2s |  |
| 493 | `if_lt` | 1 | 7.2s |  |
| 494 | `if_lte` | 10 | 7.0s |  |
| 495 | `if_ne` | 7 | 3.1s |  |
| 496 | `if_stricteq` | 6 | 7.2s |  |
| 497 | `if_strictne` | 11 | 7.1s |  |
| 498 | `ime_linux_dead_keys` | 10 | 7.3s |  |
| 499 | `in` | 102 | 8.3s |  |
| 500 | `inclocal` | 46 | 7.8s |  |
| 501 | `inclocal_i` | 46 | 7.6s |  |
| 502 | `increment` | 46 | 7.7s |  |
| 503 | `increment_i` | 46 | 7.7s |  |
| 504 | `indexing_delete` | 75 | 7.7s |  |
| 505 | `instanceof` | 58 | 8.0s |  |
| 506 | `instantiation_on_enter_frame` | 7 | 28.9s |  |
| 507 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.7s |  |
| 508 | `int_constr` | 92 | 7.5s |  |
| 509 | `int_edge_cases` | 19 | 7.7s |  |
| 510 | `int_instanceof` | 3 | 7.4s |  |
| 511 | `int_tofixed` | 1215 | 7.1s |  |
| 512 | `int_tostring` | 3375 | 7.3s |  |
| 513 | `interactiveobject_enabled` | 25 | 7.2s |  |
| 514 | `interface_namespaces` | 78 | 7.5s |  |
| 515 | `is_finite` | 46 | 7.3s |  |
| 516 | `is_nan` | 46 | 7.2s |  |
| 517 | `is_prototype_of` | 12 | 7.2s |  |
| 518 | `issue_10221` | 2 | 7.2s |  |
| 519 | `issue_13780` | 12 | 7.2s |  |
| 520 | `issue_14901` | 1 | 7.2s |  |
| 521 | `issue_17675_edittext_paste_maxchars` | 1 | 7.3s |  |
| 522 | `issue_5292` | 5 | 7.2s |  |
| 523 | `issue_8630` | 2 | 26.0s |  |
| 524 | `issue_8630_scriptremove` | 11 | 7.2s |  |
| 525 | `istype` | 24 | 3.2s |  |
| 526 | `istypelate` | 58 | 7.4s |  |
| 527 | `istypelate_coerce` | 198 | 11.7s |  |
| 528 | `jpeg_loader_context` | 6 | 7.5s |  |
| 529 | `json_errors` | 9 | 26.7s |  |
| 530 | `json_parse` | 21 | 7.5s |  |
| 531 | `json_stringify` | 12 | 7.7s |  |
| 532 | `json_stringify_order` | 1 | 7.3s |  |
| 533 | `json_version_gated` | 1 | 7.3s |  |
| 534 | `key_input_80percent` | 1812 | 7.6s |  |
| 535 | `key_input_location` | 126 | 7.4s |  |
| 536 | `key_input_numpad` | 384 | 7.3s |  |
| 537 | `lazyinit` | 17 | 7.4s |  |
| 538 | `lessequals` | 512 | 11.2s |  |
| 539 | `lessthan` | 512 | 11.4s |  |
| 540 | `loader_bitmap_transparency` | 14 | 7.6s |  |
| 541 | `loader_bytes_unknown_content` | 14 | 7.5s |  |
| 542 | `loader_child_getdefinition` | 5 | 7.7s |  |
| 543 | `loader_duplicate_coerce` | 3 | 7.7s |  |
| 544 | `loader_duplicate_coerce_new_domain` | 4 | 7.5s |  |
| 545 | `loader_error_in_root_ctor` | 4 | 7.7s |  |
| 546 | `loader_events` | 92 | 8.3s |  |
| 547 | `loader_image` | 8 | 7.9s |  |
| 548 | `loader_jpegxr` | 2 | 26.8s |  |
| 549 | `loader_jpegxr_alpha` | 1 | 26.5s |  |
| 550 | `loader_loadbytes_events` | 30 | 8.2s |  |
| 551 | `loader_loadbytes_invalid_png` | 4 | 26.3s |  |
| 552 | `loader_loadbytes_url` | 12 | 7.7s |  |
| 553 | `loader_loaderurl` | 6 | 8.0s |  |
| 554 | `loader_noninteractive_try_click_root` | 5 | 27.2s |  |
| 555 | `loader_reuse` | 38 | 7.7s |  |
| 556 | `loader_unknown_content` | 24 | 7.6s |  |
| 557 | `loader_visibility_interactive` | 1 | 7.6s |  |
| 558 | `loaderinfo_events` | 7 | 7.5s |  |
| 559 | `loaderinfo_loadurl` | 12 | 10.4s |  |
| 560 | `loaderinfo_more` | 6 | 7.7s |  |
| 561 | `loaderinfo_properties` | 18 | 7.3s |  |
| 562 | `loaderinfo_properties_not_loaded` | 23 | 7.4s |  |
| 563 | `loaderinfo_root` | 10 | 7.3s |  |
| 564 | `loaderinfo_root_allows` | 2 | 7.2s |  |
| 565 | `localconnection_send` | 4 | 7.3s |  |
| 566 | `lshift` | 1058 | 19.6s |  |
| 567 | `mask_reapply` | 1 | 7.4s |  |
| 568 | `math` | 497 | 7.6s |  |
| 569 | `matrix3d` | 57 | 8.1s |  |
| 570 | `matrix3d_compose` | 34 | 7.6s |  |
| 571 | `matrix3d_invert` | 18 | 7.4s |  |
| 572 | `missing_external_interface` | 10 | 7.4s |  |
| 573 | `modulo` | 1058 | 19.4s |  |
| 574 | `morph_shape` | 2 | 26.6s |  |
| 575 | `mouse_children` | 192 | 26.9s |  |
| 576 | `mouse_click_events` | 90 | 26.8s |  |
| 577 | `mouse_double_click_events` | 188 | 7.4s |  |
| 578 | `mouse_empty_parent` | 4 | 7.4s |  |
| 579 | `mouse_over_while_dragging` | 3 | 7.3s |  |
| 580 | `mouse_pick_button_mode` | 2 | 7.4s |  |
| 581 | `mouse_pick_dobj_mask` | 4 | 7.7s |  |
| 582 | `mouse_pick_masking` | 7 | 26.7s |  |
| 583 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.6s |  |
| 584 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.7s |  |
| 585 | `mouse_pick_text` | 8 | 7.5s |  |
| 586 | `mouse_sibling` | 8 | 7.4s |  |
| 587 | `mouse_wheel_events` | 36 | 27.7s |  |
| 588 | `mouseevent_constr` | 66 | 7.4s |  |
| 589 | `mouseevent_stagexy` | 35 | 7.4s |  |
| 590 | `mouseevent_valueof_tostring` | 28 | 7.3s |  |
| 591 | `movieclip_addframescript` | 3 | 26.6s |  |
| 592 | `movieclip_child_property` | 16 | 7.5s |  |
| 593 | `movieclip_constr` | 21 | 10.0s |  |
| 594 | `movieclip_currentlabels` | 17 | 25.2s |  |
| 595 | `movieclip_currentlabels_dupes1` | 46 | 25.2s |  |
| 596 | `movieclip_currentlabels_dupes2` | 30 | 7.0s |  |
| 597 | `movieclip_currentlabels_dupes3` | 67 | 7.0s |  |
| 598 | `movieclip_currentscene` | 12 | 7.0s |  |
| 599 | `movieclip_dispatchevent` | 430 | 7.1s |  |
| 600 | `movieclip_dispatchevent_cancel` | 102 | 7.1s |  |
| 601 | `movieclip_dispatchevent_handlerorder` | 251 | 7.0s |  |
| 602 | `movieclip_dispatchevent_selfadd` | 80 | 7.0s |  |
| 603 | `movieclip_dispatchevent_target` | 899 | 7.1s |  |
| 604 | `movieclip_displayevents` | 96 | 25.4s |  |
| 605 | `movieclip_displayevents_clickgoto` | 676 | 7.5s |  |
| 606 | `movieclip_displayevents_clickgoto2` | 2001 | 7.6s |  |
| 607 | `movieclip_displayevents_clickplay` | 575 | 7.2s |  |
| 608 | `movieclip_displayevents_clicksymbol` | 562 | 7.2s |  |
| 609 | `movieclip_displayevents_constructframegoto` | 140 | 7.4s |  |
| 610 | `movieclip_displayevents_constructframeplay` | 50 | 7.2s |  |
| 611 | `movieclip_displayevents_constructframesymbol` | 144 | 7.2s |  |
| 612 | `movieclip_displayevents_dblhandler` | 21 | 7.2s |  |
| 613 | `movieclip_displayevents_enterframegoto` | 149 | 7.3s |  |
| 614 | `movieclip_displayevents_enterframeplay` | 48 | 7.1s |  |
| 615 | `movieclip_displayevents_enterframesymbol` | 149 | 25.5s |  |
| 616 | `movieclip_displayevents_exitframegoto` | 106 | 7.1s |  |
| 617 | `movieclip_displayevents_exitframeplay` | 44 | 7.1s |  |
| 618 | `movieclip_displayevents_exitframesymbol` | 135 | 7.2s |  |
| 619 | `movieclip_displayevents_looping` | 63 | 25.5s |  |
| 620 | `movieclip_displayevents_stopped` | 113 | 7.4s |  |
| 621 | `movieclip_displayevents_swap` | 96 | 2.9s |  |
| 622 | `movieclip_displayevents_timeline` | 128 | 25.5s |  |
| 623 | `movieclip_drawrect` | 54 | 7.0s |  |
| 624 | `movieclip_frameconstruct_skipped` | 9 | 7.0s |  |
| 625 | `movieclip_goto_during_frame_script` | 15 | 7.1s |  |
| 626 | `movieclip_goto_overwrite` | 14 | 25.3s |  |
| 627 | `movieclip_goto_scene_last_frame_int` | 1 | 25.2s |  |
| 628 | `movieclip_goto_scene_last_frame_label` | 1 | 6.9s |  |
| 629 | `movieclip_gotoandplay` | 15 | 25.1s |  |
| 630 | `movieclip_gotoandstop` | 13 | 25.0s |  |
| 631 | `movieclip_gotoandstop_children` | 4 | 7.0s |  |
| 632 | `movieclip_gotoandstop_framescripts1` | 4 | 7.0s |  |
| 633 | `movieclip_gotoandstop_framescripts2` | 4 | 3.0s |  |
| 634 | `movieclip_gotoandstop_framescripts_self` | 7 | 30.8s |  |
| 635 | `movieclip_gotoandstop_queueing` | 12 | 28.1s |  |
| 636 | `movieclip_hittest` | 67 | 7.9s |  |
| 637 | `movieclip_next_frame` | 2 | 7.8s |  |
| 638 | `movieclip_next_scene` | 6 | 27.6s |  |
| 639 | `movieclip_play` | 3 | 7.7s |  |
| 640 | `movieclip_prev_frame` | 3 | 7.5s |  |
| 641 | `movieclip_prev_scene` | 7 | 7.8s |  |
| 642 | `movieclip_properties` | 79 | 8.1s |  |
| 643 | `movieclip_queued_noop_goto_swf10` | 9 | 7.8s |  |
| 644 | `movieclip_queued_noop_goto_swf9` | 7 | 1.5s |  |
| 645 | `movieclip_scenes` | 11 | 7.6s |  |
| 646 | `movieclip_soundtransform` | 831 | 29.8s |  |
| 647 | `movieclip_stop` | 1 | 7.6s |  |
| 648 | `movieclip_super_is_symbol` | 20 | 8.1s |  |
| 649 | `movieclip_symbol_constr` | 8 | 7.8s |  |
| 650 | `movieclip_text_mousedown` | 1 | 7.7s |  |
| 651 | `movieclip_willtrigger` | 5 | 7.8s |  |
| 652 | `multiply` | 1058 | 19.6s |  |
| 653 | `namespace_constr` | 253 | 8.0s |  |
| 654 | `namespace_constr_args` | 1 | 7.5s |  |
| 655 | `namespace_enumeration_order` | 7 | 7.6s |  |
| 656 | `nan_scale` | 9 | 7.6s |  |
| 657 | `navigateToURL_target_normalize` | 107 | 29.1s |  |
| 658 | `negate` | 30 | 7.7s |  |
| 659 | `negative_volume_panned` | 0 | 7.9s |  |
| 660 | `nested_iteration` | 11 | 7.7s |  |
| 661 | `net_getClassByAlias` | 3 | 7.6s |  |
| 662 | `net_navigateToURL` | 57 | 7.7s |  |
| 663 | `net_stream_play_options` | 6 | 7.7s |  |
| 664 | `netconnection_close` | 55 | 7.7s |  |
| 665 | `netconnection_properties` | 78 | 7.8s |  |
| 666 | `netconnection_send_remote` | 50 | 8.0s |  |
| 667 | `netconnection_serialize_arrays` | 6 | 7.7s |  |
| 668 | `netstream_client` | 10 | 7.8s |  |
| 669 | `netstream_connect` | 7 | 7.6s |  |
| 670 | `newactivation_in_script_init` | 3 | 7.3s |  |
| 671 | `newclass_twice` | 3 | 7.4s |  |
| 672 | `nonconflicting_declarations` | 0 | 7.4s |  |
| 673 | `null_void_types` | 8 | 7.5s |  |
| 674 | `number_autoconv` | 21 | 7.5s |  |
| 675 | `number_autoconv_amf` | 132 | 7.5s |  |
| 676 | `number_autoconv_array_sort_32bit` | 1 | 7.4s |  |
| 677 | `number_constr` | 58 | 7.5s |  |
| 678 | `number_toexponential` | 378 | 7.5s |  |
| 679 | `number_toexponential2` | 35 | 7.4s |  |
| 680 | `number_tofixed` | 378 | 7.5s |  |
| 681 | `number_toprecision` | 350 | 7.5s |  |
| 682 | `obfuscated_class_names` | 3 | 7.4s |  |
| 683 | `object_enumeration` | 10 | 7.4s |  |
| 684 | `object_prototype` | 4 | 7.5s |  |
| 685 | `object_to_locale_string` | 2 | 7.4s |  |
| 686 | `object_to_string` | 2 | 7.4s |  |
| 687 | `object_value_of` | 2 | 3.2s |  |
| 688 | `op_coerce` | 54 | 7.5s |  |
| 689 | `op_coerce_x` | 54 | 7.5s |  |
| 690 | `op_escxattr` | 2 | 7.4s |  |
| 691 | `op_escxelem` | 2 | 7.4s |  |
| 692 | `op_lookupswitch` | 4 | 7.5s |  |
| 693 | `optimize_coerce` | 1 | 7.4s |  |
| 694 | `orphan_movie_complex` | 80 | 7.9s |  |
| 695 | `orphan_movie_reorder` | 111 | 27.5s |  |
| 696 | `package_namespace` | 7 | 7.5s |  |
| 697 | `param_default_value_has_zero_cpool_index` | 1 | 7.6s |  |
| 698 | `parent_early_access_child` | 16 | 7.9s |  |
| 699 | `parse_float` | 81 | 7.8s |  |
| 700 | `parse_int` | 135 | 8.1s |  |
| 701 | `perspective_projection_basic` | 40 | 7.5s |  |
| 702 | `pixelbender_ceil` | 77 | 7.7s |  |
| 703 | `pixelbender_conditional` | 138 | 11.3s |  |
| 704 | `pixelbender_conversions` | 270 | 8.1s |  |
| 705 | `pixelbender_dithering` | 8 | 34.6s |  |
| 706 | `pixelbender_div` | 36 | 7.9s |  |
| 707 | `pixelbender_effect_BlurredFocus` | 0 | 35.2s |  |
| 708 | `pixelbender_effect_glassDisplace` | 0 | 13.9s |  |
| 709 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 33.0s |  |
| 710 | `pixelbender_effect_smudge` | 0 | 11.1s |  |
| 711 | `pixelbender_effect_tintype` | 0 | 10.2s |  |
| 712 | `pixelbender_effect_twirl` | 0 | 11.4s |  |
| 713 | `pixelbender_eof` | 7 | 7.5s |  |
| 714 | `pixelbender_images` | 0 | 9.9s |  |
| 715 | `pixelbender_input` | 103 | 27.7s |  |
| 716 | `pixelbender_logicalnot` | 20 | 7.5s |  |
| 717 | `pixelbender_malformed_data` | 190 | 27.8s |  |
| 718 | `pixelbender_multiple_out_params` | 1 | 7.5s |  |
| 719 | `pixelbender_no_out_param` | 6 | 7.5s |  |
| 720 | `pixelbender_outputs` | 13 | 7.7s |  |
| 721 | `pixelbender_padding_bytes` | 22 | 7.6s |  |
| 722 | `pixelbender_param_qualifier` | 512 | 7.6s |  |
| 723 | `pixelbender_parameters` | 1563 | 7.8s |  |
| 724 | `pixelbender_parameters_bool` | 240 | 7.7s |  |
| 725 | `pixelbender_parameters_int_vs_bool` | 54 | 7.6s |  |
| 726 | `pixelbender_parse_errors` | 6 | 7.4s |  |
| 727 | `pixelbender_rsqrt` | 24 | 7.6s |  |
| 728 | `pixelbender_select_kinds` | 8 | 7.6s |  |
| 729 | `pixelbender_shaderdata` | 49 | 7.6s |  |
| 730 | `pixelbender_shaderdata_setter` | 99 | 7.8s |  |
| 731 | `pixelbender_sign` | 60 | 7.6s |  |
| 732 | `pixelbender_vector_output` | 11 | 7.7s |  |
| 733 | `place_and_lookup/swf10` | 33 | 7.5s |  |
| 734 | `place_and_lookup/swf9` | 33 | 1.4s |  |
| 735 | `place_multiple` | 17 | 26.3s |  |
| 736 | `place_object_replace` | 9 | 7.6s |  |
| 737 | `place_object_replace_2` | 24 | 7.5s |  |
| 738 | `place_object_same_depth_frame` | 1 | 7.5s |  |
| 739 | `point` | 132 | 8.0s |  |
| 740 | `primitive_edge_cases` | 1 | 7.3s |  |
| 741 | `print_job_options` | 3 | 7.4s |  |
| 742 | `property_is_enumerable_reset` | 23 | 7.2s |  |
| 743 | `property_priority` | 22 | 7.6s |  |
| 744 | `property_priority_definition_names_order` | 2 | 7.4s |  |
| 745 | `property_priority_three_level` | 6 | 26.3s |  |
| 746 | `propertyisenumerable_namespaces` | 6 | 7.2s |  |
| 747 | `prototype_set_null` | 7 | 7.3s |  |
| 748 | `proxy_callproperty` | 24 | 7.2s |  |
| 749 | `proxy_deleteproperty` | 64 | 7.4s |  |
| 750 | `proxy_enumeration` | 34 | 7.3s |  |
| 751 | `proxy_getproperty` | 77 | 7.4s |  |
| 752 | `proxy_hasownproperty` | 8 | 7.4s |  |
| 753 | `proxy_hasproperty` | 32 | 7.4s |  |
| 754 | `proxy_serialize` | 9 | 7.3s |  |
| 755 | `proxy_setproperty` | 42 | 7.4s |  |
| 756 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.4s |  |
| 757 | `qname_constr` | 32 | 7.5s |  |
| 758 | `qname_constr_namespace` | 24 | 7.4s |  |
| 759 | `qname_enumeration` | 9 | 7.5s |  |
| 760 | `qname_indexing` | 23 | 7.5s |  |
| 761 | `qname_tostring` | 25 | 7.5s |  |
| 762 | `qname_valueof` | 29 | 7.4s |  |
| 763 | `rectangle` | 1094 | 8.1s |  |
| 764 | `regexp_constr` | 148 | 7.8s |  |
| 765 | `regexp_exec` | 19 | 7.5s |  |
| 766 | `regexp_extended` | 47 | 7.3s |  |
| 767 | `regexp_multiargs` | 1 | 7.3s |  |
| 768 | `regexp_test` | 27 | 7.3s |  |
| 769 | `regexp_toString` | 10 | 7.4s |  |
| 770 | `register_script_refresh` | 35 | 7.7s |  |
| 771 | `remove_child_clear_field` | 88 | 7.7s |  |
| 772 | `remove_dobj` | 3 | 7.2s |  |
| 773 | `resolve_order` | 4 | 7.3s |  |
| 774 | `responder_null_callbacks` | 1 | 7.3s |  |
| 775 | `rng` | 1 | 8.5s |  |
| 776 | `rootless` | 42 | 7.5s |  |
| 777 | `rshift` | 1058 | 19.9s |  |
| 778 | `sandbox_type_inherited` | 2 | 7.9s |  |
| 779 | `sandbox_type_local_file` | 1 | 11.0s |  |
| 780 | `sandbox_type_local_network` | 1 | 7.6s |  |
| 781 | `scene_constr` | 8 | 7.8s |  |
| 782 | `security_domain_current` | 2 | 7.8s |  |
| 783 | `selection` | 239 | 8.2s |  |
| 784 | `set_local_0` | 31 | 7.9s |  |
| 785 | `set_property_is_enumerable` | 85 | 8.2s |  |
| 786 | `shaderparameter_value` | 4 | 7.7s |  |
| 787 | `shape_drawrect` | 54 | 7.8s |  |
| 788 | `shared_object_no_root` | 3 | 7.8s |  |
| 789 | `simplebutton_added_to_stage` | 45 | 28.3s |  |
| 790 | `simplebutton_childevents` | 86 | 28.6s |  |
| 791 | `simplebutton_childevents_nested` | 54 | 8.0s |  |
| 792 | `simplebutton_childevents_sprite` | 13 | 7.7s |  |
| 793 | `simplebutton_childprops` | 144 | 7.9s |  |
| 794 | `simplebutton_childshuffle` | 23 | 7.5s |  |
| 795 | `simplebutton_constr` | 36 | 7.9s |  |
| 796 | `simplebutton_constr_childevents` | 48 | 7.9s |  |
| 797 | `simplebutton_constr_params` | 42 | 7.7s |  |
| 798 | `simplebutton_mouseenabled` | 26 | 7.6s |  |
| 799 | `simplebutton_multi_children` | 19 | 7.8s |  |
| 800 | `simplebutton_structure` | 27 | 8.0s |  |
| 801 | `simplebutton_symbolclass` | 68 | 8.0s |  |
| 802 | `slot_disp_id_shared_numbering` | 1 | 26.8s |  |
| 803 | `slots_force_autoassigned` | 1 | 7.6s |  |
| 804 | `socket_after_disconnect` | 1 | 7.6s |  |
| 805 | `socket_close` | 2 | 7.5s |  |
| 806 | `socket_connect` | 4 | 7.6s |  |
| 807 | `socket_errors` | 56 | 8.1s |  |
| 808 | `socket_read_big` | 48 | 7.9s |  |
| 809 | `socket_read_little` | 48 | 10.5s |  |
| 810 | `socket_read_write_object` | 8 | 7.2s |  |
| 811 | `socket_write_big` | 15 | 7.5s |  |
| 812 | `socket_write_little` | 14 | 7.2s |  |
| 813 | `sound_embeddedprops` | 26 | 7.4s |  |
| 814 | `sound_play` | 19 | 7.5s |  |
| 815 | `sound_valueof` | 33 | 7.3s |  |
| 816 | `soundchannel_soundtransform` | 835 | 27.8s |  |
| 817 | `soundchannel_soundtransform_exists` | 5 | 25.8s |  |
| 818 | `soundchannel_stop` | 8 | 7.3s |  |
| 819 | `soundmixer_buffertime` | 5 | 7.1s |  |
| 820 | `soundmixer_stopall` | 6 | 7.2s |  |
| 821 | `soundtransform` | 442 | 12.9s |  |
| 822 | `space_justifier_clone` | 12 | 7.2s |  |
| 823 | `sprite_with_frames` | 0 | 26.5s |  |
| 824 | `stage3d_agal_cross_product` | 0 | 10.1s |  |
| 825 | `stage3d_agal_upload_errors` | 66 | 9.9s |  |
| 826 | `stage3d_bitmap` | 0 | 31.2s |  |
| 827 | `stage3d_blend` | 81 | 30.5s |  |
| 828 | `stage3d_context3d_string_args` | 158 | 8.2s |  |
| 829 | `stage3d_errors` | 7 | 7.3s |  |
| 830 | `stage3d_errors_atf` | 3 | 8.6s |  |
| 831 | `stage3d_errors_swf_29` | 6 | 7.3s |  |
| 832 | `stage3d_float1_index` | 0 | 28.8s |  |
| 833 | `stage3d_fractal` | 0 | 29.1s |  |
| 834 | `stage3d_ignore_sampler_override` | 0 | 28.9s |  |
| 835 | `stage3d_multistage_triangle` | 3 | 10.1s |  |
| 836 | `stage3d_program_constants_bytearray_be` | 0 | 29.9s |  |
| 837 | `stage3d_program_constants_bytearray_le` | 0 | 10.6s |  |
| 838 | `stage3d_program_constants_invalid_input` | 21 | 8.1s |  |
| 839 | `stage3d_raytrace` | 0 | 33.5s |  |
| 840 | `stage3d_rotating_cube` | 0 | 10.8s |  |
| 841 | `stage3d_sampler` | 0 | 9.9s |  |
| 842 | `stage3d_sampler_partial_upload` | 0 | 10.9s |  |
| 843 | `stage3d_stencil` | 0 | 24.7s |  |
| 844 | `stage3d_texture` | 0 | 12.6s |  |
| 845 | `stage3d_texture_bytearray` | 0 | 9.5s |  |
| 846 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 8.8s |  |
| 847 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 9.7s |  |
| 848 | `stage3d_triangle` | 0 | 8.2s |  |
| 849 | `stage3d_triangle_bytes4` | 0 | 8.3s |  |
| 850 | `stage3d_triangle_float1` | 0 | 8.2s |  |
| 851 | `stage3d_triangle_index_upload` | 0 | 8.2s |  |
| 852 | `stage3d_x_y` | 22 | 6.1s |  |
| 853 | `stage_access` | 10 | 6.2s |  |
| 854 | `stage_displayobject_properties` | 24 | 5.7s |  |
| 855 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.0s |  |
| 856 | `stage_framerate_nan` | 7 | 6.1s |  |
| 857 | `stage_framerate_negative` | 6 | 5.8s |  |
| 858 | `stage_framerate_zero` | 6 | 5.9s |  |
| 859 | `stage_invalidate` | 38 | 6.1s |  |
| 860 | `stage_loaderinfo_properties` | 24 | 6.1s |  |
| 861 | `stage_mousechildren` | 2 | 6.1s |  |
| 862 | `stage_mouseenabled` | 15 | 5.7s |  |
| 863 | `stage_overriden_setters` | 31 | 6.1s |  |
| 864 | `stage_properties` | 30 | 6.2s |  |
| 865 | `stage_stage3Ds_vector` | 1 | 22.0s |  |
| 866 | `static_text` | 3 | 6.1s |  |
| 867 | `static_var_with_this_in_ctor` | 2 | 5.8s |  |
| 868 | `stored_properties` | 11 | 5.9s |  |
| 869 | `strict_equality` | 34 | 6.0s |  |
| 870 | `string_call` | 13 | 6.2s |  |
| 871 | `string_case` | 23 | 6.1s |  |
| 872 | `string_char_at` | 27 | 6.3s |  |
| 873 | `string_char_code_at` | 28 | 6.0s |  |
| 874 | `string_concat_fromcharcode` | 37 | 5.9s |  |
| 875 | `string_constr` | 25 | 6.1s |  |
| 876 | `string_indexof_lastindexof` | 87 | 6.1s |  |
| 877 | `string_length` | 16 | 10.3s |  |
| 878 | `string_locale_compare` | 39 | 7.5s |  |
| 879 | `string_match` | 51 | 7.5s |  |
| 880 | `string_relational_compare` | 4 | 7.2s |  |
| 881 | `string_replace` | 51 | 7.4s |  |
| 882 | `string_search` | 41 | 7.4s |  |
| 883 | `string_slice_substr_substring` | 170 | 8.5s |  |
| 884 | `string_split` | 29 | 7.3s |  |
| 885 | `string_substr_negative` | 21 | 7.1s |  |
| 886 | `string_substr_weird` | 182 | 7.2s |  |
| 887 | `subtract` | 1058 | 19.4s |  |
| 888 | `super_get_call` | 12 | 7.3s |  |
| 889 | `supercall_two_classobjects` | 2 | 7.2s |  |
| 890 | `swf8` | 1 | 7.2s |  |
| 891 | `swf_10_queued_goto_scripts_construct` | 52 | 7.5s |  |
| 892 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 893 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 894 | `swf_9_queued_goto_scripts` | 6 | 7.3s |  |
| 895 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 896 | `swf_9_versioning` | 2 | 7.2s |  |
| 897 | `swf_wrong_frame_count` | 38 | 7.5s |  |
| 898 | `swf_wrong_frame_count_isplaying` | 22 | 26.1s |  |
| 899 | `symbol_class_binary_data` | 8 | 7.2s |  |
| 900 | `symbol_class_conflict` | 4 | 7.7s |  |
| 901 | `symbol_class_root_not_zero` | 1 | 7.1s |  |
| 902 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 903 | `tab_ordering_arrows` | 998 | 27.6s |  |
| 904 | `tab_ordering_automatic_advanced` | 184 | 31.4s |  |
| 905 | `tab_ordering_automatic_basic` | 45 | 7.6s |  |
| 906 | `tab_ordering_children` | 116 | 7.7s |  |
| 907 | `tab_ordering_custom_basic` | 34 | 7.6s |  |
| 908 | `tab_ordering_stage_tab_children` | 32 | 7.6s |  |
| 909 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.6s |  |
| 910 | `tab_ordering_tabbable` | 47 | 7.7s |  |
| 911 | `tabstop_properties` | 105 | 7.8s |  |
| 912 | `text_element_basic` | 34 | 7.7s |  |
| 913 | `text_engine_fontdescription` | 27 | 7.5s |  |
| 914 | `text_engine_groupelement` | 64 | 8.6s |  |
| 915 | `text_run` | 7 | 7.3s |  |
| 916 | `textblock_createline_errors` | 23 | 7.7s |  |
| 917 | `textblock_createline_fte` | 9 | 27.6s |  |
| 918 | `textblock_properties` | 118 | 7.9s |  |
| 919 | `textbox_click` | 37 | 27.9s |  |
| 920 | `textfield_event` | 66 | 7.8s |  |
| 921 | `textfield_focusin_event` | 9 | 7.5s |  |
| 922 | `textfield_input_dead_keys_windows` | 15 | 7.5s |  |
| 923 | `textfield_unload` | 39 | 27.3s |  |
| 924 | `textformat` | 1134 | 7.5s |  |
| 925 | `textformat_display` | 14 | 7.5s |  |
| 926 | `textformat_font_max_length` | 4 | 7.4s |  |
| 927 | `textline_inapplicable_properties` | 10 | 7.4s |  |
| 928 | `textline_name` | 1 | 7.5s |  |
| 929 | `textline_splitting_basic` | 76 | 7.7s |  |
| 930 | `textline_throwerror` | 30 | 7.6s |  |
| 931 | `textline_validity` | 162 | 7.7s |  |
| 932 | `throw` | 3 | 7.4s |  |
| 933 | `timeline_scripts` | 3 | 7.5s |  |
| 934 | `timer` | 90 | 8.6s |  |
| 935 | `timer_events` | 3 | 7.6s |  |
| 936 | `timer_finished` | 11 | 7.8s |  |
| 937 | `timer_reset` | 8 | 7.7s |  |
| 938 | `timer_setdelay` | 5 | 7.7s |  |
| 939 | `trace` | 12 | 7.4s |  |
| 940 | `truthiness` | 30 | 6.5s |  |
| 941 | `try_catch` | 11 | 9.1s |  |
| 942 | `try_catch_typed` | 12 | 5.5s |  |
| 943 | `typeof` | 30 | 5.4s |  |
| 944 | `uint_constr` | 92 | 5.3s |  |
| 945 | `uint_tofixed` | 1215 | 5.4s |  |
| 946 | `uint_tostring` | 3375 | 5.5s |  |
| 947 | `unchecked_function` | 15 | 5.4s |  |
| 948 | `unescape` | 28 | 5.4s |  |
| 949 | `url_loader` | 25 | 5.4s |  |
| 950 | `urlrequest` | 18 | 5.4s |  |
| 951 | `urlstream_basic` | 5 | 5.4s |  |
| 952 | `urshift` | 1058 | 5.4s |  |
| 953 | `utils3d` | 7 | 5.4s |  |
| 954 | `vector3d` | 397 | 5.4s |  |
| 955 | `vector_class` | 36 | 5.4s |  |
| 956 | `vector_class_call` | 11 | 5.4s |  |
| 957 | `vector_coercion` | 66 | 5.4s |  |
| 958 | `vector_concat` | 90 | 5.4s |  |
| 959 | `vector_constr` | 107 | 5.3s |  |
| 960 | `vector_enumeration` | 5 | 5.4s |  |
| 961 | `vector_every` | 92 | 5.4s |  |
| 962 | `vector_filter` | 95 | 5.4s |  |
| 963 | `vector_holes` | 24 | 5.4s |  |
| 964 | `vector_indexof` | 302 | 5.4s |  |
| 965 | `vector_insertat` | 270 | 5.4s |  |
| 966 | `vector_int_access` | 4 | 5.4s |  |
| 967 | `vector_int_delete` | 11 | 5.4s |  |
| 968 | `vector_join` | 58 | 5.4s |  |
| 969 | `vector_lastindexof` | 302 | 5.5s |  |
| 970 | `vector_legacy` | 10 | 5.5s |  |
| 971 | `vector_map` | 85 | 5.4s |  |
| 972 | `vector_object_final` | 1 | 5.4s |  |
| 973 | `vector_object_toString` | 10 | 5.4s |  |
| 974 | `vector_pushpop` | 255 | 5.4s |  |
| 975 | `vector_reborrow_bug` | 10 | 5.3s |  |
| 976 | `vector_removeat` | 172 | 11.6s |  |
| 977 | `vector_reverse` | 232 | 8.3s |  |
| 978 | `vector_shiftunshift` | 252 | 7.1s |  |
| 979 | `vector_slice` | 331 | 8.9s |  |
| 980 | `vector_sort` | 905 | 17.0s |  |
| 981 | `vector_splice` | 693 | 11.4s |  |
| 982 | `vector_splice_fixed_bug_compat` | 4 | 7.3s |  |
| 983 | `vector_tostring` | 79 | 7.9s |  |
| 984 | `verification` | 8 | 7.4s |  |
| 985 | `verify_abnormal_loop` | 1 | 7.0s |  |
| 986 | `verify_dxns_without_flag` | 3 | 7.5s |  |
| 987 | `verify_exception_targets_edge_case` | 1 | 7.2s |  |
| 988 | `verify_jump_to_middle_of_op` | 1 | 7.1s |  |
| 989 | `verify_lookup_switch_edge_case` | 1 | 7.0s |  |
| 990 | `verify_stack` | 5 | 7.2s |  |
| 991 | `verify_unreachable_exception` | 2 | 7.1s |  |
| 992 | `versioned_isplaying` | 2 | 7.1s |  |
| 993 | `virtual_properties` | 16 | 7.2s |  |
| 994 | `with` | 4 | 7.2s |  |
| 995 | `wrong_arg_count` | 7 | 7.4s |  |
| 996 | `xml_abstract_equality` | 36 | 7.5s |  |
| 997 | `xml_advanced` | 52 | 7.3s |  |
| 998 | `xml_appendchild` | 10 | 7.2s |  |
| 999 | `xml_as_attribute` | 9 | 7.0s |  |
| 1000 | `xml_attribute` | 35 | 7.3s |  |
| 1001 | `xml_attribute_name` | 40 | 7.2s |  |
| 1002 | `xml_basic` | 33 | 7.3s |  |
| 1003 | `xml_child` | 25 | 7.6s |  |
| 1004 | `xml_childindex` | 7 | 7.3s |  |
| 1005 | `xml_children` | 43 | 7.9s |  |
| 1006 | `xml_class_call` | 9 | 7.1s |  |
| 1007 | `xml_contains` | 197 | 7.3s |  |
| 1008 | `xml_copy` | 20 | 3.1s |  |
| 1009 | `xml_ctor_from_tostring` | 23 | 10.3s |  |
| 1010 | `xml_delete` | 114 | 7.1s |  |
| 1011 | `xml_descendants` | 83 | 7.0s |  |
| 1012 | `xml_elements` | 6 | 7.0s |  |
| 1013 | `xml_equals_namespace_check` | 2 | 7.0s |  |
| 1014 | `xml_explicit_use_namespace` | 5 | 7.1s |  |
| 1015 | `xml_getdescendants_qname` | 21 | 7.0s |  |
| 1016 | `xml_has_property_via_in` | 26 | 7.1s |  |
| 1017 | `xml_hasownproperty` | 6 | 7.0s |  |
| 1018 | `xml_ignore_white` | 6 | 7.1s |  |
| 1019 | `xml_length` | 2 | 7.1s |  |
| 1020 | `xml_list_as_attribute` | 9 | 7.0s |  |
| 1021 | `xml_list_concat` | 20 | 7.1s |  |
| 1022 | `xml_list_enumerate` | 4 | 7.0s |  |
| 1023 | `xml_methods_settings` | 3 | 7.1s |  |
| 1024 | `xml_mismatched_tag` | 37 | 7.2s |  |
| 1025 | `xml_namespace` | 39 | 7.2s |  |
| 1026 | `xml_namespace_methods` | 245 | 7.1s |  |
| 1027 | `xml_namespaced_property` | 7 | 7.1s |  |
| 1028 | `xml_no_namespace` | 1 | 7.0s |  |
| 1029 | `xml_nodekind` | 3 | 7.4s |  |
| 1030 | `xml_normalize` | 35 | 7.5s |  |
| 1031 | `xml_notification_bubbling` | 361 | 7.4s |  |
| 1032 | `xml_parent` | 8 | 7.3s |  |
| 1033 | `xml_set_children` | 17 | 7.4s |  |
| 1034 | `xml_set_name` | 34 | 7.4s |  |
| 1035 | `xml_settings` | 6 | 3.2s |  |
| 1036 | `xml_simple_complex_content` | 47 | 7.4s |  |
| 1037 | `xml_socket` | 11 | 7.7s |  |
| 1038 | `xml_text` | 7 | 7.2s |  |
| 1039 | `xml_tostring` | 6 | 7.0s |  |
| 1040 | `xml_tostring_namespace` | 12 | 7.0s |  |
| 1041 | `xml_unescaping` | 23 | 7.1s |  |
| 1042 | `xml_weird_ignores` | 54 | 7.2s |  |
| 1043 | `xml_wildcard` | 11 | 7.0s |  |
| 1044 | `xmldocument` | 254 | 7.1s |  |
| 1045 | `xmlnode` | 3540 | 7.2s |  |
| 1046 | `zero_frame_clip` | 3 | 7.4s |  |

## Ruffle-Matched Tests

**26 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 1 | 3 | 6.6s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 7.2s |  |
| 3 | `blend_transform` | 1 | 1 | 7.8s |  |
| 4 | `coerce_property` | 3 | 3 | 5.8s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 5.7s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 7.6s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.6s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 29.6s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 7.5s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.3s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 7.3s |  |
| 12 | `freestanding_superclass` | 3 | 4 | 7.2s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 26.6s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 26.9s |  |
| 15 | `int_toexponential` | 76 | 76 | 7.4s |  |
| 16 | `int_toprecision` | 441 | 441 | 7.2s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.9s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 7.5s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 26.7s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.8s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 7.4s |  |
| 22 | `sprite_dropTarget` | 4 | 15 | 7.3s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.2s |  |
| 24 | `uint_toexponential` | 100 | 100 | 5.3s |  |
| 25 | `uint_toprecision` | 433 | 433 | 5.5s |  |
| 26 | `weird_superinterface_properties` | 1 | 1 | 26.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**47 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet` | 99.5% | 220 | 221 | 1 |  |
| 2 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 4 | `loader_method` | 97.6% | 83 | 85 | 2 |  |
| 5 | `parse_float_swf10` | 97.5% | 79 | 81 | 2 |  |
| 6 | `loader_load` | 96.9% | 124 | 128 | 4 |  |
| 7 | `core_exceptions` | 95.7% | 45 | 47 | 2 |  |
| 8 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 9 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 10 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 11 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 12 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 13 | `invalid_utf8` | 91.7% | 11 | 12 | 1 |  |
| 14 | `flash_media_video_setter` | 90.0% | 36 | 40 | 4 |  |
| 15 | `issue_8630_placeremoveplace` | 86.7% | 13 | 15 | 2 |  |
| 16 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 17 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 18 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 19 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 20 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 21 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13 | 16 | 3 |  |
| 22 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 23 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 24 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 25 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 26 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 27 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 28 | `instantiate_root_character` | 75.0% | 3 | 4 | 1 |  |
| 29 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 30 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 31 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 32 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 33 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 34 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 35 | `bitmapdata_zero_size` | 62.5% | 5 | 8 | 3 |  |
| 36 | `getouterscope_two_classobjects` | 61.5% | 8 | 13 | 5 |  |
| 37 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 38 | `displayobject_scrollrect` | 57.6% | 19 | 33 | 14 |  |
| 39 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 40 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 41 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 42 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 43 | `activation_class` | 50.0% | 3 | 6 | 3 |  |
| 44 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 45 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 46 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 47 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `method_without_body` | exit code 1 | 26.5s |  |
| 2 | `rtqname_not_namespace` | exit code 1 | 7.2s |  |
| 3 | `verify_typecheck` | exit code 1 | 7.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**147 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet` | 99.5% | 220/221 | 221 | 221 |  |
| 2 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 3 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 4 | `loader_method` | 97.6% | 83/85 | 83 | 85 |  |
| 5 | `parse_float_swf10` | 97.5% | 79/81 | 81 | 81 |  |
| 6 | `loader_load` | 96.9% | 124/128 | 126 | 128 |  |
| 7 | `core_exceptions` | 95.7% | 45/47 | 47 | 47 |  |
| 8 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 9 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 10 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 11 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 12 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 13 | `invalid_utf8` | 91.7% | 11/12 | 12 | 12 |  |
| 14 | `flash_media_video_setter` | 90.0% | 36/40 | 40 | 40 |  |
| 15 | `issue_8630_placeremoveplace` | 86.7% | 13/15 | 15 | 15 |  |
| 16 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 17 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 18 | `matrix` | 83.4% | 282/338 | 283 | 338 |  |
| 19 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 20 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 21 | `issue_8630_placeremoveplace_scriptremove` | 81.2% | 13/16 | 16 | 16 |  |
| 22 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 23 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 24 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 25 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 26 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 27 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 28 | `instantiate_root_character` | 75.0% | 3/4 | 4 | 4 |  |
| 29 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 30 | `superinterface_call` | 75.0% | 15/20 | 15 | 20 |  |
| 31 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 32 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 33 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 34 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 35 | `bitmapdata_zero_size` | 62.5% | 5/8 | 5 | 8 |  |
| 36 | `getouterscope_two_classobjects` | 61.5% | 8/13 | 9 | 13 |  |
| 37 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 38 | `displayobject_scrollrect` | 57.6% | 19/33 | 33 | 33 |  |
| 39 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 40 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 41 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 42 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 43 | `activation_class` | 50.0% | 3/6 | 5 | 6 |  |
| 44 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 45 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 46 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 47 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 48 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 49 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 50 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 51 | `large_preload_from_bytes` | 35.3% | 18/51 | 23 | 51 |  |
| 52 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 53 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 54 | `geom_transform` | 27.0% | 20/74 | 23 | 74 |  |
| 55 | `property_priority_chained` | 25.0% | 1/4 | 4 | 4 |  |
| 56 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 57 | `property_is_enumerable` | 21.9% | 25/114 | 25 | 114 |  |
| 58 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 8 | 32 |  |
| 59 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 60 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 61 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 62 | `sound_load_multiple` | 15.8% | 3/19 | 5 | 19 |  |
| 63 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 64 | `displayobject_getrect` | 12.5% | 2/16 | 2 | 16 |  |
| 65 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 66 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 67 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 68 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 69 | `url_vars` | 11.1% | 3/27 | 3 | 27 |  |
| 70 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 71 | `event_handler_exception` | 9.1% | 1/11 | 4 | 11 |  |
| 72 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 73 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 74 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 75 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 76 | `loader_duplicate_class` | 6.2% | 3/48 | 44 | 48 |  |
| 77 | `font_registerfont` | 6.2% | 8/129 | 14 | 129 |  |
| 78 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 79 | `uncaught_errors_stringified` | 5.6% | 1/18 | 3 | 18 |  |
| 80 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 81 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 82 | `external_interface` | 2.9% | 3/105 | 5 | 105 |  |
| 83 | `escape_multi_byte` | 2.2% | 1/45 | 1 | 45 |  |
| 84 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 85 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 86 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 87 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 88 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 89 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 90 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 91 | `describe_type_json` | 0.3% | 1/301 | 1 | 301 |  |
| 92 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 93 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 94 | `all_classes/events/swf9` | 0.1% | 1/1030 | 184 | 1030 |  |
| 95 | `all_classes/events/swf30` | 0.1% | 2/2353 | 184 | 2353 |  |
| 96 | `all_classes/events/swf10` | 0.1% | 1/1638 | 184 | 1638 |  |
| 97 | `all_classes/events/swf11` | 0.1% | 1/1750 | 184 | 1750 |  |
| 98 | `all_classes/events/swf12` | 0.1% | 1/1814 | 184 | 1814 |  |
| 99 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 100 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 101 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 102 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 103 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 104 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 105 | `accessibilityimplementation` | 0.0% | 0/18 | 2 | 18 |  |
| 106 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 107 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 108 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 109 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 110 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 111 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 112 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 113 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 114 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 115 | `audio_computespectrum` | 0.0% | 0/118 | 0 | 118 |  |
| 116 | `avm1_root` | 0.0% | 0/58 | 3 | 58 |  |
| 117 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 118 | `currency_parse_result` | 0.0% | 0/7 | 0 | 7 |  |
| 119 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 120 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 121 | `encode_uri_surrogate_pair_invalid` | 0.0% | 0/8 | 8 | 8 |  |
| 122 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 123 | `font_enumeratefonts_order` | 0.0% | 0/9 | 0 | 9 |  |
| 124 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 125 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 126 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 127 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 128 | `native_menu_basic` | 0.0% | 0/19 | 0 | 19 |  |
| 129 | `netfilterevent` | 0.0% | 0/10 | 0 | 10 |  |
| 130 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 131 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 132 | `newclass_mismatched` | 0.0% | 0/4 | 2 | 4 |  |
| 133 | `scopes_dont_cache/order-1` | 0.0% | 0/1 | 0 | 1 |  |
| 134 | `scopes_dont_cache/order-2` | 0.0% | 0/1 | 0 | 1 |  |
| 135 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 136 | `stage_display_state` | 0.0% | 0/6 | 0 | 6 |  |
| 137 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 138 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 139 | `supercalls_weird` | 0.0% | 0/2 | 0 | 2 |  |
| 140 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 141 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 142 | `system_setclipboard_null` | 0.0% | 0/1 | 1 | 1 |  |
| 143 | `uncaught_error_basic` | 0.0% | 0/2 | 0 | 2 |  |
| 144 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 145 | `verify_illegal_opcode` | 0.0% | 0/1 | 0 | 1 |  |
| 146 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 147 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
