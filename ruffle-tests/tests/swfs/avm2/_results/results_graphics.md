# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-01 02:48 UTC

**Git SHA**: `73c786e3fa`

**Run Duration**: 217m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1224 |
| Passing | **1068** (87.3%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1095** (89.5%) |
| Failing | 129 |
| Total expected lines | 151515 |
| Matching lines | 118135 (78.0%) |
| Mismatched lines | 33380 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 128 | 99.2% |
| Runtime Error | 1 | 0.8% |

## Passing Tests

**1068 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 26.7s |  |
| 2 | `accessibility` | 1 | 7.4s |  |
| 3 | `activation_class` | 6 | 7.4s |  |
| 4 | `add` | 1058 | 19.7s |  |
| 5 | `agal_compiler` | 13 | 9.8s |  |
| 6 | `air_datagram_socket` | 1 | 8.8s |  |
| 7 | `air_hidden_lookup` | 2 | 7.3s |  |
| 8 | `air_ifilepromise` | 1 | 7.3s |  |
| 9 | `all_classes/security/swf11` | 3 | 7.4s |  |
| 10 | `amf_array_serialization` | 17 | 9.3s |  |
| 11 | `amf_custom_obj` | 26 | 7.4s |  |
| 12 | `amf_dictionary` | 9 | 7.3s |  |
| 13 | `amf_function` | 46 | 7.4s |  |
| 14 | `amf_invalid_date` | 2 | 7.2s |  |
| 15 | `amf_missing_prop` | 6 | 7.3s |  |
| 16 | `amf_nondynamic_function_prop` | 6 | 7.6s |  |
| 17 | `amf_setter_error` | 8 | 7.6s |  |
| 18 | `amf_vector` | 40 | 7.7s |  |
| 19 | `amf_xml` | 6 | 7.5s |  |
| 20 | `application_domain` | 4 | 7.5s |  |
| 21 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.6s |  |
| 22 | `applicationdomain_hasdefinition_null` | 2 | 7.4s |  |
| 23 | `array_access` | 18 | 7.5s |  |
| 24 | `array_access_interpreter` | 4 | 7.5s |  |
| 25 | `array_access_no_pubns` | 2 | 7.4s |  |
| 26 | `array_concat` | 41 | 7.5s |  |
| 27 | `array_constr` | 10 | 7.4s |  |
| 28 | `array_delete` | 44 | 7.5s |  |
| 29 | `array_enumeration` | 10 | 7.5s |  |
| 30 | `array_enumeration_elements` | 11 | 7.5s |  |
| 31 | `array_every` | 8 | 7.5s |  |
| 32 | `array_filter` | 6 | 7.5s |  |
| 33 | `array_foreach` | 18 | 7.5s |  |
| 34 | `array_hasownproperty` | 11 | 3.3s |  |
| 35 | `array_holes` | 9 | 7.5s |  |
| 36 | `array_index_max` | 84 | 7.4s |  |
| 37 | `array_indexof` | 25 | 7.5s |  |
| 38 | `array_join` | 26 | 7.6s |  |
| 39 | `array_lastindexof` | 29 | 7.5s |  |
| 40 | `array_length` | 14 | 7.5s |  |
| 41 | `array_literal` | 3 | 7.5s |  |
| 42 | `array_map` | 8 | 7.4s |  |
| 43 | `array_pop` | 52 | 7.6s |  |
| 44 | `array_push` | 24 | 7.5s |  |
| 45 | `array_reborrow_bug` | 6 | 7.5s |  |
| 46 | `array_reverse` | 28 | 7.5s |  |
| 47 | `array_shift` | 51 | 3.4s |  |
| 48 | `array_slice` | 39 | 7.6s |  |
| 49 | `array_some` | 8 | 7.5s |  |
| 50 | `array_sort` | 297 | 8.1s |  |
| 51 | `array_sort_fun_swf12` | 2 | 7.5s |  |
| 52 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 53 | `array_sort_random` | 210 | 7.5s |  |
| 54 | `array_sort_swf10_32bit` | 1 | 7.5s |  |
| 55 | `array_sorton` | 545 | 8.2s |  |
| 56 | `array_sparse_ops` | 41 | 7.4s |  |
| 57 | `array_splice` | 133 | 7.5s |  |
| 58 | `array_splice2` | 428 | 7.5s |  |
| 59 | `array_splice_types` | 48 | 7.3s |  |
| 60 | `array_storage` | 8 | 7.2s |  |
| 61 | `array_tolocalestring` | 9 | 7.2s |  |
| 62 | `array_tostring` | 12 | 7.2s |  |
| 63 | `array_unshift` | 24 | 7.3s |  |
| 64 | `array_valueof` | 9 | 7.1s |  |
| 65 | `array_vector_null_callback` | 10 | 7.2s |  |
| 66 | `astype` | 28 | 7.3s |  |
| 67 | `astypelate` | 24 | 7.3s |  |
| 68 | `astypelate_propagates` | 1 | 7.2s |  |
| 69 | `asymmetric_key_events` | 11 | 7.4s |  |
| 70 | `av_networking_params` | 9 | 7.2s |  |
| 71 | `av_tag_data` | 2 | 7.2s |  |
| 72 | `avm2_catchup_dobj` | 158 | 7.8s |  |
| 73 | `away3d_advanced_shallow_water_demo` | 0 | 87.4s |  |
| 74 | `bevel_filter` | 187 | 7.4s |  |
| 75 | `bitand` | 1058 | 19.4s |  |
| 76 | `bitmap_constr` | 17 | 7.5s |  |
| 77 | `bitmap_data` | 1000 | 15.6s |  |
| 78 | `bitmap_pixelsnapping` | 2 | 27.0s |  |
| 79 | `bitmap_properties` | 23 | 7.6s |  |
| 80 | `bitmap_subclass` | 7 | 8.8s |  |
| 81 | `bitmap_subclass_properties` | 9 | 7.8s |  |
| 82 | `bitmap_timeline` | 9 | 7.5s |  |
| 83 | `bitmapdata_accuracy` | 1 | 46.6s |  |
| 84 | `bitmapdata_applyfilter_blur` | 0 | 27.8s |  |
| 85 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.3s |  |
| 86 | `bitmapdata_applyfilter_destpoint` | 0 | 26.9s |  |
| 87 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 27.3s |  |
| 88 | `bitmapdata_clone` | 13 | 7.5s |  |
| 89 | `bitmapdata_colortransform` | 0 | 7.8s |  |
| 90 | `bitmapdata_colortransform_oob` | 2 | 7.3s |  |
| 91 | `bitmapdata_constr` | 22 | 7.3s |  |
| 92 | `bitmapdata_constructor_from_timeline` | 1 | 7.6s |  |
| 93 | `bitmapdata_copychannel` | 0 | 29.7s |  |
| 94 | `bitmapdata_copypixels` | 23 | 28.1s |  |
| 95 | `bitmapdata_copypixels_blend_over` | 1 | 7.4s |  |
| 96 | `bitmapdata_copypixelstobytearray` | 39 | 7.3s |  |
| 97 | `bitmapdata_dispose` | 7 | 7.4s |  |
| 98 | `bitmapdata_draw` | 0 | 27.3s |  |
| 99 | `bitmapdata_draw_colortransform` | 0 | 7.7s |  |
| 100 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 27.0s |  |
| 101 | `bitmapdata_draw_filters` | 0 | 26.7s |  |
| 102 | `bitmapdata_draw_masks` | 0 | 7.4s |  |
| 103 | `bitmapdata_draw_rotation` | 0 | 7.7s |  |
| 104 | `bitmapdata_draw_self_via_graphic` | 0 | 7.7s |  |
| 105 | `bitmapdata_draw_stage` | 0 | 27.2s |  |
| 106 | `bitmapdata_drawwithquality` | 0 | 7.7s |  |
| 107 | `bitmapdata_embedded` | 9 | 7.8s |  |
| 108 | `bitmapdata_fillrect` | 0 | 7.6s |  |
| 109 | `bitmapdata_filter_sourcerect` | 0 | 26.8s |  |
| 110 | `bitmapdata_floodfill` | 35 | 7.3s |  |
| 111 | `bitmapdata_getpixels` | 39 | 27.0s |  |
| 112 | `bitmapdata_getvector` | 27 | 3.3s |  |
| 113 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 114 | `bitmapdata_hittest` | 112 | 8.0s |  |
| 115 | `bitmapdata_hittest_threshold` | 18 | 7.4s |  |
| 116 | `bitmapdata_opaque` | 0 | 7.5s |  |
| 117 | `bitmapdata_pixeldissolve` | 1037 | 8.0s |  |
| 118 | `bitmapdata_pixeldissolve_image` | 0 | 7.8s |  |
| 119 | `bitmapdata_rectangle_rounding` | 16 | 7.3s |  |
| 120 | `bitmapdata_setpixels` | 286 | 7.5s |  |
| 121 | `bitmapdata_setvector` | 26 | 7.5s |  |
| 122 | `bitmapdata_sync` | 0 | 26.7s |  |
| 123 | `bitmapdata_threshold` | 176 | 8.1s |  |
| 124 | `bitmapdata_zero_size` | 8 | 7.3s |  |
| 125 | `bitnot` | 46 | 7.4s |  |
| 126 | `bitor` | 1058 | 19.4s |  |
| 127 | `bitxor` | 1058 | 19.6s |  |
| 128 | `blend_mode_null` | 1 | 7.3s |  |
| 129 | `blend_multiply_alpha` | 0 | 7.6s |  |
| 130 | `blend_scroll` | 0 | 7.6s |  |
| 131 | `blend_shader_luma_lighten` | 3 | 8.0s |  |
| 132 | `blur_filter` | 43 | 8.1s |  |
| 133 | `boolean_constr` | 32 | 8.1s |  |
| 134 | `boolean_negation` | 30 | 8.0s |  |
| 135 | `boolean_tostring` | 8 | 7.9s |  |
| 136 | `broadcast_event` | 7 | 8.1s |  |
| 137 | `button_bounds` | 1 | 8.0s |  |
| 138 | `button_hittest` | 2 | 28.7s |  |
| 139 | `button_nested_frame` | 48 | 29.3s |  |
| 140 | `bytearray` | 48 | 8.2s |  |
| 141 | `bytearray_compress` | 31 | 7.9s |  |
| 142 | `bytearray_errors` | 24 | 8.1s |  |
| 143 | `bytearray_method_serialization` | 1 | 7.8s |  |
| 144 | `bytearray_oom` | 3 | 7.9s |  |
| 145 | `bytearray_readobject_amf0` | 50 | 8.0s |  |
| 146 | `bytearray_readobject_amf3` | 53 | 8.0s |  |
| 147 | `bytearray_readutf8bytes_with_bom` | 16 | 8.0s |  |
| 148 | `bytearray_serialization` | 3 | 7.9s |  |
| 149 | `bytearray_string_null` | 19 | 8.2s |  |
| 150 | `bytearray_tostring` | 15 | 7.9s |  |
| 151 | `bytearray_utf16` | 8 | 7.8s |  |
| 152 | `bytearray_writeobject` | 24 | 7.8s |  |
| 153 | `callee_in_initializer` | 6 | 7.8s |  |
| 154 | `callproplex_class` | 1 | 7.9s |  |
| 155 | `capabilities_resolution` | 8 | 29.6s |  |
| 156 | `catch_class` | 6 | 7.9s |  |
| 157 | `catch_scope_slot` | 7 | 3.6s |  |
| 158 | `checkfilter` | 4 | 3.5s |  |
| 159 | `class_call` | 32 | 8.1s |  |
| 160 | `class_cast_call` | 14 | 8.0s |  |
| 161 | `class_enumeration` | 4 | 7.9s |  |
| 162 | `class_has_own_property` | 2 | 7.9s |  |
| 163 | `class_init_interpreter_mode` | 1 | 7.8s |  |
| 164 | `class_is` | 32 | 8.0s |  |
| 165 | `class_methods` | 5 | 7.9s |  |
| 166 | `class_object_properties` | 10 | 8.0s |  |
| 167 | `class_singleton` | 18 | 7.9s |  |
| 168 | `class_supercalls_errors` | 35 | 8.2s |  |
| 169 | `class_supercalls_mismatched` | 26 | 8.0s |  |
| 170 | `class_superclass_wrong_order` | 1 | 29.4s |  |
| 171 | `class_to_locale_string` | 2 | 7.9s |  |
| 172 | `class_to_string` | 2 | 7.7s |  |
| 173 | `class_value_of` | 2 | 7.7s |  |
| 174 | `click_block` | 5 | 8.6s |  |
| 175 | `click_invisible` | 3 | 7.9s |  |
| 176 | `closures` | 12 | 7.6s |  |
| 177 | `coerce_return_type` | 40 | 7.7s |  |
| 178 | `coerce_return_type_fail` | 2 | 7.6s |  |
| 179 | `coerce_return_void` | 3 | 7.5s |  |
| 180 | `coerce_string` | 86 | 7.7s |  |
| 181 | `coerce_string_precision` | 28 | 7.7s |  |
| 182 | `coerce_to_primitive_side_effects` | 29 | 28.4s |  |
| 183 | `color_matrix_filter` | 19 | 7.8s |  |
| 184 | `construct_errors_swf10` | 8 | 7.7s |  |
| 185 | `construct_frame_list` | 22 | 28.6s |  |
| 186 | `construct_interface` | 3 | 7.7s |  |
| 187 | `constructor_call` | 3 | 7.6s |  |
| 188 | `constructors_vs_timeline` | 5 | 28.6s |  |
| 189 | `constructprop_dynamic_primitive` | 7 | 7.7s |  |
| 190 | `constructprop_method` | 2 | 7.6s |  |
| 191 | `content_element_basic` | 50 | 8.0s |  |
| 192 | `context3d_creation` | 9 | 7.7s |  |
| 193 | `control_flow_bool` | 4 | 7.6s |  |
| 194 | `control_flow_stricteq` | 8 | 7.7s |  |
| 195 | `convert_boolean` | 30 | 7.6s |  |
| 196 | `convert_integer` | 90 | 7.7s |  |
| 197 | `convert_number` | 56 | 7.7s |  |
| 198 | `convert_uinteger` | 90 | 7.8s |  |
| 199 | `convolution_filter` | 89 | 7.7s |  |
| 200 | `core_exceptions` | 47 | 8.7s |  |
| 201 | `cpool_index_invalid_bytecode_1` | 6 | 7.7s |  |
| 202 | `cpool_index_invalid_bytecode_2` | 3 | 7.7s |  |
| 203 | `cpool_index_invalid_bytecode_3` | 1 | 7.6s |  |
| 204 | `cross_api_version_call_older` | 12 | 8.1s |  |
| 205 | `cryptscore` | 11 | 7.7s |  |
| 206 | `date` | 30 | 7.7s |  |
| 207 | `date_parse` | 36 | 7.3s |  |
| 208 | `declocal` | 46 | 7.3s |  |
| 209 | `declocal_i` | 46 | 7.3s |  |
| 210 | `decode_uri` | 71 | 7.7s |  |
| 211 | `decrement` | 46 | 7.2s |  |
| 212 | `decrement_i` | 46 | 3.1s |  |
| 213 | `default_values` | 7 | 7.1s |  |
| 214 | `dictionary_access` | 62 | 7.4s |  |
| 215 | `dictionary_access_no_pubns` | 2 | 7.1s |  |
| 216 | `dictionary_delete` | 101 | 7.7s |  |
| 217 | `dictionary_foreach` | 42 | 7.4s |  |
| 218 | `dictionary_hasownproperty` | 63 | 7.4s |  |
| 219 | `dictionary_in` | 62 | 7.4s |  |
| 220 | `dictionary_iter_modify` | 8 | 7.1s |  |
| 221 | `dictionary_namespaces` | 36 | 7.2s |  |
| 222 | `dictionary_primitive_keys` | 29 | 7.2s |  |
| 223 | `displacement_map_filter` | 61 | 7.4s |  |
| 224 | `displayobject_alpha` | 277 | 7.2s |  |
| 225 | `displayobject_blendmode` | 0 | 7.2s |  |
| 226 | `displayobject_colortransform_nested` | 0 | 26.3s |  |
| 227 | `displayobject_filters` | 17 | 7.4s |  |
| 228 | `displayobject_from_enterframe` | 1 | 26.2s |  |
| 229 | `displayobject_getbounds_shape` | 0 | 26.5s |  |
| 230 | `displayobject_height` | 6052 | 26.2s |  |
| 231 | `displayobject_hittestobject` | 32 | 7.4s |  |
| 232 | `displayobject_hittestpoint` | 49 | 7.5s |  |
| 233 | `displayobject_hittestpoint_root` | 13 | 7.5s |  |
| 234 | `displayobject_invalid_floats` | 60 | 7.3s |  |
| 235 | `displayobject_invalid_props` | 3 | 7.2s |  |
| 236 | `displayobject_mask` | 3 | 7.6s |  |
| 237 | `displayobject_mask_self_referential` | 0 | 26.1s |  |
| 238 | `displayobject_metaData` | 3 | 7.2s |  |
| 239 | `displayobject_name` | 22 | 26.1s |  |
| 240 | `displayobject_name_from_timeline` | 24 | 7.4s |  |
| 241 | `displayobject_opaque_background` | 6 | 26.1s |  |
| 242 | `displayobject_parent` | 12 | 7.2s |  |
| 243 | `displayobject_root` | 24 | 7.2s |  |
| 244 | `displayobject_rotation` | 1284 | 7.4s |  |
| 245 | `displayobject_set_matrix_nested` | 0 | 26.3s |  |
| 246 | `displayobject_set_name_loaded` | 3 | 7.6s |  |
| 247 | `displayobject_subclass` | 2 | 7.2s |  |
| 248 | `displayobject_visible` | 23 | 7.2s |  |
| 249 | `displayobject_width` | 4852 | 26.1s |  |
| 250 | `displayobject_x` | 614 | 7.2s |  |
| 251 | `displayobject_y` | 617 | 7.2s |  |
| 252 | `displayobjectcontainer_addchild` | 32 | 7.3s |  |
| 253 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.2s |  |
| 254 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 7.6s |  |
| 255 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 7.3s |  |
| 256 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 7.3s |  |
| 257 | `displayobjectcontainer_addchildat` | 42 | 7.2s |  |
| 258 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 7.3s |  |
| 259 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 7.3s |  |
| 260 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 7.3s |  |
| 261 | `displayobjectcontainer_contains` | 66 | 26.2s |  |
| 262 | `displayobjectcontainer_getchildat` | 4 | 7.2s |  |
| 263 | `displayobjectcontainer_getchildbyname` | 9 | 7.2s |  |
| 264 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.2s |  |
| 265 | `displayobjectcontainer_getchildindex` | 28 | 7.2s |  |
| 266 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 7.3s |  |
| 267 | `displayobjectcontainer_removechild` | 10 | 7.1s |  |
| 268 | `displayobjectcontainer_removechild_errors` | 4 | 7.2s |  |
| 269 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.3s |  |
| 270 | `displayobjectcontainer_removechildat` | 18 | 7.2s |  |
| 271 | `displayobjectcontainer_removechildren` | 51 | 7.4s |  |
| 272 | `displayobjectcontainer_setchildindex` | 42 | 7.0s |  |
| 273 | `displayobjectcontainer_stopallmovieclips` | 2 | 26.1s |  |
| 274 | `displayobjectcontainer_swapchildren` | 42 | 7.3s |  |
| 275 | `displayobjectcontainer_swapchildrenat` | 42 | 7.3s |  |
| 276 | `displayobjectcontainer_timelineinstance` | 48 | 26.7s |  |
| 277 | `divide` | 1058 | 19.7s |  |
| 278 | `doabc_is_eager` | 1 | 26.0s |  |
| 279 | `documentclass` | 9 | 7.4s |  |
| 280 | `domain_memory` | 133 | 27.8s |  |
| 281 | `drag_drop` | 10 | 7.5s |  |
| 282 | `drop_shadow_filter` | 172 | 7.5s |  |
| 283 | `duplicate_defs` | 1 | 7.2s |  |
| 284 | `eager_init` | 1 | 7.3s |  |
| 285 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 286 | `edit_text_linkage` | 7 | 7.6s |  |
| 287 | `edittext_align` | 60 | 7.7s |  |
| 288 | `edittext_always_show_selection` | 0 | 27.1s |  |
| 289 | `edittext_antialiastype` | 296 | 7.6s |  |
| 290 | `edittext_at_point_methods_basic` | 16 | 8.8s |  |
| 291 | `edittext_autosize` | 39 | 7.7s |  |
| 292 | `edittext_autosize_align` | 0 | 27.1s |  |
| 293 | `edittext_autosize_height_dynamic` | 60 | 27.0s |  |
| 294 | `edittext_autosize_height_input` | 60 | 7.5s |  |
| 295 | `edittext_autosize_lazy_bounds_events` | 65 | 7.7s |  |
| 296 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.4s |  |
| 297 | `edittext_autosize_lazy_bounds_props` | 490 | 8.9s |  |
| 298 | `edittext_autosize_lazy_bounds_visual` | 0 | 27.0s |  |
| 299 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.7s |  |
| 300 | `edittext_bottom_scroll_v_basic` | 210 | 7.6s |  |
| 301 | `edittext_bounds_scale` | 24 | 26.7s |  |
| 302 | `edittext_bullet` | 30 | 7.4s |  |
| 303 | `edittext_default_format` | 221 | 7.7s |  |
| 304 | `edittext_default_format_empty` | 136 | 7.7s |  |
| 305 | `edittext_empty_text_format` | 7 | 7.5s |  |
| 306 | `edittext_focus_selection` | 5 | 7.5s |  |
| 307 | `edittext_font_size` | 45 | 7.4s |  |
| 308 | `edittext_format_empty_font` | 8 | 7.4s |  |
| 309 | `edittext_get_char_index_at_point` | 4 | 28.6s |  |
| 310 | `edittext_get_line_index_at_point` | 2 | 26.9s |  |
| 311 | `edittext_get_line_index_of_char` | 76 | 8.3s |  |
| 312 | `edittext_getcharboundaries` | 172 | 7.7s |  |
| 313 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.1s |  |
| 314 | `edittext_getcharboundaries_scroll` | 85 | 21.0s |  |
| 315 | `edittext_getlinemetrics` | 146 | 6.0s |  |
| 316 | `edittext_html` | 3101 | 6.2s |  |
| 317 | `edittext_html_condensewhite` | 487 | 5.9s |  |
| 318 | `edittext_html_entity` | 4 | 6.2s |  |
| 319 | `edittext_html_font_size_swf12` | 267 | 5.9s |  |
| 320 | `edittext_html_font_size_swf13` | 273 | 5.6s |  |
| 321 | `edittext_html_roundtrip` | 17 | 5.8s |  |
| 322 | `edittext_ime_focus_lost` | 9 | 20.9s |  |
| 323 | `edittext_input_control` | 12 | 6.0s |  |
| 324 | `edittext_leading` | 9 | 6.1s |  |
| 325 | `edittext_letter_spacing` | 15 | 5.8s |  |
| 326 | `edittext_line_methods` | 294 | 7.0s |  |
| 327 | `edittext_line_metrics` | 11 | 22.1s |  |
| 328 | `edittext_margins` | 25 | 5.9s |  |
| 329 | `edittext_max_scroll_h_basic` | 475 | 6.0s |  |
| 330 | `edittext_max_scroll_v_basic` | 1000 | 5.9s |  |
| 331 | `edittext_mouse_selection` | 363 | 21.9s |  |
| 332 | `edittext_mousedown` | 3 | 6.1s |  |
| 333 | `edittext_mouseenabled` | 26 | 5.9s |  |
| 334 | `edittext_newline_character` | 22 | 5.8s |  |
| 335 | `edittext_newline_stripping` | 64 | 8.0s |  |
| 336 | `edittext_newlines` | 30 | 5.9s |  |
| 337 | `edittext_paragraph_methods` | 257 | 5.8s |  |
| 338 | `edittext_paste_events` | 8 | 6.0s |  |
| 339 | `edittext_paste_maxchars` | 4 | 5.8s |  |
| 340 | `edittext_paste_restrict` | 16 | 5.7s |  |
| 341 | `edittext_restrict` | 191 | 5.8s |  |
| 342 | `edittext_restrict_events` | 22 | 5.8s |  |
| 343 | `edittext_scrollh` | 10 | 5.8s |  |
| 344 | `edittext_selected_text` | 9 | 5.8s |  |
| 345 | `edittext_set_html_same` | 17 | 5.8s |  |
| 346 | `edittext_set_text_vs_html` | 9 | 5.8s |  |
| 347 | `edittext_stylesheet` | 536 | 6.1s |  |
| 348 | `edittext_stylesheet_custom_tag` | 76 | 5.8s |  |
| 349 | `edittext_stylesheet_display` | 272 | 5.9s |  |
| 350 | `edittext_underline` | 40 | 5.9s |  |
| 351 | `edittext_width_height` | 103 | 23.8s |  |
| 352 | `edittext_wordwrap_word` | 150 | 26.4s |  |
| 353 | `edittext_wrap_breaks` | 2375 | 7.7s |  |
| 354 | `element_format_clone` | 44 | 7.5s |  |
| 355 | `element_format_constructor_order` | 64 | 7.5s |  |
| 356 | `element_format_properties` | 235 | 8.2s |  |
| 357 | `empty_bounds` | 1 | 7.1s |  |
| 358 | `encode_uri_surrogate_pair_invalid` | 8 | 7.3s |  |
| 359 | `encode_uri_surrogate_pair_swf11` | 15 | 7.0s |  |
| 360 | `equals` | 512 | 11.4s |  |
| 361 | `error_geterrormessage` | 779 | 7.2s |  |
| 362 | `error_prototype` | 15 | 7.3s |  |
| 363 | `error_stack_trace_debug_swf17` | 0 | 26.0s |  |
| 364 | `error_stack_trace_debug_swf18` | 0 | 7.0s |  |
| 365 | `error_stack_trace_release_swf17` | 0 | 7.1s |  |
| 366 | `error_stack_trace_release_swf18` | 0 | 7.1s |  |
| 367 | `error_tostring` | 29 | 7.1s |  |
| 368 | `error_tostring_more` | 86 | 7.3s |  |
| 369 | `es3_inheritance` | 31 | 7.2s |  |
| 370 | `es4_inheritance` | 30 | 7.2s |  |
| 371 | `es4_interfaces` | 30 | 7.2s |  |
| 372 | `es4_method_binding` | 8 | 7.2s |  |
| 373 | `es4_oop_prototypes` | 14 | 7.3s |  |
| 374 | `es4_protected_inheritance` | 6 | 7.2s |  |
| 375 | `escape` | 71 | 7.2s |  |
| 376 | `event_bubbles` | 2 | 7.1s |  |
| 377 | `event_cancelable` | 2 | 7.1s |  |
| 378 | `event_clone` | 20 | 7.2s |  |
| 379 | `event_clone_error_redispatch` | 3 | 7.3s |  |
| 380 | `event_clone_on_redispatch` | 10 | 7.3s |  |
| 381 | `event_formattostring` | 31 | 7.2s |  |
| 382 | `event_isdefaultprevented` | 12 | 7.2s |  |
| 383 | `event_target_getter` | 5 | 3.1s |  |
| 384 | `event_target_set` | 9 | 7.1s |  |
| 385 | `event_type` | 1 | 25.1s |  |
| 386 | `event_valueof_tostring` | 18 | 7.4s |  |
| 387 | `eventdispatcher_dispatchevent` | 12 | 7.6s |  |
| 388 | `eventdispatcher_dispatchevent_cancel` | 20 | 27.5s |  |
| 389 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.2s |  |
| 390 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.1s |  |
| 391 | `eventdispatcher_dispatchevent_this` | 5 | 7.1s |  |
| 392 | `eventdispatcher_haseventlistener` | 25 | 7.3s |  |
| 393 | `eventdispatcher_interface_invoke` | 1 | 7.0s |  |
| 394 | `eventdispatcher_tostring` | 10 | 7.1s |  |
| 395 | `eventdispatcher_willtrigger` | 25 | 7.0s |  |
| 396 | `falsiness` | 30 | 7.1s |  |
| 397 | `fast_index_access` | 12 | 7.2s |  |
| 398 | `filefilter_properties` | 4 | 7.2s |  |
| 399 | `filereference_browse_cancel` | 3 | 7.1s |  |
| 400 | `filereference_browse_select` | 9 | 7.2s |  |
| 401 | `filereference_load` | 31 | 7.4s |  |
| 402 | `filereference_save` | 16 | 7.5s |  |
| 403 | `filereference_save_and_browse` | 42 | 7.3s |  |
| 404 | `filereference_save_and_load` | 22 | 8.1s |  |
| 405 | `filereference_uninitialized` | 8 | 7.2s |  |
| 406 | `filereferencelist_browse_cancel` | 6 | 7.1s |  |
| 407 | `filereferencelist_browse_select` | 7 | 7.0s |  |
| 408 | `filter_rewind` | 8 | 7.7s |  |
| 409 | `filters_array_holes` | 25 | 7.2s |  |
| 410 | `finddef` | 3 | 7.1s |  |
| 411 | `findprop_global_prototype` | 6 | 7.2s |  |
| 412 | `flash_media_video_constructor` | 156 | 7.9s |  |
| 413 | `flash_media_video_rotation_probe` | 27 | 7.2s |  |
| 414 | `flash_media_video_setter` | 40 | 7.5s |  |
| 415 | `flash_xml` | 29 | 7.3s |  |
| 416 | `flash_xml_cloneNode` | 22 | 7.2s |  |
| 417 | `flash_xml_namespace` | 109 | 7.0s |  |
| 418 | `flash_xml_removeNode` | 60 | 7.1s |  |
| 419 | `focus_events_code` | 161 | 27.1s |  |
| 420 | `focus_events_key_basic` | 132 | 27.2s |  |
| 421 | `focus_events_key_navigation` | 53 | 7.2s |  |
| 422 | `focus_events_key_same_object` | 26 | 7.1s |  |
| 423 | `focus_events_mixed_key_mouse` | 100 | 27.1s |  |
| 424 | `focus_events_mouse_basic` | 260 | 42.5s |  |
| 425 | `focus_events_mouse_focusable` | 112 | 26.2s |  |
| 426 | `focus_events_mouse_same_object` | 40 | 25.8s |  |
| 427 | `focus_remove` | 20 | 25.7s |  |
| 428 | `focus_root_movie` | 4 | 27.1s |  |
| 429 | `focus_stage` | 1 | 7.0s |  |
| 430 | `focusrect` | 18 | 7.8s |  |
| 431 | `focusrect_focuslost` | 9 | 7.1s |  |
| 432 | `focusrect_property` | 110 | 25.4s |  |
| 433 | `font_description_clone` | 14 | 7.2s |  |
| 434 | `font_embedded` | 24 | 7.5s |  |
| 435 | `font_enumeratefonts` | 41 | 7.7s |  |
| 436 | `font_enumeratefonts_filter` | 4 | 25.9s |  |
| 437 | `font_enumeratefonts_order` | 9 | 8.3s |  |
| 438 | `font_hasglyphs` | 40 | 7.5s |  |
| 439 | `font_registerfont` | 129 | 8.0s |  |
| 440 | `framelabel_constr` | 5 | 7.2s |  |
| 441 | `function_call` | 12 | 7.1s |  |
| 442 | `function_call_arguments` | 46 | 7.3s |  |
| 443 | `function_call_arguments_enumerate` | 5 | 7.0s |  |
| 444 | `function_call_coercion` | 108 | 7.5s |  |
| 445 | `function_call_default` | 6 | 7.1s |  |
| 446 | `function_call_rest` | 22 | 7.1s |  |
| 447 | `function_call_types` | 3 | 7.0s |  |
| 448 | `function_call_via_apply` | 11 | 7.1s |  |
| 449 | `function_call_via_call` | 3 | 7.0s |  |
| 450 | `function_display_anonymous` | 7 | 3.1s |  |
| 451 | `function_length` | 6 | 7.1s |  |
| 452 | `function_object` | 2 | 7.1s |  |
| 453 | `function_proto` | 5 | 7.0s |  |
| 454 | `function_proto_created` | 61 | 7.2s |  |
| 455 | `function_to_locale_string` | 4 | 7.0s |  |
| 456 | `function_to_string` | 4 | 7.0s |  |
| 457 | `function_type` | 6 | 7.0s |  |
| 458 | `function_unbound_this` | 51 | 7.2s |  |
| 459 | `function_value_of` | 4 | 7.0s |  |
| 460 | `game_input` | 4 | 7.1s |  |
| 461 | `generate_random_bytes` | 3 | 7.1s |  |
| 462 | `get_definition_by_name` | 11 | 7.1s |  |
| 463 | `get_qualified_class_name` | 20 | 23.4s |  |
| 464 | `get_qualified_super_class_name` | 18 | 7.2s |  |
| 465 | `get_slot_edge_cases` | 1 | 25.4s |  |
| 466 | `get_timer` | 2 | 7.1s |  |
| 467 | `getglobalslot` | 1 | 7.1s |  |
| 468 | `getouterscope` | 8 | 7.0s |  |
| 469 | `getouterscope_two_classobjects` | 13 | 7.0s |  |
| 470 | `getter_different_namespace_setter` | 2 | 7.0s |  |
| 471 | `glow_filter` | 127 | 7.3s |  |
| 472 | `goto_button_nested_framescript` | 28 | 25.9s |  |
| 473 | `goto_in_constructframe` | 12 | 25.8s |  |
| 474 | `goto_in_scene_last_frame` | 2 | 25.5s |  |
| 475 | `goto_methods` | 56 | 7.3s |  |
| 476 | `goto_methods_swfver10` | 8 | 7.1s |  |
| 477 | `goto_nested_construct_sibling` | 18 | 7.6s |  |
| 478 | `goto_nested_framescript` | 9 | 7.3s |  |
| 479 | `goto_on_orphan` | 15 | 7.3s |  |
| 480 | `gradient_bevel_filter` | 206 | 7.2s |  |
| 481 | `gradient_glow_filter` | 206 | 7.1s |  |
| 482 | `graphics_bad_direct_commands` | 5 | 9.6s |  |
| 483 | `graphics_bitmap_fill` | 0 | 27.5s |  |
| 484 | `graphics_bitmaps` | 0 | 7.8s |  |
| 485 | `graphics_direct_commands` | 0 | 7.7s |  |
| 486 | `graphics_draw_triangles` | 98 | 26.6s |  |
| 487 | `graphics_gradients` | 0 | 7.5s |  |
| 488 | `graphics_gradients_nulls` | 0 | 7.3s |  |
| 489 | `graphics_path` | 56 | 7.2s |  |
| 490 | `graphics_round_rects` | 0 | 7.2s |  |
| 491 | `graphics_simple_shapes` | 0 | 7.4s |  |
| 492 | `greaterequals` | 512 | 11.2s |  |
| 493 | `greaterthan` | 512 | 11.0s |  |
| 494 | `has_own_property` | 102 | 7.6s |  |
| 495 | `hasownproperty_namespaces` | 2 | 7.1s |  |
| 496 | `hello_world` | 1 | 7.1s |  |
| 497 | `hittest_morph` | 30 | 7.2s |  |
| 498 | `if_eq` | 10 | 7.2s |  |
| 499 | `if_gt` | 1 | 7.2s |  |
| 500 | `if_gte` | 10 | 24.9s |  |
| 501 | `if_lt` | 1 | 7.8s |  |
| 502 | `if_lte` | 10 | 7.7s |  |
| 503 | `if_ne` | 7 | 3.4s |  |
| 504 | `if_stricteq` | 6 | 7.8s |  |
| 505 | `if_strictne` | 11 | 7.8s |  |
| 506 | `ime_linux_dead_keys` | 10 | 28.8s |  |
| 507 | `in` | 102 | 8.3s |  |
| 508 | `inclocal` | 46 | 7.8s |  |
| 509 | `inclocal_i` | 46 | 7.8s |  |
| 510 | `increment` | 46 | 7.8s |  |
| 511 | `increment_i` | 46 | 7.8s |  |
| 512 | `indexing_delete` | 75 | 7.8s |  |
| 513 | `instanceof` | 58 | 8.1s |  |
| 514 | `instantiate_root_character` | 4 | 8.0s |  |
| 515 | `instantiation_on_enter_frame` | 7 | 28.6s |  |
| 516 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.7s |  |
| 517 | `int_constr` | 92 | 8.0s |  |
| 518 | `int_edge_cases` | 19 | 7.8s |  |
| 519 | `int_instanceof` | 3 | 7.6s |  |
| 520 | `int_tofixed` | 1215 | 7.7s |  |
| 521 | `int_tostring` | 3375 | 8.1s |  |
| 522 | `interactiveobject_enabled` | 25 | 7.7s |  |
| 523 | `interface_namespaces` | 78 | 8.0s |  |
| 524 | `invalid_utf8` | 12 | 7.8s |  |
| 525 | `is_finite` | 46 | 7.9s |  |
| 526 | `is_nan` | 46 | 7.7s |  |
| 527 | `is_prototype_of` | 12 | 7.7s |  |
| 528 | `issue_10221` | 2 | 7.7s |  |
| 529 | `issue_13780` | 12 | 7.8s |  |
| 530 | `issue_14901` | 1 | 7.6s |  |
| 531 | `issue_17675_edittext_paste_maxchars` | 1 | 7.8s |  |
| 532 | `issue_5292` | 5 | 7.7s |  |
| 533 | `issue_8630` | 2 | 28.3s |  |
| 534 | `issue_8630_placeremoveplace` | 15 | 7.9s |  |
| 535 | `issue_8630_scriptremove` | 11 | 7.5s |  |
| 536 | `istype` | 24 | 3.3s |  |
| 537 | `istypelate` | 58 | 7.7s |  |
| 538 | `istypelate_coerce` | 198 | 20.0s |  |
| 539 | `jpeg_loader_context` | 6 | 21.4s |  |
| 540 | `json_errors` | 9 | 21.6s |  |
| 541 | `json_parse` | 21 | 6.0s |  |
| 542 | `json_stringify` | 12 | 6.2s |  |
| 543 | `json_stringify_order` | 1 | 5.9s |  |
| 544 | `json_version_gated` | 1 | 6.0s |  |
| 545 | `key_input_80percent` | 1812 | 6.2s |  |
| 546 | `key_input_location` | 126 | 6.2s |  |
| 547 | `key_input_numpad` | 384 | 6.0s |  |
| 548 | `lazyinit` | 17 | 6.5s |  |
| 549 | `lessequals` | 512 | 9.0s |  |
| 550 | `lessthan` | 512 | 9.1s |  |
| 551 | `loader_bitmap_transparency` | 14 | 6.3s |  |
| 552 | `loader_bytes_unknown_content` | 14 | 6.0s |  |
| 553 | `loader_child_getdefinition` | 5 | 6.1s |  |
| 554 | `loader_duplicate_coerce` | 3 | 6.2s |  |
| 555 | `loader_duplicate_coerce_new_domain` | 4 | 6.1s |  |
| 556 | `loader_error_in_root_ctor` | 4 | 6.3s |  |
| 557 | `loader_events` | 92 | 8.0s |  |
| 558 | `loader_image` | 8 | 6.5s |  |
| 559 | `loader_jpegxr` | 2 | 21.8s |  |
| 560 | `loader_jpegxr_alpha` | 1 | 21.3s |  |
| 561 | `loader_loadbytes_events` | 30 | 6.6s |  |
| 562 | `loader_loadbytes_invalid_png` | 4 | 21.2s |  |
| 563 | `loader_loadbytes_url` | 12 | 6.2s |  |
| 564 | `loader_loaderurl` | 6 | 6.4s |  |
| 565 | `loader_method` | 85 | 6.1s |  |
| 566 | `loader_noninteractive_try_click_root` | 5 | 22.0s |  |
| 567 | `loader_reuse` | 38 | 6.2s |  |
| 568 | `loader_unknown_content` | 24 | 6.1s |  |
| 569 | `loader_visibility_interactive` | 1 | 6.2s |  |
| 570 | `loaderinfo_events` | 7 | 5.9s |  |
| 571 | `loaderinfo_loadurl` | 12 | 42.7s |  |
| 572 | `loaderinfo_more` | 6 | 26.8s |  |
| 573 | `loaderinfo_properties` | 18 | 7.2s |  |
| 574 | `loaderinfo_properties_not_loaded` | 23 | 7.5s |  |
| 575 | `loaderinfo_root` | 10 | 7.2s |  |
| 576 | `loaderinfo_root_allows` | 2 | 7.2s |  |
| 577 | `localconnection_send` | 4 | 7.2s |  |
| 578 | `lshift` | 1058 | 19.4s |  |
| 579 | `mask_reapply` | 1 | 7.3s |  |
| 580 | `math` | 497 | 7.5s |  |
| 581 | `matrix3d` | 57 | 8.0s |  |
| 582 | `matrix3d_compose` | 34 | 7.4s |  |
| 583 | `matrix3d_invert` | 18 | 7.2s |  |
| 584 | `method_without_body` | 3 | 26.0s |  |
| 585 | `missing_external_interface` | 10 | 7.2s |  |
| 586 | `modulo` | 1058 | 19.1s |  |
| 587 | `morph_shape` | 2 | 26.1s |  |
| 588 | `mouse_children` | 192 | 26.5s |  |
| 589 | `mouse_click_events` | 90 | 26.0s |  |
| 590 | `mouse_double_click_events` | 188 | 7.2s |  |
| 591 | `mouse_empty_parent` | 4 | 7.2s |  |
| 592 | `mouse_over_while_dragging` | 3 | 7.4s |  |
| 593 | `mouse_pick_button_mode` | 2 | 7.3s |  |
| 594 | `mouse_pick_dobj_mask` | 4 | 7.5s |  |
| 595 | `mouse_pick_masking` | 7 | 26.2s |  |
| 596 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 26.1s |  |
| 597 | `mouse_pick_non_interactive_dobj_mask` | 3 | 7.6s |  |
| 598 | `mouse_pick_text` | 8 | 7.5s |  |
| 599 | `mouse_sibling` | 8 | 7.3s |  |
| 600 | `mouse_wheel_events` | 36 | 27.4s |  |
| 601 | `mouseevent_constr` | 66 | 7.2s |  |
| 602 | `mouseevent_stagexy` | 35 | 7.2s |  |
| 603 | `mouseevent_valueof_tostring` | 28 | 7.2s |  |
| 604 | `movieclip_addframescript` | 3 | 26.1s |  |
| 605 | `movieclip_child_property` | 16 | 7.4s |  |
| 606 | `movieclip_constr` | 21 | 23.4s |  |
| 607 | `movieclip_currentlabels` | 17 | 25.5s |  |
| 608 | `movieclip_currentlabels_dupes1` | 46 | 25.9s |  |
| 609 | `movieclip_currentlabels_dupes2` | 30 | 7.3s |  |
| 610 | `movieclip_currentlabels_dupes3` | 67 | 7.2s |  |
| 611 | `movieclip_currentscene` | 12 | 25.8s |  |
| 612 | `movieclip_dispatchevent` | 430 | 7.3s |  |
| 613 | `movieclip_dispatchevent_cancel` | 102 | 7.3s |  |
| 614 | `movieclip_dispatchevent_handlerorder` | 251 | 7.2s |  |
| 615 | `movieclip_dispatchevent_selfadd` | 80 | 7.1s |  |
| 616 | `movieclip_dispatchevent_target` | 899 | 7.2s |  |
| 617 | `movieclip_displayevents` | 96 | 26.2s |  |
| 618 | `movieclip_displayevents_clickgoto` | 676 | 26.5s |  |
| 619 | `movieclip_displayevents_clickgoto2` | 2001 | 7.9s |  |
| 620 | `movieclip_displayevents_clickplay` | 575 | 7.4s |  |
| 621 | `movieclip_displayevents_clicksymbol` | 562 | 7.5s |  |
| 622 | `movieclip_displayevents_constructframegoto` | 140 | 7.8s |  |
| 623 | `movieclip_displayevents_constructframeplay` | 50 | 7.6s |  |
| 624 | `movieclip_displayevents_constructframesymbol` | 144 | 7.4s |  |
| 625 | `movieclip_displayevents_dblhandler` | 21 | 7.5s |  |
| 626 | `movieclip_displayevents_enterframegoto` | 149 | 7.5s |  |
| 627 | `movieclip_displayevents_enterframeplay` | 48 | 7.3s |  |
| 628 | `movieclip_displayevents_enterframesymbol` | 149 | 26.5s |  |
| 629 | `movieclip_displayevents_exitframegoto` | 106 | 7.5s |  |
| 630 | `movieclip_displayevents_exitframeplay` | 44 | 7.4s |  |
| 631 | `movieclip_displayevents_exitframesymbol` | 135 | 7.5s |  |
| 632 | `movieclip_displayevents_looping` | 63 | 26.4s |  |
| 633 | `movieclip_displayevents_stopped` | 113 | 7.7s |  |
| 634 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 635 | `movieclip_displayevents_timeline` | 128 | 26.6s |  |
| 636 | `movieclip_drawrect` | 54 | 7.4s |  |
| 637 | `movieclip_frameconstruct_skipped` | 9 | 7.5s |  |
| 638 | `movieclip_goto_during_frame_script` | 15 | 7.4s |  |
| 639 | `movieclip_goto_overwrite` | 14 | 26.6s |  |
| 640 | `movieclip_goto_scene_last_frame_int` | 1 | 26.5s |  |
| 641 | `movieclip_goto_scene_last_frame_label` | 1 | 7.2s |  |
| 642 | `movieclip_gotoandplay` | 15 | 25.8s |  |
| 643 | `movieclip_gotoandstop` | 13 | 25.6s |  |
| 644 | `movieclip_gotoandstop_children` | 4 | 7.3s |  |
| 645 | `movieclip_gotoandstop_framescripts1` | 4 | 7.2s |  |
| 646 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 647 | `movieclip_gotoandstop_framescripts_self` | 7 | 41.8s |  |
| 648 | `movieclip_gotoandstop_queueing` | 12 | 25.7s |  |
| 649 | `movieclip_hittest` | 67 | 7.3s |  |
| 650 | `movieclip_next_frame` | 2 | 25.6s |  |
| 651 | `movieclip_next_scene` | 6 | 25.3s |  |
| 652 | `movieclip_play` | 3 | 7.0s |  |
| 653 | `movieclip_prev_frame` | 3 | 6.9s |  |
| 654 | `movieclip_prev_scene` | 7 | 7.1s |  |
| 655 | `movieclip_properties` | 79 | 25.6s |  |
| 656 | `movieclip_queued_noop_goto_swf10` | 9 | 7.1s |  |
| 657 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 658 | `movieclip_scenes` | 11 | 7.0s |  |
| 659 | `movieclip_soundtransform` | 831 | 27.7s |  |
| 660 | `movieclip_stop` | 1 | 25.3s |  |
| 661 | `movieclip_super_is_symbol` | 20 | 7.4s |  |
| 662 | `movieclip_symbol_constr` | 8 | 7.2s |  |
| 663 | `movieclip_text_mousedown` | 1 | 7.2s |  |
| 664 | `movieclip_willtrigger` | 5 | 7.4s |  |
| 665 | `multiply` | 1058 | 19.1s |  |
| 666 | `namespace_constr` | 253 | 7.5s |  |
| 667 | `namespace_constr_args` | 1 | 7.1s |  |
| 668 | `namespace_enumeration_order` | 7 | 25.6s |  |
| 669 | `nan_scale` | 9 | 7.1s |  |
| 670 | `navigateToURL_target_normalize` | 107 | 27.2s |  |
| 671 | `negate` | 30 | 7.1s |  |
| 672 | `negative_volume_panned` | 0 | 7.4s |  |
| 673 | `nested_iteration` | 11 | 7.1s |  |
| 674 | `net_getClassByAlias` | 3 | 7.1s |  |
| 675 | `net_navigateToURL` | 57 | 7.1s |  |
| 676 | `net_stream_play_options` | 6 | 7.2s |  |
| 677 | `netconnection_close` | 55 | 7.1s |  |
| 678 | `netconnection_properties` | 78 | 7.2s |  |
| 679 | `netconnection_send_remote` | 50 | 7.5s |  |
| 680 | `netconnection_serialize_arrays` | 6 | 7.2s |  |
| 681 | `netstream_client` | 10 | 7.3s |  |
| 682 | `netstream_connect` | 7 | 7.1s |  |
| 683 | `newactivation_in_script_init` | 3 | 7.6s |  |
| 684 | `newclass_mismatched` | 4 | 7.6s |  |
| 685 | `newclass_twice` | 3 | 7.2s |  |
| 686 | `nonconflicting_declarations` | 0 | 7.5s |  |
| 687 | `null_void_types` | 8 | 7.3s |  |
| 688 | `number_autoconv` | 21 | 26.9s |  |
| 689 | `number_autoconv_amf` | 132 | 7.6s |  |
| 690 | `number_autoconv_array_sort_32bit` | 1 | 7.3s |  |
| 691 | `number_constr` | 58 | 7.5s |  |
| 692 | `number_toexponential` | 378 | 7.3s |  |
| 693 | `number_toexponential2` | 35 | 7.3s |  |
| 694 | `number_tofixed` | 378 | 7.3s |  |
| 695 | `number_toprecision` | 350 | 7.4s |  |
| 696 | `obfuscated_class_names` | 3 | 7.3s |  |
| 697 | `object_enumeration` | 10 | 7.3s |  |
| 698 | `object_prototype` | 4 | 7.4s |  |
| 699 | `object_to_locale_string` | 2 | 7.2s |  |
| 700 | `object_to_string` | 2 | 7.3s |  |
| 701 | `object_value_of` | 2 | 3.0s |  |
| 702 | `op_coerce` | 54 | 7.3s |  |
| 703 | `op_coerce_x` | 54 | 7.3s |  |
| 704 | `op_escxattr` | 2 | 7.5s |  |
| 705 | `op_escxelem` | 2 | 7.3s |  |
| 706 | `op_lookupswitch` | 4 | 7.3s |  |
| 707 | `optimize_coerce` | 1 | 7.2s |  |
| 708 | `orphan_movie_complex` | 80 | 7.8s |  |
| 709 | `orphan_movie_reorder` | 111 | 26.9s |  |
| 710 | `package_namespace` | 7 | 7.4s |  |
| 711 | `param_default_value_has_zero_cpool_index` | 1 | 7.3s |  |
| 712 | `parent_early_access_child` | 16 | 26.8s |  |
| 713 | `parse_float` | 81 | 7.6s |  |
| 714 | `parse_float_swf10` | 81 | 7.3s |  |
| 715 | `parse_int` | 135 | 7.9s |  |
| 716 | `perspective_projection_basic` | 40 | 7.5s |  |
| 717 | `pixelbender_ceil` | 77 | 7.6s |  |
| 718 | `pixelbender_conditional` | 138 | 45.0s |  |
| 719 | `pixelbender_conversions` | 270 | 8.0s |  |
| 720 | `pixelbender_dithering` | 8 | 36.3s |  |
| 721 | `pixelbender_div` | 36 | 7.8s |  |
| 722 | `pixelbender_effect_BlurredFocus` | 0 | 35.8s |  |
| 723 | `pixelbender_effect_glassDisplace` | 0 | 13.8s |  |
| 724 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 31.6s |  |
| 725 | `pixelbender_effect_smudge` | 0 | 11.1s |  |
| 726 | `pixelbender_effect_tintype` | 0 | 10.3s |  |
| 727 | `pixelbender_effect_twirl` | 0 | 12.1s |  |
| 728 | `pixelbender_eof` | 7 | 7.6s |  |
| 729 | `pixelbender_images` | 0 | 10.2s |  |
| 730 | `pixelbender_input` | 103 | 27.3s |  |
| 731 | `pixelbender_logicalnot` | 20 | 7.2s |  |
| 732 | `pixelbender_malformed_data` | 190 | 26.8s |  |
| 733 | `pixelbender_multiple_out_params` | 1 | 7.2s |  |
| 734 | `pixelbender_no_out_param` | 6 | 7.3s |  |
| 735 | `pixelbender_outputs` | 13 | 7.5s |  |
| 736 | `pixelbender_padding_bytes` | 22 | 7.3s |  |
| 737 | `pixelbender_param_qualifier` | 512 | 7.4s |  |
| 738 | `pixelbender_parameters` | 1563 | 7.6s |  |
| 739 | `pixelbender_parameters_bool` | 240 | 7.5s |  |
| 740 | `pixelbender_parameters_int_vs_bool` | 54 | 7.4s |  |
| 741 | `pixelbender_parse_errors` | 6 | 7.4s |  |
| 742 | `pixelbender_rsqrt` | 24 | 7.6s |  |
| 743 | `pixelbender_select_kinds` | 8 | 7.5s |  |
| 744 | `pixelbender_shaderdata` | 49 | 7.4s |  |
| 745 | `pixelbender_shaderdata_setter` | 99 | 7.8s |  |
| 746 | `pixelbender_sign` | 60 | 7.6s |  |
| 747 | `pixelbender_vector_output` | 11 | 7.7s |  |
| 748 | `place_and_lookup/swf10` | 33 | 7.3s |  |
| 749 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 750 | `place_multiple` | 17 | 26.3s |  |
| 751 | `place_object_replace` | 9 | 7.6s |  |
| 752 | `place_object_replace_2` | 24 | 7.5s |  |
| 753 | `place_object_same_depth_frame` | 1 | 7.4s |  |
| 754 | `point` | 132 | 8.0s |  |
| 755 | `primitive_edge_cases` | 1 | 7.3s |  |
| 756 | `print_job_options` | 3 | 7.3s |  |
| 757 | `property_is_enumerable_reset` | 23 | 8.0s |  |
| 758 | `property_priority` | 22 | 8.3s |  |
| 759 | `property_priority_chained` | 4 | 7.8s |  |
| 760 | `property_priority_definition_names_order` | 2 | 8.2s |  |
| 761 | `property_priority_three_level` | 6 | 28.4s |  |
| 762 | `propertyisenumerable_namespaces` | 6 | 8.0s |  |
| 763 | `prototype_set_null` | 7 | 7.9s |  |
| 764 | `proxy_callproperty` | 24 | 7.9s |  |
| 765 | `proxy_deleteproperty` | 64 | 8.0s |  |
| 766 | `proxy_enumeration` | 34 | 7.9s |  |
| 767 | `proxy_getproperty` | 77 | 8.0s |  |
| 768 | `proxy_hasownproperty` | 8 | 7.8s |  |
| 769 | `proxy_hasproperty` | 32 | 8.0s |  |
| 770 | `proxy_serialize` | 9 | 7.9s |  |
| 771 | `proxy_setproperty` | 42 | 8.0s |  |
| 772 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.8s |  |
| 773 | `qname_constr` | 32 | 7.9s |  |
| 774 | `qname_constr_namespace` | 24 | 7.9s |  |
| 775 | `qname_enumeration` | 9 | 7.8s |  |
| 776 | `qname_indexing` | 23 | 7.8s |  |
| 777 | `qname_tostring` | 25 | 8.0s |  |
| 778 | `qname_valueof` | 29 | 8.0s |  |
| 779 | `rectangle` | 1094 | 8.6s |  |
| 780 | `regexp_constr` | 148 | 8.2s |  |
| 781 | `regexp_exec` | 19 | 8.0s |  |
| 782 | `regexp_extended` | 47 | 7.8s |  |
| 783 | `regexp_multiargs` | 1 | 7.8s |  |
| 784 | `regexp_test` | 27 | 7.9s |  |
| 785 | `regexp_toString` | 10 | 7.8s |  |
| 786 | `register_script_refresh` | 35 | 28.9s |  |
| 787 | `remove_child_clear_field` | 88 | 8.3s |  |
| 788 | `remove_dobj` | 3 | 7.9s |  |
| 789 | `resolve_order` | 4 | 7.9s |  |
| 790 | `responder_null_callbacks` | 1 | 7.8s |  |
| 791 | `rng` | 1 | 9.2s |  |
| 792 | `rootless` | 42 | 8.1s |  |
| 793 | `rshift` | 1058 | 19.4s |  |
| 794 | `sandbox_type_inherited` | 2 | 8.3s |  |
| 795 | `sandbox_type_local_file` | 1 | 44.7s |  |
| 796 | `sandbox_type_local_network` | 1 | 7.4s |  |
| 797 | `scene_constr` | 8 | 7.9s |  |
| 798 | `scopes_dont_cache/order-1` | 1 | 28.1s |  |
| 799 | `scopes_dont_cache/order-2` | 1 | 1.1s |  |
| 800 | `security_domain_current` | 2 | 7.6s |  |
| 801 | `selection` | 239 | 8.1s |  |
| 802 | `set_local_0` | 31 | 7.7s |  |
| 803 | `set_property_is_enumerable` | 85 | 8.0s |  |
| 804 | `shaderparameter_value` | 4 | 7.6s |  |
| 805 | `shape_drawrect` | 54 | 7.6s |  |
| 806 | `shared_object_no_root` | 3 | 7.5s |  |
| 807 | `simplebutton_added_to_stage` | 45 | 27.7s |  |
| 808 | `simplebutton_childevents` | 86 | 28.0s |  |
| 809 | `simplebutton_childevents_nested` | 54 | 8.0s |  |
| 810 | `simplebutton_childevents_sprite` | 13 | 7.6s |  |
| 811 | `simplebutton_childprops` | 144 | 8.0s |  |
| 812 | `simplebutton_childshuffle` | 23 | 7.5s |  |
| 813 | `simplebutton_constr` | 36 | 7.9s |  |
| 814 | `simplebutton_constr_childevents` | 48 | 7.9s |  |
| 815 | `simplebutton_constr_params` | 42 | 7.7s |  |
| 816 | `simplebutton_mouseenabled` | 26 | 7.5s |  |
| 817 | `simplebutton_multi_children` | 19 | 7.8s |  |
| 818 | `simplebutton_structure` | 27 | 7.9s |  |
| 819 | `simplebutton_symbolclass` | 68 | 8.0s |  |
| 820 | `slot_disp_id_shared_numbering` | 1 | 27.4s |  |
| 821 | `slots_force_autoassigned` | 1 | 7.6s |  |
| 822 | `socket_after_disconnect` | 1 | 7.7s |  |
| 823 | `socket_close` | 2 | 7.5s |  |
| 824 | `socket_connect` | 4 | 7.6s |  |
| 825 | `socket_errors` | 56 | 8.1s |  |
| 826 | `socket_read_big` | 48 | 7.5s |  |
| 827 | `socket_read_little` | 48 | 3.2s |  |
| 828 | `socket_read_write_object` | 8 | 44.2s |  |
| 829 | `socket_write_big` | 15 | 7.7s |  |
| 830 | `socket_write_little` | 14 | 7.5s |  |
| 831 | `sound_embeddedprops` | 26 | 7.8s |  |
| 832 | `sound_play` | 19 | 7.7s |  |
| 833 | `sound_valueof` | 33 | 7.5s |  |
| 834 | `soundchannel_soundtransform` | 835 | 29.9s |  |
| 835 | `soundchannel_soundtransform_exists` | 5 | 27.4s |  |
| 836 | `soundchannel_stop` | 8 | 27.7s |  |
| 837 | `soundmixer_buffertime` | 5 | 7.5s |  |
| 838 | `soundmixer_stopall` | 6 | 27.6s |  |
| 839 | `soundtransform` | 442 | 13.6s |  |
| 840 | `space_justifier_clone` | 12 | 7.5s |  |
| 841 | `sprite_with_frames` | 0 | 30.3s |  |
| 842 | `stage3d_agal_cross_product` | 0 | 10.5s |  |
| 843 | `stage3d_agal_upload_errors` | 66 | 10.5s |  |
| 844 | `stage3d_bitmap` | 0 | 34.0s |  |
| 845 | `stage3d_blend` | 81 | 32.3s |  |
| 846 | `stage3d_context3d_string_args` | 158 | 8.6s |  |
| 847 | `stage3d_errors` | 7 | 7.7s |  |
| 848 | `stage3d_errors_atf` | 3 | 9.0s |  |
| 849 | `stage3d_errors_swf_29` | 6 | 7.9s |  |
| 850 | `stage3d_float1_index` | 0 | 29.9s |  |
| 851 | `stage3d_fractal` | 0 | 30.6s |  |
| 852 | `stage3d_ignore_sampler_override` | 0 | 30.4s |  |
| 853 | `stage3d_multistage_triangle` | 3 | 10.5s |  |
| 854 | `stage3d_program_constants_bytearray_be` | 0 | 31.4s |  |
| 855 | `stage3d_program_constants_bytearray_le` | 0 | 10.8s |  |
| 856 | `stage3d_program_constants_invalid_input` | 21 | 8.3s |  |
| 857 | `stage3d_raytrace` | 0 | 34.7s |  |
| 858 | `stage3d_rotating_cube` | 0 | 11.1s |  |
| 859 | `stage3d_sampler` | 0 | 10.8s |  |
| 860 | `stage3d_sampler_partial_upload` | 0 | 10.5s |  |
| 861 | `stage3d_stencil` | 0 | 30.7s |  |
| 862 | `stage3d_texture` | 0 | 33.7s |  |
| 863 | `stage3d_texture_bytearray` | 0 | 11.7s |  |
| 864 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.9s |  |
| 865 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 11.9s |  |
| 866 | `stage3d_triangle` | 0 | 10.2s |  |
| 867 | `stage3d_triangle_bytes4` | 0 | 10.2s |  |
| 868 | `stage3d_triangle_float1` | 0 | 10.1s |  |
| 869 | `stage3d_triangle_index_upload` | 0 | 10.2s |  |
| 870 | `stage3d_x_y` | 22 | 7.6s |  |
| 871 | `stage_access` | 10 | 7.5s |  |
| 872 | `stage_displayobject_properties` | 24 | 7.4s |  |
| 873 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.5s |  |
| 874 | `stage_framerate_nan` | 7 | 26.7s |  |
| 875 | `stage_framerate_negative` | 6 | 7.5s |  |
| 876 | `stage_framerate_zero` | 6 | 7.5s |  |
| 877 | `stage_invalidate` | 38 | 7.8s |  |
| 878 | `stage_loaderinfo_properties` | 24 | 26.8s |  |
| 879 | `stage_mousechildren` | 2 | 7.4s |  |
| 880 | `stage_mouseenabled` | 15 | 7.5s |  |
| 881 | `stage_overriden_setters` | 31 | 7.7s |  |
| 882 | `stage_properties` | 30 | 7.3s |  |
| 883 | `stage_stage3Ds_vector` | 1 | 26.2s |  |
| 884 | `static_text` | 3 | 7.7s |  |
| 885 | `static_var_with_this_in_ctor` | 2 | 7.6s |  |
| 886 | `stored_properties` | 11 | 7.8s |  |
| 887 | `strict_equality` | 34 | 7.7s |  |
| 888 | `string_call` | 13 | 7.7s |  |
| 889 | `string_case` | 23 | 7.7s |  |
| 890 | `string_char_at` | 27 | 7.9s |  |
| 891 | `string_char_code_at` | 28 | 7.6s |  |
| 892 | `string_concat_fromcharcode` | 37 | 7.6s |  |
| 893 | `string_constr` | 25 | 7.6s |  |
| 894 | `string_indexof_lastindexof` | 87 | 7.7s |  |
| 895 | `string_length` | 16 | 7.5s |  |
| 896 | `string_locale_compare` | 39 | 7.8s |  |
| 897 | `string_match` | 51 | 42.7s |  |
| 898 | `string_relational_compare` | 4 | 7.4s |  |
| 899 | `string_replace` | 51 | 7.5s |  |
| 900 | `string_search` | 41 | 7.5s |  |
| 901 | `string_slice_substr_substring` | 170 | 8.4s |  |
| 902 | `string_split` | 29 | 7.3s |  |
| 903 | `string_substr_negative` | 21 | 7.2s |  |
| 904 | `string_substr_weird` | 182 | 7.2s |  |
| 905 | `stylesheet` | 221 | 7.8s |  |
| 906 | `subtract` | 1058 | 19.4s |  |
| 907 | `super_get_call` | 12 | 7.3s |  |
| 908 | `supercall_two_classobjects` | 2 | 7.3s |  |
| 909 | `swf8` | 1 | 7.2s |  |
| 910 | `swf_10_queued_goto_scripts_construct` | 52 | 26.4s |  |
| 911 | `swf_9_goto_in_enter_frame` | 17 | 7.3s |  |
| 912 | `swf_9_goto_in_enter_frame_simple` | 15 | 7.3s |  |
| 913 | `swf_9_queued_goto_scripts` | 6 | 26.3s |  |
| 914 | `swf_9_queued_goto_scripts_construct` | 28 | 1.3s |  |
| 915 | `swf_9_versioning` | 2 | 7.2s |  |
| 916 | `swf_wrong_frame_count` | 38 | 7.5s |  |
| 917 | `swf_wrong_frame_count_isplaying` | 22 | 25.8s |  |
| 918 | `symbol_class_binary_data` | 8 | 7.3s |  |
| 919 | `symbol_class_conflict` | 4 | 9.5s |  |
| 920 | `symbol_class_root_not_zero` | 1 | 7.1s |  |
| 921 | `symbolclass_invalid_utf8` | 2 | 7.2s |  |
| 922 | `system_setclipboard_null` | 1 | 7.1s |  |
| 923 | `tab_ordering_arrows` | 998 | 27.4s |  |
| 924 | `tab_ordering_automatic_advanced` | 184 | 8.0s |  |
| 925 | `tab_ordering_automatic_basic` | 45 | 7.3s |  |
| 926 | `tab_ordering_children` | 116 | 41.8s |  |
| 927 | `tab_ordering_custom_basic` | 34 | 7.2s |  |
| 928 | `tab_ordering_stage_tab_children` | 32 | 7.1s |  |
| 929 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.0s |  |
| 930 | `tab_ordering_tabbable` | 47 | 7.2s |  |
| 931 | `tabstop_properties` | 105 | 7.4s |  |
| 932 | `text_element_basic` | 34 | 7.2s |  |
| 933 | `text_engine_fontdescription` | 27 | 7.3s |  |
| 934 | `text_engine_groupelement` | 64 | 8.0s |  |
| 935 | `text_run` | 7 | 7.0s |  |
| 936 | `textblock_createline_errors` | 23 | 7.3s |  |
| 937 | `textblock_createline_fte` | 9 | 25.7s |  |
| 938 | `textblock_properties` | 118 | 7.5s |  |
| 939 | `textbox_click` | 37 | 25.6s |  |
| 940 | `textfield_event` | 66 | 7.3s |  |
| 941 | `textfield_focusin_event` | 9 | 7.1s |  |
| 942 | `textfield_input_dead_keys_windows` | 15 | 7.1s |  |
| 943 | `textfield_unload` | 39 | 25.6s |  |
| 944 | `textformat` | 1134 | 7.2s |  |
| 945 | `textformat_display` | 14 | 7.2s |  |
| 946 | `textformat_font_max_length` | 4 | 7.1s |  |
| 947 | `textline_inapplicable_properties` | 10 | 7.1s |  |
| 948 | `textline_name` | 1 | 7.0s |  |
| 949 | `textline_splitting_basic` | 76 | 7.2s |  |
| 950 | `textline_throwerror` | 30 | 7.1s |  |
| 951 | `textline_validity` | 162 | 7.2s |  |
| 952 | `throw` | 3 | 7.0s |  |
| 953 | `timeline_scripts` | 3 | 7.2s |  |
| 954 | `timer` | 90 | 8.1s |  |
| 955 | `timer_events` | 3 | 7.2s |  |
| 956 | `timer_finished` | 11 | 7.2s |  |
| 957 | `timer_reset` | 8 | 7.3s |  |
| 958 | `timer_setdelay` | 5 | 7.3s |  |
| 959 | `trace` | 12 | 7.0s |  |
| 960 | `truthiness` | 30 | 6.9s |  |
| 961 | `try_catch` | 11 | 23.8s |  |
| 962 | `try_catch_typed` | 12 | 7.2s |  |
| 963 | `typeof` | 30 | 7.2s |  |
| 964 | `uint_constr` | 92 | 7.3s |  |
| 965 | `uint_tofixed` | 1215 | 7.0s |  |
| 966 | `uint_tostring` | 3375 | 7.4s |  |
| 967 | `uncaught_error_basic` | 2 | 7.3s |  |
| 968 | `unchecked_function` | 15 | 7.2s |  |
| 969 | `unescape` | 28 | 7.2s |  |
| 970 | `url_loader` | 25 | 7.4s |  |
| 971 | `urlrequest` | 18 | 25.9s |  |
| 972 | `urlstream_basic` | 5 | 7.0s |  |
| 973 | `urshift` | 1058 | 19.0s |  |
| 974 | `utils3d` | 7 | 6.9s |  |
| 975 | `vector3d` | 397 | 11.6s |  |
| 976 | `vector_class` | 36 | 7.4s |  |
| 977 | `vector_class_call` | 11 | 7.2s |  |
| 978 | `vector_coercion` | 66 | 7.8s |  |
| 979 | `vector_concat` | 90 | 7.6s |  |
| 980 | `vector_constr` | 107 | 7.6s |  |
| 981 | `vector_enumeration` | 5 | 7.0s |  |
| 982 | `vector_every` | 92 | 7.9s |  |
| 983 | `vector_filter` | 95 | 7.9s |  |
| 984 | `vector_holes` | 24 | 7.1s |  |
| 985 | `vector_indexof` | 302 | 11.8s |  |
| 986 | `vector_insertat` | 270 | 8.2s |  |
| 987 | `vector_int_access` | 4 | 7.0s |  |
| 988 | `vector_int_delete` | 11 | 7.0s |  |
| 989 | `vector_join` | 58 | 7.4s |  |
| 990 | `vector_lastindexof` | 302 | 6.9s |  |
| 991 | `vector_legacy` | 10 | 7.1s |  |
| 992 | `vector_map` | 85 | 7.7s |  |
| 993 | `vector_object_final` | 1 | 6.8s |  |
| 994 | `vector_object_toString` | 10 | 6.9s |  |
| 995 | `vector_pushpop` | 255 | 8.3s |  |
| 996 | `vector_reborrow_bug` | 10 | 7.0s |  |
| 997 | `vector_removeat` | 172 | 25.1s |  |
| 998 | `vector_reverse` | 232 | 8.5s |  |
| 999 | `vector_shiftunshift` | 252 | 8.7s |  |
| 1000 | `vector_slice` | 331 | 9.2s |  |
| 1001 | `vector_sort` | 905 | 17.2s |  |
| 1002 | `vector_splice` | 693 | 11.6s |  |
| 1003 | `vector_splice_fixed_bug_compat` | 4 | 26.8s |  |
| 1004 | `vector_tostring` | 79 | 8.0s |  |
| 1005 | `verification` | 8 | 7.5s |  |
| 1006 | `verify_abnormal_loop` | 1 | 7.2s |  |
| 1007 | `verify_dxns_without_flag` | 3 | 7.7s |  |
| 1008 | `verify_exception_targets_edge_case` | 1 | 7.2s |  |
| 1009 | `verify_illegal_opcode` | 1 | 3.5s |  |
| 1010 | `verify_jump_to_middle_of_op` | 1 | 7.2s |  |
| 1011 | `verify_lookup_switch_edge_case` | 1 | 7.2s |  |
| 1012 | `verify_stack` | 5 | 7.4s |  |
| 1013 | `verify_unreachable_exception` | 2 | 7.3s |  |
| 1014 | `versioned_isplaying` | 2 | 7.3s |  |
| 1015 | `virtual_properties` | 16 | 7.4s |  |
| 1016 | `with` | 4 | 7.4s |  |
| 1017 | `wrong_arg_count` | 7 | 7.5s |  |
| 1018 | `xml_abstract_equality` | 36 | 7.6s |  |
| 1019 | `xml_advanced` | 52 | 7.4s |  |
| 1020 | `xml_appendchild` | 10 | 7.3s |  |
| 1021 | `xml_as_attribute` | 9 | 7.3s |  |
| 1022 | `xml_attribute` | 35 | 7.5s |  |
| 1023 | `xml_attribute_name` | 40 | 7.3s |  |
| 1024 | `xml_basic` | 33 | 7.4s |  |
| 1025 | `xml_child` | 25 | 7.4s |  |
| 1026 | `xml_childindex` | 7 | 7.3s |  |
| 1027 | `xml_children` | 43 | 7.9s |  |
| 1028 | `xml_class_call` | 9 | 7.3s |  |
| 1029 | `xml_contains` | 197 | 7.5s |  |
| 1030 | `xml_copy` | 20 | 3.2s |  |
| 1031 | `xml_ctor_from_tostring` | 23 | 24.4s |  |
| 1032 | `xml_delete` | 114 | 7.5s |  |
| 1033 | `xml_descendants` | 83 | 26.9s |  |
| 1034 | `xml_elements` | 6 | 7.4s |  |
| 1035 | `xml_equals_namespace_check` | 2 | 7.4s |  |
| 1036 | `xml_explicit_use_namespace` | 5 | 7.4s |  |
| 1037 | `xml_getdescendants_qname` | 21 | 7.4s |  |
| 1038 | `xml_has_property_via_in` | 26 | 7.4s |  |
| 1039 | `xml_hasownproperty` | 6 | 7.4s |  |
| 1040 | `xml_ignore_white` | 6 | 7.5s |  |
| 1041 | `xml_length` | 2 | 7.4s |  |
| 1042 | `xml_list_as_attribute` | 9 | 7.4s |  |
| 1043 | `xml_list_concat` | 20 | 7.4s |  |
| 1044 | `xml_list_enumerate` | 4 | 7.3s |  |
| 1045 | `xml_methods_settings` | 3 | 7.4s |  |
| 1046 | `xml_mismatched_tag` | 37 | 7.4s |  |
| 1047 | `xml_namespace` | 39 | 7.5s |  |
| 1048 | `xml_namespace_methods` | 245 | 7.5s |  |
| 1049 | `xml_namespaced_property` | 7 | 7.3s |  |
| 1050 | `xml_no_namespace` | 1 | 7.3s |  |
| 1051 | `xml_nodekind` | 3 | 7.3s |  |
| 1052 | `xml_normalize` | 35 | 7.5s |  |
| 1053 | `xml_notification_bubbling` | 361 | 7.4s |  |
| 1054 | `xml_parent` | 8 | 7.4s |  |
| 1055 | `xml_set_children` | 17 | 7.4s |  |
| 1056 | `xml_set_name` | 34 | 7.4s |  |
| 1057 | `xml_settings` | 6 | 3.1s |  |
| 1058 | `xml_simple_complex_content` | 47 | 7.4s |  |
| 1059 | `xml_socket` | 11 | 7.7s |  |
| 1060 | `xml_text` | 7 | 7.4s |  |
| 1061 | `xml_tostring` | 6 | 7.4s |  |
| 1062 | `xml_tostring_namespace` | 12 | 7.3s |  |
| 1063 | `xml_unescaping` | 23 | 7.4s |  |
| 1064 | `xml_weird_ignores` | 54 | 7.5s |  |
| 1065 | `xml_wildcard` | 11 | 7.4s |  |
| 1066 | `xmldocument` | 254 | 7.5s |  |
| 1067 | `xmlnode` | 3540 | 7.5s |  |
| 1068 | `zero_frame_clip` | 3 | 8.0s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 7.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 26.3s |  |
| 3 | `blend_transform` | 1 | 1 | 7.7s |  |
| 4 | `coerce_property` | 3 | 3 | 7.7s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 7.7s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 26.4s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.6s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 33.7s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.0s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 7.3s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 7.3s |  |
| 12 | `freestanding_superclass` | 2 | 4 | 7.1s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 25.6s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 26.5s |  |
| 15 | `int_toexponential` | 76 | 76 | 7.9s |  |
| 16 | `int_toprecision` | 441 | 441 | 7.9s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 7.8s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 7.4s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 27.8s |  |
| 20 | `soundchannel_position` | 74 | 74 | 28.2s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 7.9s |  |
| 22 | `sprite_dropTarget` | 15 | 15 | 7.7s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 26.6s |  |
| 24 | `uint_toexponential` | 100 | 100 | 7.3s |  |
| 25 | `uint_toprecision` | 433 | 433 | 7.5s |  |
| 26 | `uncaught_errors_stringified` | 15 | 15 | 7.4s |  |
| 27 | `weird_superinterface_properties` | 1 | 1 | 26.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**38 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 2 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 3 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 4 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 5 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 6 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 7 | `issue_8630_placeremoveplace_scriptremove` | 93.8% | 15 | 16 | 1 |  |
| 8 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 9 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 10 | `xml_appendchild_swf_v21` | 85.7% | 12 | 14 | 2 |  |
| 11 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 12 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 13 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 14 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 15 | `textblock_line_changes` | 79.1% | 125 | 158 | 33 |  |
| 16 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 17 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 18 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 19 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 20 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 21 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 22 | `rtqname_not_namespace` | 75.0% | 9 | 12 | 3 |  |
| 23 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 24 | `superinterface_call` | 75.0% | 15 | 20 | 5 |  |
| 25 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 26 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 27 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 28 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 29 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 30 | `displayobject_scrollrect` | 57.6% | 19 | 33 | 14 |  |
| 31 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 32 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 33 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 34 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 35 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 36 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 37 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 38 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `verify_typecheck` | exit code 1 | 7.2s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**128 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 2 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 3 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 4 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 5 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 6 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 7 | `issue_8630_placeremoveplace_scriptremove` | 93.8% | 15/16 | 16 | 16 |  |
| 8 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 9 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 10 | `xml_appendchild_swf_v21` | 85.7% | 12/14 | 14 | 13 |  |
| 11 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 12 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 13 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 14 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 15 | `textblock_line_changes` | 79.1% | 125/158 | 158 | 158 |  |
| 16 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 17 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 18 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 19 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 20 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 21 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 22 | `rtqname_not_namespace` | 75.0% | 9/12 | 10 | 12 |  |
| 23 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 24 | `superinterface_call` | 75.0% | 15/20 | 18 | 20 |  |
| 25 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 26 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 27 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 28 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 29 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 30 | `displayobject_scrollrect` | 57.6% | 19/33 | 33 | 33 |  |
| 31 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 32 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 33 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 34 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 35 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 36 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 37 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 38 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 39 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 40 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 41 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 42 | `bom` | 44.4% | 4/9 | 9 | 9 |  |
| 43 | `textblock_recreateline` | 40.8% | 40/98 | 89 | 98 |  |
| 44 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 45 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 46 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 47 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 48 | `geom_transform` | 27.0% | 20/74 | 26 | 74 |  |
| 49 | `superinterface_instanceof` | 22.2% | 4/18 | 18 | 18 |  |
| 50 | `property_is_enumerable` | 21.9% | 25/114 | 27 | 114 |  |
| 51 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 52 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 53 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 54 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 55 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 56 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 57 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 58 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 59 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 60 | `xml_list_delete_clear_parent` | 12.5% | 1/8 | 8 | 6 |  |
| 61 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 62 | `url_vars` | 11.1% | 3/27 | 5 | 27 |  |
| 63 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 64 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 65 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 66 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 67 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 68 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 69 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 70 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 71 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 72 | `escape_multi_byte` | 2.2% | 1/45 | 3 | 45 |  |
| 73 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 74 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 75 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 76 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 77 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 78 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 79 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 80 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 81 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 82 | `all_classes/events/swf9` | 0.2% | 2/1030 | 190 | 1030 |  |
| 83 | `all_classes/events/swf10` | 0.2% | 3/1638 | 190 | 1638 |  |
| 84 | `all_classes/events/swf11` | 0.2% | 3/1750 | 190 | 1750 |  |
| 85 | `all_classes/events/swf12` | 0.2% | 3/1814 | 190 | 1814 |  |
| 86 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 87 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 88 | `all_classes/events/swf30` | 0.0% | 1/2353 | 190 | 2353 |  |
| 89 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 90 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 91 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 92 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 93 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 94 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 95 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 96 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 97 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 98 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 99 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 100 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 101 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 102 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 103 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 104 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 105 | `avm1_root` | 0.0% | 0/58 | 6 | 58 |  |
| 106 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 107 | `currency_parse_result` | 0.0% | 0/7 | 2 | 7 |  |
| 108 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 109 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 110 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 111 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 112 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 113 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 114 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 115 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 116 | `netfilterevent` | 0.0% | 0/10 | 2 | 10 |  |
| 117 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 118 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 119 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 120 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 121 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 122 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 123 | `supercalls_weird` | 0.0% | 0/2 | 2 | 2 |  |
| 124 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 125 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
| 126 | `verify_exception_target_two_jumps` | 0.0% | 0/1 | 1 | 1 |  |
| 127 | `verify_method_info_duplicate` | 0.0% | 0/2 | 0 | 2 |  |
| 128 | `verify_method_info_oob` | 0.0% | 0/1 | 0 | 1 |  |
