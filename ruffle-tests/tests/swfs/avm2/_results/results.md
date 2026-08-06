# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-02 09:26 UTC

**Git SHA**: `b4c983ea4c`

**Run Duration**: 195m 32s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1225 |
| Passing | **1084** (88.5%) |
| Ruffle-matched | 27 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1111** (90.7%) |
| Failing | 114 |
| Total expected lines | 151671 |
| Matching lines | 118262 (78.0%) |
| Mismatched lines | 33409 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 114 | 100.0% |

## Passing Tests

**1084 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 24.7s |  |
| 2 | `accessibility` | 1 | 6.3s |  |
| 3 | `activation_class` | 6 | 6.2s |  |
| 4 | `add` | 1058 | 18.4s |  |
| 5 | `agal_compiler` | 13 | 8.6s |  |
| 6 | `air_datagram_socket` | 1 | 7.8s |  |
| 7 | `air_hidden_lookup` | 2 | 6.2s |  |
| 8 | `air_ifilepromise` | 1 | 6.2s |  |
| 9 | `all_classes/security/swf11` | 3 | 6.3s |  |
| 10 | `amf_array_serialization` | 17 | 8.2s |  |
| 11 | `amf_custom_obj` | 26 | 6.3s |  |
| 12 | `amf_dictionary` | 9 | 6.2s |  |
| 13 | `amf_function` | 46 | 6.3s |  |
| 14 | `amf_invalid_date` | 2 | 6.2s |  |
| 15 | `amf_missing_prop` | 6 | 6.2s |  |
| 16 | `amf_nondynamic_function_prop` | 6 | 6.4s |  |
| 17 | `amf_setter_error` | 8 | 6.4s |  |
| 18 | `amf_vector` | 40 | 6.5s |  |
| 19 | `amf_xml` | 6 | 6.2s |  |
| 20 | `application_domain` | 4 | 6.3s |  |
| 21 | `applicationdomain_getqualifieddefinitionnames` | 9 | 6.3s |  |
| 22 | `applicationdomain_hasdefinition_null` | 2 | 6.2s |  |
| 23 | `array_access` | 18 | 6.3s |  |
| 24 | `array_access_interpreter` | 4 | 6.3s |  |
| 25 | `array_access_no_pubns` | 2 | 6.2s |  |
| 26 | `array_concat` | 41 | 6.4s |  |
| 27 | `array_constr` | 10 | 6.2s |  |
| 28 | `array_delete` | 44 | 6.3s |  |
| 29 | `array_enumeration` | 10 | 6.2s |  |
| 30 | `array_enumeration_elements` | 11 | 6.3s |  |
| 31 | `array_every` | 8 | 6.2s |  |
| 32 | `array_filter` | 6 | 6.2s |  |
| 33 | `array_foreach` | 18 | 6.2s |  |
| 34 | `array_hasownproperty` | 11 | 2.2s |  |
| 35 | `array_holes` | 9 | 6.2s |  |
| 36 | `array_index_max` | 84 | 6.2s |  |
| 37 | `array_indexof` | 25 | 6.3s |  |
| 38 | `array_join` | 26 | 6.3s |  |
| 39 | `array_lastindexof` | 29 | 6.2s |  |
| 40 | `array_length` | 14 | 6.2s |  |
| 41 | `array_literal` | 3 | 6.2s |  |
| 42 | `array_map` | 8 | 6.0s |  |
| 43 | `array_pop` | 52 | 6.3s |  |
| 44 | `array_push` | 24 | 6.2s |  |
| 45 | `array_reborrow_bug` | 6 | 6.2s |  |
| 46 | `array_reverse` | 28 | 6.2s |  |
| 47 | `array_shift` | 51 | 2.4s |  |
| 48 | `array_slice` | 39 | 6.3s |  |
| 49 | `array_some` | 8 | 6.2s |  |
| 50 | `array_sort` | 297 | 6.8s |  |
| 51 | `array_sort_fun_swf12` | 2 | 6.3s |  |
| 52 | `array_sort_fun_swf13` | 2 | 0.6s |  |
| 53 | `array_sort_random` | 210 | 6.3s |  |
| 54 | `array_sort_swf10_32bit` | 1 | 6.2s |  |
| 55 | `array_sorton` | 545 | 7.1s |  |
| 56 | `array_sparse_ops` | 41 | 6.4s |  |
| 57 | `array_splice` | 133 | 6.5s |  |
| 58 | `array_splice2` | 428 | 6.6s |  |
| 59 | `array_splice_types` | 48 | 6.4s |  |
| 60 | `array_storage` | 8 | 6.3s |  |
| 61 | `array_tolocalestring` | 9 | 6.2s |  |
| 62 | `array_tostring` | 12 | 6.3s |  |
| 63 | `array_unshift` | 24 | 6.2s |  |
| 64 | `array_valueof` | 9 | 6.2s |  |
| 65 | `array_vector_null_callback` | 10 | 6.3s |  |
| 66 | `astype` | 28 | 6.3s |  |
| 67 | `astypelate` | 24 | 6.4s |  |
| 68 | `astypelate_propagates` | 1 | 6.2s |  |
| 69 | `asymmetric_key_events` | 11 | 6.5s |  |
| 70 | `av_networking_params` | 9 | 6.3s |  |
| 71 | `av_tag_data` | 2 | 6.2s |  |
| 72 | `avm2_catchup_dobj` | 158 | 6.8s |  |
| 73 | `away3d_advanced_shallow_water_demo` | 0 | 83.8s |  |
| 74 | `bevel_filter` | 187 | 6.4s |  |
| 75 | `bitand` | 1058 | 18.2s |  |
| 76 | `bitmap_constr` | 17 | 6.5s |  |
| 77 | `bitmap_data` | 1000 | 14.5s |  |
| 78 | `bitmap_pixelsnapping` | 2 | 25.0s |  |
| 79 | `bitmap_properties` | 23 | 6.3s |  |
| 80 | `bitmap_subclass` | 7 | 7.7s |  |
| 81 | `bitmap_subclass_properties` | 9 | 6.6s |  |
| 82 | `bitmap_timeline` | 9 | 6.3s |  |
| 83 | `bitmapdata_accuracy` | 1 | 42.3s |  |
| 84 | `bitmapdata_applyfilter_blur` | 0 | 25.2s |  |
| 85 | `bitmapdata_applyfilter_colormatrix` | 0 | 6.6s |  |
| 86 | `bitmapdata_applyfilter_destpoint` | 0 | 25.1s |  |
| 87 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 25.3s |  |
| 88 | `bitmapdata_clone` | 13 | 6.4s |  |
| 89 | `bitmapdata_colortransform` | 0 | 6.4s |  |
| 90 | `bitmapdata_colortransform_oob` | 2 | 6.2s |  |
| 91 | `bitmapdata_constr` | 22 | 6.3s |  |
| 92 | `bitmapdata_constructor_from_timeline` | 1 | 6.5s |  |
| 93 | `bitmapdata_copychannel` | 0 | 28.0s |  |
| 94 | `bitmapdata_copypixels` | 23 | 25.4s |  |
| 95 | `bitmapdata_copypixels_blend_over` | 1 | 6.4s |  |
| 96 | `bitmapdata_copypixelstobytearray` | 39 | 6.3s |  |
| 97 | `bitmapdata_dispose` | 7 | 6.3s |  |
| 98 | `bitmapdata_draw` | 0 | 25.2s |  |
| 99 | `bitmapdata_draw_colortransform` | 0 | 6.4s |  |
| 100 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 25.4s |  |
| 101 | `bitmapdata_draw_filters` | 0 | 25.1s |  |
| 102 | `bitmapdata_draw_masks` | 0 | 6.3s |  |
| 103 | `bitmapdata_draw_rotation` | 0 | 6.3s |  |
| 104 | `bitmapdata_draw_self_via_graphic` | 0 | 6.3s |  |
| 105 | `bitmapdata_draw_stage` | 0 | 25.0s |  |
| 106 | `bitmapdata_drawwithquality` | 0 | 6.6s |  |
| 107 | `bitmapdata_embedded` | 9 | 6.5s |  |
| 108 | `bitmapdata_fillrect` | 0 | 6.4s |  |
| 109 | `bitmapdata_filter_sourcerect` | 0 | 25.0s |  |
| 110 | `bitmapdata_floodfill` | 35 | 6.3s |  |
| 111 | `bitmapdata_getpixels` | 39 | 25.0s |  |
| 112 | `bitmapdata_getvector` | 27 | 2.4s |  |
| 113 | `bitmapdata_histogram` | 59 | 2.3s |  |
| 114 | `bitmapdata_hittest` | 112 | 6.9s |  |
| 115 | `bitmapdata_hittest_threshold` | 18 | 6.3s |  |
| 116 | `bitmapdata_opaque` | 0 | 6.3s |  |
| 117 | `bitmapdata_pixeldissolve` | 1037 | 6.9s |  |
| 118 | `bitmapdata_pixeldissolve_image` | 0 | 6.5s |  |
| 119 | `bitmapdata_rectangle_rounding` | 16 | 6.3s |  |
| 120 | `bitmapdata_setpixels` | 286 | 6.4s |  |
| 121 | `bitmapdata_setvector` | 26 | 6.4s |  |
| 122 | `bitmapdata_sync` | 0 | 24.9s |  |
| 123 | `bitmapdata_threshold` | 176 | 7.1s |  |
| 124 | `bitmapdata_zero_size` | 8 | 6.4s |  |
| 125 | `bitnot` | 46 | 6.4s |  |
| 126 | `bitor` | 1058 | 18.6s |  |
| 127 | `bitxor` | 1058 | 18.7s |  |
| 128 | `blend_mode_null` | 1 | 6.4s |  |
| 129 | `blend_multiply_alpha` | 0 | 6.3s |  |
| 130 | `blend_scroll` | 0 | 6.4s |  |
| 131 | `blend_shader_luma_lighten` | 3 | 6.5s |  |
| 132 | `blur_filter` | 43 | 6.4s |  |
| 133 | `boolean_constr` | 32 | 6.4s |  |
| 134 | `boolean_negation` | 30 | 6.3s |  |
| 135 | `boolean_tostring` | 8 | 6.3s |  |
| 136 | `broadcast_event` | 7 | 6.3s |  |
| 137 | `button_bounds` | 1 | 6.3s |  |
| 138 | `button_hittest` | 2 | 24.7s |  |
| 139 | `button_nested_frame` | 48 | 25.2s |  |
| 140 | `bytearray` | 48 | 6.5s |  |
| 141 | `bytearray_compress` | 31 | 6.3s |  |
| 142 | `bytearray_errors` | 24 | 6.3s |  |
| 143 | `bytearray_method_serialization` | 1 | 6.2s |  |
| 144 | `bytearray_oom` | 3 | 6.3s |  |
| 145 | `bytearray_readobject_amf0` | 50 | 6.2s |  |
| 146 | `bytearray_readobject_amf3` | 53 | 6.5s |  |
| 147 | `bytearray_readutf8bytes_with_bom` | 16 | 6.4s |  |
| 148 | `bytearray_serialization` | 3 | 6.3s |  |
| 149 | `bytearray_string_null` | 19 | 6.6s |  |
| 150 | `bytearray_tostring` | 15 | 6.3s |  |
| 151 | `bytearray_utf16` | 8 | 6.2s |  |
| 152 | `bytearray_writeobject` | 24 | 6.1s |  |
| 153 | `callee_in_initializer` | 6 | 6.2s |  |
| 154 | `callproplex_class` | 1 | 6.2s |  |
| 155 | `capabilities_resolution` | 8 | 26.2s |  |
| 156 | `catch_class` | 6 | 6.3s |  |
| 157 | `catch_scope_slot` | 7 | 2.4s |  |
| 158 | `checkfilter` | 4 | 2.3s |  |
| 159 | `class_call` | 32 | 6.5s |  |
| 160 | `class_cast_call` | 14 | 6.4s |  |
| 161 | `class_enumeration` | 4 | 6.4s |  |
| 162 | `class_has_own_property` | 2 | 6.4s |  |
| 163 | `class_init_interpreter_mode` | 1 | 6.5s |  |
| 164 | `class_is` | 32 | 6.4s |  |
| 165 | `class_methods` | 5 | 6.3s |  |
| 166 | `class_object_properties` | 10 | 6.4s |  |
| 167 | `class_singleton` | 18 | 6.5s |  |
| 168 | `class_supercalls_errors` | 35 | 6.6s |  |
| 169 | `class_supercalls_mismatched` | 26 | 6.4s |  |
| 170 | `class_superclass_wrong_order` | 1 | 24.2s |  |
| 171 | `class_to_locale_string` | 2 | 6.0s |  |
| 172 | `class_to_string` | 2 | 5.8s |  |
| 173 | `class_value_of` | 2 | 5.9s |  |
| 174 | `click_block` | 5 | 6.3s |  |
| 175 | `click_invisible` | 3 | 6.1s |  |
| 176 | `closures` | 12 | 5.9s |  |
| 177 | `coerce_return_type` | 40 | 6.1s |  |
| 178 | `coerce_return_type_fail` | 2 | 5.9s |  |
| 179 | `coerce_return_void` | 3 | 5.9s |  |
| 180 | `coerce_string` | 86 | 6.1s |  |
| 181 | `coerce_string_precision` | 28 | 6.0s |  |
| 182 | `coerce_to_primitive_side_effects` | 29 | 24.6s |  |
| 183 | `color_matrix_filter` | 19 | 6.0s |  |
| 184 | `construct_errors_swf10` | 8 | 6.0s |  |
| 185 | `construct_frame_list` | 22 | 24.6s |  |
| 186 | `construct_interface` | 3 | 5.9s |  |
| 187 | `constructor_call` | 3 | 5.9s |  |
| 188 | `constructors_vs_timeline` | 5 | 24.6s |  |
| 189 | `constructprop_dynamic_primitive` | 7 | 6.0s |  |
| 190 | `constructprop_method` | 2 | 5.8s |  |
| 191 | `content_element_basic` | 50 | 6.2s |  |
| 192 | `context3d_creation` | 9 | 6.0s |  |
| 193 | `control_flow_bool` | 4 | 5.9s |  |
| 194 | `control_flow_stricteq` | 8 | 5.9s |  |
| 195 | `convert_boolean` | 30 | 6.0s |  |
| 196 | `convert_integer` | 90 | 6.1s |  |
| 197 | `convert_number` | 56 | 6.0s |  |
| 198 | `convert_uinteger` | 90 | 6.1s |  |
| 199 | `convolution_filter` | 89 | 6.0s |  |
| 200 | `core_exceptions` | 47 | 6.7s |  |
| 201 | `cpool_index_invalid_bytecode_1` | 6 | 5.9s |  |
| 202 | `cpool_index_invalid_bytecode_2` | 3 | 5.9s |  |
| 203 | `cpool_index_invalid_bytecode_3` | 1 | 5.8s |  |
| 204 | `cross_api_version_call_older` | 12 | 6.0s |  |
| 205 | `cryptscore` | 11 | 6.0s |  |
| 206 | `date` | 30 | 6.8s |  |
| 207 | `date_parse` | 36 | 6.3s |  |
| 208 | `declocal` | 46 | 6.4s |  |
| 209 | `declocal_i` | 46 | 6.3s |  |
| 210 | `decode_uri` | 71 | 6.6s |  |
| 211 | `decrement` | 46 | 6.3s |  |
| 212 | `decrement_i` | 46 | 2.4s |  |
| 213 | `default_values` | 7 | 6.2s |  |
| 214 | `dictionary_access` | 62 | 6.5s |  |
| 215 | `dictionary_access_no_pubns` | 2 | 6.2s |  |
| 216 | `dictionary_delete` | 101 | 6.8s |  |
| 217 | `dictionary_foreach` | 42 | 6.5s |  |
| 218 | `dictionary_hasownproperty` | 63 | 6.5s |  |
| 219 | `dictionary_in` | 62 | 6.6s |  |
| 220 | `dictionary_iter_modify` | 8 | 6.5s |  |
| 221 | `dictionary_namespaces` | 36 | 6.6s |  |
| 222 | `dictionary_primitive_keys` | 29 | 6.4s |  |
| 223 | `displacement_map_filter` | 61 | 6.7s |  |
| 224 | `displayobject_alpha` | 277 | 6.5s |  |
| 225 | `displayobject_blendmode` | 0 | 6.6s |  |
| 226 | `displayobject_colortransform_nested` | 0 | 26.2s |  |
| 227 | `displayobject_filters` | 17 | 6.7s |  |
| 228 | `displayobject_from_enterframe` | 1 | 26.2s |  |
| 229 | `displayobject_getbounds_shape` | 0 | 26.1s |  |
| 230 | `displayobject_height` | 6052 | 26.3s |  |
| 231 | `displayobject_hittestobject` | 32 | 6.6s |  |
| 232 | `displayobject_hittestpoint` | 49 | 6.8s |  |
| 233 | `displayobject_hittestpoint_root` | 13 | 6.8s |  |
| 234 | `displayobject_invalid_floats` | 60 | 6.5s |  |
| 235 | `displayobject_invalid_props` | 3 | 6.5s |  |
| 236 | `displayobject_mask` | 3 | 6.6s |  |
| 237 | `displayobject_mask_self_referential` | 0 | 18.4s |  |
| 238 | `displayobject_metaData` | 3 | 4.3s |  |
| 239 | `displayobject_name` | 22 | 18.4s |  |
| 240 | `displayobject_name_from_timeline` | 24 | 4.4s |  |
| 241 | `displayobject_opaque_background` | 6 | 18.8s |  |
| 242 | `displayobject_parent` | 12 | 4.5s |  |
| 243 | `displayobject_root` | 24 | 4.5s |  |
| 244 | `displayobject_rotation` | 1284 | 4.4s |  |
| 245 | `displayobject_set_matrix_nested` | 0 | 19.1s |  |
| 246 | `displayobject_set_name_loaded` | 3 | 4.8s |  |
| 247 | `displayobject_subclass` | 2 | 4.3s |  |
| 248 | `displayobject_visible` | 23 | 4.4s |  |
| 249 | `displayobject_width` | 4852 | 18.9s |  |
| 250 | `displayobject_x` | 614 | 4.6s |  |
| 251 | `displayobject_y` | 617 | 4.5s |  |
| 252 | `displayobjectcontainer_addchild` | 32 | 4.5s |  |
| 253 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 4.6s |  |
| 254 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 4.6s |  |
| 255 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 4.8s |  |
| 256 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 4.7s |  |
| 257 | `displayobjectcontainer_addchildat` | 42 | 4.4s |  |
| 258 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 4.5s |  |
| 259 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 4.5s |  |
| 260 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 4.8s |  |
| 261 | `displayobjectcontainer_contains` | 66 | 18.5s |  |
| 262 | `displayobjectcontainer_getchildat` | 4 | 4.6s |  |
| 263 | `displayobjectcontainer_getchildbyname` | 9 | 4.7s |  |
| 264 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 4.5s |  |
| 265 | `displayobjectcontainer_getchildindex` | 28 | 4.9s |  |
| 266 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 5.4s |  |
| 267 | `displayobjectcontainer_removechild` | 10 | 4.6s |  |
| 268 | `displayobjectcontainer_removechild_errors` | 4 | 4.4s |  |
| 269 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 4.9s |  |
| 270 | `displayobjectcontainer_removechildat` | 18 | 4.8s |  |
| 271 | `displayobjectcontainer_removechildren` | 51 | 4.9s |  |
| 272 | `displayobjectcontainer_setchildindex` | 42 | 4.4s |  |
| 273 | `displayobjectcontainer_stopallmovieclips` | 2 | 18.8s |  |
| 274 | `displayobjectcontainer_swapchildren` | 42 | 4.6s |  |
| 275 | `displayobjectcontainer_swapchildrenat` | 42 | 4.3s |  |
| 276 | `displayobjectcontainer_timelineinstance` | 48 | 26.5s |  |
| 277 | `divide` | 1058 | 18.3s |  |
| 278 | `doabc_is_eager` | 1 | 26.0s |  |
| 279 | `documentclass` | 9 | 6.8s |  |
| 280 | `domain_memory` | 133 | 27.1s |  |
| 281 | `drag_drop` | 10 | 6.8s |  |
| 282 | `drop_shadow_filter` | 172 | 6.8s |  |
| 283 | `duplicate_defs` | 1 | 6.4s |  |
| 284 | `eager_init` | 1 | 6.6s |  |
| 285 | `east_asian_justifier_clone` | 8 | 2.5s |  |
| 286 | `edit_text_linkage` | 7 | 6.8s |  |
| 287 | `edittext_align` | 60 | 7.0s |  |
| 288 | `edittext_always_show_selection` | 0 | 26.7s |  |
| 289 | `edittext_antialiastype` | 296 | 6.9s |  |
| 290 | `edittext_at_point_methods_basic` | 16 | 8.0s |  |
| 291 | `edittext_autosize` | 39 | 7.0s |  |
| 292 | `edittext_autosize_align` | 0 | 26.3s |  |
| 293 | `edittext_autosize_height_dynamic` | 60 | 26.4s |  |
| 294 | `edittext_autosize_height_input` | 60 | 6.7s |  |
| 295 | `edittext_autosize_lazy_bounds_events` | 65 | 7.0s |  |
| 296 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.7s |  |
| 297 | `edittext_autosize_lazy_bounds_props` | 490 | 8.1s |  |
| 298 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.2s |  |
| 299 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.9s |  |
| 300 | `edittext_bottom_scroll_v_basic` | 210 | 6.8s |  |
| 301 | `edittext_bounds_scale` | 24 | 25.9s |  |
| 302 | `edittext_bullet` | 30 | 6.8s |  |
| 303 | `edittext_default_format` | 221 | 7.0s |  |
| 304 | `edittext_default_format_empty` | 136 | 6.9s |  |
| 305 | `edittext_empty_text_format` | 7 | 6.7s |  |
| 306 | `edittext_focus_selection` | 5 | 6.6s |  |
| 307 | `edittext_font_size` | 45 | 6.7s |  |
| 308 | `edittext_format_empty_font` | 8 | 6.6s |  |
| 309 | `edittext_get_char_index_at_point` | 4 | 27.3s |  |
| 310 | `edittext_get_line_index_at_point` | 2 | 26.3s |  |
| 311 | `edittext_get_line_index_of_char` | 76 | 7.6s |  |
| 312 | `edittext_getcharboundaries` | 172 | 7.1s |  |
| 313 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.7s |  |
| 314 | `edittext_getcharboundaries_scroll` | 85 | 25.5s |  |
| 315 | `edittext_getlinemetrics` | 146 | 6.6s |  |
| 316 | `edittext_html` | 3101 | 6.9s |  |
| 317 | `edittext_html_condensewhite` | 487 | 6.5s |  |
| 318 | `edittext_html_entity` | 4 | 6.7s |  |
| 319 | `edittext_html_font_size_swf12` | 267 | 6.4s |  |
| 320 | `edittext_html_font_size_swf13` | 273 | 6.2s |  |
| 321 | `edittext_html_roundtrip` | 17 | 6.4s |  |
| 322 | `edittext_ime_focus_lost` | 9 | 25.7s |  |
| 323 | `edittext_input_control` | 12 | 6.6s |  |
| 324 | `edittext_leading` | 9 | 6.7s |  |
| 325 | `edittext_letter_spacing` | 15 | 6.4s |  |
| 326 | `edittext_line_methods` | 294 | 7.8s |  |
| 327 | `edittext_line_metrics` | 11 | 27.2s |  |
| 328 | `edittext_margins` | 25 | 6.4s |  |
| 329 | `edittext_max_scroll_h_basic` | 475 | 6.6s |  |
| 330 | `edittext_max_scroll_v_basic` | 1000 | 6.6s |  |
| 331 | `edittext_mouse_selection` | 363 | 27.1s |  |
| 332 | `edittext_mousedown` | 3 | 6.9s |  |
| 333 | `edittext_mouseenabled` | 26 | 6.7s |  |
| 334 | `edittext_newline_character` | 22 | 6.4s |  |
| 335 | `edittext_newline_stripping` | 64 | 9.0s |  |
| 336 | `edittext_newlines` | 30 | 6.5s |  |
| 337 | `edittext_paragraph_methods` | 257 | 6.4s |  |
| 338 | `edittext_paste_events` | 8 | 6.6s |  |
| 339 | `edittext_paste_maxchars` | 4 | 6.4s |  |
| 340 | `edittext_paste_restrict` | 16 | 6.2s |  |
| 341 | `edittext_restrict` | 191 | 6.5s |  |
| 342 | `edittext_restrict_events` | 22 | 6.4s |  |
| 343 | `edittext_scrollh` | 10 | 6.4s |  |
| 344 | `edittext_selected_text` | 9 | 6.5s |  |
| 345 | `edittext_set_html_same` | 17 | 6.4s |  |
| 346 | `edittext_set_text_vs_html` | 9 | 6.5s |  |
| 347 | `edittext_stylesheet` | 536 | 6.8s |  |
| 348 | `edittext_stylesheet_custom_tag` | 76 | 6.5s |  |
| 349 | `edittext_stylesheet_display` | 272 | 6.6s |  |
| 350 | `edittext_underline` | 40 | 6.5s |  |
| 351 | `edittext_width_height` | 103 | 23.3s |  |
| 352 | `edittext_wordwrap_word` | 150 | 26.7s |  |
| 353 | `edittext_wrap_breaks` | 2375 | 7.0s |  |
| 354 | `element_format_clone` | 44 | 6.6s |  |
| 355 | `element_format_constructor_order` | 64 | 6.5s |  |
| 356 | `element_format_properties` | 235 | 7.2s |  |
| 357 | `empty_bounds` | 1 | 6.3s |  |
| 358 | `encode_uri_surrogate_pair_invalid` | 8 | 6.4s |  |
| 359 | `encode_uri_surrogate_pair_swf11` | 15 | 6.0s |  |
| 360 | `equals` | 512 | 10.3s |  |
| 361 | `error_geterrormessage` | 779 | 6.3s |  |
| 362 | `error_prototype` | 15 | 6.5s |  |
| 363 | `error_stack_trace_debug_swf17` | 0 | 24.9s |  |
| 364 | `error_stack_trace_debug_swf18` | 0 | 6.0s |  |
| 365 | `error_stack_trace_release_swf17` | 0 | 6.0s |  |
| 366 | `error_stack_trace_release_swf18` | 0 | 5.9s |  |
| 367 | `error_tostring` | 29 | 6.2s |  |
| 368 | `error_tostring_more` | 86 | 6.3s |  |
| 369 | `es3_inheritance` | 31 | 6.3s |  |
| 370 | `es4_inheritance` | 30 | 6.3s |  |
| 371 | `es4_interfaces` | 30 | 6.3s |  |
| 372 | `es4_method_binding` | 8 | 6.2s |  |
| 373 | `es4_oop_prototypes` | 14 | 6.4s |  |
| 374 | `es4_protected_inheritance` | 6 | 6.2s |  |
| 375 | `escape` | 71 | 6.3s |  |
| 376 | `escape_multi_byte` | 45 | 6.4s |  |
| 377 | `event_bubbles` | 2 | 6.2s |  |
| 378 | `event_cancelable` | 2 | 6.1s |  |
| 379 | `event_clone` | 20 | 6.2s |  |
| 380 | `event_clone_error_redispatch` | 3 | 6.3s |  |
| 381 | `event_clone_on_redispatch` | 10 | 6.4s |  |
| 382 | `event_formattostring` | 31 | 6.3s |  |
| 383 | `event_isdefaultprevented` | 12 | 6.2s |  |
| 384 | `event_target_getter` | 5 | 2.2s |  |
| 385 | `event_target_set` | 9 | 6.1s |  |
| 386 | `event_type` | 1 | 23.3s |  |
| 387 | `event_valueof_tostring` | 18 | 6.5s |  |
| 388 | `eventdispatcher_dispatchevent` | 12 | 6.6s |  |
| 389 | `eventdispatcher_dispatchevent_cancel` | 20 | 26.2s |  |
| 390 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.5s |  |
| 391 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.7s |  |
| 392 | `eventdispatcher_dispatchevent_this` | 5 | 6.5s |  |
| 393 | `eventdispatcher_haseventlistener` | 25 | 6.7s |  |
| 394 | `eventdispatcher_interface_invoke` | 1 | 6.5s |  |
| 395 | `eventdispatcher_tostring` | 10 | 6.6s |  |
| 396 | `eventdispatcher_willtrigger` | 25 | 6.5s |  |
| 397 | `falsiness` | 30 | 6.6s |  |
| 398 | `fast_index_access` | 12 | 6.8s |  |
| 399 | `filefilter_properties` | 4 | 6.6s |  |
| 400 | `filereference_browse_cancel` | 3 | 6.7s |  |
| 401 | `filereference_browse_select` | 9 | 6.7s |  |
| 402 | `filereference_load` | 31 | 6.6s |  |
| 403 | `filereference_save` | 16 | 6.5s |  |
| 404 | `filereference_save_and_browse` | 42 | 6.6s |  |
| 405 | `filereference_save_and_load` | 22 | 6.7s |  |
| 406 | `filereference_uninitialized` | 8 | 6.6s |  |
| 407 | `filereferencelist_browse_cancel` | 6 | 6.5s |  |
| 408 | `filereferencelist_browse_select` | 7 | 6.7s |  |
| 409 | `filter_rewind` | 8 | 6.8s |  |
| 410 | `filters_array_holes` | 25 | 6.7s |  |
| 411 | `finddef` | 3 | 6.5s |  |
| 412 | `findprop_global_prototype` | 6 | 6.7s |  |
| 413 | `flash_media_video_constructor` | 156 | 7.3s |  |
| 414 | `flash_media_video_rotation_probe` | 27 | 6.6s |  |
| 415 | `flash_media_video_setter` | 40 | 7.0s |  |
| 416 | `flash_xml` | 29 | 6.6s |  |
| 417 | `flash_xml_cloneNode` | 22 | 6.5s |  |
| 418 | `flash_xml_namespace` | 109 | 6.6s |  |
| 419 | `flash_xml_removeNode` | 60 | 6.5s |  |
| 420 | `focus_events_code` | 161 | 26.8s |  |
| 421 | `focus_events_key_basic` | 132 | 26.9s |  |
| 422 | `focus_events_key_navigation` | 53 | 6.7s |  |
| 423 | `focus_events_key_same_object` | 26 | 6.6s |  |
| 424 | `focus_events_mixed_key_mouse` | 100 | 26.4s |  |
| 425 | `focus_events_mouse_basic` | 260 | 42.1s |  |
| 426 | `focus_events_mouse_focusable` | 112 | 25.6s |  |
| 427 | `focus_events_mouse_same_object` | 40 | 25.9s |  |
| 428 | `focus_remove` | 20 | 25.9s |  |
| 429 | `focus_root_movie` | 4 | 25.3s |  |
| 430 | `focus_stage` | 1 | 6.3s |  |
| 431 | `focusrect` | 18 | 7.2s |  |
| 432 | `focusrect_focuslost` | 9 | 6.5s |  |
| 433 | `focusrect_property` | 110 | 25.6s |  |
| 434 | `font_description_clone` | 14 | 6.5s |  |
| 435 | `font_embedded` | 24 | 6.7s |  |
| 436 | `font_enumeratefonts` | 41 | 7.0s |  |
| 437 | `font_enumeratefonts_filter` | 4 | 26.1s |  |
| 438 | `font_enumeratefonts_order` | 9 | 7.8s |  |
| 439 | `font_hasglyphs` | 40 | 6.8s |  |
| 440 | `font_registerfont` | 129 | 7.5s |  |
| 441 | `framelabel_constr` | 5 | 6.7s |  |
| 442 | `function_call` | 12 | 6.5s |  |
| 443 | `function_call_arguments` | 46 | 6.6s |  |
| 444 | `function_call_arguments_enumerate` | 5 | 6.4s |  |
| 445 | `function_call_coercion` | 108 | 6.8s |  |
| 446 | `function_call_default` | 6 | 6.4s |  |
| 447 | `function_call_rest` | 22 | 6.4s |  |
| 448 | `function_call_types` | 3 | 6.4s |  |
| 449 | `function_call_via_apply` | 11 | 6.4s |  |
| 450 | `function_call_via_call` | 3 | 6.3s |  |
| 451 | `function_display_anonymous` | 7 | 2.4s |  |
| 452 | `function_length` | 6 | 6.4s |  |
| 453 | `function_object` | 2 | 6.3s |  |
| 454 | `function_proto` | 5 | 6.3s |  |
| 455 | `function_proto_created` | 61 | 6.4s |  |
| 456 | `function_to_locale_string` | 4 | 6.3s |  |
| 457 | `function_to_string` | 4 | 6.2s |  |
| 458 | `function_type` | 6 | 6.3s |  |
| 459 | `function_unbound_this` | 51 | 6.5s |  |
| 460 | `function_value_of` | 4 | 6.3s |  |
| 461 | `game_input` | 4 | 6.4s |  |
| 462 | `generate_random_bytes` | 3 | 6.4s |  |
| 463 | `get_definition_by_name` | 11 | 6.4s |  |
| 464 | `get_qualified_class_name` | 20 | 22.6s |  |
| 465 | `get_qualified_super_class_name` | 18 | 6.3s |  |
| 466 | `get_slot_edge_cases` | 1 | 24.6s |  |
| 467 | `get_timer` | 2 | 6.3s |  |
| 468 | `getglobalslot` | 1 | 6.2s |  |
| 469 | `getouterscope` | 8 | 6.2s |  |
| 470 | `getouterscope_two_classobjects` | 13 | 6.2s |  |
| 471 | `getter_different_namespace_setter` | 2 | 6.0s |  |
| 472 | `glow_filter` | 127 | 6.4s |  |
| 473 | `goto_button_nested_framescript` | 28 | 25.3s |  |
| 474 | `goto_in_constructframe` | 12 | 25.1s |  |
| 475 | `goto_in_scene_last_frame` | 2 | 24.8s |  |
| 476 | `goto_methods` | 56 | 6.5s |  |
| 477 | `goto_methods_swfver10` | 8 | 6.3s |  |
| 478 | `goto_nested_construct_sibling` | 18 | 6.8s |  |
| 479 | `goto_nested_framescript` | 9 | 6.5s |  |
| 480 | `goto_on_orphan` | 15 | 6.5s |  |
| 481 | `gradient_bevel_filter` | 206 | 6.4s |  |
| 482 | `gradient_glow_filter` | 206 | 6.3s |  |
| 483 | `graphics_bad_direct_commands` | 5 | 6.9s |  |
| 484 | `graphics_bitmap_fill` | 0 | 26.6s |  |
| 485 | `graphics_bitmaps` | 0 | 6.6s |  |
| 486 | `graphics_direct_commands` | 0 | 6.5s |  |
| 487 | `graphics_draw_triangles` | 98 | 25.8s |  |
| 488 | `graphics_gradients` | 0 | 6.3s |  |
| 489 | `graphics_gradients_nulls` | 0 | 6.3s |  |
| 490 | `graphics_path` | 56 | 6.4s |  |
| 491 | `graphics_round_rects` | 0 | 6.3s |  |
| 492 | `graphics_simple_shapes` | 0 | 6.3s |  |
| 493 | `greaterequals` | 512 | 10.1s |  |
| 494 | `greaterthan` | 512 | 10.2s |  |
| 495 | `has_own_property` | 102 | 6.8s |  |
| 496 | `hasownproperty_namespaces` | 2 | 6.2s |  |
| 497 | `hello_world` | 1 | 6.3s |  |
| 498 | `hittest_morph` | 30 | 6.5s |  |
| 499 | `if_eq` | 10 | 6.3s |  |
| 500 | `if_gt` | 1 | 22.9s |  |
| 501 | `if_gte` | 10 | 6.4s |  |
| 502 | `if_lt` | 1 | 0.6s |  |
| 503 | `if_lte` | 10 | 6.2s |  |
| 504 | `if_ne` | 7 | 2.4s |  |
| 505 | `if_stricteq` | 6 | 6.5s |  |
| 506 | `if_strictne` | 11 | 6.5s |  |
| 507 | `ime_linux_dead_keys` | 10 | 25.9s |  |
| 508 | `in` | 102 | 6.9s |  |
| 509 | `inclocal` | 46 | 6.5s |  |
| 510 | `inclocal_i` | 46 | 6.4s |  |
| 511 | `increment` | 46 | 6.4s |  |
| 512 | `increment_i` | 46 | 6.4s |  |
| 513 | `indexing_delete` | 75 | 6.4s |  |
| 514 | `instanceof` | 58 | 6.6s |  |
| 515 | `instantiate_root_character` | 4 | 6.6s |  |
| 516 | `instantiation_on_enter_frame` | 7 | 25.1s |  |
| 517 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.3s |  |
| 518 | `int_constr` | 92 | 6.5s |  |
| 519 | `int_edge_cases` | 19 | 6.4s |  |
| 520 | `int_instanceof` | 3 | 6.2s |  |
| 521 | `int_tofixed` | 1215 | 6.2s |  |
| 522 | `int_tostring` | 3375 | 6.7s |  |
| 523 | `interactiveobject_enabled` | 25 | 6.3s |  |
| 524 | `interface_namespaces` | 78 | 6.5s |  |
| 525 | `invalid_utf8` | 12 | 6.4s |  |
| 526 | `is_finite` | 46 | 6.4s |  |
| 527 | `is_nan` | 46 | 6.2s |  |
| 528 | `is_prototype_of` | 12 | 6.4s |  |
| 529 | `issue_10221` | 2 | 6.3s |  |
| 530 | `issue_13780` | 12 | 6.4s |  |
| 531 | `issue_14901` | 1 | 6.3s |  |
| 532 | `issue_17675_edittext_paste_maxchars` | 1 | 6.4s |  |
| 533 | `issue_5292` | 5 | 6.4s |  |
| 534 | `issue_8630` | 2 | 25.0s |  |
| 535 | `issue_8630_placeremoveplace` | 15 | 6.5s |  |
| 536 | `issue_8630_placeremoveplace_scriptremove` | 16 | 6.3s |  |
| 537 | `issue_8630_scriptremove` | 11 | 6.3s |  |
| 538 | `istype` | 24 | 2.4s |  |
| 539 | `istypelate` | 58 | 23.1s |  |
| 540 | `istypelate_coerce` | 198 | 7.4s |  |
| 541 | `jpeg_loader_context` | 6 | 25.1s |  |
| 542 | `json_errors` | 9 | 25.1s |  |
| 543 | `json_parse` | 21 | 6.3s |  |
| 544 | `json_stringify` | 12 | 6.5s |  |
| 545 | `json_stringify_order` | 1 | 6.4s |  |
| 546 | `json_version_gated` | 1 | 6.4s |  |
| 547 | `key_input_80percent` | 1812 | 6.6s |  |
| 548 | `key_input_location` | 126 | 6.5s |  |
| 549 | `key_input_numpad` | 384 | 6.4s |  |
| 550 | `lazyinit` | 17 | 6.4s |  |
| 551 | `lessequals` | 512 | 10.6s |  |
| 552 | `lessthan` | 512 | 10.4s |  |
| 553 | `loader_bitmap_transparency` | 14 | 6.5s |  |
| 554 | `loader_bytes_unknown_content` | 14 | 6.4s |  |
| 555 | `loader_child_getdefinition` | 5 | 6.5s |  |
| 556 | `loader_duplicate_coerce` | 3 | 6.5s |  |
| 557 | `loader_duplicate_coerce_new_domain` | 4 | 6.4s |  |
| 558 | `loader_error_in_root_ctor` | 4 | 6.6s |  |
| 559 | `loader_events` | 92 | 6.8s |  |
| 560 | `loader_image` | 8 | 6.5s |  |
| 561 | `loader_jpegxr` | 2 | 25.3s |  |
| 562 | `loader_jpegxr_alpha` | 1 | 25.2s |  |
| 563 | `loader_loadbytes_events` | 30 | 6.8s |  |
| 564 | `loader_loadbytes_invalid_png` | 4 | 25.2s |  |
| 565 | `loader_loadbytes_url` | 12 | 6.7s |  |
| 566 | `loader_loaderurl` | 6 | 6.8s |  |
| 567 | `loader_method` | 85 | 6.4s |  |
| 568 | `loader_noninteractive_try_click_root` | 5 | 25.5s |  |
| 569 | `loader_reuse` | 38 | 6.6s |  |
| 570 | `loader_unknown_content` | 24 | 6.5s |  |
| 571 | `loader_visibility_interactive` | 1 | 6.4s |  |
| 572 | `loaderinfo_events` | 7 | 40.7s |  |
| 573 | `loaderinfo_loadurl` | 12 | 24.6s |  |
| 574 | `loaderinfo_more` | 6 | 6.5s |  |
| 575 | `loaderinfo_properties` | 18 | 6.2s |  |
| 576 | `loaderinfo_properties_not_loaded` | 23 | 6.4s |  |
| 577 | `loaderinfo_root` | 10 | 6.2s |  |
| 578 | `loaderinfo_root_allows` | 2 | 6.1s |  |
| 579 | `localconnection_send` | 4 | 6.2s |  |
| 580 | `lshift` | 1058 | 18.0s |  |
| 581 | `mask_reapply` | 1 | 6.3s |  |
| 582 | `math` | 497 | 6.4s |  |
| 583 | `matrix3d` | 57 | 6.9s |  |
| 584 | `matrix3d_compose` | 34 | 6.4s |  |
| 585 | `matrix3d_invert` | 18 | 6.2s |  |
| 586 | `method_without_body` | 3 | 24.3s |  |
| 587 | `missing_external_interface` | 10 | 6.2s |  |
| 588 | `modulo` | 1058 | 17.9s |  |
| 589 | `morph_shape` | 2 | 24.5s |  |
| 590 | `mouse_children` | 192 | 24.6s |  |
| 591 | `mouse_click_events` | 90 | 24.6s |  |
| 592 | `mouse_double_click_events` | 188 | 6.3s |  |
| 593 | `mouse_empty_parent` | 4 | 6.2s |  |
| 594 | `mouse_over_while_dragging` | 3 | 6.4s |  |
| 595 | `mouse_pick_button_mode` | 2 | 6.3s |  |
| 596 | `mouse_pick_dobj_mask` | 4 | 6.3s |  |
| 597 | `mouse_pick_masking` | 7 | 24.6s |  |
| 598 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 24.5s |  |
| 599 | `mouse_pick_non_interactive_dobj_mask` | 3 | 6.3s |  |
| 600 | `mouse_pick_text` | 8 | 6.4s |  |
| 601 | `mouse_sibling` | 8 | 6.2s |  |
| 602 | `mouse_wheel_events` | 36 | 25.6s |  |
| 603 | `mouseevent_constr` | 66 | 6.2s |  |
| 604 | `mouseevent_stagexy` | 35 | 6.2s |  |
| 605 | `mouseevent_valueof_tostring` | 28 | 6.2s |  |
| 606 | `movieclip_addframescript` | 3 | 24.5s |  |
| 607 | `movieclip_child_property` | 16 | 24.4s |  |
| 608 | `movieclip_constr` | 21 | 6.9s |  |
| 609 | `movieclip_currentlabels` | 17 | 27.8s |  |
| 610 | `movieclip_currentlabels_dupes1` | 46 | 27.8s |  |
| 611 | `movieclip_currentlabels_dupes2` | 30 | 6.8s |  |
| 612 | `movieclip_currentlabels_dupes3` | 67 | 6.8s |  |
| 613 | `movieclip_currentscene` | 12 | 27.7s |  |
| 614 | `movieclip_dispatchevent` | 430 | 7.0s |  |
| 615 | `movieclip_dispatchevent_cancel` | 102 | 6.9s |  |
| 616 | `movieclip_dispatchevent_handlerorder` | 251 | 6.8s |  |
| 617 | `movieclip_dispatchevent_selfadd` | 80 | 6.7s |  |
| 618 | `movieclip_dispatchevent_target` | 899 | 6.8s |  |
| 619 | `movieclip_displayevents` | 96 | 27.5s |  |
| 620 | `movieclip_displayevents_clickgoto` | 676 | 27.9s |  |
| 621 | `movieclip_displayevents_clickgoto2` | 2001 | 7.3s |  |
| 622 | `movieclip_displayevents_clickplay` | 575 | 6.9s |  |
| 623 | `movieclip_displayevents_clicksymbol` | 562 | 7.0s |  |
| 624 | `movieclip_displayevents_constructframegoto` | 140 | 7.2s |  |
| 625 | `movieclip_displayevents_constructframeplay` | 50 | 7.0s |  |
| 626 | `movieclip_displayevents_constructframesymbol` | 144 | 7.0s |  |
| 627 | `movieclip_displayevents_dblhandler` | 21 | 7.0s |  |
| 628 | `movieclip_displayevents_enterframegoto` | 149 | 7.0s |  |
| 629 | `movieclip_displayevents_enterframeplay` | 48 | 6.9s |  |
| 630 | `movieclip_displayevents_enterframesymbol` | 149 | 27.3s |  |
| 631 | `movieclip_displayevents_exitframegoto` | 106 | 6.8s |  |
| 632 | `movieclip_displayevents_exitframeplay` | 44 | 6.8s |  |
| 633 | `movieclip_displayevents_exitframesymbol` | 135 | 6.9s |  |
| 634 | `movieclip_displayevents_looping` | 63 | 27.4s |  |
| 635 | `movieclip_displayevents_stopped` | 113 | 7.2s |  |
| 636 | `movieclip_displayevents_swap` | 96 | 2.4s |  |
| 637 | `movieclip_displayevents_timeline` | 128 | 27.5s |  |
| 638 | `movieclip_drawrect` | 54 | 6.8s |  |
| 639 | `movieclip_frameconstruct_skipped` | 9 | 6.9s |  |
| 640 | `movieclip_goto_during_frame_script` | 15 | 6.8s |  |
| 641 | `movieclip_goto_overwrite` | 14 | 27.2s |  |
| 642 | `movieclip_goto_scene_last_frame_int` | 1 | 27.4s |  |
| 643 | `movieclip_goto_scene_last_frame_label` | 1 | 6.6s |  |
| 644 | `movieclip_gotoandplay` | 15 | 27.0s |  |
| 645 | `movieclip_gotoandstop` | 13 | 26.9s |  |
| 646 | `movieclip_gotoandstop_children` | 4 | 6.8s |  |
| 647 | `movieclip_gotoandstop_framescripts1` | 4 | 6.7s |  |
| 648 | `movieclip_gotoandstop_framescripts2` | 4 | 22.9s |  |
| 649 | `movieclip_gotoandstop_framescripts_self` | 7 | 24.7s |  |
| 650 | `movieclip_gotoandstop_queueing` | 12 | 24.9s |  |
| 651 | `movieclip_hittest` | 67 | 6.5s |  |
| 652 | `movieclip_next_frame` | 2 | 24.6s |  |
| 653 | `movieclip_next_scene` | 6 | 24.6s |  |
| 654 | `movieclip_play` | 3 | 6.2s |  |
| 655 | `movieclip_prev_frame` | 3 | 5.9s |  |
| 656 | `movieclip_prev_scene` | 7 | 6.3s |  |
| 657 | `movieclip_properties` | 79 | 24.8s |  |
| 658 | `movieclip_queued_noop_goto_swf10` | 9 | 6.3s |  |
| 659 | `movieclip_queued_noop_goto_swf9` | 7 | 0.6s |  |
| 660 | `movieclip_scenes` | 11 | 6.2s |  |
| 661 | `movieclip_soundtransform` | 831 | 26.6s |  |
| 662 | `movieclip_stop` | 1 | 24.4s |  |
| 663 | `movieclip_super_is_symbol` | 20 | 6.6s |  |
| 664 | `movieclip_symbol_constr` | 8 | 6.3s |  |
| 665 | `movieclip_text_mousedown` | 1 | 6.3s |  |
| 666 | `movieclip_willtrigger` | 5 | 6.5s |  |
| 667 | `multiply` | 1058 | 18.3s |  |
| 668 | `namespace_constr` | 253 | 6.6s |  |
| 669 | `namespace_constr_args` | 1 | 6.3s |  |
| 670 | `namespace_enumeration_order` | 7 | 25.2s |  |
| 671 | `nan_scale` | 9 | 6.3s |  |
| 672 | `navigateToURL_target_normalize` | 107 | 26.5s |  |
| 673 | `negate` | 30 | 6.3s |  |
| 674 | `negative_volume_panned` | 0 | 6.5s |  |
| 675 | `nested_iteration` | 11 | 6.3s |  |
| 676 | `net_getClassByAlias` | 3 | 6.3s |  |
| 677 | `net_navigateToURL` | 57 | 6.3s |  |
| 678 | `net_stream_play_options` | 6 | 6.3s |  |
| 679 | `netconnection_close` | 55 | 6.3s |  |
| 680 | `netconnection_properties` | 78 | 6.4s |  |
| 681 | `netconnection_send_remote` | 50 | 6.6s |  |
| 682 | `netconnection_serialize_arrays` | 6 | 6.4s |  |
| 683 | `netstream_client` | 10 | 6.4s |  |
| 684 | `netstream_connect` | 7 | 6.2s |  |
| 685 | `newactivation_in_script_init` | 3 | 6.9s |  |
| 686 | `newclass_mismatched` | 4 | 6.7s |  |
| 687 | `newclass_twice` | 3 | 6.7s |  |
| 688 | `nonconflicting_declarations` | 0 | 6.8s |  |
| 689 | `null_void_types` | 8 | 6.7s |  |
| 690 | `number_autoconv` | 21 | 6.8s |  |
| 691 | `number_autoconv_amf` | 132 | 6.8s |  |
| 692 | `number_autoconv_array_sort_32bit` | 1 | 6.7s |  |
| 693 | `number_constr` | 58 | 6.8s |  |
| 694 | `number_toexponential` | 378 | 6.7s |  |
| 695 | `number_toexponential2` | 35 | 6.6s |  |
| 696 | `number_tofixed` | 378 | 6.6s |  |
| 697 | `number_toprecision` | 350 | 6.7s |  |
| 698 | `obfuscated_class_names` | 3 | 6.6s |  |
| 699 | `object_enumeration` | 10 | 6.6s |  |
| 700 | `object_prototype` | 4 | 6.8s |  |
| 701 | `object_to_locale_string` | 2 | 6.6s |  |
| 702 | `object_to_string` | 2 | 6.6s |  |
| 703 | `object_value_of` | 2 | 2.2s |  |
| 704 | `op_coerce` | 54 | 6.7s |  |
| 705 | `op_coerce_x` | 54 | 6.7s |  |
| 706 | `op_escxattr` | 2 | 6.6s |  |
| 707 | `op_escxelem` | 2 | 6.6s |  |
| 708 | `op_lookupswitch` | 4 | 6.7s |  |
| 709 | `optimize_coerce` | 1 | 6.6s |  |
| 710 | `orphan_movie_complex` | 80 | 7.0s |  |
| 711 | `orphan_movie_reorder` | 111 | 26.8s |  |
| 712 | `package_namespace` | 7 | 6.5s |  |
| 713 | `param_default_value_has_zero_cpool_index` | 1 | 6.6s |  |
| 714 | `parent_early_access_child` | 16 | 26.6s |  |
| 715 | `parse_float` | 81 | 6.9s |  |
| 716 | `parse_float_swf10` | 81 | 6.6s |  |
| 717 | `parse_int` | 135 | 7.2s |  |
| 718 | `perspective_projection_basic` | 40 | 6.7s |  |
| 719 | `pixelbender_ceil` | 77 | 41.1s |  |
| 720 | `pixelbender_conditional` | 138 | 6.6s |  |
| 721 | `pixelbender_conversions` | 270 | 6.7s |  |
| 722 | `pixelbender_dithering` | 8 | 29.4s |  |
| 723 | `pixelbender_div` | 36 | 6.5s |  |
| 724 | `pixelbender_effect_BlurredFocus` | 0 | 32.3s |  |
| 725 | `pixelbender_effect_glassDisplace` | 0 | 11.8s |  |
| 726 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 28.0s |  |
| 727 | `pixelbender_effect_smudge` | 0 | 9.5s |  |
| 728 | `pixelbender_effect_tintype` | 0 | 8.7s |  |
| 729 | `pixelbender_effect_twirl` | 0 | 10.1s |  |
| 730 | `pixelbender_eof` | 7 | 6.3s |  |
| 731 | `pixelbender_images` | 0 | 8.4s |  |
| 732 | `pixelbender_input` | 103 | 25.4s |  |
| 733 | `pixelbender_logicalnot` | 20 | 6.3s |  |
| 734 | `pixelbender_malformed_data` | 190 | 25.4s |  |
| 735 | `pixelbender_multiple_out_params` | 1 | 6.2s |  |
| 736 | `pixelbender_no_out_param` | 6 | 6.2s |  |
| 737 | `pixelbender_outputs` | 13 | 6.5s |  |
| 738 | `pixelbender_padding_bytes` | 22 | 6.3s |  |
| 739 | `pixelbender_param_qualifier` | 512 | 6.4s |  |
| 740 | `pixelbender_parameters` | 1563 | 6.6s |  |
| 741 | `pixelbender_parameters_bool` | 240 | 6.5s |  |
| 742 | `pixelbender_parameters_int_vs_bool` | 54 | 6.4s |  |
| 743 | `pixelbender_parse_errors` | 6 | 6.4s |  |
| 744 | `pixelbender_rsqrt` | 24 | 6.4s |  |
| 745 | `pixelbender_select_kinds` | 8 | 6.5s |  |
| 746 | `pixelbender_shaderdata` | 49 | 6.4s |  |
| 747 | `pixelbender_shaderdata_setter` | 99 | 6.7s |  |
| 748 | `pixelbender_sign` | 60 | 6.5s |  |
| 749 | `pixelbender_vector_output` | 11 | 6.6s |  |
| 750 | `place_and_lookup/swf10` | 33 | 6.4s |  |
| 751 | `place_and_lookup/swf9` | 33 | 0.6s |  |
| 752 | `place_multiple` | 17 | 24.9s |  |
| 753 | `place_object_replace` | 9 | 6.5s |  |
| 754 | `place_object_replace_2` | 24 | 6.5s |  |
| 755 | `place_object_same_depth_frame` | 1 | 6.4s |  |
| 756 | `point` | 132 | 6.9s |  |
| 757 | `primitive_edge_cases` | 1 | 6.3s |  |
| 758 | `print_job_options` | 3 | 41.7s |  |
| 759 | `property_is_enumerable_reset` | 23 | 6.4s |  |
| 760 | `property_priority` | 22 | 6.7s |  |
| 761 | `property_priority_chained` | 4 | 6.2s |  |
| 762 | `property_priority_definition_names_order` | 2 | 6.5s |  |
| 763 | `property_priority_three_level` | 6 | 24.8s |  |
| 764 | `propertyisenumerable_namespaces` | 6 | 6.3s |  |
| 765 | `prototype_set_null` | 7 | 6.3s |  |
| 766 | `proxy_callproperty` | 24 | 6.3s |  |
| 767 | `proxy_deleteproperty` | 64 | 6.3s |  |
| 768 | `proxy_enumeration` | 34 | 6.3s |  |
| 769 | `proxy_getproperty` | 77 | 6.3s |  |
| 770 | `proxy_hasownproperty` | 8 | 6.2s |  |
| 771 | `proxy_hasproperty` | 32 | 6.4s |  |
| 772 | `proxy_serialize` | 9 | 6.3s |  |
| 773 | `proxy_setproperty` | 42 | 6.3s |  |
| 774 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.2s |  |
| 775 | `qname_constr` | 32 | 6.3s |  |
| 776 | `qname_constr_namespace` | 24 | 6.3s |  |
| 777 | `qname_enumeration` | 9 | 6.3s |  |
| 778 | `qname_indexing` | 23 | 6.3s |  |
| 779 | `qname_tostring` | 25 | 6.3s |  |
| 780 | `qname_valueof` | 29 | 6.3s |  |
| 781 | `rectangle` | 1094 | 7.0s |  |
| 782 | `regexp_constr` | 148 | 6.5s |  |
| 783 | `regexp_exec` | 19 | 6.3s |  |
| 784 | `regexp_extended` | 47 | 6.2s |  |
| 785 | `regexp_multiargs` | 1 | 6.2s |  |
| 786 | `regexp_test` | 27 | 6.3s |  |
| 787 | `regexp_toString` | 10 | 6.3s |  |
| 788 | `register_script_refresh` | 35 | 25.3s |  |
| 789 | `remove_child_clear_field` | 88 | 6.6s |  |
| 790 | `remove_dobj` | 3 | 6.3s |  |
| 791 | `resolve_order` | 4 | 6.3s |  |
| 792 | `responder_null_callbacks` | 1 | 6.2s |  |
| 793 | `rng` | 1 | 7.5s |  |
| 794 | `rootless` | 42 | 6.5s |  |
| 795 | `rshift` | 1058 | 18.2s |  |
| 796 | `rtqname_not_namespace` | 12 | 6.3s |  |
| 797 | `sandbox_type_inherited` | 2 | 22.7s |  |
| 798 | `sandbox_type_local_file` | 1 | 24.8s |  |
| 799 | `sandbox_type_local_network` | 1 | 6.0s |  |
| 800 | `scene_constr` | 8 | 6.4s |  |
| 801 | `scopes_dont_cache/order-1` | 1 | 24.1s |  |
| 802 | `scopes_dont_cache/order-2` | 1 | 0.4s |  |
| 803 | `security_domain_current` | 2 | 6.2s |  |
| 804 | `selection` | 239 | 6.6s |  |
| 805 | `set_local_0` | 31 | 6.2s |  |
| 806 | `set_property_is_enumerable` | 85 | 6.6s |  |
| 807 | `shaderparameter_value` | 4 | 6.3s |  |
| 808 | `shape_drawrect` | 54 | 6.2s |  |
| 809 | `shared_object_no_root` | 3 | 6.1s |  |
| 810 | `simplebutton_added_to_stage` | 45 | 24.4s |  |
| 811 | `simplebutton_childevents` | 86 | 25.3s |  |
| 812 | `simplebutton_childevents_nested` | 54 | 6.5s |  |
| 813 | `simplebutton_childevents_sprite` | 13 | 6.3s |  |
| 814 | `simplebutton_childprops` | 144 | 6.5s |  |
| 815 | `simplebutton_childshuffle` | 23 | 6.2s |  |
| 816 | `simplebutton_constr` | 36 | 6.4s |  |
| 817 | `simplebutton_constr_childevents` | 48 | 6.5s |  |
| 818 | `simplebutton_constr_params` | 42 | 6.4s |  |
| 819 | `simplebutton_mouseenabled` | 26 | 6.2s |  |
| 820 | `simplebutton_multi_children` | 19 | 6.4s |  |
| 821 | `simplebutton_structure` | 27 | 6.5s |  |
| 822 | `simplebutton_symbolclass` | 68 | 6.7s |  |
| 823 | `slot_disp_id_shared_numbering` | 1 | 24.6s |  |
| 824 | `slots_force_autoassigned` | 1 | 6.3s |  |
| 825 | `socket_after_disconnect` | 1 | 6.4s |  |
| 826 | `socket_close` | 2 | 6.2s |  |
| 827 | `socket_connect` | 4 | 6.2s |  |
| 828 | `socket_errors` | 56 | 6.8s |  |
| 829 | `socket_read_big` | 48 | 6.3s |  |
| 830 | `socket_read_little` | 48 | 41.5s |  |
| 831 | `socket_read_write_object` | 8 | 6.3s |  |
| 832 | `socket_write_big` | 15 | 6.7s |  |
| 833 | `socket_write_little` | 14 | 6.3s |  |
| 834 | `sound_embeddedprops` | 26 | 6.7s |  |
| 835 | `sound_play` | 19 | 6.6s |  |
| 836 | `sound_valueof` | 33 | 6.4s |  |
| 837 | `soundchannel_soundtransform` | 835 | 27.0s |  |
| 838 | `soundchannel_soundtransform_exists` | 5 | 25.0s |  |
| 839 | `soundchannel_stop` | 8 | 25.2s |  |
| 840 | `soundmixer_buffertime` | 5 | 6.3s |  |
| 841 | `soundmixer_stopall` | 6 | 24.9s |  |
| 842 | `soundtransform` | 442 | 12.0s |  |
| 843 | `space_justifier_clone` | 12 | 6.3s |  |
| 844 | `sprite_with_frames` | 0 | 25.3s |  |
| 845 | `stage3d_agal_cross_product` | 0 | 8.8s |  |
| 846 | `stage3d_agal_upload_errors` | 66 | 9.0s |  |
| 847 | `stage3d_bitmap` | 0 | 29.9s |  |
| 848 | `stage3d_blend` | 81 | 27.7s |  |
| 849 | `stage3d_context3d_string_args` | 158 | 7.3s |  |
| 850 | `stage3d_errors` | 7 | 6.4s |  |
| 851 | `stage3d_errors_atf` | 3 | 7.7s |  |
| 852 | `stage3d_errors_swf_29` | 6 | 6.5s |  |
| 853 | `stage3d_float1_index` | 0 | 27.5s |  |
| 854 | `stage3d_fractal` | 0 | 27.4s |  |
| 855 | `stage3d_ignore_sampler_override` | 0 | 27.6s |  |
| 856 | `stage3d_multistage_triangle` | 3 | 9.0s |  |
| 857 | `stage3d_program_constants_bytearray_be` | 0 | 29.1s |  |
| 858 | `stage3d_program_constants_bytearray_le` | 0 | 9.5s |  |
| 859 | `stage3d_program_constants_invalid_input` | 21 | 7.3s |  |
| 860 | `stage3d_raytrace` | 0 | 32.6s |  |
| 861 | `stage3d_rotating_cube` | 0 | 9.6s |  |
| 862 | `stage3d_sampler` | 0 | 8.8s |  |
| 863 | `stage3d_sampler_partial_upload` | 0 | 8.8s |  |
| 864 | `stage3d_stencil` | 0 | 44.2s |  |
| 865 | `stage3d_texture` | 0 | 14.2s |  |
| 866 | `stage3d_texture_bytearray` | 0 | 10.2s |  |
| 867 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.6s |  |
| 868 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.6s |  |
| 869 | `stage3d_triangle` | 0 | 8.9s |  |
| 870 | `stage3d_triangle_bytes4` | 0 | 8.9s |  |
| 871 | `stage3d_triangle_float1` | 0 | 8.8s |  |
| 872 | `stage3d_triangle_index_upload` | 0 | 8.8s |  |
| 873 | `stage3d_x_y` | 22 | 6.4s |  |
| 874 | `stage_access` | 10 | 6.3s |  |
| 875 | `stage_displayobject_properties` | 24 | 6.2s |  |
| 876 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.2s |  |
| 877 | `stage_framerate_nan` | 7 | 24.8s |  |
| 878 | `stage_framerate_negative` | 6 | 6.2s |  |
| 879 | `stage_framerate_zero` | 6 | 6.2s |  |
| 880 | `stage_invalidate` | 38 | 6.5s |  |
| 881 | `stage_loaderinfo_properties` | 24 | 25.2s |  |
| 882 | `stage_mousechildren` | 2 | 6.3s |  |
| 883 | `stage_mouseenabled` | 15 | 6.3s |  |
| 884 | `stage_overriden_setters` | 31 | 6.6s |  |
| 885 | `stage_properties` | 30 | 6.4s |  |
| 886 | `stage_stage3Ds_vector` | 1 | 24.8s |  |
| 887 | `static_text` | 3 | 6.4s |  |
| 888 | `static_var_with_this_in_ctor` | 2 | 6.3s |  |
| 889 | `statictext_text` | 8 | 6.4s |  |
| 890 | `stored_properties` | 11 | 6.3s |  |
| 891 | `strict_equality` | 34 | 6.4s |  |
| 892 | `string_call` | 13 | 6.4s |  |
| 893 | `string_case` | 23 | 6.3s |  |
| 894 | `string_char_at` | 27 | 6.3s |  |
| 895 | `string_char_code_at` | 28 | 6.2s |  |
| 896 | `string_concat_fromcharcode` | 37 | 6.2s |  |
| 897 | `string_constr` | 25 | 6.4s |  |
| 898 | `string_indexof_lastindexof` | 87 | 6.6s |  |
| 899 | `string_length` | 16 | 6.3s |  |
| 900 | `string_locale_compare` | 39 | 6.6s |  |
| 901 | `string_match` | 51 | 41.5s |  |
| 902 | `string_relational_compare` | 4 | 6.3s |  |
| 903 | `string_replace` | 51 | 6.4s |  |
| 904 | `string_search` | 41 | 6.5s |  |
| 905 | `string_slice_substr_substring` | 170 | 7.4s |  |
| 906 | `string_split` | 29 | 6.3s |  |
| 907 | `string_substr_negative` | 21 | 6.2s |  |
| 908 | `string_substr_weird` | 182 | 6.2s |  |
| 909 | `stylesheet` | 221 | 6.8s |  |
| 910 | `stylesheet_parse_color` | 69 | 6.2s |  |
| 911 | `stylesheet_transform` | 307 | 6.5s |  |
| 912 | `subclass_superclass_linked_symbol` | 4 | 6.7s |  |
| 913 | `subtract` | 1058 | 18.4s |  |
| 914 | `super_get_call` | 12 | 6.2s |  |
| 915 | `supercall_two_classobjects` | 2 | 6.3s |  |
| 916 | `supercalls_weird` | 2 | 6.1s |  |
| 917 | `superinterface_call` | 20 | 6.3s |  |
| 918 | `superinterface_instanceof` | 18 | 6.3s |  |
| 919 | `swf8` | 1 | 6.2s |  |
| 920 | `swf_10_queued_goto_scripts_construct` | 52 | 25.2s |  |
| 921 | `swf_9_goto_in_enter_frame` | 17 | 6.4s |  |
| 922 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.4s |  |
| 923 | `swf_9_queued_goto_scripts` | 6 | 25.1s |  |
| 924 | `swf_9_queued_goto_scripts_construct` | 28 | 0.6s |  |
| 925 | `swf_9_versioning` | 2 | 6.3s |  |
| 926 | `swf_wrong_frame_count` | 38 | 6.6s |  |
| 927 | `swf_wrong_frame_count_isplaying` | 22 | 24.7s |  |
| 928 | `symbol_class_binary_data` | 8 | 6.3s |  |
| 929 | `symbol_class_conflict` | 4 | 6.6s |  |
| 930 | `symbol_class_root_not_zero` | 1 | 6.2s |  |
| 931 | `symbolclass_invalid_utf8` | 2 | 6.3s |  |
| 932 | `system_setclipboard_null` | 1 | 6.2s |  |
| 933 | `tab_ordering_arrows` | 998 | 26.4s |  |
| 934 | `tab_ordering_automatic_advanced` | 184 | 7.0s |  |
| 935 | `tab_ordering_automatic_basic` | 45 | 6.5s |  |
| 936 | `tab_ordering_children` | 116 | 35.2s |  |
| 937 | `tab_ordering_custom_basic` | 34 | 5.1s |  |
| 938 | `tab_ordering_stage_tab_children` | 32 | 5.2s |  |
| 939 | `tab_ordering_stage_tab_children_remove_root` | 5 | 5.2s |  |
| 940 | `tab_ordering_tabbable` | 47 | 5.2s |  |
| 941 | `tabstop_properties` | 105 | 5.4s |  |
| 942 | `text_element_basic` | 34 | 5.2s |  |
| 943 | `text_engine_fontdescription` | 27 | 5.3s |  |
| 944 | `text_engine_groupelement` | 64 | 5.8s |  |
| 945 | `text_run` | 7 | 5.0s |  |
| 946 | `textblock_createline_errors` | 23 | 5.3s |  |
| 947 | `textblock_createline_fte` | 9 | 21.6s |  |
| 948 | `textblock_properties` | 118 | 5.6s |  |
| 949 | `textbox_click` | 37 | 21.1s |  |
| 950 | `textfield_event` | 66 | 5.3s |  |
| 951 | `textfield_focusin_event` | 9 | 5.0s |  |
| 952 | `textfield_input_dead_keys_windows` | 15 | 5.1s |  |
| 953 | `textfield_unload` | 39 | 20.8s |  |
| 954 | `textformat` | 1134 | 5.2s |  |
| 955 | `textformat_display` | 14 | 5.2s |  |
| 956 | `textformat_font_max_length` | 4 | 5.0s |  |
| 957 | `textline_inapplicable_properties` | 10 | 5.1s |  |
| 958 | `textline_name` | 1 | 5.0s |  |
| 959 | `textline_splitting_basic` | 76 | 5.2s |  |
| 960 | `textline_throwerror` | 30 | 5.1s |  |
| 961 | `textline_validity` | 162 | 5.3s |  |
| 962 | `throw` | 3 | 5.1s |  |
| 963 | `timeline_scripts` | 3 | 5.3s |  |
| 964 | `timer` | 90 | 5.6s |  |
| 965 | `timer_events` | 3 | 5.2s |  |
| 966 | `timer_finished` | 11 | 5.2s |  |
| 967 | `timer_reset` | 8 | 5.2s |  |
| 968 | `timer_setdelay` | 5 | 5.0s |  |
| 969 | `trace` | 12 | 5.0s |  |
| 970 | `truthiness` | 30 | 4.9s |  |
| 971 | `try_catch` | 11 | 22.7s |  |
| 972 | `try_catch_typed` | 12 | 6.1s |  |
| 973 | `typeof` | 30 | 6.1s |  |
| 974 | `uint_constr` | 92 | 6.3s |  |
| 975 | `uint_tofixed` | 1215 | 5.9s |  |
| 976 | `uint_tostring` | 3375 | 6.3s |  |
| 977 | `uncaught_error_basic` | 2 | 6.2s |  |
| 978 | `unchecked_function` | 15 | 6.2s |  |
| 979 | `unescape` | 28 | 6.2s |  |
| 980 | `url_loader` | 25 | 6.2s |  |
| 981 | `url_vars` | 27 | 6.2s |  |
| 982 | `urlrequest` | 18 | 24.6s |  |
| 983 | `urlstream_basic` | 5 | 6.0s |  |
| 984 | `urshift` | 1058 | 17.9s |  |
| 985 | `utils3d` | 7 | 6.0s |  |
| 986 | `vector3d` | 397 | 10.7s |  |
| 987 | `vector_class` | 36 | 6.5s |  |
| 988 | `vector_class_call` | 11 | 6.2s |  |
| 989 | `vector_coercion` | 66 | 6.9s |  |
| 990 | `vector_concat` | 90 | 6.7s |  |
| 991 | `vector_constr` | 107 | 6.8s |  |
| 992 | `vector_enumeration` | 5 | 6.2s |  |
| 993 | `vector_every` | 92 | 7.0s |  |
| 994 | `vector_filter` | 95 | 7.2s |  |
| 995 | `vector_holes` | 24 | 6.2s |  |
| 996 | `vector_indexof` | 302 | 10.8s |  |
| 997 | `vector_insertat` | 270 | 7.2s |  |
| 998 | `vector_int_access` | 4 | 6.1s |  |
| 999 | `vector_int_delete` | 11 | 6.1s |  |
| 1000 | `vector_join` | 58 | 6.6s |  |
| 1001 | `vector_lastindexof` | 302 | 6.1s |  |
| 1002 | `vector_legacy` | 10 | 6.1s |  |
| 1003 | `vector_map` | 85 | 6.7s |  |
| 1004 | `vector_object_final` | 1 | 5.9s |  |
| 1005 | `vector_object_toString` | 10 | 6.0s |  |
| 1006 | `vector_pushpop` | 255 | 7.3s |  |
| 1007 | `vector_reborrow_bug` | 10 | 6.2s |  |
| 1008 | `vector_removeat` | 172 | 25.2s |  |
| 1009 | `vector_reverse` | 232 | 8.0s |  |
| 1010 | `vector_shiftunshift` | 252 | 8.2s |  |
| 1011 | `vector_slice` | 331 | 8.6s |  |
| 1012 | `vector_sort` | 905 | 16.8s |  |
| 1013 | `vector_splice` | 693 | 11.1s |  |
| 1014 | `vector_splice_fixed_bug_compat` | 4 | 27.5s |  |
| 1015 | `vector_tostring` | 79 | 7.4s |  |
| 1016 | `verification` | 8 | 6.8s |  |
| 1017 | `verify_abnormal_loop` | 1 | 6.6s |  |
| 1018 | `verify_dxns_without_flag` | 3 | 7.1s |  |
| 1019 | `verify_exception_target_two_jumps` | 1 | 6.6s |  |
| 1020 | `verify_exception_targets_edge_case` | 1 | 6.7s |  |
| 1021 | `verify_illegal_opcode` | 1 | 2.8s |  |
| 1022 | `verify_jump_to_middle_of_op` | 1 | 6.6s |  |
| 1023 | `verify_lookup_switch_edge_case` | 1 | 6.6s |  |
| 1024 | `verify_method_info_oob` | 1 | 0.6s |  |
| 1025 | `verify_stack` | 5 | 6.8s |  |
| 1026 | `verify_typecheck` | 4 | 6.8s |  |
| 1027 | `verify_unreachable_exception` | 2 | 6.6s |  |
| 1028 | `versioned_isplaying` | 2 | 6.8s |  |
| 1029 | `virtual_properties` | 16 | 6.8s |  |
| 1030 | `with` | 4 | 6.7s |  |
| 1031 | `wrong_arg_count` | 7 | 6.9s |  |
| 1032 | `xml_abstract_equality` | 36 | 7.1s |  |
| 1033 | `xml_advanced` | 52 | 6.8s |  |
| 1034 | `xml_appendchild` | 10 | 6.7s |  |
| 1035 | `xml_appendchild_swf_v21` | 13 | 7.1s |  |
| 1036 | `xml_as_attribute` | 9 | 6.7s |  |
| 1037 | `xml_attribute` | 35 | 6.8s |  |
| 1038 | `xml_attribute_name` | 40 | 6.7s |  |
| 1039 | `xml_basic` | 33 | 6.7s |  |
| 1040 | `xml_child` | 25 | 6.7s |  |
| 1041 | `xml_childindex` | 7 | 6.6s |  |
| 1042 | `xml_children` | 43 | 7.3s |  |
| 1043 | `xml_class_call` | 9 | 6.6s |  |
| 1044 | `xml_contains` | 197 | 6.8s |  |
| 1045 | `xml_copy` | 20 | 2.6s |  |
| 1046 | `xml_ctor_from_tostring` | 23 | 23.5s |  |
| 1047 | `xml_delete` | 114 | 6.6s |  |
| 1048 | `xml_descendants` | 83 | 25.4s |  |
| 1049 | `xml_elements` | 6 | 6.4s |  |
| 1050 | `xml_equals_namespace_check` | 2 | 6.5s |  |
| 1051 | `xml_explicit_use_namespace` | 5 | 6.5s |  |
| 1052 | `xml_getdescendants_qname` | 21 | 6.5s |  |
| 1053 | `xml_has_property_via_in` | 26 | 6.6s |  |
| 1054 | `xml_hasownproperty` | 6 | 6.4s |  |
| 1055 | `xml_ignore_white` | 6 | 6.5s |  |
| 1056 | `xml_length` | 2 | 6.5s |  |
| 1057 | `xml_list_as_attribute` | 9 | 6.4s |  |
| 1058 | `xml_list_concat` | 20 | 6.5s |  |
| 1059 | `xml_list_delete_clear_parent` | 6 | 6.4s |  |
| 1060 | `xml_list_enumerate` | 4 | 6.3s |  |
| 1061 | `xml_methods_settings` | 3 | 6.4s |  |
| 1062 | `xml_mismatched_tag` | 37 | 6.5s |  |
| 1063 | `xml_namespace` | 39 | 6.5s |  |
| 1064 | `xml_namespace_methods` | 245 | 6.5s |  |
| 1065 | `xml_namespaced_property` | 7 | 6.4s |  |
| 1066 | `xml_no_namespace` | 1 | 6.4s |  |
| 1067 | `xml_nodekind` | 3 | 6.4s |  |
| 1068 | `xml_normalize` | 35 | 6.5s |  |
| 1069 | `xml_notification_bubbling` | 361 | 6.5s |  |
| 1070 | `xml_parent` | 8 | 6.4s |  |
| 1071 | `xml_set_children` | 17 | 6.5s |  |
| 1072 | `xml_set_name` | 34 | 6.5s |  |
| 1073 | `xml_settings` | 6 | 2.3s |  |
| 1074 | `xml_simple_complex_content` | 47 | 6.5s |  |
| 1075 | `xml_socket` | 11 | 6.7s |  |
| 1076 | `xml_text` | 7 | 6.4s |  |
| 1077 | `xml_tostring` | 6 | 6.4s |  |
| 1078 | `xml_tostring_namespace` | 12 | 6.4s |  |
| 1079 | `xml_unescaping` | 23 | 6.5s |  |
| 1080 | `xml_weird_ignores` | 54 | 6.5s |  |
| 1081 | `xml_wildcard` | 11 | 6.4s |  |
| 1082 | `xmldocument` | 254 | 6.5s |  |
| 1083 | `xmlnode` | 3540 | 6.6s |  |
| 1084 | `zero_frame_clip` | 3 | 6.8s |  |

