# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-16 08:44 UTC

**Git SHA**: `88ebde6653`

**Run Duration**: 219m 50s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 1251 |
| Passing | **1153** (92.2%) |
| Ruffle-matched | 31 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **1184** (94.6%) |
| Failing | 67 |
| Total expected lines | 154806 |
| Matching lines | 142202 (91.9%) |
| Mismatched lines | 12604 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 67 | 100.0% |

## Passing Tests

**1153 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `abstract_classes` | 132 | 25.9s |  |
| 2 | `accessibility` | 1 | 6.8s |  |
| 3 | `accessibilityimplementation` | 18 | 6.9s |  |
| 4 | `activation_class` | 6 | 25.6s |  |
| 5 | `add` | 1058 | 18.0s |  |
| 6 | `agal_compiler` | 13 | 9.1s |  |
| 7 | `air_datagram_socket` | 1 | 8.8s |  |
| 8 | `air_hidden_lookup` | 2 | 6.8s |  |
| 9 | `air_ifilepromise` | 1 | 6.7s |  |
| 10 | `all_classes/accessibility/swf10` | 88 | 6.8s |  |
| 11 | `all_classes/accessibility/swf30` | 88 | 0.7s |  |
| 12 | `all_classes/accessibility/swf9` | 73 | 0.7s |  |
| 13 | `all_classes/display/swf10` | 2569 | 6.8s |  |
| 14 | `all_classes/display/swf11` | 2593 | 0.7s |  |
| 15 | `all_classes/display/swf12` | 2593 | 0.7s |  |
| 16 | `all_classes/display/swf13` | 2671 | 0.7s |  |
| 17 | `all_classes/display/swf30` | 2936 | 0.7s |  |
| 18 | `all_classes/display/swf9` | 1959 | 0.7s |  |
| 19 | `all_classes/display3D/swf12` | 61 | 6.8s |  |
| 20 | `all_classes/display3D/swf13` | 326 | 0.6s |  |
| 21 | `all_classes/display3D/swf30` | 412 | 0.6s |  |
| 22 | `all_classes/errors/swf10` | 140 | 6.8s |  |
| 23 | `all_classes/errors/swf30` | 140 | 0.6s |  |
| 24 | `all_classes/errors/swf9` | 121 | 0.6s |  |
| 25 | `all_classes/security/swf11` | 3 | 6.8s |  |
| 26 | `all_classes/security/swf12` | 19 | 0.6s |  |
| 27 | `all_classes/security/swf13` | 53 | 0.6s |  |
| 28 | `all_classes/security/swf30` | 53 | 0.6s |  |
| 29 | `all_classes/xml/swf30` | 116 | 6.8s |  |
| 30 | `all_classes/xml/swf9` | 116 | 0.6s |  |
| 31 | `amf_array_serialization` | 17 | 28.4s |  |
| 32 | `amf_custom_obj` | 26 | 6.9s |  |
| 33 | `amf_dictionary` | 9 | 6.8s |  |
| 34 | `amf_function` | 46 | 6.8s |  |
| 35 | `amf_invalid_date` | 2 | 6.7s |  |
| 36 | `amf_missing_prop` | 6 | 6.8s |  |
| 37 | `amf_nondynamic_function_prop` | 6 | 6.8s |  |
| 38 | `amf_setter_error` | 8 | 6.7s |  |
| 39 | `amf_vector` | 40 | 6.7s |  |
| 40 | `amf_xml` | 6 | 6.5s |  |
| 41 | `application_domain` | 4 | 6.5s |  |
| 42 | `applicationdomain_getqualifieddefinitionnames` | 9 | 6.6s |  |
| 43 | `applicationdomain_hasdefinition_null` | 2 | 24.9s |  |
| 44 | `array_access` | 18 | 6.6s |  |
| 45 | `array_access_interpreter` | 4 | 6.5s |  |
| 46 | `array_access_no_pubns` | 2 | 6.5s |  |
| 47 | `array_concat` | 41 | 6.6s |  |
| 48 | `array_constr` | 10 | 6.5s |  |
| 49 | `array_delete` | 44 | 6.6s |  |
| 50 | `array_enumeration` | 10 | 6.5s |  |
| 51 | `array_enumeration_elements` | 11 | 6.5s |  |
| 52 | `array_every` | 8 | 6.5s |  |
| 53 | `array_filter` | 6 | 6.5s |  |
| 54 | `array_foreach` | 18 | 6.5s |  |
| 55 | `array_hasownproperty` | 11 | 6.5s |  |
| 56 | `array_holes` | 9 | 6.5s |  |
| 57 | `array_index_max` | 84 | 6.4s |  |
| 58 | `array_indexof` | 25 | 6.5s |  |
| 59 | `array_join` | 26 | 6.5s |  |
| 60 | `array_lastindexof` | 29 | 6.5s |  |
| 61 | `array_length` | 14 | 6.5s |  |
| 62 | `array_literal` | 3 | 6.5s |  |
| 63 | `array_map` | 8 | 6.3s |  |
| 64 | `array_pop` | 52 | 6.6s |  |
| 65 | `array_push` | 24 | 6.5s |  |
| 66 | `array_reborrow_bug` | 6 | 6.5s |  |
| 67 | `array_reverse` | 28 | 6.5s |  |
| 68 | `array_shift` | 51 | 2.4s |  |
| 69 | `array_slice` | 39 | 6.6s |  |
| 70 | `array_some` | 8 | 6.5s |  |
| 71 | `array_sort` | 297 | 7.0s |  |
| 72 | `array_sort_fun_swf12` | 2 | 6.5s |  |
| 73 | `array_sort_fun_swf13` | 2 | 0.7s |  |
| 74 | `array_sort_random` | 210 | 6.6s |  |
| 75 | `array_sort_swf10_32bit` | 1 | 6.5s |  |
| 76 | `array_sorton` | 545 | 7.3s |  |
| 77 | `array_sparse_ops` | 41 | 26.2s |  |
| 78 | `array_splice` | 133 | 7.0s |  |
| 79 | `array_splice2` | 428 | 7.0s |  |
| 80 | `array_splice_types` | 48 | 6.7s |  |
| 81 | `array_storage` | 8 | 6.7s |  |
| 82 | `array_tolocalestring` | 9 | 6.6s |  |
| 83 | `array_tostring` | 12 | 6.6s |  |
| 84 | `array_unshift` | 24 | 6.6s |  |
| 85 | `array_valueof` | 9 | 6.6s |  |
| 86 | `array_vector_null_callback` | 10 | 6.8s |  |
| 87 | `astype` | 28 | 25.6s |  |
| 88 | `astypelate` | 24 | 6.7s |  |
| 89 | `astypelate_propagates` | 1 | 6.6s |  |
| 90 | `asymmetric_key_events` | 11 | 6.8s |  |
| 91 | `av_classes` | 340 | 7.0s |  |
| 92 | `avm1movie_addcallback_call` | 14 | 6.8s |  |
| 93 | `avm2_catchup_dobj` | 158 | 7.2s |  |
| 94 | `away3d_advanced_shallow_water_demo` | 0 | 86.8s |  |
| 95 | `bevel_filter` | 187 | 6.8s |  |
| 96 | `bitand` | 1058 | 19.0s |  |
| 97 | `bitmap_constr` | 17 | 7.1s |  |
| 98 | `bitmap_data` | 1000 | 15.6s |  |
| 99 | `bitmap_pixelsnapping` | 2 | 26.5s |  |
| 100 | `bitmap_properties` | 23 | 6.7s |  |
| 101 | `bitmap_subclass` | 7 | 8.1s |  |
| 102 | `bitmap_subclass_properties` | 9 | 7.1s |  |
| 103 | `bitmap_timeline` | 9 | 6.7s |  |
| 104 | `bitmapdata_accuracy` | 1 | 43.8s |  |
| 105 | `bitmapdata_applyfilter_blur` | 0 | 26.6s |  |
| 106 | `bitmapdata_applyfilter_colormatrix` | 0 | 7.0s |  |
| 107 | `bitmapdata_applyfilter_destpoint` | 0 | 26.4s |  |
| 108 | `bitmapdata_applyfilter_destpoint_edges` | 0 | 26.9s |  |
| 109 | `bitmapdata_clone` | 13 | 6.8s |  |
| 110 | `bitmapdata_colortransform` | 0 | 6.9s |  |
| 111 | `bitmapdata_colortransform_oob` | 2 | 6.6s |  |
| 112 | `bitmapdata_constr` | 22 | 6.8s |  |
| 113 | `bitmapdata_constructor_from_timeline` | 1 | 7.1s |  |
| 114 | `bitmapdata_copychannel` | 0 | 27.5s |  |
| 115 | `bitmapdata_copypixels` | 23 | 26.0s |  |
| 116 | `bitmapdata_copypixels_blend_over` | 1 | 4.5s |  |
| 117 | `bitmapdata_copypixelstobytearray` | 39 | 4.3s |  |
| 118 | `bitmapdata_dispose` | 7 | 4.4s |  |
| 119 | `bitmapdata_draw` | 0 | 16.5s |  |
| 120 | `bitmapdata_draw_alpha_erase` | 8 | 4.3s |  |
| 121 | `bitmapdata_draw_colortransform` | 0 | 16.8s |  |
| 122 | `bitmapdata_draw_cpu_overwrite_gpu` | 0 | 16.7s |  |
| 123 | `bitmapdata_draw_filters` | 0 | 17.1s |  |
| 124 | `bitmapdata_draw_masks` | 0 | 4.4s |  |
| 125 | `bitmapdata_draw_rotation` | 0 | 4.3s |  |
| 126 | `bitmapdata_draw_self_via_graphic` | 0 | 4.5s |  |
| 127 | `bitmapdata_draw_stage` | 0 | 16.2s |  |
| 128 | `bitmapdata_drawwithquality` | 0 | 4.5s |  |
| 129 | `bitmapdata_embedded` | 9 | 4.4s |  |
| 130 | `bitmapdata_fillrect` | 0 | 4.5s |  |
| 131 | `bitmapdata_filter_sourcerect` | 0 | 16.3s |  |
| 132 | `bitmapdata_floodfill` | 35 | 4.3s |  |
| 133 | `bitmapdata_getpixels` | 39 | 16.4s |  |
| 134 | `bitmapdata_getvector` | 27 | 1.6s |  |
| 135 | `bitmapdata_histogram` | 59 | 1.6s |  |
| 136 | `bitmapdata_hittest` | 112 | 4.7s |  |
| 137 | `bitmapdata_hittest_threshold` | 18 | 4.3s |  |
| 138 | `bitmapdata_opaque` | 0 | 4.3s |  |
| 139 | `bitmapdata_pixeldissolve` | 1037 | 4.6s |  |
| 140 | `bitmapdata_pixeldissolve_image` | 0 | 4.6s |  |
| 141 | `bitmapdata_rectangle_rounding` | 16 | 4.3s |  |
| 142 | `bitmapdata_setpixels` | 286 | 4.3s |  |
| 143 | `bitmapdata_setvector` | 26 | 4.4s |  |
| 144 | `bitmapdata_sync` | 0 | 16.3s |  |
| 145 | `bitmapdata_threshold` | 176 | 4.9s |  |
| 146 | `bitmapdata_zero_size` | 8 | 16.0s |  |
| 147 | `bitnot` | 46 | 4.2s |  |
| 148 | `bitor` | 1058 | 10.9s |  |
| 149 | `bitxor` | 1058 | 10.7s |  |
| 150 | `blend_mode_null` | 1 | 4.3s |  |
| 151 | `blend_multiply_alpha` | 0 | 4.3s |  |
| 152 | `blend_scroll` | 0 | 4.3s |  |
| 153 | `blend_shader_luma_lighten` | 3 | 4.3s |  |
| 154 | `blur_filter` | 43 | 4.5s |  |
| 155 | `boolean_constr` | 32 | 4.2s |  |
| 156 | `boolean_negation` | 30 | 4.9s |  |
| 157 | `boolean_tostring` | 8 | 4.8s |  |
| 158 | `broadcast_event` | 7 | 19.9s |  |
| 159 | `button_bounds` | 1 | 4.8s |  |
| 160 | `button_hittest` | 2 | 19.6s |  |
| 161 | `button_nested_frame` | 48 | 19.8s |  |
| 162 | `bytearray` | 48 | 5.4s |  |
| 163 | `bytearray_compress` | 31 | 19.9s |  |
| 164 | `bytearray_errors` | 24 | 4.9s |  |
| 165 | `bytearray_method_serialization` | 1 | 4.9s |  |
| 166 | `bytearray_oom` | 3 | 5.3s |  |
| 167 | `bytearray_readobject_amf0` | 50 | 4.7s |  |
| 168 | `bytearray_readobject_amf3` | 53 | 4.9s |  |
| 169 | `bytearray_readutf8bytes_with_bom` | 16 | 4.8s |  |
| 170 | `bytearray_serialization` | 3 | 4.7s |  |
| 171 | `bytearray_string_null` | 19 | 5.0s |  |
| 172 | `bytearray_tostring` | 15 | 4.9s |  |
| 173 | `bytearray_utf16` | 8 | 5.1s |  |
| 174 | `bytearray_writeobject` | 24 | 4.7s |  |
| 175 | `callee_in_initializer` | 6 | 4.7s |  |
| 176 | `callproplex_class` | 1 | 4.8s |  |
| 177 | `capabilities_resolution` | 8 | 20.7s |  |
| 178 | `catch_class` | 6 | 4.8s |  |
| 179 | `catch_scope_slot` | 7 | 1.6s |  |
| 180 | `checkfilter` | 4 | 2.0s |  |
| 181 | `class_call` | 32 | 5.0s |  |
| 182 | `class_cast_call` | 14 | 4.8s |  |
| 183 | `class_enumeration` | 4 | 4.9s |  |
| 184 | `class_has_own_property` | 2 | 5.1s |  |
| 185 | `class_init_interpreter_mode` | 1 | 5.2s |  |
| 186 | `class_is` | 32 | 4.8s |  |
| 187 | `class_methods` | 5 | 5.2s |  |
| 188 | `class_object_properties` | 10 | 4.8s |  |
| 189 | `class_singleton` | 18 | 5.0s |  |
| 190 | `class_supercalls_errors` | 35 | 4.9s |  |
| 191 | `class_supercalls_mismatched` | 26 | 5.2s |  |
| 192 | `class_superclass_wrong_order` | 1 | 19.2s |  |
| 193 | `class_to_locale_string` | 2 | 5.0s |  |
| 194 | `class_to_string` | 2 | 4.7s |  |
| 195 | `class_value_of` | 2 | 4.8s |  |
| 196 | `click_block` | 5 | 26.3s |  |
| 197 | `click_invisible` | 3 | 7.0s |  |
| 198 | `closures` | 12 | 6.8s |  |
| 199 | `coerce_return_type` | 40 | 6.9s |  |
| 200 | `coerce_return_type_fail` | 2 | 25.7s |  |
| 201 | `coerce_return_void` | 3 | 6.7s |  |
| 202 | `coerce_string` | 86 | 6.9s |  |
| 203 | `coerce_to_primitive_side_effects` | 29 | 26.3s |  |
| 204 | `color_matrix_filter` | 19 | 6.9s |  |
| 205 | `construct_errors_swf10` | 8 | 6.9s |  |
| 206 | `construct_frame_list` | 22 | 26.4s |  |
| 207 | `construct_interface` | 3 | 6.8s |  |
| 208 | `constructor_call` | 3 | 6.8s |  |
| 209 | `constructors_vs_timeline` | 5 | 26.1s |  |
| 210 | `constructprop_dynamic_primitive` | 7 | 6.8s |  |
| 211 | `constructprop_method` | 2 | 6.8s |  |
| 212 | `constructsuper_null` | 2 | 6.9s |  |
| 213 | `content_element_basic` | 50 | 7.1s |  |
| 214 | `context3d_creation` | 9 | 7.0s |  |
| 215 | `control_flow_bool` | 4 | 6.9s |  |
| 216 | `control_flow_stricteq` | 8 | 6.8s |  |
| 217 | `convert_boolean` | 30 | 7.0s |  |
| 218 | `convert_integer` | 90 | 7.1s |  |
| 219 | `convert_number` | 56 | 6.9s |  |
| 220 | `convert_uinteger` | 90 | 7.1s |  |
| 221 | `convolution_filter` | 89 | 7.1s |  |
| 222 | `core_exceptions` | 47 | 7.7s |  |
| 223 | `cpool_index_invalid_bytecode_1` | 6 | 7.0s |  |
| 224 | `cpool_index_invalid_bytecode_2` | 3 | 6.8s |  |
| 225 | `cpool_index_invalid_bytecode_3` | 1 | 6.7s |  |
| 226 | `cross_api_version_call_newer` | 12 | 7.5s |  |
| 227 | `cross_api_version_call_older` | 12 | 7.2s |  |
| 228 | `cryptscore` | 11 | 7.0s |  |
| 229 | `currency_parse_result` | 7 | 6.8s |  |
| 230 | `date` | 30 | 7.3s |  |
| 231 | `date_parse` | 36 | 6.9s |  |
| 232 | `declocal` | 46 | 6.8s |  |
| 233 | `declocal_i` | 46 | 7.0s |  |
| 234 | `decode_uri` | 71 | 7.2s |  |
| 235 | `decrement` | 46 | 7.2s |  |
| 236 | `decrement_i` | 46 | 7.0s |  |
| 237 | `default_values` | 7 | 7.0s |  |
| 238 | `delayed_symbolclass` | 28 | 27.8s |  |
| 239 | `describe_type_basic` | 152 | 6.9s |  |
| 240 | `describe_type_json` | 301 | 6.9s |  |
| 241 | `describe_type_metadata` | 125 | 6.9s |  |
| 242 | `describe_type_native` | 23 | 6.9s |  |
| 243 | `dictionary_access` | 62 | 6.9s |  |
| 244 | `dictionary_access_no_pubns` | 2 | 26.1s |  |
| 245 | `dictionary_delete` | 101 | 7.3s |  |
| 246 | `dictionary_foreach` | 42 | 7.0s |  |
| 247 | `dictionary_hasownproperty` | 63 | 7.1s |  |
| 248 | `dictionary_in` | 62 | 7.1s |  |
| 249 | `dictionary_iter_modify` | 8 | 6.8s |  |
| 250 | `dictionary_namespaces` | 36 | 7.0s |  |
| 251 | `dictionary_primitive_keys` | 29 | 6.9s |  |
| 252 | `displacement_map_filter` | 61 | 7.1s |  |
| 253 | `displayobject_alpha` | 277 | 6.8s |  |
| 254 | `displayobject_blendmode` | 0 | 6.9s |  |
| 255 | `displayobject_colortransform_nested` | 0 | 27.0s |  |
| 256 | `displayobject_filters` | 17 | 6.9s |  |
| 257 | `displayobject_from_enterframe` | 1 | 26.9s |  |
| 258 | `displayobject_getbounds_shape` | 0 | 26.5s |  |
| 259 | `displayobject_height` | 6052 | 26.8s |  |
| 260 | `displayobject_hittestobject` | 32 | 6.9s |  |
| 261 | `displayobject_hittestpoint` | 49 | 26.9s |  |
| 262 | `displayobject_hittestpoint_root` | 13 | 7.1s |  |
| 263 | `displayobject_invalid_floats` | 60 | 6.8s |  |
| 264 | `displayobject_invalid_props` | 3 | 6.7s |  |
| 265 | `displayobject_mask` | 3 | 6.8s |  |
| 266 | `displayobject_mask_self_referential` | 0 | 6.8s |  |
| 267 | `displayobject_metaData` | 3 | 6.8s |  |
| 268 | `displayobject_name` | 22 | 27.0s |  |
| 269 | `displayobject_name_from_timeline` | 24 | 7.0s |  |
| 270 | `displayobject_opaque_background` | 6 | 7.0s |  |
| 271 | `displayobject_parent` | 12 | 6.9s |  |
| 272 | `displayobject_root` | 24 | 25.3s |  |
| 273 | `displayobject_rotation` | 1284 | 25.6s |  |
| 274 | `displayobject_set_matrix_nested` | 0 | 25.8s |  |
| 275 | `displayobject_set_name_loaded` | 3 | 6.9s |  |
| 276 | `displayobject_subclass` | 2 | 6.5s |  |
| 277 | `displayobject_visible` | 23 | 6.5s |  |
| 278 | `displayobject_width` | 4852 | 25.5s |  |
| 279 | `displayobject_x` | 614 | 24.9s |  |
| 280 | `displayobject_y` | 617 | 6.5s |  |
| 281 | `displayobjectcontainer_addchild` | 32 | 6.6s |  |
| 282 | `displayobjectcontainer_addchild_lazy_sprite` | 1 | 6.5s |  |
| 283 | `displayobjectcontainer_addchild_timelinepull0` | 58 | 6.7s |  |
| 284 | `displayobjectcontainer_addchild_timelinepull1` | 60 | 6.6s |  |
| 285 | `displayobjectcontainer_addchild_timelinepull2` | 62 | 6.6s |  |
| 286 | `displayobjectcontainer_addchildat` | 42 | 6.5s |  |
| 287 | `displayobjectcontainer_addchildat_timelinelock0` | 34 | 6.7s |  |
| 288 | `displayobjectcontainer_addchildat_timelinelock1` | 34 | 6.6s |  |
| 289 | `displayobjectcontainer_addchildat_timelinelock2` | 34 | 6.6s |  |
| 290 | `displayobjectcontainer_contains` | 66 | 25.4s |  |
| 291 | `displayobjectcontainer_getchildat` | 4 | 6.6s |  |
| 292 | `displayobjectcontainer_getchildbyname` | 9 | 6.5s |  |
| 293 | `displayobjectcontainer_getchildbyname_wrongcase` | 5 | 6.5s |  |
| 294 | `displayobjectcontainer_getchildindex` | 28 | 6.5s |  |
| 295 | `displayobjectcontainer_getobjectsunderpoint` | 15 | 25.3s |  |
| 296 | `displayobjectcontainer_removechild` | 10 | 6.5s |  |
| 297 | `displayobjectcontainer_removechild_errors` | 4 | 6.5s |  |
| 298 | `displayobjectcontainer_removechild_timelinemanip_remove1` | 38 | 6.5s |  |
| 299 | `displayobjectcontainer_removechildat` | 18 | 6.4s |  |
| 300 | `displayobjectcontainer_removechildren` | 51 | 6.7s |  |
| 301 | `displayobjectcontainer_setchildindex` | 42 | 6.4s |  |
| 302 | `displayobjectcontainer_stopallmovieclips` | 2 | 25.6s |  |
| 303 | `displayobjectcontainer_swapchildren` | 42 | 6.6s |  |
| 304 | `displayobjectcontainer_swapchildrenat` | 42 | 6.5s |  |
| 305 | `displayobjectcontainer_timelineinstance` | 48 | 25.3s |  |
| 306 | `doabc_and_symbolclass_script_init_goto` | 7 | 25.2s |  |
| 307 | `doabc_and_symbolclass_script_init_normal` | 6 | 6.5s |  |
| 308 | `doabc_is_eager` | 1 | 25.1s |  |
| 309 | `documentclass` | 9 | 6.6s |  |
| 310 | `domain_memory` | 133 | 7.8s |  |
| 311 | `drag_drop` | 10 | 25.6s |  |
| 312 | `drop_shadow_filter` | 172 | 6.8s |  |
| 313 | `duplicate_defs` | 1 | 6.7s |  |
| 314 | `eager_init` | 1 | 6.6s |  |
| 315 | `east_asian_justifier_clone` | 8 | 21.3s |  |
| 316 | `edit_text_linkage` | 7 | 6.8s |  |
| 317 | `edittext_align` | 60 | 7.0s |  |
| 318 | `edittext_always_show_selection` | 0 | 25.9s |  |
| 319 | `edittext_antialiastype` | 296 | 6.9s |  |
| 320 | `edittext_at_point_methods_basic` | 16 | 8.0s |  |
| 321 | `edittext_autosize` | 39 | 7.0s |  |
| 322 | `edittext_autosize_align` | 0 | 25.9s |  |
| 323 | `edittext_autosize_height_dynamic` | 60 | 26.0s |  |
| 324 | `edittext_autosize_height_input` | 60 | 6.8s |  |
| 325 | `edittext_autosize_lazy_bounds_events` | 65 | 7.1s |  |
| 326 | `edittext_autosize_lazy_bounds_interactions` | 19 | 6.7s |  |
| 327 | `edittext_autosize_lazy_bounds_props` | 490 | 8.0s |  |
| 328 | `edittext_autosize_lazy_bounds_visual` | 0 | 26.0s |  |
| 329 | `edittext_autosize_lazy_bounds_vs_relayout` | 106 | 6.8s |  |
| 330 | `edittext_bottom_scroll_v_basic` | 210 | 6.7s |  |
| 331 | `edittext_bounds_scale` | 24 | 25.3s |  |
| 332 | `edittext_bullet` | 30 | 6.7s |  |
| 333 | `edittext_default_format` | 221 | 7.0s |  |
| 334 | `edittext_default_format_empty` | 136 | 6.9s |  |
| 335 | `edittext_empty_text_format` | 7 | 6.6s |  |
| 336 | `edittext_focus_selection` | 5 | 6.6s |  |
| 337 | `edittext_font_size` | 45 | 6.7s |  |
| 338 | `edittext_format_empty_font` | 8 | 6.5s |  |
| 339 | `edittext_get_char_index_at_point` | 4 | 27.1s |  |
| 340 | `edittext_get_line_index_at_point` | 2 | 25.8s |  |
| 341 | `edittext_get_line_index_of_char` | 76 | 7.5s |  |
| 342 | `edittext_getcharboundaries` | 172 | 7.0s |  |
| 343 | `edittext_getcharboundaries_missing_glyphs` | 63 | 6.7s |  |
| 344 | `edittext_getcharboundaries_scroll` | 85 | 6.7s |  |
| 345 | `edittext_getlinemetrics` | 146 | 6.9s |  |
| 346 | `edittext_html` | 3101 | 7.1s |  |
| 347 | `edittext_html_condensewhite` | 487 | 6.7s |  |
| 348 | `edittext_html_entity` | 4 | 6.6s |  |
| 349 | `edittext_html_font_size_swf12` | 267 | 6.7s |  |
| 350 | `edittext_html_font_size_swf13` | 273 | 44.4s |  |
| 351 | `edittext_html_roundtrip` | 17 | 26.2s |  |
| 352 | `edittext_ime_focus_lost` | 9 | 26.3s |  |
| 353 | `edittext_input_control` | 12 | 7.0s |  |
| 354 | `edittext_leading` | 9 | 7.1s |  |
| 355 | `edittext_letter_spacing` | 15 | 7.1s |  |
| 356 | `edittext_line_methods` | 294 | 8.3s |  |
| 357 | `edittext_line_metrics` | 11 | 28.0s |  |
| 358 | `edittext_margins` | 25 | 6.8s |  |
| 359 | `edittext_max_scroll_h_basic` | 475 | 7.1s |  |
| 360 | `edittext_max_scroll_v_basic` | 1000 | 6.9s |  |
| 361 | `edittext_mouse_selection` | 363 | 27.8s |  |
| 362 | `edittext_mousedown` | 3 | 7.2s |  |
| 363 | `edittext_mouseenabled` | 26 | 26.3s |  |
| 364 | `edittext_newline_character` | 22 | 6.8s |  |
| 365 | `edittext_newline_stripping` | 64 | 9.7s |  |
| 366 | `edittext_newlines` | 30 | 6.8s |  |
| 367 | `edittext_paragraph_methods` | 257 | 6.8s |  |
| 368 | `edittext_paste_events` | 8 | 7.0s |  |
| 369 | `edittext_paste_maxchars` | 4 | 6.8s |  |
| 370 | `edittext_paste_restrict` | 16 | 6.6s |  |
| 371 | `edittext_restrict` | 191 | 6.8s |  |
| 372 | `edittext_restrict_events` | 22 | 6.8s |  |
| 373 | `edittext_scrollh` | 10 | 6.7s |  |
| 374 | `edittext_selected_text` | 9 | 6.8s |  |
| 375 | `edittext_set_html_same` | 17 | 6.7s |  |
| 376 | `edittext_set_text_vs_html` | 9 | 6.7s |  |
| 377 | `edittext_stylesheet` | 536 | 7.2s |  |
| 378 | `edittext_stylesheet_custom_tag` | 76 | 6.8s |  |
| 379 | `edittext_stylesheet_display` | 272 | 6.9s |  |
| 380 | `edittext_tag_indent` | 49 | 26.7s |  |
| 381 | `edittext_underline` | 40 | 6.8s |  |
| 382 | `edittext_width_height` | 103 | 7.1s |  |
| 383 | `edittext_wordwrap_word` | 150 | 6.9s |  |
| 384 | `edittext_wrap_breaks` | 2375 | 7.4s |  |
| 385 | `element_format_clone` | 44 | 7.0s |  |
| 386 | `element_format_constructor_order` | 64 | 2.7s |  |
| 387 | `element_format_properties` | 235 | 7.8s |  |
| 388 | `empty_bounds` | 1 | 6.7s |  |
| 389 | `encode_uri_surrogate_pair_invalid` | 8 | 6.8s |  |
| 390 | `encode_uri_surrogate_pair_swf11` | 15 | 43.0s |  |
| 391 | `equals` | 512 | 29.6s |  |
| 392 | `error_geterrormessage` | 779 | 6.6s |  |
| 393 | `error_prototype` | 15 | 6.6s |  |
| 394 | `error_stack_trace` | 45 | 6.6s |  |
| 395 | `error_stack_trace_debug_swf17` | 0 | 25.4s |  |
| 396 | `error_stack_trace_debug_swf18` | 0 | 6.3s |  |
| 397 | `error_stack_trace_edge_cases` | 6 | 6.6s |  |
| 398 | `error_stack_trace_release_swf17` | 0 | 6.5s |  |
| 399 | `error_stack_trace_release_swf18` | 0 | 6.2s |  |
| 400 | `error_throwerror` | 103 | 6.6s |  |
| 401 | `error_tostring` | 29 | 6.5s |  |
| 402 | `error_tostring_more` | 86 | 6.7s |  |
| 403 | `es3_inheritance` | 31 | 6.6s |  |
| 404 | `es4_inheritance` | 30 | 6.6s |  |
| 405 | `es4_interfaces` | 30 | 6.6s |  |
| 406 | `es4_method_binding` | 8 | 6.5s |  |
| 407 | `es4_oop_prototypes` | 14 | 6.7s |  |
| 408 | `es4_protected_inheritance` | 6 | 6.5s |  |
| 409 | `escape` | 71 | 6.6s |  |
| 410 | `escape_multi_byte` | 45 | 6.7s |  |
| 411 | `event_bubbles` | 2 | 6.5s |  |
| 412 | `event_cancelable` | 2 | 6.5s |  |
| 413 | `event_clone` | 20 | 6.6s |  |
| 414 | `event_clone_error_redispatch` | 3 | 6.7s |  |
| 415 | `event_clone_on_redispatch` | 10 | 6.7s |  |
| 416 | `event_formattostring` | 31 | 6.7s |  |
| 417 | `event_isdefaultprevented` | 12 | 6.6s |  |
| 418 | `event_target_getter` | 5 | 2.4s |  |
| 419 | `event_target_set` | 9 | 25.3s |  |
| 420 | `event_type` | 1 | 6.7s |  |
| 421 | `event_valueof_tostring` | 18 | 6.7s |  |
| 422 | `eventdispatcher_dispatchevent` | 12 | 6.7s |  |
| 423 | `eventdispatcher_dispatchevent_cancel` | 20 | 6.8s |  |
| 424 | `eventdispatcher_dispatchevent_handlerorder` | 22 | 6.8s |  |
| 425 | `eventdispatcher_dispatchevent_indirect` | 9 | 6.7s |  |
| 426 | `eventdispatcher_dispatchevent_this` | 5 | 6.6s |  |
| 427 | `eventdispatcher_haseventlistener` | 25 | 6.7s |  |
| 428 | `eventdispatcher_interface_invoke` | 1 | 6.6s |  |
| 429 | `eventdispatcher_tostring` | 10 | 6.7s |  |
| 430 | `eventdispatcher_willtrigger` | 25 | 42.8s |  |
| 431 | `falsiness` | 30 | 6.5s |  |
| 432 | `fast_index_access` | 12 | 6.7s |  |
| 433 | `filefilter_properties` | 4 | 6.6s |  |
| 434 | `filereference_browse_cancel` | 3 | 6.5s |  |
| 435 | `filereference_browse_select` | 9 | 6.6s |  |
| 436 | `filereference_load` | 31 | 6.6s |  |
| 437 | `filereference_save` | 16 | 6.6s |  |
| 438 | `filereference_save_and_browse` | 42 | 6.7s |  |
| 439 | `filereference_save_and_load` | 22 | 7.0s |  |
| 440 | `filereference_uninitialized` | 8 | 6.8s |  |
| 441 | `filereferencelist_browse_cancel` | 6 | 6.9s |  |
| 442 | `filereferencelist_browse_select` | 7 | 6.8s |  |
| 443 | `filter_rewind` | 8 | 26.0s |  |
| 444 | `filters_array_holes` | 25 | 7.0s |  |
| 445 | `finddef` | 3 | 6.8s |  |
| 446 | `findprop_global_prototype` | 6 | 7.0s |  |
| 447 | `flash_media_video_constructor` | 156 | 7.4s |  |
| 448 | `flash_media_video_rotation_probe` | 27 | 6.8s |  |
| 449 | `flash_media_video_setter` | 40 | 7.1s |  |
| 450 | `flash_trace` | 17 | 6.8s |  |
| 451 | `flash_xml` | 29 | 6.7s |  |
| 452 | `flash_xml_cloneNode` | 22 | 6.6s |  |
| 453 | `flash_xml_namespace` | 109 | 6.5s |  |
| 454 | `flash_xml_removeNode` | 60 | 6.6s |  |
| 455 | `focus_events_code` | 161 | 25.6s |  |
| 456 | `focus_events_key_basic` | 132 | 25.8s |  |
| 457 | `focus_events_key_navigation` | 53 | 25.4s |  |
| 458 | `focus_events_key_same_object` | 26 | 6.7s |  |
| 459 | `focus_events_mixed_key_mouse` | 100 | 25.6s |  |
| 460 | `focus_events_mouse_basic` | 260 | 25.6s |  |
| 461 | `focus_events_mouse_focusable` | 112 | 25.7s |  |
| 462 | `focus_events_mouse_same_object` | 40 | 6.6s |  |
| 463 | `focus_remove` | 20 | 25.3s |  |
| 464 | `focus_root_movie` | 4 | 25.4s |  |
| 465 | `focus_stage` | 1 | 6.6s |  |
| 466 | `focusrect` | 18 | 7.4s |  |
| 467 | `focusrect_focuslost` | 9 | 6.7s |  |
| 468 | `focusrect_property` | 110 | 2.1s |  |
| 469 | `font_description_clone` | 14 | 6.6s |  |
| 470 | `font_embedded` | 24 | 44.1s |  |
| 471 | `font_enumeratefonts` | 41 | 7.5s |  |
| 472 | `font_enumeratefonts_filter` | 4 | 26.4s |  |
| 473 | `font_enumeratefonts_order` | 9 | 27.4s |  |
| 474 | `font_hasglyphs` | 40 | 7.2s |  |
| 475 | `font_registerfont` | 129 | 7.9s |  |
| 476 | `framelabel_constr` | 5 | 7.0s |  |
| 477 | `function_call` | 12 | 6.8s |  |
| 478 | `function_call_arguments` | 46 | 6.9s |  |
| 479 | `function_call_arguments_enumerate` | 5 | 6.8s |  |
| 480 | `function_call_coercion` | 108 | 7.2s |  |
| 481 | `function_call_default` | 6 | 6.7s |  |
| 482 | `function_call_rest` | 22 | 6.8s |  |
| 483 | `function_call_types` | 3 | 6.8s |  |
| 484 | `function_call_via_apply` | 11 | 6.8s |  |
| 485 | `function_call_via_call` | 3 | 6.7s |  |
| 486 | `function_display_anonymous` | 7 | 2.5s |  |
| 487 | `function_length` | 6 | 6.8s |  |
| 488 | `function_object` | 2 | 6.7s |  |
| 489 | `function_proto` | 5 | 6.7s |  |
| 490 | `function_proto_created` | 61 | 6.8s |  |
| 491 | `function_to_locale_string` | 4 | 6.7s |  |
| 492 | `function_to_string` | 4 | 6.7s |  |
| 493 | `function_type` | 6 | 6.7s |  |
| 494 | `function_unbound_this` | 51 | 6.8s |  |
| 495 | `function_value_of` | 4 | 6.8s |  |
| 496 | `game_input` | 4 | 6.8s |  |
| 497 | `generate_random_bytes` | 3 | 6.8s |  |
| 498 | `geom_transform` | 74 | 26.3s |  |
| 499 | `get_definition_by_name` | 11 | 6.8s |  |
| 500 | `get_qualified_class_name` | 20 | 6.8s |  |
| 501 | `get_qualified_super_class_name` | 18 | 6.8s |  |
| 502 | `get_slot_edge_cases` | 1 | 6.7s |  |
| 503 | `get_timer` | 2 | 2.4s |  |
| 504 | `getglobalslot` | 1 | 6.7s |  |
| 505 | `getouterscope` | 8 | 6.7s |  |
| 506 | `getouterscope_two_classobjects` | 13 | 6.7s |  |
| 507 | `getter_different_namespace_setter` | 2 | 6.5s |  |
| 508 | `glow_filter` | 127 | 6.9s |  |
| 509 | `goto_button_nested_framescript` | 28 | 26.4s |  |
| 510 | `goto_in_constructframe` | 12 | 45.3s |  |
| 511 | `goto_in_scene_last_frame` | 2 | 26.6s |  |
| 512 | `goto_methods` | 56 | 26.4s |  |
| 513 | `goto_methods_swfver10` | 8 | 6.7s |  |
| 514 | `goto_nested_construct_sibling` | 18 | 26.8s |  |
| 515 | `goto_nested_framescript` | 9 | 7.0s |  |
| 516 | `goto_on_orphan` | 15 | 26.9s |  |
| 517 | `gradient_bevel_filter` | 206 | 7.0s |  |
| 518 | `gradient_glow_filter` | 206 | 6.7s |  |
| 519 | `graphic_linkage` | 9 | 7.0s |  |
| 520 | `graphics_bad_direct_commands` | 5 | 7.4s |  |
| 521 | `graphics_bitmap_fill` | 0 | 28.4s |  |
| 522 | `graphics_bitmaps` | 0 | 7.1s |  |
| 523 | `graphics_direct_commands` | 0 | 7.0s |  |
| 524 | `graphics_draw_triangles` | 98 | 27.7s |  |
| 525 | `graphics_gradients` | 0 | 7.0s |  |
| 526 | `graphics_gradients_nulls` | 0 | 6.9s |  |
| 527 | `graphics_path` | 56 | 6.9s |  |
| 528 | `graphics_round_rects` | 0 | 6.9s |  |
| 529 | `graphics_simple_shapes` | 0 | 6.8s |  |
| 530 | `greaterequals` | 512 | 11.2s |  |
| 531 | `greaterthan` | 512 | 11.1s |  |
| 532 | `has_own_property` | 102 | 7.4s |  |
| 533 | `hasownproperty_namespaces` | 2 | 6.8s |  |
| 534 | `hello_world` | 1 | 6.8s |  |
| 535 | `hittest_morph` | 30 | 7.0s |  |
| 536 | `if_eq` | 10 | 6.9s |  |
| 537 | `if_gt` | 1 | 6.9s |  |
| 538 | `if_gte` | 10 | 2.5s |  |
| 539 | `if_lt` | 1 | 0.6s |  |
| 540 | `if_lte` | 10 | 6.7s |  |
| 541 | `if_ne` | 7 | 2.4s |  |
| 542 | `if_stricteq` | 6 | 6.7s |  |
| 543 | `if_strictne` | 11 | 6.8s |  |
| 544 | `ime_linux_dead_keys` | 10 | 6.8s |  |
| 545 | `in` | 102 | 7.2s |  |
| 546 | `inclocal` | 46 | 6.8s |  |
| 547 | `inclocal_i` | 46 | 6.8s |  |
| 548 | `increment` | 46 | 6.8s |  |
| 549 | `increment_i` | 46 | 42.5s |  |
| 550 | `indexing_delete` | 75 | 6.6s |  |
| 551 | `instanceof` | 58 | 6.8s |  |
| 552 | `instantiate_root_character` | 4 | 7.0s |  |
| 553 | `instantiation_on_enter_frame` | 7 | 25.2s |  |
| 554 | `instantiation_on_enterframe_gotoandstop` | 8 | 6.5s |  |
| 555 | `int_constr` | 92 | 6.8s |  |
| 556 | `int_edge_cases` | 19 | 25.5s |  |
| 557 | `int_instanceof` | 3 | 24.9s |  |
| 558 | `int_tofixed` | 1215 | 6.5s |  |
| 559 | `int_toprecision` | 1125 | 6.7s |  |
| 560 | `int_tostring` | 3375 | 6.8s |  |
| 561 | `interactiveobject_enabled` | 25 | 6.4s |  |
| 562 | `interface_namespaces` | 78 | 6.7s |  |
| 563 | `invalid_utf8` | 12 | 6.6s |  |
| 564 | `is_finite` | 46 | 6.7s |  |
| 565 | `is_nan` | 46 | 6.5s |  |
| 566 | `is_prototype_of` | 12 | 6.5s |  |
| 567 | `issue_10221` | 2 | 6.5s |  |
| 568 | `issue_13780` | 12 | 6.5s |  |
| 569 | `issue_14901` | 1 | 6.5s |  |
| 570 | `issue_17675_edittext_paste_maxchars` | 1 | 6.5s |  |
| 571 | `issue_5292` | 5 | 6.5s |  |
| 572 | `issue_8630` | 2 | 25.3s |  |
| 573 | `issue_8630_placeremoveplace` | 15 | 6.6s |  |
| 574 | `issue_8630_placeremoveplace_scriptremove` | 16 | 6.5s |  |
| 575 | `issue_8630_scriptremove` | 11 | 6.5s |  |
| 576 | `istype` | 24 | 2.4s |  |
| 577 | `istypelate` | 58 | 6.8s |  |
| 578 | `istypelate_coerce` | 198 | 7.5s |  |
| 579 | `jpeg_loader_context` | 6 | 6.6s |  |
| 580 | `json_errors` | 9 | 25.3s |  |
| 581 | `json_parse` | 21 | 6.5s |  |
| 582 | `json_stringify` | 12 | 6.7s |  |
| 583 | `json_stringify_function` | 12 | 6.5s |  |
| 584 | `json_stringify_order` | 1 | 6.5s |  |
| 585 | `json_version_gated` | 1 | 6.5s |  |
| 586 | `key_input_80percent` | 1812 | 6.7s |  |
| 587 | `key_input_location` | 126 | 6.8s |  |
| 588 | `key_input_numpad` | 384 | 6.6s |  |
| 589 | `lazyinit` | 17 | 6.8s |  |
| 590 | `lessequals` | 512 | 10.4s |  |
| 591 | `lessthan` | 512 | 10.5s |  |
| 592 | `loader_bitmap_transparency` | 14 | 6.7s |  |
| 593 | `loader_bytes_unknown_content` | 14 | 6.7s |  |
| 594 | `loader_child_getdefinition` | 5 | 6.8s |  |
| 595 | `loader_duplicate_coerce` | 3 | 6.8s |  |
| 596 | `loader_duplicate_coerce_new_domain` | 4 | 6.7s |  |
| 597 | `loader_error_in_root_ctor` | 4 | 6.9s |  |
| 598 | `loader_events` | 92 | 7.3s |  |
| 599 | `loader_image` | 8 | 6.8s |  |
| 600 | `loader_jpegxr` | 2 | 26.2s |  |
| 601 | `loader_jpegxr_alpha` | 1 | 25.9s |  |
| 602 | `loader_loadbytes_events` | 30 | 7.2s |  |
| 603 | `loader_loadbytes_invalid_png` | 4 | 25.5s |  |
| 604 | `loader_loadbytes_url` | 12 | 6.9s |  |
| 605 | `loader_loaderurl` | 6 | 7.2s |  |
| 606 | `loader_method` | 85 | 6.7s |  |
| 607 | `loader_noninteractive_try_click_root` | 5 | 26.2s |  |
| 608 | `loader_reuse` | 38 | 25.8s |  |
| 609 | `loader_unknown_content` | 24 | 6.7s |  |
| 610 | `loader_visibility_interactive` | 1 | 6.6s |  |
| 611 | `loaderinfo_events` | 7 | 6.5s |  |
| 612 | `loaderinfo_loadurl` | 12 | 25.5s |  |
| 613 | `loaderinfo_more` | 6 | 6.7s |  |
| 614 | `loaderinfo_properties` | 18 | 25.3s |  |
| 615 | `loaderinfo_properties_not_loaded` | 23 | 6.7s |  |
| 616 | `loaderinfo_quine` | 1005 | 6.5s |  |
| 617 | `loaderinfo_root` | 10 | 6.6s |  |
| 618 | `loaderinfo_root_allows` | 2 | 6.6s |  |
| 619 | `localconnection` | 890 | 8.4s |  |
| 620 | `localconnection_send` | 4 | 6.6s |  |
| 621 | `lshift` | 1058 | 18.7s |  |
| 622 | `mask_reapply` | 1 | 25.5s |  |
| 623 | `math` | 497 | 6.8s |  |
| 624 | `matrix` | 338 | 17.8s |  |
| 625 | `matrix3d` | 57 | 38.1s |  |
| 626 | `matrix3d_append` | 16 | 22.1s |  |
| 627 | `matrix3d_compose` | 34 | 5.7s |  |
| 628 | `matrix3d_copy_column` | 83 | 5.7s |  |
| 629 | `matrix3d_copy_raw_data_from` | 55 | 2.0s |  |
| 630 | `matrix3d_copy_raw_data_to` | 38 | 5.8s |  |
| 631 | `matrix3d_copy_row` | 83 | 5.3s |  |
| 632 | `matrix3d_invert` | 18 | 5.4s |  |
| 633 | `matrix3d_position` | 19 | 5.7s |  |
| 634 | `matrix3d_prepend` | 16 | 5.3s |  |
| 635 | `matrix3d_transform_vector` | 52 | 5.6s |  |
| 636 | `matrix3d_transpose` | 5 | 5.3s |  |
| 637 | `method_without_body` | 3 | 21.5s |  |
| 638 | `missing_external_interface` | 10 | 5.5s |  |
| 639 | `modulo` | 1058 | 13.4s |  |
| 640 | `morph_shape` | 2 | 21.5s |  |
| 641 | `mouse_children` | 192 | 22.0s |  |
| 642 | `mouse_click_events` | 90 | 22.2s |  |
| 643 | `mouse_double_click_events` | 188 | 5.6s |  |
| 644 | `mouse_empty_parent` | 4 | 5.5s |  |
| 645 | `mouse_over_while_dragging` | 3 | 6.4s |  |
| 646 | `mouse_pick_button_mode` | 2 | 5.5s |  |
| 647 | `mouse_pick_dobj_mask` | 4 | 5.5s |  |
| 648 | `mouse_pick_masking` | 7 | 22.1s |  |
| 649 | `mouse_pick_non_interactive_bitmap_mask` | 4 | 22.2s |  |
| 650 | `mouse_pick_non_interactive_dobj_mask` | 3 | 5.5s |  |
| 651 | `mouse_pick_text` | 8 | 5.7s |  |
| 652 | `mouse_sibling` | 8 | 5.5s |  |
| 653 | `mouse_wheel_events` | 36 | 44.0s |  |
| 654 | `mouseevent_constr` | 66 | 25.9s |  |
| 655 | `mouseevent_stagexy` | 35 | 6.7s |  |
| 656 | `mouseevent_valueof_tostring` | 28 | 6.6s |  |
| 657 | `movieclip_addframescript` | 3 | 25.9s |  |
| 658 | `movieclip_child_property` | 16 | 6.8s |  |
| 659 | `movieclip_constr` | 21 | 25.3s |  |
| 660 | `movieclip_currentlabels` | 17 | 25.8s |  |
| 661 | `movieclip_currentlabels_dupes1` | 46 | 25.6s |  |
| 662 | `movieclip_currentlabels_dupes2` | 30 | 6.6s |  |
| 663 | `movieclip_currentlabels_dupes3` | 67 | 6.6s |  |
| 664 | `movieclip_currentscene` | 12 | 25.8s |  |
| 665 | `movieclip_dispatchevent` | 430 | 6.8s |  |
| 666 | `movieclip_dispatchevent_cancel` | 102 | 6.9s |  |
| 667 | `movieclip_dispatchevent_handlerorder` | 251 | 6.7s |  |
| 668 | `movieclip_dispatchevent_selfadd` | 80 | 6.6s |  |
| 669 | `movieclip_dispatchevent_target` | 899 | 6.7s |  |
| 670 | `movieclip_displayevents` | 96 | 25.7s |  |
| 671 | `movieclip_displayevents_clickgoto` | 676 | 26.1s |  |
| 672 | `movieclip_displayevents_clickgoto2` | 2001 | 7.2s |  |
| 673 | `movieclip_displayevents_clickplay` | 575 | 6.8s |  |
| 674 | `movieclip_displayevents_clicksymbol` | 562 | 6.8s |  |
| 675 | `movieclip_displayevents_constructframegoto` | 140 | 7.1s |  |
| 676 | `movieclip_displayevents_constructframeplay` | 50 | 6.9s |  |
| 677 | `movieclip_displayevents_constructframesymbol` | 144 | 6.8s |  |
| 678 | `movieclip_displayevents_dblhandler` | 21 | 6.8s |  |
| 679 | `movieclip_displayevents_enterframegoto` | 149 | 7.0s |  |
| 680 | `movieclip_displayevents_enterframeplay` | 48 | 6.7s |  |
| 681 | `movieclip_displayevents_enterframesymbol` | 149 | 25.9s |  |
| 682 | `movieclip_displayevents_exitframegoto` | 106 | 6.7s |  |
| 683 | `movieclip_displayevents_exitframeplay` | 44 | 6.7s |  |
| 684 | `movieclip_displayevents_exitframesymbol` | 135 | 6.8s |  |
| 685 | `movieclip_displayevents_looping` | 63 | 25.7s |  |
| 686 | `movieclip_displayevents_stopped` | 113 | 7.1s |  |
| 687 | `movieclip_displayevents_swap` | 96 | 2.2s |  |
| 688 | `movieclip_displayevents_timeline` | 128 | 25.9s |  |
| 689 | `movieclip_drawrect` | 54 | 6.6s |  |
| 690 | `movieclip_frameconstruct_skipped` | 9 | 6.8s |  |
| 691 | `movieclip_goto_during_frame_script` | 15 | 25.4s |  |
| 692 | `movieclip_goto_overwrite` | 14 | 25.6s |  |
| 693 | `movieclip_goto_scene_last_frame_int` | 1 | 25.6s |  |
| 694 | `movieclip_goto_scene_last_frame_label` | 1 | 6.5s |  |
| 695 | `movieclip_gotoandplay` | 15 | 42.3s |  |
| 696 | `movieclip_gotoandstop` | 13 | 25.0s |  |
| 697 | `movieclip_gotoandstop_children` | 4 | 25.4s |  |
| 698 | `movieclip_gotoandstop_framescripts1` | 4 | 6.5s |  |
| 699 | `movieclip_gotoandstop_framescripts2` | 4 | 2.3s |  |
| 700 | `movieclip_gotoandstop_framescripts_self` | 7 | 25.1s |  |
| 701 | `movieclip_gotoandstop_queueing` | 12 | 25.2s |  |
| 702 | `movieclip_hittest` | 67 | 25.1s |  |
| 703 | `movieclip_next_frame` | 2 | 24.9s |  |
| 704 | `movieclip_next_scene` | 6 | 24.9s |  |
| 705 | `movieclip_play` | 3 | 6.4s |  |
| 706 | `movieclip_prev_frame` | 3 | 6.2s |  |
| 707 | `movieclip_prev_scene` | 7 | 6.5s |  |
| 708 | `movieclip_properties` | 79 | 25.2s |  |
| 709 | `movieclip_queued_noop_goto_swf10` | 9 | 6.5s |  |
| 710 | `movieclip_queued_noop_goto_swf9` | 7 | 0.6s |  |
| 711 | `movieclip_scenes` | 11 | 6.5s |  |
| 712 | `movieclip_soundtransform` | 831 | 27.2s |  |
| 713 | `movieclip_stop` | 1 | 24.8s |  |
| 714 | `movieclip_super_is_symbol` | 20 | 6.8s |  |
| 715 | `movieclip_symbol_constr` | 8 | 6.6s |  |
| 716 | `movieclip_text_mousedown` | 1 | 6.6s |  |
| 717 | `movieclip_willtrigger` | 5 | 6.8s |  |
| 718 | `multiply` | 1058 | 18.4s |  |
| 719 | `namespace_constr` | 253 | 6.9s |  |
| 720 | `namespace_constr_args` | 1 | 6.5s |  |
| 721 | `namespace_enumeration_order` | 7 | 25.1s |  |
| 722 | `nan_scale` | 9 | 6.5s |  |
| 723 | `navigateToURL_target_normalize` | 107 | 27.2s |  |
| 724 | `negate` | 30 | 6.5s |  |
| 725 | `negative_volume_panned` | 0 | 6.8s |  |
| 726 | `nested_iteration` | 11 | 6.5s |  |
| 727 | `net_getClassByAlias` | 3 | 6.5s |  |
| 728 | `net_navigateToURL` | 57 | 6.5s |  |
| 729 | `net_stream_play_options` | 6 | 6.5s |  |
| 730 | `netconnection_close` | 55 | 6.5s |  |
| 731 | `netconnection_properties` | 78 | 6.6s |  |
| 732 | `netconnection_send_remote` | 50 | 25.4s |  |
| 733 | `netconnection_serialize_arrays` | 6 | 6.6s |  |
| 734 | `netfilterevent` | 10 | 6.5s |  |
| 735 | `netstream_client` | 10 | 6.7s |  |
| 736 | `netstream_connect` | 7 | 44.2s |  |
| 737 | `netstream_flv_date` | 4 | 7.1s |  |
| 738 | `newactivation_in_script_init` | 3 | 25.9s |  |
| 739 | `newclass_mismatched` | 4 | 6.8s |  |
| 740 | `newclass_twice` | 3 | 6.8s |  |
| 741 | `nonconflicting_declarations` | 0 | 6.9s |  |
| 742 | `null_void_types` | 8 | 6.8s |  |
| 743 | `number_autoconv` | 21 | 6.8s |  |
| 744 | `number_autoconv_amf` | 132 | 6.8s |  |
| 745 | `number_autoconv_array_sort_32bit` | 1 | 6.8s |  |
| 746 | `number_constr` | 58 | 7.0s |  |
| 747 | `number_convert_edge_cases` | 180 | 26.1s |  |
| 748 | `number_toexponential` | 378 | 6.9s |  |
| 749 | `number_toexponential2` | 35 | 6.8s |  |
| 750 | `number_tofixed` | 378 | 6.7s |  |
| 751 | `number_toprecision` | 350 | 6.8s |  |
| 752 | `obfuscated_class_names` | 3 | 6.8s |  |
| 753 | `object_enumeration` | 10 | 6.8s |  |
| 754 | `object_prototype` | 4 | 6.8s |  |
| 755 | `object_to_locale_string` | 2 | 6.8s |  |
| 756 | `object_to_string` | 2 | 6.7s |  |
| 757 | `object_value_of` | 2 | 2.2s |  |
| 758 | `op_coerce` | 54 | 6.8s |  |
| 759 | `op_coerce_x` | 54 | 6.8s |  |
| 760 | `op_escxattr` | 2 | 6.8s |  |
| 761 | `op_escxelem` | 2 | 6.7s |  |
| 762 | `op_lookupswitch` | 4 | 6.7s |  |
| 763 | `optimize_coerce` | 1 | 6.7s |  |
| 764 | `orphan_movie_complex` | 80 | 7.2s |  |
| 765 | `orphan_movie_reorder` | 111 | 26.6s |  |
| 766 | `package_namespace` | 7 | 6.5s |  |
| 767 | `param_default_value_has_zero_cpool_index` | 1 | 6.7s |  |
| 768 | `parent_early_access_child` | 16 | 26.0s |  |
| 769 | `parse_float` | 81 | 7.0s |  |
| 770 | `parse_float_swf10` | 81 | 6.7s |  |
| 771 | `parse_int` | 135 | 43.8s |  |
| 772 | `perspective_projection` | 1443 | 26.2s |  |
| 773 | `perspective_projection_basic` | 40 | 6.4s |  |
| 774 | `pixelbender_ceil` | 77 | 6.6s |  |
| 775 | `pixelbender_conditional` | 138 | 6.8s |  |
| 776 | `pixelbender_conversions` | 270 | 6.8s |  |
| 777 | `pixelbender_dithering` | 8 | 31.3s |  |
| 778 | `pixelbender_div` | 36 | 6.6s |  |
| 779 | `pixelbender_effect_BlurredFocus` | 0 | 34.3s |  |
| 780 | `pixelbender_effect_glassDisplace` | 0 | 12.6s |  |
| 781 | `pixelbender_effect_glassDisplace_shaderfilter` | 4 | 29.5s |  |
| 782 | `pixelbender_effect_smudge` | 0 | 29.3s |  |
| 783 | `pixelbender_effect_tintype` | 0 | 8.9s |  |
| 784 | `pixelbender_effect_twirl` | 0 | 10.5s |  |
| 785 | `pixelbender_eof` | 7 | 6.4s |  |
| 786 | `pixelbender_images` | 0 | 8.6s |  |
| 787 | `pixelbender_input` | 103 | 26.6s |  |
| 788 | `pixelbender_logicalnot` | 20 | 6.4s |  |
| 789 | `pixelbender_malformed_data` | 190 | 26.6s |  |
| 790 | `pixelbender_multiple_out_params` | 1 | 6.4s |  |
| 791 | `pixelbender_no_out_param` | 6 | 6.4s |  |
| 792 | `pixelbender_outputs` | 13 | 6.6s |  |
| 793 | `pixelbender_padding_bytes` | 22 | 6.5s |  |
| 794 | `pixelbender_param_qualifier` | 512 | 6.5s |  |
| 795 | `pixelbender_parameters` | 1563 | 6.8s |  |
| 796 | `pixelbender_parameters_bool` | 240 | 6.7s |  |
| 797 | `pixelbender_parameters_int_vs_bool` | 54 | 6.5s |  |
| 798 | `pixelbender_parse_errors` | 6 | 6.5s |  |
| 799 | `pixelbender_rsqrt` | 24 | 6.5s |  |
| 800 | `pixelbender_select_kinds` | 8 | 6.6s |  |
| 801 | `pixelbender_shaderdata` | 49 | 6.5s |  |
| 802 | `pixelbender_shaderdata_setter` | 99 | 6.8s |  |
| 803 | `pixelbender_sign` | 60 | 6.6s |  |
| 804 | `pixelbender_vector_output` | 11 | 6.7s |  |
| 805 | `place_and_lookup/swf10` | 33 | 25.6s |  |
| 806 | `place_and_lookup/swf9` | 33 | 0.6s |  |
| 807 | `place_multiple` | 17 | 25.9s |  |
| 808 | `place_object_replace` | 9 | 26.0s |  |
| 809 | `place_object_replace_2` | 24 | 26.0s |  |
| 810 | `place_object_same_depth_frame` | 1 | 6.5s |  |
| 811 | `point` | 132 | 7.0s |  |
| 812 | `primitive_edge_cases` | 1 | 6.4s |  |
| 813 | `primitive_toString` | 277 | 42.9s |  |
| 814 | `primitive_valueOf` | 285 | 6.5s |  |
| 815 | `print_job_options` | 3 | 25.4s |  |
| 816 | `property_is_enumerable` | 114 | 7.3s |  |
| 817 | `property_is_enumerable_reset` | 23 | 6.6s |  |
| 818 | `property_priority` | 22 | 6.9s |  |
| 819 | `property_priority_chained` | 4 | 24.9s |  |
| 820 | `property_priority_definition_names_order` | 2 | 6.8s |  |
| 821 | `property_priority_three_level` | 6 | 24.9s |  |
| 822 | `propertyisenumerable_namespaces` | 6 | 6.6s |  |
| 823 | `prototype_set_null` | 7 | 6.5s |  |
| 824 | `proxy_callproperty` | 24 | 6.5s |  |
| 825 | `proxy_deleteproperty` | 64 | 6.6s |  |
| 826 | `proxy_enumeration` | 34 | 6.6s |  |
| 827 | `proxy_getproperty` | 77 | 6.6s |  |
| 828 | `proxy_hasownproperty` | 8 | 6.5s |  |
| 829 | `proxy_hasproperty` | 32 | 6.6s |  |
| 830 | `proxy_not_overridden` | 54 | 6.5s |  |
| 831 | `proxy_serialize` | 9 | 6.5s |  |
| 832 | `proxy_setproperty` | 42 | 6.6s |  |
| 833 | `qname_as_lazy_name_attribute_multiname` | 1 | 6.5s |  |
| 834 | `qname_constr` | 32 | 6.6s |  |
| 835 | `qname_constr_namespace` | 24 | 6.6s |  |
| 836 | `qname_enumeration` | 9 | 6.6s |  |
| 837 | `qname_indexing` | 23 | 6.6s |  |
| 838 | `qname_tostring` | 25 | 6.6s |  |
| 839 | `qname_valueof` | 29 | 6.6s |  |
| 840 | `rectangle` | 1094 | 7.3s |  |
| 841 | `regexp_constr` | 148 | 6.8s |  |
| 842 | `regexp_exec` | 19 | 6.6s |  |
| 843 | `regexp_extended` | 47 | 6.5s |  |
| 844 | `regexp_multiargs` | 1 | 6.5s |  |
| 845 | `regexp_test` | 27 | 6.6s |  |
| 846 | `regexp_toString` | 10 | 6.5s |  |
| 847 | `register_script_refresh` | 35 | 25.6s |  |
| 848 | `remove_child_clear_field` | 88 | 6.9s |  |
| 849 | `remove_dobj` | 3 | 6.5s |  |
| 850 | `resolve_order` | 4 | 6.5s |  |
| 851 | `responder_null_callbacks` | 1 | 6.5s |  |
| 852 | `rng` | 1 | 7.8s |  |
| 853 | `rootless` | 42 | 6.7s |  |
| 854 | `rshift` | 1058 | 55.3s |  |
| 855 | `rtqname_not_namespace` | 12 | 26.2s |  |
| 856 | `sandbox_type_inherited` | 2 | 7.4s |  |
| 857 | `sandbox_type_local_file` | 1 | 26.4s |  |
| 858 | `sandbox_type_local_network` | 1 | 6.6s |  |
| 859 | `scene_constr` | 8 | 7.0s |  |
| 860 | `scopes_dont_cache/order-1` | 1 | 25.8s |  |
| 861 | `scopes_dont_cache/order-2` | 1 | 0.5s |  |
| 862 | `security_domain_current` | 2 | 6.8s |  |
| 863 | `selection` | 239 | 7.3s |  |
| 864 | `set_local_0` | 31 | 6.8s |  |
| 865 | `set_property_is_enumerable` | 85 | 7.2s |  |
| 866 | `shaderparameter_value` | 4 | 6.9s |  |
| 867 | `shape_drawrect` | 54 | 6.8s |  |
| 868 | `shared_object_no_root` | 3 | 6.8s |  |
| 869 | `simplebutton_added_to_stage` | 45 | 26.1s |  |
| 870 | `simplebutton_childevents` | 86 | 26.5s |  |
| 871 | `simplebutton_childevents_nested` | 54 | 7.2s |  |
| 872 | `simplebutton_childevents_sprite` | 13 | 6.9s |  |
| 873 | `simplebutton_childprops` | 144 | 7.1s |  |
| 874 | `simplebutton_childshuffle` | 23 | 6.7s |  |
| 875 | `simplebutton_constr` | 36 | 7.0s |  |
| 876 | `simplebutton_constr_childevents` | 48 | 7.1s |  |
| 877 | `simplebutton_constr_params` | 42 | 6.9s |  |
| 878 | `simplebutton_mouseenabled` | 26 | 6.8s |  |
| 879 | `simplebutton_multi_children` | 19 | 7.1s |  |
| 880 | `simplebutton_structure` | 27 | 7.0s |  |
| 881 | `simplebutton_symbolclass` | 68 | 7.3s |  |
| 882 | `slot_disp_id_shared_numbering` | 1 | 26.0s |  |
| 883 | `slots_force_autoassigned` | 1 | 6.8s |  |
| 884 | `socket_after_disconnect` | 1 | 7.0s |  |
| 885 | `socket_close` | 2 | 6.8s |  |
| 886 | `socket_connect` | 4 | 6.8s |  |
| 887 | `socket_errors` | 56 | 43.2s |  |
| 888 | `socket_read_big` | 48 | 6.8s |  |
| 889 | `socket_read_little` | 48 | 2.2s |  |
| 890 | `socket_read_write_object` | 8 | 6.5s |  |
| 891 | `socket_write_big` | 15 | 6.9s |  |
| 892 | `socket_write_little` | 14 | 6.5s |  |
| 893 | `sound_constructor_with_args` | 6 | 6.7s |  |
| 894 | `sound_embeddedprops` | 26 | 25.4s |  |
| 895 | `sound_play` | 19 | 6.7s |  |
| 896 | `sound_rootless` | 7 | 6.6s |  |
| 897 | `sound_valueof` | 33 | 6.6s |  |
| 898 | `soundchannel_soundtransform` | 835 | 27.0s |  |
| 899 | `soundchannel_soundtransform_exists` | 5 | 25.2s |  |
| 900 | `soundchannel_stop` | 8 | 25.4s |  |
| 901 | `soundmixer_buffertime` | 5 | 6.5s |  |
| 902 | `soundmixer_stopall` | 6 | 25.3s |  |
| 903 | `soundtransform` | 442 | 12.2s |  |
| 904 | `space_justifier_clone` | 12 | 6.5s |  |
| 905 | `sprite_with_frames` | 0 | 25.6s |  |
| 906 | `stage3d_agal_cross_product` | 0 | 8.9s |  |
| 907 | `stage3d_agal_upload_errors` | 66 | 9.2s |  |
| 908 | `stage3d_bitmap` | 0 | 30.1s |  |
| 909 | `stage3d_blend` | 81 | 27.9s |  |
| 910 | `stage3d_context3d_string_args` | 158 | 7.6s |  |
| 911 | `stage3d_errors` | 7 | 6.6s |  |
| 912 | `stage3d_errors_atf` | 3 | 7.9s |  |
| 913 | `stage3d_errors_swf_29` | 6 | 6.7s |  |
| 914 | `stage3d_float1_index` | 0 | 27.7s |  |
| 915 | `stage3d_fractal` | 0 | 27.5s |  |
| 916 | `stage3d_ignore_sampler_override` | 0 | 27.8s |  |
| 917 | `stage3d_multistage_triangle` | 3 | 9.2s |  |
| 918 | `stage3d_program_constants_bytearray_be` | 0 | 29.5s |  |
| 919 | `stage3d_program_constants_bytearray_le` | 0 | 9.7s |  |
| 920 | `stage3d_program_constants_invalid_input` | 21 | 7.5s |  |
| 921 | `stage3d_raytrace` | 0 | 32.4s |  |
| 922 | `stage3d_rotating_cube` | 0 | 9.8s |  |
| 923 | `stage3d_sampler` | 0 | 45.3s |  |
| 924 | `stage3d_sampler_partial_upload` | 0 | 8.6s |  |
| 925 | `stage3d_stencil` | 0 | 28.2s |  |
| 926 | `stage3d_texture` | 0 | 13.8s |  |
| 927 | `stage3d_texture_bytearray` | 0 | 9.9s |  |
| 928 | `stage3d_texture_bytearray_compressed_alpha` | 0 | 9.2s |  |
| 929 | `stage3d_texture_bytearray_compressed_raw_alpha` | 0 | 10.3s |  |
| 930 | `stage3d_triangle` | 0 | 8.7s |  |
| 931 | `stage3d_triangle_bytes4` | 0 | 8.6s |  |
| 932 | `stage3d_triangle_float1` | 0 | 8.6s |  |
| 933 | `stage3d_triangle_index_upload` | 0 | 8.6s |  |
| 934 | `stage3d_x_y` | 22 | 6.4s |  |
| 935 | `stage_access` | 10 | 25.1s |  |
| 936 | `stage_displayobject_properties` | 24 | 6.3s |  |
| 937 | `stage_domain_getQualifiedDefinitionNames` | 5 | 6.3s |  |
| 938 | `stage_framerate_nan` | 7 | 25.7s |  |
| 939 | `stage_framerate_negative` | 6 | 6.3s |  |
| 940 | `stage_framerate_zero` | 6 | 6.5s |  |
| 941 | `stage_invalidate` | 38 | 6.8s |  |
| 942 | `stage_loaderinfo_properties` | 24 | 25.6s |  |
| 943 | `stage_mousechildren` | 2 | 6.4s |  |
| 944 | `stage_mouseenabled` | 15 | 6.3s |  |
| 945 | `stage_overriden_setters` | 31 | 6.5s |  |
| 946 | `stage_properties` | 30 | 6.3s |  |
| 947 | `stage_properties2` | 213 | 6.5s |  |
| 948 | `stage_stage3Ds_vector` | 1 | 25.1s |  |
| 949 | `static_length` | 24 | 6.4s |  |
| 950 | `static_text` | 3 | 6.5s |  |
| 951 | `static_var_with_this_in_ctor` | 2 | 6.3s |  |
| 952 | `statictext_text` | 8 | 6.4s |  |
| 953 | `stored_properties` | 11 | 6.4s |  |
| 954 | `strict_equality` | 34 | 6.4s |  |
| 955 | `string_call` | 13 | 6.4s |  |
| 956 | `string_case` | 23 | 6.4s |  |
| 957 | `string_char_at` | 27 | 6.3s |  |
| 958 | `string_char_code_at` | 28 | 6.3s |  |
| 959 | `string_concat_fromcharcode` | 37 | 6.2s |  |
| 960 | `string_constr` | 25 | 6.3s |  |
| 961 | `string_indexof_lastindexof` | 87 | 6.5s |  |
| 962 | `string_length` | 16 | 26.7s |  |
| 963 | `string_locale_compare` | 39 | 4.4s |  |
| 964 | `string_match` | 51 | 15.8s |  |
| 965 | `string_relational_compare` | 4 | 4.1s |  |
| 966 | `string_replace` | 51 | 4.2s |  |
| 967 | `string_search` | 41 | 4.2s |  |
| 968 | `string_slice_substr_substring` | 170 | 4.7s |  |
| 969 | `string_split` | 29 | 4.2s |  |
| 970 | `string_substr_negative` | 21 | 15.2s |  |
| 971 | `string_substr_weird` | 182 | 4.1s |  |
| 972 | `stylesheet` | 221 | 4.5s |  |
| 973 | `stylesheet_parse_color` | 69 | 4.1s |  |
| 974 | `stylesheet_transform` | 307 | 4.3s |  |
| 975 | `sub_super_same_field` | 12 | 1.6s |  |
| 976 | `subclass_superclass_linked_symbol` | 4 | 4.5s |  |
| 977 | `subtract` | 1058 | 10.2s |  |
| 978 | `super_get_call` | 12 | 4.1s |  |
| 979 | `supercall_two_classobjects` | 2 | 4.2s |  |
| 980 | `supercalls_weird` | 2 | 4.3s |  |
| 981 | `superinterface_call` | 20 | 4.1s |  |
| 982 | `superinterface_instanceof` | 18 | 4.1s |  |
| 983 | `swf8` | 1 | 4.1s |  |
| 984 | `swf_10_queued_goto_scripts_construct` | 52 | 16.0s |  |
| 985 | `swf_9_goto_in_enter_frame` | 17 | 4.1s |  |
| 986 | `swf_9_goto_in_enter_frame_simple` | 15 | 4.2s |  |
| 987 | `swf_9_queued_goto_scripts` | 6 | 15.8s |  |
| 988 | `swf_9_queued_goto_scripts_construct` | 28 | 0.4s |  |
| 989 | `swf_9_versioning` | 2 | 4.5s |  |
| 990 | `swf_wrong_frame_count` | 38 | 4.4s |  |
| 991 | `swf_wrong_frame_count_isplaying` | 22 | 15.4s |  |
| 992 | `symbol_class_binary_data` | 8 | 4.1s |  |
| 993 | `symbol_class_conflict` | 4 | 4.2s |  |
| 994 | `symbol_class_root_not_zero` | 1 | 4.0s |  |
| 995 | `symbolclass_invalid_utf8` | 2 | 4.1s |  |
| 996 | `system_exit` | 3 | 4.1s |  |
| 997 | `system_setclipboard_null` | 1 | 4.0s |  |
| 998 | `tab_ordering_arrows` | 998 | 16.1s |  |
| 999 | `tab_ordering_automatic_advanced` | 184 | 4.5s |  |
| 1000 | `tab_ordering_automatic_basic` | 45 | 43.0s |  |
| 1001 | `tab_ordering_children` | 116 | 6.4s |  |
| 1002 | `tab_ordering_custom_basic` | 34 | 6.3s |  |
| 1003 | `tab_ordering_stage_tab_children` | 32 | 6.3s |  |
| 1004 | `tab_ordering_stage_tab_children_remove_root` | 5 | 6.2s |  |
| 1005 | `tab_ordering_tabbable` | 47 | 6.4s |  |
| 1006 | `tabstop_properties` | 105 | 25.2s |  |
| 1007 | `text_element_basic` | 34 | 6.5s |  |
| 1008 | `text_engine_fontdescription` | 27 | 6.5s |  |
| 1009 | `text_engine_groupelement` | 64 | 7.3s |  |
| 1010 | `text_run` | 7 | 6.3s |  |
| 1011 | `textblock_createline_errors` | 23 | 6.6s |  |
| 1012 | `textblock_createline_fte` | 9 | 25.7s |  |
| 1013 | `textblock_properties` | 118 | 6.9s |  |
| 1014 | `textbox_click` | 37 | 25.9s |  |
| 1015 | `textfield_event` | 66 | 6.7s |  |
| 1016 | `textfield_focusin_event` | 9 | 6.3s |  |
| 1017 | `textfield_input_dead_keys_windows` | 15 | 6.4s |  |
| 1018 | `textfield_unload` | 39 | 25.3s |  |
| 1019 | `textformat` | 1134 | 24.8s |  |
| 1020 | `textformat_display` | 14 | 6.4s |  |
| 1021 | `textformat_font_max_length` | 4 | 6.3s |  |
| 1022 | `textline_inapplicable_properties` | 10 | 6.3s |  |
| 1023 | `textline_name` | 1 | 6.3s |  |
| 1024 | `textline_raw_text_length` | 30 | 6.6s |  |
| 1025 | `textline_splitting_basic` | 76 | 6.6s |  |
| 1026 | `textline_throwerror` | 30 | 6.4s |  |
| 1027 | `textline_validity` | 162 | 6.5s |  |
| 1028 | `throw` | 3 | 6.4s |  |
| 1029 | `timeline_scripts` | 3 | 25.6s |  |
| 1030 | `timer` | 90 | 7.2s |  |
| 1031 | `timer_events` | 3 | 6.7s |  |
| 1032 | `timer_finished` | 11 | 6.6s |  |
| 1033 | `timer_invalid_delay` | 30 | 6.3s |  |
| 1034 | `timer_reset` | 8 | 6.6s |  |
| 1035 | `timer_setdelay` | 5 | 6.5s |  |
| 1036 | `trace` | 12 | 44.2s |  |
| 1037 | `truthiness` | 30 | 6.5s |  |
| 1038 | `try_catch` | 11 | 6.6s |  |
| 1039 | `try_catch_typed` | 12 | 6.6s |  |
| 1040 | `typeof` | 30 | 6.5s |  |
| 1041 | `uint_constr` | 92 | 6.8s |  |
| 1042 | `uint_tofixed` | 1215 | 6.5s |  |
| 1043 | `uint_toprecision` | 1125 | 6.7s |  |
| 1044 | `uint_tostring` | 3375 | 6.8s |  |
| 1045 | `uncaught_error_basic` | 2 | 6.5s |  |
| 1046 | `unchecked_function` | 15 | 6.5s |  |
| 1047 | `unescape` | 28 | 6.5s |  |
| 1048 | `url_loader` | 25 | 6.6s |  |
| 1049 | `url_vars` | 27 | 6.6s |  |
| 1050 | `urlrequest` | 18 | 26.2s |  |
| 1051 | `urlstream_basic` | 5 | 6.5s |  |
| 1052 | `urshift` | 1058 | 18.9s |  |
| 1053 | `utils3d` | 7 | 6.5s |  |
| 1054 | `vector3d` | 397 | 11.4s |  |
| 1055 | `vector_class` | 36 | 6.9s |  |
| 1056 | `vector_class_call` | 11 | 26.1s |  |
| 1057 | `vector_coercion` | 66 | 7.4s |  |
| 1058 | `vector_concat` | 90 | 7.1s |  |
| 1059 | `vector_constr` | 107 | 7.3s |  |
| 1060 | `vector_enumeration` | 5 | 6.5s |  |
| 1061 | `vector_every` | 92 | 7.4s |  |
| 1062 | `vector_filter` | 95 | 7.3s |  |
| 1063 | `vector_holes` | 24 | 6.5s |  |
| 1064 | `vector_indexof` | 302 | 11.4s |  |
| 1065 | `vector_insertat` | 270 | 7.7s |  |
| 1066 | `vector_int_access` | 4 | 6.5s |  |
| 1067 | `vector_int_delete` | 11 | 6.4s |  |
| 1068 | `vector_join` | 58 | 6.9s |  |
| 1069 | `vector_lastindexof` | 302 | 6.4s |  |
| 1070 | `vector_legacy` | 10 | 6.5s |  |
| 1071 | `vector_map` | 85 | 7.2s |  |
| 1072 | `vector_object_final` | 1 | 6.3s |  |
| 1073 | `vector_object_toString` | 10 | 6.4s |  |
| 1074 | `vector_pushpop` | 255 | 43.5s |  |
| 1075 | `vector_reborrow_bug` | 10 | 24.8s |  |
| 1076 | `vector_removeat` | 172 | 7.6s |  |
| 1077 | `vector_reverse` | 232 | 7.6s |  |
| 1078 | `vector_shiftunshift` | 252 | 6.4s |  |
| 1079 | `vector_slice` | 331 | 8.3s |  |
| 1080 | `vector_sort` | 905 | 15.9s |  |
| 1081 | `vector_splice` | 693 | 10.5s |  |
| 1082 | `vector_splice_fixed_bug_compat` | 4 | 6.6s |  |
| 1083 | `vector_tostring` | 79 | 7.1s |  |
| 1084 | `verification` | 8 | 24.9s |  |
| 1085 | `verify_abnormal_loop` | 1 | 6.4s |  |
| 1086 | `verify_dxns_without_flag` | 3 | 6.9s |  |
| 1087 | `verify_exception_target_two_jumps` | 1 | 6.5s |  |
| 1088 | `verify_exception_targets_edge_case` | 1 | 6.4s |  |
| 1089 | `verify_illegal_opcode` | 1 | 2.6s |  |
| 1090 | `verify_jump_to_middle_of_op` | 1 | 6.4s |  |
| 1091 | `verify_lookup_switch_edge_case` | 1 | 6.4s |  |
| 1092 | `verify_method_info_oob` | 1 | 0.5s |  |
| 1093 | `verify_stack` | 5 | 6.5s |  |
| 1094 | `verify_typecheck` | 4 | 6.5s |  |
| 1095 | `verify_unreachable_exception` | 2 | 6.4s |  |
| 1096 | `versioned_isplaying` | 2 | 6.5s |  |
| 1097 | `virtual_properties` | 16 | 6.6s |  |
| 1098 | `with` | 4 | 6.5s |  |
| 1099 | `wrong_arg_count` | 7 | 6.6s |  |
| 1100 | `xml_abstract_equality` | 36 | 6.7s |  |
| 1101 | `xml_advanced` | 52 | 6.5s |  |
| 1102 | `xml_appendchild` | 10 | 6.5s |  |
| 1103 | `xml_appendchild_swf_v21` | 13 | 6.7s |  |
| 1104 | `xml_as_attribute` | 9 | 6.4s |  |
| 1105 | `xml_attribute` | 35 | 6.6s |  |
| 1106 | `xml_attribute_name` | 40 | 6.5s |  |
| 1107 | `xml_basic` | 33 | 6.6s |  |
| 1108 | `xml_child` | 25 | 6.5s |  |
| 1109 | `xml_childindex` | 7 | 6.5s |  |
| 1110 | `xml_children` | 43 | 7.0s |  |
| 1111 | `xml_class_call` | 9 | 6.5s |  |
| 1112 | `xml_contains` | 197 | 6.6s |  |
| 1113 | `xml_copy` | 20 | 44.2s |  |
| 1114 | `xml_ctor_from_tostring` | 23 | 26.6s |  |
| 1115 | `xml_delete` | 114 | 7.0s |  |
| 1116 | `xml_descendants` | 83 | 6.9s |  |
| 1117 | `xml_elements` | 6 | 6.8s |  |
| 1118 | `xml_equals_namespace_check` | 2 | 25.9s |  |
| 1119 | `xml_explicit_use_namespace` | 5 | 6.9s |  |
| 1120 | `xml_getdescendants_qname` | 21 | 6.9s |  |
| 1121 | `xml_has_property_via_in` | 26 | 6.9s |  |
| 1122 | `xml_hasownproperty` | 6 | 6.8s |  |
| 1123 | `xml_ignore_white` | 6 | 6.9s |  |
| 1124 | `xml_length` | 2 | 6.8s |  |
| 1125 | `xml_list_as_attribute` | 9 | 6.8s |  |
| 1126 | `xml_list_concat` | 20 | 6.8s |  |
| 1127 | `xml_list_ctor_errors` | 34 | 6.9s |  |
| 1128 | `xml_list_delete_clear_parent` | 6 | 6.8s |  |
| 1129 | `xml_list_enumerate` | 4 | 6.7s |  |
| 1130 | `xml_methods_settings` | 3 | 6.8s |  |
| 1131 | `xml_mismatched_tag` | 37 | 6.8s |  |
| 1132 | `xml_namespace` | 39 | 6.8s |  |
| 1133 | `xml_namespace_methods` | 245 | 6.8s |  |
| 1134 | `xml_namespaced_property` | 7 | 6.8s |  |
| 1135 | `xml_no_namespace` | 1 | 6.8s |  |
| 1136 | `xml_nodekind` | 3 | 6.8s |  |
| 1137 | `xml_normalize` | 35 | 6.9s |  |
| 1138 | `xml_notification_bubbling` | 361 | 6.8s |  |
| 1139 | `xml_parent` | 8 | 6.8s |  |
| 1140 | `xml_set_children` | 17 | 6.9s |  |
| 1141 | `xml_set_name` | 34 | 6.8s |  |
| 1142 | `xml_settings` | 6 | 2.4s |  |
| 1143 | `xml_simple_complex_content` | 47 | 6.8s |  |
| 1144 | `xml_socket` | 11 | 7.0s |  |
| 1145 | `xml_text` | 7 | 6.8s |  |
| 1146 | `xml_tostring` | 6 | 6.8s |  |
| 1147 | `xml_tostring_namespace` | 12 | 6.8s |  |
| 1148 | `xml_unescaping` | 23 | 6.9s |  |
| 1149 | `xml_weird_ignores` | 54 | 6.9s |  |
| 1150 | `xml_wildcard` | 11 | 6.8s |  |
| 1151 | `xmldocument` | 254 | 6.9s |  |
| 1152 | `xmlnode` | 3540 | 7.0s |  |
| 1153 | `zero_frame_clip` | 3 | 7.2s |  |

