# Ruffle Test Results (Filtered)

**Date**: 2026-08-01 19:38 UTC

**Git SHA**: `c4496a4c8f`

**Run Duration**: 219m 23s

**Filtered**: 53 tests ignored out of 1224 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1171 |
| Passing | **1082** (92.4%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1085** (92.7%) |
| Failing | 86 |
| Total expected lines | 133312 |
| Matching lines | 111320 (83.5%) |
| Mismatched lines | 21992 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 86 | 100.0% |

## Passing Tests

**1082 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 25.7s |  |
| 2 | `accessibility` | 1 | 7.2s |  |
| 3 | `activation_class` | 6 | 7.3s |  |
| 4 | `add` | 1058 | 19.2s |  |
| 5 | `agal_compiler` | 13 | 9.6s |  |
| 6 | `air_datagram_socket` | 1 | 8.8s |  |
| 7 | `air_hidden_lookup` | 2 | 7.2s |  |
| 8 | `air_ifilepromise` | 1 | 7.2s |  |
| 9 | `all_classes/security/swf11` | 3 | 7.2s |  |
| 10 | `amf_array_serialization` | 17 | 9.2s |  |
| 11 | `amf_custom_obj` | 26 | 7.3s |  |
| 12 | `amf_dictionary` | 9 | 7.2s |  |
| 13 | `amf_function` | 46 | 7.3s |  |
| 14 | `amf_invalid_date` | 2 | 7.2s |  |
| 15 | `amf_missing_prop` | 6 | 7.2s |  |
| 16 | `amf_nondynamic_function_prop` | 6 | 8.0s |  |
| 17 | `amf_setter_error` | 8 | 8.0s |  |
| 18 | `amf_vector` | 40 | 8.2s |  |
| 19 | `amf_xml` | 6 | 7.9s |  |
| 20 | `application_domain` | 4 | 7.9s |  |
| 21 | `applicationdomain_getqualifieddefinitionnames` | 9 | 8.1s |  |
| 22 | `applicationdomain_hasdefinition_null` | 2 | 7.8s |  |
| 23 | `array_access` | 18 | 7.9s |  |
| 24 | `array_access_interpreter` | 4 | 7.8s |  |
| 25 | `array_access_no_pubns` | 2 | 7.8s |  |
| 26 | `array_concat` | 41 | 7.8s |  |
| 27 | `array_constr` | 10 | 7.8s |  |
| 28 | `array_delete` | 44 | 7.8s |  |
| 29 | `array_enumeration` | 10 | 7.7s |  |
| 30 | `array_enumeration_elements` | 11 | 7.8s |  |
| 31 | `array_every` | 8 | 7.7s |  |
| 32 | `array_filter` | 6 | 7.8s |  |
| 33 | `array_foreach` | 18 | 7.8s |  |
| 34 | `array_hasownproperty` | 11 | 3.3s |  |
| 35 | `array_holes` | 9 | 7.7s |  |
| 36 | `array_index_max` | 84 | 7.7s |  |
| 37 | `array_indexof` | 25 | 7.8s |  |
| 38 | `array_join` | 26 | 7.8s |  |
| 39 | `array_lastindexof` | 29 | 7.8s |  |
| 40 | `array_length` | 14 | 7.8s |  |
| 41 | `array_literal` | 3 | 7.7s |  |
| 42 | `array_map` | 8 | 7.8s |  |
| 43 | `array_pop` | 52 | 8.0s |  |
| 44 | `array_push` | 24 | 7.7s |  |
| 45 | `array_reborrow_bug` | 6 | 7.6s |  |
| 46 | `array_reverse` | 28 | 7.7s |  |
| 47 | `array_shift` | 51 | 3.4s |  |
| 48 | `array_slice` | 39 | 7.8s |  |
| 49 | `array_some` | 8 | 7.8s |  |
| 50 | `array_sort` | 297 | 8.2s |  |
| 51 | `array_sort_fun_swf12` | 2 | 7.7s |  |
| 52 | `array_sort_fun_swf13` | 2 | 1.4s |  |
| 53 | `array_sort_random` | 210 | 7.8s |  |
| 54 | `array_sort_swf10_32bit` | 1 | 7.8s |  |
| 55 | `array_sorton` | 545 | 8.3s |  |
| 56 | `array_sparse_ops` | 41 | 7.5s |  |
| 57 | `array_splice` | 133 | 7.7s |  |
| 58 | `array_splice2` | 428 | 7.7s |  |
| 59 | `array_splice_types` | 48 | 7.6s |  |
| 60 | `array_storage` | 8 | 7.6s |  |
| 61 | `array_tolocalestring` | 9 | 7.6s |  |
| 62 | `array_tostring` | 12 | 7.5s |  |
| 63 | `array_unshift` | 24 | 7.5s |  |
| 64 | `array_valueof` | 9 | 7.4s |  |
| 65 | `array_vector_null_callback` | 10 | 7.6s |  |
| 66 | `astype` | 28 | 7.6s |  |
| 67 | `astypelate` | 24 | 7.4s |  |
| 68 | `astypelate_propagates` | 1 | 7.3s |  |
| 69 | `asymmetric_key_events` | 11 | 7.5s |  |
| 70 | `av_networking_params` | 9 | 7.4s |  |
| 71 | `av_tag_data` | 2 | 7.4s |  |
| 72 | `avm2_catchup_dobj` | 158 | 8.0s |  |
| 73 | `away3d_advanced_shallow_water_demo` | 0 | 88.3s |  |
| 74 | `bevel_filter` | 187 | 7.8s |  |
| 75 | `bitand` | 1058 | 20.2s |  |
| 76 | `bitmap_constr` | 17 | 8.0s |  |
| 77 | `bitmap_data` | 1000 | 16.0s |  |
| 78 | `bitmap_pixelsnapping` | 2 | 27.3s |  |
| 79 | `bitmap_properties` | 23 | 7.6s |  |
| 80 | `bitmap_subclass` | 7 | 9.2s |  |
| 81 | `bitmap_subclass_properties` | 9 | 8.2s |  |
| 82 | `bitmap_timeline` | 9 | 7.9s |  |
| 83 | `bitmapdata_accuracy` | 1 | 49.4s |  |
| 84 | `bitmapdata_applyfilter_blur` | 0 | 27.7s |  |
| 85 | `bitmapdata_applyfilter_colormatrix` | 0 | 8.5s |  |
| 86 | `bitmapdata_applyfilter_destpoint` | 0 | 27.6s |  |
| 87 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 27.2s |  |
| 88 | `bitmapdata_clone` | 13 | 7.7s |  |
| 89 | `bitmapdata_colortransform` | 0 | 7.9s |  |
| 90 | `bitmapdata_colortransform_oob` | 2 | 7.5s |  |
| 91 | `bitmapdata_constr` | 22 | 7.6s |  |
| 92 | `bitmapdata_constructor_from_timeline` | 1 | 7.8s |  |
| 93 | `bitmapdata_copychannel` | 0 | 29.5s |  |
| 94 | `bitmapdata_copypixels` | 23 | 27.9s |  |
| 95 | `bitmapdata_copypixels_blend_over` | 1 | 7.5s |  |
| 96 | `bitmapdata_copypixelstobytearray` | 39 | 7.4s |  |
| 97 | `bitmapdata_dispose` | 7 | 7.5s |  |
| 98 | `bitmapdata_draw` | 0 | 27.1s |  |
| 99 | `bitmapdata_draw_colortransform` | 0 | 7.7s |  |
| 100 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 26.7s |  |
| 101 | `bitmapdata_draw_filters` | 0 | 27.0s |  |
| 102 | `bitmapdata_draw_masks` | 0 | 7.5s |  |
| 103 | `bitmapdata_draw_rotation` | 0 | 8.0s |  |
| 104 | `bitmapdata_draw_self_via_graphic` | 0 | 7.9s |  |
| 105 | `bitmapdata_draw_stage` | 0 | 27.0s |  |
| 106 | `bitmapdata_drawwithquality` | 0 | 7.9s |  |
| 107 | `bitmapdata_embedded` | 9 | 7.9s |  |
| 108 | `bitmapdata_fillrect` | 0 | 7.8s |  |
| 109 | `bitmapdata_filter_sourcerect` | 0 | 27.0s |  |
| 110 | `bitmapdata_floodfill` | 35 | 7.2s |  |
| 111 | `bitmapdata_getpixels` | 39 | 26.5s |  |
| 112 | `bitmapdata_getvector` | 27 | 3.2s |  |
| 113 | `bitmapdata_histogram` | 59 | 3.2s |  |
| 114 | `bitmapdata_hittest` | 112 | 8.0s |  |
| 115 | `bitmapdata_hittest_threshold` | 18 | 7.5s |  |
| 116 | `bitmapdata_opaque` | 0 | 7.6s |  |
| 117 | `bitmapdata_pixeldissolve` | 1037 | 8.0s |  |
| 118 | `bitmapdata_pixeldissolve_image` | 0 | 7.8s |  |
| 119 | `bitmapdata_rectangle_rounding` | 16 | 7.4s |  |
| 120 | `bitmapdata_setpixels` | 286 | 7.4s |  |
| 121 | `bitmapdata_setvector` | 26 | 7.4s |  |
| 122 | `bitmapdata_sync` | 0 | 25.9s |  |
| 123 | `bitmapdata_threshold` | 176 | 8.0s |  |
| 124 | `bitmapdata_zero_size` | 8 | 7.3s |  |
| 125 | `bitnot` | 46 | 7.3s |  |
| 126 | `bitor` | 1058 | 19.4s |  |
| 127 | `bitxor` | 1058 | 19.5s |  |
| 128 | `blend_mode_null` | 1 | 7.6s |  |
| 129 | `blend_multiply_alpha` | 0 | 7.8s |  |
| 130 | `blend_scroll` | 0 | 7.8s |  |
| 131 | `blend_shader_luma_lighten` | 3 | 8.2s |  |
| 132 | `blur_filter` | 43 | 8.0s |  |
| 133 | `boolean_constr` | 32 | 8.0s |  |
| 134 | `boolean_negation` | 30 | 8.0s |  |
| 135 | `boolean_tostring` | 8 | 7.9s |  |
| 136 | `broadcast_event` | 7 | 8.1s |  |
| 137 | `button_bounds` | 1 | 8.0s |  |
| 138 | `button_hittest` | 2 | 27.4s |  |
| 139 | `button_nested_frame` | 48 | 27.8s |  |
| 140 | `bytearray` | 48 | 8.0s |  |
| 141 | `bytearray_compress` | 31 | 7.8s |  |
| 142 | `bytearray_errors` | 24 | 7.9s |  |
| 143 | `bytearray_method_serialization` | 1 | 7.7s |  |
| 144 | `bytearray_readobject_amf0` | 50 | 7.7s |  |
| 145 | `bytearray_readobject_amf3` | 53 | 7.8s |  |
| 146 | `bytearray_readutf8bytes_with_bom` | 16 | 7.8s |  |
| 147 | `bytearray_serialization` | 3 | 7.7s |  |
| 148 | `bytearray_string_null` | 19 | 8.0s |  |
| 149 | `bytearray_tostring` | 15 | 7.7s |  |
| 150 | `bytearray_utf16` | 8 | 7.7s |  |
| 151 | `bytearray_writeobject` | 24 | 7.6s |  |
| 152 | `callee_in_initializer` | 6 | 7.6s |  |
| 153 | `callproplex_class` | 1 | 7.7s |  |
| 154 | `capabilities_resolution` | 8 | 27.9s |  |
| 155 | `catch_class` | 6 | 7.7s |  |
| 156 | `catch_scope_slot` | 7 | 3.4s |  |
| 157 | `checkfilter` | 4 | 3.4s |  |
| 158 | `class_call` | 32 | 7.8s |  |
| 159 | `class_cast_call` | 14 | 7.7s |  |
| 160 | `class_enumeration` | 4 | 7.7s |  |
| 161 | `class_has_own_property` | 2 | 7.8s |  |
| 162 | `class_init_interpreter_mode` | 1 | 7.7s |  |
| 163 | `class_is` | 32 | 7.9s |  |
| 164 | `class_methods` | 5 | 7.8s |  |
| 165 | `class_object_properties` | 10 | 7.8s |  |
| 166 | `class_singleton` | 18 | 7.8s |  |
| 167 | `class_supercalls_errors` | 35 | 8.0s |  |
| 168 | `class_supercalls_mismatched` | 26 | 7.8s |  |
| 169 | `class_superclass_wrong_order` | 1 | 22.8s |  |
| 170 | `class_to_locale_string` | 2 | 6.1s |  |
| 171 | `class_to_string` | 2 | 6.0s |  |
| 172 | `class_value_of` | 2 | 6.1s |  |
| 173 | `click_block` | 5 | 6.7s |  |
| 174 | `click_invisible` | 3 | 6.3s |  |
| 175 | `closures` | 12 | 6.1s |  |
| 176 | `coerce_return_type` | 40 | 6.2s |  |
| 177 | `coerce_return_type_fail` | 2 | 6.4s |  |
| 178 | `coerce_return_void` | 3 | 6.0s |  |
| 179 | `coerce_string` | 86 | 6.2s |  |
| 180 | `coerce_string_precision` | 28 | 6.2s |  |
| 181 | `coerce_to_primitive_side_effects` | 29 | 21.4s |  |
| 182 | `color_matrix_filter` | 19 | 6.3s |  |
| 183 | `construct_errors_swf10` | 8 | 6.0s |  |
| 184 | `construct_frame_list` | 22 | 21.5s |  |
| 185 | `construct_interface` | 3 | 6.1s |  |
| 186 | `constructor_call` | 3 | 6.0s |  |
| 187 | `constructors_vs_timeline` | 5 | 21.8s |  |
| 188 | `constructprop_dynamic_primitive` | 7 | 6.2s |  |
| 189 | `constructprop_method` | 2 | 6.0s |  |
| 190 | `content_element_basic` | 50 | 6.3s |  |
| 191 | `context3d_creation` | 9 | 6.3s |  |
| 192 | `control_flow_bool` | 4 | 6.1s |  |
| 193 | `control_flow_stricteq` | 8 | 6.1s |  |
| 194 | `convert_boolean` | 30 | 6.1s |  |
| 195 | `convert_integer` | 90 | 6.2s |  |
| 196 | `convert_number` | 56 | 6.2s |  |
| 197 | `convert_uinteger` | 90 | 6.3s |  |
| 198 | `convolution_filter` | 89 | 6.3s |  |
| 199 | `core_exceptions` | 47 | 6.8s |  |
| 200 | `cpool_index_invalid_bytecode_1` | 6 | 6.3s |  |
| 201 | `cpool_index_invalid_bytecode_2` | 3 | 6.1s |  |
| 202 | `cpool_index_invalid_bytecode_3` | 1 | 6.2s |  |
| 203 | `cross_api_version_call_older` | 12 | 6.4s |  |
| 204 | `cryptscore` | 11 | 6.2s |  |
| 205 | `date_parse` | 36 | 7.2s |  |
| 206 | `declocal` | 46 | 7.3s |  |
| 207 | `declocal_i` | 46 | 7.3s |  |
| 208 | `decode_uri` | 71 | 7.6s |  |
| 209 | `decrement` | 46 | 7.3s |  |
| 210 | `decrement_i` | 46 | 3.1s |  |
| 211 | `default_values` | 7 | 7.2s |  |
| 212 | `dictionary_access` | 62 | 7.5s |  |
| 213 | `dictionary_access_no_pubns` | 2 | 7.2s |  |
| 214 | `dictionary_delete` | 101 | 7.7s |  |
| 215 | `dictionary_foreach` | 42 | 7.4s |  |
| 216 | `dictionary_hasownproperty` | 63 | 7.5s |  |
| 217 | `dictionary_in` | 62 | 7.5s |  |
| 218 | `dictionary_iter_modify` | 8 | 7.2s |  |
| 219 | `dictionary_namespaces` | 36 | 7.3s |  |
| 220 | `dictionary_primitive_keys` | 29 | 7.2s |  |
| 221 | `displacement_map_filter` | 61 | 7.4s |  |
| 222 | `displayobject_alpha` | 277 | 7.2s |  |
| 223 | `displayobject_blendmode` | 0 | 7.4s |  |
| 224 | `displayobject_colortransform_nested` | 0 | 25.9s |  |
| 225 | `displayobject_filters` | 17 | 7.4s |  |
| 226 | `displayobject_from_enterframe` | 1 | 25.8s |  |
| 227 | `displayobject_getbounds_shape` | 0 | 25.8s |  |
| 228 | `displayobject_height` | 6052 | 25.8s |  |
| 229 | `displayobject_hittestobject` | 32 | 7.3s |  |
| 230 | `displayobject_hittestpoint` | 49 | 7.6s |  |
| 231 | `displayobject_hittestpoint_root` | 13 | 7.5s |  |
| 232 | `displayobject_invalid_floats` | 60 | 7.2s |  |
| 233 | `displayobject_invalid_props` | 3 | 7.2s |  |
| 234 | `displayobject_mask` | 3 | 7.5s |  |
| 235 | `displayobject_mask_self_referential` | 0 | 28.9s |  |
| 236 | `displayobject_metaData` | 3 | 7.9s |  |
| 237 | `displayobject_name` | 22 | 29.2s |  |
| 238 | `displayobject_name_from_timeline` | 24 | 8.0s |  |
| 239 | `displayobject_opaque_background` | 6 | 28.8s |  |
| 240 | `displayobject_parent` | 12 | 7.9s |  |
| 241 | `displayobject_root` | 24 | 7.9s |  |
| 242 | `displayobject_rotation` | 1284 | 8.1s |  |
| 243 | `displayobject_set_matrix_nested` | 0 | 28.9s |  |
| 244 | `displayobject_set_name_loaded` | 3 | 8.2s |  |
| 245 | `displayobject_subclass` | 2 | 7.8s |  |
| 246 | `displayobject_visible` | 23 | 7.8s |  |
| 247 | `displayobject_width` | 4852 | 28.8s |  |
| 248 | `displayobject_x` | 614 | 7.9s |  |
| 249 | `displayobject_y` | 617 | 7.9s |  |
| 250 | `displayobjectcontainer_addchild` | 32 | 8.0s |  |
| 251 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 7.9s |  |
| 252 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 8.1s |  |
| 253 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 8.0s |  |
| 254 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 8.0s |  |
| 255 | `displayobjectcontainer_addchildat` | 42 | 7.8s |  |
| 256 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 8.0s |  |
| 257 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 8.0s |  |
| 258 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 8.0s |  |
| 259 | `displayobjectcontainer_contains` | 66 | 29.1s |  |
| 260 | `displayobjectcontainer_getchildat` | 4 | 7.9s |  |
| 261 | `displayobjectcontainer_getchildbyname` | 9 | 7.8s |  |
| 262 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 7.8s |  |
| 263 | `displayobjectcontainer_getchildindex` | 28 | 7.8s |  |
| 264 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 8.0s |  |
| 265 | `displayobjectcontainer_removechild` | 10 | 7.8s |  |
| 266 | `displayobjectcontainer_removechild_errors` | 4 | 7.9s |  |
| 267 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 7.9s |  |
| 268 | `displayobjectcontainer_removechildat` | 18 | 7.7s |  |
| 269 | `displayobjectcontainer_removechildren` | 51 | 8.1s |  |
| 270 | `displayobjectcontainer_setchildindex` | 42 | 7.7s |  |
| 271 | `displayobjectcontainer_stopallmovieclips` | 2 | 29.3s |  |
| 272 | `displayobjectcontainer_swapchildren` | 42 | 7.9s |  |
| 273 | `displayobjectcontainer_swapchildrenat` | 42 | 8.0s |  |
| 274 | `displayobjectcontainer_timelineinstance` | 48 | 27.6s |  |
| 275 | `divide` | 1058 | 19.9s |  |
| 276 | `doabc_is_eager` | 1 | 26.1s |  |
| 277 | `documentclass` | 9 | 7.5s |  |
| 278 | `domain_memory` | 133 | 27.6s |  |
| 279 | `drag_drop` | 10 | 7.6s |  |
| 280 | `drop_shadow_filter` | 172 | 7.6s |  |
| 281 | `duplicate_defs` | 1 | 7.3s |  |
| 282 | `eager_init` | 1 | 7.4s |  |
| 283 | `east_asian_justifier_clone` | 8 | 3.2s |  |
| 284 | `edit_text_linkage` | 7 | 7.6s |  |
| 285 | `edittext_align` | 60 | 7.9s |  |
| 286 | `edittext_always_show_selection` | 0 | 26.9s |  |
| 287 | `edittext_antialiastype` | 296 | 7.7s |  |
| 288 | `edittext_at_point_methods_basic` | 16 | 8.8s |  |
| 289 | `edittext_autosize` | 39 | 7.8s |  |
| 290 | `edittext_autosize_align` | 0 | 26.9s |  |
| 291 | `edittext_autosize_height_dynamic` | 60 | 26.7s |  |
| 292 | `edittext_autosize_height_input` | 60 | 7.5s |  |
| 293 | `edittext_autosize_lazy_bounds_events` | 65 | 7.8s |  |
| 294 | `edittext_autosize_lazy_bounds_interactions` | 19 | 7.5s |  |
| 295 | `edittext_autosize_lazy_bounds_props` | 490 | 8.9s |  |
| 296 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.9s |  |
| 297 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 7.7s |  |
| 298 | `edittext_bottom_scroll_v_basic` | 210 | 7.5s |  |
| 299 | `edittext_bounds_scale` | 24 | 26.8s |  |
| 300 | `edittext_bullet` | 30 | 7.5s |  |
| 301 | `edittext_default_format` | 221 | 7.8s |  |
| 302 | `edittext_default_format_empty` | 136 | 7.8s |  |
| 303 | `edittext_empty_text_format` | 7 | 7.5s |  |
| 304 | `edittext_focus_selection` | 5 | 7.4s |  |
| 305 | `edittext_font_size` | 45 | 7.5s |  |
| 306 | `edittext_format_empty_font` | 8 | 7.4s |  |
| 307 | `edittext_get_char_index_at_point` | 4 | 28.5s |  |
| 308 | `edittext_get_line_index_at_point` | 2 | 27.2s |  |
| 309 | `edittext_get_line_index_of_char` | 76 | 8.4s |  |
| 310 | `edittext_getcharboundaries` | 172 | 8.0s |  |
| 311 | `edittext_getcharboundaries_missing_glyphs` | 63 | 7.8s |  |
| 312 | `edittext_getcharboundaries_scroll` | 85 | 26.4s |  |
| 313 | `edittext_getlinemetrics` | 146 | 7.7s |  |
| 314 | `edittext_html` | 3101 | 8.1s |  |
| 315 | `edittext_html_condensewhite` | 487 | 7.7s |  |
| 316 | `edittext_html_entity` | 4 | 8.0s |  |
| 317 | `edittext_html_font_size_swf12` | 267 | 7.8s |  |
| 318 | `edittext_html_font_size_swf13` | 273 | 7.2s |  |
| 319 | `edittext_html_roundtrip` | 17 | 7.6s |  |
| 320 | `edittext_ime_focus_lost` | 9 | 26.3s |  |
| 321 | `edittext_input_control` | 12 | 7.6s |  |
| 322 | `edittext_leading` | 9 | 7.8s |  |
| 323 | `edittext_letter_spacing` | 15 | 7.5s |  |
| 324 | `edittext_line_methods` | 294 | 8.8s |  |
| 325 | `edittext_line_metrics` | 11 | 28.1s |  |
| 326 | `edittext_margins` | 25 | 7.6s |  |
| 327 | `edittext_max_scroll_h_basic` | 475 | 7.7s |  |
| 328 | `edittext_max_scroll_v_basic` | 1000 | 7.6s |  |
| 329 | `edittext_mouse_selection` | 363 | 28.0s |  |
| 330 | `edittext_mousedown` | 3 | 7.7s |  |
| 331 | `edittext_mouseenabled` | 26 | 7.5s |  |
| 332 | `edittext_newline_character` | 22 | 7.3s |  |
| 333 | `edittext_newline_stripping` | 64 | 10.1s |  |
| 334 | `edittext_newlines` | 30 | 7.5s |  |
| 335 | `edittext_paragraph_methods` | 257 | 7.4s |  |
| 336 | `edittext_paste_events` | 8 | 7.7s |  |
| 337 | `edittext_paste_maxchars` | 4 | 7.6s |  |
| 338 | `edittext_paste_restrict` | 16 | 7.3s |  |
| 339 | `edittext_restrict` | 191 | 7.4s |  |
| 340 | `edittext_restrict_events` | 22 | 7.5s |  |
| 341 | `edittext_scrollh` | 10 | 7.3s |  |
| 342 | `edittext_selected_text` | 9 | 7.3s |  |
| 343 | `edittext_set_html_same` | 17 | 7.3s |  |
| 344 | `edittext_set_text_vs_html` | 9 | 7.4s |  |
| 345 | `edittext_stylesheet` | 536 | 7.8s |  |
| 346 | `edittext_stylesheet_custom_tag` | 76 | 7.4s |  |
| 347 | `edittext_stylesheet_display` | 272 | 7.5s |  |
| 348 | `edittext_underline` | 40 | 7.5s |  |
| 349 | `edittext_width_height` | 103 | 24.7s |  |
| 350 | `edittext_wordwrap_word` | 150 | 27.5s |  |
| 351 | `edittext_wrap_breaks` | 2375 | 8.3s |  |
| 352 | `element_format_clone` | 44 | 7.8s |  |
| 353 | `element_format_constructor_order` | 64 | 7.9s |  |
| 354 | `element_format_properties` | 235 | 8.6s |  |
| 355 | `empty_bounds` | 1 | 7.6s |  |
| 356 | `encode_uri_surrogate_pair_invalid` | 8 | 7.7s |  |
| 357 | `encode_uri_surrogate_pair_swf11` | 15 | 7.4s |  |
| 358 | `equals` | 512 | 12.2s |  |
| 359 | `error_geterrormessage` | 779 | 7.9s |  |
| 360 | `error_prototype` | 15 | 7.9s |  |
| 361 | `error_stack_trace_debug_swf17` | 0 | 28.6s |  |
| 362 | `error_stack_trace_debug_swf18` | 0 | 7.7s |  |
| 363 | `error_stack_trace_release_swf17` | 0 | 7.6s |  |
| 364 | `error_stack_trace_release_swf18` | 0 | 7.6s |  |
| 365 | `error_tostring` | 29 | 7.8s |  |
| 366 | `error_tostring_more` | 86 | 7.9s |  |
| 367 | `es3_inheritance` | 31 | 7.9s |  |
| 368 | `es4_inheritance` | 30 | 7.9s |  |
| 369 | `es4_interfaces` | 30 | 8.0s |  |
| 370 | `es4_method_binding` | 8 | 7.9s |  |
| 371 | `es4_oop_prototypes` | 14 | 8.0s |  |
| 372 | `es4_protected_inheritance` | 6 | 7.9s |  |
| 373 | `escape` | 71 | 7.9s |  |
| 374 | `escape_multi_byte` | 45 | 8.0s |  |
| 375 | `event_bubbles` | 2 | 7.9s |  |
| 376 | `event_cancelable` | 2 | 7.8s |  |
| 377 | `event_clone` | 20 | 7.8s |  |
| 378 | `event_clone_error_redispatch` | 3 | 8.0s |  |
| 379 | `event_clone_on_redispatch` | 10 | 8.0s |  |
| 380 | `event_formattostring` | 31 | 7.9s |  |
| 381 | `event_isdefaultprevented` | 12 | 7.8s |  |
| 382 | `event_target_getter` | 5 | 3.4s |  |
| 383 | `event_target_set` | 9 | 7.8s |  |
| 384 | `event_type` | 1 | 23.9s |  |
| 385 | `event_valueof_tostring` | 18 | 7.4s |  |
| 386 | `eventdispatcher_dispatchevent` | 12 | 7.4s |  |
| 387 | `eventdispatcher_dispatchevent_cancel` | 20 | 26.2s |  |
| 388 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 7.4s |  |
| 389 | `eventdispatcher_dispatchevent_indirect` | 9 | 7.5s |  |
| 390 | `eventdispatcher_dispatchevent_this` | 5 | 7.3s |  |
| 391 | `eventdispatcher_haseventlistener` | 25 | 7.5s |  |
| 392 | `eventdispatcher_interface_invoke` | 1 | 7.4s |  |
| 393 | `eventdispatcher_tostring` | 10 | 7.4s |  |
| 394 | `eventdispatcher_willtrigger` | 25 | 7.3s |  |
| 395 | `falsiness` | 30 | 7.4s |  |
| 396 | `fast_index_access` | 12 | 7.5s |  |
| 397 | `filefilter_properties` | 4 | 7.4s |  |
| 398 | `filereference_browse_cancel` | 3 | 7.4s |  |
| 399 | `filereference_browse_select` | 9 | 7.5s |  |
| 400 | `filereference_load` | 31 | 7.4s |  |
| 401 | `filereference_save` | 16 | 7.4s |  |
| 402 | `filereference_save_and_browse` | 42 | 7.5s |  |
| 403 | `filereference_save_and_load` | 22 | 7.5s |  |
| 404 | `filereference_uninitialized` | 8 | 7.4s |  |
| 405 | `filereferencelist_browse_cancel` | 6 | 7.4s |  |
| 406 | `filereferencelist_browse_select` | 7 | 7.4s |  |
| 407 | `filter_rewind` | 8 | 7.6s |  |
| 408 | `filters_array_holes` | 25 | 7.5s |  |
| 409 | `finddef` | 3 | 7.4s |  |
| 410 | `findprop_global_prototype` | 6 | 7.5s |  |
| 411 | `flash_media_video_constructor` | 156 | 8.2s |  |
| 412 | `flash_media_video_rotation_probe` | 27 | 7.5s |  |
| 413 | `flash_media_video_setter` | 40 | 7.9s |  |
| 414 | `flash_xml` | 29 | 7.5s |  |
| 415 | `flash_xml_cloneNode` | 22 | 7.4s |  |
| 416 | `flash_xml_namespace` | 109 | 7.4s |  |
| 417 | `flash_xml_removeNode` | 60 | 7.4s |  |
| 418 | `focus_events_code` | 161 | 26.7s |  |
| 419 | `focus_events_key_basic` | 132 | 27.0s |  |
| 420 | `focus_events_key_navigation` | 53 | 7.6s |  |
| 421 | `focus_events_key_same_object` | 26 | 7.4s |  |
| 422 | `focus_events_mixed_key_mouse` | 100 | 26.4s |  |
| 423 | `focus_events_mouse_basic` | 260 | 43.5s |  |
| 424 | `focus_events_mouse_focusable` | 112 | 27.7s |  |
| 425 | `focus_events_mouse_same_object` | 40 | 26.6s |  |
| 426 | `focus_remove` | 20 | 26.6s |  |
| 427 | `focus_root_movie` | 4 | 28.4s |  |
| 428 | `focus_stage` | 1 | 7.1s |  |
| 429 | `focusrect` | 18 | 7.8s |  |
| 430 | `focusrect_focuslost` | 9 | 7.2s |  |
| 431 | `focusrect_property` | 110 | 26.4s |  |
| 432 | `font_description_clone` | 14 | 7.1s |  |
| 433 | `font_embedded` | 24 | 7.4s |  |
| 434 | `font_enumeratefonts` | 41 | 7.7s |  |
| 435 | `font_enumeratefonts_filter` | 4 | 27.1s |  |
| 436 | `font_enumeratefonts_order` | 9 | 8.3s |  |
| 437 | `font_hasglyphs` | 40 | 7.5s |  |
| 438 | `font_registerfont` | 129 | 7.9s |  |
| 439 | `framelabel_constr` | 5 | 7.4s |  |
| 440 | `function_call` | 12 | 7.1s |  |
| 441 | `function_call_arguments` | 46 | 7.2s |  |
| 442 | `function_call_arguments_enumerate` | 5 | 7.1s |  |
| 443 | `function_call_coercion` | 108 | 7.5s |  |
| 444 | `function_call_default` | 6 | 7.1s |  |
| 445 | `function_call_rest` | 22 | 7.0s |  |
| 446 | `function_call_types` | 3 | 7.0s |  |
| 447 | `function_call_via_apply` | 11 | 7.1s |  |
| 448 | `function_call_via_call` | 3 | 7.0s |  |
| 449 | `function_display_anonymous` | 7 | 2.9s |  |
| 450 | `function_length` | 6 | 7.1s |  |
| 451 | `function_object` | 2 | 7.0s |  |
| 452 | `function_proto` | 5 | 7.0s |  |
| 453 | `function_proto_created` | 61 | 7.1s |  |
| 454 | `function_to_locale_string` | 4 | 7.0s |  |
| 455 | `function_to_string` | 4 | 7.0s |  |
| 456 | `function_type` | 6 | 7.1s |  |
| 457 | `function_unbound_this` | 51 | 7.2s |  |
| 458 | `function_value_of` | 4 | 7.1s |  |
| 459 | `game_input` | 4 | 7.1s |  |
| 460 | `generate_random_bytes` | 3 | 7.1s |  |
| 461 | `get_definition_by_name` | 11 | 7.1s |  |
| 462 | `get_qualified_class_name` | 20 | 23.7s |  |
| 463 | `get_qualified_super_class_name` | 18 | 7.2s |  |
| 464 | `get_slot_edge_cases` | 1 | 25.4s |  |
| 465 | `get_timer` | 2 | 7.2s |  |
| 466 | `getglobalslot` | 1 | 7.2s |  |
| 467 | `getouterscope` | 8 | 7.2s |  |
| 468 | `getouterscope_two_classobjects` | 13 | 7.2s |  |
| 469 | `getter_different_namespace_setter` | 2 | 7.0s |  |
| 470 | `glow_filter` | 127 | 7.3s |  |
| 471 | `goto_button_nested_framescript` | 28 | 25.8s |  |
| 472 | `goto_in_constructframe` | 12 | 25.6s |  |
| 473 | `goto_in_scene_last_frame` | 2 | 25.1s |  |
| 474 | `goto_methods` | 56 | 7.5s |  |
| 475 | `goto_methods_swfver10` | 8 | 7.2s |  |
| 476 | `goto_nested_construct_sibling` | 18 | 7.7s |  |
| 477 | `goto_nested_framescript` | 9 | 7.4s |  |
| 478 | `goto_on_orphan` | 15 | 7.4s |  |
| 479 | `gradient_bevel_filter` | 206 | 7.3s |  |
| 480 | `gradient_glow_filter` | 206 | 7.2s |  |
| 481 | `graphics_bad_direct_commands` | 5 | 9.8s |  |
| 482 | `graphics_bitmap_fill` | 0 | 27.4s |  |
| 483 | `graphics_bitmaps` | 0 | 7.9s |  |
| 484 | `graphics_direct_commands` | 0 | 7.9s |  |
| 485 | `graphics_draw_triangles` | 98 | 26.4s |  |
| 486 | `graphics_gradients` | 0 | 7.6s |  |
| 487 | `graphics_gradients_nulls` | 0 | 7.5s |  |
| 488 | `graphics_path` | 56 | 7.3s |  |
| 489 | `graphics_round_rects` | 0 | 7.2s |  |
| 490 | `graphics_simple_shapes` | 0 | 7.5s |  |
| 491 | `greaterequals` | 512 | 11.1s |  |
| 492 | `greaterthan` | 512 | 11.1s |  |
| 493 | `has_own_property` | 102 | 7.7s |  |
| 494 | `hasownproperty_namespaces` | 2 | 7.2s |  |
| 495 | `hello_world` | 1 | 7.2s |  |
| 496 | `hittest_morph` | 30 | 7.4s |  |
| 497 | `if_eq` | 10 | 7.3s |  |
| 498 | `if_gt` | 1 | 7.3s |  |
| 499 | `if_gte` | 10 | 23.9s |  |
| 500 | `if_lt` | 1 | 7.3s |  |
| 501 | `if_lte` | 10 | 7.2s |  |
| 502 | `if_ne` | 7 | 3.1s |  |
| 503 | `if_stricteq` | 6 | 7.3s |  |
| 504 | `if_strictne` | 11 | 7.3s |  |
| 505 | `ime_linux_dead_keys` | 10 | 26.4s |  |
| 506 | `in` | 102 | 8.2s |  |
| 507 | `inclocal` | 46 | 7.8s |  |
| 508 | `inclocal_i` | 46 | 7.8s |  |
| 509 | `increment` | 46 | 7.8s |  |
| 510 | `increment_i` | 46 | 7.5s |  |
| 511 | `indexing_delete` | 75 | 7.3s |  |
| 512 | `instanceof` | 58 | 7.6s |  |
| 513 | `instantiate_root_character` | 4 | 7.5s |  |
| 514 | `instantiation_on_enter_frame` | 7 | 25.9s |  |
| 515 | `instantiation_on_enterframe_gotoandstop` | 8 | 7.3s |  |
| 516 | `int_constr` | 92 | 7.5s |  |
| 517 | `int_edge_cases` | 19 | 7.4s |  |
| 518 | `int_instanceof` | 3 | 7.5s |  |
| 519 | `int_tofixed` | 1215 | 7.6s |  |
| 520 | `int_tostring` | 3375 | 8.0s |  |
| 521 | `interactiveobject_enabled` | 25 | 7.7s |  |
| 522 | `interface_namespaces` | 78 | 7.6s |  |
| 523 | `invalid_utf8` | 12 | 7.4s |  |
| 524 | `is_finite` | 46 | 7.5s |  |
| 525 | `is_nan` | 46 | 7.4s |  |
| 526 | `is_prototype_of` | 12 | 7.4s |  |
| 527 | `issue_10221` | 2 | 7.4s |  |
| 528 | `issue_13780` | 12 | 7.5s |  |
| 529 | `issue_14901` | 1 | 7.4s |  |
| 530 | `issue_17675_edittext_paste_maxchars` | 1 | 7.6s |  |
| 531 | `issue_5292` | 5 | 7.5s |  |
| 532 | `issue_8630` | 2 | 28.8s |  |
| 533 | `issue_8630_placeremoveplace` | 15 | 8.0s |  |
| 534 | `issue_8630_placeremoveplace_scriptremove` | 16 | 7.8s |  |
| 535 | `issue_8630_scriptremove` | 11 | 7.5s |  |
| 536 | `istype` | 24 | 3.2s |  |
| 537 | `istypelate` | 58 | 7.8s |  |
| 538 | `istypelate_coerce` | 198 | 25.3s |  |
| 539 | `jpeg_loader_context` | 6 | 26.4s |  |
| 540 | `json_errors` | 9 | 26.5s |  |
| 541 | `json_parse` | 21 | 7.4s |  |
| 542 | `json_stringify` | 12 | 7.6s |  |
| 543 | `json_stringify_order` | 1 | 7.3s |  |
| 544 | `json_version_gated` | 1 | 7.3s |  |
| 545 | `key_input_80percent` | 1812 | 7.6s |  |
| 546 | `key_input_location` | 126 | 7.6s |  |
| 547 | `key_input_numpad` | 384 | 7.4s |  |
| 548 | `lazyinit` | 17 | 7.4s |  |
| 549 | `lessequals` | 512 | 11.4s |  |
| 550 | `lessthan` | 512 | 11.4s |  |
| 551 | `loader_bitmap_transparency` | 14 | 7.6s |  |
| 552 | `loader_bytes_unknown_content` | 14 | 7.5s |  |
| 553 | `loader_child_getdefinition` | 5 | 7.7s |  |
| 554 | `loader_duplicate_coerce` | 3 | 7.7s |  |
| 555 | `loader_duplicate_coerce_new_domain` | 4 | 7.5s |  |
| 556 | `loader_error_in_root_ctor` | 4 | 7.6s |  |
| 557 | `loader_events` | 92 | 10.0s |  |
| 558 | `loader_image` | 8 | 7.9s |  |
| 559 | `loader_jpegxr` | 2 | 26.6s |  |
| 560 | `loader_jpegxr_alpha` | 1 | 26.4s |  |
| 561 | `loader_loadbytes_events` | 30 | 8.3s |  |
| 562 | `loader_loadbytes_invalid_png` | 4 | 26.1s |  |
| 563 | `loader_loadbytes_url` | 12 | 7.8s |  |
| 564 | `loader_loaderurl` | 6 | 8.0s |  |
| 565 | `loader_method` | 85 | 7.5s |  |
| 566 | `loader_noninteractive_try_click_root` | 5 | 26.9s |  |
| 567 | `loader_reuse` | 38 | 7.6s |  |
| 568 | `loader_unknown_content` | 24 | 7.6s |  |
| 569 | `loader_visibility_interactive` | 1 | 7.6s |  |
| 570 | `loaderinfo_events` | 7 | 7.4s |  |
| 571 | `loaderinfo_loadurl` | 12 | 44.5s |  |
| 572 | `loaderinfo_more` | 6 | 28.2s |  |
| 573 | `loaderinfo_properties` | 18 | 7.9s |  |
| 574 | `loaderinfo_properties_not_loaded` | 23 | 8.1s |  |
| 575 | `loaderinfo_root` | 10 | 7.9s |  |
| 576 | `loaderinfo_root_allows` | 2 | 7.9s |  |
| 577 | `localconnection_send` | 4 | 7.8s |  |
| 578 | `lshift` | 1058 | 19.5s |  |
| 579 | `mask_reapply` | 1 | 7.8s |  |
| 580 | `math` | 497 | 8.1s |  |
| 581 | `matrix3d` | 57 | 8.6s |  |
| 582 | `matrix3d_compose` | 34 | 8.1s |  |
| 583 | `matrix3d_invert` | 18 | 7.9s |  |
| 584 | `method_without_body` | 3 | 27.7s |  |
| 585 | `missing_external_interface` | 10 | 7.9s |  |
| 586 | `modulo` | 1058 | 19.7s |  |
| 587 | `morph_shape` | 2 | 28.6s |  |
| 588 | `mouse_children` | 192 | 28.6s |  |
| 589 | `mouse_click_events` | 90 | 27.9s |  |
| 590 | `mouse_double_click_events` | 188 | 7.9s |  |
| 591 | `mouse_empty_parent` | 4 | 8.0s |  |
| 592 | `mouse_over_while_dragging` | 3 | 8.1s |  |
| 593 | `mouse_pick_button_mode` | 2 | 8.1s |  |
| 594 | `mouse_pick_dobj_mask` | 4 | 8.3s |  |
| 595 | `mouse_pick_masking` | 7 | 28.2s |  |
| 596 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 28.7s |  |
| 597 | `mouse_pick_non_interactive_dobj_mask` | 3 | 8.3s |  |
| 598 | `mouse_pick_text` | 8 | 8.2s |  |
| 599 | `mouse_sibling` | 8 | 8.1s |  |
| 600 | `mouse_wheel_events` | 36 | 30.1s |  |
| 601 | `mouseevent_constr` | 66 | 8.1s |  |
| 602 | `mouseevent_stagexy` | 35 | 8.1s |  |
| 603 | `mouseevent_valueof_tostring` | 28 | 8.0s |  |
| 604 | `movieclip_addframescript` | 3 | 28.6s |  |
| 605 | `movieclip_child_property` | 16 | 7.9s |  |
| 606 | `movieclip_constr` | 21 | 23.9s |  |
| 607 | `movieclip_currentlabels` | 17 | 26.2s |  |
| 608 | `movieclip_currentlabels_dupes1` | 46 | 26.2s |  |
| 609 | `movieclip_currentlabels_dupes2` | 30 | 7.4s |  |
| 610 | `movieclip_currentlabels_dupes3` | 67 | 7.4s |  |
| 611 | `movieclip_currentscene` | 12 | 26.1s |  |
| 612 | `movieclip_dispatchevent` | 430 | 7.5s |  |
| 613 | `movieclip_dispatchevent_cancel` | 102 | 7.5s |  |
| 614 | `movieclip_dispatchevent_handlerorder` | 251 | 7.4s |  |
| 615 | `movieclip_dispatchevent_selfadd` | 80 | 7.4s |  |
| 616 | `movieclip_dispatchevent_target` | 899 | 7.5s |  |
| 617 | `movieclip_displayevents` | 96 | 26.4s |  |
| 618 | `movieclip_displayevents_clickgoto` | 676 | 26.6s |  |
| 619 | `movieclip_displayevents_clickgoto2` | 2001 | 8.1s |  |
| 620 | `movieclip_displayevents_clickplay` | 575 | 7.7s |  |
| 621 | `movieclip_displayevents_clicksymbol` | 562 | 7.7s |  |
| 622 | `movieclip_displayevents_constructframegoto` | 140 | 7.9s |  |
| 623 | `movieclip_displayevents_constructframeplay` | 50 | 7.7s |  |
| 624 | `movieclip_displayevents_constructframesymbol` | 144 | 7.8s |  |
| 625 | `movieclip_displayevents_dblhandler` | 21 | 7.6s |  |
| 626 | `movieclip_displayevents_enterframegoto` | 149 | 7.7s |  |
| 627 | `movieclip_displayevents_enterframeplay` | 48 | 7.5s |  |
| 628 | `movieclip_displayevents_enterframesymbol` | 149 | 26.5s |  |
| 629 | `movieclip_displayevents_exitframegoto` | 106 | 7.5s |  |
| 630 | `movieclip_displayevents_exitframeplay` | 44 | 7.5s |  |
| 631 | `movieclip_displayevents_exitframesymbol` | 135 | 7.6s |  |
| 632 | `movieclip_displayevents_looping` | 63 | 26.5s |  |
| 633 | `movieclip_displayevents_stopped` | 113 | 7.9s |  |
| 634 | `movieclip_displayevents_swap` | 96 | 3.0s |  |
| 635 | `movieclip_displayevents_timeline` | 128 | 26.5s |  |
| 636 | `movieclip_drawrect` | 54 | 7.5s |  |
| 637 | `movieclip_frameconstruct_skipped` | 9 | 7.6s |  |
| 638 | `movieclip_goto_during_frame_script` | 15 | 7.5s |  |
| 639 | `movieclip_goto_overwrite` | 14 | 26.3s |  |
| 640 | `movieclip_goto_scene_last_frame_int` | 1 | 26.4s |  |
| 641 | `movieclip_goto_scene_last_frame_label` | 1 | 7.3s |  |
| 642 | `movieclip_gotoandplay` | 15 | 26.2s |  |
| 643 | `movieclip_gotoandstop` | 13 | 25.9s |  |
| 644 | `movieclip_gotoandstop_children` | 4 | 7.5s |  |
| 645 | `movieclip_gotoandstop_framescripts1` | 4 | 7.4s |  |
| 646 | `movieclip_gotoandstop_framescripts2` | 4 | 3.1s |  |
| 647 | `movieclip_gotoandstop_framescripts_self` | 7 | 42.5s |  |
| 648 | `movieclip_gotoandstop_queueing` | 12 | 26.1s |  |
| 649 | `movieclip_hittest` | 67 | 7.5s |  |
| 650 | `movieclip_next_frame` | 2 | 26.1s |  |
| 651 | `movieclip_next_scene` | 6 | 25.9s |  |
| 652 | `movieclip_play` | 3 | 7.3s |  |
| 653 | `movieclip_prev_frame` | 3 | 7.2s |  |
| 654 | `movieclip_prev_scene` | 7 | 7.3s |  |
| 655 | `movieclip_properties` | 79 | 26.3s |  |
| 656 | `movieclip_queued_noop_goto_swf10` | 9 | 7.4s |  |
| 657 | `movieclip_queued_noop_goto_swf9` | 7 | 1.3s |  |
| 658 | `movieclip_scenes` | 11 | 7.3s |  |
| 659 | `movieclip_soundtransform` | 831 | 28.2s |  |
| 660 | `movieclip_stop` | 1 | 26.1s |  |
| 661 | `movieclip_super_is_symbol` | 20 | 7.7s |  |
| 662 | `movieclip_symbol_constr` | 8 | 7.4s |  |
| 663 | `movieclip_text_mousedown` | 1 | 7.4s |  |
| 664 | `movieclip_willtrigger` | 5 | 7.6s |  |
| 665 | `multiply` | 1058 | 19.6s |  |
| 666 | `namespace_constr` | 253 | 7.7s |  |
| 667 | `namespace_constr_args` | 1 | 7.3s |  |
| 668 | `namespace_enumeration_order` | 7 | 26.2s |  |
| 669 | `nan_scale` | 9 | 7.3s |  |
| 670 | `navigateToURL_target_normalize` | 107 | 27.7s |  |
| 671 | `negate` | 30 | 7.3s |  |
| 672 | `negative_volume_panned` | 0 | 7.6s |  |
| 673 | `nested_iteration` | 11 | 7.4s |  |
| 674 | `net_getClassByAlias` | 3 | 7.3s |  |
| 675 | `net_navigateToURL` | 57 | 7.4s |  |
| 676 | `net_stream_play_options` | 6 | 7.4s |  |
| 677 | `netconnection_close` | 55 | 7.4s |  |
| 678 | `netconnection_properties` | 78 | 7.5s |  |
| 679 | `netconnection_send_remote` | 50 | 7.7s |  |
| 680 | `netconnection_serialize_arrays` | 6 | 7.5s |  |
| 681 | `netstream_client` | 10 | 7.5s |  |
| 682 | `netstream_connect` | 7 | 7.4s |  |
| 683 | `newactivation_in_script_init` | 3 | 8.1s |  |
| 684 | `newclass_mismatched` | 4 | 7.8s |  |
| 685 | `newclass_twice` | 3 | 7.8s |  |
| 686 | `nonconflicting_declarations` | 0 | 8.0s |  |
| 687 | `null_void_types` | 8 | 7.9s |  |
| 688 | `number_autoconv` | 21 | 29.4s |  |
| 689 | `number_autoconv_amf` | 132 | 7.9s |  |
| 690 | `number_autoconv_array_sort_32bit` | 1 | 7.9s |  |
| 691 | `number_constr` | 58 | 8.0s |  |
| 692 | `number_toexponential` | 378 | 8.0s |  |
| 693 | `number_toexponential2` | 35 | 7.9s |  |
| 694 | `number_tofixed` | 378 | 7.8s |  |
| 695 | `number_toprecision` | 350 | 8.0s |  |
| 696 | `obfuscated_class_names` | 3 | 7.9s |  |
| 697 | `object_enumeration` | 10 | 7.9s |  |
| 698 | `object_prototype` | 4 | 8.0s |  |
| 699 | `object_to_locale_string` | 2 | 7.9s |  |
| 700 | `object_to_string` | 2 | 7.8s |  |
| 701 | `object_value_of` | 2 | 3.3s |  |
| 702 | `op_coerce` | 54 | 8.0s |  |
| 703 | `op_coerce_x` | 54 | 8.0s |  |
| 704 | `op_escxattr` | 2 | 7.9s |  |
| 705 | `op_escxelem` | 2 | 7.8s |  |
| 706 | `op_lookupswitch` | 4 | 7.9s |  |
| 707 | `optimize_coerce` | 1 | 7.8s |  |
| 708 | `orphan_movie_complex` | 80 | 8.4s |  |
| 709 | `orphan_movie_reorder` | 111 | 29.3s |  |
| 710 | `package_namespace` | 7 | 7.8s |  |
| 711 | `param_default_value_has_zero_cpool_index` | 1 | 7.8s |  |
| 712 | `parent_early_access_child` | 16 | 29.6s |  |
| 713 | `parse_float` | 81 | 8.2s |  |
| 714 | `parse_float_swf10` | 81 | 7.9s |  |
| 715 | `parse_int` | 135 | 8.6s |  |
| 716 | `perspective_projection_basic` | 40 | 8.0s |  |
| 717 | `pixelbender_ceil` | 77 | 8.1s |  |
| 718 | `pixelbender_conditional` | 138 | 43.4s |  |
| 719 | `pixelbender_conversions` | 270 | 7.8s |  |
| 720 | `pixelbender_dithering` | 8 | 34.3s |  |
| 721 | `pixelbender_div` | 36 | 7.5s |  |
| 722 | `pixelbender_effect_BlurredFocus` | 0 | 34.0s |  |
| 723 | `pixelbender_effect_glassDisplace` | 0 | 13.7s |  |
| 724 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 31.0s |  |
| 725 | `pixelbender_effect_smudge` | 0 | 10.8s |  |
| 726 | `pixelbender_effect_tintype` | 0 | 10.0s |  |
| 727 | `pixelbender_effect_twirl` | 0 | 11.7s |  |
| 728 | `pixelbender_eof` | 7 | 7.4s |  |
| 729 | `pixelbender_images` | 0 | 9.8s |  |
| 730 | `pixelbender_input` | 103 | 26.6s |  |
| 731 | `pixelbender_logicalnot` | 20 | 7.3s |  |
| 732 | `pixelbender_malformed_data` | 190 | 26.6s |  |
| 733 | `pixelbender_multiple_out_params` | 1 | 7.3s |  |
| 734 | `pixelbender_no_out_param` | 6 | 7.3s |  |
| 735 | `pixelbender_outputs` | 13 | 7.6s |  |
| 736 | `pixelbender_padding_bytes` | 22 | 7.4s |  |
| 737 | `pixelbender_param_qualifier` | 512 | 7.5s |  |
| 738 | `pixelbender_parameters` | 1563 | 7.7s |  |
| 739 | `pixelbender_parameters_bool` | 240 | 7.6s |  |
| 740 | `pixelbender_parameters_int_vs_bool` | 54 | 7.5s |  |
| 741 | `pixelbender_parse_errors` | 6 | 7.4s |  |
| 742 | `pixelbender_rsqrt` | 24 | 7.5s |  |
| 743 | `pixelbender_select_kinds` | 8 | 7.6s |  |
| 744 | `pixelbender_shaderdata` | 49 | 7.5s |  |
| 745 | `pixelbender_shaderdata_setter` | 99 | 7.9s |  |
| 746 | `pixelbender_sign` | 60 | 7.6s |  |
| 747 | `pixelbender_vector_output` | 11 | 7.6s |  |
| 748 | `place_and_lookup/swf10` | 33 | 7.4s |  |
| 749 | `place_and_lookup/swf9` | 33 | 1.3s |  |
| 750 | `place_multiple` | 17 | 25.8s |  |
| 751 | `place_object_replace` | 9 | 7.5s |  |
| 752 | `place_object_replace_2` | 24 | 7.7s |  |
| 753 | `place_object_same_depth_frame` | 1 | 7.5s |  |
| 754 | `point` | 132 | 8.0s |  |
| 755 | `primitive_edge_cases` | 1 | 7.4s |  |
| 756 | `print_job_options` | 3 | 7.3s |  |
| 757 | `property_is_enumerable_reset` | 23 | 7.6s |  |
| 758 | `property_priority` | 22 | 7.7s |  |
| 759 | `property_priority_chained` | 4 | 7.3s |  |
| 760 | `property_priority_definition_names_order` | 2 | 7.6s |  |
| 761 | `property_priority_three_level` | 6 | 26.5s |  |
| 762 | `propertyisenumerable_namespaces` | 6 | 7.6s |  |
| 763 | `prototype_set_null` | 7 | 7.5s |  |
| 764 | `proxy_callproperty` | 24 | 7.4s |  |
| 765 | `proxy_deleteproperty` | 64 | 7.4s |  |
| 766 | `proxy_enumeration` | 34 | 7.3s |  |
| 767 | `proxy_getproperty` | 77 | 7.3s |  |
| 768 | `proxy_hasownproperty` | 8 | 7.2s |  |
| 769 | `proxy_hasproperty` | 32 | 7.2s |  |
| 770 | `proxy_serialize` | 9 | 7.4s |  |
| 771 | `proxy_setproperty` | 42 | 7.5s |  |
| 772 | `qname_as_lazy_name_attribute_multiname` | 1 | 7.4s |  |
| 773 | `qname_constr` | 32 | 7.5s |  |
| 774 | `qname_constr_namespace` | 24 | 7.4s |  |
| 775 | `qname_enumeration` | 9 | 7.3s |  |
| 776 | `qname_indexing` | 23 | 7.3s |  |
| 777 | `qname_tostring` | 25 | 7.2s |  |
| 778 | `qname_valueof` | 29 | 7.2s |  |
| 779 | `rectangle` | 1094 | 7.9s |  |
| 780 | `regexp_constr` | 148 | 7.4s |  |
| 781 | `regexp_exec` | 19 | 7.2s |  |
| 782 | `regexp_extended` | 47 | 7.2s |  |
| 783 | `regexp_multiargs` | 1 | 7.1s |  |
| 784 | `regexp_test` | 27 | 7.2s |  |
| 785 | `regexp_toString` | 10 | 7.2s |  |
| 786 | `register_script_refresh` | 35 | 25.8s |  |
| 787 | `remove_child_clear_field` | 88 | 7.6s |  |
| 788 | `remove_dobj` | 3 | 7.1s |  |
| 789 | `resolve_order` | 4 | 7.1s |  |
| 790 | `responder_null_callbacks` | 1 | 7.2s |  |
| 791 | `rng` | 1 | 8.3s |  |
| 792 | `rootless` | 42 | 7.3s |  |
| 793 | `rshift` | 1058 | 19.2s |  |
| 794 | `rtqname_not_namespace` | 12 | 7.3s |  |
| 795 | `sandbox_type_inherited` | 2 | 7.7s |  |
| 796 | `sandbox_type_local_file` | 1 | 46.5s |  |
| 797 | `sandbox_type_local_network` | 1 | 7.7s |  |
| 798 | `scene_constr` | 8 | 8.3s |  |
| 799 | `scopes_dont_cache/order-1` | 1 | 29.1s |  |
| 800 | `scopes_dont_cache/order-2` | 1 | 1.1s |  |
| 801 | `security_domain_current` | 2 | 8.0s |  |
| 802 | `selection` | 239 | 8.4s |  |
| 803 | `set_local_0` | 31 | 8.0s |  |
| 804 | `set_property_is_enumerable` | 85 | 8.4s |  |
| 805 | `shaderparameter_value` | 4 | 8.0s |  |
| 806 | `shape_drawrect` | 54 | 7.9s |  |
| 807 | `shared_object_no_root` | 3 | 7.9s |  |
| 808 | `simplebutton_added_to_stage` | 45 | 28.6s |  |
| 809 | `simplebutton_childevents` | 86 | 29.1s |  |
| 810 | `simplebutton_childevents_nested` | 54 | 8.3s |  |
| 811 | `simplebutton_childevents_sprite` | 13 | 8.0s |  |
| 812 | `simplebutton_childprops` | 144 | 8.2s |  |
| 813 | `simplebutton_childshuffle` | 23 | 7.8s |  |
| 814 | `simplebutton_constr` | 36 | 8.2s |  |
| 815 | `simplebutton_constr_childevents` | 48 | 8.2s |  |
| 816 | `simplebutton_constr_params` | 42 | 8.0s |  |
| 817 | `simplebutton_mouseenabled` | 26 | 7.9s |  |
| 818 | `simplebutton_multi_children` | 19 | 8.2s |  |
| 819 | `simplebutton_structure` | 27 | 8.3s |  |
| 820 | `simplebutton_symbolclass` | 68 | 8.5s |  |
| 821 | `slot_disp_id_shared_numbering` | 1 | 29.2s |  |
| 822 | `slots_force_autoassigned` | 1 | 7.8s |  |
| 823 | `socket_after_disconnect` | 1 | 7.9s |  |
| 824 | `socket_close` | 2 | 7.8s |  |
| 825 | `socket_connect` | 4 | 7.8s |  |
| 826 | `socket_errors` | 56 | 8.3s |  |
| 827 | `socket_read_big` | 48 | 7.8s |  |
| 828 | `socket_read_little` | 48 | 3.3s |  |
| 829 | `socket_read_write_object` | 8 | 44.0s |  |
| 830 | `socket_write_big` | 15 | 7.8s |  |
| 831 | `socket_write_little` | 14 | 7.6s |  |
| 832 | `sound_embeddedprops` | 26 | 7.9s |  |
| 833 | `sound_play` | 19 | 7.8s |  |
| 834 | `sound_valueof` | 33 | 7.6s |  |
| 835 | `soundchannel_soundtransform` | 835 | 29.0s |  |
| 836 | `soundchannel_soundtransform_exists` | 5 | 27.3s |  |
| 837 | `soundchannel_stop` | 8 | 27.1s |  |
| 838 | `soundmixer_buffertime` | 5 | 7.6s |  |
| 839 | `soundmixer_stopall` | 6 | 27.0s |  |
| 840 | `soundtransform` | 442 | 13.5s |  |
| 841 | `space_justifier_clone` | 12 | 7.7s |  |
| 842 | `sprite_with_frames` | 0 | 29.4s |  |
| 843 | `stage3d_agal_cross_product` | 0 | 10.4s |  |
| 844 | `stage3d_agal_upload_errors` | 66 | 10.3s |  |
| 845 | `stage3d_bitmap` | 0 | 32.4s |  |
| 846 | `stage3d_blend` | 81 | 31.6s |  |
| 847 | `stage3d_context3d_string_args` | 158 | 8.6s |  |
| 848 | `stage3d_errors` | 7 | 7.6s |  |
| 849 | `stage3d_errors_atf` | 3 | 9.0s |  |
| 850 | `stage3d_errors_swf_29` | 6 | 7.8s |  |
| 851 | `stage3d_float1_index` | 0 | 29.8s |  |
| 852 | `stage3d_fractal` | 0 | 30.3s |  |
| 853 | `stage3d_ignore_sampler_override` | 0 | 30.2s |  |
| 854 | `stage3d_multistage_triangle` | 3 | 10.6s |  |
| 855 | `stage3d_program_constants_bytearray_be` | 0 | 31.4s |  |
| 856 | `stage3d_program_constants_bytearray_le` | 0 | 11.1s |  |
| 857 | `stage3d_program_constants_invalid_input` | 21 | 8.6s |  |
| 858 | `stage3d_raytrace` | 0 | 34.8s |  |
| 859 | `stage3d_rotating_cube` | 0 | 11.3s |  |
| 860 | `stage3d_sampler` | 0 | 10.5s |  |
| 861 | `stage3d_sampler_partial_upload` | 0 | 10.4s |  |
| 862 | `stage3d_stencil` | 0 | 30.8s |  |
| 863 | `stage3d_texture` | 0 | 33.9s |  |
| 864 | `stage3d_texture_bytearray` | 0 | 11.7s |  |
| 865 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 11.0s |  |
| 866 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 12.1s |  |
| 867 | `stage3d_triangle` | 0 | 10.4s |  |
| 868 | `stage3d_triangle_bytes4` | 0 | 10.3s |  |
| 869 | `stage3d_triangle_float1` | 0 | 10.2s |  |
| 870 | `stage3d_triangle_index_upload` | 0 | 10.2s |  |
| 871 | `stage3d_x_y` | 22 | 7.5s |  |
| 872 | `stage_access` | 10 | 7.5s |  |
| 873 | `stage_displayobject_properties` | 24 | 7.3s |  |
| 874 | `stage_domain_getQualifiedDefinitionNames` | 5 | 7.4s |  |
| 875 | `stage_framerate_nan` | 7 | 26.5s |  |
| 876 | `stage_framerate_negative` | 6 | 7.4s |  |
| 877 | `stage_framerate_zero` | 6 | 7.4s |  |
| 878 | `stage_invalidate` | 38 | 7.7s |  |
| 879 | `stage_loaderinfo_properties` | 24 | 26.4s |  |
| 880 | `stage_mousechildren` | 2 | 7.4s |  |
| 881 | `stage_mouseenabled` | 15 | 7.3s |  |
| 882 | `stage_overriden_setters` | 31 | 7.6s |  |
| 883 | `stage_properties` | 30 | 7.4s |  |
| 884 | `stage_stage3Ds_vector` | 1 | 26.1s |  |
| 885 | `static_text` | 3 | 7.6s |  |
| 886 | `static_var_with_this_in_ctor` | 2 | 7.4s |  |
| 887 | `statictext_text` | 8 | 7.6s |  |
| 888 | `stored_properties` | 11 | 7.4s |  |
| 889 | `strict_equality` | 34 | 7.4s |  |
| 890 | `string_call` | 13 | 7.4s |  |
| 891 | `string_case` | 23 | 7.4s |  |
| 892 | `string_char_at` | 27 | 7.4s |  |
| 893 | `string_char_code_at` | 28 | 7.3s |  |
| 894 | `string_concat_fromcharcode` | 37 | 7.4s |  |
| 895 | `string_constr` | 25 | 7.4s |  |
| 896 | `string_indexof_lastindexof` | 87 | 7.7s |  |
| 897 | `string_length` | 16 | 7.4s |  |
| 898 | `string_locale_compare` | 39 | 7.7s |  |
| 899 | `string_match` | 51 | 33.9s |  |
| 900 | `string_relational_compare` | 4 | 5.9s |  |
| 901 | `string_replace` | 51 | 6.0s |  |
| 902 | `string_search` | 41 | 6.1s |  |
| 903 | `string_slice_substr_substring` | 170 | 6.7s |  |
| 904 | `string_split` | 29 | 6.0s |  |
| 905 | `string_substr_negative` | 21 | 5.9s |  |
| 906 | `string_substr_weird` | 182 | 5.8s |  |
| 907 | `stylesheet` | 221 | 6.3s |  |
| 908 | `stylesheet_parse_color` | 69 | 5.9s |  |
| 909 | `stylesheet_transform` | 307 | 6.2s |  |
| 910 | `subclass_superclass_linked_symbol` | 4 | 6.3s |  |
| 911 | `subtract` | 1058 | 14.7s |  |
| 912 | `super_get_call` | 12 | 5.9s |  |
| 913 | `supercall_two_classobjects` | 2 | 5.9s |  |
| 914 | `supercalls_weird` | 2 | 5.8s |  |
| 915 | `superinterface_call` | 20 | 5.9s |  |
| 916 | `superinterface_instanceof` | 18 | 5.9s |  |
| 917 | `swf8` | 1 | 5.8s |  |
| 918 | `swf_10_queued_goto_scripts_construct` | 52 | 20.9s |  |
| 919 | `swf_9_goto_in_enter_frame` | 17 | 6.0s |  |
| 920 | `swf_9_goto_in_enter_frame_simple` | 15 | 6.0s |  |
| 921 | `swf_9_queued_goto_scripts` | 6 | 20.8s |  |
| 922 | `swf_9_queued_goto_scripts_construct` | 28 | 1.1s |  |
| 923 | `swf_9_versioning` | 2 | 5.9s |  |
| 924 | `swf_wrong_frame_count` | 38 | 6.2s |  |
| 925 | `swf_wrong_frame_count_isplaying` | 22 | 20.6s |  |
| 926 | `symbol_class_binary_data` | 8 | 5.9s |  |
| 927 | `symbol_class_conflict` | 4 | 7.7s |  |
| 928 | `symbol_class_root_not_zero` | 1 | 5.8s |  |
| 929 | `symbolclass_invalid_utf8` | 2 | 5.9s |  |
| 930 | `system_setclipboard_null` | 1 | 5.8s |  |
| 931 | `tab_ordering_arrows` | 998 | 21.8s |  |
| 932 | `tab_ordering_automatic_advanced` | 184 | 6.5s |  |
| 933 | `tab_ordering_automatic_basic` | 45 | 5.9s |  |
| 934 | `tab_ordering_children` | 116 | 42.6s |  |
| 935 | `tab_ordering_custom_basic` | 34 | 7.0s |  |
| 936 | `tab_ordering_stage_tab_children` | 32 | 7.0s |  |
| 937 | `tab_ordering_stage_tab_children_remove_root` | 5 | 7.0s |  |
| 938 | `tab_ordering_tabbable` | 47 | 7.1s |  |
| 939 | `tabstop_properties` | 105 | 7.5s |  |
| 940 | `text_element_basic` | 34 | 7.2s |  |
| 941 | `text_engine_fontdescription` | 27 | 7.2s |  |
| 942 | `text_engine_groupelement` | 64 | 7.9s |  |
| 943 | `text_run` | 7 | 7.0s |  |
| 944 | `textblock_createline_errors` | 23 | 7.3s |  |
| 945 | `textblock_createline_fte` | 9 | 26.0s |  |
| 946 | `textblock_properties` | 118 | 7.5s |  |
| 947 | `textbox_click` | 37 | 26.0s |  |
| 948 | `textfield_event` | 66 | 7.3s |  |
| 949 | `textfield_focusin_event` | 9 | 7.0s |  |
| 950 | `textfield_input_dead_keys_windows` | 15 | 7.1s |  |
| 951 | `textfield_unload` | 39 | 25.9s |  |
| 952 | `textformat` | 1134 | 7.2s |  |
| 953 | `textformat_display` | 14 | 7.1s |  |
| 954 | `textformat_font_max_length` | 4 | 7.0s |  |
| 955 | `textline_inapplicable_properties` | 10 | 7.1s |  |
| 956 | `textline_name` | 1 | 7.0s |  |
| 957 | `textline_splitting_basic` | 76 | 7.2s |  |
| 958 | `textline_throwerror` | 30 | 7.0s |  |
| 959 | `textline_validity` | 162 | 7.2s |  |
| 960 | `throw` | 3 | 7.0s |  |
| 961 | `timeline_scripts` | 3 | 7.3s |  |
| 962 | `timer` | 90 | 8.1s |  |
| 963 | `timer_events` | 3 | 7.2s |  |
| 964 | `timer_finished` | 11 | 7.2s |  |
| 965 | `timer_reset` | 8 | 7.4s |  |
| 966 | `timer_setdelay` | 5 | 7.2s |  |
| 967 | `trace` | 12 | 7.0s |  |
| 968 | `truthiness` | 30 | 7.0s |  |
| 969 | `try_catch` | 11 | 23.6s |  |
| 970 | `try_catch_typed` | 12 | 7.2s |  |
| 971 | `typeof` | 30 | 7.1s |  |
| 972 | `uint_constr` | 92 | 7.2s |  |
| 973 | `uint_tofixed` | 1215 | 7.0s |  |
| 974 | `uint_tostring` | 3375 | 7.3s |  |
| 975 | `uncaught_error_basic` | 2 | 7.1s |  |
| 976 | `unchecked_function` | 15 | 7.0s |  |
| 977 | `unescape` | 28 | 7.0s |  |
| 978 | `url_loader` | 25 | 7.1s |  |
| 979 | `url_vars` | 27 | 7.1s |  |
| 980 | `urlrequest` | 18 | 25.5s |  |
| 981 | `urlstream_basic` | 5 | 7.0s |  |
| 982 | `urshift` | 1058 | 18.9s |  |
| 983 | `utils3d` | 7 | 7.1s |  |
| 984 | `vector3d` | 397 | 11.7s |  |
| 985 | `vector_class` | 36 | 7.5s |  |
| 986 | `vector_class_call` | 11 | 7.3s |  |
| 987 | `vector_coercion` | 66 | 7.9s |  |
| 988 | `vector_concat` | 90 | 7.7s |  |
| 989 | `vector_constr` | 107 | 7.8s |  |
| 990 | `vector_enumeration` | 5 | 7.0s |  |
| 991 | `vector_every` | 92 | 7.9s |  |
| 992 | `vector_filter` | 95 | 7.9s |  |
| 993 | `vector_holes` | 24 | 7.1s |  |
| 994 | `vector_indexof` | 302 | 11.7s |  |
| 995 | `vector_insertat` | 270 | 8.2s |  |
| 996 | `vector_int_access` | 4 | 7.1s |  |
| 997 | `vector_int_delete` | 11 | 7.1s |  |
| 998 | `vector_join` | 58 | 7.5s |  |
| 999 | `vector_lastindexof` | 302 | 7.0s |  |
| 1000 | `vector_legacy` | 10 | 7.2s |  |
| 1001 | `vector_map` | 85 | 7.8s |  |
| 1002 | `vector_object_final` | 1 | 7.0s |  |
| 1003 | `vector_object_toString` | 10 | 7.0s |  |
| 1004 | `vector_pushpop` | 255 | 8.3s |  |
| 1005 | `vector_reborrow_bug` | 10 | 7.0s |  |
| 1006 | `vector_removeat` | 172 | 25.4s |  |
| 1007 | `vector_reverse` | 232 | 8.6s |  |
| 1008 | `vector_shiftunshift` | 252 | 9.0s |  |
| 1009 | `vector_slice` | 331 | 9.4s |  |
| 1010 | `vector_sort` | 905 | 17.4s |  |
| 1011 | `vector_splice` | 693 | 11.9s |  |
| 1012 | `vector_splice_fixed_bug_compat` | 4 | 27.5s |  |
| 1013 | `vector_tostring` | 79 | 8.3s |  |
| 1014 | `verification` | 8 | 7.8s |  |
| 1015 | `verify_abnormal_loop` | 1 | 7.6s |  |
| 1016 | `verify_dxns_without_flag` | 3 | 8.0s |  |
| 1017 | `verify_exception_target_two_jumps` | 1 | 7.6s |  |
| 1018 | `verify_exception_targets_edge_case` | 1 | 7.5s |  |
| 1019 | `verify_illegal_opcode` | 1 | 3.6s |  |
| 1020 | `verify_jump_to_middle_of_op` | 1 | 7.6s |  |
| 1021 | `verify_lookup_switch_edge_case` | 1 | 7.4s |  |
| 1022 | `verify_method_info_oob` | 1 | 1.2s |  |
| 1023 | `verify_stack` | 5 | 7.4s |  |
| 1024 | `verify_typecheck` | 4 | 7.4s |  |
| 1025 | `verify_unreachable_exception` | 2 | 7.3s |  |
| 1026 | `versioned_isplaying` | 2 | 7.4s |  |
| 1027 | `virtual_properties` | 16 | 7.4s |  |
| 1028 | `with` | 4 | 7.6s |  |
| 1029 | `wrong_arg_count` | 7 | 7.7s |  |
| 1030 | `xml_abstract_equality` | 36 | 7.9s |  |
| 1031 | `xml_advanced` | 52 | 7.6s |  |
| 1032 | `xml_appendchild` | 10 | 7.5s |  |
| 1033 | `xml_appendchild_swf_v21` | 13 | 7.8s |  |
| 1034 | `xml_as_attribute` | 9 | 7.4s |  |
| 1035 | `xml_attribute` | 35 | 7.5s |  |
| 1036 | `xml_attribute_name` | 40 | 7.5s |  |
| 1037 | `xml_basic` | 33 | 7.6s |  |
| 1038 | `xml_child` | 25 | 7.6s |  |
| 1039 | `xml_childindex` | 7 | 7.4s |  |
| 1040 | `xml_children` | 43 | 7.9s |  |
| 1041 | `xml_class_call` | 9 | 7.3s |  |
| 1042 | `xml_contains` | 197 | 7.4s |  |
| 1043 | `xml_copy` | 20 | 3.1s |  |
| 1044 | `xml_ctor_from_tostring` | 23 | 19.1s |  |
| 1045 | `xml_delete` | 114 | 6.0s |  |
| 1046 | `xml_descendants` | 83 | 20.8s |  |
| 1047 | `xml_elements` | 6 | 5.9s |  |
| 1048 | `xml_equals_namespace_check` | 2 | 6.1s |  |
| 1049 | `xml_explicit_use_namespace` | 5 | 5.9s |  |
| 1050 | `xml_getdescendants_qname` | 21 | 6.1s |  |
| 1051 | `xml_has_property_via_in` | 26 | 5.9s |  |
| 1052 | `xml_hasownproperty` | 6 | 5.8s |  |
| 1053 | `xml_ignore_white` | 6 | 5.9s |  |
| 1054 | `xml_length` | 2 | 5.9s |  |
| 1055 | `xml_list_as_attribute` | 9 | 6.2s |  |
| 1056 | `xml_list_concat` | 20 | 6.0s |  |
| 1057 | `xml_list_delete_clear_parent` | 6 | 5.8s |  |
| 1058 | `xml_list_enumerate` | 4 | 5.8s |  |
| 1059 | `xml_methods_settings` | 3 | 5.8s |  |
| 1060 | `xml_mismatched_tag` | 37 | 5.9s |  |
| 1061 | `xml_namespace` | 39 | 5.9s |  |
| 1062 | `xml_namespace_methods` | 245 | 5.9s |  |
| 1063 | `xml_namespaced_property` | 7 | 5.9s |  |
| 1064 | `xml_no_namespace` | 1 | 5.8s |  |
| 1065 | `xml_nodekind` | 3 | 6.0s |  |
| 1066 | `xml_normalize` | 35 | 5.9s |  |
| 1067 | `xml_notification_bubbling` | 361 | 5.8s |  |
| 1068 | `xml_parent` | 8 | 5.9s |  |
| 1069 | `xml_set_children` | 17 | 5.9s |  |
| 1070 | `xml_set_name` | 34 | 5.8s |  |
| 1071 | `xml_settings` | 6 | 2.5s |  |
| 1072 | `xml_simple_complex_content` | 47 | 5.8s |  |
| 1073 | `xml_socket` | 11 | 6.2s |  |
| 1074 | `xml_text` | 7 | 5.9s |  |
| 1075 | `xml_tostring` | 6 | 5.8s |  |
| 1076 | `xml_tostring_namespace` | 12 | 5.8s |  |
| 1077 | `xml_unescaping` | 23 | 5.9s |  |
| 1078 | `xml_weird_ignores` | 54 | 5.9s |  |
| 1079 | `xml_wildcard` | 11 | 5.8s |  |
| 1080 | `xmldocument` | 254 | 6.0s |  |
| 1081 | `xmlnode` | 3540 | 5.9s |  |
| 1082 | `zero_frame_clip` | 3 | 6.3s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `coerce_property` | 3 | 3 | 6.2s |  |
| 2 | `error_1034_debug_string` | 19 | 19 | 7.9s |  |
| 3 | `uncaught_errors_stringified` | 15 | 15 | 7.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**22 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 2 | `perspective_projection` | 94.8% | 1368 | 1443 | 75 |  |
| 3 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 4 | `cross_api_version_call_newer` | 91.7% | 11 | 12 | 1 |  |
| 5 | `error_stack_trace` | 84.4% | 38 | 45 | 7 |  |
| 6 | `matrix` | 83.4% | 282 | 338 | 56 |  |
| 7 | `number_convert_edge_cases` | 82.2% | 148 | 180 | 32 |  |
| 8 | `textblock_line_changes` | 79.1% | 125 | 158 | 33 |  |
| 9 | `graphic_linkage` | 77.8% | 7 | 9 | 2 |  |
| 10 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 11 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 12 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 13 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 14 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 15 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 16 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 17 | `delayed_symbolclass` | 57.1% | 16 | 28 | 12 |  |
| 18 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 19 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 20 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 21 | `sub_super_same_field` | 50.0% | 6 | 12 | 6 |  |
| 22 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**86 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 2 | `perspective_projection` | 94.8% | 1368/1443 | 1443 | 1443 |  |
| 3 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 4 | `cross_api_version_call_newer` | 91.7% | 11/12 | 12 | 12 |  |
| 5 | `error_stack_trace` | 84.4% | 38/45 | 45 | 45 |  |
| 6 | `matrix` | 83.4% | 282/338 | 286 | 338 |  |
| 7 | `number_convert_edge_cases` | 82.2% | 148/180 | 180 | 180 |  |
| 8 | `textblock_line_changes` | 79.1% | 125/158 | 158 | 158 |  |
| 9 | `graphic_linkage` | 77.8% | 7/9 | 9 | 9 |  |
| 10 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 11 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 12 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 13 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 14 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 15 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 16 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 17 | `delayed_symbolclass` | 57.1% | 16/28 | 28 | 28 |  |
| 18 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 19 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 20 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 21 | `sub_super_same_field` | 50.0% | 6/12 | 12 | 12 |  |
| 22 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 23 | `loader_duplicate_class` | 46.9% | 23/49 | 49 | 48 |  |
| 24 | `static_length` | 45.8% | 11/24 | 24 | 24 |  |
| 25 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 26 | `textblock_recreateline` | 40.8% | 40/98 | 89 | 98 |  |
| 27 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 28 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 29 | `property_is_enumerable` | 21.9% | 25/114 | 27 | 114 |  |
| 30 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 31 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 32 | `doabc_and_symbolclass_script_init_normal` | 16.7% | 1/6 | 6 | 6 |  |
| 33 | `xml_list_ctor_errors` | 14.7% | 5/34 | 28 | 34 |  |
| 34 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 35 | `doabc_and_symbolclass_script_init_goto` | 12.5% | 1/8 | 8 | 7 |  |
| 36 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 37 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 38 | `stage_properties2` | 10.8% | 23/213 | 171 | 213 |  |
| 39 | `primitive_valueOf` | 8.8% | 25/285 | 240 | 285 |  |
| 40 | `proxy_not_overridden` | 7.4% | 4/54 | 45 | 54 |  |
| 41 | `primitive_toString` | 7.2% | 20/277 | 240 | 277 |  |
| 42 | `error_throwerror` | 5.8% | 6/103 | 57 | 103 |  |
| 43 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 44 | `timer_invalid_delay` | 3.3% | 1/30 | 12 | 30 |  |
| 45 | `external_interface` | 2.9% | 3/105 | 8 | 105 |  |
| 46 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 47 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 48 | `all_classes/accessibility/swf9` | 1.4% | 1/73 | 20 | 73 |  |
| 49 | `all_classes/accessibility/swf10` | 1.1% | 1/88 | 20 | 88 |  |
| 50 | `all_classes/accessibility/swf30` | 1.1% | 1/88 | 20 | 88 |  |
| 51 | `all_classes/display3D/swf12` | 0.9% | 1/109 | 109 | 61 |  |
| 52 | `describe_type_basic` | 0.7% | 1/152 | 71 | 152 |  |
| 53 | `describe_type_json` | 0.3% | 1/301 | 5 | 301 |  |
| 54 | `all_classes/display3D/swf30` | 0.2% | 1/412 | 109 | 412 |  |
| 55 | `loaderinfo_quine` | 0.1% | 1/1005 | 2 | 1005 |  |
| 56 | `all_classes/display/swf9` | 0.1% | 1/1959 | 357 | 1959 |  |
| 57 | `all_classes/display/swf10` | 0.0% | 1/2569 | 357 | 2569 |  |
| 58 | `all_classes/display/swf11` | 0.0% | 1/2593 | 357 | 2593 |  |
| 59 | `all_classes/display/swf12` | 0.0% | 1/2593 | 357 | 2593 |  |
| 60 | `all_classes/display/swf13` | 0.0% | 1/2671 | 357 | 2671 |  |
| 61 | `all_classes/display/swf30` | 0.0% | 1/2936 | 357 | 2936 |  |
| 62 | `accessibilityimplementation` | 0.0% | 0/18 | 4 | 18 |  |
| 63 | `all_classes/display3D/swf13` | 0.0% | 0/326 | 109 | 326 |  |
| 64 | `all_classes/errors/swf10` | 0.0% | 0/140 | 56 | 140 |  |
| 65 | `all_classes/errors/swf30` | 0.0% | 0/140 | 56 | 140 |  |
| 66 | `all_classes/errors/swf9` | 0.0% | 0/121 | 56 | 121 |  |
| 67 | `all_classes/security/swf12` | 0.0% | 0/19 | 3 | 19 |  |
| 68 | `all_classes/security/swf13` | 0.0% | 0/53 | 3 | 53 |  |
| 69 | `all_classes/security/swf30` | 0.0% | 0/53 | 3 | 53 |  |
| 70 | `all_classes/xml/swf30` | 0.0% | 0/116 | 19 | 116 |  |
| 71 | `all_classes/xml/swf9` | 0.0% | 0/116 | 19 | 116 |  |
| 72 | `constructsuper_null` | 0.0% | 0/2 | 2 | 2 |  |
| 73 | `currency_parse_result` | 0.0% | 0/7 | 2 | 7 |  |
| 74 | `describe_type_metadata` | 0.0% | 0/125 | 7 | 125 |  |
| 75 | `describe_type_native` | 0.0% | 0/23 | 6 | 23 |  |
| 76 | `error_stack_trace_edge_cases` | 0.0% | 0/6 | 4 | 6 |  |
| 77 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 78 | `json_stringify_function` | 0.0% | 0/12 | 12 | 12 |  |
| 79 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 80 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 81 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 82 | `netfilterevent` | 0.0% | 0/10 | 2 | 10 |  |
| 83 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 84 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 85 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
| 86 | `system_exit` | 0.0% | 0/3 | 2 | 3 |  |