## Ruffle-Matched Tests

**27 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 6.2s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 24.7s |  |
| 3 | `blend_transform` | 1 | 1 | 6.3s |  |
| 4 | `coerce_property` | 3 | 3 | 6.1s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.0s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 25.9s |  |
| 7 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.8s |  |
| 8 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 42.0s |  |
| 9 | `edittext_tab_stops` | 6 | 6 | 6.6s |  |
| 10 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.4s |  |
| 11 | `error_1034_debug_string` | 19 | 19 | 6.4s |  |
| 12 | `freestanding_superclass` | 2 | 4 | 6.5s |  |
| 13 | `goto_framescript_queued` | 5 | 5 | 24.9s |  |
| 14 | `graphics_draw_path` | 50 | 50 | 25.9s |  |
| 15 | `int_toexponential` | 76 | 76 | 6.5s |  |
| 16 | `int_toprecision` | 441 | 441 | 6.5s |  |
| 17 | `simplebutton_childevents_script_order` | 4 | 4 | 6.5s |  |
| 18 | `slot_holes_fail` | 1 | 1 | 6.2s |  |
| 19 | `slot_id_exceeds_trait_count` | 1 | 1 | 24.4s |  |
| 20 | `soundchannel_position` | 74 | 74 | 25.9s |  |
| 21 | `soundchannel_soundcomplete` | 10 | 10 | 6.7s |  |
| 22 | `sprite_dropTarget` | 15 | 15 | 6.4s |  |
| 23 | `swf_9_goto_in_construct_frame` | 12 | 12 | 25.2s |  |
| 24 | `uint_toexponential` | 100 | 100 | 6.2s |  |
| 25 | `uint_toprecision` | 433 | 433 | 6.2s |  |
| 26 | `uncaught_errors_stringified` | 15 | 15 | 6.3s |  |
| 27 | `weird_superinterface_properties` | 1 | 1 | 27.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**34 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 2 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 3 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 4 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 5 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 6 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 7 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 8 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 9 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 10 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 11 | `textblock_line_changes` | 79.1% | 125 | 158 | 33 |  |
| 12 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 13 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 14 | `edittext_tag_indent` | 76.0% | 38 | 50 | 12 |  |
| 15 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 16 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 17 | `bitmapdata_draw_alpha_erase` | 75.0% | 6 | 8 | 2 |  |
| 18 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 19 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 20 | `sound_rootless` | 71.4% | 5 | 7 | 2 |  |
| 21 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 22 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 23 | `localconnection` | 66.2% | 589 | 890 | 301 |  |
| 24 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 25 | `displayobject_scrollrect` | 57.6% | 19 | 33 | 14 |  |
| 26 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 27 | `edittext_device_transform_layout` | 55.6% | 160 | 288 | 128 |  |
| 28 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 29 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 30 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 31 | `netstream_flv_date` | 50.0% | 2 | 4 | 2 |  |
| 32 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 33 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 34 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**114 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 2 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 3 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 4 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 5 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 6 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 7 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 8 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 9 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 10 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 11 | `textblock_line_changes` | 79.1% | 125/158 | 158 | 158 |  |
| 12 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 13 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 14 | `edittext_tag_indent` | 76.0% | 38/50 | 50 | 49 |  |
| 15 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 16 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 17 | `bitmapdata_draw_alpha_erase` | 75.0% | 6/8 | 8 | 8 |  |
| 18 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 19 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 20 | `sound_rootless` | 71.4% | 5/7 | 5 | 7 |  |
| 21 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 22 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 23 | `localconnection` | 66.2% | 589/890 | 855 | 890 |  |
| 24 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 25 | `displayobject_scrollrect` | 57.6% | 19/33 | 33 | 33 |  |
| 26 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 27 | `edittext_device_transform_layout` | 55.6% | 160/288 | 288 | 288 |  |
| 28 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 29 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 30 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 31 | `netstream_flv_date` | 50.0% | 2/4 | 2 | 4 |  |
| 32 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 33 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 34 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 35 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 36 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 37 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 38 | `textblock_recreateline` | 40.8% | 40/98 | 89 | 98 |  |
| 39 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 40 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 41 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 42 | `sound_constructor_with_args` | 33.3% | 2/6 | 2 | 6 |  |
| 43 | `geom_transform` | 27.0% | 20/74 | 26 | 74 |  |
| 44 | `property_is_enumerable` | 21.9% | 25/114 | 27 | 114 |  |
| 45 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 46 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 47 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 48 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 49 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 50 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 51 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 52 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 53 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 54 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 55 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 56 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 57 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 58 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 59 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 60 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 61 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 62 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 63 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 64 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 65 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 66 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 67 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 68 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 69 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 70 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 71 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 72 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 73 | `all_classes/events/swf9` | 0.2% | 2/1030 | 190 | 1030 |  |
| 74 | `all_classes/events/swf10` | 0.2% | 3/1638 | 190 | 1638 |  |
| 75 | `all_classes/events/swf11` | 0.2% | 3/1750 | 190 | 1750 |  |
| 76 | `all_classes/events/swf12` | 0.2% | 3/1814 | 190 | 1814 |  |
| 77 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 78 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 79 | `all_classes/events/swf30` | 0.0% | 1/2353 | 190 | 2353 |  |
| 80 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 81 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 82 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 83 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 84 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 85 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 86 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 87 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 88 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 89 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 90 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 91 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 92 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 93 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 94 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 95 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 96 | `avm1_root` | 0.0% | 0/58 | 6 | 58 |  |
| 97 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 98 | `currency_parse_result` | 0.0% | 0/7 | 2 | 7 |  |
| 99 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 100 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 101 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 102 | `groupelement_text` | 0.0% | 0/156 | 3 | 156 |  |
| 103 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 104 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 105 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 106 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 107 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 108 | `netfilterevent` | 0.0% | 0/10 | 2 | 10 |  |
| 109 | `netstream_play_flv` | 0.0% | 0/16 | 0 | 16 |  |
| 110 | `netstream_seek_flv` | 0.0% | 0/49 | 0 | 49 |  |
| 111 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 112 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 113 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 114 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
