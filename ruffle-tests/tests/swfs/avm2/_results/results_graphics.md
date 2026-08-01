# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-01 07:44 UTC

**Git SHA**: `07c119c505`

**Run Duration**: 200m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1224 |
| Passing | **1080** (88.2%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1107** (90.4%) |
| Failing | 117 |
| Total expected lines | 151515 |
| Matching lines | 118243 (78.0%) |
| Mismatched lines | 33272 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 117 | 100.0% |

## Passing Tests

**1080 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 27.0s |  |
| 2 | `accessibility` | 1 | 7.5s |  |
| 3 | `activation_class` | 6 | 7.4s |  |
| 4 | `add` | 1058 | 20.0s |  |
| 5 | `agal_compiler` | 13 | 10.0s |  |
| 6 | `air_datagram_socket` | 1 | 9.0s |  |
| 7 | `air_hidden_lookup` | 2 | 7.5s |  |
| 8 | `air_ifilepromise` | 1 | 7.5s |  |
| 9 | `all_classes/security/swf11` | 3 | 7.5s |  |
| 10 | `amf_array_serialization` | 17 | 9.3s |  |
| 11 | `amf_custom_obj` | 26 | 7.6s |  |
| 12 | `amf_dictionary` | 9 | 7.6s |  |
| 13 | `amf_function` | 46 | 7.3s |  |
| 14 | `amf_invalid_date` | 2 | 7.2s |  |
| 15 | `amf_missing_prop` | 6 | 7.5s |  |
| 16 | `amf_nondynamic_function_prop` | 6 | 7.5s |  |
| 17 | `amf_setter_error` | 8 | 7.6s |  |
| 18 | `amf_vector` | 40 | 7.6s |  |
| 19 | `amf_xml` | 6 | 7.4s |  |
| 20 | `application_domain` | 4 | 7.5s |  |
| 21 | `applicationdomain_getqualifieddefinitionnames` | 9 | 7.7s |  |
| 22 | `applicationdomain_hasdefinition_null` | 2 | 7.3s |  |
| 23 | `array_access` | 18 | 7.4s |  |
| 24 | `array_access_interpreter` | 4 | 7.4s |  |
| 25 | `array_access_no_pubns` | 2 | 7.3s |  |
| 26 | `array_concat` | 41 | 7.4s |  |
| 27 | `array_constr` | 10 | 7.4s |  |
| 28 | `array_delete` | 44 | 7.5s |  |
| 29 | `array_enumeration` | 10 | 7.4s |  |
| 30 | `array_enumeration_elements` | 11 | 7.3s |  |
| 31 | `array_every` | 8 | 7.4s |  |
| 32 | `array_filter` | 6 | 7.4s |  |
| 33 | `array_foreach` | 18 | 7.3s |  |
| 34 | `array_hasownproperty` | 11 | 3.2s |  |
| 35 | `array_holes` | 9 | 7.3s |  |
| 36 | `array_index_max` | 84 | 7.2s |  |
| 37 | `array_indexof` | 25 | 7.2s |  |
| 38 | `array_join` | 26 | 7.4s |  |
| 39 | `array_lastindexof` | 29 | 7.3s |  |
| 40 | `array_length` | 14 | 7.3s |  |
| 41 | `array_literal` | 3 | 7.3s |  |
| 42 | `array_map` | 8 | 3.1s |  |
| 43 | `array_pop` | 52 | 7.5s |  |
| 44 | `array_push` | 24 | 7.3s |  |
| 45 | `array_reborrow_bug` | 6 | 7.3s |  |
| 46 | `array_reverse` | 28 | 7.4s |  |
| 47 | `array_shift` | 51 | 3.3s |  |
| 48 | `array_slice` | 39 | 7.4s |  |
| 49 | `array_some` | 8 | 7.3s |  |
| 50 | `array_sort` | 297 | 7.8s |  |
| 51 | `array_sort_fun_swf12` | 2 | 7.3s |  |
| 52 | `array_sort_fun_swf13` | 2 | 1.3s |  |
| 53 | `array_sort_random` | 210 | 7.4s |  |
| 54 | `array_sort_swf10_32bit` | 1 | 7.3s |  |
| 55 | `array_sorton` | 545 | 8.4s |  |
| 56 | `array_sparse_ops` | 41 | 7.7s |  |
| 57 | `array_splice` | 133 | 7.9s |  |
| 58 | `array_splice2` | 428 | 8.0s |  |
| 59 | `array_splice_types` | 48 | 7.7s |  |
| 60 | `array_storage` | 8 | 7.7s |  |
| 61 | `array_tolocalestring` | 9 | 7.7s |  |
| 62 | `array_tostring` | 12 | 7.5s |  |
| 63 | `array_unshift` | 24 | 7.5s |  |
| 64 | `array_valueof` | 9 | 7.4s |  |
| 65 | `array_vector_null_callback` | 10 | 7.8s |  |
| 66 | `astype` | 28 | 7.9s |  |
| 67 | `astypelate` | 24 | 8.0s |  |
| 68 | `astypelate_propagates` | 1 | 7.9s |  |
| 69 | `asymmetric_key_events` | 11 | 7.7s |  |
| 70 | `av_networking_params` | 9 | 7.7s |  |
| 71 | `av_tag_data` | 2 | 7.7s |  |
| 72 | `avm2_catchup_dobj` | 158 | 8.7s |  |
| 73 | `away3d_advanced_shallow_water_demo` | 0 | 89.9s |  |
| 74 | `bevel_filter` | 187 | 7.8s |  |
| 75 | `bitand` | 1058 | 19.0s |  |
| 76 | `bitmap_constr` | 17 | 7.8s |  |
| 77 | `bitmap_data` | 1000 | 15.7s |  |
| 78 | `bitmap_pixelsnapping` | 2 | 27.7s |  |
| 79 | `bitmap_properties` | 23 | 7.7s |  |
| 80 | `bitmap_subclass` | 7 | 9.1s |  |
| 81 | `bitmap_subclass_properties` | 9 | 8.1s |  |
| 82 | `bitmap_timeline` | 9 | 7.7s |  |
| 83 | `bitmapdata_accuracy` | 1 | 49.8s |  |
| 84 | `bitmapdata_applyfilter_blur` | 0 | 28.5s |  |
| 85 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.6s |  |
| 86 | `bitmapdata_applyfilter_destpoint` | 0 | 28.2s |  |
| 87 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 27.5s |  |
| 88 | `bitmapdata_clone` | 13 | 7.8s |  |
| 89 | `bitmapdata_colortransform` | 0 | 8.1s |  |
| 90 | `bitmapdata_colortransform_oob` | 2 | 7.5s |  |
| 91 | `bitmapdata_constr` | 22 | 7.8s |  |
| 92 | `bitmapdata_constructor_from_timeline` | 1 | 8.0s |  |
| 93 | `bitmapdata_copychannel` | 0 | 21.1s |  |
| 94 | `bitmapdata_copypixels` | 23 | 19.8s |  |
| 95 | `bitmapdata_copypixels_blend_over` | 1 | 5.7s |  |
| 96 | `bitmapdata_copypixelstobytearray` | 39 | 5.0s |  |
| 97 | `bitmapdata_dispose` | 7 | 5.2s |  |
| 98 | `bitmapdata_draw` | 0 | 19.4s |  |
| 99 | `bitmapdata_draw_colortransform` | 0 | 5.3s |  |
| 100 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 20.3s |  |
| 101 | `bitmapdata_draw_filters` | 0 | 19.3s |  |
| 102 | `bitmapdata_draw_masks` | 0 | 5.3s |  |
| 103 | `bitmapdata_draw_rotation` | 0 | 5.2s |  |
| 104 | `bitmapdata_draw_self_via_graphic` | 0 | 5.6s |  |
| 105 | `bitmapdata_draw_stage` | 0 | 19.3s |  |
| 106 | `bitmapdata_drawwithquality` | 0 | 5.3s |  |
| 107 | `bitmapdata_embedded` | 9 | 5.6s |  |
| 108 | `bitmapdata_fillrect` | 0 | 5.3s |  |
| 109 | `bitmapdata_filter_sourcerect` | 0 | 20.1s |  |
| 110 | `bitmapdata_floodfill` | 35 | 5.1s |  |
| 111 | `bitmapdata_getpixels` | 39 | 18.9s |  |
| 112 | `bitmapdata_getvector` | 27 | 2.6s |  |
| 113 | `bitmapdata_histogram` | 59 | 2.0s |  |
| 114 | `bitmapdata_hittest` | 112 | 6.4s |  |
| 115 | `bitmapdata_hittest_threshold` | 18 | 6.0s |  |
| 116 | `bitmapdata_opaque` | 0 | 5.3s |  |
| 117 | `bitmapdata_pixeldissolve` | 1037 | 5.9s |  |
| 118 | `bitmapdata_pixeldissolve_image` | 0 | 5.3s |  |
| 119 | `bitmapdata_rectangle_rounding` | 16 | 5.4s |  |
| 120 | `bitmapdata_setpixels` | 286 | 5.8s |  |
| 121 | `bitmapdata_setvector` | 26 | 5.5s |  |
| 122 | `bitmapdata_sync` | 0 | 19.5s |  |
| 123 | `bitmapdata_threshold` | 176 | 5.8s |  |
| 124 | `bitmapdata_zero_size` | 8 | 5.6s |  |
| 125 | `bitnot` | 46 | 5.1s |  |
| 126 | `bitor` | 1058 | 12.8s |  |
| 127 | `bitxor` | 1058 | 12.9s |  |
| 128 | `blend_mode_null` | 1 | 5.4s |  |
| 129 | `blend_multiply_alpha` | 0 | 6.7s |  |
| 130 | `blend_scroll` | 0 | 5.5s |  |
| 131 | `blend_shader_luma_lighten` | 3 | 5.6s |  |
| 132 | `blur_filter` | 43 | 7.3s |  |
| 133 | `boolean_constr` | 32 | 7.3s |  |
| 134 | `boolean_negation` | 30 | 7.3s |  |
| 135 | `boolean_tostring` | 8 | 7.3s |  |
| 136 | `broadcast_event` | 7 | 7.4s |  |
| 137 | `button_bounds` | 1 | 7.3s |  |
| 138 | `button_hittest` | 2 | 26.0s |  |
| 139 | `button_nested_frame` | 48 | 26.8s |  |
| 140 | `bytearray` | 48 | 7.7s |  |
| 141 | `bytearray_compress` | 31 | 7.3s |  |
| 142 | `bytearray_errors` | 24 | 7.3s |  |
| 143 | `bytearray_method_serialization` | 1 | 7.1s |  |
| 144 | `bytearray_oom` | 3 | 7.2s |  |
| 145 | `bytearray_readobject_amf0` | 50 | 7.3s |  |
| 146 | `bytearray_readobject_amf3` | 53 | 7.2s |  |
| 147 | `bytearray_readutf8bytes_with_bom` | 16 | 7.2s |  |
| 148 | `bytearray_serialization` | 3 | 7.1s |  |
| 149 | `bytearray_string_null` | 19 | 7.3s |  |
| 150 | `bytearray_tostring` | 15 | 7.2s |  |
| 151 | `bytearray_utf16` | 8 | 7.2s |  |
| 152 | `bytearray_writeobject` | 24 | 7.0s |  |
| 153 | `callee_in_initializer` | 6 | 7.0s |  |
| 154 | `callproplex_class` | 1 | 7.0s |  |
| 155 | `capabilities_resolution` | 8 | 26.6s |  |
| 156 | `catch_class` | 6 | 7.1s |  |
| 157 | `catch_scope_slot` | 7 | 3.2s |  |
| 158 | `checkfilter` | 4 | 3.1s |  |
| 159 | `class_call` | 32 | 7.3s |  |
| 160 | `class_cast_call` | 14 | 7.1s |  |
| 161 | `class_enumeration` | 4 | 7.1s |  |
| 162 | `class_has_own_property` | 2 | 7.1s |  |
| 163 | `class_init_interpreter_mode` | 1 | 7.0s |  |
| 164 | `class_is` | 32 | 7.2s |  |
| 165 | `class_methods` | 5 | 7.1s |  |
| 166 | `class_object_properties` | 10 | 7.2s |  |
| 167 | `class_singleton` | 18 | 7.2s |  |
| 168 | `class_supercalls_errors` | 35 | 7.3s |  |
| 169 | `class_supercalls_mismatched` | 26 | 7.1s |  |
| 170 | `class_superclass_wrong_order` | 1 | 29.0s |  |
| 171 | `class_to_locale_string` | 2 | 8.0s |  |
| 172 | `class_to_string` | 2 | 7.9s |  |
| 173 | `class_value_of` | 2 | 7.9s |  |
| 174 | `click_block` | 5 | 8.9s |  |
| 175 | `click_invisible` | 3 | 8.0s |  |
| 176 | `closures` | 12 | 8.3s |  |
| 177 | `coerce_return_type` | 40 | 3.9s |  |
| 178 | `coerce_return_type_fail` | 2 | 8.2s |  |
| 179 | `coerce_return_void` | 3 | 8.0s |  |
| 180 | `coerce_string` | 86 | 8.5s |  |
| 181 | `coerce_string_precision` | 28 | 8.4s |  |
| 182 | `coerce_to_primitive_side_effects` | 29 | 29.1s |  |
| 183 | `color_matrix_filter` | 19 | 8.2s |  |
| 184 | `construct_errors_swf10` | 8 | 8.1s |  |
| 185 | `construct_frame_list` | 22 | 29.5s |  |
| 186 | `construct_interface` | 3 | 7.9s |  |
| 187 | `constructor_call` | 3 | 8.1s |  |
| 188 | `constructors_vs_timeline` | 5 | 29.6s |  |
| 189 | `constructprop_dynamic_primitive` | 7 | 8.2s |  |
| 190 | `constructprop_method` | 2 | 7.9s |  |
| 191 | `content_element_basic` | 50 | 8.3s |  |
| 192 | `context3d_creation` | 9 | 8.2s |  |
| 193 | `control_flow_bool` | 4 | 7.9s |  |
| 194 | `control_flow_stricteq` | 8 | 8.0s |  |
| 195 | `convert_boolean` | 30 | 8.2s |  |
| 196 | `convert_integer` | 90 | 8.1s |  |
| 197 | `convert_number` | 56 | 3.6s |  |
| 198 | `convert_uinteger` | 90 | 8.2s |  |
| 199 | `convolution_filter` | 89 | 8.1s |  |
| 200 | `core_exceptions` | 47 | 9.1s |  |
| 201 | `cpool_index_invalid_bytecode_1` | 6 | 8.0s |  |
| 202 | `cpool_index_invalid_bytecode_2` | 3 | 8.1s |  |
| 203 | `cpool_index_invalid_bytecode_3` | 1 | 7.9s |  |
| 204 | `cross_api_version_call_older` | 12 | 8.4s |  |
| 205 | `cryptscore` | 11 | 8.1s |  |
| 206 | `date` | 30 | 7.4s |  |
| 207 | `date_parse` | 36 | 7.0s |  |
| 208 | `declocal` | 46 | 3.0s |  |
| 209 | `declocal_i` | 46 | 7.1s |  |
| 210 | `decode_uri` | 71 | 7.3s |  |
| 211 | `decrement` | 46 | 7.1s |  |
| 212 | `decrement_i` | 46 | 3.1s |  |
| 213 | `default_values` | 7 | 7.0s |  |
| 214 | `dictionary_access` | 62 | 7.2s |  |
| 215 | `dictionary_access_no_pubns` | 2 | 7.0s |  |
| 216 | `dictionary_delete` | 101 | 7.4s |  |
| 217 | `dictionary_foreach` | 42 | 7.2s |  |
| 218 | `dictionary_hasownproperty` | 63 | 7.3s |  |
| 219 | `dictionary_in` | 62 | 7.3s |  |
| 220 | `dictionary_iter_modify` | 8 | 7.0s |  |
| 221 | `dictionary_namespaces` | 36 | 7.2s |  |
| 222 | `dictionary_primitive_keys` | 29 | 7.1s |  |
| 223 | `displacement_map_filter` | 61 | 7.2s |  |
| 224 | `displayobject_alpha` | 277 | 7.0s |  |
| 225 | `displayobject_blendmode` | 0 | 7.1s |  |
| 226 | `displayobject_colortransform_nested` | 0 | 25.3s |  |
| 227 | `displayobject_filters` | 17 | 7.1s |  |
| 228 | `displayobject_from_enterframe` | 1 | 25.4s |  |
| 229 | `displayobject_getbounds_shape` | 0 | 25.5s |  |
| 230 | `displayobject_height` | 6052 | 25.3s |  |
| 231 | `displayobject_hittestobject` | 32 | 7.1s |  |
| 232 | `displayobject_hittestpoint` | 49 | 7.1s |  |
| 233 | `displayobject_hittestpoint_root` | 13 | 7.3s |  |
| 234 | `displayobject_invalid_floats` | 60 | 7.1s |  |
| 235 | `displayobject_invalid_props` | 3 | 7.0s |  |
| 236 | `displayobject_mask` | 3 | 7.4s |  |
| 237 | `displayobject_mask_self_referential` | 0 | 21.6s |  |
| 238 | `displayobject_metaData` | 3 | 6.0s |  |
| 239 | `displayobject_name` | 22 | 21.4s |  |
| 240 | `displayobject_name_from_timeline` | 24 | 6.2s |  |
| 241 | `displayobject_opaque_background` | 6 | 21.5s |  |
| 242 | `displayobject_parent` | 12 | 6.1s |  |
| 243 | `displayobject_root` | 24 | 6.0s |  |
| 244 | `displayobject_rotation` | 1284 | 6.1s |  |
| 245 | `displayobject_set_matrix_nested` | 0 | 21.6s |  |
| 246 | `displayobject_set_name_loaded` | 3 | 6.3s |  |
| 247 | `displayobject_subclass` | 2 | 6.0s |  |
| 248 | `displayobject_visible` | 23 | 6.0s |  |
| 249 | `displayobject_width` | 4852 | 21.7s |  |
| 250 | `displayobject_x` | 614 | 6.0s |  |
| 251 | `displayobject_y` | 617 | 6.0s |  |
| 252 | `displayobjectcontainer_addchild` | 32 | 6.1s |  |
| 253 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.0s |  |
| 254 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.2s |  |
| 255 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.1s |  |
| 256 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.1s |  |
| 257 | `displayobjectcontainer_addchildat` | 42 | 6.0s |  |
| 258 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.1s |  |
| 259 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.1s |  |
| 260 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.1s |  |
| 261 | `displayobjectcontainer_contains` | 66 | 21.6s |  |
| 262 | `displayobjectcontainer_getchildat` | 4 | 6.0s |  |
| 263 | `displayobjectcontainer_getchildbyname` | 9 | 5.9s |  |
| 264 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.0s |  |
| 265 | `displayobjectcontainer_getchildindex` | 28 | 6.0s |  |
| 266 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 6.0s |  |
| 267 | `displayobjectcontainer_removechild` | 10 | 5.9s |  |
| 268 | `displayobjectcontainer_removechild_errors` | 4 | 5.9s |  |
| 269 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.0s |  |
| 270 | `displayobjectcontainer_removechildat` | 18 | 5.9s |  |
| 271 | `displayobjectcontainer_removechildren` | 51 | 6.2s |  |
| 272 | `displayobjectcontainer_setchildindex` | 42 | 5.9s |  |
| 273 | `displayobjectcontainer_stopallmovieclips` | 2 | 21.6s |  |
| 274 | `displayobjectcontainer_swapchildren` | 42 | 6.0s |  |
| 275 | `displayobjectcontainer_swapchildrenat` | 42 | 6.0s |  |
| 276 | `displayobjectcontainer_timelineinstance` | 48 | 28.3s |  |
| 277 | `divide` | 1058 | 20.2s |  |
| 278 | `doabc_is_eager` | 1 | 26.8s |  |
| 279 | `documentclass` | 9 | 7.5s |  |
| 280 | `domain_memory` | 133 | 28.1s |  |
| 281 | `drag_drop` | 10 | 7.4s |  |
| 282 | `drop_shadow_filter` | 172 | 7.6s |  |
| 283 | `duplicate_defs` | 1 | 7.3s |  |
| 284 | `eager_init` | 1 | 7.4s |  |
| 285 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 286 | `edit_text_linkage` | 7 | 7.6s |  |
| 287 | `edittext_align` | 60 | 7.8s |  |
| 288 | `edittext_always_show_selection` | 0 | 26.9s |  |
| 289 | `edittext_antialiastype` | 296 | 7.7s |  |
| 290 | `edittext_at_point_methods_basic` | 16 | 8.6s |  |
| 291 | `edittext_autosize` | 39 | 7.8s |  |
| 292 | `edittext_autosize_align` | 0 | 27.6s |  |
| 293 | `edittext_autosize_height_dynamic` | 60 | 27.7s |  |
| 294 | `edittext_autosize_height_input` | 60 | 7.6s |  |
| 295 | `edittext_autosize_lazy_bounds_events` | 65 | 7.6s |  |
| 296 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.6s |  |
| 297 | `edittext_autosize_lazy_bounds_props` | 490 | 9.0s |  |
| 298 | `edittext_autosize_lazy_bounds_visual` | 0 | 27.3s |  |
| 299 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.6s |  |
| 300 | `edittext_bottom_scroll_v_basic` | 210 | 7.5s |  |
| 301 | `edittext_bounds_scale` | 24 | 26.6s |  |
| 302 | `edittext_bullet` | 30 | 7.5s |  |
| 303 | `edittext_default_format` | 221 | 7.8s |  |
| 304 | `edittext_default_format_empty` | 136 | 7.8s |  |
| 305 | `edittext_empty_text_format` | 7 | 7.6s |  |
| 306 | `edittext_focus_selection` | 5 | 7.4s |  |
| 307 | `edittext_font_size` | 45 | 7.5s |  |
| 308 | `edittext_format_empty_font` | 8 | 3.2s |  |
| 309 | `edittext_get_char_index_at_point` | 4 | 29.3s |  |
| 310 | `edittext_get_line_index_at_point` | 2 | 27.1s |  |
| 311 | `edittext_get_line_index_of_char` | 76 | 8.4s |  |
| 312 | `edittext_getcharboundaries` | 172 | 7.9s |  |
| 313 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.7s |  |
| 314 | `edittext_getcharboundaries_scroll` | 85 | 26.8s |  |
| 315 | `edittext_getlinemetrics` | 146 | 7.8s |  |
| 316 | `edittext_html` | 3101 | 8.1s |  |
| 317 | `edittext_html_condensewhite` | 487 | 7.7s |  |
| 318 | `edittext_html_entity` | 4 | 8.0s |  |
| 319 | `edittext_html_font_size_swf12` | 267 | 7.7s |  |
| 320 | `edittext_html_font_size_swf13` | 273 | 7.4s |  |
| 321 | `edittext_html_roundtrip` | 17 | 7.7s |  |
| 322 | `edittext_ime_focus_lost` | 9 | 26.9s |  |
| 323 | `edittext_input_control` | 12 | 7.5s |  |
| 324 | `edittext_leading` | 9 | 7.8s |  |
| 325 | `edittext_letter_spacing` | 15 | 7.5s |  |
| 326 | `edittext_line_methods` | 294 | 8.9s |  |
| 327 | `edittext_line_metrics` | 11 | 28.2s |  |
| 328 | `edittext_margins` | 25 | 7.7s |  |
| 329 | `edittext_max_scroll_h_basic` | 475 | 7.7s |  |
| 330 | `edittext_max_scroll_v_basic` | 1000 | 7.6s |  |
| 331 | `edittext_mouse_selection` | 363 | 28.5s |  |
| 332 | `edittext_mousedown` | 3 | 7.9s |  |
| 333 | `edittext_mouseenabled` | 26 | 7.5s |  |
| 334 | `edittext_newline_character` | 22 | 7.6s |  |
| 335 | `edittext_newline_stripping` | 64 | 10.3s |  |
| 336 | `edittext_newlines` | 30 | 7.7s |  |
| 337 | `edittext_paragraph_methods` | 257 | 7.8s |  |
| 338 | `edittext_paste_events` | 8 | 7.7s |  |
| 339 | `edittext_paste_maxchars` | 4 | 7.6s |  |
| 340 | `edittext_paste_restrict` | 16 | 7.5s |  |
| 341 | `edittext_restrict` | 191 | 7.6s |  |
| 342 | `edittext_restrict_events` | 22 | 7.7s |  |
| 343 | `edittext_scrollh` | 10 | 3.4s |  |
| 344 | `edittext_selected_text` | 9 | 7.6s |  |
| 345 | `edittext_set_html_same` | 17 | 7.6s |  |
| 346 | `edittext_set_text_vs_html` | 9 | 7.5s |  |
| 347 | `edittext_stylesheet` | 536 | 7.8s |  |
| 348 | `edittext_stylesheet_custom_tag` | 76 | 7.6s |  |
| 349 | `edittext_stylesheet_display` | 272 | 7.6s |  |
| 350 | `edittext_underline` | 40 | 7.6s |  |
| 351 | `edittext_width_height` | 103 | 7.8s |  |
| 352 | `edittext_wordwrap_word` | 150 | 27.1s |  |
| 353 | `edittext_wrap_breaks` | 2375 | 8.0s |  |
| 354 | `element_format_clone` | 44 | 7.4s |  |
| 355 | `element_format_constructor_order` | 64 | 7.5s |  |
| 356 | `element_format_properties` | 235 | 8.3s |  |
| 357 | `empty_bounds` | 1 | 7.3s |  |
| 358 | `encode_uri_surrogate_pair_invalid` | 8 | 7.4s |  |
| 359 | `encode_uri_surrogate_pair_swf11` | 15 | 2.9s |  |
| 360 | `equals` | 512 | 11.6s |  |
| 361 | `error_geterrormessage` | 779 | 7.3s |  |
| 362 | `error_prototype` | 15 | 7.4s |  |
| 363 | `error_stack_trace_debug_swf17` | 0 | 26.6s |  |
| 364 | `error_stack_trace_debug_swf18` | 0 | 7.1s |  |
| 365 | `error_stack_trace_release_swf17` | 0 | 7.2s |  |
| 366 | `error_stack_trace_release_swf18` | 0 | 7.1s |  |
| 367 | `error_tostring` | 29 | 7.4s |  |
| 368 | `error_tostring_more` | 86 | 7.6s |  |
| 369 | `es3_inheritance` | 31 | 7.5s |  |
| 370 | `es4_inheritance` | 30 | 7.6s |  |
| 371 | `es4_interfaces` | 30 | 7.6s |  |
| 372 | `es4_method_binding` | 8 | 3.3s |  |
| 373 | `es4_oop_prototypes` | 14 | 7.7s |  |
| 374 | `es4_protected_inheritance` | 6 | 7.6s |  |
| 375 | `escape` | 71 | 7.7s |  |
| 376 | `escape_multi_byte` | 45 | 7.8s |  |
| 377 | `event_bubbles` | 2 | 7.6s |  |
| 378 | `event_cancelable` | 2 | 7.4s |  |
| 379 | `event_clone` | 20 | 7.4s |  |
| 380 | `event_clone_error_redispatch` | 3 | 7.6s |  |
| 381 | `event_clone_on_redispatch` | 10 | 7.5s |  |
| 382 | `event_formattostring` | 31 | 7.5s |  |
| 383 | `event_isdefaultprevented` | 12 | 7.6s |  |
| 384 | `event_target_getter` | 5 | 3.3s |  |
| 385 | `event_target_set` | 9 | 7.4s |  |
| 386 | `event_type` | 1 | 7.2s |  |
| 387 | `event_valueof_tostring` | 18 | 7.3s |  |
| 388 | `eventdispatcher_dispatchevent` | 12 | 7.2s |  |
| 389 | `eventdispatcher_dispatchevent_cancel` | 20 | 26.5s |  |
| 390 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.2s |  |
| 391 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.3s |  |
| 392 | `eventdispatcher_dispatchevent_this` | 5 | 7.1s |  |
| 393 | `eventdispatcher_haseventlistener` | 25 | 7.2s |  |
| 394 | `eventdispatcher_interface_invoke` | 1 | 7.2s |  |
| 395 | `eventdispatcher_tostring` | 10 | 7.3s |  |
| 396 | `eventdispatcher_willtrigger` | 25 | 7.1s |  |
| 397 | `falsiness` | 30 | 7.2s |  |
| 398 | `fast_index_access` | 12 | 7.3s |  |
| 399 | `filefilter_properties` | 4 | 7.1s |  |
| 400 | `filereference_browse_cancel` | 3 | 7.2s |  |
| 401 | `filereference_browse_select` | 9 | 3.1s |  |
| 402 | `filereference_load` | 31 | 7.2s |  |
| 403 | `filereference_save` | 16 | 7.2s |  |
| 404 | `filereference_save_and_browse` | 42 | 7.2s |  |
| 405 | `filereference_save_and_load` | 22 | 7.2s |  |
| 406 | `filereference_uninitialized` | 8 | 7.1s |  |
| 407 | `filereferencelist_browse_cancel` | 6 | 3.1s |  |
| 408 | `filereferencelist_browse_select` | 7 | 7.2s |  |
| 409 | `filter_rewind` | 8 | 7.3s |  |
| 410 | `filters_array_holes` | 25 | 7.3s |  |
| 411 | `finddef` | 3 | 7.2s |  |
| 412 | `findprop_global_prototype` | 6 | 7.3s |  |
| 413 | `flash_media_video_constructor` | 156 | 8.1s |  |
| 414 | `flash_media_video_rotation_probe` | 27 | 7.4s |  |
| 415 | `flash_media_video_setter` | 40 | 7.8s |  |
| 416 | `flash_xml` | 29 | 7.3s |  |
| 417 | `flash_xml_cloneNode` | 22 | 7.2s |  |
| 418 | `flash_xml_namespace` | 109 | 7.2s |  |
| 419 | `flash_xml_removeNode` | 60 | 7.2s |  |
| 420 | `focus_events_code` | 161 | 26.0s |  |
| 421 | `focus_events_key_basic` | 132 | 26.4s |  |
| 422 | `focus_events_key_navigation` | 53 | 7.4s |  |
| 423 | `focus_events_key_same_object` | 26 | 7.3s |  |
| 424 | `focus_events_mixed_key_mouse` | 100 | 26.3s |  |
| 425 | `focus_events_mouse_basic` | 260 | 26.4s |  |
| 426 | `focus_events_mouse_focusable` | 112 | 26.4s |  |
| 427 | `focus_events_mouse_same_object` | 40 | 26.1s |  |
| 428 | `focus_remove` | 20 | 25.9s |  |
| 429 | `focus_root_movie` | 4 | 26.0s |  |
| 430 | `focus_stage` | 1 | 7.2s |  |
| 431 | `focusrect` | 18 | 7.9s |  |
| 432 | `focusrect_focuslost` | 9 | 7.3s |  |
| 433 | `focusrect_property` | 110 | 26.0s |  |
| 434 | `font_description_clone` | 14 | 7.2s |  |
| 435 | `font_embedded` | 24 | 7.6s |  |
| 436 | `font_enumeratefonts` | 41 | 7.8s |  |
| 437 | `font_enumeratefonts_filter` | 4 | 26.3s |  |
| 438 | `font_enumeratefonts_order` | 9 | 8.5s |  |
| 439 | `font_hasglyphs` | 40 | 7.6s |  |
| 440 | `font_registerfont` | 129 | 8.0s |  |
| 441 | `framelabel_constr` | 5 | 7.2s |  |
| 442 | `function_call` | 12 | 7.2s |  |
| 443 | `function_call_arguments` | 46 | 7.3s |  |
| 444 | `function_call_arguments_enumerate` | 5 | 7.2s |  |
| 445 | `function_call_coercion` | 108 | 7.6s |  |
| 446 | `function_call_default` | 6 | 7.2s |  |
| 447 | `function_call_rest` | 22 | 7.2s |  |
| 448 | `function_call_types` | 3 | 7.2s |  |
| 449 | `function_call_via_apply` | 11 | 7.2s |  |
| 450 | `function_call_via_call` | 3 | 7.2s |  |
| 451 | `function_display_anonymous` | 7 | 3.1s |  |
| 452 | `function_length` | 6 | 7.2s |  |
| 453 | `function_object` | 2 | 7.2s |  |
| 454 | `function_proto` | 5 | 7.1s |  |
| 455 | `function_proto_created` | 61 | 7.2s |  |
| 456 | `function_to_locale_string` | 4 | 7.2s |  |
| 457 | `function_to_string` | 4 | 7.0s |  |
| 458 | `function_type` | 6 | 7.2s |  |
| 459 | `function_unbound_this` | 51 | 7.3s |  |
| 460 | `function_value_of` | 4 | 3.1s |  |
| 461 | `game_input` | 4 | 7.2s |  |
| 462 | `generate_random_bytes` | 3 | 7.2s |  |
| 463 | `get_definition_by_name` | 11 | 7.2s |  |
| 464 | `get_qualified_class_name` | 20 | 7.5s |  |
| 465 | `get_qualified_super_class_name` | 18 | 7.4s |  |
| 466 | `get_slot_edge_cases` | 1 | 26.4s |  |
| 467 | `get_timer` | 2 | 7.3s |  |
| 468 | `getglobalslot` | 1 | 7.2s |  |
| 469 | `getouterscope` | 8 | 7.2s |  |
| 470 | `getouterscope_two_classobjects` | 13 | 7.3s |  |
| 471 | `getter_different_namespace_setter` | 2 | 7.1s |  |
| 472 | `glow_filter` | 127 | 7.5s |  |
| 473 | `goto_button_nested_framescript` | 28 | 26.7s |  |
| 474 | `goto_in_constructframe` | 12 | 26.5s |  |
| 475 | `goto_in_scene_last_frame` | 2 | 26.2s |  |
| 476 | `goto_methods` | 56 | 7.6s |  |
| 477 | `goto_methods_swfver10` | 8 | 7.3s |  |
| 478 | `goto_nested_construct_sibling` | 18 | 7.7s |  |
| 479 | `goto_nested_framescript` | 9 | 7.5s |  |
| 480 | `goto_on_orphan` | 15 | 7.5s |  |
| 481 | `gradient_bevel_filter` | 206 | 7.5s |  |
| 482 | `gradient_glow_filter` | 206 | 7.2s |  |
| 483 | `graphics_bad_direct_commands` | 5 | 8.1s |  |
| 484 | `graphics_bitmap_fill` | 0 | 28.3s |  |
| 485 | `graphics_bitmaps` | 0 | 8.0s |  |
| 486 | `graphics_direct_commands` | 0 | 7.9s |  |
| 487 | `graphics_draw_triangles` | 98 | 29.9s |  |
| 488 | `graphics_gradients` | 0 | 8.1s |  |
| 489 | `graphics_gradients_nulls` | 0 | 7.5s |  |
| 490 | `graphics_path` | 56 | 7.4s |  |
| 491 | `graphics_round_rects` | 0 | 7.4s |  |
| 492 | `graphics_simple_shapes` | 0 | 7.8s |  |
| 493 | `greaterequals` | 512 | 11.7s |  |
| 494 | `greaterthan` | 512 | 11.6s |  |
| 495 | `has_own_property` | 102 | 8.0s |  |
| 496 | `hasownproperty_namespaces` | 2 | 7.4s |  |
| 497 | `hello_world` | 1 | 7.3s |  |
| 498 | `hittest_morph` | 30 | 7.5s |  |
| 499 | `if_eq` | 10 | 7.4s |  |
| 500 | `if_gt` | 1 | 7.5s |  |
| 501 | `if_gte` | 10 | 6.0s |  |
| 502 | `if_lt` | 1 | 5.0s |  |
| 503 | `if_lte` | 10 | 4.9s |  |
| 504 | `if_ne` | 7 | 2.0s |  |
| 505 | `if_stricteq` | 6 | 5.0s |  |
| 506 | `if_strictne` | 11 | 4.9s |  |
| 507 | `ime_linux_dead_keys` | 10 | 18.6s |  |
| 508 | `in` | 102 | 5.5s |  |
| 509 | `inclocal` | 46 | 2.2s |  |
| 510 | `inclocal_i` | 46 | 5.0s |  |
| 511 | `increment` | 46 | 5.3s |  |
| 512 | `increment_i` | 46 | 5.5s |  |
| 513 | `indexing_delete` | 75 | 6.0s |  |
| 514 | `instanceof` | 58 | 6.0s |  |
| 515 | `instantiate_root_character` | 4 | 5.2s |  |
| 516 | `instantiation_on_enter_frame` | 7 | 18.8s |  |
| 517 | `instantiation_on_enterframe_gotoandstop` | 8 | 5.0s |  |
| 518 | `int_constr` | 92 | 5.3s |  |
| 519 | `int_edge_cases` | 19 | 5.2s |  |
| 520 | `int_instanceof` | 3 | 5.2s |  |
| 521 | `int_tofixed` | 1215 | 5.2s |  |
| 522 | `int_tostring` | 3375 | 5.3s |  |
| 523 | `interactiveobject_enabled` | 25 | 5.2s |  |
| 524 | `interface_namespaces` | 78 | 5.6s |  |
| 525 | `invalid_utf8` | 12 | 5.3s |  |
| 526 | `is_finite` | 46 | 5.4s |  |
| 527 | `is_nan` | 46 | 4.9s |  |
| 528 | `is_prototype_of` | 12 | 5.3s |  |
| 529 | `issue_10221` | 2 | 5.4s |  |
| 530 | `issue_13780` | 12 | 4.8s |  |
| 531 | `issue_14901` | 1 | 5.2s |  |
| 532 | `issue_17675_edittext_paste_maxchars` | 1 | 6.2s |  |
| 533 | `issue_5292` | 5 | 5.2s |  |
| 534 | `issue_8630` | 2 | 18.5s |  |
| 535 | `issue_8630_placeremoveplace` | 15 | 5.0s |  |
| 536 | `issue_8630_placeremoveplace_scriptremove` | 16 | 5.2s |  |
| 537 | `issue_8630_scriptremove` | 11 | 5.6s |  |
| 538 | `istype` | 24 | 2.4s |  |
| 539 | `istypelate` | 58 | 5.5s |  |
| 540 | `istypelate_coerce` | 198 | 8.4s |  |
| 541 | `jpeg_loader_context` | 6 | 22.3s |  |
| 542 | `json_errors` | 9 | 26.1s |  |
| 543 | `json_parse` | 21 | 3.1s |  |
| 544 | `json_stringify` | 12 | 7.4s |  |
| 545 | `json_stringify_order` | 1 | 7.1s |  |
| 546 | `json_version_gated` | 1 | 7.2s |  |
| 547 | `key_input_80percent` | 1812 | 7.2s |  |
| 548 | `key_input_location` | 126 | 7.2s |  |
| 549 | `key_input_numpad` | 384 | 7.0s |  |
| 550 | `lazyinit` | 17 | 7.2s |  |
| 551 | `lessequals` | 512 | 11.3s |  |
| 552 | `lessthan` | 512 | 11.2s |  |
| 553 | `loader_bitmap_transparency` | 14 | 7.3s |  |
| 554 | `loader_bytes_unknown_content` | 14 | 7.3s |  |
| 555 | `loader_child_getdefinition` | 5 | 7.4s |  |
| 556 | `loader_duplicate_coerce` | 3 | 7.4s |  |
| 557 | `loader_duplicate_coerce_new_domain` | 4 | 7.3s |  |
| 558 | `loader_error_in_root_ctor` | 4 | 7.5s |  |
| 559 | `loader_events` | 92 | 8.0s |  |
| 560 | `loader_image` | 8 | 7.6s |  |
| 561 | `loader_jpegxr` | 2 | 27.0s |  |
| 562 | `loader_jpegxr_alpha` | 1 | 28.4s |  |
| 563 | `loader_loadbytes_events` | 30 | 8.0s |  |
| 564 | `loader_loadbytes_invalid_png` | 4 | 25.9s |  |
| 565 | `loader_loadbytes_url` | 12 | 7.5s |  |
| 566 | `loader_loaderurl` | 6 | 7.6s |  |
| 567 | `loader_method` | 85 | 7.3s |  |
| 568 | `loader_noninteractive_try_click_root` | 5 | 26.5s |  |
| 569 | `loader_reuse` | 38 | 7.4s |  |
| 570 | `loader_unknown_content` | 24 | 7.3s |  |
| 571 | `loader_visibility_interactive` | 1 | 7.3s |  |
| 572 | `loaderinfo_events` | 7 | 7.2s |  |
| 573 | `loaderinfo_loadurl` | 12 | 20.9s |  |
| 574 | `loaderinfo_more` | 6 | 21.5s |  |
| 575 | `loaderinfo_properties` | 18 | 6.0s |  |
| 576 | `loaderinfo_properties_not_loaded` | 23 | 6.0s |  |
| 577 | `loaderinfo_root` | 10 | 5.8s |  |
| 578 | `loaderinfo_root_allows` | 2 | 5.8s |  |
| 579 | `localconnection_send` | 4 | 5.8s |  |
| 580 | `lshift` | 1058 | 14.8s |  |
| 581 | `mask_reapply` | 1 | 5.8s |  |
| 582 | `math` | 497 | 5.9s |  |
| 583 | `matrix3d` | 57 | 6.3s |  |
| 584 | `matrix3d_compose` | 34 | 5.9s |  |
| 585 | `matrix3d_invert` | 18 | 5.8s |  |
| 586 | `method_without_body` | 3 | 20.4s |  |
| 587 | `missing_external_interface` | 10 | 5.9s |  |
| 588 | `modulo` | 1058 | 14.7s |  |
| 589 | `morph_shape` | 2 | 20.6s |  |
| 590 | `mouse_children` | 192 | 20.9s |  |
| 591 | `mouse_click_events` | 90 | 20.5s |  |
| 592 | `mouse_double_click_events` | 188 | 5.8s |  |
| 593 | `mouse_empty_parent` | 4 | 5.8s |  |
| 594 | `mouse_over_while_dragging` | 3 | 5.8s |  |
| 595 | `mouse_pick_button_mode` | 2 | 5.9s |  |
| 596 | `mouse_pick_dobj_mask` | 4 | 6.3s |  |
| 597 | `mouse_pick_masking` | 7 | 21.2s |  |
| 598 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 20.8s |  |
| 599 | `mouse_pick_non_interactive_dobj_mask` | 3 | 6.5s |  |
| 600 | `mouse_pick_text` | 8 | 6.0s |  |
| 601 | `mouse_sibling` | 8 | 5.9s |  |
| 602 | `mouse_wheel_events` | 36 | 21.8s |  |
| 603 | `mouseevent_constr` | 66 | 5.8s |  |
| 604 | `mouseevent_stagexy` | 35 | 5.8s |  |
| 605 | `mouseevent_valueof_tostring` | 28 | 6.0s |  |
| 606 | `movieclip_addframescript` | 3 | 21.2s |  |
| 607 | `movieclip_child_property` | 16 | 5.9s |  |
| 608 | `movieclip_constr` | 21 | 6.0s |  |
| 609 | `movieclip_currentlabels` | 17 | 22.6s |  |
| 610 | `movieclip_currentlabels_dupes1` | 46 | 22.7s |  |
| 611 | `movieclip_currentlabels_dupes2` | 30 | 6.0s |  |
| 612 | `movieclip_currentlabels_dupes3` | 67 | 6.1s |  |
| 613 | `movieclip_currentscene` | 12 | 22.1s |  |
| 614 | `movieclip_dispatchevent` | 430 | 6.0s |  |
| 615 | `movieclip_dispatchevent_cancel` | 102 | 6.0s |  |
| 616 | `movieclip_dispatchevent_handlerorder` | 251 | 6.1s |  |
| 617 | `movieclip_dispatchevent_selfadd` | 80 | 6.0s |  |
| 618 | `movieclip_dispatchevent_target` | 899 | 6.0s |  |
| 619 | `movieclip_displayevents` | 96 | 22.3s |  |
| 620 | `movieclip_displayevents_clickgoto` | 676 | 22.7s |  |
| 621 | `movieclip_displayevents_clickgoto2` | 2001 | 6.4s |  |
| 622 | `movieclip_displayevents_clickplay` | 575 | 6.1s |  |
| 623 | `movieclip_displayevents_clicksymbol` | 562 | 2.5s |  |
| 624 | `movieclip_displayevents_constructframegoto` | 140 | 6.6s |  |
| 625 | `movieclip_displayevents_constructframeplay` | 50 | 6.2s |  |
| 626 | `movieclip_displayevents_constructframesymbol` | 144 | 6.1s |  |
| 627 | `movieclip_displayevents_dblhandler` | 21 | 5.9s |  |
| 628 | `movieclip_displayevents_enterframegoto` | 149 | 6.2s |  |
| 629 | `movieclip_displayevents_enterframeplay` | 48 | 6.0s |  |
| 630 | `movieclip_displayevents_enterframesymbol` | 149 | 22.3s |  |
| 631 | `movieclip_displayevents_exitframegoto` | 106 | 6.1s |  |
| 632 | `movieclip_displayevents_exitframeplay` | 44 | 6.0s |  |
| 633 | `movieclip_displayevents_exitframesymbol` | 135 | 6.1s |  |
| 634 | `movieclip_displayevents_looping` | 63 | 22.5s |  |
| 635 | `movieclip_displayevents_stopped` | 113 | 6.2s |  |
| 636 | `movieclip_displayevents_swap` | 96 | 2.3s |  |
| 637 | `movieclip_displayevents_timeline` | 128 | 22.4s |  |
| 638 | `movieclip_drawrect` | 54 | 5.9s |  |
| 639 | `movieclip_frameconstruct_skipped` | 9 | 6.0s |  |
| 640 | `movieclip_goto_during_frame_script` | 15 | 6.0s |  |
| 641 | `movieclip_goto_overwrite` | 14 | 22.0s |  |
| 642 | `movieclip_goto_scene_last_frame_int` | 1 | 22.0s |  |
| 643 | `movieclip_goto_scene_last_frame_label` | 1 | 2.3s |  |
| 644 | `movieclip_gotoandplay` | 15 | 21.9s |  |
| 645 | `movieclip_gotoandstop` | 13 | 21.7s |  |
| 646 | `movieclip_gotoandstop_children` | 4 | 6.0s |  |
| 647 | `movieclip_gotoandstop_framescripts1` | 4 | 5.9s |  |
| 648 | `movieclip_gotoandstop_framescripts2` | 4 | 2.3s |  |
| 649 | `movieclip_gotoandstop_framescripts_self` | 7 | 30.1s |  |
| 650 | `movieclip_gotoandstop_queueing` | 12 | 29.8s |  |
| 651 | `movieclip_hittest` | 67 | 8.4s |  |
| 652 | `movieclip_next_frame` | 2 | 29.9s |  |
| 653 | `movieclip_next_scene` | 6 | 29.6s |  |
| 654 | `movieclip_play` | 3 | 8.0s |  |
| 655 | `movieclip_prev_frame` | 3 | 7.9s |  |
| 656 | `movieclip_prev_scene` | 7 | 8.1s |  |
| 657 | `movieclip_properties` | 79 | 29.7s |  |
| 658 | `movieclip_queued_noop_goto_swf10` | 9 | 8.1s |  |
| 659 | `movieclip_queued_noop_goto_swf9` | 7 | 1.5s |  |
| 660 | `movieclip_scenes` | 11 | 8.0s |  |
| 661 | `movieclip_soundtransform` | 831 | 32.1s |  |
| 662 | `movieclip_stop` | 1 | 29.3s |  |
| 663 | `movieclip_super_is_symbol` | 20 | 8.4s |  |
| 664 | `movieclip_symbol_constr` | 8 | 8.2s |  |
| 665 | `movieclip_text_mousedown` | 1 | 8.2s |  |
| 666 | `movieclip_willtrigger` | 5 | 8.2s |  |
| 667 | `multiply` | 1058 | 20.0s |  |
| 668 | `namespace_constr` | 253 | 8.4s |  |
| 669 | `namespace_constr_args` | 1 | 8.1s |  |
| 670 | `namespace_enumeration_order` | 7 | 29.7s |  |
| 671 | `nan_scale` | 9 | 8.0s |  |
| 672 | `navigateToURL_target_normalize` | 107 | 31.8s |  |
| 673 | `negate` | 30 | 8.1s |  |
| 674 | `negative_volume_panned` | 0 | 8.4s |  |
| 675 | `nested_iteration` | 11 | 8.1s |  |
| 676 | `net_getClassByAlias` | 3 | 8.1s |  |
| 677 | `net_navigateToURL` | 57 | 8.1s |  |
| 678 | `net_stream_play_options` | 6 | 8.1s |  |
| 679 | `netconnection_close` | 55 | 8.2s |  |
| 680 | `netconnection_properties` | 78 | 8.3s |  |
| 681 | `netconnection_send_remote` | 50 | 8.4s |  |
| 682 | `netconnection_serialize_arrays` | 6 | 8.2s |  |
| 683 | `netstream_client` | 10 | 8.3s |  |
| 684 | `netstream_connect` | 7 | 8.2s |  |
| 685 | `newactivation_in_script_init` | 3 | 7.2s |  |
| 686 | `newclass_mismatched` | 4 | 7.2s |  |
| 687 | `newclass_twice` | 3 | 7.1s |  |
| 688 | `nonconflicting_declarations` | 0 | 3.1s |  |
| 689 | `null_void_types` | 8 | 7.2s |  |
| 690 | `number_autoconv` | 21 | 21.9s |  |
| 691 | `number_autoconv_amf` | 132 | 7.2s |  |
| 692 | `number_autoconv_array_sort_32bit` | 1 | 7.2s |  |
| 693 | `number_constr` | 58 | 7.3s |  |
| 694 | `number_toexponential` | 378 | 7.2s |  |
| 695 | `number_toexponential2` | 35 | 3.0s |  |
| 696 | `number_tofixed` | 378 | 7.1s |  |
| 697 | `number_toprecision` | 350 | 7.2s |  |
| 698 | `obfuscated_class_names` | 3 | 7.1s |  |
| 699 | `object_enumeration` | 10 | 7.2s |  |
| 700 | `object_prototype` | 4 | 7.2s |  |
| 701 | `object_to_locale_string` | 2 | 7.1s |  |
| 702 | `object_to_string` | 2 | 7.1s |  |
| 703 | `object_value_of` | 2 | 3.0s |  |
| 704 | `op_coerce` | 54 | 7.2s |  |
| 705 | `op_coerce_x` | 54 | 7.2s |  |
| 706 | `op_escxattr` | 2 | 7.1s |  |
| 707 | `op_escxelem` | 2 | 7.1s |  |
| 708 | `op_lookupswitch` | 4 | 7.2s |  |
| 709 | `optimize_coerce` | 1 | 7.1s |  |
| 710 | `orphan_movie_complex` | 80 | 7.6s |  |
| 711 | `orphan_movie_reorder` | 111 | 26.4s |  |
| 712 | `package_namespace` | 7 | 7.1s |  |
| 713 | `param_default_value_has_zero_cpool_index` | 1 | 7.1s |  |
| 714 | `parent_early_access_child` | 16 | 25.9s |  |
| 715 | `parse_float` | 81 | 7.5s |  |
| 716 | `parse_float_swf10` | 81 | 7.1s |  |
| 717 | `parse_int` | 135 | 7.8s |  |
| 718 | `perspective_projection_basic` | 40 | 7.2s |  |
| 719 | `pixelbender_ceil` | 77 | 7.4s |  |
| 720 | `pixelbender_conditional` | 138 | 23.8s |  |
| 721 | `pixelbender_conversions` | 270 | 6.3s |  |
| 722 | `pixelbender_dithering` | 8 | 28.8s |  |
| 723 | `pixelbender_div` | 36 | 6.1s |  |
| 724 | `pixelbender_effect_BlurredFocus` | 0 | 30.2s |  |
| 725 | `pixelbender_effect_glassDisplace` | 0 | 11.3s |  |
| 726 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 25.9s |  |
| 727 | `pixelbender_effect_smudge` | 0 | 8.8s |  |
| 728 | `pixelbender_effect_tintype` | 0 | 8.2s |  |
| 729 | `pixelbender_effect_twirl` | 0 | 9.3s |  |
| 730 | `pixelbender_eof` | 7 | 5.8s |  |
| 731 | `pixelbender_images` | 0 | 7.7s |  |
| 732 | `pixelbender_input` | 103 | 22.4s |  |
| 733 | `pixelbender_logicalnot` | 20 | 5.7s |  |
| 734 | `pixelbender_malformed_data` | 190 | 22.1s |  |
| 735 | `pixelbender_multiple_out_params` | 1 | 5.7s |  |
| 736 | `pixelbender_no_out_param` | 6 | 5.7s |  |
| 737 | `pixelbender_outputs` | 13 | 6.3s |  |
| 738 | `pixelbender_padding_bytes` | 22 | 6.2s |  |
| 739 | `pixelbender_param_qualifier` | 512 | 5.9s |  |
| 740 | `pixelbender_parameters` | 1563 | 6.1s |  |
| 741 | `pixelbender_parameters_bool` | 240 | 6.4s |  |
| 742 | `pixelbender_parameters_int_vs_bool` | 54 | 6.5s |  |
| 743 | `pixelbender_parse_errors` | 6 | 6.0s |  |
| 744 | `pixelbender_rsqrt` | 24 | 5.9s |  |
| 745 | `pixelbender_select_kinds` | 8 | 6.2s |  |
| 746 | `pixelbender_shaderdata` | 49 | 6.5s |  |
| 747 | `pixelbender_shaderdata_setter` | 99 | 6.2s |  |
| 748 | `pixelbender_sign` | 60 | 6.2s |  |
| 749 | `pixelbender_vector_output` | 11 | 6.1s |  |
| 750 | `place_and_lookup/swf10` | 33 | 5.8s |  |
| 751 | `place_and_lookup/swf9` | 33 | 0.9s |  |
| 752 | `place_multiple` | 17 | 21.8s |  |
| 753 | `place_object_replace` | 9 | 5.8s |  |
| 754 | `place_object_replace_2` | 24 | 5.9s |  |
| 755 | `place_object_same_depth_frame` | 1 | 5.9s |  |
| 756 | `point` | 132 | 6.3s |  |
| 757 | `primitive_edge_cases` | 1 | 5.8s |  |
| 758 | `print_job_options` | 3 | 5.8s |  |
| 759 | `property_is_enumerable_reset` | 23 | 7.2s |  |
| 760 | `property_priority` | 22 | 7.5s |  |
| 761 | `property_priority_chained` | 4 | 7.2s |  |
| 762 | `property_priority_definition_names_order` | 2 | 7.4s |  |
| 763 | `property_priority_three_level` | 6 | 25.6s |  |
| 764 | `propertyisenumerable_namespaces` | 6 | 7.1s |  |
| 765 | `prototype_set_null` | 7 | 7.1s |  |
| 766 | `proxy_callproperty` | 24 | 7.2s |  |
| 767 | `proxy_deleteproperty` | 64 | 7.2s |  |
| 768 | `proxy_enumeration` | 34 | 7.1s |  |
| 769 | `proxy_getproperty` | 77 | 7.2s |  |
| 770 | `proxy_hasownproperty` | 8 | 3.0s |  |
| 771 | `proxy_hasproperty` | 32 | 7.2s |  |
| 772 | `proxy_serialize` | 9 | 7.1s |  |
| 773 | `proxy_setproperty` | 42 | 7.2s |  |
| 774 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.1s |  |
| 775 | `qname_constr` | 32 | 7.2s |  |
| 776 | `qname_constr_namespace` | 24 | 7.1s |  |
| 777 | `qname_enumeration` | 9 | 7.1s |  |
| 778 | `qname_indexing` | 23 | 3.1s |  |
| 779 | `qname_tostring` | 25 | 7.2s |  |
| 780 | `qname_valueof` | 29 | 7.2s |  |
| 781 | `rectangle` | 1094 | 7.8s |  |
| 782 | `regexp_constr` | 148 | 7.4s |  |
| 783 | `regexp_exec` | 19 | 7.2s |  |
| 784 | `regexp_extended` | 47 | 7.1s |  |
| 785 | `regexp_multiargs` | 1 | 7.0s |  |
| 786 | `regexp_test` | 27 | 3.1s |  |
| 787 | `regexp_toString` | 10 | 7.1s |  |
| 788 | `register_script_refresh` | 35 | 25.8s |  |
| 789 | `remove_child_clear_field` | 88 | 7.5s |  |
| 790 | `remove_dobj` | 3 | 7.2s |  |
| 791 | `resolve_order` | 4 | 7.1s |  |
| 792 | `responder_null_callbacks` | 1 | 7.0s |  |
| 793 | `rng` | 1 | 8.2s |  |
| 794 | `rootless` | 42 | 7.1s |  |
| 795 | `rshift` | 1058 | 19.0s |  |
| 796 | `rtqname_not_namespace` | 12 | 7.1s |  |
| 797 | `sandbox_type_inherited` | 2 | 7.3s |  |
| 798 | `sandbox_type_local_file` | 1 | 30.1s |  |
| 799 | `sandbox_type_local_network` | 1 | 7.8s |  |
| 800 | `scene_constr` | 8 | 8.2s |  |
| 801 | `scopes_dont_cache/order-1` | 1 | 29.8s |  |
| 802 | `scopes_dont_cache/order-2` | 1 | 1.2s |  |
| 803 | `security_domain_current` | 2 | 8.0s |  |
| 804 | `selection` | 239 | 8.6s |  |
| 805 | `set_local_0` | 31 | 3.7s |  |
| 806 | `set_property_is_enumerable` | 85 | 8.6s |  |
| 807 | `shaderparameter_value` | 4 | 8.2s |  |
| 808 | `shape_drawrect` | 54 | 8.2s |  |
| 809 | `shared_object_no_root` | 3 | 8.1s |  |
| 810 | `simplebutton_added_to_stage` | 45 | 30.6s |  |
| 811 | `simplebutton_childevents` | 86 | 30.8s |  |
| 812 | `simplebutton_childevents_nested` | 54 | 8.5s |  |
| 813 | `simplebutton_childevents_sprite` | 13 | 8.3s |  |
| 814 | `simplebutton_childprops` | 144 | 8.5s |  |
| 815 | `simplebutton_childshuffle` | 23 | 8.2s |  |
| 816 | `simplebutton_constr` | 36 | 8.5s |  |
| 817 | `simplebutton_constr_childevents` | 48 | 8.7s |  |
| 818 | `simplebutton_constr_params` | 42 | 8.4s |  |
| 819 | `simplebutton_mouseenabled` | 26 | 8.2s |  |
| 820 | `simplebutton_multi_children` | 19 | 8.4s |  |
| 821 | `simplebutton_structure` | 27 | 8.4s |  |
| 822 | `simplebutton_symbolclass` | 68 | 8.5s |  |
| 823 | `slot_disp_id_shared_numbering` | 1 | 29.8s |  |
| 824 | `slots_force_autoassigned` | 1 | 8.2s |  |
| 825 | `socket_after_disconnect` | 1 | 8.0s |  |
| 826 | `socket_close` | 2 | 8.2s |  |
| 827 | `socket_connect` | 4 | 8.2s |  |
| 828 | `socket_errors` | 56 | 8.7s |  |
| 829 | `socket_read_big` | 48 | 8.2s |  |
| 830 | `socket_read_little` | 48 | 3.5s |  |
| 831 | `socket_read_write_object` | 8 | 25.7s |  |
| 832 | `socket_write_big` | 15 | 7.4s |  |
| 833 | `socket_write_little` | 14 | 7.2s |  |
| 834 | `sound_embeddedprops` | 26 | 7.3s |  |
| 835 | `sound_play` | 19 | 7.4s |  |
| 836 | `sound_valueof` | 33 | 7.3s |  |
| 837 | `soundchannel_soundtransform` | 835 | 27.9s |  |
| 838 | `soundchannel_soundtransform_exists` | 5 | 25.8s |  |
| 839 | `soundchannel_stop` | 8 | 25.8s |  |
| 840 | `soundmixer_buffertime` | 5 | 7.1s |  |
| 841 | `soundmixer_stopall` | 6 | 25.7s |  |
| 842 | `soundtransform` | 442 | 12.9s |  |
| 843 | `space_justifier_clone` | 12 | 7.2s |  |
| 844 | `sprite_with_frames` | 0 | 26.2s |  |
| 845 | `stage3d_agal_cross_product` | 0 | 9.8s |  |
| 846 | `stage3d_agal_upload_errors` | 66 | 9.9s |  |
| 847 | `stage3d_bitmap` | 0 | 31.1s |  |
| 848 | `stage3d_blend` | 81 | 30.2s |  |
| 849 | `stage3d_context3d_string_args` | 158 | 8.2s |  |
| 850 | `stage3d_errors` | 7 | 7.3s |  |
| 851 | `stage3d_errors_atf` | 3 | 8.6s |  |
| 852 | `stage3d_errors_swf_29` | 6 | 7.4s |  |
| 853 | `stage3d_float1_index` | 0 | 28.4s |  |
| 854 | `stage3d_fractal` | 0 | 28.9s |  |
| 855 | `stage3d_ignore_sampler_override` | 0 | 28.8s |  |
| 856 | `stage3d_multistage_triangle` | 3 | 10.1s |  |
| 857 | `stage3d_program_constants_bytearray_be` | 0 | 30.3s |  |
| 858 | `stage3d_program_constants_bytearray_le` | 0 | 10.6s |  |
| 859 | `stage3d_program_constants_invalid_input` | 21 | 8.1s |  |
| 860 | `stage3d_raytrace` | 0 | 33.6s |  |
| 861 | `stage3d_rotating_cube` | 0 | 10.8s |  |
| 862 | `stage3d_sampler` | 0 | 10.0s |  |
| 863 | `stage3d_sampler_partial_upload` | 0 | 9.9s |  |
| 864 | `stage3d_stencil` | 0 | 29.4s |  |
| 865 | `stage3d_texture` | 0 | 15.4s |  |
| 866 | `stage3d_texture_bytearray` | 0 | 11.6s |  |
| 867 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 10.9s |  |
| 868 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 12.0s |  |
| 869 | `stage3d_triangle` | 0 | 10.3s |  |
| 870 | `stage3d_triangle_bytes4` | 0 | 10.3s |  |
| 871 | `stage3d_triangle_float1` | 0 | 10.3s |  |
| 872 | `stage3d_triangle_index_upload` | 0 | 10.2s |  |
| 873 | `stage3d_x_y` | 22 | 7.5s |  |
| 874 | `stage_access` | 10 | 7.5s |  |
| 875 | `stage_displayobject_properties` | 24 | 7.4s |  |
| 876 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.4s |  |
| 877 | `stage_framerate_nan` | 7 | 26.6s |  |
| 878 | `stage_framerate_negative` | 6 | 7.5s |  |
| 879 | `stage_framerate_zero` | 6 | 7.5s |  |
| 880 | `stage_invalidate` | 38 | 7.7s |  |
| 881 | `stage_loaderinfo_properties` | 24 | 26.8s |  |
| 882 | `stage_mousechildren` | 2 | 7.5s |  |
| 883 | `stage_mouseenabled` | 15 | 7.4s |  |
| 884 | `stage_overriden_setters` | 31 | 7.6s |  |
| 885 | `stage_properties` | 30 | 7.4s |  |
| 886 | `stage_stage3Ds_vector` | 1 | 26.2s |  |
| 887 | `static_text` | 3 | 7.7s |  |
| 888 | `static_var_with_this_in_ctor` | 2 | 7.5s |  |
| 889 | `stored_properties` | 11 | 7.5s |  |
| 890 | `strict_equality` | 34 | 7.5s |  |
| 891 | `string_call` | 13 | 7.5s |  |
| 892 | `string_case` | 23 | 7.5s |  |
| 893 | `string_char_at` | 27 | 7.5s |  |
| 894 | `string_char_code_at` | 28 | 3.2s |  |
| 895 | `string_concat_fromcharcode` | 37 | 7.4s |  |
| 896 | `string_constr` | 25 | 7.5s |  |
| 897 | `string_indexof_lastindexof` | 87 | 7.7s |  |
| 898 | `string_length` | 16 | 7.4s |  |
| 899 | `string_locale_compare` | 39 | 7.8s |  |
| 900 | `string_match` | 51 | 28.4s |  |
| 901 | `string_relational_compare` | 4 | 7.8s |  |
| 902 | `string_replace` | 51 | 7.9s |  |
| 903 | `string_search` | 41 | 7.9s |  |
| 904 | `string_slice_substr_substring` | 170 | 8.9s |  |
| 905 | `string_split` | 29 | 7.9s |  |
| 906 | `string_substr_negative` | 21 | 7.7s |  |
| 907 | `string_substr_weird` | 182 | 7.7s |  |
| 908 | `stylesheet` | 221 | 8.3s |  |
| 909 | `subtract` | 1058 | 19.5s |  |
| 910 | `super_get_call` | 12 | 7.9s |  |
| 911 | `supercall_two_classobjects` | 2 | 7.8s |  |
| 912 | `supercalls_weird` | 2 | 7.8s |  |
| 913 | `superinterface_call` | 20 | 8.0s |  |
| 914 | `superinterface_instanceof` | 18 | 7.9s |  |
| 915 | `swf8` | 1 | 7.8s |  |
| 916 | `swf_10_queued_goto_scripts_construct` | 52 | 28.7s |  |
| 917 | `swf_9_goto_in_enter_frame` | 17 | 8.0s |  |
| 918 | `swf_9_goto_in_enter_frame_simple` | 15 | 8.0s |  |
| 919 | `swf_9_queued_goto_scripts` | 6 | 28.4s |  |
| 920 | `swf_9_queued_goto_scripts_construct` | 28 | 1.5s |  |
| 921 | `swf_9_versioning` | 2 | 7.8s |  |
| 922 | `swf_wrong_frame_count` | 38 | 8.1s |  |
| 923 | `swf_wrong_frame_count_isplaying` | 22 | 28.3s |  |
| 924 | `symbol_class_binary_data` | 8 | 7.9s |  |
| 925 | `symbol_class_conflict` | 4 | 8.3s |  |
| 926 | `symbol_class_root_not_zero` | 1 | 7.8s |  |
| 927 | `symbolclass_invalid_utf8` | 2 | 7.8s |  |
| 928 | `system_setclipboard_null` | 1 | 7.8s |  |
| 929 | `tab_ordering_arrows` | 998 | 29.5s |  |
| 930 | `tab_ordering_automatic_advanced` | 184 | 8.8s |  |
| 931 | `tab_ordering_automatic_basic` | 45 | 7.8s |  |
| 932 | `tab_ordering_children` | 116 | 22.0s |  |
| 933 | `tab_ordering_custom_basic` | 34 | 1.3s |  |
| 934 | `tab_ordering_stage_tab_children` | 32 | 1.3s |  |
| 935 | `tab_ordering_stage_tab_children_remove_root` | 5 | 1.3s |  |
| 936 | `tab_ordering_tabbable` | 47 | 1.3s |  |
| 937 | `tabstop_properties` | 105 | 1.3s |  |
| 938 | `text_element_basic` | 34 | 1.2s |  |
| 939 | `text_engine_fontdescription` | 27 | 1.2s |  |
| 940 | `text_engine_groupelement` | 64 | 1.3s |  |
| 941 | `text_run` | 7 | 1.3s |  |
| 942 | `textblock_createline_errors` | 23 | 1.3s |  |
| 943 | `textblock_createline_fte` | 9 | 21.6s |  |
| 944 | `textblock_properties` | 118 | 1.3s |  |
| 945 | `textbox_click` | 37 | 21.8s |  |
| 946 | `textfield_event` | 66 | 1.3s |  |
| 947 | `textfield_focusin_event` | 9 | 1.2s |  |
| 948 | `textfield_input_dead_keys_windows` | 15 | 1.3s |  |
| 949 | `textfield_unload` | 39 | 21.5s |  |
| 950 | `textformat` | 1134 | 1.3s |  |
| 951 | `textformat_display` | 14 | 1.2s |  |
| 952 | `textformat_font_max_length` | 4 | 1.2s |  |
| 953 | `textline_inapplicable_properties` | 10 | 1.2s |  |
| 954 | `textline_name` | 1 | 1.2s |  |
| 955 | `textline_splitting_basic` | 76 | 1.3s |  |
| 956 | `textline_throwerror` | 30 | 1.2s |  |
| 957 | `textline_validity` | 162 | 1.3s |  |
| 958 | `throw` | 3 | 1.3s |  |
| 959 | `timeline_scripts` | 3 | 1.3s |  |
| 960 | `timer` | 90 | 1.7s |  |
| 961 | `timer_events` | 3 | 1.3s |  |
| 962 | `timer_finished` | 11 | 1.3s |  |
| 963 | `timer_reset` | 8 | 1.5s |  |
| 964 | `timer_setdelay` | 5 | 1.5s |  |
| 965 | `trace` | 12 | 1.3s |  |
| 966 | `truthiness` | 30 | 1.3s |  |
| 967 | `try_catch` | 11 | 8.1s |  |
| 968 | `try_catch_typed` | 12 | 8.0s |  |
| 969 | `typeof` | 30 | 8.0s |  |
| 970 | `uint_constr` | 92 | 8.2s |  |
| 971 | `uint_tofixed` | 1215 | 7.7s |  |
| 972 | `uint_tostring` | 3375 | 8.1s |  |
| 973 | `uncaught_error_basic` | 2 | 7.8s |  |
| 974 | `unchecked_function` | 15 | 7.8s |  |
| 975 | `unescape` | 28 | 7.8s |  |
| 976 | `url_loader` | 25 | 7.9s |  |
| 977 | `url_vars` | 27 | 8.0s |  |
| 978 | `urlrequest` | 18 | 24.9s |  |
| 979 | `urlstream_basic` | 5 | 7.9s |  |
| 980 | `urshift` | 1058 | 19.9s |  |
| 981 | `utils3d` | 7 | 3.3s |  |
| 982 | `vector3d` | 397 | 12.4s |  |
| 983 | `vector_class` | 36 | 8.3s |  |
| 984 | `vector_class_call` | 11 | 8.0s |  |
| 985 | `vector_coercion` | 66 | 8.8s |  |
| 986 | `vector_concat` | 90 | 8.3s |  |
| 987 | `vector_constr` | 107 | 8.5s |  |
| 988 | `vector_enumeration` | 5 | 7.9s |  |
| 989 | `vector_every` | 92 | 8.7s |  |
| 990 | `vector_filter` | 95 | 8.7s |  |
| 991 | `vector_holes` | 24 | 7.9s |  |
| 992 | `vector_indexof` | 302 | 12.5s |  |
| 993 | `vector_insertat` | 270 | 8.9s |  |
| 994 | `vector_int_access` | 4 | 7.8s |  |
| 995 | `vector_int_delete` | 11 | 7.7s |  |
| 996 | `vector_join` | 58 | 8.3s |  |
| 997 | `vector_lastindexof` | 302 | 7.8s |  |
| 998 | `vector_legacy` | 10 | 8.0s |  |
| 999 | `vector_map` | 85 | 8.7s |  |
| 1000 | `vector_object_final` | 1 | 7.8s |  |
| 1001 | `vector_object_toString` | 10 | 7.8s |  |
| 1002 | `vector_pushpop` | 255 | 9.2s |  |
| 1003 | `vector_reborrow_bug` | 10 | 7.7s |  |
| 1004 | `vector_removeat` | 172 | 9.1s |  |
| 1005 | `vector_reverse` | 232 | 9.0s |  |
| 1006 | `vector_shiftunshift` | 252 | 9.0s |  |
| 1007 | `vector_slice` | 331 | 9.5s |  |
| 1008 | `vector_sort` | 905 | 16.9s |  |
| 1009 | `vector_splice` | 693 | 11.5s |  |
| 1010 | `vector_splice_fixed_bug_compat` | 4 | 27.8s |  |
| 1011 | `vector_tostring` | 79 | 8.3s |  |
| 1012 | `verification` | 8 | 7.8s |  |
| 1013 | `verify_abnormal_loop` | 1 | 7.7s |  |
| 1014 | `verify_dxns_without_flag` | 3 | 8.1s |  |
| 1015 | `verify_exception_target_two_jumps` | 1 | 7.7s |  |
| 1016 | `verify_exception_targets_edge_case` | 1 | 7.7s |  |
| 1017 | `verify_illegal_opcode` | 1 | 3.7s |  |
| 1018 | `verify_jump_to_middle_of_op` | 1 | 7.7s |  |
| 1019 | `verify_lookup_switch_edge_case` | 1 | 7.7s |  |
| 1020 | `verify_method_info_oob` | 1 | 1.4s |  |
| 1021 | `verify_stack` | 5 | 7.8s |  |
| 1022 | `verify_typecheck` | 4 | 7.7s |  |
| 1023 | `verify_unreachable_exception` | 2 | 7.7s |  |
| 1024 | `versioned_isplaying` | 2 | 7.8s |  |
| 1025 | `virtual_properties` | 16 | 3.5s |  |
| 1026 | `with` | 4 | 7.8s |  |
| 1027 | `wrong_arg_count` | 7 | 7.9s |  |
| 1028 | `xml_abstract_equality` | 36 | 7.9s |  |
| 1029 | `xml_advanced` | 52 | 7.7s |  |
| 1030 | `xml_appendchild` | 10 | 7.7s |  |
| 1031 | `xml_appendchild_swf_v21` | 13 | 3.7s |  |
| 1032 | `xml_as_attribute` | 9 | 7.6s |  |
| 1033 | `xml_attribute` | 35 | 7.9s |  |
| 1034 | `xml_attribute_name` | 40 | 7.8s |  |
| 1035 | `xml_basic` | 33 | 7.7s |  |
| 1036 | `xml_child` | 25 | 7.7s |  |
| 1037 | `xml_childindex` | 7 | 7.5s |  |
| 1038 | `xml_children` | 43 | 8.2s |  |
| 1039 | `xml_class_call` | 9 | 7.7s |  |
| 1040 | `xml_contains` | 197 | 7.8s |  |
| 1041 | `xml_copy` | 20 | 3.4s |  |
| 1042 | `xml_ctor_from_tostring` | 23 | 7.8s |  |
| 1043 | `xml_delete` | 114 | 7.6s |  |
| 1044 | `xml_descendants` | 83 | 27.2s |  |
| 1045 | `xml_elements` | 6 | 7.5s |  |
| 1046 | `xml_equals_namespace_check` | 2 | 7.5s |  |
| 1047 | `xml_explicit_use_namespace` | 5 | 7.6s |  |
| 1048 | `xml_getdescendants_qname` | 21 | 7.6s |  |
| 1049 | `xml_has_property_via_in` | 26 | 7.5s |  |
| 1050 | `xml_hasownproperty` | 6 | 7.4s |  |
| 1051 | `xml_ignore_white` | 6 | 7.5s |  |
| 1052 | `xml_length` | 2 | 7.5s |  |
| 1053 | `xml_list_as_attribute` | 9 | 7.5s |  |
| 1054 | `xml_list_concat` | 20 | 7.5s |  |
| 1055 | `xml_list_delete_clear_parent` | 6 | 7.4s |  |
| 1056 | `xml_list_enumerate` | 4 | 7.4s |  |
| 1057 | `xml_methods_settings` | 3 | 7.4s |  |
| 1058 | `xml_mismatched_tag` | 37 | 7.5s |  |
| 1059 | `xml_namespace` | 39 | 7.5s |  |
| 1060 | `xml_namespace_methods` | 245 | 7.5s |  |
| 1061 | `xml_namespaced_property` | 7 | 7.5s |  |
| 1062 | `xml_no_namespace` | 1 | 7.4s |  |
| 1063 | `xml_nodekind` | 3 | 7.4s |  |
| 1064 | `xml_normalize` | 35 | 7.6s |  |
| 1065 | `xml_notification_bubbling` | 361 | 7.5s |  |
| 1066 | `xml_parent` | 8 | 7.5s |  |
| 1067 | `xml_set_children` | 17 | 7.6s |  |
| 1068 | `xml_set_name` | 34 | 7.5s |  |
| 1069 | `xml_settings` | 6 | 3.2s |  |
| 1070 | `xml_simple_complex_content` | 47 | 7.5s |  |
| 1071 | `xml_socket` | 11 | 7.6s |  |
| 1072 | `xml_text` | 7 | 7.5s |  |
| 1073 | `xml_tostring` | 6 | 7.5s |  |
| 1074 | `xml_tostring_namespace` | 12 | 7.5s |  |
| 1075 | `xml_unescaping` | 23 | 7.6s |  |
| 1076 | `xml_weird_ignores` | 54 | 3.4s |  |
| 1077 | `xml_wildcard` | 11 | 7.5s |  |
| 1078 | `xmldocument` | 254 | 7.6s |  |
| 1079 | `xmlnode` | 3540 | 7.7s |  |
| 1080 | `zero_frame_clip` | 3 | 8.0s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 7.3s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 27.1s |  |
| 3 | `blend_transform` | 1 | 1 | 5.9s |  |
| 4 | `coerce_property` | 3 | 3 | 8.2s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 8.1s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 25.4s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 7.6s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 26.8s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 7.7s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 3.2s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 7.5s |  |
| 12 | `freestanding_superclass` | 2 | 4 | 7.2s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 26.3s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 28.4s |  |
| 15 | `int_toexponential` | 76 | 76 | 5.6s |  |
| 16 | `int_toprecision` | 441 | 441 | 5.2s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 8.5s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 8.1s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 29.8s |  |
| 20 | `soundchannel_position` | 74 | 74 | 26.9s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 7.4s |  |
| 22 | `sprite_dropTarget` | 15 | 15 | 7.2s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 28.1s |  |
| 24 | `uint_toexponential` | 100 | 100 | 8.1s |  |
| 25 | `uint_toprecision` | 433 | 433 | 8.0s |  |
| 26 | `uncaught_errors_stringified` | 15 | 15 | 7.8s |  |
| 27 | `weird_superinterface_properties` | 1 | 1 | 27.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**36 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stylesheet_transform` | 99.0% | 304 | 307 | 3 |  |
| 2 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 3 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 4 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 5 | `stylesheet_parse_color` | 94.2% | 65 | 69 | 4 |  |
| 6 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 7 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 8 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 9 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 10 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 11 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 12 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 13 | `textblock_line_changes` | 79.1% | 125 | 158 | 33 |  |
| 14 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 15 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 16 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 17 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 18 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 19 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 20 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 21 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 22 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 23 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 24 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 25 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 26 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 27 | `displayobject_scrollrect` | 57.6% | 19 | 33 | 14 |  |
| 28 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 29 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 30 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 31 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 32 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 33 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 34 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 35 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 36 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**117 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stylesheet_transform` | 99.0% | 304/307 | 307 | 307 |  |
| 2 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 3 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 4 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 5 | `stylesheet_parse_color` | 94.2% | 65/69 | 69 | 69 |  |
| 6 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 7 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 8 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 9 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 10 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 11 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 12 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 13 | `textblock_line_changes` | 79.1% | 125/158 | 158 | 158 |  |
| 14 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 15 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 16 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 17 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 18 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 19 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 20 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 21 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 22 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 23 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 24 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 25 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 26 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 27 | `displayobject_scrollrect` | 57.6% | 19/33 | 33 | 33 |  |
| 28 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 29 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 30 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 31 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 32 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 33 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 34 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 35 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 36 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 37 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 38 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 39 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 40 | `textblock_recreateline` | 40.8% | 40/98 | 89 | 98 |  |
| 41 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 42 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 43 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 44 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 45 | `geom_transform` | 27.0% | 20/74 | 26 | 74 |  |
| 46 | `property_is_enumerable` | 21.9% | 25/114 | 27 | 114 |  |
| 47 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 48 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 49 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 50 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 51 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 52 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 53 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 54 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 55 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 56 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 57 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 58 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 59 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 60 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 61 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 62 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 63 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 64 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 65 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 66 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 67 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 68 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 69 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 70 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 71 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 72 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 73 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 74 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 75 | `all_classes/events/swf9` | 0.2% | 2/1030 | 190 | 1030 |  |
| 76 | `all_classes/events/swf10` | 0.2% | 3/1638 | 190 | 1638 |  |
| 77 | `all_classes/events/swf11` | 0.2% | 3/1750 | 190 | 1750 |  |
| 78 | `all_classes/events/swf12` | 0.2% | 3/1814 | 190 | 1814 |  |
| 79 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 80 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 81 | `all_classes/events/swf30` | 0.0% | 1/2353 | 190 | 2353 |  |
| 82 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 83 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 84 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 85 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 86 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 87 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 88 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 89 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 90 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 91 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 92 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 93 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 94 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 95 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 96 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 97 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 98 | `avm1_root` | 0.0% | 0/58 | 6 | 58 |  |
| 99 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 100 | `currency_parse_result` | 0.0% | 0/7 | 2 | 7 |  |
| 101 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 102 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 103 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 104 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 105 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 106 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 107 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 108 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 109 | `netfilterevent` | 0.0% | 0/10 | 2 | 10 |  |
| 110 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 111 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 112 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 113 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 114 | `statictext_text` | 0.0% | 0/8 | 8 | 8 |  |
| 115 | `subclass_superclass_linked_symbol` | 0.0% | 0/6 | 6 | 4 |  |
| 116 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 117 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