## Ruffle-Matched Tests

**31 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `array_access_oob_interpreter` | 3 | 3 | 6.4s |  |
| 2 | `array_sort_swf10_64bit` | 1 | 1 | 0.4s |  |
| 3 | `blend_transform` | 1 | 1 | 4.5s |  |
| 4 | `coerce_property` | 3 | 3 | 6.9s |  |
| 5 | `coerce_to_primitive_side_effects_with_nulls` | 4 | 4 | 6.8s |  |
| 6 | `dictionary_weak_keys` | 1 | 1 | 26.5s |  |
| 7 | `edittext_device_transform_layout` | 20 | 20 | 6.8s |  |
| 8 | `edittext_getcharboundaries_culling` | 300 | 300 | 6.8s |  |
| 9 | `edittext_getcharboundaries_missing_embedded_font` | 3 | 3 | 6.6s |  |
| 10 | `edittext_tab_stops` | 6 | 6 | 6.8s |  |
| 11 | `encode_uri_surrogate_pair_swf10` | 15 | 15 | 6.8s |  |
| 12 | `error_1034_debug_string` | 19 | 19 | 6.7s |  |
| 13 | `freestanding_superclass` | 2 | 4 | 25.6s |  |
| 14 | `goto_framescript_queued` | 5 | 5 | 25.7s |  |
| 15 | `graphics_draw_path` | 50 | 50 | 28.0s |  |
| 16 | `groupelement_text` | 2 | 2 | 7.0s |  |
| 17 | `int_toexponential` | 76 | 76 | 6.8s |  |
| 18 | `matrix3d_append_rotation` | 1 | 3 | 5.5s |  |
| 19 | `matrix3d_recompose_edge_cases` | 85 | 85 | 5.9s |  |
| 20 | `simplebutton_childevents_script_order` | 4 | 4 | 7.0s |  |
| 21 | `slot_holes_fail` | 1 | 1 | 6.7s |  |
| 22 | `slot_id_exceeds_trait_count` | 1 | 1 | 26.0s |  |
| 23 | `soundchannel_position` | 74 | 74 | 26.0s |  |
| 24 | `soundchannel_soundcomplete` | 10 | 10 | 6.8s |  |
| 25 | `sprite_dropTarget` | 15 | 15 | 25.0s |  |
| 26 | `swf_9_goto_in_construct_frame` | 12 | 12 | 15.7s |  |
| 27 | `textblock_line_changes` | 44 | 44 | 7.4s |  |
| 28 | `textblock_releaselines` | 4 | 4 | 8.4s |  |
| 29 | `uint_toexponential` | 100 | 100 | 6.8s |  |
| 30 | `uncaught_errors_stringified` | 15 | 15 | 6.7s |  |
| 31 | `weird_superinterface_properties` | 1 | 1 | 24.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**28 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `divide` | 99.1% | 1048 | 1058 | 10 |  |
| 2 | `soundmixer_soundtransform` | 98.7% | 888 | 900 | 12 |  |
| 3 | `loader_load` | 98.4% | 126 | 128 | 2 |  |
| 4 | `bounds_mode` | 94.1% | 253 | 269 | 16 |  |
| 5 | `simplebutton_soundtransform` | 93.5% | 829 | 887 | 58 |  |
| 6 | `matrix3d_constructor_clone` | 93.3% | 14 | 15 | 1 |  |
| 7 | `coerce_string_precision` | 89.3% | 25 | 28 | 3 |  |
| 8 | `matrix3d_raw_data` | 84.8% | 28 | 33 | 5 |  |
| 9 | `vector3d_near_equals` | 83.8% | 67 | 80 | 13 |  |
| 10 | `number_tostring` | 83.1% | 873 | 1050 | 177 |  |
| 11 | `matrix3d_determinant` | 81.9% | 149 | 182 | 33 |  |
| 12 | `displayobject_scrollrect` | 81.8% | 27 | 33 | 6 |  |
| 13 | `tab_ordering_properties` | 76.6% | 561 | 732 | 171 |  |
| 14 | `large_preload_image_from_bytes` | 76.0% | 19 | 25 | 6 |  |
| 15 | `displayobject_transform` | 75.3% | 67 | 89 | 22 |  |
| 16 | `scope_optimizations` | 75.0% | 3 | 4 | 1 |  |
| 17 | `displayobject_hittestpoint_boundary` | 72.3% | 47 | 65 | 18 |  |
| 18 | `button_nested_frame_simple` | 69.2% | 27 | 39 | 12 |  |
| 19 | `bom` | 66.7% | 6 | 9 | 3 |  |
| 20 | `matrix3d_copy_from` | 63.2% | 12 | 19 | 7 |  |
| 21 | `matrix3d_copy_to_matrix3d` | 63.2% | 12 | 19 | 7 |  |
| 22 | `loader_duplicate_class` | 60.4% | 29 | 48 | 19 |  |
| 23 | `large_preload_from_url` | 59.3% | 16 | 27 | 11 |  |
| 24 | `dependent_strings` | 54.8% | 46 | 84 | 38 |  |
| 25 | `orphan_removeobject` | 53.0% | 340 | 641 | 301 |  |
| 26 | `mouse_pick_avm1_root` | 50.0% | 1 | 2 | 1 |  |
| 27 | `stage_scale_factor` | 50.0% | 6 | 12 | 6 |  |
| 28 | `verify_method_info_duplicate` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**67 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `divide` | 99.1% | 1048/1058 | 1058 | 1058 |  |
| 2 | `soundmixer_soundtransform` | 98.7% | 888/900 | 900 | 900 |  |
| 3 | `loader_load` | 98.4% | 126/128 | 128 | 128 |  |
| 4 | `bounds_mode` | 94.1% | 253/269 | 269 | 269 |  |
| 5 | `simplebutton_soundtransform` | 93.5% | 829/887 | 887 | 887 |  |
| 6 | `matrix3d_constructor_clone` | 93.3% | 14/15 | 15 | 15 |  |
| 7 | `coerce_string_precision` | 89.3% | 25/28 | 28 | 28 |  |
| 8 | `matrix3d_raw_data` | 84.8% | 28/33 | 33 | 33 |  |
| 9 | `vector3d_near_equals` | 83.8% | 67/80 | 80 | 80 |  |
| 10 | `number_tostring` | 83.1% | 873/1050 | 1050 | 1050 |  |
| 11 | `matrix3d_determinant` | 81.9% | 149/182 | 182 | 182 |  |
| 12 | `displayobject_scrollrect` | 81.8% | 27/33 | 33 | 33 |  |
| 13 | `tab_ordering_properties` | 76.6% | 561/732 | 732 | 732 |  |
| 14 | `large_preload_image_from_bytes` | 76.0% | 19/25 | 25 | 25 |  |
| 15 | `displayobject_transform` | 75.3% | 67/89 | 89 | 89 |  |
| 16 | `scope_optimizations` | 75.0% | 3/4 | 4 | 4 |  |
| 17 | `displayobject_hittestpoint_boundary` | 72.3% | 47/65 | 65 | 65 |  |
| 18 | `button_nested_frame_simple` | 69.2% | 27/39 | 39 | 27 |  |
| 19 | `bom` | 66.7% | 6/9 | 9 | 9 |  |
| 20 | `matrix3d_copy_from` | 63.2% | 12/19 | 16 | 19 |  |
| 21 | `matrix3d_copy_to_matrix3d` | 63.2% | 12/19 | 16 | 19 |  |
| 22 | `loader_duplicate_class` | 60.4% | 29/48 | 48 | 48 |  |
| 23 | `large_preload_from_url` | 59.3% | 16/27 | 17 | 27 |  |
| 24 | `dependent_strings` | 54.8% | 46/84 | 83 | 84 |  |
| 25 | `orphan_removeobject` | 53.0% | 340/641 | 641 | 636 |  |
| 26 | `mouse_pick_avm1_root` | 50.0% | 1/2 | 2 | 2 |  |
| 27 | `stage_scale_factor` | 50.0% | 6/12 | 12 | 12 |  |
| 28 | `verify_method_info_duplicate` | 50.0% | 1/2 | 1 | 2 |  |
| 29 | `event_handler_exception` | 45.5% | 5/11 | 10 | 11 |  |
| 30 | `textfield_input_events` | 36.0% | 9/25 | 24 | 25 |  |
| 31 | `large_preload_from_bytes` | 35.3% | 18/51 | 25 | 51 |  |
| 32 | `sandbox_type_remote` | 33.3% | 1/3 | 1 | 3 |  |
| 33 | `number_to_string` | 29.2% | 103/353 | 353 | 353 |  |
| 34 | `matrix3d_append_prepend_translation` | 23.8% | 10/42 | 42 | 42 |  |
| 35 | `textblock_recreateline` | 22.7% | 41/181 | 181 | 180 |  |
| 36 | `appdomain_lookup_edge_cases` | 21.9% | 7/32 | 11 | 32 |  |
| 37 | `simplebutton_childevents_multichild` | 21.7% | 33/152 | 132 | 152 |  |
| 38 | `avm1_root` | 20.7% | 12/58 | 34 | 58 |  |
| 39 | `method_association` | 20.0% | 1/5 | 4 | 5 |  |
| 40 | `matrix3d_precision` | 17.9% | 5/28 | 28 | 28 |  |
| 41 | `sound_load_multiple` | 15.8% | 3/19 | 7 | 19 |  |
| 42 | `displayobject_getrect` | 12.5% | 2/16 | 5 | 16 |  |
| 43 | `supercalls_coerce` | 12.5% | 1/8 | 8 | 8 |  |
| 44 | `mouse_pick_loader_avm1` | 11.9% | 5/42 | 40 | 42 |  |
| 45 | `netstream_play_stop_replay` | 9.1% | 1/11 | 1 | 11 |  |
| 46 | `number_convert_errors` | 4.6% | 40/871 | 685 | 871 |  |
| 47 | `external_interface` | 2.9% | 3/105 | 7 | 105 |  |
| 48 | `focus_events_mixed_avm_edittext` | 2.0% | 1/49 | 31 | 49 |  |
| 49 | `displayobject_early_init` | 1.9% | 1/54 | 51 | 54 |  |
| 50 | `all_classes/events/swf30` | 1.1% | 25/2353 | 735 | 2353 |  |
| 51 | `all_classes/events/swf9` | 1.0% | 10/1030 | 731 | 1030 |  |
| 52 | `all_classes/events/swf10` | 0.9% | 15/1638 | 731 | 1638 |  |
| 53 | `all_classes/events/swf11` | 0.9% | 15/1750 | 731 | 1750 |  |
| 54 | `all_classes/events/swf12` | 0.8% | 15/1814 | 731 | 1814 |  |
| 55 | `automation_classes` | 0.8% | 1/122 | 4 | 122 |  |
| 56 | `audio_computespectrum` | 0.0% | 0/478 | 478 | 118 |  |
| 57 | `id3_info` | 0.0% | 0/8 | 0 | 8 |  |
| 58 | `loader_applicationDomain` | 0.0% | 0/4 | 0 | 4 |  |
| 59 | `loader_try_click_root` | 0.0% | 0/26 | 26 | 16 |  |
| 60 | `matrix3d_append_prepend_scale` | 0.0% | 0/86 | 46 | 86 |  |
| 61 | `matrix3d_interpolate` | 0.0% | 0/21 | 3 | 21 |  |
| 62 | `native_menu_basic` | 0.0% | 0/19 | 3 | 19 |  |
| 63 | `netstream_play_flv` | 0.0% | 0/16 | 1 | 16 |  |
| 64 | `netstream_seek_flv` | 0.0% | 0/49 | 1 | 49 |  |
| 65 | `selection_onsetfocus_mixed_avm` | 0.0% | 0/5 | 0 | 5 |  |
| 66 | `stage_display_state` | 0.0% | 0/6 | 2 | 6 |  |
| 67 | `swz` | 0.0% | 0/2 | 0 | 2 |  |
